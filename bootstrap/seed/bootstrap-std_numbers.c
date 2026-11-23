#include "bootstrap.split.h"

static uint32_t std_numbers$digit_char(uint64_t l0, bool l1);
static vader_string_t std_numbers$digits_in_base(uint64_t l0, uint64_t l1, bool l2);
static void* std_numbers$digits_of(vader_string_t l0, int64_t l1);
static int64_t std_numbers$exponent_value(vader_string_t l0);
static vader_string_t std_numbers$format_1(double l0, void* l1);
static vader_string_t std_numbers$fraction_digits(void* l0);
static vader_string_t std_numbers$grouped(vader_string_t l0, vader_string_t l1, int64_t l2);
static vader_string_t std_numbers$integer_digits(void* l0);
static vader_string_t std_numbers$notation_text(void* l0, void* l1, int64_t l2);
static vader_box_t std_numbers$parse_int_in_base_1(void* l0, int32_t l1);
static vader_box_t std_numbers$parse_uint_in_base_1(void* l0, int32_t l1);
static void* std_numbers$round_at(void* l0, int64_t l1);
static void* std_numbers$rounded_for(void* l0, void* l1, int64_t l2);
static vader_string_t std_numbers$scientific_text(void* l0, int64_t l1);
static void* std_numbers$shortest_digits(double l0);
static vader_string_t std_numbers$sign_text(bool l0, uint8_t l1);
static void* std_numbers$trimmed(vader_string_t l0, int64_t l1);
static vader_string_t std_numbers$with_point(vader_string_t l0, vader_string_t l1, int64_t l2);

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
        { vader_gc_top = gc_frame.prev; return 529u; }
    }
    vader_array_t* _a0_arr = vader_array_new(27u, 0u, 11u, 602u);
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
    vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 603u);
    t1 = (void*) _a1_arr;
    vader_struct_std_string__builder$StringBuilder_t* _a2_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
    vader_obj_header_init(_a2_obj, 1061u);
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

