#include "bootstrap.split.h"

static void* vader_pipeline_check$active_stages(uint8_t l0);
static void* vader_pipeline_check$assemble_typed_project(void* l0);
static void* vader_pipeline_check$check_stages(void);
static void* vader_pipeline_check$checked_modules(void* l0);
static void* vader_pipeline_check$keys_per(uint8_t l0, void* l1);
static vader_box_t vader_pipeline_check$parsed_body(void* l0, void* l1, void* l2, vader_string_t l3, void* l4);
static void* vader_pipeline_check$plan_checks(void* l0, void* l1);
static void vader_pipeline_check$provide_late_bodies(void* l0, void* l1, void* l2);
static void vader_pipeline_check$provide_module_bodies(void* l0, void* l1, void* l2, void* l3);
static void* vader_pipeline_check$run_checks(void* l0, void* l1);
static void* vader_pipeline_check$typed_project_of(void* l0, void* l1);

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
    vader_obj_header_init(_a0_obj, 1903u);
    _a0_obj->f_name = 2231u;
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
        vader_array_t* _a0_arr = vader_array_new(82u, 0u, 13u, 1112u);
        t0 = (void*) _a0_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = l4.payload.obj;
    vader_array_t* _a1_arr = vader_array_new(82u, 0u, 13u, 1112u);
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
    vader_obj_header_init(_a0_obj, 1903u);
    _a0_obj->f_name = 2240u;
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
        vader_array_t* _a0_arr = vader_array_new(82u, 0u, 13u, 1112u);
        t0 = (void*) _a0_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = l3.payload.obj;
    l3 = ((vader_struct_vader_pipeline_check$CheckInput_t*) ((vader_struct_vader_pipeline_check$Checked_t*) l1)->f_program)->f_result;
    if (l3.tag == 0u) {
        vader_array_t* _a1_arr = vader_array_new(82u, 0u, 13u, 1112u);
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
    vader_obj_header_init(_a0_obj, 1903u);
    _a0_obj->f_name = 2472u;
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
        vader_array_t* _a0_arr = vader_array_new(82u, 0u, 13u, 1112u);
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
    vader_obj_header_init(_a0_obj, 1903u);
    _a0_obj->f_name = 3160u;
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
        vader_array_t* _a0_arr = vader_array_new(82u, 0u, 13u, 1112u);
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
    vader_obj_header_init(_a0_obj, 1903u);
    _a0_obj->f_name = 3355u;
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
    vader_obj_header_init(_a0_obj, 1903u);
    _a0_obj->f_name = 3356u;
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
        vader_array_t* _a0_arr = vader_array_new(82u, 0u, 13u, 1112u);
        t0 = (void*) _a0_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = l3.payload.obj;
    vader_array_t* _a1_arr = vader_array_new(82u, 0u, 13u, 1112u);
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
    vader_obj_header_init(_a0_obj, 1903u);
    _a0_obj->f_name = 3582u;
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
        vader_array_t* _a0_arr = vader_array_new(82u, 0u, 13u, 1112u);
        t0 = (void*) _a0_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = l3.payload.obj;
    l3 = ((vader_struct_vader_pipeline_check$CheckInput_t*) ((vader_struct_vader_pipeline_check$Checked_t*) l1)->f_program)->f_result;
    if (l3.tag == 0u) {
        vader_array_t* _a1_arr = vader_array_new(82u, 0u, 13u, 1112u);
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
    vader_struct___lambda_env_vader_pipeline_check_2_t* _a0_obj = (vader_struct___lambda_env_vader_pipeline_check_2_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_pipeline_check_2_t));
    vader_obj_header_init(_a0_obj, 782u);
    _a0_obj->f_cap_0 = l0;
    l2 = (void*) _a0_obj;
    vader_array_t* _a1_arr = vader_array_new(34u, 0u, 0u, 591u);
    l3 = (void*) _a1_arr;
    l4 = vader_array_length(((vader_array_t*) l1));
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l6 = vader_array_ref_load_box(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l5);
        t0 = __lambda_vader_pipeline_check_1(l2, l6);
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
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_pipeline_check$CheckedProject_t*) l0)->f_result;
    l2 = ((vader_struct_vader_front_effects$EffectSummary_t*) ((vader_struct_vader_pipeline_check$CheckedProject_t*) l0)->f_effects)->f_fresh;
    t0 = vader_pipeline_check$typed_project_of(l1, l2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_pipeline_check$check_project(void* l0, void* l1, bool l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    bool t0;
    void* t1 = NULL;
    void* t2 = NULL;
    void** gc_raw_roots[7] = { &l0, &l1, &l3, &l4, &l5, &t1, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 7u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_front_typecheck$check_project_with_bodies(l0, l1, l2);
    t0 = std_core$is_empty__vader_front_resolver_LateFn(((vader_struct_vader_front_resolver$LoadedProject_t*) l0)->f_late_fns);
    if (!(t0)) {
        vader_pipeline_check$provide_late_bodies(l0, l3, l1);
    }
    l4 = vader_front_effects$summarise_effects(l0, l3);
    vader_struct_vader_pipeline_check$CheckInput_t* _a0_obj = (vader_struct_vader_pipeline_check$CheckInput_t*) vader_gc_alloc(sizeof(vader_struct_vader_pipeline_check$CheckInput_t));
    vader_obj_header_init(_a0_obj, 1902u);
    _a0_obj->f_project = l0;
    _a0_obj->f_result = vader_ref_box(l3);
    _a0_obj->f_effects = vader_ref_box(l4);
    l5 = (void*) _a0_obj;
    t1 = vader_pipeline_check$active_stages((uint8_t) 0);
    t2 = vader_pipeline_check$plan_checks(t1, l5);
    l5 = vader_pipeline_check$run_checks(t2, l5);
    vader_array_push_all((vader_array_t*) l1, (vader_array_t*) l5);
    vader_struct_vader_pipeline_check$CheckedProject_t* _a1_obj = (vader_struct_vader_pipeline_check$CheckedProject_t*) vader_gc_alloc(sizeof(vader_struct_vader_pipeline_check$CheckedProject_t));
    vader_obj_header_init(_a1_obj, 1905u);
    _a1_obj->f_result = l3;
    _a1_obj->f_effects = l4;
    t1 = (void*) _a1_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
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
    t0 = (void*) &vader_data_102;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT64_C(0));
    t0 = (void*) &vader_data_103;
    vader_array_t* _a1_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    l1 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) INT64_C(0));
    t0 = (void*) &vader_data_104;
    vader_array_t* _a2_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    l2 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) INT64_C(0));
    t0 = (void*) &vader_data_105;
    vader_array_t* _a3_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
    l3 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) INT64_C(0));
    t0 = (void*) &vader_data_106;
    vader_array_t* _a4_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
    l4 = vader_array_ref_load_obj(_a4_slotarr->buf, vader_array_offset(_a4_slotarr) + (size_t) INT64_C(0));
    t0 = (void*) &vader_data_107;
    vader_array_t* _a5_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    l5 = vader_array_ref_load_obj(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) INT64_C(0));
    t0 = (void*) &vader_data_108;
    vader_array_t* _a6_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
    l6 = vader_array_ref_load_obj(_a6_slotarr->buf, vader_array_offset(_a6_slotarr) + (size_t) INT64_C(0));
    vader_array_t* _a7_arr = vader_array_new(34u, 7u, 0u, 591u);
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
    vader_array_t* _a0_arr = vader_array_new(26u, 1u, 0u, 577u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 0u] = vader_box_string(577u, t0);
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
                vader_array_push_scalar((vader_array_t*) l1, vader_box_string(577u, l8));
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
        t0 = (void*) &vader_data_36;
        vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT64_C(0));
        vader_array_t* _a1_arr = vader_array_new(403u, 1u, 13u, 1911u);
        ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = t0;
        t0 = (void*) _a1_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0 == INT32_C(1))) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    l2 = vader_pipeline_check$checked_modules(l1);
    t1 = vader_array_length(((vader_array_t*) l2));
    vader_array_t* _a2_arr = vader_array_reserve(403u, (int64_t) t1, 13u, 1911u);
    l3 = (void*) _a2_arr;
    l4 = vader_array_length(((vader_array_t*) l2));
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        t2 = vader_array_box_slots(_a3_slotarr->buf)[vader_array_offset(_a3_slotarr) + (size_t) l5];
        t3 = t2.payload.s;
        l6 = __lambda_vader_pipeline_check_8(t3);
        vader_array_push_ref((vader_array_t*) l3, l6);
        l5 = (l5 + INT64_C(1));
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_pipeline_check$parsed_body(void* l0, void* l1, void* l2, vader_string_t l3, void* l4) {
    vader_string_t l5 = 0;
    vader_string_t l6 = 0;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    int64_t l10, l11;
    vader_box_t l12 = vader_box_null();
    bool t0;
    vader_box_t* gc_roots[1] = { &l12 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l4, &l7, &l8, &l9 };
    vader_string_t* gc_atom_roots[3] = { &l3, &l5, &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l5 = ((vader_struct_vader_front_resolver$Module_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l2)->f_module)->f_module_name;
    l6 = vader_front_resolver$late_body_file(l1, l5);
    l5 = vader_front_resolver$late_body_source(l1, l5, l3);
    l7 = ((vader_struct_vader_front_resolver$LoadedProject_t*) l0)->f_given_bodies;
    vader_struct_vader_front_resolver$GeneratedSource_t* _a0_obj = (vader_struct_vader_front_resolver$GeneratedSource_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$GeneratedSource_t));
    vader_obj_header_init(_a0_obj, 1575u);
    _a0_obj->f_file = l6;
    _a0_obj->f_content = l5;
    l8 = (void*) _a0_obj;
    vader_array_push_ref((vader_array_t*) l7, l8);
    l7 = toolchain_parser$parse_compiler_written(l5, l6);
    l8 = ((vader_struct_toolchain_parser$ParsedSource_t*) l7)->f_errors;
    vader_array_push_all((vader_array_t*) l4, (vader_array_t*) l8);
    t0 = toolchain_diagnostics$any_error_diag(((vader_struct_toolchain_parser$ParsedSource_t*) l7)->f_errors);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l8 = ((vader_struct_toolchain_parser$ParsedSource_t*) l7)->f_program;
    l9 = ((vader_struct_vader_front_resolver$LoadedModule_t*) l2)->f_node_id_factory;
    toolchain_parser$assign_program_ids(l8, l9);
    l7 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_toolchain_parser$ParsedSource_t*) l7)->f_program)->f_decls;
    l10 = vader_array_length(((vader_array_t*) l7));
    l11 = INT64_C(0);
    while ((l11 < l10)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l12 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l11);
        if (l12.tag == 1048u) {
            l8 = l12.payload.obj;
            t0 = ((vader_struct_toolchain_ast$FnDecl_t*) l8)->f_is_expression_bodied;
            if (!(t0)) {
                { vader_box_t __vret = ((vader_struct_toolchain_ast$FnDecl_t*) l8)->f_body; vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
        l11 = (l11 + INT64_C(1));
    }
    l5 = ((vader_struct_toolchain_ast$FnDecl_t*) ((vader_struct_vader_front_resolver$LateFn_t*) l1)->f_decl)->f_name;
    l5 = concat_5(1267u, l5, 1421u, l3, 1609u);
    l7 = ((vader_struct_toolchain_ast$FnDecl_t*) ((vader_struct_vader_front_resolver$LateFn_t*) l1)->f_decl)->f_name_span;
    l7 = toolchain_diagnostics$hook_error((uint8_t) 3, l7, l5);
    vader_array_push_ref((vader_array_t*) l4, l7);
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
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
    if (l3.tag == 1162u) {
        t0 = l4.payload.obj;
        l5 = ((vader_struct_toolchain_stage$PlanError_t*) t0)->f_message;
        t1 = concat_2(2156u, l5);
        vader_host_std_core$Intrinsic$panic(t1);
        vader_unreachable("a no-return call returned");
    } else {
        l2 = l3.payload.obj;
        vader_array_t* _a0_arr = vader_array_new(402u, 0u, 13u, 1909u);
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
                vader_obj_header_init(_a3_obj, 1909u);
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

static void vader_pipeline_check$provide_late_bodies(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    int64_t l10, l11;
    vader_string_t l12 = 0;
    vader_string_t l13 = 0;
    void* t0 = NULL;
    bool t1;
    void** gc_raw_roots[11] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l8, &l9, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l12, &l13 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 11u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_clear((vader_array_t*) ((vader_struct_vader_front_resolver$LoadedProject_t*) l0)->f_given_bodies);
    vader_array_t* _a0_arr = vader_array_new(82u, 0u, 13u, 1112u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(28u, 0u, 8u, 581u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(24u, 0u, 12u, 575u);
    l5 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(27u, 0u, 7u, 580u);
    l6 = (void*) _a3_arr;
    vader_struct_std_collections$Map__i64__bool_t* _a4_obj = (vader_struct_std_collections$Map__i64__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i64__bool_t));
    vader_obj_header_init(_a4_obj, 864u);
    _a4_obj->f_ekeys = l4;
    _a4_obj->f_evals = l5;
    _a4_obj->f_index = l6;
    _a4_obj->f_mask = INT64_C(0);
    _a4_obj->f_grow_at = INT64_C(0);
    _a4_obj->f_size = INT64_C(0);
    _a4_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a4_obj;
    vader_struct_std_collections$Set__i64_t* _a5_obj = (vader_struct_std_collections$Set__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__i64_t));
    vader_obj_header_init(_a5_obj, 990u);
    _a5_obj->f_inner = t0;
    l4 = (void*) _a5_obj;
    vader_array_t* _a6_arr = vader_array_new(27u, 0u, 7u, 580u);
    l5 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(24u, 0u, 12u, 575u);
    l6 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(27u, 0u, 7u, 580u);
    l7 = (void*) _a8_arr;
    vader_struct_std_collections$Map__i32__bool_t* _a9_obj = (vader_struct_std_collections$Map__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__bool_t));
    vader_obj_header_init(_a9_obj, 815u);
    _a9_obj->f_ekeys = l5;
    _a9_obj->f_evals = l6;
    _a9_obj->f_index = l7;
    _a9_obj->f_mask = INT64_C(0);
    _a9_obj->f_grow_at = INT64_C(0);
    _a9_obj->f_size = INT64_C(0);
    _a9_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a9_obj;
    vader_struct_std_collections$Set__i32_t* _a10_obj = (vader_struct_std_collections$Set__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__i32_t));
    vader_obj_header_init(_a10_obj, 989u);
    _a10_obj->f_inner = t0;
    l5 = (void*) _a10_obj;
    vader_struct_vader_front_typecheck$FreshReads_t* _a11_obj = (vader_struct_vader_front_typecheck$FreshReads_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_typecheck$FreshReads_t));
    vader_obj_header_init(_a11_obj, 1635u);
    _a11_obj->f_uses = l4;
    _a11_obj->f_constants = l5;
    l4 = (void*) _a11_obj;
    l4 = vader_pipeline_check$typed_project_of(l1, l4);
    l3 = vader_front_comptime$evaluate_project(l0, l4, l3);
    l4 = vader_front_resolver$build_core_seed(l0);
    l5 = vader_front_resolver$module_index_by_name(l0);
    l6 = ((vader_struct_vader_front_resolver$LoadedProject_t*) l0)->f_late_fns;
    vader_array_t* _a12_arr = vader_array_new(26u, 0u, 0u, 577u);
    l7 = (void*) _a12_arr;
    vader_array_t* _a13_arr = vader_array_new(24u, 0u, 12u, 575u);
    l8 = (void*) _a13_arr;
    vader_array_t* _a14_arr = vader_array_new(27u, 0u, 7u, 580u);
    l9 = (void*) _a14_arr;
    vader_struct_std_collections$Map__string__bool_t* _a15_obj = (vader_struct_std_collections$Map__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__bool_t));
    vader_obj_header_init(_a15_obj, 901u);
    _a15_obj->f_ekeys = l7;
    _a15_obj->f_evals = l8;
    _a15_obj->f_index = l9;
    _a15_obj->f_mask = INT64_C(0);
    _a15_obj->f_grow_at = INT64_C(0);
    _a15_obj->f_size = INT64_C(0);
    _a15_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a15_obj;
    vader_struct_std_collections$Set__string_t* _a16_obj = (vader_struct_std_collections$Set__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__string_t));
    vader_obj_header_init(_a16_obj, 991u);
    _a16_obj->f_inner = t0;
    l7 = (void*) _a16_obj;
    l10 = vader_array_length(((vader_array_t*) l6));
    l11 = INT64_C(0);
    while ((l11 < l10)) {
        vader_array_t* _a17_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l11)
        t0 = vader_array_ref_load_obj(_a17_slotarr->buf, vader_array_offset(_a17_slotarr) + (size_t) l11);
        l12 = __lambda_vader_pipeline_check_0(t0);
        t1 = std_collections$add__string(l7, l12);
        if (t1) {
            l13 = l12;
            vader_struct_vader_pipeline_check$ModuleBodies_t* _a18_obj = (vader_struct_vader_pipeline_check$ModuleBodies_t*) vader_gc_alloc(sizeof(vader_struct_vader_pipeline_check$ModuleBodies_t));
            vader_obj_header_init(_a18_obj, 1910u);
            _a18_obj->f_loaded = l0;
            _a18_obj->f_module_id = l13;
            _a18_obj->f_core_seed = l4;
            _a18_obj->f_name_index = l5;
            t0 = (void*) _a18_obj;
            vader_pipeline_check$provide_module_bodies(t0, l1, l3, l2);
        }
        l11 = (l11 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_pipeline_check$provide_module_bodies(void* l0, void* l1, void* l2, void* l3) {
    void* l4 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l23 = NULL;
    void* l25 = NULL;
    void* l28 = NULL;
    void* l29 = NULL;
    void* l30 = NULL;
    vader_string_t l5 = 0;
    vader_string_t l26 = 0;
    vader_string_t l31 = 0;
    vader_box_t l6 = vader_box_null(), l17 = vader_box_null(), l18 = vader_box_null(), l21 = vader_box_null(), l24 = vader_box_null(), l32 = vader_box_null();
    int64_t l10, l11, l19, l20, l22, l27;
    vader_string_t t0 = 0;
    int64_t t1;
    void* t2 = NULL;
    bool t3;
    vader_box_t t4 = vader_box_null();
    vader_box_t* gc_roots[7] = { &l6, &l17, &l18, &l21, &l24, &l32, &t4 };
    void** gc_raw_roots[19] = {
        &l0, &l1, &l2, &l3, &l4, &l7, &l8, &l9, &l12, &l13, &l14, &l15, &l16, &l23, &l25, &l28,
        &l29, &l30, &t2,
    };
    vader_string_t* gc_atom_roots[4] = { &l5, &l26, &l31, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 7u, 19u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_front_resolver$LoadedProject_t*) ((vader_struct_vader_pipeline_check$ModuleBodies_t*) l0)->f_loaded)->f_modules;
    l5 = ((vader_struct_vader_pipeline_check$ModuleBodies_t*) l0)->f_module_id;
    l6 = std_collections$Map$std_core$Index$at__string__Any(l4, l5);
    if (l6.tag == 0u) {
        l5 = ((vader_struct_vader_pipeline_check$ModuleBodies_t*) l0)->f_module_id;
        t0 = concat_3(2713u, l5, 1555u);
        vader_host_std_core$Intrinsic$panic(t0);
        vader_unreachable("a no-return call returned");
    } else {
        l4 = l6.payload.obj;
        l7 = ((vader_struct_vader_front_typecheck$CheckResult_t*) l1)->f_all_modules;
        l5 = ((vader_struct_vader_pipeline_check$ModuleBodies_t*) l0)->f_module_id;
        l6 = std_collections$Map$std_core$Index$at__string__Any(l7, l5);
        if (l6.tag == 0u) {
            l5 = ((vader_struct_vader_pipeline_check$ModuleBodies_t*) l0)->f_module_id;
            t0 = concat_3(2713u, l5, 1556u);
            vader_host_std_core$Intrinsic$panic(t0);
            vader_unreachable("a no-return call returned");
        } else {
            l7 = l6.payload.obj;
            l8 = ((vader_struct_vader_front_resolver$Module_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l4)->f_module)->f_files;
            t1 = vader_array_length(((vader_array_t*) l8));
            vader_array_t* _a0_arr = vader_array_reserve(26u, (int64_t) t1, 0u, 577u);
            l9 = (void*) _a0_arr;
            l10 = vader_array_length(((vader_array_t*) l8));
            l11 = INT64_C(0);
            while ((l11 < l10)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l8);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                t2 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l11);
                l5 = __lambda_vader_pipeline_check_3(t2);
                vader_array_push_scalar((vader_array_t*) l9, vader_box_string(577u, l5));
                l11 = (l11 + INT64_C(1));
            }
            l8 = l9;
            l9 = ((vader_struct_vader_front_comptime$EvaluatedProject_t*) l2)->f_modules;
            l5 = ((vader_struct_vader_pipeline_check$ModuleBodies_t*) l0)->f_module_id;
            l6 = std_collections$Map$std_core$Index$at__string__Any(l9, l5);
            l8 = vader_front_comptime$deliver_decorators(l7, l6, l8);
            l9 = vader_front_resolver$concat_file_decls(((vader_struct_vader_front_resolver$Module_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l4)->f_module)->f_files);
            l12 = ((vader_struct_vader_front_resolver$LoadedProject_t*) ((vader_struct_vader_pipeline_check$ModuleBodies_t*) l0)->f_loaded)->f_late_fns;
            vader_struct___lambda_env_vader_pipeline_check_5_t* _a2_obj = (vader_struct___lambda_env_vader_pipeline_check_5_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_pipeline_check_5_t));
            vader_obj_header_init(_a2_obj, 783u);
            _a2_obj->f_cap_0 = l0;
            l13 = (void*) _a2_obj;
            vader_array_t* _a3_arr = vader_array_new(307u, 0u, 13u, 1582u);
            l14 = (void*) _a3_arr;
            l10 = vader_array_length(((vader_array_t*) l12));
            l11 = INT64_C(0);
            while ((l11 < l10)) {
                vader_array_t* _a4_slotarr = ((vader_array_t*) l12);
                VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                l15 = vader_array_ref_load_obj(_a4_slotarr->buf, vader_array_offset(_a4_slotarr) + (size_t) l11);
                t3 = __lambda_vader_pipeline_check_4(l13, l15);
                if (t3) {
                    l16 = l15;
                    vader_array_push_ref((vader_array_t*) l14, l16);
                }
                l11 = (l11 + INT64_C(1));
            }
            l13 = l14;
            vader_array_t* _a5_arr = vader_array_new(307u, 0u, 13u, 1582u);
            l12 = (void*) _a5_arr;
            l10 = vader_array_length(((vader_array_t*) l13));
            l11 = INT64_C(0);
            while ((l11 < l10)) {
                vader_array_t* _a6_slotarr = ((vader_array_t*) l13);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l11)
                l14 = vader_array_ref_load_obj(_a6_slotarr->buf, vader_array_offset(_a6_slotarr) + (size_t) l11);
                l15 = ((vader_struct_vader_front_resolver$LoadedProject_t*) ((vader_struct_vader_pipeline_check$ModuleBodies_t*) l0)->f_loaded)->f_body_stages;
                vader_struct___lambda_env_vader_pipeline_check_7_t* _a7_obj = (vader_struct___lambda_env_vader_pipeline_check_7_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_pipeline_check_7_t));
                vader_obj_header_init(_a7_obj, 784u);
                _a7_obj->f_cap_0 = l14;
                l16 = (void*) _a7_obj;
                l18 = vader_box_obj(0u, NULL);
                l19 = vader_array_length(((vader_array_t*) l15));
                l20 = INT64_C(0);
                {
                    while ((l20 < l19)) {
                        vader_array_t* _a8_slotarr = ((vader_array_t*) l15);
                        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
                        l21 = vader_array_ref_load_box(_a8_slotarr->buf, vader_array_offset(_a8_slotarr) + (size_t) l20);
                        t3 = __lambda_vader_pipeline_check_6(l16, l21);
                        if (t3) {
                            l18 = l21;
                            goto end_170;
                        }
                        l20 = (l20 + INT64_C(1));
                    }
                    l18 = vader_box_obj(0u, NULL);
                } end_170: ;
                l17 = l18;
                if (l17.tag == 0u) {
                    l11 = (l11 + INT64_C(1));
                    continue;
                }
                l6 = l17;
                l22 = std_time$monotonic();
                l23 = ((vader_struct_vader_front_resolver$LateFn_t*) l14)->f_decl;
                l24 = ((vader_struct_vader_front_resolver$LateFn_t*) l14)->f_owner;
                l5 = ((vader_struct_vader_front_resolver$Module_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l4)->f_module)->f_module_name;
                vader_struct_toolchain_stage$BodyRequest_t* _a9_obj = (vader_struct_toolchain_stage$BodyRequest_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_stage$BodyRequest_t));
                vader_obj_header_init(_a9_obj, 1157u);
                _a9_obj->f_decl = l23;
                _a9_obj->f_owner = l24;
                _a9_obj->f_declarations = l9;
                _a9_obj->f_module_name = l5;
                t2 = (void*) _a9_obj;
                t4 = toolchain_stage$Stage$run$$dispatch(l6, vader_ref_box(t2));
                l25 = t4.payload.obj;
                l26 = ((vader_struct_vader_front_resolver$LateFn_t*) l14)->f_stage;
                l27 = std_time$since(l22);
                vader_support_profile$note_stage(l26, true, l27);
                l28 = ((vader_struct_toolchain_stage$Body_t*) l25)->f_diagnostics;
                vader_array_push_all((vader_array_t*) l3, (vader_array_t*) l28);
                l30 = ((vader_struct_vader_pipeline_check$ModuleBodies_t*) l0)->f_loaded;
                l31 = ((vader_struct_toolchain_stage$Body_t*) l25)->f_text;
                l32 = vader_pipeline_check$parsed_body(l30, l14, l4, l31, l3);
                if (l32.tag == 0u) {
                    l11 = (l11 + INT64_C(1));
                    continue;
                }
                l29 = l32.payload.obj;
                ((vader_struct_toolchain_ast$FnDecl_t*) ((vader_struct_vader_front_resolver$LateFn_t*) l14)->f_decl)->f_body = vader_ref_box(l29);
                VADER_WRITE_BARRIER((vader_struct_toolchain_ast$FnDecl_t*) ((vader_struct_vader_front_resolver$LateFn_t*) l14)->f_decl);
                vader_array_push_ref((vader_array_t*) l12, l14);
                l11 = (l11 + INT64_C(1));
            }
            vader_front_comptime$restore_written_arguments(l8);
            l8 = ((vader_struct_vader_front_resolver$Module_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l4)->f_module)->f_files;
            l4 = ((vader_struct_vader_front_resolver$LoadedModule_t*) l4)->f_collected;
            l9 = ((vader_struct_vader_pipeline_check$ModuleBodies_t*) l0)->f_name_index;
            l13 = ((vader_struct_vader_pipeline_check$ModuleBodies_t*) l0)->f_core_seed;
            l14 = ((vader_struct_vader_front_resolver$LoadedProject_t*) ((vader_struct_vader_pipeline_check$ModuleBodies_t*) l0)->f_loaded)->f_factory;
            l4 = vader_front_resolver$module_file_scopes(l8, l4, l9, l13, l14);
            l8 = l12;
            l10 = vader_array_length(((vader_array_t*) l8));
            l11 = INT64_C(0);
            while ((l11 < l10)) {
                vader_array_t* _a10_slotarr = ((vader_array_t*) l8);
                VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l11)
                l9 = vader_array_ref_load_obj(_a10_slotarr->buf, vader_array_offset(_a10_slotarr) + (size_t) l11);
                l13 = ((vader_struct_vader_front_typecheck$TypedProgram_t*) l7)->f_resolved;
                l14 = ((vader_struct_vader_front_resolver$LoadedProject_t*) ((vader_struct_vader_pipeline_check$ModuleBodies_t*) l0)->f_loaded)->f_factory;
                l15 = vader_front_resolver$resolve_late_body(l13, l4, l14, l9);
                vader_array_push_all((vader_array_t*) l3, (vader_array_t*) l15);
                l11 = (l11 + INT64_C(1));
            }
            vader_front_typecheck$check_late_bodies(l12, l7, l3);
            { vader_gc_top = gc_frame.prev; return; }
        }
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
    vader_array_t* _a0_arr = vader_array_new(82u, 0u, 13u, 1112u);
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
        vader_obj_header_init(_a2_obj, 1904u);
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

