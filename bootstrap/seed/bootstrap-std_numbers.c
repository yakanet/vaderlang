#include "bootstrap.split.h"

static uint32_t std_numbers$digit_char(uint64_t l0, bool l1);
static vader_string_t std_numbers$digits_in_base(uint64_t l0, uint64_t l1, bool l2);

static uint32_t std_numbers$digit_char(uint64_t l0, bool l1) {
    uint32_t l2;
    bool l3;
    int32_t t0, t1;
    uint32_t t2;
    if (l1) {
        if ((l0 >= INT64_C(10))) {
            t0 = ((int32_t) (uint64_t) l0);
            l2 = (uint32_t) (int32_t) t0;
            t0 = vader_chk_add(u32, INT32_C(65), l2);
            t1 = vader_chk_sub(u32, t0, INT32_C(10));
            l2 = (uint32_t) (int32_t) t1;
            if ((l2 > INT32_C(55295))) {
                if ((l2 < INT32_C(57344))) {
                    l3 = true;
                } else {
                    l3 = (l2 > INT32_C(1114111));
                }
                if (l3) {
                    vader_unreachable("value out of range: no Unicode scalar value");
                } else {
                    return ((uint32_t) (uint32_t) l2);
                }
            } else {
                return ((uint32_t) (uint32_t) l2);
            }
        } else {
            t2 = std_numbers$hex_digit(l0);
            return t2;
        }
    } else {
        t2 = std_numbers$hex_digit(l0);
        return t2;
    }
}

static vader_string_t std_numbers$digits_in_base(uint64_t l0, uint64_t l1, bool l2) {
    void* l3 = NULL;
    void* l6 = NULL;
    uint64_t l4;
    uint32_t l5;
    int64_t l7, l8, l9;
    uint64_t t0;
    void* t1 = NULL;
    int64_t t2;
    int32_t t3;
    vader_string_t t4 = 0;
    void** gc_raw_roots[3] = { &l3, &l6, &t1 };
    vader_string_t* gc_atom_roots[1] = { &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return 496u; }
    }
    vader_array_t* _a0_arr = vader_array_new(25u, 0u, 11u, 498u);
    l3 = (void*) _a0_arr;
    l4 = l0;
    vader_array_t* _pc10_hdr = (vader_array_t*) l3;
    size_t _pc10_len = vader_array_length(_pc10_hdr);
    size_t _pc10_cap = vader_array_is_borrowed(_pc10_hdr) ? (size_t) 0 : vader_array_capacity(_pc10_hdr);
    void* _pc10_slots = _pc10_hdr->buf->slots;
    for (;;) {
        if ((l4 > INT64_C(0))) {
            t0 = vader_mod_u64(l4, l1);
            l5 = std_numbers$digit_char(t0, l2);
            if (VADER_LIKELY(_pc10_len < _pc10_cap)) {
                ((int32_t*) _pc10_slots)[_pc10_len] = (int32_t) ((int32_t) (uint32_t) l5);
                _pc10_len += 1;
            } else {
                vader_array_set_length(_pc10_hdr, _pc10_len);
                if (_pc10_hdr->buf->length < _pc10_len) {
                    _pc10_hdr->buf->length = _pc10_len;
                }
                vader_array_push_i32((vader_array_t*) l3, (int32_t) (uint32_t) l5);
                _pc10_hdr = (vader_array_t*) l3;
                _pc10_len = vader_array_length(_pc10_hdr);
                _pc10_cap = vader_array_is_borrowed(_pc10_hdr) ? (size_t) 0 : vader_array_capacity(_pc10_hdr);
                _pc10_slots = _pc10_hdr->buf->slots;
            }
            l4 = vader_div_u64(l4, l1);
            continue;
        }
        vader_array_set_length(_pc10_hdr, _pc10_len);
        if (_pc10_hdr->buf->length < _pc10_len) {
            _pc10_hdr->buf->length = _pc10_len;
        }
        break;
    }
    vader_array_t* _a1_arr = vader_array_new(26u, 0u, 0u, 499u);
    t1 = (void*) _a1_arr;
    vader_struct_std_string__builder$StringBuilder_t* _a2_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
    vader_obj_header_init(_a2_obj, 876u);
    _a2_obj->f_parts = t1;
    l6 = (void*) _a2_obj;
    l7 = vader_array_length(((vader_array_t*) l3));
    l8 = INT64_C(0);
    while ((l8 < l7)) {
        t2 = vader_chk_sub(i64, l7, INT64_C(1));
        l9 = vader_chk_sub(i64, t2, l8);
        vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l9)
        t3 = ((int32_t*) _a3_slotarr->buf->slots)[vader_array_offset(_a3_slotarr) + (size_t) l9];
        l5 = (uint32_t) (int32_t) t3;
        std_string__builder$append_char(l6, l5);
        l8 = (l8 + INT64_C(1));
    }
    t4 = std_string__builder$StringBuilder$std_core$Display$to_string(l6);
    { vader_string_t __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
}

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

