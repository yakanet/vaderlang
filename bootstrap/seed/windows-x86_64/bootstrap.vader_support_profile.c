#include "bootstrap.split.h"

static void vader_support_profile$add_change(void* l0, void* l1, void* l2);
static vader_string_t vader_support_profile$open_name(vader_box_t l0);
static vader_string_t vader_support_profile$phase_name(uint8_t l0);
static void* vader_support_profile$profiler(void);
static void* vader_support_profile$profiler$singleton(void);
static bool vader_support_profile$profiling(void);
static bool vader_support_profile$profiling$singleton(void);
static void* vader_support_profile$read_counters(void);

static void vader_support_profile$add_change(void* l0, void* l1, void* l2) {
    int64_t l3, l4, l5;
    l3 = ((vader_struct_vader_support_profile$Counters_t*) l0)->f_peak_rss;
    l4 = ((vader_struct_vader_support_profile$Counters_t*) l2)->f_peak_rss;
    l5 = ((vader_struct_vader_support_profile$Counters_t*) l1)->f_peak_rss;
    l4 = vader_chk_sub(i64, l4, l5);
    l3 = vader_chk_add(i64, l3, l4);
    ((vader_struct_vader_support_profile$Counters_t*) l0)->f_peak_rss = l3;
    l3 = ((vader_struct_vader_support_profile$Counters_t*) l0)->f_copied;
    l4 = ((vader_struct_vader_support_profile$Counters_t*) l2)->f_copied;
    l5 = ((vader_struct_vader_support_profile$Counters_t*) l1)->f_copied;
    l4 = vader_chk_sub(i64, l4, l5);
    l3 = vader_chk_add(i64, l3, l4);
    ((vader_struct_vader_support_profile$Counters_t*) l0)->f_copied = l3;
    l3 = ((vader_struct_vader_support_profile$Counters_t*) l0)->f_allocated;
    l4 = ((vader_struct_vader_support_profile$Counters_t*) l2)->f_allocated;
    l5 = ((vader_struct_vader_support_profile$Counters_t*) l1)->f_allocated;
    l4 = vader_chk_sub(i64, l4, l5);
    l3 = vader_chk_add(i64, l3, l4);
    ((vader_struct_vader_support_profile$Counters_t*) l0)->f_allocated = l3;
    l3 = ((vader_struct_vader_support_profile$Counters_t*) l0)->f_allocations;
    l4 = ((vader_struct_vader_support_profile$Counters_t*) l2)->f_allocations;
    l5 = ((vader_struct_vader_support_profile$Counters_t*) l1)->f_allocations;
    l4 = vader_chk_sub(i64, l4, l5);
    l3 = vader_chk_add(i64, l3, l4);
    ((vader_struct_vader_support_profile$Counters_t*) l0)->f_allocations = l3;
    l3 = ((vader_struct_vader_support_profile$Counters_t*) l0)->f_collections;
    l4 = ((vader_struct_vader_support_profile$Counters_t*) l2)->f_collections;
    l5 = ((vader_struct_vader_support_profile$Counters_t*) l1)->f_collections;
    l4 = vader_chk_sub(i64, l4, l5);
    l3 = vader_chk_add(i64, l3, l4);
    ((vader_struct_vader_support_profile$Counters_t*) l0)->f_collections = l3;
    return;
}

static vader_string_t vader_support_profile$open_name(vader_box_t l0) {
    uint8_t t0;
    vader_string_t t1;
    if (!(l0.tag == 0u)) {
        t0 = ((uint8_t) l0.payload.i);
        t1 = vader_support_profile$phase_name(t0);
        return t1;
    }
    return 2522u;
}

static vader_string_t vader_support_profile$phase_name(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 2380u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 2937u;
    } else if (l0 == INT32_C(2)) {
        l1 = 1867u;
    } else if (l0 == INT32_C(3)) {
        l1 = 2401u;
    } else if (l0 == INT32_C(4)) {
        l1 = 2599u;
    } else if (l0 == INT32_C(5)) {
        l1 = 1833u;
    } else if (l0 == INT32_C(6)) {
        l1 = 1834u;
    } else if (l0 == INT32_C(7)) {
        l1 = 2003u;
    } else if (l0 == INT32_C(8)) {
        l1 = 1760u;
    } else if (l0 == INT32_C(9)) {
        l1 = 1773u;
    } else if (l0 == INT32_C(10)) {
        l1 = 3175u;
    } else {
        if (!(l0 == INT32_C(11))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 2613u;
    }
    return l1;
}

