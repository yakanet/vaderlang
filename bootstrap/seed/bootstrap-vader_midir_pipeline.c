#include "bootstrap.split.h"

static void vader_midir_pipeline$measure_begin(void* l0, int32_t l1);
static void vader_midir_pipeline$measure_end(void* l0, int32_t l1);
static void* vader_midir_pipeline$through_value_returns(void* l0, void* l1, void* l2);
static void vader_midir_pipeline$verify_after(void* l0, void* l1, vader_string_t l2, void* l3);

void* vader_midir_pipeline$build_optimised_cfg(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    bool t0;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_midir_pipeline$measure_begin(l1, INT32_C(5));
    l3 = vader_midir$build_cfg_project(l0, l2);
    vader_midir_pipeline$measure_end(l1, INT32_C(5));
    vader_midir_pipeline$verify_after(l1, l3, 1672u, l2);
    l3 = vader_midir_pipeline$through_value_returns(l1, l3, l2);
    vader_midir_pipeline$measure_begin(l1, INT32_C(6));
    l3 = vader_midir_optimise$eliminate_dead_cfg(l3);
    vader_midir_pipeline$measure_end(l1, INT32_C(6));
    vader_midir_pipeline$verify_after(l1, l3, 1862u, l2);
    vader_midir_pipeline$measure_begin(l1, INT32_C(7));
    l3 = vader_midir_optimise$annotate_escape(l3);
    l4 = ((vader_struct_vader_midir_optimise$AnnotatedProject_t*) l3)->f_project;
    vader_midir_pipeline$measure_end(l1, INT32_C(7));
    t0 = ((vader_struct_vader_midir_pipeline$CfgPassOptions_t*) l1)->f_instrumented;
    if (t0) {
        vader_midir_optimise$report_heap_allocations(((vader_struct_vader_midir_optimise$AnnotatedProject_t*) l3)->f_stats);
    }
    vader_midir_pipeline$verify_after(l1, l4, 1551u, l2);
    l3 = vader_midir_optimise$array_load_forward_project(l4);
    vader_midir_pipeline$verify_after(l1, l3, 1595u, l2);
    t0 = ((vader_struct_vader_midir_pipeline$CfgPassOptions_t*) l1)->f_instrumented;
    if (t0) {
        t0 = vader_support_opt__report$opt_report_enabled();
        if (t0) {
            vader_host_vader_support_profile$prof_begin(INT32_C(11));
            vader_midir_ranges$report_ranges(l3);
            vader_host_vader_support_profile$prof_end(INT32_C(11));
        }
    }
    t0 = ((vader_struct_vader_midir_pipeline$CfgPassOptions_t*) l1)->f_prove_bounds;
    if (!(t0)) {
        { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_midir_pipeline$measure_begin(l1, INT32_C(11));
    l3 = vader_midir_ranges$mark_proven_accesses(l3);
    vader_midir_pipeline$measure_end(l1, INT32_C(11));
    vader_midir_pipeline$verify_after(l1, l3, 2314u, l2);
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_midir_pipeline$measure_begin(void* l0, int32_t l1) {
    bool t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_midir_pipeline$CfgPassOptions_t*) l0)->f_instrumented;
    if (t0) {
        vader_host_vader_support_profile$prof_begin(l1);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_pipeline$measure_end(void* l0, int32_t l1) {
    bool t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_midir_pipeline$CfgPassOptions_t*) l0)->f_instrumented;
    if (t0) {
        vader_host_vader_support_profile$prof_end(l1);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_midir_pipeline$through_value_returns(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    bool t0;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_midir_pipeline$CfgPassOptions_t*) l0)->f_plain_returns;
    if (!(t0)) {
        vader_midir_pipeline$measure_begin(l0, INT32_C(10));
        l3 = vader_midir_value__return$scalarise_value_returns(l1);
        vader_midir_pipeline$measure_end(l0, INT32_C(10));
        vader_midir_pipeline$verify_after(l0, l3, 2542u, l2);
        l3 = vader_midir_value__return$struct_field_forward_project(l3);
        vader_midir_pipeline$verify_after(l0, l3, 2679u, l2);
        { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_midir_pipeline$verify_after(void* l0, void* l1, vader_string_t l2, void* l3) {
    bool t0;
    void** gc_raw_roots[3] = { &l0, &l1, &l3 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_midir_pipeline$CfgPassOptions_t*) l0)->f_verify;
    if (t0) {
        vader_midir$verify_cfg(l1, l2, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}
