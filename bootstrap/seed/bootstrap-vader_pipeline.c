#include "bootstrap.split.h"

static void vader_pipeline$bake_deferred_values(vader_string_t l0, void* l1, vader_box_t l2, void* l3, void* l4, void* l5);
static void vader_pipeline$bake_with_own_bodies(void* l0, void* l1, void* l2);
static bool vader_pipeline$bounds_verification_enabled(void);
static vader_string_t vader_pipeline$canonicalise(vader_string_t l0);
static void* vader_pipeline$cfg_to_bytecode(void* l0, vader_string_t l1, void* l2, void* l3, void* l4);
static void* vader_pipeline$collect_body_diags(void* l0);
static void* vader_pipeline$dump_scope(void* l0, void* l1);
static vader_string_t vader_pipeline$entry_main_name(void* l0, vader_string_t l1);
static void* vader_pipeline$gather_pipeline_diags(void* l0);
static vader_string_t vader_pipeline$imports_header_path(vader_string_t l0);
static void* vader_pipeline$in_scope_diag_files(void* l0, void* l1);
static void* vader_pipeline$lower_to_entry_from(void* l0, bool l1);
static void* vader_pipeline$lower_to_entry_with(vader_string_t l0, void* l1, vader_box_t l2, vader_box_t l3, bool l4);
static bool vader_pipeline$marks_proven_bounds(void* l0);
static vader_string_t vader_pipeline$module_name_from_file(vader_string_t l0);
static void* vader_pipeline$native_c_options(vader_string_t l0);
static void* vader_pipeline$prepare_cfg_bytecode_from(void* l0, vader_string_t l1, bool l2, bool l3, bool l4);
static void* vader_pipeline$prepare_cfg_bytecode_with(vader_string_t l0, bool l1, void* l2, vader_box_t l3, vader_box_t l4, bool l5, bool l6);
static void* vader_pipeline$prepare_evaluated_project_with(vader_string_t l0, void* l1, vader_box_t l2, vader_box_t l3);
static bool vader_pipeline$proves_bounds(bool l0);
static void* vader_pipeline$scope_or_entry(void* l0, vader_string_t l1);
static vader_string_t vader_pipeline$split_globals_path(vader_string_t l0);
static vader_string_t vader_pipeline$split_header_name(vader_string_t l0);
static vader_string_t vader_pipeline$split_header_path(vader_string_t l0);
static void* vader_pipeline$split_program(void* l0, vader_string_t l1);
static vader_string_t vader_pipeline$unit_path(vader_string_t l0, vader_string_t l1, vader_string_t l2);
static bool vader_pipeline$wants_debug(void* l0);
static int32_t vader_pipeline$write_out(vader_string_t l0, vader_string_t l1);
static int32_t vader_pipeline$write_split_files(vader_string_t l0, void* l1);

