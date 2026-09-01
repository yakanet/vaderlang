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
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = l0;
    l2 = std_string_last_index_of(l1, 47u, (ptrdiff_t) (int64_t) INT64_C(0));
    if ((l2 < INT64_C(0))) {
        { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = vader_host_std_core_bytes(l1);
    t0 = (((int64_t) (ptrdiff_t) l2) + INT64_C(1));
    l4 = (size_t) (int64_t) t0;
    l5 = ((vader_array_t*) l3)->length;
    vader_array_t* _a0_arr = vader_array_slice((vader_array_t*) l3, (size_t) l4, (size_t) l5);
    t1 = (void*) _a0_arr;
    t2 = vader_host_std_core_bytes_to_string(t1);
    { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = l0;
    l2 = std_string_last_index_of(l1, 47u, (ptrdiff_t) (int64_t) INT64_C(0));
    if ((l2 < INT64_C(0))) {
        { vader_gc_top = gc_frame.prev; return 0u; }
    }
    if (l2 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return 440u; }
    }
    l3 = vader_host_std_core_bytes(l1);
    t0 = ((int64_t) (ptrdiff_t) l2);
    l4 = (size_t) (int64_t) t0;
    vader_array_t* _a0_arr = vader_array_slice((vader_array_t*) l3, (size_t) INT64_C(0), (size_t) l4);
    t1 = (void*) _a0_arr;
    t2 = vader_host_std_core_bytes_to_string(t1);
    { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_string_t std_path_to_path(vader_string_t l0) {
    return l0;
}

vader_string_t std_path_to_posix(vader_string_t l0) {
    void* l1 = NULL;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_struct___lambda_env_175_t* _a0_obj = (vader_struct___lambda_env_175_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_175_t));
    vader_obj_header_init(_a0_obj, 234u);
    t0 = (void*) _a0_obj;
    vader_fn_t* _a1_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a1_closure, 134u);
    _a1_closure->code = (void*) &vader_fn_lift_229;
    _a1_closure->env = t0;
    l1 = (void*) _a1_closure;
    t1 = std_string_replace_chars_where(l0, l1, 440u);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

