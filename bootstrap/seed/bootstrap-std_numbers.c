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
    uint64_t l2, l3, l7, l8, l9, l10;
    void* l4 = NULL;
    int32_t l5;
    bool l6;
    uint32_t l11;
    uint8_t l12;
    bool t0;
    void* t1 = NULL;
    int64_t t2;
    uint32_t t3;
    uint8_t t4;
    vader_box_t t5 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t5 };
    void** gc_raw_roots[2] = { &l4, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = std_string_is_empty(l0);
    if (t0) {
        vader_struct_std_string_ParseError_t* _a0_obj = (vader_struct_std_string_ParseError_t*) vader_gc_alloc(sizeof(vader_struct_std_string_ParseError_t));
        vader_obj_header_init(_a0_obj, 372u);
        _a0_obj->f_msg = 1358u;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = (uint64_t) 0;
    t2 = ((int64_t) (int32_t) l1);
    l3 = (uint64_t) (int64_t) t2;
    l4 = std_string_chars(l0);
    for (;;) {
        std_string_StringChars_Iterator_next_v(l4, &t3, &t4);
        l12 = t4;
        l11 = t3;
        if (l12 == INT32_C(1)) {
            t5 = vader_box_i64(199u, (int64_t)(uint64_t) l2);
            { vader_box_t __vret = t5; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l5 = std_numbers_hex_digit_value(l11);
        if ((l5 < INT32_C(0))) {
            l6 = true;
        } else {
            l6 = (l5 >= l1);
        }
        if (l6) {
            vader_struct_std_string_ParseError_t* _a1_obj = (vader_struct_std_string_ParseError_t*) vader_gc_alloc(sizeof(vader_struct_std_string_ParseError_t));
            vader_obj_header_init(_a1_obj, 372u);
            _a1_obj->f_msg = 1648u;
            t1 = (void*) _a1_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = ((int64_t) (int32_t) l5);
        l7 = (uint64_t) (int64_t) t2;
        l8 = vader_div_u64((INT64_C(-1) - l7), l3);
        if ((l2 > l8)) {
            vader_struct_std_string_ParseError_t* _a2_obj = (vader_struct_std_string_ParseError_t*) vader_gc_alloc(sizeof(vader_struct_std_string_ParseError_t));
            vader_obj_header_init(_a2_obj, 372u);
            _a2_obj->f_msg = 1840u;
            t1 = (void*) _a2_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = (l2 * l3);
        l9 = (uint64_t) (int64_t) t2;
        t2 = ((int64_t) (int32_t) l5);
        l10 = (uint64_t) (int64_t) t2;
        t2 = (l9 + l10);
        l2 = (uint64_t) (int64_t) t2;
        continue;
    }
    t5 = vader_box_i64(199u, (int64_t)(uint64_t) l2);
    { vader_box_t __vret = t5; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1 == INT32_C(10)) {
        l2 = (size_t) 0;
    } else {
        l2 = (size_t) 2;
    }
    l3 = vader_host_std_core_bytes(l0);
    l4 = ((vader_array_t*) l3)->length;
    vader_array_t* _a0_arr = vader_array_slice((vader_array_t*) l3, (size_t) l2, (size_t) l4);
    t0 = (void*) _a0_arr;
    l5 = vader_host_std_core_bytes_to_string(t0);
    t1 = std_string_string_Contains_contains(l5, 716u);
    if (!(t1)) {
        { vader_string_t __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct___lambda_env_std_numbers_1_t* _a1_obj = (vader_struct___lambda_env_std_numbers_1_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_std_numbers_1_t));
    vader_obj_header_init(_a1_obj, 225u);
    t0 = (void*) _a1_obj;
    vader_fn_t* _a2_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a2_closure, 162u);
    _a2_closure->code = (void*) &vader_fn_lift___lambda_std_numbers_0;
    _a2_closure->env = t0;
    l3 = (void*) _a2_closure;
    t2 = std_string_replace_chars_where(l5, l3, 0u);
    { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return 287u; }
    }
    vader_array_t* _a0_arr = vader_array_new(7u, 0u, 11u, 189u);
    l1 = (void*) _a0_arr;
    l2 = (uint64_t) 16;
    l3 = l0;
    {
        vader_array_t* _pc13_hdr = (vader_array_t*) l1;
        size_t _pc13_len = _pc13_hdr->length;
        size_t _pc13_cap = (_pc13_hdr->offset == 0 && !vader_array_is_borrowed(_pc13_hdr) && _pc13_hdr->length >= _pc13_hdr->buf->length) ? _pc13_hdr->capacity : (size_t) 0;
        void* _pc13_slots = _pc13_hdr->buf->slots;
        for (;;) {
            if ((l3 > INT64_C(0))) {
                t0 = vader_mod_u64(l3, l2);
                l4 = std_numbers_hex_digit(t0);
                if (VADER_LIKELY(_pc13_len < _pc13_cap)) {
                    ((int32_t*) _pc13_slots)[_pc13_len] = (int32_t) ((int32_t) (uint32_t) l4);
                    _pc13_len += 1;
                } else {
                    _pc13_hdr->length = _pc13_len;
                    if (_pc13_hdr->buf->length < _pc13_len) {
                        _pc13_hdr->buf->length = _pc13_len;
                    }
                    vader_array_push_i32((vader_array_t*) l1, (int32_t) (uint32_t) l4);
                    _pc13_hdr = (vader_array_t*) l1;
                    _pc13_len = _pc13_hdr->length;
                    _pc13_cap = (_pc13_hdr->offset == 0 && !vader_array_is_borrowed(_pc13_hdr) && _pc13_hdr->length >= _pc13_hdr->buf->length) ? _pc13_hdr->capacity : (size_t) 0;
                    _pc13_slots = _pc13_hdr->buf->slots;
                }
                l3 = vader_div_u64(l3, l2);
                continue;
            }
            _pc13_hdr->length = _pc13_len;
            if (_pc13_hdr->buf->length < _pc13_len) {
                _pc13_hdr->buf->length = _pc13_len;
            }
            break;
        }
    }
    vader_array_t* _a1_arr = vader_array_new(8u, 0u, 0u, 190u);
    t1 = (void*) _a1_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a2_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a2_obj, 374u);
    _a2_obj->f_parts = t1;
    l5 = (void*) _a2_obj;
    l6 = ((vader_array_t*) l1)->length;
    l7 = (size_t) 0;
    while ((l7 < l6)) {
        t2 = ((l6 - INT64_C(1)) - l7);
        l8 = (size_t) (int64_t) t2;
        vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l8)
        t3 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l8];
        l4 = (uint32_t) (int32_t) t3;
        std_string_builder_append_char(l5, l4);
        t2 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t2;
    }
    t4 = std_string_builder_StringBuilder_Display_to_string(l5);
    { vader_string_t __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
}
