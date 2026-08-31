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
    t1 = (t0 + INT64_C(1));
    l1 = (size_t) (int64_t) t1;
    ((vader_struct_json_Parser_t*) l0)->f_pos = l1;
    VADER_WRITE_BARRIER((vader_struct_json_Parser_t*) l0);
    return;
}

static bool json_at_end(void* l0) {
    size_t l1, l2;
    l1 = ((vader_struct_json_Parser_t*) l0)->f_pos;
    l2 = ((vader_struct_json_Parser_t*) l0)->f_eof;
    return (l1 >= l2);
}

static bool json_decode_unicode_escape(void* l0, void* l1) {
    int32_t l2;
    uint32_t l3, l8;
    size_t l4, l5;
    bool l6;
    void* l7 = NULL;
    bool t0;
    size_t t1;
    int64_t t2;
    vader_box_t t3 = vader_box_null();
    uint8_t t4;
    vader_box_t* gc_roots[1] = { &t3 };
    void** gc_raw_roots[3] = { &l0, &l1, &l7 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
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
        t2 = (t1 + INT64_C(2));
        l4 = (size_t) (int64_t) t2;
        l5 = ((vader_struct_json_Parser_t*) l0)->f_eof;
        if ((l4 <= l5)) {
            l7 = ((vader_struct_json_Parser_t*) l0)->f_bytes;
            l4 = ((vader_struct_json_Parser_t*) l0)->f_pos;
            vader_array_t* _a0_slotarr = ((vader_array_t*) l7);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t3 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l4, 167u);
            t4 = ((uint8_t) t3.payload.i);
            l6 = t4 == INT32_C(92);
        } else {
            l6 = false;
        }
        if (l6) {
            l7 = ((vader_struct_json_Parser_t*) l0)->f_bytes;
            t1 = ((vader_struct_json_Parser_t*) l0)->f_pos;
            t2 = (t1 + INT64_C(1));
            l4 = (size_t) (int64_t) t2;
            vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
            if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
            if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
            t3 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) l4, 167u);
            t4 = ((uint8_t) t3.payload.i);
            l6 = t4 == INT32_C(117);
        } else {
            l6 = false;
        }
        if (l6) {
            l4 = ((vader_struct_json_Parser_t*) l0)->f_pos;
            t1 = ((vader_struct_json_Parser_t*) l0)->f_pos;
            t2 = (t1 + INT64_C(2));
            l5 = (size_t) (int64_t) t2;
            ((vader_struct_json_Parser_t*) l0)->f_pos = l5;
            VADER_WRITE_BARRIER((vader_struct_json_Parser_t*) l0);
            l2 = json_read_hex4(l0);
            if ((l2 >= INT32_C(0))) {
                l8 = ((uint32_t) (int32_t) l2);
                t0 = std_string_is_low_surrogate(l8);
                if (t0) {
                    l3 = std_string_combine_surrogates(l3, l8);
                    std_string_builder_append_char(l1, l3);
                    { vader_gc_top = gc_frame.prev; return true; }
                }
                ((vader_struct_json_Parser_t*) l0)->f_pos = l4;
                VADER_WRITE_BARRIER((vader_struct_json_Parser_t*) l0);
                l3 = ((uint32_t) (int32_t) INT32_C(65533));
                std_string_builder_append_char(l1, l3);
                { vader_gc_top = gc_frame.prev; return true; }
            }
            ((vader_struct_json_Parser_t*) l0)->f_pos = l4;
            VADER_WRITE_BARRIER((vader_struct_json_Parser_t*) l0);
            l3 = ((uint32_t) (int32_t) INT32_C(65533));
            std_string_builder_append_char(l1, l3);
            { vader_gc_top = gc_frame.prev; return true; }
        }
        l3 = ((uint32_t) (int32_t) INT32_C(65533));
        std_string_builder_append_char(l1, l3);
        { vader_gc_top = gc_frame.prev; return true; }
    }
    l3 = ((uint32_t) (int32_t) INT32_C(65533));
    std_string_builder_append_char(l1, l3);
    { vader_gc_top = gc_frame.prev; return true; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t json_expect_byte(void* l0, uint32_t l1) {
    bool t0;
    void* t1 = NULL;
    uint32_t t2;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t3 };
    void** gc_raw_roots[2] = { &l0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = json_at_end(l0);
    if (t0) {
        t1 = json_fail(l0, 2251u);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = json_peek_byte(l0);
    if (t2 != l1) {
        t1 = json_fail(l0, 2250u);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    json_advance(l0);
    t3 = vader_box_obj(0u, NULL);
    { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* json_fail(void* l0, vader_string_t l1) {
    size_t l2;
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_json_Parser_t*) l0)->f_pos;
    vader_struct_json_JsonError_t* _a0_obj = (vader_struct_json_JsonError_t*) vader_gc_alloc(sizeof(vader_struct_json_JsonError_t));
    vader_obj_header_init(_a0_obj, 274u);
    _a0_obj->f_msg = l1;
    _a0_obj->f_pos = l2;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static bool json_match_keyword(void* l0, vader_string_t l1) {
    size_t l2, l3, l4;
    void* l5 = NULL;
    uint8_t l6, l7;
    size_t t0;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_import_0(l1);
    t0 = ((vader_struct_json_Parser_t*) l0)->f_pos;
    t1 = (t0 + l2);
    l3 = (size_t) (int64_t) t1;
    l4 = ((vader_struct_json_Parser_t*) l0)->f_eof;
    if ((l3 > l4)) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_20: {
            if ((l3 < l2)) {
                l5 = ((vader_struct_json_Parser_t*) l0)->f_bytes;
                t0 = ((vader_struct_json_Parser_t*) l0)->f_pos;
                t1 = (t0 + l3);
                l4 = (size_t) (int64_t) t1;
                vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l4, 167u);
                l6 = ((uint8_t) t2.payload.i);
                l7 = vader_import_1(l1, l3);
                if (l6 != l7) {
                    { vader_gc_top = gc_frame.prev; return false; }
                }
                t1 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t1;
                goto loop_20;
            } else {
            }
        }
    }
    t0 = ((vader_struct_json_Parser_t*) l0)->f_pos;
    t1 = (t0 + l2);
    l2 = (size_t) (int64_t) t1;
    ((vader_struct_json_Parser_t*) l0)->f_pos = l2;
    VADER_WRITE_BARRIER((vader_struct_json_Parser_t*) l0);
    { vader_gc_top = gc_frame.prev; return true; }
    vader_gc_top = gc_frame.prev;
}

static void* json_new_parser(vader_string_t l0) {
    void* l1 = NULL;
    size_t l2;
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_import_3(l0);
    l2 = vader_import_0(l0);
    vader_struct_json_Parser_t* _a0_obj = (vader_struct_json_Parser_t*) vader_gc_alloc(sizeof(vader_struct_json_Parser_t));
    vader_obj_header_init(_a0_obj, 279u);
    _a0_obj->f_src = l0;
    _a0_obj->f_bytes = l1;
    _a0_obj->f_pos = (size_t) (int64_t) INT64_C(0);
    _a0_obj->f_eof = l2;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t json_parse(vader_string_t l0) {
    void* l1 = NULL;
    vader_box_t l2 = vader_box_null();
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = json_new_parser(l0);
    l2 = json_parse_value(l1, INT32_C(0));
    if (l2.tag == 274u) {
        t0 = l2.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    json_skip_ws(l1);
    t1 = json_at_end(l1);
    if (!(t1)) {
        t0 = json_fail(l1, 2143u);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t json_parse_array(void* l0, int32_t l1) {
    void* l2 = NULL;
    bool l3;
    int32_t l4;
    vader_box_t l5 = vader_box_null(), l6 = vader_box_null();
    uint32_t l7;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    bool t2;
    uint32_t t3;
    vader_box_t* gc_roots[3] = { &l5, &l6, &t0 };
    void** gc_raw_roots[3] = { &l0, &l2, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = json_expect_byte(l0, 91u);
    if (t0.tag == 274u) {
        t0 = json_expect_byte(l0, 91u);
        t1 = t0.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(107u, 0u, 13u, 1000u);
    l2 = (void*) _a0_arr;
    json_skip_ws(l0);
    t2 = json_at_end(l0);
    if (!(t2)) {
        t3 = json_peek_byte(l0);
        l3 = t3 == 93u;
    } else {
        l3 = false;
    }
    if (l3) {
        json_advance(l0);
        vader_struct_json_JsonArray_t* _a1_obj = (vader_struct_json_JsonArray_t*) vader_gc_alloc(sizeof(vader_struct_json_JsonArray_t));
        vader_obj_header_init(_a1_obj, 272u);
        _a1_obj->f_items = l2;
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    {
        loop_37: {
            t2 = json_at_end(l0);
            if (!(t2)) {
                l4 = (l1 + INT32_C(1));
                l5 = json_parse_value(l0, l4);
                if (l5.tag == 274u) {
                    t1 = l5.payload.obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                l6 = l5;
                vader_array_push((vader_array_t*) l2, l6);
                json_skip_ws(l0);
                t2 = json_at_end(l0);
                if (t2) {
                    t1 = json_fail(l0, 2270u);
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                l7 = json_peek_byte(l0);
                if (l7 == 44u) {
                    json_advance(l0);
                    json_skip_ws(l0);
                    goto loop_37;
                }
                if (l7 == 93u) {
                    json_advance(l0);
                    vader_struct_json_JsonArray_t* _a2_obj = (vader_struct_json_JsonArray_t*) vader_gc_alloc(sizeof(vader_struct_json_JsonArray_t));
                    vader_obj_header_init(_a2_obj, 272u);
                    _a2_obj->f_items = l2;
                    t1 = (void*) _a2_obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                t1 = json_fail(l0, 1442u);
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            } else {
            }
        }
    }
    t1 = json_fail(l0, 2270u);
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t json_parse_bool(void* l0) {
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[2] = { &l0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = json_match_keyword(l0, 2151u);
    if (t0) {
        vader_struct_json_JsonBool_t* _a0_obj = (vader_struct_json_JsonBool_t*) vader_gc_alloc(sizeof(vader_struct_json_JsonBool_t));
        vader_obj_header_init(_a0_obj, 273u);
        _a0_obj->f_value = true;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = json_match_keyword(l0, 1504u);
    if (t0) {
        vader_struct_json_JsonBool_t* _a1_obj = (vader_struct_json_JsonBool_t*) vader_gc_alloc(sizeof(vader_struct_json_JsonBool_t));
        vader_obj_header_init(_a1_obj, 273u);
        _a1_obj->f_value = false;
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = json_fail(l0, 1446u);
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t json_parse_null(void* l0) {
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[2] = { &l0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = json_match_keyword(l0, 1851u);
    if (!(t0)) {
        t1 = json_fail(l0, 1445u);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_json_JsonNull_t* _a0_obj = (vader_struct_json_JsonNull_t*) vader_gc_alloc(sizeof(vader_struct_json_JsonNull_t));
    vader_obj_header_init(_a0_obj, 275u);
    t1 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t json_parse_number(void* l0) {
    size_t l1, l18;
    bool l2, l5, l8, l11, l14, l16;
    uint32_t l3, l4, l6, l7, l9, l10, l12, l13;
    vader_string_t l15, l20;
    void* l17 = NULL;
    vader_box_t l19 = vader_box_null();
    uint32_t t0;
    bool t1;
    void* t2 = NULL;
    vader_string_t t3;
    double t4;
    vader_box_t* gc_roots[1] = { &l19 };
    void** gc_raw_roots[3] = { &l0, &l17, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_json_Parser_t*) l0)->f_pos;
    t0 = json_peek_byte(l0);
    if (t0 == 45u) {
        json_advance(l0);
    } else {
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
        t2 = json_fail(l0, 1456u);
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = json_peek_byte(l0);
    json_advance(l0);
    if (l3 == 48u) {
        t1 = json_at_end(l0);
        l2 = !(t1);
    } else {
        l2 = false;
    }
    if (l2) {
        t0 = json_peek_byte(l0);
        l2 = std_char_is_digit(t0);
    } else {
        l2 = false;
    }
    if (l2) {
        t2 = json_fail(l0, 1748u);
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    {
        loop_66: {
            t1 = json_at_end(l0);
            if (!(t1)) {
                t0 = json_peek_byte(l0);
                l2 = std_char_is_digit(t0);
            } else {
                l2 = false;
            }
            if (l2) {
                json_advance(l0);
                goto loop_66;
            } else {
            }
        }
    }
    t1 = json_at_end(l0);
    if (!(t1)) {
        t0 = json_peek_byte(l0);
        l2 = t0 == 46u;
    } else {
        l2 = false;
    }
    if (l2) {
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
            t2 = json_fail(l0, 1457u);
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        {
            loop_125: {
                t1 = json_at_end(l0);
                if (!(t1)) {
                    t0 = json_peek_byte(l0);
                    l2 = std_char_is_digit(t0);
                } else {
                    l2 = false;
                }
                if (l2) {
                    json_advance(l0);
                    goto loop_125;
                } else {
                }
            }
        }
        t1 = json_at_end(l0);
        if (!(t1)) {
            l3 = json_peek_byte(l0);
            l4 = 101u;
            if (l3 == l4) {
                l5 = true;
            } else {
                l6 = json_peek_byte(l0);
                l7 = 69u;
                l5 = l6 == l7;
            }
            l2 = l5;
        } else {
            l2 = false;
        }
        if (l2) {
            json_advance(l0);
            t1 = json_at_end(l0);
            if (!(t1)) {
                l9 = json_peek_byte(l0);
                l10 = 43u;
                if (l9 == l10) {
                    l11 = true;
                } else {
                    l12 = json_peek_byte(l0);
                    l13 = 45u;
                    l11 = l12 == l13;
                }
                l8 = l11;
            } else {
                l8 = false;
            }
            if (l8) {
                json_advance(l0);
            } else {
            }
            t1 = json_at_end(l0);
            if (t1) {
                l14 = true;
            } else {
                t0 = json_peek_byte(l0);
                t1 = std_char_is_digit(t0);
                l14 = !(t1);
            }
            if (l14) {
                l15 = 1458u;
                t2 = json_fail(l0, l15);
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            {
                loop_243: {
                    t1 = json_at_end(l0);
                    if (!(t1)) {
                        t0 = json_peek_byte(l0);
                        l16 = std_char_is_digit(t0);
                    } else {
                        l16 = false;
                    }
                    if (l16) {
                        json_advance(l0);
                        goto loop_243;
                    } else {
                    }
                }
            }
            l17 = ((vader_struct_json_Parser_t*) l0)->f_bytes;
            l18 = ((vader_struct_json_Parser_t*) l0)->f_pos;
            vader_array_t* _a0_arr = vader_array_slice((vader_array_t*) l17, (size_t) l1, (size_t) l18);
            t2 = (void*) _a0_arr;
            t3 = vader_import_2(t2);
            l19 = std_string_parse_float(t3);
            if ((l19.tag == 158u || l19.tag == 159u)) {
                t4 = ((double) l19.payload.f);
                vader_struct_json_JsonNumber_t* _a1_obj = (vader_struct_json_JsonNumber_t*) vader_gc_alloc(sizeof(vader_struct_json_JsonNumber_t));
                vader_obj_header_init(_a1_obj, 276u);
                _a1_obj->f_value = t4;
                t2 = (void*) _a1_obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l19.tag == 383u) {
                l20 = 1704u;
                t2 = json_fail(l0, l20);
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            vader_unreachable("unreachable return in json$parse_number");
        }
        l17 = ((vader_struct_json_Parser_t*) l0)->f_bytes;
        l18 = ((vader_struct_json_Parser_t*) l0)->f_pos;
        vader_array_t* _a2_arr = vader_array_slice((vader_array_t*) l17, (size_t) l1, (size_t) l18);
        t2 = (void*) _a2_arr;
        t3 = vader_import_2(t2);
        l19 = std_string_parse_float(t3);
        if ((l19.tag == 158u || l19.tag == 159u)) {
            t4 = ((double) l19.payload.f);
            vader_struct_json_JsonNumber_t* _a3_obj = (vader_struct_json_JsonNumber_t*) vader_gc_alloc(sizeof(vader_struct_json_JsonNumber_t));
            vader_obj_header_init(_a3_obj, 276u);
            _a3_obj->f_value = t4;
            t2 = (void*) _a3_obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l19.tag == 383u) {
            l20 = 1704u;
            t2 = json_fail(l0, l20);
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_unreachable("unreachable return in json$parse_number");
    }
    t1 = json_at_end(l0);
    if (!(t1)) {
        l3 = json_peek_byte(l0);
        l4 = 101u;
        if (l3 == l4) {
            l5 = true;
        } else {
            l6 = json_peek_byte(l0);
            l7 = 69u;
            l5 = l6 == l7;
        }
        l2 = l5;
    } else {
        l2 = false;
    }
    if (l2) {
        json_advance(l0);
        t1 = json_at_end(l0);
        if (!(t1)) {
            l9 = json_peek_byte(l0);
            l10 = 43u;
            if (l9 == l10) {
                l11 = true;
            } else {
                l12 = json_peek_byte(l0);
                l13 = 45u;
                l11 = l12 == l13;
            }
            l8 = l11;
        } else {
            l8 = false;
        }
        if (l8) {
            json_advance(l0);
        } else {
        }
        t1 = json_at_end(l0);
        if (t1) {
            l14 = true;
        } else {
            t0 = json_peek_byte(l0);
            t1 = std_char_is_digit(t0);
            l14 = !(t1);
        }
        if (l14) {
            l15 = 1458u;
            t2 = json_fail(l0, l15);
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        {
            loop_423: {
                t1 = json_at_end(l0);
                if (!(t1)) {
                    t0 = json_peek_byte(l0);
                    l16 = std_char_is_digit(t0);
                } else {
                    l16 = false;
                }
                if (l16) {
                    json_advance(l0);
                    goto loop_423;
                } else {
                }
            }
        }
        l17 = ((vader_struct_json_Parser_t*) l0)->f_bytes;
        l18 = ((vader_struct_json_Parser_t*) l0)->f_pos;
        vader_array_t* _a4_arr = vader_array_slice((vader_array_t*) l17, (size_t) l1, (size_t) l18);
        t2 = (void*) _a4_arr;
        t3 = vader_import_2(t2);
        l19 = std_string_parse_float(t3);
        if ((l19.tag == 158u || l19.tag == 159u)) {
            t4 = ((double) l19.payload.f);
            vader_struct_json_JsonNumber_t* _a5_obj = (vader_struct_json_JsonNumber_t*) vader_gc_alloc(sizeof(vader_struct_json_JsonNumber_t));
            vader_obj_header_init(_a5_obj, 276u);
            _a5_obj->f_value = t4;
            t2 = (void*) _a5_obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l19.tag == 383u) {
            l20 = 1704u;
            t2 = json_fail(l0, l20);
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_unreachable("unreachable return in json$parse_number");
    }
    l17 = ((vader_struct_json_Parser_t*) l0)->f_bytes;
    l18 = ((vader_struct_json_Parser_t*) l0)->f_pos;
    vader_array_t* _a6_arr = vader_array_slice((vader_array_t*) l17, (size_t) l1, (size_t) l18);
    t2 = (void*) _a6_arr;
    t3 = vader_import_2(t2);
    l19 = std_string_parse_float(t3);
    if ((l19.tag == 158u || l19.tag == 159u)) {
        t4 = ((double) l19.payload.f);
        vader_struct_json_JsonNumber_t* _a7_obj = (vader_struct_json_JsonNumber_t*) vader_gc_alloc(sizeof(vader_struct_json_JsonNumber_t));
        vader_obj_header_init(_a7_obj, 276u);
        _a7_obj->f_value = t4;
        t2 = (void*) _a7_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l19.tag == 383u) {
        l20 = 1704u;
        t2 = json_fail(l0, l20);
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_unreachable("unreachable return in json$parse_number");
    vader_gc_top = gc_frame.prev;
}

static vader_box_t json_parse_object(void* l0, int32_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    bool l5;
    vader_box_t l6 = vader_box_null(), l8 = vader_box_null(), l10 = vader_box_null();
    int32_t l7;
    vader_string_t l9;
    uint32_t l11;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    bool t2;
    uint32_t t3;
    vader_box_t* gc_roots[4] = { &l6, &l8, &l10, &t0 };
    void** gc_raw_roots[5] = { &l0, &l2, &l3, &l4, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = json_expect_byte(l0, 123u);
    if (t0.tag == 274u) {
        t0 = json_expect_byte(l0, 123u);
        t1 = t0.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 162u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(15u, 0u, 0u, 171u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 164u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 317u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l2 = (void*) _a3_obj;
    json_skip_ws(l0);
    t2 = json_at_end(l0);
    if (!(t2)) {
        t3 = json_peek_byte(l0);
        l5 = t3 == 125u;
    } else {
        l5 = false;
    }
    if (l5) {
        json_advance(l0);
        vader_struct_json_JsonObject_t* _a4_obj = (vader_struct_json_JsonObject_t*) vader_gc_alloc(sizeof(vader_struct_json_JsonObject_t));
        vader_obj_header_init(_a4_obj, 277u);
        _a4_obj->f_entries = l2;
        t1 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    {
        loop_49: {
            t2 = json_at_end(l0);
            if (!(t2)) {
                json_skip_ws(l0);
                l6 = json_parse_string(l0);
                if (l6.tag == 274u) {
                    t1 = l6.payload.obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                json_skip_ws(l0);
                t0 = json_expect_byte(l0, 58u);
                if (t0.tag == 274u) {
                    t0 = json_expect_byte(l0, 58u);
                    t1 = t0.payload.obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                l7 = (l1 + INT32_C(1));
                l8 = json_parse_value(l0, l7);
                if (l8.tag == 274u) {
                    t1 = l8.payload.obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                l9 = l6.payload.s;
                l10 = l8;
                std_collections_put__string__Any(l2, l9, l10);
                json_skip_ws(l0);
                t2 = json_at_end(l0);
                if (t2) {
                    t1 = json_fail(l0, 2274u);
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                l11 = json_peek_byte(l0);
                if (l11 == 44u) {
                    json_advance(l0);
                    goto loop_49;
                }
                if (l11 == 125u) {
                    json_advance(l0);
                    vader_struct_json_JsonObject_t* _a5_obj = (vader_struct_json_JsonObject_t*) vader_gc_alloc(sizeof(vader_struct_json_JsonObject_t));
                    vader_obj_header_init(_a5_obj, 277u);
                    _a5_obj->f_entries = l2;
                    t1 = (void*) _a5_obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                t1 = json_fail(l0, 1443u);
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            } else {
            }
        }
    }
    t1 = json_fail(l0, 2274u);
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t json_parse_string(void* l0) {
    size_t l1, l2, l3, l5;
    uint8_t l4;
    void* l6 = NULL;
    vader_string_t l7;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    int64_t t2;
    vader_string_t t3;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[3] = { &l0, &l6, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = json_expect_byte(l0, 34u);
    if (t0.tag == 274u) {
        t0 = json_expect_byte(l0, 34u);
        t1 = t0.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = ((vader_struct_json_Parser_t*) l0)->f_pos;
    l2 = ((vader_struct_json_Parser_t*) l0)->f_pos;
    {
        loop_18: {
            l3 = ((vader_struct_json_Parser_t*) l0)->f_eof;
            if ((l2 < l3)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_json_Parser_t*) l0)->f_bytes);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l2 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l2, 167u);
                l4 = ((uint8_t) t0.payload.i);
                if (l4 == INT32_C(34)) {
                    t2 = (l2 + INT64_C(1));
                    l5 = (size_t) (int64_t) t2;
                    ((vader_struct_json_Parser_t*) l0)->f_pos = l5;
                    VADER_WRITE_BARRIER((vader_struct_json_Parser_t*) l0);
                    vader_array_t* _a1_arr = vader_array_slice((vader_array_t*) ((vader_struct_json_Parser_t*) l0)->f_bytes, (size_t) l1, (size_t) l2);
                    t1 = (void*) _a1_arr;
                    t3 = vader_import_2(t1);
                    t0 = vader_box_string(162u, t3);
                    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
                }
                if (l4 == INT32_C(92)) {
                    vader_array_t* _a2_arr = vader_array_new(8u, 0u, 0u, 162u);
                    t1 = (void*) _a2_arr;
                    vader_struct_std_string_builder_StringBuilder_t* _a3_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
                    vader_obj_header_init(_a3_obj, 385u);
                    _a3_obj->f_parts = t1;
                    l6 = (void*) _a3_obj;
                    vader_array_t* _a4_arr = vader_array_slice((vader_array_t*) ((vader_struct_json_Parser_t*) l0)->f_bytes, (size_t) l1, (size_t) l2);
                    t1 = (void*) _a4_arr;
                    l7 = vader_import_2(t1);
                    std_string_builder_append(l6, l7);
                    ((vader_struct_json_Parser_t*) l0)->f_pos = l2;
                    VADER_WRITE_BARRIER((vader_struct_json_Parser_t*) l0);
                    t0 = json_parse_string_with_escapes(l0, l6);
                    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
                }
                t2 = (l2 + INT64_C(1));
                l2 = (size_t) (int64_t) t2;
                goto loop_18;
            } else {
            }
        }
    }
    t1 = json_fail(l0, 2275u);
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t json_parse_string_with_escapes(void* l0, void* l1) {
    uint32_t l2, l3, l4, l5;
    size_t l6, l7, l8;
    bool t0;
    vader_string_t t1;
    vader_box_t t2 = vader_box_null();
    void* t3 = NULL;
    int64_t t4;
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[3] = { &l0, &l1, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    {
        loop_1: {
            t0 = json_at_end(l0);
            if (!(t0)) {
                l2 = json_peek_byte(l0);
                if (l2 == 34u) {
                    json_advance(l0);
                    t1 = std_string_builder_StringBuilder_Display_to_string(l1);
                    t2 = vader_box_string(162u, t1);
                    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
                }
                if (l2 == 92u) {
                    json_advance(l0);
                    t0 = json_at_end(l0);
                    if (t0) {
                        t3 = json_fail(l0, 2273u);
                        { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
                    }
                    l3 = json_peek_byte(l0);
                    json_advance(l0);
                    if (l3 == 34u) {
                        std_string_builder_append_char(l1, 34u);
                        goto loop_1;
                    }
                    if (l3 == 92u) {
                        std_string_builder_append_char(l1, 92u);
                        goto loop_1;
                    }
                    if (l3 == 47u) {
                        std_string_builder_append_char(l1, 47u);
                        goto loop_1;
                    }
                    if (l3 == 110u) {
                        std_string_builder_append_char(l1, 10u);
                        goto loop_1;
                    }
                    if (l3 == 116u) {
                        std_string_builder_append_char(l1, 9u);
                        goto loop_1;
                    }
                    if (l3 == 114u) {
                        std_string_builder_append_char(l1, 13u);
                        goto loop_1;
                    }
                    if (l3 == 98u) {
                        l4 = ((uint32_t) (int32_t) INT32_C(8));
                        std_string_builder_append_char(l1, l4);
                        goto loop_1;
                    }
                    if (l3 == 102u) {
                        l5 = ((uint32_t) (int32_t) INT32_C(12));
                        std_string_builder_append_char(l1, l5);
                        goto loop_1;
                    }
                    if (l3 == 117u) {
                        t0 = json_decode_unicode_escape(l0, l1);
                        if (!(t0)) {
                            t3 = json_fail(l0, 1695u);
                            { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
                        }
                        goto loop_1;
                    }
                    t3 = json_fail(l0, 2257u);
                    { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
                }
                std_string_builder_append_char(l1, l2);
                l6 = ((vader_struct_json_Parser_t*) l0)->f_pos;
                l7 = std_string_codepoint_byte_len(l2);
                t4 = (l6 + l7);
                l8 = (size_t) (int64_t) t4;
                ((vader_struct_json_Parser_t*) l0)->f_pos = l8;
                VADER_WRITE_BARRIER((vader_struct_json_Parser_t*) l0);
                goto loop_1;
            } else {
            }
        }
    }
    t3 = json_fail(l0, 2275u);
    { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t json_parse_value(void* l0, int32_t l1) {
    uint32_t l2;
    vader_box_t l3 = vader_box_null();
    bool l4;
    void* t0 = NULL;
    bool t1;
    vader_string_t t2;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if ((l1 > INT32_C(200))) {
        t0 = json_fail(l0, 1790u);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    json_skip_ws(l0);
    t1 = json_at_end(l0);
    if (t1) {
        t0 = json_fail(l0, 2251u);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = json_peek_byte(l0);
    if (l2 == 34u) {
        l3 = json_parse_string(l0);
        if (l3.tag == 274u) {
            t0 = l3.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = l3.payload.s;
        vader_struct_json_JsonString_t* _a0_obj = (vader_struct_json_JsonString_t*) vader_gc_alloc(sizeof(vader_struct_json_JsonString_t));
        vader_obj_header_init(_a0_obj, 278u);
        _a0_obj->f_value = t2;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2 == 123u) {
        l3 = json_parse_object(l0, l1);
        if (l3.tag == 274u) {
            t0 = l3.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = l3.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2 == 91u) {
        l3 = json_parse_array(l0, l1);
        if (l3.tag == 274u) {
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
        if (l3.tag == 274u) {
            t0 = l3.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = l3.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2 == 110u) {
        l3 = json_parse_null(l0);
        if (l3.tag == 274u) {
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
    if (l4) {
        l3 = json_parse_number(l0);
        if (l3.tag == 274u) {
            t0 = l3.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = l3.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = json_fail(l0, 2250u);
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static uint32_t json_peek_byte(void* l0) {
    size_t l1, l2;
    void* l3;
    uint32_t t0;
    l1 = ((vader_struct_json_Parser_t*) l0)->f_pos;
    l2 = ((vader_struct_json_Parser_t*) l0)->f_eof;
    if ((l1 >= l2)) {
        return 0u;
    }
    l3 = ((vader_struct_json_Parser_t*) l0)->f_bytes;
    l1 = ((vader_struct_json_Parser_t*) l0)->f_pos;
    t0 = std_string_utf8_decode(l3, l1);
    return t0;
}

static int32_t json_read_hex4(void* l0) {
    size_t l1, l2;
    int32_t l3, l5;
    void* l4;
    size_t t0;
    int64_t t1;
    uint32_t t2;
    t0 = ((vader_struct_json_Parser_t*) l0)->f_pos;
    t1 = (t0 + INT64_C(4));
    l1 = (size_t) (int64_t) t1;
    l2 = ((vader_struct_json_Parser_t*) l0)->f_eof;
    if ((l1 > l2)) {
        return -(INT32_C(1));
    }
    l3 = INT32_C(0);
    l1 = (size_t) (int64_t) INT64_C(0);
    {
        loop_21: {
            if ((l1 < INT64_C(4))) {
                l4 = ((vader_struct_json_Parser_t*) l0)->f_bytes;
                t0 = ((vader_struct_json_Parser_t*) l0)->f_pos;
                t1 = (t0 + l1);
                l2 = (size_t) (int64_t) t1;
                t2 = std_string_utf8_decode(l4, l2);
                l5 = std_numbers_hex_digit_value(t2);
                if ((l5 < INT32_C(0))) {
                    return -(INT32_C(1));
                }
                l3 = ((l3 * INT32_C(16)) + l5);
                t1 = (l1 + INT64_C(1));
                l1 = (size_t) (int64_t) t1;
                goto loop_21;
            } else {
            }
        }
    }
    t0 = ((vader_struct_json_Parser_t*) l0)->f_pos;
    t1 = (t0 + INT64_C(4));
    l1 = (size_t) (int64_t) t1;
    ((vader_struct_json_Parser_t*) l0)->f_pos = l1;
    VADER_WRITE_BARRIER((vader_struct_json_Parser_t*) l0);
    return l3;
}

static void json_skip_ws(void* l0) {
    bool t0;
    uint32_t t1;
    {
        loop_1: {
            t0 = json_at_end(l0);
            if (!(t0)) {
                t1 = json_peek_byte(l0);
                t0 = std_char_is_white_char(t1);
                if (t0) {
                    json_advance(l0);
                    goto loop_1;
                }
                return;
            } else {
            }
        }
    }
    return;
}

