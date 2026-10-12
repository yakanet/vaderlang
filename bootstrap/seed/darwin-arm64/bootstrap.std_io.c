#include "bootstrap.split.h"

static vader_string_t std_io_describe_io_error_kind(uint8_t l0);
static void* std_io_last_io_error(vader_string_t l0);
static vader_box_t std_io_read_file_bytes(vader_string_t l0, size_t l1);
static vader_string_t std_io_to_slash(vader_string_t l0);
static vader_string_t std_io_up_to_nul(void* l0);
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
    void* l1 = NULL;
    void* t0 = NULL;
    int32_t t1;
    vader_string_t t2 = 0;
    vader_string_t t4 = 0;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t3 };
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_string_t* gc_atom_roots[2] = { &t2, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(16u, 1u, 1u, 250u);
    ((uint8_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (uint8_t) INT32_C(0);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) INT32_C(4096));
    l0 = (void*) _a1_arr;
    t1 = vader_host_system_darwin_ns_get_executable_path(l0, (uint32_t) 4096);
    if (t1 != INT32_C(0)) {
        { vader_gc_top = gc_frame.prev; return 309u; }
    }
    vader_array_t* _a2_arr = vader_array_new(16u, 1u, 1u, 250u);
    ((uint8_t*) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = (uint8_t) INT32_C(0);
    t0 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) t0, (size_t) INT32_C(4096));
    l1 = (void*) _a3_arr;
    t2 = std_io_up_to_nul(l0);
    t3 = vader_host_system_posix_sys_realpath(t2, l1);
    if (!(t3.tag == 0u)) {
        t2 = std_io_up_to_nul(l1);
        t4 = std_io_to_slash(t2);
        { vader_string_t __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return 309u; }
}

