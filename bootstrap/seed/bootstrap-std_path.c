#include "bootstrap.split.h"

vader_string_t std_path_as_string(vader_string_t l0) {
    return l0;
}

vader_string_t std_path_filename(vader_string_t l0) {
    vader_string_t l1 = 0;
    ptrdiff_t l2;
    void* l3 = NULL;
    size_t l4, l5;
    int64_t t0;
    void* t1 = NULL;
    vader_string_t t2 = 0;
    void** gc_raw_roots[2] = { &l3, &t1 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l1, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = l0;
    l2 = std_string_last_index_of(l1, 47u, (ptrdiff_t) 0);
    if (!((l2 < INT64_C(0)))) {
        l3 = vader_host_std_core_bytes(l1);
        t0 = (((int64_t) (ptrdiff_t) l2) + INT64_C(1));
        l4 = (size_t) (int64_t) t0;
        l5 = ((vader_array_t*) l3)->length;
        vader_array_t* _a0_arr = vader_array_slice((vader_array_t*) l3, (size_t) l4, (size_t) l5);
        t1 = (void*) _a0_arr;
        t2 = vader_host_std_core_bytes_to_string(t1);
        { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t std_path_parent(vader_string_t l0) {
    vader_string_t l1 = 0;
    ptrdiff_t l2;
    void* l3 = NULL;
    size_t l4;
    int64_t t0;
    void* t1 = NULL;
    vader_string_t t2 = 0;
    void** gc_raw_roots[2] = { &l3, &t1 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l1, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = l0;
    l2 = std_string_last_index_of(l1, 47u, (ptrdiff_t) 0);
    if ((l2 < INT64_C(0))) {
        { vader_gc_top = gc_frame.prev; return 0u; }
    }
    if (!(l2 == INT64_C(0))) {
        l3 = vader_host_std_core_bytes(l1);
        t0 = ((int64_t) (ptrdiff_t) l2);
        l4 = (size_t) (int64_t) t0;
        vader_array_t* _a0_arr = vader_array_slice((vader_array_t*) l3, (size_t) INT64_C(0), (size_t) l4);
        t1 = (void*) _a0_arr;
        t2 = vader_host_std_core_bytes_to_string(t1);
        { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return 323u; }
}

vader_string_t std_path_to_path(vader_string_t l0) {
    return l0;
}

vader_string_t std_path_to_posix(vader_string_t l0) {
    void* l1 = NULL;
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l1 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = (void*) &vader_fn_static___lambda_std_path_0;
    t0 = std_string_replace_chars_where(l0, l1, 323u);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}
