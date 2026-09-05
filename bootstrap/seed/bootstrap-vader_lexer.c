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
                t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l6, 172u);
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
                            t0 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) l9, 172u);
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
                        } else {
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
                        } else {
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
            } else {
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
                        vader_lexer_push_error(l0, (uint8_t) (int32_t) INT32_C(5), l10, 2246u);
                    } else {
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
            } else {
            }
        }
    }
    if (l3) {
        l10 = vader_lexer_error_span(l0, l2);
        vader_lexer_push_error(l0, (uint8_t) (int32_t) INT32_C(5), l10, 2246u);
    } else {
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
    vader_obj_header_init(_a0_obj, 477u);
    _a0_obj->f_file = l0;
    _a0_obj->f_offset = (size_t) (int64_t) INT64_C(0);
    _a0_obj->f_line = INT32_C(1);
    _a0_obj->f_column = INT32_C(1);
    l1 = (void*) _a0_obj;
    vader_struct_toolchain_span_Span_t* _a1_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a1_obj, 478u);
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
    vader_obj_header_init(_a0_obj, 478u);
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
    vader_obj_header_init(_a0_obj, 478u);
    _a0_obj->f_start = l2;
    _a0_obj->f_end = l5;
    l5 = (void*) _a0_obj;
    l5 = vader_lexer_make_token((uint8_t) (int32_t) INT32_C(7), l4, l5);
    ((vader_struct_vader_lexer_Token_t*) l5)->f_value = vader_box_string(166u, l4);
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
    } else {
    }
    t0 = vader_lexer_peek(l0);
    if (t0 == 10u) {
        vader_lexer_advance(l0, (size_t) (int64_t) INT64_C(1));
    } else {
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
    vader_obj_header_init(_a0_obj, 478u);
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
    if (l0 == INT32_C(2)) {
        return 1682u;
    }
    if (l0 == INT32_C(3)) {
        return 1722u;
    }
    if (l0 == INT32_C(4)) {
        return 1585u;
    }
    if (l0 == INT32_C(5)) {
        return 1354u;
    }
    if (l0 == INT32_C(6)) {
        return 2091u;
    }
    if (l0 == INT32_C(7)) {
        return 2093u;
    }
    if (l0 == INT32_C(8)) {
        return 2092u;
    }
    if (l0 == INT32_C(9)) {
        return 1729u;
    }
    if (l0 == INT32_C(10)) {
        return 1728u;
    }
    if (l0 == INT32_C(11)) {
        return 1770u;
    }
    if (l0 == INT32_C(12)) {
        return 1781u;
    }
    if (l0 == INT32_C(13)) {
        return 1782u;
    }
    if (l0 == INT32_C(14)) {
        return 1773u;
    }
    if (l0 == INT32_C(15)) {
        return 1767u;
    }
    if (l0 == INT32_C(16)) {
        return 1772u;
    }
    if (l0 == INT32_C(17)) {
        return 1766u;
    }
    if (l0 == INT32_C(18)) {
        return 1777u;
    }
    if (l0 == INT32_C(19)) {
        return 1776u;
    }
    if (l0 == INT32_C(20)) {
        return 1771u;
    }
    if (l0 == INT32_C(21)) {
        return 1775u;
    }
    if (l0 == INT32_C(22)) {
        return 1779u;
    }
    if (l0 == INT32_C(23)) {
        return 1784u;
    }
    if (l0 == INT32_C(24)) {
        return 1761u;
    }
    if (l0 == INT32_C(25)) {
        return 1765u;
    }
    if (l0 == INT32_C(26)) {
        return 1762u;
    }
    if (l0 == INT32_C(27)) {
        return 1764u;
    }
    if (l0 == INT32_C(28)) {
        return 1774u;
    }
    if (l0 == INT32_C(29)) {
        return 1760u;
    }
    if (l0 == INT32_C(30)) {
        return 1768u;
    }
    if (l0 == INT32_C(31)) {
        return 1783u;
    }
    if (l0 == INT32_C(32)) {
        return 1769u;
    }
    if (l0 == INT32_C(33)) {
        return 1778u;
    }
    if (l0 == INT32_C(34)) {
        return 1780u;
    }
    if (l0 == INT32_C(35)) {
        return 1763u;
    }
    if (l0 == INT32_C(36)) {
        return 1926u;
    }
    if (l0 == INT32_C(37)) {
        return 1853u;
    }
    if (l0 == INT32_C(38)) {
        return 2011u;
    }
    if (l0 == INT32_C(39)) {
        return 2001u;
    }
    if (l0 == INT32_C(40)) {
        return 1923u;
    }
    if (l0 == INT32_C(41)) {
        return 1174u;
    }
    if (l0 == INT32_C(42)) {
        return 1925u;
    }
    if (l0 == INT32_C(43)) {
        return 1345u;
    }
    if (l0 == INT32_C(44)) {
        return 2138u;
    }
    if (l0 == INT32_C(45)) {
        return 1989u;
    }
    if (l0 == INT32_C(46)) {
        return 1993u;
    }
    if (l0 == INT32_C(47)) {
        return 1474u;
    }
    if (l0 == INT32_C(48)) {
        return 1879u;
    }
    if (l0 == INT32_C(49)) {
        return 1819u;
    }
    if (l0 == INT32_C(50)) {
        return 1820u;
    }
    if (l0 == INT32_C(51)) {
        return 1627u;
    }
    if (l0 == INT32_C(52)) {
        return 1628u;
    }
    if (l0 == INT32_C(53)) {
        return 1181u;
    }
    if (l0 == INT32_C(54)) {
        return 1910u;
    }
    if (l0 == INT32_C(56)) {
        return 1935u;
    }
    if (l0 == INT32_C(55)) {
        return 1247u;
    }
    if (l0 == INT32_C(57)) {
        return 1236u;
    }
    if (l0 == INT32_C(58)) {
        return 1927u;
    }
    if (l0 == INT32_C(59)) {
        return 1854u;
    }
    if (l0 == INT32_C(60)) {
        return 2012u;
    }
    if (l0 == INT32_C(61)) {
        return 2002u;
    }
    if (l0 == INT32_C(62)) {
        return 1924u;
    }
    if (l0 == INT32_C(63)) {
        return 1422u;
    }
    if (l0 == INT32_C(64)) {
        return 1423u;
    }
    if (l0 == INT32_C(65)) {
        return 1937u;
    }
    if (l0 == INT32_C(66)) {
        return 1938u;
    }
    if (l0 == INT32_C(67)) {
        return 1443u;
    }
    if (l0 == INT32_C(68)) {
        return 1233u;
    }
    if (l0 == INT32_C(69)) {
        return 1551u;
    }
    if (l0 == INT32_C(70)) {
        return 1242u;
    }
    if (l0 == INT32_C(71)) {
        return 1441u;
    }
    if (l0 == INT32_C(72)) {
        return 1818u;
    }
    if (l0 == INT32_C(73)) {
        return 1975u;
    }
    if (l0 == INT32_C(74)) {
        return 1789u;
    }
    if (l0 == INT32_C(75)) {
        return 1941u;
    }
    if (l0 == INT32_C(76)) {
        return 1788u;
    }
    if (l0 == INT32_C(77)) {
        return 1940u;
    }
    if (l0 == INT32_C(78)) {
        return 1369u;
    }
    if (l0 == INT32_C(79)) {
        return 1442u;
    }
    if (l0 == INT32_C(80)) {
        return 1368u;
    }
    if (l0 == INT32_C(1)) {
        return 1882u;
    }
    if (l0 == INT32_C(0)) {
        return 1473u;
    }
    vader_unreachable("unreachable return in vader_lexer$kind_name");
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
            } else {
            }
        }
    }
    if ((l2 > INT32_C(0))) {
        l1 = vader_lexer_error_span(l0, l1);
        vader_lexer_push_error(l0, (uint8_t) (int32_t) INT32_C(2), l1, 0u);
    } else {
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_lexer_lex_char(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l12 = NULL;
    void* l25 = NULL;
    void* l30 = NULL;
    void* l31 = NULL;
    size_t l3, l4, l20, l23, l24, l26, l27;
    vader_string_t l5 = 0;
    vader_string_t l13 = 0;
    vader_string_t l28 = 0;
    uint32_t l6;
    bool l7, l14, l17;
    uint32_t l8, l9, l10, l15, l16, l18, l19, l21, l22;
    uint8_t l11, l29;
    uint32_t t0;
    void* t1 = NULL;
    bool t2;
    int32_t t3;
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l12, &l25, &l30, &l31, &t1 };
    vader_string_t* gc_atom_roots[3] = { &l5, &l13, &l28 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 8u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_lexer_position_here(l0);
    vader_lexer_advance(l0, (size_t) (int64_t) INT64_C(1));
    t0 = vader_lexer_peek(l0);
    if (t0 == 39u) {
        vader_lexer_advance(l0, (size_t) (int64_t) INT64_C(1));
        l2 = vader_lexer_error_span(l0, l1);
        vader_lexer_push_error(l0, (uint8_t) (int32_t) INT32_C(4), l2, 1356u);
        l2 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_bytes;
        l3 = ((vader_struct_toolchain_span_Position_t*) l1)->f_offset;
        l4 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
        vader_array_t* _a0_arr = vader_array_slice((vader_array_t*) l2, (size_t) l3, (size_t) l4);
        t1 = (void*) _a0_arr;
        l5 = vader_host_std_core_bytes_to_string(t1);
        l2 = vader_lexer_error_span(l0, l1);
        l2 = vader_lexer_make_token((uint8_t) (int32_t) INT32_C(5), l5, l2);
        ((vader_struct_vader_lexer_Token_t*) l2)->f_value = vader_box_i32(169u, INT32_C(0));
        VADER_WRITE_BARRIER((vader_struct_vader_lexer_Token_t*) l2);
        vader_lexer_emit(l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = vader_lexer_peek(l0);
    if (t0 == 92u) {
        l6 = vader_lexer_lex_escape(l0, true);
        l9 = vader_lexer_peek(l0);
        l10 = 39u;
        if (l9 != l10) {
            l11 = (uint8_t) (int32_t) INT32_C(4);
            l12 = vader_lexer_error_span(l0, l1);
            l13 = 1357u;
            vader_lexer_push_error(l0, l11, l12, l13);
            {
                loop_85: {
                    t2 = vader_lexer_at_end(l0);
                    if (!(t2)) {
                        l15 = vader_lexer_peek(l0);
                        l16 = 39u;
                        l14 = l15 != l16;
                    } else {
                        l14 = false;
                    }
                    if (l14) {
                        l18 = vader_lexer_peek(l0);
                        l19 = 10u;
                        l17 = l18 != l19;
                    } else {
                        l17 = false;
                    }
                    if (l17) {
                        l20 = (size_t) (int64_t) INT64_C(1);
                        vader_lexer_advance(l0, l20);
                        goto loop_85;
                    } else {
                    }
                }
            }
            l21 = vader_lexer_peek(l0);
            l22 = 39u;
            if (l21 == l22) {
                l23 = (size_t) (int64_t) INT64_C(1);
                vader_lexer_advance(l0, l23);
            } else {
            }
        } else {
            l24 = (size_t) (int64_t) INT64_C(1);
            vader_lexer_advance(l0, l24);
        }
        l25 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_bytes;
        l26 = ((vader_struct_toolchain_span_Position_t*) l1)->f_offset;
        l27 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
        vader_array_t* _a1_arr = vader_array_slice((vader_array_t*) l25, (size_t) l26, (size_t) l27);
        t1 = (void*) _a1_arr;
        l28 = vader_host_std_core_bytes_to_string(t1);
        l29 = (uint8_t) (int32_t) INT32_C(5);
        l30 = vader_lexer_error_span(l0, l1);
        l31 = vader_lexer_make_token(l29, l28, l30);
        ((vader_struct_vader_lexer_Token_t*) l31)->f_value = vader_box_i32(174u, (int32_t)(uint32_t) l6);
        VADER_WRITE_BARRIER((vader_struct_vader_lexer_Token_t*) l31);
        vader_lexer_emit(l0, l31);
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = vader_lexer_peek(l0);
    if (t0 == 10u) {
        l7 = true;
    } else {
        l7 = vader_lexer_at_end(l0);
    }
    if (l7) {
        l2 = vader_lexer_error_span(l0, l1);
        vader_lexer_push_error(l0, (uint8_t) (int32_t) INT32_C(4), l2, 2269u);
        l2 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_bytes;
        l3 = ((vader_struct_toolchain_span_Position_t*) l1)->f_offset;
        l4 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
        vader_array_t* _a2_arr = vader_array_slice((vader_array_t*) l2, (size_t) l3, (size_t) l4);
        t1 = (void*) _a2_arr;
        l5 = vader_host_std_core_bytes_to_string(t1);
        l2 = vader_lexer_error_span(l0, l1);
        l2 = vader_lexer_make_token((uint8_t) (int32_t) INT32_C(5), l5, l2);
        ((vader_struct_vader_lexer_Token_t*) l2)->f_value = vader_box_i32(169u, INT32_C(0));
        VADER_WRITE_BARRIER((vader_struct_vader_lexer_Token_t*) l2);
        vader_lexer_emit(l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l8 = vader_lexer_peek(l0);
    t3 = ((int32_t) (uint32_t) l8);
    l6 = (uint32_t) (int32_t) t3;
    l3 = std_string_codepoint_byte_len(l8);
    vader_lexer_advance(l0, l3);
    l9 = vader_lexer_peek(l0);
    l10 = 39u;
    if (l9 != l10) {
        l11 = (uint8_t) (int32_t) INT32_C(4);
        l12 = vader_lexer_error_span(l0, l1);
        l13 = 1357u;
        vader_lexer_push_error(l0, l11, l12, l13);
        {
            loop_272: {
                t2 = vader_lexer_at_end(l0);
                if (!(t2)) {
                    l15 = vader_lexer_peek(l0);
                    l16 = 39u;
                    l14 = l15 != l16;
                } else {
                    l14 = false;
                }
                if (l14) {
                    l18 = vader_lexer_peek(l0);
                    l19 = 10u;
                    l17 = l18 != l19;
                } else {
                    l17 = false;
                }
                if (l17) {
                    l20 = (size_t) (int64_t) INT64_C(1);
                    vader_lexer_advance(l0, l20);
                    goto loop_272;
                } else {
                }
            }
        }
        l21 = vader_lexer_peek(l0);
        l22 = 39u;
        if (l21 == l22) {
            l23 = (size_t) (int64_t) INT64_C(1);
            vader_lexer_advance(l0, l23);
        } else {
        }
    } else {
        l24 = (size_t) (int64_t) INT64_C(1);
        vader_lexer_advance(l0, l24);
    }
    l25 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_bytes;
    l26 = ((vader_struct_toolchain_span_Position_t*) l1)->f_offset;
    l27 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
    vader_array_t* _a3_arr = vader_array_slice((vader_array_t*) l25, (size_t) l26, (size_t) l27);
    t1 = (void*) _a3_arr;
    l28 = vader_host_std_core_bytes_to_string(t1);
    l29 = (uint8_t) (int32_t) INT32_C(5);
    l30 = vader_lexer_error_span(l0, l1);
    l31 = vader_lexer_make_token(l29, l28, l30);
    ((vader_struct_vader_lexer_Token_t*) l31)->f_value = vader_box_i32(174u, (int32_t)(uint32_t) l6);
    VADER_WRITE_BARRIER((vader_struct_vader_lexer_Token_t*) l31);
    vader_lexer_emit(l0, l31);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static uint32_t vader_lexer_lex_escape(void* l0, bool l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l8 = NULL;
    uint32_t l4;
    bool l5;
    vader_string_t l6 = 0;
    vader_string_t l9 = 0;
    vader_string_t l10 = 0;
    uint8_t l7;
    bool t0;
    uint32_t t1;
    void* t2 = NULL;
    void** gc_raw_roots[5] = { &l0, &l2, &l3, &l8, &t2 };
    vader_string_t* gc_atom_roots[3] = { &l6, &l9, &l10 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = vader_lexer_position_here(l0);
    vader_lexer_advance(l0, (size_t) (int64_t) INT64_C(1));
    t0 = vader_lexer_at_end(l0);
    if (t0) {
        l3 = vader_lexer_error_span(l0, l2);
        vader_lexer_push_error(l0, (uint8_t) (int32_t) INT32_C(3), l3, 1708u);
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
            l6 = concat_3(1478u, l6, 133u);
            vader_lexer_push_error(l0, (uint8_t) (int32_t) INT32_C(3), l3, l6);
            { uint32_t __vret = (uint32_t) (int32_t) ((int32_t) (uint32_t) l4); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = (uint8_t) (int32_t) INT32_C(3);
        l8 = vader_lexer_error_span(l0, l2);
        l6 = 2255u;
        t2 = std_core_utf8_encode(l4);
        l9 = vader_host_std_core_bytes_to_string(t2);
        l10 = concat_2(l6, l9);
        vader_lexer_push_error(l0, l7, l8, l10);
        { uint32_t __vret = (uint32_t) (int32_t) ((int32_t) (uint32_t) l4); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == 34u) {
        { vader_gc_top = gc_frame.prev; return (uint32_t) (int32_t) INT32_C(34); }
    }
    if (l4 == 36u) {
        { vader_gc_top = gc_frame.prev; return (uint32_t) (int32_t) INT32_C(36); }
    }
    if (l4 == 39u) {
        l3 = vader_lexer_error_span(l0, l2);
        vader_lexer_push_error(l0, (uint8_t) (int32_t) INT32_C(3), l3, 1479u);
        { uint32_t __vret = (uint32_t) (int32_t) ((int32_t) (uint32_t) l4); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l7 = (uint8_t) (int32_t) INT32_C(3);
    l8 = vader_lexer_error_span(l0, l2);
    l6 = 2255u;
    t2 = std_core_utf8_encode(l4);
    l9 = vader_host_std_core_bytes_to_string(t2);
    l10 = concat_2(l6, l9);
    vader_lexer_push_error(l0, l7, l8, l10);
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
            } else {
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
                } else {
                }
            }
        }
    } else {
    }
    if (l3 != INT32_C(10)) {
        vader_lexer_advance(l0, (size_t) (int64_t) INT64_C(2));
        l6 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
        vader_lexer_consume_digits(l0, l3, l1);
        t1 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
        if (t1 == l6) {
            l7 = vader_lexer_error_span(l0, l1);
            vader_lexer_push_error(l0, (uint8_t) (int32_t) INT32_C(5), l7, 1502u);
        } else {
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
        } else {
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
            } else {
            }
            t0 = vader_lexer_peek(l0);
            t2 = std_char_is_digit(t0);
            if (!(t2)) {
                l7 = vader_lexer_error_span(l0, l1);
                vader_lexer_push_error(l0, (uint8_t) (int32_t) INT32_C(5), l7, 1507u);
            } else {
            }
            vader_lexer_consume_digits(l0, INT32_C(10), l1);
        } else {
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
        } else {
        }
        l6 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
        {
            loop_252: {
                t2 = vader_lexer_at_end(l0);
                if (!(t2)) {
                    t0 = vader_lexer_peek(l0);
                    l5 = vader_lexer_is_ident_continue(t0);
                } else {
                    l5 = false;
                }
                if (l5) {
                    vader_lexer_advance(l0, (size_t) (int64_t) INT64_C(1));
                    goto loop_252;
                } else {
                }
            }
        }
        l7 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_bytes;
        l8 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
        vader_array_t* _a1_arr = vader_array_slice((vader_array_t*) l7, (size_t) l6, (size_t) l8);
        t3 = (void*) _a1_arr;
        l10 = vader_host_std_core_bytes_to_string(t3);
        l7 = vader_lexer_error_span(l0, l1);
        l10 = concat_3(2180u, l10, 981u);
        vader_lexer_push_error(l0, (uint8_t) (int32_t) INT32_C(5), l7, l10);
    } else {
    }
    l7 = vader_lexer_position_here(l0);
    vader_struct_toolchain_span_Span_t* _a2_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a2_obj, 478u);
    _a2_obj->f_start = l1;
    _a2_obj->f_end = l7;
    l7 = (void*) _a2_obj;
    l11 = (uint8_t) (int32_t) INT32_C(3);
    if (l2) {
        l11 = (uint8_t) (int32_t) INT32_C(4);
    } else {
    }
    l7 = vader_lexer_make_token(l11, l9, l7);
    l10 = std_numbers_strip_numeric_text(l9, l3);
    t2 = std_string_is_empty(l10);
    if (t2) {
        ((vader_struct_vader_lexer_Token_t*) l7)->f_value = vader_box_i64(170u, INT64_C(0));
        VADER_WRITE_BARRIER((vader_struct_vader_lexer_Token_t*) l7);
        vader_lexer_emit(l0, l7);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2) {
        l12 = std_string_parse_float(l10);
        if ((l12.tag == 162u || l12.tag == 163u)) {
            t4 = ((double) l12.payload.f);
            l13 = vader_box_f64(163u, t4);
            ((vader_struct_vader_lexer_Token_t*) l7)->f_value = l13;
            VADER_WRITE_BARRIER((vader_struct_vader_lexer_Token_t*) l7);
            vader_lexer_emit(l0, l7);
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l12.tag == 385u) {
            l13 = vader_box_f64(163u, 0.0);
            ((vader_struct_vader_lexer_Token_t*) l7)->f_value = l13;
            VADER_WRITE_BARRIER((vader_struct_vader_lexer_Token_t*) l7);
            vader_lexer_emit(l0, l7);
            { vader_gc_top = gc_frame.prev; return; }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    l12 = std_numbers_parse_uint_in_base(l10, l3);
    if (l12.tag == 175u) {
        l14 = ((uint64_t) l12.payload.i);
        ((vader_struct_vader_lexer_Token_t*) l7)->f_value = vader_box_i64(175u, (int64_t)(uint64_t) l14);
        VADER_WRITE_BARRIER((vader_struct_vader_lexer_Token_t*) l7);
        vader_lexer_emit(l0, l7);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l12.tag == 385u) {
        l1 = vader_lexer_error_span(l0, l1);
        l9 = concat_3(923u, l9, 946u);
        vader_lexer_push_error(l0, (uint8_t) (int32_t) INT32_C(10), l1, l9);
        ((vader_struct_vader_lexer_Token_t*) l7)->f_value = vader_box_i64(170u, INT64_C(0));
        VADER_WRITE_BARRIER((vader_struct_vader_lexer_Token_t*) l7);
        vader_lexer_emit(l0, l7);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_lexer_lex_one(void* l0) {
    vader_box_t l1 = vader_box_null();
    bool l2, l8, l12, l15, l20, l25, l29, l32, l34, l38, l41;
    void* l3 = NULL;
    void* l46 = NULL;
    void* l51 = NULL;
    void* l53 = NULL;
    void* l57 = NULL;
    uint32_t l4, l5, l6, l7, l10, l11, l13, l14, l16, l17, l19, l22, l23, l24, l27, l28, l30, l31, l33, l36, l37, l39, l40, l42, l43, l48;
    size_t l9, l18, l21, l26, l35, l44, l49, l54, l55;
    uint8_t l45, l50, l56;
    vader_string_t l47 = 0;
    vader_string_t l52 = 0;
    vader_string_t l58 = 0;
    bool t0;
    uint32_t t1;
    void* t2 = NULL;
    int32_t t3;
    vader_box_t t4 = vader_box_null();
    uint8_t t5;
    vader_box_t* gc_roots[2] = { &l1, &t4 };
    void** gc_raw_roots[7] = { &l0, &l3, &l46, &l51, &l53, &l57, &t2 };
    vader_string_t* gc_atom_roots[3] = { &l47, &l52, &l58 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_lexer_skip_horizontal(l0);
    t0 = vader_lexer_at_end(l0);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l1 = vader_lexer_top_interp(l0);
    if (l1.tag == 697u) {
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
            vader_lexer_push_simple(l0, (uint8_t) (int32_t) INT32_C(10), 2410u, l3);
            t2 = l1.payload.obj;
            l2 = ((vader_struct_vader_lexer_InterpFrame_t*) t2)->f_triple;
            vader_lexer_pop_interp(l0);
            vader_lexer_lex_string_body(l0, l2, false);
            { vader_gc_top = gc_frame.prev; return; }
        }
        l4 = vader_lexer_peek(l0);
        l5 = 10u;
        if (l4 == l5) {
            l2 = true;
        } else {
            l6 = 13u;
            l2 = l4 == l6;
        }
        if (l2) {
            vader_lexer_handle_newline(l0);
            { vader_gc_top = gc_frame.prev; return; }
        }
        l7 = 47u;
        if (l4 == l7) {
            l9 = (size_t) (int64_t) INT64_C(1);
            l10 = vader_lexer_peek_at(l0, l9);
            l11 = 47u;
            l8 = l10 == l11;
        } else {
            l8 = false;
        }
        if (l8) {
            {
                loop_104: {
                    t0 = vader_lexer_at_end(l0);
                    if (!(t0)) {
                        l13 = vader_lexer_peek(l0);
                        l14 = 10u;
                        l12 = l13 != l14;
                    } else {
                        l12 = false;
                    }
                    if (l12) {
                        l16 = vader_lexer_peek(l0);
                        l17 = 13u;
                        l15 = l16 != l17;
                    } else {
                        l15 = false;
                    }
                    if (l15) {
                        l18 = (size_t) (int64_t) INT64_C(1);
                        vader_lexer_advance(l0, l18);
                        goto loop_104;
                    } else {
                    }
                }
            }
            { vader_gc_top = gc_frame.prev; return; }
        }
        l19 = 47u;
        if (l4 == l19) {
            l21 = (size_t) (int64_t) INT64_C(1);
            l22 = vader_lexer_peek_at(l0, l21);
            l23 = 42u;
            l20 = l22 == l23;
        } else {
            l20 = false;
        }
        if (l20) {
            vader_lexer_lex_block_comment(l0);
            { vader_gc_top = gc_frame.prev; return; }
        }
        l24 = 114u;
        if (l4 == l24) {
            l26 = (size_t) (int64_t) INT64_C(1);
            l27 = vader_lexer_peek_at(l0, l26);
            l28 = 34u;
            l25 = l27 == l28;
        } else {
            l25 = false;
        }
        if (l25) {
            l29 = true;
            vader_lexer_lex_string(l0, l29);
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
        l30 = 39u;
        if (l4 == l30) {
            vader_lexer_lex_char(l0);
            { vader_gc_top = gc_frame.prev; return; }
        }
        l31 = 34u;
        if (l4 == l31) {
            l32 = false;
            vader_lexer_lex_string(l0, l32);
            { vader_gc_top = gc_frame.prev; return; }
        }
        t0 = vader_lexer_try_lex_operator(l0);
        if (t0) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        l3 = vader_lexer_position_here(l0);
        l33 = 35u;
        if (l4 == l33) {
            l35 = (size_t) (int64_t) INT64_C(1);
            l36 = vader_lexer_peek_at(l0, l35);
            l37 = 33u;
            l34 = l36 == l37;
        } else {
            l34 = false;
        }
        if (l34) {
            {
                loop_280: {
                    t0 = vader_lexer_at_end(l0);
                    if (!(t0)) {
                        l39 = vader_lexer_peek(l0);
                        l40 = 10u;
                        l38 = l39 != l40;
                    } else {
                        l38 = false;
                    }
                    if (l38) {
                        l42 = vader_lexer_peek(l0);
                        l43 = 13u;
                        l41 = l42 != l43;
                    } else {
                        l41 = false;
                    }
                    if (l41) {
                        l44 = (size_t) (int64_t) INT64_C(1);
                        vader_lexer_advance(l0, l44);
                        goto loop_280;
                    } else {
                    }
                }
            }
            l45 = (uint8_t) (int32_t) INT32_C(7);
            l46 = vader_lexer_error_span(l0, l3);
            l47 = 0u;
            vader_lexer_push_error(l0, l45, l46, l47);
            { vader_gc_top = gc_frame.prev; return; }
        }
        l48 = 92u;
        if (l4 == l48) {
            l49 = (size_t) (int64_t) INT64_C(1);
            vader_lexer_advance(l0, l49);
            l50 = (uint8_t) (int32_t) INT32_C(6);
            l51 = vader_lexer_error_span(l0, l3);
            l52 = 0u;
            vader_lexer_push_error(l0, l50, l51, l52);
            { vader_gc_top = gc_frame.prev; return; }
        }
        l53 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_bytes;
        l54 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l53);
        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
        if ((size_t) l54 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
        t4 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l54, 172u);
        t5 = ((uint8_t) t4.payload.i);
        l55 = std_string_utf8_lead_len(t5);
        vader_lexer_advance(l0, l55);
        l56 = (uint8_t) (int32_t) INT32_C(0);
        l57 = vader_lexer_error_span(l0, l3);
        l58 = 0u;
        vader_lexer_push_error(l0, l56, l57, l58);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 0u) {
        l4 = vader_lexer_peek(l0);
        l5 = 10u;
        if (l4 == l5) {
            l2 = true;
        } else {
            l6 = 13u;
            l2 = l4 == l6;
        }
        if (l2) {
            vader_lexer_handle_newline(l0);
            { vader_gc_top = gc_frame.prev; return; }
        }
        l7 = 47u;
        if (l4 == l7) {
            l9 = (size_t) (int64_t) INT64_C(1);
            l10 = vader_lexer_peek_at(l0, l9);
            l11 = 47u;
            l8 = l10 == l11;
        } else {
            l8 = false;
        }
        if (l8) {
            {
                loop_448: {
                    t0 = vader_lexer_at_end(l0);
                    if (!(t0)) {
                        l13 = vader_lexer_peek(l0);
                        l14 = 10u;
                        l12 = l13 != l14;
                    } else {
                        l12 = false;
                    }
                    if (l12) {
                        l16 = vader_lexer_peek(l0);
                        l17 = 13u;
                        l15 = l16 != l17;
                    } else {
                        l15 = false;
                    }
                    if (l15) {
                        l18 = (size_t) (int64_t) INT64_C(1);
                        vader_lexer_advance(l0, l18);
                        goto loop_448;
                    } else {
                    }
                }
            }
            { vader_gc_top = gc_frame.prev; return; }
        }
        l19 = 47u;
        if (l4 == l19) {
            l21 = (size_t) (int64_t) INT64_C(1);
            l22 = vader_lexer_peek_at(l0, l21);
            l23 = 42u;
            l20 = l22 == l23;
        } else {
            l20 = false;
        }
        if (l20) {
            vader_lexer_lex_block_comment(l0);
            { vader_gc_top = gc_frame.prev; return; }
        }
        l24 = 114u;
        if (l4 == l24) {
            l26 = (size_t) (int64_t) INT64_C(1);
            l27 = vader_lexer_peek_at(l0, l26);
            l28 = 34u;
            l25 = l27 == l28;
        } else {
            l25 = false;
        }
        if (l25) {
            l29 = true;
            vader_lexer_lex_string(l0, l29);
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
        l30 = 39u;
        if (l4 == l30) {
            vader_lexer_lex_char(l0);
            { vader_gc_top = gc_frame.prev; return; }
        }
        l31 = 34u;
        if (l4 == l31) {
            l32 = false;
            vader_lexer_lex_string(l0, l32);
            { vader_gc_top = gc_frame.prev; return; }
        }
        t0 = vader_lexer_try_lex_operator(l0);
        if (t0) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        l3 = vader_lexer_position_here(l0);
        l33 = 35u;
        if (l4 == l33) {
            l35 = (size_t) (int64_t) INT64_C(1);
            l36 = vader_lexer_peek_at(l0, l35);
            l37 = 33u;
            l34 = l36 == l37;
        } else {
            l34 = false;
        }
        if (l34) {
            {
                loop_624: {
                    t0 = vader_lexer_at_end(l0);
                    if (!(t0)) {
                        l39 = vader_lexer_peek(l0);
                        l40 = 10u;
                        l38 = l39 != l40;
                    } else {
                        l38 = false;
                    }
                    if (l38) {
                        l42 = vader_lexer_peek(l0);
                        l43 = 13u;
                        l41 = l42 != l43;
                    } else {
                        l41 = false;
                    }
                    if (l41) {
                        l44 = (size_t) (int64_t) INT64_C(1);
                        vader_lexer_advance(l0, l44);
                        goto loop_624;
                    } else {
                    }
                }
            }
            l45 = (uint8_t) (int32_t) INT32_C(7);
            l46 = vader_lexer_error_span(l0, l3);
            l47 = 0u;
            vader_lexer_push_error(l0, l45, l46, l47);
            { vader_gc_top = gc_frame.prev; return; }
        }
        l48 = 92u;
        if (l4 == l48) {
            l49 = (size_t) (int64_t) INT64_C(1);
            vader_lexer_advance(l0, l49);
            l50 = (uint8_t) (int32_t) INT32_C(6);
            l51 = vader_lexer_error_span(l0, l3);
            l52 = 0u;
            vader_lexer_push_error(l0, l50, l51, l52);
            { vader_gc_top = gc_frame.prev; return; }
        }
        l53 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_bytes;
        l54 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l53);
        if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
        if ((size_t) l54 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
        t4 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) l54, 172u);
        t5 = ((uint8_t) t4.payload.i);
        l55 = std_string_utf8_lead_len(t5);
        vader_lexer_advance(l0, l55);
        l56 = (uint8_t) (int32_t) INT32_C(0);
        l57 = vader_lexer_error_span(l0, l3);
        l58 = 0u;
        vader_lexer_push_error(l0, l56, l57, l58);
        { vader_gc_top = gc_frame.prev; return; }
    }
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
    } else {
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
            } else {
            }
        }
    } else {
    }
    l5 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_bytes;
    l6 = ((vader_struct_toolchain_span_Position_t*) l2)->f_offset;
    l7 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
    vader_array_t* _a0_arr = vader_array_slice((vader_array_t*) l5, (size_t) l6, (size_t) l7);
    t1 = (void*) _a0_arr;
    l8 = vader_host_std_core_bytes_to_string(t1);
    l5 = vader_lexer_position_here(l0);
    vader_struct_toolchain_span_Span_t* _a1_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a1_obj, 478u);
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
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 166u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 387u);
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
                    } else {
                    }
                } else {
                    if (l6 == 34u) {
                        l7 = true;
                    } else {
                    }
                }
                if (l7) {
                    vader_lexer_flush_string_part(l0, l4, l3, l5);
                    l10 = vader_lexer_position_here(l0);
                    l11 = 223u;
                    if (l1) {
                        vader_lexer_advance(l0, (size_t) (int64_t) INT64_C(3));
                        l11 = 225u;
                    } else {
                        vader_lexer_advance(l0, (size_t) (int64_t) INT64_C(1));
                    }
                    l12 = vader_lexer_position_here(l0);
                    vader_struct_toolchain_span_Span_t* _a2_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
                    vader_obj_header_init(_a2_obj, 478u);
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
                    vader_obj_header_init(_a3_obj, 478u);
                    _a3_obj->f_start = l3;
                    _a3_obj->f_end = l16;
                    l17 = (void*) _a3_obj;
                    vader_lexer_push_error(l0, (uint8_t) (int32_t) INT32_C(1), l17, 0u);
                    vader_lexer_flush_string_part(l0, l4, l3, l5);
                    l18 = vader_lexer_position_here(l0);
                    vader_struct_toolchain_span_Span_t* _a4_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
                    vader_obj_header_init(_a4_obj, 478u);
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
                    vader_obj_header_init(_a5_obj, 478u);
                    _a5_obj->f_start = l23;
                    _a5_obj->f_end = l24;
                    l25 = (void*) _a5_obj;
                    l26 = vader_lexer_make_token((uint8_t) (int32_t) INT32_C(9), 253u, l25);
                    vader_lexer_emit(l0, l26);
                    l27 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_interp_stack;
                    vader_struct_vader_lexer_InterpFrame_t* _a6_obj = (vader_struct_vader_lexer_InterpFrame_t*) vader_gc_alloc(sizeof(vader_struct_vader_lexer_InterpFrame_t));
                    vader_obj_header_init(_a6_obj, 697u);
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
                    vader_obj_header_init(_a7_obj, 478u);
                    _a7_obj->f_start = l31;
                    _a7_obj->f_end = l32;
                    l33 = (void*) _a7_obj;
                    l34 = vader_lexer_make_token((uint8_t) (int32_t) INT32_C(9), 241u, l33);
                    vader_lexer_emit(l0, l34);
                    vader_lexer_lex_ident(l0);
                    l35 = vader_lexer_position_here(l0);
                    vader_struct_toolchain_span_Span_t* _a8_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
                    vader_obj_header_init(_a8_obj, 478u);
                    _a8_obj->f_start = l35;
                    _a8_obj->f_end = l35;
                    l36 = (void*) _a8_obj;
                    l37 = vader_lexer_make_token((uint8_t) (int32_t) INT32_C(10), 0u, l36);
                    vader_lexer_emit(l0, l37);
                    l3 = vader_lexer_position_here(l0);
                    vader_array_t* _a9_arr = vader_array_new(8u, 0u, 0u, 166u);
                    t0 = (void*) _a9_arr;
                    vader_struct_std_string_builder_StringBuilder_t* _a10_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
                    vader_obj_header_init(_a10_obj, 387u);
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
            } else {
            }
        }
    }
    l10 = vader_lexer_position_here(l0);
    vader_struct_toolchain_span_Span_t* _a11_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a11_obj, 478u);
    _a11_obj->f_start = l3;
    _a11_obj->f_end = l10;
    l10 = (void*) _a11_obj;
    vader_lexer_push_error(l0, (uint8_t) (int32_t) INT32_C(1), l10, 0u);
    vader_lexer_flush_string_part(l0, l4, l3, l5);
    l3 = vader_lexer_position_here(l0);
    vader_struct_toolchain_span_Span_t* _a12_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a12_obj, 478u);
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
        vader_lexer_push_error(l0, (uint8_t) (int32_t) INT32_C(8), l2, 1484u);
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
                    l6 = 1746u;
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
                            } else {
                            }
                        }
                    }
                } else {
                    vader_lexer_advance(l0, (size_t) (int64_t) INT64_C(1));
                    goto loop_23;
                }
            } else {
            }
            t3 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_pos;
            t4 = (t3 - l3);
            l14 = (size_t) (int64_t) t4;
            l15 = vader_lexer_peek(l0);
            l16 = 125u;
            if (l15 == l16) {
                l17 = (size_t) (int64_t) INT64_C(1);
                vader_lexer_advance(l0, l17);
            } else {
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
                l23 = 1365u;
                vader_lexer_push_error(l0, l21, l22, l23);
                { vader_gc_top = gc_frame.prev; return (uint32_t) (int32_t) INT32_C(0); }
            }
            l24 = (uint32_t) (int32_t) INT32_C(0);
            l25 = (size_t) (int64_t) INT64_C(0);
            {
                loop_171: {
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
                        goto loop_171;
                    } else {
                    }
                }
            }
            t2 = ((int32_t) (uint32_t) ((uint32_t) (int32_t) INT32_C(1114111)));
            l33 = (uint32_t) (int32_t) t2;
            if ((l24 > l33)) {
                l34 = (uint8_t) (int32_t) INT32_C(8);
                l35 = vader_lexer_error_span(l0, l1);
                l36 = 1366u;
                vader_lexer_push_error(l0, l34, l35, l36);
                { vader_gc_top = gc_frame.prev; return (uint32_t) (int32_t) INT32_C(0); }
            }
            { uint32_t __vret = l24; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l5 = (uint8_t) (int32_t) INT32_C(8);
    l2 = vader_lexer_error_span(l0, l1);
    l6 = 1746u;
    vader_lexer_push_error(l0, l5, l2, l6);
    {
        loop_252: {
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
                goto loop_252;
            } else {
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
    } else {
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
        l23 = 1365u;
        vader_lexer_push_error(l0, l21, l22, l23);
        { vader_gc_top = gc_frame.prev; return (uint32_t) (int32_t) INT32_C(0); }
    }
    l24 = (uint32_t) (int32_t) INT32_C(0);
    l25 = (size_t) (int64_t) INT64_C(0);
    {
        loop_356: {
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
                goto loop_356;
            } else {
            }
        }
    }
    t2 = ((int32_t) (uint32_t) ((uint32_t) (int32_t) INT32_C(1114111)));
    l33 = (uint32_t) (int32_t) t2;
    if ((l24 > l33)) {
        l34 = (uint8_t) (int32_t) INT32_C(8);
        l35 = vader_lexer_error_span(l0, l1);
        l36 = 1366u;
        vader_lexer_push_error(l0, l34, l35, l36);
        { vader_gc_top = gc_frame.prev; return (uint32_t) (int32_t) INT32_C(0); }
    }
    { uint32_t __vret = l24; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static uint8_t vader_lexer_lookup_keyword(vader_string_t l0) {
    if (l0 == 1586u) {
        return (uint8_t) (int32_t) INT32_C(11);
    }
    if (l0 == 2094u) {
        return (uint8_t) (int32_t) INT32_C(12);
    }
    if (l0 == 2144u) {
        return (uint8_t) (int32_t) INT32_C(13);
    }
    if (l0 == 1694u) {
        return (uint8_t) (int32_t) INT32_C(14);
    }
    if (l0 == 1469u) {
        return (uint8_t) (int32_t) INT32_C(15);
    }
    if (l0 == 1684u) {
        return (uint8_t) (int32_t) INT32_C(16);
    }
    if (l0 == 1457u) {
        return (uint8_t) (int32_t) INT32_C(17);
    }
    if (l0 == 1828u) {
        return (uint8_t) (int32_t) INT32_C(18);
    }
    if (l0 == 1749u) {
        return (uint8_t) (int32_t) INT32_C(19);
    }
    if (l0 == 1593u) {
        return (uint8_t) (int32_t) INT32_C(20);
    }
    if (l0 == 1705u) {
        return (uint8_t) (int32_t) INT32_C(21);
    }
    if (l0 == 1964u) {
        return (uint8_t) (int32_t) INT32_C(22);
    }
    if (l0 == 2398u) {
        return (uint8_t) (int32_t) INT32_C(23);
    }
    if (l0 == 1244u) {
        return (uint8_t) (int32_t) INT32_C(24);
    }
    if (l0 == 1431u) {
        return (uint8_t) (int32_t) INT32_C(25);
    }
    if (l0 == 1274u) {
        return (uint8_t) (int32_t) INT32_C(26);
    }
    if (l0 == 1410u) {
        return (uint8_t) (int32_t) INT32_C(27);
    }
    if (l0 == 1695u) {
        return (uint8_t) (int32_t) INT32_C(28);
    }
    if (l0 == 1234u) {
        return (uint8_t) (int32_t) INT32_C(29);
    }
    if (l0 == 1508u) {
        return (uint8_t) (int32_t) INT32_C(30);
    }
    if (l0 == 2150u) {
        return (uint8_t) (int32_t) INT32_C(31);
    }
    if (l0 == 1550u) {
        return (uint8_t) (int32_t) INT32_C(32);
    }
    if (l0 == 1895u) {
        return (uint8_t) (int32_t) INT32_C(33);
    }
    if (l0 == 1984u) {
        return (uint8_t) (int32_t) INT32_C(34);
    }
    if (l0 == 1391u) {
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
    vader_obj_header_init(_a0_obj, 699u);
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
    vader_array_t* _a0_arr = vader_array_new(53u, 0u, 13u, 699u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(51u, 0u, 13u, 696u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(52u, 0u, 13u, 697u);
    l5 = (void*) _a2_arr;
    vader_struct_vader_lexer_Lexer_t* _a3_obj = (vader_struct_vader_lexer_Lexer_t*) vader_gc_alloc(sizeof(vader_struct_vader_lexer_Lexer_t));
    vader_obj_header_init(_a3_obj, 698u);
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
            } else {
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
    vader_obj_header_init(_a0_obj, 477u);
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
    vader_obj_header_init(_a0_obj, 478u);
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
                    goto loop_6;
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
                if (l4) {
                    vader_lexer_advance(l0, (size_t) (int64_t) INT64_C(1));
                    goto loop_6;
                }
                return;
            } else {
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
        t1 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) INT32_C(0), 172u);
        t2 = ((uint8_t) t1.payload.i);
        l3 = t2 == INT32_C(239);
    } else {
        l3 = false;
    }
    if (l3) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_lexer_Lexer_t*) l2)->f_bytes);
        if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
        if ((size_t) INT32_C(1) >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
        t1 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) INT32_C(1), 172u);
        t2 = ((uint8_t) t1.payload.i);
        l3 = t2 == INT32_C(187);
    } else {
        l3 = false;
    }
    if (l3) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_lexer_Lexer_t*) l2)->f_bytes);
        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
        if ((size_t) INT32_C(2) >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
        t1 = vader_array_read_u8(_a2_slotarr, _a2_slotarr->offset + (size_t) INT32_C(2), 172u);
        t2 = ((uint8_t) t1.payload.i);
        l3 = t2 == INT32_C(191);
    } else {
        l3 = false;
    }
    if (l3) {
        vader_lexer_advance(l2, (size_t) (int64_t) INT64_C(3));
    } else {
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
            loop_82: {
                t5 = vader_lexer_at_end(l2);
                if (!(t5)) {
                    t4 = vader_lexer_peek(l2);
                    l3 = t4 != 10u;
                } else {
                    l3 = false;
                }
                if (l3) {
                    vader_lexer_advance(l2, (size_t) (int64_t) INT64_C(1));
                    goto loop_82;
                } else {
                }
            }
        }
    } else {
    }
    {
        loop_109: {
            t5 = vader_lexer_at_end(l2);
            if (!(t5)) {
                vader_lexer_lex_one(l2);
                goto loop_109;
            } else {
            }
        }
    }
    l4 = vader_lexer_position_here(l2);
    vader_struct_toolchain_span_Span_t* _a3_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a3_obj, 478u);
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
    uint32_t l1, l2, l4, l5, l8, l10, l13, l15, l18, l20, l23, l25, l28, l30, l33, l35, l38, l40, l43, l45, l48, l50, l53, l55, l58, l60, l63, l65, l68, l70, l73, l75, l78, l80, l83, l85, l88, l90, l93, l96, l99, l102, l105, l108, l111, l114, l117, l120, l123, l126, l129, l132, l135, l138, l141, l144, l147, l155, l163, l173, l183, l191;
    bool l3, l9, l14, l19, l24, l29, l34, l39, l44, l49, l54, l59, l64, l69, l74, l79, l84, l89;
    uint8_t l6, l11, l16, l21, l26, l31, l36, l41, l46, l51, l56, l61, l66, l71, l76, l81, l86, l91, l94, l97, l100, l103, l106, l109, l112, l115, l118, l121, l124, l127, l130, l133, l136, l139, l142, l145, l153, l161, l171, l181, l189, l199;
    vader_string_t l7 = 0;
    vader_string_t l12 = 0;
    vader_string_t l17 = 0;
    vader_string_t l22 = 0;
    vader_string_t l27 = 0;
    vader_string_t l32 = 0;
    vader_string_t l37 = 0;
    vader_string_t l42 = 0;
    vader_string_t l47 = 0;
    vader_string_t l52 = 0;
    vader_string_t l57 = 0;
    vader_string_t l62 = 0;
    vader_string_t l67 = 0;
    vader_string_t l72 = 0;
    vader_string_t l77 = 0;
    vader_string_t l82 = 0;
    vader_string_t l87 = 0;
    vader_string_t l92 = 0;
    vader_string_t l95 = 0;
    vader_string_t l98 = 0;
    vader_string_t l101 = 0;
    vader_string_t l104 = 0;
    vader_string_t l107 = 0;
    vader_string_t l110 = 0;
    vader_string_t l113 = 0;
    vader_string_t l116 = 0;
    vader_string_t l119 = 0;
    vader_string_t l122 = 0;
    vader_string_t l125 = 0;
    vader_string_t l128 = 0;
    vader_string_t l131 = 0;
    vader_string_t l134 = 0;
    vader_string_t l137 = 0;
    vader_string_t l140 = 0;
    vader_string_t l143 = 0;
    vader_string_t l146 = 0;
    vader_string_t l154 = 0;
    vader_string_t l162 = 0;
    vader_string_t l172 = 0;
    vader_string_t l182 = 0;
    vader_string_t l190 = 0;
    vader_string_t l200 = 0;
    void* l148 = NULL;
    void* l156 = NULL;
    void* l164 = NULL;
    void* l174 = NULL;
    void* l185 = NULL;
    void* l195 = NULL;
    size_t l149, l157, l165, l175;
    int32_t l150, l151, l152, l158, l159, l160, l166, l167, l168, l169, l170, l176, l177, l178, l179, l180, l186, l187, l188, l193, l194, l196, l197, l198;
    vader_box_t l184 = vader_box_null(), l192 = vader_box_null();
    bool t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l184, &l192 };
    void** gc_raw_roots[8] = { &l0, &l148, &l156, &l164, &l174, &l185, &l195, &t1 };
    vader_string_t* gc_atom_roots[42] = { &l7, &l12, &l17, &l22, &l27, &l32, &l37, &l42, &l47, &l52, &l57, &l62, &l67, &l72, &l77, &l82, &l87, &l92, &l95, &l98, &l101, &l104, &l107, &l110, &l113, &l116, &l119, &l122, &l125, &l128, &l131, &l134, &l137, &l140, &l143, &l146, &l154, &l162, &l172, &l182, &l190, &l200 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 42u, gc_atom_roots };
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
            t0 = vader_lexer_emit_and_advance(l0, (uint8_t) (int32_t) INT32_C(65), 411u);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l4 == 61u) {
            t0 = vader_lexer_emit_and_advance(l0, (uint8_t) (int32_t) INT32_C(66), 412u);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l4 == 46u) {
            t0 = vader_lexer_emit_and_advance(l0, (uint8_t) (int32_t) INT32_C(67), 409u);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l4 = 61u;
        if (l1 == l4) {
            l5 = 61u;
            l3 = l2 == l5;
        } else {
            l3 = false;
        }
        if (l3) {
            l6 = (uint8_t) (int32_t) INT32_C(47);
            l7 = 515u;
            t0 = vader_lexer_emit_and_advance(l0, l6, l7);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l8 = 33u;
        if (l1 == l8) {
            l10 = 61u;
            l9 = l2 == l10;
        } else {
            l9 = false;
        }
        if (l9) {
            l11 = (uint8_t) (int32_t) INT32_C(48);
            l12 = 220u;
            t0 = vader_lexer_emit_and_advance(l0, l11, l12);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l13 = 60u;
        if (l1 == l13) {
            l15 = 61u;
            l14 = l2 == l15;
        } else {
            l14 = false;
        }
        if (l14) {
            l16 = (uint8_t) (int32_t) INT32_C(50);
            l17 = 500u;
            t0 = vader_lexer_emit_and_advance(l0, l16, l17);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l18 = 62u;
        if (l1 == l18) {
            l20 = 61u;
            l19 = l2 == l20;
        } else {
            l19 = false;
        }
        if (l19) {
            l21 = (uint8_t) (int32_t) INT32_C(52);
            l22 = 518u;
            t0 = vader_lexer_emit_and_advance(l0, l21, l22);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l23 = 38u;
        if (l1 == l23) {
            l25 = 38u;
            l24 = l2 == l25;
        } else {
            l24 = false;
        }
        if (l24) {
            l26 = (uint8_t) (int32_t) INT32_C(53);
            l27 = 257u;
            t0 = vader_lexer_emit_and_advance(l0, l26, l27);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l28 = 124u;
        if (l1 == l28) {
            l30 = 124u;
            l29 = l2 == l30;
        } else {
            l29 = false;
        }
        if (l29) {
            l31 = (uint8_t) (int32_t) INT32_C(54);
            l32 = 2409u;
            t0 = vader_lexer_emit_and_advance(l0, l31, l32);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l33 = 63u;
        if (l1 == l33) {
            l35 = 63u;
            l34 = l2 == l35;
        } else {
            l34 = false;
        }
        if (l34) {
            l36 = (uint8_t) (int32_t) INT32_C(56);
            l37 = 522u;
            t0 = vader_lexer_emit_and_advance(l0, l36, l37);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l38 = 60u;
        if (l1 == l38) {
            l40 = 60u;
            l39 = l2 == l40;
        } else {
            l39 = false;
        }
        if (l39) {
            l41 = (uint8_t) (int32_t) INT32_C(45);
            l42 = 499u;
            t0 = vader_lexer_emit_and_advance(l0, l41, l42);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l43 = 62u;
        if (l1 == l43) {
            l45 = 62u;
            l44 = l2 == l45;
        } else {
            l44 = false;
        }
        if (l44) {
            l46 = (uint8_t) (int32_t) INT32_C(46);
            l47 = 519u;
            t0 = vader_lexer_emit_and_advance(l0, l46, l47);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l48 = 45u;
        if (l1 == l48) {
            l50 = 62u;
            l49 = l2 == l50;
        } else {
            l49 = false;
        }
        if (l49) {
            l51 = (uint8_t) (int32_t) INT32_C(68);
            l52 = 386u;
            t0 = vader_lexer_emit_and_advance(l0, l51, l52);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l53 = 61u;
        if (l1 == l53) {
            l55 = 62u;
            l54 = l2 == l55;
        } else {
            l54 = false;
        }
        if (l54) {
            l56 = (uint8_t) (int32_t) INT32_C(69);
            l57 = 516u;
            t0 = vader_lexer_emit_and_advance(l0, l56, l57);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l58 = 58u;
        if (l1 == l58) {
            l60 = 58u;
            l59 = l2 == l60;
        } else {
            l59 = false;
        }
        if (l59) {
            l61 = (uint8_t) (int32_t) INT32_C(63);
            l62 = 491u;
            t0 = vader_lexer_emit_and_advance(l0, l61, l62);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l63 = 58u;
        if (l1 == l63) {
            l65 = 61u;
            l64 = l2 == l65;
        } else {
            l64 = false;
        }
        if (l64) {
            l66 = (uint8_t) (int32_t) INT32_C(64);
            l67 = 493u;
            t0 = vader_lexer_emit_and_advance(l0, l66, l67);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l68 = 43u;
        if (l1 == l68) {
            l70 = 61u;
            l69 = l2 == l70;
        } else {
            l69 = false;
        }
        if (l69) {
            l71 = (uint8_t) (int32_t) INT32_C(58);
            l72 = 362u;
            t0 = vader_lexer_emit_and_advance(l0, l71, l72);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l73 = 45u;
        if (l1 == l73) {
            l75 = 61u;
            l74 = l2 == l75;
        } else {
            l74 = false;
        }
        if (l74) {
            l76 = (uint8_t) (int32_t) INT32_C(59);
            l77 = 385u;
            t0 = vader_lexer_emit_and_advance(l0, l76, l77);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l78 = 42u;
        if (l1 == l78) {
            l80 = 61u;
            l79 = l2 == l80;
        } else {
            l79 = false;
        }
        if (l79) {
            l81 = (uint8_t) (int32_t) INT32_C(60);
            l82 = 360u;
            t0 = vader_lexer_emit_and_advance(l0, l81, l82);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l83 = 47u;
        if (l1 == l83) {
            l85 = 61u;
            l84 = l2 == l85;
        } else {
            l84 = false;
        }
        if (l84) {
            l86 = (uint8_t) (int32_t) INT32_C(61);
            l87 = 443u;
            t0 = vader_lexer_emit_and_advance(l0, l86, l87);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l88 = 37u;
        if (l1 == l88) {
            l90 = 61u;
            l89 = l2 == l90;
        } else {
            l89 = false;
        }
        if (l89) {
            l91 = (uint8_t) (int32_t) INT32_C(62);
            l92 = 255u;
            t0 = vader_lexer_emit_and_advance(l0, l91, l92);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l93 = 43u;
        if (l1 == l93) {
            l94 = (uint8_t) (int32_t) INT32_C(36);
            l95 = 361u;
            t0 = vader_lexer_emit_and_advance(l0, l94, l95);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l96 = 45u;
        if (l1 == l96) {
            l97 = (uint8_t) (int32_t) INT32_C(37);
            l98 = 382u;
            t0 = vader_lexer_emit_and_advance(l0, l97, l98);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l99 = 42u;
        if (l1 == l99) {
            l100 = (uint8_t) (int32_t) INT32_C(38);
            l101 = 352u;
            t0 = vader_lexer_emit_and_advance(l0, l100, l101);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l102 = 47u;
        if (l1 == l102) {
            l103 = (uint8_t) (int32_t) INT32_C(39);
            l104 = 430u;
            t0 = vader_lexer_emit_and_advance(l0, l103, l104);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l105 = 37u;
        if (l1 == l105) {
            l106 = (uint8_t) (int32_t) INT32_C(40);
            l107 = 254u;
            t0 = vader_lexer_emit_and_advance(l0, l106, l107);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l108 = 38u;
        if (l1 == l108) {
            l109 = (uint8_t) (int32_t) INT32_C(41);
            l110 = 256u;
            t0 = vader_lexer_emit_and_advance(l0, l109, l110);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l111 = 124u;
        if (l1 == l111) {
            l112 = (uint8_t) (int32_t) INT32_C(42);
            l113 = 2408u;
            t0 = vader_lexer_emit_and_advance(l0, l112, l113);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l114 = 94u;
        if (l1 == l114) {
            l115 = (uint8_t) (int32_t) INT32_C(43);
            l116 = 861u;
            t0 = vader_lexer_emit_and_advance(l0, l115, l116);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l117 = 126u;
        if (l1 == l117) {
            l118 = (uint8_t) (int32_t) INT32_C(44);
            l119 = 2415u;
            t0 = vader_lexer_emit_and_advance(l0, l118, l119);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l120 = 60u;
        if (l1 == l120) {
            l121 = (uint8_t) (int32_t) INT32_C(49);
            l122 = 498u;
            t0 = vader_lexer_emit_and_advance(l0, l121, l122);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l123 = 62u;
        if (l1 == l123) {
            l124 = (uint8_t) (int32_t) INT32_C(51);
            l125 = 517u;
            t0 = vader_lexer_emit_and_advance(l0, l124, l125);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l126 = 33u;
        if (l1 == l126) {
            l127 = (uint8_t) (int32_t) INT32_C(55);
            l128 = 219u;
            t0 = vader_lexer_emit_and_advance(l0, l127, l128);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l129 = 61u;
        if (l1 == l129) {
            l130 = (uint8_t) (int32_t) INT32_C(57);
            l131 = 514u;
            t0 = vader_lexer_emit_and_advance(l0, l130, l131);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l132 = 64u;
        if (l1 == l132) {
            l133 = (uint8_t) (int32_t) INT32_C(70);
            l134 = 523u;
            t0 = vader_lexer_emit_and_advance(l0, l133, l134);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l135 = 36u;
        if (l1 == l135) {
            l136 = (uint8_t) (int32_t) INT32_C(71);
            l137 = 241u;
            t0 = vader_lexer_emit_and_advance(l0, l136, l137);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l138 = 58u;
        if (l1 == l138) {
            l139 = (uint8_t) (int32_t) INT32_C(80);
            l140 = 462u;
            t0 = vader_lexer_emit_and_advance(l0, l139, l140);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l141 = 44u;
        if (l1 == l141) {
            l142 = (uint8_t) (int32_t) INT32_C(78);
            l143 = 364u;
            t0 = vader_lexer_emit_and_advance(l0, l142, l143);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l144 = 46u;
        if (l1 == l144) {
            l145 = (uint8_t) (int32_t) INT32_C(79);
            l146 = 407u;
            t0 = vader_lexer_emit_and_advance(l0, l145, l146);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l147 = 40u;
        if (l1 == l147) {
            l148 = vader_lexer_position_here(l0);
            l149 = (size_t) (int64_t) INT64_C(1);
            vader_lexer_advance(l0, l149);
            l150 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_paren_depth;
            l151 = INT32_C(1);
            l152 = (l150 + l151);
            ((vader_struct_vader_lexer_Lexer_t*) l0)->f_paren_depth = l152;
            VADER_WRITE_BARRIER((vader_struct_vader_lexer_Lexer_t*) l0);
            l153 = (uint8_t) (int32_t) INT32_C(72);
            l154 = 278u;
            vader_lexer_push_simple(l0, l153, l154, l148);
            { vader_gc_top = gc_frame.prev; return true; }
        }
        l155 = 91u;
        if (l1 == l155) {
            l156 = vader_lexer_position_here(l0);
            l157 = (size_t) (int64_t) INT64_C(1);
            vader_lexer_advance(l0, l157);
            l158 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_paren_depth;
            l159 = INT32_C(1);
            l160 = (l158 + l159);
            ((vader_struct_vader_lexer_Lexer_t*) l0)->f_paren_depth = l160;
            VADER_WRITE_BARRIER((vader_struct_vader_lexer_Lexer_t*) l0);
            l161 = (uint8_t) (int32_t) INT32_C(74);
            l162 = 843u;
            vader_lexer_push_simple(l0, l161, l162, l156);
            { vader_gc_top = gc_frame.prev; return true; }
        }
        l163 = 41u;
        if (l1 == l163) {
            l164 = vader_lexer_position_here(l0);
            l165 = (size_t) (int64_t) INT64_C(1);
            vader_lexer_advance(l0, l165);
            l166 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_paren_depth;
            l167 = INT32_C(0);
            if ((l166 > l167)) {
                l168 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_paren_depth;
                l169 = INT32_C(1);
                l170 = (l168 - l169);
                ((vader_struct_vader_lexer_Lexer_t*) l0)->f_paren_depth = l170;
                VADER_WRITE_BARRIER((vader_struct_vader_lexer_Lexer_t*) l0);
            } else {
            }
            l171 = (uint8_t) (int32_t) INT32_C(73);
            l172 = 318u;
            vader_lexer_push_simple(l0, l171, l172, l164);
            { vader_gc_top = gc_frame.prev; return true; }
        }
        l173 = 93u;
        if (l1 == l173) {
            l174 = vader_lexer_position_here(l0);
            l175 = (size_t) (int64_t) INT64_C(1);
            vader_lexer_advance(l0, l175);
            l176 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_paren_depth;
            l177 = INT32_C(0);
            if ((l176 > l177)) {
                l178 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_paren_depth;
                l179 = INT32_C(1);
                l180 = (l178 - l179);
                ((vader_struct_vader_lexer_Lexer_t*) l0)->f_paren_depth = l180;
                VADER_WRITE_BARRIER((vader_struct_vader_lexer_Lexer_t*) l0);
            } else {
            }
            l181 = (uint8_t) (int32_t) INT32_C(75);
            l182 = 847u;
            vader_lexer_push_simple(l0, l181, l182, l174);
            { vader_gc_top = gc_frame.prev; return true; }
        }
        l183 = 123u;
        if (l1 == l183) {
            l184 = vader_lexer_top_interp(l0);
            if (l184.tag == 697u) {
                l185 = l184.payload.obj;
                t1 = l184.payload.obj;
                l186 = ((vader_struct_vader_lexer_InterpFrame_t*) t1)->f_brace_depth;
                l187 = INT32_C(1);
                l188 = (l186 + l187);
                ((vader_struct_vader_lexer_InterpFrame_t*) l185)->f_brace_depth = l188;
                VADER_WRITE_BARRIER((vader_struct_vader_lexer_InterpFrame_t*) l185);
            } else {
            }
            l189 = (uint8_t) (int32_t) INT32_C(76);
            l190 = 2401u;
            t0 = vader_lexer_emit_and_advance(l0, l189, l190);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l191 = 125u;
        if (l1 == l191) {
            l192 = vader_lexer_top_interp(l0);
            if (l192.tag == 697u) {
                t1 = l192.payload.obj;
                l193 = ((vader_struct_vader_lexer_InterpFrame_t*) t1)->f_brace_depth;
                l194 = INT32_C(0);
                if ((l193 > l194)) {
                    l195 = l192.payload.obj;
                    t1 = l192.payload.obj;
                    l196 = ((vader_struct_vader_lexer_InterpFrame_t*) t1)->f_brace_depth;
                    l197 = INT32_C(1);
                    l198 = (l196 - l197);
                    ((vader_struct_vader_lexer_InterpFrame_t*) l195)->f_brace_depth = l198;
                    VADER_WRITE_BARRIER((vader_struct_vader_lexer_InterpFrame_t*) l195);
                } else {
                }
            } else {
            }
            l199 = (uint8_t) (int32_t) INT32_C(77);
            l200 = 2410u;
            t0 = vader_lexer_emit_and_advance(l0, l199, l200);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_gc_top = gc_frame.prev; return false; }
    }
    l4 = 61u;
    if (l1 == l4) {
        l5 = 61u;
        l3 = l2 == l5;
    } else {
        l3 = false;
    }
    if (l3) {
        l6 = (uint8_t) (int32_t) INT32_C(47);
        l7 = 515u;
        t0 = vader_lexer_emit_and_advance(l0, l6, l7);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l8 = 33u;
    if (l1 == l8) {
        l10 = 61u;
        l9 = l2 == l10;
    } else {
        l9 = false;
    }
    if (l9) {
        l11 = (uint8_t) (int32_t) INT32_C(48);
        l12 = 220u;
        t0 = vader_lexer_emit_and_advance(l0, l11, l12);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l13 = 60u;
    if (l1 == l13) {
        l15 = 61u;
        l14 = l2 == l15;
    } else {
        l14 = false;
    }
    if (l14) {
        l16 = (uint8_t) (int32_t) INT32_C(50);
        l17 = 500u;
        t0 = vader_lexer_emit_and_advance(l0, l16, l17);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l18 = 62u;
    if (l1 == l18) {
        l20 = 61u;
        l19 = l2 == l20;
    } else {
        l19 = false;
    }
    if (l19) {
        l21 = (uint8_t) (int32_t) INT32_C(52);
        l22 = 518u;
        t0 = vader_lexer_emit_and_advance(l0, l21, l22);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l23 = 38u;
    if (l1 == l23) {
        l25 = 38u;
        l24 = l2 == l25;
    } else {
        l24 = false;
    }
    if (l24) {
        l26 = (uint8_t) (int32_t) INT32_C(53);
        l27 = 257u;
        t0 = vader_lexer_emit_and_advance(l0, l26, l27);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l28 = 124u;
    if (l1 == l28) {
        l30 = 124u;
        l29 = l2 == l30;
    } else {
        l29 = false;
    }
    if (l29) {
        l31 = (uint8_t) (int32_t) INT32_C(54);
        l32 = 2409u;
        t0 = vader_lexer_emit_and_advance(l0, l31, l32);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l33 = 63u;
    if (l1 == l33) {
        l35 = 63u;
        l34 = l2 == l35;
    } else {
        l34 = false;
    }
    if (l34) {
        l36 = (uint8_t) (int32_t) INT32_C(56);
        l37 = 522u;
        t0 = vader_lexer_emit_and_advance(l0, l36, l37);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l38 = 60u;
    if (l1 == l38) {
        l40 = 60u;
        l39 = l2 == l40;
    } else {
        l39 = false;
    }
    if (l39) {
        l41 = (uint8_t) (int32_t) INT32_C(45);
        l42 = 499u;
        t0 = vader_lexer_emit_and_advance(l0, l41, l42);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l43 = 62u;
    if (l1 == l43) {
        l45 = 62u;
        l44 = l2 == l45;
    } else {
        l44 = false;
    }
    if (l44) {
        l46 = (uint8_t) (int32_t) INT32_C(46);
        l47 = 519u;
        t0 = vader_lexer_emit_and_advance(l0, l46, l47);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l48 = 45u;
    if (l1 == l48) {
        l50 = 62u;
        l49 = l2 == l50;
    } else {
        l49 = false;
    }
    if (l49) {
        l51 = (uint8_t) (int32_t) INT32_C(68);
        l52 = 386u;
        t0 = vader_lexer_emit_and_advance(l0, l51, l52);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l53 = 61u;
    if (l1 == l53) {
        l55 = 62u;
        l54 = l2 == l55;
    } else {
        l54 = false;
    }
    if (l54) {
        l56 = (uint8_t) (int32_t) INT32_C(69);
        l57 = 516u;
        t0 = vader_lexer_emit_and_advance(l0, l56, l57);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l58 = 58u;
    if (l1 == l58) {
        l60 = 58u;
        l59 = l2 == l60;
    } else {
        l59 = false;
    }
    if (l59) {
        l61 = (uint8_t) (int32_t) INT32_C(63);
        l62 = 491u;
        t0 = vader_lexer_emit_and_advance(l0, l61, l62);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l63 = 58u;
    if (l1 == l63) {
        l65 = 61u;
        l64 = l2 == l65;
    } else {
        l64 = false;
    }
    if (l64) {
        l66 = (uint8_t) (int32_t) INT32_C(64);
        l67 = 493u;
        t0 = vader_lexer_emit_and_advance(l0, l66, l67);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l68 = 43u;
    if (l1 == l68) {
        l70 = 61u;
        l69 = l2 == l70;
    } else {
        l69 = false;
    }
    if (l69) {
        l71 = (uint8_t) (int32_t) INT32_C(58);
        l72 = 362u;
        t0 = vader_lexer_emit_and_advance(l0, l71, l72);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l73 = 45u;
    if (l1 == l73) {
        l75 = 61u;
        l74 = l2 == l75;
    } else {
        l74 = false;
    }
    if (l74) {
        l76 = (uint8_t) (int32_t) INT32_C(59);
        l77 = 385u;
        t0 = vader_lexer_emit_and_advance(l0, l76, l77);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l78 = 42u;
    if (l1 == l78) {
        l80 = 61u;
        l79 = l2 == l80;
    } else {
        l79 = false;
    }
    if (l79) {
        l81 = (uint8_t) (int32_t) INT32_C(60);
        l82 = 360u;
        t0 = vader_lexer_emit_and_advance(l0, l81, l82);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l83 = 47u;
    if (l1 == l83) {
        l85 = 61u;
        l84 = l2 == l85;
    } else {
        l84 = false;
    }
    if (l84) {
        l86 = (uint8_t) (int32_t) INT32_C(61);
        l87 = 443u;
        t0 = vader_lexer_emit_and_advance(l0, l86, l87);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l88 = 37u;
    if (l1 == l88) {
        l90 = 61u;
        l89 = l2 == l90;
    } else {
        l89 = false;
    }
    if (l89) {
        l91 = (uint8_t) (int32_t) INT32_C(62);
        l92 = 255u;
        t0 = vader_lexer_emit_and_advance(l0, l91, l92);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l93 = 43u;
    if (l1 == l93) {
        l94 = (uint8_t) (int32_t) INT32_C(36);
        l95 = 361u;
        t0 = vader_lexer_emit_and_advance(l0, l94, l95);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l96 = 45u;
    if (l1 == l96) {
        l97 = (uint8_t) (int32_t) INT32_C(37);
        l98 = 382u;
        t0 = vader_lexer_emit_and_advance(l0, l97, l98);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l99 = 42u;
    if (l1 == l99) {
        l100 = (uint8_t) (int32_t) INT32_C(38);
        l101 = 352u;
        t0 = vader_lexer_emit_and_advance(l0, l100, l101);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l102 = 47u;
    if (l1 == l102) {
        l103 = (uint8_t) (int32_t) INT32_C(39);
        l104 = 430u;
        t0 = vader_lexer_emit_and_advance(l0, l103, l104);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l105 = 37u;
    if (l1 == l105) {
        l106 = (uint8_t) (int32_t) INT32_C(40);
        l107 = 254u;
        t0 = vader_lexer_emit_and_advance(l0, l106, l107);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l108 = 38u;
    if (l1 == l108) {
        l109 = (uint8_t) (int32_t) INT32_C(41);
        l110 = 256u;
        t0 = vader_lexer_emit_and_advance(l0, l109, l110);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l111 = 124u;
    if (l1 == l111) {
        l112 = (uint8_t) (int32_t) INT32_C(42);
        l113 = 2408u;
        t0 = vader_lexer_emit_and_advance(l0, l112, l113);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l114 = 94u;
    if (l1 == l114) {
        l115 = (uint8_t) (int32_t) INT32_C(43);
        l116 = 861u;
        t0 = vader_lexer_emit_and_advance(l0, l115, l116);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l117 = 126u;
    if (l1 == l117) {
        l118 = (uint8_t) (int32_t) INT32_C(44);
        l119 = 2415u;
        t0 = vader_lexer_emit_and_advance(l0, l118, l119);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l120 = 60u;
    if (l1 == l120) {
        l121 = (uint8_t) (int32_t) INT32_C(49);
        l122 = 498u;
        t0 = vader_lexer_emit_and_advance(l0, l121, l122);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l123 = 62u;
    if (l1 == l123) {
        l124 = (uint8_t) (int32_t) INT32_C(51);
        l125 = 517u;
        t0 = vader_lexer_emit_and_advance(l0, l124, l125);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l126 = 33u;
    if (l1 == l126) {
        l127 = (uint8_t) (int32_t) INT32_C(55);
        l128 = 219u;
        t0 = vader_lexer_emit_and_advance(l0, l127, l128);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l129 = 61u;
    if (l1 == l129) {
        l130 = (uint8_t) (int32_t) INT32_C(57);
        l131 = 514u;
        t0 = vader_lexer_emit_and_advance(l0, l130, l131);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l132 = 64u;
    if (l1 == l132) {
        l133 = (uint8_t) (int32_t) INT32_C(70);
        l134 = 523u;
        t0 = vader_lexer_emit_and_advance(l0, l133, l134);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l135 = 36u;
    if (l1 == l135) {
        l136 = (uint8_t) (int32_t) INT32_C(71);
        l137 = 241u;
        t0 = vader_lexer_emit_and_advance(l0, l136, l137);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l138 = 58u;
    if (l1 == l138) {
        l139 = (uint8_t) (int32_t) INT32_C(80);
        l140 = 462u;
        t0 = vader_lexer_emit_and_advance(l0, l139, l140);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l141 = 44u;
    if (l1 == l141) {
        l142 = (uint8_t) (int32_t) INT32_C(78);
        l143 = 364u;
        t0 = vader_lexer_emit_and_advance(l0, l142, l143);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l144 = 46u;
    if (l1 == l144) {
        l145 = (uint8_t) (int32_t) INT32_C(79);
        l146 = 407u;
        t0 = vader_lexer_emit_and_advance(l0, l145, l146);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l147 = 40u;
    if (l1 == l147) {
        l148 = vader_lexer_position_here(l0);
        l149 = (size_t) (int64_t) INT64_C(1);
        vader_lexer_advance(l0, l149);
        l150 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_paren_depth;
        l151 = INT32_C(1);
        l152 = (l150 + l151);
        ((vader_struct_vader_lexer_Lexer_t*) l0)->f_paren_depth = l152;
        VADER_WRITE_BARRIER((vader_struct_vader_lexer_Lexer_t*) l0);
        l153 = (uint8_t) (int32_t) INT32_C(72);
        l154 = 278u;
        vader_lexer_push_simple(l0, l153, l154, l148);
        { vader_gc_top = gc_frame.prev; return true; }
    }
    l155 = 91u;
    if (l1 == l155) {
        l156 = vader_lexer_position_here(l0);
        l157 = (size_t) (int64_t) INT64_C(1);
        vader_lexer_advance(l0, l157);
        l158 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_paren_depth;
        l159 = INT32_C(1);
        l160 = (l158 + l159);
        ((vader_struct_vader_lexer_Lexer_t*) l0)->f_paren_depth = l160;
        VADER_WRITE_BARRIER((vader_struct_vader_lexer_Lexer_t*) l0);
        l161 = (uint8_t) (int32_t) INT32_C(74);
        l162 = 843u;
        vader_lexer_push_simple(l0, l161, l162, l156);
        { vader_gc_top = gc_frame.prev; return true; }
    }
    l163 = 41u;
    if (l1 == l163) {
        l164 = vader_lexer_position_here(l0);
        l165 = (size_t) (int64_t) INT64_C(1);
        vader_lexer_advance(l0, l165);
        l166 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_paren_depth;
        l167 = INT32_C(0);
        if ((l166 > l167)) {
            l168 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_paren_depth;
            l169 = INT32_C(1);
            l170 = (l168 - l169);
            ((vader_struct_vader_lexer_Lexer_t*) l0)->f_paren_depth = l170;
            VADER_WRITE_BARRIER((vader_struct_vader_lexer_Lexer_t*) l0);
        } else {
        }
        l171 = (uint8_t) (int32_t) INT32_C(73);
        l172 = 318u;
        vader_lexer_push_simple(l0, l171, l172, l164);
        { vader_gc_top = gc_frame.prev; return true; }
    }
    l173 = 93u;
    if (l1 == l173) {
        l174 = vader_lexer_position_here(l0);
        l175 = (size_t) (int64_t) INT64_C(1);
        vader_lexer_advance(l0, l175);
        l176 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_paren_depth;
        l177 = INT32_C(0);
        if ((l176 > l177)) {
            l178 = ((vader_struct_vader_lexer_Lexer_t*) l0)->f_paren_depth;
            l179 = INT32_C(1);
            l180 = (l178 - l179);
            ((vader_struct_vader_lexer_Lexer_t*) l0)->f_paren_depth = l180;
            VADER_WRITE_BARRIER((vader_struct_vader_lexer_Lexer_t*) l0);
        } else {
        }
        l181 = (uint8_t) (int32_t) INT32_C(75);
        l182 = 847u;
        vader_lexer_push_simple(l0, l181, l182, l174);
        { vader_gc_top = gc_frame.prev; return true; }
    }
    l183 = 123u;
    if (l1 == l183) {
        l184 = vader_lexer_top_interp(l0);
        if (l184.tag == 697u) {
            l185 = l184.payload.obj;
            t1 = l184.payload.obj;
            l186 = ((vader_struct_vader_lexer_InterpFrame_t*) t1)->f_brace_depth;
            l187 = INT32_C(1);
            l188 = (l186 + l187);
            ((vader_struct_vader_lexer_InterpFrame_t*) l185)->f_brace_depth = l188;
            VADER_WRITE_BARRIER((vader_struct_vader_lexer_InterpFrame_t*) l185);
        } else {
        }
        l189 = (uint8_t) (int32_t) INT32_C(76);
        l190 = 2401u;
        t0 = vader_lexer_emit_and_advance(l0, l189, l190);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l191 = 125u;
    if (l1 == l191) {
        l192 = vader_lexer_top_interp(l0);
        if (l192.tag == 697u) {
            t1 = l192.payload.obj;
            l193 = ((vader_struct_vader_lexer_InterpFrame_t*) t1)->f_brace_depth;
            l194 = INT32_C(0);
            if ((l193 > l194)) {
                l195 = l192.payload.obj;
                t1 = l192.payload.obj;
                l196 = ((vader_struct_vader_lexer_InterpFrame_t*) t1)->f_brace_depth;
                l197 = INT32_C(1);
                l198 = (l196 - l197);
                ((vader_struct_vader_lexer_InterpFrame_t*) l195)->f_brace_depth = l198;
                VADER_WRITE_BARRIER((vader_struct_vader_lexer_InterpFrame_t*) l195);
            } else {
            }
        } else {
        }
        l199 = (uint8_t) (int32_t) INT32_C(77);
        l200 = 2410u;
        t0 = vader_lexer_emit_and_advance(l0, l199, l200);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return false; }
    vader_gc_top = gc_frame.prev;
}

