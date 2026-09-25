#include "bootstrap.split.h"

static vader_string_t std_tty_escape(bool l0, vader_string_t l1);
static bool std_tty_is_tty(uint8_t l0);
static vader_string_t std_tty_paint(vader_string_t l0, vader_string_t l1);
static bool std_tty_should_colorize(void);
static size_t std_tty_tty_slot(uint8_t l0);

static vader_string_t std_tty_escape(bool l0, vader_string_t l1) {
    vader_string_t l2 = 0;
    vader_string_t* gc_atom_roots[2] = { &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l0) {
        l2 = concat_3(7u, l1, 1729u);
    } else {
        l2 = 0u;
    }
    { vader_string_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool std_tty_is_tty(uint8_t l0) {
    size_t l1;
    uint32_t l2;
    void* l3;
    void* l4 = NULL;
    void* t0 = NULL;
    int32_t t1, t4;
    ptrdiff_t t2;
    bool t3;
    void** gc_raw_roots[2] = { &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = std_tty_tty_slot(l0);
    t0 = (void*) &vader_data_14;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1];
    if ((t1 >= INT32_C(0))) {
        t0 = (void*) &vader_data_14;
        vader_array_t* _a1_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
        t1 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l1];
        { bool __vret = t1 != INT32_C(0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = (void*) &vader_data_14;
    vader_array_t* _a2_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l1)
    ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l1] = (int32_t) INT32_C(0);
    if (l1 == INT64_C(1)) {
        l2 = (uint32_t) -12;
    } else {
        l2 = (uint32_t) -11;
    }
    l3 = vader_host_system_windows_get_std_handle(l2);
    t2 = (ptrdiff_t) (void*) l3;
    if (t2 == INT64_C(-1)) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    vader_array_t* _a3_arr = vader_array_new(13u, 1u, 3u, 198u);
    ((int32_t*) _a3_arr->buf->slots)[_a3_arr->offset + 0u] = (int32_t) INT32_C(0);
    l4 = (void*) _a3_arr;
    t3 = vader_host_system_windows_get_console_mode(l3, l4);
    if (!(t3)) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    vader_array_t* _a4_slotarr = ((vader_array_t*) l4);
    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, INT32_C(0))
    t1 = ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) INT32_C(0)];
    t4 = (t1 | INT32_C(4));
    l2 = (uint32_t) (int32_t) t4;
    t3 = vader_host_system_windows_set_console_mode(l3, l2);
    if (t3) {
        t0 = (void*) &vader_data_14;
        vader_array_t* _a5_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l1)
        ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l1] = (int32_t) INT32_C(1);
    }
    t0 = (void*) &vader_data_14;
    vader_array_t* _a6_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l1)
    t1 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l1];
    { bool __vret = t1 != INT32_C(0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t std_tty_paint(vader_string_t l0, vader_string_t l1) {
    bool l2;
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    vader_string_t t0 = 0;
    vader_string_t* gc_atom_roots[5] = { &l0, &l1, &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 5u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = std_tty_should_colorize();
    l3 = std_tty_escape(l2, l0);
    l4 = std_tty_escape(l2, 287u);
    t0 = concat_3(l3, l1, l4);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t std_tty_red(vader_string_t l0) {
    vader_string_t t0 = 0;
    vader_string_t* gc_atom_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = std_tty_paint(292u, l0);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool std_tty_should_colorize(void) {
    bool l0;
    vader_box_t l1 = vader_box_null();
    bool t0;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[1] = { &l1 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = std_tty_is_tty((uint8_t) 0);
    if (t0) {
        l0 = true;
    } else {
        l0 = std_tty_is_tty((uint8_t) 1);
    }
    if (!(l0)) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    l1 = vader_host_std_env_get_env(489u);
    if (l1.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    t1 = l1.payload.s;
    { bool __vret = t1 == 0u; vader_gc_top = gc_frame.prev; return __vret; }
}

static size_t std_tty_tty_slot(uint8_t l0) {
    size_t l1;
    if (l0 == INT32_C(1)) {
        l1 = (size_t) 1;
    } else {
        l1 = (size_t) 0;
    }
    return l1;
}

vader_string_t std_tty_yellow(vader_string_t l0) {
    vader_string_t t0 = 0;
    vader_string_t* gc_atom_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = std_tty_paint(293u, l0);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}