static void* std_numbers$digits_of(vader_string_t l0, int64_t l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    vader_string_t l4 = 0;
    vader_string_t l5 = 0;
    int64_t l6;
    vader_string_t t0 = 0;
    int64_t t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[2] = { &l2, &t2 };
    vader_struct___Tuple_string_string_66940ed4_t _a0_storage = {0};
    void* gc_stack_objs[1] = { (void*) &_a0_storage };
    vader_string_t* gc_atom_roots[4] = { &l0, &l4, &l5, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 1u, gc_stack_objs, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = std_string$split_first(l0, 472u);
    if (l3.tag == 0u) {
        vader_struct___Tuple_string_string_66940ed4_t* _a1_obj = &_a0_storage;
        vader_obj_header_init(_a1_obj, 630u);
        _a1_obj->f__0 = l0;
        _a1_obj->f__1 = 0u;
        l2 = (void*) _a1_obj;
    } else {
        l2 = l3.payload.obj;
    }
    l4 = ((vader_struct___Tuple_string_string_66940ed4_t*) l2)->f__0;
    l5 = ((vader_struct___Tuple_string_string_66940ed4_t*) l2)->f__1;
    l4 = concat_2(l4, l5);
    t0 = ((vader_struct___Tuple_string_string_66940ed4_t*) l2)->f__0;
    t1 = vader_host_std_core$Intrinsic$byte_len(t0);
    l6 = vader_chk_add(i64, t1, l1);
    t2 = std_numbers$trimmed(l4, l6);
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static int64_t std_numbers$exponent_value(vader_string_t l0) {
    void* l1 = NULL;
    int64_t l2, l3, l4, l5, l6;
    vader_box_t t0 = vader_box_null();
    uint8_t t1;
    int32_t t2;
    int64_t t3;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[1] = { &l1 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_host_std_core$Intrinsic$bytes(l0);
    l2 = INT64_C(0);
    l3 = INT64_C(1);
    l4 = vader_array_length(((vader_array_t*) l1));
    while ((l3 < l4)) {
        l5 = vader_chk_mul(i64, l2, INT64_C(10));
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_read_u8(_a0_slotarr, vader_array_offset(_a0_slotarr) + (size_t) l3, 608u);
        t1 = ((uint8_t) t0.payload.i);
        t2 = vader_chk_sub(u8, t1, INT32_C(48));
        l6 = ((int64_t) (uint32_t) t2);
        l2 = vader_chk_add(i64, l5, l6);
        l3 = (l3 + INT64_C(1));
    }
    vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
    t0 = vader_array_read_u8(_a1_slotarr, vader_array_offset(_a1_slotarr) + (size_t) INT32_C(0), 608u);
    t1 = ((uint8_t) t0.payload.i);
    if (!(t1 == INT32_C(45))) {
        { int64_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t3 = vader_chk_neg(i64, l2);
    { int64_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t std_numbers$format_1(double l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    int64_t l3;
    void* l4 = NULL;
    bool l5;
    vader_string_t l6 = 0;
    vader_string_t l7 = 0;
    uint8_t l8;
    bool t0;
    vader_string_t t1 = 0;
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[3] = { &l1, &l4, &t2 };
    vader_string_t* gc_atom_roots[3] = { &l6, &l7, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = std_math$is_finite(l0);
    if (!(t0)) {
        t1 = std_core$f64$Display$to_string(l0);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_std_numbers$DecimalFormat_t*) l1)->f_decimals;
    if (l2.tag == 0u) {
        l3 = INT64_C(0);
    } else {
        l3 = ((int64_t) l2.payload.i);
    }
    l3 = std_math$max__i64(l3, INT64_C(0));
    t2 = std_numbers$shortest_digits(l0);
    l4 = std_numbers$rounded_for(t2, l1, l3);
    if ((l0 < 0.0)) {
        l6 = ((vader_struct_std_numbers$DecimalDigits_t*) l4)->f_digits;
        t2 = (void*) &vader_data_61;
        vader_array_t* _a0_slotarr = ((vader_array_t*) t2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t2 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT64_C(0));
        l7 = ((vader_struct_std_numbers$DecimalDigits_t*) t2)->f_digits;
        l5 = l6 != l7;
    } else {
        l5 = false;
    }
    l8 = ((vader_struct_std_numbers$DecimalFormat_t*) l1)->f_sign;
    l6 = std_numbers$sign_text(l5, l8);
    l7 = std_numbers$notation_text(l4, l1, l3);
    t1 = concat_2(l6, l7);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t std_numbers$fraction_digits(void* l0) {
    int64_t l1, l3;
    vader_string_t l2 = 0;
    vader_string_t t0 = 0;
    int64_t t1;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l2, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_std_numbers$DecimalDigits_t*) l0)->f_digits;
    l1 = vader_host_std_core$Intrinsic$byte_len(t0);
    t1 = ((vader_struct_std_numbers$DecimalDigits_t*) l0)->f_point;
    if ((t1 >= l1)) {
        { vader_gc_top = gc_frame.prev; return 0u; }
    }
    t1 = ((vader_struct_std_numbers$DecimalDigits_t*) l0)->f_point;
    if (!((t1 < INT64_C(0)))) {
        l2 = ((vader_struct_std_numbers$DecimalDigits_t*) l0)->f_digits;
        l3 = ((vader_struct_std_numbers$DecimalDigits_t*) l0)->f_point;
        t0 = vader_host_std_core$Intrinsic$byte_slice(l2, l3, l1);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_std_numbers$DecimalDigits_t*) l0)->f_digits;
    l3 = ((vader_struct_std_numbers$DecimalDigits_t*) l0)->f_point;
    l1 = vader_chk_sub(i64, l1, l3);
    t0 = std_string$pad_start(l2, l1, 48u);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t std_numbers$grouped(vader_string_t l0, vader_string_t l1, int64_t l2) {
    int64_t l3, l4, l7;
    void* l5 = NULL;
    vader_string_t l6 = 0;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    void** gc_raw_roots[2] = { &l5, &t0 };
    vader_string_t* gc_atom_roots[4] = { &l0, &l1, &l6, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_host_std_core$Intrinsic$byte_len(l0);
    if (l1 == 0u) {
        { vader_string_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if ((l2 <= INT64_C(0))) {
        { vader_string_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if ((l3 <= l2)) {
        { vader_string_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = vader_mod_i64(l3, l2);
    if (l4 == INT64_C(0)) {
        l4 = l2;
    }
    vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 603u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string__builder$StringBuilder_t* _a1_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
    vader_obj_header_init(_a1_obj, 1061u);
    _a1_obj->f_parts = t0;
    l5 = (void*) _a1_obj;
    l6 = vader_host_std_core$Intrinsic$byte_slice(l0, INT64_C(0), l4);
    std_string__builder$append(l5, l6);
    while ((l4 < l3)) {
        std_string__builder$append(l5, l1);
        l7 = vader_chk_add(i64, l4, l2);
        l6 = vader_host_std_core$Intrinsic$byte_slice(l0, l4, l7);
        std_string__builder$append(l5, l6);
        l4 = vader_chk_add(i64, l4, l2);
    }
    t1 = std_string__builder$StringBuilder$std_core$Display$to_string(l5);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
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
        l1 = vader_box_i32(606u, ((int32_t) t0));
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
        l1 = vader_box_i32(606u, ((int32_t) t1));
    } else {
        if ((l0 >= 65u)) {
            l2 = (l0 <= 70u);
        } else {
            l2 = false;
        }
        if (l2) {
            t0 = vader_chk_sub(u32, ((int32_t) (uint32_t) l0), INT32_C(65));
            t1 = vader_chk_add(u32, t0, INT32_C(10));
            l1 = vader_box_i32(606u, ((int32_t) t1));
        } else {
            l1 = vader_box_obj(0u, NULL);
        }
    }
    return l1;
}

static vader_string_t std_numbers$integer_digits(void* l0) {
    int64_t l1, l2;
    vader_string_t l3 = 0;
    int64_t t0;
    vader_string_t t1 = 0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l3, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_std_numbers$DecimalDigits_t*) l0)->f_point;
    if ((t0 <= INT64_C(0))) {
        { vader_gc_top = gc_frame.prev; return 529u; }
    }
    l1 = ((vader_struct_std_numbers$DecimalDigits_t*) l0)->f_point;
    t1 = ((vader_struct_std_numbers$DecimalDigits_t*) l0)->f_digits;
    l2 = vader_host_std_core$Intrinsic$byte_len(t1);
    if (!((l1 >= l2))) {
        l3 = ((vader_struct_std_numbers$DecimalDigits_t*) l0)->f_digits;
        l2 = ((vader_struct_std_numbers$DecimalDigits_t*) l0)->f_point;
        t1 = vader_host_std_core$Intrinsic$byte_slice(l3, INT64_C(0), l2);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((vader_struct_std_numbers$DecimalDigits_t*) l0)->f_digits;
    l1 = ((vader_struct_std_numbers$DecimalDigits_t*) l0)->f_point;
    t1 = std_string$pad_end(l3, l1, 48u);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
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

static vader_string_t std_numbers$notation_text(void* l0, void* l1, int64_t l2) {
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    int64_t l5;
    vader_string_t t0 = 0;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[3] = { &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!(((vader_struct_std_numbers$DecimalFormat_t*) l1)->f_notation == INT32_C(1))) {
        l3 = std_numbers$integer_digits(l0);
        l4 = ((vader_struct_std_numbers$DecimalFormat_t*) l1)->f_separator;
        l5 = ((vader_struct_std_numbers$DecimalFormat_t*) l1)->f_group;
        l3 = std_numbers$grouped(l3, l4, l5);
        l4 = std_numbers$fraction_digits(l0);
        t0 = std_numbers$with_point(l3, l4, l2);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = std_numbers$scientific_text(l0, l2);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t std_numbers$parse_int_in_base(vader_string_t l0, int32_t l1) {
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_host_std_core$Intrinsic$bytes(l0);
    t1 = std_numbers$parse_int_in_base_1(t0, l1);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t std_numbers$parse_int_in_base_1(void* l0, int32_t l1) {
    uint64_t l2, l5;
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null();
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[2] = { &l3, &l4 };
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = std_numbers$parse_uint_in_base_1(l0, l1);
    l4 = l3;
    if (l3.tag == 1059u) {
        t0 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((uint64_t) l3.payload.i);
    t1 = INT64_C(9223372036854775807);
    l5 = (uint64_t) (int64_t) t1;
    if (!((l2 > l5))) {
        { vader_box_t __vret = vader_box_i64(607u, ((int64_t) (uint64_t) l2)); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_std_string$ParseError_t* _a0_obj = (vader_struct_std_string$ParseError_t*) vader_gc_alloc(sizeof(vader_struct_std_string$ParseError_t));
    vader_obj_header_init(_a0_obj, 1059u);
    _a0_obj->f_msg = 2951u;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t std_numbers$parse_uint_in_base(vader_string_t l0, int32_t l1) {
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_host_std_core$Intrinsic$bytes(l0);
    t1 = std_numbers$parse_uint_in_base_1(t0, l1);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t std_numbers$parse_uint_in_base_1(void* l0, int32_t l1) {
    uint64_t l2, l3, l4, l5, l13, l14;
    void* l6 = NULL;
    int64_t l7, l8;
    uint8_t l9;
    vader_box_t l10 = vader_box_null();
    bool l11, l12;
    bool t0;
    void* t1 = NULL;
    int64_t t2;
    vader_box_t t3 = vader_box_null();
    uint8_t t4;
    vader_box_t* gc_roots[2] = { &l10, &t3 };
    void** gc_raw_roots[3] = { &l0, &l6, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = std_core$is_empty__u8(l0);
    if (t0) {
        vader_struct_std_string$ParseError_t* _a0_obj = (vader_struct_std_string$ParseError_t*) vader_gc_alloc(sizeof(vader_struct_std_string$ParseError_t));
        vader_obj_header_init(_a0_obj, 1059u);
        _a0_obj->f_msg = 2319u;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = (uint64_t) 0;
    t2 = ((int64_t) (int32_t) l1);
    l3 = (uint64_t) (int64_t) t2;
    l4 = vader_div_u64(INT64_C(-1), l3);
    l5 = vader_mod_u64(INT64_C(-1), l3);
    l6 = l0;
    l7 = vader_array_length(((vader_array_t*) l6));
    l8 = INT64_C(0);
    while ((l8 < l7)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t3 = vader_array_read_u8(_a1_slotarr, vader_array_offset(_a1_slotarr) + (size_t) l8, 608u);
        t4 = ((uint8_t) t3.payload.i);
        l10 = std_ascii$hex_value(t4);
        if (l10.tag == 0u) {
            vader_struct_std_string$ParseError_t* _a2_obj = (vader_struct_std_string$ParseError_t*) vader_gc_alloc(sizeof(vader_struct_std_string$ParseError_t));
            vader_obj_header_init(_a2_obj, 1059u);
            _a2_obj->f_msg = 2679u;
            t1 = (void*) _a2_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l9 = ((uint8_t) l10.payload.i);
        if ((((int32_t) (uint8_t) l9) >= l1)) {
            vader_struct_std_string$ParseError_t* _a3_obj = (vader_struct_std_string$ParseError_t*) vader_gc_alloc(sizeof(vader_struct_std_string$ParseError_t));
            vader_obj_header_init(_a3_obj, 1059u);
            _a3_obj->f_msg = 2679u;
            t1 = (void*) _a3_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if ((l2 > l4)) {
            l11 = true;
        } else {
            if (l2 == l4) {
                l12 = (((int64_t) (uint8_t) l9) > l5);
            } else {
                l12 = false;
            }
            l11 = l12;
        }
        if (l11) {
            vader_struct_std_string$ParseError_t* _a4_obj = (vader_struct_std_string$ParseError_t*) vader_gc_alloc(sizeof(vader_struct_std_string$ParseError_t));
            vader_obj_header_init(_a4_obj, 1059u);
            _a4_obj->f_msg = 2951u;
            t1 = (void*) _a4_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = vader_chk_mul(u64, l2, l3);
        l13 = (uint64_t) (int64_t) t2;
        t2 = ((int64_t) (uint8_t) l9);
        l14 = (uint64_t) (int64_t) t2;
        t2 = vader_chk_add(u64, l13, l14);
        l2 = (uint64_t) (int64_t) t2;
        l8 = (l8 + INT64_C(1));
    }
    { vader_box_t __vret = vader_box_i64(611u, (int64_t)(uint64_t) l2); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* std_numbers$round_at(void* l0, int64_t l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    int64_t l3, l7;
    vader_string_t l4 = 0;
    uint32_t l6;
    vader_string_t t0 = 0;
    vader_box_t t1 = vader_box_null();
    uint8_t t2;
    void* t3 = NULL;
    int32_t t4;
    int64_t t5;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[4] = { &l0, &l2, &l5, &t3 };
    vader_string_t* gc_atom_roots[2] = { &l4, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_std_numbers$DecimalDigits_t*) l0)->f_digits;
    l2 = vader_host_std_core$Intrinsic$bytes(t0);
    l3 = vader_array_length(((vader_array_t*) l2));
    if ((l1 >= l3)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    {
        if (!((l1 < INT64_C(0)))) {
            if (l1 == INT64_C(0)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
                t1 = vader_array_read_u8(_a0_slotarr, vader_array_offset(_a0_slotarr) + (size_t) INT32_C(0), 608u);
                t2 = ((uint8_t) t1.payload.i);
                if ((t2 < INT32_C(53))) goto end_13;
            }
            vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            t1 = vader_array_read_u8(_a1_slotarr, vader_array_offset(_a1_slotarr) + (size_t) l1, 608u);
            t2 = ((uint8_t) t1.payload.i);
            if ((t2 < INT32_C(53))) {
                t0 = ((vader_struct_std_numbers$DecimalDigits_t*) l0)->f_digits;
                l4 = vader_host_std_core$Intrinsic$byte_slice(t0, INT64_C(0), l1);
                l3 = ((vader_struct_std_numbers$DecimalDigits_t*) l0)->f_point;
                t3 = std_numbers$trimmed(l4, l3);
                { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
            }
            l3 = vader_chk_sub(i64, l1, INT64_C(1));
            while ((l3 >= INT64_C(0))) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                t1 = vader_array_read_u8(_a2_slotarr, vader_array_offset(_a2_slotarr) + (size_t) l3, 608u);
                t2 = ((uint8_t) t1.payload.i);
                if (!(t2 == INT32_C(57))) {
                    break;
                }
                l3 = vader_chk_sub(i64, l3, INT64_C(1));
            }
            if (!((l3 < INT64_C(0)))) {
                vader_array_t* _a3_arr = vader_array_new(28u, 0u, 0u, 603u);
                t3 = (void*) _a3_arr;
                vader_struct_std_string__builder$StringBuilder_t* _a4_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
                vader_obj_header_init(_a4_obj, 1061u);
                _a4_obj->f_parts = t3;
                l5 = (void*) _a4_obj;
                t0 = ((vader_struct_std_numbers$DecimalDigits_t*) l0)->f_digits;
                l4 = vader_host_std_core$Intrinsic$byte_slice(t0, INT64_C(0), l3);
                std_string__builder$append(l5, l4);
                vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                t1 = vader_array_read_u8(_a5_slotarr, vader_array_offset(_a5_slotarr) + (size_t) l3, 608u);
                t2 = ((uint8_t) t1.payload.i);
                t4 = vader_chk_add(u8, t2, INT32_C(1));
                l6 = ((uint32_t) (int32_t) t4);
                std_string__builder$append_char(l5, l6);
                l4 = std_string__builder$StringBuilder$std_core$Display$to_string(l5);
                l7 = ((vader_struct_std_numbers$DecimalDigits_t*) l0)->f_point;
                vader_struct_std_numbers$DecimalDigits_t* _a6_obj = (vader_struct_std_numbers$DecimalDigits_t*) vader_gc_alloc(sizeof(vader_struct_std_numbers$DecimalDigits_t));
                vader_obj_header_init(_a6_obj, 1056u);
                _a6_obj->f_digits = l4;
                _a6_obj->f_point = l7;
                t3 = (void*) _a6_obj;
                { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
            }
            t5 = ((vader_struct_std_numbers$DecimalDigits_t*) l0)->f_point;
            l3 = vader_chk_add(i64, t5, INT64_C(1));
            vader_struct_std_numbers$DecimalDigits_t* _a7_obj = (vader_struct_std_numbers$DecimalDigits_t*) vader_gc_alloc(sizeof(vader_struct_std_numbers$DecimalDigits_t));
            vader_obj_header_init(_a7_obj, 1056u);
            _a7_obj->f_digits = 534u;
            _a7_obj->f_point = l3;
            t3 = (void*) _a7_obj;
            { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
        }
    } end_13: ;
    t3 = (void*) &vader_data_61;
    vader_array_t* _a8_slotarr = ((vader_array_t*) t3);
    VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
    t3 = vader_array_ref_load_obj(_a8_slotarr->buf, vader_array_offset(_a8_slotarr) + (size_t) INT64_C(0));
    { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* std_numbers$rounded_for(void* l0, void* l1, int64_t l2) {
    int64_t l3;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (((vader_struct_std_numbers$DecimalFormat_t*) l1)->f_decimals.tag == 0u) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(((vader_struct_std_numbers$DecimalFormat_t*) l1)->f_notation == INT32_C(1))) {
        t0 = ((vader_struct_std_numbers$DecimalDigits_t*) l0)->f_point;
        l3 = vader_chk_add(i64, t0, l2);
        t1 = std_numbers$round_at(l0, l3);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = vader_chk_add(i64, INT64_C(1), l2);
    t1 = std_numbers$round_at(l0, l3);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t std_numbers$scientific_text(void* l0, int64_t l1) {
    int64_t l2, l5, l6;
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    void* l7 = NULL;
    vader_string_t t0 = 0;
    int64_t t1;
    void** gc_raw_roots[2] = { &l0, &l7 };
    vader_string_t* gc_atom_roots[3] = { &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_std_numbers$DecimalDigits_t*) l0)->f_digits;
    l2 = vader_host_std_core$Intrinsic$byte_len(t0);
    t0 = ((vader_struct_std_numbers$DecimalDigits_t*) l0)->f_digits;
    l3 = vader_host_std_core$Intrinsic$byte_slice(t0, INT64_C(0), INT64_C(1));
    t0 = ((vader_struct_std_numbers$DecimalDigits_t*) l0)->f_digits;
    l4 = vader_host_std_core$Intrinsic$byte_slice(t0, INT64_C(1), l2);
    l3 = std_numbers$with_point(l3, l4, l1);
    t1 = ((vader_struct_std_numbers$DecimalDigits_t*) l0)->f_point;
    l2 = vader_chk_sub(i64, t1, INT64_C(1));
    l4 = std_numbers$sign_text((l2 < INT64_C(0)), (uint8_t) 1);
    l5 = vader_host_std_core$Intrinsic$byte_len(l3);
    l6 = vader_host_std_core$Intrinsic$byte_len(l4);
    l5 = (l5 + l6);
    l7 = (void*) vader_buffer_new((size_t) (INT64_C(21) + l5));
    l5 = INT64_C(0);
    l5 = std_core$write_string_at(l7, l5, l3);
    l5 = std_core$write_string_at(l7, l5, 2292u);
    l5 = std_core$write_string_at(l7, l5, l4);
    l2 = std_math$abs_2(l2);
    l5 = std_core$write_int(l7, l5, l2);
    t0 = std_core$finish_buffer(l7, l5);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* std_numbers$shortest_digits(double l0) {
    vader_string_t l1 = 0;
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    int64_t l4;
    vader_string_t t0 = 0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[2] = { &l2, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = std_core$f64$Display$to_string(l0);
    l1 = std_string$trim_prefix(t0, 459u);
    l3 = std_string$split_first(l1, 2292u);
    if (l3.tag == 0u) {
        t1 = std_numbers$digits_of(l1, INT64_C(0));
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = l3.payload.obj;
    l1 = ((vader_struct___Tuple_string_string_66940ed4_t*) l2)->f__0;
    t0 = ((vader_struct___Tuple_string_string_66940ed4_t*) l2)->f__1;
    l4 = std_numbers$exponent_value(t0);
    t1 = std_numbers$digits_of(l1, l4);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t std_numbers$sign_text(bool l0, uint8_t l1) {
    if (l0) {
        return 459u;
    }
    if (!(l1 == INT32_C(1))) {
        return 0u;
    }
    return 417u;
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
    l3 = vader_host_std_core$Intrinsic$byte_len(l0);
    l4 = vader_host_std_core$Intrinsic$byte_slice(l0, l2, l3);
    t0 = std_string$string$std_core$Contains$contains(l4, 1208u);
    if (!(t0)) {
        { vader_string_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = (void*) &vader_fn_static___lambda_std_numbers_0;
    t1 = std_string$replace_chars_where(l4, l5, 0u);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t std_numbers$to_fixed(double l0, int64_t l1) {
    void* l2 = NULL;
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l2 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_std_numbers$DecimalFormat_t* _a0_obj = (vader_struct_std_numbers$DecimalFormat_t*) vader_gc_alloc(sizeof(vader_struct_std_numbers$DecimalFormat_t));
    vader_obj_header_init(_a0_obj, 1057u);
    _a0_obj->f_sign = (uint8_t) 0;
    _a0_obj->f_separator = 0u;
    _a0_obj->f_group = INT64_C(3);
    _a0_obj->f_notation = (uint8_t) 0;
    _a0_obj->f_decimals = vader_box_i64(607u, l1);
    l2 = (void*) _a0_obj;
    t0 = std_numbers$format_1(l0, l2);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t std_numbers$to_hex(uint64_t l0) {
    vader_string_t t0;
    t0 = std_numbers$digits_in_base(l0, (uint64_t) 16, false);
    return t0;
}

static void* std_numbers$trimmed(vader_string_t l0, int64_t l1) {
    void* l2 = NULL;
    int64_t l3, l4, l5;
    vader_string_t l6 = 0;
    vader_box_t t0 = vader_box_null();
    uint8_t t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l2, &t2 };
    vader_string_t* gc_atom_roots[2] = { &l0, &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_host_std_core$Intrinsic$bytes(l0);
    l3 = INT64_C(0);
    for (;;) {
        l4 = vader_array_length(((vader_array_t*) l2));
        if ((l3 < l4)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            t0 = vader_array_read_u8(_a0_slotarr, vader_array_offset(_a0_slotarr) + (size_t) l3, 608u);
            t1 = ((uint8_t) t0.payload.i);
            if (!(t1 == INT32_C(48))) {
                break;
            }
            l3 = vader_chk_add(i64, l3, INT64_C(1));
            continue;
        }
        break;
    }
    l4 = vader_array_length(((vader_array_t*) l2));
    while ((l4 > l3)) {
        l5 = vader_chk_sub(i64, l4, INT64_C(1));
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t0 = vader_array_read_u8(_a1_slotarr, vader_array_offset(_a1_slotarr) + (size_t) l5, 608u);
        t1 = ((uint8_t) t0.payload.i);
        if (!(t1 == INT32_C(48))) {
            break;
        }
        l4 = vader_chk_sub(i64, l4, INT64_C(1));
    }
    if (!(l3 == l4)) {
        l6 = vader_host_std_core$Intrinsic$byte_slice(l0, l3, l4);
        l3 = vader_chk_sub(i64, l1, l3);
        vader_struct_std_numbers$DecimalDigits_t* _a2_obj = (vader_struct_std_numbers$DecimalDigits_t*) vader_gc_alloc(sizeof(vader_struct_std_numbers$DecimalDigits_t));
        vader_obj_header_init(_a2_obj, 1056u);
        _a2_obj->f_digits = l6;
        _a2_obj->f_point = l3;
        t2 = (void*) _a2_obj;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = (void*) &vader_data_61;
    vader_array_t* _a3_slotarr = ((vader_array_t*) t2);
    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
    t2 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) INT64_C(0));
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t std_numbers$with_point(vader_string_t l0, vader_string_t l1, int64_t l2) {
    vader_string_t l3 = 0;
    vader_string_t t0 = 0;
    vader_string_t* gc_atom_roots[4] = { &l0, &l1, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = std_string$pad_end(l1, l2, 48u);
    if (!(l3 == 0u)) {
        t0 = concat_3(l0, 472u, l3);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_string_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
}
