#include "bootstrap.split.h"

static void* std_core_BigInt_Div_div(void* l0, uint32_t l1);
static void* std_core_BigInt_Mul_mul(void* l0, uint32_t l1);
static bool std_core_any_below(void* l0, int32_t l1);
static int64_t std_core_ascii_prefix(vader_string_t l0);
static int32_t std_core_b2i(bool l0);
static uint64_t std_core_b2u(bool l0);
static int32_t std_core_bit_len(void* l0);
static uint64_t std_core_bits64(void* l0, int32_t l1);
static bool std_core_bool_Equals_equals_guard(bool l0, vader_box_t l1);
static bool std_core_char_Equals_equals_guard(uint32_t l0, vader_box_t l1);
static uint64_t std_core_char_Hash_hash(uint32_t l0);
static int32_t std_core_clz32(uint32_t l0);
static int64_t std_core_codepoint_count(void* l0);
static int64_t std_core_codepoint_offset(vader_string_t l0, int64_t l1, int64_t l2);
static void* std_core_d2d(uint64_t l0, uint64_t l1);
static int32_t std_core_decimal_width(uint64_t l0);
static uint64_t std_core_eisel_lemire(uint64_t l0, int32_t l1);
static bool std_core_f32_Equals_equals_guard(float l0, vader_box_t l1);
static bool std_core_f64_Equals_equals_guard(double l0, vader_box_t l1);
static vader_string_t std_core_format_f64(double l0);
static vader_string_t std_core_format_unsigned(uint64_t l0);
static bool std_core_i16_Equals_equals_guard(int16_t l0, vader_box_t l1);
static uint64_t std_core_i16_Hash_hash(int16_t l0);
static bool std_core_i32_Equals_equals_guard(int32_t l0, vader_box_t l1);
static bool std_core_i64_Equals_equals_guard(int64_t l0, vader_box_t l1);
static bool std_core_i8_Equals_equals_guard(int8_t l0, vader_box_t l1);
static uint64_t std_core_i8_Hash_hash(int8_t l0);
static int64_t std_core_insert_point(void* l0, int64_t l1, int32_t l2, int32_t l3);
static bool std_core_is_utf8_continuation(uint8_t l0);
static bool std_core_is_zero(void* l0);
static uint64_t std_core_limb(void* l0, int64_t l1);
static int32_t std_core_log10_pow2(int32_t l0);
static int32_t std_core_log10_pow5(int32_t l0);
static void* std_core_mul_add_small(void* l0, uint32_t l1, uint32_t l2);
static void* std_core_mul_shift_all_64(uint64_t l0, uint64_t l1, uint64_t l2, int32_t l3, uint64_t l4);
static bool std_core_multiple_of_power_of_2(uint64_t l0, int32_t l1);
static bool std_core_multiple_of_power_of_5(uint64_t l0, int32_t l1);
static double std_core_parse_f64_slow(vader_string_t l0, bool l1);
static int32_t std_core_pf_clz64(uint64_t l0);
static bool std_core_pf_is_digit(uint8_t l0);
static void std_core_pf_product(int32_t l0, uint64_t l1, uint64_t* __o0, uint64_t* __o1);
static int32_t std_core_pow5_factor(uint64_t l0);
static int32_t std_core_pow5bits(int32_t l0);
static vader_string_t std_core_render(uint64_t l0, int32_t l1, bool l2);
static vader_box_t std_core_scan_decimal(vader_string_t l0);
static uint64_t std_core_sd_round_at(void* l0, int32_t l1, bool l2);
static void* std_core_sd_scan(vader_string_t l0);
static uint64_t std_core_shiftright128(uint64_t l0, uint64_t l1, uint64_t l2);
static void* std_core_shl(void* l0, int32_t l1);
static bool std_core_string_Equals_equals_guard(vader_string_t l0, vader_box_t l1);
static bool std_core_u16_Equals_equals_guard(uint16_t l0, vader_box_t l1);
static uint64_t std_core_u16_Hash_hash(uint16_t l0);
static bool std_core_u32_Equals_equals_guard(uint32_t l0, vader_box_t l1);
static uint64_t std_core_u32_Hash_hash(uint32_t l0);
static bool std_core_u64_Equals_equals_guard(uint64_t l0, vader_box_t l1);
static bool std_core_u8_Equals_equals_guard(uint8_t l0, vader_box_t l1);
static uint64_t std_core_u8_Hash_hash(uint8_t l0);
static void std_core_umul128(uint64_t l0, uint64_t l1, uint64_t* __o0, uint64_t* __o1);
static int64_t std_core_write_decimal(void* l0, int64_t l1, uint64_t l2, int32_t l3);
static int64_t std_core_write_digits(void* l0, int64_t l1, uint64_t l2, int32_t l3);
static int64_t std_core_write_zeros(void* l0, int64_t l1, int32_t l2);

static void* std_core_BigInt_Div_div(void* l0, uint32_t l1) {
    void* l2 = NULL;
    void* l11 = NULL;
    uint64_t l3, l5, l6, l7, l8, l10;
    int64_t l4;
    uint32_t l9;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    uint32_t t2;
    uint64_t t3;
    int32_t t4;
    void* t5 = NULL;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[4] = { &l0, &l2, &l11, &t5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(19u, 0u, 3u, 295u);
    l2 = (void*) _a0_arr;
    l3 = (uint64_t) 0;
    t0 = ((vader_array_t*) l0)->length;
    l4 = vader_chk_sub(i64, t0, INT64_C(1));
    vader_array_t* _pc9_hdr = (vader_array_t*) l2;
    size_t _pc9_len = _pc9_hdr->length;
    size_t _pc9_cap = (_pc9_hdr->offset == 0 && !vader_array_is_borrowed(_pc9_hdr) && _pc9_hdr->length >= _pc9_hdr->buf->length) ? _pc9_hdr->capacity : (size_t) 0;
    void* _pc9_slots = _pc9_hdr->buf->slots;
    for (;;) {
        if ((l4 >= INT64_C(0))) {
            t0 = (l3 << INT64_C(32));
            l5 = (uint64_t) (int64_t) t0;
            vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
            t1 = vader_box_i32(295u, ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4]);
            t2 = ((uint32_t) t1.payload.i);
            t0 = ((int64_t) (uint32_t) t2);
            l6 = (uint64_t) (int64_t) t0;
            t0 = (l5 | l6);
            l7 = (uint64_t) (int64_t) t0;
            t0 = ((int64_t) (uint32_t) l1);
            l8 = (uint64_t) (int64_t) t0;
            t3 = vader_div_u64(l7, l8);
            t4 = ((int32_t) (uint64_t) t3);
            l9 = (uint32_t) (int32_t) t4;
            if (VADER_LIKELY(_pc9_len < _pc9_cap)) {
                ((int32_t*) _pc9_slots)[_pc9_len] = (int32_t) ((int32_t) (uint32_t) l9);
                _pc9_len += 1;
            } else {
                _pc9_hdr->length = _pc9_len;
                if (_pc9_hdr->buf->length < _pc9_len) {
                    _pc9_hdr->buf->length = _pc9_len;
                }
                vader_array_push_i32((vader_array_t*) l2, (int32_t) (uint32_t) l9);
                _pc9_hdr = (vader_array_t*) l2;
                _pc9_len = _pc9_hdr->length;
                _pc9_cap = (_pc9_hdr->offset == 0 && !vader_array_is_borrowed(_pc9_hdr) && _pc9_hdr->length >= _pc9_hdr->buf->length) ? _pc9_hdr->capacity : (size_t) 0;
                _pc9_slots = _pc9_hdr->buf->slots;
            }
            t0 = ((int64_t) (uint32_t) l1);
            l10 = (uint64_t) (int64_t) t0;
            l3 = vader_mod_u64(l7, l10);
            l4 = vader_chk_sub(i64, l4, INT64_C(1));
            continue;
        }
        _pc9_hdr->length = _pc9_len;
        if (_pc9_hdr->buf->length < _pc9_len) {
            _pc9_hdr->buf->length = _pc9_len;
        }
        break;
    }
    vader_array_t* _a2_arr = vader_array_new(19u, 0u, 3u, 295u);
    l11 = (void*) _a2_arr;
    t0 = ((vader_array_t*) l2)->length;
    l4 = vader_chk_sub(i64, t0, INT64_C(1));
    vader_array_t* _pc60_hdr = (vader_array_t*) l11;
    size_t _pc60_len = _pc60_hdr->length;
    size_t _pc60_cap = (_pc60_hdr->offset == 0 && !vader_array_is_borrowed(_pc60_hdr) && _pc60_hdr->length >= _pc60_hdr->buf->length) ? _pc60_hdr->capacity : (size_t) 0;
    void* _pc60_slots = _pc60_hdr->buf->slots;
    for (;;) {
        if ((l4 >= INT64_C(0))) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
            t1 = vader_box_i32(295u, ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4]);
            l9 = ((uint32_t) t1.payload.i);
            if (VADER_LIKELY(_pc60_len < _pc60_cap)) {
                ((int32_t*) _pc60_slots)[_pc60_len] = (int32_t) ((int32_t) (uint32_t) l9);
                _pc60_len += 1;
            } else {
                _pc60_hdr->length = _pc60_len;
                if (_pc60_hdr->buf->length < _pc60_len) {
                    _pc60_hdr->buf->length = _pc60_len;
                }
                vader_array_push_i32((vader_array_t*) l11, (int32_t) (uint32_t) l9);
                _pc60_hdr = (vader_array_t*) l11;
                _pc60_len = _pc60_hdr->length;
                _pc60_cap = (_pc60_hdr->offset == 0 && !vader_array_is_borrowed(_pc60_hdr) && _pc60_hdr->length >= _pc60_hdr->buf->length) ? _pc60_hdr->capacity : (size_t) 0;
                _pc60_slots = _pc60_hdr->buf->slots;
            }
            l4 = vader_chk_sub(i64, l4, INT64_C(1));
            continue;
        }
        _pc60_hdr->length = _pc60_len;
        if (_pc60_hdr->buf->length < _pc60_len) {
            _pc60_hdr->buf->length = _pc60_len;
        }
        break;
    }
    t4 = ((int32_t) (uint64_t) l3);
    l9 = (uint32_t) (int32_t) t4;
    vader_struct___Tuple_Array_u32_u32_6fc96a7e_t* _a4_obj = (vader_struct___Tuple_Array_u32_u32_6fc96a7e_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_Array_u32_u32_6fc96a7e_t));
    vader_obj_header_init(_a4_obj, 303u);
    _a4_obj->f__0 = l11;
    _a4_obj->f__1 = l9;
    t5 = (void*) _a4_obj;
    { void* __vret = t5; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* std_core_BigInt_Mul_mul(void* l0, uint32_t l1) {
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = std_core_mul_add_small(l0, l1, (uint32_t) 0);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* std_core____Add_add__toolchain_ast_AssertDecl___toolchain_ast_ConstDecl___toolchain_ast_EnumDecl___toolchain_ast_FnDecl___toolchain_ast_ImplDecl___toolchain_ast_ImportDecl___toolchain_ast_StructDecl___toolchain_ast_TraitDecl___toolchain_ast_TypeAliasDecl(void* l0, void* l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(218u, 0u, 13u, 1484u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_array_t*) l0)->length;
    l4 = ((vader_array_t*) l1)->length;
    l3 = vader_chk_add(i64, l3, l4);
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a1_arr;
    vader_array_push_all((vader_array_t*) l2, (vader_array_t*) l0);
    vader_array_push_all((vader_array_t*) l2, (vader_array_t*) l1);
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

void* std_core____Add_add__vader_diagnostics_Diagnostic(void* l0, void* l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(84u, 0u, 13u, 910u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_array_t*) l0)->length;
    l4 = ((vader_array_t*) l1)->length;
    l3 = vader_chk_add(i64, l3, l4);
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a1_arr;
    vader_array_push_all((vader_array_t*) l2, (vader_array_t*) l0);
    vader_array_push_all((vader_array_t*) l2, (vader_array_t*) l1);
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

void* std_core____Add_add__vader_types_TypeParamType(void* l0, void* l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(200u, 0u, 13u, 1280u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_array_t*) l0)->length;
    l4 = ((vader_array_t*) l1)->length;
    l3 = vader_chk_add(i64, l3, l4);
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a1_arr;
    vader_array_push_all((vader_array_t*) l2, (vader_array_t*) l0);
    vader_array_push_all((vader_array_t*) l2, (vader_array_t*) l1);
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

bool std_core____Contains_contains__bool(void* l0, bool l1) {
    void* l2;
    int64_t l3, l4;
    bool t0, t1;
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
        t1 = t0;
        if (t1 == l1) {
            return true;
        }
        l4 = (l4 + INT64_C(1));
    }
    return false;
}

bool std_core____Contains_contains__i32(void* l0, int32_t l1) {
    void* l2;
    int64_t l3, l4;
    int32_t t0;
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
        if (t0 == l1) {
            return true;
        }
        l4 = (l4 + INT64_C(1));
    }
    return false;
}

bool std_core____Contains_contains__string(void* l0, vader_string_t l1) {
    void* l2;
    int64_t l3, l4;
    vader_box_t t0;
    vader_string_t t1;
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l4];
        t1 = t0.payload.s;
        if (t1 == l1) {
            return true;
        }
        l4 = (l4 + INT64_C(1));
    }
    return false;
}

bool std_core____Contains_contains__vader_bytecode_ValType(void* l0, uint8_t l1) {
    void* l2;
    int64_t l3, l4;
    vader_box_t t0;
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l4, 293u);
        if (((int32_t) t0.payload.i) == l1) {
            return true;
        }
        l4 = (l4 + INT64_C(1));
    }
    return false;
}

static bool std_core_any_below(void* l0, int32_t l1) {
    int32_t l2, l3;
    int64_t l4, l5;
    uint64_t l6;
    vader_box_t t0;
    uint32_t t1;
    int64_t t2;
    uint64_t t3;
    l2 = vader_div_i32(l1, INT32_C(32));
    l3 = vader_mod_i32(l1, INT32_C(32));
    l4 = INT64_C(0);
    l5 = ((int64_t) (int32_t) l2);
    while ((l4 < l5)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t0 = vader_box_i32(295u, ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4]);
        t1 = ((uint32_t) t0.payload.i);
        if (t1 != INT32_C(0)) {
            return true;
        }
        l4 = (l4 + INT64_C(1));
    }
    if ((l3 > INT32_C(0))) {
        t2 = ((int64_t) (int32_t) l3);
        l6 = (uint64_t) (int64_t) t2;
        t2 = vader_chk_sub(u64, (INT64_C(1) << (l6 & 63)), INT64_C(1));
        l6 = (uint64_t) (int64_t) t2;
        l4 = ((int64_t) (int32_t) l2);
        t3 = std_core_limb(l0, l4);
        if ((t3 & l6) != INT64_C(0)) {
            return true;
        }
        return false;
    }
    return false;
}

