#include "bootstrap.split.h"

vader_string_t system_posix$up_to_nul(void* l0) {
    int64_t l1, l2, l3;
    vader_box_t t0 = vader_box_null();
    uint8_t t1;
    void* t2 = NULL;
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l0, &t2 };
    vader_string_t* gc_atom_roots[1] = { &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_array_length(((vader_array_t*) l0));
    l2 = INT64_C(0);
    l3 = vader_array_length(((vader_array_t*) l0));
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_read_u8(_a0_slotarr, vader_array_offset(_a0_slotarr) + (size_t) l2, 508u);
        t1 = ((uint8_t) t0.payload.i);
        if (t1 == INT32_C(0)) {
            l1 = l2;
            break;
        }
        l2 = (l2 + INT64_C(1));
    }
    vader_array_t* _a1_arr = vader_array_slice((vader_array_t*) l0, (int64_t) INT64_C(0), (int64_t) l1);
    t2 = (void*) _a1_arr;
    t3 = vader_host_std_core$bytes_to_string(t2);
    { vader_string_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}
