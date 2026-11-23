#include "bootstrap.split.h"

static void vader_support_profile$add_change(void* l0, void* l1, void* l2);
static void* vader_support_profile$build_log(void);
static void* vader_support_profile$build_log$singleton(void);
static vader_string_t vader_support_profile$display_duration(int64_t l0);
static void vader_support_profile$log_begin(uint8_t l0);
static void vader_support_profile$log_end(uint8_t l0, int64_t l1);
static bool vader_support_profile$measuring(void);
static vader_string_t vader_support_profile$open_name(vader_box_t l0);
static vader_string_t vader_support_profile$painted_name(int64_t l0, vader_string_t l1);
static vader_string_t vader_support_profile$phase_name(uint8_t l0);
static void vader_support_profile$print_line(int64_t l0, vader_string_t l1, vader_string_t l2, int64_t l3);
static void vader_support_profile$print_step(void* l0);
static void* vader_support_profile$profiler(void);
static void* vader_support_profile$profiler$singleton(void);
static bool vader_support_profile$profiling(void);
static bool vader_support_profile$profiling$singleton(void);
static void* vader_support_profile$read_counters(void);
static vader_string_t vader_support_profile$right(vader_string_t l0, int64_t l1);
static vader_string_t vader_support_profile$stage_detail(void* l0);
static int32_t vader_support_profile$step_of(uint8_t l0);

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

