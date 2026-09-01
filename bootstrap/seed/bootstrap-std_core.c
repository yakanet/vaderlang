#include "bootstrap.split.h"

static void* std_core_BigInt_Div_div(void* l0, uint32_t l1);
static void std_core_Buffer_ByteAccess_store_u8_vt(void* l0, size_t l1, uint8_t l2);
static bool std_core_any_below(void* l0, int32_t l1);
static int32_t std_core_b2i(bool l0);
static uint64_t std_core_b2u(bool l0);
static int32_t std_core_bit_len(void* l0);
static uint64_t std_core_bits64(void* l0, int32_t l1);
static int32_t std_core_clz32(uint32_t l0);
static void* std_core_d2d(uint64_t l0, uint64_t l1);
static void* std_core_digits_of(uint64_t l0);
static uint64_t std_core_eisel_lemire(uint64_t l0, int32_t l1);
static vader_string_t std_core_format_decimal(void* l0, int32_t l1, int32_t l2);
static bool std_core_is_zero(void* l0);
static vader_string_t std_core_join_range(void* l0, int32_t l1, int32_t l2);
static uint64_t std_core_limb(void* l0, size_t l1);
static int32_t std_core_log10_pow2(int32_t l0);
static int32_t std_core_log10_pow5(int32_t l0);
static void* std_core_mul_add_small(void* l0, uint32_t l1, uint32_t l2);
static void* std_core_mul_shift_all_64(uint64_t l0, uint64_t l1, uint64_t l2, int32_t l3, uint64_t l4);
static bool std_core_multiple_of_power_of_2(uint64_t l0, int32_t l1);
static bool std_core_multiple_of_power_of_5(uint64_t l0, int32_t l1);
static double std_core_parse_f64_slow(vader_string_t l0, bool l1);
static int32_t std_core_pf_clz64(uint64_t l0);
static bool std_core_pf_is_digit(uint8_t l0);
static void* std_core_pf_product(int32_t l0, uint64_t l1);
static int32_t std_core_pow5_factor(uint64_t l0);
static int32_t std_core_pow5bits(int32_t l0);
static vader_string_t std_core_render(uint64_t l0, int32_t l1, bool l2);
static vader_box_t std_core_scan_decimal(vader_string_t l0);
static uint64_t std_core_sd_round_at(void* l0, int32_t l1, bool l2);
static void* std_core_sd_scan(vader_string_t l0);
static uint64_t std_core_shiftright128(uint64_t l0, uint64_t l1, uint64_t l2);
static void* std_core_shl(void* l0, int32_t l1);
static void* std_core_umul128(uint64_t l0, uint64_t l1);
static vader_string_t std_core_zeros(int32_t l0);

static void* std_core_BigInt_Div_div(void* l0, uint32_t l1) {
    void* l2 = NULL;
    void* l12 = NULL;
    uint64_t l3, l5, l7, l8, l9, l11;
    int32_t l4;
    size_t l6;
    uint32_t l10;
    size_t t0;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    uint32_t t3;
    uint64_t t4;
    int32_t t5;
    void* t6 = NULL;
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[4] = { &l0, &l2, &l12, &t6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(12u, 0u, 3u, 168u);
    l2 = (void*) _a0_arr;
    l3 = (uint64_t) (int64_t) INT64_C(0);
    t0 = ((vader_array_t*) l0)->length;
    l4 = (((int32_t) (size_t) t0) - INT32_C(1));
    {
        loop_11: {
            if ((l4 >= INT32_C(0))) {
                t1 = (l3 << INT64_C(32));
                l5 = (uint64_t) (int64_t) t1;
                t1 = ((int64_t) (int32_t) l4);
                l6 = (size_t) (int64_t) t1;
                vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l6 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = vader_box_i32(168u, ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l6]);
                t3 = ((uint32_t) t2.payload.i);
                t1 = ((int64_t) (uint32_t) t3);
                l7 = (uint64_t) (int64_t) t1;
                t1 = (l5 | l7);
                l8 = (uint64_t) (int64_t) t1;
                t1 = ((int64_t) (uint32_t) l1);
                l9 = (uint64_t) (int64_t) t1;
                t4 = vader_div_u64(l8, l9);
                t5 = ((int32_t) (uint64_t) t4);
                l10 = (uint32_t) (int32_t) t5;
                vader_array_push_i32((vader_array_t*) l2, (int32_t) (uint32_t) l10);
                t1 = ((int64_t) (uint32_t) l1);
                l11 = (uint64_t) (int64_t) t1;
                l3 = vader_mod_u64(l8, l11);
                l4 = (l4 - INT32_C(1));
                goto loop_11;
            } else {
            }
        }
    }
    vader_array_t* _a2_arr = vader_array_new(12u, 0u, 3u, 168u);
    l12 = (void*) _a2_arr;
    t0 = ((vader_array_t*) l2)->length;
    l4 = (((int32_t) (size_t) t0) - INT32_C(1));
    {
        loop_69: {
            if ((l4 >= INT32_C(0))) {
                t1 = ((int64_t) (int32_t) l4);
                l6 = (size_t) (int64_t) t1;
                vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l6 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = vader_box_i32(168u, ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l6]);
                l10 = ((uint32_t) t2.payload.i);
                vader_array_push_i32((vader_array_t*) l12, (int32_t) (uint32_t) l10);
                l4 = (l4 - INT32_C(1));
                goto loop_69;
            } else {
            }
        }
    }
    t5 = ((int32_t) (uint64_t) l3);
    l10 = (uint32_t) (int32_t) t5;
    vader_struct___Tuple_49_t* _a4_obj = (vader_struct___Tuple_49_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_49_t));
    vader_obj_header_init(_a4_obj, 229u);
    _a4_obj->f__0 = l12;
    _a4_obj->f__1 = l10;
    t6 = (void*) _a4_obj;
    { void* __vret = t6; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_string_t std_core_Buffer_ByteAccess_intern_string_vt(void* l0, size_t l1) {
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = vader_buffer_intern_string((vader_buffer_t*) l0, (size_t) l1);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void std_core_Buffer_ByteAccess_store_u8_vt(void* l0, size_t l1, uint8_t l2) {
    vader_buffer_store_u8((vader_buffer_t*) l0, (size_t) l1, (uint8_t) l2);
    return;
}

void std_core_Buffer_ByteAccess_write_string_vt(void* l0, size_t l1, vader_string_t l2) {
    vader_buffer_write_string((vader_buffer_t*) l0, (size_t) l1, l2);
    return;
}

bool std_core____Contains_contains__ValType(void* l0, uint8_t l1) {
    void* l2;
    size_t l3, l4;
    vader_box_t t0;
    int64_t t1;
    l2 = l0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_7: {
            if ((l4 < l3)) {
                if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l4, 167u);
                if (((int32_t) t0.payload.i) == l1) {
                    return true;
                }
                t1 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t1;
                goto loop_7;
            } else {
            }
        }
    }
    return false;
}

bool std_core____Contains_contains__i32(void* l0, int32_t l1) {
    void* l2;
    size_t l3, l4;
    int32_t t0;
    int64_t t1;
    l2 = l0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_7: {
            if ((l4 < l3)) {
                t0 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
                if (t0 == l1) {
                    return true;
                }
                t1 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t1;
                goto loop_7;
            } else {
            }
        }
    }
    return false;
}

bool std_core____Contains_contains__string(void* l0, vader_string_t l1) {
    void* l2;
    size_t l3, l4;
    vader_box_t t0;
    vader_string_t t1;
    int64_t t2;
    l2 = l0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_7: {
            if ((l4 < l3)) {
                if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l4];
                t1 = t0.payload.s;
                if (t1 == l1) {
                    return true;
                }
                t2 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                goto loop_7;
            } else {
            }
        }
    }
    return false;
}

static bool std_core_any_below(void* l0, int32_t l1) {
    int32_t l2, l3;
    size_t l4, l5;
    bool l6;
    uint32_t l7;
    int64_t t0;
    vader_box_t t1;
    uint32_t t2;
    int32_t t3;
    l2 = vader_div_i32(l1, INT32_C(32));
    l3 = vader_mod_i32(l1, INT32_C(32));
    t0 = ((int64_t) (int32_t) l2);
    l4 = (size_t) (int64_t) t0;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_14: {
            if ((l5 < l4)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l5 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = vader_box_i32(168u, ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l5]);
                t2 = ((uint32_t) t1.payload.i);
                if (t2 != INT32_C(0)) {
                    return true;
                }
                t0 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t0;
                goto loop_14;
            } else {
            }
        }
    }
    if ((l3 > INT32_C(0))) {
        t0 = ((int64_t) (int32_t) l2);
        l4 = (size_t) (int64_t) t0;
        l5 = ((vader_array_t*) l0)->length;
        l6 = (l4 < l5);
    } else {
        l6 = false;
    }
    if (l6) {
        t3 = l3;
        l7 = (uint32_t) (int32_t) t3;
        t3 = ((INT32_C(1) << l7) - INT32_C(1));
        l7 = (uint32_t) (int32_t) t3;
        t0 = ((int64_t) (int32_t) l2);
        l4 = (size_t) (int64_t) t0;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
        if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
        if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
        t1 = vader_box_i32(168u, ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4]);
        t2 = ((uint32_t) t1.payload.i);
        if ((t2 & l7) != INT32_C(0)) {
            return true;
        }
        return false;
    }
    return false;
}

static int32_t std_core_b2i(bool l0) {
    int32_t l1;
    if (l0) {
        l1 = INT32_C(1);
    } else {
        l1 = INT32_C(0);
    }
    return l1;
}

static uint64_t std_core_b2u(bool l0) {
    uint64_t l1;
    if (l0) {
        l1 = (uint64_t) (int64_t) INT64_C(1);
    } else {
        l1 = (uint64_t) (int64_t) INT64_C(0);
    }
    return l1;
}

static int32_t std_core_bit_len(void* l0) {
    int32_t l1, l3, l5, l6;
    size_t l2, l4;
    size_t t0;
    int64_t t1;
    vader_box_t t2;
    uint32_t t3;
    t0 = ((vader_array_t*) l0)->length;
    l1 = (((int32_t) (size_t) t0) - INT32_C(1));
    {
        loop_7: {
            if ((l1 >= INT32_C(0))) {
                t1 = ((int64_t) (int32_t) l1);
                l2 = (size_t) (int64_t) t1;
                vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l2 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = vader_box_i32(168u, ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l2]);
                t3 = ((uint32_t) t2.payload.i);
                if (t3 != INT32_C(0)) {
                    l3 = (l1 * INT32_C(32));
                    t1 = ((int64_t) (int32_t) l1);
                    l4 = (size_t) (int64_t) t1;
                    if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = vader_box_i32(168u, ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4]);
                    t3 = ((uint32_t) t2.payload.i);
                    l5 = std_core_clz32(t3);
                    l6 = (INT32_C(32) - l5);
                    return (l3 + l6);
                }
                l1 = (l1 - INT32_C(1));
                goto loop_7;
            } else {
            }
        }
    }
    return INT32_C(0);
}

