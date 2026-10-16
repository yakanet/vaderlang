#include "bootstrap.split.h"

static bool std_string_byte_contains(vader_string_t l0, vader_string_t l1);
static uint8_t std_string_to_lower_byte(uint8_t l0);
static uint32_t std_string_to_lower_cp(uint32_t l0);

static bool std_string_byte_contains(vader_string_t l0, vader_string_t l1) {
    size_t l2, l3, l5;
    uint8_t l4;
    int64_t t0, t1;
    uint8_t t2;
    bool t3;
    l2 = vader_host_std_core_byte_len(l0);
    l3 = vader_host_std_core_byte_len(l1);
    if (l3 == INT64_C(0)) {
        return true;
    }
    if ((l3 > l2)) {
        return false;
    }
    l4 = vader_host_std_core_byte_at(l1, (size_t) 0);
    l5 = (size_t) 0;
    t0 = vader_chk_sub(usize, l2, l3);
    t1 = vader_chk_add(usize, t0, INT64_C(1));
    l2 = (size_t) (int64_t) t1;
    while ((l5 < l2)) {
        t2 = vader_host_std_core_byte_at(l0, l5);
        if (t2 == l4) {
            t3 = std_string_matches_at(l0, l5, l1);
            if (t3) {
                return true;
            }
        }
        t0 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t0;
    }
    return false;
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
    size_t l2, l3;
    int64_t t0;
    bool t1;
    l2 = vader_host_std_core_byte_len(l1);
    l3 = vader_host_std_core_byte_len(l0);
    if (!((l2 > l3))) {
        l2 = vader_host_std_core_byte_len(l0);
        l3 = vader_host_std_core_byte_len(l1);
        t0 = vader_chk_sub(usize, l2, l3);
        l2 = (size_t) (int64_t) t0;
        t1 = std_string_matches_at(l0, l2, l1);
        return t1;
    }
    return false;
}

ptrdiff_t std_string_index_of(vader_string_t l0, uint32_t l1, size_t l2) {
    size_t l3, l4, l6, l7;
    uint32_t l5;
    uint32_t t0;
    size_t t1;
    int64_t t2;
    l3 = vader_host_std_core_byte_len(l0);
    l4 = l2;
    while ((l4 < l3)) {
        std_core_codepoint_at_byte(l0, l4, &t0, &t1);
        l7 = t1;
        l5 = t0;
        l6 = l7;
        if (l5 == l1) {
            return (ptrdiff_t) (int64_t) ((int64_t) (size_t) l4);
        }
        t2 = vader_chk_add(usize, l4, l6);
        l4 = (size_t) (int64_t) t2;
    }
    return (ptrdiff_t) -1;
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
    vader_array_t* _a0_arr = vader_array_new(14u, 0u, 0u, 276u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 494u);
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
    size_t l3, l5, l7, l8;
    ptrdiff_t l4;
    uint32_t l6;
    uint32_t t0;
    size_t t1;
    int64_t t2;
    l3 = vader_host_std_core_byte_len(l0);
    l4 = (ptrdiff_t) -1;
    l5 = (size_t) 0;
    while ((l5 < l3)) {
        std_core_codepoint_at_byte(l0, l5, &t0, &t1);
        l8 = t1;
        l6 = t0;
        l7 = l8;
        if ((((int64_t) (size_t) l5) >= l2)) {
            if (l6 == l1) {
                t2 = ((int64_t) (size_t) l5);
                l4 = (ptrdiff_t) (int64_t) t2;
            }
        }
        t2 = vader_chk_add(usize, l5, l7);
        l5 = (size_t) (int64_t) t2;
    }
    return l4;
}

