#include "bootstrap.split.h"

static vader_string_t std_fs$glob_separator(vader_string_t l0);
static vader_box_t std_fs$read_file_bytes(vader_string_t l0, int64_t l1);
static vader_box_t std_fs$whole_buffer(int64_t l0, int64_t l1);
static vader_box_t std_fs$write_file_bytes(vader_string_t l0, void* l1);

bool std_fs$exists(vader_string_t l0) {
    void* t0 = NULL;
    uint32_t t1;
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = system_windows$to_wide(l0);
    t1 = vader_host_system_windows$get_file_attributes(t0);
    { bool __vret = t1 != INT32_C(-1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t std_fs$glob_separator(vader_string_t l0) {
    int64_t l1;
    uint8_t l2;
    bool l3;
    l1 = vader_host_std_core$byte_len(l0);
    if (l1 == INT64_C(0)) {
        return 0u;
    }
    l1 = vader_chk_sub(i64, l1, INT64_C(1));
    l2 = vader_host_std_core$byte_at(l0, l1);
    if (l2 == INT32_C(92)) {
        l3 = true;
    } else {
        l3 = l2 == INT32_C(47);
    }
    if (l3) {
        l3 = true;
    } else {
        l3 = l2 == INT32_C(58);
    }
    if (!(l3)) {
        return 1034u;
    }
    return 0u;
}

bool std_fs$is_dir(vader_string_t l0) {
    uint32_t l1;
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = system_windows$to_wide(l0);
    l1 = vader_host_system_windows$get_file_attributes(t0);
    if (!(l1 == INT32_C(-1))) {
        { bool __vret = (l1 & INT32_C(16)) != INT32_C(0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

vader_box_t std_fs$read_dir(vader_string_t l0) {
    vader_string_t l1 = 0;
    void* l2 = NULL;
    void* l4 = NULL;
    void* l3;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    int64_t t2;
    bool t3;
    void** gc_raw_roots[3] = { &l2, &l4, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = std_fs$glob_separator(l0);
    vader_array_t* _a0_arr = vader_array_new(29u, 1u, 1u, 499u);
    ((uint8_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (uint8_t) INT32_C(0);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) INT64_C(1024));
    l2 = (void*) _a1_arr;
    t1 = concat_3(l0, l1, 375u);
    t0 = system_windows$to_wide(t1);
    l3 = vader_host_system_windows$find_first_file(t0, l2);
    t2 = (int64_t) (void*) l3;
    if (t2 == INT64_C(-1)) {
        t1 = concat_3(2647u, l0, 1098u);
        vader_struct_std_io$IOError_t* _a2_obj = (vader_struct_std_io$IOError_t*) vader_gc_alloc(sizeof(vader_struct_std_io$IOError_t));
        vader_obj_header_init(_a2_obj, 858u);
        _a2_obj->f_msg = t1;
        _a2_obj->f_kind = (uint8_t) 0;
        _a2_obj->f_code = INT32_C(0);
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct___defer_env_std_fs_1_t* _a3_obj = (vader_struct___defer_env_std_fs_1_t*) vader_gc_alloc(sizeof(vader_struct___defer_env_std_fs_1_t));
    vader_obj_header_init(_a3_obj, 517u);
    _a3_obj->f_cap_0 = l3;
    t0 = (void*) _a3_obj;
    vader_fn_t* _a4_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a4_closure, 436u);
    _a4_closure->code = (void*) &vader_fn_lift___defer_std_fs_0;
    _a4_closure->env = t0;
    t0 = (void*) _a4_closure;
    vader_defer_push(vader_ref_box(t0));
    vader_array_t* _a5_arr = vader_array_new(26u, 0u, 0u, 494u);
    l4 = (void*) _a5_arr;
    for (;;) {
        l1 = vader_host_system_windows$find_data_name(l2);
        if (l1 != 433u) {
            if (l1 != 434u) {
                vader_array_push_scalar((vader_array_t*) l4, vader_box_string(494u, l1));
            }
        }
        t3 = vader_host_system_windows$find_next_file(l3, l2);
        if (!(t3)) {
            vader_defer_pop_exec(1u);
            { vader_box_t __vret = vader_ref_box(l4); vader_gc_top = gc_frame.prev; return __vret; }
        }
        continue;
    }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t std_fs$read_file_bytes(vader_string_t l0, int64_t l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l11 = NULL;
    void* l13 = NULL;
    void* l17 = NULL;
    void* l19 = NULL;
    void* l22 = NULL;
    uint32_t l3, l18;
    void* l4;
    int64_t l7, l10, l15, l16, l20, l21;
    bool l12;
    vader_box_t l14 = vader_box_null();
    int32_t t0;
    int64_t t1;
    void* t2 = NULL;
    bool t3;
    uint32_t t4;
    vader_box_t* gc_roots[1] = { &l14 };
    void** gc_raw_roots[11] = { &l2, &l5, &l6, &l8, &l9, &l11, &l13, &l17, &l19, &l22, &t2 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 11u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = system_windows$to_wide(l0);
    t0 = (INT32_C(1) | INT32_C(2));
    l3 = (uint32_t) (int32_t) t0;
    l4 = vader_host_system_windows$create_file_w(l2, (uint32_t) (int32_t) INT32_MIN, l3, vader_box_obj(0u, NULL), (uint32_t) 3, (uint32_t) 128, vader_box_obj(0u, NULL));
    t1 = (int64_t) (void*) l4;
    if (t1 == INT64_C(-1)) {
        t2 = std_io$last_io_error(2124u);
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct___defer_env_std_fs_3_t* _a0_obj = (vader_struct___defer_env_std_fs_3_t*) vader_gc_alloc(sizeof(vader_struct___defer_env_std_fs_3_t));
    vader_obj_header_init(_a0_obj, 518u);
    _a0_obj->f_cap_0 = l4;
    t2 = (void*) _a0_obj;
    vader_fn_t* _a1_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a1_closure, 436u);
    _a1_closure->code = (void*) &vader_fn_lift___defer_std_fs_2;
    _a1_closure->env = t2;
    t2 = (void*) _a1_closure;
    vader_defer_push(vader_ref_box(t2));
    vader_array_t* _a2_arr = vader_array_new(29u, 0u, 1u, 499u);
    l2 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(29u, 1u, 1u, 499u);
    ((uint8_t*) _a3_arr->buf->slots)[_a3_arr->offset + 0u] = (uint8_t) INT32_C(0);
    t2 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_repeat((vader_array_t*) t2, (int64_t) INT64_C(65536));
    l5 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(31u, 1u, 3u, 501u);
    ((int32_t*) _a5_arr->buf->slots)[_a5_arr->offset + 0u] = (int32_t) INT32_C(0);
    l6 = (void*) _a5_arr;
    for (;;) {
        t1 = ((vader_array_t*) l5)->length;
        t0 = ((int32_t) (int64_t) t1);
        l3 = (uint32_t) (int32_t) t0;
        t3 = vader_host_system_windows$read_file(l4, l5, l3, l6, vader_box_obj(0u, NULL));
        if (t3) {
            vader_array_t* _a6_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a6_slotarr, INT32_C(0))
            t0 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) INT32_C(0)];
            l7 = ((int64_t) (uint32_t) t0);
            if ((l7 > INT64_C(0))) {
                vader_array_t* _a7_arr = vader_array_slice((vader_array_t*) l5, (int64_t) INT64_C(0), (int64_t) l7);
                l8 = (void*) _a7_arr;
                vader_array_push_all((vader_array_t*) l2, (vader_array_t*) l8);
            }
            t1 = ((vader_array_t*) l2)->length;
            if ((t1 > l1)) {
                vader_struct_std_io$IOError_t* _a8_obj = (vader_struct_std_io$IOError_t*) vader_gc_alloc(sizeof(vader_struct_std_io$IOError_t));
                vader_obj_header_init(_a8_obj, 858u);
                _a8_obj->f_msg = 2125u;
                _a8_obj->f_kind = (uint8_t) 0;
                _a8_obj->f_code = INT32_C(0);
                l9 = (void*) _a8_obj;
                vader_defer_pop_exec(1u);
                { vader_box_t __vret = vader_ref_box(l9); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l10 = ((vader_array_t*) l5)->length;
            if ((l7 < l10)) {
                vader_defer_pop_exec(1u);
                { vader_box_t __vret = vader_ref_box(l2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t1 = ((vader_array_t*) l2)->length;
            if (!(t1 == INT64_C(65536))) {
                continue;
            }
            vader_array_t* _a9_arr = vader_array_new(28u, 1u, 8u, 498u);
            ((int64_t*) _a9_arr->buf->slots)[_a9_arr->offset + 0u] = (int64_t) INT64_C(-1);
            l11 = (void*) _a9_arr;
            t4 = vader_host_system_windows$get_file_type(l4);
            if (t4 != INT32_C(1)) {
                l12 = true;
            } else {
                t3 = vader_host_system_windows$get_file_size_ex(l4, l11);
                l12 = !(t3);
            }
            if (l12) {
                vader_array_t* _a10_slotarr = ((vader_array_t*) l11);
                VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a10_slotarr, INT32_C(0))
                ((int64_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) INT32_C(0)] = (int64_t) INT64_C(-1);
            }
            vader_array_t* _a11_slotarr = ((vader_array_t*) l11);
            VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a11_slotarr, INT32_C(0))
            t1 = ((int64_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) INT32_C(0)];
            l14 = std_fs$whole_buffer(t1, l1);
            if (l14.tag == 0u) {
                continue;
            }
            l13 = l14.payload.obj;
            vader_array_copy((vader_array_t*) l5, (int64_t) INT64_C(0), (vader_array_t*) l13, (int64_t) INT64_C(0), (int64_t) INT64_C(65536));
            t1 = ((vader_array_t*) l13)->length;
            l15 = vader_chk_sub(i64, t1, INT64_C(65536));
            l16 = ((vader_array_t*) l13)->length;
            vader_array_t* _a12_arr = vader_array_slice((vader_array_t*) l13, (int64_t) INT64_C(65536), (int64_t) l16);
            l17 = (void*) _a12_arr;
            t0 = ((int32_t) (int64_t) l15);
            l18 = (uint32_t) (int32_t) t0;
            t3 = vader_host_system_windows$read_file(l4, l17, l18, l6, vader_box_obj(0u, NULL));
            if (!(t3)) {
                l19 = std_io$last_io_error(2646u);
                vader_defer_pop_exec(1u);
                { vader_box_t __vret = vader_ref_box(l19); vader_gc_top = gc_frame.prev; return __vret; }
            }
            vader_array_t* _a13_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a13_slotarr, INT32_C(0))
            t0 = ((int32_t*) _a13_slotarr->buf->slots)[_a13_slotarr->offset + (size_t) INT32_C(0)];
            if ((((int64_t) (uint32_t) t0) < l15)) {
                vader_array_t* _a14_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a14_slotarr, INT32_C(0))
                t0 = ((int32_t*) _a14_slotarr->buf->slots)[_a14_slotarr->offset + (size_t) INT32_C(0)];
                l20 = ((int64_t) (uint32_t) t0);
                l21 = vader_chk_add(i64, INT64_C(65536), l20);
                vader_array_t* _a15_arr = vader_array_slice((vader_array_t*) l13, (int64_t) INT64_C(0), (int64_t) l21);
                l22 = (void*) _a15_arr;
                vader_defer_pop_exec(1u);
                { vader_box_t __vret = vader_ref_box(l22); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l2 = l13;
            continue;
        }
        break;
    }
    l2 = std_io$last_io_error(2646u);
    vader_defer_pop_exec(1u);
    { vader_box_t __vret = vader_ref_box(l2); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t std_fs$read_file_string(vader_string_t l0, int64_t l1) {
    vader_box_t l2 = vader_box_null();
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = std_fs$read_file_bytes(l0, l1);
    if (!(l2.tag == 858u)) {
        t0 = l2.payload.obj;
        t1 = vader_host_std_core$bytes_to_string(t0);
        { vader_box_t __vret = vader_box_string(494u, t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l2.payload.obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t std_fs$whole_buffer(int64_t l0, int64_t l1) {
    void* l2 = NULL;
    int64_t l3;
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if ((l0 <= INT64_C(65536))) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    if ((l0 > l1)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    if (!((l0 >= INT64_C(4294967295)))) {
        vader_array_t* _a0_arr = vader_array_new(29u, 1u, 1u, 499u);
        ((uint8_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (uint8_t) INT32_C(0);
        l2 = (void*) _a0_arr;
        l3 = vader_chk_add(i64, l0, INT64_C(1));
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
        t0 = (void*) _a1_arr;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t std_fs$write_file_bytes(vader_string_t l0, void* l1) {
    int64_t l2, l3;
    void* l4;
    void* l5 = NULL;
    uint32_t l6;
    uint8_t t0;
    void* t1 = NULL;
    int64_t t2;
    int32_t t3;
    bool t4;
    void** gc_raw_roots[3] = { &l1, &l5, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = INT64_C(0);
    l3 = vader_host_std_core$byte_len(l0);
    while ((l2 < l3)) {
        t0 = vader_host_std_core$byte_at(l0, l2);
        if (t0 == INT32_C(0)) {
            vader_struct_std_io$IOError_t* _a0_obj = (vader_struct_std_io$IOError_t*) vader_gc_alloc(sizeof(vader_struct_std_io$IOError_t));
            vader_obj_header_init(_a0_obj, 858u);
            _a0_obj->f_msg = 2609u;
            _a0_obj->f_kind = (uint8_t) 0;
            _a0_obj->f_code = INT32_C(0);
            t1 = (void*) _a0_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l2 = (l2 + INT64_C(1));
    }
    t1 = system_windows$to_wide(l0);
    l4 = vader_host_system_windows$create_file_w(t1, (uint32_t) 1073741824, (uint32_t) 1, vader_box_obj(0u, NULL), (uint32_t) 2, (uint32_t) 128, vader_box_obj(0u, NULL));
    t2 = (int64_t) (void*) l4;
    if (t2 == INT64_C(-1)) {
        t1 = std_io$last_io_error(2576u);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = ((vader_array_t*) l1)->length;
    if ((t2 > INT64_C(0))) {
        vader_array_t* _a1_arr = vader_array_new(31u, 1u, 3u, 501u);
        ((int32_t*) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = (int32_t) INT32_C(0);
        l5 = (void*) _a1_arr;
        t2 = ((vader_array_t*) l1)->length;
        t3 = ((int32_t) (int64_t) t2);
        l6 = (uint32_t) (int32_t) t3;
        t4 = vader_host_system_windows$write_file(l4, l1, l6, l5, vader_box_obj(0u, NULL));
        if (!(t4)) {
            l5 = std_io$last_io_error(2708u);
            vader_host_system_windows$close_handle(l4);
            { vader_box_t __vret = vader_ref_box(l5); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    t4 = vader_host_system_windows$close_handle(l4);
    if (!(t4)) {
        t1 = std_io$last_io_error(1873u);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

vader_box_t std_fs$write_file_string(vader_string_t l0, vader_string_t l1) {
    void* l2 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[1] = { &l2 };
    vader_string_t* gc_atom_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_host_std_core$bytes(l1);
    t0 = std_fs$write_file_bytes(l0, l2);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}
