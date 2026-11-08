#include "bootstrap.split.h"

static int64_t std_time$monotonic_ns(void);

int64_t std_time$monotonic(void) {
    int64_t t0;
    t0 = std_time$monotonic_ns();
    return t0;
}

static int64_t std_time$monotonic_ns(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    int64_t l2, l3, l4;
    bool t0;
    int64_t t1;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(28u, 1u, 8u, 498u);
    ((int64_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int64_t) INT64_C(0);
    l0 = (void*) _a0_arr;
    t0 = vader_host_system_windows$query_performance_frequency(l0);
    if (t0) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
        t1 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) INT32_C(0)];
        if (t1 == INT64_C(0)) {
            { vader_gc_top = gc_frame.prev; return INT64_C(0); }
        }
        vader_array_t* _a2_arr = vader_array_new(28u, 1u, 8u, 498u);
        ((int64_t*) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = (int64_t) INT64_C(0);
        l1 = (void*) _a2_arr;
        t0 = vader_host_system_windows$query_performance_counter(l1);
        if (!(t0)) {
            { vader_gc_top = gc_frame.prev; return INT64_C(0); }
        }
        vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, INT32_C(0))
        l2 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) INT32_C(0)];
        vader_array_t* _a4_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, INT32_C(0))
        l3 = ((int64_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) INT32_C(0)];
        t1 = vader_div_i64(l2, l3);
        l2 = vader_chk_mul(i64, t1, INT64_C(1000000000));
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, INT32_C(0))
        l3 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) INT32_C(0)];
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, INT32_C(0))
        l4 = ((int64_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) INT32_C(0)];
        t1 = vader_mod_i64(l3, l4);
        l3 = vader_chk_mul(i64, t1, INT64_C(1000000000));
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, INT32_C(0))
        l4 = ((int64_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) INT32_C(0)];
        l3 = vader_div_i64(l3, l4);
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
