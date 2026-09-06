#include "bootstrap.split.h"

static vader_string_t std_io_describe_io_error_kind(uint8_t l0);
static void* std_io_last_io_error(vader_string_t l0);
static vader_box_t std_io_read_file_bytes(vader_string_t l0, size_t l1);
static vader_string_t std_io_to_slash(vader_string_t l0);
static vader_string_t std_io_up_to_nul(void* l0);
static vader_string_t std_io_without_trailing_sep(vader_string_t l0);
static int32_t std_io_write_bytes(int32_t l0, void* l1, size_t l2);
static vader_box_t std_io_write_file_bytes(vader_string_t l0, void* l1);

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
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(11u, 1u, 1u, 175u);
    ((uint8_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (uint8_t) INT32_C(0);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) INT32_C(4096));
    l0 = (void*) _a1_arr;
    t1 = vader_host_system_darwin_ns_get_executable_path(l0, (uint32_t) (int32_t) INT32_C(4096));
    if (t1 != INT32_C(0)) {
        { vader_gc_top = gc_frame.prev; return 407u; }
    }
    vader_array_t* _a2_arr = vader_array_new(11u, 1u, 1u, 175u);
    ((uint8_t*) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = (uint8_t) INT32_C(0);
    t0 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) t0, (size_t) INT32_C(4096));
    l1 = (void*) _a3_arr;
    t2 = std_io_up_to_nul(l0);
    t3 = vader_host_system_posix_sys_realpath(t2, l1);
    if (t3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return 407u; }
    }
    t2 = std_io_up_to_nul(l1);
    t4 = std_io_to_slash(t2);
    { vader_string_t __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(11u, 1u, 1u, 175u);
    ((uint8_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (uint8_t) INT32_C(0);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) INT32_C(4096));
    l0 = (void*) _a1_arr;
    l1 = ((vader_array_t*) l0)->length;
    t1 = vader_host_system_posix_sys_getcwd(l0, l1);
    if (t1.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return 407u; }
    }
    t2 = std_io_up_to_nul(l0);
    t3 = std_io_to_slash(t2);
    t2 = std_io_without_trailing_sep(t3);
    { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t std_io_describe_io_error_kind(uint8_t l0) {
    if (l0 == INT32_C(1)) {
        return 1586u;
    }
    if (l0 == INT32_C(2)) {
        return 1940u;
    }
    if (l0 == INT32_C(3)) {
        return 1740u;
    }
    if (l0 == INT32_C(4)) {
        return 1174u;
    }
    if (l0 == INT32_C(5)) {
        return 1907u;
    }
    if (l0 == INT32_C(6)) {
        return 1760u;
    }
    if (l0 == INT32_C(7)) {
        return 2402u;
    }
    if (l0 == INT32_C(8)) {
        return 1280u;
    }
    if (l0 == INT32_C(9)) {
        return 1902u;
    }
    if (l0 == INT32_C(10)) {
        return 1751u;
    }
    if (l0 == INT32_C(11)) {
        return 1445u;
    }
    if (l0 == INT32_C(12)) {
        return 1250u;
    }
    if (l0 == INT32_C(0)) {
        return 0u;
    }
    vader_unreachable("unreachable return in std_io$describe_io_error_kind");
}

bool std_io_exists(vader_string_t l0) {
    int32_t t0;
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = vader_host_system_posix_sys_access(l0, INT32_C(0));
    { bool __vret = t0 == INT32_C(0); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

bool std_io_is_dir(vader_string_t l0) {
    int32_t t0;
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = vader_host_system_posix_sys_path_kind(l0);
    { bool __vret = t0 == INT32_C(2); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* std_io_last_io_error(vader_string_t l0) {
    int32_t l1, l3;
    uint8_t l2;
    vader_string_t l4 = 0;
    vader_string_t l5 = 0;
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l4, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_host_system_posix_sys_last_errno();
    l2 = (uint8_t) (int32_t) INT32_C(0);
    if (l1 == INT32_C(2)) {
        l2 = (uint8_t) (int32_t) INT32_C(1);
    } else {
    }
    if (l1 == INT32_C(1)) {
        l2 = (uint8_t) (int32_t) INT32_C(2);
    } else {
    }
    if (l1 == INT32_C(13)) {
        l2 = (uint8_t) (int32_t) INT32_C(2);
    } else {
    }
    if (l1 == INT32_C(4)) {
        l2 = (uint8_t) (int32_t) INT32_C(3);
    } else {
    }
    if (l1 == INT32_C(17)) {
        l2 = (uint8_t) (int32_t) INT32_C(4);
    } else {
    }
    if (l1 == INT32_C(20)) {
        l2 = (uint8_t) (int32_t) INT32_C(5);
    } else {
    }
    if (l1 == INT32_C(21)) {
        l2 = (uint8_t) (int32_t) INT32_C(6);
    } else {
    }
    if (INT32_C(2) == INT32_C(2)) {
        l3 = INT32_C(35);
    } else {
        l3 = INT32_C(11);
    }
    if (l1 == l3) {
        l2 = (uint8_t) (int32_t) INT32_C(7);
    } else {
    }
    if (l1 == INT32_C(32)) {
        l2 = (uint8_t) (int32_t) INT32_C(8);
    } else {
    }
    if (l1 == INT32_C(28)) {
        l2 = (uint8_t) (int32_t) INT32_C(9);
    } else {
    }
    if (l1 == INT32_C(22)) {
        l2 = (uint8_t) (int32_t) INT32_C(10);
    } else {
    }
    if (INT32_C(2) == INT32_C(2)) {
        l3 = INT32_C(66);
    } else {
        l3 = INT32_C(39);
    }
    if (l1 == l3) {
        l2 = (uint8_t) (int32_t) INT32_C(11);
    } else {
    }
    if (l1 == INT32_C(9)) {
        l2 = (uint8_t) (int32_t) INT32_C(12);
    } else {
    }
    l4 = std_io_describe_io_error_kind(l2);
    if (l4 == 0u) {
        l5 = l0;
    } else {
        l5 = l4;
    }
    vader_struct_std_io_IOError_t* _a0_obj = (vader_struct_std_io_IOError_t*) vader_gc_alloc(sizeof(vader_struct_std_io_IOError_t));
    vader_obj_header_init(_a0_obj, 388u);
    _a0_obj->f_msg = l5;
    _a0_obj->f_kind = l2;
    _a0_obj->f_code = l1;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t std_io_read_dir(vader_string_t l0) {
    vader_box_t l1 = vader_box_null(), l3 = vader_box_null();
    void* l2 = NULL;
    vader_string_t l4 = 0;
    bool l5;
    vader_string_t t0 = 0;
    void* t1 = NULL;
    void* t2;
    vader_box_t* gc_roots[2] = { &l1, &l3 };
    void** gc_raw_roots[2] = { &l2, &t1 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_host_system_posix_sys_opendir(l0);
    if (l1.tag == 0u) {
        t0 = concat_3(1961u, l0, 924u);
        vader_struct_std_io_IOError_t* _a0_obj = (vader_struct_std_io_IOError_t*) vader_gc_alloc(sizeof(vader_struct_std_io_IOError_t));
        vader_obj_header_init(_a0_obj, 388u);
        _a0_obj->f_msg = t0;
        _a0_obj->f_kind = (uint8_t) (int32_t) INT32_C(0);
        _a0_obj->f_code = INT32_C(0);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = ((void*) (intptr_t) l1.payload.i);
    vader_struct__Cell_CPointer_t* _a1_obj = (vader_struct__Cell_CPointer_t*) vader_gc_alloc(sizeof(vader_struct__Cell_CPointer_t));
    vader_obj_header_init(_a1_obj, 188u);
    _a1_obj->f_value = t2;
    t1 = (void*) _a1_obj;
    l1 = vader_ref_box(t1);
    vader_struct___defer_env_std_io_1_t* _a2_obj = (vader_struct___defer_env_std_io_1_t*) vader_gc_alloc(sizeof(vader_struct___defer_env_std_io_1_t));
    vader_obj_header_init(_a2_obj, 241u);
    _a2_obj->f_cap_0 = l1;
    t1 = (void*) _a2_obj;
    vader_fn_t* _a3_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a3_closure, 137u);
    _a3_closure->code = (void*) &vader_fn_lift___defer_std_io_0;
    _a3_closure->env = t1;
    t1 = (void*) _a3_closure;
    vader_defer_push(vader_ref_box(t1));
    vader_array_t* _a4_arr = vader_array_new(8u, 0u, 0u, 169u);
    l2 = (void*) _a4_arr;
    {
        loop_24: {
            l3 = vader_host_system_posix_sys_readdir(((vader_struct__Cell_CPointer_t*) l1.payload.obj)->f_value);
            if (l3.tag == 0u) {
            } else {
                t2 = ((void*) (intptr_t) l3.payload.i);
                l4 = vader_host_system_posix_dirent_name(t2);
                if (l4 != 407u) {
                    l5 = l4 != 408u;
                } else {
                    l5 = false;
                }
                if (l5) {
                    vader_array_push((vader_array_t*) l2, vader_box_string(169u, l4));
                } else {
                }
                goto loop_24;
            }
        }
    }
    vader_defer_pop_exec(1u);
    { vader_box_t __vret = vader_ref_box(l2); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t std_io_read_file_bytes(vader_string_t l0, size_t l1) {
    vader_box_t l2 = vader_box_null(), l10 = vader_box_null();
    void* l3 = NULL;
    void* l4 = NULL;
    void* l8 = NULL;
    size_t l5, l7, l9;
    void* l6;
    void* t0 = NULL;
    size_t t1;
    void* t2;
    int32_t t3;
    vader_box_t* gc_roots[2] = { &l2, &l10 };
    void** gc_raw_roots[4] = { &l3, &l4, &l8, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = vader_host_system_posix_sys_fopen(l0, 1955u);
    if (l2.tag == 0u) {
        t0 = std_io_last_io_error(1348u);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(11u, 0u, 1u, 175u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(11u, 1u, 1u, 175u);
    ((uint8_t*) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = (uint8_t) INT32_C(0);
    t0 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_repeat((vader_array_t*) t0, (size_t) INT64_C(65536));
    l4 = (void*) _a2_arr;
    {
        loop_18: {
            l5 = ((vader_array_t*) l4)->length;
            l6 = ((void*) (intptr_t) l2.payload.i);
            l7 = vader_host_system_posix_sys_fread(l4, (size_t) (int64_t) INT64_C(1), l5, l6);
            if ((l7 > INT64_C(0))) {
                vader_array_t* _a3_arr = vader_array_slice((vader_array_t*) l4, (size_t) INT64_C(0), (size_t) l7);
                l8 = (void*) _a3_arr;
                vader_array_push_all((vader_array_t*) l3, (vader_array_t*) l8);
            } else {
            }
            t1 = ((vader_array_t*) l3)->length;
            if ((t1 > l1)) {
            } else {
                l9 = ((vader_array_t*) l4)->length;
                if ((l7 < l9)) {
                    t2 = ((void*) (intptr_t) l2.payload.i);
                    t3 = vader_host_system_posix_sys_ferror(t2);
                    if (t3 != INT32_C(0)) {
                        t0 = std_io_last_io_error(1959u);
                        l10 = vader_ref_box(t0);
                    } else {
                        l10 = vader_box_obj(0u, NULL);
                    }
                    t2 = ((void*) (intptr_t) l2.payload.i);
                    vader_host_system_posix_sys_fclose(t2);
                    if (!(l10.tag == 0u)) {
                        t0 = l10.payload.obj;
                        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
                    }
                    { vader_box_t __vret = vader_ref_box(l3); vader_gc_top = gc_frame.prev; return __vret; }
                }
                goto loop_18;
            }
        }
    }
    t2 = ((void*) (intptr_t) l2.payload.i);
    vader_host_system_posix_sys_fclose(t2);
    vader_struct_std_io_IOError_t* _a4_obj = (vader_struct_std_io_IOError_t*) vader_gc_alloc(sizeof(vader_struct_std_io_IOError_t));
    vader_obj_header_init(_a4_obj, 388u);
    _a4_obj->f_msg = 1587u;
    _a4_obj->f_kind = (uint8_t) (int32_t) INT32_C(0);
    _a4_obj->f_code = INT32_C(0);
    t0 = (void*) _a4_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = std_io_read_file_bytes(l0, l1);
    if (l2.tag == 388u) {
        t0 = l2.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l2.payload.obj;
    t1 = vader_host_std_core_bytes_to_string(t0);
    t2 = vader_box_string(169u, t1);
    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(11u, 1u, 1u, 175u);
    ((uint8_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (uint8_t) INT32_C(0);
    l1 = (void*) _a0_arr;
    l2 = vader_host_std_core_byte_len(l0);
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (size_t) l2);
    l1 = (void*) _a1_arr;
    l2 = vader_host_std_core_byte_len(l0);
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_16: {
            if ((l3 < l2)) {
                t0 = vader_host_std_core_byte_at(l0, l3);
                if (t0 == INT32_C(92)) {
                    l4 = (uint8_t) (int32_t) INT32_C(47);
                } else {
                    l4 = vader_host_std_core_byte_at(l0, l3);
                }
                vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l3 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                ((uint8_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3] = (uint8_t) (int32_t) (uint8_t) l4;
                t1 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t1;
                goto loop_16;
            } else {
            }
        }
    }
    t2 = vader_host_std_core_bytes_to_string(l1);
    { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = ((vader_array_t*) l0)->length;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    l2 = ((vader_array_t*) l0)->length;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_9: {
            if ((l3 < l2)) {
                if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l3, 175u);
                t1 = ((uint8_t) t0.payload.i);
                if (t1 == INT32_C(0)) {
                    l1 = l3;
                } else {
                    t2 = (l3 + INT64_C(1));
                    l3 = (size_t) (int64_t) t2;
                    goto loop_9;
                }
            } else {
            }
        }
    }
    vader_array_t* _a1_arr = vader_array_slice((vader_array_t*) l0, (size_t) INT64_C(0), (size_t) l1);
    t3 = (void*) _a1_arr;
    t4 = vader_host_std_core_bytes_to_string(t3);
    { vader_string_t __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t std_io_without_trailing_sep(vader_string_t l0) {
    void* l1 = NULL;
    size_t l2, l3, l4, l5, l7;
    bool l6;
    size_t t0;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    uint8_t t3;
    void* t4 = NULL;
    vader_string_t t5 = 0;
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[2] = { &l1, &t4 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_host_std_core_bytes(l0);
    l2 = (size_t) (int64_t) INT64_C(0);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    l3 = ((vader_array_t*) l1)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_11: {
            if ((l4 < l3)) {
                t0 = ((vader_array_t*) l1)->length;
                t1 = ((t0 - INT64_C(1)) - l4);
                l5 = (size_t) (int64_t) t1;
                if (l5 == INT64_C(0)) {
                    l6 = true;
                } else {
                    vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                    if ((size_t) l5 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) l5, 175u);
                    t3 = ((uint8_t) t2.payload.i);
                    l6 = t3 != INT32_C(47);
                }
                if (l6) {
                } else {
                    t1 = (l5 - INT64_C(1));
                    l7 = (size_t) (int64_t) t1;
                    vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
                    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                    if ((size_t) l7 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = vader_array_read_u8(_a2_slotarr, _a2_slotarr->offset + (size_t) l7, 175u);
                    t3 = ((uint8_t) t2.payload.i);
                    if (t3 == INT32_C(58)) {
                    } else {
                        t1 = (l2 + INT64_C(1));
                        l2 = (size_t) (int64_t) t1;
                        t1 = (l4 + INT64_C(1));
                        l4 = (size_t) (int64_t) t1;
                        goto loop_11;
                    }
                }
            } else {
            }
        }
    }
    if (l2 == INT64_C(0)) {
        { vader_string_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_array_t*) l1)->length;
    t1 = (t0 - l2);
    l2 = (size_t) (int64_t) t1;
    vader_array_t* _a3_arr = vader_array_slice((vader_array_t*) l1, (size_t) INT64_C(0), (size_t) l2);
    t4 = (void*) _a3_arr;
    t5 = vader_host_std_core_bytes_to_string(t4);
    { vader_string_t __vret = t5; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void std_io_write(int32_t l0, vader_string_t l1) {
    void* l2 = NULL;
    void* l6 = NULL;
    size_t l3, l4, l5, l7, l9;
    int32_t l8;
    int64_t t0;
    void** gc_raw_roots[2] = { &l2, &l6 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = vader_host_std_core_bytes(l1);
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_6: {
            l4 = ((vader_array_t*) l2)->length;
            if ((l3 >= l4)) {
            } else {
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
                goto loop_6;
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static int32_t std_io_write_bytes(int32_t l0, void* l1, size_t l2) {
    int32_t l3;
    ptrdiff_t t0;
    void** gc_raw_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(0)) {
        l3 = INT32_C(1);
    } else {
        l3 = INT32_C(2);
    }
    t0 = vader_host_system_posix_sys_write(l3, l1, l2);
    { int32_t __vret = ((int32_t) (ptrdiff_t) t0); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t std_io_write_file_bytes(vader_string_t l0, void* l1) {
    size_t l2, l3;
    vader_box_t l4 = vader_box_null();
    void* l5;
    void* l6 = NULL;
    int32_t l7, l8;
    uint8_t t0;
    void* t1 = NULL;
    int64_t t2;
    size_t t3;
    void* t4;
    vader_box_t t5 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l4, &t5 };
    void** gc_raw_roots[3] = { &l1, &l6, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = vader_host_std_core_byte_len(l0);
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_6: {
            if ((l3 < l2)) {
                t0 = vader_host_std_core_byte_at(l0, l3);
                if (t0 == INT32_C(0)) {
                    vader_struct_std_io_IOError_t* _a0_obj = (vader_struct_std_io_IOError_t*) vader_gc_alloc(sizeof(vader_struct_std_io_IOError_t));
                    vader_obj_header_init(_a0_obj, 388u);
                    _a0_obj->f_msg = 1937u;
                    _a0_obj->f_kind = (uint8_t) (int32_t) INT32_C(0);
                    _a0_obj->f_code = INT32_C(0);
                    t1 = (void*) _a0_obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                t2 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t2;
                goto loop_6;
            } else {
            }
        }
    }
    l4 = vader_host_system_posix_sys_fopen(l0, 2396u);
    if (l4.tag == 0u) {
        t1 = std_io_last_io_error(1916u);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t3 = ((vader_array_t*) l1)->length;
    if ((t3 > INT64_C(0))) {
        l2 = ((vader_array_t*) l1)->length;
        l5 = ((void*) (intptr_t) l4.payload.i);
        l2 = vader_host_system_posix_sys_fwrite(l1, (size_t) (int64_t) INT64_C(1), l2, l5);
        l3 = ((vader_array_t*) l1)->length;
        if (l2 != l3) {
            l6 = std_io_last_io_error(2008u);
            t4 = ((void*) (intptr_t) l4.payload.i);
            vader_host_system_posix_sys_fclose(t4);
            { vader_box_t __vret = vader_ref_box(l6); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t4 = ((void*) (intptr_t) l4.payload.i);
        l7 = vader_host_system_posix_sys_fclose(t4);
        l8 = INT32_C(0);
        if (l7 != l8) {
            t1 = std_io_last_io_error(1367u);
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t5 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t5; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t4 = ((void*) (intptr_t) l4.payload.i);
    l7 = vader_host_system_posix_sys_fclose(t4);
    l8 = INT32_C(0);
    if (l7 != l8) {
        t1 = std_io_last_io_error(1367u);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t5 = vader_box_obj(0u, NULL);
    { vader_box_t __vret = t5; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t std_io_write_file_string(vader_string_t l0, vader_string_t l1) {
    void* l2 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[1] = { &l2 };
    vader_string_t* gc_atom_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = vader_host_std_core_bytes(l1);
    t0 = std_io_write_file_bytes(l0, l2);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

