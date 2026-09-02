#include "bootstrap.split.h"

static vader_box_t std_io_read_file_bytes(vader_string_t l0);
static vader_string_t std_io_to_slash(vader_string_t l0);
static vader_string_t std_io_up_to_nul(void* l0);
static vader_string_t std_io_without_trailing_sep(vader_string_t l0);
static void std_io_write(int32_t l0, vader_string_t l1);
static int32_t std_io_write_bytes(int32_t l0, void* l1, size_t l2);
static vader_box_t std_io_write_file_bytes(vader_string_t l0, void* l1);

vader_string_t std_io_current_executable_location(void) {
    void* l0 = NULL;
    size_t l1;
    void* t0 = NULL;
    size_t t1;
    int64_t t2;
    ptrdiff_t t3;
    vader_string_t t4 = 0;
    vader_string_t t5 = 0;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[2] = { &t4, &t5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(11u, 1u, 1u, 170u);
    ((uint8_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (uint8_t) INT32_C(0);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) INT32_C(4096));
    l0 = (void*) _a1_arr;
    t1 = ((vader_array_t*) l0)->length;
    t2 = (t1 - INT64_C(1));
    l1 = (size_t) (int64_t) t2;
    t3 = vader_host_system_posix_sys_readlink(450u, l0, l1);
    if ((t3 <= INT64_C(0))) {
        { vader_gc_top = gc_frame.prev; return 414u; }
    }
    t4 = std_io_up_to_nul(l0);
    t5 = std_io_to_slash(t4);
    { vader_string_t __vret = t5; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_array_t* _a0_arr = vader_array_new(11u, 1u, 1u, 170u);
    ((uint8_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (uint8_t) INT32_C(0);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) INT32_C(4096));
    l0 = (void*) _a1_arr;
    l1 = ((vader_array_t*) l0)->length;
    t1 = vader_host_system_posix_sys_getcwd(l0, l1);
    if (t1.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return 414u; }
    }
    t2 = std_io_up_to_nul(l0);
    t3 = std_io_to_slash(t2);
    t2 = std_io_without_trailing_sep(t3);
    { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void std_io_eprintln__string(vader_string_t l0) {
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    std_io_write(INT32_C(1), l0);
    std_io_write(INT32_C(1), 1u);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
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
    void* l1 = NULL;
    int32_t t0;
    uint32_t t1;
    void** gc_raw_roots[1] = { &l1 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_struct_system_linux_LinuxStat_t* _a0_obj = (vader_struct_system_linux_LinuxStat_t*) vader_gc_alloc(sizeof(vader_struct_system_linux_LinuxStat_t));
    vader_obj_header_init(_a0_obj, 406u);
    _a0_obj->f_st_dev = (uint64_t) (int64_t) INT64_C(0);
    _a0_obj->f_st_ino = (uint64_t) (int64_t) INT64_C(0);
    _a0_obj->f_st_nlink = (uint64_t) (int64_t) INT64_C(0);
    _a0_obj->f_st_mode = (uint32_t) (int32_t) INT32_C(0);
    l1 = (void*) _a0_obj;
    t0 = vader_host_system_linux_sys_stat_linux(l0, l1);
    if (t0 != INT32_C(0)) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    t1 = ((vader_struct_system_linux_LinuxStat_t*) l1)->f_st_mode;
    { bool __vret = (t1 & INT32_C(61440)) == INT32_C(16384); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t std_io_read_file_bytes(vader_string_t l0) {
    vader_box_t l1 = vader_box_null();
    void* l2 = NULL;
    void* l3 = NULL;
    void* l8 = NULL;
    size_t l4, l5, l7, l9;
    void* l6;
    void* t0 = NULL;
    void* t1;
    int64_t t2;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[4] = { &l2, &l3, &l8, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_host_system_posix_sys_fopen(l0, 1921u);
    if (l1.tag == 0u) {
        vader_struct_std_io_IOError_t* _a0_obj = (vader_struct_std_io_IOError_t*) vader_gc_alloc(sizeof(vader_struct_std_io_IOError_t));
        vader_obj_header_init(_a0_obj, 401u);
        _a0_obj->f_msg = 1563u;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a1_arr = vader_array_new(11u, 0u, 1u, 170u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(11u, 1u, 1u, 170u);
    ((uint8_t*) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = (uint8_t) INT32_C(0);
    t0 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) t0, (size_t) INT64_C(65536));
    l3 = (void*) _a3_arr;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_20: {
            if ((l4 < INT64_C(65536))) {
                l5 = ((vader_array_t*) l3)->length;
                l6 = ((void*) (intptr_t) l1.payload.i);
                l7 = vader_host_system_posix_sys_fread(l3, (size_t) (int64_t) INT64_C(1), l5, l6);
                if ((l7 > INT64_C(0))) {
                    vader_array_t* _a4_arr = vader_array_slice((vader_array_t*) l3, (size_t) INT64_C(0), (size_t) l7);
                    l8 = (void*) _a4_arr;
                    vader_array_push_all((vader_array_t*) l2, (vader_array_t*) l8);
                } else {
                }
                l9 = ((vader_array_t*) l3)->length;
                if ((l7 < l9)) {
                    t1 = ((void*) (intptr_t) l1.payload.i);
                    vader_host_system_posix_sys_fclose(t1);
                    { vader_box_t __vret = vader_ref_box(l2); vader_gc_top = gc_frame.prev; return __vret; }
                }
                t2 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                goto loop_20;
            } else {
            }
        }
    }
    t1 = ((void*) (intptr_t) l1.payload.i);
    vader_host_system_posix_sys_fclose(t1);
    vader_struct_std_io_IOError_t* _a5_obj = (vader_struct_std_io_IOError_t*) vader_gc_alloc(sizeof(vader_struct_std_io_IOError_t));
    vader_obj_header_init(_a5_obj, 401u);
    _a5_obj->f_msg = 1564u;
    t0 = (void*) _a5_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t std_io_read_file_string(vader_string_t l0) {
    vader_box_t l1 = vader_box_null();
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t2 };
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = std_io_read_file_bytes(l0);
    if (l1.tag == 401u) {
        t0 = l1.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l1.payload.obj;
    t1 = vader_host_std_core_bytes_to_string(t0);
    t2 = vader_box_string(164u, t1);
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
    vader_array_t* _a0_arr = vader_array_new(11u, 1u, 1u, 170u);
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
                t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l3, 170u);
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
                    t2 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) l5, 170u);
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
                    t2 = vader_array_read_u8(_a2_slotarr, _a2_slotarr->offset + (size_t) l7, 170u);
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

static void std_io_write(int32_t l0, vader_string_t l1) {
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
    int32_t l6, l7;
    uint8_t t0;
    void* t1 = NULL;
    int64_t t2;
    size_t t3;
    void* t4;
    vader_box_t t5 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l4, &t5 };
    void** gc_raw_roots[2] = { &l1, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = vader_host_std_core_byte_len(l0);
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_6: {
            if ((l3 < l2)) {
                t0 = vader_host_std_core_byte_at(l0, l3);
                if (t0 == INT32_C(0)) {
                    vader_struct_std_io_IOError_t* _a0_obj = (vader_struct_std_io_IOError_t*) vader_gc_alloc(sizeof(vader_struct_std_io_IOError_t));
                    vader_obj_header_init(_a0_obj, 401u);
                    _a0_obj->f_msg = 1904u;
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
    l4 = vader_host_system_posix_sys_fopen(l0, 2388u);
    if (l4.tag == 0u) {
        vader_struct_std_io_IOError_t* _a1_obj = (vader_struct_std_io_IOError_t*) vader_gc_alloc(sizeof(vader_struct_std_io_IOError_t));
        vader_obj_header_init(_a1_obj, 401u);
        _a1_obj->f_msg = 1883u;
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t3 = ((vader_array_t*) l1)->length;
    if ((t3 > INT64_C(0))) {
        l2 = ((vader_array_t*) l1)->length;
        l5 = ((void*) (intptr_t) l4.payload.i);
        l2 = vader_host_system_posix_sys_fwrite(l1, (size_t) (int64_t) INT64_C(1), l2, l5);
        l3 = ((vader_array_t*) l1)->length;
        if (l2 != l3) {
            t4 = ((void*) (intptr_t) l4.payload.i);
            vader_host_system_posix_sys_fclose(t4);
            vader_struct_std_io_IOError_t* _a2_obj = (vader_struct_std_io_IOError_t*) vader_gc_alloc(sizeof(vader_struct_std_io_IOError_t));
            vader_obj_header_init(_a2_obj, 401u);
            _a2_obj->f_msg = 1976u;
            t1 = (void*) _a2_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t4 = ((void*) (intptr_t) l4.payload.i);
        l6 = vader_host_system_posix_sys_fclose(t4);
        l7 = INT32_C(0);
        if (l6 != l7) {
            vader_struct_std_io_IOError_t* _a3_obj = (vader_struct_std_io_IOError_t*) vader_gc_alloc(sizeof(vader_struct_std_io_IOError_t));
            vader_obj_header_init(_a3_obj, 401u);
            _a3_obj->f_msg = 1347u;
            t1 = (void*) _a3_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t5 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t5; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t4 = ((void*) (intptr_t) l4.payload.i);
    l6 = vader_host_system_posix_sys_fclose(t4);
    l7 = INT32_C(0);
    if (l6 != l7) {
        vader_struct_std_io_IOError_t* _a4_obj = (vader_struct_std_io_IOError_t*) vader_gc_alloc(sizeof(vader_struct_std_io_IOError_t));
        vader_obj_header_init(_a4_obj, 401u);
        _a4_obj->f_msg = 1347u;
        t1 = (void*) _a4_obj;
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

