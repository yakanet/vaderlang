#include "bootstrap.split.h"

uint32_t std_numbers$hex_digit(uint64_t l0) {
    uint32_t l1;
    bool l2;
    int32_t t0, t1;
    if ((l0 <= INT64_C(9))) {
        t0 = ((int32_t) (uint64_t) l0);
        l1 = (uint32_t) (int32_t) t0;
        t0 = vader_chk_add(u32, INT32_C(48), l1);
        l1 = (uint32_t) (int32_t) t0;
        if ((l1 > INT32_C(55295))) {
            if ((l1 < INT32_C(57344))) {
                l2 = true;
            } else {
                l2 = (l1 > INT32_C(1114111));
            }
            if (l2) {
                vader_unreachable("value out of range: no Unicode scalar value");
            } else {
                return ((uint32_t) (uint32_t) l1);
            }
        } else {
            return ((uint32_t) (uint32_t) l1);
        }
    } else {
        t0 = ((int32_t) (uint64_t) l0);
        l1 = (uint32_t) (int32_t) t0;
        t0 = vader_chk_add(u32, INT32_C(97), l1);
        t1 = vader_chk_sub(u32, t0, INT32_C(10));
        l1 = (uint32_t) (int32_t) t1;
        if ((l1 > INT32_C(55295))) {
            if ((l1 < INT32_C(57344))) {
                l2 = true;
            } else {
                l2 = (l1 > INT32_C(1114111));
            }
            if (l2) {
                vader_unreachable("value out of range: no Unicode scalar value");
            } else {
                return ((uint32_t) (uint32_t) l1);
            }
        } else {
            return ((uint32_t) (uint32_t) l1);
        }
    }
}

int32_t std_numbers$hex_digit_value(uint32_t l0) {
    int32_t l1;
    bool l2;
    int32_t t0, t1;
    if ((l0 >= 48u)) {
        l2 = (l0 <= 57u);
    } else {
        l2 = false;
    }
    if (l2) {
        t0 = vader_chk_sub(u32, ((int32_t) (uint32_t) l0), INT32_C(48));
        l1 = t0;
        return l1;
    }
    if ((l0 >= 97u)) {
        l2 = (l0 <= 102u);
    } else {
        l2 = false;
    }
    if (l2) {
        t0 = vader_chk_sub(u32, ((int32_t) (uint32_t) l0), INT32_C(97));
        t1 = vader_chk_add(u32, t0, INT32_C(10));
        l1 = t1;
    } else {
        if ((l0 >= 65u)) {
            l2 = (l0 <= 70u);
        } else {
            l2 = false;
        }
        if (l2) {
            t0 = vader_chk_sub(u32, ((int32_t) (uint32_t) l0), INT32_C(65));
            t1 = vader_chk_add(u32, t0, INT32_C(10));
            l1 = t1;
        } else {
            l1 = INT32_C(-1);
        }
    }
    return l1;
}

bool std_numbers$is_digit_in_base(uint32_t l0, int32_t l1) {
    bool t0;
    if (l1 == INT32_C(2)) {
        if (l0 == 48u) {
            return true;
        }
        return l0 == 49u;
    }
    if (l1 == INT32_C(8)) {
        if ((48u <= l0)) {
            return (l0 <= 55u);
        }
        return false;
    }
    if (!(l1 == INT32_C(16))) {
        t0 = std_char$is_digit(l0);
        return t0;
    }
    t0 = std_numbers$is_hex_digit(l0);
    return t0;
}

bool std_numbers$is_hex_digit(uint32_t l0) {
    bool l1, l2;
    bool t0;
    t0 = std_char$is_digit(l0);
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
        return true;
    }
    if ((65u <= l0)) {
        l1 = (l0 <= 70u);
    } else {
        l1 = false;
    }
    return l1;
}

