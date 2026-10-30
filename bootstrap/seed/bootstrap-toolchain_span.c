#include "bootstrap.split.h"

static uint64_t toolchain_span$span_key_mix(uint64_t l0);

bool toolchain_span$Span$std_core$Equals$equals(void* l0, void* l1) {
    vader_string_t l2, l3;
    bool l4;
    int32_t l5, l6;
    l2 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) l0)->f_start)->f_file;
    l3 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) l1)->f_start)->f_file;
    if (l2 == l3) {
        l5 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) l0)->f_start)->f_line;
        l6 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) l1)->f_start)->f_line;
        l4 = l5 == l6;
    } else {
        l4 = false;
    }
    if (l4) {
        l5 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) l0)->f_start)->f_column;
        l6 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) l1)->f_start)->f_column;
        l4 = l5 == l6;
    } else {
        l4 = false;
    }
    if (l4) {
        l5 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) l0)->f_end)->f_line;
        l6 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) l1)->f_end)->f_line;
        l4 = l5 == l6;
    } else {
        l4 = false;
    }
    if (l4) {
        l5 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) l0)->f_end)->f_column;
        l6 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) l1)->f_end)->f_column;
        return l5 == l6;
    }
    return false;
}

bool toolchain_span$Span$std_core$Equals$equals$guard(void* l0, vader_box_t l1) {
    void* l2;
    bool t0;
    if (l1.tag == 720u) {
        l2 = l1.payload.obj;
        t0 = toolchain_span$Span$std_core$Equals$equals(l0, l2);
        return t0;
    }
    return false;
}

uint64_t toolchain_span$Span$std_core$Hash$hash(void* l0) {
    uint64_t l1, l2;
    vader_string_t t0;
    uint64_t t1;
    int64_t t2;
    int32_t t3;
    t0 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) l0)->f_start)->f_file;
    t1 = std_core$string$Hash$hash_vt(t0);
    t2 = (t1 * INT64_C(1000003));
    l1 = (uint64_t) (int64_t) t2;
    t3 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) l0)->f_start)->f_line;
    t2 = (((int64_t) (int32_t) t3) << INT64_C(32));
    l2 = (uint64_t) (int64_t) t2;
    t2 = (l1 + l2);
    l1 = (uint64_t) (int64_t) t2;
    t3 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) l0)->f_start)->f_column;
    t2 = ((int64_t) (int32_t) t3);
    l2 = (uint64_t) (int64_t) t2;
    t1 = toolchain_span$span_key_mix((uint64_t) (int64_t) (l1 + l2));
    return t1;
}

void* toolchain_span$empty_span(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_toolchain_span$Position_t* _a0_obj = (vader_struct_toolchain_span$Position_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Position_t));
    vader_obj_header_init(_a0_obj, 719u);
    _a0_obj->f_file = 516u;
    _a0_obj->f_offset = INT64_C(0);
    _a0_obj->f_line = INT32_C(1);
    _a0_obj->f_column = INT32_C(1);
    l0 = (void*) _a0_obj;
    vader_struct_toolchain_span$Position_t* _a1_obj = (vader_struct_toolchain_span$Position_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Position_t));
    vader_obj_header_init(_a1_obj, 719u);
    _a1_obj->f_file = 516u;
    _a1_obj->f_offset = INT64_C(1);
    _a1_obj->f_line = INT32_C(1);
    _a1_obj->f_column = INT32_C(2);
    l1 = (void*) _a1_obj;
    vader_struct_toolchain_span$Span_t* _a2_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
    vader_obj_header_init(_a2_obj, 720u);
    _a2_obj->f_start = l0;
    _a2_obj->f_end = l1;
    t0 = (void*) _a2_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* toolchain_span$file_head_span(vader_string_t l0) {
    void* l1 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_toolchain_span$Position_t* _a0_obj = (vader_struct_toolchain_span$Position_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Position_t));
    vader_obj_header_init(_a0_obj, 719u);
    _a0_obj->f_file = l0;
    _a0_obj->f_offset = INT64_C(0);
    _a0_obj->f_line = INT32_C(1);
    _a0_obj->f_column = INT32_C(1);
    l1 = (void*) _a0_obj;
    vader_struct_toolchain_span$Span_t* _a1_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
    vader_obj_header_init(_a1_obj, 720u);
    _a1_obj->f_start = l1;
    _a1_obj->f_end = l1;
    t0 = (void*) _a1_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool toolchain_span$has_source_position(void* l0) {
    vader_string_t t0;
    int32_t t1;
    t0 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) l0)->f_start)->f_file;
    if (t0 == 0u) {
        return false;
    }
    t0 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) l0)->f_start)->f_file;
    if (!(t0 == 516u)) {
        t1 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) l0)->f_start)->f_line;
        return (t1 > INT32_C(0));
    }
    return false;
}

vader_string_t toolchain_span$source_position(void* l0) {
    vader_string_t l1 = 0;
    int64_t l2, l4;
    void* l3 = NULL;
    int32_t t0;
    vader_string_t t1 = 0;
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) l0)->f_start)->f_file;
    l2 = vader_host_std_core$byte_len(l1);
    l3 = (void*) vader_buffer_new((size_t) (INT64_C(42) + l2));
    l2 = INT64_C(0);
    l2 = std_core$write_string_at(l3, l2, l1);
    l2 = std_core$write_string_at(l3, l2, 461u);
    t0 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) l0)->f_start)->f_line;
    l4 = ((int64_t) (int32_t) t0);
    l2 = std_core$write_int(l3, l2, l4);
    l2 = std_core$write_string_at(l3, l2, 461u);
    t0 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) l0)->f_start)->f_column;
    l4 = ((int64_t) (int32_t) t0);
    l2 = std_core$write_int(l3, l2, l4);
    t1 = std_core$finish_buffer(l3, l2);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static uint64_t toolchain_span$span_key_mix(uint64_t l0) {
    uint64_t l1, l2;
    int64_t t0;
    l1 = (l0 >> INT64_C(33));
    t0 = ((l0 ^ l1) * INT64_C(-49064778989728563));
    l1 = (uint64_t) (int64_t) t0;
    l2 = (l1 >> INT64_C(33));
    t0 = ((l1 ^ l2) * INT64_C(-4265267296055464877));
    l1 = (uint64_t) (int64_t) t0;
    l2 = (l1 >> INT64_C(33));
    return (uint64_t) (int64_t) (l1 ^ l2);
}
