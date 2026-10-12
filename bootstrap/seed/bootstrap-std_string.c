#include "bootstrap.split.h"

static bool std_string_byte_contains(vader_string_t l0, vader_string_t l1);
static bool std_string_bytes_match_at(void* l0, size_t l1, void* l2, size_t l3);
static bool std_string_is_utf8_continuation(uint8_t l0);
static uint8_t std_string_to_lower_byte(uint8_t l0);
static uint32_t std_string_to_lower_cp(uint32_t l0);

void std_string_StringChars_Iterator_next_v(void* l0, uint32_t* __o0, uint8_t* __o1) {
    size_t l1, l2;
    void* l3;
    uint32_t l4;
    uint32_t t0;
    size_t t1;
    int64_t t2;
    l1 = ((vader_struct_std_string_StringChars_t*) l0)->f_cursor;
    l2 = ((vader_struct_std_string_StringChars_t*) l0)->f_length;
    if (!((l1 >= l2))) {
        l3 = ((vader_struct_std_string_StringChars_t*) l0)->f_bytes;
        l1 = ((vader_struct_std_string_StringChars_t*) l0)->f_cursor;
        std_string_utf8_decode_len(l3, l1, &t0, &t1);
        l2 = t1;
        l4 = t0;
        l1 = l2;
        t1 = ((vader_struct_std_string_StringChars_t*) l0)->f_cursor;
        t2 = vader_chk_add(usize, t1, l1);
        l1 = (size_t) (int64_t) t2;
        ((vader_struct_std_string_StringChars_t*) l0)->f_cursor = l1;
        *__o1 = (uint8_t) 0; *__o0 = l4; return;
    }
    *__o1 = (uint8_t) 1; *__o0 = 32u; return;
}

static bool std_string_byte_contains(vader_string_t l0, vader_string_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    size_t l4, l5, l7;
    uint8_t l6;
    vader_box_t t0 = vader_box_null();
    int64_t t1, t2;
    uint8_t t3;
    bool t4;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l2, &l3 };
    vader_string_t* gc_atom_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_host_std_core_bytes(l0);
    l3 = vader_host_std_core_bytes(l1);
    l4 = ((vader_array_t*) l2)->length;
    l5 = ((vader_array_t*) l3)->length;
    if (l5 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    if ((l5 > l4)) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
    t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) INT32_C(0), 250u);
    l6 = ((uint8_t) t0.payload.i);
    l7 = (size_t) 0;
    t1 = vader_chk_sub(usize, l4, l5);
    t2 = vader_chk_add(usize, t1, INT64_C(1));
    l4 = (size_t) (int64_t) t2;
    while ((l7 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l7)
        t0 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) l7, 250u);
        t3 = ((uint8_t) t0.payload.i);
        if (t3 == l6) {
            t4 = std_string_bytes_match_at(l2, l7, l3, l5);
            if (t4) {
                { vader_gc_top = gc_frame.prev; return true; }
            }
        }
        t1 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t1;
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static bool std_string_bytes_match_at(void* l0, size_t l1, void* l2, size_t l3) {
    size_t l4, l5;
    uint8_t l6, l7;
    int64_t t0;
    vader_box_t t1;
    l4 = (size_t) 1;
    while ((l4 < l3)) {
        t0 = vader_chk_add(usize, l1, l4);
        l5 = (size_t) (int64_t) t0;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        t1 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l5, 250u);
        l6 = ((uint8_t) t1.payload.i);
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        t1 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) l4, 250u);
        l7 = ((uint8_t) t1.payload.i);
        if (l6 != l7) {
            return false;
        }
        t0 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t0;
    }
    return true;
}

