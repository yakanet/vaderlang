#include "bootstrap.split.h"

static void vader_lexer_advance(void* l0, size_t l1);
static bool vader_lexer_at_end(void* l0);
static void vader_lexer_consume_digits(void* l0, int32_t l1, void* l2);
static void vader_lexer_emit(void* l0, void* l1);
static bool vader_lexer_emit_and_advance(void* l0, uint8_t l1, vader_string_t l2);
static void* vader_lexer_error_span(void* l0, void* l1);
static void vader_lexer_flush_string_part(void* l0, void* l1, void* l2, bool l3);
static void vader_lexer_handle_newline(void* l0);
static bool vader_lexer_is_ident_continue(uint32_t l0);
static bool vader_lexer_is_ident_start(uint32_t l0);
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
static void* vader_lexer_new_lexer(vader_string_t l0, vader_string_t l1);
static uint32_t vader_lexer_peek(void* l0);
static uint32_t vader_lexer_peek_at(void* l0, size_t l1);
static bool vader_lexer_peeks_leading_continuation(void* l0);
static void vader_lexer_pop_interp(void* l0);
static void* vader_lexer_position_here(void* l0);
static void vader_lexer_push_error(void* l0, uint8_t l1, void* l2, vader_string_t l3);
static void vader_lexer_push_simple(void* l0, uint8_t l1, vader_string_t l2, void* l3);
static void vader_lexer_skip_horizontal(void* l0);
static bool vader_lexer_suppresses_newline_after(uint8_t l0);
static vader_box_t vader_lexer_top_interp(void* l0);
static bool vader_lexer_try_lex_operator(void* l0);

static void vader_lexer_advance(void* l0, size_t l1) {
    size_t l2, l3, l4, l6, l9, l10, l15;
    void* l5;
    int32_t l7, l8, l12, l14;
    bool l11, l13;
    vader_box_t t0;
    uint8_t t1;
    int32_t t2;
    size_t t3;
    int64_t t4;
    l2 = (size_t) (int64_t) INT64_C(0);
    {
        loop_3: {
            if ((l2 < l1)) {
                l3 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
                l4 = ((vader_array_t*) ((vader_struct_vader_lexer_Lexer_t*) l0)->f_bytes)->length;
                if ((l3 >= l4)) {
                    return;
                }
                l5 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_bytes;
                l6 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
                vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l6 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l6, 175u);
                t1 = ((uint8_t) t0.payload.i);
                l7 = ((int32_t) (uint8_t) t1);
                if (l7 == INT32_C(10)) {
                    t2 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_line;
                    l8 = (t2 + INT32_C(1));
                    ((vader_struct_vader_lexer_Lexer_t*) l0)->f_line = l8;
                    VADER_WRITE_BARRIER((vader_struct_vader_lexer_Lexer_t*) l0);
                    ((vader_struct_vader_lexer_Lexer_t*) l0)->f_col = INT32_C(1);
                    VADER_WRITE_BARRIER((vader_struct_vader_lexer_Lexer_t*) l0);
                } else {
                    if (l7 == INT32_C(13)) {
                        t3 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
                        t4 = (t3 + INT64_C(1));
                        l9 = (size_t) (int64_t) t4;
                        l10 = ((vader_array_t*) ((vader_struct_vader_lexer_Lexer_t*) l0)->f_bytes)->length;
                        if ((l9 >= l10)) {
                            l11 = true;
                        } else {
                            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_lexer_Lexer_t*) l0)->f_bytes);
                            if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                            if ((size_t) l9 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                            t0 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) l9, 175u);
                            t1 = ((uint8_t) t0.payload.i);
                            l11 = t1 != INT32_C(10);
                        }
                        if (l11) {
                            t2 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_line;
                            l12 = (t2 + INT32_C(1));
                            ((vader_struct_vader_lexer_Lexer_t*) l0)->f_line = l12;
                            VADER_WRITE_BARRIER((vader_struct_vader_lexer_Lexer_t*) l0);
                            ((vader_struct_vader_lexer_Lexer_t*) l0)->f_col = INT32_C(1);
                            VADER_WRITE_BARRIER((vader_struct_vader_lexer_Lexer_t*) l0);
                        }
                    } else {
                        if ((l7 < INT32_C(128))) {
                            l13 = true;
                        } else {
                            l13 = (l7 >= INT32_C(192));
                        }
                        if (l13) {
                            t2 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_col;
                            l14 = (t2 + INT32_C(1));
                            ((vader_struct_vader_lexer_Lexer_t*) l0)->f_col = l14;
                            VADER_WRITE_BARRIER((vader_struct_vader_lexer_Lexer_t*) l0);
                        }
                    }
                }
                t3 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
                t4 = (t3 + INT64_C(1));
                l15 = (size_t) (int64_t) t4;
                ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos = l15;
                VADER_WRITE_BARRIER((vader_struct_vader_lexer_Lexer_t*) l0);
                t4 = (l2 + INT64_C(1));
                l2 = (size_t) (int64_t) t4;
                goto loop_3;
            }
        }
    }
    return;
}

static bool vader_lexer_at_end(void* l0) {
    size_t l1, l2;
    l1 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
    l2 = ((vader_array_t*) ((vader_struct_vader_lexer_Lexer_t*) l0)->f_bytes)->length;
    return (l1 >= l2);
}

