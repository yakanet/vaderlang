#include "bootstrap.split.h"

bool toolchain_span_Span_Equals_equals(void* l0, void* l1) {
    vader_string_t l2, l3;
    bool l4;
    int32_t l5, l6;
    l2 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) l0)->f_start)->f_file;
    l3 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) l1)->f_start)->f_file;
    if (l2 == l3) {
        l5 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) l0)->f_start)->f_line;
        l6 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) l1)->f_start)->f_line;
        l4 = l5 == l6;
    } else {
        l4 = false;
    }
    if (l4) {
        l5 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) l0)->f_start)->f_column;
        l6 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) l1)->f_start)->f_column;
        l4 = l5 == l6;
    } else {
        l4 = false;
    }
    if (l4) {
        l5 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) l0)->f_end)->f_line;
        l6 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) l1)->f_end)->f_line;
        l4 = l5 == l6;
    } else {
        l4 = false;
    }
    if (l4) {
        l5 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) l0)->f_end)->f_column;
        l6 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) l1)->f_end)->f_column;
        l4 = l5 == l6;
    } else {
        l4 = false;
    }
    return l4;
}

uint64_t toolchain_span_Span_Hash_hash(void* l0) {
    uint64_t l1, l2;
    vader_string_t t0 = 0;
    uint64_t t1;
    int64_t t2;
    int32_t t3;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) l0)->f_start)->f_file;
    t1 = std_core_string_Hash_hash_vt(t0);
    t2 = (t1 * INT64_C(1000003));
    l1 = (uint64_t) (int64_t) t2;
    t3 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) l0)->f_start)->f_line;
    t2 = (((int64_t) (int32_t) t3) << INT64_C(32));
    l2 = (uint64_t) (int64_t) t2;
    t2 = (l1 + l2);
    l1 = (uint64_t) (int64_t) t2;
    t3 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) l0)->f_start)->f_column;
    t2 = ((int64_t) (int32_t) t3);
    l2 = (uint64_t) (int64_t) t2;
    { uint64_t __vret = (uint64_t) (int64_t) (l1 + l2); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* toolchain_span_empty_span(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_toolchain_span_Position_t* _a0_obj = (vader_struct_toolchain_span_Position_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Position_t));
    vader_obj_header_init(_a0_obj, 472u);
    _a0_obj->f_file = 513u;
    _a0_obj->f_offset = (size_t) (int64_t) INT64_C(0);
    _a0_obj->f_line = INT32_C(1);
    _a0_obj->f_column = INT32_C(1);
    l0 = (void*) _a0_obj;
    vader_struct_toolchain_span_Position_t* _a1_obj = (vader_struct_toolchain_span_Position_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Position_t));
    vader_obj_header_init(_a1_obj, 472u);
    _a1_obj->f_file = 513u;
    _a1_obj->f_offset = (size_t) (int64_t) INT64_C(1);
    _a1_obj->f_line = INT32_C(1);
    _a1_obj->f_column = INT32_C(2);
    l1 = (void*) _a1_obj;
    vader_struct_toolchain_span_Span_t* _a2_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a2_obj, 473u);
    _a2_obj->f_start = l0;
    _a2_obj->f_end = l1;
    t0 = (void*) _a2_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

bool toolchain_span_has_source_position(void* l0) {
    vader_string_t t0;
    int32_t t1;
    t0 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) l0)->f_start)->f_file;
    if (t0 == 0u) {
        return false;
    }
    t0 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) l0)->f_start)->f_file;
    if (t0 == 513u) {
        return false;
    }
    t0 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) l0)->f_start)->f_file;
    if (t0 == 511u) {
        return false;
    }
    t1 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) l0)->f_start)->f_line;
    return (t1 > INT32_C(0));
}

