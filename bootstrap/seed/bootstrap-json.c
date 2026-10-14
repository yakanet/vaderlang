#include "bootstrap.split.h"

static void json_advance(void* l0);
static bool json_at_end(void* l0);
static bool json_decode_unicode_escape(void* l0, void* l1);
static vader_box_t json_expect_byte(void* l0, uint32_t l1);
static void* json_fail(void* l0, vader_string_t l1);
static bool json_match_keyword(void* l0, vader_string_t l1);
static void* json_new_parser(vader_string_t l0);
static vader_box_t json_parse_array(void* l0, int32_t l1);
static vader_box_t json_parse_bool(void* l0);
static vader_box_t json_parse_null(void* l0);
static vader_box_t json_parse_number(void* l0);
static vader_box_t json_parse_object(void* l0, int32_t l1);
static vader_box_t json_parse_string(void* l0);
static vader_box_t json_parse_string_with_escapes(void* l0, void* l1);
static vader_box_t json_parse_value(void* l0, int32_t l1);
static uint32_t json_peek_byte(void* l0);
static int32_t json_read_hex4(void* l0);
static void json_skip_ws(void* l0);

static void json_advance(void* l0) {
    size_t l1;
    size_t t0;
    int64_t t1;
    t0 = ((vader_struct_json_Parser_t*) l0)->f_pos;
    t1 = vader_chk_add(usize, t0, INT64_C(1));
    l1 = (size_t) (int64_t) t1;
    ((vader_struct_json_Parser_t*) l0)->f_pos = l1;
    return;
}

static bool json_at_end(void* l0) {
    size_t l1, l2;
    vader_string_t t0;
    l1 = ((vader_struct_json_Parser_t*) l0)->f_pos;
    t0 = ((vader_struct_json_Parser_t*) l0)->f_src;
    l2 = vader_host_std_core_byte_len(t0);
    return (l1 >= l2);
}

