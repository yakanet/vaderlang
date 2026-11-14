#include "bootstrap.split.h"

static bool std_console$has_console_mode(void* l0);
static bool std_console$is_console(uint8_t l0);
static void* std_console$std_handle(uint8_t l0);
static bool std_console$stderr_is_console(void);
static bool std_console$stderr_is_console$singleton(void);
static bool std_console$stdout_is_console(void);
static bool std_console$stdout_is_console$singleton(void);
static void std_console$write(uint8_t l0, vader_string_t l1);
static int32_t std_console$write_bytes(uint8_t l0, void* l1, int64_t l2);
static bool std_console$write_text(uint8_t l0, vader_string_t l1);

void std_console$eprintln__string(vader_string_t l0) {
    vader_string_t l1 = 0;
    vader_string_t* gc_atom_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = concat_2(l0, 1u);
    std_console$write((uint8_t) 1, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static bool std_console$has_console_mode(void* l0) {
    void* l1 = NULL;
    bool t0;
    void** gc_raw_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(31u, 1u, 3u, 510u);
    ((int32_t*) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = (int32_t) INT32_C(0);
    l1 = (void*) _a0_arr;
    t0 = vader_host_system_windows$get_console_mode(l0, l1);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool std_console$is_console(uint8_t l0) {
    bool t0;
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(0)) {
        t0 = std_console$stdout_is_console();
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0 == INT32_C(1))) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    t0 = std_console$stderr_is_console();
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* std_console$std_handle(uint8_t l0) {
    void* t0;
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(0)) {
        t0 = vader_host_system_windows$get_std_handle((uint32_t) -11);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0 == INT32_C(1))) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    t0 = vader_host_system_windows$get_std_handle((uint32_t) -12);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool std_console$stderr_is_console(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    int32_t t0;
    bool t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_global_0;
    if (t0 == INT32_C(2)) {
        t1 = vader_global_1;
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_global_2;
    l0 = std_runtime_scheduler$gate_or_new(t2);
    vader_global_2 = vader_ref_box(l0);
    l1 = (void*) &vader_fn_static_std_console$stderr_is_console$keep;
    t1 = std_runtime_scheduler$run_gated(l0, l1);
    if (!(t1)) {
        vader_unreachable("singleton `stderr_is_console` called while it initialises");
    }
    t1 = vader_global_1;
    { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

void std_console$stderr_is_console$keep(void) {
    int32_t t0;
    bool t1;
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_global_0;
    if (!(t0 == INT32_C(2))) {
        t1 = std_console$stderr_is_console$singleton();
        vader_global_1 = t1;
        vader_global_0 = INT32_C(2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static bool std_console$stderr_is_console$singleton(void) {
    void* t0;
    bool t1;
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = std_console$std_handle((uint8_t) 1);
    t1 = std_console$has_console_mode(t0);
    { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool std_console$stdout_is_console(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    int32_t t0;
    bool t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_global_3;
    if (t0 == INT32_C(2)) {
        t1 = vader_global_4;
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_global_5;
    l0 = std_runtime_scheduler$gate_or_new(t2);
    vader_global_5 = vader_ref_box(l0);
    l1 = (void*) &vader_fn_static_std_console$stdout_is_console$keep;
    t1 = std_runtime_scheduler$run_gated(l0, l1);
    if (!(t1)) {
        vader_unreachable("singleton `stdout_is_console` called while it initialises");
    }
    t1 = vader_global_4;
    { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

void std_console$stdout_is_console$keep(void) {
    int32_t t0;
    bool t1;
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_global_3;
    if (!(t0 == INT32_C(2))) {
        t1 = std_console$stdout_is_console$singleton();
        vader_global_4 = t1;
        vader_global_3 = INT32_C(2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static bool std_console$stdout_is_console$singleton(void) {
    void* t0;
    bool t1;
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = std_console$std_handle((uint8_t) 0);
    t1 = std_console$has_console_mode(t0);
    { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void std_console$write(uint8_t l0, vader_string_t l1) {
    void* l2 = NULL;
    void* l6 = NULL;
    int64_t l3, l4, l5, l7, l9;
    int32_t l8;
    bool t0;
    void** gc_raw_roots[2] = { &l2, &l6 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = std_console$write_text(l0, l1);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l2 = vader_host_std_core$bytes(l1);
    l3 = INT64_C(0);
    for (;;) {
        l4 = vader_array_length(((vader_array_t*) l2));
        if (!((l3 >= l4))) {
            l5 = vader_array_length(((vader_array_t*) l2));
            vader_array_t* _a0_arr = vader_array_slice((vader_array_t*) l2, (int64_t) l3, (int64_t) l5);
            l6 = (void*) _a0_arr;
            l7 = vader_array_length(((vader_array_t*) l6));
            l8 = std_console$write_bytes(l0, l6, l7);
            if ((l8 <= INT32_C(0))) {
                { vader_gc_top = gc_frame.prev; return; }
            }
            l9 = ((int64_t) (int32_t) l8);
            l3 = vader_chk_add(i64, l3, l9);
            continue;
        }
        break;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static int32_t std_console$write_bytes(uint8_t l0, void* l1, int64_t l2) {
    void* l3 = NULL;
    void* l4;
    uint32_t l5;
    int32_t t0;
    bool t1;
    void** gc_raw_roots[2] = { &l1, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(31u, 1u, 3u, 510u);
    ((int32_t*) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = (int32_t) INT32_C(0);
    l3 = (void*) _a0_arr;
    l4 = std_console$std_handle(l0);
    t0 = ((int32_t) (int64_t) l2);
    l5 = (uint32_t) (int32_t) t0;
    t1 = vader_host_system_windows$write_file(l4, l1, l5, l3, vader_box_obj(0u, NULL));
    if (!(t1)) {
        { vader_gc_top = gc_frame.prev; return INT32_C(-1); }
    }
    { int32_t __vret = ((int32_t) (int64_t) l2); vader_gc_top = gc_frame.prev; return __vret; }
}

static bool std_console$write_text(uint8_t l0, vader_string_t l1) {
    int64_t l2;
    void* l3 = NULL;
    void* l6 = NULL;
    int32_t l4, l5;
    void* l7;
    uint32_t l8;
    bool t0;
    void* t1 = NULL;
    int32_t t2;
    void** gc_raw_roots[3] = { &l3, &l6, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_host_std_core$is_ascii(l1);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    t0 = std_console$is_console(l0);
    if (t0) {
        l2 = vader_host_std_core$byte_len(l1);
        vader_array_t* _a0_arr = vader_array_new(30u, 1u, 2u, 509u);
        ((uint16_t*) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = (uint16_t) INT32_C(0);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) l2);
        l3 = (void*) _a1_arr;
        l4 = ((int32_t) (int64_t) l2);
        l5 = ((int32_t) (int64_t) l2);
        l4 = vader_host_system_windows$multi_byte_to_wide_char((uint32_t) 65001, (uint32_t) 0, l1, l4, l3, l5);
        if ((l4 > INT32_C(0))) {
            vader_array_t* _a2_arr = vader_array_new(31u, 1u, 3u, 510u);
            ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 0u] = (int32_t) INT32_C(0);
            l6 = (void*) _a2_arr;
            l7 = std_console$std_handle(l0);
            t2 = l4;
            l8 = (uint32_t) (int32_t) t2;
            vader_host_system_windows$write_console_w(l7, l3, l8, l6, vader_box_obj(0u, NULL));
            { vader_gc_top = gc_frame.prev; return true; }
        }
        { vader_gc_top = gc_frame.prev; return true; }
    }
    { vader_gc_top = gc_frame.prev; return false; }
}
