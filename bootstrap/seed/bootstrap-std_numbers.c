#include "bootstrap.split.h"

uint32_t std_numbers_hex_digit(uint64_t l0) {
    uint32_t l1;
    int32_t t0;
    if ((l0 <= INT64_C(9))) {
        t0 = ((int32_t) (uint64_t) l0);
        l1 = (uint32_t) (int32_t) t0;
        return ((uint32_t) (int32_t) (INT32_C(48) + l1));
    }
    t0 = ((int32_t) (uint64_t) l0);
    l1 = (uint32_t) (int32_t) t0;
    return ((uint32_t) (int32_t) ((INT32_C(97) + l1) - INT32_C(10)));
}

int32_t std_numbers_hex_digit_value(uint32_t l0) {
    bool l1;
    int32_t l2;
    if ((l0 >= 48u)) {
        l1 = (l0 <= 57u);
    } else {
        l1 = false;
    }
    if (l1) {
        l2 = (((int32_t) (uint32_t) l0) - INT32_C(48));
    } else {
        if ((l0 >= 97u)) {
            l1 = (l0 <= 102u);
        } else {
            l1 = false;
        }
        if (l1) {
            l2 = ((((int32_t) (uint32_t) l0) - INT32_C(97)) + INT32_C(10));
        } else {
            if ((l0 >= 65u)) {
                l1 = (l0 <= 70u);
            } else {
                l1 = false;
            }
            if (l1) {
                l2 = ((((int32_t) (uint32_t) l0) - INT32_C(65)) + INT32_C(10));
            } else {
                l2 = -(INT32_C(1));
            }
        }
    }
    return l2;
}

bool std_numbers_is_digit_in_base(uint32_t l0, int32_t l1) {
    bool l2;
    bool t0;
    if (l1 == INT32_C(2)) {
        if (l0 == 48u) {
            l2 = true;
        } else {
            l2 = l0 == 49u;
        }
        return l2;
    }
    if (l1 == INT32_C(8)) {
        if ((48u <= l0)) {
            l2 = (l0 <= 55u);
        } else {
            l2 = false;
        }
        return l2;
    }
    if (l1 == INT32_C(16)) {
        t0 = std_numbers_is_hex_digit(l0);
        return t0;
    }
    t0 = std_char_is_digit(l0);
    return t0;
}

bool std_numbers_is_hex_digit(uint32_t l0) {
    bool l1, l2;
    bool t0;
    t0 = std_char_is_digit(l0);
    if (t0) {
        l1 = true;
    } else {
        if ((97u <= l0)) {
            l2 = (l0 <= 102u);
        } else {
            l2 = false;
        }
        l1 = l2;
    }
    if (l1) {
        l1 = true;
    } else {
        if ((65u <= l0)) {
            l2 = (l0 <= 70u);
        } else {
            l2 = false;
        }
        l1 = l2;
    }
    return l1;
}

