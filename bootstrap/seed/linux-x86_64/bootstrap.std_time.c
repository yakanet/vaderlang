#include "bootstrap.split.h"

static int64_t std_time$monotonic_ns(void);

int64_t std_time$monotonic(void) {
    int64_t t0;
    t0 = std_time$monotonic_ns();
    return t0;
}

static int64_t std_time$monotonic_ns(void) {
    void* l0 = NULL;
    int32_t l1;
    int64_t l2, l3;
    int32_t t0;
    int64_t t1;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(28u, 2u, 8u, 503u);
    ((int64_t*) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = (int64_t) INT64_C(0);
    ((int64_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int64_t) INT64_C(0);
    l0 = (void*) _a0_arr;
    if (INT32_C(1) == INT32_C(2)) {
        l1 = INT32_C(6);
    } else {
        l1 = INT32_C(1);
    }
    t0 = vader_host_system_posix$sys_clock_gettime(l1, l0);
    if (!(t0 != INT32_C(0))) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
        t1 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) INT32_C(0)];
        l2 = vader_chk_mul(i64, t1, INT64_C(1000000000));
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(1))
        l3 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) INT32_C(1)];
        t1 = vader_chk_add(i64, l2, l3);
        { int64_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return INT64_C(0); }
}

int64_t std_time$since(int64_t l0) {
    int64_t l1, l2;
    int64_t t0;
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = std_time$monotonic_ns();
    l2 = l0;
    t0 = vader_chk_sub(i64, l1, l2);
    { int64_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}