static int64_t std_core_ascii_prefix(vader_string_t l0) {
    int64_t l1, l2, l4, l5;
    uint8_t l3, l6;
    int64_t t0;
    int32_t t1;
    l1 = vader_host_std_core_byte_len(l0);
    l2 = INT64_C(0);
    for (;;) {
        t0 = vader_chk_add(i64, l2, INT64_C(64));
        if ((t0 <= l1)) {
            l3 = (uint8_t) 0;
            l4 = l2;
            l5 = vader_chk_add(i64, l2, INT64_C(64));
            while ((l4 < l5)) {
                l6 = vader_host_std_core_byte_at(l0, l4);
                t1 = (l3 | l6);
                l3 = (uint8_t) (int32_t) t1;
                l4 = (l4 + INT64_C(1));
            }
            if ((l3 >= INT32_C(128))) {
                return l2;
            }
            l2 = vader_chk_add(i64, l2, INT64_C(64));
            continue;
        }
        break;
    }
    return l2;
}

static int32_t std_core_b2i(bool l0) {
    if (l0) {
        return INT32_C(1);
    }
    return INT32_C(0);
}

static uint64_t std_core_b2u(bool l0) {
    if (l0) {
        return (uint64_t) 1;
    }
    return (uint64_t) 0;
}

static int32_t std_core_bit_len(void* l0) {
    int32_t l1, l2, l3, l4;
    int64_t t0;
    vader_box_t t1;
    uint32_t t2;
    int32_t t3;
    t0 = ((vader_array_t*) l0)->length;
    l1 = vader_chk_sub(i32, ((int32_t) (int64_t) t0), INT32_C(1));
    while ((l1 >= INT32_C(0))) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        t1 = vader_box_i32(295u, ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1]);
        t2 = ((uint32_t) t1.payload.i);
        if (t2 != INT32_C(0)) {
            l2 = vader_chk_mul(i32, l1, INT32_C(32));
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
            t1 = vader_box_i32(295u, ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1]);
            t2 = ((uint32_t) t1.payload.i);
            l3 = std_core_clz32(t2);
            l4 = vader_chk_sub(i32, INT32_C(32), l3);
            t3 = vader_chk_add(i32, l2, l4);
            return t3;
        }
        l1 = vader_chk_sub(i32, l1, INT32_C(1));
    }
    return INT32_C(0);
}

static uint64_t std_core_bits64(void* l0, int32_t l1) {
    int64_t l2, l5;
    int32_t l3;
    uint64_t l4, l6, l7, l8, l9;
    int32_t t0;
    int64_t t1;
    t0 = vader_div_i32(l1, INT32_C(32));
    l2 = ((int64_t) (int32_t) t0);
    l3 = vader_mod_i32(l1, INT32_C(32));
    l4 = std_core_limb(l0, l2);
    l5 = vader_chk_add(i64, l2, INT64_C(1));
    l6 = std_core_limb(l0, l5);
    if (!(l3 == INT32_C(0))) {
        l2 = vader_chk_add(i64, l2, INT64_C(2));
        l7 = std_core_limb(l0, l2);
        t1 = ((int64_t) (int32_t) l3);
        l8 = (uint64_t) (int64_t) t1;
        l8 = (l4 >> (l8 & 63));
        t0 = vader_chk_sub(i32, INT32_C(32), l3);
        t1 = ((int64_t) (int32_t) t0);
        l9 = (uint64_t) (int64_t) t1;
        t1 = (l6 << (l9 & 63));
        l9 = (uint64_t) (int64_t) t1;
        t1 = (l8 | l9);
        l8 = (uint64_t) (int64_t) t1;
        t0 = vader_chk_sub(i32, INT32_C(64), l3);
        t1 = ((int64_t) (int32_t) t0);
        l9 = (uint64_t) (int64_t) t1;
        t1 = (l7 << (l9 & 63));
        l7 = (uint64_t) (int64_t) t1;
        return (uint64_t) (int64_t) (l8 | l7);
    }
    t1 = (l6 << INT64_C(32));
    l6 = (uint64_t) (int64_t) t1;
    return (uint64_t) (int64_t) (l4 | l6);
}

static bool std_core_bool_Equals_equals_guard(bool l0, vader_box_t l1) {
    bool l2;
    if (l1.tag == 286u) {
        l2 = l1.payload.b;
        return l0 == l2;
    }
    return false;
}

vader_string_t std_core_char_Display_to_string(uint32_t l0) {
    void* t0 = NULL;
    vader_string_t t1 = 0;
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = std_core_utf8_encode(l0);
    t1 = vader_host_std_core_bytes_to_string(t0);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool std_core_char_Equals_equals_guard(uint32_t l0, vader_box_t l1) {
    uint32_t l2;
    if (l1.tag == 287u) {
        l2 = ((uint32_t) l1.payload.i);
        return l0 == l2;
    }
    return false;
}

static uint64_t std_core_char_Hash_hash(uint32_t l0) {
    return (uint64_t) (int64_t) ((int64_t) (uint32_t) l0);
}

static int32_t std_core_clz32(uint32_t l0) {
    int32_t l1;
    uint32_t l2;
    int32_t t0;
    l1 = INT32_C(0);
    l2 = l0;
    while ((l2 & INT32_MIN) == INT32_C(0)) {
        t0 = (l2 << INT32_C(1));
        l2 = (uint32_t) (int32_t) t0;
        l1 = vader_chk_add(i32, l1, INT32_C(1));
    }
    return l1;
}

void std_core_codepoint_at_byte(vader_string_t l0, int64_t l1, uint32_t* __o0, int64_t* __o1) {
    uint8_t l2;
    uint32_t l3;
    int64_t l4;
    bool l5;
    uint32_t t0;
    int64_t t1;
    l2 = vader_host_std_core_byte_at(l0, l1);
    if ((l2 < INT32_C(128))) {
        *__o1 = INT64_C(1); *__o0 = ((uint32_t) (uint8_t) l2); return;
    }
    std_core_decode_tail(l0, l2, l1, &t0, &t1);
    l4 = t1;
    l3 = t0;
    if ((l3 > INT32_C(55295))) {
        if ((l3 < INT32_C(57344))) {
            l5 = true;
        } else {
            l5 = (l3 > INT32_C(1114111));
        }
        if (l5) {
            vader_unreachable("value out of range: no Unicode scalar value");
        } else {
            *__o1 = l4; *__o0 = ((uint32_t) (uint32_t) l3); return;
        }
    } else {
        *__o1 = l4; *__o0 = ((uint32_t) (uint32_t) l3); return;
    }
}

static int64_t std_core_codepoint_count(void* l0) {
    int64_t l1, l2;
    bool t0;
    int64_t t1;
    l1 = ((vader_struct_std_core_Range__i64_t*) l0)->f_end;
    t0 = ((vader_struct_std_core_Range__i64_t*) l0)->f_inclusive;
    if (t0) {
        l1 = vader_chk_add(i64, l1, INT64_C(1));
    }
    l2 = ((vader_struct_std_core_Range__i64_t*) l0)->f_start;
    if (!((l1 < l2))) {
        l2 = ((vader_struct_std_core_Range__i64_t*) l0)->f_start;
        t1 = vader_chk_sub(i64, l1, l2);
        return t1;
    }
    return INT64_C(0);
}

static int64_t std_core_codepoint_offset(vader_string_t l0, int64_t l1, int64_t l2) {
    int64_t l3, l4, l5, l7, l8;
    uint8_t l6;
    uint32_t t0;
    int64_t t1;
    l3 = vader_host_std_core_byte_len(l0);
    l4 = l1;
    l5 = INT64_C(0);
    while ((l4 < l3)) {
        if (!((l5 < l2))) {
            break;
        }
        l6 = vader_host_std_core_byte_at(l0, l4);
        if ((l6 < INT32_C(128))) {
            l4 = vader_chk_add(i64, l4, INT64_C(1));
        } else {
            std_core_decode_tail(l0, l6, l4, &t0, &t1);
            l8 = t1;
            l7 = l8;
            l4 = vader_chk_add(i64, l4, l7);
        }
        l5 = vader_chk_add(i64, l5, INT64_C(1));
    }
    return l4;
}

bool std_core_content_equals__string(void* l0, void* l1) {
    int64_t l2, l3;
    vader_string_t l4, l5;
    vader_box_t t0;
    l2 = ((vader_array_t*) l0)->length;
    l3 = ((vader_array_t*) l1)->length;
    if (l2 != l3) {
        return false;
    }
    l2 = INT64_C(0);
    l3 = ((vader_array_t*) l0)->length;
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l2];
        l4 = t0.payload.s;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
        t0 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l2];
        l5 = t0.payload.s;
        if (l4 != l5) {
            return false;
        }
        l2 = (l2 + INT64_C(1));
    }
    return true;
}

