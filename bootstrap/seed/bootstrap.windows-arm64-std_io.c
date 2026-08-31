#include "bootstrap.split.h"

static void std_io_write(int32_t l0, vader_string_t l1);
static int32_t std_io_write_bytes(int32_t l0, void* l1, size_t l2);

void std_io_eprintln__string(vader_string_t l0) {
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    std_io_write(INT32_C(1), l0);
    std_io_write(INT32_C(1), 1u);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t std_io_read_file_string(vader_string_t l0) {
    vader_box_t l1 = vader_box_null();
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t2 };
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_host_std_io_read_file_bytes(l0);
    if (l1.tag == 384u) {
        t0 = l1.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l1.payload.obj;
    t1 = vader_host_std_core_bytes_to_string(t0);
    t2 = vader_box_string(163u, t1);
    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void std_io_write(int32_t l0, vader_string_t l1) {
    void* l2 = NULL;
    void* l6 = NULL;
    size_t l3, l4, l5, l7, l9;
    int32_t l8;
    int64_t t0;
    void** gc_raw_roots[2] = { &l2, &l6 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = vader_host_std_core_bytes(l1);
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_6: {
            l4 = ((vader_array_t*) l2)->length;
            if ((l3 >= l4)) {
            } else {
                l5 = ((vader_array_t*) l2)->length;
                vader_array_t* _a0_arr = vader_array_slice((vader_array_t*) l2, (size_t) l3, (size_t) l5);
                l6 = (void*) _a0_arr;
                l7 = ((vader_array_t*) l6)->length;
                l8 = std_io_write_bytes(l0, l6, l7);
                if ((l8 <= INT32_C(0))) {
                    { vader_gc_top = gc_frame.prev; return; }
                }
                t0 = ((int64_t) (int32_t) l8);
                l9 = (size_t) (int64_t) t0;
                t0 = (l3 + l9);
                l3 = (size_t) (int64_t) t0;
                goto loop_6;
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static int32_t std_io_write_bytes(int32_t l0, void* l1, size_t l2) {
    uint32_t l3;
    void* l4;
    int32_t t0;
    bool t1;
    void** gc_raw_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(0)) {
        l3 = (uint32_t) (int32_t) INT32_C(-11);
    } else {
        l3 = (uint32_t) (int32_t) INT32_C(-12);
    }
    l4 = vader_host_system_windows_get_std_handle(l3);
    t0 = ((int32_t) (size_t) l2);
    l3 = (uint32_t) (int32_t) t0;
    t1 = vader_host_system_windows_write_file(l4, l1, l3, (uint32_t) (int32_t) INT32_C(0), vader_box_obj(0u, NULL));
    if (t1) {
        { int32_t __vret = ((int32_t) (size_t) l2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { int32_t __vret = -(INT32_C(1)); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t std_io_write_file_string(vader_string_t l0, vader_string_t l1) {
    void* l2 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[1] = { &l2 };
    vader_string_t* gc_atom_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = vader_host_std_core_bytes(l1);
    t0 = vader_host_std_io_write_file_bytes(l0, l2);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

