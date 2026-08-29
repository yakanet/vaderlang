#include "bootstrap.split.h"

void* vader_parser_advance(void* l0) {
    void* l1;
    int32_t l2, l3;
    size_t t0;
    int32_t t1;
    l1 = vader_parser_peek(l0);
    if (!(((vader_struct_vader_parser_Parser_t*) l0)->f_shr_pending_half.tag == 0u)) {
        ((vader_struct_vader_parser_Parser_t*) l0)->f_shr_pending_half = vader_box_obj(0u, NULL);
        VADER_WRITE_BARRIER((vader_struct_vader_parser_Parser_t*) l0);
    } else {
        l2 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pos;
        t0 = ((vader_array_t*) ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens)->length;
        l3 = (((int32_t) (size_t) t0) - INT32_C(1));
        if ((l2 < l3)) {
            t1 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pos;
            l2 = (t1 + INT32_C(1));
            ((vader_struct_vader_parser_Parser_t*) l0)->f_pos = l2;
            VADER_WRITE_BARRIER((vader_struct_vader_parser_Parser_t*) l0);
        } else {
        }
    }
    return l1;
}

void vader_parser_assign_block_ids(void* l0, void* l1) {
    vader_parser_walk_block(l0, l1);
    return;
}

void vader_parser_assign_program_ids(void* l0, void* l1) {
    size_t l2, l6, l7, l8;
    vader_box_t l3;
    void* l4;
    void* l5;
    vader_box_t t0;
    int64_t t1;
    l2 = vader_parser_mint(l1);
    ((vader_struct_toolchain_ast_Program_t*) l0)->f_id = l2;
    VADER_WRITE_BARRIER((vader_struct_toolchain_ast_Program_t*) l0);
    l3 = ((vader_struct_toolchain_ast_Program_t*) l0)->f_module;
    if (l3.tag == 0u) {
        l5 = ((vader_struct_toolchain_ast_Program_t*) l0)->f_decls;
        l6 = ((vader_array_t*) l5)->length;
        l7 = (size_t) (int64_t) INT64_C(0);
        {
            loop_17: {
                if ((l7 < l6)) {
                    vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
                    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                    if ((size_t) l7 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
                    vader_parser_walk_decl(t0, l1);
                    l8 = (size_t) (int64_t) INT64_C(1);
                    t1 = (l7 + l8);
                    l7 = (size_t) (int64_t) t1;
                    goto loop_17;
                } else {
                }
            }
        }
        return;
    }
    if (l3.tag == 451u) {
        t0 = ((vader_struct_toolchain_ast_Program_t*) l0)->f_module;
        l4 = t0.payload.obj;
        l2 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_ModuleDecl_t*) l4)->f_id = l2;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_ModuleDecl_t*) l4);
        l5 = ((vader_struct_toolchain_ast_Program_t*) l0)->f_decls;
        l6 = ((vader_array_t*) l5)->length;
        l7 = (size_t) (int64_t) INT64_C(0);
        {
            loop_58: {
                if ((l7 < l6)) {
                    vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                    if ((size_t) l7 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l7);
                    vader_parser_walk_decl(t0, l1);
                    l8 = (size_t) (int64_t) INT64_C(1);
                    t1 = (l7 + l8);
                    l7 = (size_t) (int64_t) t1;
                    goto loop_58;
                } else {
                }
            }
        }
        return;
    }
    return;
}

bool vader_parser_at_top_level_start(void* l0) {
    void* l1;
    void* l3;
    bool l2;
    uint8_t l4, l5;
    l1 = vader_parser_peek(l0);
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(28)) {
        l2 = true;
    } else {
        l2 = ((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(30);
    }
    if (l2) {
        return true;
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(2)) {
        l3 = vader_parser_peek_at(l0, INT32_C(1));
        if (((vader_struct_vader_lexer_Token_t*) l3)->f_kind == INT32_C(63)) {
            l2 = true;
        } else {
            l2 = ((vader_struct_vader_lexer_Token_t*) l3)->f_kind == INT32_C(14);
        }
        if (l2) {
            return true;
        }
        l4 = ((vader_struct_vader_lexer_Token_t*) l1)->f_kind;
        l5 = (uint8_t) (int32_t) INT32_C(70);
        if (l4 == l5) {
            return true;
        }
        return false;
    }
    l4 = ((vader_struct_vader_lexer_Token_t*) l1)->f_kind;
    l5 = (uint8_t) (int32_t) INT32_C(70);
    if (l4 == l5) {
        return true;
    }
    return false;
}

bool vader_parser_check(void* l0, uint8_t l1) {
    void* t0;
    t0 = vader_parser_peek(l0);
    return ((vader_struct_vader_lexer_Token_t*) t0)->f_kind == l1;
}

bool vader_parser_check_at(void* l0, uint8_t l1, int32_t l2) {
    void* t0;
    t0 = vader_parser_peek_at(l0, l2);
    return ((vader_struct_vader_lexer_Token_t*) t0)->f_kind == l1;
}

bool vader_parser_check_closing_angle(void* l0) {
    uint8_t l1;
    bool l2;
    void* t0;
    if (!(((vader_struct_vader_parser_Parser_t*) l0)->f_shr_pending_half.tag == 0u)) {
        return true;
    }
    t0 = vader_parser_peek(l0);
    l1 = ((vader_struct_vader_lexer_Token_t*) t0)->f_kind;
    if (l1 == INT32_C(51)) {
        l2 = true;
    } else {
        l2 = l1 == INT32_C(46);
    }
    return l2;
}

void vader_parser_collect_type_params(vader_box_t l0, void* l1) {
    bool l2;
    void* l3 = NULL;
    size_t l4, l5;
    vader_string_t l6, l7;
    void* t0 = NULL;
    bool t1;
    int64_t t2;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &t3 };
    void** gc_raw_roots[3] = { &l1, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 433u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_toolchain_ast_IdentExpr_t*) t0)->f_is_type_param_intro;
        if (!(t1)) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        l2 = false;
        l3 = l1;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
        l4 = ((vader_array_t*) l3)->length;
        l5 = (size_t) (int64_t) INT64_C(0);
        {
            loop_25: {
                if ((l5 < l4)) {
                    if ((size_t) l5 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
                    l6 = ((vader_struct_toolchain_ast_TypeParam_t*) t0)->f_name;
                    t0 = l0.payload.obj;
                    l7 = ((vader_struct_toolchain_ast_IdentExpr_t*) t0)->f_name;
                    if (l6 == l7) {
                        l2 = true;
                    } else {
                        t2 = (l5 + INT64_C(1));
                        l5 = (size_t) (int64_t) t2;
                        goto loop_25;
                    }
                } else {
                }
            }
        }
        if (!(l2)) {
            t0 = l0.payload.obj;
            l3 = ((vader_struct_toolchain_ast_IdentExpr_t*) t0)->f_span;
            t0 = l0.payload.obj;
            l6 = ((vader_struct_toolchain_ast_IdentExpr_t*) t0)->f_name;
            vader_struct_toolchain_ast_TypeParam_t* _a1_obj = (vader_struct_toolchain_ast_TypeParam_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_TypeParam_t));
            vader_obj_header_init(_a1_obj, 481u);
            _a1_obj->f_span = l3;
            _a1_obj->f_id = (size_t) (int64_t) INT64_C(0);
            _a1_obj->f_name = l6;
            _a1_obj->f_bound = vader_box_obj(0u, NULL);
            _a1_obj->f_default_v = vader_box_obj(0u, NULL);
            _a1_obj->f_is_comptime_value = false;
            l3 = (void*) _a1_obj;
            vader_array_push((vader_array_t*) l1, vader_ref_box(l3));
        } else {
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 403u) {
        t0 = l0.payload.obj;
        vader_parser_collect_type_params(((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_left, l1);
        t0 = l0.payload.obj;
        vader_parser_collect_type_params(((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_right, l1);
    } else {
        if (l0.tag == 430u) {
            t0 = l0.payload.obj;
            l3 = ((vader_struct_toolchain_ast_FnTypeExpr_t*) t0)->f_params;
            l4 = ((vader_array_t*) l3)->length;
            l5 = (size_t) (int64_t) INT64_C(0);
            {
                loop_111: {
                    if ((l5 < l4)) {
                        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
                        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                        if ((size_t) l5 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                        t3 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
                        vader_parser_collect_type_params(t3, l1);
                        t2 = (l5 + INT64_C(1));
                        l5 = (size_t) (int64_t) t2;
                        goto loop_111;
                    } else {
                    }
                }
            }
            t0 = l0.payload.obj;
            vader_parser_collect_type_params(((vader_struct_toolchain_ast_FnTypeExpr_t*) t0)->f_return_type, l1);
        } else {
            if (l0.tag == 399u) {
                t0 = l0.payload.obj;
                vader_parser_collect_type_params(((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t0)->f_element, l1);
            } else {
                if (l0.tag == 465u) {
                    t0 = l0.payload.obj;
                    l3 = ((vader_struct_toolchain_ast_SeqLitExpr_t*) t0)->f_elements;
                    l4 = ((vader_array_t*) l3)->length;
                    l5 = (size_t) (int64_t) INT64_C(0);
                    {
                        loop_157: {
                            if ((l5 < l4)) {
                                vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
                                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                                if ((size_t) l5 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                                t3 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l5);
                                vader_parser_collect_type_params(t3, l1);
                                t2 = (l5 + INT64_C(1));
                                l5 = (size_t) (int64_t) t2;
                                goto loop_157;
                            } else {
                            }
                        }
                    }
                } else {
                    if (l0.tag == 432u) {
                        t0 = l0.payload.obj;
                        l3 = ((vader_struct_toolchain_ast_GenericInstExpr_t*) t0)->f_type_args;
                        l4 = ((vader_array_t*) l3)->length;
                        l5 = (size_t) (int64_t) INT64_C(0);
                        {
                            loop_189: {
                                if ((l5 < l4)) {
                                    vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
                                    if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                                    if ((size_t) l5 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                                    t3 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l5);
                                    vader_parser_collect_type_params(t3, l1);
                                    t2 = (l5 + INT64_C(1));
                                    l5 = (size_t) (int64_t) t2;
                                    goto loop_189;
                                } else {
                                }
                            }
                        }
                    } else {
                    }
                }
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void* vader_parser_compound_op(uint8_t l0) {
    void* l1 = NULL;
    void** gc_raw_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(58)) {
        vader_struct_vader_parser_CompoundOpResult_t* _a0_obj = (vader_struct_vader_parser_CompoundOpResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_CompoundOpResult_t));
        vader_obj_header_init(_a0_obj, 863u);
        _a0_obj->f_matched = true;
        _a0_obj->f_op = (uint8_t) (int32_t) INT32_C(0);
        l1 = (void*) _a0_obj;
    } else {
        if (l0 == INT32_C(59)) {
            vader_struct_vader_parser_CompoundOpResult_t* _a1_obj = (vader_struct_vader_parser_CompoundOpResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_CompoundOpResult_t));
            vader_obj_header_init(_a1_obj, 863u);
            _a1_obj->f_matched = true;
            _a1_obj->f_op = (uint8_t) (int32_t) INT32_C(1);
            l1 = (void*) _a1_obj;
        } else {
            if (l0 == INT32_C(60)) {
                vader_struct_vader_parser_CompoundOpResult_t* _a2_obj = (vader_struct_vader_parser_CompoundOpResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_CompoundOpResult_t));
                vader_obj_header_init(_a2_obj, 863u);
                _a2_obj->f_matched = true;
                _a2_obj->f_op = (uint8_t) (int32_t) INT32_C(2);
                l1 = (void*) _a2_obj;
            } else {
                if (l0 == INT32_C(61)) {
                    vader_struct_vader_parser_CompoundOpResult_t* _a3_obj = (vader_struct_vader_parser_CompoundOpResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_CompoundOpResult_t));
                    vader_obj_header_init(_a3_obj, 863u);
                    _a3_obj->f_matched = true;
                    _a3_obj->f_op = (uint8_t) (int32_t) INT32_C(3);
                    l1 = (void*) _a3_obj;
                } else {
                    if (l0 == INT32_C(62)) {
                        vader_struct_vader_parser_CompoundOpResult_t* _a4_obj = (vader_struct_vader_parser_CompoundOpResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_CompoundOpResult_t));
                        vader_obj_header_init(_a4_obj, 863u);
                        _a4_obj->f_matched = true;
                        _a4_obj->f_op = (uint8_t) (int32_t) INT32_C(4);
                        l1 = (void*) _a4_obj;
                    } else {
                        vader_struct_vader_parser_CompoundOpResult_t* _a5_obj = (vader_struct_vader_parser_CompoundOpResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_CompoundOpResult_t));
                        vader_obj_header_init(_a5_obj, 863u);
                        _a5_obj->f_matched = false;
                        _a5_obj->f_op = (uint8_t) (int32_t) INT32_C(0);
                        l1 = (void*) _a5_obj;
                    }
                }
            }
        }
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_parser_consume_closing_angle(void* l0) {
    vader_box_t l1 = vader_box_null();
    void* l2 = NULL;
    void* l4 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    size_t l3;
    int32_t l5, l6;
    vader_string_t l7;
    int32_t t0;
    int64_t t1;
    void* t2 = NULL;
    size_t t3;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[6] = { &l0, &l2, &l4, &l8, &l9, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_parser_Parser_t*) l0)->f_shr_pending_half;
    if (!(l1.tag == 0u)) {
        ((vader_struct_vader_parser_Parser_t*) l0)->f_shr_pending_half = vader_box_obj(0u, NULL);
        VADER_WRITE_BARRIER((vader_struct_vader_parser_Parser_t*) l0);
        t0 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pos;
        if ((t0 > INT32_C(0))) {
            l2 = ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens;
            t0 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pos;
            t1 = ((int64_t) (int32_t) (t0 - INT32_C(1)));
            l3 = (size_t) (int64_t) t1;
            l4 = l1.payload.obj;
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            vader_array_ref_store(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3, l4);
            VADER_WRITE_BARRIER(_a0_slotarr->buf);
        } else {
        }
        t2 = l1.payload.obj;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = vader_parser_peek(l0);
    if (((vader_struct_vader_lexer_Token_t*) l2)->f_kind == INT32_C(51)) {
        l5 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pos;
        t3 = ((vader_array_t*) ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens)->length;
        l6 = (((int32_t) (size_t) t3) - INT32_C(1));
        if ((l5 < l6)) {
            t0 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pos;
            l5 = (t0 + INT32_C(1));
            ((vader_struct_vader_parser_Parser_t*) l0)->f_pos = l5;
            VADER_WRITE_BARRIER((vader_struct_vader_parser_Parser_t*) l0);
        } else {
        }
        { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l2)->f_kind == INT32_C(46)) {
        l7 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l2)->f_span)->f_start)->f_file;
        t3 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l2)->f_span)->f_start)->f_offset;
        t1 = (t3 + INT64_C(1));
        l3 = (size_t) (int64_t) t1;
        l5 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l2)->f_span)->f_start)->f_line;
        t0 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l2)->f_span)->f_start)->f_column;
        l6 = (t0 + INT32_C(1));
        vader_struct_toolchain_span_Position_t* _a1_obj = (vader_struct_toolchain_span_Position_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Position_t));
        vader_obj_header_init(_a1_obj, 488u);
        _a1_obj->f_file = l7;
        _a1_obj->f_offset = l3;
        _a1_obj->f_line = l5;
        _a1_obj->f_column = l6;
        l4 = (void*) _a1_obj;
        vader_struct_toolchain_span_Span_t* _a2_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
        vader_obj_header_init(_a2_obj, 489u);
        _a2_obj->f_start = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l2)->f_span)->f_start;
        _a2_obj->f_end = l4;
        l8 = (void*) _a2_obj;
        vader_struct_vader_lexer_Token_t* _a3_obj = (vader_struct_vader_lexer_Token_t*) vader_gc_alloc(sizeof(vader_struct_vader_lexer_Token_t));
        vader_obj_header_init(_a3_obj, 707u);
        _a3_obj->f_kind = (uint8_t) (int32_t) INT32_C(51);
        _a3_obj->f_text = 484u;
        _a3_obj->f_span = l8;
        _a3_obj->f_value = vader_box_obj(0u, NULL);
        l8 = (void*) _a3_obj;
        l9 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l2)->f_span)->f_end;
        vader_struct_toolchain_span_Span_t* _a4_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
        vader_obj_header_init(_a4_obj, 489u);
        _a4_obj->f_start = l4;
        _a4_obj->f_end = l9;
        l4 = (void*) _a4_obj;
        vader_struct_vader_lexer_Token_t* _a5_obj = (vader_struct_vader_lexer_Token_t*) vader_gc_alloc(sizeof(vader_struct_vader_lexer_Token_t));
        vader_obj_header_init(_a5_obj, 707u);
        _a5_obj->f_kind = (uint8_t) (int32_t) INT32_C(51);
        _a5_obj->f_text = 484u;
        _a5_obj->f_span = l4;
        _a5_obj->f_value = vader_box_obj(0u, NULL);
        l4 = (void*) _a5_obj;
        l9 = ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens;
        t0 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pos;
        t1 = ((int64_t) (int32_t) t0);
        l3 = (size_t) (int64_t) t1;
        vader_array_t* _a6_slotarr = ((vader_array_t*) l9);
        if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
        if ((size_t) l3 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
        vader_array_ref_store(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l3, l8);
        VADER_WRITE_BARRIER(_a6_slotarr->buf);
        ((vader_struct_vader_parser_Parser_t*) l0)->f_shr_pending_half = vader_ref_box(l4);
        VADER_WRITE_BARRIER((vader_struct_vader_parser_Parser_t*) l0);
        l5 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pos;
        t3 = ((vader_array_t*) ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens)->length;
        l6 = (((int32_t) (size_t) t3) - INT32_C(1));
        if ((l5 < l6)) {
            t0 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pos;
            l5 = (t0 + INT32_C(1));
            ((vader_struct_vader_parser_Parser_t*) l0)->f_pos = l5;
            VADER_WRITE_BARRIER((vader_struct_vader_parser_Parser_t*) l0);
        } else {
        }
        { void* __vret = l8; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_string_t vader_parser_describe_token(void* l0) {
    vader_string_t l1;
    bool l2;
    vader_string_t t0;
    bool t1;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (((vader_struct_vader_lexer_Token_t*) l0)->f_kind == INT32_C(2)) {
        l1 = ((vader_struct_vader_lexer_Token_t*) l0)->f_text;
        t0 = concat_3(872u, l1, 872u);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l0)->f_kind == INT32_C(3)) {
        l2 = true;
    } else {
        l2 = ((vader_struct_vader_lexer_Token_t*) l0)->f_kind == INT32_C(4);
    }
    if (l2) {
        t0 = ((vader_struct_vader_lexer_Token_t*) l0)->f_text;
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l0)->f_kind == INT32_C(1)) {
        { vader_gc_top = gc_frame.prev; return 1774u; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l0)->f_kind == INT32_C(0)) {
        { vader_gc_top = gc_frame.prev; return 1375u; }
    }
    t0 = ((vader_struct_vader_lexer_Token_t*) l0)->f_text;
    t1 = std_string_is_empty(t0);
    if (!(t1)) {
        l1 = ((vader_struct_vader_lexer_Token_t*) l0)->f_text;
        t0 = concat_3(872u, l1, 872u);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_lexer_kind_name(((vader_struct_vader_lexer_Token_t*) l0)->f_kind);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_parser_desugar_comptime_const(void* l0, void* l1, uint8_t l2, void* l3, vader_box_t l4) {
    void* l5 = NULL;
    void* l7 = NULL;
    void* l9 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    vader_box_t l6 = vader_box_null();
    int32_t l8;
    vader_string_t l10;
    size_t l16, l17;
    bool t0;
    void* t1 = NULL;
    int64_t t2;
    vader_box_t* gc_roots[2] = { &l4, &l6 };
    void** gc_raw_roots[12] = { &l0, &l1, &l3, &l5, &l7, &l9, &l11, &l12, &l13, &l14, &l15, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 12u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l5 = vader_parser_advance(l0);
    vader_parser_advance(l0);
    t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(76));
    if (t0) {
        t1 = vader_parser_parse_block(l0);
        l6 = vader_ref_box(t1);
    } else {
        l6 = vader_parser_parse_expr(l0, INT32_C(0));
    }
    t1 = vader_parser_wrap_as_block(l6);
    l7 = vader_parser_lift_trailing_return(t1);
    l8 = -(INT32_C(1));
    l9 = vader_parser_peek_at(l0, l8);
    l10 = ((vader_struct_vader_lexer_Token_t*) l3)->f_text;
    l10 = concat_2(840u, l10);
    l11 = vader_parser_span_of(l0, l5, l9);
    l12 = ((vader_struct_vader_lexer_Token_t*) l3)->f_span;
    vader_array_t* _a0_arr = vader_array_new(33u, 0u, 13u, 481u);
    l13 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(24u, 0u, 13u, 429u);
    l14 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(21u, 0u, 13u, 414u);
    l15 = (void*) _a2_arr;
    vader_struct_toolchain_ast_FnDecl_t* _a3_obj = (vader_struct_toolchain_ast_FnDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FnDecl_t));
    vader_obj_header_init(_a3_obj, 428u);
    _a3_obj->f_span = l11;
    _a3_obj->f_id = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_name = l10;
    _a3_obj->f_name_span = l12;
    _a3_obj->f_visibility = (uint8_t) (int32_t) INT32_C(1);
    _a3_obj->f_type_params = l13;
    _a3_obj->f_params = l14;
    _a3_obj->f_return_type = l4;
    _a3_obj->f_body = vader_ref_box(l7);
    _a3_obj->f_decorators = l15;
    _a3_obj->f_sam_synthetic = false;
    _a3_obj->f_is_expression_bodied = true;
    _a3_obj->f_materialized = false;
    _a3_obj->f_comptime_synthetic = true;
    _a3_obj->f_trailing_comma = false;
    l7 = (void*) _a3_obj;
    vader_array_push((vader_array_t*) ((vader_struct_vader_parser_Parser_t*) l0)->f_pending_decls, vader_ref_box(l7));
    l5 = vader_parser_span_of(l0, l5, l9);
    l7 = vader_parser_ident_expr(((vader_struct_vader_lexer_Token_t*) l3)->f_span, l10);
    vader_array_t* _a4_arr = vader_array_new(19u, 0u, 13u, 408u);
    l11 = (void*) _a4_arr;
    vader_struct_toolchain_ast_CallExpr_t* _a5_obj = (vader_struct_toolchain_ast_CallExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_CallExpr_t));
    vader_obj_header_init(_a5_obj, 409u);
    _a5_obj->f_span = l5;
    _a5_obj->f_id = (size_t) (int64_t) INT64_C(0);
    _a5_obj->f_callee = vader_ref_box(l7);
    _a5_obj->f_args = l11;
    _a5_obj->f_trailing_comma = false;
    l5 = (void*) _a5_obj;
    vader_array_t* _a6_arr = vader_array_new(21u, 0u, 13u, 414u);
    l7 = (void*) _a6_arr;
    l11 = l1;
    l16 = ((vader_array_t*) l11)->length;
    l17 = (size_t) (int64_t) INT64_C(0);
    {
        loop_97: {
            if ((l17 < l16)) {
                vader_array_t* _a7_slotarr = ((vader_array_t*) l11);
                if (_a7_slotarr->buf != NULL && _a7_slotarr->buf->header.forward != NULL) { _a7_slotarr->buf = vader_array_buf_forward(_a7_slotarr->buf); }
                if ((size_t) l17 >= _a7_slotarr->length) { vader_trap("array index out of bounds"); }
                l12 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l17);
                vader_array_push((vader_array_t*) l7, vader_ref_box(l12));
                t2 = (l17 + INT64_C(1));
                l17 = (size_t) (int64_t) t2;
                goto loop_97;
            } else {
            }
        }
    }
    l11 = ((vader_struct_vader_lexer_Token_t*) l3)->f_span;
    vader_array_t* _a8_arr = vader_array_new(108u, 0u, 13u, 1034u);
    l12 = (void*) _a8_arr;
    vader_struct_toolchain_ast_Decorator_t* _a9_obj = (vader_struct_toolchain_ast_Decorator_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_Decorator_t));
    vader_obj_header_init(_a9_obj, 414u);
    _a9_obj->f_span = l11;
    _a9_obj->f_id = (size_t) (int64_t) INT64_C(0);
    _a9_obj->f_name = 1285u;
    _a9_obj->f_args = l12;
    l11 = (void*) _a9_obj;
    vader_array_push((vader_array_t*) l7, vader_ref_box(l11));
    l9 = vader_parser_span_of(l0, l3, l9);
    l10 = ((vader_struct_vader_lexer_Token_t*) l3)->f_text;
    l11 = ((vader_struct_vader_lexer_Token_t*) l3)->f_span;
    vader_struct_toolchain_ast_ConstDecl_t* _a10_obj = (vader_struct_toolchain_ast_ConstDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ConstDecl_t));
    vader_obj_header_init(_a10_obj, 412u);
    _a10_obj->f_span = l9;
    _a10_obj->f_id = (size_t) (int64_t) INT64_C(0);
    _a10_obj->f_name = l10;
    _a10_obj->f_name_span = l11;
    _a10_obj->f_visibility = l2;
    _a10_obj->f_ty = l4;
    _a10_obj->f_value = vader_ref_box(l5);
    _a10_obj->f_decorators = l7;
    _a10_obj->f_comptime_body = l6;
    t1 = (void*) _a10_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_parser_empty_token(void) {
    void* l0 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l0 = vader_lexer_empty_file_span(0u);
    t0 = vader_lexer_make_token((uint8_t) (int32_t) INT32_C(0), 0u, l0);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void vader_parser_error(void* l0, uint8_t l1, void* l2, vader_string_t l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    bool t0;
    void** gc_raw_roots[4] = { &l0, &l2, &l4, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_parser_Parser_t*) l0)->f_depth_exceeded;
    if (t0) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l4 = ((vader_struct_vader_parser_Parser_t*) l0)->f_errors;
    l5 = vader_diagnostics_parser_error(l1, l2, l3);
    vader_array_push((vader_array_t*) l4, vader_ref_box(l5));
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void* vader_parser_expect(void* l0, uint8_t l1, vader_string_t l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    vader_string_t l5;
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[4] = { &l0, &l3, &l4, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_parser_check(l0, l1);
    if (t0) {
        t1 = vader_parser_advance(l0);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = vader_parser_peek(l0);
    l4 = ((vader_struct_vader_lexer_Token_t*) l3)->f_span;
    l5 = vader_parser_describe_token(l3);
    l5 = concat_5(1394u, l2, 46u, l5, 320u);
    vader_parser_error(l0, (uint8_t) (int32_t) INT32_C(1), l4, l5);
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_parser_expect_string_literal(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l9 = NULL;
    vader_string_t l4, l8;
    bool l5, l10;
    vader_box_t l7 = vader_box_null();
    bool t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l7 };
    void** gc_raw_roots[6] = { &l0, &l2, &l3, &l6, &l9, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(6));
    if (!(t0)) {
        l2 = vader_parser_peek(l0);
        l3 = ((vader_struct_vader_lexer_Token_t*) l2)->f_span;
        l4 = vader_parser_describe_token(l2);
        l4 = concat_5(1394u, l1, 46u, l4, 320u);
        vader_parser_error(l0, (uint8_t) (int32_t) INT32_C(1), l3, l4);
        l2 = ((vader_struct_vader_lexer_Token_t*) l2)->f_span;
        vader_struct_vader_parser_StringLitInfo_t* _a0_obj = (vader_struct_vader_parser_StringLitInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_StringLitInfo_t));
        vader_obj_header_init(_a0_obj, 872u);
        _a0_obj->f_text = 0u;
        _a0_obj->f_span = l2;
        t1 = (void*) _a0_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = vader_parser_advance(l0);
    vader_array_t* _a1_arr = vader_array_new(8u, 0u, 0u, 161u);
    t1 = (void*) _a1_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a2_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a2_obj, 398u);
    _a2_obj->f_parts = t1;
    l3 = (void*) _a2_obj;
    {
        loop_39: {
            t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(8));
            if (!(t0)) {
                t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(0));
                l5 = !(t0);
            } else {
                l5 = false;
            }
            if (l5) {
                l6 = vader_parser_advance(l0);
                if (((vader_struct_vader_lexer_Token_t*) l6)->f_kind == INT32_C(7)) {
                    l7 = ((vader_struct_vader_lexer_Token_t*) l6)->f_value;
                    if (l7.tag == 161u) {
                        l4 = l7.payload.s;
                        std_string_builder_append(l3, l4);
                    } else {
                        l8 = ((vader_struct_vader_lexer_Token_t*) l6)->f_text;
                        std_string_builder_append(l3, l8);
                    }
                } else {
                }
                if (((vader_struct_vader_lexer_Token_t*) l6)->f_kind == INT32_C(9)) {
                    l9 = ((vader_struct_vader_lexer_Token_t*) l6)->f_span;
                    vader_parser_error(l0, (uint8_t) (int32_t) INT32_C(0), l9, 1623u);
                    {
                        loop_95: {
                            t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(10));
                            if (!(t0)) {
                                t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(0));
                                l10 = !(t0);
                            } else {
                                l10 = false;
                            }
                            if (l10) {
                                vader_parser_advance(l0);
                                goto loop_95;
                            } else {
                            }
                        }
                    }
                } else {
                }
                goto loop_39;
            } else {
            }
        }
    }
    l6 = vader_parser_match_or_peek(l0, (uint8_t) (int32_t) INT32_C(8));
    l4 = std_string_builder_StringBuilder_Display_to_string(l3);
    l2 = vader_parser_span_of(l0, l2, l6);
    vader_struct_vader_parser_StringLitInfo_t* _a3_obj = (vader_struct_vader_parser_StringLitInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_StringLitInfo_t));
    vader_obj_header_init(_a3_obj, 872u);
    _a3_obj->f_text = l4;
    _a3_obj->f_span = l2;
    t1 = (void*) _a3_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

size_t vader_parser_header_budget(size_t l0) {
    size_t l1;
    l1 = (size_t) (int64_t) INT64_C(4096);
    if ((l0 < l1)) {
        return l0;
    }
    return l1;
}

void* vader_parser_ident_expr(void* l0, vader_string_t l1) {
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_toolchain_ast_IdentExpr_t* _a0_obj = (vader_struct_toolchain_ast_IdentExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_IdentExpr_t));
    vader_obj_header_init(_a0_obj, 433u);
    _a0_obj->f_span = l0;
    _a0_obj->f_id = (size_t) (int64_t) INT64_C(0);
    _a0_obj->f_name = l1;
    _a0_obj->f_implicit_dot = false;
    _a0_obj->f_is_type_param_intro = false;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_parser_infix_for(uint8_t l0) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(54)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a0_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a0_obj, 866u);
        _a0_obj->f_has = true;
        _a0_obj->f_left_bp = INT32_C(10);
        _a0_obj->f_right_bp = INT32_C(11);
        _a0_obj->f_op = (uint8_t) (int32_t) INT32_C(11);
        _a0_obj->f_non_assoc = false;
        t0 = (void*) _a0_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(53)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a1_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a1_obj, 866u);
        _a1_obj->f_has = true;
        _a1_obj->f_left_bp = INT32_C(12);
        _a1_obj->f_right_bp = INT32_C(13);
        _a1_obj->f_op = (uint8_t) (int32_t) INT32_C(10);
        _a1_obj->f_non_assoc = false;
        t0 = (void*) _a1_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(47)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a2_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a2_obj, 866u);
        _a2_obj->f_has = true;
        _a2_obj->f_left_bp = INT32_C(20);
        _a2_obj->f_right_bp = INT32_C(20);
        _a2_obj->f_op = (uint8_t) (int32_t) INT32_C(12);
        _a2_obj->f_non_assoc = true;
        t0 = (void*) _a2_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(48)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a3_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a3_obj, 866u);
        _a3_obj->f_has = true;
        _a3_obj->f_left_bp = INT32_C(20);
        _a3_obj->f_right_bp = INT32_C(20);
        _a3_obj->f_op = (uint8_t) (int32_t) INT32_C(13);
        _a3_obj->f_non_assoc = true;
        t0 = (void*) _a3_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(49)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a4_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a4_obj, 866u);
        _a4_obj->f_has = true;
        _a4_obj->f_left_bp = INT32_C(20);
        _a4_obj->f_right_bp = INT32_C(20);
        _a4_obj->f_op = (uint8_t) (int32_t) INT32_C(14);
        _a4_obj->f_non_assoc = true;
        t0 = (void*) _a4_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(50)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a5_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a5_obj, 866u);
        _a5_obj->f_has = true;
        _a5_obj->f_left_bp = INT32_C(20);
        _a5_obj->f_right_bp = INT32_C(20);
        _a5_obj->f_op = (uint8_t) (int32_t) INT32_C(15);
        _a5_obj->f_non_assoc = true;
        t0 = (void*) _a5_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(51)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a6_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a6_obj, 866u);
        _a6_obj->f_has = true;
        _a6_obj->f_left_bp = INT32_C(20);
        _a6_obj->f_right_bp = INT32_C(20);
        _a6_obj->f_op = (uint8_t) (int32_t) INT32_C(16);
        _a6_obj->f_non_assoc = true;
        t0 = (void*) _a6_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(52)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a7_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a7_obj, 866u);
        _a7_obj->f_has = true;
        _a7_obj->f_left_bp = INT32_C(20);
        _a7_obj->f_right_bp = INT32_C(20);
        _a7_obj->f_op = (uint8_t) (int32_t) INT32_C(17);
        _a7_obj->f_non_assoc = true;
        t0 = (void*) _a7_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(19)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a8_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a8_obj, 866u);
        _a8_obj->f_has = true;
        _a8_obj->f_left_bp = INT32_C(20);
        _a8_obj->f_right_bp = INT32_C(20);
        _a8_obj->f_op = (uint8_t) (int32_t) INT32_C(18);
        _a8_obj->f_non_assoc = true;
        t0 = (void*) _a8_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(21)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a9_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a9_obj, 866u);
        _a9_obj->f_has = true;
        _a9_obj->f_left_bp = INT32_C(20);
        _a9_obj->f_right_bp = INT32_C(20);
        _a9_obj->f_op = (uint8_t) (int32_t) INT32_C(19);
        _a9_obj->f_non_assoc = true;
        t0 = (void*) _a9_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(65)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a10_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a10_obj, 866u);
        _a10_obj->f_has = true;
        _a10_obj->f_left_bp = INT32_C(30);
        _a10_obj->f_right_bp = INT32_C(30);
        _a10_obj->f_op = (uint8_t) (int32_t) INT32_C(14);
        _a10_obj->f_non_assoc = true;
        t0 = (void*) _a10_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(66)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a11_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a11_obj, 866u);
        _a11_obj->f_has = true;
        _a11_obj->f_left_bp = INT32_C(30);
        _a11_obj->f_right_bp = INT32_C(30);
        _a11_obj->f_op = (uint8_t) (int32_t) INT32_C(15);
        _a11_obj->f_non_assoc = true;
        t0 = (void*) _a11_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(67)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(42)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a12_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a12_obj, 866u);
        _a12_obj->f_has = true;
        _a12_obj->f_left_bp = INT32_C(40);
        _a12_obj->f_right_bp = INT32_C(41);
        _a12_obj->f_op = (uint8_t) (int32_t) INT32_C(8);
        _a12_obj->f_non_assoc = false;
        t0 = (void*) _a12_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(43)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a13_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a13_obj, 866u);
        _a13_obj->f_has = true;
        _a13_obj->f_left_bp = INT32_C(50);
        _a13_obj->f_right_bp = INT32_C(51);
        _a13_obj->f_op = (uint8_t) (int32_t) INT32_C(9);
        _a13_obj->f_non_assoc = false;
        t0 = (void*) _a13_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(41)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a14_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a14_obj, 866u);
        _a14_obj->f_has = true;
        _a14_obj->f_left_bp = INT32_C(60);
        _a14_obj->f_right_bp = INT32_C(61);
        _a14_obj->f_op = (uint8_t) (int32_t) INT32_C(7);
        _a14_obj->f_non_assoc = false;
        t0 = (void*) _a14_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(45)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a15_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a15_obj, 866u);
        _a15_obj->f_has = true;
        _a15_obj->f_left_bp = INT32_C(70);
        _a15_obj->f_right_bp = INT32_C(71);
        _a15_obj->f_op = (uint8_t) (int32_t) INT32_C(5);
        _a15_obj->f_non_assoc = false;
        t0 = (void*) _a15_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(46)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a16_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a16_obj, 866u);
        _a16_obj->f_has = true;
        _a16_obj->f_left_bp = INT32_C(70);
        _a16_obj->f_right_bp = INT32_C(71);
        _a16_obj->f_op = (uint8_t) (int32_t) INT32_C(6);
        _a16_obj->f_non_assoc = false;
        t0 = (void*) _a16_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(36)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a17_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a17_obj, 866u);
        _a17_obj->f_has = true;
        _a17_obj->f_left_bp = INT32_C(80);
        _a17_obj->f_right_bp = INT32_C(81);
        _a17_obj->f_op = (uint8_t) (int32_t) INT32_C(0);
        _a17_obj->f_non_assoc = false;
        t0 = (void*) _a17_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(37)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a18_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a18_obj, 866u);
        _a18_obj->f_has = true;
        _a18_obj->f_left_bp = INT32_C(80);
        _a18_obj->f_right_bp = INT32_C(81);
        _a18_obj->f_op = (uint8_t) (int32_t) INT32_C(1);
        _a18_obj->f_non_assoc = false;
        t0 = (void*) _a18_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(38)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a19_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a19_obj, 866u);
        _a19_obj->f_has = true;
        _a19_obj->f_left_bp = INT32_C(90);
        _a19_obj->f_right_bp = INT32_C(91);
        _a19_obj->f_op = (uint8_t) (int32_t) INT32_C(2);
        _a19_obj->f_non_assoc = false;
        t0 = (void*) _a19_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(39)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a20_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a20_obj, 866u);
        _a20_obj->f_has = true;
        _a20_obj->f_left_bp = INT32_C(90);
        _a20_obj->f_right_bp = INT32_C(91);
        _a20_obj->f_op = (uint8_t) (int32_t) INT32_C(3);
        _a20_obj->f_non_assoc = false;
        t0 = (void*) _a20_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(40)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a21_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a21_obj, 866u);
        _a21_obj->f_has = true;
        _a21_obj->f_left_bp = INT32_C(90);
        _a21_obj->f_right_bp = INT32_C(91);
        _a21_obj->f_op = (uint8_t) (int32_t) INT32_C(4);
        _a21_obj->f_non_assoc = false;
        t0 = (void*) _a21_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(0)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(1)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(2)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(3)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(4)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(5)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(6)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(7)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(8)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(9)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(10)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(44)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(55)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(56)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(57)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(58)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(59)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(60)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(61)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(62)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(63)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(64)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(68)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(69)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(70)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(71)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(72)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(73)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(74)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(75)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(76)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(77)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(78)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(79)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(80)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(11)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(12)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(13)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(14)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(15)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(16)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(17)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(18)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(20)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(22)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(23)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(24)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(25)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(26)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(27)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(28)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(29)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(30)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(31)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(32)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(33)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(34)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(35)) {
        t0 = vader_parser_no_infix();
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_unreachable("unreachable return in vader_parser$infix_for");
    vader_gc_top = gc_frame.prev;
}

vader_box_t vader_parser_intrinsic_spec(vader_string_t l0) {
    void* l1;
    void* l4;
    size_t l2, l3;
    vader_string_t t0;
    int64_t t1;
    vader_box_t t2;
    l1 = (void*) &vader_data_8;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    l2 = ((vader_array_t*) l1)->length;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_7: {
            if ((l3 < l2)) {
                if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
                t0 = ((vader_struct_vader_parser_IntrinsicSpec_t*) l4)->f_name;
                if (t0 == l0) {
                    return vader_ref_box(l4);
                }
                t1 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t1;
                goto loop_7;
            } else {
            }
        }
    }
    t2 = vader_box_obj(0u, NULL);
    return t2;
}

bool vader_parser_is_angle_scan_bailout(uint8_t l0) {
    bool l1;
    if (l0 == INT32_C(76)) {
        return true;
    }
    if (l0 == INT32_C(63)) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(64);
    }
    if (l1) {
        return true;
    }
    if (l0 == INT32_C(57)) {
        return true;
    }
    if (l0 == INT32_C(58)) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(59);
    }
    if (l1) {
        return true;
    }
    if (l0 == INT32_C(60)) {
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
        return true;
    }
    if (l0 == INT32_C(52)) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(50);
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
        return true;
    }
    if (l0 == INT32_C(16)) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(17);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(18);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(19);
    }
    if (l1) {
        return true;
    }
    if (l0 == INT32_C(20)) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(21);
    }
    if (l1) {
        return true;
    }
    if (l0 == INT32_C(22)) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(23);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(24);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(25);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(26);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(27);
    }
    if (l1) {
        return true;
    }
    if (l0 == INT32_C(12)) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(13);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(14);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(15);
    }
    if (l1) {
        return true;
    }
    if (l0 == INT32_C(28)) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(30);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(34);
    }
    if (l1) {
        return true;
    }
    return false;
}

bool vader_parser_is_impl_decl(void* l0) {
    int32_t l1, l2, l3;
    void* l4;
    void* l6;
    size_t l5;
    bool l7, l8, l9, l10, l11, l12;
    size_t t0;
    int64_t t1;
    l1 = INT32_C(0);
    t0 = ((vader_array_t*) ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens)->length;
    l2 = ((int32_t) (size_t) t0);
    l3 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pos;
    {
        loop_10: {
            if ((l3 < l2)) {
                l4 = ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens;
                t1 = ((int64_t) (int32_t) l3);
                l5 = (size_t) (int64_t) t1;
                vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l5 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l6 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
                if (((vader_struct_vader_lexer_Token_t*) l6)->f_kind == INT32_C(0)) {
                    l7 = true;
                } else {
                    l7 = ((vader_struct_vader_lexer_Token_t*) l6)->f_kind == INT32_C(1);
                }
                if (l7) {
                    return false;
                }
                if (((vader_struct_vader_lexer_Token_t*) l6)->f_kind == INT32_C(14)) {
                    l8 = l1 == INT32_C(0);
                } else {
                    l8 = false;
                }
                if (l8) {
                    return true;
                }
                if (((vader_struct_vader_lexer_Token_t*) l6)->f_kind == INT32_C(72)) {
                    l9 = true;
                } else {
                    l9 = ((vader_struct_vader_lexer_Token_t*) l6)->f_kind == INT32_C(74);
                }
                if (l9) {
                    l10 = true;
                } else {
                    l10 = ((vader_struct_vader_lexer_Token_t*) l6)->f_kind == INT32_C(76);
                }
                if (l10) {
                    l1 = (l1 + INT32_C(1));
                } else {
                }
                if (((vader_struct_vader_lexer_Token_t*) l6)->f_kind == INT32_C(73)) {
                    l11 = true;
                } else {
                    l11 = ((vader_struct_vader_lexer_Token_t*) l6)->f_kind == INT32_C(75);
                }
                if (l11) {
                    l12 = true;
                } else {
                    l12 = ((vader_struct_vader_lexer_Token_t*) l6)->f_kind == INT32_C(77);
                }
                if (l12) {
                    l1 = (l1 - INT32_C(1));
                } else {
                }
                if ((l1 < INT32_C(0))) {
                    return false;
                }
                l3 = (l3 + INT32_C(1));
                goto loop_10;
            } else {
            }
        }
    }
    return false;
}

bool vader_parser_is_literal_start(void* l0) {
    bool l1;
    if (((vader_struct_vader_lexer_Token_t*) l0)->f_kind == INT32_C(3)) {
        l1 = true;
    } else {
        l1 = ((vader_struct_vader_lexer_Token_t*) l0)->f_kind == INT32_C(4);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = ((vader_struct_vader_lexer_Token_t*) l0)->f_kind == INT32_C(5);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = ((vader_struct_vader_lexer_Token_t*) l0)->f_kind == INT32_C(6);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = ((vader_struct_vader_lexer_Token_t*) l0)->f_kind == INT32_C(31);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = ((vader_struct_vader_lexer_Token_t*) l0)->f_kind == INT32_C(32);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = ((vader_struct_vader_lexer_Token_t*) l0)->f_kind == INT32_C(33);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = ((vader_struct_vader_lexer_Token_t*) l0)->f_kind == INT32_C(37);
    }
    return l1;
}

bool vader_parser_is_module_segment_continue(uint32_t l0) {
    bool l1;
    if ((97u <= l0)) {
        l1 = (l0 <= 122u);
    } else {
        l1 = false;
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = std_char_is_digit(l0);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == 95u;
    }
    return l1;
}

bool vader_parser_is_module_segment_start(uint32_t l0) {
    bool l1;
    if ((97u <= l0)) {
        l1 = (l0 <= 122u);
    } else {
        l1 = false;
    }
    return l1;
}

bool vader_parser_is_valid_module_name(vader_string_t l0) {
    bool l1, l2;
    void* l3 = NULL;
    vader_box_t l4 = vader_box_null();
    uint32_t l5;
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[2] = { &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = true;
    l2 = false;
    l3 = std_string_chars(l0);
    {
        loop_8: {
            l4 = std_string_StringChars_Iterator_next(l3);
            if (l4.tag == 0u) {
            } else {
                t0 = l4.payload.obj;
                l5 = ((vader_struct_std_core_Yield__char_t*) t0)->f_value;
                l2 = true;
                if (l1) {
                    t1 = vader_parser_is_module_segment_start(l5);
                    if (!(t1)) {
                        { vader_gc_top = gc_frame.prev; return false; }
                    }
                    l1 = false;
                    goto loop_8;
                }
                if (l5 == 47u) {
                    l1 = true;
                    goto loop_8;
                }
                t1 = vader_parser_is_module_segment_continue(l5);
                if (!(t1)) {
                    { vader_gc_top = gc_frame.prev; return false; }
                }
                goto loop_8;
            }
        }
    }
    if (!(l2)) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    { bool __vret = !(l1); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_parser_lift_trailing_return(void* l0) {
    size_t l1, l3;
    void* l2 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    vader_box_t l4 = vader_box_null();
    int64_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[5] = { &l0, &l2, &l5, &l6, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(((vader_struct_toolchain_ast_BlockExpr_t*) l0)->f_trailing.tag == 0u)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = ((vader_array_t*) ((vader_struct_toolchain_ast_BlockExpr_t*) l0)->f_stmts)->length;
    if (l1 == INT64_C(0)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_toolchain_ast_BlockExpr_t*) l0)->f_stmts;
    t0 = (l1 - INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    if (l4.tag == 464u) {
        l2 = l4.payload.obj;
        if (!(((vader_struct_toolchain_ast_ReturnStmt_t*) l2)->f_value.tag == 0u)) {
            vader_array_t* _a1_arr = vader_array_new(110u, 0u, 13u, 1047u);
            l5 = (void*) _a1_arr;
            t0 = (l1 - INT64_C(1));
            l1 = (size_t) (int64_t) t0;
            l3 = (size_t) (int64_t) INT64_C(0);
            {
                loop_44: {
                    if ((l3 < l1)) {
                        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_BlockExpr_t*) l0)->f_stmts);
                        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                        if ((size_t) l3 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                        l4 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l3);
                        vader_array_push((vader_array_t*) l5, l4);
                        t0 = (l3 + INT64_C(1));
                        l3 = (size_t) (int64_t) t0;
                        goto loop_44;
                    } else {
                    }
                }
            }
            l6 = ((vader_struct_toolchain_ast_BlockExpr_t*) l0)->f_span;
            l4 = ((vader_struct_toolchain_ast_ReturnStmt_t*) l2)->f_value;
            vader_struct_toolchain_ast_BlockExpr_t* _a3_obj = (vader_struct_toolchain_ast_BlockExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BlockExpr_t));
            vader_obj_header_init(_a3_obj, 405u);
            _a3_obj->f_span = l6;
            _a3_obj->f_id = (size_t) (int64_t) INT64_C(0);
            _a3_obj->f_stmts = l5;
            _a3_obj->f_trailing = l4;
            t1 = (void*) _a3_obj;
            { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

bool vader_parser_looks_like_for_destructure(void* l0) {
    int32_t l1, l2, l4, l5;
    void* l3;
    bool t0;
    t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(74));
    if (!(t0)) {
        return false;
    }
    l1 = INT32_C(0);
    l2 = INT32_C(0);
    {
        loop_12: {
            if ((l2 > INT32_C(256))) {
            } else {
                l3 = vader_parser_peek_at(l0, l2);
                if (((vader_struct_vader_lexer_Token_t*) l3)->f_kind == INT32_C(0)) {
                    return false;
                }
                if (((vader_struct_vader_lexer_Token_t*) l3)->f_kind == INT32_C(74)) {
                    l1 = (l1 + INT32_C(1));
                    l5 = INT32_C(1);
                    l2 = (l2 + l5);
                    goto loop_12;
                }
                if (((vader_struct_vader_lexer_Token_t*) l3)->f_kind == INT32_C(75)) {
                    l1 = (l1 - INT32_C(1));
                    if (l1 == INT32_C(0)) {
                        l4 = (l2 + INT32_C(1));
                        t0 = vader_parser_check_at(l0, (uint8_t) (int32_t) INT32_C(21), l4);
                        return t0;
                    }
                    l5 = INT32_C(1);
                    l2 = (l2 + l5);
                    goto loop_12;
                }
                l5 = INT32_C(1);
                l2 = (l2 + l5);
                goto loop_12;
            }
        }
    }
    return false;
}

bool vader_parser_looks_like_struct_lit_body(void* l0, int32_t l1) {
    int32_t l2, l3;
    size_t l4;
    void* l5;
    bool l6, l7;
    size_t t0;
    int64_t t1;
    t0 = ((vader_array_t*) l0)->length;
    l2 = ((int32_t) (size_t) t0);
    l3 = (l1 + INT32_C(1));
    {
        loop_9: {
            if ((l3 < l2)) {
                t1 = ((int64_t) (int32_t) l3);
                l4 = (size_t) (int64_t) t1;
                vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
                if (((vader_struct_vader_lexer_Token_t*) l5)->f_kind == INT32_C(1)) {
                    l3 = (l3 + INT32_C(1));
                    goto loop_9;
                }
                if (((vader_struct_vader_lexer_Token_t*) l5)->f_kind == INT32_C(79)) {
                    l6 = true;
                } else {
                    l6 = ((vader_struct_vader_lexer_Token_t*) l5)->f_kind == INT32_C(67);
                }
                if (l6) {
                    l7 = true;
                } else {
                    l7 = ((vader_struct_vader_lexer_Token_t*) l5)->f_kind == INT32_C(77);
                }
                return l7;
            } else {
            }
        }
    }
    return false;
}

vader_box_t vader_parser_match_kind(void* l0, uint8_t l1) {
    bool t0;
    void* t1;
    vader_box_t t2;
    t0 = vader_parser_check(l0, l1);
    if (t0) {
        t1 = vader_parser_advance(l0);
        return vader_ref_box(t1);
    }
    t2 = vader_box_obj(0u, NULL);
    return t2;
}

void* vader_parser_match_or_peek(void* l0, uint8_t l1) {
    vader_box_t l2;
    void* t0;
    l2 = vader_parser_match_kind(l0, l1);
    if (!(l2.tag == 0u)) {
        t0 = l2.payload.obj;
        return t0;
    }
    t0 = vader_parser_peek(l0);
    return t0;
}

void* vader_parser_merge_type_params(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    size_t l4, l5, l9, l10;
    bool l7;
    vader_string_t l11, l12;
    size_t t0;
    int64_t t1;
    void* t2 = NULL;
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l6, &l8, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 7u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) l0)->length;
    if (t0 == INT64_C(0)) {
        { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_array_t*) l1)->length;
    if (t0 == INT64_C(0)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(33u, 0u, 13u, 481u);
    l2 = (void*) _a0_arr;
    l3 = l0;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_25: {
            if ((l5 < l4)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l5 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                l6 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
                vader_array_push((vader_array_t*) l2, vader_ref_box(l6));
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_25;
            } else {
            }
        }
    }
    l3 = l1;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_53: {
            if ((l5 < l4)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l5 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                l6 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
                l7 = false;
                l8 = l2;
                vader_array_t* _a3_slotarr = ((vader_array_t*) l8);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                l9 = ((vader_array_t*) l8)->length;
                l10 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_71: {
                        if ((l10 < l9)) {
                            if ((size_t) l10 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                            t2 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l10);
                            l11 = ((vader_struct_toolchain_ast_TypeParam_t*) t2)->f_name;
                            l12 = ((vader_struct_toolchain_ast_TypeParam_t*) l6)->f_name;
                            if (l11 == l12) {
                                l7 = true;
                            } else {
                                t1 = (l10 + INT64_C(1));
                                l10 = (size_t) (int64_t) t1;
                                goto loop_71;
                            }
                        } else {
                        }
                    }
                }
                if (!(l7)) {
                    vader_array_push((vader_array_t*) l2, vader_ref_box(l6));
                } else {
                }
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_53;
            } else {
            }
        }
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

size_t vader_parser_mint(void* l0) {
    size_t l1, l2;
    int64_t t0;
    l1 = ((vader_struct_vader_parser_NodeIdFactory_t*) l0)->f_next;
    t0 = (l1 + INT64_C(1));
    l2 = (size_t) (int64_t) t0;
    ((vader_struct_vader_parser_NodeIdFactory_t*) l0)->f_next = l2;
    VADER_WRITE_BARRIER((vader_struct_vader_parser_NodeIdFactory_t*) l0);
    return l1;
}

void* vader_parser_new_node_id_factory(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_parser_NodeIdFactory_t* _a0_obj = (vader_struct_vader_parser_NodeIdFactory_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_NodeIdFactory_t));
    vader_obj_header_init(_a0_obj, 869u);
    _a0_obj->f_next = (size_t) (int64_t) INT64_C(1);
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_parser_new_parser(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(50u, 0u, 13u, 704u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(109u, 0u, 13u, 1042u);
    l3 = (void*) _a1_arr;
    vader_struct_vader_parser_Parser_t* _a2_obj = (vader_struct_vader_parser_Parser_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_Parser_t));
    vader_obj_header_init(_a2_obj, 871u);
    _a2_obj->f_tokens = l0;
    _a2_obj->f_file = l1;
    _a2_obj->f_pos = INT32_C(0);
    _a2_obj->f_errors = l2;
    _a2_obj->f_allow_struct_lit = true;
    _a2_obj->f_allow_bare_lambda = true;
    _a2_obj->f_shr_pending_half = vader_box_obj(0u, NULL);
    _a2_obj->f_pending_decls = l3;
    _a2_obj->f_expr_depth = INT32_C(0);
    _a2_obj->f_depth_exceeded = false;
    t0 = (void*) _a2_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_parser_no_infix(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_parser_InfixOpDescr_t* _a0_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
    vader_obj_header_init(_a0_obj, 866u);
    _a0_obj->f_has = false;
    _a0_obj->f_left_bp = INT32_C(0);
    _a0_obj->f_right_bp = INT32_C(0);
    _a0_obj->f_op = (uint8_t) (int32_t) INT32_C(0);
    _a0_obj->f_non_assoc = false;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_parser_parse_angle_type_params(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l5 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l16 = NULL;
    uint8_t l3, l7, l9;
    vader_string_t l4, l14;
    vader_box_t l6 = vader_box_null(), l8 = vader_box_null();
    int32_t l10;
    size_t l13;
    bool l15;
    bool t0;
    void* t1 = NULL;
    size_t t2;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l6, &l8, &t3 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l5, &l11, &l12, &l16, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 8u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(49));
    if (!(t0)) {
        vader_array_t* _a0_arr = vader_array_new(33u, 0u, 13u, 481u);
        t1 = (void*) _a0_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_parser_advance(l0);
    vader_array_t* _a1_arr = vader_array_new(33u, 0u, 13u, 481u);
    l1 = (void*) _a1_arr;
    vader_parser_skip_newlines(l0);
    {
        loop_16: {
            t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(0));
            if (!(t0)) {
                t0 = vader_parser_check_closing_angle(l0);
                if (t0) {
                } else {
                    t2 = ((vader_array_t*) l1)->length;
                    if ((t2 > INT64_C(0))) {
                        t3 = vader_parser_match_kind(l0, (uint8_t) (int32_t) INT32_C(78));
                        if (t3.tag == 0u) {
                        } else {
                            vader_parser_skip_newlines(l0);
                            t0 = vader_parser_check_closing_angle(l0);
                            if (t0) {
                            } else {
                                l2 = vader_parser_peek(l0);
                                l3 = (uint8_t) (int32_t) INT32_C(2);
                                l4 = 2090u;
                                l5 = vader_parser_expect(l0, l3, l4);
                                l6 = vader_box_obj(0u, NULL);
                                l7 = (uint8_t) (int32_t) INT32_C(80);
                                t3 = vader_parser_match_kind(l0, l7);
                                if (!(t3.tag == 0u)) {
                                    vader_parser_skip_newlines(l0);
                                    l6 = vader_parser_parse_type(l0);
                                } else {
                                }
                                l8 = vader_box_obj(0u, NULL);
                                l9 = (uint8_t) (int32_t) INT32_C(57);
                                t3 = vader_parser_match_kind(l0, l9);
                                if (!(t3.tag == 0u)) {
                                    vader_parser_skip_newlines(l0);
                                    l8 = vader_parser_parse_type(l0);
                                } else {
                                }
                                l10 = -(INT32_C(1));
                                l11 = vader_parser_peek_at(l0, l10);
                                l12 = vader_parser_span_of(l0, l2, l11);
                                l13 = (size_t) (int64_t) INT64_C(0);
                                l14 = ((vader_struct_vader_lexer_Token_t*) l5)->f_text;
                                l15 = false;
                                vader_struct_toolchain_ast_TypeParam_t* _a2_obj = (vader_struct_toolchain_ast_TypeParam_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_TypeParam_t));
                                vader_obj_header_init(_a2_obj, 481u);
                                _a2_obj->f_span = l12;
                                _a2_obj->f_id = l13;
                                _a2_obj->f_name = l14;
                                _a2_obj->f_bound = l6;
                                _a2_obj->f_default_v = l8;
                                _a2_obj->f_is_comptime_value = l15;
                                l16 = (void*) _a2_obj;
                                vader_array_push((vader_array_t*) l1, vader_ref_box(l16));
                                goto loop_16;
                            }
                        }
                    } else {
                        l2 = vader_parser_peek(l0);
                        l3 = (uint8_t) (int32_t) INT32_C(2);
                        l4 = 2090u;
                        l5 = vader_parser_expect(l0, l3, l4);
                        l6 = vader_box_obj(0u, NULL);
                        l7 = (uint8_t) (int32_t) INT32_C(80);
                        t3 = vader_parser_match_kind(l0, l7);
                        if (!(t3.tag == 0u)) {
                            vader_parser_skip_newlines(l0);
                            l6 = vader_parser_parse_type(l0);
                        } else {
                        }
                        l8 = vader_box_obj(0u, NULL);
                        l9 = (uint8_t) (int32_t) INT32_C(57);
                        t3 = vader_parser_match_kind(l0, l9);
                        if (!(t3.tag == 0u)) {
                            vader_parser_skip_newlines(l0);
                            l8 = vader_parser_parse_type(l0);
                        } else {
                        }
                        l10 = -(INT32_C(1));
                        l11 = vader_parser_peek_at(l0, l10);
                        l12 = vader_parser_span_of(l0, l2, l11);
                        l13 = (size_t) (int64_t) INT64_C(0);
                        l14 = ((vader_struct_vader_lexer_Token_t*) l5)->f_text;
                        l15 = false;
                        vader_struct_toolchain_ast_TypeParam_t* _a3_obj = (vader_struct_toolchain_ast_TypeParam_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_TypeParam_t));
                        vader_obj_header_init(_a3_obj, 481u);
                        _a3_obj->f_span = l12;
                        _a3_obj->f_id = l13;
                        _a3_obj->f_name = l14;
                        _a3_obj->f_bound = l6;
                        _a3_obj->f_default_v = l8;
                        _a3_obj->f_is_comptime_value = l15;
                        l16 = (void*) _a3_obj;
                        vader_array_push((vader_array_t*) l1, vader_ref_box(l16));
                        goto loop_16;
                    }
                }
            } else {
            }
        }
    }
    t0 = vader_parser_check_closing_angle(l0);
    if (t0) {
        vader_parser_consume_closing_angle(l0);
    } else {
        vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(51), 1001u);
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_parser_parse_block(void* l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    int32_t l2, l25, l26;
    bool l3;
    vader_box_t l6 = vader_box_null(), l7 = vader_box_null(), l18 = vader_box_null(), l21 = vader_box_null();
    size_t l16, l17, l19, l20, l22, l27;
    uint8_t l23;
    vader_string_t l24;
    int32_t t0;
    bool t1;
    void* t2 = NULL;
    int64_t t3;
    vader_box_t* gc_roots[4] = { &l6, &l7, &l18, &l21 };
    void** gc_raw_roots[13] = { &l0, &l1, &l4, &l5, &l8, &l9, &l10, &l11, &l12, &l13, &l14, &l15, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 13u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(76), 1049u);
    t0 = ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth;
    l2 = (t0 + INT32_C(1));
    ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth = l2;
    VADER_WRITE_BARRIER((vader_struct_vader_parser_Parser_t*) l0);
    t0 = ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth;
    if ((t0 > INT32_C(256))) {
        t0 = ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth;
        l2 = (t0 - INT32_C(1));
        ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth = l2;
        VADER_WRITE_BARRIER((vader_struct_vader_parser_Parser_t*) l0);
        vader_parser_report_nesting_too_deep(l0, 1177u);
        l2 = INT32_C(1);
        {
            loop_32: {
                if ((l2 > INT32_C(0))) {
                    t1 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(0));
                    l3 = !(t1);
                } else {
                    l3 = false;
                }
                if (l3) {
                    l4 = vader_parser_advance(l0);
                    if (((vader_struct_vader_lexer_Token_t*) l4)->f_kind == INT32_C(76)) {
                        l2 = (l2 + INT32_C(1));
                    } else {
                    }
                    if (((vader_struct_vader_lexer_Token_t*) l4)->f_kind == INT32_C(77)) {
                        l2 = (l2 - INT32_C(1));
                    } else {
                    }
                    goto loop_32;
                } else {
                }
            }
        }
        l2 = -(INT32_C(1));
        l4 = vader_parser_peek_at(l0, l2);
        l4 = vader_parser_span_of(l0, l1, l4);
        vader_array_t* _a0_arr = vader_array_new(110u, 0u, 13u, 1047u);
        l5 = (void*) _a0_arr;
        vader_struct_toolchain_ast_BlockExpr_t* _a1_obj = (vader_struct_toolchain_ast_BlockExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BlockExpr_t));
        vader_obj_header_init(_a1_obj, 405u);
        _a1_obj->f_span = l4;
        _a1_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a1_obj->f_stmts = l5;
        _a1_obj->f_trailing = vader_box_obj(0u, NULL);
        t2 = (void*) _a1_obj;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_parser_skip_newlines(l0);
    vader_array_t* _a2_arr = vader_array_new(110u, 0u, 13u, 1047u);
    l4 = (void*) _a2_arr;
    l6 = vader_box_obj(0u, NULL);
    {
        loop_104: {
            t1 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(77));
            if (!(t1)) {
                t1 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(0));
                l3 = !(t1);
            } else {
                l3 = false;
            }
            if (l3) {
                l7 = vader_parser_parse_stmt(l0);
                if (l7.tag == 0u) {
                    vader_parser_skip_newlines(l0);
                    goto loop_104;
                }
                if (l7.tag == 447u) {
                    l5 = l7.payload.obj;
                    vader_array_push((vader_array_t*) l4, vader_ref_box(l5));
                    vader_parser_skip_newlines(l0);
                    goto loop_104;
                }
                if (l7.tag == 401u) {
                    l8 = l7.payload.obj;
                    vader_array_push((vader_array_t*) l4, vader_ref_box(l8));
                    vader_parser_skip_newlines(l0);
                    goto loop_104;
                }
                if (l7.tag == 425u) {
                    l9 = l7.payload.obj;
                    vader_array_push((vader_array_t*) l4, vader_ref_box(l9));
                    vader_parser_skip_newlines(l0);
                    goto loop_104;
                }
                if (l7.tag == 464u) {
                    l10 = l7.payload.obj;
                    vader_array_push((vader_array_t*) l4, vader_ref_box(l10));
                    vader_parser_skip_newlines(l0);
                    goto loop_104;
                }
                if (l7.tag == 487u) {
                    l11 = l7.payload.obj;
                    vader_array_push((vader_array_t*) l4, vader_ref_box(l11));
                    vader_parser_skip_newlines(l0);
                    goto loop_104;
                }
                if (l7.tag == 431u) {
                    l12 = l7.payload.obj;
                    vader_array_push((vader_array_t*) l4, vader_ref_box(l12));
                    vader_parser_skip_newlines(l0);
                    goto loop_104;
                }
                if (l7.tag == 407u) {
                    l13 = l7.payload.obj;
                    vader_array_push((vader_array_t*) l4, vader_ref_box(l13));
                    vader_parser_skip_newlines(l0);
                    goto loop_104;
                }
                if (l7.tag == 413u) {
                    l14 = l7.payload.obj;
                    vader_array_push((vader_array_t*) l4, vader_ref_box(l14));
                    vader_parser_skip_newlines(l0);
                    goto loop_104;
                }
                if (l7.tag == 416u) {
                    l15 = l7.payload.obj;
                    vader_array_push((vader_array_t*) l4, vader_ref_box(l15));
                    vader_parser_skip_newlines(l0);
                    goto loop_104;
                }
                vader_unreachable("unreachable return in vader_parser$parse_block");
            } else {
            }
        }
    }
    vader_array_t* _a3_arr = vader_array_new(110u, 0u, 13u, 1047u);
    l5 = (void*) _a3_arr;
    l16 = ((vader_array_t*) l4)->length;
    l3 = false;
    l7 = vader_box_obj(0u, NULL);
    if ((l16 > INT64_C(0))) {
        t3 = (l16 - INT64_C(1));
        l17 = (size_t) (int64_t) t3;
        vader_array_t* _a4_slotarr = ((vader_array_t*) l4);
        if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
        if ((size_t) l17 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
        l18 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l17);
        if (l18.tag == 425u) {
            l3 = true;
            t2 = l18.payload.obj;
            l7 = ((vader_struct_toolchain_ast_ExprStmt_t*) t2)->f_expr;
            if (l3) {
                l19 = (size_t) (int64_t) INT64_C(1);
                t3 = (l16 - l19);
                l17 = (size_t) (int64_t) t3;
            } else {
                l17 = l16;
            }
            l20 = (size_t) (int64_t) INT64_C(0);
            {
                loop_296: {
                    if ((l20 < l17)) {
                        vader_array_t* _a5_slotarr = ((vader_array_t*) l4);
                        if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                        if ((size_t) l20 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                        l21 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l20);
                        vader_array_push((vader_array_t*) l5, l21);
                        l22 = (size_t) (int64_t) INT64_C(1);
                        t3 = (l20 + l22);
                        l20 = (size_t) (int64_t) t3;
                        goto loop_296;
                    } else {
                    }
                }
            }
            if (l3) {
                if (!(l7.tag == 0u)) {
                    l6 = l7;
                } else {
                }
            } else {
            }
            l23 = (uint8_t) (int32_t) INT32_C(77);
            l24 = 1055u;
            l8 = vader_parser_expect(l0, l23, l24);
            l2 = ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth;
            l25 = INT32_C(1);
            l26 = (l2 - l25);
            ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth = l26;
            VADER_WRITE_BARRIER((vader_struct_vader_parser_Parser_t*) l0);
            l9 = vader_parser_span_of(l0, l1, l8);
            l27 = (size_t) (int64_t) INT64_C(0);
            vader_struct_toolchain_ast_BlockExpr_t* _a6_obj = (vader_struct_toolchain_ast_BlockExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BlockExpr_t));
            vader_obj_header_init(_a6_obj, 405u);
            _a6_obj->f_span = l9;
            _a6_obj->f_id = l27;
            _a6_obj->f_stmts = l5;
            _a6_obj->f_trailing = l6;
            t2 = (void*) _a6_obj;
            { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l18.tag == 447u) {
            if (l3) {
                l19 = (size_t) (int64_t) INT64_C(1);
                t3 = (l16 - l19);
                l17 = (size_t) (int64_t) t3;
            } else {
                l17 = l16;
            }
            l20 = (size_t) (int64_t) INT64_C(0);
            {
                loop_384: {
                    if ((l20 < l17)) {
                        vader_array_t* _a7_slotarr = ((vader_array_t*) l4);
                        if (_a7_slotarr->buf != NULL && _a7_slotarr->buf->header.forward != NULL) { _a7_slotarr->buf = vader_array_buf_forward(_a7_slotarr->buf); }
                        if ((size_t) l20 >= _a7_slotarr->length) { vader_trap("array index out of bounds"); }
                        l21 = vader_array_ref_load_box(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l20);
                        vader_array_push((vader_array_t*) l5, l21);
                        l22 = (size_t) (int64_t) INT64_C(1);
                        t3 = (l20 + l22);
                        l20 = (size_t) (int64_t) t3;
                        goto loop_384;
                    } else {
                    }
                }
            }
            if (l3) {
                if (!(l7.tag == 0u)) {
                    l6 = l7;
                } else {
                }
            } else {
            }
            l23 = (uint8_t) (int32_t) INT32_C(77);
            l24 = 1055u;
            l8 = vader_parser_expect(l0, l23, l24);
            l2 = ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth;
            l25 = INT32_C(1);
            l26 = (l2 - l25);
            ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth = l26;
            VADER_WRITE_BARRIER((vader_struct_vader_parser_Parser_t*) l0);
            l9 = vader_parser_span_of(l0, l1, l8);
            l27 = (size_t) (int64_t) INT64_C(0);
            vader_struct_toolchain_ast_BlockExpr_t* _a8_obj = (vader_struct_toolchain_ast_BlockExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BlockExpr_t));
            vader_obj_header_init(_a8_obj, 405u);
            _a8_obj->f_span = l9;
            _a8_obj->f_id = l27;
            _a8_obj->f_stmts = l5;
            _a8_obj->f_trailing = l6;
            t2 = (void*) _a8_obj;
            { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l18.tag == 401u) {
            if (l3) {
                l19 = (size_t) (int64_t) INT64_C(1);
                t3 = (l16 - l19);
                l17 = (size_t) (int64_t) t3;
            } else {
                l17 = l16;
            }
            l20 = (size_t) (int64_t) INT64_C(0);
            {
                loop_472: {
                    if ((l20 < l17)) {
                        vader_array_t* _a9_slotarr = ((vader_array_t*) l4);
                        if (_a9_slotarr->buf != NULL && _a9_slotarr->buf->header.forward != NULL) { _a9_slotarr->buf = vader_array_buf_forward(_a9_slotarr->buf); }
                        if ((size_t) l20 >= _a9_slotarr->length) { vader_trap("array index out of bounds"); }
                        l21 = vader_array_ref_load_box(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l20);
                        vader_array_push((vader_array_t*) l5, l21);
                        l22 = (size_t) (int64_t) INT64_C(1);
                        t3 = (l20 + l22);
                        l20 = (size_t) (int64_t) t3;
                        goto loop_472;
                    } else {
                    }
                }
            }
            if (l3) {
                if (!(l7.tag == 0u)) {
                    l6 = l7;
                } else {
                }
            } else {
            }
            l23 = (uint8_t) (int32_t) INT32_C(77);
            l24 = 1055u;
            l8 = vader_parser_expect(l0, l23, l24);
            l2 = ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth;
            l25 = INT32_C(1);
            l26 = (l2 - l25);
            ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth = l26;
            VADER_WRITE_BARRIER((vader_struct_vader_parser_Parser_t*) l0);
            l9 = vader_parser_span_of(l0, l1, l8);
            l27 = (size_t) (int64_t) INT64_C(0);
            vader_struct_toolchain_ast_BlockExpr_t* _a10_obj = (vader_struct_toolchain_ast_BlockExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BlockExpr_t));
            vader_obj_header_init(_a10_obj, 405u);
            _a10_obj->f_span = l9;
            _a10_obj->f_id = l27;
            _a10_obj->f_stmts = l5;
            _a10_obj->f_trailing = l6;
            t2 = (void*) _a10_obj;
            { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l18.tag == 464u) {
            if (l3) {
                l19 = (size_t) (int64_t) INT64_C(1);
                t3 = (l16 - l19);
                l17 = (size_t) (int64_t) t3;
            } else {
                l17 = l16;
            }
            l20 = (size_t) (int64_t) INT64_C(0);
            {
                loop_560: {
                    if ((l20 < l17)) {
                        vader_array_t* _a11_slotarr = ((vader_array_t*) l4);
                        if (_a11_slotarr->buf != NULL && _a11_slotarr->buf->header.forward != NULL) { _a11_slotarr->buf = vader_array_buf_forward(_a11_slotarr->buf); }
                        if ((size_t) l20 >= _a11_slotarr->length) { vader_trap("array index out of bounds"); }
                        l21 = vader_array_ref_load_box(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l20);
                        vader_array_push((vader_array_t*) l5, l21);
                        l22 = (size_t) (int64_t) INT64_C(1);
                        t3 = (l20 + l22);
                        l20 = (size_t) (int64_t) t3;
                        goto loop_560;
                    } else {
                    }
                }
            }
            if (l3) {
                if (!(l7.tag == 0u)) {
                    l6 = l7;
                } else {
                }
            } else {
            }
            l23 = (uint8_t) (int32_t) INT32_C(77);
            l24 = 1055u;
            l8 = vader_parser_expect(l0, l23, l24);
            l2 = ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth;
            l25 = INT32_C(1);
            l26 = (l2 - l25);
            ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth = l26;
            VADER_WRITE_BARRIER((vader_struct_vader_parser_Parser_t*) l0);
            l9 = vader_parser_span_of(l0, l1, l8);
            l27 = (size_t) (int64_t) INT64_C(0);
            vader_struct_toolchain_ast_BlockExpr_t* _a12_obj = (vader_struct_toolchain_ast_BlockExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BlockExpr_t));
            vader_obj_header_init(_a12_obj, 405u);
            _a12_obj->f_span = l9;
            _a12_obj->f_id = l27;
            _a12_obj->f_stmts = l5;
            _a12_obj->f_trailing = l6;
            t2 = (void*) _a12_obj;
            { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l18.tag == 487u) {
            if (l3) {
                l19 = (size_t) (int64_t) INT64_C(1);
                t3 = (l16 - l19);
                l17 = (size_t) (int64_t) t3;
            } else {
                l17 = l16;
            }
            l20 = (size_t) (int64_t) INT64_C(0);
            {
                loop_648: {
                    if ((l20 < l17)) {
                        vader_array_t* _a13_slotarr = ((vader_array_t*) l4);
                        if (_a13_slotarr->buf != NULL && _a13_slotarr->buf->header.forward != NULL) { _a13_slotarr->buf = vader_array_buf_forward(_a13_slotarr->buf); }
                        if ((size_t) l20 >= _a13_slotarr->length) { vader_trap("array index out of bounds"); }
                        l21 = vader_array_ref_load_box(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l20);
                        vader_array_push((vader_array_t*) l5, l21);
                        l22 = (size_t) (int64_t) INT64_C(1);
                        t3 = (l20 + l22);
                        l20 = (size_t) (int64_t) t3;
                        goto loop_648;
                    } else {
                    }
                }
            }
            if (l3) {
                if (!(l7.tag == 0u)) {
                    l6 = l7;
                } else {
                }
            } else {
            }
            l23 = (uint8_t) (int32_t) INT32_C(77);
            l24 = 1055u;
            l8 = vader_parser_expect(l0, l23, l24);
            l2 = ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth;
            l25 = INT32_C(1);
            l26 = (l2 - l25);
            ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth = l26;
            VADER_WRITE_BARRIER((vader_struct_vader_parser_Parser_t*) l0);
            l9 = vader_parser_span_of(l0, l1, l8);
            l27 = (size_t) (int64_t) INT64_C(0);
            vader_struct_toolchain_ast_BlockExpr_t* _a14_obj = (vader_struct_toolchain_ast_BlockExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BlockExpr_t));
            vader_obj_header_init(_a14_obj, 405u);
            _a14_obj->f_span = l9;
            _a14_obj->f_id = l27;
            _a14_obj->f_stmts = l5;
            _a14_obj->f_trailing = l6;
            t2 = (void*) _a14_obj;
            { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l18.tag == 431u) {
            if (l3) {
                l19 = (size_t) (int64_t) INT64_C(1);
                t3 = (l16 - l19);
                l17 = (size_t) (int64_t) t3;
            } else {
                l17 = l16;
            }
            l20 = (size_t) (int64_t) INT64_C(0);
            {
                loop_736: {
                    if ((l20 < l17)) {
                        vader_array_t* _a15_slotarr = ((vader_array_t*) l4);
                        if (_a15_slotarr->buf != NULL && _a15_slotarr->buf->header.forward != NULL) { _a15_slotarr->buf = vader_array_buf_forward(_a15_slotarr->buf); }
                        if ((size_t) l20 >= _a15_slotarr->length) { vader_trap("array index out of bounds"); }
                        l21 = vader_array_ref_load_box(_a15_slotarr->buf, _a15_slotarr->offset + (size_t) l20);
                        vader_array_push((vader_array_t*) l5, l21);
                        l22 = (size_t) (int64_t) INT64_C(1);
                        t3 = (l20 + l22);
                        l20 = (size_t) (int64_t) t3;
                        goto loop_736;
                    } else {
                    }
                }
            }
            if (l3) {
                if (!(l7.tag == 0u)) {
                    l6 = l7;
                } else {
                }
            } else {
            }
            l23 = (uint8_t) (int32_t) INT32_C(77);
            l24 = 1055u;
            l8 = vader_parser_expect(l0, l23, l24);
            l2 = ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth;
            l25 = INT32_C(1);
            l26 = (l2 - l25);
            ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth = l26;
            VADER_WRITE_BARRIER((vader_struct_vader_parser_Parser_t*) l0);
            l9 = vader_parser_span_of(l0, l1, l8);
            l27 = (size_t) (int64_t) INT64_C(0);
            vader_struct_toolchain_ast_BlockExpr_t* _a16_obj = (vader_struct_toolchain_ast_BlockExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BlockExpr_t));
            vader_obj_header_init(_a16_obj, 405u);
            _a16_obj->f_span = l9;
            _a16_obj->f_id = l27;
            _a16_obj->f_stmts = l5;
            _a16_obj->f_trailing = l6;
            t2 = (void*) _a16_obj;
            { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l18.tag == 407u) {
            if (l3) {
                l19 = (size_t) (int64_t) INT64_C(1);
                t3 = (l16 - l19);
                l17 = (size_t) (int64_t) t3;
            } else {
                l17 = l16;
            }
            l20 = (size_t) (int64_t) INT64_C(0);
            {
                loop_824: {
                    if ((l20 < l17)) {
                        vader_array_t* _a17_slotarr = ((vader_array_t*) l4);
                        if (_a17_slotarr->buf != NULL && _a17_slotarr->buf->header.forward != NULL) { _a17_slotarr->buf = vader_array_buf_forward(_a17_slotarr->buf); }
                        if ((size_t) l20 >= _a17_slotarr->length) { vader_trap("array index out of bounds"); }
                        l21 = vader_array_ref_load_box(_a17_slotarr->buf, _a17_slotarr->offset + (size_t) l20);
                        vader_array_push((vader_array_t*) l5, l21);
                        l22 = (size_t) (int64_t) INT64_C(1);
                        t3 = (l20 + l22);
                        l20 = (size_t) (int64_t) t3;
                        goto loop_824;
                    } else {
                    }
                }
            }
            if (l3) {
                if (!(l7.tag == 0u)) {
                    l6 = l7;
                } else {
                }
            } else {
            }
            l23 = (uint8_t) (int32_t) INT32_C(77);
            l24 = 1055u;
            l8 = vader_parser_expect(l0, l23, l24);
            l2 = ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth;
            l25 = INT32_C(1);
            l26 = (l2 - l25);
            ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth = l26;
            VADER_WRITE_BARRIER((vader_struct_vader_parser_Parser_t*) l0);
            l9 = vader_parser_span_of(l0, l1, l8);
            l27 = (size_t) (int64_t) INT64_C(0);
            vader_struct_toolchain_ast_BlockExpr_t* _a18_obj = (vader_struct_toolchain_ast_BlockExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BlockExpr_t));
            vader_obj_header_init(_a18_obj, 405u);
            _a18_obj->f_span = l9;
            _a18_obj->f_id = l27;
            _a18_obj->f_stmts = l5;
            _a18_obj->f_trailing = l6;
            t2 = (void*) _a18_obj;
            { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l18.tag == 413u) {
            if (l3) {
                l19 = (size_t) (int64_t) INT64_C(1);
                t3 = (l16 - l19);
                l17 = (size_t) (int64_t) t3;
            } else {
                l17 = l16;
            }
            l20 = (size_t) (int64_t) INT64_C(0);
            {
                loop_912: {
                    if ((l20 < l17)) {
                        vader_array_t* _a19_slotarr = ((vader_array_t*) l4);
                        if (_a19_slotarr->buf != NULL && _a19_slotarr->buf->header.forward != NULL) { _a19_slotarr->buf = vader_array_buf_forward(_a19_slotarr->buf); }
                        if ((size_t) l20 >= _a19_slotarr->length) { vader_trap("array index out of bounds"); }
                        l21 = vader_array_ref_load_box(_a19_slotarr->buf, _a19_slotarr->offset + (size_t) l20);
                        vader_array_push((vader_array_t*) l5, l21);
                        l22 = (size_t) (int64_t) INT64_C(1);
                        t3 = (l20 + l22);
                        l20 = (size_t) (int64_t) t3;
                        goto loop_912;
                    } else {
                    }
                }
            }
            if (l3) {
                if (!(l7.tag == 0u)) {
                    l6 = l7;
                } else {
                }
            } else {
            }
            l23 = (uint8_t) (int32_t) INT32_C(77);
            l24 = 1055u;
            l8 = vader_parser_expect(l0, l23, l24);
            l2 = ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth;
            l25 = INT32_C(1);
            l26 = (l2 - l25);
            ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth = l26;
            VADER_WRITE_BARRIER((vader_struct_vader_parser_Parser_t*) l0);
            l9 = vader_parser_span_of(l0, l1, l8);
            l27 = (size_t) (int64_t) INT64_C(0);
            vader_struct_toolchain_ast_BlockExpr_t* _a20_obj = (vader_struct_toolchain_ast_BlockExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BlockExpr_t));
            vader_obj_header_init(_a20_obj, 405u);
            _a20_obj->f_span = l9;
            _a20_obj->f_id = l27;
            _a20_obj->f_stmts = l5;
            _a20_obj->f_trailing = l6;
            t2 = (void*) _a20_obj;
            { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l18.tag == 416u) {
            if (l3) {
                l19 = (size_t) (int64_t) INT64_C(1);
                t3 = (l16 - l19);
                l17 = (size_t) (int64_t) t3;
            } else {
                l17 = l16;
            }
            l20 = (size_t) (int64_t) INT64_C(0);
            {
                loop_1000: {
                    if ((l20 < l17)) {
                        vader_array_t* _a21_slotarr = ((vader_array_t*) l4);
                        if (_a21_slotarr->buf != NULL && _a21_slotarr->buf->header.forward != NULL) { _a21_slotarr->buf = vader_array_buf_forward(_a21_slotarr->buf); }
                        if ((size_t) l20 >= _a21_slotarr->length) { vader_trap("array index out of bounds"); }
                        l21 = vader_array_ref_load_box(_a21_slotarr->buf, _a21_slotarr->offset + (size_t) l20);
                        vader_array_push((vader_array_t*) l5, l21);
                        l22 = (size_t) (int64_t) INT64_C(1);
                        t3 = (l20 + l22);
                        l20 = (size_t) (int64_t) t3;
                        goto loop_1000;
                    } else {
                    }
                }
            }
            if (l3) {
                if (!(l7.tag == 0u)) {
                    l6 = l7;
                } else {
                }
            } else {
            }
            l23 = (uint8_t) (int32_t) INT32_C(77);
            l24 = 1055u;
            l8 = vader_parser_expect(l0, l23, l24);
            l2 = ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth;
            l25 = INT32_C(1);
            l26 = (l2 - l25);
            ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth = l26;
            VADER_WRITE_BARRIER((vader_struct_vader_parser_Parser_t*) l0);
            l9 = vader_parser_span_of(l0, l1, l8);
            l27 = (size_t) (int64_t) INT64_C(0);
            vader_struct_toolchain_ast_BlockExpr_t* _a22_obj = (vader_struct_toolchain_ast_BlockExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BlockExpr_t));
            vader_obj_header_init(_a22_obj, 405u);
            _a22_obj->f_span = l9;
            _a22_obj->f_id = l27;
            _a22_obj->f_stmts = l5;
            _a22_obj->f_trailing = l6;
            t2 = (void*) _a22_obj;
            { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_unreachable("unreachable return in vader_parser$parse_block");
    }
    if (l3) {
        l19 = (size_t) (int64_t) INT64_C(1);
        t3 = (l16 - l19);
        l17 = (size_t) (int64_t) t3;
    } else {
        l17 = l16;
    }
    l20 = (size_t) (int64_t) INT64_C(0);
    {
        loop_1087: {
            if ((l20 < l17)) {
                vader_array_t* _a23_slotarr = ((vader_array_t*) l4);
                if (_a23_slotarr->buf != NULL && _a23_slotarr->buf->header.forward != NULL) { _a23_slotarr->buf = vader_array_buf_forward(_a23_slotarr->buf); }
                if ((size_t) l20 >= _a23_slotarr->length) { vader_trap("array index out of bounds"); }
                l21 = vader_array_ref_load_box(_a23_slotarr->buf, _a23_slotarr->offset + (size_t) l20);
                vader_array_push((vader_array_t*) l5, l21);
                l22 = (size_t) (int64_t) INT64_C(1);
                t3 = (l20 + l22);
                l20 = (size_t) (int64_t) t3;
                goto loop_1087;
            } else {
            }
        }
    }
    if (l3) {
        if (!(l7.tag == 0u)) {
            l6 = l7;
        } else {
        }
    } else {
    }
    l23 = (uint8_t) (int32_t) INT32_C(77);
    l24 = 1055u;
    l8 = vader_parser_expect(l0, l23, l24);
    l2 = ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth;
    l25 = INT32_C(1);
    l26 = (l2 - l25);
    ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth = l26;
    VADER_WRITE_BARRIER((vader_struct_vader_parser_Parser_t*) l0);
    l9 = vader_parser_span_of(l0, l1, l8);
    l27 = (size_t) (int64_t) INT64_C(0);
    vader_struct_toolchain_ast_BlockExpr_t* _a24_obj = (vader_struct_toolchain_ast_BlockExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BlockExpr_t));
    vader_obj_header_init(_a24_obj, 405u);
    _a24_obj->f_span = l9;
    _a24_obj->f_id = l27;
    _a24_obj->f_stmts = l5;
    _a24_obj->f_trailing = l6;
    t2 = (void*) _a24_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_parser_parse_break(void* l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    vader_box_t l2 = vader_box_null();
    int32_t l3;
    bool t0;
    void* t1 = NULL;
    vader_string_t t2;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[4] = { &l0, &l1, &l4, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_advance(l0);
    l2 = vader_box_obj(0u, NULL);
    t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(2));
    if (t0) {
        t1 = vader_parser_advance(l0);
        t2 = ((vader_struct_vader_lexer_Token_t*) t1)->f_text;
        l2 = vader_box_string(161u, t2);
    } else {
    }
    l3 = -(INT32_C(1));
    l4 = vader_parser_peek_at(l0, l3);
    t1 = vader_parser_span_of(l0, l1, l4);
    vader_struct_toolchain_ast_BreakStmt_t* _a0_obj = (vader_struct_toolchain_ast_BreakStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BreakStmt_t));
    vader_obj_header_init(_a0_obj, 407u);
    _a0_obj->f_span = t1;
    _a0_obj->f_id = (size_t) (int64_t) INT64_C(0);
    _a0_obj->f_label = l2;
    t1 = (void*) _a0_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_parser_parse_call_args(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    void* l5 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l11 = NULL;
    void* l13 = NULL;
    bool l2, l4;
    vader_box_t l6 = vader_box_null(), l12 = vader_box_null();
    int32_t l7;
    vader_string_t l10;
    bool t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l6, &l12, &t2 };
    void** gc_raw_roots[9] = { &l0, &l1, &l3, &l5, &l8, &l9, &l11, &l13, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 9u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(19u, 0u, 13u, 408u);
    l1 = (void*) _a0_arr;
    l2 = false;
    vader_parser_skip_newlines(l0);
    t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(73));
    if (t0) {
        vader_struct_vader_parser_CommaList__Any_t* _a1_obj = (vader_struct_vader_parser_CommaList__Any_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_CommaList__Any_t));
        vader_obj_header_init(_a1_obj, 858u);
        _a1_obj->f_items = l1;
        _a1_obj->f_trailing_comma = false;
        t1 = (void*) _a1_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    {
        loop_16: {
            vader_parser_skip_newlines(l0);
            t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(73));
            if (t0) {
            } else {
                l3 = vader_parser_peek(l0);
                t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(2));
                if (t0) {
                    l4 = vader_parser_check_at(l0, (uint8_t) (int32_t) INT32_C(57), INT32_C(1));
                } else {
                    l4 = false;
                }
                if (l4) {
                    l5 = vader_parser_advance(l0);
                    vader_parser_advance(l0);
                    l6 = vader_parser_parse_expr(l0, INT32_C(0));
                    l7 = -(INT32_C(1));
                    l8 = vader_parser_peek_at(l0, l7);
                    l9 = vader_parser_span_of(l0, l3, l8);
                    l10 = ((vader_struct_vader_lexer_Token_t*) l5)->f_text;
                    vader_struct_toolchain_ast_CallArg_t* _a2_obj = (vader_struct_toolchain_ast_CallArg_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_CallArg_t));
                    vader_obj_header_init(_a2_obj, 408u);
                    _a2_obj->f_span = l9;
                    _a2_obj->f_id = (size_t) (int64_t) INT64_C(0);
                    _a2_obj->f_name = vader_box_string(161u, l10);
                    _a2_obj->f_value = l6;
                    _a2_obj->f_spread = false;
                    l11 = (void*) _a2_obj;
                    vader_array_push((vader_array_t*) l1, vader_ref_box(l11));
                } else {
                    l12 = vader_parser_parse_expr(l0, INT32_C(0));
                    t1 = l12.payload.obj;
                    vader_struct_toolchain_ast_CallArg_t* _a3_obj = (vader_struct_toolchain_ast_CallArg_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_CallArg_t));
                    vader_obj_header_init(_a3_obj, 408u);
                    _a3_obj->f_span = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_span;
                    _a3_obj->f_id = (size_t) (int64_t) INT64_C(0);
                    _a3_obj->f_name = vader_box_obj(0u, NULL);
                    _a3_obj->f_value = l12;
                    _a3_obj->f_spread = false;
                    l13 = (void*) _a3_obj;
                    vader_array_push((vader_array_t*) l1, vader_ref_box(l13));
                }
                vader_parser_skip_newlines(l0);
                t2 = vader_parser_match_kind(l0, (uint8_t) (int32_t) INT32_C(78));
                if (t2.tag == 0u) {
                } else {
                    vader_parser_skip_newlines(l0);
                    l2 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(73));
                    goto loop_16;
                }
            }
            vader_struct_vader_parser_CommaList__Any_t* _a4_obj = (vader_struct_vader_parser_CommaList__Any_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_CommaList__Any_t));
            vader_obj_header_init(_a4_obj, 858u);
            _a4_obj->f_items = l1;
            _a4_obj->f_trailing_comma = l2;
            t1 = (void*) _a4_obj;
            { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    vader_struct_vader_parser_CommaList__Any_t* _a5_obj = (vader_struct_vader_parser_CommaList__Any_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_CommaList__Any_t));
    vader_obj_header_init(_a5_obj, 858u);
    _a5_obj->f_items = l1;
    _a5_obj->f_trailing_comma = l2;
    t1 = (void*) _a5_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t vader_parser_parse_coalesce_fallback(void* l0) {
    uint8_t l1;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_parser_peek(l0);
    l1 = ((vader_struct_vader_lexer_Token_t*) t0)->f_kind;
    if (l1 == INT32_C(22)) {
        t0 = vader_parser_parse_return(l0);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(26)) {
        t0 = vader_parser_parse_break(l0);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(27)) {
        t0 = vader_parser_parse_continue(l0);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_parser_parse_expr(l0, INT32_C(7));
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_parser_parse_const_decl(void* l0, void* l1, uint8_t l2, void* l3) {
    bool l4;
    vader_box_t l5 = vader_box_null();
    int32_t l6;
    void* l7 = NULL;
    void* l9 = NULL;
    vader_string_t l8;
    bool t0;
    void* t1 = NULL;
    vader_string_t t2;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[6] = { &l0, &l1, &l3, &l7, &l9, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_parser_reject_target_decorator(l0, l1, 1069u);
    vader_parser_match_kind(l0, (uint8_t) (int32_t) INT32_C(42));
    t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(70));
    if (t0) {
        t1 = vader_parser_peek_at(l0, INT32_C(1));
        l4 = ((vader_struct_vader_lexer_Token_t*) t1)->f_kind == INT32_C(2);
    } else {
        l4 = false;
    }
    if (l4) {
        t1 = vader_parser_peek_at(l0, INT32_C(1));
        t2 = ((vader_struct_vader_lexer_Token_t*) t1)->f_text;
        l4 = t2 == 1285u;
    } else {
        l4 = false;
    }
    if (l4) {
        t1 = vader_parser_desugar_comptime_const(l0, l1, l2, l3, vader_box_obj(0u, NULL));
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = vader_parser_parse_expr(l0, INT32_C(0));
    l6 = -(INT32_C(1));
    l7 = vader_parser_peek_at(l0, l6);
    l7 = vader_parser_span_of(l0, l3, l7);
    l8 = ((vader_struct_vader_lexer_Token_t*) l3)->f_text;
    l9 = ((vader_struct_vader_lexer_Token_t*) l3)->f_span;
    vader_struct_toolchain_ast_ConstDecl_t* _a0_obj = (vader_struct_toolchain_ast_ConstDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ConstDecl_t));
    vader_obj_header_init(_a0_obj, 412u);
    _a0_obj->f_span = l7;
    _a0_obj->f_id = (size_t) (int64_t) INT64_C(0);
    _a0_obj->f_name = l8;
    _a0_obj->f_name_span = l9;
    _a0_obj->f_visibility = l2;
    _a0_obj->f_ty = vader_box_obj(0u, NULL);
    _a0_obj->f_value = l5;
    _a0_obj->f_decorators = l1;
    _a0_obj->f_comptime_body = vader_box_obj(0u, NULL);
    t1 = (void*) _a0_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_parser_parse_continue(void* l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    vader_box_t l2 = vader_box_null();
    int32_t l3;
    bool t0;
    void* t1 = NULL;
    vader_string_t t2;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[4] = { &l0, &l1, &l4, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_advance(l0);
    l2 = vader_box_obj(0u, NULL);
    t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(2));
    if (t0) {
        t1 = vader_parser_advance(l0);
        t2 = ((vader_struct_vader_lexer_Token_t*) t1)->f_text;
        l2 = vader_box_string(161u, t2);
    } else {
    }
    l3 = -(INT32_C(1));
    l4 = vader_parser_peek_at(l0, l3);
    t1 = vader_parser_span_of(l0, l1, l4);
    vader_struct_toolchain_ast_ContinueStmt_t* _a0_obj = (vader_struct_toolchain_ast_ContinueStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ContinueStmt_t));
    vader_obj_header_init(_a0_obj, 413u);
    _a0_obj->f_span = t1;
    _a0_obj->f_id = (size_t) (int64_t) INT64_C(0);
    _a0_obj->f_label = l2;
    t1 = (void*) _a0_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t vader_parser_parse_decl(void* l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l9 = NULL;
    void* l11 = NULL;
    void* l13 = NULL;
    uint8_t l2;
    bool l3;
    vader_box_t l6 = vader_box_null(), l7 = vader_box_null(), l8 = vader_box_null();
    size_t l10;
    int32_t l12;
    vader_string_t l14;
    vader_box_t t0 = vader_box_null();
    size_t t1;
    void* t2 = NULL;
    vader_string_t t3;
    bool t4;
    vader_box_t* gc_roots[4] = { &l6, &l7, &l8, &t0 };
    void** gc_raw_roots[8] = { &l0, &l1, &l4, &l5, &l9, &l11, &l13, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 8u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_parse_decorators(l0);
    l2 = (uint8_t) (int32_t) INT32_C(1);
    t0 = vader_parser_match_kind(l0, (uint8_t) (int32_t) INT32_C(30));
    if (!(t0.tag == 0u)) {
        l2 = (uint8_t) (int32_t) INT32_C(0);
    } else {
    }
    t1 = ((vader_array_t*) l1)->length;
    if (t1 == INT64_C(1)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
        if ((size_t) INT32_C(0) >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
        t2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
        t3 = ((vader_struct_toolchain_ast_Decorator_t*) t2)->f_name;
        l3 = t3 == 1153u;
    } else {
        l3 = false;
    }
    if (l3) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
        if ((size_t) INT32_C(0) >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
        l4 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT32_C(0));
        t1 = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_args)->length;
        if ((t1 < INT64_C(1))) {
            l3 = true;
        } else {
            t1 = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_args)->length;
            l3 = (t1 > INT64_C(2));
        }
        if (l3) {
            l5 = ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_span;
            vader_parser_error(l0, (uint8_t) (int32_t) INT32_C(13), l5, 1006u);
            t0 = vader_box_obj(0u, NULL);
            { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l6 = vader_box_obj(0u, NULL);
        t1 = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_args)->length;
        if (t1 == INT64_C(2)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_args);
            if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
            if ((size_t) INT32_C(1) >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
            l7 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT32_C(1));
            if (l7.tag == 467u) {
                l5 = l7.payload.obj;
                t1 = ((vader_array_t*) ((vader_struct_toolchain_ast_StringLitExpr_t*) l5)->f_parts)->length;
                if (t1 == INT64_C(1)) {
                    vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_StringLitExpr_t*) l5)->f_parts);
                    if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                    if ((size_t) INT32_C(0) >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                    l8 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) INT32_C(0));
                    if (l8.tag == 469u) {
                        t2 = l8.payload.obj;
                        t3 = ((vader_struct_toolchain_ast_StringLitText_t*) t2)->f_value;
                        l6 = vader_box_string(161u, t3);
                        l9 = ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_span;
                        l10 = (size_t) (int64_t) INT64_C(0);
                        l11 = ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_args;
                        l12 = INT32_C(0);
                        vader_array_t* _a4_slotarr = ((vader_array_t*) l11);
                        if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                        if ((size_t) l12 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                        l8 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l12);
                        vader_array_t* _a5_arr = vader_array_new(21u, 0u, 13u, 414u);
                        l13 = (void*) _a5_arr;
                        vader_struct_toolchain_ast_AssertDecl_t* _a6_obj = (vader_struct_toolchain_ast_AssertDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_AssertDecl_t));
                        vader_obj_header_init(_a6_obj, 400u);
                        _a6_obj->f_span = l9;
                        _a6_obj->f_id = l10;
                        _a6_obj->f_condition = l8;
                        _a6_obj->f_message = l6;
                        _a6_obj->f_decorators = l13;
                        t2 = (void*) _a6_obj;
                        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
                    }
                    t2 = l7.payload.obj;
                    l5 = ((vader_struct_toolchain_ast_StringLitExpr_t*) t2)->f_span;
                    vader_parser_error(l0, (uint8_t) (int32_t) INT32_C(13), l5, 1007u);
                    t0 = vader_box_obj(0u, NULL);
                    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
                }
                t2 = l7.payload.obj;
                l5 = ((vader_struct_toolchain_ast_StringLitExpr_t*) t2)->f_span;
                vader_parser_error(l0, (uint8_t) (int32_t) INT32_C(13), l5, 1007u);
                t0 = vader_box_obj(0u, NULL);
                { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
            }
            t2 = l7.payload.obj;
            l5 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t2)->f_span;
            vader_parser_error(l0, (uint8_t) (int32_t) INT32_C(13), l5, 1007u);
            t0 = vader_box_obj(0u, NULL);
            { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l9 = ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_span;
        l10 = (size_t) (int64_t) INT64_C(0);
        l11 = ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_args;
        l12 = INT32_C(0);
        vader_array_t* _a7_slotarr = ((vader_array_t*) l11);
        if (_a7_slotarr->buf != NULL && _a7_slotarr->buf->header.forward != NULL) { _a7_slotarr->buf = vader_array_buf_forward(_a7_slotarr->buf); }
        if ((size_t) l12 >= _a7_slotarr->length) { vader_trap("array index out of bounds"); }
        l8 = vader_array_ref_load_box(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l12);
        vader_array_t* _a8_arr = vader_array_new(21u, 0u, 13u, 414u);
        l13 = (void*) _a8_arr;
        vader_struct_toolchain_ast_AssertDecl_t* _a9_obj = (vader_struct_toolchain_ast_AssertDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_AssertDecl_t));
        vader_obj_header_init(_a9_obj, 400u);
        _a9_obj->f_span = l9;
        _a9_obj->f_id = l10;
        _a9_obj->f_condition = l8;
        _a9_obj->f_message = l6;
        _a9_obj->f_decorators = l13;
        t2 = (void*) _a9_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t4 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(28));
    if (t4) {
        t2 = vader_parser_parse_import_decl(l0, l1);
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t4 = vader_parser_is_impl_decl(l0);
    if (t4) {
        t2 = vader_parser_parse_impl_decl(l0, l1);
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t4 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(2));
    if (t4) {
        l3 = vader_parser_check_at(l0, (uint8_t) (int32_t) INT32_C(49), INT32_C(1));
    } else {
        l3 = false;
    }
    if (l3) {
        l3 = vader_parser_peek_is_lhs_generic_alias_head(l0);
    } else {
        l3 = false;
    }
    if (l3) {
        t2 = vader_parser_parse_lhs_generic_alias_decl(l0, l1, l2);
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t4 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(2));
    if (t4) {
        l3 = vader_parser_check_at(l0, (uint8_t) (int32_t) INT32_C(63), INT32_C(1));
    } else {
        l3 = false;
    }
    if (l3) {
        t0 = vader_parser_parse_named_decl(l0, l1, l2);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t4 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(2));
    if (t4) {
        l3 = vader_parser_check_at(l0, (uint8_t) (int32_t) INT32_C(80), INT32_C(1));
    } else {
        l3 = false;
    }
    if (l3) {
        t2 = vader_parser_parse_typed_const_decl(l0, l1, l2);
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = vader_parser_peek(l0);
    l4 = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
    l14 = vader_parser_describe_token(l1);
    l14 = concat_2(1516u, l14);
    vader_parser_error(l0, (uint8_t) (int32_t) INT32_C(5), l4, l14);
    vader_parser_sync_to_top_level(l0);
    t0 = vader_box_obj(0u, NULL);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_parser_parse_decorators(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l12 = NULL;
    bool l5;
    int32_t l6, l8;
    vader_box_t l7 = vader_box_null();
    vader_string_t l11;
    bool t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l7, &t1 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l4, &l9, &l10, &l12 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 13u, 414u);
    l1 = (void*) _a0_arr;
    {
        loop_3: {
            t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(70));
            if (t0) {
                l2 = vader_parser_advance(l0);
                l3 = vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(2), 1337u);
                vader_array_t* _a1_arr = vader_array_new(108u, 0u, 13u, 1034u);
                l4 = (void*) _a1_arr;
                t1 = vader_parser_match_kind(l0, (uint8_t) (int32_t) INT32_C(72));
                if (!(t1.tag == 0u)) {
                    t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(73));
                    if (!(t0)) {
                        l5 = true;
                        {
                            loop_32: {
                                if (!(l5)) {
                                } else {
                                    l5 = false;
                                    l6 = INT32_C(0);
                                    l7 = vader_parser_parse_expr(l0, l6);
                                    vader_array_push((vader_array_t*) l4, l7);
                                    goto loop_32;
                                }
                                t1 = vader_parser_match_kind(l0, (uint8_t) (int32_t) INT32_C(78));
                                if (t1.tag == 0u) {
                                } else {
                                    t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(73));
                                    if (t0) {
                                    } else {
                                        l5 = false;
                                        l6 = INT32_C(0);
                                        l7 = vader_parser_parse_expr(l0, l6);
                                        vader_array_push((vader_array_t*) l4, l7);
                                        goto loop_32;
                                    }
                                }
                                goto end_28;
                            }
                        }
                    } else {
                    } end_28: ;
                    vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(73), 976u);
                } else {
                }
                l8 = -(INT32_C(1));
                l9 = vader_parser_peek_at(l0, l8);
                l10 = vader_parser_span_of(l0, l2, l9);
                l11 = ((vader_struct_vader_lexer_Token_t*) l3)->f_text;
                vader_struct_toolchain_ast_Decorator_t* _a2_obj = (vader_struct_toolchain_ast_Decorator_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_Decorator_t));
                vader_obj_header_init(_a2_obj, 414u);
                _a2_obj->f_span = l10;
                _a2_obj->f_id = (size_t) (int64_t) INT64_C(0);
                _a2_obj->f_name = l11;
                _a2_obj->f_args = l4;
                l12 = (void*) _a2_obj;
                vader_array_push((vader_array_t*) l1, vader_ref_box(l12));
                vader_parser_skip_newlines(l0);
                goto loop_3;
            } else {
            }
        }
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_parser_parse_defer(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    size_t l8;
    void* t0 = NULL;
    void* t2 = NULL;
    bool t1;
    vader_box_t* gc_roots[2] = { &l4, &l5 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l6, &l7, &t0, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_advance(l0);
    l2 = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
    vader_struct_toolchain_ast_NullLitExpr_t* _a0_obj = (vader_struct_toolchain_ast_NullLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_NullLitExpr_t));
    vader_obj_header_init(_a0_obj, 456u);
    _a0_obj->f_span = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
    _a0_obj->f_id = (size_t) (int64_t) INT64_C(0);
    l3 = (void*) _a0_obj;
    vader_struct_toolchain_ast_ExprStmt_t* _a1_obj = (vader_struct_toolchain_ast_ExprStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ExprStmt_t));
    vader_obj_header_init(_a1_obj, 425u);
    _a1_obj->f_span = l2;
    _a1_obj->f_id = (size_t) (int64_t) INT64_C(0);
    _a1_obj->f_expr = vader_ref_box(l3);
    t0 = (void*) _a1_obj;
    vader_struct_toolchain_ast_DeferStmtBody_t* _a2_obj = (vader_struct_toolchain_ast_DeferStmtBody_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_DeferStmtBody_t));
    vader_obj_header_init(_a2_obj, 417u);
    _a2_obj->f_stmt = vader_ref_box(t0);
    t0 = (void*) _a2_obj;
    l4 = vader_ref_box(t0);
    t1 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(76));
    if (t1) {
        t0 = vader_parser_parse_block(l0);
        vader_struct_toolchain_ast_DeferBlockBody_t* _a3_obj = (vader_struct_toolchain_ast_DeferBlockBody_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_DeferBlockBody_t));
        vader_obj_header_init(_a3_obj, 415u);
        _a3_obj->f_block = t0;
        t0 = (void*) _a3_obj;
        l4 = vader_ref_box(t0);
    } else {
        l5 = vader_parser_parse_stmt(l0);
        if (!(l5.tag == 0u)) {
            vader_struct_toolchain_ast_DeferStmtBody_t* _a4_obj = (vader_struct_toolchain_ast_DeferStmtBody_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_DeferStmtBody_t));
            vader_obj_header_init(_a4_obj, 417u);
            _a4_obj->f_stmt = l5;
            t0 = (void*) _a4_obj;
            l4 = vader_ref_box(t0);
        } else {
        }
    }
    if (l4.tag == 417u) {
        t0 = l4.payload.obj;
        t2 = ((vader_struct_toolchain_ast_DeferStmtBody_t*) t0)->f_stmt.payload.obj;
        l2 = ((vader_struct_toolchain_ast_AssignStmt_t*) t2)->f_span;
        l3 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l1)->f_span)->f_start;
        l6 = ((vader_struct_toolchain_span_Span_t*) l2)->f_end;
        vader_struct_toolchain_span_Span_t* _a5_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
        vader_obj_header_init(_a5_obj, 489u);
        _a5_obj->f_start = l3;
        _a5_obj->f_end = l6;
        l7 = (void*) _a5_obj;
        l8 = (size_t) (int64_t) INT64_C(0);
        vader_struct_toolchain_ast_DeferStmt_t* _a6_obj = (vader_struct_toolchain_ast_DeferStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_DeferStmt_t));
        vader_obj_header_init(_a6_obj, 416u);
        _a6_obj->f_span = l7;
        _a6_obj->f_id = l8;
        _a6_obj->f_body = l4;
        t0 = (void*) _a6_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4.tag == 415u) {
        t0 = l4.payload.obj;
        l2 = ((vader_struct_toolchain_ast_BlockExpr_t*) ((vader_struct_toolchain_ast_DeferBlockBody_t*) t0)->f_block)->f_span;
        l3 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l1)->f_span)->f_start;
        l6 = ((vader_struct_toolchain_span_Span_t*) l2)->f_end;
        vader_struct_toolchain_span_Span_t* _a7_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
        vader_obj_header_init(_a7_obj, 489u);
        _a7_obj->f_start = l3;
        _a7_obj->f_end = l6;
        l7 = (void*) _a7_obj;
        l8 = (size_t) (int64_t) INT64_C(0);
        vader_struct_toolchain_ast_DeferStmt_t* _a8_obj = (vader_struct_toolchain_ast_DeferStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_DeferStmt_t));
        vader_obj_header_init(_a8_obj, 416u);
        _a8_obj->f_span = l7;
        _a8_obj->f_id = l8;
        _a8_obj->f_body = l4;
        t0 = (void*) _a8_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_unreachable("unreachable return in vader_parser$parse_defer");
    vader_gc_top = gc_frame.prev;
}

void* vader_parser_parse_enum_decl(void* l0, void* l1, uint8_t l2, void* l3) {
    vader_box_t l4 = vader_box_null(), l8 = vader_box_null(), l9 = vader_box_null(), l11 = vader_box_null();
    void* l5 = NULL;
    void* l7 = NULL;
    void* l10 = NULL;
    void* l12 = NULL;
    void* l14 = NULL;
    bool l6;
    vader_string_t l13;
    vader_box_t t0 = vader_box_null();
    bool t1;
    uint64_t t2;
    int64_t t3;
    void* t4 = NULL;
    vader_box_t* gc_roots[5] = { &l4, &l8, &l9, &l11, &t0 };
    void** gc_raw_roots[9] = { &l0, &l1, &l3, &l5, &l7, &l10, &l12, &l14, &t4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 5u, 9u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_parser_reject_target_decorator(l0, l1, 1097u);
    vader_parser_advance(l0);
    l4 = vader_box_obj(0u, NULL);
    t0 = vader_parser_match_kind(l0, (uint8_t) (int32_t) INT32_C(72));
    if (!(t0.tag == 0u)) {
        l4 = vader_parser_parse_type(l0);
        vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(73), 977u);
    } else {
    }
    vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(76), 1050u);
    vader_parser_skip_newlines(l0);
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 13u, 423u);
    l5 = (void*) _a0_arr;
    {
        loop_35: {
            t1 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(77));
            if (!(t1)) {
                t1 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(0));
                l6 = !(t1);
            } else {
                l6 = false;
            }
            if (l6) {
                l7 = vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(2), 2286u);
                l8 = vader_box_obj(0u, NULL);
                l9 = vader_box_obj(0u, NULL);
                t0 = vader_parser_match_kind(l0, (uint8_t) (int32_t) INT32_C(57));
                if (!(t0.tag == 0u)) {
                    l10 = vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(3), 1616u);
                    l11 = ((vader_struct_vader_lexer_Token_t*) l10)->f_value;
                    if (l11.tag == 168u) {
                        t2 = ((uint64_t) l11.payload.i);
                        t3 = ((int64_t) (uint64_t) t2);
                        l8 = vader_box_i64(164u, t3);
                    } else {
                        l8 = vader_box_i32(163u, INT32_C(0));
                    }
                    t4 = ((vader_struct_vader_lexer_Token_t*) l10)->f_span;
                    l9 = vader_ref_box(t4);
                } else {
                }
                l12 = ((vader_struct_vader_lexer_Token_t*) l7)->f_span;
                l13 = ((vader_struct_vader_lexer_Token_t*) l7)->f_text;
                vader_struct_toolchain_ast_EnumVariant_t* _a1_obj = (vader_struct_toolchain_ast_EnumVariant_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_EnumVariant_t));
                vader_obj_header_init(_a1_obj, 423u);
                _a1_obj->f_span = l12;
                _a1_obj->f_id = (size_t) (int64_t) INT64_C(0);
                _a1_obj->f_name = l13;
                _a1_obj->f_value = l8;
                _a1_obj->f_value_span = l9;
                l14 = (void*) _a1_obj;
                vader_array_push((vader_array_t*) l5, vader_ref_box(l14));
                vader_parser_match_kind(l0, (uint8_t) (int32_t) INT32_C(78));
                vader_parser_skip_newlines(l0);
                goto loop_35;
            } else {
            }
        }
    }
    l7 = vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(77), 1056u);
    l7 = vader_parser_span_of(l0, l3, l7);
    l13 = ((vader_struct_vader_lexer_Token_t*) l3)->f_text;
    l10 = ((vader_struct_vader_lexer_Token_t*) l3)->f_span;
    vader_struct_toolchain_ast_EnumDecl_t* _a2_obj = (vader_struct_toolchain_ast_EnumDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_EnumDecl_t));
    vader_obj_header_init(_a2_obj, 422u);
    _a2_obj->f_span = l7;
    _a2_obj->f_id = (size_t) (int64_t) INT64_C(0);
    _a2_obj->f_name = l13;
    _a2_obj->f_name_span = l10;
    _a2_obj->f_visibility = l2;
    _a2_obj->f_repr = l4;
    _a2_obj->f_variants = l5;
    _a2_obj->f_decorators = l1;
    t4 = (void*) _a2_obj;
    { void* __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t vader_parser_parse_expr(void* l0, int32_t l1) {
    int32_t l2, l6, l32, l37, l41, l54, l55, l56, l57;
    void* l3 = NULL;
    void* l13 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l19 = NULL;
    void* l20 = NULL;
    void* l22 = NULL;
    void* l23 = NULL;
    void* l24 = NULL;
    void* l25 = NULL;
    void* l26 = NULL;
    void* l27 = NULL;
    void* l28 = NULL;
    void* l31 = NULL;
    void* l33 = NULL;
    void* l34 = NULL;
    void* l38 = NULL;
    void* l44 = NULL;
    void* l45 = NULL;
    void* l46 = NULL;
    void* l49 = NULL;
    void* l51 = NULL;
    void* l52 = NULL;
    vader_box_t l4 = vader_box_null(), l14 = vader_box_null(), l21 = vader_box_null(), l30 = vader_box_null(), l42 = vader_box_null();
    bool l5, l7, l8, l9, l10, l11, l12, l17, l18, l29, l35, l36, l43, l47, l50;
    vader_string_t l39, l40, l48;
    uint8_t l53;
    int32_t t0;
    void* t1 = NULL;
    bool t2;
    vader_box_t* gc_roots[5] = { &l4, &l14, &l21, &l30, &l42 };
    void** gc_raw_roots[25] = { &l0, &l3, &l13, &l15, &l16, &l19, &l20, &l22, &l23, &l24, &l25, &l26, &l27, &l28, &l31, &l33, &l34, &l38, &l44, &l45, &l46, &l49, &l51, &l52, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 5u, 25u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth;
    l2 = (t0 + INT32_C(1));
    ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth = l2;
    VADER_WRITE_BARRIER((vader_struct_vader_parser_Parser_t*) l0);
    t0 = ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth;
    if ((t0 > INT32_C(256))) {
        t0 = ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth;
        l2 = (t0 - INT32_C(1));
        ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth = l2;
        VADER_WRITE_BARRIER((vader_struct_vader_parser_Parser_t*) l0);
        t1 = vader_parser_peek(l0);
        l3 = ((vader_struct_vader_lexer_Token_t*) t1)->f_span;
        vader_parser_report_nesting_too_deep(l0, 1427u);
        vader_struct_toolchain_ast_NullLitExpr_t* _a0_obj = (vader_struct_toolchain_ast_NullLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_NullLitExpr_t));
        vader_obj_header_init(_a0_obj, 456u);
        _a0_obj->f_span = l3;
        _a0_obj->f_id = (size_t) (int64_t) INT64_C(0);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = vader_parser_parse_prefix(l0);
    if (l4.tag == 433u) {
        l3 = l4.payload.obj;
        t2 = ((vader_struct_vader_parser_Parser_t*) l0)->f_allow_bare_lambda;
        if (t2) {
            l5 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(68));
        } else {
            l5 = false;
        }
        if (l5) {
            t1 = vader_parser_parse_single_param_lambda_tail(l0, l3);
            l4 = vader_ref_box(t1);
        } else {
        }
    } else {
    }
    l2 = -(INT32_C(1));
    {
        loop_66: {
            l3 = vader_parser_peek(l0);
            l6 = vader_parser_postfix_bp(((vader_struct_vader_lexer_Token_t*) l3)->f_kind);
            if ((l6 >= INT32_C(0))) {
                l5 = (l6 >= l1);
            } else {
                l5 = false;
            }
            if (l5) {
                if (((vader_struct_vader_lexer_Token_t*) l3)->f_kind == INT32_C(74)) {
                    l7 = true;
                } else {
                    l7 = ((vader_struct_vader_lexer_Token_t*) l3)->f_kind == INT32_C(72);
                }
                if (l7) {
                    if (l4.tag == 436u) {
                        l9 = true;
                    } else {
                        l9 = l4.tag == 450u;
                    }
                    if (l9) {
                        l10 = true;
                    } else {
                        l10 = l4.tag == 405u;
                    }
                    l8 = l10;
                } else {
                    l8 = false;
                }
                if (l8) {
                } else {
                    l4 = vader_parser_parse_postfix(l0, l4, l3);
                    l2 = -(INT32_C(1));
                    goto loop_66;
                }
            } else {
                if (((vader_struct_vader_lexer_Token_t*) l3)->f_kind == INT32_C(55)) {
                    t1 = vader_parser_peek_at(l0, INT32_C(1));
                    l11 = ((vader_struct_vader_lexer_Token_t*) t1)->f_kind == INT32_C(21);
                } else {
                    l11 = false;
                }
                if (l11) {
                    l12 = (INT32_C(20) >= l1);
                } else {
                    l12 = false;
                }
                if (l12) {
                    if (l2 == INT32_C(20)) {
                        l13 = ((vader_struct_vader_lexer_Token_t*) l3)->f_span;
                        vader_parser_error(l0, (uint8_t) (int32_t) INT32_C(9), l13, 1263u);
                    } else {
                        vader_parser_advance(l0);
                        vader_parser_advance(l0);
                        l14 = vader_parser_parse_expr(l0, INT32_C(21));
                        t1 = l4.payload.obj;
                        l15 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_span)->f_start;
                        t1 = l14.payload.obj;
                        l16 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_span)->f_end;
                        vader_struct_toolchain_span_Span_t* _a1_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
                        vader_obj_header_init(_a1_obj, 489u);
                        _a1_obj->f_start = l15;
                        _a1_obj->f_end = l16;
                        t1 = (void*) _a1_obj;
                        vader_struct_toolchain_ast_BinaryExpr_t* _a2_obj = (vader_struct_toolchain_ast_BinaryExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BinaryExpr_t));
                        vader_obj_header_init(_a2_obj, 403u);
                        _a2_obj->f_span = t1;
                        _a2_obj->f_id = (size_t) (int64_t) INT64_C(0);
                        _a2_obj->f_op = (uint8_t) (int32_t) INT32_C(20);
                        _a2_obj->f_left = l4;
                        _a2_obj->f_right = l14;
                        _a2_obj->f_bind_as = 0u;
                        t1 = (void*) _a2_obj;
                        l4 = vader_ref_box(t1);
                        l2 = INT32_C(20);
                        goto loop_66;
                    }
                } else {
                    if (((vader_struct_vader_lexer_Token_t*) l3)->f_kind == INT32_C(55)) {
                        t1 = vader_parser_peek_at(l0, INT32_C(1));
                        l17 = ((vader_struct_vader_lexer_Token_t*) t1)->f_kind == INT32_C(19);
                    } else {
                        l17 = false;
                    }
                    if (l17) {
                        l18 = (INT32_C(20) >= l1);
                    } else {
                        l18 = false;
                    }
                    if (l18) {
                        if (l2 == INT32_C(20)) {
                            l19 = ((vader_struct_vader_lexer_Token_t*) l3)->f_span;
                            vader_parser_error(l0, (uint8_t) (int32_t) INT32_C(9), l19, 1264u);
                        } else {
                            l20 = vader_parser_advance(l0);
                            vader_parser_advance(l0);
                            l21 = vader_parser_parse_type(l0);
                            t1 = vader_parser_peek(l0);
                            if (((vader_struct_vader_lexer_Token_t*) t1)->f_kind == INT32_C(29)) {
                                l22 = vader_parser_advance(l0);
                                t1 = vader_parser_peek(l0);
                                if (((vader_struct_vader_lexer_Token_t*) t1)->f_kind == INT32_C(2)) {
                                    vader_parser_advance(l0);
                                } else {
                                }
                                l23 = ((vader_struct_vader_lexer_Token_t*) l22)->f_span;
                                vader_parser_error(l0, (uint8_t) (int32_t) INT32_C(0), l23, 1031u);
                            } else {
                            }
                            t1 = l4.payload.obj;
                            l24 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_span)->f_start;
                            t1 = l21.payload.obj;
                            l25 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_span)->f_end;
                            vader_struct_toolchain_span_Span_t* _a3_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
                            vader_obj_header_init(_a3_obj, 489u);
                            _a3_obj->f_start = l24;
                            _a3_obj->f_end = l25;
                            t1 = (void*) _a3_obj;
                            vader_struct_toolchain_ast_BinaryExpr_t* _a4_obj = (vader_struct_toolchain_ast_BinaryExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BinaryExpr_t));
                            vader_obj_header_init(_a4_obj, 403u);
                            _a4_obj->f_span = t1;
                            _a4_obj->f_id = (size_t) (int64_t) INT64_C(0);
                            _a4_obj->f_op = (uint8_t) (int32_t) INT32_C(18);
                            _a4_obj->f_left = l4;
                            _a4_obj->f_right = l21;
                            _a4_obj->f_bind_as = 0u;
                            l26 = (void*) _a4_obj;
                            l27 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l20)->f_span)->f_start;
                            t1 = l21.payload.obj;
                            l28 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_span)->f_end;
                            vader_struct_toolchain_span_Span_t* _a5_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
                            vader_obj_header_init(_a5_obj, 489u);
                            _a5_obj->f_start = l27;
                            _a5_obj->f_end = l28;
                            t1 = (void*) _a5_obj;
                            vader_struct_toolchain_ast_UnaryExpr_t* _a6_obj = (vader_struct_toolchain_ast_UnaryExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_UnaryExpr_t));
                            vader_obj_header_init(_a6_obj, 482u);
                            _a6_obj->f_span = t1;
                            _a6_obj->f_id = (size_t) (int64_t) INT64_C(0);
                            _a6_obj->f_op = (uint8_t) (int32_t) INT32_C(1);
                            _a6_obj->f_operand = vader_ref_box(l26);
                            t1 = (void*) _a6_obj;
                            l4 = vader_ref_box(t1);
                            l2 = INT32_C(20);
                            goto loop_66;
                        }
                    } else {
                        if (((vader_struct_vader_lexer_Token_t*) l3)->f_kind == INT32_C(56)) {
                            l29 = (INT32_C(6) >= l1);
                        } else {
                            l29 = false;
                        }
                        if (l29) {
                            vader_parser_advance(l0);
                            l30 = vader_parser_parse_coalesce_fallback(l0);
                            t1 = l4.payload.obj;
                            l31 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_span)->f_start;
                            l32 = -(INT32_C(1));
                            t1 = vader_parser_peek_at(l0, l32);
                            l33 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) t1)->f_span)->f_end;
                            vader_struct_toolchain_span_Span_t* _a7_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
                            vader_obj_header_init(_a7_obj, 489u);
                            _a7_obj->f_start = l31;
                            _a7_obj->f_end = l33;
                            t1 = (void*) _a7_obj;
                            vader_struct_toolchain_ast_NullCoalesceExpr_t* _a8_obj = (vader_struct_toolchain_ast_NullCoalesceExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_NullCoalesceExpr_t));
                            vader_obj_header_init(_a8_obj, 455u);
                            _a8_obj->f_span = t1;
                            _a8_obj->f_id = (size_t) (int64_t) INT64_C(0);
                            _a8_obj->f_left = l4;
                            _a8_obj->f_fallback = l30;
                            t1 = (void*) _a8_obj;
                            l4 = vader_ref_box(t1);
                            l2 = -(INT32_C(1));
                            goto loop_66;
                        }
                        l34 = vader_parser_infix_for(((vader_struct_vader_lexer_Token_t*) l3)->f_kind);
                        t2 = ((vader_struct_vader_parser_InfixOpDescr_t*) l34)->f_has;
                        if (t2) {
                            t0 = ((vader_struct_vader_parser_InfixOpDescr_t*) l34)->f_left_bp;
                            l35 = (t0 >= l1);
                        } else {
                            l35 = false;
                        }
                        if (l35) {
                            t2 = ((vader_struct_vader_parser_InfixOpDescr_t*) l34)->f_non_assoc;
                            if (t2) {
                                l37 = ((vader_struct_vader_parser_InfixOpDescr_t*) l34)->f_left_bp;
                                l36 = l2 == l37;
                            } else {
                                l36 = false;
                            }
                            if (l36) {
                                l38 = ((vader_struct_vader_lexer_Token_t*) l3)->f_span;
                                l39 = vader_parser_describe_token(l3);
                                l40 = concat_3(1262u, l39, 872u);
                                vader_parser_error(l0, (uint8_t) (int32_t) INT32_C(9), l38, l40);
                            } else {
                                vader_parser_advance(l0);
                                t2 = ((vader_struct_vader_parser_InfixOpDescr_t*) l34)->f_non_assoc;
                                if (t2) {
                                    t0 = ((vader_struct_vader_parser_InfixOpDescr_t*) l34)->f_right_bp;
                                    l41 = (t0 + INT32_C(1));
                                } else {
                                    l41 = ((vader_struct_vader_parser_InfixOpDescr_t*) l34)->f_right_bp;
                                }
                                if (((vader_struct_vader_parser_InfixOpDescr_t*) l34)->f_op == INT32_C(18)) {
                                    l42 = vader_parser_parse_type(l0);
                                } else {
                                    l42 = vader_parser_parse_expr(l0, l41);
                                }
                                if (((vader_struct_vader_lexer_Token_t*) l3)->f_kind == INT32_C(65)) {
                                    l43 = true;
                                } else {
                                    l43 = ((vader_struct_vader_lexer_Token_t*) l3)->f_kind == INT32_C(66);
                                }
                                if (l43) {
                                    t1 = l4.payload.obj;
                                    l44 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_span)->f_start;
                                    t1 = l42.payload.obj;
                                    l45 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_span)->f_end;
                                    vader_struct_toolchain_span_Span_t* _a9_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
                                    vader_obj_header_init(_a9_obj, 489u);
                                    _a9_obj->f_start = l44;
                                    _a9_obj->f_end = l45;
                                    l46 = (void*) _a9_obj;
                                    l47 = ((vader_struct_vader_lexer_Token_t*) l3)->f_kind == INT32_C(66);
                                    vader_struct_toolchain_ast_RangeExpr_t* _a10_obj = (vader_struct_toolchain_ast_RangeExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_RangeExpr_t));
                                    vader_obj_header_init(_a10_obj, 461u);
                                    _a10_obj->f_span = l46;
                                    _a10_obj->f_id = (size_t) (int64_t) INT64_C(0);
                                    _a10_obj->f_inclusive = l47;
                                    _a10_obj->f_lower = l4;
                                    _a10_obj->f_upper = l42;
                                    t1 = (void*) _a10_obj;
                                    l4 = vader_ref_box(t1);
                                } else {
                                    l48 = 0u;
                                    t1 = l42.payload.obj;
                                    l49 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_span)->f_end;
                                    if (((vader_struct_vader_parser_InfixOpDescr_t*) l34)->f_op == INT32_C(18)) {
                                        t1 = vader_parser_peek(l0);
                                        l50 = ((vader_struct_vader_lexer_Token_t*) t1)->f_kind == INT32_C(29);
                                    } else {
                                        l50 = false;
                                    }
                                    if (l50) {
                                        vader_parser_advance(l0);
                                        l51 = vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(2), 1168u);
                                        l48 = ((vader_struct_vader_lexer_Token_t*) l51)->f_text;
                                        l49 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l51)->f_span)->f_end;
                                    } else {
                                    }
                                    t1 = l4.payload.obj;
                                    vader_struct_toolchain_span_Span_t* _a11_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
                                    vader_obj_header_init(_a11_obj, 489u);
                                    _a11_obj->f_start = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_span)->f_start;
                                    _a11_obj->f_end = l49;
                                    l52 = (void*) _a11_obj;
                                    l53 = ((vader_struct_vader_parser_InfixOpDescr_t*) l34)->f_op;
                                    vader_struct_toolchain_ast_BinaryExpr_t* _a12_obj = (vader_struct_toolchain_ast_BinaryExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BinaryExpr_t));
                                    vader_obj_header_init(_a12_obj, 403u);
                                    _a12_obj->f_span = l52;
                                    _a12_obj->f_id = (size_t) (int64_t) INT64_C(0);
                                    _a12_obj->f_op = l53;
                                    _a12_obj->f_left = l4;
                                    _a12_obj->f_right = l42;
                                    _a12_obj->f_bind_as = l48;
                                    t1 = (void*) _a12_obj;
                                    l4 = vader_ref_box(t1);
                                }
                                t2 = ((vader_struct_vader_parser_InfixOpDescr_t*) l34)->f_non_assoc;
                                if (t2) {
                                    l54 = ((vader_struct_vader_parser_InfixOpDescr_t*) l34)->f_left_bp;
                                } else {
                                    l54 = -(INT32_C(1));
                                }
                                l2 = l54;
                                goto loop_66;
                            }
                        } else {
                        }
                    }
                }
            }
            l55 = ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth;
            l56 = INT32_C(1);
            l57 = (l55 - l56);
            ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth = l57;
            VADER_WRITE_BARRIER((vader_struct_vader_parser_Parser_t*) l0);
            { vader_box_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l55 = ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth;
    l56 = INT32_C(1);
    l57 = (l55 - l56);
    ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth = l57;
    VADER_WRITE_BARRIER((vader_struct_vader_parser_Parser_t*) l0);
    { vader_box_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_parser_parse_fn_body_tail(void* l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    void* l4 = NULL;
    bool t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[4] = { &l0, &l3, &l4, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(57));
    if (t0) {
        vader_parser_advance(l0);
        l2 = vader_parser_parse_expr(l0, INT32_C(0));
        t1 = l2.payload.obj;
        l3 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_span;
        vader_array_t* _a0_arr = vader_array_new(110u, 0u, 13u, 1047u);
        l4 = (void*) _a0_arr;
        vader_struct_toolchain_ast_BlockExpr_t* _a1_obj = (vader_struct_toolchain_ast_BlockExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BlockExpr_t));
        vader_obj_header_init(_a1_obj, 405u);
        _a1_obj->f_span = l3;
        _a1_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a1_obj->f_stmts = l4;
        _a1_obj->f_trailing = l2;
        t1 = (void*) _a1_obj;
        vader_struct_vader_parser_FnBodyTail_t* _a2_obj = (vader_struct_vader_parser_FnBodyTail_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_FnBodyTail_t));
        vader_obj_header_init(_a2_obj, 864u);
        _a2_obj->f_body = vader_ref_box(t1);
        _a2_obj->f_is_expression_bodied = true;
        t1 = (void*) _a2_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(76));
    if (t0) {
        t1 = vader_parser_parse_block(l0);
        vader_struct_vader_parser_FnBodyTail_t* _a3_obj = (vader_struct_vader_parser_FnBodyTail_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_FnBodyTail_t));
        vader_obj_header_init(_a3_obj, 864u);
        _a3_obj->f_body = vader_ref_box(t1);
        _a3_obj->f_is_expression_bodied = false;
        t1 = (void*) _a3_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_parser_FnBodyTail_t* _a4_obj = (vader_struct_vader_parser_FnBodyTail_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_FnBodyTail_t));
    vader_obj_header_init(_a4_obj, 864u);
    _a4_obj->f_body = vader_box_obj(0u, NULL);
    _a4_obj->f_is_expression_bodied = false;
    t1 = (void*) _a4_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_parser_parse_fn_decl(void* l0, void* l1, uint8_t l2, void* l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l9 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    vader_box_t l7 = vader_box_null(), l13 = vader_box_null();
    int32_t l8;
    vader_string_t l10;
    bool l14, l15;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[3] = { &l7, &l13, &t0 };
    void** gc_raw_roots[10] = { &l0, &l1, &l3, &l4, &l5, &l6, &l9, &l11, &l12, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 10u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_parser_advance(l0);
    l4 = vader_parser_parse_angle_type_params(l0);
    l5 = vader_parser_parse_fn_signature_params(l0);
    l6 = ((vader_struct_vader_parser_FnSignature_t*) l5)->f_type_params;
    l4 = vader_parser_merge_type_params(l4, l6);
    l7 = vader_box_obj(0u, NULL);
    t0 = vader_parser_match_kind(l0, (uint8_t) (int32_t) INT32_C(68));
    if (!(t0.tag == 0u)) {
        l7 = vader_parser_parse_type(l0);
    } else {
    }
    l6 = vader_parser_parse_fn_body_tail(l0, l7);
    l8 = -(INT32_C(1));
    l9 = vader_parser_peek_at(l0, l8);
    l9 = vader_parser_span_of(l0, l3, l9);
    l10 = ((vader_struct_vader_lexer_Token_t*) l3)->f_text;
    l11 = ((vader_struct_vader_lexer_Token_t*) l3)->f_span;
    l12 = ((vader_struct_vader_parser_FnSignature_t*) l5)->f_params;
    l13 = ((vader_struct_vader_parser_FnBodyTail_t*) l6)->f_body;
    l14 = ((vader_struct_vader_parser_FnBodyTail_t*) l6)->f_is_expression_bodied;
    l15 = ((vader_struct_vader_parser_FnSignature_t*) l5)->f_trailing_comma;
    vader_struct_toolchain_ast_FnDecl_t* _a0_obj = (vader_struct_toolchain_ast_FnDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FnDecl_t));
    vader_obj_header_init(_a0_obj, 428u);
    _a0_obj->f_span = l9;
    _a0_obj->f_id = (size_t) (int64_t) INT64_C(0);
    _a0_obj->f_name = l10;
    _a0_obj->f_name_span = l11;
    _a0_obj->f_visibility = l2;
    _a0_obj->f_type_params = l4;
    _a0_obj->f_params = l12;
    _a0_obj->f_return_type = l7;
    _a0_obj->f_body = l13;
    _a0_obj->f_decorators = l1;
    _a0_obj->f_sam_synthetic = false;
    _a0_obj->f_is_expression_bodied = l14;
    _a0_obj->f_materialized = false;
    _a0_obj->f_comptime_synthetic = false;
    _a0_obj->f_trailing_comma = l15;
    t1 = (void*) _a0_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t vader_parser_parse_fn_decl_inside_trait(void* l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    uint8_t l2;
    bool l3, l7, l8;
    vader_string_t l6;
    vader_box_t l11 = vader_box_null(), l15 = vader_box_null();
    int32_t l12;
    vader_box_t t0 = vader_box_null();
    bool t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[3] = { &l11, &l15, &t0 };
    void** gc_raw_roots[9] = { &l0, &l1, &l4, &l5, &l9, &l10, &l13, &l14, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 9u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_parse_decorators(l0);
    l2 = (uint8_t) (int32_t) INT32_C(1);
    t0 = vader_parser_match_kind(l0, (uint8_t) (int32_t) INT32_C(30));
    if (!(t0.tag == 0u)) {
        l2 = (uint8_t) (int32_t) INT32_C(0);
    } else {
    }
    t1 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(2));
    if (t1) {
        t2 = vader_parser_peek_at(l0, INT32_C(1));
        l3 = ((vader_struct_vader_lexer_Token_t*) t2)->f_kind == INT32_C(63);
    } else {
        l3 = false;
    }
    if (l3) {
        t2 = vader_parser_peek_at(l0, INT32_C(2));
        l3 = ((vader_struct_vader_lexer_Token_t*) t2)->f_kind == INT32_C(11);
    } else {
        l3 = false;
    }
    if (!(l3)) {
        l4 = vader_parser_peek(l0);
        if (((vader_struct_vader_lexer_Token_t*) l4)->f_kind == INT32_C(11)) {
            l5 = ((vader_struct_vader_lexer_Token_t*) l4)->f_span;
            vader_parser_error(l0, (uint8_t) (int32_t) INT32_C(5), l5, 2074u);
        } else {
            l5 = ((vader_struct_vader_lexer_Token_t*) l4)->f_span;
            l6 = vader_parser_describe_token(l4);
            l6 = concat_3(1414u, l6, 320u);
            vader_parser_error(l0, (uint8_t) (int32_t) INT32_C(5), l5, l6);
        }
        {
            loop_78: {
                t1 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(77));
                if (!(t1)) {
                    t1 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(0));
                    l3 = !(t1);
                } else {
                    l3 = false;
                }
                if (l3) {
                    t1 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(2));
                    if (t1) {
                        t2 = vader_parser_peek_at(l0, INT32_C(1));
                        l7 = ((vader_struct_vader_lexer_Token_t*) t2)->f_kind == INT32_C(63);
                    } else {
                        l7 = false;
                    }
                    if (l7) {
                        t2 = vader_parser_peek_at(l0, INT32_C(2));
                        l8 = ((vader_struct_vader_lexer_Token_t*) t2)->f_kind == INT32_C(11);
                    } else {
                        l8 = false;
                    }
                    if (l8) {
                    } else {
                        vader_parser_advance(l0);
                        goto loop_78;
                    }
                } else {
                }
            }
        }
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = vader_parser_advance(l0);
    vader_parser_advance(l0);
    vader_parser_advance(l0);
    l5 = vader_parser_parse_angle_type_params(l0);
    l9 = vader_parser_parse_fn_signature_params(l0);
    l10 = ((vader_struct_vader_parser_FnSignature_t*) l9)->f_type_params;
    l5 = vader_parser_merge_type_params(l5, l10);
    l11 = vader_box_obj(0u, NULL);
    t0 = vader_parser_match_kind(l0, (uint8_t) (int32_t) INT32_C(68));
    if (!(t0.tag == 0u)) {
        l11 = vader_parser_parse_type(l0);
    } else {
    }
    l10 = vader_parser_parse_fn_body_tail(l0, l11);
    l12 = -(INT32_C(1));
    l13 = vader_parser_peek_at(l0, l12);
    l13 = vader_parser_span_of(l0, l4, l13);
    l6 = ((vader_struct_vader_lexer_Token_t*) l4)->f_text;
    l4 = ((vader_struct_vader_lexer_Token_t*) l4)->f_span;
    l14 = ((vader_struct_vader_parser_FnSignature_t*) l9)->f_params;
    l15 = ((vader_struct_vader_parser_FnBodyTail_t*) l10)->f_body;
    l3 = ((vader_struct_vader_parser_FnBodyTail_t*) l10)->f_is_expression_bodied;
    l7 = ((vader_struct_vader_parser_FnSignature_t*) l9)->f_trailing_comma;
    vader_struct_toolchain_ast_FnDecl_t* _a0_obj = (vader_struct_toolchain_ast_FnDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FnDecl_t));
    vader_obj_header_init(_a0_obj, 428u);
    _a0_obj->f_span = l13;
    _a0_obj->f_id = (size_t) (int64_t) INT64_C(0);
    _a0_obj->f_name = l6;
    _a0_obj->f_name_span = l4;
    _a0_obj->f_visibility = l2;
    _a0_obj->f_type_params = l5;
    _a0_obj->f_params = l14;
    _a0_obj->f_return_type = l11;
    _a0_obj->f_body = l15;
    _a0_obj->f_decorators = l1;
    _a0_obj->f_sam_synthetic = false;
    _a0_obj->f_is_expression_bodied = l3;
    _a0_obj->f_materialized = false;
    _a0_obj->f_comptime_synthetic = false;
    _a0_obj->f_trailing_comma = l7;
    t2 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_parser_parse_fn_signature_params(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l6 = NULL;
    void* l15 = NULL;
    void* l19 = NULL;
    void* l21 = NULL;
    void* l44 = NULL;
    void* l51 = NULL;
    void* l55 = NULL;
    void* l56 = NULL;
    void* l60 = NULL;
    bool l3, l4, l5, l7, l9, l12, l17, l27, l29, l31, l33, l34, l39, l42, l50, l59;
    uint8_t l8, l10, l13, l16, l18, l20, l26, l28, l30, l32, l35, l37, l40, l43;
    int32_t l11, l14, l41, l54;
    vader_string_t l22, l23, l24, l25, l45, l46, l47, l48, l58;
    vader_box_t l36 = vader_box_null(), l38 = vader_box_null(), l49 = vader_box_null(), l53 = vader_box_null();
    size_t l52, l57;
    bool t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[5] = { &l36, &l38, &l49, &l53, &t1 };
    void** gc_raw_roots[13] = { &l0, &l1, &l2, &l6, &l15, &l19, &l21, &l44, &l51, &l55, &l56, &l60, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 5u, 13u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(33u, 0u, 13u, 481u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(24u, 0u, 13u, 429u);
    l2 = (void*) _a1_arr;
    l3 = false;
    vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(72), 972u);
    vader_parser_skip_newlines(l0);
    t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(73));
    if (!(t0)) {
        l4 = true;
        {
            loop_21: {
                vader_parser_skip_newlines(l0);
                t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(73));
                if (t0) {
                    l5 = true;
                } else {
                    l5 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(0));
                }
                if (l5) {
                } else {
                    if (!(l4)) {
                        t1 = vader_parser_match_kind(l0, (uint8_t) (int32_t) INT32_C(78));
                        if (t1.tag == 0u) {
                        } else {
                            vader_parser_skip_newlines(l0);
                            t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(73));
                            if (t0) {
                                l3 = true;
                            } else {
                                l4 = false;
                                l6 = vader_parser_peek(l0);
                                l7 = false;
                                l8 = (uint8_t) (int32_t) INT32_C(79);
                                t0 = vader_parser_check(l0, l8);
                                if (t0) {
                                    l10 = (uint8_t) (int32_t) INT32_C(79);
                                    l11 = INT32_C(1);
                                    l9 = vader_parser_check_at(l0, l10, l11);
                                } else {
                                    l9 = false;
                                }
                                if (l9) {
                                    l13 = (uint8_t) (int32_t) INT32_C(79);
                                    l14 = INT32_C(2);
                                    l12 = vader_parser_check_at(l0, l13, l14);
                                } else {
                                    l12 = false;
                                }
                                if (l12) {
                                    vader_parser_advance(l0);
                                    vader_parser_advance(l0);
                                    vader_parser_advance(l0);
                                    l7 = true;
                                } else {
                                }
                                vader_parser_empty_token();
                                l16 = (uint8_t) (int32_t) INT32_C(34);
                                t0 = vader_parser_check(l0, l16);
                                if (t0) {
                                    l17 = true;
                                } else {
                                    l18 = (uint8_t) (int32_t) INT32_C(2);
                                    l17 = vader_parser_check(l0, l18);
                                }
                                if (l17) {
                                    l15 = vader_parser_advance(l0);
                                    l31 = false;
                                    l32 = (uint8_t) (int32_t) INT32_C(55);
                                    t1 = vader_parser_match_kind(l0, l32);
                                    if (!(t1.tag == 0u)) {
                                        l31 = true;
                                    } else {
                                    }
                                    l33 = false;
                                    if (!(l31)) {
                                        l35 = (uint8_t) (int32_t) INT32_C(48);
                                        l34 = vader_parser_check(l0, l35);
                                    } else {
                                        l34 = false;
                                    }
                                    if (l34) {
                                        vader_parser_advance(l0);
                                        l31 = true;
                                        l33 = true;
                                    } else {
                                    }
                                    l36 = vader_box_obj(0u, NULL);
                                    l37 = (uint8_t) (int32_t) INT32_C(80);
                                    t1 = vader_parser_match_kind(l0, l37);
                                    if (!(t1.tag == 0u)) {
                                        vader_parser_skip_newlines(l0);
                                        l36 = vader_parser_parse_type(l0);
                                    } else {
                                    }
                                    l38 = vader_box_obj(0u, NULL);
                                    if (l33) {
                                        l39 = true;
                                    } else {
                                        l40 = (uint8_t) (int32_t) INT32_C(57);
                                        t1 = vader_parser_match_kind(l0, l40);
                                        l39 = !(t1.tag == 0u);
                                    }
                                    if (l39) {
                                        l41 = INT32_C(0);
                                        l38 = vader_parser_parse_expr(l0, l41);
                                    } else {
                                    }
                                    vader_parser_collect_type_params(l36, l1);
                                    if (l31) {
                                        l42 = !(l36.tag == 0u);
                                    } else {
                                        l42 = false;
                                    }
                                    if (l42) {
                                        l43 = (uint8_t) (int32_t) INT32_C(27);
                                        l44 = ((vader_struct_vader_lexer_Token_t*) l15)->f_span;
                                        l45 = 2305u;
                                        l46 = ((vader_struct_vader_lexer_Token_t*) l15)->f_text;
                                        l47 = 441u;
                                        l48 = concat_3(l45, l46, l47);
                                        vader_parser_error(l0, l43, l44, l48);
                                    } else {
                                    }
                                    if (l31) {
                                        l50 = !(l36.tag == 0u);
                                    } else {
                                        l50 = false;
                                    }
                                    if (l50) {
                                        t2 = l36.payload.obj;
                                        l51 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t2)->f_span;
                                        l52 = (size_t) (int64_t) INT64_C(0);
                                        l53 = l36;
                                        vader_struct_toolchain_ast_MutableTypeExpr_t* _a2_obj = (vader_struct_toolchain_ast_MutableTypeExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_MutableTypeExpr_t));
                                        vader_obj_header_init(_a2_obj, 452u);
                                        _a2_obj->f_span = l51;
                                        _a2_obj->f_id = l52;
                                        _a2_obj->f_inner = l53;
                                        t2 = (void*) _a2_obj;
                                        l49 = vader_ref_box(t2);
                                    } else {
                                        l49 = l36;
                                    }
                                    l54 = -(INT32_C(1));
                                    l55 = vader_parser_peek_at(l0, l54);
                                    l56 = vader_parser_span_of(l0, l6, l55);
                                    l57 = (size_t) (int64_t) INT64_C(0);
                                    l58 = ((vader_struct_vader_lexer_Token_t*) l15)->f_text;
                                    if (l31) {
                                        l59 = l36.tag == 0u;
                                    } else {
                                        l59 = false;
                                    }
                                    vader_struct_toolchain_ast_FnParam_t* _a3_obj = (vader_struct_toolchain_ast_FnParam_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FnParam_t));
                                    vader_obj_header_init(_a3_obj, 429u);
                                    _a3_obj->f_span = l56;
                                    _a3_obj->f_id = l57;
                                    _a3_obj->f_name = l58;
                                    _a3_obj->f_ty = l49;
                                    _a3_obj->f_default_value = l38;
                                    _a3_obj->f_variadic = l7;
                                    _a3_obj->f_mutable = l59;
                                    l60 = (void*) _a3_obj;
                                    vader_array_push((vader_array_t*) l2, vader_ref_box(l60));
                                    goto loop_21;
                                }
                                l19 = vader_parser_peek(l0);
                                l20 = (uint8_t) (int32_t) INT32_C(1);
                                l21 = ((vader_struct_vader_lexer_Token_t*) l19)->f_span;
                                l22 = 1415u;
                                l23 = vader_parser_describe_token(l19);
                                l24 = 320u;
                                l25 = concat_3(l22, l23, l24);
                                vader_parser_error(l0, l20, l21, l25);
                                {
                                    loop_351: {
                                        l26 = (uint8_t) (int32_t) INT32_C(78);
                                        t0 = vader_parser_check(l0, l26);
                                        if (!(t0)) {
                                            l28 = (uint8_t) (int32_t) INT32_C(73);
                                            t0 = vader_parser_check(l0, l28);
                                            l27 = !(t0);
                                        } else {
                                            l27 = false;
                                        }
                                        if (l27) {
                                            l30 = (uint8_t) (int32_t) INT32_C(0);
                                            t0 = vader_parser_check(l0, l30);
                                            l29 = !(t0);
                                        } else {
                                            l29 = false;
                                        }
                                        if (l29) {
                                            vader_parser_advance(l0);
                                            goto loop_351;
                                        } else {
                                        }
                                    }
                                }
                                goto loop_21;
                            }
                        }
                    } else {
                        l4 = false;
                        l6 = vader_parser_peek(l0);
                        l7 = false;
                        l8 = (uint8_t) (int32_t) INT32_C(79);
                        t0 = vader_parser_check(l0, l8);
                        if (t0) {
                            l10 = (uint8_t) (int32_t) INT32_C(79);
                            l11 = INT32_C(1);
                            l9 = vader_parser_check_at(l0, l10, l11);
                        } else {
                            l9 = false;
                        }
                        if (l9) {
                            l13 = (uint8_t) (int32_t) INT32_C(79);
                            l14 = INT32_C(2);
                            l12 = vader_parser_check_at(l0, l13, l14);
                        } else {
                            l12 = false;
                        }
                        if (l12) {
                            vader_parser_advance(l0);
                            vader_parser_advance(l0);
                            vader_parser_advance(l0);
                            l7 = true;
                        } else {
                        }
                        vader_parser_empty_token();
                        l16 = (uint8_t) (int32_t) INT32_C(34);
                        t0 = vader_parser_check(l0, l16);
                        if (t0) {
                            l17 = true;
                        } else {
                            l18 = (uint8_t) (int32_t) INT32_C(2);
                            l17 = vader_parser_check(l0, l18);
                        }
                        if (l17) {
                            l15 = vader_parser_advance(l0);
                            l31 = false;
                            l32 = (uint8_t) (int32_t) INT32_C(55);
                            t1 = vader_parser_match_kind(l0, l32);
                            if (!(t1.tag == 0u)) {
                                l31 = true;
                            } else {
                            }
                            l33 = false;
                            if (!(l31)) {
                                l35 = (uint8_t) (int32_t) INT32_C(48);
                                l34 = vader_parser_check(l0, l35);
                            } else {
                                l34 = false;
                            }
                            if (l34) {
                                vader_parser_advance(l0);
                                l31 = true;
                                l33 = true;
                            } else {
                            }
                            l36 = vader_box_obj(0u, NULL);
                            l37 = (uint8_t) (int32_t) INT32_C(80);
                            t1 = vader_parser_match_kind(l0, l37);
                            if (!(t1.tag == 0u)) {
                                vader_parser_skip_newlines(l0);
                                l36 = vader_parser_parse_type(l0);
                            } else {
                            }
                            l38 = vader_box_obj(0u, NULL);
                            if (l33) {
                                l39 = true;
                            } else {
                                l40 = (uint8_t) (int32_t) INT32_C(57);
                                t1 = vader_parser_match_kind(l0, l40);
                                l39 = !(t1.tag == 0u);
                            }
                            if (l39) {
                                l41 = INT32_C(0);
                                l38 = vader_parser_parse_expr(l0, l41);
                            } else {
                            }
                            vader_parser_collect_type_params(l36, l1);
                            if (l31) {
                                l42 = !(l36.tag == 0u);
                            } else {
                                l42 = false;
                            }
                            if (l42) {
                                l43 = (uint8_t) (int32_t) INT32_C(27);
                                l44 = ((vader_struct_vader_lexer_Token_t*) l15)->f_span;
                                l45 = 2305u;
                                l46 = ((vader_struct_vader_lexer_Token_t*) l15)->f_text;
                                l47 = 441u;
                                l48 = concat_3(l45, l46, l47);
                                vader_parser_error(l0, l43, l44, l48);
                            } else {
                            }
                            if (l31) {
                                l50 = !(l36.tag == 0u);
                            } else {
                                l50 = false;
                            }
                            if (l50) {
                                t2 = l36.payload.obj;
                                l51 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t2)->f_span;
                                l52 = (size_t) (int64_t) INT64_C(0);
                                l53 = l36;
                                vader_struct_toolchain_ast_MutableTypeExpr_t* _a4_obj = (vader_struct_toolchain_ast_MutableTypeExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_MutableTypeExpr_t));
                                vader_obj_header_init(_a4_obj, 452u);
                                _a4_obj->f_span = l51;
                                _a4_obj->f_id = l52;
                                _a4_obj->f_inner = l53;
                                t2 = (void*) _a4_obj;
                                l49 = vader_ref_box(t2);
                            } else {
                                l49 = l36;
                            }
                            l54 = -(INT32_C(1));
                            l55 = vader_parser_peek_at(l0, l54);
                            l56 = vader_parser_span_of(l0, l6, l55);
                            l57 = (size_t) (int64_t) INT64_C(0);
                            l58 = ((vader_struct_vader_lexer_Token_t*) l15)->f_text;
                            if (l31) {
                                l59 = l36.tag == 0u;
                            } else {
                                l59 = false;
                            }
                            vader_struct_toolchain_ast_FnParam_t* _a5_obj = (vader_struct_toolchain_ast_FnParam_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FnParam_t));
                            vader_obj_header_init(_a5_obj, 429u);
                            _a5_obj->f_span = l56;
                            _a5_obj->f_id = l57;
                            _a5_obj->f_name = l58;
                            _a5_obj->f_ty = l49;
                            _a5_obj->f_default_value = l38;
                            _a5_obj->f_variadic = l7;
                            _a5_obj->f_mutable = l59;
                            l60 = (void*) _a5_obj;
                            vader_array_push((vader_array_t*) l2, vader_ref_box(l60));
                            goto loop_21;
                        }
                        l19 = vader_parser_peek(l0);
                        l20 = (uint8_t) (int32_t) INT32_C(1);
                        l21 = ((vader_struct_vader_lexer_Token_t*) l19)->f_span;
                        l22 = 1415u;
                        l23 = vader_parser_describe_token(l19);
                        l24 = 320u;
                        l25 = concat_3(l22, l23, l24);
                        vader_parser_error(l0, l20, l21, l25);
                        {
                            loop_691: {
                                l26 = (uint8_t) (int32_t) INT32_C(78);
                                t0 = vader_parser_check(l0, l26);
                                if (!(t0)) {
                                    l28 = (uint8_t) (int32_t) INT32_C(73);
                                    t0 = vader_parser_check(l0, l28);
                                    l27 = !(t0);
                                } else {
                                    l27 = false;
                                }
                                if (l27) {
                                    l30 = (uint8_t) (int32_t) INT32_C(0);
                                    t0 = vader_parser_check(l0, l30);
                                    l29 = !(t0);
                                } else {
                                    l29 = false;
                                }
                                if (l29) {
                                    vader_parser_advance(l0);
                                    goto loop_691;
                                } else {
                                }
                            }
                        }
                        goto loop_21;
                    }
                }
                goto end_17;
            }
        }
    } else {
    } end_17: ;
    vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(73), 981u);
    vader_struct_vader_parser_FnSignature_t* _a6_obj = (vader_struct_vader_parser_FnSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_FnSignature_t));
    vader_obj_header_init(_a6_obj, 865u);
    _a6_obj->f_params = l2;
    _a6_obj->f_type_params = l1;
    _a6_obj->f_trailing_comma = l3;
    t2 = (void*) _a6_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_parser_parse_fn_type(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l8 = NULL;
    bool l4, l6;
    vader_box_t l5 = vader_box_null(), l9 = vader_box_null();
    int32_t l7;
    bool t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[3] = { &l5, &l9, &t1 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l8, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_advance(l0);
    vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(72), 971u);
    vader_array_t* _a0_arr = vader_array_new(108u, 0u, 13u, 1034u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(6u, 0u, 12u, 159u);
    l3 = (void*) _a1_arr;
    l4 = false;
    vader_parser_skip_newlines(l0);
    t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(73));
    if (!(t0)) {
        {
            loop_22: {
                vader_parser_skip_newlines(l0);
                t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(73));
                if (t0) {
                } else {
                    l5 = vader_parser_parse_type(l0);
                    vader_array_push((vader_array_t*) l2, l5);
                    t1 = vader_parser_match_kind(l0, (uint8_t) (int32_t) INT32_C(55));
                    l6 = !(t1.tag == 0u);
                    if (l6) {
                        l4 = true;
                    } else {
                    }
                    vader_array_push_bool((vader_array_t*) l3, l6);
                    vader_parser_skip_newlines(l0);
                    t1 = vader_parser_match_kind(l0, (uint8_t) (int32_t) INT32_C(78));
                    if (t1.tag == 0u) {
                    } else {
                        goto loop_22;
                    }
                }
                goto end_20;
            }
        }
    } else {
    } end_20: ;
    vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(73), 978u);
    l5 = vader_box_obj(0u, NULL);
    t1 = vader_parser_match_kind(l0, (uint8_t) (int32_t) INT32_C(68));
    if (!(t1.tag == 0u)) {
        l5 = vader_parser_parse_type(l0);
    } else {
    }
    l7 = -(INT32_C(1));
    l8 = vader_parser_peek_at(l0, l7);
    l1 = vader_parser_span_of(l0, l1, l8);
    if (l4) {
        l9 = vader_ref_box(l3);
    } else {
        vader_array_t* _a2_arr = vader_array_new(6u, 0u, 12u, 159u);
        t2 = (void*) _a2_arr;
        l9 = vader_ref_box(t2);
    }
    vader_struct_toolchain_ast_FnTypeExpr_t* _a3_obj = (vader_struct_toolchain_ast_FnTypeExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FnTypeExpr_t));
    vader_obj_header_init(_a3_obj, 430u);
    _a3_obj->f_span = l1;
    _a3_obj->f_id = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_params = l2;
    _a3_obj->f_params_mutable = l9.payload.obj;
    _a3_obj->f_return_type = l5;
    t2 = (void*) _a3_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_parser_parse_for(void* l0, vader_box_t l1, bool l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l10 = NULL;
    bool l7, l8;
    vader_box_t l9 = vader_box_null(), l12 = vader_box_null();
    vader_string_t l11;
    bool t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[3] = { &l1, &l9, &l12 };
    void** gc_raw_roots[7] = { &l0, &l3, &l4, &l5, &l6, &l10, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_parser_advance(l0);
    t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(76));
    if (t0) {
        l4 = vader_parser_parse_block(l0);
        l5 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l3)->f_span)->f_start;
        l6 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_BlockExpr_t*) l4)->f_span)->f_end;
        vader_struct_toolchain_span_Span_t* _a0_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
        vader_obj_header_init(_a0_obj, 489u);
        _a0_obj->f_start = l5;
        _a0_obj->f_end = l6;
        l5 = (void*) _a0_obj;
        vader_struct_toolchain_ast_InfiniteFor_t* _a1_obj = (vader_struct_toolchain_ast_InfiniteFor_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_InfiniteFor_t));
        vader_obj_header_init(_a1_obj, 442u);
        l6 = (void*) _a1_obj;
        vader_struct_toolchain_ast_ForStmt_t* _a2_obj = (vader_struct_toolchain_ast_ForStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ForStmt_t));
        vader_obj_header_init(_a2_obj, 431u);
        _a2_obj->f_span = l5;
        _a2_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a2_obj->f_label = l1;
        _a2_obj->f_form = vader_ref_box(l6);
        _a2_obj->f_body = l4;
        _a2_obj->f_is_comptime = l2;
        t1 = (void*) _a2_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l7 = ((vader_struct_vader_parser_Parser_t*) l0)->f_allow_struct_lit;
    ((vader_struct_vader_parser_Parser_t*) l0)->f_allow_struct_lit = false;
    VADER_WRITE_BARRIER((vader_struct_vader_parser_Parser_t*) l0);
    t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(2));
    if (t0) {
        l8 = vader_parser_check_at(l0, (uint8_t) (int32_t) INT32_C(21), INT32_C(1));
    } else {
        l8 = false;
    }
    if (l8) {
        l4 = vader_parser_advance(l0);
        vader_parser_advance(l0);
        l9 = vader_parser_parse_expr(l0, INT32_C(0));
        ((vader_struct_vader_parser_Parser_t*) l0)->f_allow_struct_lit = l7;
        VADER_WRITE_BARRIER((vader_struct_vader_parser_Parser_t*) l0);
        l5 = vader_parser_parse_block(l0);
        l6 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l3)->f_span)->f_start;
        l10 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_BlockExpr_t*) l5)->f_span)->f_end;
        vader_struct_toolchain_span_Span_t* _a3_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
        vader_obj_header_init(_a3_obj, 489u);
        _a3_obj->f_start = l6;
        _a3_obj->f_end = l10;
        l6 = (void*) _a3_obj;
        l11 = ((vader_struct_vader_lexer_Token_t*) l4)->f_text;
        l4 = ((vader_struct_vader_lexer_Token_t*) l4)->f_span;
        vader_struct_toolchain_ast_NamedVar_t* _a4_obj = (vader_struct_toolchain_ast_NamedVar_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_NamedVar_t));
        vader_obj_header_init(_a4_obj, 454u);
        _a4_obj->f_name = l11;
        _a4_obj->f_span = l4;
        t1 = (void*) _a4_obj;
        vader_struct_toolchain_ast_InFor_t* _a5_obj = (vader_struct_toolchain_ast_InFor_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_InFor_t));
        vader_obj_header_init(_a5_obj, 440u);
        _a5_obj->f_loop_var = vader_ref_box(t1);
        _a5_obj->f_iter = l9;
        l4 = (void*) _a5_obj;
        vader_struct_toolchain_ast_ForStmt_t* _a6_obj = (vader_struct_toolchain_ast_ForStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ForStmt_t));
        vader_obj_header_init(_a6_obj, 431u);
        _a6_obj->f_span = l6;
        _a6_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a6_obj->f_label = l1;
        _a6_obj->f_form = vader_ref_box(l4);
        _a6_obj->f_body = l5;
        _a6_obj->f_is_comptime = l2;
        t1 = (void*) _a6_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_parser_looks_like_for_destructure(l0);
    if (t0) {
        l9 = vader_parser_parse_let_binding(l0);
        vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(21), 1042u);
        l12 = vader_parser_parse_expr(l0, INT32_C(0));
        ((vader_struct_vader_parser_Parser_t*) l0)->f_allow_struct_lit = l7;
        VADER_WRITE_BARRIER((vader_struct_vader_parser_Parser_t*) l0);
        l4 = vader_parser_parse_block(l0);
        l5 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l3)->f_span)->f_start;
        l6 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_BlockExpr_t*) l4)->f_span)->f_end;
        vader_struct_toolchain_span_Span_t* _a7_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
        vader_obj_header_init(_a7_obj, 489u);
        _a7_obj->f_start = l5;
        _a7_obj->f_end = l6;
        l5 = (void*) _a7_obj;
        vader_struct_toolchain_ast_DestructureVar_t* _a8_obj = (vader_struct_toolchain_ast_DestructureVar_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_DestructureVar_t));
        vader_obj_header_init(_a8_obj, 419u);
        _a8_obj->f_pattern = l9;
        t1 = (void*) _a8_obj;
        vader_struct_toolchain_ast_InFor_t* _a9_obj = (vader_struct_toolchain_ast_InFor_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_InFor_t));
        vader_obj_header_init(_a9_obj, 440u);
        _a9_obj->f_loop_var = vader_ref_box(t1);
        _a9_obj->f_iter = l12;
        l6 = (void*) _a9_obj;
        vader_struct_toolchain_ast_ForStmt_t* _a10_obj = (vader_struct_toolchain_ast_ForStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ForStmt_t));
        vader_obj_header_init(_a10_obj, 431u);
        _a10_obj->f_span = l5;
        _a10_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a10_obj->f_label = l1;
        _a10_obj->f_form = vader_ref_box(l6);
        _a10_obj->f_body = l4;
        _a10_obj->f_is_comptime = l2;
        t1 = (void*) _a10_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l9 = vader_parser_parse_expr(l0, INT32_C(0));
    ((vader_struct_vader_parser_Parser_t*) l0)->f_allow_struct_lit = l7;
    VADER_WRITE_BARRIER((vader_struct_vader_parser_Parser_t*) l0);
    l4 = vader_parser_parse_block(l0);
    if (l9.tag == 461u) {
        l5 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l3)->f_span)->f_start;
        l6 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_BlockExpr_t*) l4)->f_span)->f_end;
        vader_struct_toolchain_span_Span_t* _a11_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
        vader_obj_header_init(_a11_obj, 489u);
        _a11_obj->f_start = l5;
        _a11_obj->f_end = l6;
        l5 = (void*) _a11_obj;
        vader_struct_toolchain_ast_DiscardVar_t* _a12_obj = (vader_struct_toolchain_ast_DiscardVar_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_DiscardVar_t));
        vader_obj_header_init(_a12_obj, 420u);
        l6 = (void*) _a12_obj;
        l10 = l9.payload.obj;
        vader_struct_toolchain_ast_InFor_t* _a13_obj = (vader_struct_toolchain_ast_InFor_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_InFor_t));
        vader_obj_header_init(_a13_obj, 440u);
        _a13_obj->f_loop_var = vader_ref_box(l6);
        _a13_obj->f_iter = vader_ref_box(l10);
        l6 = (void*) _a13_obj;
        vader_struct_toolchain_ast_ForStmt_t* _a14_obj = (vader_struct_toolchain_ast_ForStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ForStmt_t));
        vader_obj_header_init(_a14_obj, 431u);
        _a14_obj->f_span = l5;
        _a14_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a14_obj->f_label = l1;
        _a14_obj->f_form = vader_ref_box(l6);
        _a14_obj->f_body = l4;
        _a14_obj->f_is_comptime = l2;
        t1 = (void*) _a14_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l3)->f_span)->f_start;
    l5 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_BlockExpr_t*) l4)->f_span)->f_end;
    vader_struct_toolchain_span_Span_t* _a15_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a15_obj, 489u);
    _a15_obj->f_start = l3;
    _a15_obj->f_end = l5;
    l3 = (void*) _a15_obj;
    vader_struct_toolchain_ast_WhileFor_t* _a16_obj = (vader_struct_toolchain_ast_WhileFor_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_WhileFor_t));
    vader_obj_header_init(_a16_obj, 483u);
    _a16_obj->f_cond = l9;
    l5 = (void*) _a16_obj;
    vader_struct_toolchain_ast_ForStmt_t* _a17_obj = (vader_struct_toolchain_ast_ForStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ForStmt_t));
    vader_obj_header_init(_a17_obj, 431u);
    _a17_obj->f_span = l3;
    _a17_obj->f_id = (size_t) (int64_t) INT64_C(0);
    _a17_obj->f_label = l1;
    _a17_obj->f_form = vader_ref_box(l5);
    _a17_obj->f_body = l4;
    _a17_obj->f_is_comptime = l2;
    t1 = (void*) _a17_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t vader_parser_parse_ident_or_struct_lit(void* l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    bool l2;
    int32_t l3;
    vader_string_t l6;
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[7] = { &l0, &l1, &l4, &l5, &l7, &l8, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 7u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_advance(l0);
    t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(49));
    if (t0) {
        l3 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pos;
        l2 = vader_parser_scan_angle_generic(l0, l3);
    } else {
        l2 = false;
    }
    if (l2) {
        vader_parser_advance(l0);
        l4 = vader_parser_parse_type_list_until_angle(l0);
        l5 = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
        l6 = ((vader_struct_vader_lexer_Token_t*) l1)->f_text;
        l5 = vader_parser_ident_expr(l5, l6);
        l3 = -(INT32_C(1));
        l7 = vader_parser_peek_at(l0, l3);
        t1 = vader_parser_span_of(l0, l1, l7);
        vader_struct_toolchain_ast_GenericInstExpr_t* _a0_obj = (vader_struct_toolchain_ast_GenericInstExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_GenericInstExpr_t));
        vader_obj_header_init(_a0_obj, 432u);
        _a0_obj->f_span = t1;
        _a0_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a0_obj->f_callee = vader_ref_box(l5);
        _a0_obj->f_type_args = l4;
        l4 = (void*) _a0_obj;
        t0 = ((vader_struct_vader_parser_Parser_t*) l0)->f_allow_struct_lit;
        if (t0) {
            l2 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(76));
        } else {
            l2 = false;
        }
        if (l2) {
            vader_parser_advance(l0);
            l5 = vader_parser_parse_struct_lit_fields(l0);
            l7 = vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(77), 1061u);
            l7 = vader_parser_span_of(l0, l1, l7);
            l8 = ((vader_struct_vader_parser_CommaList__StructLitField___StructLitSpread_t*) l5)->f_items;
            l2 = ((vader_struct_vader_parser_CommaList__StructLitField___StructLitSpread_t*) l5)->f_trailing_comma;
            vader_struct_toolchain_ast_StructLitExpr_t* _a1_obj = (vader_struct_toolchain_ast_StructLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_StructLitExpr_t));
            vader_obj_header_init(_a1_obj, 472u);
            _a1_obj->f_span = l7;
            _a1_obj->f_id = (size_t) (int64_t) INT64_C(0);
            _a1_obj->f_type_name = vader_ref_box(l4);
            _a1_obj->f_items = l8;
            _a1_obj->f_trailing_comma = l2;
            t1 = (void*) _a1_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(72), 973u);
        l5 = vader_parser_parse_call_args(l0);
        l7 = vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(73), 980u);
        l7 = vader_parser_span_of(l0, l1, l7);
        l8 = ((vader_struct_vader_parser_CommaList__CallArg_t*) l5)->f_items;
        l2 = ((vader_struct_vader_parser_CommaList__CallArg_t*) l5)->f_trailing_comma;
        vader_struct_toolchain_ast_CallExpr_t* _a2_obj = (vader_struct_toolchain_ast_CallExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_CallExpr_t));
        vader_obj_header_init(_a2_obj, 409u);
        _a2_obj->f_span = l7;
        _a2_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a2_obj->f_callee = vader_ref_box(l4);
        _a2_obj->f_args = l8;
        _a2_obj->f_trailing_comma = l2;
        t1 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_parser_Parser_t*) l0)->f_allow_struct_lit;
    if (t0) {
        l2 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(76));
    } else {
        l2 = false;
    }
    if (l2) {
        l4 = ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens;
        l3 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pos;
        l2 = vader_parser_looks_like_struct_lit_body(l4, l3);
    } else {
        l2 = false;
    }
    if (l2) {
        vader_parser_advance(l0);
        l4 = vader_parser_parse_struct_lit_fields(l0);
        l5 = vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(77), 1061u);
        l5 = vader_parser_span_of(l0, l1, l5);
        l7 = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
        l6 = ((vader_struct_vader_lexer_Token_t*) l1)->f_text;
        l7 = vader_parser_ident_expr(l7, l6);
        l8 = ((vader_struct_vader_parser_CommaList__StructLitField___StructLitSpread_t*) l4)->f_items;
        l2 = ((vader_struct_vader_parser_CommaList__StructLitField___StructLitSpread_t*) l4)->f_trailing_comma;
        vader_struct_toolchain_ast_StructLitExpr_t* _a3_obj = (vader_struct_toolchain_ast_StructLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_StructLitExpr_t));
        vader_obj_header_init(_a3_obj, 472u);
        _a3_obj->f_span = l5;
        _a3_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a3_obj->f_type_name = vader_ref_box(l7);
        _a3_obj->f_items = l8;
        _a3_obj->f_trailing_comma = l2;
        t1 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
    l6 = ((vader_struct_vader_lexer_Token_t*) l1)->f_text;
    t1 = vader_parser_ident_expr(l4, l6);
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_parser_parse_if_expr(void* l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    bool l2;
    vader_box_t l3 = vader_box_null(), l5 = vader_box_null();
    size_t l10;
    vader_box_t t0 = vader_box_null();
    bool t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[3] = { &l3, &l5, &t0 };
    void** gc_raw_roots[8] = { &l0, &l1, &l4, &l6, &l7, &l8, &l9, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 8u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_advance(l0);
    l2 = ((vader_struct_vader_parser_Parser_t*) l0)->f_allow_struct_lit;
    ((vader_struct_vader_parser_Parser_t*) l0)->f_allow_struct_lit = false;
    VADER_WRITE_BARRIER((vader_struct_vader_parser_Parser_t*) l0);
    l3 = vader_parser_parse_expr(l0, INT32_C(0));
    ((vader_struct_vader_parser_Parser_t*) l0)->f_allow_struct_lit = l2;
    VADER_WRITE_BARRIER((vader_struct_vader_parser_Parser_t*) l0);
    l4 = vader_parser_parse_block(l0);
    l5 = vader_box_obj(0u, NULL);
    vader_parser_skip_newlines(l0);
    t0 = vader_parser_match_kind(l0, (uint8_t) (int32_t) INT32_C(17));
    if (!(t0.tag == 0u)) {
        vader_parser_skip_newlines(l0);
        t1 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(16));
        if (t1) {
            t2 = vader_parser_parse_if_expr(l0);
            vader_struct_toolchain_ast_IfElseIf_t* _a0_obj = (vader_struct_toolchain_ast_IfElseIf_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_IfElseIf_t));
            vader_obj_header_init(_a0_obj, 435u);
            _a0_obj->f_branch = t2;
            t2 = (void*) _a0_obj;
            l5 = vader_ref_box(t2);
        } else {
            t2 = vader_parser_parse_block(l0);
            vader_struct_toolchain_ast_IfElseBlock_t* _a1_obj = (vader_struct_toolchain_ast_IfElseBlock_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_IfElseBlock_t));
            vader_obj_header_init(_a1_obj, 434u);
            _a1_obj->f_block = t2;
            t2 = (void*) _a1_obj;
            l5 = vader_ref_box(t2);
        }
    } else {
    }
    if (l5.tag == 435u) {
        t2 = l5.payload.obj;
        l6 = ((vader_struct_toolchain_ast_IfExpr_t*) ((vader_struct_toolchain_ast_IfElseIf_t*) t2)->f_branch)->f_span;
        l7 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l1)->f_span)->f_start;
        l8 = ((vader_struct_toolchain_span_Span_t*) l6)->f_end;
        vader_struct_toolchain_span_Span_t* _a2_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
        vader_obj_header_init(_a2_obj, 489u);
        _a2_obj->f_start = l7;
        _a2_obj->f_end = l8;
        l9 = (void*) _a2_obj;
        l10 = (size_t) (int64_t) INT64_C(0);
        vader_struct_toolchain_ast_IfExpr_t* _a3_obj = (vader_struct_toolchain_ast_IfExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_IfExpr_t));
        vader_obj_header_init(_a3_obj, 436u);
        _a3_obj->f_span = l9;
        _a3_obj->f_id = l10;
        _a3_obj->f_cond = l3;
        _a3_obj->f_then_block = l4;
        _a3_obj->f_else_branch = l5;
        t2 = (void*) _a3_obj;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l5.tag == 434u) {
        t2 = l5.payload.obj;
        l6 = ((vader_struct_toolchain_ast_BlockExpr_t*) ((vader_struct_toolchain_ast_IfElseBlock_t*) t2)->f_block)->f_span;
        l7 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l1)->f_span)->f_start;
        l8 = ((vader_struct_toolchain_span_Span_t*) l6)->f_end;
        vader_struct_toolchain_span_Span_t* _a4_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
        vader_obj_header_init(_a4_obj, 489u);
        _a4_obj->f_start = l7;
        _a4_obj->f_end = l8;
        l9 = (void*) _a4_obj;
        l10 = (size_t) (int64_t) INT64_C(0);
        vader_struct_toolchain_ast_IfExpr_t* _a5_obj = (vader_struct_toolchain_ast_IfExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_IfExpr_t));
        vader_obj_header_init(_a5_obj, 436u);
        _a5_obj->f_span = l9;
        _a5_obj->f_id = l10;
        _a5_obj->f_cond = l3;
        _a5_obj->f_then_block = l4;
        _a5_obj->f_else_branch = l5;
        t2 = (void*) _a5_obj;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l5.tag == 0u) {
        l6 = ((vader_struct_toolchain_ast_BlockExpr_t*) l4)->f_span;
        l7 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l1)->f_span)->f_start;
        l8 = ((vader_struct_toolchain_span_Span_t*) l6)->f_end;
        vader_struct_toolchain_span_Span_t* _a6_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
        vader_obj_header_init(_a6_obj, 489u);
        _a6_obj->f_start = l7;
        _a6_obj->f_end = l8;
        l9 = (void*) _a6_obj;
        l10 = (size_t) (int64_t) INT64_C(0);
        vader_struct_toolchain_ast_IfExpr_t* _a7_obj = (vader_struct_toolchain_ast_IfExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_IfExpr_t));
        vader_obj_header_init(_a7_obj, 436u);
        _a7_obj->f_span = l9;
        _a7_obj->f_id = l10;
        _a7_obj->f_cond = l3;
        _a7_obj->f_then_block = l4;
        _a7_obj->f_else_branch = l5;
        t2 = (void*) _a7_obj;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_unreachable("unreachable return in vader_parser$parse_if_expr");
    vader_gc_top = gc_frame.prev;
}

void* vader_parser_parse_impl_decl(void* l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    void* l11 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l18 = NULL;
    void* l20 = NULL;
    vader_box_t l3 = vader_box_null(), l14 = vader_box_null();
    bool l7, l13;
    size_t l9, l10;
    int32_t l12;
    vader_string_t l17, l19;
    bool t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_string_t t3;
    int64_t t4;
    vader_box_t* gc_roots[3] = { &l3, &l14, &t1 };
    void** gc_raw_roots[13] = { &l0, &l1, &l2, &l4, &l5, &l6, &l8, &l11, &l15, &l16, &l18, &l20, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 13u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_parser_reject_target_decorator(l0, l1, 1095u);
    l2 = vader_parser_peek(l0);
    l3 = vader_parser_parse_type(l0);
    vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(14), 1040u);
    vader_array_t* _a0_arr = vader_array_new(33u, 0u, 13u, 481u);
    l4 = (void*) _a0_arr;
    t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(49));
    if (t0) {
        l4 = vader_parser_parse_angle_type_params(l0);
    } else {
    }
    l5 = vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(2), 2071u);
    vader_array_t* _a1_arr = vader_array_new(108u, 0u, 13u, 1034u);
    l6 = (void*) _a1_arr;
    t1 = vader_parser_match_kind(l0, (uint8_t) (int32_t) INT32_C(49));
    if (!(t1.tag == 0u)) {
        l6 = vader_parser_parse_type_list_until_angle(l0);
    } else {
    }
    l7 = false;
    l8 = l1;
    vader_array_t* _a2_slotarr = ((vader_array_t*) l8);
    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
    l9 = ((vader_array_t*) l8)->length;
    l10 = (size_t) (int64_t) INT64_C(0);
    {
        loop_53: {
            if ((l10 < l9)) {
                if ((size_t) l10 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l10);
                t3 = ((vader_struct_toolchain_ast_Decorator_t*) t2)->f_name;
                if (t3 == 1625u) {
                    l7 = true;
                } else {
                }
                t4 = (l10 + INT64_C(1));
                l10 = (size_t) (int64_t) t4;
                goto loop_53;
            } else {
            }
        }
    }
    vader_array_t* _a3_arr = vader_array_new(23u, 0u, 13u, 428u);
    l8 = (void*) _a3_arr;
    t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(68));
    if (t0) {
        l11 = vader_parser_parse_sam_arrow_member(l0);
        vader_array_push((vader_array_t*) l8, vader_ref_box(l11));
        l12 = -(INT32_C(1));
        l11 = vader_parser_peek_at(l0, l12);
        l18 = vader_parser_span_of(l0, l2, l11);
        l9 = (size_t) (int64_t) INT64_C(0);
        l19 = ((vader_struct_vader_lexer_Token_t*) l5)->f_text;
        l20 = ((vader_struct_vader_lexer_Token_t*) l5)->f_span;
        vader_struct_toolchain_ast_ImplDecl_t* _a4_obj = (vader_struct_toolchain_ast_ImplDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ImplDecl_t));
        vader_obj_header_init(_a4_obj, 437u);
        _a4_obj->f_span = l18;
        _a4_obj->f_id = l9;
        _a4_obj->f_type_params = l4;
        _a4_obj->f_for_type = l3;
        _a4_obj->f_trait_name = l19;
        _a4_obj->f_trait_name_span = l20;
        _a4_obj->f_trait_args = l6;
        _a4_obj->f_members = l8;
        _a4_obj->f_decorators = l1;
        t2 = (void*) _a4_obj;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(76));
    if (t0) {
        l13 = vader_parser_peek_is_classic_impl_body(l0);
    } else {
        l13 = false;
    }
    if (l13) {
        vader_parser_advance(l0);
        vader_parser_skip_newlines(l0);
        {
            loop_141: {
                t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(77));
                if (!(t0)) {
                    t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(0));
                    l13 = !(t0);
                } else {
                    l13 = false;
                }
                if (l13) {
                    l14 = vader_parser_parse_fn_decl_inside_trait(l0);
                    if (l14.tag == 428u) {
                        l15 = l14.payload.obj;
                        l16 = ((vader_struct_toolchain_ast_FnDecl_t*) l15)->f_decorators;
                        vader_parser_reject_target_decorator(l0, l16, 1098u);
                        vader_array_push((vader_array_t*) l8, vader_ref_box(l15));
                        vader_parser_skip_newlines(l0);
                        goto loop_141;
                    }
                    if (l14.tag == 0u) {
                        vader_parser_skip_newlines(l0);
                        goto loop_141;
                    }
                    vader_unreachable("unreachable return in vader_parser$parse_impl_decl");
                } else {
                }
            }
        }
        l11 = vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(77), 1057u);
        l18 = vader_parser_span_of(l0, l2, l11);
        l9 = (size_t) (int64_t) INT64_C(0);
        l19 = ((vader_struct_vader_lexer_Token_t*) l5)->f_text;
        l20 = ((vader_struct_vader_lexer_Token_t*) l5)->f_span;
        vader_struct_toolchain_ast_ImplDecl_t* _a5_obj = (vader_struct_toolchain_ast_ImplDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ImplDecl_t));
        vader_obj_header_init(_a5_obj, 437u);
        _a5_obj->f_span = l18;
        _a5_obj->f_id = l9;
        _a5_obj->f_type_params = l4;
        _a5_obj->f_for_type = l3;
        _a5_obj->f_trait_name = l19;
        _a5_obj->f_trait_name_span = l20;
        _a5_obj->f_trait_args = l6;
        _a5_obj->f_members = l8;
        _a5_obj->f_decorators = l1;
        t2 = (void*) _a5_obj;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(76));
    if (t0) {
        l15 = vader_parser_parse_sam_block_member(l0);
        vader_array_push((vader_array_t*) l8, vader_ref_box(l15));
        l12 = -(INT32_C(1));
        l11 = vader_parser_peek_at(l0, l12);
    } else {
        if (l7) {
            l12 = -(INT32_C(1));
            l11 = vader_parser_peek_at(l0, l12);
        } else {
            l15 = vader_parser_peek(l0);
            l16 = ((vader_struct_vader_lexer_Token_t*) l15)->f_span;
            l17 = vader_parser_describe_token(l15);
            l17 = concat_3(1398u, l17, 320u);
            vader_parser_error(l0, (uint8_t) (int32_t) INT32_C(5), l16, l17);
            l11 = l15;
        }
    }
    l18 = vader_parser_span_of(l0, l2, l11);
    l9 = (size_t) (int64_t) INT64_C(0);
    l19 = ((vader_struct_vader_lexer_Token_t*) l5)->f_text;
    l20 = ((vader_struct_vader_lexer_Token_t*) l5)->f_span;
    vader_struct_toolchain_ast_ImplDecl_t* _a6_obj = (vader_struct_toolchain_ast_ImplDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ImplDecl_t));
    vader_obj_header_init(_a6_obj, 437u);
    _a6_obj->f_span = l18;
    _a6_obj->f_id = l9;
    _a6_obj->f_type_params = l4;
    _a6_obj->f_for_type = l3;
    _a6_obj->f_trait_name = l19;
    _a6_obj->f_trait_name_span = l20;
    _a6_obj->f_trait_args = l6;
    _a6_obj->f_members = l8;
    _a6_obj->f_decorators = l1;
    t2 = (void*) _a6_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_parser_parse_import_decl(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    int32_t l5;
    vader_string_t l7;
    bool l9;
    bool t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l4, &l6, &l8, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_parser_advance(l0);
    l3 = vader_parser_expect_string_literal(l0, 1591u);
    t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(29));
    if (t0) {
        l4 = vader_parser_peek(l0);
        l4 = ((vader_struct_vader_lexer_Token_t*) l4)->f_span;
        vader_parser_error(l0, (uint8_t) (int32_t) INT32_C(5), l4, 2052u);
        vader_parser_advance(l0);
        t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(2));
        if (t0) {
            vader_parser_advance(l0);
        } else {
        }
    } else {
    }
    t1 = vader_parser_match_kind(l0, (uint8_t) (int32_t) INT32_C(76));
    if (!(t1.tag == 0u)) {
        l4 = vader_parser_parse_import_name_list_rest(l0);
        l5 = -(INT32_C(1));
        l6 = vader_parser_peek_at(l0, l5);
        l6 = vader_parser_span_of(l0, l2, l6);
        l7 = ((vader_struct_vader_parser_StringLitInfo_t*) l3)->f_text;
        l8 = ((vader_struct_vader_parser_CommaList__ImportName_t*) l4)->f_items;
        l9 = ((vader_struct_vader_parser_CommaList__ImportName_t*) l4)->f_trailing_comma;
        vader_struct_toolchain_ast_DestructureImport_t* _a0_obj = (vader_struct_toolchain_ast_DestructureImport_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_DestructureImport_t));
        vader_obj_header_init(_a0_obj, 418u);
        _a0_obj->f_names = l8;
        _a0_obj->f_trailing_comma = l9;
        l4 = (void*) _a0_obj;
        vader_struct_toolchain_ast_ImportDecl_t* _a1_obj = (vader_struct_toolchain_ast_ImportDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ImportDecl_t));
        vader_obj_header_init(_a1_obj, 438u);
        _a1_obj->f_span = l6;
        _a1_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a1_obj->f_path = l7;
        _a1_obj->f_binding = vader_ref_box(l4);
        _a1_obj->f_decorators = l1;
        t2 = (void*) _a1_obj;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = -(INT32_C(1));
    l4 = vader_parser_peek_at(l0, l5);
    l2 = vader_parser_span_of(l0, l2, l4);
    l7 = ((vader_struct_vader_parser_StringLitInfo_t*) l3)->f_text;
    vader_struct_toolchain_ast_WildcardImport_t* _a2_obj = (vader_struct_toolchain_ast_WildcardImport_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_WildcardImport_t));
    vader_obj_header_init(_a2_obj, 485u);
    l3 = (void*) _a2_obj;
    vader_struct_toolchain_ast_ImportDecl_t* _a3_obj = (vader_struct_toolchain_ast_ImportDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ImportDecl_t));
    vader_obj_header_init(_a3_obj, 438u);
    _a3_obj->f_span = l2;
    _a3_obj->f_id = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_path = l7;
    _a3_obj->f_binding = vader_ref_box(l3);
    _a3_obj->f_decorators = l1;
    t2 = (void*) _a3_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_parser_parse_import_name_list_rest(void* l0) {
    void* l1 = NULL;
    void* l7 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l17 = NULL;
    bool l2, l3;
    uint8_t l4, l5, l9, l10;
    vader_string_t l6, l11, l12;
    vader_box_t l8 = vader_box_null();
    int32_t l13;
    size_t l16;
    bool t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_string_t t3;
    vader_box_t* gc_roots[2] = { &l8, &t1 };
    void** gc_raw_roots[7] = { &l0, &l1, &l7, &l14, &l15, &l17, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(25u, 0u, 13u, 439u);
    l1 = (void*) _a0_arr;
    l2 = false;
    vader_parser_skip_newlines(l0);
    t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(77));
    if (!(t0)) {
        l3 = true;
        {
            loop_14: {
                if (!(l3)) {
                    t1 = vader_parser_match_kind(l0, (uint8_t) (int32_t) INT32_C(78));
                    if (t1.tag == 0u) {
                    } else {
                        l3 = false;
                        vader_parser_skip_newlines(l0);
                        l4 = (uint8_t) (int32_t) INT32_C(77);
                        t0 = vader_parser_check(l0, l4);
                        if (t0) {
                            l2 = true;
                        } else {
                            l5 = (uint8_t) (int32_t) INT32_C(2);
                            l6 = 1594u;
                            l7 = vader_parser_expect(l0, l5, l6);
                            l8 = vader_box_obj(0u, NULL);
                            l9 = (uint8_t) (int32_t) INT32_C(29);
                            t1 = vader_parser_match_kind(l0, l9);
                            if (!(t1.tag == 0u)) {
                                l10 = (uint8_t) (int32_t) INT32_C(2);
                                l11 = 1086u;
                                t2 = vader_parser_expect(l0, l10, l11);
                                t3 = ((vader_struct_vader_lexer_Token_t*) t2)->f_text;
                                l8 = vader_box_string(161u, t3);
                            } else {
                            }
                            l12 = ((vader_struct_vader_lexer_Token_t*) l7)->f_text;
                            l13 = -(INT32_C(1));
                            l14 = vader_parser_peek_at(l0, l13);
                            l15 = vader_parser_span_of(l0, l7, l14);
                            l16 = (size_t) (int64_t) INT64_C(0);
                            vader_struct_toolchain_ast_ImportName_t* _a1_obj = (vader_struct_toolchain_ast_ImportName_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ImportName_t));
                            vader_obj_header_init(_a1_obj, 439u);
                            _a1_obj->f_name = l12;
                            _a1_obj->f_alias = l8;
                            _a1_obj->f_span = l15;
                            _a1_obj->f_id = l16;
                            l17 = (void*) _a1_obj;
                            vader_array_push((vader_array_t*) l1, vader_ref_box(l17));
                            vader_parser_skip_newlines(l0);
                            goto loop_14;
                        }
                    }
                } else {
                    l3 = false;
                    vader_parser_skip_newlines(l0);
                    l4 = (uint8_t) (int32_t) INT32_C(77);
                    t0 = vader_parser_check(l0, l4);
                    if (t0) {
                        l2 = true;
                    } else {
                        l5 = (uint8_t) (int32_t) INT32_C(2);
                        l6 = 1594u;
                        l7 = vader_parser_expect(l0, l5, l6);
                        l8 = vader_box_obj(0u, NULL);
                        l9 = (uint8_t) (int32_t) INT32_C(29);
                        t1 = vader_parser_match_kind(l0, l9);
                        if (!(t1.tag == 0u)) {
                            l10 = (uint8_t) (int32_t) INT32_C(2);
                            l11 = 1086u;
                            t2 = vader_parser_expect(l0, l10, l11);
                            t3 = ((vader_struct_vader_lexer_Token_t*) t2)->f_text;
                            l8 = vader_box_string(161u, t3);
                        } else {
                        }
                        l12 = ((vader_struct_vader_lexer_Token_t*) l7)->f_text;
                        l13 = -(INT32_C(1));
                        l14 = vader_parser_peek_at(l0, l13);
                        l15 = vader_parser_span_of(l0, l7, l14);
                        l16 = (size_t) (int64_t) INT64_C(0);
                        vader_struct_toolchain_ast_ImportName_t* _a2_obj = (vader_struct_toolchain_ast_ImportName_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ImportName_t));
                        vader_obj_header_init(_a2_obj, 439u);
                        _a2_obj->f_name = l12;
                        _a2_obj->f_alias = l8;
                        _a2_obj->f_span = l15;
                        _a2_obj->f_id = l16;
                        l17 = (void*) _a2_obj;
                        vader_array_push((vader_array_t*) l1, vader_ref_box(l17));
                        vader_parser_skip_newlines(l0);
                        goto loop_14;
                    }
                }
                goto end_10;
            }
        }
    } else {
    } end_10: ;
    vader_parser_skip_newlines(l0);
    vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(77), 1058u);
    vader_struct_vader_parser_CommaList__Any_t* _a3_obj = (vader_struct_vader_parser_CommaList__Any_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_CommaList__Any_t));
    vader_obj_header_init(_a3_obj, 858u);
    _a3_obj->f_items = l1;
    _a3_obj->f_trailing_comma = l2;
    t2 = (void*) _a3_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_parser_parse_lambda(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    vader_box_t l3 = vader_box_null();
    bool l6;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l3, &t0 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l4, &l5, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_advance(l0);
    l2 = vader_parser_parse_fn_signature_params(l0);
    l3 = vader_box_obj(0u, NULL);
    t0 = vader_parser_match_kind(l0, (uint8_t) (int32_t) INT32_C(68));
    if (!(t0.tag == 0u)) {
        l3 = vader_parser_parse_type(l0);
    } else {
    }
    l4 = vader_parser_parse_block(l0);
    l1 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l1)->f_span)->f_start;
    l5 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_BlockExpr_t*) l4)->f_span)->f_end;
    vader_struct_toolchain_span_Span_t* _a0_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a0_obj, 489u);
    _a0_obj->f_start = l1;
    _a0_obj->f_end = l5;
    l1 = (void*) _a0_obj;
    l5 = ((vader_struct_vader_parser_FnSignature_t*) l2)->f_params;
    l6 = ((vader_struct_vader_parser_FnSignature_t*) l2)->f_trailing_comma;
    vader_struct_toolchain_ast_LambdaExpr_t* _a1_obj = (vader_struct_toolchain_ast_LambdaExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_LambdaExpr_t));
    vader_obj_header_init(_a1_obj, 446u);
    _a1_obj->f_span = l1;
    _a1_obj->f_id = (size_t) (int64_t) INT64_C(0);
    _a1_obj->f_params = l5;
    _a1_obj->f_return_type = l3;
    _a1_obj->f_body = l4;
    _a1_obj->f_trailing_comma = l6;
    t1 = (void*) _a1_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_parser_parse_lambda_without_fn(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    bool l5;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l4, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_peek(l0);
    l2 = vader_parser_parse_fn_signature_params(l0);
    vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(68), 987u);
    t0 = vader_parser_parse_expr(l0, INT32_C(0));
    l3 = vader_parser_wrap_as_block(t0);
    l1 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l1)->f_span)->f_start;
    l4 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_BlockExpr_t*) l3)->f_span)->f_end;
    vader_struct_toolchain_span_Span_t* _a0_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a0_obj, 489u);
    _a0_obj->f_start = l1;
    _a0_obj->f_end = l4;
    l1 = (void*) _a0_obj;
    l4 = ((vader_struct_vader_parser_FnSignature_t*) l2)->f_params;
    l5 = ((vader_struct_vader_parser_FnSignature_t*) l2)->f_trailing_comma;
    vader_struct_toolchain_ast_LambdaExpr_t* _a1_obj = (vader_struct_toolchain_ast_LambdaExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_LambdaExpr_t));
    vader_obj_header_init(_a1_obj, 446u);
    _a1_obj->f_span = l1;
    _a1_obj->f_id = (size_t) (int64_t) INT64_C(0);
    _a1_obj->f_params = l4;
    _a1_obj->f_return_type = vader_box_obj(0u, NULL);
    _a1_obj->f_body = l3;
    _a1_obj->f_trailing_comma = l5;
    t1 = (void*) _a1_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_parser_parse_let(void* l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    void* l6 = NULL;
    bool l2;
    vader_box_t l3 = vader_box_null();
    vader_string_t l5;
    int32_t l7;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[5] = { &l0, &l1, &l4, &l6, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_advance(l0);
    t0 = vader_parser_advance(l0);
    l2 = ((vader_struct_vader_lexer_Token_t*) t0)->f_kind == INT32_C(64);
    l3 = vader_parser_parse_expr(l0, INT32_C(0));
    l4 = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
    l5 = ((vader_struct_vader_lexer_Token_t*) l1)->f_text;
    l6 = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
    vader_struct_toolchain_ast_SimpleBinding_t* _a0_obj = (vader_struct_toolchain_ast_SimpleBinding_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_SimpleBinding_t));
    vader_obj_header_init(_a0_obj, 466u);
    _a0_obj->f_span = l4;
    _a0_obj->f_id = (size_t) (int64_t) INT64_C(0);
    _a0_obj->f_name = l5;
    _a0_obj->f_name_span = l6;
    l4 = (void*) _a0_obj;
    l7 = -(INT32_C(1));
    l6 = vader_parser_peek_at(l0, l7);
    t0 = vader_parser_span_of(l0, l1, l6);
    vader_struct_toolchain_ast_LetStmt_t* _a1_obj = (vader_struct_toolchain_ast_LetStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_LetStmt_t));
    vader_obj_header_init(_a1_obj, 447u);
    _a1_obj->f_span = t0;
    _a1_obj->f_id = (size_t) (int64_t) INT64_C(0);
    _a1_obj->f_mutable = l2;
    _a1_obj->f_binding = vader_ref_box(l4);
    _a1_obj->f_ty = vader_box_obj(0u, NULL);
    _a1_obj->f_value = l3;
    t0 = (void*) _a1_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t vader_parser_parse_let_binding(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    vader_string_t l6;
    vader_box_t l9 = vader_box_null();
    bool l10;
    bool t0;
    vader_box_t t1 = vader_box_null();
    size_t t2;
    void* t3 = NULL;
    vader_string_t t4;
    vader_box_t* gc_roots[2] = { &l9, &t1 };
    void** gc_raw_roots[9] = { &l0, &l1, &l2, &l3, &l4, &l5, &l7, &l8, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 9u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(74));
    if (t0) {
        l1 = vader_parser_advance(l0);
        vader_parser_skip_newlines(l0);
        vader_array_t* _a0_arr = vader_array_new(113u, 0u, 13u, 1073u);
        l2 = (void*) _a0_arr;
        t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(75));
        if (!(t0)) {
            {
                loop_17: {
                    vader_parser_skip_newlines(l0);
                    t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(75));
                    if (t0) {
                    } else {
                        l3 = vader_parser_peek(l0);
                        t1 = vader_parser_match_kind(l0, (uint8_t) (int32_t) INT32_C(67));
                        if (!(t1.tag == 0u)) {
                            l4 = vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(2), 1765u);
                            l5 = vader_parser_span_of(l0, l3, l4);
                            l6 = ((vader_struct_vader_lexer_Token_t*) l4)->f_text;
                            l7 = ((vader_struct_vader_lexer_Token_t*) l4)->f_span;
                            vader_struct_toolchain_ast_RestBinding_t* _a1_obj = (vader_struct_toolchain_ast_RestBinding_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_RestBinding_t));
                            vader_obj_header_init(_a1_obj, 463u);
                            _a1_obj->f_span = l5;
                            _a1_obj->f_id = (size_t) (int64_t) INT64_C(0);
                            _a1_obj->f_name = l6;
                            _a1_obj->f_name_span = l7;
                            l8 = (void*) _a1_obj;
                            vader_array_push((vader_array_t*) l2, vader_ref_box(l8));
                        } else {
                            l9 = vader_parser_parse_let_binding(l0);
                            vader_array_push((vader_array_t*) l2, l9);
                        }
                        vader_parser_skip_newlines(l0);
                        t1 = vader_parser_match_kind(l0, (uint8_t) (int32_t) INT32_C(78));
                        if (t1.tag == 0u) {
                        } else {
                            vader_parser_skip_newlines(l0);
                            goto loop_17;
                        }
                    }
                    goto end_15;
                }
            }
        } else {
        } end_15: ;
        l3 = vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(75), 1027u);
        t2 = ((vader_array_t*) l2)->length;
        if ((t2 < INT64_C(2))) {
            l4 = vader_parser_span_of(l0, l1, l3);
            vader_parser_error(l0, (uint8_t) (int32_t) INT32_C(22), l4, 0u);
        } else {
        }
        t3 = vader_parser_span_of(l0, l1, l3);
        vader_struct_toolchain_ast_TupleBinding_t* _a2_obj = (vader_struct_toolchain_ast_TupleBinding_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_TupleBinding_t));
        vader_obj_header_init(_a2_obj, 478u);
        _a2_obj->f_span = t3;
        _a2_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a2_obj->f_elements = l2;
        t3 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(2));
    if (t0) {
        t3 = vader_parser_peek(l0);
        t4 = ((vader_struct_vader_lexer_Token_t*) t3)->f_text;
        l10 = t4 == 818u;
    } else {
        l10 = false;
    }
    if (l10) {
        t3 = vader_parser_advance(l0);
        vader_struct_toolchain_ast_WildcardBinding_t* _a3_obj = (vader_struct_toolchain_ast_WildcardBinding_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_WildcardBinding_t));
        vader_obj_header_init(_a3_obj, 484u);
        _a3_obj->f_span = ((vader_struct_vader_lexer_Token_t*) t3)->f_span;
        _a3_obj->f_id = (size_t) (int64_t) INT64_C(0);
        t3 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(2), 1169u);
    l2 = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
    l6 = ((vader_struct_vader_lexer_Token_t*) l1)->f_text;
    l1 = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
    vader_struct_toolchain_ast_SimpleBinding_t* _a4_obj = (vader_struct_toolchain_ast_SimpleBinding_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_SimpleBinding_t));
    vader_obj_header_init(_a4_obj, 466u);
    _a4_obj->f_span = l2;
    _a4_obj->f_id = (size_t) (int64_t) INT64_C(0);
    _a4_obj->f_name = l6;
    _a4_obj->f_name_span = l1;
    t3 = (void*) _a4_obj;
    { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_parser_parse_lhs_generic_alias_decl(void* l0, void* l1, uint8_t l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l7 = NULL;
    vader_box_t l5 = vader_box_null();
    int32_t l6;
    vader_string_t l8;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[6] = { &l0, &l1, &l3, &l4, &l7, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_parser_advance(l0);
    l4 = vader_parser_parse_angle_type_params(l0);
    vader_parser_advance(l0);
    l5 = vader_parser_parse_expr(l0, INT32_C(0));
    l6 = -(INT32_C(1));
    l7 = vader_parser_peek_at(l0, l6);
    l7 = vader_parser_span_of(l0, l3, l7);
    l8 = ((vader_struct_vader_lexer_Token_t*) l3)->f_text;
    l3 = ((vader_struct_vader_lexer_Token_t*) l3)->f_span;
    vader_struct_toolchain_ast_TypeAliasDecl_t* _a0_obj = (vader_struct_toolchain_ast_TypeAliasDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_TypeAliasDecl_t));
    vader_obj_header_init(_a0_obj, 480u);
    _a0_obj->f_span = l7;
    _a0_obj->f_id = (size_t) (int64_t) INT64_C(0);
    _a0_obj->f_name = l8;
    _a0_obj->f_name_span = l3;
    _a0_obj->f_visibility = l2;
    _a0_obj->f_type_params = l4;
    _a0_obj->f_aliased = l5;
    _a0_obj->f_decorators = l1;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_parser_parse_match_arm(void* l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    void* l6 = NULL;
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l9 = vader_box_null();
    int32_t l5;
    bool l7, l8;
    bool t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[4] = { &l2, &l3, &l9, &t1 };
    void** gc_raw_roots[5] = { &l0, &l1, &l4, &l6, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_peek(l0);
    l2 = vader_parser_parse_pattern(l0);
    l3 = l2;
    t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(42));
    if (t0) {
        vader_array_t* _a0_arr = vader_array_new(111u, 1u, 13u, 1049u);
        ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l2.payload.obj;
        l4 = (void*) _a0_arr;
        {
            loop_15: {
                t1 = vader_parser_match_kind(l0, (uint8_t) (int32_t) INT32_C(42));
                if (!(t1.tag == 0u)) {
                    vader_parser_skip_newlines(l0);
                    l2 = vader_parser_parse_pattern(l0);
                    vader_array_push((vader_array_t*) l4, l2);
                    goto loop_15;
                } else {
                }
            }
        }
        l5 = -(INT32_C(1));
        l6 = vader_parser_peek_at(l0, l5);
        t2 = vader_parser_span_of(l0, l1, l6);
        vader_struct_toolchain_ast_OrPattern_t* _a1_obj = (vader_struct_toolchain_ast_OrPattern_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_OrPattern_t));
        vader_obj_header_init(_a1_obj, 457u);
        _a1_obj->f_span = t2;
        _a1_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a1_obj->f_patterns = l4;
        t2 = (void*) _a1_obj;
        l3 = vader_ref_box(t2);
    } else {
    }
    l2 = vader_box_obj(0u, NULL);
    t1 = vader_parser_match_kind(l0, (uint8_t) (int32_t) INT32_C(16));
    if (!(t1.tag == 0u)) {
        l7 = ((vader_struct_vader_parser_Parser_t*) l0)->f_allow_struct_lit;
        l8 = ((vader_struct_vader_parser_Parser_t*) l0)->f_allow_bare_lambda;
        ((vader_struct_vader_parser_Parser_t*) l0)->f_allow_struct_lit = false;
        VADER_WRITE_BARRIER((vader_struct_vader_parser_Parser_t*) l0);
        ((vader_struct_vader_parser_Parser_t*) l0)->f_allow_bare_lambda = false;
        VADER_WRITE_BARRIER((vader_struct_vader_parser_Parser_t*) l0);
        l2 = vader_parser_parse_expr(l0, INT32_C(0));
        ((vader_struct_vader_parser_Parser_t*) l0)->f_allow_struct_lit = l7;
        VADER_WRITE_BARRIER((vader_struct_vader_parser_Parser_t*) l0);
        ((vader_struct_vader_parser_Parser_t*) l0)->f_allow_bare_lambda = l8;
        VADER_WRITE_BARRIER((vader_struct_vader_parser_Parser_t*) l0);
    } else {
    }
    vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(68), 988u);
    l9 = vader_parser_parse_expr(l0, INT32_C(0));
    l1 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l1)->f_span)->f_start;
    t2 = l9.payload.obj;
    l4 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t2)->f_span)->f_end;
    vader_struct_toolchain_span_Span_t* _a2_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a2_obj, 489u);
    _a2_obj->f_start = l1;
    _a2_obj->f_end = l4;
    t2 = (void*) _a2_obj;
    vader_struct_toolchain_ast_MatchArm_t* _a3_obj = (vader_struct_toolchain_ast_MatchArm_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_MatchArm_t));
    vader_obj_header_init(_a3_obj, 449u);
    _a3_obj->f_span = t2;
    _a3_obj->f_id = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_pattern = l3;
    _a3_obj->f_guard = l2;
    _a3_obj->f_body = l9;
    t2 = (void*) _a3_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_parser_parse_match_expr(void* l0, bool l1, bool l2) {
    void* l3 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    bool l4;
    vader_box_t l5 = vader_box_null();
    bool t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[2] = { &l5, &t1 };
    void** gc_raw_roots[5] = { &l0, &l3, &l6, &l7, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_parser_advance(l0);
    l4 = ((vader_struct_vader_parser_Parser_t*) l0)->f_allow_struct_lit;
    ((vader_struct_vader_parser_Parser_t*) l0)->f_allow_struct_lit = false;
    VADER_WRITE_BARRIER((vader_struct_vader_parser_Parser_t*) l0);
    l5 = vader_parser_parse_expr(l0, INT32_C(0));
    ((vader_struct_vader_parser_Parser_t*) l0)->f_allow_struct_lit = l4;
    VADER_WRITE_BARRIER((vader_struct_vader_parser_Parser_t*) l0);
    vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(76), 1051u);
    vader_parser_skip_newlines(l0);
    vader_array_t* _a0_arr = vader_array_new(27u, 0u, 13u, 449u);
    l6 = (void*) _a0_arr;
    {
        loop_26: {
            t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(77));
            if (!(t0)) {
                t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(0));
                l4 = !(t0);
            } else {
                l4 = false;
            }
            if (l4) {
                l7 = vader_parser_parse_match_arm(l0);
                vader_array_push((vader_array_t*) l6, vader_ref_box(l7));
                vader_parser_skip_newlines(l0);
                t1 = vader_parser_match_kind(l0, (uint8_t) (int32_t) INT32_C(78));
                if (!(t1.tag == 0u)) {
                    vader_parser_skip_newlines(l0);
                } else {
                }
                goto loop_26;
            } else {
            }
        }
    }
    l7 = vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(77), 1059u);
    l3 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l3)->f_span)->f_start;
    l7 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l7)->f_span)->f_end;
    vader_struct_toolchain_span_Span_t* _a1_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a1_obj, 489u);
    _a1_obj->f_start = l3;
    _a1_obj->f_end = l7;
    t2 = (void*) _a1_obj;
    vader_struct_toolchain_ast_MatchExpr_t* _a2_obj = (vader_struct_toolchain_ast_MatchExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_MatchExpr_t));
    vader_obj_header_init(_a2_obj, 450u);
    _a2_obj->f_span = t2;
    _a2_obj->f_id = (size_t) (int64_t) INT64_C(0);
    _a2_obj->f_scrutinee = l5;
    _a2_obj->f_arms = l6;
    _a2_obj->f_partial = l1;
    _a2_obj->f_unreachable = l2;
    t2 = (void*) _a2_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t vader_parser_parse_module_header(vader_string_t l0, vader_string_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l6, l12, l15, l16;
    bool l5, l8, l9, l10, l11, l13, l14;
    uint8_t l7;
    vader_string_t l17;
    vader_box_t t0 = vader_box_null();
    uint8_t t1;
    int64_t t2;
    void* t3 = NULL;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l2, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_import_3(l0);
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    if ((l3 >= INT64_C(3))) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
        if ((size_t) INT32_C(0) >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
        t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) INT32_C(0), 166u);
        t1 = ((uint8_t) t0.payload.i);
        l5 = t1 == INT32_C(239);
    } else {
        l5 = false;
    }
    if (l5) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
        if ((size_t) INT32_C(1) >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
        t0 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) INT32_C(1), 166u);
        t1 = ((uint8_t) t0.payload.i);
        l5 = t1 == INT32_C(187);
    } else {
        l5 = false;
    }
    if (l5) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
        if ((size_t) INT32_C(2) >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
        t0 = vader_array_read_u8(_a2_slotarr, _a2_slotarr->offset + (size_t) INT32_C(2), 166u);
        t1 = ((uint8_t) t0.payload.i);
        l5 = t1 == INT32_C(191);
    } else {
        l5 = false;
    }
    if (l5) {
        l4 = (size_t) (int64_t) INT64_C(3);
    } else {
    }
    if (((l4 + INT64_C(1)) < l3)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
        if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
        if ((size_t) l4 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
        t0 = vader_array_read_u8(_a3_slotarr, _a3_slotarr->offset + (size_t) l4, 166u);
        t1 = ((uint8_t) t0.payload.i);
        l5 = t1 == INT32_C(35);
    } else {
        l5 = false;
    }
    if (l5) {
        t2 = (l4 + INT64_C(1));
        l6 = (size_t) (int64_t) t2;
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
        if ((size_t) l6 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
        t0 = vader_array_read_u8(_a4_slotarr, _a4_slotarr->offset + (size_t) l6, 166u);
        t1 = ((uint8_t) t0.payload.i);
        l5 = t1 == INT32_C(33);
    } else {
        l5 = false;
    }
    if (l5) {
        l4 = vader_parser_skip_to_eol(l2, l4, l3);
    } else {
    }
    l6 = vader_parser_header_budget(l3);
    {
        loop_101: {
            if ((l4 < l6)) {
                vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
                if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                if ((size_t) l4 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_read_u8(_a5_slotarr, _a5_slotarr->offset + (size_t) l4, 166u);
                l7 = ((uint8_t) t0.payload.i);
                if (l7 == INT32_C(32)) {
                    l5 = true;
                } else {
                    l5 = l7 == INT32_C(9);
                }
                if (l5) {
                    l8 = true;
                } else {
                    l8 = l7 == INT32_C(10);
                }
                if (l8) {
                    l9 = true;
                } else {
                    l9 = l7 == INT32_C(13);
                }
                if (l9) {
                    t2 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t2;
                    goto loop_101;
                }
                if (l7 == INT32_C(47)) {
                    l10 = ((l4 + INT64_C(1)) < l3);
                } else {
                    l10 = false;
                }
                if (l10) {
                    t2 = (l4 + INT64_C(1));
                    l12 = (size_t) (int64_t) t2;
                    vader_array_t* _a6_slotarr = ((vader_array_t*) l2);
                    if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                    if ((size_t) l12 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = vader_array_read_u8(_a6_slotarr, _a6_slotarr->offset + (size_t) l12, 166u);
                    t1 = ((uint8_t) t0.payload.i);
                    l11 = t1 == INT32_C(47);
                } else {
                    l11 = false;
                }
                if (l11) {
                    l4 = vader_parser_skip_to_eol(l2, l4, l3);
                    goto loop_101;
                }
                if (l7 == INT32_C(47)) {
                    l13 = ((l4 + INT64_C(1)) < l3);
                } else {
                    l13 = false;
                }
                if (l13) {
                    t2 = (l4 + INT64_C(1));
                    l15 = (size_t) (int64_t) t2;
                    vader_array_t* _a7_slotarr = ((vader_array_t*) l2);
                    if (_a7_slotarr->buf != NULL && _a7_slotarr->buf->header.forward != NULL) { _a7_slotarr->buf = vader_array_buf_forward(_a7_slotarr->buf); }
                    if ((size_t) l15 >= _a7_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = vader_array_read_u8(_a7_slotarr, _a7_slotarr->offset + (size_t) l15, 166u);
                    t1 = ((uint8_t) t0.payload.i);
                    l14 = t1 == INT32_C(42);
                } else {
                    l14 = false;
                }
                if (l14) {
                    t2 = (l4 + INT64_C(2));
                    l16 = (size_t) (int64_t) t2;
                    l4 = vader_parser_skip_block_comment(l2, l16, l3);
                    goto loop_101;
                }
            } else {
            }
        }
    }
    if (((l4 + INT64_C(7)) > l3)) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a8_slotarr = ((vader_array_t*) l2);
    if (_a8_slotarr->buf != NULL && _a8_slotarr->buf->header.forward != NULL) { _a8_slotarr->buf = vader_array_buf_forward(_a8_slotarr->buf); }
    if ((size_t) l4 >= _a8_slotarr->length) { vader_trap("array index out of bounds"); }
    t0 = vader_array_read_u8(_a8_slotarr, _a8_slotarr->offset + (size_t) l4, 166u);
    t1 = ((uint8_t) t0.payload.i);
    if (t1 != INT32_C(109)) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = (l4 + INT64_C(1));
    l6 = (size_t) (int64_t) t2;
    vader_array_t* _a9_slotarr = ((vader_array_t*) l2);
    if (_a9_slotarr->buf != NULL && _a9_slotarr->buf->header.forward != NULL) { _a9_slotarr->buf = vader_array_buf_forward(_a9_slotarr->buf); }
    if ((size_t) l6 >= _a9_slotarr->length) { vader_trap("array index out of bounds"); }
    t0 = vader_array_read_u8(_a9_slotarr, _a9_slotarr->offset + (size_t) l6, 166u);
    t1 = ((uint8_t) t0.payload.i);
    if (t1 != INT32_C(111)) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = (l4 + INT64_C(2));
    l6 = (size_t) (int64_t) t2;
    vader_array_t* _a10_slotarr = ((vader_array_t*) l2);
    if (_a10_slotarr->buf != NULL && _a10_slotarr->buf->header.forward != NULL) { _a10_slotarr->buf = vader_array_buf_forward(_a10_slotarr->buf); }
    if ((size_t) l6 >= _a10_slotarr->length) { vader_trap("array index out of bounds"); }
    t0 = vader_array_read_u8(_a10_slotarr, _a10_slotarr->offset + (size_t) l6, 166u);
    t1 = ((uint8_t) t0.payload.i);
    if (t1 != INT32_C(100)) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = (l4 + INT64_C(3));
    l6 = (size_t) (int64_t) t2;
    vader_array_t* _a11_slotarr = ((vader_array_t*) l2);
    if (_a11_slotarr->buf != NULL && _a11_slotarr->buf->header.forward != NULL) { _a11_slotarr->buf = vader_array_buf_forward(_a11_slotarr->buf); }
    if ((size_t) l6 >= _a11_slotarr->length) { vader_trap("array index out of bounds"); }
    t0 = vader_array_read_u8(_a11_slotarr, _a11_slotarr->offset + (size_t) l6, 166u);
    t1 = ((uint8_t) t0.payload.i);
    if (t1 != INT32_C(117)) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = (l4 + INT64_C(4));
    l6 = (size_t) (int64_t) t2;
    vader_array_t* _a12_slotarr = ((vader_array_t*) l2);
    if (_a12_slotarr->buf != NULL && _a12_slotarr->buf->header.forward != NULL) { _a12_slotarr->buf = vader_array_buf_forward(_a12_slotarr->buf); }
    if ((size_t) l6 >= _a12_slotarr->length) { vader_trap("array index out of bounds"); }
    t0 = vader_array_read_u8(_a12_slotarr, _a12_slotarr->offset + (size_t) l6, 166u);
    t1 = ((uint8_t) t0.payload.i);
    if (t1 != INT32_C(108)) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = (l4 + INT64_C(5));
    l6 = (size_t) (int64_t) t2;
    vader_array_t* _a13_slotarr = ((vader_array_t*) l2);
    if (_a13_slotarr->buf != NULL && _a13_slotarr->buf->header.forward != NULL) { _a13_slotarr->buf = vader_array_buf_forward(_a13_slotarr->buf); }
    if ((size_t) l6 >= _a13_slotarr->length) { vader_trap("array index out of bounds"); }
    t0 = vader_array_read_u8(_a13_slotarr, _a13_slotarr->offset + (size_t) l6, 166u);
    t1 = ((uint8_t) t0.payload.i);
    if (t1 != INT32_C(101)) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = (l4 + INT64_C(6));
    l4 = (size_t) (int64_t) t2;
    {
        loop_339: {
            if ((l4 < l3)) {
                vader_array_t* _a14_slotarr = ((vader_array_t*) l2);
                if (_a14_slotarr->buf != NULL && _a14_slotarr->buf->header.forward != NULL) { _a14_slotarr->buf = vader_array_buf_forward(_a14_slotarr->buf); }
                if ((size_t) l4 >= _a14_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_read_u8(_a14_slotarr, _a14_slotarr->offset + (size_t) l4, 166u);
                l7 = ((uint8_t) t0.payload.i);
                if (l7 == INT32_C(32)) {
                    l5 = true;
                } else {
                    l5 = l7 == INT32_C(9);
                }
                if (l5) {
                    t2 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t2;
                    goto loop_339;
                }
            } else {
            }
        }
    }
    if ((l4 >= l3)) {
        l5 = true;
    } else {
        vader_array_t* _a15_slotarr = ((vader_array_t*) l2);
        if (_a15_slotarr->buf != NULL && _a15_slotarr->buf->header.forward != NULL) { _a15_slotarr->buf = vader_array_buf_forward(_a15_slotarr->buf); }
        if ((size_t) l4 >= _a15_slotarr->length) { vader_trap("array index out of bounds"); }
        t0 = vader_array_read_u8(_a15_slotarr, _a15_slotarr->offset + (size_t) l4, 166u);
        t1 = ((uint8_t) t0.payload.i);
        l5 = t1 != INT32_C(34);
    }
    if (l5) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = (l4 + INT64_C(1));
    l4 = (size_t) (int64_t) t2;
    l6 = l4;
    {
        loop_399: {
            if ((l4 < l3)) {
                vader_array_t* _a16_slotarr = ((vader_array_t*) l2);
                if (_a16_slotarr->buf != NULL && _a16_slotarr->buf->header.forward != NULL) { _a16_slotarr->buf = vader_array_buf_forward(_a16_slotarr->buf); }
                if ((size_t) l4 >= _a16_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_read_u8(_a16_slotarr, _a16_slotarr->offset + (size_t) l4, 166u);
                t1 = ((uint8_t) t0.payload.i);
                l5 = t1 != INT32_C(34);
            } else {
                l5 = false;
            }
            if (l5) {
                t2 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                goto loop_399;
            } else {
            }
        }
    }
    if ((l4 >= l3)) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a17_arr = vader_array_slice((vader_array_t*) l2, (size_t) l6, (size_t) l4);
    t3 = (void*) _a17_arr;
    l17 = vader_import_2(t3);
    l2 = vader_lexer_empty_file_span(l1);
    vader_struct_vader_parser_ModuleHeader_t* _a18_obj = (vader_struct_vader_parser_ModuleHeader_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_ModuleHeader_t));
    vader_obj_header_init(_a18_obj, 868u);
    _a18_obj->f_name = l17;
    _a18_obj->f_name_span = l2;
    t3 = (void*) _a18_obj;
    { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t vader_parser_parse_named_decl(void* l0, void* l1, uint8_t l2) {
    void* l3 = NULL;
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_parser_advance(l0);
    vader_parser_advance(l0);
    t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(11));
    if (t0) {
        t1 = vader_parser_parse_fn_decl(l0, l1, l2, l3);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(12));
    if (t0) {
        t1 = vader_parser_parse_struct_decl(l0, l1, l2, l3);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(15));
    if (t0) {
        t1 = vader_parser_parse_enum_decl(l0, l1, l2, l3);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(13));
    if (t0) {
        t1 = vader_parser_parse_trait_decl(l0, l1, l2, l3);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(28));
    if (t0) {
        t1 = vader_parser_parse_named_import_decl(l0, l1, l3);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_parser_parse_const_decl(l0, l1, l2, l3);
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_parser_parse_named_import_decl(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l5 = NULL;
    vader_box_t l4 = vader_box_null();
    int32_t l6;
    vader_string_t l7;
    void* t0 = NULL;
    vader_string_t t1;
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_parser_advance(l0);
    l3 = vader_parser_expect_string_literal(l0, 1591u);
    l4 = vader_parser_match_kind(l0, (uint8_t) (int32_t) INT32_C(76));
    if (!(l4.tag == 0u)) {
        t0 = l4.payload.obj;
        l5 = ((vader_struct_vader_lexer_Token_t*) t0)->f_span;
        vader_parser_error(l0, (uint8_t) (int32_t) INT32_C(5), l5, 2055u);
        vader_parser_parse_import_name_list_rest(l0);
    } else {
    }
    l6 = -(INT32_C(1));
    l5 = vader_parser_peek_at(l0, l6);
    l5 = vader_parser_span_of(l0, l2, l5);
    l7 = ((vader_struct_vader_parser_StringLitInfo_t*) l3)->f_text;
    t1 = ((vader_struct_vader_lexer_Token_t*) l2)->f_text;
    vader_struct_toolchain_ast_NamedNamespaceImport_t* _a0_obj = (vader_struct_toolchain_ast_NamedNamespaceImport_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_NamedNamespaceImport_t));
    vader_obj_header_init(_a0_obj, 453u);
    _a0_obj->f_name = t1;
    l3 = (void*) _a0_obj;
    vader_struct_toolchain_ast_ImportDecl_t* _a1_obj = (vader_struct_toolchain_ast_ImportDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ImportDecl_t));
    vader_obj_header_init(_a1_obj, 438u);
    _a1_obj->f_span = l5;
    _a1_obj->f_id = (size_t) (int64_t) INT64_C(0);
    _a1_obj->f_path = l7;
    _a1_obj->f_binding = vader_ref_box(l3);
    _a1_obj->f_decorators = l1;
    t0 = (void*) _a1_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t vader_parser_parse_optional_module_decl(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    int32_t l4;
    vader_string_t l5;
    vader_box_t t0 = vader_box_null();
    vader_string_t t1;
    bool t2;
    void* t3 = NULL;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_peek(l0);
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind != INT32_C(2)) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = ((vader_struct_vader_lexer_Token_t*) l1)->f_text;
    if (t1 != 1755u) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_parser_check_at(l0, (uint8_t) (int32_t) INT32_C(6), INT32_C(1));
    if (!(t2)) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = vader_parser_advance(l0);
    l2 = vader_parser_expect_string_literal(l0, 1760u);
    t1 = ((vader_struct_vader_parser_StringLitInfo_t*) l2)->f_text;
    t2 = vader_parser_is_valid_module_name(t1);
    if (!(t2)) {
        l3 = ((vader_struct_vader_parser_StringLitInfo_t*) l2)->f_span;
        vader_parser_error(l0, (uint8_t) (int32_t) INT32_C(24), l3, 0u);
    } else {
    }
    l4 = -(INT32_C(1));
    l3 = vader_parser_peek_at(l0, l4);
    l1 = vader_parser_span_of(l0, l1, l3);
    l5 = ((vader_struct_vader_parser_StringLitInfo_t*) l2)->f_text;
    l2 = ((vader_struct_vader_parser_StringLitInfo_t*) l2)->f_span;
    vader_struct_toolchain_ast_ModuleDecl_t* _a0_obj = (vader_struct_toolchain_ast_ModuleDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ModuleDecl_t));
    vader_obj_header_init(_a0_obj, 451u);
    _a0_obj->f_span = l1;
    _a0_obj->f_id = (size_t) (int64_t) INT64_C(0);
    _a0_obj->f_name = l5;
    _a0_obj->f_name_span = l2;
    t3 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t vader_parser_parse_paren(void* l0) {
    bool l1, l2;
    vader_box_t l3 = vader_box_null();
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_parser_advance(l0);
    vader_parser_skip_newlines(l0);
    l1 = ((vader_struct_vader_parser_Parser_t*) l0)->f_allow_struct_lit;
    l2 = ((vader_struct_vader_parser_Parser_t*) l0)->f_allow_bare_lambda;
    ((vader_struct_vader_parser_Parser_t*) l0)->f_allow_struct_lit = true;
    VADER_WRITE_BARRIER((vader_struct_vader_parser_Parser_t*) l0);
    ((vader_struct_vader_parser_Parser_t*) l0)->f_allow_bare_lambda = true;
    VADER_WRITE_BARRIER((vader_struct_vader_parser_Parser_t*) l0);
    l3 = vader_parser_parse_expr(l0, INT32_C(0));
    ((vader_struct_vader_parser_Parser_t*) l0)->f_allow_struct_lit = l1;
    VADER_WRITE_BARRIER((vader_struct_vader_parser_Parser_t*) l0);
    ((vader_struct_vader_parser_Parser_t*) l0)->f_allow_bare_lambda = l2;
    VADER_WRITE_BARRIER((vader_struct_vader_parser_Parser_t*) l0);
    vader_parser_skip_newlines(l0);
    vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(73), 982u);
    { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t vader_parser_parse_pattern(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    vader_string_t l5;
    vader_box_t l6 = vader_box_null(), l7 = vader_box_null(), l8 = vader_box_null();
    int32_t l9;
    bool l10;
    void* t0 = NULL;
    bool t1;
    vader_box_t t2 = vader_box_null();
    vader_string_t t3;
    vader_box_t* gc_roots[4] = { &l6, &l7, &l8, &t2 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_peek(l0);
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(79)) {
        vader_parser_advance(l0);
        l2 = vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(2), 2287u);
        l3 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l1)->f_span)->f_start;
        l4 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l2)->f_span)->f_end;
        vader_struct_toolchain_span_Span_t* _a0_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
        vader_obj_header_init(_a0_obj, 489u);
        _a0_obj->f_start = l3;
        _a0_obj->f_end = l4;
        l3 = (void*) _a0_obj;
        l5 = ((vader_struct_vader_lexer_Token_t*) l2)->f_text;
        vader_struct_toolchain_ast_EnumVariantPattern_t* _a1_obj = (vader_struct_toolchain_ast_EnumVariantPattern_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_EnumVariantPattern_t));
        vader_obj_header_init(_a1_obj, 424u);
        _a1_obj->f_span = l3;
        _a1_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a1_obj->f_variant = l5;
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(19)) {
        vader_parser_advance(l0);
        t1 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(79));
        if (t1) {
            l2 = vader_parser_advance(l0);
            l3 = vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(2), 2287u);
            l2 = vader_parser_span_of(l0, l2, l3);
            l5 = ((vader_struct_vader_lexer_Token_t*) l3)->f_text;
            vader_struct_toolchain_ast_IdentExpr_t* _a2_obj = (vader_struct_toolchain_ast_IdentExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_IdentExpr_t));
            vader_obj_header_init(_a2_obj, 433u);
            _a2_obj->f_span = l2;
            _a2_obj->f_id = (size_t) (int64_t) INT64_C(0);
            _a2_obj->f_name = l5;
            _a2_obj->f_implicit_dot = true;
            _a2_obj->f_is_type_param_intro = false;
            t0 = (void*) _a2_obj;
            l6 = vader_ref_box(t0);
        } else {
            l6 = vader_parser_parse_type(l0);
        }
        l7 = vader_box_obj(0u, NULL);
        t1 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(76));
        if (t1) {
            t0 = vader_parser_parse_struct_pattern(l0);
            l7 = vader_ref_box(t0);
        } else {
        }
        l8 = vader_box_obj(0u, NULL);
        t2 = vader_parser_match_kind(l0, (uint8_t) (int32_t) INT32_C(29));
        if (!(t2.tag == 0u)) {
            t0 = vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(2), 1168u);
            t3 = ((vader_struct_vader_lexer_Token_t*) t0)->f_text;
            l8 = vader_box_string(161u, t3);
        } else {
        }
        l9 = -(INT32_C(1));
        l2 = vader_parser_peek_at(l0, l9);
        t0 = vader_parser_span_of(l0, l1, l2);
        vader_struct_toolchain_ast_IsPattern_t* _a3_obj = (vader_struct_toolchain_ast_IsPattern_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_IsPattern_t));
        vader_obj_header_init(_a3_obj, 445u);
        _a3_obj->f_span = t0;
        _a3_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a3_obj->f_ty = l6;
        _a3_obj->f_inner = l7;
        _a3_obj->f_bind_as = l8;
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(2)) {
        t3 = ((vader_struct_vader_lexer_Token_t*) l1)->f_text;
        l10 = t3 == 818u;
    } else {
        l10 = false;
    }
    if (l10) {
        vader_parser_advance(l0);
        vader_struct_toolchain_ast_WildcardPattern_t* _a4_obj = (vader_struct_toolchain_ast_WildcardPattern_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_WildcardPattern_t));
        vader_obj_header_init(_a4_obj, 486u);
        _a4_obj->f_span = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
        _a4_obj->f_id = (size_t) (int64_t) INT64_C(0);
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(2)) {
        vader_parser_advance(l0);
        l2 = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
        l5 = ((vader_struct_vader_lexer_Token_t*) l1)->f_text;
        vader_struct_toolchain_ast_BindingPattern_t* _a5_obj = (vader_struct_toolchain_ast_BindingPattern_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BindingPattern_t));
        vader_obj_header_init(_a5_obj, 404u);
        _a5_obj->f_span = l2;
        _a5_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a5_obj->f_name = l5;
        t0 = (void*) _a5_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(74)) {
        t0 = vader_parser_parse_tuple_pattern(l0);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_parser_is_literal_start(l1);
    if (t1) {
        l6 = vader_parser_parse_prefix(l0);
        t1 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(66));
        if (t1) {
            l10 = true;
        } else {
            l10 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(65));
        }
        if (l10) {
            l10 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(66));
            vader_parser_advance(l0);
            l7 = vader_parser_parse_prefix(l0);
            l9 = -(INT32_C(1));
            l2 = vader_parser_peek_at(l0, l9);
            t0 = vader_parser_span_of(l0, l1, l2);
            vader_struct_toolchain_ast_RangePattern_t* _a6_obj = (vader_struct_toolchain_ast_RangePattern_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_RangePattern_t));
            vader_obj_header_init(_a6_obj, 462u);
            _a6_obj->f_span = t0;
            _a6_obj->f_id = (size_t) (int64_t) INT64_C(0);
            _a6_obj->f_inclusive = l10;
            _a6_obj->f_lower = l6;
            _a6_obj->f_upper = l7;
            t0 = (void*) _a6_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l9 = -(INT32_C(1));
        l2 = vader_parser_peek_at(l0, l9);
        t0 = vader_parser_span_of(l0, l1, l2);
        vader_struct_toolchain_ast_LiteralPattern_t* _a7_obj = (vader_struct_toolchain_ast_LiteralPattern_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_LiteralPattern_t));
        vader_obj_header_init(_a7_obj, 448u);
        _a7_obj->f_span = t0;
        _a7_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a7_obj->f_value = l6;
        t0 = (void*) _a7_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
    l5 = vader_parser_describe_token(l1);
    l5 = concat_2(1516u, l5);
    vader_parser_error(l0, (uint8_t) (int32_t) INT32_C(6), l2, l5);
    vader_parser_advance(l0);
    vader_struct_toolchain_ast_WildcardPattern_t* _a8_obj = (vader_struct_toolchain_ast_WildcardPattern_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_WildcardPattern_t));
    vader_obj_header_init(_a8_obj, 486u);
    _a8_obj->f_span = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
    _a8_obj->f_id = (size_t) (int64_t) INT64_C(0);
    t0 = (void*) _a8_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t vader_parser_parse_postfix(void* l0, vader_box_t l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l9 = NULL;
    vader_string_t l6;
    bool l7;
    int32_t l8;
    vader_box_t l10 = vader_box_null();
    bool t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l10 };
    void** gc_raw_roots[7] = { &l0, &l2, &l3, &l4, &l5, &l9, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (((vader_struct_vader_lexer_Token_t*) l2)->f_kind == INT32_C(79)) {
        vader_parser_advance(l0);
        t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(3));
        if (t0) {
            l3 = vader_parser_advance(l0);
            t1 = l1.payload.obj;
            l4 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_span)->f_start;
            l5 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l3)->f_span)->f_end;
            vader_struct_toolchain_span_Span_t* _a0_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
            vader_obj_header_init(_a0_obj, 489u);
            _a0_obj->f_start = l4;
            _a0_obj->f_end = l5;
            l4 = (void*) _a0_obj;
            l6 = ((vader_struct_vader_lexer_Token_t*) l3)->f_text;
            l3 = ((vader_struct_vader_lexer_Token_t*) l3)->f_span;
            vader_struct_toolchain_ast_FieldExpr_t* _a1_obj = (vader_struct_toolchain_ast_FieldExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FieldExpr_t));
            vader_obj_header_init(_a1_obj, 426u);
            _a1_obj->f_span = l4;
            _a1_obj->f_id = (size_t) (int64_t) INT64_C(0);
            _a1_obj->f_target = l1;
            _a1_obj->f_field = l6;
            _a1_obj->f_field_span = l3;
            _a1_obj->f_is_numeric = true;
            t1 = (void*) _a1_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l3 = vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(2), 1461u);
        t1 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_span)->f_start;
        l5 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l3)->f_span)->f_end;
        vader_struct_toolchain_span_Span_t* _a2_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
        vader_obj_header_init(_a2_obj, 489u);
        _a2_obj->f_start = l4;
        _a2_obj->f_end = l5;
        l4 = (void*) _a2_obj;
        l6 = ((vader_struct_vader_lexer_Token_t*) l3)->f_text;
        l3 = ((vader_struct_vader_lexer_Token_t*) l3)->f_span;
        vader_struct_toolchain_ast_FieldExpr_t* _a3_obj = (vader_struct_toolchain_ast_FieldExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FieldExpr_t));
        vader_obj_header_init(_a3_obj, 426u);
        _a3_obj->f_span = l4;
        _a3_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a3_obj->f_target = l1;
        _a3_obj->f_field = l6;
        _a3_obj->f_field_span = l3;
        _a3_obj->f_is_numeric = false;
        l3 = (void*) _a3_obj;
        t0 = ((vader_struct_vader_parser_Parser_t*) l0)->f_allow_struct_lit;
        if (t0) {
            l7 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(76));
        } else {
            l7 = false;
        }
        if (l7) {
            l4 = ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens;
            l8 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pos;
            l7 = vader_parser_looks_like_struct_lit_body(l4, l8);
        } else {
            l7 = false;
        }
        if (l7) {
            vader_parser_advance(l0);
            l4 = vader_parser_parse_struct_lit_fields(l0);
            l5 = vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(77), 1061u);
            t1 = l1.payload.obj;
            l9 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_span)->f_start;
            l5 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l5)->f_span)->f_end;
            vader_struct_toolchain_span_Span_t* _a4_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
            vader_obj_header_init(_a4_obj, 489u);
            _a4_obj->f_start = l9;
            _a4_obj->f_end = l5;
            l5 = (void*) _a4_obj;
            l9 = ((vader_struct_vader_parser_CommaList__StructLitField___StructLitSpread_t*) l4)->f_items;
            l7 = ((vader_struct_vader_parser_CommaList__StructLitField___StructLitSpread_t*) l4)->f_trailing_comma;
            vader_struct_toolchain_ast_StructLitExpr_t* _a5_obj = (vader_struct_toolchain_ast_StructLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_StructLitExpr_t));
            vader_obj_header_init(_a5_obj, 472u);
            _a5_obj->f_span = l5;
            _a5_obj->f_id = (size_t) (int64_t) INT64_C(0);
            _a5_obj->f_type_name = vader_ref_box(l3);
            _a5_obj->f_items = l9;
            _a5_obj->f_trailing_comma = l7;
            t1 = (void*) _a5_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_box_t __vret = vader_ref_box(l3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l2)->f_kind == INT32_C(72)) {
        vader_parser_advance(l0);
        l3 = vader_parser_parse_call_args(l0);
        vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(73), 980u);
        t1 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_span)->f_start;
        l8 = -(INT32_C(1));
        t1 = vader_parser_peek_at(l0, l8);
        l5 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) t1)->f_span)->f_end;
        vader_struct_toolchain_span_Span_t* _a6_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
        vader_obj_header_init(_a6_obj, 489u);
        _a6_obj->f_start = l4;
        _a6_obj->f_end = l5;
        l4 = (void*) _a6_obj;
        l5 = ((vader_struct_vader_parser_CommaList__CallArg_t*) l3)->f_items;
        l7 = ((vader_struct_vader_parser_CommaList__CallArg_t*) l3)->f_trailing_comma;
        vader_struct_toolchain_ast_CallExpr_t* _a7_obj = (vader_struct_toolchain_ast_CallExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_CallExpr_t));
        vader_obj_header_init(_a7_obj, 409u);
        _a7_obj->f_span = l4;
        _a7_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a7_obj->f_callee = l1;
        _a7_obj->f_args = l5;
        _a7_obj->f_trailing_comma = l7;
        t1 = (void*) _a7_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_parser_check_at(l0, (uint8_t) (int32_t) INT32_C(75), INT32_C(1));
    if (t0) {
        vader_parser_advance(l0);
        l3 = vader_parser_advance(l0);
        t1 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_span)->f_start;
        l3 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l3)->f_span)->f_end;
        vader_struct_toolchain_span_Span_t* _a8_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
        vader_obj_header_init(_a8_obj, 489u);
        _a8_obj->f_start = l4;
        _a8_obj->f_end = l3;
        t1 = (void*) _a8_obj;
        vader_struct_toolchain_ast_ArrayTypeExpr_t* _a9_obj = (vader_struct_toolchain_ast_ArrayTypeExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ArrayTypeExpr_t));
        vader_obj_header_init(_a9_obj, 399u);
        _a9_obj->f_span = t1;
        _a9_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a9_obj->f_element = l1;
        t1 = (void*) _a9_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_parser_advance(l0);
    l10 = vader_parser_parse_expr(l0, INT32_C(0));
    vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(75), 1028u);
    t1 = l1.payload.obj;
    l3 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_span)->f_start;
    l8 = -(INT32_C(1));
    t1 = vader_parser_peek_at(l0, l8);
    l4 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) t1)->f_span)->f_end;
    vader_struct_toolchain_span_Span_t* _a10_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a10_obj, 489u);
    _a10_obj->f_start = l3;
    _a10_obj->f_end = l4;
    t1 = (void*) _a10_obj;
    vader_struct_toolchain_ast_IndexExpr_t* _a11_obj = (vader_struct_toolchain_ast_IndexExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_IndexExpr_t));
    vader_obj_header_init(_a11_obj, 441u);
    _a11_obj->f_span = t1;
    _a11_obj->f_id = (size_t) (int64_t) INT64_C(0);
    _a11_obj->f_target = l1;
    _a11_obj->f_index = l10;
    t1 = (void*) _a11_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t vader_parser_parse_prefix(void* l0) {
    void* l1 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l13 = NULL;
    void* l18 = NULL;
    uint64_t l2;
    vader_box_t l3 = vader_box_null(), l17 = vader_box_null();
    double l4;
    uint32_t l5;
    bool l6, l12, l16;
    uint8_t l7;
    vader_string_t l11;
    size_t l14, l15;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    bool t2;
    vader_string_t t3;
    vader_box_t* gc_roots[3] = { &l3, &l17, &t1 };
    void** gc_raw_roots[8] = { &l0, &l1, &l8, &l9, &l10, &l13, &l18, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 8u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_peek(l0);
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(3)) {
        vader_parser_advance(l0);
        l2 = (uint64_t) (int64_t) INT64_C(0);
        l3 = ((vader_struct_vader_lexer_Token_t*) l1)->f_value;
        if (l3.tag == 168u) {
            l2 = ((uint64_t) l3.payload.i);
        } else {
        }
        vader_struct_toolchain_ast_IntLitExpr_t* _a0_obj = (vader_struct_toolchain_ast_IntLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_IntLitExpr_t));
        vader_obj_header_init(_a0_obj, 443u);
        _a0_obj->f_span = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
        _a0_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a0_obj->f_value = l2;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(4)) {
        vader_parser_advance(l0);
        l4 = 0.0;
        l3 = ((vader_struct_vader_lexer_Token_t*) l1)->f_value;
        if ((l3.tag == 157u || l3.tag == 158u)) {
            l4 = ((double) l3.payload.f);
        } else {
        }
        vader_struct_toolchain_ast_FloatLitExpr_t* _a1_obj = (vader_struct_toolchain_ast_FloatLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FloatLitExpr_t));
        vader_obj_header_init(_a1_obj, 427u);
        _a1_obj->f_span = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
        _a1_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a1_obj->f_value = l4;
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(5)) {
        vader_parser_advance(l0);
        l5 = (uint32_t) (int32_t) INT32_C(0);
        l3 = ((vader_struct_vader_lexer_Token_t*) l1)->f_value;
        if (l3.tag == 167u) {
            l5 = ((uint32_t) l3.payload.i);
        } else {
        }
        vader_struct_toolchain_ast_CharLitExpr_t* _a2_obj = (vader_struct_toolchain_ast_CharLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_CharLitExpr_t));
        vader_obj_header_init(_a2_obj, 411u);
        _a2_obj->f_span = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
        _a2_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a2_obj->f_value = l5;
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(31)) {
        vader_parser_advance(l0);
        vader_struct_toolchain_ast_BoolLitExpr_t* _a3_obj = (vader_struct_toolchain_ast_BoolLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BoolLitExpr_t));
        vader_obj_header_init(_a3_obj, 406u);
        _a3_obj->f_span = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
        _a3_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a3_obj->f_value = true;
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(32)) {
        vader_parser_advance(l0);
        vader_struct_toolchain_ast_BoolLitExpr_t* _a4_obj = (vader_struct_toolchain_ast_BoolLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BoolLitExpr_t));
        vader_obj_header_init(_a4_obj, 406u);
        _a4_obj->f_span = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
        _a4_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a4_obj->f_value = false;
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(33)) {
        vader_parser_advance(l0);
        vader_struct_toolchain_ast_NullLitExpr_t* _a5_obj = (vader_struct_toolchain_ast_NullLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_NullLitExpr_t));
        vader_obj_header_init(_a5_obj, 456u);
        _a5_obj->f_span = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
        _a5_obj->f_id = (size_t) (int64_t) INT64_C(0);
        t0 = (void*) _a5_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(6)) {
        t0 = vader_parser_parse_string_lit(l0);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(2)) {
        t1 = vader_parser_parse_ident_or_struct_lit(l0);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(72)) {
        t2 = ((vader_struct_vader_parser_Parser_t*) l0)->f_allow_bare_lambda;
        if (t2) {
            l6 = vader_parser_peek_lambda_without_fn(l0);
        } else {
            l6 = false;
        }
        if (l6) {
            t0 = vader_parser_parse_lambda_without_fn(l0);
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t1 = vader_parser_parse_paren(l0);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(74)) {
        t0 = vader_parser_parse_seq_lit(l0);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(76)) {
        t0 = vader_parser_parse_block(l0);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(37)) {
        l6 = true;
    } else {
        l6 = ((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(55);
    }
    if (l6) {
        l6 = true;
    } else {
        l6 = ((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(44);
    }
    if (l6) {
        vader_parser_advance(l0);
        l7 = (uint8_t) (int32_t) INT32_C(0);
        if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(55)) {
            l7 = (uint8_t) (int32_t) INT32_C(1);
        } else {
        }
        if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(44)) {
            l7 = (uint8_t) (int32_t) INT32_C(2);
        } else {
        }
        l3 = vader_parser_parse_expr(l0, INT32_C(95));
        l8 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l1)->f_span)->f_start;
        t0 = l3.payload.obj;
        l9 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t0)->f_span)->f_end;
        vader_struct_toolchain_span_Span_t* _a6_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
        vader_obj_header_init(_a6_obj, 489u);
        _a6_obj->f_start = l8;
        _a6_obj->f_end = l9;
        t0 = (void*) _a6_obj;
        vader_struct_toolchain_ast_UnaryExpr_t* _a7_obj = (vader_struct_toolchain_ast_UnaryExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_UnaryExpr_t));
        vader_obj_header_init(_a7_obj, 482u);
        _a7_obj->f_span = t0;
        _a7_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a7_obj->f_op = l7;
        _a7_obj->f_operand = l3;
        t0 = (void*) _a7_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(24)) {
        vader_parser_advance(l0);
        l3 = vader_parser_parse_expr(l0, INT32_C(95));
        l8 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l1)->f_span)->f_start;
        t0 = l3.payload.obj;
        l9 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t0)->f_span)->f_end;
        vader_struct_toolchain_span_Span_t* _a8_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
        vader_obj_header_init(_a8_obj, 489u);
        _a8_obj->f_start = l8;
        _a8_obj->f_end = l9;
        t0 = (void*) _a8_obj;
        vader_struct_toolchain_ast_AwaitExpr_t* _a9_obj = (vader_struct_toolchain_ast_AwaitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_AwaitExpr_t));
        vader_obj_header_init(_a9_obj, 402u);
        _a9_obj->f_span = t0;
        _a9_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a9_obj->f_inner = l3;
        t0 = (void*) _a9_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(16)) {
        t0 = vader_parser_parse_if_expr(l0);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(18)) {
        t0 = vader_parser_parse_match_expr(l0, false, false);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(11)) {
        t0 = vader_parser_parse_lambda(l0);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(34)) {
        vader_parser_advance(l0);
        t0 = vader_parser_ident_expr(((vader_struct_vader_lexer_Token_t*) l1)->f_span, 1872u);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(70)) {
        l8 = vader_parser_advance(l0);
        l9 = vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(2), 1337u);
        t3 = ((vader_struct_vader_lexer_Token_t*) l9)->f_text;
        if (t3 == 1811u) {
            l6 = true;
        } else {
            t3 = ((vader_struct_vader_lexer_Token_t*) l9)->f_text;
            l6 = t3 == 2184u;
        }
        if (l6) {
            t2 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(18));
            if (!(t2)) {
                l10 = ((vader_struct_vader_lexer_Token_t*) l9)->f_span;
                l11 = ((vader_struct_vader_lexer_Token_t*) l9)->f_text;
                l11 = concat_3(1005u, l11, 933u);
                vader_parser_error(l0, (uint8_t) (int32_t) INT32_C(13), l10, l11);
            } else {
            }
            t3 = ((vader_struct_vader_lexer_Token_t*) l9)->f_text;
            l6 = t3 == 1811u;
            t3 = ((vader_struct_vader_lexer_Token_t*) l9)->f_text;
            l12 = t3 == 2184u;
            t0 = vader_parser_parse_match_expr(l0, l6, l12);
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t3 = ((vader_struct_vader_lexer_Token_t*) l9)->f_text;
        l3 = vader_parser_intrinsic_spec(t3);
        if (l3.tag == 0u) {
            l10 = vader_parser_span_of(l0, l8, l9);
            l11 = ((vader_struct_vader_lexer_Token_t*) l9)->f_text;
            l11 = concat_3(1005u, l11, 922u);
            vader_parser_error(l0, (uint8_t) (int32_t) INT32_C(13), l10, l11);
            t2 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(72));
            if (t2) {
                vader_parser_advance(l0);
                {
                    loop_398: {
                        t2 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(73));
                        if (!(t2)) {
                            t2 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(0));
                            l6 = !(t2);
                        } else {
                            l6 = false;
                        }
                        if (l6) {
                            vader_parser_advance(l0);
                            goto loop_398;
                        } else {
                        }
                    }
                }
                t2 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(73));
                if (t2) {
                    vader_parser_advance(l0);
                } else {
                }
            } else {
            }
            t0 = vader_parser_span_of(l0, l8, l9);
            vader_struct_toolchain_ast_NullLitExpr_t* _a10_obj = (vader_struct_toolchain_ast_NullLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_NullLitExpr_t));
            vader_obj_header_init(_a10_obj, 456u);
            _a10_obj->f_span = t0;
            _a10_obj->f_id = (size_t) (int64_t) INT64_C(0);
            t0 = (void*) _a10_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l3.tag == 867u) {
            l10 = l3.payload.obj;
            l11 = ((vader_struct_vader_parser_IntrinsicSpec_t*) l10)->f_name;
            l11 = concat_3(970u, l11, 872u);
            vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(72), l11);
            vader_array_t* _a11_arr = vader_array_new(108u, 0u, 13u, 1034u);
            l13 = (void*) _a11_arr;
            vader_parser_skip_newlines(l0);
            l6 = false;
            t2 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(73));
            if (!(t2)) {
                {
                    loop_473: {
                        vader_parser_skip_newlines(l0);
                        t2 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(73));
                        if (t2) {
                        } else {
                            l14 = ((vader_array_t*) l13)->length;
                            l12 = false;
                            l15 = ((vader_array_t*) ((vader_struct_vader_parser_IntrinsicSpec_t*) l10)->f_args)->length;
                            if ((l14 < l15)) {
                                vader_array_t* _a12_slotarr = ((vader_array_t*) ((vader_struct_vader_parser_IntrinsicSpec_t*) l10)->f_args);
                                if (_a12_slotarr->buf != NULL && _a12_slotarr->buf->header.forward != NULL) { _a12_slotarr->buf = vader_array_buf_forward(_a12_slotarr->buf); }
                                if ((size_t) l14 >= _a12_slotarr->length) { vader_trap("array index out of bounds"); }
                                t1 = vader_array_read_u8(_a12_slotarr, _a12_slotarr->offset + (size_t) l14, 166u);
                                l16 = ((int32_t) t1.payload.i) == INT32_C(0);
                            } else {
                                l16 = false;
                            }
                            if (l16) {
                                l12 = true;
                            } else {
                            }
                            if (l12) {
                                l3 = vader_parser_parse_type(l0);
                                vader_array_push((vader_array_t*) l13, l3);
                            } else {
                                l17 = vader_parser_parse_expr(l0, INT32_C(0));
                                vader_array_push((vader_array_t*) l13, l17);
                            }
                            vader_parser_skip_newlines(l0);
                            t1 = vader_parser_match_kind(l0, (uint8_t) (int32_t) INT32_C(78));
                            if (t1.tag == 0u) {
                            } else {
                                vader_parser_skip_newlines(l0);
                                l6 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(73));
                                goto loop_473;
                            }
                        }
                        goto end_471;
                    }
                }
            } else {
            } end_471: ;
            l11 = ((vader_struct_vader_parser_IntrinsicSpec_t*) l10)->f_name;
            l11 = concat_3(979u, l11, 307u);
            l18 = vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(73), l11);
            l8 = vader_parser_span_of(l0, l8, l18);
            l11 = ((vader_struct_vader_parser_IntrinsicSpec_t*) l10)->f_name;
            l9 = ((vader_struct_vader_lexer_Token_t*) l9)->f_span;
            vader_struct_toolchain_ast_IntrinsicCallExpr_t* _a13_obj = (vader_struct_toolchain_ast_IntrinsicCallExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_IntrinsicCallExpr_t));
            vader_obj_header_init(_a13_obj, 444u);
            _a13_obj->f_span = l8;
            _a13_obj->f_id = (size_t) (int64_t) INT64_C(0);
            _a13_obj->f_name = l11;
            _a13_obj->f_name_span = l9;
            _a13_obj->f_args = l13;
            _a13_obj->f_trailing_comma = l6;
            t0 = (void*) _a13_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_unreachable("unreachable return in vader_parser$parse_prefix");
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(79)) {
        vader_parser_advance(l0);
        l8 = vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(2), 2287u);
        l9 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l1)->f_span)->f_start;
        l10 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l8)->f_span)->f_end;
        vader_struct_toolchain_span_Span_t* _a14_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
        vader_obj_header_init(_a14_obj, 489u);
        _a14_obj->f_start = l9;
        _a14_obj->f_end = l10;
        l9 = (void*) _a14_obj;
        l11 = ((vader_struct_vader_lexer_Token_t*) l8)->f_text;
        l8 = ((vader_struct_vader_lexer_Token_t*) l8)->f_span;
        vader_struct_toolchain_ast_DotVariantExpr_t* _a15_obj = (vader_struct_toolchain_ast_DotVariantExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_DotVariantExpr_t));
        vader_obj_header_init(_a15_obj, 421u);
        _a15_obj->f_span = l9;
        _a15_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a15_obj->f_variant = l11;
        _a15_obj->f_variant_span = l8;
        t0 = (void*) _a15_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l8 = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
    l11 = vader_parser_describe_token(l1);
    l11 = concat_2(1516u, l11);
    vader_parser_error(l0, (uint8_t) (int32_t) INT32_C(2), l8, l11);
    vader_parser_advance(l0);
    vader_struct_toolchain_ast_NullLitExpr_t* _a16_obj = (vader_struct_toolchain_ast_NullLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_NullLitExpr_t));
    vader_obj_header_init(_a16_obj, 456u);
    _a16_obj->f_span = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
    _a16_obj->f_id = (size_t) (int64_t) INT64_C(0);
    t0 = (void*) _a16_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_parser_parse_program(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l5 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null(), l8 = vader_box_null();
    size_t l6, l7;
    vader_string_t l19;
    bool t0;
    size_t t1;
    int64_t t2;
    void* t3 = NULL;
    vader_box_t* gc_roots[3] = { &l3, &l4, &l8 };
    void** gc_raw_roots[15] = { &l0, &l1, &l2, &l5, &l9, &l10, &l11, &l12, &l13, &l14, &l15, &l16, &l17, &l18, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 15u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_peek(l0);
    vader_array_t* _a0_arr = vader_array_new(109u, 0u, 13u, 1042u);
    l2 = (void*) _a0_arr;
    vader_parser_skip_newlines(l0);
    l3 = vader_parser_parse_optional_module_decl(l0);
    vader_parser_skip_newlines(l0);
    {
        loop_13: {
            t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(0));
            if (!(t0)) {
                l4 = vader_parser_parse_decl(l0);
                t1 = ((vader_array_t*) ((vader_struct_vader_parser_Parser_t*) l0)->f_pending_decls)->length;
                if ((t1 > INT64_C(0))) {
                    l5 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pending_decls;
                    l6 = ((vader_array_t*) l5)->length;
                    l7 = (size_t) (int64_t) INT64_C(0);
                    {
                        loop_34: {
                            if ((l7 < l6)) {
                                vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
                                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                                if ((size_t) l7 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                                l8 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l7);
                                vader_array_push((vader_array_t*) l2, l8);
                                t2 = (l7 + INT64_C(1));
                                l7 = (size_t) (int64_t) t2;
                                goto loop_34;
                            } else {
                            }
                        }
                    }
                    vader_array_t* _a2_arr = vader_array_new(109u, 0u, 13u, 1042u);
                    l9 = (void*) _a2_arr;
                    ((vader_struct_vader_parser_Parser_t*) l0)->f_pending_decls = l9;
                    VADER_WRITE_BARRIER((vader_struct_vader_parser_Parser_t*) l0);
                } else {
                }
                if (l4.tag == 0u) {
                    vader_parser_advance(l0);
                    vader_parser_skip_newlines(l0);
                    goto loop_13;
                }
                if (l4.tag == 438u) {
                    l10 = l4.payload.obj;
                    vader_array_push((vader_array_t*) l2, vader_ref_box(l10));
                    vader_parser_skip_newlines(l0);
                    goto loop_13;
                }
                if (l4.tag == 428u) {
                    l11 = l4.payload.obj;
                    vader_array_push((vader_array_t*) l2, vader_ref_box(l11));
                    vader_parser_skip_newlines(l0);
                    goto loop_13;
                }
                if (l4.tag == 470u) {
                    l12 = l4.payload.obj;
                    vader_array_push((vader_array_t*) l2, vader_ref_box(l12));
                    vader_parser_skip_newlines(l0);
                    goto loop_13;
                }
                if (l4.tag == 422u) {
                    l13 = l4.payload.obj;
                    vader_array_push((vader_array_t*) l2, vader_ref_box(l13));
                    vader_parser_skip_newlines(l0);
                    goto loop_13;
                }
                if (l4.tag == 477u) {
                    l14 = l4.payload.obj;
                    vader_array_push((vader_array_t*) l2, vader_ref_box(l14));
                    vader_parser_skip_newlines(l0);
                    goto loop_13;
                }
                if (l4.tag == 437u) {
                    l15 = l4.payload.obj;
                    vader_array_push((vader_array_t*) l2, vader_ref_box(l15));
                    vader_parser_skip_newlines(l0);
                    goto loop_13;
                }
                if (l4.tag == 480u) {
                    l16 = l4.payload.obj;
                    vader_array_push((vader_array_t*) l2, vader_ref_box(l16));
                    vader_parser_skip_newlines(l0);
                    goto loop_13;
                }
                if (l4.tag == 412u) {
                    l17 = l4.payload.obj;
                    vader_array_push((vader_array_t*) l2, vader_ref_box(l17));
                    vader_parser_skip_newlines(l0);
                    goto loop_13;
                }
                if (l4.tag == 400u) {
                    l18 = l4.payload.obj;
                    vader_array_push((vader_array_t*) l2, vader_ref_box(l18));
                    vader_parser_skip_newlines(l0);
                    goto loop_13;
                }
                vader_unreachable("unreachable return in vader_parser$parse_program");
            } else {
            }
        }
    }
    l5 = vader_parser_peek(l0);
    l19 = ((vader_struct_vader_parser_Parser_t*) l0)->f_file;
    l1 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l1)->f_span)->f_start;
    l5 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l5)->f_span)->f_end;
    vader_struct_toolchain_span_Span_t* _a3_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a3_obj, 489u);
    _a3_obj->f_start = l1;
    _a3_obj->f_end = l5;
    l1 = (void*) _a3_obj;
    vader_struct_toolchain_ast_Program_t* _a4_obj = (vader_struct_toolchain_ast_Program_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_Program_t));
    vader_obj_header_init(_a4_obj, 460u);
    _a4_obj->f_file = l19;
    _a4_obj->f_span = l1;
    _a4_obj->f_id = (size_t) (int64_t) INT64_C(0);
    _a4_obj->f_module = l3;
    _a4_obj->f_decls = l2;
    t3 = (void*) _a4_obj;
    { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_parser_parse_return(void* l0) {
    void* l1 = NULL;
    void* l5 = NULL;
    vader_box_t l2 = vader_box_null();
    bool l3;
    int32_t l4;
    bool t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[4] = { &l0, &l1, &l5, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_advance(l0);
    l2 = vader_box_obj(0u, NULL);
    t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(1));
    if (!(t0)) {
        t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(77));
        l3 = !(t0);
    } else {
        l3 = false;
    }
    if (l3) {
        t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(0));
        l3 = !(t0);
    } else {
        l3 = false;
    }
    if (l3) {
        l2 = vader_parser_parse_expr(l0, INT32_C(0));
    } else {
    }
    l4 = -(INT32_C(1));
    l5 = vader_parser_peek_at(l0, l4);
    t1 = vader_parser_span_of(l0, l1, l5);
    vader_struct_toolchain_ast_ReturnStmt_t* _a0_obj = (vader_struct_toolchain_ast_ReturnStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ReturnStmt_t));
    vader_obj_header_init(_a0_obj, 464u);
    _a0_obj->f_span = t1;
    _a0_obj->f_id = (size_t) (int64_t) INT64_C(0);
    _a0_obj->f_value = l2;
    t1 = (void*) _a0_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_parser_parse_sam_arrow_member(void* l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    vader_box_t l2 = vader_box_null();
    int32_t l3;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[8] = { &l0, &l1, &l4, &l5, &l6, &l7, &l8, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(68), 989u);
    l2 = vader_parser_parse_expr(l0, INT32_C(0));
    l3 = -(INT32_C(1));
    l4 = vader_parser_peek_at(l0, l3);
    l4 = vader_parser_span_of(l0, l1, l4);
    vader_array_t* _a0_arr = vader_array_new(110u, 0u, 13u, 1047u);
    l5 = (void*) _a0_arr;
    vader_struct_toolchain_ast_BlockExpr_t* _a1_obj = (vader_struct_toolchain_ast_BlockExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BlockExpr_t));
    vader_obj_header_init(_a1_obj, 405u);
    _a1_obj->f_span = l4;
    _a1_obj->f_id = (size_t) (int64_t) INT64_C(0);
    _a1_obj->f_stmts = l5;
    _a1_obj->f_trailing = l2;
    l5 = (void*) _a1_obj;
    l1 = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
    vader_array_t* _a2_arr = vader_array_new(33u, 0u, 13u, 481u);
    l6 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(24u, 0u, 13u, 429u);
    l7 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(21u, 0u, 13u, 414u);
    l8 = (void*) _a4_arr;
    vader_struct_toolchain_ast_FnDecl_t* _a5_obj = (vader_struct_toolchain_ast_FnDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FnDecl_t));
    vader_obj_header_init(_a5_obj, 428u);
    _a5_obj->f_span = l4;
    _a5_obj->f_id = (size_t) (int64_t) INT64_C(0);
    _a5_obj->f_name = 0u;
    _a5_obj->f_name_span = l1;
    _a5_obj->f_visibility = (uint8_t) (int32_t) INT32_C(0);
    _a5_obj->f_type_params = l6;
    _a5_obj->f_params = l7;
    _a5_obj->f_return_type = vader_box_obj(0u, NULL);
    _a5_obj->f_body = vader_ref_box(l5);
    _a5_obj->f_decorators = l8;
    _a5_obj->f_sam_synthetic = true;
    _a5_obj->f_is_expression_bodied = false;
    _a5_obj->f_materialized = false;
    _a5_obj->f_comptime_synthetic = false;
    _a5_obj->f_trailing_comma = false;
    t0 = (void*) _a5_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_parser_parse_sam_block_member(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 8u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_parse_block(l0);
    l2 = ((vader_struct_toolchain_ast_BlockExpr_t*) l1)->f_span;
    l3 = ((vader_struct_toolchain_ast_BlockExpr_t*) l1)->f_span;
    vader_array_t* _a0_arr = vader_array_new(33u, 0u, 13u, 481u);
    l4 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(24u, 0u, 13u, 429u);
    l5 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(21u, 0u, 13u, 414u);
    l6 = (void*) _a2_arr;
    vader_struct_toolchain_ast_FnDecl_t* _a3_obj = (vader_struct_toolchain_ast_FnDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FnDecl_t));
    vader_obj_header_init(_a3_obj, 428u);
    _a3_obj->f_span = l2;
    _a3_obj->f_id = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_name = 0u;
    _a3_obj->f_name_span = l3;
    _a3_obj->f_visibility = (uint8_t) (int32_t) INT32_C(0);
    _a3_obj->f_type_params = l4;
    _a3_obj->f_params = l5;
    _a3_obj->f_return_type = vader_box_obj(0u, NULL);
    _a3_obj->f_body = vader_ref_box(l1);
    _a3_obj->f_decorators = l6;
    _a3_obj->f_sam_synthetic = true;
    _a3_obj->f_is_expression_bodied = false;
    _a3_obj->f_materialized = false;
    _a3_obj->f_comptime_synthetic = false;
    _a3_obj->f_trailing_comma = false;
    t0 = (void*) _a3_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_parser_parse_seq_lit(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l5 = NULL;
    bool l3;
    vader_box_t l4 = vader_box_null();
    bool t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[2] = { &l4, &t1 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l5, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_advance(l0);
    vader_array_t* _a0_arr = vader_array_new(108u, 0u, 13u, 1034u);
    l2 = (void*) _a0_arr;
    l3 = false;
    vader_parser_skip_newlines(l0);
    t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(75));
    if (!(t0)) {
        {
            loop_15: {
                vader_parser_skip_newlines(l0);
                t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(75));
                if (t0) {
                } else {
                    l4 = vader_parser_parse_expr(l0, INT32_C(0));
                    vader_array_push((vader_array_t*) l2, l4);
                    vader_parser_skip_newlines(l0);
                    t1 = vader_parser_match_kind(l0, (uint8_t) (int32_t) INT32_C(78));
                    if (t1.tag == 0u) {
                    } else {
                        vader_parser_skip_newlines(l0);
                        l3 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(75));
                        goto loop_15;
                    }
                }
                goto end_13;
            }
        }
    } else {
    } end_13: ;
    l5 = vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(75), 1029u);
    t2 = vader_parser_span_of(l0, l1, l5);
    vader_struct_toolchain_ast_SeqLitExpr_t* _a1_obj = (vader_struct_toolchain_ast_SeqLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_SeqLitExpr_t));
    vader_obj_header_init(_a1_obj, 465u);
    _a1_obj->f_span = t2;
    _a1_obj->f_id = (size_t) (int64_t) INT64_C(0);
    _a1_obj->f_elements = l2;
    _a1_obj->f_trailing_comma = l3;
    t2 = (void*) _a1_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_parser_parse_single_param_lambda_tail(void* l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    vader_string_t l3;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l4, &l5, &l6, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_parser_advance(l0);
    l2 = ((vader_struct_toolchain_ast_IdentExpr_t*) l1)->f_span;
    l3 = ((vader_struct_toolchain_ast_IdentExpr_t*) l1)->f_name;
    vader_struct_toolchain_ast_FnParam_t* _a0_obj = (vader_struct_toolchain_ast_FnParam_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FnParam_t));
    vader_obj_header_init(_a0_obj, 429u);
    _a0_obj->f_span = l2;
    _a0_obj->f_id = (size_t) (int64_t) INT64_C(0);
    _a0_obj->f_name = l3;
    _a0_obj->f_ty = vader_box_obj(0u, NULL);
    _a0_obj->f_default_value = vader_box_obj(0u, NULL);
    _a0_obj->f_variadic = false;
    _a0_obj->f_mutable = false;
    l2 = (void*) _a0_obj;
    t0 = vader_parser_parse_expr(l0, INT32_C(0));
    l4 = vader_parser_wrap_as_block(t0);
    l5 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_IdentExpr_t*) l1)->f_span)->f_start;
    l6 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_BlockExpr_t*) l4)->f_span)->f_end;
    vader_struct_toolchain_span_Span_t* _a1_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a1_obj, 489u);
    _a1_obj->f_start = l5;
    _a1_obj->f_end = l6;
    l5 = (void*) _a1_obj;
    vader_array_t* _a2_arr = vader_array_new(24u, 1u, 13u, 429u);
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = l2;
    l2 = (void*) _a2_arr;
    vader_struct_toolchain_ast_LambdaExpr_t* _a3_obj = (vader_struct_toolchain_ast_LambdaExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_LambdaExpr_t));
    vader_obj_header_init(_a3_obj, 446u);
    _a3_obj->f_span = l5;
    _a3_obj->f_id = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_params = l2;
    _a3_obj->f_return_type = vader_box_obj(0u, NULL);
    _a3_obj->f_body = l4;
    _a3_obj->f_trailing_comma = false;
    t1 = (void*) _a3_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_parser_parse_source(vader_string_t l0, vader_string_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l7 = NULL;
    size_t l5, l6;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[5] = { &l2, &l3, &l4, &l7, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_lexer_tokenize(l0, l1);
    l3 = vader_parser_new_parser(((vader_struct_vader_lexer_Lexer_t*) l2)->f_tokens, l1);
    l4 = ((vader_struct_vader_lexer_Lexer_t*) l2)->f_errors;
    l5 = ((vader_array_t*) l4)->length;
    l6 = (size_t) (int64_t) INT64_C(0);
    {
        loop_15: {
            if ((l6 < l5)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l6 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l7 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
                vader_array_push((vader_array_t*) ((vader_struct_vader_parser_Parser_t*) l3)->f_errors, vader_ref_box(l7));
                t0 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t0;
                goto loop_15;
            } else {
            }
        }
    }
    l4 = vader_parser_parse_program(l3);
    l7 = vader_parser_new_node_id_factory();
    vader_parser_assign_program_ids(l4, l7);
    l2 = ((vader_struct_vader_lexer_Lexer_t*) l2)->f_tokens;
    l3 = ((vader_struct_vader_parser_Parser_t*) l3)->f_errors;
    vader_struct_vader_parser_ParsedSource_t* _a1_obj = (vader_struct_vader_parser_ParsedSource_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_ParsedSource_t));
    vader_obj_header_init(_a1_obj, 870u);
    _a1_obj->f_program = l4;
    _a1_obj->f_tokens = l2;
    _a1_obj->f_errors = l3;
    _a1_obj->f_id_factory = l7;
    t1 = (void*) _a1_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t vader_parser_parse_stmt(void* l0) {
    bool l1, l4;
    void* l2 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    vader_string_t l3;
    vader_box_t l5 = vader_box_null(), l6 = vader_box_null();
    int32_t l7;
    uint8_t l10;
    bool t0;
    void* t1 = NULL;
    vader_string_t t2;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l5, &l6, &t3 };
    void** gc_raw_roots[5] = { &l0, &l2, &l8, &l9, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(22));
    if (t0) {
        t1 = vader_parser_parse_return(l0);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(23));
    if (t0) {
        t1 = vader_parser_parse_yield(l0);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(20));
    if (t0) {
        t1 = vader_parser_parse_for(l0, vader_box_obj(0u, NULL), false);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(70));
    if (t0) {
        t1 = vader_parser_peek_at(l0, INT32_C(1));
        l1 = ((vader_struct_vader_lexer_Token_t*) t1)->f_kind == INT32_C(2);
    } else {
        l1 = false;
    }
    if (l1) {
        t1 = vader_parser_peek_at(l0, INT32_C(1));
        t2 = ((vader_struct_vader_lexer_Token_t*) t1)->f_text;
        l1 = t2 == 1285u;
    } else {
        l1 = false;
    }
    if (l1) {
        l1 = vader_parser_check_at(l0, (uint8_t) (int32_t) INT32_C(20), INT32_C(2));
    } else {
        l1 = false;
    }
    if (l1) {
        vader_parser_advance(l0);
        vader_parser_advance(l0);
        t1 = vader_parser_parse_for(l0, vader_box_obj(0u, NULL), true);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(26));
    if (t0) {
        t1 = vader_parser_parse_break(l0);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(27));
    if (t0) {
        t1 = vader_parser_parse_continue(l0);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(25));
    if (t0) {
        t1 = vader_parser_parse_defer(l0);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(2));
    if (t0) {
        l1 = vader_parser_check_at(l0, (uint8_t) (int32_t) INT32_C(80), INT32_C(1));
    } else {
        l1 = false;
    }
    if (l1) {
        l1 = vader_parser_check_at(l0, (uint8_t) (int32_t) INT32_C(20), INT32_C(2));
    } else {
        l1 = false;
    }
    if (l1) {
        l2 = vader_parser_advance(l0);
        vader_parser_advance(l0);
        l3 = ((vader_struct_vader_lexer_Token_t*) l2)->f_text;
        t1 = vader_parser_parse_for(l0, vader_box_string(161u, l3), false);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(74));
    if (t0) {
        l1 = vader_parser_peek_tuple_let_start(l0);
    } else {
        l1 = false;
    }
    if (l1) {
        t1 = vader_parser_parse_tuple_let(l0);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(2));
    if (t0) {
        t0 = vader_parser_check_at(l0, (uint8_t) (int32_t) INT32_C(63), INT32_C(1));
        if (t0) {
            l4 = true;
        } else {
            l4 = vader_parser_check_at(l0, (uint8_t) (int32_t) INT32_C(64), INT32_C(1));
        }
        l1 = l4;
    } else {
        l1 = false;
    }
    if (l1) {
        t1 = vader_parser_parse_let(l0);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(2));
    if (t0) {
        l1 = vader_parser_check_at(l0, (uint8_t) (int32_t) INT32_C(80), INT32_C(1));
    } else {
        l1 = false;
    }
    if (l1) {
        t1 = vader_parser_parse_typed_let(l0);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = vader_parser_peek(l0);
    l5 = vader_parser_parse_expr(l0, INT32_C(0));
    t3 = vader_parser_match_kind(l0, (uint8_t) (int32_t) INT32_C(57));
    if (!(t3.tag == 0u)) {
        l6 = vader_parser_parse_expr(l0, INT32_C(0));
        l7 = -(INT32_C(1));
        l8 = vader_parser_peek_at(l0, l7);
        t1 = vader_parser_span_of(l0, l2, l8);
        vader_struct_toolchain_ast_AssignStmt_t* _a0_obj = (vader_struct_toolchain_ast_AssignStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_AssignStmt_t));
        vader_obj_header_init(_a0_obj, 401u);
        _a0_obj->f_span = t1;
        _a0_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a0_obj->f_target = l5;
        _a0_obj->f_value = l6;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_parser_peek(l0);
    l8 = vader_parser_compound_op(((vader_struct_vader_lexer_Token_t*) t1)->f_kind);
    t0 = ((vader_struct_vader_parser_CompoundOpResult_t*) l8)->f_matched;
    if (t0) {
        vader_parser_advance(l0);
        l6 = vader_parser_parse_expr(l0, INT32_C(0));
        l7 = -(INT32_C(1));
        l9 = vader_parser_peek_at(l0, l7);
        l2 = vader_parser_span_of(l0, l2, l9);
        l10 = ((vader_struct_vader_parser_CompoundOpResult_t*) l8)->f_op;
        vader_struct_toolchain_ast_BinaryExpr_t* _a1_obj = (vader_struct_toolchain_ast_BinaryExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BinaryExpr_t));
        vader_obj_header_init(_a1_obj, 403u);
        _a1_obj->f_span = l2;
        _a1_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a1_obj->f_op = l10;
        _a1_obj->f_left = l5;
        _a1_obj->f_right = l6;
        _a1_obj->f_bind_as = 0u;
        l8 = (void*) _a1_obj;
        vader_struct_toolchain_ast_AssignStmt_t* _a2_obj = (vader_struct_toolchain_ast_AssignStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_AssignStmt_t));
        vader_obj_header_init(_a2_obj, 401u);
        _a2_obj->f_span = l2;
        _a2_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a2_obj->f_target = l5;
        _a2_obj->f_value = vader_ref_box(l8);
        t1 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = l5.payload.obj;
    vader_struct_toolchain_ast_ExprStmt_t* _a3_obj = (vader_struct_toolchain_ast_ExprStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ExprStmt_t));
    vader_obj_header_init(_a3_obj, 425u);
    _a3_obj->f_span = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_span;
    _a3_obj->f_id = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_expr = l5;
    t1 = (void*) _a3_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_parser_parse_string_lit(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l4 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    bool l3;
    vader_string_t l5;
    vader_box_t l6 = vader_box_null(), l10 = vader_box_null(), l11 = vader_box_null();
    bool t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[3] = { &l6, &l10, &l11 };
    void** gc_raw_roots[14] = { &l0, &l1, &l2, &l4, &l7, &l8, &l9, &l12, &l13, &l14, &l15, &l16, &l17, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 14u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_advance(l0);
    vader_array_t* _a0_arr = vader_array_new(114u, 0u, 13u, 1075u);
    l2 = (void*) _a0_arr;
    {
        loop_6: {
            t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(8));
            if (!(t0)) {
                t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(0));
                l3 = !(t0);
            } else {
                l3 = false;
            }
            if (l3) {
                l4 = vader_parser_peek(l0);
                if (((vader_struct_vader_lexer_Token_t*) l4)->f_kind == INT32_C(7)) {
                    vader_parser_advance(l0);
                    l5 = ((vader_struct_vader_lexer_Token_t*) l4)->f_text;
                    l6 = ((vader_struct_vader_lexer_Token_t*) l4)->f_value;
                    if (l6.tag == 161u) {
                        l5 = l6.payload.s;
                    } else {
                    }
                    l7 = ((vader_struct_vader_lexer_Token_t*) l4)->f_span;
                    vader_struct_toolchain_ast_StringLitText_t* _a1_obj = (vader_struct_toolchain_ast_StringLitText_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_StringLitText_t));
                    vader_obj_header_init(_a1_obj, 469u);
                    _a1_obj->f_value = l5;
                    _a1_obj->f_span = l7;
                    _a1_obj->f_id = (size_t) (int64_t) INT64_C(0);
                    l8 = (void*) _a1_obj;
                    vader_array_push((vader_array_t*) l2, vader_ref_box(l8));
                    goto loop_6;
                }
                if (((vader_struct_vader_lexer_Token_t*) l4)->f_kind == INT32_C(9)) {
                    l9 = vader_parser_advance(l0);
                    l10 = vader_parser_parse_expr(l0, INT32_C(0));
                    l11 = vader_parser_match_kind(l0, (uint8_t) (int32_t) INT32_C(10));
                    if (!(l11.tag == 0u)) {
                        t1 = l11.payload.obj;
                        l12 = ((vader_struct_vader_lexer_Token_t*) t1)->f_span;
                    } else {
                        t1 = l10.payload.obj;
                        l12 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_span;
                    }
                    l13 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l9)->f_span)->f_start;
                    l14 = ((vader_struct_toolchain_span_Span_t*) l12)->f_end;
                    vader_struct_toolchain_span_Span_t* _a2_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
                    vader_obj_header_init(_a2_obj, 489u);
                    _a2_obj->f_start = l13;
                    _a2_obj->f_end = l14;
                    l15 = (void*) _a2_obj;
                    vader_struct_toolchain_ast_StringLitInterp_t* _a3_obj = (vader_struct_toolchain_ast_StringLitInterp_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_StringLitInterp_t));
                    vader_obj_header_init(_a3_obj, 468u);
                    _a3_obj->f_expr = l10;
                    _a3_obj->f_span = l15;
                    _a3_obj->f_id = (size_t) (int64_t) INT64_C(0);
                    l16 = (void*) _a3_obj;
                    vader_array_push((vader_array_t*) l2, vader_ref_box(l16));
                    goto loop_6;
                }
                l17 = ((vader_struct_vader_lexer_Token_t*) l4)->f_span;
                vader_parser_error(l0, (uint8_t) (int32_t) INT32_C(0), l17, 1606u);
                vader_parser_advance(l0);
                goto loop_6;
            } else {
            }
        }
    }
    l4 = vader_parser_match_or_peek(l0, (uint8_t) (int32_t) INT32_C(8));
    t1 = vader_parser_span_of(l0, l1, l4);
    vader_struct_toolchain_ast_StringLitExpr_t* _a4_obj = (vader_struct_toolchain_ast_StringLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_StringLitExpr_t));
    vader_obj_header_init(_a4_obj, 467u);
    _a4_obj->f_span = t1;
    _a4_obj->f_id = (size_t) (int64_t) INT64_C(0);
    _a4_obj->f_parts = l2;
    t1 = (void*) _a4_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_parser_parse_struct_decl(void* l0, void* l1, uint8_t l2, void* l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    void* l8 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l20 = NULL;
    void* l21 = NULL;
    void* l23 = NULL;
    bool l6;
    uint8_t l7;
    size_t l9, l10;
    vader_string_t l13, l14, l22;
    vader_box_t l17 = vader_box_null(), l18 = vader_box_null();
    int32_t l19;
    bool t0;
    vader_string_t t1;
    int64_t t2;
    vader_box_t t3 = vader_box_null();
    void* t4 = NULL;
    vader_box_t* gc_roots[3] = { &l17, &l18, &t3 };
    void** gc_raw_roots[14] = { &l0, &l1, &l3, &l4, &l5, &l8, &l11, &l12, &l15, &l16, &l20, &l21, &l23, &t4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 14u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_parser_reject_target_decorator(l0, l1, 1077u);
    vader_parser_advance(l0);
    l4 = vader_parser_parse_struct_type_param_list(l0);
    vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(76), 1052u);
    vader_parser_skip_newlines(l0);
    vader_array_t* _a0_arr = vader_array_new(29u, 0u, 13u, 471u);
    l5 = (void*) _a0_arr;
    {
        loop_20: {
            t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(77));
            if (!(t0)) {
                t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(0));
                l6 = !(t0);
            } else {
                l6 = false;
            }
            if (l6) {
                l8 = vader_parser_parse_decorators(l0);
                l7 = (uint8_t) (int32_t) INT32_C(0);
                l9 = ((vader_array_t*) l8)->length;
                l10 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_48: {
                        if ((l10 < l9)) {
                            vader_array_t* _a1_slotarr = ((vader_array_t*) l8);
                            if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                            if ((size_t) l10 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                            l11 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l10);
                            t1 = ((vader_struct_toolchain_ast_Decorator_t*) l11)->f_name;
                            if (t1 == 1619u) {
                                l7 = (uint8_t) (int32_t) INT32_C(1);
                            } else {
                                l12 = ((vader_struct_toolchain_ast_Decorator_t*) l11)->f_span;
                                l13 = ((vader_struct_toolchain_ast_Decorator_t*) l11)->f_name;
                                l14 = concat_3(1005u, l13, 888u);
                                vader_parser_error(l0, (uint8_t) (int32_t) INT32_C(13), l12, l14);
                            }
                            t2 = (l10 + INT64_C(1));
                            l10 = (size_t) (int64_t) t2;
                            goto loop_48;
                        } else {
                        }
                    }
                }
                l15 = vader_parser_peek(l0);
                l16 = vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(2), 1460u);
                vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(80), 996u);
                l17 = vader_parser_parse_type(l0);
                l18 = vader_box_obj(0u, NULL);
                t3 = vader_parser_match_kind(l0, (uint8_t) (int32_t) INT32_C(57));
                if (!(t3.tag == 0u)) {
                    vader_parser_skip_newlines(l0);
                    l18 = vader_parser_parse_expr(l0, INT32_C(0));
                } else {
                }
                l19 = -(INT32_C(1));
                l20 = vader_parser_peek_at(l0, l19);
                l21 = vader_parser_span_of(l0, l15, l20);
                l22 = ((vader_struct_vader_lexer_Token_t*) l16)->f_text;
                vader_struct_toolchain_ast_StructField_t* _a2_obj = (vader_struct_toolchain_ast_StructField_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_StructField_t));
                vader_obj_header_init(_a2_obj, 471u);
                _a2_obj->f_span = l21;
                _a2_obj->f_id = (size_t) (int64_t) INT64_C(0);
                _a2_obj->f_name = l22;
                _a2_obj->f_ty = l17;
                _a2_obj->f_visibility = l7;
                _a2_obj->f_default_v = l18;
                l23 = (void*) _a2_obj;
                vader_array_push((vader_array_t*) l5, vader_ref_box(l23));
                t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(77));
                if (!(t0)) {
                    vader_parser_match_kind(l0, (uint8_t) (int32_t) INT32_C(78));
                    vader_parser_skip_newlines(l0);
                } else {
                }
                goto loop_20;
            } else {
            }
        }
    }
    l8 = vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(77), 1060u);
    l8 = vader_parser_span_of(l0, l3, l8);
    l13 = ((vader_struct_vader_lexer_Token_t*) l3)->f_text;
    l11 = ((vader_struct_vader_lexer_Token_t*) l3)->f_span;
    vader_struct_toolchain_ast_StructDecl_t* _a3_obj = (vader_struct_toolchain_ast_StructDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_StructDecl_t));
    vader_obj_header_init(_a3_obj, 470u);
    _a3_obj->f_span = l8;
    _a3_obj->f_id = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_name = l13;
    _a3_obj->f_name_span = l11;
    _a3_obj->f_visibility = l2;
    _a3_obj->f_type_params = l4;
    _a3_obj->f_fields = l5;
    _a3_obj->f_decorators = l1;
    t4 = (void*) _a3_obj;
    { void* __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_parser_parse_struct_lit_fields(void* l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    bool l2, l3;
    vader_box_t l5 = vader_box_null(), l10 = vader_box_null();
    int32_t l6, l11;
    vader_string_t l14;
    bool t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[3] = { &l5, &l10, &t1 };
    void** gc_raw_roots[11] = { &l0, &l1, &l4, &l7, &l8, &l9, &l12, &l13, &l15, &l16, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 11u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(115u, 0u, 13u, 1076u);
    l1 = (void*) _a0_arr;
    l2 = false;
    vader_parser_skip_newlines(l0);
    {
        loop_7: {
            t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(77));
            if (!(t0)) {
                t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(0));
                l3 = !(t0);
            } else {
                l3 = false;
            }
            if (l3) {
                l4 = vader_parser_peek(l0);
                t1 = vader_parser_match_kind(l0, (uint8_t) (int32_t) INT32_C(67));
                if (!(t1.tag == 0u)) {
                    l5 = vader_parser_parse_expr(l0, INT32_C(0));
                    l6 = -(INT32_C(1));
                    l7 = vader_parser_peek_at(l0, l6);
                    t2 = vader_parser_span_of(l0, l4, l7);
                    vader_struct_toolchain_ast_StructLitSpread_t* _a1_obj = (vader_struct_toolchain_ast_StructLitSpread_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_StructLitSpread_t));
                    vader_obj_header_init(_a1_obj, 474u);
                    _a1_obj->f_span = t2;
                    _a1_obj->f_id = (size_t) (int64_t) INT64_C(0);
                    _a1_obj->f_expr = l5;
                    l8 = (void*) _a1_obj;
                    vader_array_push((vader_array_t*) l1, vader_ref_box(l8));
                } else {
                    vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(79), 992u);
                    l9 = vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(2), 2028u);
                    vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(57), 998u);
                    l10 = vader_parser_parse_expr(l0, INT32_C(0));
                    l11 = -(INT32_C(1));
                    l12 = vader_parser_peek_at(l0, l11);
                    l13 = vader_parser_span_of(l0, l4, l12);
                    l14 = ((vader_struct_vader_lexer_Token_t*) l9)->f_text;
                    l15 = ((vader_struct_vader_lexer_Token_t*) l9)->f_span;
                    vader_struct_toolchain_ast_StructLitField_t* _a2_obj = (vader_struct_toolchain_ast_StructLitField_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_StructLitField_t));
                    vader_obj_header_init(_a2_obj, 473u);
                    _a2_obj->f_span = l13;
                    _a2_obj->f_id = (size_t) (int64_t) INT64_C(0);
                    _a2_obj->f_name = l14;
                    _a2_obj->f_name_span = l15;
                    _a2_obj->f_value = l10;
                    l16 = (void*) _a2_obj;
                    vader_array_push((vader_array_t*) l1, vader_ref_box(l16));
                }
                vader_parser_skip_newlines(l0);
                t1 = vader_parser_match_kind(l0, (uint8_t) (int32_t) INT32_C(78));
                if (t1.tag == 0u) {
                } else {
                    vader_parser_skip_newlines(l0);
                    l2 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(77));
                    goto loop_7;
                }
            } else {
            }
        }
    }
    vader_parser_skip_newlines(l0);
    vader_struct_vader_parser_CommaList__Any__Any_t* _a3_obj = (vader_struct_vader_parser_CommaList__Any__Any_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_CommaList__Any__Any_t));
    vader_obj_header_init(_a3_obj, 859u);
    _a3_obj->f_items = l1;
    _a3_obj->f_trailing_comma = l2;
    t2 = (void*) _a3_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_parser_parse_struct_pattern(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l7 = NULL;
    void* l10 = NULL;
    void* l12 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    bool l3, l9;
    vader_string_t l6, l11, l16;
    vader_box_t l8 = vader_box_null();
    int32_t l13;
    bool t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l8, &t2 };
    void** gc_raw_roots[13] = { &l0, &l1, &l2, &l4, &l5, &l7, &l10, &l12, &l14, &l15, &l17, &l18, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 13u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(76), 1053u);
    vader_parser_skip_newlines(l0);
    vader_array_t* _a0_arr = vader_array_new(30u, 0u, 13u, 476u);
    l2 = (void*) _a0_arr;
    {
        loop_10: {
            t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(77));
            if (!(t0)) {
                t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(0));
                l3 = !(t0);
            } else {
                l3 = false;
            }
            if (l3) {
                l4 = vader_parser_peek(l0);
                l5 = vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(2), 1463u);
                l6 = ((vader_struct_vader_lexer_Token_t*) l5)->f_text;
                l7 = ((vader_struct_vader_lexer_Token_t*) l5)->f_span;
                vader_struct_toolchain_ast_PatternBinding_t* _a1_obj = (vader_struct_toolchain_ast_PatternBinding_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_PatternBinding_t));
                vader_obj_header_init(_a1_obj, 458u);
                _a1_obj->f_name = l6;
                _a1_obj->f_span = l7;
                _a1_obj->f_id = (size_t) (int64_t) INT64_C(0);
                t1 = (void*) _a1_obj;
                l8 = vader_ref_box(t1);
                t2 = vader_parser_match_kind(l0, (uint8_t) (int32_t) INT32_C(80));
                if (!(t2.tag == 0u)) {
                    t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(2));
                    if (t0) {
                        t1 = vader_parser_peek_at(l0, INT32_C(1));
                        t0 = vader_parser_is_literal_start(t1);
                        l9 = !(t0);
                    } else {
                        l9 = false;
                    }
                    if (l9) {
                        l10 = vader_parser_advance(l0);
                        l11 = ((vader_struct_vader_lexer_Token_t*) l10)->f_text;
                        l12 = ((vader_struct_vader_lexer_Token_t*) l10)->f_span;
                        vader_struct_toolchain_ast_PatternBinding_t* _a2_obj = (vader_struct_toolchain_ast_PatternBinding_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_PatternBinding_t));
                        vader_obj_header_init(_a2_obj, 458u);
                        _a2_obj->f_name = l11;
                        _a2_obj->f_span = l12;
                        _a2_obj->f_id = (size_t) (int64_t) INT64_C(0);
                        t1 = (void*) _a2_obj;
                        l8 = vader_ref_box(t1);
                    } else {
                        t2 = vader_parser_parse_expr(l0, INT32_C(0));
                        vader_struct_toolchain_ast_PatternLiteral_t* _a3_obj = (vader_struct_toolchain_ast_PatternLiteral_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_PatternLiteral_t));
                        vader_obj_header_init(_a3_obj, 459u);
                        _a3_obj->f_value = t2;
                        t1 = (void*) _a3_obj;
                        l8 = vader_ref_box(t1);
                    }
                } else {
                }
                l13 = -(INT32_C(1));
                l14 = vader_parser_peek_at(l0, l13);
                l15 = vader_parser_span_of(l0, l4, l14);
                l16 = ((vader_struct_vader_lexer_Token_t*) l5)->f_text;
                l17 = ((vader_struct_vader_lexer_Token_t*) l5)->f_span;
                vader_struct_toolchain_ast_StructPatternField_t* _a4_obj = (vader_struct_toolchain_ast_StructPatternField_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_StructPatternField_t));
                vader_obj_header_init(_a4_obj, 476u);
                _a4_obj->f_span = l15;
                _a4_obj->f_id = (size_t) (int64_t) INT64_C(0);
                _a4_obj->f_name = l16;
                _a4_obj->f_name_span = l17;
                _a4_obj->f_value = l8;
                l18 = (void*) _a4_obj;
                vader_array_push((vader_array_t*) l2, vader_ref_box(l18));
                vader_parser_skip_newlines(l0);
                t2 = vader_parser_match_kind(l0, (uint8_t) (int32_t) INT32_C(78));
                if (t2.tag == 0u) {
                } else {
                    vader_parser_skip_newlines(l0);
                    goto loop_10;
                }
            } else {
            }
        }
    }
    l4 = vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(77), 1062u);
    l1 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l1)->f_span)->f_start;
    l4 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l4)->f_span)->f_end;
    vader_struct_toolchain_span_Span_t* _a5_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a5_obj, 489u);
    _a5_obj->f_start = l1;
    _a5_obj->f_end = l4;
    t1 = (void*) _a5_obj;
    vader_struct_toolchain_ast_StructPattern_t* _a6_obj = (vader_struct_toolchain_ast_StructPattern_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_StructPattern_t));
    vader_obj_header_init(_a6_obj, 475u);
    _a6_obj->f_span = t1;
    _a6_obj->f_id = (size_t) (int64_t) INT64_C(0);
    _a6_obj->f_fields = l2;
    t1 = (void*) _a6_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_parser_parse_struct_type_param_list(void* l0) {
    void* l1 = NULL;
    void* l5 = NULL;
    void* l8 = NULL;
    void* l22 = NULL;
    void* l23 = NULL;
    void* l29 = NULL;
    void* l30 = NULL;
    void* l37 = NULL;
    void* l38 = NULL;
    void* l42 = NULL;
    bool l2, l4, l35;
    uint8_t l3, l6, l10, l20, l27;
    vader_string_t l7, l11, l12, l13, l14, l15, l16, l17, l18, l19, l25, l26, l31, l32, l33, l34, l40;
    vader_box_t l9 = vader_box_null(), l24 = vader_box_null();
    int32_t l21, l28, l36;
    size_t l39;
    vader_box_t l41;
    bool t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    size_t t3;
    vader_box_t* gc_roots[3] = { &l9, &l24, &t2 };
    void** gc_raw_roots[12] = { &l0, &l1, &l5, &l8, &l22, &l23, &l29, &l30, &l37, &l38, &l42, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 12u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(49));
    if (t0) {
        t1 = vader_parser_parse_angle_type_params(l0);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_parser_match_kind(l0, (uint8_t) (int32_t) INT32_C(72));
    if (t2.tag == 0u) {
        vader_array_t* _a0_arr = vader_array_new(33u, 0u, 13u, 481u);
        t1 = (void*) _a0_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a1_arr = vader_array_new(33u, 0u, 13u, 481u);
    l1 = (void*) _a1_arr;
    vader_parser_skip_newlines(l0);
    {
        loop_21: {
            t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(73));
            if (!(t0)) {
                t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(0));
                l2 = !(t0);
            } else {
                l2 = false;
            }
            if (l2) {
                t3 = ((vader_array_t*) l1)->length;
                if ((t3 > INT64_C(0))) {
                    t2 = vader_parser_match_kind(l0, (uint8_t) (int32_t) INT32_C(78));
                    if (t2.tag == 0u) {
                    } else {
                        vader_parser_skip_newlines(l0);
                        t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(73));
                        if (t0) {
                        } else {
                            l3 = (uint8_t) (int32_t) INT32_C(71);
                            t2 = vader_parser_match_kind(l0, l3);
                            l4 = !(t2.tag == 0u);
                            l5 = vader_parser_peek(l0);
                            l6 = (uint8_t) (int32_t) INT32_C(2);
                            l7 = 2085u;
                            l8 = vader_parser_expect(l0, l6, l7);
                            l9 = vader_box_obj(0u, NULL);
                            l10 = (uint8_t) (int32_t) INT32_C(80);
                            t2 = vader_parser_match_kind(l0, l10);
                            if (!(t2.tag == 0u)) {
                                l9 = vader_parser_parse_type(l0);
                            } else {
                            }
                            if (!(l4)) {
                                if (l9.tag == 0u) {
                                    l12 = 872u;
                                    l13 = ((vader_struct_vader_lexer_Token_t*) l8)->f_text;
                                    l14 = 932u;
                                    l15 = ((vader_struct_vader_lexer_Token_t*) l8)->f_text;
                                    l16 = 872u;
                                    l11 = concat_5(l12, l13, l14, l15, l16);
                                } else {
                                    l17 = 872u;
                                    l18 = ((vader_struct_vader_lexer_Token_t*) l8)->f_text;
                                    l19 = 931u;
                                    l11 = concat_3(l17, l18, l19);
                                }
                                l20 = (uint8_t) (int32_t) INT32_C(17);
                                l21 = -(INT32_C(1));
                                l22 = vader_parser_peek_at(l0, l21);
                                l23 = vader_parser_span_of(l0, l5, l22);
                                vader_parser_error(l0, l20, l23, l11);
                            } else {
                                l24 = l9;
                                if (l24.tag == 0u) {
                                } else {
                                    if (l24.tag == 433u) {
                                        t1 = l24.payload.obj;
                                        l25 = ((vader_struct_toolchain_ast_IdentExpr_t*) t1)->f_name;
                                        l26 = 2081u;
                                        if (l25 == l26) {
                                            l27 = (uint8_t) (int32_t) INT32_C(18);
                                            l28 = -(INT32_C(1));
                                            l29 = vader_parser_peek_at(l0, l28);
                                            l30 = vader_parser_span_of(l0, l5, l29);
                                            l31 = 872u;
                                            l32 = ((vader_struct_vader_lexer_Token_t*) l8)->f_text;
                                            l33 = 908u;
                                            l34 = concat_3(l31, l32, l33);
                                            vader_parser_error(l0, l27, l30, l34);
                                            l9 = vader_box_obj(0u, NULL);
                                        } else {
                                        }
                                    } else {
                                    }
                                }
                            }
                            l35 = !(l9.tag == 0u);
                            l36 = -(INT32_C(1));
                            l37 = vader_parser_peek_at(l0, l36);
                            l38 = vader_parser_span_of(l0, l5, l37);
                            l39 = (size_t) (int64_t) INT64_C(0);
                            l40 = ((vader_struct_vader_lexer_Token_t*) l8)->f_text;
                            l41 = vader_box_obj(0u, NULL);
                            vader_struct_toolchain_ast_TypeParam_t* _a2_obj = (vader_struct_toolchain_ast_TypeParam_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_TypeParam_t));
                            vader_obj_header_init(_a2_obj, 481u);
                            _a2_obj->f_span = l38;
                            _a2_obj->f_id = l39;
                            _a2_obj->f_name = l40;
                            _a2_obj->f_bound = l9;
                            _a2_obj->f_default_v = l41;
                            _a2_obj->f_is_comptime_value = l35;
                            l42 = (void*) _a2_obj;
                            vader_array_push((vader_array_t*) l1, vader_ref_box(l42));
                            goto loop_21;
                        }
                    }
                } else {
                    l3 = (uint8_t) (int32_t) INT32_C(71);
                    t2 = vader_parser_match_kind(l0, l3);
                    l4 = !(t2.tag == 0u);
                    l5 = vader_parser_peek(l0);
                    l6 = (uint8_t) (int32_t) INT32_C(2);
                    l7 = 2085u;
                    l8 = vader_parser_expect(l0, l6, l7);
                    l9 = vader_box_obj(0u, NULL);
                    l10 = (uint8_t) (int32_t) INT32_C(80);
                    t2 = vader_parser_match_kind(l0, l10);
                    if (!(t2.tag == 0u)) {
                        l9 = vader_parser_parse_type(l0);
                    } else {
                    }
                    if (!(l4)) {
                        if (l9.tag == 0u) {
                            l12 = 872u;
                            l13 = ((vader_struct_vader_lexer_Token_t*) l8)->f_text;
                            l14 = 932u;
                            l15 = ((vader_struct_vader_lexer_Token_t*) l8)->f_text;
                            l16 = 872u;
                            l11 = concat_5(l12, l13, l14, l15, l16);
                        } else {
                            l17 = 872u;
                            l18 = ((vader_struct_vader_lexer_Token_t*) l8)->f_text;
                            l19 = 931u;
                            l11 = concat_3(l17, l18, l19);
                        }
                        l20 = (uint8_t) (int32_t) INT32_C(17);
                        l21 = -(INT32_C(1));
                        l22 = vader_parser_peek_at(l0, l21);
                        l23 = vader_parser_span_of(l0, l5, l22);
                        vader_parser_error(l0, l20, l23, l11);
                    } else {
                        l24 = l9;
                        if (l24.tag == 0u) {
                        } else {
                            if (l24.tag == 433u) {
                                t1 = l24.payload.obj;
                                l25 = ((vader_struct_toolchain_ast_IdentExpr_t*) t1)->f_name;
                                l26 = 2081u;
                                if (l25 == l26) {
                                    l27 = (uint8_t) (int32_t) INT32_C(18);
                                    l28 = -(INT32_C(1));
                                    l29 = vader_parser_peek_at(l0, l28);
                                    l30 = vader_parser_span_of(l0, l5, l29);
                                    l31 = 872u;
                                    l32 = ((vader_struct_vader_lexer_Token_t*) l8)->f_text;
                                    l33 = 908u;
                                    l34 = concat_3(l31, l32, l33);
                                    vader_parser_error(l0, l27, l30, l34);
                                    l9 = vader_box_obj(0u, NULL);
                                } else {
                                }
                            } else {
                            }
                        }
                    }
                    l35 = !(l9.tag == 0u);
                    l36 = -(INT32_C(1));
                    l37 = vader_parser_peek_at(l0, l36);
                    l38 = vader_parser_span_of(l0, l5, l37);
                    l39 = (size_t) (int64_t) INT64_C(0);
                    l40 = ((vader_struct_vader_lexer_Token_t*) l8)->f_text;
                    l41 = vader_box_obj(0u, NULL);
                    vader_struct_toolchain_ast_TypeParam_t* _a3_obj = (vader_struct_toolchain_ast_TypeParam_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_TypeParam_t));
                    vader_obj_header_init(_a3_obj, 481u);
                    _a3_obj->f_span = l38;
                    _a3_obj->f_id = l39;
                    _a3_obj->f_name = l40;
                    _a3_obj->f_bound = l9;
                    _a3_obj->f_default_v = l41;
                    _a3_obj->f_is_comptime_value = l35;
                    l42 = (void*) _a3_obj;
                    vader_array_push((vader_array_t*) l1, vader_ref_box(l42));
                    goto loop_21;
                }
            } else {
            }
        }
    }
    vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(73), 984u);
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_parser_parse_trait_decl(void* l0, void* l1, uint8_t l2, void* l3) {
    void* l4 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    void* l10 = NULL;
    vader_box_t l5 = vader_box_null(), l12 = vader_box_null();
    int32_t l7;
    vader_string_t l9;
    bool l11;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    bool t2;
    vader_box_t* gc_roots[3] = { &l5, &l12, &t0 };
    void** gc_raw_roots[8] = { &l0, &l1, &l3, &l4, &l6, &l8, &l10, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 8u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_parser_reject_target_decorator(l0, l1, 1078u);
    vader_parser_advance(l0);
    l4 = vader_parser_parse_struct_type_param_list(l0);
    l5 = vader_box_obj(0u, NULL);
    vader_array_t* _a0_arr = vader_array_new(23u, 0u, 13u, 428u);
    l6 = (void*) _a0_arr;
    t0 = vader_parser_match_kind(l0, (uint8_t) (int32_t) INT32_C(57));
    if (!(t0.tag == 0u)) {
        l5 = vader_parser_parse_type(l0);
        l7 = -(INT32_C(1));
        l8 = vader_parser_peek_at(l0, l7);
        l8 = vader_parser_span_of(l0, l3, l8);
        l9 = ((vader_struct_vader_lexer_Token_t*) l3)->f_text;
        l10 = ((vader_struct_vader_lexer_Token_t*) l3)->f_span;
        vader_struct_toolchain_ast_TraitDecl_t* _a1_obj = (vader_struct_toolchain_ast_TraitDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_TraitDecl_t));
        vader_obj_header_init(_a1_obj, 477u);
        _a1_obj->f_span = l8;
        _a1_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a1_obj->f_name = l9;
        _a1_obj->f_name_span = l10;
        _a1_obj->f_visibility = l2;
        _a1_obj->f_type_params = l4;
        _a1_obj->f_requires = l5;
        _a1_obj->f_members = l6;
        _a1_obj->f_decorators = l1;
        t1 = (void*) _a1_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_parser_match_kind(l0, (uint8_t) (int32_t) INT32_C(80));
    if (!(t0.tag == 0u)) {
        l5 = vader_parser_parse_type(l0);
    } else {
    }
    vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(76), 1054u);
    vader_parser_skip_newlines(l0);
    {
        loop_71: {
            t2 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(77));
            if (!(t2)) {
                t2 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(0));
                l11 = !(t2);
            } else {
                l11 = false;
            }
            if (l11) {
                l12 = vader_parser_parse_fn_decl_inside_trait(l0);
                if (l12.tag == 428u) {
                    l8 = l12.payload.obj;
                    vader_array_push((vader_array_t*) l6, vader_ref_box(l8));
                    vader_parser_skip_newlines(l0);
                    goto loop_71;
                }
                if (l12.tag == 0u) {
                    vader_parser_skip_newlines(l0);
                    goto loop_71;
                }
                vader_unreachable("unreachable return in vader_parser$parse_trait_decl");
            } else {
            }
        }
    }
    l8 = vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(77), 1063u);
    l8 = vader_parser_span_of(l0, l3, l8);
    l9 = ((vader_struct_vader_lexer_Token_t*) l3)->f_text;
    l10 = ((vader_struct_vader_lexer_Token_t*) l3)->f_span;
    vader_struct_toolchain_ast_TraitDecl_t* _a2_obj = (vader_struct_toolchain_ast_TraitDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_TraitDecl_t));
    vader_obj_header_init(_a2_obj, 477u);
    _a2_obj->f_span = l8;
    _a2_obj->f_id = (size_t) (int64_t) INT64_C(0);
    _a2_obj->f_name = l9;
    _a2_obj->f_name_span = l10;
    _a2_obj->f_visibility = l2;
    _a2_obj->f_type_params = l4;
    _a2_obj->f_requires = l5;
    _a2_obj->f_members = l6;
    _a2_obj->f_decorators = l1;
    t1 = (void*) _a2_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_parser_parse_tuple_let(void* l0) {
    void* l1 = NULL;
    void* l5 = NULL;
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l7 = vader_box_null();
    bool l4, l6;
    int32_t l8;
    bool t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[3] = { &l2, &l3, &l7 };
    void** gc_raw_roots[4] = { &l0, &l1, &l5, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_peek(l0);
    l2 = vader_parser_parse_let_binding(l0);
    l3 = vader_box_obj(0u, NULL);
    l4 = true;
    t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(80));
    if (t0) {
        vader_parser_advance(l0);
        l3 = vader_parser_parse_type(l0);
        t1 = vader_parser_peek(l0);
        if (((vader_struct_vader_lexer_Token_t*) t1)->f_kind == INT32_C(80)) {
            vader_parser_advance(l0);
            l4 = false;
        } else {
            vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(57), 999u);
        }
    } else {
        l5 = vader_parser_peek(l0);
        if (((vader_struct_vader_lexer_Token_t*) l5)->f_kind == INT32_C(63)) {
            l6 = true;
        } else {
            l6 = ((vader_struct_vader_lexer_Token_t*) l5)->f_kind == INT32_C(64);
        }
        if (l6) {
            vader_parser_advance(l0);
            l4 = ((vader_struct_vader_lexer_Token_t*) l5)->f_kind == INT32_C(64);
        } else {
            vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(64), 995u);
        }
    }
    l7 = vader_parser_parse_expr(l0, INT32_C(0));
    l8 = -(INT32_C(1));
    l5 = vader_parser_peek_at(l0, l8);
    t1 = vader_parser_span_of(l0, l1, l5);
    vader_struct_toolchain_ast_LetStmt_t* _a0_obj = (vader_struct_toolchain_ast_LetStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_LetStmt_t));
    vader_obj_header_init(_a0_obj, 447u);
    _a0_obj->f_span = t1;
    _a0_obj->f_id = (size_t) (int64_t) INT64_C(0);
    _a0_obj->f_mutable = l4;
    _a0_obj->f_binding = l2;
    _a0_obj->f_ty = l3;
    _a0_obj->f_value = l7;
    t1 = (void*) _a0_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_parser_parse_tuple_pattern(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    vader_box_t l3 = vader_box_null();
    bool t0;
    vader_box_t t1 = vader_box_null();
    size_t t2;
    void* t3 = NULL;
    vader_box_t* gc_roots[2] = { &l3, &t1 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l4, &l5, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_advance(l0);
    vader_parser_skip_newlines(l0);
    vader_array_t* _a0_arr = vader_array_new(111u, 0u, 13u, 1049u);
    l2 = (void*) _a0_arr;
    t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(75));
    if (!(t0)) {
        {
            loop_13: {
                vader_parser_skip_newlines(l0);
                t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(75));
                if (t0) {
                } else {
                    l3 = vader_parser_parse_pattern(l0);
                    vader_array_push((vader_array_t*) l2, l3);
                    vader_parser_skip_newlines(l0);
                    t1 = vader_parser_match_kind(l0, (uint8_t) (int32_t) INT32_C(78));
                    if (t1.tag == 0u) {
                    } else {
                        vader_parser_skip_newlines(l0);
                        goto loop_13;
                    }
                }
                goto end_11;
            }
        }
    } else {
    } end_11: ;
    l4 = vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(75), 1030u);
    t2 = ((vader_array_t*) l2)->length;
    if ((t2 < INT64_C(2))) {
        l5 = vader_parser_span_of(l0, l1, l4);
        vader_parser_error(l0, (uint8_t) (int32_t) INT32_C(21), l5, 0u);
    } else {
    }
    t3 = vader_parser_span_of(l0, l1, l4);
    vader_struct_toolchain_ast_TuplePattern_t* _a1_obj = (vader_struct_toolchain_ast_TuplePattern_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_TuplePattern_t));
    vader_obj_header_init(_a1_obj, 479u);
    _a1_obj->f_span = t3;
    _a1_obj->f_id = (size_t) (int64_t) INT64_C(0);
    _a1_obj->f_elements = l2;
    t3 = (void*) _a1_obj;
    { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t vader_parser_parse_type(void* l0) {
    int32_t l1;
    void* l2 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null();
    int32_t t0;
    void* t1 = NULL;
    bool t2;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l3, &l4, &t3 };
    void** gc_raw_roots[6] = { &l0, &l2, &l5, &l6, &l7, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth;
    l1 = (t0 + INT32_C(1));
    ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth = l1;
    VADER_WRITE_BARRIER((vader_struct_vader_parser_Parser_t*) l0);
    t0 = ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth;
    if ((t0 > INT32_C(256))) {
        t0 = ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth;
        l1 = (t0 - INT32_C(1));
        ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth = l1;
        VADER_WRITE_BARRIER((vader_struct_vader_parser_Parser_t*) l0);
        t1 = vader_parser_peek(l0);
        l2 = ((vader_struct_vader_lexer_Token_t*) t1)->f_span;
        vader_parser_report_nesting_too_deep(l0, 2081u);
        t1 = vader_parser_ident_expr(l2, 488u);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_parser_match_kind(l0, (uint8_t) (int32_t) INT32_C(42));
    vader_parser_reject_removed_const(l0);
    l3 = vader_parser_parse_type_intersection(l0);
    t2 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(42));
    if (t2) {
        t1 = l3.payload.obj;
        l2 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_span;
        {
            loop_51: {
                t3 = vader_parser_match_kind(l0, (uint8_t) (int32_t) INT32_C(42));
                if (!(t3.tag == 0u)) {
                    vader_parser_reject_removed_const(l0);
                    l4 = vader_parser_parse_type_intersection(l0);
                    t1 = l4.payload.obj;
                    l5 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_span;
                    l6 = ((vader_struct_toolchain_span_Span_t*) l2)->f_start;
                    l7 = ((vader_struct_toolchain_span_Span_t*) l5)->f_end;
                    vader_struct_toolchain_span_Span_t* _a0_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
                    vader_obj_header_init(_a0_obj, 489u);
                    _a0_obj->f_start = l6;
                    _a0_obj->f_end = l7;
                    t1 = (void*) _a0_obj;
                    vader_struct_toolchain_ast_BinaryExpr_t* _a1_obj = (vader_struct_toolchain_ast_BinaryExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BinaryExpr_t));
                    vader_obj_header_init(_a1_obj, 403u);
                    _a1_obj->f_span = t1;
                    _a1_obj->f_id = (size_t) (int64_t) INT64_C(0);
                    _a1_obj->f_op = (uint8_t) (int32_t) INT32_C(8);
                    _a1_obj->f_left = l3;
                    _a1_obj->f_right = l4;
                    _a1_obj->f_bind_as = 0u;
                    t1 = (void*) _a1_obj;
                    l3 = vader_ref_box(t1);
                    goto loop_51;
                } else {
                }
            }
        }
    } else {
    }
    t0 = ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth;
    l1 = (t0 - INT32_C(1));
    ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth = l1;
    VADER_WRITE_BARRIER((vader_struct_vader_parser_Parser_t*) l0);
    { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t vader_parser_parse_type_intersection(void* l0) {
    vader_box_t l1 = vader_box_null(), l3 = vader_box_null();
    void* l2 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    bool t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l1, &l3, &t2 };
    void** gc_raw_roots[6] = { &l0, &l2, &l4, &l5, &l6, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_parse_type_postfix(l0);
    t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(41));
    if (t0) {
        t1 = l1.payload.obj;
        l2 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_span;
        {
            loop_12: {
                t2 = vader_parser_match_kind(l0, (uint8_t) (int32_t) INT32_C(41));
                if (!(t2.tag == 0u)) {
                    l3 = vader_parser_parse_type_postfix(l0);
                    t1 = l3.payload.obj;
                    l4 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_span;
                    l5 = ((vader_struct_toolchain_span_Span_t*) l2)->f_start;
                    l6 = ((vader_struct_toolchain_span_Span_t*) l4)->f_end;
                    vader_struct_toolchain_span_Span_t* _a0_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
                    vader_obj_header_init(_a0_obj, 489u);
                    _a0_obj->f_start = l5;
                    _a0_obj->f_end = l6;
                    t1 = (void*) _a0_obj;
                    vader_struct_toolchain_ast_BinaryExpr_t* _a1_obj = (vader_struct_toolchain_ast_BinaryExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BinaryExpr_t));
                    vader_obj_header_init(_a1_obj, 403u);
                    _a1_obj->f_span = t1;
                    _a1_obj->f_id = (size_t) (int64_t) INT64_C(0);
                    _a1_obj->f_op = (uint8_t) (int32_t) INT32_C(7);
                    _a1_obj->f_left = l1;
                    _a1_obj->f_right = l3;
                    _a1_obj->f_bind_as = 0u;
                    t1 = (void*) _a1_obj;
                    l1 = vader_ref_box(t1);
                    goto loop_12;
                } else {
                }
            }
        }
    } else {
    }
    { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_parser_parse_type_list_until_angle(void* l0) {
    void* l1 = NULL;
    vader_box_t l2 = vader_box_null();
    uint8_t l3;
    vader_string_t l4;
    bool t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l2, &t1 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(108u, 0u, 13u, 1034u);
    l1 = (void*) _a0_arr;
    vader_parser_skip_newlines(l0);
    t0 = vader_parser_check_closing_angle(l0);
    if (t0) {
        vader_parser_consume_closing_angle(l0);
        { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    {
        loop_14: {
            vader_parser_skip_newlines(l0);
            t0 = vader_parser_check_closing_angle(l0);
            if (t0) {
            } else {
                l2 = vader_parser_parse_type(l0);
                vader_array_push((vader_array_t*) l1, l2);
                vader_parser_skip_newlines(l0);
                t1 = vader_parser_match_kind(l0, (uint8_t) (int32_t) INT32_C(78));
                if (t1.tag == 0u) {
                } else {
                    goto loop_14;
                }
            }
            t0 = vader_parser_check_closing_angle(l0);
            if (t0) {
                vader_parser_consume_closing_angle(l0);
            } else {
                l3 = (uint8_t) (int32_t) INT32_C(51);
                l4 = 1000u;
                vader_parser_expect(l0, l3, l4);
            }
            { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    t0 = vader_parser_check_closing_angle(l0);
    if (t0) {
        vader_parser_consume_closing_angle(l0);
    } else {
        l3 = (uint8_t) (int32_t) INT32_C(51);
        l4 = 1000u;
        vader_parser_expect(l0, l3, l4);
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t vader_parser_parse_type_mut_marker(void* l0) {
    void* l1 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    vader_string_t l2;
    size_t l3;
    int32_t l4, l5;
    bool t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    size_t t3;
    int64_t t4;
    int32_t t5;
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[6] = { &l0, &l1, &l6, &l7, &l8, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(55));
    if (t0) {
        t1 = vader_parser_advance(l0);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(48));
    if (!(t0)) {
        t2 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = vader_parser_peek(l0);
    l2 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l1)->f_span)->f_start)->f_file;
    t3 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l1)->f_span)->f_start)->f_offset;
    t4 = (t3 + INT64_C(1));
    l3 = (size_t) (int64_t) t4;
    l4 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l1)->f_span)->f_start)->f_line;
    t5 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l1)->f_span)->f_start)->f_column;
    l5 = (t5 + INT32_C(1));
    vader_struct_toolchain_span_Position_t* _a0_obj = (vader_struct_toolchain_span_Position_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Position_t));
    vader_obj_header_init(_a0_obj, 488u);
    _a0_obj->f_file = l2;
    _a0_obj->f_offset = l3;
    _a0_obj->f_line = l4;
    _a0_obj->f_column = l5;
    l6 = (void*) _a0_obj;
    l7 = ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens;
    t5 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pos;
    t4 = ((int64_t) (int32_t) t5);
    l3 = (size_t) (int64_t) t4;
    l8 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l1)->f_span)->f_end;
    vader_struct_toolchain_span_Span_t* _a1_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a1_obj, 489u);
    _a1_obj->f_start = l6;
    _a1_obj->f_end = l8;
    l8 = (void*) _a1_obj;
    vader_struct_vader_lexer_Token_t* _a2_obj = (vader_struct_vader_lexer_Token_t*) vader_gc_alloc(sizeof(vader_struct_vader_lexer_Token_t));
    vader_obj_header_init(_a2_obj, 707u);
    _a2_obj->f_kind = (uint8_t) (int32_t) INT32_C(57);
    _a2_obj->f_text = 481u;
    _a2_obj->f_span = l8;
    _a2_obj->f_value = vader_box_obj(0u, NULL);
    l8 = (void*) _a2_obj;
    vader_array_t* _a3_slotarr = ((vader_array_t*) l7);
    if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
    if ((size_t) l3 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
    vader_array_ref_store(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l3, l8);
    VADER_WRITE_BARRIER(_a3_slotarr->buf);
    vader_struct_toolchain_span_Span_t* _a4_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a4_obj, 489u);
    _a4_obj->f_start = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l1)->f_span)->f_start;
    _a4_obj->f_end = l6;
    l1 = (void*) _a4_obj;
    vader_struct_vader_lexer_Token_t* _a5_obj = (vader_struct_vader_lexer_Token_t*) vader_gc_alloc(sizeof(vader_struct_vader_lexer_Token_t));
    vader_obj_header_init(_a5_obj, 707u);
    _a5_obj->f_kind = (uint8_t) (int32_t) INT32_C(55);
    _a5_obj->f_text = 231u;
    _a5_obj->f_span = l1;
    _a5_obj->f_value = vader_box_obj(0u, NULL);
    t1 = (void*) _a5_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t vader_parser_parse_type_postfix(void* l0) {
    vader_box_t l1 = vader_box_null(), l6 = vader_box_null(), l11 = vader_box_null();
    bool l2;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    bool t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[3] = { &l1, &l6, &l11 };
    void** gc_raw_roots[9] = { &l0, &l3, &l4, &l5, &l7, &l8, &l9, &l10, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 9u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_parse_type_primary(l0);
    {
        loop_4: {
            t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(74));
            if (t0) {
                l2 = vader_parser_check_at(l0, (uint8_t) (int32_t) INT32_C(75), INT32_C(1));
            } else {
                l2 = false;
            }
            if (l2) {
                vader_parser_advance(l0);
                l3 = vader_parser_advance(l0);
                t1 = l1.payload.obj;
                l4 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_span)->f_start;
                l5 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l3)->f_span)->f_end;
                vader_struct_toolchain_span_Span_t* _a0_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
                vader_obj_header_init(_a0_obj, 489u);
                _a0_obj->f_start = l4;
                _a0_obj->f_end = l5;
                t1 = (void*) _a0_obj;
                vader_struct_toolchain_ast_ArrayTypeExpr_t* _a1_obj = (vader_struct_toolchain_ast_ArrayTypeExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ArrayTypeExpr_t));
                vader_obj_header_init(_a1_obj, 399u);
                _a1_obj->f_span = t1;
                _a1_obj->f_id = (size_t) (int64_t) INT64_C(0);
                _a1_obj->f_element = l1;
                t1 = (void*) _a1_obj;
                l1 = vader_ref_box(t1);
                goto loop_4;
            } else {
            }
            l6 = vader_parser_parse_type_mut_marker(l0);
            if (l6.tag == 0u) {
            } else {
                if (l1.tag == 452u) {
                    t1 = l6.payload.obj;
                    l7 = ((vader_struct_vader_lexer_Token_t*) t1)->f_span;
                    vader_parser_error(l0, (uint8_t) (int32_t) INT32_C(26), l7, 966u);
                    goto loop_4;
                }
                t1 = l1.payload.obj;
                l8 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_span)->f_start;
                t1 = l6.payload.obj;
                l9 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) t1)->f_span)->f_end;
                vader_struct_toolchain_span_Span_t* _a2_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
                vader_obj_header_init(_a2_obj, 489u);
                _a2_obj->f_start = l8;
                _a2_obj->f_end = l9;
                l10 = (void*) _a2_obj;
                l11 = l1;
                vader_struct_toolchain_ast_MutableTypeExpr_t* _a3_obj = (vader_struct_toolchain_ast_MutableTypeExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_MutableTypeExpr_t));
                vader_obj_header_init(_a3_obj, 452u);
                _a3_obj->f_span = l10;
                _a3_obj->f_id = (size_t) (int64_t) INT64_C(0);
                _a3_obj->f_inner = l11;
                t1 = (void*) _a3_obj;
                l1 = vader_ref_box(t1);
                goto loop_4;
            }
        }
    }
    { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t vader_parser_parse_type_primary(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    vader_string_t l4;
    vader_box_t l5 = vader_box_null();
    int32_t l10;
    void* t0 = NULL;
    bool t1;
    vader_box_t t2 = vader_box_null();
    size_t t3;
    vader_box_t* gc_roots[2] = { &l5, &t2 };
    void** gc_raw_roots[9] = { &l0, &l1, &l2, &l3, &l6, &l7, &l8, &l9, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 9u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_peek(l0);
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(71)) {
        vader_parser_advance(l0);
        l2 = vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(2), 2086u);
        l3 = vader_parser_span_of(l0, l1, l2);
        l4 = ((vader_struct_vader_lexer_Token_t*) l2)->f_text;
        vader_struct_toolchain_ast_IdentExpr_t* _a0_obj = (vader_struct_toolchain_ast_IdentExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_IdentExpr_t));
        vader_obj_header_init(_a0_obj, 433u);
        _a0_obj->f_span = l3;
        _a0_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a0_obj->f_name = l4;
        _a0_obj->f_implicit_dot = false;
        _a0_obj->f_is_type_param_intro = true;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(11)) {
        t0 = vader_parser_parse_fn_type(l0);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(72)) {
        vader_parser_advance(l0);
        vader_parser_skip_newlines(l0);
        l5 = vader_parser_parse_type(l0);
        vader_parser_skip_newlines(l0);
        vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(73), 983u);
        { vader_box_t __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(74)) {
        l2 = vader_parser_advance(l0);
        vader_array_t* _a1_arr = vader_array_new(108u, 0u, 13u, 1034u);
        l3 = (void*) _a1_arr;
        vader_parser_skip_newlines(l0);
        t1 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(75));
        if (t1) {
            l6 = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
            vader_parser_error(l0, (uint8_t) (int32_t) INT32_C(4), l6, 1371u);
            l6 = vader_parser_advance(l0);
            t0 = vader_parser_span_of(l0, l2, l6);
            vader_struct_toolchain_ast_SeqLitExpr_t* _a2_obj = (vader_struct_toolchain_ast_SeqLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_SeqLitExpr_t));
            vader_obj_header_init(_a2_obj, 465u);
            _a2_obj->f_span = t0;
            _a2_obj->f_id = (size_t) (int64_t) INT64_C(0);
            _a2_obj->f_elements = l3;
            _a2_obj->f_trailing_comma = false;
            t0 = (void*) _a2_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l5 = vader_parser_parse_type(l0);
        vader_array_push((vader_array_t*) l3, l5);
        vader_parser_skip_newlines(l0);
        {
            loop_105: {
                t2 = vader_parser_match_kind(l0, (uint8_t) (int32_t) INT32_C(78));
                if (!(t2.tag == 0u)) {
                    vader_parser_skip_newlines(l0);
                    t1 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(75));
                    if (t1) {
                    } else {
                        l5 = vader_parser_parse_type(l0);
                        vader_array_push((vader_array_t*) l3, l5);
                        vader_parser_skip_newlines(l0);
                        goto loop_105;
                    }
                } else {
                }
            }
        }
        l6 = vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(75), 1026u);
        t3 = ((vader_array_t*) l3)->length;
        if (t3 == INT64_C(1)) {
            l7 = vader_parser_span_of(l0, l2, l6);
            vader_parser_error(l0, (uint8_t) (int32_t) INT32_C(20), l7, 2201u);
            l7 = vader_parser_span_of(l0, l2, l6);
            vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
            if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
            if ((size_t) INT32_C(0) >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
            l5 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) INT32_C(0));
            vader_struct_toolchain_ast_ArrayTypeExpr_t* _a4_obj = (vader_struct_toolchain_ast_ArrayTypeExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ArrayTypeExpr_t));
            vader_obj_header_init(_a4_obj, 399u);
            _a4_obj->f_span = l7;
            _a4_obj->f_id = (size_t) (int64_t) INT64_C(0);
            _a4_obj->f_element = l5;
            t0 = (void*) _a4_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = vader_parser_span_of(l0, l2, l6);
        vader_struct_toolchain_ast_SeqLitExpr_t* _a5_obj = (vader_struct_toolchain_ast_SeqLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_SeqLitExpr_t));
        vader_obj_header_init(_a5_obj, 465u);
        _a5_obj->f_span = t0;
        _a5_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a5_obj->f_elements = l3;
        _a5_obj->f_trailing_comma = false;
        t0 = (void*) _a5_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(33)) {
        vader_parser_advance(l0);
        t0 = vader_parser_ident_expr(((vader_struct_vader_lexer_Token_t*) l1)->f_span, 1787u);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(2)) {
        l2 = vader_parser_advance(l0);
        l3 = ((vader_struct_vader_lexer_Token_t*) l2)->f_span;
        l4 = ((vader_struct_vader_lexer_Token_t*) l2)->f_text;
        t0 = vader_parser_ident_expr(l3, l4);
        l5 = vader_ref_box(t0);
        {
            loop_207: {
                t1 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(79));
                if (t1) {
                    vader_parser_advance(l0);
                    l3 = vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(2), 1462u);
                    t0 = l5.payload.obj;
                    l6 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t0)->f_span)->f_start;
                    l7 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l3)->f_span)->f_end;
                    vader_struct_toolchain_span_Span_t* _a6_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
                    vader_obj_header_init(_a6_obj, 489u);
                    _a6_obj->f_start = l6;
                    _a6_obj->f_end = l7;
                    l8 = (void*) _a6_obj;
                    l4 = ((vader_struct_vader_lexer_Token_t*) l3)->f_text;
                    l9 = ((vader_struct_vader_lexer_Token_t*) l3)->f_span;
                    vader_struct_toolchain_ast_FieldExpr_t* _a7_obj = (vader_struct_toolchain_ast_FieldExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FieldExpr_t));
                    vader_obj_header_init(_a7_obj, 426u);
                    _a7_obj->f_span = l8;
                    _a7_obj->f_id = (size_t) (int64_t) INT64_C(0);
                    _a7_obj->f_target = l5;
                    _a7_obj->f_field = l4;
                    _a7_obj->f_field_span = l9;
                    _a7_obj->f_is_numeric = false;
                    t0 = (void*) _a7_obj;
                    l5 = vader_ref_box(t0);
                    goto loop_207;
                } else {
                }
            }
        }
        t2 = vader_parser_match_kind(l0, (uint8_t) (int32_t) INT32_C(49));
        if (!(t2.tag == 0u)) {
            l3 = vader_parser_parse_type_list_until_angle(l0);
            l10 = -(INT32_C(1));
            l6 = vader_parser_peek_at(l0, l10);
            t0 = vader_parser_span_of(l0, l2, l6);
            vader_struct_toolchain_ast_GenericInstExpr_t* _a8_obj = (vader_struct_toolchain_ast_GenericInstExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_GenericInstExpr_t));
            vader_obj_header_init(_a8_obj, 432u);
            _a8_obj->f_span = t0;
            _a8_obj->f_id = (size_t) (int64_t) INT64_C(0);
            _a8_obj->f_callee = l5;
            _a8_obj->f_type_args = l3;
            t0 = (void*) _a8_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_box_t __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
    l4 = vader_parser_describe_token(l1);
    l4 = concat_2(1516u, l4);
    vader_parser_error(l0, (uint8_t) (int32_t) INT32_C(4), l2, l4);
    vader_parser_advance(l0);
    t0 = vader_parser_ident_expr(((vader_struct_vader_lexer_Token_t*) l1)->f_span, 488u);
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_parser_parse_typed_const_decl(void* l0, void* l1, uint8_t l2) {
    void* l3 = NULL;
    void* l8 = NULL;
    vader_box_t l4 = vader_box_null(), l6 = vader_box_null();
    bool l5;
    int32_t l7;
    vader_string_t l9;
    bool t0;
    void* t1 = NULL;
    vader_string_t t2;
    vader_box_t* gc_roots[2] = { &l4, &l6 };
    void** gc_raw_roots[5] = { &l0, &l1, &l3, &l8, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_parser_reject_target_decorator(l0, l1, 1069u);
    l3 = vader_parser_advance(l0);
    vader_parser_advance(l0);
    l4 = vader_parser_parse_type(l0);
    vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(80), 997u);
    t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(70));
    if (t0) {
        t1 = vader_parser_peek_at(l0, INT32_C(1));
        l5 = ((vader_struct_vader_lexer_Token_t*) t1)->f_kind == INT32_C(2);
    } else {
        l5 = false;
    }
    if (l5) {
        t1 = vader_parser_peek_at(l0, INT32_C(1));
        t2 = ((vader_struct_vader_lexer_Token_t*) t1)->f_text;
        l5 = t2 == 1285u;
    } else {
        l5 = false;
    }
    if (l5) {
        t1 = vader_parser_desugar_comptime_const(l0, l1, l2, l3, l4);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = vader_parser_parse_expr(l0, INT32_C(0));
    l7 = -(INT32_C(1));
    l8 = vader_parser_peek_at(l0, l7);
    l8 = vader_parser_span_of(l0, l3, l8);
    l9 = ((vader_struct_vader_lexer_Token_t*) l3)->f_text;
    l3 = ((vader_struct_vader_lexer_Token_t*) l3)->f_span;
    vader_struct_toolchain_ast_ConstDecl_t* _a0_obj = (vader_struct_toolchain_ast_ConstDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ConstDecl_t));
    vader_obj_header_init(_a0_obj, 412u);
    _a0_obj->f_span = l8;
    _a0_obj->f_id = (size_t) (int64_t) INT64_C(0);
    _a0_obj->f_name = l9;
    _a0_obj->f_name_span = l3;
    _a0_obj->f_visibility = l2;
    _a0_obj->f_ty = l4;
    _a0_obj->f_value = l6;
    _a0_obj->f_decorators = l1;
    _a0_obj->f_comptime_body = vader_box_obj(0u, NULL);
    t1 = (void*) _a0_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_parser_parse_typed_let(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    void* l7 = NULL;
    vader_box_t l2 = vader_box_null(), l5 = vader_box_null();
    bool l4;
    vader_string_t l6;
    int32_t l8;
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l2, &l5 };
    void** gc_raw_roots[5] = { &l0, &l1, &l3, &l7, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_advance(l0);
    vader_parser_advance(l0);
    l2 = vader_parser_parse_type(l0);
    l3 = vader_parser_peek(l0);
    l4 = true;
    if (((vader_struct_vader_lexer_Token_t*) l3)->f_kind == INT32_C(80)) {
        vader_parser_advance(l0);
        l4 = false;
    } else {
        vader_parser_expect(l0, (uint8_t) (int32_t) INT32_C(57), 999u);
    }
    l5 = vader_parser_parse_expr(l0, INT32_C(0));
    l3 = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
    l6 = ((vader_struct_vader_lexer_Token_t*) l1)->f_text;
    l7 = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
    vader_struct_toolchain_ast_SimpleBinding_t* _a0_obj = (vader_struct_toolchain_ast_SimpleBinding_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_SimpleBinding_t));
    vader_obj_header_init(_a0_obj, 466u);
    _a0_obj->f_span = l3;
    _a0_obj->f_id = (size_t) (int64_t) INT64_C(0);
    _a0_obj->f_name = l6;
    _a0_obj->f_name_span = l7;
    l3 = (void*) _a0_obj;
    l8 = -(INT32_C(1));
    l7 = vader_parser_peek_at(l0, l8);
    t0 = vader_parser_span_of(l0, l1, l7);
    vader_struct_toolchain_ast_LetStmt_t* _a1_obj = (vader_struct_toolchain_ast_LetStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_LetStmt_t));
    vader_obj_header_init(_a1_obj, 447u);
    _a1_obj->f_span = t0;
    _a1_obj->f_id = (size_t) (int64_t) INT64_C(0);
    _a1_obj->f_mutable = l4;
    _a1_obj->f_binding = vader_ref_box(l3);
    _a1_obj->f_ty = l2;
    _a1_obj->f_value = l5;
    t0 = (void*) _a1_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_parser_parse_yield(void* l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    vader_box_t l2 = vader_box_null();
    int32_t l3;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[4] = { &l0, &l1, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_advance(l0);
    l2 = vader_parser_parse_expr(l0, INT32_C(0));
    l3 = -(INT32_C(1));
    l4 = vader_parser_peek_at(l0, l3);
    t0 = vader_parser_span_of(l0, l1, l4);
    vader_struct_toolchain_ast_YieldStmt_t* _a0_obj = (vader_struct_toolchain_ast_YieldStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_YieldStmt_t));
    vader_obj_header_init(_a0_obj, 487u);
    _a0_obj->f_span = t0;
    _a0_obj->f_id = (size_t) (int64_t) INT64_C(0);
    _a0_obj->f_value = l2;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_parser_peek(void* l0) {
    vader_box_t l1;
    int32_t l2;
    void* l3;
    size_t l4;
    void* t0;
    size_t t1;
    int32_t t2;
    int64_t t3;
    l1 = ((vader_struct_vader_parser_Parser_t*) l0)->f_shr_pending_half;
    if (!(l1.tag == 0u)) {
        t0 = l1.payload.obj;
        return t0;
    }
    t1 = ((vader_array_t*) ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens)->length;
    l2 = ((int32_t) (size_t) t1);
    t2 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pos;
    if ((t2 < l2)) {
        l3 = ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens;
        t2 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pos;
        t3 = ((int64_t) (int32_t) t2);
        l4 = (size_t) (int64_t) t3;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
        if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        return t0;
    }
    l3 = ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens;
    t3 = ((int64_t) (int32_t) (l2 - INT32_C(1)));
    l4 = (size_t) (int64_t) t3;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
    if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
    t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
    return t0;
}

void* vader_parser_peek_at(void* l0, int32_t l1) {
    int32_t l2, l3;
    void* l4;
    size_t l5;
    size_t t0;
    int32_t t1;
    void* t2;
    int64_t t3;
    t0 = ((vader_array_t*) ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens)->length;
    l2 = ((int32_t) (size_t) t0);
    t1 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pos;
    l3 = (t1 + l1);
    if ((l3 < INT32_C(0))) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens);
        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
        if ((size_t) INT32_C(0) >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
        t2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
        return t2;
    }
    if ((l3 < l2)) {
        l4 = ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens;
        t3 = ((int64_t) (int32_t) l3);
        l5 = (size_t) (int64_t) t3;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
        if ((size_t) l5 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
        t2 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
        return t2;
    }
    l4 = ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens;
    t3 = ((int64_t) (int32_t) (l2 - INT32_C(1)));
    l5 = (size_t) (int64_t) t3;
    vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
    if ((size_t) l5 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
    t2 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
    return t2;
}

bool vader_parser_peek_is_classic_impl_body(void* l0) {
    int32_t l1, l4;
    bool l2, l5;
    uint8_t l3, l6;
    void* t0;
    l1 = INT32_C(1);
    {
        loop_3: {
            t0 = vader_parser_peek_at(l0, l1);
            if (((vader_struct_vader_lexer_Token_t*) t0)->f_kind == INT32_C(1)) {
                l1 = (l1 + INT32_C(1));
                goto loop_3;
            } else {
            }
        }
    }
    l2 = true;
    {
        loop_23: {
            if (l2) {
                t0 = vader_parser_peek_at(l0, l1);
                l3 = ((vader_struct_vader_lexer_Token_t*) t0)->f_kind;
                if (l3 == INT32_C(70)) {
                    l1 = (l1 + INT32_C(1));
                    t0 = vader_parser_peek_at(l0, l1);
                    if (((vader_struct_vader_lexer_Token_t*) t0)->f_kind == INT32_C(2)) {
                        l1 = (l1 + INT32_C(1));
                    } else {
                    }
                    t0 = vader_parser_peek_at(l0, l1);
                    if (((vader_struct_vader_lexer_Token_t*) t0)->f_kind == INT32_C(72)) {
                        l4 = INT32_C(1);
                        l1 = (l1 + INT32_C(1));
                        {
                            loop_65: {
                                if ((l4 > INT32_C(0))) {
                                    t0 = vader_parser_peek_at(l0, l1);
                                    l5 = ((vader_struct_vader_lexer_Token_t*) t0)->f_kind != INT32_C(0);
                                } else {
                                    l5 = false;
                                }
                                if (l5) {
                                    t0 = vader_parser_peek_at(l0, l1);
                                    l6 = ((vader_struct_vader_lexer_Token_t*) t0)->f_kind;
                                    if (l6 == INT32_C(72)) {
                                        l4 = (l4 + INT32_C(1));
                                    } else {
                                    }
                                    if (l6 == INT32_C(73)) {
                                        l4 = (l4 - INT32_C(1));
                                    } else {
                                    }
                                    l1 = (l1 + INT32_C(1));
                                    goto loop_65;
                                } else {
                                }
                            }
                        }
                    } else {
                    }
                    {
                        loop_119: {
                            t0 = vader_parser_peek_at(l0, l1);
                            if (((vader_struct_vader_lexer_Token_t*) t0)->f_kind == INT32_C(1)) {
                                l1 = (l1 + INT32_C(1));
                                goto loop_119;
                            } else {
                            }
                        }
                    }
                } else {
                    if (l3 == INT32_C(30)) {
                        l1 = (l1 + INT32_C(1));
                        {
                            loop_146: {
                                t0 = vader_parser_peek_at(l0, l1);
                                if (((vader_struct_vader_lexer_Token_t*) t0)->f_kind == INT32_C(1)) {
                                    l1 = (l1 + INT32_C(1));
                                    goto loop_146;
                                } else {
                                }
                            }
                        }
                    } else {
                        l2 = false;
                    }
                }
                goto loop_23;
            } else {
            }
        }
    }
    t0 = vader_parser_peek_at(l0, l1);
    if (((vader_struct_vader_lexer_Token_t*) t0)->f_kind == INT32_C(2)) {
        l4 = (l1 + INT32_C(1));
        t0 = vader_parser_peek_at(l0, l4);
        l2 = ((vader_struct_vader_lexer_Token_t*) t0)->f_kind == INT32_C(63);
    } else {
        l2 = false;
    }
    if (l2) {
        l1 = (l1 + INT32_C(2));
        t0 = vader_parser_peek_at(l0, l1);
        l2 = ((vader_struct_vader_lexer_Token_t*) t0)->f_kind == INT32_C(11);
    } else {
        l2 = false;
    }
    return l2;
}

bool vader_parser_peek_is_lhs_generic_alias_head(void* l0) {
    int32_t l1, l2, l3, l4, l20;
    void* l5;
    void* l7;
    void* l11;
    void* l14;
    size_t l6, l12, l15;
    bool l8, l9, l10, l13, l16, l17, l18, l19;
    size_t t0;
    int32_t t1;
    int64_t t2;
    void* t3;
    t0 = ((vader_array_t*) ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens)->length;
    l1 = ((int32_t) (size_t) t0);
    l2 = INT32_C(1);
    l3 = INT32_C(0);
    t1 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pos;
    l4 = (t1 + INT32_C(2));
    {
        loop_14: {
            if ((l4 < l1)) {
                l5 = ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens;
                t2 = ((int64_t) (int32_t) l4);
                l6 = (size_t) (int64_t) t2;
                vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l6 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l7 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
                if (((vader_struct_vader_lexer_Token_t*) l7)->f_kind == INT32_C(0)) {
                    l8 = true;
                } else {
                    l8 = ((vader_struct_vader_lexer_Token_t*) l7)->f_kind == INT32_C(1);
                }
                if (l8) {
                    return false;
                }
                if (((vader_struct_vader_lexer_Token_t*) l7)->f_kind == INT32_C(49)) {
                    l9 = l3 == INT32_C(0);
                } else {
                    l9 = false;
                }
                if (l9) {
                    l2 = (l2 + INT32_C(1));
                    l20 = INT32_C(1);
                    l4 = (l4 + l20);
                    goto loop_14;
                }
                if (((vader_struct_vader_lexer_Token_t*) l7)->f_kind == INT32_C(51)) {
                    l10 = l3 == INT32_C(0);
                } else {
                    l10 = false;
                }
                if (l10) {
                    l2 = (l2 - INT32_C(1));
                    if (l2 == INT32_C(0)) {
                        if (((l4 + INT32_C(1)) < l1)) {
                            l11 = ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens;
                            t2 = ((int64_t) (int32_t) (l4 + INT32_C(1)));
                            l12 = (size_t) (int64_t) t2;
                            vader_array_t* _a1_slotarr = ((vader_array_t*) l11);
                            if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                            if ((size_t) l12 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                            t3 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l12);
                            return ((vader_struct_vader_lexer_Token_t*) t3)->f_kind == INT32_C(63);
                        }
                        return false;
                    }
                    l20 = INT32_C(1);
                    l4 = (l4 + l20);
                    goto loop_14;
                }
                if (((vader_struct_vader_lexer_Token_t*) l7)->f_kind == INT32_C(46)) {
                    l13 = l3 == INT32_C(0);
                } else {
                    l13 = false;
                }
                if (l13) {
                    l2 = (l2 - INT32_C(2));
                    if (l2 == INT32_C(0)) {
                        if (((l4 + INT32_C(1)) < l1)) {
                            l14 = ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens;
                            t2 = ((int64_t) (int32_t) (l4 + INT32_C(1)));
                            l15 = (size_t) (int64_t) t2;
                            vader_array_t* _a2_slotarr = ((vader_array_t*) l14);
                            if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                            if ((size_t) l15 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                            t3 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l15);
                            return ((vader_struct_vader_lexer_Token_t*) t3)->f_kind == INT32_C(63);
                        }
                        return false;
                    }
                    if ((l2 < INT32_C(0))) {
                        return false;
                    }
                    l20 = INT32_C(1);
                    l4 = (l4 + l20);
                    goto loop_14;
                }
                if (((vader_struct_vader_lexer_Token_t*) l7)->f_kind == INT32_C(72)) {
                    l16 = true;
                } else {
                    l16 = ((vader_struct_vader_lexer_Token_t*) l7)->f_kind == INT32_C(74);
                }
                if (l16) {
                    l17 = true;
                } else {
                    l17 = ((vader_struct_vader_lexer_Token_t*) l7)->f_kind == INT32_C(76);
                }
                if (l17) {
                    l3 = (l3 + INT32_C(1));
                    l20 = INT32_C(1);
                    l4 = (l4 + l20);
                    goto loop_14;
                }
                if (((vader_struct_vader_lexer_Token_t*) l7)->f_kind == INT32_C(73)) {
                    l18 = true;
                } else {
                    l18 = ((vader_struct_vader_lexer_Token_t*) l7)->f_kind == INT32_C(75);
                }
                if (l18) {
                    l19 = true;
                } else {
                    l19 = ((vader_struct_vader_lexer_Token_t*) l7)->f_kind == INT32_C(77);
                }
                if (l19) {
                    l3 = (l3 - INT32_C(1));
                    if ((l3 < INT32_C(0))) {
                        return false;
                    }
                    l20 = INT32_C(1);
                    l4 = (l4 + l20);
                    goto loop_14;
                }
                l20 = INT32_C(1);
                l4 = (l4 + l20);
                goto loop_14;
            } else {
            }
        }
    }
    return false;
}

bool vader_parser_peek_lambda_without_fn(void* l0) {
    int32_t l1, l2, l4;
    uint8_t l3;
    void* t0;
    t0 = vader_parser_peek(l0);
    if (((vader_struct_vader_lexer_Token_t*) t0)->f_kind != INT32_C(72)) {
        return false;
    }
    l1 = INT32_C(1);
    l2 = INT32_C(1);
    {
        loop_13: {
            if ((l1 > INT32_C(0))) {
                t0 = vader_parser_peek_at(l0, l2);
                l3 = ((vader_struct_vader_lexer_Token_t*) t0)->f_kind;
                if (l3 == INT32_C(0)) {
                    return false;
                }
                if (l3 == INT32_C(72)) {
                    l1 = (l1 + INT32_C(1));
                    l4 = INT32_C(1);
                    l2 = (l2 + l4);
                    goto loop_13;
                }
                if (l3 == INT32_C(73)) {
                    l1 = (l1 - INT32_C(1));
                    if (l1 == INT32_C(0)) {
                    } else {
                        l4 = INT32_C(1);
                        l2 = (l2 + l4);
                        goto loop_13;
                    }
                } else {
                    l4 = INT32_C(1);
                    l2 = (l2 + l4);
                    goto loop_13;
                }
            } else {
            }
        }
    }
    l2 = (l2 + INT32_C(1));
    {
        loop_82: {
            t0 = vader_parser_peek_at(l0, l2);
            if (((vader_struct_vader_lexer_Token_t*) t0)->f_kind == INT32_C(1)) {
                l2 = (l2 + INT32_C(1));
                goto loop_82;
            } else {
            }
        }
    }
    t0 = vader_parser_peek_at(l0, l2);
    return ((vader_struct_vader_lexer_Token_t*) t0)->f_kind == INT32_C(68);
}

bool vader_parser_peek_tuple_let_start(void* l0) {
    int32_t l1, l2, l3, l8, l9, l10, l11, l17;
    bool l4, l12, l22, l24;
    void* l5;
    void* l13;
    void* l18;
    size_t l6, l14, l19;
    uint8_t l7, l15, l16, l20, l21, l23, l25;
    int32_t t0;
    size_t t1;
    int64_t t2;
    void* t3;
    l1 = INT32_C(1);
    t0 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pos;
    l2 = (t0 + INT32_C(1));
    t1 = ((vader_array_t*) ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens)->length;
    l3 = ((int32_t) (size_t) t1);
    {
        loop_12: {
            if ((l2 < l3)) {
                l4 = (l1 > INT32_C(0));
            } else {
                l4 = false;
            }
            if (l4) {
                l5 = ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens;
                t2 = ((int64_t) (int32_t) l2);
                l6 = (size_t) (int64_t) t2;
                vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l6 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t3 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
                l7 = ((vader_struct_vader_lexer_Token_t*) t3)->f_kind;
                if (l7 == INT32_C(0)) {
                } else {
                    if (l7 == INT32_C(74)) {
                        l1 = (l1 + INT32_C(1));
                        l8 = INT32_C(1);
                        l2 = (l2 + l8);
                        goto loop_12;
                    }
                    if (l7 == INT32_C(75)) {
                        l1 = (l1 - INT32_C(1));
                        if (l1 == INT32_C(0)) {
                            l9 = INT32_C(0);
                            if (l1 != l9) {
                                return false;
                            }
                            l10 = INT32_C(1);
                            l11 = (l2 + l10);
                            {
                                loop_83: {
                                    if ((l11 < l3)) {
                                        l13 = ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens;
                                        t2 = ((int64_t) (int32_t) l11);
                                        l14 = (size_t) (int64_t) t2;
                                        vader_array_t* _a1_slotarr = ((vader_array_t*) l13);
                                        if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                                        if ((size_t) l14 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                                        t3 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l14);
                                        l15 = ((vader_struct_vader_lexer_Token_t*) t3)->f_kind;
                                        l16 = (uint8_t) (int32_t) INT32_C(1);
                                        l12 = l15 == l16;
                                    } else {
                                        l12 = false;
                                    }
                                    if (l12) {
                                        l17 = INT32_C(1);
                                        l11 = (l11 + l17);
                                        goto loop_83;
                                    } else {
                                    }
                                }
                            }
                            if ((l11 >= l3)) {
                                return false;
                            }
                            l18 = ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens;
                            t2 = ((int64_t) (int32_t) l11);
                            l19 = (size_t) (int64_t) t2;
                            vader_array_t* _a2_slotarr = ((vader_array_t*) l18);
                            if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                            if ((size_t) l19 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                            t3 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l19);
                            l20 = ((vader_struct_vader_lexer_Token_t*) t3)->f_kind;
                            l21 = (uint8_t) (int32_t) INT32_C(63);
                            if (l20 == l21) {
                                l22 = true;
                            } else {
                                l23 = (uint8_t) (int32_t) INT32_C(64);
                                l22 = l20 == l23;
                            }
                            if (l22) {
                                l24 = true;
                            } else {
                                l25 = (uint8_t) (int32_t) INT32_C(80);
                                l24 = l20 == l25;
                            }
                            return l24;
                        }
                        l8 = INT32_C(1);
                        l2 = (l2 + l8);
                        goto loop_12;
                    }
                    l8 = INT32_C(1);
                    l2 = (l2 + l8);
                    goto loop_12;
                }
            } else {
                l9 = INT32_C(0);
                if (l1 != l9) {
                    return false;
                }
                l10 = INT32_C(1);
                l11 = (l2 + l10);
                {
                    loop_200: {
                        if ((l11 < l3)) {
                            l13 = ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens;
                            t2 = ((int64_t) (int32_t) l11);
                            l14 = (size_t) (int64_t) t2;
                            vader_array_t* _a3_slotarr = ((vader_array_t*) l13);
                            if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                            if ((size_t) l14 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                            t3 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l14);
                            l15 = ((vader_struct_vader_lexer_Token_t*) t3)->f_kind;
                            l16 = (uint8_t) (int32_t) INT32_C(1);
                            l12 = l15 == l16;
                        } else {
                            l12 = false;
                        }
                        if (l12) {
                            l17 = INT32_C(1);
                            l11 = (l11 + l17);
                            goto loop_200;
                        } else {
                        }
                    }
                }
                if ((l11 >= l3)) {
                    return false;
                }
                l18 = ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens;
                t2 = ((int64_t) (int32_t) l11);
                l19 = (size_t) (int64_t) t2;
                vader_array_t* _a4_slotarr = ((vader_array_t*) l18);
                if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                if ((size_t) l19 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                t3 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l19);
                l20 = ((vader_struct_vader_lexer_Token_t*) t3)->f_kind;
                l21 = (uint8_t) (int32_t) INT32_C(63);
                if (l20 == l21) {
                    l22 = true;
                } else {
                    l23 = (uint8_t) (int32_t) INT32_C(64);
                    l22 = l20 == l23;
                }
                if (l22) {
                    l24 = true;
                } else {
                    l25 = (uint8_t) (int32_t) INT32_C(80);
                    l24 = l20 == l25;
                }
                return l24;
            }
        }
    }
    return false;
}

int32_t vader_parser_postfix_bp(uint8_t l0) {
    if (l0 == INT32_C(72)) {
        return INT32_C(100);
    }
    if (l0 == INT32_C(74)) {
        return INT32_C(100);
    }
    if (l0 == INT32_C(79)) {
        return INT32_C(100);
    }
    if (l0 == INT32_C(35)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(0)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(1)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(2)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(3)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(4)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(5)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(6)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(7)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(8)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(9)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(10)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(36)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(37)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(38)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(39)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(40)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(41)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(42)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(43)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(44)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(45)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(46)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(47)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(48)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(49)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(50)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(51)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(52)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(53)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(54)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(56)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(55)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(57)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(58)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(59)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(60)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(61)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(62)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(63)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(64)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(65)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(66)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(67)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(68)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(69)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(70)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(71)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(73)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(75)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(76)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(77)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(78)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(80)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(11)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(12)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(13)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(14)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(15)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(16)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(17)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(18)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(19)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(20)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(21)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(22)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(23)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(24)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(25)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(26)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(27)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(28)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(29)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(30)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(31)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(32)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(33)) {
        return -(INT32_C(1));
    }
    if (l0 == INT32_C(34)) {
        return -(INT32_C(1));
    }
    vader_unreachable("unreachable return in vader_parser$postfix_bp");
}

void vader_parser_reject_removed_const(void* l0) {
    vader_box_t l1 = vader_box_null();
    void* l2 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_match_kind(l0, (uint8_t) (int32_t) INT32_C(35));
    if (!(l1.tag == 0u)) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_lexer_Token_t*) t0)->f_span;
        vader_parser_error(l0, (uint8_t) (int32_t) INT32_C(23), l2, 1080u);
    } else {
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void vader_parser_reject_target_decorator(void* l0, void* l1, vader_string_t l2) {
    void* l3 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    size_t l4, l5;
    vader_string_t l8;
    vader_string_t t0;
    int64_t t1;
    void** gc_raw_roots[5] = { &l0, &l1, &l3, &l6, &l7 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = l1;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_7: {
            if ((l5 < l4)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l5 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l6 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
                t0 = ((vader_struct_toolchain_ast_Decorator_t*) l6)->f_name;
                if (t0 == 2048u) {
                    l7 = ((vader_struct_toolchain_ast_Decorator_t*) l6)->f_span;
                    l8 = concat_2(1022u, l2);
                    vader_parser_error(l0, (uint8_t) (int32_t) INT32_C(13), l7, l8);
                } else {
                }
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_7;
            } else {
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void vader_parser_report_nesting_too_deep(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    vader_string_t l4;
    size_t l5;
    int64_t l7;
    bool l8;
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[5] = { &l0, &l2, &l3, &l6, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_parser_Parser_t*) l0)->f_depth_exceeded;
    if (t0) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l2 = ((vader_struct_vader_parser_Parser_t*) l0)->f_errors;
    t1 = vader_parser_peek(l0);
    l3 = ((vader_struct_vader_lexer_Token_t*) t1)->f_span;
    l4 = l1;
    l5 = vader_import_0(l4);
    l6 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(50) + l5));
    l5 = (size_t) (int64_t) INT64_C(0);
    l5 = std_core_write_string_at(l6, l5, l4);
    l5 = std_core_write_string_at(l6, l5, 128u);
    l7 = ((int64_t) (int32_t) INT32_C(256));
    l5 = std_core_write_int(l6, l5, l7);
    l5 = std_core_write_string_at(l6, l5, 123u);
    l4 = std_core_finish_buffer(l6, l5);
    l3 = vader_diagnostics_parser_error((uint8_t) (int32_t) INT32_C(25), l3, l4);
    vader_array_push((vader_array_t*) l2, vader_ref_box(l3));
    ((vader_struct_vader_parser_Parser_t*) l0)->f_depth_exceeded = true;
    VADER_WRITE_BARRIER((vader_struct_vader_parser_Parser_t*) l0);
    {
        loop_61: {
            t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(1));
            if (!(t0)) {
                t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(0));
                l8 = !(t0);
            } else {
                l8 = false;
            }
            if (l8) {
                vader_parser_advance(l0);
                goto loop_61;
            } else {
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

bool vader_parser_scan_angle_generic(void* l0, int32_t l1) {
    int32_t l2, l6, l7, l8, l9, l23, l26, l27, l30, l33, l34, l35;
    bool l3, l11, l12, l16, l20;
    void* l4;
    void* l10;
    void* l13;
    void* l17;
    size_t l5, l14, l18;
    uint8_t l15, l19, l21, l22, l24, l25, l28, l29, l31, l32;
    size_t t0;
    int64_t t1;
    void* t2;
    t0 = ((vader_array_t*) ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens)->length;
    l2 = ((int32_t) (size_t) t0);
    if ((l1 >= l2)) {
        l3 = true;
    } else {
        l4 = ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens;
        t1 = ((int64_t) (int32_t) l1);
        l5 = (size_t) (int64_t) t1;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
        if ((size_t) l5 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
        t2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        l3 = ((vader_struct_vader_lexer_Token_t*) t2)->f_kind != INT32_C(49);
    }
    if (l3) {
        return false;
    }
    l6 = INT32_C(1);
    l7 = INT32_C(0);
    l8 = INT32_C(0);
    l9 = (l1 + INT32_C(1));
    {
        loop_39: {
            if ((l9 < l2)) {
                l4 = ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens;
                t1 = ((int64_t) (int32_t) l9);
                l5 = (size_t) (int64_t) t1;
                vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l5 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                l10 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
                if (((vader_struct_vader_lexer_Token_t*) l10)->f_kind == INT32_C(0)) {
                    return false;
                }
                if (l7 == INT32_C(0)) {
                    l3 = l8 == INT32_C(0);
                } else {
                    l3 = false;
                }
                if (((vader_struct_vader_lexer_Token_t*) l10)->f_kind == INT32_C(1)) {
                    l11 = l3;
                } else {
                    l11 = false;
                }
                if (l11) {
                    return false;
                }
                if (l3) {
                    l12 = vader_parser_is_angle_scan_bailout(((vader_struct_vader_lexer_Token_t*) l10)->f_kind);
                } else {
                    l12 = false;
                }
                if (l12) {
                    return false;
                }
                if (l3) {
                    if (((vader_struct_vader_lexer_Token_t*) l10)->f_kind == INT32_C(49)) {
                        l6 = (l6 + INT32_C(1));
                        l21 = ((vader_struct_vader_lexer_Token_t*) l10)->f_kind;
                        l22 = (uint8_t) (int32_t) INT32_C(72);
                        if (l21 == l22) {
                            l23 = INT32_C(1);
                            l7 = (l7 + l23);
                            l35 = INT32_C(1);
                            l9 = (l9 + l35);
                            goto loop_39;
                        }
                        l24 = ((vader_struct_vader_lexer_Token_t*) l10)->f_kind;
                        l25 = (uint8_t) (int32_t) INT32_C(73);
                        if (l24 == l25) {
                            l26 = INT32_C(0);
                            if (l7 == l26) {
                                return false;
                            }
                            l27 = INT32_C(1);
                            l7 = (l7 - l27);
                            l35 = INT32_C(1);
                            l9 = (l9 + l35);
                            goto loop_39;
                        }
                        l28 = ((vader_struct_vader_lexer_Token_t*) l10)->f_kind;
                        l29 = (uint8_t) (int32_t) INT32_C(74);
                        if (l28 == l29) {
                            l30 = INT32_C(1);
                            l8 = (l8 + l30);
                            l35 = INT32_C(1);
                            l9 = (l9 + l35);
                            goto loop_39;
                        }
                        l31 = ((vader_struct_vader_lexer_Token_t*) l10)->f_kind;
                        l32 = (uint8_t) (int32_t) INT32_C(75);
                        if (l31 == l32) {
                            l33 = INT32_C(0);
                            if (l8 == l33) {
                                return false;
                            }
                            l34 = INT32_C(1);
                            l8 = (l8 - l34);
                            l35 = INT32_C(1);
                            l9 = (l9 + l35);
                            goto loop_39;
                        }
                        l35 = INT32_C(1);
                        l9 = (l9 + l35);
                        goto loop_39;
                    }
                    if (((vader_struct_vader_lexer_Token_t*) l10)->f_kind == INT32_C(51)) {
                        l6 = (l6 - INT32_C(1));
                        if (l6 == INT32_C(0)) {
                            if (((l9 + INT32_C(1)) >= l2)) {
                                return false;
                            }
                            l13 = ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens;
                            t1 = ((int64_t) (int32_t) (l9 + INT32_C(1)));
                            l14 = (size_t) (int64_t) t1;
                            vader_array_t* _a2_slotarr = ((vader_array_t*) l13);
                            if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                            if ((size_t) l14 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                            t2 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l14);
                            l15 = ((vader_struct_vader_lexer_Token_t*) t2)->f_kind;
                            if (l15 == INT32_C(72)) {
                                l16 = true;
                            } else {
                                l16 = l15 == INT32_C(76);
                            }
                            return l16;
                        }
                        l21 = ((vader_struct_vader_lexer_Token_t*) l10)->f_kind;
                        l22 = (uint8_t) (int32_t) INT32_C(72);
                        if (l21 == l22) {
                            l23 = INT32_C(1);
                            l7 = (l7 + l23);
                            l35 = INT32_C(1);
                            l9 = (l9 + l35);
                            goto loop_39;
                        }
                        l24 = ((vader_struct_vader_lexer_Token_t*) l10)->f_kind;
                        l25 = (uint8_t) (int32_t) INT32_C(73);
                        if (l24 == l25) {
                            l26 = INT32_C(0);
                            if (l7 == l26) {
                                return false;
                            }
                            l27 = INT32_C(1);
                            l7 = (l7 - l27);
                            l35 = INT32_C(1);
                            l9 = (l9 + l35);
                            goto loop_39;
                        }
                        l28 = ((vader_struct_vader_lexer_Token_t*) l10)->f_kind;
                        l29 = (uint8_t) (int32_t) INT32_C(74);
                        if (l28 == l29) {
                            l30 = INT32_C(1);
                            l8 = (l8 + l30);
                            l35 = INT32_C(1);
                            l9 = (l9 + l35);
                            goto loop_39;
                        }
                        l31 = ((vader_struct_vader_lexer_Token_t*) l10)->f_kind;
                        l32 = (uint8_t) (int32_t) INT32_C(75);
                        if (l31 == l32) {
                            l33 = INT32_C(0);
                            if (l8 == l33) {
                                return false;
                            }
                            l34 = INT32_C(1);
                            l8 = (l8 - l34);
                            l35 = INT32_C(1);
                            l9 = (l9 + l35);
                            goto loop_39;
                        }
                        l35 = INT32_C(1);
                        l9 = (l9 + l35);
                        goto loop_39;
                    }
                    if (((vader_struct_vader_lexer_Token_t*) l10)->f_kind == INT32_C(46)) {
                        l6 = (l6 - INT32_C(2));
                        if (l6 == INT32_C(0)) {
                            if (((l9 + INT32_C(1)) >= l2)) {
                                return false;
                            }
                            l17 = ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens;
                            t1 = ((int64_t) (int32_t) (l9 + INT32_C(1)));
                            l18 = (size_t) (int64_t) t1;
                            vader_array_t* _a3_slotarr = ((vader_array_t*) l17);
                            if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                            if ((size_t) l18 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                            t2 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l18);
                            l19 = ((vader_struct_vader_lexer_Token_t*) t2)->f_kind;
                            if (l19 == INT32_C(72)) {
                                l20 = true;
                            } else {
                                l20 = l19 == INT32_C(76);
                            }
                            return l20;
                        }
                        if ((l6 < INT32_C(0))) {
                            return false;
                        }
                        l21 = ((vader_struct_vader_lexer_Token_t*) l10)->f_kind;
                        l22 = (uint8_t) (int32_t) INT32_C(72);
                        if (l21 == l22) {
                            l23 = INT32_C(1);
                            l7 = (l7 + l23);
                            l35 = INT32_C(1);
                            l9 = (l9 + l35);
                            goto loop_39;
                        }
                        l24 = ((vader_struct_vader_lexer_Token_t*) l10)->f_kind;
                        l25 = (uint8_t) (int32_t) INT32_C(73);
                        if (l24 == l25) {
                            l26 = INT32_C(0);
                            if (l7 == l26) {
                                return false;
                            }
                            l27 = INT32_C(1);
                            l7 = (l7 - l27);
                            l35 = INT32_C(1);
                            l9 = (l9 + l35);
                            goto loop_39;
                        }
                        l28 = ((vader_struct_vader_lexer_Token_t*) l10)->f_kind;
                        l29 = (uint8_t) (int32_t) INT32_C(74);
                        if (l28 == l29) {
                            l30 = INT32_C(1);
                            l8 = (l8 + l30);
                            l35 = INT32_C(1);
                            l9 = (l9 + l35);
                            goto loop_39;
                        }
                        l31 = ((vader_struct_vader_lexer_Token_t*) l10)->f_kind;
                        l32 = (uint8_t) (int32_t) INT32_C(75);
                        if (l31 == l32) {
                            l33 = INT32_C(0);
                            if (l8 == l33) {
                                return false;
                            }
                            l34 = INT32_C(1);
                            l8 = (l8 - l34);
                            l35 = INT32_C(1);
                            l9 = (l9 + l35);
                            goto loop_39;
                        }
                        l35 = INT32_C(1);
                        l9 = (l9 + l35);
                        goto loop_39;
                    }
                    l21 = ((vader_struct_vader_lexer_Token_t*) l10)->f_kind;
                    l22 = (uint8_t) (int32_t) INT32_C(72);
                    if (l21 == l22) {
                        l23 = INT32_C(1);
                        l7 = (l7 + l23);
                        l35 = INT32_C(1);
                        l9 = (l9 + l35);
                        goto loop_39;
                    }
                    l24 = ((vader_struct_vader_lexer_Token_t*) l10)->f_kind;
                    l25 = (uint8_t) (int32_t) INT32_C(73);
                    if (l24 == l25) {
                        l26 = INT32_C(0);
                        if (l7 == l26) {
                            return false;
                        }
                        l27 = INT32_C(1);
                        l7 = (l7 - l27);
                        l35 = INT32_C(1);
                        l9 = (l9 + l35);
                        goto loop_39;
                    }
                    l28 = ((vader_struct_vader_lexer_Token_t*) l10)->f_kind;
                    l29 = (uint8_t) (int32_t) INT32_C(74);
                    if (l28 == l29) {
                        l30 = INT32_C(1);
                        l8 = (l8 + l30);
                        l35 = INT32_C(1);
                        l9 = (l9 + l35);
                        goto loop_39;
                    }
                    l31 = ((vader_struct_vader_lexer_Token_t*) l10)->f_kind;
                    l32 = (uint8_t) (int32_t) INT32_C(75);
                    if (l31 == l32) {
                        l33 = INT32_C(0);
                        if (l8 == l33) {
                            return false;
                        }
                        l34 = INT32_C(1);
                        l8 = (l8 - l34);
                        l35 = INT32_C(1);
                        l9 = (l9 + l35);
                        goto loop_39;
                    }
                    l35 = INT32_C(1);
                    l9 = (l9 + l35);
                    goto loop_39;
                }
                l21 = ((vader_struct_vader_lexer_Token_t*) l10)->f_kind;
                l22 = (uint8_t) (int32_t) INT32_C(72);
                if (l21 == l22) {
                    l23 = INT32_C(1);
                    l7 = (l7 + l23);
                    l35 = INT32_C(1);
                    l9 = (l9 + l35);
                    goto loop_39;
                }
                l24 = ((vader_struct_vader_lexer_Token_t*) l10)->f_kind;
                l25 = (uint8_t) (int32_t) INT32_C(73);
                if (l24 == l25) {
                    l26 = INT32_C(0);
                    if (l7 == l26) {
                        return false;
                    }
                    l27 = INT32_C(1);
                    l7 = (l7 - l27);
                    l35 = INT32_C(1);
                    l9 = (l9 + l35);
                    goto loop_39;
                }
                l28 = ((vader_struct_vader_lexer_Token_t*) l10)->f_kind;
                l29 = (uint8_t) (int32_t) INT32_C(74);
                if (l28 == l29) {
                    l30 = INT32_C(1);
                    l8 = (l8 + l30);
                    l35 = INT32_C(1);
                    l9 = (l9 + l35);
                    goto loop_39;
                }
                l31 = ((vader_struct_vader_lexer_Token_t*) l10)->f_kind;
                l32 = (uint8_t) (int32_t) INT32_C(75);
                if (l31 == l32) {
                    l33 = INT32_C(0);
                    if (l8 == l33) {
                        return false;
                    }
                    l34 = INT32_C(1);
                    l8 = (l8 - l34);
                    l35 = INT32_C(1);
                    l9 = (l9 + l35);
                    goto loop_39;
                }
                l35 = INT32_C(1);
                l9 = (l9 + l35);
                goto loop_39;
            } else {
            }
        }
    }
    return false;
}

size_t vader_parser_skip_block_comment(void* l0, size_t l1, size_t l2) {
    size_t l3, l7;
    int32_t l4;
    bool l5, l9, l10;
    uint8_t l6, l8;
    vader_box_t t0;
    int64_t t1;
    l3 = l1;
    l4 = INT32_C(1);
    {
        loop_5: {
            if (((l3 + INT64_C(1)) < l2)) {
                l5 = (l4 > INT32_C(0));
            } else {
                l5 = false;
            }
            if (l5) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l3, 166u);
                l6 = ((uint8_t) t0.payload.i);
                t1 = (l3 + INT64_C(1));
                l7 = (size_t) (int64_t) t1;
                if ((size_t) l7 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l7, 166u);
                l8 = ((uint8_t) t0.payload.i);
                if (l6 == INT32_C(47)) {
                    l9 = l8 == INT32_C(42);
                } else {
                    l9 = false;
                }
                if (l9) {
                    l4 = (l4 + INT32_C(1));
                    t1 = (l3 + INT64_C(2));
                    l3 = (size_t) (int64_t) t1;
                    goto loop_5;
                }
                if (l6 == INT32_C(42)) {
                    l10 = l8 == INT32_C(47);
                } else {
                    l10 = false;
                }
                if (l10) {
                    l4 = (l4 - INT32_C(1));
                    t1 = (l3 + INT64_C(2));
                    l3 = (size_t) (int64_t) t1;
                    goto loop_5;
                }
                t1 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t1;
                goto loop_5;
            } else {
            }
        }
    }
    return l3;
}

void vader_parser_skip_newlines(void* l0) {
    int32_t l1;
    bool t0;
    int32_t t1;
    {
        loop_1: {
            t0 = vader_parser_check(l0, (uint8_t) (int32_t) INT32_C(1));
            if (t0) {
                t1 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pos;
                l1 = (t1 + INT32_C(1));
                ((vader_struct_vader_parser_Parser_t*) l0)->f_pos = l1;
                VADER_WRITE_BARRIER((vader_struct_vader_parser_Parser_t*) l0);
                goto loop_1;
            } else {
            }
        }
    }
    return;
}

size_t vader_parser_skip_to_eol(void* l0, size_t l1, size_t l2) {
    size_t l3;
    bool l4;
    vader_box_t t0;
    uint8_t t1;
    int64_t t2;
    l3 = l1;
    {
        loop_3: {
            if ((l3 < l2)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l3, 166u);
                t1 = ((uint8_t) t0.payload.i);
                l4 = t1 != INT32_C(10);
            } else {
                l4 = false;
            }
            if (l4) {
                t2 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t2;
                goto loop_3;
            } else {
            }
        }
    }
    if ((l3 < l2)) {
        t2 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t2;
    } else {
    }
    return l3;
}

void* vader_parser_span_of(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l1)->f_span)->f_start;
    l4 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l2)->f_span)->f_end;
    vader_struct_toolchain_span_Span_t* _a0_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a0_obj, 489u);
    _a0_obj->f_start = l3;
    _a0_obj->f_end = l4;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void vader_parser_sync_to_top_level(void* l0) {
    bool l1;
    void* t0;
    bool t1;
    {
        loop_1: {
            t0 = vader_parser_peek(l0);
            if (((vader_struct_vader_lexer_Token_t*) t0)->f_kind != INT32_C(0)) {
                t1 = vader_parser_at_top_level_start(l0);
                l1 = !(t1);
            } else {
                l1 = false;
            }
            if (l1) {
                vader_parser_advance(l0);
                goto loop_1;
            } else {
            }
        }
    }
    return;
}

void vader_parser_walk_block(void* l0, void* l1) {
    size_t l2, l4;
    void* l3;
    vader_box_t t0;
    int64_t t1;
    l2 = vader_parser_mint(l1);
    ((vader_struct_toolchain_ast_BlockExpr_t*) l0)->f_id = l2;
    VADER_WRITE_BARRIER((vader_struct_toolchain_ast_BlockExpr_t*) l0);
    l3 = ((vader_struct_toolchain_ast_BlockExpr_t*) l0)->f_stmts;
    l2 = ((vader_array_t*) l3)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_13: {
            if ((l4 < l2)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
                vader_parser_walk_stmt(t0, l1);
                t1 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t1;
                goto loop_13;
            } else {
            }
        }
    }
    if (!(((vader_struct_toolchain_ast_BlockExpr_t*) l0)->f_trailing.tag == 0u)) {
        vader_parser_walk_expr(((vader_struct_toolchain_ast_BlockExpr_t*) l0)->f_trailing, l1);
    } else {
    }
    return;
}

void vader_parser_walk_decl(vader_box_t l0, void* l1) {
    void* l2;
    void* l5;
    void* l6;
    size_t l3, l4, l7;
    void* t0;
    int64_t t1;
    vader_box_t t2;
    if (l0.tag == 438u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_ImportDecl_t*) l2)->f_id = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_ImportDecl_t*) l2);
        vader_parser_walk_import_binding(((vader_struct_toolchain_ast_ImportDecl_t*) l2)->f_binding, l1);
        l2 = ((vader_struct_toolchain_ast_ImportDecl_t*) l2)->f_decorators;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) (int64_t) INT64_C(0);
        {
            loop_22: {
                if ((l4 < l3)) {
                    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
                    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                    if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
                    vader_parser_walk_decorator(t0, l1);
                    t1 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t1;
                    goto loop_22;
                } else {
                }
            }
        }
        return;
    }
    if (l0.tag == 428u) {
        t0 = l0.payload.obj;
        vader_parser_walk_fn_decl(t0, l1);
        return;
    }
    if (l0.tag == 470u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_StructDecl_t*) l2)->f_id = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_StructDecl_t*) l2);
        l5 = ((vader_struct_toolchain_ast_StructDecl_t*) l2)->f_type_params;
        l3 = ((vader_array_t*) l5)->length;
        l4 = (size_t) (int64_t) INT64_C(0);
        {
            loop_71: {
                if ((l4 < l3)) {
                    vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                    if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
                    vader_parser_walk_type_param(t0, l1);
                    t1 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t1;
                    goto loop_71;
                } else {
                }
            }
        }
        l5 = ((vader_struct_toolchain_ast_StructDecl_t*) l2)->f_fields;
        l3 = ((vader_array_t*) l5)->length;
        l4 = (size_t) (int64_t) INT64_C(0);
        {
            loop_97: {
                if ((l4 < l3)) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
                    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                    if ((size_t) l4 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                    l6 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
                    l7 = vader_parser_mint(l1);
                    ((vader_struct_toolchain_ast_StructField_t*) l6)->f_id = l7;
                    VADER_WRITE_BARRIER((vader_struct_toolchain_ast_StructField_t*) l6);
                    vader_parser_walk_expr(((vader_struct_toolchain_ast_StructField_t*) l6)->f_ty, l1);
                    if (!(((vader_struct_toolchain_ast_StructField_t*) l6)->f_default_v.tag == 0u)) {
                        vader_parser_walk_expr(((vader_struct_toolchain_ast_StructField_t*) l6)->f_default_v, l1);
                    } else {
                    }
                    t1 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t1;
                    goto loop_97;
                } else {
                }
            }
        }
        l2 = ((vader_struct_toolchain_ast_StructDecl_t*) l2)->f_decorators;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) (int64_t) INT64_C(0);
        {
            loop_140: {
                if ((l4 < l3)) {
                    vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
                    if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                    if ((size_t) l4 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l4);
                    vader_parser_walk_decorator(t0, l1);
                    t1 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t1;
                    goto loop_140;
                } else {
                }
            }
        }
        return;
    }
    if (l0.tag == 422u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_EnumDecl_t*) l2)->f_id = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_EnumDecl_t*) l2);
        if (!(((vader_struct_toolchain_ast_EnumDecl_t*) l2)->f_repr.tag == 0u)) {
            vader_parser_walk_expr(((vader_struct_toolchain_ast_EnumDecl_t*) l2)->f_repr, l1);
        } else {
        }
        l5 = ((vader_struct_toolchain_ast_EnumDecl_t*) l2)->f_variants;
        vader_array_t* _a4_slotarr = ((vader_array_t*) l5);
        if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
        l3 = ((vader_array_t*) l5)->length;
        l4 = (size_t) (int64_t) INT64_C(0);
        {
            loop_189: {
                if ((l4 < l3)) {
                    if ((size_t) l4 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                    l6 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l4);
                    l7 = vader_parser_mint(l1);
                    ((vader_struct_toolchain_ast_EnumVariant_t*) l6)->f_id = l7;
                    VADER_WRITE_BARRIER((vader_struct_toolchain_ast_EnumVariant_t*) l6);
                    t1 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t1;
                    goto loop_189;
                } else {
                }
            }
        }
        l2 = ((vader_struct_toolchain_ast_EnumDecl_t*) l2)->f_decorators;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) (int64_t) INT64_C(0);
        {
            loop_220: {
                if ((l4 < l3)) {
                    vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
                    if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                    if ((size_t) l4 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l4);
                    vader_parser_walk_decorator(t0, l1);
                    t1 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t1;
                    goto loop_220;
                } else {
                }
            }
        }
        return;
    }
    if (l0.tag == 477u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_TraitDecl_t*) l2)->f_id = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_TraitDecl_t*) l2);
        l5 = ((vader_struct_toolchain_ast_TraitDecl_t*) l2)->f_type_params;
        l3 = ((vader_array_t*) l5)->length;
        l4 = (size_t) (int64_t) INT64_C(0);
        {
            loop_260: {
                if ((l4 < l3)) {
                    vader_array_t* _a6_slotarr = ((vader_array_t*) l5);
                    if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                    if ((size_t) l4 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l4);
                    vader_parser_walk_type_param(t0, l1);
                    t1 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t1;
                    goto loop_260;
                } else {
                }
            }
        }
        if (!(((vader_struct_toolchain_ast_TraitDecl_t*) l2)->f_requires.tag == 0u)) {
            vader_parser_walk_expr(((vader_struct_toolchain_ast_TraitDecl_t*) l2)->f_requires, l1);
        } else {
        }
        l5 = ((vader_struct_toolchain_ast_TraitDecl_t*) l2)->f_members;
        l3 = ((vader_array_t*) l5)->length;
        l4 = (size_t) (int64_t) INT64_C(0);
        {
            loop_295: {
                if ((l4 < l3)) {
                    vader_array_t* _a7_slotarr = ((vader_array_t*) l5);
                    if (_a7_slotarr->buf != NULL && _a7_slotarr->buf->header.forward != NULL) { _a7_slotarr->buf = vader_array_buf_forward(_a7_slotarr->buf); }
                    if ((size_t) l4 >= _a7_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l4);
                    vader_parser_walk_fn_decl(t0, l1);
                    t1 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t1;
                    goto loop_295;
                } else {
                }
            }
        }
        l2 = ((vader_struct_toolchain_ast_TraitDecl_t*) l2)->f_decorators;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) (int64_t) INT64_C(0);
        {
            loop_321: {
                if ((l4 < l3)) {
                    vader_array_t* _a8_slotarr = ((vader_array_t*) l2);
                    if (_a8_slotarr->buf != NULL && _a8_slotarr->buf->header.forward != NULL) { _a8_slotarr->buf = vader_array_buf_forward(_a8_slotarr->buf); }
                    if ((size_t) l4 >= _a8_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = vader_array_ref_load_obj(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l4);
                    vader_parser_walk_decorator(t0, l1);
                    t1 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t1;
                    goto loop_321;
                } else {
                }
            }
        }
        return;
    }
    if (l0.tag == 437u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_ImplDecl_t*) l2)->f_id = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_ImplDecl_t*) l2);
        l5 = ((vader_struct_toolchain_ast_ImplDecl_t*) l2)->f_type_params;
        l3 = ((vader_array_t*) l5)->length;
        l4 = (size_t) (int64_t) INT64_C(0);
        {
            loop_361: {
                if ((l4 < l3)) {
                    vader_array_t* _a9_slotarr = ((vader_array_t*) l5);
                    if (_a9_slotarr->buf != NULL && _a9_slotarr->buf->header.forward != NULL) { _a9_slotarr->buf = vader_array_buf_forward(_a9_slotarr->buf); }
                    if ((size_t) l4 >= _a9_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = vader_array_ref_load_obj(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l4);
                    vader_parser_walk_type_param(t0, l1);
                    t1 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t1;
                    goto loop_361;
                } else {
                }
            }
        }
        vader_parser_walk_expr(((vader_struct_toolchain_ast_ImplDecl_t*) l2)->f_for_type, l1);
        l5 = ((vader_struct_toolchain_ast_ImplDecl_t*) l2)->f_trait_args;
        l3 = ((vader_array_t*) l5)->length;
        l4 = (size_t) (int64_t) INT64_C(0);
        {
            loop_390: {
                if ((l4 < l3)) {
                    vader_array_t* _a10_slotarr = ((vader_array_t*) l5);
                    if (_a10_slotarr->buf != NULL && _a10_slotarr->buf->header.forward != NULL) { _a10_slotarr->buf = vader_array_buf_forward(_a10_slotarr->buf); }
                    if ((size_t) l4 >= _a10_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = vader_array_ref_load_box(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l4);
                    vader_parser_walk_expr(t2, l1);
                    t1 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t1;
                    goto loop_390;
                } else {
                }
            }
        }
        l5 = ((vader_struct_toolchain_ast_ImplDecl_t*) l2)->f_members;
        l3 = ((vader_array_t*) l5)->length;
        l4 = (size_t) (int64_t) INT64_C(0);
        {
            loop_416: {
                if ((l4 < l3)) {
                    vader_array_t* _a11_slotarr = ((vader_array_t*) l5);
                    if (_a11_slotarr->buf != NULL && _a11_slotarr->buf->header.forward != NULL) { _a11_slotarr->buf = vader_array_buf_forward(_a11_slotarr->buf); }
                    if ((size_t) l4 >= _a11_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = vader_array_ref_load_obj(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l4);
                    vader_parser_walk_fn_decl(t0, l1);
                    t1 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t1;
                    goto loop_416;
                } else {
                }
            }
        }
        l2 = ((vader_struct_toolchain_ast_ImplDecl_t*) l2)->f_decorators;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) (int64_t) INT64_C(0);
        {
            loop_442: {
                if ((l4 < l3)) {
                    vader_array_t* _a12_slotarr = ((vader_array_t*) l2);
                    if (_a12_slotarr->buf != NULL && _a12_slotarr->buf->header.forward != NULL) { _a12_slotarr->buf = vader_array_buf_forward(_a12_slotarr->buf); }
                    if ((size_t) l4 >= _a12_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = vader_array_ref_load_obj(_a12_slotarr->buf, _a12_slotarr->offset + (size_t) l4);
                    vader_parser_walk_decorator(t0, l1);
                    t1 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t1;
                    goto loop_442;
                } else {
                }
            }
        }
        return;
    }
    if (l0.tag == 480u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_TypeAliasDecl_t*) l2)->f_id = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_TypeAliasDecl_t*) l2);
        l5 = ((vader_struct_toolchain_ast_TypeAliasDecl_t*) l2)->f_type_params;
        l3 = ((vader_array_t*) l5)->length;
        l4 = (size_t) (int64_t) INT64_C(0);
        {
            loop_482: {
                if ((l4 < l3)) {
                    vader_array_t* _a13_slotarr = ((vader_array_t*) l5);
                    if (_a13_slotarr->buf != NULL && _a13_slotarr->buf->header.forward != NULL) { _a13_slotarr->buf = vader_array_buf_forward(_a13_slotarr->buf); }
                    if ((size_t) l4 >= _a13_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = vader_array_ref_load_obj(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l4);
                    vader_parser_walk_type_param(t0, l1);
                    t1 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t1;
                    goto loop_482;
                } else {
                }
            }
        }
        vader_parser_walk_expr(((vader_struct_toolchain_ast_TypeAliasDecl_t*) l2)->f_aliased, l1);
        l2 = ((vader_struct_toolchain_ast_TypeAliasDecl_t*) l2)->f_decorators;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) (int64_t) INT64_C(0);
        {
            loop_511: {
                if ((l4 < l3)) {
                    vader_array_t* _a14_slotarr = ((vader_array_t*) l2);
                    if (_a14_slotarr->buf != NULL && _a14_slotarr->buf->header.forward != NULL) { _a14_slotarr->buf = vader_array_buf_forward(_a14_slotarr->buf); }
                    if ((size_t) l4 >= _a14_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = vader_array_ref_load_obj(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l4);
                    vader_parser_walk_decorator(t0, l1);
                    t1 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t1;
                    goto loop_511;
                } else {
                }
            }
        }
        return;
    }
    if (l0.tag == 412u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_ConstDecl_t*) l2)->f_id = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_ConstDecl_t*) l2);
        if (!(((vader_struct_toolchain_ast_ConstDecl_t*) l2)->f_ty.tag == 0u)) {
            vader_parser_walk_expr(((vader_struct_toolchain_ast_ConstDecl_t*) l2)->f_ty, l1);
        } else {
        }
        vader_parser_walk_expr(((vader_struct_toolchain_ast_ConstDecl_t*) l2)->f_value, l1);
        l2 = ((vader_struct_toolchain_ast_ConstDecl_t*) l2)->f_decorators;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) (int64_t) INT64_C(0);
        {
            loop_563: {
                if ((l4 < l3)) {
                    vader_array_t* _a15_slotarr = ((vader_array_t*) l2);
                    if (_a15_slotarr->buf != NULL && _a15_slotarr->buf->header.forward != NULL) { _a15_slotarr->buf = vader_array_buf_forward(_a15_slotarr->buf); }
                    if ((size_t) l4 >= _a15_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = vader_array_ref_load_obj(_a15_slotarr->buf, _a15_slotarr->offset + (size_t) l4);
                    vader_parser_walk_decorator(t0, l1);
                    t1 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t1;
                    goto loop_563;
                } else {
                }
            }
        }
        return;
    }
    if (l0.tag == 400u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_AssertDecl_t*) l2)->f_id = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_AssertDecl_t*) l2);
        vader_parser_walk_expr(((vader_struct_toolchain_ast_AssertDecl_t*) l2)->f_condition, l1);
        l2 = ((vader_struct_toolchain_ast_AssertDecl_t*) l2)->f_decorators;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) (int64_t) INT64_C(0);
        {
            loop_606: {
                if ((l4 < l3)) {
                    vader_array_t* _a16_slotarr = ((vader_array_t*) l2);
                    if (_a16_slotarr->buf != NULL && _a16_slotarr->buf->header.forward != NULL) { _a16_slotarr->buf = vader_array_buf_forward(_a16_slotarr->buf); }
                    if ((size_t) l4 >= _a16_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = vader_array_ref_load_obj(_a16_slotarr->buf, _a16_slotarr->offset + (size_t) l4);
                    vader_parser_walk_decorator(t0, l1);
                    t1 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t1;
                    goto loop_606;
                } else {
                }
            }
        }
        return;
    }
    return;
}

void vader_parser_walk_decorator(void* l0, void* l1) {
    size_t l2, l4;
    void* l3;
    vader_box_t t0;
    int64_t t1;
    l2 = vader_parser_mint(l1);
    ((vader_struct_toolchain_ast_Decorator_t*) l0)->f_id = l2;
    VADER_WRITE_BARRIER((vader_struct_toolchain_ast_Decorator_t*) l0);
    l3 = ((vader_struct_toolchain_ast_Decorator_t*) l0)->f_args;
    l2 = ((vader_array_t*) l3)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_13: {
            if ((l4 < l2)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
                vader_parser_walk_expr(t0, l1);
                t1 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t1;
                goto loop_13;
            } else {
            }
        }
    }
    return;
}

void vader_parser_walk_expr(vader_box_t l0, void* l1) {
    void* l2;
    void* l6;
    void* l8;
    size_t l3, l4, l7, l9, l10;
    vader_box_t l5;
    int64_t t0;
    void* t1;
    vader_box_t t2;
    if (l0.tag == 443u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_IntLitExpr_t*) l2)->f_id = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_IntLitExpr_t*) l2);
        return;
    }
    if (l0.tag == 427u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_FloatLitExpr_t*) l2)->f_id = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_FloatLitExpr_t*) l2);
        return;
    }
    if (l0.tag == 406u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_BoolLitExpr_t*) l2)->f_id = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_BoolLitExpr_t*) l2);
        return;
    }
    if (l0.tag == 456u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_NullLitExpr_t*) l2)->f_id = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_NullLitExpr_t*) l2);
        return;
    }
    if (l0.tag == 411u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_CharLitExpr_t*) l2)->f_id = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_CharLitExpr_t*) l2);
        return;
    }
    if (l0.tag == 467u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_StringLitExpr_t*) l2)->f_id = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_StringLitExpr_t*) l2);
        l2 = ((vader_struct_toolchain_ast_StringLitExpr_t*) l2)->f_parts;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) (int64_t) INT64_C(0);
        {
            loop_89: {
                if ((l4 < l3)) {
                    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
                    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                    if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                    l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
                    if (l5.tag == 469u) {
                        l6 = l5.payload.obj;
                        l7 = vader_parser_mint(l1);
                        ((vader_struct_toolchain_ast_StringLitText_t*) l6)->f_id = l7;
                        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_StringLitText_t*) l6);
                        l10 = (size_t) (int64_t) INT64_C(1);
                        t0 = (l4 + l10);
                        l4 = (size_t) (int64_t) t0;
                        goto loop_89;
                    }
                    if (l5.tag == 468u) {
                        l8 = l5.payload.obj;
                        l9 = vader_parser_mint(l1);
                        ((vader_struct_toolchain_ast_StringLitInterp_t*) l8)->f_id = l9;
                        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_StringLitInterp_t*) l8);
                        vader_parser_walk_expr(((vader_struct_toolchain_ast_StringLitInterp_t*) l8)->f_expr, l1);
                        l10 = (size_t) (int64_t) INT64_C(1);
                        t0 = (l4 + l10);
                        l4 = (size_t) (int64_t) t0;
                        goto loop_89;
                    }
                    return;
                } else {
                }
            }
        }
        return;
    }
    if (l0.tag == 433u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_IdentExpr_t*) l2)->f_id = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_IdentExpr_t*) l2);
        return;
    }
    if (l0.tag == 409u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_CallExpr_t*) l2)->f_id = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_CallExpr_t*) l2);
        vader_parser_walk_expr(((vader_struct_toolchain_ast_CallExpr_t*) l2)->f_callee, l1);
        l2 = ((vader_struct_toolchain_ast_CallExpr_t*) l2)->f_args;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) (int64_t) INT64_C(0);
        {
            loop_183: {
                if ((l4 < l3)) {
                    vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                    if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    l6 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
                    l7 = vader_parser_mint(l1);
                    ((vader_struct_toolchain_ast_CallArg_t*) l6)->f_id = l7;
                    VADER_WRITE_BARRIER((vader_struct_toolchain_ast_CallArg_t*) l6);
                    vader_parser_walk_expr(((vader_struct_toolchain_ast_CallArg_t*) l6)->f_value, l1);
                    t0 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t0;
                    goto loop_183;
                } else {
                }
            }
        }
        return;
    }
    if (l0.tag == 426u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_FieldExpr_t*) l2)->f_id = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_FieldExpr_t*) l2);
        vader_parser_walk_expr(((vader_struct_toolchain_ast_FieldExpr_t*) l2)->f_target, l1);
        return;
    }
    if (l0.tag == 441u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_IndexExpr_t*) l2)->f_id = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_IndexExpr_t*) l2);
        vader_parser_walk_expr(((vader_struct_toolchain_ast_IndexExpr_t*) l2)->f_target, l1);
        vader_parser_walk_expr(((vader_struct_toolchain_ast_IndexExpr_t*) l2)->f_index, l1);
        return;
    }
    if (l0.tag == 482u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_UnaryExpr_t*) l2)->f_id = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_UnaryExpr_t*) l2);
        vader_parser_walk_expr(((vader_struct_toolchain_ast_UnaryExpr_t*) l2)->f_operand, l1);
        return;
    }
    if (l0.tag == 403u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_BinaryExpr_t*) l2)->f_id = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_BinaryExpr_t*) l2);
        vader_parser_walk_expr(((vader_struct_toolchain_ast_BinaryExpr_t*) l2)->f_left, l1);
        vader_parser_walk_expr(((vader_struct_toolchain_ast_BinaryExpr_t*) l2)->f_right, l1);
        return;
    }
    if (l0.tag == 455u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_NullCoalesceExpr_t*) l2)->f_id = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_NullCoalesceExpr_t*) l2);
        vader_parser_walk_expr(((vader_struct_toolchain_ast_NullCoalesceExpr_t*) l2)->f_left, l1);
        l5 = ((vader_struct_toolchain_ast_NullCoalesceExpr_t*) l2)->f_fallback;
        if ((l5.tag == 407u || l5.tag == 413u || l5.tag == 464u)) {
            vader_parser_walk_stmt(l5, l1);
            return;
        }
        if ((l5.tag == 399u || l5.tag == 402u || l5.tag == 403u || l5.tag == 405u || l5.tag == 406u || l5.tag == 409u || l5.tag == 410u || l5.tag == 411u || l5.tag == 421u || l5.tag == 426u || l5.tag == 427u || l5.tag == 430u || l5.tag == 432u || l5.tag == 433u || l5.tag == 436u || l5.tag == 441u || l5.tag == 443u || l5.tag == 444u || l5.tag == 446u || l5.tag == 450u || l5.tag == 452u || l5.tag == 455u || l5.tag == 456u || l5.tag == 461u || l5.tag == 465u || l5.tag == 467u || l5.tag == 472u || l5.tag == 482u)) {
            vader_parser_walk_expr(l5, l1);
            return;
        }
        return;
    }
    if (l0.tag == 436u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_IfExpr_t*) l2)->f_id = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_IfExpr_t*) l2);
        vader_parser_walk_expr(((vader_struct_toolchain_ast_IfExpr_t*) l2)->f_cond, l1);
        vader_parser_walk_block(((vader_struct_toolchain_ast_IfExpr_t*) l2)->f_then_block, l1);
        l5 = ((vader_struct_toolchain_ast_IfExpr_t*) l2)->f_else_branch;
        if (l5.tag == 0u) {
            return;
        }
        if (l5.tag == 435u) {
            t1 = l5.payload.obj;
            vader_parser_walk_expr(vader_ref_box(((vader_struct_toolchain_ast_IfElseIf_t*) t1)->f_branch), l1);
            return;
        }
        if (l5.tag == 434u) {
            t1 = l5.payload.obj;
            vader_parser_walk_block(((vader_struct_toolchain_ast_IfElseBlock_t*) t1)->f_block, l1);
            return;
        }
        return;
    }
    if (l0.tag == 450u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_MatchExpr_t*) l2)->f_id = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_MatchExpr_t*) l2);
        vader_parser_walk_expr(((vader_struct_toolchain_ast_MatchExpr_t*) l2)->f_scrutinee, l1);
        l2 = ((vader_struct_toolchain_ast_MatchExpr_t*) l2)->f_arms;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) (int64_t) INT64_C(0);
        {
            loop_388: {
                if ((l4 < l3)) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
                    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                    if ((size_t) l4 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                    l6 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
                    l7 = vader_parser_mint(l1);
                    ((vader_struct_toolchain_ast_MatchArm_t*) l6)->f_id = l7;
                    VADER_WRITE_BARRIER((vader_struct_toolchain_ast_MatchArm_t*) l6);
                    vader_parser_walk_pattern(((vader_struct_toolchain_ast_MatchArm_t*) l6)->f_pattern, l1);
                    if (!(((vader_struct_toolchain_ast_MatchArm_t*) l6)->f_guard.tag == 0u)) {
                        vader_parser_walk_expr(((vader_struct_toolchain_ast_MatchArm_t*) l6)->f_guard, l1);
                    } else {
                    }
                    vader_parser_walk_expr(((vader_struct_toolchain_ast_MatchArm_t*) l6)->f_body, l1);
                    t0 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t0;
                    goto loop_388;
                } else {
                }
            }
        }
        return;
    }
    if (l0.tag == 405u) {
        t1 = l0.payload.obj;
        vader_parser_walk_block(t1, l1);
        return;
    }
    if (l0.tag == 446u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_LambdaExpr_t*) l2)->f_id = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_LambdaExpr_t*) l2);
        l6 = ((vader_struct_toolchain_ast_LambdaExpr_t*) l2)->f_params;
        l3 = ((vader_array_t*) l6)->length;
        l4 = (size_t) (int64_t) INT64_C(0);
        {
            loop_457: {
                if ((l4 < l3)) {
                    vader_array_t* _a3_slotarr = ((vader_array_t*) l6);
                    if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                    if ((size_t) l4 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l4);
                    vader_parser_walk_fn_param(t1, l1);
                    t0 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t0;
                    goto loop_457;
                } else {
                }
            }
        }
        if (!(((vader_struct_toolchain_ast_LambdaExpr_t*) l2)->f_return_type.tag == 0u)) {
            vader_parser_walk_expr(((vader_struct_toolchain_ast_LambdaExpr_t*) l2)->f_return_type, l1);
        } else {
        }
        vader_parser_walk_block(((vader_struct_toolchain_ast_LambdaExpr_t*) l2)->f_body, l1);
        return;
    }
    if (l0.tag == 472u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_StructLitExpr_t*) l2)->f_id = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_StructLitExpr_t*) l2);
        vader_parser_walk_expr(((vader_struct_toolchain_ast_StructLitExpr_t*) l2)->f_type_name, l1);
        l2 = ((vader_struct_toolchain_ast_StructLitExpr_t*) l2)->f_items;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) (int64_t) INT64_C(0);
        {
            loop_512: {
                if ((l4 < l3)) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
                    if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                    if ((size_t) l4 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                    l5 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l4);
                    if (l5.tag == 473u) {
                        l6 = l5.payload.obj;
                        l7 = vader_parser_mint(l1);
                        ((vader_struct_toolchain_ast_StructLitField_t*) l6)->f_id = l7;
                        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_StructLitField_t*) l6);
                        vader_parser_walk_expr(((vader_struct_toolchain_ast_StructLitField_t*) l6)->f_value, l1);
                        l10 = (size_t) (int64_t) INT64_C(1);
                        t0 = (l4 + l10);
                        l4 = (size_t) (int64_t) t0;
                        goto loop_512;
                    }
                    if (l5.tag == 474u) {
                        l8 = l5.payload.obj;
                        l9 = vader_parser_mint(l1);
                        ((vader_struct_toolchain_ast_StructLitSpread_t*) l8)->f_id = l9;
                        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_StructLitSpread_t*) l8);
                        vader_parser_walk_expr(((vader_struct_toolchain_ast_StructLitSpread_t*) l8)->f_expr, l1);
                        l10 = (size_t) (int64_t) INT64_C(1);
                        t0 = (l4 + l10);
                        l4 = (size_t) (int64_t) t0;
                        goto loop_512;
                    }
                    return;
                } else {
                }
            }
        }
        return;
    }
    if (l0.tag == 465u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_SeqLitExpr_t*) l2)->f_id = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_SeqLitExpr_t*) l2);
        l2 = ((vader_struct_toolchain_ast_SeqLitExpr_t*) l2)->f_elements;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) (int64_t) INT64_C(0);
        {
            loop_592: {
                if ((l4 < l3)) {
                    vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
                    if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                    if ((size_t) l4 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l4);
                    vader_parser_walk_expr(t2, l1);
                    t0 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t0;
                    goto loop_592;
                } else {
                }
            }
        }
        return;
    }
    if (l0.tag == 461u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_RangeExpr_t*) l2)->f_id = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_RangeExpr_t*) l2);
        vader_parser_walk_expr(((vader_struct_toolchain_ast_RangeExpr_t*) l2)->f_lower, l1);
        vader_parser_walk_expr(((vader_struct_toolchain_ast_RangeExpr_t*) l2)->f_upper, l1);
        return;
    }
    if (l0.tag == 402u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_AwaitExpr_t*) l2)->f_id = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_AwaitExpr_t*) l2);
        vader_parser_walk_expr(((vader_struct_toolchain_ast_AwaitExpr_t*) l2)->f_inner, l1);
        return;
    }
    if (l0.tag == 410u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_CastExpr_t*) l2)->f_id = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_CastExpr_t*) l2);
        vader_parser_walk_expr(((vader_struct_toolchain_ast_CastExpr_t*) l2)->f_target, l1);
        vader_parser_walk_expr(((vader_struct_toolchain_ast_CastExpr_t*) l2)->f_value, l1);
        return;
    }
    if (l0.tag == 432u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_GenericInstExpr_t*) l2)->f_id = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_GenericInstExpr_t*) l2);
        vader_parser_walk_expr(((vader_struct_toolchain_ast_GenericInstExpr_t*) l2)->f_callee, l1);
        l2 = ((vader_struct_toolchain_ast_GenericInstExpr_t*) l2)->f_type_args;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) (int64_t) INT64_C(0);
        {
            loop_692: {
                if ((l4 < l3)) {
                    vader_array_t* _a6_slotarr = ((vader_array_t*) l2);
                    if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                    if ((size_t) l4 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = vader_array_ref_load_box(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l4);
                    vader_parser_walk_expr(t2, l1);
                    t0 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t0;
                    goto loop_692;
                } else {
                }
            }
        }
        return;
    }
    if (l0.tag == 444u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l2)->f_id = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l2);
        l2 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l2)->f_args;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) (int64_t) INT64_C(0);
        {
            loop_732: {
                if ((l4 < l3)) {
                    vader_array_t* _a7_slotarr = ((vader_array_t*) l2);
                    if (_a7_slotarr->buf != NULL && _a7_slotarr->buf->header.forward != NULL) { _a7_slotarr->buf = vader_array_buf_forward(_a7_slotarr->buf); }
                    if ((size_t) l4 >= _a7_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = vader_array_ref_load_box(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l4);
                    vader_parser_walk_expr(t2, l1);
                    t0 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t0;
                    goto loop_732;
                } else {
                }
            }
        }
        return;
    }
    if (l0.tag == 421u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_DotVariantExpr_t*) l2)->f_id = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_DotVariantExpr_t*) l2);
        return;
    }
    if (l0.tag == 430u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_FnTypeExpr_t*) l2)->f_id = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_FnTypeExpr_t*) l2);
        l6 = ((vader_struct_toolchain_ast_FnTypeExpr_t*) l2)->f_params;
        l3 = ((vader_array_t*) l6)->length;
        l4 = (size_t) (int64_t) INT64_C(0);
        {
            loop_786: {
                if ((l4 < l3)) {
                    vader_array_t* _a8_slotarr = ((vader_array_t*) l6);
                    if (_a8_slotarr->buf != NULL && _a8_slotarr->buf->header.forward != NULL) { _a8_slotarr->buf = vader_array_buf_forward(_a8_slotarr->buf); }
                    if ((size_t) l4 >= _a8_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = vader_array_ref_load_box(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l4);
                    vader_parser_walk_expr(t2, l1);
                    t0 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t0;
                    goto loop_786;
                } else {
                }
            }
        }
        if (!(((vader_struct_toolchain_ast_FnTypeExpr_t*) l2)->f_return_type.tag == 0u)) {
            vader_parser_walk_expr(((vader_struct_toolchain_ast_FnTypeExpr_t*) l2)->f_return_type, l1);
        } else {
        }
        return;
    }
    if (l0.tag == 399u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) l2)->f_id = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_ArrayTypeExpr_t*) l2);
        vader_parser_walk_expr(((vader_struct_toolchain_ast_ArrayTypeExpr_t*) l2)->f_element, l1);
        return;
    }
    if (l0.tag == 452u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_MutableTypeExpr_t*) l2)->f_id = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_MutableTypeExpr_t*) l2);
        vader_parser_walk_expr(((vader_struct_toolchain_ast_MutableTypeExpr_t*) l2)->f_inner, l1);
        return;
    }
    return;
}

void vader_parser_walk_fn_decl(void* l0, void* l1) {
    size_t l2, l4;
    void* l3;
    void* t0;
    int64_t t1;
    l2 = vader_parser_mint(l1);
    ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_id = l2;
    VADER_WRITE_BARRIER((vader_struct_toolchain_ast_FnDecl_t*) l0);
    l3 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_decorators;
    l2 = ((vader_array_t*) l3)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_13: {
            if ((l4 < l2)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
                vader_parser_walk_decorator(t0, l1);
                t1 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t1;
                goto loop_13;
            } else {
            }
        }
    }
    l3 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_type_params;
    l2 = ((vader_array_t*) l3)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_39: {
            if ((l4 < l2)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
                vader_parser_walk_type_param(t0, l1);
                t1 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t1;
                goto loop_39;
            } else {
            }
        }
    }
    l3 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_params;
    l2 = ((vader_array_t*) l3)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_65: {
            if ((l4 < l2)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l4 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
                vader_parser_walk_fn_param(t0, l1);
                t1 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t1;
                goto loop_65;
            } else {
            }
        }
    }
    if (!(((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_return_type.tag == 0u)) {
        vader_parser_walk_expr(((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_return_type, l1);
    } else {
    }
    if (!(((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_body.tag == 0u)) {
        vader_parser_walk_block(((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_body.payload.obj, l1);
    } else {
    }
    return;
}

void vader_parser_walk_fn_param(void* l0, void* l1) {
    size_t l2;
    l2 = vader_parser_mint(l1);
    ((vader_struct_toolchain_ast_FnParam_t*) l0)->f_id = l2;
    VADER_WRITE_BARRIER((vader_struct_toolchain_ast_FnParam_t*) l0);
    if (!(((vader_struct_toolchain_ast_FnParam_t*) l0)->f_ty.tag == 0u)) {
        vader_parser_walk_expr(((vader_struct_toolchain_ast_FnParam_t*) l0)->f_ty, l1);
    } else {
    }
    if (!(((vader_struct_toolchain_ast_FnParam_t*) l0)->f_default_value.tag == 0u)) {
        vader_parser_walk_expr(((vader_struct_toolchain_ast_FnParam_t*) l0)->f_default_value, l1);
    } else {
    }
    return;
}

void vader_parser_walk_for_form(vader_box_t l0, void* l1) {
    void* t0;
    if (l0.tag == 442u) {
        return;
    }
    if (l0.tag == 483u) {
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_WhileFor_t*) t0)->f_cond, l1);
        return;
    }
    if (l0.tag == 440u) {
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_InFor_t*) t0)->f_iter, l1);
        return;
    }
    return;
}

void vader_parser_walk_import_binding(vader_box_t l0, void* l1) {
    void* l2;
    void* l5;
    size_t l3, l4, l6;
    void* t0;
    int64_t t1;
    if (l0.tag == 453u) {
        return;
    }
    if (l0.tag == 485u) {
        return;
    }
    if (l0.tag == 418u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_DestructureImport_t*) t0)->f_names;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) (int64_t) INT64_C(0);
        {
            loop_22: {
                if ((l4 < l3)) {
                    if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                    l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
                    l6 = vader_parser_mint(l1);
                    ((vader_struct_toolchain_ast_ImportName_t*) l5)->f_id = l6;
                    VADER_WRITE_BARRIER((vader_struct_toolchain_ast_ImportName_t*) l5);
                    t1 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t1;
                    goto loop_22;
                } else {
                }
            }
        }
        return;
    }
    return;
}

void vader_parser_walk_let_binding(vader_box_t l0, void* l1) {
    void* l2;
    size_t l3, l4;
    vader_box_t t0;
    int64_t t1;
    if (l0.tag == 466u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_SimpleBinding_t*) l2)->f_id = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_SimpleBinding_t*) l2);
        return;
    }
    if (l0.tag == 484u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_WildcardBinding_t*) l2)->f_id = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_WildcardBinding_t*) l2);
        return;
    }
    if (l0.tag == 463u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_RestBinding_t*) l2)->f_id = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_RestBinding_t*) l2);
        return;
    }
    if (l0.tag == 478u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_TupleBinding_t*) l2)->f_id = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_TupleBinding_t*) l2);
        l2 = ((vader_struct_toolchain_ast_TupleBinding_t*) l2)->f_elements;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) (int64_t) INT64_C(0);
        {
            loop_61: {
                if ((l4 < l3)) {
                    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
                    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                    if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
                    vader_parser_walk_let_binding(t0, l1);
                    t1 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t1;
                    goto loop_61;
                } else {
                }
            }
        }
        return;
    }
    return;
}

void vader_parser_walk_pattern(vader_box_t l0, void* l1) {
    void* l2;
    void* l5;
    void* l8;
    size_t l3, l4, l6, l9, l10;
    vader_box_t l7;
    int64_t t0;
    void* t1;
    vader_box_t t2;
    if (l0.tag == 445u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_IsPattern_t*) l2)->f_id = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_IsPattern_t*) l2);
        vader_parser_walk_expr(((vader_struct_toolchain_ast_IsPattern_t*) l2)->f_ty, l1);
        if (!(((vader_struct_toolchain_ast_IsPattern_t*) l2)->f_inner.tag == 0u)) {
            vader_parser_walk_pattern(((vader_struct_toolchain_ast_IsPattern_t*) l2)->f_inner, l1);
        } else {
        }
        return;
    }
    if (l0.tag == 475u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_StructPattern_t*) l2)->f_id = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_StructPattern_t*) l2);
        l2 = ((vader_struct_toolchain_ast_StructPattern_t*) l2)->f_fields;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) (int64_t) INT64_C(0);
        {
            loop_45: {
                if ((l4 < l3)) {
                    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
                    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                    if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                    l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
                    l6 = vader_parser_mint(l1);
                    ((vader_struct_toolchain_ast_StructPatternField_t*) l5)->f_id = l6;
                    VADER_WRITE_BARRIER((vader_struct_toolchain_ast_StructPatternField_t*) l5);
                    l7 = ((vader_struct_toolchain_ast_StructPatternField_t*) l5)->f_value;
                    if (l7.tag == 458u) {
                        l8 = l7.payload.obj;
                        l9 = vader_parser_mint(l1);
                        ((vader_struct_toolchain_ast_PatternBinding_t*) l8)->f_id = l9;
                        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_PatternBinding_t*) l8);
                        l10 = (size_t) (int64_t) INT64_C(1);
                        t0 = (l4 + l10);
                        l4 = (size_t) (int64_t) t0;
                        goto loop_45;
                    }
                    if (l7.tag == 459u) {
                        t1 = l7.payload.obj;
                        vader_parser_walk_expr(((vader_struct_toolchain_ast_PatternLiteral_t*) t1)->f_value, l1);
                        l10 = (size_t) (int64_t) INT64_C(1);
                        t0 = (l4 + l10);
                        l4 = (size_t) (int64_t) t0;
                        goto loop_45;
                    }
                    return;
                } else {
                }
            }
        }
        return;
    }
    if (l0.tag == 479u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_TuplePattern_t*) l2)->f_id = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_TuplePattern_t*) l2);
        l2 = ((vader_struct_toolchain_ast_TuplePattern_t*) l2)->f_elements;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) (int64_t) INT64_C(0);
        {
            loop_123: {
                if ((l4 < l3)) {
                    vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                    if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
                    vader_parser_walk_pattern(t2, l1);
                    t0 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t0;
                    goto loop_123;
                } else {
                }
            }
        }
        return;
    }
    if (l0.tag == 486u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_WildcardPattern_t*) l2)->f_id = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_WildcardPattern_t*) l2);
        return;
    }
    if (l0.tag == 404u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_BindingPattern_t*) l2)->f_id = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_BindingPattern_t*) l2);
        return;
    }
    if (l0.tag == 424u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_EnumVariantPattern_t*) l2)->f_id = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_EnumVariantPattern_t*) l2);
        return;
    }
    if (l0.tag == 448u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_LiteralPattern_t*) l2)->f_id = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_LiteralPattern_t*) l2);
        vader_parser_walk_expr(((vader_struct_toolchain_ast_LiteralPattern_t*) l2)->f_value, l1);
        return;
    }
    if (l0.tag == 462u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_RangePattern_t*) l2)->f_id = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_RangePattern_t*) l2);
        vader_parser_walk_expr(((vader_struct_toolchain_ast_RangePattern_t*) l2)->f_lower, l1);
        vader_parser_walk_expr(((vader_struct_toolchain_ast_RangePattern_t*) l2)->f_upper, l1);
        return;
    }
    if (l0.tag == 457u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_OrPattern_t*) l2)->f_id = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_OrPattern_t*) l2);
        l2 = ((vader_struct_toolchain_ast_OrPattern_t*) l2)->f_patterns;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) (int64_t) INT64_C(0);
        {
            loop_242: {
                if ((l4 < l3)) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
                    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                    if ((size_t) l4 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
                    vader_parser_walk_pattern(t2, l1);
                    t0 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t0;
                    goto loop_242;
                } else {
                }
            }
        }
        return;
    }
    return;
}

void vader_parser_walk_stmt(vader_box_t l0, void* l1) {
    void* l2;
    size_t l3;
    vader_box_t l4;
    void* t0;
    if (l0.tag == 447u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_LetStmt_t*) l2)->f_id = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_LetStmt_t*) l2);
        vader_parser_walk_let_binding(((vader_struct_toolchain_ast_LetStmt_t*) l2)->f_binding, l1);
        if (!(((vader_struct_toolchain_ast_LetStmt_t*) l2)->f_ty.tag == 0u)) {
            vader_parser_walk_expr(((vader_struct_toolchain_ast_LetStmt_t*) l2)->f_ty, l1);
        } else {
        }
        vader_parser_walk_expr(((vader_struct_toolchain_ast_LetStmt_t*) l2)->f_value, l1);
        return;
    }
    if (l0.tag == 401u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_AssignStmt_t*) l2)->f_id = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_AssignStmt_t*) l2);
        vader_parser_walk_expr(((vader_struct_toolchain_ast_AssignStmt_t*) l2)->f_target, l1);
        vader_parser_walk_expr(((vader_struct_toolchain_ast_AssignStmt_t*) l2)->f_value, l1);
        return;
    }
    if (l0.tag == 425u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_ExprStmt_t*) l2)->f_id = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_ExprStmt_t*) l2);
        vader_parser_walk_expr(((vader_struct_toolchain_ast_ExprStmt_t*) l2)->f_expr, l1);
        return;
    }
    if (l0.tag == 464u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_ReturnStmt_t*) l2)->f_id = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_ReturnStmt_t*) l2);
        if (!(((vader_struct_toolchain_ast_ReturnStmt_t*) l2)->f_value.tag == 0u)) {
            vader_parser_walk_expr(((vader_struct_toolchain_ast_ReturnStmt_t*) l2)->f_value, l1);
        } else {
        }
        return;
    }
    if (l0.tag == 487u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_YieldStmt_t*) l2)->f_id = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_YieldStmt_t*) l2);
        vader_parser_walk_expr(((vader_struct_toolchain_ast_YieldStmt_t*) l2)->f_value, l1);
        return;
    }
    if (l0.tag == 431u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_ForStmt_t*) l2)->f_id = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_ForStmt_t*) l2);
        vader_parser_walk_for_form(((vader_struct_toolchain_ast_ForStmt_t*) l2)->f_form, l1);
        vader_parser_walk_block(((vader_struct_toolchain_ast_ForStmt_t*) l2)->f_body, l1);
        return;
    }
    if (l0.tag == 407u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_BreakStmt_t*) l2)->f_id = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_BreakStmt_t*) l2);
        return;
    }
    if (l0.tag == 413u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_ContinueStmt_t*) l2)->f_id = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_ContinueStmt_t*) l2);
        return;
    }
    if (l0.tag == 416u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_DeferStmt_t*) l2)->f_id = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_DeferStmt_t*) l2);
        l4 = ((vader_struct_toolchain_ast_DeferStmt_t*) l2)->f_body;
        if (l4.tag == 417u) {
            t0 = l4.payload.obj;
            vader_parser_walk_stmt(((vader_struct_toolchain_ast_DeferStmtBody_t*) t0)->f_stmt, l1);
            return;
        }
        if (l4.tag == 415u) {
            t0 = l4.payload.obj;
            vader_parser_walk_block(((vader_struct_toolchain_ast_DeferBlockBody_t*) t0)->f_block, l1);
            return;
        }
        return;
    }
    return;
}

void vader_parser_walk_type_param(void* l0, void* l1) {
    size_t l2;
    l2 = vader_parser_mint(l1);
    ((vader_struct_toolchain_ast_TypeParam_t*) l0)->f_id = l2;
    VADER_WRITE_BARRIER((vader_struct_toolchain_ast_TypeParam_t*) l0);
    if (!(((vader_struct_toolchain_ast_TypeParam_t*) l0)->f_bound.tag == 0u)) {
        vader_parser_walk_expr(((vader_struct_toolchain_ast_TypeParam_t*) l0)->f_bound, l1);
    } else {
    }
    return;
}

void* vader_parser_wrap_as_block(vader_box_t l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l0, &l3 };
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 405u) {
        t0 = l0.payload.obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l0.payload.obj;
    l1 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t0)->f_span;
    vader_array_t* _a0_arr = vader_array_new(110u, 0u, 13u, 1047u);
    l2 = (void*) _a0_arr;
    l3 = l0;
    vader_struct_toolchain_ast_BlockExpr_t* _a1_obj = (vader_struct_toolchain_ast_BlockExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BlockExpr_t));
    vader_obj_header_init(_a1_obj, 405u);
    _a1_obj->f_span = l1;
    _a1_obj->f_id = (size_t) (int64_t) INT64_C(0);
    _a1_obj->f_stmts = l2;
    _a1_obj->f_trailing = l3;
    t0 = (void*) _a1_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