static bool json_decode_unicode_escape(void* l0, void* l1) {
    int32_t l2;
    uint32_t l3, l7;
    size_t l4, l5;
    vader_string_t l6 = 0;
    bool t0;
    size_t t1;
    int64_t t2;
    vader_string_t t3 = 0;
    uint8_t t4;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[2] = { &l6, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = json_read_hex4(l0);
    if ((l2 < INT32_C(0))) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    l3 = ((uint32_t) (int32_t) l2);
    t0 = std_string_is_surrogate(l3);
    if (!(t0)) {
        std_string_builder_append_char(l1, l3);
        { vader_gc_top = gc_frame.prev; return true; }
    }
    t0 = std_string_is_high_surrogate(l3);
    if (t0) {
        t1 = ((vader_struct_json_Parser_t*) l0)->f_pos;
        t2 = vader_chk_add(usize, t1, INT64_C(2));
        l4 = (size_t) (int64_t) t2;
        t3 = ((vader_struct_json_Parser_t*) l0)->f_src;
        l5 = vader_host_std_core_byte_len(t3);
        if ((l4 <= l5)) {
            l6 = ((vader_struct_json_Parser_t*) l0)->f_src;
            l4 = ((vader_struct_json_Parser_t*) l0)->f_pos;
            t4 = vader_host_std_core_byte_at(l6, l4);
            if (t4 == INT32_C(92)) {
                l6 = ((vader_struct_json_Parser_t*) l0)->f_src;
                t1 = ((vader_struct_json_Parser_t*) l0)->f_pos;
                t2 = vader_chk_add(usize, t1, INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                t4 = vader_host_std_core_byte_at(l6, l4);
                if (t4 == INT32_C(117)) {
                    l4 = ((vader_struct_json_Parser_t*) l0)->f_pos;
                    t1 = ((vader_struct_json_Parser_t*) l0)->f_pos;
                    t2 = vader_chk_add(usize, t1, INT64_C(2));
                    l5 = (size_t) (int64_t) t2;
                    ((vader_struct_json_Parser_t*) l0)->f_pos = l5;
                    l2 = json_read_hex4(l0);
                    if ((l2 >= INT32_C(0))) {
                        l7 = ((uint32_t) (int32_t) l2);
                        t0 = std_string_is_low_surrogate(l7);
                        if (t0) {
                            l3 = std_string_combine_surrogates(l3, l7);
                            std_string_builder_append_char(l1, l3);
                            { vader_gc_top = gc_frame.prev; return true; }
                        }
                    }
                    ((vader_struct_json_Parser_t*) l0)->f_pos = l4;
                }
            }
        }
    }
    l3 = ((uint32_t) 65533);
    std_string_builder_append_char(l1, l3);
    { vader_gc_top = gc_frame.prev; return true; }
}

static vader_box_t json_expect_byte(void* l0, uint32_t l1) {
    bool t0;
    void* t1 = NULL;
    uint32_t t2;
    void** gc_raw_roots[2] = { &l0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = json_at_end(l0);
    if (t0) {
        t1 = json_fail(l0, 2545u);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = json_peek_byte(l0);
    if (!(t2 != l1)) {
        json_advance(l0);
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t1 = json_fail(l0, 2544u);
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* json_fail(void* l0, vader_string_t l1) {
    size_t l2;
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_json_Parser_t*) l0)->f_pos;
    vader_struct_json_JsonError_t* _a0_obj = (vader_struct_json_JsonError_t*) vader_gc_alloc(sizeof(vader_struct_json_JsonError_t));
    vader_obj_header_init(_a0_obj, 336u);
    _a0_obj->f_msg = l1;
    _a0_obj->f_pos = l2;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool json_match_keyword(void* l0, vader_string_t l1) {
    size_t l2, l3, l4;
    vader_string_t l5;
    uint8_t l6, l7;
    size_t t0;
    int64_t t1;
    vader_string_t t2;
    l2 = vader_host_std_core_byte_len(l1);
    t0 = ((vader_struct_json_Parser_t*) l0)->f_pos;
    t1 = vader_chk_add(usize, t0, l2);
    l3 = (size_t) (int64_t) t1;
    t2 = ((vader_struct_json_Parser_t*) l0)->f_src;
    l4 = vader_host_std_core_byte_len(t2);
    if ((l3 > l4)) {
        return false;
    }
    l3 = (size_t) 0;
    while ((l3 < l2)) {
        l5 = ((vader_struct_json_Parser_t*) l0)->f_src;
        t0 = ((vader_struct_json_Parser_t*) l0)->f_pos;
        t1 = vader_chk_add(usize, t0, l3);
        l4 = (size_t) (int64_t) t1;
        l6 = vader_host_std_core_byte_at(l5, l4);
        l7 = vader_host_std_core_byte_at(l1, l3);
        if (l6 != l7) {
            return false;
        }
        t1 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t1;
    }
    t0 = ((vader_struct_json_Parser_t*) l0)->f_pos;
    t1 = vader_chk_add(usize, t0, l2);
    l2 = (size_t) (int64_t) t1;
    ((vader_struct_json_Parser_t*) l0)->f_pos = l2;
    return true;
}

static void* json_new_parser(vader_string_t l0) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_json_Parser_t* _a0_obj = (vader_struct_json_Parser_t*) vader_gc_alloc(sizeof(vader_struct_json_Parser_t));
    vader_obj_header_init(_a0_obj, 341u);
    _a0_obj->f_src = l0;
    _a0_obj->f_pos = (size_t) 0;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t json_parse(vader_string_t l0) {
    void* l1 = NULL;
    vader_box_t l2 = vader_box_null();
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = json_new_parser(l0);
    l2 = json_parse_value(l1, INT32_C(0));
    if (l2.tag == 336u) {
        t0 = l2.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    json_skip_ws(l1);
    t1 = json_at_end(l1);
    if (!(t1)) {
        t0 = json_fail(l1, 2464u);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t json_parse_array(void* l0, int32_t l1) {
    void* l2 = NULL;
    int32_t l3;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    uint32_t l6;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    bool t2;
    uint32_t t3;
    vader_box_t* gc_roots[3] = { &l4, &l5, &t0 };
    void** gc_raw_roots[3] = { &l0, &l2, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = json_expect_byte(l0, 91u);
    if (t0.tag == 336u) {
        t0 = json_expect_byte(l0, 91u);
        t1 = t0.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(204u, 0u, 13u, 1343u);
    l2 = (void*) _a0_arr;
    json_skip_ws(l0);
    t2 = json_at_end(l0);
    if (!(t2)) {
        t3 = json_peek_byte(l0);
        if (t3 == 93u) {
            json_advance(l0);
            vader_struct_json_JsonArray_t* _a1_obj = (vader_struct_json_JsonArray_t*) vader_gc_alloc(sizeof(vader_struct_json_JsonArray_t));
            vader_obj_header_init(_a1_obj, 334u);
            _a1_obj->f_items = l2;
            t1 = (void*) _a1_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    for (;;) {
        t2 = json_at_end(l0);
        if (!(t2)) {
            l3 = vader_chk_add(i32, l1, INT32_C(1));
            l4 = json_parse_value(l0, l3);
            if (l4.tag == 336u) {
                t1 = l4.payload.obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l5 = l4;
            vader_array_push((vader_array_t*) l2, l5);
            json_skip_ws(l0);
            t2 = json_at_end(l0);
            if (t2) {
                t1 = json_fail(l0, 2566u);
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l6 = json_peek_byte(l0);
            if (l6 == 44u) {
                json_advance(l0);
                json_skip_ws(l0);
                continue;
            }
            if (!(l6 == 93u)) {
                t1 = json_fail(l0, 1663u);
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            json_advance(l0);
            vader_struct_json_JsonArray_t* _a2_obj = (vader_struct_json_JsonArray_t*) vader_gc_alloc(sizeof(vader_struct_json_JsonArray_t));
            vader_obj_header_init(_a2_obj, 334u);
            _a2_obj->f_items = l2;
            t1 = (void*) _a2_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        break;
    }
    t1 = json_fail(l0, 2566u);
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t json_parse_bool(void* l0) {
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[2] = { &l0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = json_match_keyword(l0, 2472u);
    if (t0) {
        vader_struct_json_JsonBool_t* _a0_obj = (vader_struct_json_JsonBool_t*) vader_gc_alloc(sizeof(vader_struct_json_JsonBool_t));
        vader_obj_header_init(_a0_obj, 335u);
        _a0_obj->f_value = true;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = json_match_keyword(l0, 1724u);
    if (!(t0)) {
        t1 = json_fail(l0, 1667u);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_json_JsonBool_t* _a1_obj = (vader_struct_json_JsonBool_t*) vader_gc_alloc(sizeof(vader_struct_json_JsonBool_t));
    vader_obj_header_init(_a1_obj, 335u);
    _a1_obj->f_value = false;
    t1 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t json_parse_null(void* l0) {
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[2] = { &l0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = json_match_keyword(l0, 2146u);
    if (!(t0)) {
        t1 = json_fail(l0, 1666u);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_json_JsonNull_t* _a0_obj = (vader_struct_json_JsonNull_t*) vader_gc_alloc(sizeof(vader_struct_json_JsonNull_t));
    vader_obj_header_init(_a0_obj, 337u);
    t1 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t json_parse_number(void* l0) {
    size_t l1, l6;
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
    l1 = ((vader_struct_json_Parser_t*) l0)->f_pos;
    t0 = json_peek_byte(l0);
    if (t0 == 45u) {
        json_advance(l0);
    }
    t1 = json_at_end(l0);
    if (t1) {
        l2 = true;
    } else {
        t0 = json_peek_byte(l0);
        t1 = std_char_is_digit(t0);
        l2 = !(t1);
    }
    if (l2) {
        t2 = json_fail(l0, 1677u);
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = json_peek_byte(l0);
    json_advance(l0);
    if (l3 == 48u) {
        t1 = json_at_end(l0);
        if (!(t1)) {
            t0 = json_peek_byte(l0);
            t1 = std_char_is_digit(t0);
            if (t1) {
                t2 = json_fail(l0, 2011u);
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
    }
    for (;;) {
        t1 = json_at_end(l0);
        if (!(t1)) {
            t0 = json_peek_byte(l0);
            t1 = std_char_is_digit(t0);
            if (!(t1)) {
                break;
            }
            json_advance(l0);
            continue;
        }
        break;
    }
    t1 = json_at_end(l0);
    if (!(t1)) {
        t0 = json_peek_byte(l0);
        if (t0 == 46u) {
            json_advance(l0);
            t1 = json_at_end(l0);
            if (t1) {
                l2 = true;
            } else {
                t0 = json_peek_byte(l0);
                t1 = std_char_is_digit(t0);
                l2 = !(t1);
            }
            if (l2) {
                t2 = json_fail(l0, 1678u);
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            for (;;) {
                t1 = json_at_end(l0);
                if (!(t1)) {
                    t0 = json_peek_byte(l0);
                    t1 = std_char_is_digit(t0);
                    if (!(t1)) {
                        break;
                    }
                    json_advance(l0);
                    continue;
                }
                break;
            }
        }
    }
    t1 = json_at_end(l0);
    if (!(t1)) {
        t0 = json_peek_byte(l0);
        if (t0 == 101u) {
            l4 = true;
        } else {
            t0 = json_peek_byte(l0);
            l4 = t0 == 69u;
        }
        l2 = l4;
    } else {
        l2 = false;
    }
    if (l2) {
        json_advance(l0);
        t1 = json_at_end(l0);
        if (!(t1)) {
            t0 = json_peek_byte(l0);
            if (t0 == 43u) {
                l4 = true;
            } else {
                t0 = json_peek_byte(l0);
                l4 = t0 == 45u;
            }
            l2 = l4;
        } else {
            l2 = false;
        }
        if (l2) {
            json_advance(l0);
        }
        t1 = json_at_end(l0);
        if (t1) {
            l2 = true;
        } else {
            t0 = json_peek_byte(l0);
            t1 = std_char_is_digit(t0);
            l2 = !(t1);
        }
        if (l2) {
            t2 = json_fail(l0, 1679u);
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        for (;;) {
            t1 = json_at_end(l0);
            if (!(t1)) {
                t0 = json_peek_byte(l0);
                t1 = std_char_is_digit(t0);
                if (!(t1)) {
                    break;
                }
                json_advance(l0);
                continue;
            }
            break;
        }
    }
    l5 = ((vader_struct_json_Parser_t*) l0)->f_src;
    l6 = ((vader_struct_json_Parser_t*) l0)->f_pos;
    t3 = std_core_byte_slice(l5, l1, l6);
    l7 = std_string_parse_float(t3);
    if ((l7.tag == 274u || l7.tag == 275u)) {
        t4 = ((double) l7.payload.f);
        vader_struct_json_JsonNumber_t* _a0_obj = (vader_struct_json_JsonNumber_t*) vader_gc_alloc(sizeof(vader_struct_json_JsonNumber_t));
        vader_obj_header_init(_a0_obj, 338u);
        _a0_obj->f_value = t4;
        t2 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l7.tag == 494u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    t2 = json_fail(l0, 1954u);
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t json_parse_object(void* l0, int32_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    vader_box_t l5 = vader_box_null(), l7 = vader_box_null(), l9 = vader_box_null();
    int32_t l6;
    vader_string_t l8 = 0;
    uint32_t l10;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    bool t2;
    uint32_t t3;
    vader_box_t* gc_roots[4] = { &l5, &l7, &l9, &t0 };
    void** gc_raw_roots[5] = { &l0, &l2, &l3, &l4, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l8 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = json_expect_byte(l0, 123u);
    if (t0.tag == 336u) {
        t0 = json_expect_byte(l0, 123u);
        t1 = t0.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 0u, 278u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(23u, 0u, 0u, 289u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(16u, 0u, 7u, 281u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 384u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    l2 = (void*) _a3_obj;
    json_skip_ws(l0);
    t2 = json_at_end(l0);
    if (!(t2)) {
        t3 = json_peek_byte(l0);
        if (t3 == 125u) {
            json_advance(l0);
            vader_struct_json_JsonObject_t* _a4_obj = (vader_struct_json_JsonObject_t*) vader_gc_alloc(sizeof(vader_struct_json_JsonObject_t));
            vader_obj_header_init(_a4_obj, 339u);
            _a4_obj->f_entries = l2;
            t1 = (void*) _a4_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    for (;;) {
        t2 = json_at_end(l0);
        if (!(t2)) {
            json_skip_ws(l0);
            l5 = json_parse_string(l0);
            if (l5.tag == 336u) {
                t1 = l5.payload.obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            json_skip_ws(l0);
            t0 = json_expect_byte(l0, 58u);
            if (t0.tag == 336u) {
                t0 = json_expect_byte(l0, 58u);
                t1 = t0.payload.obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l6 = vader_chk_add(i32, l1, INT32_C(1));
            l7 = json_parse_value(l0, l6);
            if (l7.tag == 336u) {
                t1 = l7.payload.obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l8 = l5.payload.s;
            l9 = l7;
            std_collections_MutableMap_IndexSet_set_at__string__Any(l2, l8, l9);
            json_skip_ws(l0);
            t2 = json_at_end(l0);
            if (t2) {
                t1 = json_fail(l0, 2570u);
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l10 = json_peek_byte(l0);
            if (l10 == 44u) {
                json_advance(l0);
                continue;
            }
            if (!(l10 == 125u)) {
                t1 = json_fail(l0, 1664u);
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            json_advance(l0);
            vader_struct_json_JsonObject_t* _a5_obj = (vader_struct_json_JsonObject_t*) vader_gc_alloc(sizeof(vader_struct_json_JsonObject_t));
            vader_obj_header_init(_a5_obj, 339u);
            _a5_obj->f_entries = l2;
            t1 = (void*) _a5_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        break;
    }
    t1 = json_fail(l0, 2570u);
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t json_parse_string(void* l0) {
    size_t l1, l2, l3, l5;
    uint8_t l4;
    void* l6 = NULL;
    vader_string_t l7 = 0;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_string_t t2 = 0;
    vader_string_t t4 = 0;
    int64_t t3;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[3] = { &l0, &l6, &t1 };
    vader_string_t* gc_atom_roots[3] = { &l7, &t2, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = json_expect_byte(l0, 34u);
    if (t0.tag == 336u) {
        t0 = json_expect_byte(l0, 34u);
        t1 = t0.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = ((vader_struct_json_Parser_t*) l0)->f_pos;
    l2 = ((vader_struct_json_Parser_t*) l0)->f_pos;
    t2 = ((vader_struct_json_Parser_t*) l0)->f_src;
    l3 = vader_host_std_core_byte_len(t2);
    while ((l2 < l3)) {
        t2 = ((vader_struct_json_Parser_t*) l0)->f_src;
        l4 = vader_host_std_core_byte_at(t2, l2);
        if (l4 == INT32_C(34)) {
            t3 = vader_chk_add(usize, l2, INT64_C(1));
            l5 = (size_t) (int64_t) t3;
            ((vader_struct_json_Parser_t*) l0)->f_pos = l5;
            t2 = ((vader_struct_json_Parser_t*) l0)->f_src;
            t4 = std_core_byte_slice(t2, l1, l2);
            t0 = vader_box_string(278u, t4);
            { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l4 == INT32_C(92)) {
            vader_array_t* _a0_arr = vader_array_new(15u, 0u, 0u, 278u);
            t1 = (void*) _a0_arr;
            vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
            vader_obj_header_init(_a1_obj, 496u);
            _a1_obj->f_parts = t1;
            l6 = (void*) _a1_obj;
            t2 = ((vader_struct_json_Parser_t*) l0)->f_src;
            l7 = std_core_byte_slice(t2, l1, l2);
            std_string_builder_append(l6, l7);
            ((vader_struct_json_Parser_t*) l0)->f_pos = l2;
            t0 = json_parse_string_with_escapes(l0, l6);
            { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t3 = (l2 + INT64_C(1));
        l2 = (size_t) (int64_t) t3;
    }
    t1 = json_fail(l0, 2571u);
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t json_parse_string_with_escapes(void* l0, void* l1) {
    vader_string_t l2 = 0;
    vader_string_t l9 = 0;
    vader_string_t l11 = 0;
    vader_string_t l13 = 0;
    vader_string_t l15 = 0;
    size_t l3, l8, l10, l12, l14;
    uint8_t l4;
    uint32_t l5, l6, l7;
    bool t0;
    vader_string_t t1 = 0;
    vader_box_t t2 = vader_box_null();
    void* t3 = NULL;
    uint8_t t4;
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[3] = { &l0, &l1, &t3 };
    vader_string_t* gc_atom_roots[6] = { &l2, &l9, &l11, &l13, &l15, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 6u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    for (;;) {
        t0 = json_at_end(l0);
        if (!(t0)) {
            l2 = ((vader_struct_json_Parser_t*) l0)->f_src;
            l3 = ((vader_struct_json_Parser_t*) l0)->f_pos;
            l4 = vader_host_std_core_byte_at(l2, l3);
            if (l4 == INT32_C(34)) {
                json_advance(l0);
                t1 = std_string_builder_StringBuilder_Display_to_string(l1);
                t2 = vader_box_string(278u, t1);
                { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l4 == INT32_C(92)) {
                json_advance(l0);
                t0 = json_at_end(l0);
                if (t0) {
                    t3 = json_fail(l0, 2569u);
                    { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
                }
                l5 = json_peek_byte(l0);
                json_advance(l0);
                if (l5 == 34u) {
                    std_string_builder_append_char(l1, 34u);
                } else if (l5 == 92u) {
                    std_string_builder_append_char(l1, 92u);
                } else if (l5 == 47u) {
                    std_string_builder_append_char(l1, 47u);
                } else if (l5 == 110u) {
                    std_string_builder_append_char(l1, 10u);
                } else if (l5 == 116u) {
                    std_string_builder_append_char(l1, 9u);
                } else if (l5 == 114u) {
                    std_string_builder_append_char(l1, 13u);
                } else if (l5 == 98u) {
                    l6 = ((uint32_t) 8);
                    std_string_builder_append_char(l1, l6);
                } else if (l5 == 102u) {
                    l7 = ((uint32_t) 12);
                    std_string_builder_append_char(l1, l7);
                } else {
                    if (!(l5 == 117u)) {
                        t3 = json_fail(l0, 2551u);
                        { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
                    }
                    t0 = json_decode_unicode_escape(l0, l1);
                    if (!(t0)) {
                        t3 = json_fail(l0, 1944u);
                        { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
                    }
                }
                continue;
            }
            l8 = ((vader_struct_json_Parser_t*) l0)->f_pos;
            for (;;) {
                t0 = json_at_end(l0);
                if (!(t0)) {
                    l9 = ((vader_struct_json_Parser_t*) l0)->f_src;
                    l10 = ((vader_struct_json_Parser_t*) l0)->f_pos;
                    t4 = vader_host_std_core_byte_at(l9, l10);
                    if (!(t4 != INT32_C(34))) {
                        break;
                    }
                    l11 = ((vader_struct_json_Parser_t*) l0)->f_src;
                    l12 = ((vader_struct_json_Parser_t*) l0)->f_pos;
                    t4 = vader_host_std_core_byte_at(l11, l12);
                    if (!(t4 != INT32_C(92))) {
                        break;
                    }
                    json_advance(l0);
                    continue;
                }
                break;
            }
            l13 = ((vader_struct_json_Parser_t*) l0)->f_src;
            l14 = ((vader_struct_json_Parser_t*) l0)->f_pos;
            l15 = std_core_byte_slice(l13, l8, l14);
            std_string_builder_append(l1, l15);
            continue;
        }
        break;
    }
    t3 = json_fail(l0, 2571u);
    { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t json_parse_value(void* l0, int32_t l1) {
    uint32_t l2;
    vader_box_t l3 = vader_box_null();
    bool l4;
    void* t0 = NULL;
    bool t1;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if ((l1 > INT32_C(200))) {
        t0 = json_fail(l0, 2054u);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    json_skip_ws(l0);
    t1 = json_at_end(l0);
    if (t1) {
        t0 = json_fail(l0, 2545u);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = json_peek_byte(l0);
    if (l2 == 34u) {
        l3 = json_parse_string(l0);
        if (!(l3.tag == 336u)) {
            t2 = l3.payload.s;
            vader_struct_json_JsonString_t* _a0_obj = (vader_struct_json_JsonString_t*) vader_gc_alloc(sizeof(vader_struct_json_JsonString_t));
            vader_obj_header_init(_a0_obj, 340u);
            _a0_obj->f_value = t2;
            t0 = (void*) _a0_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = l3.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2 == 123u) {
        l3 = json_parse_object(l0, l1);
        if (!(l3.tag == 336u)) {
            t0 = l3.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = l3.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2 == 91u) {
        l3 = json_parse_array(l0, l1);
        if (!(l3.tag == 336u)) {
            t0 = l3.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = l3.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2 == 116u) {
        l4 = true;
    } else {
        l4 = l2 == 102u;
    }
    if (l4) {
        l3 = json_parse_bool(l0);
        if (!(l3.tag == 336u)) {
            t0 = l3.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = l3.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2 == 110u) {
        l3 = json_parse_null(l0);
        if (!(l3.tag == 336u)) {
            t0 = l3.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = l3.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2 == 45u) {
        l4 = true;
    } else {
        l4 = std_char_is_digit(l2);
    }
    if (!(l4)) {
        t0 = json_fail(l0, 2544u);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = json_parse_number(l0);
    if (!(l3.tag == 336u)) {
        t0 = l3.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l3.payload.obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static uint32_t json_peek_byte(void* l0) {
    vader_string_t l1;
    size_t l2;
    bool t0;
    uint32_t t1;
    t0 = json_at_end(l0);
    if (!(t0)) {
        l1 = ((vader_struct_json_Parser_t*) l0)->f_src;
        l2 = ((vader_struct_json_Parser_t*) l0)->f_pos;
        t1 = std_string_char_at_byte(l1, l2);
        return t1;
    }
    return 0u;
}

static int32_t json_read_hex4(void* l0) {
    size_t l1, l2;
    int32_t l3, l5;
    vader_string_t l4;
    size_t t0;
    int64_t t1;
    vader_string_t t2;
    uint32_t t3;
    int32_t t4;
    t0 = ((vader_struct_json_Parser_t*) l0)->f_pos;
    t1 = vader_chk_add(usize, t0, INT64_C(4));
    l1 = (size_t) (int64_t) t1;
    t2 = ((vader_struct_json_Parser_t*) l0)->f_src;
    l2 = vader_host_std_core_byte_len(t2);
    if ((l1 > l2)) {
        return INT32_C(-1);
    }
    l3 = INT32_C(0);
    l1 = (size_t) 0;
    while ((l1 < INT64_C(4))) {
        l4 = ((vader_struct_json_Parser_t*) l0)->f_src;
        t0 = ((vader_struct_json_Parser_t*) l0)->f_pos;
        t1 = vader_chk_add(usize, t0, l1);
        l2 = (size_t) (int64_t) t1;
        t3 = std_string_char_at_byte(l4, l2);
        l5 = std_numbers_hex_digit_value(t3);
        if ((l5 < INT32_C(0))) {
            return INT32_C(-1);
        }
        t4 = vader_chk_mul(i32, l3, INT32_C(16));
        l3 = vader_chk_add(i32, t4, l5);
        t1 = (l1 + INT64_C(1));
        l1 = (size_t) (int64_t) t1;
    }
    t0 = ((vader_struct_json_Parser_t*) l0)->f_pos;
    t1 = vader_chk_add(usize, t0, INT64_C(4));
    l1 = (size_t) (int64_t) t1;
    ((vader_struct_json_Parser_t*) l0)->f_pos = l1;
    return l3;
}

static void json_skip_ws(void* l0) {
    bool t0;
    uint32_t t1;
    for (;;) {
        t0 = json_at_end(l0);
        if (!(t0)) {
            t1 = json_peek_byte(l0);
            t0 = std_char_is_white_char(t1);
            if (!(t0)) {
                return;
            }
            json_advance(l0);
            continue;
        }
        break;
    }
    return;
}