void* std_string_chars(vader_string_t l0) {
    void* l1 = NULL;
    size_t l2;
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_host_std_core_bytes(l0);
    l2 = ((vader_array_t*) l1)->length;
    vader_struct_std_string_StringChars_t* _a0_obj = (vader_struct_std_string_StringChars_t*) vader_gc_alloc(sizeof(vader_struct_std_string_StringChars_t));
    vader_obj_header_init(_a0_obj, 439u);
    _a0_obj->f_bytes = l1;
    _a0_obj->f_cursor = (size_t) 0;
    _a0_obj->f_length = l2;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

size_t std_string_codepoint_byte_len(uint32_t l0) {
    uint32_t l1;
    int32_t t0;
    t0 = ((int32_t) (uint32_t) l0);
    l1 = (uint32_t) (int32_t) t0;
    if ((l1 < INT32_C(128))) {
        return (size_t) 1;
    }
    if ((l1 < INT32_C(2048))) {
        return (size_t) 2;
    }
    if (!((l1 < INT32_C(65536)))) {
        return (size_t) 4;
    }
    return (size_t) 3;
}

uint32_t std_string_combine_surrogates(uint32_t l0, uint32_t l1) {
    uint32_t l2, l3;
    int32_t t0, t1;
    t0 = vader_chk_sub(u32, ((int32_t) (uint32_t) l0), INT32_C(55296));
    t1 = (t0 << INT32_C(10));
    l2 = (uint32_t) (int32_t) t1;
    t0 = vader_chk_add(u32, INT32_C(65536), l2);
    l2 = (uint32_t) (int32_t) t0;
    t0 = vader_chk_sub(u32, ((int32_t) (uint32_t) l1), INT32_C(56320));
    l3 = (uint32_t) (int32_t) t0;
    t0 = vader_chk_add(u32, l2, l3);
    return ((uint32_t) (int32_t) t0);
}

bool std_string_compare_ascending(vader_string_t l0, vader_string_t l1) {
    return (vader_string_compare(l0, l1) < INT32_C(0));
}

bool std_string_compare_ascending_ci(vader_string_t l0, vader_string_t l1) {
    size_t l2, l3, l4, l5;
    uint8_t l6, l7;
    uint8_t t0;
    int64_t t1;
    l2 = vader_host_std_core_byte_len(l0);
    l3 = vader_host_std_core_byte_len(l1);
    l4 = std_math_min_2(l2, l3);
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        t0 = vader_host_std_core_byte_at(l0, l5);
        l6 = std_string_to_lower_byte(t0);
        t0 = vader_host_std_core_byte_at(l1, l5);
        l7 = std_string_to_lower_byte(t0);
        if ((l6 < l7)) {
            return true;
        }
        if ((l6 > l7)) {
            return false;
        }
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    if (!(l2 != l3)) {
        return (vader_string_compare(l0, l1) < INT32_C(0));
    }
    return (l2 < l3);
}

bool std_string_ends_with(vader_string_t l0, vader_string_t l1) {
    size_t l2, l3, l4, l5;
    uint8_t l6, l7;
    int64_t t0;
    l2 = vader_host_std_core_byte_len(l1);
    l3 = vader_host_std_core_byte_len(l0);
    if ((l2 > l3)) {
        return false;
    }
    t0 = vader_chk_sub(usize, l3, l2);
    l3 = (size_t) (int64_t) t0;
    l4 = (size_t) 0;
    while ((l4 < l2)) {
        t0 = vader_chk_add(usize, l3, l4);
        l5 = (size_t) (int64_t) t0;
        l6 = vader_host_std_core_byte_at(l0, l5);
        l7 = vader_host_std_core_byte_at(l1, l4);
        if (l6 != l7) {
            return false;
        }
        t0 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t0;
    }
    return true;
}

ptrdiff_t std_string_index_of(vader_string_t l0, uint32_t l1, size_t l2) {
    void* l3 = NULL;
    size_t l4, l5, l7, l8;
    uint32_t l6;
    uint32_t t0;
    size_t t1;
    int64_t t2;
    void** gc_raw_roots[1] = { &l3 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_host_std_core_bytes(l0);
    l4 = ((vader_array_t*) l3)->length;
    l5 = l2;
    while ((l5 < l4)) {
        std_string_utf8_decode_len(l3, l5, &t0, &t1);
        l8 = t1;
        l6 = t0;
        l7 = l8;
        if (l6 == l1) {
            { ptrdiff_t __vret = (ptrdiff_t) (int64_t) ((int64_t) (size_t) l5); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = vader_chk_add(usize, l5, l7);
        l5 = (size_t) (int64_t) t2;
    }
    { vader_gc_top = gc_frame.prev; return (ptrdiff_t) -1; }
}

bool std_string_is_empty(vader_string_t l0) {
    size_t t0;
    t0 = vader_host_std_core_byte_len(l0);
    return t0 == INT64_C(0);
}

bool std_string_is_high_surrogate(uint32_t l0) {
    uint32_t l1;
    int32_t t0;
    t0 = ((int32_t) (uint32_t) l0);
    l1 = (uint32_t) (int32_t) t0;
    if ((l1 >= INT32_C(55296))) {
        return (l1 <= INT32_C(56319));
    }
    return false;
}

bool std_string_is_low_surrogate(uint32_t l0) {
    uint32_t l1;
    int32_t t0;
    t0 = ((int32_t) (uint32_t) l0);
    l1 = (uint32_t) (int32_t) t0;
    if ((l1 >= INT32_C(56320))) {
        return (l1 <= INT32_C(57343));
    }
    return false;
}

bool std_string_is_surrogate(uint32_t l0) {
    uint32_t l1;
    int32_t t0;
    t0 = ((int32_t) (uint32_t) l0);
    l1 = (uint32_t) (int32_t) t0;
    if ((l1 >= INT32_C(55296))) {
        return (l1 <= INT32_C(57343));
    }
    return false;
}

static bool std_string_is_utf8_continuation(uint8_t l0) {
    if ((l0 >= INT32_C(128))) {
        return (l0 < INT32_C(192));
    }
    return false;
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
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(13u, 0u, 0u, 244u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 440u);
    _a1_obj->f_parts = t0;
    l2 = (void*) _a1_obj;
    l3 = (size_t) 0;
    l4 = ((vader_array_t*) l0)->length;
    while ((l3 < l4)) {
        if ((l3 > INT64_C(0))) {
            std_string_builder_append(l2, l1);
        }
        vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
        t1 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l3];
        l5 = t1.payload.s;
        std_string_builder_append(l2, l5);
        t2 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t2;
    }
    t3 = std_string_builder_StringBuilder_Display_to_string(l2);
    { vader_string_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

ptrdiff_t std_string_last_index_of(vader_string_t l0, uint32_t l1, ptrdiff_t l2) {
    void* l3 = NULL;
    size_t l4, l6, l8, l9;
    ptrdiff_t l5;
    uint32_t l7;
    uint32_t t0;
    size_t t1;
    int64_t t2;
    void** gc_raw_roots[1] = { &l3 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_host_std_core_bytes(l0);
    l4 = ((vader_array_t*) l3)->length;
    l5 = (ptrdiff_t) -1;
    l6 = (size_t) 0;
    while ((l6 < l4)) {
        std_string_utf8_decode_len(l3, l6, &t0, &t1);
        l9 = t1;
        l7 = t0;
        l8 = l9;
        if ((((int64_t) (size_t) l6) >= l2)) {
            if (l7 == l1) {
                t2 = ((int64_t) (size_t) l6);
                l5 = (ptrdiff_t) (int64_t) t2;
            }
        }
        t2 = vader_chk_add(usize, l6, l8);
        l6 = (size_t) (int64_t) t2;
    }
    { ptrdiff_t __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t std_string_pad_start(vader_string_t l0, size_t l1, uint32_t l2) {
    size_t l3;
    void* l4 = NULL;
    void* t0 = NULL;
    int64_t t1;
    vader_string_t t2 = 0;
    void** gc_raw_roots[2] = { &l4, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_host_std_core_byte_len(l0);
    if ((l3 >= l1)) {
        { vader_string_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(13u, 0u, 0u, 244u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 440u);
    _a1_obj->f_parts = t0;
    l4 = (void*) _a1_obj;
    while ((l3 < l1)) {
        std_string_builder_append_char(l4, l2);
        t1 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t1;
    }
    std_string_builder_append(l4, l0);
    t2 = std_string_builder_StringBuilder_Display_to_string(l4);
    { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = std_core_parse_f64(l0);
    if (l1.tag == 0u) {
        t0 = concat_3(2106u, l0, 866u);
        vader_struct_std_string_ParseError_t* _a0_obj = (vader_struct_std_string_ParseError_t*) vader_gc_alloc(sizeof(vader_struct_std_string_ParseError_t));
        vader_obj_header_init(_a0_obj, 438u);
        _a0_obj->f_msg = t0;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = ((double) l1.payload.f);
    t3 = vader_box_f64(241u, t2);
    { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t std_string_replace_chars_where(vader_string_t l0, void* l1, vader_string_t l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    uint32_t l5, l6;
    uint8_t l7;
    void* t0 = NULL;
    uint32_t t1;
    uint8_t t2;
    vader_box_t t3 = vader_box_null();
    bool t4;
    vader_string_t t5 = 0;
    vader_box_t* gc_roots[1] = { &t3 };
    void** gc_raw_roots[4] = { &l1, &l3, &l4, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l2, &t5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(13u, 0u, 0u, 244u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 440u);
    _a1_obj->f_parts = t0;
    l3 = (void*) _a1_obj;
    l4 = std_string_chars(l0);
    for (;;) {
        std_string_StringChars_Iterator_next_v(l4, &t1, &t2);
        l7 = t2;
        l6 = t1;
        if (!(l7 == INT32_C(1))) {
            l5 = l6;
            vader_fn_t* _a2_fnobj = (vader_fn_t*) l1;
            t3 = ((vader_fn_erased_sig_1_t) _a2_fnobj->code)(_a2_fnobj->env, vader_box_i32(243u, (int32_t) l5));
            t4 = t3.payload.b;
            if (t4) {
                std_string_builder_append(l3, l2);
            } else {
                std_string_builder_append_char(l3, l5);
            }
            continue;
        }
        break;
    }
    t5 = std_string_builder_StringBuilder_Display_to_string(l3);
    { vader_string_t __vret = t5; vader_gc_top = gc_frame.prev; return __vret; }
}

void* std_string_split(vader_string_t l0, vader_string_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    size_t l5, l6, l7, l8;
    vader_string_t l9 = 0;
    uint8_t l10;
    bool l11, l12;
    int64_t t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    uint8_t t3;
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[4] = { &l2, &l3, &l4, &t1 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l1, &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(13u, 0u, 0u, 244u);
    l2 = (void*) _a0_arr;
    l3 = vader_host_std_core_bytes(l0);
    l4 = vader_host_std_core_bytes(l1);
    l5 = ((vader_array_t*) l3)->length;
    l6 = ((vader_array_t*) l4)->length;
    if (l6 == INT64_C(0)) {
        l7 = (size_t) 0;
        while ((l7 < l5)) {
            t0 = vader_chk_add(usize, l7, INT64_C(1));
            l8 = (size_t) (int64_t) t0;
            vader_array_t* _a1_arr = vader_array_slice((vader_array_t*) l3, (size_t) l7, (size_t) l8);
            t1 = (void*) _a1_arr;
            l9 = vader_host_std_core_bytes_to_string(t1);
            vader_array_push((vader_array_t*) l2, vader_box_string(244u, l9));
            t0 = (l7 + INT64_C(1));
            l7 = (size_t) (int64_t) t0;
        }
        { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(0))
    t2 = vader_array_read_u8(_a2_slotarr, _a2_slotarr->offset + (size_t) INT32_C(0), 250u);
    l10 = ((uint8_t) t2.payload.i);
    l7 = (size_t) 0;
    l8 = (size_t) 0;
    for (;;) {
        t0 = vader_chk_add(usize, l8, l6);
        if ((t0 <= l5)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l8)
            t2 = vader_array_read_u8(_a3_slotarr, _a3_slotarr->offset + (size_t) l8, 250u);
            t3 = ((uint8_t) t2.payload.i);
            if (t3 == l10) {
                if (l6 == INT64_C(1)) {
                    l12 = true;
                } else {
                    l12 = std_string_bytes_match_at(l3, l8, l4, l6);
                }
                l11 = l12;
            } else {
                l11 = false;
            }
            if (l11) {
                vader_array_t* _a4_arr = vader_array_slice((vader_array_t*) l3, (size_t) l7, (size_t) l8);
                t1 = (void*) _a4_arr;
                l9 = vader_host_std_core_bytes_to_string(t1);
                vader_array_push((vader_array_t*) l2, vader_box_string(244u, l9));
                t0 = vader_chk_add(usize, l8, l6);
                l8 = (size_t) (int64_t) t0;
                l7 = l8;
                continue;
            }
            t0 = vader_chk_add(usize, l8, INT64_C(1));
            l8 = (size_t) (int64_t) t0;
            continue;
        }
        break;
    }
    vader_array_t* _a5_arr = vader_array_slice((vader_array_t*) l3, (size_t) l7, (size_t) l5);
    t1 = (void*) _a5_arr;
    l9 = vader_host_std_core_bytes_to_string(t1);
    vader_array_push((vader_array_t*) l2, vader_box_string(244u, l9));
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

bool std_string_starts_with(vader_string_t l0, vader_string_t l1) {
    size_t l2, l3;
    uint8_t l4, l5;
    int64_t t0;
    l2 = vader_host_std_core_byte_len(l1);
    l3 = vader_host_std_core_byte_len(l0);
    if ((l2 > l3)) {
        return false;
    }
    l3 = (size_t) 0;
    while ((l3 < l2)) {
        l4 = vader_host_std_core_byte_at(l0, l3);
        l5 = vader_host_std_core_byte_at(l1, l3);
        if (l4 != l5) {
            return false;
        }
        t0 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t0;
    }
    return true;
}

bool std_string_string_Contains_contains(vader_string_t l0, vader_string_t l1) {
    bool t0;
    vader_string_t* gc_atom_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = std_string_byte_contains(l0, l1);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t std_string_to_lower(vader_string_t l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    size_t l3, l4, l6, l8;
    uint32_t l5, l7;
    void* t0 = NULL;
    uint32_t t1;
    size_t t2;
    uint32_t t3;
    int64_t t4;
    vader_string_t t5 = 0;
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(13u, 0u, 0u, 244u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 440u);
    _a1_obj->f_parts = t0;
    l1 = (void*) _a1_obj;
    l2 = vader_host_std_core_bytes(l0);
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        std_string_utf8_decode_len(l2, l4, &t1, &t2);
        l8 = t2;
        l5 = t1;
        l6 = l8;
        t3 = std_string_to_lower_cp((uint32_t) (int32_t) ((int32_t) (uint32_t) l5));
        l7 = ((uint32_t) (uint32_t) t3);
        std_string_builder_append_char(l1, l7);
        t4 = vader_chk_add(usize, l4, l6);
        l4 = (size_t) (int64_t) t4;
    }
    t5 = std_string_builder_StringBuilder_Display_to_string(l1);
    { vader_string_t __vret = t5; vader_gc_top = gc_frame.prev; return __vret; }
}

static uint8_t std_string_to_lower_byte(uint8_t l0) {
    uint8_t l1;
    int32_t t0;
    if ((l0 >= INT32_C(65))) {
        if ((l0 <= INT32_C(90))) {
            l1 = (uint8_t) 32;
            t0 = vader_chk_add(u8, l0, l1);
            return (uint8_t) (int32_t) t0;
        }
        return l0;
    }
    return l0;
}

static uint32_t std_string_to_lower_cp(uint32_t l0) {
    uint32_t l1;
    bool l2;
    int32_t t0;
    if ((l0 >= INT32_C(65))) {
        l2 = (l0 <= INT32_C(90));
    } else {
        l2 = false;
    }
    if (l2) {
        t0 = vader_chk_add(u32, l0, INT32_C(32));
        l1 = (uint32_t) (int32_t) t0;
        return l1;
    }
    if ((l0 >= INT32_C(192))) {
        l2 = (l0 <= INT32_C(214));
    } else {
        l2 = false;
    }
    if (l2) {
        t0 = vader_chk_add(u32, l0, INT32_C(32));
        l1 = (uint32_t) (int32_t) t0;
    } else {
        if ((l0 >= INT32_C(216))) {
            l2 = (l0 <= INT32_C(222));
        } else {
            l2 = false;
        }
        if (l2) {
            t0 = vader_chk_add(u32, l0, INT32_C(32));
            l1 = (uint32_t) (int32_t) t0;
        } else if (l0 == INT32_C(376)) {
            l1 = (uint32_t) 255;
        } else {
            l1 = l0;
        }
    }
    return l1;
}

vader_string_t std_string_trim_prefix(vader_string_t l0, vader_string_t l1) {
    void* l2 = NULL;
    size_t l3, l4;
    bool t0;
    void* t1 = NULL;
    vader_string_t t2 = 0;
    void** gc_raw_roots[2] = { &l2, &t1 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l1, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = std_string_starts_with(l0, l1);
    if (!(t0)) {
        { vader_string_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = vader_host_std_core_bytes(l0);
    l3 = vader_host_std_core_byte_len(l1);
    l4 = ((vader_array_t*) l2)->length;
    vader_array_t* _a0_arr = vader_array_slice((vader_array_t*) l2, (size_t) l3, (size_t) l4);
    t1 = (void*) _a0_arr;
    t2 = vader_host_std_core_bytes_to_string(t1);
    { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = std_string_ends_with(l0, l1);
    if (!(t0)) {
        { vader_string_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = vader_host_std_core_bytes(l0);
    l3 = ((vader_array_t*) l2)->length;
    l4 = vader_host_std_core_byte_len(l1);
    t1 = vader_chk_sub(usize, l3, l4);
    l3 = (size_t) (int64_t) t1;
    vader_array_t* _a0_arr = vader_array_slice((vader_array_t*) l2, (size_t) INT64_C(0), (size_t) l3);
    t2 = (void*) _a0_arr;
    t3 = vader_host_std_core_bytes_to_string(t2);
    { vader_string_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
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
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l1, 250u);
    l3 = ((uint8_t) t0.payload.i);
    if ((l3 < INT32_C(128))) {
        return ((uint32_t) (uint8_t) l3);
    }
    t1 = std_string_is_utf8_continuation(l3);
    if (t1) {
        return ((uint32_t) 65533);
    }
    t2 = vader_chk_sub(usize, l2, l1);
    l2 = (size_t) (int64_t) t2;
    if ((l3 < INT32_C(224))) {
        if (!((l2 < INT64_C(2)))) {
            t2 = vader_chk_add(usize, l1, INT64_C(1));
            l4 = (size_t) (int64_t) t2;
            vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
            t0 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) l4, 250u);
            l5 = ((uint8_t) t0.payload.i);
            t3 = ((((int32_t) (uint8_t) l3) & INT32_C(31)) << INT32_C(6));
            l6 = (uint32_t) (int32_t) t3;
            t3 = (((int32_t) (uint8_t) l5) & INT32_C(63));
            l7 = (uint32_t) (int32_t) t3;
            t3 = vader_chk_add(u32, l6, l7);
            return ((uint32_t) (int32_t) t3);
        }
        return ((uint32_t) 0);
    }
    if ((l3 < INT32_C(240))) {
        if (!((l2 < INT64_C(3)))) {
            t2 = vader_chk_add(usize, l1, INT64_C(1));
            l4 = (size_t) (int64_t) t2;
            vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
            t0 = vader_array_read_u8(_a2_slotarr, _a2_slotarr->offset + (size_t) l4, 250u);
            l5 = ((uint8_t) t0.payload.i);
            t2 = vader_chk_add(usize, l1, INT64_C(2));
            l4 = (size_t) (int64_t) t2;
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
            t0 = vader_array_read_u8(_a2_slotarr, _a2_slotarr->offset + (size_t) l4, 250u);
            l8 = ((uint8_t) t0.payload.i);
            t3 = ((((int32_t) (uint8_t) l3) & INT32_C(15)) << INT32_C(12));
            l6 = (uint32_t) (int32_t) t3;
            t3 = ((((int32_t) (uint8_t) l5) & INT32_C(63)) << INT32_C(6));
            l7 = (uint32_t) (int32_t) t3;
            t3 = vader_chk_add(u32, l6, l7);
            l6 = (uint32_t) (int32_t) t3;
            t3 = (((int32_t) (uint8_t) l8) & INT32_C(63));
            l7 = (uint32_t) (int32_t) t3;
            t3 = vader_chk_add(u32, l6, l7);
            return ((uint32_t) (int32_t) t3);
        }
        return ((uint32_t) 0);
    }
    if (!((l2 < INT64_C(4)))) {
        t2 = vader_chk_add(usize, l1, INT64_C(1));
        l2 = (size_t) (int64_t) t2;
        vader_array_t* _a3_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l2)
        t0 = vader_array_read_u8(_a3_slotarr, _a3_slotarr->offset + (size_t) l2, 250u);
        l5 = ((uint8_t) t0.payload.i);
        t2 = vader_chk_add(usize, l1, INT64_C(2));
        l2 = (size_t) (int64_t) t2;
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l2)
        t0 = vader_array_read_u8(_a3_slotarr, _a3_slotarr->offset + (size_t) l2, 250u);
        l8 = ((uint8_t) t0.payload.i);
        t2 = vader_chk_add(usize, l1, INT64_C(3));
        l2 = (size_t) (int64_t) t2;
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l2)
        t0 = vader_array_read_u8(_a3_slotarr, _a3_slotarr->offset + (size_t) l2, 250u);
        l9 = ((uint8_t) t0.payload.i);
        t3 = ((((int32_t) (uint8_t) l3) & INT32_C(7)) << INT32_C(18));
        l6 = (uint32_t) (int32_t) t3;
        t3 = ((((int32_t) (uint8_t) l5) & INT32_C(63)) << INT32_C(12));
        l7 = (uint32_t) (int32_t) t3;
        t3 = vader_chk_add(u32, l6, l7);
        l6 = (uint32_t) (int32_t) t3;
        t3 = ((((int32_t) (uint8_t) l8) & INT32_C(63)) << INT32_C(6));
        l7 = (uint32_t) (int32_t) t3;
        t3 = vader_chk_add(u32, l6, l7);
        l6 = (uint32_t) (int32_t) t3;
        t3 = (((int32_t) (uint8_t) l9) & INT32_C(63));
        l7 = (uint32_t) (int32_t) t3;
        t3 = vader_chk_add(u32, l6, l7);
        return ((uint32_t) (int32_t) t3);
    }
    return ((uint32_t) 0);
}

void std_string_utf8_decode_len(void* l0, size_t l1, uint32_t* __o0, size_t* __o1) {
    uint32_t l2;
    size_t l3;
    l2 = std_string_utf8_decode(l0, l1);
    l3 = std_string_codepoint_byte_len(l2);
    *__o1 = l3; *__o0 = l2; return;
}

size_t std_string_utf8_lead_len(uint8_t l0) {
    if ((l0 < INT32_C(128))) {
        return (size_t) 1;
    }
    if ((l0 < INT32_C(192))) {
        return (size_t) 1;
    }
    if ((l0 < INT32_C(224))) {
        return (size_t) 2;
    }
    if (!((l0 < INT32_C(240)))) {
        return (size_t) 4;
    }
    return (size_t) 3;
}