static void vader_lexer_consume_digits(void* l0, int32_t l1, void* l2) {
    bool l3, l4, l7, l8, l9;
    uint32_t l5, l6;
    void* l10 = NULL;
    bool t0;
    void** gc_raw_roots[3] = { &l0, &l2, &l10 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = false;
    l4 = true;
    {
        loop_5: {
            t0 = vader_lexer_at_end(l0);
            if (!(t0)) {
                l5 = vader_lexer_peek(l0);
                if (l5 == 95u) {
                    l6 = vader_lexer_peek_at(l0, (size_t) (int64_t) INT64_C(1));
                    if (l6 != 95u) {
                        l7 = vader_lexer_is_ident_start(l6);
                    } else {
                        l7 = false;
                    }
                    if (l7) {
                        t0 = std_numbers_is_digit_in_base(l6, l1);
                        l8 = !(t0);
                    } else {
                        l8 = false;
                    }
                    if (l8) {
                        { vader_gc_top = gc_frame.prev; return; }
                    }
                    if (l4) {
                        l9 = true;
                    } else {
                        l9 = l3;
                    }
                    if (l9) {
                        l10 = vader_lexer_error_span(l0, l2);
                        vader_lexer_push_error(l0, (uint8_t) (int32_t) INT32_C(5), l10, 2268u);
                    }
                    l3 = true;
                    l4 = false;
                    vader_lexer_advance(l0, (size_t) (int64_t) INT64_C(1));
                    goto loop_5;
                }
                t0 = std_numbers_is_digit_in_base(l5, l1);
                if (t0) {
                    l3 = false;
                    l4 = false;
                    vader_lexer_advance(l0, (size_t) (int64_t) INT64_C(1));
                    goto loop_5;
                }
            }
        }
    }
    if (l3) {
        l10 = vader_lexer_error_span(l0, l2);
        vader_lexer_push_error(l0, (uint8_t) (int32_t) INT32_C(5), l10, 2268u);
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_lexer_emit(void* l0, void* l1) {
    uint8_t l2;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_push((vader_array_t*) ((vader_struct_vader_lexer_Lexer_t*) l0)->f_tokens, vader_ref_box(l1));
    l2 = ((vader_struct_vader_lexer_Token_t*) l1)->f_kind;
    ((vader_struct_vader_lexer_Lexer_t*) l0)->f_last_kind = l2;
    VADER_WRITE_BARRIER((vader_struct_vader_lexer_Lexer_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static bool vader_lexer_emit_and_advance(void* l0, uint8_t l1, vader_string_t l2) {
    void* l3 = NULL;
    size_t l4;
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = vader_lexer_position_here(l0);
    l4 = vader_host_std_core_byte_len(l2);
    vader_lexer_advance(l0, l4);
    vader_lexer_push_simple(l0, l1, l2, l3);
    { vader_gc_top = gc_frame.prev; return true; }
    vader_gc_top = gc_frame.prev;
}

void* vader_lexer_empty_file_span(vader_string_t l0) {
    void* l1 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_struct_toolchain_span_Position_t* _a0_obj = (vader_struct_toolchain_span_Position_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Position_t));
    vader_obj_header_init(_a0_obj, 481u);
    _a0_obj->f_file = l0;
    _a0_obj->f_offset = (size_t) (int64_t) INT64_C(0);
    _a0_obj->f_line = INT32_C(1);
    _a0_obj->f_column = INT32_C(1);
    l1 = (void*) _a0_obj;
    vader_struct_toolchain_span_Span_t* _a1_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a1_obj, 482u);
    _a1_obj->f_start = l1;
    _a1_obj->f_end = l1;
    t0 = (void*) _a1_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_lexer_error_span(void* l0, void* l1) {
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_lexer_position_here(l0);
    vader_struct_toolchain_span_Span_t* _a0_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a0_obj, 482u);
    _a0_obj->f_start = l1;
    _a0_obj->f_end = l2;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void vader_lexer_flush_string_part(void* l0, void* l1, void* l2, bool l3) {
    vader_string_t l4 = 0;
    void* l5 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (!(l3)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l4 = std_string_builder_StringBuilder_Display_to_string(l1);
    l5 = vader_lexer_position_here(l0);
    vader_struct_toolchain_span_Span_t* _a0_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a0_obj, 482u);
    _a0_obj->f_start = l2;
    _a0_obj->f_end = l5;
    l5 = (void*) _a0_obj;
    l5 = vader_lexer_make_token((uint8_t) (int32_t) INT32_C(7), l4, l5);
    ((vader_struct_vader_lexer_Token_t*) l5)->f_value = vader_box_string(169u, l4);
    VADER_WRITE_BARRIER((vader_struct_vader_lexer_Token_t*) l5);
    vader_lexer_emit(l0, l5);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
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
        vader_lexer_advance(l0, (size_t) (int64_t) INT64_C(1));
    }
    t0 = vader_lexer_peek(l0);
    if (t0 == 10u) {
        vader_lexer_advance(l0, (size_t) (int64_t) INT64_C(1));
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
    t2 = vader_lexer_peeks_leading_continuation(l0);
    if (t2) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l1 = vader_lexer_position_here(l0);
    vader_struct_toolchain_span_Span_t* _a0_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a0_obj, 482u);
    _a0_obj->f_start = l1;
    _a0_obj->f_end = l1;
    l1 = (void*) _a0_obj;
    l1 = vader_lexer_make_token((uint8_t) (int32_t) INT32_C(1), 1u, l1);
    vader_lexer_emit(l0, l1);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static bool vader_lexer_is_ident_continue(uint32_t l0) {
    bool l1;
    bool t0;
    t0 = std_char_is_alnum(l0);
    if (t0) {
        l1 = true;
    } else {
        l1 = l0 == 95u;
    }
    return l1;
}

static bool vader_lexer_is_ident_start(uint32_t l0) {
    bool l1;
    bool t0;
    t0 = std_char_is_alpha(l0);
    if (t0) {
        l1 = true;
    } else {
        l1 = l0 == 95u;
    }
    return l1;
}

vader_string_t vader_lexer_kind_name(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(2)) {
        l1 = 1694u;
    } else {
        if (l0 == INT32_C(3)) {
            l1 = 1735u;
        } else {
            if (l0 == INT32_C(4)) {
                l1 = 1597u;
            } else {
                if (l0 == INT32_C(5)) {
                    l1 = 1365u;
                } else {
                    if (l0 == INT32_C(6)) {
                        l1 = 2113u;
                    } else {
                        if (l0 == INT32_C(7)) {
                            l1 = 2115u;
                        } else {
                            if (l0 == INT32_C(8)) {
                                l1 = 2114u;
                            } else {
                                if (l0 == INT32_C(9)) {
                                    l1 = 1742u;
                                } else {
                                    if (l0 == INT32_C(10)) {
                                        l1 = 1741u;
                                    } else {
                                        if (l0 == INT32_C(11)) {
                                            l1 = 1786u;
                                        } else {
                                            if (l0 == INT32_C(12)) {
                                                l1 = 1797u;
                                            } else {
                                                if (l0 == INT32_C(13)) {
                                                    l1 = 1798u;
                                                } else {
                                                    if (l0 == INT32_C(14)) {
                                                        l1 = 1789u;
                                                    } else {
                                                        if (l0 == INT32_C(15)) {
                                                            l1 = 1783u;
                                                        } else {
                                                            if (l0 == INT32_C(16)) {
                                                                l1 = 1788u;
                                                            } else {
                                                                if (l0 == INT32_C(17)) {
                                                                    l1 = 1782u;
                                                                } else {
                                                                    if (l0 == INT32_C(18)) {
                                                                        l1 = 1793u;
                                                                    } else {
                                                                        if (l0 == INT32_C(19)) {
                                                                            l1 = 1792u;
                                                                        } else {
                                                                            if (l0 == INT32_C(20)) {
                                                                                l1 = 1787u;
                                                                            } else {
                                                                                if (l0 == INT32_C(21)) {
                                                                                    l1 = 1791u;
                                                                                } else {
                                                                                    if (l0 == INT32_C(22)) {
                                                                                        l1 = 1795u;
                                                                                    } else {
                                                                                        if (l0 == INT32_C(23)) {
                                                                                            l1 = 1800u;
                                                                                        } else {
                                                                                            if (l0 == INT32_C(24)) {
                                                                                                l1 = 1777u;
                                                                                            } else {
                                                                                                if (l0 == INT32_C(25)) {
                                                                                                    l1 = 1781u;
                                                                                                } else {
                                                                                                    if (l0 == INT32_C(26)) {
                                                                                                        l1 = 1778u;
                                                                                                    } else {
                                                                                                        if (l0 == INT32_C(27)) {
                                                                                                            l1 = 1780u;
                                                                                                        } else {
                                                                                                            if (l0 == INT32_C(28)) {
                                                                                                                l1 = 1790u;
                                                                                                            } else {
                                                                                                                if (l0 == INT32_C(29)) {
                                                                                                                    l1 = 1776u;
                                                                                                                } else {
                                                                                                                    if (l0 == INT32_C(30)) {
                                                                                                                        l1 = 1784u;
                                                                                                                    } else {
                                                                                                                        if (l0 == INT32_C(31)) {
                                                                                                                            l1 = 1799u;
                                                                                                                        } else {
                                                                                                                            if (l0 == INT32_C(32)) {
                                                                                                                                l1 = 1785u;
                                                                                                                            } else {
                                                                                                                                if (l0 == INT32_C(33)) {
                                                                                                                                    l1 = 1794u;
                                                                                                                                } else {
                                                                                                                                    if (l0 == INT32_C(34)) {
                                                                                                                                        l1 = 1796u;
                                                                                                                                    } else {
                                                                                                                                        if (l0 == INT32_C(35)) {
                                                                                                                                            l1 = 1779u;
                                                                                                                                        } else {
                                                                                                                                            if (l0 == INT32_C(36)) {
                                                                                                                                                l1 = 1948u;
                                                                                                                                            } else {
                                                                                                                                                if (l0 == INT32_C(37)) {
                                                                                                                                                    l1 = 1872u;
                                                                                                                                                } else {
                                                                                                                                                    if (l0 == INT32_C(38)) {
                                                                                                                                                        l1 = 2033u;
                                                                                                                                                    } else {
                                                                                                                                                        if (l0 == INT32_C(39)) {
                                                                                                                                                            l1 = 2023u;
                                                                                                                                                        } else {
                                                                                                                                                            if (l0 == INT32_C(40)) {
                                                                                                                                                                l1 = 1944u;
                                                                                                                                                            } else {
                                                                                                                                                                if (l0 == INT32_C(41)) {
                                                                                                                                                                    l1 = 1182u;
                                                                                                                                                                } else {
                                                                                                                                                                    if (l0 == INT32_C(42)) {
                                                                                                                                                                        l1 = 1947u;
                                                                                                                                                                    } else {
                                                                                                                                                                        if (l0 == INT32_C(43)) {
                                                                                                                                                                            l1 = 1356u;
                                                                                                                                                                        } else {
                                                                                                                                                                            if (l0 == INT32_C(44)) {
                                                                                                                                                                                l1 = 2160u;
                                                                                                                                                                            } else {
                                                                                                                                                                                if (l0 == INT32_C(45)) {
                                                                                                                                                                                    l1 = 2011u;
                                                                                                                                                                                } else {
                                                                                                                                                                                    if (l0 == INT32_C(46)) {
                                                                                                                                                                                        l1 = 2015u;
                                                                                                                                                                                    } else {
                                                                                                                                                                                        if (l0 == INT32_C(47)) {
                                                                                                                                                                                            l1 = 1486u;
                                                                                                                                                                                        } else {
                                                                                                                                                                                            if (l0 == INT32_C(48)) {
                                                                                                                                                                                                l1 = 1898u;
                                                                                                                                                                                            } else {
                                                                                                                                                                                                if (l0 == INT32_C(49)) {
                                                                                                                                                                                                    l1 = 1837u;
                                                                                                                                                                                                } else {
                                                                                                                                                                                                    if (l0 == INT32_C(50)) {
                                                                                                                                                                                                        l1 = 1838u;
                                                                                                                                                                                                    } else {
                                                                                                                                                                                                        if (l0 == INT32_C(51)) {
                                                                                                                                                                                                            l1 = 1639u;
                                                                                                                                                                                                        } else {
                                                                                                                                                                                                            if (l0 == INT32_C(52)) {
                                                                                                                                                                                                                l1 = 1640u;
                                                                                                                                                                                                            } else {
                                                                                                                                                                                                                if (l0 == INT32_C(53)) {
                                                                                                                                                                                                                    l1 = 1189u;
                                                                                                                                                                                                                } else {
                                                                                                                                                                                                                    if (l0 == INT32_C(54)) {
                                                                                                                                                                                                                        l1 = 1931u;
                                                                                                                                                                                                                    } else {
                                                                                                                                                                                                                        if (l0 == INT32_C(56)) {
                                                                                                                                                                                                                            l1 = 1957u;
                                                                                                                                                                                                                        } else {
                                                                                                                                                                                                                            if (l0 == INT32_C(55)) {
                                                                                                                                                                                                                                l1 = 1256u;
                                                                                                                                                                                                                            } else {
                                                                                                                                                                                                                                if (l0 == INT32_C(57)) {
                                                                                                                                                                                                                                    l1 = 1244u;
                                                                                                                                                                                                                                } else {
                                                                                                                                                                                                                                    if (l0 == INT32_C(58)) {
                                                                                                                                                                                                                                        l1 = 1949u;
                                                                                                                                                                                                                                    } else {
                                                                                                                                                                                                                                        if (l0 == INT32_C(59)) {
                                                                                                                                                                                                                                            l1 = 1873u;
                                                                                                                                                                                                                                        } else {
                                                                                                                                                                                                                                            if (l0 == INT32_C(60)) {
                                                                                                                                                                                                                                                l1 = 2034u;
                                                                                                                                                                                                                                            } else {
                                                                                                                                                                                                                                                if (l0 == INT32_C(61)) {
                                                                                                                                                                                                                                                    l1 = 2024u;
                                                                                                                                                                                                                                                } else {
                                                                                                                                                                                                                                                    if (l0 == INT32_C(62)) {
                                                                                                                                                                                                                                                        l1 = 1945u;
                                                                                                                                                                                                                                                    } else {
                                                                                                                                                                                                                                                        if (l0 == INT32_C(63)) {
                                                                                                                                                                                                                                                            l1 = 1433u;
                                                                                                                                                                                                                                                        } else {
                                                                                                                                                                                                                                                            if (l0 == INT32_C(64)) {
                                                                                                                                                                                                                                                                l1 = 1434u;
                                                                                                                                                                                                                                                            } else {
                                                                                                                                                                                                                                                                if (l0 == INT32_C(65)) {
                                                                                                                                                                                                                                                                    l1 = 1959u;
                                                                                                                                                                                                                                                                } else {
                                                                                                                                                                                                                                                                    if (l0 == INT32_C(66)) {
                                                                                                                                                                                                                                                                        l1 = 1960u;
                                                                                                                                                                                                                                                                    } else {
                                                                                                                                                                                                                                                                        if (l0 == INT32_C(67)) {
                                                                                                                                                                                                                                                                            l1 = 1455u;
                                                                                                                                                                                                                                                                        } else {
                                                                                                                                                                                                                                                                            if (l0 == INT32_C(68)) {
                                                                                                                                                                                                                                                                                l1 = 1241u;
                                                                                                                                                                                                                                                                            } else {
                                                                                                                                                                                                                                                                                if (l0 == INT32_C(69)) {
                                                                                                                                                                                                                                                                                    l1 = 1563u;
                                                                                                                                                                                                                                                                                } else {
                                                                                                                                                                                                                                                                                    if (l0 == INT32_C(70)) {
                                                                                                                                                                                                                                                                                        l1 = 1250u;
                                                                                                                                                                                                                                                                                    } else {
                                                                                                                                                                                                                                                                                        if (l0 == INT32_C(71)) {
                                                                                                                                                                                                                                                                                            l1 = 1453u;
                                                                                                                                                                                                                                                                                        } else {
                                                                                                                                                                                                                                                                                            if (l0 == INT32_C(72)) {
                                                                                                                                                                                                                                                                                                l1 = 1836u;
                                                                                                                                                                                                                                                                                            } else {
                                                                                                                                                                                                                                                                                                if (l0 == INT32_C(73)) {
                                                                                                                                                                                                                                                                                                    l1 = 1997u;
                                                                                                                                                                                                                                                                                                } else {
                                                                                                                                                                                                                                                                                                    if (l0 == INT32_C(74)) {
                                                                                                                                                                                                                                                                                                        l1 = 1805u;
                                                                                                                                                                                                                                                                                                    } else {
                                                                                                                                                                                                                                                                                                        if (l0 == INT32_C(75)) {
                                                                                                                                                                                                                                                                                                            l1 = 1963u;
                                                                                                                                                                                                                                                                                                        } else {
                                                                                                                                                                                                                                                                                                            if (l0 == INT32_C(76)) {
                                                                                                                                                                                                                                                                                                                l1 = 1804u;
                                                                                                                                                                                                                                                                                                            } else {
                                                                                                                                                                                                                                                                                                                if (l0 == INT32_C(77)) {
                                                                                                                                                                                                                                                                                                                    l1 = 1962u;
                                                                                                                                                                                                                                                                                                                } else {
                                                                                                                                                                                                                                                                                                                    if (l0 == INT32_C(78)) {
                                                                                                                                                                                                                                                                                                                        l1 = 1380u;
                                                                                                                                                                                                                                                                                                                    } else {
                                                                                                                                                                                                                                                                                                                        if (l0 == INT32_C(79)) {
                                                                                                                                                                                                                                                                                                                            l1 = 1454u;
                                                                                                                                                                                                                                                                                                                        } else {
                                                                                                                                                                                                                                                                                                                            if (l0 == INT32_C(80)) {
                                                                                                                                                                                                                                                                                                                                l1 = 1379u;
                                                                                                                                                                                                                                                                                                                            } else {
                                                                                                                                                                                                                                                                                                                                if (l0 == INT32_C(1)) {
                                                                                                                                                                                                                                                                                                                                    l1 = 1901u;
                                                                                                                                                                                                                                                                                                                                } else {
                                                                                                                                                                                                                                                                                                                                    if (l0 == INT32_C(0)) {
                                                                                                                                                                                                                                                                                                                                        l1 = 1485u;
                                                                                                                                                                                                                                                                                                                                    } else {
                                                                                                                                                                                                                                                                                                                                        vader_unreachable("unreachable return in vader_lexer$kind_name");
                                                                                                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                            }
                                                                                                                                                                                                                        }
                                                                                                                                                                                                                    }
                                                                                                                                                                                                                }
                                                                                                                                                                                                            }
                                                                                                                                                                                                        }
                                                                                                                                                                                                    }
                                                                                                                                                                                                }
                                                                                                                                                                                            }
                                                                                                                                                                                        }
                                                                                                                                                                                    }
                                                                                                                                                                                }
                                                                                                                                                                            }
                                                                                                                                                                        }
                                                                                                                                                                    }
                                                                                                                                                                }
                                                                                                                                                            }
                                                                                                                                                        }
                                                                                                                                                    }
                                                                                                                                                }
                                                                                                                                            }
                                                                                                                                        }
                                                                                                                                    }
                                                                                                                                }
                                                                                                                            }
                                                                                                                        }
                                                                                                                    }
                                                                                                                }
                                                                                                            }
                                                                                                        }
                                                                                                    }
                                                                                                }
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return l1;
}

static void vader_lexer_lex_block_comment(void* l0) {
    void* l1 = NULL;
    int32_t l2;
    bool l3, l4, l5;
    bool t0;
    uint32_t t1;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_lexer_position_here(l0);
    vader_lexer_advance(l0, (size_t) (int64_t) INT64_C(2));
    l2 = INT32_C(1);
    {
        loop_9: {
            t0 = vader_lexer_at_end(l0);
            if (!(t0)) {
                l3 = (l2 > INT32_C(0));
            } else {
                l3 = false;
            }
            if (l3) {
                t1 = vader_lexer_peek(l0);
                if (t1 == 47u) {
                    t1 = vader_lexer_peek_at(l0, (size_t) (int64_t) INT64_C(1));
                    l4 = t1 == 42u;
                } else {
                    l4 = false;
                }
                if (l4) {
                    vader_lexer_advance(l0, (size_t) (int64_t) INT64_C(2));
                    l2 = (l2 + INT32_C(1));
                    goto loop_9;
                }
                t1 = vader_lexer_peek(l0);
                if (t1 == 42u) {
                    t1 = vader_lexer_peek_at(l0, (size_t) (int64_t) INT64_C(1));
                    l5 = t1 == 47u;
                } else {
                    l5 = false;
                }
                if (l5) {
                    vader_lexer_advance(l0, (size_t) (int64_t) INT64_C(2));
                    l2 = (l2 - INT32_C(1));
                    goto loop_9;
                }
                vader_lexer_advance(l0, (size_t) (int64_t) INT64_C(1));
                goto loop_9;
            }
        }
    }
    if ((l2 > INT32_C(0))) {
        l1 = vader_lexer_error_span(l0, l1);
        vader_lexer_push_error(l0, (uint8_t) (int32_t) INT32_C(2), l1, 0u);
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_lexer_lex_char(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    size_t l3, l4;
    vader_string_t l5 = 0;
    uint32_t l6;
    bool l7, l9;
    uint32_t l8;
    uint32_t t0;
    void* t1 = NULL;
    int32_t t2;
    bool t3;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_lexer_position_here(l0);
    vader_lexer_advance(l0, (size_t) (int64_t) INT64_C(1));
    t0 = vader_lexer_peek(l0);
    if (t0 == 39u) {
        vader_lexer_advance(l0, (size_t) (int64_t) INT64_C(1));
        l2 = vader_lexer_error_span(l0, l1);
        vader_lexer_push_error(l0, (uint8_t) (int32_t) INT32_C(4), l2, 1367u);
        l2 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_bytes;
        l3 = ((vader_struct_toolchain_span_Position_t*) l1)->f_offset;
        l4 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
        vader_array_t* _a0_arr = vader_array_slice((vader_array_t*) l2, (size_t) l3, (size_t) l4);
        t1 = (void*) _a0_arr;
        l5 = vader_host_std_core_bytes_to_string(t1);
        l2 = vader_lexer_error_span(l0, l1);
        l2 = vader_lexer_make_token((uint8_t) (int32_t) INT32_C(5), l5, l2);
        ((vader_struct_vader_lexer_Token_t*) l2)->f_value = vader_box_i32(172u, INT32_C(0));
        VADER_WRITE_BARRIER((vader_struct_vader_lexer_Token_t*) l2);
        vader_lexer_emit(l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
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
            vader_lexer_push_error(l0, (uint8_t) (int32_t) INT32_C(4), l2, 2291u);
            l2 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_bytes;
            l3 = ((vader_struct_toolchain_span_Position_t*) l1)->f_offset;
            l4 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
            vader_array_t* _a1_arr = vader_array_slice((vader_array_t*) l2, (size_t) l3, (size_t) l4);
            t1 = (void*) _a1_arr;
            l5 = vader_host_std_core_bytes_to_string(t1);
            l2 = vader_lexer_error_span(l0, l1);
            l2 = vader_lexer_make_token((uint8_t) (int32_t) INT32_C(5), l5, l2);
            ((vader_struct_vader_lexer_Token_t*) l2)->f_value = vader_box_i32(172u, INT32_C(0));
            VADER_WRITE_BARRIER((vader_struct_vader_lexer_Token_t*) l2);
            vader_lexer_emit(l0, l2);
            { vader_gc_top = gc_frame.prev; return; }
        }
        l8 = vader_lexer_peek(l0);
        t2 = ((int32_t) (uint32_t) l8);
        l6 = (uint32_t) (int32_t) t2;
        l3 = std_string_codepoint_byte_len(l8);
        vader_lexer_advance(l0, l3);
    }
    t0 = vader_lexer_peek(l0);
    if (t0 != 39u) {
        l2 = vader_lexer_error_span(l0, l1);
        vader_lexer_push_error(l0, (uint8_t) (int32_t) INT32_C(4), l2, 1368u);
        {
            loop_143: {
                t3 = vader_lexer_at_end(l0);
                if (!(t3)) {
                    t0 = vader_lexer_peek(l0);
                    l7 = t0 != 39u;
                } else {
                    l7 = false;
                }
                if (l7) {
                    t0 = vader_lexer_peek(l0);
                    l9 = t0 != 10u;
                } else {
                    l9 = false;
                }
                if (l9) {
                    vader_lexer_advance(l0, (size_t) (int64_t) INT64_C(1));
                    goto loop_143;
                }
            }
        }
        t0 = vader_lexer_peek(l0);
        if (t0 == 39u) {
            vader_lexer_advance(l0, (size_t) (int64_t) INT64_C(1));
        }
    } else {
        vader_lexer_advance(l0, (size_t) (int64_t) INT64_C(1));
    }
    l2 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_bytes;
    l3 = ((vader_struct_toolchain_span_Position_t*) l1)->f_offset;
    l4 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
    vader_array_t* _a2_arr = vader_array_slice((vader_array_t*) l2, (size_t) l3, (size_t) l4);
    t1 = (void*) _a2_arr;
    l5 = vader_host_std_core_bytes_to_string(t1);
    l1 = vader_lexer_error_span(l0, l1);
    l1 = vader_lexer_make_token((uint8_t) (int32_t) INT32_C(5), l5, l1);
    ((vader_struct_vader_lexer_Token_t*) l1)->f_value = vader_box_i32(177u, (int32_t)(uint32_t) l6);
    VADER_WRITE_BARRIER((vader_struct_vader_lexer_Token_t*) l1);
    vader_lexer_emit(l0, l1);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static uint32_t vader_lexer_lex_escape(void* l0, bool l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    uint32_t l4;
    bool l5;
    vader_string_t l6 = 0;
    bool t0;
    uint32_t t1;
    void* t2 = NULL;
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &t2 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = vader_lexer_position_here(l0);
    vader_lexer_advance(l0, (size_t) (int64_t) INT64_C(1));
    t0 = vader_lexer_at_end(l0);
    if (t0) {
        l3 = vader_lexer_error_span(l0, l2);
        vader_lexer_push_error(l0, (uint8_t) (int32_t) INT32_C(3), l3, 1721u);
        { vader_gc_top = gc_frame.prev; return (uint32_t) (int32_t) INT32_C(0); }
    }
    l4 = vader_lexer_peek(l0);
    vader_lexer_advance(l0, (size_t) (int64_t) INT64_C(1));
    if (l4 == 110u) {
        { vader_gc_top = gc_frame.prev; return (uint32_t) (int32_t) INT32_C(10); }
    }
    if (l4 == 116u) {
        { vader_gc_top = gc_frame.prev; return (uint32_t) (int32_t) INT32_C(9); }
    }
    if (l4 == 114u) {
        { vader_gc_top = gc_frame.prev; return (uint32_t) (int32_t) INT32_C(13); }
    }
    if (l4 == 92u) {
        { vader_gc_top = gc_frame.prev; return (uint32_t) (int32_t) INT32_C(92); }
    }
    if (l4 == 48u) {
        { vader_gc_top = gc_frame.prev; return (uint32_t) (int32_t) INT32_C(0); }
    }
    if (l4 == 117u) {
        t1 = vader_lexer_lex_unicode_escape(l0, l2);
        { uint32_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1) {
        if (l4 == 39u) {
            { vader_gc_top = gc_frame.prev; return (uint32_t) (int32_t) INT32_C(39); }
        }
        if (l4 == 34u) {
            l5 = true;
        } else {
            l5 = l4 == 36u;
        }
        if (l5) {
            l3 = vader_lexer_error_span(l0, l2);
            t2 = std_core_utf8_encode(l4);
            l6 = vader_host_std_core_bytes_to_string(t2);
            l6 = concat_3(1490u, l6, 134u);
            vader_lexer_push_error(l0, (uint8_t) (int32_t) INT32_C(3), l3, l6);
            { uint32_t __vret = (uint32_t) (int32_t) ((int32_t) (uint32_t) l4); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else {
        if (l4 == 34u) {
            { vader_gc_top = gc_frame.prev; return (uint32_t) (int32_t) INT32_C(34); }
        }
        if (l4 == 36u) {
            { vader_gc_top = gc_frame.prev; return (uint32_t) (int32_t) INT32_C(36); }
        }
        if (l4 == 39u) {
            l3 = vader_lexer_error_span(l0, l2);
            vader_lexer_push_error(l0, (uint8_t) (int32_t) INT32_C(3), l3, 1491u);
            { uint32_t __vret = (uint32_t) (int32_t) ((int32_t) (uint32_t) l4); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l2 = vader_lexer_error_span(l0, l2);
    t2 = std_core_utf8_encode(l4);
    l6 = vader_host_std_core_bytes_to_string(t2);
    l6 = concat_2(2277u, l6);
    vader_lexer_push_error(l0, (uint8_t) (int32_t) INT32_C(3), l2, l6);
    { uint32_t __vret = (uint32_t) (int32_t) ((int32_t) (uint32_t) l4); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void vader_lexer_lex_ident(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    bool l2;
    size_t l4, l5;
    vader_string_t l6 = 0;
    uint8_t l7;
    bool t0;
    uint32_t t1;
    void* t2 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &t2 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_lexer_position_here(l0);
    {
        loop_4: {
            t0 = vader_lexer_at_end(l0);
            if (!(t0)) {
                t1 = vader_lexer_peek(l0);
                l2 = vader_lexer_is_ident_continue(t1);
            } else {
                l2 = false;
            }
            if (l2) {
                vader_lexer_advance(l0, (size_t) (int64_t) INT64_C(1));
                goto loop_4;
            }
        }
    }
    l3 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_bytes;
    l4 = ((vader_struct_toolchain_span_Position_t*) l1)->f_offset;
    l5 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
    vader_array_t* _a0_arr = vader_array_slice((vader_array_t*) l3, (size_t) l4, (size_t) l5);
    t2 = (void*) _a0_arr;
    l6 = vader_host_std_core_bytes_to_string(t2);
    l7 = vader_lexer_lookup_keyword(l6);
    vader_lexer_push_simple(l0, l7, l6, l1);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_lexer_lex_number(void* l0) {
    void* l1 = NULL;
    void* l7 = NULL;
    bool l2, l5;
    int32_t l3;
    uint32_t l4;
    size_t l6, l8;
    vader_string_t l9 = 0;
    vader_string_t l10 = 0;
    uint8_t l11;
    vader_box_t l12 = vader_box_null(), l13 = vader_box_null();
    uint64_t l14;
    uint32_t t0;
    size_t t1;
    bool t2;
    void* t3 = NULL;
    double t4;
    vader_box_t* gc_roots[2] = { &l12, &l13 };
    void** gc_raw_roots[4] = { &l0, &l1, &l7, &t3 };
    vader_string_t* gc_atom_roots[2] = { &l9, &l10 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_lexer_position_here(l0);
    l2 = false;
    l3 = INT32_C(10);
    t0 = vader_lexer_peek(l0);
    if (t0 == 48u) {
        l4 = vader_lexer_peek_at(l0, (size_t) (int64_t) INT64_C(1));
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
        vader_lexer_advance(l0, (size_t) (int64_t) INT64_C(2));
        l6 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
        vader_lexer_consume_digits(l0, l3, l1);
        t1 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
        if (t1 == l6) {
            l7 = vader_lexer_error_span(l0, l1);
            vader_lexer_push_error(l0, (uint8_t) (int32_t) INT32_C(5), l7, 1514u);
        }
    } else {
        vader_lexer_consume_digits(l0, INT32_C(10), l1);
        t0 = vader_lexer_peek(l0);
        if (t0 == 46u) {
            t0 = vader_lexer_peek_at(l0, (size_t) (int64_t) INT64_C(1));
            l5 = std_char_is_digit(t0);
        } else {
            l5 = false;
        }
        if (l5) {
            l2 = true;
            vader_lexer_advance(l0, (size_t) (int64_t) INT64_C(1));
            vader_lexer_consume_digits(l0, INT32_C(10), l1);
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
            vader_lexer_advance(l0, (size_t) (int64_t) INT64_C(1));
            t0 = vader_lexer_peek(l0);
            if (t0 == 43u) {
                l5 = true;
            } else {
                t0 = vader_lexer_peek(l0);
                l5 = t0 == 45u;
            }
            if (l5) {
                vader_lexer_advance(l0, (size_t) (int64_t) INT64_C(1));
            }
            t0 = vader_lexer_peek(l0);
            t2 = std_char_is_digit(t0);
            if (!(t2)) {
                l7 = vader_lexer_error_span(l0, l1);
                vader_lexer_push_error(l0, (uint8_t) (int32_t) INT32_C(5), l7, 1519u);
            }
            vader_lexer_consume_digits(l0, INT32_C(10), l1);
        }
    }
    l7 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_bytes;
    l6 = ((vader_struct_toolchain_span_Position_t*) l1)->f_offset;
    l8 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
    vader_array_t* _a0_arr = vader_array_slice((vader_array_t*) l7, (size_t) l6, (size_t) l8);
    t3 = (void*) _a0_arr;
    l9 = vader_host_std_core_bytes_to_string(t3);
    t0 = vader_lexer_peek(l0);
    if (t0 == 95u) {
        t0 = vader_lexer_peek_at(l0, (size_t) (int64_t) INT64_C(1));
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
            vader_lexer_advance(l0, (size_t) (int64_t) INT64_C(1));
        }
        l6 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
        {
            loop_244: {
                t2 = vader_lexer_at_end(l0);
                if (!(t2)) {
                    t0 = vader_lexer_peek(l0);
                    l5 = vader_lexer_is_ident_continue(t0);
                } else {
                    l5 = false;
                }
                if (l5) {
                    vader_lexer_advance(l0, (size_t) (int64_t) INT64_C(1));
                    goto loop_244;
                }
            }
        }
        l7 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_bytes;
        l8 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
        vader_array_t* _a1_arr = vader_array_slice((vader_array_t*) l7, (size_t) l6, (size_t) l8);
        t3 = (void*) _a1_arr;
        l10 = vader_host_std_core_bytes_to_string(t3);
        l7 = vader_lexer_error_span(l0, l1);
        l10 = concat_3(2202u, l10, 988u);
        vader_lexer_push_error(l0, (uint8_t) (int32_t) INT32_C(5), l7, l10);
    }
    l7 = vader_lexer_position_here(l0);
    vader_struct_toolchain_span_Span_t* _a2_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a2_obj, 482u);
    _a2_obj->f_start = l1;
    _a2_obj->f_end = l7;
    l7 = (void*) _a2_obj;
    l11 = (uint8_t) (int32_t) INT32_C(3);
    if (l2) {
        l11 = (uint8_t) (int32_t) INT32_C(4);
    }
    l7 = vader_lexer_make_token(l11, l9, l7);
    l10 = std_numbers_strip_numeric_text(l9, l3);
    t2 = std_string_is_empty(l10);
    if (t2) {
        ((vader_struct_vader_lexer_Token_t*) l7)->f_value = vader_box_i64(173u, INT64_C(0));
        VADER_WRITE_BARRIER((vader_struct_vader_lexer_Token_t*) l7);
    } else {
        if (l2) {
            l12 = std_string_parse_float(l10);
            if ((l12.tag == 165u || l12.tag == 166u)) {
                t4 = ((double) l12.payload.f);
                l13 = vader_box_f64(166u, t4);
            } else {
                if (l12.tag == 389u) {
                    l13 = vader_box_f64(166u, 0.0);
                } else {
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            ((vader_struct_vader_lexer_Token_t*) l7)->f_value = l13;
            VADER_WRITE_BARRIER((vader_struct_vader_lexer_Token_t*) l7);
        } else {
            l12 = std_numbers_parse_uint_in_base(l10, l3);
            if (l12.tag == 178u) {
                l14 = ((uint64_t) l12.payload.i);
                ((vader_struct_vader_lexer_Token_t*) l7)->f_value = vader_box_i64(178u, (int64_t)(uint64_t) l14);
                VADER_WRITE_BARRIER((vader_struct_vader_lexer_Token_t*) l7);
            } else {
                if (l12.tag == 389u) {
                    l1 = vader_lexer_error_span(l0, l1);
                    l9 = concat_3(930u, l9, 953u);
                    vader_lexer_push_error(l0, (uint8_t) (int32_t) INT32_C(10), l1, l9);
                    ((vader_struct_vader_lexer_Token_t*) l7)->f_value = vader_box_i64(173u, INT64_C(0));
                    VADER_WRITE_BARRIER((vader_struct_vader_lexer_Token_t*) l7);
                } else {
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
        }
    }
    vader_lexer_emit(l0, l7);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_lexer_lex_one(void* l0) {
    vader_box_t l1 = vader_box_null();
    bool l2, l5;
    void* l3 = NULL;
    void* l6 = NULL;
    uint32_t l4;
    size_t l7;
    bool t0;
    uint32_t t1;
    void* t2 = NULL;
    int32_t t3;
    vader_box_t t4 = vader_box_null();
    uint8_t t5;
    vader_box_t* gc_roots[2] = { &l1, &t4 };
    void** gc_raw_roots[4] = { &l0, &l3, &l6, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_lexer_skip_horizontal(l0);
    t0 = vader_lexer_at_end(l0);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l1 = vader_lexer_top_interp(l0);
    if (l1.tag == 701u) {
        t1 = vader_lexer_peek(l0);
        if (t1 == 125u) {
            t2 = l1.payload.obj;
            t3 = ((vader_struct_vader_lexer_InterpFrame_t*) t2)->f_brace_depth;
            l2 = t3 == INT32_C(0);
        } else {
            l2 = false;
        }
        if (l2) {
            l3 = vader_lexer_position_here(l0);
            vader_lexer_advance(l0, (size_t) (int64_t) INT64_C(1));
            vader_lexer_push_simple(l0, (uint8_t) (int32_t) INT32_C(10), 2433u, l3);
            t2 = l1.payload.obj;
            l2 = ((vader_struct_vader_lexer_InterpFrame_t*) t2)->f_triple;
            vader_lexer_pop_interp(l0);
            vader_lexer_lex_string_body(l0, l2, false);
            { vader_gc_top = gc_frame.prev; return; }
        }
    } else {
        if (l1.tag == 0u) {
        } else {
            { vader_gc_top = gc_frame.prev; return; }
        }
    }
    l4 = vader_lexer_peek(l0);
    if (l4 == 10u) {
        l2 = true;
    } else {
        l2 = l4 == 13u;
    }
    if (l2) {
        vader_lexer_handle_newline(l0);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l4 == 47u) {
        t1 = vader_lexer_peek_at(l0, (size_t) (int64_t) INT64_C(1));
        l2 = t1 == 47u;
    } else {
        l2 = false;
    }
    if (l2) {
        {
            loop_99: {
                t0 = vader_lexer_at_end(l0);
                if (!(t0)) {
                    t1 = vader_lexer_peek(l0);
                    l2 = t1 != 10u;
                } else {
                    l2 = false;
                }
                if (l2) {
                    t1 = vader_lexer_peek(l0);
                    l5 = t1 != 13u;
                } else {
                    l5 = false;
                }
                if (l5) {
                    vader_lexer_advance(l0, (size_t) (int64_t) INT64_C(1));
                    goto loop_99;
                }
            }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l4 == 47u) {
        t1 = vader_lexer_peek_at(l0, (size_t) (int64_t) INT64_C(1));
        l2 = t1 == 42u;
    } else {
        l2 = false;
    }
    if (l2) {
        vader_lexer_lex_block_comment(l0);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l4 == 114u) {
        t1 = vader_lexer_peek_at(l0, (size_t) (int64_t) INT64_C(1));
        l2 = t1 == 34u;
    } else {
        l2 = false;
    }
    if (l2) {
        vader_lexer_lex_string(l0, true);
        { vader_gc_top = gc_frame.prev; return; }
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
    l3 = vader_lexer_position_here(l0);
    if (l4 == 35u) {
        t1 = vader_lexer_peek_at(l0, (size_t) (int64_t) INT64_C(1));
        l2 = t1 == 33u;
    } else {
        l2 = false;
    }
    if (l2) {
        {
            loop_232: {
                t0 = vader_lexer_at_end(l0);
                if (!(t0)) {
                    t1 = vader_lexer_peek(l0);
                    l2 = t1 != 10u;
                } else {
                    l2 = false;
                }
                if (l2) {
                    t1 = vader_lexer_peek(l0);
                    l5 = t1 != 13u;
                } else {
                    l5 = false;
                }
                if (l5) {
                    vader_lexer_advance(l0, (size_t) (int64_t) INT64_C(1));
                    goto loop_232;
                }
            }
        }
        l6 = vader_lexer_error_span(l0, l3);
        vader_lexer_push_error(l0, (uint8_t) (int32_t) INT32_C(7), l6, 0u);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l4 == 92u) {
        vader_lexer_advance(l0, (size_t) (int64_t) INT64_C(1));
        l6 = vader_lexer_error_span(l0, l3);
        vader_lexer_push_error(l0, (uint8_t) (int32_t) INT32_C(6), l6, 0u);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l6 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_bytes;
    l7 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l6);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l7 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    t4 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l7, 175u);
    t5 = ((uint8_t) t4.payload.i);
    l7 = std_string_utf8_lead_len(t5);
    vader_lexer_advance(l0, l7);
    l3 = vader_lexer_error_span(l0, l3);
    vader_lexer_push_error(l0, (uint8_t) (int32_t) INT32_C(0), l3, 0u);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_lexer_lex_string(void* l0, bool l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    bool l3, l4;
    size_t l6, l7;
    vader_string_t l8 = 0;
    uint32_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[4] = { &l0, &l2, &l5, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = vader_lexer_position_here(l0);
    if (l1) {
        vader_lexer_advance(l0, (size_t) (int64_t) INT64_C(1));
    }
    vader_lexer_advance(l0, (size_t) (int64_t) INT64_C(1));
    l3 = false;
    t0 = vader_lexer_peek(l0);
    if (t0 == 34u) {
        t0 = vader_lexer_peek_at(l0, (size_t) (int64_t) INT64_C(1));
        l4 = t0 == 34u;
    } else {
        l4 = false;
    }
    if (l4) {
        l3 = true;
        vader_lexer_advance(l0, (size_t) (int64_t) INT64_C(2));
        t0 = vader_lexer_peek(l0);
        if (t0 == 13u) {
            t0 = vader_lexer_peek_at(l0, (size_t) (int64_t) INT64_C(1));
            l4 = t0 == 10u;
        } else {
            l4 = false;
        }
        if (l4) {
            vader_lexer_advance(l0, (size_t) (int64_t) INT64_C(2));
        } else {
            t0 = vader_lexer_peek(l0);
            if (t0 == 10u) {
                vader_lexer_advance(l0, (size_t) (int64_t) INT64_C(1));
            }
        }
    }
    l5 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_bytes;
    l6 = ((vader_struct_toolchain_span_Position_t*) l2)->f_offset;
    l7 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
    vader_array_t* _a0_arr = vader_array_slice((vader_array_t*) l5, (size_t) l6, (size_t) l7);
    t1 = (void*) _a0_arr;
    l8 = vader_host_std_core_bytes_to_string(t1);
    l5 = vader_lexer_position_here(l0);
    vader_struct_toolchain_span_Span_t* _a1_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a1_obj, 482u);
    _a1_obj->f_start = l2;
    _a1_obj->f_end = l5;
    l2 = (void*) _a1_obj;
    l2 = vader_lexer_make_token((uint8_t) (int32_t) INT32_C(6), l8, l2);
    vader_lexer_emit(l0, l2);
    vader_lexer_lex_string_body(l0, l3, l1);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_lexer_lex_string_body(void* l0, bool l1, bool l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l10 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    void* l19 = NULL;
    void* l20 = NULL;
    void* l23 = NULL;
    void* l24 = NULL;
    void* l25 = NULL;
    void* l26 = NULL;
    void* l27 = NULL;
    void* l28 = NULL;
    void* l31 = NULL;
    void* l32 = NULL;
    void* l33 = NULL;
    void* l34 = NULL;
    void* l35 = NULL;
    void* l36 = NULL;
    void* l37 = NULL;
    bool l5, l7, l8, l9, l15, l21, l22, l29, l30, l38;
    uint32_t l6, l39;
    vader_string_t l11 = 0;
    size_t l40;
    void* t0 = NULL;
    bool t1;
    uint32_t t2;
    uint32_t t3;
    void** gc_raw_roots[26] = { &l0, &l3, &l4, &l10, &l12, &l13, &l14, &l16, &l17, &l18, &l19, &l20, &l23, &l24, &l25, &l26, &l27, &l28, &l31, &l32, &l33, &l34, &l35, &l36, &l37, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l11 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 26u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = vader_lexer_position_here(l0);
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 169u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 391u);
    _a1_obj->f_parts = t0;
    l4 = (void*) _a1_obj;
    l5 = false;
    {
        loop_9: {
            t1 = vader_lexer_at_end(l0);
            if (!(t1)) {
                l6 = vader_lexer_peek(l0);
                l7 = false;
                if (l1) {
                    if (l6 == 34u) {
                        t2 = vader_lexer_peek_at(l0, (size_t) (int64_t) INT64_C(1));
                        l8 = t2 == 34u;
                    } else {
                        l8 = false;
                    }
                    if (l8) {
                        t2 = vader_lexer_peek_at(l0, (size_t) (int64_t) INT64_C(2));
                        l9 = t2 == 34u;
                    } else {
                        l9 = false;
                    }
                    if (l9) {
                        l7 = true;
                    }
                } else {
                    if (l6 == 34u) {
                        l7 = true;
                    }
                }
                if (l7) {
                    vader_lexer_flush_string_part(l0, l4, l3, l5);
                    l10 = vader_lexer_position_here(l0);
                    l11 = 227u;
                    if (l1) {
                        vader_lexer_advance(l0, (size_t) (int64_t) INT64_C(3));
                        l11 = 229u;
                    } else {
                        vader_lexer_advance(l0, (size_t) (int64_t) INT64_C(1));
                    }
                    l12 = vader_lexer_position_here(l0);
                    vader_struct_toolchain_span_Span_t* _a2_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
                    vader_obj_header_init(_a2_obj, 482u);
                    _a2_obj->f_start = l10;
                    _a2_obj->f_end = l12;
                    l13 = (void*) _a2_obj;
                    l14 = vader_lexer_make_token((uint8_t) (int32_t) INT32_C(8), l11, l13);
                    vader_lexer_emit(l0, l14);
                    { vader_gc_top = gc_frame.prev; return; }
                }
                if (!(l1)) {
                    l15 = l6 == 10u;
                } else {
                    l15 = false;
                }
                if (l15) {
                    l16 = vader_lexer_position_here(l0);
                    vader_struct_toolchain_span_Span_t* _a3_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
                    vader_obj_header_init(_a3_obj, 482u);
                    _a3_obj->f_start = l3;
                    _a3_obj->f_end = l16;
                    l17 = (void*) _a3_obj;
                    vader_lexer_push_error(l0, (uint8_t) (int32_t) INT32_C(1), l17, 0u);
                    vader_lexer_flush_string_part(l0, l4, l3, l5);
                    l18 = vader_lexer_position_here(l0);
                    vader_struct_toolchain_span_Span_t* _a4_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
                    vader_obj_header_init(_a4_obj, 482u);
                    _a4_obj->f_start = l18;
                    _a4_obj->f_end = l18;
                    l19 = (void*) _a4_obj;
                    l20 = vader_lexer_make_token((uint8_t) (int32_t) INT32_C(8), 0u, l19);
                    vader_lexer_emit(l0, l20);
                    { vader_gc_top = gc_frame.prev; return; }
                }
                if (!(l2)) {
                    l21 = l6 == 36u;
                } else {
                    l21 = false;
                }
                if (l21) {
                    t2 = vader_lexer_peek_at(l0, (size_t) (int64_t) INT64_C(1));
                    l22 = t2 == 123u;
                } else {
                    l22 = false;
                }
                if (l22) {
                    vader_lexer_flush_string_part(l0, l4, l3, l5);
                    l23 = vader_lexer_position_here(l0);
                    vader_lexer_advance(l0, (size_t) (int64_t) INT64_C(2));
                    l24 = vader_lexer_position_here(l0);
                    vader_struct_toolchain_span_Span_t* _a5_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
                    vader_obj_header_init(_a5_obj, 482u);
                    _a5_obj->f_start = l23;
                    _a5_obj->f_end = l24;
                    l25 = (void*) _a5_obj;
                    l26 = vader_lexer_make_token((uint8_t) (int32_t) INT32_C(9), 257u, l25);
                    vader_lexer_emit(l0, l26);
                    l27 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_interp_stack;
                    vader_struct_vader_lexer_InterpFrame_t* _a6_obj = (vader_struct_vader_lexer_InterpFrame_t*) vader_gc_alloc(sizeof(vader_struct_vader_lexer_InterpFrame_t));
                    vader_obj_header_init(_a6_obj, 701u);
                    _a6_obj->f_brace_depth = INT32_C(0);
                    _a6_obj->f_triple = l1;
                    l28 = (void*) _a6_obj;
                    vader_array_push((vader_array_t*) l27, vader_ref_box(l28));
                    { vader_gc_top = gc_frame.prev; return; }
                }
                if (!(l2)) {
                    l29 = l6 == 36u;
                } else {
                    l29 = false;
                }
                if (l29) {
                    t2 = vader_lexer_peek_at(l0, (size_t) (int64_t) INT64_C(1));
                    l30 = vader_lexer_is_ident_start(t2);
                } else {
                    l30 = false;
                }
                if (l30) {
                    vader_lexer_flush_string_part(l0, l4, l3, l5);
                    l31 = vader_lexer_position_here(l0);
                    vader_lexer_advance(l0, (size_t) (int64_t) INT64_C(1));
                    l32 = vader_lexer_position_here(l0);
                    vader_struct_toolchain_span_Span_t* _a7_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
                    vader_obj_header_init(_a7_obj, 482u);
                    _a7_obj->f_start = l31;
                    _a7_obj->f_end = l32;
                    l33 = (void*) _a7_obj;
                    l34 = vader_lexer_make_token((uint8_t) (int32_t) INT32_C(9), 245u, l33);
                    vader_lexer_emit(l0, l34);
                    vader_lexer_lex_ident(l0);
                    l35 = vader_lexer_position_here(l0);
                    vader_struct_toolchain_span_Span_t* _a8_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
                    vader_obj_header_init(_a8_obj, 482u);
                    _a8_obj->f_start = l35;
                    _a8_obj->f_end = l35;
                    l36 = (void*) _a8_obj;
                    l37 = vader_lexer_make_token((uint8_t) (int32_t) INT32_C(10), 0u, l36);
                    vader_lexer_emit(l0, l37);
                    l3 = vader_lexer_position_here(l0);
                    vader_array_t* _a9_arr = vader_array_new(8u, 0u, 0u, 169u);
                    t0 = (void*) _a9_arr;
                    vader_struct_std_string_builder_StringBuilder_t* _a10_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
                    vader_obj_header_init(_a10_obj, 391u);
                    _a10_obj->f_parts = t0;
                    l4 = (void*) _a10_obj;
                    l5 = false;
                    goto loop_9;
                }
                if (!(l2)) {
                    l38 = l6 == 92u;
                } else {
                    l38 = false;
                }
                if (l38) {
                    t3 = vader_lexer_lex_escape(l0, false);
                    l39 = ((uint32_t) (uint32_t) t3);
                    std_string_builder_append_char(l4, l39);
                    l5 = true;
                    goto loop_9;
                }
                std_string_builder_append_char(l4, l6);
                l5 = true;
                l40 = std_string_codepoint_byte_len(l6);
                vader_lexer_advance(l0, l40);
                goto loop_9;
            }
        }
    }
    l10 = vader_lexer_position_here(l0);
    vader_struct_toolchain_span_Span_t* _a11_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a11_obj, 482u);
    _a11_obj->f_start = l3;
    _a11_obj->f_end = l10;
    l10 = (void*) _a11_obj;
    vader_lexer_push_error(l0, (uint8_t) (int32_t) INT32_C(1), l10, 0u);
    vader_lexer_flush_string_part(l0, l4, l3, l5);
    l3 = vader_lexer_position_here(l0);
    vader_struct_toolchain_span_Span_t* _a12_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a12_obj, 482u);
    _a12_obj->f_start = l3;
    _a12_obj->f_end = l3;
    l3 = (void*) _a12_obj;
    l3 = vader_lexer_make_token((uint8_t) (int32_t) INT32_C(8), 0u, l3);
    vader_lexer_emit(l0, l3);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static uint32_t vader_lexer_lex_unicode_escape(void* l0, void* l1) {
    void* l2 = NULL;
    void* l22 = NULL;
    void* l26 = NULL;
    void* l35 = NULL;
    size_t l3, l13, l14, l17, l18, l20, l25, l27, l32;
    bool l4, l7, l10, l19;
    uint8_t l5, l21, l34;
    vader_string_t l6 = 0;
    vader_string_t l23 = 0;
    vader_string_t l36 = 0;
    uint32_t l8, l9, l11, l12, l15, l16;
    uint32_t l24, l29, l30, l31, l33;
    int32_t l28;
    uint32_t t0;
    bool t1;
    int32_t t2;
    size_t t3;
    int64_t t4;
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l22, &l26, &l35 };
    vader_string_t* gc_atom_roots[3] = { &l6, &l23, &l36 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = vader_lexer_peek(l0);
    if (t0 != 123u) {
        l2 = vader_lexer_error_span(l0, l1);
        vader_lexer_push_error(l0, (uint8_t) (int32_t) INT32_C(8), l2, 1496u);
        { vader_gc_top = gc_frame.prev; return (uint32_t) (int32_t) INT32_C(0); }
    }
    vader_lexer_advance(l0, (size_t) (int64_t) INT64_C(1));
    l3 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
    {
        loop_23: {
            t1 = vader_lexer_at_end(l0);
            if (!(t1)) {
                t0 = vader_lexer_peek(l0);
                l4 = t0 != 125u;
            } else {
                l4 = false;
            }
            if (l4) {
                t0 = vader_lexer_peek(l0);
                t2 = std_numbers_hex_digit_value(t0);
                if ((t2 < INT32_C(0))) {
                    l5 = (uint8_t) (int32_t) INT32_C(8);
                    l2 = vader_lexer_error_span(l0, l1);
                    l6 = 1761u;
                    vader_lexer_push_error(l0, l5, l2, l6);
                    {
                        loop_59: {
                            t1 = vader_lexer_at_end(l0);
                            if (!(t1)) {
                                l8 = vader_lexer_peek(l0);
                                l9 = 125u;
                                l7 = l8 != l9;
                            } else {
                                l7 = false;
                            }
                            if (l7) {
                                l11 = vader_lexer_peek(l0);
                                l12 = 10u;
                                l10 = l11 != l12;
                            } else {
                                l10 = false;
                            }
                            if (l10) {
                                l13 = (size_t) (int64_t) INT64_C(1);
                                vader_lexer_advance(l0, l13);
                                goto loop_59;
                            }
                        }
                    }
                } else {
                    vader_lexer_advance(l0, (size_t) (int64_t) INT64_C(1));
                    goto loop_23;
                }
            }
            t3 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
            t4 = (t3 - l3);
            l14 = (size_t) (int64_t) t4;
            l15 = vader_lexer_peek(l0);
            l16 = 125u;
            if (l15 == l16) {
                l17 = (size_t) (int64_t) INT64_C(1);
                vader_lexer_advance(l0, l17);
            }
            l18 = (size_t) (int64_t) INT64_C(0);
            if (l14 == l18) {
                l19 = true;
            } else {
                l20 = (size_t) (int64_t) INT64_C(6);
                l19 = (l14 > l20);
            }
            if (l19) {
                l21 = (uint8_t) (int32_t) INT32_C(8);
                l22 = vader_lexer_error_span(l0, l1);
                l23 = 1376u;
                vader_lexer_push_error(l0, l21, l22, l23);
                { vader_gc_top = gc_frame.prev; return (uint32_t) (int32_t) INT32_C(0); }
            }
            l24 = (uint32_t) (int32_t) INT32_C(0);
            l25 = (size_t) (int64_t) INT64_C(0);
            {
                loop_168: {
                    if ((l25 < l14)) {
                        l26 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_bytes;
                        t4 = (l3 + l25);
                        l27 = (size_t) (int64_t) t4;
                        t0 = std_string_utf8_decode(l26, l27);
                        l28 = std_numbers_hex_digit_value(t0);
                        l29 = (uint32_t) (int32_t) INT32_C(16);
                        t2 = (l24 * l29);
                        l30 = (uint32_t) (int32_t) t2;
                        t2 = l28;
                        l31 = (uint32_t) (int32_t) t2;
                        t2 = (l30 + l31);
                        l24 = (uint32_t) (int32_t) t2;
                        l32 = (size_t) (int64_t) INT64_C(1);
                        t4 = (l25 + l32);
                        l25 = (size_t) (int64_t) t4;
                        goto loop_168;
                    }
                }
            }
            t2 = ((int32_t) (uint32_t) ((uint32_t) (int32_t) INT32_C(1114111)));
            l33 = (uint32_t) (int32_t) t2;
            if ((l24 > l33)) {
                l34 = (uint8_t) (int32_t) INT32_C(8);
                l35 = vader_lexer_error_span(l0, l1);
                l36 = 1377u;
                vader_lexer_push_error(l0, l34, l35, l36);
                { vader_gc_top = gc_frame.prev; return (uint32_t) (int32_t) INT32_C(0); }
            }
            { uint32_t __vret = l24; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l5 = (uint8_t) (int32_t) INT32_C(8);
    l2 = vader_lexer_error_span(l0, l1);
    l6 = 1761u;
    vader_lexer_push_error(l0, l5, l2, l6);
    {
        loop_248: {
            t1 = vader_lexer_at_end(l0);
            if (!(t1)) {
                l8 = vader_lexer_peek(l0);
                l9 = 125u;
                l7 = l8 != l9;
            } else {
                l7 = false;
            }
            if (l7) {
                l11 = vader_lexer_peek(l0);
                l12 = 10u;
                l10 = l11 != l12;
            } else {
                l10 = false;
            }
            if (l10) {
                l13 = (size_t) (int64_t) INT64_C(1);
                vader_lexer_advance(l0, l13);
                goto loop_248;
            }
        }
    }
    t3 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
    t4 = (t3 - l3);
    l14 = (size_t) (int64_t) t4;
    l15 = vader_lexer_peek(l0);
    l16 = 125u;
    if (l15 == l16) {
        l17 = (size_t) (int64_t) INT64_C(1);
        vader_lexer_advance(l0, l17);
    }
    l18 = (size_t) (int64_t) INT64_C(0);
    if (l14 == l18) {
        l19 = true;
    } else {
        l20 = (size_t) (int64_t) INT64_C(6);
        l19 = (l14 > l20);
    }
    if (l19) {
        l21 = (uint8_t) (int32_t) INT32_C(8);
        l22 = vader_lexer_error_span(l0, l1);
        l23 = 1376u;
        vader_lexer_push_error(l0, l21, l22, l23);
        { vader_gc_top = gc_frame.prev; return (uint32_t) (int32_t) INT32_C(0); }
    }
    l24 = (uint32_t) (int32_t) INT32_C(0);
    l25 = (size_t) (int64_t) INT64_C(0);
    {
        loop_350: {
            if ((l25 < l14)) {
                l26 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_bytes;
                t4 = (l3 + l25);
                l27 = (size_t) (int64_t) t4;
                t0 = std_string_utf8_decode(l26, l27);
                l28 = std_numbers_hex_digit_value(t0);
                l29 = (uint32_t) (int32_t) INT32_C(16);
                t2 = (l24 * l29);
                l30 = (uint32_t) (int32_t) t2;
                t2 = l28;
                l31 = (uint32_t) (int32_t) t2;
                t2 = (l30 + l31);
                l24 = (uint32_t) (int32_t) t2;
                l32 = (size_t) (int64_t) INT64_C(1);
                t4 = (l25 + l32);
                l25 = (size_t) (int64_t) t4;
                goto loop_350;
            }
        }
    }
    t2 = ((int32_t) (uint32_t) ((uint32_t) (int32_t) INT32_C(1114111)));
    l33 = (uint32_t) (int32_t) t2;
    if ((l24 > l33)) {
        l34 = (uint8_t) (int32_t) INT32_C(8);
        l35 = vader_lexer_error_span(l0, l1);
        l36 = 1377u;
        vader_lexer_push_error(l0, l34, l35, l36);
        { vader_gc_top = gc_frame.prev; return (uint32_t) (int32_t) INT32_C(0); }
    }
    { uint32_t __vret = l24; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static uint8_t vader_lexer_lookup_keyword(vader_string_t l0) {
    if (l0 == 1598u) {
        return (uint8_t) (int32_t) INT32_C(11);
    }
    if (l0 == 2116u) {
        return (uint8_t) (int32_t) INT32_C(12);
    }
    if (l0 == 2166u) {
        return (uint8_t) (int32_t) INT32_C(13);
    }
    if (l0 == 1707u) {
        return (uint8_t) (int32_t) INT32_C(14);
    }
    if (l0 == 1481u) {
        return (uint8_t) (int32_t) INT32_C(15);
    }
    if (l0 == 1697u) {
        return (uint8_t) (int32_t) INT32_C(16);
    }
    if (l0 == 1469u) {
        return (uint8_t) (int32_t) INT32_C(17);
    }
    if (l0 == 1846u) {
        return (uint8_t) (int32_t) INT32_C(18);
    }
    if (l0 == 1764u) {
        return (uint8_t) (int32_t) INT32_C(19);
    }
    if (l0 == 1605u) {
        return (uint8_t) (int32_t) INT32_C(20);
    }
    if (l0 == 1718u) {
        return (uint8_t) (int32_t) INT32_C(21);
    }
    if (l0 == 1986u) {
        return (uint8_t) (int32_t) INT32_C(22);
    }
    if (l0 == 2421u) {
        return (uint8_t) (int32_t) INT32_C(23);
    }
    if (l0 == 1252u) {
        return (uint8_t) (int32_t) INT32_C(24);
    }
    if (l0 == 1442u) {
        return (uint8_t) (int32_t) INT32_C(25);
    }
    if (l0 == 1283u) {
        return (uint8_t) (int32_t) INT32_C(26);
    }
    if (l0 == 1421u) {
        return (uint8_t) (int32_t) INT32_C(27);
    }
    if (l0 == 1708u) {
        return (uint8_t) (int32_t) INT32_C(28);
    }
    if (l0 == 1242u) {
        return (uint8_t) (int32_t) INT32_C(29);
    }
    if (l0 == 1520u) {
        return (uint8_t) (int32_t) INT32_C(30);
    }
    if (l0 == 2172u) {
        return (uint8_t) (int32_t) INT32_C(31);
    }
    if (l0 == 1562u) {
        return (uint8_t) (int32_t) INT32_C(32);
    }
    if (l0 == 1916u) {
        return (uint8_t) (int32_t) INT32_C(33);
    }
    if (l0 == 2006u) {
        return (uint8_t) (int32_t) INT32_C(34);
    }
    if (l0 == 1402u) {
        return (uint8_t) (int32_t) INT32_C(35);
    }
    return (uint8_t) (int32_t) INT32_C(2);
}

void* vader_lexer_make_token(uint8_t l0, vader_string_t l1, void* l2) {
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_struct_vader_lexer_Token_t* _a0_obj = (vader_struct_vader_lexer_Token_t*) vader_gc_alloc(sizeof(vader_struct_vader_lexer_Token_t));
    vader_obj_header_init(_a0_obj, 703u);
    _a0_obj->f_kind = l0;
    _a0_obj->f_text = l1;
    _a0_obj->f_span = l2;
    _a0_obj->f_value = vader_box_obj(0u, NULL);
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_lexer_new_lexer(vader_string_t l0, vader_string_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[5] = { &l2, &l3, &l4, &l5, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = vader_host_std_core_bytes(l0);
    vader_array_t* _a0_arr = vader_array_new(53u, 0u, 13u, 703u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(51u, 0u, 13u, 700u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(52u, 0u, 13u, 701u);
    l5 = (void*) _a2_arr;
    vader_struct_vader_lexer_Lexer_t* _a3_obj = (vader_struct_vader_lexer_Lexer_t*) vader_gc_alloc(sizeof(vader_struct_vader_lexer_Lexer_t));
    vader_obj_header_init(_a3_obj, 702u);
    _a3_obj->f_src = l0;
    _a3_obj->f_bytes = l2;
    _a3_obj->f_file = l1;
    _a3_obj->f_pos = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_line = INT32_C(1);
    _a3_obj->f_col = INT32_C(1);
    _a3_obj->f_paren_depth = INT32_C(0);
    _a3_obj->f_last_kind = (uint8_t) (int32_t) INT32_C(1);
    _a3_obj->f_tokens = l3;
    _a3_obj->f_errors = l4;
    _a3_obj->f_interp_stack = l5;
    t0 = (void*) _a3_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static uint32_t vader_lexer_peek(void* l0) {
    size_t l1, l2;
    void* l3;
    uint32_t t0;
    l1 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
    l2 = ((vader_array_t*) ((vader_struct_vader_lexer_Lexer_t*) l0)->f_bytes)->length;
    if ((l1 >= l2)) {
        return 0u;
    }
    l3 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_bytes;
    l1 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
    t0 = std_string_utf8_decode(l3, l1);
    return t0;
}

static uint32_t vader_lexer_peek_at(void* l0, size_t l1) {
    size_t l2, l3;
    size_t t0;
    int64_t t1;
    uint32_t t2;
    t0 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
    t1 = (t0 + l1);
    l2 = (size_t) (int64_t) t1;
    l3 = ((vader_array_t*) ((vader_struct_vader_lexer_Lexer_t*) l0)->f_bytes)->length;
    if ((l2 >= l3)) {
        return 0u;
    }
    t2 = std_string_utf8_decode(((vader_struct_vader_lexer_Lexer_t*) l0)->f_bytes, l2);
    return t2;
}

static bool vader_lexer_peeks_leading_continuation(void* l0) {
    size_t l1;
    uint32_t l2;
    bool l3, l4, l5;
    int64_t t0;
    uint32_t t1;
    l1 = (size_t) (int64_t) INT64_C(0);
    {
        loop_3: {
            l2 = vader_lexer_peek_at(l0, l1);
            if (l2 == 32u) {
                l3 = true;
            } else {
                l3 = l2 == 9u;
            }
            if (l3) {
                l4 = true;
            } else {
                l4 = l2 == 13u;
            }
            if (l4) {
                l5 = true;
            } else {
                l5 = l2 == 10u;
            }
            if (l5) {
                t0 = (l1 + INT64_C(1));
                l1 = (size_t) (int64_t) t0;
                goto loop_3;
            }
        }
    }
    if (l2 == 124u) {
        l3 = true;
    } else {
        l3 = l2 == 38u;
    }
    if (l3) {
        t0 = (l1 + INT64_C(1));
        l1 = (size_t) (int64_t) t0;
        t1 = vader_lexer_peek_at(l0, l1);
        return t1 != 61u;
    }
    return false;
}

static void vader_lexer_pop_interp(void* l0) {
    size_t l1;
    void* l2 = NULL;
    int64_t t0;
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_array_t*) ((vader_struct_vader_lexer_Lexer_t*) l0)->f_interp_stack)->length;
    if (l1 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l2 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_interp_stack;
    t0 = (l1 - INT64_C(1));
    l1 = (size_t) (int64_t) t0;
    vader_array_t* _a0_arr = vader_array_slice((vader_array_t*) l2, (size_t) INT64_C(0), (size_t) l1);
    l2 = (void*) _a0_arr;
    ((vader_struct_vader_lexer_Lexer_t*) l0)->f_interp_stack = l2;
    VADER_WRITE_BARRIER((vader_struct_vader_lexer_Lexer_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_lexer_position_here(void* l0) {
    vader_string_t l1 = 0;
    size_t l2;
    int32_t l3, l4;
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_file;
    l2 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
    l3 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_line;
    l4 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_col;
    vader_struct_toolchain_span_Position_t* _a0_obj = (vader_struct_toolchain_span_Position_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Position_t));
    vader_obj_header_init(_a0_obj, 481u);
    _a0_obj->f_file = l1;
    _a0_obj->f_offset = l2;
    _a0_obj->f_line = l3;
    _a0_obj->f_column = l4;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void vader_lexer_push_error(void* l0, uint8_t l1, void* l2, vader_string_t l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    void** gc_raw_roots[4] = { &l0, &l2, &l4, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_errors;
    l5 = vader_diagnostics_lexer_error(l1, l2, l3);
    vader_array_push((vader_array_t*) l4, vader_ref_box(l5));
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_lexer_push_simple(void* l0, uint8_t l1, vader_string_t l2, void* l3) {
    void* l4 = NULL;
    void** gc_raw_roots[3] = { &l0, &l3, &l4 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l4 = vader_lexer_position_here(l0);
    vader_struct_toolchain_span_Span_t* _a0_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a0_obj, 482u);
    _a0_obj->f_start = l3;
    _a0_obj->f_end = l4;
    l4 = (void*) _a0_obj;
    l4 = vader_lexer_make_token(l1, l2, l4);
    vader_lexer_emit(l0, l4);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_lexer_skip_horizontal(void* l0) {
    bool l1, l3, l4, l5;
    uint32_t l2;
    size_t t0;
    bool t1;
    t0 = ((vader_array_t*) ((vader_struct_vader_lexer_Lexer_t*) l0)->f_interp_stack)->length;
    l1 = (t0 > INT64_C(0));
    {
        loop_6: {
            t1 = vader_lexer_at_end(l0);
            if (!(t1)) {
                l2 = vader_lexer_peek(l0);
                if (l2 == 32u) {
                    l3 = true;
                } else {
                    l3 = l2 == 9u;
                }
                if (l3) {
                    vader_lexer_advance(l0, (size_t) (int64_t) INT64_C(1));
                } else {
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
                    if (l4) {
                        vader_lexer_advance(l0, (size_t) (int64_t) INT64_C(1));
                    } else {
                        return;
                    }
                }
                goto loop_6;
            }
        }
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
        l1 = l0 == INT32_C(47);
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
        l1 = l0 == INT32_C(56);
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
        l1 = l0 == INT32_C(57);
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
        l1 = l0 == INT32_C(60);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(61);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(62);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(80);
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
        l1 = l0 == INT32_C(78);
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
        l1 = false;
    }
    return l1;
}

void* vader_lexer_tokenize(vader_string_t l0, vader_string_t l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    bool l3;
    size_t t0;
    vader_box_t t1 = vader_box_null();
    uint8_t t2;
    int32_t t3;
    uint32_t t4;
    bool t5;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[2] = { &l2, &l4 };
    vader_string_t* gc_atom_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = vader_lexer_new_lexer(l0, l1);
    t0 = ((vader_array_t*) ((vader_struct_vader_lexer_Lexer_t*) l2)->f_bytes)->length;
    if ((t0 >= INT64_C(3))) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_lexer_Lexer_t*) l2)->f_bytes);
        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
        if ((size_t) INT32_C(0) >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
        t1 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) INT32_C(0), 175u);
        t2 = ((uint8_t) t1.payload.i);
        l3 = t2 == INT32_C(239);
    } else {
        l3 = false;
    }
    if (l3) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_lexer_Lexer_t*) l2)->f_bytes);
        if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
        if ((size_t) INT32_C(1) >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
        t1 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) INT32_C(1), 175u);
        t2 = ((uint8_t) t1.payload.i);
        l3 = t2 == INT32_C(187);
    } else {
        l3 = false;
    }
    if (l3) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_lexer_Lexer_t*) l2)->f_bytes);
        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
        if ((size_t) INT32_C(2) >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
        t1 = vader_array_read_u8(_a2_slotarr, _a2_slotarr->offset + (size_t) INT32_C(2), 175u);
        t2 = ((uint8_t) t1.payload.i);
        l3 = t2 == INT32_C(191);
    } else {
        l3 = false;
    }
    if (l3) {
        vader_lexer_advance(l2, (size_t) (int64_t) INT64_C(3));
    }
    t3 = ((vader_struct_vader_lexer_Lexer_t*) l2)->f_line;
    if (t3 == INT32_C(1)) {
        t4 = vader_lexer_peek(l2);
        l3 = t4 == 35u;
    } else {
        l3 = false;
    }
    if (l3) {
        t4 = vader_lexer_peek_at(l2, (size_t) (int64_t) INT64_C(1));
        l3 = t4 == 33u;
    } else {
        l3 = false;
    }
    if (l3) {
        {
            loop_81: {
                t5 = vader_lexer_at_end(l2);
                if (!(t5)) {
                    t4 = vader_lexer_peek(l2);
                    l3 = t4 != 10u;
                } else {
                    l3 = false;
                }
                if (l3) {
                    vader_lexer_advance(l2, (size_t) (int64_t) INT64_C(1));
                    goto loop_81;
                }
            }
        }
    }
    {
        loop_106: {
            t5 = vader_lexer_at_end(l2);
            if (!(t5)) {
                vader_lexer_lex_one(l2);
                goto loop_106;
            }
        }
    }
    l4 = vader_lexer_position_here(l2);
    vader_struct_toolchain_span_Span_t* _a3_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a3_obj, 482u);
    _a3_obj->f_start = l4;
    _a3_obj->f_end = l4;
    l4 = (void*) _a3_obj;
    l4 = vader_lexer_make_token((uint8_t) (int32_t) INT32_C(0), 0u, l4);
    vader_lexer_emit(l2, l4);
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_lexer_top_interp(void* l0) {
    size_t l1;
    void* l2;
    vader_box_t t0;
    int64_t t1;
    void* t2;
    l1 = ((vader_array_t*) ((vader_struct_vader_lexer_Lexer_t*) l0)->f_interp_stack)->length;
    if (l1 == INT64_C(0)) {
        t0 = vader_box_obj(0u, NULL);
        return t0;
    }
    l2 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_interp_stack;
    t1 = (l1 - INT64_C(1));
    l1 = (size_t) (int64_t) t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l1 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    t2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    return vader_ref_box(t2);
}

static bool vader_lexer_try_lex_operator(void* l0) {
    uint32_t l1, l2, l4;
    bool l3;
    void* l5 = NULL;
    int32_t l6;
    vader_box_t l7 = vader_box_null();
    bool t0;
    int32_t t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &l7 };
    void** gc_raw_roots[3] = { &l0, &l5, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_lexer_peek(l0);
    l2 = vader_lexer_peek_at(l0, (size_t) (int64_t) INT64_C(1));
    if (l1 == 46u) {
        l3 = l2 == 46u;
    } else {
        l3 = false;
    }
    if (l3) {
        l4 = vader_lexer_peek_at(l0, (size_t) (int64_t) INT64_C(2));
        if (l4 == 60u) {
            t0 = vader_lexer_emit_and_advance(l0, (uint8_t) (int32_t) INT32_C(65), 417u);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l4 == 61u) {
            t0 = vader_lexer_emit_and_advance(l0, (uint8_t) (int32_t) INT32_C(66), 418u);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l4 == 46u) {
            t0 = vader_lexer_emit_and_advance(l0, (uint8_t) (int32_t) INT32_C(67), 415u);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (l1 == 61u) {
        l3 = l2 == 61u;
    } else {
        l3 = false;
    }
    if (l3) {
        t0 = vader_lexer_emit_and_advance(l0, (uint8_t) (int32_t) INT32_C(47), 521u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 33u) {
        l3 = l2 == 61u;
    } else {
        l3 = false;
    }
    if (l3) {
        t0 = vader_lexer_emit_and_advance(l0, (uint8_t) (int32_t) INT32_C(48), 224u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 60u) {
        l3 = l2 == 61u;
    } else {
        l3 = false;
    }
    if (l3) {
        t0 = vader_lexer_emit_and_advance(l0, (uint8_t) (int32_t) INT32_C(50), 506u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 62u) {
        l3 = l2 == 61u;
    } else {
        l3 = false;
    }
    if (l3) {
        t0 = vader_lexer_emit_and_advance(l0, (uint8_t) (int32_t) INT32_C(52), 524u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 38u) {
        l3 = l2 == 38u;
    } else {
        l3 = false;
    }
    if (l3) {
        t0 = vader_lexer_emit_and_advance(l0, (uint8_t) (int32_t) INT32_C(53), 261u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 124u) {
        l3 = l2 == 124u;
    } else {
        l3 = false;
    }
    if (l3) {
        t0 = vader_lexer_emit_and_advance(l0, (uint8_t) (int32_t) INT32_C(54), 2432u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 63u) {
        l3 = l2 == 63u;
    } else {
        l3 = false;
    }
    if (l3) {
        t0 = vader_lexer_emit_and_advance(l0, (uint8_t) (int32_t) INT32_C(56), 528u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 60u) {
        l3 = l2 == 60u;
    } else {
        l3 = false;
    }
    if (l3) {
        t0 = vader_lexer_emit_and_advance(l0, (uint8_t) (int32_t) INT32_C(45), 505u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 62u) {
        l3 = l2 == 62u;
    } else {
        l3 = false;
    }
    if (l3) {
        t0 = vader_lexer_emit_and_advance(l0, (uint8_t) (int32_t) INT32_C(46), 525u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 45u) {
        l3 = l2 == 62u;
    } else {
        l3 = false;
    }
    if (l3) {
        t0 = vader_lexer_emit_and_advance(l0, (uint8_t) (int32_t) INT32_C(68), 392u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 61u) {
        l3 = l2 == 62u;
    } else {
        l3 = false;
    }
    if (l3) {
        t0 = vader_lexer_emit_and_advance(l0, (uint8_t) (int32_t) INT32_C(69), 522u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 58u) {
        l3 = l2 == 58u;
    } else {
        l3 = false;
    }
    if (l3) {
        t0 = vader_lexer_emit_and_advance(l0, (uint8_t) (int32_t) INT32_C(63), 497u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 58u) {
        l3 = l2 == 61u;
    } else {
        l3 = false;
    }
    if (l3) {
        t0 = vader_lexer_emit_and_advance(l0, (uint8_t) (int32_t) INT32_C(64), 499u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 43u) {
        l3 = l2 == 61u;
    } else {
        l3 = false;
    }
    if (l3) {
        t0 = vader_lexer_emit_and_advance(l0, (uint8_t) (int32_t) INT32_C(58), 368u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 45u) {
        l3 = l2 == 61u;
    } else {
        l3 = false;
    }
    if (l3) {
        t0 = vader_lexer_emit_and_advance(l0, (uint8_t) (int32_t) INT32_C(59), 391u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 42u) {
        l3 = l2 == 61u;
    } else {
        l3 = false;
    }
    if (l3) {
        t0 = vader_lexer_emit_and_advance(l0, (uint8_t) (int32_t) INT32_C(60), 366u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 47u) {
        l3 = l2 == 61u;
    } else {
        l3 = false;
    }
    if (l3) {
        t0 = vader_lexer_emit_and_advance(l0, (uint8_t) (int32_t) INT32_C(61), 449u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 37u) {
        l3 = l2 == 61u;
    } else {
        l3 = false;
    }
    if (l3) {
        t0 = vader_lexer_emit_and_advance(l0, (uint8_t) (int32_t) INT32_C(62), 259u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 43u) {
        t0 = vader_lexer_emit_and_advance(l0, (uint8_t) (int32_t) INT32_C(36), 367u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 45u) {
        t0 = vader_lexer_emit_and_advance(l0, (uint8_t) (int32_t) INT32_C(37), 388u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 42u) {
        t0 = vader_lexer_emit_and_advance(l0, (uint8_t) (int32_t) INT32_C(38), 358u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 47u) {
        t0 = vader_lexer_emit_and_advance(l0, (uint8_t) (int32_t) INT32_C(39), 436u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 37u) {
        t0 = vader_lexer_emit_and_advance(l0, (uint8_t) (int32_t) INT32_C(40), 258u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 38u) {
        t0 = vader_lexer_emit_and_advance(l0, (uint8_t) (int32_t) INT32_C(41), 260u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 124u) {
        t0 = vader_lexer_emit_and_advance(l0, (uint8_t) (int32_t) INT32_C(42), 2431u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 94u) {
        t0 = vader_lexer_emit_and_advance(l0, (uint8_t) (int32_t) INT32_C(43), 868u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 126u) {
        t0 = vader_lexer_emit_and_advance(l0, (uint8_t) (int32_t) INT32_C(44), 2438u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 60u) {
        t0 = vader_lexer_emit_and_advance(l0, (uint8_t) (int32_t) INT32_C(49), 504u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 62u) {
        t0 = vader_lexer_emit_and_advance(l0, (uint8_t) (int32_t) INT32_C(51), 523u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 33u) {
        t0 = vader_lexer_emit_and_advance(l0, (uint8_t) (int32_t) INT32_C(55), 223u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 61u) {
        t0 = vader_lexer_emit_and_advance(l0, (uint8_t) (int32_t) INT32_C(57), 520u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 64u) {
        t0 = vader_lexer_emit_and_advance(l0, (uint8_t) (int32_t) INT32_C(70), 529u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 36u) {
        t0 = vader_lexer_emit_and_advance(l0, (uint8_t) (int32_t) INT32_C(71), 245u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 58u) {
        t0 = vader_lexer_emit_and_advance(l0, (uint8_t) (int32_t) INT32_C(80), 468u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 44u) {
        t0 = vader_lexer_emit_and_advance(l0, (uint8_t) (int32_t) INT32_C(78), 370u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 46u) {
        t0 = vader_lexer_emit_and_advance(l0, (uint8_t) (int32_t) INT32_C(79), 413u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 40u) {
        l5 = vader_lexer_position_here(l0);
        vader_lexer_advance(l0, (size_t) (int64_t) INT64_C(1));
        t1 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_paren_depth;
        l6 = (t1 + INT32_C(1));
        ((vader_struct_vader_lexer_Lexer_t*) l0)->f_paren_depth = l6;
        VADER_WRITE_BARRIER((vader_struct_vader_lexer_Lexer_t*) l0);
        vader_lexer_push_simple(l0, (uint8_t) (int32_t) INT32_C(72), 283u, l5);
        { vader_gc_top = gc_frame.prev; return true; }
    }
    if (l1 == 91u) {
        l5 = vader_lexer_position_here(l0);
        vader_lexer_advance(l0, (size_t) (int64_t) INT64_C(1));
        t1 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_paren_depth;
        l6 = (t1 + INT32_C(1));
        ((vader_struct_vader_lexer_Lexer_t*) l0)->f_paren_depth = l6;
        VADER_WRITE_BARRIER((vader_struct_vader_lexer_Lexer_t*) l0);
        vader_lexer_push_simple(l0, (uint8_t) (int32_t) INT32_C(74), 850u, l5);
        { vader_gc_top = gc_frame.prev; return true; }
    }
    if (l1 == 41u) {
        l5 = vader_lexer_position_here(l0);
        vader_lexer_advance(l0, (size_t) (int64_t) INT64_C(1));
        t1 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_paren_depth;
        if ((t1 > INT32_C(0))) {
            t1 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_paren_depth;
            l6 = (t1 - INT32_C(1));
            ((vader_struct_vader_lexer_Lexer_t*) l0)->f_paren_depth = l6;
            VADER_WRITE_BARRIER((vader_struct_vader_lexer_Lexer_t*) l0);
        }
        vader_lexer_push_simple(l0, (uint8_t) (int32_t) INT32_C(73), 324u, l5);
        { vader_gc_top = gc_frame.prev; return true; }
    }
    if (l1 == 93u) {
        l5 = vader_lexer_position_here(l0);
        vader_lexer_advance(l0, (size_t) (int64_t) INT64_C(1));
        t1 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_paren_depth;
        if ((t1 > INT32_C(0))) {
            t1 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_paren_depth;
            l6 = (t1 - INT32_C(1));
            ((vader_struct_vader_lexer_Lexer_t*) l0)->f_paren_depth = l6;
            VADER_WRITE_BARRIER((vader_struct_vader_lexer_Lexer_t*) l0);
        }
        vader_lexer_push_simple(l0, (uint8_t) (int32_t) INT32_C(75), 854u, l5);
        { vader_gc_top = gc_frame.prev; return true; }
    }
    if (l1 == 123u) {
        l7 = vader_lexer_top_interp(l0);
        if (l7.tag == 701u) {
            l5 = l7.payload.obj;
            t2 = l7.payload.obj;
            t1 = ((vader_struct_vader_lexer_InterpFrame_t*) t2)->f_brace_depth;
            l6 = (t1 + INT32_C(1));
            ((vader_struct_vader_lexer_InterpFrame_t*) l5)->f_brace_depth = l6;
            VADER_WRITE_BARRIER((vader_struct_vader_lexer_InterpFrame_t*) l5);
        }
        t0 = vader_lexer_emit_and_advance(l0, (uint8_t) (int32_t) INT32_C(76), 2424u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 125u) {
        l7 = vader_lexer_top_interp(l0);
        if (l7.tag == 701u) {
            t2 = l7.payload.obj;
            t1 = ((vader_struct_vader_lexer_InterpFrame_t*) t2)->f_brace_depth;
            if ((t1 > INT32_C(0))) {
                l5 = l7.payload.obj;
                t2 = l7.payload.obj;
                t1 = ((vader_struct_vader_lexer_InterpFrame_t*) t2)->f_brace_depth;
                l6 = (t1 - INT32_C(1));
                ((vader_struct_vader_lexer_InterpFrame_t*) l5)->f_brace_depth = l6;
                VADER_WRITE_BARRIER((vader_struct_vader_lexer_InterpFrame_t*) l5);
            }
        }
        t0 = vader_lexer_emit_and_advance(l0, (uint8_t) (int32_t) INT32_C(77), 2433u);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return false; }
    vader_gc_top = gc_frame.prev;
}

