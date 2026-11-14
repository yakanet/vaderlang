#include "bootstrap.split.h"

static void json$advance(void* l0);
static bool json$at_end(void* l0);
static bool json$decode_unicode_escape(void* l0, void* l1);
static vader_box_t json$expect_byte(void* l0, uint32_t l1);
static void* json$fail(void* l0, vader_string_t l1);
static bool json$match_keyword(void* l0, vader_string_t l1);
static vader_box_t json$parse_array(void* l0, int32_t l1);
static vader_box_t json$parse_bool(void* l0);
static vader_box_t json$parse_null(void* l0);
static vader_box_t json$parse_number(void* l0);
static vader_box_t json$parse_object(void* l0, int32_t l1);
static vader_box_t json$parse_string(void* l0);
static vader_box_t json$parse_string_with_escapes(void* l0, void* l1);
static vader_box_t json$parse_value(void* l0, int32_t l1);
static uint32_t json$peek_byte(void* l0);
static vader_box_t json$read_hex4(void* l0);
static void json$skip_ws(void* l0);

vader_string_t json$JsonError$std_core$Error$message(void* l0) {
    vader_string_t t0;
    t0 = ((vader_struct_json$JsonError_t*) l0)->f_msg;
    return t0;
}

static void json$advance(void* l0) {
    int64_t l1;
    int64_t t0;
    t0 = ((vader_struct_json$Parser_t*) l0)->f_pos;
    l1 = vader_chk_add(i64, t0, INT64_C(1));
    ((vader_struct_json$Parser_t*) l0)->f_pos = l1;
    return;
}

static bool json$at_end(void* l0) {
    int64_t l1, l2;
    vader_string_t t0;
    l1 = ((vader_struct_json$Parser_t*) l0)->f_pos;
    t0 = ((vader_struct_json$Parser_t*) l0)->f_src;
    l2 = vader_host_std_core$byte_len(t0);
    return (l1 >= l2);
}