static void vader_pipeline$bake_deferred_values(vader_string_t l0, void* l1, vader_box_t l2, void* l3, void* l4, void* l5) {
    bool l6;
    uint8_t l7, l8;
    vader_box_t l9 = vader_box_null();
    void* l10 = NULL;
    void* l11 = NULL;
    void* l14 = NULL;
    int64_t l12, l13;
    int64_t t0;
    void* t1 = NULL;
    bool t2;
    vader_box_t* gc_roots[2] = { &l2, &l9 };
    void** gc_raw_roots[8] = { &l1, &l3, &l4, &l5, &l10, &l11, &l14, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_vader_front_comptime$EvaluatedProject_t*) l4)->f_vm_required)->length;
    if (t0 == INT64_C(0)) {
        l6 = true;
    } else {
        l6 = !(l2.tag == 1417u);
    }
    if (l6) {
        l6 = true;
    } else {
        t1 = l2.payload.obj;
        l7 = ((vader_struct_vader_support_target$Target_t*) t1)->f_os;
        t1 = vader_support_target$host_target();
        l8 = ((vader_struct_vader_support_target$Target_t*) t1)->f_os;
        l6 = l7 == l8;
    }
    if (l6) {
        vader_pipeline$bake_with_own_bodies(l3, l4, l5);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l9 = ((vader_struct_vader_front_resolver$LoadedProject_t*) l3)->f_project_root;
    t1 = l2.payload.obj;
    vader_struct_vader_support_target$HostBodies_t* _a0_obj = (vader_struct_vader_support_target$HostBodies_t*) vader_gc_alloc(sizeof(vader_struct_vader_support_target$HostBodies_t));
    vader_obj_header_init(_a0_obj, 1416u);
    _a0_obj->f_target = t1;
    l10 = (void*) _a0_obj;
    l10 = vader_pipeline$prepare_evaluated_project_with(l0, l1, l9, vader_ref_box(l10));
    t2 = vader_support_diagnostics$any_error_diag(((vader_struct_vader_front_resolver$LoadedProject_t*) ((vader_struct_vader_pipeline$EvaluatedPipeline_t*) l10)->f_loaded)->f_diags);
    if (t2) {
        l6 = true;
    } else {
        l6 = vader_support_diagnostics$any_error_diag(((vader_struct_vader_pipeline$EvaluatedPipeline_t*) l10)->f_resolver_diags);
    }
    if (l6) {
        l6 = true;
    } else {
        l6 = vader_support_diagnostics$any_error_diag(((vader_struct_vader_pipeline$EvaluatedPipeline_t*) l10)->f_typecheck_diags);
    }
    if (l6) {
        vader_pipeline$bake_with_own_bodies(l3, l4, l5);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l11 = ((vader_struct_vader_pipeline$EvaluatedPipeline_t*) l10)->f_comptime_diags;
    l12 = ((vader_array_t*) l11)->length;
    l13 = INT64_C(0);
    while ((l13 < l12)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l11);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l14 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l13);
        if (((vader_struct_vader_support_diagnostics$Diagnostic_t*) l14)->f_severity == INT32_C(0)) {
            vader_array_push_ref((vader_array_t*) l5, l14);
        }
        l13 = (l13 + INT64_C(1));
    }
    vader_pipeline_comptime__vm$copy_baked_values(((vader_struct_vader_pipeline$EvaluatedPipeline_t*) l10)->f_evaluated, l4, l5);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_pipeline$bake_with_own_bodies(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_host_vader_support_profile$prof_begin(INT32_C(2));
    l3 = ((vader_struct_vader_front_comptime$EvaluatedProject_t*) l1)->f_typed;
    vader_pipeline_comptime__vm$resolve_vm_required_decls(l0, l3, l1, l2);
    vader_host_vader_support_profile$prof_end(INT32_C(2));
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_pipeline$bounds_verification_enabled(void) {
    bool t0;
    t0 = vader_support_opt__report$env_flag_set(940u);
    return t0;
}

static vader_string_t vader_pipeline$canonicalise(vader_string_t l0) {
    vader_string_t t0 = 0;
    vader_string_t t1 = 0;
    vader_string_t* gc_atom_roots[3] = { &l0, &t0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = std_path$as_string(l0);
    t1 = std_path$to_posix(t0);
    t0 = std_path$to_path(t1);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_pipeline$cfg_to_bytecode(void* l0, vader_string_t l1, void* l2, void* l3, void* l4) {
    void* l5 = NULL;
    void** gc_raw_roots[5] = { &l0, &l2, &l3, &l4, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l5 = vader_midir_pipeline$build_optimised_cfg(l0, l4, l3);
    vader_host_vader_support_profile$prof_begin(INT32_C(8));
    l5 = vader_emit_bytecode$emit_bytecode_from_cfg(l5, l1, l2);
    vader_host_vader_support_profile$prof_end(INT32_C(8));
    { void* __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_pipeline$collect_body_diags(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l9 = NULL;
    void* l11 = NULL;
    void* l14 = NULL;
    int64_t l5, l6, l12, l13;
    vader_string_t l7 = 0;
    vader_string_t l8 = 0;
    vader_string_t l10 = 0;
    bool t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l4, &l9, &l11, &l14 };
    vader_string_t* gc_atom_roots[3] = { &l7, &l8, &l10 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(216u, 0u, 13u, 1410u);
    l1 = (void*) _a0_arr;
    t0 = std_collections$is_empty__string__Any(((vader_struct_vader_front_typecheck$CheckResult_t*) l0)->f_all_modules);
    if (t0) {
        { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_vader_front_typecheck$CheckResult_t*) l0)->f_all_modules;
    l3 = ((vader_struct_std_collections$MutableMap__string__vader_front_typecheck_TypedProgram_t*) l2)->f_ekeys;
    l4 = ((vader_struct_std_collections$MutableMap__string__vader_front_typecheck_TypedProgram_t*) l2)->f_evals;
    l5 = INT64_C(0);
    l6 = ((vader_struct_std_collections$MutableMap__string__vader_front_typecheck_TypedProgram_t*) l2)->f_size;
    while ((l5 < l6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        t1 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l5];
        l7 = t1.payload.s;
        vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
        l2 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
        l8 = l7;
        l9 = l2;
        l10 = ((vader_struct_vader_front_resolver$ResolvedModule_t*) ((vader_struct_vader_front_typecheck$TypedProgram_t*) ((vader_struct_vader_front_typecheck$CheckResult_t*) l0)->f_typed)->f_resolved)->f_path;
        if (!(l8 == l10)) {
            l11 = ((vader_struct_vader_front_resolver$ResolvedModule_t*) ((vader_struct_vader_front_typecheck$TypedProgram_t*) l9)->f_resolved)->f_diags;
            l12 = ((vader_array_t*) l11)->length;
            l13 = INT64_C(0);
            while ((l13 < l12)) {
                vader_array_t* _a3_slotarr = ((vader_array_t*) l11);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                l14 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l13);
                vader_array_push_ref((vader_array_t*) l1, l14);
                l13 = (l13 + INT64_C(1));
            }
        }
        l5 = (l5 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_pipeline$dump_scope(void* l0, void* l1) {
    void* l2 = NULL;
    vader_string_t l3 = 0;
    vader_box_t l4 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_front_resolver$LoadedProject_t*) l1)->f_modules;
    l3 = ((vader_struct_vader_front_resolver$LoadedProject_t*) l1)->f_entry;
    l4 = std_collections$MutableMap$std_core$Index$at__string__Any(l2, l3);
    if (l4.tag == 1101u) {
        t0 = l4.payload.obj;
        l3 = ((vader_struct_vader_front_resolver$Module_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) t0)->f_module)->f_display_path;
        t0 = vader_pipeline$scope_or_entry(l0, l3);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((vader_struct_vader_front_resolver$LoadedProject_t*) l1)->f_entry;
    t0 = vader_pipeline$scope_or_entry(l0, l3);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_pipeline$entry_main_name(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    bool t0;
    vader_string_t t1 = 0;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_string_t* gc_atom_roots[3] = { &l1, &t1, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = std_collections$MutableMap$std_core$Index$at__string__Any(((vader_struct_vader_front_typecheck$TypedProject_t*) l0)->f_modules, l1);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return 0u; }
    }
    l2 = l3.payload.obj;
    t0 = std_collections$MutableMap$std_core$Contains$contains__string__Any(((vader_struct_vader_front_resolver$ResolvedModule_t*) ((vader_struct_vader_front_typecheck$TypedProgram_t*) l2)->f_resolved)->f_fn_overloads, 2298u);
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return 0u; }
    }
    t1 = ((vader_struct_vader_front_resolver$ResolvedModule_t*) ((vader_struct_vader_front_typecheck$TypedProgram_t*) l2)->f_resolved)->f_display_path;
    t2 = vader_core_types$mangle_module_id(t1);
    t1 = concat_2(t2, 277u);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

bool vader_pipeline$flush_build_diags(void* l0, void* l1) {
    void* l2 = NULL;
    int64_t t0;
    vader_string_t t1 = 0;
    bool t2;
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = std_core$$array$Add$add__vader_support_diagnostics_Diagnostic(l0, l1);
    t0 = ((vader_array_t*) l2)->length;
    if ((t0 > INT64_C(0))) {
        t1 = vader_support_diagnostics$dump_diagnostics_with_file(l2);
        std_io$eprintln__string(t1);
        t2 = vader_support_diagnostics$any_error_diag(l2);
        { bool __vret = !(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_support_diagnostics$any_error_diag(l2);
    { bool __vret = !(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_pipeline$gather_pipeline_diags(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    void* l5 = NULL;
    int64_t l2, l4;
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(216u, 0u, 13u, 1410u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_array_t*) ((vader_struct_vader_front_resolver$LoadedProject_t*) ((vader_struct_vader_pipeline$EvaluatedPipeline_t*) l0)->f_loaded)->f_diags)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (int64_t) l2);
    l1 = (void*) _a1_arr;
    l3 = ((vader_struct_vader_front_resolver$LoadedProject_t*) ((vader_struct_vader_pipeline$EvaluatedPipeline_t*) l0)->f_loaded)->f_diags;
    l2 = ((vader_array_t*) l3)->length;
    l4 = INT64_C(0);
    while ((l4 < l2)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l5 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        vader_array_push_ref((vader_array_t*) l1, l5);
        l4 = (l4 + INT64_C(1));
    }
    l3 = ((vader_struct_vader_pipeline$EvaluatedPipeline_t*) l0)->f_resolver_diags;
    l2 = ((vader_array_t*) l3)->length;
    l4 = INT64_C(0);
    while ((l4 < l2)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        l5 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l4);
        vader_array_push_ref((vader_array_t*) l1, l5);
        l4 = (l4 + INT64_C(1));
    }
    l3 = ((vader_struct_vader_pipeline$EvaluatedPipeline_t*) l0)->f_typecheck_diags;
    l2 = ((vader_array_t*) l3)->length;
    l4 = INT64_C(0);
    while ((l4 < l2)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        l5 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l4);
        vader_array_push_ref((vader_array_t*) l1, l5);
        l4 = (l4 + INT64_C(1));
    }
    l3 = ((vader_struct_vader_pipeline$EvaluatedPipeline_t*) l0)->f_comptime_diags;
    l2 = ((vader_array_t*) l3)->length;
    l4 = INT64_C(0);
    while ((l4 < l2)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        l5 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l4);
        vader_array_push_ref((vader_array_t*) l1, l5);
        l4 = (l4 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_pipeline$imports_header_path(vader_string_t l0) {
    vader_string_t t0 = 0;
    vader_string_t t1 = 0;
    vader_string_t* gc_atom_roots[3] = { &l0, &t0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = concat_2(l0, 415u);
    t1 = std_path$to_path(t0);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_pipeline$in_scope_diag_files(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l8 = NULL;
    int64_t l6, l7, l9, l10;
    vader_string_t l11 = 0;
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    bool t2;
    void* t3 = NULL;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l4, &l5, &l8, &t3 };
    vader_string_t* gc_atom_roots[2] = { &l11, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 0u, 335u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_struct_vader_front_resolver$LoadedProject_t*) l0)->f_modules;
    l4 = ((vader_struct_std_collections$MutableMap__string__vader_front_resolver_LoadedModule_t*) l3)->f_ekeys;
    l5 = ((vader_struct_std_collections$MutableMap__string__vader_front_resolver_LoadedModule_t*) l3)->f_evals;
    l6 = INT64_C(0);
    l7 = ((vader_struct_std_collections$MutableMap__string__vader_front_resolver_LoadedModule_t*) l3)->f_size;
    while ((l6 < l7)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        t0 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l6];
        t1 = t0.payload.s;
        vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
        l3 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l6);
        t1 = ((vader_struct_vader_front_resolver$Module_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l3)->f_module)->f_display_path;
        t2 = vader_support_text$module_in_scope(t1, l1);
        if (t2) {
            l8 = ((vader_struct_vader_front_resolver$Module_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l3)->f_module)->f_files;
            l9 = ((vader_array_t*) l8)->length;
            l10 = INT64_C(0);
            while ((l10 < l9)) {
                vader_array_t* _a3_slotarr = ((vader_array_t*) l8);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                t3 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l10);
                l11 = ((vader_struct_vader_front_resolver$SourceFile_t*) t3)->f_path;
                vader_array_push_scalar((vader_array_t*) l2, vader_box_string(335u, l11));
                l10 = (l10 + INT64_C(1));
            }
        }
        l6 = (l6 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_pipeline$lower_to_entry_from(void* l0, bool l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    vader_string_t l3 = 0;
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[8] = { &l0, &l2, &l4, &l5, &l6, &l7, &l8, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 8u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_pipeline$EvaluatedPipeline_t*) l0)->f_typed;
    l3 = ((vader_struct_vader_front_resolver$LoadedProject_t*) ((vader_struct_vader_pipeline$EvaluatedPipeline_t*) l0)->f_loaded)->f_entry;
    l3 = vader_pipeline$entry_main_name(l2, l3);
    l2 = vader_pipeline$gather_pipeline_diags(l0);
    vader_array_t* _a0_arr = vader_array_new(216u, 0u, 13u, 1410u);
    l4 = (void*) _a0_arr;
    vader_host_vader_support_profile$prof_begin(INT32_C(3));
    t0 = vader_support_diagnostics$any_error_diag(l2);
    if (t0) {
        l5 = vader_lower_ir$new_lowered_project();
    } else {
        l6 = ((vader_struct_vader_pipeline$EvaluatedPipeline_t*) l0)->f_loaded;
        l7 = ((vader_struct_vader_pipeline$EvaluatedPipeline_t*) l0)->f_typed;
        l8 = ((vader_struct_vader_pipeline$EvaluatedPipeline_t*) l0)->f_evaluated;
        l5 = vader_lower$lower_project(l6, l7, l8, l4);
    }
    vader_host_vader_support_profile$prof_end(INT32_C(3));
    if (l1) {
        vader_lower_ir$verify_lowered(l5, 2291u, l4);
    }
    l6 = ((vader_struct_vader_pipeline$EvaluatedPipeline_t*) l0)->f_loaded;
    vader_array_t* _a1_arr = vader_array_new(22u, 0u, 0u, 335u);
    l7 = (void*) _a1_arr;
    l8 = ((vader_struct_vader_pipeline$EvaluatedPipeline_t*) l0)->f_loaded;
    l7 = vader_pipeline$dump_scope(l7, l8);
    l6 = vader_pipeline$in_scope_diag_files(l6, l7);
    vader_struct_vader_pipeline$LoweredEntry_t* _a2_obj = (vader_struct_vader_pipeline$LoweredEntry_t*) vader_gc_alloc(sizeof(vader_struct_vader_pipeline$LoweredEntry_t));
    vader_obj_header_init(_a2_obj, 1405u);
    _a2_obj->f_lowered = l5;
    _a2_obj->f_entry = l3;
    _a2_obj->f_pre_diags = l2;
    _a2_obj->f_lower_diags = l4;
    _a2_obj->f_in_scope_files = l6;
    t1 = (void*) _a2_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_pipeline$lower_to_entry_with(vader_string_t l0, void* l1, vader_box_t l2, vader_box_t l3, bool l4) {
    void* t0 = NULL;
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l2, &l3 };
    void** gc_raw_roots[3] = { &l1, &t0, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_pipeline$prepare_evaluated_project_with(l0, l1, l2, l3);
    t1 = vader_pipeline$lower_to_entry_from(t0, l4);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_pipeline$marks_proven_bounds(void* l0) {
    vader_string_t t0 = 0;
    bool t1, t2;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_pipeline$BuildRequest_t*) l0)->f_emit;
    if (t0 != 1677u) {
        t1 = ((vader_struct_vader_pipeline$BuildRequest_t*) l0)->f_release;
        t2 = vader_pipeline$proves_bounds(t1);
        { bool __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static vader_string_t vader_pipeline$module_name_from_file(vader_string_t l0) {
    vader_string_t t0 = 0;
    vader_string_t t1 = 0;
    vader_string_t* gc_atom_roots[3] = { &l0, &t0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = vader_pipeline$canonicalise(l0);
    t1 = std_path$name(t0);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_pipeline$native_c_options(vader_string_t l0) {
    void* l1 = NULL;
    bool l2;
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 0u, 335u);
    l1 = (void*) _a0_arr;
    l2 = vader_pipeline$bounds_verification_enabled();
    vader_struct_vader_emit_c$CEmitOptions_t* _a1_obj = (vader_struct_vader_emit_c$CEmitOptions_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c$CEmitOptions_t));
    vader_obj_header_init(_a1_obj, 940u);
    _a1_obj->f_entry_mangled = l0;
    _a1_obj->f_split = false;
    _a1_obj->f_atom_universe = l1;
    _a1_obj->f_verify_bounds = l2;
    _a1_obj->f_library_units = false;
    t0 = (void*) _a1_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_pipeline$prepare_cfg_bytecode_from(void* l0, vader_string_t l1, bool l2, bool l3, bool l4) {
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    vader_string_t l9 = 0;
    void* t0 = NULL;
    void** gc_raw_roots[6] = { &l0, &l5, &l6, &l7, &l8, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_host_vader_support_profile$prof_begin(INT32_C(4));
    l5 = vader_lower_dce$prune_unreachable_fns(((vader_struct_vader_pipeline$LoweredEntry_t*) l0)->f_lowered, false);
    vader_host_vader_support_profile$prof_end(INT32_C(4));
    vader_array_t* _a0_arr = vader_array_new(216u, 0u, 13u, 1410u);
    l6 = (void*) _a0_arr;
    if (l3) {
        vader_lower_ir$verify_lowered(l5, 2473u, l6);
    }
    vader_array_t* _a1_arr = vader_array_new(22u, 0u, 0u, 335u);
    l7 = (void*) _a1_arr;
    vader_struct_vader_emit_bytecode$EmitOptions_t* _a2_obj = (vader_struct_vader_emit_bytecode$EmitOptions_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$EmitOptions_t));
    vader_obj_header_init(_a2_obj, 930u);
    _a2_obj->f_optimize = true;
    _a2_obj->f_keep_mangles = l7;
    _a2_obj->f_want_debug = l2;
    l7 = (void*) _a2_obj;
    vader_struct_vader_midir_pipeline$CfgPassOptions_t* _a3_obj = (vader_struct_vader_midir_pipeline$CfgPassOptions_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_pipeline$CfgPassOptions_t));
    vader_obj_header_init(_a3_obj, 1390u);
    _a3_obj->f_verify = l3;
    _a3_obj->f_prove_bounds = l4;
    _a3_obj->f_instrumented = true;
    _a3_obj->f_plain_returns = false;
    l8 = (void*) _a3_obj;
    l9 = vader_pipeline$module_name_from_file(l1);
    l5 = vader_pipeline$cfg_to_bytecode(l5, l9, l7, l6, l8);
    l6 = std_core$$array$Add$add__vader_support_diagnostics_Diagnostic(((vader_struct_vader_pipeline$LoweredEntry_t*) l0)->f_lower_diags, l6);
    l9 = ((vader_struct_vader_pipeline$LoweredEntry_t*) l0)->f_entry;
    l7 = ((vader_struct_vader_pipeline$LoweredEntry_t*) l0)->f_pre_diags;
    l8 = ((vader_struct_vader_pipeline$LoweredEntry_t*) l0)->f_in_scope_files;
    vader_struct_vader_pipeline$CfgBytecode_t* _a4_obj = (vader_struct_vader_pipeline$CfgBytecode_t*) vader_gc_alloc(sizeof(vader_struct_vader_pipeline$CfgBytecode_t));
    vader_obj_header_init(_a4_obj, 1403u);
    _a4_obj->f_entry = l9;
    _a4_obj->f_pre_diags = l7;
    _a4_obj->f_lower_diags = l6;
    _a4_obj->f_in_scope_files = l8;
    _a4_obj->f_module = l5;
    t0 = (void*) _a4_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_pipeline$prepare_cfg_bytecode_with(vader_string_t l0, bool l1, void* l2, vader_box_t l3, vader_box_t l4, bool l5, bool l6) {
    void* t0 = NULL;
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l3, &l4 };
    void** gc_raw_roots[3] = { &l2, &t0, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_pipeline$lower_to_entry_with(l0, l2, l3, l4, l5);
    t1 = vader_pipeline$prepare_cfg_bytecode_from(t0, l0, l1, l5, l6);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_pipeline$prepare_evaluated_project_with(vader_string_t l0, void* l1, vader_box_t l2, vader_box_t l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l10 = NULL;
    bool l9;
    vader_string_t t0 = 0;
    bool t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[2] = { &l2, &l3 };
    void** gc_raw_roots[8] = { &l1, &l4, &l5, &l6, &l7, &l8, &l10, &t2 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_host_vader_support_profile$prof_begin(INT32_C(0));
    t0 = std_path$as_string(l0);
    l4 = vader_front_resolver$load_project(t0, l1, l2, l3);
    vader_host_vader_support_profile$prof_end(INT32_C(0));
    vader_array_t* _a0_arr = vader_array_new(216u, 0u, 13u, 1410u);
    l5 = (void*) _a0_arr;
    vader_host_vader_support_profile$prof_begin(INT32_C(1));
    l6 = vader_pipeline_check$check_project(l4, l5, false);
    l7 = vader_pipeline$collect_body_diags(((vader_struct_vader_pipeline_check$CheckedProject_t*) l6)->f_result);
    vader_host_vader_support_profile$prof_end(INT32_C(1));
    vader_array_t* _a1_arr = vader_array_new(216u, 0u, 13u, 1410u);
    l8 = (void*) _a1_arr;
    vader_host_vader_support_profile$prof_begin(INT32_C(2));
    l6 = vader_pipeline_check$evaluate_checked(l4, l6, l8);
    vader_host_vader_support_profile$prof_end(INT32_C(2));
    t1 = vader_support_diagnostics$any_error_diag(((vader_struct_vader_front_resolver$LoadedProject_t*) l4)->f_diags);
    if (!(t1)) {
        t1 = vader_support_diagnostics$any_error_diag(l7);
        l9 = !(t1);
    } else {
        l9 = false;
    }
    if (l9) {
        t1 = vader_support_diagnostics$any_error_diag(l5);
        l9 = !(t1);
    } else {
        l9 = false;
    }
    if (l9) {
        t1 = vader_support_diagnostics$any_error_diag(l8);
        if (t1) {
            l10 = ((vader_struct_vader_front_comptime$EvaluatedProject_t*) l6)->f_typed;
            vader_struct_vader_pipeline$EvaluatedPipeline_t* _a2_obj = (vader_struct_vader_pipeline$EvaluatedPipeline_t*) vader_gc_alloc(sizeof(vader_struct_vader_pipeline$EvaluatedPipeline_t));
            vader_obj_header_init(_a2_obj, 1404u);
            _a2_obj->f_loaded = l4;
            _a2_obj->f_typed = l10;
            _a2_obj->f_evaluated = l6;
            _a2_obj->f_resolver_diags = l7;
            _a2_obj->f_typecheck_diags = l5;
            _a2_obj->f_comptime_diags = l8;
            t2 = (void*) _a2_obj;
            { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_pipeline$bake_deferred_values(l0, l1, l3, l4, l6, l8);
        l10 = ((vader_struct_vader_front_comptime$EvaluatedProject_t*) l6)->f_typed;
        vader_struct_vader_pipeline$EvaluatedPipeline_t* _a3_obj = (vader_struct_vader_pipeline$EvaluatedPipeline_t*) vader_gc_alloc(sizeof(vader_struct_vader_pipeline$EvaluatedPipeline_t));
        vader_obj_header_init(_a3_obj, 1404u);
        _a3_obj->f_loaded = l4;
        _a3_obj->f_typed = l10;
        _a3_obj->f_evaluated = l6;
        _a3_obj->f_resolver_diags = l7;
        _a3_obj->f_typecheck_diags = l5;
        _a3_obj->f_comptime_diags = l8;
        t2 = (void*) _a3_obj;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l10 = ((vader_struct_vader_front_comptime$EvaluatedProject_t*) l6)->f_typed;
    vader_struct_vader_pipeline$EvaluatedPipeline_t* _a4_obj = (vader_struct_vader_pipeline$EvaluatedPipeline_t*) vader_gc_alloc(sizeof(vader_struct_vader_pipeline$EvaluatedPipeline_t));
    vader_obj_header_init(_a4_obj, 1404u);
    _a4_obj->f_loaded = l4;
    _a4_obj->f_typed = l10;
    _a4_obj->f_evaluated = l6;
    _a4_obj->f_resolver_diags = l7;
    _a4_obj->f_typecheck_diags = l5;
    _a4_obj->f_comptime_diags = l8;
    t2 = (void*) _a4_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_pipeline$prepare_program(vader_string_t l0, void* l1) {
    bool l2, l6, l7;
    void* l3 = NULL;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l4, &l5 };
    void** gc_raw_roots[3] = { &l1, &l3, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_pipeline$wants_debug(l1);
    l3 = ((vader_struct_vader_pipeline$BuildRequest_t*) l1)->f_include_paths;
    l4 = ((vader_struct_vader_pipeline$BuildRequest_t*) l1)->f_project_root;
    l5 = ((vader_struct_vader_pipeline$BuildRequest_t*) l1)->f_target;
    l6 = ((vader_struct_vader_pipeline$BuildRequest_t*) l1)->f_verify;
    l7 = vader_pipeline$marks_proven_bounds(l1);
    t0 = vader_pipeline$prepare_cfg_bytecode_with(l0, l2, l3, l4, l5, l6, l7);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_pipeline$proves_bounds(bool l0) {
    bool t0;
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    t0 = vader_pipeline$bounds_verification_enabled();
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_pipeline$scope_or_entry(void* l0, vader_string_t l1) {
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[2] = { &l0, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) l0)->length;
    if (!((t0 > INT64_C(0)))) {
        vader_array_t* _a0_arr = vader_array_new(22u, 1u, 0u, 335u);
        vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 0u] = vader_box_string(335u, l1);
        t1 = (void*) _a0_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_pipeline$split_globals_path(vader_string_t l0) {
    vader_string_t t0 = 0;
    vader_string_t t1 = 0;
    vader_string_t* gc_atom_roots[3] = { &l0, &t0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = concat_2(l0, 433u);
    t1 = std_path$to_path(t0);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_pipeline$split_header_name(vader_string_t l0) {
    vader_string_t t0 = 0;
    vader_string_t t1 = 0;
    vader_string_t* gc_atom_roots[3] = { &l0, &t0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = vader_pipeline$canonicalise(l0);
    t1 = std_path$filename(t0);
    t0 = concat_2(t1, 434u);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_pipeline$split_header_path(vader_string_t l0) {
    vader_string_t t0 = 0;
    vader_string_t t1 = 0;
    vader_string_t* gc_atom_roots[3] = { &l0, &t0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = concat_2(l0, 434u);
    t1 = std_path$to_path(t0);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_pipeline$split_program(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    vader_string_t l4 = 0;
    vader_string_t t0 = 0;
    void* t1 = NULL;
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &t1 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l4, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_pipeline$CfgBytecode_t*) l0)->f_module;
    t0 = ((vader_struct_vader_pipeline$CfgBytecode_t*) l0)->f_entry;
    l3 = vader_pipeline$native_c_options(t0);
    l4 = vader_pipeline$split_header_name(l1);
    t1 = vader_emit_c$emit_c_split(l2, l3, l4);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_pipeline$unit_path(vader_string_t l0, vader_string_t l1, vader_string_t l2) {
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    vader_string_t t0 = 0;
    vader_string_t t1 = 0;
    vader_string_t* gc_atom_roots[7] = { &l0, &l1, &l2, &l3, &l4, &t0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 7u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l1 == 0u) {
        t0 = concat_4(l0, 385u, l2, 408u);
        t1 = std_path$to_path(t0);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = std_path$parent(l0);
    l4 = std_path$filename(l0);
    t0 = concat_8(l3, 440u, l1, 440u, l4, 399u, l2, 408u);
    t1 = std_path$to_path(t0);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_pipeline$wants_debug(void* l0) {
    vader_string_t t0;
    bool t1;
    t0 = ((vader_struct_vader_pipeline$BuildRequest_t*) l0)->f_emit;
    if (t0 != 1677u) {
        t1 = ((vader_struct_vader_pipeline$BuildRequest_t*) l0)->f_release;
        return !(t1);
    }
    return false;
}

static int32_t vader_pipeline$write_out(vader_string_t l0, vader_string_t l1) {
    vader_box_t l2 = vader_box_null();
    vader_string_t l3 = 0;
    vader_string_t t0 = 0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[1] = { &t1 };
    vader_string_t* gc_atom_roots[4] = { &l0, &l1, &l3, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = std_path$as_string(l0);
    l2 = std_io$write_file_string(t0, l1);
    if (!(l2.tag == 624u)) {
        { vader_gc_top = gc_frame.prev; return INT32_C(0); }
    }
    t1 = l2.payload.obj;
    l3 = std_io$IOError$std_core$Error$message(t1);
    t0 = concat_4(2843u, l0, 1311u, l3);
    std_io$eprintln__string(t0);
    { vader_gc_top = gc_frame.prev; return INT32_C(1); }
}

int32_t vader_pipeline$write_split_c(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    int32_t t0;
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_pipeline$split_program(l0, l1);
    t0 = vader_pipeline$write_split_files(l1, l2);
    { int32_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_pipeline$write_split_files(vader_string_t l0, void* l1) {
    vader_string_t l2 = 0;
    vader_string_t l3 = 0;
    vader_string_t l6 = 0;
    int64_t l4, l5;
    int32_t t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[1] = { &l1 };
    vader_string_t* gc_atom_roots[4] = { &l0, &l2, &l3, &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_pipeline$split_header_path(l0);
    l3 = ((vader_struct_vader_emit_c$CProgram_t*) l1)->f_header;
    t0 = vader_pipeline$write_out(l2, l3);
    if (t0 != INT32_C(0)) {
        { vader_gc_top = gc_frame.prev; return INT32_C(1); }
    }
    l2 = vader_pipeline$imports_header_path(l0);
    l3 = ((vader_struct_vader_emit_c$CProgram_t*) l1)->f_imports;
    t0 = vader_pipeline$write_out(l2, l3);
    if (t0 != INT32_C(0)) {
        { vader_gc_top = gc_frame.prev; return INT32_C(1); }
    }
    l2 = vader_pipeline$split_globals_path(l0);
    l3 = ((vader_struct_vader_emit_c$CProgram_t*) l1)->f_globals;
    t0 = vader_pipeline$write_out(l2, l3);
    if (t0 != INT32_C(0)) {
        { vader_gc_top = gc_frame.prev; return INT32_C(1); }
    }
    l4 = INT64_C(0);
    l5 = ((vader_array_t*) ((vader_struct_vader_emit_c$CProgram_t*) l1)->f_units)->length;
    while ((l4 < l5)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_c$CProgram_t*) l1)->f_unit_names);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t1 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l4];
        l2 = t1.payload.s;
        l3 = vader_pipeline$unit_path(l0, 0u, l2);
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_c$CProgram_t*) l1)->f_units);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        t1 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l4];
        l6 = t1.payload.s;
        t0 = vader_pipeline$write_out(l3, l6);
        if (t0 != INT32_C(0)) {
            { vader_gc_top = gc_frame.prev; return INT32_C(1); }
        }
        l4 = (l4 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return INT32_C(0); }
}