static void* vader_pipeline_check$typed_project_of(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    vader_string_t l4 = 0;
    vader_string_t l9 = 0;
    int64_t l7, l8;
    bool t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l5, &l6, &l10, &l11 };
    vader_string_t* gc_atom_roots[2] = { &l4, &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_front_typecheck$new_typed_project(l1);
    l3 = ((vader_struct_vader_front_typecheck$TypedProject_t*) l2)->f_modules;
    l4 = ((vader_struct_vader_front_resolver$ResolvedModule_t*) ((vader_struct_vader_front_typecheck$TypedProgram_t*) ((vader_struct_vader_front_typecheck$CheckResult_t*) l0)->f_typed)->f_resolved)->f_path;
    l5 = ((vader_struct_vader_front_typecheck$CheckResult_t*) l0)->f_typed;
    std_collections$Map$std_core$IndexSet$set_at__string__Any(l3, l4, vader_ref_box(l5));
    t0 = std_collections$is_empty__string__Any(((vader_struct_vader_front_typecheck$CheckResult_t*) l0)->f_all_modules);
    if (t0) {
        l6 = ((vader_struct_vader_front_typecheck$CheckResult_t*) l0)->f_others;
        l7 = vader_array_length(((vader_array_t*) l6));
        l8 = INT64_C(0);
        while ((l8 < l7)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            l10 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l8);
            l11 = ((vader_struct_vader_front_typecheck$TypedProject_t*) l2)->f_modules;
            l9 = ((vader_struct_vader_front_resolver$ResolvedModule_t*) ((vader_struct_vader_front_typecheck$TypedProgram_t*) l10)->f_resolved)->f_path;
            std_collections$Map$std_core$IndexSet$set_at__string__Any(l11, l9, vader_ref_box(l10));
            l8 = (l8 + INT64_C(1));
        }
        { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((vader_struct_vader_front_typecheck$CheckResult_t*) l0)->f_all_modules;
    l5 = ((vader_struct_std_collections$Map__string__vader_front_typecheck_TypedProgram_t*) l3)->f_ekeys;
    l6 = ((vader_struct_std_collections$Map__string__vader_front_typecheck_TypedProgram_t*) l3)->f_evals;
    l7 = INT64_C(0);
    l8 = ((vader_struct_std_collections$Map__string__vader_front_typecheck_TypedProgram_t*) l3)->f_size;
    while ((l7 < l8)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l7)
        t1 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l7];
        l4 = t1.payload.s;
        vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l7)
        l3 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l7);
        l9 = l4;
        l10 = l3;
        std_collections$Map$std_core$IndexSet$set_at__string__Any(((vader_struct_vader_front_typecheck$TypedProject_t*) l2)->f_modules, l9, vader_ref_box(l10));
        l7 = (l7 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}
