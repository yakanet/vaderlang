#include "bootstrap.split.h"

static void* vader_pipeline_check$active_stages(uint8_t l0);
static void* vader_pipeline_check$assemble_typed_project(void* l0);
static void* vader_pipeline_check$check_stages(void);
static void* vader_pipeline_check$checked_modules(void* l0);
static void* vader_pipeline_check$keys_per(uint8_t l0, void* l1);
static void* vader_pipeline_check$plan_checks(void* l0, void* l1);
static void* vader_pipeline_check$run_checks(void* l0, void* l1);

vader_string_t vader_pipeline_check$CheckSpec$toolchain_stage$Placed$precedes(void* l0, void* l1) {
    return 0u;
}

vader_string_t vader_pipeline_check$CheckSpec$toolchain_stage$Placed$stage_name(void* l0) {
    vader_string_t t0;
    t0 = ((vader_struct_vader_pipeline_check$CheckSpec_t*) l0)->f_name;
    return t0;
}

void* vader_pipeline_check$DeadCode$toolchain_stage$Stage$describe(void* l0) {
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_pipeline_check$CheckSpec_t* _a0_obj = (vader_struct_vader_pipeline_check$CheckSpec_t*) vader_gc_alloc(sizeof(vader_struct_vader_pipeline_check$CheckSpec_t));
    vader_obj_header_init(_a0_obj, 1803u);
    _a0_obj->f_name = 2124u;
    _a0_obj->f_purpose = (uint8_t) 0;
    _a0_obj->f_needs = (uint8_t) 1;
    _a0_obj->f_per = (uint8_t) 1;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_pipeline_check$DeadCode$toolchain_stage$Stage$run(void* l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    vader_string_t l3 = 0;
    vader_box_t l4 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l5, &l6, &l7, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_front_resolver$LoadedProject_t*) ((vader_struct_vader_pipeline_check$CheckInput_t*) ((vader_struct_vader_pipeline_check$Checked_t*) l1)->f_program)->f_project)->f_modules;
    l3 = ((vader_struct_vader_pipeline_check$StageKey_t*) ((vader_struct_vader_pipeline_check$Checked_t*) l1)->f_key)->f_module;
    l4 = std_collections$Map$std_core$Index$at__string__Any(l2, l3);
    if (l4.tag == 0u) {
        vader_array_t* _a0_arr = vader_array_new(79u, 0u, 13u, 1052u);
        t0 = (void*) _a0_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = l4.payload.obj;
    vader_array_t* _a1_arr = vader_array_new(79u, 0u, 13u, 1052u);
    l5 = (void*) _a1_arr;
    l6 = vader_front_resolver$concat_file_decls(((vader_struct_vader_front_resolver$Module_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l2)->f_module)->f_files);
    l3 = ((vader_struct_vader_front_resolver$Module_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l2)->f_module)->f_module_name;
    l7 = ((vader_struct_vader_front_resolver$LoadedModule_t*) l2)->f_discarded_bodies;
    l2 = vader_front_resolver$decorators_above_module(((vader_struct_vader_front_resolver$Module_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l2)->f_module)->f_files);
    vader_front_dead__code$check_dead_code(l6, l3, l5, l7, l2);
    { void* __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_pipeline_check$DeepCopies$toolchain_stage$Stage$describe(void* l0) {
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_pipeline_check$CheckSpec_t* _a0_obj = (vader_struct_vader_pipeline_check$CheckSpec_t*) vader_gc_alloc(sizeof(vader_struct_vader_pipeline_check$CheckSpec_t));
    vader_obj_header_init(_a0_obj, 1803u);
    _a0_obj->f_name = 2132u;
    _a0_obj->f_purpose = (uint8_t) 0;
    _a0_obj->f_needs = (uint8_t) 1;
    _a0_obj->f_per = (uint8_t) 0;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_pipeline_check$DeepCopies$toolchain_stage$Stage$run(void* l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    vader_box_t l3 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_pipeline_check$CheckInput_t*) ((vader_struct_vader_pipeline_check$Checked_t*) l1)->f_program)->f_effects;
    if (l3.tag == 0u) {
        vader_array_t* _a0_arr = vader_array_new(79u, 0u, 13u, 1052u);
        t0 = (void*) _a0_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = l3.payload.obj;
    l3 = ((vader_struct_vader_pipeline_check$CheckInput_t*) ((vader_struct_vader_pipeline_check$Checked_t*) l1)->f_program)->f_result;
    if (l3.tag == 0u) {
        vader_array_t* _a1_arr = vader_array_new(79u, 0u, 13u, 1052u);
        t0 = (void*) _a1_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = l3.payload.obj;
    t0 = vader_front_effects$deep_copy_diagnostics(l2, l4);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_pipeline_check$Frozen$toolchain_stage$Stage$describe(void* l0) {
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_pipeline_check$CheckSpec_t* _a0_obj = (vader_struct_vader_pipeline_check$CheckSpec_t*) vader_gc_alloc(sizeof(vader_struct_vader_pipeline_check$CheckSpec_t));
    vader_obj_header_init(_a0_obj, 1803u);
    _a0_obj->f_name = 2353u;
    _a0_obj->f_purpose = (uint8_t) 0;
    _a0_obj->f_needs = (uint8_t) 1;
    _a0_obj->f_per = (uint8_t) 0;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_pipeline_check$Frozen$toolchain_stage$Stage$run(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    void* t0 = NULL;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[4] = { &l0, &l1, &t0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_pipeline_check$CheckInput_t*) ((vader_struct_vader_pipeline_check$Checked_t*) l1)->f_program)->f_effects;
    if (l2.tag == 0u) {
        vader_array_t* _a0_arr = vader_array_new(79u, 0u, 13u, 1052u);
        t0 = (void*) _a0_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l2.payload.obj;
    t1 = vader_front_effects$frozen_diagnostics(t0);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_pipeline_check$TaskFaults$toolchain_stage$Stage$describe(void* l0) {
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_pipeline_check$CheckSpec_t* _a0_obj = (vader_struct_vader_pipeline_check$CheckSpec_t*) vader_gc_alloc(sizeof(vader_struct_vader_pipeline_check$CheckSpec_t));
    vader_obj_header_init(_a0_obj, 1803u);
    _a0_obj->f_name = 3005u;
    _a0_obj->f_purpose = (uint8_t) 0;
    _a0_obj->f_needs = (uint8_t) 1;
    _a0_obj->f_per = (uint8_t) 0;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_pipeline_check$TaskFaults$toolchain_stage$Stage$run(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    void* t0 = NULL;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[4] = { &l0, &l1, &t0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_pipeline_check$CheckInput_t*) ((vader_struct_vader_pipeline_check$Checked_t*) l1)->f_program)->f_effects;
    if (l2.tag == 0u) {
        vader_array_t* _a0_arr = vader_array_new(79u, 0u, 13u, 1052u);
        t0 = (void*) _a0_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l2.payload.obj;
    t1 = vader_front_effects$task_diagnostics(t0);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_pipeline_check$UnusedExports$toolchain_stage$Stage$describe(void* l0) {
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_pipeline_check$CheckSpec_t* _a0_obj = (vader_struct_vader_pipeline_check$CheckSpec_t*) vader_gc_alloc(sizeof(vader_struct_vader_pipeline_check$CheckSpec_t));
    vader_obj_header_init(_a0_obj, 1803u);
    _a0_obj->f_name = 3180u;
    _a0_obj->f_purpose = (uint8_t) 1;
    _a0_obj->f_needs = (uint8_t) 0;
    _a0_obj->f_per = (uint8_t) 0;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_pipeline_check$UnusedExports$toolchain_stage$Stage$run(void* l0, void* l1) {
    void* t0 = NULL;
    void* t1 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &t0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_front_dead__code$dead_exports_of_project(((vader_struct_vader_pipeline_check$CheckInput_t*) ((vader_struct_vader_pipeline_check$Checked_t*) l1)->f_program)->f_project);
    t1 = vader_front_dead__code$dead_export_diags(t0);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_pipeline_check$UnusedImports$toolchain_stage$Stage$describe(void* l0) {
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_pipeline_check$CheckSpec_t* _a0_obj = (vader_struct_vader_pipeline_check$CheckSpec_t*) vader_gc_alloc(sizeof(vader_struct_vader_pipeline_check$CheckSpec_t));
    vader_obj_header_init(_a0_obj, 1803u);
    _a0_obj->f_name = 3181u;
    _a0_obj->f_purpose = (uint8_t) 0;
    _a0_obj->f_needs = (uint8_t) 1;
    _a0_obj->f_per = (uint8_t) 0;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_pipeline_check$UnusedImports$toolchain_stage$Stage$run(void* l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    vader_box_t l3 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_pipeline_check$CheckInput_t*) ((vader_struct_vader_pipeline_check$Checked_t*) l1)->f_program)->f_result;
    if (l3.tag == 0u) {
        vader_array_t* _a0_arr = vader_array_new(79u, 0u, 13u, 1052u);
        t0 = (void*) _a0_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = l3.payload.obj;
    vader_array_t* _a1_arr = vader_array_new(79u, 0u, 13u, 1052u);
    l4 = (void*) _a1_arr;
    vader_front_dead__code$check_unused_imports(((vader_struct_vader_pipeline_check$CheckInput_t*) ((vader_struct_vader_pipeline_check$Checked_t*) l1)->f_program)->f_project, l2, l4);
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_pipeline_check$Widening$toolchain_stage$Stage$describe(void* l0) {
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_pipeline_check$CheckSpec_t* _a0_obj = (vader_struct_vader_pipeline_check$CheckSpec_t*) vader_gc_alloc(sizeof(vader_struct_vader_pipeline_check$CheckSpec_t));
    vader_obj_header_init(_a0_obj, 1803u);
    _a0_obj->f_name = 3390u;
    _a0_obj->f_purpose = (uint8_t) 0;
    _a0_obj->f_needs = (uint8_t) 1;
    _a0_obj->f_per = (uint8_t) 0;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_pipeline_check$Widening$toolchain_stage$Stage$run(void* l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    vader_box_t l3 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_pipeline_check$CheckInput_t*) ((vader_struct_vader_pipeline_check$Checked_t*) l1)->f_program)->f_effects;
    if (l3.tag == 0u) {
        vader_array_t* _a0_arr = vader_array_new(79u, 0u, 13u, 1052u);
        t0 = (void*) _a0_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = l3.payload.obj;
    l3 = ((vader_struct_vader_pipeline_check$CheckInput_t*) ((vader_struct_vader_pipeline_check$Checked_t*) l1)->f_program)->f_result;
    if (l3.tag == 0u) {
        vader_array_t* _a1_arr = vader_array_new(79u, 0u, 13u, 1052u);
        t0 = (void*) _a1_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = l3.payload.obj;
    t0 = vader_front_effects$widening_diagnostics(l2, l4);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_pipeline_check$active_stages(uint8_t l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    int64_t l4, l5;
    vader_box_t l6 = vader_box_null(), l7 = vader_box_null();
    bool t0;
    vader_box_t* gc_roots[2] = { &l6, &l7 };
    void** gc_raw_roots[3] = { &l1, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_pipeline_check$check_stages();
    vader_struct___lambda_env_vader_pipeline_check_1_t* _a0_obj = (vader_struct___lambda_env_vader_pipeline_check_1_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_pipeline_check_1_t));
    vader_obj_header_init(_a0_obj, 732u);
    _a0_obj->f_cap_0 = l0;
    l2 = (void*) _a0_obj;
    vader_array_t* _a1_arr = vader_array_new(34u, 0u, 0u, 550u);
    l3 = (void*) _a1_arr;
    l4 = vader_array_length(((vader_array_t*) l1));
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l6 = vader_array_ref_load_box(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l5);
        t0 = __lambda_vader_pipeline_check_0(l2, l6);
        if (t0) {
            l7 = l6;
            vader_array_push((vader_array_t*) l3, l7);
        }
        l5 = (l5 + INT64_C(1));
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_pipeline_check$assemble_typed_project(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l5 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    vader_string_t l4 = 0;
    vader_string_t l8 = 0;
    int64_t l6, l7;
    bool t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l5, &l9, &l10, &l11 };
    vader_string_t* gc_atom_roots[2] = { &l4, &l8 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_front_typecheck$new_typed_project(((vader_struct_vader_front_effects$EffectSummary_t*) ((vader_struct_vader_pipeline_check$CheckedProject_t*) l0)->f_effects)->f_fresh);
    l2 = ((vader_struct_vader_pipeline_check$CheckedProject_t*) l0)->f_result;
    l3 = ((vader_struct_vader_front_typecheck$TypedProject_t*) l1)->f_modules;
    l4 = ((vader_struct_vader_front_resolver$ResolvedModule_t*) ((vader_struct_vader_front_typecheck$TypedProgram_t*) ((vader_struct_vader_front_typecheck$CheckResult_t*) l2)->f_typed)->f_resolved)->f_path;
    l5 = ((vader_struct_vader_front_typecheck$CheckResult_t*) l2)->f_typed;
    std_collections$Map$std_core$IndexSet$set_at__string__Any(l3, l4, vader_ref_box(l5));
    t0 = std_collections$is_empty__string__Any(((vader_struct_vader_front_typecheck$CheckResult_t*) l2)->f_all_modules);
    if (t0) {
        l9 = ((vader_struct_vader_front_typecheck$CheckResult_t*) l2)->f_others;
        l6 = vader_array_length(((vader_array_t*) l9));
        l7 = INT64_C(0);
        while ((l7 < l6)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l9);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            l10 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l7);
            l11 = ((vader_struct_vader_front_typecheck$TypedProject_t*) l1)->f_modules;
            l8 = ((vader_struct_vader_front_resolver$ResolvedModule_t*) ((vader_struct_vader_front_typecheck$TypedProgram_t*) l10)->f_resolved)->f_path;
            std_collections$Map$std_core$IndexSet$set_at__string__Any(l11, l8, vader_ref_box(l10));
            l7 = (l7 + INT64_C(1));
        }
        { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_vader_front_typecheck$CheckResult_t*) l2)->f_all_modules;
    l3 = ((vader_struct_std_collections$Map__string__vader_front_typecheck_TypedProgram_t*) l2)->f_ekeys;
    l5 = ((vader_struct_std_collections$Map__string__vader_front_typecheck_TypedProgram_t*) l2)->f_evals;
    l6 = INT64_C(0);
    l7 = ((vader_struct_std_collections$Map__string__vader_front_typecheck_TypedProgram_t*) l2)->f_size;
    while ((l6 < l7)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        t1 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l6];
        l4 = t1.payload.s;
        vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
        l2 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l6);
        l8 = l4;
        l9 = l2;
        std_collections$Map$std_core$IndexSet$set_at__string__Any(((vader_struct_vader_front_typecheck$TypedProject_t*) l1)->f_modules, l8, vader_ref_box(l9));
        l6 = (l6 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_pipeline_check$check_project(void* l0, void* l1, bool l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* t0 = NULL;
    void* t1 = NULL;
    void** gc_raw_roots[7] = { &l0, &l1, &l3, &l4, &l5, &t0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 7u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_front_typecheck$check_project_with_bodies(l0, l1, l2);
    l4 = vader_front_effects$summarise_effects(l0, l3);
    vader_struct_vader_pipeline_check$CheckInput_t* _a0_obj = (vader_struct_vader_pipeline_check$CheckInput_t*) vader_gc_alloc(sizeof(vader_struct_vader_pipeline_check$CheckInput_t));
    vader_obj_header_init(_a0_obj, 1802u);
    _a0_obj->f_project = l0;
    _a0_obj->f_result = vader_ref_box(l3);
    _a0_obj->f_effects = vader_ref_box(l4);
    l5 = (void*) _a0_obj;
    t0 = vader_pipeline_check$active_stages((uint8_t) 0);
    t1 = vader_pipeline_check$plan_checks(t0, l5);
    l5 = vader_pipeline_check$run_checks(t1, l5);
    vader_array_push_all((vader_array_t*) l1, (vader_array_t*) l5);
    vader_struct_vader_pipeline_check$CheckedProject_t* _a1_obj = (vader_struct_vader_pipeline_check$CheckedProject_t*) vader_gc_alloc(sizeof(vader_struct_vader_pipeline_check$CheckedProject_t));
    vader_obj_header_init(_a1_obj, 1805u);
    _a1_obj->f_result = l3;
    _a1_obj->f_effects = l4;
    t0 = (void*) _a1_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_pipeline_check$check_stages(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 8u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = (void*) &vader_data_97;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT64_C(0));
    t0 = (void*) &vader_data_98;
    vader_array_t* _a1_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    l1 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) INT64_C(0));
    t0 = (void*) &vader_data_99;
    vader_array_t* _a2_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    l2 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) INT64_C(0));
    t0 = (void*) &vader_data_100;
    vader_array_t* _a3_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
    l3 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) INT64_C(0));
    t0 = (void*) &vader_data_101;
    vader_array_t* _a4_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
    l4 = vader_array_ref_load_obj(_a4_slotarr->buf, vader_array_offset(_a4_slotarr) + (size_t) INT64_C(0));
    t0 = (void*) &vader_data_102;
    vader_array_t* _a5_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    l5 = vader_array_ref_load_obj(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) INT64_C(0));
    t0 = (void*) &vader_data_103;
    vader_array_t* _a6_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
    l6 = vader_array_ref_load_obj(_a6_slotarr->buf, vader_array_offset(_a6_slotarr) + (size_t) INT64_C(0));
    vader_array_t* _a7_arr = vader_array_new(34u, 7u, 0u, 550u);
    vader_array_box_slots(_a7_arr->buf)[vader_array_offset(_a7_arr) + 6u] = vader_ref_box(l6);
    vader_array_box_slots(_a7_arr->buf)[vader_array_offset(_a7_arr) + 5u] = vader_ref_box(l5);
    vader_array_box_slots(_a7_arr->buf)[vader_array_offset(_a7_arr) + 4u] = vader_ref_box(l4);
    vader_array_box_slots(_a7_arr->buf)[vader_array_offset(_a7_arr) + 3u] = vader_ref_box(l3);
    vader_array_box_slots(_a7_arr->buf)[vader_array_offset(_a7_arr) + 2u] = vader_ref_box(l2);
    vader_array_box_slots(_a7_arr->buf)[vader_array_offset(_a7_arr) + 1u] = vader_ref_box(l1);
    vader_array_box_slots(_a7_arr->buf)[vader_array_offset(_a7_arr) + 0u] = vader_ref_box(l0);
    t0 = (void*) _a7_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_pipeline_check$checked_modules(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l9 = NULL;
    int64_t l5, l6;
    vader_string_t l7 = 0;
    vader_string_t l8 = 0;
    vader_string_t l10 = 0;
    vader_string_t t0 = 0;
    vader_box_t t1 = vader_box_null();
    bool t2;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l4, &l9 };
    vader_string_t* gc_atom_roots[4] = { &l7, &l8, &l10, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_front_resolver$LoadedProject_t*) l0)->f_entry;
    vader_array_t* _a0_arr = vader_array_new(26u, 1u, 0u, 536u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 0u] = vader_box_string(536u, t0);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct_vader_front_resolver$LoadedProject_t*) l0)->f_modules;
    l3 = ((vader_struct_std_collections$Map__string__vader_front_resolver_LoadedModule_t*) l2)->f_ekeys;
    l4 = ((vader_struct_std_collections$Map__string__vader_front_resolver_LoadedModule_t*) l2)->f_evals;
    l5 = INT64_C(0);
    l6 = ((vader_struct_std_collections$Map__string__vader_front_resolver_LoadedModule_t*) l2)->f_size;
    while ((l5 < l6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        t1 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l5];
        l7 = t1.payload.s;
        vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
        l2 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l5);
        l8 = l7;
        l9 = l2;
        l10 = ((vader_struct_vader_front_resolver$LoadedProject_t*) l0)->f_entry;
        if (l8 != l10) {
            t2 = ((vader_struct_vader_front_resolver$LoadedModule_t*) l9)->f_trimmed;
            if (!(t2)) {
                vader_array_push_scalar((vader_array_t*) l1, vader_box_string(536u, l8));
            }
        }
        l5 = (l5 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_pipeline_check$evaluate_checked(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_pipeline_check$assemble_typed_project(l1);
    t0 = vader_front_comptime$evaluate_project(l0, l3, l2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_pipeline_check$keys_per(uint8_t l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    int64_t l4, l5;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[5] = { &l1, &l2, &l3, &l6, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(0)) {
        t0 = (void*) &vader_data_34;
        vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT64_C(0));
        vader_array_t* _a1_arr = vader_array_new(390u, 1u, 13u, 1810u);
        ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = t0;
        t0 = (void*) _a1_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0 == INT32_C(1))) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    l2 = vader_pipeline_check$checked_modules(l1);
    t1 = vader_array_length(((vader_array_t*) l2));
    vader_array_t* _a2_arr = vader_array_reserve(390u, (int64_t) t1, 13u, 1810u);
    l3 = (void*) _a2_arr;
    l4 = vader_array_length(((vader_array_t*) l2));
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        t2 = vader_array_box_slots(_a3_slotarr->buf)[vader_array_offset(_a3_slotarr) + (size_t) l5];
        t3 = t2.payload.s;
        l6 = __lambda_vader_pipeline_check_2(t3);
        vader_array_push_ref((vader_array_t*) l3, l6);
        l5 = (l5 + INT64_C(1));
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_pipeline_check$plan_checks(void* l0, void* l1) {
    void* l2 = NULL;
    void* l6 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null();
    vader_string_t l5 = 0;
    int64_t l7, l8, l12, l13;
    uint8_t l9;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l3, &l4, &t2 };
    void** gc_raw_roots[9] = { &l0, &l1, &l2, &l6, &l10, &l11, &l14, &l15, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l5, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = toolchain_stage$plan_stages__vader_pipeline_check_Checked__toolchain_diagnostics_Diagnostic____vader_pipeline_check_CheckSpec(l0);
    l4 = l3;
    if (l3.tag == 1077u) {
        t0 = l4.payload.obj;
        l5 = ((vader_struct_toolchain_stage$PlanError_t*) t0)->f_message;
        t1 = concat_2(2052u, l5);
        vader_host_std_core$Intrinsic$panic(t1);
        vader_unreachable("a no-return call returned");
    } else {
        l2 = l3.payload.obj;
        vader_array_t* _a0_arr = vader_array_new(389u, 0u, 13u, 1809u);
        l6 = (void*) _a0_arr;
        l7 = vader_array_length(((vader_array_t*) l2));
        l8 = INT64_C(0);
        while ((l8 < l7)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            l3 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l8);
            t2 = toolchain_stage$Stage$describe$$dispatch(l3);
            l9 = ((vader_struct_vader_pipeline_check$CheckSpec_t*) t2.payload.obj)->f_per;
            l10 = ((vader_struct_vader_pipeline_check$CheckInput_t*) l1)->f_project;
            l11 = vader_pipeline_check$keys_per(l9, l10);
            l12 = vader_array_length(((vader_array_t*) l11));
            l13 = INT64_C(0);
            while ((l13 < l12)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l11);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                l14 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l13);
                vader_struct_vader_pipeline_check$Invocation_t* _a3_obj = (vader_struct_vader_pipeline_check$Invocation_t*) vader_gc_alloc(sizeof(vader_struct_vader_pipeline_check$Invocation_t));
                vader_obj_header_init(_a3_obj, 1809u);
                _a3_obj->f_stage = l3;
                _a3_obj->f_key = l14;
                l15 = (void*) _a3_obj;
                vader_array_push_ref((vader_array_t*) l6, l15);
                l13 = (l13 + INT64_C(1));
            }
            l8 = (l8 + INT64_C(1));
        }
        { void* __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_gc_top = gc_frame.prev;
}

static void* vader_pipeline_check$run_checks(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    int64_t l4, l5;
    vader_box_t l7 = vader_box_null();
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l7, &t1 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l6, &l8, &l9, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(79u, 0u, 13u, 1052u);
    l2 = (void*) _a0_arr;
    l3 = l0;
    l4 = vader_array_length(((vader_array_t*) l3));
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        l6 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l5);
        l7 = ((vader_struct_vader_pipeline_check$Invocation_t*) l6)->f_stage;
        l8 = ((vader_struct_vader_pipeline_check$Invocation_t*) l6)->f_key;
        vader_struct_vader_pipeline_check$Checked_t* _a2_obj = (vader_struct_vader_pipeline_check$Checked_t*) vader_gc_alloc(sizeof(vader_struct_vader_pipeline_check$Checked_t));
        vader_obj_header_init(_a2_obj, 1804u);
        _a2_obj->f_program = l1;
        _a2_obj->f_key = l8;
        t0 = (void*) _a2_obj;
        t1 = toolchain_stage$Stage$run$$dispatch(l7, vader_ref_box(t0));
        l9 = t1.payload.obj;
        vader_array_push_all((vader_array_t*) l2, (vader_array_t*) l9);
        l5 = (l5 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}
