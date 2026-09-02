#include "bootstrap.split.h"

static vader_string_t std_io_from_wide(void* l0, int32_t l1);
static vader_box_t std_io_read_file_bytes(vader_string_t l0);
static vader_string_t std_io_to_slash(vader_string_t l0);
static void* std_io_to_wide(vader_string_t l0);
static vader_string_t std_io_without_trailing_sep(vader_string_t l0);
static void std_io_write(int32_t l0, vader_string_t l1);
static int32_t std_io_write_bytes(int32_t l0, void* l1, size_t l2);
static vader_box_t std_io_write_file_bytes(vader_string_t l0, void* l1);

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
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(12u, 1u, 2u, 171u);
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
    if (l2) {
        { vader_gc_top = gc_frame.prev; return 414u; }
    }
    l5 = ((int32_t) (uint32_t) l1);
    t4 = std_io_from_wide(l0, l5);
    t5 = std_io_to_slash(t4);
    { vader_string_t __vret = t5; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(12u, 1u, 2u, 171u);
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
    if (l2) {
        { vader_gc_top = gc_frame.prev; return 414u; }
    }
    l5 = ((int32_t) (uint32_t) l1);
    t3 = std_io_from_wide(l0, l5);
    t4 = std_io_to_slash(t3);
    t3 = std_io_without_trailing_sep(t4);
    { vader_string_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
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
    void* t0 = NULL;
    uint32_t t1;
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = std_io_to_wide(l0);
    t1 = vader_host_system_windows_get_file_attributes(t0);
    { bool __vret = t1 != INT32_C(-1); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(11u, 0u, 1u, 170u);
    l2 = (void*) _a0_arr;
    l3 = vader_host_system_windows_wide_char_to_multi_byte((uint32_t) (int32_t) INT32_C(65001), (uint32_t) (int32_t) INT32_C(0), l0, l1, l2, INT32_C(0), vader_box_obj(0u, NULL), vader_box_obj(0u, NULL));
    if ((l3 <= INT32_C(0))) {
        { vader_gc_top = gc_frame.prev; return 0u; }
    }
    vader_array_t* _a1_arr = vader_array_new(11u, 1u, 1u, 170u);
    ((uint8_t*) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = (uint8_t) INT32_C(0);
    l2 = (void*) _a1_arr;
    t0 = ((int64_t) (int32_t) l3);
    l4 = (size_t) (int64_t) t0;
    vader_array_t* _a2_arr = vader_array_repeat((vader_array_t*) l2, (size_t) l4);
    l2 = (void*) _a2_arr;
    t1 = vader_host_system_windows_wide_char_to_multi_byte((uint32_t) (int32_t) INT32_C(65001), (uint32_t) (int32_t) INT32_C(0), l0, l1, l2, l3, vader_box_obj(0u, NULL), vader_box_obj(0u, NULL));
    if ((t1 <= INT32_C(0))) {
        { vader_gc_top = gc_frame.prev; return 0u; }
    }
    t2 = vader_host_std_core_bytes_to_string(l2);
    { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

bool std_io_is_dir(vader_string_t l0) {
    uint32_t l1;
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = std_io_to_wide(l0);
    l1 = vader_host_system_windows_get_file_attributes(t0);
    if (l1 == INT32_C(-1)) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    { bool __vret = (l1 & INT32_C(16)) != INT32_C(0); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t std_io_read_file_bytes(vader_string_t l0) {
    void* l1;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l8 = NULL;
    size_t l5, l7, l9;
    uint32_t l6;
    void* t0 = NULL;
    ptrdiff_t t1;
    size_t t2;
    int32_t t3;
    bool t4;
    int64_t t5;
    void** gc_raw_roots[5] = { &l2, &l3, &l4, &l8, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = std_io_to_wide(l0);
    l1 = vader_host_system_windows_create_file_w(t0, (uint32_t) (int32_t) INT32_MIN, (uint32_t) (int32_t) INT32_C(1), vader_box_obj(0u, NULL), (uint32_t) (int32_t) INT32_C(3), (uint32_t) (int32_t) INT32_C(128), vader_box_obj(0u, NULL));
    t1 = (ptrdiff_t) (void*) l1;
    if (t1 == INT64_C(-1)) {
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
    vader_array_t* _a4_arr = vader_array_new(13u, 1u, 3u, 172u);
    ((int32_t*) _a4_arr->buf->slots)[_a4_arr->offset + 0u] = (int32_t) INT32_C(0);
    l4 = (void*) _a4_arr;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_31: {
            if ((l5 < INT64_C(65536))) {
                t2 = ((vader_array_t*) l3)->length;
                t3 = ((int32_t) (size_t) t2);
                l6 = (uint32_t) (int32_t) t3;
                t4 = vader_host_system_windows_read_file(l1, l3, l6, l4, vader_box_obj(0u, NULL));
                if (!(t4)) {
                    vader_host_system_windows_close_handle(l1);
                    vader_struct_std_io_IOError_t* _a5_obj = (vader_struct_std_io_IOError_t*) vader_gc_alloc(sizeof(vader_struct_std_io_IOError_t));
                    vader_obj_header_init(_a5_obj, 401u);
                    _a5_obj->f_msg = 1925u;
                    t0 = (void*) _a5_obj;
                    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
                }
                vader_array_t* _a6_slotarr = ((vader_array_t*) l4);
                if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                if ((size_t) INT32_C(0) >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                t3 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) INT32_C(0)];
                t5 = ((int64_t) (uint32_t) t3);
                l7 = (size_t) (int64_t) t5;
                if ((l7 > INT64_C(0))) {
                    vader_array_t* _a7_arr = vader_array_slice((vader_array_t*) l3, (size_t) INT64_C(0), (size_t) l7);
                    l8 = (void*) _a7_arr;
                    vader_array_push_all((vader_array_t*) l2, (vader_array_t*) l8);
                } else {
                }
                l9 = ((vader_array_t*) l3)->length;
                if ((l7 < l9)) {
                    vader_host_system_windows_close_handle(l1);
                    { vader_box_t __vret = vader_ref_box(l2); vader_gc_top = gc_frame.prev; return __vret; }
                }
                t5 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t5;
                goto loop_31;
            } else {
            }
        }
    }
    vader_host_system_windows_close_handle(l1);
    vader_struct_std_io_IOError_t* _a8_obj = (vader_struct_std_io_IOError_t*) vader_gc_alloc(sizeof(vader_struct_std_io_IOError_t));
    vader_obj_header_init(_a8_obj, 401u);
    _a8_obj->f_msg = 1564u;
    t0 = (void*) _a8_obj;
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

static void* std_io_to_wide(vader_string_t l0) {
    void* l1 = NULL;
    int32_t l2, l4;
    size_t l3;
    void* t0 = NULL;
    int64_t t1;
    int32_t t2;
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(12u, 0u, 2u, 171u);
    l1 = (void*) _a0_arr;
    l2 = -(INT32_C(1));
    l2 = vader_host_system_windows_multi_byte_to_wide_char((uint32_t) (int32_t) INT32_C(65001), (uint32_t) (int32_t) INT32_C(0), l0, l2, l1, INT32_C(0));
    if ((l2 <= INT32_C(0))) {
        vader_array_t* _a1_arr = vader_array_new(12u, 0u, 2u, 171u);
        t0 = (void*) _a1_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a2_arr = vader_array_new(12u, 1u, 2u, 171u);
    ((uint16_t*) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = (uint16_t) INT32_C(0);
    l1 = (void*) _a2_arr;
    t1 = ((int64_t) (int32_t) l2);
    l3 = (size_t) (int64_t) t1;
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) l1, (size_t) l3);
    l1 = (void*) _a3_arr;
    l4 = -(INT32_C(1));
    t2 = vader_host_system_windows_multi_byte_to_wide_char((uint32_t) (int32_t) INT32_C(65001), (uint32_t) (int32_t) INT32_C(0), l0, l4, l1, l2);
    if ((t2 <= INT32_C(0))) {
        vader_array_t* _a4_arr = vader_array_new(12u, 0u, 2u, 171u);
        t0 = (void*) _a4_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
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
    uint32_t l3;
    void* l4;
    int32_t t0;
    bool t1;
    void** gc_raw_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(0)) {
        l3 = (uint32_t) (int32_t) INT32_C(-11);
    } else {
        l3 = (uint32_t) (int32_t) INT32_C(-12);
    }
    l4 = vader_host_system_windows_get_std_handle(l3);
    t0 = ((int32_t) (size_t) l2);
    l3 = (uint32_t) (int32_t) t0;
    t1 = vader_host_system_windows_write_file(l4, l1, l3, (uint32_t) (int32_t) INT32_C(0), vader_box_obj(0u, NULL));
    if (t1) {
        { int32_t __vret = ((int32_t) (size_t) l2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { int32_t __vret = -(INT32_C(1)); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t std_io_write_file_bytes(vader_string_t l0, void* l1) {
    size_t l2, l3;
    void* l4;
    uint32_t l5;
    uint8_t t0;
    void* t1 = NULL;
    int64_t t2;
    ptrdiff_t t3;
    size_t t4;
    int32_t t5;
    bool t6;
    vader_box_t t7 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t7 };
    void** gc_raw_roots[2] = { &l1, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
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
    t1 = std_io_to_wide(l0);
    l4 = vader_host_system_windows_create_file_w(t1, (uint32_t) (int32_t) INT32_C(1073741824), (uint32_t) (int32_t) INT32_C(0), vader_box_obj(0u, NULL), (uint32_t) (int32_t) INT32_C(2), (uint32_t) (int32_t) INT32_C(128), vader_box_obj(0u, NULL));
    t3 = (ptrdiff_t) (void*) l4;
    if (t3 == INT64_C(-1)) {
        vader_struct_std_io_IOError_t* _a1_obj = (vader_struct_std_io_IOError_t*) vader_gc_alloc(sizeof(vader_struct_std_io_IOError_t));
        vader_obj_header_init(_a1_obj, 401u);
        _a1_obj->f_msg = 1883u;
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t4 = ((vader_array_t*) l1)->length;
    if ((t4 > INT64_C(0))) {
        t4 = ((vader_array_t*) l1)->length;
        t5 = ((int32_t) (size_t) t4);
        l5 = (uint32_t) (int32_t) t5;
        t6 = vader_host_system_windows_write_file(l4, l1, l5, (uint32_t) (int32_t) INT32_C(0), vader_box_obj(0u, NULL));
        if (!(t6)) {
            vader_host_system_windows_close_handle(l4);
            vader_struct_std_io_IOError_t* _a2_obj = (vader_struct_std_io_IOError_t*) vader_gc_alloc(sizeof(vader_struct_std_io_IOError_t));
            vader_obj_header_init(_a2_obj, 401u);
            _a2_obj->f_msg = 1976u;
            t1 = (void*) _a2_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t6 = vader_host_system_windows_close_handle(l4);
        if (!(t6)) {
            vader_struct_std_io_IOError_t* _a3_obj = (vader_struct_std_io_IOError_t*) vader_gc_alloc(sizeof(vader_struct_std_io_IOError_t));
            vader_obj_header_init(_a3_obj, 401u);
            _a3_obj->f_msg = 1347u;
            t1 = (void*) _a3_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t7 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t7; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t6 = vader_host_system_windows_close_handle(l4);
    if (!(t6)) {
        vader_struct_std_io_IOError_t* _a4_obj = (vader_struct_std_io_IOError_t*) vader_gc_alloc(sizeof(vader_struct_std_io_IOError_t));
        vader_obj_header_init(_a4_obj, 401u);
        _a4_obj->f_msg = 1347u;
        t1 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t7 = vader_box_obj(0u, NULL);
    { vader_box_t __vret = t7; vader_gc_top = gc_frame.prev; return __vret; }
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

