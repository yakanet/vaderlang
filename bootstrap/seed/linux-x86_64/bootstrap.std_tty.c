#include "bootstrap.split.h"

static vader_string_t std_tty$escape(bool l0, vader_string_t l1);
static bool std_tty$is_tty(uint8_t l0);
static bool std_tty$no_color_set(void);
static bool std_tty$no_color_set$singleton(void);
static vader_string_t std_tty$paint(vader_string_t l0, vader_string_t l1);
static bool std_tty$probe_tty(uint8_t l0);
static bool std_tty$should_colorize(void);
static bool std_tty$stderr_is_tty(void);
static bool std_tty$stderr_is_tty$singleton(void);
static bool std_tty$stdout_is_tty(void);
static bool std_tty$stdout_is_tty$singleton(void);

static vader_string_t std_tty$escape(bool l0, vader_string_t l1) {
    vader_string_t t0 = 0;
    vader_string_t* gc_atom_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l0) {
        t0 = concat_3(13u, l1, 2455u);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return 0u; }
}

static bool std_tty$is_tty(uint8_t l0) {
    bool t0;
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(0)) {
        t0 = std_tty$stdout_is_tty();
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0 == INT32_C(1))) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    t0 = std_tty$stderr_is_tty();
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool std_tty$no_color_set(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    int32_t t0;
    bool t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_global_9;
    if (t0 == INT32_C(2)) {
        t1 = vader_global_10;
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_global_11;
    l0 = std_runtime_scheduler$gate_or_new(t2);
    vader_global_11 = vader_ref_box(l0);
    l1 = (void*) &vader_fn_static_std_tty$no_color_set$keep;
    t1 = std_runtime_scheduler$run_gated(l0, l1);
    if (!(t1)) {
        vader_unreachable("singleton `no_color_set` called while it initialises");
    }
    t1 = vader_global_10;
    { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

void std_tty$no_color_set$keep(void) {
    int32_t t0;
    bool t1;
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_global_9;
    if (!(t0 == INT32_C(2))) {
        t1 = std_tty$no_color_set$singleton();
        vader_global_10 = t1;
        vader_global_9 = INT32_C(2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static bool std_tty$no_color_set$singleton(void) {
    vader_box_t l0 = vader_box_null();
    vader_string_t l1 = 0;
    vader_string_t l2 = 0;
    vader_box_t* gc_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l0 = std_env$get_env(766u);
    if (l0.tag == 0u) {
        l1 = 0u;
        l2 = 0u;
        { bool __vret = l1 != l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = l0.payload.s;
    l2 = 0u;
    { bool __vret = l1 != l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t std_tty$paint(vader_string_t l0, vader_string_t l1) {
    bool l2;
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    vader_string_t t0 = 0;
    vader_string_t* gc_atom_roots[5] = { &l0, &l1, &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 5u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = std_tty$should_colorize();
    l3 = std_tty$escape(l2, l0);
    l4 = std_tty$escape(l2, 496u);
    t0 = concat_3(l3, l1, l4);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool std_tty$probe_tty(uint8_t l0) {
    int32_t t0;
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(0)) {
        t0 = vader_host_system_posix$sys_isatty(INT32_C(1));
        { bool __vret = t0 != INT32_C(0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0 == INT32_C(1))) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    t0 = vader_host_system_posix$sys_isatty(INT32_C(2));
    { bool __vret = t0 != INT32_C(0); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t std_tty$red(vader_string_t l0) {
    vader_string_t t0;
    t0 = std_tty$paint(503u, l0);
    return t0;
}

static bool std_tty$should_colorize(void) {
    bool l0;
    bool t0;
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = std_tty$is_tty((uint8_t) 0);
    if (t0) {
        l0 = true;
    } else {
        l0 = std_tty$is_tty((uint8_t) 1);
    }
    if (l0) {
        t0 = std_tty$no_color_set();
        { bool __vret = !(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static bool std_tty$stderr_is_tty(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    int32_t t0;
    bool t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_global_12;
    if (t0 == INT32_C(2)) {
        t1 = vader_global_13;
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_global_14;
    l0 = std_runtime_scheduler$gate_or_new(t2);
    vader_global_14 = vader_ref_box(l0);
    l1 = (void*) &vader_fn_static_std_tty$stderr_is_tty$keep;
    t1 = std_runtime_scheduler$run_gated(l0, l1);
    if (!(t1)) {
        vader_unreachable("singleton `stderr_is_tty` called while it initialises");
    }
    t1 = vader_global_13;
    { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

void std_tty$stderr_is_tty$keep(void) {
    int32_t t0;
    bool t1;
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_global_12;
    if (!(t0 == INT32_C(2))) {
        t1 = std_tty$stderr_is_tty$singleton();
        vader_global_13 = t1;
        vader_global_12 = INT32_C(2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static bool std_tty$stderr_is_tty$singleton(void) {
    bool t0;
    t0 = std_tty$probe_tty((uint8_t) 1);
    return t0;
}

static bool std_tty$stdout_is_tty(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    int32_t t0;
    bool t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_global_15;
    if (t0 == INT32_C(2)) {
        t1 = vader_global_16;
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_global_17;
    l0 = std_runtime_scheduler$gate_or_new(t2);
    vader_global_17 = vader_ref_box(l0);
    l1 = (void*) &vader_fn_static_std_tty$stdout_is_tty$keep;
    t1 = std_runtime_scheduler$run_gated(l0, l1);
    if (!(t1)) {
        vader_unreachable("singleton `stdout_is_tty` called while it initialises");
    }
    t1 = vader_global_16;
    { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

void std_tty$stdout_is_tty$keep(void) {
    int32_t t0;
    bool t1;
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_global_15;
    if (!(t0 == INT32_C(2))) {
        t1 = std_tty$stdout_is_tty$singleton();
        vader_global_16 = t1;
        vader_global_15 = INT32_C(2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static bool std_tty$stdout_is_tty$singleton(void) {
    bool t0;
    t0 = std_tty$probe_tty((uint8_t) 0);
    return t0;
}

vader_string_t std_tty$yellow(vader_string_t l0) {
    vader_string_t t0;
    t0 = std_tty$paint(504u, l0);
    return t0;
}
