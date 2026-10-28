#include "bootstrap.split.h"

static void vader_front_resolver$add_fn(void* l0, void* l1, vader_string_t l2, vader_string_t l3, void* l4, void* l5);
static void vader_front_resolver$add_named(void* l0, uint8_t l1, vader_string_t l2, void* l3, uint8_t l4, vader_string_t l5, vader_string_t l6, void* l7, void* l8);
static bool vader_front_resolver$any_has_body(void* l0);
static vader_box_t vader_front_resolver$asset_problem(vader_string_t l0);
static void vader_front_resolver$auto_bind_for_type_params(void* l0, vader_box_t l1);
static void* vader_front_resolver$baked_target_of(vader_box_t l0);
static void vader_front_resolver$bind(void* l0, vader_string_t l1, void* l2);
static void vader_front_resolver$bind_1(void* l0, vader_string_t l1, vader_box_t l2);
static void vader_front_resolver$bind_import(void* l0, vader_string_t l1, void* l2, vader_string_t l3, vader_box_t l4, vader_string_t l5, void* l6, void* l7);
static void vader_front_resolver$bind_let_binding(void* l0, vader_box_t l1, void* l2);
static void* vader_front_resolver$bind_local(void* l0, uint8_t l1, vader_string_t l2, void* l3);
static void* vader_front_resolver$bind_local_checked(void* l0, uint8_t l1, vader_string_t l2, void* l3);
static void vader_front_resolver$bind_param(void* l0, void* l1);
static void vader_front_resolver$bind_pattern(void* l0, vader_box_t l1);
static void* vader_front_resolver$bind_type_param(void* l0, void* l1);
static void* vader_front_resolver$binding_clashes(void* l0, void* l1);
static void* vader_front_resolver$binding_span(vader_box_t l0);
static bool vader_front_resolver$body_survives(void* l0, void* l1);
static void* vader_front_resolver$build_subst(void* l0, void* l1);
static void* vader_front_resolver$builtin_type_names(void);
static void vader_front_resolver$check_groups(void* l0, void* l1);
static void vader_front_resolver$check_import_form_conflict(void* l0, void* l1);
static void vader_front_resolver$check_orphan_rule(void* l0, vader_string_t l1, void* l2, void* l3, void* l4, void* l5, void* l6);
static void vader_front_resolver$check_selectors(void* l0, void* l1);
static void vader_front_resolver$check_short_impl_arity(void* l0, void* l1, void* l2);
static void vader_front_resolver$check_signature(void* l0, void* l1, void* l2);
static void vader_front_resolver$check_target_selectors(void* l0, void* l1);
static void vader_front_resolver$check_wildcard_ambiguity(void* l0, vader_string_t l1, void* l2, void* l3);
static vader_box_t vader_front_resolver$checked_bound(void* l0, void* l1, vader_box_t l2);
static vader_box_t vader_front_resolver$clone_assign_value(void* l0, vader_box_t l1, void* l2);
static vader_box_t vader_front_resolver$clone_header_binding(vader_box_t l0);
static void* vader_front_resolver$clone_ident(void* l0);
static vader_box_t vader_front_resolver$clone_let_binding(vader_box_t l0);
static void vader_front_resolver$collect_decl(void* l0, vader_box_t l1, vader_string_t l2, vader_string_t l3, void* l4, void* l5, void* l6, void* l7);
static void* vader_front_resolver$collect_files(void* l0, vader_string_t l1, vader_string_t l2, void* l3, void* l4, void* l5, void* l6);
static void vader_front_resolver$collect_import(void* l0, void* l1, vader_string_t l2, vader_string_t l3, void* l4, void* l5, void* l6, void* l7);
static void* vader_front_resolver$collect_module(void* l0, vader_string_t l1, vader_string_t l2, void* l3, void* l4, void* l5, void* l6);
static void* vader_front_resolver$collect_module_no_index(void* l0, vader_string_t l1, void* l2);
static int64_t vader_front_resolver$count_sam_synthetics(void* l0);
static void* vader_front_resolver$declaration_index(void* l0);
static void vader_front_resolver$declare_loop_local(void* l0, void* l1);
static void* vader_front_resolver$declare_type_param(void* l0, void* l1);
static bool vader_front_resolver$declared_outside_lambda(void* l0, vader_string_t l1);
static void* vader_front_resolver$declared_roots(void);
static void* vader_front_resolver$declared_roots$singleton(void);
static void vader_front_resolver$detect_import_cycles(void* l0, void* l1, void* l2);
static vader_box_t vader_front_resolver$diagnose_import_path(vader_string_t l0, void* l1, vader_string_t l2, void* l3, void* l4, void* l5);
static void* vader_front_resolver$discarded_bodies(void* l0, vader_box_t l1);
static vader_box_t vader_front_resolver$displayable_impl(void* l0, void* l1, vader_string_t l2);
static void vader_front_resolver$drain_load_queue(void* l0, void* l1);
static void* vader_front_resolver$enter_file(void* l0, void* l1);
static vader_string_t vader_front_resolver$entry_folder_of(vader_string_t l0);
static vader_box_t vader_front_resolver$entry_name_problem(vader_string_t l0);
static vader_box_t vader_front_resolver$entry_named(void* l0, vader_string_t l1);
static void* vader_front_resolver$entry_namespace(vader_string_t l0, vader_string_t l1);
static void* vader_front_resolver$file_imports(void* l0, vader_string_t l1);
static void* vader_front_resolver$file_root_scope(void* l0, void* l1, void* l2, void* l3, void* l4);
static void* vader_front_resolver$find_impl_trait_decl(vader_string_t l0, void* l1, void* l2, void* l3, void* l4);
static vader_string_t vader_front_resolver$for_type_display_name(vader_box_t l0);
static vader_box_t vader_front_resolver$for_type_owner_sym(vader_box_t l0, void* l1, void* l2);
static int32_t vader_front_resolver$frame_count(void* l0);
static vader_string_t vader_front_resolver$generated_root_for(vader_box_t l0);
static void* vader_front_resolver$graft_body(void* l0, void* l1);
static bool vader_front_resolver$has_impl_decl(void* l0);
static bool vader_front_resolver$has_module(void* l0, vader_string_t l1);
static bool vader_front_resolver$has_reassignment(void* l0, void* l1);
static vader_box_t vader_front_resolver$home_root(vader_string_t l0, vader_string_t l1);
static uint8_t vader_front_resolver$importer_origin(void* l0, vader_string_t l1);
static void* vader_front_resolver$include_paths(void* l0, void* l1, vader_string_t l2);
static void vader_front_resolver$index_declaration(void* l0, void* l1);
static void vader_front_resolver$ingest_module(void* l0, void* l1);
static void* vader_front_resolver$intrinsic_decorator(void* l0);
static bool vader_front_resolver$is_contract_decorator(vader_string_t l0);
static bool vader_front_resolver$is_host_bound(void* l0);
static bool vader_front_resolver$is_intrinsic(void* l0);
static bool vader_front_resolver$is_known_decorator(vader_string_t l0);
static bool vader_front_resolver$is_portable_name(vader_string_t l0);
static bool vader_front_resolver$is_windows_device_name(vader_string_t l0);
static bool vader_front_resolver$leaves_project(vader_string_t l0);
static void vader_front_resolver$load_baked_target(void* l0, void* l1);
static void* vader_front_resolver$load_project_with_overlay(vader_string_t l0, void* l1, void* l2, vader_box_t l3, vader_box_t l4, void* l5, bool l6);
static vader_box_t vader_front_resolver$lookup(void* l0, vader_string_t l1);
static int32_t vader_front_resolver$lookup_frame_index(void* l0, vader_string_t l1);
static vader_box_t vader_front_resolver$lookup_subst(void* l0, vader_string_t l1);
static vader_box_t vader_front_resolver$lookup_trait_sym(void* l0, void* l1, void* l2, void* l3);
static void* vader_front_resolver$make_builtin_scope(void* l0);
static void* vader_front_resolver$manifest_at(vader_box_t l0);
static vader_string_t vader_front_resolver$manifest_root(vader_string_t l0, vader_string_t l1, vader_box_t l2);
static bool vader_front_resolver$matches_target(void* l0, void* l1);
static void vader_front_resolver$materialize_default_members(void* l0, void* l1, void* l2);
static void vader_front_resolver$materialize_file_impl_members(void* l0, void* l1, void* l2, void* l3, void* l4);
static void vader_front_resolver$materialize_intrinsic_members(void* l0, void* l1, void* l2);
static void vader_front_resolver$materialize_sam_members(void* l0, void* l1, void* l2);
static void vader_front_resolver$merge_collected(void* l0, void* l1, void* l2);
static void* vader_front_resolver$mint_local(void* l0, uint8_t l1, vader_string_t l2, void* l3);
static vader_box_t vader_front_resolver$misplaced_module_at(vader_string_t l0, void* l1);
static vader_box_t vader_front_resolver$name_in_file_scope(vader_string_t l0, void* l1, void* l2, void* l3);
static vader_box_t vader_front_resolver$name_in_folder(vader_string_t l0, vader_string_t l1);
static bool vader_front_resolver$names_equal(vader_box_t l0, vader_box_t l1);
static void* vader_front_resolver$new_import_target_table(void);
static void* vader_front_resolver$new_scope(void* l0);
static void* vader_front_resolver$new_subst(void);
static void* vader_front_resolver$next_clone_span(void* l0);
static void vader_front_resolver$note_rebind(void* l0, vader_box_t l1);
static uint8_t vader_front_resolver$origin_of_root(vader_string_t l0);
static void* vader_front_resolver$parse_file(vader_string_t l0, vader_string_t l1, bool l2);
static void* vader_front_resolver$parse_manifest(vader_string_t l0);
static void* vader_front_resolver$parse_module_files(void* l0, void* l1);
static void* vader_front_resolver$plain_root(vader_string_t l0, uint8_t l1);
static void vader_front_resolver$pop(void* l0);
static vader_box_t vader_front_resolver$posix_or_null(vader_box_t l0);
static void vader_front_resolver$preresolve_imports(void* l0, void* l1, void* l2, void* l3, void* l4);
static void* vader_front_resolver$project_include_paths(vader_box_t l0, void* l1, void* l2);
static void* vader_front_resolver$provided_names(void* l0);
static bool vader_front_resolver$provides_body(vader_string_t l0);
static void vader_front_resolver$push(void* l0);
static void* vader_front_resolver$read_manifest(vader_string_t l0);
static vader_string_t vader_front_resolver$read_with_overlay(void* l0, vader_string_t l1);
static void* vader_front_resolver$rebind_free_locals(void* l0);
static void* vader_front_resolver$registered_toolchain(void);
static void* vader_front_resolver$registered_toolchain$singleton(void);
static void vader_front_resolver$report_uncovered(void* l0, void* l1, void* l2, void* l3, void* l4);
static void vader_front_resolver$report_unreassigned_mutables(void* l0);
static void* vader_front_resolver$required_methods(void* l0);
static vader_box_t vader_front_resolver$resolve_decl(vader_box_t l0, void* l1, void* l2, void* l3);
static vader_box_t vader_front_resolver$resolve_in(void* l0, vader_string_t l1);
static vader_box_t vader_front_resolver$resolve_lazy(vader_string_t l0, void* l1, void* l2, void* l3, void* l4);
static void* vader_front_resolver$resolve_module_programs(void* l0, void* l1, vader_string_t l2, void* l3);
static vader_box_t vader_front_resolver$rooted_candidate(void* l0, vader_string_t l1);
static vader_box_t vader_front_resolver$scan_folder(vader_string_t l0, void* l1, void* l2);
static void* vader_front_resolver$search_roots(vader_string_t l0, void* l1, vader_box_t l2, void* l3, void* l4);
static vader_box_t vader_front_resolver$seed_entry(vader_string_t l0, void* l1, void* l2);
static void vader_front_resolver$seed_wildcard_exports(void* l0, void* l1, void* l2, void* l3);
static void* vader_front_resolver$select_target_bodies(void* l0, vader_box_t l1, void* l2);
static vader_box_t vader_front_resolver$selected_target_of(vader_box_t l0);
static vader_box_t vader_front_resolver$sidecar_root(vader_string_t l0, vader_string_t l1);
static void* vader_front_resolver$sort_by_name(void* l0);
static void* vader_front_resolver$source_files_in(vader_string_t l0, void* l1);
static vader_string_t vader_front_resolver$span_origin(void* l0);
static void vader_front_resolver$stamp_binding_spans(vader_box_t l0, void* l1);
static void vader_front_resolver$stamp_block_spans(void* l0, void* l1);
static void vader_front_resolver$stamp_expr_spans(vader_box_t l0, void* l1);
static void vader_front_resolver$stamp_pattern_spans(vader_box_t l0, void* l1);
static void vader_front_resolver$stamp_stmt_spans(vader_box_t l0, void* l1);
static vader_string_t vader_front_resolver$string_at(void* l0, vader_string_t l1, void* l2);
static void* vader_front_resolver$string_list(void* l0, vader_string_t l1, void* l2);
static vader_box_t vader_front_resolver$subst_opt_expr(vader_box_t l0, void* l1);
static void* vader_front_resolver$substitute_block(void* l0, void* l1);
static void* vader_front_resolver$substitute_block_materialized(void* l0, void* l1, void* l2, void* l3);
static vader_box_t vader_front_resolver$substitute_coalesce_fallback(vader_box_t l0, void* l1);
static vader_box_t vader_front_resolver$substitute_expr_full(vader_box_t l0, void* l1);
static vader_box_t vader_front_resolver$substitute_opt_type(vader_box_t l0, void* l1);
static void* vader_front_resolver$substitute_params(void* l0, void* l1);
static void* vader_front_resolver$substitute_params_disambiguated(void* l0, void* l1, void* l2, void* l3);
static void* vader_front_resolver$substitute_params_stamped(void* l0, void* l1, void* l2);
static vader_box_t vader_front_resolver$substitute_pattern(vader_box_t l0, void* l1);
static vader_box_t vader_front_resolver$substitute_stmt(vader_box_t l0, void* l1);
static vader_box_t vader_front_resolver$substitute_type_expr(vader_box_t l0, void* l1);
static void* vader_front_resolver$swap_root(void* l0, void* l1);
static void* vader_front_resolver$synth_clone_span(void* l0);
static void* vader_front_resolver$synth_signature(void* l0, void* l1, void* l2, void* l3, int64_t l4);
static void* vader_front_resolver$synth_with_body(void* l0, void* l1, void* l2, void* l3, void* l4, int64_t l5);
static void* vader_front_resolver$target_declarations(void* l0);
static vader_box_t vader_front_resolver$target_selectors(void* l0);
static vader_string_t vader_front_resolver$toolchain_base(void);
static vader_string_t vader_front_resolver$toolchain_folder(vader_box_t l0);
static vader_box_t vader_front_resolver$try_read(vader_string_t l0);
static vader_box_t vader_front_resolver$union_in_bound(vader_box_t l0);
static void vader_front_resolver$walk_block(void* l0, void* l1);
static void vader_front_resolver$walk_body(void* l0, void* l1);
static void vader_front_resolver$walk_decl(void* l0, vader_box_t l1);
static void vader_front_resolver$walk_decorators(void* l0, void* l1);
static void vader_front_resolver$walk_defer(void* l0, void* l1);
static void vader_front_resolver$walk_enum_decl(void* l0, void* l1);
static void vader_front_resolver$walk_expr(void* l0, vader_box_t l1);
static void vader_front_resolver$walk_fn_decl(void* l0, void* l1);
static void vader_front_resolver$walk_for(void* l0, void* l1);
static void vader_front_resolver$walk_if(void* l0, void* l1);
static void vader_front_resolver$walk_impl_decl(void* l0, void* l1);
static void vader_front_resolver$walk_import_cycle(vader_string_t l0, void* l1, void* l2, void* l3, void* l4);
static void vader_front_resolver$walk_lambda(void* l0, void* l1);
static void vader_front_resolver$walk_let(void* l0, void* l1);
static void vader_front_resolver$walk_match(void* l0, void* l1);
static void vader_front_resolver$walk_opt_expr(void* l0, vader_box_t l1);
static void vader_front_resolver$walk_stmt(void* l0, vader_box_t l1);
static void vader_front_resolver$walk_struct_decl(void* l0, void* l1);
static void vader_front_resolver$walk_struct_lit(void* l0, void* l1);
static void vader_front_resolver$walk_struct_lit_items(void* l0, void* l1);
static void vader_front_resolver$walk_trait_decl(void* l0, void* l1);
static void vader_front_resolver$warn_collision(void* l0, vader_string_t l1, void* l2);
static void* vader_front_resolver$wildcard_ambiguities(void* l0, void* l1, void* l2, void* l3);
static bool vader_front_resolver$wildcard_exposable(uint8_t l0);
static bool vader_front_resolver$wildcard_exposes(void* l0, vader_box_t l1);
static void vader_front_resolver$wire_module(void* l0, void* l1, void* l2, void* l3);
static void* vader_front_resolver$with_displayable_impls(void* l0);
static void* vader_front_resolver$zero_span(vader_string_t l0);

static void vader_front_resolver$add_fn(void* l0, void* l1, vader_string_t l2, vader_string_t l3, void* l4, void* l5) {
    uint8_t l6;
    void* l7 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    vader_string_t l8 = 0;
    vader_box_t l9 = vader_box_null();
    vader_string_t t0 = 0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l9 };
    void** gc_raw_roots[8] = { &l0, &l1, &l4, &l5, &l7, &l10, &l11, &t1 };
    vader_string_t* gc_atom_roots[4] = { &l2, &l3, &l8, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l6 = ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_visibility;
    t0 = ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_name;
    if (t0 == 2307u) {
        l6 = (uint8_t) 0;
    }
    l7 = ((vader_struct_vader_front_resolver$CollectedModule_t*) l0)->f_symbols;
    l8 = ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_name;
    l9 = std_collections$MutableMap$std_core$Index$at__string__Any(l7, l8);
    if (l9.tag == 892u) {
        t1 = l9.payload.obj;
        if (((vader_struct_vader_core_symbol$Symbol_t*) t1)->f_kind != INT32_C(0)) {
            l7 = ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_name_span;
            l8 = ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_name;
            l8 = concat_3(1038u, l8, 1056u);
            l7 = vader_support_diagnostics$resolver_error((uint8_t) 3, l7, l8);
            vader_array_push_ref((vader_array_t*) l5, l7);
            { vader_gc_top = gc_frame.prev; return; }
        }
    }
    l8 = ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_name;
    l7 = ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_name_span;
    l7 = vader_core_symbol$make(l4, (uint8_t) 0, l8, l2, l3, l6, vader_ref_box(l7));
    l10 = ((vader_struct_vader_front_resolver$CollectedModule_t*) l0)->f_fn_overloads;
    l8 = ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_name;
    l11 = (void*) &vader_fn_static___lambda_vader_front_resolver_3;
    t1 = std_collections$get_or_put_with__string__vader_core_symbol_Symbol__(l10, l8, l11);
    vader_array_push_ref((vader_array_t*) t1, l7);
    if (l9.tag == 0u) {
        l10 = ((vader_struct_vader_front_resolver$CollectedModule_t*) l0)->f_symbols;
        l8 = ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_name;
        std_collections$MutableMap$std_core$IndexSet$set_at__string__Any(l10, l8, vader_ref_box(l7));
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$add_named(void* l0, uint8_t l1, vader_string_t l2, void* l3, uint8_t l4, vader_string_t l5, vader_string_t l6, void* l7, void* l8) {
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
    l9 = std_collections$MutableMap$std_core$Index$at__string__Any(((vader_struct_vader_front_resolver$CollectedModule_t*) l0)->f_symbols, l2);
    if (l9.tag == 892u) {
        l10 = concat_3(1038u, l2, 1056u);
        l11 = vader_support_diagnostics$resolver_error((uint8_t) 3, l3, l10);
        vader_array_push_ref((vader_array_t*) l8, l11);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (!(l9.tag == 0u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    l11 = vader_core_symbol$make(l7, l1, l2, l5, l6, l4, vader_ref_box(l3));
    std_collections$MutableMap$std_core$IndexSet$set_at__string__Any(((vader_struct_vader_front_resolver$CollectedModule_t*) l0)->f_symbols, l2, vader_ref_box(l11));
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_front_resolver$any_has_body(void* l0) {
    void* l1;
    int64_t l2, l3;
    vader_box_t l4;
    void* t0;
    l1 = l0;
    l2 = ((vader_array_t*) l1)->length;
    l3 = INT64_C(0);
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        l4 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_body;
        if (l4.tag == 624u) {
            return true;
        }
        if (!(l4.tag == 0u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l3 = (l3 + INT64_C(1));
    }
    return false;
}

static vader_box_t vader_front_resolver$asset_problem(vader_string_t l0) {
    bool t0;
    vader_string_t t1 = 0;
    vader_string_t* gc_atom_roots[2] = { &l0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = vader_front_resolver$leaves_project(l0);
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t1 = concat_3(1599u, l0, 1181u);
    { vader_box_t __vret = vader_box_string(335u, t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_front_resolver$auto_bind_for_type_params(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l6 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null();
    vader_string_t l7 = 0;
    vader_string_t l8 = 0;
    vader_string_t l12 = 0;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l1, &l5, &t1 };
    void** gc_raw_roots[7] = { &l0, &l2, &l6, &l9, &l10, &l11, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l7, &l8, &l12 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!(l1.tag == 654u)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = l1.payload.obj;
    l2 = ((vader_struct_toolchain_ast$GenericInstExpr_t*) t0)->f_type_args;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        if (l5.tag == 655u) {
            l6 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope;
            t0 = l5.payload.obj;
            l7 = ((vader_struct_toolchain_ast$IdentExpr_t*) t0)->f_name;
            t1 = vader_front_resolver$lookup(l6, l7);
            if (t1.tag == 0u) {
                t0 = l5.payload.obj;
                l8 = ((vader_struct_toolchain_ast$IdentExpr_t*) t0)->f_name;
                t0 = l5.payload.obj;
                l9 = ((vader_struct_toolchain_ast$IdentExpr_t*) t0)->f_span;
                l10 = vader_front_resolver$mint_local(l0, (uint8_t) 9, l8, l9);
                l11 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope;
                t0 = l5.payload.obj;
                l12 = ((vader_struct_toolchain_ast$IdentExpr_t*) t0)->f_name;
                vader_front_resolver$bind(l11, l12, l10);
            }
        }
        l4 = (l4 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_front_resolver$baked_target_of(vader_box_t l0) {
    void* l1 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1407u) {
        l1 = l0.payload.obj;
        { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1405u) {
        l1 = vader_support_target$host_target();
    } else {
        if (!(l0.tag == 1406u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_support_target$HostBodies_t*) t0)->f_target;
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_front_resolver$bind(void* l0, vader_string_t l1, void* l2) {
    int64_t l3;
    void* l4 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l2, &l4, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_array_t*) ((vader_struct_vader_front_resolver$Scope_t*) l0)->f_frames)->length;
    if (!(l3 == INT64_C(0))) {
        l4 = ((vader_struct_vader_front_resolver$Scope_t*) l0)->f_frames;
        l3 = vader_chk_sub(i64, l3, INT64_C(1));
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        std_collections$MutableMap$std_core$IndexSet$set_at__string__Any(t0, l1, vader_ref_box(l2));
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$bind_1(void* l0, vader_string_t l1, vader_box_t l2) {
    std_collections$MutableMap$std_core$IndexSet$set_at__string__Any(((vader_struct_vader_front_resolver$Subst_t*) l0)->f_entries, l1, l2);
    return;
}

static void vader_front_resolver$bind_import(void* l0, vader_string_t l1, void* l2, vader_string_t l3, vader_box_t l4, vader_string_t l5, void* l6, void* l7) {
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
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_front_resolver$CollectedModule_t*) l0)->f_files);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
    l8 = std_collections$MutableMap$std_core$Index$at__string__Any(((vader_struct_vader_front_resolver$FileImports_t*) t0)->f_bindings, l1);
    if (l8.tag == 0u) {
        l9 = vader_core_symbol$make(l6, (uint8_t) 7, l1, l5, l5, (uint8_t) 1, vader_ref_box(l2));
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_front_resolver$CollectedModule_t*) l0)->f_files);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT32_C(0));
        std_collections$MutableMap$std_core$IndexSet$set_at__string__Any(((vader_struct_vader_front_resolver$FileImports_t*) t0)->f_bindings, l1, vader_ref_box(l9));
        l13 = ((vader_struct_vader_front_resolver$CollectedModule_t*) l0)->f_imports;
        l10 = ((vader_struct_vader_core_symbol$Symbol_t*) l9)->f_id;
        vader_struct_vader_front_resolver$ImportInfo_t* _a2_obj = (vader_struct_vader_front_resolver$ImportInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$ImportInfo_t));
        vader_obj_header_init(_a2_obj, 1091u);
        _a2_obj->f_path = l3;
        _a2_obj->f_imported_name = l4;
        _a2_obj->f_local = l1;
        _a2_obj->f_binding_span = l2;
        l14 = (void*) _a2_obj;
        std_collections$MutableMap$std_core$IndexSet$set_at__i32__Any(l13, l10, vader_ref_box(l14));
        { vader_gc_top = gc_frame.prev; return; }
    }
    l9 = ((vader_struct_vader_front_resolver$CollectedModule_t*) l0)->f_imports;
    t0 = l8.payload.obj;
    l10 = ((vader_struct_vader_core_symbol$Symbol_t*) t0)->f_id;
    l8 = std_collections$MutableMap$std_core$Index$at__i32__Any(l9, l10);
    if (!(l8.tag == 0u)) {
        t0 = l8.payload.obj;
        t1 = ((vader_struct_vader_front_resolver$ImportInfo_t*) t0)->f_path;
        if (t1 == l3) {
            t0 = l8.payload.obj;
            l11 = vader_front_resolver$names_equal(((vader_struct_vader_front_resolver$ImportInfo_t*) t0)->f_imported_name, l4);
        } else {
            l11 = false;
        }
        l11 = !(l11);
    } else {
        l11 = false;
    }
    if (l11) {
        l12 = concat_3(1038u, l1, 1038u);
        l9 = vader_support_diagnostics$resolver_error((uint8_t) 10, l2, l12);
        vader_array_push_ref((vader_array_t*) l7, l9);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$bind_let_binding(void* l0, vader_box_t l1, void* l2) {
    vader_string_t l3 = 0;
    void* l4 = NULL;
    void* l5 = NULL;
    uint64_t l6;
    int64_t l7, l8;
    vader_box_t l9 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l9 };
    void** gc_raw_roots[5] = { &l0, &l2, &l4, &l5, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1.tag == 689u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast$SimpleBinding_t*) t0)->f_name;
        t0 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_ast$SimpleBinding_t*) t0)->f_name_span;
        l4 = vader_front_resolver$bind_local_checked(l0, (uint8_t) 10, l3, l4);
        l5 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_idents;
        t0 = l1.payload.obj;
        l6 = toolchain_span$Span$std_core$Hash$hash(((vader_struct_toolchain_ast$SimpleBinding_t*) t0)->f_name_span);
        std_collections$MutableMap$std_core$IndexSet$set_at__u64__Any(l5, l6, vader_ref_box(l4));
        vader_array_push_ref((vader_array_t*) l2, l4);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 701u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_ast$TupleBinding_t*) t0)->f_elements;
        l7 = ((vader_array_t*) l4)->length;
        l8 = INT64_C(0);
        while ((l8 < l7)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            l9 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l8);
            vader_front_resolver$bind_let_binding(l0, l9, l2);
            l8 = (l8 + INT64_C(1));
        }
    } else if (!(l1.tag == 706u)) {
        if (!(l1.tag == 685u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast$RestBinding_t*) t0)->f_name;
        t0 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_ast$RestBinding_t*) t0)->f_span;
        l4 = vader_front_resolver$bind_local_checked(l0, (uint8_t) 10, l3, l4);
        l5 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_idents;
        t0 = l1.payload.obj;
        l6 = toolchain_span$Span$std_core$Hash$hash(((vader_struct_toolchain_ast$RestBinding_t*) t0)->f_span);
        std_collections$MutableMap$std_core$IndexSet$set_at__u64__Any(l5, l6, vader_ref_box(l4));
        vader_array_push_ref((vader_array_t*) l2, l4);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_front_resolver$bind_local(void* l0, uint8_t l1, vader_string_t l2, void* l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    int32_t l6;
    void** gc_raw_roots[4] = { &l0, &l3, &l4, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = vader_front_resolver$mint_local(l0, l1, l2, l3);
    vader_front_resolver$bind(((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope, l2, l4);
    l5 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_declared_locals;
    l6 = ((vader_struct_vader_core_symbol$Symbol_t*) l4)->f_id;
    vader_array_push_i32((vader_array_t*) l5, l6);
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$bind_local_checked(void* l0, uint8_t l1, vader_string_t l2, void* l3) {
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l3, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_front_resolver$warn_collision(l0, l2, l3);
    t0 = vader_front_resolver$bind_local(l0, l1, l2, l3);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_front_resolver$bind_param(void* l0, void* l1) {
    vader_string_t l2 = 0;
    void* l3 = NULL;
    void* l5 = NULL;
    uint64_t l4;
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast$FnParam_t*) l1)->f_name;
    l3 = ((vader_struct_toolchain_ast$FnParam_t*) l1)->f_name_span;
    vader_front_resolver$warn_collision(l0, l2, l3);
    l3 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_idents;
    l4 = toolchain_span$Span$std_core$Hash$hash(((vader_struct_toolchain_ast$FnParam_t*) l1)->f_span);
    l2 = ((vader_struct_toolchain_ast$FnParam_t*) l1)->f_name;
    l5 = ((vader_struct_toolchain_ast$FnParam_t*) l1)->f_span;
    l5 = vader_front_resolver$bind_local(l0, (uint8_t) 8, l2, l5);
    std_collections$MutableMap$std_core$IndexSet$set_at__u64__Any(l3, l4, vader_ref_box(l5));
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$bind_pattern(void* l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null(), l7 = vader_box_null(), l13 = vader_box_null();
    void* l3 = NULL;
    void* l6 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    int64_t l4, l5;
    vader_string_t l8 = 0;
    uint64_t l12;
    void* t0 = NULL;
    vader_box_t* gc_roots[4] = { &l1, &l2, &l7, &l13 };
    void** gc_raw_roots[7] = { &l0, &l3, &l6, &l9, &l10, &l11, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l8 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1.tag == 667u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_toolchain_ast$IsPattern_t*) t0)->f_ty;
        vader_front_resolver$walk_expr(l0, l2);
        t0 = l1.payload.obj;
        if (!(((vader_struct_toolchain_ast$IsPattern_t*) t0)->f_inner.tag == 0u)) {
            t0 = l1.payload.obj;
            l2 = ((vader_struct_toolchain_ast$IsPattern_t*) t0)->f_inner;
            vader_front_resolver$bind_pattern(l0, l2);
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 698u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast$StructPattern_t*) t0)->f_fields;
        l4 = ((vader_array_t*) l3)->length;
        l5 = INT64_C(0);
        while ((l5 < l4)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
            l6 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
            l2 = ((vader_struct_toolchain_ast$StructPatternField_t*) l6)->f_value;
            l7 = l2;
            if (l2.tag == 679u) {
                l8 = ((vader_struct_toolchain_ast$StructPatternField_t*) l6)->f_name;
                l9 = ((vader_struct_toolchain_ast$StructPatternField_t*) l6)->f_name_span;
                l10 = vader_front_resolver$bind_local(l0, (uint8_t) 11, l8, l9);
                l11 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_idents;
                l12 = toolchain_span$Span$std_core$Hash$hash(((vader_struct_toolchain_ast$StructPatternField_t*) l6)->f_name_span);
                std_collections$MutableMap$std_core$IndexSet$set_at__u64__Any(l11, l12, vader_ref_box(l10));
            } else {
                if (!(l2.tag == 680u)) {
                    vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                }
                t0 = l7.payload.obj;
                l13 = ((vader_struct_toolchain_ast$PatternLiteral_t*) t0)->f_value;
                vader_front_resolver$walk_expr(l0, l13);
            }
            l5 = (l5 + INT64_C(1));
        }
    } else if (!(l1.tag == 708u)) {
        if (!(l1.tag == 646u)) {
            if (l1.tag == 670u) {
                t0 = l1.payload.obj;
                l2 = ((vader_struct_toolchain_ast$LiteralPattern_t*) t0)->f_value;
                vader_front_resolver$walk_expr(l0, l2);
            } else if (l1.tag == 684u) {
                t0 = l1.payload.obj;
                l2 = ((vader_struct_toolchain_ast$RangePattern_t*) t0)->f_lower;
                vader_front_resolver$walk_expr(l0, l2);
                t0 = l1.payload.obj;
                l2 = ((vader_struct_toolchain_ast$RangePattern_t*) t0)->f_upper;
                vader_front_resolver$walk_expr(l0, l2);
            } else {
                if (!(l1.tag == 678u)) {
                    vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                }
                t0 = l1.payload.obj;
                l3 = ((vader_struct_toolchain_ast$OrPattern_t*) t0)->f_patterns;
                l4 = ((vader_array_t*) l3)->length;
                l5 = INT64_C(0);
                while ((l5 < l4)) {
                    vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
                    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
                    l2 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
                    vader_front_resolver$bind_pattern(l0, l2);
                    l5 = (l5 + INT64_C(1));
                }
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_front_resolver$bind_type_param(void* l0, void* l1) {
    vader_string_t l2 = 0;
    void* l3 = NULL;
    void* l4 = NULL;
    uint64_t l5;
    vader_box_t l6 = vader_box_null();
    vader_box_t* gc_roots[1] = { &l6 };
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &l4 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast$TypeParam_t*) l1)->f_name;
    l3 = ((vader_struct_toolchain_ast$TypeParam_t*) l1)->f_span;
    l3 = vader_front_resolver$mint_local(l0, (uint8_t) 9, l2, l3);
    l4 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_idents;
    l5 = toolchain_span$Span$std_core$Hash$hash(((vader_struct_toolchain_ast$TypeParam_t*) l1)->f_span);
    std_collections$MutableMap$std_core$IndexSet$set_at__u64__Any(l4, l5, vader_ref_box(l3));
    l4 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope;
    l2 = ((vader_struct_toolchain_ast$TypeParam_t*) l1)->f_name;
    vader_front_resolver$bind(l4, l2, l3);
    l6 = ((vader_struct_toolchain_ast$TypeParam_t*) l1)->f_bound;
    vader_front_resolver$walk_opt_expr(l0, l6);
    l6 = ((vader_struct_toolchain_ast$TypeParam_t*) l1)->f_default;
    vader_front_resolver$walk_opt_expr(l0, l6);
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$binding_clashes(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l13 = NULL;
    void* l16 = NULL;
    int64_t l6, l7;
    vader_string_t l8 = 0;
    vader_string_t l9 = 0;
    vader_string_t l15 = 0;
    vader_box_t l12 = vader_box_null(), l14 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l12, &l14, &t0 };
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l4, &l5, &l10, &l11, &l13, &l16 };
    vader_string_t* gc_atom_roots[3] = { &l8, &l9, &l15 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(217u, 0u, 13u, 1400u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_struct_vader_front_resolver$FileImports_t*) l1)->f_bindings;
    l4 = ((vader_struct_std_collections$MutableMap__string__vader_core_symbol_Symbol_t*) l3)->f_ekeys;
    l5 = ((vader_struct_std_collections$MutableMap__string__vader_core_symbol_Symbol_t*) l3)->f_evals;
    l6 = INT64_C(0);
    l7 = ((vader_struct_std_collections$MutableMap__string__vader_core_symbol_Symbol_t*) l3)->f_size;
    while ((l6 < l7)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        t0 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l6];
        l8 = t0.payload.s;
        vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
        l3 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l6);
        l9 = l8;
        l10 = l3;
        l12 = std_collections$MutableMap$std_core$Index$at__string__Any(((vader_struct_vader_front_resolver$CollectedModule_t*) l0)->f_symbols, l9);
        if (!(l12.tag == 0u)) {
            l11 = l12.payload.obj;
            l14 = ((vader_struct_vader_core_symbol$Symbol_t*) l10)->f_defined_at;
            if (!(l14.tag == 0u)) {
                l13 = l14.payload.obj;
                if (((vader_struct_vader_core_symbol$Symbol_t*) l11)->f_kind != INT32_C(0)) {
                    l15 = concat_3(1038u, l9, 1038u);
                    l16 = vader_support_diagnostics$resolver_error((uint8_t) 10, l13, l15);
                    vader_array_push_ref((vader_array_t*) l2, l16);
                }
            }
        }
        l6 = (l6 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$binding_span(vader_box_t l0) {
    void* l1;
    void* t0;
    if (l0.tag == 689u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast$SimpleBinding_t*) t0)->f_name_span;
        return l1;
    }
    if (l0.tag == 701u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast$TupleBinding_t*) t0)->f_span;
    } else if (l0.tag == 685u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast$RestBinding_t*) t0)->f_span;
    } else {
        if (!(l0.tag == 706u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast$WildcardBinding_t*) t0)->f_span;
    }
    return l1;
}

static bool vader_front_resolver$body_survives(void* l0, void* l1) {
    void* l2;
    void* l4;
    void* l7;
    void* l11;
    void* l12;
    vader_box_t l3, l10;
    int64_t l5, l6, l8, l9;
    void* t0;
    bool t1;
    l3 = ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_body;
    if (l3.tag == 0u) {
        return false;
    }
    l2 = l3.payload.obj;
    l4 = l1;
    l5 = ((vader_array_t*) l4)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
        l7 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) t0)->f_program)->f_decls;
        l8 = ((vader_array_t*) l7)->length;
        l9 = INT64_C(0);
        while ((l9 < l8)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            l3 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l9);
            if (l3.tag == 650u) {
                t0 = l3.payload.obj;
                l10 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_body;
                if (!(l10.tag == 0u)) {
                    t0 = l10.payload.obj;
                    l11 = ((vader_struct_toolchain_ast$BlockExpr_t*) t0)->f_span;
                    l12 = ((vader_struct_toolchain_ast$BlockExpr_t*) l2)->f_span;
                    t1 = toolchain_span$Span$std_core$Equals$equals(l11, l12);
                    if (t1) {
                        return true;
                    }
                }
            }
            l9 = (l9 + INT64_C(1));
        }
        l6 = (l6 + INT64_C(1));
    }
    return false;
}

void* vader_front_resolver$build_core_seed(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l5 = NULL;
    void* l10 = NULL;
    vader_box_t l4 = vader_box_null();
    int64_t l6, l7;
    vader_string_t l8 = 0;
    vader_string_t l9 = 0;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    bool t2;
    vader_box_t* gc_roots[2] = { &l4, &t1 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l5, &l10, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l8, &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 335u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 346u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections$MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 533u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l1 = (void*) _a3_obj;
    l4 = std_collections$MutableMap$std_core$Index$at__string__Any(((vader_struct_vader_front_resolver$LoadedProject_t*) l0)->f_modules, 505u);
    if (l4.tag == 1095u) {
        t0 = l4.payload.obj;
        l2 = ((vader_struct_vader_front_resolver$CollectedModule_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) t0)->f_collected)->f_symbols;
        l3 = ((vader_struct_std_collections$MutableMap__string__vader_core_symbol_Symbol_t*) l2)->f_ekeys;
        l5 = ((vader_struct_std_collections$MutableMap__string__vader_core_symbol_Symbol_t*) l2)->f_evals;
        l6 = INT64_C(0);
        l7 = ((vader_struct_std_collections$MutableMap__string__vader_core_symbol_Symbol_t*) l2)->f_size;
        while ((l6 < l7)) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l6)
            t1 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l6];
            l8 = t1.payload.s;
            vader_array_t* _a5_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l6)
            l2 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l6);
            l9 = l8;
            l10 = l2;
            std_collections$MutableMap$std_core$IndexSet$set_at__string__Any(l1, l9, vader_ref_box(l10));
            l6 = (l6 + INT64_C(1));
        }
    }
    l4 = vader_front_resolver$find_core_module_id(l0);
    if (l4.tag == 0u) {
        { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l8 = l4.payload.s;
    l4 = std_collections$MutableMap$std_core$Index$at__string__Any(((vader_struct_vader_front_resolver$LoadedProject_t*) l0)->f_modules, l8);
    if (l4.tag == 0u) {
        { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = l4.payload.obj;
    l2 = ((vader_struct_vader_front_resolver$CollectedModule_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l2)->f_collected)->f_symbols;
    l3 = ((vader_struct_std_collections$MutableMap__string__vader_core_symbol_Symbol_t*) l2)->f_ekeys;
    l5 = ((vader_struct_std_collections$MutableMap__string__vader_core_symbol_Symbol_t*) l2)->f_evals;
    l6 = INT64_C(0);
    l7 = ((vader_struct_std_collections$MutableMap__string__vader_core_symbol_Symbol_t*) l2)->f_size;
    while ((l6 < l7)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l6)
        t1 = vader_array_box_slots(_a6_slotarr->buf)[_a6_slotarr->offset + (size_t) l6];
        l8 = t1.payload.s;
        vader_array_t* _a7_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l6)
        l2 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l6);
        l9 = l8;
        l10 = l2;
        t2 = vader_front_resolver$wildcard_exposes(l10, vader_box_obj(0u, NULL));
        if (t2) {
            std_collections$MutableMap$std_core$IndexSet$set_at__string__Any(l1, l9, vader_ref_box(l10));
        }
        l6 = (l6 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$build_subst(void* l0, void* l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null(), l7 = vader_box_null(), l8 = vader_box_null();
    int64_t l4, l5;
    vader_string_t l6 = 0;
    void* t0 = NULL;
    vader_box_t* gc_roots[3] = { &l3, &l7, &l8 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_front_resolver$new_subst();
    l3 = ((vader_struct_toolchain_ast$ImplDecl_t*) l0)->f_for_type;
    vader_front_resolver$bind_1(l2, 799u, l3);
    l4 = ((vader_array_t*) ((vader_struct_toolchain_ast$TraitDecl_t*) l1)->f_type_params)->length;
    l5 = ((vader_array_t*) ((vader_struct_toolchain_ast$ImplDecl_t*) l0)->f_trait_args)->length;
    l4 = std_math$min_3(l4, l5);
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$TraitDecl_t*) l1)->f_type_params);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        l6 = ((vader_struct_toolchain_ast$TypeParam_t*) t0)->f_name;
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$ImplDecl_t*) l0)->f_trait_args);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        l3 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
        vader_front_resolver$bind_1(l2, l6, l3);
        l5 = (l5 + INT64_C(1));
    }
    l5 = ((vader_array_t*) ((vader_struct_toolchain_ast$TraitDecl_t*) l1)->f_type_params)->length;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$TraitDecl_t*) l1)->f_type_params);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        l7 = ((vader_struct_toolchain_ast$TypeParam_t*) t0)->f_default;
        if (l7.tag == 0u) break;
        l3 = l7;
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$TraitDecl_t*) l1)->f_type_params);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
        t0 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l4);
        l6 = ((vader_struct_toolchain_ast$TypeParam_t*) t0)->f_name;
        l8 = vader_front_resolver$substitute_type_expr(l3, l2);
        vader_front_resolver$bind_1(l2, l6, l8);
        l4 = (l4 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$builtin_type_names(void) {
    void* l0 = NULL;
    void* l2 = NULL;
    int64_t l1, l3;
    vader_string_t l4 = 0;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 335u);
    l0 = (void*) _a0_arr;
    t0 = (void*) &vader_data_24;
    l1 = ((vader_array_t*) t0)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l0, (int64_t) l1);
    l0 = (void*) _a1_arr;
    l2 = (void*) &vader_data_24;
    l1 = ((vader_array_t*) l2)->length;
    l3 = INT64_C(0);
    while ((l3 < l1)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l3);
        l4 = ((vader_struct_vader_core_types$PrimitiveMeta_t*) t0)->f_name;
        vader_array_push_scalar((vader_array_t*) l0, vader_box_string(335u, l4));
        l3 = (l3 + INT64_C(1));
    }
    l2 = (void*) &vader_data_12;
    l1 = ((vader_array_t*) l2)->length;
    l3 = INT64_C(0);
    while ((l3 < l1)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        t1 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l3];
        l4 = t1.payload.s;
        vader_array_push_scalar((vader_array_t*) l0, vader_box_string(335u, l4));
        l3 = (l3 + INT64_C(1));
    }
    { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_front_resolver$check_groups(void* l0, void* l1) {
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
    void* l28 = NULL;
    void* l29 = NULL;
    void* l31 = NULL;
    void* l32 = NULL;
    void* l41 = NULL;
    void* l42 = NULL;
    void* l48 = NULL;
    void* l49 = NULL;
    void* l50 = NULL;
    int64_t l6, l7, l8, l9, l15, l16, l33, l34;
    vader_box_t l10 = vader_box_null(), l12 = vader_box_null(), l14 = vader_box_null(), l39 = vader_box_null();
    vader_string_t l13 = 0;
    vader_string_t l17 = 0;
    vader_string_t l19 = 0;
    vader_string_t l20 = 0;
    vader_string_t l21 = 0;
    vader_string_t l23 = 0;
    vader_string_t l30 = 0;
    vader_string_t l36 = 0;
    vader_string_t l37 = 0;
    vader_string_t l38 = 0;
    vader_string_t l40 = 0;
    vader_string_t l43 = 0;
    vader_string_t l44 = 0;
    vader_string_t l45 = 0;
    vader_string_t l46 = 0;
    vader_string_t l47 = 0;
    uint8_t l35;
    void* t0 = NULL;
    bool t1;
    vader_string_t t2 = 0;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[5] = { &l10, &l12, &l14, &l39, &t3 };
    void** gc_raw_roots[23] = {
        &l0, &l1, &l2, &l3, &l4, &l5, &l11, &l18, &l22, &l24, &l25, &l26, &l27, &l28, &l29, &l31,
        &l32, &l41, &l42, &l48, &l49, &l50, &t0,
    };
    vader_string_t* gc_atom_roots[17] = {
        &l13, &l17, &l19, &l20, &l21, &l23, &l30, &l36, &l37, &l38, &l40, &l43, &l44, &l45, &l46,
        &l47, &t2,
    };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 5u, 23u, gc_roots, gc_raw_roots, 0u, NULL, 17u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 335u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 346u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections$MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 533u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l2 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(21u, 0u, 0u, 335u);
    l3 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(28u, 0u, 0u, 346u);
    l4 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(22u, 0u, 7u, 338u);
    l5 = (void*) _a6_arr;
    vader_struct_std_collections$MutableMap__string__Any_t* _a7_obj = (vader_struct_std_collections$MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__Any_t));
    vader_obj_header_init(_a7_obj, 533u);
    _a7_obj->f_ekeys = l3;
    _a7_obj->f_evals = l4;
    _a7_obj->f_index = l5;
    _a7_obj->f_mask = INT64_C(0);
    _a7_obj->f_grow_at = INT64_C(0);
    _a7_obj->f_size = INT64_C(0);
    _a7_obj->f_tombs = INT64_C(0);
    l3 = (void*) _a7_obj;
    l4 = l0;
    l6 = ((vader_array_t*) l4)->length;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a8_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        t0 = vader_array_ref_load_obj(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l7);
        l5 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) t0)->f_program)->f_decls;
        l8 = ((vader_array_t*) l5)->length;
        l9 = INT64_C(0);
        while ((l9 < l8)) {
            vader_array_t* _a9_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            l10 = vader_array_ref_load_box(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l9);
            if (l10.tag == 650u) {
                t0 = l10.payload.obj;
                l12 = vader_front_resolver$target_selectors(((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_decorators);
                if (l12.tag == 0u) {
                    l9 = (l9 + INT64_C(1));
                    continue;
                }
                l11 = l12.payload.obj;
                t1 = ((vader_struct_vader_front_resolver$TargetSelectors_t*) l11)->f_is_bare;
                if (t1) {
                    t0 = l10.payload.obj;
                    l13 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_name;
                    l14 = std_collections$MutableMap$std_core$Index$at__string__Any(l2, l13);
                    if (l14.tag == 0u) {
                        t0 = l10.payload.obj;
                        l23 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_name;
                        l24 = l10.payload.obj;
                        std_collections$MutableMap$std_core$IndexSet$set_at__string__Any(l2, l23, vader_ref_box(l24));
                    } else {
                        t0 = l14.payload.obj;
                        l15 = ((vader_array_t*) ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_params)->length;
                        t0 = l10.payload.obj;
                        l16 = ((vader_array_t*) ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_params)->length;
                        if (l15 != l16) {
                            l17 = 48u;
                        } else {
                            l17 = 0u;
                        }
                        t0 = l10.payload.obj;
                        l18 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_name_span;
                        t0 = l10.payload.obj;
                        l19 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_name;
                        t0 = l14.payload.obj;
                        l20 = vader_front_resolver$span_origin(((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_name_span);
                        l21 = concat_5(1038u, l19, 1146u, l20, l17);
                        l22 = vader_support_diagnostics$resolver_error((uint8_t) 30, l18, l21);
                        vader_array_push_ref((vader_array_t*) l1, l22);
                        l9 = (l9 + INT64_C(1));
                        continue;
                    }
                } else {
                    l9 = (l9 + INT64_C(1));
                    continue;
                }
            }
            l9 = (l9 + INT64_C(1));
        }
        l7 = (l7 + INT64_C(1));
    }
    l4 = l0;
    l6 = ((vader_array_t*) l4)->length;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a10_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        t0 = vader_array_ref_load_obj(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l7);
        l5 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) t0)->f_program)->f_decls;
        l8 = ((vader_array_t*) l5)->length;
        l9 = INT64_C(0);
        while ((l9 < l8)) {
            vader_array_t* _a11_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
            l10 = vader_array_ref_load_box(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l9);
            if (l10.tag == 650u) {
                t0 = l10.payload.obj;
                l12 = vader_front_resolver$target_selectors(((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_decorators);
                if (l12.tag == 0u) {
                    l9 = (l9 + INT64_C(1));
                    continue;
                }
                t0 = l12.payload.obj;
                t1 = ((vader_struct_vader_front_resolver$TargetSelectors_t*) t0)->f_is_bare;
                if (t1) {
                    l9 = (l9 + INT64_C(1));
                    continue;
                }
                t0 = l10.payload.obj;
                l13 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_name;
                l14 = std_collections$MutableMap$std_core$Index$at__string__Any(l2, l13);
                if (l14.tag == 0u) {
                    t0 = l10.payload.obj;
                    l11 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_name_span;
                    t0 = l10.payload.obj;
                    l17 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_name;
                    l19 = concat_3(1038u, l17, 1108u);
                    l18 = vader_support_diagnostics$resolver_error((uint8_t) 27, l11, l19);
                    vader_array_push_ref((vader_array_t*) l1, l18);
                } else {
                    l22 = l14.payload.obj;
                    l24 = l10.payload.obj;
                    vader_front_resolver$check_signature(l22, l24, l1);
                }
                t0 = l10.payload.obj;
                if (((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_visibility == INT32_C(0)) {
                    t0 = l10.payload.obj;
                    l25 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_name_span;
                    t0 = l10.payload.obj;
                    l20 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_name;
                    l21 = concat_3(1038u, l20, 1139u);
                    l26 = vader_support_diagnostics$resolver_error((uint8_t) 28, l25, l21);
                    vader_array_push_ref((vader_array_t*) l1, l26);
                }
                t0 = l10.payload.obj;
                l27 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_decorators;
                l15 = ((vader_array_t*) l27)->length;
                l16 = INT64_C(0);
                while ((l16 < l15)) {
                    vader_array_t* _a12_slotarr = ((vader_array_t*) l27);
                    VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
                    l28 = vader_array_ref_load_obj(_a12_slotarr->buf, _a12_slotarr->offset + (size_t) l16);
                    t2 = ((vader_struct_toolchain_ast$Decorator_t*) l28)->f_name;
                    if (t2 != 2698u) {
                        t2 = ((vader_struct_toolchain_ast$Decorator_t*) l28)->f_name;
                        t1 = vader_front_resolver$provides_body(t2);
                        if (!(t1)) {
                            l29 = ((vader_struct_toolchain_ast$Decorator_t*) l28)->f_span;
                            l23 = ((vader_struct_toolchain_ast$Decorator_t*) l28)->f_name;
                            l30 = concat_3(1337u, l23, 1069u);
                            l31 = vader_support_diagnostics$resolver_error((uint8_t) 28, l29, l30);
                            vader_array_push_ref((vader_array_t*) l1, l31);
                        }
                    }
                    l16 = (l16 + INT64_C(1));
                }
                t0 = l12.payload.obj;
                l32 = ((vader_struct_vader_front_resolver$TargetSelectors_t*) t0)->f_os;
                l33 = ((vader_array_t*) l32)->length;
                l34 = INT64_C(0);
                while ((l34 < l33)) {
                    vader_array_t* _a13_slotarr = ((vader_array_t*) l32);
                    VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
                    t3 = vader_array_read_u8(_a13_slotarr, _a13_slotarr->offset + (size_t) l34, 340u);
                    l35 = ((uint8_t) t3.payload.i);
                    t0 = l10.payload.obj;
                    l36 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_name;
                    l37 = std_target$Os$std_core$Display$to_string(l35);
                    l38 = concat_3(l36, 3068u, l37);
                    l39 = std_collections$MutableMap$std_core$Index$at__string__Any(l3, l38);
                    if (l39.tag == 0u) {
                        t0 = l10.payload.obj;
                        l50 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_name_span;
                        std_collections$MutableMap$std_core$IndexSet$set_at__string__Any(l3, l38, vader_ref_box(l50));
                    } else {
                        l41 = l39.payload.obj;
                        t0 = l10.payload.obj;
                        l42 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_name_span;
                        t1 = toolchain_span$Span$std_core$Equals$equals(l41, l42);
                        if (t1) {
                            t0 = l10.payload.obj;
                            l43 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_name;
                            l44 = std_target$Os$std_core$Display$to_string(l35);
                            l40 = concat_5(1038u, l43, 1195u, l44, 1261u);
                        } else {
                            t0 = l10.payload.obj;
                            l45 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_name;
                            l46 = std_target$Os$std_core$Display$to_string(l35);
                            t0 = l39.payload.obj;
                            l47 = vader_front_resolver$span_origin(t0);
                            l40 = concat_6(1038u, l45, 1057u, l46, 1066u, l47);
                        }
                        t0 = l10.payload.obj;
                        l48 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_name_span;
                        l49 = vader_support_diagnostics$resolver_error((uint8_t) 29, l48, l40);
                        vader_array_push_ref((vader_array_t*) l1, l49);
                    }
                    l34 = (l34 + INT64_C(1));
                }
            }
            l9 = (l9 + INT64_C(1));
        }
        l7 = (l7 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$check_import_form_conflict(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l13 = NULL;
    void* l15 = NULL;
    void* l19 = NULL;
    void* l22 = NULL;
    void* l24 = NULL;
    int64_t l6, l7;
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
    vader_box_t* gc_roots[3] = { &l8, &l9, &t1 };
    void** gc_raw_roots[12] = { &l0, &l1, &l2, &l3, &l4, &l5, &l13, &l15, &l19, &l22, &l24, &t0 };
    vader_string_t* gc_atom_roots[9] = { &l10, &l11, &l12, &l14, &l16, &l18, &l20, &l21, &l23 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 9u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 335u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 346u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections$MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 533u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l2 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(21u, 0u, 0u, 335u);
    l3 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(28u, 0u, 0u, 346u);
    l4 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(22u, 0u, 7u, 338u);
    l5 = (void*) _a6_arr;
    vader_struct_std_collections$MutableMap__string__Any_t* _a7_obj = (vader_struct_std_collections$MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__Any_t));
    vader_obj_header_init(_a7_obj, 533u);
    _a7_obj->f_ekeys = l3;
    _a7_obj->f_evals = l4;
    _a7_obj->f_index = l5;
    _a7_obj->f_mask = INT64_C(0);
    _a7_obj->f_grow_at = INT64_C(0);
    _a7_obj->f_size = INT64_C(0);
    _a7_obj->f_tombs = INT64_C(0);
    l3 = (void*) _a7_obj;
    l4 = l0;
    l6 = ((vader_array_t*) l4)->length;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a8_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        l8 = vader_array_ref_load_box(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l7);
        if (l8.tag == 660u) {
            t0 = l8.payload.obj;
            l9 = ((vader_struct_toolchain_ast$ImportDecl_t*) t0)->f_binding;
            if (l9.tag == 707u) {
                t0 = l8.payload.obj;
                l10 = ((vader_struct_toolchain_ast$ImportDecl_t*) t0)->f_path;
                t1 = std_collections$MutableMap$std_core$Index$at__string__Any(l3, l10);
                if (!(t1.tag == 0u)) {
                    t0 = l8.payload.obj;
                    l5 = ((vader_struct_toolchain_ast$ImportDecl_t*) t0)->f_span;
                    t0 = l8.payload.obj;
                    l11 = ((vader_struct_toolchain_ast$ImportDecl_t*) t0)->f_path;
                    l12 = concat_3(1038u, l11, 1038u);
                    l13 = vader_support_diagnostics$resolver_error((uint8_t) 23, l5, l12);
                    vader_array_push_ref((vader_array_t*) l1, l13);
                }
                t0 = l8.payload.obj;
                l14 = ((vader_struct_toolchain_ast$ImportDecl_t*) t0)->f_path;
                t0 = l8.payload.obj;
                l15 = ((vader_struct_toolchain_ast$ImportDecl_t*) t0)->f_span;
                std_collections$MutableMap$std_core$IndexSet$set_at__string__Any(l2, l14, vader_ref_box(l15));
            } else if (l9.tag == 638u) {
                t0 = l8.payload.obj;
                l16 = ((vader_struct_toolchain_ast$ImportDecl_t*) t0)->f_path;
                t1 = std_collections$MutableMap$std_core$Index$at__string__Any(l2, l16);
                if (!(t1.tag == 0u)) {
                    l17 = true;
                } else {
                    t0 = l8.payload.obj;
                    l18 = ((vader_struct_toolchain_ast$ImportDecl_t*) t0)->f_path;
                    t1 = std_collections$MutableMap$std_core$Index$at__string__Any(l3, l18);
                    l17 = !(t1.tag == 0u);
                }
                if (l17) {
                    t0 = l8.payload.obj;
                    l19 = ((vader_struct_toolchain_ast$ImportDecl_t*) t0)->f_span;
                    t0 = l8.payload.obj;
                    l20 = ((vader_struct_toolchain_ast$ImportDecl_t*) t0)->f_path;
                    l21 = concat_3(1038u, l20, 1038u);
                    l22 = vader_support_diagnostics$resolver_error((uint8_t) 23, l19, l21);
                    vader_array_push_ref((vader_array_t*) l1, l22);
                }
                t0 = l8.payload.obj;
                l23 = ((vader_struct_toolchain_ast$ImportDecl_t*) t0)->f_path;
                t0 = l8.payload.obj;
                l24 = ((vader_struct_toolchain_ast$ImportDecl_t*) t0)->f_span;
                std_collections$MutableMap$std_core$IndexSet$set_at__string__Any(l3, l23, vader_ref_box(l24));
            }
        }
        l7 = (l7 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$check_orphan_rule(void* l0, vader_string_t l1, void* l2, void* l3, void* l4, void* l5, void* l6) {
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
    l8 = vader_front_resolver$lookup_trait_sym(l0, l2, l3, l5);
    if (l8.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l7 = l8.payload.obj;
    if (((vader_struct_vader_core_symbol$Symbol_t*) l7)->f_kind != INT32_C(3)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l8 = vader_front_resolver$for_type_owner_sym(((vader_struct_toolchain_ast$ImplDecl_t*) l0)->f_for_type, l4, l5);
    l9 = false;
    l10 = false;
    if (l8.tag == 892u) {
        t0 = l8.payload.obj;
        l9 = ((vader_struct_vader_core_symbol$Symbol_t*) t0)->f_kind == INT32_C(12);
        t0 = l8.payload.obj;
        t1 = ((vader_struct_vader_core_symbol$Symbol_t*) t0)->f_module;
        l10 = t1 == l1;
    }
    t1 = ((vader_struct_vader_core_symbol$Symbol_t*) l7)->f_module;
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
    l7 = ((vader_struct_toolchain_ast$ImplDecl_t*) l0)->f_span;
    l12 = ((vader_struct_toolchain_ast$ImplDecl_t*) l0)->f_trait_name;
    l13 = vader_front_resolver$for_type_display_name(((vader_struct_toolchain_ast$ImplDecl_t*) l0)->f_for_type);
    l12 = concat_4(l12, 125u, l13, 55u);
    l7 = vader_support_diagnostics$resolver_error((uint8_t) 13, l7, l12);
    vader_array_push_ref((vader_array_t*) l6, l7);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$check_selectors(void* l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    void* l9 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l17 = NULL;
    void* l20 = NULL;
    void* l21 = NULL;
    void* l22 = NULL;
    int64_t l3, l4, l6, l7, l10, l11, l14, l15;
    vader_box_t l8 = vader_box_null(), l16 = vader_box_null();
    vader_string_t l18 = 0;
    vader_string_t l19 = 0;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_string_t t2 = 0;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l8, &l16, &t3 };
    void** gc_raw_roots[12] = { &l0, &l1, &l2, &l5, &l9, &l12, &l13, &l17, &l20, &l21, &l22, &t0 };
    vader_string_t* gc_atom_roots[4] = { &l18, &l19, &t1, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        l5 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) t0)->f_program)->f_decls;
        l6 = ((vader_array_t*) l5)->length;
        l7 = INT64_C(0);
        while ((l7 < l6)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            l8 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l7);
            if (l8.tag == 650u) {
                t0 = l8.payload.obj;
                l9 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_decorators;
                l10 = ((vader_array_t*) l9)->length;
                l11 = INT64_C(0);
                while ((l11 < l10)) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) l9);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    l12 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l11);
                    t1 = ((vader_struct_toolchain_ast$Decorator_t*) l12)->f_name;
                    if (t1 != 2698u) {
                        l11 = (l11 + INT64_C(1));
                        continue;
                    }
                    l13 = ((vader_struct_toolchain_ast$Decorator_t*) l12)->f_args;
                    l14 = ((vader_array_t*) l13)->length;
                    l15 = INT64_C(0);
                    while ((l15 < l14)) {
                        vader_array_t* _a3_slotarr = ((vader_array_t*) l13);
                        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                        l16 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l15);
                        if (l16.tag == 643u) {
                            t0 = l16.payload.obj;
                            t1 = ((vader_struct_toolchain_ast$DotVariantExpr_t*) t0)->f_variant;
                            t2 = std_string$to_lower(t1);
                            t3 = vader_support_target$parse_os(t2);
                            if (t3.tag == 0u) {
                                t0 = l16.payload.obj;
                                l17 = ((vader_struct_toolchain_ast$DotVariantExpr_t*) t0)->f_span;
                                t0 = l16.payload.obj;
                                l18 = ((vader_struct_toolchain_ast$DotVariantExpr_t*) t0)->f_variant;
                                l19 = concat_3(1315u, l18, 1209u);
                                l20 = vader_support_diagnostics$resolver_error((uint8_t) 26, l17, l19);
                                vader_array_push_ref((vader_array_t*) l1, l20);
                            }
                        } else {
                            l21 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l16.payload.obj);
                            l22 = vader_support_diagnostics$resolver_error((uint8_t) 26, l21, 1429u);
                            vader_array_push_ref((vader_array_t*) l1, l22);
                        }
                        l15 = (l15 + INT64_C(1));
                    }
                    l11 = (l11 + INT64_C(1));
                }
            }
            l7 = (l7 + INT64_C(1));
        }
        l4 = (l4 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$check_short_impl_arity(void* l0, void* l1, void* l2) {
    int64_t l3, l4, l5, l9, l11;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l10 = NULL;
    void* l13 = NULL;
    vader_string_t l8 = 0;
    vader_string_t l12 = 0;
    void* t0 = NULL;
    bool t1;
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l6, &l7, &l10, &l13, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l8, &l12 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 8u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_front_resolver$required_methods(((vader_struct_toolchain_ast$TraitDecl_t*) l1)->f_members);
    l3 = ((vader_array_t*) t0)->length;
    if (l3 == INT64_C(1)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l4 = INT64_C(0);
    l5 = ((vader_array_t*) ((vader_struct_toolchain_ast$ImplDecl_t*) l0)->f_members)->length;
    while ((l4 < l5)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$ImplDecl_t*) l0)->f_members);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l6 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t1 = ((vader_struct_toolchain_ast$FnDecl_t*) l6)->f_sam_synthetic;
        if (t1) {
            l7 = ((vader_struct_toolchain_ast$FnDecl_t*) l6)->f_span;
            l8 = ((vader_struct_toolchain_ast$ImplDecl_t*) l0)->f_trait_name;
            l9 = vader_host_std_core$byte_len(l8);
            l10 = (void*) vader_buffer_new((size_t) (INT64_C(50) + l9));
            l11 = INT64_C(0);
            l11 = std_core$write_string_at(l10, l11, 2741u);
            l11 = std_core$write_string_at(l10, l11, l8);
            l11 = std_core$write_string_at(l10, l11, 1099u);
            l11 = std_core$write_int(l10, l11, l3);
            l11 = std_core$write_string_at(l10, l11, 205u);
            l12 = std_core$finish_buffer(l10, l11);
            l13 = vader_support_diagnostics$resolver_error((uint8_t) 12, l7, l12);
            vader_array_push_ref((vader_array_t*) l2, l13);
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$ImplDecl_t*) l0)->f_members);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
            t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
            ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_materialized = true;
        }
        l4 = (l4 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$check_signature(void* l0, void* l1, void* l2) {
    int64_t l3, l4, l12, l13, l14, l15, l16, l17, l18;
    void* l5 = NULL;
    void* l8 = NULL;
    void* l22 = NULL;
    vader_string_t l6 = 0;
    vader_string_t l7 = 0;
    vader_string_t l9 = 0;
    vader_string_t l10 = 0;
    vader_string_t l11 = 0;
    vader_string_t l19 = 0;
    vader_string_t l20 = 0;
    vader_string_t l21 = 0;
    void* t0 = NULL;
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l5, &l8, &l22, &t0 };
    vader_string_t* gc_atom_roots[8] = { &l6, &l7, &l9, &l10, &l11, &l19, &l20, &l21 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 7u, NULL, gc_raw_roots, 0u, NULL, 8u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_array_t*) ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_params)->length;
    l4 = ((vader_array_t*) ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_params)->length;
    if (l3 != l4) {
        l5 = ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_name_span;
        l6 = ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_name;
        l7 = vader_front_resolver$span_origin(((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_name_span);
        l3 = vader_host_std_core$byte_len(l6);
        l4 = vader_host_std_core$byte_len(l7);
        l3 = (l3 + l4);
        l8 = (void*) vader_buffer_new((size_t) (INT64_C(48) + l3));
        l3 = INT64_C(0);
        l3 = std_core$write_string_at(l8, l3, 1038u);
        l3 = std_core$write_string_at(l8, l3, l6);
        l3 = std_core$write_string_at(l8, l3, 1245u);
        l4 = ((vader_array_t*) ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_params)->length;
        l3 = std_core$write_int(l8, l3, l4);
        l3 = std_core$write_string_at(l8, l3, 197u);
        l3 = std_core$write_string_at(l8, l3, l7);
        l3 = std_core$write_string_at(l8, l3, 360u);
        l6 = std_core$finish_buffer(l8, l3);
        l8 = (void*) vader_buffer_new((size_t) INT64_C(36));
        l3 = INT64_C(0);
        l3 = std_core$write_string_at(l8, l3, 2726u);
        l4 = ((vader_array_t*) ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_params)->length;
        l3 = std_core$write_int(l8, l3, l4);
        l7 = std_core$finish_buffer(l8, l3);
        l6 = concat_2(l6, l7);
        l5 = vader_support_diagnostics$resolver_error((uint8_t) 31, l5, l6);
        vader_array_push_ref((vader_array_t*) l2, l5);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = INT64_C(0);
    l4 = ((vader_array_t*) ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_params)->length;
    while ((l3 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_params);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        l6 = ((vader_struct_toolchain_ast$FnParam_t*) t0)->f_name;
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_params);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
        l7 = ((vader_struct_toolchain_ast$FnParam_t*) t0)->f_name;
        if (l6 != l7) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_params);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
            t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l3);
            l5 = ((vader_struct_toolchain_ast$FnParam_t*) t0)->f_span;
            l9 = ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_name;
            l10 = l6;
            l11 = vader_front_resolver$span_origin(((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_name_span);
            l12 = vader_host_std_core$byte_len(l9);
            l13 = vader_host_std_core$byte_len(l10);
            l14 = (l12 + l13);
            l15 = vader_host_std_core$byte_len(l11);
            l16 = (l14 + l15);
            l8 = (void*) vader_buffer_new((size_t) (INT64_C(48) + l16));
            l17 = INT64_C(0);
            l17 = std_core$write_string_at(l8, l17, 2454u);
            l18 = vader_chk_add(i64, l3, INT64_C(1));
            l17 = std_core$write_int(l8, l17, l18);
            l17 = std_core$write_string_at(l8, l17, 185u);
            l17 = std_core$write_string_at(l8, l17, l9);
            l17 = std_core$write_string_at(l8, l17, 1136u);
            l17 = std_core$write_string_at(l8, l17, l10);
            l17 = std_core$write_string_at(l8, l17, 1066u);
            l17 = std_core$write_string_at(l8, l17, l11);
            l17 = std_core$write_string_at(l8, l17, 360u);
            l19 = std_core$finish_buffer(l8, l17);
            l20 = concat_3(1038u, l7, 1122u);
            l21 = concat_3(l19, l20, 1791u);
            l22 = vader_support_diagnostics$resolver_error((uint8_t) 31, l5, l21);
            vader_array_push_ref((vader_array_t*) l2, l22);
        }
        l3 = (l3 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$check_target_selectors(void* l0, void* l1) {
    void* l2 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null();
    vader_string_t l8 = 0;
    vader_string_t l9 = 0;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_string_t t2 = 0;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l5, &t3 };
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l6, &l7, &l10, &l11, &l12, &l13, &t0 };
    vader_string_t* gc_atom_roots[4] = { &l8, &l9, &t1, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast$Decorator_t*) l1)->f_args;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        if (l5.tag == 643u) {
            t0 = l5.payload.obj;
            t1 = ((vader_struct_toolchain_ast$DotVariantExpr_t*) t0)->f_variant;
            t2 = std_string$to_lower(t1);
            t3 = vader_support_target$parse_os(t2);
            if (t3.tag == 0u) {
                l6 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_diags;
                t0 = l5.payload.obj;
                l7 = ((vader_struct_toolchain_ast$DotVariantExpr_t*) t0)->f_span;
                t0 = l5.payload.obj;
                l8 = ((vader_struct_toolchain_ast$DotVariantExpr_t*) t0)->f_variant;
                l9 = concat_3(1315u, l8, 1209u);
                l10 = vader_support_diagnostics$resolver_error((uint8_t) 26, l7, l9);
                vader_array_push_ref((vader_array_t*) l6, l10);
            }
        } else {
            l11 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_diags;
            l12 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l5.payload.obj);
            l13 = vader_support_diagnostics$resolver_error((uint8_t) 26, l12, 1927u);
            vader_array_push_ref((vader_array_t*) l11, l13);
        }
        l4 = (l4 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$check_wildcard_ambiguity(void* l0, vader_string_t l1, void* l2, void* l3) {
    vader_string_t l4 = 0;
    vader_string_t l5 = 0;
    void* l6 = NULL;
    void* l8 = NULL;
    vader_box_t l7 = vader_box_null();
    vader_box_t* gc_roots[1] = { &l7 };
    void** gc_raw_roots[5] = { &l0, &l2, &l3, &l6, &l8 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l4, &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_core_symbol$Symbol_t*) l3)->f_module;
    l5 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_module_path;
    if (l4 == l5) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l7 = std_collections$MutableMap$std_core$Index$at__string__string__(((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_ambiguous, l1);
    if (l7.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l6 = l7.payload.obj;
    l8 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_diags;
    l4 = vader_support_diagnostics$wildcard_clash_detail(l1, l6);
    l6 = vader_support_diagnostics$resolver_error((uint8_t) 22, l2, l4);
    vader_array_push_ref((vader_array_t*) l8, l6);
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_front_resolver$checked_bound(void* l0, void* l1, vader_box_t l2) {
    void* l3 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    vader_box_t l4 = vader_box_null();
    int64_t l8, l9;
    bool l10;
    vader_string_t l11 = 0;
    vader_string_t l12 = 0;
    bool t0;
    void* t1 = NULL;
    vader_string_t t2 = 0;
    int64_t t3;
    vader_box_t t4 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l2, &l4, &t4 };
    void** gc_raw_roots[7] = { &l0, &l1, &l3, &l5, &l6, &l7, &t1 };
    vader_string_t* gc_atom_roots[3] = { &l11, &l12, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_toolchain_ast$TypeParam_t*) l1)->f_is_comptime_value;
    if (t0) {
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = vader_front_resolver$union_in_bound(l2);
    if (l4.tag == 0u) {
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = l4.payload.obj;
    l5 = toolchain_ast$collect_bitor_variants(vader_ref_box(l3));
    vader_array_t* _a0_arr = vader_array_new(238u, 0u, 13u, 1591u);
    l6 = (void*) _a0_arr;
    l7 = l5;
    l8 = ((vader_array_t*) l7)->length;
    l9 = INT64_C(0);
    while ((l9 < l8)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l4 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l9);
        if (!(l4.tag == 655u)) {
            l10 = true;
        } else {
            t1 = l4.payload.obj;
            t2 = ((vader_struct_toolchain_ast$IdentExpr_t*) t1)->f_name;
            l10 = t2 != 2416u;
        }
        if (l10) {
            vader_array_push_ref((vader_array_t*) l6, l4.payload.obj);
        }
        l9 = (l9 + INT64_C(1));
    }
    l8 = ((vader_array_t*) l6)->length;
    l9 = ((vader_array_t*) l5)->length;
    if ((l8 < l9)) {
        l11 = ((vader_struct_toolchain_ast$TypeParam_t*) l1)->f_name;
        l12 = ((vader_struct_toolchain_ast$TypeParam_t*) l1)->f_name;
        l11 = concat_5(2484u, l11, 1193u, l12, 237u);
    } else {
        l11 = 1439u;
    }
    l5 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_diags;
    l3 = ((vader_struct_toolchain_ast$BinaryExpr_t*) l3)->f_span;
    l12 = ((vader_struct_toolchain_ast$TypeParam_t*) l1)->f_name;
    l11 = concat_5(1038u, l12, 1040u, l11, 321u);
    l3 = vader_support_diagnostics$resolver_error((uint8_t) 33, l3, l11);
    vader_array_push_ref((vader_array_t*) l5, l3);
    t3 = ((vader_array_t*) l6)->length;
    if (t3 == INT64_C(1)) {
        if (l2.tag == 623u) {
            t1 = l2.payload.obj;
            if (((vader_struct_toolchain_ast$BinaryExpr_t*) t1)->f_op == INT32_C(8)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                t4 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT32_C(0));
                { vader_box_t __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
            }
            { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_resolver$clone_assign_value(void* l0, vader_box_t l1, void* l2) {
    vader_box_t l3 = vader_box_null();
    void* l4 = NULL;
    uint8_t l5;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[3] = { &l1, &l3, &t0 };
    void** gc_raw_roots[4] = { &l0, &l2, &l4, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = toolchain_ast$compound_assign_op(l0);
    if (t0.tag == 0u) {
        t0 = vader_front_resolver$substitute_expr_full(((vader_struct_toolchain_ast$AssignStmt_t*) l0)->f_value, l2);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((vader_struct_toolchain_ast$AssignStmt_t*) l0)->f_value;
    if (l3.tag == 623u) {
        t1 = l3.payload.obj;
        l4 = ((vader_struct_toolchain_ast$BinaryExpr_t*) t1)->f_span;
        t1 = l3.payload.obj;
        l5 = ((vader_struct_toolchain_ast$BinaryExpr_t*) t1)->f_op;
        t1 = l3.payload.obj;
        l3 = vader_front_resolver$substitute_expr_full(((vader_struct_toolchain_ast$BinaryExpr_t*) t1)->f_right, l2);
        vader_struct_toolchain_ast$BinaryExpr_t* _a0_obj = (vader_struct_toolchain_ast$BinaryExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$BinaryExpr_t));
        vader_obj_header_init(_a0_obj, 623u);
        _a0_obj->f_span = l4;
        _a0_obj->f_id = INT64_C(0);
        _a0_obj->f_op = l5;
        _a0_obj->f_left = l1;
        _a0_obj->f_right = l3;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_front_resolver$substitute_expr_full(((vader_struct_toolchain_ast$AssignStmt_t*) l0)->f_value, l2);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_resolver$clone_header_binding(vader_box_t l0) {
    vader_box_t l1 = vader_box_null();
    void* l2 = NULL;
    void* l3 = NULL;
    vader_string_t l4 = 0;
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l0, &l1 };
    void** gc_raw_roots[3] = { &l2, &l3, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = l0;
    if (l1.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = l1.payload.obj;
    l3 = ((vader_struct_toolchain_ast$SimpleBinding_t*) l2)->f_span;
    l4 = ((vader_struct_toolchain_ast$SimpleBinding_t*) l2)->f_name;
    l2 = ((vader_struct_toolchain_ast$SimpleBinding_t*) l2)->f_name_span;
    vader_struct_toolchain_ast$SimpleBinding_t* _a0_obj = (vader_struct_toolchain_ast$SimpleBinding_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$SimpleBinding_t));
    vader_obj_header_init(_a0_obj, 689u);
    _a0_obj->f_span = l3;
    _a0_obj->f_id = INT64_C(0);
    _a0_obj->f_name = l4;
    _a0_obj->f_name_span = l2;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$clone_ident(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    vader_string_t l3 = 0;
    bool l4, l5;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = l0;
    l2 = ((vader_struct_toolchain_ast$IdentExpr_t*) l1)->f_span;
    l3 = ((vader_struct_toolchain_ast$IdentExpr_t*) l1)->f_name;
    l4 = ((vader_struct_toolchain_ast$IdentExpr_t*) l1)->f_implicit_dot;
    l5 = ((vader_struct_toolchain_ast$IdentExpr_t*) l1)->f_is_type_param_intro;
    vader_struct_toolchain_ast$IdentExpr_t* _a0_obj = (vader_struct_toolchain_ast$IdentExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$IdentExpr_t));
    vader_obj_header_init(_a0_obj, 655u);
    _a0_obj->f_span = l2;
    _a0_obj->f_id = INT64_C(0);
    _a0_obj->f_name = l3;
    _a0_obj->f_implicit_dot = l4;
    _a0_obj->f_is_type_param_intro = l5;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_resolver$clone_let_binding(vader_box_t l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    vader_string_t l3 = 0;
    int64_t l4, l5;
    vader_box_t l6 = vader_box_null();
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l6, &t1 };
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 689u) {
        l1 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$SimpleBinding_t*) l1)->f_span;
        l3 = ((vader_struct_toolchain_ast$SimpleBinding_t*) l1)->f_name;
        l1 = ((vader_struct_toolchain_ast$SimpleBinding_t*) l1)->f_name_span;
        vader_struct_toolchain_ast$SimpleBinding_t* _a0_obj = (vader_struct_toolchain_ast$SimpleBinding_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$SimpleBinding_t));
        vader_obj_header_init(_a0_obj, 689u);
        _a0_obj->f_span = l2;
        _a0_obj->f_id = INT64_C(0);
        _a0_obj->f_name = l3;
        _a0_obj->f_name_span = l1;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 701u) {
        vader_array_t* _a1_arr = vader_array_new(244u, 0u, 13u, 1671u);
        l1 = (void*) _a1_arr;
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$TupleBinding_t*) t0)->f_elements;
        l4 = ((vader_array_t*) l2)->length;
        l5 = INT64_C(0);
        while ((l5 < l4)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            t1 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
            l6 = vader_front_resolver$clone_let_binding(t1);
            vader_array_push_ref((vader_array_t*) l1, l6.payload.obj);
            l5 = (l5 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        vader_struct_toolchain_ast$TupleBinding_t* _a3_obj = (vader_struct_toolchain_ast$TupleBinding_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$TupleBinding_t));
        vader_obj_header_init(_a3_obj, 701u);
        _a3_obj->f_span = ((vader_struct_toolchain_ast$TupleBinding_t*) t0)->f_span;
        _a3_obj->f_id = INT64_C(0);
        _a3_obj->f_elements = l1;
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 706u) {
        t0 = l0.payload.obj;
        vader_struct_toolchain_ast$WildcardBinding_t* _a4_obj = (vader_struct_toolchain_ast$WildcardBinding_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$WildcardBinding_t));
        vader_obj_header_init(_a4_obj, 706u);
        _a4_obj->f_span = ((vader_struct_toolchain_ast$WildcardBinding_t*) t0)->f_span;
        _a4_obj->f_id = INT64_C(0);
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0.tag == 685u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    l1 = l0.payload.obj;
    l2 = ((vader_struct_toolchain_ast$RestBinding_t*) l1)->f_span;
    l3 = ((vader_struct_toolchain_ast$RestBinding_t*) l1)->f_name;
    l1 = ((vader_struct_toolchain_ast$RestBinding_t*) l1)->f_name_span;
    vader_struct_toolchain_ast$RestBinding_t* _a5_obj = (vader_struct_toolchain_ast$RestBinding_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$RestBinding_t));
    vader_obj_header_init(_a5_obj, 685u);
    _a5_obj->f_span = l2;
    _a5_obj->f_id = INT64_C(0);
    _a5_obj->f_name = l3;
    _a5_obj->f_name_span = l1;
    t0 = (void*) _a5_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_front_resolver$collect_decl(void* l0, vader_box_t l1, vader_string_t l2, vader_string_t l3, void* l4, void* l5, void* l6, void* l7) {
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
    if (l1.tag == 660u) {
        l8 = l1.payload.obj;
        vader_front_resolver$collect_import(l0, l8, l2, l3, l4, l5, l6, l7);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 650u) {
        l8 = l1.payload.obj;
        vader_front_resolver$add_fn(l0, l8, l2, l3, l4, l7);
    } else if (l1.tag == 693u) {
        t0 = l1.payload.obj;
        l9 = ((vader_struct_toolchain_ast$StructDecl_t*) t0)->f_name;
        t0 = l1.payload.obj;
        l8 = ((vader_struct_toolchain_ast$StructDecl_t*) t0)->f_name_span;
        t0 = l1.payload.obj;
        l10 = ((vader_struct_toolchain_ast$StructDecl_t*) t0)->f_visibility;
        vader_front_resolver$add_named(l0, (uint8_t) 1, l9, l8, l10, l2, l3, l4, l7);
    } else if (l1.tag == 644u) {
        t0 = l1.payload.obj;
        l9 = ((vader_struct_toolchain_ast$EnumDecl_t*) t0)->f_name;
        t0 = l1.payload.obj;
        l8 = ((vader_struct_toolchain_ast$EnumDecl_t*) t0)->f_name_span;
        t0 = l1.payload.obj;
        l10 = ((vader_struct_toolchain_ast$EnumDecl_t*) t0)->f_visibility;
        vader_front_resolver$add_named(l0, (uint8_t) 2, l9, l8, l10, l2, l3, l4, l7);
    } else if (l1.tag == 700u) {
        t0 = l1.payload.obj;
        l9 = ((vader_struct_toolchain_ast$TraitDecl_t*) t0)->f_name;
        t0 = l1.payload.obj;
        l8 = ((vader_struct_toolchain_ast$TraitDecl_t*) t0)->f_name_span;
        t0 = l1.payload.obj;
        l10 = ((vader_struct_toolchain_ast$TraitDecl_t*) t0)->f_visibility;
        vader_front_resolver$add_named(l0, (uint8_t) 3, l9, l8, l10, l2, l3, l4, l7);
    } else if (l1.tag == 702u) {
        t0 = l1.payload.obj;
        l9 = ((vader_struct_toolchain_ast$TypeAliasDecl_t*) t0)->f_name;
        t0 = l1.payload.obj;
        l8 = ((vader_struct_toolchain_ast$TypeAliasDecl_t*) t0)->f_name_span;
        t0 = l1.payload.obj;
        l10 = ((vader_struct_toolchain_ast$TypeAliasDecl_t*) t0)->f_visibility;
        vader_front_resolver$add_named(l0, (uint8_t) 5, l9, l8, l10, l2, l3, l4, l7);
    } else if (l1.tag == 631u) {
        t0 = l1.payload.obj;
        l9 = ((vader_struct_toolchain_ast$ConstDecl_t*) t0)->f_name;
        t0 = l1.payload.obj;
        l8 = ((vader_struct_toolchain_ast$ConstDecl_t*) t0)->f_name_span;
        t0 = l1.payload.obj;
        l10 = ((vader_struct_toolchain_ast$ConstDecl_t*) t0)->f_visibility;
        vader_front_resolver$add_named(l0, (uint8_t) 6, l9, l8, l10, l2, l3, l4, l7);
    } else if (!(l1.tag == 659u)) {
        if (!(l1.tag == 620u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_front_resolver$collect_files(void* l0, vader_string_t l1, vader_string_t l2, void* l3, void* l4, void* l5, void* l6) {
    void* l7 = NULL;
    void* l10 = NULL;
    int64_t l8, l9;
    void* t0 = NULL;
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
    l7 = vader_front_resolver$collect_module(((vader_struct_vader_front_resolver$SourceFile_t*) t0)->f_program, l1, l2, l3, l4, l5, l6);
    l8 = INT64_C(1);
    l9 = ((vader_array_t*) l0)->length;
    while ((l8 < l9)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l8)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l8);
        l10 = vader_front_resolver$collect_module(((vader_struct_vader_front_resolver$SourceFile_t*) t0)->f_program, l1, l2, l3, l4, l5, l6);
        vader_front_resolver$merge_collected(l7, l10, l6);
        l8 = (l8 + INT64_C(1));
    }
    { void* __vret = l7; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_front_resolver$collect_import(void* l0, void* l1, vader_string_t l2, vader_string_t l3, void* l4, void* l5, void* l6, void* l7) {
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
    int64_t l13, l14;
    vader_string_t t0 = 0;
    void* t1 = NULL;
    int64_t t2;
    vader_box_t* gc_roots[2] = { &l10, &l16 };
    void** gc_raw_roots[13] = {
        &l0, &l1, &l4, &l5, &l6, &l7, &l8, &l12, &l15, &l17, &l18, &l21, &t1,
    };
    vader_string_t* gc_atom_roots[9] = { &l2, &l3, &l9, &l11, &l19, &l20, &l22, &l23, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 13u, gc_roots, gc_raw_roots, 0u, NULL, 9u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_toolchain_ast$ImportDecl_t*) l1)->f_path;
    if (t0 == 0u) {
        l8 = ((vader_struct_toolchain_ast$ImportDecl_t*) l1)->f_span;
        l8 = vader_support_diagnostics$resolver_error((uint8_t) 1, l8, 0u);
        vader_array_push_ref((vader_array_t*) l7, l8);
    } else {
        l8 = ((vader_struct_vader_front_resolver$CollectedModule_t*) l0)->f_import_paths;
        l9 = ((vader_struct_toolchain_ast$ImportDecl_t*) l1)->f_path;
        vader_array_push_scalar((vader_array_t*) l8, vader_box_string(335u, l9));
        l9 = ((vader_struct_toolchain_ast$ImportDecl_t*) l1)->f_path;
        l8 = ((vader_struct_toolchain_ast$ImportDecl_t*) l1)->f_span;
        vader_front_resolver$diagnose_import_path(l9, l8, l3, l5, l6, l7);
    }
    l10 = ((vader_struct_toolchain_ast$ImportDecl_t*) l1)->f_binding;
    if (l10.tag == 674u) {
        t1 = l10.payload.obj;
        l9 = ((vader_struct_toolchain_ast$NamedNamespaceImport_t*) t1)->f_name;
        l8 = ((vader_struct_toolchain_ast$ImportDecl_t*) l1)->f_span;
        l11 = ((vader_struct_toolchain_ast$ImportDecl_t*) l1)->f_path;
        vader_front_resolver$bind_import(l0, l9, l8, l11, vader_box_obj(0u, NULL), l2, l4, l7);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l10.tag == 707u) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_front_resolver$CollectedModule_t*) l0)->f_files);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
        t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
        l8 = ((vader_struct_vader_front_resolver$FileImports_t*) t1)->f_paths;
        l9 = ((vader_struct_toolchain_ast$ImportDecl_t*) l1)->f_path;
        vader_array_push_scalar((vader_array_t*) l8, vader_box_string(335u, l9));
    } else {
        if (!(l10.tag == 638u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_front_resolver$CollectedModule_t*) l0)->f_files);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
        t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT32_C(0));
        l8 = ((vader_struct_vader_front_resolver$FileImports_t*) t1)->f_paths;
        l9 = ((vader_struct_toolchain_ast$ImportDecl_t*) l1)->f_path;
        vader_array_push_scalar((vader_array_t*) l8, vader_box_string(335u, l9));
        t1 = l10.payload.obj;
        t2 = ((vader_array_t*) ((vader_struct_toolchain_ast$DestructureImport_t*) t1)->f_names)->length;
        if (t2 == INT64_C(0)) {
            l8 = ((vader_struct_toolchain_ast$ImportDecl_t*) l1)->f_span;
            l9 = ((vader_struct_toolchain_ast$ImportDecl_t*) l1)->f_path;
            l9 = concat_3(1038u, l9, 1038u);
            l8 = vader_support_diagnostics$warning((uint8_t) 7, l8, l9);
            vader_array_push_ref((vader_array_t*) l7, l8);
        }
        vader_array_t* _a2_arr = vader_array_new(21u, 0u, 0u, 335u);
        l8 = (void*) _a2_arr;
        t1 = l10.payload.obj;
        l12 = ((vader_struct_toolchain_ast$DestructureImport_t*) t1)->f_names;
        l13 = ((vader_array_t*) l12)->length;
        l14 = INT64_C(0);
        while ((l14 < l13)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l12);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            l15 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l14);
            l10 = ((vader_struct_toolchain_ast$ImportName_t*) l15)->f_alias;
            l16 = l10;
            if (l10.tag == 0u) {
                l17 = ((vader_struct_toolchain_ast$ImportName_t*) l15)->f_span;
                l9 = ((vader_struct_toolchain_ast$ImportName_t*) l15)->f_name;
                l11 = concat_3(1038u, l9, 1038u);
                l18 = vader_support_diagnostics$resolver_error((uint8_t) 24, l17, l11);
                vader_array_push_ref((vader_array_t*) l7, l18);
            } else {
                if (!(l10.tag == 335u)) {
                    vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                }
                l19 = ((vader_struct_toolchain_ast$ImportName_t*) l15)->f_name;
                vader_array_push_scalar((vader_array_t*) l8, vader_box_string(335u, l19));
                t0 = l16.payload.s;
                if (t0 != 977u) {
                    l20 = l16.payload.s;
                    l21 = ((vader_struct_toolchain_ast$ImportName_t*) l15)->f_span;
                    l22 = ((vader_struct_toolchain_ast$ImportDecl_t*) l1)->f_path;
                    l23 = ((vader_struct_toolchain_ast$ImportName_t*) l15)->f_name;
                    vader_front_resolver$bind_import(l0, l20, l21, l22, vader_box_string(335u, l23), l2, l4, l7);
                }
            }
            l14 = (l14 + INT64_C(1));
        }
        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_front_resolver$CollectedModule_t*) l0)->f_files);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, INT32_C(0))
        t1 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) INT32_C(0));
        l12 = ((vader_struct_vader_front_resolver$FileImports_t*) t1)->f_excludes;
        l9 = ((vader_struct_toolchain_ast$ImportDecl_t*) l1)->f_path;
        std_collections$MutableMap$std_core$IndexSet$set_at__string__string__(l12, l9, l8);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_front_resolver$collect_module(void* l0, vader_string_t l1, vader_string_t l2, void* l3, void* l4, void* l5, void* l6) {
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
    int64_t l17, l18;
    vader_box_t l19 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l19 };
    void** gc_raw_roots[15] = {
        &l0, &l3, &l4, &l5, &l6, &l7, &l8, &l9, &l10, &l11, &l13, &l14, &l15, &l16, &t0,
    };
    vader_string_t* gc_atom_roots[3] = { &l1, &l2, &l12 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 15u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 335u);
    l7 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 346u);
    l8 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
    l9 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections$MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 533u);
    _a3_obj->f_ekeys = l7;
    _a3_obj->f_evals = l8;
    _a3_obj->f_index = l9;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l7 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(21u, 0u, 0u, 335u);
    l8 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(28u, 0u, 0u, 346u);
    l9 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(22u, 0u, 7u, 338u);
    l10 = (void*) _a6_arr;
    vader_struct_std_collections$MutableMap__string__Any___t* _a7_obj = (vader_struct_std_collections$MutableMap__string__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__Any___t));
    vader_obj_header_init(_a7_obj, 534u);
    _a7_obj->f_ekeys = l8;
    _a7_obj->f_evals = l9;
    _a7_obj->f_index = l10;
    _a7_obj->f_mask = INT64_C(0);
    _a7_obj->f_grow_at = INT64_C(0);
    _a7_obj->f_size = INT64_C(0);
    _a7_obj->f_tombs = INT64_C(0);
    l8 = (void*) _a7_obj;
    vader_array_t* _a8_arr = vader_array_new(22u, 0u, 7u, 338u);
    l9 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(28u, 0u, 0u, 346u);
    l10 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(22u, 0u, 7u, 338u);
    l11 = (void*) _a10_arr;
    vader_struct_std_collections$MutableMap__i32__Any_t* _a11_obj = (vader_struct_std_collections$MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__Any_t));
    vader_obj_header_init(_a11_obj, 459u);
    _a11_obj->f_ekeys = l9;
    _a11_obj->f_evals = l10;
    _a11_obj->f_index = l11;
    _a11_obj->f_mask = INT64_C(0);
    _a11_obj->f_grow_at = INT64_C(0);
    _a11_obj->f_size = INT64_C(0);
    _a11_obj->f_tombs = INT64_C(0);
    l9 = (void*) _a11_obj;
    vader_array_t* _a12_arr = vader_array_new(21u, 0u, 0u, 335u);
    l10 = (void*) _a12_arr;
    l12 = ((vader_struct_toolchain_ast$Program_t*) l0)->f_file;
    vader_array_t* _a13_arr = vader_array_new(21u, 0u, 0u, 335u);
    l11 = (void*) _a13_arr;
    vader_array_t* _a14_arr = vader_array_new(21u, 0u, 0u, 335u);
    l13 = (void*) _a14_arr;
    vader_array_t* _a15_arr = vader_array_new(2u, 0u, 13u, 21u);
    l14 = (void*) _a15_arr;
    vader_array_t* _a16_arr = vader_array_new(22u, 0u, 7u, 338u);
    l15 = (void*) _a16_arr;
    vader_struct_std_collections$MutableMap__string__string___t* _a17_obj = (vader_struct_std_collections$MutableMap__string__string___t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__string___t));
    vader_obj_header_init(_a17_obj, 554u);
    _a17_obj->f_ekeys = l13;
    _a17_obj->f_evals = l14;
    _a17_obj->f_index = l15;
    _a17_obj->f_mask = INT64_C(0);
    _a17_obj->f_grow_at = INT64_C(0);
    _a17_obj->f_size = INT64_C(0);
    _a17_obj->f_tombs = INT64_C(0);
    l13 = (void*) _a17_obj;
    vader_array_t* _a18_arr = vader_array_new(21u, 0u, 0u, 335u);
    l14 = (void*) _a18_arr;
    vader_array_t* _a19_arr = vader_array_new(28u, 0u, 0u, 346u);
    l15 = (void*) _a19_arr;
    vader_array_t* _a20_arr = vader_array_new(22u, 0u, 7u, 338u);
    l16 = (void*) _a20_arr;
    vader_struct_std_collections$MutableMap__string__Any_t* _a21_obj = (vader_struct_std_collections$MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__Any_t));
    vader_obj_header_init(_a21_obj, 533u);
    _a21_obj->f_ekeys = l14;
    _a21_obj->f_evals = l15;
    _a21_obj->f_index = l16;
    _a21_obj->f_mask = INT64_C(0);
    _a21_obj->f_grow_at = INT64_C(0);
    _a21_obj->f_size = INT64_C(0);
    _a21_obj->f_tombs = INT64_C(0);
    l14 = (void*) _a21_obj;
    vader_struct_vader_front_resolver$FileImports_t* _a22_obj = (vader_struct_vader_front_resolver$FileImports_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$FileImports_t));
    vader_obj_header_init(_a22_obj, 1088u);
    _a22_obj->f_file = l12;
    _a22_obj->f_paths = l11;
    _a22_obj->f_excludes = l13;
    _a22_obj->f_bindings = l14;
    t0 = (void*) _a22_obj;
    vader_array_t* _a23_arr = vader_array_new(137u, 1u, 13u, 1088u);
    ((void**) _a23_arr->buf->slots)[_a23_arr->offset + 0u] = t0;
    l11 = (void*) _a23_arr;
    vader_struct_vader_front_resolver$CollectedModule_t* _a24_obj = (vader_struct_vader_front_resolver$CollectedModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$CollectedModule_t));
    vader_obj_header_init(_a24_obj, 1086u);
    _a24_obj->f_symbols = l7;
    _a24_obj->f_fn_overloads = l8;
    _a24_obj->f_imports = l9;
    _a24_obj->f_import_paths = l10;
    _a24_obj->f_files = l11;
    l7 = (void*) _a24_obj;
    vader_front_resolver$check_import_form_conflict(((vader_struct_toolchain_ast$Program_t*) l0)->f_decls, l6);
    l8 = ((vader_struct_toolchain_ast$Program_t*) l0)->f_decls;
    l17 = ((vader_array_t*) l8)->length;
    l18 = INT64_C(0);
    while ((l18 < l17)) {
        vader_array_t* _a25_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a25_slotarr, l18)
        l19 = vader_array_ref_load_box(_a25_slotarr->buf, _a25_slotarr->offset + (size_t) l18);
        vader_front_resolver$collect_decl(l7, l19, l1, l2, l3, l4, l5, l6);
        l18 = (l18 + INT64_C(1));
    }
    { void* __vret = l7; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$collect_module_no_index(void* l0, vader_string_t l1, void* l2) {
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
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 335u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 346u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
    l5 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections$MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 533u);
    _a3_obj->f_ekeys = l3;
    _a3_obj->f_evals = l4;
    _a3_obj->f_index = l5;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l3 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(217u, 0u, 13u, 1400u);
    l4 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(139u, 0u, 13u, 1093u);
    l5 = (void*) _a5_arr;
    t0 = vader_front_resolver$collect_module(l0, l1, l1, l2, l3, l5, l4);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_front_resolver$concat_file_decls(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l5 = NULL;
    int64_t l3, l4, l6, l7;
    vader_box_t l8 = vader_box_null();
    int64_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l8 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l5, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) l0)->length;
    if (t0 == INT64_C(1)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
        { void* __vret = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) t1)->f_program)->f_decls; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a1_arr = vader_array_new(239u, 0u, 13u, 1618u);
    l1 = (void*) _a1_arr;
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t1 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        l5 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) t1)->f_program)->f_decls;
        l6 = ((vader_array_t*) l5)->length;
        l7 = INT64_C(0);
        while ((l7 < l6)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            l8 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l7);
            vader_array_push_ref((vader_array_t*) l1, l8.payload.obj);
            l7 = (l7 + INT64_C(1));
        }
        l4 = (l4 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static int64_t vader_front_resolver$count_sam_synthetics(void* l0) {
    int64_t l1, l3, l4;
    void* l2;
    void* t0;
    bool t1;
    l1 = INT64_C(0);
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t1 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_sam_synthetic;
        if (t1) {
            l1 = vader_chk_add(i64, l1, INT64_C(1));
        }
        l4 = (l4 + INT64_C(1));
    }
    return l1;
}

vader_box_t vader_front_resolver$decl_symbol(void* l0, vader_box_t l1) {
    void* l2;
    vader_box_t l3;
    vader_box_t t0;
    l3 = toolchain_ast$decl_name_span(l1);
    if (l3.tag == 0u) {
        return vader_box_obj(0u, NULL);
    }
    l2 = l3.payload.obj;
    t0 = vader_front_resolver$symbol_declared_at(l0, l2);
    return t0;
}

static void* vader_front_resolver$declaration_index(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l9 = NULL;
    int64_t l5, l6, l7, l8;
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l4, &l9 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(27u, 0u, 4u, 343u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 346u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__u64__Any_t* _a3_obj = (vader_struct_std_collections$MutableMap__u64__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__u64__Any_t));
    vader_obj_header_init(_a3_obj, 589u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l1 = (void*) _a3_obj;
    l2 = ((vader_struct_vader_front_resolver$CollectedModule_t*) l0)->f_symbols;
    l3 = ((vader_struct_std_collections$MutableMap__string__vader_core_symbol_Symbol_t*) l2)->f_ekeys;
    l4 = ((vader_struct_std_collections$MutableMap__string__vader_core_symbol_Symbol_t*) l2)->f_evals;
    l5 = INT64_C(0);
    l6 = ((vader_struct_std_collections$MutableMap__string__vader_core_symbol_Symbol_t*) l2)->f_size;
    while ((l5 < l6)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
        t0 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l5];
        t1 = t0.payload.s;
        vader_array_t* _a5_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
        l2 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l5);
        if (((vader_struct_vader_core_symbol$Symbol_t*) l2)->f_kind != INT32_C(0)) {
            vader_front_resolver$index_declaration(l1, l2);
        }
        l5 = (l5 + INT64_C(1));
    }
    l2 = ((vader_struct_vader_front_resolver$CollectedModule_t*) l0)->f_fn_overloads;
    l3 = ((vader_struct_std_collections$MutableMap__string__vader_core_symbol_Symbol___t*) l2)->f_ekeys;
    l4 = ((vader_struct_std_collections$MutableMap__string__vader_core_symbol_Symbol___t*) l2)->f_evals;
    l5 = INT64_C(0);
    l6 = ((vader_struct_std_collections$MutableMap__string__vader_core_symbol_Symbol___t*) l2)->f_size;
    while ((l5 < l6)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l5)
        t0 = vader_array_box_slots(_a6_slotarr->buf)[_a6_slotarr->offset + (size_t) l5];
        t1 = t0.payload.s;
        vader_array_t* _a7_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l5)
        l2 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l5);
        l7 = ((vader_array_t*) l2)->length;
        l8 = INT64_C(0);
        while ((l8 < l7)) {
            vader_array_t* _a8_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            l9 = vader_array_ref_load_obj(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l8);
            vader_front_resolver$index_declaration(l1, l9);
            l8 = (l8 + INT64_C(1));
        }
        l5 = (l5 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_front_resolver$declare_loop_local(void* l0, void* l1) {
    void* l2 = NULL;
    int32_t l3;
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_immutable_locals;
    l3 = ((vader_struct_vader_core_symbol$Symbol_t*) l1)->f_id;
    std_collections$MutableMap$std_core$IndexSet$set_at__i32__vader_front_resolver_ConstLocal(l2, l3, (uint8_t) 1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_front_resolver$declare_type_param(void* l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    vader_box_t l3 = vader_box_null();
    int32_t l5;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_front_resolver$bind_type_param(l0, l1);
    l3 = ((vader_struct_toolchain_ast$TypeParam_t*) l1)->f_bound;
    if (l3.tag == 0u) {
        { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_type_param_bounds;
    l5 = ((vader_struct_vader_core_symbol$Symbol_t*) l2)->f_id;
    l3 = vader_front_resolver$checked_bound(l0, l1, l3);
    std_collections$MutableMap$std_core$IndexSet$set_at__i32__Any(l4, l5, l3);
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_front_resolver$declared_outside_lambda(void* l0, vader_string_t l1) {
    int32_t l2;
    vader_box_t l3;
    int32_t t0;
    l3 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_lambda_frame;
    if (l3.tag == 0u) {
        return false;
    }
    l2 = ((int32_t) l3.payload.i);
    t0 = vader_front_resolver$lookup_frame_index(((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope, l1);
    return (t0 < l2);
}

static void* vader_front_resolver$declared_roots(void) {
    int32_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_global_6;
    if (t0 == INT32_C(2)) {
        t1 = vader_global_7;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_global_6;
    if (!(t0 == INT32_C(1))) {
        vader_global_6 = INT32_C(1);
        t1 = vader_front_resolver$declared_roots$singleton();
        vader_global_7 = t1;
        vader_global_6 = INT32_C(2);
        t1 = vader_global_7;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_unreachable("singleton `declared_roots` called while it initialises");
    vader_gc_top = gc_frame.prev;
}

static void* vader_front_resolver$declared_roots$singleton(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 335u);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(2u, 0u, 13u, 21u);
    l1 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
    l2 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__string__string___t* _a3_obj = (vader_struct_std_collections$MutableMap__string__string___t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__string___t));
    vader_obj_header_init(_a3_obj, 554u);
    _a3_obj->f_ekeys = l0;
    _a3_obj->f_evals = l1;
    _a3_obj->f_index = l2;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_front_resolver$detect_import_cycles(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    int64_t l7, l8;
    vader_string_t l9 = 0;
    vader_string_t l10 = 0;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l9, &l10 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 335u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(22u, 0u, 7u, 338u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
    l5 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__string__i32_t* _a3_obj = (vader_struct_std_collections$MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__i32_t));
    vader_obj_header_init(_a3_obj, 540u);
    _a3_obj->f_ekeys = l3;
    _a3_obj->f_evals = l4;
    _a3_obj->f_index = l5;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l3 = (void*) _a3_obj;
    l4 = l0;
    l5 = ((vader_struct_std_collections$MutableMap__string__vader_front_resolver_LoadedModule_t*) l4)->f_ekeys;
    l6 = ((vader_struct_std_collections$MutableMap__string__vader_front_resolver_LoadedModule_t*) l4)->f_evals;
    l7 = INT64_C(0);
    l8 = ((vader_struct_std_collections$MutableMap__string__vader_front_resolver_LoadedModule_t*) l4)->f_size;
    while ((l7 < l8)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        t0 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l7];
        l9 = t0.payload.s;
        vader_array_t* _a5_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l7)
        t1 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l7);
        l10 = l9;
        t0 = std_collections$MutableMap$std_core$Index$at__string__i32(l3, l10);
        if (t0.tag == 0u) {
            vader_front_resolver$walk_import_cycle(l10, l0, l1, l3, l2);
        }
        l7 = (l7 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_front_resolver$diagnose_import_path(vader_string_t l0, void* l1, vader_string_t l2, void* l3, void* l4, void* l5) {
    bool l6;
    vader_string_t l7 = 0;
    void* l8 = NULL;
    vader_box_t l9 = vader_box_null();
    bool t0;
    uint8_t t1;
    void* t2 = NULL;
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[1] = { &l9 };
    void** gc_raw_roots[6] = { &l1, &l3, &l4, &l5, &l8, &t2 };
    vader_string_t* gc_atom_roots[4] = { &l0, &l2, &l7, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = std_string$starts_with(l0, 403u);
    if (t0) {
        l6 = true;
    } else {
        l6 = std_string$starts_with(l0, 400u);
    }
    if (l6) {
        l7 = concat_3(1038u, l0, 1038u);
        l8 = vader_support_diagnostics$resolver_error((uint8_t) 18, l1, l7);
        vader_array_push_ref((vader_array_t*) l5, l8);
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    if (l0 == l2) {
        l7 = concat_3(1038u, l0, 1038u);
        l8 = vader_support_diagnostics$resolver_error((uint8_t) 17, l1, l7);
        vader_array_push_ref((vader_array_t*) l5, l8);
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    if (l0 == 2591u) {
        if (l2 != 2591u) {
            l8 = vader_support_diagnostics$resolver_error((uint8_t) 20, l1, 0u);
            vader_array_push_ref((vader_array_t*) l5, l8);
            { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
        }
    }
    t0 = std_string$starts_with(l0, 2858u);
    if (t0) {
        t0 = std_string$starts_with(l2, 2858u);
        if (!(t0)) {
            if (l2 != 2736u) {
                t1 = vader_front_resolver$importer_origin(l3, l2);
                if (t1 == INT32_C(1)) {
                    l7 = concat_5(1038u, l2, 1191u, l0, 1299u);
                    l8 = vader_support_diagnostics$resolver_error((uint8_t) 25, l1, l7);
                    vader_array_push_ref((vader_array_t*) l5, l8);
                    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
                }
            }
        }
    }
    t0 = std_collections$is_empty__string__Any(l3);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l9 = std_collections$MutableMap$std_core$Index$at__string__Any(l3, l0);
    if (l9.tag == 1087u) {
        t2 = l9.payload.obj;
        t3 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) t2)->f_folder;
        { vader_box_t __vret = vader_box_string(335u, t3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l9.tag == 0u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    l9 = vader_front_resolver$misplaced_module_at(l0, l4);
    if (l9.tag == 0u) {
        l7 = concat_3(1038u, l0, 1038u);
        l8 = vader_support_diagnostics$resolver_error((uint8_t) 0, l1, l7);
        vader_array_push_ref((vader_array_t*) l5, l8);
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l7 = l9.payload.s;
    l7 = concat_5(1038u, l0, 1310u, l7, 252u);
    l8 = vader_support_diagnostics$resolver_error((uint8_t) 0, l1, l7);
    vader_array_push_ref((vader_array_t*) l5, l8);
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

vader_string_t vader_front_resolver$dir_of(vader_string_t l0) {
    vader_string_t t0, t1;
    t0 = std_path$to_path(l0);
    t1 = std_path$parent(t0);
    t0 = std_path$as_string(t1);
    return t0;
}

static void* vader_front_resolver$discarded_bodies(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l7 = NULL;
    void* l11 = NULL;
    int64_t l5, l6, l8, l9;
    vader_box_t l10 = vader_box_null();
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    bool t2;
    vader_box_t* gc_roots[3] = { &l1, &l10, &t1 };
    void** gc_raw_roots[7] = { &l0, &l2, &l3, &l4, &l7, &l11, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(45u, 0u, 13u, 650u);
    l2 = (void*) _a0_arr;
    if (l1.tag == 0u) {
        { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = l1.payload.obj;
    vader_array_t* _a1_arr = vader_array_new(217u, 0u, 13u, 1400u);
    l4 = (void*) _a1_arr;
    l3 = vader_front_resolver$select_target_bodies(l0, vader_ref_box(l3), l4);
    l4 = l0;
    l5 = ((vader_array_t*) l4)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l6);
        l7 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) t0)->f_program)->f_decls;
        l8 = ((vader_array_t*) l7)->length;
        l9 = INT64_C(0);
        while ((l9 < l8)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            l10 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l9);
            if (l10.tag == 650u) {
                t0 = l10.payload.obj;
                t1 = vader_front_resolver$target_selectors(((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_decorators);
                if (t1.tag == 0u) {
                    l9 = (l9 + INT64_C(1));
                    continue;
                }
                t0 = l10.payload.obj;
                t2 = vader_front_resolver$body_survives(t0, l3);
                if (t2) {
                    l9 = (l9 + INT64_C(1));
                    continue;
                }
                l11 = l10.payload.obj;
                vader_array_push_ref((vader_array_t*) l2, l11);
            }
            l9 = (l9 + INT64_C(1));
        }
        l6 = (l6 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_resolver$displayable_impl(void* l0, void* l1, vader_string_t l2) {
    void* l3 = NULL;
    void* l5 = NULL;
    void* l8 = NULL;
    vader_string_t l4 = 0;
    vader_string_t l9 = 0;
    vader_string_t l10 = 0;
    int64_t l6, l7;
    vader_box_t l11 = vader_box_null();
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[1] = { &l11 };
    void** gc_raw_roots[6] = { &l0, &l1, &l3, &l5, &l8, &t0 };
    vader_string_t* gc_atom_roots[5] = { &l2, &l4, &l9, &l10, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 335u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string__builder$StringBuilder_t* _a1_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
    vader_obj_header_init(_a1_obj, 618u);
    _a1_obj->f_parts = t0;
    l3 = (void*) _a1_obj;
    t1 = ((vader_struct_toolchain_ast$EnumDecl_t*) l0)->f_name;
    l4 = concat_2(t1, 139u);
    std_string__builder$append(l3, l4);
    std_string__builder$append(l3, 29u);
    l5 = ((vader_struct_toolchain_ast$EnumDecl_t*) l0)->f_variants;
    l6 = ((vader_array_t*) l5)->length;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l8 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l7);
        l4 = ((vader_struct_toolchain_ast$EnumVariant_t*) l8)->f_name;
        l9 = ((vader_struct_toolchain_ast$EnumVariant_t*) l8)->f_name;
        l10 = concat_5(24u, l4, 63u, l9, 249u);
        std_string__builder$append(l3, l10);
        l7 = (l7 + INT64_C(1));
    }
    std_string__builder$append(l3, 30u);
    l4 = ((vader_struct_toolchain_ast$EnumDecl_t*) l0)->f_name;
    l4 = concat_4(510u, l2, 253u, l4);
    t1 = std_string__builder$StringBuilder$std_core$Display$to_string(l3);
    t0 = vader_front_parser$parse_source(t1, l4);
    vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_parser$ParsedSource_t*) t0)->f_program)->f_decls);
    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a3_slotarr, INT32_C(0))
    l11 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) INT32_C(0));
    if (l11.tag == 659u) {
        l3 = l11.payload.obj;
        l5 = ((vader_struct_toolchain_ast$Decorator_t*) l1)->f_span;
        ((vader_struct_toolchain_ast$ImplDecl_t*) l3)->f_span = l5;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast$ImplDecl_t*) l3);
        l3 = l11.payload.obj;
        vader_array_t* _a4_arr = vader_array_new(42u, 1u, 13u, 633u);
        ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 0u] = l1;
        l5 = (void*) _a4_arr;
        ((vader_struct_toolchain_ast$ImplDecl_t*) l3)->f_decorators = l5;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast$ImplDecl_t*) l3);
        { vader_box_t __vret = l11; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l11; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_front_resolver$drain_load_queue(void* l0, void* l1) {
    int64_t l2, l3, l9, l10;
    void* l4 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    void* l12 = NULL;
    void* l14 = NULL;
    vader_string_t l5 = 0;
    vader_string_t l11 = 0;
    vader_string_t l15 = 0;
    vader_box_t l7 = vader_box_null(), l13 = vader_box_null();
    bool t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l7, &l13, &t1 };
    void** gc_raw_roots[7] = { &l0, &l1, &l4, &l6, &l8, &l12, &l14 };
    vader_string_t* gc_atom_roots[3] = { &l5, &l11, &l15 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = INT64_C(0);
    for (;;) {
        l3 = ((vader_array_t*) l1)->length;
        if ((l2 < l3)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
            l2 = vader_chk_add(i64, l2, INT64_C(1));
            l5 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) l4)->f_folder;
            t0 = vader_front_resolver$has_module(((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_modules, l5);
            if (t0) {
                continue;
            }
            vader_front_resolver$ingest_module(l0, l4);
            l7 = std_collections$MutableMap$std_core$Index$at__string__Any(((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_modules, l5);
            if (l7.tag == 0u) {
                continue;
            }
            l6 = l7.payload.obj;
            l8 = ((vader_struct_vader_front_resolver$CollectedModule_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l6)->f_collected)->f_import_paths;
            l9 = ((vader_array_t*) l8)->length;
            l10 = INT64_C(0);
            while ((l10 < l9)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l8);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                t1 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l10];
                l11 = t1.payload.s;
                l13 = std_collections$MutableMap$std_core$Index$at__string__Any(((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_index, l11);
                if (l13.tag == 0u) {
                    l10 = (l10 + INT64_C(1));
                    continue;
                }
                l12 = l13.payload.obj;
                l14 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_modules;
                l15 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) l12)->f_folder;
                t0 = vader_front_resolver$has_module(l14, l15);
                if (!(t0)) {
                    vader_array_push_ref((vader_array_t*) l1, l12);
                }
                l10 = (l10 + INT64_C(1));
            }
            continue;
        }
        break;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_front_resolver$enter_file(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope;
    l3 = ((vader_struct_vader_front_resolver$FileScope_t*) l1)->f_root;
    l2 = vader_front_resolver$swap_root(l2, l3);
    l3 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_ambiguous;
    vader_struct_vader_front_resolver$FileScope_t* _a0_obj = (vader_struct_vader_front_resolver$FileScope_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$FileScope_t));
    vader_obj_header_init(_a0_obj, 1089u);
    _a0_obj->f_root = l2;
    _a0_obj->f_ambiguous = l3;
    l2 = (void*) _a0_obj;
    l3 = ((vader_struct_vader_front_resolver$FileScope_t*) l1)->f_ambiguous;
    ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_ambiguous = l3;
    VADER_WRITE_BARRIER((vader_struct_vader_front_resolver$ResolveState_t*) l0);
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_front_resolver$entry_folder_of(vader_string_t l0) {
    vader_string_t l1 = 0;
    bool t0;
    vader_string_t* gc_atom_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = std_io$exists(l0);
    if (t0) {
        t0 = std_io$is_dir(l0);
        if (t0) {
            { vader_string_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l1 = vader_front_resolver$dir_of(l0);
    if (!(l1 == 0u)) {
        { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return 397u; }
}

static vader_box_t vader_front_resolver$entry_name_problem(vader_string_t l0) {
    bool t0;
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = vader_front_resolver$is_portable_name(l0);
    if (!(t0)) {
        { vader_box_t __vret = vader_box_string(335u, 1734u); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_front_resolver$is_windows_device_name(l0);
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    { vader_box_t __vret = vader_box_string(335u, 1733u); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_resolver$entry_named(void* l0, vader_string_t l1) {
    vader_string_t l2 = 0;
    void* l3 = NULL;
    void* l6 = NULL;
    int64_t l4, l5;
    vader_string_t t0 = 0;
    vader_string_t t1 = 0;
    void** gc_raw_roots[3] = { &l0, &l3, &l6 };
    vader_string_t* gc_atom_roots[4] = { &l1, &l2, &t0, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = std_string$to_lower(l1);
    l3 = l0;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l6 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        t0 = ((vader_struct_vader_front_resolver$ManifestEntry_t*) l6)->f_name;
        t1 = std_string$to_lower(t0);
        if (t1 == l2) {
            { vader_box_t __vret = vader_ref_box(l6); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l5 = (l5 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static void* vader_front_resolver$entry_namespace(vader_string_t l0, vader_string_t l1) {
    void* l2 = NULL;
    int64_t l3, l6;
    vader_string_t l4 = 0;
    vader_string_t l5 = 0;
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[2] = { &l2, &t1 };
    vader_string_t* gc_atom_roots[4] = { &l0, &l1, &l4, &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_vader_front_resolver$IncludePath_t* _a0_obj = (vader_struct_vader_front_resolver$IncludePath_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$IncludePath_t));
    vader_obj_header_init(_a0_obj, 1093u);
    _a0_obj->f_dir = l1;
    _a0_obj->f_prefix = l0;
    _a0_obj->f_merge = false;
    _a0_obj->f_origin = (uint8_t) 0;
    l2 = (void*) _a0_obj;
    l3 = std_string$index_of(l0, 47u, INT64_C(0));
    if ((l3 < INT64_C(0))) {
        { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = std_string$trim_suffix(l1, 438u);
    if (l4 != l0) {
        l5 = concat_2(438u, l0);
        t0 = std_string$ends_with(l4, l5);
        if (!(t0)) {
            { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l6 = vader_host_std_core$byte_len(l0);
    l5 = vader_host_std_core$byte_slice(l0, l3, l6);
    l4 = std_string$trim_suffix(l4, l5);
    l5 = vader_host_std_core$byte_slice(l0, INT64_C(0), l3);
    vader_struct_vader_front_resolver$IncludePath_t* _a1_obj = (vader_struct_vader_front_resolver$IncludePath_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$IncludePath_t));
    vader_obj_header_init(_a1_obj, 1093u);
    _a1_obj->f_dir = l4;
    _a1_obj->f_prefix = l5;
    _a1_obj->f_merge = false;
    _a1_obj->f_origin = (uint8_t) 0;
    t1 = (void*) _a1_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$file_imports(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    int64_t l3, l4;
    vader_string_t t0 = 0;
    void* t1 = NULL;
    void** gc_raw_roots[7] = { &l0, &l2, &l5, &l6, &l7, &l8, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 7u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_front_resolver$CollectedModule_t*) l0)->f_files;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t0 = ((vader_struct_vader_front_resolver$FileImports_t*) l5)->f_file;
        if (t0 == l1) {
            { void* __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l4 = (l4 + INT64_C(1));
    }
    vader_array_t* _a1_arr = vader_array_new(21u, 0u, 0u, 335u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(21u, 0u, 0u, 335u);
    l5 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(2u, 0u, 13u, 21u);
    l6 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(22u, 0u, 7u, 338u);
    l7 = (void*) _a4_arr;
    vader_struct_std_collections$MutableMap__string__string___t* _a5_obj = (vader_struct_std_collections$MutableMap__string__string___t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__string___t));
    vader_obj_header_init(_a5_obj, 554u);
    _a5_obj->f_ekeys = l5;
    _a5_obj->f_evals = l6;
    _a5_obj->f_index = l7;
    _a5_obj->f_mask = INT64_C(0);
    _a5_obj->f_grow_at = INT64_C(0);
    _a5_obj->f_size = INT64_C(0);
    _a5_obj->f_tombs = INT64_C(0);
    l5 = (void*) _a5_obj;
    vader_array_t* _a6_arr = vader_array_new(21u, 0u, 0u, 335u);
    l6 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(28u, 0u, 0u, 346u);
    l7 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(22u, 0u, 7u, 338u);
    l8 = (void*) _a8_arr;
    vader_struct_std_collections$MutableMap__string__Any_t* _a9_obj = (vader_struct_std_collections$MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__Any_t));
    vader_obj_header_init(_a9_obj, 533u);
    _a9_obj->f_ekeys = l6;
    _a9_obj->f_evals = l7;
    _a9_obj->f_index = l8;
    _a9_obj->f_mask = INT64_C(0);
    _a9_obj->f_grow_at = INT64_C(0);
    _a9_obj->f_size = INT64_C(0);
    _a9_obj->f_tombs = INT64_C(0);
    l6 = (void*) _a9_obj;
    vader_struct_vader_front_resolver$FileImports_t* _a10_obj = (vader_struct_vader_front_resolver$FileImports_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$FileImports_t));
    vader_obj_header_init(_a10_obj, 1088u);
    _a10_obj->f_file = l1;
    _a10_obj->f_paths = l2;
    _a10_obj->f_excludes = l5;
    _a10_obj->f_bindings = l6;
    t1 = (void*) _a10_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$file_root_scope(void* l0, void* l1, void* l2, void* l3, void* l4) {
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l13 = NULL;
    int64_t l9, l10;
    vader_string_t l11 = 0;
    vader_string_t l12 = 0;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l8, &l13 };
    vader_string_t* gc_atom_roots[2] = { &l11, &l12 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 335u);
    l5 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 346u);
    l6 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
    l7 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections$MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 533u);
    _a3_obj->f_ekeys = l5;
    _a3_obj->f_evals = l6;
    _a3_obj->f_index = l7;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l5 = (void*) _a3_obj;
    l6 = l0;
    l7 = ((vader_struct_std_collections$MutableMap__string__vader_core_symbol_Symbol_t*) l6)->f_ekeys;
    l8 = ((vader_struct_std_collections$MutableMap__string__vader_core_symbol_Symbol_t*) l6)->f_evals;
    l9 = INT64_C(0);
    l10 = ((vader_struct_std_collections$MutableMap__string__vader_core_symbol_Symbol_t*) l6)->f_size;
    while ((l9 < l10)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l9)
        t0 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l9];
        l11 = t0.payload.s;
        vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l9)
        l6 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l9);
        l12 = l11;
        l13 = l6;
        std_collections$MutableMap$std_core$IndexSet$set_at__string__Any(l5, l12, vader_ref_box(l13));
        l9 = (l9 + INT64_C(1));
    }
    l6 = ((vader_struct_vader_front_resolver$FileImports_t*) l2)->f_bindings;
    l7 = ((vader_struct_std_collections$MutableMap__string__vader_core_symbol_Symbol_t*) l6)->f_ekeys;
    l8 = ((vader_struct_std_collections$MutableMap__string__vader_core_symbol_Symbol_t*) l6)->f_evals;
    l9 = INT64_C(0);
    l10 = ((vader_struct_std_collections$MutableMap__string__vader_core_symbol_Symbol_t*) l6)->f_size;
    while ((l9 < l10)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l9)
        t0 = vader_array_box_slots(_a6_slotarr->buf)[_a6_slotarr->offset + (size_t) l9];
        l11 = t0.payload.s;
        vader_array_t* _a7_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l9)
        l6 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l9);
        l12 = l11;
        l13 = l6;
        std_collections$MutableMap$std_core$IndexSet$set_at__string__Any(l5, l12, vader_ref_box(l13));
        l9 = (l9 + INT64_C(1));
    }
    l6 = ((vader_struct_vader_front_resolver$CollectedModule_t*) l1)->f_symbols;
    l7 = ((vader_struct_std_collections$MutableMap__string__vader_core_symbol_Symbol_t*) l6)->f_ekeys;
    l8 = ((vader_struct_std_collections$MutableMap__string__vader_core_symbol_Symbol_t*) l6)->f_evals;
    l9 = INT64_C(0);
    l10 = ((vader_struct_std_collections$MutableMap__string__vader_core_symbol_Symbol_t*) l6)->f_size;
    while ((l9 < l10)) {
        vader_array_t* _a8_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l9)
        t0 = vader_array_box_slots(_a8_slotarr->buf)[_a8_slotarr->offset + (size_t) l9];
        l11 = t0.payload.s;
        vader_array_t* _a9_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l9)
        l6 = vader_array_ref_load_obj(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l9);
        l12 = l11;
        l13 = l6;
        std_collections$MutableMap$std_core$IndexSet$set_at__string__Any(l5, l12, vader_ref_box(l13));
        l9 = (l9 + INT64_C(1));
    }
    l6 = l4;
    l7 = ((vader_struct_std_collections$MutableMap__string__vader_core_symbol_Symbol_t*) l6)->f_ekeys;
    l8 = ((vader_struct_std_collections$MutableMap__string__vader_core_symbol_Symbol_t*) l6)->f_evals;
    l9 = INT64_C(0);
    l10 = ((vader_struct_std_collections$MutableMap__string__vader_core_symbol_Symbol_t*) l6)->f_size;
    while ((l9 < l10)) {
        vader_array_t* _a10_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l9)
        t0 = vader_array_box_slots(_a10_slotarr->buf)[_a10_slotarr->offset + (size_t) l9];
        l11 = t0.payload.s;
        vader_array_t* _a11_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l9)
        l6 = vader_array_ref_load_obj(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l9);
        l12 = l11;
        l13 = l6;
        std_collections$get_or_put__string__vader_core_symbol_Symbol(l5, l12, l13);
        l9 = (l9 + INT64_C(1));
    }
    l6 = ((vader_struct_vader_front_resolver$FileImports_t*) l2)->f_paths;
    l7 = ((vader_struct_vader_front_resolver$FileImports_t*) l2)->f_excludes;
    vader_front_resolver$seed_wildcard_exports(l5, l3, l6, l7);
    { void* __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_front_resolver$find_async_module_id(void* l0) {
    void* l1;
    void* l2;
    void* l3;
    int64_t l4, l5;
    vader_string_t l6, l7;
    vader_box_t t0;
    void* t1;
    bool t2;
    l1 = ((vader_struct_vader_front_resolver$LoadedProject_t*) l0)->f_modules;
    l2 = ((vader_struct_std_collections$MutableMap__string__vader_front_resolver_LoadedModule_t*) l1)->f_ekeys;
    l3 = ((vader_struct_std_collections$MutableMap__string__vader_front_resolver_LoadedModule_t*) l1)->f_evals;
    l4 = INT64_C(0);
    l5 = ((vader_struct_std_collections$MutableMap__string__vader_front_resolver_LoadedModule_t*) l1)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l4];
        l6 = t0.payload.s;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        l7 = l6;
        t2 = std_string$ends_with(l7, 2590u);
        if (t2) {
            return vader_box_string(335u, l7);
        }
        t2 = std_string$ends_with(l7, 2589u);
        if (t2) {
            return vader_box_string(335u, l7);
        }
        l4 = (l4 + INT64_C(1));
    }
    return vader_box_obj(0u, NULL);
}

vader_box_t vader_front_resolver$find_core_module_id(void* l0) {
    void* l1;
    void* l2;
    void* l3;
    int64_t l4, l5;
    vader_string_t l6, l7;
    vader_box_t t0;
    void* t1;
    bool t2;
    l1 = ((vader_struct_vader_front_resolver$LoadedProject_t*) l0)->f_modules;
    l2 = ((vader_struct_std_collections$MutableMap__string__vader_front_resolver_LoadedModule_t*) l1)->f_ekeys;
    l3 = ((vader_struct_std_collections$MutableMap__string__vader_front_resolver_LoadedModule_t*) l1)->f_evals;
    l4 = INT64_C(0);
    l5 = ((vader_struct_std_collections$MutableMap__string__vader_front_resolver_LoadedModule_t*) l1)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l4];
        l6 = t0.payload.s;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        l7 = l6;
        t2 = std_string$ends_with(l7, 2594u);
        if (t2) {
            return vader_box_string(335u, l7);
        }
        t2 = std_string$ends_with(l7, 2591u);
        if (t2) {
            return vader_box_string(335u, l7);
        }
        l4 = (l4 + INT64_C(1));
    }
    return vader_box_obj(0u, NULL);
}

static void* vader_front_resolver$find_impl_trait_decl(vader_string_t l0, void* l1, void* l2, void* l3, void* l4) {
    void* l5 = NULL;
    void* l6 = NULL;
    void* l10 = NULL;
    vader_box_t l7 = vader_box_null();
    vader_string_t l8 = 0;
    vader_string_t l13 = 0;
    uint8_t l9;
    int64_t l11, l12;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l7 };
    void** gc_raw_roots[8] = { &l1, &l2, &l3, &l4, &l5, &l6, &l10, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l8, &l13 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_vader_front_resolver$TraitLookup_t* _a0_obj = (vader_struct_vader_front_resolver$TraitLookup_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$TraitLookup_t));
    vader_obj_header_init(_a0_obj, 1112u);
    _a0_obj->f_trait_decl = vader_box_obj(0u, NULL);
    _a0_obj->f_other_kind = 0u;
    l5 = (void*) _a0_obj;
    l7 = vader_front_resolver$name_in_file_scope(l0, l1, l2, l3);
    if (l7.tag == 0u) {
        { void* __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = l7.payload.obj;
    if (((vader_struct_vader_core_symbol$Symbol_t*) l6)->f_kind != INT32_C(3)) {
        l9 = ((vader_struct_vader_core_symbol$Symbol_t*) l6)->f_kind;
        if (l9 == INT32_C(1)) {
            l8 = 1493u;
            vader_struct_vader_front_resolver$TraitLookup_t* _a1_obj = (vader_struct_vader_front_resolver$TraitLookup_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$TraitLookup_t));
            vader_obj_header_init(_a1_obj, 1112u);
            _a1_obj->f_trait_decl = vader_box_obj(0u, NULL);
            _a1_obj->f_other_kind = l8;
            t0 = (void*) _a1_obj;
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l9 == INT32_C(2)) {
            l8 = 1532u;
        } else if (l9 == INT32_C(5)) {
            l8 = 1527u;
        } else {
            l8 = 0u;
        }
        vader_struct_vader_front_resolver$TraitLookup_t* _a2_obj = (vader_struct_vader_front_resolver$TraitLookup_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$TraitLookup_t));
        vader_obj_header_init(_a2_obj, 1112u);
        _a2_obj->f_trait_decl = vader_box_obj(0u, NULL);
        _a2_obj->f_other_kind = l8;
        t0 = (void*) _a2_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l10 = ((vader_struct_vader_front_resolver$LoadedProject_t*) l4)->f_modules;
    l8 = ((vader_struct_vader_core_symbol$Symbol_t*) l6)->f_module;
    l7 = std_collections$MutableMap$std_core$Index$at__string__Any(l10, l8);
    if (l7.tag == 0u) {
        { void* __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l10 = l7.payload.obj;
    l10 = vader_front_resolver$concat_file_decls(((vader_struct_vader_front_resolver$Module_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l10)->f_module)->f_files);
    l11 = ((vader_array_t*) l10)->length;
    l12 = INT64_C(0);
    while ((l12 < l11)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l10);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        l7 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l12);
        if (l7.tag == 700u) {
            t0 = l7.payload.obj;
            l8 = ((vader_struct_toolchain_ast$TraitDecl_t*) t0)->f_name;
            l13 = ((vader_struct_vader_core_symbol$Symbol_t*) l6)->f_name;
            if (l8 == l13) {
                t0 = l7.payload.obj;
                vader_struct_vader_front_resolver$TraitLookup_t* _a4_obj = (vader_struct_vader_front_resolver$TraitLookup_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$TraitLookup_t));
                vader_obj_header_init(_a4_obj, 1112u);
                _a4_obj->f_trait_decl = vader_ref_box(t0);
                _a4_obj->f_other_kind = 0u;
                t0 = (void*) _a4_obj;
                { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
        l12 = (l12 + INT64_C(1));
    }
    { void* __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_front_resolver$for_type_display_name(vader_box_t l0) {
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[2] = { &t1, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 619u) {
        t0 = l0.payload.obj;
        t1 = vader_front_resolver$for_type_display_name(((vader_struct_toolchain_ast$ArrayTypeExpr_t*) t0)->f_element);
        t2 = concat_2(t1, 967u);
        { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 655u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_toolchain_ast$IdentExpr_t*) t0)->f_name;
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 654u) {
        t0 = l0.payload.obj;
        if (((vader_struct_toolchain_ast$GenericInstExpr_t*) t0)->f_callee.tag == 655u) {
            t0 = l0.payload.obj;
            t1 = ((vader_struct_toolchain_ast$IdentExpr_t*) ((vader_struct_toolchain_ast$GenericInstExpr_t*) t0)->f_callee.payload.obj)->f_name;
            { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_gc_top = gc_frame.prev; return 530u; }
    }
    { vader_gc_top = gc_frame.prev; return 530u; }
}

static vader_box_t vader_front_resolver$for_type_owner_sym(vader_box_t l0, void* l1, void* l2) {
    void* l3;
    vader_box_t l4;
    uint64_t l5;
    void* t0;
    void* t1;
    if (l0.tag == 619u) {
        t0 = l0.payload.obj;
        l4 = vader_front_resolver$for_type_owner_sym(((vader_struct_toolchain_ast$ArrayTypeExpr_t*) t0)->f_element, l1, l2);
        if (l4.tag == 0u) {
            return vader_box_obj(0u, NULL);
        }
        l3 = l4.payload.obj;
        if (((vader_struct_vader_core_symbol$Symbol_t*) l3)->f_kind == INT32_C(9)) {
            return vader_box_obj(0u, NULL);
        }
        return vader_ref_box(l3);
    }
    if (l0.tag == 655u) {
        t0 = l0.payload.obj;
        l5 = toolchain_span$Span$std_core$Hash$hash(((vader_struct_toolchain_ast$IdentExpr_t*) t0)->f_span);
        l4 = std_collections$MutableMap$std_core$Index$at__u64__Any(l1, l5);
        if (l4.tag == 0u) {
            return vader_box_obj(0u, NULL);
        }
        t0 = l4.payload.obj;
        t1 = vader_front_resolver$resolve_import_redirect(t0, l2);
        return vader_ref_box(t1);
    }
    if (l0.tag == 654u) {
        t0 = l0.payload.obj;
        if (((vader_struct_toolchain_ast$GenericInstExpr_t*) t0)->f_callee.tag == 655u) {
            t0 = l0.payload.obj;
            l5 = toolchain_span$Span$std_core$Hash$hash(((vader_struct_toolchain_ast$IdentExpr_t*) ((vader_struct_toolchain_ast$GenericInstExpr_t*) t0)->f_callee.payload.obj)->f_span);
            l4 = std_collections$MutableMap$std_core$Index$at__u64__Any(l1, l5);
            if (l4.tag == 0u) {
                return vader_box_obj(0u, NULL);
            }
            t0 = l4.payload.obj;
            t1 = vader_front_resolver$resolve_import_redirect(t0, l2);
            return vader_ref_box(t1);
        }
        return vader_box_obj(0u, NULL);
    }
    return vader_box_obj(0u, NULL);
}

static int32_t vader_front_resolver$frame_count(void* l0) {
    int64_t t0;
    t0 = ((vader_array_t*) ((vader_struct_vader_front_resolver$Scope_t*) l0)->f_frames)->length;
    return ((int32_t) (int64_t) t0);
}

static vader_string_t vader_front_resolver$generated_root_for(vader_box_t l0) {
    vader_string_t l1 = 0;
    bool t0;
    vader_box_t* gc_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 335u) {
        l1 = l0.payload.s;
    } else {
        if (!(l0.tag == 0u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = std_io$current_working_directory();
    }
    l1 = vader_front_resolver$join_path(l1, 1671u);
    t0 = std_io$is_dir(l1);
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return 0u; }
    }
    { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$graft_body(void* l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    int64_t l3, l5;
    vader_string_t l7 = 0;
    uint8_t l9;
    vader_box_t l12 = vader_box_null(), l13 = vader_box_null(), l19 = vader_box_null();
    bool l14, l15, l16, l17, l18;
    vader_string_t t0 = 0;
    bool t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[3] = { &l12, &l13, &l19 };
    void** gc_raw_roots[9] = { &l0, &l1, &l2, &l4, &l6, &l8, &l10, &l11, &t2 };
    vader_string_t* gc_atom_roots[2] = { &l7, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(42u, 0u, 13u, 633u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_array_t*) ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_decorators)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a1_arr;
    l4 = ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_decorators;
    l3 = ((vader_array_t*) l4)->length;
    l5 = INT64_C(0);
    while ((l5 < l3)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l6 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
        vader_array_push_ref((vader_array_t*) l2, l6);
        l5 = (l5 + INT64_C(1));
    }
    l4 = ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_decorators;
    l3 = ((vader_array_t*) l4)->length;
    l5 = INT64_C(0);
    while ((l5 < l3)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        l6 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l5);
        t0 = ((vader_struct_toolchain_ast$Decorator_t*) l6)->f_name;
        t1 = vader_front_resolver$provides_body(t0);
        if (t1) {
            vader_array_push_ref((vader_array_t*) l2, l6);
        }
        l5 = (l5 + INT64_C(1));
    }
    l4 = l0;
    l6 = ((vader_struct_toolchain_ast$FnDecl_t*) l4)->f_span;
    l3 = ((vader_struct_toolchain_ast$FnDecl_t*) l4)->f_id;
    l7 = ((vader_struct_toolchain_ast$FnDecl_t*) l4)->f_name;
    l8 = ((vader_struct_toolchain_ast$FnDecl_t*) l4)->f_name_span;
    l9 = ((vader_struct_toolchain_ast$FnDecl_t*) l4)->f_visibility;
    l10 = ((vader_struct_toolchain_ast$FnDecl_t*) l4)->f_type_params;
    l11 = ((vader_struct_toolchain_ast$FnDecl_t*) l4)->f_params;
    l12 = ((vader_struct_toolchain_ast$FnDecl_t*) l4)->f_return_type;
    l13 = ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_body;
    l14 = ((vader_struct_toolchain_ast$FnDecl_t*) l4)->f_sam_synthetic;
    l15 = ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_is_expression_bodied;
    l16 = ((vader_struct_toolchain_ast$FnDecl_t*) l4)->f_materialized;
    l17 = ((vader_struct_toolchain_ast$FnDecl_t*) l4)->f_comptime_synthetic;
    l18 = ((vader_struct_toolchain_ast$FnDecl_t*) l4)->f_trailing_comma;
    l19 = ((vader_struct_toolchain_ast$FnDecl_t*) l4)->f_doc;
    vader_struct_toolchain_ast$FnDecl_t* _a4_obj = (vader_struct_toolchain_ast$FnDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$FnDecl_t));
    vader_obj_header_init(_a4_obj, 650u);
    _a4_obj->f_span = l6;
    _a4_obj->f_id = l3;
    _a4_obj->f_name = l7;
    _a4_obj->f_name_span = l8;
    _a4_obj->f_visibility = l9;
    _a4_obj->f_type_params = l10;
    _a4_obj->f_params = l11;
    _a4_obj->f_return_type = l12;
    _a4_obj->f_body = l13;
    _a4_obj->f_decorators = l2;
    _a4_obj->f_sam_synthetic = l14;
    _a4_obj->f_is_expression_bodied = l15;
    _a4_obj->f_materialized = l16;
    _a4_obj->f_comptime_synthetic = l17;
    _a4_obj->f_trailing_comma = l18;
    _a4_obj->f_doc = l19;
    t2 = (void*) _a4_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_front_resolver$has_impl_decl(void* l0) {
    void* l1;
    int64_t l2, l3;
    vader_box_t t0;
    l1 = l0;
    l2 = ((vader_array_t*) l1)->length;
    l3 = INT64_C(0);
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        if (t0.tag == 659u) {
            return true;
        }
        l3 = (l3 + INT64_C(1));
    }
    return false;
}

static bool vader_front_resolver$has_module(void* l0, vader_string_t l1) {
    vader_box_t t0;
    t0 = std_collections$MutableMap$std_core$Index$at__string__Any(l0, l1);
    return !(t0.tag == 0u);
}

static bool vader_front_resolver$has_reassignment(void* l0, void* l1) {
    void* l2;
    void* l5;
    void* l6;
    int64_t l3, l4;
    int32_t l7;
    bool t0;
    l2 = l1;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        l6 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_reassigned;
        l7 = ((vader_struct_vader_core_symbol$Symbol_t*) l5)->f_id;
        t0 = std_collections$MutableSet$std_core$Contains$contains__i32(l6, l7);
        if (t0) {
            return true;
        }
        l4 = (l4 + INT64_C(1));
    }
    return false;
}

static vader_box_t vader_front_resolver$home_root(vader_string_t l0, vader_string_t l1) {
    vader_string_t l2 = 0;
    vader_box_t l3 = vader_box_null();
    vader_string_t t0 = 0;
    bool t1;
    vader_box_t* gc_roots[1] = { &l3 };
    vader_string_t* gc_atom_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_host_std_env$get_env(935u);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = l3.payload.s;
    if (l2 == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = vader_front_resolver$join_path(l2, l0);
    t0 = vader_front_resolver$join_path(l2, l1);
    t1 = std_io$exists(t0);
    if (!(t1)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    { vader_box_t __vret = vader_box_string(335u, l2); vader_gc_top = gc_frame.prev; return __vret; }
}

static uint8_t vader_front_resolver$importer_origin(void* l0, vader_string_t l1) {
    void* l2;
    vader_box_t l3;
    l3 = std_collections$MutableMap$std_core$Index$at__string__Any(l0, l1);
    if (l3.tag == 0u) {
        return (uint8_t) 0;
    }
    l2 = l3.payload.obj;
    return ((vader_struct_vader_front_resolver$DiscoveredModule_t*) l2)->f_origin;
}

static void* vader_front_resolver$include_paths(void* l0, void* l1, vader_string_t l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &l4 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(139u, 1u, 13u, 1093u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l0;
    l3 = (void*) _a0_arr;
    vader_array_push_all((vader_array_t*) l3, (vader_array_t*) l1);
    if (l2 != 0u) {
        vader_struct_vader_front_resolver$IncludePath_t* _a1_obj = (vader_struct_vader_front_resolver$IncludePath_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$IncludePath_t));
        vader_obj_header_init(_a1_obj, 1093u);
        _a1_obj->f_dir = l2;
        _a1_obj->f_prefix = 0u;
        _a1_obj->f_merge = true;
        _a1_obj->f_origin = (uint8_t) 0;
        l4 = (void*) _a1_obj;
        vader_array_push_ref((vader_array_t*) l3, l4);
        { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_front_resolver$index_declaration(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    uint64_t l3;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_core_symbol$Symbol_t*) l1)->f_defined_at;
    if (l2.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = l2.payload.obj;
    l3 = toolchain_span$Span$std_core$Hash$hash(t0);
    std_collections$MutableMap$std_core$IndexSet$set_at__u64__Any(l0, l3, vader_ref_box(l1));
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$ingest_module(void* l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    vader_box_t l3 = vader_box_null();
    vader_string_t l10 = 0;
    vader_string_t l11 = 0;
    vader_string_t l12 = 0;
    vader_string_t l13 = 0;
    uint8_t l14;
    int64_t t0;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[9] = { &l0, &l1, &l2, &l4, &l5, &l6, &l7, &l8, &l9 };
    vader_string_t* gc_atom_roots[4] = { &l10, &l11, &l12, &l13 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_vader_front_resolver$DiscoveredModule_t*) l1)->f_files)->length;
    if (t0 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l2 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) l1)->f_files;
    l2 = vader_front_resolver$parse_module_files(l0, l2);
    t0 = ((vader_array_t*) l2)->length;
    if (!(t0 == INT64_C(0))) {
        l3 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_selected_target;
        l4 = vader_front_resolver$discarded_bodies(l2, l3);
        l3 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_selected_target;
        l5 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_diags;
        l5 = vader_front_resolver$select_target_bodies(l2, l3, l5);
        l6 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_bases;
        l7 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_index;
        l8 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_overlay;
        l9 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_diags;
        vader_front_resolver$preresolve_imports(l5, l6, l7, l8, l9);
        l10 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) l1)->f_folder;
        l11 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) l1)->f_name;
        l6 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_factory;
        l7 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_index;
        l8 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_bases;
        l9 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_diags;
        l6 = vader_front_resolver$collect_files(l5, l10, l11, l6, l7, l8, l9);
        l7 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_modules;
        l10 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) l1)->f_folder;
        l11 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) l1)->f_folder;
        l12 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) l1)->f_name;
        l13 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) l1)->f_name;
        l14 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) l1)->f_origin;
        vader_struct_vader_front_resolver$Module_t* _a0_obj = (vader_struct_vader_front_resolver$Module_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$Module_t));
        vader_obj_header_init(_a0_obj, 1099u);
        _a0_obj->f_id = l11;
        _a0_obj->f_display_path = l12;
        _a0_obj->f_module_name = l13;
        _a0_obj->f_origin = l14;
        _a0_obj->f_files = l5;
        l5 = (void*) _a0_obj;
        l8 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_node_factory;
        l2 = vader_front_resolver$target_declarations(l2);
        vader_struct_vader_front_resolver$LoadedModule_t* _a1_obj = (vader_struct_vader_front_resolver$LoadedModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$LoadedModule_t));
        vader_obj_header_init(_a1_obj, 1095u);
        _a1_obj->f_module = l5;
        _a1_obj->f_collected = l6;
        _a1_obj->f_node_id_factory = l8;
        _a1_obj->f_discarded_bodies = l4;
        _a1_obj->f_target_decls = l2;
        l2 = (void*) _a1_obj;
        std_collections$MutableMap$std_core$IndexSet$set_at__string__Any(l7, l10, vader_ref_box(l2));
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_front_resolver$intrinsic_decorator(void* l0) {
    void* l1 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(238u, 0u, 13u, 1591u);
    l1 = (void*) _a0_arr;
    vader_struct_toolchain_ast$Decorator_t* _a1_obj = (vader_struct_toolchain_ast$Decorator_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$Decorator_t));
    vader_obj_header_init(_a1_obj, 633u);
    _a1_obj->f_span = l0;
    _a1_obj->f_id = INT64_C(0);
    _a1_obj->f_name = 2195u;
    _a1_obj->f_args = l1;
    t0 = (void*) _a1_obj;
    vader_array_t* _a2_arr = vader_array_new(42u, 1u, 13u, 633u);
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = t0;
    t0 = (void*) _a2_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_front_resolver$is_contract_decorator(vader_string_t l0) {
    if (l0 == 2533u) {
        return true;
    }
    return l0 == 1883u;
}

static bool vader_front_resolver$is_host_bound(void* l0) {
    void* l1;
    void* l4;
    int64_t l2, l3;
    vader_string_t t0;
    l1 = ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_decorators;
    l2 = ((vader_array_t*) l1)->length;
    l3 = INT64_C(0);
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        t0 = ((vader_struct_toolchain_ast$Decorator_t*) l4)->f_name;
        if (t0 == 2195u) {
            return true;
        }
        t0 = ((vader_struct_toolchain_ast$Decorator_t*) l4)->f_name;
        if (t0 == 1954u) {
            return true;
        }
        l3 = (l3 + INT64_C(1));
    }
    return false;
}

static bool vader_front_resolver$is_intrinsic(void* l0) {
    void* l1;
    int64_t l2, l3;
    void* t0;
    vader_string_t t1;
    l1 = l0;
    l2 = ((vader_array_t*) l1)->length;
    l3 = INT64_C(0);
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        t1 = ((vader_struct_toolchain_ast$Decorator_t*) t0)->f_name;
        if (t1 == 2195u) {
            return true;
        }
        l3 = (l3 + INT64_C(1));
    }
    return false;
}

static bool vader_front_resolver$is_known_decorator(vader_string_t l0) {
    bool t0;
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = vader_front_parser$decorator_on(l0, (uint8_t) 0);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    t0 = vader_front_parser$decorator_on(l0, (uint8_t) 1);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_front_resolver$is_portable_name(vader_string_t l0) {
    void* l1 = NULL;
    int64_t l2, l3;
    uint8_t l4;
    bool t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[1] = { &l1 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0 == 0u) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    t0 = std_string$starts_with(l0, 383u);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    l1 = vader_host_std_core$bytes(l0);
    l2 = ((vader_array_t*) l1)->length;
    l3 = INT64_C(0);
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t1 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l3, 340u);
        l4 = ((uint8_t) t1.payload.i);
        t0 = vader_support_text$is_ident_byte(l4);
        if (!(t0)) {
            if (l4 != INT32_C(45)) {
                { vader_gc_top = gc_frame.prev; return false; }
            }
        }
        l3 = (l3 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return true; }
}

static bool vader_front_resolver$is_windows_device_name(vader_string_t l0) {
    vader_string_t l1 = 0;
    bool l2;
    uint8_t l3;
    void* t0 = NULL;
    bool t1;
    int64_t t2;
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = std_string$to_lower(l0);
    vader_array_t* _a0_arr = vader_array_new(21u, 4u, 0u, 335u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 3u] = vader_box_string(335u, 2415u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 2u] = vader_box_string(335u, 1612u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 1u] = vader_box_string(335u, 2479u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 0u] = vader_box_string(335u, 1792u);
    t0 = (void*) _a0_arr;
    t1 = std_core$$array$Contains$contains__string(t0, l1);
    if (t1) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    t2 = vader_host_std_core$byte_len(l1);
    if (t2 == INT64_C(4)) {
        t1 = std_string$starts_with(l1, 1773u);
        if (t1) {
            l2 = true;
        } else {
            l2 = std_string$starts_with(l1, 2303u);
        }
    } else {
        l2 = false;
    }
    if (l2) {
        l3 = vader_host_std_core$byte_at(l1, INT64_C(3));
        if ((INT32_C(48) <= l3)) {
            l2 = (l3 <= INT32_C(57));
        } else {
            l2 = false;
        }
        { bool __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

vader_string_t vader_front_resolver$join_path(vader_string_t l0, vader_string_t l1) {
    vader_string_t l2 = 0;
    bool t0;
    vader_string_t t1 = 0;
    vader_string_t* gc_atom_roots[4] = { &l0, &l1, &l2, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = std_string$trim_prefix(l1, 403u);
    if (l0 == 0u) {
        { vader_string_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = std_string$ends_with(l0, 438u);
    if (!(t0)) {
        t1 = concat_3(l0, 438u, l2);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = concat_2(l0, l2);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_front_resolver$leaves_project(vader_string_t l0) {
    vader_string_t l1 = 0;
    bool l2;
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[1] = { &t1 };
    vader_string_t* gc_atom_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = std_path$to_posix(l0);
    t0 = std_string$starts_with(l1, 438u);
    if (t0) {
        l2 = true;
    } else {
        l2 = std_string$string$std_core$Contains$contains(l1, 459u);
    }
    if (l2) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    t1 = std_string$split(l1, 438u);
    t0 = std_core$$array$Contains$contains__string(t1, 398u);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_front_resolver$load_baked_target(void* l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    vader_box_t l3 = vader_box_null();
    vader_string_t l5 = 0;
    vader_string_t l10 = 0;
    vader_string_t l11 = 0;
    vader_string_t l12 = 0;
    int64_t l8, l9;
    bool l18;
    bool t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l3, &t1 };
    void** gc_raw_roots[11] = { &l0, &l1, &l2, &l4, &l6, &l7, &l13, &l14, &l15, &l16, &l17 };
    vader_string_t* gc_atom_roots[4] = { &l5, &l10, &l11, &l12 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 11u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_front_resolver$resolve_in(l0, 2598u);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l2 = l3.payload.obj;
    l4 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_modules;
    l5 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) l2)->f_folder;
    t0 = vader_front_resolver$has_module(l4, l5);
    if (!(t0)) {
        vader_array_t* _a0_arr = vader_array_new(136u, 1u, 13u, 1087u);
        ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l2;
        l2 = (void*) _a0_arr;
        vader_front_resolver$drain_load_queue(l0, l2);
    }
    vader_array_t* _a1_arr = vader_array_new(21u, 0u, 0u, 335u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(21u, 0u, 0u, 335u);
    l4 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(22u, 0u, 7u, 338u);
    l6 = (void*) _a3_arr;
    vader_struct_std_collections$MutableMap__string__string_t* _a4_obj = (vader_struct_std_collections$MutableMap__string__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__string_t));
    vader_obj_header_init(_a4_obj, 553u);
    _a4_obj->f_ekeys = l2;
    _a4_obj->f_evals = l4;
    _a4_obj->f_index = l6;
    _a4_obj->f_mask = INT64_C(0);
    _a4_obj->f_grow_at = INT64_C(0);
    _a4_obj->f_size = INT64_C(0);
    _a4_obj->f_tombs = INT64_C(0);
    l2 = (void*) _a4_obj;
    l4 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_overlay;
    l6 = ((vader_struct_std_collections$MutableMap__string__string_t*) l4)->f_ekeys;
    l7 = ((vader_struct_std_collections$MutableMap__string__string_t*) l4)->f_evals;
    l8 = INT64_C(0);
    l9 = ((vader_struct_std_collections$MutableMap__string__string_t*) l4)->f_size;
    while ((l8 < l9)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l8)
        t1 = vader_array_box_slots(_a5_slotarr->buf)[_a5_slotarr->offset + (size_t) l8];
        l5 = t1.payload.s;
        vader_array_t* _a6_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l8)
        t1 = vader_array_box_slots(_a6_slotarr->buf)[_a6_slotarr->offset + (size_t) l8];
        l10 = t1.payload.s;
        l11 = l5;
        l12 = l10;
        std_collections$MutableMap$std_core$IndexSet$set_at__string__string(l2, l11, l12);
        l8 = (l8 + INT64_C(1));
    }
    l5 = vader_support_target$baked_module_source(l1);
    std_collections$MutableMap$std_core$IndexSet$set_at__string__string(l2, 506u, l5);
    vader_array_t* _a7_arr = vader_array_new(21u, 1u, 0u, 335u);
    vader_array_box_slots(_a7_arr->buf)[_a7_arr->offset + 0u] = vader_box_string(335u, 506u);
    l4 = (void*) _a7_arr;
    vader_struct_vader_front_resolver$DiscoveredModule_t* _a8_obj = (vader_struct_vader_front_resolver$DiscoveredModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$DiscoveredModule_t));
    vader_obj_header_init(_a8_obj, 1087u);
    _a8_obj->f_name = 2599u;
    _a8_obj->f_folder = 505u;
    _a8_obj->f_files = l4;
    _a8_obj->f_origin = (uint8_t) 1;
    l4 = (void*) _a8_obj;
    l6 = l0;
    l7 = ((vader_struct_vader_front_resolver$LoadState_t*) l6)->f_bases;
    l13 = ((vader_struct_vader_front_resolver$LoadState_t*) l6)->f_modules;
    l14 = ((vader_struct_vader_front_resolver$LoadState_t*) l6)->f_factory;
    l15 = ((vader_struct_vader_front_resolver$LoadState_t*) l6)->f_index;
    l16 = ((vader_struct_vader_front_resolver$LoadState_t*) l6)->f_diags;
    l17 = ((vader_struct_vader_front_resolver$LoadState_t*) l6)->f_node_factory;
    l3 = ((vader_struct_vader_front_resolver$LoadState_t*) l6)->f_selected_target;
    l18 = ((vader_struct_vader_front_resolver$LoadState_t*) l6)->f_keep_docs;
    vader_struct_vader_front_resolver$LoadState_t* _a9_obj = (vader_struct_vader_front_resolver$LoadState_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$LoadState_t));
    vader_obj_header_init(_a9_obj, 1094u);
    _a9_obj->f_bases = l7;
    _a9_obj->f_modules = l13;
    _a9_obj->f_factory = l14;
    _a9_obj->f_index = l15;
    _a9_obj->f_diags = l16;
    _a9_obj->f_overlay = l2;
    _a9_obj->f_node_factory = l17;
    _a9_obj->f_selected_target = l3;
    _a9_obj->f_keep_docs = l18;
    l2 = (void*) _a9_obj;
    vader_array_t* _a10_arr = vader_array_new(136u, 1u, 13u, 1087u);
    ((void**) _a10_arr->buf->slots)[_a10_arr->offset + 0u] = l4;
    l4 = (void*) _a10_arr;
    vader_front_resolver$drain_load_queue(l2, l4);
    { vader_gc_top = gc_frame.prev; return; }
}

void* vader_front_resolver$load_project(vader_string_t l0, void* l1, vader_box_t l2, vader_box_t l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l2, &l3 };
    void** gc_raw_roots[5] = { &l1, &l4, &l5, &l6, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 335u);
    l4 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(21u, 0u, 0u, 335u);
    l5 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
    l6 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__string__string_t* _a3_obj = (vader_struct_std_collections$MutableMap__string__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__string_t));
    vader_obj_header_init(_a3_obj, 553u);
    _a3_obj->f_ekeys = l4;
    _a3_obj->f_evals = l5;
    _a3_obj->f_index = l6;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l4 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(21u, 0u, 0u, 335u);
    l5 = (void*) _a4_arr;
    t0 = vader_front_resolver$load_project_with_overlay(l0, l4, l1, l2, l3, l5, false);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$load_project_with_overlay(vader_string_t l0, void* l1, void* l2, vader_box_t l3, vader_box_t l4, void* l5, bool l6) {
    void* l7 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    void* l19 = NULL;
    vader_string_t l8 = 0;
    vader_string_t l20 = 0;
    vader_box_t l9 = vader_box_null(), l10 = vader_box_null(), l11 = vader_box_null();
    int64_t l21, l22;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    bool t2;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[6] = { &l3, &l4, &l9, &l10, &l11, &t3 };
    void** gc_raw_roots[13] = {
        &l1, &l2, &l5, &l7, &l12, &l13, &l14, &l15, &l16, &l17, &l18, &l19, &t0,
    };
    vader_string_t* gc_atom_roots[4] = { &l0, &l8, &l20, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 6u, 13u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_vader_core_symbol$SymbolFactory_t* _a0_obj = (vader_struct_vader_core_symbol$SymbolFactory_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_symbol$SymbolFactory_t));
    vader_obj_header_init(_a0_obj, 893u);
    _a0_obj->f_next = INT32_C(1);
    l7 = (void*) _a0_obj;
    l8 = std_path$to_posix(l0);
    l9 = vader_front_resolver$posix_or_null(l3);
    l11 = l4;
    if (l11.tag == 0u) {
        t0 = vader_support_target$host_target();
        l10 = vader_ref_box(t0);
    } else {
        l10 = l11;
    }
    l12 = vader_front_resolver$baked_target_of(l10);
    l10 = vader_front_resolver$selected_target_of(l10);
    vader_array_t* _a1_arr = vader_array_new(21u, 0u, 0u, 335u);
    l13 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(28u, 0u, 0u, 346u);
    l14 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(22u, 0u, 7u, 338u);
    l15 = (void*) _a3_arr;
    vader_struct_std_collections$MutableMap__string__Any_t* _a4_obj = (vader_struct_std_collections$MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__Any_t));
    vader_obj_header_init(_a4_obj, 533u);
    _a4_obj->f_ekeys = l13;
    _a4_obj->f_evals = l14;
    _a4_obj->f_index = l15;
    _a4_obj->f_mask = INT64_C(0);
    _a4_obj->f_grow_at = INT64_C(0);
    _a4_obj->f_size = INT64_C(0);
    _a4_obj->f_tombs = INT64_C(0);
    l13 = (void*) _a4_obj;
    vader_array_t* _a5_arr = vader_array_new(217u, 0u, 13u, 1400u);
    l14 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(217u, 0u, 13u, 1400u);
    l15 = (void*) _a6_arr;
    l16 = vader_front_resolver$search_roots(l8, l2, l9, l1, l15);
    vader_array_t* _a7_arr = vader_array_new(21u, 0u, 0u, 335u);
    l17 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(28u, 0u, 0u, 346u);
    l18 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(22u, 0u, 7u, 338u);
    l19 = (void*) _a9_arr;
    vader_struct_std_collections$MutableMap__string__Any_t* _a10_obj = (vader_struct_std_collections$MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__Any_t));
    vader_obj_header_init(_a10_obj, 533u);
    _a10_obj->f_ekeys = l17;
    _a10_obj->f_evals = l18;
    _a10_obj->f_index = l19;
    _a10_obj->f_mask = INT64_C(0);
    _a10_obj->f_grow_at = INT64_C(0);
    _a10_obj->f_size = INT64_C(0);
    _a10_obj->f_tombs = INT64_C(0);
    l17 = (void*) _a10_obj;
    l11 = ((vader_struct_vader_front_resolver$SearchRoots_t*) l16)->f_entry;
    if (l11.tag == 0u) {
        vader_array_push_all((vader_array_t*) l14, (vader_array_t*) l15);
        l20 = vader_front_resolver$entry_folder_of(l8);
        l15 = vader_front_resolver$zero_span(l8);
        t1 = concat_3(2385u, l20, 1101u);
        l8 = concat_2(t1, 1515u);
        l15 = vader_support_diagnostics$resolver_error((uint8_t) 0, l15, l8);
        vader_array_push_ref((vader_array_t*) l14, l15);
        vader_struct_vader_front_resolver$LoadedProject_t* _a11_obj = (vader_struct_vader_front_resolver$LoadedProject_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$LoadedProject_t));
        vader_obj_header_init(_a11_obj, 1096u);
        _a11_obj->f_entry = l20;
        _a11_obj->f_modules = l13;
        _a11_obj->f_factory = l7;
        _a11_obj->f_project_root = l9;
        _a11_obj->f_diags = l14;
        t0 = (void*) _a11_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l11.tag == 1087u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    l15 = ((vader_struct_vader_front_resolver$SearchRoots_t*) l16)->f_paths;
    l16 = vader_front_parser$new_node_id_factory();
    vader_struct_vader_front_resolver$LoadState_t* _a12_obj = (vader_struct_vader_front_resolver$LoadState_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$LoadState_t));
    vader_obj_header_init(_a12_obj, 1094u);
    _a12_obj->f_bases = l15;
    _a12_obj->f_modules = l13;
    _a12_obj->f_factory = l7;
    _a12_obj->f_index = l17;
    _a12_obj->f_diags = l14;
    _a12_obj->f_overlay = l1;
    _a12_obj->f_node_factory = l16;
    _a12_obj->f_selected_target = l10;
    _a12_obj->f_keep_docs = l6;
    l15 = (void*) _a12_obj;
    t0 = l11.payload.obj;
    l8 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) t0)->f_name;
    l10 = vader_front_resolver$resolve_in(l15, l8);
    if (l10.tag == 0u) {
        l16 = l11.payload.obj;
    } else {
        l16 = l10.payload.obj;
    }
    vader_array_t* _a13_arr = vader_array_new(136u, 1u, 13u, 1087u);
    ((void**) _a13_arr->buf->slots)[_a13_arr->offset + 0u] = l16;
    l16 = (void*) _a13_arr;
    l10 = vader_front_resolver$resolve_in(l15, 2591u);
    if (l10.tag == 1087u) {
        t0 = l10.payload.obj;
        l8 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) t0)->f_folder;
        t0 = l11.payload.obj;
        l20 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) t0)->f_folder;
        if (l8 != l20) {
            l18 = l10.payload.obj;
            vader_array_push_ref((vader_array_t*) l16, l18);
        }
    }
    vader_front_resolver$drain_load_queue(l15, l16);
    l10 = vader_front_resolver$resolve_in(l15, 2597u);
    if (l10.tag == 1087u) {
        t0 = l10.payload.obj;
        l8 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) t0)->f_folder;
        t2 = vader_front_resolver$has_module(l13, l8);
        if (!(t2)) {
            t0 = l10.payload.obj;
            vader_array_t* _a14_arr = vader_array_new(136u, 1u, 13u, 1087u);
            ((void**) _a14_arr->buf->slots)[_a14_arr->offset + 0u] = t0;
            l16 = (void*) _a14_arr;
            vader_front_resolver$drain_load_queue(l15, l16);
        }
    }
    vader_array_t* _a15_arr = vader_array_new(136u, 0u, 13u, 1087u);
    l16 = (void*) _a15_arr;
    l18 = l5;
    l21 = ((vader_array_t*) l18)->length;
    l22 = INT64_C(0);
    while ((l22 < l21)) {
        vader_array_t* _a16_slotarr = ((vader_array_t*) l18);
        VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l22)
        t3 = vader_array_box_slots(_a16_slotarr->buf)[_a16_slotarr->offset + (size_t) l22];
        l8 = t3.payload.s;
        l10 = vader_front_resolver$resolve_in(l15, l8);
        if (l10.tag == 0u) {
            l22 = (l22 + INT64_C(1));
            continue;
        }
        l19 = l10.payload.obj;
        vader_array_push_ref((vader_array_t*) l16, l19);
        l22 = (l22 + INT64_C(1));
    }
    vader_front_resolver$drain_load_queue(l15, l16);
    vader_front_resolver$load_baked_target(l15, l12);
    vader_front_resolver$detect_import_cycles(l13, l17, l14);
    t0 = l11.payload.obj;
    t1 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) t0)->f_folder;
    vader_struct_vader_front_resolver$LoadedProject_t* _a17_obj = (vader_struct_vader_front_resolver$LoadedProject_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$LoadedProject_t));
    vader_obj_header_init(_a17_obj, 1096u);
    _a17_obj->f_entry = t1;
    _a17_obj->f_modules = l13;
    _a17_obj->f_factory = l7;
    _a17_obj->f_project_root = l9;
    _a17_obj->f_diags = l14;
    t0 = (void*) _a17_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_resolver$lookup(void* l0, vader_string_t l1) {
    int64_t l2;
    vader_box_t l3;
    void* t0;
    l2 = ((vader_array_t*) ((vader_struct_vader_front_resolver$Scope_t*) l0)->f_frames)->length;
    while ((l2 > INT64_C(0))) {
        l2 = vader_chk_sub(i64, l2, INT64_C(1));
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_front_resolver$Scope_t*) l0)->f_frames);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        l3 = std_collections$MutableMap$std_core$Index$at__string__Any(t0, l1);
        if (l3.tag == 892u) {
            t0 = l3.payload.obj;
            return vader_ref_box(t0);
        }
        if (!(l3.tag == 0u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
    }
    return vader_box_obj(0u, NULL);
}

static int32_t vader_front_resolver$lookup_frame_index(void* l0, vader_string_t l1) {
    int64_t l2;
    void* t0;
    vader_box_t t1;
    l2 = ((vader_array_t*) ((vader_struct_vader_front_resolver$Scope_t*) l0)->f_frames)->length;
    while ((l2 > INT64_C(0))) {
        l2 = vader_chk_sub(i64, l2, INT64_C(1));
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_front_resolver$Scope_t*) l0)->f_frames);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        t1 = std_collections$MutableMap$std_core$Index$at__string__Any(t0, l1);
        if (!(t1.tag == 0u)) {
            return ((int32_t) (int64_t) l2);
        }
    }
    return INT32_C(-1);
}

static vader_box_t vader_front_resolver$lookup_subst(void* l0, vader_string_t l1) {
    vader_box_t t0;
    t0 = std_collections$MutableMap$std_core$Index$at__string__Any(((vader_struct_vader_front_resolver$Subst_t*) l0)->f_entries, l1);
    return t0;
}

static vader_box_t vader_front_resolver$lookup_trait_sym(void* l0, void* l1, void* l2, void* l3) {
    vader_string_t l4;
    vader_box_t l5;
    void* t0;
    void* t1;
    l4 = ((vader_struct_toolchain_ast$ImplDecl_t*) l0)->f_trait_name;
    l5 = std_collections$MutableMap$std_core$Index$at__string__Any(l1, l4);
    if (l5.tag == 892u) {
        t0 = l5.payload.obj;
        t1 = vader_front_resolver$resolve_import_redirect(t0, l3);
        return vader_ref_box(t1);
    }
    l4 = ((vader_struct_toolchain_ast$ImplDecl_t*) l0)->f_trait_name;
    l5 = std_collections$MutableMap$std_core$Index$at__string__Any(l2, l4);
    if (l5.tag == 0u) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l5.payload.obj;
    t1 = vader_front_resolver$resolve_import_redirect(t0, l3);
    return vader_ref_box(t1);
}

static void* vader_front_resolver$make_builtin_scope(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    int64_t l4, l5;
    vader_string_t l6 = 0;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 335u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 346u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections$MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 533u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l1 = (void*) _a3_obj;
    l2 = vader_front_resolver$builtin_type_names();
    l4 = ((vader_array_t*) l2)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        t0 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l5];
        l6 = t0.payload.s;
        l3 = vader_core_symbol$make(l0, (uint8_t) 12, l6, 507u, 507u, (uint8_t) 0, vader_box_obj(0u, NULL));
        std_collections$MutableMap$std_core$IndexSet$set_at__string__Any(l1, l6, vader_ref_box(l3));
        l5 = (l5 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$manifest_at(vader_box_t l0) {
    vader_string_t l1 = 0;
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    bool t2;
    vader_box_t* gc_roots[2] = { &l0, &l2 };
    void** gc_raw_roots[6] = { &l3, &l4, &l5, &l6, &l7, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = l0;
    if (l2.tag == 0u) {
        vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 335u);
        l3 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_new(141u, 0u, 13u, 1098u);
        l4 = (void*) _a1_arr;
        vader_array_t* _a2_arr = vader_array_new(21u, 0u, 0u, 335u);
        l5 = (void*) _a2_arr;
        vader_array_t* _a3_arr = vader_array_new(21u, 0u, 0u, 335u);
        l6 = (void*) _a3_arr;
        vader_struct_vader_front_resolver$Manifest_t* _a4_obj = (vader_struct_vader_front_resolver$Manifest_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$Manifest_t));
        vader_obj_header_init(_a4_obj, 1097u);
        _a4_obj->f_name = 0u;
        _a4_obj->f_version = 0u;
        _a4_obj->f_include_paths = l3;
        _a4_obj->f_entries = l4;
        _a4_obj->f_assets = l5;
        _a4_obj->f_problems = l6;
        t0 = (void*) _a4_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = l2.payload.s;
    t1 = vader_front_resolver$join_path(l1, 2856u);
    t2 = std_io$exists(t1);
    if (t2) {
        t0 = vader_front_resolver$read_manifest(l1);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_front_resolver$declared_roots();
    l2 = std_collections$MutableMap$std_core$Index$at__string__string__(t0, l1);
    if (l2.tag == 0u) {
        vader_array_t* _a5_arr = vader_array_new(21u, 0u, 0u, 335u);
        l4 = (void*) _a5_arr;
        vader_array_t* _a6_arr = vader_array_new(141u, 0u, 13u, 1098u);
        l5 = (void*) _a6_arr;
        vader_array_t* _a7_arr = vader_array_new(21u, 0u, 0u, 335u);
        l6 = (void*) _a7_arr;
        vader_array_t* _a8_arr = vader_array_new(21u, 0u, 0u, 335u);
        l7 = (void*) _a8_arr;
        vader_struct_vader_front_resolver$Manifest_t* _a9_obj = (vader_struct_vader_front_resolver$Manifest_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$Manifest_t));
        vader_obj_header_init(_a9_obj, 1097u);
        _a9_obj->f_name = 0u;
        _a9_obj->f_version = 0u;
        _a9_obj->f_include_paths = l4;
        _a9_obj->f_entries = l5;
        _a9_obj->f_assets = l6;
        _a9_obj->f_problems = l7;
        t0 = (void*) _a9_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = l2.payload.obj;
    vader_array_t* _a10_arr = vader_array_new(141u, 0u, 13u, 1098u);
    l4 = (void*) _a10_arr;
    vader_array_t* _a11_arr = vader_array_new(21u, 0u, 0u, 335u);
    l5 = (void*) _a11_arr;
    vader_array_t* _a12_arr = vader_array_new(21u, 0u, 0u, 335u);
    l6 = (void*) _a12_arr;
    vader_struct_vader_front_resolver$Manifest_t* _a13_obj = (vader_struct_vader_front_resolver$Manifest_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$Manifest_t));
    vader_obj_header_init(_a13_obj, 1097u);
    _a13_obj->f_name = 0u;
    _a13_obj->f_version = 0u;
    _a13_obj->f_include_paths = l3;
    _a13_obj->f_entries = l4;
    _a13_obj->f_assets = l5;
    _a13_obj->f_problems = l6;
    t0 = (void*) _a13_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_front_resolver$manifest_root(vader_string_t l0, vader_string_t l1, vader_box_t l2) {
    vader_string_t l3 = 0;
    vader_string_t t0 = 0;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[1] = { &l2 };
    vader_string_t* gc_atom_roots[5] = { &l0, &l1, &l3, &t0, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = std_core$char$Display$to_string(36u);
    l3 = concat_2(t0, 935u);
    if (l1 == l3) {
        t0 = vader_front_resolver$toolchain_folder(l2);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = concat_2(l3, 438u);
    l3 = std_string$trim_prefix(l1, l3);
    if (!(l3 != l1)) {
        t0 = vader_front_resolver$join_path(l0, l1);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_front_resolver$toolchain_folder(l2);
    t1 = vader_front_resolver$join_path(t0, l3);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_front_resolver$matches_target(void* l0, void* l1) {
    void* l2;
    int64_t l3, l4;
    uint8_t l5, l6;
    vader_box_t t0;
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l4, 340u);
        l5 = ((uint8_t) t0.payload.i);
        l6 = ((vader_struct_vader_support_target$Target_t*) l1)->f_os;
        if (l5 == l6) {
            return true;
        }
        l4 = (l4 + INT64_C(1));
    }
    return false;
}

static void vader_front_resolver$materialize_default_members(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l9 = NULL;
    void* l12 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    int32_t l6, l7;
    vader_string_t l8 = 0;
    int64_t l10, l11, l16;
    vader_box_t l13 = vader_box_null();
    bool t0;
    int32_t t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &l13 };
    void** gc_raw_roots[13] = {
        &l0, &l1, &l2, &l3, &l4, &l5, &l9, &l12, &l14, &l15, &l17, &l18, &t2,
    };
    vader_string_t* gc_atom_roots[1] = { &l8 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 13u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_front_resolver$any_has_body(((vader_struct_toolchain_ast$TraitDecl_t*) l1)->f_members);
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = vader_front_resolver$provided_names(((vader_struct_toolchain_ast$ImplDecl_t*) l0)->f_members);
    l4 = vader_front_resolver$build_subst(l0, l1);
    l5 = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_toolchain_ast$ImplDecl_t*) l0)->f_trait_name_span)->f_start;
    t1 = ((vader_struct_toolchain_span$Position_t*) l5)->f_line;
    l6 = vader_chk_mul(i32, t1, INT32_C(1024));
    l7 = ((vader_struct_toolchain_span$Position_t*) l5)->f_column;
    l6 = vader_chk_add(i32, l6, l7);
    l8 = ((vader_struct_toolchain_span$Position_t*) l5)->f_file;
    l8 = concat_2(509u, l8);
    vader_struct_vader_front_resolver$StampCtx_t* _a0_obj = (vader_struct_vader_front_resolver$StampCtx_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$StampCtx_t));
    vader_obj_header_init(_a0_obj, 1107u);
    _a0_obj->f_base_line = l6;
    _a0_obj->f_counter = INT32_C(0);
    _a0_obj->f_file = l8;
    l5 = (void*) _a0_obj;
    l9 = ((vader_struct_toolchain_ast$TraitDecl_t*) l1)->f_members;
    l10 = ((vader_array_t*) l9)->length;
    l11 = INT64_C(0);
    while ((l11 < l10)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l12 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l11);
        l13 = ((vader_struct_toolchain_ast$FnDecl_t*) l12)->f_body;
        if (!(l13.tag == 0u)) {
            if (!(l13.tag == 624u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            l8 = ((vader_struct_toolchain_ast$FnDecl_t*) l12)->f_name;
            t0 = std_collections$MutableSet$std_core$Contains$contains__string(l3, l8);
            if (t0) {
                l11 = (l11 + INT64_C(1));
                continue;
            }
            vader_array_t* _a2_arr = vader_array_new(42u, 0u, 13u, 633u);
            l14 = (void*) _a2_arr;
            t2 = l13.payload.obj;
            l15 = vader_front_resolver$substitute_block_materialized(t2, l4, l2, l5);
            l16 = vader_front_parser$mint(l2);
            l17 = ((vader_struct_toolchain_ast$ImplDecl_t*) l0)->f_members;
            l18 = vader_front_resolver$synth_with_body(l12, l4, l14, l15, l5, l16);
            vader_array_push_ref((vader_array_t*) l17, l18);
        }
        l11 = (l11 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$materialize_file_impl_members(void* l0, void* l1, void* l2, void* l3, void* l4) {
    void* l5 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
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
    vader_string_t l7 = 0;
    vader_string_t l14 = 0;
    vader_string_t l15 = 0;
    vader_string_t l19 = 0;
    vader_string_t l20 = 0;
    int64_t l11, l12;
    vader_box_t l13 = vader_box_null();
    bool t0;
    void* t1 = NULL;
    vader_string_t t2 = 0;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l13, &t3 };
    void** gc_raw_roots[24] = {
        &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l8, &l9, &l10, &l16, &l17, &l18, &l21, &l22, &l23, &l24,
        &l25, &l26, &l27, &l28, &l29, &l30, &t1,
    };
    vader_string_t* gc_atom_roots[6] = { &l7, &l14, &l15, &l19, &l20, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 24u, gc_roots, gc_raw_roots, 0u, NULL, 6u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l5 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) l2)->f_program)->f_decls;
    t0 = vader_front_resolver$has_impl_decl(l5);
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l6 = ((vader_struct_vader_front_resolver$LoadedModule_t*) l1)->f_collected;
    l7 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) l2)->f_program)->f_file;
    l6 = vader_front_resolver$file_imports(l6, l7);
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 335u);
    l8 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 346u);
    l9 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
    l10 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections$MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 533u);
    _a3_obj->f_ekeys = l8;
    _a3_obj->f_evals = l9;
    _a3_obj->f_index = l10;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l8 = (void*) _a3_obj;
    l9 = ((vader_struct_vader_front_resolver$LoadedModule_t*) l1)->f_collected;
    l6 = vader_front_resolver$file_root_scope(l8, l9, l6, l3, l4);
    l11 = ((vader_array_t*) l5)->length;
    l12 = INT64_C(0);
    while ((l12 < l11)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        l13 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l12);
        if (l13.tag == 659u) {
            t1 = l13.payload.obj;
            t2 = ((vader_struct_toolchain_ast$ImplDecl_t*) t1)->f_trait_name;
            l8 = vader_front_resolver$find_impl_trait_decl(t2, l1, l6, l3, l0);
            if (((vader_struct_vader_front_resolver$TraitLookup_t*) l8)->f_trait_decl.tag == 0u) {
                t2 = ((vader_struct_vader_front_resolver$TraitLookup_t*) l8)->f_other_kind;
                if (t2 != 0u) {
                    l9 = ((vader_struct_vader_front_resolver$LoadedProject_t*) l0)->f_diags;
                    t1 = l13.payload.obj;
                    l10 = ((vader_struct_toolchain_ast$ImplDecl_t*) t1)->f_trait_name_span;
                    t1 = l13.payload.obj;
                    l7 = ((vader_struct_toolchain_ast$ImplDecl_t*) t1)->f_trait_name;
                    l14 = ((vader_struct_vader_front_resolver$TraitLookup_t*) l8)->f_other_kind;
                    l15 = concat_4(1038u, l7, 1135u, l14);
                    l16 = vader_support_diagnostics$resolver_error((uint8_t) 8, l10, l15);
                    vader_array_push_ref((vader_array_t*) l9, l16);
                } else {
                    l17 = ((vader_struct_vader_front_resolver$LoadedProject_t*) l0)->f_diags;
                    t1 = l13.payload.obj;
                    l18 = ((vader_struct_toolchain_ast$ImplDecl_t*) t1)->f_trait_name_span;
                    t1 = l13.payload.obj;
                    l19 = ((vader_struct_toolchain_ast$ImplDecl_t*) t1)->f_trait_name;
                    l20 = concat_3(1038u, l19, 1038u);
                    l21 = vader_support_diagnostics$resolver_error((uint8_t) 6, l18, l20);
                    vader_array_push_ref((vader_array_t*) l17, l21);
                }
                l12 = (l12 + INT64_C(1));
                continue;
            }
            t3 = ((vader_struct_vader_front_resolver$TraitLookup_t*) l8)->f_trait_decl;
            l22 = t3.payload.obj;
            l23 = l13.payload.obj;
            l24 = ((vader_struct_vader_front_resolver$LoadedProject_t*) l0)->f_diags;
            vader_front_resolver$check_short_impl_arity(l23, l22, l24);
            l25 = l13.payload.obj;
            l26 = ((vader_struct_vader_front_resolver$LoadedModule_t*) l1)->f_node_id_factory;
            vader_front_resolver$materialize_intrinsic_members(l25, l22, l26);
            l27 = l13.payload.obj;
            l28 = ((vader_struct_vader_front_resolver$LoadedModule_t*) l1)->f_node_id_factory;
            vader_front_resolver$materialize_sam_members(l27, l22, l28);
            l29 = l13.payload.obj;
            l30 = ((vader_struct_vader_front_resolver$LoadedModule_t*) l1)->f_node_id_factory;
            vader_front_resolver$materialize_default_members(l29, l22, l30);
            l12 = (l12 + INT64_C(1));
            continue;
        }
        l12 = (l12 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

void vader_front_resolver$materialize_impl_members(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l8 = NULL;
    void* l11 = NULL;
    int64_t l6, l7, l9, l10;
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l4, &l5, &l8, &l11 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_front_resolver$LoadedProject_t*) l0)->f_modules;
    l4 = ((vader_struct_std_collections$MutableMap__string__vader_front_resolver_LoadedModule_t*) l3)->f_ekeys;
    l5 = ((vader_struct_std_collections$MutableMap__string__vader_front_resolver_LoadedModule_t*) l3)->f_evals;
    l6 = INT64_C(0);
    l7 = ((vader_struct_std_collections$MutableMap__string__vader_front_resolver_LoadedModule_t*) l3)->f_size;
    while ((l6 < l7)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
        t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l6];
        t1 = t0.payload.s;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        l3 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
        l8 = ((vader_struct_vader_front_resolver$Module_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l3)->f_module)->f_files;
        l9 = ((vader_array_t*) l8)->length;
        l10 = INT64_C(0);
        while ((l10 < l9)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            l11 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l10);
            vader_front_resolver$materialize_file_impl_members(l0, l3, l11, l1, l2);
            l10 = (l10 + INT64_C(1));
        }
        l6 = (l6 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$materialize_intrinsic_members(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l8 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l16 = NULL;
    int32_t l5, l6;
    vader_string_t l7 = 0;
    int64_t l9, l10, l15;
    bool t0;
    int64_t t1;
    int32_t t2;
    void** gc_raw_roots[11] = { &l0, &l1, &l2, &l3, &l4, &l8, &l11, &l12, &l13, &l14, &l16 };
    vader_string_t* gc_atom_roots[1] = { &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 11u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_front_resolver$is_intrinsic(((vader_struct_toolchain_ast$ImplDecl_t*) l0)->f_decorators);
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    t1 = ((vader_array_t*) ((vader_struct_toolchain_ast$ImplDecl_t*) l0)->f_members)->length;
    if ((t1 > INT64_C(0))) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = vader_front_resolver$build_subst(l0, l1);
    l4 = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_toolchain_ast$ImplDecl_t*) l0)->f_trait_name_span)->f_start;
    t2 = ((vader_struct_toolchain_span$Position_t*) l4)->f_line;
    l5 = vader_chk_mul(i32, t2, INT32_C(1024));
    l6 = ((vader_struct_toolchain_span$Position_t*) l4)->f_column;
    l5 = vader_chk_add(i32, l5, l6);
    l7 = ((vader_struct_toolchain_span$Position_t*) l4)->f_file;
    l7 = concat_2(509u, l7);
    vader_struct_vader_front_resolver$StampCtx_t* _a0_obj = (vader_struct_vader_front_resolver$StampCtx_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$StampCtx_t));
    vader_obj_header_init(_a0_obj, 1107u);
    _a0_obj->f_base_line = l5;
    _a0_obj->f_counter = INT32_C(0);
    _a0_obj->f_file = l7;
    l4 = (void*) _a0_obj;
    l8 = ((vader_struct_toolchain_ast$TraitDecl_t*) l1)->f_members;
    l9 = ((vader_array_t*) l8)->length;
    l10 = INT64_C(0);
    while ((l10 < l9)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l11 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l10);
        l12 = vader_front_resolver$intrinsic_decorator(((vader_struct_toolchain_ast$ImplDecl_t*) l0)->f_span);
        l13 = vader_front_resolver$next_clone_span(l4);
        l14 = ((vader_struct_toolchain_ast$ImplDecl_t*) l0)->f_members;
        l15 = vader_front_parser$mint(l2);
        l16 = vader_front_resolver$synth_signature(l11, l13, l3, l12, l15);
        vader_array_push_ref((vader_array_t*) l14, l16);
        l10 = (l10 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$materialize_sam_members(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l7 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    int64_t l5, l6;
    vader_string_t l8 = 0;
    vader_box_t l12 = vader_box_null();
    int64_t t0;
    bool t1;
    vader_box_t* gc_roots[1] = { &l12 };
    void** gc_raw_roots[9] = { &l0, &l1, &l2, &l3, &l4, &l7, &l9, &l10, &l11 };
    vader_string_t* gc_atom_roots[1] = { &l8 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_front_resolver$count_sam_synthetics(((vader_struct_toolchain_ast$ImplDecl_t*) l0)->f_members);
    if (t0 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = vader_front_resolver$required_methods(((vader_struct_toolchain_ast$TraitDecl_t*) l1)->f_members);
    t1 = std_iter$is_empty__toolchain_ast_AssertDecl___toolchain_ast_ConstDecl___toolchain_ast_EnumDecl___toolchain_ast_FnDecl___toolchain_ast_ImplDecl___toolchain_ast_ImportDecl___toolchain_ast_StructDecl___toolchain_ast_TraitDecl___toolchain_ast_TypeAliasDecl(l3);
    if (t1) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
    l4 = vader_front_resolver$build_subst(l0, l1);
    l5 = INT64_C(0);
    l6 = ((vader_array_t*) ((vader_struct_toolchain_ast$ImplDecl_t*) l0)->f_members)->length;
    while ((l5 < l6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$ImplDecl_t*) l0)->f_members);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        l7 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
        t1 = ((vader_struct_toolchain_ast$FnDecl_t*) l7)->f_sam_synthetic;
        if (t1) {
            l8 = ((vader_struct_toolchain_ast$FnDecl_t*) l3)->f_name;
            ((vader_struct_toolchain_ast$FnDecl_t*) l7)->f_name = l8;
            l9 = ((vader_struct_toolchain_ast$FnDecl_t*) l3)->f_params;
            l10 = ((vader_struct_toolchain_ast$FnDecl_t*) l7)->f_name_span;
            l11 = vader_front_resolver$substitute_params_disambiguated(l9, l4, l10, l2);
            ((vader_struct_toolchain_ast$FnDecl_t*) l7)->f_params = l11;
            VADER_WRITE_BARRIER((vader_struct_toolchain_ast$FnDecl_t*) l7);
            l12 = vader_front_resolver$substitute_opt_type(((vader_struct_toolchain_ast$FnDecl_t*) l3)->f_return_type, l4);
            ((vader_struct_toolchain_ast$FnDecl_t*) l7)->f_return_type = l12;
            VADER_WRITE_BARRIER((vader_struct_toolchain_ast$FnDecl_t*) l7);
            l5 = (l5 + INT64_C(1));
            continue;
        }
        l5 = (l5 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$merge_collected(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l10 = NULL;
    void* l12 = NULL;
    void* l14 = NULL;
    void* l18 = NULL;
    int64_t l6, l7, l11, l19, l20;
    vader_string_t l8 = 0;
    vader_string_t l9 = 0;
    vader_string_t l17 = 0;
    bool l13;
    vader_box_t l15 = vader_box_null(), l16 = vader_box_null();
    int32_t l21, l22;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    vader_box_t* gc_roots[3] = { &l15, &l16, &t0 };
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l4, &l5, &l10, &l12, &l14, &l18 };
    vader_string_t* gc_atom_roots[3] = { &l8, &l9, &l17 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_front_resolver$CollectedModule_t*) l1)->f_symbols;
    l4 = ((vader_struct_std_collections$MutableMap__string__vader_core_symbol_Symbol_t*) l3)->f_ekeys;
    l5 = ((vader_struct_std_collections$MutableMap__string__vader_core_symbol_Symbol_t*) l3)->f_evals;
    l6 = INT64_C(0);
    l7 = ((vader_struct_std_collections$MutableMap__string__vader_core_symbol_Symbol_t*) l3)->f_size;
    while ((l6 < l7)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
        t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l6];
        l8 = t0.payload.s;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        l3 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
        l9 = l8;
        l10 = l3;
        l11 = std_collections$len__string__Any(((vader_struct_vader_front_resolver$CollectedModule_t*) l0)->f_symbols);
        l12 = std_collections$get_or_put__string__vader_core_symbol_Symbol(((vader_struct_vader_front_resolver$CollectedModule_t*) l0)->f_symbols, l9, l10);
        t1 = std_collections$len__string__Any(((vader_struct_vader_front_resolver$CollectedModule_t*) l0)->f_symbols);
        if (!((t1 > l11))) {
            if (((vader_struct_vader_core_symbol$Symbol_t*) l12)->f_kind != INT32_C(0)) {
                l13 = true;
            } else {
                l13 = ((vader_struct_vader_core_symbol$Symbol_t*) l10)->f_kind != INT32_C(0);
            }
            if (l13) {
                l15 = ((vader_struct_vader_core_symbol$Symbol_t*) l10)->f_defined_at;
                l16 = l15;
                if (l15.tag == 712u) {
                    l14 = l16.payload.obj;
                } else {
                    if (!(l15.tag == 0u)) {
                        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                    }
                    l14 = vader_front_resolver$zero_span(0u);
                }
                l17 = concat_3(1038u, l9, 1055u);
                l18 = vader_support_diagnostics$resolver_error((uint8_t) 19, l14, l17);
                vader_array_push_ref((vader_array_t*) l2, l18);
            }
        }
        l6 = (l6 + INT64_C(1));
    }
    l3 = ((vader_struct_vader_front_resolver$CollectedModule_t*) l1)->f_fn_overloads;
    l4 = ((vader_struct_std_collections$MutableMap__string__vader_core_symbol_Symbol___t*) l3)->f_ekeys;
    l5 = ((vader_struct_std_collections$MutableMap__string__vader_core_symbol_Symbol___t*) l3)->f_evals;
    l6 = INT64_C(0);
    l7 = ((vader_struct_std_collections$MutableMap__string__vader_core_symbol_Symbol___t*) l3)->f_size;
    while ((l6 < l7)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
        t0 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l6];
        l8 = t0.payload.s;
        vader_array_t* _a3_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l6)
        l3 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l6);
        l9 = l8;
        l10 = l3;
        l11 = std_collections$len__string__Any(((vader_struct_vader_front_resolver$CollectedModule_t*) l0)->f_fn_overloads);
        l12 = std_collections$get_or_put__string__vader_core_symbol_Symbol__(((vader_struct_vader_front_resolver$CollectedModule_t*) l0)->f_fn_overloads, l9, l10);
        t1 = std_collections$len__string__Any(((vader_struct_vader_front_resolver$CollectedModule_t*) l0)->f_fn_overloads);
        if (t1 == l11) {
            l14 = l10;
            l19 = ((vader_array_t*) l14)->length;
            l20 = INT64_C(0);
            while ((l20 < l19)) {
                vader_array_t* _a4_slotarr = ((vader_array_t*) l14);
                VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                l18 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l20);
                vader_array_push_ref((vader_array_t*) l12, l18);
                l20 = (l20 + INT64_C(1));
            }
        }
        l6 = (l6 + INT64_C(1));
    }
    l3 = ((vader_struct_vader_front_resolver$CollectedModule_t*) l1)->f_imports;
    l4 = ((vader_struct_std_collections$MutableMap__i32__vader_front_resolver_ImportInfo_t*) l3)->f_ekeys;
    l5 = ((vader_struct_std_collections$MutableMap__i32__vader_front_resolver_ImportInfo_t*) l3)->f_evals;
    l6 = INT64_C(0);
    l7 = ((vader_struct_std_collections$MutableMap__i32__vader_front_resolver_ImportInfo_t*) l3)->f_size;
    while ((l6 < l7)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l6)
        l21 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l6];
        vader_array_t* _a6_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l6)
        l3 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l6);
        l22 = l21;
        l10 = l3;
        std_collections$MutableMap$std_core$IndexSet$set_at__i32__Any(((vader_struct_vader_front_resolver$CollectedModule_t*) l0)->f_imports, l22, vader_ref_box(l10));
        l6 = (l6 + INT64_C(1));
    }
    l3 = ((vader_struct_vader_front_resolver$CollectedModule_t*) l1)->f_import_paths;
    l6 = ((vader_array_t*) l3)->length;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a7_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        t0 = vader_array_box_slots(_a7_slotarr->buf)[_a7_slotarr->offset + (size_t) l7];
        l8 = t0.payload.s;
        vader_array_push_scalar((vader_array_t*) ((vader_struct_vader_front_resolver$CollectedModule_t*) l0)->f_import_paths, vader_box_string(335u, l8));
        l7 = (l7 + INT64_C(1));
    }
    l3 = ((vader_struct_vader_front_resolver$CollectedModule_t*) l0)->f_files;
    l4 = ((vader_struct_vader_front_resolver$CollectedModule_t*) l1)->f_files;
    vader_array_push_all((vader_array_t*) l3, (vader_array_t*) l4);
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_front_resolver$mint_local(void* l0, uint8_t l1, vader_string_t l2, void* l3) {
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
    if (l2 == 3016u) {
        l4 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_diags;
        l5 = concat_3(1038u, l2, 1038u);
        l6 = vader_support_diagnostics$resolver_error((uint8_t) 14, l3, l5);
        vader_array_push_ref((vader_array_t*) l4, l6);
    }
    l4 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_factory;
    l5 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_module_path;
    l7 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_module_path;
    t0 = vader_core_symbol$make(l4, l1, l2, l5, l7, (uint8_t) 1, vader_ref_box(l3));
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_resolver$misplaced_module_at(vader_string_t l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    int64_t l6, l7;
    vader_box_t l8 = vader_box_null(), l10 = vader_box_null();
    vader_string_t l9 = 0;
    void* t0 = NULL;
    bool t1;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[2] = { &l8, &l10 };
    void** gc_raw_roots[6] = { &l1, &l2, &l3, &l4, &l5, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l9, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(217u, 0u, 13u, 1400u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(21u, 0u, 0u, 335u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(21u, 0u, 0u, 335u);
    l4 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(22u, 0u, 7u, 338u);
    l5 = (void*) _a3_arr;
    vader_struct_std_collections$MutableMap__string__string_t* _a4_obj = (vader_struct_std_collections$MutableMap__string__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__string_t));
    vader_obj_header_init(_a4_obj, 553u);
    _a4_obj->f_ekeys = l3;
    _a4_obj->f_evals = l4;
    _a4_obj->f_index = l5;
    _a4_obj->f_mask = INT64_C(0);
    _a4_obj->f_grow_at = INT64_C(0);
    _a4_obj->f_size = INT64_C(0);
    _a4_obj->f_tombs = INT64_C(0);
    l3 = (void*) _a4_obj;
    l6 = INT64_C(0);
    l7 = ((vader_array_t*) l1)->length;
    while ((l6 < l7)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l6)
        t0 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l6);
        l8 = vader_front_resolver$rooted_candidate(t0, l0);
        if (l8.tag == 0u) {
            l6 = (l6 + INT64_C(1));
            continue;
        }
        l9 = l8.payload.s;
        t1 = std_io$is_dir(l9);
        if (t1) {
            l10 = vader_front_resolver$scan_folder(l9, l3, l2);
            if (l10.tag == 0u) {
                l6 = (l6 + INT64_C(1));
                continue;
            }
            l4 = l10.payload.obj;
            t2 = ((vader_struct_vader_front_resolver$FolderBucket_t*) l4)->f_name;
            if (t2 != 0u) {
                t2 = ((vader_struct_vader_front_resolver$FolderBucket_t*) l4)->f_name;
                if (t2 != l0) {
                    t2 = ((vader_struct_vader_front_resolver$FolderBucket_t*) l4)->f_name;
                    { vader_box_t __vret = vader_box_string(335u, t2); vader_gc_top = gc_frame.prev; return __vret; }
                }
            }
            l6 = (l6 + INT64_C(1));
            continue;
        }
        l6 = (l6 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

void* vader_front_resolver$module_index_by_name(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    int64_t l5, l6;
    vader_string_t l7 = 0;
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l4 };
    vader_string_t* gc_atom_roots[2] = { &l7, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 335u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 346u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections$MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 533u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l1 = (void*) _a3_obj;
    l2 = ((vader_struct_vader_front_resolver$LoadedProject_t*) l0)->f_modules;
    l3 = ((vader_struct_std_collections$MutableMap__string__vader_front_resolver_LoadedModule_t*) l2)->f_ekeys;
    l4 = ((vader_struct_std_collections$MutableMap__string__vader_front_resolver_LoadedModule_t*) l2)->f_evals;
    l5 = INT64_C(0);
    l6 = ((vader_struct_std_collections$MutableMap__string__vader_front_resolver_LoadedModule_t*) l2)->f_size;
    while ((l5 < l6)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
        t0 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l5];
        t1 = t0.payload.s;
        vader_array_t* _a5_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
        l2 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l5);
        l7 = ((vader_struct_vader_front_resolver$Module_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l2)->f_module)->f_module_name;
        std_collections$MutableMap$std_core$IndexSet$set_at__string__Any(l1, l7, vader_ref_box(l2));
        l5 = (l5 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_resolver$name_in_file_scope(vader_string_t l0, void* l1, void* l2, void* l3) {
    void* l4;
    void* l6;
    vader_box_t l5;
    int32_t l7;
    vader_string_t l8, l9;
    vader_box_t t0;
    l5 = std_collections$MutableMap$std_core$Index$at__string__Any(l2, l0);
    if (l5.tag == 0u) {
        return vader_box_obj(0u, NULL);
    }
    l4 = l5.payload.obj;
    if (((vader_struct_vader_core_symbol$Symbol_t*) l4)->f_kind != INT32_C(7)) {
        return vader_ref_box(l4);
    }
    l6 = ((vader_struct_vader_front_resolver$CollectedModule_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l1)->f_collected)->f_imports;
    l7 = ((vader_struct_vader_core_symbol$Symbol_t*) l4)->f_id;
    l5 = std_collections$MutableMap$std_core$Index$at__i32__Any(l6, l7);
    if (l5.tag == 0u) {
        return vader_box_obj(0u, NULL);
    }
    l4 = l5.payload.obj;
    l5 = ((vader_struct_vader_front_resolver$ImportInfo_t*) l4)->f_imported_name;
    if (l5.tag == 0u) {
        return vader_box_obj(0u, NULL);
    }
    l8 = l5.payload.s;
    l9 = ((vader_struct_vader_front_resolver$ImportInfo_t*) l4)->f_path;
    l5 = std_collections$MutableMap$std_core$Index$at__string__Any(l3, l9);
    if (l5.tag == 0u) {
        return vader_box_obj(0u, NULL);
    }
    l4 = l5.payload.obj;
    t0 = std_collections$MutableMap$std_core$Index$at__string__Any(((vader_struct_vader_front_resolver$CollectedModule_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l4)->f_collected)->f_symbols, l8);
    return t0;
}

static vader_box_t vader_front_resolver$name_in_folder(vader_string_t l0, vader_string_t l1) {
    vader_string_t l2 = 0;
    vader_string_t t0 = 0;
    vader_string_t* gc_atom_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = std_path$to_path(l0);
    l2 = std_path$filename(t0);
    if (l2 == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t0 = vader_front_resolver$join_path(l1, l2);
    if (!(t0 != l0)) {
        { vader_box_t __vret = vader_box_string(335u, l2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static bool vader_front_resolver$names_equal(vader_box_t l0, vader_box_t l1) {
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

static void* vader_front_resolver$new_import_target_table(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 7u, 338u);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 346u);
    l1 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
    l2 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__i32__Any_t* _a3_obj = (vader_struct_std_collections$MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__Any_t));
    vader_obj_header_init(_a3_obj, 459u);
    _a3_obj->f_ekeys = l0;
    _a3_obj->f_evals = l1;
    _a3_obj->f_index = l2;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l0 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(22u, 0u, 7u, 338u);
    l1 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(21u, 0u, 0u, 335u);
    l2 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(22u, 0u, 7u, 338u);
    l3 = (void*) _a6_arr;
    vader_struct_std_collections$MutableMap__i32__string_t* _a7_obj = (vader_struct_std_collections$MutableMap__i32__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__string_t));
    vader_obj_header_init(_a7_obj, 474u);
    _a7_obj->f_ekeys = l1;
    _a7_obj->f_evals = l2;
    _a7_obj->f_index = l3;
    _a7_obj->f_mask = INT64_C(0);
    _a7_obj->f_grow_at = INT64_C(0);
    _a7_obj->f_size = INT64_C(0);
    _a7_obj->f_tombs = INT64_C(0);
    l1 = (void*) _a7_obj;
    vader_array_t* _a8_arr = vader_array_new(22u, 0u, 7u, 338u);
    l2 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(19u, 0u, 12u, 333u);
    l3 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(22u, 0u, 7u, 338u);
    l4 = (void*) _a10_arr;
    vader_struct_std_collections$MutableMap__i32__bool_t* _a11_obj = (vader_struct_std_collections$MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__bool_t));
    vader_obj_header_init(_a11_obj, 462u);
    _a11_obj->f_ekeys = l2;
    _a11_obj->f_evals = l3;
    _a11_obj->f_index = l4;
    _a11_obj->f_mask = INT64_C(0);
    _a11_obj->f_grow_at = INT64_C(0);
    _a11_obj->f_size = INT64_C(0);
    _a11_obj->f_tombs = INT64_C(0);
    l2 = (void*) _a11_obj;
    vader_struct_vader_front_resolver$ImportTargetTable_t* _a12_obj = (vader_struct_vader_front_resolver$ImportTargetTable_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$ImportTargetTable_t));
    vader_obj_header_init(_a12_obj, 1092u);
    _a12_obj->f_symbol_targets = l0;
    _a12_obj->f_namespace_targets = l1;
    _a12_obj->f_missing = l2;
    t0 = (void*) _a12_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$new_scope(void* l0) {
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(34u, 1u, 13u, 559u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l0;
    t0 = (void*) _a0_arr;
    vader_struct_vader_front_resolver$Scope_t* _a1_obj = (vader_struct_vader_front_resolver$Scope_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$Scope_t));
    vader_obj_header_init(_a1_obj, 1104u);
    _a1_obj->f_frames = t0;
    t0 = (void*) _a1_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$new_subst(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 335u);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 346u);
    l1 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
    l2 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections$MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 533u);
    _a3_obj->f_ekeys = l0;
    _a3_obj->f_evals = l1;
    _a3_obj->f_index = l2;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_vader_front_resolver$Subst_t* _a4_obj = (vader_struct_vader_front_resolver$Subst_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$Subst_t));
    vader_obj_header_init(_a4_obj, 1108u);
    _a4_obj->f_entries = t0;
    t0 = (void*) _a4_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$next_clone_span(void* l0) {
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
    l1 = ((vader_struct_vader_front_resolver$StampCtx_t*) l0)->f_counter;
    t0 = ((vader_struct_vader_front_resolver$StampCtx_t*) l0)->f_counter;
    l2 = vader_chk_add(i32, t0, INT32_C(1));
    ((vader_struct_vader_front_resolver$StampCtx_t*) l0)->f_counter = l2;
    l3 = ((vader_struct_vader_front_resolver$StampCtx_t*) l0)->f_file;
    l2 = ((vader_struct_vader_front_resolver$StampCtx_t*) l0)->f_base_line;
    vader_struct_toolchain_span$Position_t* _a0_obj = (vader_struct_toolchain_span$Position_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Position_t));
    vader_obj_header_init(_a0_obj, 711u);
    _a0_obj->f_file = l3;
    _a0_obj->f_offset = INT64_C(0);
    _a0_obj->f_line = l2;
    _a0_obj->f_column = l1;
    l4 = (void*) _a0_obj;
    vader_struct_toolchain_span$Span_t* _a1_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
    vader_obj_header_init(_a1_obj, 712u);
    _a1_obj->f_start = l4;
    _a1_obj->f_end = l4;
    t1 = (void*) _a1_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_front_resolver$note_rebind(void* l0, vader_box_t l1) {
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
    if (l1.tag == 655u) {
        l2 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_idents;
        t0 = l1.payload.obj;
        l3 = toolchain_span$Span$std_core$Hash$hash(((vader_struct_toolchain_ast$IdentExpr_t*) t0)->f_span);
        l4 = std_collections$MutableMap$std_core$Index$at__u64__Any(l2, l3);
        if (l4.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        l2 = l4.payload.obj;
        l5 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_reassigned;
        l6 = ((vader_struct_vader_core_symbol$Symbol_t*) l2)->f_id;
        std_collections$add__i32(l5, l6);
        t1 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_loop_depth;
        if ((t1 > INT32_C(0))) {
            l5 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_rebind_log;
            l6 = ((vader_struct_vader_core_symbol$Symbol_t*) l2)->f_id;
            vader_array_push_i32((vader_array_t*) l5, l6);
        }
        t0 = l1.payload.obj;
        l7 = ((vader_struct_toolchain_ast$IdentExpr_t*) t0)->f_name;
        t2 = vader_front_resolver$declared_outside_lambda(l0, l7);
        if (t2) {
            l5 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_closure_rebound;
            l6 = ((vader_struct_vader_core_symbol$Symbol_t*) l2)->f_id;
            std_collections$add__i32(l5, l6);
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static uint8_t vader_front_resolver$origin_of_root(vader_string_t l0) {
    vader_string_t t0 = 0;
    bool t1;
    vader_string_t* gc_atom_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = vader_front_resolver$join_path(l0, 2596u);
    t1 = std_io$exists(t0);
    if (!(t1)) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 0; }
    }
    { vader_gc_top = gc_frame.prev; return (uint8_t) 1; }
}

static void* vader_front_resolver$parse_file(vader_string_t l0, vader_string_t l1, bool l2) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!(l2)) {
        t0 = vader_front_parser$parse_source(l0, l1);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_front_parser$parse_source_with_docs(l0, l1);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$parse_manifest(vader_string_t l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l19 = NULL;
    void* l21 = NULL;
    void* l23 = NULL;
    void* l24 = NULL;
    vader_box_t l5 = vader_box_null(), l12 = vader_box_null(), l13 = vader_box_null(), l14 = vader_box_null(), l15 = vader_box_null(), l16 = vader_box_null();
    vader_string_t l6 = 0;
    vader_string_t l9 = 0;
    vader_string_t l10 = 0;
    vader_string_t l11 = 0;
    vader_string_t l17 = 0;
    vader_string_t l18 = 0;
    vader_string_t l20 = 0;
    vader_string_t l22 = 0;
    vader_string_t l25 = 0;
    int64_t l7, l8;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    bool t2;
    vader_box_t* gc_roots[7] = { &l5, &l12, &l13, &l14, &l15, &l16, &t1 };
    void** gc_raw_roots[9] = { &l1, &l2, &l3, &l4, &l19, &l21, &l23, &l24, &t0 };
    vader_string_t* gc_atom_roots[10] = { &l0, &l6, &l9, &l10, &l11, &l17, &l18, &l20, &l22, &l25 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 7u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 10u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 335u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(141u, 0u, 13u, 1098u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(21u, 0u, 0u, 335u);
    l3 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(21u, 0u, 0u, 335u);
    l4 = (void*) _a3_arr;
    vader_struct_vader_front_resolver$Manifest_t* _a4_obj = (vader_struct_vader_front_resolver$Manifest_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$Manifest_t));
    vader_obj_header_init(_a4_obj, 1097u);
    _a4_obj->f_name = 0u;
    _a4_obj->f_version = 0u;
    _a4_obj->f_include_paths = l1;
    _a4_obj->f_entries = l2;
    _a4_obj->f_assets = l3;
    _a4_obj->f_problems = l4;
    l1 = (void*) _a4_obj;
    l5 = json$parse(l0);
    if (l5.tag == 451u) {
        l2 = ((vader_struct_vader_front_resolver$Manifest_t*) l1)->f_problems;
        t0 = l5.payload.obj;
        l6 = json$JsonError$std_core$Error$message(t0);
        l7 = vader_host_std_core$byte_len(l6);
        l3 = (void*) vader_buffer_new((size_t) (INT64_C(29) + l7));
        l7 = INT64_C(0);
        l7 = std_core$write_string_at(l3, l7, l6);
        l7 = std_core$write_string_at(l3, l7, 94u);
        t0 = l5.payload.obj;
        l8 = ((vader_struct_json$JsonError_t*) t0)->f_pos;
        l7 = std_core$write_int(l3, l7, l8);
        l6 = std_core$finish_buffer(l3, l7);
        vader_array_push_scalar((vader_array_t*) l2, vader_box_string(335u, l6));
        { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l5.tag == 454u)) {
        vader_array_push_scalar((vader_array_t*) ((vader_struct_vader_front_resolver$Manifest_t*) l1)->f_problems, vader_box_string(335u, 2222u));
        { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l5.payload.obj;
    l2 = ((vader_struct_json$JsonObject_t*) t0)->f_entries;
    l3 = ((vader_struct_std_collections$MutableMap__string__json_JsonArray___json_JsonBool___json_JsonNull___json_JsonNumber___json_JsonObject___json_JsonString_t*) l2)->f_ekeys;
    l4 = ((vader_struct_std_collections$MutableMap__string__json_JsonArray___json_JsonBool___json_JsonNull___json_JsonNumber___json_JsonObject___json_JsonString_t*) l2)->f_evals;
    l7 = INT64_C(0);
    l8 = ((vader_struct_std_collections$MutableMap__string__json_JsonArray___json_JsonBool___json_JsonNull___json_JsonNumber___json_JsonObject___json_JsonString_t*) l2)->f_size;
    while ((l7 < l8)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l7)
        t1 = vader_array_box_slots(_a5_slotarr->buf)[_a5_slotarr->offset + (size_t) l7];
        l6 = t1.payload.s;
        vader_array_t* _a6_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l7)
        t1 = vader_array_ref_load_box(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l7);
        l9 = l6;
        t0 = (void*) &vader_data_11;
        t2 = std_core$$array$Contains$contains__string(t0, l9);
        if (!(t2)) {
            t0 = (void*) &vader_data_11;
            l10 = std_string$join(t0, 1290u);
            l2 = ((vader_struct_vader_front_resolver$Manifest_t*) l1)->f_problems;
            l11 = concat_5(2828u, l9, 1327u, l10, 1038u);
            vader_array_push_scalar((vader_array_t*) l2, vader_box_string(335u, l11));
        }
        l7 = (l7 + INT64_C(1));
    }
    l2 = l5.payload.obj;
    l3 = ((vader_struct_vader_front_resolver$Manifest_t*) l1)->f_problems;
    l6 = vader_front_resolver$string_at(l2, 2366u, l3);
    ((vader_struct_vader_front_resolver$Manifest_t*) l1)->f_name = l6;
    l2 = l5.payload.obj;
    l3 = ((vader_struct_vader_front_resolver$Manifest_t*) l1)->f_problems;
    l6 = vader_front_resolver$string_at(l2, 3012u, l3);
    ((vader_struct_vader_front_resolver$Manifest_t*) l1)->f_version = l6;
    l2 = ((vader_struct_vader_front_resolver$Manifest_t*) l1)->f_include_paths;
    l3 = l5.payload.obj;
    l4 = ((vader_struct_vader_front_resolver$Manifest_t*) l1)->f_problems;
    l3 = vader_front_resolver$string_list(l3, 2159u, l4);
    vader_array_push_all((vader_array_t*) l2, (vader_array_t*) l3);
    t0 = l5.payload.obj;
    l12 = std_collections$MutableMap$std_core$Index$at__string__Any(((vader_struct_json$JsonObject_t*) t0)->f_entries, 1885u);
    if (l12.tag == 454u) {
        t0 = l12.payload.obj;
        l2 = ((vader_struct_json$JsonObject_t*) t0)->f_entries;
        l3 = ((vader_struct_std_collections$MutableMap__string__json_JsonArray___json_JsonBool___json_JsonNull___json_JsonNumber___json_JsonObject___json_JsonString_t*) l2)->f_ekeys;
        l4 = ((vader_struct_std_collections$MutableMap__string__json_JsonArray___json_JsonBool___json_JsonNull___json_JsonNumber___json_JsonObject___json_JsonString_t*) l2)->f_evals;
        l7 = INT64_C(0);
        l8 = ((vader_struct_std_collections$MutableMap__string__json_JsonArray___json_JsonBool___json_JsonNull___json_JsonNumber___json_JsonObject___json_JsonString_t*) l2)->f_size;
        while ((l7 < l8)) {
            vader_array_t* _a7_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l7)
            t1 = vader_array_box_slots(_a7_slotarr->buf)[_a7_slotarr->offset + (size_t) l7];
            l6 = t1.payload.s;
            vader_array_t* _a8_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l7)
            l13 = vader_array_ref_load_box(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l7);
            l9 = l6;
            l14 = l13;
            l15 = vader_front_resolver$entry_name_problem(l9);
            l16 = vader_front_resolver$entry_named(((vader_struct_vader_front_resolver$Manifest_t*) l1)->f_entries, l9);
            if (l15.tag == 0u) {
                if (l16.tag == 0u) {
                    if (l14.tag == 455u) {
                        l21 = ((vader_struct_vader_front_resolver$Manifest_t*) l1)->f_entries;
                        t0 = l14.payload.obj;
                        l22 = ((vader_struct_json$JsonString_t*) t0)->f_value;
                        vader_struct_vader_front_resolver$ManifestEntry_t* _a9_obj = (vader_struct_vader_front_resolver$ManifestEntry_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$ManifestEntry_t));
                        vader_obj_header_init(_a9_obj, 1098u);
                        _a9_obj->f_name = l9;
                        _a9_obj->f_path = l22;
                        l23 = (void*) _a9_obj;
                        vader_array_push_ref((vader_array_t*) l21, l23);
                    } else {
                        l24 = ((vader_struct_vader_front_resolver$Manifest_t*) l1)->f_problems;
                        l25 = concat_3(1887u, l9, 1182u);
                        vader_array_push_scalar((vader_array_t*) l24, vader_box_string(335u, l25));
                    }
                } else {
                    t0 = l16.payload.obj;
                    l17 = ((vader_struct_vader_front_resolver$ManifestEntry_t*) t0)->f_name;
                    l18 = concat_5(1886u, l17, 1060u, l9, 1038u);
                    l19 = ((vader_struct_vader_front_resolver$Manifest_t*) l1)->f_problems;
                    l20 = concat_2(l18, 177u);
                    vader_array_push_scalar((vader_array_t*) l19, vader_box_string(335u, l20));
                }
            } else {
                l2 = ((vader_struct_vader_front_resolver$Manifest_t*) l1)->f_problems;
                l10 = l15.payload.s;
                l11 = concat_4(1887u, l9, 1039u, l10);
                vader_array_push_scalar((vader_array_t*) l2, vader_box_string(335u, l11));
            }
            l7 = (l7 + INT64_C(1));
        }
    } else if (!(l12.tag == 0u)) {
        vader_array_push_scalar((vader_array_t*) ((vader_struct_vader_front_resolver$Manifest_t*) l1)->f_problems, vader_box_string(335u, 1391u));
    }
    l2 = l5.payload.obj;
    l3 = ((vader_struct_vader_front_resolver$Manifest_t*) l1)->f_problems;
    l2 = vader_front_resolver$string_list(l2, 1600u, l3);
    l7 = ((vader_array_t*) l2)->length;
    l8 = INT64_C(0);
    while ((l8 < l7)) {
        vader_array_t* _a10_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l8)
        t1 = vader_array_box_slots(_a10_slotarr->buf)[_a10_slotarr->offset + (size_t) l8];
        l6 = t1.payload.s;
        l5 = vader_front_resolver$asset_problem(l6);
        if (l5.tag == 0u) {
            vader_array_push_scalar((vader_array_t*) ((vader_struct_vader_front_resolver$Manifest_t*) l1)->f_assets, vader_box_string(335u, l6));
        } else {
            l3 = ((vader_struct_vader_front_resolver$Manifest_t*) l1)->f_problems;
            l9 = l5.payload.s;
            vader_array_push_scalar((vader_array_t*) l3, vader_box_string(335u, l9));
        }
        l8 = (l8 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$parse_module_files(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    int64_t l4, l5, l11, l12;
    vader_string_t l6 = 0;
    vader_string_t l7 = 0;
    bool l8;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[11] = { &l0, &l1, &l2, &l3, &l9, &l10, &l13, &l14, &l15, &l16, &l17 };
    vader_string_t* gc_atom_roots[2] = { &l6, &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 11u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(143u, 0u, 13u, 1106u);
    l2 = (void*) _a0_arr;
    l3 = l1;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        t0 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l5];
        l6 = t0.payload.s;
        l7 = vader_front_resolver$read_with_overlay(((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_overlay, l6);
        if (l7 == 0u) {
            l5 = (l5 + INT64_C(1));
            continue;
        }
        l8 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_keep_docs;
        l9 = vader_front_resolver$parse_file(l7, l6, l8);
        l10 = ((vader_struct_vader_front_parser$ParsedSource_t*) l9)->f_errors;
        l11 = ((vader_array_t*) l10)->length;
        l12 = INT64_C(0);
        while ((l12 < l11)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l10);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            l13 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l12);
            vader_array_push_ref((vader_array_t*) ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_diags, l13);
            l12 = (l12 + INT64_C(1));
        }
        l14 = vader_front_resolver$with_displayable_impls(((vader_struct_vader_front_parser$ParsedSource_t*) l9)->f_program);
        l15 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_node_factory;
        vader_front_parser$assign_program_ids(l14, l15);
        l16 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_node_factory;
        vader_struct_vader_front_resolver$SourceFile_t* _a3_obj = (vader_struct_vader_front_resolver$SourceFile_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$SourceFile_t));
        vader_obj_header_init(_a3_obj, 1106u);
        _a3_obj->f_path = l6;
        _a3_obj->f_content = l7;
        _a3_obj->f_program = l14;
        _a3_obj->f_id_factory = l16;
        l17 = (void*) _a3_obj;
        vader_array_push_ref((vader_array_t*) l2, l17);
        l5 = (l5 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$plain_root(vader_string_t l0, uint8_t l1) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_vader_front_resolver$IncludePath_t* _a0_obj = (vader_struct_vader_front_resolver$IncludePath_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$IncludePath_t));
    vader_obj_header_init(_a0_obj, 1093u);
    _a0_obj->f_dir = l0;
    _a0_obj->f_prefix = 0u;
    _a0_obj->f_merge = false;
    _a0_obj->f_origin = l1;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_front_resolver$pop(void* l0) {
    vader_box_t t0;
    t0 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_front_resolver$Scope_t*) l0)->f_frames);
    return;
}

static vader_box_t vader_front_resolver$posix_or_null(vader_box_t l0) {
    vader_box_t l1 = vader_box_null();
    vader_string_t t0 = 0;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[2] = { &t0, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 0u, gc_roots, NULL, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = l0;
    if (l1.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t0 = l1.payload.s;
    t1 = std_path$to_posix(t0);
    { vader_box_t __vret = vader_box_string(335u, t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_front_resolver$preresolve_imports(void* l0, void* l1, void* l2, void* l3, void* l4) {
    void* l5 = NULL;
    void* l8 = NULL;
    int64_t l6, l7, l9, l10;
    vader_box_t l11 = vader_box_null();
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[1] = { &l11 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l4, &l5, &l8, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l5 = l0;
    l6 = ((vader_array_t*) l5)->length;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l7)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
        l8 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) t0)->f_program)->f_decls;
        l9 = ((vader_array_t*) l8)->length;
        l10 = INT64_C(0);
        while ((l10 < l9)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l10)
            l11 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l10);
            if (l11.tag == 660u) {
                t0 = l11.payload.obj;
                t1 = ((vader_struct_toolchain_ast$ImportDecl_t*) t0)->f_path;
                vader_front_resolver$resolve_lazy(t1, l1, l2, l3, l4);
            }
            l10 = (l10 + INT64_C(1));
        }
        l7 = (l7 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_front_resolver$project_include_paths(vader_box_t l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l5 = NULL;
    void* l9 = NULL;
    int64_t l4, l6;
    vader_string_t l7 = 0;
    vader_string_t l11 = 0;
    uint8_t l8;
    vader_box_t l10 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[3] = { &l0, &l10, &t0 };
    void** gc_raw_roots[5] = { &l1, &l2, &l3, &l5, &l9 };
    vader_string_t* gc_atom_roots[3] = { &l7, &l11, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(139u, 0u, 13u, 1093u);
    l3 = (void*) _a0_arr;
    l4 = ((vader_array_t*) l2)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l3, (int64_t) l4);
    l3 = (void*) _a1_arr;
    l5 = l2;
    l4 = ((vader_array_t*) l5)->length;
    l6 = INT64_C(0);
    while ((l6 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t0 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l6];
        l7 = t0.payload.s;
        l8 = vader_front_resolver$origin_of_root(l7);
        l9 = vader_front_resolver$plain_root(l7, l8);
        vader_array_push_ref((vader_array_t*) l3, l9);
        l6 = (l6 + INT64_C(1));
    }
    l10 = vader_front_resolver$sidecar_root(2274u, 2596u);
    if (!(l10.tag == 0u)) {
        t1 = l10.payload.s;
        l5 = vader_front_resolver$plain_root(t1, (uint8_t) 1);
        vader_array_push_ref((vader_array_t*) l3, l5);
    }
    if (l0.tag == 335u) {
        t1 = l0.payload.s;
        l5 = vader_front_resolver$plain_root(t1, (uint8_t) 0);
        vader_array_push_ref((vader_array_t*) l3, l5);
        l5 = ((vader_struct_vader_front_resolver$Manifest_t*) l1)->f_include_paths;
        l4 = ((vader_array_t*) l5)->length;
        l6 = INT64_C(0);
        while ((l6 < l4)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            t0 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l6];
            l7 = t0.payload.s;
            t1 = l0.payload.s;
            l11 = vader_front_resolver$manifest_root(t1, l7, l10);
            l8 = vader_front_resolver$origin_of_root(l11);
            l9 = vader_front_resolver$plain_root(l11, l8);
            vader_array_push_ref((vader_array_t*) l3, l9);
            l6 = (l6 + INT64_C(1));
        }
    } else if (!(l0.tag == 0u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    if (l10.tag == 0u) {
        l8 = vader_front_resolver$origin_of_root(2274u);
        l5 = vader_front_resolver$plain_root(2274u, l8);
        vader_array_push_ref((vader_array_t*) l3, l5);
        { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$provided_names(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    int64_t l4, l5;
    vader_string_t l6 = 0;
    void* t0 = NULL;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 335u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(19u, 0u, 12u, 333u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__string__bool_t* _a3_obj = (vader_struct_std_collections$MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__bool_t));
    vader_obj_header_init(_a3_obj, 539u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections$MutableSet__string_t* _a4_obj = (vader_struct_std_collections$MutableSet__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__string_t));
    vader_obj_header_init(_a4_obj, 607u);
    _a4_obj->f_inner = t0;
    l1 = (void*) _a4_obj;
    l2 = l0;
    l4 = ((vader_array_t*) l2)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        t0 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l5);
        l6 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_name;
        std_collections$add__string(l1, l6);
        l5 = (l5 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_front_resolver$provides_body(vader_string_t l0) {
    if (l0 == 1954u) {
        return true;
    }
    return l0 == 2195u;
}

static void vader_front_resolver$push(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_front_resolver$Scope_t*) l0)->f_frames;
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 335u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 346u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections$MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 533u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l2 = (void*) _a3_obj;
    vader_array_push_ref((vader_array_t*) l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_front_resolver$read_manifest(vader_string_t l0) {
    vader_string_t l1 = 0;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    vader_box_t l6 = vader_box_null();
    bool t0;
    void* t1 = NULL;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[1] = { &l6 };
    void** gc_raw_roots[5] = { &l2, &l3, &l4, &l5, &t1 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l1, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_front_resolver$join_path(l0, 2856u);
    t0 = std_io$exists(l1);
    if (!(t0)) {
        vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 335u);
        l2 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_new(141u, 0u, 13u, 1098u);
        l3 = (void*) _a1_arr;
        vader_array_t* _a2_arr = vader_array_new(21u, 0u, 0u, 335u);
        l4 = (void*) _a2_arr;
        vader_array_t* _a3_arr = vader_array_new(21u, 0u, 0u, 335u);
        l5 = (void*) _a3_arr;
        vader_struct_vader_front_resolver$Manifest_t* _a4_obj = (vader_struct_vader_front_resolver$Manifest_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$Manifest_t));
        vader_obj_header_init(_a4_obj, 1097u);
        _a4_obj->f_name = 0u;
        _a4_obj->f_version = 0u;
        _a4_obj->f_include_paths = l2;
        _a4_obj->f_entries = l3;
        _a4_obj->f_assets = l4;
        _a4_obj->f_problems = l5;
        t1 = (void*) _a4_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = vader_front_resolver$try_read(l1);
    if (l6.tag == 0u) {
        t1 = vader_front_resolver$parse_manifest(0u);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = l6.payload.s;
    t1 = vader_front_resolver$parse_manifest(t2);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_front_resolver$read_with_overlay(void* l0, vader_string_t l1) {
    vader_box_t l2 = vader_box_null();
    vader_string_t t0 = 0;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = std_collections$MutableMap$std_core$Index$at__string__string(l0, l1);
    if (!(l2.tag == 0u)) {
        t0 = l2.payload.s;
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = std_io$read_file_string(l1, INT64_C(16777216));
    if (!(l2.tag == 335u)) {
        { vader_gc_top = gc_frame.prev; return 0u; }
    }
    t0 = l2.payload.s;
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$rebind_free_locals(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    int64_t l4, l5;
    int32_t l6;
    void* t0 = NULL;
    bool t1;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
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
    l2 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_declared_locals;
    l4 = ((vader_array_t*) l2)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        l6 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l5];
        t1 = std_collections$MutableSet$std_core$Contains$contains__i32(((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_reassigned, l6);
        if (!(t1)) {
            std_collections$add__i32(l1, l6);
        }
        l5 = (l5 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$registered_toolchain(void) {
    int32_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_global_12;
    if (t0 == INT32_C(2)) {
        t1 = vader_global_13;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_global_12;
    if (!(t0 == INT32_C(1))) {
        vader_global_12 = INT32_C(1);
        t1 = vader_front_resolver$registered_toolchain$singleton();
        vader_global_13 = t1;
        vader_global_12 = INT32_C(2);
        t1 = vader_global_13;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_unreachable("singleton `registered_toolchain` called while it initialises");
    vader_gc_top = gc_frame.prev;
}

static void* vader_front_resolver$registered_toolchain$singleton(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_front_resolver$ToolchainFolder_t* _a0_obj = (vader_struct_vader_front_resolver$ToolchainFolder_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$ToolchainFolder_t));
    vader_obj_header_init(_a0_obj, 1111u);
    _a0_obj->f_path = 0u;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_front_resolver$report_uncovered(void* l0, void* l1, void* l2, void* l3, void* l4) {
    void* l5 = NULL;
    void* l8 = NULL;
    void* l12 = NULL;
    void* l18 = NULL;
    void* l24 = NULL;
    int64_t l6, l7, l9, l10;
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
    bool t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l11, &l13, &l17, &t2 };
    void** gc_raw_roots[11] = { &l0, &l1, &l2, &l3, &l4, &l5, &l8, &l12, &l18, &l24, &t0 };
    vader_string_t* gc_atom_roots[8] = { &l14, &l15, &l16, &l19, &l20, &l21, &l22, &l23 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 11u, gc_roots, gc_raw_roots, 0u, NULL, 8u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l5 = l0;
    l6 = ((vader_array_t*) l5)->length;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
        l8 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) t0)->f_program)->f_decls;
        l9 = ((vader_array_t*) l8)->length;
        l10 = INT64_C(0);
        while ((l10 < l9)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            l11 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l10);
            if (l11.tag == 650u) {
                t0 = l11.payload.obj;
                l13 = vader_front_resolver$target_selectors(((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_decorators);
                if (l13.tag == 0u) {
                    l10 = (l10 + INT64_C(1));
                    continue;
                }
                l12 = l13.payload.obj;
                t1 = ((vader_struct_vader_front_resolver$TargetSelectors_t*) l12)->f_is_bare;
                if (t1) {
                    t0 = l11.payload.obj;
                    if (((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_body.tag == 0u) {
                        t0 = l11.payload.obj;
                        l14 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_name;
                        t2 = std_collections$MutableMap$std_core$Index$at__string__Any(l2, l14);
                        if (t2.tag == 0u) {
                            t0 = l11.payload.obj;
                            t1 = vader_front_resolver$is_host_bound(t0);
                            if (t1) {
                                l10 = (l10 + INT64_C(1));
                                continue;
                            }
                            t0 = l11.payload.obj;
                            l16 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_name;
                            l17 = std_collections$MutableMap$std_core$Index$at__string__string(l3, l16);
                            if (l17.tag == 0u) {
                                l15 = 317u;
                            } else {
                                l15 = l17.payload.s;
                            }
                            t0 = l11.payload.obj;
                            l18 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_name_span;
                            t0 = l11.payload.obj;
                            l19 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_name;
                            l20 = vader_support_target$display_target(l1);
                            l21 = concat_5(1038u, l19, 1109u, l20, 1061u);
                            l22 = concat_2(2232u, l15);
                            l23 = concat_2(l21, l22);
                            l24 = vader_support_diagnostics$resolver_error((uint8_t) 32, l18, l23);
                            vader_array_push_ref((vader_array_t*) l4, l24);
                        } else {
                            l10 = (l10 + INT64_C(1));
                            continue;
                        }
                    } else {
                        l10 = (l10 + INT64_C(1));
                        continue;
                    }
                } else {
                    l10 = (l10 + INT64_C(1));
                    continue;
                }
            }
            l10 = (l10 + INT64_C(1));
        }
        l7 = (l7 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$report_unreassigned_mutables(void* l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l17 = NULL;
    int64_t l2, l3, l7, l10, l11;
    vader_string_t l12 = 0;
    vader_string_t l13 = 0;
    vader_string_t l16 = 0;
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[11] = { &l0, &l1, &l4, &l5, &l6, &l8, &l9, &l14, &l15, &l17, &t1 };
    vader_string_t* gc_atom_roots[3] = { &l12, &l13, &l16 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 11u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_mutable_decls;
    l2 = ((vader_array_t*) l1)->length;
    l3 = INT64_C(0);
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        l5 = ((vader_struct_vader_front_resolver$MutableDecl_t*) l4)->f_syms;
        t0 = vader_front_resolver$has_reassignment(l0, l5);
        if (t0) {
            l3 = (l3 + INT64_C(1));
            continue;
        }
        vader_array_t* _a1_arr = vader_array_new(21u, 0u, 0u, 335u);
        l6 = (void*) _a1_arr;
        l7 = ((vader_array_t*) ((vader_struct_vader_front_resolver$MutableDecl_t*) l4)->f_syms)->length;
        vader_array_t* _a2_arr = vader_array_repeat((vader_array_t*) l6, (int64_t) l7);
        l8 = (void*) _a2_arr;
        l9 = ((vader_struct_vader_front_resolver$MutableDecl_t*) l4)->f_syms;
        l10 = ((vader_array_t*) l9)->length;
        l11 = INT64_C(0);
        while ((l11 < l10)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l9);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            t1 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l11);
            l12 = ((vader_struct_vader_core_symbol$Symbol_t*) t1)->f_name;
            vader_array_push_scalar((vader_array_t*) l8, vader_box_string(335u, l12));
            l11 = (l11 + INT64_C(1));
        }
        l13 = std_string$join(l8, 1290u);
        l14 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_diags;
        l15 = ((vader_struct_vader_front_resolver$MutableDecl_t*) l4)->f_span;
        l16 = concat_3(1038u, l13, 1038u);
        l17 = vader_support_diagnostics$warning((uint8_t) 11, l15, l16);
        vader_array_push_ref((vader_array_t*) l14, l17);
        l3 = (l3 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_front_resolver$required_methods(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l5 = NULL;
    int64_t l3, l4;
    vader_box_t l6 = vader_box_null();
    vader_box_t* gc_roots[1] = { &l6 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(45u, 0u, 13u, 650u);
    l1 = (void*) _a0_arr;
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l5 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        l6 = ((vader_struct_toolchain_ast$FnDecl_t*) l5)->f_body;
        if (l6.tag == 0u) {
            vader_array_push_ref((vader_array_t*) l1, l5);
        } else if (!(l6.tag == 624u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l4 = (l4 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_resolver$resolve_decl(vader_box_t l0, void* l1, void* l2, void* l3) {
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
    if (l0.tag == 693u) {
        t0 = l0.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0.tag == 650u)) {
        { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l0.payload.obj;
    l5 = vader_front_resolver$target_selectors(((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_decorators);
    if (l5.tag == 0u) {
        t0 = l0.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = l5.payload.obj;
    t1 = ((vader_struct_vader_front_resolver$TargetSelectors_t*) l4)->f_is_bare;
    if (!(t1)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t0 = l0.payload.obj;
    l6 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_name;
    l5 = std_collections$MutableMap$std_core$Index$at__string__Any(l2, l6);
    if (l5.tag == 0u) {
        t0 = l0.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = l5.payload.obj;
    t0 = l0.payload.obj;
    t2 = vader_front_resolver$graft_body(t0, l4);
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_front_resolver$resolve_import_redirect(void* l0, void* l1) {
    void* l2;
    int32_t l3;
    vader_box_t l4;
    if (((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_kind != INT32_C(7)) {
        return l0;
    }
    l2 = ((vader_struct_vader_front_resolver$ImportTargetTable_t*) l1)->f_symbol_targets;
    l3 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_id;
    l4 = std_collections$MutableMap$std_core$Index$at__i32__Any(l2, l3);
    if (l4.tag == 0u) {
        return l0;
    }
    l2 = l4.payload.obj;
    return ((vader_struct_vader_front_resolver$SymbolTarget_t*) l2)->f_symbol;
}

static vader_box_t vader_front_resolver$resolve_in(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[5] = { &l0, &l2, &l3, &l4, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_bases;
    l3 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_index;
    l4 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_overlay;
    l5 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_diags;
    t0 = vader_front_resolver$resolve_lazy(l1, l2, l3, l4, l5);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_resolver$resolve_lazy(vader_string_t l0, void* l1, void* l2, void* l3, void* l4) {
    vader_box_t l5 = vader_box_null(), l10 = vader_box_null(), l13 = vader_box_null();
    uint8_t l6;
    void* l7 = NULL;
    void* l12 = NULL;
    void* l14 = NULL;
    void* l16 = NULL;
    int64_t l8, l9;
    vader_string_t l11 = 0;
    vader_string_t l15 = 0;
    void* t0 = NULL;
    bool t1;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[3] = { &l5, &l10, &l13 };
    void** gc_raw_roots[9] = { &l1, &l2, &l3, &l4, &l7, &l12, &l14, &l16, &t0 };
    vader_string_t* gc_atom_roots[4] = { &l0, &l11, &l15, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l5 = std_collections$MutableMap$std_core$Index$at__string__Any(l2, l0);
    if (l5.tag == 1087u) {
        t0 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = vader_box_obj(0u, NULL);
    l6 = (uint8_t) 0;
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 335u);
    l7 = (void*) _a0_arr;
    l8 = INT64_C(0);
    l9 = ((vader_array_t*) l1)->length;
    while ((l8 < l9)) {
        if (!(l5.tag == 0u)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l8)
            t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l8);
            t1 = ((vader_struct_vader_front_resolver$IncludePath_t*) t0)->f_merge;
            if (!(t1)) {
                l8 = (l8 + INT64_C(1));
                continue;
            }
        }
        vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l8)
        t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l8);
        l10 = vader_front_resolver$rooted_candidate(t0, l0);
        if (l10.tag == 0u) {
            l8 = (l8 + INT64_C(1));
            continue;
        }
        l11 = l10.payload.s;
        t1 = std_io$is_dir(l11);
        if (t1) {
            l13 = vader_front_resolver$scan_folder(l11, l3, l4);
            if (l13.tag == 0u) {
                l8 = (l8 + INT64_C(1));
                continue;
            }
            l12 = l13.payload.obj;
            t2 = ((vader_struct_vader_front_resolver$FolderBucket_t*) l12)->f_name;
            if (t2 != l0) {
                l8 = (l8 + INT64_C(1));
                continue;
            }
            if (l5.tag == 0u) {
                l5 = vader_box_string(335u, l11);
                vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l8)
                t0 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l8);
                l6 = ((vader_struct_vader_front_resolver$IncludePath_t*) t0)->f_origin;
                l14 = ((vader_struct_vader_front_resolver$FolderBucket_t*) l12)->f_files;
                vader_array_push_all((vader_array_t*) l7, (vader_array_t*) l14);
                l8 = (l8 + INT64_C(1));
                continue;
            }
            l15 = l5.payload.s;
            if (l11 == l15) {
                l8 = (l8 + INT64_C(1));
                continue;
            }
            l16 = ((vader_struct_vader_front_resolver$FolderBucket_t*) l12)->f_files;
            vader_array_push_all((vader_array_t*) l7, (vader_array_t*) l16);
            l8 = (l8 + INT64_C(1));
            continue;
        }
        l8 = (l8 + INT64_C(1));
    }
    if (l5.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l11 = l5.payload.s;
    vader_struct_vader_front_resolver$DiscoveredModule_t* _a4_obj = (vader_struct_vader_front_resolver$DiscoveredModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$DiscoveredModule_t));
    vader_obj_header_init(_a4_obj, 1087u);
    _a4_obj->f_name = l0;
    _a4_obj->f_folder = l11;
    _a4_obj->f_files = l7;
    _a4_obj->f_origin = l6;
    l7 = (void*) _a4_obj;
    std_collections$MutableMap$std_core$IndexSet$set_at__string__Any(l2, l0, vader_ref_box(l7));
    { vader_box_t __vret = vader_ref_box(l7); vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_front_resolver$resolve_module(void* l0, vader_string_t l1, void* l2) {
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
    l3 = vader_front_resolver$collect_module_no_index(l0, l1, l2);
    l4 = ((vader_struct_toolchain_ast$Program_t*) l0)->f_file;
    l5 = vader_front_parser$new_node_id_factory();
    vader_struct_vader_front_resolver$SourceFile_t* _a0_obj = (vader_struct_vader_front_resolver$SourceFile_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$SourceFile_t));
    vader_obj_header_init(_a0_obj, 1106u);
    _a0_obj->f_path = l4;
    _a0_obj->f_content = 0u;
    _a0_obj->f_program = l0;
    _a0_obj->f_id_factory = l5;
    t0 = (void*) _a0_obj;
    vader_array_t* _a1_arr = vader_array_new(143u, 1u, 13u, 1106u);
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = t0;
    l5 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(21u, 0u, 0u, 335u);
    l6 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(28u, 0u, 0u, 346u);
    l7 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(22u, 0u, 7u, 338u);
    l8 = (void*) _a4_arr;
    vader_struct_std_collections$MutableMap__string__Any_t* _a5_obj = (vader_struct_std_collections$MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__Any_t));
    vader_obj_header_init(_a5_obj, 533u);
    _a5_obj->f_ekeys = l6;
    _a5_obj->f_evals = l7;
    _a5_obj->f_index = l8;
    _a5_obj->f_mask = INT64_C(0);
    _a5_obj->f_grow_at = INT64_C(0);
    _a5_obj->f_size = INT64_C(0);
    _a5_obj->f_tombs = INT64_C(0);
    l6 = (void*) _a5_obj;
    vader_array_t* _a6_arr = vader_array_new(21u, 0u, 0u, 335u);
    l7 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(28u, 0u, 0u, 346u);
    l8 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(22u, 0u, 7u, 338u);
    l9 = (void*) _a8_arr;
    vader_struct_std_collections$MutableMap__string__Any_t* _a9_obj = (vader_struct_std_collections$MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__Any_t));
    vader_obj_header_init(_a9_obj, 533u);
    _a9_obj->f_ekeys = l7;
    _a9_obj->f_evals = l8;
    _a9_obj->f_index = l9;
    _a9_obj->f_mask = INT64_C(0);
    _a9_obj->f_grow_at = INT64_C(0);
    _a9_obj->f_size = INT64_C(0);
    _a9_obj->f_tombs = INT64_C(0);
    l7 = (void*) _a9_obj;
    t0 = vader_front_resolver$resolve_module_files(l5, l1, l1, l2, l3, l6, l7);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_front_resolver$resolve_module_files(void* l0, vader_string_t l1, vader_string_t l2, void* l3, void* l4, void* l5, void* l6) {
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
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
    int64_t l11, l14, l28, l29;
    vader_string_t l16 = 0;
    vader_string_t l18 = 0;
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[25] = {
        &l0, &l3, &l4, &l5, &l6, &l7, &l8, &l9, &l10, &l12, &l13, &l15, &l17, &l19, &l20, &l21,
        &l22, &l23, &l24, &l25, &l26, &l27, &l30, &l31, &t2,
    };
    vader_string_t* gc_atom_roots[5] = { &l1, &l2, &l16, &l18, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 25u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l7 = vader_front_resolver$make_builtin_scope(l3);
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 335u);
    l8 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 346u);
    l9 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
    l10 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections$MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 533u);
    _a3_obj->f_ekeys = l8;
    _a3_obj->f_evals = l9;
    _a3_obj->f_index = l10;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l8 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(50u, 0u, 13u, 682u);
    l9 = (void*) _a4_arr;
    l11 = ((vader_array_t*) l0)->length;
    vader_array_t* _a5_arr = vader_array_repeat((vader_array_t*) l9, (int64_t) l11);
    l9 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(69u, 0u, 13u, 892u);
    l10 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(217u, 0u, 13u, 1400u);
    l12 = (void*) _a7_arr;
    l13 = l0;
    l11 = ((vader_array_t*) l13)->length;
    l14 = INT64_C(0);
    while ((l14 < l11)) {
        vader_array_t* _a8_slotarr = ((vader_array_t*) l13);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l14)
        l15 = vader_array_ref_load_obj(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l14);
        l16 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) l15)->f_program)->f_file;
        l17 = vader_front_resolver$file_imports(l4, l16);
        l18 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) l15)->f_program)->f_file;
        l19 = vader_front_resolver$file_root_scope(l7, l4, l17, l5, l6);
        l20 = ((vader_struct_vader_front_resolver$FileImports_t*) l17)->f_paths;
        l21 = ((vader_struct_vader_front_resolver$FileImports_t*) l17)->f_excludes;
        l22 = vader_front_resolver$wildcard_ambiguities(l5, l20, l21, l6);
        vader_struct_vader_front_resolver$FileScope_t* _a9_obj = (vader_struct_vader_front_resolver$FileScope_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$FileScope_t));
        vader_obj_header_init(_a9_obj, 1089u);
        _a9_obj->f_root = l19;
        _a9_obj->f_ambiguous = l22;
        l23 = (void*) _a9_obj;
        std_collections$MutableMap$std_core$IndexSet$set_at__string__Any(l8, l18, vader_ref_box(l23));
        l24 = ((vader_struct_vader_front_resolver$SourceFile_t*) l15)->f_program;
        vader_array_push_ref((vader_array_t*) l9, l24);
        l25 = ((vader_struct_vader_front_resolver$FileImports_t*) l17)->f_bindings;
        l26 = ((vader_struct_std_collections$MutableMap__string__vader_core_symbol_Symbol_t*) l25)->f_ekeys;
        l27 = ((vader_struct_std_collections$MutableMap__string__vader_core_symbol_Symbol_t*) l25)->f_evals;
        l28 = INT64_C(0);
        l29 = ((vader_struct_std_collections$MutableMap__string__vader_core_symbol_Symbol_t*) l25)->f_size;
        while ((l28 < l29)) {
            vader_array_t* _a10_slotarr = ((vader_array_t*) l26);
            VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l28)
            t0 = vader_array_box_slots(_a10_slotarr->buf)[_a10_slotarr->offset + (size_t) l28];
            t1 = t0.payload.s;
            vader_array_t* _a11_slotarr = ((vader_array_t*) l27);
            VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l28)
            l30 = vader_array_ref_load_obj(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l28);
            vader_array_push_ref((vader_array_t*) l10, l30);
            l28 = (l28 + INT64_C(1));
        }
        l31 = vader_front_resolver$binding_clashes(l4, l17);
        vader_array_push_all((vader_array_t*) l12, (vader_array_t*) l31);
        l14 = (l14 + INT64_C(1));
    }
    l7 = vader_front_resolver$resolve_module_programs(l9, l8, l1, l3);
    vader_array_push_all((vader_array_t*) ((vader_struct_vader_front_resolver$ResolvedFile_t*) l7)->f_diags, (vader_array_t*) l12);
    t2 = std_collections$values__string__vader_core_symbol_Symbol(((vader_struct_vader_front_resolver$CollectedModule_t*) l4)->f_symbols);
    l8 = vader_front_resolver$sort_by_name(t2);
    l9 = ((vader_struct_vader_front_resolver$ResolvedFile_t*) l7)->f_idents;
    l12 = ((vader_struct_vader_front_resolver$ResolvedFile_t*) l7)->f_immutable_locals;
    l13 = ((vader_struct_vader_front_resolver$ResolvedFile_t*) l7)->f_rebind_free;
    l15 = ((vader_struct_vader_front_resolver$ResolvedFile_t*) l7)->f_loop_rebinds;
    l17 = ((vader_struct_vader_front_resolver$ResolvedFile_t*) l7)->f_closure_rebound;
    l19 = ((vader_struct_vader_front_resolver$CollectedModule_t*) l4)->f_fn_overloads;
    l20 = vader_front_resolver$declaration_index(l4);
    vader_array_t* _a12_arr = vader_array_new(22u, 0u, 7u, 338u);
    l21 = (void*) _a12_arr;
    vader_array_t* _a13_arr = vader_array_new(28u, 0u, 0u, 346u);
    l22 = (void*) _a13_arr;
    vader_array_t* _a14_arr = vader_array_new(22u, 0u, 7u, 338u);
    l23 = (void*) _a14_arr;
    vader_struct_std_collections$MutableMap__i32__Any_t* _a15_obj = (vader_struct_std_collections$MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__Any_t));
    vader_obj_header_init(_a15_obj, 459u);
    _a15_obj->f_ekeys = l21;
    _a15_obj->f_evals = l22;
    _a15_obj->f_index = l23;
    _a15_obj->f_mask = INT64_C(0);
    _a15_obj->f_grow_at = INT64_C(0);
    _a15_obj->f_size = INT64_C(0);
    _a15_obj->f_tombs = INT64_C(0);
    l21 = (void*) _a15_obj;
    vader_array_t* _a16_arr = vader_array_new(22u, 0u, 7u, 338u);
    l22 = (void*) _a16_arr;
    vader_array_t* _a17_arr = vader_array_new(28u, 0u, 0u, 346u);
    l23 = (void*) _a17_arr;
    vader_array_t* _a18_arr = vader_array_new(22u, 0u, 7u, 338u);
    l24 = (void*) _a18_arr;
    vader_struct_std_collections$MutableMap__i32__Any_t* _a19_obj = (vader_struct_std_collections$MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__Any_t));
    vader_obj_header_init(_a19_obj, 459u);
    _a19_obj->f_ekeys = l22;
    _a19_obj->f_evals = l23;
    _a19_obj->f_index = l24;
    _a19_obj->f_mask = INT64_C(0);
    _a19_obj->f_grow_at = INT64_C(0);
    _a19_obj->f_size = INT64_C(0);
    _a19_obj->f_tombs = INT64_C(0);
    l22 = (void*) _a19_obj;
    vader_array_t* _a20_arr = vader_array_new(22u, 0u, 7u, 338u);
    l23 = (void*) _a20_arr;
    vader_array_t* _a21_arr = vader_array_new(28u, 0u, 0u, 346u);
    l24 = (void*) _a21_arr;
    vader_array_t* _a22_arr = vader_array_new(22u, 0u, 7u, 338u);
    l25 = (void*) _a22_arr;
    vader_struct_std_collections$MutableMap__i32__Any___t* _a23_obj = (vader_struct_std_collections$MutableMap__i32__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__Any___t));
    vader_obj_header_init(_a23_obj, 460u);
    _a23_obj->f_ekeys = l23;
    _a23_obj->f_evals = l24;
    _a23_obj->f_index = l25;
    _a23_obj->f_mask = INT64_C(0);
    _a23_obj->f_grow_at = INT64_C(0);
    _a23_obj->f_size = INT64_C(0);
    _a23_obj->f_tombs = INT64_C(0);
    l23 = (void*) _a23_obj;
    l24 = ((vader_struct_vader_front_resolver$ResolvedFile_t*) l7)->f_type_param_bounds;
    l7 = ((vader_struct_vader_front_resolver$ResolvedFile_t*) l7)->f_diags;
    vader_array_t* _a24_arr = vader_array_new(22u, 0u, 7u, 338u);
    l25 = (void*) _a24_arr;
    vader_array_t* _a25_arr = vader_array_new(21u, 0u, 0u, 335u);
    l26 = (void*) _a25_arr;
    vader_array_t* _a26_arr = vader_array_new(22u, 0u, 7u, 338u);
    l27 = (void*) _a26_arr;
    vader_struct_std_collections$MutableMap__i32__string_t* _a27_obj = (vader_struct_std_collections$MutableMap__i32__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__string_t));
    vader_obj_header_init(_a27_obj, 474u);
    _a27_obj->f_ekeys = l25;
    _a27_obj->f_evals = l26;
    _a27_obj->f_index = l27;
    _a27_obj->f_mask = INT64_C(0);
    _a27_obj->f_grow_at = INT64_C(0);
    _a27_obj->f_size = INT64_C(0);
    _a27_obj->f_tombs = INT64_C(0);
    l25 = (void*) _a27_obj;
    vader_array_t* _a28_arr = vader_array_new(22u, 0u, 7u, 338u);
    l26 = (void*) _a28_arr;
    vader_array_t* _a29_arr = vader_array_new(35u, 0u, 13u, 561u);
    l27 = (void*) _a29_arr;
    vader_array_t* _a30_arr = vader_array_new(22u, 0u, 7u, 338u);
    l30 = (void*) _a30_arr;
    vader_struct_std_collections$MutableMap__i32__std_collections_MutableMap_string__vader_core_types_AnyType___vader_core_types_ArrayType___vader_core_types_DistinctType___vader_core_types_EnumType___vader_core_types_FnType___vader_core_types_FreeCharType___vader_core_types_FreeFloatType___vader_core_types_FreeIntType___vader_core_types_InferVar___vader_core_types_NeverType___vader_core_types_PrimitiveType___vader_core_types_RangeType___vader_core_types_SelfType___vader_core_types_StructType___vader_core_types_TraitType___vader_core_types_TupleType___vader_core_types_TypeMetaType___vader_core_types_TypeParamType___vader_core_types_UnionType___vader_core_types_UnresolvedType__t* _a31_obj = (vader_struct_std_collections$MutableMap__i32__std_collections_MutableMap_string__vader_core_types_AnyType___vader_core_types_ArrayType___vader_core_types_DistinctType___vader_core_types_EnumType___vader_core_types_FnType___vader_core_types_FreeCharType___vader_core_types_FreeFloatType___vader_core_types_FreeIntType___vader_core_types_InferVar___vader_core_types_NeverType___vader_core_types_PrimitiveType___vader_core_types_RangeType___vader_core_types_SelfType___vader_core_types_StructType___vader_core_types_TraitType___vader_core_types_TupleType___vader_core_types_TypeMetaType___vader_core_types_TypeParamType___vader_core_types_UnionType___vader_core_types_UnresolvedType__t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__std_collections_MutableMap_string__vader_core_types_AnyType___vader_core_types_ArrayType___vader_core_types_DistinctType___vader_core_types_EnumType___vader_core_types_FnType___vader_core_types_FreeCharType___vader_core_types_FreeFloatType___vader_core_types_FreeIntType___vader_core_types_InferVar___vader_core_types_NeverType___vader_core_types_PrimitiveType___vader_core_types_RangeType___vader_core_types_SelfType___vader_core_types_StructType___vader_core_types_TraitType___vader_core_types_TupleType___vader_core_types_TypeMetaType___vader_core_types_TypeParamType___vader_core_types_UnionType___vader_core_types_UnresolvedType__t));
    vader_obj_header_init(_a31_obj, 469u);
    _a31_obj->f_ekeys = l26;
    _a31_obj->f_evals = l27;
    _a31_obj->f_index = l30;
    _a31_obj->f_mask = INT64_C(0);
    _a31_obj->f_grow_at = INT64_C(0);
    _a31_obj->f_size = INT64_C(0);
    _a31_obj->f_tombs = INT64_C(0);
    l26 = (void*) _a31_obj;
    vader_array_t* _a32_arr = vader_array_new(22u, 0u, 7u, 338u);
    l27 = (void*) _a32_arr;
    vader_array_t* _a33_arr = vader_array_new(32u, 0u, 13u, 539u);
    l30 = (void*) _a33_arr;
    vader_array_t* _a34_arr = vader_array_new(22u, 0u, 7u, 338u);
    l31 = (void*) _a34_arr;
    vader_struct_std_collections$MutableMap__i32__std_collections_MutableMap_string__bool__t* _a35_obj = (vader_struct_std_collections$MutableMap__i32__std_collections_MutableMap_string__bool__t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__std_collections_MutableMap_string__bool__t));
    vader_obj_header_init(_a35_obj, 468u);
    _a35_obj->f_ekeys = l27;
    _a35_obj->f_evals = l30;
    _a35_obj->f_index = l31;
    _a35_obj->f_mask = INT64_C(0);
    _a35_obj->f_grow_at = INT64_C(0);
    _a35_obj->f_size = INT64_C(0);
    _a35_obj->f_tombs = INT64_C(0);
    l27 = (void*) _a35_obj;
    vader_struct_vader_front_resolver$ResolvedModule_t* _a36_obj = (vader_struct_vader_front_resolver$ResolvedModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$ResolvedModule_t));
    vader_obj_header_init(_a36_obj, 1103u);
    _a36_obj->f_path = l1;
    _a36_obj->f_display_path = l2;
    _a36_obj->f_symbols = l8;
    _a36_obj->f_import_bindings = l10;
    _a36_obj->f_idents = l9;
    _a36_obj->f_immutable_locals = l12;
    _a36_obj->f_rebind_free = l13;
    _a36_obj->f_loop_rebinds = l15;
    _a36_obj->f_closure_rebound = l17;
    _a36_obj->f_fn_overloads = l19;
    _a36_obj->f_declarations = l20;
    _a36_obj->f_imports_to = l21;
    _a36_obj->f_alias_types = l22;
    _a36_obj->f_alias_params = l23;
    _a36_obj->f_type_param_bounds = l24;
    _a36_obj->f_diags = l7;
    _a36_obj->f_deprecated_messages = l25;
    _a36_obj->f_namespace_member_types = l26;
    _a36_obj->f_namespace_private_members = l27;
    t2 = (void*) _a36_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$resolve_module_programs(void* l0, void* l1, vader_string_t l2, void* l3) {
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
    int64_t l18, l19, l23, l24;
    vader_string_t l20 = 0;
    vader_string_t l22 = 0;
    vader_box_t l21 = vader_box_null(), l25 = vader_box_null();
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[2] = { &l21, &l25 };
    void** gc_raw_roots[18] = {
        &l0, &l1, &l3, &l4, &l5, &l6, &l7, &l8, &l9, &l10, &l11, &l12, &l13, &l14, &l15, &l16, &l17,
        &t0,
    };
    vader_string_t* gc_atom_roots[4] = { &l2, &l20, &l22, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 18u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(27u, 0u, 4u, 343u);
    l4 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 346u);
    l5 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
    l6 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__u64__Any_t* _a3_obj = (vader_struct_std_collections$MutableMap__u64__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__u64__Any_t));
    vader_obj_header_init(_a3_obj, 589u);
    _a3_obj->f_ekeys = l4;
    _a3_obj->f_evals = l5;
    _a3_obj->f_index = l6;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l4 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(22u, 0u, 7u, 338u);
    l5 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(24u, 0u, 1u, 340u);
    l6 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(22u, 0u, 7u, 338u);
    l7 = (void*) _a6_arr;
    vader_struct_std_collections$MutableMap__i32__vader_front_resolver_ConstLocal_t* _a7_obj = (vader_struct_std_collections$MutableMap__i32__vader_front_resolver_ConstLocal_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__vader_front_resolver_ConstLocal_t));
    vader_obj_header_init(_a7_obj, 491u);
    _a7_obj->f_ekeys = l5;
    _a7_obj->f_evals = l6;
    _a7_obj->f_index = l7;
    _a7_obj->f_mask = INT64_C(0);
    _a7_obj->f_grow_at = INT64_C(0);
    _a7_obj->f_size = INT64_C(0);
    _a7_obj->f_tombs = INT64_C(0);
    l5 = (void*) _a7_obj;
    vader_array_t* _a8_arr = vader_array_new(22u, 0u, 7u, 338u);
    l6 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(28u, 0u, 0u, 346u);
    l7 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(22u, 0u, 7u, 338u);
    l8 = (void*) _a10_arr;
    vader_struct_std_collections$MutableMap__i32__Any_t* _a11_obj = (vader_struct_std_collections$MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__Any_t));
    vader_obj_header_init(_a11_obj, 459u);
    _a11_obj->f_ekeys = l6;
    _a11_obj->f_evals = l7;
    _a11_obj->f_index = l8;
    _a11_obj->f_mask = INT64_C(0);
    _a11_obj->f_grow_at = INT64_C(0);
    _a11_obj->f_size = INT64_C(0);
    _a11_obj->f_tombs = INT64_C(0);
    l6 = (void*) _a11_obj;
    vader_array_t* _a12_arr = vader_array_new(142u, 0u, 13u, 1100u);
    l7 = (void*) _a12_arr;
    vader_array_t* _a13_arr = vader_array_new(22u, 0u, 7u, 338u);
    l8 = (void*) _a13_arr;
    vader_array_t* _a14_arr = vader_array_new(19u, 0u, 12u, 333u);
    l9 = (void*) _a14_arr;
    vader_array_t* _a15_arr = vader_array_new(22u, 0u, 7u, 338u);
    l10 = (void*) _a15_arr;
    vader_struct_std_collections$MutableMap__i32__bool_t* _a16_obj = (vader_struct_std_collections$MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__bool_t));
    vader_obj_header_init(_a16_obj, 462u);
    _a16_obj->f_ekeys = l8;
    _a16_obj->f_evals = l9;
    _a16_obj->f_index = l10;
    _a16_obj->f_mask = INT64_C(0);
    _a16_obj->f_grow_at = INT64_C(0);
    _a16_obj->f_size = INT64_C(0);
    _a16_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a16_obj;
    vader_struct_std_collections$MutableSet__i32_t* _a17_obj = (vader_struct_std_collections$MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__i32_t));
    vader_obj_header_init(_a17_obj, 605u);
    _a17_obj->f_inner = t0;
    l8 = (void*) _a17_obj;
    vader_array_t* _a18_arr = vader_array_new(22u, 0u, 7u, 338u);
    l9 = (void*) _a18_arr;
    vader_array_t* _a19_arr = vader_array_new(22u, 0u, 7u, 338u);
    l10 = (void*) _a19_arr;
    vader_array_t* _a20_arr = vader_array_new(27u, 0u, 4u, 343u);
    l11 = (void*) _a20_arr;
    vader_array_t* _a21_arr = vader_array_new(28u, 0u, 0u, 346u);
    l12 = (void*) _a21_arr;
    vader_array_t* _a22_arr = vader_array_new(22u, 0u, 7u, 338u);
    l13 = (void*) _a22_arr;
    vader_struct_std_collections$MutableMap__u64__std_collections_MutableSet_Any__t* _a23_obj = (vader_struct_std_collections$MutableMap__u64__std_collections_MutableSet_Any__t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__u64__std_collections_MutableSet_Any__t));
    vader_obj_header_init(_a23_obj, 593u);
    _a23_obj->f_ekeys = l11;
    _a23_obj->f_evals = l12;
    _a23_obj->f_index = l13;
    _a23_obj->f_mask = INT64_C(0);
    _a23_obj->f_grow_at = INT64_C(0);
    _a23_obj->f_size = INT64_C(0);
    _a23_obj->f_tombs = INT64_C(0);
    l11 = (void*) _a23_obj;
    vader_array_t* _a24_arr = vader_array_new(22u, 0u, 7u, 338u);
    l12 = (void*) _a24_arr;
    vader_array_t* _a25_arr = vader_array_new(19u, 0u, 12u, 333u);
    l13 = (void*) _a25_arr;
    vader_array_t* _a26_arr = vader_array_new(22u, 0u, 7u, 338u);
    l14 = (void*) _a26_arr;
    vader_struct_std_collections$MutableMap__i32__bool_t* _a27_obj = (vader_struct_std_collections$MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__bool_t));
    vader_obj_header_init(_a27_obj, 462u);
    _a27_obj->f_ekeys = l12;
    _a27_obj->f_evals = l13;
    _a27_obj->f_index = l14;
    _a27_obj->f_mask = INT64_C(0);
    _a27_obj->f_grow_at = INT64_C(0);
    _a27_obj->f_size = INT64_C(0);
    _a27_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a27_obj;
    vader_struct_std_collections$MutableSet__i32_t* _a28_obj = (vader_struct_std_collections$MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__i32_t));
    vader_obj_header_init(_a28_obj, 605u);
    _a28_obj->f_inner = t0;
    l12 = (void*) _a28_obj;
    vader_array_t* _a29_arr = vader_array_new(217u, 0u, 13u, 1400u);
    l13 = (void*) _a29_arr;
    vader_array_t* _a30_arr = vader_array_new(21u, 0u, 0u, 335u);
    l14 = (void*) _a30_arr;
    vader_array_t* _a31_arr = vader_array_new(28u, 0u, 0u, 346u);
    l15 = (void*) _a31_arr;
    vader_array_t* _a32_arr = vader_array_new(22u, 0u, 7u, 338u);
    l16 = (void*) _a32_arr;
    vader_struct_std_collections$MutableMap__string__Any_t* _a33_obj = (vader_struct_std_collections$MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__Any_t));
    vader_obj_header_init(_a33_obj, 533u);
    _a33_obj->f_ekeys = l14;
    _a33_obj->f_evals = l15;
    _a33_obj->f_index = l16;
    _a33_obj->f_mask = INT64_C(0);
    _a33_obj->f_grow_at = INT64_C(0);
    _a33_obj->f_size = INT64_C(0);
    _a33_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a33_obj;
    l14 = vader_front_resolver$new_scope(t0);
    vader_array_t* _a34_arr = vader_array_new(21u, 0u, 0u, 335u);
    l15 = (void*) _a34_arr;
    vader_array_t* _a35_arr = vader_array_new(2u, 0u, 13u, 21u);
    l16 = (void*) _a35_arr;
    vader_array_t* _a36_arr = vader_array_new(22u, 0u, 7u, 338u);
    l17 = (void*) _a36_arr;
    vader_struct_std_collections$MutableMap__string__string___t* _a37_obj = (vader_struct_std_collections$MutableMap__string__string___t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__string___t));
    vader_obj_header_init(_a37_obj, 554u);
    _a37_obj->f_ekeys = l15;
    _a37_obj->f_evals = l16;
    _a37_obj->f_index = l17;
    _a37_obj->f_mask = INT64_C(0);
    _a37_obj->f_grow_at = INT64_C(0);
    _a37_obj->f_size = INT64_C(0);
    _a37_obj->f_tombs = INT64_C(0);
    l15 = (void*) _a37_obj;
    vader_struct_vader_front_resolver$ResolveState_t* _a38_obj = (vader_struct_vader_front_resolver$ResolveState_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$ResolveState_t));
    vader_obj_header_init(_a38_obj, 1101u);
    _a38_obj->f_idents = l4;
    _a38_obj->f_immutable_locals = l5;
    _a38_obj->f_type_param_bounds = l6;
    _a38_obj->f_mutable_decls = l7;
    _a38_obj->f_reassigned = l8;
    _a38_obj->f_declared_locals = l9;
    _a38_obj->f_rebind_log = l10;
    _a38_obj->f_loop_depth = INT32_C(0);
    _a38_obj->f_loop_rebinds = l11;
    _a38_obj->f_lambda_frame = vader_box_obj(0u, NULL);
    _a38_obj->f_closure_rebound = l12;
    _a38_obj->f_diags = l13;
    _a38_obj->f_scope = l14;
    _a38_obj->f_module_path = l2;
    _a38_obj->f_factory = l3;
    _a38_obj->f_ambiguous = l15;
    _a38_obj->f_file_scopes = l1;
    l4 = (void*) _a38_obj;
    l5 = l0;
    l18 = ((vader_array_t*) l5)->length;
    l19 = INT64_C(0);
    for (;;) {
        if ((l19 < l18)) {
            vader_array_t* _a39_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a39_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a39_slotarr, l19)
            l6 = vader_array_ref_load_obj(_a39_slotarr->buf, _a39_slotarr->offset + (size_t) l19);
            l20 = ((vader_struct_toolchain_ast$Program_t*) l6)->f_file;
            l21 = std_collections$MutableMap$std_core$Index$at__string__Any(l1, l20);
            if (l21.tag == 0u) {
                l22 = ((vader_struct_toolchain_ast$Program_t*) l6)->f_file;
                t1 = concat_3(2517u, l22, 1038u);
                vader_host_std_abort$panic(t1);
                vader_unreachable("a no-return call returned");
            } else {
                l7 = l21.payload.obj;
                vader_front_resolver$enter_file(l4, l7);
                l8 = ((vader_struct_toolchain_ast$Program_t*) l6)->f_decls;
                l23 = ((vader_array_t*) l8)->length;
                l24 = INT64_C(0);
                while ((l24 < l23)) {
                    vader_array_t* _a40_slotarr = ((vader_array_t*) l8);
                    VADER_ARRAY_RESOLVE_BUF(_a40_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a40_slotarr, l24)
                    l25 = vader_array_ref_load_box(_a40_slotarr->buf, _a40_slotarr->offset + (size_t) l24);
                    vader_front_resolver$walk_decl(l4, l25);
                    l24 = (l24 + INT64_C(1));
                }
                l19 = (l19 + INT64_C(1));
                continue;
            }
        }
        break;
    }
    vader_front_resolver$report_unreassigned_mutables(l4);
    l5 = ((vader_struct_vader_front_resolver$ResolveState_t*) l4)->f_idents;
    l6 = ((vader_struct_vader_front_resolver$ResolveState_t*) l4)->f_immutable_locals;
    l7 = vader_front_resolver$rebind_free_locals(l4);
    l8 = ((vader_struct_vader_front_resolver$ResolveState_t*) l4)->f_loop_rebinds;
    l9 = ((vader_struct_vader_front_resolver$ResolveState_t*) l4)->f_closure_rebound;
    l10 = ((vader_struct_vader_front_resolver$ResolveState_t*) l4)->f_type_param_bounds;
    l4 = ((vader_struct_vader_front_resolver$ResolveState_t*) l4)->f_diags;
    vader_struct_vader_front_resolver$ResolvedFile_t* _a41_obj = (vader_struct_vader_front_resolver$ResolvedFile_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$ResolvedFile_t));
    vader_obj_header_init(_a41_obj, 1102u);
    _a41_obj->f_idents = l5;
    _a41_obj->f_immutable_locals = l6;
    _a41_obj->f_rebind_free = l7;
    _a41_obj->f_loop_rebinds = l8;
    _a41_obj->f_closure_rebound = l9;
    _a41_obj->f_type_param_bounds = l10;
    _a41_obj->f_diags = l4;
    t0 = (void*) _a41_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_resolver$rooted_candidate(void* l0, vader_string_t l1) {
    vader_string_t l2 = 0;
    vader_string_t l3 = 0;
    vader_string_t t0 = 0;
    vader_string_t t1 = 0;
    bool t2;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[5] = { &l1, &l2, &l3, &t0, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_front_resolver$IncludePath_t*) l0)->f_prefix;
    if (t0 == 0u) {
        t0 = ((vader_struct_vader_front_resolver$IncludePath_t*) l0)->f_dir;
        t1 = vader_front_resolver$join_path(t0, l1);
        { vader_box_t __vret = vader_box_string(335u, t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_vader_front_resolver$IncludePath_t*) l0)->f_prefix;
    if (l1 == l2) {
        t0 = ((vader_struct_vader_front_resolver$IncludePath_t*) l0)->f_dir;
        { vader_box_t __vret = vader_box_string(335u, t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_front_resolver$IncludePath_t*) l0)->f_prefix;
    l2 = concat_2(t0, 438u);
    t2 = std_string$starts_with(l1, l2);
    if (!(t2)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = ((vader_struct_vader_front_resolver$IncludePath_t*) l0)->f_dir;
    t0 = ((vader_struct_vader_front_resolver$IncludePath_t*) l0)->f_prefix;
    l3 = concat_2(t0, 438u);
    l3 = std_string$trim_prefix(l1, l3);
    t0 = vader_front_resolver$join_path(l2, l3);
    { vader_box_t __vret = vader_box_string(335u, t0); vader_gc_top = gc_frame.prev; return __vret; }
}

void vader_front_resolver$run_orphan_rule_check_for_module(void* l0, vader_string_t l1, void* l2, void* l3, void* l4) {
    void* l5 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    int64_t l6, l7, l13, l14;
    vader_string_t l10 = 0;
    vader_box_t l15 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l15 };
    void** gc_raw_roots[12] = { &l0, &l2, &l3, &l4, &l5, &l8, &l9, &l11, &l12, &l16, &l17, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l10 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l5 = ((vader_struct_vader_front_resolver$Module_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l0)->f_module)->f_files;
    l6 = ((vader_array_t*) l5)->length;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l8 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
        l9 = ((vader_struct_vader_front_resolver$LoadedModule_t*) l0)->f_collected;
        l10 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) l8)->f_program)->f_file;
        t0 = vader_front_resolver$file_imports(l9, l10);
        l11 = ((vader_struct_vader_front_resolver$FileImports_t*) t0)->f_bindings;
        l12 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) l8)->f_program)->f_decls;
        l13 = ((vader_array_t*) l12)->length;
        l14 = INT64_C(0);
        while ((l14 < l13)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l12);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            l15 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l14);
            if (l15.tag == 659u) {
                l16 = l15.payload.obj;
                l17 = ((vader_struct_vader_front_resolver$CollectedModule_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l0)->f_collected)->f_symbols;
                vader_front_resolver$check_orphan_rule(l16, l1, l17, l11, l2, l3, l4);
            }
            l14 = (l14 + INT64_C(1));
        }
        l7 = (l7 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_front_resolver$scan_folder(vader_string_t l0, void* l1, void* l2) {
    vader_box_t l3 = vader_box_null();
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l13 = NULL;
    void* l16 = NULL;
    void* l20 = NULL;
    int64_t l8, l9;
    vader_string_t l10 = 0;
    vader_string_t l11 = 0;
    vader_string_t l12 = 0;
    vader_string_t l14 = 0;
    vader_string_t l15 = 0;
    vader_string_t l17 = 0;
    vader_string_t l18 = 0;
    vader_string_t l19 = 0;
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    bool t2;
    int64_t t3;
    void* t4 = NULL;
    vader_box_t* gc_roots[2] = { &l3, &t0 };
    void** gc_raw_roots[10] = { &l1, &l2, &l4, &l5, &l6, &l7, &l13, &l16, &l20, &t4 };
    vader_string_t* gc_atom_roots[10] = {
        &l0, &l10, &l11, &l12, &l14, &l15, &l17, &l18, &l19, &t1,
    };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 10u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = std_io$read_dir(l0);
    if (l3.tag == 21u) {
        l4 = l3.payload.obj;
    } else {
        if (!(l3.tag == 616u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 335u);
        l4 = (void*) _a0_arr;
    }
    l5 = l1;
    l6 = ((vader_struct_std_collections$MutableMap__string__string_t*) l5)->f_ekeys;
    l7 = ((vader_struct_std_collections$MutableMap__string__string_t*) l5)->f_evals;
    l8 = INT64_C(0);
    l9 = ((vader_struct_std_collections$MutableMap__string__string_t*) l5)->f_size;
    while ((l8 < l9)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l8)
        t0 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l8];
        l10 = t0.payload.s;
        vader_array_t* _a2_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l8)
        t0 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l8];
        t1 = t0.payload.s;
        l3 = vader_front_resolver$name_in_folder(l10, l0);
        if (!(l3.tag == 0u)) {
            l11 = l3.payload.s;
            t2 = std_core$$array$Contains$contains__string(l4, l11);
            if (!(t2)) {
                vader_array_push_scalar((vader_array_t*) l4, vader_box_string(335u, l11));
            }
        }
        l8 = (l8 + INT64_C(1));
    }
    t3 = ((vader_array_t*) l4)->length;
    if (t3 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l4 = vader_front_resolver$source_files_in(l0, l4);
    t3 = ((vader_array_t*) l4)->length;
    if (t3 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l5 = toolchain_span$empty_span();
    vader_array_t* _a3_arr = vader_array_new(21u, 0u, 0u, 335u);
    l6 = (void*) _a3_arr;
    vader_struct_vader_front_resolver$FolderBucket_t* _a4_obj = (vader_struct_vader_front_resolver$FolderBucket_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$FolderBucket_t));
    vader_obj_header_init(_a4_obj, 1090u);
    _a4_obj->f_name = 0u;
    _a4_obj->f_first_decl_span = l5;
    _a4_obj->f_files = l6;
    l5 = (void*) _a4_obj;
    l8 = ((vader_array_t*) l4)->length;
    l9 = INT64_C(0);
    while ((l9 < l8)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l9)
        t0 = vader_array_box_slots(_a5_slotarr->buf)[_a5_slotarr->offset + (size_t) l9];
        l10 = t0.payload.s;
        l11 = vader_front_resolver$read_with_overlay(l1, l10);
        if (l11 == 0u) {
            l9 = (l9 + INT64_C(1));
            continue;
        }
        vader_array_push_scalar((vader_array_t*) ((vader_struct_vader_front_resolver$FolderBucket_t*) l5)->f_files, vader_box_string(335u, l10));
        l3 = vader_front_parser$parse_module_header(l11, l10);
        if (l3.tag == 0u) {
            l6 = toolchain_span$file_head_span(l10);
            l7 = vader_support_diagnostics$resolver_error((uint8_t) 15, l6, 0u);
            vader_array_push_ref((vader_array_t*) l2, l7);
        } else {
            if (!(l3.tag == 1081u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            t1 = ((vader_struct_vader_front_resolver$FolderBucket_t*) l5)->f_name;
            if (t1 == 0u) {
                t4 = l3.payload.obj;
                l12 = ((vader_struct_vader_front_parser$ModuleHeader_t*) t4)->f_name;
                ((vader_struct_vader_front_resolver$FolderBucket_t*) l5)->f_name = l12;
                t4 = l3.payload.obj;
                l13 = ((vader_struct_vader_front_parser$ModuleHeader_t*) t4)->f_name_span;
                ((vader_struct_vader_front_resolver$FolderBucket_t*) l5)->f_first_decl_span = l13;
                VADER_WRITE_BARRIER((vader_struct_vader_front_resolver$FolderBucket_t*) l5);
            } else {
                t4 = l3.payload.obj;
                l14 = ((vader_struct_vader_front_parser$ModuleHeader_t*) t4)->f_name;
                l15 = ((vader_struct_vader_front_resolver$FolderBucket_t*) l5)->f_name;
                if (l14 != l15) {
                    t4 = l3.payload.obj;
                    l16 = ((vader_struct_vader_front_parser$ModuleHeader_t*) t4)->f_name_span;
                    t4 = l3.payload.obj;
                    l17 = ((vader_struct_vader_front_parser$ModuleHeader_t*) t4)->f_name;
                    l18 = ((vader_struct_vader_front_resolver$FolderBucket_t*) l5)->f_name;
                    l19 = concat_5(1038u, l17, 1079u, l18, 1264u);
                    l20 = vader_support_diagnostics$resolver_error((uint8_t) 16, l16, l19);
                    vader_array_push_ref((vader_array_t*) l2, l20);
                }
            }
        }
        l9 = (l9 + INT64_C(1));
    }
    { vader_box_t __vret = vader_ref_box(l5); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$search_roots(vader_string_t l0, void* l1, vader_box_t l2, void* l3, void* l4) {
    void* l5 = NULL;
    void* l8 = NULL;
    void* l11 = NULL;
    vader_string_t l6 = 0;
    vader_string_t l9 = 0;
    vader_string_t l10 = 0;
    vader_box_t l7 = vader_box_null();
    vader_string_t t0 = 0;
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l2, &l7 };
    void** gc_raw_roots[7] = { &l1, &l3, &l4, &l5, &l8, &l11, &t1 };
    vader_string_t* gc_atom_roots[5] = { &l0, &l6, &l9, &l10, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l5 = vader_front_resolver$manifest_at(l2);
    l5 = vader_front_resolver$project_include_paths(l2, l5, l1);
    l6 = vader_front_resolver$generated_root_for(l2);
    t0 = vader_front_resolver$entry_folder_of(l0);
    l7 = vader_front_resolver$seed_entry(t0, l3, l4);
    if (!(l7.tag == 0u)) {
        l8 = l7.payload.obj;
        t1 = l7.payload.obj;
        l9 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) t1)->f_name;
        t1 = l7.payload.obj;
        l10 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) t1)->f_folder;
        t1 = vader_front_resolver$entry_namespace(l9, l10);
        l11 = vader_front_resolver$include_paths(t1, l5, l6);
        vader_struct_vader_front_resolver$SearchRoots_t* _a0_obj = (vader_struct_vader_front_resolver$SearchRoots_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$SearchRoots_t));
        vader_obj_header_init(_a0_obj, 1105u);
        _a0_obj->f_entry = vader_ref_box(l8);
        _a0_obj->f_paths = l11;
        t1 = (void*) _a0_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_front_resolver$SearchRoots_t* _a1_obj = (vader_struct_vader_front_resolver$SearchRoots_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$SearchRoots_t));
    vader_obj_header_init(_a1_obj, 1105u);
    _a1_obj->f_entry = vader_box_obj(0u, NULL);
    _a1_obj->f_paths = l5;
    t1 = (void*) _a1_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_resolver$seed_entry(vader_string_t l0, void* l1, void* l2) {
    void* l3 = NULL;
    vader_box_t l4 = vader_box_null();
    vader_string_t l5 = 0;
    vader_string_t t0 = 0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[4] = { &l1, &l2, &l3, &t1 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l5, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = vader_front_resolver$scan_folder(l0, l1, l2);
    if (l4.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l3 = l4.payload.obj;
    t0 = ((vader_struct_vader_front_resolver$FolderBucket_t*) l3)->f_name;
    if (!(t0 == 0u)) {
        l5 = ((vader_struct_vader_front_resolver$FolderBucket_t*) l3)->f_name;
        l3 = ((vader_struct_vader_front_resolver$FolderBucket_t*) l3)->f_files;
        vader_struct_vader_front_resolver$DiscoveredModule_t* _a0_obj = (vader_struct_vader_front_resolver$DiscoveredModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$DiscoveredModule_t));
        vader_obj_header_init(_a0_obj, 1087u);
        _a0_obj->f_name = l5;
        _a0_obj->f_folder = l0;
        _a0_obj->f_files = l3;
        _a0_obj->f_origin = (uint8_t) 0;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static void vader_front_resolver$seed_wildcard_exports(void* l0, void* l1, void* l2, void* l3) {
    void* l4 = NULL;
    void* l8 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l16 = NULL;
    int64_t l5, l6, l14, l15;
    vader_string_t l7 = 0;
    vader_string_t l17 = 0;
    vader_box_t l9 = vader_box_null(), l10 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    bool t2;
    vader_box_t* gc_roots[3] = { &l9, &l10, &t0 };
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l4, &l8, &l11, &l12, &l13, &l16 };
    vader_string_t* gc_atom_roots[3] = { &l7, &l17, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = l2;
    l5 = ((vader_array_t*) l4)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l6];
        l7 = t0.payload.s;
        l9 = std_collections$MutableMap$std_core$Index$at__string__Any(l1, l7);
        if (l9.tag == 0u) {
            l6 = (l6 + INT64_C(1));
            continue;
        }
        l8 = l9.payload.obj;
        l10 = std_collections$MutableMap$std_core$Index$at__string__string__(l3, l7);
        l11 = ((vader_struct_vader_front_resolver$CollectedModule_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l8)->f_collected)->f_symbols;
        l12 = ((vader_struct_std_collections$MutableMap__string__vader_core_symbol_Symbol_t*) l11)->f_ekeys;
        l13 = ((vader_struct_std_collections$MutableMap__string__vader_core_symbol_Symbol_t*) l11)->f_evals;
        l14 = INT64_C(0);
        l15 = ((vader_struct_std_collections$MutableMap__string__vader_core_symbol_Symbol_t*) l11)->f_size;
        while ((l14 < l15)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l12);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l14)
            t0 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l14];
            t1 = t0.payload.s;
            vader_array_t* _a2_slotarr = ((vader_array_t*) l13);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l14)
            l16 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l14);
            t2 = vader_front_resolver$wildcard_exposes(l16, l10);
            if (t2) {
                l17 = ((vader_struct_vader_core_symbol$Symbol_t*) l16)->f_name;
                std_collections$get_or_put__string__vader_core_symbol_Symbol(l0, l17, l16);
            }
            l14 = (l14 + INT64_C(1));
        }
        l6 = (l6 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_front_resolver$select_target_bodies(void* l0, vader_box_t l1, void* l2) {
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
    void* l31 = NULL;
    void* l33 = NULL;
    void* l34 = NULL;
    void* l35 = NULL;
    int64_t l8, l9, l10, l11, l17, l18;
    vader_box_t l12 = vader_box_null(), l14 = vader_box_null(), l21 = vader_box_null(), l32 = vader_box_null();
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
    bool t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[6] = { &l1, &l12, &l14, &l21, &l32, &t2 };
    void** gc_raw_roots[17] = {
        &l0, &l2, &l3, &l4, &l5, &l6, &l7, &l13, &l16, &l27, &l28, &l30, &l31, &l33, &l34, &l35,
        &t0,
    };
    vader_string_t* gc_atom_roots[8] = { &l15, &l20, &l22, &l23, &l24, &l25, &l26, &l29 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 6u, 17u, gc_roots, gc_raw_roots, 0u, NULL, 8u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_front_resolver$check_selectors(l0, l2);
    vader_front_resolver$check_groups(l0, l2);
    if (l1.tag == 0u) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 335u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 346u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
    l5 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections$MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 533u);
    _a3_obj->f_ekeys = l3;
    _a3_obj->f_evals = l4;
    _a3_obj->f_index = l5;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l3 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(21u, 0u, 0u, 335u);
    l4 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(19u, 0u, 12u, 333u);
    l5 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(22u, 0u, 7u, 338u);
    l6 = (void*) _a6_arr;
    vader_struct_std_collections$MutableMap__string__bool_t* _a7_obj = (vader_struct_std_collections$MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__bool_t));
    vader_obj_header_init(_a7_obj, 539u);
    _a7_obj->f_ekeys = l4;
    _a7_obj->f_evals = l5;
    _a7_obj->f_index = l6;
    _a7_obj->f_mask = INT64_C(0);
    _a7_obj->f_grow_at = INT64_C(0);
    _a7_obj->f_size = INT64_C(0);
    _a7_obj->f_tombs = INT64_C(0);
    l4 = (void*) _a7_obj;
    vader_array_t* _a8_arr = vader_array_new(21u, 0u, 0u, 335u);
    l5 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(21u, 0u, 0u, 335u);
    l6 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(22u, 0u, 7u, 338u);
    l7 = (void*) _a10_arr;
    vader_struct_std_collections$MutableMap__string__string_t* _a11_obj = (vader_struct_std_collections$MutableMap__string__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__string_t));
    vader_obj_header_init(_a11_obj, 553u);
    _a11_obj->f_ekeys = l5;
    _a11_obj->f_evals = l6;
    _a11_obj->f_index = l7;
    _a11_obj->f_mask = INT64_C(0);
    _a11_obj->f_grow_at = INT64_C(0);
    _a11_obj->f_size = INT64_C(0);
    _a11_obj->f_tombs = INT64_C(0);
    l5 = (void*) _a11_obj;
    l6 = l0;
    l8 = ((vader_array_t*) l6)->length;
    l9 = INT64_C(0);
    while ((l9 < l8)) {
        vader_array_t* _a12_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
        t0 = vader_array_ref_load_obj(_a12_slotarr->buf, _a12_slotarr->offset + (size_t) l9);
        l7 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) t0)->f_program)->f_decls;
        l10 = ((vader_array_t*) l7)->length;
        l11 = INT64_C(0);
        while ((l11 < l10)) {
            vader_array_t* _a13_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
            l12 = vader_array_ref_load_box(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l11);
            if (l12.tag == 650u) {
                t0 = l12.payload.obj;
                l14 = vader_front_resolver$target_selectors(((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_decorators);
                if (l14.tag == 0u) {
                    l11 = (l11 + INT64_C(1));
                    continue;
                }
                l13 = l14.payload.obj;
                t1 = ((vader_struct_vader_front_resolver$TargetSelectors_t*) l13)->f_is_bare;
                if (t1) {
                    t0 = l12.payload.obj;
                    l15 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_name;
                    std_collections$MutableMap$std_core$IndexSet$set_at__string__bool(l4, l15, true);
                } else {
                    l16 = ((vader_struct_vader_front_resolver$TargetSelectors_t*) l13)->f_os;
                    l17 = ((vader_array_t*) l16)->length;
                    l18 = INT64_C(0);
                    while ((l18 < l17)) {
                        vader_array_t* _a14_slotarr = ((vader_array_t*) l16);
                        VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
                        t2 = vader_array_read_u8(_a14_slotarr, _a14_slotarr->offset + (size_t) l18, 340u);
                        l19 = ((uint8_t) t2.payload.i);
                        t0 = l12.payload.obj;
                        l20 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_name;
                        l21 = std_collections$MutableMap$std_core$Index$at__string__string(l5, l20);
                        t0 = l12.payload.obj;
                        l22 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_name;
                        if (l21.tag == 0u) {
                            l24 = std_target$Os$std_core$Display$to_string(l19);
                            l23 = concat_2(397u, l24);
                        } else {
                            l25 = l21.payload.s;
                            l26 = std_target$Os$std_core$Display$to_string(l19);
                            l23 = concat_3(l25, 361u, l26);
                        }
                        std_collections$MutableMap$std_core$IndexSet$set_at__string__string(l5, l22, l23);
                        l18 = (l18 + INT64_C(1));
                    }
                    l27 = ((vader_struct_vader_front_resolver$TargetSelectors_t*) l13)->f_os;
                    l28 = l1.payload.obj;
                    t1 = vader_front_resolver$matches_target(l27, l28);
                    if (t1) {
                        t0 = l12.payload.obj;
                        l29 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_name;
                        l30 = l12.payload.obj;
                        std_collections$MutableMap$std_core$IndexSet$set_at__string__Any(l3, l29, vader_ref_box(l30));
                    }
                }
            }
            l11 = (l11 + INT64_C(1));
        }
        l9 = (l9 + INT64_C(1));
    }
    l6 = l1.payload.obj;
    vader_front_resolver$report_uncovered(l0, l6, l3, l5, l2);
    vader_array_t* _a15_arr = vader_array_new(143u, 0u, 13u, 1106u);
    l5 = (void*) _a15_arr;
    l8 = ((vader_array_t*) l0)->length;
    vader_array_t* _a16_arr = vader_array_repeat((vader_array_t*) l5, (int64_t) l8);
    l5 = (void*) _a16_arr;
    l6 = l0;
    l8 = ((vader_array_t*) l6)->length;
    l9 = INT64_C(0);
    while ((l9 < l8)) {
        vader_array_t* _a17_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
        l7 = vader_array_ref_load_obj(_a17_slotarr->buf, _a17_slotarr->offset + (size_t) l9);
        vader_array_t* _a18_arr = vader_array_new(239u, 0u, 13u, 1618u);
        l13 = (void*) _a18_arr;
        l16 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) l7)->f_program)->f_decls;
        l10 = ((vader_array_t*) l16)->length;
        l11 = INT64_C(0);
        while ((l11 < l10)) {
            vader_array_t* _a19_slotarr = ((vader_array_t*) l16);
            VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
            l12 = vader_array_ref_load_box(_a19_slotarr->buf, _a19_slotarr->offset + (size_t) l11);
            l27 = l1.payload.obj;
            l14 = vader_front_resolver$resolve_decl(l12, l27, l3, l4);
            if (!(l14.tag == 0u)) {
                l21 = l14;
                vader_array_push_ref((vader_array_t*) l13, l21.payload.obj);
            }
            l11 = (l11 + INT64_C(1));
        }
        l28 = l7;
        l15 = ((vader_struct_vader_front_resolver$SourceFile_t*) l28)->f_path;
        l20 = ((vader_struct_vader_front_resolver$SourceFile_t*) l28)->f_content;
        l30 = ((vader_struct_vader_front_resolver$SourceFile_t*) l7)->f_program;
        l22 = ((vader_struct_toolchain_ast$Program_t*) l30)->f_file;
        l31 = ((vader_struct_toolchain_ast$Program_t*) l30)->f_span;
        l17 = ((vader_struct_toolchain_ast$Program_t*) l30)->f_id;
        l32 = ((vader_struct_toolchain_ast$Program_t*) l30)->f_module;
        vader_struct_toolchain_ast$Program_t* _a20_obj = (vader_struct_toolchain_ast$Program_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$Program_t));
        vader_obj_header_init(_a20_obj, 682u);
        _a20_obj->f_file = l22;
        _a20_obj->f_span = l31;
        _a20_obj->f_id = l17;
        _a20_obj->f_module = l32;
        _a20_obj->f_decls = l13;
        l33 = (void*) _a20_obj;
        l34 = ((vader_struct_vader_front_resolver$SourceFile_t*) l28)->f_id_factory;
        vader_struct_vader_front_resolver$SourceFile_t* _a21_obj = (vader_struct_vader_front_resolver$SourceFile_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$SourceFile_t));
        vader_obj_header_init(_a21_obj, 1106u);
        _a21_obj->f_path = l15;
        _a21_obj->f_content = l20;
        _a21_obj->f_program = l33;
        _a21_obj->f_id_factory = l34;
        l35 = (void*) _a21_obj;
        vader_array_push_ref((vader_array_t*) l5, l35);
        l9 = (l9 + INT64_C(1));
    }
    { void* __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_resolver$selected_target_of(vader_box_t l0) {
    vader_box_t l1 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l0, &l1 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1407u) {
        t0 = l0.payload.obj;
        l1 = vader_ref_box(t0);
        { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1405u) {
        l1 = vader_box_obj(0u, NULL);
    } else {
        if (!(l0.tag == 1406u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = vader_support_target$host_target();
        l1 = vader_ref_box(t0);
    }
    { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_resolver$sidecar_root(vader_string_t l0, vader_string_t l1) {
    vader_box_t l2 = vader_box_null();
    vader_string_t l3 = 0;
    vader_string_t t0 = 0;
    bool t1;
    vader_box_t* gc_roots[1] = { &l2 };
    vader_string_t* gc_atom_roots[4] = { &l0, &l1, &l3, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_front_resolver$home_root(l0, l1);
    if (!(l2.tag == 0u)) {
        t0 = l2.payload.s;
        { vader_box_t __vret = vader_box_string(335u, t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_front_resolver$toolchain_base();
    l3 = vader_front_resolver$join_path(t0, l0);
    t0 = vader_front_resolver$join_path(l3, l1);
    t1 = std_io$exists(t0);
    if (!(t1)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    { vader_box_t __vret = vader_box_string(335u, l3); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$sort_by_name(void* l0) {
    void* l1 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = (void*) &vader_fn_static___lambda_vader_front_resolver_1;
    t0 = std_sort$sort__vader_core_symbol_Symbol(l0, l1);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$source_files_in(vader_string_t l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    int64_t l4, l5;
    vader_string_t l6 = 0;
    vader_string_t l7 = 0;
    vader_box_t t0 = vader_box_null();
    bool t1;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[3] = { &l1, &l2, &l3 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l6, &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 335u);
    l2 = (void*) _a0_arr;
    l3 = (void*) &vader_fn_static_std_string$compare_ascending;
    l3 = std_sort$sort__string(l1, l3);
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t0 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l5];
        l6 = t0.payload.s;
        l7 = vader_front_resolver$join_path(l0, l6);
        t1 = std_string$ends_with(l6, 436u);
        if (t1) {
            t1 = std_io$is_dir(l7);
            if (!(t1)) {
                vader_array_push_scalar((vader_array_t*) l2, vader_box_string(335u, l7));
            }
        }
        l5 = (l5 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_front_resolver$span_origin(void* l0) {
    vader_string_t l1 = 0;
    int64_t l2, l4;
    void* l3 = NULL;
    int32_t t0;
    vader_string_t t1 = 0;
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) l0)->f_start)->f_file;
    l2 = vader_host_std_core$byte_len(l1);
    l3 = (void*) vader_buffer_new((size_t) (INT64_C(21) + l2));
    l2 = INT64_C(0);
    l2 = std_core$write_string_at(l3, l2, l1);
    l2 = std_core$write_string_at(l3, l2, 459u);
    t0 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) l0)->f_start)->f_line;
    l4 = ((int64_t) (int32_t) t0);
    l2 = std_core$write_int(l3, l2, l4);
    t1 = std_core$finish_buffer(l3, l2);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_front_resolver$stamp_binding_spans(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    int64_t l4, l5;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &t1 };
    void** gc_raw_roots[4] = { &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 689u) {
        l2 = l0.payload.obj;
        l3 = vader_front_resolver$next_clone_span(l1);
        ((vader_struct_toolchain_ast$SimpleBinding_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast$SimpleBinding_t*) l2);
        l2 = l0.payload.obj;
        l3 = vader_front_resolver$next_clone_span(l1);
        ((vader_struct_toolchain_ast$SimpleBinding_t*) l2)->f_name_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast$SimpleBinding_t*) l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 701u) {
        l2 = l0.payload.obj;
        l3 = vader_front_resolver$next_clone_span(l1);
        ((vader_struct_toolchain_ast$TupleBinding_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast$TupleBinding_t*) l2);
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$TupleBinding_t*) t0)->f_elements;
        l4 = ((vader_array_t*) l2)->length;
        l5 = INT64_C(0);
        while ((l5 < l4)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
            vader_front_resolver$stamp_binding_spans(t1, l1);
            l5 = (l5 + INT64_C(1));
        }
    } else if (l0.tag == 706u) {
        l2 = l0.payload.obj;
        l3 = vader_front_resolver$next_clone_span(l1);
        ((vader_struct_toolchain_ast$WildcardBinding_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast$WildcardBinding_t*) l2);
    } else {
        if (!(l0.tag == 685u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = l0.payload.obj;
        l3 = vader_front_resolver$next_clone_span(l1);
        ((vader_struct_toolchain_ast$RestBinding_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast$RestBinding_t*) l2);
        l2 = l0.payload.obj;
        l3 = vader_front_resolver$next_clone_span(l1);
        ((vader_struct_toolchain_ast$RestBinding_t*) l2)->f_name_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast$RestBinding_t*) l2);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$stamp_block_spans(void* l0, void* l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_front_resolver$next_clone_span(l1);
    ((vader_struct_toolchain_ast$BlockExpr_t*) l0)->f_span = l2;
    VADER_WRITE_BARRIER((vader_struct_toolchain_ast$BlockExpr_t*) l0);
    l2 = ((vader_struct_toolchain_ast$BlockExpr_t*) l0)->f_stmts;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        vader_front_resolver$stamp_stmt_spans(t0, l1);
        l4 = (l4 + INT64_C(1));
    }
    if (((vader_struct_toolchain_ast$BlockExpr_t*) l0)->f_trailing.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_front_resolver$stamp_expr_spans(((vader_struct_toolchain_ast$BlockExpr_t*) l0)->f_trailing, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$stamp_expr_spans(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    int64_t l4, l5;
    vader_box_t l7 = vader_box_null(), l8 = vader_box_null();
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l0, &l7, &l8, &t1 };
    void** gc_raw_roots[9] = { &l1, &l2, &l3, &l6, &l9, &l10, &l11, &l12, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 9u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 665u) {
        l2 = l0.payload.obj;
        l3 = vader_front_resolver$next_clone_span(l1);
        ((vader_struct_toolchain_ast$IntLitExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast$IntLitExpr_t*) l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 649u) {
        l2 = l0.payload.obj;
        l3 = vader_front_resolver$next_clone_span(l1);
        ((vader_struct_toolchain_ast$FloatLitExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast$FloatLitExpr_t*) l2);
    } else if (l0.tag == 625u) {
        l2 = l0.payload.obj;
        l3 = vader_front_resolver$next_clone_span(l1);
        ((vader_struct_toolchain_ast$BoolLitExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast$BoolLitExpr_t*) l2);
    } else if (l0.tag == 677u) {
        l2 = l0.payload.obj;
        l3 = vader_front_resolver$next_clone_span(l1);
        ((vader_struct_toolchain_ast$NullLitExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast$NullLitExpr_t*) l2);
    } else if (l0.tag == 630u) {
        l2 = l0.payload.obj;
        l3 = vader_front_resolver$next_clone_span(l1);
        ((vader_struct_toolchain_ast$CharLitExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast$CharLitExpr_t*) l2);
    } else if (l0.tag == 655u) {
        l2 = l0.payload.obj;
        l3 = vader_front_resolver$next_clone_span(l1);
        ((vader_struct_toolchain_ast$IdentExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast$IdentExpr_t*) l2);
    } else if (l0.tag == 628u) {
        l2 = l0.payload.obj;
        l3 = vader_front_resolver$next_clone_span(l1);
        ((vader_struct_toolchain_ast$CallExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast$CallExpr_t*) l2);
        t0 = l0.payload.obj;
        vader_front_resolver$stamp_expr_spans(((vader_struct_toolchain_ast$CallExpr_t*) t0)->f_callee, l1);
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$CallExpr_t*) t0)->f_type_args;
        l4 = ((vader_array_t*) l2)->length;
        l5 = INT64_C(0);
        while ((l5 < l4)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
            vader_front_resolver$stamp_expr_spans(t1, l1);
            l5 = (l5 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$CallExpr_t*) t0)->f_args;
        l4 = ((vader_array_t*) l2)->length;
        l5 = INT64_C(0);
        while ((l5 < l4)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            l3 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
            l6 = vader_front_resolver$next_clone_span(l1);
            ((vader_struct_toolchain_ast$CallArg_t*) l3)->f_span = l6;
            VADER_WRITE_BARRIER((vader_struct_toolchain_ast$CallArg_t*) l3);
            vader_front_resolver$stamp_expr_spans(((vader_struct_toolchain_ast$CallArg_t*) l3)->f_value, l1);
            l5 = (l5 + INT64_C(1));
        }
    } else if (l0.tag == 648u) {
        l2 = l0.payload.obj;
        l3 = vader_front_resolver$next_clone_span(l1);
        ((vader_struct_toolchain_ast$FieldExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast$FieldExpr_t*) l2);
        t0 = l0.payload.obj;
        vader_front_resolver$stamp_expr_spans(((vader_struct_toolchain_ast$FieldExpr_t*) t0)->f_target, l1);
    } else if (l0.tag == 663u) {
        l2 = l0.payload.obj;
        l3 = vader_front_resolver$next_clone_span(l1);
        ((vader_struct_toolchain_ast$IndexExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast$IndexExpr_t*) l2);
        t0 = l0.payload.obj;
        vader_front_resolver$stamp_expr_spans(((vader_struct_toolchain_ast$IndexExpr_t*) t0)->f_target, l1);
        t0 = l0.payload.obj;
        vader_front_resolver$stamp_expr_spans(((vader_struct_toolchain_ast$IndexExpr_t*) t0)->f_index, l1);
    } else if (l0.tag == 704u) {
        l2 = l0.payload.obj;
        l3 = vader_front_resolver$next_clone_span(l1);
        ((vader_struct_toolchain_ast$UnaryExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast$UnaryExpr_t*) l2);
        t0 = l0.payload.obj;
        vader_front_resolver$stamp_expr_spans(((vader_struct_toolchain_ast$UnaryExpr_t*) t0)->f_operand, l1);
    } else if (l0.tag == 623u) {
        l2 = l0.payload.obj;
        l3 = vader_front_resolver$next_clone_span(l1);
        ((vader_struct_toolchain_ast$BinaryExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast$BinaryExpr_t*) l2);
        t0 = l0.payload.obj;
        vader_front_resolver$stamp_expr_spans(((vader_struct_toolchain_ast$BinaryExpr_t*) t0)->f_left, l1);
        t0 = l0.payload.obj;
        vader_front_resolver$stamp_expr_spans(((vader_struct_toolchain_ast$BinaryExpr_t*) t0)->f_right, l1);
    } else if (l0.tag == 658u) {
        l2 = l0.payload.obj;
        l3 = vader_front_resolver$next_clone_span(l1);
        ((vader_struct_toolchain_ast$IfExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast$IfExpr_t*) l2);
        t0 = l0.payload.obj;
        vader_front_resolver$stamp_expr_spans(((vader_struct_toolchain_ast$IfExpr_t*) t0)->f_cond, l1);
        t0 = l0.payload.obj;
        vader_front_resolver$stamp_block_spans(((vader_struct_toolchain_ast$IfExpr_t*) t0)->f_then_block, l1);
        t0 = l0.payload.obj;
        l7 = ((vader_struct_toolchain_ast$IfExpr_t*) t0)->f_else_branch;
        l8 = l7;
        if (!(l7.tag == 0u)) {
            if (l7.tag == 656u) {
                t0 = l8.payload.obj;
                vader_front_resolver$stamp_block_spans(((vader_struct_toolchain_ast$IfElseBlock_t*) t0)->f_block, l1);
            } else {
                if (!(l7.tag == 657u)) {
                    vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                }
                t0 = l8.payload.obj;
                vader_front_resolver$stamp_expr_spans(vader_ref_box(((vader_struct_toolchain_ast$IfElseIf_t*) t0)->f_branch), l1);
            }
        }
    } else if (l0.tag == 672u) {
        l2 = l0.payload.obj;
        l3 = vader_front_resolver$next_clone_span(l1);
        ((vader_struct_toolchain_ast$MatchExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast$MatchExpr_t*) l2);
        t0 = l0.payload.obj;
        vader_front_resolver$stamp_expr_spans(((vader_struct_toolchain_ast$MatchExpr_t*) t0)->f_scrutinee, l1);
        t0 = l0.payload.obj;
        l7 = ((vader_struct_toolchain_ast$MatchExpr_t*) t0)->f_binding;
        if (!(l7.tag == 0u)) {
            t0 = l7.payload.obj;
            vader_front_resolver$stamp_binding_spans(vader_ref_box(t0), l1);
        }
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$MatchExpr_t*) t0)->f_arms;
        l4 = ((vader_array_t*) l2)->length;
        l5 = INT64_C(0);
        while ((l5 < l4)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            l3 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
            l6 = vader_front_resolver$next_clone_span(l1);
            ((vader_struct_toolchain_ast$MatchArm_t*) l3)->f_span = l6;
            VADER_WRITE_BARRIER((vader_struct_toolchain_ast$MatchArm_t*) l3);
            vader_front_resolver$stamp_pattern_spans(((vader_struct_toolchain_ast$MatchArm_t*) l3)->f_pattern, l1);
            if (!(((vader_struct_toolchain_ast$MatchArm_t*) l3)->f_guard.tag == 0u)) {
                vader_front_resolver$stamp_expr_spans(((vader_struct_toolchain_ast$MatchArm_t*) l3)->f_guard, l1);
            }
            vader_front_resolver$stamp_expr_spans(((vader_struct_toolchain_ast$MatchArm_t*) l3)->f_body, l1);
            l5 = (l5 + INT64_C(1));
        }
    } else if (l0.tag == 624u) {
        t0 = l0.payload.obj;
        vader_front_resolver$stamp_block_spans(t0, l1);
    } else if (l0.tag == 695u) {
        l2 = l0.payload.obj;
        l3 = vader_front_resolver$next_clone_span(l1);
        ((vader_struct_toolchain_ast$StructLitExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast$StructLitExpr_t*) l2);
        t0 = l0.payload.obj;
        vader_front_resolver$stamp_expr_spans(((vader_struct_toolchain_ast$StructLitExpr_t*) t0)->f_type_name, l1);
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$StructLitExpr_t*) t0)->f_items;
        l4 = ((vader_array_t*) l2)->length;
        l5 = INT64_C(0);
        while ((l5 < l4)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            l7 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l5);
            if (l7.tag == 696u) {
                l3 = l7.payload.obj;
                l6 = vader_front_resolver$next_clone_span(l1);
                ((vader_struct_toolchain_ast$StructLitField_t*) l3)->f_span = l6;
                VADER_WRITE_BARRIER((vader_struct_toolchain_ast$StructLitField_t*) l3);
                l9 = l7.payload.obj;
                l10 = vader_front_resolver$next_clone_span(l1);
                ((vader_struct_toolchain_ast$StructLitField_t*) l9)->f_name_span = l10;
                VADER_WRITE_BARRIER((vader_struct_toolchain_ast$StructLitField_t*) l9);
                t0 = l7.payload.obj;
                vader_front_resolver$stamp_expr_spans(((vader_struct_toolchain_ast$StructLitField_t*) t0)->f_value, l1);
            } else {
                if (!(l7.tag == 697u)) {
                    vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                }
                l11 = l7.payload.obj;
                l12 = vader_front_resolver$next_clone_span(l1);
                ((vader_struct_toolchain_ast$StructLitSpread_t*) l11)->f_span = l12;
                VADER_WRITE_BARRIER((vader_struct_toolchain_ast$StructLitSpread_t*) l11);
                t0 = l7.payload.obj;
                vader_front_resolver$stamp_expr_spans(((vader_struct_toolchain_ast$StructLitSpread_t*) t0)->f_expr, l1);
            }
            l5 = (l5 + INT64_C(1));
        }
    } else if (l0.tag == 688u) {
        l2 = l0.payload.obj;
        l3 = vader_front_resolver$next_clone_span(l1);
        ((vader_struct_toolchain_ast$SeqLitExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast$SeqLitExpr_t*) l2);
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$SeqLitExpr_t*) t0)->f_elements;
        l4 = ((vader_array_t*) l2)->length;
        l5 = INT64_C(0);
        while ((l5 < l4)) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            t1 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l5);
            vader_front_resolver$stamp_expr_spans(t1, l1);
            l5 = (l5 + INT64_C(1));
        }
    } else if (l0.tag == 683u) {
        l2 = l0.payload.obj;
        l3 = vader_front_resolver$next_clone_span(l1);
        ((vader_struct_toolchain_ast$RangeExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast$RangeExpr_t*) l2);
        t0 = l0.payload.obj;
        vader_front_resolver$stamp_expr_spans(((vader_struct_toolchain_ast$RangeExpr_t*) t0)->f_lower, l1);
        t0 = l0.payload.obj;
        vader_front_resolver$stamp_expr_spans(((vader_struct_toolchain_ast$RangeExpr_t*) t0)->f_upper, l1);
    } else if (l0.tag == 622u) {
        l2 = l0.payload.obj;
        l3 = vader_front_resolver$next_clone_span(l1);
        ((vader_struct_toolchain_ast$AwaitExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast$AwaitExpr_t*) l2);
        t0 = l0.payload.obj;
        vader_front_resolver$stamp_expr_spans(((vader_struct_toolchain_ast$AwaitExpr_t*) t0)->f_inner, l1);
    } else if (l0.tag == 629u) {
        l2 = l0.payload.obj;
        l3 = vader_front_resolver$next_clone_span(l1);
        ((vader_struct_toolchain_ast$CastExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast$CastExpr_t*) l2);
        t0 = l0.payload.obj;
        vader_front_resolver$stamp_expr_spans(((vader_struct_toolchain_ast$CastExpr_t*) t0)->f_target, l1);
        t0 = l0.payload.obj;
        vader_front_resolver$stamp_expr_spans(((vader_struct_toolchain_ast$CastExpr_t*) t0)->f_value, l1);
    } else if (l0.tag == 666u) {
        l2 = l0.payload.obj;
        l3 = vader_front_resolver$next_clone_span(l1);
        ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l2);
        l2 = l0.payload.obj;
        l3 = vader_front_resolver$next_clone_span(l1);
        ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l2)->f_name_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l2);
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) t0)->f_args;
        l4 = ((vader_array_t*) l2)->length;
        l5 = INT64_C(0);
        while ((l5 < l4)) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            t1 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l5);
            vader_front_resolver$stamp_expr_spans(t1, l1);
            l5 = (l5 + INT64_C(1));
        }
    } else if (l0.tag == 643u) {
        l2 = l0.payload.obj;
        l3 = vader_front_resolver$next_clone_span(l1);
        ((vader_struct_toolchain_ast$DotVariantExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast$DotVariantExpr_t*) l2);
        l2 = l0.payload.obj;
        l3 = vader_front_resolver$next_clone_span(l1);
        ((vader_struct_toolchain_ast$DotVariantExpr_t*) l2)->f_variant_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast$DotVariantExpr_t*) l2);
    } else if (l0.tag == 690u) {
        l2 = l0.payload.obj;
        l3 = vader_front_resolver$next_clone_span(l1);
        ((vader_struct_toolchain_ast$StringLitExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast$StringLitExpr_t*) l2);
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$StringLitExpr_t*) t0)->f_parts;
        l4 = ((vader_array_t*) l2)->length;
        l5 = INT64_C(0);
        while ((l5 < l4)) {
            vader_array_t* _a6_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            l7 = vader_array_ref_load_box(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l5);
            if (l7.tag == 692u) {
                l3 = l7.payload.obj;
                l6 = vader_front_resolver$next_clone_span(l1);
                ((vader_struct_toolchain_ast$StringLitText_t*) l3)->f_span = l6;
                VADER_WRITE_BARRIER((vader_struct_toolchain_ast$StringLitText_t*) l3);
            } else {
                if (!(l7.tag == 691u)) {
                    vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                }
                l9 = l7.payload.obj;
                l10 = vader_front_resolver$next_clone_span(l1);
                ((vader_struct_toolchain_ast$StringLitInterp_t*) l9)->f_span = l10;
                VADER_WRITE_BARRIER((vader_struct_toolchain_ast$StringLitInterp_t*) l9);
                t0 = l7.payload.obj;
                vader_front_resolver$stamp_expr_spans(((vader_struct_toolchain_ast$StringLitInterp_t*) t0)->f_expr, l1);
            }
            l5 = (l5 + INT64_C(1));
        }
    } else if (l0.tag == 668u) {
        l2 = l0.payload.obj;
        l3 = vader_front_resolver$next_clone_span(l1);
        ((vader_struct_toolchain_ast$LambdaExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast$LambdaExpr_t*) l2);
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$LambdaExpr_t*) t0)->f_params;
        l4 = ((vader_array_t*) l2)->length;
        l5 = INT64_C(0);
        while ((l5 < l4)) {
            vader_array_t* _a7_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            l3 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l5);
            l6 = vader_front_resolver$next_clone_span(l1);
            ((vader_struct_toolchain_ast$FnParam_t*) l3)->f_span = l6;
            VADER_WRITE_BARRIER((vader_struct_toolchain_ast$FnParam_t*) l3);
            l9 = toolchain_span$empty_span();
            ((vader_struct_toolchain_ast$FnParam_t*) l3)->f_name_span = l9;
            VADER_WRITE_BARRIER((vader_struct_toolchain_ast$FnParam_t*) l3);
            if (!(((vader_struct_toolchain_ast$FnParam_t*) l3)->f_ty.tag == 0u)) {
                vader_front_resolver$stamp_expr_spans(((vader_struct_toolchain_ast$FnParam_t*) l3)->f_ty, l1);
            }
            if (!(((vader_struct_toolchain_ast$FnParam_t*) l3)->f_default_value.tag == 0u)) {
                vader_front_resolver$stamp_expr_spans(((vader_struct_toolchain_ast$FnParam_t*) l3)->f_default_value, l1);
            }
            l5 = (l5 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        if (!(((vader_struct_toolchain_ast$LambdaExpr_t*) t0)->f_return_type.tag == 0u)) {
            t0 = l0.payload.obj;
            vader_front_resolver$stamp_expr_spans(((vader_struct_toolchain_ast$LambdaExpr_t*) t0)->f_return_type, l1);
        }
        t0 = l0.payload.obj;
        vader_front_resolver$stamp_block_spans(((vader_struct_toolchain_ast$LambdaExpr_t*) t0)->f_body, l1);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$stamp_pattern_spans(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[4] = { &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 667u) {
        l2 = l0.payload.obj;
        l3 = vader_front_resolver$next_clone_span(l1);
        ((vader_struct_toolchain_ast$IsPattern_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast$IsPattern_t*) l2);
        t0 = l0.payload.obj;
        if (!(((vader_struct_toolchain_ast$IsPattern_t*) t0)->f_inner.tag == 0u)) {
            t0 = l0.payload.obj;
            vader_front_resolver$stamp_pattern_spans(((vader_struct_toolchain_ast$IsPattern_t*) t0)->f_inner, l1);
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$stamp_stmt_spans(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    int64_t l4, l5;
    vader_box_t l6 = vader_box_null(), l7 = vader_box_null(), l8 = vader_box_null(), l9 = vader_box_null();
    vader_string_t l10 = 0;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[6] = { &l0, &l6, &l7, &l8, &l9, &t1 };
    void** gc_raw_roots[4] = { &l1, &l2, &l3, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l10 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 6u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 669u) {
        l2 = l0.payload.obj;
        l3 = vader_front_resolver$next_clone_span(l1);
        ((vader_struct_toolchain_ast$LetStmt_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast$LetStmt_t*) l2);
        t0 = l0.payload.obj;
        vader_front_resolver$stamp_binding_spans(((vader_struct_toolchain_ast$LetStmt_t*) t0)->f_binding, l1);
        t0 = l0.payload.obj;
        if (!(((vader_struct_toolchain_ast$LetStmt_t*) t0)->f_ty.tag == 0u)) {
            t0 = l0.payload.obj;
            vader_front_resolver$stamp_expr_spans(((vader_struct_toolchain_ast$LetStmt_t*) t0)->f_ty, l1);
        }
        t0 = l0.payload.obj;
        vader_front_resolver$stamp_expr_spans(((vader_struct_toolchain_ast$LetStmt_t*) t0)->f_value, l1);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 647u) {
        l2 = l0.payload.obj;
        l3 = vader_front_resolver$next_clone_span(l1);
        ((vader_struct_toolchain_ast$ExprStmt_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast$ExprStmt_t*) l2);
        t0 = l0.payload.obj;
        vader_front_resolver$stamp_expr_spans(((vader_struct_toolchain_ast$ExprStmt_t*) t0)->f_expr, l1);
    } else if (l0.tag == 687u) {
        l2 = l0.payload.obj;
        l3 = vader_front_resolver$next_clone_span(l1);
        ((vader_struct_toolchain_ast$ReturnStmt_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast$ReturnStmt_t*) l2);
        t0 = l0.payload.obj;
        if (!(((vader_struct_toolchain_ast$ReturnStmt_t*) t0)->f_value.tag == 0u)) {
            t0 = l0.payload.obj;
            vader_front_resolver$stamp_expr_spans(((vader_struct_toolchain_ast$ReturnStmt_t*) t0)->f_value, l1);
        }
    } else if (l0.tag == 621u) {
        l2 = l0.payload.obj;
        l3 = vader_front_resolver$next_clone_span(l1);
        ((vader_struct_toolchain_ast$AssignStmt_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast$AssignStmt_t*) l2);
        t0 = l0.payload.obj;
        vader_front_resolver$stamp_expr_spans(((vader_struct_toolchain_ast$AssignStmt_t*) t0)->f_target, l1);
        t0 = l0.payload.obj;
        vader_front_resolver$stamp_expr_spans(((vader_struct_toolchain_ast$AssignStmt_t*) t0)->f_value, l1);
    } else if (l0.tag == 637u) {
        l2 = l0.payload.obj;
        l3 = vader_front_resolver$next_clone_span(l1);
        ((vader_struct_toolchain_ast$DestructureAssignStmt_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast$DestructureAssignStmt_t*) l2);
        t0 = l0.payload.obj;
        l2 = toolchain_ast$assign_places(t0);
        l4 = ((vader_array_t*) l2)->length;
        l5 = INT64_C(0);
        while ((l5 < l4)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
            vader_front_resolver$stamp_expr_spans(t1, l1);
            l5 = (l5 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        vader_front_resolver$stamp_expr_spans(((vader_struct_toolchain_ast$DestructureAssignStmt_t*) t0)->f_value, l1);
    } else if (l0.tag == 653u) {
        l2 = l0.payload.obj;
        l3 = vader_front_resolver$next_clone_span(l1);
        ((vader_struct_toolchain_ast$ForStmt_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast$ForStmt_t*) l2);
        t0 = l0.payload.obj;
        l6 = ((vader_struct_toolchain_ast$ForStmt_t*) t0)->f_form;
        l7 = l6;
        if (l6.tag == 705u) {
            t0 = l7.payload.obj;
            vader_front_resolver$stamp_expr_spans(((vader_struct_toolchain_ast$WhileFor_t*) t0)->f_cond, l1);
        } else if (l6.tag == 662u) {
            t0 = l7.payload.obj;
            l8 = ((vader_struct_toolchain_ast$InFor_t*) t0)->f_loop_var;
            l9 = l8;
            if (l8.tag == 675u) {
                l2 = l7.payload.obj;
                t0 = l9.payload.obj;
                l10 = ((vader_struct_toolchain_ast$NamedVar_t*) t0)->f_name;
                l3 = vader_front_resolver$next_clone_span(l1);
                vader_struct_toolchain_ast$NamedVar_t* _a1_obj = (vader_struct_toolchain_ast$NamedVar_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$NamedVar_t));
                vader_obj_header_init(_a1_obj, 675u);
                _a1_obj->f_name = l10;
                _a1_obj->f_span = l3;
                l3 = (void*) _a1_obj;
                ((vader_struct_toolchain_ast$InFor_t*) l2)->f_loop_var = vader_ref_box(l3);
                VADER_WRITE_BARRIER((vader_struct_toolchain_ast$InFor_t*) l2);
            } else if (l8.tag == 639u) {
                t0 = l9.payload.obj;
                vader_front_resolver$stamp_binding_spans(((vader_struct_toolchain_ast$DestructureVar_t*) t0)->f_pattern, l1);
            } else if (!(l8.tag == 640u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            t0 = l7.payload.obj;
            vader_front_resolver$stamp_expr_spans(((vader_struct_toolchain_ast$InFor_t*) t0)->f_iter, l1);
        } else if (!(l6.tag == 664u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = l0.payload.obj;
        vader_front_resolver$stamp_block_spans(((vader_struct_toolchain_ast$ForStmt_t*) t0)->f_body, l1);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_string_t vader_front_resolver$string_at(void* l0, vader_string_t l1, void* l2) {
    vader_box_t l3 = vader_box_null();
    vader_string_t l4 = 0;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l4, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = std_collections$MutableMap$std_core$Index$at__string__Any(((vader_struct_json$JsonObject_t*) l0)->f_entries, l1);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return 0u; }
    }
    if (!(l3.tag == 455u)) {
        l4 = concat_3(1038u, l1, 1171u);
        vader_array_push_scalar((vader_array_t*) l2, vader_box_string(335u, l4));
        { vader_gc_top = gc_frame.prev; return 0u; }
    }
    t0 = l3.payload.obj;
    t1 = ((vader_struct_json$JsonString_t*) t0)->f_value;
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$string_list(void* l0, vader_string_t l1, void* l2) {
    vader_box_t l3 = vader_box_null();
    vader_string_t l4 = 0;
    vader_string_t l9 = 0;
    void* l5 = NULL;
    void* l6 = NULL;
    int64_t l7, l8;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[5] = { &l0, &l2, &l5, &l6, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l4, &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = std_collections$MutableMap$std_core$Index$at__string__Any(((vader_struct_json$JsonObject_t*) l0)->f_entries, l1);
    if (l3.tag == 0u) {
        vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 335u);
        t0 = (void*) _a0_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l3.tag == 449u)) {
        l4 = concat_3(1038u, l1, 1175u);
        vader_array_push_scalar((vader_array_t*) l2, vader_box_string(335u, l4));
        vader_array_t* _a1_arr = vader_array_new(21u, 0u, 0u, 335u);
        t0 = (void*) _a1_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a2_arr = vader_array_new(21u, 0u, 0u, 335u);
    l5 = (void*) _a2_arr;
    t0 = l3.payload.obj;
    l6 = ((vader_struct_json$JsonArray_t*) t0)->f_items;
    l7 = ((vader_array_t*) l6)->length;
    l8 = INT64_C(0);
    while ((l8 < l7)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        l3 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l8);
        if (l3.tag == 455u) {
            t0 = l3.payload.obj;
            l4 = ((vader_struct_json$JsonString_t*) t0)->f_value;
            vader_array_push_scalar((vader_array_t*) l5, vader_box_string(335u, l4));
        } else {
            l9 = concat_3(1038u, l1, 1196u);
            vader_array_push_scalar((vader_array_t*) l2, vader_box_string(335u, l9));
        }
        l8 = (l8 + INT64_C(1));
    }
    { void* __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_resolver$subst_opt_expr(vader_box_t l0, void* l1) {
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &t0 };
    void** gc_raw_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(l0.tag == 0u)) {
        t0 = vader_front_resolver$substitute_expr_full(l0, l1);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static void* vader_front_resolver$substitute_block(void* l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    int64_t l3, l5;
    vader_box_t l6 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l6, &t0 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l4, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(240u, 0u, 13u, 1626u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_array_t*) ((vader_struct_toolchain_ast$BlockExpr_t*) l0)->f_stmts)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a1_arr;
    l4 = ((vader_struct_toolchain_ast$BlockExpr_t*) l0)->f_stmts;
    l3 = ((vader_array_t*) l4)->length;
    l5 = INT64_C(0);
    while ((l5 < l3)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t0 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
        l6 = vader_front_resolver$substitute_stmt(t0, l1);
        vader_array_push_ref((vader_array_t*) l2, l6.payload.obj);
        l5 = (l5 + INT64_C(1));
    }
    l6 = vader_box_obj(0u, NULL);
    if (!(((vader_struct_toolchain_ast$BlockExpr_t*) l0)->f_trailing.tag == 0u)) {
        l6 = vader_front_resolver$substitute_expr_full(((vader_struct_toolchain_ast$BlockExpr_t*) l0)->f_trailing, l1);
    }
    vader_struct_toolchain_ast$BlockExpr_t* _a3_obj = (vader_struct_toolchain_ast$BlockExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$BlockExpr_t));
    vader_obj_header_init(_a3_obj, 624u);
    _a3_obj->f_span = ((vader_struct_toolchain_ast$BlockExpr_t*) l0)->f_span;
    _a3_obj->f_id = INT64_C(0);
    _a3_obj->f_stmts = l2;
    _a3_obj->f_trailing = l6;
    t1 = (void*) _a3_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$substitute_block_materialized(void* l0, void* l1, void* l2, void* l3) {
    void* l4 = NULL;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = vader_front_resolver$substitute_block(l0, l1);
    vader_front_parser$assign_block_ids(l4, l2);
    vader_front_resolver$stamp_block_spans(l4, l3);
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_resolver$substitute_coalesce_fallback(vader_box_t l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l0, &l2 };
    void** gc_raw_roots[3] = { &l1, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 687u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_toolchain_ast$ReturnStmt_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l2 = vader_front_resolver$subst_opt_expr(((vader_struct_toolchain_ast$ReturnStmt_t*) t0)->f_value, l1);
        vader_struct_toolchain_ast$ReturnStmt_t* _a0_obj = (vader_struct_toolchain_ast$ReturnStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$ReturnStmt_t));
        vader_obj_header_init(_a0_obj, 687u);
        _a0_obj->f_span = l3;
        _a0_obj->f_id = INT64_C(0);
        _a0_obj->f_value = l2;
        t0 = (void*) _a0_obj;
        l2 = vader_ref_box(t0);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if ((l0.tag == 626u || l0.tag == 632u)) {
        l2 = l0;
    } else {
        if (!((l0.tag == 619u || l0.tag == 622u || l0.tag == 623u || l0.tag == 624u || l0.tag == 625u || l0.tag == 628u || l0.tag == 629u || l0.tag == 630u || l0.tag == 643u || l0.tag == 648u || l0.tag == 649u || l0.tag == 652u || l0.tag == 654u || l0.tag == 655u || l0.tag == 658u || l0.tag == 663u || l0.tag == 665u || l0.tag == 666u || l0.tag == 668u || l0.tag == 672u || l0.tag == 676u || l0.tag == 677u || l0.tag == 683u || l0.tag == 688u || l0.tag == 690u || l0.tag == 695u || l0.tag == 704u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = vader_front_resolver$substitute_expr_full(l0, l1);
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_resolver$substitute_expr_full(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l11 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null(), l14 = vader_box_null();
    int64_t l6, l7;
    bool l10, l15;
    vader_string_t l12 = 0;
    uint8_t l13;
    void* t0 = NULL;
    void* t2 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[5] = { &l0, &l3, &l4, &l14, &t1 };
    void** gc_raw_roots[10] = { &l1, &l2, &l5, &l8, &l9, &l11, &l16, &l17, &t0, &t2 };
    vader_string_t* gc_atom_roots[1] = { &l12 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 5u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if ((l0.tag == 625u || l0.tag == 630u || l0.tag == 649u || l0.tag == 665u || l0.tag == 677u)) {
        { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 676u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$NullCoalesceExpr_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = vader_front_resolver$substitute_expr_full(((vader_struct_toolchain_ast$NullCoalesceExpr_t*) t0)->f_left, l1);
        t0 = l0.payload.obj;
        l4 = vader_front_resolver$substitute_coalesce_fallback(((vader_struct_toolchain_ast$NullCoalesceExpr_t*) t0)->f_fallback, l1);
        vader_struct_toolchain_ast$NullCoalesceExpr_t* _a0_obj = (vader_struct_toolchain_ast$NullCoalesceExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$NullCoalesceExpr_t));
        vader_obj_header_init(_a0_obj, 676u);
        _a0_obj->f_span = l2;
        _a0_obj->f_id = INT64_C(0);
        _a0_obj->f_left = l3;
        _a0_obj->f_fallback = l4;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 655u) {
        t0 = l0.payload.obj;
        t1 = vader_front_resolver$substitute_type_expr(vader_ref_box(t0), l1);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 654u) {
        t0 = l0.payload.obj;
        t1 = vader_front_resolver$substitute_type_expr(vader_ref_box(t0), l1);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 652u) {
        t0 = l0.payload.obj;
        t1 = vader_front_resolver$substitute_type_expr(vader_ref_box(t0), l1);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 619u) {
        t0 = l0.payload.obj;
        t1 = vader_front_resolver$substitute_type_expr(vader_ref_box(t0), l1);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 628u) {
        vader_array_t* _a1_arr = vader_array_new(40u, 0u, 13u, 627u);
        l2 = (void*) _a1_arr;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast$CallExpr_t*) t0)->f_args;
        l6 = ((vader_array_t*) l5)->length;
        l7 = INT64_C(0);
        while ((l7 < l6)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            l8 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l7);
            l9 = ((vader_struct_toolchain_ast$CallArg_t*) l8)->f_span;
            l3 = ((vader_struct_toolchain_ast$CallArg_t*) l8)->f_name;
            l4 = vader_front_resolver$substitute_expr_full(((vader_struct_toolchain_ast$CallArg_t*) l8)->f_value, l1);
            l10 = ((vader_struct_toolchain_ast$CallArg_t*) l8)->f_spread;
            vader_struct_toolchain_ast$CallArg_t* _a3_obj = (vader_struct_toolchain_ast$CallArg_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$CallArg_t));
            vader_obj_header_init(_a3_obj, 627u);
            _a3_obj->f_span = l9;
            _a3_obj->f_id = INT64_C(0);
            _a3_obj->f_name = l3;
            _a3_obj->f_value = l4;
            _a3_obj->f_spread = l10;
            l11 = (void*) _a3_obj;
            vader_array_push_ref((vader_array_t*) l2, l11);
            l7 = (l7 + INT64_C(1));
        }
        vader_array_t* _a4_arr = vader_array_new(238u, 0u, 13u, 1591u);
        l5 = (void*) _a4_arr;
        t0 = l0.payload.obj;
        l8 = ((vader_struct_toolchain_ast$CallExpr_t*) t0)->f_type_args;
        l6 = ((vader_array_t*) l8)->length;
        l7 = INT64_C(0);
        while ((l7 < l6)) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            t1 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l7);
            l3 = vader_front_resolver$substitute_type_expr(t1, l1);
            vader_array_push_ref((vader_array_t*) l5, l3.payload.obj);
            l7 = (l7 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        l8 = ((vader_struct_toolchain_ast$CallExpr_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = vader_front_resolver$substitute_expr_full(((vader_struct_toolchain_ast$CallExpr_t*) t0)->f_callee, l1);
        vader_struct_toolchain_ast$CallExpr_t* _a6_obj = (vader_struct_toolchain_ast$CallExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$CallExpr_t));
        vader_obj_header_init(_a6_obj, 628u);
        _a6_obj->f_span = l8;
        _a6_obj->f_id = INT64_C(0);
        _a6_obj->f_callee = l3;
        _a6_obj->f_type_args = l5;
        _a6_obj->f_args = l2;
        _a6_obj->f_trailing_comma = false;
        t0 = (void*) _a6_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 648u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$FieldExpr_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = vader_front_resolver$substitute_expr_full(((vader_struct_toolchain_ast$FieldExpr_t*) t0)->f_target, l1);
        t0 = l0.payload.obj;
        l12 = ((vader_struct_toolchain_ast$FieldExpr_t*) t0)->f_field;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast$FieldExpr_t*) t0)->f_field_span;
        t0 = l0.payload.obj;
        l10 = ((vader_struct_toolchain_ast$FieldExpr_t*) t0)->f_is_numeric;
        vader_struct_toolchain_ast$FieldExpr_t* _a7_obj = (vader_struct_toolchain_ast$FieldExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$FieldExpr_t));
        vader_obj_header_init(_a7_obj, 648u);
        _a7_obj->f_span = l2;
        _a7_obj->f_id = INT64_C(0);
        _a7_obj->f_target = l3;
        _a7_obj->f_field = l12;
        _a7_obj->f_field_span = l5;
        _a7_obj->f_is_numeric = l10;
        t0 = (void*) _a7_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 663u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$IndexExpr_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = vader_front_resolver$substitute_expr_full(((vader_struct_toolchain_ast$IndexExpr_t*) t0)->f_target, l1);
        t0 = l0.payload.obj;
        l4 = vader_front_resolver$substitute_expr_full(((vader_struct_toolchain_ast$IndexExpr_t*) t0)->f_index, l1);
        vader_struct_toolchain_ast$IndexExpr_t* _a8_obj = (vader_struct_toolchain_ast$IndexExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$IndexExpr_t));
        vader_obj_header_init(_a8_obj, 663u);
        _a8_obj->f_span = l2;
        _a8_obj->f_id = INT64_C(0);
        _a8_obj->f_target = l3;
        _a8_obj->f_index = l4;
        t0 = (void*) _a8_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 704u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$UnaryExpr_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l13 = ((vader_struct_toolchain_ast$UnaryExpr_t*) t0)->f_op;
        t0 = l0.payload.obj;
        l3 = vader_front_resolver$substitute_expr_full(((vader_struct_toolchain_ast$UnaryExpr_t*) t0)->f_operand, l1);
        vader_struct_toolchain_ast$UnaryExpr_t* _a9_obj = (vader_struct_toolchain_ast$UnaryExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$UnaryExpr_t));
        vader_obj_header_init(_a9_obj, 704u);
        _a9_obj->f_span = l2;
        _a9_obj->f_id = INT64_C(0);
        _a9_obj->f_op = l13;
        _a9_obj->f_operand = l3;
        t0 = (void*) _a9_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 623u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$BinaryExpr_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l13 = ((vader_struct_toolchain_ast$BinaryExpr_t*) t0)->f_op;
        t0 = l0.payload.obj;
        l3 = vader_front_resolver$substitute_expr_full(((vader_struct_toolchain_ast$BinaryExpr_t*) t0)->f_left, l1);
        t0 = l0.payload.obj;
        l4 = vader_front_resolver$substitute_expr_full(((vader_struct_toolchain_ast$BinaryExpr_t*) t0)->f_right, l1);
        vader_struct_toolchain_ast$BinaryExpr_t* _a10_obj = (vader_struct_toolchain_ast$BinaryExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$BinaryExpr_t));
        vader_obj_header_init(_a10_obj, 623u);
        _a10_obj->f_span = l2;
        _a10_obj->f_id = INT64_C(0);
        _a10_obj->f_op = l13;
        _a10_obj->f_left = l3;
        _a10_obj->f_right = l4;
        t0 = (void*) _a10_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 658u) {
        l3 = vader_box_obj(0u, NULL);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_toolchain_ast$IfExpr_t*) t0)->f_else_branch;
        l14 = l4;
        if (!(l4.tag == 0u)) {
            if (l4.tag == 656u) {
                t0 = l14.payload.obj;
                t2 = vader_front_resolver$substitute_block(((vader_struct_toolchain_ast$IfElseBlock_t*) t0)->f_block, l1);
                vader_struct_toolchain_ast$IfElseBlock_t* _a11_obj = (vader_struct_toolchain_ast$IfElseBlock_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$IfElseBlock_t));
                vader_obj_header_init(_a11_obj, 656u);
                _a11_obj->f_block = t2;
                t0 = (void*) _a11_obj;
                l3 = vader_ref_box(t0);
            } else {
                if (!(l4.tag == 657u)) {
                    vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                }
                t0 = l14.payload.obj;
                l4 = vader_front_resolver$substitute_expr_full(vader_ref_box(((vader_struct_toolchain_ast$IfElseIf_t*) t0)->f_branch), l1);
                if (l4.tag == 658u) {
                    t0 = l4.payload.obj;
                    vader_struct_toolchain_ast$IfElseIf_t* _a12_obj = (vader_struct_toolchain_ast$IfElseIf_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$IfElseIf_t));
                    vader_obj_header_init(_a12_obj, 657u);
                    _a12_obj->f_branch = t0;
                    t0 = (void*) _a12_obj;
                    l3 = vader_ref_box(t0);
                }
            }
        }
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$IfExpr_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = vader_front_resolver$substitute_expr_full(((vader_struct_toolchain_ast$IfExpr_t*) t0)->f_cond, l1);
        t0 = l0.payload.obj;
        l5 = vader_front_resolver$substitute_block(((vader_struct_toolchain_ast$IfExpr_t*) t0)->f_then_block, l1);
        vader_struct_toolchain_ast$IfExpr_t* _a13_obj = (vader_struct_toolchain_ast$IfExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$IfExpr_t));
        vader_obj_header_init(_a13_obj, 658u);
        _a13_obj->f_span = l2;
        _a13_obj->f_id = INT64_C(0);
        _a13_obj->f_cond = l4;
        _a13_obj->f_then_block = l5;
        _a13_obj->f_else_branch = l3;
        t0 = (void*) _a13_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 672u) {
        vader_array_t* _a14_arr = vader_array_new(49u, 0u, 13u, 671u);
        l2 = (void*) _a14_arr;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast$MatchExpr_t*) t0)->f_arms;
        l6 = ((vader_array_t*) l5)->length;
        l7 = INT64_C(0);
        while ((l7 < l6)) {
            vader_array_t* _a15_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
            l8 = vader_array_ref_load_obj(_a15_slotarr->buf, _a15_slotarr->offset + (size_t) l7);
            l3 = vader_box_obj(0u, NULL);
            if (!(((vader_struct_toolchain_ast$MatchArm_t*) l8)->f_guard.tag == 0u)) {
                l3 = vader_front_resolver$substitute_expr_full(((vader_struct_toolchain_ast$MatchArm_t*) l8)->f_guard, l1);
            }
            l9 = ((vader_struct_toolchain_ast$MatchArm_t*) l8)->f_span;
            l4 = vader_front_resolver$substitute_pattern(((vader_struct_toolchain_ast$MatchArm_t*) l8)->f_pattern, l1);
            l14 = vader_front_resolver$substitute_expr_full(((vader_struct_toolchain_ast$MatchArm_t*) l8)->f_body, l1);
            vader_struct_toolchain_ast$MatchArm_t* _a16_obj = (vader_struct_toolchain_ast$MatchArm_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$MatchArm_t));
            vader_obj_header_init(_a16_obj, 671u);
            _a16_obj->f_span = l9;
            _a16_obj->f_id = INT64_C(0);
            _a16_obj->f_pattern = l4;
            _a16_obj->f_guard = l3;
            _a16_obj->f_body = l14;
            l11 = (void*) _a16_obj;
            vader_array_push_ref((vader_array_t*) l2, l11);
            l7 = (l7 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast$MatchExpr_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = vader_front_resolver$substitute_expr_full(((vader_struct_toolchain_ast$MatchExpr_t*) t0)->f_scrutinee, l1);
        t0 = l0.payload.obj;
        l10 = ((vader_struct_toolchain_ast$MatchExpr_t*) t0)->f_partial;
        t0 = l0.payload.obj;
        l15 = ((vader_struct_toolchain_ast$MatchExpr_t*) t0)->f_unreachable;
        t0 = l0.payload.obj;
        l4 = vader_front_resolver$clone_header_binding(((vader_struct_toolchain_ast$MatchExpr_t*) t0)->f_binding);
        vader_struct_toolchain_ast$MatchExpr_t* _a17_obj = (vader_struct_toolchain_ast$MatchExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$MatchExpr_t));
        vader_obj_header_init(_a17_obj, 672u);
        _a17_obj->f_span = l5;
        _a17_obj->f_id = INT64_C(0);
        _a17_obj->f_scrutinee = l3;
        _a17_obj->f_arms = l2;
        _a17_obj->f_partial = l10;
        _a17_obj->f_unreachable = l15;
        _a17_obj->f_binding = l4;
        t0 = (void*) _a17_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 624u) {
        t0 = l0.payload.obj;
        t2 = vader_front_resolver$substitute_block(t0, l1);
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 695u) {
        vader_array_t* _a18_arr = vader_array_new(246u, 0u, 13u, 1674u);
        l2 = (void*) _a18_arr;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast$StructLitExpr_t*) t0)->f_items;
        l6 = ((vader_array_t*) l5)->length;
        l7 = INT64_C(0);
        while ((l7 < l6)) {
            vader_array_t* _a19_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
            l3 = vader_array_ref_load_box(_a19_slotarr->buf, _a19_slotarr->offset + (size_t) l7);
            if (l3.tag == 696u) {
                t0 = l3.payload.obj;
                l8 = ((vader_struct_toolchain_ast$StructLitField_t*) t0)->f_span;
                t0 = l3.payload.obj;
                l12 = ((vader_struct_toolchain_ast$StructLitField_t*) t0)->f_name;
                t0 = l3.payload.obj;
                l9 = ((vader_struct_toolchain_ast$StructLitField_t*) t0)->f_name_span;
                t0 = l3.payload.obj;
                l4 = vader_front_resolver$substitute_expr_full(((vader_struct_toolchain_ast$StructLitField_t*) t0)->f_value, l1);
                vader_struct_toolchain_ast$StructLitField_t* _a20_obj = (vader_struct_toolchain_ast$StructLitField_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$StructLitField_t));
                vader_obj_header_init(_a20_obj, 696u);
                _a20_obj->f_span = l8;
                _a20_obj->f_id = INT64_C(0);
                _a20_obj->f_name = l12;
                _a20_obj->f_name_span = l9;
                _a20_obj->f_value = l4;
                l11 = (void*) _a20_obj;
                vader_array_push_ref((vader_array_t*) l2, l11);
            } else {
                if (!(l3.tag == 697u)) {
                    vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                }
                t0 = l3.payload.obj;
                l16 = ((vader_struct_toolchain_ast$StructLitSpread_t*) t0)->f_span;
                t0 = l3.payload.obj;
                l14 = vader_front_resolver$substitute_expr_full(((vader_struct_toolchain_ast$StructLitSpread_t*) t0)->f_expr, l1);
                vader_struct_toolchain_ast$StructLitSpread_t* _a21_obj = (vader_struct_toolchain_ast$StructLitSpread_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$StructLitSpread_t));
                vader_obj_header_init(_a21_obj, 697u);
                _a21_obj->f_span = l16;
                _a21_obj->f_id = INT64_C(0);
                _a21_obj->f_expr = l14;
                l17 = (void*) _a21_obj;
                vader_array_push_ref((vader_array_t*) l2, l17);
            }
            l7 = (l7 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast$StructLitExpr_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = vader_front_resolver$substitute_type_expr(((vader_struct_toolchain_ast$StructLitExpr_t*) t0)->f_type_name, l1);
        vader_struct_toolchain_ast$StructLitExpr_t* _a22_obj = (vader_struct_toolchain_ast$StructLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$StructLitExpr_t));
        vader_obj_header_init(_a22_obj, 695u);
        _a22_obj->f_span = l5;
        _a22_obj->f_id = INT64_C(0);
        _a22_obj->f_type_name = l3;
        _a22_obj->f_items = l2;
        _a22_obj->f_trailing_comma = false;
        t0 = (void*) _a22_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 688u) {
        vader_array_t* _a23_arr = vader_array_new(238u, 0u, 13u, 1591u);
        l2 = (void*) _a23_arr;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast$SeqLitExpr_t*) t0)->f_elements;
        l6 = ((vader_array_t*) l5)->length;
        l7 = INT64_C(0);
        while ((l7 < l6)) {
            vader_array_t* _a24_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a24_slotarr)
            t1 = vader_array_ref_load_box(_a24_slotarr->buf, _a24_slotarr->offset + (size_t) l7);
            l3 = vader_front_resolver$substitute_expr_full(t1, l1);
            vader_array_push_ref((vader_array_t*) l2, l3.payload.obj);
            l7 = (l7 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        vader_struct_toolchain_ast$SeqLitExpr_t* _a25_obj = (vader_struct_toolchain_ast$SeqLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$SeqLitExpr_t));
        vader_obj_header_init(_a25_obj, 688u);
        _a25_obj->f_span = ((vader_struct_toolchain_ast$SeqLitExpr_t*) t0)->f_span;
        _a25_obj->f_id = INT64_C(0);
        _a25_obj->f_elements = l2;
        _a25_obj->f_trailing_comma = false;
        t0 = (void*) _a25_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 683u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$RangeExpr_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l10 = ((vader_struct_toolchain_ast$RangeExpr_t*) t0)->f_inclusive;
        t0 = l0.payload.obj;
        l3 = vader_front_resolver$substitute_expr_full(((vader_struct_toolchain_ast$RangeExpr_t*) t0)->f_lower, l1);
        t0 = l0.payload.obj;
        l4 = vader_front_resolver$substitute_expr_full(((vader_struct_toolchain_ast$RangeExpr_t*) t0)->f_upper, l1);
        vader_struct_toolchain_ast$RangeExpr_t* _a26_obj = (vader_struct_toolchain_ast$RangeExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$RangeExpr_t));
        vader_obj_header_init(_a26_obj, 683u);
        _a26_obj->f_span = l2;
        _a26_obj->f_id = INT64_C(0);
        _a26_obj->f_inclusive = l10;
        _a26_obj->f_lower = l3;
        _a26_obj->f_upper = l4;
        t0 = (void*) _a26_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 622u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$AwaitExpr_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = vader_front_resolver$substitute_expr_full(((vader_struct_toolchain_ast$AwaitExpr_t*) t0)->f_inner, l1);
        vader_struct_toolchain_ast$AwaitExpr_t* _a27_obj = (vader_struct_toolchain_ast$AwaitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$AwaitExpr_t));
        vader_obj_header_init(_a27_obj, 622u);
        _a27_obj->f_span = l2;
        _a27_obj->f_id = INT64_C(0);
        _a27_obj->f_inner = l3;
        t0 = (void*) _a27_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 629u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$CastExpr_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = vader_front_resolver$substitute_type_expr(((vader_struct_toolchain_ast$CastExpr_t*) t0)->f_target, l1);
        t0 = l0.payload.obj;
        l4 = vader_front_resolver$substitute_expr_full(((vader_struct_toolchain_ast$CastExpr_t*) t0)->f_value, l1);
        vader_struct_toolchain_ast$CastExpr_t* _a28_obj = (vader_struct_toolchain_ast$CastExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$CastExpr_t));
        vader_obj_header_init(_a28_obj, 629u);
        _a28_obj->f_span = l2;
        _a28_obj->f_id = INT64_C(0);
        _a28_obj->f_target = l3;
        _a28_obj->f_value = l4;
        t0 = (void*) _a28_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 666u) {
        vader_array_t* _a29_arr = vader_array_new(238u, 0u, 13u, 1591u);
        l2 = (void*) _a29_arr;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) t0)->f_args;
        l6 = ((vader_array_t*) l5)->length;
        l7 = INT64_C(0);
        while ((l7 < l6)) {
            vader_array_t* _a30_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a30_slotarr)
            t1 = vader_array_ref_load_box(_a30_slotarr->buf, _a30_slotarr->offset + (size_t) l7);
            l3 = vader_front_resolver$substitute_expr_full(t1, l1);
            vader_array_push_ref((vader_array_t*) l2, l3.payload.obj);
            l7 = (l7 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l12 = ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) t0)->f_name;
        t0 = l0.payload.obj;
        l8 = ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) t0)->f_name_span;
        vader_struct_toolchain_ast$IntrinsicCallExpr_t* _a31_obj = (vader_struct_toolchain_ast$IntrinsicCallExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$IntrinsicCallExpr_t));
        vader_obj_header_init(_a31_obj, 666u);
        _a31_obj->f_span = l5;
        _a31_obj->f_id = INT64_C(0);
        _a31_obj->f_name = l12;
        _a31_obj->f_name_span = l8;
        _a31_obj->f_args = l2;
        _a31_obj->f_trailing_comma = false;
        t0 = (void*) _a31_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 643u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$DotVariantExpr_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l12 = ((vader_struct_toolchain_ast$DotVariantExpr_t*) t0)->f_variant;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast$DotVariantExpr_t*) t0)->f_variant_span;
        vader_struct_toolchain_ast$DotVariantExpr_t* _a32_obj = (vader_struct_toolchain_ast$DotVariantExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$DotVariantExpr_t));
        vader_obj_header_init(_a32_obj, 643u);
        _a32_obj->f_span = l2;
        _a32_obj->f_id = INT64_C(0);
        _a32_obj->f_variant = l12;
        _a32_obj->f_variant_span = l5;
        t0 = (void*) _a32_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 690u) {
        vader_array_t* _a33_arr = vader_array_new(245u, 0u, 13u, 1673u);
        l2 = (void*) _a33_arr;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast$StringLitExpr_t*) t0)->f_parts;
        l6 = ((vader_array_t*) l5)->length;
        l7 = INT64_C(0);
        while ((l7 < l6)) {
            vader_array_t* _a34_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a34_slotarr)
            l3 = vader_array_ref_load_box(_a34_slotarr->buf, _a34_slotarr->offset + (size_t) l7);
            if (l3.tag == 692u) {
                t0 = l3.payload.obj;
                l12 = ((vader_struct_toolchain_ast$StringLitText_t*) t0)->f_value;
                t0 = l3.payload.obj;
                l8 = ((vader_struct_toolchain_ast$StringLitText_t*) t0)->f_span;
                vader_struct_toolchain_ast$StringLitText_t* _a35_obj = (vader_struct_toolchain_ast$StringLitText_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$StringLitText_t));
                vader_obj_header_init(_a35_obj, 692u);
                _a35_obj->f_value = l12;
                _a35_obj->f_span = l8;
                _a35_obj->f_id = INT64_C(0);
                l9 = (void*) _a35_obj;
                vader_array_push_ref((vader_array_t*) l2, l9);
            } else {
                if (!(l3.tag == 691u)) {
                    vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                }
                t0 = l3.payload.obj;
                l4 = vader_front_resolver$substitute_expr_full(((vader_struct_toolchain_ast$StringLitInterp_t*) t0)->f_expr, l1);
                t0 = l3.payload.obj;
                l11 = ((vader_struct_toolchain_ast$StringLitInterp_t*) t0)->f_span;
                vader_struct_toolchain_ast$StringLitInterp_t* _a36_obj = (vader_struct_toolchain_ast$StringLitInterp_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$StringLitInterp_t));
                vader_obj_header_init(_a36_obj, 691u);
                _a36_obj->f_expr = l4;
                _a36_obj->f_span = l11;
                _a36_obj->f_id = INT64_C(0);
                l16 = (void*) _a36_obj;
                vader_array_push_ref((vader_array_t*) l2, l16);
            }
            l7 = (l7 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        vader_struct_toolchain_ast$StringLitExpr_t* _a37_obj = (vader_struct_toolchain_ast$StringLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$StringLitExpr_t));
        vader_obj_header_init(_a37_obj, 690u);
        _a37_obj->f_span = ((vader_struct_toolchain_ast$StringLitExpr_t*) t0)->f_span;
        _a37_obj->f_id = INT64_C(0);
        _a37_obj->f_parts = l2;
        t0 = (void*) _a37_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0.tag == 668u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    vader_array_t* _a38_arr = vader_array_new(46u, 0u, 13u, 651u);
    l2 = (void*) _a38_arr;
    t0 = l0.payload.obj;
    l5 = ((vader_struct_toolchain_ast$LambdaExpr_t*) t0)->f_params;
    l6 = ((vader_array_t*) l5)->length;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a39_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a39_slotarr)
        l8 = vader_array_ref_load_obj(_a39_slotarr->buf, _a39_slotarr->offset + (size_t) l7);
        l3 = vader_box_obj(0u, NULL);
        if (!(((vader_struct_toolchain_ast$FnParam_t*) l8)->f_ty.tag == 0u)) {
            l3 = vader_front_resolver$substitute_type_expr(((vader_struct_toolchain_ast$FnParam_t*) l8)->f_ty, l1);
        }
        l4 = vader_box_obj(0u, NULL);
        if (!(((vader_struct_toolchain_ast$FnParam_t*) l8)->f_default_value.tag == 0u)) {
            l4 = vader_front_resolver$substitute_expr_full(((vader_struct_toolchain_ast$FnParam_t*) l8)->f_default_value, l1);
        }
        l9 = ((vader_struct_toolchain_ast$FnParam_t*) l8)->f_span;
        l12 = ((vader_struct_toolchain_ast$FnParam_t*) l8)->f_name;
        l11 = ((vader_struct_toolchain_ast$FnParam_t*) l8)->f_name_span;
        l10 = ((vader_struct_toolchain_ast$FnParam_t*) l8)->f_variadic;
        l16 = ((vader_struct_toolchain_ast$FnParam_t*) l8)->f_decorators;
        vader_struct_toolchain_ast$FnParam_t* _a40_obj = (vader_struct_toolchain_ast$FnParam_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$FnParam_t));
        vader_obj_header_init(_a40_obj, 651u);
        _a40_obj->f_span = l9;
        _a40_obj->f_id = INT64_C(0);
        _a40_obj->f_name = l12;
        _a40_obj->f_name_span = l11;
        _a40_obj->f_ty = l3;
        _a40_obj->f_default_value = l4;
        _a40_obj->f_variadic = l10;
        _a40_obj->f_decorators = l16;
        l17 = (void*) _a40_obj;
        vader_array_push_ref((vader_array_t*) l2, l17);
        l7 = (l7 + INT64_C(1));
    }
    l3 = vader_box_obj(0u, NULL);
    t0 = l0.payload.obj;
    if (!(((vader_struct_toolchain_ast$LambdaExpr_t*) t0)->f_return_type.tag == 0u)) {
        t0 = l0.payload.obj;
        l3 = vader_front_resolver$substitute_type_expr(((vader_struct_toolchain_ast$LambdaExpr_t*) t0)->f_return_type, l1);
    }
    t0 = l0.payload.obj;
    l5 = ((vader_struct_toolchain_ast$LambdaExpr_t*) t0)->f_span;
    t0 = l0.payload.obj;
    l8 = vader_front_resolver$substitute_block(((vader_struct_toolchain_ast$LambdaExpr_t*) t0)->f_body, l1);
    vader_struct_toolchain_ast$LambdaExpr_t* _a41_obj = (vader_struct_toolchain_ast$LambdaExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$LambdaExpr_t));
    vader_obj_header_init(_a41_obj, 668u);
    _a41_obj->f_span = l5;
    _a41_obj->f_id = INT64_C(0);
    _a41_obj->f_params = l2;
    _a41_obj->f_return_type = l3;
    _a41_obj->f_body = l8;
    _a41_obj->f_trailing_comma = false;
    t0 = (void*) _a41_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_resolver$substitute_opt_type(vader_box_t l0, void* l1) {
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &t0 };
    void** gc_raw_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(l0.tag == 0u)) {
        t0 = vader_front_resolver$substitute_type_expr(l0, l1);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static void* vader_front_resolver$substitute_params(void* l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l10 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    int64_t l3, l5;
    vader_string_t l9 = 0;
    vader_box_t l11 = vader_box_null(), l12 = vader_box_null();
    bool l13;
    vader_box_t* gc_roots[2] = { &l11, &l12 };
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l4, &l6, &l7, &l8, &l10, &l14, &l15 };
    vader_string_t* gc_atom_roots[1] = { &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(46u, 0u, 13u, 651u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_array_t*) l0)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a1_arr;
    l4 = l0;
    l3 = ((vader_array_t*) l4)->length;
    l5 = INT64_C(0);
    while ((l5 < l3)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l6 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
        l7 = l6;
        l8 = ((vader_struct_toolchain_ast$FnParam_t*) l7)->f_span;
        l9 = ((vader_struct_toolchain_ast$FnParam_t*) l7)->f_name;
        l10 = ((vader_struct_toolchain_ast$FnParam_t*) l7)->f_name_span;
        l11 = vader_front_resolver$substitute_opt_type(((vader_struct_toolchain_ast$FnParam_t*) l6)->f_ty, l1);
        l12 = ((vader_struct_toolchain_ast$FnParam_t*) l7)->f_default_value;
        l13 = ((vader_struct_toolchain_ast$FnParam_t*) l7)->f_variadic;
        l14 = ((vader_struct_toolchain_ast$FnParam_t*) l7)->f_decorators;
        vader_struct_toolchain_ast$FnParam_t* _a3_obj = (vader_struct_toolchain_ast$FnParam_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$FnParam_t));
        vader_obj_header_init(_a3_obj, 651u);
        _a3_obj->f_span = l8;
        _a3_obj->f_id = INT64_C(0);
        _a3_obj->f_name = l9;
        _a3_obj->f_name_span = l10;
        _a3_obj->f_ty = l11;
        _a3_obj->f_default_value = l12;
        _a3_obj->f_variadic = l13;
        _a3_obj->f_decorators = l14;
        l15 = (void*) _a3_obj;
        vader_array_push_ref((vader_array_t*) l2, l15);
        l5 = (l5 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$substitute_params_disambiguated(void* l0, void* l1, void* l2, void* l3) {
    void* l4 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l12 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    int64_t l5, l7;
    vader_string_t l11 = 0;
    vader_box_t l13 = vader_box_null(), l14 = vader_box_null();
    bool l15;
    vader_string_t t0 = 0;
    vader_box_t* gc_roots[2] = { &l13, &l14 };
    void** gc_raw_roots[12] = { &l0, &l1, &l2, &l3, &l4, &l6, &l8, &l9, &l10, &l12, &l16, &l17 };
    vader_string_t* gc_atom_roots[2] = { &l11, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(46u, 0u, 13u, 651u);
    l4 = (void*) _a0_arr;
    l5 = ((vader_array_t*) l0)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l4, (int64_t) l5);
    l4 = (void*) _a1_arr;
    l6 = l0;
    l5 = ((vader_array_t*) l6)->length;
    l7 = INT64_C(0);
    while ((l7 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l8 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l7);
        t0 = ((vader_struct_toolchain_ast$FnParam_t*) l8)->f_name;
        if (t0 == 2547u) {
            l9 = l2;
        } else {
            l9 = vader_front_resolver$synth_clone_span(l3);
        }
        l10 = l8;
        l11 = ((vader_struct_toolchain_ast$FnParam_t*) l10)->f_name;
        l12 = toolchain_span$empty_span();
        l13 = vader_front_resolver$substitute_opt_type(((vader_struct_toolchain_ast$FnParam_t*) l8)->f_ty, l1);
        l14 = ((vader_struct_toolchain_ast$FnParam_t*) l10)->f_default_value;
        l15 = ((vader_struct_toolchain_ast$FnParam_t*) l10)->f_variadic;
        l16 = ((vader_struct_toolchain_ast$FnParam_t*) l10)->f_decorators;
        vader_struct_toolchain_ast$FnParam_t* _a3_obj = (vader_struct_toolchain_ast$FnParam_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$FnParam_t));
        vader_obj_header_init(_a3_obj, 651u);
        _a3_obj->f_span = l9;
        _a3_obj->f_id = INT64_C(0);
        _a3_obj->f_name = l11;
        _a3_obj->f_name_span = l12;
        _a3_obj->f_ty = l13;
        _a3_obj->f_default_value = l14;
        _a3_obj->f_variadic = l15;
        _a3_obj->f_decorators = l16;
        l17 = (void*) _a3_obj;
        vader_array_push_ref((vader_array_t*) l4, l17);
        l7 = (l7 + INT64_C(1));
    }
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$substitute_params_stamped(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l5 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l11 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    int64_t l4, l6;
    vader_string_t l10 = 0;
    vader_box_t l12 = vader_box_null(), l13 = vader_box_null();
    bool l14;
    vader_box_t* gc_roots[2] = { &l12, &l13 };
    void** gc_raw_roots[11] = { &l0, &l1, &l2, &l3, &l5, &l7, &l8, &l9, &l11, &l15, &l16 };
    vader_string_t* gc_atom_roots[1] = { &l10 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 11u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(46u, 0u, 13u, 651u);
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
        l8 = l7;
        l9 = vader_front_resolver$next_clone_span(l2);
        l10 = ((vader_struct_toolchain_ast$FnParam_t*) l8)->f_name;
        l11 = toolchain_span$empty_span();
        l12 = vader_front_resolver$substitute_opt_type(((vader_struct_toolchain_ast$FnParam_t*) l7)->f_ty, l1);
        l13 = ((vader_struct_toolchain_ast$FnParam_t*) l8)->f_default_value;
        l14 = ((vader_struct_toolchain_ast$FnParam_t*) l8)->f_variadic;
        l15 = ((vader_struct_toolchain_ast$FnParam_t*) l8)->f_decorators;
        vader_struct_toolchain_ast$FnParam_t* _a3_obj = (vader_struct_toolchain_ast$FnParam_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$FnParam_t));
        vader_obj_header_init(_a3_obj, 651u);
        _a3_obj->f_span = l9;
        _a3_obj->f_id = INT64_C(0);
        _a3_obj->f_name = l10;
        _a3_obj->f_name_span = l11;
        _a3_obj->f_ty = l12;
        _a3_obj->f_default_value = l13;
        _a3_obj->f_variadic = l14;
        _a3_obj->f_decorators = l15;
        l16 = (void*) _a3_obj;
        vader_array_push_ref((vader_array_t*) l3, l16);
        l6 = (l6 + INT64_C(1));
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_resolver$substitute_pattern(vader_box_t l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l4 = vader_box_null();
    void* l3 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[3] = { &l0, &l2, &l4 };
    void** gc_raw_roots[3] = { &l1, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(l0.tag == 667u)) {
        { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = vader_box_obj(0u, NULL);
    t0 = l0.payload.obj;
    if (!(((vader_struct_toolchain_ast$IsPattern_t*) t0)->f_inner.tag == 0u)) {
        t0 = l0.payload.obj;
        l2 = vader_front_resolver$substitute_pattern(((vader_struct_toolchain_ast$IsPattern_t*) t0)->f_inner, l1);
    }
    t0 = l0.payload.obj;
    l3 = ((vader_struct_toolchain_ast$IsPattern_t*) t0)->f_span;
    t0 = l0.payload.obj;
    l4 = vader_front_resolver$substitute_type_expr(((vader_struct_toolchain_ast$IsPattern_t*) t0)->f_ty, l1);
    vader_struct_toolchain_ast$IsPattern_t* _a0_obj = (vader_struct_toolchain_ast$IsPattern_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$IsPattern_t));
    vader_obj_header_init(_a0_obj, 667u);
    _a0_obj->f_span = l3;
    _a0_obj->f_id = INT64_C(0);
    _a0_obj->f_ty = l4;
    _a0_obj->f_inner = l2;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_resolver$substitute_stmt(vader_box_t l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l5 = vader_box_null(), l6 = vader_box_null(), l13 = vader_box_null();
    void* l3 = NULL;
    void* l7 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    bool l4;
    int64_t l8, l9;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[6] = { &l0, &l2, &l5, &l6, &l13, &t1 };
    void** gc_raw_roots[7] = { &l1, &l3, &l7, &l10, &l11, &l12, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 6u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 669u) {
        l2 = vader_box_obj(0u, NULL);
        t0 = l0.payload.obj;
        if (!(((vader_struct_toolchain_ast$LetStmt_t*) t0)->f_ty.tag == 0u)) {
            t0 = l0.payload.obj;
            l2 = vader_front_resolver$substitute_type_expr(((vader_struct_toolchain_ast$LetStmt_t*) t0)->f_ty, l1);
        }
        t0 = l0.payload.obj;
        l3 = ((vader_struct_toolchain_ast$LetStmt_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_toolchain_ast$LetStmt_t*) t0)->f_mutable;
        t0 = l0.payload.obj;
        l5 = vader_front_resolver$clone_let_binding(((vader_struct_toolchain_ast$LetStmt_t*) t0)->f_binding);
        t0 = l0.payload.obj;
        l6 = vader_front_resolver$substitute_expr_full(((vader_struct_toolchain_ast$LetStmt_t*) t0)->f_value, l1);
        vader_struct_toolchain_ast$LetStmt_t* _a0_obj = (vader_struct_toolchain_ast$LetStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$LetStmt_t));
        vader_obj_header_init(_a0_obj, 669u);
        _a0_obj->f_span = l3;
        _a0_obj->f_id = INT64_C(0);
        _a0_obj->f_mutable = l4;
        _a0_obj->f_binding = l5;
        _a0_obj->f_ty = l2;
        _a0_obj->f_value = l6;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 647u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_toolchain_ast$ExprStmt_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l2 = vader_front_resolver$substitute_expr_full(((vader_struct_toolchain_ast$ExprStmt_t*) t0)->f_expr, l1);
        vader_struct_toolchain_ast$ExprStmt_t* _a1_obj = (vader_struct_toolchain_ast$ExprStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$ExprStmt_t));
        vader_obj_header_init(_a1_obj, 647u);
        _a1_obj->f_span = l3;
        _a1_obj->f_id = INT64_C(0);
        _a1_obj->f_expr = l2;
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 687u) {
        l2 = vader_box_obj(0u, NULL);
        t0 = l0.payload.obj;
        if (!(((vader_struct_toolchain_ast$ReturnStmt_t*) t0)->f_value.tag == 0u)) {
            t0 = l0.payload.obj;
            l2 = vader_front_resolver$substitute_expr_full(((vader_struct_toolchain_ast$ReturnStmt_t*) t0)->f_value, l1);
        }
        t0 = l0.payload.obj;
        vader_struct_toolchain_ast$ReturnStmt_t* _a2_obj = (vader_struct_toolchain_ast$ReturnStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$ReturnStmt_t));
        vader_obj_header_init(_a2_obj, 687u);
        _a2_obj->f_span = ((vader_struct_toolchain_ast$ReturnStmt_t*) t0)->f_span;
        _a2_obj->f_id = INT64_C(0);
        _a2_obj->f_value = l2;
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 621u) {
        t0 = l0.payload.obj;
        l2 = vader_front_resolver$substitute_expr_full(((vader_struct_toolchain_ast$AssignStmt_t*) t0)->f_target, l1);
        t0 = l0.payload.obj;
        l3 = ((vader_struct_toolchain_ast$AssignStmt_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l5 = vader_front_resolver$clone_assign_value(t0, l2, l1);
        vader_struct_toolchain_ast$AssignStmt_t* _a3_obj = (vader_struct_toolchain_ast$AssignStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$AssignStmt_t));
        vader_obj_header_init(_a3_obj, 621u);
        _a3_obj->f_span = l3;
        _a3_obj->f_id = INT64_C(0);
        _a3_obj->f_target = l2;
        _a3_obj->f_value = l5;
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 637u) {
        vader_array_t* _a4_arr = vader_array_new(243u, 0u, 13u, 1668u);
        l3 = (void*) _a4_arr;
        t0 = l0.payload.obj;
        l7 = ((vader_struct_toolchain_ast$DestructureAssignStmt_t*) t0)->f_targets;
        l8 = ((vader_array_t*) l7)->length;
        l9 = INT64_C(0);
        while ((l9 < l8)) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            l2 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l9);
            if (l2.tag == 681u) {
                t0 = l2.payload.obj;
                l5 = vader_front_resolver$substitute_expr_full(((vader_struct_toolchain_ast$PlaceTarget_t*) t0)->f_place, l1);
                t0 = l2.payload.obj;
                vader_struct_toolchain_ast$PlaceTarget_t* _a6_obj = (vader_struct_toolchain_ast$PlaceTarget_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$PlaceTarget_t));
                vader_obj_header_init(_a6_obj, 681u);
                _a6_obj->f_span = ((vader_struct_toolchain_ast$PlaceTarget_t*) t0)->f_span;
                _a6_obj->f_id = INT64_C(0);
                _a6_obj->f_place = l5;
                l10 = (void*) _a6_obj;
                vader_array_push_ref((vader_array_t*) l3, l10);
            } else if (l2.tag == 686u) {
                t0 = l2.payload.obj;
                l6 = vader_front_resolver$substitute_expr_full(((vader_struct_toolchain_ast$RestTarget_t*) t0)->f_place, l1);
                t0 = l2.payload.obj;
                vader_struct_toolchain_ast$RestTarget_t* _a7_obj = (vader_struct_toolchain_ast$RestTarget_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$RestTarget_t));
                vader_obj_header_init(_a7_obj, 686u);
                _a7_obj->f_span = ((vader_struct_toolchain_ast$RestTarget_t*) t0)->f_span;
                _a7_obj->f_id = INT64_C(0);
                _a7_obj->f_place = l6;
                l11 = (void*) _a7_obj;
                vader_array_push_ref((vader_array_t*) l3, l11);
            } else {
                if (!(l2.tag == 709u)) {
                    vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                }
                t0 = l2.payload.obj;
                vader_struct_toolchain_ast$WildcardTarget_t* _a8_obj = (vader_struct_toolchain_ast$WildcardTarget_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$WildcardTarget_t));
                vader_obj_header_init(_a8_obj, 709u);
                _a8_obj->f_span = ((vader_struct_toolchain_ast$WildcardTarget_t*) t0)->f_span;
                _a8_obj->f_id = INT64_C(0);
                l12 = (void*) _a8_obj;
                vader_array_push_ref((vader_array_t*) l3, l12);
            }
            l9 = (l9 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        l7 = ((vader_struct_toolchain_ast$DestructureAssignStmt_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l2 = vader_front_resolver$substitute_expr_full(((vader_struct_toolchain_ast$DestructureAssignStmt_t*) t0)->f_value, l1);
        vader_struct_toolchain_ast$DestructureAssignStmt_t* _a9_obj = (vader_struct_toolchain_ast$DestructureAssignStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$DestructureAssignStmt_t));
        vader_obj_header_init(_a9_obj, 637u);
        _a9_obj->f_span = l7;
        _a9_obj->f_id = INT64_C(0);
        _a9_obj->f_targets = l3;
        _a9_obj->f_value = l2;
        t0 = (void*) _a9_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 653u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$ForStmt_t*) t0)->f_form;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast$ForStmt_t*) t0)->f_form;
        l6 = l5;
        if (l5.tag == 705u) {
            t0 = l6.payload.obj;
            t1 = vader_front_resolver$substitute_expr_full(((vader_struct_toolchain_ast$WhileFor_t*) t0)->f_cond, l1);
            vader_struct_toolchain_ast$WhileFor_t* _a10_obj = (vader_struct_toolchain_ast$WhileFor_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$WhileFor_t));
            vader_obj_header_init(_a10_obj, 705u);
            _a10_obj->f_cond = t1;
            t0 = (void*) _a10_obj;
            l2 = vader_ref_box(t0);
        } else if (l5.tag == 662u) {
            t0 = l6.payload.obj;
            l13 = ((vader_struct_toolchain_ast$InFor_t*) t0)->f_loop_var;
            t0 = l6.payload.obj;
            l6 = vader_front_resolver$substitute_expr_full(((vader_struct_toolchain_ast$InFor_t*) t0)->f_iter, l1);
            vader_struct_toolchain_ast$InFor_t* _a11_obj = (vader_struct_toolchain_ast$InFor_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$InFor_t));
            vader_obj_header_init(_a11_obj, 662u);
            _a11_obj->f_loop_var = l13;
            _a11_obj->f_iter = l6;
            t0 = (void*) _a11_obj;
            l2 = vader_ref_box(t0);
        } else if (!(l5.tag == 664u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = l0.payload.obj;
        l3 = ((vader_struct_toolchain_ast$ForStmt_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast$ForStmt_t*) t0)->f_label;
        t0 = l0.payload.obj;
        l7 = vader_front_resolver$substitute_block(((vader_struct_toolchain_ast$ForStmt_t*) t0)->f_body, l1);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_toolchain_ast$ForStmt_t*) t0)->f_is_comptime;
        vader_struct_toolchain_ast$ForStmt_t* _a12_obj = (vader_struct_toolchain_ast$ForStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$ForStmt_t));
        vader_obj_header_init(_a12_obj, 653u);
        _a12_obj->f_span = l3;
        _a12_obj->f_id = INT64_C(0);
        _a12_obj->f_label = l5;
        _a12_obj->f_form = l2;
        _a12_obj->f_body = l7;
        _a12_obj->f_is_comptime = l4;
        t0 = (void*) _a12_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 626u) {
        t0 = l0.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0.tag == 632u)) {
        { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l0.payload.obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_resolver$substitute_type_expr(vader_box_t l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l6 = vader_box_null();
    vader_string_t l3 = 0;
    void* l4 = NULL;
    void* l7 = NULL;
    uint8_t l5;
    int64_t l8, l9;
    void* t0 = NULL;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l0, &l2, &l6, &t2 };
    void** gc_raw_roots[5] = { &l1, &l4, &l7, &t0, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 655u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_toolchain_ast$IdentExpr_t*) t0)->f_name;
        l2 = vader_front_resolver$lookup_subst(l1, l3);
        if (l2.tag == 0u) {
            t0 = l0.payload.obj;
            t1 = vader_front_resolver$clone_ident(t0);
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l4 = vader_front_resolver$new_subst();
        t2 = vader_front_resolver$substitute_type_expr(l2, l4);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 623u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_toolchain_ast$BinaryExpr_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast$BinaryExpr_t*) t0)->f_op;
        t0 = l0.payload.obj;
        l2 = vader_front_resolver$substitute_type_expr(((vader_struct_toolchain_ast$BinaryExpr_t*) t0)->f_left, l1);
        t0 = l0.payload.obj;
        l6 = vader_front_resolver$substitute_type_expr(((vader_struct_toolchain_ast$BinaryExpr_t*) t0)->f_right, l1);
        vader_struct_toolchain_ast$BinaryExpr_t* _a0_obj = (vader_struct_toolchain_ast$BinaryExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$BinaryExpr_t));
        vader_obj_header_init(_a0_obj, 623u);
        _a0_obj->f_span = l4;
        _a0_obj->f_id = INT64_C(0);
        _a0_obj->f_op = l5;
        _a0_obj->f_left = l2;
        _a0_obj->f_right = l6;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 652u) {
        vader_array_t* _a1_arr = vader_array_new(238u, 0u, 13u, 1591u);
        l4 = (void*) _a1_arr;
        t0 = l0.payload.obj;
        l7 = ((vader_struct_toolchain_ast$FnTypeExpr_t*) t0)->f_params;
        l8 = ((vader_array_t*) l7)->length;
        l9 = INT64_C(0);
        while ((l9 < l8)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            t2 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l9);
            l2 = vader_front_resolver$substitute_type_expr(t2, l1);
            vader_array_push_ref((vader_array_t*) l4, l2.payload.obj);
            l9 = (l9 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$FnTypeExpr_t*) t0)->f_return_type;
        l6 = vader_box_obj(0u, NULL);
        if (!(l2.tag == 0u)) {
            l6 = vader_front_resolver$substitute_type_expr(l2, l1);
        }
        t0 = l0.payload.obj;
        vader_struct_toolchain_ast$FnTypeExpr_t* _a3_obj = (vader_struct_toolchain_ast$FnTypeExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$FnTypeExpr_t));
        vader_obj_header_init(_a3_obj, 652u);
        _a3_obj->f_span = ((vader_struct_toolchain_ast$FnTypeExpr_t*) t0)->f_span;
        _a3_obj->f_id = INT64_C(0);
        _a3_obj->f_params = l4;
        _a3_obj->f_return_type = l6;
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 619u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_toolchain_ast$ArrayTypeExpr_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l2 = vader_front_resolver$substitute_type_expr(((vader_struct_toolchain_ast$ArrayTypeExpr_t*) t0)->f_element, l1);
        vader_struct_toolchain_ast$ArrayTypeExpr_t* _a4_obj = (vader_struct_toolchain_ast$ArrayTypeExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$ArrayTypeExpr_t));
        vader_obj_header_init(_a4_obj, 619u);
        _a4_obj->f_span = l4;
        _a4_obj->f_id = INT64_C(0);
        _a4_obj->f_element = l2;
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 688u) {
        vader_array_t* _a5_arr = vader_array_new(238u, 0u, 13u, 1591u);
        l4 = (void*) _a5_arr;
        t0 = l0.payload.obj;
        l7 = ((vader_struct_toolchain_ast$SeqLitExpr_t*) t0)->f_elements;
        l8 = ((vader_array_t*) l7)->length;
        l9 = INT64_C(0);
        while ((l9 < l8)) {
            vader_array_t* _a6_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            t2 = vader_array_ref_load_box(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l9);
            l2 = vader_front_resolver$substitute_type_expr(t2, l1);
            vader_array_push_ref((vader_array_t*) l4, l2.payload.obj);
            l9 = (l9 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        vader_struct_toolchain_ast$SeqLitExpr_t* _a7_obj = (vader_struct_toolchain_ast$SeqLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$SeqLitExpr_t));
        vader_obj_header_init(_a7_obj, 688u);
        _a7_obj->f_span = ((vader_struct_toolchain_ast$SeqLitExpr_t*) t0)->f_span;
        _a7_obj->f_id = INT64_C(0);
        _a7_obj->f_elements = l4;
        _a7_obj->f_trailing_comma = false;
        t0 = (void*) _a7_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0.tag == 654u)) {
        { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a8_arr = vader_array_new(238u, 0u, 13u, 1591u);
    l4 = (void*) _a8_arr;
    t0 = l0.payload.obj;
    l7 = ((vader_struct_toolchain_ast$GenericInstExpr_t*) t0)->f_type_args;
    l8 = ((vader_array_t*) l7)->length;
    l9 = INT64_C(0);
    while ((l9 < l8)) {
        vader_array_t* _a9_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        t2 = vader_array_ref_load_box(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l9);
        l2 = vader_front_resolver$substitute_type_expr(t2, l1);
        vader_array_push_ref((vader_array_t*) l4, l2.payload.obj);
        l9 = (l9 + INT64_C(1));
    }
    t0 = l0.payload.obj;
    l7 = ((vader_struct_toolchain_ast$GenericInstExpr_t*) t0)->f_span;
    t0 = l0.payload.obj;
    l2 = ((vader_struct_toolchain_ast$GenericInstExpr_t*) t0)->f_callee;
    vader_struct_toolchain_ast$GenericInstExpr_t* _a10_obj = (vader_struct_toolchain_ast$GenericInstExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$GenericInstExpr_t));
    vader_obj_header_init(_a10_obj, 654u);
    _a10_obj->f_span = l7;
    _a10_obj->f_id = INT64_C(0);
    _a10_obj->f_callee = l2;
    _a10_obj->f_type_args = l4;
    t0 = (void*) _a10_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$swap_root(void* l0, void* l1) {
    void* l2;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_front_resolver$Scope_t*) l0)->f_frames);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
    l2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
    vader_array_ref_store(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0), l1);
    VADER_WRITE_BARRIER(_a0_slotarr->buf);
    return l2;
}

vader_box_t vader_front_resolver$symbol_declared_at(void* l0, void* l1) {
    void* l2;
    uint64_t l3;
    vader_box_t t0;
    l2 = ((vader_struct_vader_front_resolver$ResolvedModule_t*) l0)->f_declarations;
    l3 = toolchain_span$Span$std_core$Hash$hash(l1);
    t0 = std_collections$MutableMap$std_core$Index$at__u64__Any(l2, l3);
    return t0;
}

static void* vader_front_resolver$synth_clone_span(void* l0) {
    int32_t l1;
    void* l2 = NULL;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[3] = { &l0, &l2, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_front_parser$mint(l0);
    l1 = ((int32_t) (int64_t) t0);
    vader_struct_toolchain_span$Position_t* _a0_obj = (vader_struct_toolchain_span$Position_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Position_t));
    vader_obj_header_init(_a0_obj, 711u);
    _a0_obj->f_file = 0u;
    _a0_obj->f_offset = INT64_C(0);
    _a0_obj->f_line = INT32_C(0);
    _a0_obj->f_column = l1;
    l2 = (void*) _a0_obj;
    vader_struct_toolchain_span$Span_t* _a1_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
    vader_obj_header_init(_a1_obj, 712u);
    _a1_obj->f_start = l2;
    _a1_obj->f_end = l2;
    t1 = (void*) _a1_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$synth_signature(void* l0, void* l1, void* l2, void* l3, int64_t l4) {
    void* l5 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    vader_string_t l6 = 0;
    vader_box_t l9 = vader_box_null(), l11 = vader_box_null();
    bool l10;
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l9, &l11 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l5, &l7, &l8, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l5 = ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_span;
    l6 = ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_name;
    vader_array_t* _a0_arr = vader_array_new(56u, 0u, 13u, 703u);
    l7 = (void*) _a0_arr;
    l8 = vader_front_resolver$substitute_params(((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_params, l2);
    l9 = vader_front_resolver$substitute_opt_type(((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_return_type, l2);
    l10 = ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_is_expression_bodied;
    l11 = ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_doc;
    vader_struct_toolchain_ast$FnDecl_t* _a1_obj = (vader_struct_toolchain_ast$FnDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$FnDecl_t));
    vader_obj_header_init(_a1_obj, 650u);
    _a1_obj->f_span = l5;
    _a1_obj->f_id = l4;
    _a1_obj->f_name = l6;
    _a1_obj->f_name_span = l1;
    _a1_obj->f_visibility = (uint8_t) 0;
    _a1_obj->f_type_params = l7;
    _a1_obj->f_params = l8;
    _a1_obj->f_return_type = l9;
    _a1_obj->f_body = vader_box_obj(0u, NULL);
    _a1_obj->f_decorators = l3;
    _a1_obj->f_sam_synthetic = false;
    _a1_obj->f_is_expression_bodied = l10;
    _a1_obj->f_materialized = true;
    _a1_obj->f_comptime_synthetic = false;
    _a1_obj->f_trailing_comma = false;
    _a1_obj->f_doc = l11;
    t0 = (void*) _a1_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$synth_with_body(void* l0, void* l1, void* l2, void* l3, void* l4, int64_t l5) {
    void* l6 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    vader_string_t l7 = 0;
    vader_box_t l11 = vader_box_null(), l13 = vader_box_null();
    bool l12;
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l11, &l13 };
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l4, &l6, &l8, &l9, &l10, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l6 = ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_span;
    l7 = ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_name;
    l8 = vader_front_resolver$next_clone_span(l4);
    vader_array_t* _a0_arr = vader_array_new(56u, 0u, 13u, 703u);
    l9 = (void*) _a0_arr;
    l10 = vader_front_resolver$substitute_params_stamped(((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_params, l1, l4);
    l11 = vader_front_resolver$substitute_opt_type(((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_return_type, l1);
    l12 = ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_is_expression_bodied;
    l13 = ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_doc;
    vader_struct_toolchain_ast$FnDecl_t* _a1_obj = (vader_struct_toolchain_ast$FnDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$FnDecl_t));
    vader_obj_header_init(_a1_obj, 650u);
    _a1_obj->f_span = l6;
    _a1_obj->f_id = l5;
    _a1_obj->f_name = l7;
    _a1_obj->f_name_span = l8;
    _a1_obj->f_visibility = (uint8_t) 0;
    _a1_obj->f_type_params = l9;
    _a1_obj->f_params = l10;
    _a1_obj->f_return_type = l11;
    _a1_obj->f_body = vader_ref_box(l3);
    _a1_obj->f_decorators = l2;
    _a1_obj->f_sam_synthetic = false;
    _a1_obj->f_is_expression_bodied = l12;
    _a1_obj->f_materialized = true;
    _a1_obj->f_comptime_synthetic = false;
    _a1_obj->f_trailing_comma = false;
    _a1_obj->f_doc = l13;
    t0 = (void*) _a1_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$target_declarations(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l5 = NULL;
    void* l9 = NULL;
    int64_t l3, l4, l6, l7;
    vader_box_t l8 = vader_box_null();
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l8, &t1 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l5, &l9, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(45u, 0u, 13u, 650u);
    l1 = (void*) _a0_arr;
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        l5 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) t0)->f_program)->f_decls;
        l6 = ((vader_array_t*) l5)->length;
        l7 = INT64_C(0);
        while ((l7 < l6)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            l8 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l7);
            if (l8.tag == 650u) {
                t0 = l8.payload.obj;
                t1 = vader_front_resolver$target_selectors(((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_decorators);
                if (!(t1.tag == 0u)) {
                    l9 = l8.payload.obj;
                    vader_array_push_ref((vader_array_t*) l1, l9);
                }
            }
            l7 = (l7 + INT64_C(1));
        }
        l4 = (l4 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_resolver$target_selectors(void* l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    int64_t l2, l3, l7, l8;
    vader_box_t l9 = vader_box_null(), l10 = vader_box_null();
    uint8_t l11;
    bool l12;
    vader_string_t t0 = 0;
    vader_string_t t2 = 0;
    void* t1 = NULL;
    int64_t t3;
    vader_box_t* gc_roots[2] = { &l9, &l10 };
    void** gc_raw_roots[6] = { &l0, &l1, &l4, &l5, &l6, &t1 };
    vader_string_t* gc_atom_roots[2] = { &t0, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = l0;
    l2 = ((vader_array_t*) l1)->length;
    l3 = INT64_C(0);
    for (;;) {
        if ((l3 < l2)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
            t0 = ((vader_struct_toolchain_ast$Decorator_t*) l4)->f_name;
            if (t0 != 2698u) {
                l3 = (l3 + INT64_C(1));
                continue;
            }
            vader_array_t* _a1_arr = vader_array_new(24u, 0u, 1u, 340u);
            l5 = (void*) _a1_arr;
            l6 = ((vader_struct_toolchain_ast$Decorator_t*) l4)->f_args;
            l7 = ((vader_array_t*) l6)->length;
            l8 = INT64_C(0);
            while ((l8 < l7)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                l9 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l8);
                if (l9.tag == 643u) {
                    t1 = l9.payload.obj;
                    t0 = ((vader_struct_toolchain_ast$DotVariantExpr_t*) t1)->f_variant;
                    t2 = std_string$to_lower(t0);
                    l10 = vader_support_target$parse_os(t2);
                    if (!(l10.tag == 0u)) {
                        l11 = ((uint8_t) l10.payload.i);
                        vader_array_push_u8((vader_array_t*) l5, (int32_t) (uint8_t) l11);
                    }
                }
                l8 = (l8 + INT64_C(1));
            }
            t3 = ((vader_array_t*) ((vader_struct_toolchain_ast$Decorator_t*) l4)->f_args)->length;
            l12 = t3 == INT64_C(0);
            vader_struct_vader_front_resolver$TargetSelectors_t* _a3_obj = (vader_struct_vader_front_resolver$TargetSelectors_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$TargetSelectors_t));
            vader_obj_header_init(_a3_obj, 1110u);
            _a3_obj->f_os = l5;
            _a3_obj->f_is_bare = l12;
            t1 = (void*) _a3_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        break;
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_string_t vader_front_resolver$toolchain_base(void) {
    vader_string_t l0 = 0;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_string_t t2 = 0;
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[3] = { &l0, &t1, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_front_resolver$registered_toolchain();
    l0 = ((vader_struct_vader_front_resolver$ToolchainFolder_t*) t0)->f_path;
    if (!(l0 != 0u)) {
        t1 = std_io$current_executable_location();
        t2 = vader_front_resolver$dir_of(t1);
        { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_string_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_front_resolver$toolchain_folder(vader_box_t l0) {
    vader_string_t t0, t1;
    if (!(l0.tag == 0u)) {
        t0 = l0.payload.s;
        t1 = vader_front_resolver$dir_of(t0);
        return t1;
    }
    return 397u;
}

static vader_box_t vader_front_resolver$try_read(vader_string_t l0) {
    vader_box_t l1 = vader_box_null();
    vader_string_t t0 = 0;
    vader_box_t* gc_roots[1] = { &l1 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = std_io$read_file_string(l0, INT64_C(16777216));
    if (!(l1.tag == 335u)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t0 = l1.payload.s;
    { vader_box_t __vret = vader_box_string(335u, t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_resolver$union_in_bound(vader_box_t l0) {
    vader_box_t l1;
    void* t0;
    vader_box_t t1;
    if (!(l0.tag == 623u)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l0.payload.obj;
    if (((vader_struct_toolchain_ast$BinaryExpr_t*) t0)->f_op == INT32_C(8)) {
        t0 = l0.payload.obj;
        return vader_ref_box(t0);
    }
    t0 = l0.payload.obj;
    if (((vader_struct_toolchain_ast$BinaryExpr_t*) t0)->f_op != INT32_C(7)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l0.payload.obj;
    l1 = vader_front_resolver$union_in_bound(((vader_struct_toolchain_ast$BinaryExpr_t*) t0)->f_left);
    if (l1.tag == 0u) {
        t0 = l0.payload.obj;
        t1 = vader_front_resolver$union_in_bound(((vader_struct_toolchain_ast$BinaryExpr_t*) t0)->f_right);
        return t1;
    }
    t0 = l1.payload.obj;
    return vader_ref_box(t0);
}

static void vader_front_resolver$walk_block(void* l0, void* l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null();
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_front_resolver$push(((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope);
    l2 = ((vader_struct_toolchain_ast$BlockExpr_t*) l1)->f_stmts;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        vader_front_resolver$walk_stmt(l0, l5);
        l4 = (l4 + INT64_C(1));
    }
    l5 = ((vader_struct_toolchain_ast$BlockExpr_t*) l1)->f_trailing;
    vader_front_resolver$walk_opt_expr(l0, l5);
    vader_front_resolver$pop(((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$walk_body(void* l0, void* l1) {
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
    l2 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_file_scopes;
    l3 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) ((vader_struct_toolchain_ast$BlockExpr_t*) l1)->f_span)->f_start)->f_file;
    l4 = std_collections$MutableMap$std_core$Index$at__string__Any(l2, l3);
    if (!(l4.tag == 0u)) {
        l2 = l4.payload.obj;
        l2 = vader_front_resolver$enter_file(l0, l2);
        vader_front_resolver$walk_block(l0, l1);
        vader_front_resolver$enter_file(l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_front_resolver$walk_block(l0, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$walk_decl(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    int64_t l3, l4;
    vader_box_t l6 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l6 };
    void** gc_raw_roots[4] = { &l0, &l2, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 660u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 650u) {
        l2 = l1.payload.obj;
        vader_front_resolver$walk_fn_decl(l0, l2);
    } else if (l1.tag == 693u) {
        l2 = l1.payload.obj;
        vader_front_resolver$walk_struct_decl(l0, l2);
    } else if (l1.tag == 644u) {
        l2 = l1.payload.obj;
        vader_front_resolver$walk_enum_decl(l0, l2);
    } else if (l1.tag == 700u) {
        l2 = l1.payload.obj;
        vader_front_resolver$walk_trait_decl(l0, l2);
    } else if (l1.tag == 659u) {
        l2 = l1.payload.obj;
        vader_front_resolver$walk_impl_decl(l0, l2);
    } else if (l1.tag == 702u) {
        vader_front_resolver$push(((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope);
        t0 = l1.payload.obj;
        l2 = ((vader_struct_toolchain_ast$TypeAliasDecl_t*) t0)->f_type_params;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
            l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
            vader_front_resolver$bind_type_param(l0, l5);
            if (!(((vader_struct_toolchain_ast$TypeParam_t*) l5)->f_bound.tag == 0u)) {
                l6 = ((vader_struct_toolchain_ast$TypeParam_t*) l5)->f_bound;
                vader_front_resolver$checked_bound(l0, l5, l6);
            }
            l4 = (l4 + INT64_C(1));
        }
        t0 = l1.payload.obj;
        l6 = ((vader_struct_toolchain_ast$TypeAliasDecl_t*) t0)->f_aliased;
        vader_front_resolver$walk_opt_expr(l0, l6);
        vader_front_resolver$pop(((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope);
    } else if (l1.tag == 631u) {
        t0 = l1.payload.obj;
        l6 = ((vader_struct_toolchain_ast$ConstDecl_t*) t0)->f_ty;
        vader_front_resolver$walk_opt_expr(l0, l6);
        t0 = l1.payload.obj;
        l6 = ((vader_struct_toolchain_ast$ConstDecl_t*) t0)->f_value;
        vader_front_resolver$walk_expr(l0, l6);
    } else {
        if (!(l1.tag == 620u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = l1.payload.obj;
        l6 = ((vader_struct_toolchain_ast$AssertDecl_t*) t0)->f_condition;
        vader_front_resolver$walk_expr(l0, l6);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$walk_decorators(void* l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    int64_t l3, l4, l12, l13;
    vader_string_t l8 = 0;
    vader_string_t l9 = 0;
    vader_box_t l14 = vader_box_null();
    vader_string_t t0 = 0;
    bool t1;
    vader_box_t* gc_roots[1] = { &l14 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l5, &l6, &l7, &l10, &l11 };
    vader_string_t* gc_atom_roots[3] = { &l8, &l9, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = l1;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t0 = ((vader_struct_toolchain_ast$Decorator_t*) l5)->f_name;
        t1 = vader_front_resolver$is_known_decorator(t0);
        if (!(t1)) {
            l6 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_diags;
            l7 = ((vader_struct_toolchain_ast$Decorator_t*) l5)->f_span;
            l8 = ((vader_struct_toolchain_ast$Decorator_t*) l5)->f_name;
            l9 = concat_3(1337u, l8, 1038u);
            l10 = vader_support_diagnostics$resolver_error((uint8_t) 9, l7, l9);
            vader_array_push_ref((vader_array_t*) l6, l10);
        }
        t0 = ((vader_struct_toolchain_ast$Decorator_t*) l5)->f_name;
        if (t0 == 2698u) {
            vader_front_resolver$check_target_selectors(l0, l5);
            l4 = (l4 + INT64_C(1));
            continue;
        }
        t0 = ((vader_struct_toolchain_ast$Decorator_t*) l5)->f_name;
        t1 = vader_front_resolver$is_contract_decorator(t0);
        if (t1) {
            l4 = (l4 + INT64_C(1));
            continue;
        }
        l11 = ((vader_struct_toolchain_ast$Decorator_t*) l5)->f_args;
        l12 = ((vader_array_t*) l11)->length;
        l13 = INT64_C(0);
        while ((l13 < l12)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l11);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l13)
            l14 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l13);
            vader_front_resolver$walk_expr(l0, l14);
            l13 = (l13 + INT64_C(1));
        }
        l4 = (l4 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$walk_defer(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l4 = vader_box_null();
    void* l5 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[3] = { &l2, &l3, &l4 };
    void** gc_raw_roots[4] = { &l0, &l1, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast$DeferStmt_t*) l1)->f_body;
    l3 = l2;
    if (l2.tag == 636u) {
        t0 = l3.payload.obj;
        l4 = ((vader_struct_toolchain_ast$DeferStmtBody_t*) t0)->f_stmt;
        vader_front_resolver$walk_stmt(l0, l4);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (!(l2.tag == 634u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    t0 = l3.payload.obj;
    l5 = ((vader_struct_toolchain_ast$DeferBlockBody_t*) t0)->f_block;
    vader_front_resolver$walk_block(l0, l5);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$walk_enum_decl(void* l0, void* l1) {
    void* l2 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l5, &t0 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l6, &l7 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast$EnumDecl_t*) l1)->f_decorators;
    vader_front_resolver$walk_decorators(l0, l2);
    l2 = ((vader_struct_toolchain_ast$EnumDecl_t*) l1)->f_header;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        vader_front_resolver$walk_expr(l0, l5);
        l4 = (l4 + INT64_C(1));
    }
    l2 = ((vader_struct_toolchain_ast$EnumDecl_t*) l1)->f_variants;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        l6 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        if (!(((vader_struct_toolchain_ast$EnumVariant_t*) l6)->f_data.tag == 0u)) {
            t0 = ((vader_struct_toolchain_ast$EnumVariant_t*) l6)->f_data;
            l7 = t0.payload.obj;
            vader_front_resolver$walk_struct_lit_items(l0, l7);
        }
        l4 = (l4 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$walk_expr(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l6 = NULL;
    vader_string_t l3 = 0;
    vader_box_t l4 = vader_box_null(), l9 = vader_box_null(), l10 = vader_box_null();
    uint64_t l5;
    int64_t l7, l8;
    void* t0 = NULL;
    vader_box_t* gc_roots[4] = { &l1, &l4, &l9, &l10 };
    void** gc_raw_roots[4] = { &l0, &l2, &l6, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1.tag == 655u) {
        l2 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast$IdentExpr_t*) t0)->f_name;
        l4 = vader_front_resolver$lookup(l2, l3);
        if (l4.tag == 892u) {
            l2 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_idents;
            t0 = l1.payload.obj;
            l5 = toolchain_span$Span$std_core$Hash$hash(((vader_struct_toolchain_ast$IdentExpr_t*) t0)->f_span);
            l6 = l4.payload.obj;
            std_collections$MutableMap$std_core$IndexSet$set_at__u64__Any(l2, l5, vader_ref_box(l6));
            t0 = l1.payload.obj;
            l3 = ((vader_struct_toolchain_ast$IdentExpr_t*) t0)->f_name;
            t0 = l1.payload.obj;
            l2 = ((vader_struct_toolchain_ast$IdentExpr_t*) t0)->f_span;
            l6 = l4.payload.obj;
            vader_front_resolver$check_wildcard_ambiguity(l0, l3, l2, l6);
        } else {
            if (!(l4.tag == 0u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            l2 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_diags;
            t0 = l1.payload.obj;
            l6 = ((vader_struct_toolchain_ast$IdentExpr_t*) t0)->f_span;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_toolchain_ast$IdentExpr_t*) t0)->f_name;
            l3 = concat_3(1038u, l3, 1038u);
            l6 = vader_support_diagnostics$resolver_error((uint8_t) 5, l6, l3);
            vader_array_push_ref((vader_array_t*) l2, l6);
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 628u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_ast$CallExpr_t*) t0)->f_callee;
        vader_front_resolver$walk_expr(l0, l4);
        t0 = l1.payload.obj;
        l2 = ((vader_struct_toolchain_ast$CallExpr_t*) t0)->f_type_args;
        l7 = ((vader_array_t*) l2)->length;
        l8 = INT64_C(0);
        while ((l8 < l7)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l8)
            l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l8);
            vader_front_resolver$walk_expr(l0, l4);
            l8 = (l8 + INT64_C(1));
        }
        t0 = l1.payload.obj;
        l2 = ((vader_struct_toolchain_ast$CallExpr_t*) t0)->f_args;
        l7 = ((vader_array_t*) l2)->length;
        l8 = INT64_C(0);
        while ((l8 < l7)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l8)
            t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l8);
            l4 = ((vader_struct_toolchain_ast$CallArg_t*) t0)->f_value;
            vader_front_resolver$walk_expr(l0, l4);
            l8 = (l8 + INT64_C(1));
        }
    } else if (l1.tag == 648u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_ast$FieldExpr_t*) t0)->f_target;
        vader_front_resolver$walk_expr(l0, l4);
    } else if (l1.tag == 663u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_ast$IndexExpr_t*) t0)->f_target;
        vader_front_resolver$walk_expr(l0, l4);
        t0 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_ast$IndexExpr_t*) t0)->f_index;
        vader_front_resolver$walk_expr(l0, l4);
    } else if (l1.tag == 704u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_ast$UnaryExpr_t*) t0)->f_operand;
        vader_front_resolver$walk_expr(l0, l4);
    } else if (l1.tag == 623u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_ast$BinaryExpr_t*) t0)->f_left;
        vader_front_resolver$walk_expr(l0, l4);
        t0 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_ast$BinaryExpr_t*) t0)->f_right;
        vader_front_resolver$walk_expr(l0, l4);
    } else if (l1.tag == 676u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_ast$NullCoalesceExpr_t*) t0)->f_left;
        vader_front_resolver$walk_expr(l0, l4);
        t0 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_ast$NullCoalesceExpr_t*) t0)->f_fallback;
        l9 = l4;
        if ((l4.tag == 626u || l4.tag == 632u || l4.tag == 687u)) {
            l10 = l9;
            vader_front_resolver$walk_stmt(l0, l10);
        } else {
            if (!((l4.tag == 619u || l4.tag == 622u || l4.tag == 623u || l4.tag == 624u || l4.tag == 625u || l4.tag == 628u || l4.tag == 629u || l4.tag == 630u || l4.tag == 643u || l4.tag == 648u || l4.tag == 649u || l4.tag == 652u || l4.tag == 654u || l4.tag == 655u || l4.tag == 658u || l4.tag == 663u || l4.tag == 665u || l4.tag == 666u || l4.tag == 668u || l4.tag == 672u || l4.tag == 676u || l4.tag == 677u || l4.tag == 683u || l4.tag == 688u || l4.tag == 690u || l4.tag == 695u || l4.tag == 704u))) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            l4 = l9;
            vader_front_resolver$walk_expr(l0, l4);
        }
    } else if (l1.tag == 658u) {
        l2 = l1.payload.obj;
        vader_front_resolver$walk_if(l0, l2);
    } else if (l1.tag == 672u) {
        l2 = l1.payload.obj;
        vader_front_resolver$walk_match(l0, l2);
    } else if (l1.tag == 624u) {
        l2 = l1.payload.obj;
        vader_front_resolver$walk_block(l0, l2);
    } else if (l1.tag == 668u) {
        l2 = l1.payload.obj;
        vader_front_resolver$walk_lambda(l0, l2);
    } else if (l1.tag == 695u) {
        l2 = l1.payload.obj;
        vader_front_resolver$walk_struct_lit(l0, l2);
    } else if (l1.tag == 688u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_toolchain_ast$SeqLitExpr_t*) t0)->f_elements;
        l7 = ((vader_array_t*) l2)->length;
        l8 = INT64_C(0);
        while ((l8 < l7)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l8)
            l4 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l8);
            vader_front_resolver$walk_expr(l0, l4);
            l8 = (l8 + INT64_C(1));
        }
    } else if (l1.tag == 683u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_ast$RangeExpr_t*) t0)->f_lower;
        vader_front_resolver$walk_expr(l0, l4);
        t0 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_ast$RangeExpr_t*) t0)->f_upper;
        vader_front_resolver$walk_expr(l0, l4);
    } else if (l1.tag == 622u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_ast$AwaitExpr_t*) t0)->f_inner;
        vader_front_resolver$walk_expr(l0, l4);
    } else if (l1.tag == 629u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_ast$CastExpr_t*) t0)->f_value;
        vader_front_resolver$walk_expr(l0, l4);
        t0 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_ast$CastExpr_t*) t0)->f_target;
        vader_front_resolver$walk_expr(l0, l4);
    } else if (l1.tag == 654u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_ast$GenericInstExpr_t*) t0)->f_callee;
        vader_front_resolver$walk_expr(l0, l4);
        t0 = l1.payload.obj;
        l2 = ((vader_struct_toolchain_ast$GenericInstExpr_t*) t0)->f_type_args;
        l7 = ((vader_array_t*) l2)->length;
        l8 = INT64_C(0);
        while ((l8 < l7)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l8)
            l4 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l8);
            vader_front_resolver$walk_expr(l0, l4);
            l8 = (l8 + INT64_C(1));
        }
    } else if (l1.tag == 666u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) t0)->f_args;
        l7 = ((vader_array_t*) l2)->length;
        l8 = INT64_C(0);
        while ((l8 < l7)) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l8)
            l4 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l8);
            vader_front_resolver$walk_expr(l0, l4);
            l8 = (l8 + INT64_C(1));
        }
    } else if (!(l1.tag == 643u)) {
        if (l1.tag == 652u) {
            t0 = l1.payload.obj;
            l2 = ((vader_struct_toolchain_ast$FnTypeExpr_t*) t0)->f_params;
            l7 = ((vader_array_t*) l2)->length;
            l8 = INT64_C(0);
            while ((l8 < l7)) {
                vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l8)
                l4 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l8);
                vader_front_resolver$walk_expr(l0, l4);
                l8 = (l8 + INT64_C(1));
            }
            t0 = l1.payload.obj;
            l4 = ((vader_struct_toolchain_ast$FnTypeExpr_t*) t0)->f_return_type;
            vader_front_resolver$walk_opt_expr(l0, l4);
        } else if (l1.tag == 619u) {
            t0 = l1.payload.obj;
            l4 = ((vader_struct_toolchain_ast$ArrayTypeExpr_t*) t0)->f_element;
            vader_front_resolver$walk_expr(l0, l4);
        } else if (!(l1.tag == 665u)) {
            if (!(l1.tag == 649u)) {
                if (!(l1.tag == 625u)) {
                    if (!(l1.tag == 677u)) {
                        if (!(l1.tag == 630u)) {
                            if (!(l1.tag == 690u)) {
                                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                            }
                            t0 = l1.payload.obj;
                            l2 = ((vader_struct_toolchain_ast$StringLitExpr_t*) t0)->f_parts;
                            l7 = ((vader_array_t*) l2)->length;
                            l8 = INT64_C(0);
                            while ((l8 < l7)) {
                                vader_array_t* _a6_slotarr = ((vader_array_t*) l2);
                                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                                VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l8)
                                l4 = vader_array_ref_load_box(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l8);
                                if (l4.tag == 691u) {
                                    t0 = l4.payload.obj;
                                    l9 = ((vader_struct_toolchain_ast$StringLitInterp_t*) t0)->f_expr;
                                    vader_front_resolver$walk_expr(l0, l9);
                                }
                                l8 = (l8 + INT64_C(1));
                            }
                        }
                    }
                }
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$walk_fn_decl(void* l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    void* l8 = NULL;
    int64_t l3, l4, l9, l10;
    vader_box_t l6 = vader_box_null(), l7 = vader_box_null();
    vader_string_t t0 = 0;
    bool t1;
    vader_box_t* gc_roots[2] = { &l6, &l7 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l5, &l8 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_decorators;
    vader_front_resolver$walk_decorators(l0, l2);
    vader_front_resolver$push(((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope);
    l2 = ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_type_params;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        vader_front_resolver$declare_type_param(l0, l5);
        l4 = (l4 + INT64_C(1));
    }
    l2 = ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_params;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        l5 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        l6 = ((vader_struct_toolchain_ast$FnParam_t*) l5)->f_ty;
        vader_front_resolver$walk_opt_expr(l0, l6);
        l7 = ((vader_struct_toolchain_ast$FnParam_t*) l5)->f_default_value;
        vader_front_resolver$walk_opt_expr(l0, l7);
        vader_front_resolver$bind_param(l0, l5);
        l4 = (l4 + INT64_C(1));
    }
    l2 = ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_decorators;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        l5 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        t0 = ((vader_struct_toolchain_ast$Decorator_t*) l5)->f_name;
        t1 = vader_front_resolver$is_contract_decorator(t0);
        if (t1) {
            l8 = ((vader_struct_toolchain_ast$Decorator_t*) l5)->f_args;
            l9 = ((vader_array_t*) l8)->length;
            l10 = INT64_C(0);
            while ((l10 < l9)) {
                vader_array_t* _a3_slotarr = ((vader_array_t*) l8);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l10)
                l6 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l10);
                vader_front_resolver$walk_expr(l0, l6);
                l10 = (l10 + INT64_C(1));
            }
            l4 = (l4 + INT64_C(1));
            continue;
        }
        l4 = (l4 + INT64_C(1));
    }
    l6 = ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_return_type;
    vader_front_resolver$walk_opt_expr(l0, l6);
    l6 = ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_body;
    l7 = l6;
    if (l6.tag == 0u) {
        vader_front_resolver$pop(((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (!(l6.tag == 624u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    l2 = l7.payload.obj;
    vader_front_resolver$walk_body(l0, l2);
    vader_front_resolver$pop(((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$walk_for(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l4 = vader_box_null();
    vader_string_t l5 = 0;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l12 = NULL;
    uint64_t l8;
    int64_t l9, l10;
    int32_t l11;
    void* t0 = NULL;
    int32_t t1;
    int64_t t2;
    vader_box_t* gc_roots[3] = { &l2, &l3, &l4 };
    void** gc_raw_roots[6] = { &l0, &l1, &l6, &l7, &l12, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast$ForStmt_t*) l1)->f_form;
    l3 = l2;
    if (!(l2.tag == 664u)) {
        if (l2.tag == 705u) {
            t0 = l3.payload.obj;
            l4 = ((vader_struct_toolchain_ast$WhileFor_t*) t0)->f_cond;
            vader_front_resolver$walk_expr(l0, l4);
        } else {
            if (!(l2.tag == 662u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            t0 = l3.payload.obj;
            l2 = ((vader_struct_toolchain_ast$InFor_t*) t0)->f_iter;
            vader_front_resolver$walk_expr(l0, l2);
        }
    }
    vader_front_resolver$push(((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope);
    l2 = ((vader_struct_toolchain_ast$ForStmt_t*) l1)->f_form;
    l3 = l2;
    if (l2.tag == 662u) {
        t0 = l3.payload.obj;
        l3 = ((vader_struct_toolchain_ast$InFor_t*) t0)->f_loop_var;
        l4 = l3;
        if (l3.tag == 675u) {
            t0 = l4.payload.obj;
            l5 = ((vader_struct_toolchain_ast$NamedVar_t*) t0)->f_name;
            t0 = l4.payload.obj;
            l6 = ((vader_struct_toolchain_ast$NamedVar_t*) t0)->f_span;
            l6 = vader_front_resolver$bind_local_checked(l0, (uint8_t) 10, l5, l6);
            l7 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_idents;
            t0 = l4.payload.obj;
            l8 = toolchain_span$Span$std_core$Hash$hash(((vader_struct_toolchain_ast$NamedVar_t*) t0)->f_span);
            std_collections$MutableMap$std_core$IndexSet$set_at__u64__Any(l7, l8, vader_ref_box(l6));
            vader_front_resolver$declare_loop_local(l0, l6);
        } else if (l3.tag == 639u) {
            vader_array_t* _a0_arr = vader_array_new(69u, 0u, 13u, 892u);
            l6 = (void*) _a0_arr;
            t0 = l4.payload.obj;
            l4 = ((vader_struct_toolchain_ast$DestructureVar_t*) t0)->f_pattern;
            vader_front_resolver$bind_let_binding(l0, l4, l6);
            l9 = ((vader_array_t*) l6)->length;
            l10 = INT64_C(0);
            while ((l10 < l9)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                l7 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l10);
                vader_front_resolver$declare_loop_local(l0, l7);
                l10 = (l10 + INT64_C(1));
            }
        } else if (!(l3.tag == 640u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
    } else if (!((l2.tag == 664u || l2.tag == 705u))) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    l9 = ((vader_array_t*) ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_rebind_log)->length;
    t1 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_loop_depth;
    l11 = vader_chk_add(i32, t1, INT32_C(1));
    ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_loop_depth = l11;
    l6 = ((vader_struct_toolchain_ast$ForStmt_t*) l1)->f_body;
    vader_front_resolver$walk_block(l0, l6);
    t1 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_loop_depth;
    l11 = vader_chk_sub(i32, t1, INT32_C(1));
    ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_loop_depth = l11;
    vader_front_resolver$pop(((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope);
    t2 = ((vader_array_t*) ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_rebind_log)->length;
    if ((t2 > l9)) {
        vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
        l6 = (void*) _a2_arr;
        vader_array_t* _a3_arr = vader_array_new(19u, 0u, 12u, 333u);
        l7 = (void*) _a3_arr;
        vader_array_t* _a4_arr = vader_array_new(22u, 0u, 7u, 338u);
        l12 = (void*) _a4_arr;
        vader_struct_std_collections$MutableMap__i32__bool_t* _a5_obj = (vader_struct_std_collections$MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__bool_t));
        vader_obj_header_init(_a5_obj, 462u);
        _a5_obj->f_ekeys = l6;
        _a5_obj->f_evals = l7;
        _a5_obj->f_index = l12;
        _a5_obj->f_mask = INT64_C(0);
        _a5_obj->f_grow_at = INT64_C(0);
        _a5_obj->f_size = INT64_C(0);
        _a5_obj->f_tombs = INT64_C(0);
        t0 = (void*) _a5_obj;
        vader_struct_std_collections$MutableSet__i32_t* _a6_obj = (vader_struct_std_collections$MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__i32_t));
        vader_obj_header_init(_a6_obj, 605u);
        _a6_obj->f_inner = t0;
        l6 = (void*) _a6_obj;
        l10 = ((vader_array_t*) ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_rebind_log)->length;
        while ((l9 < l10)) {
            vader_array_t* _a7_slotarr = ((vader_array_t*) ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_rebind_log);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l9)
            l11 = ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l9];
            std_collections$add__i32(l6, l11);
            l9 = (l9 + INT64_C(1));
        }
        l7 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_loop_rebinds;
        l8 = toolchain_span$Span$std_core$Hash$hash(((vader_struct_toolchain_ast$ForStmt_t*) l1)->f_span);
        std_collections$MutableMap$std_core$IndexSet$set_at__u64__Any(l7, l8, vader_ref_box(l6));
    }
    t1 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_loop_depth;
    if (t1 == INT32_C(0)) {
        vader_array_clear((vader_array_t*) ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_rebind_log);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$walk_if(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l4 = vader_box_null();
    void* l3 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l2, &l4 };
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast$IfExpr_t*) l1)->f_cond;
    vader_front_resolver$walk_expr(l0, l2);
    l3 = ((vader_struct_toolchain_ast$IfExpr_t*) l1)->f_then_block;
    vader_front_resolver$walk_block(l0, l3);
    l2 = ((vader_struct_toolchain_ast$IfExpr_t*) l1)->f_else_branch;
    l4 = l2;
    if (l2.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 657u) {
        t0 = l4.payload.obj;
        l3 = ((vader_struct_toolchain_ast$IfElseIf_t*) t0)->f_branch;
        vader_front_resolver$walk_if(l0, l3);
    } else {
        if (!(l2.tag == 656u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = l4.payload.obj;
        l3 = ((vader_struct_toolchain_ast$IfElseBlock_t*) t0)->f_block;
        vader_front_resolver$walk_block(l0, l3);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$walk_impl_decl(void* l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    int64_t l3, l4;
    vader_box_t l6 = vader_box_null();
    vader_string_t l7 = 0;
    uint64_t l8;
    bool t0;
    vader_box_t* gc_roots[1] = { &l6 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast$ImplDecl_t*) l1)->f_decorators;
    vader_front_resolver$walk_decorators(l0, l2);
    vader_front_resolver$push(((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope);
    l2 = ((vader_struct_toolchain_ast$ImplDecl_t*) l1)->f_type_params;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        vader_front_resolver$declare_type_param(l0, l5);
        l4 = (l4 + INT64_C(1));
    }
    l6 = ((vader_struct_toolchain_ast$ImplDecl_t*) l1)->f_for_type;
    vader_front_resolver$auto_bind_for_type_params(l0, l6);
    l6 = ((vader_struct_toolchain_ast$ImplDecl_t*) l1)->f_for_type;
    vader_front_resolver$walk_expr(l0, l6);
    l2 = ((vader_struct_toolchain_ast$ImplDecl_t*) l1)->f_trait_args;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        l6 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        vader_front_resolver$walk_expr(l0, l6);
        l4 = (l4 + INT64_C(1));
    }
    l2 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope;
    l7 = ((vader_struct_toolchain_ast$ImplDecl_t*) l1)->f_trait_name;
    l6 = vader_front_resolver$lookup(l2, l7);
    if (!(l6.tag == 0u)) {
        l2 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_idents;
        l8 = toolchain_span$Span$std_core$Hash$hash(((vader_struct_toolchain_ast$ImplDecl_t*) l1)->f_trait_name_span);
        l5 = l6.payload.obj;
        std_collections$MutableMap$std_core$IndexSet$set_at__u64__Any(l2, l8, vader_ref_box(l5));
        l7 = ((vader_struct_toolchain_ast$ImplDecl_t*) l1)->f_trait_name;
        l2 = ((vader_struct_toolchain_ast$ImplDecl_t*) l1)->f_trait_name_span;
        l5 = l6.payload.obj;
        vader_front_resolver$check_wildcard_ambiguity(l0, l7, l2, l5);
    }
    l2 = ((vader_struct_toolchain_ast$ImplDecl_t*) l1)->f_members;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        l5 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        t0 = ((vader_struct_toolchain_ast$FnDecl_t*) l5)->f_materialized;
        if (t0) {
            t0 = ((vader_struct_toolchain_ast$FnDecl_t*) l5)->f_sam_synthetic;
            if (t0) {
                l4 = (l4 + INT64_C(1));
                continue;
            }
        }
        vader_front_resolver$walk_fn_decl(l0, l5);
        l4 = (l4 + INT64_C(1));
    }
    vader_front_resolver$pop(((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$walk_import_cycle(vader_string_t l0, void* l1, void* l2, void* l3, void* l4) {
    vader_box_t l5 = vader_box_null(), l10 = vader_box_null(), l12 = vader_box_null();
    void* l6 = NULL;
    void* l13 = NULL;
    void* l16 = NULL;
    int64_t l7, l8;
    vader_string_t l9 = 0;
    vader_string_t l11 = 0;
    vader_string_t l14 = 0;
    vader_string_t l15 = 0;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_string_t t2 = 0;
    int32_t t3;
    vader_box_t* gc_roots[4] = { &l5, &l10, &l12, &t1 };
    void** gc_raw_roots[8] = { &l1, &l2, &l3, &l4, &l6, &l13, &l16, &t0 };
    vader_string_t* gc_atom_roots[6] = { &l0, &l9, &l11, &l14, &l15, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 6u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections$MutableMap$std_core$IndexSet$set_at__string__i32(l3, l0, INT32_C(1));
    l5 = std_collections$MutableMap$std_core$Index$at__string__Any(l1, l0);
    if (l5.tag == 1095u) {
        t0 = l5.payload.obj;
        l6 = ((vader_struct_vader_front_resolver$CollectedModule_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) t0)->f_collected)->f_import_paths;
        l7 = ((vader_array_t*) l6)->length;
        l8 = INT64_C(0);
        while ((l8 < l7)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            t1 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l8];
            l9 = t1.payload.s;
            l10 = std_collections$MutableMap$std_core$Index$at__string__Any(l2, l9);
            if (l10.tag == 1087u) {
                t0 = l10.payload.obj;
                l11 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) t0)->f_folder;
                l12 = std_collections$MutableMap$std_core$Index$at__string__i32(l3, l11);
                if (l12.tag == 0u) {
                    t0 = l10.payload.obj;
                    t2 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) t0)->f_folder;
                    vader_front_resolver$walk_import_cycle(t2, l1, l2, l3, l4);
                } else {
                    t3 = ((int32_t) l12.payload.i);
                    if (t3 == INT32_C(1)) {
                        t0 = l5.payload.obj;
                        t2 = ((vader_struct_vader_front_resolver$Module_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) t0)->f_module)->f_display_path;
                        l13 = vader_front_resolver$zero_span(t2);
                        t0 = l5.payload.obj;
                        l14 = ((vader_struct_vader_front_resolver$Module_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) t0)->f_module)->f_display_path;
                        l15 = concat_5(1038u, l14, 1128u, l9, 1294u);
                        l16 = vader_support_diagnostics$resolver_error((uint8_t) 4, l13, l15);
                        vader_array_push_ref((vader_array_t*) l4, l16);
                    }
                }
            }
            l8 = (l8 + INT64_C(1));
        }
    }
    std_collections$MutableMap$std_core$IndexSet$set_at__string__i32(l3, l0, INT32_C(2));
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$walk_lambda(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l8 = vader_box_null();
    int32_t l3;
    void* l4 = NULL;
    void* l7 = NULL;
    int64_t l5, l6;
    vader_box_t* gc_roots[2] = { &l2, &l8 };
    void** gc_raw_roots[4] = { &l0, &l1, &l4, &l7 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_lambda_frame;
    l3 = vader_front_resolver$frame_count(((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope);
    ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_lambda_frame = vader_box_i32(338u, l3);
    VADER_WRITE_BARRIER((vader_struct_vader_front_resolver$ResolveState_t*) l0);
    vader_front_resolver$push(((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope);
    l4 = ((vader_struct_toolchain_ast$LambdaExpr_t*) l1)->f_params;
    l5 = ((vader_array_t*) l4)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
        l7 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
        l8 = ((vader_struct_toolchain_ast$FnParam_t*) l7)->f_ty;
        vader_front_resolver$walk_opt_expr(l0, l8);
        vader_front_resolver$bind_param(l0, l7);
        l6 = (l6 + INT64_C(1));
    }
    l8 = ((vader_struct_toolchain_ast$LambdaExpr_t*) l1)->f_return_type;
    vader_front_resolver$walk_opt_expr(l0, l8);
    l4 = ((vader_struct_toolchain_ast$LambdaExpr_t*) l1)->f_body;
    vader_front_resolver$walk_block(l0, l4);
    vader_front_resolver$pop(((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope);
    ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_lambda_frame = l2;
    VADER_WRITE_BARRIER((vader_struct_vader_front_resolver$ResolveState_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$walk_let(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l9 = NULL;
    int64_t l4, l5;
    int32_t l8;
    bool t0;
    int64_t t1;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[6] = { &l0, &l1, &l3, &l6, &l7, &l9 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast$LetStmt_t*) l1)->f_ty;
    vader_front_resolver$walk_opt_expr(l0, l2);
    l2 = ((vader_struct_toolchain_ast$LetStmt_t*) l1)->f_value;
    vader_front_resolver$walk_expr(l0, l2);
    vader_array_t* _a0_arr = vader_array_new(69u, 0u, 13u, 892u);
    l3 = (void*) _a0_arr;
    l2 = ((vader_struct_toolchain_ast$LetStmt_t*) l1)->f_binding;
    vader_front_resolver$bind_let_binding(l0, l2, l3);
    t0 = ((vader_struct_toolchain_ast$LetStmt_t*) l1)->f_mutable;
    if (t0) {
        t1 = ((vader_array_t*) l3)->length;
        if ((t1 > INT64_C(0))) {
            l6 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_mutable_decls;
            l7 = vader_front_resolver$binding_span(((vader_struct_toolchain_ast$LetStmt_t*) l1)->f_binding);
            vader_struct_vader_front_resolver$MutableDecl_t* _a1_obj = (vader_struct_vader_front_resolver$MutableDecl_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$MutableDecl_t));
            vader_obj_header_init(_a1_obj, 1100u);
            _a1_obj->f_syms = l3;
            _a1_obj->f_span = l7;
            l9 = (void*) _a1_obj;
            vader_array_push_ref((vader_array_t*) l6, l9);
        }
    } else {
        l4 = ((vader_array_t*) l3)->length;
        l5 = INT64_C(0);
        while ((l5 < l4)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            l6 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
            l7 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_immutable_locals;
            l8 = ((vader_struct_vader_core_symbol$Symbol_t*) l6)->f_id;
            std_collections$MutableMap$std_core$IndexSet$set_at__i32__vader_front_resolver_ConstLocal(l7, l8, (uint8_t) 0);
            l5 = (l5 + INT64_C(1));
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$walk_match(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l10 = vader_box_null(), l11 = vader_box_null();
    vader_string_t l3 = 0;
    void* l4 = NULL;
    void* l5 = NULL;
    uint64_t l6;
    int32_t l7;
    int64_t l8, l9;
    void* t0 = NULL;
    vader_box_t* gc_roots[3] = { &l2, &l10, &l11 };
    void** gc_raw_roots[5] = { &l0, &l1, &l4, &l5, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast$MatchExpr_t*) l1)->f_scrutinee;
    vader_front_resolver$walk_expr(l0, l2);
    vader_front_resolver$push(((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope);
    l2 = ((vader_struct_toolchain_ast$MatchExpr_t*) l1)->f_binding;
    if (!(l2.tag == 0u)) {
        t0 = l2.payload.obj;
        l3 = ((vader_struct_toolchain_ast$SimpleBinding_t*) t0)->f_name;
        t0 = l2.payload.obj;
        l4 = ((vader_struct_toolchain_ast$SimpleBinding_t*) t0)->f_name_span;
        l4 = vader_front_resolver$bind_local(l0, (uint8_t) 10, l3, l4);
        l5 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_idents;
        t0 = l2.payload.obj;
        l6 = toolchain_span$Span$std_core$Hash$hash(((vader_struct_toolchain_ast$SimpleBinding_t*) t0)->f_name_span);
        std_collections$MutableMap$std_core$IndexSet$set_at__u64__Any(l5, l6, vader_ref_box(l4));
        l5 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_immutable_locals;
        l7 = ((vader_struct_vader_core_symbol$Symbol_t*) l4)->f_id;
        std_collections$MutableMap$std_core$IndexSet$set_at__i32__vader_front_resolver_ConstLocal(l5, l7, (uint8_t) 2);
    }
    l4 = ((vader_struct_toolchain_ast$MatchExpr_t*) l1)->f_arms;
    l8 = ((vader_array_t*) l4)->length;
    l9 = INT64_C(0);
    while ((l9 < l8)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l9)
        l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l9);
        vader_front_resolver$push(((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope);
        l2 = ((vader_struct_toolchain_ast$MatchArm_t*) l5)->f_pattern;
        vader_front_resolver$bind_pattern(l0, l2);
        l10 = ((vader_struct_toolchain_ast$MatchArm_t*) l5)->f_guard;
        vader_front_resolver$walk_opt_expr(l0, l10);
        l11 = ((vader_struct_toolchain_ast$MatchArm_t*) l5)->f_body;
        vader_front_resolver$walk_expr(l0, l11);
        vader_front_resolver$pop(((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope);
        l9 = (l9 + INT64_C(1));
    }
    vader_front_resolver$pop(((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$walk_opt_expr(void* l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l2 = l1;
    vader_front_resolver$walk_expr(l0, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$walk_stmt(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    int64_t l4, l5;
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l3 };
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 669u) {
        l2 = l1.payload.obj;
        vader_front_resolver$walk_let(l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 621u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast$AssignStmt_t*) t0)->f_target;
        vader_front_resolver$walk_expr(l0, l3);
        t0 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast$AssignStmt_t*) t0)->f_value;
        vader_front_resolver$walk_expr(l0, l3);
        t0 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast$AssignStmt_t*) t0)->f_target;
        vader_front_resolver$note_rebind(l0, l3);
    } else if (l1.tag == 637u) {
        t0 = l1.payload.obj;
        l2 = toolchain_ast$assign_places(t0);
        l4 = ((vader_array_t*) l2)->length;
        l5 = INT64_C(0);
        while ((l5 < l4)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
            l3 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
            vader_front_resolver$walk_expr(l0, l3);
            vader_front_resolver$note_rebind(l0, l3);
            l5 = (l5 + INT64_C(1));
        }
        t0 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast$DestructureAssignStmt_t*) t0)->f_value;
        vader_front_resolver$walk_expr(l0, l3);
    } else if (l1.tag == 647u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast$ExprStmt_t*) t0)->f_expr;
        vader_front_resolver$walk_expr(l0, l3);
    } else if (l1.tag == 687u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast$ReturnStmt_t*) t0)->f_value;
        vader_front_resolver$walk_opt_expr(l0, l3);
    } else if (l1.tag == 710u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast$YieldStmt_t*) t0)->f_value;
        vader_front_resolver$walk_expr(l0, l3);
    } else if (l1.tag == 653u) {
        l2 = l1.payload.obj;
        vader_front_resolver$walk_for(l0, l2);
    } else if (!(l1.tag == 626u)) {
        if (!(l1.tag == 632u)) {
            if (!(l1.tag == 635u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            l2 = l1.payload.obj;
            vader_front_resolver$walk_defer(l0, l2);
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$walk_struct_decl(void* l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    int64_t l3, l4;
    vader_box_t l6 = vader_box_null(), l7 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l6, &l7 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast$StructDecl_t*) l1)->f_decorators;
    vader_front_resolver$walk_decorators(l0, l2);
    vader_front_resolver$push(((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope);
    l2 = ((vader_struct_toolchain_ast$StructDecl_t*) l1)->f_type_params;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        vader_front_resolver$declare_type_param(l0, l5);
        l4 = (l4 + INT64_C(1));
    }
    l2 = ((vader_struct_toolchain_ast$StructDecl_t*) l1)->f_fields;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        l5 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        l6 = ((vader_struct_toolchain_ast$StructField_t*) l5)->f_ty;
        vader_front_resolver$walk_expr(l0, l6);
        l7 = ((vader_struct_toolchain_ast$StructField_t*) l5)->f_default;
        vader_front_resolver$walk_opt_expr(l0, l7);
        l4 = (l4 + INT64_C(1));
    }
    vader_front_resolver$pop(((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$walk_struct_lit(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[3] = { &l0, &l1, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast$StructLitExpr_t*) l1)->f_type_name;
    vader_front_resolver$walk_expr(l0, l2);
    l3 = ((vader_struct_toolchain_ast$StructLitExpr_t*) l1)->f_items;
    vader_front_resolver$walk_struct_lit_items(l0, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$walk_struct_lit_items(void* l0, void* l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null(), l6 = vader_box_null(), l7 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[3] = { &l5, &l6, &l7 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l1;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        if (l5.tag == 696u) {
            t0 = l5.payload.obj;
            l6 = ((vader_struct_toolchain_ast$StructLitField_t*) t0)->f_value;
            vader_front_resolver$walk_expr(l0, l6);
        } else {
            t0 = l5.payload.obj;
            l7 = ((vader_struct_toolchain_ast$StructLitSpread_t*) t0)->f_expr;
            vader_front_resolver$walk_expr(l0, l7);
        }
        l4 = (l4 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$walk_trait_decl(void* l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    int64_t l3, l4;
    vader_box_t l6 = vader_box_null();
    vader_string_t l7 = 0;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l6 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l5, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast$TraitDecl_t*) l1)->f_decorators;
    vader_front_resolver$walk_decorators(l0, l2);
    vader_front_resolver$push(((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope);
    l2 = ((vader_struct_toolchain_ast$TraitDecl_t*) l1)->f_type_params;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        vader_front_resolver$declare_type_param(l0, l5);
        l4 = (l4 + INT64_C(1));
    }
    l6 = ((vader_struct_toolchain_ast$TraitDecl_t*) l1)->f_requires;
    vader_front_resolver$walk_opt_expr(l0, l6);
    l6 = vader_front_resolver$union_in_bound(((vader_struct_toolchain_ast$TraitDecl_t*) l1)->f_requires);
    if (!(l6.tag == 0u)) {
        l7 = ((vader_struct_toolchain_ast$TraitDecl_t*) l1)->f_name;
        l7 = concat_3(1038u, l7, 1042u);
        l2 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_diags;
        t0 = l6.payload.obj;
        l5 = ((vader_struct_toolchain_ast$BinaryExpr_t*) t0)->f_span;
        l5 = vader_support_diagnostics$resolver_error((uint8_t) 33, l5, l7);
        vader_array_push_ref((vader_array_t*) l2, l5);
    }
    l2 = ((vader_struct_toolchain_ast$TraitDecl_t*) l1)->f_members;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        l5 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        vader_front_resolver$walk_fn_decl(l0, l5);
        l4 = (l4 + INT64_C(1));
    }
    vader_front_resolver$pop(((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$warn_collision(void* l0, vader_string_t l1, void* l2) {
    int32_t l3, l4;
    void* l5 = NULL;
    void* l7 = NULL;
    vader_string_t l6 = 0;
    int32_t t0;
    void** gc_raw_roots[4] = { &l0, &l2, &l5, &l7 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1 == 977u) {
        l3 = INT32_C(-1);
    } else {
        l3 = vader_front_resolver$lookup_frame_index(((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope, l1);
    }
    if ((l3 <= INT32_C(0))) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = vader_front_resolver$frame_count(((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope);
    l4 = vader_chk_sub(i32, t0, INT32_C(1));
    if (l3 == l4) {
        l5 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_diags;
        l6 = concat_3(1038u, l1, 1038u);
        l7 = vader_support_diagnostics$warning((uint8_t) 5, l2, l6);
        vader_array_push_ref((vader_array_t*) l5, l7);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l5 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_diags;
    l6 = concat_3(1038u, l1, 1038u);
    l7 = vader_support_diagnostics$warning((uint8_t) 4, l2, l6);
    vader_array_push_ref((vader_array_t*) l5, l7);
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_front_resolver$wildcard_ambiguities(void* l0, void* l1, void* l2, void* l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l17 = NULL;
    void* l20 = NULL;
    void* l21 = NULL;
    void* l23 = NULL;
    int64_t l7, l8, l15, l16, l24, l25;
    vader_string_t l9 = 0;
    vader_string_t l18 = 0;
    vader_string_t l19 = 0;
    vader_box_t l10 = vader_box_null(), l11 = vader_box_null();
    bool l22;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    vader_string_t t2 = 0;
    bool t3;
    vader_box_t* gc_roots[3] = { &l10, &l11, &t1 };
    void** gc_raw_roots[14] = {
        &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l12, &l13, &l14, &l17, &l20, &l21, &l23,
    };
    vader_string_t* gc_atom_roots[4] = { &l9, &l18, &l19, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 14u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 335u);
    l4 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(2u, 0u, 13u, 21u);
    l5 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
    l6 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__string__string___t* _a3_obj = (vader_struct_std_collections$MutableMap__string__string___t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__string___t));
    vader_obj_header_init(_a3_obj, 554u);
    _a3_obj->f_ekeys = l4;
    _a3_obj->f_evals = l5;
    _a3_obj->f_index = l6;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l4 = (void*) _a3_obj;
    t0 = ((vader_array_t*) l1)->length;
    if ((t0 < INT64_C(2))) {
        { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = l1;
    l7 = ((vader_array_t*) l5)->length;
    l8 = INT64_C(0);
    while ((l8 < l7)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l8)
        t1 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l8];
        l9 = t1.payload.s;
        l10 = std_collections$MutableMap$std_core$Index$at__string__Any(l0, l9);
        if (l10.tag == 0u) {
            l8 = (l8 + INT64_C(1));
            continue;
        }
        l6 = l10.payload.obj;
        l11 = std_collections$MutableMap$std_core$Index$at__string__string__(l2, l9);
        l12 = ((vader_struct_vader_front_resolver$CollectedModule_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l6)->f_collected)->f_symbols;
        l13 = ((vader_struct_std_collections$MutableMap__string__vader_core_symbol_Symbol_t*) l12)->f_ekeys;
        l14 = ((vader_struct_std_collections$MutableMap__string__vader_core_symbol_Symbol_t*) l12)->f_evals;
        l15 = INT64_C(0);
        l16 = ((vader_struct_std_collections$MutableMap__string__vader_core_symbol_Symbol_t*) l12)->f_size;
        while ((l15 < l16)) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) l13);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l15)
            t1 = vader_array_box_slots(_a5_slotarr->buf)[_a5_slotarr->offset + (size_t) l15];
            t2 = t1.payload.s;
            vader_array_t* _a6_slotarr = ((vader_array_t*) l14);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l15)
            l17 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l15);
            t3 = vader_front_resolver$wildcard_exposes(l17, l11);
            if (t3) {
                l18 = ((vader_struct_vader_core_symbol$Symbol_t*) l17)->f_name;
                t1 = std_collections$MutableMap$std_core$Index$at__string__Any(l3, l18);
                if (t1.tag == 0u) {
                    l19 = ((vader_struct_vader_core_symbol$Symbol_t*) l17)->f_name;
                    l20 = (void*) &vader_fn_static___lambda_vader_front_resolver_0;
                    l21 = std_collections$get_or_put_with__string__string__(l4, l19, l20);
                    l22 = false;
                    l23 = l21;
                    l24 = ((vader_array_t*) l23)->length;
                    l25 = INT64_C(0);
                    while ((l25 < l24)) {
                        vader_array_t* _a7_slotarr = ((vader_array_t*) l23);
                        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
                        t1 = vader_array_box_slots(_a7_slotarr->buf)[_a7_slotarr->offset + (size_t) l25];
                        t2 = t1.payload.s;
                        if (t2 == l9) {
                            l22 = true;
                        }
                        l25 = (l25 + INT64_C(1));
                    }
                    if (!(l22)) {
                        vader_array_push_scalar((vader_array_t*) l21, vader_box_string(335u, l9));
                    }
                }
            }
            l15 = (l15 + INT64_C(1));
        }
        l8 = (l8 + INT64_C(1));
    }
    vader_array_t* _a8_arr = vader_array_new(21u, 0u, 0u, 335u);
    l5 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(2u, 0u, 13u, 21u);
    l6 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(22u, 0u, 7u, 338u);
    l12 = (void*) _a10_arr;
    vader_struct_std_collections$MutableMap__string__string___t* _a11_obj = (vader_struct_std_collections$MutableMap__string__string___t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__string___t));
    vader_obj_header_init(_a11_obj, 554u);
    _a11_obj->f_ekeys = l5;
    _a11_obj->f_evals = l6;
    _a11_obj->f_index = l12;
    _a11_obj->f_mask = INT64_C(0);
    _a11_obj->f_grow_at = INT64_C(0);
    _a11_obj->f_size = INT64_C(0);
    _a11_obj->f_tombs = INT64_C(0);
    l5 = (void*) _a11_obj;
    l6 = ((vader_struct_std_collections$MutableMap__string__string___t*) l4)->f_ekeys;
    l12 = ((vader_struct_std_collections$MutableMap__string__string___t*) l4)->f_evals;
    l7 = INT64_C(0);
    l8 = ((vader_struct_std_collections$MutableMap__string__string___t*) l4)->f_size;
    while ((l7 < l8)) {
        vader_array_t* _a12_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l7)
        t1 = vader_array_box_slots(_a12_slotarr->buf)[_a12_slotarr->offset + (size_t) l7];
        l9 = t1.payload.s;
        vader_array_t* _a13_slotarr = ((vader_array_t*) l12);
        VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l7)
        l4 = vader_array_ref_load_obj(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l7);
        l18 = l9;
        l13 = l4;
        t0 = ((vader_array_t*) l13)->length;
        if ((t0 >= INT64_C(2))) {
            std_collections$MutableMap$std_core$IndexSet$set_at__string__string__(l5, l18, l13);
        }
        l7 = (l7 + INT64_C(1));
    }
    { void* __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_front_resolver$wildcard_exposable(uint8_t l0) {
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

static bool vader_front_resolver$wildcard_exposes(void* l0, vader_box_t l1) {
    vader_string_t l2;
    bool t0;
    void* t1;
    t0 = vader_front_resolver$wildcard_exposable(((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_kind);
    if (t0) {
        if (((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_visibility != INT32_C(0)) {
            return false;
        }
        if (!(l1.tag == 0u)) {
            l2 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_name;
            t1 = l1.payload.obj;
            t0 = std_core$$array$Contains$contains__string(t1, l2);
            return !(t0);
        }
        return true;
    }
    return false;
}

void* vader_front_resolver$wire_imports(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    int64_t l6, l7;
    vader_string_t l8 = 0;
    vader_string_t l9 = 0;
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l4, &l5, &t2 };
    vader_string_t* gc_atom_roots[3] = { &l8, &l9, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_front_resolver$new_import_target_table();
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 335u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(21u, 0u, 0u, 335u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__string__string_t* _a3_obj = (vader_struct_std_collections$MutableMap__string__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__string_t));
    vader_obj_header_init(_a3_obj, 553u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l2 = (void*) _a3_obj;
    l3 = ((vader_struct_vader_front_resolver$LoadedProject_t*) l0)->f_modules;
    l4 = ((vader_struct_std_collections$MutableMap__string__vader_front_resolver_LoadedModule_t*) l3)->f_ekeys;
    l5 = ((vader_struct_std_collections$MutableMap__string__vader_front_resolver_LoadedModule_t*) l3)->f_evals;
    l6 = INT64_C(0);
    l7 = ((vader_struct_std_collections$MutableMap__string__vader_front_resolver_LoadedModule_t*) l3)->f_size;
    while ((l6 < l7)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l6)
        t0 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l6];
        t1 = t0.payload.s;
        vader_array_t* _a5_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l6)
        l3 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l6);
        l8 = ((vader_struct_vader_front_resolver$Module_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l3)->f_module)->f_module_name;
        l9 = ((vader_struct_vader_front_resolver$Module_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l3)->f_module)->f_id;
        std_collections$MutableMap$std_core$IndexSet$set_at__string__string(l2, l8, l9);
        l6 = (l6 + INT64_C(1));
    }
    l3 = ((vader_struct_vader_front_resolver$LoadedProject_t*) l0)->f_modules;
    l4 = ((vader_struct_std_collections$MutableMap__string__vader_front_resolver_LoadedModule_t*) l3)->f_ekeys;
    l5 = ((vader_struct_std_collections$MutableMap__string__vader_front_resolver_LoadedModule_t*) l3)->f_evals;
    l6 = INT64_C(0);
    l7 = ((vader_struct_std_collections$MutableMap__string__vader_front_resolver_LoadedModule_t*) l3)->f_size;
    while ((l6 < l7)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l6)
        t0 = vader_array_box_slots(_a6_slotarr->buf)[_a6_slotarr->offset + (size_t) l6];
        t1 = t0.payload.s;
        vader_array_t* _a7_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l6)
        t2 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l6);
        vader_front_resolver$wire_module(t2, l2, l0, l1);
        l6 = (l6 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_front_resolver$wire_module(void* l0, void* l1, void* l2, void* l3) {
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
    int64_t l7, l8;
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
    void* t0 = NULL;
    vader_box_t* gc_roots[5] = { &l13, &l16, &l17, &l18, &l23 };
    void** gc_raw_roots[21] = {
        &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l11, &l14, &l19, &l21, &l24, &l25, &l29, &l30, &l31,
        &l34, &l35, &l36, &l38, &t0,
    };
    vader_string_t* gc_atom_roots[10] = {
        &l12, &l15, &l20, &l22, &l26, &l27, &l28, &l32, &l33, &l37,
    };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 5u, 21u, gc_roots, gc_raw_roots, 0u, NULL, 10u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_front_resolver$CollectedModule_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l0)->f_collected)->f_imports;
    l5 = ((vader_struct_std_collections$MutableMap__i32__vader_front_resolver_ImportInfo_t*) l4)->f_ekeys;
    l6 = ((vader_struct_std_collections$MutableMap__i32__vader_front_resolver_ImportInfo_t*) l4)->f_evals;
    l7 = INT64_C(0);
    l8 = ((vader_struct_std_collections$MutableMap__i32__vader_front_resolver_ImportInfo_t*) l4)->f_size;
    while ((l7 < l8)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l7)
        l9 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l7];
        vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l7)
        l4 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l7);
        l10 = l9;
        l11 = l4;
        l12 = ((vader_struct_vader_front_resolver$ImportInfo_t*) l11)->f_path;
        l13 = std_collections$MutableMap$std_core$Index$at__string__string(l1, l12);
        if (l13.tag == 0u) {
            std_collections$MutableMap$std_core$IndexSet$set_at__i32__bool(((vader_struct_vader_front_resolver$ImportTargetTable_t*) l3)->f_missing, l10, true);
        } else {
            l14 = ((vader_struct_vader_front_resolver$LoadedProject_t*) l2)->f_modules;
            l15 = l13.payload.s;
            l16 = std_collections$MutableMap$std_core$Index$at__string__Any(l14, l15);
            if (l16.tag == 0u) {
                std_collections$MutableMap$std_core$IndexSet$set_at__i32__bool(((vader_struct_vader_front_resolver$ImportTargetTable_t*) l3)->f_missing, l10, true);
            } else {
                l17 = ((vader_struct_vader_front_resolver$ImportInfo_t*) l11)->f_imported_name;
                l18 = l17;
                if (l17.tag == 0u) {
                    l19 = ((vader_struct_vader_front_resolver$ImportTargetTable_t*) l3)->f_namespace_targets;
                    l20 = l13.payload.s;
                    std_collections$MutableMap$std_core$IndexSet$set_at__i32__string(l19, l10, l20);
                } else {
                    if (!(l17.tag == 335u)) {
                        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                    }
                    t0 = l16.payload.obj;
                    l21 = ((vader_struct_vader_front_resolver$CollectedModule_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) t0)->f_collected)->f_symbols;
                    l22 = l18.payload.s;
                    l23 = std_collections$MutableMap$std_core$Index$at__string__Any(l21, l22);
                    if (l23.tag == 0u) {
                        std_collections$MutableMap$std_core$IndexSet$set_at__i32__bool(((vader_struct_vader_front_resolver$ImportTargetTable_t*) l3)->f_missing, l10, true);
                        l24 = ((vader_struct_vader_front_resolver$LoadedProject_t*) l2)->f_diags;
                        l25 = ((vader_struct_vader_front_resolver$ImportInfo_t*) l11)->f_binding_span;
                        l26 = l18.payload.s;
                        l27 = ((vader_struct_vader_front_resolver$ImportInfo_t*) l11)->f_path;
                        l28 = concat_5(1038u, l26, 1098u, l27, 1038u);
                        l29 = vader_support_diagnostics$resolver_error((uint8_t) 2, l25, l28);
                        vader_array_push_ref((vader_array_t*) l24, l29);
                    } else {
                        if (!(l23.tag == 892u)) {
                            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                        }
                        t0 = l23.payload.obj;
                        if (((vader_struct_vader_core_symbol$Symbol_t*) t0)->f_visibility == INT32_C(1)) {
                            std_collections$MutableMap$std_core$IndexSet$set_at__i32__bool(((vader_struct_vader_front_resolver$ImportTargetTable_t*) l3)->f_missing, l10, true);
                            l30 = ((vader_struct_vader_front_resolver$LoadedProject_t*) l2)->f_diags;
                            l31 = ((vader_struct_vader_front_resolver$ImportInfo_t*) l11)->f_binding_span;
                            l32 = l18.payload.s;
                            l33 = concat_3(1038u, l32, 1038u);
                            l34 = vader_support_diagnostics$resolver_error((uint8_t) 7, l31, l33);
                            vader_array_push_ref((vader_array_t*) l30, l34);
                        } else {
                            l35 = ((vader_struct_vader_front_resolver$ImportTargetTable_t*) l3)->f_symbol_targets;
                            l36 = l23.payload.obj;
                            l37 = l13.payload.s;
                            vader_struct_vader_front_resolver$SymbolTarget_t* _a2_obj = (vader_struct_vader_front_resolver$SymbolTarget_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$SymbolTarget_t));
                            vader_obj_header_init(_a2_obj, 1109u);
                            _a2_obj->f_symbol = l36;
                            _a2_obj->f_module_id = l37;
                            l38 = (void*) _a2_obj;
                            std_collections$MutableMap$std_core$IndexSet$set_at__i32__Any(l35, l10, vader_ref_box(l38));
                        }
                    }
                }
            }
        }
        l7 = (l7 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_front_resolver$with_displayable_impls(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    int64_t l3, l4, l10, l11;
    vader_box_t l5 = vader_box_null(), l7 = vader_box_null(), l9 = vader_box_null(), l15 = vader_box_null();
    vader_string_t l14 = 0;
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[4] = { &l5, &l7, &l9, &l15 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l6, &l8, &l12, &l13, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l14 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(239u, 0u, 13u, 1618u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct_toolchain_ast$Program_t*) l0)->f_decls;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        l5 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        if (l5.tag == 644u) {
            t0 = l5.payload.obj;
            l8 = ((vader_struct_toolchain_ast$EnumDecl_t*) t0)->f_decorators;
            l9 = vader_box_obj(0u, NULL);
            l10 = ((vader_array_t*) l8)->length;
            l11 = INT64_C(0);
            {
                while ((l11 < l10)) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) l8);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    l12 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l11);
                    t1 = __lambda_vader_front_resolver_2(l12);
                    if (t1) {
                        l9 = vader_ref_box(l12);
                        goto end_30;
                    }
                    l11 = (l11 + INT64_C(1));
                }
                l9 = vader_box_obj(0u, NULL);
            } end_30: ;
            l7 = l9;
            if (l7.tag == 0u) {
                l4 = (l4 + INT64_C(1));
                continue;
            }
            l6 = l7.payload.obj;
            l13 = l5.payload.obj;
            l14 = ((vader_struct_toolchain_ast$Program_t*) l0)->f_file;
            l15 = vader_front_resolver$displayable_impl(l13, l6, l14);
            vader_array_push_ref((vader_array_t*) l1, l15.payload.obj);
        }
        l4 = (l4 + INT64_C(1));
    }
    t1 = std_iter$is_empty__toolchain_ast_AssertDecl___toolchain_ast_ConstDecl___toolchain_ast_EnumDecl___toolchain_ast_FnDecl___toolchain_ast_ImplDecl___toolchain_ast_ImportDecl___toolchain_ast_StructDecl___toolchain_ast_TraitDecl___toolchain_ast_TypeAliasDecl(l1);
    if (!(t1)) {
        l2 = l0;
        l14 = ((vader_struct_toolchain_ast$Program_t*) l2)->f_file;
        l6 = ((vader_struct_toolchain_ast$Program_t*) l2)->f_span;
        l3 = ((vader_struct_toolchain_ast$Program_t*) l2)->f_id;
        l5 = ((vader_struct_toolchain_ast$Program_t*) l2)->f_module;
        l1 = std_core$$array$Add$add__toolchain_ast_AssertDecl___toolchain_ast_ConstDecl___toolchain_ast_EnumDecl___toolchain_ast_FnDecl___toolchain_ast_ImplDecl___toolchain_ast_ImportDecl___toolchain_ast_StructDecl___toolchain_ast_TraitDecl___toolchain_ast_TypeAliasDecl(((vader_struct_toolchain_ast$Program_t*) l0)->f_decls, l1);
        vader_struct_toolchain_ast$Program_t* _a3_obj = (vader_struct_toolchain_ast$Program_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$Program_t));
        vader_obj_header_init(_a3_obj, 682u);
        _a3_obj->f_file = l14;
        _a3_obj->f_span = l6;
        _a3_obj->f_id = l3;
        _a3_obj->f_module = l5;
        _a3_obj->f_decls = l1;
        t0 = (void*) _a3_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$zero_span(vader_string_t l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_toolchain_span$Position_t* _a0_obj = (vader_struct_toolchain_span$Position_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Position_t));
    vader_obj_header_init(_a0_obj, 711u);
    _a0_obj->f_file = l0;
    _a0_obj->f_offset = INT64_C(0);
    _a0_obj->f_line = INT32_C(1);
    _a0_obj->f_column = INT32_C(1);
    l1 = (void*) _a0_obj;
    vader_struct_toolchain_span$Position_t* _a1_obj = (vader_struct_toolchain_span$Position_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Position_t));
    vader_obj_header_init(_a1_obj, 711u);
    _a1_obj->f_file = l0;
    _a1_obj->f_offset = INT64_C(0);
    _a1_obj->f_line = INT32_C(1);
    _a1_obj->f_column = INT32_C(1);
    l2 = (void*) _a1_obj;
    vader_struct_toolchain_span$Span_t* _a2_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
    vader_obj_header_init(_a2_obj, 712u);
    _a2_obj->f_start = l1;
    _a2_obj->f_end = l2;
    t0 = (void*) _a2_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}
