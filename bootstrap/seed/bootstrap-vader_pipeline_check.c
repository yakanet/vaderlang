#include "bootstrap.split.h"

static void* vader_pipeline_check$assemble_typed_project(void* l0);
static void vader_pipeline_check$lint_dead_code(void* l0, void* l1);
static void vader_pipeline_check$lint_module(void* l0, void* l1);

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
    std_collections$MutableMap$std_core$IndexSet$set_at__string__Any(l3, l4, vader_ref_box(l5));
    t0 = std_collections$is_empty__string__Any(((vader_struct_vader_front_typecheck$CheckResult_t*) l2)->f_all_modules);
    if (t0) {
        l9 = ((vader_struct_vader_front_typecheck$CheckResult_t*) l2)->f_others;
        l6 = ((vader_array_t*) l9)->length;
        l7 = INT64_C(0);
        while ((l7 < l6)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l9);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            l10 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
            l11 = ((vader_struct_vader_front_typecheck$TypedProject_t*) l1)->f_modules;
            l8 = ((vader_struct_vader_front_resolver$ResolvedModule_t*) ((vader_struct_vader_front_typecheck$TypedProgram_t*) l10)->f_resolved)->f_path;
            std_collections$MutableMap$std_core$IndexSet$set_at__string__Any(l11, l8, vader_ref_box(l10));
            l7 = (l7 + INT64_C(1));
        }
        { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_vader_front_typecheck$CheckResult_t*) l2)->f_all_modules;
    l3 = ((vader_struct_std_collections$MutableMap__string__vader_front_typecheck_TypedProgram_t*) l2)->f_ekeys;
    l5 = ((vader_struct_std_collections$MutableMap__string__vader_front_typecheck_TypedProgram_t*) l2)->f_evals;
    l6 = INT64_C(0);
    l7 = ((vader_struct_std_collections$MutableMap__string__vader_front_typecheck_TypedProgram_t*) l2)->f_size;
    while ((l6 < l7)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        t1 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l6];
        l4 = t1.payload.s;
        vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
        l2 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l6);
        l8 = l4;
        l9 = l2;
        std_collections$MutableMap$std_core$IndexSet$set_at__string__Any(((vader_struct_vader_front_typecheck$TypedProject_t*) l1)->f_modules, l8, vader_ref_box(l9));
        l6 = (l6 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_pipeline_check$check_project(void* l0, void* l1, bool l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[6] = { &l0, &l1, &l3, &l4, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_front_typecheck$check_project_with_bodies(l0, l1, l2);
    vader_pipeline_check$lint_dead_code(l0, l1);
    l4 = vader_front_effects$summarise_effects(l0, l3);
    l5 = vader_front_effects$widening_diagnostics(l4, l3);
    vader_array_push_all((vader_array_t*) l1, (vader_array_t*) l5);
    l5 = vader_front_effects$frozen_diagnostics(l4);
    vader_array_push_all((vader_array_t*) l1, (vader_array_t*) l5);
    vader_struct_vader_pipeline_check$CheckedProject_t* _a0_obj = (vader_struct_vader_pipeline_check$CheckedProject_t*) vader_gc_alloc(sizeof(vader_struct_vader_pipeline_check$CheckedProject_t));
    vader_obj_header_init(_a0_obj, 1406u);
    _a0_obj->f_result = l3;
    _a0_obj->f_effects = l4;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
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

static void vader_pipeline_check$lint_dead_code(void* l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l10 = NULL;
    vader_string_t l3 = 0;
    vader_string_t l9 = 0;
    vader_string_t l11 = 0;
    vader_box_t l4 = vader_box_null();
    int64_t l7, l8;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l4, &t1 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l5, &l6, &l10, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l3, &l9, &l11 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_front_resolver$LoadedProject_t*) l0)->f_modules;
    l3 = ((vader_struct_vader_front_resolver$LoadedProject_t*) l0)->f_entry;
    l4 = std_collections$MutableMap$std_core$Index$at__string__Any(l2, l3);
    if (l4.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = l4.payload.obj;
    vader_pipeline_check$lint_module(t0, l1);
    l2 = ((vader_struct_vader_front_resolver$LoadedProject_t*) l0)->f_modules;
    l5 = ((vader_struct_std_collections$MutableMap__string__vader_front_resolver_LoadedModule_t*) l2)->f_ekeys;
    l6 = ((vader_struct_std_collections$MutableMap__string__vader_front_resolver_LoadedModule_t*) l2)->f_evals;
    l7 = INT64_C(0);
    l8 = ((vader_struct_std_collections$MutableMap__string__vader_front_resolver_LoadedModule_t*) l2)->f_size;
    while ((l7 < l8)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l7)
        t1 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l7];
        l3 = t1.payload.s;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l7)
        l2 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l7);
        l9 = l3;
        l10 = l2;
        l11 = ((vader_struct_vader_front_resolver$LoadedProject_t*) l0)->f_entry;
        if (l9 != l11) {
            vader_pipeline_check$lint_module(l10, l1);
        }
        l7 = (l7 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_pipeline_check$lint_module(void* l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    vader_string_t l3 = 0;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l4 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_front_resolver$concat_file_decls(((vader_struct_vader_front_resolver$Module_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l0)->f_module)->f_files);
    l3 = ((vader_struct_vader_front_resolver$Module_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l0)->f_module)->f_module_name;
    l4 = ((vader_struct_vader_front_resolver$LoadedModule_t*) l0)->f_discarded_bodies;
    vader_front_dead__code$check_dead_code(l2, l3, l1, l4);
    { vader_gc_top = gc_frame.prev; return; }
}
