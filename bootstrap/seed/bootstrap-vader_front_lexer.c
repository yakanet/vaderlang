#include "bootstrap.split.h"

static void vader_front_lexer$advance(void* l0, int64_t l1);
static bool vader_front_lexer$at_end(void* l0);
static void vader_front_lexer$close_doc_run(void* l0, void* l1);
static vader_string_t vader_front_lexer$codepoint_label(uint32_t l0);
static void vader_front_lexer$consume_digits(void* l0, int32_t l1, void* l2);
static bool vader_front_lexer$continues_previous_line(uint8_t l0);
static void vader_front_lexer$count_indentation(void* l0, int64_t l1);
static void vader_front_lexer$drop_empty_parts(void* l0, int64_t l1);
static void vader_front_lexer$emit(void* l0, void* l1);
static bool vader_front_lexer$emit_and_advance(void* l0, uint8_t l1, vader_string_t l2);
static void vader_front_lexer$end_line(void* l0);
static void vader_front_lexer$end_part(void* l0, void* l1, bool l2);
static void* vader_front_lexer$error_span(void* l0, void* l1);
static void* vader_front_lexer$first_malformed_utf8(void* l0);
static void vader_front_lexer$flush_string_part(void* l0, void* l1, void* l2, bool l3, vader_box_t l4);
static void vader_front_lexer$handle_newline(void* l0);
static int64_t vader_front_lexer$held_width(void* l0, void* l1);
static void vader_front_lexer$hold_blank(void* l0, void* l1);
static bool vader_front_lexer$in_interp_expression(void* l0);
static bool vader_front_lexer$is_ident_continue(uint32_t l0);
static bool vader_front_lexer$is_ident_start(uint32_t l0);
static bool vader_front_lexer$is_malformed_utf8(uint32_t l0, int64_t l1, uint8_t l2);
static void vader_front_lexer$lex_block_comment(void* l0);
static void vader_front_lexer$lex_char(void* l0);
static uint32_t vader_front_lexer$lex_escape(void* l0, bool l1);
static void vader_front_lexer$lex_ident(void* l0);
static void vader_front_lexer$lex_number(void* l0);
static void vader_front_lexer$lex_one(void* l0);
static void vader_front_lexer$lex_string(void* l0, bool l1);
static void vader_front_lexer$lex_string_body(void* l0, bool l1, bool l2, vader_box_t l3);
static uint32_t vader_front_lexer$lex_unicode_escape(void* l0, void* l1);
static int64_t vader_front_lexer$line_break_width(void* l0);
static uint8_t vader_front_lexer$lookup_keyword(vader_string_t l0);
static void* vader_front_lexer$make_token(uint8_t l0, vader_string_t l1, void* l2);
static bool vader_front_lexer$malformed_here(void* l0);
static vader_string_t vader_front_lexer$malformed_utf8_detail(int32_t l0);
static void vader_front_lexer$note_line_comment(void* l0, int64_t l1, int32_t l2);
static uint32_t vader_front_lexer$peek(void* l0);
static uint32_t vader_front_lexer$peek_at(void* l0, int64_t l1);
static void vader_front_lexer$pop_interp(void* l0);
static void* vader_front_lexer$position_here(void* l0);
static void vader_front_lexer$push_error(void* l0, uint8_t l1, void* l2, vader_string_t l3);
static void vader_front_lexer$push_simple(void* l0, uint8_t l1, vader_string_t l2, void* l3);
static void* vader_front_lexer$run_lexer(void* l0);
static bool vader_front_lexer$settle(void* l0, void* l1, void* l2);
static void vader_front_lexer$skip_bom(void* l0);
static void vader_front_lexer$skip_horizontal(void* l0);
static void vader_front_lexer$strip_indentation(void* l0, void* l1);
static bool vader_front_lexer$suppresses_newline_after(uint8_t l0);
static vader_box_t vader_front_lexer$top_interp(void* l0);
static bool vader_front_lexer$try_lex_operator(void* l0);
static void vader_front_lexer$write_char(void* l0, uint32_t l1, vader_box_t l2);

static void vader_front_lexer$advance(void* l0, int64_t l1) {
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
        l3 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_pos;
        t0 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_src;
        l4 = vader_host_std_core$byte_len(t0);
        if ((l3 >= l4)) {
            return;
        }
        l5 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_src;
        l6 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_pos;
        l7 = vader_host_std_core$byte_at(l5, l6);
        if ((l7 >= INT32_C(128))) {
            l8 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_src;
            l9 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_pos;
            std_core$codepoint_at_byte(l8, l9, &t1, &t2);
            l23 = t2;
            l10 = t1;
            l11 = l23;
            t3 = vader_front_lexer$is_malformed_utf8(l10, l11, l7);
            if (t3) {
                t4 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_malformed_utf8_runs;
                if (t4 == INT32_C(0)) {
                    l12 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_pos;
                    ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_malformed_utf8_at = l12;
                }
                t4 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_malformed_utf8_runs;
                l13 = vader_chk_add(i32, t4, INT32_C(1));
                ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_malformed_utf8_runs = l13;
            }
            t4 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_col;
            l14 = vader_chk_add(i32, t4, INT32_C(1));
            ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_col = l14;
            t2 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_pos;
            l15 = vader_chk_add(i64, t2, l11);
            ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_pos = l15;
            l2 = (l2 + INT64_C(1));
            continue;
        }
        if (l7 == INT32_C(10)) {
            t4 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_line;
            l16 = vader_chk_add(i32, t4, INT32_C(1));
            ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_line = l16;
            ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_col = INT32_C(1);
        } else if (l7 == INT32_C(13)) {
            t2 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_pos;
            l17 = vader_chk_add(i64, t2, INT64_C(1));
            t0 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_src;
            l18 = vader_host_std_core$byte_len(t0);
            if ((l17 >= l18)) {
                l19 = true;
            } else {
                t0 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_src;
                t5 = vader_host_std_core$byte_at(t0, l17);
                l19 = t5 != INT32_C(10);
            }
            if (l19) {
                t4 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_line;
                l20 = vader_chk_add(i32, t4, INT32_C(1));
                ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_line = l20;
                ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_col = INT32_C(1);
            }
        } else {
            t4 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_col;
            l21 = vader_chk_add(i32, t4, INT32_C(1));
            ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_col = l21;
        }
        t2 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_pos;
        l22 = vader_chk_add(i64, t2, INT64_C(1));
        ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_pos = l22;
        l2 = (l2 + INT64_C(1));
    }
    return;
}

static bool vader_front_lexer$at_end(void* l0) {
    int64_t l1, l2;
    vader_string_t t0;
    l1 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_pos;
    t0 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_src;
    l2 = vader_host_std_core$byte_len(t0);
    return (l1 >= l2);
}