vader_box_t std_numbers_parse_uint_in_base(vader_string_t l0, int32_t l1) {
    uint64_t l2, l3, l8, l9, l10, l11;
    void* l4 = NULL;
    vader_box_t l5 = vader_box_null();
    int32_t l6;
    bool l7;
    bool t0;
    void* t1 = NULL;
    int64_t t2;
    vader_box_t t3 = vader_box_null();
    uint32_t t4;
    vader_box_t* gc_roots[2] = { &l5, &t3 };
    void** gc_raw_roots[2] = { &l4, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = std_string_is_empty(l0);
    if (t0) {
        vader_struct_std_string_ParseError_t* _a0_obj = (vader_struct_std_string_ParseError_t*) vader_gc_alloc(sizeof(vader_struct_std_string_ParseError_t));
        vader_obj_header_init(_a0_obj, 389u);
        _a0_obj->f_msg = 1474u;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = (uint64_t) (int64_t) INT64_C(0);
    t2 = ((int64_t) (int32_t) l1);
    l3 = (uint64_t) (int64_t) t2;
    l4 = std_string_chars(l0);
    {
        loop_16: {
            l5 = std_string_StringChars_Iterator_next(l4);
            if (l5.tag == 0u) {
                t3 = vader_box_i64(178u, (int64_t)(uint64_t) l2);
                { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
            }
            t1 = l5.payload.obj;
            t4 = ((vader_struct_std_core_Yield__char_t*) t1)->f_value;
            l6 = std_numbers_hex_digit_value(t4);
            if ((l6 < INT32_C(0))) {
                l7 = true;
            } else {
                l7 = (l6 >= l1);
            }
            if (l7) {
                vader_struct_std_string_ParseError_t* _a1_obj = (vader_struct_std_string_ParseError_t*) vader_gc_alloc(sizeof(vader_struct_std_string_ParseError_t));
                vader_obj_header_init(_a1_obj, 389u);
                _a1_obj->f_msg = 1759u;
                t1 = (void*) _a1_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t2 = ((int64_t) (int32_t) l6);
            l8 = (uint64_t) (int64_t) t2;
            l9 = vader_div_u64((INT64_C(-1) - l8), l3);
            if ((l2 > l9)) {
                vader_struct_std_string_ParseError_t* _a2_obj = (vader_struct_std_string_ParseError_t*) vader_gc_alloc(sizeof(vader_struct_std_string_ParseError_t));
                vader_obj_header_init(_a2_obj, 389u);
                _a2_obj->f_msg = 1934u;
                t1 = (void*) _a2_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t2 = (l2 * l3);
            l10 = (uint64_t) (int64_t) t2;
            t2 = ((int64_t) (int32_t) l6);
            l11 = (uint64_t) (int64_t) t2;
            t2 = (l10 + l11);
            l2 = (uint64_t) (int64_t) t2;
            goto loop_16;
        }
    }
    t3 = vader_box_i64(178u, (int64_t)(uint64_t) l2);
    { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_string_t std_numbers_strip_numeric_text(vader_string_t l0, int32_t l1) {
    size_t l2, l4;
    void* l3 = NULL;
    vader_string_t l5 = 0;
    void* t0 = NULL;
    bool t1;
    vader_string_t t2 = 0;
    void** gc_raw_roots[2] = { &l3, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l5, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l1 == INT32_C(10)) {
        l2 = (size_t) (int64_t) INT64_C(0);
    } else {
        l2 = (size_t) (int64_t) INT64_C(2);
    }
    l3 = vader_host_std_core_bytes(l0);
    l4 = ((vader_array_t*) l3)->length;
    vader_array_t* _a0_arr = vader_array_slice((vader_array_t*) l3, (size_t) l2, (size_t) l4);
    t0 = (void*) _a0_arr;
    l5 = vader_host_std_core_bytes_to_string(t0);
    t1 = std_string_byte_contains(l5, 869u);
    if (!(t1)) {
        { vader_string_t __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct___lambda_env_std_numbers_1_t* _a1_obj = (vader_struct___lambda_env_std_numbers_1_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_std_numbers_1_t));
    vader_obj_header_init(_a1_obj, 242u);
    t0 = (void*) _a1_obj;
    vader_fn_t* _a2_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a2_closure, 140u);
    _a2_closure->code = (void*) &vader_fn_lift___lambda_std_numbers_0;
    _a2_closure->env = t0;
    l3 = (void*) _a2_closure;
    t2 = std_string_replace_chars_where(l5, l3, 0u);
    { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_string_t std_numbers_to_hex(uint64_t l0) {
    void* l1 = NULL;
    void* l5 = NULL;
    uint64_t l2, l3;
    uint32_t l4;
    size_t l6, l7, l8;
    uint64_t t0;
    void* t1 = NULL;
    int64_t t2;
    int32_t t3;
    vader_string_t t4 = 0;
    void** gc_raw_roots[3] = { &l1, &l5, &t1 };
    vader_string_t* gc_atom_roots[1] = { &t4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l0 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return 451u; }
    }
    vader_array_t* _a0_arr = vader_array_new(7u, 0u, 11u, 168u);
    l1 = (void*) _a0_arr;
    l2 = (uint64_t) (int64_t) INT64_C(16);
    l3 = l0;
    {
        loop_13: {
            if ((l3 > INT64_C(0))) {
                t0 = vader_mod_u64(l3, l2);
                l4 = std_numbers_hex_digit(t0);
                vader_array_push_i32((vader_array_t*) l1, (int32_t) (uint32_t) l4);
                l3 = vader_div_u64(l3, l2);
                goto loop_13;
            }
        }
    }
    vader_array_t* _a1_arr = vader_array_new(8u, 0u, 0u, 169u);
    t1 = (void*) _a1_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a2_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a2_obj, 391u);
    _a2_obj->f_parts = t1;
    l5 = (void*) _a2_obj;
    l6 = ((vader_array_t*) l1)->length;
    l7 = (size_t) (int64_t) INT64_C(0);
    {
        loop_43: {
            if ((l7 < l6)) {
                t2 = ((l6 - INT64_C(1)) - l7);
                l8 = (size_t) (int64_t) t2;
                vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l8 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                t3 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l8];
                l4 = (uint32_t) (int32_t) t3;
                std_string_builder_append_char(l5, l4);
                t2 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t2;
                goto loop_43;
            }
        }
    }
    t4 = std_string_builder_StringBuilder_Display_to_string(l5);
    { vader_string_t __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