static void* std_core_d2d(uint64_t l0, uint64_t l1) {
    int32_t l2, l11, l13, l14;
    uint64_t l3, l5, l7, l8, l9, l10, l16, l18, l20, l21, l22, l23;
    bool l4, l6, l12, l19, l24;
    int64_t l15;
    void* l17 = NULL;
    int32_t t0, t1;
    int64_t t2, t5;
    void* t3 = NULL;
    uint64_t t4;
    bool t6;
    void** gc_raw_roots[2] = { &l17, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = INT32_C(0);
    l3 = (uint64_t) 0;
    if (l1 == INT64_C(0)) {
        t0 = vader_chk_sub(i32, INT32_C(-1022), INT32_C(52));
        l2 = vader_chk_sub(i32, t0, INT32_C(2));
        l3 = l0;
    } else {
        t0 = vader_chk_sub(i32, ((int32_t) (uint64_t) l1), INT32_C(1023));
        t1 = vader_chk_sub(i32, t0, INT32_C(52));
        l2 = vader_chk_sub(i32, t1, INT32_C(2));
        t2 = ((INT64_C(1) << INT64_C(52)) | l0);
        l3 = (uint64_t) (int64_t) t2;
    }
    l4 = (l3 & INT64_C(1)) == INT64_C(0);
    t2 = vader_chk_mul(u64, l3, INT64_C(4));
    l5 = (uint64_t) (int64_t) t2;
    if (l0 != INT64_C(0)) {
        l6 = true;
    } else {
        l6 = (l1 <= INT64_C(1));
    }
    l7 = std_core_b2u(l6);
    l8 = (uint64_t) 0;
    l9 = (uint64_t) 0;
    l10 = (uint64_t) 0;
    l11 = INT32_C(0);
    l6 = false;
    l12 = false;
    if ((l2 >= INT32_C(0))) {
        l13 = std_core_log10_pow2(l2);
        l14 = std_core_b2i((l2 > INT32_C(3)));
        l13 = vader_chk_sub(i32, l13, l14);
        l11 = l13;
        l14 = std_core_pow5bits(l13);
        t0 = vader_chk_add(i32, INT32_C(125), l14);
        l14 = vader_chk_sub(i32, t0, INT32_C(1));
        t0 = vader_chk_neg(i32, l2);
        t1 = vader_chk_add(i32, t0, l13);
        l14 = vader_chk_add(i32, t1, l14);
        l15 = ((int64_t) (int32_t) l13);
        l15 = vader_chk_mul(i64, INT64_C(2), l15);
        t3 = (void*) &vader_data_1;
        vader_array_t* _a0_slotarr = ((vader_array_t*) t3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l15)
        t2 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l15];
        l16 = (uint64_t) (int64_t) t2;
        l17 = (void*) &vader_data_1;
        l15 = vader_chk_add(i64, l15, INT64_C(1));
        vader_array_t* _a1_slotarr = ((vader_array_t*) l17);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l15)
        t2 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l15];
        l18 = (uint64_t) (int64_t) t2;
        l17 = std_core_mul_shift_all_64(l3, l16, l18, l14, l7);
        l8 = ((vader_struct___Tuple_u64_u64_u64_2d035edd_t*) l17)->f__0;
        l9 = ((vader_struct___Tuple_u64_u64_u64_2d035edd_t*) l17)->f__1;
        l10 = ((vader_struct___Tuple_u64_u64_u64_2d035edd_t*) l17)->f__2;
        if ((l13 <= INT32_C(21))) {
            t4 = vader_div_u64(l5, INT64_C(5));
            t2 = vader_chk_mul(u64, t4, INT64_C(5));
            l16 = (uint64_t) (int64_t) t2;
            t2 = vader_chk_sub(u64, l5, l16);
            if (t2 == INT64_C(0)) {
                l12 = std_core_multiple_of_power_of_5(l5, l13);
            } else if (l4) {
                t2 = vader_chk_sub(u64, l5, INT64_C(1));
                t5 = vader_chk_sub(u64, t2, l7);
                l6 = std_core_multiple_of_power_of_5((uint64_t) (int64_t) t5, l13);
            } else {
                t2 = vader_chk_add(u64, l5, INT64_C(2));
                t6 = std_core_multiple_of_power_of_5((uint64_t) (int64_t) t2, l13);
                l16 = std_core_b2u(t6);
                t2 = vader_chk_sub(u64, l9, l16);
                l9 = (uint64_t) (int64_t) t2;
            }
        }
    } else {
        t0 = vader_chk_neg(i32, l2);
        l13 = std_core_log10_pow5(t0);
        t0 = vader_chk_neg(i32, l2);
        l14 = std_core_b2i((t0 > INT32_C(1)));
        l13 = vader_chk_sub(i32, l13, l14);
        l11 = vader_chk_add(i32, l13, l2);
        t0 = vader_chk_neg(i32, l2);
        l2 = vader_chk_sub(i32, t0, l13);
        t0 = std_core_pow5bits(l2);
        l14 = vader_chk_sub(i32, t0, INT32_C(125));
        l14 = vader_chk_sub(i32, l13, l14);
        l15 = ((int64_t) (int32_t) l2);
        l15 = vader_chk_mul(i64, INT64_C(2), l15);
        t3 = (void*) &vader_data_2;
        vader_array_t* _a2_slotarr = ((vader_array_t*) t3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l15)
        t2 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l15];
        l16 = (uint64_t) (int64_t) t2;
        l17 = (void*) &vader_data_2;
        l15 = vader_chk_add(i64, l15, INT64_C(1));
        vader_array_t* _a3_slotarr = ((vader_array_t*) l17);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l15)
        t2 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l15];
        l18 = (uint64_t) (int64_t) t2;
        l17 = std_core_mul_shift_all_64(l3, l16, l18, l14, l7);
        l8 = ((vader_struct___Tuple_u64_u64_u64_2d035edd_t*) l17)->f__0;
        l9 = ((vader_struct___Tuple_u64_u64_u64_2d035edd_t*) l17)->f__1;
        l10 = ((vader_struct___Tuple_u64_u64_u64_2d035edd_t*) l17)->f__2;
        if ((l13 <= INT32_C(1))) {
            l12 = true;
            if (l4) {
                l6 = l7 == INT64_C(1);
            } else {
                t2 = vader_chk_sub(u64, l9, INT64_C(1));
                l9 = (uint64_t) (int64_t) t2;
            }
        } else if ((l13 < INT32_C(63))) {
            l12 = std_core_multiple_of_power_of_2(l5, l13);
        }
    }
    l2 = INT32_C(0);
    l3 = (uint64_t) 0;
    l5 = (uint64_t) 0;
    if (l6) {
        l19 = true;
    } else {
        l19 = l12;
    }
    if (l19) {
        for (;;) {
            l7 = vader_div_u64(l9, INT64_C(10));
            l16 = vader_div_u64(l10, INT64_C(10));
            if (!((l7 <= l16))) {
                t2 = vader_chk_mul(u64, l16, INT64_C(10));
                l18 = (uint64_t) (int64_t) t2;
                t2 = vader_chk_sub(u64, l10, l18);
                l20 = (uint64_t) (int64_t) t2;
                l21 = vader_div_u64(l8, INT64_C(10));
                t2 = vader_chk_mul(u64, l21, INT64_C(10));
                l22 = (uint64_t) (int64_t) t2;
                t2 = vader_chk_sub(u64, l8, l22);
                l23 = (uint64_t) (int64_t) t2;
                if (l6) {
                    l19 = l20 == INT64_C(0);
                } else {
                    l19 = false;
                }
                l6 = l19;
                if (l12) {
                    l24 = l3 == INT64_C(0);
                } else {
                    l24 = false;
                }
                l12 = l24;
                l3 = l23;
                l8 = l21;
                l9 = l7;
                l10 = l16;
                l2 = vader_chk_add(i32, l2, INT32_C(1));
                continue;
            }
            break;
        }
        if (l6) {
            for (;;) {
                l7 = vader_div_u64(l10, INT64_C(10));
                t2 = vader_chk_mul(u64, l7, INT64_C(10));
                l16 = (uint64_t) (int64_t) t2;
                t2 = vader_chk_sub(u64, l10, l16);
                if (!(t2 != INT64_C(0))) {
                    l18 = vader_div_u64(l9, INT64_C(10));
                    l20 = vader_div_u64(l8, INT64_C(10));
                    t2 = vader_chk_mul(u64, l20, INT64_C(10));
                    l21 = (uint64_t) (int64_t) t2;
                    t2 = vader_chk_sub(u64, l8, l21);
                    l22 = (uint64_t) (int64_t) t2;
                    if (l12) {
                        l19 = l3 == INT64_C(0);
                    } else {
                        l19 = false;
                    }
                    l12 = l19;
                    l3 = l22;
                    l8 = l20;
                    l9 = l18;
                    l10 = l7;
                    l2 = vader_chk_add(i32, l2, INT32_C(1));
                    continue;
                }
                break;
            }
        }
        if (l12) {
            if (l3 == INT64_C(5)) {
                t4 = vader_mod_u64(l8, INT64_C(2));
                if (t4 == INT64_C(0)) {
                    l3 = (uint64_t) 4;
                }
            }
        }
        if (l8 == l10) {
            if (!(l4)) {
                l12 = true;
            } else {
                l12 = !(l6);
            }
            l6 = l12;
        } else {
            l6 = false;
        }
        if (l6) {
            l4 = true;
        } else {
            l4 = (l3 >= INT64_C(5));
        }
        l3 = std_core_b2u(l4);
        t2 = vader_chk_add(u64, l8, l3);
        l5 = (uint64_t) (int64_t) t2;
        l13 = vader_chk_add(i32, l11, l2);
        vader_struct_std_core_Dec64_t* _a4_obj = (vader_struct_std_core_Dec64_t*) vader_gc_alloc(sizeof(vader_struct_std_core_Dec64_t));
        vader_obj_header_init(_a4_obj, 528u);
        _a4_obj->f_mantissa = l5;
        _a4_obj->f_exp = l13;
        t3 = (void*) _a4_obj;
        { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = false;
    l3 = vader_div_u64(l9, INT64_C(100));
    l7 = vader_div_u64(l10, INT64_C(100));
    if ((l3 > l7)) {
        l16 = vader_div_u64(l8, INT64_C(100));
        t2 = vader_chk_mul(u64, l16, INT64_C(100));
        l18 = (uint64_t) (int64_t) t2;
        t2 = vader_chk_sub(u64, l8, l18);
        l4 = ((uint64_t) (int64_t) t2 >= INT64_C(50));
        l8 = l16;
        l9 = l3;
        l10 = l7;
        l2 = vader_chk_add(i32, l2, INT32_C(2));
    }
    for (;;) {
        l3 = vader_div_u64(l9, INT64_C(10));
        l7 = vader_div_u64(l10, INT64_C(10));
        if (!((l3 <= l7))) {
            l16 = vader_div_u64(l8, INT64_C(10));
            t2 = vader_chk_mul(u64, l16, INT64_C(10));
            l18 = (uint64_t) (int64_t) t2;
            t2 = vader_chk_sub(u64, l8, l18);
            l4 = ((uint64_t) (int64_t) t2 >= INT64_C(5));
            l8 = l16;
            l9 = l3;
            l10 = l7;
            l2 = vader_chk_add(i32, l2, INT32_C(1));
            continue;
        }
        break;
    }
    if (l8 == l10) {
        l6 = true;
    } else {
        l6 = l4;
    }
    l3 = std_core_b2u(l6);
    t2 = vader_chk_add(u64, l8, l3);
    l5 = (uint64_t) (int64_t) t2;
    l13 = vader_chk_add(i32, l11, l2);
    vader_struct_std_core_Dec64_t* _a5_obj = (vader_struct_std_core_Dec64_t*) vader_gc_alloc(sizeof(vader_struct_std_core_Dec64_t));
    vader_obj_header_init(_a5_obj, 528u);
    _a5_obj->f_mantissa = l5;
    _a5_obj->f_exp = l13;
    t3 = (void*) _a5_obj;
    { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t std_core_decimal_width(uint64_t l0) {
    int32_t l1;
    uint64_t l2;
    if (l0 == INT64_C(0)) {
        return INT32_C(1);
    }
    l1 = INT32_C(0);
    l2 = l0;
    while (l2 != INT64_C(0)) {
        l1 = vader_chk_add(i32, l1, INT32_C(1));
        l2 = vader_div_u64(l2, INT64_C(10));
    }
    return l1;
}

void std_core_decode_tail(vader_string_t l0, uint8_t l1, int64_t l2, uint32_t* __o0, int64_t* __o1) {
    bool l3, l9;
    int64_t l4, l5;
    uint8_t l6, l10, l11;
    uint32_t l7, l8;
    int64_t t0;
    bool t1;
    int32_t t2;
    if ((l1 < INT32_C(194))) {
        l3 = true;
    } else {
        l3 = (l1 > INT32_C(244));
    }
    if (l3) {
        *__o1 = INT64_C(1); *__o0 = (uint32_t) 65533; return;
    }
    l4 = vader_host_std_core_byte_len(l0);
    t0 = vader_chk_add(i64, l2, INT64_C(1));
    if ((t0 >= l4)) {
        *__o1 = INT64_C(1); *__o0 = (uint32_t) 65533; return;
    }
    l5 = vader_chk_add(i64, l2, INT64_C(1));
    l6 = vader_host_std_core_byte_at(l0, l5);
    t1 = std_core_is_utf8_continuation(l6);
    if (!(t1)) {
        *__o1 = INT64_C(1); *__o0 = (uint32_t) 65533; return;
    }
    if ((l1 < INT32_C(224))) {
        t2 = ((((int32_t) (uint8_t) l1) & INT32_C(31)) << INT32_C(6));
        l7 = (uint32_t) (int32_t) t2;
        t2 = (((int32_t) (uint8_t) l6) & INT32_C(63));
        l8 = (uint32_t) (int32_t) t2;
        *__o1 = INT64_C(2); *__o0 = (uint32_t) (int32_t) (l7 | l8); return;
    }
    if ((l1 < INT32_C(240))) {
        if (l1 == INT32_C(224)) {
            l3 = (l6 < INT32_C(160));
        } else {
            l3 = false;
        }
        if (l3) {
            l3 = true;
        } else {
            if (l1 == INT32_C(237)) {
                l9 = (l6 > INT32_C(159));
            } else {
                l9 = false;
            }
            l3 = l9;
        }
        if (l3) {
            *__o1 = INT64_C(1); *__o0 = (uint32_t) 65533; return;
        }
    } else {
        if (l1 == INT32_C(240)) {
            l3 = (l6 < INT32_C(144));
        } else {
            l3 = false;
        }
        if (l3) {
            l3 = true;
        } else {
            if (l1 == INT32_C(244)) {
                l9 = (l6 > INT32_C(143));
            } else {
                l9 = false;
            }
            l3 = l9;
        }
        if (l3) {
            *__o1 = INT64_C(1); *__o0 = (uint32_t) 65533; return;
        }
    }
    t0 = vader_chk_add(i64, l2, INT64_C(2));
    if ((t0 >= l4)) {
        *__o1 = INT64_C(2); *__o0 = (uint32_t) 65533; return;
    }
    l5 = vader_chk_add(i64, l2, INT64_C(2));
    l10 = vader_host_std_core_byte_at(l0, l5);
    t1 = std_core_is_utf8_continuation(l10);
    if (!(t1)) {
        *__o1 = INT64_C(2); *__o0 = (uint32_t) 65533; return;
    }
    if ((l1 < INT32_C(240))) {
        t2 = ((((int32_t) (uint8_t) l1) & INT32_C(15)) << INT32_C(12));
        l7 = (uint32_t) (int32_t) t2;
        t2 = ((((int32_t) (uint8_t) l6) & INT32_C(63)) << INT32_C(6));
        l8 = (uint32_t) (int32_t) t2;
        t2 = (l7 | l8);
        l7 = (uint32_t) (int32_t) t2;
        t2 = (((int32_t) (uint8_t) l10) & INT32_C(63));
        l8 = (uint32_t) (int32_t) t2;
        *__o1 = INT64_C(3); *__o0 = (uint32_t) (int32_t) (l7 | l8); return;
    }
    t0 = vader_chk_add(i64, l2, INT64_C(3));
    if ((t0 >= l4)) {
        *__o1 = INT64_C(3); *__o0 = (uint32_t) 65533; return;
    }
    l4 = vader_chk_add(i64, l2, INT64_C(3));
    l11 = vader_host_std_core_byte_at(l0, l4);
    t1 = std_core_is_utf8_continuation(l11);
    if (!(t1)) {
        *__o1 = INT64_C(3); *__o0 = (uint32_t) 65533; return;
    }
    t2 = ((((int32_t) (uint8_t) l1) & INT32_C(7)) << INT32_C(18));
    l7 = (uint32_t) (int32_t) t2;
    t2 = ((((int32_t) (uint8_t) l6) & INT32_C(63)) << INT32_C(12));
    l8 = (uint32_t) (int32_t) t2;
    t2 = (l7 | l8);
    l7 = (uint32_t) (int32_t) t2;
    t2 = ((((int32_t) (uint8_t) l10) & INT32_C(63)) << INT32_C(6));
    l8 = (uint32_t) (int32_t) t2;
    t2 = (l7 | l8);
    l7 = (uint32_t) (int32_t) t2;
    t2 = (((int32_t) (uint8_t) l11) & INT32_C(63));
    l8 = (uint32_t) (int32_t) t2;
    *__o1 = INT64_C(4); *__o0 = (uint32_t) (int32_t) (l7 | l8); return;
}

static uint64_t std_core_eisel_lemire(uint64_t l0, int32_t l1) {
    bool l2;
    uint64_t l3, l4, l8, l9, l10;
    int32_t l5, l6, l7;
    int64_t t0;
    uint64_t t1, t2;
    int32_t t3, t4;
    if (l0 == INT64_C(0)) {
        l2 = true;
    } else {
        l2 = (l1 < INT32_C(-342));
    }
    if (l2) {
        return (uint64_t) 0;
    }
    if ((l1 > INT32_C(308))) {
        t0 = ((int64_t) 2047);
        l3 = (uint64_t) (int64_t) t0;
        t0 = ((int64_t) 52);
        l4 = (uint64_t) (int64_t) t0;
        return (uint64_t) (int64_t) (l3 << (l4 & 63));
    }
    l5 = std_core_pf_clz64(l0);
    t0 = ((int64_t) (int32_t) l5);
    l3 = (uint64_t) (int64_t) t0;
    t0 = (l0 << (l3 & 63));
    l3 = (uint64_t) (int64_t) t0;
    std_core_pf_product(l1, l3, &t1, &t2);
    l8 = t2;
    l3 = t1;
    l4 = l8;
    l6 = ((int32_t) (uint64_t) (l3 >> INT64_C(63)));
    t3 = vader_chk_add(i32, l6, INT32_C(64));
    t4 = vader_chk_sub(i32, t3, INT32_C(52));
    l7 = vader_chk_sub(i32, t4, INT32_C(3));
    t0 = ((int64_t) (int32_t) l7);
    l8 = (uint64_t) (int64_t) t0;
    l8 = (l3 >> (l8 & 63));
    t3 = vader_chk_mul(i32, INT32_C(217706), l1);
    t4 = vader_chk_add(i32, (t3 >> INT32_C(16)), INT32_C(63));
    t3 = vader_chk_add(i32, t4, l6);
    t4 = vader_chk_sub(i32, t3, l5);
    l5 = vader_chk_sub(i32, t4, INT32_C(-1023));
    if ((l5 <= INT32_C(0))) {
        t3 = vader_chk_neg(i32, l5);
        t4 = vader_chk_add(i32, t3, INT32_C(1));
        if ((t4 >= INT32_C(64))) {
            return (uint64_t) 0;
        }
        t3 = vader_chk_neg(i32, l5);
        t4 = vader_chk_add(i32, t3, INT32_C(1));
        t0 = ((int64_t) (int32_t) t4);
        l9 = (uint64_t) (int64_t) t0;
        l8 = (l8 >> (l9 & 63));
        t0 = (l8 & INT64_C(1));
        l9 = (uint64_t) (int64_t) t0;
        t0 = vader_chk_add(u64, l8, l9);
        l8 = (uint64_t) (int64_t) t0;
        l8 = (l8 >> INT64_C(1));
        t0 = ((int64_t) 52);
        l9 = (uint64_t) (int64_t) t0;
        t0 = (INT64_C(1) << (l9 & 63));
        l9 = (uint64_t) (int64_t) t0;
        if ((l8 < l9)) {
            l6 = INT32_C(0);
        } else {
            l6 = INT32_C(1);
        }
        t0 = ((int64_t) (int32_t) l6);
        l9 = (uint64_t) (int64_t) t0;
        t0 = ((int64_t) 52);
        l10 = (uint64_t) (int64_t) t0;
        return (uint64_t) (int64_t) ((l9 << (l10 & 63)) | l8);
    }
    if ((l4 <= INT64_C(1))) {
        if ((l1 >= INT32_C(-4))) {
            if ((l1 <= INT32_C(23))) {
                if ((l8 & INT64_C(3)) == INT64_C(1)) {
                    t0 = ((int64_t) (int32_t) l7);
                    l4 = (uint64_t) (int64_t) t0;
                    if ((l8 << (l4 & 63)) == l3) {
                        t0 = ~(INT64_C(1));
                        l3 = (uint64_t) (int64_t) t0;
                        t0 = (l8 & l3);
                        l8 = (uint64_t) (int64_t) t0;
                    }
                }
            }
        }
    }
    t0 = (l8 & INT64_C(1));
    l3 = (uint64_t) (int64_t) t0;
    t0 = vader_chk_add(u64, l8, l3);
    l8 = (uint64_t) (int64_t) t0;
    l8 = (l8 >> INT64_C(1));
    t0 = ((int64_t) 52);
    l3 = (uint64_t) (int64_t) t0;
    t0 = (INT64_C(2) << (l3 & 63));
    l3 = (uint64_t) (int64_t) t0;
    if ((l8 >= l3)) {
        t0 = ((int64_t) 52);
        l3 = (uint64_t) (int64_t) t0;
        t0 = (INT64_C(1) << (l3 & 63));
        l8 = (uint64_t) (int64_t) t0;
        l5 = vader_chk_add(i32, l5, INT32_C(1));
    }
    t0 = ((int64_t) 52);
    l3 = (uint64_t) (int64_t) t0;
    t0 = ~((INT64_C(1) << (l3 & 63)));
    l3 = (uint64_t) (int64_t) t0;
    t0 = (l8 & l3);
    l8 = (uint64_t) (int64_t) t0;
    if (!((l5 >= INT32_C(2047)))) {
        t0 = ((int64_t) (int32_t) l5);
        l9 = (uint64_t) (int64_t) t0;
        t0 = ((int64_t) 52);
        l10 = (uint64_t) (int64_t) t0;
        return (uint64_t) (int64_t) ((l9 << (l10 & 63)) | l8);
    }
    t0 = ((int64_t) 2047);
    l3 = (uint64_t) (int64_t) t0;
    t0 = ((int64_t) 52);
    l4 = (uint64_t) (int64_t) t0;
    return (uint64_t) (int64_t) (l3 << (l4 & 63));
}

static bool std_core_f32_Equals_equals_guard(float l0, vader_box_t l1) {
    float l2;
    if ((l1.tag == 297u || l1.tag == 298u)) {
        l2 = ((float) l1.payload.f);
        return l0 == l2;
    }
    return false;
}

vader_string_t std_core_f64_Display_to_string(double l0) {
    vader_string_t t0 = 0;
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = std_core_format_f64(l0);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool std_core_f64_Equals_equals_guard(double l0, vader_box_t l1) {
    double l2;
    if ((l1.tag == 297u || l1.tag == 298u)) {
        l2 = ((double) l1.payload.f);
        return l0 == l2;
    }
    return false;
}

void* std_core_filled__bool(int64_t l0, void* l1) {
    void* l2 = NULL;
    int64_t l3;
    bool l4;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(12u, 0u, 12u, 286u);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l0);
    l2 = (void*) _a1_arr;
    l3 = INT64_C(0);
    while ((l3 < l0)) {
        vader_fn_t* _a2_fnobj = (vader_fn_t*) l1;
        t1 = ((vader_fn_erased_sig_0_t) _a2_fnobj->code)(_a2_fnobj->env);
        l4 = t1.payload.b;
        vader_array_push_bool((vader_array_t*) l2, l4);
        l3 = (l3 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

void* std_core_filled__i32(int64_t l0, void* l1) {
    void* l2 = NULL;
    int64_t l3;
    int32_t l4;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 291u);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l0);
    l2 = (void*) _a1_arr;
    l3 = INT64_C(0);
    while ((l3 < l0)) {
        vader_fn_t* _a2_fnobj = (vader_fn_t*) l1;
        t1 = ((vader_fn_erased_sig_0_t) _a2_fnobj->code)(_a2_fnobj->env);
        l4 = ((int32_t) t1.payload.i);
        vader_array_push_i32((vader_array_t*) l2, l4);
        l3 = (l3 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

void* std_core_filled__i32__(int64_t l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    int64_t l3;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[4] = { &l1, &l2, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(2u, 0u, 13u, 15u);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l0);
    l2 = (void*) _a1_arr;
    l3 = INT64_C(0);
    while ((l3 < l0)) {
        vader_fn_t* _a2_fnobj = (vader_fn_t*) l1;
        t1 = ((vader_fn_erased_sig_0_t) _a2_fnobj->code)(_a2_fnobj->env);
        l4 = t1.payload.obj;
        vader_array_push((vader_array_t*) l2, vader_ref_box(l4));
        l3 = (l3 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

void* std_core_filled__i64(int64_t l0, void* l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 8u, 292u);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l0);
    l2 = (void*) _a1_arr;
    l3 = INT64_C(0);
    while ((l3 < l0)) {
        vader_fn_t* _a2_fnobj = (vader_fn_t*) l1;
        t1 = ((vader_fn_erased_sig_0_t) _a2_fnobj->code)(_a2_fnobj->env);
        l4 = ((int64_t) t1.payload.i);
        vader_array_push_i64((vader_array_t*) l2, l4);
        l3 = (l3 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

void* std_core_filled__std_collections_MutableSet_i32_(int64_t l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    int64_t l3;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[4] = { &l1, &l2, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(30u, 0u, 13u, 522u);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l0);
    l2 = (void*) _a1_arr;
    l3 = INT64_C(0);
    while ((l3 < l0)) {
        vader_fn_t* _a2_fnobj = (vader_fn_t*) l1;
        t1 = ((vader_fn_erased_sig_0_t) _a2_fnobj->code)(_a2_fnobj->env);
        l4 = t1.payload.obj;
        vader_array_push((vader_array_t*) l2, vader_ref_box(l4));
        l3 = (l3 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

void* std_core_filled__vader_effects_ParamEffects(int64_t l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    int64_t l3;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[4] = { &l1, &l2, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(95u, 0u, 13u, 932u);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l0);
    l2 = (void*) _a1_arr;
    l3 = INT64_C(0);
    while ((l3 < l0)) {
        vader_fn_t* _a2_fnobj = (vader_fn_t*) l1;
        t1 = ((vader_fn_erased_sig_0_t) _a2_fnobj->code)(_a2_fnobj->env);
        l4 = t1.payload.obj;
        vader_array_push((vader_array_t*) l2, vader_ref_box(l4));
        l3 = (l3 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

void* std_core_filled__vader_vm_ArrayVal___bool___char___vader_vm_ErrorVal___f64___vader_vm_FnVal___i32___i64___vader_vm_NullVal___vader_vm_ObjVal___string___vader_vm_StructVal___vader_vm_TypeVal(int64_t l0, void* l1) {
    void* l2 = NULL;
    int64_t l3;
    vader_box_t l4 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(247u, 0u, 0u, 1952u);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l0);
    l2 = (void*) _a1_arr;
    l3 = INT64_C(0);
    while ((l3 < l0)) {
        vader_fn_t* _a2_fnobj = (vader_fn_t*) l1;
        l4 = ((vader_fn_erased_sig_0_t) _a2_fnobj->code)(_a2_fnobj->env);
        vader_array_push((vader_array_t*) l2, l4);
        l3 = (l3 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

void* std_core_filled_indexed__i32__(int64_t l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    int64_t l3;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[4] = { &l1, &l2, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(2u, 0u, 13u, 15u);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l0);
    l2 = (void*) _a1_arr;
    l3 = INT64_C(0);
    while ((l3 < l0)) {
        vader_fn_t* _a2_fnobj = (vader_fn_t*) l1;
        t1 = ((vader_fn_erased_sig_1_t) _a2_fnobj->code)(_a2_fnobj->env, vader_box_i64(292u, l3));
        l4 = t1.payload.obj;
        vader_array_push((vader_array_t*) l2, vader_ref_box(l4));
        l3 = (l3 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t std_core_finish_buffer(void* l0, int64_t l1) {
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_buffer_intern_string((vader_buffer_t*) l0, (size_t) l1);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t std_core_format_f64(double l0) {
    uint64_t l1, l3;
    bool l2;
    void* l4 = NULL;
    int32_t l5;
    int64_t t0;
    vader_string_t t1 = 0;
    void** gc_raw_roots[1] = { &l4 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = (int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = l0 }).__vu);
    l1 = (uint64_t) (int64_t) t0;
    l2 = (l1 >> INT64_C(63)) != INT64_C(0);
    t0 = (l1 & INT64_C(4503599627370495));
    l3 = (uint64_t) (int64_t) t0;
    t0 = ((l1 >> INT64_C(52)) & INT64_C(2047));
    l1 = (uint64_t) (int64_t) t0;
    if (l1 == INT64_C(2047)) {
        if (l3 != INT64_C(0)) {
            { vader_gc_top = gc_frame.prev; return 2194u; }
        }
        if (l2) {
            { vader_gc_top = gc_frame.prev; return 342u; }
        }
        { vader_gc_top = gc_frame.prev; return 1993u; }
    }
    if (l1 == INT64_C(0)) {
        if (l3 == INT64_C(0)) {
            if (l2) {
                { vader_gc_top = gc_frame.prev; return 332u; }
            }
            { vader_gc_top = gc_frame.prev; return 396u; }
        }
    }
    l4 = std_core_d2d(l3, l1);
    l1 = ((vader_struct_std_core_Dec64_t*) l4)->f_mantissa;
    l5 = ((vader_struct_std_core_Dec64_t*) l4)->f_exp;
    t1 = std_core_render(l1, l5, l2);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t std_core_format_unsigned(uint64_t l0) {
    int64_t l1, l4;
    uint64_t l2;
    void* l3 = NULL;
    uint8_t l5, l6;
    uint64_t t0;
    int32_t t1;
    vader_string_t t2 = 0;
    void** gc_raw_roots[1] = { &l3 };
    vader_string_t* gc_atom_roots[1] = { &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return 395u; }
    }
    l1 = INT64_C(0);
    l2 = l0;
    while (l2 != INT64_C(0)) {
        l1 = vader_chk_add(i64, l1, INT64_C(1));
        l2 = vader_div_u64(l2, INT64_C(10));
    }
    l3 = (void*) vader_buffer_new((size_t) l1);
    l4 = l1;
    while (l0 != INT64_C(0)) {
        l4 = vader_chk_sub(i64, l4, INT64_C(1));
        t0 = vader_mod_u64(l0, INT64_C(10));
        t1 = (((int32_t) (uint64_t) t0) & INT32_C(255));
        l5 = (uint8_t) (int32_t) t1;
        t1 = vader_chk_add(u8, INT32_C(48), l5);
        l6 = (uint8_t) (int32_t) t1;
        vader_buffer_store_u8((vader_buffer_t*) l3, (size_t) l4, (uint8_t) l6);
        l0 = vader_div_u64(l0, INT64_C(10));
    }
    t2 = vader_buffer_intern_string((vader_buffer_t*) l3, (size_t) l1);
    { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool std_core_i16_Equals_equals_guard(int16_t l0, vader_box_t l1) {
    int16_t l2;
    if (l1.tag == 285u) {
        l2 = ((int16_t) l1.payload.i);
        return l0 == l2;
    }
    return false;
}

static uint64_t std_core_i16_Hash_hash(int16_t l0) {
    return (uint64_t) (int64_t) ((int64_t) (int16_t) l0);
}

static bool std_core_i32_Equals_equals_guard(int32_t l0, vader_box_t l1) {
    int32_t l2;
    if (l1.tag == 291u) {
        l2 = ((int32_t) l1.payload.i);
        return l0 == l2;
    }
    return false;
}

uint64_t std_core_i32_Hash_hash(int32_t l0) {
    return (uint64_t) (int64_t) ((int64_t) (int32_t) l0);
}

static bool std_core_i64_Equals_equals_guard(int64_t l0, vader_box_t l1) {
    int64_t l2;
    if (l1.tag == 292u) {
        l2 = ((int64_t) l1.payload.i);
        return l0 == l2;
    }
    return false;
}

uint64_t std_core_i64_Hash_hash(int64_t l0) {
    return (uint64_t) (int64_t) l0;
}

static bool std_core_i8_Equals_equals_guard(int8_t l0, vader_box_t l1) {
    int8_t l2;
    if (l1.tag == 284u) {
        l2 = ((int8_t) l1.payload.i);
        return l0 == l2;
    }
    return false;
}

static uint64_t std_core_i8_Hash_hash(int8_t l0) {
    return (uint64_t) (int64_t) ((int64_t) (int8_t) l0);
}

static int64_t std_core_insert_point(void* l0, int64_t l1, int32_t l2, int32_t l3) {
    int64_t l4, l5, l6;
    int32_t t0;
    int64_t t1, t2;
    l4 = ((int64_t) (int32_t) l3);
    l4 = vader_chk_add(i64, l1, l4);
    l5 = vader_chk_add(i64, l4, INT64_C(1));
    t0 = vader_chk_sub(i32, l2, l3);
    l6 = ((int64_t) (int32_t) t0);
    vader_buffer_memory_copy((vader_buffer_t*) l0, (size_t) l5, (vader_buffer_t*) l0, (size_t) l4, (size_t) l6);
    vader_buffer_store_u8((vader_buffer_t*) l0, (size_t) l4, (uint8_t) INT32_C(46));
    l4 = ((int64_t) (int32_t) l2);
    t1 = vader_chk_add(i64, l1, l4);
    t2 = vader_chk_add(i64, t1, INT64_C(1));
    return t2;
}

static bool std_core_is_utf8_continuation(uint8_t l0) {
    return (l0 & INT32_C(192)) == INT32_C(128);
}

static bool std_core_is_zero(void* l0) {
    int64_t l1, l2;
    vader_box_t t0;
    uint32_t t1;
    l1 = INT64_C(0);
    l2 = ((vader_array_t*) l0)->length;
    while ((l1 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_box_i32(295u, ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1]);
        t1 = ((uint32_t) t0.payload.i);
        if (t1 != INT32_C(0)) {
            return false;
        }
        l1 = (l1 + INT64_C(1));
    }
    return true;
}

int64_t std_core_len(vader_string_t l0) {
    int64_t l1, l2, l3, l5, l6;
    uint8_t l4;
    bool t0;
    uint32_t t1;
    int64_t t2;
    l1 = vader_host_std_core_byte_len(l0);
    t0 = vader_host_std_core_is_ascii(l0);
    if (t0) {
        return l1;
    }
    l2 = std_core_ascii_prefix(l0);
    l3 = l2;
    while ((l2 < l1)) {
        l4 = vader_host_std_core_byte_at(l0, l2);
        if ((l4 < INT32_C(128))) {
            l2 = vader_chk_add(i64, l2, INT64_C(1));
        } else {
            std_core_decode_tail(l0, l4, l2, &t1, &t2);
            l6 = t2;
            l5 = l6;
            l2 = vader_chk_add(i64, l2, l5);
        }
        l3 = vader_chk_add(i64, l3, INT64_C(1));
    }
    return l3;
}

static uint64_t std_core_limb(void* l0, int64_t l1) {
    bool l2;
    int64_t l3;
    vader_box_t t0;
    uint32_t t1;
    if ((INT64_C(0) <= l1)) {
        l3 = ((vader_array_t*) l0)->length;
        l2 = (l1 < l3);
    } else {
        l2 = false;
    }
    if (l2) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        t0 = vader_box_i32(295u, ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1]);
        t1 = ((uint32_t) t0.payload.i);
        return (uint64_t) (int64_t) ((int64_t) (uint32_t) t1);
    }
    return (uint64_t) 0;
}

static int32_t std_core_log10_pow2(int32_t l0) {
    int64_t t0;
    t0 = vader_chk_mul(u64, ((int64_t) (int32_t) l0), INT64_C(78913));
    return ((int32_t) (uint64_t) ((uint64_t) (int64_t) t0 >> INT64_C(18)));
}

static int32_t std_core_log10_pow5(int32_t l0) {
    int64_t t0;
    t0 = vader_chk_mul(u64, ((int64_t) (int32_t) l0), INT64_C(732923));
    return ((int32_t) (uint64_t) ((uint64_t) (int64_t) t0 >> INT64_C(20)));
}

static void* std_core_mul_add_small(void* l0, uint32_t l1, uint32_t l2) {
    void* l3 = NULL;
    int64_t l4, l6;
    uint64_t l5, l7, l8, l9;
    uint32_t l10;
    int64_t t0, t3;
    vader_box_t t1 = vader_box_null();
    uint32_t t2;
    int32_t t4;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(19u, 0u, 3u, 295u);
    l3 = (void*) _a0_arr;
    l4 = ((vader_array_t*) l0)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l3, (int64_t) l4);
    l3 = (void*) _a1_arr;
    t0 = ((int64_t) (uint32_t) l2);
    l5 = (uint64_t) (int64_t) t0;
    l4 = INT64_C(0);
    l6 = ((vader_array_t*) l0)->length;
    vader_array_t* _pc17_hdr = (vader_array_t*) l3;
    size_t _pc17_len = _pc17_hdr->length;
    size_t _pc17_cap = (_pc17_hdr->offset == 0 && !vader_array_is_borrowed(_pc17_hdr) && _pc17_hdr->length >= _pc17_hdr->buf->length) ? _pc17_hdr->capacity : (size_t) 0;
    void* _pc17_slots = _pc17_hdr->buf->slots;
    for (;;) {
        if ((l4 < l6)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            t1 = vader_box_i32(295u, ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4]);
            t2 = ((uint32_t) t1.payload.i);
            t0 = ((int64_t) (uint32_t) t2);
            l7 = (uint64_t) (int64_t) t0;
            t0 = ((int64_t) (uint32_t) l1);
            l8 = (uint64_t) (int64_t) t0;
            t0 = vader_chk_mul(u64, l7, l8);
            t3 = vader_chk_add(u64, t0, l5);
            l9 = (uint64_t) (int64_t) t3;
            t4 = ((int32_t) (int64_t) (l9 & INT64_C(4294967295)));
            l10 = (uint32_t) (int32_t) t4;
            if (VADER_LIKELY(_pc17_len < _pc17_cap)) {
                ((int32_t*) _pc17_slots)[_pc17_len] = (int32_t) ((int32_t) (uint32_t) l10);
                _pc17_len += 1;
            } else {
                _pc17_hdr->length = _pc17_len;
                if (_pc17_hdr->buf->length < _pc17_len) {
                    _pc17_hdr->buf->length = _pc17_len;
                }
                vader_array_push_i32((vader_array_t*) l3, (int32_t) (uint32_t) l10);
                _pc17_hdr = (vader_array_t*) l3;
                _pc17_len = _pc17_hdr->length;
                _pc17_cap = (_pc17_hdr->offset == 0 && !vader_array_is_borrowed(_pc17_hdr) && _pc17_hdr->length >= _pc17_hdr->buf->length) ? _pc17_hdr->capacity : (size_t) 0;
                _pc17_slots = _pc17_hdr->buf->slots;
            }
            l5 = (l9 >> INT64_C(32));
            l4 = (l4 + INT64_C(1));
            continue;
        }
        _pc17_hdr->length = _pc17_len;
        if (_pc17_hdr->buf->length < _pc17_len) {
            _pc17_hdr->buf->length = _pc17_len;
        }
        break;
    }
    vader_array_t* _pc55_hdr = (vader_array_t*) l3;
    size_t _pc55_len = _pc55_hdr->length;
    size_t _pc55_cap = (_pc55_hdr->offset == 0 && !vader_array_is_borrowed(_pc55_hdr) && _pc55_hdr->length >= _pc55_hdr->buf->length) ? _pc55_hdr->capacity : (size_t) 0;
    void* _pc55_slots = _pc55_hdr->buf->slots;
    for (;;) {
        if ((l5 > INT64_C(0))) {
            t4 = ((int32_t) (int64_t) (l5 & INT64_C(4294967295)));
            l10 = (uint32_t) (int32_t) t4;
            if (VADER_LIKELY(_pc55_len < _pc55_cap)) {
                ((int32_t*) _pc55_slots)[_pc55_len] = (int32_t) ((int32_t) (uint32_t) l10);
                _pc55_len += 1;
            } else {
                _pc55_hdr->length = _pc55_len;
                if (_pc55_hdr->buf->length < _pc55_len) {
                    _pc55_hdr->buf->length = _pc55_len;
                }
                vader_array_push_i32((vader_array_t*) l3, (int32_t) (uint32_t) l10);
                _pc55_hdr = (vader_array_t*) l3;
                _pc55_len = _pc55_hdr->length;
                _pc55_cap = (_pc55_hdr->offset == 0 && !vader_array_is_borrowed(_pc55_hdr) && _pc55_hdr->length >= _pc55_hdr->buf->length) ? _pc55_hdr->capacity : (size_t) 0;
                _pc55_slots = _pc55_hdr->buf->slots;
            }
            l5 = (l5 >> INT64_C(32));
            continue;
        }
        _pc55_hdr->length = _pc55_len;
        if (_pc55_hdr->buf->length < _pc55_len) {
            _pc55_hdr->buf->length = _pc55_len;
        }
        break;
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* std_core_mul_shift_all_64(uint64_t l0, uint64_t l1, uint64_t l2, int32_t l3, uint64_t l4) {
    uint64_t l5, l6, l7, l8, l9, l10, l11, l12, l13;
    int64_t t0;
    uint64_t t1, t2;
    int32_t t3, t4;
    void* t5 = NULL;
    void** gc_raw_roots[1] = { &t5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = (l0 << INT64_C(1));
    l5 = (uint64_t) (int64_t) t0;
    std_core_umul128(l5, l1, &t1, &t2);
    l7 = t2;
    l6 = t1;
    std_core_umul128(l5, l2, &t1, &t2);
    l8 = t2;
    l5 = t1;
    t0 = (l6 + l8);
    l8 = (uint64_t) (int64_t) t0;
    l6 = std_core_b2u((l8 < l6));
    t0 = vader_chk_add(u64, l5, l6);
    l5 = (uint64_t) (int64_t) t0;
    t0 = (l7 + l1);
    l6 = (uint64_t) (int64_t) t0;
    t0 = (l8 + l2);
    l9 = (uint64_t) (int64_t) t0;
    l6 = std_core_b2u((l6 < l7));
    t0 = (l9 + l6);
    l6 = (uint64_t) (int64_t) t0;
    l9 = std_core_b2u((l6 < l8));
    t0 = vader_chk_add(u64, l5, l9);
    l9 = (uint64_t) (int64_t) t0;
    t3 = vader_chk_sub(i32, l3, INT32_C(64));
    t4 = vader_chk_sub(i32, t3, INT32_C(1));
    t0 = ((int64_t) (int32_t) t4);
    l10 = (uint64_t) (int64_t) t0;
    l6 = std_core_shiftright128(l6, l9, l10);
    l9 = (uint64_t) 0;
    if (l4 == INT64_C(1)) {
        t0 = (l7 - l1);
        l10 = (uint64_t) (int64_t) t0;
        t0 = (l8 - l2);
        l11 = (uint64_t) (int64_t) t0;
        l10 = std_core_b2u((l10 > l7));
        t0 = (l11 - l10);
        l10 = (uint64_t) (int64_t) t0;
        l11 = std_core_b2u((l10 > l8));
        t0 = vader_chk_sub(u64, l5, l11);
        l11 = (uint64_t) (int64_t) t0;
        t3 = vader_chk_sub(i32, l3, INT32_C(64));
        t4 = vader_chk_sub(i32, t3, INT32_C(1));
        t0 = ((int64_t) (int32_t) t4);
        l12 = (uint64_t) (int64_t) t0;
        l9 = std_core_shiftright128(l10, l11, l12);
    } else {
        t0 = (l7 + l7);
        l10 = (uint64_t) (int64_t) t0;
        t0 = (l8 + l8);
        l11 = (uint64_t) (int64_t) t0;
        l7 = std_core_b2u((l10 < l7));
        t0 = (l11 + l7);
        l7 = (uint64_t) (int64_t) t0;
        t0 = vader_chk_add(u64, l5, l5);
        l11 = (uint64_t) (int64_t) t0;
        l12 = std_core_b2u((l7 < l8));
        t0 = vader_chk_add(u64, l11, l12);
        l11 = (uint64_t) (int64_t) t0;
        t0 = (l10 - l1);
        l12 = (uint64_t) (int64_t) t0;
        t0 = (l7 - l2);
        l13 = (uint64_t) (int64_t) t0;
        l10 = std_core_b2u((l12 > l10));
        t0 = (l13 - l10);
        l10 = (uint64_t) (int64_t) t0;
        l7 = std_core_b2u((l10 > l7));
        t0 = vader_chk_sub(u64, l11, l7);
        l7 = (uint64_t) (int64_t) t0;
        t3 = vader_chk_sub(i32, l3, INT32_C(64));
        t0 = ((int64_t) (int32_t) t3);
        l11 = (uint64_t) (int64_t) t0;
        l9 = std_core_shiftright128(l10, l7, l11);
    }
    t3 = vader_chk_sub(i32, l3, INT32_C(64));
    t4 = vader_chk_sub(i32, t3, INT32_C(1));
    t0 = ((int64_t) (int32_t) t4);
    l7 = (uint64_t) (int64_t) t0;
    t1 = std_core_shiftright128(l8, l5, l7);
    vader_struct___Tuple_u64_u64_u64_2d035edd_t* _a0_obj = (vader_struct___Tuple_u64_u64_u64_2d035edd_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_u64_u64_u64_2d035edd_t));
    vader_obj_header_init(_a0_obj, 307u);
    _a0_obj->f__0 = t1;
    _a0_obj->f__1 = l6;
    _a0_obj->f__2 = l9;
    t5 = (void*) _a0_obj;
    { void* __vret = t5; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool std_core_multiple_of_power_of_2(uint64_t l0, int32_t l1) {
    uint64_t l2;
    int64_t t0;
    t0 = ((int64_t) (int32_t) l1);
    l2 = (uint64_t) (int64_t) t0;
    t0 = vader_chk_sub(u64, (INT64_C(1) << (l2 & 63)), INT64_C(1));
    l2 = (uint64_t) (int64_t) t0;
    return (l0 & l2) == INT64_C(0);
}

static bool std_core_multiple_of_power_of_5(uint64_t l0, int32_t l1) {
    int32_t t0;
    t0 = std_core_pow5_factor(l0);
    return (t0 >= l1);
}

vader_box_t std_core_parse_f64(vader_string_t l0) {
    void* l1 = NULL;
    vader_box_t l2 = vader_box_null();
    uint64_t l3, l5;
    int32_t l4;
    bool l6;
    bool t0;
    uint64_t t1;
    int64_t t2;
    double t3;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[1] = { &l1 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = std_core_scan_decimal(l0);
    if (l2.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l1 = l2.payload.obj;
    t0 = ((vader_struct_std_core_DecimalParts_t*) l1)->f_too_many_digits;
    if (t0) {
        l3 = ((vader_struct_std_core_DecimalParts_t*) l1)->f_w;
        l4 = ((vader_struct_std_core_DecimalParts_t*) l1)->f_q;
        l3 = std_core_eisel_lemire(l3, l4);
        t1 = ((vader_struct_std_core_DecimalParts_t*) l1)->f_w;
        t2 = vader_chk_add(u64, t1, INT64_C(1));
        l5 = (uint64_t) (int64_t) t2;
        l4 = ((vader_struct_std_core_DecimalParts_t*) l1)->f_q;
        l5 = std_core_eisel_lemire(l5, l4);
        if (l3 != l5) {
            l6 = ((vader_struct_std_core_DecimalParts_t*) l1)->f_negative;
            t3 = std_core_parse_f64_slow(l0, l6);
            { vader_box_t __vret = vader_box_f64(298u, t3); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l3 = ((vader_struct_std_core_DecimalParts_t*) l1)->f_w;
    l4 = ((vader_struct_std_core_DecimalParts_t*) l1)->f_q;
    l3 = std_core_eisel_lemire(l3, l4);
    t0 = ((vader_struct_std_core_DecimalParts_t*) l1)->f_negative;
    if (t0) {
        t2 = (INT64_C(1) << INT64_C(63));
        l5 = (uint64_t) (int64_t) t2;
        t2 = (l3 | l5);
        l3 = (uint64_t) (int64_t) t2;
        { vader_box_t __vret = vader_box_f64(298u, (((union { uint64_t __vu; double __vd; }){ .__vu = (uint64_t)(l3) }).__vd)); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = vader_box_f64(298u, (((union { uint64_t __vu; double __vd; }){ .__vu = (uint64_t)(l3) }).__vd)); vader_gc_top = gc_frame.prev; return __vret; }
}

static double std_core_parse_f64_slow(vader_string_t l0, bool l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    void* l10 = NULL;
    uint64_t l3, l11, l12, l13;
    int32_t l5, l7, l8, l9;
    bool l6;
    bool t0;
    int32_t t1;
    uint32_t t2;
    int64_t t3;
    void** gc_raw_roots[3] = { &l2, &l4, &l10 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = std_core_sd_scan(l0);
    if (l1) {
        l3 = (uint64_t) (int64_t) INT64_MIN;
    } else {
        l3 = (uint64_t) 0;
    }
    t0 = std_core_is_zero(((vader_struct_std_core_SlowParts_t*) l2)->f_d);
    if (t0) {
        { double __vret = (((union { uint64_t __vu; double __vd; }){ .__vu = (uint64_t)(l3) }).__vd); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = ((vader_struct_std_core_SlowParts_t*) l2)->f_d;
    l5 = INT32_C(0);
    l6 = false;
    t1 = ((vader_struct_std_core_SlowParts_t*) l2)->f_e;
    if ((t1 >= INT32_C(0))) {
        l7 = INT32_C(0);
        l8 = ((vader_struct_std_core_SlowParts_t*) l2)->f_e;
        while ((l7 < l8)) {
            l4 = std_core_BigInt_Mul_mul(l4, (uint32_t) 5);
            l7 = (l7 + INT32_C(1));
        }
        l5 = ((vader_struct_std_core_SlowParts_t*) l2)->f_e;
    } else {
        t1 = ((vader_struct_std_core_SlowParts_t*) l2)->f_e;
        l7 = vader_chk_neg(i32, t1);
        t1 = vader_chk_mul(i32, l7, INT32_C(4));
        l8 = vader_chk_add(i32, t1, INT32_C(64));
        l4 = std_core_shl(((vader_struct_std_core_SlowParts_t*) l2)->f_d, l8);
        l9 = INT32_C(0);
        while ((l9 < l7)) {
            l10 = std_core_BigInt_Div_div(l4, (uint32_t) 5);
            l4 = ((vader_struct___Tuple_Array_u32_u32_6fc96a7e_t*) l10)->f__0;
            t2 = ((vader_struct___Tuple_Array_u32_u32_6fc96a7e_t*) l10)->f__1;
            if (t2 != INT32_C(0)) {
                l6 = true;
            }
            l9 = (l9 + INT32_C(1));
        }
        t1 = ((vader_struct_std_core_SlowParts_t*) l2)->f_e;
        l5 = vader_chk_sub(i32, t1, l8);
    }
    l7 = std_core_bit_len(l4);
    t1 = vader_chk_sub(i32, l7, INT32_C(1));
    l8 = vader_chk_add(i32, t1, l5);
    if ((l8 >= INT32_C(1024))) {
        t3 = (INT64_C(2047) << INT64_C(52));
        l11 = (uint64_t) (int64_t) t3;
        { double __vret = (((union { uint64_t __vu; double __vd; }){ .__vu = (uint64_t)((l3 | l11)) }).__vd); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!((l8 >= INT32_C(-1022)))) {
        l9 = vader_chk_sub(i32, INT32_C(-1074), l5);
        l12 = std_core_sd_round_at(l4, l9, l6);
        { double __vret = (((union { uint64_t __vu; double __vd; }){ .__vu = (uint64_t)((l3 | l12)) }).__vd); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = vader_chk_add(i32, l8, INT32_C(1023));
    l7 = vader_chk_sub(i32, l7, INT32_C(53));
    l11 = std_core_sd_round_at(l4, l7, l6);
    t3 = (INT64_C(1) << INT64_C(53));
    l12 = (uint64_t) (int64_t) t3;
    if ((l11 >= l12)) {
        l11 = (l11 >> INT64_C(1));
        l5 = vader_chk_add(i32, l5, INT32_C(1));
    }
    if (!((l5 >= INT32_C(2047)))) {
        t3 = (((int64_t) (int32_t) l5) << INT64_C(52));
        l12 = (uint64_t) (int64_t) t3;
        t3 = (l3 | l12);
        l12 = (uint64_t) (int64_t) t3;
        t3 = vader_chk_sub(u64, (INT64_C(1) << INT64_C(52)), INT64_C(1));
        l13 = (uint64_t) (int64_t) t3;
        t3 = (l11 & l13);
        l13 = (uint64_t) (int64_t) t3;
        { double __vret = (((union { uint64_t __vu; double __vd; }){ .__vu = (uint64_t)((l12 | l13)) }).__vd); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t3 = (INT64_C(2047) << INT64_C(52));
    l11 = (uint64_t) (int64_t) t3;
    { double __vret = (((union { uint64_t __vu; double __vd; }){ .__vu = (uint64_t)((l3 | l11)) }).__vd); vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t std_core_pf_clz64(uint64_t l0) {
    int32_t l1;
    uint64_t l2;
    int64_t t0;
    l1 = INT32_C(0);
    l2 = l0;
    while ((l2 & INT64_MIN) == INT64_C(0)) {
        t0 = (l2 << INT64_C(1));
        l2 = (uint64_t) (int64_t) t0;
        l1 = vader_chk_add(i32, l1, INT32_C(1));
    }
    return l1;
}

static bool std_core_pf_is_digit(uint8_t l0) {
    if ((l0 >= INT32_C(48))) {
        return (l0 <= INT32_C(57));
    }
    return false;
}

static void std_core_pf_product(int32_t l0, uint64_t l1, uint64_t* __o0, uint64_t* __o1) {
    int32_t l2;
    int64_t l3;
    uint64_t l4, l5, l7;
    void* l6;
    int32_t t0;
    void* t1;
    int64_t t2;
    uint64_t t3, t4;
    l2 = vader_chk_sub(i32, l0, INT32_C(-342));
    t0 = vader_chk_mul(i32, INT32_C(2), l2);
    l3 = ((int64_t) (int32_t) t0);
    t1 = (void*) &vader_data_0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t1);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    t2 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
    l4 = (uint64_t) (int64_t) t2;
    std_core_umul128(l1, l4, &t3, &t4);
    l5 = t4;
    l4 = t3;
    if ((l4 & INT64_C(511)) == INT64_C(511)) {
        l6 = (void*) &vader_data_0;
        l3 = vader_chk_add(i64, l3, INT64_C(1));
        vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        t2 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
        l7 = (uint64_t) (int64_t) t2;
        std_core_umul128(l1, l7, &t3, &t4);
        l7 = t3;
        t2 = (l5 + l7);
        l5 = (uint64_t) (int64_t) t2;
        if ((l7 > l5)) {
            t2 = vader_chk_add(u64, l4, INT64_C(1));
            l4 = (uint64_t) (int64_t) t2;
        }
        *__o1 = l5; *__o0 = l4; return;
    }
    *__o1 = l5; *__o0 = l4; return;
}

static int32_t std_core_pow5_factor(uint64_t l0) {
    uint64_t l1;
    int32_t l2;
    int64_t t0;
    l1 = l0;
    l2 = INT32_C(0);
    for (;;) {
        t0 = (l1 * INT64_C(-3689348814741910323));
        l1 = (uint64_t) (int64_t) t0;
        if (!((l1 > INT64_C(3689348814741910323)))) {
            l2 = vader_chk_add(i32, l2, INT32_C(1));
            continue;
        }
        break;
    }
    return l2;
}

static int32_t std_core_pow5bits(int32_t l0) {
    int64_t t0, t1;
    t0 = vader_chk_mul(u64, ((int64_t) (int32_t) l0), INT64_C(1217359));
    t1 = vader_chk_add(u64, ((uint64_t) (int64_t) t0 >> INT64_C(19)), INT64_C(1));
    return ((int32_t) (int64_t) t1);
}

static vader_string_t std_core_render(uint64_t l0, int32_t l1, bool l2) {
    uint64_t l3;
    int32_t l4;
    void* l5 = NULL;
    int64_t l6, l7;
    uint64_t t0;
    vader_string_t t1 = 0;
    void** gc_raw_roots[1] = { &l5 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = l0;
    l4 = l1;
    for (;;) {
        t0 = vader_mod_u64(l3, INT64_C(10));
        if (t0 == INT64_C(0)) {
            l3 = vader_div_u64(l3, INT64_C(10));
            l4 = vader_chk_add(i32, l4, INT32_C(1));
            continue;
        }
        break;
    }
    l5 = (void*) vader_buffer_new((size_t) INT64_C(25));
    l6 = INT64_C(0);
    if (l2) {
        vader_buffer_store_u8((vader_buffer_t*) l5, (size_t) INT64_C(0), (uint8_t) INT32_C(45));
        l6 = INT64_C(1);
        l7 = std_core_write_decimal(l5, l6, l3, l4);
        t1 = vader_buffer_intern_string((vader_buffer_t*) l5, (size_t) l7);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l7 = std_core_write_decimal(l5, l6, l3, l4);
    t1 = vader_buffer_intern_string((vader_buffer_t*) l5, (size_t) l7);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t std_core_scan_decimal(vader_string_t l0) {
    int64_t l1, l2;
    bool l3, l7, l8, l10;
    uint64_t l4, l9;
    int32_t l5, l6, l11, l12;
    uint8_t t0;
    bool t1;
    int32_t t2;
    int64_t t3, t4;
    void* t5 = NULL;
    void** gc_raw_roots[1] = { &t5 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_host_std_core_byte_len(l0);
    if (l1 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = INT64_C(0);
    l3 = false;
    t0 = vader_host_std_core_byte_at(l0, INT64_C(0));
    if (t0 == INT32_C(45)) {
        l3 = true;
        l2 = INT64_C(1);
    } else {
        t0 = vader_host_std_core_byte_at(l0, INT64_C(0));
        if (t0 == INT32_C(43)) {
            l2 = INT64_C(1);
        }
    }
    l4 = (uint64_t) 0;
    l5 = INT32_C(0);
    l6 = INT32_C(0);
    l7 = false;
    l8 = false;
    while ((l2 < l1)) {
        t0 = vader_host_std_core_byte_at(l0, l2);
        t1 = std_core_pf_is_digit(t0);
        if (!(t1)) {
            break;
        }
        l8 = true;
        t0 = vader_host_std_core_byte_at(l0, l2);
        t2 = vader_chk_sub(u8, t0, INT32_C(48));
        t3 = ((int64_t) (uint32_t) t2);
        l9 = (uint64_t) (int64_t) t3;
        if ((l5 < INT32_C(19))) {
            if (l4 != INT64_C(0)) {
                l10 = true;
            } else {
                l10 = l9 != INT64_C(0);
            }
            if (l10) {
                t3 = vader_chk_mul(u64, l4, INT64_C(10));
                t4 = vader_chk_add(u64, t3, l9);
                l4 = (uint64_t) (int64_t) t4;
                l5 = vader_chk_add(i32, l5, INT32_C(1));
            }
        } else {
            l6 = vader_chk_add(i32, l6, INT32_C(1));
            l7 = true;
        }
        l2 = vader_chk_add(i64, l2, INT64_C(1));
    }
    if ((l2 < l1)) {
        t0 = vader_host_std_core_byte_at(l0, l2);
        if (t0 == INT32_C(46)) {
            l2 = vader_chk_add(i64, l2, INT64_C(1));
            while ((l2 < l1)) {
                t0 = vader_host_std_core_byte_at(l0, l2);
                t1 = std_core_pf_is_digit(t0);
                if (!(t1)) {
                    break;
                }
                l8 = true;
                t0 = vader_host_std_core_byte_at(l0, l2);
                t2 = vader_chk_sub(u8, t0, INT32_C(48));
                t3 = ((int64_t) (uint32_t) t2);
                l9 = (uint64_t) (int64_t) t3;
                if ((l5 < INT32_C(19))) {
                    if (l4 != INT64_C(0)) {
                        l10 = true;
                    } else {
                        l10 = l9 != INT64_C(0);
                    }
                    if (l10) {
                        t3 = vader_chk_mul(u64, l4, INT64_C(10));
                        t4 = vader_chk_add(u64, t3, l9);
                        l4 = (uint64_t) (int64_t) t4;
                        l5 = vader_chk_add(i32, l5, INT32_C(1));
                    }
                    l6 = vader_chk_sub(i32, l6, INT32_C(1));
                } else {
                    l7 = true;
                }
                l2 = vader_chk_add(i64, l2, INT64_C(1));
            }
        }
    }
    if (!(l8)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    if ((l2 < l1)) {
        t0 = vader_host_std_core_byte_at(l0, l2);
        if (t0 == INT32_C(101)) {
            l10 = true;
        } else {
            t0 = vader_host_std_core_byte_at(l0, l2);
            l10 = t0 == INT32_C(69);
        }
        l8 = l10;
    } else {
        l8 = false;
    }
    if (l8) {
        l2 = vader_chk_add(i64, l2, INT64_C(1));
        l8 = false;
        if ((l2 < l1)) {
            t0 = vader_host_std_core_byte_at(l0, l2);
            l10 = t0 == INT32_C(45);
        } else {
            l10 = false;
        }
        if (l10) {
            l8 = true;
            l2 = vader_chk_add(i64, l2, INT64_C(1));
        } else if ((l2 < l1)) {
            t0 = vader_host_std_core_byte_at(l0, l2);
            if (t0 == INT32_C(43)) {
                l2 = vader_chk_add(i64, l2, INT64_C(1));
            }
        }
        if ((l2 >= l1)) {
            { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
        }
        t0 = vader_host_std_core_byte_at(l0, l2);
        t1 = std_core_pf_is_digit(t0);
        if (t1) {
            l5 = INT32_C(0);
            while ((l2 < l1)) {
                t0 = vader_host_std_core_byte_at(l0, l2);
                t1 = std_core_pf_is_digit(t0);
                if (!(t1)) {
                    break;
                }
                if ((l5 < INT32_C(100000))) {
                    l11 = vader_chk_mul(i32, l5, INT32_C(10));
                    t0 = vader_host_std_core_byte_at(l0, l2);
                    t2 = vader_chk_sub(u8, t0, INT32_C(48));
                    l12 = t2;
                    l5 = vader_chk_add(i32, l11, l12);
                }
                l2 = vader_chk_add(i64, l2, INT64_C(1));
            }
            if (l8) {
                l6 = vader_chk_sub(i32, l6, l5);
            } else {
                l6 = vader_chk_add(i32, l6, l5);
            }
        } else {
            { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
        }
    }
    if (!(l2 != l1)) {
        vader_struct_std_core_DecimalParts_t* _a0_obj = (vader_struct_std_core_DecimalParts_t*) vader_gc_alloc(sizeof(vader_struct_std_core_DecimalParts_t));
        vader_obj_header_init(_a0_obj, 529u);
        _a0_obj->f_w = l4;
        _a0_obj->f_q = l6;
        _a0_obj->f_negative = l3;
        _a0_obj->f_too_many_digits = l7;
        t5 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t5); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static uint64_t std_core_sd_round_at(void* l0, int32_t l1, bool l2) {
    uint64_t l3, l4;
    int32_t l5;
    bool l6, l7;
    int32_t t0;
    int64_t t1;
    uint64_t t2;
    if ((l1 <= INT32_C(0))) {
        l3 = std_core_bits64(l0, INT32_C(0));
        t0 = vader_chk_neg(i32, l1);
        t1 = ((int64_t) (int32_t) t0);
        l4 = (uint64_t) (int64_t) t1;
        return (uint64_t) (int64_t) (l3 << (l4 & 63));
    }
    l3 = std_core_bits64(l0, l1);
    l5 = vader_chk_sub(i32, l1, INT32_C(1));
    t2 = std_core_bits64(l0, l5);
    l6 = (t2 & INT64_C(1)) == INT64_C(1);
    if (l2) {
        l7 = true;
    } else {
        l5 = vader_chk_sub(i32, l1, INT32_C(1));
        l7 = std_core_any_below(l0, l5);
    }
    if (l6) {
        if (l7) {
            l7 = true;
        } else {
            l7 = (l3 & INT64_C(1)) == INT64_C(1);
        }
        l6 = l7;
    } else {
        l6 = false;
    }
    if (!(l6)) {
        return l3;
    }
    t1 = vader_chk_add(u64, l3, INT64_C(1));
    return (uint64_t) (int64_t) t1;
}

static void* std_core_sd_scan(vader_string_t l0) {
    int64_t l1, l2;
    bool l3, l7;
    void* l4 = NULL;
    int32_t l5, l9, l10, l11;
    uint8_t l6;
    uint32_t l8;
    uint8_t t0;
    bool t1;
    int32_t t2;
    void* t3 = NULL;
    void** gc_raw_roots[2] = { &l4, &t3 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_host_std_core_byte_len(l0);
    l2 = INT64_C(0);
    t0 = vader_host_std_core_byte_at(l0, INT64_C(0));
    if (t0 == INT32_C(45)) {
        l3 = true;
    } else {
        t0 = vader_host_std_core_byte_at(l0, INT64_C(0));
        l3 = t0 == INT32_C(43);
    }
    if (l3) {
        l2 = INT64_C(1);
    }
    vader_array_t* _a0_arr = vader_array_new(19u, 1u, 3u, 295u);
    ((int32_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int32_t) INT32_C(0);
    l4 = (void*) _a0_arr;
    l5 = INT32_C(0);
    l3 = false;
    while ((l2 < l1)) {
        t0 = vader_host_std_core_byte_at(l0, l2);
        t1 = std_core_pf_is_digit(t0);
        if (!(t1)) {
            break;
        }
        t0 = vader_host_std_core_byte_at(l0, l2);
        t2 = vader_chk_sub(u8, t0, INT32_C(48));
        l6 = (uint8_t) (int32_t) t2;
        if (l3) {
            l7 = true;
        } else {
            l7 = l6 != INT32_C(0);
        }
        if (l7) {
            t2 = ((int32_t) (uint8_t) l6);
            l8 = (uint32_t) (int32_t) t2;
            l4 = std_core_mul_add_small(l4, (uint32_t) 10, l8);
            l3 = true;
        }
        l2 = vader_chk_add(i64, l2, INT64_C(1));
    }
    if ((l2 < l1)) {
        t0 = vader_host_std_core_byte_at(l0, l2);
        if (t0 == INT32_C(46)) {
            l2 = vader_chk_add(i64, l2, INT64_C(1));
            while ((l2 < l1)) {
                t0 = vader_host_std_core_byte_at(l0, l2);
                t1 = std_core_pf_is_digit(t0);
                if (!(t1)) {
                    break;
                }
                t0 = vader_host_std_core_byte_at(l0, l2);
                t2 = vader_chk_sub(u8, t0, INT32_C(48));
                l6 = (uint8_t) (int32_t) t2;
                if (l3) {
                    l7 = true;
                } else {
                    l7 = l6 != INT32_C(0);
                }
                if (l7) {
                    t2 = ((int32_t) (uint8_t) l6);
                    l8 = (uint32_t) (int32_t) t2;
                    l4 = std_core_mul_add_small(l4, (uint32_t) 10, l8);
                    l3 = true;
                }
                l5 = vader_chk_sub(i32, l5, INT32_C(1));
                l2 = vader_chk_add(i64, l2, INT64_C(1));
            }
        }
    }
    if ((l2 < l1)) {
        t0 = vader_host_std_core_byte_at(l0, l2);
        if (t0 == INT32_C(101)) {
            l7 = true;
        } else {
            t0 = vader_host_std_core_byte_at(l0, l2);
            l7 = t0 == INT32_C(69);
        }
        l3 = l7;
    } else {
        l3 = false;
    }
    if (l3) {
        l2 = vader_chk_add(i64, l2, INT64_C(1));
        l3 = false;
        if ((l2 < l1)) {
            t0 = vader_host_std_core_byte_at(l0, l2);
            l7 = t0 == INT32_C(45);
        } else {
            l7 = false;
        }
        if (l7) {
            l3 = true;
            l2 = vader_chk_add(i64, l2, INT64_C(1));
        } else if ((l2 < l1)) {
            t0 = vader_host_std_core_byte_at(l0, l2);
            if (t0 == INT32_C(43)) {
                l2 = vader_chk_add(i64, l2, INT64_C(1));
            }
        }
        l9 = INT32_C(0);
        while ((l2 < l1)) {
            t0 = vader_host_std_core_byte_at(l0, l2);
            t1 = std_core_pf_is_digit(t0);
            if (!(t1)) {
                break;
            }
            if ((l9 < INT32_C(100000))) {
                l10 = vader_chk_mul(i32, l9, INT32_C(10));
                t0 = vader_host_std_core_byte_at(l0, l2);
                t2 = vader_chk_sub(u8, t0, INT32_C(48));
                l11 = t2;
                l9 = vader_chk_add(i32, l10, l11);
            }
            l2 = vader_chk_add(i64, l2, INT64_C(1));
        }
        if (l3) {
            l5 = vader_chk_sub(i32, l5, l9);
        } else {
            l5 = vader_chk_add(i32, l5, l9);
        }
        vader_struct_std_core_SlowParts_t* _a1_obj = (vader_struct_std_core_SlowParts_t*) vader_gc_alloc(sizeof(vader_struct_std_core_SlowParts_t));
        vader_obj_header_init(_a1_obj, 531u);
        _a1_obj->f_d = l4;
        _a1_obj->f_e = l5;
        t3 = (void*) _a1_obj;
        { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_std_core_SlowParts_t* _a2_obj = (vader_struct_std_core_SlowParts_t*) vader_gc_alloc(sizeof(vader_struct_std_core_SlowParts_t));
    vader_obj_header_init(_a2_obj, 531u);
    _a2_obj->f_d = l4;
    _a2_obj->f_e = l5;
    t3 = (void*) _a2_obj;
    { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static uint64_t std_core_shiftright128(uint64_t l0, uint64_t l1, uint64_t l2) {
    uint64_t l3, l4;
    int64_t t0;
    t0 = vader_chk_sub(u64, INT64_C(64), l2);
    l3 = (uint64_t) (int64_t) t0;
    t0 = (l1 << (l3 & 63));
    l3 = (uint64_t) (int64_t) t0;
    l4 = (l0 >> (l2 & 63));
    return (uint64_t) (int64_t) (l3 | l4);
}

static void* std_core_shl(void* l0, int32_t l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    int32_t l5;
    uint32_t l6, l12;
    uint64_t l7, l8, l9, l10, l11;
    int32_t t0;
    vader_box_t t1 = vader_box_null();
    uint32_t t2;
    int64_t t3;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(19u, 0u, 3u, 295u);
    l2 = (void*) _a0_arr;
    l3 = INT64_C(0);
    t0 = vader_div_i32(l1, INT32_C(32));
    l4 = ((int64_t) (int32_t) t0);
    vader_array_t* _pc9_hdr = (vader_array_t*) l2;
    size_t _pc9_len = _pc9_hdr->length;
    size_t _pc9_cap = (_pc9_hdr->offset == 0 && !vader_array_is_borrowed(_pc9_hdr) && _pc9_hdr->length >= _pc9_hdr->buf->length) ? _pc9_hdr->capacity : (size_t) 0;
    void* _pc9_slots = _pc9_hdr->buf->slots;
    for (;;) {
        if ((l3 < l4)) {
            if (VADER_LIKELY(_pc9_len < _pc9_cap)) {
                ((int32_t*) _pc9_slots)[_pc9_len] = (int32_t) (INT32_C(0));
                _pc9_len += 1;
            } else {
                _pc9_hdr->length = _pc9_len;
                if (_pc9_hdr->buf->length < _pc9_len) {
                    _pc9_hdr->buf->length = _pc9_len;
                }
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                _pc9_hdr = (vader_array_t*) l2;
                _pc9_len = _pc9_hdr->length;
                _pc9_cap = (_pc9_hdr->offset == 0 && !vader_array_is_borrowed(_pc9_hdr) && _pc9_hdr->length >= _pc9_hdr->buf->length) ? _pc9_hdr->capacity : (size_t) 0;
                _pc9_slots = _pc9_hdr->buf->slots;
            }
            l3 = (l3 + INT64_C(1));
            continue;
        }
        _pc9_hdr->length = _pc9_len;
        if (_pc9_hdr->buf->length < _pc9_len) {
            _pc9_hdr->buf->length = _pc9_len;
        }
        break;
    }
    l5 = vader_mod_i32(l1, INT32_C(32));
    if (l5 == INT32_C(0)) {
        l3 = INT64_C(0);
        l4 = ((vader_array_t*) l0)->length;
        vader_array_t* _pc36_hdr = (vader_array_t*) l2;
        size_t _pc36_len = _pc36_hdr->length;
        size_t _pc36_cap = (_pc36_hdr->offset == 0 && !vader_array_is_borrowed(_pc36_hdr) && _pc36_hdr->length >= _pc36_hdr->buf->length) ? _pc36_hdr->capacity : (size_t) 0;
        void* _pc36_slots = _pc36_hdr->buf->slots;
        for (;;) {
            if ((l3 < l4)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                t1 = vader_box_i32(295u, ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3]);
                l6 = ((uint32_t) t1.payload.i);
                if (VADER_LIKELY(_pc36_len < _pc36_cap)) {
                    ((int32_t*) _pc36_slots)[_pc36_len] = (int32_t) ((int32_t) (uint32_t) l6);
                    _pc36_len += 1;
                } else {
                    _pc36_hdr->length = _pc36_len;
                    if (_pc36_hdr->buf->length < _pc36_len) {
                        _pc36_hdr->buf->length = _pc36_len;
                    }
                    vader_array_push_i32((vader_array_t*) l2, (int32_t) (uint32_t) l6);
                    _pc36_hdr = (vader_array_t*) l2;
                    _pc36_len = _pc36_hdr->length;
                    _pc36_cap = (_pc36_hdr->offset == 0 && !vader_array_is_borrowed(_pc36_hdr) && _pc36_hdr->length >= _pc36_hdr->buf->length) ? _pc36_hdr->capacity : (size_t) 0;
                    _pc36_slots = _pc36_hdr->buf->slots;
                }
                l3 = (l3 + INT64_C(1));
                continue;
            }
            _pc36_hdr->length = _pc36_len;
            if (_pc36_hdr->buf->length < _pc36_len) {
                _pc36_hdr->buf->length = _pc36_len;
            }
            break;
        }
        { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = (uint32_t) 0;
    l3 = INT64_C(0);
    l4 = ((vader_array_t*) l0)->length;
    while ((l3 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t1 = vader_box_i32(295u, ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3]);
        t2 = ((uint32_t) t1.payload.i);
        t3 = ((int64_t) (uint32_t) t2);
        l7 = (uint64_t) (int64_t) t3;
        t3 = ((int64_t) (int32_t) l5);
        l8 = (uint64_t) (int64_t) t3;
        t3 = (l7 << (l8 & 63));
        l9 = (uint64_t) (int64_t) t3;
        t3 = ((int64_t) (uint32_t) l6);
        l10 = (uint64_t) (int64_t) t3;
        t3 = (l9 | l10);
        l11 = (uint64_t) (int64_t) t3;
        t0 = ((int32_t) (int64_t) (l11 & INT64_C(4294967295)));
        l12 = (uint32_t) (int32_t) t0;
        vader_array_push_i32((vader_array_t*) l2, (int32_t) (uint32_t) l12);
        t0 = ((int32_t) (uint64_t) (l11 >> INT64_C(32)));
        l6 = (uint32_t) (int32_t) t0;
        l3 = (l3 + INT64_C(1));
    }
    if (l6 != INT32_C(0)) {
        vader_array_push_i32((vader_array_t*) l2, (int32_t) (uint32_t) l6);
        { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool std_core_string_Equals_equals_guard(vader_string_t l0, vader_box_t l1) {
    vader_string_t l2;
    if (l1.tag == 288u) {
        l2 = l1.payload.s;
        return l0 == l2;
    }
    return false;
}

uint64_t std_core_string_Hash_hash_vt(vader_string_t l0) {
    uint64_t t0;
    t0 = vader_host_std_core_string_Hash_hash(l0);
    return t0;
}

vader_string_t std_core_string_Index_at_1(vader_string_t l0, void* l1) {
    int64_t l2, l3, l4, l5;
    bool t0;
    vader_string_t t1;
    t0 = vader_host_std_core_is_ascii(l0);
    if (!(t0)) {
        l2 = ((vader_struct_std_core_Range__i64_t*) l1)->f_start;
        l3 = std_core_codepoint_offset(l0, INT64_C(0), l2);
        l4 = std_core_codepoint_count(l1);
        l5 = std_core_codepoint_offset(l0, l3, l4);
        t1 = vader_host_std_core_byte_slice(l0, l3, l5);
        return t1;
    }
    l2 = ((vader_struct_std_core_Range__i64_t*) l1)->f_start;
    l3 = ((vader_struct_std_core_Range__i64_t*) l1)->f_start;
    l4 = std_core_codepoint_count(l1);
    l3 = vader_chk_add(i64, l3, l4);
    t1 = vader_host_std_core_byte_slice(l0, l2, l3);
    return t1;
}

static bool std_core_u16_Equals_equals_guard(uint16_t l0, vader_box_t l1) {
    uint16_t l2;
    if (l1.tag == 294u) {
        l2 = ((uint16_t) l1.payload.i);
        return l0 == l2;
    }
    return false;
}

static uint64_t std_core_u16_Hash_hash(uint16_t l0) {
    return (uint64_t) (int64_t) ((int64_t) (uint16_t) l0);
}

static bool std_core_u32_Equals_equals_guard(uint32_t l0, vader_box_t l1) {
    uint32_t l2;
    if (l1.tag == 295u) {
        l2 = ((uint32_t) l1.payload.i);
        return l0 == l2;
    }
    return false;
}

static uint64_t std_core_u32_Hash_hash(uint32_t l0) {
    return (uint64_t) (int64_t) ((int64_t) (uint32_t) l0);
}

vader_string_t std_core_u64_Display_to_string(uint64_t l0) {
    vader_string_t t0 = 0;
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = std_core_format_unsigned(l0);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool std_core_u64_Equals_equals_guard(uint64_t l0, vader_box_t l1) {
    uint64_t l2;
    if (l1.tag == 296u) {
        l2 = ((uint64_t) l1.payload.i);
        return l0 == l2;
    }
    return false;
}

uint64_t std_core_u64_Hash_hash(uint64_t l0) {
    return l0;
}

static bool std_core_u8_Equals_equals_guard(uint8_t l0, vader_box_t l1) {
    uint8_t l2;
    if (l1.tag == 293u) {
        l2 = ((uint8_t) l1.payload.i);
        return l0 == l2;
    }
    return false;
}

static uint64_t std_core_u8_Hash_hash(uint8_t l0) {
    return (uint64_t) (int64_t) ((int64_t) (uint8_t) l0);
}

static void std_core_umul128(uint64_t l0, uint64_t l1, uint64_t* __o0, uint64_t* __o1) {
    uint64_t l2, l3, l4, l5, l6;
    int64_t t0;
    t0 = (l0 & INT64_C(4294967295));
    l2 = (uint64_t) (int64_t) t0;
    l3 = (l0 >> INT64_C(32));
    t0 = (l1 & INT64_C(4294967295));
    l4 = (uint64_t) (int64_t) t0;
    l5 = (l1 >> INT64_C(32));
    t0 = vader_chk_mul(u64, l2, l4);
    l6 = (uint64_t) (int64_t) t0;
    t0 = vader_chk_mul(u64, l2, l5);
    l2 = (uint64_t) (int64_t) t0;
    t0 = vader_chk_mul(u64, l3, l4);
    l4 = (uint64_t) (int64_t) t0;
    t0 = vader_chk_mul(u64, l3, l5);
    l3 = (uint64_t) (int64_t) t0;
    l5 = (l6 >> INT64_C(32));
    t0 = vader_chk_add(u64, l4, l5);
    l4 = (uint64_t) (int64_t) t0;
    t0 = (l4 & INT64_C(4294967295));
    l5 = (uint64_t) (int64_t) t0;
    t0 = vader_chk_add(u64, l2, l5);
    l2 = (uint64_t) (int64_t) t0;
    l4 = (l4 >> INT64_C(32));
    t0 = vader_chk_add(u64, l3, l4);
    l3 = (uint64_t) (int64_t) t0;
    l4 = (l2 >> INT64_C(32));
    t0 = vader_chk_add(u64, l3, l4);
    l3 = (uint64_t) (int64_t) t0;
    t0 = ((l2 & INT64_C(4294967295)) << INT64_C(32));
    l2 = (uint64_t) (int64_t) t0;
    t0 = (l6 & INT64_C(4294967295));
    l4 = (uint64_t) (int64_t) t0;
    t0 = (l2 | l4);
    l2 = (uint64_t) (int64_t) t0;
    *__o1 = l2; *__o0 = l3; return;
}

void* std_core_utf8_encode(uint32_t l0) {
    uint32_t l1, l3;
    void* l2 = NULL;
    uint8_t l4;
    int32_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[2] = { &l2, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((int32_t) (uint32_t) l0);
    l1 = (uint32_t) (int32_t) t0;
    if ((l1 < INT32_C(128))) {
        vader_array_t* _a0_arr = vader_array_new(17u, 1u, 1u, 293u);
        ((uint8_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (uint8_t) (((int32_t) (uint32_t) l1) & INT32_C(255));
        t1 = (void*) _a0_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a1_arr = vader_array_new(17u, 0u, 1u, 293u);
    l2 = (void*) _a1_arr;
    if ((l1 < INT32_C(2048))) {
        l3 = (l1 >> INT32_C(6));
        t0 = ((INT32_C(192) | l3) & INT32_C(255));
        l4 = (uint8_t) (int32_t) t0;
        vader_array_push_u8((vader_array_t*) l2, (int32_t) (uint8_t) l4);
        t0 = (l1 & INT32_C(63));
        l3 = (uint32_t) (int32_t) t0;
        t0 = ((INT32_C(128) | l3) & INT32_C(255));
        l4 = (uint8_t) (int32_t) t0;
        vader_array_push_u8((vader_array_t*) l2, (int32_t) (uint8_t) l4);
        { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if ((l1 < INT32_C(65536))) {
        l3 = (l1 >> INT32_C(12));
        t0 = ((INT32_C(224) | l3) & INT32_C(255));
        l4 = (uint8_t) (int32_t) t0;
        vader_array_push_u8((vader_array_t*) l2, (int32_t) (uint8_t) l4);
        t0 = ((l1 >> INT32_C(6)) & INT32_C(63));
        l3 = (uint32_t) (int32_t) t0;
        t0 = ((INT32_C(128) | l3) & INT32_C(255));
        l4 = (uint8_t) (int32_t) t0;
        vader_array_push_u8((vader_array_t*) l2, (int32_t) (uint8_t) l4);
        t0 = (l1 & INT32_C(63));
        l3 = (uint32_t) (int32_t) t0;
        t0 = ((INT32_C(128) | l3) & INT32_C(255));
        l4 = (uint8_t) (int32_t) t0;
        vader_array_push_u8((vader_array_t*) l2, (int32_t) (uint8_t) l4);
    } else {
        l3 = (l1 >> INT32_C(18));
        t0 = ((INT32_C(240) | l3) & INT32_C(255));
        l4 = (uint8_t) (int32_t) t0;
        vader_array_push_u8((vader_array_t*) l2, (int32_t) (uint8_t) l4);
        t0 = ((l1 >> INT32_C(12)) & INT32_C(63));
        l3 = (uint32_t) (int32_t) t0;
        t0 = ((INT32_C(128) | l3) & INT32_C(255));
        l4 = (uint8_t) (int32_t) t0;
        vader_array_push_u8((vader_array_t*) l2, (int32_t) (uint8_t) l4);
        t0 = ((l1 >> INT32_C(6)) & INT32_C(63));
        l3 = (uint32_t) (int32_t) t0;
        t0 = ((INT32_C(128) | l3) & INT32_C(255));
        l4 = (uint8_t) (int32_t) t0;
        vader_array_push_u8((vader_array_t*) l2, (int32_t) (uint8_t) l4);
        t0 = (l1 & INT32_C(63));
        l1 = (uint32_t) (int32_t) t0;
        t0 = ((INT32_C(128) | l1) & INT32_C(255));
        l4 = (uint8_t) (int32_t) t0;
        vader_array_push_u8((vader_array_t*) l2, (int32_t) (uint8_t) l4);
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

int64_t std_core_write_bool(void* l0, int64_t l1, bool l2) {
    int64_t t0;
    if (!(l2)) {
        t0 = std_core_write_string_at(l0, l1, 1801u);
        return t0;
    }
    t0 = std_core_write_string_at(l0, l1, 2545u);
    return t0;
}

static int64_t std_core_write_decimal(void* l0, int64_t l1, uint64_t l2, int32_t l3) {
    int32_t l4, l5, l7;
    int64_t l6, l8, l9;
    uint8_t l10;
    uint64_t l11;
    int64_t t0;
    int32_t t1;
    l4 = std_core_decimal_width(l2);
    l5 = vader_chk_add(i32, l3, l4);
    if ((INT32_C(-6) < l5)) {
        if ((l5 <= INT32_C(0))) {
            vader_buffer_store_u8((vader_buffer_t*) l0, (size_t) l1, (uint8_t) INT32_C(48));
            l6 = vader_chk_add(i64, l1, INT64_C(1));
            vader_buffer_store_u8((vader_buffer_t*) l0, (size_t) l6, (uint8_t) INT32_C(46));
            l6 = vader_chk_add(i64, l1, INT64_C(2));
            l7 = vader_chk_neg(i32, l5);
            l6 = std_core_write_zeros(l0, l6, l7);
            t0 = std_core_write_digits(l0, l6, l2, l4);
            return t0;
        }
    }
    l6 = std_core_write_digits(l0, l1, l2, l4);
    if ((l4 <= l5)) {
        if ((l5 <= INT32_C(21))) {
            l7 = vader_chk_sub(i32, l5, l4);
            l8 = std_core_write_zeros(l0, l6, l7);
            vader_buffer_store_u8((vader_buffer_t*) l0, (size_t) l8, (uint8_t) INT32_C(46));
            l9 = vader_chk_add(i64, l8, INT64_C(1));
            vader_buffer_store_u8((vader_buffer_t*) l0, (size_t) l9, (uint8_t) INT32_C(48));
            t0 = vader_chk_add(i64, l8, INT64_C(2));
            return t0;
        }
    }
    if ((INT32_C(0) < l5)) {
        if ((l5 <= INT32_C(21))) {
            t0 = std_core_insert_point(l0, l1, l4, l5);
            return t0;
        }
    }
    if ((l4 > INT32_C(1))) {
        l8 = std_core_insert_point(l0, l1, l4, INT32_C(1));
    } else {
        l8 = l6;
    }
    l4 = vader_chk_sub(i32, l5, INT32_C(1));
    vader_buffer_store_u8((vader_buffer_t*) l0, (size_t) l8, (uint8_t) INT32_C(101));
    l6 = vader_chk_add(i64, l8, INT64_C(1));
    if ((l4 < INT32_C(0))) {
        l10 = (uint8_t) 45;
    } else {
        l10 = (uint8_t) 43;
    }
    vader_buffer_store_u8((vader_buffer_t*) l0, (size_t) l6, (uint8_t) l10);
    l6 = vader_chk_add(i64, l8, INT64_C(2));
    if ((l4 < INT32_C(0))) {
        t1 = vader_chk_neg(i32, l4);
        t0 = ((int64_t) (int32_t) t1);
        l11 = (uint64_t) (int64_t) t0;
        t0 = std_core_write_unsigned(l0, l6, l11);
        return t0;
    }
    t0 = ((int64_t) (int32_t) l4);
    l11 = (uint64_t) (int64_t) t0;
    t0 = std_core_write_unsigned(l0, l6, l11);
    return t0;
}

static int64_t std_core_write_digits(void* l0, int64_t l1, uint64_t l2, int32_t l3) {
    uint64_t l4;
    int64_t l5, l6;
    uint8_t l7, l8;
    uint64_t t0;
    int32_t t1;
    l4 = l2;
    l5 = ((int64_t) (int32_t) l3);
    l5 = vader_chk_add(i64, l1, l5);
    l6 = l5;
    while ((l6 > l1)) {
        l6 = vader_chk_sub(i64, l6, INT64_C(1));
        t0 = vader_mod_u64(l4, INT64_C(10));
        t1 = (((int32_t) (uint64_t) t0) & INT32_C(255));
        l7 = (uint8_t) (int32_t) t1;
        t1 = vader_chk_add(u8, INT32_C(48), l7);
        l8 = (uint8_t) (int32_t) t1;
        vader_buffer_store_u8((vader_buffer_t*) l0, (size_t) l6, (uint8_t) l8);
        l4 = vader_div_u64(l4, INT64_C(10));
    }
    return l5;
}

int64_t std_core_write_int(void* l0, int64_t l1, int64_t l2) {
    bool l3;
    int64_t l4, l5;
    uint8_t l6, l7;
    int64_t t0, t1;
    int32_t t2;
    if (l2 == INT64_C(0)) {
        vader_buffer_store_u8((vader_buffer_t*) l0, (size_t) l1, (uint8_t) INT32_C(48));
        t0 = vader_chk_add(i64, l1, INT64_C(1));
        return t0;
    }
    l3 = (l2 < INT64_C(0));
    if ((l2 > INT64_C(0))) {
        l2 = vader_chk_neg(i64, l2);
    }
    l4 = INT64_C(0);
    l5 = l2;
    while (l5 != INT64_C(0)) {
        l4 = vader_chk_add(i64, l4, INT64_C(1));
        l5 = vader_div_i64(l5, INT64_C(10));
    }
    if (l3) {
        l5 = vader_chk_add(i64, l4, INT64_C(1));
    } else {
        l5 = l4;
    }
    l4 = vader_chk_add(i64, l1, l5);
    while (l2 != INT64_C(0)) {
        l4 = vader_chk_sub(i64, l4, INT64_C(1));
        t0 = vader_mod_i64(l2, INT64_C(10));
        t1 = vader_chk_neg(i64, t0);
        t2 = (((int32_t) (int64_t) t1) & INT32_C(255));
        l6 = (uint8_t) (int32_t) t2;
        t2 = vader_chk_add(u8, INT32_C(48), l6);
        l7 = (uint8_t) (int32_t) t2;
        vader_buffer_store_u8((vader_buffer_t*) l0, (size_t) l4, (uint8_t) l7);
        l2 = vader_div_i64(l2, INT64_C(10));
    }
    if (l3) {
        vader_buffer_store_u8((vader_buffer_t*) l0, (size_t) l1, (uint8_t) INT32_C(45));
        t0 = vader_chk_add(i64, l1, l5);
        return t0;
    }
    t0 = vader_chk_add(i64, l1, l5);
    return t0;
}

int64_t std_core_write_string_at(void* l0, int64_t l1, vader_string_t l2) {
    int64_t l3;
    int64_t t0;
    vader_buffer_write_string((vader_buffer_t*) l0, (size_t) l1, l2);
    l3 = vader_host_std_core_byte_len(l2);
    t0 = vader_chk_add(i64, l1, l3);
    return t0;
}

int64_t std_core_write_unsigned(void* l0, int64_t l1, uint64_t l2) {
    int64_t l3, l5;
    uint64_t l4;
    uint8_t l6, l7;
    int64_t t0;
    uint64_t t1;
    int32_t t2;
    if (l2 == INT64_C(0)) {
        vader_buffer_store_u8((vader_buffer_t*) l0, (size_t) l1, (uint8_t) INT32_C(48));
        t0 = vader_chk_add(i64, l1, INT64_C(1));
        return t0;
    }
    l3 = INT64_C(0);
    l4 = l2;
    while (l4 != INT64_C(0)) {
        l3 = vader_chk_add(i64, l3, INT64_C(1));
        l4 = vader_div_u64(l4, INT64_C(10));
    }
    l5 = vader_chk_add(i64, l1, l3);
    while (l2 != INT64_C(0)) {
        l5 = vader_chk_sub(i64, l5, INT64_C(1));
        t1 = vader_mod_u64(l2, INT64_C(10));
        t2 = (((int32_t) (uint64_t) t1) & INT32_C(255));
        l6 = (uint8_t) (int32_t) t2;
        t2 = vader_chk_add(u8, INT32_C(48), l6);
        l7 = (uint8_t) (int32_t) t2;
        vader_buffer_store_u8((vader_buffer_t*) l0, (size_t) l5, (uint8_t) l7);
        l2 = vader_div_u64(l2, INT64_C(10));
    }
    t0 = vader_chk_add(i64, l1, l3);
    return t0;
}

static int64_t std_core_write_zeros(void* l0, int64_t l1, int32_t l2) {
    int32_t l3;
    int64_t l4, l5;
    int64_t t0;
    l3 = INT32_C(0);
    while ((l3 < l2)) {
        l4 = ((int64_t) (int32_t) l3);
        l5 = vader_chk_add(i64, l1, l4);
        vader_buffer_store_u8((vader_buffer_t*) l0, (size_t) l5, (uint8_t) INT32_C(48));
        l3 = (l3 + INT32_C(1));
    }
    l4 = ((int64_t) (int32_t) l2);
    t0 = vader_chk_add(i64, l1, l4);
    return t0;
}