vader_string_t std_io_current_working_directory(void) {
    void* l0 = NULL;
    size_t l1;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_string_t t2 = 0;
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[2] = { &t2, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(16u, 1u, 1u, 250u);
    ((uint8_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (uint8_t) INT32_C(0);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) INT32_C(4096));
    l0 = (void*) _a1_arr;
    l1 = ((vader_array_t*) l0)->length;
    t1 = vader_host_system_posix_sys_getcwd(l0, l1);
    if (!(t1.tag == 0u)) {
        t2 = std_io_up_to_nul(l0);
        t3 = std_io_to_slash(t2);
        t2 = std_io_without_trailing_sep(t3);
        { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return 309u; }
}

static vader_string_t std_io_describe_io_error_kind(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(1)) {
        l1 = 1696u;
        return l1;
    }
    if (l0 == INT32_C(2)) {
        l1 = 2113u;
    } else if (l0 == INT32_C(3)) {
        l1 = 1871u;
    } else if (l0 == INT32_C(4)) {
        l1 = 1252u;
    } else if (l0 == INT32_C(5)) {
        l1 = 2063u;
    } else if (l0 == INT32_C(6)) {
        l1 = 1892u;
    } else if (l0 == INT32_C(7)) {
        l1 = 2648u;
    } else if (l0 == INT32_C(8)) {
        l1 = 1367u;
    } else if (l0 == INT32_C(9)) {
        l1 = 2057u;
    } else if (l0 == INT32_C(10)) {
        l1 = 1883u;
    } else if (l0 == INT32_C(11)) {
        l1 = 1544u;
    } else if (l0 == INT32_C(12)) {
        l1 = 1337u;
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
    int32_t t0;
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = vader_host_system_posix_sys_access(l0, INT32_C(0));
    { bool __vret = t0 == INT32_C(0); vader_gc_top = gc_frame.prev; return __vret; }
}

bool std_io_is_dir(vader_string_t l0) {
    int32_t t0;
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = vader_host_system_posix_sys_path_kind(l0);
    { bool __vret = t0 == INT32_C(2); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* std_io_last_io_error(vader_string_t l0) {
    int32_t l1, l3;
    uint8_t l2;
    vader_string_t l4 = 0;
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[2] = { &l0, &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_host_system_posix_sys_last_errno();
    l2 = (uint8_t) 0;
    if (l1 == INT32_C(2)) {
        l2 = (uint8_t) 1;
    }
    if (l1 == INT32_C(1)) {
        l2 = (uint8_t) 2;
    }
    if (l1 == INT32_C(13)) {
        l2 = (uint8_t) 2;
    }
    if (l1 == INT32_C(4)) {
        l2 = (uint8_t) 3;
    }
    if (l1 == INT32_C(17)) {
        l2 = (uint8_t) 4;
    }
    if (l1 == INT32_C(20)) {
        l2 = (uint8_t) 5;
    }
    if (l1 == INT32_C(21)) {
        l2 = (uint8_t) 6;
    }
    if (INT32_C(2) == INT32_C(2)) {
        l3 = INT32_C(35);
    } else {
        l3 = INT32_C(11);
    }
    if (l1 == l3) {
        l2 = (uint8_t) 7;
    }
    if (l1 == INT32_C(32)) {
        l2 = (uint8_t) 8;
    }
    if (l1 == INT32_C(28)) {
        l2 = (uint8_t) 9;
    }
    if (l1 == INT32_C(22)) {
        l2 = (uint8_t) 10;
    }
    if (INT32_C(2) == INT32_C(2)) {
        l3 = INT32_C(66);
    } else {
        l3 = INT32_C(39);
    }
    if (l1 == l3) {
        l2 = (uint8_t) 11;
    }
    if (l1 == INT32_C(9)) {
        l2 = (uint8_t) 12;
    }
    l4 = std_io_describe_io_error_kind(l2);
    if (l4 == 0u) {
        vader_struct_std_io_IOError_t* _a0_obj = (vader_struct_std_io_IOError_t*) vader_gc_alloc(sizeof(vader_struct_std_io_IOError_t));
        vader_obj_header_init(_a0_obj, 437u);
        _a0_obj->f_msg = l0;
        _a0_obj->f_kind = l2;
        _a0_obj->f_code = l1;
        t0 = (void*) _a0_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_std_io_IOError_t* _a1_obj = (vader_struct_std_io_IOError_t*) vader_gc_alloc(sizeof(vader_struct_std_io_IOError_t));
    vader_obj_header_init(_a1_obj, 437u);
    _a1_obj->f_msg = l4;
    _a1_obj->f_kind = l2;
    _a1_obj->f_code = l1;
    t0 = (void*) _a1_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t std_io_read_dir(vader_string_t l0) {
    void* l1;
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    vader_string_t l4 = 0;
    vader_string_t t0 = 0;
    void* t1 = NULL;
    void* t2;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l3, &t1 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l4, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_host_system_posix_sys_opendir(l0);
    if (l2.tag == 0u) {
        t0 = concat_3(2142u, l0, 866u);
        vader_struct_std_io_IOError_t* _a0_obj = (vader_struct_std_io_IOError_t*) vader_gc_alloc(sizeof(vader_struct_std_io_IOError_t));
        vader_obj_header_init(_a0_obj, 437u);
        _a0_obj->f_msg = t0;
        _a0_obj->f_kind = (uint8_t) 0;
        _a0_obj->f_code = INT32_C(0);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = ((void*) (intptr_t) l2.payload.i);
    vader_struct___defer_env_std_io_1_t* _a1_obj = (vader_struct___defer_env_std_io_1_t*) vader_gc_alloc(sizeof(vader_struct___defer_env_std_io_1_t));
    vader_obj_header_init(_a1_obj, 259u);
    _a1_obj->f_cap_0 = l1;
    t1 = (void*) _a1_obj;
    vader_fn_t* _a2_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a2_closure, 209u);
    _a2_closure->code = (void*) &vader_fn_lift___defer_std_io_0;
    _a2_closure->env = t1;
    t1 = (void*) _a2_closure;
    vader_defer_push(vader_ref_box(t1));
    vader_array_t* _a3_arr = vader_array_new(13u, 0u, 0u, 244u);
    l3 = (void*) _a3_arr;
    for (;;) {
        l2 = vader_host_system_posix_sys_readdir(l1);
        if (!(l2.tag == 0u)) {
            t2 = ((void*) (intptr_t) l2.payload.i);
            l4 = vader_host_system_posix_dirent_name(t2);
            if (!(l4 != 309u)) {
                continue;
            }
            if (!(l4 != 310u)) {
                continue;
            }
            vader_array_push((vader_array_t*) l3, vader_box_string(244u, l4));
            continue;
        }
        break;
    }
    vader_defer_pop_exec(1u);
    { vader_box_t __vret = vader_ref_box(l3); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t std_io_read_file_bytes(vader_string_t l0, size_t l1) {
    void* l2;
    vader_box_t l3 = vader_box_null();
    void* l4 = NULL;
    void* l5 = NULL;
    void* l8 = NULL;
    size_t l6, l7, l9;
    void* t0 = NULL;
    size_t t1;
    int32_t t2;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[4] = { &l4, &l5, &l8, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_host_system_posix_sys_fopen(l0, 2136u);
    if (l3.tag == 0u) {
        t0 = std_io_last_io_error(1446u);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((void*) (intptr_t) l3.payload.i);
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 1u, 250u);
    l4 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(16u, 1u, 1u, 250u);
    ((uint8_t*) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = (uint8_t) INT32_C(0);
    t0 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_repeat((vader_array_t*) t0, (size_t) INT64_C(65536));
    l5 = (void*) _a2_arr;
    for (;;) {
        l6 = ((vader_array_t*) l5)->length;
        l7 = vader_host_system_posix_sys_fread(l5, (size_t) 1, l6, l2);
        if ((l7 > INT64_C(0))) {
            vader_array_t* _a3_arr = vader_array_slice((vader_array_t*) l5, (size_t) INT64_C(0), (size_t) l7);
            l8 = (void*) _a3_arr;
            vader_array_push_all((vader_array_t*) l4, (vader_array_t*) l8);
        }
        t1 = ((vader_array_t*) l4)->length;
        if ((t1 > l1)) {
            vader_host_system_posix_sys_fclose(l2);
            vader_struct_std_io_IOError_t* _a4_obj = (vader_struct_std_io_IOError_t*) vader_gc_alloc(sizeof(vader_struct_std_io_IOError_t));
            vader_obj_header_init(_a4_obj, 437u);
            _a4_obj->f_msg = 1697u;
            _a4_obj->f_kind = (uint8_t) 0;
            _a4_obj->f_code = INT32_C(0);
            t0 = (void*) _a4_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l9 = ((vader_array_t*) l5)->length;
        if (!((l7 < l9))) {
            continue;
        }
        t2 = vader_host_system_posix_sys_ferror(l2);
        if (t2 != INT32_C(0)) {
            t0 = std_io_last_io_error(2141u);
            l3 = vader_ref_box(t0);
        } else {
            l3 = vader_box_obj(0u, NULL);
        }
        vader_host_system_posix_sys_fclose(l2);
        if (!(l3.tag == 0u)) {
            t0 = l3.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_box_t __vret = vader_ref_box(l4); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_gc_top = gc_frame.prev;
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
    if (!(l2.tag == 437u)) {
        t0 = l2.payload.obj;
        t1 = vader_host_std_core_bytes_to_string(t0);
        t2 = vader_box_string(244u, t1);
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
    vader_array_t* _a0_arr = vader_array_new(16u, 1u, 1u, 250u);
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

static vader_string_t std_io_up_to_nul(void* l0) {
    size_t l1, l2, l3;
    vader_box_t t0 = vader_box_null();
    uint8_t t1;
    int64_t t2;
    void* t3 = NULL;
    vader_string_t t4 = 0;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l0, &t3 };
    vader_string_t* gc_atom_roots[1] = { &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_array_t*) l0)->length;
    l2 = (size_t) 0;
    l3 = ((vader_array_t*) l0)->length;
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l2, 250u);
        t1 = ((uint8_t) t0.payload.i);
        if (t1 == INT32_C(0)) {
            l1 = l2;
            break;
        }
        t2 = (l2 + INT64_C(1));
        l2 = (size_t) (int64_t) t2;
    }
    vader_array_t* _a1_arr = vader_array_slice((vader_array_t*) l0, (size_t) INT64_C(0), (size_t) l1);
    t3 = (void*) _a1_arr;
    t4 = vader_host_std_core_bytes_to_string(t3);
    { vader_string_t __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t std_io_without_trailing_sep(vader_string_t l0) {
    void* l1 = NULL;
    size_t l2, l3, l4, l5, l6;
    size_t t0;
    int64_t t1, t2;
    vader_box_t t3 = vader_box_null();
    uint8_t t4;
    void* t5 = NULL;
    vader_string_t t6 = 0;
    vader_box_t* gc_roots[1] = { &t3 };
    void** gc_raw_roots[2] = { &l1, &t5 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t6 };
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
        t1 = vader_chk_sub(usize, t0, INT64_C(1));
        t2 = vader_chk_sub(usize, t1, l3);
        l5 = (size_t) (int64_t) t2;
        if (l5 == INT64_C(0)) break;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        t3 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l5, 250u);
        t4 = ((uint8_t) t3.payload.i);
        if (t4 != INT32_C(47)) break;
        t1 = vader_chk_sub(usize, l5, INT64_C(1));
        l6 = (size_t) (int64_t) t1;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        t3 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) l6, 250u);
        t4 = ((uint8_t) t3.payload.i);
        if (t4 == INT32_C(58)) break;
        t1 = vader_chk_add(usize, l2, INT64_C(1));
        l2 = (size_t) (int64_t) t1;
        t1 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t1;
    }
    if (!(l2 == INT64_C(0))) {
        t0 = ((vader_array_t*) l1)->length;
        t1 = vader_chk_sub(usize, t0, l2);
        l2 = (size_t) (int64_t) t1;
        vader_array_t* _a2_arr = vader_array_slice((vader_array_t*) l1, (size_t) INT64_C(0), (size_t) l2);
        t5 = (void*) _a2_arr;
        t6 = vader_host_std_core_bytes_to_string(t5);
        { vader_string_t __vret = t6; vader_gc_top = gc_frame.prev; return __vret; }
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
            t0 = vader_chk_add(usize, l3, l9);
            l3 = (size_t) (int64_t) t0;
            continue;
        }
        break;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static int32_t std_io_write_bytes(uint8_t l0, void* l1, size_t l2) {
    ptrdiff_t t0;
    void** gc_raw_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(0)) {
        t0 = vader_host_system_posix_sys_write(INT32_C(1), l1, l2);
        { int32_t __vret = ((int32_t) (ptrdiff_t) t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_host_system_posix_sys_write(INT32_C(2), l1, l2);
    { int32_t __vret = ((int32_t) (ptrdiff_t) t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t std_io_write_file_bytes(vader_string_t l0, void* l1) {
    size_t l2, l3;
    void* l4;
    vader_box_t l5 = vader_box_null();
    void* l6 = NULL;
    uint8_t t0;
    void* t1 = NULL;
    int64_t t2;
    size_t t3;
    int32_t t4;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[3] = { &l1, &l6, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_host_std_core_byte_len(l0);
    l3 = (size_t) 0;
    while ((l3 < l2)) {
        t0 = vader_host_std_core_byte_at(l0, l3);
        if (t0 == INT32_C(0)) {
            vader_struct_std_io_IOError_t* _a0_obj = (vader_struct_std_io_IOError_t*) vader_gc_alloc(sizeof(vader_struct_std_io_IOError_t));
            vader_obj_header_init(_a0_obj, 437u);
            _a0_obj->f_msg = 2108u;
            _a0_obj->f_kind = (uint8_t) 0;
            _a0_obj->f_code = INT32_C(0);
            t1 = (void*) _a0_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t2;
    }
    l5 = vader_host_system_posix_sys_fopen(l0, 2639u);
    if (l5.tag == 0u) {
        t1 = std_io_last_io_error(2082u);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = ((void*) (intptr_t) l5.payload.i);
    t3 = ((vader_array_t*) l1)->length;
    if ((t3 > INT64_C(0))) {
        l2 = ((vader_array_t*) l1)->length;
        l2 = vader_host_system_posix_sys_fwrite(l1, (size_t) 1, l2, l4);
        l3 = ((vader_array_t*) l1)->length;
        if (l2 != l3) {
            l6 = std_io_last_io_error(2199u);
            vader_host_system_posix_sys_fclose(l4);
            { vader_box_t __vret = vader_ref_box(l6); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    t4 = vader_host_system_posix_sys_fclose(l4);
    if (!(t4 != INT32_C(0))) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t1 = std_io_last_io_error(1470u);
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
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
