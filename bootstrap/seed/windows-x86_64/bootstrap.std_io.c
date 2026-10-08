#include "bootstrap.split.h"

static vader_string_t std_io_describe_io_error_kind(uint8_t l0);
static vader_string_t std_io_from_wide(void* l0, int32_t l1);
static void* std_io_last_io_error(vader_string_t l0);
static vader_box_t std_io_read_file_bytes(vader_string_t l0, size_t l1);
static vader_string_t std_io_to_slash(vader_string_t l0);
static void* std_io_to_wide(vader_string_t l0);
static vader_string_t std_io_without_trailing_sep(vader_string_t l0);
static void std_io_write(uint8_t l0, vader_string_t l1);
static int32_t std_io_write_bytes(uint8_t l0, void* l1, size_t l2);
static vader_box_t std_io_write_file_bytes(vader_string_t l0, void* l1);

vader_string_t std_io_IOError_Error_message(void* l0) {
    vader_string_t t0;
    t0 = ((vader_struct_std_io_IOError_t*) l0)->f_msg;
    return t0;
}

vader_string_t std_io_current_executable_location(void) {
    void* l0 = NULL;
    uint32_t l1;
    bool l2;
    size_t l3, l4;
    int32_t l5;
    void* t0 = NULL;
    size_t t1;
    int32_t t2;
    int64_t t3;
    vader_string_t t4 = 0;
    vader_string_t t5 = 0;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[2] = { &t4, &t5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(14u, 1u, 2u, 237u);
    ((uint16_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (uint16_t) INT32_C(0);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) INT32_C(4096));
    l0 = (void*) _a1_arr;
    t1 = ((vader_array_t*) l0)->length;
    t2 = ((int32_t) (size_t) t1);
    l1 = (uint32_t) (int32_t) t2;
    l1 = vader_host_system_windows_get_module_file_name(vader_box_obj(0u, NULL), l0, l1);
    if (l1 == INT32_C(0)) {
        l2 = true;
    } else {
        t3 = ((int64_t) (uint32_t) l1);
        l3 = (size_t) (int64_t) t3;
        l4 = ((vader_array_t*) l0)->length;
        l2 = (l3 >= l4);
    }
    if (!(l2)) {
        l5 = ((int32_t) (uint32_t) l1);
        t4 = std_io_from_wide(l0, l5);
        t5 = std_io_to_slash(t4);
        { vader_string_t __vret = t5; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return 295u; }
}

vader_string_t std_io_current_working_directory(void) {
    void* l0 = NULL;
    uint32_t l1;
    bool l2;
    size_t l3, l4;
    int32_t l5;
    void* t0 = NULL;
    size_t t1;
    int64_t t2;
    vader_string_t t3 = 0;
    vader_string_t t4 = 0;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[2] = { &t3, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(14u, 1u, 2u, 237u);
    ((uint16_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (uint16_t) INT32_C(0);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) INT32_C(4096));
    l0 = (void*) _a1_arr;
    t1 = ((vader_array_t*) l0)->length;
    l1 = vader_host_system_windows_get_current_directory((uint32_t) (int32_t) ((int32_t) (size_t) t1), l0);
    if (l1 == INT32_C(0)) {
        l2 = true;
    } else {
        t2 = ((int64_t) (uint32_t) l1);
        l3 = (size_t) (int64_t) t2;
        l4 = ((vader_array_t*) l0)->length;
        l2 = (l3 >= l4);
    }
    if (!(l2)) {
        l5 = ((int32_t) (uint32_t) l1);
        t3 = std_io_from_wide(l0, l5);
        t4 = std_io_to_slash(t3);
        t3 = std_io_without_trailing_sep(t4);
        { vader_string_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return 295u; }
}

static vader_string_t std_io_describe_io_error_kind(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(1)) {
        l1 = 1646u;
        return l1;
    }
    if (l0 == INT32_C(2)) {
        l1 = 2050u;
    } else if (l0 == INT32_C(3)) {
        l1 = 1820u;
    } else if (l0 == INT32_C(4)) {
        l1 = 1211u;
    } else if (l0 == INT32_C(5)) {
        l1 = 2000u;
    } else if (l0 == INT32_C(6)) {
        l1 = 1841u;
    } else if (l0 == INT32_C(7)) {
        l1 = 2575u;
    } else if (l0 == INT32_C(8)) {
        l1 = 1323u;
    } else if (l0 == INT32_C(9)) {
        l1 = 1994u;
    } else if (l0 == INT32_C(10)) {
        l1 = 1832u;
    } else if (l0 == INT32_C(11)) {
        l1 = 1497u;
    } else if (l0 == INT32_C(12)) {
        l1 = 1293u;
    } else {
        if (!(l0 == INT32_C(0))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 0u;
    }
    return l1;
}

void std_io_eprintln__string(vader_string_t l0) {
    vader_string_t l1 = 0;
    vader_string_t* gc_atom_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = concat_2(l0, 1u);
    std_io_write((uint8_t) 1, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

bool std_io_exists(vader_string_t l0) {
    void* t0 = NULL;
    uint32_t t1;
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = std_io_to_wide(l0);
    t1 = vader_host_system_windows_get_file_attributes(t0);
    { bool __vret = t1 != INT32_C(-1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t std_io_from_wide(void* l0, int32_t l1) {
    void* l2 = NULL;
    int32_t l3;
    size_t l4;
    int64_t t0;
    int32_t t1;
    vader_string_t t2 = 0;
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_string_t* gc_atom_roots[1] = { &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(13u, 0u, 1u, 236u);
    l2 = (void*) _a0_arr;
    l3 = vader_host_system_windows_wide_char_to_multi_byte((uint32_t) 65001, (uint32_t) 0, l0, l1, l2, INT32_C(0), vader_box_obj(0u, NULL), vader_box_obj(0u, NULL));
    if ((l3 <= INT32_C(0))) {
        { vader_gc_top = gc_frame.prev; return 0u; }
    }
    vader_array_t* _a1_arr = vader_array_new(13u, 1u, 1u, 236u);
    ((uint8_t*) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = (uint8_t) INT32_C(0);
    l2 = (void*) _a1_arr;
    t0 = ((int64_t) (int32_t) l3);
    l4 = (size_t) (int64_t) t0;
    vader_array_t* _a2_arr = vader_array_repeat((vader_array_t*) l2, (size_t) l4);
    l2 = (void*) _a2_arr;
    t1 = vader_host_system_windows_wide_char_to_multi_byte((uint32_t) 65001, (uint32_t) 0, l0, l1, l2, l3, vader_box_obj(0u, NULL), vader_box_obj(0u, NULL));
    if (!((t1 <= INT32_C(0)))) {
        t2 = vader_host_std_core_bytes_to_string(l2);
        { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return 0u; }
}

bool std_io_is_dir(vader_string_t l0) {
    uint32_t l1;
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = std_io_to_wide(l0);
    l1 = vader_host_system_windows_get_file_attributes(t0);
    if (!(l1 == INT32_C(-1))) {
        { bool __vret = (l1 & INT32_C(16)) != INT32_C(0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static void* std_io_last_io_error(vader_string_t l0) {
    uint32_t l1;
    uint8_t l2;
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    int32_t l5;
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l3, &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_host_system_windows_get_last_error();
    l2 = (uint8_t) 0;
    if (l1 == INT32_C(2)) {
        l2 = (uint8_t) 1;
    }
    if (l1 == INT32_C(3)) {
        l2 = (uint8_t) 1;
    }
    if (l1 == INT32_C(5)) {
        l2 = (uint8_t) 2;
    }
    if (l1 == INT32_C(6)) {
        l2 = (uint8_t) 12;
    }
    if (l1 == INT32_C(80)) {
        l2 = (uint8_t) 4;
    }
    if (l1 == INT32_C(183)) {
        l2 = (uint8_t) 4;
    }
    if (l1 == INT32_C(109)) {
        l2 = (uint8_t) 8;
    }
    if (l1 == INT32_C(112)) {
        l2 = (uint8_t) 9;
    }
    if (l1 == INT32_C(145)) {
        l2 = (uint8_t) 11;
    }
    l3 = std_io_describe_io_error_kind(l2);
    if (l3 == 0u) {
        l4 = l0;
        l5 = ((int32_t) (uint32_t) l1);
        vader_struct_std_io_IOError_t* _a0_obj = (vader_struct_std_io_IOError_t*) vader_gc_alloc(sizeof(vader_struct_std_io_IOError_t));
        vader_obj_header_init(_a0_obj, 410u);
        _a0_obj->f_msg = l4;
        _a0_obj->f_kind = l2;
        _a0_obj->f_code = l5;
        t0 = (void*) _a0_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = l3;
    l5 = ((int32_t) (uint32_t) l1);
    vader_struct_std_io_IOError_t* _a1_obj = (vader_struct_std_io_IOError_t*) vader_gc_alloc(sizeof(vader_struct_std_io_IOError_t));
    vader_obj_header_init(_a1_obj, 410u);
    _a1_obj->f_msg = l4;
    _a1_obj->f_kind = l2;
    _a1_obj->f_code = l5;
    t0 = (void*) _a1_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t std_io_read_dir(vader_string_t l0) {
    uint8_t l1;
    size_t l2;
    vader_string_t l3 = 0;
    bool l4;
    void* l5 = NULL;
    void* l7 = NULL;
    void* l6;
    size_t t0;
    int64_t t1;
    void* t2 = NULL;
    vader_string_t t3 = 0;
    ptrdiff_t t4;
    bool t5;
    void** gc_raw_roots[3] = { &l5, &l7, &t2 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l3, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_host_std_core_byte_len(l0);
    if (t0 == INT64_C(0)) {
        l1 = (uint8_t) 0;
    } else {
        t0 = vader_host_std_core_byte_len(l0);
        t1 = (t0 - INT64_C(1));
        l2 = (size_t) (int64_t) t1;
        l1 = vader_host_std_core_byte_at(l0, l2);
    }
    t0 = vader_host_std_core_byte_len(l0);
    if (t0 == INT64_C(0)) {
        l4 = true;
    } else {
        l4 = l1 == INT32_C(92);
    }
    if (l4) {
        l4 = true;
    } else {
        l4 = l1 == INT32_C(47);
    }
    if (l4) {
        l4 = true;
    } else {
        l4 = l1 == INT32_C(58);
    }
    if (l4) {
        l3 = 0u;
    } else {
        l3 = 779u;
    }
    vader_array_t* _a0_arr = vader_array_new(13u, 1u, 1u, 236u);
    ((uint8_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (uint8_t) INT32_C(0);
    t2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t2, (size_t) INT64_C(1024));
    l5 = (void*) _a1_arr;
    t3 = concat_3(l0, l3, 264u);
    t2 = std_io_to_wide(t3);
    l6 = vader_host_system_windows_find_first_file(t2, l5);
    t4 = (ptrdiff_t) (void*) l6;
    if (t4 == INT64_C(-1)) {
        t3 = concat_3(2077u, l0, 843u);
        vader_struct_std_io_IOError_t* _a2_obj = (vader_struct_std_io_IOError_t*) vader_gc_alloc(sizeof(vader_struct_std_io_IOError_t));
        vader_obj_header_init(_a2_obj, 410u);
        _a2_obj->f_msg = t3;
        _a2_obj->f_kind = (uint8_t) 0;
        _a2_obj->f_code = INT32_C(0);
        t2 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct___defer_env_std_io_1_t* _a3_obj = (vader_struct___defer_env_std_io_1_t*) vader_gc_alloc(sizeof(vader_struct___defer_env_std_io_1_t));
    vader_obj_header_init(_a3_obj, 245u);
    _a3_obj->f_cap_0 = l6;
    t2 = (void*) _a3_obj;
    vader_fn_t* _a4_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a4_closure, 196u);
    _a4_closure->code = (void*) &vader_fn_lift___defer_std_io_0;
    _a4_closure->env = t2;
    t2 = (void*) _a4_closure;
    vader_defer_push(vader_ref_box(t2));
    vader_array_t* _a5_arr = vader_array_new(10u, 0u, 0u, 230u);
    l7 = (void*) _a5_arr;
    for (;;) {
        l3 = vader_host_system_windows_find_data_name(l5);
        if (l3 != 295u) {
            if (l3 != 296u) {
                vader_array_push((vader_array_t*) l7, vader_box_string(230u, l3));
            }
        }
        t5 = vader_host_system_windows_find_next_file(l6, l5);
        if (!(t5)) {
            vader_defer_pop_exec(1u);
            { vader_box_t __vret = vader_ref_box(l7); vader_gc_top = gc_frame.prev; return __vret; }
        }
        continue;
    }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t std_io_read_file_bytes(vader_string_t l0, size_t l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    uint32_t l3;
    void* l4;
    size_t l7, l9;
    int32_t t0;
    ptrdiff_t t1;
    void* t2 = NULL;
    size_t t3;
    bool t4;
    int64_t t5;
    void** gc_raw_roots[5] = { &l2, &l5, &l6, &l8, &t2 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = std_io_to_wide(l0);
    t0 = (INT32_C(1) | INT32_C(2));
    l3 = (uint32_t) (int32_t) t0;
    l4 = vader_host_system_windows_create_file_w(l2, (uint32_t) (int32_t) INT32_MIN, l3, vader_box_obj(0u, NULL), (uint32_t) 3, (uint32_t) 128, vader_box_obj(0u, NULL));
    t1 = (ptrdiff_t) (void*) l4;
    if (t1 == INT64_C(-1)) {
        t2 = std_io_last_io_error(1646u);
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(13u, 0u, 1u, 236u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(13u, 1u, 1u, 236u);
    ((uint8_t*) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = (uint8_t) INT32_C(0);
    t2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_repeat((vader_array_t*) t2, (size_t) INT64_C(65536));
    l5 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(15u, 1u, 3u, 238u);
    ((int32_t*) _a3_arr->buf->slots)[_a3_arr->offset + 0u] = (int32_t) INT32_C(0);
    l6 = (void*) _a3_arr;
    for (;;) {
        t3 = ((vader_array_t*) l5)->length;
        t0 = ((int32_t) (size_t) t3);
        l3 = (uint32_t) (int32_t) t0;
        t4 = vader_host_system_windows_read_file(l4, l5, l3, l6, vader_box_obj(0u, NULL));
        if (t4) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, INT32_C(0))
            t0 = ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) INT32_C(0)];
            t5 = ((int64_t) (uint32_t) t0);
            l7 = (size_t) (int64_t) t5;
            if ((l7 > INT64_C(0))) {
                vader_array_t* _a5_arr = vader_array_slice((vader_array_t*) l5, (size_t) INT64_C(0), (size_t) l7);
                l8 = (void*) _a5_arr;
                vader_array_push_all((vader_array_t*) l2, (vader_array_t*) l8);
            }
            t3 = ((vader_array_t*) l2)->length;
            if ((t3 > l1)) {
                vader_host_system_windows_close_handle(l4);
                vader_struct_std_io_IOError_t* _a6_obj = (vader_struct_std_io_IOError_t*) vader_gc_alloc(sizeof(vader_struct_std_io_IOError_t));
                vader_obj_header_init(_a6_obj, 410u);
                _a6_obj->f_msg = 1647u;
                _a6_obj->f_kind = (uint8_t) 0;
                _a6_obj->f_code = INT32_C(0);
                t2 = (void*) _a6_obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l9 = ((vader_array_t*) l5)->length;
            if (!((l7 < l9))) {
                continue;
            }
            vader_host_system_windows_close_handle(l4);
            { vader_box_t __vret = vader_ref_box(l2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        break;
    }
    l2 = std_io_last_io_error(2076u);
    vader_host_system_windows_close_handle(l4);
    { vader_box_t __vret = vader_ref_box(l2); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t std_io_read_file_string(vader_string_t l0, size_t l1) {
    vader_box_t l2 = vader_box_null();
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l2, &t2 };
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = std_io_read_file_bytes(l0, l1);
    if (!(l2.tag == 410u)) {
        t0 = l2.payload.obj;
        t1 = vader_host_std_core_bytes_to_string(t0);
        t2 = vader_box_string(230u, t1);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l2.payload.obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t std_io_to_slash(vader_string_t l0) {
    void* l1 = NULL;
    size_t l2, l3;
    uint8_t l4;
    uint8_t t0;
    int64_t t1;
    vader_string_t t2 = 0;
    void** gc_raw_roots[1] = { &l1 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(13u, 1u, 1u, 236u);
    ((uint8_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (uint8_t) INT32_C(0);
    l1 = (void*) _a0_arr;
    l2 = vader_host_std_core_byte_len(l0);
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (size_t) l2);
    l1 = (void*) _a1_arr;
    l2 = (size_t) 0;
    l3 = vader_host_std_core_byte_len(l0);
    while ((l2 < l3)) {
        t0 = vader_host_std_core_byte_at(l0, l2);
        if (t0 == INT32_C(92)) {
            l4 = (uint8_t) 47;
        } else {
            l4 = vader_host_std_core_byte_at(l0, l2);
        }
        vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
        ((uint8_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l2] = (uint8_t) (int32_t) (uint8_t) l4;
        t1 = (l2 + INT64_C(1));
        l2 = (size_t) (int64_t) t1;
    }
    t2 = vader_host_std_core_bytes_to_string(l1);
    { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* std_io_to_wide(vader_string_t l0) {
    void* l1 = NULL;
    int32_t l2, l4;
    size_t l3;
    void* t0 = NULL;
    int64_t t1;
    int32_t t2;
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(14u, 0u, 2u, 237u);
    l1 = (void*) _a0_arr;
    l2 = -(INT32_C(1));
    l2 = vader_host_system_windows_multi_byte_to_wide_char((uint32_t) 65001, (uint32_t) 0, l0, l2, l1, INT32_C(0));
    if ((l2 <= INT32_C(0))) {
        vader_array_t* _a1_arr = vader_array_new(14u, 0u, 2u, 237u);
        t0 = (void*) _a1_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a2_arr = vader_array_new(14u, 1u, 2u, 237u);
    ((uint16_t*) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = (uint16_t) INT32_C(0);
    l1 = (void*) _a2_arr;
    t1 = ((int64_t) (int32_t) l2);
    l3 = (size_t) (int64_t) t1;
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) l1, (size_t) l3);
    l1 = (void*) _a3_arr;
    l4 = -(INT32_C(1));
    t2 = vader_host_system_windows_multi_byte_to_wide_char((uint32_t) 65001, (uint32_t) 0, l0, l4, l1, l2);
    if (!((t2 <= INT32_C(0)))) {
        { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a4_arr = vader_array_new(14u, 0u, 2u, 237u);
    t0 = (void*) _a4_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t std_io_without_trailing_sep(vader_string_t l0) {
    void* l1 = NULL;
    size_t l2, l3, l4, l5, l6;
    size_t t0;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    uint8_t t3;
    void* t4 = NULL;
    vader_string_t t5 = 0;
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[2] = { &l1, &t4 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_host_std_core_bytes(l0);
    l2 = (size_t) 0;
    l3 = (size_t) 0;
    l4 = ((vader_array_t*) l1)->length;
    while ((l3 < l4)) {
        t0 = ((vader_array_t*) l1)->length;
        t1 = ((t0 - INT64_C(1)) - l3);
        l5 = (size_t) (int64_t) t1;
        if (l5 == INT64_C(0)) break;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        t2 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l5, 236u);
        t3 = ((uint8_t) t2.payload.i);
        if (t3 != INT32_C(47)) break;
        t1 = (l5 - INT64_C(1));
        l6 = (size_t) (int64_t) t1;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        t2 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) l6, 236u);
        t3 = ((uint8_t) t2.payload.i);
        if (t3 == INT32_C(58)) break;
        t1 = (l2 + INT64_C(1));
        l2 = (size_t) (int64_t) t1;
        t1 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t1;
    }
    if (!(l2 == INT64_C(0))) {
        t0 = ((vader_array_t*) l1)->length;
        t1 = (t0 - l2);
        l2 = (size_t) (int64_t) t1;
        vader_array_t* _a2_arr = vader_array_slice((vader_array_t*) l1, (size_t) INT64_C(0), (size_t) l2);
        t4 = (void*) _a2_arr;
        t5 = vader_host_std_core_bytes_to_string(t4);
        { vader_string_t __vret = t5; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_string_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void std_io_write(uint8_t l0, vader_string_t l1) {
    void* l2 = NULL;
    void* l6 = NULL;
    size_t l3, l4, l5, l7, l9;
    int32_t l8;
    int64_t t0;
    void** gc_raw_roots[2] = { &l2, &l6 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_host_std_core_bytes(l1);
    l3 = (size_t) 0;
    for (;;) {
        l4 = ((vader_array_t*) l2)->length;
        if (!((l3 >= l4))) {
            l5 = ((vader_array_t*) l2)->length;
            vader_array_t* _a0_arr = vader_array_slice((vader_array_t*) l2, (size_t) l3, (size_t) l5);
            l6 = (void*) _a0_arr;
            l7 = ((vader_array_t*) l6)->length;
            l8 = std_io_write_bytes(l0, l6, l7);
            if ((l8 <= INT32_C(0))) {
                { vader_gc_top = gc_frame.prev; return; }
            }
            t0 = ((int64_t) (int32_t) l8);
            l9 = (size_t) (int64_t) t0;
            t0 = (l3 + l9);
            l3 = (size_t) (int64_t) t0;
            continue;
        }
        break;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static int32_t std_io_write_bytes(uint8_t l0, void* l1, size_t l2) {
    uint32_t l3;
    void* l4 = NULL;
    void* l5;
    int32_t t0;
    bool t1;
    void** gc_raw_roots[2] = { &l1, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(0)) {
        l3 = (uint32_t) -11;
    } else {
        l3 = (uint32_t) -12;
    }
    vader_array_t* _a0_arr = vader_array_new(15u, 1u, 3u, 238u);
    ((int32_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int32_t) INT32_C(0);
    l4 = (void*) _a0_arr;
    l5 = vader_host_system_windows_get_std_handle(l3);
    t0 = ((int32_t) (size_t) l2);
    l3 = (uint32_t) (int32_t) t0;
    t1 = vader_host_system_windows_write_file(l5, l1, l3, l4, vader_box_obj(0u, NULL));
    if (!(t1)) {
        { int32_t __vret = -(INT32_C(1)); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { int32_t __vret = ((int32_t) (size_t) l2); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t std_io_write_file_bytes(vader_string_t l0, void* l1) {
    size_t l2, l3;
    void* l4;
    void* l5 = NULL;
    uint32_t l6;
    uint8_t t0;
    void* t1 = NULL;
    int64_t t2;
    ptrdiff_t t3;
    size_t t4;
    int32_t t5;
    bool t6;
    void** gc_raw_roots[3] = { &l1, &l5, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_host_std_core_byte_len(l0);
    l3 = (size_t) 0;
    while ((l3 < l2)) {
        t0 = vader_host_std_core_byte_at(l0, l3);
        if (t0 == INT32_C(0)) {
            vader_struct_std_io_IOError_t* _a0_obj = (vader_struct_std_io_IOError_t*) vader_gc_alloc(sizeof(vader_struct_std_io_IOError_t));
            vader_obj_header_init(_a0_obj, 410u);
            _a0_obj->f_msg = 2045u;
            _a0_obj->f_kind = (uint8_t) 0;
            _a0_obj->f_code = INT32_C(0);
            t1 = (void*) _a0_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t2;
    }
    t1 = std_io_to_wide(l0);
    l4 = vader_host_system_windows_create_file_w(t1, (uint32_t) 1073741824, (uint32_t) 1, vader_box_obj(0u, NULL), (uint32_t) 2, (uint32_t) 128, vader_box_obj(0u, NULL));
    t3 = (ptrdiff_t) (void*) l4;
    if (t3 == INT64_C(-1)) {
        t1 = std_io_last_io_error(2018u);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t4 = ((vader_array_t*) l1)->length;
    if ((t4 > INT64_C(0))) {
        vader_array_t* _a1_arr = vader_array_new(15u, 1u, 3u, 238u);
        ((int32_t*) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = (int32_t) INT32_C(0);
        l5 = (void*) _a1_arr;
        t4 = ((vader_array_t*) l1)->length;
        t5 = ((int32_t) (size_t) t4);
        l6 = (uint32_t) (int32_t) t5;
        t6 = vader_host_system_windows_write_file(l4, l1, l6, l5, vader_box_obj(0u, NULL));
        if (!(t6)) {
            l5 = std_io_last_io_error(2134u);
            vader_host_system_windows_close_handle(l4);
            { vader_box_t __vret = vader_ref_box(l5); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    t6 = vader_host_system_windows_close_handle(l4);
    if (!(t6)) {
        t1 = std_io_last_io_error(1423u);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

vader_box_t std_io_write_file_string(vader_string_t l0, vader_string_t l1) {
    void* l2 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[1] = { &l2 };
    vader_string_t* gc_atom_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_host_std_core_bytes(l1);
    t0 = std_io_write_file_bytes(l0, l2);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}
