#include "bootstrap.split.h"

static vader_string_t std_tty_escape(bool l0, vader_string_t l1);
static vader_string_t std_tty_paint(vader_string_t l0, vader_string_t l1);
static bool std_tty_should_colorize(void);

static vader_string_t std_tty_escape(bool l0, vader_string_t l1) {
    vader_string_t l2;
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0) {
        l2 = concat_3(5u, l1, 1757u);
    } else {
        l2 = 0u;
    }
    { vader_string_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t std_tty_paint(vader_string_t l0, vader_string_t l1) {
    bool l2;
    vader_string_t l3, l4;
    vader_string_t t0;
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = std_tty_should_colorize();
    l3 = std_tty_escape(l2, l0);
    l4 = std_tty_escape(l2, 442u);
    t0 = concat_3(l3, l1, l4);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_string_t std_tty_red(vader_string_t l0) {
    vader_string_t t0;
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = std_tty_paint(450u, l0);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static bool std_tty_should_colorize(void) {
    bool l0;
    vader_box_t l1 = vader_box_null();
    bool t0;
    vader_string_t t1;
    vader_box_t* gc_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_import_28(INT32_C(0));
    if (t0) {
        l0 = true;
    } else {
        l0 = vader_import_28(INT32_C(1));
    }
    if (!(l0)) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    l1 = vader_import_29(635u);
    if (l1.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    t1 = l1.payload.s;
    { bool __vret = t1 == 0u; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_string_t std_tty_yellow(vader_string_t l0) {
    vader_string_t t0;
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = std_tty_paint(451u, l0);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

