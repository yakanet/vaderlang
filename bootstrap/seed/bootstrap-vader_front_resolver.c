#include "bootstrap.split.h"

static bool __lambda_vader_front_resolver_10(void* l0, vader_box_t l1);
static void* __lambda_vader_front_resolver_12(void* l0, void* l1);
static bool __lambda_vader_front_resolver_14(void* l0);
static bool __lambda_vader_front_resolver_15(vader_box_t l0);
static bool __lambda_vader_front_resolver_16(void* l0, vader_box_t l1);
static void __lambda_vader_front_resolver_18(void* l0, void* l1, vader_box_t l2);
static bool __lambda_vader_front_resolver_2(void* l0);
static void* __lambda_vader_front_resolver_21(void* l0);
static bool __lambda_vader_front_resolver_22(void* l0);
static vader_string_t __lambda_vader_front_resolver_23(void* l0);
static vader_box_t __lambda_vader_front_resolver_24(void* l0, vader_box_t l1);
static void* __lambda_vader_front_resolver_26(void* l0, void* l1);
static vader_string_t __lambda_vader_front_resolver_29(int64_t l0);
static bool __lambda_vader_front_resolver_31(void* l0);
static bool __lambda_vader_front_resolver_32(void* l0, void* l1);
static bool __lambda_vader_front_resolver_34(void* l0, void* l1);
static void* __lambda_vader_front_resolver_36(void* l0, void* l1);
static vader_string_t __lambda_vader_front_resolver_38(void* l0);
static void* __lambda_vader_front_resolver_39(void* l0, void* l1);
static bool __lambda_vader_front_resolver_41(void* l0, void* l1);
static bool __lambda_vader_front_resolver_43(vader_string_t l0);
static void* __lambda_vader_front_resolver_6(void* l0);
static bool __lambda_vader_front_resolver_7(void* l0);
static void* __lambda_vader_front_resolver_8(vader_box_t l0);
static bool __lambda_vader_front_resolver_9(void* l0);
static vader_string_t vader_front_resolver$absolute_path(vader_string_t l0);
static void vader_front_resolver$add_fn(void* l0, void* l1, vader_string_t l2, vader_string_t l3, void* l4, void* l5);
static void vader_front_resolver$add_leading_names(vader_box_t l0, vader_string_t l1, void* l2);
static vader_box_t vader_front_resolver$add_named(void* l0, uint8_t l1, vader_string_t l2, void* l3, uint8_t l4, vader_string_t l5, vader_string_t l6, void* l7, void* l8);
static void* vader_front_resolver$aliases_in(void* l0, vader_string_t l1);
static void* vader_front_resolver$aliases_read_by(vader_box_t l0, void* l1, void* l2);
static void* vader_front_resolver$anchor_impls(void* l0, void* l1, vader_string_t l2);
static void* vader_front_resolver$anchors_read(void* l0, void* l1);
static bool vader_front_resolver$any_has_body(void* l0);
static vader_string_t vader_front_resolver$arguments_type(vader_string_t l0, void* l1);
static vader_box_t vader_front_resolver$around_of(void* l0, void* l1, void* l2, void* l3);
static void vader_front_resolver$auto_bind_for_type_params(void* l0, vader_box_t l1);
static void* vader_front_resolver$baked_target_of(vader_box_t l0);
static void vader_front_resolver$bind(void* l0, vader_string_t l1, void* l2);
static void vader_front_resolver$bind_1(void* l0, vader_string_t l1, vader_box_t l2);
static void vader_front_resolver$bind_declared(void* l0, vader_string_t l1, void* l2);
static void vader_front_resolver$bind_header_name(void* l0, vader_box_t l1, uint8_t l2);
static void vader_front_resolver$bind_impl_params(void* l0, void* l1);
static void vader_front_resolver$bind_import(void* l0, vader_string_t l1, void* l2, vader_string_t l3, vader_box_t l4, vader_string_t l5, void* l6, void* l7);
static void vader_front_resolver$bind_let_binding(void* l0, vader_box_t l1, void* l2);
static void* vader_front_resolver$bind_local(void* l0, uint8_t l1, vader_string_t l2, void* l3);
static void* vader_front_resolver$bind_local_checked(void* l0, uint8_t l1, vader_string_t l2, void* l3);
static void vader_front_resolver$bind_param(void* l0, void* l1);
static void vader_front_resolver$bind_pattern(void* l0, vader_box_t l1);
static void vader_front_resolver$bind_trait_params(void* l0, void* l1, void* l2);
static void* vader_front_resolver$bind_type_param(void* l0, void* l1);
static void* vader_front_resolver$binding_clashes(void* l0, void* l1);
static void* vader_front_resolver$binding_span(vader_box_t l0);
static vader_string_t vader_front_resolver$bodies_folder(vader_string_t l0);
static vader_string_t vader_front_resolver$body_record_key(vader_string_t l0, void* l1, void* l2);
static vader_string_t vader_front_resolver$body_record_path(vader_string_t l0, vader_string_t l1, void* l2);
static void* vader_front_resolver$body_stages(void);
static void* vader_front_resolver$body_stages_of_driver(vader_box_t l0);
static bool vader_front_resolver$body_survives(void* l0, void* l1);
static void* vader_front_resolver$build_subst(void* l0, void* l1, void* l2);
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
static void* vader_front_resolver$clone_ident(void* l0);
static void vader_front_resolver$collect_decl(void* l0, vader_box_t l1, vader_string_t l2, vader_string_t l3, void* l4, void* l5, void* l6, void* l7);
static void vader_front_resolver$collect_deferred(void* l0);
static void* vader_front_resolver$collect_files(void* l0, vader_string_t l1, vader_string_t l2, void* l3, void* l4, void* l5, void* l6);
static void vader_front_resolver$collect_import(void* l0, void* l1, vader_string_t l2, vader_string_t l3, void* l4, void* l5, void* l6, void* l7);
static void* vader_front_resolver$collect_module(void* l0, vader_string_t l1, vader_string_t l2, void* l3, void* l4, void* l5, void* l6);
static void* vader_front_resolver$collect_module_no_index(void* l0, vader_string_t l1, void* l2);
static int64_t vader_front_resolver$count_sam_synthetics(void* l0);
static void* vader_front_resolver$declaration_index(void* l0);
static void vader_front_resolver$declare_loop_local(void* l0, void* l1);
static vader_box_t vader_front_resolver$declare_trait_self(void* l0, void* l1);
static void* vader_front_resolver$declare_type_param(void* l0, void* l1);
static void* vader_front_resolver$declared_by(void* l0, void* l1);
static void* vader_front_resolver$declared_decorators(void* l0);
static vader_box_t vader_front_resolver$declared_in(void* l0, vader_string_t l1, vader_string_t l2);
static void* vader_front_resolver$declared_interceptors(void* l0, void* l1);
static vader_box_t vader_front_resolver$declared_name(vader_box_t l0);
static vader_box_t vader_front_resolver$declared_name_through(vader_box_t l0, vader_string_t l1);
static bool vader_front_resolver$declared_outside_lambda(void* l0, vader_string_t l1);
static void* vader_front_resolver$declared_roots(void);
static void* vader_front_resolver$declared_roots$singleton(void);
static bool vader_front_resolver$declares_type(vader_box_t l0);
static int64_t vader_front_resolver$declaring_id(void* l0);
static vader_box_t vader_front_resolver$dependency_of(void* l0, void* l1, void* l2);
static void vader_front_resolver$detect_import_cycles(void* l0, void* l1, void* l2);
static vader_box_t vader_front_resolver$diagnose_import_path(vader_string_t l0, void* l1, vader_string_t l2, void* l3, void* l4, void* l5);
static void* vader_front_resolver$discarded_bodies(void* l0, vader_box_t l1);
static void vader_front_resolver$drain_load_queue(void* l0, void* l1);
static void* vader_front_resolver$driver_names(void* l0, vader_box_t l1);
static void* vader_front_resolver$driver_request(void* l0);
static void* vader_front_resolver$driver_sources(void* l0);
static void* vader_front_resolver$driver_stages(void);
static void* vader_front_resolver$driver_stages$singleton(void);
static void* vader_front_resolver$enter_file(void* l0, void* l1);
static vader_string_t vader_front_resolver$entry_folder_of(vader_string_t l0);
static void* vader_front_resolver$entry_namespace(vader_string_t l0, vader_string_t l1);
static bool vader_front_resolver$exports_only_functions(void* l0, void* l1, vader_string_t l2);
static void* vader_front_resolver$failed(void* l0, void* l1);
static vader_box_t vader_front_resolver$fallback_of_stmt(vader_box_t l0);
static void* vader_front_resolver$file_imports(void* l0, vader_string_t l1);
static vader_string_t vader_front_resolver$file_of(void* l0);
static void* vader_front_resolver$file_root_scope(void* l0, void* l1, void* l2, void* l3, void* l4);
static void* vader_front_resolver$file_scope(void* l0, void* l1, void* l2, void* l3, void* l4);
static void* vader_front_resolver$find_impl_trait_decl(vader_box_t l0, void* l1, void* l2, void* l3, void* l4, void* l5, void* l6);
static vader_box_t vader_front_resolver$find_module_id(void* l0, vader_string_t l1);
static vader_string_t vader_front_resolver$for_type_display_name(vader_box_t l0);
static vader_box_t vader_front_resolver$for_type_owner_sym(vader_box_t l0, void* l1, void* l2);
static int32_t vader_front_resolver$frame_count(void* l0);
static vader_string_t vader_front_resolver$framed_source(vader_string_t l0, vader_string_t l1, vader_string_t l2, vader_string_t l3);
static void* vader_front_resolver$function_clashes(void* l0, void* l1);
static vader_box_t vader_front_resolver$function_named(void* l0, vader_string_t l1);
static vader_string_t vader_front_resolver$generated_file(vader_string_t l0, vader_string_t l1);
static vader_string_t vader_front_resolver$generated_root_for(vader_box_t l0);
static void* vader_front_resolver$graft_body(void* l0, void* l1);
static bool vader_front_resolver$has_module(void* l0, vader_string_t l1);
static bool vader_front_resolver$has_reassignment(void* l0, void* l1);
static vader_box_t vader_front_resolver$home_root(vader_string_t l0, vader_string_t l1);
static vader_box_t vader_front_resolver$hook_diagnostic(void* l0);
static void* vader_front_resolver$import_paths_of(void* l0);
static uint8_t vader_front_resolver$importer_origin(void* l0, vader_string_t l1);
static vader_string_t vader_front_resolver$imports_text(void* l0);
static void* vader_front_resolver$include_paths(void* l0, void* l1, vader_string_t l2);
static void vader_front_resolver$index_declaration(void* l0, void* l1);
static void vader_front_resolver$ingest_module(void* l0, void* l1, void* l2);
static void vader_front_resolver$intercept_functions(void* l0, void* l1, void* l2);
static void* vader_front_resolver$interceptions_of(void* l0, vader_string_t l1, void* l2, void* l3, void* l4);
static void* vader_front_resolver$interface_name_of(vader_string_t l0);
static void* vader_front_resolver$io_error(vader_string_t l0, vader_string_t l1);
static bool vader_front_resolver$is_contract_decorator(void* l0);
static bool vader_front_resolver$is_core_file(void* l0);
static bool vader_front_resolver$is_generated_by(vader_string_t l0, vader_string_t l1);
static bool vader_front_resolver$is_host_bound(void* l0);
static bool vader_front_resolver$is_instance_of(vader_box_t l0, vader_string_t l1, void* l2);
static bool vader_front_resolver$is_named(vader_box_t l0, vader_string_t l1);
static bool vader_front_resolver$is_private_to(vader_box_t l0, vader_string_t l1);
static bool vader_front_resolver$is_proceed(vader_box_t l0, vader_string_t l1, vader_string_t l2);
static bool vader_front_resolver$is_reached(vader_box_t l0, void* l1, void* l2);
static bool vader_front_resolver$is_reached_1(vader_box_t l0, vader_string_t l1, vader_string_t l2, void* l3);
static bool vader_front_resolver$is_surface(vader_box_t l0, vader_string_t l1, vader_string_t l2);
static bool vader_front_resolver$is_test(vader_box_t l0);
static bool vader_front_resolver$is_trimmed(void* l0, void* l1);
static vader_string_t vader_front_resolver$late_body_origin(void* l0, vader_string_t l1);
static vader_string_t vader_front_resolver$late_fn_label(void* l0, vader_box_t l1);
static void* vader_front_resolver$late_fns_of(void* l0, vader_string_t l1, vader_string_t l2);
static vader_string_t vader_front_resolver$layer_function(vader_string_t l0, int64_t l1, int64_t l2);
static void* vader_front_resolver$layer_origin(void* l0, void* l1);
static vader_string_t vader_front_resolver$layer_text(void* l0, vader_string_t l1, void* l2, vader_box_t l3, void* l4, int64_t l5);
static void vader_front_resolver$load_baked_target(void* l0, void* l1);
static void* vader_front_resolver$load_project_with_overlay(vader_string_t l0, void* l1, void* l2, vader_box_t l3, vader_box_t l4, void* l5, bool l6, bool l7, bool l8);
static void vader_front_resolver$load_stage_imports(void* l0, int64_t l1, int64_t l2);
static void* vader_front_resolver$loaded_module(void* l0, void* l1, void* l2);
static vader_box_t vader_front_resolver$lookup(void* l0, vader_string_t l1);
static int32_t vader_front_resolver$lookup_frame_index(void* l0, vader_string_t l1);
static vader_box_t vader_front_resolver$lookup_subst(void* l0, vader_string_t l1);
static vader_box_t vader_front_resolver$lookup_trait_sym(vader_string_t l0, void* l1, void* l2, void* l3);
static void* vader_front_resolver$make_builtin_scope(void* l0);
static void* vader_front_resolver$manifest_at(vader_box_t l0);
static vader_string_t vader_front_resolver$manifest_root(vader_string_t l0, vader_string_t l1, vader_box_t l2);
static bool vader_front_resolver$matches_target(void* l0, void* l1);
static void vader_front_resolver$materialize_default_members(void* l0, void* l1, void* l2, void* l3);
static void vader_front_resolver$materialize_file_impl_members(void* l0, void* l1, void* l2, void* l3, void* l4);
static void vader_front_resolver$materialize_sam_members(void* l0, void* l1, void* l2, void* l3);
static void vader_front_resolver$merge_collected(void* l0, void* l1, void* l2);
static void* vader_front_resolver$mint_local(void* l0, uint8_t l1, vader_string_t l2, void* l3);
static vader_box_t vader_front_resolver$misplaced_module_at(vader_string_t l0, void* l1);
static vader_string_t vader_front_resolver$module_of(void* l0);
static void* vader_front_resolver$module_server_for(void* l0, void* l1);
static vader_box_t vader_front_resolver$module_text(void* l0, void* l1, void* l2, vader_string_t l3);
static void vader_front_resolver$name_declared_decorators(void* l0, vader_string_t l1, void* l2);
static vader_box_t vader_front_resolver$name_in_file_scope(vader_string_t l0, void* l1, void* l2, void* l3);
static vader_box_t vader_front_resolver$name_in_folder(vader_string_t l0, vader_string_t l1);
static void vader_front_resolver$name_sites(void* l0, vader_string_t l1, vader_box_t l2, vader_string_t l3, void* l4);
static bool vader_front_resolver$names_equal(vader_box_t l0, vader_box_t l1);
static bool vader_front_resolver$names_given(void* l0, vader_string_t l1, void* l2, vader_box_t l3, void* l4);
static void* vader_front_resolver$names_written_by(vader_box_t l0, void* l1, vader_string_t l2);
static void* vader_front_resolver$namespace_aliases(void* l0, void* l1);
static void* vader_front_resolver$new_scope(void* l0);
static void* vader_front_resolver$new_subst(void);
static vader_box_t vader_front_resolver$next_in_block(void* l0, int64_t l1);
static vader_string_t vader_front_resolver$normalized_path(vader_string_t l0);
static void vader_front_resolver$note_fallback_name(void* l0, vader_box_t l1, void* l2);
static void vader_front_resolver$note_rebind(void* l0, vader_box_t l1);
static void vader_front_resolver$note_uncovered(void* l0, void* l1, void* l2, void* l3, void* l4);
static void* vader_front_resolver$number_module_files(void* l0, void* l1);
static void* vader_front_resolver$only_reached(void* l0, void* l1);
static uint8_t vader_front_resolver$origin_of_root(vader_string_t l0);
static void* vader_front_resolver$package_folders(void* l0, void* l1);
static vader_box_t vader_front_resolver$package_in(void* l0, void* l1, void* l2);
static void* vader_front_resolver$parse_file(vader_string_t l0, vader_string_t l1, bool l2);
static void* vader_front_resolver$parse_level(void* l0, void* l1, bool l2);
static void* vader_front_resolver$parse_lot(void* l0, void* l1, bool l2);
static void* vader_front_resolver$parse_manifest(vader_string_t l0);
static vader_box_t vader_front_resolver$plain_ident(void* l0, vader_string_t l1);
static void* vader_front_resolver$plain_root(vader_string_t l0, uint8_t l1);
static void* vader_front_resolver$planned_body_stages(vader_box_t l0);
static void* vader_front_resolver$planned_source_stages(vader_box_t l0);
static void vader_front_resolver$pop(void* l0);
static vader_box_t vader_front_resolver$posix_or_null(vader_box_t l0);
static void vader_front_resolver$preresolve_imports(void* l0, void* l1, void* l2, void* l3, void* l4, void* l5);
static vader_box_t vader_front_resolver$private_type_of(vader_box_t l0, void* l1);
static void* vader_front_resolver$project_include_paths(vader_box_t l0, void* l1, void* l2);
static void* vader_front_resolver$provided_names(void* l0);
static bool vader_front_resolver$provides_body(void* l0);
static void vader_front_resolver$push(void* l0);
static vader_string_t vader_front_resolver$qualifier_of(void* l0);
static vader_box_t vader_front_resolver$reach_key(vader_box_t l0, void* l1);
static void* vader_front_resolver$read_and_parse(void* l0, void* l1, bool l2);
static vader_box_t vader_front_resolver$read_buffer_or_disk(void* l0, vader_string_t l1);
static void* vader_front_resolver$read_interfaces(void* l0);
static void* vader_front_resolver$read_manifest(vader_string_t l0);
static vader_box_t vader_front_resolver$read_recorded(vader_string_t l0);
static vader_string_t vader_front_resolver$read_with_overlay(void* l0, vader_string_t l1);
static void* vader_front_resolver$rebind_free_locals(void* l0);
static vader_string_t vader_front_resolver$record_key(vader_string_t l0, void* l1, void* l2);
static void* vader_front_resolver$recorded_plan(vader_string_t l0);
static vader_string_t vader_front_resolver$records_folder(vader_box_t l0);
static vader_box_t vader_front_resolver$refusal(void* l0, void* l1);
static vader_box_t vader_front_resolver$refused(void* l0, void* l1, vader_string_t l2);
static vader_box_t vader_front_resolver$repeated_interceptor(void* l0);
static void* vader_front_resolver$replay_warning(void* l0, vader_string_t l1);
static void* vader_front_resolver$replay_warning_at(void* l0, vader_string_t l1);
static void* vader_front_resolver$replayed_body_stages(vader_string_t l0);
static void* vader_front_resolver$replayed_diagnostics(void* l0);
static void* vader_front_resolver$replayed_stages(vader_string_t l0);
static void vader_front_resolver$report_unreassigned_mutables(void* l0);
static void* vader_front_resolver$reports_read(void* l0, void* l1);
static void* vader_front_resolver$request_files(void* l0);
static void* vader_front_resolver$required_methods(void* l0);
static vader_box_t vader_front_resolver$resolve_decl(vader_box_t l0, void* l1, void* l2, void* l3);
static vader_box_t vader_front_resolver$resolve_in(void* l0, vader_string_t l1);
static vader_box_t vader_front_resolver$resolve_lazy(vader_string_t l0, void* l1, void* l2, void* l3, void* l4, void* l5);
static void* vader_front_resolver$resolve_module_programs(void* l0, void* l1, vader_string_t l2, void* l3);
static vader_string_t vader_front_resolver$resolve_sidecar(vader_string_t l0, vader_string_t l1);
static vader_box_t vader_front_resolver$rooted_candidate(void* l0, vader_string_t l1);
static void vader_front_resolver$run_source_stages(void* l0, int64_t l1, void* l2, void* l3, void* l4, void* l5);
static vader_box_t vader_front_resolver$scan_folder(vader_string_t l0, void* l1, void* l2);
static void* vader_front_resolver$search_roots(vader_string_t l0, void* l1, vader_box_t l2, void* l3, void* l4);
static vader_box_t vader_front_resolver$seed_entry(vader_string_t l0, void* l1, void* l2);
static void vader_front_resolver$seed_leading(void* l0, void* l1, void* l2, void* l3);
static void vader_front_resolver$seed_wildcard_exports(void* l0, void* l1, void* l2, void* l3);
static void* vader_front_resolver$select_target_bodies(void* l0, vader_box_t l1, void* l2, void* l3);
static vader_box_t vader_front_resolver$selected_target_of(vader_box_t l0);
static void* vader_front_resolver$selector_exprs(void* l0);
static vader_box_t vader_front_resolver$sidecar_root(vader_string_t l0, vader_string_t l1);
static void* vader_front_resolver$sort_by_name(void* l0);
static void* vader_front_resolver$source_files(void* l0);
static void* vader_front_resolver$source_files_in(vader_string_t l0, void* l1);
static void* vader_front_resolver$source_stages(void);
static vader_string_t vader_front_resolver$span_origin(void* l0);
static vader_string_t vader_front_resolver$spread(int64_t l0);
static vader_string_t vader_front_resolver$stage_plan_path(vader_string_t l0);
static vader_string_t vader_front_resolver$stage_record_path(vader_string_t l0, vader_string_t l1, vader_string_t l2);
static vader_string_t vader_front_resolver$stage_records_dir(vader_string_t l0);
static vader_box_t vader_front_resolver$stage_serving(void* l0, vader_string_t l1);
static void* vader_front_resolver$stages_of_driver(vader_box_t l0);
static vader_box_t vader_front_resolver$state_name(vader_box_t l0, vader_string_t l1, vader_string_t l2);
static vader_box_t vader_front_resolver$state_struct(void* l0, vader_string_t l1, void* l2);
static void* vader_front_resolver$still_declared(void* l0, void* l1);
static vader_string_t vader_front_resolver$string_at(void* l0, vader_string_t l1, void* l2);
static void* vader_front_resolver$string_list(void* l0, vader_string_t l1, void* l2);
static vader_box_t vader_front_resolver$substitute_opt_type(vader_box_t l0, void* l1);
static void* vader_front_resolver$substitute_param(void* l0, void* l1);
static void* vader_front_resolver$substitute_params_disambiguated(void* l0, void* l1, void* l2, void* l3);
static vader_box_t vader_front_resolver$substitute_type_expr(vader_box_t l0, void* l1);
static void* vader_front_resolver$swap_root(void* l0, void* l1);
static void* vader_front_resolver$synth_inherited(void* l0, void* l1, int64_t l2);
static void* vader_front_resolver$synth_param_span(void* l0);
static void* vader_front_resolver$target_declarations(void* l0);
static vader_box_t vader_front_resolver$target_selectors(void* l0);
static void* vader_front_resolver$tested_or_not(void* l0, void* l1, void* l2);
static void* vader_front_resolver$tests_declared(void* l0);
static void* vader_front_resolver$through_aliases(void* l0, void* l1, void* l2, void* l3, void* l4, void* l5);
static vader_string_t vader_front_resolver$toolchain_folder(vader_box_t l0);
static vader_string_t vader_front_resolver$toolchain_runtime(void);
static vader_string_t vader_front_resolver$toolchain_runtime$singleton(void);
static vader_box_t vader_front_resolver$trait_at_its_params(void* l0);
static vader_box_t vader_front_resolver$trait_in_file_scope(vader_box_t l0, void* l1, void* l2, void* l3);
static vader_box_t vader_front_resolver$trait_named(void* l0, vader_string_t l1);
static vader_box_t vader_front_resolver$trait_owner_module(void* l0, void* l1, void* l2, void* l3);
static vader_box_t vader_front_resolver$trait_self_bound(void* l0);
static void* vader_front_resolver$trimmed_to_reached(void* l0);
static vader_box_t vader_front_resolver$try_read(vader_string_t l0);
static vader_string_t vader_front_resolver$tupled(void* l0);
static void* vader_front_resolver$two_folders(vader_string_t l0, void* l1);
static vader_box_t vader_front_resolver$type_head_name(vader_box_t l0);
static void* vader_front_resolver$type_span(void* l0);
static vader_box_t vader_front_resolver$union_in_bound(vader_box_t l0);
static void* vader_front_resolver$unloaded(void* l0, void* l1);
static void* vader_front_resolver$unplaced_param(void* l0, void* l1);
static void* vader_front_resolver$unplaced_span(void);
static vader_box_t vader_front_resolver$version_in(vader_string_t l0, void* l1);
static void vader_front_resolver$walk_block(void* l0, void* l1);
static void vader_front_resolver$walk_body(void* l0, void* l1);
static void vader_front_resolver$walk_decl(void* l0, vader_box_t l1);
static void vader_front_resolver$walk_declared_decorator(void* l0, void* l1);
static void vader_front_resolver$walk_decorator_args(void* l0, void* l1);
static void vader_front_resolver$walk_decorators(void* l0, void* l1);
static void vader_front_resolver$walk_defer(void* l0, void* l1);
static void vader_front_resolver$walk_enum_decl(void* l0, void* l1);
static void vader_front_resolver$walk_expr(void* l0, vader_box_t l1);
static void vader_front_resolver$walk_fn_decl(void* l0, void* l1);
static void vader_front_resolver$walk_for(void* l0, void* l1);
static void vader_front_resolver$walk_ident(void* l0, void* l1, bool l2);
static void vader_front_resolver$walk_if(void* l0, void* l1);
static void vader_front_resolver$walk_impl_decl(void* l0, void* l1);
static void vader_front_resolver$walk_import_cycle(vader_string_t l0, void* l1, void* l2, void* l3, void* l4);
static void vader_front_resolver$walk_lambda(void* l0, void* l1);
static void vader_front_resolver$walk_let(void* l0, void* l1);
static void vader_front_resolver$walk_match(void* l0, void* l1);
static void vader_front_resolver$walk_member_body(void* l0, void* l1);
static void vader_front_resolver$walk_opt_expr(void* l0, vader_box_t l1);
static void vader_front_resolver$walk_stmt(void* l0, vader_box_t l1);
static void vader_front_resolver$walk_struct_decl(void* l0, void* l1);
static void vader_front_resolver$walk_struct_lit(void* l0, void* l1);
static void vader_front_resolver$walk_struct_lit_items(void* l0, void* l1);
static void vader_front_resolver$walk_trait_decl(void* l0, void* l1);
static void vader_front_resolver$warn_block_after_else_value(void* l0, vader_box_t l1, vader_box_t l2);
static void vader_front_resolver$warn_collision(void* l0, vader_string_t l1, void* l2);
static void* vader_front_resolver$wildcard_ambiguities(void* l0, void* l1, void* l2, void* l3);
static bool vader_front_resolver$wildcard_exposable(uint8_t l0);
static void vader_front_resolver$wire_module(void* l0, void* l1, void* l2, void* l3);
static void* vader_front_resolver$wit_diagnostic(void* l0);
static void* vader_front_resolver$with_compiler_stages(void* l0);
static void* vader_front_resolver$with_written_texts(void* l0, void* l1);
static void* vader_front_resolver$without_tests(void* l0, vader_string_t l1);
static vader_box_t vader_front_resolver$wrap_file(void* l0, vader_string_t l1, void* l2, void* l3, void* l4, void* l5);
static bool vader_front_resolver$writes_given(void* l0, vader_string_t l1, void* l2, void* l3);
static vader_box_t vader_front_resolver$written_module(void* l0, vader_box_t l1, vader_string_t l2, void* l3, void* l4);
static vader_box_t vader_front_resolver$written_origin(void* l0, vader_string_t l1, void* l2, void* l3);
static void* vader_front_resolver$zero_span(vader_string_t l0);

vader_box_t vader_fn_tramp___lambda_vader_front_resolver_20(void* env, vader_box_t a0, vader_box_t a1) {
	(void) env;
	return vader_box_bool(640u, __lambda_vader_front_resolver_20(a0.payload.obj, a1.payload.obj));
}

vader_fn_t vader_fn_static___lambda_vader_front_resolver_20 = {
	VADER_STATIC_HEADER(612u), (void*) &vader_fn_tramp___lambda_vader_front_resolver_20, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_resolver_28(void* env) {
	(void) env;
	return vader_ref_box(__lambda_vader_front_resolver_28());
}

vader_fn_t vader_fn_static___lambda_vader_front_resolver_28 = {
	VADER_STATIC_HEADER(524u), (void*) &vader_fn_tramp___lambda_vader_front_resolver_28, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_resolver_30(void* env) {
	(void) env;
	return vader_ref_box(__lambda_vader_front_resolver_30());
}

vader_fn_t vader_fn_static___lambda_vader_front_resolver_30 = {
	VADER_STATIC_HEADER(528u), (void*) &vader_fn_tramp___lambda_vader_front_resolver_30, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_resolver_5(void* env, vader_box_t a0) {
	(void) env;
	return vader_ref_box(__lambda_vader_front_resolver_5(a0.payload.obj));
}

vader_fn_t vader_fn_static___lambda_vader_front_resolver_5 = {
	VADER_STATIC_HEADER(617u), (void*) &vader_fn_tramp___lambda_vader_front_resolver_5, NULL,
};

vader_box_t vader_fn_tramp_vader_front_resolver$declared_roots$keep(void* env) {
	(void) env;
	vader_front_resolver$declared_roots$keep();
	return vader_box_obj(643u, NULL);
}

vader_fn_t vader_fn_static_vader_front_resolver$declared_roots$keep = {
	VADER_STATIC_HEADER(542u), (void*) &vader_fn_tramp_vader_front_resolver$declared_roots$keep,
	NULL,
};

vader_box_t vader_fn_tramp_vader_front_resolver$driver_stages$keep(void* env) {
	(void) env;
	vader_front_resolver$driver_stages$keep();
	return vader_box_obj(643u, NULL);
}

vader_fn_t vader_fn_static_vader_front_resolver$driver_stages$keep = {
	VADER_STATIC_HEADER(542u), (void*) &vader_fn_tramp_vader_front_resolver$driver_stages$keep,
	NULL,
};

vader_box_t vader_fn_tramp_vader_front_resolver$toolchain_runtime$keep(void* env) {
	(void) env;
	vader_front_resolver$toolchain_runtime$keep();
	return vader_box_obj(643u, NULL);
}

vader_fn_t vader_fn_static_vader_front_resolver$toolchain_runtime$keep = {
	VADER_STATIC_HEADER(542u), (void*) &vader_fn_tramp_vader_front_resolver$toolchain_runtime$keep,
	NULL,
};

vader_box_t vader_fn_lift___lambda_vader_front_resolver_0(void* env, vader_box_t a0) {
	return vader_box_bool(640u, __lambda_vader_front_resolver_0(env, a0.payload.obj));
}

vader_box_t vader_fn_lift___lambda_vader_front_resolver_3(void* env) {
	return vader_ref_box(__lambda_vader_front_resolver_3(env));
}

vader_box_t vader_fn_lift___lambda_vader_front_resolver_44(void* env, vader_box_t a0) {
	return __lambda_vader_front_resolver_44(env, a0.payload.obj);
}

bool __lambda_vader_front_resolver_0(void* l0, void* l1) {
	void* l2 = NULL;
	vader_string_t l3 = 0;
	bool t0;
	vader_string_t t1 = 0;
	vader_box_t t2 = vader_box_null();
	vader_box_t* gc_roots[1] = { &t2 };
	void** gc_raw_roots[3] = { &l0, &l1, &l2 };
	vader_string_t* gc_atom_roots[2] = { &l3, &t1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_vader_front_resolver$GeneratedCode_t*) ((vader_struct___lambda_env_vader_front_resolver_1_t*) l0)->f_cap_0)->f_shipped_interfaces;
	l3 = ((vader_struct_vader_front_resolver$GeneratedSource_t*) l1)->f_file;
	t0 = std_collections$Set$std_core$Contains$contains__string(l2, l3);
	if (!(t0)) {
		{ vader_gc_top = gc_frame.prev; return true; }
	}
	l2 = ((vader_struct___lambda_env_vader_front_resolver_1_t*) l0)->f_cap_1;
	t1 = ((vader_struct_vader_front_resolver$GeneratedSource_t*) l1)->f_file;
	vader_fn_t* _a0_fnobj = (vader_fn_t*) l2;
	t2 = ((vader_fn_erased_sig_1_t) _a0_fnobj->code)(_a0_fnobj->env, vader_box_string(642u, t1));
	t0 = t2.payload.b;
	{ bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool __lambda_vader_front_resolver_10(void* l0, vader_box_t l1) {
	uint8_t l2;
	vader_string_t l3 = 0;
	vader_box_t t0 = vader_box_null();
	bool t1;
	vader_box_t* gc_roots[2] = { &l1, &t0 };
	void** gc_raw_roots[1] = { &l0 };
	vader_string_t* gc_atom_roots[1] = { &l3 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	t0 = toolchain_stage$Stage$describe$$dispatch(l1);
	l2 = ((vader_struct_toolchain_stage$ModuleSpec_t*) t0.payload.obj)->f_form;
	l3 = ((vader_struct___lambda_env_vader_front_resolver_11_t*) l0)->f_cap_0;
	t1 = toolchain_stage$serves_path(l2, l3);
	{ bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* __lambda_vader_front_resolver_12(void* l0, void* l1) {
	void* l2 = NULL;
	bool l3;
	void* t0 = NULL;
	void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct___lambda_env_vader_front_resolver_13_t*) l0)->f_cap_0;
	l3 = ((vader_struct___lambda_env_vader_front_resolver_13_t*) l0)->f_cap_1;
	t0 = vader_front_resolver$read_and_parse(l1, l2, l3);
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool __lambda_vader_front_resolver_14(void* l0) {
	void* l1;
	int64_t l2, l3;
	vader_box_t t0;
	bool t1;
	l1 = ((vader_struct_toolchain_stage$SourceSpec_t*) l0)->f_given;
	l2 = vader_array_length(((vader_array_t*) l1));
	l3 = INT64_C(0);
	while ((l3 < l2)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		t0 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l3);
		t1 = __lambda_vader_front_resolver_15(t0);
		if (t1) {
			return true;
		}
		l3 = (l3 + INT64_C(1));
	}
	return false;
}

static bool __lambda_vader_front_resolver_15(vader_box_t l0) {
	return l0.tag == 1294u;
}

static bool __lambda_vader_front_resolver_16(void* l0, vader_box_t l1) {
	void* l2 = NULL;
	void* l4 = NULL;
	void* l5 = NULL;
	vader_string_t l3 = 0;
	bool t0;
	vader_box_t* gc_roots[1] = { &l1 };
	void** gc_raw_roots[4] = { &l0, &l2, &l4, &l5 };
	vader_string_t* gc_atom_roots[1] = { &l3 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct___lambda_env_vader_front_resolver_17_t*) l0)->f_cap_0;
	l3 = ((vader_struct___lambda_env_vader_front_resolver_17_t*) l0)->f_cap_1;
	l4 = ((vader_struct___lambda_env_vader_front_resolver_17_t*) l0)->f_cap_2;
	l5 = ((vader_struct___lambda_env_vader_front_resolver_17_t*) l0)->f_cap_3;
	t0 = vader_front_resolver$names_given(l2, l3, l4, l1, l5);
	{ bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void __lambda_vader_front_resolver_18(void* l0, void* l1, vader_box_t l2) {
	void* l3 = NULL;
	void* l6 = NULL;
	vader_string_t l4 = 0;
	vader_string_t l5 = 0;
	bool t0;
	vader_box_t* gc_roots[1] = { &l2 };
	void** gc_raw_roots[4] = { &l0, &l1, &l3, &l6 };
	vader_string_t* gc_atom_roots[2] = { &l4, &l5 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	if (((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_body.tag == 0u) {
		t0 = toolchain_ast$has_compiler_decorator(((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_decorators, (uint8_t) 14);
		if (t0) {
			{ vader_gc_top = gc_frame.prev; return; }
		}
		l3 = ((vader_struct___lambda_env_vader_front_resolver_19_t*) l0)->f_cap_0;
		l4 = ((vader_struct___lambda_env_vader_front_resolver_19_t*) l0)->f_cap_1;
		l5 = ((vader_struct___lambda_env_vader_front_resolver_19_t*) l0)->f_cap_2;
		vader_struct_vader_front_resolver$LateFn_t* _a0_obj = (vader_struct_vader_front_resolver$LateFn_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$LateFn_t));
		vader_obj_header_init(_a0_obj, 1793u);
		_a0_obj->f_module = l4;
		_a0_obj->f_decl = l1;
		_a0_obj->f_owner = l2;
		_a0_obj->f_stage = l5;
		l6 = (void*) _a0_obj;
		vader_array_push_ref((vader_array_t*) l3, l6);
		{ vader_gc_top = gc_frame.prev; return; }
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static bool __lambda_vader_front_resolver_2(void* l0) {
	vader_string_t t0;
	bool t1;
	t0 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) ((vader_struct_toolchain_diagnostics$Diagnostic_t*) l0)->f_primary)->f_start)->f_file;
	t1 = vader_front_resolver$is_generated_file(t0);
	return t1;
}

bool __lambda_vader_front_resolver_20(void* l0, void* l1) {
	vader_string_t l2, l3;
	bool t0;
	l2 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_name;
	l3 = ((vader_struct_vader_core_symbol$Symbol_t*) l1)->f_name;
	t0 = std_string$compare_ascending(l2, l3);
	return t0;
}

static void* __lambda_vader_front_resolver_21(void* l0) {
	void* t0;
	t0 = toolchain_ast$module_decorators(((vader_struct_vader_front_resolver$SourceFile_t*) l0)->f_program);
	return t0;
}

static bool __lambda_vader_front_resolver_22(void* l0) {
	void* l1 = NULL;
	int64_t l2, l3;
	vader_box_t t0 = vader_box_null();
	bool t1;
	vader_box_t* gc_roots[1] = { &t0 };
	void** gc_raw_roots[2] = { &l0, &l1 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l1 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) l0)->f_program)->f_decls;
	l2 = vader_array_length(((vader_array_t*) l1));
	l3 = INT64_C(0);
	while ((l3 < l2)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		t0 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l3);
		t1 = vader_front_resolver$is_test(t0);
		if (t1) {
			{ vader_gc_top = gc_frame.prev; return true; }
		}
		l3 = (l3 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return false; }
}

static vader_string_t __lambda_vader_front_resolver_23(void* l0) {
	vader_string_t t0;
	t0 = ((vader_struct_toolchain_ast$FnParam_t*) l0)->f_name;
	return t0;
}

static vader_box_t __lambda_vader_front_resolver_24(void* l0, vader_box_t l1) {
	void* l2 = NULL;
	vader_box_t t0 = vader_box_null();
	vader_box_t* gc_roots[2] = { &l1, &t0 };
	void** gc_raw_roots[2] = { &l0, &l2 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct___lambda_env_vader_front_resolver_25_t*) l0)->f_cap_0;
	t0 = vader_front_resolver$substitute_type_expr(l1, l2);
	{ vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* __lambda_vader_front_resolver_26(void* l0, void* l1) {
	void* l2 = NULL;
	void* t0 = NULL;
	void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct___lambda_env_vader_front_resolver_27_t*) l0)->f_cap_0;
	t0 = vader_front_resolver$unplaced_param(l1, l2);
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_vader_front_resolver_28(void) {
	void* t0 = NULL;
	void** gc_raw_roots[1] = { &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
	t0 = (void*) _a0_arr;
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t __lambda_vader_front_resolver_29(int64_t l0) {
	void* l1 = NULL;
	int64_t l2;
	vader_string_t t0 = 0;
	void** gc_raw_roots[1] = { &l1 };
	vader_string_t* gc_atom_roots[1] = { &t0 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l1 = (void*) vader_buffer_new((size_t) INT64_C(25));
	l2 = INT64_C(0);
	l2 = std_core$write_string_at(l1, l2, 2007u);
	l2 = std_core$write_int(l1, l2, l0);
	t0 = std_core$finish_buffer(l1, l2);
	{ vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_vader_front_resolver_3(void* l0) {
	void* l1 = NULL;
	void* l2 = NULL;
	bool l3;
	void* t0 = NULL;
	void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l1 = ((vader_struct___lambda_env_vader_front_resolver_4_t*) l0)->f_cap_0;
	l2 = ((vader_struct___lambda_env_vader_front_resolver_4_t*) l0)->f_cap_1;
	l3 = ((vader_struct___lambda_env_vader_front_resolver_4_t*) l0)->f_cap_2;
	t0 = vader_front_resolver$parse_lot(l1, l2, l3);
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_vader_front_resolver_30(void) {
	void* t0 = NULL;
	void** gc_raw_roots[1] = { &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(224u, 0u, 13u, 1491u);
	t0 = (void*) _a0_arr;
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool __lambda_vader_front_resolver_31(void* l0) {
	vader_string_t t0 = 0;
	bool t1;
	void** gc_raw_roots[1] = { &l0 };
	vader_string_t* gc_atom_roots[1] = { &t0 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	t0 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_span)->f_start)->f_file;
	t1 = vader_front_resolver$is_generated_by(t0, 2347u);
	{ bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool __lambda_vader_front_resolver_32(void* l0, void* l1) {
	vader_box_t l2;
	vader_string_t l3;
	l2 = ((vader_struct_toolchain_ast$ImportName_t*) l1)->f_alias;
	l3 = ((vader_struct___lambda_env_vader_front_resolver_33_t*) l0)->f_cap_0;
	return vader_box_eq(l2, vader_box_string(642u, l3));
}

static bool __lambda_vader_front_resolver_34(void* l0, void* l1) {
	vader_string_t l2, l3;
	l2 = ((vader_struct_toolchain_ast$ImportName_t*) l1)->f_name;
	l3 = ((vader_struct___lambda_env_vader_front_resolver_35_t*) l0)->f_cap_0;
	if (l2 == l3) {
		return !(((vader_struct_toolchain_ast$ImportName_t*) l1)->f_alias.tag == 0u);
	}
	return false;
}

static void* __lambda_vader_front_resolver_36(void* l0, void* l1) {
	void* l2 = NULL;
	void* l4 = NULL;
	void* l5 = NULL;
	vader_string_t l3 = 0;
	vader_string_t l6 = 0;
	void* t0 = NULL;
	void** gc_raw_roots[6] = { &l0, &l1, &l2, &l4, &l5, &t0 };
	vader_string_t* gc_atom_roots[2] = { &l3, &l6 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = l1;
	l3 = ((vader_struct_toolchain_protocol$ReportFrame_t*) l2)->f_code;
	l4 = ((vader_struct_toolchain_protocol$ReportFrame_t*) l1)->f_span;
	l5 = ((vader_struct_vader_front_resolver$DriverNames_t*) ((vader_struct___lambda_env_vader_front_resolver_37_t*) l0)->f_cap_0)->f_read;
	l4 = toolchain_protocol$renamed_span(l4, l5);
	l6 = ((vader_struct_toolchain_protocol$ReportFrame_t*) l2)->f_detail;
	vader_struct_toolchain_protocol$ReportFrame_t* _a0_obj = (vader_struct_toolchain_protocol$ReportFrame_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_protocol$ReportFrame_t));
	vader_obj_header_init(_a0_obj, 1283u);
	_a0_obj->f_code = l3;
	_a0_obj->f_span = l4;
	_a0_obj->f_detail = l6;
	t0 = (void*) _a0_obj;
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t __lambda_vader_front_resolver_38(void* l0) {
	vader_string_t t0;
	t0 = ((vader_struct_toolchain_ast$Program_t*) l0)->f_file;
	return t0;
}

static void* __lambda_vader_front_resolver_39(void* l0, void* l1) {
	void* l2 = NULL;
	void* t0 = NULL;
	void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_vader_front_resolver$DriverNames_t*) ((vader_struct___lambda_env_vader_front_resolver_40_t*) l0)->f_cap_0)->f_read;
	t0 = toolchain_protocol$renamed_span(l1, l2);
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool __lambda_vader_front_resolver_41(void* l0, void* l1) {
	vader_string_t l2, l3;
	l2 = ((vader_struct_vader_core_wit$WitOwner_t*) ((vader_struct_vader_core_wit$WitInterface_t*) l1)->f_owner)->f_interface;
	l3 = ((vader_struct___lambda_env_vader_front_resolver_42_t*) l0)->f_cap_0;
	return l2 == l3;
}

static bool __lambda_vader_front_resolver_43(vader_string_t l0) {
	bool t0;
	t0 = std_string$ends_with(l0, 533u);
	return t0;
}

vader_box_t __lambda_vader_front_resolver_44(void* l0, void* l1) {
	void* l2 = NULL;
	void* l3 = NULL;
	vader_box_t t0 = vader_box_null();
	vader_box_t* gc_roots[1] = { &t0 };
	void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct___lambda_env_vader_front_resolver_45_t*) l0)->f_cap_0;
	l3 = ((vader_struct___lambda_env_vader_front_resolver_45_t*) l0)->f_cap_1;
	t0 = vader_front_resolver$dependency_of(l2, l3, l1);
	{ vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_vader_front_resolver_5(void* l0) {
	void* t0 = NULL;
	void** gc_raw_roots[2] = { &l0, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	t0 = vader_host_std_core$Runtime$deep_copy__string__(((vader_struct_vader_front_resolver$DiscoveredModule_t*) l0)->f_files);
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* __lambda_vader_front_resolver_6(void* l0) {
	return l0;
}

static bool __lambda_vader_front_resolver_7(void* l0) {
	bool t0;
	t0 = std_collections$is_empty__string__string(((vader_struct_vader_front_resolver$DiscoveredModule_t*) l0)->f_texts);
	return t0;
}

static void* __lambda_vader_front_resolver_8(vader_box_t l0) {
	vader_box_t t0 = vader_box_null();
	vader_box_t* gc_roots[2] = { &l0, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 0u, gc_roots, NULL, 0u, NULL };
	vader_gc_top = &gc_frame;
	t0 = toolchain_stage$Stage$describe$$dispatch(l0);
	{ void* __vret = t0.payload.obj; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool __lambda_vader_front_resolver_9(void* l0) {
	vader_string_t t0;
	bool t1;
	t0 = ((vader_struct_vader_front_resolver$SourceFile_t*) l0)->f_path;
	t1 = vader_front_resolver$is_generated_file(t0);
	return t1;
}

void* vader_front_resolver$DisplayableStage$toolchain_stage$Stage$describe(void* l0) {
	void* l1 = NULL;
	void* l2 = NULL;
	void* t0 = NULL;
	void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	vader_struct_toolchain_stage$DecoratedWith_t* _a0_obj = (vader_struct_toolchain_stage$DecoratedWith_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_stage$DecoratedWith_t));
	vader_obj_header_init(_a0_obj, 1293u);
	_a0_obj->f_marker = (uint8_t) 12;
	t0 = (void*) _a0_obj;
	vader_array_t* _a1_arr = vader_array_new(490u, 1u, 13u, 2546u);
	((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = t0;
	l1 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(490u, 0u, 13u, 2546u);
	l2 = (void*) _a2_arr;
	vader_struct_toolchain_stage$SourceSpec_t* _a3_obj = (vader_struct_toolchain_stage$SourceSpec_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_stage$SourceSpec_t));
	vader_obj_header_init(_a3_obj, 1301u);
	_a3_obj->f_name = 2347u;
	_a3_obj->f_given = l1;
	_a3_obj->f_generates = l2;
	t0 = (void*) _a3_obj;
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_front_resolver$DisplayableStage$toolchain_stage$Stage$run(void* l0, void* l1) {
	void* l2 = NULL;
	void* l3 = NULL;
	void* l4 = NULL;
	void* l7 = NULL;
	void* l11 = NULL;
	void* l12 = NULL;
	void* l15 = NULL;
	void* l18 = NULL;
	void* l22 = NULL;
	int64_t l5, l6, l8, l9, l16, l17;
	vader_box_t l10 = vader_box_null(), l13 = vader_box_null();
	vader_string_t l14 = 0;
	vader_string_t l19 = 0;
	vader_string_t l20 = 0;
	vader_string_t l21 = 0;
	void* t0 = NULL;
	vader_string_t t1 = 0;
	vader_box_t* gc_roots[2] = { &l10, &l13 };
	void** gc_raw_roots[12] = { &l0, &l1, &l2, &l3, &l4, &l7, &l11, &l12, &l15, &l18, &l22, &t0 };
	vader_string_t* gc_atom_roots[5] = { &l14, &l19, &l20, &l21, &t1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
	t0 = (void*) _a0_arr;
	vader_struct_std_string__builder$StringBuilder_t* _a1_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
	vader_obj_header_init(_a1_obj, 1139u);
	_a1_obj->f_parts = t0;
	l2 = (void*) _a1_obj;
	vader_array_t* _a2_arr = vader_array_new(104u, 0u, 13u, 1289u);
	l3 = (void*) _a2_arr;
	l4 = ((vader_struct_toolchain_stage$Sources_t*) l1)->f_files;
	l5 = vader_array_length(((vader_array_t*) l4));
	l6 = INT64_C(0);
	while ((l6 < l5)) {
		vader_array_t* _a3_slotarr = ((vader_array_t*) l4);
		VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
		t0 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l6);
		l7 = ((vader_struct_toolchain_ast$Program_t*) t0)->f_decls;
		l8 = vader_array_length(((vader_array_t*) l7));
		l9 = INT64_C(0);
		while ((l9 < l8)) {
			vader_array_t* _a4_slotarr = ((vader_array_t*) l7);
			VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
			l10 = vader_array_ref_load_box(_a4_slotarr->buf, vader_array_offset(_a4_slotarr) + (size_t) l9);
			if (l10.tag == 1172u) {
				l11 = l10.payload.obj;
				l13 = toolchain_ast$find_compiler_decorator(((vader_struct_toolchain_ast$EnumDecl_t*) l11)->f_decorators, (uint8_t) 12);
				if (l13.tag == 0u) {
					l9 = (l9 + INT64_C(1));
					continue;
				}
				l12 = l13.payload.obj;
				t1 = ((vader_struct_toolchain_ast$EnumDecl_t*) l11)->f_name;
				l14 = concat_2(t1, 178u);
				std_string__builder$append(l2, l14);
				std_string__builder$append(l2, 41u);
				l15 = ((vader_struct_toolchain_ast$EnumDecl_t*) l11)->f_variants;
				l16 = vader_array_length(((vader_array_t*) l15));
				l17 = INT64_C(0);
				while ((l17 < l16)) {
					vader_array_t* _a5_slotarr = ((vader_array_t*) l15);
					VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
					l18 = vader_array_ref_load_obj(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) l17);
					l19 = ((vader_struct_toolchain_ast$EnumVariant_t*) l18)->f_name;
					l20 = ((vader_struct_toolchain_ast$EnumVariant_t*) l18)->f_name;
					l21 = concat_5(23u, l19, 79u, l20, 316u);
					std_string__builder$append(l2, l21);
					l17 = (l17 + INT64_C(1));
				}
				std_string__builder$append(l2, 42u);
				l22 = ((vader_struct_toolchain_ast$Decorator_t*) l12)->f_span;
				vader_array_push_ref((vader_array_t*) l3, l22);
			}
			l9 = (l9 + INT64_C(1));
		}
		l6 = (l6 + INT64_C(1));
	}
	l14 = std_string__builder$StringBuilder$std_core$Display$to_string(l2);
	vader_array_t* _a6_arr = vader_array_new(93u, 0u, 13u, 1245u);
	l2 = (void*) _a6_arr;
	vader_struct_toolchain_stage$Generated_t* _a7_obj = (vader_struct_toolchain_stage$Generated_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_stage$Generated_t));
	vader_obj_header_init(_a7_obj, 1295u);
	_a7_obj->f_text = l14;
	_a7_obj->f_anchors = l3;
	_a7_obj->f_diagnostics = l2;
	t0 = (void*) _a7_obj;
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_front_resolver$LoadFiles$toolchain_stage$BuildFiles$list_folder(void* l0, vader_string_t l1) {
	vader_box_t t0;
	t0 = std_fs$read_dir(l1);
	return t0;
}

vader_box_t vader_front_resolver$LoadFiles$toolchain_stage$BuildFiles$read_text(void* l0, vader_string_t l1) {
	vader_box_t t0;
	t0 = vader_front_resolver$read_buffer_or_disk(((vader_struct_vader_front_resolver$LoadFiles_t*) l0)->f_overlay, l1);
	return t0;
}

void* vader_front_resolver$ReplayedBodyStage$toolchain_stage$Stage$describe(void* l0) {
	vader_string_t t0 = 0;
	void* t1 = NULL;
	void** gc_raw_roots[2] = { &l0, &t1 };
	vader_string_t* gc_atom_roots[1] = { &t0 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	t0 = ((vader_struct_vader_front_resolver$ReplayedBodyStage_t*) l0)->f_name;
	vader_struct_toolchain_stage$BodySpec_t* _a0_obj = (vader_struct_toolchain_stage$BodySpec_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_stage$BodySpec_t));
	vader_obj_header_init(_a0_obj, 1292u);
	_a0_obj->f_name = t0;
	t1 = (void*) _a0_obj;
	{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_front_resolver$ReplayedBodyStage$toolchain_stage$Stage$run(void* l0, void* l1) {
	void* l2 = NULL;
	void* l3 = NULL;
	void* l6 = NULL;
	void* l7 = NULL;
	void* l9 = NULL;
	vader_string_t l4 = 0;
	vader_string_t l5 = 0;
	vader_box_t l8 = vader_box_null();
	void* t0 = NULL;
	void* t2 = NULL;
	vader_string_t t1 = 0;
	vader_box_t* gc_roots[1] = { &l8 };
	void** gc_raw_roots[9] = { &l0, &l1, &l2, &l3, &l6, &l7, &l9, &t0, &t2 };
	vader_string_t* gc_atom_roots[3] = { &l4, &l5, &t1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = vader_front_resolver$driver_request(l1);
	l3 = ((vader_struct_toolchain_ast$FnDecl_t*) ((vader_struct_toolchain_stage$BodyRequest_t*) l1)->f_decl)->f_name_span;
	l4 = ((vader_struct_vader_front_resolver$ReplayedBodyStage_t*) l0)->f_name;
	l5 = ((vader_struct_toolchain_ast$FnDecl_t*) ((vader_struct_toolchain_stage$BodyRequest_t*) l1)->f_decl)->f_name;
	l4 = concat_5(1307u, l4, 1411u, l5, 1321u);
	t0 = vader_front_resolver$replay_warning_at(l3, l4);
	vader_array_t* _a0_arr = vader_array_new(93u, 1u, 13u, 1245u);
	((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = t0;
	l6 = (void*) _a0_arr;
	vader_struct_toolchain_stage$Body_t* _a1_obj = (vader_struct_toolchain_stage$Body_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_stage$Body_t));
	vader_obj_header_init(_a1_obj, 1290u);
	_a1_obj->f_text = 3800u;
	_a1_obj->f_diagnostics = l6;
	l6 = (void*) _a1_obj;
	l4 = ((vader_struct_vader_front_resolver$ReplayedBodyStage_t*) l0)->f_project_root;
	l5 = ((vader_struct_vader_front_resolver$ReplayedBodyStage_t*) l0)->f_name;
	t1 = vader_front_resolver$body_record_path(l4, l5, l2);
	l8 = vader_front_resolver$read_recorded(t1);
	if (l8.tag == 0u) {
		{ void* __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l7 = l8.payload.obj;
	l8 = ((vader_struct_vader_front_resolver$Recorded_t*) l7)->f_answer;
	if (!(l8.tag == 1270u)) {
		{ void* __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l6 = vader_front_resolver$request_files(l2);
	l4 = ((vader_struct_vader_front_resolver$ReplayedBodyStage_t*) l0)->f_project_root;
	l6 = vader_front_resolver$driver_names(l6, vader_box_string(642u, l4));
	t0 = l8.payload.obj;
	t2 = vader_front_resolver$reports_read(((vader_struct_toolchain_protocol$BodyFrame_t*) t0)->f_reports, l6);
	l9 = vader_front_resolver$replayed_diagnostics(t2);
	l4 = ((vader_struct_vader_front_resolver$Recorded_t*) l7)->f_key;
	t1 = ((vader_struct_vader_front_resolver$ReplayedBodyStage_t*) l0)->f_name;
	l5 = vader_front_resolver$body_record_key(t1, l2, l6);
	if (l4 != l5) {
		l4 = ((vader_struct_vader_front_resolver$ReplayedBodyStage_t*) l0)->f_name;
		l5 = ((vader_struct_toolchain_stage$BodyRequest_t*) l1)->f_module_name;
		l4 = concat_5(1307u, l4, 1571u, l5, 1307u);
		l2 = vader_front_resolver$replay_warning_at(l3, l4);
		vader_array_push_ref((vader_array_t*) l9, l2);
	}
	t0 = l8.payload.obj;
	t1 = ((vader_struct_toolchain_protocol$BodyFrame_t*) t0)->f_text;
	vader_struct_toolchain_stage$Body_t* _a2_obj = (vader_struct_toolchain_stage$Body_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_stage$Body_t));
	vader_obj_header_init(_a2_obj, 1290u);
	_a2_obj->f_text = t1;
	_a2_obj->f_diagnostics = l9;
	t0 = (void*) _a2_obj;
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_front_resolver$ReplayedStage$toolchain_stage$Stage$describe(void* l0) {
	return ((vader_struct_vader_front_resolver$ReplayedStage_t*) l0)->f_spec;
}

void* vader_front_resolver$ReplayedStage$toolchain_stage$Stage$run(void* l0, void* l1) {
	vader_string_t l2 = 0;
	vader_string_t l3 = 0;
	vader_string_t l4 = 0;
	void* l5 = NULL;
	void* l6 = NULL;
	void* l8 = NULL;
	vader_box_t l7 = vader_box_null();
	void* t0 = NULL;
	void* t1 = NULL;
	vader_box_t* gc_roots[1] = { &l7 };
	void** gc_raw_roots[7] = { &l0, &l1, &l5, &l6, &l8, &t0, &t1 };
	vader_string_t* gc_atom_roots[3] = { &l2, &l3, &l4 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_toolchain_stage$SourceSpec_t*) ((vader_struct_vader_front_resolver$ReplayedStage_t*) l0)->f_spec)->f_name;
	l3 = ((vader_struct_vader_front_resolver$ReplayedStage_t*) l0)->f_project_root;
	l4 = ((vader_struct_toolchain_stage$Sources_t*) l1)->f_module_name;
	l3 = vader_front_resolver$stage_record_path(l3, l2, l4);
	l4 = ((vader_struct_toolchain_stage$Sources_t*) l1)->f_module_name;
	l4 = concat_5(1307u, l2, 1412u, l4, 1307u);
	vader_array_t* _a0_arr = vader_array_new(104u, 0u, 13u, 1289u);
	l5 = (void*) _a0_arr;
	t0 = vader_front_resolver$replay_warning(l1, l4);
	vader_array_t* _a1_arr = vader_array_new(93u, 1u, 13u, 1245u);
	((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = t0;
	l6 = (void*) _a1_arr;
	vader_struct_toolchain_stage$Generated_t* _a2_obj = (vader_struct_toolchain_stage$Generated_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_stage$Generated_t));
	vader_obj_header_init(_a2_obj, 1295u);
	_a2_obj->f_text = 0u;
	_a2_obj->f_anchors = l5;
	_a2_obj->f_diagnostics = l6;
	l5 = (void*) _a2_obj;
	l7 = vader_front_resolver$read_recorded(l3);
	if (l7.tag == 0u) {
		{ void* __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l6 = l7.payload.obj;
	l7 = ((vader_struct_vader_front_resolver$Recorded_t*) l6)->f_answer;
	if (!(l7.tag == 1279u)) {
		{ void* __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l5 = vader_front_resolver$source_files(l1);
	l3 = ((vader_struct_vader_front_resolver$ReplayedStage_t*) l0)->f_project_root;
	l5 = vader_front_resolver$driver_names(l5, vader_box_string(642u, l3));
	t0 = l7.payload.obj;
	t1 = vader_front_resolver$reports_read(((vader_struct_toolchain_protocol$GeneratedFrame_t*) t0)->f_reports, l5);
	l8 = vader_front_resolver$replayed_diagnostics(t1);
	l3 = ((vader_struct_vader_front_resolver$Recorded_t*) l6)->f_key;
	l6 = vader_front_resolver$driver_sources(l1);
	l4 = vader_front_resolver$record_key(l2, l6, l5);
	if (l3 != l4) {
		l3 = ((vader_struct_toolchain_stage$Sources_t*) l1)->f_module_name;
		l2 = concat_5(1307u, l2, 1572u, l3, 1307u);
		l6 = vader_front_resolver$replay_warning(l1, l2);
		vader_array_push_ref((vader_array_t*) l8, l6);
	}
	t0 = l7.payload.obj;
	l2 = ((vader_struct_toolchain_protocol$GeneratedFrame_t*) t0)->f_text;
	t0 = l7.payload.obj;
	l5 = vader_front_resolver$anchors_read(((vader_struct_toolchain_protocol$GeneratedFrame_t*) t0)->f_anchors, l5);
	vader_struct_toolchain_stage$Generated_t* _a3_obj = (vader_struct_toolchain_stage$Generated_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_stage$Generated_t));
	vader_obj_header_init(_a3_obj, 1295u);
	_a3_obj->f_text = l2;
	_a3_obj->f_anchors = l5;
	_a3_obj->f_diagnostics = l8;
	t0 = (void*) _a3_obj;
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_front_resolver$TestsStage$toolchain_stage$Stage$describe(void* l0) {
	void* l1 = NULL;
	void* l2 = NULL;
	void* t0 = NULL;
	void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	vader_struct_toolchain_stage$DecoratedWith_t* _a0_obj = (vader_struct_toolchain_stage$DecoratedWith_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_stage$DecoratedWith_t));
	vader_obj_header_init(_a0_obj, 1293u);
	_a0_obj->f_marker = (uint8_t) 23;
	t0 = (void*) _a0_obj;
	vader_array_t* _a1_arr = vader_array_new(490u, 1u, 13u, 2546u);
	((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = t0;
	l1 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(490u, 0u, 13u, 2546u);
	l2 = (void*) _a2_arr;
	vader_struct_toolchain_stage$SourceSpec_t* _a3_obj = (vader_struct_toolchain_stage$SourceSpec_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_stage$SourceSpec_t));
	vader_obj_header_init(_a3_obj, 1301u);
	_a3_obj->f_name = 3321u;
	_a3_obj->f_given = l1;
	_a3_obj->f_generates = l2;
	t0 = (void*) _a3_obj;
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_front_resolver$TestsStage$toolchain_stage$Stage$run(void* l0, void* l1) {
	void* l2 = NULL;
	void* l3 = NULL;
	void* l7 = NULL;
	void* l11 = NULL;
	int64_t l4, l5, l6, l8, l10, l12;
	vader_string_t l9 = 0;
	vader_string_t l13 = 0;
	void* t0 = NULL;
	void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l7, &l11, &t0 };
	vader_string_t* gc_atom_roots[2] = { &l9, &l13 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 7u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
	t0 = (void*) _a0_arr;
	vader_struct_std_string__builder$StringBuilder_t* _a1_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
	vader_obj_header_init(_a1_obj, 1139u);
	_a1_obj->f_parts = t0;
	l2 = (void*) _a1_obj;
	std_string__builder$append(l2, 3322u);
	std_string__builder$append(l2, 36u);
	l3 = vader_front_resolver$tests_declared(((vader_struct_toolchain_stage$Sources_t*) l1)->f_files);
	l4 = INT64_C(0);
	l5 = vader_array_length(((vader_array_t*) l3));
	l6 = INT64_C(0);
	while ((l6 < l5)) {
		vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
		l7 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l6);
		l8 = l4;
		l9 = ((vader_struct_vader_front_resolver$DeclaredTest_t*) l7)->f_name;
		l10 = (int64_t) vader_string_byte_len(l9);
		l11 = (void*) vader_buffer_new((size_t) (INT64_C(35) + l10));
		l12 = INT64_C(0);
		l12 = std_core$write_string_at(l11, l12, 22u);
		l12 = std_core$write_int(l11, l12, l8);
		l12 = std_core$write_string_at(l11, l12, 78u);
		l12 = std_core$write_string_at(l11, l12, l9);
		l12 = std_core$write_string_at(l11, l12, 383u);
		l13 = std_core$finish_buffer(l11, l12);
		std_string__builder$append(l2, l13);
		l4 = vader_chk_add(i64, l4, INT64_C(1));
		l6 = (l6 + INT64_C(1));
	}
	std_string__builder$append(l2, 28u);
	l9 = std_string__builder$StringBuilder$std_core$Display$to_string(l2);
	vader_array_t* _a3_arr = vader_array_new(104u, 0u, 13u, 1289u);
	l2 = (void*) _a3_arr;
	vader_array_t* _a4_arr = vader_array_new(93u, 0u, 13u, 1245u);
	l3 = (void*) _a4_arr;
	vader_struct_toolchain_stage$Generated_t* _a5_obj = (vader_struct_toolchain_stage$Generated_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_stage$Generated_t));
	vader_obj_header_init(_a5_obj, 1295u);
	_a5_obj->f_text = l9;
	_a5_obj->f_anchors = l2;
	_a5_obj->f_diagnostics = l3;
	t0 = (void*) _a5_obj;
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_front_resolver$WitStage$toolchain_stage$Stage$describe(void* l0) {
	void* t0 = NULL;
	void** gc_raw_roots[2] = { &l0, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	vader_struct_toolchain_stage$ModuleSpec_t* _a0_obj = (vader_struct_toolchain_stage$ModuleSpec_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_stage$ModuleSpec_t));
	vader_obj_header_init(_a0_obj, 1299u);
	_a0_obj->f_name = 3755u;
	_a0_obj->f_form = (uint8_t) 0;
	t0 = (void*) _a0_obj;
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_front_resolver$WitStage$toolchain_stage$Stage$run(void* l0, void* l1) {
	void* l2 = NULL;
	void* l3 = NULL;
	void* l4 = NULL;
	vader_string_t l5 = 0;
	vader_box_t l6 = vader_box_null(), l7 = vader_box_null();
	bool l8;
	vader_string_t t0 = 0;
	int64_t t1;
	void* t2 = NULL;
	vader_box_t* gc_roots[2] = { &l6, &l7 };
	void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l4, &t2 };
	vader_string_t* gc_atom_roots[2] = { &l5, &t0 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	t0 = ((vader_struct_toolchain_stage$ModuleRequest_t*) l1)->f_name;
	l2 = vader_front_resolver$interface_name_of(t0);
	l3 = ((vader_struct_vader_front_resolver$InterfaceName_t*) l2)->f_package;
	l3 = vader_front_resolver$package_folders(l1, l3);
	t1 = vader_array_length(((vader_array_t*) l3));
	if (t1 == INT64_C(0)) {
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
	VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
	VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
	l4 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT32_C(0));
	t1 = vader_array_length(((vader_array_t*) l3));
	if ((t1 > INT64_C(1))) {
		t0 = ((vader_struct_toolchain_stage$ModuleRequest_t*) l1)->f_name;
		l3 = vader_front_resolver$two_folders(t0, l3);
		t2 = vader_front_resolver$failed(l4, l3);
		{ vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l5 = ((vader_struct_vader_front_resolver$InterfaceName_t*) l2)->f_interface;
	l6 = vader_front_resolver$module_text(l0, l1, l4, l5);
	l7 = l6;
	if (l6.tag == 1533u) {
		t2 = l7.payload.obj;
		l2 = vader_front_resolver$wit_diagnostic(t2);
		t2 = vader_front_resolver$failed(l4, l2);
		{ vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (l6.tag == 0u) {
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	l5 = l6.payload.s;
	l8 = ((vader_struct_vader_front_resolver$PackageFolder_t*) l4)->f_of_toolchain;
	vader_array_t* _a1_arr = vader_array_new(93u, 0u, 13u, 1245u);
	l2 = (void*) _a1_arr;
	vader_struct_toolchain_stage$ModuleSource_t* _a2_obj = (vader_struct_toolchain_stage$ModuleSource_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_stage$ModuleSource_t));
	vader_obj_header_init(_a2_obj, 1298u);
	_a2_obj->f_text = l5;
	_a2_obj->f_of_toolchain = l8;
	_a2_obj->f_diagnostics = l2;
	t2 = (void*) _a2_obj;
	{ vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_front_resolver$absolute_path(vader_string_t l0) {
	vader_string_t l1 = 0;
	vader_string_t l2 = 0;
	vader_string_t t0 = 0;
	vader_string_t* gc_atom_roots[4] = { &l0, &l1, &l2, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 4u, gc_atom_roots };
	vader_gc_top = &gc_frame;
	t0 = std_env$current_working_directory();
	l1 = std_path$to_path(t0);
	l2 = std_string$trim_prefix(l0, 497u);
	t0 = std_path$join(l1, l2);
	{ vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

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
	if (t0 == 2871u) {
		l6 = (uint8_t) 0;
	}
	l7 = ((vader_struct_vader_front_resolver$CollectedModule_t*) l0)->f_symbols;
	l8 = ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_name;
	l9 = std_collections$Map$std_core$Index$at__string__Any(l7, l8);
	if (l9.tag == 1491u) {
		t1 = l9.payload.obj;
		if (((vader_struct_vader_core_symbol$Symbol_t*) t1)->f_kind != INT32_C(0)) {
			l7 = ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_name_span;
			l8 = ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_name;
			l8 = concat_3(1307u, l8, 1332u);
			l7 = toolchain_diagnostics$resolver_error((uint8_t) 3, l7, l8);
			vader_array_push_ref((vader_array_t*) l5, l7);
			{ vader_gc_top = gc_frame.prev; return; }
		}
	}
	l8 = ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_name;
	l7 = ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_name_span;
	l7 = vader_core_symbol$make(l4, (uint8_t) 0, l8, l2, l3, l6, vader_ref_box(l7));
	l10 = ((vader_struct_vader_front_resolver$CollectedModule_t*) l0)->f_fn_overloads;
	l8 = ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_name;
	l11 = (void*) &vader_fn_static___lambda_vader_front_resolver_30;
	t1 = std_collections$get_or_put_with__string__vader_core_symbol_Symbol__(l10, l8, l11);
	vader_array_push_ref((vader_array_t*) t1, l7);
	if (l9.tag == 0u) {
		l10 = ((vader_struct_vader_front_resolver$CollectedModule_t*) l0)->f_symbols;
		l8 = ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_name;
		std_collections$Map$std_core$IndexSet$set_at__string__Any(l10, l8, vader_ref_box(l7));
		{ vader_gc_top = gc_frame.prev; return; }
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$add_leading_names(vader_box_t l0, vader_string_t l1, void* l2) {
	vader_string_t l3 = 0;
	vader_box_t l4 = vader_box_null();
	void* l5 = NULL;
	int64_t l6, l7;
	void* t0 = NULL;
	vader_box_t* gc_roots[2] = { &l0, &l4 };
	void** gc_raw_roots[3] = { &l2, &l5, &t0 };
	vader_string_t* gc_atom_roots[2] = { &l1, &l3 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	if (l0.tag == 1190u) {
		t0 = l0.payload.obj;
		l3 = toolchain_ast$impl_trait_name(t0);
		std_collections$add__string(l2, l3);
		{ vader_gc_top = gc_frame.prev; return; }
	}
	l4 = vader_front_resolver$declared_name(l0);
	if (l4.tag == 0u) {
		{ vader_gc_top = gc_frame.prev; return; }
	}
	l3 = l4.payload.s;
	std_collections$add__string(l2, l3);
	if (l1 != 0u) {
		l3 = vader_front_reach$qualified_name(l1, l3);
		std_collections$add__string(l2, l3);
	}
	if (l0.tag == 1232u) {
		t0 = l0.payload.obj;
		l5 = ((vader_struct_toolchain_ast$TraitDecl_t*) t0)->f_members;
		l6 = vader_array_length(((vader_array_t*) l5));
		l7 = INT64_C(0);
		while ((l7 < l6)) {
			vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
			VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
			t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l7);
			l3 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_name;
			std_collections$add__string(l2, l3);
			l7 = (l7 + INT64_C(1));
		}
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_front_resolver$add_named(void* l0, uint8_t l1, vader_string_t l2, void* l3, uint8_t l4, vader_string_t l5, vader_string_t l6, void* l7, void* l8) {
	vader_string_t l9 = 0;
	void* l10 = NULL;
	bool t0;
	void** gc_raw_roots[5] = { &l0, &l3, &l7, &l8, &l10 };
	vader_string_t* gc_atom_roots[4] = { &l2, &l5, &l6, &l9 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	t0 = std_collections$Map$std_core$Contains$contains__string__Any(((vader_struct_vader_front_resolver$CollectedModule_t*) l0)->f_symbols, l2);
	if (!(t0)) {
		l10 = vader_core_symbol$make(l7, l1, l2, l5, l6, l4, vader_ref_box(l3));
		std_collections$Map$std_core$IndexSet$set_at__string__Any(((vader_struct_vader_front_resolver$CollectedModule_t*) l0)->f_symbols, l2, vader_ref_box(l10));
		{ vader_box_t __vret = vader_ref_box(l10); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l9 = concat_3(1307u, l2, 1332u);
	l10 = toolchain_diagnostics$resolver_error((uint8_t) 3, l3, l9);
	vader_array_push_ref((vader_array_t*) l8, l10);
	{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static void* vader_front_resolver$aliases_in(void* l0, vader_string_t l1) {
	vader_box_t l2 = vader_box_null();
	void* l3 = NULL;
	void* l4 = NULL;
	void* l5 = NULL;
	void* t0 = NULL;
	vader_box_t* gc_roots[1] = { &l2 };
	void** gc_raw_roots[5] = { &l0, &l3, &l4, &l5, &t0 };
	vader_string_t* gc_atom_roots[1] = { &l1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = std_collections$Map$std_core$Index$at__string__std_collections_Map_string__string_(l0, l1);
	if (l2.tag == 0u) {
		vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
		l3 = (void*) _a0_arr;
		vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 642u);
		l4 = (void*) _a1_arr;
		vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 645u);
		l5 = (void*) _a2_arr;
		vader_struct_std_collections$Map__string__string_t* _a3_obj = (vader_struct_std_collections$Map__string__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__string_t));
		vader_obj_header_init(_a3_obj, 1028u);
		_a3_obj->f_ekeys = l3;
		_a3_obj->f_evals = l4;
		_a3_obj->f_index = l5;
		_a3_obj->f_mask = INT64_C(0);
		_a3_obj->f_grow_at = INT64_C(0);
		_a3_obj->f_size = INT64_C(0);
		_a3_obj->f_tombs = INT64_C(0);
		t0 = (void*) _a3_obj;
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	t0 = l2.payload.obj;
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$aliases_read_by(vader_box_t l0, void* l1, void* l2) {
	vader_box_t l3 = vader_box_null();
	vader_string_t l4 = 0;
	void* t0 = NULL;
	vader_box_t* gc_roots[2] = { &l0, &l3 };
	void** gc_raw_roots[3] = { &l1, &l2, &t0 };
	vader_string_t* gc_atom_roots[1] = { &l4 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	if (l0.tag == 1181u) {
		t0 = l0.payload.obj;
		l3 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_body;
		if (!(l3.tag == 0u)) {
			t0 = l3.payload.obj;
			l4 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) ((vader_struct_toolchain_ast$BlockExpr_t*) t0)->f_span)->f_start)->f_file;
			t0 = vader_front_resolver$aliases_in(l2, l4);
			{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
		}
		l4 = vader_front_resolver$file_of(l1);
		t0 = vader_front_resolver$aliases_in(l2, l4);
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l4 = vader_front_resolver$file_of(l1);
	t0 = vader_front_resolver$aliases_in(l2, l4);
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$anchor_impls(void* l0, void* l1, vader_string_t l2) {
	void* l3 = NULL;
	void* l6 = NULL;
	void* l10 = NULL;
	void* l14 = NULL;
	void* l15 = NULL;
	void* l16 = NULL;
	vader_string_t l4 = 0;
	int64_t l5, l7, l8, l11, l12, l13;
	vader_box_t l9 = vader_box_null();
	void* t0 = NULL;
	vader_box_t* gc_roots[1] = { &l9 };
	void** gc_raw_roots[9] = { &l0, &l1, &l3, &l6, &l10, &l14, &l15, &l16, &t0 };
	vader_string_t* gc_atom_roots[2] = { &l2, &l4 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(333u, 0u, 13u, 1772u);
	l3 = (void*) _a0_arr;
	l4 = concat_3(3335u, l2, 1629u);
	l5 = INT64_C(0);
	l6 = ((vader_struct_toolchain_ast$Program_t*) l0)->f_decls;
	l7 = vader_array_length(((vader_array_t*) l6));
	l8 = INT64_C(0);
	while ((l8 < l7)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		l9 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l8);
		if (l9.tag == 1190u) {
			l10 = l9.payload.obj;
			l11 = vader_array_length(((vader_array_t*) l1));
			if ((l5 >= l11)) break;
			l12 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) ((vader_struct_toolchain_ast$ImplDecl_t*) l10)->f_span)->f_start)->f_offset;
			l13 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) ((vader_struct_toolchain_ast$ImplDecl_t*) l10)->f_span)->f_end)->f_offset;
			vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
			VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
			t0 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l5);
			vader_struct_toolchain_diagnostics$Related_t* _a3_obj = (vader_struct_toolchain_diagnostics$Related_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_diagnostics$Related_t));
			vader_obj_header_init(_a3_obj, 1246u);
			_a3_obj->f_span = t0;
			_a3_obj->f_message = l4;
			l14 = (void*) _a3_obj;
			vader_struct_vader_front_resolver$CodeOrigin_t* _a4_obj = (vader_struct_vader_front_resolver$CodeOrigin_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$CodeOrigin_t));
			vader_obj_header_init(_a4_obj, 1772u);
			_a4_obj->f_start = l12;
			_a4_obj->f_end = l13;
			_a4_obj->f_origin = l14;
			l15 = (void*) _a4_obj;
			vader_array_push_ref((vader_array_t*) l3, l15);
			vader_array_t* _a5_slotarr = ((vader_array_t*) l1);
			VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
			l16 = vader_array_ref_load_obj(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) l5);
			((vader_struct_toolchain_ast$ImplDecl_t*) l10)->f_span = l16;
			VADER_WRITE_BARRIER((vader_struct_toolchain_ast$ImplDecl_t*) l10);
			l5 = vader_chk_add(i64, l5, INT64_C(1));
		}
		l8 = (l8 + INT64_C(1));
	}
	{ void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$anchors_read(void* l0, void* l1) {
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
	vader_struct___lambda_env_vader_front_resolver_40_t* _a0_obj = (vader_struct___lambda_env_vader_front_resolver_40_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_front_resolver_40_t));
	vader_obj_header_init(_a0_obj, 812u);
	_a0_obj->f_cap_0 = l1;
	l3 = (void*) _a0_obj;
	t0 = vader_array_length(((vader_array_t*) l2));
	vader_array_t* _a1_arr = vader_array_reserve(104u, (int64_t) t0, 13u, 1289u);
	l4 = (void*) _a1_arr;
	l5 = vader_array_length(((vader_array_t*) l2));
	l6 = INT64_C(0);
	while ((l6 < l5)) {
		vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
		l7 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l6);
		l8 = __lambda_vader_front_resolver_39(l3, l7);
		vader_array_push_ref((vader_array_t*) l4, l8);
		l6 = (l6 + INT64_C(1));
	}
	{ void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_front_resolver$any_has_body(void* l0) {
	void* l1;
	int64_t l2, l3;
	vader_box_t l4;
	void* t0;
	l1 = l0;
	l2 = vader_array_length(((vader_array_t*) l1));
	l3 = INT64_C(0);
	while ((l3 < l2)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l3);
		l4 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_body;
		if (l4.tag == 1150u) {
			return true;
		}
		if (!(l4.tag == 0u)) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		l3 = (l3 + INT64_C(1));
	}
	return false;
}

static vader_string_t vader_front_resolver$arguments_type(vader_string_t l0, void* l1) {
	void* l2 = NULL;
	void* l3 = NULL;
	int64_t l4, l5;
	vader_box_t l6 = vader_box_null();
	vader_string_t l7 = 0;
	void* t0 = NULL;
	vader_string_t t1 = 0;
	vader_box_t* gc_roots[1] = { &l6 };
	void** gc_raw_roots[4] = { &l1, &l2, &l3, &t0 };
	vader_string_t* gc_atom_roots[3] = { &l0, &l7, &t1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
	l2 = (void*) _a0_arr;
	l3 = ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_params;
	l4 = vader_array_length(((vader_array_t*) l3));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		t0 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l5);
		l6 = ((vader_struct_toolchain_ast$FnParam_t*) t0)->f_ty;
		if (l6.tag == 0u) {
			l5 = (l5 + INT64_C(1));
			continue;
		}
		l7 = toolchain_span$text_in(VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l6.payload.obj), l0);
		vader_array_push_scalar((vader_array_t*) l2, vader_box_string(642u, l7));
		l5 = (l5 + INT64_C(1));
	}
	t1 = vader_front_resolver$tupled(l2);
	{ vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_resolver$around_of(void* l0, void* l1, void* l2, void* l3) {
	vader_box_t l4 = vader_box_null(), l7 = vader_box_null();
	void* l5 = NULL;
	void* l8 = NULL;
	vader_string_t l6 = 0;
	vader_string_t l9 = 0;
	void* t0 = NULL;
	vader_box_t* gc_roots[2] = { &l4, &l7 };
	void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l5, &l8, &t0 };
	vader_string_t* gc_atom_roots[2] = { &l6, &l9 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l4 = toolchain_ast$argument_named(l2, 2011u, INT64_C(0));
	if (l4.tag == 0u) {
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	if (!(l4.tag == 1186u)) {
		l5 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l4.payload.obj);
		l5 = toolchain_diagnostics$resolver_error((uint8_t) 35, l5, 3774u);
		vader_array_push_ref((vader_array_t*) l3, l5);
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	t0 = l4.payload.obj;
	l6 = ((vader_struct_toolchain_ast$IdentExpr_t*) t0)->f_name;
	l7 = vader_front_resolver$function_named(l0, l6);
	if (l7.tag == 0u) {
		t0 = l4.payload.obj;
		l8 = ((vader_struct_toolchain_ast$IdentExpr_t*) t0)->f_span;
		t0 = l4.payload.obj;
		l6 = ((vader_struct_toolchain_ast$IdentExpr_t*) t0)->f_name;
		l6 = concat_3(1307u, l6, 1485u);
		l8 = toolchain_diagnostics$resolver_error((uint8_t) 35, l8, l6);
		vader_array_push_ref((vader_array_t*) l3, l8);
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	l5 = l7.payload.obj;
	l9 = ((vader_struct_toolchain_ast$StructDecl_t*) l1)->f_name;
	l4 = vader_front_resolver$state_struct(l5, l9, l3);
	if (l4.tag == 0u) {
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	l6 = l4.payload.s;
	vader_struct_vader_front_resolver$AroundFunction_t* _a0_obj = (vader_struct_vader_front_resolver$AroundFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$AroundFunction_t));
	vader_obj_header_init(_a0_obj, 1771u);
	_a0_obj->f_function = l5;
	_a0_obj->f_state = l6;
	t0 = (void*) _a0_obj;
	{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_front_resolver$auto_bind_for_type_params(void* l0, vader_box_t l1) {
	void* l2 = NULL;
	void* l6 = NULL;
	void* l7 = NULL;
	void* l10 = NULL;
	void* l11 = NULL;
	void* l12 = NULL;
	int64_t l3, l4;
	vader_box_t l5 = vader_box_null();
	vader_string_t l8 = 0;
	vader_string_t l9 = 0;
	vader_string_t l13 = 0;
	void* t0 = NULL;
	vader_box_t t1 = vader_box_null();
	vader_box_t* gc_roots[3] = { &l1, &l5, &t1 };
	void** gc_raw_roots[8] = { &l0, &l2, &l6, &l7, &l10, &l11, &l12, &t0 };
	vader_string_t* gc_atom_roots[3] = { &l8, &l9, &l13 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 3u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	if (!(l1.tag == 1185u)) {
		{ vader_gc_top = gc_frame.prev; return; }
	}
	t0 = l1.payload.obj;
	l2 = ((vader_struct_toolchain_ast$GenericInstExpr_t*) t0)->f_type_args;
	l3 = vader_array_length(((vader_array_t*) l2));
	l4 = INT64_C(0);
	while ((l4 < l3)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		l5 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l4);
		if (l5.tag == 1186u) {
			l6 = l5.payload.obj;
			l7 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope;
			l8 = ((vader_struct_toolchain_ast$IdentExpr_t*) l6)->f_name;
			t1 = vader_front_resolver$lookup(l7, l8);
			if (t1.tag == 0u) {
				l9 = ((vader_struct_toolchain_ast$IdentExpr_t*) l6)->f_name;
				l10 = ((vader_struct_toolchain_ast$IdentExpr_t*) l6)->f_span;
				l11 = vader_front_resolver$mint_local(l0, (uint8_t) 9, l9, l10);
				l12 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope;
				l13 = ((vader_struct_toolchain_ast$IdentExpr_t*) l6)->f_name;
				vader_front_resolver$bind(l12, l13, l11);
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
	if (l0.tag == 2152u) {
		l1 = l0.payload.obj;
		{ void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (l0.tag == 2150u) {
		l1 = vader_support_target$host_target();
	} else {
		if (!(l0.tag == 2151u)) {
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
	l3 = vader_array_length(((vader_array_t*) ((vader_struct_vader_front_resolver$Scope_t*) l0)->f_frames));
	if (!(l3 == INT64_C(0))) {
		l4 = ((vader_struct_vader_front_resolver$Scope_t*) l0)->f_frames;
		l3 = vader_chk_sub(i64, l3, INT64_C(1));
		vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
		t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l3);
		std_collections$Map$std_core$IndexSet$set_at__string__Any(t0, l1, vader_ref_box(l2));
		{ vader_gc_top = gc_frame.prev; return; }
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$bind_1(void* l0, vader_string_t l1, vader_box_t l2) {
	std_collections$Map$std_core$IndexSet$set_at__string__Any(((vader_struct_vader_front_resolver$Subst_t*) l0)->f_entries, l1, l2);
	return;
}

static void vader_front_resolver$bind_declared(void* l0, vader_string_t l1, void* l2) {
	void* l3 = NULL;
	uint64_t l4;
	vader_box_t l5 = vader_box_null();
	vader_string_t t0 = 0;
	vader_box_t* gc_roots[1] = { &l5 };
	void** gc_raw_roots[3] = { &l0, &l2, &l3 };
	vader_string_t* gc_atom_roots[2] = { &l1, &t0 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l3 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_idents;
	l4 = toolchain_span$Span$std_core$Hash$hash(l2);
	l5 = std_collections$Map$std_core$Index$at__u64__Any(l3, l4);
	if (l5.tag == 0u) {
		t0 = concat_3(3124u, l1, 1620u);
		vader_host_std_core$Runtime$panic(t0);
		vader_unreachable("a no-return call returned");
	} else {
		l3 = l5.payload.obj;
		vader_front_resolver$bind(((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope, l1, l3);
		{ vader_gc_top = gc_frame.prev; return; }
	}
	vader_gc_top = gc_frame.prev;
}

static void vader_front_resolver$bind_header_name(void* l0, vader_box_t l1, uint8_t l2) {
	void* l3 = NULL;
	void* l6 = NULL;
	void* l7 = NULL;
	vader_box_t l4 = vader_box_null();
	vader_string_t l5 = 0;
	uint64_t l8;
	int32_t l9;
	vader_box_t* gc_roots[2] = { &l1, &l4 };
	void** gc_raw_roots[4] = { &l0, &l3, &l6, &l7 };
	vader_string_t* gc_atom_roots[1] = { &l5 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l4 = l1;
	if (l4.tag == 0u) {
		{ vader_gc_top = gc_frame.prev; return; }
	}
	l3 = l4.payload.obj;
	l5 = ((vader_struct_toolchain_ast$SimpleBinding_t*) l3)->f_name;
	l6 = ((vader_struct_toolchain_ast$SimpleBinding_t*) l3)->f_name_span;
	l6 = vader_front_resolver$bind_local(l0, (uint8_t) 10, l5, l6);
	l7 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_idents;
	l8 = toolchain_span$Span$std_core$Hash$hash(((vader_struct_toolchain_ast$SimpleBinding_t*) l3)->f_name_span);
	std_collections$Map$std_core$IndexSet$set_at__u64__Any(l7, l8, vader_ref_box(l6));
	l3 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_immutable_locals;
	l9 = ((vader_struct_vader_core_symbol$Symbol_t*) l6)->f_id;
	std_collections$Map$std_core$IndexSet$set_at__i32__vader_front_resolver_ConstLocal(l3, l9, l2);
	{ vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$bind_impl_params(void* l0, void* l1) {
	void* l2 = NULL;
	void* l5 = NULL;
	void* l7 = NULL;
	void* l9 = NULL;
	void* l12 = NULL;
	int64_t l3, l4;
	vader_string_t l6 = 0;
	vader_box_t l8 = vader_box_null(), l11 = vader_box_null();
	uint64_t l10;
	void* t0 = NULL;
	vader_box_t* gc_roots[2] = { &l8, &l11 };
	void** gc_raw_roots[8] = { &l0, &l1, &l2, &l5, &l7, &l9, &l12, &t0 };
	vader_string_t* gc_atom_roots[1] = { &l6 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_toolchain_ast$ImplDecl_t*) l1)->f_type_params;
	l3 = vader_array_length(((vader_array_t*) l2));
	l4 = INT64_C(0);
	while ((l4 < l3)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		l5 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l4);
		l6 = ((vader_struct_toolchain_ast$TypeParam_t*) l5)->f_name;
		l7 = ((vader_struct_toolchain_ast$TypeParam_t*) l5)->f_span;
		vader_front_resolver$bind_declared(l0, l6, l7);
		l4 = (l4 + INT64_C(1));
	}
	l8 = ((vader_struct_toolchain_ast$ImplDecl_t*) l1)->f_for_type;
	if (!(l8.tag == 1185u)) {
		{ vader_gc_top = gc_frame.prev; return; }
	}
	t0 = l8.payload.obj;
	l2 = ((vader_struct_toolchain_ast$GenericInstExpr_t*) t0)->f_type_args;
	l3 = vader_array_length(((vader_array_t*) l2));
	l4 = INT64_C(0);
	while ((l4 < l3)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		l8 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l4);
		if (l8.tag == 1186u) {
			l5 = l8.payload.obj;
			l9 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_idents;
			l10 = toolchain_span$Span$std_core$Hash$hash(((vader_struct_toolchain_ast$IdentExpr_t*) l5)->f_span);
			l11 = std_collections$Map$std_core$Index$at__u64__Any(l9, l10);
			if (l11.tag == 0u) {
				l4 = (l4 + INT64_C(1));
				continue;
			}
			l7 = l11.payload.obj;
			if (((vader_struct_vader_core_symbol$Symbol_t*) l7)->f_kind == INT32_C(9)) {
				l12 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope;
				l6 = ((vader_struct_toolchain_ast$IdentExpr_t*) l5)->f_name;
				vader_front_resolver$bind(l12, l6, l7);
			}
		}
		l4 = (l4 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return; }
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
	t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT32_C(0));
	l8 = std_collections$Map$std_core$Index$at__string__Any(((vader_struct_vader_front_resolver$FileImports_t*) t0)->f_bindings, l1);
	if (l8.tag == 0u) {
		l9 = vader_core_symbol$make(l6, (uint8_t) 7, l1, l5, l5, (uint8_t) 1, vader_ref_box(l2));
		vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_front_resolver$CollectedModule_t*) l0)->f_files);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
		t0 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) INT32_C(0));
		std_collections$Map$std_core$IndexSet$set_at__string__Any(((vader_struct_vader_front_resolver$FileImports_t*) t0)->f_bindings, l1, vader_ref_box(l9));
		l13 = ((vader_struct_vader_front_resolver$CollectedModule_t*) l0)->f_imports;
		l10 = ((vader_struct_vader_core_symbol$Symbol_t*) l9)->f_id;
		vader_struct_vader_front_resolver$ImportInfo_t* _a2_obj = (vader_struct_vader_front_resolver$ImportInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$ImportInfo_t));
		vader_obj_header_init(_a2_obj, 1786u);
		_a2_obj->f_path = l3;
		_a2_obj->f_imported_name = l4;
		_a2_obj->f_local = l1;
		_a2_obj->f_binding_span = l2;
		l14 = (void*) _a2_obj;
		std_collections$Map$std_core$IndexSet$set_at__i32__Any(l13, l10, vader_ref_box(l14));
		{ vader_gc_top = gc_frame.prev; return; }
	}
	l9 = ((vader_struct_vader_front_resolver$CollectedModule_t*) l0)->f_imports;
	t0 = l8.payload.obj;
	l10 = ((vader_struct_vader_core_symbol$Symbol_t*) t0)->f_id;
	l8 = std_collections$Map$std_core$Index$at__i32__Any(l9, l10);
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
		l12 = concat_3(1307u, l1, 1307u);
		l9 = toolchain_diagnostics$resolver_error((uint8_t) 10, l2, l12);
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
	if (l1.tag == 1220u) {
		t0 = l1.payload.obj;
		l3 = ((vader_struct_toolchain_ast$SimpleBinding_t*) t0)->f_name;
		t0 = l1.payload.obj;
		l4 = ((vader_struct_toolchain_ast$SimpleBinding_t*) t0)->f_name_span;
		l4 = vader_front_resolver$bind_local_checked(l0, (uint8_t) 10, l3, l4);
		l5 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_idents;
		t0 = l1.payload.obj;
		l6 = toolchain_span$Span$std_core$Hash$hash(((vader_struct_toolchain_ast$SimpleBinding_t*) t0)->f_name_span);
		std_collections$Map$std_core$IndexSet$set_at__u64__Any(l5, l6, vader_ref_box(l4));
		vader_array_push_ref((vader_array_t*) l2, l4);
		{ vader_gc_top = gc_frame.prev; return; }
	}
	if (l1.tag == 1233u) {
		t0 = l1.payload.obj;
		l4 = ((vader_struct_toolchain_ast$TupleBinding_t*) t0)->f_elements;
		l7 = vader_array_length(((vader_array_t*) l4));
		l8 = INT64_C(0);
		while ((l8 < l7)) {
			vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
			VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
			l9 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l8);
			vader_front_resolver$bind_let_binding(l0, l9, l2);
			l8 = (l8 + INT64_C(1));
		}
	} else if (!(l1.tag == 1238u)) {
		if (!(l1.tag == 1216u)) {
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
		std_collections$Map$std_core$IndexSet$set_at__u64__Any(l5, l6, vader_ref_box(l4));
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
	std_collections$Map$std_core$IndexSet$set_at__u64__Any(l3, l4, vader_ref_box(l5));
	{ vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$bind_pattern(void* l0, vader_box_t l1) {
	bool l2;
	vader_box_t l3 = vader_box_null(), l8 = vader_box_null(), l14 = vader_box_null();
	void* l4 = NULL;
	void* l7 = NULL;
	void* l10 = NULL;
	void* l11 = NULL;
	void* l12 = NULL;
	int64_t l5, l6;
	vader_string_t l9 = 0;
	uint64_t l13;
	void* t0 = NULL;
	vader_box_t* gc_roots[4] = { &l1, &l3, &l8, &l14 };
	void** gc_raw_roots[7] = { &l0, &l4, &l7, &l10, &l11, &l12, &t0 };
	vader_string_t* gc_atom_roots[1] = { &l9 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 4u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	if (l1.tag == 1199u) {
		t0 = l1.payload.obj;
		if (((vader_struct_toolchain_ast$IsPattern_t*) t0)->f_ty.tag == 1186u) {
			t0 = l1.payload.obj;
			l2 = ((vader_struct_toolchain_ast$IdentExpr_t*) ((vader_struct_toolchain_ast$IsPattern_t*) t0)->f_ty.payload.obj)->f_implicit_dot;
		} else {
			l2 = false;
		}
		if (!(l2)) {
			t0 = l1.payload.obj;
			l3 = ((vader_struct_toolchain_ast$IsPattern_t*) t0)->f_ty;
			vader_front_resolver$walk_expr(l0, l3);
		}
		t0 = l1.payload.obj;
		if (!(((vader_struct_toolchain_ast$IsPattern_t*) t0)->f_inner.tag == 0u)) {
			t0 = l1.payload.obj;
			l3 = ((vader_struct_toolchain_ast$IsPattern_t*) t0)->f_inner;
			vader_front_resolver$bind_pattern(l0, l3);
		}
		{ vader_gc_top = gc_frame.prev; return; }
	}
	if (l1.tag == 1229u) {
		t0 = l1.payload.obj;
		l4 = ((vader_struct_toolchain_ast$StructPattern_t*) t0)->f_fields;
		l5 = vader_array_length(((vader_array_t*) l4));
		l6 = INT64_C(0);
		while ((l6 < l5)) {
			vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
			VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
			VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
			l7 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l6);
			l3 = ((vader_struct_toolchain_ast$StructPatternField_t*) l7)->f_value;
			l8 = l3;
			if (l3.tag == 1210u) {
				l9 = ((vader_struct_toolchain_ast$StructPatternField_t*) l7)->f_name;
				l10 = ((vader_struct_toolchain_ast$StructPatternField_t*) l7)->f_name_span;
				l11 = vader_front_resolver$bind_local(l0, (uint8_t) 11, l9, l10);
				l12 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_idents;
				l13 = toolchain_span$Span$std_core$Hash$hash(((vader_struct_toolchain_ast$StructPatternField_t*) l7)->f_name_span);
				std_collections$Map$std_core$IndexSet$set_at__u64__Any(l12, l13, vader_ref_box(l11));
			} else {
				if (!(l3.tag == 1211u)) {
					vader_unreachable("non-exhaustive match (T3013 should have caught this)");
				}
				t0 = l8.payload.obj;
				l14 = ((vader_struct_toolchain_ast$PatternLiteral_t*) t0)->f_value;
				vader_front_resolver$walk_expr(l0, l14);
			}
			l6 = (l6 + INT64_C(1));
		}
	} else if (!(l1.tag == 1240u)) {
		if (!(l1.tag == 1174u)) {
			if (l1.tag == 1202u) {
				t0 = l1.payload.obj;
				l3 = ((vader_struct_toolchain_ast$LiteralPattern_t*) t0)->f_value;
				vader_front_resolver$walk_expr(l0, l3);
			} else if (l1.tag == 1215u) {
				t0 = l1.payload.obj;
				l3 = ((vader_struct_toolchain_ast$RangePattern_t*) t0)->f_lower;
				vader_front_resolver$walk_expr(l0, l3);
				t0 = l1.payload.obj;
				l3 = ((vader_struct_toolchain_ast$RangePattern_t*) t0)->f_upper;
				vader_front_resolver$walk_expr(l0, l3);
			} else {
				if (!(l1.tag == 1209u)) {
					vader_unreachable("non-exhaustive match (T3013 should have caught this)");
				}
				t0 = l1.payload.obj;
				l4 = ((vader_struct_toolchain_ast$OrPattern_t*) t0)->f_patterns;
				l5 = vader_array_length(((vader_array_t*) l4));
				l6 = INT64_C(0);
				while ((l6 < l5)) {
					vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
					VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
					VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
					l3 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l6);
					vader_front_resolver$bind_pattern(l0, l3);
					l6 = (l6 + INT64_C(1));
				}
			}
		}
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$bind_trait_params(void* l0, void* l1, void* l2) {
	int64_t l3, l4;
	vader_string_t l5 = 0;
	vader_box_t l6 = vader_box_null(), l7 = vader_box_null(), l8 = vader_box_null();
	void* t0 = NULL;
	vader_box_t* gc_roots[3] = { &l6, &l7, &l8 };
	void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
	vader_string_t* gc_atom_roots[1] = { &l5 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l3 = vader_array_length(((vader_array_t*) ((vader_struct_toolchain_ast$TraitDecl_t*) l1)->f_type_params));
	l4 = vader_array_length(((vader_array_t*) l2));
	l3 = std_math$min__i64(l3, l4);
	l4 = INT64_C(0);
	while ((l4 < l3)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$TraitDecl_t*) l1)->f_type_params);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
		t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l4);
		l5 = ((vader_struct_toolchain_ast$TypeParam_t*) t0)->f_name;
		vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
		l6 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l4);
		vader_front_resolver$bind_1(l0, l5, l6);
		l4 = (l4 + INT64_C(1));
	}
	l4 = vader_array_length(((vader_array_t*) ((vader_struct_toolchain_ast$TraitDecl_t*) l1)->f_type_params));
	while ((l3 < l4)) {
		vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$TraitDecl_t*) l1)->f_type_params);
		VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
		t0 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l3);
		l7 = ((vader_struct_toolchain_ast$TypeParam_t*) t0)->f_default;
		if (l7.tag == 0u) break;
		l6 = l7;
		vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$TraitDecl_t*) l1)->f_type_params);
		VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l3)
		t0 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l3);
		l5 = ((vader_struct_toolchain_ast$TypeParam_t*) t0)->f_name;
		l8 = vader_front_resolver$substitute_type_expr(l6, l0);
		vader_front_resolver$bind_1(l0, l5, l8);
		l3 = (l3 + INT64_C(1));
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
	std_collections$Map$std_core$IndexSet$set_at__u64__Any(l4, l5, vader_ref_box(l3));
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
	vader_array_t* _a0_arr = vader_array_new(93u, 0u, 13u, 1245u);
	l2 = (void*) _a0_arr;
	l3 = ((vader_struct_vader_front_resolver$FileImports_t*) l1)->f_bindings;
	l4 = ((vader_struct_std_collections$Map__string__vader_core_symbol_Symbol_t*) l3)->f_ekeys;
	l5 = ((vader_struct_std_collections$Map__string__vader_core_symbol_Symbol_t*) l3)->f_evals;
	l6 = INT64_C(0);
	l7 = ((vader_struct_std_collections$Map__string__vader_core_symbol_Symbol_t*) l3)->f_size;
	while ((l6 < l7)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
		t0 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l6];
		l8 = t0.payload.s;
		vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
		VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
		l3 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l6);
		l9 = l8;
		l10 = l3;
		l12 = std_collections$Map$std_core$Index$at__string__Any(((vader_struct_vader_front_resolver$CollectedModule_t*) l0)->f_symbols, l9);
		if (!(l12.tag == 0u)) {
			l11 = l12.payload.obj;
			l14 = ((vader_struct_vader_core_symbol$Symbol_t*) l10)->f_defined_at;
			if (!(l14.tag == 0u)) {
				l13 = l14.payload.obj;
				if (((vader_struct_vader_core_symbol$Symbol_t*) l11)->f_kind != INT32_C(0)) {
					l15 = concat_3(1307u, l9, 1307u);
					l16 = toolchain_diagnostics$resolver_error((uint8_t) 10, l13, l15);
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
	if (l0.tag == 1220u) {
		t0 = l0.payload.obj;
		l1 = ((vader_struct_toolchain_ast$SimpleBinding_t*) t0)->f_name_span;
		return l1;
	}
	if (l0.tag == 1233u) {
		t0 = l0.payload.obj;
		l1 = ((vader_struct_toolchain_ast$TupleBinding_t*) t0)->f_span;
	} else if (l0.tag == 1216u) {
		t0 = l0.payload.obj;
		l1 = ((vader_struct_toolchain_ast$RestBinding_t*) t0)->f_span;
	} else {
		if (!(l0.tag == 1238u)) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		t0 = l0.payload.obj;
		l1 = ((vader_struct_toolchain_ast$WildcardBinding_t*) t0)->f_span;
	}
	return l1;
}

static vader_string_t vader_front_resolver$bodies_folder(vader_string_t l0) {
	vader_string_t t0;
	t0 = concat_2(l0, 500u);
	return t0;
}

static vader_string_t vader_front_resolver$body_record_key(vader_string_t l0, void* l1, void* l2) {
	void* l3 = NULL;
	void* t0 = NULL;
	vader_string_t t1 = 0;
	vader_string_t t2 = 0;
	void** gc_raw_roots[4] = { &l1, &l2, &l3, &t0 };
	vader_string_t* gc_atom_roots[3] = { &l0, &t1, &t2 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l3 = ((vader_struct_vader_front_resolver$DriverNames_t*) l2)->f_sent;
	vader_struct_toolchain_protocol$BodyStageFrame_t* _a0_obj = (vader_struct_toolchain_protocol$BodyStageFrame_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_protocol$BodyStageFrame_t));
	vader_obj_header_init(_a0_obj, 1271u);
	_a0_obj->f_stage = l0;
	_a0_obj->f_request = l1;
	_a0_obj->f_names = l3;
	t0 = (void*) _a0_obj;
	t1 = toolchain_protocol$server_payload(vader_ref_box(t0));
	t2 = std_numbers$to_hex((uint64_t) vader_string_hash(t1));
	{ vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_front_resolver$body_record_path(vader_string_t l0, vader_string_t l1, void* l2) {
	vader_string_t l3 = 0;
	vader_string_t l6 = 0;
	void* l4 = NULL;
	vader_box_t l5 = vader_box_null();
	vader_string_t t0 = 0;
	vader_string_t t1 = 0;
	vader_box_t* gc_roots[1] = { &l5 };
	void** gc_raw_roots[2] = { &l2, &l4 };
	vader_string_t* gc_atom_roots[6] = { &l0, &l1, &l3, &l6, &t0, &t1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 6u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	t0 = ((vader_struct_toolchain_stage$BodyRequest_t*) l2)->f_module_name;
	l3 = vader_front_resolver$bodies_folder(t0);
	t0 = vader_front_resolver$stage_records_dir(l0);
	t1 = vader_front_resolver$join_path(t0, l1);
	l3 = vader_front_resolver$join_path(t1, l3);
	l4 = ((vader_struct_toolchain_stage$BodyRequest_t*) l2)->f_decl;
	l5 = ((vader_struct_toolchain_stage$BodyRequest_t*) l2)->f_owner;
	t0 = vader_front_resolver$late_fn_label(l4, l5);
	l6 = concat_2(t0, 520u);
	t0 = vader_front_resolver$join_path(l3, l6);
	{ vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$body_stages(void) {
	void* t0 = NULL;
	void** gc_raw_roots[1] = { &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(36u, 0u, 0u, 660u);
	t0 = (void*) _a0_arr;
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$body_stages_of_driver(vader_box_t l0) {
	void* l1 = NULL;
	vader_string_t l2 = 0;
	vader_box_t l3 = vader_box_null();
	void* t0 = NULL;
	int32_t t1;
	vader_string_t t2 = 0;
	vader_box_t* gc_roots[2] = { &l0, &l3 };
	void** gc_raw_roots[2] = { &l1, &t0 };
	vader_string_t* gc_atom_roots[2] = { &l2, &t2 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	if (l0.tag == 0u) {
		t0 = vader_front_resolver$replayed_body_stages(0u);
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	t1 = vader_global$vader_front_resolver$driver_stages$state;
	if (t1 == INT32_C(2)) {
		l1 = vader_global$vader_front_resolver$driver_stages$instance;
	} else {
		l1 = vader_front_resolver$driver_stages();
	}
	l2 = l0.payload.s;
	l3 = std_collections$Map$std_core$Index$at__string__Any(l1, l2);
	if (l3.tag == 0u) {
		t2 = l0.payload.s;
		t0 = vader_front_resolver$replayed_body_stages(t2);
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l1 = l3.payload.obj;
	{ void* __vret = ((vader_struct_vader_front_resolver$DriverStages_t*) l1)->f_bodies; vader_gc_top = gc_frame.prev; return __vret; }
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
	l5 = vader_array_length(((vader_array_t*) l4));
	l6 = INT64_C(0);
	while ((l6 < l5)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l6);
		l7 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) t0)->f_program)->f_decls;
		l8 = vader_array_length(((vader_array_t*) l7));
		l9 = INT64_C(0);
		while ((l9 < l8)) {
			vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
			VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
			l3 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l9);
			if (l3.tag == 1181u) {
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
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
	l1 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(35u, 0u, 0u, 653u);
	l2 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 645u);
	l3 = (void*) _a2_arr;
	vader_struct_std_collections$Map__string__Any_t* _a3_obj = (vader_struct_std_collections$Map__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any_t));
	vader_obj_header_init(_a3_obj, 1004u);
	_a3_obj->f_ekeys = l1;
	_a3_obj->f_evals = l2;
	_a3_obj->f_index = l3;
	_a3_obj->f_mask = INT64_C(0);
	_a3_obj->f_grow_at = INT64_C(0);
	_a3_obj->f_size = INT64_C(0);
	_a3_obj->f_tombs = INT64_C(0);
	l1 = (void*) _a3_obj;
	l4 = std_collections$Map$std_core$Index$at__string__Any(((vader_struct_vader_front_resolver$LoadedProject_t*) l0)->f_modules, 612u);
	if (l4.tag == 1796u) {
		t0 = l4.payload.obj;
		l2 = ((vader_struct_vader_front_resolver$CollectedModule_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) t0)->f_collected)->f_symbols;
		l3 = ((vader_struct_std_collections$Map__string__vader_core_symbol_Symbol_t*) l2)->f_ekeys;
		l5 = ((vader_struct_std_collections$Map__string__vader_core_symbol_Symbol_t*) l2)->f_evals;
		l6 = INT64_C(0);
		l7 = ((vader_struct_std_collections$Map__string__vader_core_symbol_Symbol_t*) l2)->f_size;
		while ((l6 < l7)) {
			vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
			VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
			VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l6)
			t1 = vader_array_box_slots(_a4_slotarr->buf)[vader_array_offset(_a4_slotarr) + (size_t) l6];
			l8 = t1.payload.s;
			vader_array_t* _a5_slotarr = ((vader_array_t*) l5);
			VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
			VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l6)
			l2 = vader_array_ref_load_obj(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) l6);
			l9 = l8;
			l10 = l2;
			std_collections$Map$std_core$IndexSet$set_at__string__Any(l1, l9, vader_ref_box(l10));
			l6 = (l6 + INT64_C(1));
		}
	}
	l4 = vader_front_resolver$find_core_module_id(l0);
	if (l4.tag == 0u) {
		{ void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l8 = l4.payload.s;
	l4 = std_collections$Map$std_core$Index$at__string__Any(((vader_struct_vader_front_resolver$LoadedProject_t*) l0)->f_modules, l8);
	if (l4.tag == 0u) {
		{ void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l2 = l4.payload.obj;
	l2 = ((vader_struct_vader_front_resolver$CollectedModule_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l2)->f_collected)->f_symbols;
	l3 = ((vader_struct_std_collections$Map__string__vader_core_symbol_Symbol_t*) l2)->f_ekeys;
	l5 = ((vader_struct_std_collections$Map__string__vader_core_symbol_Symbol_t*) l2)->f_evals;
	l6 = INT64_C(0);
	l7 = ((vader_struct_std_collections$Map__string__vader_core_symbol_Symbol_t*) l2)->f_size;
	while ((l6 < l7)) {
		vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l6)
		t1 = vader_array_box_slots(_a6_slotarr->buf)[vader_array_offset(_a6_slotarr) + (size_t) l6];
		l8 = t1.payload.s;
		vader_array_t* _a7_slotarr = ((vader_array_t*) l5);
		VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l6)
		l2 = vader_array_ref_load_obj(_a7_slotarr->buf, vader_array_offset(_a7_slotarr) + (size_t) l6);
		l9 = l8;
		l10 = l2;
		t2 = vader_front_resolver$wildcard_exposes(l10, vader_box_obj(0u, NULL));
		if (t2) {
			std_collections$Map$std_core$IndexSet$set_at__string__Any(l1, l9, vader_ref_box(l10));
		}
		l6 = (l6 + INT64_C(1));
	}
	{ void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$build_subst(void* l0, void* l1, void* l2) {
	void* l3 = NULL;
	vader_box_t l4 = vader_box_null();
	vader_box_t* gc_roots[1] = { &l4 };
	void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l3 = vader_front_resolver$new_subst();
	l4 = ((vader_struct_toolchain_ast$ImplDecl_t*) l0)->f_for_type;
	vader_front_resolver$bind_1(l3, 990u, l4);
	vader_front_resolver$bind_trait_params(l3, l1, l2);
	{ void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$builtin_type_names(void) {
	void* l0 = NULL;
	void* l1 = NULL;
	int64_t l2, l3;
	vader_string_t l4 = 0;
	void* t0 = NULL;
	int64_t t1;
	vader_box_t t2 = vader_box_null();
	vader_box_t* gc_roots[1] = { &t2 };
	void** gc_raw_roots[3] = { &l0, &l1, &t0 };
	vader_string_t* gc_atom_roots[1] = { &l4 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	t0 = (void*) &vader_data_46;
	t1 = vader_array_length(((vader_array_t*) t0));
	vader_array_t* _a0_arr = vader_array_reserve(28u, (int64_t) t1, 0u, 642u);
	l0 = (void*) _a0_arr;
	l1 = (void*) &vader_data_46;
	l2 = vader_array_length(((vader_array_t*) l1));
	l3 = INT64_C(0);
	while ((l3 < l2)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		t0 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l3);
		l4 = ((vader_struct_vader_core_types$PrimitiveMeta_t*) t0)->f_name;
		vader_array_push_scalar((vader_array_t*) l0, vader_box_string(642u, l4));
		l3 = (l3 + INT64_C(1));
	}
	l1 = (void*) &vader_data_14;
	l2 = vader_array_length(((vader_array_t*) l1));
	l3 = INT64_C(0);
	while ((l3 < l2)) {
		vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
		VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
		t2 = vader_array_box_slots(_a2_slotarr->buf)[vader_array_offset(_a2_slotarr) + (size_t) l3];
		l4 = t2.payload.s;
		vader_array_push_scalar((vader_array_t*) l0, vader_box_string(642u, l4));
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
	void* l12 = NULL;
	void* l19 = NULL;
	void* l23 = NULL;
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
	int64_t l6, l7, l8, l9, l16, l17, l33, l34;
	vader_box_t l10 = vader_box_null(), l13 = vader_box_null(), l15 = vader_box_null(), l39 = vader_box_null();
	vader_string_t l14 = 0;
	vader_string_t l18 = 0;
	vader_string_t l20 = 0;
	vader_string_t l21 = 0;
	vader_string_t l22 = 0;
	vader_string_t l24 = 0;
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
	vader_box_t t2 = vader_box_null();
	vader_box_t* gc_roots[5] = { &l10, &l13, &l15, &l39, &t2 };
	void** gc_raw_roots[23] = {
		&l0, &l1, &l2, &l3, &l4, &l5, &l11, &l12, &l19, &l23, &l25, &l26, &l27, &l28, &l29, &l31,
		&l32, &l41, &l42, &l48, &l49, &l50, &t0,
	};
	vader_string_t* gc_atom_roots[16] = {
		&l14, &l18, &l20, &l21, &l22, &l24, &l30, &l36, &l37, &l38, &l40, &l43, &l44, &l45, &l46,
		&l47,
	};
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 5u, 23u, gc_roots, gc_raw_roots, 0u, NULL, 16u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
	l2 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(35u, 0u, 0u, 653u);
	l3 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 645u);
	l4 = (void*) _a2_arr;
	vader_struct_std_collections$Map__string__Any_t* _a3_obj = (vader_struct_std_collections$Map__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any_t));
	vader_obj_header_init(_a3_obj, 1004u);
	_a3_obj->f_ekeys = l2;
	_a3_obj->f_evals = l3;
	_a3_obj->f_index = l4;
	_a3_obj->f_mask = INT64_C(0);
	_a3_obj->f_grow_at = INT64_C(0);
	_a3_obj->f_size = INT64_C(0);
	_a3_obj->f_tombs = INT64_C(0);
	l2 = (void*) _a3_obj;
	vader_array_t* _a4_arr = vader_array_new(28u, 0u, 0u, 642u);
	l3 = (void*) _a4_arr;
	vader_array_t* _a5_arr = vader_array_new(35u, 0u, 0u, 653u);
	l4 = (void*) _a5_arr;
	vader_array_t* _a6_arr = vader_array_new(29u, 0u, 7u, 645u);
	l5 = (void*) _a6_arr;
	vader_struct_std_collections$Map__string__Any_t* _a7_obj = (vader_struct_std_collections$Map__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any_t));
	vader_obj_header_init(_a7_obj, 1004u);
	_a7_obj->f_ekeys = l3;
	_a7_obj->f_evals = l4;
	_a7_obj->f_index = l5;
	_a7_obj->f_mask = INT64_C(0);
	_a7_obj->f_grow_at = INT64_C(0);
	_a7_obj->f_size = INT64_C(0);
	_a7_obj->f_tombs = INT64_C(0);
	l3 = (void*) _a7_obj;
	l4 = l0;
	l6 = vader_array_length(((vader_array_t*) l4));
	l7 = INT64_C(0);
	while ((l7 < l6)) {
		vader_array_t* _a8_slotarr = ((vader_array_t*) l4);
		VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
		t0 = vader_array_ref_load_obj(_a8_slotarr->buf, vader_array_offset(_a8_slotarr) + (size_t) l7);
		l5 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) t0)->f_program)->f_decls;
		l8 = vader_array_length(((vader_array_t*) l5));
		l9 = INT64_C(0);
		while ((l9 < l8)) {
			vader_array_t* _a9_slotarr = ((vader_array_t*) l5);
			VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
			l10 = vader_array_ref_load_box(_a9_slotarr->buf, vader_array_offset(_a9_slotarr) + (size_t) l9);
			if (l10.tag == 1181u) {
				l11 = l10.payload.obj;
				l13 = vader_front_resolver$target_selectors(((vader_struct_toolchain_ast$FnDecl_t*) l11)->f_decorators);
				if (l13.tag == 0u) {
					l9 = (l9 + INT64_C(1));
					continue;
				}
				l12 = l13.payload.obj;
				t1 = ((vader_struct_vader_front_resolver$TargetSelectors_t*) l12)->f_is_bare;
				if (t1) {
					l14 = ((vader_struct_toolchain_ast$FnDecl_t*) l11)->f_name;
					l15 = std_collections$Map$std_core$Index$at__string__Any(l2, l14);
					if (l15.tag == 0u) {
						l24 = ((vader_struct_toolchain_ast$FnDecl_t*) l11)->f_name;
						std_collections$Map$std_core$IndexSet$set_at__string__Any(l2, l24, vader_ref_box(l11));
					} else {
						t0 = l15.payload.obj;
						l16 = vader_array_length(((vader_array_t*) ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_params));
						l17 = vader_array_length(((vader_array_t*) ((vader_struct_toolchain_ast$FnDecl_t*) l11)->f_params));
						if (l16 != l17) {
							l18 = 61u;
						} else {
							l18 = 0u;
						}
						l19 = ((vader_struct_toolchain_ast$FnDecl_t*) l11)->f_name_span;
						l20 = ((vader_struct_toolchain_ast$FnDecl_t*) l11)->f_name;
						t0 = l15.payload.obj;
						l21 = vader_front_resolver$span_origin(((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_name_span);
						l22 = concat_5(1307u, l20, 1451u, l21, l18);
						l23 = toolchain_diagnostics$resolver_error((uint8_t) 30, l19, l22);
						vader_array_push_ref((vader_array_t*) l1, l23);
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
	l6 = vader_array_length(((vader_array_t*) l4));
	l7 = INT64_C(0);
	while ((l7 < l6)) {
		vader_array_t* _a10_slotarr = ((vader_array_t*) l4);
		VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
		t0 = vader_array_ref_load_obj(_a10_slotarr->buf, vader_array_offset(_a10_slotarr) + (size_t) l7);
		l5 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) t0)->f_program)->f_decls;
		l8 = vader_array_length(((vader_array_t*) l5));
		l9 = INT64_C(0);
		while ((l9 < l8)) {
			vader_array_t* _a11_slotarr = ((vader_array_t*) l5);
			VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
			l10 = vader_array_ref_load_box(_a11_slotarr->buf, vader_array_offset(_a11_slotarr) + (size_t) l9);
			if (l10.tag == 1181u) {
				l11 = l10.payload.obj;
				l13 = vader_front_resolver$target_selectors(((vader_struct_toolchain_ast$FnDecl_t*) l11)->f_decorators);
				if (l13.tag == 0u) {
					l9 = (l9 + INT64_C(1));
					continue;
				}
				l12 = l13.payload.obj;
				t1 = ((vader_struct_vader_front_resolver$TargetSelectors_t*) l12)->f_is_bare;
				if (t1) {
					l9 = (l9 + INT64_C(1));
					continue;
				}
				l14 = ((vader_struct_toolchain_ast$FnDecl_t*) l11)->f_name;
				l15 = std_collections$Map$std_core$Index$at__string__Any(l2, l14);
				if (l15.tag == 0u) {
					l19 = ((vader_struct_toolchain_ast$FnDecl_t*) l11)->f_name_span;
					l18 = ((vader_struct_toolchain_ast$FnDecl_t*) l11)->f_name;
					l20 = concat_3(1307u, l18, 1395u);
					l23 = toolchain_diagnostics$resolver_error((uint8_t) 27, l19, l20);
					vader_array_push_ref((vader_array_t*) l1, l23);
				} else {
					t0 = l15.payload.obj;
					vader_front_resolver$check_signature(t0, l11, l1);
				}
				if (((vader_struct_toolchain_ast$FnDecl_t*) l11)->f_visibility == INT32_C(0)) {
					l25 = ((vader_struct_toolchain_ast$FnDecl_t*) l11)->f_name_span;
					l21 = ((vader_struct_toolchain_ast$FnDecl_t*) l11)->f_name;
					l22 = concat_3(1307u, l21, 1442u);
					l26 = toolchain_diagnostics$resolver_error((uint8_t) 28, l25, l22);
					vader_array_push_ref((vader_array_t*) l1, l26);
				}
				l27 = ((vader_struct_toolchain_ast$FnDecl_t*) l11)->f_decorators;
				l16 = vader_array_length(((vader_array_t*) l27));
				l17 = INT64_C(0);
				while ((l17 < l16)) {
					vader_array_t* _a12_slotarr = ((vader_array_t*) l27);
					VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
					l28 = vader_array_ref_load_obj(_a12_slotarr->buf, vader_array_offset(_a12_slotarr) + (size_t) l17);
					t1 = toolchain_ast$is_compiler(l28, (uint8_t) 22);
					if (!(t1)) {
						t1 = vader_front_resolver$provides_body(l28);
						if (!(t1)) {
							l29 = ((vader_struct_toolchain_ast$Decorator_t*) l28)->f_span;
							l24 = ((vader_struct_toolchain_ast$Decorator_t*) l28)->f_name;
							l30 = concat_3(1708u, l24, 1348u);
							l31 = toolchain_diagnostics$resolver_error((uint8_t) 28, l29, l30);
							vader_array_push_ref((vader_array_t*) l1, l31);
						}
					}
					l17 = (l17 + INT64_C(1));
				}
				l32 = ((vader_struct_vader_front_resolver$TargetSelectors_t*) l12)->f_os;
				l33 = vader_array_length(((vader_array_t*) l32));
				l34 = INT64_C(0);
				while ((l34 < l33)) {
					vader_array_t* _a13_slotarr = ((vader_array_t*) l32);
					VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
					t2 = vader_array_read_u8(_a13_slotarr, vader_array_offset(_a13_slotarr) + (size_t) l34, 647u);
					l35 = ((uint8_t) t2.payload.i);
					l36 = ((vader_struct_toolchain_ast$FnDecl_t*) l11)->f_name;
					l37 = std_target$Os$std_core$Display$to_string(l35);
					l38 = concat_3(l36, 3801u, l37);
					l39 = std_collections$Map$std_core$Index$at__string__Any(l3, l38);
					if (l39.tag == 0u) {
						l50 = ((vader_struct_toolchain_ast$FnDecl_t*) l11)->f_name_span;
						std_collections$Map$std_core$IndexSet$set_at__string__Any(l3, l38, vader_ref_box(l50));
					} else {
						l41 = l39.payload.obj;
						l42 = ((vader_struct_toolchain_ast$FnDecl_t*) l11)->f_name_span;
						t1 = toolchain_span$Span$std_core$Equals$equals(l41, l42);
						if (t1) {
							l43 = ((vader_struct_toolchain_ast$FnDecl_t*) l11)->f_name;
							l44 = std_target$Os$std_core$Display$to_string(l35);
							l40 = concat_5(1307u, l43, 1526u, l44, 1613u);
						} else {
							l45 = ((vader_struct_toolchain_ast$FnDecl_t*) l11)->f_name;
							l46 = std_target$Os$std_core$Display$to_string(l35);
							t0 = l39.payload.obj;
							l47 = vader_front_resolver$span_origin(t0);
							l40 = concat_6(1307u, l45, 1333u, l46, 1345u, l47);
						}
						l48 = ((vader_struct_toolchain_ast$FnDecl_t*) l11)->f_name_span;
						l49 = toolchain_diagnostics$resolver_error((uint8_t) 29, l48, l40);
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
	void* l11 = NULL;
	void* l14 = NULL;
	void* l16 = NULL;
	void* l20 = NULL;
	void* l23 = NULL;
	void* l25 = NULL;
	int64_t l6, l7;
	vader_box_t l8 = vader_box_null(), l9 = vader_box_null();
	vader_string_t l10 = 0;
	vader_string_t l12 = 0;
	vader_string_t l13 = 0;
	vader_string_t l15 = 0;
	vader_string_t l17 = 0;
	vader_string_t l19 = 0;
	vader_string_t l21 = 0;
	vader_string_t l22 = 0;
	vader_string_t l24 = 0;
	bool l18;
	vader_box_t t0 = vader_box_null();
	vader_box_t* gc_roots[3] = { &l8, &l9, &t0 };
	void** gc_raw_roots[12] = { &l0, &l1, &l2, &l3, &l4, &l5, &l11, &l14, &l16, &l20, &l23, &l25 };
	vader_string_t* gc_atom_roots[9] = { &l10, &l12, &l13, &l15, &l17, &l19, &l21, &l22, &l24 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 3u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 9u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
	l2 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(35u, 0u, 0u, 653u);
	l3 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 645u);
	l4 = (void*) _a2_arr;
	vader_struct_std_collections$Map__string__Any_t* _a3_obj = (vader_struct_std_collections$Map__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any_t));
	vader_obj_header_init(_a3_obj, 1004u);
	_a3_obj->f_ekeys = l2;
	_a3_obj->f_evals = l3;
	_a3_obj->f_index = l4;
	_a3_obj->f_mask = INT64_C(0);
	_a3_obj->f_grow_at = INT64_C(0);
	_a3_obj->f_size = INT64_C(0);
	_a3_obj->f_tombs = INT64_C(0);
	l2 = (void*) _a3_obj;
	vader_array_t* _a4_arr = vader_array_new(28u, 0u, 0u, 642u);
	l3 = (void*) _a4_arr;
	vader_array_t* _a5_arr = vader_array_new(35u, 0u, 0u, 653u);
	l4 = (void*) _a5_arr;
	vader_array_t* _a6_arr = vader_array_new(29u, 0u, 7u, 645u);
	l5 = (void*) _a6_arr;
	vader_struct_std_collections$Map__string__Any_t* _a7_obj = (vader_struct_std_collections$Map__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any_t));
	vader_obj_header_init(_a7_obj, 1004u);
	_a7_obj->f_ekeys = l3;
	_a7_obj->f_evals = l4;
	_a7_obj->f_index = l5;
	_a7_obj->f_mask = INT64_C(0);
	_a7_obj->f_grow_at = INT64_C(0);
	_a7_obj->f_size = INT64_C(0);
	_a7_obj->f_tombs = INT64_C(0);
	l3 = (void*) _a7_obj;
	l4 = l0;
	l6 = vader_array_length(((vader_array_t*) l4));
	l7 = INT64_C(0);
	while ((l7 < l6)) {
		vader_array_t* _a8_slotarr = ((vader_array_t*) l4);
		VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
		l8 = vader_array_ref_load_box(_a8_slotarr->buf, vader_array_offset(_a8_slotarr) + (size_t) l7);
		if (l8.tag == 1191u) {
			l5 = l8.payload.obj;
			l9 = ((vader_struct_toolchain_ast$ImportDecl_t*) l5)->f_binding;
			if (l9.tag == 1239u) {
				l10 = ((vader_struct_toolchain_ast$ImportDecl_t*) l5)->f_path;
				t0 = std_collections$Map$std_core$Index$at__string__Any(l3, l10);
				if (!(t0.tag == 0u)) {
					l11 = ((vader_struct_toolchain_ast$ImportDecl_t*) l5)->f_span;
					l12 = ((vader_struct_toolchain_ast$ImportDecl_t*) l5)->f_path;
					l13 = concat_3(1307u, l12, 1307u);
					l14 = toolchain_diagnostics$resolver_error((uint8_t) 23, l11, l13);
					vader_array_push_ref((vader_array_t*) l1, l14);
				}
				l15 = ((vader_struct_toolchain_ast$ImportDecl_t*) l5)->f_path;
				l16 = ((vader_struct_toolchain_ast$ImportDecl_t*) l5)->f_span;
				std_collections$Map$std_core$IndexSet$set_at__string__Any(l2, l15, vader_ref_box(l16));
			} else if (l9.tag == 1166u) {
				l17 = ((vader_struct_toolchain_ast$ImportDecl_t*) l5)->f_path;
				t0 = std_collections$Map$std_core$Index$at__string__Any(l2, l17);
				if (!(t0.tag == 0u)) {
					l18 = true;
				} else {
					l19 = ((vader_struct_toolchain_ast$ImportDecl_t*) l5)->f_path;
					t0 = std_collections$Map$std_core$Index$at__string__Any(l3, l19);
					l18 = !(t0.tag == 0u);
				}
				if (l18) {
					l20 = ((vader_struct_toolchain_ast$ImportDecl_t*) l5)->f_span;
					l21 = ((vader_struct_toolchain_ast$ImportDecl_t*) l5)->f_path;
					l22 = concat_3(1307u, l21, 1307u);
					l23 = toolchain_diagnostics$resolver_error((uint8_t) 23, l20, l22);
					vader_array_push_ref((vader_array_t*) l1, l23);
				}
				l24 = ((vader_struct_toolchain_ast$ImportDecl_t*) l5)->f_path;
				l25 = ((vader_struct_toolchain_ast$ImportDecl_t*) l5)->f_span;
				std_collections$Map$std_core$IndexSet$set_at__string__Any(l3, l24, vader_ref_box(l25));
			}
		}
		l7 = (l7 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$check_orphan_rule(void* l0, vader_string_t l1, void* l2, void* l3, void* l4, void* l5, void* l6) {
	vader_string_t l7 = 0;
	vader_string_t l13 = 0;
	vader_box_t l8 = vader_box_null();
	bool l9, l10, l11;
	void* l12 = NULL;
	void* t0 = NULL;
	vader_string_t t1 = 0;
	vader_box_t* gc_roots[1] = { &l8 };
	void** gc_raw_roots[8] = { &l0, &l2, &l3, &l4, &l5, &l6, &l12, &t0 };
	vader_string_t* gc_atom_roots[4] = { &l1, &l7, &l13, &t1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l8 = vader_front_resolver$trait_owner_module(l0, l2, l3, l5);
	if (l8.tag == 0u) {
		{ vader_gc_top = gc_frame.prev; return; }
	}
	l7 = l8.payload.s;
	l8 = vader_front_resolver$for_type_owner_sym(((vader_struct_toolchain_ast$ImplDecl_t*) l0)->f_for_type, l4, l5);
	l9 = false;
	l10 = false;
	if (l8.tag == 1491u) {
		t0 = l8.payload.obj;
		l9 = ((vader_struct_vader_core_symbol$Symbol_t*) t0)->f_kind == INT32_C(12);
		t0 = l8.payload.obj;
		t1 = ((vader_struct_vader_core_symbol$Symbol_t*) t0)->f_module;
		l10 = t1 == l1;
	}
	l11 = l7 == l1;
	if (l9) {
		{ vader_gc_top = gc_frame.prev; return; }
	}
	if (l10) {
		{ vader_gc_top = gc_frame.prev; return; }
	}
	if (l11) {
		{ vader_gc_top = gc_frame.prev; return; }
	}
	l12 = ((vader_struct_toolchain_ast$ImplDecl_t*) l0)->f_span;
	l7 = toolchain_ast$impl_trait_written_name(l0);
	l13 = vader_front_resolver$for_type_display_name(((vader_struct_toolchain_ast$ImplDecl_t*) l0)->f_for_type);
	l7 = concat_4(l7, 161u, l13, 69u);
	l12 = toolchain_diagnostics$resolver_error((uint8_t) 13, l12, l7);
	vader_array_push_ref((vader_array_t*) l6, l12);
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
	bool t1;
	vader_string_t t2 = 0;
	vader_string_t t3 = 0;
	vader_box_t t4 = vader_box_null();
	vader_box_t* gc_roots[3] = { &l8, &l16, &t4 };
	void** gc_raw_roots[12] = { &l0, &l1, &l2, &l5, &l9, &l12, &l13, &l17, &l20, &l21, &l22, &t0 };
	vader_string_t* gc_atom_roots[4] = { &l18, &l19, &t2, &t3 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 3u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = l0;
	l3 = vader_array_length(((vader_array_t*) l2));
	l4 = INT64_C(0);
	while ((l4 < l3)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l4);
		l5 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) t0)->f_program)->f_decls;
		l6 = vader_array_length(((vader_array_t*) l5));
		l7 = INT64_C(0);
		while ((l7 < l6)) {
			vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
			VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
			l8 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l7);
			if (l8.tag == 1181u) {
				t0 = l8.payload.obj;
				l9 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_decorators;
				l10 = vader_array_length(((vader_array_t*) l9));
				l11 = INT64_C(0);
				while ((l11 < l10)) {
					vader_array_t* _a2_slotarr = ((vader_array_t*) l9);
					VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
					l12 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l11);
					t1 = toolchain_ast$is_compiler(l12, (uint8_t) 22);
					if (t1) {
						l13 = vader_front_resolver$selector_exprs(l12);
						l14 = vader_array_length(((vader_array_t*) l13));
						l15 = INT64_C(0);
						while ((l15 < l14)) {
							vader_array_t* _a3_slotarr = ((vader_array_t*) l13);
							VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
							l16 = vader_array_ref_load_box(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l15);
							if (l16.tag == 1171u) {
								t0 = l16.payload.obj;
								t2 = ((vader_struct_toolchain_ast$DotVariantExpr_t*) t0)->f_variant;
								t3 = std_string$to_lower(t2);
								t4 = vader_support_target$parse_os(t3);
								if (t4.tag == 0u) {
									t0 = l16.payload.obj;
									l17 = ((vader_struct_toolchain_ast$DotVariantExpr_t*) t0)->f_span;
									t0 = l16.payload.obj;
									l18 = ((vader_struct_toolchain_ast$DotVariantExpr_t*) t0)->f_variant;
									l19 = concat_3(1686u, l18, 1540u);
									l20 = toolchain_diagnostics$resolver_error((uint8_t) 26, l17, l19);
									vader_array_push_ref((vader_array_t*) l1, l20);
								}
							} else {
								l21 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l16.payload.obj);
								l22 = toolchain_diagnostics$resolver_error((uint8_t) 26, l21, 1803u);
								vader_array_push_ref((vader_array_t*) l1, l22);
							}
							l15 = (l15 + INT64_C(1));
						}
						l11 = (l11 + INT64_C(1));
						continue;
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
	l3 = vader_array_length(((vader_array_t*) t0));
	if (l3 == INT64_C(1)) {
		{ vader_gc_top = gc_frame.prev; return; }
	}
	l4 = INT64_C(0);
	l5 = vader_array_length(((vader_array_t*) ((vader_struct_toolchain_ast$ImplDecl_t*) l0)->f_members));
	while ((l4 < l5)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$ImplDecl_t*) l0)->f_members);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
		l6 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l4);
		t1 = ((vader_struct_toolchain_ast$FnDecl_t*) l6)->f_sam_synthetic;
		if (t1) {
			l7 = ((vader_struct_toolchain_ast$FnDecl_t*) l6)->f_span;
			l8 = toolchain_ast$impl_trait_name(l0);
			l9 = (int64_t) vader_string_byte_len(l8);
			l10 = (void*) vader_buffer_new((size_t) (INT64_C(50) + l9));
			l11 = INT64_C(0);
			l11 = std_core$write_string_at(l10, l11, 3391u);
			l11 = std_core$write_string_at(l10, l11, l8);
			l11 = std_core$write_string_at(l10, l11, 1385u);
			l11 = std_core$write_int(l10, l11, l3);
			l11 = std_core$write_string_at(l10, l11, 257u);
			l12 = std_core$finish_buffer(l10, l11);
			l13 = toolchain_diagnostics$resolver_error((uint8_t) 12, l7, l12);
			vader_array_push_ref((vader_array_t*) l2, l13);
			vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$ImplDecl_t*) l0)->f_members);
			VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
			VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
			t0 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l4);
			((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_materialized = true;
		}
		l4 = (l4 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$check_signature(void* l0, void* l1, void* l2) {
	int64_t l3, l4, l8, l13, l14, l15, l16, l17, l18;
	void* l5 = NULL;
	void* l9 = NULL;
	void* l22 = NULL;
	vader_string_t l6 = 0;
	vader_string_t l7 = 0;
	vader_string_t l10 = 0;
	vader_string_t l11 = 0;
	vader_string_t l12 = 0;
	vader_string_t l19 = 0;
	vader_string_t l20 = 0;
	vader_string_t l21 = 0;
	void* t0 = NULL;
	void** gc_raw_roots[7] = { &l0, &l1, &l2, &l5, &l9, &l22, &t0 };
	vader_string_t* gc_atom_roots[8] = { &l6, &l7, &l10, &l11, &l12, &l19, &l20, &l21 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 7u, NULL, gc_raw_roots, 0u, NULL, 8u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l3 = vader_array_length(((vader_array_t*) ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_params));
	l4 = vader_array_length(((vader_array_t*) ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_params));
	if (l3 != l4) {
		l5 = ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_name_span;
		l6 = ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_name;
		l3 = vader_array_length(((vader_array_t*) ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_params));
		l7 = vader_front_resolver$span_origin(((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_name_span);
		l4 = (int64_t) vader_string_byte_len(l6);
		l8 = (int64_t) vader_string_byte_len(l7);
		l4 = (l4 + l8);
		l9 = (void*) vader_buffer_new((size_t) (INT64_C(48) + l4));
		l4 = INT64_C(0);
		l4 = std_core$write_string_at(l9, l4, 1307u);
		l4 = std_core$write_string_at(l9, l4, l6);
		l4 = std_core$write_string_at(l9, l4, 1593u);
		l4 = std_core$write_int(l9, l4, l3);
		l4 = std_core$write_string_at(l9, l4, 247u);
		l4 = std_core$write_string_at(l9, l4, l7);
		l4 = std_core$write_string_at(l9, l4, 441u);
		l6 = std_core$finish_buffer(l9, l4);
		l9 = (void*) vader_buffer_new((size_t) INT64_C(36));
		l3 = INT64_C(0);
		l3 = std_core$write_string_at(l9, l3, 3370u);
		l4 = vader_array_length(((vader_array_t*) ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_params));
		l3 = std_core$write_int(l9, l3, l4);
		l7 = std_core$finish_buffer(l9, l3);
		l6 = concat_2(l6, l7);
		l5 = toolchain_diagnostics$resolver_error((uint8_t) 31, l5, l6);
		vader_array_push_ref((vader_array_t*) l2, l5);
		{ vader_gc_top = gc_frame.prev; return; }
	}
	l3 = INT64_C(0);
	l4 = vader_array_length(((vader_array_t*) ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_params));
	while ((l3 < l4)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_params);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
		t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l3);
		l6 = ((vader_struct_toolchain_ast$FnParam_t*) t0)->f_name;
		vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_params);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
		t0 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l3);
		l7 = ((vader_struct_toolchain_ast$FnParam_t*) t0)->f_name;
		if (l6 != l7) {
			vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_params);
			VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
			VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
			t0 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l3);
			l5 = ((vader_struct_toolchain_ast$FnParam_t*) t0)->f_span;
			l8 = vader_chk_add(i64, l3, INT64_C(1));
			l10 = ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_name;
			l11 = l6;
			l12 = vader_front_resolver$span_origin(((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_name_span);
			l13 = (int64_t) vader_string_byte_len(l10);
			l14 = (int64_t) vader_string_byte_len(l11);
			l15 = (l13 + l14);
			l16 = (int64_t) vader_string_byte_len(l12);
			l17 = (l15 + l16);
			l9 = (void*) vader_buffer_new((size_t) (INT64_C(48) + l17));
			l18 = INT64_C(0);
			l18 = std_core$write_string_at(l9, l18, 3055u);
			l18 = std_core$write_int(l9, l18, l8);
			l18 = std_core$write_string_at(l9, l18, 232u);
			l18 = std_core$write_string_at(l9, l18, l10);
			l18 = std_core$write_string_at(l9, l18, 1437u);
			l18 = std_core$write_string_at(l9, l18, l11);
			l18 = std_core$write_string_at(l9, l18, 1345u);
			l18 = std_core$write_string_at(l9, l18, l12);
			l18 = std_core$write_string_at(l9, l18, 441u);
			l19 = std_core$finish_buffer(l9, l18);
			l20 = concat_3(1307u, l7, 1418u);
			l21 = concat_3(l19, l20, 2272u);
			l22 = toolchain_diagnostics$resolver_error((uint8_t) 31, l5, l21);
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
	l2 = vader_front_resolver$selector_exprs(l1);
	l3 = vader_array_length(((vader_array_t*) l2));
	l4 = INT64_C(0);
	while ((l4 < l3)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		l5 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l4);
		if (l5.tag == 1171u) {
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
				l9 = concat_3(1686u, l8, 1540u);
				l10 = toolchain_diagnostics$resolver_error((uint8_t) 26, l7, l9);
				vader_array_push_ref((vader_array_t*) l6, l10);
			}
		} else {
			l11 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_diags;
			l12 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l5.payload.obj);
			l13 = toolchain_diagnostics$resolver_error((uint8_t) 26, l12, 2447u);
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
	l7 = std_collections$Map$std_core$Index$at__string__string__(((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_ambiguous, l1);
	if (l7.tag == 0u) {
		{ vader_gc_top = gc_frame.prev; return; }
	}
	l6 = l7.payload.obj;
	l8 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_diags;
	l4 = toolchain_diagnostics$wildcard_clash_detail(l1, l6);
	l6 = toolchain_diagnostics$resolver_error((uint8_t) 22, l2, l4);
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
	void* t0 = NULL;
	vader_string_t t1 = 0;
	int64_t t2;
	vader_box_t t3 = vader_box_null();
	vader_box_t* gc_roots[3] = { &l2, &l4, &t3 };
	void** gc_raw_roots[7] = { &l0, &l1, &l3, &l5, &l6, &l7, &t0 };
	vader_string_t* gc_atom_roots[3] = { &l11, &l12, &t1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 3u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l4 = vader_front_resolver$union_in_bound(l2);
	if (l4.tag == 0u) {
		{ vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l3 = l4.payload.obj;
	l5 = toolchain_ast$collect_bitor_variants(vader_ref_box(l3));
	vader_array_t* _a0_arr = vader_array_new(480u, 0u, 13u, 2419u);
	l6 = (void*) _a0_arr;
	l7 = l5;
	l8 = vader_array_length(((vader_array_t*) l7));
	l9 = INT64_C(0);
	while ((l9 < l8)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		l4 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l9);
		if (!(l4.tag == 1186u)) {
			l10 = true;
		} else {
			t0 = l4.payload.obj;
			t1 = ((vader_struct_toolchain_ast$IdentExpr_t*) t0)->f_name;
			l10 = t1 != 3004u;
		}
		if (l10) {
			vader_array_push_ref((vader_array_t*) l6, l4.payload.obj);
		}
		l9 = (l9 + INT64_C(1));
	}
	l8 = vader_array_length(((vader_array_t*) l6));
	l9 = vader_array_length(((vader_array_t*) l5));
	if ((l8 < l9)) {
		l11 = ((vader_struct_toolchain_ast$TypeParam_t*) l1)->f_name;
		l12 = ((vader_struct_toolchain_ast$TypeParam_t*) l1)->f_name;
		l11 = concat_5(3086u, l11, 1519u, l12, 307u);
	} else {
		l11 = 1817u;
	}
	l5 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_diags;
	l3 = ((vader_struct_toolchain_ast$BinaryExpr_t*) l3)->f_span;
	l12 = ((vader_struct_toolchain_ast$TypeParam_t*) l1)->f_name;
	l11 = concat_5(1307u, l12, 1309u, l11, 394u);
	l3 = toolchain_diagnostics$resolver_error((uint8_t) 33, l3, l11);
	vader_array_push_ref((vader_array_t*) l5, l3);
	t2 = vader_array_length(((vader_array_t*) l6));
	if (t2 == INT64_C(1)) {
		if (l2.tag == 1149u) {
			t0 = l2.payload.obj;
			if (((vader_struct_toolchain_ast$BinaryExpr_t*) t0)->f_op == INT32_C(8)) {
				vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
				VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
				t3 = vader_array_ref_load_box(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) INT32_C(0));
				{ vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
			}
			{ vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
		}
		{ vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
	}
	{ vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$clone_ident(void* l0) {
	void* l1 = NULL;
	void* l2 = NULL;
	vader_string_t l3 = 0;
	bool l4;
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
	vader_struct_toolchain_ast$IdentExpr_t* _a0_obj = (vader_struct_toolchain_ast$IdentExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$IdentExpr_t));
	vader_obj_header_init(_a0_obj, 1186u);
	_a0_obj->f_span = l2;
	_a0_obj->f_id = INT64_C(0);
	_a0_obj->f_name = l3;
	_a0_obj->f_implicit_dot = l4;
	t0 = (void*) _a0_obj;
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_front_resolver$collect_decl(void* l0, vader_box_t l1, vader_string_t l2, vader_string_t l3, void* l4, void* l5, void* l6, void* l7) {
	void* l8 = NULL;
	vader_string_t l9 = 0;
	uint8_t l10;
	vader_box_t l11 = vader_box_null();
	bool l12;
	void* t0 = NULL;
	vader_box_t* gc_roots[2] = { &l1, &l11 };
	void** gc_raw_roots[7] = { &l0, &l4, &l5, &l6, &l7, &l8, &t0 };
	vader_string_t* gc_atom_roots[3] = { &l2, &l3, &l9 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	if (l1.tag == 1191u) {
		l8 = l1.payload.obj;
		vader_front_resolver$collect_import(l0, l8, l2, l3, l4, l5, l6, l7);
		{ vader_gc_top = gc_frame.prev; return; }
	}
	if (l1.tag == 1181u) {
		l8 = l1.payload.obj;
		vader_front_resolver$add_fn(l0, l8, l2, l3, l4, l7);
	} else if (l1.tag == 1224u) {
		t0 = l1.payload.obj;
		l9 = ((vader_struct_toolchain_ast$StructDecl_t*) t0)->f_name;
		t0 = l1.payload.obj;
		l8 = ((vader_struct_toolchain_ast$StructDecl_t*) t0)->f_name_span;
		t0 = l1.payload.obj;
		l10 = ((vader_struct_toolchain_ast$StructDecl_t*) t0)->f_visibility;
		l11 = vader_front_resolver$add_named(l0, (uint8_t) 1, l9, l8, l10, l2, l3, l4, l7);
		if (!(l11.tag == 0u)) {
			l8 = l11.payload.obj;
			t0 = l1.payload.obj;
			l12 = toolchain_ast$is_decorator(t0);
			((vader_struct_vader_core_symbol$Symbol_t*) l8)->f_is_decorator = l12;
		}
	} else if (l1.tag == 1172u) {
		t0 = l1.payload.obj;
		l9 = ((vader_struct_toolchain_ast$EnumDecl_t*) t0)->f_name;
		t0 = l1.payload.obj;
		l8 = ((vader_struct_toolchain_ast$EnumDecl_t*) t0)->f_name_span;
		t0 = l1.payload.obj;
		l10 = ((vader_struct_toolchain_ast$EnumDecl_t*) t0)->f_visibility;
		vader_front_resolver$add_named(l0, (uint8_t) 2, l9, l8, l10, l2, l3, l4, l7);
	} else if (l1.tag == 1232u) {
		t0 = l1.payload.obj;
		l9 = ((vader_struct_toolchain_ast$TraitDecl_t*) t0)->f_name;
		t0 = l1.payload.obj;
		l8 = ((vader_struct_toolchain_ast$TraitDecl_t*) t0)->f_name_span;
		t0 = l1.payload.obj;
		l10 = ((vader_struct_toolchain_ast$TraitDecl_t*) t0)->f_visibility;
		vader_front_resolver$add_named(l0, (uint8_t) 3, l9, l8, l10, l2, l3, l4, l7);
	} else if (l1.tag == 1234u) {
		t0 = l1.payload.obj;
		l9 = ((vader_struct_toolchain_ast$TypeAliasDecl_t*) t0)->f_name;
		t0 = l1.payload.obj;
		l8 = ((vader_struct_toolchain_ast$TypeAliasDecl_t*) t0)->f_name_span;
		t0 = l1.payload.obj;
		l10 = ((vader_struct_toolchain_ast$TypeAliasDecl_t*) t0)->f_visibility;
		vader_front_resolver$add_named(l0, (uint8_t) 5, l9, l8, l10, l2, l3, l4, l7);
	} else if (l1.tag == 1157u) {
		t0 = l1.payload.obj;
		l9 = ((vader_struct_toolchain_ast$ConstDecl_t*) t0)->f_name;
		t0 = l1.payload.obj;
		l8 = ((vader_struct_toolchain_ast$ConstDecl_t*) t0)->f_name_span;
		t0 = l1.payload.obj;
		l10 = ((vader_struct_toolchain_ast$ConstDecl_t*) t0)->f_visibility;
		vader_front_resolver$add_named(l0, (uint8_t) 6, l9, l8, l10, l2, l3, l4, l7);
	} else if (!(l1.tag == 1190u)) {
		if (!(l1.tag == 1147u)) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$collect_deferred(void* l0) {
	void* l1 = NULL;
	void* l2 = NULL;
	void* l3 = NULL;
	void* l8 = NULL;
	void* l9 = NULL;
	void* l10 = NULL;
	void* l11 = NULL;
	void* l12 = NULL;
	void* l13 = NULL;
	void* l15 = NULL;
	void* l16 = NULL;
	void* l17 = NULL;
	void* l18 = NULL;
	void* l19 = NULL;
	void* l20 = NULL;
	void* l22 = NULL;
	int64_t l4, l5, l7;
	vader_string_t l6 = 0;
	vader_string_t l14 = 0;
	vader_string_t l21 = 0;
	int64_t t0;
	void* t1 = NULL;
	vader_box_t t2 = vader_box_null(), t3 = vader_box_null();
	bool t4;
	vader_box_t* gc_roots[2] = { &t2, &t3 };
	void** gc_raw_roots[18] = {
		&l0, &l1, &l2, &l3, &l8, &l9, &l10, &l11, &l12, &l13, &l15, &l16, &l17, &l18, &l19, &l20,
		&l22, &t1,
	};
	vader_string_t* gc_atom_roots[3] = { &l6, &l14, &l21 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 18u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_deferred));
	if (t0 == INT64_C(0)) {
		{ vader_gc_top = gc_frame.prev; return; }
	}
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
	l1 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(26u, 0u, 12u, 640u);
	l2 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 645u);
	l3 = (void*) _a2_arr;
	vader_struct_std_collections$Map__string__bool_t* _a3_obj = (vader_struct_std_collections$Map__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__bool_t));
	vader_obj_header_init(_a3_obj, 1010u);
	_a3_obj->f_ekeys = l1;
	_a3_obj->f_evals = l2;
	_a3_obj->f_index = l3;
	_a3_obj->f_mask = INT64_C(0);
	_a3_obj->f_grow_at = INT64_C(0);
	_a3_obj->f_size = INT64_C(0);
	_a3_obj->f_tombs = INT64_C(0);
	t1 = (void*) _a3_obj;
	vader_struct_std_collections$Set__string_t* _a4_obj = (vader_struct_std_collections$Set__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__string_t));
	vader_obj_header_init(_a4_obj, 1110u);
	_a4_obj->f_inner = t1;
	l1 = (void*) _a4_obj;
	l2 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_body_stages;
	l4 = vader_array_length(((vader_array_t*) l2));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
		t2 = vader_array_ref_load_box(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) l5);
		t3 = toolchain_stage$Stage$describe$$dispatch(t2);
		l6 = ((vader_struct_toolchain_stage$BodySpec_t*) t3.payload.obj)->f_name;
		std_collections$add__string(l1, l6);
		l5 = (l5 + INT64_C(1));
	}
	l4 = INT64_C(0);
	for (;;) {
		l5 = vader_array_length(((vader_array_t*) ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_deferred));
		if ((l4 < l5)) {
			l7 = vader_array_length(((vader_array_t*) ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_deferred));
			l2 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_deferred;
			l3 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_source_stages;
			l8 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_node_factory;
			l9 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_diags;
			vader_front_resolver$run_source_stages(l2, l4, l3, l1, l8, l9);
			vader_front_resolver$load_stage_imports(l0, l4, l7);
			l4 = l7;
			continue;
		}
		break;
	}
	l1 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_deferred;
	l2 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_node_factory;
	l3 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_diags;
	vader_front_resolver$intercept_functions(l1, l2, l3);
	t4 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_only_reached;
	if (t4) {
		l1 = vader_front_resolver$trimmed_to_reached(l0);
	} else {
		l1 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_deferred;
	}
	l4 = vader_array_length(((vader_array_t*) l1));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a6_slotarr = ((vader_array_t*) l1);
		VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l5)
		l2 = vader_array_ref_load_obj(_a6_slotarr->buf, vader_array_offset(_a6_slotarr) + (size_t) l5);
		l3 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_uncovered;
		l8 = ((vader_struct_vader_front_resolver$DeferredModule_t*) l2)->f_uncovered;
		vader_array_push_all((vader_array_t*) l3, (vader_array_t*) l8);
		l9 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_late_fns;
		l10 = ((vader_struct_vader_front_resolver$DeferredModule_t*) l2)->f_late;
		l11 = ((vader_struct_vader_front_resolver$DeferredModule_t*) l2)->f_sources;
		l12 = vader_front_resolver$still_declared(l10, l11);
		vader_array_push_all((vader_array_t*) l9, (vader_array_t*) l12);
		l13 = ((vader_struct_vader_front_resolver$DeferredModule_t*) l2)->f_sources;
		l6 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) ((vader_struct_vader_front_resolver$DeferredModule_t*) l2)->f_found)->f_folder;
		l14 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) ((vader_struct_vader_front_resolver$DeferredModule_t*) l2)->f_found)->f_name;
		l15 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_factory;
		l16 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_index;
		l17 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_bases;
		l18 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_diags;
		l19 = vader_front_resolver$collect_files(l13, l6, l14, l15, l16, l17, l18);
		l20 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_modules;
		l21 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) ((vader_struct_vader_front_resolver$DeferredModule_t*) l2)->f_found)->f_folder;
		l22 = vader_front_resolver$loaded_module(l0, l2, l19);
		std_collections$Map$std_core$IndexSet$set_at__string__Any(l20, l21, vader_ref_box(l22));
		l5 = (l5 + INT64_C(1));
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
	t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT32_C(0));
	l7 = vader_front_resolver$collect_module(((vader_struct_vader_front_resolver$SourceFile_t*) t0)->f_program, l1, l2, l3, l4, l5, l6);
	l8 = INT64_C(1);
	l9 = vader_array_length(((vader_array_t*) l0));
	while ((l8 < l9)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l8)
		t0 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l8);
		l10 = vader_front_resolver$collect_module(((vader_struct_vader_front_resolver$SourceFile_t*) t0)->f_program, l1, l2, l3, l4, l5, l6);
		vader_front_resolver$merge_collected(l7, l10, l6);
		l8 = (l8 + INT64_C(1));
	}
	{ void* __vret = l7; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_front_resolver$collect_import(void* l0, void* l1, vader_string_t l2, vader_string_t l3, void* l4, void* l5, void* l6, void* l7) {
	void* l8 = NULL;
	void* l10 = NULL;
	void* l15 = NULL;
	void* l17 = NULL;
	void* l18 = NULL;
	void* l21 = NULL;
	vader_string_t l9 = 0;
	vader_string_t l12 = 0;
	vader_string_t l19 = 0;
	vader_string_t l20 = 0;
	vader_string_t l22 = 0;
	vader_string_t l23 = 0;
	vader_box_t l11 = vader_box_null(), l16 = vader_box_null();
	int64_t l13, l14;
	vader_string_t t0 = 0;
	void* t1 = NULL;
	int64_t t2;
	vader_box_t* gc_roots[2] = { &l11, &l16 };
	void** gc_raw_roots[13] = {
		&l0, &l1, &l4, &l5, &l6, &l7, &l8, &l10, &l15, &l17, &l18, &l21, &t1,
	};
	vader_string_t* gc_atom_roots[9] = { &l2, &l3, &l9, &l12, &l19, &l20, &l22, &l23, &t0 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 13u, gc_roots, gc_raw_roots, 0u, NULL, 9u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	t0 = ((vader_struct_toolchain_ast$ImportDecl_t*) l1)->f_path;
	if (t0 == 0u) {
		l8 = ((vader_struct_toolchain_ast$ImportDecl_t*) l1)->f_span;
		l8 = toolchain_diagnostics$resolver_error((uint8_t) 1, l8, 0u);
		vader_array_push_ref((vader_array_t*) l7, l8);
	} else {
		l8 = ((vader_struct_vader_front_resolver$CollectedModule_t*) l0)->f_import_paths;
		l9 = ((vader_struct_toolchain_ast$ImportDecl_t*) l1)->f_path;
		l10 = ((vader_struct_toolchain_ast$ImportDecl_t*) l1)->f_span;
		vader_struct_vader_front_resolver$ImportPath_t* _a0_obj = (vader_struct_vader_front_resolver$ImportPath_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$ImportPath_t));
		vader_obj_header_init(_a0_obj, 1787u);
		_a0_obj->f_path = l9;
		_a0_obj->f_span = l10;
		l10 = (void*) _a0_obj;
		vader_array_push_ref((vader_array_t*) l8, l10);
		l9 = ((vader_struct_toolchain_ast$ImportDecl_t*) l1)->f_path;
		l8 = ((vader_struct_toolchain_ast$ImportDecl_t*) l1)->f_span;
		vader_front_resolver$diagnose_import_path(l9, l8, l3, l5, l6, l7);
	}
	l11 = ((vader_struct_toolchain_ast$ImportDecl_t*) l1)->f_binding;
	if (l11.tag == 1206u) {
		t1 = l11.payload.obj;
		l9 = ((vader_struct_toolchain_ast$NamedNamespaceImport_t*) t1)->f_name;
		l8 = ((vader_struct_toolchain_ast$ImportDecl_t*) l1)->f_span;
		l12 = ((vader_struct_toolchain_ast$ImportDecl_t*) l1)->f_path;
		vader_front_resolver$bind_import(l0, l9, l8, l12, vader_box_obj(0u, NULL), l2, l4, l7);
		{ vader_gc_top = gc_frame.prev; return; }
	}
	if (l11.tag == 1239u) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_front_resolver$CollectedModule_t*) l0)->f_files);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
		t1 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) INT32_C(0));
		l8 = ((vader_struct_vader_front_resolver$FileImports_t*) t1)->f_paths;
		l9 = ((vader_struct_toolchain_ast$ImportDecl_t*) l1)->f_path;
		vader_array_push_scalar((vader_array_t*) l8, vader_box_string(642u, l9));
	} else {
		if (!(l11.tag == 1166u)) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_front_resolver$CollectedModule_t*) l0)->f_files);
		VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(0))
		t1 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) INT32_C(0));
		l8 = ((vader_struct_vader_front_resolver$FileImports_t*) t1)->f_paths;
		l9 = ((vader_struct_toolchain_ast$ImportDecl_t*) l1)->f_path;
		vader_array_push_scalar((vader_array_t*) l8, vader_box_string(642u, l9));
		t1 = l11.payload.obj;
		t2 = vader_array_length(((vader_array_t*) ((vader_struct_toolchain_ast$DestructureImport_t*) t1)->f_names));
		if (t2 == INT64_C(0)) {
			l8 = ((vader_struct_toolchain_ast$ImportDecl_t*) l1)->f_span;
			l9 = ((vader_struct_toolchain_ast$ImportDecl_t*) l1)->f_path;
			l9 = concat_3(1307u, l9, 1307u);
			l8 = toolchain_diagnostics$warning((uint8_t) 8, l8, l9);
			vader_array_push_ref((vader_array_t*) l7, l8);
		}
		vader_array_t* _a3_arr = vader_array_new(28u, 0u, 0u, 642u);
		l8 = (void*) _a3_arr;
		t1 = l11.payload.obj;
		l10 = ((vader_struct_toolchain_ast$DestructureImport_t*) t1)->f_names;
		l13 = vader_array_length(((vader_array_t*) l10));
		l14 = INT64_C(0);
		while ((l14 < l13)) {
			vader_array_t* _a4_slotarr = ((vader_array_t*) l10);
			VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
			l15 = vader_array_ref_load_obj(_a4_slotarr->buf, vader_array_offset(_a4_slotarr) + (size_t) l14);
			l11 = ((vader_struct_toolchain_ast$ImportName_t*) l15)->f_alias;
			l16 = l11;
			if (l11.tag == 0u) {
				l17 = ((vader_struct_toolchain_ast$ImportName_t*) l15)->f_span;
				l9 = ((vader_struct_toolchain_ast$ImportName_t*) l15)->f_name;
				l12 = concat_3(1307u, l9, 1307u);
				l18 = toolchain_diagnostics$resolver_error((uint8_t) 24, l17, l12);
				vader_array_push_ref((vader_array_t*) l7, l18);
			} else {
				if (!(l11.tag == 642u)) {
					vader_unreachable("non-exhaustive match (T3013 should have caught this)");
				}
				l19 = ((vader_struct_toolchain_ast$ImportName_t*) l15)->f_name;
				vader_array_push_scalar((vader_array_t*) l8, vader_box_string(642u, l19));
				t0 = l16.payload.s;
				if (t0 != 1242u) {
					l20 = l16.payload.s;
					l21 = ((vader_struct_toolchain_ast$ImportName_t*) l15)->f_span;
					l22 = ((vader_struct_toolchain_ast$ImportDecl_t*) l1)->f_path;
					l23 = ((vader_struct_toolchain_ast$ImportName_t*) l15)->f_name;
					vader_front_resolver$bind_import(l0, l20, l21, l22, vader_box_string(642u, l23), l2, l4, l7);
				}
			}
			l14 = (l14 + INT64_C(1));
		}
		vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_front_resolver$CollectedModule_t*) l0)->f_files);
		VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a5_slotarr, INT32_C(0))
		t1 = vader_array_ref_load_obj(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) INT32_C(0));
		l10 = ((vader_struct_vader_front_resolver$FileImports_t*) t1)->f_excludes;
		l9 = ((vader_struct_toolchain_ast$ImportDecl_t*) l1)->f_path;
		std_collections$Map$std_core$IndexSet$set_at__string__string__(l10, l9, l8);
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
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
	l7 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(35u, 0u, 0u, 653u);
	l8 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 645u);
	l9 = (void*) _a2_arr;
	vader_struct_std_collections$Map__string__Any_t* _a3_obj = (vader_struct_std_collections$Map__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any_t));
	vader_obj_header_init(_a3_obj, 1004u);
	_a3_obj->f_ekeys = l7;
	_a3_obj->f_evals = l8;
	_a3_obj->f_index = l9;
	_a3_obj->f_mask = INT64_C(0);
	_a3_obj->f_grow_at = INT64_C(0);
	_a3_obj->f_size = INT64_C(0);
	_a3_obj->f_tombs = INT64_C(0);
	l7 = (void*) _a3_obj;
	vader_array_t* _a4_arr = vader_array_new(28u, 0u, 0u, 642u);
	l8 = (void*) _a4_arr;
	vader_array_t* _a5_arr = vader_array_new(35u, 0u, 0u, 653u);
	l9 = (void*) _a5_arr;
	vader_array_t* _a6_arr = vader_array_new(29u, 0u, 7u, 645u);
	l10 = (void*) _a6_arr;
	vader_struct_std_collections$Map__string__Any___t* _a7_obj = (vader_struct_std_collections$Map__string__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any___t));
	vader_obj_header_init(_a7_obj, 1005u);
	_a7_obj->f_ekeys = l8;
	_a7_obj->f_evals = l9;
	_a7_obj->f_index = l10;
	_a7_obj->f_mask = INT64_C(0);
	_a7_obj->f_grow_at = INT64_C(0);
	_a7_obj->f_size = INT64_C(0);
	_a7_obj->f_tombs = INT64_C(0);
	l8 = (void*) _a7_obj;
	vader_array_t* _a8_arr = vader_array_new(29u, 0u, 7u, 645u);
	l9 = (void*) _a8_arr;
	vader_array_t* _a9_arr = vader_array_new(35u, 0u, 0u, 653u);
	l10 = (void*) _a9_arr;
	vader_array_t* _a10_arr = vader_array_new(29u, 0u, 7u, 645u);
	l11 = (void*) _a10_arr;
	vader_struct_std_collections$Map__i32__Any_t* _a11_obj = (vader_struct_std_collections$Map__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__Any_t));
	vader_obj_header_init(_a11_obj, 916u);
	_a11_obj->f_ekeys = l9;
	_a11_obj->f_evals = l10;
	_a11_obj->f_index = l11;
	_a11_obj->f_mask = INT64_C(0);
	_a11_obj->f_grow_at = INT64_C(0);
	_a11_obj->f_size = INT64_C(0);
	_a11_obj->f_tombs = INT64_C(0);
	l9 = (void*) _a11_obj;
	vader_array_t* _a12_arr = vader_array_new(341u, 0u, 13u, 1787u);
	l10 = (void*) _a12_arr;
	l12 = ((vader_struct_toolchain_ast$Program_t*) l0)->f_file;
	vader_array_t* _a13_arr = vader_array_new(28u, 0u, 0u, 642u);
	l11 = (void*) _a13_arr;
	vader_array_t* _a14_arr = vader_array_new(28u, 0u, 0u, 642u);
	l13 = (void*) _a14_arr;
	vader_array_t* _a15_arr = vader_array_new(3u, 0u, 13u, 28u);
	l14 = (void*) _a15_arr;
	vader_array_t* _a16_arr = vader_array_new(29u, 0u, 7u, 645u);
	l15 = (void*) _a16_arr;
	vader_struct_std_collections$Map__string__string___t* _a17_obj = (vader_struct_std_collections$Map__string__string___t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__string___t));
	vader_obj_header_init(_a17_obj, 1029u);
	_a17_obj->f_ekeys = l13;
	_a17_obj->f_evals = l14;
	_a17_obj->f_index = l15;
	_a17_obj->f_mask = INT64_C(0);
	_a17_obj->f_grow_at = INT64_C(0);
	_a17_obj->f_size = INT64_C(0);
	_a17_obj->f_tombs = INT64_C(0);
	l13 = (void*) _a17_obj;
	vader_array_t* _a18_arr = vader_array_new(28u, 0u, 0u, 642u);
	l14 = (void*) _a18_arr;
	vader_array_t* _a19_arr = vader_array_new(35u, 0u, 0u, 653u);
	l15 = (void*) _a19_arr;
	vader_array_t* _a20_arr = vader_array_new(29u, 0u, 7u, 645u);
	l16 = (void*) _a20_arr;
	vader_struct_std_collections$Map__string__Any_t* _a21_obj = (vader_struct_std_collections$Map__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any_t));
	vader_obj_header_init(_a21_obj, 1004u);
	_a21_obj->f_ekeys = l14;
	_a21_obj->f_evals = l15;
	_a21_obj->f_index = l16;
	_a21_obj->f_mask = INT64_C(0);
	_a21_obj->f_grow_at = INT64_C(0);
	_a21_obj->f_size = INT64_C(0);
	_a21_obj->f_tombs = INT64_C(0);
	l14 = (void*) _a21_obj;
	vader_struct_vader_front_resolver$FileImports_t* _a22_obj = (vader_struct_vader_front_resolver$FileImports_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$FileImports_t));
	vader_obj_header_init(_a22_obj, 1781u);
	_a22_obj->f_file = l12;
	_a22_obj->f_paths = l11;
	_a22_obj->f_excludes = l13;
	_a22_obj->f_bindings = l14;
	t0 = (void*) _a22_obj;
	vader_array_t* _a23_arr = vader_array_new(338u, 1u, 13u, 1781u);
	((void**) _a23_arr->buf->slots)[vader_array_offset(_a23_arr) + 0u] = t0;
	l11 = (void*) _a23_arr;
	vader_struct_vader_front_resolver$CollectedModule_t* _a24_obj = (vader_struct_vader_front_resolver$CollectedModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$CollectedModule_t));
	vader_obj_header_init(_a24_obj, 1773u);
	_a24_obj->f_symbols = l7;
	_a24_obj->f_fn_overloads = l8;
	_a24_obj->f_imports = l9;
	_a24_obj->f_import_paths = l10;
	_a24_obj->f_files = l11;
	l7 = (void*) _a24_obj;
	vader_front_resolver$check_import_form_conflict(((vader_struct_toolchain_ast$Program_t*) l0)->f_decls, l6);
	l8 = ((vader_struct_toolchain_ast$Program_t*) l0)->f_decls;
	l17 = vader_array_length(((vader_array_t*) l8));
	l18 = INT64_C(0);
	while ((l18 < l17)) {
		vader_array_t* _a25_slotarr = ((vader_array_t*) l8);
		VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a25_slotarr, l18)
		l19 = vader_array_ref_load_box(_a25_slotarr->buf, vader_array_offset(_a25_slotarr) + (size_t) l18);
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
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
	l3 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(35u, 0u, 0u, 653u);
	l4 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 645u);
	l5 = (void*) _a2_arr;
	vader_struct_std_collections$Map__string__Any_t* _a3_obj = (vader_struct_std_collections$Map__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any_t));
	vader_obj_header_init(_a3_obj, 1004u);
	_a3_obj->f_ekeys = l3;
	_a3_obj->f_evals = l4;
	_a3_obj->f_index = l5;
	_a3_obj->f_mask = INT64_C(0);
	_a3_obj->f_grow_at = INT64_C(0);
	_a3_obj->f_size = INT64_C(0);
	_a3_obj->f_tombs = INT64_C(0);
	l3 = (void*) _a3_obj;
	vader_array_t* _a4_arr = vader_array_new(93u, 0u, 13u, 1245u);
	l4 = (void*) _a4_arr;
	vader_array_t* _a5_arr = vader_array_new(342u, 0u, 13u, 1789u);
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
	t0 = vader_array_length(((vader_array_t*) l0));
	if (t0 == INT64_C(1)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		t1 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT32_C(0));
		{ void* __vret = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) t1)->f_program)->f_decls; vader_gc_top = gc_frame.prev; return __vret; }
	}
	vader_array_t* _a1_arr = vader_array_new(481u, 0u, 13u, 2450u);
	l1 = (void*) _a1_arr;
	l2 = l0;
	l3 = vader_array_length(((vader_array_t*) l2));
	l4 = INT64_C(0);
	while ((l4 < l3)) {
		vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
		t1 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l4);
		l5 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) t1)->f_program)->f_decls;
		l6 = vader_array_length(((vader_array_t*) l5));
		l7 = INT64_C(0);
		while ((l7 < l6)) {
			vader_array_t* _a3_slotarr = ((vader_array_t*) l5);
			VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
			l8 = vader_array_ref_load_box(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l7);
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
	l3 = vader_array_length(((vader_array_t*) l2));
	l4 = INT64_C(0);
	while ((l4 < l3)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l4);
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
	vader_array_t* _a0_arr = vader_array_new(34u, 0u, 4u, 650u);
	l1 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(35u, 0u, 0u, 653u);
	l2 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 645u);
	l3 = (void*) _a2_arr;
	vader_struct_std_collections$Map__u64__Any_t* _a3_obj = (vader_struct_std_collections$Map__u64__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__u64__Any_t));
	vader_obj_header_init(_a3_obj, 1083u);
	_a3_obj->f_ekeys = l1;
	_a3_obj->f_evals = l2;
	_a3_obj->f_index = l3;
	_a3_obj->f_mask = INT64_C(0);
	_a3_obj->f_grow_at = INT64_C(0);
	_a3_obj->f_size = INT64_C(0);
	_a3_obj->f_tombs = INT64_C(0);
	l1 = (void*) _a3_obj;
	l2 = ((vader_struct_vader_front_resolver$CollectedModule_t*) l0)->f_symbols;
	l3 = ((vader_struct_std_collections$Map__string__vader_core_symbol_Symbol_t*) l2)->f_ekeys;
	l4 = ((vader_struct_std_collections$Map__string__vader_core_symbol_Symbol_t*) l2)->f_evals;
	l5 = INT64_C(0);
	l6 = ((vader_struct_std_collections$Map__string__vader_core_symbol_Symbol_t*) l2)->f_size;
	while ((l5 < l6)) {
		vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
		t0 = vader_array_box_slots(_a4_slotarr->buf)[vader_array_offset(_a4_slotarr) + (size_t) l5];
		t1 = t0.payload.s;
		vader_array_t* _a5_slotarr = ((vader_array_t*) l4);
		VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
		l2 = vader_array_ref_load_obj(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) l5);
		if (((vader_struct_vader_core_symbol$Symbol_t*) l2)->f_kind != INT32_C(0)) {
			vader_front_resolver$index_declaration(l1, l2);
		}
		l5 = (l5 + INT64_C(1));
	}
	l2 = ((vader_struct_vader_front_resolver$CollectedModule_t*) l0)->f_fn_overloads;
	l3 = ((vader_struct_std_collections$Map__string__vader_core_symbol_Symbol___t*) l2)->f_ekeys;
	l4 = ((vader_struct_std_collections$Map__string__vader_core_symbol_Symbol___t*) l2)->f_evals;
	l5 = INT64_C(0);
	l6 = ((vader_struct_std_collections$Map__string__vader_core_symbol_Symbol___t*) l2)->f_size;
	while ((l5 < l6)) {
		vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l5)
		t0 = vader_array_box_slots(_a6_slotarr->buf)[vader_array_offset(_a6_slotarr) + (size_t) l5];
		t1 = t0.payload.s;
		vader_array_t* _a7_slotarr = ((vader_array_t*) l4);
		VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l5)
		l2 = vader_array_ref_load_obj(_a7_slotarr->buf, vader_array_offset(_a7_slotarr) + (size_t) l5);
		l7 = vader_array_length(((vader_array_t*) l2));
		l8 = INT64_C(0);
		while ((l8 < l7)) {
			vader_array_t* _a8_slotarr = ((vader_array_t*) l2);
			VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
			l9 = vader_array_ref_load_obj(_a8_slotarr->buf, vader_array_offset(_a8_slotarr) + (size_t) l8);
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
	std_collections$Map$std_core$IndexSet$set_at__i32__vader_front_resolver_ConstLocal(l2, l3, (uint8_t) 1);
	{ vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_front_resolver$declare_trait_self(void* l0, void* l1) {
	void* l2 = NULL;
	void* l5 = NULL;
	void* l6 = NULL;
	vader_string_t l3 = 0;
	vader_box_t l4 = vader_box_null();
	uint64_t l7;
	int32_t l8;
	vader_box_t* gc_roots[1] = { &l4 };
	void** gc_raw_roots[5] = { &l0, &l1, &l2, &l5, &l6 };
	vader_string_t* gc_atom_roots[1] = { &l3 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope;
	l3 = ((vader_struct_toolchain_ast$TraitDecl_t*) l1)->f_name;
	l4 = vader_front_resolver$lookup(l2, l3);
	if (l4.tag == 0u) {
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	l2 = l4.payload.obj;
	if (!(((vader_struct_vader_core_symbol$Symbol_t*) l2)->f_kind != INT32_C(3))) {
		l5 = ((vader_struct_toolchain_ast$TraitDecl_t*) l1)->f_name_span;
		l5 = vader_front_resolver$mint_local(l0, (uint8_t) 9, 990u, l5);
		l6 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_idents;
		l7 = toolchain_span$Span$std_core$Hash$hash(((vader_struct_toolchain_ast$TraitDecl_t*) l1)->f_name_span);
		std_collections$Map$std_core$IndexSet$set_at__u64__Any(l6, l7, vader_ref_box(l2));
		l6 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_type_param_bounds;
		l8 = ((vader_struct_vader_core_symbol$Symbol_t*) l5)->f_id;
		l4 = vader_front_resolver$trait_self_bound(l1);
		std_collections$Map$std_core$IndexSet$set_at__i32__Any(l6, l8, l4);
		l6 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_trait_self_params;
		l8 = ((vader_struct_vader_core_symbol$Symbol_t*) l2)->f_id;
		std_collections$Map$std_core$IndexSet$set_at__i32__Any(l6, l8, vader_ref_box(l5));
		{ vader_box_t __vret = vader_ref_box(l5); vader_gc_top = gc_frame.prev; return __vret; }
	}
	{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
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
	std_collections$Map$std_core$IndexSet$set_at__i32__Any(l4, l5, l3);
	{ void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$declared_by(void* l0, void* l1) {
	void* l2 = NULL;
	void* l6 = NULL;
	void* l7 = NULL;
	bool l3;
	int64_t l4, l5;
	void* t0 = NULL;
	bool t1;
	void** gc_raw_roots[6] = { &l0, &l1, &l2, &l6, &l7, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l2 = l1;
	l3 = false;
	l4 = vader_array_length(((vader_array_t*) l2));
	l5 = INT64_C(0);
	{
		while ((l5 < l4)) {
			vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
			VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
			t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
			t1 = __lambda_vader_front_resolver_14(t0);
			if (t1) {
				l3 = true;
				goto end_9;
			}
			l5 = (l5 + INT64_C(1));
		}
		l3 = false;
	} end_9: ;
	if (!(l3)) {
		vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 642u);
		l2 = (void*) _a1_arr;
		vader_array_t* _a2_arr = vader_array_new(54u, 0u, 13u, 1110u);
		l6 = (void*) _a2_arr;
		vader_array_t* _a3_arr = vader_array_new(29u, 0u, 7u, 645u);
		l7 = (void*) _a3_arr;
		vader_struct_std_collections$Map__string__std_collections_Set_string__t* _a4_obj = (vader_struct_std_collections$Map__string__std_collections_Set_string__t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__std_collections_Set_string__t));
		vader_obj_header_init(_a4_obj, 1027u);
		_a4_obj->f_ekeys = l2;
		_a4_obj->f_evals = l6;
		_a4_obj->f_index = l7;
		_a4_obj->f_mask = INT64_C(0);
		_a4_obj->f_grow_at = INT64_C(0);
		_a4_obj->f_size = INT64_C(0);
		_a4_obj->f_tombs = INT64_C(0);
		t0 = (void*) _a4_obj;
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	t0 = vader_front_resolver$declared_decorators(l0);
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$declared_decorators(void* l0) {
	void* l1 = NULL;
	void* l2 = NULL;
	void* l3 = NULL;
	void* l6 = NULL;
	void* l9 = NULL;
	void* l10 = NULL;
	void* l11 = NULL;
	void* l12 = NULL;
	void* l14 = NULL;
	void* l17 = NULL;
	void* l21 = NULL;
	int64_t l4, l5, l15, l16, l18, l19;
	vader_string_t l7 = 0;
	vader_string_t l13 = 0;
	vader_string_t l22 = 0;
	vader_box_t l8 = vader_box_null(), l20 = vader_box_null();
	void* t0 = NULL;
	bool t1;
	vader_box_t* gc_roots[2] = { &l8, &l20 };
	void** gc_raw_roots[13] = {
		&l0, &l1, &l2, &l3, &l6, &l9, &l10, &l11, &l12, &l14, &l17, &l21, &t0,
	};
	vader_string_t* gc_atom_roots[3] = { &l7, &l13, &l22 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 13u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
	l1 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(54u, 0u, 13u, 1110u);
	l2 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 645u);
	l3 = (void*) _a2_arr;
	vader_struct_std_collections$Map__string__std_collections_Set_string__t* _a3_obj = (vader_struct_std_collections$Map__string__std_collections_Set_string__t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__std_collections_Set_string__t));
	vader_obj_header_init(_a3_obj, 1027u);
	_a3_obj->f_ekeys = l1;
	_a3_obj->f_evals = l2;
	_a3_obj->f_index = l3;
	_a3_obj->f_mask = INT64_C(0);
	_a3_obj->f_grow_at = INT64_C(0);
	_a3_obj->f_size = INT64_C(0);
	_a3_obj->f_tombs = INT64_C(0);
	l1 = (void*) _a3_obj;
	l2 = l0;
	l4 = vader_array_length(((vader_array_t*) l2));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
		l3 = vader_array_ref_load_obj(_a4_slotarr->buf, vader_array_offset(_a4_slotarr) + (size_t) l5);
		l7 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) ((vader_struct_vader_front_resolver$DeferredModule_t*) l3)->f_found)->f_name;
		l8 = std_collections$Map$std_core$Index$at__string__std_collections_Set_string_(l1, l7);
		if (l8.tag == 0u) {
			vader_array_t* _a5_arr = vader_array_new(28u, 0u, 0u, 642u);
			l9 = (void*) _a5_arr;
			vader_array_t* _a6_arr = vader_array_new(26u, 0u, 12u, 640u);
			l10 = (void*) _a6_arr;
			vader_array_t* _a7_arr = vader_array_new(29u, 0u, 7u, 645u);
			l11 = (void*) _a7_arr;
			vader_struct_std_collections$Map__string__bool_t* _a8_obj = (vader_struct_std_collections$Map__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__bool_t));
			vader_obj_header_init(_a8_obj, 1010u);
			_a8_obj->f_ekeys = l9;
			_a8_obj->f_evals = l10;
			_a8_obj->f_index = l11;
			_a8_obj->f_mask = INT64_C(0);
			_a8_obj->f_grow_at = INT64_C(0);
			_a8_obj->f_size = INT64_C(0);
			_a8_obj->f_tombs = INT64_C(0);
			t0 = (void*) _a8_obj;
			vader_struct_std_collections$Set__string_t* _a9_obj = (vader_struct_std_collections$Set__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__string_t));
			vader_obj_header_init(_a9_obj, 1110u);
			_a9_obj->f_inner = t0;
			l12 = (void*) _a9_obj;
			l13 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) ((vader_struct_vader_front_resolver$DeferredModule_t*) l3)->f_found)->f_name;
			std_collections$Map$std_core$IndexSet$set_at__string__std_collections_Set_string_(l1, l13, l12);
			l6 = l12;
		} else {
			l6 = l8.payload.obj;
		}
		l14 = ((vader_struct_vader_front_resolver$DeferredModule_t*) l3)->f_sources;
		l15 = vader_array_length(((vader_array_t*) l14));
		l16 = INT64_C(0);
		while ((l16 < l15)) {
			vader_array_t* _a10_slotarr = ((vader_array_t*) l14);
			VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
			t0 = vader_array_ref_load_obj(_a10_slotarr->buf, vader_array_offset(_a10_slotarr) + (size_t) l16);
			l17 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) t0)->f_program)->f_decls;
			l18 = vader_array_length(((vader_array_t*) l17));
			l19 = INT64_C(0);
			while ((l19 < l18)) {
				vader_array_t* _a11_slotarr = ((vader_array_t*) l17);
				VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
				l20 = vader_array_ref_load_box(_a11_slotarr->buf, vader_array_offset(_a11_slotarr) + (size_t) l19);
				if (l20.tag == 1224u) {
					l21 = l20.payload.obj;
					t1 = toolchain_ast$is_decorator(l21);
					if (t1) {
						l22 = ((vader_struct_toolchain_ast$StructDecl_t*) l21)->f_name;
						std_collections$add__string(l6, l22);
					}
				}
				l19 = (l19 + INT64_C(1));
			}
			l16 = (l16 + INT64_C(1));
		}
		l5 = (l5 + INT64_C(1));
	}
	{ void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_resolver$declared_in(void* l0, vader_string_t l1, vader_string_t l2) {
	vader_box_t l3 = vader_box_null();
	void* t0 = NULL;
	bool t1;
	vader_box_t* gc_roots[1] = { &l3 };
	void** gc_raw_roots[2] = { &l0, &t0 };
	vader_string_t* gc_atom_roots[2] = { &l1, &l2 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l3 = std_collections$Map$std_core$Index$at__string__std_collections_Set_string_(l0, l1);
	if (l3.tag == 0u) {
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	t0 = l3.payload.obj;
	t1 = std_collections$Set$std_core$Contains$contains__string(t0, l2);
	if (!(t1)) {
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	vader_struct_toolchain_stage$DecoratorOrigin_t* _a0_obj = (vader_struct_toolchain_stage$DecoratorOrigin_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_stage$DecoratorOrigin_t));
	vader_obj_header_init(_a0_obj, 1294u);
	_a0_obj->f_module = l1;
	_a0_obj->f_name = l2;
	t0 = (void*) _a0_obj;
	{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$declared_interceptors(void* l0, void* l1) {
	void* l2 = NULL;
	void* l3 = NULL;
	void* l6 = NULL;
	void* l7 = NULL;
	void* l10 = NULL;
	void* l14 = NULL;
	void* l15 = NULL;
	void* l17 = NULL;
	void* l21 = NULL;
	void* l24 = NULL;
	int64_t l4, l5, l8, l9, l11, l12;
	vader_box_t l13 = vader_box_null(), l16 = vader_box_null(), l18 = vader_box_null();
	vader_string_t l19 = 0;
	vader_string_t l20 = 0;
	vader_string_t l22 = 0;
	vader_string_t l23 = 0;
	void* t0 = NULL;
	vader_box_t* gc_roots[3] = { &l13, &l16, &l18 };
	void** gc_raw_roots[13] = {
		&l0, &l1, &l2, &l3, &l6, &l7, &l10, &l14, &l15, &l17, &l21, &l24, &t0,
	};
	vader_string_t* gc_atom_roots[4] = { &l19, &l20, &l22, &l23 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 3u, 13u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(344u, 0u, 13u, 1791u);
	l2 = (void*) _a0_arr;
	l3 = l0;
	l4 = vader_array_length(((vader_array_t*) l3));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		l6 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l5);
		l7 = ((vader_struct_vader_front_resolver$DeferredModule_t*) l6)->f_sources;
		l8 = vader_array_length(((vader_array_t*) l7));
		l9 = INT64_C(0);
		while ((l9 < l8)) {
			vader_array_t* _a2_slotarr = ((vader_array_t*) l7);
			VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
			t0 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l9);
			l10 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) t0)->f_program)->f_decls;
			l11 = vader_array_length(((vader_array_t*) l10));
			l12 = INT64_C(0);
			while ((l12 < l11)) {
				vader_array_t* _a3_slotarr = ((vader_array_t*) l10);
				VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
				l13 = vader_array_ref_load_box(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l12);
				if (l13.tag == 1224u) {
					l14 = l13.payload.obj;
					l16 = toolchain_ast$find_compiler_decorator(((vader_struct_toolchain_ast$StructDecl_t*) l14)->f_decorators, (uint8_t) 15);
					if (l16.tag == 0u) {
						l12 = (l12 + INT64_C(1));
						continue;
					}
					l15 = l16.payload.obj;
					l18 = vader_front_resolver$around_of(((vader_struct_vader_front_resolver$DeferredModule_t*) l6)->f_sources, l14, l15, l1);
					if (l18.tag == 0u) {
						l12 = (l12 + INT64_C(1));
						continue;
					}
					l17 = l18.payload.obj;
					l19 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) ((vader_struct_vader_front_resolver$DeferredModule_t*) l6)->f_found)->f_name;
					l20 = ((vader_struct_toolchain_ast$StructDecl_t*) l14)->f_name;
					vader_struct_toolchain_stage$DecoratorOrigin_t* _a4_obj = (vader_struct_toolchain_stage$DecoratorOrigin_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_stage$DecoratorOrigin_t));
					vader_obj_header_init(_a4_obj, 1294u);
					_a4_obj->f_module = l19;
					_a4_obj->f_name = l20;
					l21 = (void*) _a4_obj;
					l22 = ((vader_struct_toolchain_ast$FnDecl_t*) ((vader_struct_vader_front_resolver$AroundFunction_t*) l17)->f_function)->f_name;
					l23 = ((vader_struct_vader_front_resolver$AroundFunction_t*) l17)->f_state;
					vader_struct_vader_front_resolver$Interceptor_t* _a5_obj = (vader_struct_vader_front_resolver$Interceptor_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$Interceptor_t));
					vader_obj_header_init(_a5_obj, 1791u);
					_a5_obj->f_origin = l21;
					_a5_obj->f_around = l22;
					_a5_obj->f_state = l23;
					l24 = (void*) _a5_obj;
					vader_array_push_ref((vader_array_t*) l2, l24);
				}
				l12 = (l12 + INT64_C(1));
			}
			l9 = (l9 + INT64_C(1));
		}
		l5 = (l5 + INT64_C(1));
	}
	{ void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_resolver$declared_name(vader_box_t l0) {
	vader_box_t l1;
	void* t0;
	vader_string_t t1;
	if (l0.tag == 1181u) {
		t0 = l0.payload.obj;
		t1 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_name;
		l1 = vader_box_string(642u, t1);
		return l1;
	}
	if (l0.tag == 1224u) {
		t0 = l0.payload.obj;
		t1 = ((vader_struct_toolchain_ast$StructDecl_t*) t0)->f_name;
		l1 = vader_box_string(642u, t1);
	} else if (l0.tag == 1172u) {
		t0 = l0.payload.obj;
		t1 = ((vader_struct_toolchain_ast$EnumDecl_t*) t0)->f_name;
		l1 = vader_box_string(642u, t1);
	} else if (l0.tag == 1232u) {
		t0 = l0.payload.obj;
		t1 = ((vader_struct_toolchain_ast$TraitDecl_t*) t0)->f_name;
		l1 = vader_box_string(642u, t1);
	} else if (l0.tag == 1234u) {
		t0 = l0.payload.obj;
		t1 = ((vader_struct_toolchain_ast$TypeAliasDecl_t*) t0)->f_name;
		l1 = vader_box_string(642u, t1);
	} else if (l0.tag == 1157u) {
		t0 = l0.payload.obj;
		t1 = ((vader_struct_toolchain_ast$ConstDecl_t*) t0)->f_name;
		l1 = vader_box_string(642u, t1);
	} else {
		if (!((l0.tag == 1147u || l0.tag == 1190u || l0.tag == 1191u))) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		l1 = vader_box_obj(0u, NULL);
	}
	return l1;
}

static vader_box_t vader_front_resolver$declared_name_through(vader_box_t l0, vader_string_t l1) {
	vader_box_t l2 = vader_box_null();
	void* l3 = NULL;
	void* l4 = NULL;
	void* l7 = NULL;
	int64_t l5, l6;
	bool l8;
	void* t0 = NULL;
	bool t1;
	vader_string_t t2 = 0;
	vader_box_t* gc_roots[2] = { &l0, &l2 };
	void** gc_raw_roots[4] = { &l3, &l4, &l7, &t0 };
	vader_string_t* gc_atom_roots[2] = { &l1, &t2 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	if (l0.tag == 1239u) {
		{ vader_box_t __vret = vader_box_string(642u, l1); vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (!(l0.tag == 1166u)) {
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	t0 = l0.payload.obj;
	l3 = ((vader_struct_toolchain_ast$DestructureImport_t*) t0)->f_names;
	vader_struct___lambda_env_vader_front_resolver_33_t* _a0_obj = (vader_struct___lambda_env_vader_front_resolver_33_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_front_resolver_33_t));
	vader_obj_header_init(_a0_obj, 808u);
	_a0_obj->f_cap_0 = l1;
	l4 = (void*) _a0_obj;
	l2 = vader_box_obj(0u, NULL);
	l5 = vader_array_length(((vader_array_t*) l3));
	l6 = INT64_C(0);
	{
		while ((l6 < l5)) {
			vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
			VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
			l7 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l6);
			t1 = __lambda_vader_front_resolver_32(l4, l7);
			if (t1) {
				l2 = vader_ref_box(l7);
				goto end_27;
			}
			l6 = (l6 + INT64_C(1));
		}
		l2 = vader_box_obj(0u, NULL);
	} end_27: ;
	if (!(l2.tag == 0u)) {
		t0 = l2.payload.obj;
		t2 = ((vader_struct_toolchain_ast$ImportName_t*) t0)->f_name;
		{ vader_box_t __vret = vader_box_string(642u, t2); vader_gc_top = gc_frame.prev; return __vret; }
	}
	t0 = l0.payload.obj;
	l3 = ((vader_struct_toolchain_ast$DestructureImport_t*) t0)->f_names;
	vader_struct___lambda_env_vader_front_resolver_35_t* _a2_obj = (vader_struct___lambda_env_vader_front_resolver_35_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_front_resolver_35_t));
	vader_obj_header_init(_a2_obj, 809u);
	_a2_obj->f_cap_0 = l1;
	l4 = (void*) _a2_obj;
	l8 = false;
	l5 = vader_array_length(((vader_array_t*) l3));
	l6 = INT64_C(0);
	{
		while ((l6 < l5)) {
			vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
			VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
			l7 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l6);
			t1 = __lambda_vader_front_resolver_34(l4, l7);
			if (t1) {
				l8 = true;
				goto end_80;
			}
			l6 = (l6 + INT64_C(1));
		}
		l8 = false;
	} end_80: ;
	if (!(l8)) {
		{ vader_box_t __vret = vader_box_string(642u, l1); vader_gc_top = gc_frame.prev; return __vret; }
	}
	{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
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
	void* l0 = NULL;
	void* l1 = NULL;
	int32_t t0;
	void* t1 = NULL;
	vader_box_t t2 = vader_box_null();
	bool t3;
	vader_box_t* gc_roots[1] = { &t2 };
	void** gc_raw_roots[3] = { &l0, &l1, &t1 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	t0 = vader_global$vader_front_resolver$declared_roots$state;
	if (t0 == INT32_C(2)) {
		t1 = vader_global$vader_front_resolver$declared_roots$instance;
		{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	std_runtime_scheduler$monitor_enter_to_publish();
	t2 = vader_global$vader_front_resolver$declared_roots$gate;
	l0 = std_runtime_scheduler$gate_or_new(t2);
	vader_global$vader_front_resolver$declared_roots$gate = vader_ref_box(l0);
	l1 = (void*) &vader_fn_static_vader_front_resolver$declared_roots$keep;
	t3 = std_runtime_scheduler$run_gated(l0, l1);
	if (!(t3)) {
		vader_unreachable("singleton `declared_roots` called while it initialises");
	}
	t1 = vader_global$vader_front_resolver$declared_roots$instance;
	{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

void vader_front_resolver$declared_roots$keep(void) {
	int32_t t0;
	void* t1 = NULL;
	void** gc_raw_roots[1] = { &t1 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	t0 = vader_global$vader_front_resolver$declared_roots$state;
	if (!(t0 == INT32_C(2))) {
		t1 = vader_front_resolver$declared_roots$singleton();
		vader_global$vader_front_resolver$declared_roots$instance = t1;
		vader_global$vader_front_resolver$declared_roots$state = INT32_C(2);
		{ vader_gc_top = gc_frame.prev; return; }
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static void* vader_front_resolver$declared_roots$singleton(void) {
	void* l0 = NULL;
	void* l1 = NULL;
	void* l2 = NULL;
	void* t0 = NULL;
	void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
	l0 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(3u, 0u, 13u, 28u);
	l1 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 645u);
	l2 = (void*) _a2_arr;
	vader_struct_std_collections$Map__string__string___t* _a3_obj = (vader_struct_std_collections$Map__string__string___t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__string___t));
	vader_obj_header_init(_a3_obj, 1029u);
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

static bool vader_front_resolver$declares_type(vader_box_t l0) {
	bool l1;
	if (l0.tag == 1224u) {
		l1 = true;
	} else {
		l1 = l0.tag == 1172u;
	}
	if (l1) {
		return true;
	}
	return l0.tag == 1234u;
}

static int64_t vader_front_resolver$declaring_id(void* l0) {
	void* l1;
	vader_box_t l2;
	int64_t t0;
	l2 = ((vader_struct_vader_front_resolver$LateFn_t*) l0)->f_owner;
	if (l2.tag == 0u) {
		t0 = ((vader_struct_toolchain_ast$FnDecl_t*) ((vader_struct_vader_front_resolver$LateFn_t*) l0)->f_decl)->f_id;
		return t0;
	}
	l1 = l2.payload.obj;
	t0 = ((vader_struct_toolchain_ast$ImplDecl_t*) l1)->f_id;
	return t0;
}

void* vader_front_resolver$decorators_above_module(void* l0) {
	void* l1 = NULL;
	void* l2 = NULL;
	void* l5 = NULL;
	void* l8 = NULL;
	int64_t l3, l4, l6, l7;
	void* t0 = NULL;
	void** gc_raw_roots[6] = { &l0, &l1, &l2, &l5, &l8, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l1 = l0;
	vader_array_t* _a0_arr = vader_array_new(67u, 0u, 13u, 1159u);
	l2 = (void*) _a0_arr;
	l3 = vader_array_length(((vader_array_t*) l1));
	l4 = INT64_C(0);
	while ((l4 < l3)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		t0 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l4);
		l5 = __lambda_vader_front_resolver_21(t0);
		l6 = vader_array_length(((vader_array_t*) l5));
		l7 = INT64_C(0);
		while ((l7 < l6)) {
			vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
			VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
			l8 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l7);
			vader_array_push_ref((vader_array_t*) l2, l8);
			l7 = (l7 + INT64_C(1));
		}
		l4 = (l4 + INT64_C(1));
	}
	{ void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_resolver$dependency_of(void* l0, void* l1, void* l2) {
	void* l3 = NULL;
	void* l6 = NULL;
	vader_string_t l4 = 0;
	int64_t l5, l7;
	int64_t t0;
	vader_box_t t1 = vader_box_null();
	void* t2 = NULL;
	vader_box_t* gc_roots[1] = { &t1 };
	void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l6, &t2 };
	vader_string_t* gc_atom_roots[1] = { &l4 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l3 = vader_front_resolver$package_folders(l1, l2);
	t0 = vader_array_length(((vader_array_t*) l3));
	if (!(t0 != INT64_C(1))) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		l6 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT32_C(0));
		t1 = vader_front_resolver$package_in(l0, l1, l6);
		{ vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l4 = vader_core_wit$wit_package_text(l2);
	l5 = (int64_t) vader_string_byte_len(l4);
	l6 = (void*) vader_buffer_new((size_t) (INT64_C(51) + l5));
	l5 = INT64_C(0);
	l5 = std_core$write_string_at(l6, l5, 3050u);
	l5 = std_core$write_string_at(l6, l5, l4);
	l5 = std_core$write_string_at(l6, l5, 1466u);
	l7 = vader_array_length(((vader_array_t*) l3));
	l5 = std_core$write_int(l6, l5, l7);
	l5 = std_core$write_string_at(l6, l5, 160u);
	l4 = std_core$finish_buffer(l6, l5);
	vader_struct_vader_core_wit$WitSpan_t* _a1_obj = (vader_struct_vader_core_wit$WitSpan_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitSpan_t));
	vader_obj_header_init(_a1_obj, 1564u);
	_a1_obj->f_file = 0u;
	_a1_obj->f_line = INT32_C(1);
	_a1_obj->f_column = INT32_C(1);
	l3 = (void*) _a1_obj;
	vader_struct_vader_core_wit$WitError_t* _a2_obj = (vader_struct_vader_core_wit$WitError_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitError_t));
	vader_obj_header_init(_a2_obj, 1533u);
	_a2_obj->f_message = l4;
	_a2_obj->f_span = l3;
	t2 = (void*) _a2_obj;
	{ vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
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
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
	l3 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(29u, 0u, 7u, 645u);
	l4 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 645u);
	l5 = (void*) _a2_arr;
	vader_struct_std_collections$Map__string__i32_t* _a3_obj = (vader_struct_std_collections$Map__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__i32_t));
	vader_obj_header_init(_a3_obj, 1011u);
	_a3_obj->f_ekeys = l3;
	_a3_obj->f_evals = l4;
	_a3_obj->f_index = l5;
	_a3_obj->f_mask = INT64_C(0);
	_a3_obj->f_grow_at = INT64_C(0);
	_a3_obj->f_size = INT64_C(0);
	_a3_obj->f_tombs = INT64_C(0);
	l3 = (void*) _a3_obj;
	l4 = l0;
	l5 = ((vader_struct_std_collections$Map__string__vader_front_resolver_LoadedModule_t*) l4)->f_ekeys;
	l6 = ((vader_struct_std_collections$Map__string__vader_front_resolver_LoadedModule_t*) l4)->f_evals;
	l7 = INT64_C(0);
	l8 = ((vader_struct_std_collections$Map__string__vader_front_resolver_LoadedModule_t*) l4)->f_size;
	while ((l7 < l8)) {
		vader_array_t* _a4_slotarr = ((vader_array_t*) l5);
		VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
		t0 = vader_array_box_slots(_a4_slotarr->buf)[vader_array_offset(_a4_slotarr) + (size_t) l7];
		l9 = t0.payload.s;
		vader_array_t* _a5_slotarr = ((vader_array_t*) l6);
		VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l7)
		t1 = vader_array_ref_load_obj(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) l7);
		l10 = l9;
		t0 = std_collections$Map$std_core$Index$at__string__i32(l3, l10);
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
	t0 = std_string$starts_with(l0, 497u);
	if (t0) {
		l6 = true;
	} else {
		l6 = std_string$starts_with(l0, 494u);
	}
	if (l6) {
		l7 = concat_3(1307u, l0, 1307u);
		l8 = toolchain_diagnostics$resolver_error((uint8_t) 18, l1, l7);
		vader_array_push_ref((vader_array_t*) l5, l8);
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	if (l0 == l2) {
		l7 = concat_3(1307u, l0, 1307u);
		l8 = toolchain_diagnostics$resolver_error((uint8_t) 17, l1, l7);
		vader_array_push_ref((vader_array_t*) l5, l8);
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	if (l0 == 3209u) {
		if (l2 != 3209u) {
			l8 = toolchain_diagnostics$resolver_error((uint8_t) 20, l1, 0u);
			vader_array_push_ref((vader_array_t*) l5, l8);
			{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
		}
	}
	t0 = std_string$starts_with(l0, 3529u);
	if (t0) {
		t0 = std_string$starts_with(l2, 3529u);
		if (!(t0)) {
			t1 = vader_front_resolver$importer_origin(l3, l2);
			if (t1 == INT32_C(1)) {
				l7 = concat_5(1307u, l2, 1517u, l0, 1307u);
				l8 = toolchain_diagnostics$resolver_error((uint8_t) 25, l1, l7);
				vader_array_push_ref((vader_array_t*) l5, l8);
				{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
			}
		}
	}
	t0 = std_collections$is_empty__string__Any(l3);
	if (t0) {
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	l9 = std_collections$Map$std_core$Index$at__string__Any(l3, l0);
	if (l9.tag == 1777u) {
		t2 = l9.payload.obj;
		t3 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) t2)->f_folder;
		{ vader_box_t __vret = vader_box_string(642u, t3); vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (!(l9.tag == 0u)) {
		vader_unreachable("non-exhaustive match (T3013 should have caught this)");
	}
	l9 = vader_front_resolver$misplaced_module_at(l0, l4);
	if (l9.tag == 0u) {
		l7 = concat_3(1307u, l0, 1307u);
		l8 = toolchain_diagnostics$resolver_error((uint8_t) 0, l1, l7);
		vader_array_push_ref((vader_array_t*) l5, l8);
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	l7 = l9.payload.s;
	l7 = concat_5(1307u, l0, 1680u, l7, 325u);
	l8 = toolchain_diagnostics$resolver_error((uint8_t) 0, l1, l7);
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
	void* l5 = NULL;
	void* l11 = NULL;
	int64_t l6, l7, l8, l9;
	vader_box_t l10 = vader_box_null();
	void* t0 = NULL;
	vader_box_t t1 = vader_box_null();
	bool t2;
	vader_box_t* gc_roots[3] = { &l1, &l10, &t1 };
	void** gc_raw_roots[7] = { &l0, &l2, &l3, &l4, &l5, &l11, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(73u, 0u, 13u, 1181u);
	l2 = (void*) _a0_arr;
	if (l1.tag == 0u) {
		{ void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l3 = l1.payload.obj;
	vader_array_t* _a1_arr = vader_array_new(93u, 0u, 13u, 1245u);
	l4 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(355u, 0u, 13u, 1820u);
	l5 = (void*) _a2_arr;
	l3 = vader_front_resolver$select_target_bodies(l0, vader_ref_box(l3), l4, l5);
	l4 = l0;
	l6 = vader_array_length(((vader_array_t*) l4));
	l7 = INT64_C(0);
	while ((l7 < l6)) {
		vader_array_t* _a3_slotarr = ((vader_array_t*) l4);
		VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
		t0 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l7);
		l5 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) t0)->f_program)->f_decls;
		l8 = vader_array_length(((vader_array_t*) l5));
		l9 = INT64_C(0);
		while ((l9 < l8)) {
			vader_array_t* _a4_slotarr = ((vader_array_t*) l5);
			VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
			l10 = vader_array_ref_load_box(_a4_slotarr->buf, vader_array_offset(_a4_slotarr) + (size_t) l9);
			if (l10.tag == 1181u) {
				l11 = l10.payload.obj;
				t1 = vader_front_resolver$target_selectors(((vader_struct_toolchain_ast$FnDecl_t*) l11)->f_decorators);
				if (t1.tag == 0u) {
					l9 = (l9 + INT64_C(1));
					continue;
				}
				t2 = vader_front_resolver$body_survives(l11, l3);
				if (t2) {
					l9 = (l9 + INT64_C(1));
					continue;
				}
				vader_array_push_ref((vader_array_t*) l2, l11);
			}
			l9 = (l9 + INT64_C(1));
		}
		l7 = (l7 + INT64_C(1));
	}
	{ void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_front_resolver$drain_load_queue(void* l0, void* l1) {
	void* l2 = NULL;
	void* l3 = NULL;
	void* l4 = NULL;
	void* l6 = NULL;
	void* l7 = NULL;
	void* l10 = NULL;
	void* l11 = NULL;
	void* l12 = NULL;
	void* l13 = NULL;
	void* l16 = NULL;
	void* l19 = NULL;
	void* l20 = NULL;
	void* l21 = NULL;
	bool l5;
	int64_t l8, l9, l17, l18;
	vader_string_t l14 = 0;
	vader_string_t l22 = 0;
	vader_box_t l15 = vader_box_null(), l23 = vader_box_null();
	int64_t t0;
	vader_box_t* gc_roots[2] = { &l15, &l23 };
	void** gc_raw_roots[15] = {
		&l0, &l1, &l2, &l3, &l4, &l6, &l7, &l10, &l11, &l12, &l13, &l16, &l19, &l20, &l21,
	};
	vader_string_t* gc_atom_roots[2] = { &l14, &l22 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 15u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = vader_host_std_core$Runtime$deep_copy__std_collections_Map_string__string_(((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_overlay);
	l3 = vader_front_resolver$unloaded(l0, l1);
	for (;;) {
		t0 = vader_array_length(((vader_array_t*) l3));
		if ((t0 > INT64_C(0))) {
			l4 = vader_front_resolver$with_written_texts(l2, l3);
			l5 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_keep_docs;
			l6 = vader_front_resolver$parse_level(l3, l4, l5);
			vader_array_t* _a0_arr = vader_array_new(336u, 0u, 13u, 1777u);
			l7 = (void*) _a0_arr;
			l8 = INT64_C(0);
			l9 = vader_array_length(((vader_array_t*) l3));
			while ((l8 < l9)) {
				vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
				VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
				VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l8)
				l10 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l8);
				vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
				VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
				VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l8)
				l11 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l8);
				vader_front_resolver$ingest_module(l0, l10, l11);
				l13 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_modules;
				l14 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) l10)->f_folder;
				l15 = std_collections$Map$std_core$Index$at__string__Any(l13, l14);
				if (l15.tag == 0u) {
					l8 = (l8 + INT64_C(1));
					continue;
				}
				l12 = l15.payload.obj;
				l16 = ((vader_struct_vader_front_resolver$CollectedModule_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l12)->f_collected)->f_import_paths;
				l17 = vader_array_length(((vader_array_t*) l16));
				l18 = INT64_C(0);
				while ((l18 < l17)) {
					vader_array_t* _a3_slotarr = ((vader_array_t*) l16);
					VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
					l19 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l18);
					l21 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_index;
					l22 = ((vader_struct_vader_front_resolver$ImportPath_t*) l19)->f_path;
					l23 = std_collections$Map$std_core$Index$at__string__Any(l21, l22);
					if (l23.tag == 0u) {
						l18 = (l18 + INT64_C(1));
						continue;
					}
					l20 = l23.payload.obj;
					vader_array_push_ref((vader_array_t*) l7, l20);
					l18 = (l18 + INT64_C(1));
				}
				l8 = (l8 + INT64_C(1));
			}
			l3 = vader_front_resolver$unloaded(l0, l7);
			continue;
		}
		break;
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static void* vader_front_resolver$driver_names(void* l0, vader_box_t l1) {
	void* l2 = NULL;
	void* l3 = NULL;
	void* l4 = NULL;
	void* l5 = NULL;
	vader_string_t l6 = 0;
	vader_string_t l9 = 0;
	vader_string_t l10 = 0;
	vader_string_t l11 = 0;
	int64_t l7, l8;
	vader_string_t t0 = 0;
	vader_box_t t1 = vader_box_null();
	bool t2;
	vader_box_t* gc_roots[2] = { &l1, &t1 };
	void** gc_raw_roots[5] = { &l0, &l2, &l3, &l4, &l5 };
	vader_string_t* gc_atom_roots[5] = { &l6, &l9, &l10, &l11, &t0 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
	l2 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 642u);
	l3 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 645u);
	l4 = (void*) _a2_arr;
	vader_struct_std_collections$Map__string__string_t* _a3_obj = (vader_struct_std_collections$Map__string__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__string_t));
	vader_obj_header_init(_a3_obj, 1028u);
	_a3_obj->f_ekeys = l2;
	_a3_obj->f_evals = l3;
	_a3_obj->f_index = l4;
	_a3_obj->f_mask = INT64_C(0);
	_a3_obj->f_grow_at = INT64_C(0);
	_a3_obj->f_size = INT64_C(0);
	_a3_obj->f_tombs = INT64_C(0);
	l2 = (void*) _a3_obj;
	vader_array_t* _a4_arr = vader_array_new(28u, 0u, 0u, 642u);
	l3 = (void*) _a4_arr;
	vader_array_t* _a5_arr = vader_array_new(28u, 0u, 0u, 642u);
	l4 = (void*) _a5_arr;
	vader_array_t* _a6_arr = vader_array_new(29u, 0u, 7u, 645u);
	l5 = (void*) _a6_arr;
	vader_struct_std_collections$Map__string__string_t* _a7_obj = (vader_struct_std_collections$Map__string__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__string_t));
	vader_obj_header_init(_a7_obj, 1028u);
	_a7_obj->f_ekeys = l3;
	_a7_obj->f_evals = l4;
	_a7_obj->f_index = l5;
	_a7_obj->f_mask = INT64_C(0);
	_a7_obj->f_grow_at = INT64_C(0);
	_a7_obj->f_size = INT64_C(0);
	_a7_obj->f_tombs = INT64_C(0);
	l3 = (void*) _a7_obj;
	vader_struct_vader_front_resolver$DriverNames_t* _a8_obj = (vader_struct_vader_front_resolver$DriverNames_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$DriverNames_t));
	vader_obj_header_init(_a8_obj, 1779u);
	_a8_obj->f_sent = l2;
	_a8_obj->f_read = l3;
	l2 = (void*) _a8_obj;
	t0 = vader_front_resolver$records_folder(l1);
	l6 = vader_front_resolver$normalized_path(t0);
	l3 = l0;
	l7 = vader_array_length(((vader_array_t*) l3));
	l8 = INT64_C(0);
	while ((l8 < l7)) {
		vader_array_t* _a9_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l8)
		t1 = vader_array_box_slots(_a9_slotarr->buf)[vader_array_offset(_a9_slotarr) + (size_t) l8];
		l9 = t1.payload.s;
		t2 = vader_front_resolver$is_generated_file(l9);
		if (t2) {
			l8 = (l8 + INT64_C(1));
			continue;
		}
		l10 = vader_front_resolver$normalized_path(l9);
		l11 = toolchain_diagnostics$relative_to(l10, l6);
		if (l11 != l10) {
			if (l11 != l9) {
				std_collections$Map$std_core$IndexSet$set_at__string__string(((vader_struct_vader_front_resolver$DriverNames_t*) l2)->f_sent, l9, l11);
				std_collections$Map$std_core$IndexSet$set_at__string__string(((vader_struct_vader_front_resolver$DriverNames_t*) l2)->f_read, l11, l9);
			}
		}
		l8 = (l8 + INT64_C(1));
	}
	{ void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$driver_request(void* l0) {
	void* l1 = NULL;
	void* l2 = NULL;
	void* l4 = NULL;
	void* l5 = NULL;
	vader_box_t l3 = vader_box_null(), l8 = vader_box_null(), l9 = vader_box_null();
	int64_t l6, l7;
	vader_string_t l10 = 0;
	bool t0;
	void* t1 = NULL;
	vader_box_t* gc_roots[3] = { &l3, &l8, &l9 };
	void** gc_raw_roots[6] = { &l0, &l1, &l2, &l4, &l5, &t1 };
	vader_string_t* gc_atom_roots[1] = { &l10 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 3u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l1 = l0;
	l2 = ((vader_struct_toolchain_stage$BodyRequest_t*) l1)->f_decl;
	l3 = ((vader_struct_toolchain_stage$BodyRequest_t*) l1)->f_owner;
	l4 = ((vader_struct_toolchain_stage$BodyRequest_t*) l0)->f_declarations;
	vader_array_t* _a0_arr = vader_array_new(481u, 0u, 13u, 2450u);
	l5 = (void*) _a0_arr;
	l6 = vader_array_length(((vader_array_t*) l4));
	l7 = INT64_C(0);
	while ((l7 < l6)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		l8 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l7);
		t0 = toolchain_protocol$crosses(l8);
		if (t0) {
			l9 = l8;
			vader_array_push_ref((vader_array_t*) l5, l9.payload.obj);
		}
		l7 = (l7 + INT64_C(1));
	}
	l10 = ((vader_struct_toolchain_stage$BodyRequest_t*) l1)->f_module_name;
	vader_struct_toolchain_stage$BodyRequest_t* _a2_obj = (vader_struct_toolchain_stage$BodyRequest_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_stage$BodyRequest_t));
	vader_obj_header_init(_a2_obj, 1291u);
	_a2_obj->f_decl = l2;
	_a2_obj->f_owner = l3;
	_a2_obj->f_declarations = l5;
	_a2_obj->f_module_name = l10;
	t1 = (void*) _a2_obj;
	{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$driver_sources(void* l0) {
	void* l1 = NULL;
	void* l2 = NULL;
	void* l5 = NULL;
	void* l6 = NULL;
	void* l8 = NULL;
	void* l11 = NULL;
	void* l12 = NULL;
	void* l17 = NULL;
	int64_t l3, l4, l9, l13, l14;
	vader_string_t l7 = 0;
	vader_box_t l10 = vader_box_null(), l15 = vader_box_null(), l16 = vader_box_null();
	int64_t t0;
	bool t1;
	vader_string_t t2 = 0;
	void* t3 = NULL;
	vader_box_t* gc_roots[3] = { &l10, &l15, &l16 };
	void** gc_raw_roots[10] = { &l0, &l1, &l2, &l5, &l6, &l8, &l11, &l12, &l17, &t3 };
	vader_string_t* gc_atom_roots[2] = { &l7, &t2 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 3u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	t0 = vader_array_length(((vader_array_t*) ((vader_struct_toolchain_stage$Sources_t*) l0)->f_files));
	vader_array_t* _a0_arr = vader_array_reserve(83u, (int64_t) t0, 13u, 1213u);
	l1 = (void*) _a0_arr;
	l2 = ((vader_struct_toolchain_stage$Sources_t*) l0)->f_files;
	l3 = vader_array_length(((vader_array_t*) l2));
	l4 = INT64_C(0);
	while ((l4 < l3)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		l5 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l4);
		l6 = l5;
		l7 = ((vader_struct_toolchain_ast$Program_t*) l6)->f_file;
		l8 = ((vader_struct_toolchain_ast$Program_t*) l6)->f_span;
		l9 = ((vader_struct_toolchain_ast$Program_t*) l6)->f_id;
		l10 = ((vader_struct_toolchain_ast$Program_t*) l6)->f_module;
		l11 = ((vader_struct_toolchain_ast$Program_t*) l5)->f_decls;
		vader_array_t* _a2_arr = vader_array_new(481u, 0u, 13u, 2450u);
		l12 = (void*) _a2_arr;
		l13 = vader_array_length(((vader_array_t*) l11));
		l14 = INT64_C(0);
		while ((l14 < l13)) {
			vader_array_t* _a3_slotarr = ((vader_array_t*) l11);
			VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
			l15 = vader_array_ref_load_box(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l14);
			t1 = toolchain_protocol$crosses(l15);
			if (t1) {
				l16 = l15;
				vader_array_push_ref((vader_array_t*) l12, l16.payload.obj);
			}
			l14 = (l14 + INT64_C(1));
		}
		vader_struct_toolchain_ast$Program_t* _a4_obj = (vader_struct_toolchain_ast$Program_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$Program_t));
		vader_obj_header_init(_a4_obj, 1213u);
		_a4_obj->f_file = l7;
		_a4_obj->f_span = l8;
		_a4_obj->f_id = l9;
		_a4_obj->f_module = l10;
		_a4_obj->f_decls = l12;
		l17 = (void*) _a4_obj;
		vader_array_push_ref((vader_array_t*) l1, l17);
		l4 = (l4 + INT64_C(1));
	}
	t2 = ((vader_struct_toolchain_stage$Sources_t*) l0)->f_module_name;
	vader_struct_toolchain_stage$Sources_t* _a5_obj = (vader_struct_toolchain_stage$Sources_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_stage$Sources_t));
	vader_obj_header_init(_a5_obj, 1302u);
	_a5_obj->f_module_name = t2;
	_a5_obj->f_files = l1;
	t3 = (void*) _a5_obj;
	{ void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$driver_stages(void) {
	void* l0 = NULL;
	void* l1 = NULL;
	int32_t t0;
	void* t1 = NULL;
	vader_box_t t2 = vader_box_null();
	bool t3;
	vader_box_t* gc_roots[1] = { &t2 };
	void** gc_raw_roots[3] = { &l0, &l1, &t1 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	t0 = vader_global$vader_front_resolver$driver_stages$state;
	if (t0 == INT32_C(2)) {
		t1 = vader_global$vader_front_resolver$driver_stages$instance;
		{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	std_runtime_scheduler$monitor_enter_to_publish();
	t2 = vader_global$vader_front_resolver$driver_stages$gate;
	l0 = std_runtime_scheduler$gate_or_new(t2);
	vader_global$vader_front_resolver$driver_stages$gate = vader_ref_box(l0);
	l1 = (void*) &vader_fn_static_vader_front_resolver$driver_stages$keep;
	t3 = std_runtime_scheduler$run_gated(l0, l1);
	if (!(t3)) {
		vader_unreachable("singleton `driver_stages` called while it initialises");
	}
	t1 = vader_global$vader_front_resolver$driver_stages$instance;
	{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

void vader_front_resolver$driver_stages$keep(void) {
	int32_t t0;
	void* t1 = NULL;
	void** gc_raw_roots[1] = { &t1 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	t0 = vader_global$vader_front_resolver$driver_stages$state;
	if (!(t0 == INT32_C(2))) {
		t1 = vader_front_resolver$driver_stages$singleton();
		vader_global$vader_front_resolver$driver_stages$instance = t1;
		vader_global$vader_front_resolver$driver_stages$state = INT32_C(2);
		{ vader_gc_top = gc_frame.prev; return; }
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static void* vader_front_resolver$driver_stages$singleton(void) {
	void* l0 = NULL;
	void* l1 = NULL;
	void* l2 = NULL;
	void* t0 = NULL;
	void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
	l0 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(35u, 0u, 0u, 653u);
	l1 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 645u);
	l2 = (void*) _a2_arr;
	vader_struct_std_collections$Map__string__Any_t* _a3_obj = (vader_struct_std_collections$Map__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any_t));
	vader_obj_header_init(_a3_obj, 1004u);
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

static void* vader_front_resolver$enter_file(void* l0, void* l1) {
	void* l2 = NULL;
	void* l3 = NULL;
	void* l4 = NULL;
	void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l4 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope;
	l3 = ((vader_struct_vader_front_resolver$FileScope_t*) l1)->f_root;
	l2 = vader_front_resolver$swap_root(l2, l3);
	l3 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_ambiguous;
	l4 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_overloaded;
	vader_struct_vader_front_resolver$FileScope_t* _a0_obj = (vader_struct_vader_front_resolver$FileScope_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$FileScope_t));
	vader_obj_header_init(_a0_obj, 1782u);
	_a0_obj->f_root = l2;
	_a0_obj->f_ambiguous = l3;
	_a0_obj->f_overloaded = l4;
	l2 = (void*) _a0_obj;
	l3 = ((vader_struct_vader_front_resolver$FileScope_t*) l1)->f_ambiguous;
	((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_ambiguous = l3;
	VADER_WRITE_BARRIER((vader_struct_vader_front_resolver$ResolveState_t*) l0);
	l3 = ((vader_struct_vader_front_resolver$FileScope_t*) l1)->f_overloaded;
	((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_overloaded = l3;
	VADER_WRITE_BARRIER((vader_struct_vader_front_resolver$ResolveState_t*) l0);
	{ void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_front_resolver$entry_folder_of(vader_string_t l0) {
	vader_string_t l1 = 0;
	bool t0;
	vader_string_t* gc_atom_roots[2] = { &l0, &l1 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 2u, gc_atom_roots };
	vader_gc_top = &gc_frame;
	t0 = std_fs$exists(l0);
	if (t0) {
		t0 = std_fs$is_dir(l0);
		if (t0) {
			{ vader_string_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
		}
	}
	l1 = vader_front_resolver$dir_of(l0);
	if (!(l1 == 0u)) {
		{ vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	{ vader_gc_top = gc_frame.prev; return 489u; }
}

static void* vader_front_resolver$entry_namespace(vader_string_t l0, vader_string_t l1) {
	void* l2 = NULL;
	int64_t l3, l7;
	vader_box_t l4 = vader_box_null();
	vader_string_t l5 = 0;
	vader_string_t l6 = 0;
	bool t0;
	void* t1 = NULL;
	vader_box_t* gc_roots[1] = { &l4 };
	void** gc_raw_roots[2] = { &l2, &t1 };
	vader_string_t* gc_atom_roots[4] = { &l0, &l1, &l5, &l6 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_struct_vader_front_resolver$IncludePath_t* _a0_obj = (vader_struct_vader_front_resolver$IncludePath_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$IncludePath_t));
	vader_obj_header_init(_a0_obj, 1789u);
	_a0_obj->f_dir = l1;
	_a0_obj->f_prefix = l0;
	_a0_obj->f_merge = false;
	_a0_obj->f_origin = (uint8_t) 0;
	l2 = (void*) _a0_obj;
	l4 = std_string$index_of(l0, 47u, INT64_C(0));
	if (l4.tag == 0u) {
		{ void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l3 = ((int64_t) l4.payload.i);
	l5 = std_string$trim_suffix(l1, 534u);
	if (l5 != l0) {
		l6 = concat_2(534u, l0);
		t0 = std_string$ends_with(l5, l6);
		if (!(t0)) {
			{ void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
		}
	}
	l7 = (int64_t) vader_string_byte_len(l0);
	l6 = vader_string_byte_slice(l0, l3, l7);
	l5 = std_string$trim_suffix(l5, l6);
	l6 = vader_string_byte_slice(l0, INT64_C(0), l3);
	vader_struct_vader_front_resolver$IncludePath_t* _a1_obj = (vader_struct_vader_front_resolver$IncludePath_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$IncludePath_t));
	vader_obj_header_init(_a1_obj, 1789u);
	_a1_obj->f_dir = l5;
	_a1_obj->f_prefix = l6;
	_a1_obj->f_merge = false;
	_a1_obj->f_origin = (uint8_t) 0;
	t1 = (void*) _a1_obj;
	{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_front_resolver$exports_only_functions(void* l0, void* l1, vader_string_t l2) {
	void* l3;
	void* l7;
	void* l9;
	int64_t l4, l5;
	vader_string_t l6;
	vader_box_t l8, l10;
	vader_box_t t0;
	l3 = l1;
	l4 = vader_array_length(((vader_array_t*) l3));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		t0 = vader_array_box_slots(_a0_slotarr->buf)[vader_array_offset(_a0_slotarr) + (size_t) l5];
		l6 = t0.payload.s;
		l8 = std_collections$Map$std_core$Index$at__string__Any(l0, l6);
		if (l8.tag == 0u) {
			l5 = (l5 + INT64_C(1));
			continue;
		}
		l7 = l8.payload.obj;
		l10 = std_collections$Map$std_core$Index$at__string__Any(((vader_struct_vader_front_resolver$CollectedModule_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l7)->f_collected)->f_symbols, l2);
		if (l10.tag == 0u) {
			l5 = (l5 + INT64_C(1));
			continue;
		}
		l9 = l10.payload.obj;
		if (((vader_struct_vader_core_symbol$Symbol_t*) l9)->f_kind != INT32_C(0)) {
			return false;
		}
		l5 = (l5 + INT64_C(1));
	}
	return true;
}

static void* vader_front_resolver$failed(void* l0, void* l1) {
	bool l2;
	void* l3 = NULL;
	void* t0 = NULL;
	void** gc_raw_roots[4] = { &l0, &l1, &l3, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_vader_front_resolver$PackageFolder_t*) l0)->f_of_toolchain;
	vader_array_t* _a0_arr = vader_array_new(93u, 1u, 13u, 1245u);
	((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = l1;
	l3 = (void*) _a0_arr;
	vader_struct_toolchain_stage$ModuleSource_t* _a1_obj = (vader_struct_toolchain_stage$ModuleSource_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_stage$ModuleSource_t));
	vader_obj_header_init(_a1_obj, 1298u);
	_a1_obj->f_text = 0u;
	_a1_obj->f_of_toolchain = l2;
	_a1_obj->f_diagnostics = l3;
	t0 = (void*) _a1_obj;
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_resolver$fallback_of_stmt(vader_box_t l0) {
	void* t0;
	if (l0.tag == 1201u) {
		t0 = l0.payload.obj;
		if (((vader_struct_toolchain_ast$LetStmt_t*) t0)->f_value.tag == 1178u) {
			t0 = l0.payload.obj;
			return ((vader_struct_toolchain_ast$LetStmt_t*) t0)->f_value;
		}
	}
	if (l0.tag == 1175u) {
		t0 = l0.payload.obj;
		if (((vader_struct_toolchain_ast$ExprStmt_t*) t0)->f_expr.tag == 1178u) {
			t0 = l0.payload.obj;
			return ((vader_struct_toolchain_ast$ExprStmt_t*) t0)->f_expr;
		}
		return vader_box_obj(0u, NULL);
	}
	return vader_box_obj(0u, NULL);
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
	l3 = vader_array_length(((vader_array_t*) l2));
	l4 = INT64_C(0);
	while ((l4 < l3)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		l5 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l4);
		t0 = ((vader_struct_vader_front_resolver$FileImports_t*) l5)->f_file;
		if (t0 == l1) {
			{ void* __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
		}
		l4 = (l4 + INT64_C(1));
	}
	vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 642u);
	l2 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(28u, 0u, 0u, 642u);
	l5 = (void*) _a2_arr;
	vader_array_t* _a3_arr = vader_array_new(3u, 0u, 13u, 28u);
	l6 = (void*) _a3_arr;
	vader_array_t* _a4_arr = vader_array_new(29u, 0u, 7u, 645u);
	l7 = (void*) _a4_arr;
	vader_struct_std_collections$Map__string__string___t* _a5_obj = (vader_struct_std_collections$Map__string__string___t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__string___t));
	vader_obj_header_init(_a5_obj, 1029u);
	_a5_obj->f_ekeys = l5;
	_a5_obj->f_evals = l6;
	_a5_obj->f_index = l7;
	_a5_obj->f_mask = INT64_C(0);
	_a5_obj->f_grow_at = INT64_C(0);
	_a5_obj->f_size = INT64_C(0);
	_a5_obj->f_tombs = INT64_C(0);
	l5 = (void*) _a5_obj;
	vader_array_t* _a6_arr = vader_array_new(28u, 0u, 0u, 642u);
	l6 = (void*) _a6_arr;
	vader_array_t* _a7_arr = vader_array_new(35u, 0u, 0u, 653u);
	l7 = (void*) _a7_arr;
	vader_array_t* _a8_arr = vader_array_new(29u, 0u, 7u, 645u);
	l8 = (void*) _a8_arr;
	vader_struct_std_collections$Map__string__Any_t* _a9_obj = (vader_struct_std_collections$Map__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any_t));
	vader_obj_header_init(_a9_obj, 1004u);
	_a9_obj->f_ekeys = l6;
	_a9_obj->f_evals = l7;
	_a9_obj->f_index = l8;
	_a9_obj->f_mask = INT64_C(0);
	_a9_obj->f_grow_at = INT64_C(0);
	_a9_obj->f_size = INT64_C(0);
	_a9_obj->f_tombs = INT64_C(0);
	l6 = (void*) _a9_obj;
	vader_struct_vader_front_resolver$FileImports_t* _a10_obj = (vader_struct_vader_front_resolver$FileImports_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$FileImports_t));
	vader_obj_header_init(_a10_obj, 1781u);
	_a10_obj->f_file = l1;
	_a10_obj->f_paths = l2;
	_a10_obj->f_excludes = l5;
	_a10_obj->f_bindings = l6;
	t1 = (void*) _a10_obj;
	{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_front_resolver$file_of(void* l0) {
	vader_string_t t0;
	t0 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) l0)->f_program)->f_span)->f_start)->f_file;
	return t0;
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
	bool t1;
	vader_box_t* gc_roots[1] = { &t0 };
	void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l8, &l13 };
	vader_string_t* gc_atom_roots[2] = { &l11, &l12 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
	l5 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(35u, 0u, 0u, 653u);
	l6 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 645u);
	l7 = (void*) _a2_arr;
	vader_struct_std_collections$Map__string__Any_t* _a3_obj = (vader_struct_std_collections$Map__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any_t));
	vader_obj_header_init(_a3_obj, 1004u);
	_a3_obj->f_ekeys = l5;
	_a3_obj->f_evals = l6;
	_a3_obj->f_index = l7;
	_a3_obj->f_mask = INT64_C(0);
	_a3_obj->f_grow_at = INT64_C(0);
	_a3_obj->f_size = INT64_C(0);
	_a3_obj->f_tombs = INT64_C(0);
	l5 = (void*) _a3_obj;
	l6 = l0;
	l7 = ((vader_struct_std_collections$Map__string__vader_core_symbol_Symbol_t*) l6)->f_ekeys;
	l8 = ((vader_struct_std_collections$Map__string__vader_core_symbol_Symbol_t*) l6)->f_evals;
	l9 = INT64_C(0);
	l10 = ((vader_struct_std_collections$Map__string__vader_core_symbol_Symbol_t*) l6)->f_size;
	while ((l9 < l10)) {
		vader_array_t* _a4_slotarr = ((vader_array_t*) l7);
		VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l9)
		t0 = vader_array_box_slots(_a4_slotarr->buf)[vader_array_offset(_a4_slotarr) + (size_t) l9];
		l11 = t0.payload.s;
		vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
		VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l9)
		l6 = vader_array_ref_load_obj(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) l9);
		l12 = l11;
		l13 = l6;
		std_collections$Map$std_core$IndexSet$set_at__string__Any(l5, l12, vader_ref_box(l13));
		l9 = (l9 + INT64_C(1));
	}
	l6 = ((vader_struct_vader_front_resolver$FileImports_t*) l2)->f_bindings;
	l7 = ((vader_struct_std_collections$Map__string__vader_core_symbol_Symbol_t*) l6)->f_ekeys;
	l8 = ((vader_struct_std_collections$Map__string__vader_core_symbol_Symbol_t*) l6)->f_evals;
	l9 = INT64_C(0);
	l10 = ((vader_struct_std_collections$Map__string__vader_core_symbol_Symbol_t*) l6)->f_size;
	while ((l9 < l10)) {
		vader_array_t* _a6_slotarr = ((vader_array_t*) l7);
		VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l9)
		t0 = vader_array_box_slots(_a6_slotarr->buf)[vader_array_offset(_a6_slotarr) + (size_t) l9];
		l11 = t0.payload.s;
		vader_array_t* _a7_slotarr = ((vader_array_t*) l8);
		VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l9)
		l6 = vader_array_ref_load_obj(_a7_slotarr->buf, vader_array_offset(_a7_slotarr) + (size_t) l9);
		l12 = l11;
		l13 = l6;
		std_collections$Map$std_core$IndexSet$set_at__string__Any(l5, l12, vader_ref_box(l13));
		l9 = (l9 + INT64_C(1));
	}
	l6 = ((vader_struct_vader_front_resolver$CollectedModule_t*) l1)->f_symbols;
	l7 = ((vader_struct_std_collections$Map__string__vader_core_symbol_Symbol_t*) l6)->f_ekeys;
	l8 = ((vader_struct_std_collections$Map__string__vader_core_symbol_Symbol_t*) l6)->f_evals;
	l9 = INT64_C(0);
	l10 = ((vader_struct_std_collections$Map__string__vader_core_symbol_Symbol_t*) l6)->f_size;
	while ((l9 < l10)) {
		vader_array_t* _a8_slotarr = ((vader_array_t*) l7);
		VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l9)
		t0 = vader_array_box_slots(_a8_slotarr->buf)[vader_array_offset(_a8_slotarr) + (size_t) l9];
		l11 = t0.payload.s;
		vader_array_t* _a9_slotarr = ((vader_array_t*) l8);
		VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l9)
		l6 = vader_array_ref_load_obj(_a9_slotarr->buf, vader_array_offset(_a9_slotarr) + (size_t) l9);
		l12 = l11;
		l13 = l6;
		t1 = vader_core_symbol$is_compiler_decorator_symbol(l13);
		if (!(t1)) {
			std_collections$Map$std_core$IndexSet$set_at__string__Any(l5, l12, vader_ref_box(l13));
		}
		l9 = (l9 + INT64_C(1));
	}
	l6 = l4;
	l7 = ((vader_struct_std_collections$Map__string__vader_core_symbol_Symbol_t*) l6)->f_ekeys;
	l8 = ((vader_struct_std_collections$Map__string__vader_core_symbol_Symbol_t*) l6)->f_evals;
	l9 = INT64_C(0);
	l10 = ((vader_struct_std_collections$Map__string__vader_core_symbol_Symbol_t*) l6)->f_size;
	while ((l9 < l10)) {
		vader_array_t* _a10_slotarr = ((vader_array_t*) l7);
		VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l9)
		t0 = vader_array_box_slots(_a10_slotarr->buf)[vader_array_offset(_a10_slotarr) + (size_t) l9];
		l11 = t0.payload.s;
		vader_array_t* _a11_slotarr = ((vader_array_t*) l8);
		VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l9)
		l6 = vader_array_ref_load_obj(_a11_slotarr->buf, vader_array_offset(_a11_slotarr) + (size_t) l9);
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

static void* vader_front_resolver$file_scope(void* l0, void* l1, void* l2, void* l3, void* l4) {
	void* l5 = NULL;
	void* l6 = NULL;
	void* l7 = NULL;
	void* t0 = NULL;
	void** gc_raw_roots[9] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 9u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l5 = ((vader_struct_vader_front_resolver$FileImports_t*) l0)->f_paths;
	l6 = ((vader_struct_vader_front_resolver$FileImports_t*) l0)->f_excludes;
	l5 = vader_front_resolver$wildcard_ambiguities(l2, l5, l6, l3);
	l6 = vader_front_resolver$file_root_scope(l4, l1, l0, l2, l3);
	l7 = vader_front_resolver$function_clashes(l2, l5);
	vader_struct_vader_front_resolver$FileScope_t* _a0_obj = (vader_struct_vader_front_resolver$FileScope_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$FileScope_t));
	vader_obj_header_init(_a0_obj, 1782u);
	_a0_obj->f_root = l6;
	_a0_obj->f_ambiguous = l5;
	_a0_obj->f_overloaded = l7;
	t0 = (void*) _a0_obj;
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_front_resolver$find_core_module_id(void* l0) {
	vader_box_t t0;
	t0 = vader_front_resolver$find_module_id(l0, 3209u);
	return t0;
}

static void* vader_front_resolver$find_impl_trait_decl(vader_box_t l0, void* l1, void* l2, void* l3, void* l4, void* l5, void* l6) {
	void* l7 = NULL;
	void* l8 = NULL;
	void* l10 = NULL;
	void* l13 = NULL;
	vader_box_t l9 = vader_box_null();
	vader_string_t l11 = 0;
	uint8_t l12;
	void* t0 = NULL;
	void* t1 = NULL;
	vader_box_t* gc_roots[2] = { &l0, &l9 };
	void** gc_raw_roots[12] = { &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l8, &l10, &l13, &t0, &t1 };
	vader_string_t* gc_atom_roots[1] = { &l11 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(480u, 0u, 13u, 2419u);
	l7 = (void*) _a0_arr;
	vader_struct_vader_front_resolver$TraitLookup_t* _a1_obj = (vader_struct_vader_front_resolver$TraitLookup_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$TraitLookup_t));
	vader_obj_header_init(_a1_obj, 1819u);
	_a1_obj->f_trait_decl = vader_box_obj(0u, NULL);
	_a1_obj->f_other_kind = 0u;
	_a1_obj->f_hidden = false;
	_a1_obj->f_args = l7;
	l7 = (void*) _a1_obj;
	l9 = vader_front_resolver$trait_in_file_scope(l0, l2, l3, l4);
	if (l9.tag == 0u) {
		{ void* __vret = l7; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l8 = l9.payload.obj;
	if (l0.tag == 1179u) {
		if (((vader_struct_vader_core_symbol$Symbol_t*) l8)->f_visibility == INT32_C(1)) {
			vader_array_t* _a2_arr = vader_array_new(480u, 0u, 13u, 2419u);
			l10 = (void*) _a2_arr;
			vader_struct_vader_front_resolver$TraitLookup_t* _a3_obj = (vader_struct_vader_front_resolver$TraitLookup_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$TraitLookup_t));
			vader_obj_header_init(_a3_obj, 1819u);
			_a3_obj->f_trait_decl = vader_box_obj(0u, NULL);
			_a3_obj->f_other_kind = 0u;
			_a3_obj->f_hidden = true;
			_a3_obj->f_args = l10;
			t0 = (void*) _a3_obj;
			{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
		}
	}
	if (((vader_struct_vader_core_symbol$Symbol_t*) l8)->f_kind != INT32_C(3)) {
		l12 = ((vader_struct_vader_core_symbol$Symbol_t*) l8)->f_kind;
		if (l12 == INT32_C(1)) {
			l11 = 1907u;
		} else if (l12 == INT32_C(2)) {
			l11 = 1973u;
		} else if (l12 == INT32_C(5)) {
			l11 = 1963u;
		} else {
			l11 = 0u;
		}
		vader_array_t* _a4_arr = vader_array_new(480u, 0u, 13u, 2419u);
		l10 = (void*) _a4_arr;
		vader_struct_vader_front_resolver$TraitLookup_t* _a5_obj = (vader_struct_vader_front_resolver$TraitLookup_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$TraitLookup_t));
		vader_obj_header_init(_a5_obj, 1819u);
		_a5_obj->f_trait_decl = vader_box_obj(0u, NULL);
		_a5_obj->f_other_kind = l11;
		_a5_obj->f_hidden = false;
		_a5_obj->f_args = l10;
		t0 = (void*) _a5_obj;
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l13 = ((vader_struct_vader_front_resolver$LoadedProject_t*) l5)->f_modules;
	l11 = ((vader_struct_vader_core_symbol$Symbol_t*) l8)->f_module;
	l9 = std_collections$Map$std_core$Index$at__string__Any(l13, l11);
	if (l9.tag == 0u) {
		{ void* __vret = l7; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l10 = l9.payload.obj;
	l11 = ((vader_struct_vader_core_symbol$Symbol_t*) l8)->f_name;
	l9 = vader_front_resolver$trait_named(l10, l11);
	if (l9.tag == 0u) {
		{ void* __vret = l7; vader_gc_top = gc_frame.prev; return __vret; }
	}
	t0 = l9.payload.obj;
	t1 = vader_front_resolver$through_aliases(t0, l10, l1, l4, l5, l6);
	{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_resolver$find_module_id(void* l0, vader_string_t l1) {
	void* l2;
	void* l3;
	void* l4;
	int64_t l5, l6;
	vader_string_t l7, l8;
	vader_box_t t0;
	vader_string_t t1;
	l2 = ((vader_struct_vader_front_resolver$LoadedProject_t*) l0)->f_modules;
	l3 = ((vader_struct_std_collections$Map__string__vader_front_resolver_LoadedModule_t*) l2)->f_ekeys;
	l4 = ((vader_struct_std_collections$Map__string__vader_front_resolver_LoadedModule_t*) l2)->f_evals;
	l5 = INT64_C(0);
	l6 = ((vader_struct_std_collections$Map__string__vader_front_resolver_LoadedModule_t*) l2)->f_size;
	while ((l5 < l6)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
		t0 = vader_array_box_slots(_a0_slotarr->buf)[vader_array_offset(_a0_slotarr) + (size_t) l5];
		l7 = t0.payload.s;
		vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
		l2 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l5);
		l8 = l7;
		t1 = ((vader_struct_vader_front_resolver$Module_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l2)->f_module)->f_module_name;
		if (t1 == l1) {
			return vader_box_string(642u, l8);
		}
		l5 = (l5 + INT64_C(1));
	}
	return vader_box_obj(0u, NULL);
}

vader_box_t vader_front_resolver$find_scheduler_module_id(void* l0) {
	vader_box_t t0;
	t0 = vader_front_resolver$find_module_id(l0, 3211u);
	return t0;
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
	if (l0.tag == 1146u) {
		t0 = l0.payload.obj;
		t1 = vader_front_resolver$for_type_display_name(((vader_struct_toolchain_ast$ArrayTypeExpr_t*) t0)->f_element);
		t2 = concat_2(t1, 1220u);
		{ vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (l0.tag == 1186u) {
		t0 = l0.payload.obj;
		t1 = ((vader_struct_toolchain_ast$IdentExpr_t*) t0)->f_name;
		{ vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (l0.tag == 1185u) {
		t0 = l0.payload.obj;
		if (((vader_struct_toolchain_ast$GenericInstExpr_t*) t0)->f_callee.tag == 1186u) {
			t0 = l0.payload.obj;
			t1 = ((vader_struct_toolchain_ast$IdentExpr_t*) ((vader_struct_toolchain_ast$GenericInstExpr_t*) t0)->f_callee.payload.obj)->f_name;
			{ vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
		}
		{ vader_gc_top = gc_frame.prev; return 639u; }
	}
	{ vader_gc_top = gc_frame.prev; return 639u; }
}

static vader_box_t vader_front_resolver$for_type_owner_sym(vader_box_t l0, void* l1, void* l2) {
	void* l3;
	vader_box_t l4;
	uint64_t l5;
	void* t0;
	void* t1;
	if (l0.tag == 1146u) {
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
	if (l0.tag == 1186u) {
		t0 = l0.payload.obj;
		l5 = toolchain_span$Span$std_core$Hash$hash(((vader_struct_toolchain_ast$IdentExpr_t*) t0)->f_span);
		l4 = std_collections$Map$std_core$Index$at__u64__Any(l1, l5);
		if (l4.tag == 0u) {
			return vader_box_obj(0u, NULL);
		}
		t0 = l4.payload.obj;
		t1 = vader_front_resolver$resolve_import_redirect(t0, l2);
		return vader_ref_box(t1);
	}
	if (l0.tag == 1185u) {
		t0 = l0.payload.obj;
		if (((vader_struct_toolchain_ast$GenericInstExpr_t*) t0)->f_callee.tag == 1186u) {
			t0 = l0.payload.obj;
			l5 = toolchain_span$Span$std_core$Hash$hash(((vader_struct_toolchain_ast$IdentExpr_t*) ((vader_struct_toolchain_ast$GenericInstExpr_t*) t0)->f_callee.payload.obj)->f_span);
			l4 = std_collections$Map$std_core$Index$at__u64__Any(l1, l5);
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
	t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_front_resolver$Scope_t*) l0)->f_frames));
	return ((int32_t) (int64_t) t0);
}

static vader_string_t vader_front_resolver$framed_source(vader_string_t l0, vader_string_t l1, vader_string_t l2, vader_string_t l3) {
	vader_string_t t0;
	t0 = concat_8(537u, l0, 405u, l1, 1694u, l2, 316u, l3);
	return t0;
}

static void* vader_front_resolver$function_clashes(void* l0, void* l1) {
	void* l2 = NULL;
	void* l3 = NULL;
	void* l4 = NULL;
	void* l5 = NULL;
	void* l10 = NULL;
	int64_t l6, l7;
	vader_string_t l8 = 0;
	vader_string_t l9 = 0;
	void* t0 = NULL;
	vader_box_t t1 = vader_box_null();
	bool t2;
	vader_box_t* gc_roots[1] = { &t1 };
	void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l4, &l5, &l10, &t0 };
	vader_string_t* gc_atom_roots[2] = { &l8, &l9 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
	l2 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(26u, 0u, 12u, 640u);
	l3 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 645u);
	l4 = (void*) _a2_arr;
	vader_struct_std_collections$Map__string__bool_t* _a3_obj = (vader_struct_std_collections$Map__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__bool_t));
	vader_obj_header_init(_a3_obj, 1010u);
	_a3_obj->f_ekeys = l2;
	_a3_obj->f_evals = l3;
	_a3_obj->f_index = l4;
	_a3_obj->f_mask = INT64_C(0);
	_a3_obj->f_grow_at = INT64_C(0);
	_a3_obj->f_size = INT64_C(0);
	_a3_obj->f_tombs = INT64_C(0);
	t0 = (void*) _a3_obj;
	vader_struct_std_collections$Set__string_t* _a4_obj = (vader_struct_std_collections$Set__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__string_t));
	vader_obj_header_init(_a4_obj, 1110u);
	_a4_obj->f_inner = t0;
	l2 = (void*) _a4_obj;
	l3 = l1;
	l4 = ((vader_struct_std_collections$Map__string__string___t*) l3)->f_ekeys;
	l5 = ((vader_struct_std_collections$Map__string__string___t*) l3)->f_evals;
	l6 = INT64_C(0);
	l7 = ((vader_struct_std_collections$Map__string__string___t*) l3)->f_size;
	while ((l6 < l7)) {
		vader_array_t* _a5_slotarr = ((vader_array_t*) l4);
		VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l6)
		t1 = vader_array_box_slots(_a5_slotarr->buf)[vader_array_offset(_a5_slotarr) + (size_t) l6];
		l8 = t1.payload.s;
		vader_array_t* _a6_slotarr = ((vader_array_t*) l5);
		VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l6)
		l3 = vader_array_ref_load_obj(_a6_slotarr->buf, vader_array_offset(_a6_slotarr) + (size_t) l6);
		l9 = l8;
		l10 = l3;
		t2 = vader_front_resolver$exports_only_functions(l0, l10, l9);
		if (t2) {
			std_collections$add__string(l2, l9);
		}
		l6 = (l6 + INT64_C(1));
	}
	{ void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_resolver$function_named(void* l0, vader_string_t l1) {
	void* l2;
	void* l5;
	void* l9;
	int64_t l3, l4, l6, l7;
	vader_box_t l8;
	void* t0;
	vader_string_t t1;
	l2 = l0;
	l3 = vader_array_length(((vader_array_t*) l2));
	l4 = INT64_C(0);
	while ((l4 < l3)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l4);
		l5 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) t0)->f_program)->f_decls;
		l6 = vader_array_length(((vader_array_t*) l5));
		l7 = INT64_C(0);
		while ((l7 < l6)) {
			vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
			VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
			l8 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l7);
			if (l8.tag == 1181u) {
				l9 = l8.payload.obj;
				t1 = ((vader_struct_toolchain_ast$FnDecl_t*) l9)->f_name;
				if (t1 == l1) {
					return vader_ref_box(l9);
				}
			}
			l7 = (l7 + INT64_C(1));
		}
		l4 = (l4 + INT64_C(1));
	}
	return vader_box_obj(0u, NULL);
}

void* vader_front_resolver$generated_code(void* l0) {
	void* l1 = NULL;
	void* l2 = NULL;
	void* l3 = NULL;
	void* l4 = NULL;
	void* l5 = NULL;
	void* l10 = NULL;
	void* l12 = NULL;
	void* l15 = NULL;
	void* l16 = NULL;
	void* l19 = NULL;
	void* l20 = NULL;
	int64_t l6, l7, l13, l14;
	uint8_t l8;
	vader_string_t l9 = 0;
	vader_string_t l11 = 0;
	vader_string_t l17 = 0;
	vader_string_t l18 = 0;
	vader_string_t l21 = 0;
	void* t0 = NULL;
	vader_box_t t1 = vader_box_null();
	vader_string_t t2 = 0;
	bool t3;
	vader_box_t* gc_roots[1] = { &t1 };
	void** gc_raw_roots[13] = {
		&l0, &l1, &l2, &l3, &l4, &l5, &l10, &l12, &l15, &l16, &l19, &l20, &t0,
	};
	vader_string_t* gc_atom_roots[6] = { &l9, &l11, &l17, &l18, &l21, &t2 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 13u, gc_roots, gc_raw_roots, 0u, NULL, 6u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(339u, 0u, 13u, 1785u);
	l1 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 642u);
	l2 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(28u, 0u, 0u, 642u);
	l3 = (void*) _a2_arr;
	vader_array_t* _a3_arr = vader_array_new(26u, 0u, 12u, 640u);
	l4 = (void*) _a3_arr;
	vader_array_t* _a4_arr = vader_array_new(29u, 0u, 7u, 645u);
	l5 = (void*) _a4_arr;
	vader_struct_std_collections$Map__string__bool_t* _a5_obj = (vader_struct_std_collections$Map__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__bool_t));
	vader_obj_header_init(_a5_obj, 1010u);
	_a5_obj->f_ekeys = l3;
	_a5_obj->f_evals = l4;
	_a5_obj->f_index = l5;
	_a5_obj->f_mask = INT64_C(0);
	_a5_obj->f_grow_at = INT64_C(0);
	_a5_obj->f_size = INT64_C(0);
	_a5_obj->f_tombs = INT64_C(0);
	t0 = (void*) _a5_obj;
	vader_struct_std_collections$Set__string_t* _a6_obj = (vader_struct_std_collections$Set__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__string_t));
	vader_obj_header_init(_a6_obj, 1110u);
	_a6_obj->f_inner = t0;
	l3 = (void*) _a6_obj;
	vader_struct_vader_front_resolver$GeneratedCode_t* _a7_obj = (vader_struct_vader_front_resolver$GeneratedCode_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$GeneratedCode_t));
	vader_obj_header_init(_a7_obj, 1784u);
	_a7_obj->f_sources = l1;
	_a7_obj->f_origins = l2;
	_a7_obj->f_shipped_interfaces = l3;
	l1 = (void*) _a7_obj;
	l2 = ((vader_struct_vader_front_resolver$LoadedProject_t*) l0)->f_modules;
	l3 = ((vader_struct_std_collections$Map__string__vader_front_resolver_LoadedModule_t*) l2)->f_ekeys;
	l4 = ((vader_struct_std_collections$Map__string__vader_front_resolver_LoadedModule_t*) l2)->f_evals;
	l6 = INT64_C(0);
	l7 = ((vader_struct_std_collections$Map__string__vader_front_resolver_LoadedModule_t*) l2)->f_size;
	while ((l6 < l7)) {
		vader_array_t* _a8_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l6)
		t1 = vader_array_box_slots(_a8_slotarr->buf)[vader_array_offset(_a8_slotarr) + (size_t) l6];
		t2 = t1.payload.s;
		vader_array_t* _a9_slotarr = ((vader_array_t*) l4);
		VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l6)
		l2 = vader_array_ref_load_obj(_a9_slotarr->buf, vader_array_offset(_a9_slotarr) + (size_t) l6);
		l8 = ((vader_struct_vader_front_resolver$Module_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l2)->f_module)->f_origin;
		{
			if (l8 == INT32_C(1)) {
				t2 = ((vader_struct_vader_front_resolver$Module_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l2)->f_module)->f_id;
				t3 = vader_front_resolver$is_wit_module_file(t2);
				if (!(t3)) {
					goto end_53;
				}
			}
			l5 = ((vader_struct_vader_front_resolver$GeneratedCode_t*) l1)->f_origins;
			l9 = ((vader_struct_vader_front_resolver$Module_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l2)->f_module)->f_module_name;
			vader_array_push_scalar((vader_array_t*) l5, vader_box_string(642u, l9));
			if (((vader_struct_vader_front_resolver$Module_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l2)->f_module)->f_origin == INT32_C(1)) {
				l10 = ((vader_struct_vader_front_resolver$GeneratedCode_t*) l1)->f_shipped_interfaces;
				l11 = ((vader_struct_vader_front_resolver$Module_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l2)->f_module)->f_id;
				std_collections$add__string(l10, l11);
			}
			l12 = ((vader_struct_vader_front_resolver$Module_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l2)->f_module)->f_files;
			l13 = vader_array_length(((vader_array_t*) l12));
			l14 = INT64_C(0);
			while ((l14 < l13)) {
				vader_array_t* _a10_slotarr = ((vader_array_t*) l12);
				VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
				l15 = vader_array_ref_load_obj(_a10_slotarr->buf, vader_array_offset(_a10_slotarr) + (size_t) l14);
				t2 = ((vader_struct_vader_front_resolver$SourceFile_t*) l15)->f_path;
				t3 = vader_front_resolver$is_generated_file(t2);
				if (t3) {
					l16 = ((vader_struct_vader_front_resolver$GeneratedCode_t*) l1)->f_sources;
					l17 = ((vader_struct_vader_front_resolver$SourceFile_t*) l15)->f_path;
					l18 = ((vader_struct_vader_front_resolver$SourceFile_t*) l15)->f_content;
					vader_struct_vader_front_resolver$GeneratedSource_t* _a11_obj = (vader_struct_vader_front_resolver$GeneratedSource_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$GeneratedSource_t));
					vader_obj_header_init(_a11_obj, 1785u);
					_a11_obj->f_file = l17;
					_a11_obj->f_content = l18;
					l19 = (void*) _a11_obj;
					vader_array_push_ref((vader_array_t*) l16, l19);
				} else {
					l20 = ((vader_struct_vader_front_resolver$GeneratedCode_t*) l1)->f_origins;
					l21 = ((vader_struct_vader_front_resolver$SourceFile_t*) l15)->f_path;
					vader_array_push_scalar((vader_array_t*) l20, vader_box_string(642u, l21));
				}
				l14 = (l14 + INT64_C(1));
			}
		} end_53: ;
		l6 = (l6 + INT64_C(1));
	}
	l2 = ((vader_struct_vader_front_resolver$GeneratedCode_t*) l1)->f_sources;
	l3 = ((vader_struct_vader_front_resolver$LoadedProject_t*) l0)->f_given_bodies;
	vader_array_push_all((vader_array_t*) l2, (vader_array_t*) l3);
	{ void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_front_resolver$generated_file(vader_string_t l0, vader_string_t l1) {
	vader_string_t t0;
	t0 = concat_4(617u, l0, 563u, l1);
	return t0;
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
	if (l0.tag == 642u) {
		l1 = l0.payload.s;
	} else {
		if (!(l0.tag == 0u)) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		l1 = std_env$current_working_directory();
	}
	l1 = vader_front_resolver$join_path(l1, 2134u);
	t0 = std_fs$is_dir(l1);
	if (!(t0)) {
		{ vader_gc_top = gc_frame.prev; return 0u; }
	}
	{ vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$graft_body(void* l0, void* l1) {
	void* l2 = NULL;
	void* l3 = NULL;
	void* l6 = NULL;
	void* l8 = NULL;
	void* l10 = NULL;
	void* l11 = NULL;
	void* l12 = NULL;
	int64_t l4, l5;
	vader_string_t l7 = 0;
	uint8_t l9;
	vader_box_t l13 = vader_box_null(), l14 = vader_box_null(), l20 = vader_box_null(), l21 = vader_box_null();
	bool l15, l16, l17, l18, l19;
	int64_t t0;
	bool t1;
	void* t2 = NULL;
	vader_box_t* gc_roots[4] = { &l13, &l14, &l20, &l21 };
	void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l6, &l8, &l10, &l11, &l12, &t2 };
	vader_string_t* gc_atom_roots[1] = { &l7 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 4u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	t0 = vader_array_length(((vader_array_t*) ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_decorators));
	vader_array_t* _a0_arr = vader_array_reserve(67u, (int64_t) t0, 13u, 1159u);
	l2 = (void*) _a0_arr;
	l3 = ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_decorators;
	l4 = vader_array_length(((vader_array_t*) l3));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		l6 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l5);
		vader_array_push_ref((vader_array_t*) l2, l6);
		l5 = (l5 + INT64_C(1));
	}
	l3 = ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_decorators;
	l4 = vader_array_length(((vader_array_t*) l3));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
		l6 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l5);
		t1 = vader_front_resolver$provides_body(l6);
		if (t1) {
			vader_array_push_ref((vader_array_t*) l2, l6);
		}
		l5 = (l5 + INT64_C(1));
	}
	l3 = l0;
	l6 = ((vader_struct_toolchain_ast$FnDecl_t*) l3)->f_span;
	l4 = ((vader_struct_toolchain_ast$FnDecl_t*) l3)->f_id;
	l7 = ((vader_struct_toolchain_ast$FnDecl_t*) l3)->f_name;
	l8 = ((vader_struct_toolchain_ast$FnDecl_t*) l3)->f_name_span;
	l9 = ((vader_struct_toolchain_ast$FnDecl_t*) l3)->f_visibility;
	l10 = ((vader_struct_toolchain_ast$FnDecl_t*) l3)->f_type_params;
	l11 = ((vader_struct_toolchain_ast$FnDecl_t*) l3)->f_params;
	l12 = ((vader_struct_toolchain_ast$FnDecl_t*) l3)->f_params_span;
	l13 = ((vader_struct_toolchain_ast$FnDecl_t*) l3)->f_return_type;
	l14 = ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_body;
	l15 = ((vader_struct_toolchain_ast$FnDecl_t*) l3)->f_sam_synthetic;
	l16 = ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_is_expression_bodied;
	l17 = ((vader_struct_toolchain_ast$FnDecl_t*) l3)->f_materialized;
	l18 = ((vader_struct_toolchain_ast$FnDecl_t*) l3)->f_comptime_synthetic;
	l19 = ((vader_struct_toolchain_ast$FnDecl_t*) l3)->f_trailing_comma;
	l20 = ((vader_struct_toolchain_ast$FnDecl_t*) l3)->f_doc;
	l21 = ((vader_struct_toolchain_ast$FnDecl_t*) l3)->f_inherits;
	vader_struct_toolchain_ast$FnDecl_t* _a3_obj = (vader_struct_toolchain_ast$FnDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$FnDecl_t));
	vader_obj_header_init(_a3_obj, 1181u);
	_a3_obj->f_span = l6;
	_a3_obj->f_id = l4;
	_a3_obj->f_name = l7;
	_a3_obj->f_name_span = l8;
	_a3_obj->f_visibility = l9;
	_a3_obj->f_type_params = l10;
	_a3_obj->f_params = l11;
	_a3_obj->f_params_span = l12;
	_a3_obj->f_return_type = l13;
	_a3_obj->f_body = l14;
	_a3_obj->f_decorators = l2;
	_a3_obj->f_sam_synthetic = l15;
	_a3_obj->f_is_expression_bodied = l16;
	_a3_obj->f_materialized = l17;
	_a3_obj->f_comptime_synthetic = l18;
	_a3_obj->f_trailing_comma = l19;
	_a3_obj->f_doc = l20;
	_a3_obj->f_inherits = l21;
	t2 = (void*) _a3_obj;
	{ void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

bool vader_front_resolver$has_impl_decl(void* l0) {
	void* l1;
	int64_t l2, l3;
	vader_box_t t0;
	l1 = l0;
	l2 = vader_array_length(((vader_array_t*) l1));
	l3 = INT64_C(0);
	while ((l3 < l2)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		t0 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l3);
		if (t0.tag == 1190u) {
			return !(false);
		}
		l3 = (l3 + INT64_C(1));
	}
	return !(true);
}

static bool vader_front_resolver$has_module(void* l0, vader_string_t l1) {
	vader_box_t t0;
	t0 = std_collections$Map$std_core$Index$at__string__Any(l0, l1);
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
	l3 = vader_array_length(((vader_array_t*) l2));
	l4 = INT64_C(0);
	while ((l4 < l3)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		l5 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l4);
		l6 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_reassigned;
		l7 = ((vader_struct_vader_core_symbol$Symbol_t*) l5)->f_id;
		t0 = std_collections$Set$std_core$Contains$contains__i32(l6, l7);
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
	l3 = std_env$get_env(1173u);
	if (l3.tag == 0u) {
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	l2 = l3.payload.s;
	if (l2 == 0u) {
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	l2 = vader_front_resolver$join_path(l2, l0);
	t0 = vader_front_resolver$join_path(l2, l1);
	t1 = std_fs$exists(t0);
	if (!(t1)) {
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	{ vader_box_t __vret = vader_box_string(642u, l2); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_resolver$hook_diagnostic(void* l0) {
	uint8_t l1, l2;
	void* l3 = NULL;
	void* l7 = NULL;
	int64_t l4;
	vader_string_t l5 = 0;
	vader_string_t l6 = 0;
	vader_string_t l8 = 0;
	void* t0 = NULL;
	int32_t t1;
	vader_string_t t2 = 0;
	void** gc_raw_roots[4] = { &l0, &l3, &l7, &t0 };
	vader_string_t* gc_atom_roots[4] = { &l5, &l6, &l8, &t2 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l1 = (uint8_t) 0;
	while ((l1 <= INT32_C(16))) {
		l2 = l1;
		l3 = (void*) &vader_data_5;
		l4 = ((int64_t) (uint8_t) l2);
		vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
		t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l4);
		l5 = ((vader_struct_toolchain_diagnostics$CodeInfo_t*) t0)->f_id;
		l6 = ((vader_struct_toolchain_protocol$ReportFrame_t*) l0)->f_code;
		if (l5 == l6) {
			l7 = ((vader_struct_toolchain_protocol$ReportFrame_t*) l0)->f_span;
			l8 = ((vader_struct_toolchain_protocol$ReportFrame_t*) l0)->f_detail;
			t0 = toolchain_diagnostics$hook_error(l2, l7, l8);
			{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
		}
		t1 = ((l1 + INT32_C(1)) & INT32_C(255));
		l1 = (uint8_t) (int32_t) t1;
	}
	l5 = ((vader_struct_toolchain_protocol$ReportFrame_t*) l0)->f_code;
	t2 = concat_3(1307u, l5, 1486u);
	vader_struct_toolchain_protocol$ProtocolError_t* _a1_obj = (vader_struct_toolchain_protocol$ProtocolError_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_protocol$ProtocolError_t));
	vader_obj_header_init(_a1_obj, 1282u);
	_a1_obj->f_msg = t2;
	t0 = (void*) _a1_obj;
	{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$import_paths_of(void* l0) {
	void* l1 = NULL;
	void* l2 = NULL;
	void* l5 = NULL;
	void* l10 = NULL;
	void* l11 = NULL;
	int64_t l3, l4, l6, l7;
	vader_box_t l8 = vader_box_null();
	vader_string_t l9 = 0;
	void* t0 = NULL;
	vader_string_t t1 = 0;
	vader_box_t* gc_roots[1] = { &l8 };
	void** gc_raw_roots[7] = { &l0, &l1, &l2, &l5, &l10, &l11, &t0 };
	vader_string_t* gc_atom_roots[2] = { &l9, &t1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(341u, 0u, 13u, 1787u);
	l1 = (void*) _a0_arr;
	l2 = l0;
	l3 = vader_array_length(((vader_array_t*) l2));
	l4 = INT64_C(0);
	while ((l4 < l3)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		t0 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l4);
		l5 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) t0)->f_program)->f_decls;
		l6 = vader_array_length(((vader_array_t*) l5));
		l7 = INT64_C(0);
		while ((l7 < l6)) {
			vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
			VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
			l8 = vader_array_ref_load_box(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l7);
			if (l8.tag == 1191u) {
				t0 = l8.payload.obj;
				t1 = ((vader_struct_toolchain_ast$ImportDecl_t*) t0)->f_path;
				if (t1 != 0u) {
					t0 = l8.payload.obj;
					l9 = ((vader_struct_toolchain_ast$ImportDecl_t*) t0)->f_path;
					t0 = l8.payload.obj;
					l10 = ((vader_struct_toolchain_ast$ImportDecl_t*) t0)->f_span;
					vader_struct_vader_front_resolver$ImportPath_t* _a3_obj = (vader_struct_vader_front_resolver$ImportPath_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$ImportPath_t));
					vader_obj_header_init(_a3_obj, 1787u);
					_a3_obj->f_path = l9;
					_a3_obj->f_span = l10;
					l11 = (void*) _a3_obj;
					vader_array_push_ref((vader_array_t*) l1, l11);
				}
			}
			l7 = (l7 + INT64_C(1));
		}
		l4 = (l4 + INT64_C(1));
	}
	{ void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static uint8_t vader_front_resolver$importer_origin(void* l0, vader_string_t l1) {
	void* l2;
	vader_box_t l3;
	l3 = std_collections$Map$std_core$Index$at__string__Any(l0, l1);
	if (l3.tag == 0u) {
		return (uint8_t) 0;
	}
	l2 = l3.payload.obj;
	return ((vader_struct_vader_front_resolver$DiscoveredModule_t*) l2)->f_origin;
}

static vader_string_t vader_front_resolver$imports_text(void* l0) {
	void* l1 = NULL;
	void* l2 = NULL;
	void* l6 = NULL;
	void* l7 = NULL;
	int64_t l3, l4, l9, l10;
	vader_box_t l5 = vader_box_null();
	vader_string_t l8 = 0;
	vader_string_t l11 = 0;
	void* t0 = NULL;
	bool t1;
	vader_string_t t2 = 0;
	vader_box_t* gc_roots[1] = { &l5 };
	void** gc_raw_roots[6] = { &l0, &l1, &l2, &l6, &l7, &t0 };
	vader_string_t* gc_atom_roots[3] = { &l8, &l11, &t2 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
	t0 = (void*) _a0_arr;
	vader_struct_std_string__builder$StringBuilder_t* _a1_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
	vader_obj_header_init(_a1_obj, 1139u);
	_a1_obj->f_parts = t0;
	l1 = (void*) _a1_obj;
	l2 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) l0)->f_program)->f_decls;
	l3 = vader_array_length(((vader_array_t*) l2));
	l4 = INT64_C(0);
	while ((l4 < l3)) {
		vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
		l5 = vader_array_ref_load_box(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l4);
		if (l5.tag == 1191u) {
			l6 = l5.payload.obj;
			t1 = std_core$is_empty__toolchain_ast_Decorator(((vader_struct_toolchain_ast$ImportDecl_t*) l6)->f_decorators);
			if (t1) {
				l7 = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_toolchain_ast$ImportDecl_t*) l6)->f_span)->f_start;
			} else {
				vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$ImportDecl_t*) l6)->f_decorators);
				VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
				VADER_ARRAY_CHECK_INDEX(_a3_slotarr, INT32_C(0))
				t0 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) INT32_C(0));
				l7 = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_toolchain_ast$Decorator_t*) t0)->f_span)->f_start;
			}
			l8 = ((vader_struct_vader_front_resolver$SourceFile_t*) l0)->f_content;
			l9 = ((vader_struct_toolchain_span$Position_t*) l7)->f_offset;
			l10 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) ((vader_struct_toolchain_ast$ImportDecl_t*) l6)->f_span)->f_end)->f_offset;
			l11 = vader_string_byte_slice(l8, l9, l10);
			std_string__builder$append(l1, l11);
			std_string__builder$append(l1, 2u);
		}
		l4 = (l4 + INT64_C(1));
	}
	t2 = std_string__builder$StringBuilder$std_core$Display$to_string(l1);
	{ vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
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
	vader_array_t* _a0_arr = vader_array_new(342u, 1u, 13u, 1789u);
	((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = l0;
	l3 = (void*) _a0_arr;
	vader_array_push_all((vader_array_t*) l3, (vader_array_t*) l1);
	if (l2 != 0u) {
		vader_struct_vader_front_resolver$IncludePath_t* _a1_obj = (vader_struct_vader_front_resolver$IncludePath_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$IncludePath_t));
		vader_obj_header_init(_a1_obj, 1789u);
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
	std_collections$Map$std_core$IndexSet$set_at__u64__Any(l0, l3, vader_ref_box(l1));
	{ vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$ingest_module(void* l0, void* l1, void* l2) {
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
	vader_box_t l5 = vader_box_null();
	vader_string_t l14 = 0;
	int64_t t0;
	vader_box_t* gc_roots[1] = { &l5 };
	void** gc_raw_roots[13] = {
		&l0, &l1, &l2, &l3, &l4, &l6, &l7, &l8, &l9, &l10, &l11, &l12, &l13,
	};
	vader_string_t* gc_atom_roots[1] = { &l14 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 13u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_front_resolver$DiscoveredModule_t*) l1)->f_files));
	if (t0 == INT64_C(0)) {
		{ vader_gc_top = gc_frame.prev; return; }
	}
	l3 = vader_front_resolver$number_module_files(l0, l2);
	t0 = vader_array_length(((vader_array_t*) l3));
	if (!(t0 == INT64_C(0))) {
		l3 = vader_front_resolver$tested_or_not(l0, l1, l3);
		l4 = ((vader_struct_vader_front_resolver$Untested_t*) l3)->f_files;
		l5 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_selected_target;
		l6 = vader_front_resolver$discarded_bodies(l4, l5);
		vader_array_t* _a0_arr = vader_array_new(355u, 0u, 13u, 1820u);
		l7 = (void*) _a0_arr;
		l5 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_selected_target;
		l8 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_diags;
		l8 = vader_front_resolver$select_target_bodies(l4, l5, l8, l7);
		l9 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_bases;
		l10 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_index;
		l11 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_overlay;
		l12 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_diags;
		l13 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_module_server;
		vader_front_resolver$preresolve_imports(l8, l9, l10, l11, l12, l13);
		l4 = vader_front_resolver$target_declarations(l4);
		l3 = ((vader_struct_vader_front_resolver$Untested_t*) l3)->f_cut;
		vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 642u);
		l9 = (void*) _a1_arr;
		vader_array_t* _a2_arr = vader_array_new(345u, 0u, 13u, 1793u);
		l10 = (void*) _a2_arr;
		vader_struct_vader_front_resolver$DeferredModule_t* _a3_obj = (vader_struct_vader_front_resolver$DeferredModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$DeferredModule_t));
		vader_obj_header_init(_a3_obj, 1776u);
		_a3_obj->f_found = l1;
		_a3_obj->f_sources = l8;
		_a3_obj->f_discarded_bodies = l6;
		_a3_obj->f_target_decls = l4;
		_a3_obj->f_files_without_tests = l3;
		_a3_obj->f_trimmed = false;
		_a3_obj->f_lost_impl_traits = l9;
		_a3_obj->f_late = l10;
		_a3_obj->f_uncovered = l7;
		l3 = (void*) _a3_obj;
		vader_array_push_ref((vader_array_t*) ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_deferred, l3);
		l4 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_modules;
		l14 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) l1)->f_folder;
		vader_array_t* _a4_arr = vader_array_new(28u, 0u, 0u, 642u);
		l6 = (void*) _a4_arr;
		vader_array_t* _a5_arr = vader_array_new(35u, 0u, 0u, 653u);
		l7 = (void*) _a5_arr;
		vader_array_t* _a6_arr = vader_array_new(29u, 0u, 7u, 645u);
		l9 = (void*) _a6_arr;
		vader_struct_std_collections$Map__string__Any_t* _a7_obj = (vader_struct_std_collections$Map__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any_t));
		vader_obj_header_init(_a7_obj, 1004u);
		_a7_obj->f_ekeys = l6;
		_a7_obj->f_evals = l7;
		_a7_obj->f_index = l9;
		_a7_obj->f_mask = INT64_C(0);
		_a7_obj->f_grow_at = INT64_C(0);
		_a7_obj->f_size = INT64_C(0);
		_a7_obj->f_tombs = INT64_C(0);
		l6 = (void*) _a7_obj;
		vader_array_t* _a8_arr = vader_array_new(28u, 0u, 0u, 642u);
		l7 = (void*) _a8_arr;
		vader_array_t* _a9_arr = vader_array_new(35u, 0u, 0u, 653u);
		l9 = (void*) _a9_arr;
		vader_array_t* _a10_arr = vader_array_new(29u, 0u, 7u, 645u);
		l10 = (void*) _a10_arr;
		vader_struct_std_collections$Map__string__Any___t* _a11_obj = (vader_struct_std_collections$Map__string__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any___t));
		vader_obj_header_init(_a11_obj, 1005u);
		_a11_obj->f_ekeys = l7;
		_a11_obj->f_evals = l9;
		_a11_obj->f_index = l10;
		_a11_obj->f_mask = INT64_C(0);
		_a11_obj->f_grow_at = INT64_C(0);
		_a11_obj->f_size = INT64_C(0);
		_a11_obj->f_tombs = INT64_C(0);
		l7 = (void*) _a11_obj;
		vader_array_t* _a12_arr = vader_array_new(29u, 0u, 7u, 645u);
		l9 = (void*) _a12_arr;
		vader_array_t* _a13_arr = vader_array_new(35u, 0u, 0u, 653u);
		l10 = (void*) _a13_arr;
		vader_array_t* _a14_arr = vader_array_new(29u, 0u, 7u, 645u);
		l11 = (void*) _a14_arr;
		vader_struct_std_collections$Map__i32__Any_t* _a15_obj = (vader_struct_std_collections$Map__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__Any_t));
		vader_obj_header_init(_a15_obj, 916u);
		_a15_obj->f_ekeys = l9;
		_a15_obj->f_evals = l10;
		_a15_obj->f_index = l11;
		_a15_obj->f_mask = INT64_C(0);
		_a15_obj->f_grow_at = INT64_C(0);
		_a15_obj->f_size = INT64_C(0);
		_a15_obj->f_tombs = INT64_C(0);
		l9 = (void*) _a15_obj;
		l8 = vader_front_resolver$import_paths_of(l8);
		vader_array_t* _a16_arr = vader_array_new(338u, 0u, 13u, 1781u);
		l10 = (void*) _a16_arr;
		vader_struct_vader_front_resolver$CollectedModule_t* _a17_obj = (vader_struct_vader_front_resolver$CollectedModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$CollectedModule_t));
		vader_obj_header_init(_a17_obj, 1773u);
		_a17_obj->f_symbols = l6;
		_a17_obj->f_fn_overloads = l7;
		_a17_obj->f_imports = l9;
		_a17_obj->f_import_paths = l8;
		_a17_obj->f_files = l10;
		l6 = (void*) _a17_obj;
		l3 = vader_front_resolver$loaded_module(l0, l3, l6);
		std_collections$Map$std_core$IndexSet$set_at__string__Any(l4, l14, vader_ref_box(l3));
		{ vader_gc_top = gc_frame.prev; return; }
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$intercept_functions(void* l0, void* l1, void* l2) {
	void* l3 = NULL;
	void* l4 = NULL;
	void* l5 = NULL;
	void* l8 = NULL;
	void* l9 = NULL;
	void* l10 = NULL;
	void* l13 = NULL;
	void* l16 = NULL;
	int64_t l6, l7, l11, l12;
	vader_string_t l14 = 0;
	vader_box_t l15 = vader_box_null();
	bool t0;
	vader_box_t* gc_roots[1] = { &l15 };
	void** gc_raw_roots[11] = { &l0, &l1, &l2, &l3, &l4, &l5, &l8, &l9, &l10, &l13, &l16 };
	vader_string_t* gc_atom_roots[1] = { &l14 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 11u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l3 = vader_front_resolver$declared_interceptors(l0, l2);
	t0 = std_core$is_empty__vader_front_resolver_Interceptor(l3);
	if (t0) {
		{ vader_gc_top = gc_frame.prev; return; }
	}
	l4 = vader_front_resolver$declared_decorators(l0);
	l5 = l0;
	l6 = vader_array_length(((vader_array_t*) l5));
	l7 = INT64_C(0);
	while ((l7 < l6)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l7)
		l8 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l7);
		vader_array_t* _a1_arr = vader_array_new(352u, 0u, 13u, 1814u);
		l9 = (void*) _a1_arr;
		l10 = ((vader_struct_vader_front_resolver$DeferredModule_t*) l8)->f_sources;
		l11 = vader_array_length(((vader_array_t*) l10));
		l12 = INT64_C(0);
		while ((l12 < l11)) {
			vader_array_t* _a2_slotarr = ((vader_array_t*) l10);
			VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
			VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l12)
			l13 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l12);
			l14 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) ((vader_struct_vader_front_resolver$DeferredModule_t*) l8)->f_found)->f_name;
			l15 = vader_front_resolver$wrap_file(l13, l14, l3, l4, l1, l2);
			if (!(l15.tag == 0u)) {
				l16 = l15.payload.obj;
				vader_array_push_ref((vader_array_t*) l9, l16);
			}
			l12 = (l12 + INT64_C(1));
		}
		vader_array_push_all((vader_array_t*) ((vader_struct_vader_front_resolver$DeferredModule_t*) l8)->f_sources, (vader_array_t*) l9);
		l7 = (l7 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static void* vader_front_resolver$interceptions_of(void* l0, vader_string_t l1, void* l2, void* l3, void* l4) {
	void* l5 = NULL;
	void* l6 = NULL;
	void* l9 = NULL;
	void* l10 = NULL;
	void* l12 = NULL;
	void* l15 = NULL;
	void* l18 = NULL;
	int64_t l7, l8, l13, l14;
	vader_box_t l11 = vader_box_null();
	vader_string_t l16 = 0;
	vader_string_t l17 = 0;
	bool t0;
	vader_box_t* gc_roots[1] = { &l11 };
	void** gc_raw_roots[11] = { &l0, &l2, &l3, &l4, &l5, &l6, &l9, &l10, &l12, &l15, &l18 };
	vader_string_t* gc_atom_roots[3] = { &l1, &l16, &l17 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 11u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(343u, 0u, 13u, 1790u);
	l5 = (void*) _a0_arr;
	l6 = ((vader_struct_toolchain_ast$FnDecl_t*) l2)->f_decorators;
	l7 = vader_array_length(((vader_array_t*) l6));
	l8 = INT64_C(0);
	while ((l8 < l7)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		l9 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l8);
		l11 = vader_front_resolver$written_origin(l0, l1, l9, l4);
		if (l11.tag == 0u) {
			l8 = (l8 + INT64_C(1));
			continue;
		}
		l10 = l11.payload.obj;
		l12 = l3;
		l13 = vader_array_length(((vader_array_t*) l12));
		l14 = INT64_C(0);
		while ((l14 < l13)) {
			vader_array_t* _a2_slotarr = ((vader_array_t*) l12);
			VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
			l15 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l14);
			t0 = toolchain_stage$same_origin(((vader_struct_vader_front_resolver$Interceptor_t*) l15)->f_origin, l10);
			if (t0) {
				l16 = vader_front_resolver$qualifier_of(l9);
				l17 = ((vader_struct_toolchain_ast$Decorator_t*) l9)->f_name;
				vader_struct_vader_front_resolver$Interception_t* _a3_obj = (vader_struct_vader_front_resolver$Interception_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$Interception_t));
				vader_obj_header_init(_a3_obj, 1790u);
				_a3_obj->f_interceptor = l15;
				_a3_obj->f_qualifier = l16;
				_a3_obj->f_name = l17;
				l18 = (void*) _a3_obj;
				vader_array_push_ref((vader_array_t*) l5, l18);
			}
			l14 = (l14 + INT64_C(1));
		}
		l8 = (l8 + INT64_C(1));
	}
	{ void* __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$interface_name_of(vader_string_t l0) {
	int64_t l1, l4, l7;
	vader_box_t l2 = vader_box_null();
	vader_string_t l3 = 0;
	vader_string_t l5 = 0;
	vader_string_t l6 = 0;
	vader_string_t l8 = 0;
	void* t0 = NULL;
	vader_box_t* gc_roots[1] = { &l2 };
	void** gc_raw_roots[1] = { &t0 };
	vader_string_t* gc_atom_roots[5] = { &l0, &l3, &l5, &l6, &l8 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = std_string$last_index_of(l0, 47u, INT64_C(0));
	if (l2.tag == 0u) {
		l1 = INT64_C(-1);
	} else {
		l1 = ((int64_t) l2.payload.i);
	}
	l3 = vader_string_byte_slice(l0, INT64_C(0), l1);
	l1 = vader_chk_add(i64, l1, INT64_C(1));
	l4 = (int64_t) vader_string_byte_len(l0);
	l5 = vader_string_byte_slice(l0, l1, l4);
	l2 = std_string$last_index_of(l3, 58u, INT64_C(0));
	if (l2.tag == 0u) {
		l1 = INT64_C(-1);
	} else {
		l1 = ((int64_t) l2.payload.i);
	}
	l2 = std_string$index_of(l5, 64u, INT64_C(0));
	if (l2.tag == 0u) {
		l4 = (int64_t) vader_string_byte_len(l5);
	} else {
		l4 = ((int64_t) l2.payload.i);
	}
	l6 = vader_string_byte_slice(l5, INT64_C(0), l4);
	l7 = (int64_t) vader_string_byte_len(l5);
	if ((l4 < l7)) {
		l4 = vader_chk_add(i64, l4, INT64_C(1));
		l7 = (int64_t) vader_string_byte_len(l5);
		l5 = vader_string_byte_slice(l5, l4, l7);
	} else {
		l5 = 0u;
	}
	l8 = vader_string_byte_slice(l3, INT64_C(0), l1);
	l1 = vader_chk_add(i64, l1, INT64_C(1));
	l4 = (int64_t) vader_string_byte_len(l3);
	l3 = vader_string_byte_slice(l3, l1, l4);
	vader_struct_vader_core_wit$WitPackageName_t* _a0_obj = (vader_struct_vader_core_wit$WitPackageName_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitPackageName_t));
	vader_obj_header_init(_a0_obj, 1553u);
	_a0_obj->f_namespace = l8;
	_a0_obj->f_name = l3;
	_a0_obj->f_version = l5;
	t0 = (void*) _a0_obj;
	vader_struct_vader_front_resolver$InterfaceName_t* _a1_obj = (vader_struct_vader_front_resolver$InterfaceName_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$InterfaceName_t));
	vader_obj_header_init(_a1_obj, 1792u);
	_a1_obj->f_package = t0;
	_a1_obj->f_interface = l6;
	t0 = (void*) _a1_obj;
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$io_error(vader_string_t l0, vader_string_t l1) {
	void* l2 = NULL;
	void* t0 = NULL;
	void** gc_raw_roots[2] = { &l2, &t0 };
	vader_string_t* gc_atom_roots[2] = { &l0, &l1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_struct_vader_core_wit$WitSpan_t* _a0_obj = (vader_struct_vader_core_wit$WitSpan_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitSpan_t));
	vader_obj_header_init(_a0_obj, 1564u);
	_a0_obj->f_file = l0;
	_a0_obj->f_line = INT32_C(1);
	_a0_obj->f_column = INT32_C(1);
	l2 = (void*) _a0_obj;
	vader_struct_vader_core_wit$WitError_t* _a1_obj = (vader_struct_vader_core_wit$WitError_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitError_t));
	vader_obj_header_init(_a1_obj, 1533u);
	_a1_obj->f_message = l1;
	_a1_obj->f_span = l2;
	t0 = (void*) _a1_obj;
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_front_resolver$is_contract_decorator(void* l0) {
	bool t0;
	t0 = toolchain_ast$is_compiler(l0, (uint8_t) 20);
	if (t0) {
		return true;
	}
	t0 = toolchain_ast$is_compiler(l0, (uint8_t) 13);
	return t0;
}

static bool vader_front_resolver$is_core_file(void* l0) {
	void* l1;
	vader_box_t l2;
	vader_string_t t0;
	l2 = ((vader_struct_toolchain_ast$Program_t*) l0)->f_module;
	if (l2.tag == 0u) {
		return false;
	}
	l1 = l2.payload.obj;
	t0 = ((vader_struct_toolchain_ast$ModuleDecl_t*) l1)->f_name;
	return t0 == 3209u;
}

bool vader_front_resolver$is_displayable_impl(void* l0) {
	void* l1 = NULL;
	int64_t l2, l3;
	void* t0 = NULL;
	bool t1;
	void** gc_raw_roots[3] = { &l0, &l1, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l1 = ((vader_struct_toolchain_ast$ImplDecl_t*) l0)->f_members;
	l2 = vader_array_length(((vader_array_t*) l1));
	l3 = INT64_C(0);
	while ((l3 < l2)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l3);
		t1 = __lambda_vader_front_resolver_31(t0);
		if (t1) {
			{ vader_gc_top = gc_frame.prev; return true; }
		}
		l3 = (l3 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return false; }
}

static bool vader_front_resolver$is_generated_by(vader_string_t l0, vader_string_t l1) {
	vader_string_t l2 = 0;
	bool t0;
	vader_string_t* gc_atom_roots[3] = { &l0, &l1, &l2 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 3u, gc_atom_roots };
	vader_gc_top = &gc_frame;
	l2 = concat_3(617u, l1, 563u);
	t0 = std_string$starts_with(l0, l2);
	{ bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool vader_front_resolver$is_generated_file(vader_string_t l0) {
	bool t0;
	t0 = std_string$starts_with(l0, 617u);
	return t0;
}

static bool vader_front_resolver$is_host_bound(void* l0) {
	void* l1;
	int64_t l2, l3;
	void* t0;
	bool t1;
	l1 = ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_decorators;
	l2 = vader_array_length(((vader_array_t*) l1));
	l3 = INT64_C(0);
	while ((l3 < l2)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l3);
		t1 = vader_front_resolver$provides_body(t0);
		if (t1) {
			return true;
		}
		l3 = (l3 + INT64_C(1));
	}
	return false;
}

static bool vader_front_resolver$is_instance_of(vader_box_t l0, vader_string_t l1, void* l2) {
	int64_t l3, l4;
	vader_box_t l5;
	vader_string_t l6;
	void* t0;
	bool t1;
	vader_box_t t2;
	if (l0.tag == 1185u) {
		t0 = l0.payload.obj;
		t1 = vader_front_resolver$is_named(((vader_struct_toolchain_ast$GenericInstExpr_t*) t0)->f_callee, l1);
		if (t1) {
			t0 = l0.payload.obj;
			l3 = vader_array_length(((vader_array_t*) ((vader_struct_toolchain_ast$GenericInstExpr_t*) t0)->f_type_args));
			l4 = vader_array_length(((vader_array_t*) l2));
			if (l3 != l4) {
				return false;
			}
			l3 = INT64_C(0);
			l4 = vader_array_length(((vader_array_t*) l2));
			while ((l3 < l4)) {
				t0 = l0.payload.obj;
				vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$GenericInstExpr_t*) t0)->f_type_args);
				VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
				VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
				l5 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l3);
				vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
				VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
				t2 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l3];
				l6 = t2.payload.s;
				t1 = vader_front_resolver$is_named(l5, l6);
				if (!(t1)) {
					return false;
				}
				l3 = (l3 + INT64_C(1));
			}
			return true;
		}
		return false;
	}
	return false;
}

static bool vader_front_resolver$is_named(vader_box_t l0, vader_string_t l1) {
	void* t0;
	vader_string_t t1;
	if (l0.tag == 1186u) {
		t0 = l0.payload.obj;
		t1 = ((vader_struct_toolchain_ast$IdentExpr_t*) t0)->f_name;
		return t1 == l1;
	}
	return false;
}

static bool vader_front_resolver$is_private_to(vader_box_t l0, vader_string_t l1) {
	if (l1 == 0u) {
		return false;
	}
	if (!((l0.tag == 1157u || l0.tag == 1181u))) {
		return false;
	}
	return VADER_UNION_FIELD(uint8_t, vader_struct_toolchain_ast$ConstDecl_t, f_visibility, l0.payload.obj) == INT32_C(1);
}

static bool vader_front_resolver$is_proceed(vader_box_t l0, vader_string_t l1, vader_string_t l2) {
	void* t0;
	int64_t t1;
	vader_box_t t2;
	bool t3;
	if (l0.tag == 1183u) {
		t0 = l0.payload.obj;
		t1 = vader_array_length(((vader_array_t*) ((vader_struct_toolchain_ast$FnTypeExpr_t*) t0)->f_params));
		if (t1 != INT64_C(1)) {
			return false;
		}
		t0 = l0.payload.obj;
		vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$FnTypeExpr_t*) t0)->f_params);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
		t2 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT32_C(0));
		t3 = vader_front_resolver$is_named(t2, l1);
		if (t3) {
			t0 = l0.payload.obj;
			t3 = vader_front_resolver$is_named(((vader_struct_toolchain_ast$FnTypeExpr_t*) t0)->f_return_type, l2);
			return t3;
		}
		return false;
	}
	return false;
}

static bool vader_front_resolver$is_reached(vader_box_t l0, void* l1, void* l2) {
	vader_box_t l3;
	vader_string_t l4;
	bool t0;
	l3 = vader_front_resolver$declared_name(l0);
	if (!(l3.tag == 0u)) {
		l4 = l3.payload.s;
		t0 = std_collections$Set$std_core$Contains$contains__string(l1, l4);
		return t0;
	}
	l3 = vader_front_resolver$private_type_of(l0, l2);
	if (l3.tag == 0u) {
		return true;
	}
	l4 = l3.payload.s;
	t0 = std_collections$Set$std_core$Contains$contains__string(l1, l4);
	return t0;
}

static bool vader_front_resolver$is_reached_1(vader_box_t l0, vader_string_t l1, vader_string_t l2, void* l3) {
	bool l4;
	vader_string_t l5 = 0;
	bool t0;
	vader_box_t* gc_roots[1] = { &l0 };
	void** gc_raw_roots[1] = { &l3 };
	vader_string_t* gc_atom_roots[3] = { &l1, &l2, &l5 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	t0 = std_collections$Set$std_core$Contains$contains__string(l3, l1);
	if (t0) {
		t0 = vader_front_resolver$is_private_to(l0, l2);
		if (!(t0)) {
			{ vader_gc_top = gc_frame.prev; return true; }
		}
	}
	if (l2 != 0u) {
		l4 = !(l0.tag == 1190u);
	} else {
		l4 = false;
	}
	if (l4) {
		l5 = vader_front_reach$qualified_name(l2, l1);
		t0 = std_collections$Set$std_core$Contains$contains__string(l3, l5);
		{ bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	{ vader_gc_top = gc_frame.prev; return false; }
}

static bool vader_front_resolver$is_surface(vader_box_t l0, vader_string_t l1, vader_string_t l2) {
	void* l3;
	bool l4;
	bool t0;
	l3 = toolchain_ast$decl_decorators(l0);
	t0 = toolchain_ast$decl_is_public(l0);
	if (t0) {
		l4 = true;
	} else {
		l4 = vader_front_reach$is_wired_root(l3, l1);
	}
	if (l4) {
		return true;
	}
	if (l2 == 2129u) {
		l4 = l1 == 2129u;
	} else {
		l4 = false;
	}
	return l4;
}

static bool vader_front_resolver$is_test(vader_box_t l0) {
	void* t0 = NULL;
	bool t1;
	vader_box_t* gc_roots[1] = { &l0 };
	void** gc_raw_roots[1] = { &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	t0 = toolchain_ast$decl_decorators(l0);
	t1 = toolchain_ast$has_compiler_decorator(t0, (uint8_t) 23);
	{ bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_front_resolver$is_trimmed(void* l0, void* l1) {
	bool l2, l3;
	vader_string_t l4, l5;
	vader_box_t l6;
	if (((vader_struct_vader_front_resolver$DiscoveredModule_t*) l1)->f_origin == INT32_C(1)) {
		l2 = true;
	} else {
		if (!(((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_tested.tag == 0u)) {
			l4 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) l1)->f_folder;
			l5 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_tested.payload.s;
			l3 = l4 != l5;
		} else {
			l3 = false;
		}
		l2 = l3;
	}
	if (l2) {
		l4 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) l1)->f_folder;
		l6 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_prelude;
		return !(vader_box_eq(vader_box_string(642u, l4), l6));
	}
	return false;
}

bool vader_front_resolver$is_wit_module_file(vader_string_t l0) {
	bool t0;
	t0 = vader_front_resolver$is_generated_by(l0, 3755u);
	return t0;
}

vader_string_t vader_front_resolver$join_path(vader_string_t l0, vader_string_t l1) {
	vader_string_t l2 = 0;
	bool t0;
	vader_string_t t1 = 0;
	vader_string_t* gc_atom_roots[4] = { &l0, &l1, &l2, &t1 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 4u, gc_atom_roots };
	vader_gc_top = &gc_frame;
	l2 = std_string$trim_prefix(l1, 497u);
	if (l0 == 0u) {
		{ vader_string_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
	}
	t0 = std_string$ends_with(l0, 534u);
	if (!(t0)) {
		t1 = concat_3(l0, 534u, l2);
		{ vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	t1 = concat_2(l0, l2);
	{ vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_front_resolver$late_body_file(void* l0, vader_string_t l1) {
	vader_string_t l2 = 0;
	vader_string_t l3 = 0;
	vader_string_t t0 = 0;
	void** gc_raw_roots[1] = { &l0 };
	vader_string_t* gc_atom_roots[4] = { &l1, &l2, &l3, &t0 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_vader_front_resolver$LateFn_t*) l0)->f_stage;
	l3 = vader_front_resolver$late_body_origin(l0, l1);
	t0 = vader_front_resolver$generated_file(l2, l3);
	{ vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_front_resolver$late_body_origin(void* l0, vader_string_t l1) {
	vader_string_t l2 = 0;
	vader_string_t l5 = 0;
	void* l3 = NULL;
	vader_box_t l4 = vader_box_null();
	vader_string_t t0 = 0;
	vader_box_t* gc_roots[1] = { &l4 };
	void** gc_raw_roots[2] = { &l0, &l3 };
	vader_string_t* gc_atom_roots[4] = { &l1, &l2, &l5, &t0 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = vader_front_resolver$bodies_folder(l1);
	l3 = ((vader_struct_vader_front_resolver$LateFn_t*) l0)->f_decl;
	l4 = ((vader_struct_vader_front_resolver$LateFn_t*) l0)->f_owner;
	l5 = vader_front_resolver$late_fn_label(l3, l4);
	t0 = concat_3(l2, 534u, l5);
	{ vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_front_resolver$late_body_source(void* l0, vader_string_t l1, vader_string_t l2) {
	void* l3 = NULL;
	vader_box_t l4 = vader_box_null();
	vader_string_t l5 = 0;
	vader_string_t l6 = 0;
	vader_string_t l7 = 0;
	vader_string_t t0 = 0;
	vader_box_t* gc_roots[1] = { &l4 };
	void** gc_raw_roots[2] = { &l0, &l3 };
	vader_string_t* gc_atom_roots[6] = { &l1, &l2, &l5, &l6, &l7, &t0 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 6u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l3 = ((vader_struct_vader_front_resolver$LateFn_t*) l0)->f_decl;
	l4 = ((vader_struct_vader_front_resolver$LateFn_t*) l0)->f_owner;
	l5 = vader_front_resolver$late_fn_label(l3, l4);
	l6 = ((vader_struct_vader_front_resolver$LateFn_t*) l0)->f_stage;
	t0 = concat_5(539u, l6, 1383u, l5, 1697u);
	l5 = concat_4(t0, 15u, l2, 2u);
	l6 = ((vader_struct_vader_front_resolver$LateFn_t*) l0)->f_stage;
	l7 = vader_front_resolver$late_body_origin(l0, l1);
	t0 = vader_front_resolver$framed_source(l6, l7, l1, l5);
	{ vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_front_resolver$late_fn_label(void* l0, vader_box_t l1) {
	int32_t l2;
	vader_string_t l3 = 0;
	vader_string_t l8 = 0;
	int64_t l4, l6;
	void* l5 = NULL;
	vader_box_t l7 = vader_box_null();
	vader_string_t t0 = 0;
	void* t1 = NULL;
	vader_box_t* gc_roots[2] = { &l1, &l7 };
	void** gc_raw_roots[3] = { &l0, &l5, &t1 };
	vader_string_t* gc_atom_roots[3] = { &l3, &l8, &t0 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_span)->f_start)->f_line;
	if (l1.tag == 0u) {
		l3 = ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_name;
		l4 = (int64_t) vader_string_byte_len(l3);
		l5 = (void*) vader_buffer_new((size_t) (INT64_C(21) + l4));
		l4 = INT64_C(0);
		l4 = std_core$write_string_at(l5, l4, l3);
		l4 = std_core$write_string_at(l5, l4, 640u);
		l6 = ((int64_t) (int32_t) l2);
		l4 = std_core$write_int(l5, l4, l6);
		t0 = std_core$finish_buffer(l5, l4);
		{ vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	t1 = l1.payload.obj;
	l7 = toolchain_ast$impl_type_name(t1);
	if (l7.tag == 0u) {
		l3 = 2692u;
	} else {
		l3 = l7.payload.s;
	}
	l8 = ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_name;
	l4 = (int64_t) vader_string_byte_len(l3);
	l6 = (int64_t) vader_string_byte_len(l8);
	l4 = (l4 + l6);
	l5 = (void*) vader_buffer_new((size_t) (INT64_C(22) + l4));
	l4 = INT64_C(0);
	l4 = std_core$write_string_at(l5, l4, l3);
	l4 = std_core$write_string_at(l5, l4, 489u);
	l4 = std_core$write_string_at(l5, l4, l8);
	l4 = std_core$write_string_at(l5, l4, 640u);
	l6 = ((int64_t) (int32_t) l2);
	l4 = std_core$write_int(l5, l4, l6);
	t0 = std_core$finish_buffer(l5, l4);
	{ vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$late_fns_of(void* l0, vader_string_t l1, vader_string_t l2) {
	void* l3 = NULL;
	void* l4 = NULL;
	void* l5 = NULL;
	void* l9 = NULL;
	void* l10 = NULL;
	void* l13 = NULL;
	void* l14 = NULL;
	int64_t l6, l7, l11, l12;
	vader_box_t l8 = vader_box_null();
	void* t0 = NULL;
	vader_box_t* gc_roots[1] = { &l8 };
	void** gc_raw_roots[9] = { &l0, &l3, &l4, &l5, &l9, &l10, &l13, &l14, &t0 };
	vader_string_t* gc_atom_roots[2] = { &l1, &l2 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(345u, 0u, 13u, 1793u);
	l3 = (void*) _a0_arr;
	vader_struct___lambda_env_vader_front_resolver_19_t* _a1_obj = (vader_struct___lambda_env_vader_front_resolver_19_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_front_resolver_19_t));
	vader_obj_header_init(_a1_obj, 805u);
	_a1_obj->f_cap_0 = l3;
	_a1_obj->f_cap_1 = l1;
	_a1_obj->f_cap_2 = l2;
	l4 = (void*) _a1_obj;
	l5 = ((vader_struct_toolchain_ast$Program_t*) l0)->f_decls;
	l6 = vader_array_length(((vader_array_t*) l5));
	l7 = INT64_C(0);
	while ((l7 < l6)) {
		vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
		VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
		l8 = vader_array_ref_load_box(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l7);
		if (l8.tag == 1181u) {
			l9 = l8.payload.obj;
			__lambda_vader_front_resolver_18(l4, l9, vader_box_obj(0u, NULL));
		} else if (l8.tag == 1190u) {
			t0 = l8.payload.obj;
			l10 = ((vader_struct_toolchain_ast$ImplDecl_t*) t0)->f_members;
			l11 = vader_array_length(((vader_array_t*) l10));
			l12 = INT64_C(0);
			while ((l12 < l11)) {
				vader_array_t* _a3_slotarr = ((vader_array_t*) l10);
				VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
				l13 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l12);
				l14 = l8.payload.obj;
				__lambda_vader_front_resolver_18(l4, l13, vader_ref_box(l14));
				l12 = (l12 + INT64_C(1));
			}
		}
		l7 = (l7 + INT64_C(1));
	}
	{ void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_front_resolver$layer_function(vader_string_t l0, int64_t l1, int64_t l2) {
	vader_string_t t0 = 0;
	vader_string_t* gc_atom_roots[2] = { &l0, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 2u, gc_atom_roots };
	vader_gc_top = &gc_frame;
	if (l1 == INT64_C(1)) {
		{ vader_string_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (!((l1 > l2))) {
		t0 = vader_core_mangle$ranked_generated_name(l0, (uint8_t) 3, l1);
		{ vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	t0 = vader_core_mangle$generated_name(l0, (uint8_t) 0);
	{ vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$layer_origin(void* l0, void* l1) {
	void* l2 = NULL;
	vader_string_t l3 = 0;
	vader_string_t l4 = 0;
	vader_string_t l5 = 0;
	void* t0 = NULL;
	void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
	vader_string_t* gc_atom_roots[3] = { &l3, &l4, &l5 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_name_span;
	l3 = ((vader_struct_vader_front_resolver$Interception_t*) l1)->f_qualifier;
	l4 = ((vader_struct_vader_front_resolver$Interception_t*) l1)->f_name;
	l5 = ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_name;
	l3 = concat_6(3336u, l3, l4, 1628u, l5, 1307u);
	vader_struct_toolchain_diagnostics$Related_t* _a0_obj = (vader_struct_toolchain_diagnostics$Related_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_diagnostics$Related_t));
	vader_obj_header_init(_a0_obj, 1246u);
	_a0_obj->f_span = l2;
	_a0_obj->f_message = l3;
	t0 = (void*) _a0_obj;
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_front_resolver$layer_text(void* l0, vader_string_t l1, void* l2, vader_box_t l3, void* l4, int64_t l5) {
	vader_string_t l6 = 0;
	vader_string_t l7 = 0;
	vader_string_t l12 = 0;
	vader_string_t l14 = 0;
	vader_string_t l16 = 0;
	vader_string_t l17 = 0;
	vader_string_t l18 = 0;
	vader_string_t l19 = 0;
	vader_string_t l20 = 0;
	vader_string_t l21 = 0;
	void* l8 = NULL;
	void* l9 = NULL;
	void* l13 = NULL;
	void* l15 = NULL;
	int64_t l10, l11;
	int64_t t0;
	void* t1 = NULL;
	vader_string_t t2 = 0;
	vader_string_t t3 = 0;
	int32_t t4;
	vader_box_t* gc_roots[1] = { &l3 };
	void** gc_raw_roots[8] = { &l0, &l2, &l4, &l8, &l9, &l13, &l15, &t1 };
	vader_string_t* gc_atom_roots[13] = {
		&l1, &l6, &l7, &l12, &l14, &l16, &l17, &l18, &l19, &l20, &l21, &t2, &t3,
	};
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 13u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l6 = ((vader_struct_vader_front_resolver$SourceFile_t*) l0)->f_content;
	l7 = toolchain_span$text_in(VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l3.payload.obj), l6);
	l8 = ((vader_struct_toolchain_ast$FnDecl_t*) l2)->f_params;
	t0 = vader_array_length(((vader_array_t*) l8));
	vader_array_t* _a0_arr = vader_array_reserve(28u, (int64_t) t0, 0u, 642u);
	l9 = (void*) _a0_arr;
	l10 = vader_array_length(((vader_array_t*) l8));
	l11 = INT64_C(0);
	while ((l11 < l10)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l8);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		t1 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l11);
		l12 = __lambda_vader_front_resolver_23(t1);
		vader_array_push_scalar((vader_array_t*) l9, vader_box_string(642u, l12));
		l11 = (l11 + INT64_C(1));
	}
	l8 = l9;
	l10 = vader_chk_sub(i64, l5, INT64_C(1));
	vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
	VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
	VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l10)
	l9 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l10);
	l12 = ((vader_struct_vader_front_resolver$Interception_t*) l9)->f_qualifier;
	l13 = ((vader_struct_vader_front_resolver$Interception_t*) l9)->f_interceptor;
	t2 = ((vader_struct_vader_front_resolver$SourceFile_t*) l0)->f_path;
	t3 = std_path$to_path(t2);
	l14 = std_path$filename(t3);
	l10 = (int64_t) vader_string_byte_len(l14);
	l15 = (void*) vader_buffer_new((size_t) (INT64_C(21) + l10));
	l10 = INT64_C(0);
	l10 = std_core$write_string_at(l15, l10, l14);
	l10 = std_core$write_string_at(l15, l10, 563u);
	t4 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) ((vader_struct_toolchain_ast$FnDecl_t*) l2)->f_name_span)->f_start)->f_line;
	l11 = ((int64_t) (int32_t) t4);
	l10 = std_core$write_int(l15, l10, l11);
	l14 = std_core$finish_buffer(l15, l10);
	l16 = ((vader_struct_vader_front_resolver$Interception_t*) l9)->f_name;
	l16 = concat_2(l12, l16);
	l17 = ((vader_struct_vader_front_resolver$Interceptor_t*) l13)->f_state;
	l18 = vader_front_resolver$arguments_type(l6, l2);
	l17 = concat_7(l12, l17, 609u, l18, 441u, l7, 631u);
	t2 = ((vader_struct_toolchain_ast$FnDecl_t*) l2)->f_name;
	l18 = vader_core_mangle$generated_name(t2, (uint8_t) 0);
	t2 = ((vader_struct_toolchain_ast$FnDecl_t*) l2)->f_name;
	l19 = vader_core_mangle$ranked_generated_name(t2, (uint8_t) 1, l5);
	t2 = ((vader_struct_toolchain_ast$FnDecl_t*) l2)->f_name;
	l20 = vader_core_mangle$ranked_generated_name(t2, (uint8_t) 2, l5);
	vader_array_t* _a3_arr = vader_array_new(28u, 0u, 0u, 642u);
	t1 = (void*) _a3_arr;
	vader_struct_std_string__builder$StringBuilder_t* _a4_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
	vader_obj_header_init(_a4_obj, 1139u);
	_a4_obj->f_parts = t1;
	l9 = (void*) _a4_obj;
	l21 = concat_2(l20, 95u);
	std_string__builder$append(l9, l21);
	l21 = concat_3(40u, l17, 2u);
	std_string__builder$append(l9, l21);
	l21 = concat_3(39u, l16, 632u);
	std_string__builder$append(l9, l21);
	std_string__builder$append(l9, 3804u);
	std_string__builder$append(l9, 657u);
	l20 = concat_4(l19, 93u, l20, 300u);
	std_string__builder$append(l9, l20);
	l17 = concat_3(31u, l17, 304u);
	std_string__builder$append(l9, l17);
	l17 = concat_3(30u, l16, 633u);
	std_string__builder$append(l9, l17);
	t2 = ((vader_struct_toolchain_ast$FnDecl_t*) l2)->f_name;
	l17 = toolchain_lexer$quote_vader(t2);
	l17 = concat_3(24u, l17, 440u);
	std_string__builder$append(l9, l17);
	l17 = toolchain_lexer$quote_vader(l1);
	l17 = concat_3(27u, l17, 440u);
	std_string__builder$append(l9, l17);
	l14 = toolchain_lexer$quote_vader(l14);
	l14 = concat_3(25u, l14, 440u);
	std_string__builder$append(l9, l14);
	l14 = concat_5(26u, l18, 441u, l16, 419u);
	std_string__builder$append(l9, l14);
	std_string__builder$append(l9, 43u);
	std_string__builder$append(l9, 3804u);
	if (l5 == INT64_C(1)) {
		if (((vader_struct_toolchain_ast$FnDecl_t*) l2)->f_visibility == INT32_C(0)) {
			std_string__builder$append(l9, 2463u);
		}
	}
	l14 = ((vader_struct_toolchain_ast$FnDecl_t*) l2)->f_name;
	l10 = vader_array_length(((vader_array_t*) l4));
	l14 = vader_front_resolver$layer_function(l14, l5, l10);
	l16 = ((vader_struct_toolchain_ast$FnDecl_t*) l2)->f_name;
	l10 = vader_chk_add(i64, l5, INT64_C(1));
	l11 = vader_array_length(((vader_array_t*) l4));
	l16 = vader_front_resolver$layer_function(l16, l10, l11);
	l6 = toolchain_span$text_in(((vader_struct_toolchain_ast$FnDecl_t*) l2)->f_params_span, l6);
	l6 = concat_6(l14, 91u, l6, 78u, l7, 300u);
	std_string__builder$append(l9, l6);
	l6 = concat_3(35u, l19, 383u);
	std_string__builder$append(l9, l6);
	l6 = ((vader_struct_vader_front_resolver$Interceptor_t*) l13)->f_around;
	l6 = concat_4(38u, l12, l6, 392u);
	std_string__builder$append(l9, l6);
	l6 = vader_front_resolver$tupled(l8);
	t0 = vader_array_length(((vader_array_t*) l8));
	l7 = vader_front_resolver$spread(t0);
	l6 = concat_6(l6, 442u, l16, 377u, l7, 417u);
	std_string__builder$append(l9, l6);
	std_string__builder$append(l9, 3804u);
	t2 = std_string__builder$StringBuilder$std_core$Display$to_string(l9);
	{ vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

void vader_front_resolver$link_generated_origins(void* l0, void* l1) {
	void* l2 = NULL;
	void* l6 = NULL;
	void* l7 = NULL;
	void* l8 = NULL;
	void* l11 = NULL;
	void* l13 = NULL;
	void* l18 = NULL;
	void* l20 = NULL;
	void* l21 = NULL;
	void* l22 = NULL;
	void* l23 = NULL;
	void* l24 = NULL;
	bool l3;
	int64_t l4, l5, l9, l10, l15, l16;
	vader_string_t l12 = 0;
	vader_string_t l19 = 0;
	vader_box_t l14 = vader_box_null();
	uint8_t l17;
	void* t0 = NULL;
	bool t1;
	vader_box_t t2 = vader_box_null();
	vader_string_t t3 = 0;
	int64_t t4;
	vader_box_t* gc_roots[2] = { &l14, &t2 };
	void** gc_raw_roots[15] = {
		&l0, &l1, &l2, &l6, &l7, &l8, &l11, &l13, &l18, &l20, &l21, &l22, &l23, &l24, &t0,
	};
	vader_string_t* gc_atom_roots[3] = { &l12, &l19, &t3 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 15u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = l0;
	l3 = false;
	l4 = vader_array_length(((vader_array_t*) l2));
	l5 = INT64_C(0);
	{
		while ((l5 < l4)) {
			vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
			VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
			t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
			t1 = __lambda_vader_front_resolver_2(t0);
			if (t1) {
				l3 = true;
				goto end_9;
			}
			l5 = (l5 + INT64_C(1));
		}
		l3 = false;
	} end_9: ;
	if (!(l3)) {
		{ vader_gc_top = gc_frame.prev; return; }
	}
	vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 642u);
	l2 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(35u, 0u, 0u, 653u);
	l6 = (void*) _a2_arr;
	vader_array_t* _a3_arr = vader_array_new(29u, 0u, 7u, 645u);
	l7 = (void*) _a3_arr;
	vader_struct_std_collections$Map__string__Any___t* _a4_obj = (vader_struct_std_collections$Map__string__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any___t));
	vader_obj_header_init(_a4_obj, 1005u);
	_a4_obj->f_ekeys = l2;
	_a4_obj->f_evals = l6;
	_a4_obj->f_index = l7;
	_a4_obj->f_mask = INT64_C(0);
	_a4_obj->f_grow_at = INT64_C(0);
	_a4_obj->f_size = INT64_C(0);
	_a4_obj->f_tombs = INT64_C(0);
	l2 = (void*) _a4_obj;
	l6 = ((vader_struct_vader_front_resolver$LoadedProject_t*) l1)->f_modules;
	l7 = ((vader_struct_std_collections$Map__string__vader_front_resolver_LoadedModule_t*) l6)->f_ekeys;
	l8 = ((vader_struct_std_collections$Map__string__vader_front_resolver_LoadedModule_t*) l6)->f_evals;
	l4 = INT64_C(0);
	l5 = ((vader_struct_std_collections$Map__string__vader_front_resolver_LoadedModule_t*) l6)->f_size;
	while ((l4 < l5)) {
		vader_array_t* _a5_slotarr = ((vader_array_t*) l7);
		VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
		t2 = vader_array_box_slots(_a5_slotarr->buf)[vader_array_offset(_a5_slotarr) + (size_t) l4];
		t3 = t2.payload.s;
		vader_array_t* _a6_slotarr = ((vader_array_t*) l8);
		VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l4)
		t0 = vader_array_ref_load_obj(_a6_slotarr->buf, vader_array_offset(_a6_slotarr) + (size_t) l4);
		l6 = ((vader_struct_vader_front_resolver$Module_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) t0)->f_module)->f_files;
		l9 = vader_array_length(((vader_array_t*) l6));
		l10 = INT64_C(0);
		while ((l10 < l9)) {
			vader_array_t* _a7_slotarr = ((vader_array_t*) l6);
			VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
			l11 = vader_array_ref_load_obj(_a7_slotarr->buf, vader_array_offset(_a7_slotarr) + (size_t) l10);
			t1 = std_core$is_empty__vader_front_resolver_CodeOrigin(((vader_struct_vader_front_resolver$SourceFile_t*) l11)->f_origins);
			if (!(t1)) {
				l12 = ((vader_struct_vader_front_resolver$SourceFile_t*) l11)->f_path;
				l13 = ((vader_struct_vader_front_resolver$SourceFile_t*) l11)->f_origins;
				std_collections$Map$std_core$IndexSet$set_at__string__Any(l2, l12, vader_ref_box(l13));
			}
			l10 = (l10 + INT64_C(1));
		}
		l4 = (l4 + INT64_C(1));
	}
	l4 = INT64_C(0);
	l5 = vader_array_length(((vader_array_t*) l0));
	while ((l4 < l5)) {
		vader_array_t* _a8_slotarr = ((vader_array_t*) l0);
		VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
		l6 = vader_array_ref_load_obj(_a8_slotarr->buf, vader_array_offset(_a8_slotarr) + (size_t) l4);
		l12 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) ((vader_struct_toolchain_diagnostics$Diagnostic_t*) l6)->f_primary)->f_start)->f_file;
		l14 = std_collections$Map$std_core$Index$at__string__Any(l2, l12);
		if (l14.tag == 0u) {
			l4 = (l4 + INT64_C(1));
			continue;
		}
		l7 = l14.payload.obj;
		l9 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) ((vader_struct_toolchain_diagnostics$Diagnostic_t*) l6)->f_primary)->f_start)->f_offset;
		l8 = l7;
		l10 = vader_array_length(((vader_array_t*) l8));
		l15 = INT64_C(0);
		while ((l15 < l10)) {
			vader_array_t* _a9_slotarr = ((vader_array_t*) l8);
			VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
			l11 = vader_array_ref_load_obj(_a9_slotarr->buf, vader_array_offset(_a9_slotarr) + (size_t) l15);
			t4 = ((vader_struct_vader_front_resolver$CodeOrigin_t*) l11)->f_start;
			if ((t4 <= l9)) {
				l16 = ((vader_struct_vader_front_resolver$CodeOrigin_t*) l11)->f_end;
				if ((l9 < l16)) {
					l13 = l6;
					l17 = ((vader_struct_toolchain_diagnostics$Diagnostic_t*) l13)->f_severity;
					l18 = ((vader_struct_toolchain_diagnostics$Diagnostic_t*) l13)->f_code;
					l19 = ((vader_struct_toolchain_diagnostics$Diagnostic_t*) l13)->f_detail;
					l20 = ((vader_struct_toolchain_diagnostics$Diagnostic_t*) l13)->f_primary;
					l21 = ((vader_struct_toolchain_diagnostics$Diagnostic_t*) l6)->f_related;
					vader_array_t* _a10_arr = vader_array_new(94u, 1u, 13u, 1246u);
					((void**) _a10_arr->buf->slots)[vader_array_offset(_a10_arr) + 0u] = ((vader_struct_vader_front_resolver$CodeOrigin_t*) l11)->f_origin;
					l22 = (void*) _a10_arr;
					l23 = std_core$$array$Add$add__toolchain_diagnostics_Related(l21, l22);
					vader_struct_toolchain_diagnostics$Diagnostic_t* _a11_obj = (vader_struct_toolchain_diagnostics$Diagnostic_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_diagnostics$Diagnostic_t));
					vader_obj_header_init(_a11_obj, 1245u);
					_a11_obj->f_severity = l17;
					_a11_obj->f_code = l18;
					_a11_obj->f_detail = l19;
					_a11_obj->f_primary = l20;
					_a11_obj->f_related = l23;
					l24 = (void*) _a11_obj;
					vader_array_t* _a12_slotarr = ((vader_array_t*) l0);
					VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
					vader_array_ref_store(_a12_slotarr->buf, vader_array_offset(_a12_slotarr) + (size_t) l4, l24);
					VADER_WRITE_BARRIER(_a12_slotarr->buf);
					break;
				}
			}
			l15 = (l15 + INT64_C(1));
		}
		l4 = (l4 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return; }
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
	void* l21 = NULL;
	void* l22 = NULL;
	void* l23 = NULL;
	void* l24 = NULL;
	void* l25 = NULL;
	void* l26 = NULL;
	vader_box_t l3 = vader_box_null(), l19 = vader_box_null(), l27 = vader_box_null();
	vader_string_t l5 = 0;
	vader_string_t l10 = 0;
	vader_string_t l11 = 0;
	vader_string_t l12 = 0;
	int64_t l8, l9;
	bool l18, l20;
	bool t0;
	vader_box_t t1 = vader_box_null();
	vader_box_t* gc_roots[4] = { &l3, &l19, &l27, &t1 };
	void** gc_raw_roots[17] = {
		&l0, &l1, &l2, &l4, &l6, &l7, &l13, &l14, &l15, &l16, &l17, &l21, &l22, &l23, &l24, &l25,
		&l26,
	};
	vader_string_t* gc_atom_roots[4] = { &l5, &l10, &l11, &l12 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 4u, 17u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l3 = vader_front_resolver$resolve_in(l0, 3212u);
	if (l3.tag == 0u) {
		{ vader_gc_top = gc_frame.prev; return; }
	}
	l2 = l3.payload.obj;
	l4 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_modules;
	l5 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) l2)->f_folder;
	t0 = vader_front_resolver$has_module(l4, l5);
	if (!(t0)) {
		vader_array_t* _a0_arr = vader_array_new(336u, 1u, 13u, 1777u);
		((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = l2;
		l2 = (void*) _a0_arr;
		vader_front_resolver$drain_load_queue(l0, l2);
	}
	vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 642u);
	l2 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(28u, 0u, 0u, 642u);
	l4 = (void*) _a2_arr;
	vader_array_t* _a3_arr = vader_array_new(29u, 0u, 7u, 645u);
	l6 = (void*) _a3_arr;
	vader_struct_std_collections$Map__string__string_t* _a4_obj = (vader_struct_std_collections$Map__string__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__string_t));
	vader_obj_header_init(_a4_obj, 1028u);
	_a4_obj->f_ekeys = l2;
	_a4_obj->f_evals = l4;
	_a4_obj->f_index = l6;
	_a4_obj->f_mask = INT64_C(0);
	_a4_obj->f_grow_at = INT64_C(0);
	_a4_obj->f_size = INT64_C(0);
	_a4_obj->f_tombs = INT64_C(0);
	l2 = (void*) _a4_obj;
	l4 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_overlay;
	l6 = ((vader_struct_std_collections$Map__string__string_t*) l4)->f_ekeys;
	l7 = ((vader_struct_std_collections$Map__string__string_t*) l4)->f_evals;
	l8 = INT64_C(0);
	l9 = ((vader_struct_std_collections$Map__string__string_t*) l4)->f_size;
	while ((l8 < l9)) {
		vader_array_t* _a5_slotarr = ((vader_array_t*) l6);
		VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l8)
		t1 = vader_array_box_slots(_a5_slotarr->buf)[vader_array_offset(_a5_slotarr) + (size_t) l8];
		l5 = t1.payload.s;
		vader_array_t* _a6_slotarr = ((vader_array_t*) l7);
		VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l8)
		t1 = vader_array_box_slots(_a6_slotarr->buf)[vader_array_offset(_a6_slotarr) + (size_t) l8];
		l10 = t1.payload.s;
		l11 = l5;
		l12 = l10;
		std_collections$Map$std_core$IndexSet$set_at__string__string(l2, l11, l12);
		l8 = (l8 + INT64_C(1));
	}
	l5 = vader_support_target$baked_module_source(l1);
	std_collections$Map$std_core$IndexSet$set_at__string__string(l2, 613u, l5);
	vader_array_t* _a7_arr = vader_array_new(28u, 1u, 0u, 642u);
	vader_array_box_slots(_a7_arr->buf)[vader_array_offset(_a7_arr) + 0u] = vader_box_string(642u, 613u);
	l4 = (void*) _a7_arr;
	vader_array_t* _a8_arr = vader_array_new(28u, 0u, 0u, 642u);
	l6 = (void*) _a8_arr;
	vader_array_t* _a9_arr = vader_array_new(28u, 0u, 0u, 642u);
	l7 = (void*) _a9_arr;
	vader_array_t* _a10_arr = vader_array_new(29u, 0u, 7u, 645u);
	l13 = (void*) _a10_arr;
	vader_struct_std_collections$Map__string__string_t* _a11_obj = (vader_struct_std_collections$Map__string__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__string_t));
	vader_obj_header_init(_a11_obj, 1028u);
	_a11_obj->f_ekeys = l6;
	_a11_obj->f_evals = l7;
	_a11_obj->f_index = l13;
	_a11_obj->f_mask = INT64_C(0);
	_a11_obj->f_grow_at = INT64_C(0);
	_a11_obj->f_size = INT64_C(0);
	_a11_obj->f_tombs = INT64_C(0);
	l6 = (void*) _a11_obj;
	vader_struct_vader_front_resolver$DiscoveredModule_t* _a12_obj = (vader_struct_vader_front_resolver$DiscoveredModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$DiscoveredModule_t));
	vader_obj_header_init(_a12_obj, 1777u);
	_a12_obj->f_name = 3213u;
	_a12_obj->f_folder = 612u;
	_a12_obj->f_files = l4;
	_a12_obj->f_origin = (uint8_t) 1;
	_a12_obj->f_texts = l6;
	l4 = (void*) _a12_obj;
	l6 = l0;
	l7 = ((vader_struct_vader_front_resolver$LoadState_t*) l6)->f_bases;
	l13 = ((vader_struct_vader_front_resolver$LoadState_t*) l6)->f_modules;
	l14 = ((vader_struct_vader_front_resolver$LoadState_t*) l6)->f_factory;
	l15 = ((vader_struct_vader_front_resolver$LoadState_t*) l6)->f_index;
	l16 = ((vader_struct_vader_front_resolver$LoadState_t*) l6)->f_diags;
	l17 = ((vader_struct_vader_front_resolver$LoadState_t*) l6)->f_node_factory;
	l3 = ((vader_struct_vader_front_resolver$LoadState_t*) l6)->f_selected_target;
	l18 = ((vader_struct_vader_front_resolver$LoadState_t*) l6)->f_keep_docs;
	l19 = ((vader_struct_vader_front_resolver$LoadState_t*) l6)->f_tested;
	l20 = ((vader_struct_vader_front_resolver$LoadState_t*) l6)->f_only_reached;
	l21 = ((vader_struct_vader_front_resolver$LoadState_t*) l6)->f_deferred;
	l22 = ((vader_struct_vader_front_resolver$LoadState_t*) l6)->f_source_stages;
	l23 = ((vader_struct_vader_front_resolver$LoadState_t*) l6)->f_body_stages;
	l24 = ((vader_struct_vader_front_resolver$LoadState_t*) l6)->f_module_server;
	l25 = ((vader_struct_vader_front_resolver$LoadState_t*) l6)->f_late_fns;
	l26 = ((vader_struct_vader_front_resolver$LoadState_t*) l6)->f_uncovered;
	l27 = ((vader_struct_vader_front_resolver$LoadState_t*) l6)->f_prelude;
	vader_struct_vader_front_resolver$LoadState_t* _a13_obj = (vader_struct_vader_front_resolver$LoadState_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$LoadState_t));
	vader_obj_header_init(_a13_obj, 1795u);
	_a13_obj->f_bases = l7;
	_a13_obj->f_modules = l13;
	_a13_obj->f_factory = l14;
	_a13_obj->f_index = l15;
	_a13_obj->f_diags = l16;
	_a13_obj->f_overlay = l2;
	_a13_obj->f_node_factory = l17;
	_a13_obj->f_selected_target = l3;
	_a13_obj->f_keep_docs = l18;
	_a13_obj->f_tested = l19;
	_a13_obj->f_only_reached = l20;
	_a13_obj->f_deferred = l21;
	_a13_obj->f_source_stages = l22;
	_a13_obj->f_body_stages = l23;
	_a13_obj->f_module_server = l24;
	_a13_obj->f_late_fns = l25;
	_a13_obj->f_uncovered = l26;
	_a13_obj->f_prelude = l27;
	l2 = (void*) _a13_obj;
	vader_array_t* _a14_arr = vader_array_new(336u, 1u, 13u, 1777u);
	((void**) _a14_arr->buf->slots)[vader_array_offset(_a14_arr) + 0u] = l4;
	l4 = (void*) _a14_arr;
	vader_front_resolver$drain_load_queue(l2, l4);
	{ vader_gc_top = gc_frame.prev; return; }
}

void* vader_front_resolver$load_project(vader_string_t l0, void* l1, vader_box_t l2, vader_box_t l3, bool l4, bool l5, bool l6) {
	void* l7 = NULL;
	void* l8 = NULL;
	void* l9 = NULL;
	void* t0 = NULL;
	vader_box_t* gc_roots[2] = { &l2, &l3 };
	void** gc_raw_roots[5] = { &l1, &l7, &l8, &l9, &t0 };
	vader_string_t* gc_atom_roots[1] = { &l0 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
	l7 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 642u);
	l8 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 645u);
	l9 = (void*) _a2_arr;
	vader_struct_std_collections$Map__string__string_t* _a3_obj = (vader_struct_std_collections$Map__string__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__string_t));
	vader_obj_header_init(_a3_obj, 1028u);
	_a3_obj->f_ekeys = l7;
	_a3_obj->f_evals = l8;
	_a3_obj->f_index = l9;
	_a3_obj->f_mask = INT64_C(0);
	_a3_obj->f_grow_at = INT64_C(0);
	_a3_obj->f_size = INT64_C(0);
	_a3_obj->f_tombs = INT64_C(0);
	l7 = (void*) _a3_obj;
	vader_array_t* _a4_arr = vader_array_new(28u, 0u, 0u, 642u);
	l8 = (void*) _a4_arr;
	t0 = vader_front_resolver$load_project_with_overlay(l0, l7, l1, l2, l3, l8, l6, l4, l5);
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$load_project_with_overlay(vader_string_t l0, void* l1, void* l2, vader_box_t l3, vader_box_t l4, void* l5, bool l6, bool l7, bool l8) {
	void* l9 = NULL;
	void* l14 = NULL;
	void* l15 = NULL;
	void* l16 = NULL;
	void* l17 = NULL;
	void* l18 = NULL;
	void* l19 = NULL;
	void* l20 = NULL;
	void* l21 = NULL;
	void* l23 = NULL;
	void* l24 = NULL;
	void* l25 = NULL;
	void* l27 = NULL;
	void* l28 = NULL;
	vader_string_t l10 = 0;
	vader_string_t l22 = 0;
	vader_box_t l11 = vader_box_null(), l12 = vader_box_null(), l13 = vader_box_null(), l26 = vader_box_null();
	int64_t l29, l30;
	void* t0 = NULL;
	vader_string_t t1 = 0;
	vader_box_t t2 = vader_box_null();
	vader_box_t* gc_roots[7] = { &l3, &l4, &l11, &l12, &l13, &l26, &t2 };
	void** gc_raw_roots[18] = {
		&l1, &l2, &l5, &l9, &l14, &l15, &l16, &l17, &l18, &l19, &l20, &l21, &l23, &l24, &l25, &l27,
		&l28, &t0,
	};
	vader_string_t* gc_atom_roots[4] = { &l0, &l10, &l22, &t1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 7u, 18u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_struct_vader_core_symbol$SymbolFactory_t* _a0_obj = (vader_struct_vader_core_symbol$SymbolFactory_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_symbol$SymbolFactory_t));
	vader_obj_header_init(_a0_obj, 1492u);
	_a0_obj->f_next = INT32_C(1);
	l9 = (void*) _a0_obj;
	l10 = std_path$to_posix(l0);
	l11 = vader_front_resolver$posix_or_null(l3);
	l13 = l4;
	if (l13.tag == 0u) {
		t0 = vader_support_target$host_target();
		l12 = vader_ref_box(t0);
	} else {
		l12 = l13;
	}
	l14 = vader_front_resolver$baked_target_of(l12);
	l12 = vader_front_resolver$selected_target_of(l12);
	vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 642u);
	l15 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(35u, 0u, 0u, 653u);
	l16 = (void*) _a2_arr;
	vader_array_t* _a3_arr = vader_array_new(29u, 0u, 7u, 645u);
	l17 = (void*) _a3_arr;
	vader_struct_std_collections$Map__string__Any_t* _a4_obj = (vader_struct_std_collections$Map__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any_t));
	vader_obj_header_init(_a4_obj, 1004u);
	_a4_obj->f_ekeys = l15;
	_a4_obj->f_evals = l16;
	_a4_obj->f_index = l17;
	_a4_obj->f_mask = INT64_C(0);
	_a4_obj->f_grow_at = INT64_C(0);
	_a4_obj->f_size = INT64_C(0);
	_a4_obj->f_tombs = INT64_C(0);
	l15 = (void*) _a4_obj;
	vader_array_t* _a5_arr = vader_array_new(93u, 0u, 13u, 1245u);
	l16 = (void*) _a5_arr;
	vader_array_t* _a6_arr = vader_array_new(93u, 0u, 13u, 1245u);
	l17 = (void*) _a6_arr;
	l18 = vader_front_resolver$search_roots(l10, l2, l11, l1, l17);
	vader_array_t* _a7_arr = vader_array_new(28u, 0u, 0u, 642u);
	l19 = (void*) _a7_arr;
	vader_array_t* _a8_arr = vader_array_new(35u, 0u, 0u, 653u);
	l20 = (void*) _a8_arr;
	vader_array_t* _a9_arr = vader_array_new(29u, 0u, 7u, 645u);
	l21 = (void*) _a9_arr;
	vader_struct_std_collections$Map__string__Any_t* _a10_obj = (vader_struct_std_collections$Map__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any_t));
	vader_obj_header_init(_a10_obj, 1004u);
	_a10_obj->f_ekeys = l19;
	_a10_obj->f_evals = l20;
	_a10_obj->f_index = l21;
	_a10_obj->f_mask = INT64_C(0);
	_a10_obj->f_grow_at = INT64_C(0);
	_a10_obj->f_size = INT64_C(0);
	_a10_obj->f_tombs = INT64_C(0);
	l19 = (void*) _a10_obj;
	l13 = ((vader_struct_vader_front_resolver$SearchRoots_t*) l18)->f_entry;
	if (l13.tag == 0u) {
		vader_array_push_all((vader_array_t*) l16, (vader_array_t*) l17);
		l22 = vader_front_resolver$entry_folder_of(l10);
		l17 = vader_front_resolver$zero_span(l10);
		l10 = std_path$to_native(l22);
		t1 = concat_3(2965u, l10, 1387u);
		l10 = concat_2(t1, 1948u);
		l17 = toolchain_diagnostics$resolver_error((uint8_t) 0, l17, l10);
		vader_array_push_ref((vader_array_t*) l16, l17);
		vader_array_t* _a11_arr = vader_array_new(345u, 0u, 13u, 1793u);
		l17 = (void*) _a11_arr;
		vader_array_t* _a12_arr = vader_array_new(36u, 0u, 0u, 660u);
		l20 = (void*) _a12_arr;
		vader_array_t* _a13_arr = vader_array_new(339u, 0u, 13u, 1785u);
		l21 = (void*) _a13_arr;
		vader_array_t* _a14_arr = vader_array_new(28u, 0u, 0u, 642u);
		l23 = (void*) _a14_arr;
		vader_array_t* _a15_arr = vader_array_new(35u, 0u, 0u, 653u);
		l24 = (void*) _a15_arr;
		vader_array_t* _a16_arr = vader_array_new(29u, 0u, 7u, 645u);
		l25 = (void*) _a16_arr;
		vader_struct_std_collections$Map__string__Any_t* _a17_obj = (vader_struct_std_collections$Map__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any_t));
		vader_obj_header_init(_a17_obj, 1004u);
		_a17_obj->f_ekeys = l23;
		_a17_obj->f_evals = l24;
		_a17_obj->f_index = l25;
		_a17_obj->f_mask = INT64_C(0);
		_a17_obj->f_grow_at = INT64_C(0);
		_a17_obj->f_size = INT64_C(0);
		_a17_obj->f_tombs = INT64_C(0);
		l23 = (void*) _a17_obj;
		vader_array_t* _a18_arr = vader_array_new(355u, 0u, 13u, 1820u);
		l24 = (void*) _a18_arr;
		vader_struct_vader_front_resolver$LoadedProject_t* _a19_obj = (vader_struct_vader_front_resolver$LoadedProject_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$LoadedProject_t));
		vader_obj_header_init(_a19_obj, 1797u);
		_a19_obj->f_entry = l22;
		_a19_obj->f_modules = l15;
		_a19_obj->f_factory = l9;
		_a19_obj->f_project_root = l11;
		_a19_obj->f_diags = l16;
		_a19_obj->f_late_fns = l17;
		_a19_obj->f_body_stages = l20;
		_a19_obj->f_given_bodies = l21;
		_a19_obj->f_wit_interfaces = l23;
		_a19_obj->f_uncovered = l24;
		_a19_obj->f_under_test = false;
		t0 = (void*) _a19_obj;
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (!(l13.tag == 1777u)) {
		vader_unreachable("non-exhaustive match (T3013 should have caught this)");
	}
	l17 = ((vader_struct_vader_front_resolver$SearchRoots_t*) l18)->f_paths;
	l20 = toolchain_parser$new_node_id_factory();
	if (l7) {
		t0 = l13.payload.obj;
		t1 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) t0)->f_folder;
		l26 = vader_box_string(642u, t1);
	} else {
		l26 = vader_box_obj(0u, NULL);
	}
	vader_array_t* _a20_arr = vader_array_new(335u, 0u, 13u, 1776u);
	l21 = (void*) _a20_arr;
	l23 = vader_front_resolver$planned_source_stages(l11);
	l24 = vader_front_resolver$planned_body_stages(l11);
	l18 = ((vader_struct_vader_front_resolver$SearchRoots_t*) l18)->f_paths;
	vader_array_t* _a21_arr = vader_array_new(28u, 0u, 0u, 642u);
	l25 = (void*) _a21_arr;
	vader_array_t* _a22_arr = vader_array_new(35u, 0u, 0u, 653u);
	l27 = (void*) _a22_arr;
	vader_array_t* _a23_arr = vader_array_new(29u, 0u, 7u, 645u);
	l28 = (void*) _a23_arr;
	vader_struct_std_collections$Map__string__Any_t* _a24_obj = (vader_struct_std_collections$Map__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any_t));
	vader_obj_header_init(_a24_obj, 1004u);
	_a24_obj->f_ekeys = l25;
	_a24_obj->f_evals = l27;
	_a24_obj->f_index = l28;
	_a24_obj->f_mask = INT64_C(0);
	_a24_obj->f_grow_at = INT64_C(0);
	_a24_obj->f_size = INT64_C(0);
	_a24_obj->f_tombs = INT64_C(0);
	t0 = (void*) _a24_obj;
	vader_struct_vader_front_resolver$WitStage_t* _a25_obj = (vader_struct_vader_front_resolver$WitStage_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$WitStage_t));
	vader_obj_header_init(_a25_obj, 1822u);
	_a25_obj->f_packages = t0;
	l25 = (void*) _a25_obj;
	l18 = vader_front_resolver$module_server_for(l18, l25);
	vader_array_t* _a26_arr = vader_array_new(345u, 0u, 13u, 1793u);
	l25 = (void*) _a26_arr;
	vader_array_t* _a27_arr = vader_array_new(355u, 0u, 13u, 1820u);
	l27 = (void*) _a27_arr;
	vader_struct_vader_front_resolver$LoadState_t* _a28_obj = (vader_struct_vader_front_resolver$LoadState_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$LoadState_t));
	vader_obj_header_init(_a28_obj, 1795u);
	_a28_obj->f_bases = l17;
	_a28_obj->f_modules = l15;
	_a28_obj->f_factory = l9;
	_a28_obj->f_index = l19;
	_a28_obj->f_diags = l16;
	_a28_obj->f_overlay = l1;
	_a28_obj->f_node_factory = l20;
	_a28_obj->f_selected_target = l12;
	_a28_obj->f_keep_docs = l6;
	_a28_obj->f_tested = l26;
	_a28_obj->f_only_reached = l8;
	_a28_obj->f_deferred = l21;
	_a28_obj->f_source_stages = l23;
	_a28_obj->f_body_stages = l24;
	_a28_obj->f_module_server = l18;
	_a28_obj->f_late_fns = l25;
	_a28_obj->f_uncovered = l27;
	_a28_obj->f_prelude = vader_box_obj(0u, NULL);
	l17 = (void*) _a28_obj;
	t0 = l13.payload.obj;
	l10 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) t0)->f_name;
	l12 = vader_front_resolver$resolve_in(l17, l10);
	if (l12.tag == 0u) {
		l18 = l13.payload.obj;
	} else {
		l18 = l12.payload.obj;
	}
	vader_array_t* _a29_arr = vader_array_new(336u, 1u, 13u, 1777u);
	((void**) _a29_arr->buf->slots)[vader_array_offset(_a29_arr) + 0u] = l18;
	l18 = (void*) _a29_arr;
	l12 = vader_front_resolver$resolve_in(l17, 3209u);
	if (l12.tag == 1777u) {
		t0 = l12.payload.obj;
		l10 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) t0)->f_folder;
		((vader_struct_vader_front_resolver$LoadState_t*) l17)->f_prelude = vader_box_string(642u, l10);
		VADER_WRITE_BARRIER((vader_struct_vader_front_resolver$LoadState_t*) l17);
		t0 = l12.payload.obj;
		l10 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) t0)->f_folder;
		t0 = l13.payload.obj;
		l22 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) t0)->f_folder;
		if (l10 != l22) {
			l20 = l12.payload.obj;
			vader_array_push_ref((vader_array_t*) l18, l20);
		}
	}
	vader_front_resolver$drain_load_queue(l17, l18);
	vader_array_t* _a30_arr = vader_array_new(336u, 0u, 13u, 1777u);
	l18 = (void*) _a30_arr;
	l20 = l5;
	l29 = vader_array_length(((vader_array_t*) l20));
	l30 = INT64_C(0);
	while ((l30 < l29)) {
		vader_array_t* _a31_slotarr = ((vader_array_t*) l20);
		VADER_ARRAY_RESOLVE_BUF(_a31_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a31_slotarr, l30)
		t2 = vader_array_box_slots(_a31_slotarr->buf)[vader_array_offset(_a31_slotarr) + (size_t) l30];
		l10 = t2.payload.s;
		l12 = vader_front_resolver$resolve_in(l17, l10);
		if (l12.tag == 0u) {
			l30 = (l30 + INT64_C(1));
			continue;
		}
		l21 = l12.payload.obj;
		vader_array_push_ref((vader_array_t*) l18, l21);
		l30 = (l30 + INT64_C(1));
	}
	vader_front_resolver$drain_load_queue(l17, l18);
	vader_front_resolver$load_baked_target(l17, l14);
	vader_front_resolver$collect_deferred(l17);
	vader_front_resolver$detect_import_cycles(l15, l19, l16);
	t0 = l13.payload.obj;
	l10 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) t0)->f_folder;
	l14 = ((vader_struct_vader_front_resolver$LoadState_t*) l17)->f_late_fns;
	l18 = ((vader_struct_vader_front_resolver$LoadState_t*) l17)->f_body_stages;
	vader_array_t* _a32_arr = vader_array_new(339u, 0u, 13u, 1785u);
	l19 = (void*) _a32_arr;
	l20 = vader_front_resolver$read_interfaces(((vader_struct_vader_front_resolver$LoadState_t*) l17)->f_module_server);
	l17 = ((vader_struct_vader_front_resolver$LoadState_t*) l17)->f_uncovered;
	vader_struct_vader_front_resolver$LoadedProject_t* _a33_obj = (vader_struct_vader_front_resolver$LoadedProject_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$LoadedProject_t));
	vader_obj_header_init(_a33_obj, 1797u);
	_a33_obj->f_entry = l10;
	_a33_obj->f_modules = l15;
	_a33_obj->f_factory = l9;
	_a33_obj->f_project_root = l11;
	_a33_obj->f_diags = l16;
	_a33_obj->f_late_fns = l14;
	_a33_obj->f_body_stages = l18;
	_a33_obj->f_given_bodies = l19;
	_a33_obj->f_wit_interfaces = l20;
	_a33_obj->f_uncovered = l17;
	_a33_obj->f_under_test = l7;
	t0 = (void*) _a33_obj;
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_front_resolver$load_stage_imports(void* l0, int64_t l1, int64_t l2) {
	void* l3 = NULL;
	void* l5 = NULL;
	void* l6 = NULL;
	void* l7 = NULL;
	void* l10 = NULL;
	void* l11 = NULL;
	void* l12 = NULL;
	void* l13 = NULL;
	void* l14 = NULL;
	void* l15 = NULL;
	void* l16 = NULL;
	void* l17 = NULL;
	void* l20 = NULL;
	void* l21 = NULL;
	void* l22 = NULL;
	int64_t l4, l8, l9, l18, l19;
	vader_string_t l23 = 0;
	vader_box_t l24 = vader_box_null();
	void* t0 = NULL;
	bool t1;
	vader_box_t* gc_roots[1] = { &l24 };
	void** gc_raw_roots[17] = {
		&l0, &l3, &l5, &l6, &l7, &l10, &l11, &l12, &l13, &l14, &l15, &l16, &l17, &l20, &l21, &l22,
		&t0,
	};
	vader_string_t* gc_atom_roots[1] = { &l23 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 17u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(336u, 0u, 13u, 1777u);
	l3 = (void*) _a0_arr;
	l4 = l1;
	while ((l4 < l2)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_deferred);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
		t0 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l4);
		l6 = ((vader_struct_vader_front_resolver$DeferredModule_t*) t0)->f_sources;
		vader_array_t* _a2_arr = vader_array_new(352u, 0u, 13u, 1814u);
		l7 = (void*) _a2_arr;
		l8 = vader_array_length(((vader_array_t*) l6));
		l9 = INT64_C(0);
		while ((l9 < l8)) {
			vader_array_t* _a3_slotarr = ((vader_array_t*) l6);
			VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
			l10 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l9);
			t1 = __lambda_vader_front_resolver_9(l10);
			if (t1) {
				l11 = l10;
				vader_array_push_ref((vader_array_t*) l7, l11);
			}
			l9 = (l9 + INT64_C(1));
		}
		l5 = l7;
		l12 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_bases;
		l13 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_index;
		l14 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_overlay;
		l15 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_diags;
		l16 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_module_server;
		vader_front_resolver$preresolve_imports(l5, l12, l13, l14, l15, l16);
		l17 = vader_front_resolver$import_paths_of(l5);
		l18 = vader_array_length(((vader_array_t*) l17));
		l19 = INT64_C(0);
		while ((l19 < l18)) {
			vader_array_t* _a4_slotarr = ((vader_array_t*) l17);
			VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
			l20 = vader_array_ref_load_obj(_a4_slotarr->buf, vader_array_offset(_a4_slotarr) + (size_t) l19);
			l22 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_index;
			l23 = ((vader_struct_vader_front_resolver$ImportPath_t*) l20)->f_path;
			l24 = std_collections$Map$std_core$Index$at__string__Any(l22, l23);
			if (l24.tag == 0u) {
				l19 = (l19 + INT64_C(1));
				continue;
			}
			l21 = l24.payload.obj;
			vader_array_push_ref((vader_array_t*) l3, l21);
			l19 = (l19 + INT64_C(1));
		}
		l4 = (l4 + INT64_C(1));
	}
	vader_front_resolver$drain_load_queue(l0, l3);
	{ vader_gc_top = gc_frame.prev; return; }
}

static void* vader_front_resolver$loaded_module(void* l0, void* l1, void* l2) {
	vader_string_t l3 = 0;
	vader_string_t l4 = 0;
	vader_string_t l5 = 0;
	uint8_t l6;
	void* l7 = NULL;
	void* l8 = NULL;
	void* l9 = NULL;
	void* l10 = NULL;
	void* l11 = NULL;
	void* l13 = NULL;
	bool l12;
	void* t0 = NULL;
	void** gc_raw_roots[10] = { &l0, &l1, &l2, &l7, &l8, &l9, &l10, &l11, &l13, &t0 };
	vader_string_t* gc_atom_roots[3] = { &l3, &l4, &l5 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 10u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l3 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) ((vader_struct_vader_front_resolver$DeferredModule_t*) l1)->f_found)->f_folder;
	l4 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) ((vader_struct_vader_front_resolver$DeferredModule_t*) l1)->f_found)->f_name;
	l5 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) ((vader_struct_vader_front_resolver$DeferredModule_t*) l1)->f_found)->f_name;
	l6 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) ((vader_struct_vader_front_resolver$DeferredModule_t*) l1)->f_found)->f_origin;
	l7 = ((vader_struct_vader_front_resolver$DeferredModule_t*) l1)->f_sources;
	vader_struct_vader_front_resolver$Module_t* _a0_obj = (vader_struct_vader_front_resolver$Module_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$Module_t));
	vader_obj_header_init(_a0_obj, 1799u);
	_a0_obj->f_id = l3;
	_a0_obj->f_display_path = l4;
	_a0_obj->f_module_name = l5;
	_a0_obj->f_origin = l6;
	_a0_obj->f_files = l7;
	l7 = (void*) _a0_obj;
	l8 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_node_factory;
	l9 = ((vader_struct_vader_front_resolver$DeferredModule_t*) l1)->f_discarded_bodies;
	l10 = ((vader_struct_vader_front_resolver$DeferredModule_t*) l1)->f_target_decls;
	l11 = ((vader_struct_vader_front_resolver$DeferredModule_t*) l1)->f_files_without_tests;
	l12 = ((vader_struct_vader_front_resolver$DeferredModule_t*) l1)->f_trimmed;
	l13 = ((vader_struct_vader_front_resolver$DeferredModule_t*) l1)->f_lost_impl_traits;
	vader_struct_vader_front_resolver$LoadedModule_t* _a1_obj = (vader_struct_vader_front_resolver$LoadedModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$LoadedModule_t));
	vader_obj_header_init(_a1_obj, 1796u);
	_a1_obj->f_module = l7;
	_a1_obj->f_collected = l2;
	_a1_obj->f_node_id_factory = l8;
	_a1_obj->f_discarded_bodies = l9;
	_a1_obj->f_target_decls = l10;
	_a1_obj->f_files_without_tests = l11;
	_a1_obj->f_trimmed = l12;
	_a1_obj->f_lost_impl_traits = l13;
	t0 = (void*) _a1_obj;
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_resolver$lookup(void* l0, vader_string_t l1) {
	int64_t l2;
	vader_box_t l3;
	void* t0;
	l2 = vader_array_length(((vader_array_t*) ((vader_struct_vader_front_resolver$Scope_t*) l0)->f_frames));
	while ((l2 > INT64_C(0))) {
		l2 = vader_chk_sub(i64, l2, INT64_C(1));
		vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_front_resolver$Scope_t*) l0)->f_frames);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
		t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l2);
		l3 = std_collections$Map$std_core$Index$at__string__Any(t0, l1);
		if (l3.tag == 1491u) {
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
	l2 = vader_array_length(((vader_array_t*) ((vader_struct_vader_front_resolver$Scope_t*) l0)->f_frames));
	while ((l2 > INT64_C(0))) {
		l2 = vader_chk_sub(i64, l2, INT64_C(1));
		vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_front_resolver$Scope_t*) l0)->f_frames);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
		t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l2);
		t1 = std_collections$Map$std_core$Index$at__string__Any(t0, l1);
		if (!(t1.tag == 0u)) {
			return ((int32_t) (int64_t) l2);
		}
	}
	return INT32_C(-1);
}

static vader_box_t vader_front_resolver$lookup_subst(void* l0, vader_string_t l1) {
	vader_box_t t0;
	t0 = std_collections$Map$std_core$Index$at__string__Any(((vader_struct_vader_front_resolver$Subst_t*) l0)->f_entries, l1);
	return t0;
}

static vader_box_t vader_front_resolver$lookup_trait_sym(vader_string_t l0, void* l1, void* l2, void* l3) {
	vader_box_t l4;
	void* t0;
	void* t1;
	l4 = std_collections$Map$std_core$Index$at__string__Any(l1, l0);
	if (l4.tag == 1491u) {
		t0 = l4.payload.obj;
		t1 = vader_front_resolver$resolve_import_redirect(t0, l3);
		return vader_ref_box(t1);
	}
	l4 = std_collections$Map$std_core$Index$at__string__Any(l2, l0);
	if (l4.tag == 0u) {
		return vader_box_obj(0u, NULL);
	}
	t0 = l4.payload.obj;
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
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
	l1 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(35u, 0u, 0u, 653u);
	l2 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 645u);
	l3 = (void*) _a2_arr;
	vader_struct_std_collections$Map__string__Any_t* _a3_obj = (vader_struct_std_collections$Map__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any_t));
	vader_obj_header_init(_a3_obj, 1004u);
	_a3_obj->f_ekeys = l1;
	_a3_obj->f_evals = l2;
	_a3_obj->f_index = l3;
	_a3_obj->f_mask = INT64_C(0);
	_a3_obj->f_grow_at = INT64_C(0);
	_a3_obj->f_size = INT64_C(0);
	_a3_obj->f_tombs = INT64_C(0);
	l1 = (void*) _a3_obj;
	l2 = vader_front_resolver$builtin_type_names();
	l4 = vader_array_length(((vader_array_t*) l2));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
		t0 = vader_array_box_slots(_a4_slotarr->buf)[vader_array_offset(_a4_slotarr) + (size_t) l5];
		l6 = t0.payload.s;
		l3 = vader_core_symbol$make(l0, (uint8_t) 12, l6, 614u, 614u, (uint8_t) 0, vader_box_obj(0u, NULL));
		std_collections$Map$std_core$IndexSet$set_at__string__Any(l1, l6, vader_ref_box(l3));
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
	int32_t t3;
	vader_box_t* gc_roots[2] = { &l0, &l2 };
	void** gc_raw_roots[6] = { &l3, &l4, &l5, &l6, &l7, &t0 };
	vader_string_t* gc_atom_roots[2] = { &l1, &t1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = l0;
	if (l2.tag == 0u) {
		vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
		l3 = (void*) _a0_arr;
		vader_array_t* _a1_arr = vader_array_new(100u, 0u, 13u, 1269u);
		l4 = (void*) _a1_arr;
		vader_array_t* _a2_arr = vader_array_new(28u, 0u, 0u, 642u);
		l5 = (void*) _a2_arr;
		vader_array_t* _a3_arr = vader_array_new(28u, 0u, 0u, 642u);
		l6 = (void*) _a3_arr;
		vader_struct_vader_front_resolver$Manifest_t* _a4_obj = (vader_struct_vader_front_resolver$Manifest_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$Manifest_t));
		vader_obj_header_init(_a4_obj, 1798u);
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
	t1 = vader_front_resolver$join_path(l1, 3527u);
	t2 = std_fs$exists(t1);
	if (t2) {
		t0 = vader_front_resolver$read_manifest(l1);
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	t3 = vader_global$vader_front_resolver$declared_roots$state;
	if (t3 == INT32_C(2)) {
		l4 = vader_global$vader_front_resolver$declared_roots$instance;
	} else {
		l4 = vader_front_resolver$declared_roots();
	}
	l2 = std_collections$Map$std_core$Index$at__string__string__(l4, l1);
	if (l2.tag == 0u) {
		vader_array_t* _a5_arr = vader_array_new(28u, 0u, 0u, 642u);
		l4 = (void*) _a5_arr;
		vader_array_t* _a6_arr = vader_array_new(100u, 0u, 13u, 1269u);
		l5 = (void*) _a6_arr;
		vader_array_t* _a7_arr = vader_array_new(28u, 0u, 0u, 642u);
		l6 = (void*) _a7_arr;
		vader_array_t* _a8_arr = vader_array_new(28u, 0u, 0u, 642u);
		l7 = (void*) _a8_arr;
		vader_struct_vader_front_resolver$Manifest_t* _a9_obj = (vader_struct_vader_front_resolver$Manifest_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$Manifest_t));
		vader_obj_header_init(_a9_obj, 1798u);
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
	vader_array_t* _a10_arr = vader_array_new(100u, 0u, 13u, 1269u);
	l4 = (void*) _a10_arr;
	vader_array_t* _a11_arr = vader_array_new(28u, 0u, 0u, 642u);
	l5 = (void*) _a11_arr;
	vader_array_t* _a12_arr = vader_array_new(28u, 0u, 0u, 642u);
	l6 = (void*) _a12_arr;
	vader_struct_vader_front_resolver$Manifest_t* _a13_obj = (vader_struct_vader_front_resolver$Manifest_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$Manifest_t));
	vader_obj_header_init(_a13_obj, 1798u);
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
	l3 = concat_2(t0, 1173u);
	if (l1 == l3) {
		t0 = vader_front_resolver$toolchain_folder(l2);
		{ vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l3 = concat_2(l3, 534u);
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
	l3 = vader_array_length(((vader_array_t*) l2));
	l4 = INT64_C(0);
	while ((l4 < l3)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		t0 = vader_array_read_u8(_a0_slotarr, vader_array_offset(_a0_slotarr) + (size_t) l4, 647u);
		l5 = ((uint8_t) t0.payload.i);
		l6 = ((vader_struct_vader_support_target$Target_t*) l1)->f_os;
		if (l5 == l6) {
			return true;
		}
		l4 = (l4 + INT64_C(1));
	}
	return false;
}

static void vader_front_resolver$materialize_default_members(void* l0, void* l1, void* l2, void* l3) {
	void* l4 = NULL;
	void* l5 = NULL;
	void* l6 = NULL;
	void* l9 = NULL;
	void* l11 = NULL;
	void* l13 = NULL;
	int64_t l7, l8, l12;
	vader_string_t l10 = 0;
	bool t0;
	void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l9, &l11, &l13 };
	vader_string_t* gc_atom_roots[1] = { &l10 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 10u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	t0 = vader_front_resolver$any_has_body(((vader_struct_toolchain_ast$TraitDecl_t*) l1)->f_members);
	if (!(t0)) {
		{ vader_gc_top = gc_frame.prev; return; }
	}
	l4 = vader_front_resolver$provided_names(((vader_struct_toolchain_ast$ImplDecl_t*) l0)->f_members);
	l5 = vader_front_resolver$build_subst(l0, l1, l2);
	l6 = ((vader_struct_toolchain_ast$TraitDecl_t*) l1)->f_members;
	l7 = vader_array_length(((vader_array_t*) l6));
	l8 = INT64_C(0);
	while ((l8 < l7)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l6);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		l9 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l8);
		if (!(((vader_struct_toolchain_ast$FnDecl_t*) l9)->f_body.tag == 0u)) {
			l10 = ((vader_struct_toolchain_ast$FnDecl_t*) l9)->f_name;
			t0 = std_collections$Set$std_core$Contains$contains__string(l4, l10);
			if (!(t0)) {
				l11 = ((vader_struct_toolchain_ast$ImplDecl_t*) l0)->f_members;
				l12 = toolchain_parser$mint(l3);
				l13 = vader_front_resolver$synth_inherited(l9, l5, l12);
				vader_array_push_ref((vader_array_t*) l11, l13);
				l8 = (l8 + INT64_C(1));
				continue;
			}
		}
		l8 = (l8 + INT64_C(1));
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
	vader_string_t l7 = 0;
	vader_string_t l15 = 0;
	vader_string_t l18 = 0;
	vader_string_t l19 = 0;
	int64_t l11, l12;
	vader_box_t l13 = vader_box_null(), l14 = vader_box_null();
	bool t0;
	void* t1 = NULL;
	vader_string_t t2 = 0;
	vader_box_t t3 = vader_box_null();
	vader_box_t* gc_roots[3] = { &l13, &l14, &t3 };
	void** gc_raw_roots[23] = {
		&l0, &l1, &l2, &l3, &l4, &l5, &l6, &l8, &l9, &l10, &l16, &l17, &l20, &l21, &l22, &l23, &l24,
		&l25, &l26, &l27, &l28, &l29, &t1,
	};
	vader_string_t* gc_atom_roots[5] = { &l7, &l15, &l18, &l19, &t2 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 3u, 23u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
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
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
	l8 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(35u, 0u, 0u, 653u);
	l9 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 645u);
	l10 = (void*) _a2_arr;
	vader_struct_std_collections$Map__string__Any_t* _a3_obj = (vader_struct_std_collections$Map__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any_t));
	vader_obj_header_init(_a3_obj, 1004u);
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
	l11 = vader_array_length(((vader_array_t*) l5));
	l12 = INT64_C(0);
	while ((l12 < l11)) {
		vader_array_t* _a4_slotarr = ((vader_array_t*) l5);
		VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
		l13 = vader_array_ref_load_box(_a4_slotarr->buf, vader_array_offset(_a4_slotarr) + (size_t) l12);
		if (l13.tag == 1190u) {
			t1 = l13.payload.obj;
			l14 = toolchain_ast$impl_trait_head(t1);
			t1 = l13.payload.obj;
			l8 = toolchain_ast$impl_trait_args(t1);
			l9 = vader_front_resolver$find_impl_trait_decl(l14, l8, l1, l6, l3, l0, l4);
			if (((vader_struct_vader_front_resolver$TraitLookup_t*) l9)->f_trait_decl.tag == 0u) {
				t1 = l13.payload.obj;
				l7 = toolchain_ast$impl_trait_written_name(t1);
				l15 = concat_3(1307u, l7, 1307u);
				t0 = ((vader_struct_vader_front_resolver$TraitLookup_t*) l9)->f_hidden;
				if (t0) {
					l16 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l14.payload.obj);
					l10 = toolchain_diagnostics$resolver_error((uint8_t) 7, l16, l15);
				} else {
					t2 = ((vader_struct_vader_front_resolver$TraitLookup_t*) l9)->f_other_kind;
					if (t2 != 0u) {
						l17 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l14.payload.obj);
						l18 = ((vader_struct_vader_front_resolver$TraitLookup_t*) l9)->f_other_kind;
						l19 = concat_3(l15, 187u, l18);
						l10 = toolchain_diagnostics$resolver_error((uint8_t) 8, l17, l19);
					} else {
						l20 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l14.payload.obj);
						l10 = toolchain_diagnostics$resolver_error((uint8_t) 6, l20, l15);
					}
				}
				vader_array_push_ref((vader_array_t*) ((vader_struct_vader_front_resolver$LoadedProject_t*) l0)->f_diags, l10);
				l12 = (l12 + INT64_C(1));
				continue;
			}
			t3 = ((vader_struct_vader_front_resolver$TraitLookup_t*) l9)->f_trait_decl;
			l21 = t3.payload.obj;
			l22 = l13.payload.obj;
			l23 = ((vader_struct_vader_front_resolver$LoadedProject_t*) l0)->f_diags;
			vader_front_resolver$check_short_impl_arity(l22, l21, l23);
			l24 = l13.payload.obj;
			l25 = ((vader_struct_vader_front_resolver$TraitLookup_t*) l9)->f_args;
			l26 = ((vader_struct_vader_front_resolver$LoadedModule_t*) l1)->f_node_id_factory;
			vader_front_resolver$materialize_sam_members(l24, l21, l25, l26);
			l27 = l13.payload.obj;
			l28 = ((vader_struct_vader_front_resolver$TraitLookup_t*) l9)->f_args;
			l29 = ((vader_struct_vader_front_resolver$LoadedModule_t*) l1)->f_node_id_factory;
			vader_front_resolver$materialize_default_members(l27, l21, l28, l29);
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
	l4 = ((vader_struct_std_collections$Map__string__vader_front_resolver_LoadedModule_t*) l3)->f_ekeys;
	l5 = ((vader_struct_std_collections$Map__string__vader_front_resolver_LoadedModule_t*) l3)->f_evals;
	l6 = INT64_C(0);
	l7 = ((vader_struct_std_collections$Map__string__vader_front_resolver_LoadedModule_t*) l3)->f_size;
	while ((l6 < l7)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
		t0 = vader_array_box_slots(_a0_slotarr->buf)[vader_array_offset(_a0_slotarr) + (size_t) l6];
		t1 = t0.payload.s;
		vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
		l3 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l6);
		l8 = ((vader_struct_vader_front_resolver$Module_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l3)->f_module)->f_files;
		l9 = vader_array_length(((vader_array_t*) l8));
		l10 = INT64_C(0);
		while ((l10 < l9)) {
			vader_array_t* _a2_slotarr = ((vader_array_t*) l8);
			VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
			l11 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l10);
			vader_front_resolver$materialize_file_impl_members(l0, l3, l11, l1, l2);
			l10 = (l10 + INT64_C(1));
		}
		l6 = (l6 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$materialize_sam_members(void* l0, void* l1, void* l2, void* l3) {
	void* l4 = NULL;
	void* l5 = NULL;
	void* l8 = NULL;
	void* l10 = NULL;
	void* l11 = NULL;
	void* l12 = NULL;
	int64_t l6, l7;
	vader_string_t l9 = 0;
	vader_box_t l13 = vader_box_null();
	int64_t t0;
	bool t1;
	vader_box_t* gc_roots[1] = { &l13 };
	void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l4, &l5, &l8, &l10, &l11, &l12 };
	vader_string_t* gc_atom_roots[1] = { &l9 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	t0 = vader_front_resolver$count_sam_synthetics(((vader_struct_toolchain_ast$ImplDecl_t*) l0)->f_members);
	if (t0 == INT64_C(0)) {
		{ vader_gc_top = gc_frame.prev; return; }
	}
	l4 = vader_front_resolver$required_methods(((vader_struct_toolchain_ast$TraitDecl_t*) l1)->f_members);
	t1 = std_core$is_empty__toolchain_ast_FnDecl(l4);
	if (t1) {
		{ vader_gc_top = gc_frame.prev; return; }
	}
	vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
	VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
	VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
	l4 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT32_C(0));
	l5 = vader_front_resolver$build_subst(l0, l1, l2);
	l6 = INT64_C(0);
	l7 = vader_array_length(((vader_array_t*) ((vader_struct_toolchain_ast$ImplDecl_t*) l0)->f_members));
	while ((l6 < l7)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$ImplDecl_t*) l0)->f_members);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
		l8 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l6);
		t1 = ((vader_struct_toolchain_ast$FnDecl_t*) l8)->f_sam_synthetic;
		if (t1) {
			l9 = ((vader_struct_toolchain_ast$FnDecl_t*) l4)->f_name;
			((vader_struct_toolchain_ast$FnDecl_t*) l8)->f_name = l9;
			l10 = ((vader_struct_toolchain_ast$FnDecl_t*) l4)->f_params;
			l11 = ((vader_struct_toolchain_ast$FnDecl_t*) l8)->f_name_span;
			l12 = vader_front_resolver$substitute_params_disambiguated(l10, l5, l11, l3);
			((vader_struct_toolchain_ast$FnDecl_t*) l8)->f_params = l12;
			VADER_WRITE_BARRIER((vader_struct_toolchain_ast$FnDecl_t*) l8);
			l13 = vader_front_resolver$substitute_opt_type(((vader_struct_toolchain_ast$FnDecl_t*) l4)->f_return_type, l5);
			((vader_struct_toolchain_ast$FnDecl_t*) l8)->f_return_type = l13;
			VADER_WRITE_BARRIER((vader_struct_toolchain_ast$FnDecl_t*) l8);
			l6 = (l6 + INT64_C(1));
			continue;
		}
		l6 = (l6 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$merge_collected(void* l0, void* l1, void* l2) {
	void* l3 = NULL;
	void* l4 = NULL;
	void* l5 = NULL;
	void* l10 = NULL;
	void* l11 = NULL;
	void* l14 = NULL;
	void* l18 = NULL;
	int64_t l6, l7, l19, l20;
	vader_string_t l8 = 0;
	vader_string_t l9 = 0;
	vader_string_t l17 = 0;
	vader_box_t l12 = vader_box_null(), l15 = vader_box_null(), l16 = vader_box_null();
	bool l13;
	int32_t l21, l22;
	vader_box_t t0 = vader_box_null();
	vader_box_t* gc_roots[4] = { &l12, &l15, &l16, &t0 };
	void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l4, &l5, &l10, &l11, &l14, &l18 };
	vader_string_t* gc_atom_roots[3] = { &l8, &l9, &l17 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 4u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l3 = ((vader_struct_vader_front_resolver$CollectedModule_t*) l1)->f_symbols;
	l4 = ((vader_struct_std_collections$Map__string__vader_core_symbol_Symbol_t*) l3)->f_ekeys;
	l5 = ((vader_struct_std_collections$Map__string__vader_core_symbol_Symbol_t*) l3)->f_evals;
	l6 = INT64_C(0);
	l7 = ((vader_struct_std_collections$Map__string__vader_core_symbol_Symbol_t*) l3)->f_size;
	while ((l6 < l7)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
		t0 = vader_array_box_slots(_a0_slotarr->buf)[vader_array_offset(_a0_slotarr) + (size_t) l6];
		l8 = t0.payload.s;
		vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
		l3 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l6);
		l9 = l8;
		l10 = l3;
		l12 = std_collections$put_absent__string__vader_core_symbol_Symbol(((vader_struct_vader_front_resolver$CollectedModule_t*) l0)->f_symbols, l9, l10);
		if (!(l12.tag == 0u)) {
			l11 = l12.payload.obj;
			if (((vader_struct_vader_core_symbol$Symbol_t*) l11)->f_kind != INT32_C(0)) {
				l13 = true;
			} else {
				l13 = ((vader_struct_vader_core_symbol$Symbol_t*) l10)->f_kind != INT32_C(0);
			}
			if (l13) {
				l15 = ((vader_struct_vader_core_symbol$Symbol_t*) l10)->f_defined_at;
				l16 = l15;
				if (l15.tag == 1289u) {
					l14 = l16.payload.obj;
				} else {
					if (!(l15.tag == 0u)) {
						vader_unreachable("non-exhaustive match (T3013 should have caught this)");
					}
					l14 = vader_front_resolver$zero_span(0u);
				}
				l17 = concat_3(1307u, l9, 1331u);
				l18 = toolchain_diagnostics$resolver_error((uint8_t) 19, l14, l17);
				vader_array_push_ref((vader_array_t*) l2, l18);
			}
		}
		l6 = (l6 + INT64_C(1));
	}
	l3 = ((vader_struct_vader_front_resolver$CollectedModule_t*) l1)->f_fn_overloads;
	l4 = ((vader_struct_std_collections$Map__string__vader_core_symbol_Symbol___t*) l3)->f_ekeys;
	l5 = ((vader_struct_std_collections$Map__string__vader_core_symbol_Symbol___t*) l3)->f_evals;
	l6 = INT64_C(0);
	l7 = ((vader_struct_std_collections$Map__string__vader_core_symbol_Symbol___t*) l3)->f_size;
	while ((l6 < l7)) {
		vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
		VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
		t0 = vader_array_box_slots(_a2_slotarr->buf)[vader_array_offset(_a2_slotarr) + (size_t) l6];
		l8 = t0.payload.s;
		vader_array_t* _a3_slotarr = ((vader_array_t*) l5);
		VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l6)
		l3 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l6);
		l9 = l8;
		l10 = l3;
		l12 = std_collections$put_absent__string__vader_core_symbol_Symbol__(((vader_struct_vader_front_resolver$CollectedModule_t*) l0)->f_fn_overloads, l9, l10);
		if (!(l12.tag == 0u)) {
			l11 = l12.payload.obj;
			l14 = l10;
			l19 = vader_array_length(((vader_array_t*) l14));
			l20 = INT64_C(0);
			while ((l20 < l19)) {
				vader_array_t* _a4_slotarr = ((vader_array_t*) l14);
				VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
				l18 = vader_array_ref_load_obj(_a4_slotarr->buf, vader_array_offset(_a4_slotarr) + (size_t) l20);
				vader_array_push_ref((vader_array_t*) l11, l18);
				l20 = (l20 + INT64_C(1));
			}
		}
		l6 = (l6 + INT64_C(1));
	}
	l3 = ((vader_struct_vader_front_resolver$CollectedModule_t*) l1)->f_imports;
	l4 = ((vader_struct_std_collections$Map__i32__vader_front_resolver_ImportInfo_t*) l3)->f_ekeys;
	l5 = ((vader_struct_std_collections$Map__i32__vader_front_resolver_ImportInfo_t*) l3)->f_evals;
	l6 = INT64_C(0);
	l7 = ((vader_struct_std_collections$Map__i32__vader_front_resolver_ImportInfo_t*) l3)->f_size;
	while ((l6 < l7)) {
		vader_array_t* _a5_slotarr = ((vader_array_t*) l4);
		VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l6)
		l21 = ((int32_t*) _a5_slotarr->buf->slots)[vader_array_offset(_a5_slotarr) + (size_t) l6];
		vader_array_t* _a6_slotarr = ((vader_array_t*) l5);
		VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l6)
		l3 = vader_array_ref_load_obj(_a6_slotarr->buf, vader_array_offset(_a6_slotarr) + (size_t) l6);
		l22 = l21;
		l10 = l3;
		std_collections$Map$std_core$IndexSet$set_at__i32__Any(((vader_struct_vader_front_resolver$CollectedModule_t*) l0)->f_imports, l22, vader_ref_box(l10));
		l6 = (l6 + INT64_C(1));
	}
	l3 = ((vader_struct_vader_front_resolver$CollectedModule_t*) l0)->f_import_paths;
	l4 = ((vader_struct_vader_front_resolver$CollectedModule_t*) l1)->f_import_paths;
	vader_array_push_all((vader_array_t*) l3, (vader_array_t*) l4);
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
	if (l2 == 3714u) {
		l4 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_diags;
		l5 = concat_3(1307u, l2, 1307u);
		l6 = toolchain_diagnostics$resolver_error((uint8_t) 14, l3, l5);
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
	vader_array_t* _a0_arr = vader_array_new(93u, 0u, 13u, 1245u);
	l2 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 642u);
	l3 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(28u, 0u, 0u, 642u);
	l4 = (void*) _a2_arr;
	vader_array_t* _a3_arr = vader_array_new(29u, 0u, 7u, 645u);
	l5 = (void*) _a3_arr;
	vader_struct_std_collections$Map__string__string_t* _a4_obj = (vader_struct_std_collections$Map__string__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__string_t));
	vader_obj_header_init(_a4_obj, 1028u);
	_a4_obj->f_ekeys = l3;
	_a4_obj->f_evals = l4;
	_a4_obj->f_index = l5;
	_a4_obj->f_mask = INT64_C(0);
	_a4_obj->f_grow_at = INT64_C(0);
	_a4_obj->f_size = INT64_C(0);
	_a4_obj->f_tombs = INT64_C(0);
	l3 = (void*) _a4_obj;
	l6 = INT64_C(0);
	l7 = vader_array_length(((vader_array_t*) l1));
	while ((l6 < l7)) {
		vader_array_t* _a5_slotarr = ((vader_array_t*) l1);
		VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l6)
		t0 = vader_array_ref_load_obj(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) l6);
		l8 = vader_front_resolver$rooted_candidate(t0, l0);
		if (l8.tag == 0u) {
			l6 = (l6 + INT64_C(1));
			continue;
		}
		l9 = l8.payload.s;
		t1 = std_fs$is_dir(l9);
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
					{ vader_box_t __vret = vader_box_string(642u, t2); vader_gc_top = gc_frame.prev; return __vret; }
				}
			}
			l6 = (l6 + INT64_C(1));
			continue;
		}
		l6 = (l6 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

void* vader_front_resolver$module_file_scopes(void* l0, void* l1, void* l2, void* l3, void* l4) {
	void* l5 = NULL;
	void* l6 = NULL;
	void* l7 = NULL;
	void* l8 = NULL;
	void* l12 = NULL;
	void* l14 = NULL;
	int64_t l9, l10;
	vader_string_t l11 = 0;
	vader_string_t l13 = 0;
	void** gc_raw_roots[11] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l8, &l12, &l14 };
	vader_string_t* gc_atom_roots[2] = { &l11, &l13 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 11u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l5 = vader_front_resolver$make_builtin_scope(l4);
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
	l6 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(35u, 0u, 0u, 653u);
	l7 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 645u);
	l8 = (void*) _a2_arr;
	vader_struct_std_collections$Map__string__Any_t* _a3_obj = (vader_struct_std_collections$Map__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any_t));
	vader_obj_header_init(_a3_obj, 1004u);
	_a3_obj->f_ekeys = l6;
	_a3_obj->f_evals = l7;
	_a3_obj->f_index = l8;
	_a3_obj->f_mask = INT64_C(0);
	_a3_obj->f_grow_at = INT64_C(0);
	_a3_obj->f_size = INT64_C(0);
	_a3_obj->f_tombs = INT64_C(0);
	l6 = (void*) _a3_obj;
	l7 = l0;
	l9 = vader_array_length(((vader_array_t*) l7));
	l10 = INT64_C(0);
	while ((l10 < l9)) {
		vader_array_t* _a4_slotarr = ((vader_array_t*) l7);
		VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l10)
		l8 = vader_array_ref_load_obj(_a4_slotarr->buf, vader_array_offset(_a4_slotarr) + (size_t) l10);
		l11 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) l8)->f_program)->f_file;
		l12 = vader_front_resolver$file_imports(l1, l11);
		l13 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) l8)->f_program)->f_file;
		l14 = vader_front_resolver$file_scope(l12, l1, l2, l3, l5);
		std_collections$Map$std_core$IndexSet$set_at__string__Any(l6, l13, vader_ref_box(l14));
		l10 = (l10 + INT64_C(1));
	}
	{ void* __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
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
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
	l1 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(35u, 0u, 0u, 653u);
	l2 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 645u);
	l3 = (void*) _a2_arr;
	vader_struct_std_collections$Map__string__Any_t* _a3_obj = (vader_struct_std_collections$Map__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any_t));
	vader_obj_header_init(_a3_obj, 1004u);
	_a3_obj->f_ekeys = l1;
	_a3_obj->f_evals = l2;
	_a3_obj->f_index = l3;
	_a3_obj->f_mask = INT64_C(0);
	_a3_obj->f_grow_at = INT64_C(0);
	_a3_obj->f_size = INT64_C(0);
	_a3_obj->f_tombs = INT64_C(0);
	l1 = (void*) _a3_obj;
	l2 = ((vader_struct_vader_front_resolver$LoadedProject_t*) l0)->f_modules;
	l3 = ((vader_struct_std_collections$Map__string__vader_front_resolver_LoadedModule_t*) l2)->f_ekeys;
	l4 = ((vader_struct_std_collections$Map__string__vader_front_resolver_LoadedModule_t*) l2)->f_evals;
	l5 = INT64_C(0);
	l6 = ((vader_struct_std_collections$Map__string__vader_front_resolver_LoadedModule_t*) l2)->f_size;
	while ((l5 < l6)) {
		vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
		t0 = vader_array_box_slots(_a4_slotarr->buf)[vader_array_offset(_a4_slotarr) + (size_t) l5];
		t1 = t0.payload.s;
		vader_array_t* _a5_slotarr = ((vader_array_t*) l4);
		VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
		l2 = vader_array_ref_load_obj(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) l5);
		l7 = ((vader_struct_vader_front_resolver$Module_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l2)->f_module)->f_module_name;
		std_collections$Map$std_core$IndexSet$set_at__string__Any(l1, l7, vader_ref_box(l2));
		l5 = (l5 + INT64_C(1));
	}
	{ void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_front_resolver$module_of(void* l0) {
	void* l1;
	vader_box_t l2;
	vader_string_t t0;
	l2 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) l0)->f_program)->f_module;
	if (l2.tag == 0u) {
		return 0u;
	}
	l1 = l2.payload.obj;
	t0 = ((vader_struct_toolchain_ast$ModuleDecl_t*) l1)->f_name;
	return t0;
}

static void* vader_front_resolver$module_server_for(void* l0, void* l1) {
	vader_string_t l2 = 0;
	void* l3 = NULL;
	void* l4 = NULL;
	void* l5 = NULL;
	void* l6 = NULL;
	int64_t l7, l8;
	int32_t t0;
	void* t1 = NULL;
	vader_string_t t2 = 0;
	vader_string_t t3 = 0;
	bool t4;
	void** gc_raw_roots[7] = { &l0, &l1, &l3, &l4, &l5, &l6, &t1 };
	vader_string_t* gc_atom_roots[3] = { &l2, &t2, &t3 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 7u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	t0 = vader_global$vader_front_resolver$toolchain_runtime$state;
	if (t0 == INT32_C(2)) {
		l2 = vader_global$vader_front_resolver$toolchain_runtime$instance;
	} else {
		l2 = vader_front_resolver$toolchain_runtime();
	}
	vader_struct_toolchain_stage$ModuleRoot_t* _a0_obj = (vader_struct_toolchain_stage$ModuleRoot_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_stage$ModuleRoot_t));
	vader_obj_header_init(_a0_obj, 1297u);
	_a0_obj->f_path = l2;
	_a0_obj->f_of_toolchain = true;
	t1 = (void*) _a0_obj;
	vader_array_t* _a1_arr = vader_array_new(105u, 1u, 13u, 1297u);
	((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = t1;
	l3 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(28u, 0u, 0u, 642u);
	l4 = (void*) _a2_arr;
	vader_array_t* _a3_arr = vader_array_new(26u, 0u, 12u, 640u);
	l5 = (void*) _a3_arr;
	vader_array_t* _a4_arr = vader_array_new(29u, 0u, 7u, 645u);
	l6 = (void*) _a4_arr;
	vader_struct_std_collections$Map__string__bool_t* _a5_obj = (vader_struct_std_collections$Map__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__bool_t));
	vader_obj_header_init(_a5_obj, 1010u);
	_a5_obj->f_ekeys = l4;
	_a5_obj->f_evals = l5;
	_a5_obj->f_index = l6;
	_a5_obj->f_mask = INT64_C(0);
	_a5_obj->f_grow_at = INT64_C(0);
	_a5_obj->f_size = INT64_C(0);
	_a5_obj->f_tombs = INT64_C(0);
	t1 = (void*) _a5_obj;
	vader_struct_std_collections$Set__string_t* _a6_obj = (vader_struct_std_collections$Set__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__string_t));
	vader_obj_header_init(_a6_obj, 1110u);
	_a6_obj->f_inner = t1;
	l4 = (void*) _a6_obj;
	l5 = l0;
	l7 = vader_array_length(((vader_array_t*) l5));
	l8 = INT64_C(0);
	while ((l8 < l7)) {
		vader_array_t* _a7_slotarr = ((vader_array_t*) l5);
		VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
		t1 = vader_array_ref_load_obj(_a7_slotarr->buf, vader_array_offset(_a7_slotarr) + (size_t) l8);
		t2 = ((vader_struct_vader_front_resolver$IncludePath_t*) t1)->f_dir;
		t3 = std_string$trim_suffix(t2, 534u);
		l2 = concat_2(t3, 550u);
		t4 = std_collections$add__string(l4, l2);
		if (t4) {
			vader_struct_toolchain_stage$ModuleRoot_t* _a8_obj = (vader_struct_toolchain_stage$ModuleRoot_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_stage$ModuleRoot_t));
			vader_obj_header_init(_a8_obj, 1297u);
			_a8_obj->f_path = l2;
			_a8_obj->f_of_toolchain = false;
			l6 = (void*) _a8_obj;
			vader_array_push_ref((vader_array_t*) l3, l6);
		}
		l8 = (l8 + INT64_C(1));
	}
	vader_array_t* _a9_arr = vader_array_new(36u, 1u, 0u, 660u);
	vader_array_box_slots(_a9_arr->buf)[vader_array_offset(_a9_arr) + 0u] = vader_ref_box(l1);
	t1 = (void*) _a9_arr;
	vader_struct_vader_front_resolver$ModuleServer_t* _a10_obj = (vader_struct_vader_front_resolver$ModuleServer_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$ModuleServer_t));
	vader_obj_header_init(_a10_obj, 1800u);
	_a10_obj->f_stages = t1;
	_a10_obj->f_roots = l3;
	t1 = (void*) _a10_obj;
	{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_resolver$module_text(void* l0, void* l1, void* l2, vader_string_t l3) {
	void* l4 = NULL;
	void* l7 = NULL;
	void* l8 = NULL;
	void* l11 = NULL;
	vader_box_t l5 = vader_box_null(), l6 = vader_box_null();
	int64_t l9, l10;
	void* t0 = NULL;
	bool t1;
	vader_box_t t2 = vader_box_null();
	vader_box_t* gc_roots[3] = { &l5, &l6, &t2 };
	void** gc_raw_roots[8] = { &l0, &l1, &l2, &l4, &l7, &l8, &l11, &t0 };
	vader_string_t* gc_atom_roots[1] = { &l3 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 3u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l5 = vader_front_resolver$package_in(l0, l1, l2);
	l6 = l5;
	if (l5.tag == 1533u) {
		t0 = l6.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l4 = l5.payload.obj;
	l7 = ((vader_struct_vader_core_wit$WitPackage_t*) l4)->f_interfaces;
	vader_struct___lambda_env_vader_front_resolver_42_t* _a0_obj = (vader_struct___lambda_env_vader_front_resolver_42_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_front_resolver_42_t));
	vader_obj_header_init(_a0_obj, 813u);
	_a0_obj->f_cap_0 = l3;
	l8 = (void*) _a0_obj;
	l6 = vader_box_obj(0u, NULL);
	l9 = vader_array_length(((vader_array_t*) l7));
	l10 = INT64_C(0);
	{
		while ((l10 < l9)) {
			vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
			VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
			l11 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l10);
			t1 = __lambda_vader_front_resolver_41(l8, l11);
			if (t1) {
				l6 = vader_ref_box(l11);
				goto end_28;
			}
			l10 = (l10 + INT64_C(1));
		}
		l6 = vader_box_obj(0u, NULL);
	} end_28: ;
	l5 = l6;
	if (l5.tag == 0u) {
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	l7 = l5.payload.obj;
	t2 = vader_core_wit$wit_module_source(l4, l7);
	{ vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_front_resolver$name_declared_decorators(void* l0, vader_string_t l1, void* l2) {
	void* l3 = NULL;
	void* l8 = NULL;
	void* l11 = NULL;
	int64_t l4, l5, l9, l10;
	vader_box_t l6 = vader_box_null();
	vader_string_t l7 = 0;
	vader_string_t l12 = 0;
	vader_box_t* gc_roots[1] = { &l6 };
	void** gc_raw_roots[5] = { &l0, &l2, &l3, &l8, &l11 };
	vader_string_t* gc_atom_roots[3] = { &l1, &l7, &l12 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l3 = ((vader_struct_toolchain_ast$Program_t*) l0)->f_decls;
	l4 = vader_array_length(((vader_array_t*) l3));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		l6 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
		l7 = toolchain_ast$place_of(l6);
		vader_front_resolver$name_sites(l0, l1, l6, l7, l2);
		l8 = toolchain_ast$members_of(l6);
		l9 = vader_array_length(((vader_array_t*) l8));
		l10 = INT64_C(0);
		while ((l10 < l9)) {
			vader_array_t* _a1_slotarr = ((vader_array_t*) l8);
			VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
			l11 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l10);
			l12 = toolchain_ast$member_place(l6);
			vader_front_resolver$name_sites(l0, l1, vader_ref_box(l11), l12, l2);
			l10 = (l10 + INT64_C(1));
		}
		l5 = (l5 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_front_resolver$name_in_file_scope(vader_string_t l0, void* l1, void* l2, void* l3) {
	void* l4;
	void* l6;
	vader_box_t l5;
	int32_t l7;
	vader_string_t l8, l9;
	vader_box_t t0;
	l5 = std_collections$Map$std_core$Index$at__string__Any(l2, l0);
	if (l5.tag == 0u) {
		return vader_box_obj(0u, NULL);
	}
	l4 = l5.payload.obj;
	if (((vader_struct_vader_core_symbol$Symbol_t*) l4)->f_kind != INT32_C(7)) {
		return vader_ref_box(l4);
	}
	l6 = ((vader_struct_vader_front_resolver$CollectedModule_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l1)->f_collected)->f_imports;
	l7 = ((vader_struct_vader_core_symbol$Symbol_t*) l4)->f_id;
	l5 = std_collections$Map$std_core$Index$at__i32__Any(l6, l7);
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
	l5 = std_collections$Map$std_core$Index$at__string__Any(l3, l9);
	if (l5.tag == 0u) {
		return vader_box_obj(0u, NULL);
	}
	l4 = l5.payload.obj;
	t0 = std_collections$Map$std_core$Index$at__string__Any(((vader_struct_vader_front_resolver$CollectedModule_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l4)->f_collected)->f_symbols, l8);
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
		{ vader_box_t __vret = vader_box_string(642u, l2); vader_gc_top = gc_frame.prev; return __vret; }
	}
	{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static void vader_front_resolver$name_sites(void* l0, vader_string_t l1, vader_box_t l2, vader_string_t l3, void* l4) {
	vader_box_t l5 = vader_box_null(), l12 = vader_box_null();
	vader_string_t l6 = 0;
	void* l7 = NULL;
	void* l10 = NULL;
	void* l11 = NULL;
	void* l13 = NULL;
	void* l16 = NULL;
	void* l17 = NULL;
	int64_t l8, l9, l14, l15;
	void* t0 = NULL;
	vader_box_t* gc_roots[3] = { &l2, &l5, &l12 };
	void** gc_raw_roots[9] = { &l0, &l4, &l7, &l10, &l11, &l13, &l16, &l17, &t0 };
	vader_string_t* gc_atom_roots[3] = { &l1, &l3, &l6 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 3u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l5 = l2;
	l6 = l3;
	l7 = toolchain_ast$decl_decorators(l5);
	vader_struct_toolchain_ast$DecoratorSite_t* _a0_obj = (vader_struct_toolchain_ast$DecoratorSite_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$DecoratorSite_t));
	vader_obj_header_init(_a0_obj, 1161u);
	_a0_obj->f_place = l6;
	_a0_obj->f_decorators = l7;
	t0 = (void*) _a0_obj;
	l7 = ((vader_struct_toolchain_ast$DecoratorSite_t*) t0)->f_decorators;
	l8 = vader_array_length(((vader_array_t*) l7));
	l9 = INT64_C(0);
	while ((l9 < l8)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		l10 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l9);
		l12 = vader_front_resolver$written_origin(l0, l1, l10, l4);
		if (l12.tag == 0u) {
			l9 = (l9 + INT64_C(1));
			continue;
		}
		l11 = l12.payload.obj;
		l6 = ((vader_struct_toolchain_stage$DecoratorOrigin_t*) l11)->f_module;
		((vader_struct_toolchain_ast$Decorator_t*) l10)->f_module_name = l6;
		l9 = (l9 + INT64_C(1));
	}
	if (l5.tag == 1224u) {
		t0 = l5.payload.obj;
		l7 = ((vader_struct_toolchain_ast$StructDecl_t*) t0)->f_fields;
		l8 = vader_array_length(((vader_array_t*) l7));
		l9 = INT64_C(0);
		while ((l9 < l8)) {
			vader_array_t* _a2_slotarr = ((vader_array_t*) l7);
			VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
			l10 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l9);
			l11 = ((vader_struct_toolchain_ast$StructField_t*) l10)->f_decorators;
			vader_struct_toolchain_ast$DecoratorSite_t* _a3_obj = (vader_struct_toolchain_ast$DecoratorSite_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$DecoratorSite_t));
			vader_obj_header_init(_a3_obj, 1161u);
			_a3_obj->f_place = 756u;
			_a3_obj->f_decorators = l11;
			t0 = (void*) _a3_obj;
			l13 = ((vader_struct_toolchain_ast$DecoratorSite_t*) t0)->f_decorators;
			l14 = vader_array_length(((vader_array_t*) l13));
			l15 = INT64_C(0);
			while ((l15 < l14)) {
				vader_array_t* _a4_slotarr = ((vader_array_t*) l13);
				VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
				l16 = vader_array_ref_load_obj(_a4_slotarr->buf, vader_array_offset(_a4_slotarr) + (size_t) l15);
				l12 = vader_front_resolver$written_origin(l0, l1, l16, l4);
				if (l12.tag == 0u) {
					l15 = (l15 + INT64_C(1));
					continue;
				}
				l17 = l12.payload.obj;
				l6 = ((vader_struct_toolchain_stage$DecoratorOrigin_t*) l17)->f_module;
				((vader_struct_toolchain_ast$Decorator_t*) l16)->f_module_name = l6;
				l15 = (l15 + INT64_C(1));
			}
			l9 = (l9 + INT64_C(1));
		}
	} else if (l5.tag == 1172u) {
		t0 = l5.payload.obj;
		l7 = ((vader_struct_toolchain_ast$EnumDecl_t*) t0)->f_variants;
		l8 = vader_array_length(((vader_array_t*) l7));
		l9 = INT64_C(0);
		while ((l9 < l8)) {
			vader_array_t* _a5_slotarr = ((vader_array_t*) l7);
			VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
			l10 = vader_array_ref_load_obj(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) l9);
			l11 = ((vader_struct_toolchain_ast$EnumVariant_t*) l10)->f_decorators;
			vader_struct_toolchain_ast$DecoratorSite_t* _a6_obj = (vader_struct_toolchain_ast$DecoratorSite_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$DecoratorSite_t));
			vader_obj_header_init(_a6_obj, 1161u);
			_a6_obj->f_place = 1186u;
			_a6_obj->f_decorators = l11;
			t0 = (void*) _a6_obj;
			l13 = ((vader_struct_toolchain_ast$DecoratorSite_t*) t0)->f_decorators;
			l14 = vader_array_length(((vader_array_t*) l13));
			l15 = INT64_C(0);
			while ((l15 < l14)) {
				vader_array_t* _a7_slotarr = ((vader_array_t*) l13);
				VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
				l16 = vader_array_ref_load_obj(_a7_slotarr->buf, vader_array_offset(_a7_slotarr) + (size_t) l15);
				l12 = vader_front_resolver$written_origin(l0, l1, l16, l4);
				if (l12.tag == 0u) {
					l15 = (l15 + INT64_C(1));
					continue;
				}
				l17 = l12.payload.obj;
				l6 = ((vader_struct_toolchain_stage$DecoratorOrigin_t*) l17)->f_module;
				((vader_struct_toolchain_ast$Decorator_t*) l16)->f_module_name = l6;
				l15 = (l15 + INT64_C(1));
			}
			l9 = (l9 + INT64_C(1));
		}
	} else if (l5.tag == 1181u) {
		t0 = l5.payload.obj;
		l7 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_params;
		l8 = vader_array_length(((vader_array_t*) l7));
		l9 = INT64_C(0);
		while ((l9 < l8)) {
			vader_array_t* _a8_slotarr = ((vader_array_t*) l7);
			VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
			l10 = vader_array_ref_load_obj(_a8_slotarr->buf, vader_array_offset(_a8_slotarr) + (size_t) l9);
			l11 = ((vader_struct_toolchain_ast$FnParam_t*) l10)->f_decorators;
			vader_struct_toolchain_ast$DecoratorSite_t* _a9_obj = (vader_struct_toolchain_ast$DecoratorSite_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$DecoratorSite_t));
			vader_obj_header_init(_a9_obj, 1161u);
			_a9_obj->f_place = 928u;
			_a9_obj->f_decorators = l11;
			t0 = (void*) _a9_obj;
			l13 = ((vader_struct_toolchain_ast$DecoratorSite_t*) t0)->f_decorators;
			l14 = vader_array_length(((vader_array_t*) l13));
			l15 = INT64_C(0);
			while ((l15 < l14)) {
				vader_array_t* _a10_slotarr = ((vader_array_t*) l13);
				VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
				l16 = vader_array_ref_load_obj(_a10_slotarr->buf, vader_array_offset(_a10_slotarr) + (size_t) l15);
				l5 = vader_front_resolver$written_origin(l0, l1, l16, l4);
				if (l5.tag == 0u) {
					l15 = (l15 + INT64_C(1));
					continue;
				}
				l17 = l5.payload.obj;
				l6 = ((vader_struct_toolchain_stage$DecoratorOrigin_t*) l17)->f_module;
				((vader_struct_toolchain_ast$Decorator_t*) l16)->f_module_name = l6;
				l15 = (l15 + INT64_C(1));
			}
			l9 = (l9 + INT64_C(1));
		}
	}
	{ vader_gc_top = gc_frame.prev; return; }
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

static bool vader_front_resolver$names_given(void* l0, vader_string_t l1, void* l2, vader_box_t l3, void* l4) {
	uint8_t l5;
	void* l6 = NULL;
	void* l8 = NULL;
	vader_box_t l7 = vader_box_null();
	void* t0 = NULL;
	bool t1;
	vader_box_t* gc_roots[2] = { &l3, &l7 };
	void** gc_raw_roots[6] = { &l0, &l2, &l4, &l6, &l8, &t0 };
	vader_string_t* gc_atom_roots[1] = { &l1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	if (l3.tag == 1293u) {
		t0 = l3.payload.obj;
		l5 = ((vader_struct_toolchain_stage$DecoratedWith_t*) t0)->f_marker;
		t1 = toolchain_ast$is_compiler(l2, l5);
		{ bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l7 = vader_front_resolver$written_origin(l0, l1, l2, l4);
	if (l7.tag == 0u) {
		{ vader_gc_top = gc_frame.prev; return false; }
	}
	l6 = l7.payload.obj;
	l8 = l3.payload.obj;
	t1 = toolchain_stage$same_origin(l6, l8);
	{ bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$names_written_by(vader_box_t l0, void* l1, vader_string_t l2) {
	void* l3 = NULL;
	void* l5 = NULL;
	vader_box_t l4 = vader_box_null();
	int64_t l6, l7;
	vader_string_t l8 = 0;
	vader_string_t l9 = 0;
	void* t0 = NULL;
	vader_box_t t1 = vader_box_null();
	vader_string_t t2 = 0;
	bool t3;
	vader_box_t* gc_roots[3] = { &l0, &l4, &t1 };
	void** gc_raw_roots[4] = { &l1, &l3, &l5, &t0 };
	vader_string_t* gc_atom_roots[4] = { &l2, &l8, &l9, &t2 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
	l3 = (void*) _a0_arr;
	vader_front_reach$collect_names_through(l0, l1, l3);
	if (l0.tag == 1191u) {
		t0 = l0.payload.obj;
		l4 = ((vader_struct_toolchain_ast$ImportDecl_t*) t0)->f_binding;
		if (l4.tag == 1166u) {
			t0 = l4.payload.obj;
			l5 = ((vader_struct_toolchain_ast$DestructureImport_t*) t0)->f_names;
			l6 = vader_array_length(((vader_array_t*) l5));
			l7 = INT64_C(0);
			while ((l7 < l6)) {
				vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
				VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
				t0 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l7);
				l8 = ((vader_struct_toolchain_ast$ImportName_t*) t0)->f_name;
				vader_array_push_scalar((vader_array_t*) l3, vader_box_string(642u, l8));
				l7 = (l7 + INT64_C(1));
			}
		}
	}
	if (l2 == 0u) {
		{ void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l6 = vader_array_length(((vader_array_t*) l3));
	l7 = INT64_C(0);
	while ((l7 < l6)) {
		vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
		t1 = vader_array_box_slots(_a2_slotarr->buf)[vader_array_offset(_a2_slotarr) + (size_t) l7];
		t2 = t1.payload.s;
		t3 = std_string$string$std_core$Contains$contains(t2, 326u);
		if (!(t3)) {
			vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
			VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
			t1 = vader_array_box_slots(_a3_slotarr->buf)[vader_array_offset(_a3_slotarr) + (size_t) l7];
			l8 = t1.payload.s;
			l9 = vader_front_reach$qualified_name(l2, l8);
			vader_array_push_scalar((vader_array_t*) l3, vader_box_string(642u, l9));
		}
		l7 = (l7 + INT64_C(1));
	}
	{ void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$namespace_aliases(void* l0, void* l1) {
	void* l2 = NULL;
	void* l3 = NULL;
	void* l4 = NULL;
	int64_t l5, l6;
	vader_box_t l7 = vader_box_null(), l8 = vader_box_null();
	vader_string_t l9 = 0;
	vader_string_t l10 = 0;
	vader_string_t l11 = 0;
	bool t0;
	void* t1 = NULL;
	vader_box_t* gc_roots[2] = { &l7, &l8 };
	void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l4, &t1 };
	vader_string_t* gc_atom_roots[3] = { &l9, &l10, &l11 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
	l2 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 642u);
	l3 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 645u);
	l4 = (void*) _a2_arr;
	vader_struct_std_collections$Map__string__string_t* _a3_obj = (vader_struct_std_collections$Map__string__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__string_t));
	vader_obj_header_init(_a3_obj, 1028u);
	_a3_obj->f_ekeys = l2;
	_a3_obj->f_evals = l3;
	_a3_obj->f_index = l4;
	_a3_obj->f_mask = INT64_C(0);
	_a3_obj->f_grow_at = INT64_C(0);
	_a3_obj->f_size = INT64_C(0);
	_a3_obj->f_tombs = INT64_C(0);
	l2 = (void*) _a3_obj;
	l3 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) l0)->f_program)->f_decls;
	l5 = vader_array_length(((vader_array_t*) l3));
	l6 = INT64_C(0);
	while ((l6 < l5)) {
		vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
		l7 = vader_array_ref_load_box(_a4_slotarr->buf, vader_array_offset(_a4_slotarr) + (size_t) l6);
		if (l7.tag == 1191u) {
			l4 = l7.payload.obj;
			l8 = ((vader_struct_toolchain_ast$ImportDecl_t*) l4)->f_binding;
			if (l8.tag == 1206u) {
				l9 = ((vader_struct_toolchain_ast$ImportDecl_t*) l4)->f_path;
				t0 = std_collections$Set$std_core$Contains$contains__string(l1, l9);
				if (t0) {
					t1 = l8.payload.obj;
					l10 = ((vader_struct_toolchain_ast$NamedNamespaceImport_t*) t1)->f_name;
					l11 = ((vader_struct_toolchain_ast$ImportDecl_t*) l4)->f_path;
					std_collections$Map$std_core$IndexSet$set_at__string__string(l2, l10, l11);
				}
			}
		}
		l6 = (l6 + INT64_C(1));
	}
	{ void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$new_scope(void* l0) {
	void* t0 = NULL;
	void** gc_raw_roots[2] = { &l0, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(48u, 1u, 13u, 1037u);
	((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = l0;
	t0 = (void*) _a0_arr;
	vader_struct_vader_front_resolver$Scope_t* _a1_obj = (vader_struct_vader_front_resolver$Scope_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$Scope_t));
	vader_obj_header_init(_a1_obj, 1812u);
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
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
	l0 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(35u, 0u, 0u, 653u);
	l1 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 645u);
	l2 = (void*) _a2_arr;
	vader_struct_std_collections$Map__string__Any_t* _a3_obj = (vader_struct_std_collections$Map__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any_t));
	vader_obj_header_init(_a3_obj, 1004u);
	_a3_obj->f_ekeys = l0;
	_a3_obj->f_evals = l1;
	_a3_obj->f_index = l2;
	_a3_obj->f_mask = INT64_C(0);
	_a3_obj->f_grow_at = INT64_C(0);
	_a3_obj->f_size = INT64_C(0);
	_a3_obj->f_tombs = INT64_C(0);
	t0 = (void*) _a3_obj;
	vader_struct_vader_front_resolver$Subst_t* _a4_obj = (vader_struct_vader_front_resolver$Subst_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$Subst_t));
	vader_obj_header_init(_a4_obj, 1815u);
	_a4_obj->f_entries = t0;
	t0 = (void*) _a4_obj;
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_resolver$next_in_block(void* l0, int64_t l1) {
	int64_t l2, l3;
	void* l4;
	vader_box_t l5;
	void* t0;
	l2 = vader_chk_add(i64, l1, INT64_C(1));
	l3 = vader_array_length(((vader_array_t*) ((vader_struct_toolchain_ast$BlockExpr_t*) l0)->f_stmts));
	if (l2 == l3) {
		return ((vader_struct_toolchain_ast$BlockExpr_t*) l0)->f_trailing;
	}
	l4 = ((vader_struct_toolchain_ast$BlockExpr_t*) l0)->f_stmts;
	l2 = vader_chk_add(i64, l1, INT64_C(1));
	vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
	VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
	VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
	l5 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l2);
	if (!(l5.tag == 1175u)) {
		return vader_box_obj(0u, NULL);
	}
	t0 = l5.payload.obj;
	return ((vader_struct_toolchain_ast$ExprStmt_t*) t0)->f_expr;
}

static vader_string_t vader_front_resolver$normalized_path(vader_string_t l0) {
	vader_string_t t0 = 0;
	vader_string_t t1 = 0;
	vader_string_t* gc_atom_roots[3] = { &l0, &t0, &t1 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 3u, gc_atom_roots };
	vader_gc_top = &gc_frame;
	t0 = std_path$to_posix(l0);
	t1 = vader_front_resolver$absolute_path(t0);
	t0 = std_path$to_path(t1);
	t1 = std_path$normalize(t0);
	t0 = std_path$as_string(t1);
	{ vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_front_resolver$note_fallback_name(void* l0, vader_box_t l1, void* l2) {
	void* l3 = NULL;
	void* l5 = NULL;
	vader_box_t l4 = vader_box_null();
	uint64_t l6;
	int32_t l7;
	int64_t t0;
	void* t1 = NULL;
	vader_box_t* gc_roots[2] = { &l1, &l4 };
	void** gc_raw_roots[5] = { &l0, &l2, &l3, &l5, &t1 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	if (l1.tag == 1178u) {
		t0 = vader_array_length(((vader_array_t*) l2));
		if (t0 != INT64_C(1)) {
			{ vader_gc_top = gc_frame.prev; return; }
		}
		t1 = l1.payload.obj;
		l4 = ((vader_struct_toolchain_ast$FallbackExpr_t*) t1)->f_binding;
		if (l4.tag == 0u) {
			{ vader_gc_top = gc_frame.prev; return; }
		}
		l3 = l4.payload.obj;
		l5 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_idents;
		l6 = toolchain_span$Span$std_core$Hash$hash(((vader_struct_toolchain_ast$SimpleBinding_t*) l3)->f_name_span);
		l4 = std_collections$Map$std_core$Index$at__u64__Any(l5, l6);
		if (l4.tag == 0u) {
			{ vader_gc_top = gc_frame.prev; return; }
		}
		l3 = l4.payload.obj;
		l5 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_fallback_names;
		l7 = ((vader_struct_vader_core_symbol$Symbol_t*) l3)->f_id;
		vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		l3 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT32_C(0));
		std_collections$Map$std_core$IndexSet$set_at__i32__Any(l5, l7, vader_ref_box(l3));
		{ vader_gc_top = gc_frame.prev; return; }
	}
	{ vader_gc_top = gc_frame.prev; return; }
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
	if (l1.tag == 1186u) {
		l2 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_idents;
		t0 = l1.payload.obj;
		l3 = toolchain_span$Span$std_core$Hash$hash(((vader_struct_toolchain_ast$IdentExpr_t*) t0)->f_span);
		l4 = std_collections$Map$std_core$Index$at__u64__Any(l2, l3);
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

static void vader_front_resolver$note_uncovered(void* l0, void* l1, void* l2, void* l3, void* l4) {
	void* l5 = NULL;
	void* l8 = NULL;
	void* l12 = NULL;
	void* l13 = NULL;
	void* l20 = NULL;
	int64_t l6, l7, l9, l10;
	vader_box_t l11 = vader_box_null(), l14 = vader_box_null(), l18 = vader_box_null();
	vader_string_t l15 = 0;
	vader_string_t l16 = 0;
	vader_string_t l17 = 0;
	vader_string_t l19 = 0;
	void* t0 = NULL;
	bool t1;
	vader_box_t t2 = vader_box_null();
	vader_box_t* gc_roots[4] = { &l11, &l14, &l18, &t2 };
	void** gc_raw_roots[11] = { &l0, &l1, &l2, &l3, &l4, &l5, &l8, &l12, &l13, &l20, &t0 };
	vader_string_t* gc_atom_roots[4] = { &l15, &l16, &l17, &l19 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 4u, 11u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l5 = l0;
	l6 = vader_array_length(((vader_array_t*) l5));
	l7 = INT64_C(0);
	while ((l7 < l6)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l7);
		l8 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) t0)->f_program)->f_decls;
		l9 = vader_array_length(((vader_array_t*) l8));
		l10 = INT64_C(0);
		while ((l10 < l9)) {
			vader_array_t* _a1_slotarr = ((vader_array_t*) l8);
			VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
			l11 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l10);
			if (l11.tag == 1181u) {
				l12 = l11.payload.obj;
				l14 = vader_front_resolver$target_selectors(((vader_struct_toolchain_ast$FnDecl_t*) l12)->f_decorators);
				if (l14.tag == 0u) {
					l10 = (l10 + INT64_C(1));
					continue;
				}
				l13 = l14.payload.obj;
				t1 = ((vader_struct_vader_front_resolver$TargetSelectors_t*) l13)->f_is_bare;
				if (t1) {
					if (((vader_struct_toolchain_ast$FnDecl_t*) l12)->f_body.tag == 0u) {
						l15 = ((vader_struct_toolchain_ast$FnDecl_t*) l12)->f_name;
						t2 = std_collections$Map$std_core$Index$at__string__Any(l2, l15);
						if (t2.tag == 0u) {
							t1 = vader_front_resolver$is_host_bound(l12);
							if (t1) {
								l10 = (l10 + INT64_C(1));
								continue;
							}
							l16 = vader_support_target$Target$std_core$Display$to_string(l1);
							l17 = ((vader_struct_toolchain_ast$FnDecl_t*) l12)->f_name;
							l18 = std_collections$Map$std_core$Index$at__string__string(l3, l17);
							if (l18.tag == 0u) {
								l19 = 393u;
							} else {
								l19 = l18.payload.s;
							}
							vader_struct_vader_front_resolver$UncoveredDecl_t* _a2_obj = (vader_struct_vader_front_resolver$UncoveredDecl_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$UncoveredDecl_t));
							vader_obj_header_init(_a2_obj, 1820u);
							_a2_obj->f_decl = l12;
							_a2_obj->f_target = l16;
							_a2_obj->f_covered = l19;
							l20 = (void*) _a2_obj;
							vader_array_push_ref((vader_array_t*) l4, l20);
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

static void* vader_front_resolver$number_module_files(void* l0, void* l1) {
	void* l2 = NULL;
	void* l3 = NULL;
	void* l6 = NULL;
	void* l7 = NULL;
	void* l10 = NULL;
	void* l11 = NULL;
	void* l12 = NULL;
	void* l15 = NULL;
	void* l16 = NULL;
	void* l17 = NULL;
	int64_t l4, l5, l8, l9;
	vader_string_t l13 = 0;
	vader_string_t l14 = 0;
	int64_t t0;
	void** gc_raw_roots[12] = { &l0, &l1, &l2, &l3, &l6, &l7, &l10, &l11, &l12, &l15, &l16, &l17 };
	vader_string_t* gc_atom_roots[2] = { &l13, &l14 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 12u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	t0 = vader_array_length(((vader_array_t*) l1));
	vader_array_t* _a0_arr = vader_array_reserve(352u, (int64_t) t0, 13u, 1814u);
	l2 = (void*) _a0_arr;
	l3 = l1;
	l4 = vader_array_length(((vader_array_t*) l3));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		l6 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l5);
		l7 = ((vader_struct_vader_front_resolver$ParsedFile_t*) l6)->f_errors;
		l8 = vader_array_length(((vader_array_t*) l7));
		l9 = INT64_C(0);
		while ((l9 < l8)) {
			vader_array_t* _a2_slotarr = ((vader_array_t*) l7);
			VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
			l10 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l9);
			vader_array_push_ref((vader_array_t*) ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_diags, l10);
			l9 = (l9 + INT64_C(1));
		}
		l11 = ((vader_struct_vader_front_resolver$ParsedFile_t*) l6)->f_program;
		l12 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_node_factory;
		toolchain_parser$assign_program_ids(l11, l12);
		l13 = ((vader_struct_vader_front_resolver$ParsedFile_t*) l6)->f_path;
		l14 = ((vader_struct_vader_front_resolver$ParsedFile_t*) l6)->f_content;
		l15 = ((vader_struct_vader_front_resolver$ParsedFile_t*) l6)->f_program;
		vader_array_t* _a3_arr = vader_array_new(333u, 0u, 13u, 1772u);
		l16 = (void*) _a3_arr;
		vader_struct_vader_front_resolver$SourceFile_t* _a4_obj = (vader_struct_vader_front_resolver$SourceFile_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$SourceFile_t));
		vader_obj_header_init(_a4_obj, 1814u);
		_a4_obj->f_path = l13;
		_a4_obj->f_content = l14;
		_a4_obj->f_program = l15;
		_a4_obj->f_origins = l16;
		l17 = (void*) _a4_obj;
		vader_array_push_ref((vader_array_t*) l2, l17);
		l5 = (l5 + INT64_C(1));
	}
	{ void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$only_reached(void* l0, void* l1) {
	void* l2 = NULL;
	void* l3 = NULL;
	void* l4 = NULL;
	void* l5 = NULL;
	void* l6 = NULL;
	void* l12 = NULL;
	void* l13 = NULL;
	void* l14 = NULL;
	void* l20 = NULL;
	void* l21 = NULL;
	void* l22 = NULL;
	void* l23 = NULL;
	void* l24 = NULL;
	void* l25 = NULL;
	void* l26 = NULL;
	void* l29 = NULL;
	void* l30 = NULL;
	void* l32 = NULL;
	void* l33 = NULL;
	void* l40 = NULL;
	void* l41 = NULL;
	void* l45 = NULL;
	void* l47 = NULL;
	int64_t l7, l8, l9, l10, l15, l16, l27, l28, l34, l35, l42, l43;
	vader_string_t l11 = 0;
	vader_string_t l19 = 0;
	vader_string_t l36 = 0;
	vader_string_t l37 = 0;
	vader_string_t l38 = 0;
	vader_string_t l39 = 0;
	vader_string_t l44 = 0;
	vader_box_t l17 = vader_box_null(), l18 = vader_box_null(), l46 = vader_box_null();
	bool l31;
	void* t0 = NULL;
	bool t1;
	vader_box_t t2 = vader_box_null();
	vader_string_t t3 = 0;
	vader_box_t* gc_roots[4] = { &l17, &l18, &l46, &t2 };
	void** gc_raw_roots[26] = {
		&l0, &l1, &l2, &l3, &l4, &l5, &l6, &l12, &l13, &l14, &l20, &l21, &l22, &l23, &l24, &l25,
		&l26, &l29, &l30, &l32, &l33, &l40, &l41, &l45, &l47, &t0,
	};
	vader_string_t* gc_atom_roots[8] = { &l11, &l19, &l36, &l37, &l38, &l39, &l44, &t3 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 4u, 26u, gc_roots, gc_raw_roots, 0u, NULL, 8u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
	l2 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(26u, 0u, 12u, 640u);
	l3 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 645u);
	l4 = (void*) _a2_arr;
	vader_struct_std_collections$Map__string__bool_t* _a3_obj = (vader_struct_std_collections$Map__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__bool_t));
	vader_obj_header_init(_a3_obj, 1010u);
	_a3_obj->f_ekeys = l2;
	_a3_obj->f_evals = l3;
	_a3_obj->f_index = l4;
	_a3_obj->f_mask = INT64_C(0);
	_a3_obj->f_grow_at = INT64_C(0);
	_a3_obj->f_size = INT64_C(0);
	_a3_obj->f_tombs = INT64_C(0);
	t0 = (void*) _a3_obj;
	vader_struct_std_collections$Set__string_t* _a4_obj = (vader_struct_std_collections$Set__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__string_t));
	vader_obj_header_init(_a4_obj, 1110u);
	_a4_obj->f_inner = t0;
	l2 = (void*) _a4_obj;
	vader_array_t* _a5_arr = vader_array_new(28u, 0u, 0u, 642u);
	l3 = (void*) _a5_arr;
	vader_array_t* _a6_arr = vader_array_new(26u, 0u, 12u, 640u);
	l4 = (void*) _a6_arr;
	vader_array_t* _a7_arr = vader_array_new(29u, 0u, 7u, 645u);
	l5 = (void*) _a7_arr;
	vader_struct_std_collections$Map__string__bool_t* _a8_obj = (vader_struct_std_collections$Map__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__bool_t));
	vader_obj_header_init(_a8_obj, 1010u);
	_a8_obj->f_ekeys = l3;
	_a8_obj->f_evals = l4;
	_a8_obj->f_index = l5;
	_a8_obj->f_mask = INT64_C(0);
	_a8_obj->f_grow_at = INT64_C(0);
	_a8_obj->f_size = INT64_C(0);
	_a8_obj->f_tombs = INT64_C(0);
	t0 = (void*) _a8_obj;
	vader_struct_std_collections$Set__string_t* _a9_obj = (vader_struct_std_collections$Set__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__string_t));
	vader_obj_header_init(_a9_obj, 1110u);
	_a9_obj->f_inner = t0;
	l3 = (void*) _a9_obj;
	vader_array_t* _a10_arr = vader_array_new(28u, 0u, 0u, 642u);
	l4 = (void*) _a10_arr;
	vader_array_t* _a11_arr = vader_array_new(26u, 0u, 12u, 640u);
	l5 = (void*) _a11_arr;
	vader_array_t* _a12_arr = vader_array_new(29u, 0u, 7u, 645u);
	l6 = (void*) _a12_arr;
	vader_struct_std_collections$Map__string__bool_t* _a13_obj = (vader_struct_std_collections$Map__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__bool_t));
	vader_obj_header_init(_a13_obj, 1010u);
	_a13_obj->f_ekeys = l4;
	_a13_obj->f_evals = l5;
	_a13_obj->f_index = l6;
	_a13_obj->f_mask = INT64_C(0);
	_a13_obj->f_grow_at = INT64_C(0);
	_a13_obj->f_size = INT64_C(0);
	_a13_obj->f_tombs = INT64_C(0);
	t0 = (void*) _a13_obj;
	vader_struct_std_collections$Set__string_t* _a14_obj = (vader_struct_std_collections$Set__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__string_t));
	vader_obj_header_init(_a14_obj, 1110u);
	_a14_obj->f_inner = t0;
	l4 = (void*) _a14_obj;
	l5 = l0;
	l7 = vader_array_length(((vader_array_t*) l5));
	l8 = INT64_C(0);
	while ((l8 < l7)) {
		vader_array_t* _a15_slotarr = ((vader_array_t*) l5);
		VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
		t0 = vader_array_ref_load_obj(_a15_slotarr->buf, vader_array_offset(_a15_slotarr) + (size_t) l8);
		l6 = ((vader_struct_vader_front_resolver$ReachUnit_t*) t0)->f_files;
		l9 = vader_array_length(((vader_array_t*) l6));
		l10 = INT64_C(0);
		while ((l10 < l9)) {
			vader_array_t* _a16_slotarr = ((vader_array_t*) l6);
			VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
			t0 = vader_array_ref_load_obj(_a16_slotarr->buf, vader_array_offset(_a16_slotarr) + (size_t) l10);
			l11 = vader_front_resolver$module_of(t0);
			std_collections$add__string(l4, l11);
			l10 = (l10 + INT64_C(1));
		}
		l8 = (l8 + INT64_C(1));
	}
	vader_array_t* _a17_arr = vader_array_new(28u, 0u, 0u, 642u);
	l5 = (void*) _a17_arr;
	vader_array_t* _a18_arr = vader_array_new(46u, 0u, 13u, 1028u);
	l6 = (void*) _a18_arr;
	vader_array_t* _a19_arr = vader_array_new(29u, 0u, 7u, 645u);
	l12 = (void*) _a19_arr;
	vader_struct_std_collections$Map__string__std_collections_Map_string__string__t* _a20_obj = (vader_struct_std_collections$Map__string__std_collections_Map_string__string__t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__std_collections_Map_string__string__t));
	vader_obj_header_init(_a20_obj, 1018u);
	_a20_obj->f_ekeys = l5;
	_a20_obj->f_evals = l6;
	_a20_obj->f_index = l12;
	_a20_obj->f_mask = INT64_C(0);
	_a20_obj->f_grow_at = INT64_C(0);
	_a20_obj->f_size = INT64_C(0);
	_a20_obj->f_tombs = INT64_C(0);
	l5 = (void*) _a20_obj;
	l6 = l0;
	l7 = vader_array_length(((vader_array_t*) l6));
	l8 = INT64_C(0);
	while ((l8 < l7)) {
		vader_array_t* _a21_slotarr = ((vader_array_t*) l6);
		VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
		t0 = vader_array_ref_load_obj(_a21_slotarr->buf, vader_array_offset(_a21_slotarr) + (size_t) l8);
		l12 = ((vader_struct_vader_front_resolver$ReachUnit_t*) t0)->f_files;
		l9 = vader_array_length(((vader_array_t*) l12));
		l10 = INT64_C(0);
		while ((l10 < l9)) {
			vader_array_t* _a22_slotarr = ((vader_array_t*) l12);
			VADER_ARRAY_RESOLVE_BUF(_a22_slotarr)
			l13 = vader_array_ref_load_obj(_a22_slotarr->buf, vader_array_offset(_a22_slotarr) + (size_t) l10);
			l11 = vader_front_resolver$file_of(l13);
			l14 = vader_front_resolver$namespace_aliases(l13, l4);
			std_collections$Map$std_core$IndexSet$set_at__string__std_collections_Map_string__string_(l5, l11, l14);
			l10 = (l10 + INT64_C(1));
		}
		l8 = (l8 + INT64_C(1));
	}
	l4 = l0;
	l7 = vader_array_length(((vader_array_t*) l4));
	l8 = INT64_C(0);
	while ((l8 < l7)) {
		vader_array_t* _a23_slotarr = ((vader_array_t*) l4);
		VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
		l6 = vader_array_ref_load_obj(_a23_slotarr->buf, vader_array_offset(_a23_slotarr) + (size_t) l8);
		t1 = ((vader_struct_vader_front_resolver$ReachUnit_t*) l6)->f_trimmed;
		if (t1) {
			l12 = ((vader_struct_vader_front_resolver$ReachUnit_t*) l6)->f_files;
			l9 = vader_array_length(((vader_array_t*) l12));
			l10 = INT64_C(0);
			while ((l10 < l9)) {
				vader_array_t* _a24_slotarr = ((vader_array_t*) l12);
				VADER_ARRAY_RESOLVE_BUF(_a24_slotarr)
				l13 = vader_array_ref_load_obj(_a24_slotarr->buf, vader_array_offset(_a24_slotarr) + (size_t) l10);
				l11 = vader_front_resolver$module_of(l13);
				l14 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) l13)->f_program)->f_decls;
				l15 = vader_array_length(((vader_array_t*) l14));
				l16 = INT64_C(0);
				while ((l16 < l15)) {
					vader_array_t* _a25_slotarr = ((vader_array_t*) l14);
					VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
					l17 = vader_array_ref_load_box(_a25_slotarr->buf, vader_array_offset(_a25_slotarr) + (size_t) l16);
					vader_front_resolver$add_leading_names(l17, l11, l3);
					t1 = vader_front_resolver$declares_type(l17);
					if (t1) {
						l18 = vader_front_resolver$declared_name(l17);
						if (l18.tag == 0u) {
							l16 = (l16 + INT64_C(1));
							continue;
						}
						l19 = l18.payload.s;
						std_collections$add__string(l2, l19);
					}
					l16 = (l16 + INT64_C(1));
				}
				l10 = (l10 + INT64_C(1));
			}
			l8 = (l8 + INT64_C(1));
			continue;
		}
		l8 = (l8 + INT64_C(1));
	}
	vader_array_t* _a26_arr = vader_array_new(28u, 0u, 0u, 642u);
	l4 = (void*) _a26_arr;
	vader_array_t* _a27_arr = vader_array_new(3u, 0u, 13u, 28u);
	l6 = (void*) _a27_arr;
	vader_array_t* _a28_arr = vader_array_new(29u, 0u, 7u, 645u);
	l12 = (void*) _a28_arr;
	vader_struct_std_collections$Map__string__string___t* _a29_obj = (vader_struct_std_collections$Map__string__string___t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__string___t));
	vader_obj_header_init(_a29_obj, 1029u);
	_a29_obj->f_ekeys = l4;
	_a29_obj->f_evals = l6;
	_a29_obj->f_index = l12;
	_a29_obj->f_mask = INT64_C(0);
	_a29_obj->f_grow_at = INT64_C(0);
	_a29_obj->f_size = INT64_C(0);
	_a29_obj->f_tombs = INT64_C(0);
	l4 = (void*) _a29_obj;
	vader_array_t* _a30_arr = vader_array_new(28u, 0u, 0u, 642u);
	l6 = (void*) _a30_arr;
	vader_array_t* _a31_arr = vader_array_new(26u, 0u, 12u, 640u);
	l12 = (void*) _a31_arr;
	vader_array_t* _a32_arr = vader_array_new(29u, 0u, 7u, 645u);
	l13 = (void*) _a32_arr;
	vader_struct_std_collections$Map__string__bool_t* _a33_obj = (vader_struct_std_collections$Map__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__bool_t));
	vader_obj_header_init(_a33_obj, 1010u);
	_a33_obj->f_ekeys = l6;
	_a33_obj->f_evals = l12;
	_a33_obj->f_index = l13;
	_a33_obj->f_mask = INT64_C(0);
	_a33_obj->f_grow_at = INT64_C(0);
	_a33_obj->f_size = INT64_C(0);
	_a33_obj->f_tombs = INT64_C(0);
	t0 = (void*) _a33_obj;
	vader_struct_std_collections$Set__string_t* _a34_obj = (vader_struct_std_collections$Set__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__string_t));
	vader_obj_header_init(_a34_obj, 1110u);
	_a34_obj->f_inner = t0;
	l6 = (void*) _a34_obj;
	vader_array_t* _a35_arr = vader_array_new(28u, 0u, 0u, 642u);
	l12 = (void*) _a35_arr;
	l13 = l1;
	l7 = vader_array_length(((vader_array_t*) l13));
	l8 = INT64_C(0);
	while ((l8 < l7)) {
		vader_array_t* _a36_slotarr = ((vader_array_t*) l13);
		VADER_ARRAY_RESOLVE_BUF(_a36_slotarr)
		t2 = vader_array_box_slots(_a36_slotarr->buf)[vader_array_offset(_a36_slotarr) + (size_t) l8];
		l11 = t2.payload.s;
		t1 = std_collections$add__string(l6, l11);
		if (t1) {
			vader_array_push_scalar((vader_array_t*) l12, vader_box_string(642u, l11));
		}
		l8 = (l8 + INT64_C(1));
	}
	l13 = l0;
	l7 = vader_array_length(((vader_array_t*) l13));
	l8 = INT64_C(0);
	while ((l8 < l7)) {
		vader_array_t* _a37_slotarr = ((vader_array_t*) l13);
		VADER_ARRAY_RESOLVE_BUF(_a37_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a37_slotarr, l8)
		l14 = vader_array_ref_load_obj(_a37_slotarr->buf, vader_array_offset(_a37_slotarr) + (size_t) l8);
		t1 = ((vader_struct_vader_front_resolver$ReachUnit_t*) l14)->f_trimmed;
		if (!(t1)) {
			l20 = ((vader_struct_vader_front_resolver$ReachUnit_t*) l14)->f_discarded;
			l9 = vader_array_length(((vader_array_t*) l20));
			l10 = INT64_C(0);
			while ((l10 < l9)) {
				vader_array_t* _a38_slotarr = ((vader_array_t*) l20);
				VADER_ARRAY_RESOLVE_BUF(_a38_slotarr)
				VADER_ARRAY_CHECK_INDEX(_a38_slotarr, l10)
				l21 = vader_array_ref_load_obj(_a38_slotarr->buf, vader_array_offset(_a38_slotarr) + (size_t) l10);
				l11 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) ((vader_struct_toolchain_ast$FnDecl_t*) l21)->f_span)->f_start)->f_file;
				l22 = vader_front_resolver$aliases_in(l5, l11);
				t0 = vader_front_resolver$names_written_by(vader_ref_box(l21), l22, 0u);
				vader_front_resolver$seed_leading(t0, l3, l6, l12);
				l10 = (l10 + INT64_C(1));
			}
		}
		l23 = ((vader_struct_vader_front_resolver$ReachUnit_t*) l14)->f_files;
		l15 = vader_array_length(((vader_array_t*) l23));
		l16 = INT64_C(0);
		while ((l16 < l15)) {
			vader_array_t* _a39_slotarr = ((vader_array_t*) l23);
			VADER_ARRAY_RESOLVE_BUF(_a39_slotarr)
			VADER_ARRAY_CHECK_INDEX(_a39_slotarr, l16)
			l24 = vader_array_ref_load_obj(_a39_slotarr->buf, vader_array_offset(_a39_slotarr) + (size_t) l16);
			l19 = vader_front_resolver$module_of(l24);
			vader_array_t* _a40_arr = vader_array_new(28u, 0u, 0u, 642u);
			l25 = (void*) _a40_arr;
			t0 = toolchain_ast$module_decorators(((vader_struct_vader_front_resolver$SourceFile_t*) l24)->f_program);
			vader_front_reach$collect_decorator_names(t0, l25);
			vader_front_resolver$seed_leading(l25, l3, l6, l12);
			l26 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) l24)->f_program)->f_decls;
			l27 = vader_array_length(((vader_array_t*) l26));
			l28 = INT64_C(0);
			while ((l28 < l27)) {
				vader_array_t* _a41_slotarr = ((vader_array_t*) l26);
				VADER_ARRAY_RESOLVE_BUF(_a41_slotarr)
				VADER_ARRAY_CHECK_INDEX(_a41_slotarr, l28)
				l17 = vader_array_ref_load_box(_a41_slotarr->buf, vader_array_offset(_a41_slotarr) + (size_t) l28);
				l29 = vader_front_resolver$aliases_read_by(l17, l24, l5);
				l30 = vader_front_resolver$names_written_by(l17, l29, l19);
				l18 = vader_front_resolver$reach_key(l17, l2);
				t1 = ((vader_struct_vader_front_resolver$ReachUnit_t*) l14)->f_trimmed;
				if (!(t1)) {
					l31 = true;
				} else {
					l31 = l18.tag == 0u;
				}
				if (l31) {
					vader_front_resolver$seed_leading(l30, l3, l6, l12);
					l28 = (l28 + INT64_C(1));
					continue;
				}
				vader_array_t* _a42_arr = vader_array_new(28u, 0u, 0u, 642u);
				l32 = (void*) _a42_arr;
				l33 = l30;
				l34 = vader_array_length(((vader_array_t*) l33));
				l35 = INT64_C(0);
				while ((l35 < l34)) {
					vader_array_t* _a43_slotarr = ((vader_array_t*) l33);
					VADER_ARRAY_RESOLVE_BUF(_a43_slotarr)
					t2 = vader_array_box_slots(_a43_slotarr->buf)[vader_array_offset(_a43_slotarr) + (size_t) l35];
					l36 = t2.payload.s;
					t1 = std_collections$Set$std_core$Contains$contains__string(l3, l36);
					if (t1) {
						vader_array_push_scalar((vader_array_t*) l32, vader_box_string(642u, l36));
					}
					l35 = (l35 + INT64_C(1));
				}
				t1 = vader_front_resolver$is_private_to(l17, l19);
				if (!(t1)) {
					l37 = l18.payload.s;
					vader_front_reach$register_refs(l4, l37, l32);
				}
				if (l19 != 0u) {
					if (!(l17.tag == 1190u)) {
						l38 = l18.payload.s;
						l39 = vader_front_reach$qualified_name(l19, l38);
						l40 = std_core$clone__string(l32);
						vader_front_reach$register_refs(l4, l39, l40);
					}
				}
				if (l17.tag == 1232u) {
					t0 = l17.payload.obj;
					l41 = ((vader_struct_toolchain_ast$TraitDecl_t*) t0)->f_members;
					l42 = vader_array_length(((vader_array_t*) l41));
					l43 = INT64_C(0);
					while ((l43 < l42)) {
						vader_array_t* _a44_slotarr = ((vader_array_t*) l41);
						VADER_ARRAY_RESOLVE_BUF(_a44_slotarr)
						t0 = vader_array_ref_load_obj(_a44_slotarr->buf, vader_array_offset(_a44_slotarr) + (size_t) l43);
						l44 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_name;
						t0 = l17.payload.obj;
						t3 = ((vader_struct_toolchain_ast$TraitDecl_t*) t0)->f_name;
						vader_array_t* _a45_arr = vader_array_new(28u, 1u, 0u, 642u);
						vader_array_box_slots(_a45_arr->buf)[vader_array_offset(_a45_arr) + 0u] = vader_box_string(642u, t3);
						l45 = (void*) _a45_arr;
						vader_front_reach$register_refs(l4, l44, l45);
						l43 = (l43 + INT64_C(1));
					}
				}
				l28 = (l28 + INT64_C(1));
			}
			l16 = (l16 + INT64_C(1));
		}
		l8 = (l8 + INT64_C(1));
	}
	vader_array_t* _a46_arr = vader_array_new(28u, 0u, 0u, 642u);
	t0 = (void*) _a46_arr;
	l3 = vader_front_reach$bfs_reachable(t0, l12, l4);
	vader_array_t* _a47_arr = vader_array_new(351u, 0u, 13u, 1805u);
	l4 = (void*) _a47_arr;
	l5 = l0;
	l7 = vader_array_length(((vader_array_t*) l5));
	l8 = INT64_C(0);
	while ((l8 < l7)) {
		vader_array_t* _a48_slotarr = ((vader_array_t*) l5);
		VADER_ARRAY_RESOLVE_BUF(_a48_slotarr)
		l6 = vader_array_ref_load_obj(_a48_slotarr->buf, vader_array_offset(_a48_slotarr) + (size_t) l8);
		t1 = ((vader_struct_vader_front_resolver$ReachUnit_t*) l6)->f_trimmed;
		if (t1) {
			vader_array_t* _a49_arr = vader_array_new(352u, 0u, 13u, 1814u);
			l20 = (void*) _a49_arr;
			vader_array_t* _a50_arr = vader_array_new(28u, 0u, 0u, 642u);
			l21 = (void*) _a50_arr;
			vader_struct_vader_front_resolver$Reached_t* _a51_obj = (vader_struct_vader_front_resolver$Reached_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$Reached_t));
			vader_obj_header_init(_a51_obj, 1805u);
			_a51_obj->f_files = l20;
			_a51_obj->f_lost_impl_traits = l21;
			l22 = (void*) _a51_obj;
			l23 = ((vader_struct_vader_front_resolver$ReachUnit_t*) l6)->f_files;
			l9 = vader_array_length(((vader_array_t*) l23));
			l10 = INT64_C(0);
			while ((l10 < l9)) {
				vader_array_t* _a52_slotarr = ((vader_array_t*) l23);
				VADER_ARRAY_RESOLVE_BUF(_a52_slotarr)
				l24 = vader_array_ref_load_obj(_a52_slotarr->buf, vader_array_offset(_a52_slotarr) + (size_t) l10);
				l11 = vader_front_resolver$module_of(l24);
				vader_array_t* _a53_arr = vader_array_new(481u, 0u, 13u, 2450u);
				l25 = (void*) _a53_arr;
				l26 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) l24)->f_program)->f_decls;
				l15 = vader_array_length(((vader_array_t*) l26));
				l16 = INT64_C(0);
				while ((l16 < l15)) {
					vader_array_t* _a54_slotarr = ((vader_array_t*) l26);
					VADER_ARRAY_RESOLVE_BUF(_a54_slotarr)
					l17 = vader_array_ref_load_box(_a54_slotarr->buf, vader_array_offset(_a54_slotarr) + (size_t) l16);
					l18 = vader_front_resolver$reach_key(l17, l2);
					if (l18.tag == 0u) {
						l31 = true;
					} else {
						l19 = l18.payload.s;
						l31 = vader_front_resolver$is_reached_1(l17, l19, l11, l3);
					}
					if (l31) {
						vader_array_push_ref((vader_array_t*) l25, l17.payload.obj);
					} else if (l17.tag == 1190u) {
						l29 = ((vader_struct_vader_front_resolver$Reached_t*) l22)->f_lost_impl_traits;
						t0 = l17.payload.obj;
						l36 = toolchain_ast$impl_trait_name(t0);
						vader_array_push_scalar((vader_array_t*) l29, vader_box_string(642u, l36));
					}
					l16 = (l16 + INT64_C(1));
				}
				l30 = ((vader_struct_vader_front_resolver$Reached_t*) l22)->f_files;
				l32 = l24;
				l37 = ((vader_struct_vader_front_resolver$SourceFile_t*) l32)->f_path;
				l38 = ((vader_struct_vader_front_resolver$SourceFile_t*) l32)->f_content;
				l33 = ((vader_struct_vader_front_resolver$SourceFile_t*) l24)->f_program;
				l39 = ((vader_struct_toolchain_ast$Program_t*) l33)->f_file;
				l40 = ((vader_struct_toolchain_ast$Program_t*) l33)->f_span;
				l27 = ((vader_struct_toolchain_ast$Program_t*) l33)->f_id;
				l46 = ((vader_struct_toolchain_ast$Program_t*) l33)->f_module;
				vader_struct_toolchain_ast$Program_t* _a55_obj = (vader_struct_toolchain_ast$Program_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$Program_t));
				vader_obj_header_init(_a55_obj, 1213u);
				_a55_obj->f_file = l39;
				_a55_obj->f_span = l40;
				_a55_obj->f_id = l27;
				_a55_obj->f_module = l46;
				_a55_obj->f_decls = l25;
				l41 = (void*) _a55_obj;
				l45 = ((vader_struct_vader_front_resolver$SourceFile_t*) l32)->f_origins;
				vader_struct_vader_front_resolver$SourceFile_t* _a56_obj = (vader_struct_vader_front_resolver$SourceFile_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$SourceFile_t));
				vader_obj_header_init(_a56_obj, 1814u);
				_a56_obj->f_path = l37;
				_a56_obj->f_content = l38;
				_a56_obj->f_program = l41;
				_a56_obj->f_origins = l45;
				l47 = (void*) _a56_obj;
				vader_array_push_ref((vader_array_t*) l30, l47);
				l10 = (l10 + INT64_C(1));
			}
			vader_array_push_ref((vader_array_t*) l4, l22);
			l8 = (l8 + INT64_C(1));
			continue;
		}
		l12 = ((vader_struct_vader_front_resolver$ReachUnit_t*) l6)->f_files;
		vader_array_t* _a57_arr = vader_array_new(28u, 0u, 0u, 642u);
		l13 = (void*) _a57_arr;
		vader_struct_vader_front_resolver$Reached_t* _a58_obj = (vader_struct_vader_front_resolver$Reached_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$Reached_t));
		vader_obj_header_init(_a58_obj, 1805u);
		_a58_obj->f_files = l12;
		_a58_obj->f_lost_impl_traits = l13;
		l14 = (void*) _a58_obj;
		vader_array_push_ref((vader_array_t*) l4, l14);
		l8 = (l8 + INT64_C(1));
	}
	{ void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static uint8_t vader_front_resolver$origin_of_root(vader_string_t l0) {
	vader_string_t t0 = 0;
	bool t1;
	vader_string_t* gc_atom_roots[2] = { &l0, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 2u, gc_atom_roots };
	vader_gc_top = &gc_frame;
	t0 = vader_front_resolver$join_path(l0, 3210u);
	t1 = std_fs$exists(t0);
	if (!(t1)) {
		{ vader_gc_top = gc_frame.prev; return (uint8_t) 0; }
	}
	{ vader_gc_top = gc_frame.prev; return (uint8_t) 1; }
}

static void* vader_front_resolver$package_folders(void* l0, void* l1) {
	void* l2 = NULL;
	void* l3 = NULL;
	void* l4 = NULL;
	void* l5 = NULL;
	void* l11 = NULL;
	void* l14 = NULL;
	void* l15 = NULL;
	void* l23 = NULL;
	int64_t l6, l7, l16, l17;
	vader_string_t l8 = 0;
	vader_string_t l9 = 0;
	vader_string_t l10 = 0;
	vader_string_t l18 = 0;
	vader_string_t l19 = 0;
	vader_string_t l21 = 0;
	vader_box_t l12 = vader_box_null(), l13 = vader_box_null(), l20 = vader_box_null();
	bool l22;
	void* t0 = NULL;
	vader_box_t t1 = vader_box_null();
	vader_string_t t2 = 0;
	int64_t t3;
	vader_box_t* gc_roots[4] = { &l12, &l13, &l20, &t1 };
	void** gc_raw_roots[11] = { &l0, &l1, &l2, &l3, &l4, &l5, &l11, &l14, &l15, &l23, &t0 };
	vader_string_t* gc_atom_roots[7] = { &l8, &l9, &l10, &l18, &l19, &l21, &t2 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 4u, 11u, gc_roots, gc_raw_roots, 0u, NULL, 7u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(348u, 0u, 13u, 1802u);
	l2 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 642u);
	l3 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(26u, 0u, 12u, 640u);
	l4 = (void*) _a2_arr;
	vader_array_t* _a3_arr = vader_array_new(29u, 0u, 7u, 645u);
	l5 = (void*) _a3_arr;
	vader_struct_std_collections$Map__string__bool_t* _a4_obj = (vader_struct_std_collections$Map__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__bool_t));
	vader_obj_header_init(_a4_obj, 1010u);
	_a4_obj->f_ekeys = l3;
	_a4_obj->f_evals = l4;
	_a4_obj->f_index = l5;
	_a4_obj->f_mask = INT64_C(0);
	_a4_obj->f_grow_at = INT64_C(0);
	_a4_obj->f_size = INT64_C(0);
	_a4_obj->f_tombs = INT64_C(0);
	t0 = (void*) _a4_obj;
	vader_struct_std_collections$Set__string_t* _a5_obj = (vader_struct_std_collections$Set__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__string_t));
	vader_obj_header_init(_a5_obj, 1110u);
	_a5_obj->f_inner = t0;
	l3 = (void*) _a5_obj;
	l4 = ((vader_struct_toolchain_stage$ModuleRequest_t*) l0)->f_roots;
	l6 = vader_array_length(((vader_array_t*) l4));
	l7 = INT64_C(0);
	while ((l7 < l6)) {
		vader_array_t* _a6_slotarr = ((vader_array_t*) l4);
		VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l7)
		l5 = vader_array_ref_load_obj(_a6_slotarr->buf, vader_array_offset(_a6_slotarr) + (size_t) l7);
		l8 = ((vader_struct_toolchain_stage$ModuleRoot_t*) l5)->f_path;
		l9 = ((vader_struct_vader_core_wit$WitPackageName_t*) l1)->f_namespace;
		l10 = concat_3(l8, 534u, l9);
		l12 = ((vader_struct_toolchain_stage$ModuleRequest_t*) l0)->f_files;
		l13 = toolchain_stage$BuildFiles$list_folder$$dispatch(l12, vader_box_string(642u, l10));
		if (l13.tag == 1131u) {
			l7 = (l7 + INT64_C(1));
			continue;
		}
		l11 = l13.payload.obj;
		l14 = (void*) &vader_fn_static_std_string$compare_ascending;
		l15 = std_sort$sort__string(l11, l14);
		l16 = vader_array_length(((vader_array_t*) l15));
		l17 = INT64_C(0);
		while ((l17 < l16)) {
			vader_array_t* _a7_slotarr = ((vader_array_t*) l15);
			VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
			t1 = vader_array_box_slots(_a7_slotarr->buf)[vader_array_offset(_a7_slotarr) + (size_t) l17];
			l18 = t1.payload.s;
			l20 = vader_front_resolver$version_in(l18, l1);
			if (l20.tag == 0u) {
				l17 = (l17 + INT64_C(1));
				continue;
			}
			l19 = l20.payload.s;
			std_collections$add__string(l3, l19);
			l21 = concat_3(l10, 534u, l18);
			l22 = ((vader_struct_toolchain_stage$ModuleRoot_t*) l5)->f_of_toolchain;
			vader_struct_vader_front_resolver$PackageFolder_t* _a8_obj = (vader_struct_vader_front_resolver$PackageFolder_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$PackageFolder_t));
			vader_obj_header_init(_a8_obj, 1802u);
			_a8_obj->f_path = l21;
			_a8_obj->f_of_toolchain = l22;
			l23 = (void*) _a8_obj;
			vader_array_push_ref((vader_array_t*) l2, l23);
			l17 = (l17 + INT64_C(1));
		}
		l7 = (l7 + INT64_C(1));
	}
	t2 = ((vader_struct_vader_core_wit$WitPackageName_t*) l1)->f_version;
	if (t2 == 0u) {
		t3 = std_collections$len__string(l3);
		if ((t3 > INT64_C(1))) {
			vader_array_t* _a9_arr = vader_array_new(348u, 0u, 13u, 1802u);
			t0 = (void*) _a9_arr;
			{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
		}
		{ void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
	}
	{ void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_resolver$package_in(void* l0, void* l1, void* l2) {
	void* l3 = NULL;
	void* l6 = NULL;
	void* l7 = NULL;
	vader_string_t l4 = 0;
	vader_string_t l10 = 0;
	vader_string_t l11 = 0;
	vader_string_t l12 = 0;
	vader_box_t l5 = vader_box_null(), l13 = vader_box_null();
	int64_t l8, l9;
	void* t0 = NULL;
	vader_string_t t1 = 0;
	vader_box_t t2 = vader_box_null();
	bool t3;
	vader_box_t* gc_roots[3] = { &l5, &l13, &t2 };
	void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l6, &l7, &t0 };
	vader_string_t* gc_atom_roots[5] = { &l4, &l10, &l11, &l12, &t1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 3u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l3 = ((vader_struct_vader_front_resolver$WitStage_t*) l0)->f_packages;
	l4 = ((vader_struct_vader_front_resolver$PackageFolder_t*) l2)->f_path;
	l5 = std_collections$Map$std_core$Index$at__string__Any(l3, l4);
	if (!(l5.tag == 0u)) {
		t0 = l5.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l5 = ((vader_struct_toolchain_stage$ModuleRequest_t*) l1)->f_files;
	t1 = ((vader_struct_vader_front_resolver$PackageFolder_t*) l2)->f_path;
	l5 = toolchain_stage$BuildFiles$list_folder$$dispatch(l5, vader_box_string(642u, t1));
	if (l5.tag == 1131u) {
		t1 = ((vader_struct_vader_front_resolver$PackageFolder_t*) l2)->f_path;
		t0 = vader_front_resolver$io_error(t1, 2204u);
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l3 = l5.payload.obj;
	vader_array_t* _a0_arr = vader_array_new(254u, 0u, 13u, 1563u);
	l6 = (void*) _a0_arr;
	l7 = (void*) &vader_fn_static_std_string$compare_ascending;
	l3 = std_sort$sort__string(l3, l7);
	l8 = vader_array_length(((vader_array_t*) l3));
	l9 = INT64_C(0);
	while ((l9 < l8)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l9)
		t2 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l9];
		l4 = t2.payload.s;
		t3 = __lambda_vader_front_resolver_43(l4);
		if (t3) {
			l10 = l4;
			t1 = ((vader_struct_vader_front_resolver$PackageFolder_t*) l2)->f_path;
			l11 = concat_3(t1, 534u, l10);
			l5 = ((vader_struct_toolchain_stage$ModuleRequest_t*) l1)->f_files;
			l13 = toolchain_stage$BuildFiles$read_text$$dispatch(l5, vader_box_string(642u, l11));
			if (l13.tag == 1131u) {
				t0 = vader_front_resolver$io_error(l11, 2212u);
				{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
			}
			l12 = l13.payload.s;
			vader_struct_vader_core_wit$WitSource_t* _a2_obj = (vader_struct_vader_core_wit$WitSource_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitSource_t));
			vader_obj_header_init(_a2_obj, 1563u);
			_a2_obj->f_path = l11;
			_a2_obj->f_text = l12;
			l7 = (void*) _a2_obj;
			vader_array_push_ref((vader_array_t*) l6, l7);
		}
		l9 = (l9 + INT64_C(1));
	}
	vader_struct___lambda_env_vader_front_resolver_45_t* _a3_obj = (vader_struct___lambda_env_vader_front_resolver_45_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_front_resolver_45_t));
	vader_obj_header_init(_a3_obj, 814u);
	_a3_obj->f_cap_0 = l0;
	_a3_obj->f_cap_1 = l1;
	t0 = (void*) _a3_obj;
	vader_fn_t* _a4_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
	vader_obj_header_init(_a4_closure, 613u);
	_a4_closure->code = (void*) &vader_fn_lift___lambda_vader_front_resolver_44;
	_a4_closure->env = t0;
	l7 = (void*) _a4_closure;
	l5 = vader_core_wit$read_wit_package(l6, l7);
	l13 = l5;
	if (l5.tag == 1533u) {
		t0 = l13.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l3 = l5.payload.obj;
	l6 = ((vader_struct_vader_front_resolver$WitStage_t*) l0)->f_packages;
	l4 = ((vader_struct_vader_front_resolver$PackageFolder_t*) l2)->f_path;
	std_collections$Map$std_core$IndexSet$set_at__string__Any(l6, l4, vader_ref_box(l3));
	{ vader_box_t __vret = vader_ref_box(l3); vader_gc_top = gc_frame.prev; return __vret; }
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
		t0 = toolchain_parser$parse_source(l0, l1);
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	t0 = toolchain_parser$parse_source_with_docs(l0, l1);
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$parse_level(void* l0, void* l1, bool l2) {
	void* l3 = NULL;
	void* l5 = NULL;
	void* l9 = NULL;
	void* l10 = NULL;
	vader_box_t l4 = vader_box_null(), l8 = vader_box_null();
	int64_t l6, l7, l11, l12;
	int64_t t0, t3;
	void* t1 = NULL;
	void* t2 = NULL;
	vader_box_t* gc_roots[2] = { &l4, &l8 };
	void** gc_raw_roots[8] = { &l0, &l1, &l3, &l5, &l9, &l10, &t1, &t2 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	t0 = vader_array_length(((vader_array_t*) l0));
	if (t0 == INT64_C(1)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		t1 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT32_C(0));
		t2 = vader_front_resolver$read_and_parse(((vader_struct_vader_front_resolver$DiscoveredModule_t*) t1)->f_files, l1, l2);
		vader_array_t* _a1_arr = vader_array_new(15u, 1u, 13u, 349u);
		((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = t2;
		t1 = (void*) _a1_arr;
		{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	t0 = vader_array_length(((vader_array_t*) l0));
	t3 = vader_chk_add(i64, t0, INT64_C(8));
	t0 = vader_chk_sub(i64, t3, INT64_C(1));
	l6 = vader_div_i64(t0, INT64_C(8));
	vader_array_t* _a2_arr = vader_array_new(61u, 0u, 13u, 1143u);
	l3 = (void*) _a2_arr;
	l4 = std_core$$array$Into$into__vader_front_resolver_DiscoveredModule(l0);
	l5 = (void*) &vader_fn_static___lambda_vader_front_resolver_5;
	l4 = std_iter$map__Any__string__(l4, l5);
	if (!(l6 == INT64_C(0))) {
		if ((l6 < INT64_C(1024))) {
			l7 = l6;
		} else {
			l7 = INT64_C(1024);
		}
		vader_array_t* _a3_arr = vader_array_reserve(3u, (int64_t) l7, 13u, 28u);
		l5 = (void*) _a3_arr;
		for (;;) {
			l8 = std_core$Iterator$next$$dispatch(l4);
			if (!(l8.tag == 1120u)) {
				l9 = l8.payload.obj;
				vader_array_push_ref((vader_array_t*) l5, l9);
				t0 = vader_array_length(((vader_array_t*) l5));
				if (t0 == l6) {
					vader_struct___lambda_env_vader_front_resolver_4_t* _a4_obj = (vader_struct___lambda_env_vader_front_resolver_4_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_front_resolver_4_t));
					vader_obj_header_init(_a4_obj, 811u);
					_a4_obj->f_cap_0 = l5;
					_a4_obj->f_cap_1 = l1;
					_a4_obj->f_cap_2 = l2;
					t1 = (void*) _a4_obj;
					vader_fn_t* _a5_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
					vader_obj_header_init(_a5_closure, 522u);
					_a5_closure->code = (void*) &vader_fn_lift___lambda_vader_front_resolver_3;
					_a5_closure->env = t1;
					t1 = (void*) _a5_closure;
					l10 = std_task$launch__vader_front_resolver_ParsedFile____(t1);
					vader_array_push_ref((vader_array_t*) l3, l10);
					vader_array_t* _a6_arr = vader_array_reserve(3u, (int64_t) l7, 13u, 28u);
					l5 = (void*) _a6_arr;
				}
				continue;
			}
			break;
		}
		t0 = vader_array_length(((vader_array_t*) l5));
		if ((t0 > INT64_C(0))) {
			vader_struct___lambda_env_vader_front_resolver_4_t* _a7_obj = (vader_struct___lambda_env_vader_front_resolver_4_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_front_resolver_4_t));
			vader_obj_header_init(_a7_obj, 811u);
			_a7_obj->f_cap_0 = l5;
			_a7_obj->f_cap_1 = l1;
			_a7_obj->f_cap_2 = l2;
			t1 = (void*) _a7_obj;
			vader_fn_t* _a8_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
			vader_obj_header_init(_a8_closure, 522u);
			_a8_closure->code = (void*) &vader_fn_lift___lambda_vader_front_resolver_3;
			_a8_closure->env = t1;
			t1 = (void*) _a8_closure;
			l5 = std_task$launch__vader_front_resolver_ParsedFile____(t1);
			vader_array_push_ref((vader_array_t*) l3, l5);
		}
	}
	l4 = std_task$try_join_all__vader_front_resolver_ParsedFile____(l3);
	if ((l4.tag == 657u) || (l4.tag == 1131u) || (l4.tag == 1522u) || (l4.tag == 907u) || (l4.tag == 1116u) || (l4.tag == 1137u) || (l4.tag == 1533u) || (l4.tag == 1282u) || (l4.tag == 1300u) || (l4.tag == 2191u) || (l4.tag == 2188u) || (l4.tag == 1737u)) {
		vader_host_std_core$Runtime$panic(2843u);
		vader_unreachable("a no-return call returned");
	} else {
		l3 = l4.payload.obj;
		vader_array_t* _a9_arr = vader_array_new(15u, 0u, 13u, 349u);
		l5 = (void*) _a9_arr;
		l6 = vader_array_length(((vader_array_t*) l3));
		l7 = INT64_C(0);
		while ((l7 < l6)) {
			vader_array_t* _a10_slotarr = ((vader_array_t*) l3);
			VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
			t1 = vader_array_ref_load_obj(_a10_slotarr->buf, vader_array_offset(_a10_slotarr) + (size_t) l7);
			l9 = __lambda_vader_front_resolver_6(t1);
			l11 = vader_array_length(((vader_array_t*) l9));
			l12 = INT64_C(0);
			while ((l12 < l11)) {
				vader_array_t* _a11_slotarr = ((vader_array_t*) l9);
				VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
				l10 = vader_array_ref_load_obj(_a11_slotarr->buf, vader_array_offset(_a11_slotarr) + (size_t) l12);
				vader_array_push_ref((vader_array_t*) l5, l10);
				l12 = (l12 + INT64_C(1));
			}
			l7 = (l7 + INT64_C(1));
		}
		{ void* __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
	}
	vader_gc_top = gc_frame.prev;
}

static void* vader_front_resolver$parse_lot(void* l0, void* l1, bool l2) {
	void* l3 = NULL;
	void* l4 = NULL;
	void* l5 = NULL;
	void* l8 = NULL;
	void* l9 = NULL;
	int64_t l6, l7;
	int64_t t0;
	void** gc_raw_roots[7] = { &l0, &l1, &l3, &l4, &l5, &l8, &l9 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 7u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l3 = l0;
	vader_struct___lambda_env_vader_front_resolver_13_t* _a0_obj = (vader_struct___lambda_env_vader_front_resolver_13_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_front_resolver_13_t));
	vader_obj_header_init(_a0_obj, 803u);
	_a0_obj->f_cap_0 = l1;
	_a0_obj->f_cap_1 = l2;
	l4 = (void*) _a0_obj;
	t0 = vader_array_length(((vader_array_t*) l3));
	vader_array_t* _a1_arr = vader_array_reserve(15u, (int64_t) t0, 13u, 349u);
	l5 = (void*) _a1_arr;
	l6 = vader_array_length(((vader_array_t*) l3));
	l7 = INT64_C(0);
	while ((l7 < l6)) {
		vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l7)
		l8 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l7);
		l9 = __lambda_vader_front_resolver_12(l4, l8);
		vader_array_push_ref((vader_array_t*) l5, l9);
		l7 = (l7 + INT64_C(1));
	}
	{ void* __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
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
	vader_box_t l5 = vader_box_null(), l6 = vader_box_null(), l12 = vader_box_null(), l13 = vader_box_null(), l14 = vader_box_null(), l15 = vader_box_null();
	vader_string_t l7 = 0;
	vader_string_t l10 = 0;
	vader_string_t l11 = 0;
	vader_string_t l16 = 0;
	vader_string_t l17 = 0;
	vader_string_t l18 = 0;
	vader_string_t l20 = 0;
	vader_string_t l22 = 0;
	vader_string_t l25 = 0;
	int64_t l8, l9;
	void* t0 = NULL;
	vader_box_t t1 = vader_box_null();
	vader_box_t* gc_roots[7] = { &l5, &l6, &l12, &l13, &l14, &l15, &t1 };
	void** gc_raw_roots[9] = { &l1, &l2, &l3, &l4, &l19, &l21, &l23, &l24, &t0 };
	vader_string_t* gc_atom_roots[10] = {
		&l0, &l7, &l10, &l11, &l16, &l17, &l18, &l20, &l22, &l25,
	};
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 7u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 10u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
	l1 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(100u, 0u, 13u, 1269u);
	l2 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(28u, 0u, 0u, 642u);
	l3 = (void*) _a2_arr;
	vader_array_t* _a3_arr = vader_array_new(28u, 0u, 0u, 642u);
	l4 = (void*) _a3_arr;
	vader_struct_vader_front_resolver$Manifest_t* _a4_obj = (vader_struct_vader_front_resolver$Manifest_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$Manifest_t));
	vader_obj_header_init(_a4_obj, 1798u);
	_a4_obj->f_name = 0u;
	_a4_obj->f_version = 0u;
	_a4_obj->f_include_paths = l1;
	_a4_obj->f_entries = l2;
	_a4_obj->f_assets = l3;
	_a4_obj->f_problems = l4;
	l1 = (void*) _a4_obj;
	l5 = json$parse(l0);
	l6 = l5;
	if (l5.tag == 907u) {
		l2 = ((vader_struct_vader_front_resolver$Manifest_t*) l1)->f_problems;
		t0 = l6.payload.obj;
		l7 = json$JsonError$std_core$Error$message(t0);
		l8 = (int64_t) vader_string_byte_len(l7);
		l3 = (void*) vader_buffer_new((size_t) (INT64_C(29) + l8));
		l8 = INT64_C(0);
		l8 = std_core$write_string_at(l3, l8, l7);
		l8 = std_core$write_string_at(l3, l8, 124u);
		t0 = l6.payload.obj;
		l9 = ((vader_struct_json$JsonError_t*) t0)->f_pos;
		l8 = std_core$write_int(l3, l8, l9);
		l7 = std_core$finish_buffer(l3, l8);
		vader_array_push_scalar((vader_array_t*) l2, vader_box_string(642u, l7));
		{ void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (!(l5.tag == 910u)) {
		vader_array_push_scalar((vader_array_t*) ((vader_struct_vader_front_resolver$Manifest_t*) l1)->f_problems, vader_box_string(642u, 2788u));
		{ void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l2 = l5.payload.obj;
	l3 = (void*) &vader_data_13;
	l2 = json$unknown_keys(l2, l3);
	l8 = vader_array_length(((vader_array_t*) l2));
	l9 = INT64_C(0);
	while ((l9 < l8)) {
		vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
		t1 = vader_array_box_slots(_a5_slotarr->buf)[vader_array_offset(_a5_slotarr) + (size_t) l9];
		l7 = t1.payload.s;
		t0 = (void*) &vader_data_13;
		l10 = std_string$join(t0, 1650u);
		l3 = ((vader_struct_vader_front_resolver$Manifest_t*) l1)->f_problems;
		l11 = concat_5(3493u, l7, 1701u, l10, 1307u);
		vader_array_push_scalar((vader_array_t*) l3, vader_box_string(642u, l11));
		l9 = (l9 + INT64_C(1));
	}
	l2 = l5.payload.obj;
	l3 = ((vader_struct_vader_front_resolver$Manifest_t*) l1)->f_problems;
	l7 = vader_front_resolver$string_at(l2, 2940u, l3);
	((vader_struct_vader_front_resolver$Manifest_t*) l1)->f_name = l7;
	l2 = l5.payload.obj;
	l3 = ((vader_struct_vader_front_resolver$Manifest_t*) l1)->f_problems;
	l7 = vader_front_resolver$string_at(l2, 3709u, l3);
	((vader_struct_vader_front_resolver$Manifest_t*) l1)->f_version = l7;
	l2 = ((vader_struct_vader_front_resolver$Manifest_t*) l1)->f_include_paths;
	l3 = l5.payload.obj;
	l4 = ((vader_struct_vader_front_resolver$Manifest_t*) l1)->f_problems;
	l3 = vader_front_resolver$string_list(l3, 2713u, l4);
	vader_array_push_all((vader_array_t*) l2, (vader_array_t*) l3);
	t0 = l5.payload.obj;
	l6 = std_collections$Map$std_core$Index$at__string__Any(((vader_struct_json$JsonObject_t*) t0)->f_entries, 2396u);
	if (l6.tag == 910u) {
		t0 = l6.payload.obj;
		l2 = ((vader_struct_json$JsonObject_t*) t0)->f_entries;
		l3 = ((vader_struct_std_collections$Map__string__json_JsonArray___json_JsonBool___json_JsonNull___json_JsonNumber___json_JsonObject___json_JsonString_t*) l2)->f_ekeys;
		l4 = ((vader_struct_std_collections$Map__string__json_JsonArray___json_JsonBool___json_JsonNull___json_JsonNumber___json_JsonObject___json_JsonString_t*) l2)->f_evals;
		l8 = INT64_C(0);
		l9 = ((vader_struct_std_collections$Map__string__json_JsonArray___json_JsonBool___json_JsonNull___json_JsonNumber___json_JsonObject___json_JsonString_t*) l2)->f_size;
		while ((l8 < l9)) {
			vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
			VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
			VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l8)
			t1 = vader_array_box_slots(_a6_slotarr->buf)[vader_array_offset(_a6_slotarr) + (size_t) l8];
			l7 = t1.payload.s;
			vader_array_t* _a7_slotarr = ((vader_array_t*) l4);
			VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
			VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l8)
			l12 = vader_array_ref_load_box(_a7_slotarr->buf, vader_array_offset(_a7_slotarr) + (size_t) l8);
			l10 = l7;
			l13 = l12;
			l14 = toolchain_project$entry_name_problem(l10);
			l15 = toolchain_project$entry_named(((vader_struct_vader_front_resolver$Manifest_t*) l1)->f_entries, l10);
			if (l14.tag == 0u) {
				if (l15.tag == 0u) {
					if (l13.tag == 911u) {
						l21 = ((vader_struct_vader_front_resolver$Manifest_t*) l1)->f_entries;
						t0 = l13.payload.obj;
						l22 = ((vader_struct_json$JsonString_t*) t0)->f_value;
						vader_struct_toolchain_project$ManifestEntry_t* _a8_obj = (vader_struct_toolchain_project$ManifestEntry_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_project$ManifestEntry_t));
						vader_obj_header_init(_a8_obj, 1269u);
						_a8_obj->f_name = l10;
						_a8_obj->f_path = l22;
						l23 = (void*) _a8_obj;
						vader_array_push_ref((vader_array_t*) l21, l23);
					} else {
						l24 = ((vader_struct_vader_front_resolver$Manifest_t*) l1)->f_problems;
						l25 = concat_3(2398u, l10, 1508u);
						vader_array_push_scalar((vader_array_t*) l24, vader_box_string(642u, l25));
					}
				} else {
					t0 = l15.payload.obj;
					l17 = ((vader_struct_toolchain_project$ManifestEntry_t*) t0)->f_name;
					l18 = concat_5(2397u, l17, 1336u, l10, 1307u);
					l19 = ((vader_struct_vader_front_resolver$Manifest_t*) l1)->f_problems;
					l20 = concat_2(l18, 224u);
					vader_array_push_scalar((vader_array_t*) l19, vader_box_string(642u, l20));
				}
			} else {
				l2 = ((vader_struct_vader_front_resolver$Manifest_t*) l1)->f_problems;
				l11 = l14.payload.s;
				l16 = concat_4(2398u, l10, 1308u, l11);
				vader_array_push_scalar((vader_array_t*) l2, vader_box_string(642u, l16));
			}
			l8 = (l8 + INT64_C(1));
		}
	} else if (!(l6.tag == 0u)) {
		vader_array_push_scalar((vader_array_t*) ((vader_struct_vader_front_resolver$Manifest_t*) l1)->f_problems, vader_box_string(642u, 1756u));
	}
	l2 = l5.payload.obj;
	l3 = ((vader_struct_vader_front_resolver$Manifest_t*) l1)->f_problems;
	l2 = vader_front_resolver$string_list(l2, 2059u, l3);
	l8 = vader_array_length(((vader_array_t*) l2));
	l9 = INT64_C(0);
	while ((l9 < l8)) {
		vader_array_t* _a9_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l9)
		t1 = vader_array_box_slots(_a9_slotarr->buf)[vader_array_offset(_a9_slotarr) + (size_t) l9];
		l7 = t1.payload.s;
		l5 = toolchain_project$asset_problem(l7);
		if (l5.tag == 0u) {
			vader_array_push_scalar((vader_array_t*) ((vader_struct_vader_front_resolver$Manifest_t*) l1)->f_assets, vader_box_string(642u, l7));
		} else {
			l3 = ((vader_struct_vader_front_resolver$Manifest_t*) l1)->f_problems;
			l10 = l5.payload.s;
			vader_array_push_scalar((vader_array_t*) l3, vader_box_string(642u, l10));
		}
		l9 = (l9 + INT64_C(1));
	}
	{ void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_resolver$plain_ident(void* l0, vader_string_t l1) {
	void* t0 = NULL;
	void** gc_raw_roots[2] = { &l0, &t0 };
	vader_string_t* gc_atom_roots[1] = { &l1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_struct_toolchain_ast$IdentExpr_t* _a0_obj = (vader_struct_toolchain_ast$IdentExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$IdentExpr_t));
	vader_obj_header_init(_a0_obj, 1186u);
	_a0_obj->f_span = l0;
	_a0_obj->f_id = INT64_C(0);
	_a0_obj->f_name = l1;
	_a0_obj->f_implicit_dot = false;
	t0 = (void*) _a0_obj;
	{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
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
	vader_obj_header_init(_a0_obj, 1789u);
	_a0_obj->f_dir = l0;
	_a0_obj->f_prefix = 0u;
	_a0_obj->f_merge = false;
	_a0_obj->f_origin = l1;
	t0 = (void*) _a0_obj;
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$planned_body_stages(vader_box_t l0) {
	void* l1 = NULL;
	void* l2 = NULL;
	vader_box_t* gc_roots[1] = { &l0 };
	void** gc_raw_roots[2] = { &l1, &l2 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l1 = vader_front_resolver$body_stages();
	l2 = vader_front_resolver$body_stages_of_driver(l0);
	vader_array_push_all((vader_array_t*) l1, (vader_array_t*) l2);
	{ void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$planned_source_stages(vader_box_t l0) {
	vader_box_t l1 = vader_box_null(), l2 = vader_box_null();
	vader_string_t l3 = 0;
	void* t0 = NULL;
	void* t1 = NULL;
	vader_string_t t2 = 0;
	vader_box_t* gc_roots[3] = { &l0, &l1, &l2 };
	void** gc_raw_roots[2] = { &t0, &t1 };
	vader_string_t* gc_atom_roots[2] = { &l3, &t2 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	t0 = vader_front_resolver$stages_of_driver(l0);
	t1 = vader_front_resolver$with_compiler_stages(t0);
	l1 = toolchain_stage$plan_stages__toolchain_stage_Sources__toolchain_stage_Generated__toolchain_stage_SourceSpec(t1);
	l2 = l1;
	if (l1.tag == 1300u) {
		t0 = l2.payload.obj;
		l3 = ((vader_struct_toolchain_stage$PlanError_t*) t0)->f_message;
		t2 = concat_2(3195u, l3);
		vader_host_std_core$Runtime$panic(t2);
		vader_unreachable("a no-return call returned");
	} else {
		t0 = l1.payload.obj;
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	vader_gc_top = gc_frame.prev;
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
	{ vader_box_t __vret = vader_box_string(642u, t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_front_resolver$preresolve_imports(void* l0, void* l1, void* l2, void* l3, void* l4, void* l5) {
	void* l6 = NULL;
	void* l9 = NULL;
	int64_t l7, l8, l10, l11;
	vader_box_t l12 = vader_box_null();
	void* t0 = NULL;
	vader_string_t t1 = 0;
	vader_box_t* gc_roots[1] = { &l12 };
	void** gc_raw_roots[9] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l9, &t0 };
	vader_string_t* gc_atom_roots[1] = { &t1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l6 = l0;
	l7 = vader_array_length(((vader_array_t*) l6));
	l8 = INT64_C(0);
	while ((l8 < l7)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l6);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l8)
		t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l8);
		l9 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) t0)->f_program)->f_decls;
		l10 = vader_array_length(((vader_array_t*) l9));
		l11 = INT64_C(0);
		while ((l11 < l10)) {
			vader_array_t* _a1_slotarr = ((vader_array_t*) l9);
			VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
			VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l11)
			l12 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l11);
			if (l12.tag == 1191u) {
				t0 = l12.payload.obj;
				t1 = ((vader_struct_toolchain_ast$ImportDecl_t*) t0)->f_path;
				vader_front_resolver$resolve_lazy(t1, l1, l2, l3, l4, l5);
			}
			l11 = (l11 + INT64_C(1));
		}
		l8 = (l8 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_front_resolver$private_type_of(vader_box_t l0, void* l1) {
	vader_string_t l2;
	vader_box_t l3;
	void* t0;
	bool t1;
	if (!(l0.tag == 1190u)) {
		return vader_box_obj(0u, NULL);
	}
	t0 = l0.payload.obj;
	l3 = vader_front_resolver$type_head_name(((vader_struct_toolchain_ast$ImplDecl_t*) t0)->f_for_type);
	if (l3.tag == 0u) {
		return vader_box_obj(0u, NULL);
	}
	l2 = l3.payload.s;
	t1 = std_collections$Set$std_core$Contains$contains__string(l1, l2);
	if (!(t1)) {
		return vader_box_obj(0u, NULL);
	}
	return vader_box_string(642u, l2);
}

static void* vader_front_resolver$project_include_paths(vader_box_t l0, void* l1, void* l2) {
	void* l3 = NULL;
	void* l4 = NULL;
	void* l9 = NULL;
	int64_t l5, l6;
	vader_string_t l7 = 0;
	vader_string_t l11 = 0;
	uint8_t l8;
	vader_box_t l10 = vader_box_null();
	int64_t t0;
	vader_box_t t1 = vader_box_null();
	vader_string_t t2 = 0;
	vader_box_t* gc_roots[3] = { &l0, &l10, &t1 };
	void** gc_raw_roots[5] = { &l1, &l2, &l3, &l4, &l9 };
	vader_string_t* gc_atom_roots[3] = { &l7, &l11, &t2 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	t0 = vader_array_length(((vader_array_t*) l2));
	vader_array_t* _a0_arr = vader_array_reserve(342u, (int64_t) t0, 13u, 1789u);
	l3 = (void*) _a0_arr;
	l4 = l2;
	l5 = vader_array_length(((vader_array_t*) l4));
	l6 = INT64_C(0);
	while ((l6 < l5)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		t1 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l6];
		l7 = t1.payload.s;
		l8 = vader_front_resolver$origin_of_root(l7);
		l9 = vader_front_resolver$plain_root(l7, l8);
		vader_array_push_ref((vader_array_t*) l3, l9);
		l6 = (l6 + INT64_C(1));
	}
	l10 = vader_front_resolver$sidecar_root(2825u, 3210u);
	if (!(l10.tag == 0u)) {
		t2 = l10.payload.s;
		l4 = vader_front_resolver$plain_root(t2, (uint8_t) 1);
		vader_array_push_ref((vader_array_t*) l3, l4);
	}
	if (l0.tag == 642u) {
		t2 = l0.payload.s;
		l4 = vader_front_resolver$plain_root(t2, (uint8_t) 0);
		vader_array_push_ref((vader_array_t*) l3, l4);
		l4 = ((vader_struct_vader_front_resolver$Manifest_t*) l1)->f_include_paths;
		l5 = vader_array_length(((vader_array_t*) l4));
		l6 = INT64_C(0);
		while ((l6 < l5)) {
			vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
			VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
			t1 = vader_array_box_slots(_a2_slotarr->buf)[vader_array_offset(_a2_slotarr) + (size_t) l6];
			l7 = t1.payload.s;
			t2 = l0.payload.s;
			l11 = vader_front_resolver$manifest_root(t2, l7, l10);
			l8 = vader_front_resolver$origin_of_root(l11);
			l9 = vader_front_resolver$plain_root(l11, l8);
			vader_array_push_ref((vader_array_t*) l3, l9);
			l6 = (l6 + INT64_C(1));
		}
	} else if (!(l0.tag == 0u)) {
		vader_unreachable("non-exhaustive match (T3013 should have caught this)");
	}
	if (l10.tag == 0u) {
		l8 = vader_front_resolver$origin_of_root(2825u);
		l4 = vader_front_resolver$plain_root(2825u, l8);
		vader_array_push_ref((vader_array_t*) l3, l4);
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
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
	l1 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(26u, 0u, 12u, 640u);
	l2 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 645u);
	l3 = (void*) _a2_arr;
	vader_struct_std_collections$Map__string__bool_t* _a3_obj = (vader_struct_std_collections$Map__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__bool_t));
	vader_obj_header_init(_a3_obj, 1010u);
	_a3_obj->f_ekeys = l1;
	_a3_obj->f_evals = l2;
	_a3_obj->f_index = l3;
	_a3_obj->f_mask = INT64_C(0);
	_a3_obj->f_grow_at = INT64_C(0);
	_a3_obj->f_size = INT64_C(0);
	_a3_obj->f_tombs = INT64_C(0);
	t0 = (void*) _a3_obj;
	vader_struct_std_collections$Set__string_t* _a4_obj = (vader_struct_std_collections$Set__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__string_t));
	vader_obj_header_init(_a4_obj, 1110u);
	_a4_obj->f_inner = t0;
	l1 = (void*) _a4_obj;
	l2 = l0;
	l4 = vader_array_length(((vader_array_t*) l2));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
		t0 = vader_array_ref_load_obj(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) l5);
		l6 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_name;
		std_collections$add__string(l1, l6);
		l5 = (l5 + INT64_C(1));
	}
	{ void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_front_resolver$provides_body(void* l0) {
	bool t0;
	t0 = toolchain_ast$is_compiler(l0, (uint8_t) 14);
	return t0;
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
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
	l2 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(35u, 0u, 0u, 653u);
	l3 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 645u);
	l4 = (void*) _a2_arr;
	vader_struct_std_collections$Map__string__Any_t* _a3_obj = (vader_struct_std_collections$Map__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any_t));
	vader_obj_header_init(_a3_obj, 1004u);
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

static vader_string_t vader_front_resolver$qualifier_of(void* l0) {
	void* l1 = NULL;
	vader_box_t l2 = vader_box_null();
	vader_string_t t0 = 0;
	vader_string_t t1 = 0;
	vader_box_t* gc_roots[1] = { &l2 };
	void** gc_raw_roots[2] = { &l0, &l1 };
	vader_string_t* gc_atom_roots[2] = { &t0, &t1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_toolchain_ast$Decorator_t*) l0)->f_qualifier;
	if (l2.tag == 0u) {
		{ vader_gc_top = gc_frame.prev; return 0u; }
	}
	l1 = l2.payload.obj;
	t0 = ((vader_struct_toolchain_ast$IdentExpr_t*) l1)->f_name;
	t1 = concat_2(t0, 489u);
	{ vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_resolver$reach_key(vader_box_t l0, void* l1) {
	vader_box_t l2;
	vader_string_t l3;
	vader_box_t t0;
	void* t1;
	bool t2;
	vader_string_t t3;
	if (!(l0.tag == 1190u)) {
		t0 = vader_front_resolver$declared_name(l0);
		return t0;
	}
	t1 = l0.payload.obj;
	l2 = vader_front_resolver$type_head_name(((vader_struct_toolchain_ast$ImplDecl_t*) t1)->f_for_type);
	if (!(l2.tag == 0u)) {
		l3 = l2.payload.s;
		t2 = std_collections$Set$std_core$Contains$contains__string(l1, l3);
		if (t2) {
			t3 = l2.payload.s;
			return vader_box_string(642u, t3);
		}
	}
	t1 = l0.payload.obj;
	l3 = toolchain_ast$impl_trait_name(t1);
	if (l3 == 0u) {
		return vader_box_obj(0u, NULL);
	}
	return vader_box_string(642u, l3);
}

static void* vader_front_resolver$read_and_parse(void* l0, void* l1, bool l2) {
	void* l3 = NULL;
	void* l4 = NULL;
	void* l9 = NULL;
	void* l10 = NULL;
	void* l11 = NULL;
	void* l12 = NULL;
	int64_t l5, l6;
	vader_string_t l7 = 0;
	vader_string_t l8 = 0;
	vader_box_t t0 = vader_box_null();
	vader_box_t* gc_roots[1] = { &t0 };
	void** gc_raw_roots[8] = { &l0, &l1, &l3, &l4, &l9, &l10, &l11, &l12 };
	vader_string_t* gc_atom_roots[2] = { &l7, &l8 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(349u, 0u, 13u, 1803u);
	l3 = (void*) _a0_arr;
	l4 = l0;
	l5 = vader_array_length(((vader_array_t*) l4));
	l6 = INT64_C(0);
	while ((l6 < l5)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
		t0 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l6];
		l7 = t0.payload.s;
		l8 = vader_front_resolver$read_with_overlay(l1, l7);
		if (l8 == 0u) {
			l6 = (l6 + INT64_C(1));
			continue;
		}
		l9 = vader_front_resolver$parse_file(l8, l7, l2);
		l10 = ((vader_struct_toolchain_parser$ParsedSource_t*) l9)->f_program;
		l11 = ((vader_struct_toolchain_parser$ParsedSource_t*) l9)->f_errors;
		vader_struct_vader_front_resolver$ParsedFile_t* _a2_obj = (vader_struct_vader_front_resolver$ParsedFile_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$ParsedFile_t));
		vader_obj_header_init(_a2_obj, 1803u);
		_a2_obj->f_path = l7;
		_a2_obj->f_content = l8;
		_a2_obj->f_program = l10;
		_a2_obj->f_errors = l11;
		l12 = (void*) _a2_obj;
		vader_array_push_ref((vader_array_t*) l3, l12);
		l6 = (l6 + INT64_C(1));
	}
	{ void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_resolver$read_buffer_or_disk(void* l0, vader_string_t l1) {
	vader_box_t l2 = vader_box_null();
	vader_string_t t0 = 0;
	vader_box_t t1 = vader_box_null();
	vader_box_t* gc_roots[2] = { &l2, &t1 };
	void** gc_raw_roots[1] = { &l0 };
	vader_string_t* gc_atom_roots[2] = { &l1, &t0 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = std_collections$Map$std_core$Index$at__string__string(l0, l1);
	if (!(l2.tag == 0u)) {
		t0 = l2.payload.s;
		{ vader_box_t __vret = vader_box_string(642u, t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	t1 = std_fs$read_file_string(l1, INT64_C(16777216));
	{ vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$read_interfaces(void* l0) {
	void* l1 = NULL;
	void* l2 = NULL;
	void* l3 = NULL;
	void* l7 = NULL;
	void* l8 = NULL;
	void* l11 = NULL;
	void* l14 = NULL;
	int64_t l4, l5, l9, l10, l12, l13;
	vader_box_t l6 = vader_box_null();
	vader_string_t l15 = 0;
	void* t0 = NULL;
	vader_box_t t1 = vader_box_null();
	vader_string_t t2 = 0;
	vader_box_t* gc_roots[2] = { &l6, &t1 };
	void** gc_raw_roots[9] = { &l0, &l1, &l2, &l3, &l7, &l8, &l11, &l14, &t0 };
	vader_string_t* gc_atom_roots[2] = { &l15, &t2 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
	l1 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(35u, 0u, 0u, 653u);
	l2 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 645u);
	l3 = (void*) _a2_arr;
	vader_struct_std_collections$Map__string__Any_t* _a3_obj = (vader_struct_std_collections$Map__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any_t));
	vader_obj_header_init(_a3_obj, 1004u);
	_a3_obj->f_ekeys = l1;
	_a3_obj->f_evals = l2;
	_a3_obj->f_index = l3;
	_a3_obj->f_mask = INT64_C(0);
	_a3_obj->f_grow_at = INT64_C(0);
	_a3_obj->f_size = INT64_C(0);
	_a3_obj->f_tombs = INT64_C(0);
	l1 = (void*) _a3_obj;
	l2 = ((vader_struct_vader_front_resolver$ModuleServer_t*) l0)->f_stages;
	l4 = vader_array_length(((vader_array_t*) l2));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
		l6 = vader_array_ref_load_box(_a4_slotarr->buf, vader_array_offset(_a4_slotarr) + (size_t) l5);
		if (l6.tag == 1822u) {
			t0 = l6.payload.obj;
			l3 = ((vader_struct_vader_front_resolver$WitStage_t*) t0)->f_packages;
			l7 = ((vader_struct_std_collections$Map__string__vader_core_wit_WitPackage_t*) l3)->f_ekeys;
			l8 = ((vader_struct_std_collections$Map__string__vader_core_wit_WitPackage_t*) l3)->f_evals;
			l9 = INT64_C(0);
			l10 = ((vader_struct_std_collections$Map__string__vader_core_wit_WitPackage_t*) l3)->f_size;
			while ((l9 < l10)) {
				vader_array_t* _a5_slotarr = ((vader_array_t*) l7);
				VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
				VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l9)
				t1 = vader_array_box_slots(_a5_slotarr->buf)[vader_array_offset(_a5_slotarr) + (size_t) l9];
				t2 = t1.payload.s;
				vader_array_t* _a6_slotarr = ((vader_array_t*) l8);
				VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
				VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l9)
				t0 = vader_array_ref_load_obj(_a6_slotarr->buf, vader_array_offset(_a6_slotarr) + (size_t) l9);
				l11 = ((vader_struct_vader_core_wit$WitPackage_t*) t0)->f_interfaces;
				l12 = vader_array_length(((vader_array_t*) l11));
				l13 = INT64_C(0);
				while ((l13 < l12)) {
					vader_array_t* _a7_slotarr = ((vader_array_t*) l11);
					VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
					l14 = vader_array_ref_load_obj(_a7_slotarr->buf, vader_array_offset(_a7_slotarr) + (size_t) l13);
					l15 = vader_core_wit$wit_owner_text(((vader_struct_vader_core_wit$WitInterface_t*) l14)->f_owner);
					std_collections$Map$std_core$IndexSet$set_at__string__Any(l1, l15, vader_ref_box(l14));
					l13 = (l13 + INT64_C(1));
				}
				l9 = (l9 + INT64_C(1));
			}
		}
		l5 = (l5 + INT64_C(1));
	}
	{ void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
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
	l1 = vader_front_resolver$join_path(l0, 3527u);
	t0 = std_fs$exists(l1);
	if (!(t0)) {
		vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
		l2 = (void*) _a0_arr;
		vader_array_t* _a1_arr = vader_array_new(100u, 0u, 13u, 1269u);
		l3 = (void*) _a1_arr;
		vader_array_t* _a2_arr = vader_array_new(28u, 0u, 0u, 642u);
		l4 = (void*) _a2_arr;
		vader_array_t* _a3_arr = vader_array_new(28u, 0u, 0u, 642u);
		l5 = (void*) _a3_arr;
		vader_struct_vader_front_resolver$Manifest_t* _a4_obj = (vader_struct_vader_front_resolver$Manifest_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$Manifest_t));
		vader_obj_header_init(_a4_obj, 1798u);
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

static vader_box_t vader_front_resolver$read_recorded(vader_string_t l0) {
	vader_string_t l1 = 0;
	vader_box_t l2 = vader_box_null(), l6 = vader_box_null();
	int64_t l3, l4, l5;
	void* t0 = NULL;
	vader_box_t* gc_roots[2] = { &l2, &l6 };
	void** gc_raw_roots[1] = { &t0 };
	vader_string_t* gc_atom_roots[2] = { &l0, &l1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = std_fs$read_file_string(l0, INT64_C(16777216));
	if (l2.tag == 1131u) {
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	l1 = l2.payload.s;
	l2 = std_string$index_of(l1, 10u, INT64_C(0));
	if (l2.tag == 0u) {
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	l3 = ((int64_t) l2.payload.i);
	l4 = vader_chk_add(i64, l3, INT64_C(1));
	l5 = (int64_t) vader_string_byte_len(l1);
	l6 = toolchain_protocol$decode_driver_frame(vader_string_byte_slice(l1, l4, l5));
	if (l6.tag == 1282u) {
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	l2 = l6;
	vader_struct_vader_front_resolver$Recorded_t* _a0_obj = (vader_struct_vader_front_resolver$Recorded_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$Recorded_t));
	vader_obj_header_init(_a0_obj, 1806u);
	_a0_obj->f_key = vader_string_byte_slice(l1, INT64_C(0), l3);
	_a0_obj->f_answer = l2;
	t0 = (void*) _a0_obj;
	{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
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
	l2 = vader_front_resolver$read_buffer_or_disk(l0, l1);
	if (l2.tag == 1131u) {
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
	vader_array_t* _a0_arr = vader_array_new(29u, 0u, 7u, 645u);
	l1 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(26u, 0u, 12u, 640u);
	l2 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 645u);
	l3 = (void*) _a2_arr;
	vader_struct_std_collections$Map__i32__bool_t* _a3_obj = (vader_struct_std_collections$Map__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__bool_t));
	vader_obj_header_init(_a3_obj, 919u);
	_a3_obj->f_ekeys = l1;
	_a3_obj->f_evals = l2;
	_a3_obj->f_index = l3;
	_a3_obj->f_mask = INT64_C(0);
	_a3_obj->f_grow_at = INT64_C(0);
	_a3_obj->f_size = INT64_C(0);
	_a3_obj->f_tombs = INT64_C(0);
	t0 = (void*) _a3_obj;
	vader_struct_std_collections$Set__i32_t* _a4_obj = (vader_struct_std_collections$Set__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__i32_t));
	vader_obj_header_init(_a4_obj, 1108u);
	_a4_obj->f_inner = t0;
	l1 = (void*) _a4_obj;
	l2 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_declared_locals;
	l4 = vader_array_length(((vader_array_t*) l2));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
		l6 = ((int32_t*) _a5_slotarr->buf->slots)[vader_array_offset(_a5_slotarr) + (size_t) l5];
		t1 = std_collections$Set$std_core$Contains$contains__i32(((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_reassigned, l6);
		if (!(t1)) {
			std_collections$add__i32(l1, l6);
		}
		l5 = (l5 + INT64_C(1));
	}
	{ void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_front_resolver$record_key(vader_string_t l0, void* l1, void* l2) {
	void* l3 = NULL;
	void* t0 = NULL;
	vader_string_t t1 = 0;
	vader_string_t t2 = 0;
	void** gc_raw_roots[4] = { &l1, &l2, &l3, &t0 };
	vader_string_t* gc_atom_roots[3] = { &l0, &t1, &t2 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l3 = ((vader_struct_vader_front_resolver$DriverNames_t*) l2)->f_sent;
	vader_struct_toolchain_protocol$SourceStageFrame_t* _a0_obj = (vader_struct_toolchain_protocol$SourceStageFrame_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_protocol$SourceStageFrame_t));
	vader_obj_header_init(_a0_obj, 1284u);
	_a0_obj->f_stage = l0;
	_a0_obj->f_sources = l1;
	_a0_obj->f_names = l3;
	t0 = (void*) _a0_obj;
	t1 = toolchain_protocol$server_payload(vader_ref_box(t0));
	t2 = std_numbers$to_hex((uint64_t) vader_string_hash(t1));
	{ vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$recorded_plan(vader_string_t l0) {
	vader_box_t l1 = vader_box_null();
	void* l2 = NULL;
	void* l3 = NULL;
	vader_string_t t0 = 0;
	void* t1 = NULL;
	vader_box_t* gc_roots[1] = { &l1 };
	void** gc_raw_roots[3] = { &l2, &l3, &t1 };
	vader_string_t* gc_atom_roots[2] = { &l0, &t0 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	t0 = vader_front_resolver$stage_plan_path(l0);
	l1 = std_fs$read_file_string(t0, INT64_C(16777216));
	if (l1.tag == 1131u) {
		vader_array_t* _a0_arr = vader_array_new(106u, 0u, 13u, 1301u);
		l2 = (void*) _a0_arr;
		vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 642u);
		l3 = (void*) _a1_arr;
		vader_struct_toolchain_protocol$StagePlan_t* _a2_obj = (vader_struct_toolchain_protocol$StagePlan_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_protocol$StagePlan_t));
		vader_obj_header_init(_a2_obj, 1285u);
		_a2_obj->f_sources = l2;
		_a2_obj->f_bodies = l3;
		t1 = (void*) _a2_obj;
		{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	t0 = l1.payload.s;
	l1 = toolchain_protocol$decode_stage_plan(t0);
	if (l1.tag == 1282u) {
		vader_array_t* _a3_arr = vader_array_new(106u, 0u, 13u, 1301u);
		l2 = (void*) _a3_arr;
		vader_array_t* _a4_arr = vader_array_new(28u, 0u, 0u, 642u);
		l3 = (void*) _a4_arr;
		vader_struct_toolchain_protocol$StagePlan_t* _a5_obj = (vader_struct_toolchain_protocol$StagePlan_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_protocol$StagePlan_t));
		vader_obj_header_init(_a5_obj, 1285u);
		_a5_obj->f_sources = l2;
		_a5_obj->f_bodies = l3;
		t1 = (void*) _a5_obj;
		{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	t1 = l1.payload.obj;
	{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_front_resolver$records_folder(vader_box_t l0) {
	bool l1;
	vader_string_t t0;
	if (l0.tag == 0u) {
		l1 = true;
	} else {
		t0 = l0.payload.s;
		l1 = t0 == 0u;
	}
	if (!(l1)) {
		t0 = l0.payload.s;
		return t0;
	}
	return 489u;
}

static vader_box_t vader_front_resolver$refusal(void* l0, void* l1) {
	vader_box_t l2 = vader_box_null();
	vader_string_t l3 = 0;
	vader_string_t l4 = 0;
	vader_string_t t0 = 0;
	bool t1;
	vader_box_t* gc_roots[1] = { &l2 };
	void** gc_raw_roots[2] = { &l0, &l1 };
	vader_string_t* gc_atom_roots[3] = { &l3, &l4, &t0 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = vader_front_resolver$repeated_interceptor(l1);
	if (!(l2.tag == 0u)) {
		l3 = ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_name;
		l4 = l2.payload.s;
		t0 = concat_5(1307u, l3, 1475u, l4, 1679u);
		{ vader_box_t __vret = vader_box_string(642u, t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_body.tag == 0u) {
		l3 = ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_name;
		t0 = concat_3(1307u, l3, 1397u);
		{ vader_box_t __vret = vader_box_string(642u, t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	t1 = std_core$is_empty__toolchain_ast_TypeParam(((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_type_params);
	if (!(t1)) {
		l3 = ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_name;
		t0 = concat_3(1307u, l3, 1470u);
		{ vader_box_t __vret = vader_box_string(642u, t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	t1 = std_core$is_empty__toolchain_ast_FnParam(((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_params);
	if (t1) {
		l3 = ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_name;
		t0 = concat_3(1307u, l3, 1604u);
		{ vader_box_t __vret = vader_box_string(642u, t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (!(((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_return_type.tag == 0u)) {
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	l3 = ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_name;
	t0 = concat_3(3353u, l3, 1532u);
	{ vader_box_t __vret = vader_box_string(642u, t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_resolver$refused(void* l0, void* l1, vader_string_t l2) {
	void* l3 = NULL;
	void** gc_raw_roots[3] = { &l0, &l1, &l3 };
	vader_string_t* gc_atom_roots[1] = { &l2 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l3 = toolchain_diagnostics$resolver_error((uint8_t) 35, l1, l2);
	vader_array_push_ref((vader_array_t*) l0, l3);
	{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_front_resolver$repeated_interceptor(void* l0) {
	int64_t l1, l2, l4;
	void* l3;
	void* t0;
	bool t1;
	vader_string_t t2;
	l1 = INT64_C(1);
	l2 = vader_array_length(((vader_array_t*) l0));
	while ((l1 < l2)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l1);
		l3 = ((vader_struct_vader_front_resolver$Interceptor_t*) ((vader_struct_vader_front_resolver$Interception_t*) t0)->f_interceptor)->f_origin;
		l4 = INT64_C(0);
		while ((l4 < l1)) {
			t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l4);
			t1 = toolchain_stage$same_origin(((vader_struct_vader_front_resolver$Interceptor_t*) ((vader_struct_vader_front_resolver$Interception_t*) t0)->f_interceptor)->f_origin, l3);
			if (t1) {
				t2 = ((vader_struct_toolchain_stage$DecoratorOrigin_t*) l3)->f_name;
				return vader_box_string(642u, t2);
			}
			l4 = (l4 + INT64_C(1));
		}
		l1 = (l1 + INT64_C(1));
	}
	return vader_box_obj(0u, NULL);
}

static void* vader_front_resolver$replay_warning(void* l0, vader_string_t l1) {
	void* l2 = NULL;
	void* t0 = NULL;
	void* t1 = NULL;
	void** gc_raw_roots[4] = { &l0, &l2, &t0, &t1 };
	vader_string_t* gc_atom_roots[1] = { &l1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_stage$Sources_t*) l0)->f_files);
	VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
	VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
	t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT32_C(0));
	l2 = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_toolchain_ast$Program_t*) t0)->f_span)->f_start;
	vader_struct_toolchain_span$Span_t* _a1_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
	vader_obj_header_init(_a1_obj, 1289u);
	_a1_obj->f_start = l2;
	_a1_obj->f_end = l2;
	t0 = (void*) _a1_obj;
	t1 = vader_front_resolver$replay_warning_at(t0, l1);
	{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$replay_warning_at(void* l0, vader_string_t l1) {
	vader_string_t l2 = 0;
	void* l3 = NULL;
	int64_t l4;
	void* t0 = NULL;
	void** gc_raw_roots[3] = { &l0, &l3, &t0 };
	vader_string_t* gc_atom_roots[2] = { &l1, &l2 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = concat_2(l1, 267u);
	l3 = (void*) &vader_data_5;
	l4 = ((int64_t) (uint32_t) INT32_C(15));
	vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
	VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
	VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
	l3 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l4);
	t0 = toolchain_diagnostics$new_diagnostic((uint8_t) 1, l3, l0, l2);
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$replayed_body_stages(vader_string_t l0) {
	void* l1 = NULL;
	void* l2 = NULL;
	void* l5 = NULL;
	int64_t l3, l4;
	void* t0 = NULL;
	vader_box_t t1 = vader_box_null();
	vader_string_t t2 = 0;
	vader_box_t* gc_roots[1] = { &t1 };
	void** gc_raw_roots[4] = { &l1, &l2, &l5, &t0 };
	vader_string_t* gc_atom_roots[2] = { &l0, &t2 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(36u, 0u, 0u, 660u);
	l1 = (void*) _a0_arr;
	t0 = vader_front_resolver$recorded_plan(l0);
	l2 = ((vader_struct_toolchain_protocol$StagePlan_t*) t0)->f_bodies;
	l3 = vader_array_length(((vader_array_t*) l2));
	l4 = INT64_C(0);
	while ((l4 < l3)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		t1 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l4];
		t2 = t1.payload.s;
		vader_struct_vader_front_resolver$ReplayedBodyStage_t* _a2_obj = (vader_struct_vader_front_resolver$ReplayedBodyStage_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$ReplayedBodyStage_t));
		vader_obj_header_init(_a2_obj, 1807u);
		_a2_obj->f_name = t2;
		_a2_obj->f_project_root = l0;
		l5 = (void*) _a2_obj;
		vader_array_push((vader_array_t*) l1, vader_ref_box(l5));
		l4 = (l4 + INT64_C(1));
	}
	{ void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$replayed_diagnostics(void* l0) {
	void* l1 = NULL;
	void* l2 = NULL;
	void* l5 = NULL;
	int64_t l3, l4;
	vader_box_t l6 = vader_box_null();
	void* t0 = NULL;
	vader_box_t* gc_roots[1] = { &l6 };
	void** gc_raw_roots[5] = { &l0, &l1, &l2, &l5, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(93u, 0u, 13u, 1245u);
	l1 = (void*) _a0_arr;
	l2 = l0;
	l3 = vader_array_length(((vader_array_t*) l2));
	l4 = INT64_C(0);
	while ((l4 < l3)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		t0 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l4);
		l6 = vader_front_resolver$hook_diagnostic(t0);
		if (l6.tag == 1282u) {
			l4 = (l4 + INT64_C(1));
			continue;
		}
		l5 = l6.payload.obj;
		vader_array_push_ref((vader_array_t*) l1, l5);
		l4 = (l4 + INT64_C(1));
	}
	{ void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$replayed_stages(vader_string_t l0) {
	void* l1 = NULL;
	void* l2 = NULL;
	void* l5 = NULL;
	int64_t l3, l4;
	void* t0 = NULL;
	void** gc_raw_roots[4] = { &l1, &l2, &l5, &t0 };
	vader_string_t* gc_atom_roots[1] = { &l0 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(36u, 0u, 0u, 660u);
	l1 = (void*) _a0_arr;
	t0 = vader_front_resolver$recorded_plan(l0);
	l2 = ((vader_struct_toolchain_protocol$StagePlan_t*) t0)->f_sources;
	l3 = vader_array_length(((vader_array_t*) l2));
	l4 = INT64_C(0);
	while ((l4 < l3)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		t0 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l4);
		vader_struct_vader_front_resolver$ReplayedStage_t* _a2_obj = (vader_struct_vader_front_resolver$ReplayedStage_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$ReplayedStage_t));
		vader_obj_header_init(_a2_obj, 1808u);
		_a2_obj->f_spec = t0;
		_a2_obj->f_project_root = l0;
		l5 = (void*) _a2_obj;
		vader_array_push((vader_array_t*) l1, vader_ref_box(l5));
		l4 = (l4 + INT64_C(1));
	}
	{ void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_front_resolver$report_unreassigned_mutables(void* l0) {
	void* l1 = NULL;
	void* l4 = NULL;
	void* l5 = NULL;
	void* l6 = NULL;
	void* l7 = NULL;
	void* l12 = NULL;
	void* l13 = NULL;
	void* l15 = NULL;
	int64_t l2, l3, l8, l9;
	vader_string_t l10 = 0;
	vader_string_t l11 = 0;
	vader_string_t l14 = 0;
	bool t0;
	int64_t t1;
	void* t2 = NULL;
	void** gc_raw_roots[10] = { &l0, &l1, &l4, &l5, &l6, &l7, &l12, &l13, &l15, &t2 };
	vader_string_t* gc_atom_roots[3] = { &l10, &l11, &l14 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 10u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l1 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_mutable_decls;
	l2 = vader_array_length(((vader_array_t*) l1));
	l3 = INT64_C(0);
	while ((l3 < l2)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		l4 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l3);
		l5 = ((vader_struct_vader_front_resolver$MutableDecl_t*) l4)->f_syms;
		t0 = vader_front_resolver$has_reassignment(l0, l5);
		if (t0) {
			l3 = (l3 + INT64_C(1));
			continue;
		}
		t1 = vader_array_length(((vader_array_t*) ((vader_struct_vader_front_resolver$MutableDecl_t*) l4)->f_syms));
		vader_array_t* _a1_arr = vader_array_reserve(28u, (int64_t) t1, 0u, 642u);
		l6 = (void*) _a1_arr;
		l7 = ((vader_struct_vader_front_resolver$MutableDecl_t*) l4)->f_syms;
		l8 = vader_array_length(((vader_array_t*) l7));
		l9 = INT64_C(0);
		while ((l9 < l8)) {
			vader_array_t* _a2_slotarr = ((vader_array_t*) l7);
			VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
			t2 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l9);
			l10 = ((vader_struct_vader_core_symbol$Symbol_t*) t2)->f_name;
			vader_array_push_scalar((vader_array_t*) l6, vader_box_string(642u, l10));
			l9 = (l9 + INT64_C(1));
		}
		l11 = std_string$join(l6, 1650u);
		l12 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_diags;
		l13 = ((vader_struct_vader_front_resolver$MutableDecl_t*) l4)->f_span;
		l14 = concat_3(1307u, l11, 1307u);
		l15 = toolchain_diagnostics$warning((uint8_t) 12, l13, l14);
		vader_array_push_ref((vader_array_t*) l12, l15);
		l3 = (l3 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static void* vader_front_resolver$reports_read(void* l0, void* l1) {
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
	vader_struct___lambda_env_vader_front_resolver_37_t* _a0_obj = (vader_struct___lambda_env_vader_front_resolver_37_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_front_resolver_37_t));
	vader_obj_header_init(_a0_obj, 810u);
	_a0_obj->f_cap_0 = l1;
	l3 = (void*) _a0_obj;
	t0 = vader_array_length(((vader_array_t*) l2));
	vader_array_t* _a1_arr = vader_array_reserve(102u, (int64_t) t0, 13u, 1283u);
	l4 = (void*) _a1_arr;
	l5 = vader_array_length(((vader_array_t*) l2));
	l6 = INT64_C(0);
	while ((l6 < l5)) {
		vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
		l7 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l6);
		l8 = __lambda_vader_front_resolver_36(l3, l7);
		vader_array_push_ref((vader_array_t*) l4, l8);
		l6 = (l6 + INT64_C(1));
	}
	{ void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$request_files(void* l0) {
	void* l1 = NULL;
	void* l2 = NULL;
	void* l6 = NULL;
	void* l7 = NULL;
	void* l8 = NULL;
	int64_t l3, l4;
	vader_string_t l5 = 0;
	vader_string_t l9 = 0;
	vader_string_t t0 = 0;
	vader_box_t t1 = vader_box_null();
	void* t2 = NULL;
	bool t3;
	vader_box_t* gc_roots[1] = { &t1 };
	void** gc_raw_roots[7] = { &l0, &l1, &l2, &l6, &l7, &l8, &t2 };
	vader_string_t* gc_atom_roots[3] = { &l5, &l9, &t0 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	t0 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) ((vader_struct_toolchain_ast$FnDecl_t*) ((vader_struct_toolchain_stage$BodyRequest_t*) l0)->f_decl)->f_span)->f_start)->f_file;
	vader_array_t* _a0_arr = vader_array_new(28u, 1u, 0u, 642u);
	vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 0u] = vader_box_string(642u, t0);
	l1 = (void*) _a0_arr;
	l2 = ((vader_struct_toolchain_stage$BodyRequest_t*) l0)->f_declarations;
	l3 = vader_array_length(((vader_array_t*) l2));
	l4 = INT64_C(0);
	while ((l4 < l3)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		t1 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l4);
		t2 = toolchain_ast$decl_span(t1);
		l5 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) t2)->f_start)->f_file;
		vader_array_push_scalar((vader_array_t*) l1, vader_box_string(642u, l5));
		l4 = (l4 + INT64_C(1));
	}
	vader_array_t* _a2_arr = vader_array_new(28u, 0u, 0u, 642u);
	l2 = (void*) _a2_arr;
	vader_array_t* _a3_arr = vader_array_new(28u, 0u, 0u, 642u);
	l6 = (void*) _a3_arr;
	vader_array_t* _a4_arr = vader_array_new(26u, 0u, 12u, 640u);
	l7 = (void*) _a4_arr;
	vader_array_t* _a5_arr = vader_array_new(29u, 0u, 7u, 645u);
	l8 = (void*) _a5_arr;
	vader_struct_std_collections$Map__string__bool_t* _a6_obj = (vader_struct_std_collections$Map__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__bool_t));
	vader_obj_header_init(_a6_obj, 1010u);
	_a6_obj->f_ekeys = l6;
	_a6_obj->f_evals = l7;
	_a6_obj->f_index = l8;
	_a6_obj->f_mask = INT64_C(0);
	_a6_obj->f_grow_at = INT64_C(0);
	_a6_obj->f_size = INT64_C(0);
	_a6_obj->f_tombs = INT64_C(0);
	t2 = (void*) _a6_obj;
	vader_struct_std_collections$Set__string_t* _a7_obj = (vader_struct_std_collections$Set__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__string_t));
	vader_obj_header_init(_a7_obj, 1110u);
	_a7_obj->f_inner = t2;
	l6 = (void*) _a7_obj;
	l3 = vader_array_length(((vader_array_t*) l1));
	l4 = INT64_C(0);
	while ((l4 < l3)) {
		vader_array_t* _a8_slotarr = ((vader_array_t*) l1);
		VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
		t1 = vader_array_box_slots(_a8_slotarr->buf)[vader_array_offset(_a8_slotarr) + (size_t) l4];
		l5 = t1.payload.s;
		t3 = std_collections$add__string(l6, l5);
		if (t3) {
			l9 = l5;
			vader_array_push_scalar((vader_array_t*) l2, vader_box_string(642u, l9));
		}
		l4 = (l4 + INT64_C(1));
	}
	{ void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
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
	vader_array_t* _a0_arr = vader_array_new(73u, 0u, 13u, 1181u);
	l1 = (void*) _a0_arr;
	l2 = l0;
	l3 = vader_array_length(((vader_array_t*) l2));
	l4 = INT64_C(0);
	while ((l4 < l3)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		l5 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l4);
		l6 = ((vader_struct_toolchain_ast$FnDecl_t*) l5)->f_body;
		if (l6.tag == 0u) {
			vader_array_push_ref((vader_array_t*) l1, l5);
		} else if (!(l6.tag == 1150u)) {
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
	if (l0.tag == 1224u) {
		t0 = l0.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (!(l0.tag == 1181u)) {
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
	l5 = std_collections$Map$std_core$Index$at__string__Any(l2, l6);
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
	l4 = std_collections$Map$std_core$Index$at__i32__Any(l2, l3);
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
	void* l6 = NULL;
	vader_box_t t0 = vader_box_null();
	vader_box_t* gc_roots[1] = { &t0 };
	void** gc_raw_roots[6] = { &l0, &l2, &l3, &l4, &l5, &l6 };
	vader_string_t* gc_atom_roots[1] = { &l1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_bases;
	l3 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_index;
	l4 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_overlay;
	l5 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_diags;
	l6 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_module_server;
	t0 = vader_front_resolver$resolve_lazy(l1, l2, l3, l4, l5, l6);
	{ vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_front_resolver$resolve_late_body(void* l0, void* l1, void* l2, void* l3) {
	void* l4 = NULL;
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
	void* l20 = NULL;
	void* l21 = NULL;
	void* l22 = NULL;
	void* l23 = NULL;
	vader_box_t l5 = vader_box_null();
	vader_string_t l6 = 0;
	int64_t l24, l25;
	int32_t l26;
	vader_string_t t0 = 0;
	void* t1 = NULL;
	vader_box_t* gc_roots[1] = { &l5 };
	void** gc_raw_roots[23] = {
		&l0, &l1, &l2, &l3, &l4, &l7, &l8, &l9, &l10, &l11, &l12, &l13, &l14, &l15, &l16, &l17,
		&l18, &l19, &l20, &l21, &l22, &l23, &t1,
	};
	vader_string_t* gc_atom_roots[2] = { &l6, &t0 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 23u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l5 = ((vader_struct_toolchain_ast$FnDecl_t*) ((vader_struct_vader_front_resolver$LateFn_t*) l3)->f_decl)->f_body;
	if (l5.tag == 0u) {
		l6 = ((vader_struct_toolchain_ast$FnDecl_t*) ((vader_struct_vader_front_resolver$LateFn_t*) l3)->f_decl)->f_name;
		t0 = concat_3(3124u, l6, 1619u);
		vader_host_std_core$Runtime$panic(t0);
		vader_unreachable("a no-return call returned");
	} else {
		l4 = l5.payload.obj;
		l7 = ((vader_struct_vader_front_resolver$ResolvedModule_t*) l0)->f_idents;
		l8 = ((vader_struct_vader_front_resolver$ResolvedModule_t*) l0)->f_immutable_locals;
		l9 = ((vader_struct_vader_front_resolver$ResolvedModule_t*) l0)->f_fallback_names;
		l10 = ((vader_struct_vader_front_resolver$ResolvedModule_t*) l0)->f_type_param_bounds;
		vader_array_t* _a0_arr = vader_array_new(347u, 0u, 13u, 1801u);
		l11 = (void*) _a0_arr;
		vader_array_t* _a1_arr = vader_array_new(29u, 0u, 7u, 645u);
		l12 = (void*) _a1_arr;
		vader_array_t* _a2_arr = vader_array_new(26u, 0u, 12u, 640u);
		l13 = (void*) _a2_arr;
		vader_array_t* _a3_arr = vader_array_new(29u, 0u, 7u, 645u);
		l14 = (void*) _a3_arr;
		vader_struct_std_collections$Map__i32__bool_t* _a4_obj = (vader_struct_std_collections$Map__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__bool_t));
		vader_obj_header_init(_a4_obj, 919u);
		_a4_obj->f_ekeys = l12;
		_a4_obj->f_evals = l13;
		_a4_obj->f_index = l14;
		_a4_obj->f_mask = INT64_C(0);
		_a4_obj->f_grow_at = INT64_C(0);
		_a4_obj->f_size = INT64_C(0);
		_a4_obj->f_tombs = INT64_C(0);
		t1 = (void*) _a4_obj;
		vader_struct_std_collections$Set__i32_t* _a5_obj = (vader_struct_std_collections$Set__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__i32_t));
		vader_obj_header_init(_a5_obj, 1108u);
		_a5_obj->f_inner = t1;
		l12 = (void*) _a5_obj;
		vader_array_t* _a6_arr = vader_array_new(29u, 0u, 7u, 645u);
		l13 = (void*) _a6_arr;
		vader_array_t* _a7_arr = vader_array_new(29u, 0u, 7u, 645u);
		l14 = (void*) _a7_arr;
		l15 = ((vader_struct_vader_front_resolver$ResolvedModule_t*) l0)->f_loop_rebinds;
		l16 = ((vader_struct_vader_front_resolver$ResolvedModule_t*) l0)->f_closure_rebound;
		vader_array_t* _a8_arr = vader_array_new(29u, 0u, 7u, 645u);
		l17 = (void*) _a8_arr;
		vader_array_t* _a9_arr = vader_array_new(35u, 0u, 0u, 653u);
		l18 = (void*) _a9_arr;
		vader_array_t* _a10_arr = vader_array_new(29u, 0u, 7u, 645u);
		l19 = (void*) _a10_arr;
		vader_struct_std_collections$Map__i32__Any_t* _a11_obj = (vader_struct_std_collections$Map__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__Any_t));
		vader_obj_header_init(_a11_obj, 916u);
		_a11_obj->f_ekeys = l17;
		_a11_obj->f_evals = l18;
		_a11_obj->f_index = l19;
		_a11_obj->f_mask = INT64_C(0);
		_a11_obj->f_grow_at = INT64_C(0);
		_a11_obj->f_size = INT64_C(0);
		_a11_obj->f_tombs = INT64_C(0);
		l17 = (void*) _a11_obj;
		vader_array_t* _a12_arr = vader_array_new(93u, 0u, 13u, 1245u);
		l18 = (void*) _a12_arr;
		vader_array_t* _a13_arr = vader_array_new(28u, 0u, 0u, 642u);
		l19 = (void*) _a13_arr;
		vader_array_t* _a14_arr = vader_array_new(35u, 0u, 0u, 653u);
		l20 = (void*) _a14_arr;
		vader_array_t* _a15_arr = vader_array_new(29u, 0u, 7u, 645u);
		l21 = (void*) _a15_arr;
		vader_struct_std_collections$Map__string__Any_t* _a16_obj = (vader_struct_std_collections$Map__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any_t));
		vader_obj_header_init(_a16_obj, 1004u);
		_a16_obj->f_ekeys = l19;
		_a16_obj->f_evals = l20;
		_a16_obj->f_index = l21;
		_a16_obj->f_mask = INT64_C(0);
		_a16_obj->f_grow_at = INT64_C(0);
		_a16_obj->f_size = INT64_C(0);
		_a16_obj->f_tombs = INT64_C(0);
		t1 = (void*) _a16_obj;
		l19 = vader_front_resolver$new_scope(t1);
		l6 = ((vader_struct_vader_front_resolver$ResolvedModule_t*) l0)->f_path;
		vader_array_t* _a17_arr = vader_array_new(28u, 0u, 0u, 642u);
		l20 = (void*) _a17_arr;
		vader_array_t* _a18_arr = vader_array_new(3u, 0u, 13u, 28u);
		l21 = (void*) _a18_arr;
		vader_array_t* _a19_arr = vader_array_new(29u, 0u, 7u, 645u);
		l22 = (void*) _a19_arr;
		vader_struct_std_collections$Map__string__string___t* _a20_obj = (vader_struct_std_collections$Map__string__string___t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__string___t));
		vader_obj_header_init(_a20_obj, 1029u);
		_a20_obj->f_ekeys = l20;
		_a20_obj->f_evals = l21;
		_a20_obj->f_index = l22;
		_a20_obj->f_mask = INT64_C(0);
		_a20_obj->f_grow_at = INT64_C(0);
		_a20_obj->f_size = INT64_C(0);
		_a20_obj->f_tombs = INT64_C(0);
		l20 = (void*) _a20_obj;
		vader_array_t* _a21_arr = vader_array_new(28u, 0u, 0u, 642u);
		l21 = (void*) _a21_arr;
		vader_array_t* _a22_arr = vader_array_new(26u, 0u, 12u, 640u);
		l22 = (void*) _a22_arr;
		vader_array_t* _a23_arr = vader_array_new(29u, 0u, 7u, 645u);
		l23 = (void*) _a23_arr;
		vader_struct_std_collections$Map__string__bool_t* _a24_obj = (vader_struct_std_collections$Map__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__bool_t));
		vader_obj_header_init(_a24_obj, 1010u);
		_a24_obj->f_ekeys = l21;
		_a24_obj->f_evals = l22;
		_a24_obj->f_index = l23;
		_a24_obj->f_mask = INT64_C(0);
		_a24_obj->f_grow_at = INT64_C(0);
		_a24_obj->f_size = INT64_C(0);
		_a24_obj->f_tombs = INT64_C(0);
		t1 = (void*) _a24_obj;
		vader_struct_std_collections$Set__string_t* _a25_obj = (vader_struct_std_collections$Set__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__string_t));
		vader_obj_header_init(_a25_obj, 1110u);
		_a25_obj->f_inner = t1;
		l21 = (void*) _a25_obj;
		vader_struct_vader_front_resolver$ResolveState_t* _a26_obj = (vader_struct_vader_front_resolver$ResolveState_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$ResolveState_t));
		vader_obj_header_init(_a26_obj, 1809u);
		_a26_obj->f_idents = l7;
		_a26_obj->f_immutable_locals = l8;
		_a26_obj->f_fallback_names = l9;
		_a26_obj->f_type_param_bounds = l10;
		_a26_obj->f_mutable_decls = l11;
		_a26_obj->f_reassigned = l12;
		_a26_obj->f_declared_locals = l13;
		_a26_obj->f_rebind_log = l14;
		_a26_obj->f_loop_depth = INT32_C(0);
		_a26_obj->f_loop_rebinds = l15;
		_a26_obj->f_lambda_frame = vader_box_obj(0u, NULL);
		_a26_obj->f_closure_rebound = l16;
		_a26_obj->f_trait_self_params = l17;
		_a26_obj->f_trait_self = vader_box_obj(0u, NULL);
		_a26_obj->f_diags = l18;
		_a26_obj->f_scope = l19;
		_a26_obj->f_module_path = l6;
		_a26_obj->f_in_core = false;
		_a26_obj->f_factory = l2;
		_a26_obj->f_ambiguous = l20;
		_a26_obj->f_overloaded = l21;
		_a26_obj->f_file_scopes = l1;
		l7 = (void*) _a26_obj;
		l8 = ((vader_struct_vader_front_resolver$LateFn_t*) l3)->f_decl;
		l6 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) ((vader_struct_toolchain_ast$FnDecl_t*) l8)->f_span)->f_start)->f_file;
		l5 = std_collections$Map$std_core$Index$at__string__Any(l1, l6);
		if (l5.tag == 0u) {
			l6 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) ((vader_struct_toolchain_ast$FnDecl_t*) l8)->f_span)->f_start)->f_file;
			t0 = concat_3(3125u, l6, 1307u);
			vader_host_std_core$Runtime$panic(t0);
			vader_unreachable("a no-return call returned");
		} else {
			l9 = l5.payload.obj;
			vader_front_resolver$enter_file(l7, l9);
			vader_front_resolver$push(((vader_struct_vader_front_resolver$ResolveState_t*) l7)->f_scope);
			l5 = ((vader_struct_vader_front_resolver$LateFn_t*) l3)->f_owner;
			if (!(l5.tag == 0u)) {
				l9 = l5.payload.obj;
				vader_front_resolver$bind_impl_params(l7, l9);
			}
			l9 = ((vader_struct_toolchain_ast$FnDecl_t*) l8)->f_type_params;
			l24 = vader_array_length(((vader_array_t*) l9));
			l25 = INT64_C(0);
			while ((l25 < l24)) {
				vader_array_t* _a27_slotarr = ((vader_array_t*) l9);
				VADER_ARRAY_RESOLVE_BUF(_a27_slotarr)
				l10 = vader_array_ref_load_obj(_a27_slotarr->buf, vader_array_offset(_a27_slotarr) + (size_t) l25);
				l6 = ((vader_struct_toolchain_ast$TypeParam_t*) l10)->f_name;
				l11 = ((vader_struct_toolchain_ast$TypeParam_t*) l10)->f_span;
				vader_front_resolver$bind_declared(l7, l6, l11);
				l25 = (l25 + INT64_C(1));
			}
			l8 = ((vader_struct_toolchain_ast$FnDecl_t*) l8)->f_params;
			l24 = vader_array_length(((vader_array_t*) l8));
			l25 = INT64_C(0);
			while ((l25 < l24)) {
				vader_array_t* _a28_slotarr = ((vader_array_t*) l8);
				VADER_ARRAY_RESOLVE_BUF(_a28_slotarr)
				l9 = vader_array_ref_load_obj(_a28_slotarr->buf, vader_array_offset(_a28_slotarr) + (size_t) l25);
				l6 = ((vader_struct_toolchain_ast$FnParam_t*) l9)->f_name;
				l10 = ((vader_struct_toolchain_ast$FnParam_t*) l9)->f_span;
				vader_front_resolver$bind_declared(l7, l6, l10);
				l25 = (l25 + INT64_C(1));
			}
			vader_front_resolver$walk_body(l7, l4);
			vader_front_resolver$pop(((vader_struct_vader_front_resolver$ResolveState_t*) l7)->f_scope);
			vader_front_resolver$report_unreassigned_mutables(l7);
			l4 = vader_front_resolver$rebind_free_locals(l7);
			l8 = ((vader_struct_std_collections$Map__i32__bool_t*) ((vader_struct_std_collections$Set__i32_t*) l4)->f_inner)->f_ekeys;
			l24 = INT64_C(0);
			l25 = ((vader_struct_std_collections$Map__i32__bool_t*) ((vader_struct_std_collections$Set__i32_t*) l4)->f_inner)->f_size;
			while ((l24 < l25)) {
				vader_array_t* _a29_slotarr = ((vader_array_t*) l8);
				VADER_ARRAY_RESOLVE_BUF(_a29_slotarr)
				VADER_ARRAY_CHECK_INDEX(_a29_slotarr, l24)
				l26 = ((int32_t*) _a29_slotarr->buf->slots)[vader_array_offset(_a29_slotarr) + (size_t) l24];
				std_collections$add__i32(((vader_struct_vader_front_resolver$ResolvedModule_t*) l0)->f_rebind_free, l26);
				l24 = (l24 + INT64_C(1));
			}
			l4 = ((vader_struct_vader_front_resolver$ResolveState_t*) l7)->f_reassigned;
			l8 = ((vader_struct_std_collections$Map__i32__bool_t*) ((vader_struct_std_collections$Set__i32_t*) l4)->f_inner)->f_ekeys;
			l24 = INT64_C(0);
			l25 = ((vader_struct_std_collections$Map__i32__bool_t*) ((vader_struct_std_collections$Set__i32_t*) l4)->f_inner)->f_size;
			while ((l24 < l25)) {
				vader_array_t* _a30_slotarr = ((vader_array_t*) l8);
				VADER_ARRAY_RESOLVE_BUF(_a30_slotarr)
				VADER_ARRAY_CHECK_INDEX(_a30_slotarr, l24)
				l26 = ((int32_t*) _a30_slotarr->buf->slots)[vader_array_offset(_a30_slotarr) + (size_t) l24];
				std_collections$remove__i32(((vader_struct_vader_front_resolver$ResolvedModule_t*) l0)->f_rebind_free, l26);
				l24 = (l24 + INT64_C(1));
			}
			{ void* __vret = ((vader_struct_vader_front_resolver$ResolveState_t*) l7)->f_diags; vader_gc_top = gc_frame.prev; return __vret; }
		}
	}
	vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_front_resolver$resolve_lazy(vader_string_t l0, void* l1, void* l2, void* l3, void* l4, void* l5) {
	vader_box_t l6 = vader_box_null(), l8 = vader_box_null(), l12 = vader_box_null(), l15 = vader_box_null();
	void* l7 = NULL;
	void* l14 = NULL;
	void* l16 = NULL;
	void* l18 = NULL;
	uint8_t l9;
	int64_t l10, l11;
	vader_string_t l13 = 0;
	vader_string_t l17 = 0;
	void* t0 = NULL;
	bool t1;
	vader_string_t t2 = 0;
	vader_box_t* gc_roots[4] = { &l6, &l8, &l12, &l15 };
	void** gc_raw_roots[10] = { &l1, &l2, &l3, &l4, &l5, &l7, &l14, &l16, &l18, &t0 };
	vader_string_t* gc_atom_roots[4] = { &l0, &l13, &l17, &t2 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 4u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l6 = std_collections$Map$std_core$Index$at__string__Any(l2, l0);
	if (l6.tag == 1777u) {
		t0 = l6.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l6 = vader_front_resolver$stage_serving(l5, l0);
	if (l6.tag == 0u) {
		l8 = vader_box_obj(0u, NULL);
		l9 = (uint8_t) 0;
		vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
		l7 = (void*) _a0_arr;
		l10 = INT64_C(0);
		l11 = vader_array_length(((vader_array_t*) l1));
		while ((l10 < l11)) {
			if (!(l8.tag == 0u)) {
				vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
				VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
				VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l10)
				t0 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l10);
				t1 = ((vader_struct_vader_front_resolver$IncludePath_t*) t0)->f_merge;
				if (!(t1)) {
					l10 = (l10 + INT64_C(1));
					continue;
				}
			}
			vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
			VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
			VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l10)
			t0 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l10);
			l12 = vader_front_resolver$rooted_candidate(t0, l0);
			if (l12.tag == 0u) {
				l10 = (l10 + INT64_C(1));
				continue;
			}
			l13 = l12.payload.s;
			t1 = std_fs$is_dir(l13);
			if (t1) {
				l15 = vader_front_resolver$scan_folder(l13, l3, l4);
				if (l15.tag == 0u) {
					l10 = (l10 + INT64_C(1));
					continue;
				}
				l14 = l15.payload.obj;
				t2 = ((vader_struct_vader_front_resolver$FolderBucket_t*) l14)->f_name;
				if (t2 != l0) {
					l10 = (l10 + INT64_C(1));
					continue;
				}
				if (l8.tag == 0u) {
					l8 = vader_box_string(642u, l13);
					vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
					VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
					VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l10)
					t0 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l10);
					l9 = ((vader_struct_vader_front_resolver$IncludePath_t*) t0)->f_origin;
					l16 = ((vader_struct_vader_front_resolver$FolderBucket_t*) l14)->f_files;
					vader_array_push_all((vader_array_t*) l7, (vader_array_t*) l16);
					l10 = (l10 + INT64_C(1));
					continue;
				}
				l17 = l8.payload.s;
				if (l13 == l17) {
					l10 = (l10 + INT64_C(1));
					continue;
				}
				l18 = ((vader_struct_vader_front_resolver$FolderBucket_t*) l14)->f_files;
				vader_array_push_all((vader_array_t*) l7, (vader_array_t*) l18);
				l10 = (l10 + INT64_C(1));
				continue;
			}
			l10 = (l10 + INT64_C(1));
		}
		if (l8.tag == 0u) {
			{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
		}
		l13 = l8.payload.s;
		vader_array_t* _a4_arr = vader_array_new(28u, 0u, 0u, 642u);
		l14 = (void*) _a4_arr;
		vader_array_t* _a5_arr = vader_array_new(28u, 0u, 0u, 642u);
		l16 = (void*) _a5_arr;
		vader_array_t* _a6_arr = vader_array_new(29u, 0u, 7u, 645u);
		l18 = (void*) _a6_arr;
		vader_struct_std_collections$Map__string__string_t* _a7_obj = (vader_struct_std_collections$Map__string__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__string_t));
		vader_obj_header_init(_a7_obj, 1028u);
		_a7_obj->f_ekeys = l14;
		_a7_obj->f_evals = l16;
		_a7_obj->f_index = l18;
		_a7_obj->f_mask = INT64_C(0);
		_a7_obj->f_grow_at = INT64_C(0);
		_a7_obj->f_size = INT64_C(0);
		_a7_obj->f_tombs = INT64_C(0);
		l14 = (void*) _a7_obj;
		vader_struct_vader_front_resolver$DiscoveredModule_t* _a8_obj = (vader_struct_vader_front_resolver$DiscoveredModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$DiscoveredModule_t));
		vader_obj_header_init(_a8_obj, 1777u);
		_a8_obj->f_name = l0;
		_a8_obj->f_folder = l13;
		_a8_obj->f_files = l7;
		_a8_obj->f_origin = l9;
		_a8_obj->f_texts = l14;
		l14 = (void*) _a8_obj;
		std_collections$Map$std_core$IndexSet$set_at__string__Any(l2, l0, vader_ref_box(l14));
		{ vader_box_t __vret = vader_ref_box(l14); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l6 = vader_front_resolver$written_module(l5, l6, l0, l3, l4);
	if (l6.tag == 0u) {
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	l7 = l6.payload.obj;
	std_collections$Map$std_core$IndexSet$set_at__string__Any(l2, l0, vader_ref_box(l7));
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
	vader_array_t* _a0_arr = vader_array_new(333u, 0u, 13u, 1772u);
	l5 = (void*) _a0_arr;
	vader_struct_vader_front_resolver$SourceFile_t* _a1_obj = (vader_struct_vader_front_resolver$SourceFile_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$SourceFile_t));
	vader_obj_header_init(_a1_obj, 1814u);
	_a1_obj->f_path = l4;
	_a1_obj->f_content = 0u;
	_a1_obj->f_program = l0;
	_a1_obj->f_origins = l5;
	t0 = (void*) _a1_obj;
	vader_array_t* _a2_arr = vader_array_new(352u, 1u, 13u, 1814u);
	((void**) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 0u] = t0;
	l5 = (void*) _a2_arr;
	vader_array_t* _a3_arr = vader_array_new(28u, 0u, 0u, 642u);
	l6 = (void*) _a3_arr;
	vader_array_t* _a4_arr = vader_array_new(35u, 0u, 0u, 653u);
	l7 = (void*) _a4_arr;
	vader_array_t* _a5_arr = vader_array_new(29u, 0u, 7u, 645u);
	l8 = (void*) _a5_arr;
	vader_struct_std_collections$Map__string__Any_t* _a6_obj = (vader_struct_std_collections$Map__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any_t));
	vader_obj_header_init(_a6_obj, 1004u);
	_a6_obj->f_ekeys = l6;
	_a6_obj->f_evals = l7;
	_a6_obj->f_index = l8;
	_a6_obj->f_mask = INT64_C(0);
	_a6_obj->f_grow_at = INT64_C(0);
	_a6_obj->f_size = INT64_C(0);
	_a6_obj->f_tombs = INT64_C(0);
	l6 = (void*) _a6_obj;
	vader_array_t* _a7_arr = vader_array_new(28u, 0u, 0u, 642u);
	l7 = (void*) _a7_arr;
	vader_array_t* _a8_arr = vader_array_new(35u, 0u, 0u, 653u);
	l8 = (void*) _a8_arr;
	vader_array_t* _a9_arr = vader_array_new(29u, 0u, 7u, 645u);
	l9 = (void*) _a9_arr;
	vader_struct_std_collections$Map__string__Any_t* _a10_obj = (vader_struct_std_collections$Map__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any_t));
	vader_obj_header_init(_a10_obj, 1004u);
	_a10_obj->f_ekeys = l7;
	_a10_obj->f_evals = l8;
	_a10_obj->f_index = l9;
	_a10_obj->f_mask = INT64_C(0);
	_a10_obj->f_grow_at = INT64_C(0);
	_a10_obj->f_size = INT64_C(0);
	_a10_obj->f_tombs = INT64_C(0);
	l7 = (void*) _a10_obj;
	t0 = vader_front_resolver$resolve_module_files(l5, l1, l1, l2, l3, l6, l7);
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_front_resolver$resolve_module_files(void* l0, vader_string_t l1, vader_string_t l2, void* l3, void* l4, void* l5, void* l6) {
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
	int64_t l13, l14, l24, l25;
	vader_string_t l16 = 0;
	vader_string_t l18 = 0;
	int64_t t0;
	vader_box_t t1 = vader_box_null();
	vader_string_t t2 = 0;
	void* t3 = NULL;
	vader_box_t* gc_roots[1] = { &t1 };
	void** gc_raw_roots[30] = {
		&l0, &l3, &l4, &l5, &l6, &l7, &l8, &l9, &l10, &l11, &l12, &l15, &l17, &l19, &l20, &l21,
		&l22, &l23, &l26, &l27, &l28, &l29, &l30, &l31, &l32, &l33, &l34, &l35, &l36, &t3,
	};
	vader_string_t* gc_atom_roots[5] = { &l1, &l2, &l16, &l18, &t2 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 30u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l7 = vader_front_resolver$make_builtin_scope(l3);
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
	l8 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(35u, 0u, 0u, 653u);
	l9 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 645u);
	l10 = (void*) _a2_arr;
	vader_struct_std_collections$Map__string__Any_t* _a3_obj = (vader_struct_std_collections$Map__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any_t));
	vader_obj_header_init(_a3_obj, 1004u);
	_a3_obj->f_ekeys = l8;
	_a3_obj->f_evals = l9;
	_a3_obj->f_index = l10;
	_a3_obj->f_mask = INT64_C(0);
	_a3_obj->f_grow_at = INT64_C(0);
	_a3_obj->f_size = INT64_C(0);
	_a3_obj->f_tombs = INT64_C(0);
	l8 = (void*) _a3_obj;
	t0 = vader_array_length(((vader_array_t*) l0));
	vader_array_t* _a4_arr = vader_array_reserve(83u, (int64_t) t0, 13u, 1213u);
	l9 = (void*) _a4_arr;
	vader_array_t* _a5_arr = vader_array_new(224u, 0u, 13u, 1491u);
	l10 = (void*) _a5_arr;
	vader_array_t* _a6_arr = vader_array_new(93u, 0u, 13u, 1245u);
	l11 = (void*) _a6_arr;
	l12 = l0;
	l13 = vader_array_length(((vader_array_t*) l12));
	l14 = INT64_C(0);
	while ((l14 < l13)) {
		vader_array_t* _a7_slotarr = ((vader_array_t*) l12);
		VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l14)
		l15 = vader_array_ref_load_obj(_a7_slotarr->buf, vader_array_offset(_a7_slotarr) + (size_t) l14);
		l16 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) l15)->f_program)->f_file;
		l17 = vader_front_resolver$file_imports(l4, l16);
		l18 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) l15)->f_program)->f_file;
		l19 = vader_front_resolver$file_scope(l17, l4, l5, l6, l7);
		std_collections$Map$std_core$IndexSet$set_at__string__Any(l8, l18, vader_ref_box(l19));
		l20 = ((vader_struct_vader_front_resolver$SourceFile_t*) l15)->f_program;
		vader_array_push_ref((vader_array_t*) l9, l20);
		l21 = ((vader_struct_vader_front_resolver$FileImports_t*) l17)->f_bindings;
		l22 = ((vader_struct_std_collections$Map__string__vader_core_symbol_Symbol_t*) l21)->f_ekeys;
		l23 = ((vader_struct_std_collections$Map__string__vader_core_symbol_Symbol_t*) l21)->f_evals;
		l24 = INT64_C(0);
		l25 = ((vader_struct_std_collections$Map__string__vader_core_symbol_Symbol_t*) l21)->f_size;
		while ((l24 < l25)) {
			vader_array_t* _a8_slotarr = ((vader_array_t*) l22);
			VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
			VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l24)
			t1 = vader_array_box_slots(_a8_slotarr->buf)[vader_array_offset(_a8_slotarr) + (size_t) l24];
			t2 = t1.payload.s;
			vader_array_t* _a9_slotarr = ((vader_array_t*) l23);
			VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
			VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l24)
			l26 = vader_array_ref_load_obj(_a9_slotarr->buf, vader_array_offset(_a9_slotarr) + (size_t) l24);
			vader_array_push_ref((vader_array_t*) l10, l26);
			l24 = (l24 + INT64_C(1));
		}
		l27 = vader_front_resolver$binding_clashes(l4, l17);
		vader_array_push_all((vader_array_t*) l11, (vader_array_t*) l27);
		l14 = (l14 + INT64_C(1));
	}
	l7 = vader_front_resolver$resolve_module_programs(l9, l8, l1, l3);
	vader_array_push_all((vader_array_t*) ((vader_struct_vader_front_resolver$ResolvedFile_t*) l7)->f_diags, (vader_array_t*) l11);
	l8 = ((vader_struct_vader_front_resolver$CollectedModule_t*) l4)->f_symbols;
	l14 = ((vader_struct_std_collections$Map__string__vader_core_symbol_Symbol_t*) l8)->f_size;
	if ((INT64_C(0) < l14)) {
		l13 = ((vader_struct_std_collections$Map__string__vader_core_symbol_Symbol_t*) l8)->f_size;
	} else {
		l13 = INT64_C(0);
	}
	vader_array_t* _a10_arr = vader_array_reserve(224u, (int64_t) l13, 13u, 1491u);
	l9 = (void*) _a10_arr;
	l11 = ((vader_struct_std_collections$Map__string__vader_core_symbol_Symbol_t*) l8)->f_evals;
	l13 = INT64_C(0);
	l14 = ((vader_struct_std_collections$Map__string__vader_core_symbol_Symbol_t*) l8)->f_size;
	while ((l13 < l14)) {
		vader_array_t* _a11_slotarr = ((vader_array_t*) l11);
		VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l13)
		l8 = vader_array_ref_load_obj(_a11_slotarr->buf, vader_array_offset(_a11_slotarr) + (size_t) l13);
		vader_array_push_ref((vader_array_t*) l9, l8);
		l13 = (l13 + INT64_C(1));
	}
	l8 = vader_front_resolver$sort_by_name(l9);
	l9 = ((vader_struct_vader_front_resolver$ResolvedFile_t*) l7)->f_idents;
	l11 = ((vader_struct_vader_front_resolver$ResolvedFile_t*) l7)->f_immutable_locals;
	l12 = ((vader_struct_vader_front_resolver$ResolvedFile_t*) l7)->f_fallback_names;
	l15 = ((vader_struct_vader_front_resolver$ResolvedFile_t*) l7)->f_rebind_free;
	l17 = ((vader_struct_vader_front_resolver$ResolvedFile_t*) l7)->f_loop_rebinds;
	l19 = ((vader_struct_vader_front_resolver$ResolvedFile_t*) l7)->f_closure_rebound;
	l20 = ((vader_struct_vader_front_resolver$CollectedModule_t*) l4)->f_fn_overloads;
	l21 = vader_front_resolver$declaration_index(l4);
	vader_array_t* _a12_arr = vader_array_new(29u, 0u, 7u, 645u);
	l22 = (void*) _a12_arr;
	vader_array_t* _a13_arr = vader_array_new(35u, 0u, 0u, 653u);
	l23 = (void*) _a13_arr;
	vader_array_t* _a14_arr = vader_array_new(29u, 0u, 7u, 645u);
	l26 = (void*) _a14_arr;
	vader_struct_std_collections$Map__i32__Any_t* _a15_obj = (vader_struct_std_collections$Map__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__Any_t));
	vader_obj_header_init(_a15_obj, 916u);
	_a15_obj->f_ekeys = l22;
	_a15_obj->f_evals = l23;
	_a15_obj->f_index = l26;
	_a15_obj->f_mask = INT64_C(0);
	_a15_obj->f_grow_at = INT64_C(0);
	_a15_obj->f_size = INT64_C(0);
	_a15_obj->f_tombs = INT64_C(0);
	l22 = (void*) _a15_obj;
	vader_array_t* _a16_arr = vader_array_new(29u, 0u, 7u, 645u);
	l23 = (void*) _a16_arr;
	vader_array_t* _a17_arr = vader_array_new(35u, 0u, 0u, 653u);
	l26 = (void*) _a17_arr;
	vader_array_t* _a18_arr = vader_array_new(29u, 0u, 7u, 645u);
	l27 = (void*) _a18_arr;
	vader_struct_std_collections$Map__i32__Any_t* _a19_obj = (vader_struct_std_collections$Map__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__Any_t));
	vader_obj_header_init(_a19_obj, 916u);
	_a19_obj->f_ekeys = l23;
	_a19_obj->f_evals = l26;
	_a19_obj->f_index = l27;
	_a19_obj->f_mask = INT64_C(0);
	_a19_obj->f_grow_at = INT64_C(0);
	_a19_obj->f_size = INT64_C(0);
	_a19_obj->f_tombs = INT64_C(0);
	l23 = (void*) _a19_obj;
	vader_array_t* _a20_arr = vader_array_new(29u, 0u, 7u, 645u);
	l26 = (void*) _a20_arr;
	vader_array_t* _a21_arr = vader_array_new(35u, 0u, 0u, 653u);
	l27 = (void*) _a21_arr;
	vader_array_t* _a22_arr = vader_array_new(29u, 0u, 7u, 645u);
	l28 = (void*) _a22_arr;
	vader_struct_std_collections$Map__i32__Any___t* _a23_obj = (vader_struct_std_collections$Map__i32__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__Any___t));
	vader_obj_header_init(_a23_obj, 917u);
	_a23_obj->f_ekeys = l26;
	_a23_obj->f_evals = l27;
	_a23_obj->f_index = l28;
	_a23_obj->f_mask = INT64_C(0);
	_a23_obj->f_grow_at = INT64_C(0);
	_a23_obj->f_size = INT64_C(0);
	_a23_obj->f_tombs = INT64_C(0);
	l26 = (void*) _a23_obj;
	l27 = ((vader_struct_vader_front_resolver$ResolvedFile_t*) l7)->f_type_param_bounds;
	l28 = ((vader_struct_vader_front_resolver$ResolvedFile_t*) l7)->f_trait_self_params;
	l29 = vader_front_resolver$decorators_above_module(l0);
	l7 = ((vader_struct_vader_front_resolver$ResolvedFile_t*) l7)->f_diags;
	vader_array_t* _a24_arr = vader_array_new(29u, 0u, 7u, 645u);
	l30 = (void*) _a24_arr;
	vader_array_t* _a25_arr = vader_array_new(28u, 0u, 0u, 642u);
	l31 = (void*) _a25_arr;
	vader_array_t* _a26_arr = vader_array_new(29u, 0u, 7u, 645u);
	l32 = (void*) _a26_arr;
	vader_struct_std_collections$Map__i32__string_t* _a27_obj = (vader_struct_std_collections$Map__i32__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__string_t));
	vader_obj_header_init(_a27_obj, 932u);
	_a27_obj->f_ekeys = l30;
	_a27_obj->f_evals = l31;
	_a27_obj->f_index = l32;
	_a27_obj->f_mask = INT64_C(0);
	_a27_obj->f_grow_at = INT64_C(0);
	_a27_obj->f_size = INT64_C(0);
	_a27_obj->f_tombs = INT64_C(0);
	l30 = (void*) _a27_obj;
	vader_array_t* _a28_arr = vader_array_new(29u, 0u, 7u, 645u);
	l31 = (void*) _a28_arr;
	vader_array_t* _a29_arr = vader_array_new(49u, 0u, 13u, 1039u);
	l32 = (void*) _a29_arr;
	vader_array_t* _a30_arr = vader_array_new(29u, 0u, 7u, 645u);
	l33 = (void*) _a30_arr;
	vader_struct_std_collections$Map__i32__std_collections_Map_string__vader_core_types_AnyType___vader_core_types_ArrayType___vader_core_types_DistinctType___vader_core_types_EnumType___vader_core_types_FnType___vader_core_types_FreeCharType___vader_core_types_FreeFloatType___vader_core_types_FreeIntType___vader_core_types_InferVar___vader_core_types_NeverType___vader_core_types_PrimitiveType___vader_core_types_RangeType___vader_core_types_SelfType___vader_core_types_StructType___vader_core_types_TraitType___vader_core_types_TupleType___vader_core_types_TypeMetaType___vader_core_types_TypeParamType___vader_core_types_UnionType___vader_core_types_UnresolvedType__t* _a31_obj = (vader_struct_std_collections$Map__i32__std_collections_Map_string__vader_core_types_AnyType___vader_core_types_ArrayType___vader_core_types_DistinctType___vader_core_types_EnumType___vader_core_types_FnType___vader_core_types_FreeCharType___vader_core_types_FreeFloatType___vader_core_types_FreeIntType___vader_core_types_InferVar___vader_core_types_NeverType___vader_core_types_PrimitiveType___vader_core_types_RangeType___vader_core_types_SelfType___vader_core_types_StructType___vader_core_types_TraitType___vader_core_types_TupleType___vader_core_types_TypeMetaType___vader_core_types_TypeParamType___vader_core_types_UnionType___vader_core_types_UnresolvedType__t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__std_collections_Map_string__vader_core_types_AnyType___vader_core_types_ArrayType___vader_core_types_DistinctType___vader_core_types_EnumType___vader_core_types_FnType___vader_core_types_FreeCharType___vader_core_types_FreeFloatType___vader_core_types_FreeIntType___vader_core_types_InferVar___vader_core_types_NeverType___vader_core_types_PrimitiveType___vader_core_types_RangeType___vader_core_types_SelfType___vader_core_types_StructType___vader_core_types_TraitType___vader_core_types_TupleType___vader_core_types_TypeMetaType___vader_core_types_TypeParamType___vader_core_types_UnionType___vader_core_types_UnresolvedType__t));
	vader_obj_header_init(_a31_obj, 927u);
	_a31_obj->f_ekeys = l31;
	_a31_obj->f_evals = l32;
	_a31_obj->f_index = l33;
	_a31_obj->f_mask = INT64_C(0);
	_a31_obj->f_grow_at = INT64_C(0);
	_a31_obj->f_size = INT64_C(0);
	_a31_obj->f_tombs = INT64_C(0);
	l31 = (void*) _a31_obj;
	vader_array_t* _a32_arr = vader_array_new(29u, 0u, 7u, 645u);
	l32 = (void*) _a32_arr;
	vader_array_t* _a33_arr = vader_array_new(45u, 0u, 13u, 1010u);
	l33 = (void*) _a33_arr;
	vader_array_t* _a34_arr = vader_array_new(29u, 0u, 7u, 645u);
	l34 = (void*) _a34_arr;
	vader_struct_std_collections$Map__i32__std_collections_Map_string__bool__t* _a35_obj = (vader_struct_std_collections$Map__i32__std_collections_Map_string__bool__t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__std_collections_Map_string__bool__t));
	vader_obj_header_init(_a35_obj, 925u);
	_a35_obj->f_ekeys = l32;
	_a35_obj->f_evals = l33;
	_a35_obj->f_index = l34;
	_a35_obj->f_mask = INT64_C(0);
	_a35_obj->f_grow_at = INT64_C(0);
	_a35_obj->f_size = INT64_C(0);
	_a35_obj->f_tombs = INT64_C(0);
	l32 = (void*) _a35_obj;
	vader_array_t* _a36_arr = vader_array_new(29u, 0u, 7u, 645u);
	l33 = (void*) _a36_arr;
	vader_array_t* _a37_arr = vader_array_new(48u, 0u, 13u, 1037u);
	l34 = (void*) _a37_arr;
	vader_array_t* _a38_arr = vader_array_new(29u, 0u, 7u, 645u);
	l35 = (void*) _a38_arr;
	vader_struct_std_collections$Map__i32__std_collections_Map_string__vader_core_symbol_Symbol__t* _a39_obj = (vader_struct_std_collections$Map__i32__std_collections_Map_string__vader_core_symbol_Symbol__t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__std_collections_Map_string__vader_core_symbol_Symbol__t));
	vader_obj_header_init(_a39_obj, 926u);
	_a39_obj->f_ekeys = l33;
	_a39_obj->f_evals = l34;
	_a39_obj->f_index = l35;
	_a39_obj->f_mask = INT64_C(0);
	_a39_obj->f_grow_at = INT64_C(0);
	_a39_obj->f_size = INT64_C(0);
	_a39_obj->f_tombs = INT64_C(0);
	l33 = (void*) _a39_obj;
	vader_array_t* _a40_arr = vader_array_new(30u, 0u, 8u, 646u);
	l34 = (void*) _a40_arr;
	vader_array_t* _a41_arr = vader_array_new(26u, 0u, 12u, 640u);
	l35 = (void*) _a41_arr;
	vader_array_t* _a42_arr = vader_array_new(29u, 0u, 7u, 645u);
	l36 = (void*) _a42_arr;
	vader_struct_std_collections$Map__i64__bool_t* _a43_obj = (vader_struct_std_collections$Map__i64__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i64__bool_t));
	vader_obj_header_init(_a43_obj, 968u);
	_a43_obj->f_ekeys = l34;
	_a43_obj->f_evals = l35;
	_a43_obj->f_index = l36;
	_a43_obj->f_mask = INT64_C(0);
	_a43_obj->f_grow_at = INT64_C(0);
	_a43_obj->f_size = INT64_C(0);
	_a43_obj->f_tombs = INT64_C(0);
	t3 = (void*) _a43_obj;
	vader_struct_std_collections$Set__i64_t* _a44_obj = (vader_struct_std_collections$Set__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__i64_t));
	vader_obj_header_init(_a44_obj, 1109u);
	_a44_obj->f_inner = t3;
	l34 = (void*) _a44_obj;
	vader_struct_vader_front_resolver$ResolvedModule_t* _a45_obj = (vader_struct_vader_front_resolver$ResolvedModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$ResolvedModule_t));
	vader_obj_header_init(_a45_obj, 1811u);
	_a45_obj->f_path = l1;
	_a45_obj->f_display_path = l2;
	_a45_obj->f_symbols = l8;
	_a45_obj->f_import_bindings = l10;
	_a45_obj->f_idents = l9;
	_a45_obj->f_immutable_locals = l11;
	_a45_obj->f_fallback_names = l12;
	_a45_obj->f_rebind_free = l15;
	_a45_obj->f_loop_rebinds = l17;
	_a45_obj->f_closure_rebound = l19;
	_a45_obj->f_fn_overloads = l20;
	_a45_obj->f_declarations = l21;
	_a45_obj->f_imports_to = l22;
	_a45_obj->f_alias_types = l23;
	_a45_obj->f_alias_params = l26;
	_a45_obj->f_type_param_bounds = l27;
	_a45_obj->f_trait_self_params = l28;
	_a45_obj->f_module_decorators = l29;
	_a45_obj->f_diags = l7;
	_a45_obj->f_deprecated_messages = l30;
	_a45_obj->f_namespace_member_types = l31;
	_a45_obj->f_namespace_private_members = l32;
	_a45_obj->f_namespace_member_symbols = l33;
	_a45_obj->f_late_bodies = l34;
	t3 = (void*) _a45_obj;
	{ void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
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
	void* l18 = NULL;
	void* l22 = NULL;
	void* l23 = NULL;
	bool l19;
	int64_t l20, l21, l27, l28;
	vader_string_t l24 = 0;
	vader_string_t l26 = 0;
	vader_box_t l25 = vader_box_null(), l29 = vader_box_null();
	void* t0 = NULL;
	bool t1;
	vader_string_t t2 = 0;
	vader_box_t* gc_roots[2] = { &l25, &l29 };
	void** gc_raw_roots[21] = {
		&l0, &l1, &l3, &l4, &l5, &l6, &l7, &l8, &l9, &l10, &l11, &l12, &l13, &l14, &l15, &l16, &l17,
		&l18, &l22, &l23, &t0,
	};
	vader_string_t* gc_atom_roots[4] = { &l2, &l24, &l26, &t2 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 21u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(34u, 0u, 4u, 650u);
	l4 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(35u, 0u, 0u, 653u);
	l5 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 645u);
	l6 = (void*) _a2_arr;
	vader_struct_std_collections$Map__u64__Any_t* _a3_obj = (vader_struct_std_collections$Map__u64__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__u64__Any_t));
	vader_obj_header_init(_a3_obj, 1083u);
	_a3_obj->f_ekeys = l4;
	_a3_obj->f_evals = l5;
	_a3_obj->f_index = l6;
	_a3_obj->f_mask = INT64_C(0);
	_a3_obj->f_grow_at = INT64_C(0);
	_a3_obj->f_size = INT64_C(0);
	_a3_obj->f_tombs = INT64_C(0);
	l4 = (void*) _a3_obj;
	vader_array_t* _a4_arr = vader_array_new(29u, 0u, 7u, 645u);
	l5 = (void*) _a4_arr;
	vader_array_t* _a5_arr = vader_array_new(31u, 0u, 1u, 647u);
	l6 = (void*) _a5_arr;
	vader_array_t* _a6_arr = vader_array_new(29u, 0u, 7u, 645u);
	l7 = (void*) _a6_arr;
	vader_struct_std_collections$Map__i32__vader_front_resolver_ConstLocal_t* _a7_obj = (vader_struct_std_collections$Map__i32__vader_front_resolver_ConstLocal_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__vader_front_resolver_ConstLocal_t));
	vader_obj_header_init(_a7_obj, 949u);
	_a7_obj->f_ekeys = l5;
	_a7_obj->f_evals = l6;
	_a7_obj->f_index = l7;
	_a7_obj->f_mask = INT64_C(0);
	_a7_obj->f_grow_at = INT64_C(0);
	_a7_obj->f_size = INT64_C(0);
	_a7_obj->f_tombs = INT64_C(0);
	l5 = (void*) _a7_obj;
	vader_array_t* _a8_arr = vader_array_new(29u, 0u, 7u, 645u);
	l6 = (void*) _a8_arr;
	vader_array_t* _a9_arr = vader_array_new(35u, 0u, 0u, 653u);
	l7 = (void*) _a9_arr;
	vader_array_t* _a10_arr = vader_array_new(29u, 0u, 7u, 645u);
	l8 = (void*) _a10_arr;
	vader_struct_std_collections$Map__i32__Any_t* _a11_obj = (vader_struct_std_collections$Map__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__Any_t));
	vader_obj_header_init(_a11_obj, 916u);
	_a11_obj->f_ekeys = l6;
	_a11_obj->f_evals = l7;
	_a11_obj->f_index = l8;
	_a11_obj->f_mask = INT64_C(0);
	_a11_obj->f_grow_at = INT64_C(0);
	_a11_obj->f_size = INT64_C(0);
	_a11_obj->f_tombs = INT64_C(0);
	l6 = (void*) _a11_obj;
	vader_array_t* _a12_arr = vader_array_new(29u, 0u, 7u, 645u);
	l7 = (void*) _a12_arr;
	vader_array_t* _a13_arr = vader_array_new(35u, 0u, 0u, 653u);
	l8 = (void*) _a13_arr;
	vader_array_t* _a14_arr = vader_array_new(29u, 0u, 7u, 645u);
	l9 = (void*) _a14_arr;
	vader_struct_std_collections$Map__i32__Any_t* _a15_obj = (vader_struct_std_collections$Map__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__Any_t));
	vader_obj_header_init(_a15_obj, 916u);
	_a15_obj->f_ekeys = l7;
	_a15_obj->f_evals = l8;
	_a15_obj->f_index = l9;
	_a15_obj->f_mask = INT64_C(0);
	_a15_obj->f_grow_at = INT64_C(0);
	_a15_obj->f_size = INT64_C(0);
	_a15_obj->f_tombs = INT64_C(0);
	l7 = (void*) _a15_obj;
	vader_array_t* _a16_arr = vader_array_new(347u, 0u, 13u, 1801u);
	l8 = (void*) _a16_arr;
	vader_array_t* _a17_arr = vader_array_new(29u, 0u, 7u, 645u);
	l9 = (void*) _a17_arr;
	vader_array_t* _a18_arr = vader_array_new(26u, 0u, 12u, 640u);
	l10 = (void*) _a18_arr;
	vader_array_t* _a19_arr = vader_array_new(29u, 0u, 7u, 645u);
	l11 = (void*) _a19_arr;
	vader_struct_std_collections$Map__i32__bool_t* _a20_obj = (vader_struct_std_collections$Map__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__bool_t));
	vader_obj_header_init(_a20_obj, 919u);
	_a20_obj->f_ekeys = l9;
	_a20_obj->f_evals = l10;
	_a20_obj->f_index = l11;
	_a20_obj->f_mask = INT64_C(0);
	_a20_obj->f_grow_at = INT64_C(0);
	_a20_obj->f_size = INT64_C(0);
	_a20_obj->f_tombs = INT64_C(0);
	t0 = (void*) _a20_obj;
	vader_struct_std_collections$Set__i32_t* _a21_obj = (vader_struct_std_collections$Set__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__i32_t));
	vader_obj_header_init(_a21_obj, 1108u);
	_a21_obj->f_inner = t0;
	l9 = (void*) _a21_obj;
	vader_array_t* _a22_arr = vader_array_new(29u, 0u, 7u, 645u);
	l10 = (void*) _a22_arr;
	vader_array_t* _a23_arr = vader_array_new(29u, 0u, 7u, 645u);
	l11 = (void*) _a23_arr;
	vader_array_t* _a24_arr = vader_array_new(34u, 0u, 4u, 650u);
	l12 = (void*) _a24_arr;
	vader_array_t* _a25_arr = vader_array_new(35u, 0u, 0u, 653u);
	l13 = (void*) _a25_arr;
	vader_array_t* _a26_arr = vader_array_new(29u, 0u, 7u, 645u);
	l14 = (void*) _a26_arr;
	vader_struct_std_collections$Map__u64__std_collections_Set_Any__t* _a27_obj = (vader_struct_std_collections$Map__u64__std_collections_Set_Any__t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__u64__std_collections_Set_Any__t));
	vader_obj_header_init(_a27_obj, 1087u);
	_a27_obj->f_ekeys = l12;
	_a27_obj->f_evals = l13;
	_a27_obj->f_index = l14;
	_a27_obj->f_mask = INT64_C(0);
	_a27_obj->f_grow_at = INT64_C(0);
	_a27_obj->f_size = INT64_C(0);
	_a27_obj->f_tombs = INT64_C(0);
	l12 = (void*) _a27_obj;
	vader_array_t* _a28_arr = vader_array_new(29u, 0u, 7u, 645u);
	l13 = (void*) _a28_arr;
	vader_array_t* _a29_arr = vader_array_new(26u, 0u, 12u, 640u);
	l14 = (void*) _a29_arr;
	vader_array_t* _a30_arr = vader_array_new(29u, 0u, 7u, 645u);
	l15 = (void*) _a30_arr;
	vader_struct_std_collections$Map__i32__bool_t* _a31_obj = (vader_struct_std_collections$Map__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__bool_t));
	vader_obj_header_init(_a31_obj, 919u);
	_a31_obj->f_ekeys = l13;
	_a31_obj->f_evals = l14;
	_a31_obj->f_index = l15;
	_a31_obj->f_mask = INT64_C(0);
	_a31_obj->f_grow_at = INT64_C(0);
	_a31_obj->f_size = INT64_C(0);
	_a31_obj->f_tombs = INT64_C(0);
	t0 = (void*) _a31_obj;
	vader_struct_std_collections$Set__i32_t* _a32_obj = (vader_struct_std_collections$Set__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__i32_t));
	vader_obj_header_init(_a32_obj, 1108u);
	_a32_obj->f_inner = t0;
	l13 = (void*) _a32_obj;
	vader_array_t* _a33_arr = vader_array_new(29u, 0u, 7u, 645u);
	l14 = (void*) _a33_arr;
	vader_array_t* _a34_arr = vader_array_new(35u, 0u, 0u, 653u);
	l15 = (void*) _a34_arr;
	vader_array_t* _a35_arr = vader_array_new(29u, 0u, 7u, 645u);
	l16 = (void*) _a35_arr;
	vader_struct_std_collections$Map__i32__Any_t* _a36_obj = (vader_struct_std_collections$Map__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__Any_t));
	vader_obj_header_init(_a36_obj, 916u);
	_a36_obj->f_ekeys = l14;
	_a36_obj->f_evals = l15;
	_a36_obj->f_index = l16;
	_a36_obj->f_mask = INT64_C(0);
	_a36_obj->f_grow_at = INT64_C(0);
	_a36_obj->f_size = INT64_C(0);
	_a36_obj->f_tombs = INT64_C(0);
	l14 = (void*) _a36_obj;
	vader_array_t* _a37_arr = vader_array_new(93u, 0u, 13u, 1245u);
	l15 = (void*) _a37_arr;
	vader_array_t* _a38_arr = vader_array_new(28u, 0u, 0u, 642u);
	l16 = (void*) _a38_arr;
	vader_array_t* _a39_arr = vader_array_new(35u, 0u, 0u, 653u);
	l17 = (void*) _a39_arr;
	vader_array_t* _a40_arr = vader_array_new(29u, 0u, 7u, 645u);
	l18 = (void*) _a40_arr;
	vader_struct_std_collections$Map__string__Any_t* _a41_obj = (vader_struct_std_collections$Map__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any_t));
	vader_obj_header_init(_a41_obj, 1004u);
	_a41_obj->f_ekeys = l16;
	_a41_obj->f_evals = l17;
	_a41_obj->f_index = l18;
	_a41_obj->f_mask = INT64_C(0);
	_a41_obj->f_grow_at = INT64_C(0);
	_a41_obj->f_size = INT64_C(0);
	_a41_obj->f_tombs = INT64_C(0);
	t0 = (void*) _a41_obj;
	l16 = vader_front_resolver$new_scope(t0);
	l17 = l0;
	l19 = false;
	l20 = vader_array_length(((vader_array_t*) l17));
	l21 = INT64_C(0);
	{
		while ((l21 < l20)) {
			vader_array_t* _a42_slotarr = ((vader_array_t*) l17);
			VADER_ARRAY_RESOLVE_BUF(_a42_slotarr)
			t0 = vader_array_ref_load_obj(_a42_slotarr->buf, vader_array_offset(_a42_slotarr) + (size_t) l21);
			t1 = vader_front_resolver$is_core_file(t0);
			if (t1) {
				l19 = true;
				goto end_155;
			}
			l21 = (l21 + INT64_C(1));
		}
		l19 = false;
	} end_155: ;
	vader_array_t* _a43_arr = vader_array_new(28u, 0u, 0u, 642u);
	l17 = (void*) _a43_arr;
	vader_array_t* _a44_arr = vader_array_new(3u, 0u, 13u, 28u);
	l18 = (void*) _a44_arr;
	vader_array_t* _a45_arr = vader_array_new(29u, 0u, 7u, 645u);
	l22 = (void*) _a45_arr;
	vader_struct_std_collections$Map__string__string___t* _a46_obj = (vader_struct_std_collections$Map__string__string___t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__string___t));
	vader_obj_header_init(_a46_obj, 1029u);
	_a46_obj->f_ekeys = l17;
	_a46_obj->f_evals = l18;
	_a46_obj->f_index = l22;
	_a46_obj->f_mask = INT64_C(0);
	_a46_obj->f_grow_at = INT64_C(0);
	_a46_obj->f_size = INT64_C(0);
	_a46_obj->f_tombs = INT64_C(0);
	l17 = (void*) _a46_obj;
	vader_array_t* _a47_arr = vader_array_new(28u, 0u, 0u, 642u);
	l18 = (void*) _a47_arr;
	vader_array_t* _a48_arr = vader_array_new(26u, 0u, 12u, 640u);
	l22 = (void*) _a48_arr;
	vader_array_t* _a49_arr = vader_array_new(29u, 0u, 7u, 645u);
	l23 = (void*) _a49_arr;
	vader_struct_std_collections$Map__string__bool_t* _a50_obj = (vader_struct_std_collections$Map__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__bool_t));
	vader_obj_header_init(_a50_obj, 1010u);
	_a50_obj->f_ekeys = l18;
	_a50_obj->f_evals = l22;
	_a50_obj->f_index = l23;
	_a50_obj->f_mask = INT64_C(0);
	_a50_obj->f_grow_at = INT64_C(0);
	_a50_obj->f_size = INT64_C(0);
	_a50_obj->f_tombs = INT64_C(0);
	t0 = (void*) _a50_obj;
	vader_struct_std_collections$Set__string_t* _a51_obj = (vader_struct_std_collections$Set__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__string_t));
	vader_obj_header_init(_a51_obj, 1110u);
	_a51_obj->f_inner = t0;
	l18 = (void*) _a51_obj;
	vader_struct_vader_front_resolver$ResolveState_t* _a52_obj = (vader_struct_vader_front_resolver$ResolveState_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$ResolveState_t));
	vader_obj_header_init(_a52_obj, 1809u);
	_a52_obj->f_idents = l4;
	_a52_obj->f_immutable_locals = l5;
	_a52_obj->f_fallback_names = l6;
	_a52_obj->f_type_param_bounds = l7;
	_a52_obj->f_mutable_decls = l8;
	_a52_obj->f_reassigned = l9;
	_a52_obj->f_declared_locals = l10;
	_a52_obj->f_rebind_log = l11;
	_a52_obj->f_loop_depth = INT32_C(0);
	_a52_obj->f_loop_rebinds = l12;
	_a52_obj->f_lambda_frame = vader_box_obj(0u, NULL);
	_a52_obj->f_closure_rebound = l13;
	_a52_obj->f_trait_self_params = l14;
	_a52_obj->f_trait_self = vader_box_obj(0u, NULL);
	_a52_obj->f_diags = l15;
	_a52_obj->f_scope = l16;
	_a52_obj->f_module_path = l2;
	_a52_obj->f_in_core = l19;
	_a52_obj->f_factory = l3;
	_a52_obj->f_ambiguous = l17;
	_a52_obj->f_overloaded = l18;
	_a52_obj->f_file_scopes = l1;
	l4 = (void*) _a52_obj;
	l5 = l0;
	l20 = vader_array_length(((vader_array_t*) l5));
	l21 = INT64_C(0);
	for (;;) {
		if ((l21 < l20)) {
			vader_array_t* _a53_slotarr = ((vader_array_t*) l5);
			VADER_ARRAY_RESOLVE_BUF(_a53_slotarr)
			VADER_ARRAY_CHECK_INDEX(_a53_slotarr, l21)
			l6 = vader_array_ref_load_obj(_a53_slotarr->buf, vader_array_offset(_a53_slotarr) + (size_t) l21);
			l24 = ((vader_struct_toolchain_ast$Program_t*) l6)->f_file;
			l25 = std_collections$Map$std_core$Index$at__string__Any(l1, l24);
			if (l25.tag == 0u) {
				l26 = ((vader_struct_toolchain_ast$Program_t*) l6)->f_file;
				t2 = concat_3(3125u, l26, 1307u);
				vader_host_std_core$Runtime$panic(t2);
				vader_unreachable("a no-return call returned");
			} else {
				l7 = l25.payload.obj;
				vader_front_resolver$enter_file(l4, l7);
				l8 = toolchain_ast$module_decorators(l6);
				vader_front_resolver$walk_decorators(l4, l8);
				l9 = ((vader_struct_toolchain_ast$Program_t*) l6)->f_decls;
				l27 = vader_array_length(((vader_array_t*) l9));
				l28 = INT64_C(0);
				while ((l28 < l27)) {
					vader_array_t* _a54_slotarr = ((vader_array_t*) l9);
					VADER_ARRAY_RESOLVE_BUF(_a54_slotarr)
					VADER_ARRAY_CHECK_INDEX(_a54_slotarr, l28)
					l29 = vader_array_ref_load_box(_a54_slotarr->buf, vader_array_offset(_a54_slotarr) + (size_t) l28);
					vader_front_resolver$walk_decl(l4, l29);
					l28 = (l28 + INT64_C(1));
				}
				l21 = (l21 + INT64_C(1));
				continue;
			}
		}
		break;
	}
	vader_front_resolver$report_unreassigned_mutables(l4);
	l5 = ((vader_struct_vader_front_resolver$ResolveState_t*) l4)->f_idents;
	l6 = ((vader_struct_vader_front_resolver$ResolveState_t*) l4)->f_immutable_locals;
	l7 = ((vader_struct_vader_front_resolver$ResolveState_t*) l4)->f_fallback_names;
	l8 = vader_front_resolver$rebind_free_locals(l4);
	l9 = ((vader_struct_vader_front_resolver$ResolveState_t*) l4)->f_loop_rebinds;
	l10 = ((vader_struct_vader_front_resolver$ResolveState_t*) l4)->f_closure_rebound;
	l11 = ((vader_struct_vader_front_resolver$ResolveState_t*) l4)->f_type_param_bounds;
	l12 = ((vader_struct_vader_front_resolver$ResolveState_t*) l4)->f_trait_self_params;
	l4 = ((vader_struct_vader_front_resolver$ResolveState_t*) l4)->f_diags;
	vader_struct_vader_front_resolver$ResolvedFile_t* _a55_obj = (vader_struct_vader_front_resolver$ResolvedFile_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$ResolvedFile_t));
	vader_obj_header_init(_a55_obj, 1810u);
	_a55_obj->f_idents = l5;
	_a55_obj->f_immutable_locals = l6;
	_a55_obj->f_fallback_names = l7;
	_a55_obj->f_rebind_free = l8;
	_a55_obj->f_loop_rebinds = l9;
	_a55_obj->f_closure_rebound = l10;
	_a55_obj->f_type_param_bounds = l11;
	_a55_obj->f_trait_self_params = l12;
	_a55_obj->f_diags = l4;
	t0 = (void*) _a55_obj;
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_front_resolver$resolve_sidecar(vader_string_t l0, vader_string_t l1) {
	vader_box_t l2 = vader_box_null();
	vader_string_t t0 = 0;
	vader_box_t* gc_roots[1] = { &l2 };
	vader_string_t* gc_atom_roots[3] = { &l0, &l1, &t0 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL, 3u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = vader_front_resolver$sidecar_root(l0, l1);
	if (l2.tag == 0u) {
		{ vader_string_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	t0 = l2.payload.s;
	{ vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
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
		{ vader_box_t __vret = vader_box_string(642u, t1); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l2 = ((vader_struct_vader_front_resolver$IncludePath_t*) l0)->f_prefix;
	if (l1 == l2) {
		t0 = ((vader_struct_vader_front_resolver$IncludePath_t*) l0)->f_dir;
		{ vader_box_t __vret = vader_box_string(642u, t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	t0 = ((vader_struct_vader_front_resolver$IncludePath_t*) l0)->f_prefix;
	l2 = concat_2(t0, 534u);
	t2 = std_string$starts_with(l1, l2);
	if (!(t2)) {
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	l2 = ((vader_struct_vader_front_resolver$IncludePath_t*) l0)->f_dir;
	t0 = ((vader_struct_vader_front_resolver$IncludePath_t*) l0)->f_prefix;
	l3 = concat_2(t0, 534u);
	l3 = std_string$trim_prefix(l1, l3);
	t0 = vader_front_resolver$join_path(l2, l3);
	{ vader_box_t __vret = vader_box_string(642u, t0); vader_gc_top = gc_frame.prev; return __vret; }
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
	l6 = vader_array_length(((vader_array_t*) l5));
	l7 = INT64_C(0);
	while ((l7 < l6)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		l8 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l7);
		l9 = ((vader_struct_vader_front_resolver$LoadedModule_t*) l0)->f_collected;
		l10 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) l8)->f_program)->f_file;
		t0 = vader_front_resolver$file_imports(l9, l10);
		l11 = ((vader_struct_vader_front_resolver$FileImports_t*) t0)->f_bindings;
		l12 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) l8)->f_program)->f_decls;
		l13 = vader_array_length(((vader_array_t*) l12));
		l14 = INT64_C(0);
		while ((l14 < l13)) {
			vader_array_t* _a1_slotarr = ((vader_array_t*) l12);
			VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
			l15 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l14);
			if (l15.tag == 1190u) {
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

static void vader_front_resolver$run_source_stages(void* l0, int64_t l1, void* l2, void* l3, void* l4, void* l5) {
	void* l6 = NULL;
	void* l7 = NULL;
	void* l10 = NULL;
	void* l11 = NULL;
	void* l12 = NULL;
	void* l16 = NULL;
	void* l17 = NULL;
	void* l20 = NULL;
	void* l21 = NULL;
	void* l23 = NULL;
	void* l24 = NULL;
	void* l25 = NULL;
	void* l28 = NULL;
	void* l32 = NULL;
	void* l35 = NULL;
	void* l44 = NULL;
	void* l45 = NULL;
	void* l46 = NULL;
	void* l47 = NULL;
	void* l49 = NULL;
	void* l50 = NULL;
	void* l53 = NULL;
	void* l55 = NULL;
	void* l58 = NULL;
	void* l62 = NULL;
	void* l63 = NULL;
	void* l64 = NULL;
	void* l65 = NULL;
	void* l66 = NULL;
	int64_t l8, l9, l13, l14, l18, l19, l26, l27, l31, l34, l56, l57;
	vader_box_t l15 = vader_box_null();
	vader_string_t l22 = 0;
	vader_string_t l29 = 0;
	vader_string_t l30 = 0;
	vader_string_t l33 = 0;
	vader_string_t l36 = 0;
	vader_string_t l37 = 0;
	vader_string_t l38 = 0;
	vader_string_t l39 = 0;
	vader_string_t l40 = 0;
	vader_string_t l41 = 0;
	vader_string_t l42 = 0;
	vader_string_t l43 = 0;
	vader_string_t l48 = 0;
	vader_string_t l51 = 0;
	vader_string_t l52 = 0;
	vader_string_t l54 = 0;
	vader_string_t l59 = 0;
	vader_string_t l60 = 0;
	vader_string_t l61 = 0;
	int64_t t0;
	vader_box_t t1 = vader_box_null();
	void* t2 = NULL;
	bool t3;
	vader_string_t t4 = 0;
	vader_box_t* gc_roots[2] = { &l15, &t1 };
	void** gc_raw_roots[35] = {
		&l0, &l2, &l3, &l4, &l5, &l6, &l7, &l10, &l11, &l12, &l16, &l17, &l20, &l21, &l23, &l24,
		&l25, &l28, &l32, &l35, &l44, &l45, &l46, &l47, &l49, &l50, &l53, &l55, &l58, &l62, &l63,
		&l64, &l65, &l66, &t2,
	};
	vader_string_t* gc_atom_roots[20] = {
		&l22, &l29, &l30, &l33, &l36, &l37, &l38, &l39, &l40, &l41, &l42, &l43, &l48, &l51, &l52,
		&l54, &l59, &l60, &l61, &t4,
	};
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 35u, gc_roots, gc_raw_roots, 0u, NULL, 20u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l6 = l2;
	t0 = vader_array_length(((vader_array_t*) l6));
	vader_array_t* _a0_arr = vader_array_reserve(106u, (int64_t) t0, 13u, 1301u);
	l7 = (void*) _a0_arr;
	l8 = vader_array_length(((vader_array_t*) l6));
	l9 = INT64_C(0);
	while ((l9 < l8)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		t1 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l9);
		l10 = __lambda_vader_front_resolver_8(t1);
		vader_array_push_ref((vader_array_t*) l7, l10);
		l9 = (l9 + INT64_C(1));
	}
	l6 = l7;
	l7 = vader_front_resolver$declared_by(l0, l6);
	vader_array_t* _a2_arr = vader_array_new(28u, 0u, 0u, 642u);
	l10 = (void*) _a2_arr;
	vader_array_t* _a3_arr = vader_array_new(26u, 0u, 12u, 640u);
	l11 = (void*) _a3_arr;
	vader_array_t* _a4_arr = vader_array_new(29u, 0u, 7u, 645u);
	l12 = (void*) _a4_arr;
	vader_struct_std_collections$Map__string__bool_t* _a5_obj = (vader_struct_std_collections$Map__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__bool_t));
	vader_obj_header_init(_a5_obj, 1010u);
	_a5_obj->f_ekeys = l10;
	_a5_obj->f_evals = l11;
	_a5_obj->f_index = l12;
	_a5_obj->f_mask = INT64_C(0);
	_a5_obj->f_grow_at = INT64_C(0);
	_a5_obj->f_size = INT64_C(0);
	_a5_obj->f_tombs = INT64_C(0);
	t2 = (void*) _a5_obj;
	vader_struct_std_collections$Set__string_t* _a6_obj = (vader_struct_std_collections$Set__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__string_t));
	vader_obj_header_init(_a6_obj, 1110u);
	_a6_obj->f_inner = t2;
	l10 = (void*) _a6_obj;
	l8 = l1;
	l9 = vader_array_length(((vader_array_t*) l0));
	while ((l8 < l9)) {
		vader_array_t* _a7_slotarr = ((vader_array_t*) l0);
		VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l8)
		l11 = vader_array_ref_load_obj(_a7_slotarr->buf, vader_array_offset(_a7_slotarr) + (size_t) l8);
		l13 = INT64_C(0);
		l14 = vader_array_length(((vader_array_t*) l2));
		while ((l13 < l14)) {
			vader_array_t* _a8_slotarr = ((vader_array_t*) l2);
			VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
			VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l13)
			l15 = vader_array_ref_load_box(_a8_slotarr->buf, vader_array_offset(_a8_slotarr) + (size_t) l13);
			vader_array_t* _a9_slotarr = ((vader_array_t*) l6);
			VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
			VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l13)
			l12 = vader_array_ref_load_obj(_a9_slotarr->buf, vader_array_offset(_a9_slotarr) + (size_t) l13);
			vader_array_t* _a10_arr = vader_array_new(83u, 0u, 13u, 1213u);
			l16 = (void*) _a10_arr;
			l17 = ((vader_struct_vader_front_resolver$DeferredModule_t*) l11)->f_sources;
			l18 = vader_array_length(((vader_array_t*) l17));
			l19 = INT64_C(0);
			while ((l19 < l18)) {
				vader_array_t* _a11_slotarr = ((vader_array_t*) l17);
				VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
				l20 = vader_array_ref_load_obj(_a11_slotarr->buf, vader_array_offset(_a11_slotarr) + (size_t) l19);
				l21 = ((vader_struct_vader_front_resolver$SourceFile_t*) l20)->f_program;
				l22 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) ((vader_struct_vader_front_resolver$DeferredModule_t*) l11)->f_found)->f_name;
				l23 = ((vader_struct_toolchain_stage$SourceSpec_t*) l12)->f_given;
				t3 = vader_front_resolver$writes_given(l21, l22, l23, l7);
				if (t3) {
					l24 = ((vader_struct_vader_front_resolver$SourceFile_t*) l20)->f_program;
					vader_array_push_ref((vader_array_t*) l16, l24);
				}
				l19 = (l19 + INT64_C(1));
			}
			t3 = std_core$is_empty__toolchain_ast_Program(l16);
			if (t3) {
				l13 = (l13 + INT64_C(1));
				continue;
			}
			l25 = l16;
			l26 = vader_array_length(((vader_array_t*) l25));
			l27 = INT64_C(0);
			while ((l27 < l26)) {
				vader_array_t* _a12_slotarr = ((vader_array_t*) l25);
				VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
				l28 = vader_array_ref_load_obj(_a12_slotarr->buf, vader_array_offset(_a12_slotarr) + (size_t) l27);
				t0 = std_collections$len__string__std_collections_Set_string_(l7);
				if ((t0 > INT64_C(0))) {
					l29 = ((vader_struct_toolchain_ast$Program_t*) l28)->f_file;
					t3 = std_collections$add__string(l10, l29);
					if (t3) {
						l30 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) ((vader_struct_vader_front_resolver$DeferredModule_t*) l11)->f_found)->f_name;
						vader_front_resolver$name_declared_decorators(l28, l30, l7);
					}
				}
				l27 = (l27 + INT64_C(1));
			}
			l31 = std_time$monotonic();
			t4 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) ((vader_struct_vader_front_resolver$DeferredModule_t*) l11)->f_found)->f_name;
			vader_struct_toolchain_stage$Sources_t* _a13_obj = (vader_struct_toolchain_stage$Sources_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_stage$Sources_t));
			vader_obj_header_init(_a13_obj, 1302u);
			_a13_obj->f_module_name = t4;
			_a13_obj->f_files = l16;
			t2 = (void*) _a13_obj;
			t1 = toolchain_stage$Stage$run$$dispatch(l15, vader_ref_box(t2));
			l32 = t1.payload.obj;
			l33 = ((vader_struct_toolchain_stage$SourceSpec_t*) l12)->f_name;
			l34 = std_time$since(l31);
			vader_support_profile$note_stage(l33, false, l34);
			l35 = ((vader_struct_toolchain_stage$Generated_t*) l32)->f_diagnostics;
			vader_array_push_all((vader_array_t*) l5, (vader_array_t*) l35);
			t4 = ((vader_struct_toolchain_stage$Generated_t*) l32)->f_text;
			if (t4 == 0u) {
				l13 = (l13 + INT64_C(1));
				continue;
			}
			l36 = ((vader_struct_toolchain_stage$SourceSpec_t*) l12)->f_name;
			l37 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) ((vader_struct_vader_front_resolver$DeferredModule_t*) l11)->f_found)->f_name;
			l38 = vader_front_resolver$generated_file(l36, l37);
			l39 = ((vader_struct_toolchain_stage$SourceSpec_t*) l12)->f_name;
			l40 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) ((vader_struct_vader_front_resolver$DeferredModule_t*) l11)->f_found)->f_name;
			l41 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) ((vader_struct_vader_front_resolver$DeferredModule_t*) l11)->f_found)->f_name;
			l42 = ((vader_struct_toolchain_stage$Generated_t*) l32)->f_text;
			l43 = vader_front_resolver$framed_source(l39, l40, l41, l42);
			l44 = toolchain_parser$parse_stage_written(l43, l38);
			l45 = ((vader_struct_toolchain_parser$ParsedSource_t*) l44)->f_errors;
			vader_array_push_all((vader_array_t*) l5, (vader_array_t*) l45);
			l46 = ((vader_struct_toolchain_parser$ParsedSource_t*) l44)->f_program;
			l47 = ((vader_struct_toolchain_stage$Generated_t*) l32)->f_anchors;
			l48 = ((vader_struct_toolchain_stage$SourceSpec_t*) l12)->f_name;
			l49 = vader_front_resolver$anchor_impls(l46, l47, l48);
			toolchain_parser$assign_program_ids(((vader_struct_toolchain_parser$ParsedSource_t*) l44)->f_program, l4);
			l50 = ((vader_struct_toolchain_parser$ParsedSource_t*) l44)->f_program;
			l51 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) ((vader_struct_vader_front_resolver$DeferredModule_t*) l11)->f_found)->f_folder;
			l52 = ((vader_struct_toolchain_stage$SourceSpec_t*) l12)->f_name;
			l53 = vader_front_resolver$late_fns_of(l50, l51, l52);
			l54 = ((vader_struct_toolchain_stage$SourceSpec_t*) l12)->f_name;
			t3 = std_collections$Set$std_core$Contains$contains__string(l3, l54);
			if (!(t3)) {
				l55 = l53;
				l56 = vader_array_length(((vader_array_t*) l55));
				l57 = INT64_C(0);
				while ((l57 < l56)) {
					vader_array_t* _a14_slotarr = ((vader_array_t*) l55);
					VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
					l58 = vader_array_ref_load_obj(_a14_slotarr->buf, vader_array_offset(_a14_slotarr) + (size_t) l57);
					l59 = ((vader_struct_toolchain_ast$FnDecl_t*) ((vader_struct_vader_front_resolver$LateFn_t*) l58)->f_decl)->f_name;
					l60 = ((vader_struct_toolchain_stage$SourceSpec_t*) l12)->f_name;
					l61 = concat_5(1307u, l59, 1696u, l60, 1307u);
					l62 = ((vader_struct_toolchain_ast$FnDecl_t*) ((vader_struct_vader_front_resolver$LateFn_t*) l58)->f_decl)->f_name_span;
					l63 = toolchain_diagnostics$hook_error((uint8_t) 16, l62, l61);
					vader_array_push_ref((vader_array_t*) l5, l63);
					l57 = (l57 + INT64_C(1));
				}
			}
			vader_array_push_all((vader_array_t*) ((vader_struct_vader_front_resolver$DeferredModule_t*) l11)->f_late, (vader_array_t*) l53);
			l64 = ((vader_struct_vader_front_resolver$DeferredModule_t*) l11)->f_sources;
			l65 = ((vader_struct_toolchain_parser$ParsedSource_t*) l44)->f_program;
			vader_struct_vader_front_resolver$SourceFile_t* _a15_obj = (vader_struct_vader_front_resolver$SourceFile_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$SourceFile_t));
			vader_obj_header_init(_a15_obj, 1814u);
			_a15_obj->f_path = l38;
			_a15_obj->f_content = l43;
			_a15_obj->f_program = l65;
			_a15_obj->f_origins = l49;
			l66 = (void*) _a15_obj;
			vader_array_push_ref((vader_array_t*) l64, l66);
			l13 = (l13 + INT64_C(1));
		}
		l8 = (l8 + INT64_C(1));
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
	l3 = std_fs$read_dir(l0);
	if (l3.tag == 28u) {
		l4 = l3.payload.obj;
	} else {
		if (!(l3.tag == 1131u)) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
		l4 = (void*) _a0_arr;
	}
	l5 = l1;
	l6 = ((vader_struct_std_collections$Map__string__string_t*) l5)->f_ekeys;
	l7 = ((vader_struct_std_collections$Map__string__string_t*) l5)->f_evals;
	l8 = INT64_C(0);
	l9 = ((vader_struct_std_collections$Map__string__string_t*) l5)->f_size;
	while ((l8 < l9)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l8)
		t0 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l8];
		l10 = t0.payload.s;
		vader_array_t* _a2_slotarr = ((vader_array_t*) l7);
		VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l8)
		t0 = vader_array_box_slots(_a2_slotarr->buf)[vader_array_offset(_a2_slotarr) + (size_t) l8];
		t1 = t0.payload.s;
		l3 = vader_front_resolver$name_in_folder(l10, l0);
		if (!(l3.tag == 0u)) {
			l11 = l3.payload.s;
			t2 = std_core$$array$Contains$contains__string(l4, l11);
			if (!(t2)) {
				vader_array_push_scalar((vader_array_t*) l4, vader_box_string(642u, l11));
			}
		}
		l8 = (l8 + INT64_C(1));
	}
	t3 = vader_array_length(((vader_array_t*) l4));
	if (t3 == INT64_C(0)) {
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	l4 = vader_front_resolver$source_files_in(l0, l4);
	t3 = vader_array_length(((vader_array_t*) l4));
	if (t3 == INT64_C(0)) {
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	l5 = toolchain_span$empty_span();
	vader_array_t* _a3_arr = vader_array_new(28u, 0u, 0u, 642u);
	l6 = (void*) _a3_arr;
	vader_struct_vader_front_resolver$FolderBucket_t* _a4_obj = (vader_struct_vader_front_resolver$FolderBucket_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$FolderBucket_t));
	vader_obj_header_init(_a4_obj, 1783u);
	_a4_obj->f_name = 0u;
	_a4_obj->f_first_decl_span = l5;
	_a4_obj->f_files = l6;
	l5 = (void*) _a4_obj;
	l8 = vader_array_length(((vader_array_t*) l4));
	l9 = INT64_C(0);
	while ((l9 < l8)) {
		vader_array_t* _a5_slotarr = ((vader_array_t*) l4);
		VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l9)
		t0 = vader_array_box_slots(_a5_slotarr->buf)[vader_array_offset(_a5_slotarr) + (size_t) l9];
		l10 = t0.payload.s;
		l11 = vader_front_resolver$read_with_overlay(l1, l10);
		if (l11 == 0u) {
			l9 = (l9 + INT64_C(1));
			continue;
		}
		vader_array_push_scalar((vader_array_t*) ((vader_struct_vader_front_resolver$FolderBucket_t*) l5)->f_files, vader_box_string(642u, l10));
		l3 = toolchain_parser$parse_module_header(l11, l10);
		if (l3.tag == 0u) {
			l6 = toolchain_span$file_head_span(l10);
			l7 = toolchain_diagnostics$resolver_error((uint8_t) 15, l6, 0u);
			vader_array_push_ref((vader_array_t*) l2, l7);
		} else {
			if (!(l3.tag == 1263u)) {
				vader_unreachable("non-exhaustive match (T3013 should have caught this)");
			}
			t1 = ((vader_struct_vader_front_resolver$FolderBucket_t*) l5)->f_name;
			if (t1 == 0u) {
				t4 = l3.payload.obj;
				l12 = ((vader_struct_toolchain_parser$ModuleHeader_t*) t4)->f_name;
				((vader_struct_vader_front_resolver$FolderBucket_t*) l5)->f_name = l12;
				t4 = l3.payload.obj;
				l13 = ((vader_struct_toolchain_parser$ModuleHeader_t*) t4)->f_name_span;
				((vader_struct_vader_front_resolver$FolderBucket_t*) l5)->f_first_decl_span = l13;
				VADER_WRITE_BARRIER((vader_struct_vader_front_resolver$FolderBucket_t*) l5);
			} else {
				t4 = l3.payload.obj;
				l14 = ((vader_struct_toolchain_parser$ModuleHeader_t*) t4)->f_name;
				l15 = ((vader_struct_vader_front_resolver$FolderBucket_t*) l5)->f_name;
				if (l14 != l15) {
					t4 = l3.payload.obj;
					l16 = ((vader_struct_toolchain_parser$ModuleHeader_t*) t4)->f_name_span;
					t4 = l3.payload.obj;
					l17 = ((vader_struct_toolchain_parser$ModuleHeader_t*) t4)->f_name;
					l18 = ((vader_struct_vader_front_resolver$FolderBucket_t*) l5)->f_name;
					l19 = concat_5(1307u, l17, 1361u, l18, 1618u);
					l20 = toolchain_diagnostics$resolver_error((uint8_t) 16, l16, l19);
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
	void* l7 = NULL;
	vader_string_t l6 = 0;
	vader_string_t l9 = 0;
	vader_string_t l10 = 0;
	vader_box_t l8 = vader_box_null();
	vader_string_t t0 = 0;
	void* t1 = NULL;
	vader_box_t* gc_roots[2] = { &l2, &l8 };
	void** gc_raw_roots[6] = { &l1, &l3, &l4, &l5, &l7, &t1 };
	vader_string_t* gc_atom_roots[5] = { &l0, &l6, &l9, &l10, &t0 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l5 = vader_front_resolver$manifest_at(l2);
	l5 = vader_front_resolver$project_include_paths(l2, l5, l1);
	l6 = vader_front_resolver$generated_root_for(l2);
	t0 = vader_front_resolver$entry_folder_of(l0);
	l8 = vader_front_resolver$seed_entry(t0, l3, l4);
	if (l8.tag == 0u) {
		vader_struct_vader_front_resolver$SearchRoots_t* _a0_obj = (vader_struct_vader_front_resolver$SearchRoots_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$SearchRoots_t));
		vader_obj_header_init(_a0_obj, 1813u);
		_a0_obj->f_entry = vader_box_obj(0u, NULL);
		_a0_obj->f_paths = l5;
		t1 = (void*) _a0_obj;
		{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l7 = l8.payload.obj;
	l9 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) l7)->f_name;
	l10 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) l7)->f_folder;
	t1 = vader_front_resolver$entry_namespace(l9, l10);
	l5 = vader_front_resolver$include_paths(t1, l5, l6);
	vader_struct_vader_front_resolver$SearchRoots_t* _a1_obj = (vader_struct_vader_front_resolver$SearchRoots_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$SearchRoots_t));
	vader_obj_header_init(_a1_obj, 1813u);
	_a1_obj->f_entry = vader_ref_box(l7);
	_a1_obj->f_paths = l5;
	t1 = (void*) _a1_obj;
	{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_resolver$seed_entry(vader_string_t l0, void* l1, void* l2) {
	void* l3 = NULL;
	void* l6 = NULL;
	void* l7 = NULL;
	void* l8 = NULL;
	vader_box_t l4 = vader_box_null();
	vader_string_t l5 = 0;
	vader_string_t t0 = 0;
	void* t1 = NULL;
	vader_box_t* gc_roots[1] = { &l4 };
	void** gc_raw_roots[7] = { &l1, &l2, &l3, &l6, &l7, &l8, &t1 };
	vader_string_t* gc_atom_roots[3] = { &l0, &l5, &t0 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
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
		vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
		l6 = (void*) _a0_arr;
		vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 642u);
		l7 = (void*) _a1_arr;
		vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 645u);
		l8 = (void*) _a2_arr;
		vader_struct_std_collections$Map__string__string_t* _a3_obj = (vader_struct_std_collections$Map__string__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__string_t));
		vader_obj_header_init(_a3_obj, 1028u);
		_a3_obj->f_ekeys = l6;
		_a3_obj->f_evals = l7;
		_a3_obj->f_index = l8;
		_a3_obj->f_mask = INT64_C(0);
		_a3_obj->f_grow_at = INT64_C(0);
		_a3_obj->f_size = INT64_C(0);
		_a3_obj->f_tombs = INT64_C(0);
		l6 = (void*) _a3_obj;
		vader_struct_vader_front_resolver$DiscoveredModule_t* _a4_obj = (vader_struct_vader_front_resolver$DiscoveredModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$DiscoveredModule_t));
		vader_obj_header_init(_a4_obj, 1777u);
		_a4_obj->f_name = l5;
		_a4_obj->f_folder = l0;
		_a4_obj->f_files = l3;
		_a4_obj->f_origin = (uint8_t) 0;
		_a4_obj->f_texts = l6;
		t1 = (void*) _a4_obj;
		{ vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
	}
	{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static void vader_front_resolver$seed_leading(void* l0, void* l1, void* l2, void* l3) {
	void* l4 = NULL;
	int64_t l5, l6;
	vader_string_t l7 = 0;
	vader_box_t t0 = vader_box_null();
	bool t1;
	vader_box_t* gc_roots[1] = { &t0 };
	void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l4 };
	vader_string_t* gc_atom_roots[1] = { &l7 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l4 = l0;
	l5 = vader_array_length(((vader_array_t*) l4));
	l6 = INT64_C(0);
	while ((l6 < l5)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		t0 = vader_array_box_slots(_a0_slotarr->buf)[vader_array_offset(_a0_slotarr) + (size_t) l6];
		l7 = t0.payload.s;
		t1 = std_collections$Set$std_core$Contains$contains__string(l1, l7);
		if (t1) {
			t1 = std_collections$add__string(l2, l7);
			if (t1) {
				vader_array_push_scalar((vader_array_t*) l3, vader_box_string(642u, l7));
			}
		}
		l6 = (l6 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return; }
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
	l5 = vader_array_length(((vader_array_t*) l4));
	l6 = INT64_C(0);
	while ((l6 < l5)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		t0 = vader_array_box_slots(_a0_slotarr->buf)[vader_array_offset(_a0_slotarr) + (size_t) l6];
		l7 = t0.payload.s;
		l9 = std_collections$Map$std_core$Index$at__string__Any(l1, l7);
		if (l9.tag == 0u) {
			l6 = (l6 + INT64_C(1));
			continue;
		}
		l8 = l9.payload.obj;
		l10 = std_collections$Map$std_core$Index$at__string__string__(l3, l7);
		l11 = ((vader_struct_vader_front_resolver$CollectedModule_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l8)->f_collected)->f_symbols;
		l12 = ((vader_struct_std_collections$Map__string__vader_core_symbol_Symbol_t*) l11)->f_ekeys;
		l13 = ((vader_struct_std_collections$Map__string__vader_core_symbol_Symbol_t*) l11)->f_evals;
		l14 = INT64_C(0);
		l15 = ((vader_struct_std_collections$Map__string__vader_core_symbol_Symbol_t*) l11)->f_size;
		while ((l14 < l15)) {
			vader_array_t* _a1_slotarr = ((vader_array_t*) l12);
			VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
			VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l14)
			t0 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l14];
			t1 = t0.payload.s;
			vader_array_t* _a2_slotarr = ((vader_array_t*) l13);
			VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
			VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l14)
			l16 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l14);
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

static void* vader_front_resolver$select_target_bodies(void* l0, vader_box_t l1, void* l2, void* l3) {
	void* l4 = NULL;
	void* l5 = NULL;
	void* l6 = NULL;
	void* l7 = NULL;
	void* l8 = NULL;
	void* l14 = NULL;
	void* l15 = NULL;
	void* l18 = NULL;
	void* l29 = NULL;
	void* l30 = NULL;
	void* l32 = NULL;
	void* l34 = NULL;
	void* l35 = NULL;
	void* l36 = NULL;
	int64_t l9, l10, l11, l12, l19, l20;
	vader_box_t l13 = vader_box_null(), l16 = vader_box_null(), l23 = vader_box_null(), l33 = vader_box_null();
	vader_string_t l17 = 0;
	vader_string_t l22 = 0;
	vader_string_t l24 = 0;
	vader_string_t l25 = 0;
	vader_string_t l26 = 0;
	vader_string_t l27 = 0;
	vader_string_t l28 = 0;
	vader_string_t l31 = 0;
	uint8_t l21;
	void* t0 = NULL;
	bool t1;
	vader_box_t t2 = vader_box_null();
	int64_t t3;
	vader_box_t* gc_roots[6] = { &l1, &l13, &l16, &l23, &l33, &t2 };
	void** gc_raw_roots[18] = {
		&l0, &l2, &l3, &l4, &l5, &l6, &l7, &l8, &l14, &l15, &l18, &l29, &l30, &l32, &l34, &l35,
		&l36, &t0,
	};
	vader_string_t* gc_atom_roots[8] = { &l17, &l22, &l24, &l25, &l26, &l27, &l28, &l31 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 6u, 18u, gc_roots, gc_raw_roots, 0u, NULL, 8u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_front_resolver$check_selectors(l0, l2);
	vader_front_resolver$check_groups(l0, l2);
	if (l1.tag == 0u) {
		{ void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
	l4 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(35u, 0u, 0u, 653u);
	l5 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 645u);
	l6 = (void*) _a2_arr;
	vader_struct_std_collections$Map__string__Any_t* _a3_obj = (vader_struct_std_collections$Map__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any_t));
	vader_obj_header_init(_a3_obj, 1004u);
	_a3_obj->f_ekeys = l4;
	_a3_obj->f_evals = l5;
	_a3_obj->f_index = l6;
	_a3_obj->f_mask = INT64_C(0);
	_a3_obj->f_grow_at = INT64_C(0);
	_a3_obj->f_size = INT64_C(0);
	_a3_obj->f_tombs = INT64_C(0);
	l4 = (void*) _a3_obj;
	vader_array_t* _a4_arr = vader_array_new(28u, 0u, 0u, 642u);
	l5 = (void*) _a4_arr;
	vader_array_t* _a5_arr = vader_array_new(26u, 0u, 12u, 640u);
	l6 = (void*) _a5_arr;
	vader_array_t* _a6_arr = vader_array_new(29u, 0u, 7u, 645u);
	l7 = (void*) _a6_arr;
	vader_struct_std_collections$Map__string__bool_t* _a7_obj = (vader_struct_std_collections$Map__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__bool_t));
	vader_obj_header_init(_a7_obj, 1010u);
	_a7_obj->f_ekeys = l5;
	_a7_obj->f_evals = l6;
	_a7_obj->f_index = l7;
	_a7_obj->f_mask = INT64_C(0);
	_a7_obj->f_grow_at = INT64_C(0);
	_a7_obj->f_size = INT64_C(0);
	_a7_obj->f_tombs = INT64_C(0);
	l5 = (void*) _a7_obj;
	vader_array_t* _a8_arr = vader_array_new(28u, 0u, 0u, 642u);
	l6 = (void*) _a8_arr;
	vader_array_t* _a9_arr = vader_array_new(28u, 0u, 0u, 642u);
	l7 = (void*) _a9_arr;
	vader_array_t* _a10_arr = vader_array_new(29u, 0u, 7u, 645u);
	l8 = (void*) _a10_arr;
	vader_struct_std_collections$Map__string__string_t* _a11_obj = (vader_struct_std_collections$Map__string__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__string_t));
	vader_obj_header_init(_a11_obj, 1028u);
	_a11_obj->f_ekeys = l6;
	_a11_obj->f_evals = l7;
	_a11_obj->f_index = l8;
	_a11_obj->f_mask = INT64_C(0);
	_a11_obj->f_grow_at = INT64_C(0);
	_a11_obj->f_size = INT64_C(0);
	_a11_obj->f_tombs = INT64_C(0);
	l6 = (void*) _a11_obj;
	l7 = l0;
	l9 = vader_array_length(((vader_array_t*) l7));
	l10 = INT64_C(0);
	while ((l10 < l9)) {
		vader_array_t* _a12_slotarr = ((vader_array_t*) l7);
		VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
		t0 = vader_array_ref_load_obj(_a12_slotarr->buf, vader_array_offset(_a12_slotarr) + (size_t) l10);
		l8 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) t0)->f_program)->f_decls;
		l11 = vader_array_length(((vader_array_t*) l8));
		l12 = INT64_C(0);
		while ((l12 < l11)) {
			vader_array_t* _a13_slotarr = ((vader_array_t*) l8);
			VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
			l13 = vader_array_ref_load_box(_a13_slotarr->buf, vader_array_offset(_a13_slotarr) + (size_t) l12);
			if (l13.tag == 1181u) {
				l14 = l13.payload.obj;
				l16 = vader_front_resolver$target_selectors(((vader_struct_toolchain_ast$FnDecl_t*) l14)->f_decorators);
				if (l16.tag == 0u) {
					l12 = (l12 + INT64_C(1));
					continue;
				}
				l15 = l16.payload.obj;
				t1 = ((vader_struct_vader_front_resolver$TargetSelectors_t*) l15)->f_is_bare;
				if (t1) {
					l17 = ((vader_struct_toolchain_ast$FnDecl_t*) l14)->f_name;
					std_collections$Map$std_core$IndexSet$set_at__string__bool(l5, l17, true);
				} else {
					l18 = ((vader_struct_vader_front_resolver$TargetSelectors_t*) l15)->f_os;
					l19 = vader_array_length(((vader_array_t*) l18));
					l20 = INT64_C(0);
					while ((l20 < l19)) {
						vader_array_t* _a14_slotarr = ((vader_array_t*) l18);
						VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
						t2 = vader_array_read_u8(_a14_slotarr, vader_array_offset(_a14_slotarr) + (size_t) l20, 647u);
						l21 = ((uint8_t) t2.payload.i);
						l22 = ((vader_struct_toolchain_ast$FnDecl_t*) l14)->f_name;
						l23 = std_collections$Map$std_core$Index$at__string__string(l6, l22);
						l24 = ((vader_struct_toolchain_ast$FnDecl_t*) l14)->f_name;
						if (l23.tag == 0u) {
							l26 = std_target$Os$std_core$Display$to_string(l21);
							l25 = concat_2(489u, l26);
						} else {
							l27 = l23.payload.s;
							l28 = std_target$Os$std_core$Display$to_string(l21);
							l25 = concat_3(l27, 443u, l28);
						}
						std_collections$Map$std_core$IndexSet$set_at__string__string(l6, l24, l25);
						l20 = (l20 + INT64_C(1));
					}
					l29 = ((vader_struct_vader_front_resolver$TargetSelectors_t*) l15)->f_os;
					l30 = l1.payload.obj;
					t1 = vader_front_resolver$matches_target(l29, l30);
					if (t1) {
						l31 = ((vader_struct_toolchain_ast$FnDecl_t*) l14)->f_name;
						std_collections$Map$std_core$IndexSet$set_at__string__Any(l4, l31, vader_ref_box(l14));
					}
				}
			}
			l12 = (l12 + INT64_C(1));
		}
		l10 = (l10 + INT64_C(1));
	}
	l7 = l1.payload.obj;
	vader_front_resolver$note_uncovered(l0, l7, l4, l6, l3);
	t3 = vader_array_length(((vader_array_t*) l0));
	vader_array_t* _a15_arr = vader_array_reserve(352u, (int64_t) t3, 13u, 1814u);
	l6 = (void*) _a15_arr;
	l7 = l0;
	l9 = vader_array_length(((vader_array_t*) l7));
	l10 = INT64_C(0);
	while ((l10 < l9)) {
		vader_array_t* _a16_slotarr = ((vader_array_t*) l7);
		VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
		l8 = vader_array_ref_load_obj(_a16_slotarr->buf, vader_array_offset(_a16_slotarr) + (size_t) l10);
		vader_array_t* _a17_arr = vader_array_new(481u, 0u, 13u, 2450u);
		l14 = (void*) _a17_arr;
		l15 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) l8)->f_program)->f_decls;
		l11 = vader_array_length(((vader_array_t*) l15));
		l12 = INT64_C(0);
		while ((l12 < l11)) {
			vader_array_t* _a18_slotarr = ((vader_array_t*) l15);
			VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
			l13 = vader_array_ref_load_box(_a18_slotarr->buf, vader_array_offset(_a18_slotarr) + (size_t) l12);
			l18 = l1.payload.obj;
			l16 = vader_front_resolver$resolve_decl(l13, l18, l4, l5);
			if (!(l16.tag == 0u)) {
				l23 = l16;
				vader_array_push_ref((vader_array_t*) l14, l23.payload.obj);
			}
			l12 = (l12 + INT64_C(1));
		}
		l29 = l8;
		l17 = ((vader_struct_vader_front_resolver$SourceFile_t*) l29)->f_path;
		l22 = ((vader_struct_vader_front_resolver$SourceFile_t*) l29)->f_content;
		l30 = ((vader_struct_vader_front_resolver$SourceFile_t*) l8)->f_program;
		l24 = ((vader_struct_toolchain_ast$Program_t*) l30)->f_file;
		l32 = ((vader_struct_toolchain_ast$Program_t*) l30)->f_span;
		l19 = ((vader_struct_toolchain_ast$Program_t*) l30)->f_id;
		l33 = ((vader_struct_toolchain_ast$Program_t*) l30)->f_module;
		vader_struct_toolchain_ast$Program_t* _a19_obj = (vader_struct_toolchain_ast$Program_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$Program_t));
		vader_obj_header_init(_a19_obj, 1213u);
		_a19_obj->f_file = l24;
		_a19_obj->f_span = l32;
		_a19_obj->f_id = l19;
		_a19_obj->f_module = l33;
		_a19_obj->f_decls = l14;
		l34 = (void*) _a19_obj;
		l35 = ((vader_struct_vader_front_resolver$SourceFile_t*) l29)->f_origins;
		vader_struct_vader_front_resolver$SourceFile_t* _a20_obj = (vader_struct_vader_front_resolver$SourceFile_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$SourceFile_t));
		vader_obj_header_init(_a20_obj, 1814u);
		_a20_obj->f_path = l17;
		_a20_obj->f_content = l22;
		_a20_obj->f_program = l34;
		_a20_obj->f_origins = l35;
		l36 = (void*) _a20_obj;
		vader_array_push_ref((vader_array_t*) l6, l36);
		l10 = (l10 + INT64_C(1));
	}
	{ void* __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_resolver$selected_target_of(vader_box_t l0) {
	vader_box_t l1 = vader_box_null();
	void* t0 = NULL;
	vader_box_t* gc_roots[2] = { &l0, &l1 };
	void** gc_raw_roots[1] = { &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	if (l0.tag == 2152u) {
		t0 = l0.payload.obj;
		l1 = vader_ref_box(t0);
		{ vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (l0.tag == 2150u) {
		l1 = vader_box_obj(0u, NULL);
	} else {
		if (!(l0.tag == 2151u)) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		t0 = vader_support_target$host_target();
		l1 = vader_ref_box(t0);
	}
	{ vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$selector_exprs(void* l0) {
	void* l1 = NULL;
	void* l2 = NULL;
	void* l5 = NULL;
	void* l8 = NULL;
	int64_t l3, l4;
	vader_box_t l6 = vader_box_null();
	bool l7;
	void* t0 = NULL;
	vader_box_t* gc_roots[1] = { &l6 };
	void** gc_raw_roots[6] = { &l0, &l1, &l2, &l5, &l8, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(480u, 0u, 13u, 2419u);
	l1 = (void*) _a0_arr;
	l2 = ((vader_struct_toolchain_ast$Decorator_t*) l0)->f_args;
	l3 = vader_array_length(((vader_array_t*) l2));
	l4 = INT64_C(0);
	while ((l4 < l3)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		l5 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l4);
		l6 = ((vader_struct_toolchain_ast$CallArg_t*) l5)->f_value;
		if (!(((vader_struct_toolchain_ast$CallArg_t*) l5)->f_name.tag == 0u)) {
			l7 = l6.tag == 1219u;
		} else {
			l7 = false;
		}
		if (l7) {
			t0 = l6.payload.obj;
			l8 = ((vader_struct_toolchain_ast$SeqLitExpr_t*) t0)->f_elements;
			vader_array_push_all((vader_array_t*) l1, (vader_array_t*) l8);
		} else {
			vader_array_push_ref((vader_array_t*) l1, l6.payload.obj);
		}
		l4 = (l4 + INT64_C(1));
	}
	{ void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_resolver$sidecar_root(vader_string_t l0, vader_string_t l1) {
	vader_box_t l2 = vader_box_null();
	vader_string_t l3 = 0;
	vader_string_t t0 = 0;
	vader_string_t t1 = 0;
	bool t2;
	vader_box_t* gc_roots[1] = { &l2 };
	vader_string_t* gc_atom_roots[5] = { &l0, &l1, &l3, &t0, &t1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL, 5u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = vader_front_resolver$home_root(l0, l1);
	if (!(l2.tag == 0u)) {
		t0 = l2.payload.s;
		{ vader_box_t __vret = vader_box_string(642u, t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	t0 = std_env$current_executable_location();
	t1 = vader_front_resolver$dir_of(t0);
	l3 = vader_front_resolver$join_path(t1, l0);
	t0 = vader_front_resolver$join_path(l3, l1);
	t2 = std_fs$exists(t0);
	if (!(t2)) {
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	{ vader_box_t __vret = vader_box_string(642u, l3); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$sort_by_name(void* l0) {
	void* l1 = NULL;
	void* t0 = NULL;
	void** gc_raw_roots[3] = { &l0, &l1, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l1 = (void*) &vader_fn_static___lambda_vader_front_resolver_20;
	t0 = std_sort$sort__vader_core_symbol_Symbol(l0, l1);
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$source_files(void* l0) {
	void* l1 = NULL;
	void* l2 = NULL;
	int64_t l3, l4;
	vader_string_t l5 = 0;
	int64_t t0;
	void* t1 = NULL;
	void** gc_raw_roots[4] = { &l0, &l1, &l2, &t1 };
	vader_string_t* gc_atom_roots[1] = { &l5 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l1 = ((vader_struct_toolchain_stage$Sources_t*) l0)->f_files;
	t0 = vader_array_length(((vader_array_t*) l1));
	vader_array_t* _a0_arr = vader_array_reserve(28u, (int64_t) t0, 0u, 642u);
	l2 = (void*) _a0_arr;
	l3 = vader_array_length(((vader_array_t*) l1));
	l4 = INT64_C(0);
	while ((l4 < l3)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		t1 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l4);
		l5 = __lambda_vader_front_resolver_38(t1);
		vader_array_push_scalar((vader_array_t*) l2, vader_box_string(642u, l5));
		l4 = (l4 + INT64_C(1));
	}
	{ void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
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
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
	l2 = (void*) _a0_arr;
	l3 = (void*) &vader_fn_static_std_string$compare_ascending;
	l3 = std_sort$sort__string(l1, l3);
	l4 = vader_array_length(((vader_array_t*) l3));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		t0 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l5];
		l6 = t0.payload.s;
		l7 = vader_front_resolver$join_path(l0, l6);
		t1 = std_string$ends_with(l6, 531u);
		if (t1) {
			t1 = std_fs$is_dir(l7);
			if (!(t1)) {
				vader_array_push_scalar((vader_array_t*) l2, vader_box_string(642u, l7));
			}
		}
		l5 = (l5 + INT64_C(1));
	}
	{ void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$source_stages(void) {
	void* l0 = NULL;
	void* l1 = NULL;
	void* t0 = NULL;
	void** gc_raw_roots[3] = { &l0, &l1, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	t0 = (void*) &vader_data_73;
	vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
	VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
	l0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT64_C(0));
	t0 = (void*) &vader_data_74;
	vader_array_t* _a1_slotarr = ((vader_array_t*) t0);
	VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
	l1 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) INT64_C(0));
	vader_array_t* _a2_arr = vader_array_new(36u, 2u, 0u, 660u);
	vader_array_box_slots(_a2_arr->buf)[vader_array_offset(_a2_arr) + 1u] = vader_ref_box(l1);
	vader_array_box_slots(_a2_arr->buf)[vader_array_offset(_a2_arr) + 0u] = vader_ref_box(l0);
	t0 = (void*) _a2_arr;
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
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
	l2 = (int64_t) vader_string_byte_len(l1);
	l3 = (void*) vader_buffer_new((size_t) (INT64_C(21) + l2));
	l2 = INT64_C(0);
	l2 = std_core$write_string_at(l3, l2, l1);
	l2 = std_core$write_string_at(l3, l2, 563u);
	t0 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) l0)->f_start)->f_line;
	l4 = ((int64_t) (int32_t) t0);
	l2 = std_core$write_int(l3, l2, l4);
	t1 = std_core$finish_buffer(l3, l2);
	{ vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_front_resolver$spread(int64_t l0) {
	int64_t l1;
	void* l2 = NULL;
	vader_string_t l3 = 0;
	vader_string_t t0 = 0;
	void** gc_raw_roots[1] = { &l2 };
	vader_string_t* gc_atom_roots[2] = { &l3, &t0 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	if (l0 == INT64_C(1)) {
		{ vader_gc_top = gc_frame.prev; return 2006u; }
	}
	if ((INT64_C(0) < l0)) {
		l1 = l0;
	} else {
		l1 = INT64_C(0);
	}
	vader_array_t* _a0_arr = vader_array_reserve(28u, (int64_t) l1, 0u, 642u);
	l2 = (void*) _a0_arr;
	l1 = INT64_C(0);
	while ((l1 < l0)) {
		l3 = __lambda_vader_front_resolver_29(l1);
		vader_array_push_scalar((vader_array_t*) l2, vader_box_string(642u, l3));
		l1 = (l1 + INT64_C(1));
	}
	t0 = std_string$join(l2, 441u);
	{ vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_front_resolver$stage_plan_path(vader_string_t l0) {
	vader_string_t t0 = 0;
	vader_string_t t1 = 0;
	vader_string_t* gc_atom_roots[3] = { &l0, &t0, &t1 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 3u, gc_atom_roots };
	vader_gc_top = &gc_frame;
	t0 = vader_front_resolver$stage_records_dir(l0);
	t1 = vader_front_resolver$join_path(t0, 3073u);
	{ vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_front_resolver$stage_record_path(vader_string_t l0, vader_string_t l1, vader_string_t l2) {
	vader_string_t l3 = 0;
	vader_string_t l4 = 0;
	vader_string_t t0 = 0;
	vader_string_t* gc_atom_roots[6] = { &l0, &l1, &l2, &l3, &l4, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 6u, gc_atom_roots };
	vader_gc_top = &gc_frame;
	t0 = vader_front_resolver$stage_records_dir(l0);
	l3 = vader_front_resolver$join_path(t0, l1);
	l4 = concat_2(l2, 520u);
	t0 = vader_front_resolver$join_path(l3, l4);
	{ vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_front_resolver$stage_records_dir(vader_string_t l0) {
	vader_string_t t0;
	t0 = vader_front_resolver$join_path(l0, 2135u);
	return t0;
}

static vader_box_t vader_front_resolver$stage_serving(void* l0, vader_string_t l1) {
	void* l2 = NULL;
	void* l3 = NULL;
	int64_t l4, l5;
	vader_box_t l6 = vader_box_null();
	bool t0;
	vader_box_t* gc_roots[1] = { &l6 };
	void** gc_raw_roots[3] = { &l0, &l2, &l3 };
	vader_string_t* gc_atom_roots[1] = { &l1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_vader_front_resolver$ModuleServer_t*) l0)->f_stages;
	vader_struct___lambda_env_vader_front_resolver_11_t* _a0_obj = (vader_struct___lambda_env_vader_front_resolver_11_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_front_resolver_11_t));
	vader_obj_header_init(_a0_obj, 802u);
	_a0_obj->f_cap_0 = l1;
	l3 = (void*) _a0_obj;
	l4 = vader_array_length(((vader_array_t*) l2));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		l6 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l5);
		t0 = __lambda_vader_front_resolver_10(l3, l6);
		if (t0) {
			{ vader_box_t __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
		}
		l5 = (l5 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static void* vader_front_resolver$stages_of_driver(vader_box_t l0) {
	void* l1 = NULL;
	vader_string_t l2 = 0;
	vader_box_t l3 = vader_box_null();
	void* t0 = NULL;
	int32_t t1;
	vader_string_t t2 = 0;
	vader_box_t* gc_roots[2] = { &l0, &l3 };
	void** gc_raw_roots[2] = { &l1, &t0 };
	vader_string_t* gc_atom_roots[2] = { &l2, &t2 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	if (l0.tag == 0u) {
		t0 = vader_front_resolver$replayed_stages(0u);
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	t1 = vader_global$vader_front_resolver$driver_stages$state;
	if (t1 == INT32_C(2)) {
		l1 = vader_global$vader_front_resolver$driver_stages$instance;
	} else {
		l1 = vader_front_resolver$driver_stages();
	}
	l2 = l0.payload.s;
	l3 = std_collections$Map$std_core$Index$at__string__Any(l1, l2);
	if (l3.tag == 0u) {
		t2 = l0.payload.s;
		t0 = vader_front_resolver$replayed_stages(t2);
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l1 = l3.payload.obj;
	{ void* __vret = ((vader_struct_vader_front_resolver$DriverStages_t*) l1)->f_sources; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_resolver$state_name(vader_box_t l0, vader_string_t l1, vader_string_t l2) {
	vader_box_t l3 = vader_box_null();
	void* l4 = NULL;
	void* l6 = NULL;
	vader_string_t l5 = 0;
	void* t0 = NULL;
	bool t1;
	vader_string_t t2 = 0;
	vader_box_t* gc_roots[2] = { &l0, &l3 };
	void** gc_raw_roots[3] = { &l4, &l6, &t0 };
	vader_string_t* gc_atom_roots[4] = { &l1, &l2, &l5, &t2 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	if (!(l0.tag == 1185u)) {
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	t0 = l0.payload.obj;
	l3 = ((vader_struct_toolchain_ast$GenericInstExpr_t*) t0)->f_callee;
	if (l3.tag == 1186u) {
		l4 = l0.payload.obj;
		t0 = l3.payload.obj;
		l5 = ((vader_struct_toolchain_ast$IdentExpr_t*) t0)->f_name;
		vader_array_t* _a0_arr = vader_array_new(28u, 2u, 0u, 642u);
		vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 1u] = vader_box_string(642u, l2);
		vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 0u] = vader_box_string(642u, l1);
		l6 = (void*) _a0_arr;
		t1 = vader_front_resolver$is_instance_of(vader_ref_box(l4), l5, l6);
		if (t1) {
			t0 = l3.payload.obj;
			t2 = ((vader_struct_toolchain_ast$IdentExpr_t*) t0)->f_name;
			{ vader_box_t __vret = vader_box_string(642u, t2); vader_gc_top = gc_frame.prev; return __vret; }
		}
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_front_resolver$state_struct(void* l0, vader_string_t l1, void* l2) {
	bool l3;
	void* l4 = NULL;
	void* l9 = NULL;
	vader_string_t l5 = 0;
	vader_string_t l6 = 0;
	vader_string_t l7 = 0;
	vader_string_t l10 = 0;
	vader_box_t l8 = vader_box_null();
	int64_t t0;
	vader_string_t t1 = 0;
	vader_box_t t2 = vader_box_null();
	void* t3 = NULL;
	bool t4;
	vader_box_t* gc_roots[2] = { &l8, &t2 };
	void** gc_raw_roots[5] = { &l0, &l2, &l4, &l9, &t3 };
	vader_string_t* gc_atom_roots[6] = { &l1, &l5, &l6, &l7, &l10, &t1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 6u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	t0 = vader_array_length(((vader_array_t*) ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_type_params));
	if (t0 != INT64_C(2)) {
		l3 = true;
	} else {
		t0 = vader_array_length(((vader_array_t*) ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_params));
		l3 = t0 != INT64_C(4);
	}
	if (l3) {
		l4 = ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_name_span;
		l5 = ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_name;
		t1 = concat_5(1307u, l5, 1439u, l1, 634u);
		l5 = concat_2(t1, 3080u);
		t2 = vader_front_resolver$refused(l2, l4, l5);
		{ vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
	}
	vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_type_params);
	VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
	VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
	t3 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT32_C(0));
	l5 = ((vader_struct_toolchain_ast$TypeParam_t*) t3)->f_name;
	VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(1))
	t3 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT32_C(1));
	l6 = ((vader_struct_toolchain_ast$TypeParam_t*) t3)->f_name;
	l4 = ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_params;
	vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
	VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
	VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
	t3 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) INT32_C(0));
	l8 = vader_front_resolver$state_name(((vader_struct_toolchain_ast$FnParam_t*) t3)->f_ty, l5, l6);
	if (l8.tag == 0u) {
		vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
		VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(0))
		t3 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) INT32_C(0));
		l9 = vader_front_resolver$type_span(t3);
		l7 = concat_9(3359u, l5, 441u, l6, 638u, l5, 441u, l6, 637u);
		t2 = vader_front_resolver$refused(l2, l9, l7);
		{ vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l7 = l8.payload.s;
	vader_array_t* _a3_slotarr = ((vader_array_t*) l4);
	VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
	VADER_ARRAY_CHECK_INDEX(_a3_slotarr, INT32_C(1))
	t3 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) INT32_C(1));
	l8 = ((vader_struct_toolchain_ast$FnParam_t*) t3)->f_ty;
	vader_array_t* _a4_arr = vader_array_new(28u, 1u, 0u, 642u);
	vader_array_box_slots(_a4_arr->buf)[vader_array_offset(_a4_arr) + 0u] = vader_box_string(642u, l1);
	l9 = (void*) _a4_arr;
	t4 = vader_front_resolver$is_instance_of(l8, 995u, l9);
	if (!(t4)) {
		vader_array_t* _a5_slotarr = ((vader_array_t*) l4);
		VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a5_slotarr, INT32_C(1))
		t3 = vader_array_ref_load_obj(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) INT32_C(1));
		l9 = vader_front_resolver$type_span(t3);
		l10 = concat_3(3356u, l1, 637u);
		t2 = vader_front_resolver$refused(l2, l9, l10);
		{ vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
	}
	vader_array_t* _a6_slotarr = ((vader_array_t*) l4);
	VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
	VADER_ARRAY_CHECK_INDEX(_a6_slotarr, INT32_C(2))
	t3 = vader_array_ref_load_obj(_a6_slotarr->buf, vader_array_offset(_a6_slotarr) + (size_t) INT32_C(2));
	t4 = vader_front_resolver$is_named(((vader_struct_toolchain_ast$FnParam_t*) t3)->f_ty, l5);
	if (!(t4)) {
		vader_array_t* _a7_slotarr = ((vader_array_t*) l4);
		VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a7_slotarr, INT32_C(2))
		t3 = vader_array_ref_load_obj(_a7_slotarr->buf, vader_array_offset(_a7_slotarr) + (size_t) INT32_C(2));
		l9 = vader_front_resolver$type_span(t3);
		l10 = concat_3(3330u, l5, 1307u);
		t2 = vader_front_resolver$refused(l2, l9, l10);
		{ vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
	}
	vader_array_t* _a8_slotarr = ((vader_array_t*) l4);
	VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
	VADER_ARRAY_CHECK_INDEX(_a8_slotarr, INT32_C(3))
	t3 = vader_array_ref_load_obj(_a8_slotarr->buf, vader_array_offset(_a8_slotarr) + (size_t) INT32_C(3));
	t4 = vader_front_resolver$is_proceed(((vader_struct_toolchain_ast$FnParam_t*) t3)->f_ty, l5, l6);
	if (!(t4)) {
		vader_array_t* _a9_slotarr = ((vader_array_t*) l4);
		VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a9_slotarr, INT32_C(3))
		t3 = vader_array_ref_load_obj(_a9_slotarr->buf, vader_array_offset(_a9_slotarr) + (size_t) INT32_C(3));
		l4 = vader_front_resolver$type_span(t3);
		l5 = concat_5(1768u, l5, 398u, l6, 1307u);
		t2 = vader_front_resolver$refused(l2, l4, l5);
		{ vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l8 = ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_return_type;
	t4 = vader_front_resolver$is_named(l8, l6);
	if (t4) {
		{ vader_box_t __vret = vader_box_string(642u, l7); vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (l8.tag == 0u) {
		l4 = ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_name_span;
	} else {
		l4 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l8.payload.obj);
	}
	l5 = ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_name;
	l5 = concat_5(1307u, l5, 1586u, l6, 1307u);
	t2 = vader_front_resolver$refused(l2, l4, l5);
	{ vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$still_declared(void* l0, void* l1) {
	void* l2 = NULL;
	void* l3 = NULL;
	void* l4 = NULL;
	void* l10 = NULL;
	int64_t l5, l6, l7, l8, l9;
	bool t0;
	void* t1 = NULL;
	vader_box_t t2 = vader_box_null();
	vader_box_t* gc_roots[1] = { &t2 };
	void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l4, &l10, &t1 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	t0 = std_core$is_empty__vader_front_resolver_LateFn(l0);
	if (t0) {
		{ void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	vader_array_t* _a0_arr = vader_array_new(30u, 0u, 8u, 646u);
	l2 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(26u, 0u, 12u, 640u);
	l3 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 645u);
	l4 = (void*) _a2_arr;
	vader_struct_std_collections$Map__i64__bool_t* _a3_obj = (vader_struct_std_collections$Map__i64__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i64__bool_t));
	vader_obj_header_init(_a3_obj, 968u);
	_a3_obj->f_ekeys = l2;
	_a3_obj->f_evals = l3;
	_a3_obj->f_index = l4;
	_a3_obj->f_mask = INT64_C(0);
	_a3_obj->f_grow_at = INT64_C(0);
	_a3_obj->f_size = INT64_C(0);
	_a3_obj->f_tombs = INT64_C(0);
	t1 = (void*) _a3_obj;
	vader_struct_std_collections$Set__i64_t* _a4_obj = (vader_struct_std_collections$Set__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__i64_t));
	vader_obj_header_init(_a4_obj, 1109u);
	_a4_obj->f_inner = t1;
	l2 = (void*) _a4_obj;
	l3 = l1;
	l5 = vader_array_length(((vader_array_t*) l3));
	l6 = INT64_C(0);
	while ((l6 < l5)) {
		vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
		t1 = vader_array_ref_load_obj(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) l6);
		l4 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) t1)->f_program)->f_decls;
		l7 = vader_array_length(((vader_array_t*) l4));
		l8 = INT64_C(0);
		while ((l8 < l7)) {
			vader_array_t* _a6_slotarr = ((vader_array_t*) l4);
			VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
			t2 = vader_array_ref_load_box(_a6_slotarr->buf, vader_array_offset(_a6_slotarr) + (size_t) l8);
			l9 = VADER_UNION_FIELD(int64_t, vader_struct_toolchain_ast$AssertDecl_t, f_id, t2.payload.obj);
			std_collections$add__i64(l2, l9);
			l8 = (l8 + INT64_C(1));
		}
		l6 = (l6 + INT64_C(1));
	}
	vader_array_t* _a7_arr = vader_array_new(345u, 0u, 13u, 1793u);
	l3 = (void*) _a7_arr;
	l4 = l0;
	l5 = vader_array_length(((vader_array_t*) l4));
	l6 = INT64_C(0);
	while ((l6 < l5)) {
		vader_array_t* _a8_slotarr = ((vader_array_t*) l4);
		VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
		l10 = vader_array_ref_load_obj(_a8_slotarr->buf, vader_array_offset(_a8_slotarr) + (size_t) l6);
		l7 = vader_front_resolver$declaring_id(l10);
		t0 = std_collections$Set$std_core$Contains$contains__i64(l2, l7);
		if (t0) {
			vader_array_push_ref((vader_array_t*) l3, l10);
		}
		l6 = (l6 + INT64_C(1));
	}
	{ void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
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
	l3 = std_collections$Map$std_core$Index$at__string__Any(((vader_struct_json$JsonObject_t*) l0)->f_entries, l1);
	if (l3.tag == 0u) {
		{ vader_gc_top = gc_frame.prev; return 0u; }
	}
	if (!(l3.tag == 911u)) {
		l4 = concat_3(1307u, l1, 1497u);
		vader_array_push_scalar((vader_array_t*) l2, vader_box_string(642u, l4));
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
	l3 = std_collections$Map$std_core$Index$at__string__Any(((vader_struct_json$JsonObject_t*) l0)->f_entries, l1);
	if (l3.tag == 0u) {
		vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
		t0 = (void*) _a0_arr;
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (!(l3.tag == 905u)) {
		l4 = concat_3(1307u, l1, 1501u);
		vader_array_push_scalar((vader_array_t*) l2, vader_box_string(642u, l4));
		vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 642u);
		t0 = (void*) _a1_arr;
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	vader_array_t* _a2_arr = vader_array_new(28u, 0u, 0u, 642u);
	l5 = (void*) _a2_arr;
	t0 = l3.payload.obj;
	l6 = ((vader_struct_json$JsonArray_t*) t0)->f_items;
	l7 = vader_array_length(((vader_array_t*) l6));
	l8 = INT64_C(0);
	while ((l8 < l7)) {
		vader_array_t* _a3_slotarr = ((vader_array_t*) l6);
		VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
		l3 = vader_array_ref_load_box(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l8);
		if (l3.tag == 911u) {
			t0 = l3.payload.obj;
			l4 = ((vader_struct_json$JsonString_t*) t0)->f_value;
			vader_array_push_scalar((vader_array_t*) l5, vader_box_string(642u, l4));
		} else {
			l9 = concat_3(1307u, l1, 1527u);
			vader_array_push_scalar((vader_array_t*) l2, vader_box_string(642u, l9));
		}
		l8 = (l8 + INT64_C(1));
	}
	{ void* __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
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

static void* vader_front_resolver$substitute_param(void* l0, void* l1) {
	void* l2 = NULL;
	void* l3 = NULL;
	void* l5 = NULL;
	vader_string_t l4 = 0;
	vader_box_t l6 = vader_box_null(), l7 = vader_box_null();
	bool l8;
	void* t0 = NULL;
	vader_box_t* gc_roots[2] = { &l6, &l7 };
	void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l5, &t0 };
	vader_string_t* gc_atom_roots[1] = { &l4 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = l0;
	l3 = ((vader_struct_toolchain_ast$FnParam_t*) l2)->f_span;
	l4 = ((vader_struct_toolchain_ast$FnParam_t*) l2)->f_name;
	l5 = ((vader_struct_toolchain_ast$FnParam_t*) l2)->f_name_span;
	l6 = vader_front_resolver$substitute_opt_type(((vader_struct_toolchain_ast$FnParam_t*) l0)->f_ty, l1);
	l7 = ((vader_struct_toolchain_ast$FnParam_t*) l2)->f_default_value;
	l8 = ((vader_struct_toolchain_ast$FnParam_t*) l2)->f_variadic;
	l2 = ((vader_struct_toolchain_ast$FnParam_t*) l2)->f_decorators;
	vader_struct_toolchain_ast$FnParam_t* _a0_obj = (vader_struct_toolchain_ast$FnParam_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$FnParam_t));
	vader_obj_header_init(_a0_obj, 1182u);
	_a0_obj->f_span = l3;
	_a0_obj->f_id = INT64_C(0);
	_a0_obj->f_name = l4;
	_a0_obj->f_name_span = l5;
	_a0_obj->f_ty = l6;
	_a0_obj->f_default_value = l7;
	_a0_obj->f_variadic = l8;
	_a0_obj->f_decorators = l2;
	t0 = (void*) _a0_obj;
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$substitute_params_disambiguated(void* l0, void* l1, void* l2, void* l3) {
	void* l4 = NULL;
	void* l5 = NULL;
	void* l8 = NULL;
	void* l9 = NULL;
	void* l10 = NULL;
	void* l13 = NULL;
	void* l17 = NULL;
	void* l18 = NULL;
	int64_t l6, l7, l11;
	vader_string_t l12 = 0;
	vader_box_t l14 = vader_box_null(), l15 = vader_box_null();
	bool l16;
	int64_t t0;
	vader_string_t t1 = 0;
	vader_box_t* gc_roots[2] = { &l14, &l15 };
	void** gc_raw_roots[12] = { &l0, &l1, &l2, &l3, &l4, &l5, &l8, &l9, &l10, &l13, &l17, &l18 };
	vader_string_t* gc_atom_roots[2] = { &l12, &t1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	t0 = vader_array_length(((vader_array_t*) l0));
	vader_array_t* _a0_arr = vader_array_reserve(74u, (int64_t) t0, 13u, 1182u);
	l4 = (void*) _a0_arr;
	l5 = l0;
	l6 = vader_array_length(((vader_array_t*) l5));
	l7 = INT64_C(0);
	while ((l7 < l6)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		l8 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l7);
		t1 = ((vader_struct_toolchain_ast$FnParam_t*) l8)->f_name;
		if (t1 == 3165u) {
			l9 = l2;
		} else {
			l9 = vader_front_resolver$synth_param_span(l3);
		}
		l10 = vader_front_resolver$substitute_param(l8, l1);
		l11 = ((vader_struct_toolchain_ast$FnParam_t*) l10)->f_id;
		l12 = ((vader_struct_toolchain_ast$FnParam_t*) l10)->f_name;
		l13 = vader_front_resolver$unplaced_span();
		l14 = ((vader_struct_toolchain_ast$FnParam_t*) l10)->f_ty;
		l15 = ((vader_struct_toolchain_ast$FnParam_t*) l10)->f_default_value;
		l16 = ((vader_struct_toolchain_ast$FnParam_t*) l10)->f_variadic;
		l17 = ((vader_struct_toolchain_ast$FnParam_t*) l10)->f_decorators;
		vader_struct_toolchain_ast$FnParam_t* _a2_obj = (vader_struct_toolchain_ast$FnParam_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$FnParam_t));
		vader_obj_header_init(_a2_obj, 1182u);
		_a2_obj->f_span = l9;
		_a2_obj->f_id = l11;
		_a2_obj->f_name = l12;
		_a2_obj->f_name_span = l13;
		_a2_obj->f_ty = l14;
		_a2_obj->f_default_value = l15;
		_a2_obj->f_variadic = l16;
		_a2_obj->f_decorators = l17;
		l18 = (void*) _a2_obj;
		vader_array_push_ref((vader_array_t*) l4, l18);
		l7 = (l7 + INT64_C(1));
	}
	{ void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_resolver$substitute_type_expr(vader_box_t l0, void* l1) {
	vader_box_t l2 = vader_box_null(), l7 = vader_box_null();
	vader_string_t l3 = 0;
	void* l4 = NULL;
	void* l6 = NULL;
	uint8_t l5;
	int64_t l8, l9;
	void* t0 = NULL;
	void* t1 = NULL;
	vader_box_t t2 = vader_box_null();
	vader_box_t* gc_roots[4] = { &l0, &l2, &l7, &t2 };
	void** gc_raw_roots[5] = { &l1, &l4, &l6, &t0, &t1 };
	vader_string_t* gc_atom_roots[1] = { &l3 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 4u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	if (l0.tag == 1186u) {
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
	if (l0.tag == 1149u) {
		t0 = l0.payload.obj;
		l4 = ((vader_struct_toolchain_ast$BinaryExpr_t*) t0)->f_span;
		t0 = l0.payload.obj;
		l5 = ((vader_struct_toolchain_ast$BinaryExpr_t*) t0)->f_op;
		t0 = l0.payload.obj;
		l6 = ((vader_struct_toolchain_ast$BinaryExpr_t*) t0)->f_op_span;
		t0 = l0.payload.obj;
		l2 = vader_front_resolver$substitute_type_expr(((vader_struct_toolchain_ast$BinaryExpr_t*) t0)->f_left, l1);
		t0 = l0.payload.obj;
		l7 = vader_front_resolver$substitute_type_expr(((vader_struct_toolchain_ast$BinaryExpr_t*) t0)->f_right, l1);
		vader_struct_toolchain_ast$BinaryExpr_t* _a0_obj = (vader_struct_toolchain_ast$BinaryExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$BinaryExpr_t));
		vader_obj_header_init(_a0_obj, 1149u);
		_a0_obj->f_span = l4;
		_a0_obj->f_id = INT64_C(0);
		_a0_obj->f_op = l5;
		_a0_obj->f_op_span = l6;
		_a0_obj->f_left = l2;
		_a0_obj->f_right = l7;
		t0 = (void*) _a0_obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (l0.tag == 1183u) {
		vader_array_t* _a1_arr = vader_array_new(480u, 0u, 13u, 2419u);
		l4 = (void*) _a1_arr;
		t0 = l0.payload.obj;
		l6 = ((vader_struct_toolchain_ast$FnTypeExpr_t*) t0)->f_params;
		l8 = vader_array_length(((vader_array_t*) l6));
		l9 = INT64_C(0);
		while ((l9 < l8)) {
			vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
			VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
			t2 = vader_array_ref_load_box(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l9);
			l2 = vader_front_resolver$substitute_type_expr(t2, l1);
			vader_array_push_ref((vader_array_t*) l4, l2.payload.obj);
			l9 = (l9 + INT64_C(1));
		}
		t0 = l0.payload.obj;
		l2 = ((vader_struct_toolchain_ast$FnTypeExpr_t*) t0)->f_return_type;
		l7 = vader_box_obj(0u, NULL);
		if (!(l2.tag == 0u)) {
			l7 = vader_front_resolver$substitute_type_expr(l2, l1);
		}
		t0 = l0.payload.obj;
		vader_struct_toolchain_ast$FnTypeExpr_t* _a3_obj = (vader_struct_toolchain_ast$FnTypeExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$FnTypeExpr_t));
		vader_obj_header_init(_a3_obj, 1183u);
		_a3_obj->f_span = ((vader_struct_toolchain_ast$FnTypeExpr_t*) t0)->f_span;
		_a3_obj->f_id = INT64_C(0);
		_a3_obj->f_params = l4;
		_a3_obj->f_return_type = l7;
		t0 = (void*) _a3_obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (l0.tag == 1146u) {
		t0 = l0.payload.obj;
		l4 = ((vader_struct_toolchain_ast$ArrayTypeExpr_t*) t0)->f_span;
		t0 = l0.payload.obj;
		l2 = vader_front_resolver$substitute_type_expr(((vader_struct_toolchain_ast$ArrayTypeExpr_t*) t0)->f_element, l1);
		vader_struct_toolchain_ast$ArrayTypeExpr_t* _a4_obj = (vader_struct_toolchain_ast$ArrayTypeExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$ArrayTypeExpr_t));
		vader_obj_header_init(_a4_obj, 1146u);
		_a4_obj->f_span = l4;
		_a4_obj->f_id = INT64_C(0);
		_a4_obj->f_element = l2;
		t0 = (void*) _a4_obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (l0.tag == 1219u) {
		vader_array_t* _a5_arr = vader_array_new(480u, 0u, 13u, 2419u);
		l4 = (void*) _a5_arr;
		t0 = l0.payload.obj;
		l6 = ((vader_struct_toolchain_ast$SeqLitExpr_t*) t0)->f_elements;
		l8 = vader_array_length(((vader_array_t*) l6));
		l9 = INT64_C(0);
		while ((l9 < l8)) {
			vader_array_t* _a6_slotarr = ((vader_array_t*) l6);
			VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
			t2 = vader_array_ref_load_box(_a6_slotarr->buf, vader_array_offset(_a6_slotarr) + (size_t) l9);
			l2 = vader_front_resolver$substitute_type_expr(t2, l1);
			vader_array_push_ref((vader_array_t*) l4, l2.payload.obj);
			l9 = (l9 + INT64_C(1));
		}
		t0 = l0.payload.obj;
		vader_struct_toolchain_ast$SeqLitExpr_t* _a7_obj = (vader_struct_toolchain_ast$SeqLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$SeqLitExpr_t));
		vader_obj_header_init(_a7_obj, 1219u);
		_a7_obj->f_span = ((vader_struct_toolchain_ast$SeqLitExpr_t*) t0)->f_span;
		_a7_obj->f_id = INT64_C(0);
		_a7_obj->f_elements = l4;
		_a7_obj->f_trailing_comma = false;
		t0 = (void*) _a7_obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (!(l0.tag == 1185u)) {
		{ vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	vader_array_t* _a8_arr = vader_array_new(480u, 0u, 13u, 2419u);
	l4 = (void*) _a8_arr;
	t0 = l0.payload.obj;
	l6 = ((vader_struct_toolchain_ast$GenericInstExpr_t*) t0)->f_type_args;
	l8 = vader_array_length(((vader_array_t*) l6));
	l9 = INT64_C(0);
	while ((l9 < l8)) {
		vader_array_t* _a9_slotarr = ((vader_array_t*) l6);
		VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
		t2 = vader_array_ref_load_box(_a9_slotarr->buf, vader_array_offset(_a9_slotarr) + (size_t) l9);
		l2 = vader_front_resolver$substitute_type_expr(t2, l1);
		vader_array_push_ref((vader_array_t*) l4, l2.payload.obj);
		l9 = (l9 + INT64_C(1));
	}
	t0 = l0.payload.obj;
	l6 = ((vader_struct_toolchain_ast$GenericInstExpr_t*) t0)->f_span;
	t0 = l0.payload.obj;
	l2 = ((vader_struct_toolchain_ast$GenericInstExpr_t*) t0)->f_callee;
	vader_struct_toolchain_ast$GenericInstExpr_t* _a10_obj = (vader_struct_toolchain_ast$GenericInstExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$GenericInstExpr_t));
	vader_obj_header_init(_a10_obj, 1185u);
	_a10_obj->f_span = l6;
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
	l2 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT32_C(0));
	VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
	vader_array_ref_store(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT32_C(0), l1);
	VADER_WRITE_BARRIER(_a0_slotarr->buf);
	return l2;
}

vader_box_t vader_front_resolver$symbol_declared_at(void* l0, void* l1) {
	void* l2;
	uint64_t l3;
	vader_box_t t0;
	l2 = ((vader_struct_vader_front_resolver$ResolvedModule_t*) l0)->f_declarations;
	l3 = toolchain_span$Span$std_core$Hash$hash(l1);
	t0 = std_collections$Map$std_core$Index$at__u64__Any(l2, l3);
	return t0;
}

static void* vader_front_resolver$synth_inherited(void* l0, void* l1, int64_t l2) {
	void* l3 = NULL;
	void* l5 = NULL;
	void* l6 = NULL;
	void* l7 = NULL;
	void* l8 = NULL;
	void* l9 = NULL;
	void* l12 = NULL;
	void* l13 = NULL;
	vader_string_t l4 = 0;
	int64_t l10, l11;
	vader_box_t l14 = vader_box_null(), l16 = vader_box_null();
	bool l15;
	int64_t t0;
	void* t1 = NULL;
	vader_box_t* gc_roots[2] = { &l14, &l16 };
	void** gc_raw_roots[11] = { &l0, &l1, &l3, &l5, &l6, &l7, &l8, &l9, &l12, &l13, &t1 };
	vader_string_t* gc_atom_roots[1] = { &l4 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 11u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l3 = ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_span;
	l4 = ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_name;
	l5 = vader_front_resolver$unplaced_span();
	vader_array_t* _a0_arr = vader_array_new(90u, 0u, 13u, 1235u);
	l6 = (void*) _a0_arr;
	l7 = ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_params;
	vader_struct___lambda_env_vader_front_resolver_27_t* _a1_obj = (vader_struct___lambda_env_vader_front_resolver_27_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_front_resolver_27_t));
	vader_obj_header_init(_a1_obj, 807u);
	_a1_obj->f_cap_0 = l1;
	l8 = (void*) _a1_obj;
	t0 = vader_array_length(((vader_array_t*) l7));
	vader_array_t* _a2_arr = vader_array_reserve(74u, (int64_t) t0, 13u, 1182u);
	l9 = (void*) _a2_arr;
	l10 = vader_array_length(((vader_array_t*) l7));
	l11 = INT64_C(0);
	while ((l11 < l10)) {
		vader_array_t* _a3_slotarr = ((vader_array_t*) l7);
		VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
		l12 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l11);
		l13 = __lambda_vader_front_resolver_26(l8, l12);
		vader_array_push_ref((vader_array_t*) l9, l13);
		l11 = (l11 + INT64_C(1));
	}
	l7 = ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_params_span;
	l14 = vader_front_resolver$substitute_opt_type(((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_return_type, l1);
	vader_array_t* _a4_arr = vader_array_new(67u, 0u, 13u, 1159u);
	l8 = (void*) _a4_arr;
	l15 = ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_is_expression_bodied;
	l16 = ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_doc;
	vader_struct_toolchain_ast$FnDecl_t* _a5_obj = (vader_struct_toolchain_ast$FnDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$FnDecl_t));
	vader_obj_header_init(_a5_obj, 1181u);
	_a5_obj->f_span = l3;
	_a5_obj->f_id = l2;
	_a5_obj->f_name = l4;
	_a5_obj->f_name_span = l5;
	_a5_obj->f_visibility = (uint8_t) 0;
	_a5_obj->f_type_params = l6;
	_a5_obj->f_params = l9;
	_a5_obj->f_params_span = l7;
	_a5_obj->f_return_type = l14;
	_a5_obj->f_body = vader_box_obj(0u, NULL);
	_a5_obj->f_decorators = l8;
	_a5_obj->f_sam_synthetic = false;
	_a5_obj->f_is_expression_bodied = l15;
	_a5_obj->f_materialized = true;
	_a5_obj->f_comptime_synthetic = false;
	_a5_obj->f_trailing_comma = false;
	_a5_obj->f_doc = l16;
	_a5_obj->f_inherits = vader_ref_box(l0);
	t1 = (void*) _a5_obj;
	{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$synth_param_span(void* l0) {
	int32_t l1;
	void* l2 = NULL;
	int64_t t0;
	void* t1 = NULL;
	void** gc_raw_roots[3] = { &l0, &l2, &t1 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	t0 = toolchain_parser$mint(l0);
	l1 = ((int32_t) (int64_t) t0);
	vader_struct_toolchain_span$Position_t* _a0_obj = (vader_struct_toolchain_span$Position_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Position_t));
	vader_obj_header_init(_a0_obj, 1288u);
	_a0_obj->f_file = 0u;
	_a0_obj->f_offset = INT64_C(0);
	_a0_obj->f_line = INT32_C(0);
	_a0_obj->f_column = l1;
	l2 = (void*) _a0_obj;
	vader_struct_toolchain_span$Span_t* _a1_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
	vader_obj_header_init(_a1_obj, 1289u);
	_a1_obj->f_start = l2;
	_a1_obj->f_end = l2;
	t1 = (void*) _a1_obj;
	{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
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
	vader_array_t* _a0_arr = vader_array_new(73u, 0u, 13u, 1181u);
	l1 = (void*) _a0_arr;
	l2 = l0;
	l3 = vader_array_length(((vader_array_t*) l2));
	l4 = INT64_C(0);
	while ((l4 < l3)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		t0 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l4);
		l5 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) t0)->f_program)->f_decls;
		l6 = vader_array_length(((vader_array_t*) l5));
		l7 = INT64_C(0);
		while ((l7 < l6)) {
			vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
			VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
			l8 = vader_array_ref_load_box(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l7);
			if (l8.tag == 1181u) {
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
	bool t0;
	void* t1 = NULL;
	vader_string_t t2 = 0;
	vader_string_t t3 = 0;
	int64_t t4;
	vader_box_t* gc_roots[2] = { &l9, &l10 };
	void** gc_raw_roots[6] = { &l0, &l1, &l4, &l5, &l6, &t1 };
	vader_string_t* gc_atom_roots[2] = { &t2, &t3 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l1 = l0;
	l2 = vader_array_length(((vader_array_t*) l1));
	l3 = INT64_C(0);
	while ((l3 < l2)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		l4 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l3);
		t0 = toolchain_ast$is_compiler(l4, (uint8_t) 22);
		if (t0) {
			vader_array_t* _a1_arr = vader_array_new(31u, 0u, 1u, 647u);
			l5 = (void*) _a1_arr;
			l6 = vader_front_resolver$selector_exprs(l4);
			l7 = vader_array_length(((vader_array_t*) l6));
			l8 = INT64_C(0);
			while ((l8 < l7)) {
				vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
				VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
				l9 = vader_array_ref_load_box(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l8);
				if (l9.tag == 1171u) {
					t1 = l9.payload.obj;
					t2 = ((vader_struct_toolchain_ast$DotVariantExpr_t*) t1)->f_variant;
					t3 = std_string$to_lower(t2);
					l10 = vader_support_target$parse_os(t3);
					if (!(l10.tag == 0u)) {
						l11 = ((uint8_t) l10.payload.i);
						vader_array_push_u8((vader_array_t*) l5, (int32_t) (uint8_t) l11);
					}
					l8 = (l8 + INT64_C(1));
					continue;
				}
				l8 = (l8 + INT64_C(1));
			}
			t4 = vader_array_length(((vader_array_t*) ((vader_struct_toolchain_ast$Decorator_t*) l4)->f_args));
			l12 = t4 == INT64_C(0);
			vader_struct_vader_front_resolver$TargetSelectors_t* _a3_obj = (vader_struct_vader_front_resolver$TargetSelectors_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$TargetSelectors_t));
			vader_obj_header_init(_a3_obj, 1817u);
			_a3_obj->f_os = l5;
			_a3_obj->f_is_bare = l12;
			t1 = (void*) _a3_obj;
			{ vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
		}
		l3 = (l3 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static void* vader_front_resolver$tested_or_not(void* l0, void* l1, void* l2) {
	vader_string_t l3 = 0;
	vader_box_t l4 = vader_box_null();
	void* l5 = NULL;
	void* l6 = NULL;
	void* l7 = NULL;
	void* t0 = NULL;
	vader_box_t* gc_roots[1] = { &l4 };
	void** gc_raw_roots[7] = { &l0, &l1, &l2, &l5, &l6, &l7, &t0 };
	vader_string_t* gc_atom_roots[1] = { &l3 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l3 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) l1)->f_folder;
	l4 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_tested;
	if (!(vader_box_eq(vader_box_string(642u, l3), l4))) {
		l3 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) l1)->f_name;
		t0 = vader_front_resolver$without_tests(l2, l3);
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
	l5 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(26u, 0u, 12u, 640u);
	l6 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 645u);
	l7 = (void*) _a2_arr;
	vader_struct_std_collections$Map__string__bool_t* _a3_obj = (vader_struct_std_collections$Map__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__bool_t));
	vader_obj_header_init(_a3_obj, 1010u);
	_a3_obj->f_ekeys = l5;
	_a3_obj->f_evals = l6;
	_a3_obj->f_index = l7;
	_a3_obj->f_mask = INT64_C(0);
	_a3_obj->f_grow_at = INT64_C(0);
	_a3_obj->f_size = INT64_C(0);
	_a3_obj->f_tombs = INT64_C(0);
	t0 = (void*) _a3_obj;
	vader_struct_std_collections$Set__string_t* _a4_obj = (vader_struct_std_collections$Set__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__string_t));
	vader_obj_header_init(_a4_obj, 1110u);
	_a4_obj->f_inner = t0;
	l5 = (void*) _a4_obj;
	vader_struct_vader_front_resolver$Untested_t* _a5_obj = (vader_struct_vader_front_resolver$Untested_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$Untested_t));
	vader_obj_header_init(_a5_obj, 1821u);
	_a5_obj->f_files = l2;
	_a5_obj->f_cut = l5;
	t0 = (void*) _a5_obj;
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$tests_declared(void* l0) {
	void* l1 = NULL;
	void* l2 = NULL;
	void* l5 = NULL;
	void* l9 = NULL;
	void* l13 = NULL;
	int64_t l3, l4, l6, l7;
	vader_box_t l8 = vader_box_null();
	vader_string_t l10 = 0;
	vader_string_t l11 = 0;
	int32_t l12;
	void* t0 = NULL;
	bool t1;
	vader_box_t* gc_roots[1] = { &l8 };
	void** gc_raw_roots[7] = { &l0, &l1, &l2, &l5, &l9, &l13, &t0 };
	vader_string_t* gc_atom_roots[2] = { &l10, &l11 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(334u, 0u, 13u, 1774u);
	l1 = (void*) _a0_arr;
	l2 = l0;
	l3 = vader_array_length(((vader_array_t*) l2));
	l4 = INT64_C(0);
	while ((l4 < l3)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		t0 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l4);
		l5 = ((vader_struct_toolchain_ast$Program_t*) t0)->f_decls;
		l6 = vader_array_length(((vader_array_t*) l5));
		l7 = INT64_C(0);
		while ((l7 < l6)) {
			vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
			VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
			l8 = vader_array_ref_load_box(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l7);
			if (l8.tag == 1181u) {
				l9 = l8.payload.obj;
				t1 = toolchain_ast$has_compiler_decorator(((vader_struct_toolchain_ast$FnDecl_t*) l9)->f_decorators, (uint8_t) 23);
				if (t1) {
					l10 = ((vader_struct_toolchain_ast$FnDecl_t*) l9)->f_name;
					l11 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) ((vader_struct_toolchain_ast$FnDecl_t*) l9)->f_span)->f_start)->f_file;
					l12 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) ((vader_struct_toolchain_ast$FnDecl_t*) l9)->f_name_span)->f_start)->f_line;
					vader_struct_vader_front_resolver$DeclaredTest_t* _a3_obj = (vader_struct_vader_front_resolver$DeclaredTest_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$DeclaredTest_t));
					vader_obj_header_init(_a3_obj, 1774u);
					_a3_obj->f_name = l10;
					_a3_obj->f_file = l11;
					_a3_obj->f_line = l12;
					l13 = (void*) _a3_obj;
					vader_array_push_ref((vader_array_t*) l1, l13);
				}
			}
			l7 = (l7 + INT64_C(1));
		}
		l4 = (l4 + INT64_C(1));
	}
	{ void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$through_aliases(void* l0, void* l1, void* l2, void* l3, void* l4, void* l5) {
	void* l6 = NULL;
	void* l7 = NULL;
	void* l8 = NULL;
	void* l9 = NULL;
	void* l10 = NULL;
	void* l14 = NULL;
	void* l16 = NULL;
	void* l17 = NULL;
	void* l18 = NULL;
	void* l19 = NULL;
	void* l21 = NULL;
	void* l22 = NULL;
	void* l23 = NULL;
	void* l26 = NULL;
	void* l29 = NULL;
	void* l30 = NULL;
	void* l31 = NULL;
	void* l32 = NULL;
	void* l33 = NULL;
	int32_t l11;
	vader_box_t l12 = vader_box_null(), l13 = vader_box_null(), l20 = vader_box_null(), l25 = vader_box_null(), l28 = vader_box_null(), l36 = vader_box_null(), l37 = vader_box_null();
	vader_string_t l15 = 0;
	vader_string_t l24 = 0;
	vader_string_t l27 = 0;
	int64_t l34, l35;
	void* t0 = NULL;
	vader_box_t t1 = vader_box_null();
	int64_t t2;
	vader_box_t* gc_roots[8] = { &l12, &l13, &l20, &l25, &l28, &l36, &l37, &t1 };
	void** gc_raw_roots[26] = {
		&l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l8, &l9, &l10, &l14, &l16, &l17, &l18, &l19, &l21,
		&l22, &l23, &l26, &l29, &l30, &l31, &l32, &l33, &t0,
	};
	vader_string_t* gc_atom_roots[3] = { &l15, &l24, &l27 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 8u, 26u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(480u, 0u, 13u, 2419u);
	l6 = (void*) _a0_arr;
	vader_struct_vader_front_resolver$TraitLookup_t* _a1_obj = (vader_struct_vader_front_resolver$TraitLookup_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$TraitLookup_t));
	vader_obj_header_init(_a1_obj, 1819u);
	_a1_obj->f_trait_decl = vader_box_obj(0u, NULL);
	_a1_obj->f_other_kind = 0u;
	_a1_obj->f_hidden = false;
	_a1_obj->f_args = l6;
	l6 = (void*) _a1_obj;
	vader_array_t* _a2_arr = vader_array_new(28u, 0u, 0u, 642u);
	l7 = (void*) _a2_arr;
	vader_array_t* _a3_arr = vader_array_new(35u, 0u, 0u, 653u);
	l8 = (void*) _a3_arr;
	vader_array_t* _a4_arr = vader_array_new(29u, 0u, 7u, 645u);
	l9 = (void*) _a4_arr;
	vader_struct_std_collections$Map__string__Any_t* _a5_obj = (vader_struct_std_collections$Map__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any_t));
	vader_obj_header_init(_a5_obj, 1004u);
	_a5_obj->f_ekeys = l7;
	_a5_obj->f_evals = l8;
	_a5_obj->f_index = l9;
	_a5_obj->f_mask = INT64_C(0);
	_a5_obj->f_grow_at = INT64_C(0);
	_a5_obj->f_size = INT64_C(0);
	_a5_obj->f_tombs = INT64_C(0);
	l7 = (void*) _a5_obj;
	l8 = l0;
	l9 = l1;
	l10 = l2;
	l11 = INT32_C(0);
	while ((l11 < INT32_C(16))) {
		l13 = toolchain_ast$trait_alias_target(((vader_struct_vader_front_resolver$DeclaredTrait_t*) l8)->f_decl);
		if (l13.tag == 0u) {
			vader_struct_vader_front_resolver$TraitLookup_t* _a6_obj = (vader_struct_vader_front_resolver$TraitLookup_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$TraitLookup_t));
			vader_obj_header_init(_a6_obj, 1819u);
			_a6_obj->f_trait_decl = vader_ref_box(((vader_struct_vader_front_resolver$DeclaredTrait_t*) l8)->f_decl);
			_a6_obj->f_other_kind = 0u;
			_a6_obj->f_hidden = false;
			_a6_obj->f_args = l10;
			t0 = (void*) _a6_obj;
			{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
		}
		l12 = l13;
		l14 = ((vader_struct_vader_front_resolver$LoadedModule_t*) l9)->f_collected;
		l15 = ((vader_struct_vader_front_resolver$DeclaredTrait_t*) l8)->f_file;
		l16 = vader_front_resolver$file_imports(l14, l15);
		l17 = ((vader_struct_vader_front_resolver$LoadedModule_t*) l9)->f_collected;
		l18 = vader_front_resolver$file_root_scope(l7, l17, l16, l3, l5);
		t1 = toolchain_ast$instance_head(l12);
		l20 = vader_front_resolver$trait_in_file_scope(t1, l9, l18, l3);
		if (l20.tag == 0u) {
			{ void* __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
		}
		l19 = l20.payload.obj;
		if (((vader_struct_vader_core_symbol$Symbol_t*) l19)->f_kind != INT32_C(3)) {
			vader_array_t* _a7_arr = vader_array_new(480u, 0u, 13u, 2419u);
			l21 = (void*) _a7_arr;
			vader_struct_vader_front_resolver$TraitLookup_t* _a8_obj = (vader_struct_vader_front_resolver$TraitLookup_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$TraitLookup_t));
			vader_obj_header_init(_a8_obj, 1819u);
			_a8_obj->f_trait_decl = vader_box_obj(0u, NULL);
			_a8_obj->f_other_kind = 1964u;
			_a8_obj->f_hidden = false;
			_a8_obj->f_args = l21;
			t0 = (void*) _a8_obj;
			{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
		}
		l23 = ((vader_struct_vader_front_resolver$LoadedProject_t*) l4)->f_modules;
		l24 = ((vader_struct_vader_core_symbol$Symbol_t*) l19)->f_module;
		l25 = std_collections$Map$std_core$Index$at__string__Any(l23, l24);
		if (l25.tag == 0u) {
			{ void* __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
		}
		l22 = l25.payload.obj;
		l27 = ((vader_struct_vader_core_symbol$Symbol_t*) l19)->f_name;
		l28 = vader_front_resolver$trait_named(l22, l27);
		if (l28.tag == 0u) {
			{ void* __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
		}
		l26 = l28.payload.obj;
		l29 = vader_front_resolver$new_subst();
		l30 = ((vader_struct_vader_front_resolver$DeclaredTrait_t*) l8)->f_decl;
		vader_front_resolver$bind_trait_params(l29, l30, l10);
		l31 = toolchain_ast$instance_args(l12);
		vader_struct___lambda_env_vader_front_resolver_25_t* _a9_obj = (vader_struct___lambda_env_vader_front_resolver_25_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_front_resolver_25_t));
		vader_obj_header_init(_a9_obj, 806u);
		_a9_obj->f_cap_0 = l29;
		l32 = (void*) _a9_obj;
		t2 = vader_array_length(((vader_array_t*) l31));
		vader_array_t* _a10_arr = vader_array_reserve(480u, (int64_t) t2, 13u, 2419u);
		l33 = (void*) _a10_arr;
		l34 = vader_array_length(((vader_array_t*) l31));
		l35 = INT64_C(0);
		while ((l35 < l34)) {
			vader_array_t* _a11_slotarr = ((vader_array_t*) l31);
			VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
			l36 = vader_array_ref_load_box(_a11_slotarr->buf, vader_array_offset(_a11_slotarr) + (size_t) l35);
			l37 = __lambda_vader_front_resolver_24(l32, l36);
			vader_array_push_ref((vader_array_t*) l33, l37.payload.obj);
			l35 = (l35 + INT64_C(1));
		}
		l10 = l33;
		l8 = l26;
		l9 = l22;
		l11 = (l11 + INT32_C(1));
	}
	vader_array_t* _a12_arr = vader_array_new(480u, 0u, 13u, 2419u);
	l6 = (void*) _a12_arr;
	vader_struct_vader_front_resolver$TraitLookup_t* _a13_obj = (vader_struct_vader_front_resolver$TraitLookup_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$TraitLookup_t));
	vader_obj_header_init(_a13_obj, 1819u);
	_a13_obj->f_trait_decl = vader_box_obj(0u, NULL);
	_a13_obj->f_other_kind = 1965u;
	_a13_obj->f_hidden = false;
	_a13_obj->f_args = l6;
	t0 = (void*) _a13_obj;
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_front_resolver$toolchain_folder(vader_box_t l0) {
	vader_string_t t0, t1;
	if (!(l0.tag == 0u)) {
		t0 = l0.payload.s;
		t1 = vader_front_resolver$dir_of(t0);
		return t1;
	}
	return 489u;
}

static vader_string_t vader_front_resolver$toolchain_runtime(void) {
	void* l0 = NULL;
	void* l1 = NULL;
	int32_t t0;
	vader_string_t t1 = 0;
	vader_box_t t2 = vader_box_null();
	bool t3;
	vader_box_t* gc_roots[1] = { &t2 };
	void** gc_raw_roots[2] = { &l0, &l1 };
	vader_string_t* gc_atom_roots[1] = { &t1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	t0 = vader_global$vader_front_resolver$toolchain_runtime$state;
	if (t0 == INT32_C(2)) {
		t1 = vader_global$vader_front_resolver$toolchain_runtime$instance;
		{ vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	std_runtime_scheduler$monitor_enter_to_publish();
	t2 = vader_global$vader_front_resolver$toolchain_runtime$gate;
	l0 = std_runtime_scheduler$gate_or_new(t2);
	vader_global$vader_front_resolver$toolchain_runtime$gate = vader_ref_box(l0);
	l1 = (void*) &vader_fn_static_vader_front_resolver$toolchain_runtime$keep;
	t3 = std_runtime_scheduler$run_gated(l0, l1);
	if (!(t3)) {
		vader_unreachable("singleton `toolchain_runtime` called while it initialises");
	}
	t1 = vader_global$vader_front_resolver$toolchain_runtime$instance;
	{ vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

void vader_front_resolver$toolchain_runtime$keep(void) {
	int32_t t0;
	vader_string_t t1 = 0;
	vader_string_t* gc_atom_roots[1] = { &t1 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 1u, gc_atom_roots };
	vader_gc_top = &gc_frame;
	t0 = vader_global$vader_front_resolver$toolchain_runtime$state;
	if (!(t0 == INT32_C(2))) {
		t1 = vader_front_resolver$toolchain_runtime$singleton();
		vader_global$vader_front_resolver$toolchain_runtime$instance = t1;
		vader_global$vader_front_resolver$toolchain_runtime$state = INT32_C(2);
		{ vader_gc_top = gc_frame.prev; return; }
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static vader_string_t vader_front_resolver$toolchain_runtime$singleton(void) {
	vader_string_t t0;
	t0 = vader_front_resolver$resolve_sidecar(3152u, 3727u);
	return t0;
}

static vader_box_t vader_front_resolver$trait_at_its_params(void* l0) {
	void* l1 = NULL;
	void* l4 = NULL;
	void* l7 = NULL;
	void* l8 = NULL;
	vader_string_t l2 = 0;
	vader_box_t l3 = vader_box_null(), l9 = vader_box_null();
	int64_t l5, l6;
	int64_t t0;
	void* t1 = NULL;
	vader_box_t* gc_roots[2] = { &l3, &l9 };
	void** gc_raw_roots[6] = { &l0, &l1, &l4, &l7, &l8, &t1 };
	vader_string_t* gc_atom_roots[1] = { &l2 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l1 = ((vader_struct_toolchain_ast$TraitDecl_t*) l0)->f_name_span;
	l2 = ((vader_struct_toolchain_ast$TraitDecl_t*) l0)->f_name;
	l3 = vader_front_resolver$plain_ident(l1, l2);
	t0 = vader_array_length(((vader_array_t*) ((vader_struct_toolchain_ast$TraitDecl_t*) l0)->f_type_params));
	if (t0 == INT64_C(0)) {
		{ vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
	}
	t0 = vader_array_length(((vader_array_t*) ((vader_struct_toolchain_ast$TraitDecl_t*) l0)->f_type_params));
	vader_array_t* _a0_arr = vader_array_reserve(480u, (int64_t) t0, 13u, 2419u);
	l1 = (void*) _a0_arr;
	l4 = ((vader_struct_toolchain_ast$TraitDecl_t*) l0)->f_type_params;
	l5 = vader_array_length(((vader_array_t*) l4));
	l6 = INT64_C(0);
	while ((l6 < l5)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		l7 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l6);
		l8 = ((vader_struct_toolchain_ast$TypeParam_t*) l7)->f_span;
		l2 = ((vader_struct_toolchain_ast$TypeParam_t*) l7)->f_name;
		l9 = vader_front_resolver$plain_ident(l8, l2);
		vader_array_push_ref((vader_array_t*) l1, l9.payload.obj);
		l6 = (l6 + INT64_C(1));
	}
	vader_struct_toolchain_ast$GenericInstExpr_t* _a2_obj = (vader_struct_toolchain_ast$GenericInstExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$GenericInstExpr_t));
	vader_obj_header_init(_a2_obj, 1185u);
	_a2_obj->f_span = ((vader_struct_toolchain_ast$TraitDecl_t*) l0)->f_name_span;
	_a2_obj->f_id = INT64_C(0);
	_a2_obj->f_callee = l3;
	_a2_obj->f_type_args = l1;
	t1 = (void*) _a2_obj;
	{ vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_resolver$trait_in_file_scope(vader_box_t l0, void* l1, void* l2, void* l3) {
	void* l4;
	void* l7;
	vader_string_t l5;
	vader_box_t l6;
	int32_t l8;
	void* t0;
	vader_string_t t1;
	vader_box_t t2;
	if (l0.tag == 1186u) {
		t0 = l0.payload.obj;
		t1 = ((vader_struct_toolchain_ast$IdentExpr_t*) t0)->f_name;
		t2 = vader_front_resolver$name_in_file_scope(t1, l1, l2, l3);
		return t2;
	}
	if (l0.tag == 1179u) {
		t0 = l0.payload.obj;
		if (((vader_struct_toolchain_ast$FieldExpr_t*) t0)->f_target.tag == 1186u) {
			t0 = l0.payload.obj;
			l5 = ((vader_struct_toolchain_ast$IdentExpr_t*) ((vader_struct_toolchain_ast$FieldExpr_t*) t0)->f_target.payload.obj)->f_name;
			l6 = std_collections$Map$std_core$Index$at__string__Any(l2, l5);
			if (l6.tag == 0u) {
				return vader_box_obj(0u, NULL);
			}
			l4 = l6.payload.obj;
			l7 = ((vader_struct_vader_front_resolver$CollectedModule_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l1)->f_collected)->f_imports;
			l8 = ((vader_struct_vader_core_symbol$Symbol_t*) l4)->f_id;
			l6 = std_collections$Map$std_core$Index$at__i32__Any(l7, l8);
			if (l6.tag == 0u) {
				return vader_box_obj(0u, NULL);
			}
			l4 = l6.payload.obj;
			if (!(((vader_struct_vader_front_resolver$ImportInfo_t*) l4)->f_imported_name.tag == 0u)) {
				return vader_box_obj(0u, NULL);
			}
			l5 = ((vader_struct_vader_front_resolver$ImportInfo_t*) l4)->f_path;
			l6 = std_collections$Map$std_core$Index$at__string__Any(l3, l5);
			if (l6.tag == 0u) {
				return vader_box_obj(0u, NULL);
			}
			l4 = l6.payload.obj;
			l4 = ((vader_struct_vader_front_resolver$CollectedModule_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l4)->f_collected)->f_symbols;
			t0 = l0.payload.obj;
			l5 = ((vader_struct_toolchain_ast$FieldExpr_t*) t0)->f_field;
			t2 = std_collections$Map$std_core$Index$at__string__Any(l4, l5);
			return t2;
		}
		return vader_box_obj(0u, NULL);
	}
	return vader_box_obj(0u, NULL);
}

static vader_box_t vader_front_resolver$trait_named(void* l0, vader_string_t l1) {
	void* l2 = NULL;
	void* l5 = NULL;
	void* l6 = NULL;
	void* l10 = NULL;
	int64_t l3, l4, l7, l8;
	vader_box_t l9 = vader_box_null();
	vader_string_t l11 = 0;
	vader_string_t t0 = 0;
	void* t1 = NULL;
	vader_box_t* gc_roots[1] = { &l9 };
	void** gc_raw_roots[6] = { &l0, &l2, &l5, &l6, &l10, &t1 };
	vader_string_t* gc_atom_roots[3] = { &l1, &l11, &t0 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_vader_front_resolver$Module_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l0)->f_module)->f_files;
	l3 = vader_array_length(((vader_array_t*) l2));
	l4 = INT64_C(0);
	while ((l4 < l3)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		l5 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l4);
		l6 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) l5)->f_program)->f_decls;
		l7 = vader_array_length(((vader_array_t*) l6));
		l8 = INT64_C(0);
		while ((l8 < l7)) {
			vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
			VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
			l9 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l8);
			if (l9.tag == 1232u) {
				l10 = l9.payload.obj;
				t0 = ((vader_struct_toolchain_ast$TraitDecl_t*) l10)->f_name;
				if (t0 == l1) {
					l11 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) l5)->f_program)->f_file;
					vader_struct_vader_front_resolver$DeclaredTrait_t* _a2_obj = (vader_struct_vader_front_resolver$DeclaredTrait_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$DeclaredTrait_t));
					vader_obj_header_init(_a2_obj, 1775u);
					_a2_obj->f_decl = l10;
					_a2_obj->f_file = l11;
					t1 = (void*) _a2_obj;
					{ vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
				}
			}
			l8 = (l8 + INT64_C(1));
		}
		l4 = (l4 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_front_resolver$trait_owner_module(void* l0, void* l1, void* l2, void* l3) {
	vader_box_t l4;
	void* l5;
	void* l7;
	vader_string_t l6;
	int32_t l8;
	void* t0;
	vader_box_t t1;
	vader_string_t t2;
	l4 = toolchain_ast$impl_trait_head(l0);
	if (l4.tag == 1179u) {
		t0 = l4.payload.obj;
		if (((vader_struct_toolchain_ast$FieldExpr_t*) t0)->f_target.tag == 1186u) {
			t0 = l4.payload.obj;
			l6 = ((vader_struct_toolchain_ast$IdentExpr_t*) ((vader_struct_toolchain_ast$FieldExpr_t*) t0)->f_target.payload.obj)->f_name;
			l4 = std_collections$Map$std_core$Index$at__string__Any(l2, l6);
			if (l4.tag == 0u) {
				return vader_box_obj(0u, NULL);
			}
			l5 = l4.payload.obj;
			l7 = ((vader_struct_vader_front_resolver$ImportTargetTable_t*) l3)->f_namespace_targets;
			l8 = ((vader_struct_vader_core_symbol$Symbol_t*) l5)->f_id;
			t1 = std_collections$Map$std_core$Index$at__i32__string(l7, l8);
			return t1;
		}
	}
	t2 = toolchain_ast$impl_trait_name(l0);
	l4 = vader_front_resolver$lookup_trait_sym(t2, l1, l2, l3);
	if (l4.tag == 0u) {
		return vader_box_obj(0u, NULL);
	}
	l5 = l4.payload.obj;
	if (((vader_struct_vader_core_symbol$Symbol_t*) l5)->f_kind == INT32_C(3)) {
		t2 = ((vader_struct_vader_core_symbol$Symbol_t*) l5)->f_module;
		return vader_box_string(642u, t2);
	}
	return vader_box_obj(0u, NULL);
}

static vader_box_t vader_front_resolver$trait_self_bound(void* l0) {
	vader_box_t l1 = vader_box_null(), l2 = vader_box_null();
	void* l3 = NULL;
	void* l4 = NULL;
	void* t0 = NULL;
	vader_box_t* gc_roots[2] = { &l1, &l2 };
	void** gc_raw_roots[4] = { &l0, &l3, &l4, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l1 = vader_front_resolver$trait_at_its_params(l0);
	l2 = ((vader_struct_toolchain_ast$TraitDecl_t*) l0)->f_requires;
	if (l2.tag == 0u) {
		{ vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l3 = ((vader_struct_toolchain_ast$TraitDecl_t*) l0)->f_name_span;
	l4 = toolchain_span$empty_span();
	vader_struct_toolchain_ast$BinaryExpr_t* _a0_obj = (vader_struct_toolchain_ast$BinaryExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$BinaryExpr_t));
	vader_obj_header_init(_a0_obj, 1149u);
	_a0_obj->f_span = l3;
	_a0_obj->f_id = INT64_C(0);
	_a0_obj->f_op = (uint8_t) 7;
	_a0_obj->f_op_span = l4;
	_a0_obj->f_left = l1;
	_a0_obj->f_right = l2;
	t0 = (void*) _a0_obj;
	{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$trimmed_to_reached(void* l0) {
	void* l1 = NULL;
	void* l2 = NULL;
	void* l5 = NULL;
	void* l6 = NULL;
	void* l7 = NULL;
	void* l9 = NULL;
	void* l10 = NULL;
	void* l11 = NULL;
	void* l12 = NULL;
	void* l13 = NULL;
	void* l14 = NULL;
	void* l15 = NULL;
	void* l16 = NULL;
	void* l17 = NULL;
	int64_t l3, l4;
	bool l8;
	int64_t t0;
	void* t1 = NULL;
	void** gc_raw_roots[16] = {
		&l0, &l1, &l2, &l5, &l6, &l7, &l9, &l10, &l11, &l12, &l13, &l14, &l15, &l16, &l17, &t1,
	};
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 16u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_deferred));
	vader_array_t* _a0_arr = vader_array_reserve(350u, (int64_t) t0, 13u, 1804u);
	l1 = (void*) _a0_arr;
	l2 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_deferred;
	l3 = vader_array_length(((vader_array_t*) l2));
	l4 = INT64_C(0);
	while ((l4 < l3)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		l5 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l4);
		l6 = ((vader_struct_vader_front_resolver$DeferredModule_t*) l5)->f_sources;
		l7 = ((vader_struct_vader_front_resolver$DeferredModule_t*) l5)->f_found;
		l8 = vader_front_resolver$is_trimmed(l0, l7);
		l9 = ((vader_struct_vader_front_resolver$DeferredModule_t*) l5)->f_discarded_bodies;
		vader_struct_vader_front_resolver$ReachUnit_t* _a2_obj = (vader_struct_vader_front_resolver$ReachUnit_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$ReachUnit_t));
		vader_obj_header_init(_a2_obj, 1804u);
		_a2_obj->f_files = l6;
		_a2_obj->f_trimmed = l8;
		_a2_obj->f_discarded = l9;
		l10 = (void*) _a2_obj;
		vader_array_push_ref((vader_array_t*) l1, l10);
		l4 = (l4 + INT64_C(1));
	}
	l2 = (void*) &vader_data_12;
	l2 = vader_front_resolver$only_reached(l1, l2);
	t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_deferred));
	vader_array_t* _a3_arr = vader_array_reserve(335u, (int64_t) t0, 13u, 1776u);
	l5 = (void*) _a3_arr;
	l3 = INT64_C(0);
	l4 = vader_array_length(((vader_array_t*) ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_deferred));
	while ((l3 < l4)) {
		vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_deferred);
		VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l3)
		l6 = vader_array_ref_load_obj(_a4_slotarr->buf, vader_array_offset(_a4_slotarr) + (size_t) l3);
		l7 = ((vader_struct_vader_front_resolver$DeferredModule_t*) l6)->f_found;
		vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l3)
		l9 = vader_array_ref_load_obj(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) l3);
		l10 = ((vader_struct_vader_front_resolver$Reached_t*) l9)->f_files;
		l11 = ((vader_struct_vader_front_resolver$DeferredModule_t*) l6)->f_discarded_bodies;
		l12 = ((vader_struct_vader_front_resolver$DeferredModule_t*) l6)->f_target_decls;
		l13 = ((vader_struct_vader_front_resolver$DeferredModule_t*) l6)->f_files_without_tests;
		vader_array_t* _a6_slotarr = ((vader_array_t*) l1);
		VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l3)
		t1 = vader_array_ref_load_obj(_a6_slotarr->buf, vader_array_offset(_a6_slotarr) + (size_t) l3);
		l8 = ((vader_struct_vader_front_resolver$ReachUnit_t*) t1)->f_trimmed;
		l14 = ((vader_struct_vader_front_resolver$Reached_t*) l9)->f_lost_impl_traits;
		l15 = ((vader_struct_vader_front_resolver$DeferredModule_t*) l6)->f_late;
		l16 = ((vader_struct_vader_front_resolver$DeferredModule_t*) l6)->f_uncovered;
		vader_struct_vader_front_resolver$DeferredModule_t* _a7_obj = (vader_struct_vader_front_resolver$DeferredModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$DeferredModule_t));
		vader_obj_header_init(_a7_obj, 1776u);
		_a7_obj->f_found = l7;
		_a7_obj->f_sources = l10;
		_a7_obj->f_discarded_bodies = l11;
		_a7_obj->f_target_decls = l12;
		_a7_obj->f_files_without_tests = l13;
		_a7_obj->f_trimmed = l8;
		_a7_obj->f_lost_impl_traits = l14;
		_a7_obj->f_late = l15;
		_a7_obj->f_uncovered = l16;
		l17 = (void*) _a7_obj;
		vader_array_push_ref((vader_array_t*) l5, l17);
		l3 = (l3 + INT64_C(1));
	}
	{ void* __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
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
	l1 = std_fs$read_file_string(l0, INT64_C(16777216));
	if (!(l1.tag == 642u)) {
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	t0 = l1.payload.s;
	{ vader_box_t __vret = vader_box_string(642u, t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_front_resolver$tupled(void* l0) {
	vader_string_t l1 = 0;
	int64_t t0;
	vader_string_t t1 = 0;
	vader_box_t t2 = vader_box_null();
	vader_box_t* gc_roots[1] = { &t2 };
	void** gc_raw_roots[1] = { &l0 };
	vader_string_t* gc_atom_roots[2] = { &l1, &t1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	t0 = vader_array_length(((vader_array_t*) l0));
	if (!(t0 == INT64_C(1))) {
		l1 = std_string$join(l0, 441u);
		t1 = concat_3(1217u, l1, 1234u);
		{ vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
	VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
	t2 = vader_array_box_slots(_a0_slotarr->buf)[vader_array_offset(_a0_slotarr) + (size_t) INT32_C(0)];
	t1 = t2.payload.s;
	{ vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$two_folders(vader_string_t l0, void* l1) {
	void* l2 = NULL;
	vader_string_t l3 = 0;
	vader_string_t l4 = 0;
	vader_string_t l5 = 0;
	void* t0 = NULL;
	bool t1;
	void** gc_raw_roots[3] = { &l1, &l2, &t0 };
	vader_string_t* gc_atom_roots[4] = { &l0, &l3, &l4, &l5 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
	VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
	VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
	l2 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT32_C(0));
	VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(1))
	t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT32_C(1));
	l3 = ((vader_struct_vader_front_resolver$PackageFolder_t*) t0)->f_path;
	t1 = ((vader_struct_vader_front_resolver$PackageFolder_t*) l2)->f_of_toolchain;
	if (t1) {
		l4 = concat_5(3363u, l0, 1652u, l3, 1424u);
	} else {
		l5 = ((vader_struct_vader_front_resolver$PackageFolder_t*) l2)->f_path;
		l4 = concat_7(1307u, l0, 1473u, l5, 1337u, l3, 1307u);
	}
	l2 = vader_front_resolver$zero_span(l3);
	t0 = toolchain_diagnostics$resolver_error((uint8_t) 37, l2, l4);
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_resolver$type_head_name(vader_box_t l0) {
	vader_box_t l1;
	void* t0;
	vader_string_t t1;
	if (l0.tag == 1186u) {
		t0 = l0.payload.obj;
		t1 = ((vader_struct_toolchain_ast$IdentExpr_t*) t0)->f_name;
		return vader_box_string(642u, t1);
	}
	if (l0.tag == 1185u) {
		t0 = l0.payload.obj;
		l1 = ((vader_struct_toolchain_ast$GenericInstExpr_t*) t0)->f_callee;
		if (l1.tag == 1186u) {
			t0 = l1.payload.obj;
			t1 = ((vader_struct_toolchain_ast$IdentExpr_t*) t0)->f_name;
			return vader_box_string(642u, t1);
		}
		return vader_box_obj(0u, NULL);
	}
	return vader_box_obj(0u, NULL);
}

static void* vader_front_resolver$type_span(void* l0) {
	vader_box_t l1;
	l1 = ((vader_struct_toolchain_ast$FnParam_t*) l0)->f_ty;
	if (l1.tag == 0u) {
		return ((vader_struct_toolchain_ast$FnParam_t*) l0)->f_span;
	}
	return VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l1.payload.obj);
}

static vader_box_t vader_front_resolver$union_in_bound(vader_box_t l0) {
	vader_box_t l1;
	void* t0;
	vader_box_t t1;
	if (!(l0.tag == 1149u)) {
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

static void* vader_front_resolver$unloaded(void* l0, void* l1) {
	void* l2 = NULL;
	void* l3 = NULL;
	void* l4 = NULL;
	void* l7 = NULL;
	void* l8 = NULL;
	int64_t l5, l6;
	vader_string_t l9 = 0;
	vader_string_t l10 = 0;
	vader_string_t l11 = 0;
	void* t0 = NULL;
	bool t1;
	void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l4, &l7, &l8, &t0 };
	vader_string_t* gc_atom_roots[3] = { &l9, &l10, &l11 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 8u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
	l2 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(26u, 0u, 12u, 640u);
	l3 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 645u);
	l4 = (void*) _a2_arr;
	vader_struct_std_collections$Map__string__bool_t* _a3_obj = (vader_struct_std_collections$Map__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__bool_t));
	vader_obj_header_init(_a3_obj, 1010u);
	_a3_obj->f_ekeys = l2;
	_a3_obj->f_evals = l3;
	_a3_obj->f_index = l4;
	_a3_obj->f_mask = INT64_C(0);
	_a3_obj->f_grow_at = INT64_C(0);
	_a3_obj->f_size = INT64_C(0);
	_a3_obj->f_tombs = INT64_C(0);
	t0 = (void*) _a3_obj;
	vader_struct_std_collections$Set__string_t* _a4_obj = (vader_struct_std_collections$Set__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__string_t));
	vader_obj_header_init(_a4_obj, 1110u);
	_a4_obj->f_inner = t0;
	l2 = (void*) _a4_obj;
	vader_array_t* _a5_arr = vader_array_new(336u, 0u, 13u, 1777u);
	l3 = (void*) _a5_arr;
	l4 = l1;
	l5 = vader_array_length(((vader_array_t*) l4));
	l6 = INT64_C(0);
	while ((l6 < l5)) {
		vader_array_t* _a6_slotarr = ((vader_array_t*) l4);
		VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
		l7 = vader_array_ref_load_obj(_a6_slotarr->buf, vader_array_offset(_a6_slotarr) + (size_t) l6);
		l8 = ((vader_struct_vader_front_resolver$LoadState_t*) l0)->f_modules;
		l9 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) l7)->f_folder;
		t1 = vader_front_resolver$has_module(l8, l9);
		if (!(t1)) {
			l10 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) l7)->f_folder;
			t1 = std_collections$Set$std_core$Contains$contains__string(l2, l10);
			if (!(t1)) {
				l11 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) l7)->f_folder;
				std_collections$add__string(l2, l11);
				vader_array_push_ref((vader_array_t*) l3, l7);
				l6 = (l6 + INT64_C(1));
				continue;
			}
		}
		l6 = (l6 + INT64_C(1));
	}
	{ void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$unplaced_param(void* l0, void* l1) {
	void* l2 = NULL;
	void* l3 = NULL;
	void* l6 = NULL;
	int64_t l4;
	vader_string_t l5 = 0;
	vader_box_t l7 = vader_box_null(), l8 = vader_box_null();
	bool l9;
	void* t0 = NULL;
	vader_box_t* gc_roots[2] = { &l7, &l8 };
	void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l6, &t0 };
	vader_string_t* gc_atom_roots[1] = { &l5 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = vader_front_resolver$substitute_param(l0, l1);
	l3 = vader_front_resolver$unplaced_span();
	l4 = ((vader_struct_toolchain_ast$FnParam_t*) l2)->f_id;
	l5 = ((vader_struct_toolchain_ast$FnParam_t*) l2)->f_name;
	l6 = vader_front_resolver$unplaced_span();
	l7 = ((vader_struct_toolchain_ast$FnParam_t*) l2)->f_ty;
	l8 = ((vader_struct_toolchain_ast$FnParam_t*) l2)->f_default_value;
	l9 = ((vader_struct_toolchain_ast$FnParam_t*) l2)->f_variadic;
	l2 = ((vader_struct_toolchain_ast$FnParam_t*) l2)->f_decorators;
	vader_struct_toolchain_ast$FnParam_t* _a0_obj = (vader_struct_toolchain_ast$FnParam_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$FnParam_t));
	vader_obj_header_init(_a0_obj, 1182u);
	_a0_obj->f_span = l3;
	_a0_obj->f_id = l4;
	_a0_obj->f_name = l5;
	_a0_obj->f_name_span = l6;
	_a0_obj->f_ty = l7;
	_a0_obj->f_default_value = l8;
	_a0_obj->f_variadic = l9;
	_a0_obj->f_decorators = l2;
	t0 = (void*) _a0_obj;
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$unplaced_span(void) {
	void* l0 = NULL;
	void* t0 = NULL;
	void** gc_raw_roots[2] = { &l0, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	vader_struct_toolchain_span$Position_t* _a0_obj = (vader_struct_toolchain_span$Position_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Position_t));
	vader_obj_header_init(_a0_obj, 1288u);
	_a0_obj->f_file = 622u;
	_a0_obj->f_offset = INT64_C(0);
	_a0_obj->f_line = INT32_C(0);
	_a0_obj->f_column = INT32_C(0);
	l0 = (void*) _a0_obj;
	vader_struct_toolchain_span$Span_t* _a1_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
	vader_obj_header_init(_a1_obj, 1289u);
	_a1_obj->f_start = l0;
	_a1_obj->f_end = l0;
	t0 = (void*) _a1_obj;
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_resolver$version_in(vader_string_t l0, void* l1) {
	vader_string_t l2 = 0;
	vader_string_t l5 = 0;
	int64_t l3, l4;
	vader_string_t t0 = 0;
	bool t1;
	void** gc_raw_roots[1] = { &l1 };
	vader_string_t* gc_atom_roots[4] = { &l0, &l2, &l5, &t0 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	t0 = ((vader_struct_vader_core_wit$WitPackageName_t*) l1)->f_name;
	l2 = concat_2(t0, 640u);
	t1 = std_string$starts_with(l0, l2);
	if (!(t1)) {
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	l3 = (int64_t) vader_string_byte_len(l2);
	l4 = (int64_t) vader_string_byte_len(l0);
	l2 = vader_string_byte_slice(l0, l3, l4);
	t0 = ((vader_struct_vader_core_wit$WitPackageName_t*) l1)->f_version;
	if (t0 != 0u) {
		l5 = ((vader_struct_vader_core_wit$WitPackageName_t*) l1)->f_version;
		if (l2 != l5) {
			{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
		}
		{ vader_box_t __vret = vader_box_string(642u, l2); vader_gc_top = gc_frame.prev; return __vret; }
	}
	{ vader_box_t __vret = vader_box_string(642u, l2); vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_front_resolver$walk_block(void* l0, void* l1) {
	int64_t l2, l3;
	vader_box_t l4 = vader_box_null(), l5 = vader_box_null(), l6 = vader_box_null();
	vader_box_t* gc_roots[3] = { &l4, &l5, &l6 };
	void** gc_raw_roots[2] = { &l0, &l1 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	vader_front_resolver$push(((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope);
	l2 = INT64_C(0);
	l3 = vader_array_length(((vader_array_t*) ((vader_struct_toolchain_ast$BlockExpr_t*) l1)->f_stmts));
	while ((l2 < l3)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$BlockExpr_t*) l1)->f_stmts);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
		l4 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l2);
		vader_front_resolver$walk_stmt(l0, l4);
		vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$BlockExpr_t*) l1)->f_stmts);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
		l5 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l2);
		l6 = vader_front_resolver$next_in_block(l1, l2);
		vader_front_resolver$warn_block_after_else_value(l0, l5, l6);
		l2 = (l2 + INT64_C(1));
	}
	l4 = ((vader_struct_toolchain_ast$BlockExpr_t*) l1)->f_trailing;
	vader_front_resolver$walk_opt_expr(l0, l4);
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
	l4 = std_collections$Map$std_core$Index$at__string__Any(l2, l3);
	if (l4.tag == 0u) {
		vader_front_resolver$walk_block(l0, l1);
		{ vader_gc_top = gc_frame.prev; return; }
	}
	l2 = l4.payload.obj;
	l2 = vader_front_resolver$enter_file(l0, l2);
	vader_front_resolver$walk_block(l0, l1);
	vader_front_resolver$enter_file(l0, l2);
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
	if (l1.tag == 1191u) {
		{ vader_gc_top = gc_frame.prev; return; }
	}
	if (l1.tag == 1181u) {
		l2 = l1.payload.obj;
		vader_front_resolver$walk_fn_decl(l0, l2);
	} else if (l1.tag == 1224u) {
		l2 = l1.payload.obj;
		vader_front_resolver$walk_struct_decl(l0, l2);
	} else if (l1.tag == 1172u) {
		l2 = l1.payload.obj;
		vader_front_resolver$walk_enum_decl(l0, l2);
	} else if (l1.tag == 1232u) {
		l2 = l1.payload.obj;
		vader_front_resolver$walk_trait_decl(l0, l2);
	} else if (l1.tag == 1190u) {
		l2 = l1.payload.obj;
		vader_front_resolver$walk_impl_decl(l0, l2);
	} else if (l1.tag == 1234u) {
		vader_front_resolver$push(((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope);
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$TypeAliasDecl_t*) t0)->f_type_params;
		l3 = vader_array_length(((vader_array_t*) l2));
		l4 = INT64_C(0);
		while ((l4 < l3)) {
			vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
			VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
			VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
			l5 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l4);
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
	} else if (l1.tag == 1157u) {
		t0 = l1.payload.obj;
		l6 = ((vader_struct_toolchain_ast$ConstDecl_t*) t0)->f_ty;
		vader_front_resolver$walk_opt_expr(l0, l6);
		t0 = l1.payload.obj;
		l6 = ((vader_struct_toolchain_ast$ConstDecl_t*) t0)->f_value;
		vader_front_resolver$walk_expr(l0, l6);
	} else {
		if (!(l1.tag == 1147u)) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		t0 = l1.payload.obj;
		l6 = ((vader_struct_toolchain_ast$AssertDecl_t*) t0)->f_condition;
		vader_front_resolver$walk_expr(l0, l6);
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$walk_declared_decorator(void* l0, void* l1) {
	void* l2 = NULL;
	void* l5 = NULL;
	void* l6 = NULL;
	vader_string_t l3 = 0;
	vader_box_t l4 = vader_box_null();
	uint64_t l7;
	vader_box_t* gc_roots[1] = { &l4 };
	void** gc_raw_roots[5] = { &l0, &l1, &l2, &l5, &l6 };
	vader_string_t* gc_atom_roots[1] = { &l3 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope;
	l3 = ((vader_struct_toolchain_ast$Decorator_t*) l1)->f_name;
	l4 = vader_front_resolver$lookup(l2, l3);
	if (l4.tag == 0u) {
		l5 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_diags;
		l6 = ((vader_struct_toolchain_ast$Decorator_t*) l1)->f_name_span;
		l3 = ((vader_struct_toolchain_ast$Decorator_t*) l1)->f_name;
		l3 = concat_3(1708u, l3, 1307u);
		l6 = toolchain_diagnostics$resolver_error((uint8_t) 9, l6, l3);
		vader_array_push_ref((vader_array_t*) l5, l6);
		{ vader_gc_top = gc_frame.prev; return; }
	}
	l2 = l4.payload.obj;
	l5 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_idents;
	l7 = toolchain_span$Span$std_core$Hash$hash(((vader_struct_toolchain_ast$Decorator_t*) l1)->f_name_span);
	std_collections$Map$std_core$IndexSet$set_at__u64__Any(l5, l7, vader_ref_box(l2));
	vader_front_resolver$walk_decorator_args(l0, l1);
	{ vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$walk_decorator_args(void* l0, void* l1) {
	void* l2 = NULL;
	int64_t l3, l4;
	vader_box_t l5 = vader_box_null();
	void* t0 = NULL;
	vader_box_t* gc_roots[1] = { &l5 };
	void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_toolchain_ast$Decorator_t*) l1)->f_args;
	l3 = vader_array_length(((vader_array_t*) l2));
	l4 = INT64_C(0);
	while ((l4 < l3)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
		t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l4);
		l5 = ((vader_struct_toolchain_ast$CallArg_t*) t0)->f_value;
		vader_front_resolver$walk_expr(l0, l5);
		l4 = (l4 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$walk_decorators(void* l0, void* l1) {
	void* l2 = NULL;
	void* l5 = NULL;
	void* l7 = NULL;
	int64_t l3, l4;
	vader_box_t l6 = vader_box_null();
	bool t0;
	vader_box_t* gc_roots[1] = { &l6 };
	void** gc_raw_roots[5] = { &l0, &l1, &l2, &l5, &l7 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l2 = l1;
	l3 = vader_array_length(((vader_array_t*) l2));
	l4 = INT64_C(0);
	while ((l4 < l3)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
		l5 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l4);
		l6 = ((vader_struct_toolchain_ast$Decorator_t*) l5)->f_qualifier;
		if (l6.tag == 0u) {
			t0 = toolchain_parser$is_compiler_decorator(l5);
			if (t0) {
				t0 = toolchain_ast$is_compiler(l5, (uint8_t) 22);
				if (t0) {
					vader_front_resolver$check_target_selectors(l0, l5);
					l4 = (l4 + INT64_C(1));
					continue;
				}
				t0 = vader_front_resolver$is_contract_decorator(l5);
				if (t0) {
					l4 = (l4 + INT64_C(1));
					continue;
				}
				vader_front_resolver$walk_decorator_args(l0, l5);
				l4 = (l4 + INT64_C(1));
				continue;
			}
			vader_front_resolver$walk_declared_decorator(l0, l5);
			l4 = (l4 + INT64_C(1));
			continue;
		}
		l7 = l6.payload.obj;
		vader_front_resolver$walk_ident(l0, l7, false);
		vader_front_resolver$walk_decorator_args(l0, l5);
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
	if (l2.tag == 1164u) {
		t0 = l3.payload.obj;
		l4 = ((vader_struct_toolchain_ast$DeferStmtBody_t*) t0)->f_stmt;
		vader_front_resolver$walk_stmt(l0, l4);
		{ vader_gc_top = gc_frame.prev; return; }
	}
	if (!(l2.tag == 1162u)) {
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
	void* l8 = NULL;
	int64_t l3, l4;
	vader_box_t l5 = vader_box_null();
	vader_box_t t0 = vader_box_null();
	vader_box_t* gc_roots[2] = { &l5, &t0 };
	void** gc_raw_roots[6] = { &l0, &l1, &l2, &l6, &l7, &l8 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_toolchain_ast$EnumDecl_t*) l1)->f_decorators;
	vader_front_resolver$walk_decorators(l0, l2);
	l2 = ((vader_struct_toolchain_ast$EnumDecl_t*) l1)->f_header;
	l3 = vader_array_length(((vader_array_t*) l2));
	l4 = INT64_C(0);
	while ((l4 < l3)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
		l5 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l4);
		vader_front_resolver$walk_expr(l0, l5);
		l4 = (l4 + INT64_C(1));
	}
	l2 = ((vader_struct_toolchain_ast$EnumDecl_t*) l1)->f_variants;
	l3 = vader_array_length(((vader_array_t*) l2));
	l4 = INT64_C(0);
	while ((l4 < l3)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
		l6 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l4);
		l7 = ((vader_struct_toolchain_ast$EnumVariant_t*) l6)->f_decorators;
		vader_front_resolver$walk_decorators(l0, l7);
		if (!(((vader_struct_toolchain_ast$EnumVariant_t*) l6)->f_data.tag == 0u)) {
			t0 = ((vader_struct_toolchain_ast$EnumVariant_t*) l6)->f_data;
			l8 = t0.payload.obj;
			vader_front_resolver$walk_struct_lit_items(l0, l8);
		}
		l4 = (l4 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$walk_expr(void* l0, vader_box_t l1) {
	void* l2 = NULL;
	void* l6 = NULL;
	vader_box_t l3 = vader_box_null(), l7 = vader_box_null(), l8 = vader_box_null(), l9 = vader_box_null(), l10 = vader_box_null();
	int64_t l4, l5;
	void* t0 = NULL;
	vader_box_t* gc_roots[6] = { &l1, &l3, &l7, &l8, &l9, &l10 };
	void** gc_raw_roots[4] = { &l0, &l2, &l6, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 6u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	if (l1.tag == 1186u) {
		l2 = l1.payload.obj;
		vader_front_resolver$walk_ident(l0, l2, false);
		{ vader_gc_top = gc_frame.prev; return; }
	}
	if (l1.tag == 1154u) {
		t0 = l1.payload.obj;
		l3 = ((vader_struct_toolchain_ast$CallExpr_t*) t0)->f_callee;
		if (l3.tag == 1186u) {
			l2 = l3.payload.obj;
			vader_front_resolver$walk_ident(l0, l2, true);
		} else {
			vader_front_resolver$walk_expr(l0, l3);
		}
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$CallExpr_t*) t0)->f_type_args;
		l4 = vader_array_length(((vader_array_t*) l2));
		l5 = INT64_C(0);
		while ((l5 < l4)) {
			vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
			VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
			VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
			l3 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
			vader_front_resolver$walk_expr(l0, l3);
			l5 = (l5 + INT64_C(1));
		}
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$CallExpr_t*) t0)->f_args;
		l4 = vader_array_length(((vader_array_t*) l2));
		l5 = INT64_C(0);
		while ((l5 < l4)) {
			vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
			VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
			VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
			t0 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l5);
			l3 = ((vader_struct_toolchain_ast$CallArg_t*) t0)->f_value;
			vader_front_resolver$walk_expr(l0, l3);
			l5 = (l5 + INT64_C(1));
		}
	} else if (l1.tag == 1179u) {
		t0 = l1.payload.obj;
		l3 = ((vader_struct_toolchain_ast$FieldExpr_t*) t0)->f_target;
		vader_front_resolver$walk_expr(l0, l3);
	} else if (l1.tag == 1194u) {
		t0 = l1.payload.obj;
		l3 = ((vader_struct_toolchain_ast$IndexExpr_t*) t0)->f_target;
		vader_front_resolver$walk_expr(l0, l3);
		t0 = l1.payload.obj;
		l3 = ((vader_struct_toolchain_ast$IndexExpr_t*) t0)->f_index;
		vader_front_resolver$walk_expr(l0, l3);
	} else if (l1.tag == 1236u) {
		t0 = l1.payload.obj;
		l3 = ((vader_struct_toolchain_ast$UnaryExpr_t*) t0)->f_operand;
		vader_front_resolver$walk_expr(l0, l3);
	} else if (l1.tag == 1149u) {
		t0 = l1.payload.obj;
		l3 = ((vader_struct_toolchain_ast$BinaryExpr_t*) t0)->f_left;
		vader_front_resolver$walk_expr(l0, l3);
		t0 = l1.payload.obj;
		l3 = ((vader_struct_toolchain_ast$BinaryExpr_t*) t0)->f_right;
		vader_front_resolver$walk_expr(l0, l3);
	} else if (l1.tag == 1178u) {
		t0 = l1.payload.obj;
		l3 = ((vader_struct_toolchain_ast$FallbackExpr_t*) t0)->f_left;
		vader_front_resolver$walk_expr(l0, l3);
		vader_front_resolver$push(((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope);
		t0 = l1.payload.obj;
		l3 = ((vader_struct_toolchain_ast$FallbackExpr_t*) t0)->f_binding;
		vader_front_resolver$bind_header_name(l0, l3, (uint8_t) 3);
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$FallbackExpr_t*) t0)->f_clauses;
		l4 = vader_array_length(((vader_array_t*) l2));
		l5 = INT64_C(0);
		while ((l5 < l4)) {
			vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
			VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
			VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
			l6 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l5);
			l3 = ((vader_struct_toolchain_ast$FallbackClause_t*) l6)->f_test;
			vader_front_resolver$walk_opt_expr(l0, l3);
			l7 = ((vader_struct_toolchain_ast$FallbackClause_t*) l6)->f_body;
			l8 = l7;
			if ((l7.tag == 1152u || l7.tag == 1158u || l7.tag == 1218u)) {
				l9 = l8;
				vader_front_resolver$walk_stmt(l0, l9);
			} else {
				if (!((l7.tag == 1146u || l7.tag == 1149u || l7.tag == 1150u || l7.tag == 1151u || l7.tag == 1154u || l7.tag == 1155u || l7.tag == 1156u || l7.tag == 1171u || l7.tag == 1178u || l7.tag == 1179u || l7.tag == 1180u || l7.tag == 1183u || l7.tag == 1185u || l7.tag == 1186u || l7.tag == 1189u || l7.tag == 1194u || l7.tag == 1196u || l7.tag == 1197u || l7.tag == 1200u || l7.tag == 1204u || l7.tag == 1208u || l7.tag == 1214u || l7.tag == 1219u || l7.tag == 1221u || l7.tag == 1226u || l7.tag == 1236u))) {
					vader_unreachable("non-exhaustive match (T3013 should have caught this)");
				}
				l10 = l8;
				vader_front_resolver$walk_expr(l0, l10);
			}
			l5 = (l5 + INT64_C(1));
		}
		vader_front_resolver$pop(((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope);
	} else if (l1.tag == 1189u) {
		l2 = l1.payload.obj;
		vader_front_resolver$walk_if(l0, l2);
	} else if (l1.tag == 1204u) {
		l2 = l1.payload.obj;
		vader_front_resolver$walk_match(l0, l2);
	} else if (l1.tag == 1150u) {
		l2 = l1.payload.obj;
		vader_front_resolver$walk_block(l0, l2);
	} else if (l1.tag == 1200u) {
		l2 = l1.payload.obj;
		vader_front_resolver$walk_lambda(l0, l2);
	} else if (l1.tag == 1226u) {
		l2 = l1.payload.obj;
		vader_front_resolver$walk_struct_lit(l0, l2);
	} else if (l1.tag == 1219u) {
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$SeqLitExpr_t*) t0)->f_elements;
		l4 = vader_array_length(((vader_array_t*) l2));
		l5 = INT64_C(0);
		while ((l5 < l4)) {
			vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
			VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
			VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
			l3 = vader_array_ref_load_box(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l5);
			vader_front_resolver$walk_expr(l0, l3);
			l5 = (l5 + INT64_C(1));
		}
	} else if (l1.tag == 1214u) {
		t0 = l1.payload.obj;
		l3 = ((vader_struct_toolchain_ast$RangeExpr_t*) t0)->f_lower;
		vader_front_resolver$walk_expr(l0, l3);
		t0 = l1.payload.obj;
		l3 = ((vader_struct_toolchain_ast$RangeExpr_t*) t0)->f_upper;
		vader_front_resolver$walk_expr(l0, l3);
	} else if (l1.tag == 1155u) {
		t0 = l1.payload.obj;
		l3 = ((vader_struct_toolchain_ast$CastExpr_t*) t0)->f_value;
		vader_front_resolver$walk_expr(l0, l3);
		t0 = l1.payload.obj;
		l3 = ((vader_struct_toolchain_ast$CastExpr_t*) t0)->f_target;
		vader_front_resolver$walk_expr(l0, l3);
	} else if (l1.tag == 1185u) {
		t0 = l1.payload.obj;
		l3 = ((vader_struct_toolchain_ast$GenericInstExpr_t*) t0)->f_callee;
		vader_front_resolver$walk_expr(l0, l3);
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$GenericInstExpr_t*) t0)->f_type_args;
		l4 = vader_array_length(((vader_array_t*) l2));
		l5 = INT64_C(0);
		while ((l5 < l4)) {
			vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
			VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
			VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
			l3 = vader_array_ref_load_box(_a4_slotarr->buf, vader_array_offset(_a4_slotarr) + (size_t) l5);
			vader_front_resolver$walk_expr(l0, l3);
			l5 = (l5 + INT64_C(1));
		}
	} else if (l1.tag == 1197u) {
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) t0)->f_args;
		l4 = vader_array_length(((vader_array_t*) l2));
		l5 = INT64_C(0);
		while ((l5 < l4)) {
			vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
			VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
			VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
			l3 = vader_array_ref_load_box(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) l5);
			vader_front_resolver$walk_expr(l0, l3);
			l5 = (l5 + INT64_C(1));
		}
	} else if (!(l1.tag == 1171u)) {
		if (l1.tag == 1183u) {
			t0 = l1.payload.obj;
			l2 = ((vader_struct_toolchain_ast$FnTypeExpr_t*) t0)->f_params;
			l4 = vader_array_length(((vader_array_t*) l2));
			l5 = INT64_C(0);
			while ((l5 < l4)) {
				vader_array_t* _a6_slotarr = ((vader_array_t*) l2);
				VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
				VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l5)
				l3 = vader_array_ref_load_box(_a6_slotarr->buf, vader_array_offset(_a6_slotarr) + (size_t) l5);
				vader_front_resolver$walk_expr(l0, l3);
				l5 = (l5 + INT64_C(1));
			}
			t0 = l1.payload.obj;
			l3 = ((vader_struct_toolchain_ast$FnTypeExpr_t*) t0)->f_return_type;
			vader_front_resolver$walk_opt_expr(l0, l3);
		} else if (l1.tag == 1146u) {
			t0 = l1.payload.obj;
			l3 = ((vader_struct_toolchain_ast$ArrayTypeExpr_t*) t0)->f_element;
			vader_front_resolver$walk_expr(l0, l3);
		} else if (!(l1.tag == 1196u)) {
			if (!(l1.tag == 1180u)) {
				if (!(l1.tag == 1151u)) {
					if (!(l1.tag == 1208u)) {
						if (!(l1.tag == 1156u)) {
							if (!(l1.tag == 1221u)) {
								vader_unreachable("non-exhaustive match (T3013 should have caught this)");
							}
							t0 = l1.payload.obj;
							l2 = ((vader_struct_toolchain_ast$StringLitExpr_t*) t0)->f_parts;
							l4 = vader_array_length(((vader_array_t*) l2));
							l5 = INT64_C(0);
							while ((l5 < l4)) {
								vader_array_t* _a7_slotarr = ((vader_array_t*) l2);
								VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
								VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l5)
								l3 = vader_array_ref_load_box(_a7_slotarr->buf, vader_array_offset(_a7_slotarr) + (size_t) l5);
								if (l3.tag == 1222u) {
									t0 = l3.payload.obj;
									l7 = ((vader_struct_toolchain_ast$StringLitInterpolation_t*) t0)->f_expr;
									vader_front_resolver$walk_expr(l0, l7);
								}
								l5 = (l5 + INT64_C(1));
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
	void* t0 = NULL;
	bool t1;
	vader_box_t* gc_roots[2] = { &l6, &l7 };
	void** gc_raw_roots[6] = { &l0, &l1, &l2, &l5, &l8, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_decorators;
	vader_front_resolver$walk_decorators(l0, l2);
	l2 = ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_params;
	l3 = vader_array_length(((vader_array_t*) l2));
	l4 = INT64_C(0);
	while ((l4 < l3)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
		t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l4);
		l5 = ((vader_struct_toolchain_ast$FnParam_t*) t0)->f_decorators;
		vader_front_resolver$walk_decorators(l0, l5);
		l4 = (l4 + INT64_C(1));
	}
	vader_front_resolver$push(((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope);
	l2 = ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_type_params;
	l3 = vader_array_length(((vader_array_t*) l2));
	l4 = INT64_C(0);
	while ((l4 < l3)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
		l5 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l4);
		vader_front_resolver$declare_type_param(l0, l5);
		l4 = (l4 + INT64_C(1));
	}
	l2 = ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_params;
	l3 = vader_array_length(((vader_array_t*) l2));
	l4 = INT64_C(0);
	while ((l4 < l3)) {
		vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
		l5 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l4);
		l6 = ((vader_struct_toolchain_ast$FnParam_t*) l5)->f_ty;
		vader_front_resolver$walk_opt_expr(l0, l6);
		l7 = ((vader_struct_toolchain_ast$FnParam_t*) l5)->f_default_value;
		vader_front_resolver$walk_opt_expr(l0, l7);
		vader_front_resolver$bind_param(l0, l5);
		l4 = (l4 + INT64_C(1));
	}
	l2 = ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_decorators;
	l3 = vader_array_length(((vader_array_t*) l2));
	l4 = INT64_C(0);
	while ((l4 < l3)) {
		vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
		l5 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l4);
		t1 = vader_front_resolver$is_contract_decorator(l5);
		if (t1) {
			l8 = ((vader_struct_toolchain_ast$Decorator_t*) l5)->f_args;
			l9 = vader_array_length(((vader_array_t*) l8));
			l10 = INT64_C(0);
			while ((l10 < l9)) {
				vader_array_t* _a4_slotarr = ((vader_array_t*) l8);
				VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
				VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l10)
				t0 = vader_array_ref_load_obj(_a4_slotarr->buf, vader_array_offset(_a4_slotarr) + (size_t) l10);
				l6 = ((vader_struct_toolchain_ast$CallArg_t*) t0)->f_value;
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
	if (!(l6.tag == 1150u)) {
		vader_unreachable("non-exhaustive match (T3013 should have caught this)");
	}
	l2 = l7.payload.obj;
	vader_front_resolver$walk_member_body(l0, l2);
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
	if (!(l2.tag == 1195u)) {
		if (l2.tag == 1237u) {
			t0 = l3.payload.obj;
			l4 = ((vader_struct_toolchain_ast$WhileFor_t*) t0)->f_cond;
			vader_front_resolver$walk_expr(l0, l4);
		} else {
			if (!(l2.tag == 1193u)) {
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
	if (l2.tag == 1193u) {
		t0 = l3.payload.obj;
		l3 = ((vader_struct_toolchain_ast$InFor_t*) t0)->f_loop_var;
		l4 = l3;
		if (l3.tag == 1207u) {
			t0 = l4.payload.obj;
			l5 = ((vader_struct_toolchain_ast$NamedVar_t*) t0)->f_name;
			t0 = l4.payload.obj;
			l6 = ((vader_struct_toolchain_ast$NamedVar_t*) t0)->f_span;
			l6 = vader_front_resolver$bind_local_checked(l0, (uint8_t) 10, l5, l6);
			l7 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_idents;
			t0 = l4.payload.obj;
			l8 = toolchain_span$Span$std_core$Hash$hash(((vader_struct_toolchain_ast$NamedVar_t*) t0)->f_span);
			std_collections$Map$std_core$IndexSet$set_at__u64__Any(l7, l8, vader_ref_box(l6));
			vader_front_resolver$declare_loop_local(l0, l6);
		} else if (l3.tag == 1167u) {
			vader_array_t* _a0_arr = vader_array_new(224u, 0u, 13u, 1491u);
			l6 = (void*) _a0_arr;
			t0 = l4.payload.obj;
			l4 = ((vader_struct_toolchain_ast$DestructureVar_t*) t0)->f_pattern;
			vader_front_resolver$bind_let_binding(l0, l4, l6);
			l9 = vader_array_length(((vader_array_t*) l6));
			l10 = INT64_C(0);
			while ((l10 < l9)) {
				vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
				VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
				l7 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l10);
				vader_front_resolver$declare_loop_local(l0, l7);
				l10 = (l10 + INT64_C(1));
			}
		} else if (!(l3.tag == 1168u)) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
	} else if (!((l2.tag == 1195u || l2.tag == 1237u))) {
		vader_unreachable("non-exhaustive match (T3013 should have caught this)");
	}
	l9 = vader_array_length(((vader_array_t*) ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_rebind_log));
	t1 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_loop_depth;
	l11 = vader_chk_add(i32, t1, INT32_C(1));
	((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_loop_depth = l11;
	l6 = ((vader_struct_toolchain_ast$ForStmt_t*) l1)->f_body;
	vader_front_resolver$walk_block(l0, l6);
	t1 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_loop_depth;
	l11 = vader_chk_sub(i32, t1, INT32_C(1));
	((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_loop_depth = l11;
	vader_front_resolver$pop(((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope);
	t2 = vader_array_length(((vader_array_t*) ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_rebind_log));
	if ((t2 > l9)) {
		vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 645u);
		l6 = (void*) _a2_arr;
		vader_array_t* _a3_arr = vader_array_new(26u, 0u, 12u, 640u);
		l7 = (void*) _a3_arr;
		vader_array_t* _a4_arr = vader_array_new(29u, 0u, 7u, 645u);
		l12 = (void*) _a4_arr;
		vader_struct_std_collections$Map__i32__bool_t* _a5_obj = (vader_struct_std_collections$Map__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__bool_t));
		vader_obj_header_init(_a5_obj, 919u);
		_a5_obj->f_ekeys = l6;
		_a5_obj->f_evals = l7;
		_a5_obj->f_index = l12;
		_a5_obj->f_mask = INT64_C(0);
		_a5_obj->f_grow_at = INT64_C(0);
		_a5_obj->f_size = INT64_C(0);
		_a5_obj->f_tombs = INT64_C(0);
		t0 = (void*) _a5_obj;
		vader_struct_std_collections$Set__i32_t* _a6_obj = (vader_struct_std_collections$Set__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__i32_t));
		vader_obj_header_init(_a6_obj, 1108u);
		_a6_obj->f_inner = t0;
		l6 = (void*) _a6_obj;
		l10 = vader_array_length(((vader_array_t*) ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_rebind_log));
		while ((l9 < l10)) {
			vader_array_t* _a7_slotarr = ((vader_array_t*) ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_rebind_log);
			VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
			VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l9)
			l11 = ((int32_t*) _a7_slotarr->buf->slots)[vader_array_offset(_a7_slotarr) + (size_t) l9];
			std_collections$add__i32(l6, l11);
			l9 = (l9 + INT64_C(1));
		}
		l7 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_loop_rebinds;
		l8 = toolchain_span$Span$std_core$Hash$hash(((vader_struct_toolchain_ast$ForStmt_t*) l1)->f_span);
		std_collections$Map$std_core$IndexSet$set_at__u64__Any(l7, l8, vader_ref_box(l6));
	}
	t1 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_loop_depth;
	if (t1 == INT32_C(0)) {
		vader_array_clear((vader_array_t*) ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_rebind_log);
		{ vader_gc_top = gc_frame.prev; return; }
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$walk_ident(void* l0, void* l1, bool l2) {
	void* l3 = NULL;
	void* l6 = NULL;
	void* l7 = NULL;
	vader_string_t l4 = 0;
	vader_box_t l5 = vader_box_null();
	uint64_t l8;
	bool t0;
	vader_box_t* gc_roots[1] = { &l5 };
	void** gc_raw_roots[5] = { &l0, &l1, &l3, &l6, &l7 };
	vader_string_t* gc_atom_roots[1] = { &l4 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l3 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope;
	l4 = ((vader_struct_toolchain_ast$IdentExpr_t*) l1)->f_name;
	l5 = vader_front_resolver$lookup(l3, l4);
	if (l5.tag == 0u) {
		l6 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_diags;
		l7 = ((vader_struct_toolchain_ast$IdentExpr_t*) l1)->f_span;
		l4 = ((vader_struct_toolchain_ast$IdentExpr_t*) l1)->f_name;
		l4 = concat_3(1307u, l4, 1307u);
		l7 = toolchain_diagnostics$resolver_error((uint8_t) 5, l7, l4);
		vader_array_push_ref((vader_array_t*) l6, l7);
		{ vader_gc_top = gc_frame.prev; return; }
	}
	l3 = l5.payload.obj;
	l6 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_idents;
	l8 = toolchain_span$Span$std_core$Hash$hash(((vader_struct_toolchain_ast$IdentExpr_t*) l1)->f_span);
	std_collections$Map$std_core$IndexSet$set_at__u64__Any(l6, l8, vader_ref_box(l3));
	if (l2) {
		l6 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_overloaded;
		l4 = ((vader_struct_toolchain_ast$IdentExpr_t*) l1)->f_name;
		t0 = std_collections$Set$std_core$Contains$contains__string(l6, l4);
		if (t0) {
			{ vader_gc_top = gc_frame.prev; return; }
		}
	}
	l4 = ((vader_struct_toolchain_ast$IdentExpr_t*) l1)->f_name;
	l6 = ((vader_struct_toolchain_ast$IdentExpr_t*) l1)->f_span;
	vader_front_resolver$check_wildcard_ambiguity(l0, l4, l6, l3);
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
	if (l2.tag == 1188u) {
		t0 = l4.payload.obj;
		l3 = ((vader_struct_toolchain_ast$IfElseIf_t*) t0)->f_branch;
		vader_front_resolver$walk_if(l0, l3);
	} else {
		if (!(l2.tag == 1187u)) {
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
	vader_box_t l6 = vader_box_null(), l7 = vader_box_null();
	vader_string_t l8 = 0;
	uint64_t l9;
	void* t0 = NULL;
	bool t1;
	vader_box_t* gc_roots[2] = { &l6, &l7 };
	void** gc_raw_roots[5] = { &l0, &l1, &l2, &l5, &t0 };
	vader_string_t* gc_atom_roots[1] = { &l8 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_toolchain_ast$ImplDecl_t*) l1)->f_decorators;
	vader_front_resolver$walk_decorators(l0, l2);
	vader_front_resolver$push(((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope);
	l2 = ((vader_struct_toolchain_ast$ImplDecl_t*) l1)->f_type_params;
	l3 = vader_array_length(((vader_array_t*) l2));
	l4 = INT64_C(0);
	while ((l4 < l3)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
		l5 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l4);
		vader_front_resolver$declare_type_param(l0, l5);
		l4 = (l4 + INT64_C(1));
	}
	l6 = ((vader_struct_toolchain_ast$ImplDecl_t*) l1)->f_for_type;
	vader_front_resolver$auto_bind_for_type_params(l0, l6);
	l6 = ((vader_struct_toolchain_ast$ImplDecl_t*) l1)->f_for_type;
	vader_front_resolver$walk_expr(l0, l6);
	l2 = toolchain_ast$impl_trait_args(l1);
	l3 = vader_array_length(((vader_array_t*) l2));
	l4 = INT64_C(0);
	while ((l4 < l3)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
		l6 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l4);
		vader_front_resolver$walk_expr(l0, l6);
		l4 = (l4 + INT64_C(1));
	}
	l6 = toolchain_ast$impl_trait_head(l1);
	if (l6.tag == 1179u) {
		t0 = l6.payload.obj;
		l7 = ((vader_struct_toolchain_ast$FieldExpr_t*) t0)->f_target;
	} else {
		l7 = l6;
	}
	if (l7.tag == 1186u) {
		l2 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope;
		t0 = l7.payload.obj;
		l8 = ((vader_struct_toolchain_ast$IdentExpr_t*) t0)->f_name;
		l6 = vader_front_resolver$lookup(l2, l8);
		if (!(l6.tag == 0u)) {
			l2 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_idents;
			t0 = l7.payload.obj;
			l9 = toolchain_span$Span$std_core$Hash$hash(((vader_struct_toolchain_ast$IdentExpr_t*) t0)->f_span);
			l5 = l6.payload.obj;
			std_collections$Map$std_core$IndexSet$set_at__u64__Any(l2, l9, vader_ref_box(l5));
			t0 = l7.payload.obj;
			l8 = ((vader_struct_toolchain_ast$IdentExpr_t*) t0)->f_name;
			t0 = l7.payload.obj;
			l2 = ((vader_struct_toolchain_ast$IdentExpr_t*) t0)->f_span;
			l5 = l6.payload.obj;
			vader_front_resolver$check_wildcard_ambiguity(l0, l8, l2, l5);
		}
	}
	l2 = ((vader_struct_toolchain_ast$ImplDecl_t*) l1)->f_members;
	l3 = vader_array_length(((vader_array_t*) l2));
	l4 = INT64_C(0);
	while ((l4 < l3)) {
		vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
		l5 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l4);
		t1 = ((vader_struct_toolchain_ast$FnDecl_t*) l5)->f_materialized;
		if (t1) {
			t1 = ((vader_struct_toolchain_ast$FnDecl_t*) l5)->f_sam_synthetic;
			if (t1) {
				l4 = (l4 + INT64_C(1));
				continue;
			}
		}
		if (((vader_struct_toolchain_ast$FnDecl_t*) l5)->f_inherits.tag == 0u) {
			vader_front_resolver$walk_fn_decl(l0, l5);
			l4 = (l4 + INT64_C(1));
			continue;
		}
		l4 = (l4 + INT64_C(1));
	}
	vader_front_resolver$pop(((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope);
	{ vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$walk_import_cycle(vader_string_t l0, void* l1, void* l2, void* l3, void* l4) {
	vader_box_t l5 = vader_box_null(), l11 = vader_box_null(), l13 = vader_box_null();
	void* l6 = NULL;
	void* l9 = NULL;
	void* l14 = NULL;
	void* l18 = NULL;
	int64_t l7, l8;
	vader_string_t l10 = 0;
	vader_string_t l12 = 0;
	vader_string_t l15 = 0;
	vader_string_t l16 = 0;
	vader_string_t l17 = 0;
	void* t0 = NULL;
	vader_string_t t1 = 0;
	int32_t t2;
	vader_box_t* gc_roots[3] = { &l5, &l11, &l13 };
	void** gc_raw_roots[9] = { &l1, &l2, &l3, &l4, &l6, &l9, &l14, &l18, &t0 };
	vader_string_t* gc_atom_roots[7] = { &l0, &l10, &l12, &l15, &l16, &l17, &t1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 3u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 7u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	std_collections$Map$std_core$IndexSet$set_at__string__i32(l3, l0, INT32_C(1));
	l5 = std_collections$Map$std_core$Index$at__string__Any(l1, l0);
	if (l5.tag == 1796u) {
		t0 = l5.payload.obj;
		l6 = ((vader_struct_vader_front_resolver$CollectedModule_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) t0)->f_collected)->f_import_paths;
		l7 = vader_array_length(((vader_array_t*) l6));
		l8 = INT64_C(0);
		while ((l8 < l7)) {
			vader_array_t* _a0_slotarr = ((vader_array_t*) l6);
			VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
			l9 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l8);
			l10 = ((vader_struct_vader_front_resolver$ImportPath_t*) l9)->f_path;
			l11 = std_collections$Map$std_core$Index$at__string__Any(l2, l10);
			if (l11.tag == 1777u) {
				t0 = l11.payload.obj;
				t1 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) t0)->f_folder;
				if (t1 != l0) {
					t0 = l11.payload.obj;
					l12 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) t0)->f_folder;
					l13 = std_collections$Map$std_core$Index$at__string__i32(l3, l12);
					if (l13.tag == 0u) {
						t0 = l11.payload.obj;
						t1 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) t0)->f_folder;
						vader_front_resolver$walk_import_cycle(t1, l1, l2, l3, l4);
					} else {
						t2 = ((int32_t) l13.payload.i);
						if (t2 == INT32_C(1)) {
							l14 = ((vader_struct_vader_front_resolver$ImportPath_t*) l9)->f_span;
							t0 = l5.payload.obj;
							l15 = ((vader_struct_vader_front_resolver$Module_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) t0)->f_module)->f_display_path;
							l16 = ((vader_struct_vader_front_resolver$ImportPath_t*) l9)->f_path;
							l17 = concat_5(1307u, l15, 1429u, l16, 1656u);
							l18 = toolchain_diagnostics$resolver_error((uint8_t) 4, l14, l17);
							vader_array_push_ref((vader_array_t*) l4, l18);
						}
					}
				}
			}
			l8 = (l8 + INT64_C(1));
		}
	}
	std_collections$Map$std_core$IndexSet$set_at__string__i32(l3, l0, INT32_C(2));
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
	((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_lambda_frame = vader_box_i32(645u, l3);
	VADER_WRITE_BARRIER((vader_struct_vader_front_resolver$ResolveState_t*) l0);
	vader_front_resolver$push(((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope);
	l4 = ((vader_struct_toolchain_ast$LambdaExpr_t*) l1)->f_params;
	l5 = vader_array_length(((vader_array_t*) l4));
	l6 = INT64_C(0);
	while ((l6 < l5)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
		l7 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l6);
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
	vader_array_t* _a0_arr = vader_array_new(224u, 0u, 13u, 1491u);
	l3 = (void*) _a0_arr;
	l2 = ((vader_struct_toolchain_ast$LetStmt_t*) l1)->f_binding;
	vader_front_resolver$bind_let_binding(l0, l2, l3);
	l2 = ((vader_struct_toolchain_ast$LetStmt_t*) l1)->f_value;
	vader_front_resolver$note_fallback_name(l0, l2, l3);
	t0 = ((vader_struct_toolchain_ast$LetStmt_t*) l1)->f_mutable;
	if (t0) {
		t1 = vader_array_length(((vader_array_t*) l3));
		if ((t1 > INT64_C(0))) {
			l6 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_mutable_decls;
			l7 = vader_front_resolver$binding_span(((vader_struct_toolchain_ast$LetStmt_t*) l1)->f_binding);
			vader_struct_vader_front_resolver$MutableDecl_t* _a1_obj = (vader_struct_vader_front_resolver$MutableDecl_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$MutableDecl_t));
			vader_obj_header_init(_a1_obj, 1801u);
			_a1_obj->f_syms = l3;
			_a1_obj->f_span = l7;
			l9 = (void*) _a1_obj;
			vader_array_push_ref((vader_array_t*) l6, l9);
		}
	} else {
		l4 = vader_array_length(((vader_array_t*) l3));
		l5 = INT64_C(0);
		while ((l5 < l4)) {
			vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
			VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
			l6 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l5);
			l7 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_immutable_locals;
			l8 = ((vader_struct_vader_core_symbol$Symbol_t*) l6)->f_id;
			std_collections$Map$std_core$IndexSet$set_at__i32__vader_front_resolver_ConstLocal(l7, l8, (uint8_t) 0);
			l5 = (l5 + INT64_C(1));
		}
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$walk_match(void* l0, void* l1) {
	vader_box_t l2 = vader_box_null(), l7 = vader_box_null(), l8 = vader_box_null();
	void* l3 = NULL;
	void* l6 = NULL;
	int64_t l4, l5;
	vader_box_t* gc_roots[3] = { &l2, &l7, &l8 };
	void** gc_raw_roots[4] = { &l0, &l1, &l3, &l6 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_toolchain_ast$MatchExpr_t*) l1)->f_scrutinee;
	vader_front_resolver$walk_expr(l0, l2);
	vader_front_resolver$push(((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope);
	l2 = ((vader_struct_toolchain_ast$MatchExpr_t*) l1)->f_binding;
	vader_front_resolver$bind_header_name(l0, l2, (uint8_t) 2);
	l3 = ((vader_struct_toolchain_ast$MatchExpr_t*) l1)->f_arms;
	l4 = vader_array_length(((vader_array_t*) l3));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
		l6 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
		vader_front_resolver$push(((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope);
		l2 = ((vader_struct_toolchain_ast$MatchArm_t*) l6)->f_pattern;
		vader_front_resolver$bind_pattern(l0, l2);
		l7 = ((vader_struct_toolchain_ast$MatchArm_t*) l6)->f_guard;
		vader_front_resolver$walk_opt_expr(l0, l7);
		l8 = ((vader_struct_toolchain_ast$MatchArm_t*) l6)->f_body;
		vader_front_resolver$walk_expr(l0, l8);
		vader_front_resolver$pop(((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope);
		l5 = (l5 + INT64_C(1));
	}
	vader_front_resolver$pop(((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope);
	{ vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$walk_member_body(void* l0, void* l1) {
	void* l2 = NULL;
	vader_box_t l3 = vader_box_null();
	vader_box_t* gc_roots[1] = { &l3 };
	void** gc_raw_roots[3] = { &l0, &l1, &l2 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l3 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_trait_self;
	if (l3.tag == 0u) {
		vader_front_resolver$walk_body(l0, l1);
		{ vader_gc_top = gc_frame.prev; return; }
	}
	l2 = l3.payload.obj;
	vader_front_resolver$push(((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope);
	vader_front_resolver$bind(((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope, 990u, l2);
	vader_front_resolver$walk_body(l0, l1);
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
	if (l1.tag == 1201u) {
		l2 = l1.payload.obj;
		vader_front_resolver$walk_let(l0, l2);
		{ vader_gc_top = gc_frame.prev; return; }
	}
	if (l1.tag == 1148u) {
		t0 = l1.payload.obj;
		l3 = ((vader_struct_toolchain_ast$AssignStmt_t*) t0)->f_target;
		vader_front_resolver$walk_expr(l0, l3);
		t0 = l1.payload.obj;
		l3 = ((vader_struct_toolchain_ast$AssignStmt_t*) t0)->f_value;
		vader_front_resolver$walk_expr(l0, l3);
		t0 = l1.payload.obj;
		l3 = ((vader_struct_toolchain_ast$AssignStmt_t*) t0)->f_target;
		vader_front_resolver$note_rebind(l0, l3);
	} else if (l1.tag == 1165u) {
		t0 = l1.payload.obj;
		l2 = toolchain_ast$assign_places(t0);
		l4 = vader_array_length(((vader_array_t*) l2));
		l5 = INT64_C(0);
		while ((l5 < l4)) {
			vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
			VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
			VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
			l3 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
			vader_front_resolver$walk_expr(l0, l3);
			vader_front_resolver$note_rebind(l0, l3);
			l5 = (l5 + INT64_C(1));
		}
		t0 = l1.payload.obj;
		l3 = ((vader_struct_toolchain_ast$DestructureAssignStmt_t*) t0)->f_value;
		vader_front_resolver$walk_expr(l0, l3);
	} else if (l1.tag == 1175u) {
		t0 = l1.payload.obj;
		l3 = ((vader_struct_toolchain_ast$ExprStmt_t*) t0)->f_expr;
		vader_front_resolver$walk_expr(l0, l3);
	} else if (l1.tag == 1218u) {
		t0 = l1.payload.obj;
		l3 = ((vader_struct_toolchain_ast$ReturnStmt_t*) t0)->f_value;
		vader_front_resolver$walk_opt_expr(l0, l3);
	} else if (l1.tag == 1242u) {
		t0 = l1.payload.obj;
		l3 = ((vader_struct_toolchain_ast$YieldStmt_t*) t0)->f_value;
		vader_front_resolver$walk_expr(l0, l3);
	} else if (l1.tag == 1184u) {
		l2 = l1.payload.obj;
		vader_front_resolver$walk_for(l0, l2);
	} else if (!(l1.tag == 1152u)) {
		if (!(l1.tag == 1158u)) {
			if (!(l1.tag == 1163u)) {
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
	void* l4 = NULL;
	void* l8 = NULL;
	vader_box_t l3 = vader_box_null(), l9 = vader_box_null();
	vader_string_t l5 = 0;
	int64_t l6, l7;
	vader_string_t t0 = 0;
	vader_box_t t1 = vader_box_null();
	bool t2;
	void* t3 = NULL;
	vader_box_t* gc_roots[3] = { &l3, &l9, &t1 };
	void** gc_raw_roots[6] = { &l0, &l1, &l2, &l4, &l8, &t3 };
	vader_string_t* gc_atom_roots[2] = { &l5, &t0 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 3u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_toolchain_ast$StructDecl_t*) l1)->f_decorators;
	vader_front_resolver$walk_decorators(l0, l2);
	l3 = ((vader_struct_toolchain_ast$StructDecl_t*) l1)->f_decorator_args;
	if (!(l3.tag == 0u)) {
		t0 = ((vader_struct_toolchain_ast$StructDecl_t*) l1)->f_name;
		t1 = toolchain_ast$compiler_decorator_named(t0);
		if (!(t1.tag == 0u)) {
			t2 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_in_core;
			if (!(t2)) {
				l2 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_diags;
				l4 = ((vader_struct_toolchain_ast$StructDecl_t*) l1)->f_name_span;
				l5 = ((vader_struct_toolchain_ast$StructDecl_t*) l1)->f_name;
				l5 = concat_3(1708u, l5, 1307u);
				l4 = toolchain_diagnostics$resolver_error((uint8_t) 34, l4, l5);
				vader_array_push_ref((vader_array_t*) l2, l4);
			}
		}
		l2 = l3.payload.obj;
		l6 = vader_array_length(((vader_array_t*) l2));
		l7 = INT64_C(0);
		while ((l7 < l6)) {
			vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
			VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
			VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l7)
			t3 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l7);
			l3 = ((vader_struct_toolchain_ast$CallArg_t*) t3)->f_value;
			vader_front_resolver$walk_expr(l0, l3);
			l7 = (l7 + INT64_C(1));
		}
	}
	vader_front_resolver$push(((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope);
	l2 = ((vader_struct_toolchain_ast$StructDecl_t*) l1)->f_type_params;
	l6 = vader_array_length(((vader_array_t*) l2));
	l7 = INT64_C(0);
	while ((l7 < l6)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l7)
		l4 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l7);
		vader_front_resolver$declare_type_param(l0, l4);
		l7 = (l7 + INT64_C(1));
	}
	l2 = ((vader_struct_toolchain_ast$StructDecl_t*) l1)->f_fields;
	l6 = vader_array_length(((vader_array_t*) l2));
	l7 = INT64_C(0);
	while ((l7 < l6)) {
		vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l7)
		l4 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l7);
		l8 = ((vader_struct_toolchain_ast$StructField_t*) l4)->f_decorators;
		vader_front_resolver$walk_decorators(l0, l8);
		l3 = ((vader_struct_toolchain_ast$StructField_t*) l4)->f_ty;
		vader_front_resolver$walk_expr(l0, l3);
		l9 = ((vader_struct_toolchain_ast$StructField_t*) l4)->f_default;
		vader_front_resolver$walk_opt_expr(l0, l9);
		l7 = (l7 + INT64_C(1));
	}
	l2 = ((vader_struct_toolchain_ast$StructDecl_t*) l1)->f_spreads;
	l6 = vader_array_length(((vader_array_t*) l2));
	l7 = INT64_C(0);
	while ((l7 < l6)) {
		vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
		t3 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l7);
		l3 = ((vader_struct_toolchain_ast$StructSpread_t*) t3)->f_base;
		vader_front_resolver$walk_expr(l0, l3);
		l7 = (l7 + INT64_C(1));
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
	l3 = vader_array_length(((vader_array_t*) l2));
	l4 = INT64_C(0);
	while ((l4 < l3)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
		l5 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l4);
		if (l5.tag == 1227u) {
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
	l3 = vader_array_length(((vader_array_t*) l2));
	l4 = INT64_C(0);
	while ((l4 < l3)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
		l5 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l4);
		vader_front_resolver$declare_type_param(l0, l5);
		l4 = (l4 + INT64_C(1));
	}
	l6 = ((vader_struct_toolchain_ast$TraitDecl_t*) l1)->f_requires;
	vader_front_resolver$walk_opt_expr(l0, l6);
	l6 = vader_front_resolver$union_in_bound(((vader_struct_toolchain_ast$TraitDecl_t*) l1)->f_requires);
	if (!(l6.tag == 0u)) {
		l7 = ((vader_struct_toolchain_ast$TraitDecl_t*) l1)->f_name;
		l7 = concat_3(1307u, l7, 1311u);
		l2 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_diags;
		t0 = l6.payload.obj;
		l5 = ((vader_struct_toolchain_ast$BinaryExpr_t*) t0)->f_span;
		l5 = toolchain_diagnostics$resolver_error((uint8_t) 33, l5, l7);
		vader_array_push_ref((vader_array_t*) l2, l5);
	}
	l6 = vader_front_resolver$declare_trait_self(l0, l1);
	((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_trait_self = l6;
	VADER_WRITE_BARRIER((vader_struct_vader_front_resolver$ResolveState_t*) l0);
	l2 = ((vader_struct_toolchain_ast$TraitDecl_t*) l1)->f_members;
	l3 = vader_array_length(((vader_array_t*) l2));
	l4 = INT64_C(0);
	while ((l4 < l3)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
		l5 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l4);
		vader_front_resolver$walk_fn_decl(l0, l5);
		l4 = (l4 + INT64_C(1));
	}
	((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_trait_self = vader_box_obj(0u, NULL);
	VADER_WRITE_BARRIER((vader_struct_vader_front_resolver$ResolveState_t*) l0);
	vader_front_resolver$pop(((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_scope);
	{ vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_resolver$warn_block_after_else_value(void* l0, vader_box_t l1, vader_box_t l2) {
	void* l3 = NULL;
	void* l5 = NULL;
	vader_box_t l4 = vader_box_null();
	int64_t l6;
	int32_t l7, l8;
	int64_t t0;
	void* t1 = NULL;
	vader_box_t* gc_roots[3] = { &l1, &l2, &l4 };
	void** gc_raw_roots[4] = { &l0, &l3, &l5, &t1 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	if (!(l2.tag == 1150u)) {
		{ vader_gc_top = gc_frame.prev; return; }
	}
	l4 = vader_front_resolver$fallback_of_stmt(l1);
	if (l4.tag == 0u) {
		{ vader_gc_top = gc_frame.prev; return; }
	}
	l3 = l4.payload.obj;
	l5 = ((vader_struct_toolchain_ast$FallbackExpr_t*) l3)->f_clauses;
	t0 = vader_array_length(((vader_array_t*) ((vader_struct_toolchain_ast$FallbackExpr_t*) l3)->f_clauses));
	l6 = vader_chk_sub(i64, t0, INT64_C(1));
	vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
	VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
	VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
	l5 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l6);
	if (((vader_struct_toolchain_ast$FallbackClause_t*) l5)->f_test.tag == 0u) {
		if (((vader_struct_toolchain_ast$FallbackClause_t*) l5)->f_body.tag == 1150u) {
			{ vader_gc_top = gc_frame.prev; return; }
		}
		if ((((vader_struct_toolchain_ast$FallbackClause_t*) l5)->f_body.tag == 1146u || ((vader_struct_toolchain_ast$FallbackClause_t*) l5)->f_body.tag == 1149u || ((vader_struct_toolchain_ast$FallbackClause_t*) l5)->f_body.tag == 1150u || ((vader_struct_toolchain_ast$FallbackClause_t*) l5)->f_body.tag == 1151u || ((vader_struct_toolchain_ast$FallbackClause_t*) l5)->f_body.tag == 1154u || ((vader_struct_toolchain_ast$FallbackClause_t*) l5)->f_body.tag == 1155u || ((vader_struct_toolchain_ast$FallbackClause_t*) l5)->f_body.tag == 1156u || ((vader_struct_toolchain_ast$FallbackClause_t*) l5)->f_body.tag == 1171u || ((vader_struct_toolchain_ast$FallbackClause_t*) l5)->f_body.tag == 1178u || ((vader_struct_toolchain_ast$FallbackClause_t*) l5)->f_body.tag == 1179u || ((vader_struct_toolchain_ast$FallbackClause_t*) l5)->f_body.tag == 1180u || ((vader_struct_toolchain_ast$FallbackClause_t*) l5)->f_body.tag == 1183u || ((vader_struct_toolchain_ast$FallbackClause_t*) l5)->f_body.tag == 1185u || ((vader_struct_toolchain_ast$FallbackClause_t*) l5)->f_body.tag == 1186u || ((vader_struct_toolchain_ast$FallbackClause_t*) l5)->f_body.tag == 1189u || ((vader_struct_toolchain_ast$FallbackClause_t*) l5)->f_body.tag == 1194u || ((vader_struct_toolchain_ast$FallbackClause_t*) l5)->f_body.tag == 1196u || ((vader_struct_toolchain_ast$FallbackClause_t*) l5)->f_body.tag == 1197u || ((vader_struct_toolchain_ast$FallbackClause_t*) l5)->f_body.tag == 1200u || ((vader_struct_toolchain_ast$FallbackClause_t*) l5)->f_body.tag == 1204u || ((vader_struct_toolchain_ast$FallbackClause_t*) l5)->f_body.tag == 1208u || ((vader_struct_toolchain_ast$FallbackClause_t*) l5)->f_body.tag == 1214u || ((vader_struct_toolchain_ast$FallbackClause_t*) l5)->f_body.tag == 1219u || ((vader_struct_toolchain_ast$FallbackClause_t*) l5)->f_body.tag == 1221u || ((vader_struct_toolchain_ast$FallbackClause_t*) l5)->f_body.tag == 1226u || ((vader_struct_toolchain_ast$FallbackClause_t*) l5)->f_body.tag == 1236u)) {
			t1 = l2.payload.obj;
			l7 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) ((vader_struct_toolchain_ast$BlockExpr_t*) t1)->f_span)->f_start)->f_line;
			l8 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) ((vader_struct_toolchain_ast$FallbackExpr_t*) l3)->f_span)->f_end)->f_line;
			if (!(l7 != l8)) {
				l3 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_diags;
				t1 = l2.payload.obj;
				l5 = ((vader_struct_toolchain_ast$BlockExpr_t*) t1)->f_span;
				l5 = toolchain_diagnostics$warning((uint8_t) 16, l5, 3383u);
				vader_array_push_ref((vader_array_t*) l3, l5);
				{ vader_gc_top = gc_frame.prev; return; }
			}
			{ vader_gc_top = gc_frame.prev; return; }
		}
		{ vader_gc_top = gc_frame.prev; return; }
	}
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
	if (l1 == 1242u) {
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
		l6 = concat_3(1307u, l1, 1307u);
		l7 = toolchain_diagnostics$warning((uint8_t) 6, l2, l6);
		vader_array_push_ref((vader_array_t*) l5, l7);
		{ vader_gc_top = gc_frame.prev; return; }
	}
	l5 = ((vader_struct_vader_front_resolver$ResolveState_t*) l0)->f_diags;
	l6 = concat_3(1307u, l1, 1307u);
	l7 = toolchain_diagnostics$warning((uint8_t) 5, l2, l6);
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
	int64_t l7, l8, l15, l16;
	vader_string_t l9 = 0;
	vader_string_t l18 = 0;
	vader_string_t l19 = 0;
	vader_box_t l10 = vader_box_null(), l11 = vader_box_null();
	int64_t t0;
	vader_box_t t1 = vader_box_null();
	vader_string_t t2 = 0;
	bool t3;
	vader_box_t* gc_roots[3] = { &l10, &l11, &t1 };
	void** gc_raw_roots[13] = {
		&l0, &l1, &l2, &l3, &l4, &l5, &l6, &l12, &l13, &l14, &l17, &l20, &l21,
	};
	vader_string_t* gc_atom_roots[4] = { &l9, &l18, &l19, &t2 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 3u, 13u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
	l4 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(3u, 0u, 13u, 28u);
	l5 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 645u);
	l6 = (void*) _a2_arr;
	vader_struct_std_collections$Map__string__string___t* _a3_obj = (vader_struct_std_collections$Map__string__string___t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__string___t));
	vader_obj_header_init(_a3_obj, 1029u);
	_a3_obj->f_ekeys = l4;
	_a3_obj->f_evals = l5;
	_a3_obj->f_index = l6;
	_a3_obj->f_mask = INT64_C(0);
	_a3_obj->f_grow_at = INT64_C(0);
	_a3_obj->f_size = INT64_C(0);
	_a3_obj->f_tombs = INT64_C(0);
	l4 = (void*) _a3_obj;
	t0 = vader_array_length(((vader_array_t*) l1));
	if ((t0 < INT64_C(2))) {
		{ void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l5 = l1;
	l7 = vader_array_length(((vader_array_t*) l5));
	l8 = INT64_C(0);
	while ((l8 < l7)) {
		vader_array_t* _a4_slotarr = ((vader_array_t*) l5);
		VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l8)
		t1 = vader_array_box_slots(_a4_slotarr->buf)[vader_array_offset(_a4_slotarr) + (size_t) l8];
		l9 = t1.payload.s;
		l10 = std_collections$Map$std_core$Index$at__string__Any(l0, l9);
		if (l10.tag == 0u) {
			l8 = (l8 + INT64_C(1));
			continue;
		}
		l6 = l10.payload.obj;
		l11 = std_collections$Map$std_core$Index$at__string__string__(l2, l9);
		l12 = ((vader_struct_vader_front_resolver$CollectedModule_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l6)->f_collected)->f_symbols;
		l13 = ((vader_struct_std_collections$Map__string__vader_core_symbol_Symbol_t*) l12)->f_ekeys;
		l14 = ((vader_struct_std_collections$Map__string__vader_core_symbol_Symbol_t*) l12)->f_evals;
		l15 = INT64_C(0);
		l16 = ((vader_struct_std_collections$Map__string__vader_core_symbol_Symbol_t*) l12)->f_size;
		while ((l15 < l16)) {
			vader_array_t* _a5_slotarr = ((vader_array_t*) l13);
			VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
			VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l15)
			t1 = vader_array_box_slots(_a5_slotarr->buf)[vader_array_offset(_a5_slotarr) + (size_t) l15];
			t2 = t1.payload.s;
			vader_array_t* _a6_slotarr = ((vader_array_t*) l14);
			VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
			VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l15)
			l17 = vader_array_ref_load_obj(_a6_slotarr->buf, vader_array_offset(_a6_slotarr) + (size_t) l15);
			t3 = vader_front_resolver$wildcard_exposes(l17, l11);
			if (t3) {
				l18 = ((vader_struct_vader_core_symbol$Symbol_t*) l17)->f_name;
				t1 = std_collections$Map$std_core$Index$at__string__Any(l3, l18);
				if (t1.tag == 0u) {
					l19 = ((vader_struct_vader_core_symbol$Symbol_t*) l17)->f_name;
					l20 = (void*) &vader_fn_static___lambda_vader_front_resolver_28;
					l21 = std_collections$get_or_put_with__string__string__(l4, l19, l20);
					t3 = std_core$$array$Contains$contains__string(l21, l9);
					if (!(t3)) {
						vader_array_push_scalar((vader_array_t*) l21, vader_box_string(642u, l9));
					}
				}
			}
			l15 = (l15 + INT64_C(1));
		}
		l8 = (l8 + INT64_C(1));
	}
	vader_array_t* _a7_arr = vader_array_new(28u, 0u, 0u, 642u);
	l5 = (void*) _a7_arr;
	vader_array_t* _a8_arr = vader_array_new(3u, 0u, 13u, 28u);
	l6 = (void*) _a8_arr;
	vader_array_t* _a9_arr = vader_array_new(29u, 0u, 7u, 645u);
	l12 = (void*) _a9_arr;
	vader_struct_std_collections$Map__string__string___t* _a10_obj = (vader_struct_std_collections$Map__string__string___t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__string___t));
	vader_obj_header_init(_a10_obj, 1029u);
	_a10_obj->f_ekeys = l5;
	_a10_obj->f_evals = l6;
	_a10_obj->f_index = l12;
	_a10_obj->f_mask = INT64_C(0);
	_a10_obj->f_grow_at = INT64_C(0);
	_a10_obj->f_size = INT64_C(0);
	_a10_obj->f_tombs = INT64_C(0);
	l5 = (void*) _a10_obj;
	l6 = ((vader_struct_std_collections$Map__string__string___t*) l4)->f_ekeys;
	l12 = ((vader_struct_std_collections$Map__string__string___t*) l4)->f_evals;
	l7 = INT64_C(0);
	l8 = ((vader_struct_std_collections$Map__string__string___t*) l4)->f_size;
	while ((l7 < l8)) {
		vader_array_t* _a11_slotarr = ((vader_array_t*) l6);
		VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l7)
		t1 = vader_array_box_slots(_a11_slotarr->buf)[vader_array_offset(_a11_slotarr) + (size_t) l7];
		l9 = t1.payload.s;
		vader_array_t* _a12_slotarr = ((vader_array_t*) l12);
		VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l7)
		l4 = vader_array_ref_load_obj(_a12_slotarr->buf, vader_array_offset(_a12_slotarr) + (size_t) l7);
		l18 = l9;
		l13 = l4;
		t0 = vader_array_length(((vader_array_t*) l13));
		if ((t0 >= INT64_C(2))) {
			std_collections$Map$std_core$IndexSet$set_at__string__string__(l5, l18, l13);
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

bool vader_front_resolver$wildcard_exposes(void* l0, vader_box_t l1) {
	void* l2;
	vader_string_t l3;
	bool t0;
	t0 = vader_front_resolver$wildcard_exposable(((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_kind);
	if (t0) {
		if (((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_visibility != INT32_C(0)) {
			return false;
		}
		t0 = vader_core_symbol$is_compiler_decorator_symbol(l0);
		if (t0) {
			return false;
		}
		if (!(l1.tag == 0u)) {
			l2 = l1.payload.obj;
			l3 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_name;
			t0 = std_core$$array$Contains$contains__string(l2, l3);
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
	vader_array_t* _a0_arr = vader_array_new(29u, 0u, 7u, 645u);
	l1 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(35u, 0u, 0u, 653u);
	l2 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 645u);
	l3 = (void*) _a2_arr;
	vader_struct_std_collections$Map__i32__Any_t* _a3_obj = (vader_struct_std_collections$Map__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__Any_t));
	vader_obj_header_init(_a3_obj, 916u);
	_a3_obj->f_ekeys = l1;
	_a3_obj->f_evals = l2;
	_a3_obj->f_index = l3;
	_a3_obj->f_mask = INT64_C(0);
	_a3_obj->f_grow_at = INT64_C(0);
	_a3_obj->f_size = INT64_C(0);
	_a3_obj->f_tombs = INT64_C(0);
	l1 = (void*) _a3_obj;
	vader_array_t* _a4_arr = vader_array_new(29u, 0u, 7u, 645u);
	l2 = (void*) _a4_arr;
	vader_array_t* _a5_arr = vader_array_new(28u, 0u, 0u, 642u);
	l3 = (void*) _a5_arr;
	vader_array_t* _a6_arr = vader_array_new(29u, 0u, 7u, 645u);
	l4 = (void*) _a6_arr;
	vader_struct_std_collections$Map__i32__string_t* _a7_obj = (vader_struct_std_collections$Map__i32__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__string_t));
	vader_obj_header_init(_a7_obj, 932u);
	_a7_obj->f_ekeys = l2;
	_a7_obj->f_evals = l3;
	_a7_obj->f_index = l4;
	_a7_obj->f_mask = INT64_C(0);
	_a7_obj->f_grow_at = INT64_C(0);
	_a7_obj->f_size = INT64_C(0);
	_a7_obj->f_tombs = INT64_C(0);
	l2 = (void*) _a7_obj;
	vader_struct_vader_front_resolver$ImportTargetTable_t* _a8_obj = (vader_struct_vader_front_resolver$ImportTargetTable_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$ImportTargetTable_t));
	vader_obj_header_init(_a8_obj, 1788u);
	_a8_obj->f_symbol_targets = l1;
	_a8_obj->f_namespace_targets = l2;
	l1 = (void*) _a8_obj;
	vader_array_t* _a9_arr = vader_array_new(28u, 0u, 0u, 642u);
	l2 = (void*) _a9_arr;
	vader_array_t* _a10_arr = vader_array_new(28u, 0u, 0u, 642u);
	l3 = (void*) _a10_arr;
	vader_array_t* _a11_arr = vader_array_new(29u, 0u, 7u, 645u);
	l4 = (void*) _a11_arr;
	vader_struct_std_collections$Map__string__string_t* _a12_obj = (vader_struct_std_collections$Map__string__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__string_t));
	vader_obj_header_init(_a12_obj, 1028u);
	_a12_obj->f_ekeys = l2;
	_a12_obj->f_evals = l3;
	_a12_obj->f_index = l4;
	_a12_obj->f_mask = INT64_C(0);
	_a12_obj->f_grow_at = INT64_C(0);
	_a12_obj->f_size = INT64_C(0);
	_a12_obj->f_tombs = INT64_C(0);
	l2 = (void*) _a12_obj;
	l3 = ((vader_struct_vader_front_resolver$LoadedProject_t*) l0)->f_modules;
	l4 = ((vader_struct_std_collections$Map__string__vader_front_resolver_LoadedModule_t*) l3)->f_ekeys;
	l5 = ((vader_struct_std_collections$Map__string__vader_front_resolver_LoadedModule_t*) l3)->f_evals;
	l6 = INT64_C(0);
	l7 = ((vader_struct_std_collections$Map__string__vader_front_resolver_LoadedModule_t*) l3)->f_size;
	while ((l6 < l7)) {
		vader_array_t* _a13_slotarr = ((vader_array_t*) l4);
		VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l6)
		t0 = vader_array_box_slots(_a13_slotarr->buf)[vader_array_offset(_a13_slotarr) + (size_t) l6];
		t1 = t0.payload.s;
		vader_array_t* _a14_slotarr = ((vader_array_t*) l5);
		VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l6)
		l3 = vader_array_ref_load_obj(_a14_slotarr->buf, vader_array_offset(_a14_slotarr) + (size_t) l6);
		l8 = ((vader_struct_vader_front_resolver$Module_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l3)->f_module)->f_module_name;
		l9 = ((vader_struct_vader_front_resolver$Module_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l3)->f_module)->f_id;
		std_collections$Map$std_core$IndexSet$set_at__string__string(l2, l8, l9);
		l6 = (l6 + INT64_C(1));
	}
	l3 = ((vader_struct_vader_front_resolver$LoadedProject_t*) l0)->f_modules;
	l4 = ((vader_struct_std_collections$Map__string__vader_front_resolver_LoadedModule_t*) l3)->f_ekeys;
	l5 = ((vader_struct_std_collections$Map__string__vader_front_resolver_LoadedModule_t*) l3)->f_evals;
	l6 = INT64_C(0);
	l7 = ((vader_struct_std_collections$Map__string__vader_front_resolver_LoadedModule_t*) l3)->f_size;
	while ((l6 < l7)) {
		vader_array_t* _a15_slotarr = ((vader_array_t*) l4);
		VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l6)
		t0 = vader_array_box_slots(_a15_slotarr->buf)[vader_array_offset(_a15_slotarr) + (size_t) l6];
		t1 = t0.payload.s;
		vader_array_t* _a16_slotarr = ((vader_array_t*) l5);
		VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l6)
		t2 = vader_array_ref_load_obj(_a16_slotarr->buf, vader_array_offset(_a16_slotarr) + (size_t) l6);
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
	void* l15 = NULL;
	void* l19 = NULL;
	void* l22 = NULL;
	void* l23 = NULL;
	void* l27 = NULL;
	void* l28 = NULL;
	void* l29 = NULL;
	void* l32 = NULL;
	void* l33 = NULL;
	void* l34 = NULL;
	int64_t l7, l8;
	int32_t l9, l10;
	vader_string_t l12 = 0;
	vader_string_t l13 = 0;
	vader_string_t l20 = 0;
	vader_string_t l24 = 0;
	vader_string_t l25 = 0;
	vader_string_t l26 = 0;
	vader_string_t l30 = 0;
	vader_string_t l31 = 0;
	vader_box_t l14 = vader_box_null(), l16 = vader_box_null(), l17 = vader_box_null(), l18 = vader_box_null(), l21 = vader_box_null();
	void* t0 = NULL;
	vader_box_t* gc_roots[5] = { &l14, &l16, &l17, &l18, &l21 };
	void** gc_raw_roots[19] = {
		&l0, &l1, &l2, &l3, &l4, &l5, &l6, &l11, &l15, &l19, &l22, &l23, &l27, &l28, &l29, &l32,
		&l33, &l34, &t0,
	};
	vader_string_t* gc_atom_roots[8] = { &l12, &l13, &l20, &l24, &l25, &l26, &l30, &l31 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 5u, 19u, gc_roots, gc_raw_roots, 0u, NULL, 8u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l4 = ((vader_struct_vader_front_resolver$CollectedModule_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l0)->f_collected)->f_imports;
	l5 = ((vader_struct_std_collections$Map__i32__vader_front_resolver_ImportInfo_t*) l4)->f_ekeys;
	l6 = ((vader_struct_std_collections$Map__i32__vader_front_resolver_ImportInfo_t*) l4)->f_evals;
	l7 = INT64_C(0);
	l8 = ((vader_struct_std_collections$Map__i32__vader_front_resolver_ImportInfo_t*) l4)->f_size;
	while ((l7 < l8)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l7)
		l9 = ((int32_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l7];
		vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l7)
		l4 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l7);
		l10 = l9;
		l11 = l4;
		l13 = ((vader_struct_vader_front_resolver$ImportInfo_t*) l11)->f_path;
		l14 = std_collections$Map$std_core$Index$at__string__string(l1, l13);
		if (!(l14.tag == 0u)) {
			l12 = l14.payload.s;
			l16 = std_collections$Map$std_core$Index$at__string__Any(((vader_struct_vader_front_resolver$LoadedProject_t*) l2)->f_modules, l12);
			if (!(l16.tag == 0u)) {
				l15 = l16.payload.obj;
				l17 = ((vader_struct_vader_front_resolver$ImportInfo_t*) l11)->f_imported_name;
				l18 = l17;
				if (l17.tag == 0u) {
					std_collections$Map$std_core$IndexSet$set_at__i32__string(((vader_struct_vader_front_resolver$ImportTargetTable_t*) l3)->f_namespace_targets, l10, l12);
				} else {
					if (!(l17.tag == 642u)) {
						vader_unreachable("non-exhaustive match (T3013 should have caught this)");
					}
					l19 = ((vader_struct_vader_front_resolver$CollectedModule_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l15)->f_collected)->f_symbols;
					l20 = l18.payload.s;
					l21 = std_collections$Map$std_core$Index$at__string__Any(l19, l20);
					if (l21.tag == 0u) {
						l22 = ((vader_struct_vader_front_resolver$LoadedProject_t*) l2)->f_diags;
						l23 = ((vader_struct_vader_front_resolver$ImportInfo_t*) l11)->f_binding_span;
						l24 = l18.payload.s;
						l25 = ((vader_struct_vader_front_resolver$ImportInfo_t*) l11)->f_path;
						l26 = concat_5(1307u, l24, 1381u, l25, 1307u);
						l27 = toolchain_diagnostics$resolver_error((uint8_t) 2, l23, l26);
						vader_array_push_ref((vader_array_t*) l22, l27);
					} else {
						if (!(l21.tag == 1491u)) {
							vader_unreachable("non-exhaustive match (T3013 should have caught this)");
						}
						t0 = l21.payload.obj;
						if (((vader_struct_vader_core_symbol$Symbol_t*) t0)->f_visibility == INT32_C(1)) {
							l28 = ((vader_struct_vader_front_resolver$LoadedProject_t*) l2)->f_diags;
							l29 = ((vader_struct_vader_front_resolver$ImportInfo_t*) l11)->f_binding_span;
							l30 = l18.payload.s;
							l31 = concat_3(1307u, l30, 1307u);
							l32 = toolchain_diagnostics$resolver_error((uint8_t) 7, l29, l31);
							vader_array_push_ref((vader_array_t*) l28, l32);
						} else {
							l33 = ((vader_struct_vader_front_resolver$ImportTargetTable_t*) l3)->f_symbol_targets;
							t0 = l21.payload.obj;
							vader_struct_vader_front_resolver$SymbolTarget_t* _a2_obj = (vader_struct_vader_front_resolver$SymbolTarget_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$SymbolTarget_t));
							vader_obj_header_init(_a2_obj, 1816u);
							_a2_obj->f_symbol = t0;
							_a2_obj->f_module_id = l12;
							l34 = (void*) _a2_obj;
							std_collections$Map$std_core$IndexSet$set_at__i32__Any(l33, l10, vader_ref_box(l34));
						}
					}
				}
			}
		}
		l7 = (l7 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static void* vader_front_resolver$wit_diagnostic(void* l0) {
	vader_string_t l1 = 0;
	int32_t l2, l3;
	void* l4 = NULL;
	void* t0 = NULL;
	void** gc_raw_roots[3] = { &l0, &l4, &t0 };
	vader_string_t* gc_atom_roots[1] = { &l1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l1 = ((vader_struct_vader_core_wit$WitSpan_t*) ((vader_struct_vader_core_wit$WitError_t*) l0)->f_span)->f_file;
	l2 = ((vader_struct_vader_core_wit$WitSpan_t*) ((vader_struct_vader_core_wit$WitError_t*) l0)->f_span)->f_line;
	l3 = ((vader_struct_vader_core_wit$WitSpan_t*) ((vader_struct_vader_core_wit$WitError_t*) l0)->f_span)->f_column;
	vader_struct_toolchain_span$Position_t* _a0_obj = (vader_struct_toolchain_span$Position_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Position_t));
	vader_obj_header_init(_a0_obj, 1288u);
	_a0_obj->f_file = l1;
	_a0_obj->f_offset = INT64_C(0);
	_a0_obj->f_line = l2;
	_a0_obj->f_column = l3;
	l4 = (void*) _a0_obj;
	vader_struct_toolchain_span$Span_t* _a1_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
	vader_obj_header_init(_a1_obj, 1289u);
	_a1_obj->f_start = l4;
	_a1_obj->f_end = l4;
	l4 = (void*) _a1_obj;
	l1 = ((vader_struct_vader_core_wit$WitError_t*) l0)->f_message;
	t0 = toolchain_diagnostics$resolver_error((uint8_t) 38, l4, l1);
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_front_resolver$with_called_interfaces(void* l0, void* l1) {
	vader_box_t l2 = vader_box_null();
	void* l3 = NULL;
	void* l4 = NULL;
	void* l5 = NULL;
	void* t0 = NULL;
	vader_box_t t1 = vader_box_null();
	vader_box_t* gc_roots[2] = { &l2, &t1 };
	void** gc_raw_roots[6] = { &l0, &l1, &l3, &l4, &l5, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l2 = std_core$$array$Into$into__vader_front_resolver_GeneratedSource(((vader_struct_vader_front_resolver$GeneratedCode_t*) l0)->f_sources);
	vader_struct___lambda_env_vader_front_resolver_1_t* _a0_obj = (vader_struct___lambda_env_vader_front_resolver_1_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_front_resolver_1_t));
	vader_obj_header_init(_a0_obj, 801u);
	_a0_obj->f_cap_0 = l0;
	_a0_obj->f_cap_1 = l1;
	t0 = (void*) _a0_obj;
	vader_fn_t* _a1_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
	vader_obj_header_init(_a1_closure, 618u);
	_a1_closure->code = (void*) &vader_fn_lift___lambda_vader_front_resolver_0;
	_a1_closure->env = t0;
	l3 = (void*) _a1_closure;
	t1 = std_iter$filter__vader_front_resolver_GeneratedSource(l2, l3);
	l3 = t1.payload.obj;
	l4 = l0;
	l3 = std_iter$collect__vader_front_resolver_GeneratedSource(vader_ref_box(l3));
	l5 = ((vader_struct_vader_front_resolver$GeneratedCode_t*) l4)->f_origins;
	l4 = ((vader_struct_vader_front_resolver$GeneratedCode_t*) l4)->f_shipped_interfaces;
	vader_struct_vader_front_resolver$GeneratedCode_t* _a2_obj = (vader_struct_vader_front_resolver$GeneratedCode_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$GeneratedCode_t));
	vader_obj_header_init(_a2_obj, 1784u);
	_a2_obj->f_sources = l3;
	_a2_obj->f_origins = l5;
	_a2_obj->f_shipped_interfaces = l4;
	t0 = (void*) _a2_obj;
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$with_compiler_stages(void* l0) {
	void* l1 = NULL;
	void** gc_raw_roots[2] = { &l0, &l1 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l1 = vader_front_resolver$source_stages();
	vader_array_push_all((vader_array_t*) l1, (vader_array_t*) l0);
	{ void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$with_written_texts(void* l0, void* l1) {
	void* l2 = NULL;
	void* l6 = NULL;
	void* l7 = NULL;
	void* l8 = NULL;
	void* l9 = NULL;
	bool l3;
	int64_t l4, l5, l10, l11;
	vader_string_t l12 = 0;
	vader_string_t l13 = 0;
	vader_string_t l14 = 0;
	vader_string_t l15 = 0;
	void* t0 = NULL;
	bool t1;
	vader_box_t t2 = vader_box_null();
	vader_box_t* gc_roots[1] = { &t2 };
	void** gc_raw_roots[8] = { &l0, &l1, &l2, &l6, &l7, &l8, &l9, &t0 };
	vader_string_t* gc_atom_roots[4] = { &l12, &l13, &l14, &l15 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = l1;
	l3 = false;
	l4 = vader_array_length(((vader_array_t*) l2));
	l5 = INT64_C(0);
	{
		for (;;) {
			if ((l5 < l4)) {
				vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
				VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
				t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
				t1 = __lambda_vader_front_resolver_7(t0);
				if (t1) {
					l5 = (l5 + INT64_C(1));
					continue;
				}
				l3 = false;
				goto end_9;
			}
			break;
		}
		l3 = true;
	} end_9: ;
	if (l3) {
		{ void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l2 = vader_host_std_core$Runtime$deep_copy__std_collections_Map_string__string_(l0);
	l6 = l1;
	l4 = vader_array_length(((vader_array_t*) l6));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		t0 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l5);
		l7 = ((vader_struct_vader_front_resolver$DiscoveredModule_t*) t0)->f_texts;
		l8 = ((vader_struct_std_collections$Map__string__string_t*) l7)->f_ekeys;
		l9 = ((vader_struct_std_collections$Map__string__string_t*) l7)->f_evals;
		l10 = INT64_C(0);
		l11 = ((vader_struct_std_collections$Map__string__string_t*) l7)->f_size;
		while ((l10 < l11)) {
			vader_array_t* _a2_slotarr = ((vader_array_t*) l8);
			VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
			VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l10)
			t2 = vader_array_box_slots(_a2_slotarr->buf)[vader_array_offset(_a2_slotarr) + (size_t) l10];
			l12 = t2.payload.s;
			vader_array_t* _a3_slotarr = ((vader_array_t*) l9);
			VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
			VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l10)
			t2 = vader_array_box_slots(_a3_slotarr->buf)[vader_array_offset(_a3_slotarr) + (size_t) l10];
			l13 = t2.payload.s;
			l14 = l12;
			l15 = l13;
			std_collections$Map$std_core$IndexSet$set_at__string__string(l2, l14, l15);
			l10 = (l10 + INT64_C(1));
		}
		l5 = (l5 + INT64_C(1));
	}
	{ void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_resolver$without_tests(void* l0, vader_string_t l1) {
	void* l2 = NULL;
	void* l6 = NULL;
	void* l7 = NULL;
	void* l13 = NULL;
	void* l14 = NULL;
	void* l15 = NULL;
	void* l16 = NULL;
	void* l17 = NULL;
	void* l24 = NULL;
	void* l25 = NULL;
	void* l26 = NULL;
	void* l27 = NULL;
	void* l28 = NULL;
	void* l30 = NULL;
	void* l31 = NULL;
	void* l32 = NULL;
	bool l3, l23;
	int64_t l4, l5, l8, l9, l29;
	vader_box_t l10 = vader_box_null(), l11 = vader_box_null(), l21 = vader_box_null();
	vader_string_t l12 = 0;
	vader_string_t l18 = 0;
	vader_string_t l19 = 0;
	vader_string_t l20 = 0;
	vader_string_t l22 = 0;
	void* t0 = NULL;
	bool t1;
	vader_box_t* gc_roots[3] = { &l10, &l11, &l21 };
	void** gc_raw_roots[18] = {
		&l0, &l2, &l6, &l7, &l13, &l14, &l15, &l16, &l17, &l24, &l25, &l26, &l27, &l28, &l30, &l31,
		&l32, &t0,
	};
	vader_string_t* gc_atom_roots[6] = { &l1, &l12, &l18, &l19, &l20, &l22 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 3u, 18u, gc_roots, gc_raw_roots, 0u, NULL, 6u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = l0;
	l3 = false;
	l4 = vader_array_length(((vader_array_t*) l2));
	l5 = INT64_C(0);
	{
		while ((l5 < l4)) {
			vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
			VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
			t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
			t1 = __lambda_vader_front_resolver_22(t0);
			if (t1) {
				l3 = true;
				goto end_9;
			}
			l5 = (l5 + INT64_C(1));
		}
		l3 = false;
	} end_9: ;
	if (!(l3)) {
		vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 642u);
		l2 = (void*) _a1_arr;
		vader_array_t* _a2_arr = vader_array_new(26u, 0u, 12u, 640u);
		l6 = (void*) _a2_arr;
		vader_array_t* _a3_arr = vader_array_new(29u, 0u, 7u, 645u);
		l7 = (void*) _a3_arr;
		vader_struct_std_collections$Map__string__bool_t* _a4_obj = (vader_struct_std_collections$Map__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__bool_t));
		vader_obj_header_init(_a4_obj, 1010u);
		_a4_obj->f_ekeys = l2;
		_a4_obj->f_evals = l6;
		_a4_obj->f_index = l7;
		_a4_obj->f_mask = INT64_C(0);
		_a4_obj->f_grow_at = INT64_C(0);
		_a4_obj->f_size = INT64_C(0);
		_a4_obj->f_tombs = INT64_C(0);
		t0 = (void*) _a4_obj;
		vader_struct_std_collections$Set__string_t* _a5_obj = (vader_struct_std_collections$Set__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__string_t));
		vader_obj_header_init(_a5_obj, 1110u);
		_a5_obj->f_inner = t0;
		l2 = (void*) _a5_obj;
		vader_struct_vader_front_resolver$Untested_t* _a6_obj = (vader_struct_vader_front_resolver$Untested_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$Untested_t));
		vader_obj_header_init(_a6_obj, 1821u);
		_a6_obj->f_files = l0;
		_a6_obj->f_cut = l2;
		t0 = (void*) _a6_obj;
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	vader_array_t* _a7_arr = vader_array_new(28u, 0u, 0u, 642u);
	l2 = (void*) _a7_arr;
	vader_array_t* _a8_arr = vader_array_new(26u, 0u, 12u, 640u);
	l6 = (void*) _a8_arr;
	vader_array_t* _a9_arr = vader_array_new(29u, 0u, 7u, 645u);
	l7 = (void*) _a9_arr;
	vader_struct_std_collections$Map__string__bool_t* _a10_obj = (vader_struct_std_collections$Map__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__bool_t));
	vader_obj_header_init(_a10_obj, 1010u);
	_a10_obj->f_ekeys = l2;
	_a10_obj->f_evals = l6;
	_a10_obj->f_index = l7;
	_a10_obj->f_mask = INT64_C(0);
	_a10_obj->f_grow_at = INT64_C(0);
	_a10_obj->f_size = INT64_C(0);
	_a10_obj->f_tombs = INT64_C(0);
	t0 = (void*) _a10_obj;
	vader_struct_std_collections$Set__string_t* _a11_obj = (vader_struct_std_collections$Set__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__string_t));
	vader_obj_header_init(_a11_obj, 1110u);
	_a11_obj->f_inner = t0;
	l2 = (void*) _a11_obj;
	l6 = l0;
	l4 = vader_array_length(((vader_array_t*) l6));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a12_slotarr = ((vader_array_t*) l6);
		VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
		t0 = vader_array_ref_load_obj(_a12_slotarr->buf, vader_array_offset(_a12_slotarr) + (size_t) l5);
		l7 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) t0)->f_program)->f_decls;
		l8 = vader_array_length(((vader_array_t*) l7));
		l9 = INT64_C(0);
		while ((l9 < l8)) {
			vader_array_t* _a13_slotarr = ((vader_array_t*) l7);
			VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
			l10 = vader_array_ref_load_box(_a13_slotarr->buf, vader_array_offset(_a13_slotarr) + (size_t) l9);
			t1 = toolchain_ast$decl_is_public(l10);
			if (!(t1)) {
				t1 = vader_front_resolver$declares_type(l10);
				if (t1) {
					l11 = vader_front_resolver$declared_name(l10);
					if (l11.tag == 0u) {
						l9 = (l9 + INT64_C(1));
						continue;
					}
					l12 = l11.payload.s;
					std_collections$add__string(l2, l12);
				}
			}
			l9 = (l9 + INT64_C(1));
		}
		l5 = (l5 + INT64_C(1));
	}
	vader_array_t* _a14_arr = vader_array_new(28u, 0u, 0u, 642u);
	l6 = (void*) _a14_arr;
	vader_array_t* _a15_arr = vader_array_new(3u, 0u, 13u, 28u);
	l7 = (void*) _a15_arr;
	vader_array_t* _a16_arr = vader_array_new(29u, 0u, 7u, 645u);
	l13 = (void*) _a16_arr;
	vader_struct_std_collections$Map__string__string___t* _a17_obj = (vader_struct_std_collections$Map__string__string___t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__string___t));
	vader_obj_header_init(_a17_obj, 1029u);
	_a17_obj->f_ekeys = l6;
	_a17_obj->f_evals = l7;
	_a17_obj->f_index = l13;
	_a17_obj->f_mask = INT64_C(0);
	_a17_obj->f_grow_at = INT64_C(0);
	_a17_obj->f_size = INT64_C(0);
	_a17_obj->f_tombs = INT64_C(0);
	l6 = (void*) _a17_obj;
	vader_array_t* _a18_arr = vader_array_new(28u, 0u, 0u, 642u);
	l7 = (void*) _a18_arr;
	vader_array_t* _a19_arr = vader_array_new(28u, 0u, 0u, 642u);
	l13 = (void*) _a19_arr;
	vader_array_t* _a20_arr = vader_array_new(28u, 0u, 0u, 642u);
	l14 = (void*) _a20_arr;
	l15 = l0;
	l4 = vader_array_length(((vader_array_t*) l15));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a21_slotarr = ((vader_array_t*) l15);
		VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l5)
		t0 = vader_array_ref_load_obj(_a21_slotarr->buf, vader_array_offset(_a21_slotarr) + (size_t) l5);
		l16 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) t0)->f_program)->f_decls;
		l8 = vader_array_length(((vader_array_t*) l16));
		l9 = INT64_C(0);
		while ((l9 < l8)) {
			vader_array_t* _a22_slotarr = ((vader_array_t*) l16);
			VADER_ARRAY_RESOLVE_BUF(_a22_slotarr)
			VADER_ARRAY_CHECK_INDEX(_a22_slotarr, l9)
			l10 = vader_array_ref_load_box(_a22_slotarr->buf, vader_array_offset(_a22_slotarr) + (size_t) l9);
			vader_array_t* _a23_arr = vader_array_new(28u, 0u, 0u, 642u);
			l17 = (void*) _a23_arr;
			vader_front_reach$collect_names(l10, l17);
			l11 = vader_front_resolver$declared_name(l10);
			if (l11.tag == 0u) {
				l21 = vader_front_resolver$private_type_of(l10, l2);
				if (l21.tag == 0u) {
					vader_array_push_all((vader_array_t*) l14, (vader_array_t*) l17);
				} else {
					l22 = l21.payload.s;
					vader_front_reach$register_refs(l6, l22, l17);
				}
				l9 = (l9 + INT64_C(1));
				continue;
			}
			l12 = l11.payload.s;
			vader_front_reach$register_refs(l6, l12, l17);
			t1 = vader_front_resolver$is_test(l10);
			if (t1) {
				l18 = l11.payload.s;
				vader_array_push_scalar((vader_array_t*) l13, vader_box_string(642u, l18));
			} else {
				l19 = l11.payload.s;
				t1 = vader_front_resolver$is_surface(l10, l19, l1);
				if (t1) {
					l20 = l11.payload.s;
					vader_array_push_scalar((vader_array_t*) l7, vader_box_string(642u, l20));
				}
			}
			l9 = (l9 + INT64_C(1));
		}
		l5 = (l5 + INT64_C(1));
	}
	l7 = vader_front_reach$bfs_reachable(l7, l14, l6);
	vader_array_t* _a24_arr = vader_array_new(28u, 0u, 0u, 642u);
	l14 = (void*) _a24_arr;
	l6 = vader_front_reach$bfs_reachable(l13, l14, l6);
	vader_array_t* _a25_arr = vader_array_new(352u, 0u, 13u, 1814u);
	l13 = (void*) _a25_arr;
	vader_array_t* _a26_arr = vader_array_new(28u, 0u, 0u, 642u);
	l14 = (void*) _a26_arr;
	vader_array_t* _a27_arr = vader_array_new(26u, 0u, 12u, 640u);
	l15 = (void*) _a27_arr;
	vader_array_t* _a28_arr = vader_array_new(29u, 0u, 7u, 645u);
	l16 = (void*) _a28_arr;
	vader_struct_std_collections$Map__string__bool_t* _a29_obj = (vader_struct_std_collections$Map__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__bool_t));
	vader_obj_header_init(_a29_obj, 1010u);
	_a29_obj->f_ekeys = l14;
	_a29_obj->f_evals = l15;
	_a29_obj->f_index = l16;
	_a29_obj->f_mask = INT64_C(0);
	_a29_obj->f_grow_at = INT64_C(0);
	_a29_obj->f_size = INT64_C(0);
	_a29_obj->f_tombs = INT64_C(0);
	t0 = (void*) _a29_obj;
	vader_struct_std_collections$Set__string_t* _a30_obj = (vader_struct_std_collections$Set__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__string_t));
	vader_obj_header_init(_a30_obj, 1110u);
	_a30_obj->f_inner = t0;
	l14 = (void*) _a30_obj;
	vader_struct_vader_front_resolver$Untested_t* _a31_obj = (vader_struct_vader_front_resolver$Untested_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$Untested_t));
	vader_obj_header_init(_a31_obj, 1821u);
	_a31_obj->f_files = l13;
	_a31_obj->f_cut = l14;
	l13 = (void*) _a31_obj;
	l14 = l0;
	l4 = vader_array_length(((vader_array_t*) l14));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a32_slotarr = ((vader_array_t*) l14);
		VADER_ARRAY_RESOLVE_BUF(_a32_slotarr)
		l15 = vader_array_ref_load_obj(_a32_slotarr->buf, vader_array_offset(_a32_slotarr) + (size_t) l5);
		vader_array_t* _a33_arr = vader_array_new(481u, 0u, 13u, 2450u);
		l16 = (void*) _a33_arr;
		l17 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) l15)->f_program)->f_decls;
		l8 = vader_array_length(((vader_array_t*) l17));
		l9 = INT64_C(0);
		while ((l9 < l8)) {
			vader_array_t* _a34_slotarr = ((vader_array_t*) l17);
			VADER_ARRAY_RESOLVE_BUF(_a34_slotarr)
			l10 = vader_array_ref_load_box(_a34_slotarr->buf, vader_array_offset(_a34_slotarr) + (size_t) l9);
			t1 = vader_front_resolver$is_reached(l10, l6, l2);
			if (t1) {
				t1 = vader_front_resolver$is_reached(l10, l7, l2);
				l3 = !(t1);
			} else {
				l3 = false;
			}
			t1 = vader_front_resolver$is_test(l10);
			if (t1) {
				l23 = true;
			} else {
				l23 = l3;
			}
			if (l23) {
				l24 = ((vader_struct_vader_front_resolver$Untested_t*) l13)->f_cut;
				t0 = toolchain_ast$decl_span(l10);
				l12 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) t0)->f_start)->f_file;
				std_collections$add__string(l24, l12);
			} else {
				vader_array_push_ref((vader_array_t*) l16, l10.payload.obj);
			}
			l9 = (l9 + INT64_C(1));
		}
		l25 = ((vader_struct_vader_front_resolver$Untested_t*) l13)->f_files;
		l26 = l15;
		l18 = ((vader_struct_vader_front_resolver$SourceFile_t*) l26)->f_path;
		l19 = ((vader_struct_vader_front_resolver$SourceFile_t*) l26)->f_content;
		l27 = ((vader_struct_vader_front_resolver$SourceFile_t*) l15)->f_program;
		l20 = ((vader_struct_toolchain_ast$Program_t*) l27)->f_file;
		l28 = ((vader_struct_toolchain_ast$Program_t*) l27)->f_span;
		l29 = ((vader_struct_toolchain_ast$Program_t*) l27)->f_id;
		l11 = ((vader_struct_toolchain_ast$Program_t*) l27)->f_module;
		vader_struct_toolchain_ast$Program_t* _a35_obj = (vader_struct_toolchain_ast$Program_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$Program_t));
		vader_obj_header_init(_a35_obj, 1213u);
		_a35_obj->f_file = l20;
		_a35_obj->f_span = l28;
		_a35_obj->f_id = l29;
		_a35_obj->f_module = l11;
		_a35_obj->f_decls = l16;
		l30 = (void*) _a35_obj;
		l31 = ((vader_struct_vader_front_resolver$SourceFile_t*) l26)->f_origins;
		vader_struct_vader_front_resolver$SourceFile_t* _a36_obj = (vader_struct_vader_front_resolver$SourceFile_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$SourceFile_t));
		vader_obj_header_init(_a36_obj, 1814u);
		_a36_obj->f_path = l18;
		_a36_obj->f_content = l19;
		_a36_obj->f_program = l30;
		_a36_obj->f_origins = l31;
		l32 = (void*) _a36_obj;
		vader_array_push_ref((vader_array_t*) l25, l32);
		l5 = (l5 + INT64_C(1));
	}
	{ void* __vret = l13; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_resolver$wrap_file(void* l0, vader_string_t l1, void* l2, void* l3, void* l4, void* l5) {
	void* l6 = NULL;
	void* l9 = NULL;
	void* l10 = NULL;
	void* l11 = NULL;
	void* l12 = NULL;
	void* l16 = NULL;
	void* l17 = NULL;
	void* l19 = NULL;
	void* l20 = NULL;
	void* l33 = NULL;
	void* l34 = NULL;
	void* l35 = NULL;
	vader_string_t l7 = 0;
	vader_string_t l8 = 0;
	vader_string_t l27 = 0;
	vader_string_t l36 = 0;
	int64_t l13, l14, l23, l24, l26, l28, l29, l30, l31, l32;
	vader_box_t l15 = vader_box_null(), l18 = vader_box_null(), l21 = vader_box_null(), l22 = vader_box_null();
	bool l25;
	void* t0 = NULL;
	bool t1;
	vader_string_t t2 = 0;
	vader_box_t* gc_roots[4] = { &l15, &l18, &l21, &l22 };
	void** gc_raw_roots[18] = {
		&l0, &l2, &l3, &l4, &l5, &l6, &l9, &l10, &l11, &l12, &l16, &l17, &l19, &l20, &l33, &l34,
		&l35, &t0,
	};
	vader_string_t* gc_atom_roots[6] = { &l1, &l7, &l8, &l27, &l36, &t2 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 4u, 18u, gc_roots, gc_raw_roots, 0u, NULL, 6u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l6 = ((vader_struct_vader_front_resolver$SourceFile_t*) l0)->f_program;
	l7 = ((vader_struct_vader_front_resolver$SourceFile_t*) l0)->f_path;
	l8 = vader_front_resolver$imports_text(l0);
	l7 = vader_front_resolver$framed_source(2739u, l7, l1, l8);
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
	t0 = (void*) _a0_arr;
	vader_struct_std_string__builder$StringBuilder_t* _a1_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
	vader_obj_header_init(_a1_obj, 1139u);
	_a1_obj->f_parts = t0;
	l9 = (void*) _a1_obj;
	vader_array_t* _a2_arr = vader_array_new(333u, 0u, 13u, 1772u);
	l10 = (void*) _a2_arr;
	vader_array_t* _a3_arr = vader_array_new(73u, 0u, 13u, 1181u);
	l11 = (void*) _a3_arr;
	l12 = ((vader_struct_toolchain_ast$Program_t*) l6)->f_decls;
	l13 = vader_array_length(((vader_array_t*) l12));
	l14 = INT64_C(0);
	while ((l14 < l13)) {
		vader_array_t* _a4_slotarr = ((vader_array_t*) l12);
		VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
		l15 = vader_array_ref_load_box(_a4_slotarr->buf, vader_array_offset(_a4_slotarr) + (size_t) l14);
		if (l15.tag == 1181u) {
			l16 = l15.payload.obj;
			l17 = vader_front_resolver$interceptions_of(l6, l1, l16, l2, l3);
			t1 = std_core$is_empty__vader_front_resolver_Interception(l17);
			if (t1) {
				l14 = (l14 + INT64_C(1));
				continue;
			}
			l18 = vader_front_resolver$refusal(l16, l17);
			if (l18.tag == 0u) {
				l22 = ((vader_struct_toolchain_ast$FnDecl_t*) l16)->f_return_type;
				if (l22.tag == 0u) {
					l14 = (l14 + INT64_C(1));
					continue;
				}
				l21 = l22;
				l23 = INT64_C(1);
				l24 = vader_array_length(((vader_array_t*) l17));
				l25 = (l23 <= l24);
				while (l25) {
					l26 = std_string__builder$byte_len(l9);
					l27 = vader_front_resolver$layer_text(l0, l1, l16, l21, l17, l23);
					std_string__builder$append(l9, l27);
					l28 = vader_chk_add(i64, (int64_t) vader_string_byte_len(l7), l26);
					l29 = (int64_t) vader_string_byte_len(l7);
					l30 = std_string__builder$byte_len(l9);
					l31 = vader_chk_add(i64, l29, l30);
					l32 = vader_chk_sub(i64, l23, INT64_C(1));
					vader_array_t* _a5_slotarr = ((vader_array_t*) l17);
					VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
					VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l32)
					l33 = vader_array_ref_load_obj(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) l32);
					l34 = vader_front_resolver$layer_origin(l16, l33);
					vader_struct_vader_front_resolver$CodeOrigin_t* _a6_obj = (vader_struct_vader_front_resolver$CodeOrigin_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$CodeOrigin_t));
					vader_obj_header_init(_a6_obj, 1772u);
					_a6_obj->f_start = l28;
					_a6_obj->f_end = l31;
					_a6_obj->f_origin = l34;
					l35 = (void*) _a6_obj;
					vader_array_push_ref((vader_array_t*) l10, l35);
					l25 = (l23 < l24);
					l23 = (l23 + INT64_C(1));
				}
				vader_array_push_ref((vader_array_t*) l11, l16);
			} else {
				l19 = ((vader_struct_toolchain_ast$FnDecl_t*) l16)->f_name_span;
				l8 = l18.payload.s;
				l20 = toolchain_diagnostics$resolver_error((uint8_t) 36, l19, l8);
				vader_array_push_ref((vader_array_t*) l5, l20);
				l14 = (l14 + INT64_C(1));
				continue;
			}
		}
		l14 = (l14 + INT64_C(1));
	}
	t1 = std_core$is_empty__toolchain_ast_FnDecl(l11);
	if (t1) {
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	l8 = ((vader_struct_vader_front_resolver$SourceFile_t*) l0)->f_path;
	l8 = vader_front_resolver$generated_file(2739u, l8);
	l27 = std_string__builder$StringBuilder$std_core$Display$to_string(l9);
	l7 = concat_2(l7, l27);
	l6 = toolchain_parser$parse_compiler_written(l7, l8);
	l9 = ((vader_struct_toolchain_parser$ParsedSource_t*) l6)->f_errors;
	vader_array_push_all((vader_array_t*) l5, (vader_array_t*) l9);
	toolchain_parser$assign_program_ids(((vader_struct_toolchain_parser$ParsedSource_t*) l6)->f_program, l4);
	vader_array_t* _a7_arr = vader_array_new(28u, 0u, 0u, 642u);
	l9 = (void*) _a7_arr;
	vader_array_t* _a8_arr = vader_array_new(35u, 0u, 0u, 653u);
	l12 = (void*) _a8_arr;
	vader_array_t* _a9_arr = vader_array_new(29u, 0u, 7u, 645u);
	l16 = (void*) _a9_arr;
	vader_struct_std_collections$Map__string__Any_t* _a10_obj = (vader_struct_std_collections$Map__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any_t));
	vader_obj_header_init(_a10_obj, 1004u);
	_a10_obj->f_ekeys = l9;
	_a10_obj->f_evals = l12;
	_a10_obj->f_index = l16;
	_a10_obj->f_mask = INT64_C(0);
	_a10_obj->f_grow_at = INT64_C(0);
	_a10_obj->f_size = INT64_C(0);
	_a10_obj->f_tombs = INT64_C(0);
	l9 = (void*) _a10_obj;
	l12 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_toolchain_parser$ParsedSource_t*) l6)->f_program)->f_decls;
	l13 = vader_array_length(((vader_array_t*) l12));
	l14 = INT64_C(0);
	while ((l14 < l13)) {
		vader_array_t* _a11_slotarr = ((vader_array_t*) l12);
		VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
		l15 = vader_array_ref_load_box(_a11_slotarr->buf, vader_array_offset(_a11_slotarr) + (size_t) l14);
		if (l15.tag == 1181u) {
			l16 = l15.payload.obj;
			l27 = ((vader_struct_toolchain_ast$FnDecl_t*) l16)->f_name;
			std_collections$Map$std_core$IndexSet$set_at__string__Any(l9, l27, vader_ref_box(l16));
		}
		l14 = (l14 + INT64_C(1));
	}
	l13 = vader_array_length(((vader_array_t*) l11));
	l14 = INT64_C(0);
	while ((l14 < l13)) {
		vader_array_t* _a12_slotarr = ((vader_array_t*) l11);
		VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
		l12 = vader_array_ref_load_obj(_a12_slotarr->buf, vader_array_offset(_a12_slotarr) + (size_t) l14);
		l27 = ((vader_struct_toolchain_ast$FnDecl_t*) l12)->f_name;
		l15 = std_collections$Map$std_core$Index$at__string__Any(l9, l27);
		if (!(l15.tag == 0u)) {
			l16 = l15.payload.obj;
			l18 = ((vader_struct_toolchain_ast$FnDecl_t*) l12)->f_doc;
			((vader_struct_toolchain_ast$FnDecl_t*) l16)->f_doc = l18;
			VADER_WRITE_BARRIER((vader_struct_toolchain_ast$FnDecl_t*) l16);
		}
		t2 = ((vader_struct_toolchain_ast$FnDecl_t*) l12)->f_name;
		l36 = vader_core_mangle$generated_name(t2, (uint8_t) 0);
		((vader_struct_toolchain_ast$FnDecl_t*) l12)->f_name = l36;
		((vader_struct_toolchain_ast$FnDecl_t*) l12)->f_visibility = (uint8_t) 1;
		((vader_struct_toolchain_ast$FnDecl_t*) l12)->f_doc = vader_box_obj(0u, NULL);
		VADER_WRITE_BARRIER((vader_struct_toolchain_ast$FnDecl_t*) l12);
		l14 = (l14 + INT64_C(1));
	}
	l6 = ((vader_struct_toolchain_parser$ParsedSource_t*) l6)->f_program;
	vader_struct_vader_front_resolver$SourceFile_t* _a13_obj = (vader_struct_vader_front_resolver$SourceFile_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$SourceFile_t));
	vader_obj_header_init(_a13_obj, 1814u);
	_a13_obj->f_path = l8;
	_a13_obj->f_content = l7;
	_a13_obj->f_program = l6;
	_a13_obj->f_origins = l10;
	t0 = (void*) _a13_obj;
	{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_front_resolver$writes_given(void* l0, vader_string_t l1, void* l2, void* l3) {
	void* l4 = NULL;
	void* l7 = NULL;
	void* l10 = NULL;
	void* l11 = NULL;
	void* l12 = NULL;
	int64_t l5, l6, l8, l9, l14, l15;
	bool l13;
	vader_box_t l16 = vader_box_null();
	vader_box_t t0 = vader_box_null();
	bool t1;
	vader_box_t* gc_roots[2] = { &l16, &t0 };
	void** gc_raw_roots[8] = { &l0, &l2, &l3, &l4, &l7, &l10, &l11, &l12 };
	vader_string_t* gc_atom_roots[1] = { &l1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l4 = ((vader_struct_toolchain_ast$Program_t*) l0)->f_decls;
	l5 = vader_array_length(((vader_array_t*) l4));
	l6 = INT64_C(0);
	while ((l6 < l5)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		t0 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l6);
		l7 = toolchain_ast$decl_decorators(t0);
		l8 = vader_array_length(((vader_array_t*) l7));
		l9 = INT64_C(0);
		while ((l9 < l8)) {
			vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
			VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
			l10 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l9);
			l11 = l2;
			vader_struct___lambda_env_vader_front_resolver_17_t* _a2_obj = (vader_struct___lambda_env_vader_front_resolver_17_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_front_resolver_17_t));
			vader_obj_header_init(_a2_obj, 804u);
			_a2_obj->f_cap_0 = l0;
			_a2_obj->f_cap_1 = l1;
			_a2_obj->f_cap_2 = l10;
			_a2_obj->f_cap_3 = l3;
			l12 = (void*) _a2_obj;
			l13 = false;
			l14 = vader_array_length(((vader_array_t*) l11));
			l15 = INT64_C(0);
			{
				while ((l15 < l14)) {
					vader_array_t* _a3_slotarr = ((vader_array_t*) l11);
					VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
					l16 = vader_array_ref_load_box(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l15);
					t1 = __lambda_vader_front_resolver_16(l12, l16);
					if (t1) {
						l13 = true;
						goto end_44;
					}
					l15 = (l15 + INT64_C(1));
				}
				l13 = false;
			} end_44: ;
			if (l13) {
				{ vader_gc_top = gc_frame.prev; return true; }
			}
			l9 = (l9 + INT64_C(1));
		}
		l6 = (l6 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return false; }
}

static vader_box_t vader_front_resolver$written_module(void* l0, vader_box_t l1, vader_string_t l2, void* l3, void* l4) {
	void* l5 = NULL;
	void* l6 = NULL;
	void* l10 = NULL;
	void* l11 = NULL;
	vader_box_t l7 = vader_box_null();
	vader_string_t l8 = 0;
	vader_string_t l9 = 0;
	vader_string_t l12 = 0;
	uint8_t l13;
	void* t0 = NULL;
	vader_box_t t1 = vader_box_null();
	vader_string_t t2 = 0;
	bool t3;
	vader_box_t* gc_roots[3] = { &l1, &l7, &t1 };
	void** gc_raw_roots[8] = { &l0, &l3, &l4, &l5, &l6, &l10, &l11, &t0 };
	vader_string_t* gc_atom_roots[5] = { &l2, &l8, &l9, &l12, &t2 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 3u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l5 = ((vader_struct_vader_front_resolver$ModuleServer_t*) l0)->f_roots;
	vader_struct_vader_front_resolver$LoadFiles_t* _a0_obj = (vader_struct_vader_front_resolver$LoadFiles_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$LoadFiles_t));
	vader_obj_header_init(_a0_obj, 1794u);
	_a0_obj->f_overlay = l3;
	l6 = (void*) _a0_obj;
	vader_struct_toolchain_stage$ModuleRequest_t* _a1_obj = (vader_struct_toolchain_stage$ModuleRequest_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_stage$ModuleRequest_t));
	vader_obj_header_init(_a1_obj, 1296u);
	_a1_obj->f_name = l2;
	_a1_obj->f_roots = l5;
	_a1_obj->f_files = vader_ref_box(l6);
	t0 = (void*) _a1_obj;
	l7 = toolchain_stage$Stage$run$$dispatch(l1, vader_ref_box(t0));
	if (l7.tag == 0u) {
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	l5 = l7.payload.obj;
	l6 = ((vader_struct_toolchain_stage$ModuleSource_t*) l5)->f_diagnostics;
	vader_array_push_all((vader_array_t*) l4, (vader_array_t*) l6);
	t1 = toolchain_stage$Stage$describe$$dispatch(l1);
	l8 = ((vader_struct_toolchain_stage$ModuleSpec_t*) t1.payload.obj)->f_name;
	l9 = vader_front_resolver$generated_file(l8, l2);
	vader_array_t* _a2_arr = vader_array_new(28u, 0u, 0u, 642u);
	l6 = (void*) _a2_arr;
	vader_array_t* _a3_arr = vader_array_new(28u, 0u, 0u, 642u);
	l10 = (void*) _a3_arr;
	vader_array_t* _a4_arr = vader_array_new(29u, 0u, 7u, 645u);
	l11 = (void*) _a4_arr;
	vader_struct_std_collections$Map__string__string_t* _a5_obj = (vader_struct_std_collections$Map__string__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__string_t));
	vader_obj_header_init(_a5_obj, 1028u);
	_a5_obj->f_ekeys = l6;
	_a5_obj->f_evals = l10;
	_a5_obj->f_index = l11;
	_a5_obj->f_mask = INT64_C(0);
	_a5_obj->f_grow_at = INT64_C(0);
	_a5_obj->f_size = INT64_C(0);
	_a5_obj->f_tombs = INT64_C(0);
	l6 = (void*) _a5_obj;
	t2 = ((vader_struct_toolchain_stage$ModuleSource_t*) l5)->f_text;
	if (t2 != 0u) {
		l12 = ((vader_struct_toolchain_stage$ModuleSource_t*) l5)->f_text;
		l8 = vader_front_resolver$framed_source(l8, l2, l2, l12);
		std_collections$Map$std_core$IndexSet$set_at__string__string(l6, l9, l8);
	}
	vader_array_t* _a6_arr = vader_array_new(28u, 1u, 0u, 642u);
	vader_array_box_slots(_a6_arr->buf)[vader_array_offset(_a6_arr) + 0u] = vader_box_string(642u, l9);
	l10 = (void*) _a6_arr;
	t3 = ((vader_struct_toolchain_stage$ModuleSource_t*) l5)->f_of_toolchain;
	if (t3) {
		l13 = (uint8_t) 1;
		vader_struct_vader_front_resolver$DiscoveredModule_t* _a7_obj = (vader_struct_vader_front_resolver$DiscoveredModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$DiscoveredModule_t));
		vader_obj_header_init(_a7_obj, 1777u);
		_a7_obj->f_name = l2;
		_a7_obj->f_folder = l9;
		_a7_obj->f_files = l10;
		_a7_obj->f_origin = l13;
		_a7_obj->f_texts = l6;
		t0 = (void*) _a7_obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l13 = (uint8_t) 0;
	vader_struct_vader_front_resolver$DiscoveredModule_t* _a8_obj = (vader_struct_vader_front_resolver$DiscoveredModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$DiscoveredModule_t));
	vader_obj_header_init(_a8_obj, 1777u);
	_a8_obj->f_name = l2;
	_a8_obj->f_folder = l9;
	_a8_obj->f_files = l10;
	_a8_obj->f_origin = l13;
	_a8_obj->f_texts = l6;
	t0 = (void*) _a8_obj;
	{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_resolver$written_origin(void* l0, vader_string_t l1, void* l2, void* l3) {
	vader_box_t l4 = vader_box_null(), l8 = vader_box_null(), l10 = vader_box_null(), l15 = vader_box_null(), l16 = vader_box_null(), l17 = vader_box_null();
	void* l5 = NULL;
	void* l9 = NULL;
	int64_t l6, l7;
	vader_string_t l11 = 0;
	vader_string_t l12 = 0;
	vader_string_t l13 = 0;
	vader_string_t l14 = 0;
	void* t0 = NULL;
	vader_box_t t1 = vader_box_null();
	vader_box_t* gc_roots[7] = { &l4, &l8, &l10, &l15, &l16, &l17, &t1 };
	void** gc_raw_roots[6] = { &l0, &l2, &l3, &l5, &l9, &t0 };
	vader_string_t* gc_atom_roots[5] = { &l1, &l11, &l12, &l13, &l14 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 7u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l4 = ((vader_struct_toolchain_ast$Decorator_t*) l2)->f_qualifier;
	if (l4.tag == 0u) {
		l11 = ((vader_struct_toolchain_ast$Decorator_t*) l2)->f_name;
		l8 = vader_front_resolver$declared_in(l3, l1, l11);
		if (!(l8.tag == 0u)) {
			t0 = l8.payload.obj;
			{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
		}
		l5 = ((vader_struct_toolchain_ast$Program_t*) l0)->f_decls;
		l6 = vader_array_length(((vader_array_t*) l5));
		l7 = INT64_C(0);
		while ((l7 < l6)) {
			vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
			VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
			l10 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l7);
			if (l10.tag == 1191u) {
				l9 = l10.payload.obj;
				l15 = ((vader_struct_toolchain_ast$ImportDecl_t*) l9)->f_binding;
				l13 = ((vader_struct_toolchain_ast$Decorator_t*) l2)->f_name;
				l16 = vader_front_resolver$declared_name_through(l15, l13);
				if (l16.tag == 0u) {
					l7 = (l7 + INT64_C(1));
					continue;
				}
				l12 = l16.payload.s;
				l14 = ((vader_struct_toolchain_ast$ImportDecl_t*) l9)->f_path;
				l17 = vader_front_resolver$declared_in(l3, l14, l12);
				if (!(l17.tag == 0u)) {
					t0 = l17.payload.obj;
					{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
				}
			}
			l7 = (l7 + INT64_C(1));
		}
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	l5 = ((vader_struct_toolchain_ast$Program_t*) l0)->f_decls;
	l6 = vader_array_length(((vader_array_t*) l5));
	l7 = INT64_C(0);
	while ((l7 < l6)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		l8 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l7);
		if (l8.tag == 1191u) {
			l9 = l8.payload.obj;
			l10 = ((vader_struct_toolchain_ast$ImportDecl_t*) l9)->f_binding;
			if (l10.tag == 1206u) {
				t0 = l10.payload.obj;
				l11 = ((vader_struct_toolchain_ast$NamedNamespaceImport_t*) t0)->f_name;
				t0 = l4.payload.obj;
				l12 = ((vader_struct_toolchain_ast$IdentExpr_t*) t0)->f_name;
				if (l11 == l12) {
					l13 = ((vader_struct_toolchain_ast$ImportDecl_t*) l9)->f_path;
					l14 = ((vader_struct_toolchain_ast$Decorator_t*) l2)->f_name;
					t1 = vader_front_resolver$declared_in(l3, l13, l14);
					{ vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
				}
			}
		}
		l7 = (l7 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
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
	vader_obj_header_init(_a0_obj, 1288u);
	_a0_obj->f_file = l0;
	_a0_obj->f_offset = INT64_C(0);
	_a0_obj->f_line = INT32_C(1);
	_a0_obj->f_column = INT32_C(1);
	l1 = (void*) _a0_obj;
	vader_struct_toolchain_span$Position_t* _a1_obj = (vader_struct_toolchain_span$Position_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Position_t));
	vader_obj_header_init(_a1_obj, 1288u);
	_a1_obj->f_file = l0;
	_a1_obj->f_offset = INT64_C(0);
	_a1_obj->f_line = INT32_C(1);
	_a1_obj->f_column = INT32_C(1);
	l2 = (void*) _a1_obj;
	vader_struct_toolchain_span$Span_t* _a2_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
	vader_obj_header_init(_a2_obj, 1289u);
	_a2_obj->f_start = l1;
	_a2_obj->f_end = l2;
	t0 = (void*) _a2_obj;
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}
