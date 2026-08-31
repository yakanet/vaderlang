#include "bootstrap.split.h"

static void std_io_write(int32_t l0, vader_string_t l1);

void std_io_eprintln__string(vader_string_t l0) {
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_io_write(INT32_C(1), l0);
    std_io_write(INT32_C(1), 1u);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t std_io_read_file_string(vader_string_t l0) {
    vader_box_t l1 = vader_box_null();
    void* t0 = NULL;
    vader_string_t t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t2 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_import_6(l0);
    if (l1.tag == 382u) {
        t0 = l1.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l1.payload.obj;
    t1 = vader_import_2(t0);
    t2 = vader_box_string(162u, t1);
    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void std_io_write(int32_t l0, vader_string_t l1) {
    int32_t l2;
    void* l3 = NULL;
    void* l7 = NULL;
    size_t l4, l5, l6, l8, l10;
    ptrdiff_t l9;
    int64_t t0;
    void** gc_raw_roots[2] = { &l3, &l7 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(0)) {
        l2 = INT32_C(1);
    } else {
        l2 = INT32_C(2);
    }
    l3 = vader_import_3(l1);
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_16: {
            l5 = ((vader_array_t*) l3)->length;
            if ((l4 >= l5)) {
            } else {
                l6 = ((vader_array_t*) l3)->length;
                vader_array_t* _a0_arr = vader_array_slice((vader_array_t*) l3, (size_t) l4, (size_t) l6);
                l7 = (void*) _a0_arr;
                l8 = ((vader_array_t*) l7)->length;
                l9 = vader_import_5(l2, l7, l8);
                if ((l9 <= INT64_C(0))) {
                    { vader_gc_top = gc_frame.prev; return; }
                }
                t0 = ((int64_t) (ptrdiff_t) l9);
                l10 = (size_t) (int64_t) t0;
                t0 = (l4 + l10);
                l4 = (size_t) (int64_t) t0;
                goto loop_16;
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t std_io_write_file_string(vader_string_t l0, vader_string_t l1) {
    void* l2 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_import_3(l1);
    t0 = vader_import_7(l0, l2);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

