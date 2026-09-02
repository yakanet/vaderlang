#include "bootstrap.split.h"

static ptrdiff_t std_string_byte_find(vader_string_t l0, vader_string_t l1, size_t l2);
static bool std_string_bytes_match_at(void* l0, size_t l1, void* l2, size_t l3);
static bool std_string_is_utf8_continuation(uint8_t l0);
static uint8_t std_string_to_lower_byte(uint8_t l0);
static uint32_t std_string_to_lower_cp(uint32_t l0);

vader_box_t std_string_StringChars_Iterator_next(void* l0) {
    size_t l1, l2;
    void* l3 = NULL;
    uint32_t l4;
    vader_box_t t0 = vader_box_null();
    size_t t1;
    int64_t t2;
    void* t3 = NULL;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[3] = { &l0, &l3, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_std_string_StringChars_t*) l0)->f_cursor;
    l2 = ((vader_struct_std_string_StringChars_t*) l0)->f_length;
    if ((l1 >= l2)) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((vader_struct_std_string_StringChars_t*) l0)->f_bytes;
    l1 = ((vader_struct_std_string_StringChars_t*) l0)->f_cursor;
    l3 = std_string_utf8_decode_len(l3, l1);
    l4 = ((vader_struct___Tuple_256_t*) l3)->f__0;
    l1 = ((vader_struct___Tuple_256_t*) l3)->f__1;
    t1 = ((vader_struct_std_string_StringChars_t*) l0)->f_cursor;
    t2 = (t1 + l1);
    l1 = (size_t) (int64_t) t2;
    ((vader_struct_std_string_StringChars_t*) l0)->f_cursor = l1;
    VADER_WRITE_BARRIER((vader_struct_std_string_StringChars_t*) l0);
    vader_struct_std_core_Yield__char_t* _a0_obj = (vader_struct_std_core_Yield__char_t*) vader_gc_alloc(sizeof(vader_struct_std_core_Yield__char_t));
    vader_obj_header_init(_a0_obj, 400u);
    _a0_obj->f_value = l4;
    t3 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