void vader_support_profile$prof_begin(uint8_t l0) {
    void* l1 = NULL;
    void* l5 = NULL;
    vader_box_t l2 = vader_box_null();
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    int64_t l6;
    bool t0;
    uint8_t t1;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l1, &l5 };
    vader_string_t* gc_atom_roots[3] = { &l3, &l4, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_support_profile$profiling();
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l1 = vader_support_profile$profiler();
    l2 = ((vader_struct_vader_support_profile$Profiler_t*) l1)->f_open;
    if (!(l2.tag == 0u)) {
        l3 = vader_support_profile$phase_name(l0);
        l3 = concat_3(1020u, l3, 152u);
        t1 = ((uint8_t) l2.payload.i);
        t2 = vader_support_profile$phase_name(t1);
        l4 = concat_2(t2, 364u);
        t2 = concat_2(l3, l4);
        std_io$eprintln__string(t2);
    }
    ((vader_struct_vader_support_profile$Profiler_t*) l1)->f_open = vader_box_i32(498u, (int32_t)(uint32_t) l0);
    VADER_WRITE_BARRIER((vader_struct_vader_support_profile$Profiler_t*) l1);
    l5 = vader_support_profile$read_counters();
    ((vader_struct_vader_support_profile$Profiler_t*) l1)->f_start = l5;
    VADER_WRITE_BARRIER((vader_struct_vader_support_profile$Profiler_t*) l1);
    l6 = std_time$monotonic();
    ((vader_struct_vader_support_profile$Profiler_t*) l1)->f_started = l6;
    { vader_gc_top = gc_frame.prev; return; }
}