static uint64_t std_core_bits64(void* l0, int32_t l1) {
    size_t l2, l5;
    int32_t l3;
    uint64_t l4, l6, l7, l8;
    int32_t t0;
    int64_t t1;
    t0 = vader_div_i32(l1, INT32_C(32));
    t1 = ((int64_t) (int32_t) t0);
    l2 = (size_t) (int64_t) t1;
    l3 = vader_mod_i32(l1, INT32_C(32));
    l4 = std_core_limb(l0, l2);
    t1 = (l2 + INT64_C(1));
    l5 = (size_t) (int64_t) t1;
    l6 = std_core_limb(l0, l5);
    if (l3 == INT32_C(0)) {
        t1 = (l6 << INT64_C(32));
        l7 = (uint64_t) (int64_t) t1;
        return (uint64_t) (int64_t) (l4 | l7);
    }
    t1 = (l2 + INT64_C(2));
    l2 = (size_t) (int64_t) t1;
    l7 = std_core_limb(l0, l2);
    t1 = ((int64_t) (int32_t) l3);
    l8 = (uint64_t) (int64_t) t1;
    l4 = (l4 >> l8);
    t1 = ((int64_t) (int32_t) (INT32_C(32) - l3));
    l8 = (uint64_t) (int64_t) t1;
    t1 = (l6 << l8);
    l6 = (uint64_t) (int64_t) t1;
    t1 = (l4 | l6);
    l4 = (uint64_t) (int64_t) t1;
    t1 = ((int64_t) (int32_t) (INT32_C(64) - l3));
    l6 = (uint64_t) (int64_t) t1;
    t1 = (l7 << l6);
    l6 = (uint64_t) (int64_t) t1;
    return (uint64_t) (int64_t) (l4 | l6);
}

static int32_t std_core_clz32(uint32_t l0) {
    int32_t l1;
    uint32_t l2;
    int32_t t0;
    l1 = INT32_C(0);
    l2 = l0;
    {
        loop_5: {
            if ((l2 & INT32_MIN) == INT32_C(0)) {
                t0 = (l2 << INT32_C(1));
                l2 = (uint32_t) (int32_t) t0;
                l1 = (l1 + INT32_C(1));
                goto loop_5;
            } else {
            }
        }
    }
    return l1;
}

