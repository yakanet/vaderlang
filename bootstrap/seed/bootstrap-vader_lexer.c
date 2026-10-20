#include "bootstrap.split.h"

static void vader_lexer_advance(void* l0, int64_t l1);
static bool vader_lexer_at_end(void* l0);
static void vader_lexer_consume_digits(void* l0, int32_t l1, void* l2);
static bool vader_lexer_continues_previous_line(uint8_t l0);
static void vader_lexer_emit(void* l0, void* l1);
static bool vader_lexer_emit_and_advance(void* l0, uint8_t l1, vader_string_t l2);
static void* vader_lexer_error_span(void* l0, void* l1);
static void* vader_lexer_first_malformed_utf8(void* l0);
static void vader_lexer_flush_string_part(void* l0, void* l1, void* l2, bool l3);
static void vader_lexer_handle_newline(void* l0);
static bool vader_lexer_in_interp_expression(void* l0);
static bool vader_lexer_is_ident_continue(uint32_t l0);
static bool vader_lexer_is_ident_start(uint32_t l0);
static bool vader_lexer_is_malformed_utf8(uint32_t l0, int64_t l1, uint8_t l2);
static void vader_lexer_lex_block_comment(void* l0);
static void vader_lexer_lex_char(void* l0);
static uint32_t vader_lexer_lex_escape(void* l0, bool l1);
static void vader_lexer_lex_ident(void* l0);
static void vader_lexer_lex_number(void* l0);
static void vader_lexer_lex_one(void* l0);
static void vader_lexer_lex_string(void* l0, bool l1);
static void vader_lexer_lex_string_body(void* l0, bool l1, bool l2);
static uint32_t vader_lexer_lex_unicode_escape(void* l0, void* l1);
static uint8_t vader_lexer_lookup_keyword(vader_string_t l0);
static vader_string_t vader_lexer_malformed_utf8_detail(int32_t l0);
static void* vader_lexer_new_lexer(vader_string_t l0, vader_string_t l1);
static uint32_t vader_lexer_peek(void* l0);
static uint32_t vader_lexer_peek_at(void* l0, int64_t l1);
static void vader_lexer_pop_interp(void* l0);
static void* vader_lexer_position_here(void* l0);
static void vader_lexer_push_error(void* l0, uint8_t l1, void* l2, vader_string_t l3);
static void vader_lexer_push_simple(void* l0, uint8_t l1, vader_string_t l2, void* l3);
static void vader_lexer_skip_bom(void* l0);
static void vader_lexer_skip_horizontal(void* l0);
static bool vader_lexer_suppresses_newline_after(uint8_t l0);
static vader_box_t vader_lexer_top_interp(void* l0);
static bool vader_lexer_try_lex_operator(void* l0);

static void vader_lexer_advance(void* l0, int64_t l1) {
    int64_t l2, l3, l4, l6, l9, l11, l12, l15, l17, l18, l22, l23;
    vader_string_t l5, l8;
    uint8_t l7;
    uint32_t l10;
    int32_t l13, l14, l16, l20, l21;
    bool l19;
    vader_string_t t0;
    uint32_t t1;
    int64_t t2;
    bool t3;
    int32_t t4;
    uint8_t t5;
    l2 = INT64_C(0);
    while ((l2 < l1)) {
        l3 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
        t0 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_src;
        l4 = vader_host_std_core_byte_len(t0);
        if ((l3 >= l4)) {
            return;
        }
        l5 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_src;
        l6 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
        l7 = vader_host_std_core_byte_at(l5, l6);
        if ((l7 >= INT32_C(128))) {
            l8 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_src;
            l9 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
            std_core_codepoint_at_byte(l8, l9, &t1, &t2);
            l23 = t2;
            l10 = t1;
            l11 = l23;
            t3 = vader_lexer_is_malformed_utf8(l10, l11, l7);
            if (t3) {
                t4 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_malformed_utf8_runs;
                if (t4 == INT32_C(0)) {
                    l12 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
                    ((vader_struct_vader_lexer_Lexer_t*) l0)->f_malformed_utf8_at = l12;
                }
                t4 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_malformed_utf8_runs;
                l13 = vader_chk_add(i32, t4, INT32_C(1));
                ((vader_struct_vader_lexer_Lexer_t*) l0)->f_malformed_utf8_runs = l13;
            }
            t4 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_col;
            l14 = vader_chk_add(i32, t4, INT32_C(1));
            ((vader_struct_vader_lexer_Lexer_t*) l0)->f_col = l14;
            t2 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
            l15 = vader_chk_add(i64, t2, l11);
            ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos = l15;
            l2 = (l2 + INT64_C(1));
            continue;
        }
        if (l7 == INT32_C(10)) {
            t4 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_line;
            l16 = vader_chk_add(i32, t4, INT32_C(1));
            ((vader_struct_vader_lexer_Lexer_t*) l0)->f_line = l16;
            ((vader_struct_vader_lexer_Lexer_t*) l0)->f_col = INT32_C(1);
        } else if (l7 == INT32_C(13)) {
            t2 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
            l17 = vader_chk_add(i64, t2, INT64_C(1));
            t0 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_src;
            l18 = vader_host_std_core_byte_len(t0);
            if ((l17 >= l18)) {
                l19 = true;
            } else {
                t0 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_src;
                t5 = vader_host_std_core_byte_at(t0, l17);
                l19 = t5 != INT32_C(10);
            }
            if (l19) {
                t4 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_line;
                l20 = vader_chk_add(i32, t4, INT32_C(1));
                ((vader_struct_vader_lexer_Lexer_t*) l0)->f_line = l20;
                ((vader_struct_vader_lexer_Lexer_t*) l0)->f_col = INT32_C(1);
            }
        } else {
            t4 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_col;
            l21 = vader_chk_add(i32, t4, INT32_C(1));
            ((vader_struct_vader_lexer_Lexer_t*) l0)->f_col = l21;
        }
        t2 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
        l22 = vader_chk_add(i64, t2, INT64_C(1));
        ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos = l22;
        l2 = (l2 + INT64_C(1));
    }
    return;
}

static bool vader_lexer_at_end(void* l0) {
    int64_t l1, l2;
    vader_string_t t0;
    l1 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
    t0 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_src;
    l2 = vader_host_std_core_byte_len(t0);
    return (l1 >= l2);
}