vader_box_t std_numbers$hex_digit_value(uint32_t l0) {
    vader_box_t l1;
    bool l2;
    int32_t t0, t1;
    if ((l0 >= 48u)) {
        l2 = (l0 <= 57u);
    } else {
        l2 = false;
    }
    if (l2) {
        t0 = vader_chk_sub(u32, ((int32_t) (uint32_t) l0), INT32_C(48));
        l1 = vader_box_i32(502u, t0);
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
        l1 = vader_box_i32(502u, t1);
    } else {
        if ((l0 >= 65u)) {
            l2 = (l0 <= 70u);
        } else {
            l2 = false;
        }
        if (l2) {
            t0 = vader_chk_sub(u32, ((int32_t) (uint32_t) l0), INT32_C(65));
            t1 = vader_chk_add(u32, t0, INT32_C(10));
            l1 = vader_box_i32(502u, t1);
        } else {
            l1 = vader_box_obj(0u, NULL);
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
    uint64_t l2, l3, l4, l5, l14, l15, l23, l24;
    vader_string_t l6 = 0;
    int64_t l7, l8, l17, l25;
    uint8_t l9;
    int32_t l10, l19;
    vader_box_t l11 = vader_box_null(), l20 = vader_box_null();
    bool l12, l13, l18, l21, l22;
    uint32_t l16;
    bool t0;
    void* t1 = NULL;
    int64_t t2;
    uint32_t t3;
    vader_box_t* gc_roots[2] = { &l11, &l20 };
    void** gc_raw_roots[1] = { &t1 };
    vader_string_t* gc_atom_roots[2] = { &l0, &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = std_core$is_empty_1(l0);
    if (t0) {
        vader_struct_std_string$ParseError_t* _a0_obj = (vader_struct_std_string$ParseError_t*) vader_gc_alloc(sizeof(vader_struct_std_string$ParseError_t));
        vader_obj_header_init(_a0_obj, 875u);
        _a0_obj->f_msg = 2005u;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = (uint64_t) 0;
    t2 = ((int64_t) (int32_t) l1);
    l3 = (uint64_t) (int64_t) t2;
    l4 = vader_div_u64(INT64_C(-1), l3);
    l5 = vader_mod_u64(INT64_C(-1), l3);
    l6 = l0;
    l7 = INT64_C(0);
    for (;;) {
        l8 = vader_host_std_core$byte_len(l6);
        if ((l7 < l8)) {
            l9 = vader_host_std_core$byte_at(l6, l7);
            if ((l9 < INT32_C(128))) {
                l7 = vader_chk_add(i64, l7, INT64_C(1));
                l11 = std_numbers$hex_digit_value(((uint32_t) (uint8_t) l9));
                if (l11.tag == 0u) {
                    vader_struct_std_string$ParseError_t* _a1_obj = (vader_struct_std_string$ParseError_t*) vader_gc_alloc(sizeof(vader_struct_std_string$ParseError_t));
                    vader_obj_header_init(_a1_obj, 875u);
                    _a1_obj->f_msg = 2343u;
                    t1 = (void*) _a1_obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                l10 = ((int32_t) l11.payload.i);
                if ((l10 >= l1)) {
                    vader_struct_std_string$ParseError_t* _a2_obj = (vader_struct_std_string$ParseError_t*) vader_gc_alloc(sizeof(vader_struct_std_string$ParseError_t));
                    vader_obj_header_init(_a2_obj, 875u);
                    _a2_obj->f_msg = 2343u;
                    t1 = (void*) _a2_obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                if ((l2 > l4)) {
                    l12 = true;
                } else {
                    if (l2 == l4) {
                        l13 = (((int64_t) (int32_t) l10) > l5);
                    } else {
                        l13 = false;
                    }
                    l12 = l13;
                }
                if (l12) {
                    vader_struct_std_string$ParseError_t* _a3_obj = (vader_struct_std_string$ParseError_t*) vader_gc_alloc(sizeof(vader_struct_std_string$ParseError_t));
                    vader_obj_header_init(_a3_obj, 875u);
                    _a3_obj->f_msg = 2608u;
                    t1 = (void*) _a3_obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                t2 = vader_chk_mul(u64, l2, l3);
                l14 = (uint64_t) (int64_t) t2;
                t2 = ((int64_t) (int32_t) l10);
                l15 = (uint64_t) (int64_t) t2;
                t2 = vader_chk_add(u64, l14, l15);
                l2 = (uint64_t) (int64_t) t2;
                continue;
            }
            std_core$decode_tail(l6, l9, l7, &t3, &t2);
            l25 = t2;
            l16 = t3;
            l17 = l25;
            l7 = vader_chk_add(i64, l7, l17);
            if ((l16 > INT32_C(55295))) {
                if ((l16 < INT32_C(57344))) {
                    l18 = true;
                } else {
                    l18 = (l16 > INT32_C(1114111));
                }
                if (l18) {
                    vader_unreachable("value out of range: no Unicode scalar value");
                }
            }
            l20 = std_numbers$hex_digit_value(((uint32_t) (uint32_t) l16));
            if (l20.tag == 0u) {
                vader_struct_std_string$ParseError_t* _a4_obj = (vader_struct_std_string$ParseError_t*) vader_gc_alloc(sizeof(vader_struct_std_string$ParseError_t));
                vader_obj_header_init(_a4_obj, 875u);
                _a4_obj->f_msg = 2343u;
                t1 = (void*) _a4_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l19 = ((int32_t) l20.payload.i);
            if ((l19 >= l1)) {
                vader_struct_std_string$ParseError_t* _a5_obj = (vader_struct_std_string$ParseError_t*) vader_gc_alloc(sizeof(vader_struct_std_string$ParseError_t));
                vader_obj_header_init(_a5_obj, 875u);
                _a5_obj->f_msg = 2343u;
                t1 = (void*) _a5_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if ((l2 > l4)) {
                l21 = true;
            } else {
                if (l2 == l4) {
                    l22 = (((int64_t) (int32_t) l19) > l5);
                } else {
                    l22 = false;
                }
                l21 = l22;
            }
            if (l21) {
                vader_struct_std_string$ParseError_t* _a6_obj = (vader_struct_std_string$ParseError_t*) vader_gc_alloc(sizeof(vader_struct_std_string$ParseError_t));
                vader_obj_header_init(_a6_obj, 875u);
                _a6_obj->f_msg = 2608u;
                t1 = (void*) _a6_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t2 = vader_chk_mul(u64, l2, l3);
            l23 = (uint64_t) (int64_t) t2;
            t2 = ((int64_t) (int32_t) l19);
            l24 = (uint64_t) (int64_t) t2;
            t2 = vader_chk_add(u64, l23, l24);
            l2 = (uint64_t) (int64_t) t2;
            continue;
        }
        break;
    }
    { vader_box_t __vret = vader_box_i64(507u, (int64_t)(uint64_t) l2); vader_gc_top = gc_frame.prev; return __vret; }
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
    t0 = std_string$string$std_core$Contains$contains(l4, 1047u);
    if (!(t0)) {
        { vader_string_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = (void*) &vader_fn_static___lambda_std_numbers_0;
    t1 = std_string$replace_chars_where(l4, l5, 0u);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t std_numbers$to_hex(uint64_t l0) {
    vader_string_t t0;
    t0 = std_numbers$digits_in_base(l0, (uint64_t) 16, false);
    return t0;
}