static bool json$decode_unicode_escape(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    uint32_t l3, l9;
    bool l4;
    uint32_t l5, l10;
    int64_t l6, l7;
    vader_string_t l8 = 0;
    int32_t t0, t1;
    bool t2;
    int64_t t3;
    vader_string_t t4 = 0;
    uint8_t t5;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[2] = { &l8, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = json$read_hex4(l0);
    if (l2.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    t0 = ((int32_t) l2.payload.i);
    t1 = t0;
    l3 = (uint32_t) (int32_t) t1;
    t2 = std_string$is_surrogate(l3);
    if (t2) {
        t2 = std_string$is_high_surrogate(l3);
        if (t2) {
            t3 = ((vader_struct_json$Parser_t*) l0)->f_pos;
            l6 = vader_chk_add(i64, t3, INT64_C(2));
            t4 = ((vader_struct_json$Parser_t*) l0)->f_src;
            l7 = vader_host_std_core$byte_len(t4);
            if ((l6 <= l7)) {
                l8 = ((vader_struct_json$Parser_t*) l0)->f_src;
                l6 = ((vader_struct_json$Parser_t*) l0)->f_pos;
                t5 = vader_host_std_core$byte_at(l8, l6);
                if (t5 == INT32_C(92)) {
                    l8 = ((vader_struct_json$Parser_t*) l0)->f_src;
                    t3 = ((vader_struct_json$Parser_t*) l0)->f_pos;
                    l6 = vader_chk_add(i64, t3, INT64_C(1));
                    t5 = vader_host_std_core$byte_at(l8, l6);
                    if (t5 == INT32_C(117)) {
                        l6 = ((vader_struct_json$Parser_t*) l0)->f_pos;
                        t3 = ((vader_struct_json$Parser_t*) l0)->f_pos;
                        l7 = vader_chk_add(i64, t3, INT64_C(2));
                        ((vader_struct_json$Parser_t*) l0)->f_pos = l7;
                        l2 = json$read_hex4(l0);
                        if (!(l2.tag == 0u)) {
                            t0 = ((int32_t) l2.payload.i);
                            t2 = std_string$is_low_surrogate((uint32_t) (int32_t) t0);
                            if (t2) {
                                t0 = ((int32_t) l2.payload.i);
                                t1 = t0;
                                l9 = (uint32_t) (int32_t) t1;
                                l5 = std_string$combine_surrogates(l3, l9);
                                std_string__builder$append_char(l1, l5);
                                { vader_gc_top = gc_frame.prev; return true; }
                            }
                        }
                        ((vader_struct_json$Parser_t*) l0)->f_pos = l6;
                    }
                }
            }
        }
        l10 = ((uint32_t) 65533);
        std_string__builder$append_char(l1, l10);
        { vader_gc_top = gc_frame.prev; return true; }
    }
    if ((l3 > INT32_C(55295))) {
        if ((l3 < INT32_C(57344))) {
            l4 = true;
        } else {
            l4 = (l3 > INT32_C(1114111));
        }
        if (l4) {
            vader_unreachable("value out of range: no Unicode scalar value");
        }
    }
    l5 = ((uint32_t) (uint32_t) l3);
    std_string__builder$append_char(l1, l5);
    { vader_gc_top = gc_frame.prev; return true; }
}

static vader_box_t json$expect_byte(void* l0, uint32_t l1) {
    bool t0;
    void* t1 = NULL;
    uint32_t t2;
    void** gc_raw_roots[2] = { &l0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = json$at_end(l0);
    if (t0) {
        t1 = json$fail(l0, 3053u);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = json$peek_byte(l0);
    if (!(t2 != l1)) {
        json$advance(l0);
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t1 = json$fail(l0, 3052u);
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* json$fail(void* l0, vader_string_t l1) {
    int64_t l2;
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_json$Parser_t*) l0)->f_pos;
    vader_struct_json$JsonError_t* _a0_obj = (vader_struct_json$JsonError_t*) vader_gc_alloc(sizeof(vader_struct_json$JsonError_t));
    vader_obj_header_init(_a0_obj, 696u);
    _a0_obj->f_msg = l1;
    _a0_obj->f_pos = l2;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool json$match_keyword(void* l0, vader_string_t l1) {
    vader_string_t l2;
    int64_t l3, l4;
    bool t0;
    l2 = ((vader_struct_json$Parser_t*) l0)->f_src;
    l3 = ((vader_struct_json$Parser_t*) l0)->f_pos;
    t0 = std_string$matches_at(l2, l3, l1);
    if (!(t0)) {
        return false;
    }
    l3 = ((vader_struct_json$Parser_t*) l0)->f_pos;
    l4 = vader_host_std_core$byte_len(l1);
    l3 = vader_chk_add(i64, l3, l4);
    ((vader_struct_json$Parser_t*) l0)->f_pos = l3;
    return true;
}

vader_box_t json$parse(vader_string_t l0) {
    void* l1 = NULL;
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null();
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[2] = { &l2, &l3 };
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_json$Parser_t* _a0_obj = (vader_struct_json$Parser_t*) vader_gc_alloc(sizeof(vader_struct_json$Parser_t));
    vader_obj_header_init(_a0_obj, 701u);
    _a0_obj->f_src = l0;
    _a0_obj->f_pos = INT64_C(0);
    l1 = (void*) _a0_obj;
    l2 = json$parse_value(l1, INT32_C(0));
    l3 = l2;
    if (l2.tag == 696u) {
        t0 = l3.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    json$skip_ws(l1);
    t1 = json$at_end(l1);
    if (!(t1)) {
        t0 = json$fail(l1, 2972u);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t json$parse_array(void* l0, int32_t l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l6 = vader_box_null();
    void* l4 = NULL;
    int32_t l5;
    uint32_t l7;
    void* t0 = NULL;
    bool t1;
    uint32_t t2;
    vader_box_t* gc_roots[3] = { &l2, &l3, &l6 };
    void** gc_raw_roots[3] = { &l0, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = json$expect_byte(l0, 91u);
    l3 = l2;
    if (l2.tag == 696u) {
        t0 = l3.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(386u, 0u, 13u, 1904u);
    l4 = (void*) _a0_arr;
    json$skip_ws(l0);
    t1 = json$at_end(l0);
    if (!(t1)) {
        t2 = json$peek_byte(l0);
        if (t2 == 93u) {
            json$advance(l0);
            vader_struct_json$JsonArray_t* _a1_obj = (vader_struct_json$JsonArray_t*) vader_gc_alloc(sizeof(vader_struct_json$JsonArray_t));
            vader_obj_header_init(_a1_obj, 694u);
            _a1_obj->f_items = l4;
            t0 = (void*) _a1_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    for (;;) {
        t1 = json$at_end(l0);
        if (!(t1)) {
            l5 = vader_chk_add(i32, l1, INT32_C(1));
            l3 = json$parse_value(l0, l5);
            l6 = l3;
            if (l3.tag == 696u) {
                t0 = l6.payload.obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l2 = l3;
            vader_array_push_ref((vader_array_t*) l4, l2.payload.obj);
            json$skip_ws(l0);
            t1 = json$at_end(l0);
            if (t1) {
                t0 = json$fail(l0, 3080u);
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l7 = json$peek_byte(l0);
            if (l7 == 44u) {
                json$advance(l0);
                json$skip_ws(l0);
                continue;
            }
            if (!(l7 == 93u)) {
                t0 = json$fail(l0, 2068u);
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            json$advance(l0);
            vader_struct_json$JsonArray_t* _a2_obj = (vader_struct_json$JsonArray_t*) vader_gc_alloc(sizeof(vader_struct_json$JsonArray_t));
            vader_obj_header_init(_a2_obj, 694u);
            _a2_obj->f_items = l4;
            t0 = (void*) _a2_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        break;
    }
    t0 = json$fail(l0, 3080u);
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t json$parse_bool(void* l0) {
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[2] = { &l0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = json$match_keyword(l0, 2979u);
    if (t0) {
        vader_struct_json$JsonBool_t* _a0_obj = (vader_struct_json$JsonBool_t*) vader_gc_alloc(sizeof(vader_struct_json$JsonBool_t));
        vader_obj_header_init(_a0_obj, 695u);
        _a0_obj->f_value = true;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = json$match_keyword(l0, 2126u);
    if (!(t0)) {
        t1 = json$fail(l0, 2072u);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_json$JsonBool_t* _a1_obj = (vader_struct_json$JsonBool_t*) vader_gc_alloc(sizeof(vader_struct_json$JsonBool_t));
    vader_obj_header_init(_a1_obj, 695u);
    _a1_obj->f_value = false;
    t1 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t json$parse_null(void* l0) {
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[2] = { &l0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = json$match_keyword(l0, 2594u);
    if (!(t0)) {
        t1 = json$fail(l0, 2071u);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = (void*) &vader_data_83;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t1);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    t1 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT64_C(0));
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t json$parse_number(void* l0) {
    int64_t l1, l6;
    bool l2, l4;
    uint32_t l3;
    vader_string_t l5 = 0;
    vader_box_t l7 = vader_box_null();
    uint32_t t0;
    bool t1;
    void* t2 = NULL;
    vader_string_t t3 = 0;
    double t4;
    vader_box_t* gc_roots[1] = { &l7 };
    void** gc_raw_roots[2] = { &l0, &t2 };
    vader_string_t* gc_atom_roots[2] = { &l5, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_json$Parser_t*) l0)->f_pos;
    t0 = json$peek_byte(l0);
    if (t0 == 45u) {
        json$advance(l0);
    }
    t1 = json$at_end(l0);
    if (t1) {
        l2 = true;
    } else {
        t0 = json$peek_byte(l0);
        t1 = std_char$is_digit(t0);
        l2 = !(t1);
    }
    if (l2) {
        t2 = json$fail(l0, 2079u);
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = json$peek_byte(l0);
    json$advance(l0);
    if (l3 == 48u) {
        t1 = json$at_end(l0);
        if (!(t1)) {
            t0 = json$peek_byte(l0);
            t1 = std_char$is_digit(t0);
            if (t1) {
                t2 = json$fail(l0, 2428u);
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
    }
    for (;;) {
        t1 = json$at_end(l0);
        if (!(t1)) {
            t0 = json$peek_byte(l0);
            t1 = std_char$is_digit(t0);
            if (!(t1)) {
                break;
            }
            json$advance(l0);
            continue;
        }
        break;
    }
    t1 = json$at_end(l0);
    if (!(t1)) {
        t0 = json$peek_byte(l0);
        if (t0 == 46u) {
            json$advance(l0);
            t1 = json$at_end(l0);
            if (t1) {
                l2 = true;
            } else {
                t0 = json$peek_byte(l0);
                t1 = std_char$is_digit(t0);
                l2 = !(t1);
            }
            if (l2) {
                t2 = json$fail(l0, 2080u);
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            for (;;) {
                t1 = json$at_end(l0);
                if (!(t1)) {
                    t0 = json$peek_byte(l0);
                    t1 = std_char$is_digit(t0);
                    if (!(t1)) {
                        break;
                    }
                    json$advance(l0);
                    continue;
                }
                break;
            }
        }
    }
    t1 = json$at_end(l0);
    if (!(t1)) {
        t0 = json$peek_byte(l0);
        if (t0 == 101u) {
            l4 = true;
        } else {
            t0 = json$peek_byte(l0);
            l4 = t0 == 69u;
        }
        l2 = l4;
    } else {
        l2 = false;
    }
    if (l2) {
        json$advance(l0);
        t1 = json$at_end(l0);
        if (!(t1)) {
            t0 = json$peek_byte(l0);
            if (t0 == 43u) {
                l4 = true;
            } else {
                t0 = json$peek_byte(l0);
                l4 = t0 == 45u;
            }
            l2 = l4;
        } else {
            l2 = false;
        }
        if (l2) {
            json$advance(l0);
        }
        t1 = json$at_end(l0);
        if (t1) {
            l2 = true;
        } else {
            t0 = json$peek_byte(l0);
            t1 = std_char$is_digit(t0);
            l2 = !(t1);
        }
        if (l2) {
            t2 = json$fail(l0, 2081u);
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        for (;;) {
            t1 = json$at_end(l0);
            if (!(t1)) {
                t0 = json$peek_byte(l0);
                t1 = std_char$is_digit(t0);
                if (!(t1)) {
                    break;
                }
                json$advance(l0);
                continue;
            }
            break;
        }
    }
    l5 = ((vader_struct_json$Parser_t*) l0)->f_src;
    l6 = ((vader_struct_json$Parser_t*) l0)->f_pos;
    t3 = vader_host_std_core$byte_slice(l5, l1, l6);
    l7 = std_string$parse_float(t3);
    if ((l7.tag == 513u || l7.tag == 514u)) {
        t4 = ((double) l7.payload.f);
        vader_struct_json$JsonNumber_t* _a0_obj = (vader_struct_json$JsonNumber_t*) vader_gc_alloc(sizeof(vader_struct_json$JsonNumber_t));
        vader_obj_header_init(_a0_obj, 698u);
        _a0_obj->f_value = t4;
        t2 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l7.tag == 885u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    t2 = json$fail(l0, 2365u);
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t json$parse_object(void* l0, int32_t l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l8 = vader_box_null(), l9 = vader_box_null(), l10 = vader_box_null(), l12 = vader_box_null(), l13 = vader_box_null();
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    vader_string_t l7 = 0;
    int32_t l11;
    uint32_t l14;
    void* t0 = NULL;
    bool t1;
    uint32_t t2;
    vader_box_t* gc_roots[7] = { &l2, &l3, &l8, &l9, &l10, &l12, &l13 };
    void** gc_raw_roots[5] = { &l0, &l4, &l5, &l6, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 7u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = json$expect_byte(l0, 123u);
    l3 = l2;
    if (l2.tag == 696u) {
        t0 = l3.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(26u, 0u, 0u, 504u);
    l4 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(33u, 0u, 0u, 515u);
    l5 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(27u, 0u, 7u, 507u);
    l6 = (void*) _a2_arr;
    vader_struct_std_collections$Map__string__Any_t* _a3_obj = (vader_struct_std_collections$Map__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any_t));
    vader_obj_header_init(_a3_obj, 783u);
    _a3_obj->f_ekeys = l4;
    _a3_obj->f_evals = l5;
    _a3_obj->f_index = l6;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l4 = (void*) _a3_obj;
    json$skip_ws(l0);
    t1 = json$at_end(l0);
    if (!(t1)) {
        t2 = json$peek_byte(l0);
        if (t2 == 125u) {
            json$advance(l0);
            vader_struct_json$JsonObject_t* _a4_obj = (vader_struct_json$JsonObject_t*) vader_gc_alloc(sizeof(vader_struct_json$JsonObject_t));
            vader_obj_header_init(_a4_obj, 699u);
            _a4_obj->f_entries = l4;
            t0 = (void*) _a4_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    for (;;) {
        t1 = json$at_end(l0);
        if (!(t1)) {
            json$skip_ws(l0);
            l2 = json$parse_string(l0);
            l3 = l2;
            if (l2.tag == 696u) {
                t0 = l3.payload.obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l7 = l2.payload.s;
            json$skip_ws(l0);
            l8 = json$expect_byte(l0, 58u);
            l9 = l8;
            if (l8.tag == 696u) {
                t0 = l9.payload.obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l11 = vader_chk_add(i32, l1, INT32_C(1));
            l12 = json$parse_value(l0, l11);
            l13 = l12;
            if (l12.tag == 696u) {
                t0 = l13.payload.obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l10 = l12;
            std_collections$Map$std_core$IndexSet$set_at__string__Any(l4, l7, l10);
            json$skip_ws(l0);
            t1 = json$at_end(l0);
            if (t1) {
                t0 = json$fail(l0, 3084u);
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l14 = json$peek_byte(l0);
            if (l14 == 44u) {
                json$advance(l0);
                continue;
            }
            if (!(l14 == 125u)) {
                t0 = json$fail(l0, 2069u);
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            json$advance(l0);
            vader_struct_json$JsonObject_t* _a5_obj = (vader_struct_json$JsonObject_t*) vader_gc_alloc(sizeof(vader_struct_json$JsonObject_t));
            vader_obj_header_init(_a5_obj, 699u);
            _a5_obj->f_entries = l4;
            t0 = (void*) _a5_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        break;
    }
    t0 = json$fail(l0, 3084u);
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t json$parse_string(void* l0) {
    vader_box_t l1 = vader_box_null(), l2 = vader_box_null();
    int64_t l3, l4, l5, l7;
    uint8_t l6;
    void* l8 = NULL;
    vader_string_t l9 = 0;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_string_t t2 = 0;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l1, &l2, &t3 };
    void** gc_raw_roots[3] = { &l0, &l8, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l9, &t1, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = json$expect_byte(l0, 34u);
    l2 = l1;
    if (l1.tag == 696u) {
        t0 = l2.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((vader_struct_json$Parser_t*) l0)->f_pos;
    l4 = ((vader_struct_json$Parser_t*) l0)->f_pos;
    t1 = ((vader_struct_json$Parser_t*) l0)->f_src;
    l5 = vader_host_std_core$byte_len(t1);
    while ((l4 < l5)) {
        t1 = ((vader_struct_json$Parser_t*) l0)->f_src;
        l6 = vader_host_std_core$byte_at(t1, l4);
        if (l6 == INT32_C(34)) {
            l7 = vader_chk_add(i64, l4, INT64_C(1));
            ((vader_struct_json$Parser_t*) l0)->f_pos = l7;
            t1 = ((vader_struct_json$Parser_t*) l0)->f_src;
            t2 = vader_host_std_core$byte_slice(t1, l3, l4);
            { vader_box_t __vret = vader_box_string(504u, t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l6 == INT32_C(92)) {
            vader_array_t* _a0_arr = vader_array_new(26u, 0u, 0u, 504u);
            t0 = (void*) _a0_arr;
            vader_struct_std_string__builder$StringBuilder_t* _a1_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
            vader_obj_header_init(_a1_obj, 886u);
            _a1_obj->f_parts = t0;
            l8 = (void*) _a1_obj;
            t1 = ((vader_struct_json$Parser_t*) l0)->f_src;
            l9 = vader_host_std_core$byte_slice(t1, l3, l4);
            std_string__builder$append(l8, l9);
            ((vader_struct_json$Parser_t*) l0)->f_pos = l4;
            t3 = json$parse_string_with_escapes(l0, l8);
            { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l4 = (l4 + INT64_C(1));
    }
    t0 = json$fail(l0, 3085u);
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t json$parse_string_with_escapes(void* l0, void* l1) {
    vader_string_t l2 = 0;
    vader_string_t l9 = 0;
    vader_string_t l11 = 0;
    vader_string_t l13 = 0;
    vader_string_t l15 = 0;
    int64_t l3, l8, l10, l12, l14;
    uint8_t l4;
    uint32_t l5, l6, l7;
    bool t0;
    vader_string_t t1 = 0;
    void* t2 = NULL;
    uint8_t t3;
    void** gc_raw_roots[3] = { &l0, &l1, &t2 };
    vader_string_t* gc_atom_roots[6] = { &l2, &l9, &l11, &l13, &l15, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 6u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    for (;;) {
        t0 = json$at_end(l0);
        if (!(t0)) {
            l2 = ((vader_struct_json$Parser_t*) l0)->f_src;
            l3 = ((vader_struct_json$Parser_t*) l0)->f_pos;
            l4 = vader_host_std_core$byte_at(l2, l3);
            if (l4 == INT32_C(34)) {
                json$advance(l0);
                t1 = std_string__builder$StringBuilder$std_core$Display$to_string(l1);
                { vader_box_t __vret = vader_box_string(504u, t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l4 == INT32_C(92)) {
                json$advance(l0);
                t0 = json$at_end(l0);
                if (t0) {
                    t2 = json$fail(l0, 3083u);
                    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
                }
                l5 = json$peek_byte(l0);
                json$advance(l0);
                if (l5 == 34u) {
                    std_string__builder$append_char(l1, 34u);
                } else if (l5 == 92u) {
                    std_string__builder$append_char(l1, 92u);
                } else if (l5 == 47u) {
                    std_string__builder$append_char(l1, 47u);
                } else if (l5 == 110u) {
                    std_string__builder$append_char(l1, 10u);
                } else if (l5 == 116u) {
                    std_string__builder$append_char(l1, 9u);
                } else if (l5 == 114u) {
                    std_string__builder$append_char(l1, 13u);
                } else if (l5 == 98u) {
                    l6 = ((uint32_t) 8);
                    std_string__builder$append_char(l1, l6);
                } else if (l5 == 102u) {
                    l7 = ((uint32_t) 12);
                    std_string__builder$append_char(l1, l7);
                } else {
                    if (!(l5 == 117u)) {
                        t2 = json$fail(l0, 3062u);
                        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
                    }
                    t0 = json$decode_unicode_escape(l0, l1);
                    if (!(t0)) {
                        t2 = json$fail(l0, 2355u);
                        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
                    }
                }
                continue;
            }
            l8 = ((vader_struct_json$Parser_t*) l0)->f_pos;
            for (;;) {
                t0 = json$at_end(l0);
                if (!(t0)) {
                    l9 = ((vader_struct_json$Parser_t*) l0)->f_src;
                    l10 = ((vader_struct_json$Parser_t*) l0)->f_pos;
                    t3 = vader_host_std_core$byte_at(l9, l10);
                    if (!(t3 != INT32_C(34))) {
                        break;
                    }
                    l11 = ((vader_struct_json$Parser_t*) l0)->f_src;
                    l12 = ((vader_struct_json$Parser_t*) l0)->f_pos;
                    t3 = vader_host_std_core$byte_at(l11, l12);
                    if (!(t3 != INT32_C(92))) {
                        break;
                    }
                    json$advance(l0);
                    continue;
                }
                break;
            }
            l13 = ((vader_struct_json$Parser_t*) l0)->f_src;
            l14 = ((vader_struct_json$Parser_t*) l0)->f_pos;
            l15 = vader_host_std_core$byte_slice(l13, l8, l14);
            std_string__builder$append(l1, l15);
            continue;
        }
        break;
    }
    t2 = json$fail(l0, 3085u);
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t json$parse_value(void* l0, int32_t l1) {
    uint32_t l2;
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null();
    bool l5;
    void* t0 = NULL;
    bool t1;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[2] = { &l3, &l4 };
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if ((l1 > INT32_C(200))) {
        t0 = json$fail(l0, 2493u);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    json$skip_ws(l0);
    t1 = json$at_end(l0);
    if (t1) {
        t0 = json$fail(l0, 3053u);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = json$peek_byte(l0);
    if (l2 == 34u) {
        l3 = json$parse_string(l0);
        l4 = l3;
        if (l3.tag == 696u) {
            t0 = l4.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = l3.payload.s;
        vader_struct_json$JsonString_t* _a0_obj = (vader_struct_json$JsonString_t*) vader_gc_alloc(sizeof(vader_struct_json$JsonString_t));
        vader_obj_header_init(_a0_obj, 700u);
        _a0_obj->f_value = t2;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2 == 123u) {
        l3 = json$parse_object(l0, l1);
        l4 = l3;
        if (l3.tag == 696u) {
            t0 = l4.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = l3.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2 == 91u) {
        l3 = json$parse_array(l0, l1);
        l4 = l3;
        if (l3.tag == 696u) {
            t0 = l4.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = l3.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2 == 116u) {
        l5 = true;
    } else {
        l5 = l2 == 102u;
    }
    if (l5) {
        l3 = json$parse_bool(l0);
        l4 = l3;
        if (l3.tag == 696u) {
            t0 = l4.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = l3.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2 == 110u) {
        l3 = json$parse_null(l0);
        l4 = l3;
        if (l3.tag == 696u) {
            t0 = l4.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = l3.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2 == 45u) {
        l5 = true;
    } else {
        l5 = std_char$is_digit(l2);
    }
    if (!(l5)) {
        t0 = json$fail(l0, 3052u);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = json$parse_number(l0);
    l4 = l3;
    if (l3.tag == 696u) {
        t0 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l3.payload.obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static uint32_t json$peek_byte(void* l0) {
    vader_string_t l1;
    int64_t l2;
    bool t0;
    uint8_t t1;
    t0 = json$at_end(l0);
    if (!(t0)) {
        l1 = ((vader_struct_json$Parser_t*) l0)->f_src;
        l2 = ((vader_struct_json$Parser_t*) l0)->f_pos;
        t1 = vader_host_std_core$byte_at(l1, l2);
        return ((uint32_t) (uint8_t) t1);
    }
    return 0u;
}

static vader_box_t json$read_hex4(void* l0) {
    int64_t l1, l2;
    int32_t l3, l4;
    vader_string_t l5;
    vader_box_t l6;
    int64_t t0;
    vader_string_t t1;
    uint8_t t2;
    int32_t t3;
    t0 = ((vader_struct_json$Parser_t*) l0)->f_pos;
    l1 = vader_chk_add(i64, t0, INT64_C(4));
    t1 = ((vader_struct_json$Parser_t*) l0)->f_src;
    l2 = vader_host_std_core$byte_len(t1);
    if ((l1 > l2)) {
        return vader_box_obj(0u, NULL);
    }
    l3 = INT32_C(0);
    l1 = INT64_C(0);
    while ((l1 < INT64_C(4))) {
        l5 = ((vader_struct_json$Parser_t*) l0)->f_src;
        t0 = ((vader_struct_json$Parser_t*) l0)->f_pos;
        l2 = vader_chk_add(i64, t0, l1);
        t2 = vader_host_std_core$byte_at(l5, l2);
        l6 = std_numbers$hex_digit_value(((uint32_t) (uint8_t) t2));
        if (l6.tag == 0u) {
            return vader_box_obj(0u, NULL);
        }
        l4 = ((int32_t) l6.payload.i);
        t3 = vader_chk_mul(i32, l3, INT32_C(16));
        l3 = vader_chk_add(i32, t3, l4);
        l1 = (l1 + INT64_C(1));
    }
    t0 = ((vader_struct_json$Parser_t*) l0)->f_pos;
    l1 = vader_chk_add(i64, t0, INT64_C(4));
    ((vader_struct_json$Parser_t*) l0)->f_pos = l1;
    return vader_box_i32(507u, l3);
}

static void json$skip_ws(void* l0) {
    bool t0;
    uint32_t t1;
    for (;;) {
        t0 = json$at_end(l0);
        if (!(t0)) {
            t1 = json$peek_byte(l0);
            t0 = std_char$is_white_char(t1);
            if (!(t0)) {
                return;
            }
            json$advance(l0);
            continue;
        }
        break;
    }
    return;
}

void* json$unknown_keys(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    int64_t l5, l6;
    vader_string_t l7 = 0;
    vader_box_t t0 = vader_box_null();
    bool t1;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l4 };
    vader_string_t* gc_atom_roots[1] = { &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(26u, 0u, 0u, 504u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_struct_json$JsonObject_t*) l0)->f_entries;
    l4 = ((vader_struct_std_collections$Map__string__json_JsonArray___json_JsonBool___json_JsonNull___json_JsonNumber___json_JsonObject___json_JsonString_t*) l3)->f_ekeys;
    l5 = INT64_C(0);
    l6 = ((vader_struct_std_collections$Map__string__json_JsonArray___json_JsonBool___json_JsonNull___json_JsonNumber___json_JsonObject___json_JsonString_t*) l3)->f_size;
    while ((l5 < l6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        t0 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l5];
        l7 = t0.payload.s;
        t1 = std_core$$array$Contains$contains__string(l1, l7);
        if (!(t1)) {
            vader_array_push_scalar((vader_array_t*) l2, vader_box_string(504u, l7));
        }
        l5 = (l5 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}