static void vader_lexer_consume_digits(void* l0, int32_t l1, void* l2) {
    bool l3, l4, l7;
    uint32_t l5, l6;
    void* l8 = NULL;
    bool t0;
    void** gc_raw_roots[3] = { &l0, &l2, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = false;
    l4 = true;
    for (;;) {
        t0 = vader_lexer_at_end(l0);
        if (!(t0)) {
            l5 = vader_lexer_peek(l0);
            if (l5 == 95u) {
                l6 = vader_lexer_peek_at(l0, INT64_C(1));
                if (l6 != 95u) {
                    t0 = vader_lexer_is_ident_start(l6);
                    if (t0) {
                        t0 = std_numbers_is_digit_in_base(l6, l1);
                        if (!(t0)) {
                            { vader_gc_top = gc_frame.prev; return; }
                        }
                    }
                }
                if (l4) {
                    l7 = true;
                } else {
                    l7 = l3;
                }
                if (l7) {
                    l8 = vader_lexer_error_span(l0, l2);
                    vader_lexer_push_error(l0, (uint8_t) 5, l8, 2584u);
                }
                l3 = true;
                l4 = false;
                vader_lexer_advance(l0, INT64_C(1));
                continue;
            }
            t0 = std_numbers_is_digit_in_base(l5, l1);
            if (!(t0)) {
                break;
            }
            l3 = false;
            l4 = false;
            vader_lexer_advance(l0, INT64_C(1));
            continue;
        }
        break;
    }
    if (l3) {
        l8 = vader_lexer_error_span(l0, l2);
        vader_lexer_push_error(l0, (uint8_t) 5, l8, 2584u);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_lexer_continues_previous_line(uint8_t l0) {
    bool l1;
    if (l0 == INT32_C(36)) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(38);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(39);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(40);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(46);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(61);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(50);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(51);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(56);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(57);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(52);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(53);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(48);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(54);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(55);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(49);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(58);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(59);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(44);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(45);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(41);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(42);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(43);
    }
    if (l1) {
        return true;
    }
    return false;
}

static void vader_lexer_emit(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    void* l4 = NULL;
    uint8_t l5;
    bool t0;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pending_newline;
    if (!(l2.tag == 0u)) {
        ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pending_newline = vader_box_obj(0u, NULL);
        VADER_WRITE_BARRIER((vader_struct_vader_lexer_Lexer_t*) l0);
        t0 = vader_lexer_continues_previous_line(((vader_struct_vader_lexer_Token_t*) l1)->f_kind);
        if (!(t0)) {
            l3 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_tokens;
            l4 = l2.payload.obj;
            l4 = vader_lexer_make_token((uint8_t) 1, 1u, l4);
            vader_array_push((vader_array_t*) l3, vader_ref_box(l4));
        }
    }
    vader_array_push((vader_array_t*) ((vader_struct_vader_lexer_Lexer_t*) l0)->f_tokens, vader_ref_box(l1));
    l5 = ((vader_struct_vader_lexer_Token_t*) l1)->f_kind;
    ((vader_struct_vader_lexer_Lexer_t*) l0)->f_last_kind = l5;
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_lexer_emit_and_advance(void* l0, uint8_t l1, vader_string_t l2) {
    void* l3 = NULL;
    int64_t l4;
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_lexer_position_here(l0);
    l4 = vader_host_std_core_byte_len(l2);
    vader_lexer_advance(l0, l4);
    vader_lexer_push_simple(l0, l1, l2, l3);
    { vader_gc_top = gc_frame.prev; return true; }
}

void* vader_lexer_empty_file_span(vader_string_t l0) {
    void* l1 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_toolchain_span_Position_t* _a0_obj = (vader_struct_toolchain_span_Position_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Position_t));
    vader_obj_header_init(_a0_obj, 621u);
    _a0_obj->f_file = l0;
    _a0_obj->f_offset = INT64_C(0);
    _a0_obj->f_line = INT32_C(1);
    _a0_obj->f_column = INT32_C(1);
    l1 = (void*) _a0_obj;
    vader_struct_toolchain_span_Span_t* _a1_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a1_obj, 622u);
    _a1_obj->f_start = l1;
    _a1_obj->f_end = l1;
    t0 = (void*) _a1_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_lexer_error_span(void* l0, void* l1) {
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_lexer_position_here(l0);
    vader_struct_toolchain_span_Span_t* _a0_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a0_obj, 622u);
    _a0_obj->f_start = l1;
    _a0_obj->f_end = l2;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_lexer_first_malformed_utf8(void* l0) {
    vader_string_t l1 = 0;
    vader_string_t l2 = 0;
    void* l3 = NULL;
    void* l6 = NULL;
    int64_t l4, l5;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l3, &l6, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_src;
    l2 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_file;
    l3 = vader_lexer_new_lexer(l1, l2);
    vader_lexer_skip_bom(l3);
    for (;;) {
        l4 = ((vader_struct_vader_lexer_Lexer_t*) l3)->f_pos;
        l5 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_malformed_utf8_at;
        if ((l4 < l5)) {
            vader_lexer_advance(l3, INT64_C(1));
            continue;
        }
        break;
    }
    l6 = vader_lexer_position_here(l3);
    vader_lexer_advance(l3, INT64_C(1));
    t0 = vader_lexer_error_span(l3, l6);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_lexer_flush_string_part(void* l0, void* l1, void* l2, bool l3) {
    vader_string_t l4 = 0;
    void* l5 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!(l3)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l4 = std_string_builder_StringBuilder_std_core_Display_to_string(l1);
    l5 = vader_lexer_position_here(l0);
    vader_struct_toolchain_span_Span_t* _a0_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a0_obj, 622u);
    _a0_obj->f_start = l2;
    _a0_obj->f_end = l5;
    l5 = (void*) _a0_obj;
    l5 = vader_lexer_make_token((uint8_t) 7, l4, l5);
    ((vader_struct_vader_lexer_Token_t*) l5)->f_value = vader_box_string(285u, l4);
    VADER_WRITE_BARRIER((vader_struct_vader_lexer_Token_t*) l5);
    vader_lexer_emit(l0, l5);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_lexer_handle_newline(void* l0) {
    void* l1 = NULL;
    uint32_t t0;
    int32_t t1;
    bool t2;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_lexer_peek(l0);
    if (t0 == 13u) {
        vader_lexer_advance(l0, INT64_C(1));
    }
    t0 = vader_lexer_peek(l0);
    if (t0 == 10u) {
        vader_lexer_advance(l0, INT64_C(1));
    }
    t1 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_paren_depth;
    if ((t1 > INT32_C(0))) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    t2 = vader_lexer_suppresses_newline_after(((vader_struct_vader_lexer_Lexer_t*) l0)->f_last_kind);
    if (t2) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (((vader_struct_vader_lexer_Lexer_t*) l0)->f_last_kind == INT32_C(1)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (((vader_struct_vader_lexer_Lexer_t*) l0)->f_pending_newline.tag == 0u) {
        l1 = vader_lexer_position_here(l0);
        vader_struct_toolchain_span_Span_t* _a0_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
        vader_obj_header_init(_a0_obj, 622u);
        _a0_obj->f_start = l1;
        _a0_obj->f_end = l1;
        l1 = (void*) _a0_obj;
        ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pending_newline = vader_ref_box(l1);
        VADER_WRITE_BARRIER((vader_struct_vader_lexer_Lexer_t*) l0);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_lexer_in_interp_expression(void* l0) {
    void* l1;
    vader_box_t l2;
    int32_t t0;
    l2 = vader_lexer_top_interp(l0);
    if (l2.tag == 0u) {
        return false;
    }
    l1 = l2.payload.obj;
    t0 = ((vader_struct_vader_lexer_InterpFrame_t*) l1)->f_brace_depth;
    return t0 == INT32_C(0);
}

static bool vader_lexer_is_ident_continue(uint32_t l0) {
    bool t0;
    t0 = std_char_is_alnum(l0);
    if (t0) {
        return true;
    }
    return l0 == 95u;
}

static bool vader_lexer_is_ident_start(uint32_t l0) {
    bool t0;
    t0 = std_char_is_alpha(l0);
    if (t0) {
        return true;
    }
    return l0 == 95u;
}

static bool vader_lexer_is_malformed_utf8(uint32_t l0, int64_t l1, uint8_t l2) {
    uint32_t l3;
    bool l4;
    l3 = ((uint32_t) 65533);
    if (l0 == l3) {
        if (l2 == INT32_C(239)) {
            l4 = l1 == INT64_C(3);
        } else {
            l4 = false;
        }
        return !(l4);
    }
    return false;
}

vader_string_t vader_lexer_kind_name(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(2)) {
        l1 = 1932u;
        return l1;
    }
    if (l0 == INT32_C(3)) {
        l1 = 1982u;
    } else if (l0 == INT32_C(4)) {
        l1 = 1815u;
    } else if (l0 == INT32_C(5)) {
        l1 = 1568u;
    } else if (l0 == INT32_C(6)) {
        l1 = 2433u;
    } else if (l0 == INT32_C(7)) {
        l1 = 2435u;
    } else if (l0 == INT32_C(8)) {
        l1 = 2434u;
    } else if (l0 == INT32_C(9)) {
        l1 = 1991u;
    } else if (l0 == INT32_C(10)) {
        l1 = 1990u;
    } else if (l0 == INT32_C(11)) {
        l1 = 2041u;
    } else if (l0 == INT32_C(12)) {
        l1 = 2052u;
    } else if (l0 == INT32_C(13)) {
        l1 = 2053u;
    } else if (l0 == INT32_C(14)) {
        l1 = 2044u;
    } else if (l0 == INT32_C(15)) {
        l1 = 2038u;
    } else if (l0 == INT32_C(16)) {
        l1 = 2043u;
    } else if (l0 == INT32_C(17)) {
        l1 = 2037u;
    } else if (l0 == INT32_C(18)) {
        l1 = 2048u;
    } else if (l0 == INT32_C(19)) {
        l1 = 2047u;
    } else if (l0 == INT32_C(20)) {
        l1 = 2042u;
    } else if (l0 == INT32_C(21)) {
        l1 = 2046u;
    } else if (l0 == INT32_C(22)) {
        l1 = 2050u;
    } else if (l0 == INT32_C(23)) {
        l1 = 2055u;
    } else if (l0 == INT32_C(24)) {
        l1 = 2032u;
    } else if (l0 == INT32_C(25)) {
        l1 = 2036u;
    } else if (l0 == INT32_C(26)) {
        l1 = 2033u;
    } else if (l0 == INT32_C(27)) {
        l1 = 2035u;
    } else if (l0 == INT32_C(28)) {
        l1 = 2045u;
    } else if (l0 == INT32_C(29)) {
        l1 = 2031u;
    } else if (l0 == INT32_C(30)) {
        l1 = 2039u;
    } else if (l0 == INT32_C(31)) {
        l1 = 2054u;
    } else if (l0 == INT32_C(32)) {
        l1 = 2040u;
    } else if (l0 == INT32_C(33)) {
        l1 = 2049u;
    } else if (l0 == INT32_C(34)) {
        l1 = 2051u;
    } else if (l0 == INT32_C(35)) {
        l1 = 2034u;
    } else if (l0 == INT32_C(36)) {
        l1 = 2257u;
    } else if (l0 == INT32_C(37)) {
        l1 = 2140u;
    } else if (l0 == INT32_C(38)) {
        l1 = 2361u;
    } else if (l0 == INT32_C(39)) {
        l1 = 2350u;
    } else if (l0 == INT32_C(40)) {
        l1 = 2252u;
    } else if (l0 == INT32_C(41)) {
        l1 = 2259u;
    } else if (l0 == INT32_C(42)) {
        l1 = 2142u;
    } else if (l0 == INT32_C(43)) {
        l1 = 2363u;
    } else if (l0 == INT32_C(44)) {
        l1 = 1357u;
    } else if (l0 == INT32_C(45)) {
        l1 = 2255u;
    } else if (l0 == INT32_C(46)) {
        l1 = 1556u;
    } else if (l0 == INT32_C(47)) {
        l1 = 2499u;
    } else if (l0 == INT32_C(48)) {
        l1 = 2336u;
    } else if (l0 == INT32_C(49)) {
        l1 = 2340u;
    } else if (l0 == INT32_C(50)) {
        l1 = 1698u;
    } else if (l0 == INT32_C(51)) {
        l1 = 2173u;
    } else if (l0 == INT32_C(56)) {
        l1 = 2321u;
    } else if (l0 == INT32_C(57)) {
        l1 = 2205u;
    } else if (l0 == INT32_C(52)) {
        l1 = 2092u;
    } else if (l0 == INT32_C(53)) {
        l1 = 2093u;
    } else if (l0 == INT32_C(54)) {
        l1 = 1874u;
    } else if (l0 == INT32_C(55)) {
        l1 = 1875u;
    } else if (l0 == INT32_C(58)) {
        l1 = 1380u;
    } else if (l0 == INT32_C(59)) {
        l1 = 2234u;
    } else if (l0 == INT32_C(61)) {
        l1 = 2270u;
    } else if (l0 == INT32_C(60)) {
        l1 = 1443u;
    } else if (l0 == INT32_C(62)) {
        l1 = 1427u;
    } else if (l0 == INT32_C(63)) {
        l1 = 2258u;
    } else if (l0 == INT32_C(64)) {
        l1 = 2141u;
    } else if (l0 == INT32_C(65)) {
        l1 = 2362u;
    } else if (l0 == INT32_C(66)) {
        l1 = 2351u;
    } else if (l0 == INT32_C(67)) {
        l1 = 2253u;
    } else if (l0 == INT32_C(68)) {
        l1 = 2260u;
    } else if (l0 == INT32_C(69)) {
        l1 = 2143u;
    } else if (l0 == INT32_C(70)) {
        l1 = 2364u;
    } else if (l0 == INT32_C(71)) {
        l1 = 1631u;
    } else if (l0 == INT32_C(72)) {
        l1 = 1632u;
    } else if (l0 == INT32_C(73)) {
        l1 = 2274u;
    } else if (l0 == INT32_C(74)) {
        l1 = 2275u;
    } else if (l0 == INT32_C(75)) {
        l1 = 1660u;
    } else if (l0 == INT32_C(76)) {
        l1 = 1424u;
    } else if (l0 == INT32_C(77)) {
        l1 = 1778u;
    } else if (l0 == INT32_C(78)) {
        l1 = 1433u;
    } else if (l0 == INT32_C(79)) {
        l1 = 1658u;
    } else if (l0 == INT32_C(80)) {
        l1 = 2091u;
    } else if (l0 == INT32_C(81)) {
        l1 = 2317u;
    } else if (l0 == INT32_C(82)) {
        l1 = 2060u;
    } else if (l0 == INT32_C(83)) {
        l1 = 2279u;
    } else if (l0 == INT32_C(84)) {
        l1 = 2059u;
    } else if (l0 == INT32_C(85)) {
        l1 = 2278u;
    } else if (l0 == INT32_C(86)) {
        l1 = 1583u;
    } else if (l0 == INT32_C(87)) {
        l1 = 1659u;
    } else if (l0 == INT32_C(88)) {
        l1 = 1582u;
    } else if (l0 == INT32_C(1)) {
        l1 = 2176u;
    } else {
        if (!(l0 == INT32_C(0))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 1697u;
    }
    return l1;
}

static void vader_lexer_lex_block_comment(void* l0) {
    void* l1 = NULL;
    int32_t l2;
    bool t0;
    uint32_t t1;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_lexer_position_here(l0);
    vader_lexer_advance(l0, INT64_C(2));
    l2 = INT32_C(1);
    for (;;) {
        t0 = vader_lexer_at_end(l0);
        if (!(t0)) {
            if (!((l2 > INT32_C(0)))) {
                break;
            }
            t1 = vader_lexer_peek(l0);
            if (t1 == 47u) {
                t1 = vader_lexer_peek_at(l0, INT64_C(1));
                if (t1 == 42u) {
                    vader_lexer_advance(l0, INT64_C(2));
                    l2 = vader_chk_add(i32, l2, INT32_C(1));
                    continue;
                }
            }
            t1 = vader_lexer_peek(l0);
            if (t1 == 42u) {
                t1 = vader_lexer_peek_at(l0, INT64_C(1));
                if (t1 == 47u) {
                    vader_lexer_advance(l0, INT64_C(2));
                    l2 = vader_chk_sub(i32, l2, INT32_C(1));
                    continue;
                }
            }
            vader_lexer_advance(l0, INT64_C(1));
            continue;
        }
        break;
    }
    if ((l2 > INT32_C(0))) {
        l1 = vader_lexer_error_span(l0, l1);
        vader_lexer_push_error(l0, (uint8_t) 2, l1, 0u);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_lexer_lex_char(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    vader_string_t l3 = 0;
    int64_t l4, l5;
    uint32_t l6;
    bool l7;
    uint32_t t0;
    int32_t t1;
    bool t2;
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_lexer_position_here(l0);
    vader_lexer_advance(l0, INT64_C(1));
    t0 = vader_lexer_peek(l0);
    if (t0 == 39u) {
        vader_lexer_advance(l0, INT64_C(1));
        l2 = vader_lexer_error_span(l0, l1);
        vader_lexer_push_error(l0, (uint8_t) 4, l2, 1570u);
        l3 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_src;
        l4 = ((vader_struct_toolchain_span_Position_t*) l1)->f_offset;
        l5 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
        l3 = vader_host_std_core_byte_slice(l3, l4, l5);
        l2 = vader_lexer_error_span(l0, l1);
        l2 = vader_lexer_make_token((uint8_t) 5, l3, l2);
        ((vader_struct_vader_lexer_Token_t*) l2)->f_value = vader_box_i32(292u, INT32_C(0));
        VADER_WRITE_BARRIER((vader_struct_vader_lexer_Token_t*) l2);
        vader_lexer_emit(l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l6 = (uint32_t) 0;
    t0 = vader_lexer_peek(l0);
    if (t0 == 92u) {
        l6 = vader_lexer_lex_escape(l0, true);
    } else {
        t0 = vader_lexer_peek(l0);
        if (t0 == 10u) {
            l7 = true;
        } else {
            l7 = vader_lexer_at_end(l0);
        }
        if (l7) {
            l2 = vader_lexer_error_span(l0, l1);
            vader_lexer_push_error(l0, (uint8_t) 4, l2, 2611u);
            l3 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_src;
            l4 = ((vader_struct_toolchain_span_Position_t*) l1)->f_offset;
            l5 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
            l3 = vader_host_std_core_byte_slice(l3, l4, l5);
            l2 = vader_lexer_error_span(l0, l1);
            l2 = vader_lexer_make_token((uint8_t) 5, l3, l2);
            ((vader_struct_vader_lexer_Token_t*) l2)->f_value = vader_box_i32(292u, INT32_C(0));
            VADER_WRITE_BARRIER((vader_struct_vader_lexer_Token_t*) l2);
            vader_lexer_emit(l0, l2);
            { vader_gc_top = gc_frame.prev; return; }
        }
        t0 = vader_lexer_peek(l0);
        t1 = ((int32_t) (uint32_t) t0);
        l6 = (uint32_t) (int32_t) t1;
        vader_lexer_advance(l0, INT64_C(1));
    }
    t0 = vader_lexer_peek(l0);
    if (t0 != 39u) {
        l2 = vader_lexer_error_span(l0, l1);
        vader_lexer_push_error(l0, (uint8_t) 4, l2, 1571u);
        for (;;) {
            t2 = vader_lexer_at_end(l0);
            if (!(t2)) {
                t0 = vader_lexer_peek(l0);
                if (!(t0 != 39u)) {
                    break;
                }
                t0 = vader_lexer_peek(l0);
                if (!(t0 != 10u)) {
                    break;
                }
                vader_lexer_advance(l0, INT64_C(1));
                continue;
            }
            break;
        }
        t0 = vader_lexer_peek(l0);
        if (t0 == 39u) {
            vader_lexer_advance(l0, INT64_C(1));
        }
    } else {
        vader_lexer_advance(l0, INT64_C(1));
    }
    l3 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_src;
    l4 = ((vader_struct_toolchain_span_Position_t*) l1)->f_offset;
    l5 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
    l3 = vader_host_std_core_byte_slice(l3, l4, l5);
    l1 = vader_lexer_error_span(l0, l1);
    l1 = vader_lexer_make_token((uint8_t) 5, l3, l1);
    ((vader_struct_vader_lexer_Token_t*) l1)->f_value = vader_box_i32(292u, (int32_t)(uint32_t) l6);
    VADER_WRITE_BARRIER((vader_struct_vader_lexer_Token_t*) l1);
    vader_lexer_emit(l0, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static uint32_t vader_lexer_lex_escape(void* l0, bool l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    uint32_t l4;
    bool l5;
    vader_string_t l6 = 0;
    bool t0;
    uint32_t t1;
    void** gc_raw_roots[3] = { &l0, &l2, &l3 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_lexer_position_here(l0);
    vader_lexer_advance(l0, INT64_C(1));
    t0 = vader_lexer_at_end(l0);
    if (t0) {
        l3 = vader_lexer_error_span(l0, l2);
        vader_lexer_push_error(l0, (uint8_t) 3, l3, 1963u);
        { vader_gc_top = gc_frame.prev; return (uint32_t) 0; }
    }
    l4 = vader_lexer_peek(l0);
    vader_lexer_advance(l0, INT64_C(1));
    if (l4 == 110u) {
        { vader_gc_top = gc_frame.prev; return (uint32_t) 10; }
    }
    if (l4 == 116u) {
        { vader_gc_top = gc_frame.prev; return (uint32_t) 9; }
    }
    if (l4 == 114u) {
        { vader_gc_top = gc_frame.prev; return (uint32_t) 13; }
    }
    if (l4 == 92u) {
        { vader_gc_top = gc_frame.prev; return (uint32_t) 92; }
    }
    if (l4 == 48u) {
        { vader_gc_top = gc_frame.prev; return (uint32_t) 0; }
    }
    if (l4 == 117u) {
        t1 = vader_lexer_lex_unicode_escape(l0, l2);
        { uint32_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1) {
        if (l4 == 39u) {
            { vader_gc_top = gc_frame.prev; return (uint32_t) 39; }
        }
        if (l4 == 34u) {
            l5 = true;
        } else {
            l5 = l4 == 36u;
        }
        if (l5) {
            l3 = vader_lexer_error_span(l0, l2);
            l6 = std_core_char_Display_to_string(l4);
            l6 = concat_3(1706u, l6, 116u);
            vader_lexer_push_error(l0, (uint8_t) 3, l3, l6);
            { uint32_t __vret = (uint32_t) (int32_t) ((int32_t) (uint32_t) l4); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else {
        if (l4 == 34u) {
            { vader_gc_top = gc_frame.prev; return (uint32_t) 34; }
        }
        if (l4 == 36u) {
            { vader_gc_top = gc_frame.prev; return (uint32_t) 36; }
        }
        if (l4 == 39u) {
            l3 = vader_lexer_error_span(l0, l2);
            vader_lexer_push_error(l0, (uint8_t) 3, l3, 1707u);
            { uint32_t __vret = (uint32_t) (int32_t) ((int32_t) (uint32_t) l4); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l2 = vader_lexer_error_span(l0, l2);
    l6 = std_core_char_Display_to_string(l4);
    l6 = concat_2(2595u, l6);
    vader_lexer_push_error(l0, (uint8_t) 3, l2, l6);
    { uint32_t __vret = (uint32_t) (int32_t) ((int32_t) (uint32_t) l4); vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_lexer_lex_ident(void* l0) {
    void* l1 = NULL;
    vader_string_t l2 = 0;
    int64_t l3, l4;
    uint8_t l5;
    bool t0;
    uint32_t t1;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_lexer_position_here(l0);
    for (;;) {
        t0 = vader_lexer_at_end(l0);
        if (!(t0)) {
            t1 = vader_lexer_peek(l0);
            t0 = vader_lexer_is_ident_continue(t1);
            if (!(t0)) {
                break;
            }
            vader_lexer_advance(l0, INT64_C(1));
            continue;
        }
        break;
    }
    l2 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_src;
    l3 = ((vader_struct_toolchain_span_Position_t*) l1)->f_offset;
    l4 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
    l2 = vader_host_std_core_byte_slice(l2, l3, l4);
    l5 = vader_lexer_lookup_keyword(l2);
    vader_lexer_push_simple(l0, l5, l2, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_lexer_lex_number(void* l0) {
    void* l1 = NULL;
    void* l7 = NULL;
    bool l2, l5;
    int32_t l3;
    uint32_t l4;
    int64_t l6, l9;
    vader_string_t l8 = 0;
    vader_string_t l10 = 0;
    uint8_t l11;
    vader_box_t l12 = vader_box_null();
    double l13;
    uint64_t l14;
    uint32_t t0;
    int64_t t1;
    bool t2;
    vader_box_t* gc_roots[1] = { &l12 };
    void** gc_raw_roots[3] = { &l0, &l1, &l7 };
    vader_string_t* gc_atom_roots[2] = { &l8, &l10 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_lexer_position_here(l0);
    l2 = false;
    l3 = INT32_C(10);
    t0 = vader_lexer_peek(l0);
    if (t0 == 48u) {
        l4 = vader_lexer_peek_at(l0, INT64_C(1));
        if (l4 == 120u) {
            l5 = true;
        } else {
            l5 = l4 == 88u;
        }
        if (l5) {
            l3 = INT32_C(16);
        } else {
            if (l4 == 98u) {
                l5 = true;
            } else {
                l5 = l4 == 66u;
            }
            if (l5) {
                l3 = INT32_C(2);
            } else {
                if (l4 == 111u) {
                    l5 = true;
                } else {
                    l5 = l4 == 79u;
                }
                if (l5) {
                    l3 = INT32_C(8);
                }
            }
        }
    }
    if (l3 != INT32_C(10)) {
        vader_lexer_advance(l0, INT64_C(2));
        l6 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
        vader_lexer_consume_digits(l0, l3, l1);
        t1 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
        if (t1 == l6) {
            l7 = vader_lexer_error_span(l0, l1);
            vader_lexer_push_error(l0, (uint8_t) 5, l7, 1733u);
        }
    } else {
        vader_lexer_consume_digits(l0, INT32_C(10), l1);
        t0 = vader_lexer_peek(l0);
        if (t0 == 46u) {
            t0 = vader_lexer_peek_at(l0, INT64_C(1));
            t2 = std_char_is_digit(t0);
            if (t2) {
                l2 = true;
                vader_lexer_advance(l0, INT64_C(1));
                vader_lexer_consume_digits(l0, INT32_C(10), l1);
            }
        }
        t0 = vader_lexer_peek(l0);
        if (t0 == 101u) {
            l5 = true;
        } else {
            t0 = vader_lexer_peek(l0);
            l5 = t0 == 69u;
        }
        if (l5) {
            l2 = true;
            vader_lexer_advance(l0, INT64_C(1));
            t0 = vader_lexer_peek(l0);
            if (t0 == 43u) {
                l5 = true;
            } else {
                t0 = vader_lexer_peek(l0);
                l5 = t0 == 45u;
            }
            if (l5) {
                vader_lexer_advance(l0, INT64_C(1));
            }
            t0 = vader_lexer_peek(l0);
            t2 = std_char_is_digit(t0);
            if (!(t2)) {
                l7 = vader_lexer_error_span(l0, l1);
                vader_lexer_push_error(l0, (uint8_t) 5, l7, 1739u);
            }
            vader_lexer_consume_digits(l0, INT32_C(10), l1);
        }
    }
    l8 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_src;
    l6 = ((vader_struct_toolchain_span_Position_t*) l1)->f_offset;
    l9 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
    l8 = vader_host_std_core_byte_slice(l8, l6, l9);
    t0 = vader_lexer_peek(l0);
    if (t0 == 95u) {
        t0 = vader_lexer_peek_at(l0, INT64_C(1));
        l5 = vader_lexer_is_ident_start(t0);
    } else {
        l5 = false;
    }
    if (l5) {
        l5 = true;
    } else {
        t0 = vader_lexer_peek(l0);
        l5 = vader_lexer_is_ident_start(t0);
    }
    if (l5) {
        t0 = vader_lexer_peek(l0);
        if (t0 == 95u) {
            vader_lexer_advance(l0, INT64_C(1));
        }
        l6 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
        for (;;) {
            t2 = vader_lexer_at_end(l0);
            if (!(t2)) {
                t0 = vader_lexer_peek(l0);
                t2 = vader_lexer_is_ident_continue(t0);
                if (!(t2)) {
                    break;
                }
                vader_lexer_advance(l0, INT64_C(1));
                continue;
            }
            break;
        }
        l10 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_src;
        l9 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
        l10 = vader_host_std_core_byte_slice(l10, l6, l9);
        l7 = vader_lexer_error_span(l0, l1);
        l10 = concat_3(2545u, l10, 1021u);
        vader_lexer_push_error(l0, (uint8_t) 5, l7, l10);
    }
    l7 = vader_lexer_position_here(l0);
    vader_struct_toolchain_span_Span_t* _a0_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a0_obj, 622u);
    _a0_obj->f_start = l1;
    _a0_obj->f_end = l7;
    l7 = (void*) _a0_obj;
    l11 = (uint8_t) 3;
    if (l2) {
        l11 = (uint8_t) 4;
    }
    l7 = vader_lexer_make_token(l11, l8, l7);
    l10 = std_numbers_strip_numeric_text(l8, l3);
    t2 = std_string_is_empty(l10);
    if (t2) {
        ((vader_struct_vader_lexer_Token_t*) l7)->f_value = vader_box_i64(293u, INT64_C(0));
        VADER_WRITE_BARRIER((vader_struct_vader_lexer_Token_t*) l7);
        vader_lexer_emit(l0, l7);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2) {
        l12 = std_string_parse_float(l10);
        if ((l12.tag == 294u || l12.tag == 295u)) {
            l13 = ((double) l12.payload.f);
        } else {
            if (!(l12.tag == 528u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            l13 = 0.0;
        }
        ((vader_struct_vader_lexer_Token_t*) l7)->f_value = vader_box_f64(295u, l13);
        VADER_WRITE_BARRIER((vader_struct_vader_lexer_Token_t*) l7);
    } else {
        l12 = std_numbers_parse_uint_in_base(l10, l3);
        if (l12.tag == 293u) {
            l14 = ((uint64_t) l12.payload.i);
            ((vader_struct_vader_lexer_Token_t*) l7)->f_value = vader_box_i64(293u, (int64_t)(uint64_t) l14);
            VADER_WRITE_BARRIER((vader_struct_vader_lexer_Token_t*) l7);
        } else {
            if (!(l12.tag == 528u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            l1 = vader_lexer_error_span(l0, l1);
            l8 = concat_3(910u, l8, 948u);
            vader_lexer_push_error(l0, (uint8_t) 10, l1, l8);
            ((vader_struct_vader_lexer_Token_t*) l7)->f_value = vader_box_i64(293u, INT64_C(0));
            VADER_WRITE_BARRIER((vader_struct_vader_lexer_Token_t*) l7);
        }
    }
    vader_lexer_emit(l0, l7);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_lexer_lex_one(void* l0) {
    vader_box_t l1 = vader_box_null();
    void* l2 = NULL;
    void* l5 = NULL;
    bool l3;
    uint32_t l4;
    vader_string_t l6 = 0;
    int64_t l7, l8;
    uint8_t l9;
    bool t0;
    uint32_t t1;
    void* t2 = NULL;
    int32_t t3;
    int64_t t4;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[4] = { &l0, &l2, &l5, &t2 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_lexer_skip_horizontal(l0);
    t0 = vader_lexer_at_end(l0);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l1 = vader_lexer_top_interp(l0);
    if (l1.tag == 945u) {
        t1 = vader_lexer_peek(l0);
        if (t1 == 125u) {
            t2 = l1.payload.obj;
            t3 = ((vader_struct_vader_lexer_InterpFrame_t*) t2)->f_brace_depth;
            if (t3 == INT32_C(0)) {
                l2 = vader_lexer_position_here(l0);
                vader_lexer_advance(l0, INT64_C(1));
                vader_lexer_push_simple(l0, (uint8_t) 10, 2825u, l2);
                t2 = l1.payload.obj;
                l3 = ((vader_struct_vader_lexer_InterpFrame_t*) t2)->f_triple;
                vader_lexer_pop_interp(l0);
                vader_lexer_lex_string_body(l0, l3, false);
                { vader_gc_top = gc_frame.prev; return; }
            }
        }
    } else if (!(l1.tag == 0u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    l4 = vader_lexer_peek(l0);
    if (l4 == 10u) {
        l3 = true;
    } else {
        l3 = l4 == 13u;
    }
    if (l3) {
        vader_lexer_handle_newline(l0);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l4 == 47u) {
        t1 = vader_lexer_peek_at(l0, INT64_C(1));
        if (t1 == 47u) {
            for (;;) {
                t0 = vader_lexer_at_end(l0);
                if (!(t0)) {
                    t1 = vader_lexer_peek(l0);
                    if (!(t1 != 10u)) {
                        break;
                    }
                    t1 = vader_lexer_peek(l0);
                    if (!(t1 != 13u)) {
                        break;
                    }
                    vader_lexer_advance(l0, INT64_C(1));
                    continue;
                }
                break;
            }
            { vader_gc_top = gc_frame.prev; return; }
        }
    }
    if (l4 == 47u) {
        t1 = vader_lexer_peek_at(l0, INT64_C(1));
        if (t1 == 42u) {
            vader_lexer_lex_block_comment(l0);
            { vader_gc_top = gc_frame.prev; return; }
        }
    }
    if (l4 == 114u) {
        t1 = vader_lexer_peek_at(l0, INT64_C(1));
        if (t1 == 34u) {
            vader_lexer_lex_string(l0, true);
            { vader_gc_top = gc_frame.prev; return; }
        }
    }
    t0 = vader_lexer_is_ident_start(l4);
    if (t0) {
        vader_lexer_lex_ident(l0);
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = std_char_is_digit(l4);
    if (t0) {
        vader_lexer_lex_number(l0);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l4 == 39u) {
        vader_lexer_lex_char(l0);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l4 == 34u) {
        vader_lexer_lex_string(l0, false);
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = vader_lexer_try_lex_operator(l0);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l2 = vader_lexer_position_here(l0);
    if (l4 == 35u) {
        t1 = vader_lexer_peek_at(l0, INT64_C(1));
        if (t1 == 33u) {
            for (;;) {
                t0 = vader_lexer_at_end(l0);
                if (!(t0)) {
                    t1 = vader_lexer_peek(l0);
                    if (!(t1 != 10u)) {
                        break;
                    }
                    t1 = vader_lexer_peek(l0);
                    if (!(t1 != 13u)) {
                        break;
                    }
                    vader_lexer_advance(l0, INT64_C(1));
                    continue;
                }
                break;
            }
            l5 = vader_lexer_error_span(l0, l2);
            vader_lexer_push_error(l0, (uint8_t) 7, l5, 0u);
            { vader_gc_top = gc_frame.prev; return; }
        }
    }
    if (l4 == 92u) {
        vader_lexer_advance(l0, INT64_C(1));
        l5 = vader_lexer_error_span(l0, l2);
        vader_lexer_push_error(l0, (uint8_t) 6, l5, 0u);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l6 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_src;
    l7 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
    std_core_codepoint_at_byte(l6, l7, &t1, &t4);
    l8 = t4;
    l7 = l8;
    l6 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_src;
    l8 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
    l9 = vader_host_std_core_byte_at(l6, l8);
    l3 = vader_lexer_is_malformed_utf8(l4, l7, l9);
    vader_lexer_advance(l0, INT64_C(1));
    if (l3) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l2 = vader_lexer_error_span(l0, l2);
    vader_lexer_push_error(l0, (uint8_t) 0, l2, 0u);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_lexer_lex_string(void* l0, bool l1) {
    void* l2 = NULL;
    void* l8 = NULL;
    bool l3, l4;
    vader_string_t l5 = 0;
    int64_t l6, l7;
    uint32_t t0;
    void** gc_raw_roots[3] = { &l0, &l2, &l8 };
    vader_string_t* gc_atom_roots[1] = { &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_lexer_position_here(l0);
    if (l1) {
        vader_lexer_advance(l0, INT64_C(1));
    }
    vader_lexer_advance(l0, INT64_C(1));
    l3 = false;
    t0 = vader_lexer_peek(l0);
    if (t0 == 34u) {
        t0 = vader_lexer_peek_at(l0, INT64_C(1));
        if (t0 == 34u) {
            l3 = true;
            vader_lexer_advance(l0, INT64_C(2));
            t0 = vader_lexer_peek(l0);
            if (t0 == 13u) {
                t0 = vader_lexer_peek_at(l0, INT64_C(1));
                l4 = t0 == 10u;
            } else {
                l4 = false;
            }
            if (l4) {
                vader_lexer_advance(l0, INT64_C(2));
            } else {
                t0 = vader_lexer_peek(l0);
                if (t0 == 10u) {
                    vader_lexer_advance(l0, INT64_C(1));
                }
            }
        }
    }
    l5 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_src;
    l6 = ((vader_struct_toolchain_span_Position_t*) l2)->f_offset;
    l7 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
    l5 = vader_host_std_core_byte_slice(l5, l6, l7);
    l8 = vader_lexer_position_here(l0);
    vader_struct_toolchain_span_Span_t* _a0_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a0_obj, 622u);
    _a0_obj->f_start = l2;
    _a0_obj->f_end = l8;
    l2 = (void*) _a0_obj;
    l2 = vader_lexer_make_token((uint8_t) 6, l5, l2);
    vader_lexer_emit(l0, l2);
    vader_lexer_lex_string_body(l0, l3, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_lexer_lex_string_body(void* l0, bool l1, bool l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l8 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    void* l19 = NULL;
    void* l20 = NULL;
    void* l21 = NULL;
    void* l22 = NULL;
    void* l23 = NULL;
    void* l24 = NULL;
    void* l25 = NULL;
    void* l26 = NULL;
    void* l27 = NULL;
    void* l28 = NULL;
    void* l29 = NULL;
    void* l30 = NULL;
    bool l5, l7, l32;
    uint32_t l6, l33;
    vader_string_t l9 = 0;
    uint32_t l31;
    void* t0 = NULL;
    bool t1;
    uint32_t t2;
    void** gc_raw_roots[26] = {
        &l0, &l3, &l4, &l8, &l10, &l11, &l12, &l13, &l14, &l15, &l16, &l17, &l18, &l19, &l20, &l21,
        &l22, &l23, &l24, &l25, &l26, &l27, &l28, &l29, &l30, &t0,
    };
    vader_string_t* gc_atom_roots[1] = { &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 26u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_lexer_position_here(l0);
    vader_array_t* _a0_arr = vader_array_new(14u, 0u, 0u, 285u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 529u);
    _a1_obj->f_parts = t0;
    l4 = (void*) _a1_obj;
    l5 = false;
    for (;;) {
        t1 = vader_lexer_at_end(l0);
        if (!(t1)) {
            l6 = vader_lexer_peek(l0);
            l7 = false;
            if (l1) {
                if (l6 == 34u) {
                    t2 = vader_lexer_peek_at(l0, INT64_C(1));
                    if (t2 == 34u) {
                        t2 = vader_lexer_peek_at(l0, INT64_C(2));
                        if (t2 == 34u) {
                            l7 = true;
                        }
                    }
                }
            } else if (l6 == 34u) {
                l7 = true;
            }
            if (l7) {
                vader_lexer_flush_string_part(l0, l4, l3, l5);
                l8 = vader_lexer_position_here(l0);
                l9 = 200u;
                if (l1) {
                    vader_lexer_advance(l0, INT64_C(3));
                    l9 = 203u;
                } else {
                    vader_lexer_advance(l0, INT64_C(1));
                }
                l10 = vader_lexer_position_here(l0);
                vader_struct_toolchain_span_Span_t* _a2_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
                vader_obj_header_init(_a2_obj, 622u);
                _a2_obj->f_start = l8;
                _a2_obj->f_end = l10;
                l11 = (void*) _a2_obj;
                l12 = vader_lexer_make_token((uint8_t) 8, l9, l11);
                vader_lexer_emit(l0, l12);
                { vader_gc_top = gc_frame.prev; return; }
            }
            if (!(l1)) {
                if (l6 == 10u) {
                    l13 = vader_lexer_position_here(l0);
                    vader_struct_toolchain_span_Span_t* _a3_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
                    vader_obj_header_init(_a3_obj, 622u);
                    _a3_obj->f_start = l3;
                    _a3_obj->f_end = l13;
                    l14 = (void*) _a3_obj;
                    vader_lexer_push_error(l0, (uint8_t) 1, l14, 0u);
                    vader_lexer_flush_string_part(l0, l4, l3, l5);
                    l15 = vader_lexer_position_here(l0);
                    vader_struct_toolchain_span_Span_t* _a4_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
                    vader_obj_header_init(_a4_obj, 622u);
                    _a4_obj->f_start = l15;
                    _a4_obj->f_end = l15;
                    l16 = (void*) _a4_obj;
                    l17 = vader_lexer_make_token((uint8_t) 8, 0u, l16);
                    vader_lexer_emit(l0, l17);
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            if (!(l2)) {
                if (l6 == 36u) {
                    t2 = vader_lexer_peek_at(l0, INT64_C(1));
                    if (t2 == 123u) {
                        vader_lexer_flush_string_part(l0, l4, l3, l5);
                        l18 = vader_lexer_position_here(l0);
                        vader_lexer_advance(l0, INT64_C(2));
                        l19 = vader_lexer_position_here(l0);
                        vader_struct_toolchain_span_Span_t* _a5_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
                        vader_obj_header_init(_a5_obj, 622u);
                        _a5_obj->f_start = l18;
                        _a5_obj->f_end = l19;
                        l20 = (void*) _a5_obj;
                        l21 = vader_lexer_make_token((uint8_t) 9, 228u, l20);
                        vader_lexer_emit(l0, l21);
                        l22 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_interp_stack;
                        vader_struct_vader_lexer_InterpFrame_t* _a6_obj = (vader_struct_vader_lexer_InterpFrame_t*) vader_gc_alloc(sizeof(vader_struct_vader_lexer_InterpFrame_t));
                        vader_obj_header_init(_a6_obj, 945u);
                        _a6_obj->f_brace_depth = INT32_C(0);
                        _a6_obj->f_triple = l1;
                        l23 = (void*) _a6_obj;
                        vader_array_push((vader_array_t*) l22, vader_ref_box(l23));
                        { vader_gc_top = gc_frame.prev; return; }
                    }
                }
            }
            if (!(l2)) {
                if (l6 == 36u) {
                    t2 = vader_lexer_peek_at(l0, INT64_C(1));
                    t1 = vader_lexer_is_ident_start(t2);
                    if (t1) {
                        vader_lexer_flush_string_part(l0, l4, l3, l5);
                        l24 = vader_lexer_position_here(l0);
                        vader_lexer_advance(l0, INT64_C(1));
                        l25 = vader_lexer_position_here(l0);
                        vader_struct_toolchain_span_Span_t* _a7_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
                        vader_obj_header_init(_a7_obj, 622u);
                        _a7_obj->f_start = l24;
                        _a7_obj->f_end = l25;
                        l26 = (void*) _a7_obj;
                        l27 = vader_lexer_make_token((uint8_t) 9, 210u, l26);
                        vader_lexer_emit(l0, l27);
                        vader_lexer_lex_ident(l0);
                        l28 = vader_lexer_position_here(l0);
                        vader_struct_toolchain_span_Span_t* _a8_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
                        vader_obj_header_init(_a8_obj, 622u);
                        _a8_obj->f_start = l28;
                        _a8_obj->f_end = l28;
                        l29 = (void*) _a8_obj;
                        l30 = vader_lexer_make_token((uint8_t) 10, 0u, l29);
                        vader_lexer_emit(l0, l30);
                        l3 = vader_lexer_position_here(l0);
                        vader_array_t* _a9_arr = vader_array_new(14u, 0u, 0u, 285u);
                        t0 = (void*) _a9_arr;
                        vader_struct_std_string_builder_StringBuilder_t* _a10_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
                        vader_obj_header_init(_a10_obj, 529u);
                        _a10_obj->f_parts = t0;
                        l4 = (void*) _a10_obj;
                        l5 = false;
                        continue;
                    }
                }
            }
            if (!(l2)) {
                if (l6 == 92u) {
                    l31 = vader_lexer_lex_escape(l0, false);
                    if ((l31 > INT32_C(55295))) {
                        if ((l31 < INT32_C(57344))) {
                            l32 = true;
                        } else {
                            l32 = (l31 > INT32_C(1114111));
                        }
                        if (l32) {
                            vader_unreachable("value out of range: no Unicode scalar value");
                        }
                    }
                    l33 = ((uint32_t) (uint32_t) l31);
                    std_string_builder_append_char(l4, l33);
                    l5 = true;
                    continue;
                }
            }
            std_string_builder_append_char(l4, l6);
            l5 = true;
            vader_lexer_advance(l0, INT64_C(1));
            continue;
        }
        break;
    }
    l8 = vader_lexer_position_here(l0);
    vader_struct_toolchain_span_Span_t* _a11_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a11_obj, 622u);
    _a11_obj->f_start = l3;
    _a11_obj->f_end = l8;
    l8 = (void*) _a11_obj;
    vader_lexer_push_error(l0, (uint8_t) 1, l8, 0u);
    vader_lexer_flush_string_part(l0, l4, l3, l5);
    l3 = vader_lexer_position_here(l0);
    vader_struct_toolchain_span_Span_t* _a12_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a12_obj, 622u);
    _a12_obj->f_start = l3;
    _a12_obj->f_end = l3;
    l3 = (void*) _a12_obj;
    l3 = vader_lexer_make_token((uint8_t) 8, 0u, l3);
    vader_lexer_emit(l0, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static uint32_t vader_lexer_lex_unicode_escape(void* l0, void* l1) {
    void* l2 = NULL;
    int64_t l3, l4, l7, l9;
    bool l5;
    uint32_t l6, l11, l12;
    vader_string_t l8 = 0;
    int32_t l10;
    uint32_t t0;
    bool t1;
    int32_t t2;
    int64_t t3;
    uint8_t t4;
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_string_t* gc_atom_roots[1] = { &l8 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_lexer_peek(l0);
    if (t0 != 123u) {
        l2 = vader_lexer_error_span(l0, l1);
        vader_lexer_push_error(l0, (uint8_t) 8, l2, 1714u);
        { vader_gc_top = gc_frame.prev; return (uint32_t) 0; }
    }
    vader_lexer_advance(l0, INT64_C(1));
    l3 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
    for (;;) {
        t1 = vader_lexer_at_end(l0);
        if (!(t1)) {
            t0 = vader_lexer_peek(l0);
            if (!(t0 != 125u)) {
                break;
            }
            t0 = vader_lexer_peek(l0);
            t2 = std_numbers_hex_digit_value(t0);
            if ((t2 < INT32_C(0))) {
                l2 = vader_lexer_error_span(l0, l1);
                vader_lexer_push_error(l0, (uint8_t) 8, l2, 2011u);
                for (;;) {
                    t1 = vader_lexer_at_end(l0);
                    if (!(t1)) {
                        t0 = vader_lexer_peek(l0);
                        if (!(t0 != 125u)) {
                            break;
                        }
                        t0 = vader_lexer_peek(l0);
                        if (!(t0 != 10u)) {
                            break;
                        }
                        vader_lexer_advance(l0, INT64_C(1));
                        continue;
                    }
                    break;
                }
                t0 = vader_lexer_peek(l0);
                if (t0 == 125u) {
                    vader_lexer_advance(l0, INT64_C(1));
                    { vader_gc_top = gc_frame.prev; return (uint32_t) 0; }
                }
                { vader_gc_top = gc_frame.prev; return (uint32_t) 0; }
            }
            vader_lexer_advance(l0, INT64_C(1));
            continue;
        }
        break;
    }
    t3 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
    l4 = vader_chk_sub(i64, t3, l3);
    t0 = vader_lexer_peek(l0);
    if (t0 == 125u) {
        vader_lexer_advance(l0, INT64_C(1));
    }
    if (l4 == INT64_C(0)) {
        l5 = true;
    } else {
        l5 = (l4 > INT64_C(6));
    }
    if (l5) {
        l2 = vader_lexer_error_span(l0, l1);
        vader_lexer_push_error(l0, (uint8_t) 8, l2, 1579u);
        { vader_gc_top = gc_frame.prev; return (uint32_t) 0; }
    }
    l6 = (uint32_t) 0;
    l7 = INT64_C(0);
    while ((l7 < l4)) {
        l8 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_src;
        l9 = vader_chk_add(i64, l3, l7);
        t4 = vader_host_std_core_byte_at(l8, l9);
        l10 = std_numbers_hex_digit_value(((uint32_t) (uint8_t) t4));
        t2 = vader_chk_mul(u32, l6, INT32_C(16));
        l11 = (uint32_t) (int32_t) t2;
        t2 = l10;
        l12 = (uint32_t) (int32_t) t2;
        t2 = vader_chk_add(u32, l11, l12);
        l6 = (uint32_t) (int32_t) t2;
        l7 = (l7 + INT64_C(1));
    }
    t2 = ((int32_t) (uint32_t) ((uint32_t) 1114111));
    l11 = (uint32_t) (int32_t) t2;
    if ((l6 > l11)) {
        l2 = vader_lexer_error_span(l0, l1);
        vader_lexer_push_error(l0, (uint8_t) 8, l2, 1580u);
        { vader_gc_top = gc_frame.prev; return (uint32_t) 0; }
    }
    t1 = std_string_is_surrogate(l6);
    if (!(t1)) {
        { uint32_t __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = vader_lexer_error_span(l0, l1);
    vader_lexer_push_error(l0, (uint8_t) 8, l2, 1581u);
    { vader_gc_top = gc_frame.prev; return (uint32_t) 0; }
}

static uint8_t vader_lexer_lookup_keyword(vader_string_t l0) {
    if (l0 == 1816u) {
        return (uint8_t) 11;
    }
    if (l0 == 2437u) {
        return (uint8_t) 12;
    }
    if (l0 == 2508u) {
        return (uint8_t) 13;
    }
    if (l0 == 1943u) {
        return (uint8_t) 14;
    }
    if (l0 == 1689u) {
        return (uint8_t) 15;
    }
    if (l0 == 1935u) {
        return (uint8_t) 16;
    }
    if (l0 == 1675u) {
        return (uint8_t) 17;
    }
    if (l0 == 2102u) {
        return (uint8_t) 18;
    }
    if (l0 == 2014u) {
        return (uint8_t) 19;
    }
    if (l0 == 1825u) {
        return (uint8_t) 20;
    }
    if (l0 == 1955u) {
        return (uint8_t) 21;
    }
    if (l0 == 2308u) {
        return (uint8_t) 22;
    }
    if (l0 == 2811u) {
        return (uint8_t) 23;
    }
    if (l0 == 1437u) {
        return (uint8_t) 24;
    }
    if (l0 == 1641u) {
        return (uint8_t) 25;
    }
    if (l0 == 1473u) {
        return (uint8_t) 26;
    }
    if (l0 == 1615u) {
        return (uint8_t) 27;
    }
    if (l0 == 1945u) {
        return (uint8_t) 28;
    }
    if (l0 == 1425u) {
        return (uint8_t) 29;
    }
    if (l0 == 1740u) {
        return (uint8_t) 30;
    }
    if (l0 == 2514u) {
        return (uint8_t) 31;
    }
    if (l0 == 1777u) {
        return (uint8_t) 32;
    }
    if (l0 == 2207u) {
        return (uint8_t) 33;
    }
    if (l0 == 2327u) {
        return (uint8_t) 34;
    }
    if (!(l0 == 1607u)) {
        return (uint8_t) 2;
    }
    return (uint8_t) 35;
}

void* vader_lexer_make_token(uint8_t l0, vader_string_t l1, void* l2) {
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_vader_lexer_Token_t* _a0_obj = (vader_struct_vader_lexer_Token_t*) vader_gc_alloc(sizeof(vader_struct_vader_lexer_Token_t));
    vader_obj_header_init(_a0_obj, 947u);
    _a0_obj->f_kind = l0;
    _a0_obj->f_text = l1;
    _a0_obj->f_span = l2;
    _a0_obj->f_value = vader_box_obj(0u, NULL);
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_lexer_malformed_utf8_detail(int32_t l0) {
    void* l1 = NULL;
    int64_t l2, l3;
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l1 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!(l0 == INT32_C(1))) {
        l1 = (void*) vader_buffer_new((size_t) INT64_C(60));
        l2 = INT64_C(0);
        l2 = std_core_write_string_at(l1, l2, 2485u);
        l3 = ((int64_t) (int32_t) l0);
        l2 = std_core_write_int(l1, l2, l3);
        l2 = std_core_write_string_at(l1, l2, 122u);
        t0 = std_core_finish_buffer(l1, l2);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return 0u; }
}

static void* vader_lexer_new_lexer(vader_string_t l0, vader_string_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[5] = { &l2, &l3, &l4, &l5, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 288u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(105u, 0u, 13u, 947u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(84u, 0u, 13u, 906u);
    l4 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(104u, 0u, 13u, 945u);
    l5 = (void*) _a3_arr;
    vader_struct_vader_lexer_Lexer_t* _a4_obj = (vader_struct_vader_lexer_Lexer_t*) vader_gc_alloc(sizeof(vader_struct_vader_lexer_Lexer_t));
    vader_obj_header_init(_a4_obj, 946u);
    _a4_obj->f_src = l0;
    _a4_obj->f_file = l1;
    _a4_obj->f_pos = INT64_C(0);
    _a4_obj->f_line = INT32_C(1);
    _a4_obj->f_col = INT32_C(1);
    _a4_obj->f_paren_depth = INT32_C(0);
    _a4_obj->f_enclosing_paren_depths = l2;
    _a4_obj->f_last_kind = (uint8_t) 1;
    _a4_obj->f_pending_newline = vader_box_obj(0u, NULL);
    _a4_obj->f_malformed_utf8_runs = INT32_C(0);
    _a4_obj->f_malformed_utf8_at = INT64_C(0);
    _a4_obj->f_tokens = l3;
    _a4_obj->f_errors = l4;
    _a4_obj->f_interp_stack = l5;
    t0 = (void*) _a4_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static uint32_t vader_lexer_peek(void* l0) {
    int64_t l1, l2;
    vader_string_t l3;
    uint8_t l4;
    vader_string_t t0;
    uint32_t t1;
    int64_t t2;
    l1 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
    t0 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_src;
    l2 = vader_host_std_core_byte_len(t0);
    if ((l1 >= l2)) {
        return 0u;
    }
    l3 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_src;
    l1 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
    l4 = vader_host_std_core_byte_at(l3, l1);
    if (!((l4 < INT32_C(128)))) {
        l3 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_src;
        l1 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
        std_core_codepoint_at_byte(l3, l1, &t1, &t2);
        return t1;
    }
    return ((uint32_t) (uint8_t) l4);
}

static uint32_t vader_lexer_peek_at(void* l0, int64_t l1) {
    int64_t l2, l3;
    uint8_t l4;
    int64_t t0;
    vader_string_t t1;
    uint32_t t2;
    t0 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
    l2 = vader_chk_add(i64, t0, l1);
    t1 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_src;
    l3 = vader_host_std_core_byte_len(t1);
    if ((l2 >= l3)) {
        return 0u;
    }
    t1 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_src;
    l4 = vader_host_std_core_byte_at(t1, l2);
    if (!((l4 < INT32_C(128)))) {
        t1 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_src;
        std_core_codepoint_at_byte(t1, l2, &t2, &t0);
        return t2;
    }
    return ((uint32_t) (uint8_t) l4);
}

static void vader_lexer_pop_interp(void* l0) {
    int64_t l1;
    void* l2 = NULL;
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_array_t*) ((vader_struct_vader_lexer_Lexer_t*) l0)->f_interp_stack)->length;
    if (!(l1 == INT64_C(0))) {
        l2 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_interp_stack;
        l1 = vader_chk_sub(i64, l1, INT64_C(1));
        vader_array_t* _a0_arr = vader_array_slice((vader_array_t*) l2, (int64_t) INT64_C(0), (int64_t) l1);
        l2 = (void*) _a0_arr;
        ((vader_struct_vader_lexer_Lexer_t*) l0)->f_interp_stack = l2;
        VADER_WRITE_BARRIER((vader_struct_vader_lexer_Lexer_t*) l0);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_lexer_position_here(void* l0) {
    vader_string_t l1 = 0;
    int64_t l2;
    int32_t l3, l4;
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_file;
    l2 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
    l3 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_line;
    l4 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_col;
    vader_struct_toolchain_span_Position_t* _a0_obj = (vader_struct_toolchain_span_Position_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Position_t));
    vader_obj_header_init(_a0_obj, 621u);
    _a0_obj->f_file = l1;
    _a0_obj->f_offset = l2;
    _a0_obj->f_line = l3;
    _a0_obj->f_column = l4;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_lexer_push_error(void* l0, uint8_t l1, void* l2, vader_string_t l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    void** gc_raw_roots[4] = { &l0, &l2, &l4, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_errors;
    l5 = vader_diagnostics_lexer_error(l1, l2, l3);
    vader_array_push((vader_array_t*) l4, vader_ref_box(l5));
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_lexer_push_simple(void* l0, uint8_t l1, vader_string_t l2, void* l3) {
    void* l4 = NULL;
    void** gc_raw_roots[3] = { &l0, &l3, &l4 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = vader_lexer_position_here(l0);
    vader_struct_toolchain_span_Span_t* _a0_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a0_obj, 622u);
    _a0_obj->f_start = l3;
    _a0_obj->f_end = l4;
    l4 = (void*) _a0_obj;
    l4 = vader_lexer_make_token(l1, l2, l4);
    vader_lexer_emit(l0, l4);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_lexer_skip_bom(void* l0) {
    uint32_t t0;
    t0 = vader_lexer_peek(l0);
    if (t0 == 65279u) {
        ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos = INT64_C(3);
        return;
    }
    return;
}

static void vader_lexer_skip_horizontal(void* l0) {
    bool l1, l3, l4, l5;
    uint32_t l2;
    bool t0;
    l1 = vader_lexer_in_interp_expression(l0);
    for (;;) {
        t0 = vader_lexer_at_end(l0);
        if (!(t0)) {
            l2 = vader_lexer_peek(l0);
            if (l2 == 32u) {
                l3 = true;
            } else {
                l3 = l2 == 9u;
            }
            if (l3) {
                vader_lexer_advance(l0, INT64_C(1));
                continue;
            }
            if (l1) {
                if (l2 == 10u) {
                    l5 = true;
                } else {
                    l5 = l2 == 13u;
                }
                l4 = l5;
            } else {
                l4 = false;
            }
            if (!(l4)) {
                return;
            }
            vader_lexer_advance(l0, INT64_C(1));
            continue;
        }
        break;
    }
    return;
}

static bool vader_lexer_suppresses_newline_after(uint8_t l0) {
    bool l1;
    if (l0 == INT32_C(36)) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(37);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(38);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(39);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(40);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(41);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(42);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(43);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(44);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(45);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(46);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(48);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(49);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(50);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(51);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(56);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(57);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(52);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(53);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(54);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(55);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(58);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(59);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(61);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(73);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(74);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(75);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(62);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(63);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(64);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(65);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(66);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(67);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(68);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(69);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(70);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(88);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(76);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(77);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(86);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(71);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(72);
    }
    if (l1) {
        return true;
    }
    return false;
}

void* vader_lexer_tokenize(vader_string_t l0, vader_string_t l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    vader_string_t l3 = 0;
    int32_t t0;
    uint32_t t1;
    bool t2;
    void** gc_raw_roots[2] = { &l2, &l4 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l1, &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_lexer_new_lexer(l0, l1);
    vader_lexer_skip_bom(l2);
    t0 = ((vader_struct_vader_lexer_Lexer_t*) l2)->f_line;
    if (t0 == INT32_C(1)) {
        t1 = vader_lexer_peek(l2);
        if (t1 == 35u) {
            t1 = vader_lexer_peek_at(l2, INT64_C(1));
            if (t1 == 33u) {
                for (;;) {
                    t2 = vader_lexer_at_end(l2);
                    if (!(t2)) {
                        t1 = vader_lexer_peek(l2);
                        if (!(t1 != 10u)) {
                            break;
                        }
                        vader_lexer_advance(l2, INT64_C(1));
                        continue;
                    }
                    break;
                }
            }
        }
    }
    for (;;) {
        t2 = vader_lexer_at_end(l2);
        if (!(t2)) {
            vader_lexer_lex_one(l2);
            continue;
        }
        break;
    }
    t0 = ((vader_struct_vader_lexer_Lexer_t*) l2)->f_malformed_utf8_runs;
    if ((t0 > INT32_C(0))) {
        t0 = ((vader_struct_vader_lexer_Lexer_t*) l2)->f_malformed_utf8_runs;
        l3 = vader_lexer_malformed_utf8_detail(t0);
        l4 = vader_lexer_first_malformed_utf8(l2);
        vader_lexer_push_error(l2, (uint8_t) 11, l4, l3);
    }
    l4 = vader_lexer_position_here(l2);
    vader_struct_toolchain_span_Span_t* _a0_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a0_obj, 622u);
    _a0_obj->f_start = l4;
    _a0_obj->f_end = l4;
    l4 = (void*) _a0_obj;
    l4 = vader_lexer_make_token((uint8_t) 0, 0u, l4);
    vader_lexer_emit(l2, l4);
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_lexer_top_interp(void* l0) {
    int64_t l1;
    void* l2;
    void* t0;
    l1 = ((vader_array_t*) ((vader_struct_vader_lexer_Lexer_t*) l0)->f_interp_stack)->length;
    if (!(l1 == INT64_C(0))) {
        l2 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_interp_stack;
        l1 = vader_chk_sub(i64, l1, INT64_C(1));
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
        return vader_ref_box(t0);
    }
    return vader_box_obj(0u, NULL);
}

static bool vader_lexer_try_lex_operator(void* l0) {
    uint32_t l1, l2, l3;
    void* l4 = NULL;
    int32_t l5;
    vader_box_t l6 = vader_box_null();
    bool t0;
    uint32_t t1;
    int32_t t2;
    void* t3 = NULL;
    vader_box_t* gc_roots[1] = { &l6 };
    void** gc_raw_roots[3] = { &l0, &l4, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_lexer_peek(l0);
    l2 = vader_lexer_peek_at(l0, INT64_C(1));
    if (l1 == 46u) {
        if (l2 == 46u) {
            l3 = vader_lexer_peek_at(l0, INT64_C(2));
            if (l3 == 60u) {
                t0 = vader_lexer_emit_and_advance(l0, (uint8_t) 73, 338u);
                { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l3 == 61u) {
                t0 = vader_lexer_emit_and_advance(l0, (uint8_t) 74, 339u);
                { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l3 == 46u) {
                t0 = vader_lexer_emit_and_advance(l0, (uint8_t) 75, 336u);
                { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
    }
    if (l2 == 61u) {
        t1 = vader_lexer_peek_at(l0, INT64_C(2));
        if (t1 == 61u) {
            if (l1 == 61u) {
                t0 = vader_lexer_emit_and_advance(l0, (uint8_t) 56, 452u);
                { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l1 == 33u) {
                t0 = vader_lexer_emit_and_advance(l0, (uint8_t) 57, 198u);
                { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
    }
    if (l2 == 37u) {
        t1 = vader_lexer_peek_at(l0, INT64_C(2));
        if (t1 == 61u) {
            if (l1 == 43u) {
                t0 = vader_lexer_emit_and_advance(l0, (uint8_t) 68, 299u);
                { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l1 == 45u) {
                t0 = vader_lexer_emit_and_advance(l0, (uint8_t) 69, 322u);
                { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l1 == 42u) {
                t0 = vader_lexer_emit_and_advance(l0, (uint8_t) 70, 295u);
                { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
        if (l1 == 43u) {
            t0 = vader_lexer_emit_and_advance(l0, (uint8_t) 41, 298u);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l1 == 45u) {
            t0 = vader_lexer_emit_and_advance(l0, (uint8_t) 42, 321u);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l1 == 42u) {
            t0 = vader_lexer_emit_and_advance(l0, (uint8_t) 43, 294u);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (l1 == 61u) {
        if (l2 == 61u) {
            t0 = vader_lexer_emit_and_advance(l0, (uint8_t) 50, 451u);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (l1 == 33u) {
        if (l2 == 61u) {
            t0 = vader_lexer_emit_and_advance(l0, (uint8_t) 51, 197u);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (l1 == 60u) {
        if (l2 == 61u) {
            t0 = vader_lexer_emit_and_advance(l0, (uint8_t) 53, 433u);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (l1 == 62u) {
        if (l2 == 61u) {
            t0 = vader_lexer_emit_and_advance(l0, (uint8_t) 55, 455u);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (l1 == 38u) {
        if (l2 == 38u) {
            t0 = vader_lexer_emit_and_advance(l0, (uint8_t) 58, 232u);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (l1 == 124u) {
        if (l2 == 124u) {
            t0 = vader_lexer_emit_and_advance(l0, (uint8_t) 59, 2824u);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (l1 == 63u) {
        if (l2 == 63u) {
            t0 = vader_lexer_emit_and_advance(l0, (uint8_t) 61, 459u);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (l1 == 60u) {
        if (l2 == 60u) {
            t0 = vader_lexer_emit_and_advance(l0, (uint8_t) 48, 432u);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (l1 == 62u) {
        if (l2 == 62u) {
            t0 = vader_lexer_emit_and_advance(l0, (uint8_t) 49, 456u);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (l1 == 45u) {
        if (l2 == 62u) {
            t0 = vader_lexer_emit_and_advance(l0, (uint8_t) 76, 325u);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (l1 == 61u) {
        if (l2 == 62u) {
            t0 = vader_lexer_emit_and_advance(l0, (uint8_t) 77, 453u);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (l1 == 58u) {
        if (l2 == 58u) {
            t0 = vader_lexer_emit_and_advance(l0, (uint8_t) 71, 424u);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (l1 == 58u) {
        if (l2 == 61u) {
            t0 = vader_lexer_emit_and_advance(l0, (uint8_t) 72, 426u);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (l1 == 43u) {
        if (l2 == 61u) {
            t0 = vader_lexer_emit_and_advance(l0, (uint8_t) 63, 300u);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (l1 == 45u) {
        if (l2 == 61u) {
            t0 = vader_lexer_emit_and_advance(l0, (uint8_t) 64, 324u);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (l1 == 42u) {
        if (l2 == 61u) {
            t0 = vader_lexer_emit_and_advance(l0, (uint8_t) 65, 296u);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (l1 == 47u) {
        if (l2 == 61u) {
            t0 = vader_lexer_emit_and_advance(l0, (uint8_t) 66, 383u);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (l1 == 37u) {
        if (l2 == 61u) {
            t0 = vader_lexer_emit_and_advance(l0, (uint8_t) 67, 230u);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (l1 == 43u) {
        t0 = vader_lexer_emit_and_advance(l0, (uint8_t) 36, 297u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 45u) {
        t0 = vader_lexer_emit_and_advance(l0, (uint8_t) 37, 320u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 42u) {
        t0 = vader_lexer_emit_and_advance(l0, (uint8_t) 38, 293u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 47u) {
        t0 = vader_lexer_emit_and_advance(l0, (uint8_t) 39, 374u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 37u) {
        t0 = vader_lexer_emit_and_advance(l0, (uint8_t) 40, 229u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 38u) {
        t0 = vader_lexer_emit_and_advance(l0, (uint8_t) 44, 231u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 124u) {
        t0 = vader_lexer_emit_and_advance(l0, (uint8_t) 45, 2823u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 94u) {
        t0 = vader_lexer_emit_and_advance(l0, (uint8_t) 46, 852u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 126u) {
        t0 = vader_lexer_emit_and_advance(l0, (uint8_t) 47, 2830u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 60u) {
        t0 = vader_lexer_emit_and_advance(l0, (uint8_t) 52, 431u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 62u) {
        t0 = vader_lexer_emit_and_advance(l0, (uint8_t) 54, 454u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 33u) {
        t0 = vader_lexer_emit_and_advance(l0, (uint8_t) 60, 196u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 61u) {
        t0 = vader_lexer_emit_and_advance(l0, (uint8_t) 62, 449u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 64u) {
        t0 = vader_lexer_emit_and_advance(l0, (uint8_t) 78, 460u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 36u) {
        t0 = vader_lexer_emit_and_advance(l0, (uint8_t) 79, 210u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 58u) {
        t0 = vader_lexer_emit_and_advance(l0, (uint8_t) 88, 393u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 44u) {
        t0 = vader_lexer_emit_and_advance(l0, (uint8_t) 86, 302u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 46u) {
        t0 = vader_lexer_emit_and_advance(l0, (uint8_t) 87, 334u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 40u) {
        l4 = vader_lexer_position_here(l0);
        vader_lexer_advance(l0, INT64_C(1));
        t2 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_paren_depth;
        l5 = vader_chk_add(i32, t2, INT32_C(1));
        ((vader_struct_vader_lexer_Lexer_t*) l0)->f_paren_depth = l5;
        vader_lexer_push_simple(l0, (uint8_t) 80, 251u, l4);
        { vader_gc_top = gc_frame.prev; return true; }
    }
    if (l1 == 91u) {
        l4 = vader_lexer_position_here(l0);
        vader_lexer_advance(l0, INT64_C(1));
        t2 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_paren_depth;
        l5 = vader_chk_add(i32, t2, INT32_C(1));
        ((vader_struct_vader_lexer_Lexer_t*) l0)->f_paren_depth = l5;
        vader_lexer_push_simple(l0, (uint8_t) 82, 843u, l4);
        { vader_gc_top = gc_frame.prev; return true; }
    }
    if (l1 == 41u) {
        l4 = vader_lexer_position_here(l0);
        vader_lexer_advance(l0, INT64_C(1));
        t2 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_paren_depth;
        if ((t2 > INT32_C(0))) {
            t2 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_paren_depth;
            l5 = vader_chk_sub(i32, t2, INT32_C(1));
            ((vader_struct_vader_lexer_Lexer_t*) l0)->f_paren_depth = l5;
        }
        vader_lexer_push_simple(l0, (uint8_t) 81, 268u, l4);
        { vader_gc_top = gc_frame.prev; return true; }
    }
    if (l1 == 93u) {
        l4 = vader_lexer_position_here(l0);
        vader_lexer_advance(l0, INT64_C(1));
        t2 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_paren_depth;
        if ((t2 > INT32_C(0))) {
            t2 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_paren_depth;
            l5 = vader_chk_sub(i32, t2, INT32_C(1));
            ((vader_struct_vader_lexer_Lexer_t*) l0)->f_paren_depth = l5;
        }
        vader_lexer_push_simple(l0, (uint8_t) 83, 846u, l4);
        { vader_gc_top = gc_frame.prev; return true; }
    }
    if (l1 == 123u) {
        l6 = vader_lexer_top_interp(l0);
        if (l6.tag == 945u) {
            l4 = l6.payload.obj;
            t3 = l6.payload.obj;
            t2 = ((vader_struct_vader_lexer_InterpFrame_t*) t3)->f_brace_depth;
            l5 = vader_chk_add(i32, t2, INT32_C(1));
            ((vader_struct_vader_lexer_InterpFrame_t*) l4)->f_brace_depth = l5;
        }
        l4 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_enclosing_paren_depths;
        l5 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_paren_depth;
        vader_array_push_i32((vader_array_t*) l4, l5);
        ((vader_struct_vader_lexer_Lexer_t*) l0)->f_paren_depth = INT32_C(0);
        t0 = vader_lexer_emit_and_advance(l0, (uint8_t) 84, 2815u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l1 == 125u)) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    l6 = vader_lexer_top_interp(l0);
    if (l6.tag == 945u) {
        t3 = l6.payload.obj;
        t2 = ((vader_struct_vader_lexer_InterpFrame_t*) t3)->f_brace_depth;
        if ((t2 > INT32_C(0))) {
            l4 = l6.payload.obj;
            t3 = l6.payload.obj;
            t2 = ((vader_struct_vader_lexer_InterpFrame_t*) t3)->f_brace_depth;
            l5 = vader_chk_sub(i32, t2, INT32_C(1));
            ((vader_struct_vader_lexer_InterpFrame_t*) l4)->f_brace_depth = l5;
        }
    }
    l6 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_lexer_Lexer_t*) l0)->f_enclosing_paren_depths);
    if (l6.tag == 0u) {
        l5 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_paren_depth;
    } else {
        l5 = ((int32_t) l6.payload.i);
    }
    ((vader_struct_vader_lexer_Lexer_t*) l0)->f_paren_depth = l5;
    t0 = vader_lexer_emit_and_advance(l0, (uint8_t) 85, 2825u);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}