void vader_support_profile$prof_end(uint8_t l0) {
    void* l1 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    int64_t l2, l7;
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    bool t0;
    int64_t t1;
    vader_string_t t2 = 0;
    void** gc_raw_roots[4] = { &l1, &l5, &l6, &l8 };
    vader_string_t* gc_atom_roots[3] = { &l3, &l4, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_support_profile$profiling();
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l1 = vader_support_profile$profiler();
    l2 = std_time$since(((vader_struct_vader_support_profile$Profiler_t*) l1)->f_started);
    if (!(!(vader_box_eq(((vader_struct_vader_support_profile$Profiler_t*) l1)->f_open, vader_box_i32(498u, (int32_t)(uint32_t) l0))))) {
        l5 = ((vader_struct_vader_support_profile$Profiler_t*) l1)->f_totals;
        l6 = (void*) &vader_fn_static___lambda_vader_support_profile_0;
        l5 = std_collections$get_or_put_with__vader_support_profile_ProfPhase__vader_support_profile_PassTotals(l5, l0, l6);
        l7 = ((vader_struct_vader_support_profile$PassTotals_t*) l5)->f_wall_ns;
        l2 = vader_chk_add(i64, l7, l2);
        ((vader_struct_vader_support_profile$PassTotals_t*) l5)->f_wall_ns = l2;
        t1 = ((vader_struct_vader_support_profile$PassTotals_t*) l5)->f_calls;
        l2 = vader_chk_add(i64, t1, INT64_C(1));
        ((vader_struct_vader_support_profile$PassTotals_t*) l5)->f_calls = l2;
        l5 = ((vader_struct_vader_support_profile$PassTotals_t*) l5)->f_change;
        l6 = ((vader_struct_vader_support_profile$Profiler_t*) l1)->f_start;
        l8 = vader_support_profile$read_counters();
        vader_support_profile$add_change(l5, l6, l8);
        ((vader_struct_vader_support_profile$Profiler_t*) l1)->f_open = vader_box_obj(0u, NULL);
        VADER_WRITE_BARRIER((vader_struct_vader_support_profile$Profiler_t*) l1);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = vader_support_profile$phase_name(l0);
    l3 = concat_3(1021u, l3, 405u);
    t2 = vader_support_profile$open_name(((vader_struct_vader_support_profile$Profiler_t*) l1)->f_open);
    l4 = concat_2(t2, 363u);
    t2 = concat_2(l3, l4);
    std_io$eprintln__string(t2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_support_profile$profiler(void) {
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
    t0 = vader_global_9;
    if (t0 == INT32_C(2)) {
        t1 = vader_global_10;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_global_11;
    l0 = std_runtime_scheduler$gate_or_new(t2);
    vader_global_11 = vader_ref_box(l0);
    l1 = (void*) &vader_fn_static_vader_support_profile$profiler$keep;
    t3 = std_runtime_scheduler$run_gated(l0, l1);
    if (!(t3)) {
        vader_unreachable("singleton `profiler` called while it initialises");
    }
    t1 = vader_global_10;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

void vader_support_profile$profiler$keep(void) {
    int32_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_global_9;
    if (!(t0 == INT32_C(2))) {
        t1 = vader_support_profile$profiler$singleton();
        vader_global_10 = t1;
        vader_global_9 = INT32_C(2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_support_profile$profiler$singleton(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(29u, 0u, 1u, 498u);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(33u, 0u, 0u, 504u);
    l1 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(27u, 0u, 7u, 496u);
    l2 = (void*) _a2_arr;
    vader_struct_std_collections$Map__vader_support_profile_ProfPhase__Any_t* _a3_obj = (vader_struct_std_collections$Map__vader_support_profile_ProfPhase__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__vader_support_profile_ProfPhase__Any_t));
    vader_obj_header_init(_a3_obj, 832u);
    _a3_obj->f_ekeys = l0;
    _a3_obj->f_evals = l1;
    _a3_obj->f_index = l2;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l0 = (void*) _a3_obj;
    vader_struct_vader_support_profile$Counters_t* _a4_obj = (vader_struct_vader_support_profile$Counters_t*) vader_gc_alloc(sizeof(vader_struct_vader_support_profile$Counters_t));
    vader_obj_header_init(_a4_obj, 1674u);
    _a4_obj->f_peak_rss = INT64_C(0);
    _a4_obj->f_copied = INT64_C(0);
    _a4_obj->f_allocated = INT64_C(0);
    _a4_obj->f_allocations = INT64_C(0);
    _a4_obj->f_collections = INT64_C(0);
    l1 = (void*) _a4_obj;
    vader_struct_vader_support_profile$Profiler_t* _a5_obj = (vader_struct_vader_support_profile$Profiler_t*) vader_gc_alloc(sizeof(vader_struct_vader_support_profile$Profiler_t));
    vader_obj_header_init(_a5_obj, 1676u);
    _a5_obj->f_totals = l0;
    _a5_obj->f_open = vader_box_obj(0u, NULL);
    _a5_obj->f_start = l1;
    _a5_obj->f_started = INT64_C(0);
    t0 = (void*) _a5_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_support_profile$profiling(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    int32_t t0;
    bool t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_global_6;
    if (t0 == INT32_C(2)) {
        t1 = vader_global_7;
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_global_8;
    l0 = std_runtime_scheduler$gate_or_new(t2);
    vader_global_8 = vader_ref_box(l0);
    l1 = (void*) &vader_fn_static_vader_support_profile$profiling$keep;
    t1 = std_runtime_scheduler$run_gated(l0, l1);
    if (!(t1)) {
        vader_unreachable("singleton `profiling` called while it initialises");
    }
    t1 = vader_global_7;
    { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

void vader_support_profile$profiling$keep(void) {
    int32_t t0;
    bool t1;
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_global_6;
    if (!(t0 == INT32_C(2))) {
        t1 = vader_support_profile$profiling$singleton();
        vader_global_7 = t1;
        vader_global_6 = INT32_C(2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_support_profile$profiling$singleton(void) {
    bool t0;
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = std_env$is_env_flag_on(988u);
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    vader_host_std_runtime$count_allocations();
    { vader_gc_top = gc_frame.prev; return true; }
}

static void* vader_support_profile$read_counters(void) {
    int64_t l0, l1, l2, l3, l4;
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l0 = std_runtime$peak_resident_bytes();
    l1 = vader_host_std_runtime$bytes_copied();
    l2 = vader_host_std_runtime$allocated_bytes();
    l3 = vader_host_std_runtime$allocations();
    l4 = vader_host_std_runtime$collections();
    vader_struct_vader_support_profile$Counters_t* _a0_obj = (vader_struct_vader_support_profile$Counters_t*) vader_gc_alloc(sizeof(vader_struct_vader_support_profile$Counters_t));
    vader_obj_header_init(_a0_obj, 1674u);
    _a0_obj->f_peak_rss = l0;
    _a0_obj->f_copied = l1;
    _a0_obj->f_allocated = l2;
    _a0_obj->f_allocations = l3;
    _a0_obj->f_collections = l4;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}