static void vader_front_lexer$close_doc_run(void* l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    vader_box_t l3 = vader_box_null();
    int64_t l5;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_open_doc;
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l2 = l3.payload.obj;
    l4 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_doc_runs;
    l5 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_front_lexer$Token_t*) l1)->f_span)->f_start)->f_offset;
    vader_struct_vader_front_lexer$DocRun_t* _a0_obj = (vader_struct_vader_front_lexer$DocRun_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_lexer$DocRun_t));
    vader_obj_header_init(_a0_obj, 1185u);
    _a0_obj->f_doc = l2;
    _a0_obj->f_followed_by = l5;
    l2 = (void*) _a0_obj;
    vader_array_push_ref((vader_array_t*) l4, l2);
    ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_open_doc = vader_box_obj(0u, NULL);
    VADER_WRITE_BARRIER((vader_struct_vader_front_lexer$Lexer_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_string_t vader_front_lexer$codepoint_label(uint32_t l0) {
    vader_string_t l1 = 0;
    vader_string_t t0 = 0;
    vader_string_t t1 = 0;
    vader_string_t* gc_atom_roots[3] = { &l1, &t0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = std_numbers$to_hex((uint64_t) (int64_t) ((int64_t) (uint32_t) ((int32_t) (uint32_t) l0)));
    t1 = std_string$to_upper(t0);
    l1 = std_string$pad_start(t1, INT64_C(4), 48u);
    t0 = concat_2(918u, l1);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_front_lexer$consume_digits(void* l0, int32_t l1, void* l2) {
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
        t0 = vader_front_lexer$at_end(l0);
        if (!(t0)) {
            l5 = vader_front_lexer$peek(l0);
            if (l5 == 95u) {
                l6 = vader_front_lexer$peek_at(l0, INT64_C(1));
                if (l6 != 95u) {
                    t0 = vader_front_lexer$is_ident_start(l6);
                    if (t0) {
                        t0 = std_numbers$is_digit_in_base(l6, l1);
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
                    l8 = vader_front_lexer$error_span(l0, l2);
                    vader_front_lexer$push_error(l0, (uint8_t) 5, l8, 2809u);
                }
                l3 = true;
                l4 = false;
                vader_front_lexer$advance(l0, INT64_C(1));
                continue;
            }
            t0 = std_numbers$is_digit_in_base(l5, l1);
            if (!(t0)) {
                break;
            }
            l3 = false;
            l4 = false;
            vader_front_lexer$advance(l0, INT64_C(1));
            continue;
        }
        break;
    }
    if (l3) {
        l8 = vader_front_lexer$error_span(l0, l2);
        vader_front_lexer$push_error(l0, (uint8_t) 5, l8, 2809u);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_front_lexer$continues_previous_line(uint8_t l0) {
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

static void vader_front_lexer$count_indentation(void* l0, int64_t l1) {
    bool l2;
    int64_t l3;
    int64_t t0;
    t0 = ((vader_struct_vader_front_lexer$TextBlock_t*) l0)->f_common;
    if ((t0 < INT64_C(0))) {
        l2 = true;
    } else {
        l3 = ((vader_struct_vader_front_lexer$TextBlock_t*) l0)->f_common;
        l2 = (l1 < l3);
    }
    if (l2) {
        ((vader_struct_vader_front_lexer$TextBlock_t*) l0)->f_common = l1;
        return;
    }
    return;
}

static void vader_front_lexer$drop_empty_parts(void* l0, int64_t l1) {
    int64_t l2, l3, l4;
    void* l5;
    bool l6;
    vader_string_t t0;
    int64_t t1;
    vader_box_t t2;
    l2 = l1;
    l3 = l1;
    l4 = ((vader_array_t*) ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_tokens)->length;
    while ((l3 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_tokens);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        if (((vader_struct_vader_front_lexer$Token_t*) l5)->f_kind != INT32_C(7)) {
            l6 = true;
        } else {
            t0 = ((vader_struct_vader_front_lexer$Token_t*) l5)->f_text;
            l6 = t0 != 0u;
        }
        if (l6) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_tokens);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
            vader_array_ref_store(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l2, l5);
            VADER_WRITE_BARRIER(_a1_slotarr->buf);
            l2 = vader_chk_add(i64, l2, INT64_C(1));
        }
        l3 = (l3 + INT64_C(1));
    }
    for (;;) {
        t1 = ((vader_array_t*) ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_tokens)->length;
        if ((t1 > l2)) {
            t2 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_tokens);
            continue;
        }
        break;
    }
    return;
}

static void vader_front_lexer$emit(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    void* l4 = NULL;
    uint8_t l5;
    bool t0;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_pending_newline;
    if (!(l2.tag == 0u)) {
        ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_pending_newline = vader_box_obj(0u, NULL);
        VADER_WRITE_BARRIER((vader_struct_vader_front_lexer$Lexer_t*) l0);
        t0 = vader_front_lexer$continues_previous_line(((vader_struct_vader_front_lexer$Token_t*) l1)->f_kind);
        if (!(t0)) {
            l3 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_tokens;
            l4 = l2.payload.obj;
            l4 = vader_front_lexer$make_token((uint8_t) 1, 1u, l4);
            vader_array_push_ref((vader_array_t*) l3, l4);
        }
    }
    vader_array_push_ref((vader_array_t*) ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_tokens, l1);
    l5 = ((vader_struct_vader_front_lexer$Token_t*) l1)->f_kind;
    ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_last_kind = l5;
    if (((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_open_doc.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_front_lexer$close_doc_run(l0, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_front_lexer$emit_and_advance(void* l0, uint8_t l1, vader_string_t l2) {
    void* l3 = NULL;
    int64_t l4;
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_front_lexer$position_here(l0);
    l4 = vader_host_std_core$byte_len(l2);
    vader_front_lexer$advance(l0, l4);
    vader_front_lexer$push_simple(l0, l1, l2, l3);
    { vader_gc_top = gc_frame.prev; return true; }
}

void* vader_front_lexer$empty_file_span(vader_string_t l0) {
    void* l1 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_toolchain_span$Position_t* _a0_obj = (vader_struct_toolchain_span$Position_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Position_t));
    vader_obj_header_init(_a0_obj, 834u);
    _a0_obj->f_file = l0;
    _a0_obj->f_offset = INT64_C(0);
    _a0_obj->f_line = INT32_C(1);
    _a0_obj->f_column = INT32_C(1);
    l1 = (void*) _a0_obj;
    vader_struct_toolchain_span$Span_t* _a1_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
    vader_obj_header_init(_a1_obj, 835u);
    _a1_obj->f_start = l1;
    _a1_obj->f_end = l1;
    t0 = (void*) _a1_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_front_lexer$end_line(void* l0) {
    ((vader_struct_vader_front_lexer$TextBlock_t*) l0)->f_pending_from = INT64_C(-1);
    ((vader_struct_vader_front_lexer$TextBlock_t*) l0)->f_at_line_start = true;
    return;
}

static void vader_front_lexer$end_part(void* l0, void* l1, bool l2) {
    void* l3 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    int64_t l4, l5, l6;
    int64_t t0, t1;
    void** gc_raw_roots[5] = { &l0, &l1, &l3, &l7, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l2) {
        l3 = ((vader_struct_vader_front_lexer$TextBlock_t*) l0)->f_part_lines;
        l4 = ((vader_array_t*) l3)->length;
        l5 = INT64_C(0);
        while ((l5 < l4)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            l6 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l5];
            l7 = ((vader_struct_vader_front_lexer$TextBlock_t*) l0)->f_lines;
            t0 = ((vader_array_t*) ((vader_struct_vader_front_lexer$Lexer_t*) l1)->f_tokens)->length;
            t1 = vader_chk_sub(i64, t0, INT64_C(1));
            vader_struct_vader_front_lexer$TextBlockLine_t* _a1_obj = (vader_struct_vader_front_lexer$TextBlockLine_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_lexer$TextBlockLine_t));
            vader_obj_header_init(_a1_obj, 1190u);
            _a1_obj->f_part = t1;
            _a1_obj->f_offset = l6;
            l8 = (void*) _a1_obj;
            vader_array_push_ref((vader_array_t*) l7, l8);
            l5 = (l5 + INT64_C(1));
        }
    }
    vader_array_clear((vader_array_t*) ((vader_struct_vader_front_lexer$TextBlock_t*) l0)->f_part_lines);
    ((vader_struct_vader_front_lexer$TextBlock_t*) l0)->f_part_len = INT64_C(0);
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_front_lexer$error_span(void* l0, void* l1) {
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_front_lexer$position_here(l0);
    vader_struct_toolchain_span$Span_t* _a0_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
    vader_obj_header_init(_a0_obj, 835u);
    _a0_obj->f_start = l1;
    _a0_obj->f_end = l2;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_lexer$first_malformed_utf8(void* l0) {
    vader_string_t l1 = 0;
    vader_string_t l2 = 0;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    int64_t l8, l9;
    void* t0 = NULL;
    void** gc_raw_roots[7] = { &l0, &l3, &l4, &l5, &l6, &l7, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 7u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_src;
    l2 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_file;
    vader_array_t* _a0_arr = vader_array_new(23u, 0u, 7u, 450u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(236u, 0u, 13u, 1191u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(328u, 0u, 13u, 1524u);
    l5 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(234u, 0u, 13u, 1186u);
    l6 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(233u, 0u, 13u, 1185u);
    l7 = (void*) _a4_arr;
    vader_struct_vader_front_lexer$Lexer_t* _a5_obj = (vader_struct_vader_front_lexer$Lexer_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_lexer$Lexer_t));
    vader_obj_header_init(_a5_obj, 1188u);
    _a5_obj->f_src = l1;
    _a5_obj->f_file = l2;
    _a5_obj->f_pos = INT64_C(0);
    _a5_obj->f_line = INT32_C(1);
    _a5_obj->f_col = INT32_C(1);
    _a5_obj->f_paren_depth = INT32_C(0);
    _a5_obj->f_enclosing_paren_depths = l3;
    _a5_obj->f_last_kind = (uint8_t) 1;
    _a5_obj->f_pending_newline = vader_box_obj(0u, NULL);
    _a5_obj->f_malformed_utf8_runs = INT32_C(0);
    _a5_obj->f_malformed_utf8_at = INT64_C(0);
    _a5_obj->f_tokens = l4;
    _a5_obj->f_errors = l5;
    _a5_obj->f_interp_stack = l6;
    _a5_obj->f_include_doc_comments = false;
    _a5_obj->f_doc_runs = l7;
    _a5_obj->f_open_doc = vader_box_obj(0u, NULL);
    l3 = (void*) _a5_obj;
    vader_front_lexer$skip_bom(l3);
    for (;;) {
        l8 = ((vader_struct_vader_front_lexer$Lexer_t*) l3)->f_pos;
        l9 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_malformed_utf8_at;
        if ((l8 < l9)) {
            vader_front_lexer$advance(l3, INT64_C(1));
            continue;
        }
        break;
    }
    l4 = vader_front_lexer$position_here(l3);
    vader_front_lexer$advance(l3, INT64_C(1));
    t0 = vader_front_lexer$error_span(l3, l4);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_front_lexer$flush_string_part(void* l0, void* l1, void* l2, bool l3, vader_box_t l4) {
    vader_string_t l5 = 0;
    void* l6 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l6, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l3) {
        l5 = std_string__builder$StringBuilder$std_core$Display$to_string(l1);
        l6 = vader_front_lexer$position_here(l0);
        vader_struct_toolchain_span$Span_t* _a0_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
        vader_obj_header_init(_a0_obj, 835u);
        _a0_obj->f_start = l2;
        _a0_obj->f_end = l6;
        l6 = (void*) _a0_obj;
        l6 = vader_front_lexer$make_token((uint8_t) 7, l5, l6);
        ((vader_struct_vader_front_lexer$Token_t*) l6)->f_value = vader_box_string(447u, l5);
        VADER_WRITE_BARRIER((vader_struct_vader_front_lexer$Token_t*) l6);
        vader_front_lexer$emit(l0, l6);
    }
    if (l4.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = l4.payload.obj;
    vader_front_lexer$end_part(t0, l0, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_lexer$handle_newline(void* l0) {
    int64_t l1;
    void* l2 = NULL;
    int32_t t0;
    bool t1;
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_front_lexer$line_break_width(l0);
    vader_front_lexer$advance(l0, l1);
    t0 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_paren_depth;
    if ((t0 > INT32_C(0))) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    t1 = vader_front_lexer$suppresses_newline_after(((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_last_kind);
    if (t1) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_last_kind == INT32_C(1)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_pending_newline.tag == 0u) {
        l2 = vader_front_lexer$position_here(l0);
        vader_struct_toolchain_span$Span_t* _a0_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
        vader_obj_header_init(_a0_obj, 835u);
        _a0_obj->f_start = l2;
        _a0_obj->f_end = l2;
        l2 = (void*) _a0_obj;
        ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_pending_newline = vader_ref_box(l2);
        VADER_WRITE_BARRIER((vader_struct_vader_front_lexer$Lexer_t*) l0);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static int64_t vader_front_lexer$held_width(void* l0, void* l1) {
    int64_t l2, l3;
    int64_t t0;
    t0 = ((vader_struct_vader_front_lexer$TextBlock_t*) l0)->f_pending_from;
    if (!((t0 < INT64_C(0)))) {
        l2 = ((vader_struct_vader_front_lexer$Lexer_t*) l1)->f_pos;
        l3 = ((vader_struct_vader_front_lexer$TextBlock_t*) l0)->f_pending_from;
        t0 = vader_chk_sub(i64, l2, l3);
        return t0;
    }
    return INT64_C(0);
}

static void vader_front_lexer$hold_blank(void* l0, void* l1) {
    int64_t l2;
    int64_t t0;
    t0 = ((vader_struct_vader_front_lexer$TextBlock_t*) l0)->f_pending_from;
    if ((t0 < INT64_C(0))) {
        l2 = ((vader_struct_vader_front_lexer$Lexer_t*) l1)->f_pos;
        ((vader_struct_vader_front_lexer$TextBlock_t*) l0)->f_pending_from = l2;
        return;
    }
    return;
}

static bool vader_front_lexer$in_interp_expression(void* l0) {
    void* l1;
    vader_box_t l2;
    int32_t t0;
    l2 = vader_front_lexer$top_interp(l0);
    if (l2.tag == 0u) {
        return false;
    }
    l1 = l2.payload.obj;
    t0 = ((vader_struct_vader_front_lexer$InterpFrame_t*) l1)->f_brace_depth;
    return t0 == INT32_C(0);
}

static bool vader_front_lexer$is_ident_continue(uint32_t l0) {
    bool t0;
    t0 = std_char$is_alnum(l0);
    if (t0) {
        return true;
    }
    return l0 == 95u;
}

static bool vader_front_lexer$is_ident_start(uint32_t l0) {
    bool t0;
    t0 = std_char$is_alpha(l0);
    if (t0) {
        return true;
    }
    return l0 == 95u;
}

static bool vader_front_lexer$is_malformed_utf8(uint32_t l0, int64_t l1, uint8_t l2) {
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

vader_string_t vader_front_lexer$kind_name(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(2)) {
        l1 = 2125u;
        return l1;
    }
    if (l0 == INT32_C(3)) {
        l1 = 2176u;
    } else if (l0 == INT32_C(4)) {
        l1 = 2008u;
    } else if (l0 == INT32_C(5)) {
        l1 = 1753u;
    } else if (l0 == INT32_C(6)) {
        l1 = 2651u;
    } else if (l0 == INT32_C(7)) {
        l1 = 2653u;
    } else if (l0 == INT32_C(8)) {
        l1 = 2652u;
    } else if (l0 == INT32_C(9)) {
        l1 = 2185u;
    } else if (l0 == INT32_C(10)) {
        l1 = 2184u;
    } else if (l0 == INT32_C(11)) {
        l1 = 2247u;
    } else if (l0 == INT32_C(12)) {
        l1 = 2258u;
    } else if (l0 == INT32_C(13)) {
        l1 = 2259u;
    } else if (l0 == INT32_C(14)) {
        l1 = 2250u;
    } else if (l0 == INT32_C(15)) {
        l1 = 2244u;
    } else if (l0 == INT32_C(16)) {
        l1 = 2249u;
    } else if (l0 == INT32_C(17)) {
        l1 = 2243u;
    } else if (l0 == INT32_C(18)) {
        l1 = 2254u;
    } else if (l0 == INT32_C(19)) {
        l1 = 2253u;
    } else if (l0 == INT32_C(20)) {
        l1 = 2248u;
    } else if (l0 == INT32_C(21)) {
        l1 = 2252u;
    } else if (l0 == INT32_C(22)) {
        l1 = 2256u;
    } else if (l0 == INT32_C(23)) {
        l1 = 2261u;
    } else if (l0 == INT32_C(24)) {
        l1 = 2238u;
    } else if (l0 == INT32_C(25)) {
        l1 = 2242u;
    } else if (l0 == INT32_C(26)) {
        l1 = 2239u;
    } else if (l0 == INT32_C(27)) {
        l1 = 2241u;
    } else if (l0 == INT32_C(28)) {
        l1 = 2251u;
    } else if (l0 == INT32_C(29)) {
        l1 = 2237u;
    } else if (l0 == INT32_C(30)) {
        l1 = 2245u;
    } else if (l0 == INT32_C(31)) {
        l1 = 2260u;
    } else if (l0 == INT32_C(32)) {
        l1 = 2246u;
    } else if (l0 == INT32_C(33)) {
        l1 = 2255u;
    } else if (l0 == INT32_C(34)) {
        l1 = 2257u;
    } else if (l0 == INT32_C(35)) {
        l1 = 2240u;
    } else if (l0 == INT32_C(36)) {
        l1 = 2469u;
    } else if (l0 == INT32_C(37)) {
        l1 = 2344u;
    } else if (l0 == INT32_C(38)) {
        l1 = 2579u;
    } else if (l0 == INT32_C(39)) {
        l1 = 2568u;
    } else if (l0 == INT32_C(40)) {
        l1 = 2464u;
    } else if (l0 == INT32_C(41)) {
        l1 = 2471u;
    } else if (l0 == INT32_C(42)) {
        l1 = 2346u;
    } else if (l0 == INT32_C(43)) {
        l1 = 2581u;
    } else if (l0 == INT32_C(44)) {
        l1 = 1519u;
    } else if (l0 == INT32_C(45)) {
        l1 = 2467u;
    } else if (l0 == INT32_C(46)) {
        l1 = 1741u;
    } else if (l0 == INT32_C(47)) {
        l1 = 2730u;
    } else if (l0 == INT32_C(48)) {
        l1 = 2554u;
    } else if (l0 == INT32_C(49)) {
        l1 = 2558u;
    } else if (l0 == INT32_C(50)) {
        l1 = 1902u;
    } else if (l0 == INT32_C(51)) {
        l1 = 2375u;
    } else if (l0 == INT32_C(56)) {
        l1 = 2537u;
    } else if (l0 == INT32_C(57)) {
        l1 = 2410u;
    } else if (l0 == INT32_C(52)) {
        l1 = 2300u;
    } else if (l0 == INT32_C(53)) {
        l1 = 2301u;
    } else if (l0 == INT32_C(54)) {
        l1 = 2068u;
    } else if (l0 == INT32_C(55)) {
        l1 = 2069u;
    } else if (l0 == INT32_C(58)) {
        l1 = 1546u;
    } else if (l0 == INT32_C(59)) {
        l1 = 2441u;
    } else if (l0 == INT32_C(61)) {
        l1 = 2484u;
    } else if (l0 == INT32_C(60)) {
        l1 = 1617u;
    } else if (l0 == INT32_C(62)) {
        l1 = 1599u;
    } else if (l0 == INT32_C(63)) {
        l1 = 2470u;
    } else if (l0 == INT32_C(64)) {
        l1 = 2345u;
    } else if (l0 == INT32_C(65)) {
        l1 = 2580u;
    } else if (l0 == INT32_C(66)) {
        l1 = 2569u;
    } else if (l0 == INT32_C(67)) {
        l1 = 2465u;
    } else if (l0 == INT32_C(68)) {
        l1 = 2472u;
    } else if (l0 == INT32_C(69)) {
        l1 = 2347u;
    } else if (l0 == INT32_C(70)) {
        l1 = 2582u;
    } else if (l0 == INT32_C(71)) {
        l1 = 1818u;
    } else if (l0 == INT32_C(72)) {
        l1 = 1819u;
    } else if (l0 == INT32_C(73)) {
        l1 = 2488u;
    } else if (l0 == INT32_C(74)) {
        l1 = 2489u;
    } else if (l0 == INT32_C(75)) {
        l1 = 1845u;
    } else if (l0 == INT32_C(76)) {
        l1 = 1594u;
    } else if (l0 == INT32_C(77)) {
        l1 = 1975u;
    } else if (l0 == INT32_C(78)) {
        l1 = 1606u;
    } else if (l0 == INT32_C(79)) {
        l1 = 2298u;
    } else if (l0 == INT32_C(80)) {
        l1 = 2533u;
    } else if (l0 == INT32_C(81)) {
        l1 = 2266u;
    } else if (l0 == INT32_C(82)) {
        l1 = 2493u;
    } else if (l0 == INT32_C(83)) {
        l1 = 2265u;
    } else if (l0 == INT32_C(84)) {
        l1 = 2492u;
    } else if (l0 == INT32_C(85)) {
        l1 = 1771u;
    } else if (l0 == INT32_C(86)) {
        l1 = 1844u;
    } else if (l0 == INT32_C(87)) {
        l1 = 1769u;
    } else if (l0 == INT32_C(1)) {
        l1 = 2378u;
    } else {
        if (!(l0 == INT32_C(0))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 1901u;
    }
    return l1;
}

static void vader_front_lexer$lex_block_comment(void* l0) {
    void* l1 = NULL;
    int32_t l2;
    bool t0;
    uint32_t t1;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_open_doc = vader_box_obj(0u, NULL);
    VADER_WRITE_BARRIER((vader_struct_vader_front_lexer$Lexer_t*) l0);
    l1 = vader_front_lexer$position_here(l0);
    vader_front_lexer$advance(l0, INT64_C(2));
    l2 = INT32_C(1);
    for (;;) {
        t0 = vader_front_lexer$at_end(l0);
        if (!(t0)) {
            if (!((l2 > INT32_C(0)))) {
                break;
            }
            t1 = vader_front_lexer$peek(l0);
            if (t1 == 47u) {
                t1 = vader_front_lexer$peek_at(l0, INT64_C(1));
                if (t1 == 42u) {
                    vader_front_lexer$advance(l0, INT64_C(2));
                    l2 = vader_chk_add(i32, l2, INT32_C(1));
                    continue;
                }
            }
            t1 = vader_front_lexer$peek(l0);
            if (t1 == 42u) {
                t1 = vader_front_lexer$peek_at(l0, INT64_C(1));
                if (t1 == 47u) {
                    vader_front_lexer$advance(l0, INT64_C(2));
                    l2 = vader_chk_sub(i32, l2, INT32_C(1));
                    continue;
                }
            }
            vader_front_lexer$advance(l0, INT64_C(1));
            continue;
        }
        break;
    }
    if ((l2 > INT32_C(0))) {
        l1 = vader_front_lexer$error_span(l0, l1);
        vader_front_lexer$push_error(l0, (uint8_t) 2, l1, 0u);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_lexer$lex_char(void* l0) {
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
    l1 = vader_front_lexer$position_here(l0);
    vader_front_lexer$advance(l0, INT64_C(1));
    t0 = vader_front_lexer$peek(l0);
    if (t0 == 39u) {
        vader_front_lexer$advance(l0, INT64_C(1));
        l2 = vader_front_lexer$error_span(l0, l1);
        vader_front_lexer$push_error(l0, (uint8_t) 4, l2, 1755u);
        l3 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_src;
        l4 = ((vader_struct_toolchain_span$Position_t*) l1)->f_offset;
        l5 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_pos;
        l3 = vader_host_std_core$byte_slice(l3, l4, l5);
        l2 = vader_front_lexer$error_span(l0, l1);
        l2 = vader_front_lexer$make_token((uint8_t) 5, l3, l2);
        ((vader_struct_vader_front_lexer$Token_t*) l2)->f_value = vader_box_i32(454u, INT32_C(0));
        VADER_WRITE_BARRIER((vader_struct_vader_front_lexer$Token_t*) l2);
        vader_front_lexer$emit(l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l6 = (uint32_t) 0;
    t0 = vader_front_lexer$peek(l0);
    if (t0 == 92u) {
        l6 = vader_front_lexer$lex_escape(l0, true);
    } else {
        t0 = vader_front_lexer$peek(l0);
        if (t0 == 10u) {
            l7 = true;
        } else {
            l7 = vader_front_lexer$at_end(l0);
        }
        if (l7) {
            l2 = vader_front_lexer$error_span(l0, l1);
            vader_front_lexer$push_error(l0, (uint8_t) 4, l2, 2839u);
            l3 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_src;
            l4 = ((vader_struct_toolchain_span$Position_t*) l1)->f_offset;
            l5 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_pos;
            l3 = vader_host_std_core$byte_slice(l3, l4, l5);
            l2 = vader_front_lexer$error_span(l0, l1);
            l2 = vader_front_lexer$make_token((uint8_t) 5, l3, l2);
            ((vader_struct_vader_front_lexer$Token_t*) l2)->f_value = vader_box_i32(454u, INT32_C(0));
            VADER_WRITE_BARRIER((vader_struct_vader_front_lexer$Token_t*) l2);
            vader_front_lexer$emit(l0, l2);
            { vader_gc_top = gc_frame.prev; return; }
        }
        t0 = vader_front_lexer$peek(l0);
        t1 = ((int32_t) (uint32_t) t0);
        l6 = (uint32_t) (int32_t) t1;
        vader_front_lexer$advance(l0, INT64_C(1));
    }
    t0 = vader_front_lexer$peek(l0);
    if (t0 != 39u) {
        l2 = vader_front_lexer$error_span(l0, l1);
        vader_front_lexer$push_error(l0, (uint8_t) 4, l2, 1756u);
        for (;;) {
            t2 = vader_front_lexer$at_end(l0);
            if (!(t2)) {
                t0 = vader_front_lexer$peek(l0);
                if (!(t0 != 39u)) {
                    break;
                }
                t0 = vader_front_lexer$peek(l0);
                if (!(t0 != 10u)) {
                    break;
                }
                vader_front_lexer$advance(l0, INT64_C(1));
                continue;
            }
            break;
        }
        t0 = vader_front_lexer$peek(l0);
        if (t0 == 39u) {
            vader_front_lexer$advance(l0, INT64_C(1));
        }
    } else {
        vader_front_lexer$advance(l0, INT64_C(1));
    }
    l3 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_src;
    l4 = ((vader_struct_toolchain_span$Position_t*) l1)->f_offset;
    l5 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_pos;
    l3 = vader_host_std_core$byte_slice(l3, l4, l5);
    l1 = vader_front_lexer$error_span(l0, l1);
    l1 = vader_front_lexer$make_token((uint8_t) 5, l3, l1);
    ((vader_struct_vader_front_lexer$Token_t*) l1)->f_value = vader_box_i32(454u, (int32_t)(uint32_t) l6);
    VADER_WRITE_BARRIER((vader_struct_vader_front_lexer$Token_t*) l1);
    vader_front_lexer$emit(l0, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static uint32_t vader_front_lexer$lex_escape(void* l0, bool l1) {
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
    l2 = vader_front_lexer$position_here(l0);
    vader_front_lexer$advance(l0, INT64_C(1));
    t0 = vader_front_lexer$at_end(l0);
    if (t0) {
        l3 = vader_front_lexer$error_span(l0, l2);
        vader_front_lexer$push_error(l0, (uint8_t) 3, l3, 2156u);
        { vader_gc_top = gc_frame.prev; return (uint32_t) 0; }
    }
    l4 = vader_front_lexer$peek(l0);
    vader_front_lexer$advance(l0, INT64_C(1));
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
        t1 = vader_front_lexer$lex_unicode_escape(l0, l2);
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
            l3 = vader_front_lexer$error_span(l0, l2);
            l6 = std_core$char$Display$to_string(l4);
            l6 = concat_3(1909u, l6, 164u);
            vader_front_lexer$push_error(l0, (uint8_t) 3, l3, l6);
            { uint32_t __vret = (uint32_t) (int32_t) ((int32_t) (uint32_t) l4); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else {
        if (l4 == 34u) {
            { vader_gc_top = gc_frame.prev; return (uint32_t) 34; }
        }
        if (l4 == 36u) {
            { vader_gc_top = gc_frame.prev; return (uint32_t) 36; }
        }
        if (l4 == 115u) {
            { vader_gc_top = gc_frame.prev; return (uint32_t) 32; }
        }
        if (l4 == 39u) {
            l3 = vader_front_lexer$error_span(l0, l2);
            vader_front_lexer$push_error(l0, (uint8_t) 3, l3, 1910u);
            { uint32_t __vret = (uint32_t) (int32_t) ((int32_t) (uint32_t) l4); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l2 = vader_front_lexer$error_span(l0, l2);
    l6 = std_core$char$Display$to_string(l4);
    l6 = concat_2(2820u, l6);
    vader_front_lexer$push_error(l0, (uint8_t) 3, l2, l6);
    { uint32_t __vret = (uint32_t) (int32_t) ((int32_t) (uint32_t) l4); vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_front_lexer$lex_ident(void* l0) {
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
    l1 = vader_front_lexer$position_here(l0);
    for (;;) {
        t0 = vader_front_lexer$at_end(l0);
        if (!(t0)) {
            t1 = vader_front_lexer$peek(l0);
            t0 = vader_front_lexer$is_ident_continue(t1);
            if (!(t0)) {
                break;
            }
            vader_front_lexer$advance(l0, INT64_C(1));
            continue;
        }
        break;
    }
    l2 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_src;
    l3 = ((vader_struct_toolchain_span$Position_t*) l1)->f_offset;
    l4 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_pos;
    l2 = vader_host_std_core$byte_slice(l2, l3, l4);
    l5 = vader_front_lexer$lookup_keyword(l2);
    vader_front_lexer$push_simple(l0, l5, l2, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_lexer$lex_number(void* l0) {
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
    l1 = vader_front_lexer$position_here(l0);
    l2 = false;
    l3 = INT32_C(10);
    t0 = vader_front_lexer$peek(l0);
    if (t0 == 48u) {
        l4 = vader_front_lexer$peek_at(l0, INT64_C(1));
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
        vader_front_lexer$advance(l0, INT64_C(2));
        l6 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_pos;
        vader_front_lexer$consume_digits(l0, l3, l1);
        t1 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_pos;
        if (t1 == l6) {
            l7 = vader_front_lexer$error_span(l0, l1);
            vader_front_lexer$push_error(l0, (uint8_t) 5, l7, 1931u);
        }
    } else {
        vader_front_lexer$consume_digits(l0, INT32_C(10), l1);
        t0 = vader_front_lexer$peek(l0);
        if (t0 == 46u) {
            t0 = vader_front_lexer$peek_at(l0, INT64_C(1));
            t2 = std_char$is_digit(t0);
            if (t2) {
                l2 = true;
                vader_front_lexer$advance(l0, INT64_C(1));
                vader_front_lexer$consume_digits(l0, INT32_C(10), l1);
            }
        }
        t0 = vader_front_lexer$peek(l0);
        if (t0 == 101u) {
            l5 = true;
        } else {
            t0 = vader_front_lexer$peek(l0);
            l5 = t0 == 69u;
        }
        if (l5) {
            l2 = true;
            vader_front_lexer$advance(l0, INT64_C(1));
            t0 = vader_front_lexer$peek(l0);
            if (t0 == 43u) {
                l5 = true;
            } else {
                t0 = vader_front_lexer$peek(l0);
                l5 = t0 == 45u;
            }
            if (l5) {
                vader_front_lexer$advance(l0, INT64_C(1));
            }
            t0 = vader_front_lexer$peek(l0);
            t2 = std_char$is_digit(t0);
            if (!(t2)) {
                l7 = vader_front_lexer$error_span(l0, l1);
                vader_front_lexer$push_error(l0, (uint8_t) 5, l7, 1937u);
            }
            vader_front_lexer$consume_digits(l0, INT32_C(10), l1);
        }
    }
    l8 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_src;
    l6 = ((vader_struct_toolchain_span$Position_t*) l1)->f_offset;
    l9 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_pos;
    l8 = vader_host_std_core$byte_slice(l8, l6, l9);
    t0 = vader_front_lexer$peek(l0);
    if (t0 == 95u) {
        t0 = vader_front_lexer$peek_at(l0, INT64_C(1));
        l5 = vader_front_lexer$is_ident_start(t0);
    } else {
        l5 = false;
    }
    if (l5) {
        l5 = true;
    } else {
        t0 = vader_front_lexer$peek(l0);
        l5 = vader_front_lexer$is_ident_start(t0);
    }
    if (l5) {
        t0 = vader_front_lexer$peek(l0);
        if (t0 == 95u) {
            vader_front_lexer$advance(l0, INT64_C(1));
        }
        l6 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_pos;
        for (;;) {
            t2 = vader_front_lexer$at_end(l0);
            if (!(t2)) {
                t0 = vader_front_lexer$peek(l0);
                t2 = vader_front_lexer$is_ident_continue(t0);
                if (!(t2)) {
                    break;
                }
                vader_front_lexer$advance(l0, INT64_C(1));
                continue;
            }
            break;
        }
        l10 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_src;
        l9 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_pos;
        l10 = vader_host_std_core$byte_slice(l10, l6, l9);
        l7 = vader_front_lexer$error_span(l0, l1);
        l10 = concat_3(2770u, l10, 1157u);
        vader_front_lexer$push_error(l0, (uint8_t) 5, l7, l10);
    }
    l7 = vader_front_lexer$position_here(l0);
    vader_struct_toolchain_span$Span_t* _a0_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
    vader_obj_header_init(_a0_obj, 835u);
    _a0_obj->f_start = l1;
    _a0_obj->f_end = l7;
    l7 = (void*) _a0_obj;
    l11 = (uint8_t) 3;
    if (l2) {
        l11 = (uint8_t) 4;
    }
    l7 = vader_front_lexer$make_token(l11, l8, l7);
    l10 = std_numbers$strip_numeric_text(l8, l3);
    t2 = std_string$is_empty(l10);
    if (t2) {
        ((vader_struct_vader_front_lexer$Token_t*) l7)->f_value = vader_box_i64(455u, INT64_C(0));
        VADER_WRITE_BARRIER((vader_struct_vader_front_lexer$Token_t*) l7);
        vader_front_lexer$emit(l0, l7);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2) {
        l12 = std_string$parse_float(l10);
        if ((l12.tag == 456u || l12.tag == 457u)) {
            l13 = ((double) l12.payload.f);
        } else {
            if (!(l12.tag == 740u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            l13 = 0.0;
        }
        ((vader_struct_vader_front_lexer$Token_t*) l7)->f_value = vader_box_f64(457u, l13);
        VADER_WRITE_BARRIER((vader_struct_vader_front_lexer$Token_t*) l7);
    } else {
        l12 = std_numbers$parse_uint_in_base(l10, l3);
        if (l12.tag == 455u) {
            l14 = ((uint64_t) l12.payload.i);
            ((vader_struct_vader_front_lexer$Token_t*) l7)->f_value = vader_box_i64(455u, (int64_t)(uint64_t) l14);
            VADER_WRITE_BARRIER((vader_struct_vader_front_lexer$Token_t*) l7);
        } else {
            if (!(l12.tag == 740u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            l1 = vader_front_lexer$error_span(l0, l1);
            l8 = concat_3(1033u, l8, 1080u);
            vader_front_lexer$push_error(l0, (uint8_t) 9, l1, l8);
            ((vader_struct_vader_front_lexer$Token_t*) l7)->f_value = vader_box_i64(455u, INT64_C(0));
            VADER_WRITE_BARRIER((vader_struct_vader_front_lexer$Token_t*) l7);
        }
    }
    vader_front_lexer$emit(l0, l7);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_lexer$lex_one(void* l0) {
    vader_box_t l1 = vader_box_null(), l4 = vader_box_null();
    void* l2 = NULL;
    void* l8 = NULL;
    bool l3;
    uint32_t l5;
    int64_t l6;
    int32_t l7;
    vader_string_t l9 = 0;
    bool t0;
    uint32_t t1;
    void* t2 = NULL;
    int32_t t3;
    vader_box_t* gc_roots[2] = { &l1, &l4 };
    void** gc_raw_roots[4] = { &l0, &l2, &l8, &t2 };
    vader_string_t* gc_atom_roots[1] = { &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_front_lexer$skip_horizontal(l0);
    t0 = vader_front_lexer$at_end(l0);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l1 = vader_front_lexer$top_interp(l0);
    if (l1.tag == 1186u) {
        t1 = vader_front_lexer$peek(l0);
        if (t1 == 125u) {
            t2 = l1.payload.obj;
            t3 = ((vader_struct_vader_front_lexer$InterpFrame_t*) t2)->f_brace_depth;
            if (t3 == INT32_C(0)) {
                l2 = vader_front_lexer$position_here(l0);
                vader_front_lexer$advance(l0, INT64_C(1));
                vader_front_lexer$push_simple(l0, (uint8_t) 10, 3065u, l2);
                t2 = l1.payload.obj;
                l3 = ((vader_struct_vader_front_lexer$InterpFrame_t*) t2)->f_triple;
                t2 = l1.payload.obj;
                l4 = ((vader_struct_vader_front_lexer$InterpFrame_t*) t2)->f_block;
                vader_front_lexer$pop_interp(l0);
                vader_front_lexer$lex_string_body(l0, l3, false, l4);
                { vader_gc_top = gc_frame.prev; return; }
            }
        }
    } else if (!(l1.tag == 0u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    l5 = vader_front_lexer$peek(l0);
    if (l5 == 10u) {
        l3 = true;
    } else {
        l3 = l5 == 13u;
    }
    if (l3) {
        vader_front_lexer$handle_newline(l0);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l5 == 47u) {
        t1 = vader_front_lexer$peek_at(l0, INT64_C(1));
        if (t1 == 47u) {
            l6 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_pos;
            l7 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_col;
            for (;;) {
                t0 = vader_front_lexer$at_end(l0);
                if (!(t0)) {
                    t1 = vader_front_lexer$peek(l0);
                    if (!(t1 != 10u)) {
                        break;
                    }
                    t1 = vader_front_lexer$peek(l0);
                    if (!(t1 != 13u)) {
                        break;
                    }
                    vader_front_lexer$advance(l0, INT64_C(1));
                    continue;
                }
                break;
            }
            t0 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_include_doc_comments;
            if (t0) {
                vader_front_lexer$note_line_comment(l0, l6, l7);
                { vader_gc_top = gc_frame.prev; return; }
            }
            { vader_gc_top = gc_frame.prev; return; }
        }
    }
    if (l5 == 47u) {
        t1 = vader_front_lexer$peek_at(l0, INT64_C(1));
        if (t1 == 42u) {
            vader_front_lexer$lex_block_comment(l0);
            { vader_gc_top = gc_frame.prev; return; }
        }
    }
    if (l5 == 114u) {
        t1 = vader_front_lexer$peek_at(l0, INT64_C(1));
        if (t1 == 34u) {
            vader_front_lexer$lex_string(l0, true);
            { vader_gc_top = gc_frame.prev; return; }
        }
    }
    t0 = vader_front_lexer$is_ident_start(l5);
    if (t0) {
        vader_front_lexer$lex_ident(l0);
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = std_char$is_digit(l5);
    if (t0) {
        vader_front_lexer$lex_number(l0);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l5 == 39u) {
        vader_front_lexer$lex_char(l0);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l5 == 34u) {
        vader_front_lexer$lex_string(l0, false);
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = vader_front_lexer$try_lex_operator(l0);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l2 = vader_front_lexer$position_here(l0);
    if (l5 == 35u) {
        t1 = vader_front_lexer$peek_at(l0, INT64_C(1));
        if (t1 == 33u) {
            for (;;) {
                t0 = vader_front_lexer$at_end(l0);
                if (!(t0)) {
                    t1 = vader_front_lexer$peek(l0);
                    if (!(t1 != 10u)) {
                        break;
                    }
                    t1 = vader_front_lexer$peek(l0);
                    if (!(t1 != 13u)) {
                        break;
                    }
                    vader_front_lexer$advance(l0, INT64_C(1));
                    continue;
                }
                break;
            }
            l8 = vader_front_lexer$error_span(l0, l2);
            vader_front_lexer$push_error(l0, (uint8_t) 7, l8, 0u);
            { vader_gc_top = gc_frame.prev; return; }
        }
    }
    if (l5 == 92u) {
        vader_front_lexer$advance(l0, INT64_C(1));
        l8 = vader_front_lexer$error_span(l0, l2);
        vader_front_lexer$push_error(l0, (uint8_t) 6, l8, 0u);
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = vader_front_lexer$malformed_here(l0);
    if (t0) {
        vader_front_lexer$advance(l0, INT64_C(1));
        { vader_gc_top = gc_frame.prev; return; }
    }
    for (;;) {
        t0 = vader_front_lexer$at_end(l0);
        if (!(t0)) {
            t1 = vader_front_lexer$peek(l0);
            if (!(t1 == l5)) {
                break;
            }
            t0 = vader_front_lexer$malformed_here(l0);
            if (t0) break;
            vader_front_lexer$advance(l0, INT64_C(1));
            continue;
        }
        break;
    }
    l2 = vader_front_lexer$error_span(l0, l2);
    l9 = vader_front_lexer$codepoint_label(l5);
    vader_front_lexer$push_error(l0, (uint8_t) 0, l2, l9);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_lexer$lex_string(void* l0, bool l1) {
    void* l2 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    bool l3, l5;
    vader_box_t l4 = vader_box_null();
    int64_t l6, l10;
    vader_string_t l9 = 0;
    uint32_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[5] = { &l0, &l2, &l7, &l8, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_front_lexer$position_here(l0);
    if (l1) {
        vader_front_lexer$advance(l0, INT64_C(1));
    }
    vader_front_lexer$advance(l0, INT64_C(1));
    l3 = false;
    l4 = vader_box_obj(0u, NULL);
    t0 = vader_front_lexer$peek(l0);
    if (t0 == 34u) {
        t0 = vader_front_lexer$peek_at(l0, INT64_C(1));
        if (t0 == 34u) {
            l3 = true;
            vader_front_lexer$advance(l0, INT64_C(2));
            t0 = vader_front_lexer$peek(l0);
            if (t0 == 10u) {
                l5 = true;
            } else {
                t0 = vader_front_lexer$peek(l0);
                l5 = t0 == 13u;
            }
            if (l5) {
                l6 = vader_front_lexer$line_break_width(l0);
                vader_front_lexer$advance(l0, l6);
                vader_array_t* _a0_arr = vader_array_new(235u, 0u, 13u, 1190u);
                l7 = (void*) _a0_arr;
                vader_array_t* _a1_arr = vader_array_new(24u, 0u, 8u, 451u);
                l8 = (void*) _a1_arr;
                vader_struct_vader_front_lexer$TextBlock_t* _a2_obj = (vader_struct_vader_front_lexer$TextBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_lexer$TextBlock_t));
                vader_obj_header_init(_a2_obj, 1189u);
                _a2_obj->f_lines = l7;
                _a2_obj->f_common = INT64_C(-1);
                _a2_obj->f_at_line_start = true;
                _a2_obj->f_pending_from = INT64_C(-1);
                _a2_obj->f_part_len = INT64_C(0);
                _a2_obj->f_part_lines = l8;
                t1 = (void*) _a2_obj;
                l4 = vader_ref_box(t1);
            }
        }
    }
    l9 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_src;
    l6 = ((vader_struct_toolchain_span$Position_t*) l2)->f_offset;
    l10 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_pos;
    l9 = vader_host_std_core$byte_slice(l9, l6, l10);
    l7 = vader_front_lexer$position_here(l0);
    vader_struct_toolchain_span$Span_t* _a3_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
    vader_obj_header_init(_a3_obj, 835u);
    _a3_obj->f_start = l2;
    _a3_obj->f_end = l7;
    l2 = (void*) _a3_obj;
    l2 = vader_front_lexer$make_token((uint8_t) 6, l9, l2);
    vader_front_lexer$emit(l0, l2);
    vader_front_lexer$lex_string_body(l0, l3, l1, l4);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_lexer$lex_string_body(void* l0, bool l1, bool l2, vader_box_t l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    void* l19 = NULL;
    void* l23 = NULL;
    void* l24 = NULL;
    void* l25 = NULL;
    void* l26 = NULL;
    void* l27 = NULL;
    void* l28 = NULL;
    void* l29 = NULL;
    void* l30 = NULL;
    void* l31 = NULL;
    void* l32 = NULL;
    void* l33 = NULL;
    void* l34 = NULL;
    void* l35 = NULL;
    void* l36 = NULL;
    bool l6, l8, l20, l21, l38;
    uint32_t l7, l39;
    vader_string_t l11 = 0;
    int64_t l22;
    uint32_t l37;
    void* t0 = NULL;
    bool t1;
    uint32_t t2;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[28] = {
        &l0, &l4, &l5, &l9, &l10, &l12, &l13, &l14, &l15, &l16, &l17, &l18, &l19, &l23, &l24, &l25,
        &l26, &l27, &l28, &l29, &l30, &l31, &l32, &l33, &l34, &l35, &l36, &t0,
    };
    vader_string_t* gc_atom_roots[1] = { &l11 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 28u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = vader_front_lexer$position_here(l0);
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 0u, 447u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string__builder$StringBuilder_t* _a1_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
    vader_obj_header_init(_a1_obj, 741u);
    _a1_obj->f_parts = t0;
    l5 = (void*) _a1_obj;
    l6 = false;
    for (;;) {
        t1 = vader_front_lexer$at_end(l0);
        if (!(t1)) {
            l7 = vader_front_lexer$peek(l0);
            l8 = false;
            if (l1) {
                if (l7 == 34u) {
                    t2 = vader_front_lexer$peek_at(l0, INT64_C(1));
                    if (t2 == 34u) {
                        t2 = vader_front_lexer$peek_at(l0, INT64_C(2));
                        if (t2 == 34u) {
                            l8 = true;
                        }
                    }
                }
            } else if (l7 == 34u) {
                l8 = true;
            }
            if (l8) {
                vader_front_lexer$flush_string_part(l0, l5, l4, l6, l3);
                if (!(l3.tag == 0u)) {
                    l9 = l3.payload.obj;
                    vader_front_lexer$strip_indentation(l0, l9);
                }
                l10 = vader_front_lexer$position_here(l0);
                l11 = 250u;
                if (l1) {
                    vader_front_lexer$advance(l0, INT64_C(3));
                    l11 = 253u;
                } else {
                    vader_front_lexer$advance(l0, INT64_C(1));
                }
                l12 = vader_front_lexer$position_here(l0);
                vader_struct_toolchain_span$Span_t* _a2_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
                vader_obj_header_init(_a2_obj, 835u);
                _a2_obj->f_start = l10;
                _a2_obj->f_end = l12;
                l13 = (void*) _a2_obj;
                l14 = vader_front_lexer$make_token((uint8_t) 8, l11, l13);
                vader_front_lexer$emit(l0, l14);
                { vader_gc_top = gc_frame.prev; return; }
            }
            if (!(l1)) {
                if (l7 == 10u) {
                    l15 = vader_front_lexer$position_here(l0);
                    vader_struct_toolchain_span$Span_t* _a3_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
                    vader_obj_header_init(_a3_obj, 835u);
                    _a3_obj->f_start = l4;
                    _a3_obj->f_end = l15;
                    l16 = (void*) _a3_obj;
                    vader_front_lexer$push_error(l0, (uint8_t) 1, l16, 0u);
                    vader_front_lexer$flush_string_part(l0, l5, l4, l6, l3);
                    l17 = vader_front_lexer$position_here(l0);
                    vader_struct_toolchain_span$Span_t* _a4_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
                    vader_obj_header_init(_a4_obj, 835u);
                    _a4_obj->f_start = l17;
                    _a4_obj->f_end = l17;
                    l18 = (void*) _a4_obj;
                    l19 = vader_front_lexer$make_token((uint8_t) 8, 0u, l18);
                    vader_front_lexer$emit(l0, l19);
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            if (!(l3.tag == 0u)) {
                if (l7 == 32u) {
                    l20 = true;
                } else {
                    l20 = l7 == 9u;
                }
                if (l20) {
                    t0 = l3.payload.obj;
                    vader_front_lexer$hold_blank(t0, l0);
                    vader_front_lexer$advance(l0, INT64_C(1));
                    continue;
                }
                if (l7 == 10u) {
                    l21 = true;
                } else {
                    l21 = l7 == 13u;
                }
                if (l21) {
                    t0 = l3.payload.obj;
                    vader_front_lexer$end_line(t0);
                    l22 = vader_front_lexer$line_break_width(l0);
                    vader_front_lexer$advance(l0, l22);
                    l23 = l3.payload.obj;
                    vader_front_lexer$write_char(l5, 10u, vader_ref_box(l23));
                    l6 = true;
                    continue;
                }
                t0 = l3.payload.obj;
                t1 = vader_front_lexer$settle(t0, l0, l5);
                if (t1) {
                    l6 = true;
                }
            }
            if (!(l2)) {
                if (l7 == 36u) {
                    t2 = vader_front_lexer$peek_at(l0, INT64_C(1));
                    if (t2 == 123u) {
                        vader_front_lexer$flush_string_part(l0, l5, l4, l6, l3);
                        l24 = vader_front_lexer$position_here(l0);
                        vader_front_lexer$advance(l0, INT64_C(2));
                        l25 = vader_front_lexer$position_here(l0);
                        vader_struct_toolchain_span$Span_t* _a5_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
                        vader_obj_header_init(_a5_obj, 835u);
                        _a5_obj->f_start = l24;
                        _a5_obj->f_end = l25;
                        l26 = (void*) _a5_obj;
                        l27 = vader_front_lexer$make_token((uint8_t) 9, 284u, l26);
                        vader_front_lexer$emit(l0, l27);
                        l28 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_interp_stack;
                        vader_struct_vader_front_lexer$InterpFrame_t* _a6_obj = (vader_struct_vader_front_lexer$InterpFrame_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_lexer$InterpFrame_t));
                        vader_obj_header_init(_a6_obj, 1186u);
                        _a6_obj->f_brace_depth = INT32_C(0);
                        _a6_obj->f_triple = l1;
                        _a6_obj->f_block = l3;
                        l29 = (void*) _a6_obj;
                        vader_array_push_ref((vader_array_t*) l28, l29);
                        { vader_gc_top = gc_frame.prev; return; }
                    }
                }
            }
            if (!(l2)) {
                if (l7 == 36u) {
                    t2 = vader_front_lexer$peek_at(l0, INT64_C(1));
                    t1 = vader_front_lexer$is_ident_start(t2);
                    if (t1) {
                        vader_front_lexer$flush_string_part(l0, l5, l4, l6, l3);
                        l30 = vader_front_lexer$position_here(l0);
                        vader_front_lexer$advance(l0, INT64_C(1));
                        l31 = vader_front_lexer$position_here(l0);
                        vader_struct_toolchain_span$Span_t* _a7_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
                        vader_obj_header_init(_a7_obj, 835u);
                        _a7_obj->f_start = l30;
                        _a7_obj->f_end = l31;
                        l32 = (void*) _a7_obj;
                        l33 = vader_front_lexer$make_token((uint8_t) 9, 260u, l32);
                        vader_front_lexer$emit(l0, l33);
                        vader_front_lexer$lex_ident(l0);
                        l34 = vader_front_lexer$position_here(l0);
                        vader_struct_toolchain_span$Span_t* _a8_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
                        vader_obj_header_init(_a8_obj, 835u);
                        _a8_obj->f_start = l34;
                        _a8_obj->f_end = l34;
                        l35 = (void*) _a8_obj;
                        l36 = vader_front_lexer$make_token((uint8_t) 10, 0u, l35);
                        vader_front_lexer$emit(l0, l36);
                        l4 = vader_front_lexer$position_here(l0);
                        vader_array_t* _a9_arr = vader_array_new(22u, 0u, 0u, 447u);
                        t0 = (void*) _a9_arr;
                        vader_struct_std_string__builder$StringBuilder_t* _a10_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
                        vader_obj_header_init(_a10_obj, 741u);
                        _a10_obj->f_parts = t0;
                        l5 = (void*) _a10_obj;
                        l6 = false;
                        continue;
                    }
                }
            }
            if (!(l2)) {
                if (l7 == 92u) {
                    l37 = vader_front_lexer$lex_escape(l0, false);
                    if ((l37 > INT32_C(55295))) {
                        if ((l37 < INT32_C(57344))) {
                            l38 = true;
                        } else {
                            l38 = (l37 > INT32_C(1114111));
                        }
                        if (l38) {
                            vader_unreachable("value out of range: no Unicode scalar value");
                        }
                    }
                    l39 = ((uint32_t) (uint32_t) l37);
                    vader_front_lexer$write_char(l5, l39, l3);
                    l6 = true;
                    continue;
                }
            }
            vader_front_lexer$write_char(l5, l7, l3);
            l6 = true;
            vader_front_lexer$advance(l0, INT64_C(1));
            continue;
        }
        break;
    }
    l9 = vader_front_lexer$position_here(l0);
    vader_struct_toolchain_span$Span_t* _a11_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
    vader_obj_header_init(_a11_obj, 835u);
    _a11_obj->f_start = l4;
    _a11_obj->f_end = l9;
    l9 = (void*) _a11_obj;
    vader_front_lexer$push_error(l0, (uint8_t) 1, l9, 0u);
    vader_front_lexer$flush_string_part(l0, l5, l4, l6, l3);
    l4 = vader_front_lexer$position_here(l0);
    vader_struct_toolchain_span$Span_t* _a12_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
    vader_obj_header_init(_a12_obj, 835u);
    _a12_obj->f_start = l4;
    _a12_obj->f_end = l4;
    l4 = (void*) _a12_obj;
    l4 = vader_front_lexer$make_token((uint8_t) 8, 0u, l4);
    vader_front_lexer$emit(l0, l4);
    { vader_gc_top = gc_frame.prev; return; }
}

static uint32_t vader_front_lexer$lex_unicode_escape(void* l0, void* l1) {
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
    t0 = vader_front_lexer$peek(l0);
    if (t0 != 123u) {
        l2 = vader_front_lexer$error_span(l0, l1);
        vader_front_lexer$push_error(l0, (uint8_t) 8, l2, 1915u);
        { vader_gc_top = gc_frame.prev; return (uint32_t) 0; }
    }
    vader_front_lexer$advance(l0, INT64_C(1));
    l3 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_pos;
    for (;;) {
        t1 = vader_front_lexer$at_end(l0);
        if (!(t1)) {
            t0 = vader_front_lexer$peek(l0);
            if (!(t0 != 125u)) {
                break;
            }
            t0 = vader_front_lexer$peek(l0);
            t2 = std_numbers$hex_digit_value(t0);
            if ((t2 < INT32_C(0))) {
                l2 = vader_front_lexer$error_span(l0, l1);
                vader_front_lexer$push_error(l0, (uint8_t) 8, l2, 2204u);
                for (;;) {
                    t1 = vader_front_lexer$at_end(l0);
                    if (!(t1)) {
                        t0 = vader_front_lexer$peek(l0);
                        if (!(t0 != 125u)) {
                            break;
                        }
                        t0 = vader_front_lexer$peek(l0);
                        if (!(t0 != 10u)) {
                            break;
                        }
                        vader_front_lexer$advance(l0, INT64_C(1));
                        continue;
                    }
                    break;
                }
                t0 = vader_front_lexer$peek(l0);
                if (t0 == 125u) {
                    vader_front_lexer$advance(l0, INT64_C(1));
                    { vader_gc_top = gc_frame.prev; return (uint32_t) 0; }
                }
                { vader_gc_top = gc_frame.prev; return (uint32_t) 0; }
            }
            vader_front_lexer$advance(l0, INT64_C(1));
            continue;
        }
        break;
    }
    t3 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_pos;
    l4 = vader_chk_sub(i64, t3, l3);
    t0 = vader_front_lexer$peek(l0);
    if (t0 == 125u) {
        vader_front_lexer$advance(l0, INT64_C(1));
    }
    if (l4 == INT64_C(0)) {
        l5 = true;
    } else {
        l5 = (l4 > INT64_C(6));
    }
    if (l5) {
        l2 = vader_front_lexer$error_span(l0, l1);
        vader_front_lexer$push_error(l0, (uint8_t) 8, l2, 1766u);
        { vader_gc_top = gc_frame.prev; return (uint32_t) 0; }
    }
    l6 = (uint32_t) 0;
    l7 = INT64_C(0);
    while ((l7 < l4)) {
        l8 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_src;
        l9 = vader_chk_add(i64, l3, l7);
        t4 = vader_host_std_core$byte_at(l8, l9);
        l10 = std_numbers$hex_digit_value(((uint32_t) (uint8_t) t4));
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
        l2 = vader_front_lexer$error_span(l0, l1);
        vader_front_lexer$push_error(l0, (uint8_t) 8, l2, 1767u);
        { vader_gc_top = gc_frame.prev; return (uint32_t) 0; }
    }
    t1 = std_string$is_surrogate(l6);
    if (!(t1)) {
        { uint32_t __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = vader_front_lexer$error_span(l0, l1);
    vader_front_lexer$push_error(l0, (uint8_t) 8, l2, 1768u);
    { vader_gc_top = gc_frame.prev; return (uint32_t) 0; }
}

static int64_t vader_front_lexer$line_break_width(void* l0) {
    uint32_t t0;
    t0 = vader_front_lexer$peek(l0);
    if (t0 == 13u) {
        t0 = vader_front_lexer$peek_at(l0, INT64_C(1));
        if (t0 == 10u) {
            return INT64_C(2);
        }
        return INT64_C(1);
    }
    return INT64_C(1);
}

static uint8_t vader_front_lexer$lookup_keyword(vader_string_t l0) {
    if (l0 == 2009u) {
        return (uint8_t) 11;
    }
    if (l0 == 2655u) {
        return (uint8_t) 12;
    }
    if (l0 == 2738u) {
        return (uint8_t) 13;
    }
    if (l0 == 2137u) {
        return (uint8_t) 14;
    }
    if (l0 == 1888u) {
        return (uint8_t) 15;
    }
    if (l0 == 2129u) {
        return (uint8_t) 16;
    }
    if (l0 == 1859u) {
        return (uint8_t) 17;
    }
    if (l0 == 2311u) {
        return (uint8_t) 18;
    }
    if (l0 == 2207u) {
        return (uint8_t) 19;
    }
    if (l0 == 2020u) {
        return (uint8_t) 20;
    }
    if (l0 == 2147u) {
        return (uint8_t) 21;
    }
    if (l0 == 2524u) {
        return (uint8_t) 22;
    }
    if (l0 == 3051u) {
        return (uint8_t) 23;
    }
    if (l0 == 1611u) {
        return (uint8_t) 24;
    }
    if (l0 == 1827u) {
        return (uint8_t) 25;
    }
    if (l0 == 1646u) {
        return (uint8_t) 26;
    }
    if (l0 == 1803u) {
        return (uint8_t) 27;
    }
    if (l0 == 2139u) {
        return (uint8_t) 28;
    }
    if (l0 == 1595u) {
        return (uint8_t) 29;
    }
    if (l0 == 1938u) {
        return (uint8_t) 30;
    }
    if (l0 == 2744u) {
        return (uint8_t) 31;
    }
    if (l0 == 1974u) {
        return (uint8_t) 32;
    }
    if (l0 == 2413u) {
        return (uint8_t) 33;
    }
    if (l0 == 2545u) {
        return (uint8_t) 34;
    }
    if (!(l0 == 1794u)) {
        return (uint8_t) 2;
    }
    return (uint8_t) 35;
}

static void* vader_front_lexer$make_token(uint8_t l0, vader_string_t l1, void* l2) {
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_vader_front_lexer$Token_t* _a0_obj = (vader_struct_vader_front_lexer$Token_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_lexer$Token_t));
    vader_obj_header_init(_a0_obj, 1191u);
    _a0_obj->f_kind = l0;
    _a0_obj->f_text = l1;
    _a0_obj->f_span = l2;
    _a0_obj->f_value = vader_box_obj(0u, NULL);
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_front_lexer$malformed_here(void* l0) {
    vader_string_t l1;
    int64_t l2, l4;
    uint32_t l3;
    uint8_t l5;
    uint32_t t0;
    int64_t t1;
    bool t2;
    l1 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_src;
    l2 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_pos;
    std_core$codepoint_at_byte(l1, l2, &t0, &t1);
    l4 = t1;
    l3 = t0;
    l2 = l4;
    l1 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_src;
    l4 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_pos;
    l5 = vader_host_std_core$byte_at(l1, l4);
    t2 = vader_front_lexer$is_malformed_utf8(l3, l2, l5);
    return t2;
}

static vader_string_t vader_front_lexer$malformed_utf8_detail(int32_t l0) {
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
        l2 = std_core$write_string_at(l1, l2, 2714u);
        l3 = ((int64_t) (int32_t) l0);
        l2 = std_core$write_int(l1, l2, l3);
        l2 = std_core$write_string_at(l1, l2, 172u);
        t0 = std_core$finish_buffer(l1, l2);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return 0u; }
}

static void vader_front_lexer$note_line_comment(void* l0, int64_t l1, int32_t l2) {
    vader_string_t l3 = 0;
    int32_t l4;
    void* l5 = NULL;
    void* l8 = NULL;
    int64_t l6, l7;
    vader_box_t l9 = vader_box_null();
    vader_string_t t0 = 0;
    bool t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &l9 };
    void** gc_raw_roots[4] = { &l0, &l5, &l8, &t2 };
    vader_string_t* gc_atom_roots[2] = { &l3, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_src;
    t1 = std_string$matches_at(t0, l1, 448u);
    if (!(t1)) {
        ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_open_doc = vader_box_obj(0u, NULL);
        VADER_WRITE_BARRIER((vader_struct_vader_front_lexer$Lexer_t*) l0);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_file;
    l4 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_line;
    vader_struct_toolchain_span$Position_t* _a0_obj = (vader_struct_toolchain_span$Position_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Position_t));
    vader_obj_header_init(_a0_obj, 834u);
    _a0_obj->f_file = l3;
    _a0_obj->f_offset = l1;
    _a0_obj->f_line = l4;
    _a0_obj->f_column = l2;
    l5 = (void*) _a0_obj;
    l3 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_src;
    l6 = vader_chk_add(i64, l1, INT64_C(3));
    l7 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_pos;
    l3 = vader_host_std_core$byte_slice(l3, l6, l7);
    l8 = vader_front_lexer$position_here(l0);
    vader_struct_toolchain_span$Span_t* _a1_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
    vader_obj_header_init(_a1_obj, 835u);
    _a1_obj->f_start = l5;
    _a1_obj->f_end = l8;
    l5 = (void*) _a1_obj;
    vader_struct_toolchain_ast$DocCommentLine_t* _a2_obj = (vader_struct_toolchain_ast$DocCommentLine_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$DocCommentLine_t));
    vader_obj_header_init(_a2_obj, 765u);
    _a2_obj->f_text = l3;
    _a2_obj->f_span = l5;
    l5 = (void*) _a2_obj;
    l9 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_open_doc;
    if (!(l9.tag == 0u)) {
        t2 = l9.payload.obj;
        vader_array_push_ref((vader_array_t*) ((vader_struct_toolchain_ast$DocComment_t*) t2)->f_lines, l5);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_t* _a3_arr = vader_array_new(45u, 1u, 13u, 765u);
    ((void**) _a3_arr->buf->slots)[_a3_arr->offset + 0u] = l5;
    t2 = (void*) _a3_arr;
    vader_struct_toolchain_ast$DocComment_t* _a4_obj = (vader_struct_toolchain_ast$DocComment_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$DocComment_t));
    vader_obj_header_init(_a4_obj, 764u);
    _a4_obj->f_lines = t2;
    l5 = (void*) _a4_obj;
    ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_open_doc = vader_ref_box(l5);
    VADER_WRITE_BARRIER((vader_struct_vader_front_lexer$Lexer_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
}

static uint32_t vader_front_lexer$peek(void* l0) {
    int64_t l1, l2;
    vader_string_t l3;
    uint8_t l4;
    vader_string_t t0;
    uint32_t t1;
    int64_t t2;
    l1 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_pos;
    t0 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_src;
    l2 = vader_host_std_core$byte_len(t0);
    if ((l1 >= l2)) {
        return 0u;
    }
    l3 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_src;
    l1 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_pos;
    l4 = vader_host_std_core$byte_at(l3, l1);
    if (!((l4 < INT32_C(128)))) {
        l3 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_src;
        l1 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_pos;
        std_core$codepoint_at_byte(l3, l1, &t1, &t2);
        return t1;
    }
    return ((uint32_t) (uint8_t) l4);
}

static uint32_t vader_front_lexer$peek_at(void* l0, int64_t l1) {
    int64_t l2, l3;
    uint8_t l4;
    int64_t t0;
    vader_string_t t1;
    uint32_t t2;
    t0 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_pos;
    l2 = vader_chk_add(i64, t0, l1);
    t1 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_src;
    l3 = vader_host_std_core$byte_len(t1);
    if ((l2 >= l3)) {
        return 0u;
    }
    t1 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_src;
    l4 = vader_host_std_core$byte_at(t1, l2);
    if (!((l4 < INT32_C(128)))) {
        t1 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_src;
        std_core$codepoint_at_byte(t1, l2, &t2, &t0);
        return t2;
    }
    return ((uint32_t) (uint8_t) l4);
}

static void vader_front_lexer$pop_interp(void* l0) {
    vader_box_t t0;
    t0 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_interp_stack);
    return;
}

static void* vader_front_lexer$position_here(void* l0) {
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
    l1 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_file;
    l2 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_pos;
    l3 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_line;
    l4 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_col;
    vader_struct_toolchain_span$Position_t* _a0_obj = (vader_struct_toolchain_span$Position_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Position_t));
    vader_obj_header_init(_a0_obj, 834u);
    _a0_obj->f_file = l1;
    _a0_obj->f_offset = l2;
    _a0_obj->f_line = l3;
    _a0_obj->f_column = l4;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_front_lexer$push_error(void* l0, uint8_t l1, void* l2, vader_string_t l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    void** gc_raw_roots[4] = { &l0, &l2, &l4, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_errors;
    l5 = vader_support_diagnostics$lexer_error(l1, l2, l3);
    vader_array_push_ref((vader_array_t*) l4, l5);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_lexer$push_simple(void* l0, uint8_t l1, vader_string_t l2, void* l3) {
    void* l4 = NULL;
    void** gc_raw_roots[3] = { &l0, &l3, &l4 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = vader_front_lexer$position_here(l0);
    vader_struct_toolchain_span$Span_t* _a0_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
    vader_obj_header_init(_a0_obj, 835u);
    _a0_obj->f_start = l3;
    _a0_obj->f_end = l4;
    l4 = (void*) _a0_obj;
    l4 = vader_front_lexer$make_token(l1, l2, l4);
    vader_front_lexer$emit(l0, l4);
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_front_lexer$run_lexer(void* l0) {
    vader_string_t l1 = 0;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    int32_t t0;
    uint32_t t1;
    bool t2;
    void* t3 = NULL;
    void** gc_raw_roots[5] = { &l0, &l2, &l3, &l4, &t3 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_front_lexer$skip_bom(l0);
    t0 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_line;
    if (t0 == INT32_C(1)) {
        t1 = vader_front_lexer$peek(l0);
        if (t1 == 35u) {
            t1 = vader_front_lexer$peek_at(l0, INT64_C(1));
            if (t1 == 33u) {
                for (;;) {
                    t2 = vader_front_lexer$at_end(l0);
                    if (!(t2)) {
                        t1 = vader_front_lexer$peek(l0);
                        if (!(t1 != 10u)) {
                            break;
                        }
                        vader_front_lexer$advance(l0, INT64_C(1));
                        continue;
                    }
                    break;
                }
            }
        }
    }
    for (;;) {
        t2 = vader_front_lexer$at_end(l0);
        if (!(t2)) {
            vader_front_lexer$lex_one(l0);
            continue;
        }
        break;
    }
    t0 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_malformed_utf8_runs;
    if ((t0 > INT32_C(0))) {
        t0 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_malformed_utf8_runs;
        l1 = vader_front_lexer$malformed_utf8_detail(t0);
        l2 = vader_front_lexer$first_malformed_utf8(l0);
        vader_front_lexer$push_error(l0, (uint8_t) 10, l2, l1);
    }
    l2 = vader_front_lexer$position_here(l0);
    vader_struct_toolchain_span$Span_t* _a0_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
    vader_obj_header_init(_a0_obj, 835u);
    _a0_obj->f_start = l2;
    _a0_obj->f_end = l2;
    l2 = (void*) _a0_obj;
    l2 = vader_front_lexer$make_token((uint8_t) 0, 0u, l2);
    vader_front_lexer$emit(l0, l2);
    l1 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_file;
    l2 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_tokens;
    l3 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_errors;
    l4 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_doc_runs;
    vader_struct_vader_front_lexer$LexedSource_t* _a1_obj = (vader_struct_vader_front_lexer$LexedSource_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_lexer$LexedSource_t));
    vader_obj_header_init(_a1_obj, 1187u);
    _a1_obj->f_file = l1;
    _a1_obj->f_tokens = l2;
    _a1_obj->f_errors = l3;
    _a1_obj->f_doc_runs = l4;
    t3 = (void*) _a1_obj;
    { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_front_lexer$settle(void* l0, void* l1, void* l2) {
    int64_t l3, l5, l7;
    void* l4 = NULL;
    vader_string_t l6 = 0;
    bool t0;
    int64_t t1;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l4 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_front_lexer$held_width(l0, l1);
    t0 = ((vader_struct_vader_front_lexer$TextBlock_t*) l0)->f_at_line_start;
    if (t0) {
        l4 = ((vader_struct_vader_front_lexer$TextBlock_t*) l0)->f_part_lines;
        l5 = ((vader_struct_vader_front_lexer$TextBlock_t*) l0)->f_part_len;
        vader_array_push_i64((vader_array_t*) l4, l5);
        vader_front_lexer$count_indentation(l0, l3);
        ((vader_struct_vader_front_lexer$TextBlock_t*) l0)->f_at_line_start = false;
    }
    if (!(l3 == INT64_C(0))) {
        l6 = ((vader_struct_vader_front_lexer$Lexer_t*) l1)->f_src;
        l5 = ((vader_struct_vader_front_lexer$TextBlock_t*) l0)->f_pending_from;
        l7 = ((vader_struct_vader_front_lexer$Lexer_t*) l1)->f_pos;
        l6 = vader_host_std_core$byte_slice(l6, l5, l7);
        std_string__builder$append(l2, l6);
        t1 = ((vader_struct_vader_front_lexer$TextBlock_t*) l0)->f_part_len;
        l3 = vader_chk_add(i64, t1, l3);
        ((vader_struct_vader_front_lexer$TextBlock_t*) l0)->f_part_len = l3;
        ((vader_struct_vader_front_lexer$TextBlock_t*) l0)->f_pending_from = INT64_C(-1);
        { vader_gc_top = gc_frame.prev; return true; }
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static void vader_front_lexer$skip_bom(void* l0) {
    uint32_t t0;
    t0 = vader_front_lexer$peek(l0);
    if (t0 == 65279u) {
        ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_pos = INT64_C(3);
        return;
    }
    return;
}

static void vader_front_lexer$skip_horizontal(void* l0) {
    bool l1, l3, l4, l5;
    uint32_t l2;
    bool t0;
    l1 = vader_front_lexer$in_interp_expression(l0);
    for (;;) {
        t0 = vader_front_lexer$at_end(l0);
        if (!(t0)) {
            l2 = vader_front_lexer$peek(l0);
            if (l2 == 32u) {
                l3 = true;
            } else {
                l3 = l2 == 9u;
            }
            if (l3) {
                vader_front_lexer$advance(l0, INT64_C(1));
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
            vader_front_lexer$advance(l0, INT64_C(1));
            continue;
        }
        break;
    }
    return;
}

static void vader_front_lexer$strip_indentation(void* l0, void* l1) {
    int64_t l2, l3, l4, l5, l9, l10, l11, l13, l14;
    void* l6 = NULL;
    void* l8 = NULL;
    vader_string_t l7 = 0;
    vader_string_t l12 = 0;
    vader_string_t l15 = 0;
    vader_string_t l16 = 0;
    bool t0;
    int64_t t1;
    void* t2 = NULL;
    void** gc_raw_roots[5] = { &l0, &l1, &l6, &l8, &t2 };
    vader_string_t* gc_atom_roots[4] = { &l7, &l12, &l15, &l16 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_front_lexer$TextBlock_t*) l1)->f_at_line_start;
    if (t0) {
        l2 = vader_front_lexer$held_width(l1, l0);
        vader_front_lexer$count_indentation(l1, l2);
    }
    t1 = ((vader_struct_vader_front_lexer$TextBlock_t*) l1)->f_common;
    if ((t1 <= INT64_C(0))) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l2 = INT64_C(-1);
    l3 = INT64_C(0);
    for (;;) {
        l4 = ((vader_array_t*) ((vader_struct_vader_front_lexer$TextBlock_t*) l1)->f_lines)->length;
        if ((l3 < l4)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_front_lexer$TextBlock_t*) l1)->f_lines);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
            l5 = ((vader_struct_vader_front_lexer$TextBlockLine_t*) t2)->f_part;
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_tokens);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
            l6 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
            l7 = ((vader_struct_vader_front_lexer$Token_t*) l6)->f_text;
            vader_array_t* _a2_arr = vader_array_new(22u, 0u, 0u, 447u);
            t2 = (void*) _a2_arr;
            vader_struct_std_string__builder$StringBuilder_t* _a3_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
            vader_obj_header_init(_a3_obj, 741u);
            _a3_obj->f_parts = t2;
            l8 = (void*) _a3_obj;
            l9 = INT64_C(0);
            for (;;) {
                l10 = ((vader_array_t*) ((vader_struct_vader_front_lexer$TextBlock_t*) l1)->f_lines)->length;
                if ((l3 < l10)) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_front_lexer$TextBlock_t*) l1)->f_lines);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l3)
                    t2 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l3);
                    t1 = ((vader_struct_vader_front_lexer$TextBlockLine_t*) t2)->f_part;
                    if (!(t1 == l5)) {
                        break;
                    }
                    vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_front_lexer$TextBlock_t*) l1)->f_lines);
                    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l3)
                    t2 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l3);
                    l11 = ((vader_struct_vader_front_lexer$TextBlockLine_t*) t2)->f_offset;
                    l12 = vader_host_std_core$byte_slice(l7, l9, l11);
                    std_string__builder$append(l8, l12);
                    l13 = ((vader_struct_vader_front_lexer$TextBlock_t*) l1)->f_common;
                    l9 = vader_chk_add(i64, l11, l13);
                    l3 = vader_chk_add(i64, l3, INT64_C(1));
                    continue;
                }
                break;
            }
            l14 = vader_host_std_core$byte_len(l7);
            l15 = vader_host_std_core$byte_slice(l7, l9, l14);
            std_string__builder$append(l8, l15);
            l16 = std_string__builder$StringBuilder$std_core$Display$to_string(l8);
            ((vader_struct_vader_front_lexer$Token_t*) l6)->f_text = l16;
            ((vader_struct_vader_front_lexer$Token_t*) l6)->f_value = vader_box_string(447u, l16);
            VADER_WRITE_BARRIER((vader_struct_vader_front_lexer$Token_t*) l6);
            if (!(l16 == 0u)) {
                continue;
            }
            if (!((l2 < INT64_C(0)))) {
                continue;
            }
            l2 = l5;
            continue;
        }
        break;
    }
    if ((l2 >= INT64_C(0))) {
        vader_front_lexer$drop_empty_parts(l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_front_lexer$suppresses_newline_after(uint8_t l0) {
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
        l1 = l0 == INT32_C(87);
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
        l1 = l0 == INT32_C(85);
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

void* vader_front_lexer$tokenize(vader_string_t l0, vader_string_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* t0 = NULL;
    void* t1 = NULL;
    void** gc_raw_roots[7] = { &l2, &l3, &l4, &l5, &l6, &t0, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 7u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(23u, 0u, 7u, 450u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(236u, 0u, 13u, 1191u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(328u, 0u, 13u, 1524u);
    l4 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(234u, 0u, 13u, 1186u);
    l5 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(233u, 0u, 13u, 1185u);
    l6 = (void*) _a4_arr;
    vader_struct_vader_front_lexer$Lexer_t* _a5_obj = (vader_struct_vader_front_lexer$Lexer_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_lexer$Lexer_t));
    vader_obj_header_init(_a5_obj, 1188u);
    _a5_obj->f_src = l0;
    _a5_obj->f_file = l1;
    _a5_obj->f_pos = INT64_C(0);
    _a5_obj->f_line = INT32_C(1);
    _a5_obj->f_col = INT32_C(1);
    _a5_obj->f_paren_depth = INT32_C(0);
    _a5_obj->f_enclosing_paren_depths = l2;
    _a5_obj->f_last_kind = (uint8_t) 1;
    _a5_obj->f_pending_newline = vader_box_obj(0u, NULL);
    _a5_obj->f_malformed_utf8_runs = INT32_C(0);
    _a5_obj->f_malformed_utf8_at = INT64_C(0);
    _a5_obj->f_tokens = l3;
    _a5_obj->f_errors = l4;
    _a5_obj->f_interp_stack = l5;
    _a5_obj->f_include_doc_comments = false;
    _a5_obj->f_doc_runs = l6;
    _a5_obj->f_open_doc = vader_box_obj(0u, NULL);
    t0 = (void*) _a5_obj;
    t1 = vader_front_lexer$run_lexer(t0);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_front_lexer$tokenize_with_docs(vader_string_t l0, vader_string_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* t0 = NULL;
    void* t1 = NULL;
    void** gc_raw_roots[7] = { &l2, &l3, &l4, &l5, &l6, &t0, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 7u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(23u, 0u, 7u, 450u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(236u, 0u, 13u, 1191u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(328u, 0u, 13u, 1524u);
    l4 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(234u, 0u, 13u, 1186u);
    l5 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(233u, 0u, 13u, 1185u);
    l6 = (void*) _a4_arr;
    vader_struct_vader_front_lexer$Lexer_t* _a5_obj = (vader_struct_vader_front_lexer$Lexer_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_lexer$Lexer_t));
    vader_obj_header_init(_a5_obj, 1188u);
    _a5_obj->f_src = l0;
    _a5_obj->f_file = l1;
    _a5_obj->f_pos = INT64_C(0);
    _a5_obj->f_line = INT32_C(1);
    _a5_obj->f_col = INT32_C(1);
    _a5_obj->f_paren_depth = INT32_C(0);
    _a5_obj->f_enclosing_paren_depths = l2;
    _a5_obj->f_last_kind = (uint8_t) 1;
    _a5_obj->f_pending_newline = vader_box_obj(0u, NULL);
    _a5_obj->f_malformed_utf8_runs = INT32_C(0);
    _a5_obj->f_malformed_utf8_at = INT64_C(0);
    _a5_obj->f_tokens = l3;
    _a5_obj->f_errors = l4;
    _a5_obj->f_interp_stack = l5;
    _a5_obj->f_include_doc_comments = true;
    _a5_obj->f_doc_runs = l6;
    _a5_obj->f_open_doc = vader_box_obj(0u, NULL);
    t0 = (void*) _a5_obj;
    t1 = vader_front_lexer$run_lexer(t0);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_lexer$top_interp(void* l0) {
    int64_t l1;
    void* l2;
    void* t0;
    l1 = ((vader_array_t*) ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_interp_stack)->length;
    if (!(l1 == INT64_C(0))) {
        l2 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_interp_stack;
        l1 = vader_chk_sub(i64, l1, INT64_C(1));
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
        return vader_ref_box(t0);
    }
    return vader_box_obj(0u, NULL);
}

static bool vader_front_lexer$try_lex_operator(void* l0) {
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
    l1 = vader_front_lexer$peek(l0);
    l2 = vader_front_lexer$peek_at(l0, INT64_C(1));
    if (l1 == 46u) {
        if (l2 == 46u) {
            l3 = vader_front_lexer$peek_at(l0, INT64_C(2));
            if (l3 == 60u) {
                t0 = vader_front_lexer$emit_and_advance(l0, (uint8_t) 73, 404u);
                { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l3 == 61u) {
                t0 = vader_front_lexer$emit_and_advance(l0, (uint8_t) 74, 405u);
                { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l3 == 46u) {
                t0 = vader_front_lexer$emit_and_advance(l0, (uint8_t) 75, 402u);
                { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
    }
    if (l2 == 61u) {
        t1 = vader_front_lexer$peek_at(l0, INT64_C(2));
        if (t1 == 61u) {
            if (l1 == 61u) {
                t0 = vader_front_lexer$emit_and_advance(l0, (uint8_t) 56, 524u);
                { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l1 == 33u) {
                t0 = vader_front_lexer$emit_and_advance(l0, (uint8_t) 57, 248u);
                { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
    }
    if (l2 == 37u) {
        t1 = vader_front_lexer$peek_at(l0, INT64_C(2));
        if (t1 == 61u) {
            if (l1 == 43u) {
                t0 = vader_front_lexer$emit_and_advance(l0, (uint8_t) 68, 358u);
                { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l1 == 45u) {
                t0 = vader_front_lexer$emit_and_advance(l0, (uint8_t) 69, 388u);
                { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l1 == 42u) {
                t0 = vader_front_lexer$emit_and_advance(l0, (uint8_t) 70, 354u);
                { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
        if (l1 == 43u) {
            t0 = vader_front_lexer$emit_and_advance(l0, (uint8_t) 41, 357u);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l1 == 45u) {
            t0 = vader_front_lexer$emit_and_advance(l0, (uint8_t) 42, 387u);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l1 == 42u) {
            t0 = vader_front_lexer$emit_and_advance(l0, (uint8_t) 43, 353u);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (l1 == 61u) {
        if (l2 == 61u) {
            t0 = vader_front_lexer$emit_and_advance(l0, (uint8_t) 50, 523u);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (l1 == 33u) {
        if (l2 == 61u) {
            t0 = vader_front_lexer$emit_and_advance(l0, (uint8_t) 51, 247u);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (l1 == 60u) {
        if (l2 == 61u) {
            t0 = vader_front_lexer$emit_and_advance(l0, (uint8_t) 53, 507u);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (l1 == 62u) {
        if (l2 == 61u) {
            t0 = vader_front_lexer$emit_and_advance(l0, (uint8_t) 55, 527u);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (l1 == 38u) {
        if (l2 == 38u) {
            t0 = vader_front_lexer$emit_and_advance(l0, (uint8_t) 58, 288u);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (l1 == 124u) {
        if (l2 == 124u) {
            t0 = vader_front_lexer$emit_and_advance(l0, (uint8_t) 59, 3064u);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (l1 == 63u) {
        if (l2 == 63u) {
            t0 = vader_front_lexer$emit_and_advance(l0, (uint8_t) 61, 531u);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (l1 == 60u) {
        if (l2 == 60u) {
            t0 = vader_front_lexer$emit_and_advance(l0, (uint8_t) 48, 506u);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (l1 == 62u) {
        if (l2 == 62u) {
            t0 = vader_front_lexer$emit_and_advance(l0, (uint8_t) 49, 528u);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (l1 == 45u) {
        if (l2 == 62u) {
            t0 = vader_front_lexer$emit_and_advance(l0, (uint8_t) 76, 391u);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (l1 == 61u) {
        if (l2 == 62u) {
            t0 = vader_front_lexer$emit_and_advance(l0, (uint8_t) 77, 525u);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (l1 == 58u) {
        if (l2 == 58u) {
            t0 = vader_front_lexer$emit_and_advance(l0, (uint8_t) 71, 498u);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (l1 == 58u) {
        if (l2 == 61u) {
            t0 = vader_front_lexer$emit_and_advance(l0, (uint8_t) 72, 500u);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (l1 == 43u) {
        if (l2 == 61u) {
            t0 = vader_front_lexer$emit_and_advance(l0, (uint8_t) 63, 359u);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (l1 == 45u) {
        if (l2 == 61u) {
            t0 = vader_front_lexer$emit_and_advance(l0, (uint8_t) 64, 390u);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (l1 == 42u) {
        if (l2 == 61u) {
            t0 = vader_front_lexer$emit_and_advance(l0, (uint8_t) 65, 355u);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (l1 == 47u) {
        if (l2 == 61u) {
            t0 = vader_front_lexer$emit_and_advance(l0, (uint8_t) 66, 451u);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (l1 == 37u) {
        if (l2 == 61u) {
            t0 = vader_front_lexer$emit_and_advance(l0, (uint8_t) 67, 286u);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (l1 == 43u) {
        t0 = vader_front_lexer$emit_and_advance(l0, (uint8_t) 36, 356u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 45u) {
        t0 = vader_front_lexer$emit_and_advance(l0, (uint8_t) 37, 386u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 42u) {
        t0 = vader_front_lexer$emit_and_advance(l0, (uint8_t) 38, 352u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 47u) {
        t0 = vader_front_lexer$emit_and_advance(l0, (uint8_t) 39, 441u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 37u) {
        t0 = vader_front_lexer$emit_and_advance(l0, (uint8_t) 40, 285u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 38u) {
        t0 = vader_front_lexer$emit_and_advance(l0, (uint8_t) 44, 287u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 124u) {
        t0 = vader_front_lexer$emit_and_advance(l0, (uint8_t) 45, 3063u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 94u) {
        t0 = vader_front_lexer$emit_and_advance(l0, (uint8_t) 46, 975u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 126u) {
        t0 = vader_front_lexer$emit_and_advance(l0, (uint8_t) 47, 3070u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 60u) {
        t0 = vader_front_lexer$emit_and_advance(l0, (uint8_t) 52, 505u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 62u) {
        t0 = vader_front_lexer$emit_and_advance(l0, (uint8_t) 54, 526u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 33u) {
        t0 = vader_front_lexer$emit_and_advance(l0, (uint8_t) 60, 246u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 61u) {
        t0 = vader_front_lexer$emit_and_advance(l0, (uint8_t) 62, 521u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 64u) {
        t0 = vader_front_lexer$emit_and_advance(l0, (uint8_t) 78, 532u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 58u) {
        t0 = vader_front_lexer$emit_and_advance(l0, (uint8_t) 87, 462u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 44u) {
        t0 = vader_front_lexer$emit_and_advance(l0, (uint8_t) 85, 361u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 46u) {
        t0 = vader_front_lexer$emit_and_advance(l0, (uint8_t) 86, 400u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 40u) {
        l4 = vader_front_lexer$position_here(l0);
        vader_front_lexer$advance(l0, INT64_C(1));
        t2 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_paren_depth;
        l5 = vader_chk_add(i32, t2, INT32_C(1));
        ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_paren_depth = l5;
        vader_front_lexer$push_simple(l0, (uint8_t) 79, 307u, l4);
        { vader_gc_top = gc_frame.prev; return true; }
    }
    if (l1 == 91u) {
        l4 = vader_front_lexer$position_here(l0);
        vader_front_lexer$advance(l0, INT64_C(1));
        t2 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_paren_depth;
        l5 = vader_chk_add(i32, t2, INT32_C(1));
        ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_paren_depth = l5;
        vader_front_lexer$push_simple(l0, (uint8_t) 81, 964u, l4);
        { vader_gc_top = gc_frame.prev; return true; }
    }
    if (l1 == 41u) {
        l4 = vader_front_lexer$position_here(l0);
        vader_front_lexer$advance(l0, INT64_C(1));
        t2 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_paren_depth;
        if ((t2 > INT32_C(0))) {
            t2 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_paren_depth;
            l5 = vader_chk_sub(i32, t2, INT32_C(1));
            ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_paren_depth = l5;
        }
        vader_front_lexer$push_simple(l0, (uint8_t) 80, 324u, l4);
        { vader_gc_top = gc_frame.prev; return true; }
    }
    if (l1 == 93u) {
        l4 = vader_front_lexer$position_here(l0);
        vader_front_lexer$advance(l0, INT64_C(1));
        t2 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_paren_depth;
        if ((t2 > INT32_C(0))) {
            t2 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_paren_depth;
            l5 = vader_chk_sub(i32, t2, INT32_C(1));
            ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_paren_depth = l5;
        }
        vader_front_lexer$push_simple(l0, (uint8_t) 82, 967u, l4);
        { vader_gc_top = gc_frame.prev; return true; }
    }
    if (l1 == 123u) {
        l6 = vader_front_lexer$top_interp(l0);
        if (l6.tag == 1186u) {
            l4 = l6.payload.obj;
            t3 = l6.payload.obj;
            t2 = ((vader_struct_vader_front_lexer$InterpFrame_t*) t3)->f_brace_depth;
            l5 = vader_chk_add(i32, t2, INT32_C(1));
            ((vader_struct_vader_front_lexer$InterpFrame_t*) l4)->f_brace_depth = l5;
        }
        l4 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_enclosing_paren_depths;
        l5 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_paren_depth;
        vader_array_push_i32((vader_array_t*) l4, l5);
        ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_paren_depth = INT32_C(0);
        t0 = vader_front_lexer$emit_and_advance(l0, (uint8_t) 83, 3055u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l1 == 125u)) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    l6 = vader_front_lexer$top_interp(l0);
    if (l6.tag == 1186u) {
        t3 = l6.payload.obj;
        t2 = ((vader_struct_vader_front_lexer$InterpFrame_t*) t3)->f_brace_depth;
        if ((t2 > INT32_C(0))) {
            l4 = l6.payload.obj;
            t3 = l6.payload.obj;
            t2 = ((vader_struct_vader_front_lexer$InterpFrame_t*) t3)->f_brace_depth;
            l5 = vader_chk_sub(i32, t2, INT32_C(1));
            ((vader_struct_vader_front_lexer$InterpFrame_t*) l4)->f_brace_depth = l5;
        }
    }
    l6 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_enclosing_paren_depths);
    if (l6.tag == 0u) {
        l5 = ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_paren_depth;
    } else {
        l5 = ((int32_t) l6.payload.i);
    }
    ((vader_struct_vader_front_lexer$Lexer_t*) l0)->f_paren_depth = l5;
    t0 = vader_front_lexer$emit_and_advance(l0, (uint8_t) 84, 3065u);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_front_lexer$write_char(void* l0, uint32_t l1, vader_box_t l2) {
    void* l3 = NULL;
    int64_t l4, l5;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[3] = { &l0, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_string__builder$append_char(l0, l1);
    if (l2.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = l2.payload.obj;
    t0 = l2.payload.obj;
    l4 = ((vader_struct_vader_front_lexer$TextBlock_t*) t0)->f_part_len;
    l5 = std_string$codepoint_byte_len(l1);
    l4 = vader_chk_add(i64, l4, l5);
    ((vader_struct_vader_front_lexer$TextBlock_t*) l3)->f_part_len = l4;
    { vader_gc_top = gc_frame.prev; return; }
}
