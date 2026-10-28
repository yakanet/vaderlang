#include "bootstrap.split.h"

void* __const_vader_core_types$CHAR_VALUES(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_support_integer$Interval_t* _a0_obj = (vader_struct_vader_support_integer$Interval_t*) vader_gc_alloc(sizeof(vader_struct_vader_support_integer$Interval_t));
    vader_obj_header_init(_a0_obj, 1403u);
    _a0_obj->f_lo = INT64_C(0);
    _a0_obj->f_hi = INT64_C(55295);
    _a0_obj->f_lo_open = false;
    _a0_obj->f_hi_open = false;
    _a0_obj->f_hi_past = (uint64_t) 0;
    l0 = (void*) _a0_obj;
    vader_struct_vader_support_integer$Interval_t* _a1_obj = (vader_struct_vader_support_integer$Interval_t*) vader_gc_alloc(sizeof(vader_struct_vader_support_integer$Interval_t));
    vader_obj_header_init(_a1_obj, 1403u);
    _a1_obj->f_lo = INT64_C(57344);
    _a1_obj->f_hi = INT64_C(1114111);
    _a1_obj->f_lo_open = false;
    _a1_obj->f_hi_open = false;
    _a1_obj->f_hi_past = (uint64_t) 0;
    l1 = (void*) _a1_obj;
    vader_array_t* _a2_arr = vader_array_new(218u, 2u, 13u, 1403u);
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 1u] = l1;
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = l0;
    t0 = (void*) _a2_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}