vader_box_t std_numbers$parse_uint_in_base(vader_string_t l0, int32_t l1) {
    uint64_t l2, l3, l4, l11, l12, l13, l14, l20, l21, l22, l23;
    vader_string_t l5 = 0;
    int64_t l6, l7, l16, l24;
    uint8_t l8;
    int32_t l9, l18;
    bool l10, l17, l19;
    uint32_t l15;
    bool t0;
    void* t1 = NULL;
    int64_t t2;
    uint32_t t3;
    void** gc_raw_roots[1] = { &t1 };
    vader_string_t* gc_atom_roots[2] = { &l0, &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = std_string$is_empty(l0);
    if (t0) {
        vader_struct_std_string$ParseError_t* _a0_obj = (vader_struct_std_string$ParseError_t*) vader_gc_alloc(sizeof(vader_struct_std_string$ParseError_t));
        vader_obj_header_init(_a0_obj, 625u);
        _a0_obj->f_msg = 1869u;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = (uint64_t) 0;
    t2 = ((int64_t) (int32_t) l1);
    l3 = (uint64_t) (int64_t) t2;
    l4 = (uint64_t) -1;
    l5 = l0;
    l6 = INT64_C(0);
    for (;;) {
        l7 = vader_host_std_core$byte_len(l5);
        if ((l6 < l7)) {
            l8 = vader_host_std_core$byte_at(l5, l6);
            if ((l8 < INT32_C(128))) {
                l6 = vader_chk_add(i64, l6, INT64_C(1));
                l9 = std_numbers$hex_digit_value(((uint32_t) (uint8_t) l8));
                if ((l9 < INT32_C(0))) {
                    l10 = true;
                } else {
                    l10 = (l9 >= l1);
                }
                if (l10) {
                    vader_struct_std_string$ParseError_t* _a1_obj = (vader_struct_std_string$ParseError_t*) vader_gc_alloc(sizeof(vader_struct_std_string$ParseError_t));
                    vader_obj_header_init(_a1_obj, 625u);
                    _a1_obj->f_msg = 2197u;
                    t1 = (void*) _a1_obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                t2 = ((int64_t) (int32_t) l9);
                l11 = (uint64_t) (int64_t) t2;
                t2 = vader_chk_sub(u64, l4, l11);
                l12 = vader_div_u64(t2, l3);
                if ((l2 > l12)) {
                    vader_struct_std_string$ParseError_t* _a2_obj = (vader_struct_std_string$ParseError_t*) vader_gc_alloc(sizeof(vader_struct_std_string$ParseError_t));
                    vader_obj_header_init(_a2_obj, 625u);
                    _a2_obj->f_msg = 2441u;
                    t1 = (void*) _a2_obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                t2 = vader_chk_mul(u64, l2, l3);
                l13 = (uint64_t) (int64_t) t2;
                t2 = ((int64_t) (int32_t) l9);
                l14 = (uint64_t) (int64_t) t2;
                t2 = vader_chk_add(u64, l13, l14);
                l2 = (uint64_t) (int64_t) t2;
                continue;
            }
            std_core$decode_tail(l5, l8, l6, &t3, &t2);
            l24 = t2;
            l15 = t3;
            l16 = l24;
            l6 = vader_chk_add(i64, l6, l16);
            if ((l15 > INT32_C(55295))) {
                if ((l15 < INT32_C(57344))) {
                    l17 = true;
                } else {
                    l17 = (l15 > INT32_C(1114111));
                }
                if (l17) {
                    vader_unreachable("value out of range: no Unicode scalar value");
                }
            }
            l18 = std_numbers$hex_digit_value(((uint32_t) (uint32_t) l15));
            if ((l18 < INT32_C(0))) {
                l19 = true;
            } else {
                l19 = (l18 >= l1);
            }
            if (l19) {
                vader_struct_std_string$ParseError_t* _a3_obj = (vader_struct_std_string$ParseError_t*) vader_gc_alloc(sizeof(vader_struct_std_string$ParseError_t));
                vader_obj_header_init(_a3_obj, 625u);
                _a3_obj->f_msg = 2197u;
                t1 = (void*) _a3_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t2 = ((int64_t) (int32_t) l18);
            l20 = (uint64_t) (int64_t) t2;
            t2 = vader_chk_sub(u64, l4, l20);
            l21 = vader_div_u64(t2, l3);
            if ((l2 > l21)) {
                vader_struct_std_string$ParseError_t* _a4_obj = (vader_struct_std_string$ParseError_t*) vader_gc_alloc(sizeof(vader_struct_std_string$ParseError_t));
                vader_obj_header_init(_a4_obj, 625u);
                _a4_obj->f_msg = 2441u;
                t1 = (void*) _a4_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t2 = vader_chk_mul(u64, l2, l3);
            l22 = (uint64_t) (int64_t) t2;
            t2 = ((int64_t) (int32_t) l18);
            l23 = (uint64_t) (int64_t) t2;
            t2 = vader_chk_add(u64, l22, l23);
            l2 = (uint64_t) (int64_t) t2;
            continue;
        }
        break;
    }
    { vader_box_t __vret = vader_box_i64(343u, (int64_t)(uint64_t) l2); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t std_numbers$strip_numeric_text(vader_string_t l0, int32_t l1) {
    int64_t l2, l3;
    vader_string_t l4 = 0;
    void* l5 = NULL;
    bool t0;
    vader_string_t t1 = 0;
    void** gc_raw_roots[1] = { &l5 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l4, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1 == INT32_C(10)) {
        l2 = INT64_C(0);
    } else {
        l2 = INT64_C(2);
    }
    l3 = vader_host_std_core$byte_len(l0);
    l4 = vader_host_std_core$byte_slice(l0, l2, l3);
    t0 = std_string$string$std_core$Contains$contains(l4, 976u);
    if (!(t0)) {
        { vader_string_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = (void*) &vader_fn_static___lambda_std_numbers_0;
    t1 = std_string$replace_chars_where(l4, l5, 0u);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t std_numbers$to_hex(uint64_t l0) {
    void* l1 = NULL;
    void* l5 = NULL;
    uint64_t l2, l3;
    uint32_t l4;
    int64_t l6, l7, l8;
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
        { vader_gc_top = gc_frame.prev; return 452u; }
    }
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 11u, 334u);
    l1 = (void*) _a0_arr;
    l2 = (uint64_t) 16;
    l3 = l0;
    vader_array_t* _pc12_hdr = (vader_array_t*) l1;
    size_t _pc12_len = _pc12_hdr->length;
    size_t _pc12_cap = (_pc12_hdr->offset == 0 && !vader_array_is_borrowed(_pc12_hdr) && _pc12_hdr->length >= _pc12_hdr->buf->length) ? _pc12_hdr->capacity : (size_t) 0;
    void* _pc12_slots = _pc12_hdr->buf->slots;
    for (;;) {
        if ((l3 > INT64_C(0))) {
            t0 = vader_mod_u64(l3, l2);
            l4 = std_numbers$hex_digit(t0);
            if (VADER_LIKELY(_pc12_len < _pc12_cap)) {
                ((int32_t*) _pc12_slots)[_pc12_len] = (int32_t) ((int32_t) (uint32_t) l4);
                _pc12_len += 1;
            } else {
                _pc12_hdr->length = _pc12_len;
                if (_pc12_hdr->buf->length < _pc12_len) {
                    _pc12_hdr->buf->length = _pc12_len;
                }
                vader_array_push_i32((vader_array_t*) l1, (int32_t) (uint32_t) l4);
                _pc12_hdr = (vader_array_t*) l1;
                _pc12_len = _pc12_hdr->length;
                _pc12_cap = (_pc12_hdr->offset == 0 && !vader_array_is_borrowed(_pc12_hdr) && _pc12_hdr->length >= _pc12_hdr->buf->length) ? _pc12_hdr->capacity : (size_t) 0;
                _pc12_slots = _pc12_hdr->buf->slots;
            }
            l3 = vader_div_u64(l3, l2);
            continue;
        }
        _pc12_hdr->length = _pc12_len;
        if (_pc12_hdr->buf->length < _pc12_len) {
            _pc12_hdr->buf->length = _pc12_len;
        }
        break;
    }
    vader_array_t* _a1_arr = vader_array_new(22u, 0u, 0u, 335u);
    t1 = (void*) _a1_arr;
    vader_struct_std_string__builder$StringBuilder_t* _a2_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
    vader_obj_header_init(_a2_obj, 626u);
    _a2_obj->f_parts = t1;
    l5 = (void*) _a2_obj;
    l6 = ((vader_array_t*) l1)->length;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        t2 = vader_chk_sub(i64, l6, INT64_C(1));
        l8 = vader_chk_sub(i64, t2, l7);
        vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l8)
        t3 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l8];
        l4 = (uint32_t) (int32_t) t3;
        std_string__builder$append_char(l5, l4);
        l7 = (l7 + INT64_C(1));
    }
    t4 = std_string__builder$StringBuilder$std_core$Display$to_string(l5);
    { vader_string_t __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
}
