#include "bootstrap.split.h"

static void* vader_parser_advance(void* l0);
static bool vader_parser_at_top_level_start(void* l0);
static bool vader_parser_check(void* l0, uint8_t l1);
static bool vader_parser_check_at(void* l0, uint8_t l1, int32_t l2);
static bool vader_parser_check_closing_angle(void* l0);
static void vader_parser_collect_type_params(vader_box_t l0, void* l1);
static void* vader_parser_compound_op(uint8_t l0);
static void* vader_parser_consume_closing_angle(void* l0);
static vader_string_t vader_parser_describe_token(void* l0);
static void* vader_parser_desugar_comptime_const(void* l0, void* l1, uint8_t l2, void* l3, vader_box_t l4);
static void* vader_parser_empty_token(void);
static void vader_parser_error(void* l0, uint8_t l1, void* l2, vader_string_t l3);
static void* vader_parser_expect(void* l0, uint8_t l1, vader_string_t l2);
static void* vader_parser_expect_string_literal(void* l0, vader_string_t l1);
static size_t vader_parser_header_budget(size_t l0);
static void* vader_parser_ident_expr(void* l0, vader_string_t l1);
static void* vader_parser_infix_for(uint8_t l0);
static bool vader_parser_is_angle_scan_bailout(uint8_t l0);
static bool vader_parser_is_impl_decl(void* l0);
static bool vader_parser_is_literal_start(void* l0);
static bool vader_parser_is_module_segment_continue(uint32_t l0);
static bool vader_parser_is_module_segment_start(uint32_t l0);
static bool vader_parser_is_valid_module_name(vader_string_t l0);
static uint8_t vader_parser_kind_after_bracket_group(void* l0);
static void* vader_parser_lift_trailing_return(void* l0);
static bool vader_parser_looks_like_for_destructure(void* l0);
static bool vader_parser_looks_like_struct_lit_body(void* l0, int32_t l1);
static vader_box_t vader_parser_match_kind(void* l0, uint8_t l1);
static void* vader_parser_match_or_peek(void* l0, uint8_t l1);
static void* vader_parser_merge_type_params(void* l0, void* l1);
static void* vader_parser_new_parser(void* l0, vader_string_t l1);
static void* vader_parser_no_infix(void);
static void* vader_parser_parse_angle_type_params(void* l0);
static vader_box_t vader_parser_parse_assign_target(void* l0);
static void* vader_parser_parse_block(void* l0);
static void* vader_parser_parse_break(void* l0);
static void* vader_parser_parse_call_args(void* l0);
static vader_box_t vader_parser_parse_coalesce_fallback(void* l0);
static void* vader_parser_parse_const_decl(void* l0, void* l1, uint8_t l2, void* l3);
static void* vader_parser_parse_continue(void* l0);
static vader_box_t vader_parser_parse_decl(void* l0);
static vader_box_t vader_parser_parse_decorated_decl(void* l0, void* l1, uint8_t l2);
static void* vader_parser_parse_decorators(void* l0);
static void* vader_parser_parse_defer(void* l0);
static void* vader_parser_parse_destructure_assign(void* l0);
static void* vader_parser_parse_enum_decl(void* l0, void* l1, uint8_t l2, void* l3);
static vader_box_t vader_parser_parse_expr(void* l0, int32_t l1);
static void* vader_parser_parse_fn_body_tail(void* l0, vader_box_t l1);
static void* vader_parser_parse_fn_decl(void* l0, void* l1, uint8_t l2, void* l3);
static vader_box_t vader_parser_parse_fn_decl_inside_trait(void* l0);
static void* vader_parser_parse_fn_signature_params(void* l0);
static void* vader_parser_parse_fn_type(void* l0);
static void* vader_parser_parse_for(void* l0, vader_box_t l1, bool l2);
static vader_box_t vader_parser_parse_ident_or_struct_lit(void* l0);
static void* vader_parser_parse_if_expr(void* l0);
static void* vader_parser_parse_impl_decl(void* l0, void* l1);
static void* vader_parser_parse_import_decl(void* l0, void* l1);
static void* vader_parser_parse_import_name_list_rest(void* l0);
static void* vader_parser_parse_lambda(void* l0);
static void* vader_parser_parse_lambda_without_fn(void* l0);
static void* vader_parser_parse_let(void* l0);
static vader_box_t vader_parser_parse_let_binding(void* l0);
static void* vader_parser_parse_lhs_generic_alias_decl(void* l0, void* l1, uint8_t l2);
static void* vader_parser_parse_match_arm(void* l0);
static void* vader_parser_parse_match_expr(void* l0, bool l1, bool l2);
static vader_box_t vader_parser_parse_named_decl(void* l0, void* l1, uint8_t l2);
static void* vader_parser_parse_named_import_decl(void* l0, void* l1, void* l2);
static vader_box_t vader_parser_parse_optional_module_decl(void* l0);
static vader_box_t vader_parser_parse_paren(void* l0);
static vader_box_t vader_parser_parse_pattern(void* l0);
static vader_box_t vader_parser_parse_postfix(void* l0, vader_box_t l1, void* l2);
static vader_box_t vader_parser_parse_prefix(void* l0);
static void* vader_parser_parse_program(void* l0);
static void* vader_parser_parse_return(void* l0);
static void* vader_parser_parse_sam_arrow_member(void* l0);
static void* vader_parser_parse_sam_block_member(void* l0);
static void* vader_parser_parse_seq_lit(void* l0);
static void* vader_parser_parse_single_param_lambda_tail(void* l0, void* l1);
static vader_box_t vader_parser_parse_stmt(void* l0);
static void* vader_parser_parse_string_lit(void* l0);
static void* vader_parser_parse_struct_decl(void* l0, void* l1, uint8_t l2, void* l3);
static void* vader_parser_parse_struct_lit_fields(void* l0);
static void* vader_parser_parse_struct_pattern(void* l0);
static void* vader_parser_parse_struct_type_param_list(void* l0);
static void* vader_parser_parse_trait_decl(void* l0, void* l1, uint8_t l2, void* l3);
static void* vader_parser_parse_tuple_let(void* l0);
static vader_box_t vader_parser_parse_type(void* l0);
static vader_box_t vader_parser_parse_type_intersection(void* l0);
static void* vader_parser_parse_type_list_until_angle(void* l0);
static vader_box_t vader_parser_parse_type_mut_marker(void* l0);
static vader_box_t vader_parser_parse_type_postfix(void* l0);
static vader_box_t vader_parser_parse_type_primary(void* l0);
static void* vader_parser_parse_typed_const_decl(void* l0, void* l1, uint8_t l2);
static void* vader_parser_parse_typed_let(void* l0);
static void* vader_parser_parse_yield(void* l0);
static void* vader_parser_peek(void* l0);
static void* vader_parser_peek_at(void* l0, int32_t l1);
static bool vader_parser_peek_is_classic_impl_body(void* l0);
static bool vader_parser_peek_is_lhs_generic_alias_head(void* l0);
static bool vader_parser_peek_lambda_without_fn(void* l0);
static int32_t vader_parser_postfix_bp(uint8_t l0);
static void vader_parser_reject_arm_binding(void* l0);
static void vader_parser_reject_c_decorators(void* l0, void* l1, vader_string_t l2);
static void vader_parser_reject_displayable_decorator(void* l0, void* l1);
static void vader_parser_reject_removed_const(void* l0);
static void vader_parser_reject_target_decorator(void* l0, void* l1, vader_string_t l2);
static void* vader_parser_reject_tuple_pattern(void* l0);
static void vader_parser_report_nesting_too_deep(void* l0, vader_string_t l1);
static bool vader_parser_scan_angle_generic(void* l0, int32_t l1);
static size_t vader_parser_skip_block_comment(void* l0, size_t l1, size_t l2);
static void vader_parser_skip_newlines(void* l0);
static size_t vader_parser_skip_to_eol(void* l0, size_t l1, size_t l2);
static void* vader_parser_span_of(void* l0, void* l1, void* l2);
static void vader_parser_sync_to_top_level(void* l0);
static void vader_parser_walk_assign_target(vader_box_t l0, void* l1);
static void vader_parser_walk_block(void* l0, void* l1);
static void vader_parser_walk_decl(vader_box_t l0, void* l1);
static void vader_parser_walk_decorator(void* l0, void* l1);
static void vader_parser_walk_expr(vader_box_t l0, void* l1);
static void vader_parser_walk_fn_decl(void* l0, void* l1);
static void vader_parser_walk_fn_param(void* l0, void* l1);
static void vader_parser_walk_for_form(vader_box_t l0, void* l1);
static void vader_parser_walk_import_binding(vader_box_t l0, void* l1);
static void vader_parser_walk_let_binding(vader_box_t l0, void* l1);
static void vader_parser_walk_pattern(vader_box_t l0, void* l1);
static void vader_parser_walk_stmt(vader_box_t l0, void* l1);
static void vader_parser_walk_struct_lit_items(void* l0, void* l1);
static void vader_parser_walk_type_param(void* l0, void* l1);
static void* vader_parser_wrap_as_block(vader_box_t l0);

static void* vader_parser_advance(void* l0) {
    void* l1;
    int32_t l2, l3;
    size_t t0;
    int32_t t1;
    l1 = vader_parser_peek(l0);
    if (((vader_struct_vader_parser_Parser_t*) l0)->f_shr_pending_half.tag == 0u) {
        l2 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pos;
        t0 = ((vader_array_t*) ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens)->length;
        l3 = (((int32_t) (size_t) t0) - INT32_C(1));
        if ((l2 < l3)) {
            t1 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pos;
            l2 = (t1 + INT32_C(1));
            ((vader_struct_vader_parser_Parser_t*) l0)->f_pos = l2;
        }
        return l1;
    }
    ((vader_struct_vader_parser_Parser_t*) l0)->f_shr_pending_half = vader_box_obj(0u, NULL);
    VADER_WRITE_BARRIER((vader_struct_vader_parser_Parser_t*) l0);
    return l1;
}

void vader_parser_assign_block_ids(void* l0, void* l1) {
    vader_parser_walk_block(l0, l1);
    return;
}

void vader_parser_assign_program_ids(void* l0, void* l1) {
    size_t l2, l5;
    vader_box_t l3;
    void* l4;
    vader_box_t t0;
    int64_t t1;
    l2 = vader_parser_mint(l1);
    ((vader_struct_toolchain_ast_Program_t*) l0)->f_id = l2;
    l3 = ((vader_struct_toolchain_ast_Program_t*) l0)->f_module;
    if (!(l3.tag == 0u)) {
        if (!(l3.tag == 484u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = ((vader_struct_toolchain_ast_Program_t*) l0)->f_module;
        l4 = t0.payload.obj;
        l2 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_ModuleDecl_t*) l4)->f_id = l2;
    }
    l4 = ((vader_struct_toolchain_ast_Program_t*) l0)->f_decls;
    l2 = ((vader_array_t*) l4)->length;
    l5 = (size_t) 0;
    while ((l5 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        vader_parser_walk_decl(t0, l1);
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    return;
}

static bool vader_parser_at_top_level_start(void* l0) {
    void* l1;
    void* l2;
    l1 = vader_parser_peek(l0);
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(28)) {
        return true;
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(30)) {
        return true;
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(2)) {
        l2 = vader_parser_peek_at(l0, INT32_C(1));
        if (((vader_struct_vader_lexer_Token_t*) l2)->f_kind == INT32_C(65)) {
            return true;
        }
        if (((vader_struct_vader_lexer_Token_t*) l2)->f_kind == INT32_C(14)) {
            return true;
        }
    }
    if (!(((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(72))) {
        return false;
    }
    return true;
}

static bool vader_parser_check(void* l0, uint8_t l1) {
    void* t0;
    t0 = vader_parser_peek(l0);
    return ((vader_struct_vader_lexer_Token_t*) t0)->f_kind == l1;
}

static bool vader_parser_check_at(void* l0, uint8_t l1, int32_t l2) {
    void* t0;
    t0 = vader_parser_peek_at(l0, l2);
    return ((vader_struct_vader_lexer_Token_t*) t0)->f_kind == l1;
}

static bool vader_parser_check_closing_angle(void* l0) {
    uint8_t l1;
    void* t0;
    if (!(((vader_struct_vader_parser_Parser_t*) l0)->f_shr_pending_half.tag == 0u)) {
        return true;
    }
    t0 = vader_parser_peek(l0);
    l1 = ((vader_struct_vader_lexer_Token_t*) t0)->f_kind;
    if (l1 == INT32_C(51)) {
        return true;
    }
    return l1 == INT32_C(46);
}

static void vader_parser_collect_type_params(vader_box_t l0, void* l1) {
    bool l2;
    void* l3 = NULL;
    size_t l4, l5;
    vader_string_t l6 = 0;
    vader_string_t l7 = 0;
    void* t0 = NULL;
    bool t1;
    int64_t t2;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &t3 };
    void** gc_raw_roots[3] = { &l1, &l3, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l6, &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 466u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_toolchain_ast_IdentExpr_t*) t0)->f_is_type_param_intro;
        if (!(t1)) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        l2 = false;
        l3 = l1;
        l4 = ((vader_array_t*) l3)->length;
        l5 = (size_t) 0;
        while ((l5 < l4)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
            l6 = ((vader_struct_toolchain_ast_TypeParam_t*) t0)->f_name;
            t0 = l0.payload.obj;
            l7 = ((vader_struct_toolchain_ast_IdentExpr_t*) t0)->f_name;
            if (l6 == l7) {
                l2 = true;
                break;
            }
            t2 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t2;
        }
        if (!(l2)) {
            t0 = l0.payload.obj;
            l3 = ((vader_struct_toolchain_ast_IdentExpr_t*) t0)->f_span;
            t0 = l0.payload.obj;
            l6 = ((vader_struct_toolchain_ast_IdentExpr_t*) t0)->f_name;
            vader_struct_toolchain_ast_TypeParam_t* _a1_obj = (vader_struct_toolchain_ast_TypeParam_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_TypeParam_t));
            vader_obj_header_init(_a1_obj, 515u);
            _a1_obj->f_span = l3;
            _a1_obj->f_id = (size_t) 0;
            _a1_obj->f_name = l6;
            _a1_obj->f_bound = vader_box_obj(0u, NULL);
            _a1_obj->f_default_v = vader_box_obj(0u, NULL);
            _a1_obj->f_is_comptime_value = false;
            l3 = (void*) _a1_obj;
            vader_array_push((vader_array_t*) l1, vader_ref_box(l3));
        }
    } else if (l0.tag == 436u) {
        t0 = l0.payload.obj;
        vader_parser_collect_type_params(((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_left, l1);
        t0 = l0.payload.obj;
        vader_parser_collect_type_params(((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_right, l1);
    } else if (l0.tag == 463u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_toolchain_ast_FnTypeExpr_t*) t0)->f_params;
        l4 = ((vader_array_t*) l3)->length;
        l5 = (size_t) 0;
        while ((l5 < l4)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
            t3 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
            vader_parser_collect_type_params(t3, l1);
            t2 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t2;
        }
        t0 = l0.payload.obj;
        vader_parser_collect_type_params(((vader_struct_toolchain_ast_FnTypeExpr_t*) t0)->f_return_type, l1);
    } else if (l0.tag == 431u) {
        t0 = l0.payload.obj;
        vader_parser_collect_type_params(((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t0)->f_element, l1);
    } else if (l0.tag == 500u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_toolchain_ast_SeqLitExpr_t*) t0)->f_elements;
        l4 = ((vader_array_t*) l3)->length;
        l5 = (size_t) 0;
        while ((l5 < l4)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
            t3 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l5);
            vader_parser_collect_type_params(t3, l1);
            t2 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t2;
        }
    } else if (l0.tag == 465u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_toolchain_ast_GenericInstExpr_t*) t0)->f_type_args;
        l4 = ((vader_array_t*) l3)->length;
        l5 = (size_t) 0;
        while ((l5 < l4)) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
            t3 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l5);
            vader_parser_collect_type_params(t3, l1);
            t2 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t2;
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_parser_compound_op(uint8_t l0) {
    void* l1 = NULL;
    void** gc_raw_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(60)) {
        vader_struct_vader_parser_CompoundOpResult_t* _a0_obj = (vader_struct_vader_parser_CompoundOpResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_CompoundOpResult_t));
        vader_obj_header_init(_a0_obj, 977u);
        _a0_obj->f_matched = true;
        _a0_obj->f_op = (uint8_t) 0;
        l1 = (void*) _a0_obj;
        { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(61)) {
        vader_struct_vader_parser_CompoundOpResult_t* _a1_obj = (vader_struct_vader_parser_CompoundOpResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_CompoundOpResult_t));
        vader_obj_header_init(_a1_obj, 977u);
        _a1_obj->f_matched = true;
        _a1_obj->f_op = (uint8_t) 1;
        l1 = (void*) _a1_obj;
    } else if (l0 == INT32_C(62)) {
        vader_struct_vader_parser_CompoundOpResult_t* _a2_obj = (vader_struct_vader_parser_CompoundOpResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_CompoundOpResult_t));
        vader_obj_header_init(_a2_obj, 977u);
        _a2_obj->f_matched = true;
        _a2_obj->f_op = (uint8_t) 2;
        l1 = (void*) _a2_obj;
    } else if (l0 == INT32_C(63)) {
        vader_struct_vader_parser_CompoundOpResult_t* _a3_obj = (vader_struct_vader_parser_CompoundOpResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_CompoundOpResult_t));
        vader_obj_header_init(_a3_obj, 977u);
        _a3_obj->f_matched = true;
        _a3_obj->f_op = (uint8_t) 3;
        l1 = (void*) _a3_obj;
    } else if (l0 == INT32_C(64)) {
        vader_struct_vader_parser_CompoundOpResult_t* _a4_obj = (vader_struct_vader_parser_CompoundOpResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_CompoundOpResult_t));
        vader_obj_header_init(_a4_obj, 977u);
        _a4_obj->f_matched = true;
        _a4_obj->f_op = (uint8_t) 4;
        l1 = (void*) _a4_obj;
    } else {
        vader_struct_vader_parser_CompoundOpResult_t* _a5_obj = (vader_struct_vader_parser_CompoundOpResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_CompoundOpResult_t));
        vader_obj_header_init(_a5_obj, 977u);
        _a5_obj->f_matched = false;
        _a5_obj->f_op = (uint8_t) 0;
        l1 = (void*) _a5_obj;
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_consume_closing_angle(void* l0) {
    vader_box_t l1 = vader_box_null();
    void* l2 = NULL;
    void* l4 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    size_t l3, l11;
    int32_t l5, l6;
    vader_string_t l7 = 0;
    size_t t0;
    int32_t t1;
    int64_t t2;
    void* t3 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[7] = { &l0, &l2, &l4, &l8, &l9, &l10, &t3 };
    vader_string_t* gc_atom_roots[1] = { &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_parser_Parser_t*) l0)->f_shr_pending_half;
    if (l1.tag == 0u) {
        l2 = vader_parser_peek(l0);
        if (((vader_struct_vader_lexer_Token_t*) l2)->f_kind == INT32_C(51)) {
            l5 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pos;
            t0 = ((vader_array_t*) ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens)->length;
            l6 = (((int32_t) (size_t) t0) - INT32_C(1));
            if ((l5 < l6)) {
                t1 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pos;
                l5 = (t1 + INT32_C(1));
                ((vader_struct_vader_parser_Parser_t*) l0)->f_pos = l5;
                { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
            }
            { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (!(((vader_struct_vader_lexer_Token_t*) l2)->f_kind == INT32_C(46))) {
            { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l2)->f_span)->f_start)->f_file;
        t0 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l2)->f_span)->f_start)->f_offset;
        t2 = (t0 + INT64_C(1));
        l3 = (size_t) (int64_t) t2;
        l5 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l2)->f_span)->f_start)->f_line;
        t1 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l2)->f_span)->f_start)->f_column;
        l6 = (t1 + INT32_C(1));
        vader_struct_toolchain_span_Position_t* _a0_obj = (vader_struct_toolchain_span_Position_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Position_t));
        vader_obj_header_init(_a0_obj, 523u);
        _a0_obj->f_file = l7;
        _a0_obj->f_offset = l3;
        _a0_obj->f_line = l5;
        _a0_obj->f_column = l6;
        l4 = (void*) _a0_obj;
        vader_struct_toolchain_span_Span_t* _a1_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
        vader_obj_header_init(_a1_obj, 524u);
        _a1_obj->f_start = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l2)->f_span)->f_start;
        _a1_obj->f_end = l4;
        l8 = (void*) _a1_obj;
        vader_struct_vader_lexer_Token_t* _a2_obj = (vader_struct_vader_lexer_Token_t*) vader_gc_alloc(sizeof(vader_struct_vader_lexer_Token_t));
        vader_obj_header_init(_a2_obj, 802u);
        _a2_obj->f_kind = (uint8_t) 51;
        _a2_obj->f_text = 395u;
        _a2_obj->f_span = l8;
        _a2_obj->f_value = vader_box_obj(0u, NULL);
        l8 = (void*) _a2_obj;
        l9 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l2)->f_span)->f_end;
        vader_struct_toolchain_span_Span_t* _a3_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
        vader_obj_header_init(_a3_obj, 524u);
        _a3_obj->f_start = l4;
        _a3_obj->f_end = l9;
        l9 = (void*) _a3_obj;
        vader_struct_vader_lexer_Token_t* _a4_obj = (vader_struct_vader_lexer_Token_t*) vader_gc_alloc(sizeof(vader_struct_vader_lexer_Token_t));
        vader_obj_header_init(_a4_obj, 802u);
        _a4_obj->f_kind = (uint8_t) 51;
        _a4_obj->f_text = 395u;
        _a4_obj->f_span = l9;
        _a4_obj->f_value = vader_box_obj(0u, NULL);
        l9 = (void*) _a4_obj;
        l10 = ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens;
        t1 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pos;
        t2 = ((int64_t) (int32_t) t1);
        l11 = (size_t) (int64_t) t2;
        vader_array_t* _a5_slotarr = ((vader_array_t*) l10);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l11)
        vader_array_ref_store(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l11, l8);
        VADER_WRITE_BARRIER(_a5_slotarr->buf);
        ((vader_struct_vader_parser_Parser_t*) l0)->f_shr_pending_half = vader_ref_box(l9);
        VADER_WRITE_BARRIER((vader_struct_vader_parser_Parser_t*) l0);
        l5 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pos;
        t0 = ((vader_array_t*) ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens)->length;
        l6 = (((int32_t) (size_t) t0) - INT32_C(1));
        if ((l5 < l6)) {
            t1 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pos;
            l5 = (t1 + INT32_C(1));
            ((vader_struct_vader_parser_Parser_t*) l0)->f_pos = l5;
            { void* __vret = l8; vader_gc_top = gc_frame.prev; return __vret; }
        }
        { void* __vret = l8; vader_gc_top = gc_frame.prev; return __vret; }
    }
    ((vader_struct_vader_parser_Parser_t*) l0)->f_shr_pending_half = vader_box_obj(0u, NULL);
    VADER_WRITE_BARRIER((vader_struct_vader_parser_Parser_t*) l0);
    t1 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pos;
    if ((t1 > INT32_C(0))) {
        l2 = ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens;
        t1 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pos;
        t2 = ((int64_t) (int32_t) (t1 - INT32_C(1)));
        l3 = (size_t) (int64_t) t2;
        l4 = l1.payload.obj;
        vader_array_t* _a6_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l3)
        vader_array_ref_store(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l3, l4);
        VADER_WRITE_BARRIER(_a6_slotarr->buf);
        t3 = l1.payload.obj;
        { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t3 = l1.payload.obj;
    { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_parser_describe_token(void* l0) {
    vader_string_t l1 = 0;
    bool l2;
    vader_string_t t0 = 0;
    bool t1;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (((vader_struct_vader_lexer_Token_t*) l0)->f_kind == INT32_C(2)) {
        l1 = ((vader_struct_vader_lexer_Token_t*) l0)->f_text;
        t0 = concat_3(850u, l1, 850u);
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
        { vader_gc_top = gc_frame.prev; return 2008u; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l0)->f_kind == INT32_C(0)) {
        { vader_gc_top = gc_frame.prev; return 1541u; }
    }
    t0 = ((vader_struct_vader_lexer_Token_t*) l0)->f_text;
    t1 = std_string_is_empty(t0);
    if (!(t1)) {
        l1 = ((vader_struct_vader_lexer_Token_t*) l0)->f_text;
        t0 = concat_3(850u, l1, 850u);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_lexer_kind_name(((vader_struct_vader_lexer_Token_t*) l0)->f_kind);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_desugar_comptime_const(void* l0, void* l1, uint8_t l2, void* l3, vader_box_t l4) {
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
    vader_string_t l10 = 0;
    size_t l16, l17;
    bool t0;
    void* t1 = NULL;
    int64_t t2;
    vader_box_t* gc_roots[2] = { &l4, &l6 };
    void** gc_raw_roots[12] = { &l0, &l1, &l3, &l5, &l7, &l9, &l11, &l12, &l13, &l14, &l15, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l10 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l5 = vader_parser_advance(l0);
    vader_parser_advance(l0);
    t0 = vader_parser_check(l0, (uint8_t) 78);
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
    l10 = concat_2(816u, l10);
    l11 = vader_parser_span_of(l0, l5, l9);
    l12 = ((vader_struct_vader_lexer_Token_t*) l3)->f_span;
    vader_array_t* _a0_arr = vader_array_new(38u, 0u, 13u, 515u);
    l13 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(28u, 0u, 13u, 462u);
    l14 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(25u, 0u, 13u, 446u);
    l15 = (void*) _a2_arr;
    vader_struct_toolchain_ast_FnDecl_t* _a3_obj = (vader_struct_toolchain_ast_FnDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FnDecl_t));
    vader_obj_header_init(_a3_obj, 461u);
    _a3_obj->f_span = l11;
    _a3_obj->f_id = (size_t) 0;
    _a3_obj->f_name = l10;
    _a3_obj->f_name_span = l12;
    _a3_obj->f_visibility = (uint8_t) 1;
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
    vader_array_t* _a4_arr = vader_array_new(23u, 0u, 13u, 440u);
    l11 = (void*) _a4_arr;
    vader_struct_toolchain_ast_CallExpr_t* _a5_obj = (vader_struct_toolchain_ast_CallExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_CallExpr_t));
    vader_obj_header_init(_a5_obj, 441u);
    _a5_obj->f_span = l5;
    _a5_obj->f_id = (size_t) 0;
    _a5_obj->f_callee = vader_ref_box(l7);
    _a5_obj->f_args = l11;
    _a5_obj->f_trailing_comma = false;
    l5 = (void*) _a5_obj;
    vader_array_t* _a6_arr = vader_array_new(25u, 0u, 13u, 446u);
    l7 = (void*) _a6_arr;
    l16 = ((vader_array_t*) l1)->length;
    vader_array_t* _a7_arr = vader_array_repeat((vader_array_t*) l7, (size_t) l16);
    l7 = (void*) _a7_arr;
    l11 = l1;
    l16 = ((vader_array_t*) l11)->length;
    l17 = (size_t) 0;
    while ((l17 < l16)) {
        vader_array_t* _a8_slotarr = ((vader_array_t*) l11);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l17)
        l12 = vader_array_ref_load_obj(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l17);
        vader_array_push((vader_array_t*) l7, vader_ref_box(l12));
        t2 = (l17 + INT64_C(1));
        l17 = (size_t) (int64_t) t2;
    }
    l11 = ((vader_struct_vader_lexer_Token_t*) l3)->f_span;
    vader_array_t* _a9_arr = vader_array_new(175u, 0u, 13u, 1241u);
    l12 = (void*) _a9_arr;
    vader_struct_toolchain_ast_Decorator_t* _a10_obj = (vader_struct_toolchain_ast_Decorator_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_Decorator_t));
    vader_obj_header_init(_a10_obj, 446u);
    _a10_obj->f_span = l11;
    _a10_obj->f_id = (size_t) 0;
    _a10_obj->f_name = 1454u;
    _a10_obj->f_args = l12;
    l11 = (void*) _a10_obj;
    vader_array_push((vader_array_t*) l7, vader_ref_box(l11));
    l9 = vader_parser_span_of(l0, l3, l9);
    l10 = ((vader_struct_vader_lexer_Token_t*) l3)->f_text;
    l11 = ((vader_struct_vader_lexer_Token_t*) l3)->f_span;
    vader_struct_toolchain_ast_ConstDecl_t* _a11_obj = (vader_struct_toolchain_ast_ConstDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ConstDecl_t));
    vader_obj_header_init(_a11_obj, 444u);
    _a11_obj->f_span = l9;
    _a11_obj->f_id = (size_t) 0;
    _a11_obj->f_name = l10;
    _a11_obj->f_name_span = l11;
    _a11_obj->f_visibility = l2;
    _a11_obj->f_ty = l4;
    _a11_obj->f_value = vader_ref_box(l5);
    _a11_obj->f_decorators = l7;
    _a11_obj->f_comptime_body = l6;
    t1 = (void*) _a11_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_empty_token(void) {
    void* l0 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l0 = vader_lexer_empty_file_span(0u);
    t0 = vader_lexer_make_token((uint8_t) 0, 0u, l0);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_parser_error(void* l0, uint8_t l1, void* l2, vader_string_t l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    bool t0;
    void** gc_raw_roots[4] = { &l0, &l2, &l4, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_parser_Parser_t*) l0)->f_depth_exceeded;
    if (!(t0)) {
        l4 = ((vader_struct_vader_parser_Parser_t*) l0)->f_errors;
        l5 = vader_diagnostics_parser_error(l1, l2, l3);
        vader_array_push((vader_array_t*) l4, vader_ref_box(l5));
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_parser_expect(void* l0, uint8_t l1, vader_string_t l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    vader_string_t l5 = 0;
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[4] = { &l0, &l3, &l4, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l2, &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_parser_check(l0, l1);
    if (!(t0)) {
        l3 = vader_parser_peek(l0);
        l4 = ((vader_struct_vader_lexer_Token_t*) l3)->f_span;
        l5 = vader_parser_describe_token(l3);
        l5 = concat_5(1569u, l2, 26u, l5, 243u);
        vader_parser_error(l0, (uint8_t) 1, l4, l5);
        { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_parser_advance(l0);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_expect_string_literal(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l5 = NULL;
    void* l8 = NULL;
    vader_string_t l4 = 0;
    vader_string_t l7 = 0;
    vader_box_t l6 = vader_box_null();
    bool t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l6 };
    void** gc_raw_roots[6] = { &l0, &l2, &l3, &l5, &l8, &t1 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l4, &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_parser_check(l0, (uint8_t) 6);
    if (!(t0)) {
        l2 = vader_parser_peek(l0);
        l3 = ((vader_struct_vader_lexer_Token_t*) l2)->f_span;
        l4 = vader_parser_describe_token(l2);
        l4 = concat_5(1569u, l1, 26u, l4, 243u);
        vader_parser_error(l0, (uint8_t) 1, l3, l4);
        l2 = ((vader_struct_vader_lexer_Token_t*) l2)->f_span;
        vader_struct_vader_parser_StringLitInfo_t* _a0_obj = (vader_struct_vader_parser_StringLitInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_StringLitInfo_t));
        vader_obj_header_init(_a0_obj, 986u);
        _a0_obj->f_text = 0u;
        _a0_obj->f_span = l2;
        t1 = (void*) _a0_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = vader_parser_advance(l0);
    vader_array_t* _a1_arr = vader_array_new(11u, 0u, 0u, 240u);
    t1 = (void*) _a1_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a2_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a2_obj, 430u);
    _a2_obj->f_parts = t1;
    l3 = (void*) _a2_obj;
    for (;;) {
        t0 = vader_parser_check(l0, (uint8_t) 8);
        if (!(t0)) {
            t0 = vader_parser_check(l0, (uint8_t) 0);
            if (t0) break;
            l5 = vader_parser_advance(l0);
            if (((vader_struct_vader_lexer_Token_t*) l5)->f_kind == INT32_C(7)) {
                l6 = ((vader_struct_vader_lexer_Token_t*) l5)->f_value;
                if (l6.tag == 240u) {
                    l4 = l6.payload.s;
                    std_string_builder_append(l3, l4);
                } else {
                    l7 = ((vader_struct_vader_lexer_Token_t*) l5)->f_text;
                    std_string_builder_append(l3, l7);
                }
            }
            if (!(((vader_struct_vader_lexer_Token_t*) l5)->f_kind == INT32_C(9))) {
                continue;
            }
            l8 = ((vader_struct_vader_lexer_Token_t*) l5)->f_span;
            vader_parser_error(l0, (uint8_t) 0, l8, 1836u);
            for (;;) {
                t0 = vader_parser_check(l0, (uint8_t) 10);
                if (!(t0)) {
                    t0 = vader_parser_check(l0, (uint8_t) 0);
                    if (t0) break;
                    vader_parser_advance(l0);
                    continue;
                }
                break;
            }
            continue;
        }
        break;
    }
    l5 = vader_parser_match_or_peek(l0, (uint8_t) 8);
    l4 = std_string_builder_StringBuilder_Display_to_string(l3);
    l2 = vader_parser_span_of(l0, l2, l5);
    vader_struct_vader_parser_StringLitInfo_t* _a3_obj = (vader_struct_vader_parser_StringLitInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_StringLitInfo_t));
    vader_obj_header_init(_a3_obj, 986u);
    _a3_obj->f_text = l4;
    _a3_obj->f_span = l2;
    t1 = (void*) _a3_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static size_t vader_parser_header_budget(size_t l0) {
    size_t l1;
    l1 = (size_t) 4096;
    if (!((l0 < l1))) {
        return l1;
    }
    return l0;
}

static void* vader_parser_ident_expr(void* l0, vader_string_t l1) {
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_toolchain_ast_IdentExpr_t* _a0_obj = (vader_struct_toolchain_ast_IdentExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_IdentExpr_t));
    vader_obj_header_init(_a0_obj, 466u);
    _a0_obj->f_span = l0;
    _a0_obj->f_id = (size_t) 0;
    _a0_obj->f_name = l1;
    _a0_obj->f_implicit_dot = false;
    _a0_obj->f_is_type_param_intro = false;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_infix_for(uint8_t l0) {
    void* l1 = NULL;
    void** gc_raw_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(56)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a0_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a0_obj, 980u);
        _a0_obj->f_has = true;
        _a0_obj->f_left_bp = INT32_C(10);
        _a0_obj->f_right_bp = INT32_C(11);
        _a0_obj->f_op = (uint8_t) 11;
        _a0_obj->f_non_assoc = false;
        l1 = (void*) _a0_obj;
        { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(55)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a1_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a1_obj, 980u);
        _a1_obj->f_has = true;
        _a1_obj->f_left_bp = INT32_C(12);
        _a1_obj->f_right_bp = INT32_C(13);
        _a1_obj->f_op = (uint8_t) 10;
        _a1_obj->f_non_assoc = false;
        l1 = (void*) _a1_obj;
    } else if (l0 == INT32_C(47)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a2_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a2_obj, 980u);
        _a2_obj->f_has = true;
        _a2_obj->f_left_bp = INT32_C(20);
        _a2_obj->f_right_bp = INT32_C(20);
        _a2_obj->f_op = (uint8_t) 12;
        _a2_obj->f_non_assoc = true;
        l1 = (void*) _a2_obj;
    } else if (l0 == INT32_C(48)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a3_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a3_obj, 980u);
        _a3_obj->f_has = true;
        _a3_obj->f_left_bp = INT32_C(20);
        _a3_obj->f_right_bp = INT32_C(20);
        _a3_obj->f_op = (uint8_t) 13;
        _a3_obj->f_non_assoc = true;
        l1 = (void*) _a3_obj;
    } else if (l0 == INT32_C(53)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a4_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a4_obj, 980u);
        _a4_obj->f_has = true;
        _a4_obj->f_left_bp = INT32_C(20);
        _a4_obj->f_right_bp = INT32_C(20);
        _a4_obj->f_op = (uint8_t) 21;
        _a4_obj->f_non_assoc = true;
        l1 = (void*) _a4_obj;
    } else if (l0 == INT32_C(54)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a5_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a5_obj, 980u);
        _a5_obj->f_has = true;
        _a5_obj->f_left_bp = INT32_C(20);
        _a5_obj->f_right_bp = INT32_C(20);
        _a5_obj->f_op = (uint8_t) 22;
        _a5_obj->f_non_assoc = true;
        l1 = (void*) _a5_obj;
    } else if (l0 == INT32_C(49)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a6_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a6_obj, 980u);
        _a6_obj->f_has = true;
        _a6_obj->f_left_bp = INT32_C(20);
        _a6_obj->f_right_bp = INT32_C(20);
        _a6_obj->f_op = (uint8_t) 14;
        _a6_obj->f_non_assoc = true;
        l1 = (void*) _a6_obj;
    } else if (l0 == INT32_C(50)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a7_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a7_obj, 980u);
        _a7_obj->f_has = true;
        _a7_obj->f_left_bp = INT32_C(20);
        _a7_obj->f_right_bp = INT32_C(20);
        _a7_obj->f_op = (uint8_t) 15;
        _a7_obj->f_non_assoc = true;
        l1 = (void*) _a7_obj;
    } else if (l0 == INT32_C(51)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a8_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a8_obj, 980u);
        _a8_obj->f_has = true;
        _a8_obj->f_left_bp = INT32_C(20);
        _a8_obj->f_right_bp = INT32_C(20);
        _a8_obj->f_op = (uint8_t) 16;
        _a8_obj->f_non_assoc = true;
        l1 = (void*) _a8_obj;
    } else if (l0 == INT32_C(52)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a9_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a9_obj, 980u);
        _a9_obj->f_has = true;
        _a9_obj->f_left_bp = INT32_C(20);
        _a9_obj->f_right_bp = INT32_C(20);
        _a9_obj->f_op = (uint8_t) 17;
        _a9_obj->f_non_assoc = true;
        l1 = (void*) _a9_obj;
    } else if (l0 == INT32_C(19)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a10_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a10_obj, 980u);
        _a10_obj->f_has = true;
        _a10_obj->f_left_bp = INT32_C(20);
        _a10_obj->f_right_bp = INT32_C(20);
        _a10_obj->f_op = (uint8_t) 18;
        _a10_obj->f_non_assoc = true;
        l1 = (void*) _a10_obj;
    } else if (l0 == INT32_C(21)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a11_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a11_obj, 980u);
        _a11_obj->f_has = true;
        _a11_obj->f_left_bp = INT32_C(20);
        _a11_obj->f_right_bp = INT32_C(20);
        _a11_obj->f_op = (uint8_t) 19;
        _a11_obj->f_non_assoc = true;
        l1 = (void*) _a11_obj;
    } else if (l0 == INT32_C(67)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a12_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a12_obj, 980u);
        _a12_obj->f_has = true;
        _a12_obj->f_left_bp = INT32_C(30);
        _a12_obj->f_right_bp = INT32_C(30);
        _a12_obj->f_op = (uint8_t) 14;
        _a12_obj->f_non_assoc = true;
        l1 = (void*) _a12_obj;
    } else if (l0 == INT32_C(68)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a13_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a13_obj, 980u);
        _a13_obj->f_has = true;
        _a13_obj->f_left_bp = INT32_C(30);
        _a13_obj->f_right_bp = INT32_C(30);
        _a13_obj->f_op = (uint8_t) 15;
        _a13_obj->f_non_assoc = true;
        l1 = (void*) _a13_obj;
    } else if (l0 == INT32_C(69)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(42)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a14_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a14_obj, 980u);
        _a14_obj->f_has = true;
        _a14_obj->f_left_bp = INT32_C(40);
        _a14_obj->f_right_bp = INT32_C(41);
        _a14_obj->f_op = (uint8_t) 8;
        _a14_obj->f_non_assoc = false;
        l1 = (void*) _a14_obj;
    } else if (l0 == INT32_C(43)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a15_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a15_obj, 980u);
        _a15_obj->f_has = true;
        _a15_obj->f_left_bp = INT32_C(50);
        _a15_obj->f_right_bp = INT32_C(51);
        _a15_obj->f_op = (uint8_t) 9;
        _a15_obj->f_non_assoc = false;
        l1 = (void*) _a15_obj;
    } else if (l0 == INT32_C(41)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a16_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a16_obj, 980u);
        _a16_obj->f_has = true;
        _a16_obj->f_left_bp = INT32_C(60);
        _a16_obj->f_right_bp = INT32_C(61);
        _a16_obj->f_op = (uint8_t) 7;
        _a16_obj->f_non_assoc = false;
        l1 = (void*) _a16_obj;
    } else if (l0 == INT32_C(45)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a17_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a17_obj, 980u);
        _a17_obj->f_has = true;
        _a17_obj->f_left_bp = INT32_C(70);
        _a17_obj->f_right_bp = INT32_C(71);
        _a17_obj->f_op = (uint8_t) 5;
        _a17_obj->f_non_assoc = false;
        l1 = (void*) _a17_obj;
    } else if (l0 == INT32_C(46)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a18_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a18_obj, 980u);
        _a18_obj->f_has = true;
        _a18_obj->f_left_bp = INT32_C(70);
        _a18_obj->f_right_bp = INT32_C(71);
        _a18_obj->f_op = (uint8_t) 6;
        _a18_obj->f_non_assoc = false;
        l1 = (void*) _a18_obj;
    } else if (l0 == INT32_C(36)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a19_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a19_obj, 980u);
        _a19_obj->f_has = true;
        _a19_obj->f_left_bp = INT32_C(80);
        _a19_obj->f_right_bp = INT32_C(81);
        _a19_obj->f_op = (uint8_t) 0;
        _a19_obj->f_non_assoc = false;
        l1 = (void*) _a19_obj;
    } else if (l0 == INT32_C(37)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a20_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a20_obj, 980u);
        _a20_obj->f_has = true;
        _a20_obj->f_left_bp = INT32_C(80);
        _a20_obj->f_right_bp = INT32_C(81);
        _a20_obj->f_op = (uint8_t) 1;
        _a20_obj->f_non_assoc = false;
        l1 = (void*) _a20_obj;
    } else if (l0 == INT32_C(38)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a21_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a21_obj, 980u);
        _a21_obj->f_has = true;
        _a21_obj->f_left_bp = INT32_C(90);
        _a21_obj->f_right_bp = INT32_C(91);
        _a21_obj->f_op = (uint8_t) 2;
        _a21_obj->f_non_assoc = false;
        l1 = (void*) _a21_obj;
    } else if (l0 == INT32_C(39)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a22_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a22_obj, 980u);
        _a22_obj->f_has = true;
        _a22_obj->f_left_bp = INT32_C(90);
        _a22_obj->f_right_bp = INT32_C(91);
        _a22_obj->f_op = (uint8_t) 3;
        _a22_obj->f_non_assoc = false;
        l1 = (void*) _a22_obj;
    } else if (l0 == INT32_C(40)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a23_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a23_obj, 980u);
        _a23_obj->f_has = true;
        _a23_obj->f_left_bp = INT32_C(90);
        _a23_obj->f_right_bp = INT32_C(91);
        _a23_obj->f_op = (uint8_t) 4;
        _a23_obj->f_non_assoc = false;
        l1 = (void*) _a23_obj;
    } else if (l0 == INT32_C(0)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(1)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(2)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(3)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(4)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(5)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(6)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(7)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(8)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(9)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(10)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(44)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(57)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(58)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(59)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(60)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(61)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(62)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(63)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(64)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(65)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(66)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(70)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(71)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(72)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(73)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(74)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(75)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(76)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(77)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(78)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(79)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(80)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(81)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(82)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(11)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(12)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(13)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(14)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(15)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(16)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(17)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(18)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(20)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(22)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(23)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(24)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(25)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(26)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(27)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(28)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(29)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(30)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(31)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(32)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(33)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(34)) {
        l1 = vader_parser_no_infix();
    } else {
        if (!(l0 == INT32_C(35))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = vader_parser_no_infix();
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_parser_intrinsic_spec(vader_string_t l0) {
    void* l1;
    void* l4;
    size_t l2, l3;
    vader_string_t t0;
    int64_t t1;
    l1 = (void*) &vader_data_44;
    l2 = ((vader_array_t*) l1)->length;
    l3 = (size_t) 0;
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        t0 = ((vader_struct_vader_parser_IntrinsicSpec_t*) l4)->f_name;
        if (t0 == l0) {
            return vader_ref_box(l4);
        }
        t1 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t1;
    }
    return vader_box_obj(0u, NULL);
}

static bool vader_parser_is_angle_scan_bailout(uint8_t l0) {
    if (l0 == INT32_C(78)) {
        return true;
    }
    if (l0 == INT32_C(65)) {
        return true;
    }
    if (l0 == INT32_C(66)) {
        return true;
    }
    if (l0 == INT32_C(59)) {
        return true;
    }
    if (l0 == INT32_C(60)) {
        return true;
    }
    if (l0 == INT32_C(61)) {
        return true;
    }
    if (l0 == INT32_C(62)) {
        return true;
    }
    if (l0 == INT32_C(63)) {
        return true;
    }
    if (l0 == INT32_C(64)) {
        return true;
    }
    if (l0 == INT32_C(52)) {
        return true;
    }
    if (l0 == INT32_C(50)) {
        return true;
    }
    if (l0 == INT32_C(47)) {
        return true;
    }
    if (l0 == INT32_C(48)) {
        return true;
    }
    if (l0 == INT32_C(53)) {
        return true;
    }
    if (l0 == INT32_C(54)) {
        return true;
    }
    if (l0 == INT32_C(16)) {
        return true;
    }
    if (l0 == INT32_C(17)) {
        return true;
    }
    if (l0 == INT32_C(18)) {
        return true;
    }
    if (l0 == INT32_C(19)) {
        return true;
    }
    if (l0 == INT32_C(20)) {
        return true;
    }
    if (l0 == INT32_C(21)) {
        return true;
    }
    if (l0 == INT32_C(22)) {
        return true;
    }
    if (l0 == INT32_C(23)) {
        return true;
    }
    if (l0 == INT32_C(24)) {
        return true;
    }
    if (l0 == INT32_C(25)) {
        return true;
    }
    if (l0 == INT32_C(26)) {
        return true;
    }
    if (l0 == INT32_C(27)) {
        return true;
    }
    if (l0 == INT32_C(12)) {
        return true;
    }
    if (l0 == INT32_C(13)) {
        return true;
    }
    if (l0 == INT32_C(14)) {
        return true;
    }
    if (l0 == INT32_C(15)) {
        return true;
    }
    if (l0 == INT32_C(28)) {
        return true;
    }
    if (l0 == INT32_C(30)) {
        return true;
    }
    if (!(l0 == INT32_C(34))) {
        return false;
    }
    return true;
}

static bool vader_parser_is_impl_decl(void* l0) {
    int32_t l1, l2, l3;
    void* l4;
    void* l6;
    size_t l5;
    bool l7, l8, l9, l10;
    size_t t0;
    int64_t t1;
    l1 = INT32_C(0);
    t0 = ((vader_array_t*) ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens)->length;
    l2 = ((int32_t) (size_t) t0);
    l3 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pos;
    while ((l3 < l2)) {
        l4 = ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens;
        t1 = ((int64_t) (int32_t) l3);
        l5 = (size_t) (int64_t) t1;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        l6 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        if (((vader_struct_vader_lexer_Token_t*) l6)->f_kind == INT32_C(0)) {
            return false;
        }
        if (((vader_struct_vader_lexer_Token_t*) l6)->f_kind == INT32_C(1)) {
            return false;
        }
        if (((vader_struct_vader_lexer_Token_t*) l6)->f_kind == INT32_C(14)) {
            if (l1 == INT32_C(0)) {
                return true;
            }
        }
        if (((vader_struct_vader_lexer_Token_t*) l6)->f_kind == INT32_C(74)) {
            l7 = true;
        } else {
            l7 = ((vader_struct_vader_lexer_Token_t*) l6)->f_kind == INT32_C(76);
        }
        if (l7) {
            l8 = true;
        } else {
            l8 = ((vader_struct_vader_lexer_Token_t*) l6)->f_kind == INT32_C(78);
        }
        if (l8) {
            l1 = (l1 + INT32_C(1));
        }
        if (((vader_struct_vader_lexer_Token_t*) l6)->f_kind == INT32_C(75)) {
            l9 = true;
        } else {
            l9 = ((vader_struct_vader_lexer_Token_t*) l6)->f_kind == INT32_C(77);
        }
        if (l9) {
            l10 = true;
        } else {
            l10 = ((vader_struct_vader_lexer_Token_t*) l6)->f_kind == INT32_C(79);
        }
        if (l10) {
            l1 = (l1 - INT32_C(1));
        }
        if ((l1 < INT32_C(0))) {
            return false;
        }
        l3 = (l3 + INT32_C(1));
    }
    return false;
}

static bool vader_parser_is_literal_start(void* l0) {
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
        return true;
    }
    return ((vader_struct_vader_lexer_Token_t*) l0)->f_kind == INT32_C(37);
}

static bool vader_parser_is_module_segment_continue(uint32_t l0) {
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
        return true;
    }
    return l0 == 95u;
}

static bool vader_parser_is_module_segment_start(uint32_t l0) {
    if ((97u <= l0)) {
        return (l0 <= 122u);
    }
    return false;
}

static bool vader_parser_is_valid_module_name(vader_string_t l0) {
    bool l1, l2;
    void* l3 = NULL;
    uint32_t l4, l5;
    uint8_t l6;
    uint32_t t0;
    uint8_t t1;
    bool t2;
    void** gc_raw_roots[1] = { &l3 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = true;
    l2 = false;
    l3 = std_string_chars(l0);
    for (;;) {
        std_string_StringChars_Iterator_next_v(l3, &t0, &t1);
        l6 = t1;
        l5 = t0;
        if (!(l6 == INT32_C(1))) {
            l4 = l5;
            l2 = true;
            if (l1) {
                t2 = vader_parser_is_module_segment_start(l4);
                if (!(t2)) {
                    { vader_gc_top = gc_frame.prev; return false; }
                }
                l1 = false;
            } else if (l4 == 47u) {
                l1 = true;
            } else {
                t2 = vader_parser_is_module_segment_continue(l4);
                if (!(t2)) {
                    { vader_gc_top = gc_frame.prev; return false; }
                }
            }
            continue;
        }
        break;
    }
    if (!(l2)) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    { bool __vret = !(l1); vader_gc_top = gc_frame.prev; return __vret; }
}

static uint8_t vader_parser_kind_after_bracket_group(void* l0) {
    int32_t l1, l2, l3;
    void* l4;
    size_t l5;
    uint8_t l6;
    int32_t t0;
    size_t t1;
    int64_t t2;
    void* t3;
    l1 = INT32_C(1);
    t0 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pos;
    l2 = (t0 + INT32_C(1));
    t1 = ((vader_array_t*) ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens)->length;
    l3 = ((int32_t) (size_t) t1);
    while ((l2 < l3)) {
        if (!((l1 > INT32_C(0)))) {
            break;
        }
        l4 = ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens;
        t2 = ((int64_t) (int32_t) l2);
        l5 = (size_t) (int64_t) t2;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        t3 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        l6 = ((vader_struct_vader_lexer_Token_t*) t3)->f_kind;
        if (l6 == INT32_C(0)) {
            return (uint8_t) 0;
        }
        if (l6 == INT32_C(76)) {
            l1 = (l1 + INT32_C(1));
        } else if (l6 == INT32_C(77)) {
            l1 = (l1 - INT32_C(1));
            if (l1 == INT32_C(0)) break;
        }
        l2 = (l2 + INT32_C(1));
    }
    if (l1 != INT32_C(0)) {
        return (uint8_t) 0;
    }
    l1 = (l2 + INT32_C(1));
    while ((l1 < l3)) {
        l4 = ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens;
        t2 = ((int64_t) (int32_t) l1);
        l5 = (size_t) (int64_t) t2;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        t3 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
        if (!(((vader_struct_vader_lexer_Token_t*) t3)->f_kind == INT32_C(1))) {
            break;
        }
        l1 = (l1 + INT32_C(1));
    }
    if (!((l1 >= l3))) {
        l4 = ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens;
        t2 = ((int64_t) (int32_t) l1);
        l5 = (size_t) (int64_t) t2;
        vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
        t3 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
        return ((vader_struct_vader_lexer_Token_t*) t3)->f_kind;
    }
    return (uint8_t) 0;
}

static void* vader_parser_lift_trailing_return(void* l0) {
    size_t l1, l3;
    void* l2 = NULL;
    void* l6 = NULL;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    int64_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l4, &l5 };
    void** gc_raw_roots[4] = { &l0, &l2, &l6, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
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
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    if (l4.tag == 499u) {
        t1 = l4.payload.obj;
        if (((vader_struct_toolchain_ast_ReturnStmt_t*) t1)->f_value.tag == 0u) {
            { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_array_t* _a1_arr = vader_array_new(177u, 0u, 13u, 1262u);
        l2 = (void*) _a1_arr;
        l3 = (size_t) 0;
        t0 = (l1 - INT64_C(1));
        l1 = (size_t) (int64_t) t0;
        while ((l3 < l1)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_BlockExpr_t*) l0)->f_stmts);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
            l5 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l3);
            vader_array_push((vader_array_t*) l2, l5);
            t0 = (l3 + INT64_C(1));
            l3 = (size_t) (int64_t) t0;
        }
        l6 = ((vader_struct_toolchain_ast_BlockExpr_t*) l0)->f_span;
        t1 = l4.payload.obj;
        l4 = ((vader_struct_toolchain_ast_ReturnStmt_t*) t1)->f_value;
        vader_struct_toolchain_ast_BlockExpr_t* _a3_obj = (vader_struct_toolchain_ast_BlockExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BlockExpr_t));
        vader_obj_header_init(_a3_obj, 437u);
        _a3_obj->f_span = l6;
        _a3_obj->f_id = (size_t) 0;
        _a3_obj->f_stmts = l2;
        _a3_obj->f_trailing = l4;
        t1 = (void*) _a3_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_parser_looks_like_for_destructure(void* l0) {
    int32_t l1, l2, l4;
    void* l3;
    bool t0;
    t0 = vader_parser_check(l0, (uint8_t) 76);
    if (!(t0)) {
        return false;
    }
    l1 = INT32_C(0);
    l2 = INT32_C(0);
    while (!((l2 > INT32_C(256)))) {
        l3 = vader_parser_peek_at(l0, l2);
        if (((vader_struct_vader_lexer_Token_t*) l3)->f_kind == INT32_C(0)) {
            return false;
        }
        if (((vader_struct_vader_lexer_Token_t*) l3)->f_kind == INT32_C(76)) {
            l1 = (l1 + INT32_C(1));
        } else if (((vader_struct_vader_lexer_Token_t*) l3)->f_kind == INT32_C(77)) {
            l1 = (l1 - INT32_C(1));
            if (l1 == INT32_C(0)) {
                l4 = (l2 + INT32_C(1));
                t0 = vader_parser_check_at(l0, (uint8_t) 21, l4);
                return t0;
            }
        }
        l2 = (l2 + INT32_C(1));
    }
    return false;
}

static bool vader_parser_looks_like_struct_lit_body(void* l0, int32_t l1) {
    int32_t l2, l3;
    size_t l4;
    void* l5;
    bool l6;
    size_t t0;
    int64_t t1;
    t0 = ((vader_array_t*) l0)->length;
    l2 = ((int32_t) (size_t) t0);
    l3 = (l1 + INT32_C(1));
    for (;;) {
        if ((l3 < l2)) {
            t1 = ((int64_t) (int32_t) l3);
            l4 = (size_t) (int64_t) t1;
            vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
            l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
            if (((vader_struct_vader_lexer_Token_t*) l5)->f_kind == INT32_C(1)) {
                l3 = (l3 + INT32_C(1));
                continue;
            }
            if (((vader_struct_vader_lexer_Token_t*) l5)->f_kind == INT32_C(81)) {
                l6 = true;
            } else {
                l6 = ((vader_struct_vader_lexer_Token_t*) l5)->f_kind == INT32_C(69);
            }
            if (l6) {
                return true;
            }
            return ((vader_struct_vader_lexer_Token_t*) l5)->f_kind == INT32_C(79);
        }
        break;
    }
    return false;
}

static vader_box_t vader_parser_match_kind(void* l0, uint8_t l1) {
    bool t0;
    void* t1;
    t0 = vader_parser_check(l0, l1);
    if (!(t0)) {
        return vader_box_obj(0u, NULL);
    }
    t1 = vader_parser_advance(l0);
    return vader_ref_box(t1);
}

static void* vader_parser_match_or_peek(void* l0, uint8_t l1) {
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

static void* vader_parser_merge_type_params(void* l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    size_t l3, l5, l9, l10;
    bool l7;
    vader_string_t l11 = 0;
    vader_string_t l12 = 0;
    size_t t0;
    int64_t t1;
    void* t2 = NULL;
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l4, &l6, &l8, &t2 };
    vader_string_t* gc_atom_roots[2] = { &l11, &l12 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 7u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) l0)->length;
    if (t0 == INT64_C(0)) {
        { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_array_t*) l1)->length;
    if (t0 == INT64_C(0)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(38u, 0u, 13u, 515u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_array_t*) l0)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (size_t) l3);
    l2 = (void*) _a1_arr;
    l4 = l0;
    l3 = ((vader_array_t*) l4)->length;
    l5 = (size_t) 0;
    while ((l5 < l3)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
        l6 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
        vader_array_push((vader_array_t*) l2, vader_ref_box(l6));
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    l4 = l1;
    l3 = ((vader_array_t*) l4)->length;
    l5 = (size_t) 0;
    while ((l5 < l3)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
        l6 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l5);
        l7 = false;
        l8 = l2;
        l9 = ((vader_array_t*) l8)->length;
        l10 = (size_t) 0;
        while ((l10 < l9)) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            t2 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l10);
            l11 = ((vader_struct_toolchain_ast_TypeParam_t*) t2)->f_name;
            l12 = ((vader_struct_toolchain_ast_TypeParam_t*) l6)->f_name;
            if (l11 == l12) {
                l7 = true;
                break;
            }
            t1 = (l10 + INT64_C(1));
            l10 = (size_t) (int64_t) t1;
        }
        if (!(l7)) {
            vader_array_push((vader_array_t*) l2, vader_ref_box(l6));
        }
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

size_t vader_parser_mint(void* l0) {
    size_t l1, l2;
    int64_t t0;
    l1 = ((vader_struct_vader_parser_NodeIdFactory_t*) l0)->f_next;
    t0 = (l1 + INT64_C(1));
    l2 = (size_t) (int64_t) t0;
    ((vader_struct_vader_parser_NodeIdFactory_t*) l0)->f_next = l2;
    return l1;
}

void* vader_parser_new_node_id_factory(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_parser_NodeIdFactory_t* _a0_obj = (vader_struct_vader_parser_NodeIdFactory_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_NodeIdFactory_t));
    vader_obj_header_init(_a0_obj, 983u);
    _a0_obj->f_next = (size_t) 1;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_new_parser(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(71u, 0u, 13u, 799u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(176u, 0u, 13u, 1256u);
    l3 = (void*) _a1_arr;
    vader_struct_vader_parser_Parser_t* _a2_obj = (vader_struct_vader_parser_Parser_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_Parser_t));
    vader_obj_header_init(_a2_obj, 985u);
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
}

static void* vader_parser_no_infix(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_parser_InfixOpDescr_t* _a0_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
    vader_obj_header_init(_a0_obj, 980u);
    _a0_obj->f_has = false;
    _a0_obj->f_left_bp = INT32_C(0);
    _a0_obj->f_right_bp = INT32_C(0);
    _a0_obj->f_op = (uint8_t) 0;
    _a0_obj->f_non_assoc = false;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_angle_type_params(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l10 = NULL;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    int32_t l6;
    vader_string_t l9 = 0;
    bool t0;
    void* t1 = NULL;
    size_t t2;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l4, &l5, &t3 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l7, &l8, &l10, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_parser_check(l0, (uint8_t) 49);
    if (!(t0)) {
        vader_array_t* _a0_arr = vader_array_new(38u, 0u, 13u, 515u);
        t1 = (void*) _a0_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_parser_advance(l0);
    vader_array_t* _a1_arr = vader_array_new(38u, 0u, 13u, 515u);
    l1 = (void*) _a1_arr;
    vader_parser_skip_newlines(l0);
    for (;;) {
        t0 = vader_parser_check(l0, (uint8_t) 0);
        if (!(t0)) {
            t0 = vader_parser_check_closing_angle(l0);
            if (t0) break;
            t2 = ((vader_array_t*) l1)->length;
            if ((t2 > INT64_C(0))) {
                t3 = vader_parser_match_kind(l0, (uint8_t) 80);
                if (t3.tag == 0u) break;
                vader_parser_skip_newlines(l0);
                t0 = vader_parser_check_closing_angle(l0);
                if (t0) break;
            }
            l2 = vader_parser_peek(l0);
            l3 = vader_parser_expect(l0, (uint8_t) 2, 2356u);
            l4 = vader_box_obj(0u, NULL);
            t3 = vader_parser_match_kind(l0, (uint8_t) 82);
            if (!(t3.tag == 0u)) {
                vader_parser_skip_newlines(l0);
                l4 = vader_parser_parse_type(l0);
            }
            l5 = vader_box_obj(0u, NULL);
            t3 = vader_parser_match_kind(l0, (uint8_t) 59);
            if (!(t3.tag == 0u)) {
                vader_parser_skip_newlines(l0);
                l5 = vader_parser_parse_type(l0);
            }
            l6 = -(INT32_C(1));
            l7 = vader_parser_peek_at(l0, l6);
            l8 = vader_parser_span_of(l0, l2, l7);
            l9 = ((vader_struct_vader_lexer_Token_t*) l3)->f_text;
            vader_struct_toolchain_ast_TypeParam_t* _a2_obj = (vader_struct_toolchain_ast_TypeParam_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_TypeParam_t));
            vader_obj_header_init(_a2_obj, 515u);
            _a2_obj->f_span = l8;
            _a2_obj->f_id = (size_t) 0;
            _a2_obj->f_name = l9;
            _a2_obj->f_bound = l4;
            _a2_obj->f_default_v = l5;
            _a2_obj->f_is_comptime_value = false;
            l10 = (void*) _a2_obj;
            vader_array_push((vader_array_t*) l1, vader_ref_box(l10));
            continue;
        }
        break;
    }
    t0 = vader_parser_check_closing_angle(l0);
    if (t0) {
        vader_parser_consume_closing_angle(l0);
        { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_parser_expect(l0, (uint8_t) 51, 1087u);
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_parser_parse_assign_target(void* l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    vader_box_t l2 = vader_box_null();
    int32_t l3;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    bool t2;
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[2] = { &l2, &t0 };
    void** gc_raw_roots[4] = { &l0, &l1, &l4, &t1 };
    vader_string_t* gc_atom_roots[1] = { &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_peek(l0);
    t0 = vader_parser_match_kind(l0, (uint8_t) 69);
    if (!(t0.tag == 0u)) {
        l2 = vader_parser_parse_expr(l0, INT32_C(0));
        l3 = -(INT32_C(1));
        l4 = vader_parser_peek_at(l0, l3);
        t1 = vader_parser_span_of(l0, l1, l4);
        vader_struct_toolchain_ast_RestTarget_t* _a0_obj = (vader_struct_toolchain_ast_RestTarget_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_RestTarget_t));
        vader_obj_header_init(_a0_obj, 498u);
        _a0_obj->f_span = t1;
        _a0_obj->f_id = (size_t) 0;
        _a0_obj->f_place = l2;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_parser_check(l0, (uint8_t) 2);
    if (t2) {
        t1 = vader_parser_peek(l0);
        t3 = ((vader_struct_vader_lexer_Token_t*) t1)->f_text;
        if (t3 == 793u) {
            t1 = vader_parser_advance(l0);
            vader_struct_toolchain_ast_WildcardTarget_t* _a1_obj = (vader_struct_toolchain_ast_WildcardTarget_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_WildcardTarget_t));
            vader_obj_header_init(_a1_obj, 521u);
            _a1_obj->f_span = ((vader_struct_vader_lexer_Token_t*) t1)->f_span;
            _a1_obj->f_id = (size_t) 0;
            t1 = (void*) _a1_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l2 = vader_parser_parse_expr(l0, INT32_C(0));
    t1 = l2.payload.obj;
    vader_struct_toolchain_ast_PlaceTarget_t* _a2_obj = (vader_struct_toolchain_ast_PlaceTarget_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_PlaceTarget_t));
    vader_obj_header_init(_a2_obj, 493u);
    _a2_obj->f_span = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_span;
    _a2_obj->f_id = (size_t) 0;
    _a2_obj->f_place = l2;
    t1 = (void*) _a2_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_block(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    int32_t l2;
    vader_box_t l5 = vader_box_null(), l6 = vader_box_null(), l19 = vader_box_null();
    size_t l16, l18;
    bool l17;
    int32_t t0;
    bool t1;
    void* t2 = NULL;
    int64_t t3;
    vader_box_t* gc_roots[3] = { &l5, &l6, &l19 };
    void** gc_raw_roots[14] = {
        &l0, &l1, &l3, &l4, &l7, &l8, &l9, &l10, &l11, &l12, &l13, &l14, &l15, &t2,
    };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 14u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_expect(l0, (uint8_t) 78, 1147u);
    t0 = ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth;
    l2 = (t0 + INT32_C(1));
    ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth = l2;
    t0 = ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth;
    if ((t0 > INT32_C(256))) {
        t0 = ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth;
        l2 = (t0 - INT32_C(1));
        ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth = l2;
        vader_parser_report_nesting_too_deep(l0, 1320u);
        l2 = INT32_C(1);
        while ((l2 > INT32_C(0))) {
            t1 = vader_parser_check(l0, (uint8_t) 0);
            if (t1) break;
            l3 = vader_parser_advance(l0);
            if (((vader_struct_vader_lexer_Token_t*) l3)->f_kind == INT32_C(78)) {
                l2 = (l2 + INT32_C(1));
            }
            if (!(((vader_struct_vader_lexer_Token_t*) l3)->f_kind == INT32_C(79))) {
                continue;
            }
            l2 = (l2 - INT32_C(1));
        }
        l2 = -(INT32_C(1));
        l3 = vader_parser_peek_at(l0, l2);
        l3 = vader_parser_span_of(l0, l1, l3);
        vader_array_t* _a0_arr = vader_array_new(177u, 0u, 13u, 1262u);
        l4 = (void*) _a0_arr;
        vader_struct_toolchain_ast_BlockExpr_t* _a1_obj = (vader_struct_toolchain_ast_BlockExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BlockExpr_t));
        vader_obj_header_init(_a1_obj, 437u);
        _a1_obj->f_span = l3;
        _a1_obj->f_id = (size_t) 0;
        _a1_obj->f_stmts = l4;
        _a1_obj->f_trailing = vader_box_obj(0u, NULL);
        t2 = (void*) _a1_obj;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_parser_skip_newlines(l0);
    vader_array_t* _a2_arr = vader_array_new(177u, 0u, 13u, 1262u);
    l3 = (void*) _a2_arr;
    l5 = vader_box_obj(0u, NULL);
    for (;;) {
        t1 = vader_parser_check(l0, (uint8_t) 79);
        if (!(t1)) {
            t1 = vader_parser_check(l0, (uint8_t) 0);
            if (t1) break;
            l6 = vader_parser_parse_stmt(l0);
            if (!(l6.tag == 0u)) {
                if (l6.tag == 480u) {
                    l4 = l6.payload.obj;
                    vader_array_push((vader_array_t*) l3, vader_ref_box(l4));
                } else if (l6.tag == 434u) {
                    l7 = l6.payload.obj;
                    vader_array_push((vader_array_t*) l3, vader_ref_box(l7));
                } else if (l6.tag == 450u) {
                    l8 = l6.payload.obj;
                    vader_array_push((vader_array_t*) l3, vader_ref_box(l8));
                } else if (l6.tag == 458u) {
                    l9 = l6.payload.obj;
                    vader_array_push((vader_array_t*) l3, vader_ref_box(l9));
                } else if (l6.tag == 499u) {
                    l10 = l6.payload.obj;
                    vader_array_push((vader_array_t*) l3, vader_ref_box(l10));
                } else if (l6.tag == 522u) {
                    l11 = l6.payload.obj;
                    vader_array_push((vader_array_t*) l3, vader_ref_box(l11));
                } else if (l6.tag == 464u) {
                    l12 = l6.payload.obj;
                    vader_array_push((vader_array_t*) l3, vader_ref_box(l12));
                } else if (l6.tag == 439u) {
                    l13 = l6.payload.obj;
                    vader_array_push((vader_array_t*) l3, vader_ref_box(l13));
                } else if (l6.tag == 445u) {
                    l14 = l6.payload.obj;
                    vader_array_push((vader_array_t*) l3, vader_ref_box(l14));
                } else {
                    if (!(l6.tag == 448u)) {
                        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                    }
                    l15 = l6.payload.obj;
                    vader_array_push((vader_array_t*) l3, vader_ref_box(l15));
                }
            }
            vader_parser_skip_newlines(l0);
            continue;
        }
        break;
    }
    vader_array_t* _a3_arr = vader_array_new(177u, 0u, 13u, 1262u);
    l4 = (void*) _a3_arr;
    l16 = ((vader_array_t*) l3)->length;
    l17 = false;
    l6 = vader_box_obj(0u, NULL);
    if ((l16 > INT64_C(0))) {
        t3 = (l16 - INT64_C(1));
        l18 = (size_t) (int64_t) t3;
        vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l18)
        l19 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l18);
        if (l19.tag == 458u) {
            l17 = true;
            t2 = l19.payload.obj;
            l6 = ((vader_struct_toolchain_ast_ExprStmt_t*) t2)->f_expr;
        } else if (!(l19.tag == 480u)) {
            if (!(l19.tag == 434u)) {
                if (!(l19.tag == 450u)) {
                    if (!(l19.tag == 499u)) {
                        if (!(l19.tag == 522u)) {
                            if (!(l19.tag == 464u)) {
                                if (!(l19.tag == 439u)) {
                                    if (!(l19.tag == 445u)) {
                                        if (!(l19.tag == 448u)) {
                                            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
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
    if (l17) {
        t3 = (l16 - INT64_C(1));
        l18 = (size_t) (int64_t) t3;
    } else {
        l18 = l16;
    }
    l16 = (size_t) 0;
    while ((l16 < l18)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l16)
        l19 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l16);
        vader_array_push((vader_array_t*) l4, l19);
        t3 = (l16 + INT64_C(1));
        l16 = (size_t) (int64_t) t3;
    }
    if (l17) {
        if (!(l6.tag == 0u)) {
            l5 = l6;
        }
    }
    l3 = vader_parser_expect(l0, (uint8_t) 79, 1153u);
    t0 = ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth;
    l2 = (t0 - INT32_C(1));
    ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth = l2;
    t2 = vader_parser_span_of(l0, l1, l3);
    vader_struct_toolchain_ast_BlockExpr_t* _a6_obj = (vader_struct_toolchain_ast_BlockExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BlockExpr_t));
    vader_obj_header_init(_a6_obj, 437u);
    _a6_obj->f_span = t2;
    _a6_obj->f_id = (size_t) 0;
    _a6_obj->f_stmts = l4;
    _a6_obj->f_trailing = l5;
    t2 = (void*) _a6_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_break(void* l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    vader_box_t l2 = vader_box_null();
    int32_t l3;
    bool t0;
    void* t1 = NULL;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[4] = { &l0, &l1, &l4, &t1 };
    vader_string_t* gc_atom_roots[1] = { &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_advance(l0);
    l2 = vader_box_obj(0u, NULL);
    t0 = vader_parser_check(l0, (uint8_t) 2);
    if (t0) {
        t1 = vader_parser_advance(l0);
        t2 = ((vader_struct_vader_lexer_Token_t*) t1)->f_text;
        l2 = vader_box_string(240u, t2);
    }
    l3 = -(INT32_C(1));
    l4 = vader_parser_peek_at(l0, l3);
    t1 = vader_parser_span_of(l0, l1, l4);
    vader_struct_toolchain_ast_BreakStmt_t* _a0_obj = (vader_struct_toolchain_ast_BreakStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BreakStmt_t));
    vader_obj_header_init(_a0_obj, 439u);
    _a0_obj->f_span = t1;
    _a0_obj->f_id = (size_t) 0;
    _a0_obj->f_label = l2;
    t1 = (void*) _a0_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_call_args(void* l0) {
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
    vader_string_t l10 = 0;
    bool t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l6, &l12, &t2 };
    void** gc_raw_roots[9] = { &l0, &l1, &l3, &l5, &l8, &l9, &l11, &l13, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l10 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(23u, 0u, 13u, 440u);
    l1 = (void*) _a0_arr;
    l2 = false;
    vader_parser_skip_newlines(l0);
    t0 = vader_parser_check(l0, (uint8_t) 75);
    if (t0) {
        vader_struct_vader_parser_CommaList__Any_t* _a1_obj = (vader_struct_vader_parser_CommaList__Any_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_CommaList__Any_t));
        vader_obj_header_init(_a1_obj, 973u);
        _a1_obj->f_items = l1;
        _a1_obj->f_trailing_comma = false;
        t1 = (void*) _a1_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    for (;;) {
        vader_parser_skip_newlines(l0);
        t0 = vader_parser_check(l0, (uint8_t) 75);
        if (!(t0)) {
            l3 = vader_parser_peek(l0);
            t0 = vader_parser_check(l0, (uint8_t) 2);
            if (t0) {
                l4 = vader_parser_check_at(l0, (uint8_t) 59, INT32_C(1));
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
                t2 = vader_box_string(240u, l10);
                vader_struct_toolchain_ast_CallArg_t* _a2_obj = (vader_struct_toolchain_ast_CallArg_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_CallArg_t));
                vader_obj_header_init(_a2_obj, 440u);
                _a2_obj->f_span = l9;
                _a2_obj->f_id = (size_t) 0;
                _a2_obj->f_name = t2;
                _a2_obj->f_value = l6;
                _a2_obj->f_spread = false;
                l11 = (void*) _a2_obj;
                vader_array_push((vader_array_t*) l1, vader_ref_box(l11));
            } else {
                l12 = vader_parser_parse_expr(l0, INT32_C(0));
                t1 = l12.payload.obj;
                vader_struct_toolchain_ast_CallArg_t* _a3_obj = (vader_struct_toolchain_ast_CallArg_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_CallArg_t));
                vader_obj_header_init(_a3_obj, 440u);
                _a3_obj->f_span = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_span;
                _a3_obj->f_id = (size_t) 0;
                _a3_obj->f_name = vader_box_obj(0u, NULL);
                _a3_obj->f_value = l12;
                _a3_obj->f_spread = false;
                l13 = (void*) _a3_obj;
                vader_array_push((vader_array_t*) l1, vader_ref_box(l13));
            }
            vader_parser_skip_newlines(l0);
            t2 = vader_parser_match_kind(l0, (uint8_t) 80);
            if (t2.tag == 0u) break;
            vader_parser_skip_newlines(l0);
            l2 = vader_parser_check(l0, (uint8_t) 75);
            continue;
        }
        break;
    }
    vader_struct_vader_parser_CommaList__Any_t* _a4_obj = (vader_struct_vader_parser_CommaList__Any_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_CommaList__Any_t));
    vader_obj_header_init(_a4_obj, 973u);
    _a4_obj->f_items = l1;
    _a4_obj->f_trailing_comma = l2;
    t1 = (void*) _a4_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_parser_parse_coalesce_fallback(void* l0) {
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
    if (!(l1 == INT32_C(27))) {
        t1 = vader_parser_parse_expr(l0, INT32_C(7));
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_parser_parse_continue(l0);
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_const_decl(void* l0, void* l1, uint8_t l2, void* l3) {
    vader_box_t l4 = vader_box_null();
    int32_t l5;
    void* l6 = NULL;
    void* l8 = NULL;
    vader_string_t l7 = 0;
    bool t0;
    void* t1 = NULL;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[6] = { &l0, &l1, &l3, &l6, &l8, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l7, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_parser_reject_target_decorator(l0, l1, 1179u);
    vader_parser_match_kind(l0, (uint8_t) 42);
    t0 = vader_parser_check(l0, (uint8_t) 72);
    if (t0) {
        t1 = vader_parser_peek_at(l0, INT32_C(1));
        if (((vader_struct_vader_lexer_Token_t*) t1)->f_kind == INT32_C(2)) {
            t1 = vader_parser_peek_at(l0, INT32_C(1));
            t2 = ((vader_struct_vader_lexer_Token_t*) t1)->f_text;
            if (t2 == 1454u) {
                t1 = vader_parser_desugar_comptime_const(l0, l1, l2, l3, vader_box_obj(0u, NULL));
                { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
    }
    l4 = vader_parser_parse_expr(l0, INT32_C(0));
    l5 = -(INT32_C(1));
    l6 = vader_parser_peek_at(l0, l5);
    l6 = vader_parser_span_of(l0, l3, l6);
    l7 = ((vader_struct_vader_lexer_Token_t*) l3)->f_text;
    l8 = ((vader_struct_vader_lexer_Token_t*) l3)->f_span;
    vader_struct_toolchain_ast_ConstDecl_t* _a0_obj = (vader_struct_toolchain_ast_ConstDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ConstDecl_t));
    vader_obj_header_init(_a0_obj, 444u);
    _a0_obj->f_span = l6;
    _a0_obj->f_id = (size_t) 0;
    _a0_obj->f_name = l7;
    _a0_obj->f_name_span = l8;
    _a0_obj->f_visibility = l2;
    _a0_obj->f_ty = vader_box_obj(0u, NULL);
    _a0_obj->f_value = l4;
    _a0_obj->f_decorators = l1;
    _a0_obj->f_comptime_body = vader_box_obj(0u, NULL);
    t1 = (void*) _a0_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_continue(void* l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    vader_box_t l2 = vader_box_null();
    int32_t l3;
    bool t0;
    void* t1 = NULL;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[4] = { &l0, &l1, &l4, &t1 };
    vader_string_t* gc_atom_roots[1] = { &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_advance(l0);
    l2 = vader_box_obj(0u, NULL);
    t0 = vader_parser_check(l0, (uint8_t) 2);
    if (t0) {
        t1 = vader_parser_advance(l0);
        t2 = ((vader_struct_vader_lexer_Token_t*) t1)->f_text;
        l2 = vader_box_string(240u, t2);
    }
    l3 = -(INT32_C(1));
    l4 = vader_parser_peek_at(l0, l3);
    t1 = vader_parser_span_of(l0, l1, l4);
    vader_struct_toolchain_ast_ContinueStmt_t* _a0_obj = (vader_struct_toolchain_ast_ContinueStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ContinueStmt_t));
    vader_obj_header_init(_a0_obj, 445u);
    _a0_obj->f_span = t1;
    _a0_obj->f_id = (size_t) 0;
    _a0_obj->f_label = l2;
    t1 = (void*) _a0_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_parser_parse_decl(void* l0) {
    void* l1 = NULL;
    uint8_t l2;
    vader_box_t l3 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l3, &t0 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_parse_decorators(l0);
    l2 = (uint8_t) 1;
    t0 = vader_parser_match_kind(l0, (uint8_t) 30);
    if (!(t0.tag == 0u)) {
        l2 = (uint8_t) 0;
    }
    l3 = vader_parser_parse_decorated_decl(l0, l1, l2);
    if (l3.tag == 0u) {
        { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l3.tag == 455u) {
        { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_parser_reject_displayable_decorator(l0, l1);
    { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_parser_parse_decorated_decl(void* l0, void* l1, uint8_t l2) {
    void* l3 = NULL;
    void* l5 = NULL;
    void* l10 = NULL;
    bool l4;
    vader_box_t l6 = vader_box_null(), l7 = vader_box_null(), l8 = vader_box_null(), l9 = vader_box_null();
    vader_string_t l11 = 0;
    size_t t0;
    void* t1 = NULL;
    vader_string_t t2 = 0;
    bool t3;
    vader_box_t t4 = vader_box_null();
    vader_box_t* gc_roots[5] = { &l6, &l7, &l8, &l9, &t4 };
    void** gc_raw_roots[6] = { &l0, &l1, &l3, &l5, &l10, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l11, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 5u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) l1)->length;
    if (t0 == INT64_C(1)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
        t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
        t2 = ((vader_struct_toolchain_ast_Decorator_t*) t1)->f_name;
        if (t2 == 1294u) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
            l3 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT32_C(0));
            t0 = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l3)->f_args)->length;
            if ((t0 < INT64_C(1))) {
                l4 = true;
            } else {
                t0 = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l3)->f_args)->length;
                l4 = (t0 > INT64_C(2));
            }
            if (l4) {
                l5 = ((vader_struct_toolchain_ast_Decorator_t*) l3)->f_span;
                vader_parser_error(l0, (uint8_t) 28, l5, 1092u);
                { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
            }
            l6 = vader_box_obj(0u, NULL);
            t0 = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l3)->f_args)->length;
            if (t0 == INT64_C(2)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l3)->f_args);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(1))
                l7 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT32_C(1));
                if (!(l7.tag == 502u)) {
                    t1 = l7.payload.obj;
                    l10 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_span;
                    vader_parser_error(l0, (uint8_t) 29, l10, 1093u);
                    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
                }
                t1 = l7.payload.obj;
                t0 = ((vader_array_t*) ((vader_struct_toolchain_ast_StringLitExpr_t*) t1)->f_parts)->length;
                if (!(t0 == INT64_C(1))) {
                    t1 = l7.payload.obj;
                    l10 = ((vader_struct_toolchain_ast_StringLitExpr_t*) t1)->f_span;
                    vader_parser_error(l0, (uint8_t) 29, l10, 1093u);
                    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
                }
                t1 = l7.payload.obj;
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_StringLitExpr_t*) t1)->f_parts);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, INT32_C(0))
                l8 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) INT32_C(0));
                l9 = l8;
                if (!(l8.tag == 504u)) {
                    t1 = l7.payload.obj;
                    l5 = ((vader_struct_toolchain_ast_StringLitExpr_t*) t1)->f_span;
                    vader_parser_error(l0, (uint8_t) 29, l5, 1093u);
                    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
                }
                t1 = l9.payload.obj;
                t2 = ((vader_struct_toolchain_ast_StringLitText_t*) t1)->f_value;
                l6 = vader_box_string(240u, t2);
            }
            l5 = ((vader_struct_toolchain_ast_Decorator_t*) l3)->f_span;
            vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l3)->f_args);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, INT32_C(0))
            l7 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) INT32_C(0));
            vader_array_t* _a5_arr = vader_array_new(25u, 0u, 13u, 446u);
            l3 = (void*) _a5_arr;
            vader_struct_toolchain_ast_AssertDecl_t* _a6_obj = (vader_struct_toolchain_ast_AssertDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_AssertDecl_t));
            vader_obj_header_init(_a6_obj, 433u);
            _a6_obj->f_span = l5;
            _a6_obj->f_id = (size_t) 0;
            _a6_obj->f_condition = l7;
            _a6_obj->f_message = l6;
            _a6_obj->f_decorators = l3;
            t1 = (void*) _a6_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    t3 = vader_parser_check(l0, (uint8_t) 28);
    if (t3) {
        t1 = vader_parser_parse_import_decl(l0, l1);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t3 = vader_parser_is_impl_decl(l0);
    if (t3) {
        t1 = vader_parser_parse_impl_decl(l0, l1);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t3 = vader_parser_check(l0, (uint8_t) 2);
    if (t3) {
        t3 = vader_parser_check_at(l0, (uint8_t) 49, INT32_C(1));
        if (t3) {
            t3 = vader_parser_peek_is_lhs_generic_alias_head(l0);
            if (t3) {
                t1 = vader_parser_parse_lhs_generic_alias_decl(l0, l1, l2);
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
    }
    t3 = vader_parser_check(l0, (uint8_t) 2);
    if (t3) {
        t3 = vader_parser_check_at(l0, (uint8_t) 65, INT32_C(1));
        if (t3) {
            t4 = vader_parser_parse_named_decl(l0, l1, l2);
            { vader_box_t __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    t3 = vader_parser_check(l0, (uint8_t) 2);
    if (t3) {
        t3 = vader_parser_check_at(l0, (uint8_t) 82, INT32_C(1));
        if (t3) {
            t1 = vader_parser_parse_typed_const_decl(l0, l1, l2);
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l3 = vader_parser_peek(l0);
    l5 = ((vader_struct_vader_lexer_Token_t*) l3)->f_span;
    l11 = vader_parser_describe_token(l3);
    l11 = concat_2(1720u, l11);
    vader_parser_error(l0, (uint8_t) 5, l5, l11);
    vader_parser_sync_to_top_level(l0);
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static void* vader_parser_parse_decorators(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l11 = NULL;
    bool l5;
    vader_box_t l6 = vader_box_null();
    int32_t l7;
    vader_string_t l10 = 0;
    bool t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l6, &t1 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l4, &l8, &l9, &l11 };
    vader_string_t* gc_atom_roots[1] = { &l10 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(25u, 0u, 13u, 446u);
    l1 = (void*) _a0_arr;
    for (;;) {
        t0 = vader_parser_check(l0, (uint8_t) 72);
        if (t0) {
            l2 = vader_parser_advance(l0);
            l3 = vader_parser_expect(l0, (uint8_t) 2, 1498u);
            vader_array_t* _a1_arr = vader_array_new(175u, 0u, 13u, 1241u);
            l4 = (void*) _a1_arr;
            t1 = vader_parser_match_kind(l0, (uint8_t) 74);
            if (!(t1.tag == 0u)) {
                t0 = vader_parser_check(l0, (uint8_t) 75);
                if (!(t0)) {
                    l5 = true;
                    for (;;) {
                        if (!(l5)) {
                            t1 = vader_parser_match_kind(l0, (uint8_t) 80);
                            if (t1.tag == 0u) break;
                            t0 = vader_parser_check(l0, (uint8_t) 75);
                            if (t0) break;
                        }
                        l5 = false;
                        l6 = vader_parser_parse_expr(l0, INT32_C(0));
                        vader_array_push((vader_array_t*) l4, l6);
                        continue;
                    }
                }
                vader_parser_expect(l0, (uint8_t) 75, 1047u);
            }
            l7 = -(INT32_C(1));
            l8 = vader_parser_peek_at(l0, l7);
            l9 = vader_parser_span_of(l0, l2, l8);
            l10 = ((vader_struct_vader_lexer_Token_t*) l3)->f_text;
            vader_struct_toolchain_ast_Decorator_t* _a2_obj = (vader_struct_toolchain_ast_Decorator_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_Decorator_t));
            vader_obj_header_init(_a2_obj, 446u);
            _a2_obj->f_span = l9;
            _a2_obj->f_id = (size_t) 0;
            _a2_obj->f_name = l10;
            _a2_obj->f_args = l4;
            l11 = (void*) _a2_obj;
            vader_array_push((vader_array_t*) l1, vader_ref_box(l11));
            vader_parser_skip_newlines(l0);
            continue;
        }
        break;
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_defer(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    void* t0 = NULL;
    void* t2 = NULL;
    bool t1;
    vader_box_t* gc_roots[2] = { &l4, &l5 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &t0, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_advance(l0);
    l2 = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
    vader_struct_toolchain_ast_NullLitExpr_t* _a0_obj = (vader_struct_toolchain_ast_NullLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_NullLitExpr_t));
    vader_obj_header_init(_a0_obj, 489u);
    _a0_obj->f_span = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
    _a0_obj->f_id = (size_t) 0;
    l3 = (void*) _a0_obj;
    vader_struct_toolchain_ast_ExprStmt_t* _a1_obj = (vader_struct_toolchain_ast_ExprStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ExprStmt_t));
    vader_obj_header_init(_a1_obj, 458u);
    _a1_obj->f_span = l2;
    _a1_obj->f_id = (size_t) 0;
    _a1_obj->f_expr = vader_ref_box(l3);
    t0 = (void*) _a1_obj;
    vader_struct_toolchain_ast_DeferStmtBody_t* _a2_obj = (vader_struct_toolchain_ast_DeferStmtBody_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_DeferStmtBody_t));
    vader_obj_header_init(_a2_obj, 449u);
    _a2_obj->f_stmt = vader_ref_box(t0);
    t0 = (void*) _a2_obj;
    l4 = vader_ref_box(t0);
    t1 = vader_parser_check(l0, (uint8_t) 78);
    if (t1) {
        t0 = vader_parser_parse_block(l0);
        vader_struct_toolchain_ast_DeferBlockBody_t* _a3_obj = (vader_struct_toolchain_ast_DeferBlockBody_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_DeferBlockBody_t));
        vader_obj_header_init(_a3_obj, 447u);
        _a3_obj->f_block = t0;
        t0 = (void*) _a3_obj;
        l4 = vader_ref_box(t0);
    } else {
        l5 = vader_parser_parse_stmt(l0);
        if (!(l5.tag == 0u)) {
            vader_struct_toolchain_ast_DeferStmtBody_t* _a4_obj = (vader_struct_toolchain_ast_DeferStmtBody_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_DeferStmtBody_t));
            vader_obj_header_init(_a4_obj, 449u);
            _a4_obj->f_stmt = l5;
            t0 = (void*) _a4_obj;
            l4 = vader_ref_box(t0);
        }
    }
    if (l4.tag == 449u) {
        t0 = l4.payload.obj;
        t2 = ((vader_struct_toolchain_ast_DeferStmtBody_t*) t0)->f_stmt.payload.obj;
        l2 = ((vader_struct_toolchain_ast_AssignStmt_t*) t2)->f_span;
    } else {
        if (!(l4.tag == 447u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = l4.payload.obj;
        l2 = ((vader_struct_toolchain_ast_BlockExpr_t*) ((vader_struct_toolchain_ast_DeferBlockBody_t*) t0)->f_block)->f_span;
    }
    l1 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l1)->f_span)->f_start;
    l2 = ((vader_struct_toolchain_span_Span_t*) l2)->f_end;
    vader_struct_toolchain_span_Span_t* _a5_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a5_obj, 524u);
    _a5_obj->f_start = l1;
    _a5_obj->f_end = l2;
    t0 = (void*) _a5_obj;
    vader_struct_toolchain_ast_DeferStmt_t* _a6_obj = (vader_struct_toolchain_ast_DeferStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_DeferStmt_t));
    vader_obj_header_init(_a6_obj, 448u);
    _a6_obj->f_span = t0;
    _a6_obj->f_id = (size_t) 0;
    _a6_obj->f_body = l4;
    t0 = (void*) _a6_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_destructure_assign(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l4 = NULL;
    void* l9 = NULL;
    vader_box_t l3 = vader_box_null();
    size_t l5, l6, l7, l8;
    int32_t l10;
    bool t0;
    vader_box_t t1 = vader_box_null();
    size_t t2;
    int64_t t3;
    void* t4 = NULL;
    void* t5 = NULL;
    vader_box_t* gc_roots[2] = { &l3, &t1 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l4, &l9, &t4, &t5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_advance(l0);
    vader_array_t* _a0_arr = vader_array_new(180u, 0u, 13u, 1296u);
    l2 = (void*) _a0_arr;
    for (;;) {
        vader_parser_skip_newlines(l0);
        t0 = vader_parser_check(l0, (uint8_t) 77);
        if (!(t0)) {
            l3 = vader_parser_parse_assign_target(l0);
            vader_array_push((vader_array_t*) l2, l3);
            vader_parser_skip_newlines(l0);
            t1 = vader_parser_match_kind(l0, (uint8_t) 80);
            if (t1.tag == 0u) break;
            continue;
        }
        break;
    }
    l4 = vader_parser_expect(l0, (uint8_t) 77, 1121u);
    t2 = ((vader_array_t*) l2)->length;
    if (t2 == INT64_C(0)) {
        l4 = vader_parser_span_of(l0, l1, l4);
        vader_parser_error(l0, (uint8_t) 22, l4, 1234u);
    }
    l5 = (size_t) 1;
    l6 = ((vader_array_t*) l2)->length;
    while ((l5 < l6)) {
        t3 = (l5 - INT64_C(1));
        l7 = (size_t) (int64_t) t3;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l7)
        t1 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l7);
        if (t1.tag == 498u) {
            t3 = (l5 - INT64_C(1));
            l8 = (size_t) (int64_t) t3;
            vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l8)
            t1 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l8);
            l4 = t1.payload.obj;
            l9 = ((vader_struct_toolchain_ast_RestTarget_t*) l4)->f_span;
            vader_parser_error(l0, (uint8_t) 33, l9, 0u);
        }
        t3 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t3;
    }
    t4 = vader_parser_peek(l0);
    t5 = vader_parser_compound_op(((vader_struct_vader_lexer_Token_t*) t4)->f_kind);
    t0 = ((vader_struct_vader_parser_CompoundOpResult_t*) t5)->f_matched;
    if (t0) {
        l4 = vader_parser_advance(l0);
        l4 = vader_parser_span_of(l0, l1, l4);
        vader_parser_error(l0, (uint8_t) 30, l4, 1184u);
    } else {
        vader_parser_expect(l0, (uint8_t) 59, 1083u);
    }
    l3 = vader_parser_parse_expr(l0, INT32_C(0));
    l10 = -(INT32_C(1));
    l4 = vader_parser_peek_at(l0, l10);
    t4 = vader_parser_span_of(l0, l1, l4);
    vader_struct_toolchain_ast_DestructureAssignStmt_t* _a3_obj = (vader_struct_toolchain_ast_DestructureAssignStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_DestructureAssignStmt_t));
    vader_obj_header_init(_a3_obj, 450u);
    _a3_obj->f_span = t4;
    _a3_obj->f_id = (size_t) 0;
    _a3_obj->f_targets = l2;
    _a3_obj->f_value = l3;
    t4 = (void*) _a3_obj;
    { void* __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_enum_decl(void* l0, void* l1, uint8_t l2, void* l3) {
    void* l4 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    void* l12 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    void* l19 = NULL;
    vader_box_t l5 = vader_box_null(), l9 = vader_box_null(), l10 = vader_box_null(), l11 = vader_box_null(), l13 = vader_box_null(), l15 = vader_box_null();
    size_t l7;
    int64_t l14;
    vader_string_t l18 = 0;
    vader_box_t t0 = vader_box_null();
    bool t1;
    void* t2 = NULL;
    void* t3 = NULL;
    uint64_t t4;
    size_t t5;
    vader_box_t* gc_roots[7] = { &l5, &l9, &l10, &l11, &l13, &l15, &t0 };
    void** gc_raw_roots[12] = { &l0, &l1, &l3, &l4, &l6, &l8, &l12, &l16, &l17, &l19, &t2, &t3 };
    vader_string_t* gc_atom_roots[1] = { &l18 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 7u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_parser_reject_target_decorator(l0, l1, 1237u);
    vader_parser_reject_c_decorators(l0, l1, 1237u);
    vader_parser_advance(l0);
    vader_array_t* _a0_arr = vader_array_new(175u, 0u, 13u, 1241u);
    l4 = (void*) _a0_arr;
    t0 = vader_parser_match_kind(l0, (uint8_t) 74);
    if (!(t0.tag == 0u)) {
        l5 = vader_parser_parse_type(l0);
        vader_array_push((vader_array_t*) l4, l5);
        t0 = vader_parser_match_kind(l0, (uint8_t) 80);
        if (!(t0.tag == 0u)) {
            l5 = vader_parser_parse_type(l0);
            vader_array_push((vader_array_t*) l4, l5);
        }
        vader_parser_expect(l0, (uint8_t) 75, 1048u);
    }
    vader_parser_expect(l0, (uint8_t) 78, 1148u);
    vader_parser_skip_newlines(l0);
    vader_array_t* _a1_arr = vader_array_new(26u, 0u, 13u, 456u);
    l6 = (void*) _a1_arr;
    for (;;) {
        t1 = vader_parser_check(l0, (uint8_t) 79);
        if (!(t1)) {
            t1 = vader_parser_check(l0, (uint8_t) 0);
            if (t1) break;
            l7 = ((vader_array_t*) ((vader_struct_vader_parser_Parser_t*) l0)->f_errors)->length;
            l8 = vader_parser_expect(l0, (uint8_t) 2, 2576u);
            l5 = vader_box_obj(0u, NULL);
            t0 = vader_parser_match_kind(l0, (uint8_t) 78);
            if (!(t0.tag == 0u)) {
                t2 = vader_parser_parse_struct_lit_fields(l0);
                t3 = ((vader_struct_vader_parser_CommaList__StructLitField___StructLitSpread_t*) t2)->f_items;
                l5 = vader_ref_box(t3);
                vader_parser_expect(l0, (uint8_t) 79, 1162u);
            }
            l9 = vader_box_obj(0u, NULL);
            l10 = vader_box_obj(0u, NULL);
            t0 = vader_parser_match_kind(l0, (uint8_t) 59);
            if (!(t0.tag == 0u)) {
                l11 = vader_parser_match_kind(l0, (uint8_t) 37);
                l12 = vader_parser_expect(l0, (uint8_t) 3, 1828u);
                l13 = ((vader_struct_vader_lexer_Token_t*) l12)->f_value;
                if (l13.tag == 249u) {
                    if (l11.tag == 0u) {
                        t4 = ((uint64_t) l13.payload.i);
                        l14 = ((int64_t) (uint64_t) t4);
                    } else {
                        t4 = ((uint64_t) l13.payload.i);
                        l14 = -(((int64_t) (uint64_t) t4));
                    }
                    l9 = vader_box_i64(244u, l14);
                }
                l15 = l11;
                if (l15.tag == 0u) {
                    l16 = l12;
                } else {
                    l16 = l15.payload.obj;
                }
                t2 = vader_parser_span_of(l0, l16, l12);
                l10 = vader_ref_box(t2);
            }
            l17 = ((vader_struct_vader_lexer_Token_t*) l8)->f_span;
            l18 = ((vader_struct_vader_lexer_Token_t*) l8)->f_text;
            vader_struct_toolchain_ast_EnumVariant_t* _a2_obj = (vader_struct_toolchain_ast_EnumVariant_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_EnumVariant_t));
            vader_obj_header_init(_a2_obj, 456u);
            _a2_obj->f_span = l17;
            _a2_obj->f_id = (size_t) 0;
            _a2_obj->f_name = l18;
            _a2_obj->f_value = l9;
            _a2_obj->f_value_span = l10;
            _a2_obj->f_data = l5;
            l19 = (void*) _a2_obj;
            vader_array_push((vader_array_t*) l6, vader_ref_box(l19));
            t5 = ((vader_array_t*) ((vader_struct_vader_parser_Parser_t*) l0)->f_errors)->length;
            if ((t5 > l7)) {
                for (;;) {
                    t1 = vader_parser_check(l0, (uint8_t) 80);
                    if (!(t1)) {
                        t1 = vader_parser_check(l0, (uint8_t) 1);
                        if (t1) break;
                        t1 = vader_parser_check(l0, (uint8_t) 79);
                        if (t1) break;
                        t1 = vader_parser_check(l0, (uint8_t) 0);
                        if (t1) break;
                        vader_parser_advance(l0);
                        continue;
                    }
                    break;
                }
            }
            vader_parser_match_kind(l0, (uint8_t) 80);
            vader_parser_skip_newlines(l0);
            continue;
        }
        break;
    }
    l8 = vader_parser_expect(l0, (uint8_t) 79, 1154u);
    l8 = vader_parser_span_of(l0, l3, l8);
    l18 = ((vader_struct_vader_lexer_Token_t*) l3)->f_text;
    l12 = ((vader_struct_vader_lexer_Token_t*) l3)->f_span;
    vader_struct_toolchain_ast_EnumDecl_t* _a3_obj = (vader_struct_toolchain_ast_EnumDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_EnumDecl_t));
    vader_obj_header_init(_a3_obj, 455u);
    _a3_obj->f_span = l8;
    _a3_obj->f_id = (size_t) 0;
    _a3_obj->f_name = l18;
    _a3_obj->f_name_span = l12;
    _a3_obj->f_visibility = l2;
    _a3_obj->f_header = l4;
    _a3_obj->f_variants = l6;
    _a3_obj->f_decorators = l1;
    t2 = (void*) _a3_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_parser_parse_expr(void* l0, int32_t l1) {
    int32_t l2, l5, l23, l26, l30, l44;
    void* l3 = NULL;
    void* l7 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    void* l19 = NULL;
    void* l20 = NULL;
    void* l22 = NULL;
    void* l24 = NULL;
    void* l25 = NULL;
    void* l27 = NULL;
    void* l33 = NULL;
    void* l34 = NULL;
    void* l35 = NULL;
    void* l38 = NULL;
    void* l39 = NULL;
    void* l41 = NULL;
    void* l42 = NULL;
    vader_box_t l4 = vader_box_null(), l8 = vader_box_null(), l13 = vader_box_null(), l21 = vader_box_null(), l31 = vader_box_null(), l37 = vader_box_null();
    bool l6, l32, l36;
    vader_string_t l28 = 0;
    vader_string_t l29 = 0;
    vader_string_t l40 = 0;
    uint8_t l43;
    int32_t t0;
    void* t1 = NULL;
    bool t2;
    vader_box_t* gc_roots[6] = { &l4, &l8, &l13, &l21, &l31, &l37 };
    void** gc_raw_roots[26] = {
        &l0, &l3, &l7, &l9, &l10, &l11, &l12, &l14, &l15, &l16, &l17, &l18, &l19, &l20, &l22, &l24,
        &l25, &l27, &l33, &l34, &l35, &l38, &l39, &l41, &l42, &t1,
    };
    vader_string_t* gc_atom_roots[3] = { &l28, &l29, &l40 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 6u, 26u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth;
    l2 = (t0 + INT32_C(1));
    ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth = l2;
    t0 = ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth;
    if ((t0 > INT32_C(256))) {
        t0 = ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth;
        l2 = (t0 - INT32_C(1));
        ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth = l2;
        t1 = vader_parser_peek(l0);
        l3 = ((vader_struct_vader_lexer_Token_t*) t1)->f_span;
        vader_parser_report_nesting_too_deep(l0, 1604u);
        vader_struct_toolchain_ast_NullLitExpr_t* _a0_obj = (vader_struct_toolchain_ast_NullLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_NullLitExpr_t));
        vader_obj_header_init(_a0_obj, 489u);
        _a0_obj->f_span = l3;
        _a0_obj->f_id = (size_t) 0;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = vader_parser_parse_prefix(l0);
    if (l4.tag == 466u) {
        t2 = ((vader_struct_vader_parser_Parser_t*) l0)->f_allow_bare_lambda;
        if (t2) {
            t2 = vader_parser_check(l0, (uint8_t) 70);
            if (t2) {
                l3 = l4.payload.obj;
                t1 = vader_parser_parse_single_param_lambda_tail(l0, l3);
                l4 = vader_ref_box(t1);
            }
        }
    }
    l2 = -(INT32_C(1));
    {
        {
            for (;;) {
                l3 = vader_parser_peek(l0);
                l5 = vader_parser_postfix_bp(((vader_struct_vader_lexer_Token_t*) l3)->f_kind);
                if ((l5 >= INT32_C(0))) {
                    if ((l5 >= l1)) {
                        if (((vader_struct_vader_lexer_Token_t*) l3)->f_kind == INT32_C(76)) {
                            l6 = true;
                        } else {
                            l6 = ((vader_struct_vader_lexer_Token_t*) l3)->f_kind == INT32_C(74);
                        }
                        if (l6) {
                            if (l4.tag == 469u) goto end_59;
                            if (l4.tag == 483u) goto end_59;
                            if (l4.tag == 437u) goto end_59;
                        }
                        l4 = vader_parser_parse_postfix(l0, l4, l3);
                        l2 = -(INT32_C(1));
                        continue;
                    }
                }
                if (((vader_struct_vader_lexer_Token_t*) l3)->f_kind == INT32_C(57)) {
                    t1 = vader_parser_peek_at(l0, INT32_C(1));
                    if (((vader_struct_vader_lexer_Token_t*) t1)->f_kind == INT32_C(21)) {
                        if ((INT32_C(20) >= l1)) {
                            if (l2 == INT32_C(20)) {
                                l7 = ((vader_struct_vader_lexer_Token_t*) l3)->f_span;
                                vader_parser_error(l0, (uint8_t) 9, l7, 1428u);
                                goto end_58;
                            }
                            vader_parser_advance(l0);
                            vader_parser_advance(l0);
                            l8 = vader_parser_parse_expr(l0, INT32_C(21));
                            t1 = l4.payload.obj;
                            l9 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_span)->f_start;
                            t1 = l8.payload.obj;
                            l10 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_span)->f_end;
                            vader_struct_toolchain_span_Span_t* _a1_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
                            vader_obj_header_init(_a1_obj, 524u);
                            _a1_obj->f_start = l9;
                            _a1_obj->f_end = l10;
                            t1 = (void*) _a1_obj;
                            vader_struct_toolchain_ast_BinaryExpr_t* _a2_obj = (vader_struct_toolchain_ast_BinaryExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BinaryExpr_t));
                            vader_obj_header_init(_a2_obj, 436u);
                            _a2_obj->f_span = t1;
                            _a2_obj->f_id = (size_t) 0;
                            _a2_obj->f_op = (uint8_t) 20;
                            _a2_obj->f_left = l4;
                            _a2_obj->f_right = l8;
                            _a2_obj->f_bind_as = vader_box_obj(0u, NULL);
                            t1 = (void*) _a2_obj;
                            l4 = vader_ref_box(t1);
                            l2 = INT32_C(20);
                            continue;
                        }
                    }
                }
                if (((vader_struct_vader_lexer_Token_t*) l3)->f_kind == INT32_C(57)) {
                    t1 = vader_parser_peek_at(l0, INT32_C(1));
                    if (((vader_struct_vader_lexer_Token_t*) t1)->f_kind == INT32_C(19)) {
                        if ((INT32_C(20) >= l1)) {
                            if (l2 == INT32_C(20)) {
                                l11 = ((vader_struct_vader_lexer_Token_t*) l3)->f_span;
                                vader_parser_error(l0, (uint8_t) 9, l11, 1429u);
                                goto end_58;
                            }
                            l12 = vader_parser_advance(l0);
                            vader_parser_advance(l0);
                            l13 = vader_parser_parse_type(l0);
                            t1 = vader_parser_peek(l0);
                            if (((vader_struct_vader_lexer_Token_t*) t1)->f_kind == INT32_C(29)) {
                                l14 = vader_parser_advance(l0);
                                t1 = vader_parser_peek(l0);
                                if (((vader_struct_vader_lexer_Token_t*) t1)->f_kind == INT32_C(2)) {
                                    vader_parser_advance(l0);
                                }
                                l15 = ((vader_struct_vader_lexer_Token_t*) l14)->f_span;
                                vader_parser_error(l0, (uint8_t) 0, l15, 1124u);
                            }
                            t1 = l4.payload.obj;
                            l16 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_span)->f_start;
                            t1 = l13.payload.obj;
                            l17 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_span)->f_end;
                            vader_struct_toolchain_span_Span_t* _a3_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
                            vader_obj_header_init(_a3_obj, 524u);
                            _a3_obj->f_start = l16;
                            _a3_obj->f_end = l17;
                            t1 = (void*) _a3_obj;
                            vader_struct_toolchain_ast_BinaryExpr_t* _a4_obj = (vader_struct_toolchain_ast_BinaryExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BinaryExpr_t));
                            vader_obj_header_init(_a4_obj, 436u);
                            _a4_obj->f_span = t1;
                            _a4_obj->f_id = (size_t) 0;
                            _a4_obj->f_op = (uint8_t) 18;
                            _a4_obj->f_left = l4;
                            _a4_obj->f_right = l13;
                            _a4_obj->f_bind_as = vader_box_obj(0u, NULL);
                            l18 = (void*) _a4_obj;
                            l19 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l12)->f_span)->f_start;
                            t1 = l13.payload.obj;
                            l20 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_span)->f_end;
                            vader_struct_toolchain_span_Span_t* _a5_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
                            vader_obj_header_init(_a5_obj, 524u);
                            _a5_obj->f_start = l19;
                            _a5_obj->f_end = l20;
                            t1 = (void*) _a5_obj;
                            vader_struct_toolchain_ast_UnaryExpr_t* _a6_obj = (vader_struct_toolchain_ast_UnaryExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_UnaryExpr_t));
                            vader_obj_header_init(_a6_obj, 516u);
                            _a6_obj->f_span = t1;
                            _a6_obj->f_id = (size_t) 0;
                            _a6_obj->f_op = (uint8_t) 1;
                            _a6_obj->f_operand = vader_ref_box(l18);
                            t1 = (void*) _a6_obj;
                            l4 = vader_ref_box(t1);
                            l2 = INT32_C(20);
                            continue;
                        }
                    }
                }
                if (((vader_struct_vader_lexer_Token_t*) l3)->f_kind == INT32_C(58)) {
                    if ((INT32_C(6) >= l1)) {
                        vader_parser_advance(l0);
                        l21 = vader_parser_parse_coalesce_fallback(l0);
                        t1 = l4.payload.obj;
                        l22 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_span)->f_start;
                        l23 = -(INT32_C(1));
                        t1 = vader_parser_peek_at(l0, l23);
                        l24 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) t1)->f_span)->f_end;
                        vader_struct_toolchain_span_Span_t* _a7_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
                        vader_obj_header_init(_a7_obj, 524u);
                        _a7_obj->f_start = l22;
                        _a7_obj->f_end = l24;
                        t1 = (void*) _a7_obj;
                        vader_struct_toolchain_ast_NullCoalesceExpr_t* _a8_obj = (vader_struct_toolchain_ast_NullCoalesceExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_NullCoalesceExpr_t));
                        vader_obj_header_init(_a8_obj, 488u);
                        _a8_obj->f_span = t1;
                        _a8_obj->f_id = (size_t) 0;
                        _a8_obj->f_left = l4;
                        _a8_obj->f_fallback = l21;
                        t1 = (void*) _a8_obj;
                        l4 = vader_ref_box(t1);
                        l2 = -(INT32_C(1));
                        continue;
                    }
                }
                l25 = vader_parser_infix_for(((vader_struct_vader_lexer_Token_t*) l3)->f_kind);
                t2 = ((vader_struct_vader_parser_InfixOpDescr_t*) l25)->f_has;
                if (!(t2)) {
                    break;
                }
                t0 = ((vader_struct_vader_parser_InfixOpDescr_t*) l25)->f_left_bp;
                if (!((t0 >= l1))) {
                    break;
                }
                t2 = ((vader_struct_vader_parser_InfixOpDescr_t*) l25)->f_non_assoc;
                if (t2) {
                    l26 = ((vader_struct_vader_parser_InfixOpDescr_t*) l25)->f_left_bp;
                    if (l2 == l26) {
                        l27 = ((vader_struct_vader_lexer_Token_t*) l3)->f_span;
                        l28 = vader_parser_describe_token(l3);
                        l29 = concat_3(1427u, l28, 850u);
                        vader_parser_error(l0, (uint8_t) 9, l27, l29);
                        goto end_58;
                    }
                }
                vader_parser_advance(l0);
                t2 = ((vader_struct_vader_parser_InfixOpDescr_t*) l25)->f_non_assoc;
                if (t2) {
                    t0 = ((vader_struct_vader_parser_InfixOpDescr_t*) l25)->f_right_bp;
                    l30 = (t0 + INT32_C(1));
                } else {
                    l30 = ((vader_struct_vader_parser_InfixOpDescr_t*) l25)->f_right_bp;
                }
                if (((vader_struct_vader_parser_InfixOpDescr_t*) l25)->f_op == INT32_C(18)) {
                    l31 = vader_parser_parse_type(l0);
                } else {
                    l31 = vader_parser_parse_expr(l0, l30);
                }
                if (((vader_struct_vader_lexer_Token_t*) l3)->f_kind == INT32_C(67)) {
                    l32 = true;
                } else {
                    l32 = ((vader_struct_vader_lexer_Token_t*) l3)->f_kind == INT32_C(68);
                }
                if (l32) {
                    t1 = l4.payload.obj;
                    l33 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_span)->f_start;
                    t1 = l31.payload.obj;
                    l34 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_span)->f_end;
                    vader_struct_toolchain_span_Span_t* _a9_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
                    vader_obj_header_init(_a9_obj, 524u);
                    _a9_obj->f_start = l33;
                    _a9_obj->f_end = l34;
                    l35 = (void*) _a9_obj;
                    l36 = ((vader_struct_vader_lexer_Token_t*) l3)->f_kind == INT32_C(68);
                    vader_struct_toolchain_ast_RangeExpr_t* _a10_obj = (vader_struct_toolchain_ast_RangeExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_RangeExpr_t));
                    vader_obj_header_init(_a10_obj, 495u);
                    _a10_obj->f_span = l35;
                    _a10_obj->f_id = (size_t) 0;
                    _a10_obj->f_inclusive = l36;
                    _a10_obj->f_lower = l4;
                    _a10_obj->f_upper = l31;
                    t1 = (void*) _a10_obj;
                    l4 = vader_ref_box(t1);
                } else {
                    l37 = vader_box_obj(0u, NULL);
                    t1 = l31.payload.obj;
                    l38 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_span)->f_end;
                    if (((vader_struct_vader_parser_InfixOpDescr_t*) l25)->f_op == INT32_C(18)) {
                        t1 = vader_parser_peek(l0);
                        if (((vader_struct_vader_lexer_Token_t*) t1)->f_kind == INT32_C(29)) {
                            vader_parser_advance(l0);
                            l39 = vader_parser_expect(l0, (uint8_t) 2, 1312u);
                            l40 = ((vader_struct_vader_lexer_Token_t*) l39)->f_text;
                            l41 = ((vader_struct_vader_lexer_Token_t*) l39)->f_span;
                            vader_struct_toolchain_ast_AsBinding_t* _a11_obj = (vader_struct_toolchain_ast_AsBinding_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_AsBinding_t));
                            vader_obj_header_init(_a11_obj, 432u);
                            _a11_obj->f_name = l40;
                            _a11_obj->f_span = l41;
                            t1 = (void*) _a11_obj;
                            l37 = vader_ref_box(t1);
                            l38 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l39)->f_span)->f_end;
                        }
                    }
                    t1 = l4.payload.obj;
                    vader_struct_toolchain_span_Span_t* _a12_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
                    vader_obj_header_init(_a12_obj, 524u);
                    _a12_obj->f_start = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_span)->f_start;
                    _a12_obj->f_end = l38;
                    l42 = (void*) _a12_obj;
                    l43 = ((vader_struct_vader_parser_InfixOpDescr_t*) l25)->f_op;
                    vader_struct_toolchain_ast_BinaryExpr_t* _a13_obj = (vader_struct_toolchain_ast_BinaryExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BinaryExpr_t));
                    vader_obj_header_init(_a13_obj, 436u);
                    _a13_obj->f_span = l42;
                    _a13_obj->f_id = (size_t) 0;
                    _a13_obj->f_op = l43;
                    _a13_obj->f_left = l4;
                    _a13_obj->f_right = l31;
                    _a13_obj->f_bind_as = l37;
                    t1 = (void*) _a13_obj;
                    l4 = vader_ref_box(t1);
                }
                t2 = ((vader_struct_vader_parser_InfixOpDescr_t*) l25)->f_non_assoc;
                if (t2) {
                    l44 = ((vader_struct_vader_parser_InfixOpDescr_t*) l25)->f_left_bp;
                } else {
                    l44 = -(INT32_C(1));
                }
                l2 = l44;
                continue;
            }
            goto end_58;
        } end_59: ;
    } end_58: ;
    t0 = ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth;
    l2 = (t0 - INT32_C(1));
    ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth = l2;
    { vader_box_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_fn_body_tail(void* l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    void* l4 = NULL;
    bool t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[4] = { &l0, &l3, &l4, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_parser_check(l0, (uint8_t) 59);
    if (t0) {
        vader_parser_advance(l0);
        l2 = vader_parser_parse_expr(l0, INT32_C(0));
        t1 = l2.payload.obj;
        l3 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_span;
        vader_array_t* _a0_arr = vader_array_new(177u, 0u, 13u, 1262u);
        l4 = (void*) _a0_arr;
        vader_struct_toolchain_ast_BlockExpr_t* _a1_obj = (vader_struct_toolchain_ast_BlockExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BlockExpr_t));
        vader_obj_header_init(_a1_obj, 437u);
        _a1_obj->f_span = l3;
        _a1_obj->f_id = (size_t) 0;
        _a1_obj->f_stmts = l4;
        _a1_obj->f_trailing = l2;
        t1 = (void*) _a1_obj;
        vader_struct_vader_parser_FnBodyTail_t* _a2_obj = (vader_struct_vader_parser_FnBodyTail_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_FnBodyTail_t));
        vader_obj_header_init(_a2_obj, 978u);
        _a2_obj->f_body = vader_ref_box(t1);
        _a2_obj->f_is_expression_bodied = true;
        t1 = (void*) _a2_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_parser_check(l0, (uint8_t) 78);
    if (!(t0)) {
        vader_struct_vader_parser_FnBodyTail_t* _a3_obj = (vader_struct_vader_parser_FnBodyTail_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_FnBodyTail_t));
        vader_obj_header_init(_a3_obj, 978u);
        _a3_obj->f_body = vader_box_obj(0u, NULL);
        _a3_obj->f_is_expression_bodied = false;
        t1 = (void*) _a3_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_parser_parse_block(l0);
    vader_struct_vader_parser_FnBodyTail_t* _a4_obj = (vader_struct_vader_parser_FnBodyTail_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_FnBodyTail_t));
    vader_obj_header_init(_a4_obj, 978u);
    _a4_obj->f_body = vader_ref_box(t1);
    _a4_obj->f_is_expression_bodied = false;
    t1 = (void*) _a4_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_fn_decl(void* l0, void* l1, uint8_t l2, void* l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l9 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    vader_box_t l7 = vader_box_null(), l13 = vader_box_null();
    int32_t l8;
    vader_string_t l10 = 0;
    bool l14, l15;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[3] = { &l7, &l13, &t0 };
    void** gc_raw_roots[10] = { &l0, &l1, &l3, &l4, &l5, &l6, &l9, &l11, &l12, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l10 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_parser_reject_c_decorators(l0, l1, 1185u);
    vader_parser_advance(l0);
    l4 = vader_parser_parse_angle_type_params(l0);
    l5 = vader_parser_parse_fn_signature_params(l0);
    l6 = ((vader_struct_vader_parser_FnSignature_t*) l5)->f_type_params;
    l4 = vader_parser_merge_type_params(l4, l6);
    l7 = vader_box_obj(0u, NULL);
    t0 = vader_parser_match_kind(l0, (uint8_t) 70);
    if (!(t0.tag == 0u)) {
        l7 = vader_parser_parse_type(l0);
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
    vader_obj_header_init(_a0_obj, 461u);
    _a0_obj->f_span = l9;
    _a0_obj->f_id = (size_t) 0;
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
}

static vader_box_t vader_parser_parse_fn_decl_inside_trait(void* l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    uint8_t l2;
    bool l3, l15;
    vader_string_t l5 = 0;
    vader_box_t l9 = vader_box_null(), l14 = vader_box_null();
    int32_t l10;
    vader_box_t t0 = vader_box_null();
    bool t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[3] = { &l9, &l14, &t0 };
    void** gc_raw_roots[10] = { &l0, &l1, &l4, &l6, &l7, &l8, &l11, &l12, &l13, &t2 };
    vader_string_t* gc_atom_roots[1] = { &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_parse_decorators(l0);
    vader_parser_reject_displayable_decorator(l0, l1);
    l2 = (uint8_t) 1;
    t0 = vader_parser_match_kind(l0, (uint8_t) 30);
    if (!(t0.tag == 0u)) {
        l2 = (uint8_t) 0;
    }
    t1 = vader_parser_check(l0, (uint8_t) 2);
    if (t1) {
        t2 = vader_parser_peek_at(l0, INT32_C(1));
        l3 = ((vader_struct_vader_lexer_Token_t*) t2)->f_kind == INT32_C(65);
    } else {
        l3 = false;
    }
    if (l3) {
        t2 = vader_parser_peek_at(l0, INT32_C(2));
        l3 = ((vader_struct_vader_lexer_Token_t*) t2)->f_kind == INT32_C(11);
    } else {
        l3 = false;
    }
    if (l3) {
        l4 = vader_parser_advance(l0);
        vader_parser_advance(l0);
        vader_parser_advance(l0);
        l6 = vader_parser_parse_angle_type_params(l0);
        l7 = vader_parser_parse_fn_signature_params(l0);
        l8 = ((vader_struct_vader_parser_FnSignature_t*) l7)->f_type_params;
        l6 = vader_parser_merge_type_params(l6, l8);
        l9 = vader_box_obj(0u, NULL);
        t0 = vader_parser_match_kind(l0, (uint8_t) 70);
        if (!(t0.tag == 0u)) {
            l9 = vader_parser_parse_type(l0);
        }
        l8 = vader_parser_parse_fn_body_tail(l0, l9);
        l10 = -(INT32_C(1));
        l11 = vader_parser_peek_at(l0, l10);
        l11 = vader_parser_span_of(l0, l4, l11);
        l5 = ((vader_struct_vader_lexer_Token_t*) l4)->f_text;
        l12 = ((vader_struct_vader_lexer_Token_t*) l4)->f_span;
        l13 = ((vader_struct_vader_parser_FnSignature_t*) l7)->f_params;
        l14 = ((vader_struct_vader_parser_FnBodyTail_t*) l8)->f_body;
        l3 = ((vader_struct_vader_parser_FnBodyTail_t*) l8)->f_is_expression_bodied;
        l15 = ((vader_struct_vader_parser_FnSignature_t*) l7)->f_trailing_comma;
        vader_struct_toolchain_ast_FnDecl_t* _a0_obj = (vader_struct_toolchain_ast_FnDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FnDecl_t));
        vader_obj_header_init(_a0_obj, 461u);
        _a0_obj->f_span = l11;
        _a0_obj->f_id = (size_t) 0;
        _a0_obj->f_name = l5;
        _a0_obj->f_name_span = l12;
        _a0_obj->f_visibility = l2;
        _a0_obj->f_type_params = l6;
        _a0_obj->f_params = l13;
        _a0_obj->f_return_type = l9;
        _a0_obj->f_body = l14;
        _a0_obj->f_decorators = l1;
        _a0_obj->f_sam_synthetic = false;
        _a0_obj->f_is_expression_bodied = l3;
        _a0_obj->f_materialized = false;
        _a0_obj->f_comptime_synthetic = false;
        _a0_obj->f_trailing_comma = l15;
        t2 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = vader_parser_peek(l0);
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(11)) {
        l4 = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
        vader_parser_error(l0, (uint8_t) 5, l4, 2340u);
    } else {
        l4 = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
        l5 = vader_parser_describe_token(l1);
        l5 = concat_3(1591u, l5, 243u);
        vader_parser_error(l0, (uint8_t) 5, l4, l5);
    }
    for (;;) {
        t1 = vader_parser_check(l0, (uint8_t) 79);
        if (!(t1)) {
            t1 = vader_parser_check(l0, (uint8_t) 0);
            if (t1) break;
            t1 = vader_parser_check(l0, (uint8_t) 2);
            if (t1) {
                t2 = vader_parser_peek_at(l0, INT32_C(1));
                if (((vader_struct_vader_lexer_Token_t*) t2)->f_kind == INT32_C(65)) {
                    t2 = vader_parser_peek_at(l0, INT32_C(2));
                    if (((vader_struct_vader_lexer_Token_t*) t2)->f_kind == INT32_C(11)) break;
                }
            }
            vader_parser_advance(l0);
            continue;
        }
        break;
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static void* vader_parser_parse_fn_signature_params(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l19 = NULL;
    void* l24 = NULL;
    void* l27 = NULL;
    void* l28 = NULL;
    void* l31 = NULL;
    bool l3, l4, l7, l9, l14, l15, l18, l23, l30;
    vader_string_t l12 = 0;
    vader_string_t l13 = 0;
    vader_string_t l20 = 0;
    vader_string_t l21 = 0;
    vader_string_t l29 = 0;
    vader_box_t l16 = vader_box_null(), l17 = vader_box_null(), l22 = vader_box_null(), l25 = vader_box_null();
    int32_t l26;
    bool t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[5] = { &l16, &l17, &l22, &l25, &t1 };
    void** gc_raw_roots[14] = {
        &l0, &l1, &l2, &l5, &l6, &l8, &l10, &l11, &l19, &l24, &l27, &l28, &l31, &t2,
    };
    vader_string_t* gc_atom_roots[5] = { &l12, &l13, &l20, &l21, &l29 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 5u, 14u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(38u, 0u, 13u, 515u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(28u, 0u, 13u, 462u);
    l2 = (void*) _a1_arr;
    l3 = false;
    vader_parser_expect(l0, (uint8_t) 74, 1042u);
    vader_parser_skip_newlines(l0);
    t0 = vader_parser_check(l0, (uint8_t) 75);
    if (!(t0)) {
        l4 = true;
        for (;;) {
            vader_parser_skip_newlines(l0);
            t0 = vader_parser_check(l0, (uint8_t) 75);
            if (!(t0)) {
                t0 = vader_parser_check(l0, (uint8_t) 0);
                if (t0) break;
                if (!(l4)) {
                    t1 = vader_parser_match_kind(l0, (uint8_t) 80);
                    if (t1.tag == 0u) break;
                    vader_parser_skip_newlines(l0);
                    t0 = vader_parser_check(l0, (uint8_t) 75);
                    if (t0) {
                        l3 = true;
                        break;
                    }
                }
                l4 = false;
                l5 = vader_parser_peek(l0);
                l6 = vader_parser_parse_decorators(l0);
                l7 = false;
                t0 = vader_parser_check(l0, (uint8_t) 81);
                if (t0) {
                    t0 = vader_parser_check_at(l0, (uint8_t) 81, INT32_C(1));
                    if (t0) {
                        t0 = vader_parser_check_at(l0, (uint8_t) 81, INT32_C(2));
                        if (t0) {
                            vader_parser_advance(l0);
                            vader_parser_advance(l0);
                            vader_parser_advance(l0);
                            l7 = true;
                        }
                    }
                }
                l8 = vader_parser_empty_token();
                t0 = vader_parser_check(l0, (uint8_t) 34);
                if (t0) {
                    l9 = true;
                } else {
                    l9 = vader_parser_check(l0, (uint8_t) 2);
                }
                if (l9) {
                    l8 = vader_parser_advance(l0);
                    l14 = false;
                    t1 = vader_parser_match_kind(l0, (uint8_t) 57);
                    if (!(t1.tag == 0u)) {
                        l14 = true;
                    }
                    l15 = false;
                    if (!(l14)) {
                        t0 = vader_parser_check(l0, (uint8_t) 48);
                        if (t0) {
                            vader_parser_advance(l0);
                            l14 = true;
                            l15 = true;
                        }
                    }
                    l16 = vader_box_obj(0u, NULL);
                    t1 = vader_parser_match_kind(l0, (uint8_t) 82);
                    if (!(t1.tag == 0u)) {
                        vader_parser_skip_newlines(l0);
                        l16 = vader_parser_parse_type(l0);
                    }
                    l17 = vader_box_obj(0u, NULL);
                    if (l15) {
                        l18 = true;
                    } else {
                        t1 = vader_parser_match_kind(l0, (uint8_t) 59);
                        l18 = !(t1.tag == 0u);
                    }
                    if (l18) {
                        l17 = vader_parser_parse_expr(l0, INT32_C(0));
                    }
                    vader_parser_collect_type_params(l16, l1);
                    if (l14) {
                        if (!(l16.tag == 0u)) {
                            l19 = ((vader_struct_vader_lexer_Token_t*) l8)->f_span;
                            l20 = ((vader_struct_vader_lexer_Token_t*) l8)->f_text;
                            l21 = concat_3(2605u, l20, 343u);
                            vader_parser_error(l0, (uint8_t) 27, l19, l21);
                        }
                    }
                    if (l14) {
                        l23 = !(l16.tag == 0u);
                    } else {
                        l23 = false;
                    }
                    if (l23) {
                        t2 = l16.payload.obj;
                        l24 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t2)->f_span;
                        l25 = l16;
                        vader_struct_toolchain_ast_MutableTypeExpr_t* _a2_obj = (vader_struct_toolchain_ast_MutableTypeExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_MutableTypeExpr_t));
                        vader_obj_header_init(_a2_obj, 485u);
                        _a2_obj->f_span = l24;
                        _a2_obj->f_id = (size_t) 0;
                        _a2_obj->f_inner = l25;
                        _a2_obj->f_deduced = false;
                        t2 = (void*) _a2_obj;
                        l22 = vader_ref_box(t2);
                    } else {
                        l22 = l16;
                    }
                    l26 = -(INT32_C(1));
                    l27 = vader_parser_peek_at(l0, l26);
                    l28 = vader_parser_span_of(l0, l5, l27);
                    l29 = ((vader_struct_vader_lexer_Token_t*) l8)->f_text;
                    if (l14) {
                        l30 = l16.tag == 0u;
                    } else {
                        l30 = false;
                    }
                    vader_struct_toolchain_ast_FnParam_t* _a3_obj = (vader_struct_toolchain_ast_FnParam_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FnParam_t));
                    vader_obj_header_init(_a3_obj, 462u);
                    _a3_obj->f_span = l28;
                    _a3_obj->f_id = (size_t) 0;
                    _a3_obj->f_name = l29;
                    _a3_obj->f_ty = l22;
                    _a3_obj->f_default_value = l17;
                    _a3_obj->f_variadic = l7;
                    _a3_obj->f_mutable = l30;
                    _a3_obj->f_decorators = l6;
                    l31 = (void*) _a3_obj;
                    vader_array_push((vader_array_t*) l2, vader_ref_box(l31));
                    continue;
                }
                l10 = vader_parser_peek(l0);
                l11 = ((vader_struct_vader_lexer_Token_t*) l10)->f_span;
                l12 = vader_parser_describe_token(l10);
                l13 = concat_3(1592u, l12, 243u);
                vader_parser_error(l0, (uint8_t) 1, l11, l13);
                for (;;) {
                    t0 = vader_parser_check(l0, (uint8_t) 80);
                    if (!(t0)) {
                        t0 = vader_parser_check(l0, (uint8_t) 75);
                        if (t0) break;
                        t0 = vader_parser_check(l0, (uint8_t) 0);
                        if (t0) break;
                        vader_parser_advance(l0);
                        continue;
                    }
                    break;
                }
                continue;
            }
            break;
        }
    }
    vader_parser_expect(l0, (uint8_t) 75, 1052u);
    vader_struct_vader_parser_FnSignature_t* _a4_obj = (vader_struct_vader_parser_FnSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_FnSignature_t));
    vader_obj_header_init(_a4_obj, 979u);
    _a4_obj->f_params = l2;
    _a4_obj->f_type_params = l1;
    _a4_obj->f_trailing_comma = l3;
    t2 = (void*) _a4_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_fn_type(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l8 = NULL;
    bool l4, l6;
    vader_box_t l5 = vader_box_null(), l10 = vader_box_null();
    int32_t l7;
    size_t l9;
    bool t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[3] = { &l5, &l10, &t1 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l8, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_advance(l0);
    vader_parser_expect(l0, (uint8_t) 74, 1041u);
    vader_array_t* _a0_arr = vader_array_new(175u, 0u, 13u, 1241u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(9u, 0u, 12u, 238u);
    l3 = (void*) _a1_arr;
    l4 = false;
    vader_parser_skip_newlines(l0);
    t0 = vader_parser_check(l0, (uint8_t) 75);
    if (!(t0)) {
        for (;;) {
            vader_parser_skip_newlines(l0);
            t0 = vader_parser_check(l0, (uint8_t) 75);
            if (!(t0)) {
                l5 = vader_parser_parse_type(l0);
                vader_array_push((vader_array_t*) l2, l5);
                t1 = vader_parser_match_kind(l0, (uint8_t) 57);
                l6 = !(t1.tag == 0u);
                if (l6) {
                    l4 = true;
                }
                vader_array_push_bool((vader_array_t*) l3, l6);
                vader_parser_skip_newlines(l0);
                t1 = vader_parser_match_kind(l0, (uint8_t) 80);
                if (t1.tag == 0u) break;
                continue;
            }
            break;
        }
    }
    vader_parser_expect(l0, (uint8_t) 75, 1049u);
    l5 = vader_box_obj(0u, NULL);
    t1 = vader_parser_match_kind(l0, (uint8_t) 70);
    if (!(t1.tag == 0u)) {
        l5 = vader_parser_parse_type(l0);
    }
    l7 = -(INT32_C(1));
    l8 = vader_parser_peek_at(l0, l7);
    l1 = vader_parser_span_of(l0, l1, l8);
    l9 = (size_t) 0;
    if (l4) {
        l10 = vader_ref_box(l3);
        vader_struct_toolchain_ast_FnTypeExpr_t* _a2_obj = (vader_struct_toolchain_ast_FnTypeExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FnTypeExpr_t));
        vader_obj_header_init(_a2_obj, 463u);
        _a2_obj->f_span = l1;
        _a2_obj->f_id = l9;
        _a2_obj->f_params = l2;
        _a2_obj->f_params_mutable = l10.payload.obj;
        _a2_obj->f_return_type = l5;
        t2 = (void*) _a2_obj;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a3_arr = vader_array_new(9u, 0u, 12u, 238u);
    t2 = (void*) _a3_arr;
    l10 = vader_ref_box(t2);
    vader_struct_toolchain_ast_FnTypeExpr_t* _a4_obj = (vader_struct_toolchain_ast_FnTypeExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FnTypeExpr_t));
    vader_obj_header_init(_a4_obj, 463u);
    _a4_obj->f_span = l1;
    _a4_obj->f_id = l9;
    _a4_obj->f_params = l2;
    _a4_obj->f_params_mutable = l10.payload.obj;
    _a4_obj->f_return_type = l5;
    t2 = (void*) _a4_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_for(void* l0, vader_box_t l1, bool l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l9 = NULL;
    void* l12 = NULL;
    bool l7;
    vader_box_t l8 = vader_box_null(), l11 = vader_box_null();
    vader_string_t l10 = 0;
    bool t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[3] = { &l1, &l8, &l11 };
    void** gc_raw_roots[8] = { &l0, &l3, &l4, &l5, &l6, &l9, &l12, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l10 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_parser_advance(l0);
    t0 = vader_parser_check(l0, (uint8_t) 78);
    if (t0) {
        l4 = vader_parser_parse_block(l0);
        l5 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l3)->f_span)->f_start;
        l6 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_BlockExpr_t*) l4)->f_span)->f_end;
        vader_struct_toolchain_span_Span_t* _a0_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
        vader_obj_header_init(_a0_obj, 524u);
        _a0_obj->f_start = l5;
        _a0_obj->f_end = l6;
        l5 = (void*) _a0_obj;
        vader_struct_toolchain_ast_InfiniteFor_t* _a1_obj = (vader_struct_toolchain_ast_InfiniteFor_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_InfiniteFor_t));
        vader_obj_header_init(_a1_obj, 475u);
        l6 = (void*) _a1_obj;
        vader_struct_toolchain_ast_ForStmt_t* _a2_obj = (vader_struct_toolchain_ast_ForStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ForStmt_t));
        vader_obj_header_init(_a2_obj, 464u);
        _a2_obj->f_span = l5;
        _a2_obj->f_id = (size_t) 0;
        _a2_obj->f_label = l1;
        _a2_obj->f_form = vader_ref_box(l6);
        _a2_obj->f_body = l4;
        _a2_obj->f_is_comptime = l2;
        t1 = (void*) _a2_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l7 = ((vader_struct_vader_parser_Parser_t*) l0)->f_allow_struct_lit;
    ((vader_struct_vader_parser_Parser_t*) l0)->f_allow_struct_lit = false;
    t0 = vader_parser_check(l0, (uint8_t) 2);
    if (t0) {
        t0 = vader_parser_check_at(l0, (uint8_t) 21, INT32_C(1));
        if (t0) {
            l4 = vader_parser_advance(l0);
            vader_parser_advance(l0);
            l8 = vader_parser_parse_expr(l0, INT32_C(0));
            ((vader_struct_vader_parser_Parser_t*) l0)->f_allow_struct_lit = l7;
            l5 = vader_parser_parse_block(l0);
            l6 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l3)->f_span)->f_start;
            l9 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_BlockExpr_t*) l5)->f_span)->f_end;
            vader_struct_toolchain_span_Span_t* _a3_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
            vader_obj_header_init(_a3_obj, 524u);
            _a3_obj->f_start = l6;
            _a3_obj->f_end = l9;
            l6 = (void*) _a3_obj;
            l10 = ((vader_struct_vader_lexer_Token_t*) l4)->f_text;
            l4 = ((vader_struct_vader_lexer_Token_t*) l4)->f_span;
            vader_struct_toolchain_ast_NamedVar_t* _a4_obj = (vader_struct_toolchain_ast_NamedVar_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_NamedVar_t));
            vader_obj_header_init(_a4_obj, 487u);
            _a4_obj->f_name = l10;
            _a4_obj->f_span = l4;
            t1 = (void*) _a4_obj;
            vader_struct_toolchain_ast_InFor_t* _a5_obj = (vader_struct_toolchain_ast_InFor_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_InFor_t));
            vader_obj_header_init(_a5_obj, 473u);
            _a5_obj->f_loop_var = vader_ref_box(t1);
            _a5_obj->f_iter = l8;
            l4 = (void*) _a5_obj;
            vader_struct_toolchain_ast_ForStmt_t* _a6_obj = (vader_struct_toolchain_ast_ForStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ForStmt_t));
            vader_obj_header_init(_a6_obj, 464u);
            _a6_obj->f_span = l6;
            _a6_obj->f_id = (size_t) 0;
            _a6_obj->f_label = l1;
            _a6_obj->f_form = vader_ref_box(l4);
            _a6_obj->f_body = l5;
            _a6_obj->f_is_comptime = l2;
            t1 = (void*) _a6_obj;
            { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    t0 = vader_parser_looks_like_for_destructure(l0);
    if (t0) {
        l8 = vader_parser_parse_let_binding(l0);
        vader_parser_expect(l0, (uint8_t) 21, 1139u);
        l11 = vader_parser_parse_expr(l0, INT32_C(0));
        ((vader_struct_vader_parser_Parser_t*) l0)->f_allow_struct_lit = l7;
        l4 = vader_parser_parse_block(l0);
        l5 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l3)->f_span)->f_start;
        l6 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_BlockExpr_t*) l4)->f_span)->f_end;
        vader_struct_toolchain_span_Span_t* _a7_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
        vader_obj_header_init(_a7_obj, 524u);
        _a7_obj->f_start = l5;
        _a7_obj->f_end = l6;
        l5 = (void*) _a7_obj;
        vader_struct_toolchain_ast_DestructureVar_t* _a8_obj = (vader_struct_toolchain_ast_DestructureVar_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_DestructureVar_t));
        vader_obj_header_init(_a8_obj, 452u);
        _a8_obj->f_pattern = l8;
        t1 = (void*) _a8_obj;
        vader_struct_toolchain_ast_InFor_t* _a9_obj = (vader_struct_toolchain_ast_InFor_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_InFor_t));
        vader_obj_header_init(_a9_obj, 473u);
        _a9_obj->f_loop_var = vader_ref_box(t1);
        _a9_obj->f_iter = l11;
        l6 = (void*) _a9_obj;
        vader_struct_toolchain_ast_ForStmt_t* _a10_obj = (vader_struct_toolchain_ast_ForStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ForStmt_t));
        vader_obj_header_init(_a10_obj, 464u);
        _a10_obj->f_span = l5;
        _a10_obj->f_id = (size_t) 0;
        _a10_obj->f_label = l1;
        _a10_obj->f_form = vader_ref_box(l6);
        _a10_obj->f_body = l4;
        _a10_obj->f_is_comptime = l2;
        t1 = (void*) _a10_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l8 = vader_parser_parse_expr(l0, INT32_C(0));
    ((vader_struct_vader_parser_Parser_t*) l0)->f_allow_struct_lit = l7;
    l4 = vader_parser_parse_block(l0);
    if (!(l8.tag == 495u)) {
        l9 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l3)->f_span)->f_start;
        l12 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_BlockExpr_t*) l4)->f_span)->f_end;
        vader_struct_toolchain_span_Span_t* _a11_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
        vader_obj_header_init(_a11_obj, 524u);
        _a11_obj->f_start = l9;
        _a11_obj->f_end = l12;
        l9 = (void*) _a11_obj;
        vader_struct_toolchain_ast_WhileFor_t* _a12_obj = (vader_struct_toolchain_ast_WhileFor_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_WhileFor_t));
        vader_obj_header_init(_a12_obj, 517u);
        _a12_obj->f_cond = l8;
        l12 = (void*) _a12_obj;
        vader_struct_toolchain_ast_ForStmt_t* _a13_obj = (vader_struct_toolchain_ast_ForStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ForStmt_t));
        vader_obj_header_init(_a13_obj, 464u);
        _a13_obj->f_span = l9;
        _a13_obj->f_id = (size_t) 0;
        _a13_obj->f_label = l1;
        _a13_obj->f_form = vader_ref_box(l12);
        _a13_obj->f_body = l4;
        _a13_obj->f_is_comptime = l2;
        t1 = (void*) _a13_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l3)->f_span)->f_start;
    l5 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_BlockExpr_t*) l4)->f_span)->f_end;
    vader_struct_toolchain_span_Span_t* _a14_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a14_obj, 524u);
    _a14_obj->f_start = l3;
    _a14_obj->f_end = l5;
    l3 = (void*) _a14_obj;
    vader_struct_toolchain_ast_DiscardVar_t* _a15_obj = (vader_struct_toolchain_ast_DiscardVar_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_DiscardVar_t));
    vader_obj_header_init(_a15_obj, 453u);
    l5 = (void*) _a15_obj;
    l6 = l8.payload.obj;
    vader_struct_toolchain_ast_InFor_t* _a16_obj = (vader_struct_toolchain_ast_InFor_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_InFor_t));
    vader_obj_header_init(_a16_obj, 473u);
    _a16_obj->f_loop_var = vader_ref_box(l5);
    _a16_obj->f_iter = vader_ref_box(l6);
    l5 = (void*) _a16_obj;
    vader_struct_toolchain_ast_ForStmt_t* _a17_obj = (vader_struct_toolchain_ast_ForStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ForStmt_t));
    vader_obj_header_init(_a17_obj, 464u);
    _a17_obj->f_span = l3;
    _a17_obj->f_id = (size_t) 0;
    _a17_obj->f_label = l1;
    _a17_obj->f_form = vader_ref_box(l5);
    _a17_obj->f_body = l4;
    _a17_obj->f_is_comptime = l2;
    t1 = (void*) _a17_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_parser_parse_ident_or_struct_lit(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    int32_t l2;
    vader_string_t l5 = 0;
    bool l8;
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[7] = { &l0, &l1, &l3, &l4, &l6, &l7, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 7u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_advance(l0);
    t0 = vader_parser_check(l0, (uint8_t) 49);
    if (t0) {
        l2 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pos;
        t0 = vader_parser_scan_angle_generic(l0, l2);
        if (t0) {
            vader_parser_advance(l0);
            l3 = vader_parser_parse_type_list_until_angle(l0);
            l4 = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
            l5 = ((vader_struct_vader_lexer_Token_t*) l1)->f_text;
            l4 = vader_parser_ident_expr(l4, l5);
            l2 = -(INT32_C(1));
            l6 = vader_parser_peek_at(l0, l2);
            t1 = vader_parser_span_of(l0, l1, l6);
            vader_struct_toolchain_ast_GenericInstExpr_t* _a0_obj = (vader_struct_toolchain_ast_GenericInstExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_GenericInstExpr_t));
            vader_obj_header_init(_a0_obj, 465u);
            _a0_obj->f_span = t1;
            _a0_obj->f_id = (size_t) 0;
            _a0_obj->f_callee = vader_ref_box(l4);
            _a0_obj->f_type_args = l3;
            l3 = (void*) _a0_obj;
            t0 = ((vader_struct_vader_parser_Parser_t*) l0)->f_allow_struct_lit;
            if (t0) {
                t0 = vader_parser_check(l0, (uint8_t) 78);
                if (t0) {
                    vader_parser_advance(l0);
                    l4 = vader_parser_parse_struct_lit_fields(l0);
                    l6 = vader_parser_expect(l0, (uint8_t) 79, 1159u);
                    l6 = vader_parser_span_of(l0, l1, l6);
                    l7 = ((vader_struct_vader_parser_CommaList__StructLitField___StructLitSpread_t*) l4)->f_items;
                    l8 = ((vader_struct_vader_parser_CommaList__StructLitField___StructLitSpread_t*) l4)->f_trailing_comma;
                    vader_struct_toolchain_ast_StructLitExpr_t* _a1_obj = (vader_struct_toolchain_ast_StructLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_StructLitExpr_t));
                    vader_obj_header_init(_a1_obj, 507u);
                    _a1_obj->f_span = l6;
                    _a1_obj->f_id = (size_t) 0;
                    _a1_obj->f_type_name = vader_ref_box(l3);
                    _a1_obj->f_items = l7;
                    _a1_obj->f_trailing_comma = l8;
                    t1 = (void*) _a1_obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
            }
            vader_parser_expect(l0, (uint8_t) 74, 1043u);
            l4 = vader_parser_parse_call_args(l0);
            l6 = vader_parser_expect(l0, (uint8_t) 75, 1051u);
            l6 = vader_parser_span_of(l0, l1, l6);
            l7 = ((vader_struct_vader_parser_CommaList__CallArg_t*) l4)->f_items;
            l8 = ((vader_struct_vader_parser_CommaList__CallArg_t*) l4)->f_trailing_comma;
            vader_struct_toolchain_ast_CallExpr_t* _a2_obj = (vader_struct_toolchain_ast_CallExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_CallExpr_t));
            vader_obj_header_init(_a2_obj, 441u);
            _a2_obj->f_span = l6;
            _a2_obj->f_id = (size_t) 0;
            _a2_obj->f_callee = vader_ref_box(l3);
            _a2_obj->f_args = l7;
            _a2_obj->f_trailing_comma = l8;
            t1 = (void*) _a2_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    t0 = ((vader_struct_vader_parser_Parser_t*) l0)->f_allow_struct_lit;
    if (t0) {
        t0 = vader_parser_check(l0, (uint8_t) 78);
        if (t0) {
            l3 = ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens;
            l2 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pos;
            t0 = vader_parser_looks_like_struct_lit_body(l3, l2);
            if (t0) {
                vader_parser_advance(l0);
                l3 = vader_parser_parse_struct_lit_fields(l0);
                l4 = vader_parser_expect(l0, (uint8_t) 79, 1159u);
                l4 = vader_parser_span_of(l0, l1, l4);
                l6 = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
                l5 = ((vader_struct_vader_lexer_Token_t*) l1)->f_text;
                l6 = vader_parser_ident_expr(l6, l5);
                l7 = ((vader_struct_vader_parser_CommaList__StructLitField___StructLitSpread_t*) l3)->f_items;
                l8 = ((vader_struct_vader_parser_CommaList__StructLitField___StructLitSpread_t*) l3)->f_trailing_comma;
                vader_struct_toolchain_ast_StructLitExpr_t* _a3_obj = (vader_struct_toolchain_ast_StructLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_StructLitExpr_t));
                vader_obj_header_init(_a3_obj, 507u);
                _a3_obj->f_span = l4;
                _a3_obj->f_id = (size_t) 0;
                _a3_obj->f_type_name = vader_ref_box(l6);
                _a3_obj->f_items = l7;
                _a3_obj->f_trailing_comma = l8;
                t1 = (void*) _a3_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
    }
    l3 = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
    l5 = ((vader_struct_vader_lexer_Token_t*) l1)->f_text;
    t1 = vader_parser_ident_expr(l3, l5);
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_if_expr(void* l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    void* l6 = NULL;
    bool l2;
    vader_box_t l3 = vader_box_null(), l5 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    bool t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[3] = { &l3, &l5, &t0 };
    void** gc_raw_roots[5] = { &l0, &l1, &l4, &l6, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_advance(l0);
    l2 = ((vader_struct_vader_parser_Parser_t*) l0)->f_allow_struct_lit;
    ((vader_struct_vader_parser_Parser_t*) l0)->f_allow_struct_lit = false;
    l3 = vader_parser_parse_expr(l0, INT32_C(0));
    ((vader_struct_vader_parser_Parser_t*) l0)->f_allow_struct_lit = l2;
    l4 = vader_parser_parse_block(l0);
    l5 = vader_box_obj(0u, NULL);
    vader_parser_skip_newlines(l0);
    t0 = vader_parser_match_kind(l0, (uint8_t) 17);
    if (!(t0.tag == 0u)) {
        vader_parser_skip_newlines(l0);
        t1 = vader_parser_check(l0, (uint8_t) 16);
        if (t1) {
            t2 = vader_parser_parse_if_expr(l0);
            vader_struct_toolchain_ast_IfElseIf_t* _a0_obj = (vader_struct_toolchain_ast_IfElseIf_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_IfElseIf_t));
            vader_obj_header_init(_a0_obj, 468u);
            _a0_obj->f_branch = t2;
            t2 = (void*) _a0_obj;
            l5 = vader_ref_box(t2);
        } else {
            t2 = vader_parser_parse_block(l0);
            vader_struct_toolchain_ast_IfElseBlock_t* _a1_obj = (vader_struct_toolchain_ast_IfElseBlock_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_IfElseBlock_t));
            vader_obj_header_init(_a1_obj, 467u);
            _a1_obj->f_block = t2;
            t2 = (void*) _a1_obj;
            l5 = vader_ref_box(t2);
        }
    }
    if (l5.tag == 468u) {
        t2 = l5.payload.obj;
        l6 = ((vader_struct_toolchain_ast_IfExpr_t*) ((vader_struct_toolchain_ast_IfElseIf_t*) t2)->f_branch)->f_span;
    } else if (l5.tag == 467u) {
        t2 = l5.payload.obj;
        l6 = ((vader_struct_toolchain_ast_BlockExpr_t*) ((vader_struct_toolchain_ast_IfElseBlock_t*) t2)->f_block)->f_span;
    } else {
        if (!(l5.tag == 0u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l6 = ((vader_struct_toolchain_ast_BlockExpr_t*) l4)->f_span;
    }
    l1 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l1)->f_span)->f_start;
    l6 = ((vader_struct_toolchain_span_Span_t*) l6)->f_end;
    vader_struct_toolchain_span_Span_t* _a2_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a2_obj, 524u);
    _a2_obj->f_start = l1;
    _a2_obj->f_end = l6;
    t2 = (void*) _a2_obj;
    vader_struct_toolchain_ast_IfExpr_t* _a3_obj = (vader_struct_toolchain_ast_IfExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_IfExpr_t));
    vader_obj_header_init(_a3_obj, 469u);
    _a3_obj->f_span = t2;
    _a3_obj->f_id = (size_t) 0;
    _a3_obj->f_cond = l3;
    _a3_obj->f_then_block = l4;
    _a3_obj->f_else_branch = l5;
    t2 = (void*) _a3_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_impl_decl(void* l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l16 = NULL;
    vader_box_t l3 = vader_box_null(), l15 = vader_box_null();
    bool l7, l14;
    size_t l9, l10;
    int32_t l13;
    vader_string_t l17 = 0;
    bool t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_string_t t3 = 0;
    int64_t t4;
    vader_box_t* gc_roots[3] = { &l3, &l15, &t1 };
    void** gc_raw_roots[11] = { &l0, &l1, &l2, &l4, &l5, &l6, &l8, &l11, &l12, &l16, &t2 };
    vader_string_t* gc_atom_roots[2] = { &l17, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 11u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_parser_reject_target_decorator(l0, l1, 1230u);
    l2 = vader_parser_peek(l0);
    l3 = vader_parser_parse_type(l0);
    vader_parser_expect(l0, (uint8_t) 14, 1137u);
    vader_array_t* _a0_arr = vader_array_new(38u, 0u, 13u, 515u);
    l4 = (void*) _a0_arr;
    t0 = vader_parser_check(l0, (uint8_t) 49);
    if (t0) {
        l4 = vader_parser_parse_angle_type_params(l0);
    }
    l5 = vader_parser_expect(l0, (uint8_t) 2, 2337u);
    vader_array_t* _a1_arr = vader_array_new(175u, 0u, 13u, 1241u);
    l6 = (void*) _a1_arr;
    t1 = vader_parser_match_kind(l0, (uint8_t) 49);
    if (!(t1.tag == 0u)) {
        l6 = vader_parser_parse_type_list_until_angle(l0);
    }
    l7 = false;
    l8 = l1;
    l9 = ((vader_array_t*) l8)->length;
    l10 = (size_t) 0;
    while ((l10 < l9)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t2 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l10);
        t3 = ((vader_struct_toolchain_ast_Decorator_t*) t2)->f_name;
        if (t3 == 1840u) {
            l7 = true;
        }
        t4 = (l10 + INT64_C(1));
        l10 = (size_t) (int64_t) t4;
    }
    vader_array_t* _a3_arr = vader_array_new(27u, 0u, 13u, 461u);
    l8 = (void*) _a3_arr;
    l11 = l5;
    t0 = vader_parser_check(l0, (uint8_t) 70);
    if (t0) {
        l12 = vader_parser_parse_sam_arrow_member(l0);
        vader_array_push((vader_array_t*) l8, vader_ref_box(l12));
        l13 = -(INT32_C(1));
        l11 = vader_parser_peek_at(l0, l13);
    } else {
        t0 = vader_parser_check(l0, (uint8_t) 78);
        if (t0) {
            l14 = vader_parser_peek_is_classic_impl_body(l0);
        } else {
            l14 = false;
        }
        if (l14) {
            vader_parser_advance(l0);
            vader_parser_skip_newlines(l0);
            for (;;) {
                t0 = vader_parser_check(l0, (uint8_t) 79);
                if (!(t0)) {
                    t0 = vader_parser_check(l0, (uint8_t) 0);
                    if (t0) break;
                    l15 = vader_parser_parse_fn_decl_inside_trait(l0);
                    if (l15.tag == 461u) {
                        t2 = l15.payload.obj;
                        l12 = ((vader_struct_toolchain_ast_FnDecl_t*) t2)->f_decorators;
                        vader_parser_reject_target_decorator(l0, l12, 1238u);
                        l16 = l15.payload.obj;
                        vader_array_push((vader_array_t*) l8, vader_ref_box(l16));
                    } else if (!(l15.tag == 0u)) {
                        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                    }
                    vader_parser_skip_newlines(l0);
                    continue;
                }
                break;
            }
            l11 = vader_parser_expect(l0, (uint8_t) 79, 1155u);
        } else {
            t0 = vader_parser_check(l0, (uint8_t) 78);
            if (t0) {
                l12 = vader_parser_parse_sam_block_member(l0);
                vader_array_push((vader_array_t*) l8, vader_ref_box(l12));
                l13 = -(INT32_C(1));
                l11 = vader_parser_peek_at(l0, l13);
            } else if (l7) {
                l13 = -(INT32_C(1));
                l11 = vader_parser_peek_at(l0, l13);
            } else {
                l12 = vader_parser_peek(l0);
                l16 = ((vader_struct_vader_lexer_Token_t*) l12)->f_span;
                l17 = vader_parser_describe_token(l12);
                l17 = concat_3(1574u, l17, 243u);
                vader_parser_error(l0, (uint8_t) 5, l16, l17);
                l11 = l12;
            }
        }
    }
    l2 = vader_parser_span_of(l0, l2, l11);
    l17 = ((vader_struct_vader_lexer_Token_t*) l5)->f_text;
    l5 = ((vader_struct_vader_lexer_Token_t*) l5)->f_span;
    vader_struct_toolchain_ast_ImplDecl_t* _a4_obj = (vader_struct_toolchain_ast_ImplDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ImplDecl_t));
    vader_obj_header_init(_a4_obj, 470u);
    _a4_obj->f_span = l2;
    _a4_obj->f_id = (size_t) 0;
    _a4_obj->f_type_params = l4;
    _a4_obj->f_for_type = l3;
    _a4_obj->f_trait_name = l17;
    _a4_obj->f_trait_name_span = l5;
    _a4_obj->f_trait_args = l6;
    _a4_obj->f_members = l8;
    _a4_obj->f_decorators = l1;
    t2 = (void*) _a4_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_import_decl(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    int32_t l5;
    vader_string_t l7 = 0;
    bool l9;
    bool t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l4, &l6, &l8, &t2 };
    vader_string_t* gc_atom_roots[1] = { &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_parser_advance(l0);
    l3 = vader_parser_expect_string_literal(l0, 1796u);
    t0 = vader_parser_check(l0, (uint8_t) 29);
    if (t0) {
        l4 = vader_parser_peek(l0);
        l4 = ((vader_struct_vader_lexer_Token_t*) l4)->f_span;
        vader_parser_error(l0, (uint8_t) 5, l4, 2298u);
        vader_parser_advance(l0);
        t0 = vader_parser_check(l0, (uint8_t) 2);
        if (t0) {
            vader_parser_advance(l0);
        }
    }
    t1 = vader_parser_match_kind(l0, (uint8_t) 78);
    if (!(t1.tag == 0u)) {
        l4 = vader_parser_parse_import_name_list_rest(l0);
        l5 = -(INT32_C(1));
        l6 = vader_parser_peek_at(l0, l5);
        l6 = vader_parser_span_of(l0, l2, l6);
        l7 = ((vader_struct_vader_parser_StringLitInfo_t*) l3)->f_text;
        l8 = ((vader_struct_vader_parser_CommaList__ImportName_t*) l4)->f_items;
        l9 = ((vader_struct_vader_parser_CommaList__ImportName_t*) l4)->f_trailing_comma;
        vader_struct_toolchain_ast_DestructureImport_t* _a0_obj = (vader_struct_toolchain_ast_DestructureImport_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_DestructureImport_t));
        vader_obj_header_init(_a0_obj, 451u);
        _a0_obj->f_names = l8;
        _a0_obj->f_trailing_comma = l9;
        l4 = (void*) _a0_obj;
        vader_struct_toolchain_ast_ImportDecl_t* _a1_obj = (vader_struct_toolchain_ast_ImportDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ImportDecl_t));
        vader_obj_header_init(_a1_obj, 471u);
        _a1_obj->f_span = l6;
        _a1_obj->f_id = (size_t) 0;
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
    vader_obj_header_init(_a2_obj, 519u);
    l3 = (void*) _a2_obj;
    vader_struct_toolchain_ast_ImportDecl_t* _a3_obj = (vader_struct_toolchain_ast_ImportDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ImportDecl_t));
    vader_obj_header_init(_a3_obj, 471u);
    _a3_obj->f_span = l2;
    _a3_obj->f_id = (size_t) 0;
    _a3_obj->f_path = l7;
    _a3_obj->f_binding = vader_ref_box(l3);
    _a3_obj->f_decorators = l1;
    t2 = (void*) _a3_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_import_name_list_rest(void* l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    bool l2, l3;
    vader_box_t l5 = vader_box_null();
    vader_string_t l6 = 0;
    int32_t l7;
    bool t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[2] = { &l5, &t1 };
    void** gc_raw_roots[7] = { &l0, &l1, &l4, &l8, &l9, &l10, &t2 };
    vader_string_t* gc_atom_roots[2] = { &l6, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(29u, 0u, 13u, 472u);
    l1 = (void*) _a0_arr;
    l2 = false;
    vader_parser_skip_newlines(l0);
    t0 = vader_parser_check(l0, (uint8_t) 79);
    if (!(t0)) {
        l3 = true;
        for (;;) {
            if (!(l3)) {
                t1 = vader_parser_match_kind(l0, (uint8_t) 80);
                if (t1.tag == 0u) break;
            }
            l3 = false;
            vader_parser_skip_newlines(l0);
            t0 = vader_parser_check(l0, (uint8_t) 79);
            if (t0) {
                l2 = true;
                break;
            }
            l4 = vader_parser_expect(l0, (uint8_t) 2, 1799u);
            l5 = vader_box_obj(0u, NULL);
            t1 = vader_parser_match_kind(l0, (uint8_t) 29);
            if (!(t1.tag == 0u)) {
                t2 = vader_parser_expect(l0, (uint8_t) 2, 1221u);
                t3 = ((vader_struct_vader_lexer_Token_t*) t2)->f_text;
                l5 = vader_box_string(240u, t3);
            }
            l6 = ((vader_struct_vader_lexer_Token_t*) l4)->f_text;
            l7 = -(INT32_C(1));
            l8 = vader_parser_peek_at(l0, l7);
            l9 = vader_parser_span_of(l0, l4, l8);
            vader_struct_toolchain_ast_ImportName_t* _a1_obj = (vader_struct_toolchain_ast_ImportName_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ImportName_t));
            vader_obj_header_init(_a1_obj, 472u);
            _a1_obj->f_name = l6;
            _a1_obj->f_alias = l5;
            _a1_obj->f_span = l9;
            _a1_obj->f_id = (size_t) 0;
            l10 = (void*) _a1_obj;
            vader_array_push((vader_array_t*) l1, vader_ref_box(l10));
            vader_parser_skip_newlines(l0);
            continue;
        }
    }
    vader_parser_skip_newlines(l0);
    vader_parser_expect(l0, (uint8_t) 79, 1156u);
    vader_struct_vader_parser_CommaList__Any_t* _a2_obj = (vader_struct_vader_parser_CommaList__Any_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_CommaList__Any_t));
    vader_obj_header_init(_a2_obj, 973u);
    _a2_obj->f_items = l1;
    _a2_obj->f_trailing_comma = l2;
    t2 = (void*) _a2_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_lambda(void* l0) {
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
    t0 = vader_parser_match_kind(l0, (uint8_t) 70);
    if (!(t0.tag == 0u)) {
        l3 = vader_parser_parse_type(l0);
    }
    l4 = vader_parser_parse_block(l0);
    l1 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l1)->f_span)->f_start;
    l5 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_BlockExpr_t*) l4)->f_span)->f_end;
    vader_struct_toolchain_span_Span_t* _a0_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a0_obj, 524u);
    _a0_obj->f_start = l1;
    _a0_obj->f_end = l5;
    l1 = (void*) _a0_obj;
    l5 = ((vader_struct_vader_parser_FnSignature_t*) l2)->f_params;
    l6 = ((vader_struct_vader_parser_FnSignature_t*) l2)->f_trailing_comma;
    vader_struct_toolchain_ast_LambdaExpr_t* _a1_obj = (vader_struct_toolchain_ast_LambdaExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_LambdaExpr_t));
    vader_obj_header_init(_a1_obj, 479u);
    _a1_obj->f_span = l1;
    _a1_obj->f_id = (size_t) 0;
    _a1_obj->f_params = l5;
    _a1_obj->f_return_type = l3;
    _a1_obj->f_body = l4;
    _a1_obj->f_trailing_comma = l6;
    t1 = (void*) _a1_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_lambda_without_fn(void* l0) {
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
    vader_parser_expect(l0, (uint8_t) 70, 1069u);
    t0 = vader_parser_parse_expr(l0, INT32_C(0));
    l3 = vader_parser_wrap_as_block(t0);
    l1 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l1)->f_span)->f_start;
    l4 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_BlockExpr_t*) l3)->f_span)->f_end;
    vader_struct_toolchain_span_Span_t* _a0_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a0_obj, 524u);
    _a0_obj->f_start = l1;
    _a0_obj->f_end = l4;
    l1 = (void*) _a0_obj;
    l4 = ((vader_struct_vader_parser_FnSignature_t*) l2)->f_params;
    l5 = ((vader_struct_vader_parser_FnSignature_t*) l2)->f_trailing_comma;
    vader_struct_toolchain_ast_LambdaExpr_t* _a1_obj = (vader_struct_toolchain_ast_LambdaExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_LambdaExpr_t));
    vader_obj_header_init(_a1_obj, 479u);
    _a1_obj->f_span = l1;
    _a1_obj->f_id = (size_t) 0;
    _a1_obj->f_params = l4;
    _a1_obj->f_return_type = vader_box_obj(0u, NULL);
    _a1_obj->f_body = l3;
    _a1_obj->f_trailing_comma = l5;
    t1 = (void*) _a1_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_let(void* l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    void* l6 = NULL;
    bool l2;
    vader_box_t l3 = vader_box_null();
    vader_string_t l5 = 0;
    int32_t l7;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[5] = { &l0, &l1, &l4, &l6, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_advance(l0);
    t0 = vader_parser_advance(l0);
    l2 = ((vader_struct_vader_lexer_Token_t*) t0)->f_kind == INT32_C(66);
    l3 = vader_parser_parse_expr(l0, INT32_C(0));
    l4 = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
    l5 = ((vader_struct_vader_lexer_Token_t*) l1)->f_text;
    l6 = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
    vader_struct_toolchain_ast_SimpleBinding_t* _a0_obj = (vader_struct_toolchain_ast_SimpleBinding_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_SimpleBinding_t));
    vader_obj_header_init(_a0_obj, 501u);
    _a0_obj->f_span = l4;
    _a0_obj->f_id = (size_t) 0;
    _a0_obj->f_name = l5;
    _a0_obj->f_name_span = l6;
    l4 = (void*) _a0_obj;
    l7 = -(INT32_C(1));
    l6 = vader_parser_peek_at(l0, l7);
    t0 = vader_parser_span_of(l0, l1, l6);
    vader_struct_toolchain_ast_LetStmt_t* _a1_obj = (vader_struct_toolchain_ast_LetStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_LetStmt_t));
    vader_obj_header_init(_a1_obj, 480u);
    _a1_obj->f_span = t0;
    _a1_obj->f_id = (size_t) 0;
    _a1_obj->f_mutable = l2;
    _a1_obj->f_binding = vader_ref_box(l4);
    _a1_obj->f_ty = vader_box_obj(0u, NULL);
    _a1_obj->f_value = l3;
    t0 = (void*) _a1_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_parser_parse_let_binding(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    vader_string_t l6 = 0;
    vader_box_t l9 = vader_box_null();
    size_t l10, l11, l12, l13;
    bool t0;
    vader_box_t t1 = vader_box_null();
    size_t t2;
    int64_t t3;
    void* t4 = NULL;
    vader_string_t t5 = 0;
    vader_box_t* gc_roots[2] = { &l9, &t1 };
    void** gc_raw_roots[9] = { &l0, &l1, &l2, &l3, &l4, &l5, &l7, &l8, &t4 };
    vader_string_t* gc_atom_roots[2] = { &l6, &t5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_parser_check(l0, (uint8_t) 76);
    if (t0) {
        l1 = vader_parser_advance(l0);
        vader_parser_skip_newlines(l0);
        vader_array_t* _a0_arr = vader_array_new(181u, 0u, 13u, 1298u);
        l2 = (void*) _a0_arr;
        t0 = vader_parser_check(l0, (uint8_t) 77);
        if (!(t0)) {
            for (;;) {
                vader_parser_skip_newlines(l0);
                t0 = vader_parser_check(l0, (uint8_t) 77);
                if (!(t0)) {
                    l3 = vader_parser_peek(l0);
                    t1 = vader_parser_match_kind(l0, (uint8_t) 69);
                    if (t1.tag == 0u) {
                        l9 = vader_parser_parse_let_binding(l0);
                        vader_array_push((vader_array_t*) l2, l9);
                    } else {
                        l4 = vader_parser_expect(l0, (uint8_t) 2, 1996u);
                        l5 = vader_parser_span_of(l0, l3, l4);
                        l6 = ((vader_struct_vader_lexer_Token_t*) l4)->f_text;
                        l7 = ((vader_struct_vader_lexer_Token_t*) l4)->f_span;
                        vader_struct_toolchain_ast_RestBinding_t* _a1_obj = (vader_struct_toolchain_ast_RestBinding_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_RestBinding_t));
                        vader_obj_header_init(_a1_obj, 497u);
                        _a1_obj->f_span = l5;
                        _a1_obj->f_id = (size_t) 0;
                        _a1_obj->f_name = l6;
                        _a1_obj->f_name_span = l7;
                        l8 = (void*) _a1_obj;
                        vader_array_push((vader_array_t*) l2, vader_ref_box(l8));
                    }
                    vader_parser_skip_newlines(l0);
                    t1 = vader_parser_match_kind(l0, (uint8_t) 80);
                    if (t1.tag == 0u) break;
                    vader_parser_skip_newlines(l0);
                    continue;
                }
                break;
            }
        }
        l3 = vader_parser_expect(l0, (uint8_t) 77, 1120u);
        t2 = ((vader_array_t*) l2)->length;
        if ((t2 < INT64_C(2))) {
            l4 = vader_parser_span_of(l0, l1, l3);
            vader_parser_error(l0, (uint8_t) 22, l4, 1182u);
        }
        l10 = (size_t) 1;
        l11 = ((vader_array_t*) l2)->length;
        while ((l10 < l11)) {
            t3 = (l10 - INT64_C(1));
            l12 = (size_t) (int64_t) t3;
            vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l12)
            t1 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l12);
            if (t1.tag == 497u) {
                t3 = (l10 - INT64_C(1));
                l13 = (size_t) (int64_t) t3;
                vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l13)
                t1 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l13);
                l4 = t1.payload.obj;
                l5 = ((vader_struct_toolchain_ast_RestBinding_t*) l4)->f_span;
                vader_parser_error(l0, (uint8_t) 33, l5, 0u);
            }
            t3 = (l10 + INT64_C(1));
            l10 = (size_t) (int64_t) t3;
        }
        t4 = vader_parser_span_of(l0, l1, l3);
        vader_struct_toolchain_ast_TupleBinding_t* _a4_obj = (vader_struct_toolchain_ast_TupleBinding_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_TupleBinding_t));
        vader_obj_header_init(_a4_obj, 513u);
        _a4_obj->f_span = t4;
        _a4_obj->f_id = (size_t) 0;
        _a4_obj->f_elements = l2;
        t4 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t4); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_parser_check(l0, (uint8_t) 2);
    if (t0) {
        t4 = vader_parser_peek(l0);
        t5 = ((vader_struct_vader_lexer_Token_t*) t4)->f_text;
        if (t5 == 793u) {
            t4 = vader_parser_advance(l0);
            vader_struct_toolchain_ast_WildcardBinding_t* _a5_obj = (vader_struct_toolchain_ast_WildcardBinding_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_WildcardBinding_t));
            vader_obj_header_init(_a5_obj, 518u);
            _a5_obj->f_span = ((vader_struct_vader_lexer_Token_t*) t4)->f_span;
            _a5_obj->f_id = (size_t) 0;
            t4 = (void*) _a5_obj;
            { vader_box_t __vret = vader_ref_box(t4); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l1 = vader_parser_expect(l0, (uint8_t) 2, 1313u);
    l2 = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
    l6 = ((vader_struct_vader_lexer_Token_t*) l1)->f_text;
    l1 = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
    vader_struct_toolchain_ast_SimpleBinding_t* _a6_obj = (vader_struct_toolchain_ast_SimpleBinding_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_SimpleBinding_t));
    vader_obj_header_init(_a6_obj, 501u);
    _a6_obj->f_span = l2;
    _a6_obj->f_id = (size_t) 0;
    _a6_obj->f_name = l6;
    _a6_obj->f_name_span = l1;
    t4 = (void*) _a6_obj;
    { vader_box_t __vret = vader_ref_box(t4); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_lhs_generic_alias_decl(void* l0, void* l1, uint8_t l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l7 = NULL;
    vader_box_t l5 = vader_box_null();
    int32_t l6;
    vader_string_t l8 = 0;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[6] = { &l0, &l1, &l3, &l4, &l7, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l8 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
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
    vader_obj_header_init(_a0_obj, 514u);
    _a0_obj->f_span = l7;
    _a0_obj->f_id = (size_t) 0;
    _a0_obj->f_name = l8;
    _a0_obj->f_name_span = l3;
    _a0_obj->f_visibility = l2;
    _a0_obj->f_type_params = l4;
    _a0_obj->f_aliased = l5;
    _a0_obj->f_decorators = l1;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_match_arm(void* l0) {
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
    t0 = vader_parser_check(l0, (uint8_t) 42);
    if (t0) {
        vader_array_t* _a0_arr = vader_array_new(179u, 1u, 13u, 1282u);
        ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l2.payload.obj;
        l4 = (void*) _a0_arr;
        for (;;) {
            t1 = vader_parser_match_kind(l0, (uint8_t) 42);
            if (!(t1.tag == 0u)) {
                vader_parser_skip_newlines(l0);
                l2 = vader_parser_parse_pattern(l0);
                vader_array_push((vader_array_t*) l4, l2);
                continue;
            }
            break;
        }
        l5 = -(INT32_C(1));
        l6 = vader_parser_peek_at(l0, l5);
        t2 = vader_parser_span_of(l0, l1, l6);
        vader_struct_toolchain_ast_OrPattern_t* _a1_obj = (vader_struct_toolchain_ast_OrPattern_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_OrPattern_t));
        vader_obj_header_init(_a1_obj, 490u);
        _a1_obj->f_span = t2;
        _a1_obj->f_id = (size_t) 0;
        _a1_obj->f_patterns = l4;
        t2 = (void*) _a1_obj;
        l3 = vader_ref_box(t2);
    }
    l2 = vader_box_obj(0u, NULL);
    t1 = vader_parser_match_kind(l0, (uint8_t) 16);
    if (!(t1.tag == 0u)) {
        l7 = ((vader_struct_vader_parser_Parser_t*) l0)->f_allow_struct_lit;
        l8 = ((vader_struct_vader_parser_Parser_t*) l0)->f_allow_bare_lambda;
        ((vader_struct_vader_parser_Parser_t*) l0)->f_allow_struct_lit = false;
        ((vader_struct_vader_parser_Parser_t*) l0)->f_allow_bare_lambda = false;
        l2 = vader_parser_parse_expr(l0, INT32_C(0));
        ((vader_struct_vader_parser_Parser_t*) l0)->f_allow_struct_lit = l7;
        ((vader_struct_vader_parser_Parser_t*) l0)->f_allow_bare_lambda = l8;
    }
    vader_parser_expect(l0, (uint8_t) 70, 1070u);
    l9 = vader_parser_parse_expr(l0, INT32_C(0));
    l1 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l1)->f_span)->f_start;
    t2 = l9.payload.obj;
    l4 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t2)->f_span)->f_end;
    vader_struct_toolchain_span_Span_t* _a2_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a2_obj, 524u);
    _a2_obj->f_start = l1;
    _a2_obj->f_end = l4;
    t2 = (void*) _a2_obj;
    vader_struct_toolchain_ast_MatchArm_t* _a3_obj = (vader_struct_toolchain_ast_MatchArm_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_MatchArm_t));
    vader_obj_header_init(_a3_obj, 482u);
    _a3_obj->f_span = t2;
    _a3_obj->f_id = (size_t) 0;
    _a3_obj->f_pattern = l3;
    _a3_obj->f_guard = l2;
    _a3_obj->f_body = l9;
    t2 = (void*) _a3_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_match_expr(void* l0, bool l1, bool l2) {
    void* l3 = NULL;
    void* l7 = NULL;
    void* l9 = NULL;
    bool l4;
    vader_box_t l5 = vader_box_null(), l6 = vader_box_null();
    vader_string_t l8 = 0;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    bool t2;
    vader_box_t* gc_roots[3] = { &l5, &l6, &t0 };
    void** gc_raw_roots[5] = { &l0, &l3, &l7, &l9, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l8 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_parser_advance(l0);
    l4 = ((vader_struct_vader_parser_Parser_t*) l0)->f_allow_struct_lit;
    ((vader_struct_vader_parser_Parser_t*) l0)->f_allow_struct_lit = false;
    l5 = vader_parser_parse_expr(l0, INT32_C(0));
    ((vader_struct_vader_parser_Parser_t*) l0)->f_allow_struct_lit = l4;
    l6 = vader_box_obj(0u, NULL);
    t0 = vader_parser_match_kind(l0, (uint8_t) 29);
    if (!(t0.tag == 0u)) {
        l7 = vader_parser_expect(l0, (uint8_t) 2, 1312u);
        l8 = ((vader_struct_vader_lexer_Token_t*) l7)->f_text;
        l7 = ((vader_struct_vader_lexer_Token_t*) l7)->f_span;
        vader_struct_toolchain_ast_AsBinding_t* _a0_obj = (vader_struct_toolchain_ast_AsBinding_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_AsBinding_t));
        vader_obj_header_init(_a0_obj, 432u);
        _a0_obj->f_name = l8;
        _a0_obj->f_span = l7;
        t1 = (void*) _a0_obj;
        l6 = vader_ref_box(t1);
    }
    vader_parser_expect(l0, (uint8_t) 78, 1149u);
    vader_parser_skip_newlines(l0);
    vader_array_t* _a1_arr = vader_array_new(31u, 0u, 13u, 482u);
    l7 = (void*) _a1_arr;
    for (;;) {
        t2 = vader_parser_check(l0, (uint8_t) 79);
        if (!(t2)) {
            t2 = vader_parser_check(l0, (uint8_t) 0);
            if (t2) break;
            l9 = vader_parser_parse_match_arm(l0);
            vader_array_push((vader_array_t*) l7, vader_ref_box(l9));
            vader_parser_skip_newlines(l0);
            t0 = vader_parser_match_kind(l0, (uint8_t) 80);
            if (t0.tag == 0u) {
                continue;
            }
            vader_parser_skip_newlines(l0);
            continue;
        }
        break;
    }
    l9 = vader_parser_expect(l0, (uint8_t) 79, 1157u);
    l3 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l3)->f_span)->f_start;
    l9 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l9)->f_span)->f_end;
    vader_struct_toolchain_span_Span_t* _a2_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a2_obj, 524u);
    _a2_obj->f_start = l3;
    _a2_obj->f_end = l9;
    t1 = (void*) _a2_obj;
    vader_struct_toolchain_ast_MatchExpr_t* _a3_obj = (vader_struct_toolchain_ast_MatchExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_MatchExpr_t));
    vader_obj_header_init(_a3_obj, 483u);
    _a3_obj->f_span = t1;
    _a3_obj->f_id = (size_t) 0;
    _a3_obj->f_scrutinee = l5;
    _a3_obj->f_arms = l7;
    _a3_obj->f_partial = l1;
    _a3_obj->f_unreachable = l2;
    _a3_obj->f_bind_as = l6;
    t1 = (void*) _a3_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_parser_parse_module_header(vader_string_t l0, vader_string_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l5, l10, l11, l12;
    uint8_t l6;
    bool l7, l8, l9;
    vader_string_t l13 = 0;
    vader_box_t t0 = vader_box_null();
    uint8_t t1;
    int64_t t2;
    void* t3 = NULL;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l2, &t3 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l1, &l13 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_host_std_core_bytes(l0);
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    if ((l3 >= INT64_C(3))) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
        t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) INT32_C(0), 246u);
        t1 = ((uint8_t) t0.payload.i);
        if (t1 == INT32_C(239)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(1))
            t0 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) INT32_C(1), 246u);
            t1 = ((uint8_t) t0.payload.i);
            if (t1 == INT32_C(187)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(2))
                t0 = vader_array_read_u8(_a2_slotarr, _a2_slotarr->offset + (size_t) INT32_C(2), 246u);
                t1 = ((uint8_t) t0.payload.i);
                if (t1 == INT32_C(191)) {
                    l4 = (size_t) 3;
                }
            }
        }
    }
    if (((l4 + INT64_C(1)) < l3)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
        t0 = vader_array_read_u8(_a3_slotarr, _a3_slotarr->offset + (size_t) l4, 246u);
        t1 = ((uint8_t) t0.payload.i);
        if (t1 == INT32_C(35)) {
            t2 = (l4 + INT64_C(1));
            l5 = (size_t) (int64_t) t2;
            vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
            t0 = vader_array_read_u8(_a4_slotarr, _a4_slotarr->offset + (size_t) l5, 246u);
            t1 = ((uint8_t) t0.payload.i);
            if (t1 == INT32_C(33)) {
                l4 = vader_parser_skip_to_eol(l2, l4, l3);
            }
        }
    }
    l5 = vader_parser_header_budget(l3);
    while ((l4 < l5)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
        t0 = vader_array_read_u8(_a5_slotarr, _a5_slotarr->offset + (size_t) l4, 246u);
        l6 = ((uint8_t) t0.payload.i);
        if (l6 == INT32_C(32)) {
            l7 = true;
        } else {
            l7 = l6 == INT32_C(9);
        }
        if (l7) {
            l8 = true;
        } else {
            l8 = l6 == INT32_C(10);
        }
        if (l8) {
            l9 = true;
        } else {
            l9 = l6 == INT32_C(13);
        }
        if (l9) {
            t2 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t2;
            continue;
        }
        if (l6 == INT32_C(47)) {
            if (((l4 + INT64_C(1)) < l3)) {
                t2 = (l4 + INT64_C(1));
                l10 = (size_t) (int64_t) t2;
                vader_array_t* _a6_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l10)
                t0 = vader_array_read_u8(_a6_slotarr, _a6_slotarr->offset + (size_t) l10, 246u);
                t1 = ((uint8_t) t0.payload.i);
                if (t1 == INT32_C(47)) {
                    l4 = vader_parser_skip_to_eol(l2, l4, l3);
                    continue;
                }
            }
        }
        if (!(l6 == INT32_C(47))) {
            break;
        }
        if (!(((l4 + INT64_C(1)) < l3))) {
            break;
        }
        t2 = (l4 + INT64_C(1));
        l11 = (size_t) (int64_t) t2;
        vader_array_t* _a7_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l11)
        t0 = vader_array_read_u8(_a7_slotarr, _a7_slotarr->offset + (size_t) l11, 246u);
        t1 = ((uint8_t) t0.payload.i);
        if (!(t1 == INT32_C(42))) {
            break;
        }
        t2 = (l4 + INT64_C(2));
        l12 = (size_t) (int64_t) t2;
        l4 = vader_parser_skip_block_comment(l2, l12, l3);
    }
    if (((l4 + INT64_C(7)) > l3)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    vader_array_t* _a8_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l4)
    t0 = vader_array_read_u8(_a8_slotarr, _a8_slotarr->offset + (size_t) l4, 246u);
    t1 = ((uint8_t) t0.payload.i);
    if (t1 != INT32_C(109)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t2 = (l4 + INT64_C(1));
    l5 = (size_t) (int64_t) t2;
    vader_array_t* _a9_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l5)
    t0 = vader_array_read_u8(_a9_slotarr, _a9_slotarr->offset + (size_t) l5, 246u);
    t1 = ((uint8_t) t0.payload.i);
    if (t1 != INT32_C(111)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t2 = (l4 + INT64_C(2));
    l5 = (size_t) (int64_t) t2;
    vader_array_t* _a10_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l5)
    t0 = vader_array_read_u8(_a10_slotarr, _a10_slotarr->offset + (size_t) l5, 246u);
    t1 = ((uint8_t) t0.payload.i);
    if (t1 != INT32_C(100)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t2 = (l4 + INT64_C(3));
    l5 = (size_t) (int64_t) t2;
    vader_array_t* _a11_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l5)
    t0 = vader_array_read_u8(_a11_slotarr, _a11_slotarr->offset + (size_t) l5, 246u);
    t1 = ((uint8_t) t0.payload.i);
    if (t1 != INT32_C(117)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t2 = (l4 + INT64_C(4));
    l5 = (size_t) (int64_t) t2;
    vader_array_t* _a12_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l5)
    t0 = vader_array_read_u8(_a12_slotarr, _a12_slotarr->offset + (size_t) l5, 246u);
    t1 = ((uint8_t) t0.payload.i);
    if (t1 != INT32_C(108)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t2 = (l4 + INT64_C(5));
    l5 = (size_t) (int64_t) t2;
    vader_array_t* _a13_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l5)
    t0 = vader_array_read_u8(_a13_slotarr, _a13_slotarr->offset + (size_t) l5, 246u);
    t1 = ((uint8_t) t0.payload.i);
    if (t1 != INT32_C(101)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t2 = (l4 + INT64_C(6));
    l4 = (size_t) (int64_t) t2;
    while ((l4 < l3)) {
        vader_array_t* _a14_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l4)
        t0 = vader_array_read_u8(_a14_slotarr, _a14_slotarr->offset + (size_t) l4, 246u);
        l6 = ((uint8_t) t0.payload.i);
        if (l6 == INT32_C(32)) {
            l7 = true;
        } else {
            l7 = l6 == INT32_C(9);
        }
        if (!(l7)) {
            break;
        }
        t2 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t2;
    }
    if ((l4 >= l3)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    vader_array_t* _a15_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l4)
    t0 = vader_array_read_u8(_a15_slotarr, _a15_slotarr->offset + (size_t) l4, 246u);
    t1 = ((uint8_t) t0.payload.i);
    if (t1 != INT32_C(34)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t2 = (l4 + INT64_C(1));
    l4 = (size_t) (int64_t) t2;
    l5 = l4;
    while ((l4 < l3)) {
        vader_array_t* _a16_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l4)
        t0 = vader_array_read_u8(_a16_slotarr, _a16_slotarr->offset + (size_t) l4, 246u);
        t1 = ((uint8_t) t0.payload.i);
        if (!(t1 != INT32_C(34))) {
            break;
        }
        t2 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t2;
    }
    if (!((l4 >= l3))) {
        vader_array_t* _a17_arr = vader_array_slice((vader_array_t*) l2, (size_t) l5, (size_t) l4);
        t3 = (void*) _a17_arr;
        l13 = vader_host_std_core_bytes_to_string(t3);
        l2 = vader_lexer_empty_file_span(l1);
        vader_struct_vader_parser_ModuleHeader_t* _a18_obj = (vader_struct_vader_parser_ModuleHeader_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_ModuleHeader_t));
        vader_obj_header_init(_a18_obj, 982u);
        _a18_obj->f_name = l13;
        _a18_obj->f_name_span = l2;
        t3 = (void*) _a18_obj;
        { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_parser_parse_named_decl(void* l0, void* l1, uint8_t l2) {
    void* l3 = NULL;
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_parser_advance(l0);
    vader_parser_advance(l0);
    t0 = vader_parser_check(l0, (uint8_t) 11);
    if (t0) {
        t1 = vader_parser_parse_fn_decl(l0, l1, l2, l3);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_parser_check(l0, (uint8_t) 12);
    if (t0) {
        t1 = vader_parser_parse_struct_decl(l0, l1, l2, l3);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_parser_check(l0, (uint8_t) 15);
    if (t0) {
        t1 = vader_parser_parse_enum_decl(l0, l1, l2, l3);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_parser_check(l0, (uint8_t) 13);
    if (t0) {
        t1 = vader_parser_parse_trait_decl(l0, l1, l2, l3);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_parser_check(l0, (uint8_t) 28);
    if (!(t0)) {
        t1 = vader_parser_parse_const_decl(l0, l1, l2, l3);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_parser_parse_named_import_decl(l0, l1, l3);
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_named_import_decl(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l5 = NULL;
    vader_box_t l4 = vader_box_null();
    int32_t l6;
    vader_string_t l7 = 0;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l5, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l7, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_parser_advance(l0);
    l3 = vader_parser_expect_string_literal(l0, 1796u);
    l4 = vader_parser_match_kind(l0, (uint8_t) 78);
    if (!(l4.tag == 0u)) {
        t0 = l4.payload.obj;
        l5 = ((vader_struct_vader_lexer_Token_t*) t0)->f_span;
        vader_parser_error(l0, (uint8_t) 5, l5, 2311u);
        vader_parser_parse_import_name_list_rest(l0);
    }
    l6 = -(INT32_C(1));
    l5 = vader_parser_peek_at(l0, l6);
    l5 = vader_parser_span_of(l0, l2, l5);
    l7 = ((vader_struct_vader_parser_StringLitInfo_t*) l3)->f_text;
    t1 = ((vader_struct_vader_lexer_Token_t*) l2)->f_text;
    vader_struct_toolchain_ast_NamedNamespaceImport_t* _a0_obj = (vader_struct_toolchain_ast_NamedNamespaceImport_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_NamedNamespaceImport_t));
    vader_obj_header_init(_a0_obj, 486u);
    _a0_obj->f_name = t1;
    l3 = (void*) _a0_obj;
    vader_struct_toolchain_ast_ImportDecl_t* _a1_obj = (vader_struct_toolchain_ast_ImportDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ImportDecl_t));
    vader_obj_header_init(_a1_obj, 471u);
    _a1_obj->f_span = l5;
    _a1_obj->f_id = (size_t) 0;
    _a1_obj->f_path = l7;
    _a1_obj->f_binding = vader_ref_box(l3);
    _a1_obj->f_decorators = l1;
    t0 = (void*) _a1_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_parser_parse_optional_module_decl(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    int32_t l4;
    vader_string_t l5 = 0;
    vader_string_t t0 = 0;
    bool t1;
    void* t2 = NULL;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t2 };
    vader_string_t* gc_atom_roots[2] = { &l5, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_peek(l0);
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind != INT32_C(2)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t0 = ((vader_struct_vader_lexer_Token_t*) l1)->f_text;
    if (t0 != 1986u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t1 = vader_parser_check_at(l0, (uint8_t) 6, INT32_C(1));
    if (!(t1)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l1 = vader_parser_advance(l0);
    l2 = vader_parser_expect_string_literal(l0, 1991u);
    t0 = ((vader_struct_vader_parser_StringLitInfo_t*) l2)->f_text;
    t1 = vader_parser_is_valid_module_name(t0);
    if (!(t1)) {
        l3 = ((vader_struct_vader_parser_StringLitInfo_t*) l2)->f_span;
        vader_parser_error(l0, (uint8_t) 24, l3, 0u);
    }
    l4 = -(INT32_C(1));
    l3 = vader_parser_peek_at(l0, l4);
    l1 = vader_parser_span_of(l0, l1, l3);
    l5 = ((vader_struct_vader_parser_StringLitInfo_t*) l2)->f_text;
    l2 = ((vader_struct_vader_parser_StringLitInfo_t*) l2)->f_span;
    vader_struct_toolchain_ast_ModuleDecl_t* _a0_obj = (vader_struct_toolchain_ast_ModuleDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ModuleDecl_t));
    vader_obj_header_init(_a0_obj, 484u);
    _a0_obj->f_span = l1;
    _a0_obj->f_id = (size_t) 0;
    _a0_obj->f_name = l5;
    _a0_obj->f_name_span = l2;
    t2 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_parser_parse_paren(void* l0) {
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
    ((vader_struct_vader_parser_Parser_t*) l0)->f_allow_bare_lambda = true;
    l3 = vader_parser_parse_expr(l0, INT32_C(0));
    ((vader_struct_vader_parser_Parser_t*) l0)->f_allow_struct_lit = l1;
    ((vader_struct_vader_parser_Parser_t*) l0)->f_allow_bare_lambda = l2;
    vader_parser_skip_newlines(l0);
    vader_parser_expect(l0, (uint8_t) 75, 1053u);
    { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_parser_parse_pattern(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    vader_string_t l5 = 0;
    vader_box_t l6 = vader_box_null(), l7 = vader_box_null();
    int32_t l8, l10;
    bool l9;
    void* t0 = NULL;
    bool t1;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[2] = { &l6, &l7 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l4, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l5, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_peek(l0);
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(81)) {
        vader_parser_advance(l0);
        l2 = vader_parser_expect(l0, (uint8_t) 2, 2577u);
        l3 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l1)->f_span)->f_start;
        l4 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l2)->f_span)->f_end;
        vader_struct_toolchain_span_Span_t* _a0_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
        vader_obj_header_init(_a0_obj, 524u);
        _a0_obj->f_start = l3;
        _a0_obj->f_end = l4;
        l3 = (void*) _a0_obj;
        l5 = ((vader_struct_vader_lexer_Token_t*) l2)->f_text;
        vader_struct_toolchain_ast_EnumVariantPattern_t* _a1_obj = (vader_struct_toolchain_ast_EnumVariantPattern_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_EnumVariantPattern_t));
        vader_obj_header_init(_a1_obj, 457u);
        _a1_obj->f_span = l3;
        _a1_obj->f_id = (size_t) 0;
        _a1_obj->f_variant = l5;
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(19)) {
        vader_parser_advance(l0);
        t1 = vader_parser_check(l0, (uint8_t) 81);
        if (t1) {
            l2 = vader_parser_advance(l0);
            l3 = vader_parser_expect(l0, (uint8_t) 2, 2577u);
            l2 = vader_parser_span_of(l0, l2, l3);
            l5 = ((vader_struct_vader_lexer_Token_t*) l3)->f_text;
            vader_struct_toolchain_ast_IdentExpr_t* _a2_obj = (vader_struct_toolchain_ast_IdentExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_IdentExpr_t));
            vader_obj_header_init(_a2_obj, 466u);
            _a2_obj->f_span = l2;
            _a2_obj->f_id = (size_t) 0;
            _a2_obj->f_name = l5;
            _a2_obj->f_implicit_dot = true;
            _a2_obj->f_is_type_param_intro = false;
            t0 = (void*) _a2_obj;
            l6 = vader_ref_box(t0);
        } else {
            l6 = vader_parser_parse_type(l0);
        }
        l7 = vader_box_obj(0u, NULL);
        t1 = vader_parser_check(l0, (uint8_t) 78);
        if (t1) {
            t0 = vader_parser_parse_struct_pattern(l0);
            l7 = vader_ref_box(t0);
        }
        vader_parser_reject_arm_binding(l0);
        l8 = -(INT32_C(1));
        l2 = vader_parser_peek_at(l0, l8);
        t0 = vader_parser_span_of(l0, l1, l2);
        vader_struct_toolchain_ast_IsPattern_t* _a3_obj = (vader_struct_toolchain_ast_IsPattern_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_IsPattern_t));
        vader_obj_header_init(_a3_obj, 478u);
        _a3_obj->f_span = t0;
        _a3_obj->f_id = (size_t) 0;
        _a3_obj->f_ty = l6;
        _a3_obj->f_inner = l7;
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(2)) {
        t2 = ((vader_struct_vader_lexer_Token_t*) l1)->f_text;
        if (t2 == 793u) {
            vader_parser_advance(l0);
            vader_struct_toolchain_ast_WildcardPattern_t* _a4_obj = (vader_struct_toolchain_ast_WildcardPattern_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_WildcardPattern_t));
            vader_obj_header_init(_a4_obj, 520u);
            _a4_obj->f_span = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
            _a4_obj->f_id = (size_t) 0;
            t0 = (void*) _a4_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(2)) {
        vader_parser_advance(l0);
        l2 = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
        l5 = ((vader_struct_vader_lexer_Token_t*) l1)->f_text;
        l5 = concat_3(2607u, l5, 850u);
        vader_parser_error(l0, (uint8_t) 32, l2, l5);
        vader_struct_toolchain_ast_WildcardPattern_t* _a5_obj = (vader_struct_toolchain_ast_WildcardPattern_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_WildcardPattern_t));
        vader_obj_header_init(_a5_obj, 520u);
        _a5_obj->f_span = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
        _a5_obj->f_id = (size_t) 0;
        t0 = (void*) _a5_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(76)) {
        t0 = vader_parser_reject_tuple_pattern(l0);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_parser_is_literal_start(l1);
    if (!(t1)) {
        l4 = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
        l5 = vader_parser_describe_token(l1);
        l5 = concat_2(1720u, l5);
        vader_parser_error(l0, (uint8_t) 6, l4, l5);
        vader_parser_advance(l0);
        vader_struct_toolchain_ast_WildcardPattern_t* _a6_obj = (vader_struct_toolchain_ast_WildcardPattern_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_WildcardPattern_t));
        vader_obj_header_init(_a6_obj, 520u);
        _a6_obj->f_span = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
        _a6_obj->f_id = (size_t) 0;
        t0 = (void*) _a6_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = vader_parser_parse_prefix(l0);
    t1 = vader_parser_check(l0, (uint8_t) 68);
    if (t1) {
        l9 = true;
    } else {
        l9 = vader_parser_check(l0, (uint8_t) 67);
    }
    if (!(l9)) {
        l10 = -(INT32_C(1));
        l3 = vader_parser_peek_at(l0, l10);
        t0 = vader_parser_span_of(l0, l1, l3);
        vader_struct_toolchain_ast_LiteralPattern_t* _a7_obj = (vader_struct_toolchain_ast_LiteralPattern_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_LiteralPattern_t));
        vader_obj_header_init(_a7_obj, 481u);
        _a7_obj->f_span = t0;
        _a7_obj->f_id = (size_t) 0;
        _a7_obj->f_value = l6;
        t0 = (void*) _a7_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l9 = vader_parser_check(l0, (uint8_t) 68);
    vader_parser_advance(l0);
    l7 = vader_parser_parse_prefix(l0);
    l8 = -(INT32_C(1));
    l2 = vader_parser_peek_at(l0, l8);
    t0 = vader_parser_span_of(l0, l1, l2);
    vader_struct_toolchain_ast_RangePattern_t* _a8_obj = (vader_struct_toolchain_ast_RangePattern_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_RangePattern_t));
    vader_obj_header_init(_a8_obj, 496u);
    _a8_obj->f_span = t0;
    _a8_obj->f_id = (size_t) 0;
    _a8_obj->f_inclusive = l9;
    _a8_obj->f_lower = l6;
    _a8_obj->f_upper = l7;
    t0 = (void*) _a8_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_parser_parse_postfix(void* l0, vader_box_t l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l8 = NULL;
    vader_string_t l6 = 0;
    int32_t l7;
    bool l9;
    vader_box_t l10 = vader_box_null();
    bool t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l10 };
    void** gc_raw_roots[7] = { &l0, &l2, &l3, &l4, &l5, &l8, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (((vader_struct_vader_lexer_Token_t*) l2)->f_kind == INT32_C(81)) {
        vader_parser_advance(l0);
        t0 = vader_parser_check(l0, (uint8_t) 3);
        if (t0) {
            l3 = vader_parser_advance(l0);
            t1 = l1.payload.obj;
            l4 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_span)->f_start;
            l5 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l3)->f_span)->f_end;
            vader_struct_toolchain_span_Span_t* _a0_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
            vader_obj_header_init(_a0_obj, 524u);
            _a0_obj->f_start = l4;
            _a0_obj->f_end = l5;
            l4 = (void*) _a0_obj;
            l6 = ((vader_struct_vader_lexer_Token_t*) l3)->f_text;
            l3 = ((vader_struct_vader_lexer_Token_t*) l3)->f_span;
            vader_struct_toolchain_ast_FieldExpr_t* _a1_obj = (vader_struct_toolchain_ast_FieldExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FieldExpr_t));
            vader_obj_header_init(_a1_obj, 459u);
            _a1_obj->f_span = l4;
            _a1_obj->f_id = (size_t) 0;
            _a1_obj->f_target = l1;
            _a1_obj->f_field = l6;
            _a1_obj->f_field_span = l3;
            _a1_obj->f_is_numeric = true;
            t1 = (void*) _a1_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l3 = vader_parser_expect(l0, (uint8_t) 2, 1650u);
        t1 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_span)->f_start;
        l5 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l3)->f_span)->f_end;
        vader_struct_toolchain_span_Span_t* _a2_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
        vader_obj_header_init(_a2_obj, 524u);
        _a2_obj->f_start = l4;
        _a2_obj->f_end = l5;
        l4 = (void*) _a2_obj;
        l6 = ((vader_struct_vader_lexer_Token_t*) l3)->f_text;
        l3 = ((vader_struct_vader_lexer_Token_t*) l3)->f_span;
        vader_struct_toolchain_ast_FieldExpr_t* _a3_obj = (vader_struct_toolchain_ast_FieldExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FieldExpr_t));
        vader_obj_header_init(_a3_obj, 459u);
        _a3_obj->f_span = l4;
        _a3_obj->f_id = (size_t) 0;
        _a3_obj->f_target = l1;
        _a3_obj->f_field = l6;
        _a3_obj->f_field_span = l3;
        _a3_obj->f_is_numeric = false;
        l3 = (void*) _a3_obj;
        t0 = ((vader_struct_vader_parser_Parser_t*) l0)->f_allow_struct_lit;
        if (t0) {
            t0 = vader_parser_check(l0, (uint8_t) 78);
            if (t0) {
                l4 = ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens;
                l7 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pos;
                t0 = vader_parser_looks_like_struct_lit_body(l4, l7);
                if (t0) {
                    vader_parser_advance(l0);
                    l4 = vader_parser_parse_struct_lit_fields(l0);
                    l5 = vader_parser_expect(l0, (uint8_t) 79, 1159u);
                    t1 = l1.payload.obj;
                    l8 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_span)->f_start;
                    l5 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l5)->f_span)->f_end;
                    vader_struct_toolchain_span_Span_t* _a4_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
                    vader_obj_header_init(_a4_obj, 524u);
                    _a4_obj->f_start = l8;
                    _a4_obj->f_end = l5;
                    l5 = (void*) _a4_obj;
                    l8 = ((vader_struct_vader_parser_CommaList__StructLitField___StructLitSpread_t*) l4)->f_items;
                    l9 = ((vader_struct_vader_parser_CommaList__StructLitField___StructLitSpread_t*) l4)->f_trailing_comma;
                    vader_struct_toolchain_ast_StructLitExpr_t* _a5_obj = (vader_struct_toolchain_ast_StructLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_StructLitExpr_t));
                    vader_obj_header_init(_a5_obj, 507u);
                    _a5_obj->f_span = l5;
                    _a5_obj->f_id = (size_t) 0;
                    _a5_obj->f_type_name = vader_ref_box(l3);
                    _a5_obj->f_items = l8;
                    _a5_obj->f_trailing_comma = l9;
                    t1 = (void*) _a5_obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                { vader_box_t __vret = vader_ref_box(l3); vader_gc_top = gc_frame.prev; return __vret; }
            }
            { vader_box_t __vret = vader_ref_box(l3); vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_box_t __vret = vader_ref_box(l3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l2)->f_kind == INT32_C(74)) {
        vader_parser_advance(l0);
        l3 = vader_parser_parse_call_args(l0);
        vader_parser_expect(l0, (uint8_t) 75, 1051u);
        t1 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_span)->f_start;
        l7 = -(INT32_C(1));
        t1 = vader_parser_peek_at(l0, l7);
        l5 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) t1)->f_span)->f_end;
        vader_struct_toolchain_span_Span_t* _a6_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
        vader_obj_header_init(_a6_obj, 524u);
        _a6_obj->f_start = l4;
        _a6_obj->f_end = l5;
        l4 = (void*) _a6_obj;
        l5 = ((vader_struct_vader_parser_CommaList__CallArg_t*) l3)->f_items;
        l9 = ((vader_struct_vader_parser_CommaList__CallArg_t*) l3)->f_trailing_comma;
        vader_struct_toolchain_ast_CallExpr_t* _a7_obj = (vader_struct_toolchain_ast_CallExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_CallExpr_t));
        vader_obj_header_init(_a7_obj, 441u);
        _a7_obj->f_span = l4;
        _a7_obj->f_id = (size_t) 0;
        _a7_obj->f_callee = l1;
        _a7_obj->f_args = l5;
        _a7_obj->f_trailing_comma = l9;
        t1 = (void*) _a7_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_parser_check_at(l0, (uint8_t) 77, INT32_C(1));
    if (!(t0)) {
        vader_parser_advance(l0);
        l10 = vader_parser_parse_expr(l0, INT32_C(0));
        vader_parser_expect(l0, (uint8_t) 77, 1122u);
        t1 = l1.payload.obj;
        l5 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_span)->f_start;
        l7 = -(INT32_C(1));
        t1 = vader_parser_peek_at(l0, l7);
        l8 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) t1)->f_span)->f_end;
        vader_struct_toolchain_span_Span_t* _a8_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
        vader_obj_header_init(_a8_obj, 524u);
        _a8_obj->f_start = l5;
        _a8_obj->f_end = l8;
        t1 = (void*) _a8_obj;
        vader_struct_toolchain_ast_IndexExpr_t* _a9_obj = (vader_struct_toolchain_ast_IndexExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_IndexExpr_t));
        vader_obj_header_init(_a9_obj, 474u);
        _a9_obj->f_span = t1;
        _a9_obj->f_id = (size_t) 0;
        _a9_obj->f_target = l1;
        _a9_obj->f_index = l10;
        t1 = (void*) _a9_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_parser_advance(l0);
    l3 = vader_parser_advance(l0);
    t1 = l1.payload.obj;
    l4 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_span)->f_start;
    l3 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l3)->f_span)->f_end;
    vader_struct_toolchain_span_Span_t* _a10_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a10_obj, 524u);
    _a10_obj->f_start = l4;
    _a10_obj->f_end = l3;
    t1 = (void*) _a10_obj;
    vader_struct_toolchain_ast_ArrayTypeExpr_t* _a11_obj = (vader_struct_toolchain_ast_ArrayTypeExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ArrayTypeExpr_t));
    vader_obj_header_init(_a11_obj, 431u);
    _a11_obj->f_span = t1;
    _a11_obj->f_id = (size_t) 0;
    _a11_obj->f_element = l1;
    t1 = (void*) _a11_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_parser_parse_prefix(void* l0) {
    void* l1 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l17 = NULL;
    uint64_t l2;
    vader_box_t l3 = vader_box_null(), l15 = vader_box_null(), l16 = vader_box_null();
    double l4;
    uint32_t l5;
    bool l6, l12;
    uint8_t l7;
    vader_string_t l11 = 0;
    vader_string_t l18 = 0;
    size_t l13, l14;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    bool t2;
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[4] = { &l3, &l15, &l16, &t1 };
    void** gc_raw_roots[7] = { &l0, &l1, &l8, &l9, &l10, &l17, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l11, &l18, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_peek(l0);
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(3)) {
        vader_parser_advance(l0);
        l2 = (uint64_t) 0;
        l3 = ((vader_struct_vader_lexer_Token_t*) l1)->f_value;
        if (l3.tag == 249u) {
            l2 = ((uint64_t) l3.payload.i);
        }
        vader_struct_toolchain_ast_IntLitExpr_t* _a0_obj = (vader_struct_toolchain_ast_IntLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_IntLitExpr_t));
        vader_obj_header_init(_a0_obj, 476u);
        _a0_obj->f_span = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
        _a0_obj->f_id = (size_t) 0;
        _a0_obj->f_value = l2;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(4)) {
        vader_parser_advance(l0);
        l4 = 0.0;
        l3 = ((vader_struct_vader_lexer_Token_t*) l1)->f_value;
        if ((l3.tag == 236u || l3.tag == 237u)) {
            l4 = ((double) l3.payload.f);
        }
        vader_struct_toolchain_ast_FloatLitExpr_t* _a1_obj = (vader_struct_toolchain_ast_FloatLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FloatLitExpr_t));
        vader_obj_header_init(_a1_obj, 460u);
        _a1_obj->f_span = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
        _a1_obj->f_id = (size_t) 0;
        _a1_obj->f_value = l4;
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(5)) {
        vader_parser_advance(l0);
        l5 = (uint32_t) 0;
        l3 = ((vader_struct_vader_lexer_Token_t*) l1)->f_value;
        if (l3.tag == 248u) {
            l5 = ((uint32_t) l3.payload.i);
        }
        vader_struct_toolchain_ast_CharLitExpr_t* _a2_obj = (vader_struct_toolchain_ast_CharLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_CharLitExpr_t));
        vader_obj_header_init(_a2_obj, 443u);
        _a2_obj->f_span = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
        _a2_obj->f_id = (size_t) 0;
        _a2_obj->f_value = l5;
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(31)) {
        vader_parser_advance(l0);
        vader_struct_toolchain_ast_BoolLitExpr_t* _a3_obj = (vader_struct_toolchain_ast_BoolLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BoolLitExpr_t));
        vader_obj_header_init(_a3_obj, 438u);
        _a3_obj->f_span = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
        _a3_obj->f_id = (size_t) 0;
        _a3_obj->f_value = true;
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(32)) {
        vader_parser_advance(l0);
        vader_struct_toolchain_ast_BoolLitExpr_t* _a4_obj = (vader_struct_toolchain_ast_BoolLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BoolLitExpr_t));
        vader_obj_header_init(_a4_obj, 438u);
        _a4_obj->f_span = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
        _a4_obj->f_id = (size_t) 0;
        _a4_obj->f_value = false;
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(33)) {
        vader_parser_advance(l0);
        vader_struct_toolchain_ast_NullLitExpr_t* _a5_obj = (vader_struct_toolchain_ast_NullLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_NullLitExpr_t));
        vader_obj_header_init(_a5_obj, 489u);
        _a5_obj->f_span = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
        _a5_obj->f_id = (size_t) 0;
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
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(74)) {
        t2 = ((vader_struct_vader_parser_Parser_t*) l0)->f_allow_bare_lambda;
        if (t2) {
            t2 = vader_parser_peek_lambda_without_fn(l0);
            if (t2) {
                t0 = vader_parser_parse_lambda_without_fn(l0);
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t1 = vader_parser_parse_paren(l0);
            { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t1 = vader_parser_parse_paren(l0);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(76)) {
        t0 = vader_parser_parse_seq_lit(l0);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(78)) {
        t0 = vader_parser_parse_block(l0);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(37)) {
        l6 = true;
    } else {
        l6 = ((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(57);
    }
    if (l6) {
        l6 = true;
    } else {
        l6 = ((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(44);
    }
    if (l6) {
        vader_parser_advance(l0);
        l7 = (uint8_t) 0;
        if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(57)) {
            l7 = (uint8_t) 1;
        }
        if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(44)) {
            l7 = (uint8_t) 2;
        }
        l3 = vader_parser_parse_expr(l0, INT32_C(95));
        l8 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l1)->f_span)->f_start;
        t0 = l3.payload.obj;
        l9 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t0)->f_span)->f_end;
        vader_struct_toolchain_span_Span_t* _a6_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
        vader_obj_header_init(_a6_obj, 524u);
        _a6_obj->f_start = l8;
        _a6_obj->f_end = l9;
        t0 = (void*) _a6_obj;
        vader_struct_toolchain_ast_UnaryExpr_t* _a7_obj = (vader_struct_toolchain_ast_UnaryExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_UnaryExpr_t));
        vader_obj_header_init(_a7_obj, 516u);
        _a7_obj->f_span = t0;
        _a7_obj->f_id = (size_t) 0;
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
        vader_obj_header_init(_a8_obj, 524u);
        _a8_obj->f_start = l8;
        _a8_obj->f_end = l9;
        t0 = (void*) _a8_obj;
        vader_struct_toolchain_ast_AwaitExpr_t* _a9_obj = (vader_struct_toolchain_ast_AwaitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_AwaitExpr_t));
        vader_obj_header_init(_a9_obj, 435u);
        _a9_obj->f_span = t0;
        _a9_obj->f_id = (size_t) 0;
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
        t0 = vader_parser_ident_expr(((vader_struct_vader_lexer_Token_t*) l1)->f_span, 2149u);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(72)) {
        l8 = vader_parser_advance(l0);
        l9 = vader_parser_expect(l0, (uint8_t) 2, 1498u);
        t3 = ((vader_struct_vader_lexer_Token_t*) l9)->f_text;
        if (t3 == 2070u) {
            l6 = true;
        } else {
            t3 = ((vader_struct_vader_lexer_Token_t*) l9)->f_text;
            l6 = t3 == 2423u;
        }
        if (l6) {
            t2 = vader_parser_check(l0, (uint8_t) 18);
            if (!(t2)) {
                l10 = ((vader_struct_vader_lexer_Token_t*) l9)->f_span;
                l11 = ((vader_struct_vader_lexer_Token_t*) l9)->f_text;
                l11 = concat_3(1091u, l11, 968u);
                vader_parser_error(l0, (uint8_t) 13, l10, l11);
            }
            t3 = ((vader_struct_vader_lexer_Token_t*) l9)->f_text;
            l6 = t3 == 2070u;
            t3 = ((vader_struct_vader_lexer_Token_t*) l9)->f_text;
            l12 = t3 == 2423u;
            t0 = vader_parser_parse_match_expr(l0, l6, l12);
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t3 = ((vader_struct_vader_lexer_Token_t*) l9)->f_text;
        l3 = vader_parser_intrinsic_spec(t3);
        if (l3.tag == 0u) {
            l10 = vader_parser_span_of(l0, l8, l9);
            l11 = ((vader_struct_vader_lexer_Token_t*) l9)->f_text;
            l11 = concat_3(1091u, l11, 951u);
            vader_parser_error(l0, (uint8_t) 13, l10, l11);
            t2 = vader_parser_check(l0, (uint8_t) 74);
            if (t2) {
                vader_parser_advance(l0);
                for (;;) {
                    t2 = vader_parser_check(l0, (uint8_t) 75);
                    if (!(t2)) {
                        t2 = vader_parser_check(l0, (uint8_t) 0);
                        if (t2) break;
                        vader_parser_advance(l0);
                        continue;
                    }
                    break;
                }
                t2 = vader_parser_check(l0, (uint8_t) 75);
                if (t2) {
                    vader_parser_advance(l0);
                }
            }
            t0 = vader_parser_span_of(l0, l8, l9);
            vader_struct_toolchain_ast_NullLitExpr_t* _a10_obj = (vader_struct_toolchain_ast_NullLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_NullLitExpr_t));
            vader_obj_header_init(_a10_obj, 489u);
            _a10_obj->f_span = t0;
            _a10_obj->f_id = (size_t) 0;
            t0 = (void*) _a10_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (!(l3.tag == 981u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = l3.payload.obj;
        l11 = ((vader_struct_vader_parser_IntrinsicSpec_t*) t0)->f_name;
        l11 = concat_3(1040u, l11, 850u);
        vader_parser_expect(l0, (uint8_t) 74, l11);
        vader_array_t* _a11_arr = vader_array_new(175u, 0u, 13u, 1241u);
        l10 = (void*) _a11_arr;
        vader_parser_skip_newlines(l0);
        l6 = false;
        t2 = vader_parser_check(l0, (uint8_t) 75);
        if (!(t2)) {
            for (;;) {
                vader_parser_skip_newlines(l0);
                t2 = vader_parser_check(l0, (uint8_t) 75);
                if (!(t2)) {
                    l13 = ((vader_array_t*) l10)->length;
                    l12 = false;
                    t0 = l3.payload.obj;
                    l14 = ((vader_array_t*) ((vader_struct_vader_parser_IntrinsicSpec_t*) t0)->f_args)->length;
                    if ((l13 < l14)) {
                        t0 = l3.payload.obj;
                        vader_array_t* _a12_slotarr = ((vader_array_t*) ((vader_struct_vader_parser_IntrinsicSpec_t*) t0)->f_args);
                        VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l13)
                        t1 = vader_array_read_u8(_a12_slotarr, _a12_slotarr->offset + (size_t) l13, 246u);
                        if (((int32_t) t1.payload.i) == INT32_C(0)) {
                            l12 = true;
                        }
                    }
                    if (l12) {
                        l15 = vader_parser_parse_type(l0);
                        vader_array_push((vader_array_t*) l10, l15);
                    } else {
                        l16 = vader_parser_parse_expr(l0, INT32_C(0));
                        vader_array_push((vader_array_t*) l10, l16);
                    }
                    vader_parser_skip_newlines(l0);
                    t1 = vader_parser_match_kind(l0, (uint8_t) 80);
                    if (t1.tag == 0u) break;
                    vader_parser_skip_newlines(l0);
                    l6 = vader_parser_check(l0, (uint8_t) 75);
                    continue;
                }
                break;
            }
        }
        t0 = l3.payload.obj;
        l11 = ((vader_struct_vader_parser_IntrinsicSpec_t*) t0)->f_name;
        l11 = concat_3(1050u, l11, 236u);
        l17 = vader_parser_expect(l0, (uint8_t) 75, l11);
        l8 = vader_parser_span_of(l0, l8, l17);
        t0 = l3.payload.obj;
        l11 = ((vader_struct_vader_parser_IntrinsicSpec_t*) t0)->f_name;
        l9 = ((vader_struct_vader_lexer_Token_t*) l9)->f_span;
        vader_struct_toolchain_ast_IntrinsicCallExpr_t* _a13_obj = (vader_struct_toolchain_ast_IntrinsicCallExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_IntrinsicCallExpr_t));
        vader_obj_header_init(_a13_obj, 477u);
        _a13_obj->f_span = l8;
        _a13_obj->f_id = (size_t) 0;
        _a13_obj->f_name = l11;
        _a13_obj->f_name_span = l9;
        _a13_obj->f_args = l10;
        _a13_obj->f_trailing_comma = l6;
        t0 = (void*) _a13_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(81))) {
        l10 = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
        l18 = vader_parser_describe_token(l1);
        l18 = concat_2(1720u, l18);
        vader_parser_error(l0, (uint8_t) 2, l10, l18);
        vader_parser_advance(l0);
        vader_struct_toolchain_ast_NullLitExpr_t* _a14_obj = (vader_struct_toolchain_ast_NullLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_NullLitExpr_t));
        vader_obj_header_init(_a14_obj, 489u);
        _a14_obj->f_span = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
        _a14_obj->f_id = (size_t) 0;
        t0 = (void*) _a14_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_parser_advance(l0);
    l8 = vader_parser_expect(l0, (uint8_t) 2, 2577u);
    l1 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l1)->f_span)->f_start;
    l9 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l8)->f_span)->f_end;
    vader_struct_toolchain_span_Span_t* _a15_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a15_obj, 524u);
    _a15_obj->f_start = l1;
    _a15_obj->f_end = l9;
    l1 = (void*) _a15_obj;
    l11 = ((vader_struct_vader_lexer_Token_t*) l8)->f_text;
    l8 = ((vader_struct_vader_lexer_Token_t*) l8)->f_span;
    vader_struct_toolchain_ast_DotVariantExpr_t* _a16_obj = (vader_struct_toolchain_ast_DotVariantExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_DotVariantExpr_t));
    vader_obj_header_init(_a16_obj, 454u);
    _a16_obj->f_span = l1;
    _a16_obj->f_id = (size_t) 0;
    _a16_obj->f_variant = l11;
    _a16_obj->f_variant_span = l8;
    t0 = (void*) _a16_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_program(void* l0) {
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
    vader_string_t l19 = 0;
    bool t0;
    size_t t1;
    int64_t t2;
    void* t3 = NULL;
    vader_box_t* gc_roots[3] = { &l3, &l4, &l8 };
    void** gc_raw_roots[15] = {
        &l0, &l1, &l2, &l5, &l9, &l10, &l11, &l12, &l13, &l14, &l15, &l16, &l17, &l18, &t3,
    };
    vader_string_t* gc_atom_roots[1] = { &l19 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 15u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_peek(l0);
    vader_array_t* _a0_arr = vader_array_new(176u, 0u, 13u, 1256u);
    l2 = (void*) _a0_arr;
    vader_parser_skip_newlines(l0);
    l3 = vader_parser_parse_optional_module_decl(l0);
    vader_parser_skip_newlines(l0);
    for (;;) {
        t0 = vader_parser_check(l0, (uint8_t) 0);
        if (!(t0)) {
            l4 = vader_parser_parse_decl(l0);
            t1 = ((vader_array_t*) ((vader_struct_vader_parser_Parser_t*) l0)->f_pending_decls)->length;
            if ((t1 > INT64_C(0))) {
                l5 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pending_decls;
                l6 = ((vader_array_t*) l5)->length;
                l7 = (size_t) 0;
                while ((l7 < l6)) {
                    vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
                    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l7)
                    l8 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l7);
                    vader_array_push((vader_array_t*) l2, l8);
                    t2 = (l7 + INT64_C(1));
                    l7 = (size_t) (int64_t) t2;
                }
                vader_array_t* _a2_arr = vader_array_new(176u, 0u, 13u, 1256u);
                l9 = (void*) _a2_arr;
                ((vader_struct_vader_parser_Parser_t*) l0)->f_pending_decls = l9;
                VADER_WRITE_BARRIER((vader_struct_vader_parser_Parser_t*) l0);
            }
            if (l4.tag == 0u) {
                vader_parser_advance(l0);
            } else if (l4.tag == 471u) {
                l10 = l4.payload.obj;
                vader_array_push((vader_array_t*) l2, vader_ref_box(l10));
            } else if (l4.tag == 461u) {
                l11 = l4.payload.obj;
                vader_array_push((vader_array_t*) l2, vader_ref_box(l11));
            } else if (l4.tag == 505u) {
                l12 = l4.payload.obj;
                vader_array_push((vader_array_t*) l2, vader_ref_box(l12));
            } else if (l4.tag == 455u) {
                l13 = l4.payload.obj;
                vader_array_push((vader_array_t*) l2, vader_ref_box(l13));
            } else if (l4.tag == 512u) {
                l14 = l4.payload.obj;
                vader_array_push((vader_array_t*) l2, vader_ref_box(l14));
            } else if (l4.tag == 470u) {
                l15 = l4.payload.obj;
                vader_array_push((vader_array_t*) l2, vader_ref_box(l15));
            } else if (l4.tag == 514u) {
                l16 = l4.payload.obj;
                vader_array_push((vader_array_t*) l2, vader_ref_box(l16));
            } else if (l4.tag == 444u) {
                l17 = l4.payload.obj;
                vader_array_push((vader_array_t*) l2, vader_ref_box(l17));
            } else {
                if (!(l4.tag == 433u)) {
                    vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                }
                l18 = l4.payload.obj;
                vader_array_push((vader_array_t*) l2, vader_ref_box(l18));
            }
            vader_parser_skip_newlines(l0);
            continue;
        }
        break;
    }
    l5 = vader_parser_peek(l0);
    l19 = ((vader_struct_vader_parser_Parser_t*) l0)->f_file;
    l1 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l1)->f_span)->f_start;
    l5 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l5)->f_span)->f_end;
    vader_struct_toolchain_span_Span_t* _a3_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a3_obj, 524u);
    _a3_obj->f_start = l1;
    _a3_obj->f_end = l5;
    l1 = (void*) _a3_obj;
    vader_struct_toolchain_ast_Program_t* _a4_obj = (vader_struct_toolchain_ast_Program_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_Program_t));
    vader_obj_header_init(_a4_obj, 494u);
    _a4_obj->f_file = l19;
    _a4_obj->f_span = l1;
    _a4_obj->f_id = (size_t) 0;
    _a4_obj->f_module = l3;
    _a4_obj->f_decls = l2;
    t3 = (void*) _a4_obj;
    { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_return(void* l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    vader_box_t l2 = vader_box_null();
    int32_t l3;
    bool t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[4] = { &l0, &l1, &l4, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_advance(l0);
    l2 = vader_box_obj(0u, NULL);
    t0 = vader_parser_check(l0, (uint8_t) 1);
    if (!(t0)) {
        t0 = vader_parser_check(l0, (uint8_t) 79);
        if (!(t0)) {
            t0 = vader_parser_check(l0, (uint8_t) 0);
            if (!(t0)) {
                l2 = vader_parser_parse_expr(l0, INT32_C(0));
            }
        }
    }
    l3 = -(INT32_C(1));
    l4 = vader_parser_peek_at(l0, l3);
    t1 = vader_parser_span_of(l0, l1, l4);
    vader_struct_toolchain_ast_ReturnStmt_t* _a0_obj = (vader_struct_toolchain_ast_ReturnStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ReturnStmt_t));
    vader_obj_header_init(_a0_obj, 499u);
    _a0_obj->f_span = t1;
    _a0_obj->f_id = (size_t) 0;
    _a0_obj->f_value = l2;
    t1 = (void*) _a0_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_sam_arrow_member(void* l0) {
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
    l1 = vader_parser_expect(l0, (uint8_t) 70, 1071u);
    l2 = vader_parser_parse_expr(l0, INT32_C(0));
    l3 = -(INT32_C(1));
    l4 = vader_parser_peek_at(l0, l3);
    l4 = vader_parser_span_of(l0, l1, l4);
    vader_array_t* _a0_arr = vader_array_new(177u, 0u, 13u, 1262u);
    l5 = (void*) _a0_arr;
    vader_struct_toolchain_ast_BlockExpr_t* _a1_obj = (vader_struct_toolchain_ast_BlockExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BlockExpr_t));
    vader_obj_header_init(_a1_obj, 437u);
    _a1_obj->f_span = l4;
    _a1_obj->f_id = (size_t) 0;
    _a1_obj->f_stmts = l5;
    _a1_obj->f_trailing = l2;
    l5 = (void*) _a1_obj;
    l1 = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
    vader_array_t* _a2_arr = vader_array_new(38u, 0u, 13u, 515u);
    l6 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(28u, 0u, 13u, 462u);
    l7 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(25u, 0u, 13u, 446u);
    l8 = (void*) _a4_arr;
    vader_struct_toolchain_ast_FnDecl_t* _a5_obj = (vader_struct_toolchain_ast_FnDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FnDecl_t));
    vader_obj_header_init(_a5_obj, 461u);
    _a5_obj->f_span = l4;
    _a5_obj->f_id = (size_t) 0;
    _a5_obj->f_name = 0u;
    _a5_obj->f_name_span = l1;
    _a5_obj->f_visibility = (uint8_t) 0;
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
}

static void* vader_parser_parse_sam_block_member(void* l0) {
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
    vader_array_t* _a0_arr = vader_array_new(38u, 0u, 13u, 515u);
    l4 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(28u, 0u, 13u, 462u);
    l5 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(25u, 0u, 13u, 446u);
    l6 = (void*) _a2_arr;
    vader_struct_toolchain_ast_FnDecl_t* _a3_obj = (vader_struct_toolchain_ast_FnDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FnDecl_t));
    vader_obj_header_init(_a3_obj, 461u);
    _a3_obj->f_span = l2;
    _a3_obj->f_id = (size_t) 0;
    _a3_obj->f_name = 0u;
    _a3_obj->f_name_span = l3;
    _a3_obj->f_visibility = (uint8_t) 0;
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
}

static void* vader_parser_parse_seq_lit(void* l0) {
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
    vader_array_t* _a0_arr = vader_array_new(175u, 0u, 13u, 1241u);
    l2 = (void*) _a0_arr;
    l3 = false;
    vader_parser_skip_newlines(l0);
    t0 = vader_parser_check(l0, (uint8_t) 77);
    if (!(t0)) {
        for (;;) {
            vader_parser_skip_newlines(l0);
            t0 = vader_parser_check(l0, (uint8_t) 77);
            if (!(t0)) {
                l4 = vader_parser_parse_expr(l0, INT32_C(0));
                vader_array_push((vader_array_t*) l2, l4);
                vader_parser_skip_newlines(l0);
                t1 = vader_parser_match_kind(l0, (uint8_t) 80);
                if (t1.tag == 0u) break;
                vader_parser_skip_newlines(l0);
                l3 = vader_parser_check(l0, (uint8_t) 77);
                continue;
            }
            break;
        }
    }
    l5 = vader_parser_expect(l0, (uint8_t) 77, 1123u);
    t2 = vader_parser_span_of(l0, l1, l5);
    vader_struct_toolchain_ast_SeqLitExpr_t* _a1_obj = (vader_struct_toolchain_ast_SeqLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_SeqLitExpr_t));
    vader_obj_header_init(_a1_obj, 500u);
    _a1_obj->f_span = t2;
    _a1_obj->f_id = (size_t) 0;
    _a1_obj->f_elements = l2;
    _a1_obj->f_trailing_comma = l3;
    t2 = (void*) _a1_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_single_param_lambda_tail(void* l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    vader_string_t l3 = 0;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l4, &l5, &l6, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_parser_advance(l0);
    l2 = ((vader_struct_toolchain_ast_IdentExpr_t*) l1)->f_span;
    l3 = ((vader_struct_toolchain_ast_IdentExpr_t*) l1)->f_name;
    vader_array_t* _a0_arr = vader_array_new(25u, 0u, 13u, 446u);
    l4 = (void*) _a0_arr;
    vader_struct_toolchain_ast_FnParam_t* _a1_obj = (vader_struct_toolchain_ast_FnParam_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FnParam_t));
    vader_obj_header_init(_a1_obj, 462u);
    _a1_obj->f_span = l2;
    _a1_obj->f_id = (size_t) 0;
    _a1_obj->f_name = l3;
    _a1_obj->f_ty = vader_box_obj(0u, NULL);
    _a1_obj->f_default_value = vader_box_obj(0u, NULL);
    _a1_obj->f_variadic = false;
    _a1_obj->f_mutable = false;
    _a1_obj->f_decorators = l4;
    l2 = (void*) _a1_obj;
    t0 = vader_parser_parse_expr(l0, INT32_C(0));
    l4 = vader_parser_wrap_as_block(t0);
    l5 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_IdentExpr_t*) l1)->f_span)->f_start;
    l6 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_BlockExpr_t*) l4)->f_span)->f_end;
    vader_struct_toolchain_span_Span_t* _a2_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a2_obj, 524u);
    _a2_obj->f_start = l5;
    _a2_obj->f_end = l6;
    l5 = (void*) _a2_obj;
    vader_array_t* _a3_arr = vader_array_new(28u, 1u, 13u, 462u);
    ((void**) _a3_arr->buf->slots)[_a3_arr->offset + 0u] = l2;
    l2 = (void*) _a3_arr;
    vader_struct_toolchain_ast_LambdaExpr_t* _a4_obj = (vader_struct_toolchain_ast_LambdaExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_LambdaExpr_t));
    vader_obj_header_init(_a4_obj, 479u);
    _a4_obj->f_span = l5;
    _a4_obj->f_id = (size_t) 0;
    _a4_obj->f_params = l2;
    _a4_obj->f_return_type = vader_box_obj(0u, NULL);
    _a4_obj->f_body = l4;
    _a4_obj->f_trailing_comma = false;
    t1 = (void*) _a4_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_string_t* gc_atom_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_lexer_tokenize(l0, l1);
    l3 = vader_parser_new_parser(((vader_struct_vader_lexer_Lexer_t*) l2)->f_tokens, l1);
    l4 = ((vader_struct_vader_lexer_Lexer_t*) l2)->f_errors;
    l5 = ((vader_array_t*) l4)->length;
    l6 = (size_t) 0;
    while ((l6 < l5)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
        l7 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
        vader_array_push((vader_array_t*) ((vader_struct_vader_parser_Parser_t*) l3)->f_errors, vader_ref_box(l7));
        t0 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t0;
    }
    l4 = vader_parser_parse_program(l3);
    l7 = vader_parser_new_node_id_factory();
    vader_parser_assign_program_ids(l4, l7);
    l2 = ((vader_struct_vader_lexer_Lexer_t*) l2)->f_tokens;
    l3 = ((vader_struct_vader_parser_Parser_t*) l3)->f_errors;
    vader_struct_vader_parser_ParsedSource_t* _a1_obj = (vader_struct_vader_parser_ParsedSource_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_ParsedSource_t));
    vader_obj_header_init(_a1_obj, 984u);
    _a1_obj->f_program = l4;
    _a1_obj->f_tokens = l2;
    _a1_obj->f_errors = l3;
    _a1_obj->f_id_factory = l7;
    t1 = (void*) _a1_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_parser_parse_stmt(void* l0) {
    void* l1 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    vader_string_t l2 = 0;
    uint8_t l3;
    bool l4, l5;
    vader_box_t l6 = vader_box_null(), l7 = vader_box_null();
    int32_t l8;
    bool t0;
    void* t1 = NULL;
    vader_string_t t2 = 0;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l6, &l7, &t3 };
    void** gc_raw_roots[5] = { &l0, &l1, &l9, &l10, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l2, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_parser_check(l0, (uint8_t) 22);
    if (t0) {
        t1 = vader_parser_parse_return(l0);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_parser_check(l0, (uint8_t) 23);
    if (t0) {
        t1 = vader_parser_parse_yield(l0);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_parser_check(l0, (uint8_t) 20);
    if (t0) {
        t1 = vader_parser_parse_for(l0, vader_box_obj(0u, NULL), false);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_parser_check(l0, (uint8_t) 72);
    if (t0) {
        t1 = vader_parser_peek_at(l0, INT32_C(1));
        if (((vader_struct_vader_lexer_Token_t*) t1)->f_kind == INT32_C(2)) {
            t1 = vader_parser_peek_at(l0, INT32_C(1));
            t2 = ((vader_struct_vader_lexer_Token_t*) t1)->f_text;
            if (t2 == 1454u) {
                t0 = vader_parser_check_at(l0, (uint8_t) 20, INT32_C(2));
                if (t0) {
                    vader_parser_advance(l0);
                    vader_parser_advance(l0);
                    t1 = vader_parser_parse_for(l0, vader_box_obj(0u, NULL), true);
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
            }
        }
    }
    t0 = vader_parser_check(l0, (uint8_t) 26);
    if (t0) {
        t1 = vader_parser_parse_break(l0);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_parser_check(l0, (uint8_t) 27);
    if (t0) {
        t1 = vader_parser_parse_continue(l0);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_parser_check(l0, (uint8_t) 25);
    if (t0) {
        t1 = vader_parser_parse_defer(l0);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_parser_check(l0, (uint8_t) 2);
    if (t0) {
        t0 = vader_parser_check_at(l0, (uint8_t) 82, INT32_C(1));
        if (t0) {
            t0 = vader_parser_check_at(l0, (uint8_t) 20, INT32_C(2));
            if (t0) {
                l1 = vader_parser_advance(l0);
                vader_parser_advance(l0);
                l2 = ((vader_struct_vader_lexer_Token_t*) l1)->f_text;
                t3 = vader_box_string(240u, l2);
                t1 = vader_parser_parse_for(l0, t3, false);
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
    }
    t0 = vader_parser_check(l0, (uint8_t) 76);
    if (t0) {
        l3 = vader_parser_kind_after_bracket_group(l0);
        if (l3 == INT32_C(65)) {
            l4 = true;
        } else {
            l4 = l3 == INT32_C(66);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l3 == INT32_C(82);
        }
        if (l4) {
            t1 = vader_parser_parse_tuple_let(l0);
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l3 == INT32_C(59)) {
            l4 = true;
        } else {
            t1 = vader_parser_compound_op(l3);
            l4 = ((vader_struct_vader_parser_CompoundOpResult_t*) t1)->f_matched;
        }
        if (l4) {
            t1 = vader_parser_parse_destructure_assign(l0);
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    t0 = vader_parser_check(l0, (uint8_t) 2);
    if (t0) {
        t0 = vader_parser_check_at(l0, (uint8_t) 65, INT32_C(1));
        if (t0) {
            l5 = true;
        } else {
            l5 = vader_parser_check_at(l0, (uint8_t) 66, INT32_C(1));
        }
        l4 = l5;
    } else {
        l4 = false;
    }
    if (l4) {
        t1 = vader_parser_parse_let(l0);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_parser_check(l0, (uint8_t) 2);
    if (t0) {
        t0 = vader_parser_check_at(l0, (uint8_t) 82, INT32_C(1));
        if (t0) {
            t1 = vader_parser_parse_typed_let(l0);
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l1 = vader_parser_peek(l0);
    l6 = vader_parser_parse_expr(l0, INT32_C(0));
    t3 = vader_parser_match_kind(l0, (uint8_t) 59);
    if (!(t3.tag == 0u)) {
        l7 = vader_parser_parse_expr(l0, INT32_C(0));
        l8 = -(INT32_C(1));
        l9 = vader_parser_peek_at(l0, l8);
        t1 = vader_parser_span_of(l0, l1, l9);
        vader_struct_toolchain_ast_AssignStmt_t* _a0_obj = (vader_struct_toolchain_ast_AssignStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_AssignStmt_t));
        vader_obj_header_init(_a0_obj, 434u);
        _a0_obj->f_span = t1;
        _a0_obj->f_id = (size_t) 0;
        _a0_obj->f_target = l6;
        _a0_obj->f_value = l7;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_parser_peek(l0);
    l9 = vader_parser_compound_op(((vader_struct_vader_lexer_Token_t*) t1)->f_kind);
    t0 = ((vader_struct_vader_parser_CompoundOpResult_t*) l9)->f_matched;
    if (!(t0)) {
        t1 = l6.payload.obj;
        vader_struct_toolchain_ast_ExprStmt_t* _a1_obj = (vader_struct_toolchain_ast_ExprStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ExprStmt_t));
        vader_obj_header_init(_a1_obj, 458u);
        _a1_obj->f_span = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_span;
        _a1_obj->f_id = (size_t) 0;
        _a1_obj->f_expr = l6;
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_parser_advance(l0);
    l7 = vader_parser_parse_expr(l0, INT32_C(0));
    l8 = -(INT32_C(1));
    l10 = vader_parser_peek_at(l0, l8);
    l1 = vader_parser_span_of(l0, l1, l10);
    l3 = ((vader_struct_vader_parser_CompoundOpResult_t*) l9)->f_op;
    vader_struct_toolchain_ast_BinaryExpr_t* _a2_obj = (vader_struct_toolchain_ast_BinaryExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BinaryExpr_t));
    vader_obj_header_init(_a2_obj, 436u);
    _a2_obj->f_span = l1;
    _a2_obj->f_id = (size_t) 0;
    _a2_obj->f_op = l3;
    _a2_obj->f_left = l6;
    _a2_obj->f_right = l7;
    _a2_obj->f_bind_as = vader_box_obj(0u, NULL);
    l9 = (void*) _a2_obj;
    vader_struct_toolchain_ast_AssignStmt_t* _a3_obj = (vader_struct_toolchain_ast_AssignStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_AssignStmt_t));
    vader_obj_header_init(_a3_obj, 434u);
    _a3_obj->f_span = l1;
    _a3_obj->f_id = (size_t) 0;
    _a3_obj->f_target = l6;
    _a3_obj->f_value = vader_ref_box(l9);
    t1 = (void*) _a3_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_string_lit(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    vader_string_t l4 = 0;
    vader_box_t l5 = vader_box_null(), l9 = vader_box_null(), l10 = vader_box_null();
    bool t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[3] = { &l5, &l9, &l10 };
    void** gc_raw_roots[14] = {
        &l0, &l1, &l2, &l3, &l6, &l7, &l8, &l11, &l12, &l13, &l14, &l15, &l16, &t1,
    };
    vader_string_t* gc_atom_roots[1] = { &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 14u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_advance(l0);
    vader_array_t* _a0_arr = vader_array_new(182u, 0u, 13u, 1300u);
    l2 = (void*) _a0_arr;
    for (;;) {
        t0 = vader_parser_check(l0, (uint8_t) 8);
        if (!(t0)) {
            t0 = vader_parser_check(l0, (uint8_t) 0);
            if (t0) break;
            l3 = vader_parser_peek(l0);
            if (((vader_struct_vader_lexer_Token_t*) l3)->f_kind == INT32_C(7)) {
                vader_parser_advance(l0);
                l4 = ((vader_struct_vader_lexer_Token_t*) l3)->f_text;
                l5 = ((vader_struct_vader_lexer_Token_t*) l3)->f_value;
                if (l5.tag == 240u) {
                    l4 = l5.payload.s;
                }
                l6 = ((vader_struct_vader_lexer_Token_t*) l3)->f_span;
                vader_struct_toolchain_ast_StringLitText_t* _a1_obj = (vader_struct_toolchain_ast_StringLitText_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_StringLitText_t));
                vader_obj_header_init(_a1_obj, 504u);
                _a1_obj->f_value = l4;
                _a1_obj->f_span = l6;
                _a1_obj->f_id = (size_t) 0;
                l7 = (void*) _a1_obj;
                vader_array_push((vader_array_t*) l2, vader_ref_box(l7));
                continue;
            }
            if (((vader_struct_vader_lexer_Token_t*) l3)->f_kind == INT32_C(9)) {
                l8 = vader_parser_advance(l0);
                l9 = vader_parser_parse_expr(l0, INT32_C(0));
                l10 = vader_parser_match_kind(l0, (uint8_t) 10);
                if (l10.tag == 0u) {
                    t1 = l9.payload.obj;
                    l11 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_span;
                } else {
                    t1 = l10.payload.obj;
                    l11 = ((vader_struct_vader_lexer_Token_t*) t1)->f_span;
                }
                l12 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l8)->f_span)->f_start;
                l13 = ((vader_struct_toolchain_span_Span_t*) l11)->f_end;
                vader_struct_toolchain_span_Span_t* _a2_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
                vader_obj_header_init(_a2_obj, 524u);
                _a2_obj->f_start = l12;
                _a2_obj->f_end = l13;
                l14 = (void*) _a2_obj;
                vader_struct_toolchain_ast_StringLitInterp_t* _a3_obj = (vader_struct_toolchain_ast_StringLitInterp_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_StringLitInterp_t));
                vader_obj_header_init(_a3_obj, 503u);
                _a3_obj->f_expr = l9;
                _a3_obj->f_span = l14;
                _a3_obj->f_id = (size_t) 0;
                l15 = (void*) _a3_obj;
                vader_array_push((vader_array_t*) l2, vader_ref_box(l15));
                continue;
            }
            l16 = ((vader_struct_vader_lexer_Token_t*) l3)->f_span;
            vader_parser_error(l0, (uint8_t) 0, l16, 1818u);
            vader_parser_advance(l0);
            continue;
        }
        break;
    }
    l3 = vader_parser_match_or_peek(l0, (uint8_t) 8);
    t1 = vader_parser_span_of(l0, l1, l3);
    vader_struct_toolchain_ast_StringLitExpr_t* _a4_obj = (vader_struct_toolchain_ast_StringLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_StringLitExpr_t));
    vader_obj_header_init(_a4_obj, 502u);
    _a4_obj->f_span = t1;
    _a4_obj->f_id = (size_t) 0;
    _a4_obj->f_parts = l2;
    t1 = (void*) _a4_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_struct_decl(void* l0, void* l1, uint8_t l2, void* l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    void* l7 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l19 = NULL;
    void* l20 = NULL;
    void* l22 = NULL;
    uint8_t l6;
    size_t l8, l9;
    vader_string_t l12 = 0;
    vader_string_t l13 = 0;
    vader_string_t l21 = 0;
    vader_box_t l16 = vader_box_null(), l17 = vader_box_null();
    int32_t l18;
    bool t0;
    vader_string_t t1 = 0;
    int64_t t2;
    vader_box_t t3 = vader_box_null();
    void* t4 = NULL;
    vader_box_t* gc_roots[3] = { &l16, &l17, &t3 };
    void** gc_raw_roots[14] = {
        &l0, &l1, &l3, &l4, &l5, &l7, &l10, &l11, &l14, &l15, &l19, &l20, &l22, &t4,
    };
    vader_string_t* gc_atom_roots[4] = { &l12, &l13, &l21, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 14u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_parser_reject_target_decorator(l0, l1, 1204u);
    vader_parser_advance(l0);
    l4 = vader_parser_parse_struct_type_param_list(l0);
    vader_parser_expect(l0, (uint8_t) 78, 1150u);
    vader_parser_skip_newlines(l0);
    vader_array_t* _a0_arr = vader_array_new(34u, 0u, 13u, 506u);
    l5 = (void*) _a0_arr;
    for (;;) {
        t0 = vader_parser_check(l0, (uint8_t) 79);
        if (!(t0)) {
            t0 = vader_parser_check(l0, (uint8_t) 0);
            if (t0) break;
            l7 = vader_parser_parse_decorators(l0);
            l6 = (uint8_t) 0;
            l8 = ((vader_array_t*) l7)->length;
            l9 = (size_t) 0;
            while ((l9 < l8)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l9)
                l10 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l9);
                t1 = ((vader_struct_toolchain_ast_Decorator_t*) l10)->f_name;
                if (t1 == 1832u) {
                    l6 = (uint8_t) 1;
                } else {
                    l11 = ((vader_struct_toolchain_ast_Decorator_t*) l10)->f_span;
                    l12 = ((vader_struct_toolchain_ast_Decorator_t*) l10)->f_name;
                    l13 = concat_3(1091u, l12, 882u);
                    vader_parser_error(l0, (uint8_t) 13, l11, l13);
                }
                t2 = (l9 + INT64_C(1));
                l9 = (size_t) (int64_t) t2;
            }
            l14 = vader_parser_peek(l0);
            l15 = vader_parser_expect(l0, (uint8_t) 2, 1649u);
            vader_parser_expect(l0, (uint8_t) 82, 1080u);
            l16 = vader_parser_parse_type(l0);
            l17 = vader_box_obj(0u, NULL);
            t3 = vader_parser_match_kind(l0, (uint8_t) 59);
            if (!(t3.tag == 0u)) {
                vader_parser_skip_newlines(l0);
                l17 = vader_parser_parse_expr(l0, INT32_C(0));
            }
            l18 = -(INT32_C(1));
            l19 = vader_parser_peek_at(l0, l18);
            l20 = vader_parser_span_of(l0, l14, l19);
            l21 = ((vader_struct_vader_lexer_Token_t*) l15)->f_text;
            vader_struct_toolchain_ast_StructField_t* _a2_obj = (vader_struct_toolchain_ast_StructField_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_StructField_t));
            vader_obj_header_init(_a2_obj, 506u);
            _a2_obj->f_span = l20;
            _a2_obj->f_id = (size_t) 0;
            _a2_obj->f_name = l21;
            _a2_obj->f_ty = l16;
            _a2_obj->f_visibility = l6;
            _a2_obj->f_default_v = l17;
            l22 = (void*) _a2_obj;
            vader_array_push((vader_array_t*) l5, vader_ref_box(l22));
            t0 = vader_parser_check(l0, (uint8_t) 79);
            if (t0) {
                continue;
            }
            vader_parser_match_kind(l0, (uint8_t) 80);
            vader_parser_skip_newlines(l0);
            continue;
        }
        break;
    }
    l7 = vader_parser_expect(l0, (uint8_t) 79, 1158u);
    l7 = vader_parser_span_of(l0, l3, l7);
    l12 = ((vader_struct_vader_lexer_Token_t*) l3)->f_text;
    l10 = ((vader_struct_vader_lexer_Token_t*) l3)->f_span;
    vader_struct_toolchain_ast_StructDecl_t* _a3_obj = (vader_struct_toolchain_ast_StructDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_StructDecl_t));
    vader_obj_header_init(_a3_obj, 505u);
    _a3_obj->f_span = l7;
    _a3_obj->f_id = (size_t) 0;
    _a3_obj->f_name = l12;
    _a3_obj->f_name_span = l10;
    _a3_obj->f_visibility = l2;
    _a3_obj->f_type_params = l4;
    _a3_obj->f_fields = l5;
    _a3_obj->f_decorators = l1;
    t4 = (void*) _a3_obj;
    { void* __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_struct_lit_fields(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    bool l2;
    vader_box_t l4 = vader_box_null(), l9 = vader_box_null();
    int32_t l5, l10;
    vader_string_t l13 = 0;
    bool t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[3] = { &l4, &l9, &t1 };
    void** gc_raw_roots[11] = { &l0, &l1, &l3, &l6, &l7, &l8, &l11, &l12, &l14, &l15, &t2 };
    vader_string_t* gc_atom_roots[1] = { &l13 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 11u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(183u, 0u, 13u, 1301u);
    l1 = (void*) _a0_arr;
    l2 = false;
    vader_parser_skip_newlines(l0);
    for (;;) {
        t0 = vader_parser_check(l0, (uint8_t) 79);
        if (!(t0)) {
            t0 = vader_parser_check(l0, (uint8_t) 0);
            if (t0) break;
            l3 = vader_parser_peek(l0);
            t1 = vader_parser_match_kind(l0, (uint8_t) 69);
            if (t1.tag == 0u) {
                vader_parser_expect(l0, (uint8_t) 81, 1075u);
                l8 = vader_parser_expect(l0, (uint8_t) 2, 2263u);
                vader_parser_expect(l0, (uint8_t) 59, 1084u);
                l9 = vader_parser_parse_expr(l0, INT32_C(0));
                l10 = -(INT32_C(1));
                l11 = vader_parser_peek_at(l0, l10);
                l12 = vader_parser_span_of(l0, l3, l11);
                l13 = ((vader_struct_vader_lexer_Token_t*) l8)->f_text;
                l14 = ((vader_struct_vader_lexer_Token_t*) l8)->f_span;
                vader_struct_toolchain_ast_StructLitField_t* _a1_obj = (vader_struct_toolchain_ast_StructLitField_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_StructLitField_t));
                vader_obj_header_init(_a1_obj, 508u);
                _a1_obj->f_span = l12;
                _a1_obj->f_id = (size_t) 0;
                _a1_obj->f_name = l13;
                _a1_obj->f_name_span = l14;
                _a1_obj->f_value = l9;
                l15 = (void*) _a1_obj;
                vader_array_push((vader_array_t*) l1, vader_ref_box(l15));
            } else {
                l4 = vader_parser_parse_expr(l0, INT32_C(0));
                l5 = -(INT32_C(1));
                l6 = vader_parser_peek_at(l0, l5);
                t2 = vader_parser_span_of(l0, l3, l6);
                vader_struct_toolchain_ast_StructLitSpread_t* _a2_obj = (vader_struct_toolchain_ast_StructLitSpread_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_StructLitSpread_t));
                vader_obj_header_init(_a2_obj, 509u);
                _a2_obj->f_span = t2;
                _a2_obj->f_id = (size_t) 0;
                _a2_obj->f_expr = l4;
                l7 = (void*) _a2_obj;
                vader_array_push((vader_array_t*) l1, vader_ref_box(l7));
            }
            vader_parser_skip_newlines(l0);
            t1 = vader_parser_match_kind(l0, (uint8_t) 80);
            if (t1.tag == 0u) break;
            vader_parser_skip_newlines(l0);
            l2 = vader_parser_check(l0, (uint8_t) 79);
            continue;
        }
        break;
    }
    vader_parser_skip_newlines(l0);
    vader_struct_vader_parser_CommaList__Any_t* _a3_obj = (vader_struct_vader_parser_CommaList__Any_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_CommaList__Any_t));
    vader_obj_header_init(_a3_obj, 973u);
    _a3_obj->f_items = l1;
    _a3_obj->f_trailing_comma = l2;
    t2 = (void*) _a3_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_struct_pattern(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l6 = NULL;
    void* l9 = NULL;
    void* l11 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    vader_string_t l5 = 0;
    vader_string_t l10 = 0;
    vader_string_t l15 = 0;
    vader_box_t l7 = vader_box_null();
    bool l8;
    int32_t l12;
    bool t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l7, &t2 };
    void** gc_raw_roots[13] = {
        &l0, &l1, &l2, &l3, &l4, &l6, &l9, &l11, &l13, &l14, &l16, &l17, &t1,
    };
    vader_string_t* gc_atom_roots[3] = { &l5, &l10, &l15 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 13u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_expect(l0, (uint8_t) 78, 1151u);
    vader_parser_skip_newlines(l0);
    vader_array_t* _a0_arr = vader_array_new(35u, 0u, 13u, 511u);
    l2 = (void*) _a0_arr;
    for (;;) {
        t0 = vader_parser_check(l0, (uint8_t) 79);
        if (!(t0)) {
            t0 = vader_parser_check(l0, (uint8_t) 0);
            if (t0) break;
            l3 = vader_parser_peek(l0);
            l4 = vader_parser_expect(l0, (uint8_t) 2, 1652u);
            l5 = ((vader_struct_vader_lexer_Token_t*) l4)->f_text;
            l6 = ((vader_struct_vader_lexer_Token_t*) l4)->f_span;
            vader_struct_toolchain_ast_PatternBinding_t* _a1_obj = (vader_struct_toolchain_ast_PatternBinding_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_PatternBinding_t));
            vader_obj_header_init(_a1_obj, 491u);
            _a1_obj->f_name = l5;
            _a1_obj->f_span = l6;
            _a1_obj->f_id = (size_t) 0;
            t1 = (void*) _a1_obj;
            l7 = vader_ref_box(t1);
            t2 = vader_parser_match_kind(l0, (uint8_t) 82);
            if (!(t2.tag == 0u)) {
                t0 = vader_parser_check(l0, (uint8_t) 2);
                if (t0) {
                    t1 = vader_parser_peek_at(l0, INT32_C(1));
                    t0 = vader_parser_is_literal_start(t1);
                    l8 = !(t0);
                } else {
                    l8 = false;
                }
                if (l8) {
                    l9 = vader_parser_advance(l0);
                    l10 = ((vader_struct_vader_lexer_Token_t*) l9)->f_text;
                    l11 = ((vader_struct_vader_lexer_Token_t*) l9)->f_span;
                    vader_struct_toolchain_ast_PatternBinding_t* _a2_obj = (vader_struct_toolchain_ast_PatternBinding_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_PatternBinding_t));
                    vader_obj_header_init(_a2_obj, 491u);
                    _a2_obj->f_name = l10;
                    _a2_obj->f_span = l11;
                    _a2_obj->f_id = (size_t) 0;
                    t1 = (void*) _a2_obj;
                    l7 = vader_ref_box(t1);
                } else {
                    t2 = vader_parser_parse_expr(l0, INT32_C(0));
                    vader_struct_toolchain_ast_PatternLiteral_t* _a3_obj = (vader_struct_toolchain_ast_PatternLiteral_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_PatternLiteral_t));
                    vader_obj_header_init(_a3_obj, 492u);
                    _a3_obj->f_value = t2;
                    t1 = (void*) _a3_obj;
                    l7 = vader_ref_box(t1);
                }
            }
            l12 = -(INT32_C(1));
            l13 = vader_parser_peek_at(l0, l12);
            l14 = vader_parser_span_of(l0, l3, l13);
            l15 = ((vader_struct_vader_lexer_Token_t*) l4)->f_text;
            l16 = ((vader_struct_vader_lexer_Token_t*) l4)->f_span;
            vader_struct_toolchain_ast_StructPatternField_t* _a4_obj = (vader_struct_toolchain_ast_StructPatternField_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_StructPatternField_t));
            vader_obj_header_init(_a4_obj, 511u);
            _a4_obj->f_span = l14;
            _a4_obj->f_id = (size_t) 0;
            _a4_obj->f_name = l15;
            _a4_obj->f_name_span = l16;
            _a4_obj->f_value = l7;
            l17 = (void*) _a4_obj;
            vader_array_push((vader_array_t*) l2, vader_ref_box(l17));
            vader_parser_skip_newlines(l0);
            t2 = vader_parser_match_kind(l0, (uint8_t) 80);
            if (t2.tag == 0u) break;
            vader_parser_skip_newlines(l0);
            continue;
        }
        break;
    }
    l3 = vader_parser_expect(l0, (uint8_t) 79, 1160u);
    l1 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l1)->f_span)->f_start;
    l3 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l3)->f_span)->f_end;
    vader_struct_toolchain_span_Span_t* _a5_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a5_obj, 524u);
    _a5_obj->f_start = l1;
    _a5_obj->f_end = l3;
    t1 = (void*) _a5_obj;
    vader_struct_toolchain_ast_StructPattern_t* _a6_obj = (vader_struct_toolchain_ast_StructPattern_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_StructPattern_t));
    vader_obj_header_init(_a6_obj, 510u);
    _a6_obj->f_span = t1;
    _a6_obj->f_id = (size_t) 0;
    _a6_obj->f_fields = l2;
    t1 = (void*) _a6_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_struct_type_param_list(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l21 = NULL;
    void* l22 = NULL;
    void* l24 = NULL;
    bool l2, l19;
    vader_box_t l5 = vader_box_null(), l13 = vader_box_null();
    vader_string_t l6 = 0;
    vader_string_t l7 = 0;
    vader_string_t l8 = 0;
    vader_string_t l9 = 0;
    vader_string_t l17 = 0;
    vader_string_t l18 = 0;
    vader_string_t l23 = 0;
    int32_t l10, l14, l20;
    bool t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    size_t t3;
    vader_string_t t4 = 0;
    vader_box_t* gc_roots[3] = { &l5, &l13, &t2 };
    void** gc_raw_roots[12] = { &l0, &l1, &l3, &l4, &l11, &l12, &l15, &l16, &l21, &l22, &l24, &t1 };
    vader_string_t* gc_atom_roots[8] = { &l6, &l7, &l8, &l9, &l17, &l18, &l23, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 8u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_parser_check(l0, (uint8_t) 49);
    if (t0) {
        t1 = vader_parser_parse_angle_type_params(l0);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_parser_match_kind(l0, (uint8_t) 74);
    if (t2.tag == 0u) {
        vader_array_t* _a0_arr = vader_array_new(38u, 0u, 13u, 515u);
        t1 = (void*) _a0_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a1_arr = vader_array_new(38u, 0u, 13u, 515u);
    l1 = (void*) _a1_arr;
    vader_parser_skip_newlines(l0);
    for (;;) {
        t0 = vader_parser_check(l0, (uint8_t) 75);
        if (!(t0)) {
            t0 = vader_parser_check(l0, (uint8_t) 0);
            if (t0) break;
            t3 = ((vader_array_t*) l1)->length;
            if ((t3 > INT64_C(0))) {
                t2 = vader_parser_match_kind(l0, (uint8_t) 80);
                if (t2.tag == 0u) break;
                vader_parser_skip_newlines(l0);
                t0 = vader_parser_check(l0, (uint8_t) 75);
                if (t0) break;
            }
            t2 = vader_parser_match_kind(l0, (uint8_t) 73);
            l2 = !(t2.tag == 0u);
            l3 = vader_parser_peek(l0);
            l4 = vader_parser_expect(l0, (uint8_t) 2, 2351u);
            l5 = vader_box_obj(0u, NULL);
            t2 = vader_parser_match_kind(l0, (uint8_t) 82);
            if (!(t2.tag == 0u)) {
                l5 = vader_parser_parse_type(l0);
            }
            if (l2) {
                l13 = l5;
                if (!(l13.tag == 0u)) {
                    if (l13.tag == 466u) {
                        t1 = l13.payload.obj;
                        t4 = ((vader_struct_toolchain_ast_IdentExpr_t*) t1)->f_name;
                        if (t4 == 2346u) {
                            l14 = -(INT32_C(1));
                            l15 = vader_parser_peek_at(l0, l14);
                            l16 = vader_parser_span_of(l0, l3, l15);
                            l17 = ((vader_struct_vader_lexer_Token_t*) l4)->f_text;
                            l18 = concat_3(850u, l17, 928u);
                            vader_parser_error(l0, (uint8_t) 18, l16, l18);
                            l5 = vader_box_obj(0u, NULL);
                        }
                    }
                }
            } else {
                if (l5.tag == 0u) {
                    l7 = ((vader_struct_vader_lexer_Token_t*) l4)->f_text;
                    l8 = ((vader_struct_vader_lexer_Token_t*) l4)->f_text;
                    l6 = concat_5(850u, l7, 967u, l8, 850u);
                } else {
                    l9 = ((vader_struct_vader_lexer_Token_t*) l4)->f_text;
                    l6 = concat_3(850u, l9, 966u);
                }
                l10 = -(INT32_C(1));
                l11 = vader_parser_peek_at(l0, l10);
                l12 = vader_parser_span_of(l0, l3, l11);
                vader_parser_error(l0, (uint8_t) 17, l12, l6);
            }
            l19 = !(l5.tag == 0u);
            l20 = -(INT32_C(1));
            l21 = vader_parser_peek_at(l0, l20);
            l22 = vader_parser_span_of(l0, l3, l21);
            l23 = ((vader_struct_vader_lexer_Token_t*) l4)->f_text;
            vader_struct_toolchain_ast_TypeParam_t* _a2_obj = (vader_struct_toolchain_ast_TypeParam_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_TypeParam_t));
            vader_obj_header_init(_a2_obj, 515u);
            _a2_obj->f_span = l22;
            _a2_obj->f_id = (size_t) 0;
            _a2_obj->f_name = l23;
            _a2_obj->f_bound = l5;
            _a2_obj->f_default_v = vader_box_obj(0u, NULL);
            _a2_obj->f_is_comptime_value = l19;
            l24 = (void*) _a2_obj;
            vader_array_push((vader_array_t*) l1, vader_ref_box(l24));
            continue;
        }
        break;
    }
    vader_parser_expect(l0, (uint8_t) 75, 1055u);
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_trait_decl(void* l0, void* l1, uint8_t l2, void* l3) {
    void* l4 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    void* l10 = NULL;
    vader_box_t l5 = vader_box_null(), l11 = vader_box_null();
    int32_t l7;
    vader_string_t l9 = 0;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    bool t2;
    vader_box_t* gc_roots[3] = { &l5, &l11, &t0 };
    void** gc_raw_roots[8] = { &l0, &l1, &l3, &l4, &l6, &l8, &l10, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_parser_reject_target_decorator(l0, l1, 1205u);
    vader_parser_reject_c_decorators(l0, l1, 1205u);
    vader_parser_advance(l0);
    l4 = vader_parser_parse_struct_type_param_list(l0);
    l5 = vader_box_obj(0u, NULL);
    vader_array_t* _a0_arr = vader_array_new(27u, 0u, 13u, 461u);
    l6 = (void*) _a0_arr;
    t0 = vader_parser_match_kind(l0, (uint8_t) 59);
    if (!(t0.tag == 0u)) {
        l5 = vader_parser_parse_type(l0);
        l7 = -(INT32_C(1));
        l8 = vader_parser_peek_at(l0, l7);
        l8 = vader_parser_span_of(l0, l3, l8);
        l9 = ((vader_struct_vader_lexer_Token_t*) l3)->f_text;
        l10 = ((vader_struct_vader_lexer_Token_t*) l3)->f_span;
        vader_struct_toolchain_ast_TraitDecl_t* _a1_obj = (vader_struct_toolchain_ast_TraitDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_TraitDecl_t));
        vader_obj_header_init(_a1_obj, 512u);
        _a1_obj->f_span = l8;
        _a1_obj->f_id = (size_t) 0;
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
    t0 = vader_parser_match_kind(l0, (uint8_t) 82);
    if (!(t0.tag == 0u)) {
        l5 = vader_parser_parse_type(l0);
    }
    vader_parser_expect(l0, (uint8_t) 78, 1152u);
    vader_parser_skip_newlines(l0);
    for (;;) {
        t2 = vader_parser_check(l0, (uint8_t) 79);
        if (!(t2)) {
            t2 = vader_parser_check(l0, (uint8_t) 0);
            if (t2) break;
            l11 = vader_parser_parse_fn_decl_inside_trait(l0);
            if (l11.tag == 461u) {
                l8 = l11.payload.obj;
                vader_array_push((vader_array_t*) l6, vader_ref_box(l8));
            } else if (!(l11.tag == 0u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            vader_parser_skip_newlines(l0);
            continue;
        }
        break;
    }
    l8 = vader_parser_expect(l0, (uint8_t) 79, 1161u);
    l8 = vader_parser_span_of(l0, l3, l8);
    l9 = ((vader_struct_vader_lexer_Token_t*) l3)->f_text;
    l10 = ((vader_struct_vader_lexer_Token_t*) l3)->f_span;
    vader_struct_toolchain_ast_TraitDecl_t* _a2_obj = (vader_struct_toolchain_ast_TraitDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_TraitDecl_t));
    vader_obj_header_init(_a2_obj, 512u);
    _a2_obj->f_span = l8;
    _a2_obj->f_id = (size_t) 0;
    _a2_obj->f_name = l9;
    _a2_obj->f_name_span = l10;
    _a2_obj->f_visibility = l2;
    _a2_obj->f_type_params = l4;
    _a2_obj->f_requires = l5;
    _a2_obj->f_members = l6;
    _a2_obj->f_decorators = l1;
    t1 = (void*) _a2_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_tuple_let(void* l0) {
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
    t0 = vader_parser_check(l0, (uint8_t) 82);
    if (t0) {
        vader_parser_advance(l0);
        l3 = vader_parser_parse_type(l0);
        t1 = vader_parser_peek(l0);
        if (((vader_struct_vader_lexer_Token_t*) t1)->f_kind == INT32_C(82)) {
            vader_parser_advance(l0);
            l4 = false;
        } else {
            vader_parser_expect(l0, (uint8_t) 59, 1085u);
        }
    } else {
        l5 = vader_parser_peek(l0);
        if (((vader_struct_vader_lexer_Token_t*) l5)->f_kind == INT32_C(65)) {
            l6 = true;
        } else {
            l6 = ((vader_struct_vader_lexer_Token_t*) l5)->f_kind == INT32_C(66);
        }
        if (l6) {
            vader_parser_advance(l0);
            l4 = ((vader_struct_vader_lexer_Token_t*) l5)->f_kind == INT32_C(66);
        } else {
            vader_parser_expect(l0, (uint8_t) 66, 1079u);
        }
    }
    l7 = vader_parser_parse_expr(l0, INT32_C(0));
    l8 = -(INT32_C(1));
    l5 = vader_parser_peek_at(l0, l8);
    t1 = vader_parser_span_of(l0, l1, l5);
    vader_struct_toolchain_ast_LetStmt_t* _a0_obj = (vader_struct_toolchain_ast_LetStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_LetStmt_t));
    vader_obj_header_init(_a0_obj, 480u);
    _a0_obj->f_span = t1;
    _a0_obj->f_id = (size_t) 0;
    _a0_obj->f_mutable = l4;
    _a0_obj->f_binding = l2;
    _a0_obj->f_ty = l3;
    _a0_obj->f_value = l7;
    t1 = (void*) _a0_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_parser_parse_type(void* l0) {
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
    t0 = ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth;
    if ((t0 > INT32_C(256))) {
        t0 = ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth;
        l1 = (t0 - INT32_C(1));
        ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth = l1;
        t1 = vader_parser_peek(l0);
        l2 = ((vader_struct_vader_lexer_Token_t*) t1)->f_span;
        vader_parser_report_nesting_too_deep(l0, 2346u);
        t1 = vader_parser_ident_expr(l2, 399u);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_parser_match_kind(l0, (uint8_t) 42);
    vader_parser_reject_removed_const(l0);
    l3 = vader_parser_parse_type_intersection(l0);
    t2 = vader_parser_check(l0, (uint8_t) 42);
    if (t2) {
        t1 = l3.payload.obj;
        l2 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_span;
        for (;;) {
            t3 = vader_parser_match_kind(l0, (uint8_t) 42);
            if (!(t3.tag == 0u)) {
                vader_parser_reject_removed_const(l0);
                l4 = vader_parser_parse_type_intersection(l0);
                t1 = l4.payload.obj;
                l5 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_span;
                l6 = ((vader_struct_toolchain_span_Span_t*) l2)->f_start;
                l7 = ((vader_struct_toolchain_span_Span_t*) l5)->f_end;
                vader_struct_toolchain_span_Span_t* _a0_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
                vader_obj_header_init(_a0_obj, 524u);
                _a0_obj->f_start = l6;
                _a0_obj->f_end = l7;
                t1 = (void*) _a0_obj;
                vader_struct_toolchain_ast_BinaryExpr_t* _a1_obj = (vader_struct_toolchain_ast_BinaryExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BinaryExpr_t));
                vader_obj_header_init(_a1_obj, 436u);
                _a1_obj->f_span = t1;
                _a1_obj->f_id = (size_t) 0;
                _a1_obj->f_op = (uint8_t) 8;
                _a1_obj->f_left = l3;
                _a1_obj->f_right = l4;
                _a1_obj->f_bind_as = vader_box_obj(0u, NULL);
                t1 = (void*) _a1_obj;
                l3 = vader_ref_box(t1);
                continue;
            }
            break;
        }
    }
    t0 = ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth;
    l1 = (t0 - INT32_C(1));
    ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth = l1;
    { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_parser_parse_type_intersection(void* l0) {
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
    t0 = vader_parser_check(l0, (uint8_t) 41);
    if (t0) {
        t1 = l1.payload.obj;
        l2 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_span;
        for (;;) {
            t2 = vader_parser_match_kind(l0, (uint8_t) 41);
            if (!(t2.tag == 0u)) {
                l3 = vader_parser_parse_type_postfix(l0);
                t1 = l3.payload.obj;
                l4 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_span;
                l5 = ((vader_struct_toolchain_span_Span_t*) l2)->f_start;
                l6 = ((vader_struct_toolchain_span_Span_t*) l4)->f_end;
                vader_struct_toolchain_span_Span_t* _a0_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
                vader_obj_header_init(_a0_obj, 524u);
                _a0_obj->f_start = l5;
                _a0_obj->f_end = l6;
                t1 = (void*) _a0_obj;
                vader_struct_toolchain_ast_BinaryExpr_t* _a1_obj = (vader_struct_toolchain_ast_BinaryExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BinaryExpr_t));
                vader_obj_header_init(_a1_obj, 436u);
                _a1_obj->f_span = t1;
                _a1_obj->f_id = (size_t) 0;
                _a1_obj->f_op = (uint8_t) 7;
                _a1_obj->f_left = l1;
                _a1_obj->f_right = l3;
                _a1_obj->f_bind_as = vader_box_obj(0u, NULL);
                t1 = (void*) _a1_obj;
                l1 = vader_ref_box(t1);
                continue;
            }
            break;
        }
    }
    { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_type_list_until_angle(void* l0) {
    void* l1 = NULL;
    vader_box_t l2 = vader_box_null();
    bool t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l2, &t1 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(175u, 0u, 13u, 1241u);
    l1 = (void*) _a0_arr;
    vader_parser_skip_newlines(l0);
    t0 = vader_parser_check_closing_angle(l0);
    if (t0) {
        vader_parser_consume_closing_angle(l0);
        { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    for (;;) {
        vader_parser_skip_newlines(l0);
        t0 = vader_parser_check_closing_angle(l0);
        if (!(t0)) {
            l2 = vader_parser_parse_type(l0);
            vader_array_push((vader_array_t*) l1, l2);
            vader_parser_skip_newlines(l0);
            t1 = vader_parser_match_kind(l0, (uint8_t) 80);
            if (t1.tag == 0u) break;
            continue;
        }
        break;
    }
    t0 = vader_parser_check_closing_angle(l0);
    if (t0) {
        vader_parser_consume_closing_angle(l0);
        { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_parser_expect(l0, (uint8_t) 51, 1086u);
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_parser_parse_type_mut_marker(void* l0) {
    void* l1 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    vader_string_t l2 = 0;
    size_t l3;
    int32_t l4, l5;
    bool t0;
    void* t1 = NULL;
    size_t t2;
    int64_t t3;
    int32_t t4;
    void** gc_raw_roots[6] = { &l0, &l1, &l6, &l7, &l8, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_parser_check(l0, (uint8_t) 57);
    if (t0) {
        t1 = vader_parser_advance(l0);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_parser_check(l0, (uint8_t) 48);
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l1 = vader_parser_peek(l0);
    l2 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l1)->f_span)->f_start)->f_file;
    t2 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l1)->f_span)->f_start)->f_offset;
    t3 = (t2 + INT64_C(1));
    l3 = (size_t) (int64_t) t3;
    l4 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l1)->f_span)->f_start)->f_line;
    t4 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l1)->f_span)->f_start)->f_column;
    l5 = (t4 + INT32_C(1));
    vader_struct_toolchain_span_Position_t* _a0_obj = (vader_struct_toolchain_span_Position_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Position_t));
    vader_obj_header_init(_a0_obj, 523u);
    _a0_obj->f_file = l2;
    _a0_obj->f_offset = l3;
    _a0_obj->f_line = l4;
    _a0_obj->f_column = l5;
    l6 = (void*) _a0_obj;
    l7 = ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens;
    t4 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pos;
    t3 = ((int64_t) (int32_t) t4);
    l3 = (size_t) (int64_t) t3;
    l8 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l1)->f_span)->f_end;
    vader_struct_toolchain_span_Span_t* _a1_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a1_obj, 524u);
    _a1_obj->f_start = l6;
    _a1_obj->f_end = l8;
    l8 = (void*) _a1_obj;
    vader_struct_vader_lexer_Token_t* _a2_obj = (vader_struct_vader_lexer_Token_t*) vader_gc_alloc(sizeof(vader_struct_vader_lexer_Token_t));
    vader_obj_header_init(_a2_obj, 802u);
    _a2_obj->f_kind = (uint8_t) 59;
    _a2_obj->f_text = 390u;
    _a2_obj->f_span = l8;
    _a2_obj->f_value = vader_box_obj(0u, NULL);
    l8 = (void*) _a2_obj;
    vader_array_t* _a3_slotarr = ((vader_array_t*) l7);
    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l3)
    vader_array_ref_store(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l3, l8);
    VADER_WRITE_BARRIER(_a3_slotarr->buf);
    vader_struct_toolchain_span_Span_t* _a4_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a4_obj, 524u);
    _a4_obj->f_start = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l1)->f_span)->f_start;
    _a4_obj->f_end = l6;
    l1 = (void*) _a4_obj;
    vader_struct_vader_lexer_Token_t* _a5_obj = (vader_struct_vader_lexer_Token_t*) vader_gc_alloc(sizeof(vader_struct_vader_lexer_Token_t));
    vader_obj_header_init(_a5_obj, 802u);
    _a5_obj->f_kind = (uint8_t) 57;
    _a5_obj->f_text = 174u;
    _a5_obj->f_span = l1;
    _a5_obj->f_value = vader_box_obj(0u, NULL);
    t1 = (void*) _a5_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_parser_parse_type_postfix(void* l0) {
    vader_box_t l1 = vader_box_null(), l6 = vader_box_null(), l11 = vader_box_null();
    void* l2 = NULL;
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
    void** gc_raw_roots[10] = { &l0, &l2, &l3, &l4, &l5, &l7, &l8, &l9, &l10, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 10u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_parse_type_primary(l0);
    for (;;) {
        t0 = vader_parser_check(l0, (uint8_t) 76);
        if (t0) {
            t0 = vader_parser_check_at(l0, (uint8_t) 77, INT32_C(1));
            if (t0) {
                vader_parser_advance(l0);
                l2 = vader_parser_advance(l0);
                t1 = l1.payload.obj;
                l3 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_span)->f_start;
                l4 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l2)->f_span)->f_end;
                vader_struct_toolchain_span_Span_t* _a0_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
                vader_obj_header_init(_a0_obj, 524u);
                _a0_obj->f_start = l3;
                _a0_obj->f_end = l4;
                t1 = (void*) _a0_obj;
                vader_struct_toolchain_ast_ArrayTypeExpr_t* _a1_obj = (vader_struct_toolchain_ast_ArrayTypeExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ArrayTypeExpr_t));
                vader_obj_header_init(_a1_obj, 431u);
                _a1_obj->f_span = t1;
                _a1_obj->f_id = (size_t) 0;
                _a1_obj->f_element = l1;
                t1 = (void*) _a1_obj;
                l1 = vader_ref_box(t1);
                continue;
            }
        }
        l6 = vader_parser_parse_type_mut_marker(l0);
        if (l6.tag == 0u) {
            { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l5 = l6.payload.obj;
        if (l1.tag == 485u) {
            l7 = ((vader_struct_vader_lexer_Token_t*) l5)->f_span;
            vader_parser_error(l0, (uint8_t) 26, l7, 1035u);
            continue;
        }
        t1 = l1.payload.obj;
        l8 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_span)->f_start;
        l9 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l5)->f_span)->f_end;
        vader_struct_toolchain_span_Span_t* _a2_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
        vader_obj_header_init(_a2_obj, 524u);
        _a2_obj->f_start = l8;
        _a2_obj->f_end = l9;
        l10 = (void*) _a2_obj;
        l11 = l1;
        vader_struct_toolchain_ast_MutableTypeExpr_t* _a3_obj = (vader_struct_toolchain_ast_MutableTypeExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_MutableTypeExpr_t));
        vader_obj_header_init(_a3_obj, 485u);
        _a3_obj->f_span = l10;
        _a3_obj->f_id = (size_t) 0;
        _a3_obj->f_inner = l11;
        _a3_obj->f_deduced = false;
        t1 = (void*) _a3_obj;
        l1 = vader_ref_box(t1);
        continue;
    }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_parser_parse_type_primary(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    vader_string_t l4 = 0;
    vader_string_t l10 = 0;
    vader_box_t l5 = vader_box_null();
    int32_t l9;
    void* t0 = NULL;
    bool t1;
    vader_box_t t2 = vader_box_null();
    size_t t3;
    vader_box_t* gc_roots[2] = { &l5, &t2 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l6, &l7, &l8, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l4, &l10 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_peek(l0);
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(73)) {
        vader_parser_advance(l0);
        l2 = vader_parser_expect(l0, (uint8_t) 2, 2352u);
        l3 = vader_parser_span_of(l0, l1, l2);
        l4 = ((vader_struct_vader_lexer_Token_t*) l2)->f_text;
        vader_struct_toolchain_ast_IdentExpr_t* _a0_obj = (vader_struct_toolchain_ast_IdentExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_IdentExpr_t));
        vader_obj_header_init(_a0_obj, 466u);
        _a0_obj->f_span = l3;
        _a0_obj->f_id = (size_t) 0;
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
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(74)) {
        vader_parser_advance(l0);
        vader_parser_skip_newlines(l0);
        l5 = vader_parser_parse_type(l0);
        vader_parser_skip_newlines(l0);
        vader_parser_expect(l0, (uint8_t) 75, 1054u);
        { vader_box_t __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(76)) {
        l2 = vader_parser_advance(l0);
        vader_array_t* _a1_arr = vader_array_new(175u, 0u, 13u, 1241u);
        l3 = (void*) _a1_arr;
        vader_parser_skip_newlines(l0);
        t1 = vader_parser_check(l0, (uint8_t) 77);
        if (t1) {
            l6 = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
            vader_parser_error(l0, (uint8_t) 4, l6, 1537u);
            l6 = vader_parser_advance(l0);
            t0 = vader_parser_span_of(l0, l2, l6);
            vader_struct_toolchain_ast_SeqLitExpr_t* _a2_obj = (vader_struct_toolchain_ast_SeqLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_SeqLitExpr_t));
            vader_obj_header_init(_a2_obj, 500u);
            _a2_obj->f_span = t0;
            _a2_obj->f_id = (size_t) 0;
            _a2_obj->f_elements = l3;
            _a2_obj->f_trailing_comma = false;
            t0 = (void*) _a2_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l5 = vader_parser_parse_type(l0);
        vader_array_push((vader_array_t*) l3, l5);
        vader_parser_skip_newlines(l0);
        for (;;) {
            t2 = vader_parser_match_kind(l0, (uint8_t) 80);
            if (!(t2.tag == 0u)) {
                vader_parser_skip_newlines(l0);
                t1 = vader_parser_check(l0, (uint8_t) 77);
                if (t1) break;
                l5 = vader_parser_parse_type(l0);
                vader_array_push((vader_array_t*) l3, l5);
                vader_parser_skip_newlines(l0);
                continue;
            }
            break;
        }
        l6 = vader_parser_expect(l0, (uint8_t) 77, 1119u);
        t3 = ((vader_array_t*) l3)->length;
        if (!(t3 == INT64_C(1))) {
            t0 = vader_parser_span_of(l0, l2, l6);
            vader_struct_toolchain_ast_SeqLitExpr_t* _a3_obj = (vader_struct_toolchain_ast_SeqLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_SeqLitExpr_t));
            vader_obj_header_init(_a3_obj, 500u);
            _a3_obj->f_span = t0;
            _a3_obj->f_id = (size_t) 0;
            _a3_obj->f_elements = l3;
            _a3_obj->f_trailing_comma = false;
            t0 = (void*) _a3_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = vader_parser_span_of(l0, l2, l6);
        vader_parser_error(l0, (uint8_t) 20, l7, 2441u);
        l2 = vader_parser_span_of(l0, l2, l6);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, INT32_C(0))
        l5 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) INT32_C(0));
        vader_struct_toolchain_ast_ArrayTypeExpr_t* _a5_obj = (vader_struct_toolchain_ast_ArrayTypeExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ArrayTypeExpr_t));
        vader_obj_header_init(_a5_obj, 431u);
        _a5_obj->f_span = l2;
        _a5_obj->f_id = (size_t) 0;
        _a5_obj->f_element = l5;
        t0 = (void*) _a5_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(33)) {
        vader_parser_advance(l0);
        t0 = vader_parser_ident_expr(((vader_struct_vader_lexer_Token_t*) l1)->f_span, 2032u);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(2))) {
        l8 = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
        l10 = vader_parser_describe_token(l1);
        l10 = concat_2(1720u, l10);
        vader_parser_error(l0, (uint8_t) 4, l8, l10);
        vader_parser_advance(l0);
        t0 = vader_parser_ident_expr(((vader_struct_vader_lexer_Token_t*) l1)->f_span, 399u);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = vader_parser_advance(l0);
    l2 = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
    l4 = ((vader_struct_vader_lexer_Token_t*) l1)->f_text;
    t0 = vader_parser_ident_expr(l2, l4);
    l5 = vader_ref_box(t0);
    for (;;) {
        t1 = vader_parser_check(l0, (uint8_t) 81);
        if (t1) {
            vader_parser_advance(l0);
            l2 = vader_parser_expect(l0, (uint8_t) 2, 1651u);
            t0 = l5.payload.obj;
            l3 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t0)->f_span)->f_start;
            l6 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l2)->f_span)->f_end;
            vader_struct_toolchain_span_Span_t* _a6_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
            vader_obj_header_init(_a6_obj, 524u);
            _a6_obj->f_start = l3;
            _a6_obj->f_end = l6;
            l7 = (void*) _a6_obj;
            l4 = ((vader_struct_vader_lexer_Token_t*) l2)->f_text;
            l8 = ((vader_struct_vader_lexer_Token_t*) l2)->f_span;
            vader_struct_toolchain_ast_FieldExpr_t* _a7_obj = (vader_struct_toolchain_ast_FieldExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FieldExpr_t));
            vader_obj_header_init(_a7_obj, 459u);
            _a7_obj->f_span = l7;
            _a7_obj->f_id = (size_t) 0;
            _a7_obj->f_target = l5;
            _a7_obj->f_field = l4;
            _a7_obj->f_field_span = l8;
            _a7_obj->f_is_numeric = false;
            t0 = (void*) _a7_obj;
            l5 = vader_ref_box(t0);
            continue;
        }
        break;
    }
    t2 = vader_parser_match_kind(l0, (uint8_t) 49);
    if (!(t2.tag == 0u)) {
        l2 = vader_parser_parse_type_list_until_angle(l0);
        l9 = -(INT32_C(1));
        l3 = vader_parser_peek_at(l0, l9);
        t0 = vader_parser_span_of(l0, l1, l3);
        vader_struct_toolchain_ast_GenericInstExpr_t* _a8_obj = (vader_struct_toolchain_ast_GenericInstExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_GenericInstExpr_t));
        vader_obj_header_init(_a8_obj, 465u);
        _a8_obj->f_span = t0;
        _a8_obj->f_id = (size_t) 0;
        _a8_obj->f_callee = l5;
        _a8_obj->f_type_args = l2;
        t0 = (void*) _a8_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_typed_const_decl(void* l0, void* l1, uint8_t l2) {
    void* l3 = NULL;
    void* l7 = NULL;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    int32_t l6;
    vader_string_t l8 = 0;
    bool t0;
    void* t1 = NULL;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[2] = { &l4, &l5 };
    void** gc_raw_roots[5] = { &l0, &l1, &l3, &l7, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l8, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_parser_reject_target_decorator(l0, l1, 1179u);
    l3 = vader_parser_advance(l0);
    vader_parser_advance(l0);
    l4 = vader_parser_parse_type(l0);
    vader_parser_expect(l0, (uint8_t) 82, 1081u);
    t0 = vader_parser_check(l0, (uint8_t) 72);
    if (t0) {
        t1 = vader_parser_peek_at(l0, INT32_C(1));
        if (((vader_struct_vader_lexer_Token_t*) t1)->f_kind == INT32_C(2)) {
            t1 = vader_parser_peek_at(l0, INT32_C(1));
            t2 = ((vader_struct_vader_lexer_Token_t*) t1)->f_text;
            if (t2 == 1454u) {
                t1 = vader_parser_desugar_comptime_const(l0, l1, l2, l3, l4);
                { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
    }
    l5 = vader_parser_parse_expr(l0, INT32_C(0));
    l6 = -(INT32_C(1));
    l7 = vader_parser_peek_at(l0, l6);
    l7 = vader_parser_span_of(l0, l3, l7);
    l8 = ((vader_struct_vader_lexer_Token_t*) l3)->f_text;
    l3 = ((vader_struct_vader_lexer_Token_t*) l3)->f_span;
    vader_struct_toolchain_ast_ConstDecl_t* _a0_obj = (vader_struct_toolchain_ast_ConstDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ConstDecl_t));
    vader_obj_header_init(_a0_obj, 444u);
    _a0_obj->f_span = l7;
    _a0_obj->f_id = (size_t) 0;
    _a0_obj->f_name = l8;
    _a0_obj->f_name_span = l3;
    _a0_obj->f_visibility = l2;
    _a0_obj->f_ty = l4;
    _a0_obj->f_value = l5;
    _a0_obj->f_decorators = l1;
    _a0_obj->f_comptime_body = vader_box_obj(0u, NULL);
    t1 = (void*) _a0_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_typed_let(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    void* l7 = NULL;
    vader_box_t l2 = vader_box_null(), l5 = vader_box_null();
    bool l4;
    vader_string_t l6 = 0;
    int32_t l8;
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l2, &l5 };
    void** gc_raw_roots[5] = { &l0, &l1, &l3, &l7, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_advance(l0);
    vader_parser_advance(l0);
    l2 = vader_parser_parse_type(l0);
    l3 = vader_parser_peek(l0);
    l4 = true;
    if (((vader_struct_vader_lexer_Token_t*) l3)->f_kind == INT32_C(82)) {
        vader_parser_advance(l0);
        l4 = false;
    } else {
        vader_parser_expect(l0, (uint8_t) 59, 1085u);
    }
    l5 = vader_parser_parse_expr(l0, INT32_C(0));
    l3 = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
    l6 = ((vader_struct_vader_lexer_Token_t*) l1)->f_text;
    l7 = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
    vader_struct_toolchain_ast_SimpleBinding_t* _a0_obj = (vader_struct_toolchain_ast_SimpleBinding_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_SimpleBinding_t));
    vader_obj_header_init(_a0_obj, 501u);
    _a0_obj->f_span = l3;
    _a0_obj->f_id = (size_t) 0;
    _a0_obj->f_name = l6;
    _a0_obj->f_name_span = l7;
    l3 = (void*) _a0_obj;
    l8 = -(INT32_C(1));
    l7 = vader_parser_peek_at(l0, l8);
    t0 = vader_parser_span_of(l0, l1, l7);
    vader_struct_toolchain_ast_LetStmt_t* _a1_obj = (vader_struct_toolchain_ast_LetStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_LetStmt_t));
    vader_obj_header_init(_a1_obj, 480u);
    _a1_obj->f_span = t0;
    _a1_obj->f_id = (size_t) 0;
    _a1_obj->f_mutable = l4;
    _a1_obj->f_binding = vader_ref_box(l3);
    _a1_obj->f_ty = l2;
    _a1_obj->f_value = l5;
    t0 = (void*) _a1_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_yield(void* l0) {
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
    vader_obj_header_init(_a0_obj, 522u);
    _a0_obj->f_span = t0;
    _a0_obj->f_id = (size_t) 0;
    _a0_obj->f_value = l2;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_peek(void* l0) {
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
    if (!((t2 < l2))) {
        l3 = ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens;
        t3 = ((int64_t) (int32_t) (l2 - INT32_C(1)));
        l4 = (size_t) (int64_t) t3;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        return t0;
    }
    l3 = ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens;
    t2 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pos;
    t3 = ((int64_t) (int32_t) t2);
    l4 = (size_t) (int64_t) t3;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
    t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
    return t0;
}

static void* vader_parser_peek_at(void* l0, int32_t l1) {
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
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
        t2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
        return t2;
    }
    if (!((l3 < l2))) {
        l4 = ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens;
        t3 = ((int64_t) (int32_t) (l2 - INT32_C(1)));
        l5 = (size_t) (int64_t) t3;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        t2 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
        return t2;
    }
    l4 = ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens;
    t3 = ((int64_t) (int32_t) l3);
    l5 = (size_t) (int64_t) t3;
    vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
    t2 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
    return t2;
}

static bool vader_parser_peek_is_classic_impl_body(void* l0) {
    int32_t l1, l4;
    bool l2;
    uint8_t l3, l5;
    void* t0;
    l1 = INT32_C(1);
    for (;;) {
        t0 = vader_parser_peek_at(l0, l1);
        if (((vader_struct_vader_lexer_Token_t*) t0)->f_kind == INT32_C(1)) {
            l1 = (l1 + INT32_C(1));
            continue;
        }
        break;
    }
    l2 = true;
    while (l2) {
        t0 = vader_parser_peek_at(l0, l1);
        l3 = ((vader_struct_vader_lexer_Token_t*) t0)->f_kind;
        if (l3 == INT32_C(72)) {
            l1 = (l1 + INT32_C(1));
            t0 = vader_parser_peek_at(l0, l1);
            if (((vader_struct_vader_lexer_Token_t*) t0)->f_kind == INT32_C(2)) {
                l1 = (l1 + INT32_C(1));
            }
            t0 = vader_parser_peek_at(l0, l1);
            if (((vader_struct_vader_lexer_Token_t*) t0)->f_kind == INT32_C(74)) {
                l4 = INT32_C(1);
                l1 = (l1 + INT32_C(1));
                while ((l4 > INT32_C(0))) {
                    t0 = vader_parser_peek_at(l0, l1);
                    if (!(((vader_struct_vader_lexer_Token_t*) t0)->f_kind != INT32_C(0))) {
                        break;
                    }
                    t0 = vader_parser_peek_at(l0, l1);
                    l5 = ((vader_struct_vader_lexer_Token_t*) t0)->f_kind;
                    if (l5 == INT32_C(74)) {
                        l4 = (l4 + INT32_C(1));
                    }
                    if (l5 == INT32_C(75)) {
                        l4 = (l4 - INT32_C(1));
                    }
                    l1 = (l1 + INT32_C(1));
                }
            }
            for (;;) {
                t0 = vader_parser_peek_at(l0, l1);
                if (((vader_struct_vader_lexer_Token_t*) t0)->f_kind == INT32_C(1)) {
                    l1 = (l1 + INT32_C(1));
                    continue;
                }
                break;
            }
            continue;
        }
        if (l3 == INT32_C(30)) {
            l1 = (l1 + INT32_C(1));
            for (;;) {
                t0 = vader_parser_peek_at(l0, l1);
                if (((vader_struct_vader_lexer_Token_t*) t0)->f_kind == INT32_C(1)) {
                    l1 = (l1 + INT32_C(1));
                    continue;
                }
                break;
            }
        } else {
            l2 = false;
        }
    }
    t0 = vader_parser_peek_at(l0, l1);
    if (((vader_struct_vader_lexer_Token_t*) t0)->f_kind == INT32_C(2)) {
        l4 = (l1 + INT32_C(1));
        t0 = vader_parser_peek_at(l0, l4);
        l2 = ((vader_struct_vader_lexer_Token_t*) t0)->f_kind == INT32_C(65);
    } else {
        l2 = false;
    }
    if (l2) {
        l1 = (l1 + INT32_C(2));
        t0 = vader_parser_peek_at(l0, l1);
        return ((vader_struct_vader_lexer_Token_t*) t0)->f_kind == INT32_C(11);
    }
    return false;
}

static bool vader_parser_peek_is_lhs_generic_alias_head(void* l0) {
    int32_t l1, l2, l3, l4;
    void* l5;
    void* l7;
    void* l10;
    void* l13;
    size_t l6, l11, l14;
    bool l8, l9, l12, l15, l16, l17, l18;
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
    while ((l4 < l1)) {
        l5 = ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens;
        t2 = ((int64_t) (int32_t) l4);
        l6 = (size_t) (int64_t) t2;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
        l7 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
        if (((vader_struct_vader_lexer_Token_t*) l7)->f_kind == INT32_C(0)) {
            return false;
        }
        if (((vader_struct_vader_lexer_Token_t*) l7)->f_kind == INT32_C(1)) {
            return false;
        }
        if (((vader_struct_vader_lexer_Token_t*) l7)->f_kind == INT32_C(49)) {
            l8 = l3 == INT32_C(0);
        } else {
            l8 = false;
        }
        if (l8) {
            l2 = (l2 + INT32_C(1));
        } else {
            if (((vader_struct_vader_lexer_Token_t*) l7)->f_kind == INT32_C(51)) {
                l9 = l3 == INT32_C(0);
            } else {
                l9 = false;
            }
            if (l9) {
                l2 = (l2 - INT32_C(1));
                if (l2 == INT32_C(0)) {
                    if (!(((l4 + INT32_C(1)) < l1))) {
                        return false;
                    }
                    l10 = ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens;
                    t2 = ((int64_t) (int32_t) (l4 + INT32_C(1)));
                    l11 = (size_t) (int64_t) t2;
                    vader_array_t* _a1_slotarr = ((vader_array_t*) l10);
                    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l11)
                    t3 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l11);
                    return ((vader_struct_vader_lexer_Token_t*) t3)->f_kind == INT32_C(65);
                }
            } else {
                if (((vader_struct_vader_lexer_Token_t*) l7)->f_kind == INT32_C(46)) {
                    l12 = l3 == INT32_C(0);
                } else {
                    l12 = false;
                }
                if (l12) {
                    l2 = (l2 - INT32_C(2));
                    if (l2 == INT32_C(0)) {
                        if (!(((l4 + INT32_C(1)) < l1))) {
                            return false;
                        }
                        l13 = ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens;
                        t2 = ((int64_t) (int32_t) (l4 + INT32_C(1)));
                        l14 = (size_t) (int64_t) t2;
                        vader_array_t* _a2_slotarr = ((vader_array_t*) l13);
                        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l14)
                        t3 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l14);
                        return ((vader_struct_vader_lexer_Token_t*) t3)->f_kind == INT32_C(65);
                    }
                    if ((l2 < INT32_C(0))) {
                        return false;
                    }
                } else {
                    if (((vader_struct_vader_lexer_Token_t*) l7)->f_kind == INT32_C(74)) {
                        l15 = true;
                    } else {
                        l15 = ((vader_struct_vader_lexer_Token_t*) l7)->f_kind == INT32_C(76);
                    }
                    if (l15) {
                        l16 = true;
                    } else {
                        l16 = ((vader_struct_vader_lexer_Token_t*) l7)->f_kind == INT32_C(78);
                    }
                    if (l16) {
                        l3 = (l3 + INT32_C(1));
                    } else {
                        if (((vader_struct_vader_lexer_Token_t*) l7)->f_kind == INT32_C(75)) {
                            l17 = true;
                        } else {
                            l17 = ((vader_struct_vader_lexer_Token_t*) l7)->f_kind == INT32_C(77);
                        }
                        if (l17) {
                            l18 = true;
                        } else {
                            l18 = ((vader_struct_vader_lexer_Token_t*) l7)->f_kind == INT32_C(79);
                        }
                        if (l18) {
                            l3 = (l3 - INT32_C(1));
                            if ((l3 < INT32_C(0))) {
                                return false;
                            }
                        }
                    }
                }
            }
        }
        l4 = (l4 + INT32_C(1));
    }
    return false;
}

static bool vader_parser_peek_lambda_without_fn(void* l0) {
    int32_t l1, l2;
    uint8_t l3;
    void* t0;
    t0 = vader_parser_peek(l0);
    if (((vader_struct_vader_lexer_Token_t*) t0)->f_kind != INT32_C(74)) {
        return false;
    }
    l1 = INT32_C(1);
    l2 = INT32_C(1);
    while ((l1 > INT32_C(0))) {
        t0 = vader_parser_peek_at(l0, l2);
        l3 = ((vader_struct_vader_lexer_Token_t*) t0)->f_kind;
        if (l3 == INT32_C(0)) {
            return false;
        }
        if (l3 == INT32_C(74)) {
            l1 = (l1 + INT32_C(1));
        } else if (l3 == INT32_C(75)) {
            l1 = (l1 - INT32_C(1));
            if (l1 == INT32_C(0)) break;
        }
        l2 = (l2 + INT32_C(1));
    }
    l2 = (l2 + INT32_C(1));
    for (;;) {
        t0 = vader_parser_peek_at(l0, l2);
        if (((vader_struct_vader_lexer_Token_t*) t0)->f_kind == INT32_C(1)) {
            l2 = (l2 + INT32_C(1));
            continue;
        }
        break;
    }
    t0 = vader_parser_peek_at(l0, l2);
    return ((vader_struct_vader_lexer_Token_t*) t0)->f_kind == INT32_C(70);
}

static int32_t vader_parser_postfix_bp(uint8_t l0) {
    int32_t l1;
    if (l0 == INT32_C(74)) {
        l1 = INT32_C(100);
        return l1;
    }
    if (l0 == INT32_C(76)) {
        l1 = INT32_C(100);
    } else if (l0 == INT32_C(81)) {
        l1 = INT32_C(100);
    } else if (l0 == INT32_C(35)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(0)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(1)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(2)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(3)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(4)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(5)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(6)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(7)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(8)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(9)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(10)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(36)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(37)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(38)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(39)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(40)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(41)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(42)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(43)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(44)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(45)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(46)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(47)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(48)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(53)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(54)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(49)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(50)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(51)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(52)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(55)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(56)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(58)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(57)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(59)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(60)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(61)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(62)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(63)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(64)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(65)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(66)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(67)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(68)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(69)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(70)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(71)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(72)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(73)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(75)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(77)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(78)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(79)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(80)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(82)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(11)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(12)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(13)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(14)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(15)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(16)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(17)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(18)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(19)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(20)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(21)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(22)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(23)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(24)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(25)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(26)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(27)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(28)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(29)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(30)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(31)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(32)) {
        l1 = -(INT32_C(1));
    } else if (l0 == INT32_C(33)) {
        l1 = -(INT32_C(1));
    } else {
        if (!(l0 == INT32_C(34))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = -(INT32_C(1));
    }
    return l1;
}

static void vader_parser_reject_arm_binding(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    vader_box_t l2 = vader_box_null();
    vader_string_t l4 = 0;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[3] = { &l0, &l1, &l3 };
    vader_string_t* gc_atom_roots[1] = { &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_parser_match_kind(l0, (uint8_t) 29);
    if (l2.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l1 = l2.payload.obj;
    l3 = vader_parser_expect(l0, (uint8_t) 2, 1312u);
    if (((vader_struct_vader_lexer_Token_t*) l3)->f_kind == INT32_C(2)) {
        l1 = vader_parser_span_of(l0, l1, l3);
        l4 = ((vader_struct_vader_lexer_Token_t*) l3)->f_text;
        l4 = concat_3(1998u, l4, 850u);
        vader_parser_error(l0, (uint8_t) 31, l1, l4);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_parser_reject_c_decorators(void* l0, void* l1, vader_string_t l2) {
    void* l3 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    void* l11 = NULL;
    size_t l4, l5;
    bool l7;
    vader_string_t l9 = 0;
    vader_string_t l10 = 0;
    vader_string_t l12 = 0;
    vader_string_t t0 = 0;
    int64_t t1;
    void** gc_raw_roots[6] = { &l0, &l1, &l3, &l6, &l8, &l11 };
    vader_string_t* gc_atom_roots[5] = { &l2, &l9, &l10, &l12, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = l1;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        l6 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        t0 = ((vader_struct_toolchain_ast_Decorator_t*) l6)->f_name;
        if (t0 == 1392u) {
            l7 = true;
        } else {
            t0 = ((vader_struct_toolchain_ast_Decorator_t*) l6)->f_name;
            l7 = t0 == 1391u;
        }
        if (l7) {
            l8 = ((vader_struct_toolchain_ast_Decorator_t*) l6)->f_span;
            l9 = ((vader_struct_toolchain_ast_Decorator_t*) l6)->f_name;
            l10 = concat_4(1091u, l9, 881u, l2);
            vader_parser_error(l0, (uint8_t) 13, l8, l10);
        }
        t0 = ((vader_struct_toolchain_ast_Decorator_t*) l6)->f_name;
        if (t0 == 1393u) {
            l11 = ((vader_struct_toolchain_ast_Decorator_t*) l6)->f_span;
            l12 = concat_2(1097u, l2);
            vader_parser_error(l0, (uint8_t) 13, l11, l12);
        }
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_parser_reject_displayable_decorator(void* l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    size_t l3, l4;
    vader_string_t t0 = 0;
    int64_t t1;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l5, &l6 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = l1;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t0 = ((vader_struct_toolchain_ast_Decorator_t*) l5)->f_name;
        if (t0 == 1516u) {
            l6 = ((vader_struct_toolchain_ast_Decorator_t*) l5)->f_span;
            vader_parser_error(l0, (uint8_t) 13, l6, 1104u);
        }
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_parser_reject_removed_const(void* l0) {
    vader_box_t l1 = vader_box_null();
    void* l2 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_match_kind(l0, (uint8_t) 35);
    if (l1.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = l1.payload.obj;
    l2 = ((vader_struct_vader_lexer_Token_t*) t0)->f_span;
    vader_parser_error(l0, (uint8_t) 23, l2, 1213u);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_parser_reject_target_decorator(void* l0, void* l1, vader_string_t l2) {
    void* l3 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    size_t l4, l5;
    vader_string_t l8 = 0;
    vader_string_t t0 = 0;
    int64_t t1;
    void** gc_raw_roots[5] = { &l0, &l1, &l3, &l6, &l7 };
    vader_string_t* gc_atom_roots[3] = { &l2, &l8, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = l1;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        l6 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        t0 = ((vader_struct_toolchain_ast_Decorator_t*) l6)->f_name;
        if (t0 == 2290u) {
            l7 = ((vader_struct_toolchain_ast_Decorator_t*) l6)->f_span;
            l8 = concat_2(1115u, l2);
            vader_parser_error(l0, (uint8_t) 13, l7, l8);
        }
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_parser_reject_tuple_pattern(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    int32_t l2;
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_advance(l0);
    l2 = INT32_C(1);
    l3 = l1;
    while ((l2 > INT32_C(0))) {
        t0 = vader_parser_check(l0, (uint8_t) 0);
        if (t0) break;
        l3 = vader_parser_advance(l0);
        if (((vader_struct_vader_lexer_Token_t*) l3)->f_kind == INT32_C(76)) {
            l2 = (l2 + INT32_C(1));
        }
        if (!(((vader_struct_vader_lexer_Token_t*) l3)->f_kind == INT32_C(77))) {
            continue;
        }
        l2 = (l2 - INT32_C(1));
    }
    l1 = vader_parser_span_of(l0, l1, l3);
    vader_parser_error(l0, (uint8_t) 21, l1, 2296u);
    vader_struct_toolchain_ast_WildcardPattern_t* _a0_obj = (vader_struct_toolchain_ast_WildcardPattern_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_WildcardPattern_t));
    vader_obj_header_init(_a0_obj, 520u);
    _a0_obj->f_span = l1;
    _a0_obj->f_id = (size_t) 0;
    t1 = (void*) _a0_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_parser_report_nesting_too_deep(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    vader_string_t l4 = 0;
    size_t l5;
    int64_t l7;
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[5] = { &l0, &l2, &l3, &l6, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_parser_Parser_t*) l0)->f_depth_exceeded;
    if (t0) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l2 = ((vader_struct_vader_parser_Parser_t*) l0)->f_errors;
    t1 = vader_parser_peek(l0);
    l3 = ((vader_struct_vader_lexer_Token_t*) t1)->f_span;
    l4 = l1;
    l5 = vader_host_std_core_byte_len(l4);
    l6 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(50) + l5));
    l5 = (size_t) 0;
    l5 = std_core_write_string_at(l6, l5, l4);
    l5 = std_core_write_string_at(l6, l5, 105u);
    l7 = ((int64_t) 256);
    l5 = std_core_write_int(l6, l5, l7);
    l5 = std_core_write_string_at(l6, l5, 100u);
    l4 = std_core_finish_buffer(l6, l5);
    l3 = vader_diagnostics_parser_error((uint8_t) 25, l3, l4);
    vader_array_push((vader_array_t*) l2, vader_ref_box(l3));
    ((vader_struct_vader_parser_Parser_t*) l0)->f_depth_exceeded = true;
    for (;;) {
        t0 = vader_parser_check(l0, (uint8_t) 1);
        if (!(t0)) {
            t0 = vader_parser_check(l0, (uint8_t) 0);
            if (t0) break;
            vader_parser_advance(l0);
            continue;
        }
        break;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_parser_scan_angle_generic(void* l0, int32_t l1) {
    int32_t l2, l5, l6, l7, l8;
    void* l3;
    void* l9;
    void* l11;
    void* l14;
    size_t l4, l12, l15;
    bool l10;
    uint8_t l13, l16;
    size_t t0;
    int64_t t1;
    void* t2;
    bool t3;
    t0 = ((vader_array_t*) ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens)->length;
    l2 = ((int32_t) (size_t) t0);
    if ((l1 >= l2)) {
        return false;
    }
    l3 = ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens;
    t1 = ((int64_t) (int32_t) l1);
    l4 = (size_t) (int64_t) t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    t2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
    if (((vader_struct_vader_lexer_Token_t*) t2)->f_kind != INT32_C(49)) {
        return false;
    }
    l5 = INT32_C(1);
    l6 = INT32_C(0);
    l7 = INT32_C(0);
    l8 = (l1 + INT32_C(1));
    while ((l8 < l2)) {
        l3 = ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens;
        t1 = ((int64_t) (int32_t) l8);
        l4 = (size_t) (int64_t) t1;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        l9 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        if (((vader_struct_vader_lexer_Token_t*) l9)->f_kind == INT32_C(0)) {
            return false;
        }
        if (l6 == INT32_C(0)) {
            l10 = l7 == INT32_C(0);
        } else {
            l10 = false;
        }
        if (((vader_struct_vader_lexer_Token_t*) l9)->f_kind == INT32_C(1)) {
            if (l10) {
                return false;
            }
        }
        if (l10) {
            t3 = vader_parser_is_angle_scan_bailout(((vader_struct_vader_lexer_Token_t*) l9)->f_kind);
            if (t3) {
                return false;
            }
        }
        if (l10) {
            if (((vader_struct_vader_lexer_Token_t*) l9)->f_kind == INT32_C(49)) {
                l5 = (l5 + INT32_C(1));
            } else if (((vader_struct_vader_lexer_Token_t*) l9)->f_kind == INT32_C(51)) {
                l5 = (l5 - INT32_C(1));
                if (l5 == INT32_C(0)) {
                    if (((l8 + INT32_C(1)) >= l2)) {
                        return false;
                    }
                    l11 = ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens;
                    t1 = ((int64_t) (int32_t) (l8 + INT32_C(1)));
                    l12 = (size_t) (int64_t) t1;
                    vader_array_t* _a2_slotarr = ((vader_array_t*) l11);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l12)
                    t2 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l12);
                    l13 = ((vader_struct_vader_lexer_Token_t*) t2)->f_kind;
                    if (l13 == INT32_C(74)) {
                        return true;
                    }
                    return l13 == INT32_C(78);
                }
            } else if (((vader_struct_vader_lexer_Token_t*) l9)->f_kind == INT32_C(46)) {
                l5 = (l5 - INT32_C(2));
                if (l5 == INT32_C(0)) {
                    if (((l8 + INT32_C(1)) >= l2)) {
                        return false;
                    }
                    l14 = ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens;
                    t1 = ((int64_t) (int32_t) (l8 + INT32_C(1)));
                    l15 = (size_t) (int64_t) t1;
                    vader_array_t* _a3_slotarr = ((vader_array_t*) l14);
                    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l15)
                    t2 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l15);
                    l16 = ((vader_struct_vader_lexer_Token_t*) t2)->f_kind;
                    if (l16 == INT32_C(74)) {
                        return true;
                    }
                    return l16 == INT32_C(78);
                }
                if ((l5 < INT32_C(0))) {
                    return false;
                }
            }
        }
        if (((vader_struct_vader_lexer_Token_t*) l9)->f_kind == INT32_C(74)) {
            l6 = (l6 + INT32_C(1));
        } else if (((vader_struct_vader_lexer_Token_t*) l9)->f_kind == INT32_C(75)) {
            if (l6 == INT32_C(0)) {
                return false;
            }
            l6 = (l6 - INT32_C(1));
        } else if (((vader_struct_vader_lexer_Token_t*) l9)->f_kind == INT32_C(76)) {
            l7 = (l7 + INT32_C(1));
        } else if (((vader_struct_vader_lexer_Token_t*) l9)->f_kind == INT32_C(77)) {
            if (l7 == INT32_C(0)) {
                return false;
            }
            l7 = (l7 - INT32_C(1));
        }
        l8 = (l8 + INT32_C(1));
    }
    return false;
}

static size_t vader_parser_skip_block_comment(void* l0, size_t l1, size_t l2) {
    size_t l3, l6;
    int32_t l4;
    uint8_t l5, l7;
    vader_box_t t0;
    int64_t t1;
    l3 = l1;
    l4 = INT32_C(1);
    while (((l3 + INT64_C(1)) < l2)) {
        if (!((l4 > INT32_C(0)))) {
            break;
        }
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l3, 246u);
        l5 = ((uint8_t) t0.payload.i);
        t1 = (l3 + INT64_C(1));
        l6 = (size_t) (int64_t) t1;
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
        t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l6, 246u);
        l7 = ((uint8_t) t0.payload.i);
        if (l5 == INT32_C(47)) {
            if (l7 == INT32_C(42)) {
                l4 = (l4 + INT32_C(1));
                t1 = (l3 + INT64_C(2));
                l3 = (size_t) (int64_t) t1;
                continue;
            }
        }
        if (l5 == INT32_C(42)) {
            if (l7 == INT32_C(47)) {
                l4 = (l4 - INT32_C(1));
                t1 = (l3 + INT64_C(2));
                l3 = (size_t) (int64_t) t1;
                continue;
            }
        }
        t1 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t1;
    }
    return l3;
}

static void vader_parser_skip_newlines(void* l0) {
    int32_t l1;
    bool t0;
    int32_t t1;
    for (;;) {
        t0 = vader_parser_check(l0, (uint8_t) 1);
        if (t0) {
            t1 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pos;
            l1 = (t1 + INT32_C(1));
            ((vader_struct_vader_parser_Parser_t*) l0)->f_pos = l1;
            continue;
        }
        break;
    }
    return;
}

static size_t vader_parser_skip_to_eol(void* l0, size_t l1, size_t l2) {
    size_t l3;
    vader_box_t t0;
    uint8_t t1;
    int64_t t2;
    l3 = l1;
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l3, 246u);
        t1 = ((uint8_t) t0.payload.i);
        if (!(t1 != INT32_C(10))) {
            break;
        }
        t2 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t2;
    }
    if ((l3 < l2)) {
        t2 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t2;
        return l3;
    }
    return l3;
}

static void* vader_parser_span_of(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l1)->f_span)->f_start;
    l4 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l2)->f_span)->f_end;
    vader_struct_toolchain_span_Span_t* _a0_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a0_obj, 524u);
    _a0_obj->f_start = l3;
    _a0_obj->f_end = l4;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_parser_sync_to_top_level(void* l0) {
    void* t0;
    bool t1;
    for (;;) {
        t0 = vader_parser_peek(l0);
        if (((vader_struct_vader_lexer_Token_t*) t0)->f_kind != INT32_C(0)) {
            t1 = vader_parser_at_top_level_start(l0);
            if (t1) break;
            vader_parser_advance(l0);
            continue;
        }
        break;
    }
    return;
}

static void vader_parser_walk_assign_target(vader_box_t l0, void* l1) {
    void* l2;
    size_t l3;
    void* t0;
    if ((l0.tag == 493u || l0.tag == 498u)) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_PlaceTarget_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_PlaceTarget_t*) t0)->f_place, l1);
        return;
    }
    if (!(l0.tag == 521u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    l2 = l0.payload.obj;
    l3 = vader_parser_mint(l1);
    ((vader_struct_toolchain_ast_WildcardTarget_t*) l2)->f_id = l3;
    return;
}

static void vader_parser_walk_block(void* l0, void* l1) {
    size_t l2, l4;
    void* l3;
    vader_box_t t0;
    int64_t t1;
    l2 = vader_parser_mint(l1);
    ((vader_struct_toolchain_ast_BlockExpr_t*) l0)->f_id = l2;
    l3 = ((vader_struct_toolchain_ast_BlockExpr_t*) l0)->f_stmts;
    l2 = ((vader_array_t*) l3)->length;
    l4 = (size_t) 0;
    while ((l4 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        vader_parser_walk_stmt(t0, l1);
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    if (((vader_struct_toolchain_ast_BlockExpr_t*) l0)->f_trailing.tag == 0u) {
        return;
    }
    vader_parser_walk_expr(((vader_struct_toolchain_ast_BlockExpr_t*) l0)->f_trailing, l1);
    return;
}

static void vader_parser_walk_decl(vader_box_t l0, void* l1) {
    void* l2;
    void* l5;
    size_t l3, l4, l6;
    void* t0;
    int64_t t1;
    vader_box_t t2;
    if (l0.tag == 471u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_ImportDecl_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_parser_walk_import_binding(((vader_struct_toolchain_ast_ImportDecl_t*) t0)->f_binding, l1);
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_ImportDecl_t*) t0)->f_decorators;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) 0;
        while ((l4 < l3)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
            t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
            vader_parser_walk_decorator(t0, l1);
            t1 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t1;
        }
    } else if (l0.tag == 461u) {
        t0 = l0.payload.obj;
        vader_parser_walk_fn_decl(t0, l1);
    } else if (l0.tag == 505u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_StructDecl_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_StructDecl_t*) t0)->f_type_params;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) 0;
        while ((l4 < l3)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
            t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
            vader_parser_walk_type_param(t0, l1);
            t1 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t1;
        }
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_StructDecl_t*) t0)->f_fields;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) 0;
        while ((l4 < l3)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
            l5 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
            l6 = vader_parser_mint(l1);
            ((vader_struct_toolchain_ast_StructField_t*) l5)->f_id = l6;
            vader_parser_walk_expr(((vader_struct_toolchain_ast_StructField_t*) l5)->f_ty, l1);
            if (!(((vader_struct_toolchain_ast_StructField_t*) l5)->f_default_v.tag == 0u)) {
                vader_parser_walk_expr(((vader_struct_toolchain_ast_StructField_t*) l5)->f_default_v, l1);
            }
            t1 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t1;
        }
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_StructDecl_t*) t0)->f_decorators;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) 0;
        while ((l4 < l3)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
            t0 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l4);
            vader_parser_walk_decorator(t0, l1);
            t1 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t1;
        }
    } else if (l0.tag == 455u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_EnumDecl_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_EnumDecl_t*) t0)->f_header;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) 0;
        while ((l4 < l3)) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
            t2 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l4);
            vader_parser_walk_expr(t2, l1);
            t1 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t1;
        }
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_EnumDecl_t*) t0)->f_variants;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) 0;
        while ((l4 < l3)) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
            l5 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l4);
            l6 = vader_parser_mint(l1);
            ((vader_struct_toolchain_ast_EnumVariant_t*) l5)->f_id = l6;
            if (!(((vader_struct_toolchain_ast_EnumVariant_t*) l5)->f_data.tag == 0u)) {
                vader_parser_walk_struct_lit_items(((vader_struct_toolchain_ast_EnumVariant_t*) l5)->f_data.payload.obj, l1);
            }
            t1 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t1;
        }
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_EnumDecl_t*) t0)->f_decorators;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) 0;
        while ((l4 < l3)) {
            vader_array_t* _a6_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l4)
            t0 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l4);
            vader_parser_walk_decorator(t0, l1);
            t1 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t1;
        }
    } else if (l0.tag == 512u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_TraitDecl_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_TraitDecl_t*) t0)->f_type_params;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) 0;
        while ((l4 < l3)) {
            vader_array_t* _a7_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l4)
            t0 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l4);
            vader_parser_walk_type_param(t0, l1);
            t1 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t1;
        }
        t0 = l0.payload.obj;
        if (!(((vader_struct_toolchain_ast_TraitDecl_t*) t0)->f_requires.tag == 0u)) {
            t0 = l0.payload.obj;
            vader_parser_walk_expr(((vader_struct_toolchain_ast_TraitDecl_t*) t0)->f_requires, l1);
        }
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_TraitDecl_t*) t0)->f_members;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) 0;
        while ((l4 < l3)) {
            vader_array_t* _a8_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l4)
            t0 = vader_array_ref_load_obj(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l4);
            vader_parser_walk_fn_decl(t0, l1);
            t1 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t1;
        }
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_TraitDecl_t*) t0)->f_decorators;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) 0;
        while ((l4 < l3)) {
            vader_array_t* _a9_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l4)
            t0 = vader_array_ref_load_obj(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l4);
            vader_parser_walk_decorator(t0, l1);
            t1 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t1;
        }
    } else if (l0.tag == 470u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_ImplDecl_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_ImplDecl_t*) t0)->f_type_params;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) 0;
        while ((l4 < l3)) {
            vader_array_t* _a10_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l4)
            t0 = vader_array_ref_load_obj(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l4);
            vader_parser_walk_type_param(t0, l1);
            t1 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t1;
        }
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_ImplDecl_t*) t0)->f_for_type, l1);
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_ImplDecl_t*) t0)->f_trait_args;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) 0;
        while ((l4 < l3)) {
            vader_array_t* _a11_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l4)
            t2 = vader_array_ref_load_box(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l4);
            vader_parser_walk_expr(t2, l1);
            t1 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t1;
        }
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_ImplDecl_t*) t0)->f_members;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) 0;
        while ((l4 < l3)) {
            vader_array_t* _a12_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l4)
            t0 = vader_array_ref_load_obj(_a12_slotarr->buf, _a12_slotarr->offset + (size_t) l4);
            vader_parser_walk_fn_decl(t0, l1);
            t1 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t1;
        }
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_ImplDecl_t*) t0)->f_decorators;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) 0;
        while ((l4 < l3)) {
            vader_array_t* _a13_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l4)
            t0 = vader_array_ref_load_obj(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l4);
            vader_parser_walk_decorator(t0, l1);
            t1 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t1;
        }
    } else if (l0.tag == 514u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_TypeAliasDecl_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_TypeAliasDecl_t*) t0)->f_type_params;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) 0;
        while ((l4 < l3)) {
            vader_array_t* _a14_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l4)
            t0 = vader_array_ref_load_obj(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l4);
            vader_parser_walk_type_param(t0, l1);
            t1 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t1;
        }
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_TypeAliasDecl_t*) t0)->f_aliased, l1);
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_TypeAliasDecl_t*) t0)->f_decorators;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) 0;
        while ((l4 < l3)) {
            vader_array_t* _a15_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l4)
            t0 = vader_array_ref_load_obj(_a15_slotarr->buf, _a15_slotarr->offset + (size_t) l4);
            vader_parser_walk_decorator(t0, l1);
            t1 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t1;
        }
    } else if (l0.tag == 444u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_ConstDecl_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        if (!(((vader_struct_toolchain_ast_ConstDecl_t*) t0)->f_ty.tag == 0u)) {
            t0 = l0.payload.obj;
            vader_parser_walk_expr(((vader_struct_toolchain_ast_ConstDecl_t*) t0)->f_ty, l1);
        }
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_ConstDecl_t*) t0)->f_value, l1);
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_ConstDecl_t*) t0)->f_decorators;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) 0;
        while ((l4 < l3)) {
            vader_array_t* _a16_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l4)
            t0 = vader_array_ref_load_obj(_a16_slotarr->buf, _a16_slotarr->offset + (size_t) l4);
            vader_parser_walk_decorator(t0, l1);
            t1 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t1;
        }
    } else {
        if (!(l0.tag == 433u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_AssertDecl_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_AssertDecl_t*) t0)->f_condition, l1);
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_AssertDecl_t*) t0)->f_decorators;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) 0;
        while ((l4 < l3)) {
            vader_array_t* _a17_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l4)
            t0 = vader_array_ref_load_obj(_a17_slotarr->buf, _a17_slotarr->offset + (size_t) l4);
            vader_parser_walk_decorator(t0, l1);
            t1 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t1;
        }
    }
    return;
}

static void vader_parser_walk_decorator(void* l0, void* l1) {
    size_t l2, l4;
    void* l3;
    vader_box_t t0;
    int64_t t1;
    l2 = vader_parser_mint(l1);
    ((vader_struct_toolchain_ast_Decorator_t*) l0)->f_id = l2;
    l3 = ((vader_struct_toolchain_ast_Decorator_t*) l0)->f_args;
    l2 = ((vader_array_t*) l3)->length;
    l4 = (size_t) 0;
    while ((l4 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        vader_parser_walk_expr(t0, l1);
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    return;
}

static void vader_parser_walk_expr(vader_box_t l0, void* l1) {
    void* l2;
    void* l6;
    void* l8;
    size_t l3, l4, l7, l9;
    vader_box_t l5, l10;
    void* t0;
    int64_t t1;
    vader_box_t t2;
    if (l0.tag == 476u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_IntLitExpr_t*) l2)->f_id = l3;
        return;
    }
    if (l0.tag == 460u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_FloatLitExpr_t*) l2)->f_id = l3;
    } else if (l0.tag == 438u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_BoolLitExpr_t*) l2)->f_id = l3;
    } else if (l0.tag == 489u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_NullLitExpr_t*) l2)->f_id = l3;
    } else if (l0.tag == 443u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_CharLitExpr_t*) l2)->f_id = l3;
    } else if (l0.tag == 502u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_StringLitExpr_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_StringLitExpr_t*) t0)->f_parts;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) 0;
        while ((l4 < l3)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
            l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
            if (l5.tag == 504u) {
                l6 = l5.payload.obj;
                l7 = vader_parser_mint(l1);
                ((vader_struct_toolchain_ast_StringLitText_t*) l6)->f_id = l7;
            } else {
                if (!(l5.tag == 503u)) {
                    vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                }
                l8 = l5.payload.obj;
                l9 = vader_parser_mint(l1);
                ((vader_struct_toolchain_ast_StringLitInterp_t*) l8)->f_id = l9;
                t0 = l5.payload.obj;
                vader_parser_walk_expr(((vader_struct_toolchain_ast_StringLitInterp_t*) t0)->f_expr, l1);
            }
            t1 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t1;
        }
    } else if (l0.tag == 466u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_IdentExpr_t*) l2)->f_id = l3;
    } else if (l0.tag == 441u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_CallExpr_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_CallExpr_t*) t0)->f_callee, l1);
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_CallExpr_t*) t0)->f_args;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) 0;
        while ((l4 < l3)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
            l6 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
            l7 = vader_parser_mint(l1);
            ((vader_struct_toolchain_ast_CallArg_t*) l6)->f_id = l7;
            vader_parser_walk_expr(((vader_struct_toolchain_ast_CallArg_t*) l6)->f_value, l1);
            t1 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t1;
        }
    } else if (l0.tag == 459u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_FieldExpr_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_FieldExpr_t*) t0)->f_target, l1);
    } else if (l0.tag == 474u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_IndexExpr_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_IndexExpr_t*) t0)->f_target, l1);
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_IndexExpr_t*) t0)->f_index, l1);
    } else if (l0.tag == 516u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_UnaryExpr_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_UnaryExpr_t*) t0)->f_operand, l1);
    } else if (l0.tag == 436u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_BinaryExpr_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_left, l1);
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_right, l1);
    } else if (l0.tag == 488u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_NullCoalesceExpr_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_NullCoalesceExpr_t*) t0)->f_left, l1);
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_NullCoalesceExpr_t*) t0)->f_fallback;
        l10 = l5;
        if ((l5.tag == 439u || l5.tag == 445u || l5.tag == 499u)) {
            vader_parser_walk_stmt(l10, l1);
        } else {
            if (!((l5.tag == 431u || l5.tag == 435u || l5.tag == 436u || l5.tag == 437u || l5.tag == 438u || l5.tag == 441u || l5.tag == 442u || l5.tag == 443u || l5.tag == 454u || l5.tag == 459u || l5.tag == 460u || l5.tag == 463u || l5.tag == 465u || l5.tag == 466u || l5.tag == 469u || l5.tag == 474u || l5.tag == 476u || l5.tag == 477u || l5.tag == 479u || l5.tag == 483u || l5.tag == 485u || l5.tag == 488u || l5.tag == 489u || l5.tag == 495u || l5.tag == 500u || l5.tag == 502u || l5.tag == 507u || l5.tag == 516u))) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            vader_parser_walk_expr(l10, l1);
        }
    } else if (l0.tag == 469u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_IfExpr_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_IfExpr_t*) t0)->f_cond, l1);
        t0 = l0.payload.obj;
        vader_parser_walk_block(((vader_struct_toolchain_ast_IfExpr_t*) t0)->f_then_block, l1);
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_IfExpr_t*) t0)->f_else_branch;
        l10 = l5;
        if (!(l5.tag == 0u)) {
            if (l5.tag == 468u) {
                t0 = l10.payload.obj;
                vader_parser_walk_expr(vader_ref_box(((vader_struct_toolchain_ast_IfElseIf_t*) t0)->f_branch), l1);
            } else {
                if (!(l5.tag == 467u)) {
                    vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                }
                t0 = l10.payload.obj;
                vader_parser_walk_block(((vader_struct_toolchain_ast_IfElseBlock_t*) t0)->f_block, l1);
            }
        }
    } else if (l0.tag == 483u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_MatchExpr_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_MatchExpr_t*) t0)->f_scrutinee, l1);
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_MatchExpr_t*) t0)->f_arms;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) 0;
        while ((l4 < l3)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
            l6 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
            l7 = vader_parser_mint(l1);
            ((vader_struct_toolchain_ast_MatchArm_t*) l6)->f_id = l7;
            vader_parser_walk_pattern(((vader_struct_toolchain_ast_MatchArm_t*) l6)->f_pattern, l1);
            if (!(((vader_struct_toolchain_ast_MatchArm_t*) l6)->f_guard.tag == 0u)) {
                vader_parser_walk_expr(((vader_struct_toolchain_ast_MatchArm_t*) l6)->f_guard, l1);
            }
            vader_parser_walk_expr(((vader_struct_toolchain_ast_MatchArm_t*) l6)->f_body, l1);
            t1 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t1;
        }
    } else if (l0.tag == 437u) {
        t0 = l0.payload.obj;
        vader_parser_walk_block(t0, l1);
    } else if (l0.tag == 479u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_LambdaExpr_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_LambdaExpr_t*) t0)->f_params;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) 0;
        while ((l4 < l3)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
            t0 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l4);
            vader_parser_walk_fn_param(t0, l1);
            t1 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t1;
        }
        t0 = l0.payload.obj;
        if (!(((vader_struct_toolchain_ast_LambdaExpr_t*) t0)->f_return_type.tag == 0u)) {
            t0 = l0.payload.obj;
            vader_parser_walk_expr(((vader_struct_toolchain_ast_LambdaExpr_t*) t0)->f_return_type, l1);
        }
        t0 = l0.payload.obj;
        vader_parser_walk_block(((vader_struct_toolchain_ast_LambdaExpr_t*) t0)->f_body, l1);
    } else if (l0.tag == 507u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_StructLitExpr_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_StructLitExpr_t*) t0)->f_type_name, l1);
        t0 = l0.payload.obj;
        vader_parser_walk_struct_lit_items(((vader_struct_toolchain_ast_StructLitExpr_t*) t0)->f_items, l1);
    } else if (l0.tag == 500u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_SeqLitExpr_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_SeqLitExpr_t*) t0)->f_elements;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) 0;
        while ((l4 < l3)) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
            t2 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l4);
            vader_parser_walk_expr(t2, l1);
            t1 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t1;
        }
    } else if (l0.tag == 495u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_RangeExpr_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_RangeExpr_t*) t0)->f_lower, l1);
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_RangeExpr_t*) t0)->f_upper, l1);
    } else if (l0.tag == 435u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_AwaitExpr_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_AwaitExpr_t*) t0)->f_inner, l1);
    } else if (l0.tag == 442u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_CastExpr_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_CastExpr_t*) t0)->f_target, l1);
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_CastExpr_t*) t0)->f_value, l1);
    } else if (l0.tag == 465u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_GenericInstExpr_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_GenericInstExpr_t*) t0)->f_callee, l1);
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_GenericInstExpr_t*) t0)->f_type_args;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) 0;
        while ((l4 < l3)) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
            t2 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l4);
            vader_parser_walk_expr(t2, l1);
            t1 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t1;
        }
    } else if (l0.tag == 477u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) t0)->f_args;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) 0;
        while ((l4 < l3)) {
            vader_array_t* _a6_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l4)
            t2 = vader_array_ref_load_box(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l4);
            vader_parser_walk_expr(t2, l1);
            t1 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t1;
        }
    } else if (l0.tag == 454u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_DotVariantExpr_t*) l2)->f_id = l3;
    } else if (l0.tag == 463u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_FnTypeExpr_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_FnTypeExpr_t*) t0)->f_params;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) 0;
        while ((l4 < l3)) {
            vader_array_t* _a7_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l4)
            t2 = vader_array_ref_load_box(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l4);
            vader_parser_walk_expr(t2, l1);
            t1 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t1;
        }
        t0 = l0.payload.obj;
        if (!(((vader_struct_toolchain_ast_FnTypeExpr_t*) t0)->f_return_type.tag == 0u)) {
            t0 = l0.payload.obj;
            vader_parser_walk_expr(((vader_struct_toolchain_ast_FnTypeExpr_t*) t0)->f_return_type, l1);
        }
    } else if (l0.tag == 431u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t0)->f_element, l1);
    } else {
        if (!(l0.tag == 485u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_MutableTypeExpr_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_MutableTypeExpr_t*) t0)->f_inner, l1);
    }
    return;
}

static void vader_parser_walk_fn_decl(void* l0, void* l1) {
    size_t l2, l4;
    void* l3;
    void* t0;
    int64_t t1;
    l2 = vader_parser_mint(l1);
    ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_id = l2;
    l3 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_decorators;
    l2 = ((vader_array_t*) l3)->length;
    l4 = (size_t) 0;
    while ((l4 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        vader_parser_walk_decorator(t0, l1);
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    l3 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_type_params;
    l2 = ((vader_array_t*) l3)->length;
    l4 = (size_t) 0;
    while ((l4 < l2)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        vader_parser_walk_type_param(t0, l1);
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    l3 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_params;
    l2 = ((vader_array_t*) l3)->length;
    l4 = (size_t) 0;
    while ((l4 < l2)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        vader_parser_walk_fn_param(t0, l1);
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    if (!(((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_return_type.tag == 0u)) {
        vader_parser_walk_expr(((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_return_type, l1);
    }
    if (((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_body.tag == 0u) {
        return;
    }
    vader_parser_walk_block(((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_body.payload.obj, l1);
    return;
}

static void vader_parser_walk_fn_param(void* l0, void* l1) {
    size_t l2;
    l2 = vader_parser_mint(l1);
    ((vader_struct_toolchain_ast_FnParam_t*) l0)->f_id = l2;
    if (!(((vader_struct_toolchain_ast_FnParam_t*) l0)->f_ty.tag == 0u)) {
        vader_parser_walk_expr(((vader_struct_toolchain_ast_FnParam_t*) l0)->f_ty, l1);
    }
    if (((vader_struct_toolchain_ast_FnParam_t*) l0)->f_default_value.tag == 0u) {
        return;
    }
    vader_parser_walk_expr(((vader_struct_toolchain_ast_FnParam_t*) l0)->f_default_value, l1);
    return;
}

static void vader_parser_walk_for_form(vader_box_t l0, void* l1) {
    void* t0;
    if (l0.tag == 475u) {
        return;
    }
    if (l0.tag == 517u) {
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_WhileFor_t*) t0)->f_cond, l1);
    } else {
        if (!(l0.tag == 473u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_InFor_t*) t0)->f_iter, l1);
    }
    return;
}

static void vader_parser_walk_import_binding(vader_box_t l0, void* l1) {
    void* l2;
    void* l5;
    size_t l3, l4, l6;
    void* t0;
    int64_t t1;
    if (l0.tag == 486u) {
        return;
    }
    if (!(l0.tag == 519u)) {
        if (!(l0.tag == 451u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_DestructureImport_t*) t0)->f_names;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) 0;
        while ((l4 < l3)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
            l6 = vader_parser_mint(l1);
            ((vader_struct_toolchain_ast_ImportName_t*) l5)->f_id = l6;
            t1 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t1;
        }
    }
    return;
}

static void vader_parser_walk_let_binding(vader_box_t l0, void* l1) {
    void* l2;
    size_t l3, l4;
    void* t0;
    vader_box_t t1;
    int64_t t2;
    if (l0.tag == 501u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_SimpleBinding_t*) l2)->f_id = l3;
        return;
    }
    if (l0.tag == 518u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_WildcardBinding_t*) l2)->f_id = l3;
    } else if (l0.tag == 497u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_RestBinding_t*) l2)->f_id = l3;
    } else {
        if (!(l0.tag == 513u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_TupleBinding_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_TupleBinding_t*) t0)->f_elements;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) 0;
        while ((l4 < l3)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
            t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
            vader_parser_walk_let_binding(t1, l1);
            t2 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t2;
        }
    }
    return;
}

static void vader_parser_walk_pattern(vader_box_t l0, void* l1) {
    void* l2;
    void* l5;
    void* l9;
    size_t l3, l4, l6, l10;
    vader_box_t l7, l8;
    void* t0;
    int64_t t1;
    vader_box_t t2;
    if (l0.tag == 478u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_IsPattern_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_IsPattern_t*) t0)->f_ty, l1);
        t0 = l0.payload.obj;
        if (!(((vader_struct_toolchain_ast_IsPattern_t*) t0)->f_inner.tag == 0u)) {
            t0 = l0.payload.obj;
            vader_parser_walk_pattern(((vader_struct_toolchain_ast_IsPattern_t*) t0)->f_inner, l1);
        }
        return;
    }
    if (l0.tag == 510u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_StructPattern_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_StructPattern_t*) t0)->f_fields;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) 0;
        while ((l4 < l3)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
            l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
            l6 = vader_parser_mint(l1);
            ((vader_struct_toolchain_ast_StructPatternField_t*) l5)->f_id = l6;
            l7 = ((vader_struct_toolchain_ast_StructPatternField_t*) l5)->f_value;
            l8 = l7;
            if (l7.tag == 491u) {
                l9 = l8.payload.obj;
                l10 = vader_parser_mint(l1);
                ((vader_struct_toolchain_ast_PatternBinding_t*) l9)->f_id = l10;
            } else {
                if (!(l7.tag == 492u)) {
                    vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                }
                t0 = l8.payload.obj;
                vader_parser_walk_expr(((vader_struct_toolchain_ast_PatternLiteral_t*) t0)->f_value, l1);
            }
            t1 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t1;
        }
    } else if (l0.tag == 520u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_WildcardPattern_t*) l2)->f_id = l3;
    } else if (l0.tag == 457u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_EnumVariantPattern_t*) l2)->f_id = l3;
    } else if (l0.tag == 481u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_LiteralPattern_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_LiteralPattern_t*) t0)->f_value, l1);
    } else if (l0.tag == 496u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_RangePattern_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_RangePattern_t*) t0)->f_lower, l1);
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_RangePattern_t*) t0)->f_upper, l1);
    } else {
        if (!(l0.tag == 490u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_OrPattern_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_OrPattern_t*) t0)->f_patterns;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) 0;
        while ((l4 < l3)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
            t2 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
            vader_parser_walk_pattern(t2, l1);
            t1 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t1;
        }
    }
    return;
}

static void vader_parser_walk_stmt(vader_box_t l0, void* l1) {
    void* l2;
    size_t l3, l4;
    vader_box_t l5, l6;
    void* t0;
    vader_box_t t1;
    int64_t t2;
    if (l0.tag == 480u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_LetStmt_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_parser_walk_let_binding(((vader_struct_toolchain_ast_LetStmt_t*) t0)->f_binding, l1);
        t0 = l0.payload.obj;
        if (!(((vader_struct_toolchain_ast_LetStmt_t*) t0)->f_ty.tag == 0u)) {
            t0 = l0.payload.obj;
            vader_parser_walk_expr(((vader_struct_toolchain_ast_LetStmt_t*) t0)->f_ty, l1);
        }
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_LetStmt_t*) t0)->f_value, l1);
        return;
    }
    if (l0.tag == 434u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_AssignStmt_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_AssignStmt_t*) t0)->f_target, l1);
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_AssignStmt_t*) t0)->f_value, l1);
    } else if (l0.tag == 450u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_DestructureAssignStmt_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_DestructureAssignStmt_t*) t0)->f_targets;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) 0;
        while ((l4 < l3)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
            t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
            vader_parser_walk_assign_target(t1, l1);
            t2 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t2;
        }
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_DestructureAssignStmt_t*) t0)->f_value, l1);
    } else if (l0.tag == 458u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_ExprStmt_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_ExprStmt_t*) t0)->f_expr, l1);
    } else if (l0.tag == 499u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_ReturnStmt_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        if (!(((vader_struct_toolchain_ast_ReturnStmt_t*) t0)->f_value.tag == 0u)) {
            t0 = l0.payload.obj;
            vader_parser_walk_expr(((vader_struct_toolchain_ast_ReturnStmt_t*) t0)->f_value, l1);
        }
    } else if (l0.tag == 522u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_YieldStmt_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_YieldStmt_t*) t0)->f_value, l1);
    } else if (l0.tag == 464u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_ForStmt_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_parser_walk_for_form(((vader_struct_toolchain_ast_ForStmt_t*) t0)->f_form, l1);
        t0 = l0.payload.obj;
        vader_parser_walk_block(((vader_struct_toolchain_ast_ForStmt_t*) t0)->f_body, l1);
    } else if (l0.tag == 439u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_BreakStmt_t*) l2)->f_id = l3;
    } else if (l0.tag == 445u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_ContinueStmt_t*) l2)->f_id = l3;
    } else {
        if (!(l0.tag == 448u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_DeferStmt_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_DeferStmt_t*) t0)->f_body;
        l6 = l5;
        if (l5.tag == 449u) {
            t0 = l6.payload.obj;
            vader_parser_walk_stmt(((vader_struct_toolchain_ast_DeferStmtBody_t*) t0)->f_stmt, l1);
        } else {
            if (!(l5.tag == 447u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            t0 = l6.payload.obj;
            vader_parser_walk_block(((vader_struct_toolchain_ast_DeferBlockBody_t*) t0)->f_block, l1);
        }
    }
    return;
}

static void vader_parser_walk_struct_lit_items(void* l0, void* l1) {
    void* l2;
    void* l6;
    size_t l3, l4, l7;
    vader_box_t l5;
    void* t0;
    int64_t t1;
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        l6 = l5.payload.obj;
        l7 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_StructLitField_t*) l6)->f_id = l7;
        if (l5.tag == 508u) {
            t0 = l5.payload.obj;
            vader_parser_walk_expr(((vader_struct_toolchain_ast_StructLitField_t*) t0)->f_value, l1);
        } else {
            t0 = l5.payload.obj;
            vader_parser_walk_expr(((vader_struct_toolchain_ast_StructLitSpread_t*) t0)->f_expr, l1);
        }
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    return;
}

static void vader_parser_walk_type_param(void* l0, void* l1) {
    size_t l2;
    l2 = vader_parser_mint(l1);
    ((vader_struct_toolchain_ast_TypeParam_t*) l0)->f_id = l2;
    if (((vader_struct_toolchain_ast_TypeParam_t*) l0)->f_bound.tag == 0u) {
        return;
    }
    vader_parser_walk_expr(((vader_struct_toolchain_ast_TypeParam_t*) l0)->f_bound, l1);
    return;
}

static void* vader_parser_wrap_as_block(vader_box_t l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l0, &l3 };
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(l0.tag == 437u)) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t0)->f_span;
        vader_array_t* _a0_arr = vader_array_new(177u, 0u, 13u, 1262u);
        l2 = (void*) _a0_arr;
        l3 = l0;
        vader_struct_toolchain_ast_BlockExpr_t* _a1_obj = (vader_struct_toolchain_ast_BlockExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BlockExpr_t));
        vader_obj_header_init(_a1_obj, 437u);
        _a1_obj->f_span = l1;
        _a1_obj->f_id = (size_t) 0;
        _a1_obj->f_stmts = l2;
        _a1_obj->f_trailing = l3;
        t0 = (void*) _a1_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l0.payload.obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}
