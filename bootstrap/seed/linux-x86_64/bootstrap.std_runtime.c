#include "bootstrap.split.h"

vader_box_t std_runtime$peak_resident_bytes(void) {
    void* l0 = NULL;
    int64_t l1, l2;
    void* t0 = NULL;
    int32_t t1;
    int64_t t2;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(28u, 1u, 8u, 503u);
    ((int64_t*) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = (int64_t) INT64_C(0);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) INT64_C(18));
    l0 = (void*) _a1_arr;
    t1 = vader_host_system_posix$sys_getrusage(INT32_C(0), l0);
    if (t1 != INT32_C(0)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT64_C(4))
    l1 = ((int64_t*) _a2_slotarr->buf->slots)[vader_array_offset(_a2_slotarr) + (size_t) INT64_C(4)];
    if (INT32_C(1) == INT32_C(2)) {
        l2 = INT64_C(1);
        t2 = vader_chk_mul(i64, l1, l2);
        { vader_box_t __vret = vader_box_i64(503u, t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = INT64_C(1024);
    t2 = vader_chk_mul(i64, l1, l2);
    { vader_box_t __vret = vader_box_i64(503u, t2); vader_gc_top = gc_frame.prev; return __vret; }
}