static void* std_core_d2d(uint64_t l0, uint64_t l1) {
    int32_t l2, l11, l13, l14;
    uint64_t l3, l5, l7, l8, l9, l10, l17, l18, l20, l21, l22;
    bool l4, l6, l12, l19, l23;
    void* l15 = NULL;
    size_t l16;
    int64_t t0;
    uint64_t t1;
    bool t2;
    int32_t t3;
    void* t4 = NULL;
    void** gc_raw_roots[2] = { &l15, &t4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1 == INT64_C(0)) {
        l2 = ((INT32_C(-1022) - INT32_C(52)) - INT32_C(2));
        l3 = l0;
    } else {
        l2 = (((((int32_t) (uint64_t) l1) - INT32_C(1023)) - INT32_C(52)) - INT32_C(2));
        t0 = ((INT64_C(1) << INT64_C(52)) | l0);
        l3 = (uint64_t) (int64_t) t0;
    }
    l4 = (l3 & INT64_C(1)) == INT64_C(0);
    t0 = (l3 * INT64_C(4));
    l5 = (uint64_t) (int64_t) t0;
    if (l0 != INT64_C(0)) {
        l6 = true;
    } else {
        l6 = (l1 <= INT64_C(1));
    }
    l7 = std_core_b2u(l6);
    l6 = false;
    l12 = false;
    if ((l2 >= INT32_C(0))) {
        l11 = std_core_log10_pow2(l2);
        l13 = std_core_b2i((l2 > INT32_C(3)));
        l13 = (l11 - l13);
        l11 = l13;
        l14 = std_core_pow5bits(l13);
        l14 = ((INT32_C(125) + l14) - INT32_C(1));
        l14 = ((-(l2) + l13) + l14);
        l15 = (void*) &vader_data_1;
        t0 = ((int64_t) (int32_t) l13);
        l16 = (size_t) (int64_t) t0;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l15);
        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
        if ((size_t) l16 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
        t0 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l16];
        l8 = (uint64_t) (int64_t) t0;
        l15 = (void*) &vader_data_2;
        t0 = ((int64_t) (int32_t) l13);
        l16 = (size_t) (int64_t) t0;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l15);
        if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
        if ((size_t) l16 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
        t0 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l16];
        l9 = (uint64_t) (int64_t) t0;
        l15 = std_core_mul_shift_all_64(l3, l8, l9, l14, l7);
        l8 = ((vader_struct___Tuple_52_t*) l15)->f__0;
        l9 = ((vader_struct___Tuple_52_t*) l15)->f__1;
        l10 = ((vader_struct___Tuple_52_t*) l15)->f__2;
        if ((l13 <= INT32_C(21))) {
            t1 = vader_div_u64(l5, INT64_C(5));
            t0 = (t1 * INT64_C(5));
            l17 = (uint64_t) (int64_t) t0;
            if ((l5 - l17) == INT64_C(0)) {
                l12 = std_core_multiple_of_power_of_5(l5, l13);
            } else {
                if (l4) {
                    l6 = std_core_multiple_of_power_of_5((uint64_t) (int64_t) ((l5 - INT64_C(1)) - l7), l13);
                } else {
                    t2 = std_core_multiple_of_power_of_5((uint64_t) (int64_t) (l5 + INT64_C(2)), l13);
                    l17 = std_core_b2u(t2);
                    t0 = (l9 - l17);
                    l9 = (uint64_t) (int64_t) t0;
                }
            }
        } else {
        }
    } else {
        l13 = std_core_log10_pow5(-(l2));
        l14 = std_core_b2i((-(l2) > INT32_C(1)));
        l13 = (l13 - l14);
        l11 = (l13 + l2);
        l2 = (-(l2) - l13);
        t3 = std_core_pow5bits(l2);
        l14 = (t3 - INT32_C(125));
        l14 = (l13 - l14);
        l15 = (void*) &vader_data_3;
        t0 = ((int64_t) (int32_t) l2);
        l16 = (size_t) (int64_t) t0;
        vader_array_t* _a2_slotarr = ((vader_array_t*) l15);
        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
        if ((size_t) l16 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
        t0 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l16];
        l17 = (uint64_t) (int64_t) t0;
        l15 = (void*) &vader_data_4;
        t0 = ((int64_t) (int32_t) l2);
        l16 = (size_t) (int64_t) t0;
        vader_array_t* _a3_slotarr = ((vader_array_t*) l15);
        if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
        if ((size_t) l16 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
        t0 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l16];
        l18 = (uint64_t) (int64_t) t0;
        l15 = std_core_mul_shift_all_64(l3, l17, l18, l14, l7);
        l8 = ((vader_struct___Tuple_52_t*) l15)->f__0;
        l9 = ((vader_struct___Tuple_52_t*) l15)->f__1;
        l10 = ((vader_struct___Tuple_52_t*) l15)->f__2;
        if ((l13 <= INT32_C(1))) {
            l12 = true;
            if (l4) {
                l6 = l7 == INT64_C(1);
            } else {
                t0 = (l9 - INT64_C(1));
                l9 = (uint64_t) (int64_t) t0;
            }
        } else {
            if ((l13 < INT32_C(63))) {
                l12 = std_core_multiple_of_power_of_2(l5, l13);
            } else {
            }
        }
    }
    l2 = INT32_C(0);
    l3 = (uint64_t) (int64_t) INT64_C(0);
    if (l6) {
        l19 = true;
    } else {
        l19 = l12;
    }
    if (l19) {
        {
            loop_283: {
                l5 = vader_div_u64(l9, INT64_C(10));
                l7 = vader_div_u64(l10, INT64_C(10));
                if ((l5 <= l7)) {
                } else {
                    t0 = (l7 * INT64_C(10));
                    l17 = (uint64_t) (int64_t) t0;
                    t0 = (l10 - l17);
                    l18 = (uint64_t) (int64_t) t0;
                    l20 = vader_div_u64(l8, INT64_C(10));
                    t0 = (l20 * INT64_C(10));
                    l21 = (uint64_t) (int64_t) t0;
                    t0 = (l8 - l21);
                    l22 = (uint64_t) (int64_t) t0;
                    if (l6) {
                        l19 = l18 == INT64_C(0);
                    } else {
                        l19 = false;
                    }
                    l6 = l19;
                    if (l12) {
                        l23 = l3 == INT64_C(0);
                    } else {
                        l23 = false;
                    }
                    l12 = l23;
                    l3 = l22;
                    l8 = l20;
                    l9 = l5;
                    l10 = l7;
                    l2 = (l2 + INT32_C(1));
                    goto loop_283;
                }
            }
        }
        if (l6) {
            {
                loop_359: {
                    l5 = vader_div_u64(l10, INT64_C(10));
                    t0 = (l5 * INT64_C(10));
                    l7 = (uint64_t) (int64_t) t0;
                    if ((l10 - l7) != INT64_C(0)) {
                    } else {
                        l17 = vader_div_u64(l9, INT64_C(10));
                        l18 = vader_div_u64(l8, INT64_C(10));
                        t0 = (l18 * INT64_C(10));
                        l20 = (uint64_t) (int64_t) t0;
                        t0 = (l8 - l20);
                        l21 = (uint64_t) (int64_t) t0;
                        if (l12) {
                            l19 = l3 == INT64_C(0);
                        } else {
                            l19 = false;
                        }
                        l12 = l19;
                        l3 = l21;
                        l8 = l18;
                        l9 = l17;
                        l10 = l5;
                        l2 = (l2 + INT32_C(1));
                        goto loop_359;
                    }
                }
            }
        } else {
        }
        if (l12) {
            l12 = l3 == INT64_C(5);
        } else {
            l12 = false;
        }
        if (l12) {
            t1 = vader_mod_u64(l8, INT64_C(2));
            l12 = t1 == INT64_C(0);
        } else {
            l12 = false;
        }
        if (l12) {
            l3 = (uint64_t) (int64_t) INT64_C(4);
        } else {
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
        l5 = std_core_b2u(l4);
        t0 = (l8 + l5);
        l3 = (uint64_t) (int64_t) t0;
    } else {
        l4 = false;
        l5 = vader_div_u64(l9, INT64_C(100));
        l7 = vader_div_u64(l10, INT64_C(100));
        if ((l5 > l7)) {
            l17 = vader_div_u64(l8, INT64_C(100));
            t0 = (l17 * INT64_C(100));
            l18 = (uint64_t) (int64_t) t0;
            l4 = ((l8 - l18) >= INT64_C(50));
            l8 = l17;
            l9 = l5;
            l10 = l7;
            l2 = (l2 + INT32_C(2));
        } else {
        }
        {
            loop_525: {
                l5 = vader_div_u64(l9, INT64_C(10));
                l7 = vader_div_u64(l10, INT64_C(10));
                if ((l5 <= l7)) {
                } else {
                    l17 = vader_div_u64(l8, INT64_C(10));
                    t0 = (l17 * INT64_C(10));
                    l18 = (uint64_t) (int64_t) t0;
                    l4 = ((l8 - l18) >= INT64_C(5));
                    l8 = l17;
                    l9 = l5;
                    l10 = l7;
                    l2 = (l2 + INT32_C(1));
                    goto loop_525;
                }
            }
        }
        if (l8 == l10) {
            l6 = true;
        } else {
            l6 = l4;
        }
        l5 = std_core_b2u(l6);
        t0 = (l8 + l5);
        l3 = (uint64_t) (int64_t) t0;
    }
    l2 = (l11 + l2);
    vader_struct_std_core_Dec64_t* _a4_obj = (vader_struct_std_core_Dec64_t*) vader_gc_alloc(sizeof(vader_struct_std_core_Dec64_t));
    vader_obj_header_init(_a4_obj, 370u);
    _a4_obj->f_mantissa = l3;
    _a4_obj->f_exp = l2;
    t4 = (void*) _a4_obj;
    { void* __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* std_core_digits_of(uint64_t l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    uint64_t l2;
    size_t l4, l6, l7;
    vader_string_t l5 = 0;
    void* t0 = NULL;
    uint64_t t1;
    int64_t t2;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t3 };
    void** gc_raw_roots[3] = { &l1, &l3, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(8u, 1u, 0u, 161u);
        vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 0u] = vader_box_string(161u, 452u);
        t0 = (void*) _a0_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a1_arr = vader_array_new(8u, 0u, 0u, 161u);
    l1 = (void*) _a1_arr;
    l2 = l0;
    {
        loop_13: {
            if (l2 != INT64_C(0)) {
                l3 = (void*) &vader_data_5;
                t1 = vader_mod_u64(l2, INT64_C(10));
                t2 = ((int64_t) (uint64_t) t1);
                l4 = (size_t) (int64_t) t2;
                vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l4 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                t3 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l4];
                l5 = t3.payload.s;
                vader_array_push((vader_array_t*) l1, vader_box_string(161u, l5));
                l2 = vader_div_u64(l2, INT64_C(10));
                goto loop_13;
            } else {
            }
        }
    }
    vader_array_t* _a3_arr = vader_array_new(8u, 0u, 0u, 161u);
    l3 = (void*) _a3_arr;
    l4 = ((vader_array_t*) l1)->length;
    l6 = (size_t) (int64_t) INT64_C(0);
    {
        loop_50: {
            if ((l6 < l4)) {
                t2 = ((l4 - INT64_C(1)) - l6);
                l7 = (size_t) (int64_t) t2;
                vader_array_t* _a4_slotarr = ((vader_array_t*) l1);
                if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                if ((size_t) l7 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                t3 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l7];
                l5 = t3.payload.s;
                vader_array_push((vader_array_t*) l3, vader_box_string(161u, l5));
                t2 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t2;
                goto loop_50;
            } else {
            }
        }
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static uint64_t std_core_eisel_lemire(uint64_t l0, int32_t l1) {
    bool l2;
    uint64_t l3, l4, l9, l10, l11;
    int32_t l5, l7, l8;
    void* l6 = NULL;
    int64_t t0;
    void** gc_raw_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT64_C(0)) {
        l2 = true;
    } else {
        l2 = (l1 < INT32_C(-342));
    }
    if (l2) {
        { vader_gc_top = gc_frame.prev; return (uint64_t) (int64_t) INT64_C(0); }
    }
    if ((l1 > INT32_C(308))) {
        t0 = ((int64_t) (int32_t) INT32_C(2047));
        l3 = (uint64_t) (int64_t) t0;
        t0 = ((int64_t) (int32_t) INT32_C(52));
        l4 = (uint64_t) (int64_t) t0;
        { uint64_t __vret = (uint64_t) (int64_t) (l3 << l4); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = std_core_pf_clz64(l0);
    t0 = ((int64_t) (int32_t) l5);
    l3 = (uint64_t) (int64_t) t0;
    t0 = (l0 << l3);
    l3 = (uint64_t) (int64_t) t0;
    l6 = std_core_pf_product(l1, l3);
    l3 = ((vader_struct___Tuple_45_t*) l6)->f__0;
    l4 = ((vader_struct___Tuple_45_t*) l6)->f__1;
    l7 = ((int32_t) (uint64_t) (l3 >> INT64_C(63)));
    l8 = (((l7 + INT32_C(64)) - INT32_C(52)) - INT32_C(3));
    t0 = ((int64_t) (int32_t) l8);
    l9 = (uint64_t) (int64_t) t0;
    l9 = (l3 >> l9);
    l5 = ((((((INT32_C(217706) * l1) >> INT32_C(16)) + INT32_C(63)) + l7) - l5) - INT32_C(-1023));
    if ((l5 <= INT32_C(0))) {
        if (((-(l5) + INT32_C(1)) >= INT32_C(64))) {
            { vader_gc_top = gc_frame.prev; return (uint64_t) (int64_t) INT64_C(0); }
        }
        t0 = ((int64_t) (int32_t) (-(l5) + INT32_C(1)));
        l10 = (uint64_t) (int64_t) t0;
        l9 = (l9 >> l10);
        t0 = (l9 & INT64_C(1));
        l10 = (uint64_t) (int64_t) t0;
        t0 = (l9 + l10);
        l9 = (uint64_t) (int64_t) t0;
        l9 = (l9 >> INT64_C(1));
        t0 = ((int64_t) (int32_t) INT32_C(52));
        l10 = (uint64_t) (int64_t) t0;
        t0 = (INT64_C(1) << l10);
        l10 = (uint64_t) (int64_t) t0;
        if ((l9 < l10)) {
            l7 = INT32_C(0);
        } else {
            l7 = INT32_C(1);
        }
        t0 = ((int64_t) (int32_t) l7);
        l10 = (uint64_t) (int64_t) t0;
        t0 = ((int64_t) (int32_t) INT32_C(52));
        l11 = (uint64_t) (int64_t) t0;
        { uint64_t __vret = (uint64_t) (int64_t) ((l10 << l11) | l9); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if ((l4 <= INT64_C(1))) {
        l2 = (l1 >= INT32_C(-4));
    } else {
        l2 = false;
    }
    if (l2) {
        l2 = (l1 <= INT32_C(23));
    } else {
        l2 = false;
    }
    if (l2) {
        l2 = (l9 & INT64_C(3)) == INT64_C(1);
    } else {
        l2 = false;
    }
    if (l2) {
        t0 = ((int64_t) (int32_t) l8);
        l4 = (uint64_t) (int64_t) t0;
        if ((l9 << l4) == l3) {
            t0 = ~(INT64_C(1));
            l3 = (uint64_t) (int64_t) t0;
            t0 = (l9 & l3);
            l9 = (uint64_t) (int64_t) t0;
        } else {
        }
    } else {
    }
    t0 = (l9 & INT64_C(1));
    l3 = (uint64_t) (int64_t) t0;
    t0 = (l9 + l3);
    l9 = (uint64_t) (int64_t) t0;
    l9 = (l9 >> INT64_C(1));
    t0 = ((int64_t) (int32_t) INT32_C(52));
    l3 = (uint64_t) (int64_t) t0;
    t0 = (INT64_C(2) << l3);
    l3 = (uint64_t) (int64_t) t0;
    if ((l9 >= l3)) {
        t0 = ((int64_t) (int32_t) INT32_C(52));
        l3 = (uint64_t) (int64_t) t0;
        t0 = (INT64_C(1) << l3);
        l9 = (uint64_t) (int64_t) t0;
        l5 = (l5 + INT32_C(1));
    } else {
    }
    t0 = ((int64_t) (int32_t) INT32_C(52));
    l3 = (uint64_t) (int64_t) t0;
    t0 = ~((INT64_C(1) << l3));
    l3 = (uint64_t) (int64_t) t0;
    t0 = (l9 & l3);
    l9 = (uint64_t) (int64_t) t0;
    if ((l5 >= INT32_C(2047))) {
        t0 = ((int64_t) (int32_t) INT32_C(2047));
        l3 = (uint64_t) (int64_t) t0;
        t0 = ((int64_t) (int32_t) INT32_C(52));
        l4 = (uint64_t) (int64_t) t0;
        { uint64_t __vret = (uint64_t) (int64_t) (l3 << l4); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((int64_t) (int32_t) l5);
    l3 = (uint64_t) (int64_t) t0;
    t0 = ((int64_t) (int32_t) INT32_C(52));
    l4 = (uint64_t) (int64_t) t0;
    { uint64_t __vret = (uint64_t) (int64_t) ((l3 << l4) | l9); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

uint32_t std_core_f32_Float32Bits_to_bits_vt(float l0) {
    return (uint32_t) (int32_t) (int32_t)(((union { float __vf; uint32_t __vb; }){ .__vf = l0 }).__vb);
}

uint64_t std_core_f64_FloatBits_to_bits_vt(double l0) {
    return (uint64_t) (int64_t) (int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = l0 }).__vu);
}

void* std_core_filled__MutableSet_i32_(size_t l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    size_t l3;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[4] = { &l1, &l2, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(18u, 0u, 13u, 366u);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l0);
    l2 = (void*) _a1_arr;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_7: {
            if ((l3 < l0)) {
                vader_fn_t* _a2_fnobj = (vader_fn_t*) l1;
                t1 = ((vader_fn_erased_sig_0_t) _a2_fnobj->code)(_a2_fnobj->env);
                l4 = t1.payload.obj;
                vader_array_push((vader_array_t*) l2, vader_ref_box(l4));
                t2 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t2;
                goto loop_7;
            } else {
            }
        }
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* std_core_filled__i32__(size_t l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    size_t l3;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[4] = { &l1, &l2, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(2u, 0u, 13u, 9u);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l0);
    l2 = (void*) _a1_arr;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_7: {
            if ((l3 < l0)) {
                vader_fn_t* _a2_fnobj = (vader_fn_t*) l1;
                t1 = ((vader_fn_erased_sig_0_t) _a2_fnobj->code)(_a2_fnobj->env);
                l4 = t1.payload.obj;
                vader_array_push((vader_array_t*) l2, vader_ref_box(l4));
                t2 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t2;
                goto loop_7;
            } else {
            }
        }
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_string_t std_core_finish_buffer(void* l0, size_t l1) {
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = std_core_Buffer_ByteAccess_intern_string_vt(l0, l1);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t std_core_format_decimal(void* l0, int32_t l1, int32_t l2) {
    bool l3;
    vader_string_t l4 = 0;
    vader_string_t l5 = 0;
    vader_string_t l8 = 0;
    int32_t l6, l7;
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[4] = { &l4, &l5, &l8, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if ((l1 <= l2)) {
        l3 = (l2 <= INT32_C(21));
    } else {
        l3 = false;
    }
    if (l3) {
        l4 = std_core_join_range(l0, INT32_C(0), l1);
        l5 = std_core_zeros((l2 - l1));
        t0 = concat_3(l4, l5, 422u);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if ((INT32_C(0) < l2)) {
        l3 = (l2 <= INT32_C(21));
    } else {
        l3 = false;
    }
    if (l3) {
        l4 = std_core_join_range(l0, INT32_C(0), l2);
        l5 = std_core_join_range(l0, l2, l1);
        t0 = concat_3(l4, 416u, l5);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if ((-(INT32_C(6)) < l2)) {
        l3 = (l2 <= INT32_C(0));
    } else {
        l3 = false;
    }
    if (l3) {
        l4 = std_core_zeros(-(l2));
        l5 = std_core_join_range(l0, INT32_C(0), l1);
        t0 = concat_3(453u, l4, l5);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = (l2 - INT32_C(1));
    l4 = std_core_join_range(l0, INT32_C(0), INT32_C(1));
    if ((l1 > INT32_C(1))) {
        l5 = std_core_join_range(l0, INT32_C(1), l1);
        l4 = concat_3(l4, 416u, l5);
    } else {
    }
    if ((l6 < INT32_C(0))) {
        l5 = 391u;
    } else {
        l5 = 371u;
    }
    if ((l6 < INT32_C(0))) {
        l7 = -(l6);
    } else {
        l7 = l6;
    }
    l8 = std_core_format_unsigned((uint64_t) (int64_t) ((int64_t) (int32_t) l7));
    t0 = concat_4(l4, 1427u, l5, l8);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_string_t std_core_format_f64(double l0) {
    uint64_t l1, l3;
    bool l2, l5;
    vader_string_t l4 = 0;
    void* l6 = NULL;
    int32_t l7;
    int64_t t0;
    vader_string_t t1 = 0;
    void** gc_raw_roots[1] = { &l6 };
    vader_string_t* gc_atom_roots[2] = { &l4, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = std_core_f64_FloatBits_to_bits_vt(l0);
    l2 = (l1 >> INT64_C(63)) != INT64_C(0);
    t0 = (l1 & INT64_C(4503599627370495));
    l3 = (uint64_t) (int64_t) t0;
    t0 = ((l1 >> INT64_C(52)) & INT64_C(2047));
    l1 = (uint64_t) (int64_t) t0;
    if (l1 == INT64_C(2047)) {
        if (l3 != INT64_C(0)) {
            { vader_gc_top = gc_frame.prev; return 1847u; }
        }
        if (l2) {
            l4 = 415u;
        } else {
            l4 = 1681u;
        }
        { vader_string_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT64_C(0)) {
        l5 = l3 == INT64_C(0);
    } else {
        l5 = false;
    }
    if (l5) {
        if (l2) {
            l4 = 393u;
        } else {
            l4 = 454u;
        }
        { vader_string_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = std_core_d2d(l3, l1);
    l1 = ((vader_struct_std_core_Dec64_t*) l6)->f_mantissa;
    l7 = ((vader_struct_std_core_Dec64_t*) l6)->f_exp;
    t1 = std_core_render(l1, l7, l2);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_string_t std_core_format_unsigned(uint64_t l0) {
    size_t l1, l4;
    uint64_t l2;
    void* l3 = NULL;
    uint8_t l5, l6;
    int64_t t0;
    uint64_t t1;
    int32_t t2;
    vader_string_t t3 = 0;
    void** gc_raw_roots[1] = { &l3 };
    vader_string_t* gc_atom_roots[1] = { &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l0 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return 452u; }
    }
    l1 = (size_t) (int64_t) INT64_C(0);
    l2 = l0;
    {
        loop_11: {
            if (l2 != INT64_C(0)) {
                t0 = (l1 + INT64_C(1));
                l1 = (size_t) (int64_t) t0;
                l2 = vader_div_u64(l2, INT64_C(10));
                goto loop_11;
            } else {
            }
        }
    }
    l3 = std_core_usize_BufferAlloc_new_buffer_vt(l1);
    l4 = l1;
    {
        loop_35: {
            if (l0 != INT64_C(0)) {
                t0 = (l4 - INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                t1 = vader_mod_u64(l0, INT64_C(10));
                t2 = ((int32_t) (uint64_t) t1);
                l5 = (uint8_t) (int32_t) t2;
                t2 = (INT32_C(48) + l5);
                l6 = (uint8_t) (int32_t) t2;
                std_core_Buffer_ByteAccess_store_u8_vt(l3, l4, l6);
                l0 = vader_div_u64(l0, INT64_C(10));
                goto loop_35;
            } else {
            }
        }
    }
    t3 = std_core_Buffer_ByteAccess_intern_string_vt(l3, l1);
    { vader_string_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static bool std_core_is_zero(void* l0) {
    size_t l1, l2;
    vader_box_t t0;
    uint32_t t1;
    int64_t t2;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    l1 = ((vader_array_t*) l0)->length;
    l2 = (size_t) (int64_t) INT64_C(0);
    {
        loop_6: {
            if ((l2 < l1)) {
                if ((size_t) l2 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_box_i32(168u, ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l2]);
                t1 = ((uint32_t) t0.payload.i);
                if (t1 != INT32_C(0)) {
                    return false;
                }
                t2 = (l2 + INT64_C(1));
                l2 = (size_t) (int64_t) t2;
                goto loop_6;
            } else {
            }
        }
    }
    return true;
}

static vader_string_t std_core_join_range(void* l0, int32_t l1, int32_t l2) {
    vader_string_t l3 = 0;
    vader_string_t l6 = 0;
    int32_t l4;
    size_t l5;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l3, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = 0u;
    l4 = l1;
    {
        loop_5: {
            if ((l4 < l2)) {
                t0 = ((int64_t) (int32_t) l4);
                l5 = (size_t) (int64_t) t0;
                vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l5 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l5];
                l6 = t1.payload.s;
                l3 = concat_2(l3, l6);
                l4 = (l4 + INT32_C(1));
                goto loop_5;
            } else {
            }
        }
    }
    { vader_string_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

size_t std_core_len(vader_string_t l0) {
    size_t l1, l2, l3;
    uint8_t t0;
    int64_t t1;
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = (size_t) (int64_t) INT64_C(0);
    l2 = vader_host_std_core_byte_len(l0);
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_8: {
            if ((l3 < l2)) {
                t0 = vader_host_std_core_byte_at(l0, l3);
                if ((t0 & INT32_C(192)) != INT32_C(128)) {
                    t1 = (l1 + INT64_C(1));
                    l1 = (size_t) (int64_t) t1;
                } else {
                }
                t1 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t1;
                goto loop_8;
            } else {
            }
        }
    }
    { size_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static uint64_t std_core_limb(void* l0, size_t l1) {
    size_t l2;
    uint64_t l3;
    vader_box_t t0;
    uint32_t t1;
    int64_t t2;
    l2 = ((vader_array_t*) l0)->length;
    if ((l1 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
        if ((size_t) l1 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
        t0 = vader_box_i32(168u, ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1]);
        t1 = ((uint32_t) t0.payload.i);
        t2 = ((int64_t) (uint32_t) t1);
        l3 = (uint64_t) (int64_t) t2;
    } else {
        l3 = (uint64_t) (int64_t) INT64_C(0);
    }
    return l3;
}

static int32_t std_core_log10_pow2(int32_t l0) {
    return ((int32_t) (uint64_t) ((((int64_t) (int32_t) l0) * INT64_C(78913)) >> INT64_C(18)));
}

static int32_t std_core_log10_pow5(int32_t l0) {
    return ((int32_t) (uint64_t) ((((int64_t) (int32_t) l0) * INT64_C(732923)) >> INT64_C(20)));
}

static void* std_core_mul_add_small(void* l0, uint32_t l1, uint32_t l2) {
    void* l3 = NULL;
    uint64_t l4, l7, l8, l9;
    size_t l5, l6;
    uint32_t l10;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    uint32_t t2;
    int32_t t3;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(12u, 0u, 3u, 168u);
    l3 = (void*) _a0_arr;
    t0 = ((int64_t) (uint32_t) l2);
    l4 = (uint64_t) (int64_t) t0;
    l5 = ((vader_array_t*) l0)->length;
    l6 = (size_t) (int64_t) INT64_C(0);
    {
        loop_11: {
            if ((l6 < l5)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l6 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = vader_box_i32(168u, ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l6]);
                t2 = ((uint32_t) t1.payload.i);
                t0 = ((int64_t) (uint32_t) t2);
                l7 = (uint64_t) (int64_t) t0;
                t0 = ((int64_t) (uint32_t) l1);
                l8 = (uint64_t) (int64_t) t0;
                t0 = ((l7 * l8) + l4);
                l9 = (uint64_t) (int64_t) t0;
                t3 = ((int32_t) (int64_t) (l9 & INT64_C(4294967295)));
                l10 = (uint32_t) (int32_t) t3;
                vader_array_push_i32((vader_array_t*) l3, (int32_t) (uint32_t) l10);
                l4 = (l9 >> INT64_C(32));
                t0 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t0;
                goto loop_11;
            } else {
            }
        }
    }
    {
        loop_52: {
            if ((l4 > INT64_C(0))) {
                t3 = ((int32_t) (int64_t) (l4 & INT64_C(4294967295)));
                l10 = (uint32_t) (int32_t) t3;
                vader_array_push_i32((vader_array_t*) l3, (int32_t) (uint32_t) l10);
                l4 = (l4 >> INT64_C(32));
                goto loop_52;
            } else {
            }
        }
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* std_core_mul_shift_all_64(uint64_t l0, uint64_t l1, uint64_t l2, int32_t l3, uint64_t l4) {
    uint64_t l5, l7, l8, l9, l10, l11, l12, l13, l14;
    void* l6 = NULL;
    int64_t t0;
    uint64_t t1;
    void* t2 = NULL;
    void** gc_raw_roots[2] = { &l6, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = (l0 << INT64_C(1));
    l5 = (uint64_t) (int64_t) t0;
    l6 = std_core_umul128(l5, l1);
    l7 = ((vader_struct___Tuple_45_t*) l6)->f__0;
    l8 = ((vader_struct___Tuple_45_t*) l6)->f__1;
    l6 = std_core_umul128(l5, l2);
    l5 = ((vader_struct___Tuple_45_t*) l6)->f__0;
    l9 = ((vader_struct___Tuple_45_t*) l6)->f__1;
    t0 = (l7 + l9);
    l9 = (uint64_t) (int64_t) t0;
    l7 = std_core_b2u((l9 < l7));
    t0 = (l5 + l7);
    l5 = (uint64_t) (int64_t) t0;
    t0 = (l8 + l1);
    l7 = (uint64_t) (int64_t) t0;
    t0 = (l9 + l2);
    l10 = (uint64_t) (int64_t) t0;
    l7 = std_core_b2u((l7 < l8));
    t0 = (l10 + l7);
    l7 = (uint64_t) (int64_t) t0;
    l10 = std_core_b2u((l7 < l9));
    t0 = (l5 + l10);
    l10 = (uint64_t) (int64_t) t0;
    t0 = ((int64_t) (int32_t) ((l3 - INT32_C(64)) - INT32_C(1)));
    l11 = (uint64_t) (int64_t) t0;
    l7 = std_core_shiftright128(l7, l10, l11);
    if (l4 == INT64_C(1)) {
        t0 = (l8 - l1);
        l11 = (uint64_t) (int64_t) t0;
        t0 = (l9 - l2);
        l12 = (uint64_t) (int64_t) t0;
        l11 = std_core_b2u((l11 > l8));
        t0 = (l12 - l11);
        l11 = (uint64_t) (int64_t) t0;
        l12 = std_core_b2u((l11 > l9));
        t0 = (l5 - l12);
        l12 = (uint64_t) (int64_t) t0;
        t0 = ((int64_t) (int32_t) ((l3 - INT32_C(64)) - INT32_C(1)));
        l13 = (uint64_t) (int64_t) t0;
        l10 = std_core_shiftright128(l11, l12, l13);
    } else {
        t0 = (l8 + l8);
        l11 = (uint64_t) (int64_t) t0;
        t0 = (l9 + l9);
        l12 = (uint64_t) (int64_t) t0;
        l8 = std_core_b2u((l11 < l8));
        t0 = (l12 + l8);
        l8 = (uint64_t) (int64_t) t0;
        t0 = (l5 + l5);
        l12 = (uint64_t) (int64_t) t0;
        l13 = std_core_b2u((l8 < l9));
        t0 = (l12 + l13);
        l12 = (uint64_t) (int64_t) t0;
        t0 = (l11 - l1);
        l13 = (uint64_t) (int64_t) t0;
        t0 = (l8 - l2);
        l14 = (uint64_t) (int64_t) t0;
        l11 = std_core_b2u((l13 > l11));
        t0 = (l14 - l11);
        l11 = (uint64_t) (int64_t) t0;
        l8 = std_core_b2u((l11 > l8));
        t0 = (l12 - l8);
        l8 = (uint64_t) (int64_t) t0;
        t0 = ((int64_t) (int32_t) (l3 - INT32_C(64)));
        l12 = (uint64_t) (int64_t) t0;
        l10 = std_core_shiftright128(l11, l8, l12);
    }
    t0 = ((int64_t) (int32_t) ((l3 - INT32_C(64)) - INT32_C(1)));
    l8 = (uint64_t) (int64_t) t0;
    t1 = std_core_shiftright128(l9, l5, l8);
    vader_struct___Tuple_52_t* _a0_obj = (vader_struct___Tuple_52_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_52_t));
    vader_obj_header_init(_a0_obj, 230u);
    _a0_obj->f__0 = t1;
    _a0_obj->f__1 = l7;
    _a0_obj->f__2 = l10;
    t2 = (void*) _a0_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static bool std_core_multiple_of_power_of_2(uint64_t l0, int32_t l1) {
    uint64_t l2;
    int64_t t0;
    t0 = ((int64_t) (int32_t) l1);
    l2 = (uint64_t) (int64_t) t0;
    t0 = ((INT64_C(1) << l2) - INT64_C(1));
    l2 = (uint64_t) (int64_t) t0;
    return (l0 & l2) == INT64_C(0);
}

static bool std_core_multiple_of_power_of_5(uint64_t l0, int32_t l1) {
    int32_t t0;
    t0 = std_core_pow5_factor(l0);
    return (t0 >= l1);
}

void* std_core_new_byte_buffer(size_t l0) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = std_core_usize_BufferAlloc_new_buffer_vt(l0);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t std_core_parse_f64(vader_string_t l0) {
    vader_box_t l1 = vader_box_null();
    uint64_t l2, l4, l6, l7, l8;
    int32_t l3;
    bool l5;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    bool t2;
    uint64_t t3;
    int64_t t4;
    double t5;
    vader_box_t* gc_roots[2] = { &l1, &t0 };
    void** gc_raw_roots[1] = { &t1 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = std_core_scan_decimal(l0);
    if (l1.tag == 0u) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = l1.payload.obj;
    t2 = ((vader_struct_std_core_DecimalParts_t*) t1)->f_too_many_digits;
    if (t2) {
        t1 = l1.payload.obj;
        l2 = ((vader_struct_std_core_DecimalParts_t*) t1)->f_w;
        t1 = l1.payload.obj;
        l3 = ((vader_struct_std_core_DecimalParts_t*) t1)->f_q;
        l2 = std_core_eisel_lemire(l2, l3);
        t1 = l1.payload.obj;
        t3 = ((vader_struct_std_core_DecimalParts_t*) t1)->f_w;
        t4 = (t3 + INT64_C(1));
        l4 = (uint64_t) (int64_t) t4;
        t1 = l1.payload.obj;
        l3 = ((vader_struct_std_core_DecimalParts_t*) t1)->f_q;
        l4 = std_core_eisel_lemire(l4, l3);
        if (l2 != l4) {
            t1 = l1.payload.obj;
            l5 = ((vader_struct_std_core_DecimalParts_t*) t1)->f_negative;
            t5 = std_core_parse_f64_slow(l0, l5);
            t0 = vader_box_f64(158u, t5);
            { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t1 = l1.payload.obj;
        l2 = ((vader_struct_std_core_DecimalParts_t*) t1)->f_w;
        t1 = l1.payload.obj;
        l3 = ((vader_struct_std_core_DecimalParts_t*) t1)->f_q;
        l4 = std_core_eisel_lemire(l2, l3);
        t1 = l1.payload.obj;
        t2 = ((vader_struct_std_core_DecimalParts_t*) t1)->f_negative;
        if (t2) {
            l6 = (uint64_t) (int64_t) INT64_C(1);
            l7 = (uint64_t) (int64_t) INT64_C(63);
            t4 = (l6 << l7);
            l8 = (uint64_t) (int64_t) t4;
            t4 = (l4 | l8);
            l4 = (uint64_t) (int64_t) t4;
        } else {
        }
        t5 = std_core_u64_BitsFloat_from_bits_vt(l4);
        t0 = vader_box_f64(158u, t5);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = l1.payload.obj;
    l2 = ((vader_struct_std_core_DecimalParts_t*) t1)->f_w;
    t1 = l1.payload.obj;
    l3 = ((vader_struct_std_core_DecimalParts_t*) t1)->f_q;
    l4 = std_core_eisel_lemire(l2, l3);
    t1 = l1.payload.obj;
    t2 = ((vader_struct_std_core_DecimalParts_t*) t1)->f_negative;
    if (t2) {
        l6 = (uint64_t) (int64_t) INT64_C(1);
        l7 = (uint64_t) (int64_t) INT64_C(63);
        t4 = (l6 << l7);
        l8 = (uint64_t) (int64_t) t4;
        t4 = (l4 | l8);
        l4 = (uint64_t) (int64_t) t4;
    } else {
    }
    t5 = std_core_u64_BitsFloat_from_bits_vt(l4);
    t0 = vader_box_f64(158u, t5);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static double std_core_parse_f64_slow(vader_string_t l0, bool l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    void* l10 = NULL;
    uint64_t l3, l11, l12, l13;
    int32_t l5, l7, l8, l9;
    bool l6;
    bool t0;
    double t1;
    int32_t t2;
    uint32_t t3;
    int64_t t4;
    void** gc_raw_roots[3] = { &l2, &l4, &l10 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = std_core_sd_scan(l0);
    if (l1) {
        l3 = (uint64_t) (int64_t) INT64_MIN;
    } else {
        l3 = (uint64_t) (int64_t) INT64_C(0);
    }
    t0 = std_core_is_zero(((vader_struct_std_core_SlowParts_t*) l2)->f_d);
    if (t0) {
        t1 = std_core_u64_BitsFloat_from_bits_vt(l3);
        { double __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = ((vader_struct_std_core_SlowParts_t*) l2)->f_d;
    l6 = false;
    t2 = ((vader_struct_std_core_SlowParts_t*) l2)->f_e;
    if ((t2 >= INT32_C(0))) {
        l5 = INT32_C(0);
        {
            loop_30: {
                l7 = ((vader_struct_std_core_SlowParts_t*) l2)->f_e;
                if ((l5 < l7)) {
                    l4 = std_core_mul_add_small(l4, (uint32_t) (int32_t) INT32_C(5), (uint32_t) (int32_t) INT32_C(0));
                    l5 = (l5 + INT32_C(1));
                    goto loop_30;
                } else {
                }
            }
        }
        l5 = ((vader_struct_std_core_SlowParts_t*) l2)->f_e;
    } else {
        t2 = ((vader_struct_std_core_SlowParts_t*) l2)->f_e;
        l7 = -(t2);
        l8 = ((l7 * INT32_C(4)) + INT32_C(64));
        l4 = std_core_shl(((vader_struct_std_core_SlowParts_t*) l2)->f_d, l8);
        l9 = INT32_C(0);
        {
            loop_72: {
                if ((l9 < l7)) {
                    l10 = std_core_BigInt_Div_div(l4, (uint32_t) (int32_t) INT32_C(5));
                    l4 = ((vader_struct___Tuple_49_t*) l10)->f__0;
                    t3 = ((vader_struct___Tuple_49_t*) l10)->f__1;
                    if (t3 != INT32_C(0)) {
                        l6 = true;
                    } else {
                    }
                    l9 = (l9 + INT32_C(1));
                    goto loop_72;
                } else {
                }
            }
        }
        t2 = ((vader_struct_std_core_SlowParts_t*) l2)->f_e;
        l5 = (t2 - l8);
    }
    l7 = std_core_bit_len(l4);
    l8 = ((l7 - INT32_C(1)) + l5);
    if ((l8 >= INT32_C(1024))) {
        t4 = (INT64_C(2047) << INT64_C(52));
        l11 = (uint64_t) (int64_t) t4;
        t1 = std_core_u64_BitsFloat_from_bits_vt((uint64_t) (int64_t) (l3 | l11));
        { double __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l9 = -(INT32_C(1022));
    if ((l8 >= l9)) {
        l8 = (l8 + INT32_C(1023));
        l7 = (l7 - INT32_C(53));
        l11 = std_core_sd_round_at(l4, l7, l6);
        t4 = (INT64_C(1) << INT64_C(53));
        l12 = (uint64_t) (int64_t) t4;
        if ((l11 >= l12)) {
            l11 = (l11 >> INT64_C(1));
            l8 = (l8 + INT32_C(1));
        } else {
        }
        if ((l8 >= INT32_C(2047))) {
            t4 = (INT64_C(2047) << INT64_C(52));
            l12 = (uint64_t) (int64_t) t4;
            t1 = std_core_u64_BitsFloat_from_bits_vt((uint64_t) (int64_t) (l3 | l12));
            { double __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t4 = (((int64_t) (int32_t) l8) << INT64_C(52));
        l12 = (uint64_t) (int64_t) t4;
        t4 = (l3 | l12);
        l12 = (uint64_t) (int64_t) t4;
        t4 = ((INT64_C(1) << INT64_C(52)) - INT64_C(1));
        l13 = (uint64_t) (int64_t) t4;
        t4 = (l11 & l13);
        l11 = (uint64_t) (int64_t) t4;
        t1 = std_core_u64_BitsFloat_from_bits_vt((uint64_t) (int64_t) (l12 | l11));
        { double __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = (-(INT32_C(1074)) - l5);
    l11 = std_core_sd_round_at(l4, l5, l6);
    t1 = std_core_u64_BitsFloat_from_bits_vt((uint64_t) (int64_t) (l3 | l11));
    { double __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static int32_t std_core_pf_clz64(uint64_t l0) {
    int32_t l1;
    uint64_t l2;
    int64_t t0;
    l1 = INT32_C(0);
    l2 = l0;
    {
        loop_5: {
            if ((l2 & INT64_MIN) == INT64_C(0)) {
                t0 = (l2 << INT64_C(1));
                l2 = (uint64_t) (int64_t) t0;
                l1 = (l1 + INT32_C(1));
                goto loop_5;
            } else {
            }
        }
    }
    return l1;
}

static bool std_core_pf_is_digit(uint8_t l0) {
    bool l1;
    if ((l0 >= INT32_C(48))) {
        l1 = (l0 <= INT32_C(57));
    } else {
        l1 = false;
    }
    return l1;
}

static void* std_core_pf_product(int32_t l0, uint64_t l1) {
    int32_t l2;
    size_t l3;
    uint64_t l4, l6, l7;
    void* l5 = NULL;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[2] = { &l5, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = (l0 - INT32_C(-342));
    t0 = ((int64_t) (int32_t) (INT32_C(2) * l2));
    l3 = (size_t) (int64_t) t0;
    t1 = (void*) &vader_data_0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t1);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    t0 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
    l4 = (uint64_t) (int64_t) t0;
    l5 = std_core_umul128(l1, l4);
    l4 = ((vader_struct___Tuple_45_t*) l5)->f__0;
    l6 = ((vader_struct___Tuple_45_t*) l5)->f__1;
    if ((l4 & INT64_C(511)) == INT64_C(511)) {
        l5 = (void*) &vader_data_0;
        t0 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t0;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
        if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
        t0 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
        l7 = (uint64_t) (int64_t) t0;
        t1 = std_core_umul128(l1, l7);
        l7 = ((vader_struct___Tuple_45_t*) t1)->f__0;
        t0 = (l6 + l7);
        l6 = (uint64_t) (int64_t) t0;
        if ((l7 > l6)) {
            t0 = (l4 + INT64_C(1));
            l4 = (uint64_t) (int64_t) t0;
        } else {
        }
    } else {
    }
    vader_struct___Tuple_45_t* _a2_obj = (vader_struct___Tuple_45_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_45_t));
    vader_obj_header_init(_a2_obj, 228u);
    _a2_obj->f__0 = l4;
    _a2_obj->f__1 = l6;
    t1 = (void*) _a2_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static int32_t std_core_pow5_factor(uint64_t l0) {
    uint64_t l1;
    int32_t l2;
    int64_t t0;
    l1 = l0;
    l2 = INT32_C(0);
    {
        loop_5: {
            t0 = (l1 * INT64_C(-3689348814741910323));
            l1 = (uint64_t) (int64_t) t0;
            if ((l1 > INT64_C(3689348814741910323))) {
            } else {
                l2 = (l2 + INT32_C(1));
                goto loop_5;
            }
        }
    }
    return l2;
}

static int32_t std_core_pow5bits(int32_t l0) {
    return ((int32_t) (int64_t) (((((int64_t) (int32_t) l0) * INT64_C(1217359)) >> INT64_C(19)) + INT64_C(1)));
}

static vader_string_t std_core_render(uint64_t l0, int32_t l1, bool l2) {
    uint64_t l3;
    int32_t l4, l6;
    void* l5 = NULL;
    vader_string_t l7 = 0;
    vader_string_t l8 = 0;
    uint64_t t0;
    size_t t1;
    void** gc_raw_roots[1] = { &l5 };
    vader_string_t* gc_atom_roots[2] = { &l7, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = l0;
    l4 = l1;
    {
        loop_5: {
            t0 = vader_mod_u64(l3, INT64_C(10));
            if (t0 == INT64_C(0)) {
                l3 = vader_div_u64(l3, INT64_C(10));
                l4 = (l4 + INT32_C(1));
                goto loop_5;
            } else {
            }
        }
    }
    l5 = std_core_digits_of(l3);
    t1 = ((vader_array_t*) l5)->length;
    l6 = ((int32_t) (size_t) t1);
    l4 = (l4 + l6);
    l7 = std_core_format_decimal(l5, l6, l4);
    if (l2) {
        l8 = concat_2(391u, l7);
    } else {
        l8 = l7;
    }
    { vader_string_t __vret = l8; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t std_core_scan_decimal(vader_string_t l0) {
    size_t l1, l2;
    bool l3, l7, l8, l9, l11;
    uint64_t l4, l10;
    int32_t l5, l6, l12, l13;
    vader_box_t t0 = vader_box_null();
    uint8_t t1;
    int64_t t2;
    bool t3;
    void* t4 = NULL;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[1] = { &t4 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_host_std_core_byte_len(l0);
    if (l1 == INT64_C(0)) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = (size_t) (int64_t) INT64_C(0);
    l3 = false;
    t1 = vader_host_std_core_byte_at(l0, (size_t) (int32_t) INT32_C(0));
    if (t1 == INT32_C(45)) {
        l3 = true;
        l2 = (size_t) (int64_t) INT64_C(1);
    } else {
        t1 = vader_host_std_core_byte_at(l0, (size_t) (int32_t) INT32_C(0));
        if (t1 == INT32_C(43)) {
            l2 = (size_t) (int64_t) INT64_C(1);
        } else {
        }
    }
    l4 = (uint64_t) (int64_t) INT64_C(0);
    l5 = INT32_C(0);
    l6 = INT32_C(0);
    l7 = false;
    l8 = false;
    {
        loop_47: {
            if ((l2 < l1)) {
                t1 = vader_host_std_core_byte_at(l0, l2);
                l9 = std_core_pf_is_digit(t1);
            } else {
                l9 = false;
            }
            if (l9) {
                l8 = true;
                t1 = vader_host_std_core_byte_at(l0, l2);
                t2 = ((int64_t) (uint32_t) (t1 - INT32_C(48)));
                l10 = (uint64_t) (int64_t) t2;
                if ((l5 < INT32_C(19))) {
                    if (l4 != INT64_C(0)) {
                        l11 = true;
                    } else {
                        l11 = l10 != INT64_C(0);
                    }
                    if (l11) {
                        t2 = ((l4 * INT64_C(10)) + l10);
                        l4 = (uint64_t) (int64_t) t2;
                        l5 = (l5 + INT32_C(1));
                    } else {
                    }
                } else {
                    l6 = (l6 + INT32_C(1));
                    l7 = true;
                }
                t2 = (l2 + INT64_C(1));
                l2 = (size_t) (int64_t) t2;
                goto loop_47;
            } else {
            }
        }
    }
    if ((l2 < l1)) {
        t1 = vader_host_std_core_byte_at(l0, l2);
        l9 = t1 == INT32_C(46);
    } else {
        l9 = false;
    }
    if (l9) {
        t2 = (l2 + INT64_C(1));
        l2 = (size_t) (int64_t) t2;
        {
            loop_140: {
                if ((l2 < l1)) {
                    t1 = vader_host_std_core_byte_at(l0, l2);
                    l9 = std_core_pf_is_digit(t1);
                } else {
                    l9 = false;
                }
                if (l9) {
                    l8 = true;
                    t1 = vader_host_std_core_byte_at(l0, l2);
                    t2 = ((int64_t) (uint32_t) (t1 - INT32_C(48)));
                    l10 = (uint64_t) (int64_t) t2;
                    if ((l5 < INT32_C(19))) {
                        if (l4 != INT64_C(0)) {
                            l11 = true;
                        } else {
                            l11 = l10 != INT64_C(0);
                        }
                        if (l11) {
                            t2 = ((l4 * INT64_C(10)) + l10);
                            l4 = (uint64_t) (int64_t) t2;
                            l5 = (l5 + INT32_C(1));
                        } else {
                        }
                        l6 = (l6 - INT32_C(1));
                    } else {
                        l7 = true;
                    }
                    t2 = (l2 + INT64_C(1));
                    l2 = (size_t) (int64_t) t2;
                    goto loop_140;
                } else {
                }
            }
        }
    } else {
    }
    if (!(l8)) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if ((l2 < l1)) {
        t1 = vader_host_std_core_byte_at(l0, l2);
        if (t1 == INT32_C(101)) {
            l9 = true;
        } else {
            t1 = vader_host_std_core_byte_at(l0, l2);
            l9 = t1 == INT32_C(69);
        }
        l8 = l9;
    } else {
        l8 = false;
    }
    if (l8) {
        t2 = (l2 + INT64_C(1));
        l2 = (size_t) (int64_t) t2;
        l8 = false;
        if ((l2 < l1)) {
            t1 = vader_host_std_core_byte_at(l0, l2);
            l9 = t1 == INT32_C(45);
        } else {
            l9 = false;
        }
        if (l9) {
            l8 = true;
            t2 = (l2 + INT64_C(1));
            l2 = (size_t) (int64_t) t2;
        } else {
            if ((l2 < l1)) {
                t1 = vader_host_std_core_byte_at(l0, l2);
                l9 = t1 == INT32_C(43);
            } else {
                l9 = false;
            }
            if (l9) {
                t2 = (l2 + INT64_C(1));
                l2 = (size_t) (int64_t) t2;
            } else {
            }
        }
        if ((l2 >= l1)) {
            l9 = true;
        } else {
            t1 = vader_host_std_core_byte_at(l0, l2);
            t3 = std_core_pf_is_digit(t1);
            l9 = !(t3);
        }
        if (l9) {
            t0 = vader_box_obj(0u, NULL);
            { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l5 = INT32_C(0);
        {
            loop_324: {
                if ((l2 < l1)) {
                    t1 = vader_host_std_core_byte_at(l0, l2);
                    l9 = std_core_pf_is_digit(t1);
                } else {
                    l9 = false;
                }
                if (l9) {
                    if ((l5 < INT32_C(100000))) {
                        l12 = (l5 * INT32_C(10));
                        t1 = vader_host_std_core_byte_at(l0, l2);
                        l13 = (t1 - INT32_C(48));
                        l5 = (l12 + l13);
                    } else {
                    }
                    t2 = (l2 + INT64_C(1));
                    l2 = (size_t) (int64_t) t2;
                    goto loop_324;
                } else {
                }
            }
        }
        if (l8) {
            l6 = (l6 - l5);
        } else {
            l6 = (l6 + l5);
        }
        if (l2 != l1) {
            t0 = vader_box_obj(0u, NULL);
            { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_struct_std_core_DecimalParts_t* _a0_obj = (vader_struct_std_core_DecimalParts_t*) vader_gc_alloc(sizeof(vader_struct_std_core_DecimalParts_t));
        vader_obj_header_init(_a0_obj, 371u);
        _a0_obj->f_w = l4;
        _a0_obj->f_q = l6;
        _a0_obj->f_negative = l3;
        _a0_obj->f_too_many_digits = l7;
        t4 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t4); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2 != l1) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_std_core_DecimalParts_t* _a1_obj = (vader_struct_std_core_DecimalParts_t*) vader_gc_alloc(sizeof(vader_struct_std_core_DecimalParts_t));
    vader_obj_header_init(_a1_obj, 371u);
    _a1_obj->f_w = l4;
    _a1_obj->f_q = l6;
    _a1_obj->f_negative = l3;
    _a1_obj->f_too_many_digits = l7;
    t4 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t4); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static uint64_t std_core_sd_round_at(void* l0, int32_t l1, bool l2) {
    uint64_t l3, l4;
    int32_t l5;
    bool l6, l7;
    int64_t t0;
    uint64_t t1;
    if ((l1 <= INT32_C(0))) {
        l3 = std_core_bits64(l0, INT32_C(0));
        t0 = ((int64_t) (int32_t) -(l1));
        l4 = (uint64_t) (int64_t) t0;
        return (uint64_t) (int64_t) (l3 << l4);
    }
    l3 = std_core_bits64(l0, l1);
    l5 = (l1 - INT32_C(1));
    t1 = std_core_bits64(l0, l5);
    l6 = (t1 & INT64_C(1)) == INT64_C(1);
    if (l2) {
        l7 = true;
    } else {
        l5 = (l1 - INT32_C(1));
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
    if (l6) {
        return (uint64_t) (int64_t) (l3 + INT64_C(1));
    }
    return l3;
}

static void* std_core_sd_scan(vader_string_t l0) {
    size_t l1, l2;
    bool l3, l6, l8;
    void* l4 = NULL;
    int32_t l5, l10, l11, l12;
    uint8_t l7;
    uint32_t l9;
    uint8_t t0;
    int32_t t1;
    int64_t t2;
    void* t3 = NULL;
    void** gc_raw_roots[2] = { &l4, &t3 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_host_std_core_byte_len(l0);
    l2 = (size_t) (int64_t) INT64_C(0);
    t0 = vader_host_std_core_byte_at(l0, (size_t) (int32_t) INT32_C(0));
    if (t0 == INT32_C(45)) {
        l3 = true;
    } else {
        t0 = vader_host_std_core_byte_at(l0, (size_t) (int32_t) INT32_C(0));
        l3 = t0 == INT32_C(43);
    }
    if (l3) {
        l2 = (size_t) (int64_t) INT64_C(1);
    } else {
    }
    vader_array_t* _a0_arr = vader_array_new(12u, 1u, 3u, 168u);
    ((int32_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int32_t) INT32_C(0);
    l4 = (void*) _a0_arr;
    l5 = INT32_C(0);
    l3 = false;
    {
        loop_35: {
            if ((l2 < l1)) {
                t0 = vader_host_std_core_byte_at(l0, l2);
                l6 = std_core_pf_is_digit(t0);
            } else {
                l6 = false;
            }
            if (l6) {
                t0 = vader_host_std_core_byte_at(l0, l2);
                t1 = (t0 - INT32_C(48));
                l7 = (uint8_t) (int32_t) t1;
                if (l3) {
                    l8 = true;
                } else {
                    l8 = l7 != INT32_C(0);
                }
                if (l8) {
                    t1 = ((int32_t) (uint8_t) l7);
                    l9 = (uint32_t) (int32_t) t1;
                    l4 = std_core_mul_add_small(l4, (uint32_t) (int32_t) INT32_C(10), l9);
                    l3 = true;
                } else {
                }
                t2 = (l2 + INT64_C(1));
                l2 = (size_t) (int64_t) t2;
                goto loop_35;
            } else {
            }
        }
    }
    if ((l2 < l1)) {
        t0 = vader_host_std_core_byte_at(l0, l2);
        l6 = t0 == INT32_C(46);
    } else {
        l6 = false;
    }
    if (l6) {
        t2 = (l2 + INT64_C(1));
        l2 = (size_t) (int64_t) t2;
        {
            loop_111: {
                if ((l2 < l1)) {
                    t0 = vader_host_std_core_byte_at(l0, l2);
                    l6 = std_core_pf_is_digit(t0);
                } else {
                    l6 = false;
                }
                if (l6) {
                    t0 = vader_host_std_core_byte_at(l0, l2);
                    t1 = (t0 - INT32_C(48));
                    l7 = (uint8_t) (int32_t) t1;
                    if (l3) {
                        l8 = true;
                    } else {
                        l8 = l7 != INT32_C(0);
                    }
                    if (l8) {
                        t1 = ((int32_t) (uint8_t) l7);
                        l9 = (uint32_t) (int32_t) t1;
                        l4 = std_core_mul_add_small(l4, (uint32_t) (int32_t) INT32_C(10), l9);
                        l3 = true;
                    } else {
                    }
                    l5 = (l5 - INT32_C(1));
                    t2 = (l2 + INT64_C(1));
                    l2 = (size_t) (int64_t) t2;
                    goto loop_111;
                } else {
                }
            }
        }
    } else {
    }
    if ((l2 < l1)) {
        t0 = vader_host_std_core_byte_at(l0, l2);
        if (t0 == INT32_C(101)) {
            l6 = true;
        } else {
            t0 = vader_host_std_core_byte_at(l0, l2);
            l6 = t0 == INT32_C(69);
        }
        l3 = l6;
    } else {
        l3 = false;
    }
    if (l3) {
        t2 = (l2 + INT64_C(1));
        l2 = (size_t) (int64_t) t2;
        l3 = false;
        if ((l2 < l1)) {
            t0 = vader_host_std_core_byte_at(l0, l2);
            l6 = t0 == INT32_C(45);
        } else {
            l6 = false;
        }
        if (l6) {
            l3 = true;
            t2 = (l2 + INT64_C(1));
            l2 = (size_t) (int64_t) t2;
        } else {
            if ((l2 < l1)) {
                t0 = vader_host_std_core_byte_at(l0, l2);
                l6 = t0 == INT32_C(43);
            } else {
                l6 = false;
            }
            if (l6) {
                t2 = (l2 + INT64_C(1));
                l2 = (size_t) (int64_t) t2;
            } else {
            }
        }
        l10 = INT32_C(0);
        {
            loop_255: {
                if ((l2 < l1)) {
                    t0 = vader_host_std_core_byte_at(l0, l2);
                    l6 = std_core_pf_is_digit(t0);
                } else {
                    l6 = false;
                }
                if (l6) {
                    if ((l10 < INT32_C(100000))) {
                        l11 = (l10 * INT32_C(10));
                        t0 = vader_host_std_core_byte_at(l0, l2);
                        l12 = (t0 - INT32_C(48));
                        l10 = (l11 + l12);
                    } else {
                    }
                    t2 = (l2 + INT64_C(1));
                    l2 = (size_t) (int64_t) t2;
                    goto loop_255;
                } else {
                }
            }
        }
        if (l3) {
            l5 = (l5 - l10);
        } else {
            l5 = (l5 + l10);
        }
    } else {
    }
    vader_struct_std_core_SlowParts_t* _a1_obj = (vader_struct_std_core_SlowParts_t*) vader_gc_alloc(sizeof(vader_struct_std_core_SlowParts_t));
    vader_obj_header_init(_a1_obj, 372u);
    _a1_obj->f_d = l4;
    _a1_obj->f_e = l5;
    t3 = (void*) _a1_obj;
    { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static uint64_t std_core_shiftright128(uint64_t l0, uint64_t l1, uint64_t l2) {
    uint64_t l3, l4;
    int64_t t0;
    t0 = (INT64_C(64) - l2);
    l3 = (uint64_t) (int64_t) t0;
    t0 = (l1 << l3);
    l3 = (uint64_t) (int64_t) t0;
    l4 = (l0 >> l2);
    return (uint64_t) (int64_t) (l3 | l4);
}

static void* std_core_shl(void* l0, int32_t l1) {
    void* l2 = NULL;
    size_t l3, l4;
    int32_t l5;
    uint32_t l6, l12;
    uint64_t l7, l8, l9, l10, l11;
    int32_t t0;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    uint32_t t3;
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(12u, 0u, 3u, 168u);
    l2 = (void*) _a0_arr;
    t0 = vader_div_i32(l1, INT32_C(32));
    t1 = ((int64_t) (int32_t) t0);
    l3 = (size_t) (int64_t) t1;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_10: {
            if ((l4 < l3)) {
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                t1 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t1;
                goto loop_10;
            } else {
            }
        }
    }
    l5 = vader_mod_i32(l1, INT32_C(32));
    if (l5 == INT32_C(0)) {
        l3 = ((vader_array_t*) l0)->length;
        l4 = (size_t) (int64_t) INT64_C(0);
        {
            loop_40: {
                if ((l4 < l3)) {
                    vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                    if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = vader_box_i32(168u, ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4]);
                    l6 = ((uint32_t) t2.payload.i);
                    vader_array_push_i32((vader_array_t*) l2, (int32_t) (uint32_t) l6);
                    t1 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t1;
                    goto loop_40;
                } else {
                }
            }
        }
        { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = (uint32_t) (int32_t) INT32_C(0);
    l3 = ((vader_array_t*) l0)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_73: {
            if ((l4 < l3)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l4 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = vader_box_i32(168u, ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4]);
                t3 = ((uint32_t) t2.payload.i);
                t1 = ((int64_t) (uint32_t) t3);
                l7 = (uint64_t) (int64_t) t1;
                t1 = ((int64_t) (int32_t) l5);
                l8 = (uint64_t) (int64_t) t1;
                t1 = (l7 << l8);
                l9 = (uint64_t) (int64_t) t1;
                t1 = ((int64_t) (uint32_t) l6);
                l10 = (uint64_t) (int64_t) t1;
                t1 = (l9 | l10);
                l11 = (uint64_t) (int64_t) t1;
                t0 = ((int32_t) (int64_t) (l11 & INT64_C(4294967295)));
                l12 = (uint32_t) (int32_t) t0;
                vader_array_push_i32((vader_array_t*) l2, (int32_t) (uint32_t) l12);
                t0 = ((int32_t) (uint64_t) (l11 >> INT64_C(32)));
                l6 = (uint32_t) (int32_t) t0;
                t1 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t1;
                goto loop_73;
            } else {
            }
        }
    }
    if (l6 != INT32_C(0)) {
        vader_array_push_i32((vader_array_t*) l2, (int32_t) (uint32_t) l6);
    } else {
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

uint64_t std_core_string_Hash_hash_vt(vader_string_t l0) {
    uint64_t t0;
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = vader_host_std_core_string_Hash_hash(l0);
    { uint64_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

float std_core_u32_Bits32Float_from_bits_vt(uint32_t l0) {
    return (((union { uint32_t __vb; float __vf; }){ .__vb = (uint32_t)(l0) }).__vf);
}

double std_core_u64_BitsFloat_from_bits_vt(uint64_t l0) {
    return (((union { uint64_t __vu; double __vd; }){ .__vu = (uint64_t)(l0) }).__vd);
}

static void* std_core_umul128(uint64_t l0, uint64_t l1) {
    uint64_t l2, l3, l4, l5, l6;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = (l0 & INT64_C(4294967295));
    l2 = (uint64_t) (int64_t) t0;
    l3 = (l0 >> INT64_C(32));
    t0 = (l1 & INT64_C(4294967295));
    l4 = (uint64_t) (int64_t) t0;
    l5 = (l1 >> INT64_C(32));
    t0 = (l2 * l4);
    l6 = (uint64_t) (int64_t) t0;
    t0 = (l2 * l5);
    l2 = (uint64_t) (int64_t) t0;
    t0 = (l3 * l4);
    l4 = (uint64_t) (int64_t) t0;
    t0 = (l3 * l5);
    l3 = (uint64_t) (int64_t) t0;
    l5 = (l6 >> INT64_C(32));
    t0 = (l4 + l5);
    l4 = (uint64_t) (int64_t) t0;
    t0 = (l4 & INT64_C(4294967295));
    l5 = (uint64_t) (int64_t) t0;
    t0 = (l2 + l5);
    l2 = (uint64_t) (int64_t) t0;
    l4 = (l4 >> INT64_C(32));
    t0 = (l3 + l4);
    l3 = (uint64_t) (int64_t) t0;
    l4 = (l2 >> INT64_C(32));
    t0 = (l3 + l4);
    l3 = (uint64_t) (int64_t) t0;
    t0 = ((l2 & INT64_C(4294967295)) << INT64_C(32));
    l2 = (uint64_t) (int64_t) t0;
    t0 = (l6 & INT64_C(4294967295));
    l4 = (uint64_t) (int64_t) t0;
    t0 = (l2 | l4);
    l2 = (uint64_t) (int64_t) t0;
    vader_struct___Tuple_45_t* _a0_obj = (vader_struct___Tuple_45_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_45_t));
    vader_obj_header_init(_a0_obj, 228u);
    _a0_obj->f__0 = l3;
    _a0_obj->f__1 = l2;
    t1 = (void*) _a0_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* std_core_usize_BufferAlloc_new_buffer_vt(size_t l0) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = (void*) vader_buffer_new((size_t) l0);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* std_core_utf8_encode(uint32_t l0) {
    uint32_t l1, l4;
    void* l2 = NULL;
    uint8_t l3;
    int32_t t0;
    void** gc_raw_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((int32_t) (uint32_t) l0);
    l1 = (uint32_t) (int32_t) t0;
    vader_array_t* _a0_arr = vader_array_new(11u, 0u, 1u, 167u);
    l2 = (void*) _a0_arr;
    if ((l1 < INT32_C(128))) {
        t0 = ((int32_t) (uint32_t) l1);
        l3 = (uint8_t) (int32_t) t0;
        vader_array_push_u8((vader_array_t*) l2, (int32_t) (uint8_t) l3);
    } else {
        if ((l1 < INT32_C(2048))) {
            l4 = (l1 >> INT32_C(6));
            t0 = (INT32_C(192) | l4);
            l3 = (uint8_t) (int32_t) t0;
            vader_array_push_u8((vader_array_t*) l2, (int32_t) (uint8_t) l3);
            t0 = (l1 & INT32_C(63));
            l4 = (uint32_t) (int32_t) t0;
            t0 = (INT32_C(128) | l4);
            l3 = (uint8_t) (int32_t) t0;
            vader_array_push_u8((vader_array_t*) l2, (int32_t) (uint8_t) l3);
        } else {
            if ((l1 < INT32_C(65536))) {
                l4 = (l1 >> INT32_C(12));
                t0 = (INT32_C(224) | l4);
                l3 = (uint8_t) (int32_t) t0;
                vader_array_push_u8((vader_array_t*) l2, (int32_t) (uint8_t) l3);
                t0 = ((l1 >> INT32_C(6)) & INT32_C(63));
                l4 = (uint32_t) (int32_t) t0;
                t0 = (INT32_C(128) | l4);
                l3 = (uint8_t) (int32_t) t0;
                vader_array_push_u8((vader_array_t*) l2, (int32_t) (uint8_t) l3);
                t0 = (l1 & INT32_C(63));
                l4 = (uint32_t) (int32_t) t0;
                t0 = (INT32_C(128) | l4);
                l3 = (uint8_t) (int32_t) t0;
                vader_array_push_u8((vader_array_t*) l2, (int32_t) (uint8_t) l3);
            } else {
                l4 = (l1 >> INT32_C(18));
                t0 = (INT32_C(240) | l4);
                l3 = (uint8_t) (int32_t) t0;
                vader_array_push_u8((vader_array_t*) l2, (int32_t) (uint8_t) l3);
                t0 = ((l1 >> INT32_C(12)) & INT32_C(63));
                l4 = (uint32_t) (int32_t) t0;
                t0 = (INT32_C(128) | l4);
                l3 = (uint8_t) (int32_t) t0;
                vader_array_push_u8((vader_array_t*) l2, (int32_t) (uint8_t) l3);
                t0 = ((l1 >> INT32_C(6)) & INT32_C(63));
                l4 = (uint32_t) (int32_t) t0;
                t0 = (INT32_C(128) | l4);
                l3 = (uint8_t) (int32_t) t0;
                vader_array_push_u8((vader_array_t*) l2, (int32_t) (uint8_t) l3);
                t0 = (l1 & INT32_C(63));
                l1 = (uint32_t) (int32_t) t0;
                t0 = (INT32_C(128) | l1);
                l3 = (uint8_t) (int32_t) t0;
                vader_array_push_u8((vader_array_t*) l2, (int32_t) (uint8_t) l3);
            }
        }
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

size_t std_core_write_bool(void* l0, size_t l1, bool l2) {
    size_t t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l2) {
        t0 = std_core_write_string_at(l0, l1, 2154u);
        { size_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = std_core_write_string_at(l0, l1, 1523u);
    { size_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

size_t std_core_write_int(void* l0, size_t l1, int64_t l2) {
    bool l3;
    size_t l4, l6;
    int64_t l5;
    uint8_t l7, l8;
    int64_t t0;
    int32_t t1;
    if (l2 == INT64_C(0)) {
        std_core_Buffer_ByteAccess_store_u8_vt(l0, l1, (uint8_t) (int32_t) INT32_C(48));
        return (size_t) (int64_t) (l1 + INT64_C(1));
    }
    l3 = (l2 < INT64_C(0));
    if ((l2 > INT64_C(0))) {
        l2 = -(l2);
    } else {
    }
    l4 = (size_t) (int64_t) INT64_C(0);
    l5 = l2;
    {
        loop_31: {
            if (l5 != INT64_C(0)) {
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                l5 = vader_div_i64(l5, INT64_C(10));
                goto loop_31;
            } else {
            }
        }
    }
    if (l3) {
        t0 = (l4 + INT64_C(1));
        l6 = (size_t) (int64_t) t0;
    } else {
        l6 = l4;
    }
    t0 = (l1 + l6);
    l4 = (size_t) (int64_t) t0;
    {
        loop_64: {
            if (l2 != INT64_C(0)) {
                t0 = (l4 - INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                t0 = vader_mod_i64(l2, INT64_C(10));
                t1 = ((int32_t) (int64_t) -(t0));
                l7 = (uint8_t) (int32_t) t1;
                t1 = (INT32_C(48) + l7);
                l8 = (uint8_t) (int32_t) t1;
                std_core_Buffer_ByteAccess_store_u8_vt(l0, l4, l8);
                l2 = vader_div_i64(l2, INT64_C(10));
                goto loop_64;
            } else {
            }
        }
    }
    if (l3) {
        std_core_Buffer_ByteAccess_store_u8_vt(l0, l1, (uint8_t) (int32_t) INT32_C(45));
    } else {
    }
    return (size_t) (int64_t) (l1 + l6);
}

size_t std_core_write_string_at(void* l0, size_t l1, vader_string_t l2) {
    size_t l3;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    std_core_Buffer_ByteAccess_write_string_vt(l0, l1, l2);
    l3 = vader_host_std_core_byte_len(l2);
    { size_t __vret = (size_t) (int64_t) (l1 + l3); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

size_t std_core_write_unsigned(void* l0, size_t l1, uint64_t l2) {
    size_t l3, l5;
    uint64_t l4;
    uint8_t l6, l7;
    int64_t t0;
    uint64_t t1;
    int32_t t2;
    if (l2 == INT64_C(0)) {
        std_core_Buffer_ByteAccess_store_u8_vt(l0, l1, (uint8_t) (int32_t) INT32_C(48));
        return (size_t) (int64_t) (l1 + INT64_C(1));
    }
    l3 = (size_t) (int64_t) INT64_C(0);
    l4 = l2;
    {
        loop_18: {
            if (l4 != INT64_C(0)) {
                t0 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t0;
                l4 = vader_div_u64(l4, INT64_C(10));
                goto loop_18;
            } else {
            }
        }
    }
    t0 = (l1 + l3);
    l5 = (size_t) (int64_t) t0;
    {
        loop_41: {
            if (l2 != INT64_C(0)) {
                t0 = (l5 - INT64_C(1));
                l5 = (size_t) (int64_t) t0;
                t1 = vader_mod_u64(l2, INT64_C(10));
                t2 = ((int32_t) (uint64_t) t1);
                l6 = (uint8_t) (int32_t) t2;
                t2 = (INT32_C(48) + l6);
                l7 = (uint8_t) (int32_t) t2;
                std_core_Buffer_ByteAccess_store_u8_vt(l0, l5, l7);
                l2 = vader_div_u64(l2, INT64_C(10));
                goto loop_41;
            } else {
            }
        }
    }
    return (size_t) (int64_t) (l1 + l3);
}

static vader_string_t std_core_zeros(int32_t l0) {
    vader_string_t l1 = 0;
    int32_t l2;
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = 0u;
    l2 = INT32_C(0);
    {
        loop_5: {
            if ((l2 < l0)) {
                l1 = concat_2(l1, 452u);
                l2 = (l2 + INT32_C(1));
                goto loop_5;
            } else {
            }
        }
    }
    { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

