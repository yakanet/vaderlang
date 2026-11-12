#include "bootstrap.split.h"

static void* system_windows$wide_to_utf8(void* l0, int32_t l1);

vader_string_t system_windows$from_wide(void* l0, int32_t l1) {
    void* t0 = NULL;
    vader_string_t t1 = 0;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = system_windows$wide_to_utf8(l0, l1);
    t1 = vader_host_std_core$bytes_to_string(t0);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

void* system_windows$to_wide(vader_string_t l0) {
    void* l1 = NULL;
    int32_t l2;
    int64_t l3;
    void* t0 = NULL;
    int32_t t1;
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(30u, 0u, 2u, 505u);
    l1 = (void*) _a0_arr;
    l2 = vader_host_system_windows$multi_byte_to_wide_char((uint32_t) 65001, (uint32_t) 0, l0, INT32_C(-1), l1, INT32_C(0));
    if ((l2 <= INT32_C(0))) {
        vader_array_t* _a1_arr = vader_array_new(30u, 0u, 2u, 505u);
        t0 = (void*) _a1_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a2_arr = vader_array_new(30u, 1u, 2u, 505u);
    ((uint16_t*) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = (uint16_t) INT32_C(0);
    l1 = (void*) _a2_arr;
    l3 = ((int64_t) (int32_t) l2);
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) l1, (int64_t) l3);
    l1 = (void*) _a3_arr;
    t1 = vader_host_system_windows$multi_byte_to_wide_char((uint32_t) 65001, (uint32_t) 0, l0, INT32_C(-1), l1, l2);
    if (!((t1 <= INT32_C(0)))) {
        { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a4_arr = vader_array_new(30u, 0u, 2u, 505u);
    t0 = (void*) _a4_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* system_windows$wide_to_utf8(void* l0, int32_t l1) {
    void* l2 = NULL;
    int32_t l3;
    int64_t l4;
    void* t0 = NULL;
    int32_t t1;
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(29u, 0u, 1u, 504u);
    l2 = (void*) _a0_arr;
    l3 = vader_host_system_windows$wide_char_to_multi_byte((uint32_t) 65001, (uint32_t) 0, l0, l1, l2, INT32_C(0), vader_box_obj(0u, NULL), vader_box_obj(0u, NULL));
    if ((l3 <= INT32_C(0))) {
        vader_array_t* _a1_arr = vader_array_new(29u, 0u, 1u, 504u);
        t0 = (void*) _a1_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a2_arr = vader_array_new(29u, 1u, 1u, 504u);
    ((uint8_t*) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = (uint8_t) INT32_C(0);
    l2 = (void*) _a2_arr;
    l4 = ((int64_t) (int32_t) l3);
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l4);
    l2 = (void*) _a3_arr;
    t1 = vader_host_system_windows$wide_char_to_multi_byte((uint32_t) 65001, (uint32_t) 0, l0, l1, l2, l3, vader_box_obj(0u, NULL), vader_box_obj(0u, NULL));
    if (!((t1 <= INT32_C(0)))) {
        { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a4_arr = vader_array_new(29u, 0u, 1u, 504u);
    t0 = (void*) _a4_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}