static void* vader_support_profile$build_log(void) {
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
    t0 = vader_global_10;
    if (t0 == INT32_C(2)) {
        t1 = vader_global_11;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    std_runtime_scheduler$monitor_enter_to_publish();
    t2 = vader_global_14;
    l0 = std_runtime_scheduler$gate_or_new(t2);
    vader_global_14 = vader_ref_box(l0);
    l1 = (void*) &vader_fn_static_vader_support_profile$build_log$keep;
    t3 = std_runtime_scheduler$run_gated(l0, l1);
    if (!(t3)) {
        vader_unreachable("singleton `build_log` called while it initialises");
    }
    t1 = vader_global_11;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

void vader_support_profile$build_log$keep(void) {
    int32_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_global_10;
    if (!(t0 == INT32_C(2))) {
        t1 = vader_support_profile$build_log$singleton();
        vader_global_11 = t1;
        vader_global_10 = INT32_C(2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_support_profile$build_log$singleton(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(441u, 0u, 13u, 2086u);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(443u, 0u, 13u, 2089u);
    l1 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(28u, 0u, 0u, 623u);
    l2 = (void*) _a2_arr;
    vader_struct_vader_support_profile$BuildLog_t* _a3_obj = (vader_struct_vader_support_profile$BuildLog_t*) vader_gc_alloc(sizeof(vader_struct_vader_support_profile$BuildLog_t));
    vader_obj_header_init(_a3_obj, 2084u);
    _a3_obj->f_verbose = false;
    _a3_obj->f_step = INT32_C(-1);
    _a3_obj->f_passes = l0;
    _a3_obj->f_note = 0u;
    _a3_obj->f_stages = l1;
    _a3_obj->f_built = l2;
    t0 = (void*) _a3_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_support_profile$display_duration(int64_t l0) {
    void* l1 = NULL;
    int64_t l2, l3;
    double t0;
    vader_string_t t1 = 0;
    vader_string_t t2 = 0;
    void** gc_raw_roots[1] = { &l1 };
    vader_string_t* gc_atom_roots[2] = { &t1, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if ((l0 < INT64_C(10000000))) {
        t0 = ((double) (int64_t) l0) / 1000000.0;
        t1 = std_numbers$to_fixed(t0, INT64_C(1));
        t2 = concat_2(t1, 228u);
        { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!((l0 < INT64_C(1000000000)))) {
        t0 = ((double) (int64_t) l0) / 1000000000.0;
        t1 = std_numbers$to_fixed(t0, INT64_C(2));
        t2 = concat_2(t1, 268u);
        { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = (void*) vader_buffer_new((size_t) INT64_C(23));
    l2 = INT64_C(0);
    l3 = vader_div_i64(l0, INT64_C(1000000));
    l2 = std_core$write_int(l1, l2, l3);
    l2 = std_core$write_string_at(l1, l2, 228u);
    t1 = std_core$finish_buffer(l1, l2);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_support_profile$log_begin(uint8_t l0) {
    void* l1 = NULL;
    int32_t l2, l3;
    int32_t t0;
    bool t1;
    void** gc_raw_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_global_10;
    if (t0 == INT32_C(2)) {
        l1 = vader_global_11;
    } else {
        l1 = vader_support_profile$build_log();
    }
    t1 = ((vader_struct_vader_support_profile$BuildLog_t*) l1)->f_verbose;
    if (!(t1)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l2 = vader_support_profile$step_of(l0);
    l3 = ((vader_struct_vader_support_profile$BuildLog_t*) l1)->f_step;
    if ((l2 > l3)) {
        vader_support_profile$print_step(l1);
        ((vader_struct_vader_support_profile$BuildLog_t*) l1)->f_step = l2;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_support_profile$log_end(uint8_t l0, int64_t l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    void* l7 = NULL;
    vader_string_t l3 = 0;
    int64_t l5, l6, l8;
    int32_t t0;
    bool t1;
    vader_string_t t2 = 0;
    int64_t t3;
    void** gc_raw_roots[3] = { &l2, &l4, &l7 };
    vader_string_t* gc_atom_roots[2] = { &l3, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_global_10;
    if (t0 == INT32_C(2)) {
        l2 = vader_global_11;
    } else {
        l2 = vader_support_profile$build_log();
    }
    t1 = ((vader_struct_vader_support_profile$BuildLog_t*) l2)->f_verbose;
    if (!(t1)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = vader_support_profile$phase_name(l0);
    l4 = ((vader_struct_vader_support_profile$BuildLog_t*) l2)->f_passes;
    l5 = vader_array_length(((vader_array_t*) l4));
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l7 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l6);
        t2 = ((vader_struct_vader_support_profile$PassTime_t*) l7)->f_name;
        if (t2 == l3) {
            t3 = ((vader_struct_vader_support_profile$PassTime_t*) l7)->f_ns;
            l8 = vader_chk_add(i64, t3, l1);
            ((vader_struct_vader_support_profile$PassTime_t*) l7)->f_ns = l8;
            { vader_gc_top = gc_frame.prev; return; }
        }
        l6 = (l6 + INT64_C(1));
    }
    l2 = ((vader_struct_vader_support_profile$BuildLog_t*) l2)->f_passes;
    vader_struct_vader_support_profile$PassTime_t* _a1_obj = (vader_struct_vader_support_profile$PassTime_t*) vader_gc_alloc(sizeof(vader_struct_vader_support_profile$PassTime_t));
    vader_obj_header_init(_a1_obj, 2086u);
    _a1_obj->f_name = l3;
    _a1_obj->f_ns = l1;
    l4 = (void*) _a1_obj;
    vader_array_push_ref((vader_array_t*) l2, l4);
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_support_profile$measuring(void) {
    bool l0;
    void* l1 = NULL;
    int32_t t0;
    bool t1;
    void** gc_raw_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_global_6;
    if (t0 == INT32_C(2)) {
        l0 = vader_global_7;
    } else {
        l0 = vader_support_profile$profiling();
    }
    if (l0) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    t0 = vader_global_10;
    if (t0 == INT32_C(2)) {
        l1 = vader_global_11;
    } else {
        l1 = vader_support_profile$build_log();
    }
    t1 = ((vader_struct_vader_support_profile$BuildLog_t*) l1)->f_verbose;
    { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

void vader_support_profile$note_stage(vader_string_t l0, bool l1, int64_t l2) {
    void* l3 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l9 = NULL;
    vader_box_t l4 = vader_box_null();
    int64_t l7, l8;
    int32_t t0;
    bool t1;
    int64_t t2;
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[4] = { &l3, &l5, &l6, &l9 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_global_10;
    if (t0 == INT32_C(2)) {
        l3 = vader_global_11;
    } else {
        l3 = vader_support_profile$build_log();
    }
    t1 = ((vader_struct_vader_support_profile$BuildLog_t*) l3)->f_verbose;
    if (!(t1)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l5 = ((vader_struct_vader_support_profile$BuildLog_t*) l3)->f_stages;
    vader_struct___lambda_env_vader_support_profile_4_t* _a0_obj = (vader_struct___lambda_env_vader_support_profile_4_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_support_profile_4_t));
    vader_obj_header_init(_a0_obj, 867u);
    _a0_obj->f_cap_0 = l0;
    l6 = (void*) _a0_obj;
    l4 = vader_box_obj(0u, NULL);
    l7 = vader_array_length(((vader_array_t*) l5));
    l8 = INT64_C(0);
    {
        while ((l8 < l7)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            l9 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l8);
            t1 = __lambda_vader_support_profile_3(l6, l9);
            if (t1) {
                l4 = vader_ref_box(l9);
                goto end_28;
            }
            l8 = (l8 + INT64_C(1));
        }
        l4 = vader_box_obj(0u, NULL);
    } end_28: ;
    if (l4.tag == 0u) {
        l5 = ((vader_struct_vader_support_profile$BuildLog_t*) l3)->f_stages;
        vader_struct_vader_support_profile$StageTime_t* _a2_obj = (vader_struct_vader_support_profile$StageTime_t*) vader_gc_alloc(sizeof(vader_struct_vader_support_profile$StageTime_t));
        vader_obj_header_init(_a2_obj, 2089u);
        _a2_obj->f_name = l0;
        _a2_obj->f_sources_ns = INT64_C(0);
        _a2_obj->f_bodies_ns = INT64_C(0);
        l6 = (void*) _a2_obj;
        vader_array_push_ref((vader_array_t*) l5, l6);
        l5 = ((vader_struct_vader_support_profile$BuildLog_t*) l3)->f_stages;
        t2 = vader_array_length(((vader_array_t*) ((vader_struct_vader_support_profile$BuildLog_t*) l3)->f_stages));
        l7 = vader_chk_sub(i64, t2, INT64_C(1));
        vader_array_t* _a3_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
        l3 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l7);
    } else {
        l3 = l4.payload.obj;
    }
    if (l1) {
        t2 = ((vader_struct_vader_support_profile$StageTime_t*) l3)->f_bodies_ns;
        l7 = vader_chk_add(i64, t2, l2);
        ((vader_struct_vader_support_profile$StageTime_t*) l3)->f_bodies_ns = l7;
        { vader_gc_top = gc_frame.prev; return; }
    }
    t2 = ((vader_struct_vader_support_profile$StageTime_t*) l3)->f_sources_ns;
    l7 = vader_chk_add(i64, t2, l2);
    ((vader_struct_vader_support_profile$StageTime_t*) l3)->f_sources_ns = l7;
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_string_t vader_support_profile$open_name(vader_box_t l0) {
    uint8_t t0;
    vader_string_t t1;
    if (!(l0.tag == 0u)) {
        t0 = ((uint8_t) l0.payload.i);
        t1 = vader_support_profile$phase_name(t0);
        return t1;
    }
    return 2994u;
}

static vader_string_t vader_support_profile$painted_name(int64_t l0, vader_string_t l1) {
    vader_string_t l2 = 0;
    vader_string_t t0 = 0;
    vader_string_t* gc_atom_roots[3] = { &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l0 == INT64_C(0)) {
        t0 = std_tty$cyan(l1);
        l2 = std_tty$bold(t0);
        { vader_string_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT64_C(2)) {
        l2 = std_tty$magenta(l1);
    } else {
        l2 = l1;
    }
    { vader_string_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_support_profile$phase_name(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 2833u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 3416u;
    } else if (l0 == INT32_C(2)) {
        l1 = 2263u;
    } else if (l0 == INT32_C(3)) {
        l1 = 2855u;
    } else if (l0 == INT32_C(4)) {
        l1 = 3081u;
    } else if (l0 == INT32_C(5)) {
        l1 = 2227u;
    } else if (l0 == INT32_C(6)) {
        l1 = 2228u;
    } else if (l0 == INT32_C(7)) {
        l1 = 2420u;
    } else if (l0 == INT32_C(8)) {
        l1 = 2146u;
    } else if (l0 == INT32_C(9)) {
        l1 = 2163u;
    } else if (l0 == INT32_C(10)) {
        l1 = 2224u;
    } else if (l0 == INT32_C(11)) {
        l1 = 2827u;
    } else if (l0 == INT32_C(12)) {
        l1 = 3678u;
    } else {
        if (!(l0 == INT32_C(13))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 3092u;
    }
    return l1;
}

static void vader_support_profile$print_line(int64_t l0, vader_string_t l1, vader_string_t l2, int64_t l3) {
    int64_t l4;
    vader_string_t l5 = 0;
    vader_string_t l6 = 0;
    vader_string_t l7 = 0;
    vader_string_t l8 = 0;
    vader_string_t t0 = 0;
    vader_string_t* gc_atom_roots[7] = { &l1, &l2, &l5, &l6, &l7, &l8, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 7u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l4 = vader_chk_mul(i64, INT64_C(2), l0);
    l4 = vader_chk_add(i64, INT64_C(2), l4);
    l5 = std_string$pad_end(0u, l4, 32u);
    l4 = vader_chk_mul(i64, INT64_C(2), l0);
    l4 = vader_chk_sub(i64, INT64_C(14), l4);
    l6 = std_string$pad_end(l1, l4, 32u);
    l6 = vader_support_profile$painted_name(l0, l6);
    t0 = vader_support_profile$display_duration(l3);
    l7 = vader_support_profile$right(t0, INT64_C(7));
    if ((l3 >= INT64_C(1000000000))) {
        l8 = std_tty$yellow(l7);
    } else {
        l8 = l7;
    }
    t0 = std_string$pad_end(l2, INT64_C(32), 32u);
    l7 = std_tty$dim(t0);
    t0 = concat_6(l5, l6, 19u, l7, 19u, l8);
    std_console$eprintln__string(t0);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_support_profile$print_step(void* l0) {
    int64_t l1, l3, l4, l5, l13, l14;
    void* l2 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    int32_t l6;
    vader_string_t l7 = 0;
    vader_string_t l8 = 0;
    bool t0;
    int32_t t1;
    void* t2 = NULL;
    vader_box_t t3 = vader_box_null();
    vader_string_t t4 = 0;
    int64_t t5;
    vader_box_t* gc_roots[1] = { &t3 };
    void** gc_raw_roots[7] = { &l0, &l2, &l9, &l10, &l11, &l12, &t2 };
    vader_string_t* gc_atom_roots[3] = { &l7, &l8, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_support_profile$BuildLog_t*) l0)->f_verbose;
    if (t0) {
        t1 = ((vader_struct_vader_support_profile$BuildLog_t*) l0)->f_step;
        if ((t1 < INT32_C(0))) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        l1 = INT64_C(0);
        l2 = ((vader_struct_vader_support_profile$BuildLog_t*) l0)->f_passes;
        l3 = vader_array_length(((vader_array_t*) l2));
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            t2 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l4);
            l5 = ((vader_struct_vader_support_profile$PassTime_t*) t2)->f_ns;
            l1 = vader_chk_add(i64, l1, l5);
            l4 = (l4 + INT64_C(1));
        }
        l2 = (void*) &vader_data_27;
        l6 = ((vader_struct_vader_support_profile$BuildLog_t*) l0)->f_step;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        t3 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l6];
        l7 = t3.payload.s;
        l8 = ((vader_struct_vader_support_profile$BuildLog_t*) l0)->f_note;
        vader_support_profile$print_line(INT64_C(0), l7, l8, l1);
        t4 = ((vader_struct_vader_support_profile$BuildLog_t*) l0)->f_note;
        if (t4 == 0u) {
            t5 = vader_array_length(((vader_array_t*) ((vader_struct_vader_support_profile$BuildLog_t*) l0)->f_passes));
            if ((t5 > INT64_C(1))) {
                l2 = ((vader_struct_vader_support_profile$BuildLog_t*) l0)->f_passes;
                l1 = vader_array_length(((vader_array_t*) l2));
                l3 = INT64_C(0);
                while ((l3 < l1)) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                    l9 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l3);
                    t0 = __lambda_vader_support_profile_1(l9);
                    if (t0) {
                        l10 = l9;
                        l7 = ((vader_struct_vader_support_profile$PassTime_t*) l10)->f_name;
                        l4 = ((vader_struct_vader_support_profile$PassTime_t*) l10)->f_ns;
                        vader_support_profile$print_line(INT64_C(1), l7, 0u, l4);
                    }
                    l3 = (l3 + INT64_C(1));
                }
            }
        }
        l9 = ((vader_struct_vader_support_profile$BuildLog_t*) l0)->f_stages;
        vader_array_t* _a3_arr = vader_array_new(443u, 0u, 13u, 2089u);
        l10 = (void*) _a3_arr;
        l1 = vader_array_length(((vader_array_t*) l9));
        l3 = INT64_C(0);
        while ((l3 < l1)) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) l9);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            l11 = vader_array_ref_load_obj(_a4_slotarr->buf, vader_array_offset(_a4_slotarr) + (size_t) l3);
            t0 = __lambda_vader_support_profile_2(l11);
            if (t0) {
                l12 = l11;
                vader_array_push_ref((vader_array_t*) l10, l12);
            }
            l3 = (l3 + INT64_C(1));
        }
        l2 = l10;
        t0 = std_core$is_empty__vader_support_profile_StageTime(l2);
        if (!(t0)) {
            l1 = INT64_C(0);
            l9 = l2;
            l3 = vader_array_length(((vader_array_t*) l9));
            l4 = INT64_C(0);
            while ((l4 < l3)) {
                vader_array_t* _a5_slotarr = ((vader_array_t*) l9);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                l10 = vader_array_ref_load_obj(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) l4);
                l5 = ((vader_struct_vader_support_profile$StageTime_t*) l10)->f_sources_ns;
                l13 = ((vader_struct_vader_support_profile$StageTime_t*) l10)->f_bodies_ns;
                l14 = vader_chk_add(i64, l5, l13);
                l1 = vader_chk_add(i64, l1, l14);
                l4 = (l4 + INT64_C(1));
            }
            vader_support_profile$print_line(INT64_C(1), 3202u, 0u, l1);
            l1 = vader_array_length(((vader_array_t*) l2));
            l3 = INT64_C(0);
            while ((l3 < l1)) {
                vader_array_t* _a6_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l3)
                l9 = vader_array_ref_load_obj(_a6_slotarr->buf, vader_array_offset(_a6_slotarr) + (size_t) l3);
                l7 = ((vader_struct_vader_support_profile$StageTime_t*) l9)->f_name;
                l8 = vader_support_profile$stage_detail(l9);
                l4 = ((vader_struct_vader_support_profile$StageTime_t*) l9)->f_sources_ns;
                l5 = ((vader_struct_vader_support_profile$StageTime_t*) l9)->f_bodies_ns;
                l13 = vader_chk_add(i64, l4, l5);
                vader_support_profile$print_line(INT64_C(2), l7, l8, l13);
                l3 = (l3 + INT64_C(1));
            }
        }
        vader_array_clear((vader_array_t*) ((vader_struct_vader_support_profile$BuildLog_t*) l0)->f_passes);
        vader_array_clear((vader_array_t*) ((vader_struct_vader_support_profile$BuildLog_t*) l0)->f_stages);
        ((vader_struct_vader_support_profile$BuildLog_t*) l0)->f_note = 0u;
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

void vader_support_profile$prof_begin(uint8_t l0) {
    void* l1 = NULL;
    void* l6 = NULL;
    vader_box_t l2 = vader_box_null();
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    bool l5;
    int64_t l7;
    bool t0;
    int32_t t1;
    uint8_t t2;
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l1, &l6 };
    vader_string_t* gc_atom_roots[3] = { &l3, &l4, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_support_profile$measuring();
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    t1 = vader_global_4;
    if (t1 == INT32_C(2)) {
        l1 = vader_global_5;
    } else {
        l1 = vader_support_profile$profiler();
    }
    l2 = ((vader_struct_vader_support_profile$Profiler_t*) l1)->f_open;
    if (!(l2.tag == 0u)) {
        l3 = vader_support_profile$phase_name(l0);
        l3 = concat_3(1222u, l3, 190u);
        t2 = ((uint8_t) l2.payload.i);
        t3 = vader_support_profile$phase_name(t2);
        l4 = concat_2(t3, 424u);
        t3 = concat_2(l3, l4);
        std_console$eprintln__string(t3);
    }
    vader_support_profile$log_begin(l0);
    ((vader_struct_vader_support_profile$Profiler_t*) l1)->f_open = vader_box_i32(628u, (int32_t)(uint32_t) l0);
    VADER_WRITE_BARRIER((vader_struct_vader_support_profile$Profiler_t*) l1);
    t1 = vader_global_6;
    if (t1 == INT32_C(2)) {
        l5 = vader_global_7;
    } else {
        l5 = vader_support_profile$profiling();
    }
    if (l5) {
        l6 = vader_support_profile$read_counters();
        ((vader_struct_vader_support_profile$Profiler_t*) l1)->f_start = l6;
        VADER_WRITE_BARRIER((vader_struct_vader_support_profile$Profiler_t*) l1);
        l7 = std_time$monotonic();
        ((vader_struct_vader_support_profile$Profiler_t*) l1)->f_started = l7;
        { vader_gc_top = gc_frame.prev; return; }
    }
    l7 = std_time$monotonic();
    ((vader_struct_vader_support_profile$Profiler_t*) l1)->f_started = l7;
    { vader_gc_top = gc_frame.prev; return; }
}

void vader_support_profile$prof_end(uint8_t l0) {
    void* l1 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    int64_t l2, l5;
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    bool l6;
    bool t0;
    int32_t t1;
    vader_string_t t2 = 0;
    int64_t t3;
    void** gc_raw_roots[3] = { &l1, &l7, &l8 };
    vader_string_t* gc_atom_roots[3] = { &l3, &l4, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_support_profile$measuring();
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    t1 = vader_global_4;
    if (t1 == INT32_C(2)) {
        l1 = vader_global_5;
    } else {
        l1 = vader_support_profile$profiler();
    }
    l2 = std_time$since(((vader_struct_vader_support_profile$Profiler_t*) l1)->f_started);
    if (!(vader_box_eq(((vader_struct_vader_support_profile$Profiler_t*) l1)->f_open, vader_box_i32(628u, (int32_t)(uint32_t) l0)))) {
        l3 = vader_support_profile$phase_name(l0);
        l3 = concat_3(1223u, l3, 468u);
        t2 = vader_support_profile$open_name(((vader_struct_vader_support_profile$Profiler_t*) l1)->f_open);
        l4 = concat_2(t2, 423u);
        t2 = concat_2(l3, l4);
        std_console$eprintln__string(t2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l5 = l2;
    vader_support_profile$log_end(l0, l5);
    ((vader_struct_vader_support_profile$Profiler_t*) l1)->f_open = vader_box_obj(0u, NULL);
    VADER_WRITE_BARRIER((vader_struct_vader_support_profile$Profiler_t*) l1);
    t1 = vader_global_6;
    if (t1 == INT32_C(2)) {
        l6 = vader_global_7;
    } else {
        l6 = vader_support_profile$profiling();
    }
    if (!(l6)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l7 = ((vader_struct_vader_support_profile$Profiler_t*) l1)->f_totals;
    l8 = (void*) &vader_fn_static___lambda_vader_support_profile_0;
    l7 = std_collections$get_or_put_with__vader_support_profile_ProfPhase__vader_support_profile_PassTotals(l7, l0, l8);
    l5 = ((vader_struct_vader_support_profile$PassTotals_t*) l7)->f_wall_ns;
    l2 = vader_chk_add(i64, l5, l2);
    ((vader_struct_vader_support_profile$PassTotals_t*) l7)->f_wall_ns = l2;
    t3 = ((vader_struct_vader_support_profile$PassTotals_t*) l7)->f_calls;
    l2 = vader_chk_add(i64, t3, INT64_C(1));
    ((vader_struct_vader_support_profile$PassTotals_t*) l7)->f_calls = l2;
    l7 = ((vader_struct_vader_support_profile$PassTotals_t*) l7)->f_change;
    l1 = ((vader_struct_vader_support_profile$Profiler_t*) l1)->f_start;
    l8 = vader_support_profile$read_counters();
    vader_support_profile$add_change(l7, l1, l8);
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
    t0 = vader_global_4;
    if (t0 == INT32_C(2)) {
        t1 = vader_global_5;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    std_runtime_scheduler$monitor_enter_to_publish();
    t2 = vader_global_12;
    l0 = std_runtime_scheduler$gate_or_new(t2);
    vader_global_12 = vader_ref_box(l0);
    l1 = (void*) &vader_fn_static_vader_support_profile$profiler$keep;
    t3 = std_runtime_scheduler$run_gated(l0, l1);
    if (!(t3)) {
        vader_unreachable("singleton `profiler` called while it initialises");
    }
    t1 = vader_global_5;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

void vader_support_profile$profiler$keep(void) {
    int32_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_global_4;
    if (!(t0 == INT32_C(2))) {
        t1 = vader_support_profile$profiler$singleton();
        vader_global_5 = t1;
        vader_global_4 = INT32_C(2);
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
    vader_array_t* _a0_arr = vader_array_new(31u, 0u, 1u, 628u);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(35u, 0u, 0u, 634u);
    l1 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 626u);
    l2 = (void*) _a2_arr;
    vader_struct_std_collections$Map__vader_support_profile_ProfPhase__Any_t* _a3_obj = (vader_struct_std_collections$Map__vader_support_profile_ProfPhase__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__vader_support_profile_ProfPhase__Any_t));
    vader_obj_header_init(_a3_obj, 1060u);
    _a3_obj->f_ekeys = l0;
    _a3_obj->f_evals = l1;
    _a3_obj->f_index = l2;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l0 = (void*) _a3_obj;
    vader_struct_vader_support_profile$Counters_t* _a4_obj = (vader_struct_vader_support_profile$Counters_t*) vader_gc_alloc(sizeof(vader_struct_vader_support_profile$Counters_t));
    vader_obj_header_init(_a4_obj, 2085u);
    _a4_obj->f_peak_rss = INT64_C(0);
    _a4_obj->f_copied = INT64_C(0);
    _a4_obj->f_allocated = INT64_C(0);
    _a4_obj->f_allocations = INT64_C(0);
    _a4_obj->f_collections = INT64_C(0);
    l1 = (void*) _a4_obj;
    vader_struct_vader_support_profile$Profiler_t* _a5_obj = (vader_struct_vader_support_profile$Profiler_t*) vader_gc_alloc(sizeof(vader_struct_vader_support_profile$Profiler_t));
    vader_obj_header_init(_a5_obj, 2088u);
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
    std_runtime_scheduler$monitor_enter_to_publish();
    t2 = vader_global_13;
    l0 = std_runtime_scheduler$gate_or_new(t2);
    vader_global_13 = vader_ref_box(l0);
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
    t0 = std_env$is_env_flag_on(1180u);
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    vader_host_std_core$Intrinsic$count_allocations();
    { vader_gc_top = gc_frame.prev; return true; }
}

static void* vader_support_profile$read_counters(void) {
    vader_box_t l0 = vader_box_null();
    int64_t l1, l2, l3, l4, l5;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l0 = std_runtime$peak_resident_bytes();
    if (l0.tag == 0u) {
        l1 = INT64_C(0);
    } else {
        l1 = ((int64_t) l0.payload.i);
    }
    l2 = vader_host_std_core$Intrinsic$bytes_copied();
    l3 = vader_host_std_core$Intrinsic$allocated_bytes();
    l4 = vader_host_std_core$Intrinsic$allocations();
    l5 = vader_host_std_core$Intrinsic$collections();
    vader_struct_vader_support_profile$Counters_t* _a0_obj = (vader_struct_vader_support_profile$Counters_t*) vader_gc_alloc(sizeof(vader_struct_vader_support_profile$Counters_t));
    vader_obj_header_init(_a0_obj, 2085u);
    _a0_obj->f_peak_rss = l1;
    _a0_obj->f_copied = l2;
    _a0_obj->f_allocated = l3;
    _a0_obj->f_allocations = l4;
    _a0_obj->f_collections = l5;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_support_profile$right(vader_string_t l0, int64_t l1) {
    vader_string_t t0;
    t0 = std_string$pad_start(l0, l1, 32u);
    return t0;
}

static vader_string_t vader_support_profile$stage_detail(void* l0) {
    void* l1 = NULL;
    vader_string_t l2 = 0;
    int64_t t0;
    vader_string_t t1 = 0;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[2] = { &l2, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 623u);
    l1 = (void*) _a0_arr;
    t0 = ((vader_struct_vader_support_profile$StageTime_t*) l0)->f_sources_ns;
    if ((t0 > INT64_C(0))) {
        t0 = ((vader_struct_vader_support_profile$StageTime_t*) l0)->f_sources_ns;
        l2 = vader_support_profile$display_duration(t0);
        l2 = concat_2(3196u, l2);
        vader_array_push_scalar((vader_array_t*) l1, vader_box_string(623u, l2));
    }
    t0 = ((vader_struct_vader_support_profile$StageTime_t*) l0)->f_bodies_ns;
    if ((t0 > INT64_C(0))) {
        t0 = ((vader_struct_vader_support_profile$StageTime_t*) l0)->f_bodies_ns;
        l2 = vader_support_profile$display_duration(t0);
        l2 = concat_2(2088u, l2);
        vader_array_push_scalar((vader_array_t*) l1, vader_box_string(623u, l2));
        l2 = 444u;
        t1 = std_string$join(l1, l2);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = 444u;
    t1 = std_string$join(l1, l2);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_support_profile$step_of(uint8_t l0) {
    int32_t l1;
    bool l2;
    if (l0 == INT32_C(0)) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(1);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(2);
    }
    if (l2) {
        l1 = INT32_C(0);
        return l1;
    }
    if (l0 == INT32_C(3)) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(4);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(5);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(6);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(7);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(8);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(12);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(13);
    }
    if (l2) {
        l1 = INT32_C(1);
    } else if (l0 == INT32_C(9)) {
        l1 = INT32_C(2);
    } else if (l0 == INT32_C(10)) {
        l1 = INT32_C(3);
    } else {
        if (!(l0 == INT32_C(11))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = INT32_C(4);
    }
    return l1;
}