bool std_string_matches_at(vader_string_t l0, size_t l1, vader_string_t l2) {
    size_t l3, l4, l5;
    uint8_t l6, l7;
    size_t t0;
    int64_t t1;
    l3 = vader_host_std_core_byte_len(l2);
    l4 = vader_host_std_core_byte_len(l0);
    if ((l1 > l4)) {
        return false;
    }
    t0 = vader_host_std_core_byte_len(l0);
    t1 = vader_chk_sub(usize, t0, l1);
    l4 = (size_t) (int64_t) t1;
    if ((l3 > l4)) {
        return false;
    }
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        t1 = vader_chk_add(usize, l1, l4);
        l5 = (size_t) (int64_t) t1;
        l6 = vader_host_std_core_byte_at(l0, l5);
        l7 = vader_host_std_core_byte_at(l2, l4);
        if (l6 != l7) {
            return false;
        }
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    return true;
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
    l3 = std_core_len(l0);
    if ((l3 >= l1)) {
        { vader_string_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(14u, 0u, 0u, 276u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 494u);
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
        t0 = concat_3(2146u, l0, 896u);
        vader_struct_std_string_ParseError_t* _a0_obj = (vader_struct_std_string_ParseError_t*) vader_gc_alloc(sizeof(vader_struct_std_string_ParseError_t));
        vader_obj_header_init(_a0_obj, 493u);
        _a0_obj->f_msg = t0;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = ((double) l1.payload.f);
    t3 = vader_box_f64(273u, t2);
    { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t std_string_replace_chars_where(vader_string_t l0, void* l1, vader_string_t l2) {
    void* l3 = NULL;
    vader_string_t l4 = 0;
    size_t l5, l6, l9, l11;
    uint8_t l7;
    uint32_t l8, l10;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    bool t3;
    uint32_t t4;
    size_t t5;
    vader_string_t t6 = 0;
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[3] = { &l1, &l3, &t0 };
    vader_string_t* gc_atom_roots[4] = { &l0, &l2, &l4, &t6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(14u, 0u, 0u, 276u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 494u);
    _a1_obj->f_parts = t0;
    l3 = (void*) _a1_obj;
    l4 = l0;
    l5 = (size_t) 0;
    for (;;) {
        l6 = vader_host_std_core_byte_len(l4);
        if ((l5 < l6)) {
            l7 = vader_host_std_core_byte_at(l4, l5);
            if ((l7 < INT32_C(128))) {
                t1 = vader_chk_add(usize, l5, INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                l8 = ((uint32_t) (uint8_t) l7);
                vader_fn_t* _a2_fnobj = (vader_fn_t*) l1;
                t2 = ((vader_fn_erased_sig_1_t) _a2_fnobj->code)(_a2_fnobj->env, vader_box_i32(275u, (int32_t) l8));
                t3 = t2.payload.b;
                if (t3) {
                    std_string_builder_append(l3, l2);
                } else {
                    std_string_builder_append_char(l3, l8);
                }
                continue;
            }
            std_core_decode_tail(l4, l7, l5, &t4, &t5);
            l11 = t5;
            l10 = t4;
            l9 = l11;
            t1 = vader_chk_add(usize, l5, l9);
            l5 = (size_t) (int64_t) t1;
            vader_fn_t* _a3_fnobj = (vader_fn_t*) l1;
            t2 = ((vader_fn_erased_sig_1_t) _a3_fnobj->code)(_a3_fnobj->env, vader_box_i32(275u, (int32_t) l10));
            t3 = t2.payload.b;
            if (t3) {
                std_string_builder_append(l3, l2);
            } else {
                std_string_builder_append_char(l3, l10);
            }
            continue;
        }
        break;
    }
    t6 = std_string_builder_StringBuilder_Display_to_string(l3);
    { vader_string_t __vret = t6; vader_gc_top = gc_frame.prev; return __vret; }
}

void* std_string_split(vader_string_t l0, vader_string_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l5, l6, l7, l12;
    vader_string_t l8 = 0;
    uint8_t l9;
    bool l10, l11;
    uint32_t t0;
    size_t t1;
    int64_t t2;
    uint8_t t3;
    void** gc_raw_roots[1] = { &l2 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l1, &l8 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(14u, 0u, 0u, 276u);
    l2 = (void*) _a0_arr;
    l3 = vader_host_std_core_byte_len(l0);
    l4 = vader_host_std_core_byte_len(l1);
    if (l4 == INT64_C(0)) {
        l5 = (size_t) 0;
        while ((l5 < l3)) {
            std_core_codepoint_at_byte(l0, l5, &t0, &t1);
            l12 = t1;
            l6 = l12;
            t2 = vader_chk_add(usize, l5, l6);
            l7 = (size_t) (int64_t) t2;
            l8 = vader_host_std_core_byte_slice(l0, l5, l7);
            vader_array_push((vader_array_t*) l2, vader_box_string(276u, l8));
            l5 = l7;
        }
        { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l9 = vader_host_std_core_byte_at(l1, (size_t) 0);
    l5 = (size_t) 0;
    l6 = (size_t) 0;
    for (;;) {
        t2 = vader_chk_add(usize, l6, l4);
        if ((t2 <= l3)) {
            t3 = vader_host_std_core_byte_at(l0, l6);
            if (t3 == l9) {
                if (l4 == INT64_C(1)) {
                    l11 = true;
                } else {
                    l11 = std_string_matches_at(l0, l6, l1);
                }
                l10 = l11;
            } else {
                l10 = false;
            }
            if (l10) {
                l8 = vader_host_std_core_byte_slice(l0, l5, l6);
                vader_array_push((vader_array_t*) l2, vader_box_string(276u, l8));
                t2 = vader_chk_add(usize, l6, l4);
                l6 = (size_t) (int64_t) t2;
                l5 = l6;
                continue;
            }
            t2 = vader_chk_add(usize, l6, INT64_C(1));
            l6 = (size_t) (int64_t) t2;
            continue;
        }
        break;
    }
    l8 = vader_host_std_core_byte_slice(l0, l5, l3);
    vader_array_push((vader_array_t*) l2, vader_box_string(276u, l8));
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

bool std_string_starts_with(vader_string_t l0, vader_string_t l1) {
    bool t0;
    t0 = std_string_matches_at(l0, (size_t) 0, l1);
    return t0;
}

bool std_string_string_Contains_contains(vader_string_t l0, vader_string_t l1) {
    bool t0;
    t0 = std_string_byte_contains(l0, l1);
    return t0;
}

vader_string_t std_string_to_lower(vader_string_t l0) {
    void* l1 = NULL;
    vader_string_t l2 = 0;
    size_t l3, l4, l7, l10;
    uint8_t l5;
    uint32_t l6, l8, l9;
    void* t0 = NULL;
    int64_t t1;
    uint32_t t2;
    uint32_t t3;
    size_t t4;
    vader_string_t t5 = 0;
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l2, &t5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(14u, 0u, 0u, 276u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 494u);
    _a1_obj->f_parts = t0;
    l1 = (void*) _a1_obj;
    l2 = l0;
    l3 = (size_t) 0;
    for (;;) {
        l4 = vader_host_std_core_byte_len(l2);
        if ((l3 < l4)) {
            l5 = vader_host_std_core_byte_at(l2, l3);
            if ((l5 < INT32_C(128))) {
                t1 = vader_chk_add(usize, l3, INT64_C(1));
                l3 = (size_t) (int64_t) t1;
                t2 = std_string_to_lower_cp((uint32_t) (int32_t) ((int32_t) (uint32_t) ((uint32_t) (uint8_t) l5)));
                l6 = ((uint32_t) (uint32_t) t2);
                std_string_builder_append_char(l1, l6);
                continue;
            }
            std_core_decode_tail(l2, l5, l3, &t3, &t4);
            l10 = t4;
            l8 = t3;
            l7 = l10;
            t1 = vader_chk_add(usize, l3, l7);
            l3 = (size_t) (int64_t) t1;
            t2 = std_string_to_lower_cp((uint32_t) (int32_t) ((int32_t) (uint32_t) l8));
            l9 = ((uint32_t) (uint32_t) t2);
            std_string_builder_append_char(l1, l9);
            continue;
        }
        break;
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
    size_t l2, l3;
    bool t0;
    vader_string_t t1;
    t0 = std_string_starts_with(l0, l1);
    if (!(t0)) {
        return l0;
    }
    l2 = vader_host_std_core_byte_len(l1);
    l3 = vader_host_std_core_byte_len(l0);
    t1 = vader_host_std_core_byte_slice(l0, l2, l3);
    return t1;
}

vader_string_t std_string_trim_suffix(vader_string_t l0, vader_string_t l1) {
    size_t l2, l3;
    bool t0;
    int64_t t1;
    vader_string_t t2;
    t0 = std_string_ends_with(l0, l1);
    if (!(t0)) {
        return l0;
    }
    l2 = vader_host_std_core_byte_len(l0);
    l3 = vader_host_std_core_byte_len(l1);
    t1 = vader_chk_sub(usize, l2, l3);
    l2 = (size_t) (int64_t) t1;
    t2 = vader_host_std_core_byte_slice(l0, (size_t) 0, l2);
    return t2;
}