bool std_string_byte_contains(vader_string_t l0, vader_string_t l1) {
    ptrdiff_t t0;
    vader_string_t* gc_atom_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = std_string_byte_find(l0, l1, (size_t) (int64_t) INT64_C(0));
    { bool __vret = (t0 >= INT64_C(0)); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static ptrdiff_t std_string_byte_find(vader_string_t l0, vader_string_t l1, size_t l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    size_t l5, l6, l7;
    int64_t t0;
    bool t1;
    void** gc_raw_roots[2] = { &l3, &l4 };
    vader_string_t* gc_atom_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = vader_host_std_core_bytes(l0);
    l4 = vader_host_std_core_bytes(l1);
    l5 = ((vader_array_t*) l3)->length;
    l6 = ((vader_array_t*) l4)->length;
    if (l6 == INT64_C(0)) {
        { ptrdiff_t __vret = (ptrdiff_t) (int64_t) ((int64_t) (size_t) l2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if ((l6 > l5)) {
        { ptrdiff_t __vret = (ptrdiff_t) (int64_t) -(INT64_C(1)); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = (l5 - l6);
    l5 = (size_t) (int64_t) t0;
    l7 = l2;
    {
        loop_34: {
            if ((l7 <= l5)) {
                t1 = std_string_bytes_match_at(l3, l7, l4, l6);
                if (t1) {
                    { ptrdiff_t __vret = (ptrdiff_t) (int64_t) ((int64_t) (size_t) l7); vader_gc_top = gc_frame.prev; return __vret; }
                }
                t0 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t0;
                goto loop_34;
            } else {
            }
        }
    }
    { ptrdiff_t __vret = (ptrdiff_t) (int64_t) -(INT64_C(1)); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static bool std_string_bytes_match_at(void* l0, size_t l1, void* l2, size_t l3) {
    size_t l4, l5;
    uint8_t l6, l7;
    int64_t t0;
    vader_box_t t1;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_3: {
            if ((l4 < l3)) {
                t0 = (l1 + l4);
                l5 = (size_t) (int64_t) t0;
                vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l5 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l5, 170u);
                l6 = ((uint8_t) t1.payload.i);
                vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) l4, 170u);
                l7 = ((uint8_t) t1.payload.i);
                if (l6 != l7) {
                    return false;
                }
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_3;
            } else {
            }
        }
    }
    return true;
}

void* std_string_chars(vader_string_t l0) {
    void* l1 = NULL;
    size_t l2;
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_host_std_core_bytes(l0);
    l2 = ((vader_array_t*) l1)->length;
    vader_struct_std_string_StringChars_t* _a0_obj = (vader_struct_std_string_StringChars_t*) vader_gc_alloc(sizeof(vader_struct_std_string_StringChars_t));
    vader_obj_header_init(_a0_obj, 403u);
    _a0_obj->f_bytes = l1;
    _a0_obj->f_cursor = (size_t) (int64_t) INT64_C(0);
    _a0_obj->f_length = l2;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

size_t std_string_codepoint_byte_len(uint32_t l0) {
    uint32_t l1;
    int32_t t0;
    t0 = ((int32_t) (uint32_t) l0);
    l1 = (uint32_t) (int32_t) t0;
    if ((l1 < INT32_C(128))) {
        return (size_t) (int64_t) INT64_C(1);
    }
    if ((l1 < INT32_C(2048))) {
        return (size_t) (int64_t) INT64_C(2);
    }
    if ((l1 < INT32_C(65536))) {
        return (size_t) (int64_t) INT64_C(3);
    }
    return (size_t) (int64_t) INT64_C(4);
}

uint32_t std_string_combine_surrogates(uint32_t l0, uint32_t l1) {
    uint32_t l2, l3;
    int32_t t0;
    t0 = ((((int32_t) (uint32_t) l0) - INT32_C(55296)) << INT32_C(10));
    l2 = (uint32_t) (int32_t) t0;
    t0 = (INT32_C(65536) + l2);
    l2 = (uint32_t) (int32_t) t0;
    t0 = (((int32_t) (uint32_t) l1) - INT32_C(56320));
    l3 = (uint32_t) (int32_t) t0;
    return ((uint32_t) (int32_t) (l2 + l3));
}

bool std_string_compare_ascending(vader_string_t l0, vader_string_t l1) {
    size_t l2, l3, l4, l5;
    uint8_t l6, l7;
    int64_t t0;
    vader_string_t* gc_atom_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = vader_host_std_core_byte_len(l0);
    l3 = vader_host_std_core_byte_len(l1);
    l4 = std_math_min_2(l2, l3);
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_13: {
            if ((l5 < l4)) {
                l6 = vader_host_std_core_byte_at(l0, l5);
                l7 = vader_host_std_core_byte_at(l1, l5);
                if ((l6 < l7)) {
                    { vader_gc_top = gc_frame.prev; return true; }
                }
                if ((l6 > l7)) {
                    { vader_gc_top = gc_frame.prev; return false; }
                }
                t0 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t0;
                goto loop_13;
            } else {
            }
        }
    }
    { bool __vret = (l2 < l3); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

bool std_string_compare_ascending_ci(vader_string_t l0, vader_string_t l1) {
    size_t l2, l3, l4, l5;
    uint8_t l6, l7;
    uint8_t t0;
    int64_t t1;
    vader_string_t* gc_atom_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = vader_host_std_core_byte_len(l0);
    l3 = vader_host_std_core_byte_len(l1);
    l4 = std_math_min_2(l2, l3);
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_13: {
            if ((l5 < l4)) {
                t0 = vader_host_std_core_byte_at(l0, l5);
                l6 = std_string_to_lower_byte(t0);
                t0 = vader_host_std_core_byte_at(l1, l5);
                l7 = std_string_to_lower_byte(t0);
                if ((l6 < l7)) {
                    { vader_gc_top = gc_frame.prev; return true; }
                }
                if ((l6 > l7)) {
                    { vader_gc_top = gc_frame.prev; return false; }
                }
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_13;
            } else {
            }
        }
    }
    if (l2 != l3) {
        { bool __vret = (l2 < l3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = (size_t) (int64_t) INT64_C(0);
    {
        loop_61: {
            if ((l2 < l4)) {
                l6 = vader_host_std_core_byte_at(l0, l2);
                l7 = vader_host_std_core_byte_at(l1, l2);
                if ((l6 < l7)) {
                    { vader_gc_top = gc_frame.prev; return true; }
                }
                if ((l6 > l7)) {
                    { vader_gc_top = gc_frame.prev; return false; }
                }
                t1 = (l2 + INT64_C(1));
                l2 = (size_t) (int64_t) t1;
                goto loop_61;
            } else {
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return false; }
    vader_gc_top = gc_frame.prev;
}

bool std_string_ends_with(vader_string_t l0, vader_string_t l1) {
    size_t l2, l3, l4, l5;
    uint8_t l6, l7;
    int64_t t0;
    vader_string_t* gc_atom_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = vader_host_std_core_byte_len(l1);
    l3 = vader_host_std_core_byte_len(l0);
    if ((l2 > l3)) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    t0 = (l3 - l2);
    l3 = (size_t) (int64_t) t0;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_19: {
            if ((l4 < l2)) {
                t0 = (l3 + l4);
                l5 = (size_t) (int64_t) t0;
                l6 = vader_host_std_core_byte_at(l0, l5);
                l7 = vader_host_std_core_byte_at(l1, l4);
                if (l6 != l7) {
                    { vader_gc_top = gc_frame.prev; return false; }
                }
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_19;
            } else {
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return true; }
    vader_gc_top = gc_frame.prev;
}

ptrdiff_t std_string_index_of(vader_string_t l0, uint32_t l1, size_t l2) {
    void* l3 = NULL;
    void* l6 = NULL;
    size_t l4, l5, l8;
    uint32_t l7;
    int64_t t0;
    void** gc_raw_roots[2] = { &l3, &l6 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = vader_host_std_core_bytes(l0);
    l4 = ((vader_array_t*) l3)->length;
    l5 = l2;
    {
        loop_8: {
            if ((l5 < l4)) {
                l6 = std_string_utf8_decode_len(l3, l5);
                l7 = ((vader_struct___Tuple_256_t*) l6)->f__0;
                l8 = ((vader_struct___Tuple_256_t*) l6)->f__1;
                if (l7 == l1) {
                    { ptrdiff_t __vret = (ptrdiff_t) (int64_t) ((int64_t) (size_t) l5); vader_gc_top = gc_frame.prev; return __vret; }
                }
                t0 = (l5 + l8);
                l5 = (size_t) (int64_t) t0;
                goto loop_8;
            } else {
            }
        }
    }
    { ptrdiff_t __vret = (ptrdiff_t) (int64_t) -(INT64_C(1)); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

bool std_string_is_empty(vader_string_t l0) {
    size_t t0;
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = vader_host_std_core_byte_len(l0);
    { bool __vret = t0 == INT64_C(0); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

bool std_string_is_high_surrogate(uint32_t l0) {
    uint32_t l1;
    bool l2;
    int32_t t0;
    t0 = ((int32_t) (uint32_t) l0);
    l1 = (uint32_t) (int32_t) t0;
    if ((l1 >= INT32_C(55296))) {
        l2 = (l1 <= INT32_C(56319));
    } else {
        l2 = false;
    }
    return l2;
}

bool std_string_is_low_surrogate(uint32_t l0) {
    uint32_t l1;
    bool l2;
    int32_t t0;
    t0 = ((int32_t) (uint32_t) l0);
    l1 = (uint32_t) (int32_t) t0;
    if ((l1 >= INT32_C(56320))) {
        l2 = (l1 <= INT32_C(57343));
    } else {
        l2 = false;
    }
    return l2;
}

bool std_string_is_surrogate(uint32_t l0) {
    uint32_t l1;
    bool l2;
    int32_t t0;
    t0 = ((int32_t) (uint32_t) l0);
    l1 = (uint32_t) (int32_t) t0;
    if ((l1 >= INT32_C(55296))) {
        l2 = (l1 <= INT32_C(57343));
    } else {
        l2 = false;
    }
    return l2;
}

static bool std_string_is_utf8_continuation(uint8_t l0) {
    bool l1;
    if ((l0 >= INT32_C(128))) {
        l1 = (l0 < INT32_C(192));
    } else {
        l1 = false;
    }
    return l1;
}

vader_string_t std_string_join(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    size_t l3, l4;
    vader_string_t l5 = 0;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l5, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 164u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 404u);
    _a1_obj->f_parts = t0;
    l2 = (void*) _a1_obj;
    l3 = ((vader_array_t*) l0)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_9: {
            if ((l4 < l3)) {
                if ((l4 > INT64_C(0))) {
                    std_string_builder_append(l2, l1);
                } else {
                }
                vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l4 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l4];
                l5 = t1.payload.s;
                std_string_builder_append(l2, l5);
                t2 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                goto loop_9;
            } else {
            }
        }
    }
    t3 = std_string_builder_StringBuilder_Display_to_string(l2);
    { vader_string_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

ptrdiff_t std_string_last_index_of(vader_string_t l0, uint32_t l1, ptrdiff_t l2) {
    void* l3 = NULL;
    void* l7 = NULL;
    size_t l4, l6, l9;
    ptrdiff_t l5;
    uint32_t l8;
    bool l10;
    int64_t t0;
    void** gc_raw_roots[2] = { &l3, &l7 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = vader_host_std_core_bytes(l0);
    l4 = ((vader_array_t*) l3)->length;
    t0 = -(INT64_C(1));
    l5 = (ptrdiff_t) (int64_t) t0;
    l6 = (size_t) (int64_t) INT64_C(0);
    {
        loop_11: {
            if ((l6 < l4)) {
                l7 = std_string_utf8_decode_len(l3, l6);
                l8 = ((vader_struct___Tuple_256_t*) l7)->f__0;
                l9 = ((vader_struct___Tuple_256_t*) l7)->f__1;
                if ((((int64_t) (size_t) l6) >= l2)) {
                    l10 = l8 == l1;
                } else {
                    l10 = false;
                }
                if (l10) {
                    t0 = ((int64_t) (size_t) l6);
                    l5 = (ptrdiff_t) (int64_t) t0;
                } else {
                }
                t0 = (l6 + l9);
                l6 = (size_t) (int64_t) t0;
                goto loop_11;
            } else {
            }
        }
    }
    { ptrdiff_t __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_string_t std_string_pad_start(vader_string_t l0, size_t l1, uint32_t l2) {
    size_t l3;
    void* l4 = NULL;
    void* t0 = NULL;
    int64_t t1;
    vader_string_t t2 = 0;
    void** gc_raw_roots[2] = { &l4, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = vader_host_std_core_byte_len(l0);
    if ((l3 >= l1)) {
        { vader_string_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 164u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 404u);
    _a1_obj->f_parts = t0;
    l4 = (void*) _a1_obj;
    {
        loop_13: {
            if ((l3 < l1)) {
                std_string_builder_append_char(l4, l2);
                t1 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t1;
                goto loop_13;
            } else {
            }
        }
    }
    std_string_builder_append(l4, l0);
    t2 = std_string_builder_StringBuilder_Display_to_string(l4);
    { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t std_string_parse_float(vader_string_t l0) {
    vader_box_t l1 = vader_box_null();
    vader_string_t t0 = 0;
    void* t1 = NULL;
    double t2;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t3 };
    void** gc_raw_roots[1] = { &t1 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = std_core_parse_f64(l0);
    if (l1.tag == 0u) {
        t0 = concat_3(1902u, l0, 920u);
        vader_struct_std_string_ParseError_t* _a0_obj = (vader_struct_std_string_ParseError_t*) vader_gc_alloc(sizeof(vader_struct_std_string_ParseError_t));
        vader_obj_header_init(_a0_obj, 402u);
        _a0_obj->f_msg = t0;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = ((double) l1.payload.f);
    t3 = vader_box_f64(161u, t2);
    { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_string_t std_string_replace_chars_where(vader_string_t l0, void* l1, vader_string_t l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    vader_box_t l5 = vader_box_null();
    uint32_t l6;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    bool t2;
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[2] = { &l5, &t1 };
    void** gc_raw_roots[4] = { &l1, &l3, &l4, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l2, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 164u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 404u);
    _a1_obj->f_parts = t0;
    l3 = (void*) _a1_obj;
    l4 = std_string_chars(l0);
    {
        loop_7: {
            l5 = std_string_StringChars_Iterator_next(l4);
            if (l5.tag == 0u) {
            } else {
                t0 = l5.payload.obj;
                l6 = ((vader_struct_std_core_Yield__char_t*) t0)->f_value;
                vader_fn_t* _a2_fnobj = (vader_fn_t*) l1;
                t1 = ((vader_fn_erased_sig_1_t) _a2_fnobj->code)(_a2_fnobj->env, vader_box_i32(163u, (int32_t) l6));
                t2 = t1.payload.b;
                if (t2) {
                    std_string_builder_append(l3, l2);
                } else {
                    std_string_builder_append_char(l3, l6);
                }
                goto loop_7;
            }
        }
    }
    t3 = std_string_builder_StringBuilder_Display_to_string(l3);
    { vader_string_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* std_string_split(vader_string_t l0, vader_string_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    size_t l4, l5, l6, l7;
    vader_string_t l8 = 0;
    ptrdiff_t l9;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[3] = { &l2, &l3, &t1 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l1, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 164u);
    l2 = (void*) _a0_arr;
    l3 = vader_host_std_core_bytes(l0);
    l4 = ((vader_array_t*) l3)->length;
    l5 = vader_host_std_core_byte_len(l1);
    if (l5 == INT64_C(0)) {
        l6 = (size_t) (int64_t) INT64_C(0);
        {
            loop_16: {
                if ((l6 < l4)) {
                    t0 = (l6 + INT64_C(1));
                    l7 = (size_t) (int64_t) t0;
                    vader_array_t* _a1_arr = vader_array_slice((vader_array_t*) l3, (size_t) l6, (size_t) l7);
                    t1 = (void*) _a1_arr;
                    l8 = vader_host_std_core_bytes_to_string(t1);
                    vader_array_push((vader_array_t*) l2, vader_box_string(164u, l8));
                    t0 = (l6 + INT64_C(1));
                    l6 = (size_t) (int64_t) t0;
                    goto loop_16;
                } else {
                }
            }
        }
        { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = (size_t) (int64_t) INT64_C(0);
    l9 = std_string_byte_find(l0, l1, l6);
    {
        loop_54: {
            if ((l9 >= INT64_C(0))) {
                t0 = ((int64_t) (ptrdiff_t) l9);
                l7 = (size_t) (int64_t) t0;
                vader_array_t* _a2_arr = vader_array_slice((vader_array_t*) l3, (size_t) l6, (size_t) l7);
                t1 = (void*) _a2_arr;
                l8 = vader_host_std_core_bytes_to_string(t1);
                vader_array_push((vader_array_t*) l2, vader_box_string(164u, l8));
                t0 = (l7 + l5);
                l6 = (size_t) (int64_t) t0;
                l9 = std_string_byte_find(l0, l1, l6);
                goto loop_54;
            } else {
            }
        }
    }
    vader_array_t* _a3_arr = vader_array_slice((vader_array_t*) l3, (size_t) l6, (size_t) l4);
    t1 = (void*) _a3_arr;
    l8 = vader_host_std_core_bytes_to_string(t1);
    vader_array_push((vader_array_t*) l2, vader_box_string(164u, l8));
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

bool std_string_starts_with(vader_string_t l0, vader_string_t l1) {
    size_t l2, l3;
    uint8_t l4, l5;
    int64_t t0;
    vader_string_t* gc_atom_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = vader_host_std_core_byte_len(l1);
    l3 = vader_host_std_core_byte_len(l0);
    if ((l2 > l3)) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_15: {
            if ((l3 < l2)) {
                l4 = vader_host_std_core_byte_at(l0, l3);
                l5 = vader_host_std_core_byte_at(l1, l3);
                if (l4 != l5) {
                    { vader_gc_top = gc_frame.prev; return false; }
                }
                t0 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t0;
                goto loop_15;
            } else {
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return true; }
    vader_gc_top = gc_frame.prev;
}

vader_string_t std_string_to_lower(vader_string_t l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l5 = NULL;
    size_t l3, l4, l7;
    uint32_t l6, l8;
    void* t0 = NULL;
    uint32_t t1;
    int64_t t2;
    vader_string_t t3 = 0;
    void** gc_raw_roots[4] = { &l1, &l2, &l5, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 164u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 404u);
    _a1_obj->f_parts = t0;
    l1 = (void*) _a1_obj;
    l2 = vader_host_std_core_bytes(l0);
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_11: {
            if ((l4 < l3)) {
                l5 = std_string_utf8_decode_len(l2, l4);
                l6 = ((vader_struct___Tuple_256_t*) l5)->f__0;
                l7 = ((vader_struct___Tuple_256_t*) l5)->f__1;
                t1 = std_string_to_lower_cp((uint32_t) (int32_t) ((int32_t) (uint32_t) l6));
                l8 = ((uint32_t) (uint32_t) t1);
                std_string_builder_append_char(l1, l8);
                t2 = (l4 + l7);
                l4 = (size_t) (int64_t) t2;
                goto loop_11;
            } else {
            }
        }
    }
    t3 = std_string_builder_StringBuilder_Display_to_string(l1);
    { vader_string_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static uint8_t std_string_to_lower_byte(uint8_t l0) {
    bool l1;
    uint8_t l2;
    if ((l0 >= INT32_C(65))) {
        l1 = (l0 <= INT32_C(90));
    } else {
        l1 = false;
    }
    if (l1) {
        l2 = (uint8_t) (int32_t) INT32_C(32);
        return (uint8_t) (int32_t) (l0 + l2);
    }
    return l0;
}

static uint32_t std_string_to_lower_cp(uint32_t l0) {
    bool l1;
    uint32_t l2;
    int32_t t0;
    if ((l0 >= INT32_C(65))) {
        l1 = (l0 <= INT32_C(90));
    } else {
        l1 = false;
    }
    if (l1) {
        t0 = (l0 + INT32_C(32));
        l2 = (uint32_t) (int32_t) t0;
    } else {
        if ((l0 >= INT32_C(192))) {
            l1 = (l0 <= INT32_C(214));
        } else {
            l1 = false;
        }
        if (l1) {
            t0 = (l0 + INT32_C(32));
            l2 = (uint32_t) (int32_t) t0;
        } else {
            if ((l0 >= INT32_C(216))) {
                l1 = (l0 <= INT32_C(222));
            } else {
                l1 = false;
            }
            if (l1) {
                t0 = (l0 + INT32_C(32));
                l2 = (uint32_t) (int32_t) t0;
            } else {
                if (l0 == INT32_C(376)) {
                    l2 = (uint32_t) (int32_t) INT32_C(255);
                } else {
                    l2 = l0;
                }
            }
        }
    }
    return l2;
}

vader_string_t std_string_trim_prefix(vader_string_t l0, vader_string_t l1) {
    void* l2 = NULL;
    size_t l3, l4;
    bool t0;
    void* t1 = NULL;
    vader_string_t t2 = 0;
    void** gc_raw_roots[2] = { &l2, &t1 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l1, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = std_string_starts_with(l0, l1);
    if (t0) {
        l2 = vader_host_std_core_bytes(l0);
        l3 = vader_host_std_core_byte_len(l1);
        l4 = ((vader_array_t*) l2)->length;
        vader_array_t* _a0_arr = vader_array_slice((vader_array_t*) l2, (size_t) l3, (size_t) l4);
        t1 = (void*) _a0_arr;
        t2 = vader_host_std_core_bytes_to_string(t1);
        { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_string_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_string_t std_string_trim_suffix(vader_string_t l0, vader_string_t l1) {
    void* l2 = NULL;
    size_t l3, l4;
    bool t0;
    int64_t t1;
    void* t2 = NULL;
    vader_string_t t3 = 0;
    void** gc_raw_roots[2] = { &l2, &t2 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l1, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = std_string_ends_with(l0, l1);
    if (t0) {
        l2 = vader_host_std_core_bytes(l0);
        l3 = ((vader_array_t*) l2)->length;
        l4 = vader_host_std_core_byte_len(l1);
        t1 = (l3 - l4);
        l3 = (size_t) (int64_t) t1;
        vader_array_t* _a0_arr = vader_array_slice((vader_array_t*) l2, (size_t) INT64_C(0), (size_t) l3);
        t2 = (void*) _a0_arr;
        t3 = vader_host_std_core_bytes_to_string(t2);
        { vader_string_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_string_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

uint32_t std_string_utf8_decode(void* l0, size_t l1) {
    size_t l2, l4;
    uint8_t l3, l5, l8, l9;
    uint32_t l6, l7;
    vader_box_t t0;
    bool t1;
    int64_t t2;
    int32_t t3;
    l2 = ((vader_array_t*) l0)->length;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l1 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l1, 170u);
    l3 = ((uint8_t) t0.payload.i);
    if ((l3 < INT32_C(128))) {
        return ((uint32_t) (uint8_t) l3);
    }
    t1 = std_string_is_utf8_continuation(l3);
    if (t1) {
        return ((uint32_t) (int32_t) INT32_C(65533));
    }
    t2 = (l2 - l1);
    l2 = (size_t) (int64_t) t2;
    if ((l3 < INT32_C(224))) {
        if ((l2 < INT64_C(2))) {
            return ((uint32_t) (int32_t) INT32_C(0));
        }
        t2 = (l1 + INT64_C(1));
        l4 = (size_t) (int64_t) t2;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
        if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
        if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
        t0 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) l4, 170u);
        l5 = ((uint8_t) t0.payload.i);
        t3 = ((((int32_t) (uint8_t) l3) & INT32_C(31)) << INT32_C(6));
        l6 = (uint32_t) (int32_t) t3;
        t3 = (((int32_t) (uint8_t) l5) & INT32_C(63));
        l7 = (uint32_t) (int32_t) t3;
        return ((uint32_t) (int32_t) (l6 + l7));
    }
    if ((l3 < INT32_C(240))) {
        if ((l2 < INT64_C(3))) {
            return ((uint32_t) (int32_t) INT32_C(0));
        }
        t2 = (l1 + INT64_C(1));
        l4 = (size_t) (int64_t) t2;
        vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
        if ((size_t) l4 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
        t0 = vader_array_read_u8(_a2_slotarr, _a2_slotarr->offset + (size_t) l4, 170u);
        l5 = ((uint8_t) t0.payload.i);
        t2 = (l1 + INT64_C(2));
        l4 = (size_t) (int64_t) t2;
        if ((size_t) l4 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
        t0 = vader_array_read_u8(_a2_slotarr, _a2_slotarr->offset + (size_t) l4, 170u);
        l8 = ((uint8_t) t0.payload.i);
        t3 = ((((int32_t) (uint8_t) l3) & INT32_C(15)) << INT32_C(12));
        l6 = (uint32_t) (int32_t) t3;
        t3 = ((((int32_t) (uint8_t) l5) & INT32_C(63)) << INT32_C(6));
        l7 = (uint32_t) (int32_t) t3;
        t3 = (l6 + l7);
        l6 = (uint32_t) (int32_t) t3;
        t3 = (((int32_t) (uint8_t) l8) & INT32_C(63));
        l7 = (uint32_t) (int32_t) t3;
        return ((uint32_t) (int32_t) (l6 + l7));
    }
    if ((l2 < INT64_C(4))) {
        return ((uint32_t) (int32_t) INT32_C(0));
    }
    t2 = (l1 + INT64_C(1));
    l2 = (size_t) (int64_t) t2;
    vader_array_t* _a3_slotarr = ((vader_array_t*) l0);
    if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
    if ((size_t) l2 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
    t0 = vader_array_read_u8(_a3_slotarr, _a3_slotarr->offset + (size_t) l2, 170u);
    l5 = ((uint8_t) t0.payload.i);
    t2 = (l1 + INT64_C(2));
    l2 = (size_t) (int64_t) t2;
    if ((size_t) l2 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
    t0 = vader_array_read_u8(_a3_slotarr, _a3_slotarr->offset + (size_t) l2, 170u);
    l8 = ((uint8_t) t0.payload.i);
    t2 = (l1 + INT64_C(3));
    l2 = (size_t) (int64_t) t2;
    if ((size_t) l2 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
    t0 = vader_array_read_u8(_a3_slotarr, _a3_slotarr->offset + (size_t) l2, 170u);
    l9 = ((uint8_t) t0.payload.i);
    t3 = ((((int32_t) (uint8_t) l3) & INT32_C(7)) << INT32_C(18));
    l6 = (uint32_t) (int32_t) t3;
    t3 = ((((int32_t) (uint8_t) l5) & INT32_C(63)) << INT32_C(12));
    l7 = (uint32_t) (int32_t) t3;
    t3 = (l6 + l7);
    l6 = (uint32_t) (int32_t) t3;
    t3 = ((((int32_t) (uint8_t) l8) & INT32_C(63)) << INT32_C(6));
    l7 = (uint32_t) (int32_t) t3;
    t3 = (l6 + l7);
    l6 = (uint32_t) (int32_t) t3;
    t3 = (((int32_t) (uint8_t) l9) & INT32_C(63));
    l7 = (uint32_t) (int32_t) t3;
    return ((uint32_t) (int32_t) (l6 + l7));
}

void* std_string_utf8_decode_len(void* l0, size_t l1) {
    uint32_t l2;
    size_t l3;
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = std_string_utf8_decode(l0, l1);
    l3 = std_string_codepoint_byte_len(l2);
    vader_struct___Tuple_256_t* _a0_obj = (vader_struct___Tuple_256_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_256_t));
    vader_obj_header_init(_a0_obj, 232u);
    _a0_obj->f__0 = l2;
    _a0_obj->f__1 = l3;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

size_t std_string_utf8_lead_len(uint8_t l0) {
    if ((l0 < INT32_C(128))) {
        return (size_t) (int64_t) INT64_C(1);
    }
    if ((l0 < INT32_C(192))) {
        return (size_t) (int64_t) INT64_C(1);
    }
    if ((l0 < INT32_C(224))) {
        return (size_t) (int64_t) INT64_C(2);
    }
    if ((l0 < INT32_C(240))) {
        return (size_t) (int64_t) INT64_C(3);
    }
    return (size_t) (int64_t) INT64_C(4);
}

