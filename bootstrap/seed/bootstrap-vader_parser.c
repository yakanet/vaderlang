#include "bootstrap.split.h"

static void* vader_parser_advance(void* l0);
static bool vader_parser_allows_bare_lambda(void* l0);
static bool vader_parser_allows_struct_lit(void* l0);
static bool vader_parser_at_top_level_start(void* l0);
static int32_t vader_parser_bracket_step(uint8_t l0);
static bool vader_parser_check(void* l0, uint8_t l1);
static bool vader_parser_check_at(void* l0, uint8_t l1, int32_t l2);
static void vader_parser_check_c_struct_arguments(void* l0, void* l1);
static bool vader_parser_check_closing_angle(void* l0);
static void vader_parser_check_guard_arity(void* l0, void* l1);
static void vader_parser_collect_type_params(vader_box_t l0, void* l1);
static void* vader_parser_compound_op(uint8_t l0);
static void* vader_parser_consume_closing_angle(void* l0);
static vader_box_t vader_parser_declared_binding(vader_box_t l0);
static vader_box_t vader_parser_decorator_spec(vader_string_t l0);
static vader_string_t vader_parser_describe_token(void* l0);
static void* vader_parser_desugar_comptime_const(void* l0, void* l1, uint8_t l2, void* l3, vader_box_t l4);
static void* vader_parser_empty_token(void);
static bool vader_parser_ends_a_value(uint8_t l0);
static bool vader_parser_ends_its_line(void* l0, int32_t l1);
static void vader_parser_error(void* l0, uint8_t l1, void* l2, vader_string_t l3);
static void* vader_parser_expect(void* l0, uint8_t l1, vader_string_t l2);
static void* vader_parser_expect_string_literal(void* l0, vader_string_t l1);
static bool vader_parser_generic_use_follows(void* l0, int32_t l1);
static int64_t vader_parser_header_budget(int64_t l0);
static void* vader_parser_ident_expr(void* l0, vader_string_t l1);
static void* vader_parser_infix_for(uint8_t l0);
static bool vader_parser_is_angle_scan_bailout(uint8_t l0);
static bool vader_parser_is_impl_decl(void* l0);
static bool vader_parser_is_literal_start(void* l0);
static bool vader_parser_is_module_segment_continue(uint32_t l0);
static bool vader_parser_is_module_segment_start(uint32_t l0);
static bool vader_parser_is_number_token(void* l0);
static bool vader_parser_is_valid_module_name(vader_string_t l0);
static uint8_t vader_parser_kind_after_bracket_group(void* l0);
static void* vader_parser_lift_trailing_return(void* l0);
static bool vader_parser_looks_like_for_destructure(void* l0);
static bool vader_parser_looks_like_struct_lit_body(void* l0, int32_t l1);
static vader_box_t vader_parser_match_kind(void* l0, uint8_t l1);
static void* vader_parser_match_or_peek(void* l0, uint8_t l1);
static vader_box_t vader_parser_match_scrutinee(void* l0, vader_box_t l1);
static void* vader_parser_merge_type_params(void* l0, void* l1);
static void* vader_parser_new_parser(void* l0, vader_string_t l1);
static void* vader_parser_no_infix(void);
static vader_box_t vader_parser_number_literal(void* l0, void* l1, bool l2);
static void* vader_parser_parse_angle_type_params(void* l0);
static void* vader_parser_parse_any_let(void* l0);
static vader_box_t vader_parser_parse_assert_decl(void* l0);
static vader_box_t vader_parser_parse_assign_target(void* l0);
static void* vader_parser_parse_block(void* l0);
static void* vader_parser_parse_break(void* l0);
static void* vader_parser_parse_call_args(void* l0);
static vader_box_t vader_parser_parse_coalesce_fallback(void* l0);
static void* vader_parser_parse_const_decl(void* l0, void* l1, uint8_t l2, void* l3);
static void* vader_parser_parse_continue(void* l0);
static vader_box_t vader_parser_parse_decl(void* l0);
static vader_box_t vader_parser_parse_decorated_decl(void* l0, void* l1, uint8_t l2);
static void* vader_parser_parse_decorator(void* l0);
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
static vader_box_t vader_parser_parse_generic_use(void* l0, vader_box_t l1);
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
static vader_box_t vader_parser_parse_match_declaration(void* l0);
static void* vader_parser_parse_match_expr(void* l0, bool l1, bool l2, void* l3);
static vader_box_t vader_parser_parse_named_decl(void* l0, void* l1, uint8_t l2);
static void* vader_parser_parse_named_import_decl(void* l0, void* l1, void* l2);
static vader_box_t vader_parser_parse_optional_module_decl(void* l0);
static vader_box_t vader_parser_parse_paren(void* l0);
static vader_box_t vader_parser_parse_pattern(void* l0);
static vader_box_t vader_parser_parse_postfix(void* l0, vader_box_t l1, void* l2);
static vader_box_t vader_parser_parse_prefix(void* l0);
static void* vader_parser_parse_program(void* l0);
static vader_box_t vader_parser_parse_range_bound(void* l0);
static vader_box_t vader_parser_parse_range_type(void* l0);
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
static vader_box_t vader_parser_place_text(vader_box_t l0);
static int32_t vader_parser_postfix_bp(uint8_t l0);
static void vader_parser_reject_alternative_bindings(void* l0, vader_box_t l1);
static void vader_parser_reject_as_binder(void* l0, uint8_t l1, void* l2);
static void vader_parser_reject_assert_decorator(void* l0, void* l1);
static void vader_parser_reject_c_decorators(void* l0, void* l1, vader_string_t l2);
static void vader_parser_reject_displayable_decorator(void* l0, void* l1);
static void vader_parser_reject_free_fn_decorators(void* l0, void* l1, vader_string_t l2, vader_string_t l3);
static void vader_parser_reject_removed_const(void* l0);
static void* vader_parser_reject_tuple_pattern(void* l0);
static void vader_parser_report_nesting_too_deep(void* l0, vader_string_t l1);
static bool vader_parser_scan_angle_generic(void* l0, int32_t l1);
static int64_t vader_parser_skip_block_comment(vader_string_t l0, int64_t l1);
static void vader_parser_skip_newlines(void* l0);
static int64_t vader_parser_skip_to_eol(vader_string_t l0, int64_t l1);
static void* vader_parser_span_of(void* l0, void* l1, void* l2);
static bool vader_parser_starts_let(void* l0);
static vader_box_t vader_parser_static_assert_message(void* l0, vader_box_t l1);
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
    int64_t t0;
    int32_t t1;
    l1 = vader_parser_peek(l0);
    if (((vader_struct_vader_parser_Parser_t*) l0)->f_shr_pending_half.tag == 0u) {
        l2 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pos;
        t0 = ((vader_array_t*) ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens)->length;
        l3 = vader_chk_sub(i32, ((int32_t) (int64_t) t0), INT32_C(1));
        if ((l2 < l3)) {
            t1 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pos;
            l2 = vader_chk_add(i32, t1, INT32_C(1));
            ((vader_struct_vader_parser_Parser_t*) l0)->f_pos = l2;
        }
    } else {
        ((vader_struct_vader_parser_Parser_t*) l0)->f_shr_pending_half = vader_box_obj(0u, NULL);
        VADER_WRITE_BARRIER((vader_struct_vader_parser_Parser_t*) l0);
    }
    l2 = ((vader_struct_vader_parser_Parser_t*) l0)->f_bracket_depth;
    l3 = vader_parser_bracket_step(((vader_struct_vader_lexer_Token_t*) l1)->f_kind);
    l2 = vader_chk_add(i32, l2, l3);
    ((vader_struct_vader_parser_Parser_t*) l0)->f_bracket_depth = l2;
    return l1;
}

static bool vader_parser_allows_bare_lambda(void* l0) {
    int32_t l1, l2;
    l1 = ((vader_struct_vader_parser_Parser_t*) l0)->f_bracket_depth;
    l2 = ((vader_struct_vader_parser_Parser_t*) l0)->f_no_bare_lambda_at;
    return l1 != l2;
}

static bool vader_parser_allows_struct_lit(void* l0) {
    int32_t l1, l2;
    l1 = ((vader_struct_vader_parser_Parser_t*) l0)->f_bracket_depth;
    l2 = ((vader_struct_vader_parser_Parser_t*) l0)->f_no_struct_lit_at;
    return l1 != l2;
}

uint8_t vader_parser_arg_kind(void* l0, int64_t l1) {
    int64_t l2;
    vader_box_t t0;
    l2 = ((vader_array_t*) ((vader_struct_vader_parser_IntrinsicSpec_t*) l0)->f_args)->length;
    if (!((l1 < l2))) {
        return (uint8_t) 1;
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_parser_IntrinsicSpec_t*) l0)->f_args);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l1, 322u);
    return ((uint8_t) t0.payload.i);
}

void vader_parser_assign_block_ids(void* l0, void* l1) {
    vader_parser_walk_block(l0, l1);
    return;
}

void vader_parser_assign_program_ids(void* l0, void* l1) {
    int64_t l2, l4;
    void* l3;
    vader_box_t t0;
    l2 = vader_parser_mint(l1);
    ((vader_struct_toolchain_ast_Program_t*) l0)->f_id = l2;
    if (!(((vader_struct_toolchain_ast_Program_t*) l0)->f_module.tag == 0u)) {
        t0 = ((vader_struct_toolchain_ast_Program_t*) l0)->f_module;
        l3 = t0.payload.obj;
        l2 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_ModuleDecl_t*) l3)->f_id = l2;
    }
    l3 = ((vader_struct_toolchain_ast_Program_t*) l0)->f_decls;
    l2 = ((vader_array_t*) l3)->length;
    l4 = INT64_C(0);
    while ((l4 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        vader_parser_walk_decl(t0, l1);
        l4 = (l4 + INT64_C(1));
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
        if (((vader_struct_vader_lexer_Token_t*) l2)->f_kind == INT32_C(71)) {
            return true;
        }
        if (((vader_struct_vader_lexer_Token_t*) l2)->f_kind == INT32_C(14)) {
            return true;
        }
    }
    if (!(((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(78))) {
        return false;
    }
    return true;
}

static int32_t vader_parser_bracket_step(uint8_t l0) {
    if (l0 == INT32_C(80)) {
        return INT32_C(1);
    }
    if (l0 == INT32_C(82)) {
        return INT32_C(1);
    }
    if (l0 == INT32_C(84)) {
        return INT32_C(1);
    }
    if (l0 == INT32_C(9)) {
        return INT32_C(1);
    }
    if (l0 == INT32_C(81)) {
        return INT32_C(-1);
    }
    if (l0 == INT32_C(83)) {
        return INT32_C(-1);
    }
    if (l0 == INT32_C(85)) {
        return INT32_C(-1);
    }
    if (!(l0 == INT32_C(10))) {
        return INT32_C(0);
    }
    return INT32_C(-1);
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

static void vader_parser_check_c_struct_arguments(void* l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    vader_box_t l3 = vader_box_null();
    int64_t t0;
    vader_box_t t1 = vader_box_null(), t2 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l3, &t1, &t2 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = toolchain_ast_find_decorator(l1, 1638u);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l2 = l3.payload.obj;
    t0 = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l2)->f_args)->length;
    if ((t0 > INT64_C(1))) {
        l4 = ((vader_struct_toolchain_ast_Decorator_t*) l2)->f_span;
        vader_parser_error(l0, (uint8_t) 18, l4, 1290u);
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l2)->f_args)->length;
    if (t0 == INT64_C(1)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l2)->f_args);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
        t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
        t2 = toolchain_ast_string_literal_text(t1);
        if (t2.tag == 0u) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l2)->f_args);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
            t1 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT32_C(0));
            l2 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, t1.payload.obj);
            vader_parser_error(l0, (uint8_t) 19, l2, 1289u);
            { vader_gc_top = gc_frame.prev; return; }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_parser_check_closing_angle(void* l0) {
    uint8_t l1;
    void* t0;
    if (!(((vader_struct_vader_parser_Parser_t*) l0)->f_shr_pending_half.tag == 0u)) {
        return true;
    }
    t0 = vader_parser_peek(l0);
    l1 = ((vader_struct_vader_lexer_Token_t*) t0)->f_kind;
    if (l1 == INT32_C(54)) {
        return true;
    }
    return l1 == INT32_C(49);
}

static void vader_parser_check_guard_arity(void* l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    void* l7 = NULL;
    int64_t l3, l4;
    vader_string_t l6 = 0;
    vader_string_t l8 = 0;
    vader_string_t l9 = 0;
    vader_string_t l10 = 0;
    vader_string_t t0 = 0;
    int64_t t1;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l5, &l7 };
    vader_string_t* gc_atom_roots[5] = { &l6, &l8, &l9, &l10, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = l1;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        l6 = ((vader_struct_toolchain_ast_Decorator_t*) l5)->f_name;
        {
            if (!(l6 == 2433u)) {
                t0 = ((vader_struct_toolchain_ast_Decorator_t*) l5)->f_name;
                if (!(t0 == 1792u)) {
                    goto end_18;
                }
            }
            t1 = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l5)->f_args)->length;
            if (t1 != INT64_C(1)) {
                l7 = ((vader_struct_toolchain_ast_Decorator_t*) l5)->f_span;
                l8 = ((vader_struct_toolchain_ast_Decorator_t*) l5)->f_name;
                l9 = ((vader_struct_toolchain_ast_Decorator_t*) l5)->f_name;
                l10 = concat_5(1280u, l8, 1037u, l9, 281u);
                vader_parser_error(l0, (uint8_t) 18, l7, l10);
            }
        } end_18: ;
        l4 = (l4 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_parser_collect_type_params(vader_box_t l0, void* l1) {
    bool l2;
    void* l3 = NULL;
    int64_t l4, l5;
    vader_string_t l6 = 0;
    vader_string_t l7 = 0;
    void* t0 = NULL;
    bool t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &t2 };
    void** gc_raw_roots[3] = { &l1, &l3, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l6, &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 610u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_toolchain_ast_IdentExpr_t*) t0)->f_is_type_param_intro;
        if (!(t1)) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        l2 = false;
        l3 = l1;
        l4 = ((vader_array_t*) l3)->length;
        l5 = INT64_C(0);
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
            l5 = (l5 + INT64_C(1));
        }
        if (!(l2)) {
            t0 = l0.payload.obj;
            l3 = ((vader_struct_toolchain_ast_IdentExpr_t*) t0)->f_span;
            t0 = l0.payload.obj;
            l6 = ((vader_struct_toolchain_ast_IdentExpr_t*) t0)->f_name;
            vader_struct_toolchain_ast_TypeParam_t* _a1_obj = (vader_struct_toolchain_ast_TypeParam_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_TypeParam_t));
            vader_obj_header_init(_a1_obj, 658u);
            _a1_obj->f_span = l3;
            _a1_obj->f_id = INT64_C(0);
            _a1_obj->f_name = l6;
            _a1_obj->f_bound = vader_box_obj(0u, NULL);
            _a1_obj->f_default_v = vader_box_obj(0u, NULL);
            _a1_obj->f_is_comptime_value = false;
            l3 = (void*) _a1_obj;
            vader_array_push_ref((vader_array_t*) l1, l3);
        }
    } else if (l0.tag == 580u) {
        t0 = l0.payload.obj;
        vader_parser_collect_type_params(((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_left, l1);
        t0 = l0.payload.obj;
        vader_parser_collect_type_params(((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_right, l1);
    } else if (l0.tag == 607u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_toolchain_ast_FnTypeExpr_t*) t0)->f_params;
        l4 = ((vader_array_t*) l3)->length;
        l5 = INT64_C(0);
        while ((l5 < l4)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            t2 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
            vader_parser_collect_type_params(t2, l1);
            l5 = (l5 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        vader_parser_collect_type_params(((vader_struct_toolchain_ast_FnTypeExpr_t*) t0)->f_return_type, l1);
    } else if (l0.tag == 576u) {
        t0 = l0.payload.obj;
        vader_parser_collect_type_params(((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t0)->f_element, l1);
    } else if (l0.tag == 643u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_toolchain_ast_SeqLitExpr_t*) t0)->f_elements;
        l4 = ((vader_array_t*) l3)->length;
        l5 = INT64_C(0);
        while ((l5 < l4)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            t2 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l5);
            vader_parser_collect_type_params(t2, l1);
            l5 = (l5 + INT64_C(1));
        }
    } else if (l0.tag == 609u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_toolchain_ast_GenericInstExpr_t*) t0)->f_type_args;
        l4 = ((vader_array_t*) l3)->length;
        l5 = INT64_C(0);
        while ((l5 < l4)) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            t2 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l5);
            vader_parser_collect_type_params(t2, l1);
            l5 = (l5 + INT64_C(1));
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_parser_compound_op(uint8_t l0) {
    void* l1 = NULL;
    void** gc_raw_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(63)) {
        vader_struct_vader_parser_CompoundOpResult_t* _a0_obj = (vader_struct_vader_parser_CompoundOpResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_CompoundOpResult_t));
        vader_obj_header_init(_a0_obj, 1196u);
        _a0_obj->f_matched = true;
        _a0_obj->f_op = (uint8_t) 0;
        l1 = (void*) _a0_obj;
        { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(64)) {
        vader_struct_vader_parser_CompoundOpResult_t* _a1_obj = (vader_struct_vader_parser_CompoundOpResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_CompoundOpResult_t));
        vader_obj_header_init(_a1_obj, 1196u);
        _a1_obj->f_matched = true;
        _a1_obj->f_op = (uint8_t) 1;
        l1 = (void*) _a1_obj;
    } else if (l0 == INT32_C(65)) {
        vader_struct_vader_parser_CompoundOpResult_t* _a2_obj = (vader_struct_vader_parser_CompoundOpResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_CompoundOpResult_t));
        vader_obj_header_init(_a2_obj, 1196u);
        _a2_obj->f_matched = true;
        _a2_obj->f_op = (uint8_t) 2;
        l1 = (void*) _a2_obj;
    } else if (l0 == INT32_C(66)) {
        vader_struct_vader_parser_CompoundOpResult_t* _a3_obj = (vader_struct_vader_parser_CompoundOpResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_CompoundOpResult_t));
        vader_obj_header_init(_a3_obj, 1196u);
        _a3_obj->f_matched = true;
        _a3_obj->f_op = (uint8_t) 3;
        l1 = (void*) _a3_obj;
    } else if (l0 == INT32_C(67)) {
        vader_struct_vader_parser_CompoundOpResult_t* _a4_obj = (vader_struct_vader_parser_CompoundOpResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_CompoundOpResult_t));
        vader_obj_header_init(_a4_obj, 1196u);
        _a4_obj->f_matched = true;
        _a4_obj->f_op = (uint8_t) 4;
        l1 = (void*) _a4_obj;
    } else if (l0 == INT32_C(68)) {
        vader_struct_vader_parser_CompoundOpResult_t* _a5_obj = (vader_struct_vader_parser_CompoundOpResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_CompoundOpResult_t));
        vader_obj_header_init(_a5_obj, 1196u);
        _a5_obj->f_matched = true;
        _a5_obj->f_op = (uint8_t) 23;
        l1 = (void*) _a5_obj;
    } else if (l0 == INT32_C(69)) {
        vader_struct_vader_parser_CompoundOpResult_t* _a6_obj = (vader_struct_vader_parser_CompoundOpResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_CompoundOpResult_t));
        vader_obj_header_init(_a6_obj, 1196u);
        _a6_obj->f_matched = true;
        _a6_obj->f_op = (uint8_t) 24;
        l1 = (void*) _a6_obj;
    } else if (l0 == INT32_C(70)) {
        vader_struct_vader_parser_CompoundOpResult_t* _a7_obj = (vader_struct_vader_parser_CompoundOpResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_CompoundOpResult_t));
        vader_obj_header_init(_a7_obj, 1196u);
        _a7_obj->f_matched = true;
        _a7_obj->f_op = (uint8_t) 25;
        l1 = (void*) _a7_obj;
    } else {
        vader_struct_vader_parser_CompoundOpResult_t* _a8_obj = (vader_struct_vader_parser_CompoundOpResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_CompoundOpResult_t));
        vader_obj_header_init(_a8_obj, 1196u);
        _a8_obj->f_matched = false;
        _a8_obj->f_op = (uint8_t) 0;
        l1 = (void*) _a8_obj;
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_consume_closing_angle(void* l0) {
    vader_box_t l1 = vader_box_null();
    void* l2 = NULL;
    void* l4 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    int32_t l3, l5, l8;
    vader_string_t l6 = 0;
    int64_t l7;
    int64_t t0;
    int32_t t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[7] = { &l0, &l2, &l4, &l9, &l10, &l11, &t2 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_parser_Parser_t*) l0)->f_shr_pending_half;
    if (l1.tag == 0u) {
        l2 = vader_parser_peek(l0);
        if (((vader_struct_vader_lexer_Token_t*) l2)->f_kind == INT32_C(54)) {
            l3 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pos;
            t0 = ((vader_array_t*) ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens)->length;
            l5 = vader_chk_sub(i32, ((int32_t) (int64_t) t0), INT32_C(1));
            if ((l3 < l5)) {
                t1 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pos;
                l5 = vader_chk_add(i32, t1, INT32_C(1));
                ((vader_struct_vader_parser_Parser_t*) l0)->f_pos = l5;
                { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
            }
            { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (!(((vader_struct_vader_lexer_Token_t*) l2)->f_kind == INT32_C(49))) {
            { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l6 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l2)->f_span)->f_start)->f_file;
        t0 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l2)->f_span)->f_start)->f_offset;
        l7 = vader_chk_add(i64, t0, INT64_C(1));
        l5 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l2)->f_span)->f_start)->f_line;
        t1 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l2)->f_span)->f_start)->f_column;
        l8 = vader_chk_add(i32, t1, INT32_C(1));
        vader_struct_toolchain_span_Position_t* _a0_obj = (vader_struct_toolchain_span_Position_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Position_t));
        vader_obj_header_init(_a0_obj, 666u);
        _a0_obj->f_file = l6;
        _a0_obj->f_offset = l7;
        _a0_obj->f_line = l5;
        _a0_obj->f_column = l8;
        l4 = (void*) _a0_obj;
        vader_struct_toolchain_span_Span_t* _a1_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
        vader_obj_header_init(_a1_obj, 667u);
        _a1_obj->f_start = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l2)->f_span)->f_start;
        _a1_obj->f_end = l4;
        l9 = (void*) _a1_obj;
        vader_struct_vader_lexer_Token_t* _a2_obj = (vader_struct_vader_lexer_Token_t*) vader_gc_alloc(sizeof(vader_struct_vader_lexer_Token_t));
        vader_obj_header_init(_a2_obj, 995u);
        _a2_obj->f_kind = (uint8_t) 54;
        _a2_obj->f_text = 477u;
        _a2_obj->f_span = l9;
        _a2_obj->f_value = vader_box_obj(0u, NULL);
        l9 = (void*) _a2_obj;
        l10 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l2)->f_span)->f_end;
        vader_struct_toolchain_span_Span_t* _a3_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
        vader_obj_header_init(_a3_obj, 667u);
        _a3_obj->f_start = l4;
        _a3_obj->f_end = l10;
        l10 = (void*) _a3_obj;
        vader_struct_vader_lexer_Token_t* _a4_obj = (vader_struct_vader_lexer_Token_t*) vader_gc_alloc(sizeof(vader_struct_vader_lexer_Token_t));
        vader_obj_header_init(_a4_obj, 995u);
        _a4_obj->f_kind = (uint8_t) 54;
        _a4_obj->f_text = 477u;
        _a4_obj->f_span = l10;
        _a4_obj->f_value = vader_box_obj(0u, NULL);
        l10 = (void*) _a4_obj;
        l11 = ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens;
        l5 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pos;
        vader_array_t* _a5_slotarr = ((vader_array_t*) l11);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
        vader_array_ref_store(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l5, l9);
        VADER_WRITE_BARRIER(_a5_slotarr->buf);
        ((vader_struct_vader_parser_Parser_t*) l0)->f_shr_pending_half = vader_ref_box(l10);
        VADER_WRITE_BARRIER((vader_struct_vader_parser_Parser_t*) l0);
        l5 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pos;
        t0 = ((vader_array_t*) ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens)->length;
        l8 = vader_chk_sub(i32, ((int32_t) (int64_t) t0), INT32_C(1));
        if ((l5 < l8)) {
            t1 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pos;
            l5 = vader_chk_add(i32, t1, INT32_C(1));
            ((vader_struct_vader_parser_Parser_t*) l0)->f_pos = l5;
            { void* __vret = l9; vader_gc_top = gc_frame.prev; return __vret; }
        }
        { void* __vret = l9; vader_gc_top = gc_frame.prev; return __vret; }
    }
    ((vader_struct_vader_parser_Parser_t*) l0)->f_shr_pending_half = vader_box_obj(0u, NULL);
    VADER_WRITE_BARRIER((vader_struct_vader_parser_Parser_t*) l0);
    t1 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pos;
    if ((t1 > INT32_C(0))) {
        l2 = ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens;
        t1 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pos;
        l3 = vader_chk_sub(i32, t1, INT32_C(1));
        l4 = l1.payload.obj;
        vader_array_t* _a6_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l3)
        vader_array_ref_store(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l3, l4);
        VADER_WRITE_BARRIER(_a6_slotarr->buf);
        t2 = l1.payload.obj;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = l1.payload.obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_parser_declared_binding(vader_box_t l0) {
    vader_box_t l1;
    void* t0;
    if (l0.tag == 0u) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l0.payload.obj;
    l1 = ((vader_struct_toolchain_ast_LetStmt_t*) t0)->f_binding;
    if (!(l1.tag == 644u)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l1.payload.obj;
    return vader_ref_box(t0);
}

bool vader_parser_decorator_on(vader_string_t l0, uint8_t l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    bool t0;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[1] = { &l2 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_parser_decorator_spec(l0);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    l2 = l3.payload.obj;
    t0 = std_core____Contains_contains__vader_parser_DecoratorPlace(((vader_struct_vader_parser_DecoratorSpec_t*) l2)->f_places, l1);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_parser_decorator_spec(vader_string_t l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    int64_t l2, l3;
    vader_string_t t0 = 0;
    void** gc_raw_roots[2] = { &l1, &l4 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = __const_vader_parser_DECORATORS();
    l2 = ((vader_array_t*) l1)->length;
    l3 = INT64_C(0);
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        t0 = ((vader_struct_vader_parser_DecoratorSpec_t*) l4)->f_name;
        if (t0 == l0) {
            { vader_box_t __vret = vader_ref_box(l4); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l3 = (l3 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
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
        t0 = concat_3(990u, l1, 990u);
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
        { vader_gc_top = gc_frame.prev; return 2291u; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l0)->f_kind == INT32_C(0)) {
        { vader_gc_top = gc_frame.prev; return 1789u; }
    }
    t0 = ((vader_struct_vader_lexer_Token_t*) l0)->f_text;
    t1 = std_string_is_empty(t0);
    if (!(t1)) {
        l1 = ((vader_struct_vader_lexer_Token_t*) l0)->f_text;
        t0 = concat_3(990u, l1, 990u);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_lexer_kind_name(((vader_struct_vader_lexer_Token_t*) l0)->f_kind);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_desugar_comptime_const(void* l0, void* l1, uint8_t l2, void* l3, vader_box_t l4) {
    void* l5 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    vader_box_t l7 = vader_box_null();
    vader_string_t l10 = 0;
    int64_t l15, l16;
    bool t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l4, &l7 };
    void** gc_raw_roots[12] = { &l0, &l1, &l3, &l5, &l6, &l8, &l9, &l11, &l12, &l13, &l14, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l10 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l5 = vader_parser_advance(l0);
    l6 = vader_parser_advance(l0);
    t0 = vader_parser_check(l0, (uint8_t) 84);
    if (t0) {
        t1 = vader_parser_parse_block(l0);
        l7 = vader_ref_box(t1);
    } else {
        l7 = vader_parser_parse_expr(l0, INT32_C(0));
    }
    t1 = vader_parser_wrap_as_block(l7);
    l8 = vader_parser_lift_trailing_return(t1);
    l9 = vader_parser_peek_at(l0, INT32_C(-1));
    l10 = ((vader_struct_vader_lexer_Token_t*) l3)->f_text;
    l10 = concat_2(951u, l10);
    l11 = vader_parser_span_of(l0, l5, l9);
    l6 = vader_parser_span_of(l0, l5, l6);
    vader_array_t* _a0_arr = vader_array_new(54u, 0u, 13u, 658u);
    l12 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(43u, 0u, 13u, 606u);
    l13 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(40u, 0u, 13u, 590u);
    l14 = (void*) _a2_arr;
    vader_struct_toolchain_ast_FnDecl_t* _a3_obj = (vader_struct_toolchain_ast_FnDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FnDecl_t));
    vader_obj_header_init(_a3_obj, 605u);
    _a3_obj->f_span = l11;
    _a3_obj->f_id = INT64_C(0);
    _a3_obj->f_name = l10;
    _a3_obj->f_name_span = l6;
    _a3_obj->f_visibility = (uint8_t) 1;
    _a3_obj->f_type_params = l12;
    _a3_obj->f_params = l13;
    _a3_obj->f_return_type = l4;
    _a3_obj->f_body = vader_ref_box(l8);
    _a3_obj->f_decorators = l14;
    _a3_obj->f_sam_synthetic = false;
    _a3_obj->f_is_expression_bodied = true;
    _a3_obj->f_materialized = false;
    _a3_obj->f_comptime_synthetic = true;
    _a3_obj->f_trailing_comma = false;
    l6 = (void*) _a3_obj;
    vader_array_push_ref((vader_array_t*) ((vader_struct_vader_parser_Parser_t*) l0)->f_pending_decls, l6);
    l5 = vader_parser_span_of(l0, l5, l9);
    l6 = vader_parser_ident_expr(((vader_struct_vader_lexer_Token_t*) l3)->f_span, l10);
    vader_array_t* _a4_arr = vader_array_new(227u, 0u, 13u, 1503u);
    l8 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(38u, 0u, 13u, 584u);
    l11 = (void*) _a5_arr;
    vader_struct_toolchain_ast_CallExpr_t* _a6_obj = (vader_struct_toolchain_ast_CallExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_CallExpr_t));
    vader_obj_header_init(_a6_obj, 585u);
    _a6_obj->f_span = l5;
    _a6_obj->f_id = INT64_C(0);
    _a6_obj->f_callee = vader_ref_box(l6);
    _a6_obj->f_type_args = l8;
    _a6_obj->f_args = l11;
    _a6_obj->f_trailing_comma = false;
    l5 = (void*) _a6_obj;
    vader_array_t* _a7_arr = vader_array_new(40u, 0u, 13u, 590u);
    l6 = (void*) _a7_arr;
    l15 = ((vader_array_t*) l1)->length;
    vader_array_t* _a8_arr = vader_array_repeat((vader_array_t*) l6, (int64_t) l15);
    l6 = (void*) _a8_arr;
    l8 = l1;
    l15 = ((vader_array_t*) l8)->length;
    l16 = INT64_C(0);
    while ((l16 < l15)) {
        vader_array_t* _a9_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        l11 = vader_array_ref_load_obj(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l16);
        vader_array_push_ref((vader_array_t*) l6, l11);
        l16 = (l16 + INT64_C(1));
    }
    l8 = ((vader_struct_vader_lexer_Token_t*) l3)->f_span;
    vader_array_t* _a10_arr = vader_array_new(227u, 0u, 13u, 1503u);
    l11 = (void*) _a10_arr;
    vader_struct_toolchain_ast_Decorator_t* _a11_obj = (vader_struct_toolchain_ast_Decorator_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_Decorator_t));
    vader_obj_header_init(_a11_obj, 590u);
    _a11_obj->f_span = l8;
    _a11_obj->f_id = INT64_C(0);
    _a11_obj->f_name = 1702u;
    _a11_obj->f_args = l11;
    l8 = (void*) _a11_obj;
    vader_array_push_ref((vader_array_t*) l6, l8);
    l8 = vader_parser_span_of(l0, l3, l9);
    l10 = ((vader_struct_vader_lexer_Token_t*) l3)->f_text;
    l9 = ((vader_struct_vader_lexer_Token_t*) l3)->f_span;
    vader_struct_toolchain_ast_ConstDecl_t* _a12_obj = (vader_struct_toolchain_ast_ConstDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ConstDecl_t));
    vader_obj_header_init(_a12_obj, 588u);
    _a12_obj->f_span = l8;
    _a12_obj->f_id = INT64_C(0);
    _a12_obj->f_name = l10;
    _a12_obj->f_name_span = l9;
    _a12_obj->f_visibility = l2;
    _a12_obj->f_ty = l4;
    _a12_obj->f_value = vader_ref_box(l5);
    _a12_obj->f_decorators = l6;
    _a12_obj->f_comptime_body = l7;
    t1 = (void*) _a12_obj;
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

static bool vader_parser_ends_a_value(uint8_t l0) {
    bool l1;
    int32_t t0;
    t0 = vader_parser_bracket_step(l0);
    if ((t0 < INT32_C(0))) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(86);
    }
    if (l1) {
        return true;
    }
    return l0 == INT32_C(0);
}

static bool vader_parser_ends_its_line(void* l0, int32_t l1) {
    void* l2;
    int32_t l3, l4;
    void* t0;
    l2 = ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens;
    l3 = vader_chk_add(i32, l1, INT32_C(1));
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    l3 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) t0)->f_span)->f_start)->f_line;
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
    t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l1);
    l4 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) t0)->f_span)->f_end)->f_line;
    return (l3 > l4);
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
        vader_array_push_ref((vader_array_t*) l4, l5);
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
        l5 = concat_5(1826u, l2, 37u, l5, 289u);
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
        l4 = concat_5(1826u, l1, 37u, l4, 289u);
        vader_parser_error(l0, (uint8_t) 1, l3, l4);
        l2 = ((vader_struct_vader_lexer_Token_t*) l2)->f_span;
        vader_struct_vader_parser_StringLitInfo_t* _a0_obj = (vader_struct_vader_parser_StringLitInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_StringLitInfo_t));
        vader_obj_header_init(_a0_obj, 1206u);
        _a0_obj->f_text = 0u;
        _a0_obj->f_span = l2;
        t1 = (void*) _a0_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = vader_parser_advance(l0);
    vader_array_t* _a1_arr = vader_array_new(21u, 0u, 0u, 317u);
    t1 = (void*) _a1_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a2_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a2_obj, 575u);
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
                if (l6.tag == 317u) {
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
            vader_parser_error(l0, (uint8_t) 0, l8, 2098u);
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
    l4 = std_string_builder_StringBuilder_std_core_Display_to_string(l3);
    l2 = vader_parser_span_of(l0, l2, l5);
    vader_struct_vader_parser_StringLitInfo_t* _a3_obj = (vader_struct_vader_parser_StringLitInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_StringLitInfo_t));
    vader_obj_header_init(_a3_obj, 1206u);
    _a3_obj->f_text = l4;
    _a3_obj->f_span = l2;
    t1 = (void*) _a3_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_parser_generic_use_follows(void* l0, int32_t l1) {
    int32_t l2, l4;
    void* l3;
    uint8_t l5;
    bool l6;
    int64_t t0;
    int32_t t1;
    void* t2;
    bool t3;
    t0 = ((vader_array_t*) ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens)->length;
    l2 = ((int32_t) (int64_t) t0);
    t1 = vader_chk_add(i32, l1, INT32_C(1));
    if ((t1 >= l2)) {
        return false;
    }
    l3 = ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens;
    l4 = vader_chk_add(i32, l1, INT32_C(1));
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    t2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
    l5 = ((vader_struct_vader_lexer_Token_t*) t2)->f_kind;
    if (l5 == INT32_C(80)) {
        return true;
    }
    if (l5 == INT32_C(84)) {
        return true;
    }
    t3 = vader_parser_ends_a_value(l5);
    if (t3) {
        return true;
    }
    t3 = vader_parser_ends_its_line(l0, l1);
    if (t3) {
        return true;
    }
    if (l5 == INT32_C(87)) {
        t1 = vader_chk_add(i32, l1, INT32_C(2));
        l6 = (t1 < l2);
    } else {
        l6 = false;
    }
    if (l6) {
        l3 = ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens;
        l2 = vader_chk_add(i32, l1, INT32_C(2));
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
        t2 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l2);
        return ((vader_struct_vader_lexer_Token_t*) t2)->f_kind == INT32_C(2);
    }
    return false;
}

static int64_t vader_parser_header_budget(int64_t l0) {
    int64_t l1;
    l1 = INT64_C(4096);
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
    vader_obj_header_init(_a0_obj, 610u);
    _a0_obj->f_span = l0;
    _a0_obj->f_id = INT64_C(0);
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
    if (l0 == INT32_C(59)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a0_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a0_obj, 1200u);
        _a0_obj->f_has = true;
        _a0_obj->f_left_bp = INT32_C(10);
        _a0_obj->f_right_bp = INT32_C(11);
        _a0_obj->f_op = (uint8_t) 11;
        _a0_obj->f_non_assoc = false;
        l1 = (void*) _a0_obj;
        { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(58)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a1_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a1_obj, 1200u);
        _a1_obj->f_has = true;
        _a1_obj->f_left_bp = INT32_C(12);
        _a1_obj->f_right_bp = INT32_C(13);
        _a1_obj->f_op = (uint8_t) 10;
        _a1_obj->f_non_assoc = false;
        l1 = (void*) _a1_obj;
    } else if (l0 == INT32_C(50)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a2_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a2_obj, 1200u);
        _a2_obj->f_has = true;
        _a2_obj->f_left_bp = INT32_C(20);
        _a2_obj->f_right_bp = INT32_C(20);
        _a2_obj->f_op = (uint8_t) 12;
        _a2_obj->f_non_assoc = true;
        l1 = (void*) _a2_obj;
    } else if (l0 == INT32_C(51)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a3_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a3_obj, 1200u);
        _a3_obj->f_has = true;
        _a3_obj->f_left_bp = INT32_C(20);
        _a3_obj->f_right_bp = INT32_C(20);
        _a3_obj->f_op = (uint8_t) 13;
        _a3_obj->f_non_assoc = true;
        l1 = (void*) _a3_obj;
    } else if (l0 == INT32_C(56)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a4_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a4_obj, 1200u);
        _a4_obj->f_has = true;
        _a4_obj->f_left_bp = INT32_C(20);
        _a4_obj->f_right_bp = INT32_C(20);
        _a4_obj->f_op = (uint8_t) 21;
        _a4_obj->f_non_assoc = true;
        l1 = (void*) _a4_obj;
    } else if (l0 == INT32_C(57)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a5_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a5_obj, 1200u);
        _a5_obj->f_has = true;
        _a5_obj->f_left_bp = INT32_C(20);
        _a5_obj->f_right_bp = INT32_C(20);
        _a5_obj->f_op = (uint8_t) 22;
        _a5_obj->f_non_assoc = true;
        l1 = (void*) _a5_obj;
    } else if (l0 == INT32_C(52)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a6_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a6_obj, 1200u);
        _a6_obj->f_has = true;
        _a6_obj->f_left_bp = INT32_C(20);
        _a6_obj->f_right_bp = INT32_C(20);
        _a6_obj->f_op = (uint8_t) 14;
        _a6_obj->f_non_assoc = true;
        l1 = (void*) _a6_obj;
    } else if (l0 == INT32_C(53)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a7_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a7_obj, 1200u);
        _a7_obj->f_has = true;
        _a7_obj->f_left_bp = INT32_C(20);
        _a7_obj->f_right_bp = INT32_C(20);
        _a7_obj->f_op = (uint8_t) 15;
        _a7_obj->f_non_assoc = true;
        l1 = (void*) _a7_obj;
    } else if (l0 == INT32_C(54)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a8_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a8_obj, 1200u);
        _a8_obj->f_has = true;
        _a8_obj->f_left_bp = INT32_C(20);
        _a8_obj->f_right_bp = INT32_C(20);
        _a8_obj->f_op = (uint8_t) 16;
        _a8_obj->f_non_assoc = true;
        l1 = (void*) _a8_obj;
    } else if (l0 == INT32_C(55)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a9_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a9_obj, 1200u);
        _a9_obj->f_has = true;
        _a9_obj->f_left_bp = INT32_C(20);
        _a9_obj->f_right_bp = INT32_C(20);
        _a9_obj->f_op = (uint8_t) 17;
        _a9_obj->f_non_assoc = true;
        l1 = (void*) _a9_obj;
    } else if (l0 == INT32_C(19)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a10_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a10_obj, 1200u);
        _a10_obj->f_has = true;
        _a10_obj->f_left_bp = INT32_C(20);
        _a10_obj->f_right_bp = INT32_C(20);
        _a10_obj->f_op = (uint8_t) 18;
        _a10_obj->f_non_assoc = true;
        l1 = (void*) _a10_obj;
    } else if (l0 == INT32_C(21)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a11_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a11_obj, 1200u);
        _a11_obj->f_has = true;
        _a11_obj->f_left_bp = INT32_C(20);
        _a11_obj->f_right_bp = INT32_C(20);
        _a11_obj->f_op = (uint8_t) 19;
        _a11_obj->f_non_assoc = true;
        l1 = (void*) _a11_obj;
    } else if (l0 == INT32_C(73)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a12_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a12_obj, 1200u);
        _a12_obj->f_has = true;
        _a12_obj->f_left_bp = INT32_C(30);
        _a12_obj->f_right_bp = INT32_C(30);
        _a12_obj->f_op = (uint8_t) 14;
        _a12_obj->f_non_assoc = true;
        l1 = (void*) _a12_obj;
    } else if (l0 == INT32_C(74)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a13_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a13_obj, 1200u);
        _a13_obj->f_has = true;
        _a13_obj->f_left_bp = INT32_C(30);
        _a13_obj->f_right_bp = INT32_C(30);
        _a13_obj->f_op = (uint8_t) 15;
        _a13_obj->f_non_assoc = true;
        l1 = (void*) _a13_obj;
    } else if (l0 == INT32_C(75)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(45)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a14_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a14_obj, 1200u);
        _a14_obj->f_has = true;
        _a14_obj->f_left_bp = INT32_C(40);
        _a14_obj->f_right_bp = INT32_C(41);
        _a14_obj->f_op = (uint8_t) 8;
        _a14_obj->f_non_assoc = false;
        l1 = (void*) _a14_obj;
    } else if (l0 == INT32_C(46)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a15_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a15_obj, 1200u);
        _a15_obj->f_has = true;
        _a15_obj->f_left_bp = INT32_C(50);
        _a15_obj->f_right_bp = INT32_C(51);
        _a15_obj->f_op = (uint8_t) 9;
        _a15_obj->f_non_assoc = false;
        l1 = (void*) _a15_obj;
    } else if (l0 == INT32_C(44)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a16_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a16_obj, 1200u);
        _a16_obj->f_has = true;
        _a16_obj->f_left_bp = INT32_C(60);
        _a16_obj->f_right_bp = INT32_C(61);
        _a16_obj->f_op = (uint8_t) 7;
        _a16_obj->f_non_assoc = false;
        l1 = (void*) _a16_obj;
    } else if (l0 == INT32_C(48)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a17_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a17_obj, 1200u);
        _a17_obj->f_has = true;
        _a17_obj->f_left_bp = INT32_C(70);
        _a17_obj->f_right_bp = INT32_C(71);
        _a17_obj->f_op = (uint8_t) 5;
        _a17_obj->f_non_assoc = false;
        l1 = (void*) _a17_obj;
    } else if (l0 == INT32_C(49)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a18_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a18_obj, 1200u);
        _a18_obj->f_has = true;
        _a18_obj->f_left_bp = INT32_C(70);
        _a18_obj->f_right_bp = INT32_C(71);
        _a18_obj->f_op = (uint8_t) 6;
        _a18_obj->f_non_assoc = false;
        l1 = (void*) _a18_obj;
    } else if (l0 == INT32_C(36)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a19_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a19_obj, 1200u);
        _a19_obj->f_has = true;
        _a19_obj->f_left_bp = INT32_C(80);
        _a19_obj->f_right_bp = INT32_C(81);
        _a19_obj->f_op = (uint8_t) 0;
        _a19_obj->f_non_assoc = false;
        l1 = (void*) _a19_obj;
    } else if (l0 == INT32_C(37)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a20_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a20_obj, 1200u);
        _a20_obj->f_has = true;
        _a20_obj->f_left_bp = INT32_C(80);
        _a20_obj->f_right_bp = INT32_C(81);
        _a20_obj->f_op = (uint8_t) 1;
        _a20_obj->f_non_assoc = false;
        l1 = (void*) _a20_obj;
    } else if (l0 == INT32_C(38)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a21_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a21_obj, 1200u);
        _a21_obj->f_has = true;
        _a21_obj->f_left_bp = INT32_C(90);
        _a21_obj->f_right_bp = INT32_C(91);
        _a21_obj->f_op = (uint8_t) 2;
        _a21_obj->f_non_assoc = false;
        l1 = (void*) _a21_obj;
    } else if (l0 == INT32_C(39)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a22_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a22_obj, 1200u);
        _a22_obj->f_has = true;
        _a22_obj->f_left_bp = INT32_C(90);
        _a22_obj->f_right_bp = INT32_C(91);
        _a22_obj->f_op = (uint8_t) 3;
        _a22_obj->f_non_assoc = false;
        l1 = (void*) _a22_obj;
    } else if (l0 == INT32_C(40)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a23_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a23_obj, 1200u);
        _a23_obj->f_has = true;
        _a23_obj->f_left_bp = INT32_C(90);
        _a23_obj->f_right_bp = INT32_C(91);
        _a23_obj->f_op = (uint8_t) 4;
        _a23_obj->f_non_assoc = false;
        l1 = (void*) _a23_obj;
    } else if (l0 == INT32_C(41)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a24_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a24_obj, 1200u);
        _a24_obj->f_has = true;
        _a24_obj->f_left_bp = INT32_C(80);
        _a24_obj->f_right_bp = INT32_C(81);
        _a24_obj->f_op = (uint8_t) 23;
        _a24_obj->f_non_assoc = false;
        l1 = (void*) _a24_obj;
    } else if (l0 == INT32_C(42)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a25_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a25_obj, 1200u);
        _a25_obj->f_has = true;
        _a25_obj->f_left_bp = INT32_C(80);
        _a25_obj->f_right_bp = INT32_C(81);
        _a25_obj->f_op = (uint8_t) 24;
        _a25_obj->f_non_assoc = false;
        l1 = (void*) _a25_obj;
    } else if (l0 == INT32_C(43)) {
        vader_struct_vader_parser_InfixOpDescr_t* _a26_obj = (vader_struct_vader_parser_InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_InfixOpDescr_t));
        vader_obj_header_init(_a26_obj, 1200u);
        _a26_obj->f_has = true;
        _a26_obj->f_left_bp = INT32_C(90);
        _a26_obj->f_right_bp = INT32_C(91);
        _a26_obj->f_op = (uint8_t) 25;
        _a26_obj->f_non_assoc = false;
        l1 = (void*) _a26_obj;
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
    } else if (l0 == INT32_C(47)) {
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
    } else if (l0 == INT32_C(67)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(68)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(69)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(70)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(71)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(72)) {
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
    } else if (l0 == INT32_C(83)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(84)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(85)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(86)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(87)) {
        l1 = vader_parser_no_infix();
    } else if (l0 == INT32_C(88)) {
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
    void* l1 = NULL;
    void* l4 = NULL;
    int64_t l2, l3;
    vader_string_t t0 = 0;
    void** gc_raw_roots[2] = { &l1, &l4 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = __const_vader_parser_INTRINSICS();
    l2 = ((vader_array_t*) l1)->length;
    l3 = INT64_C(0);
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        t0 = ((vader_struct_vader_parser_IntrinsicSpec_t*) l4)->f_name;
        if (t0 == l0) {
            { vader_box_t __vret = vader_ref_box(l4); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l3 = (l3 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static bool vader_parser_is_angle_scan_bailout(uint8_t l0) {
    if (l0 == INT32_C(84)) {
        return true;
    }
    if (l0 == INT32_C(71)) {
        return true;
    }
    if (l0 == INT32_C(72)) {
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
    if (l0 == INT32_C(65)) {
        return true;
    }
    if (l0 == INT32_C(66)) {
        return true;
    }
    if (l0 == INT32_C(67)) {
        return true;
    }
    if (l0 == INT32_C(68)) {
        return true;
    }
    if (l0 == INT32_C(69)) {
        return true;
    }
    if (l0 == INT32_C(70)) {
        return true;
    }
    if (l0 == INT32_C(55)) {
        return true;
    }
    if (l0 == INT32_C(53)) {
        return true;
    }
    if (l0 == INT32_C(50)) {
        return true;
    }
    if (l0 == INT32_C(51)) {
        return true;
    }
    if (l0 == INT32_C(56)) {
        return true;
    }
    if (l0 == INT32_C(57)) {
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

vader_string_t vader_parser_is_binding_hint(vader_box_t l0, vader_string_t l1, bool l2) {
    vader_box_t l3 = vader_box_null();
    vader_string_t l4 = 0;
    vader_string_t l5 = 0;
    vader_string_t t0 = 0;
    vader_box_t* gc_roots[2] = { &l0, &l3 };
    vader_string_t* gc_atom_roots[4] = { &l1, &l4, &l5, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 0u, gc_roots, NULL, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_parser_place_text(l0);
    if (!(l3.tag == 0u)) {
        l4 = l3.payload.s;
        l5 = l3.payload.s;
        t0 = concat_7(990u, l4, 1106u, l1, 1008u, l5, 990u);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l2)) {
        t0 = concat_5(1554u, l1, 50u, l1, 137u);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = concat_5(1554u, l1, 50u, l1, 31u);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool vader_parser_is_evaluated(uint8_t l0) {
    bool l1;
    if (l0 == INT32_C(1)) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(2);
    }
    if (l1) {
        return true;
    }
    if (l0 == INT32_C(0)) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(3);
    }
    if (!(l1)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    return false;
}

static bool vader_parser_is_impl_decl(void* l0) {
    int32_t l1, l2, l3;
    void* l4;
    bool l5, l6, l7, l8;
    int64_t t0;
    l1 = INT32_C(0);
    t0 = ((vader_array_t*) ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens)->length;
    l2 = ((int32_t) (int64_t) t0);
    l3 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pos;
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        if (((vader_struct_vader_lexer_Token_t*) l4)->f_kind == INT32_C(0)) {
            return false;
        }
        if (((vader_struct_vader_lexer_Token_t*) l4)->f_kind == INT32_C(1)) {
            return false;
        }
        if (((vader_struct_vader_lexer_Token_t*) l4)->f_kind == INT32_C(14)) {
            if (l1 == INT32_C(0)) {
                return true;
            }
        }
        if (((vader_struct_vader_lexer_Token_t*) l4)->f_kind == INT32_C(80)) {
            l5 = true;
        } else {
            l5 = ((vader_struct_vader_lexer_Token_t*) l4)->f_kind == INT32_C(82);
        }
        if (l5) {
            l6 = true;
        } else {
            l6 = ((vader_struct_vader_lexer_Token_t*) l4)->f_kind == INT32_C(84);
        }
        if (l6) {
            l1 = vader_chk_add(i32, l1, INT32_C(1));
        }
        if (((vader_struct_vader_lexer_Token_t*) l4)->f_kind == INT32_C(81)) {
            l7 = true;
        } else {
            l7 = ((vader_struct_vader_lexer_Token_t*) l4)->f_kind == INT32_C(83);
        }
        if (l7) {
            l8 = true;
        } else {
            l8 = ((vader_struct_vader_lexer_Token_t*) l4)->f_kind == INT32_C(85);
        }
        if (l8) {
            l1 = vader_chk_sub(i32, l1, INT32_C(1));
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

static bool vader_parser_is_number_token(void* l0) {
    if (((vader_struct_vader_lexer_Token_t*) l0)->f_kind == INT32_C(3)) {
        return true;
    }
    return ((vader_struct_vader_lexer_Token_t*) l0)->f_kind == INT32_C(4);
}

static bool vader_parser_is_valid_module_name(vader_string_t l0) {
    bool l1, l10;
    vader_string_t l2;
    int64_t l3, l4, l8, l11;
    uint8_t l5;
    uint32_t l6, l9;
    uint32_t l7;
    bool t0;
    uint32_t t1;
    int64_t t2;
    l1 = true;
    l2 = l0;
    l3 = INT64_C(0);
    for (;;) {
        l4 = vader_host_std_core_byte_len(l2);
        if ((l3 < l4)) {
            l5 = vader_host_std_core_byte_at(l2, l3);
            if ((l5 < INT32_C(128))) {
                l3 = vader_chk_add(i64, l3, INT64_C(1));
                l6 = ((uint32_t) (uint8_t) l5);
                if (l1) {
                    t0 = vader_parser_is_module_segment_start(l6);
                    if (!(t0)) {
                        return false;
                    }
                    l1 = false;
                } else if (l6 == 47u) {
                    l1 = true;
                } else {
                    t0 = vader_parser_is_module_segment_continue(l6);
                    if (!(t0)) {
                        return false;
                    }
                }
                continue;
            }
            std_core_decode_tail(l2, l5, l3, &t1, &t2);
            l11 = t2;
            l7 = t1;
            l8 = l11;
            l3 = vader_chk_add(i64, l3, l8);
            if ((l7 > INT32_C(55295))) {
                if ((l7 < INT32_C(57344))) {
                    l10 = true;
                } else {
                    l10 = (l7 > INT32_C(1114111));
                }
                if (l10) {
                    vader_unreachable("value out of range: no Unicode scalar value");
                }
            }
            l9 = ((uint32_t) (uint32_t) l7);
            if (l1) {
                t0 = vader_parser_is_module_segment_start(l9);
                if (!(t0)) {
                    return false;
                }
                l1 = false;
            } else if (l9 == 47u) {
                l1 = true;
            } else {
                t0 = vader_parser_is_module_segment_continue(l9);
                if (!(t0)) {
                    return false;
                }
            }
            continue;
        }
        break;
    }
    return !(l1);
}

static uint8_t vader_parser_kind_after_bracket_group(void* l0) {
    int32_t l1, l2, l3;
    uint8_t l4;
    int32_t t0;
    int64_t t1;
    void* t2;
    l1 = INT32_C(1);
    t0 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pos;
    l2 = vader_chk_add(i32, t0, INT32_C(1));
    t1 = ((vader_array_t*) ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens)->length;
    l3 = ((int32_t) (int64_t) t1);
    while ((l2 < l3)) {
        if (!((l1 > INT32_C(0)))) {
            break;
        }
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        t2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        l4 = ((vader_struct_vader_lexer_Token_t*) t2)->f_kind;
        if (l4 == INT32_C(0)) {
            return (uint8_t) 0;
        }
        if (l4 == INT32_C(82)) {
            l1 = vader_chk_add(i32, l1, INT32_C(1));
        } else if (l4 == INT32_C(83)) {
            l1 = vader_chk_sub(i32, l1, INT32_C(1));
            if (l1 == INT32_C(0)) break;
        }
        l2 = vader_chk_add(i32, l2, INT32_C(1));
    }
    if (l1 != INT32_C(0)) {
        return (uint8_t) 0;
    }
    l1 = vader_chk_add(i32, l2, INT32_C(1));
    while ((l1 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
        t2 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l1);
        if (!(((vader_struct_vader_lexer_Token_t*) t2)->f_kind == INT32_C(1))) {
            break;
        }
        l1 = vader_chk_add(i32, l1, INT32_C(1));
    }
    if (!((l1 >= l3))) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l1)
        t2 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l1);
        return ((vader_struct_vader_lexer_Token_t*) t2)->f_kind;
    }
    return (uint8_t) 0;
}

static void* vader_parser_lift_trailing_return(void* l0) {
    int64_t l1, l3;
    void* l2 = NULL;
    void* l6 = NULL;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l4, &l5 };
    void** gc_raw_roots[4] = { &l0, &l2, &l6, &t0 };
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
    l3 = vader_chk_sub(i64, l1, INT64_C(1));
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    if (l4.tag == 642u) {
        t0 = l4.payload.obj;
        if (((vader_struct_toolchain_ast_ReturnStmt_t*) t0)->f_value.tag == 0u) {
            { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_array_t* _a1_arr = vader_array_new(229u, 0u, 13u, 1536u);
        l2 = (void*) _a1_arr;
        l3 = INT64_C(0);
        l1 = vader_chk_sub(i64, l1, INT64_C(1));
        while ((l3 < l1)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_BlockExpr_t*) l0)->f_stmts);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
            l5 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l3);
            vader_array_push_ref((vader_array_t*) l2, l5.payload.obj);
            l3 = (l3 + INT64_C(1));
        }
        l6 = ((vader_struct_toolchain_ast_BlockExpr_t*) l0)->f_span;
        t0 = l4.payload.obj;
        l4 = ((vader_struct_toolchain_ast_ReturnStmt_t*) t0)->f_value;
        vader_struct_toolchain_ast_BlockExpr_t* _a3_obj = (vader_struct_toolchain_ast_BlockExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BlockExpr_t));
        vader_obj_header_init(_a3_obj, 581u);
        _a3_obj->f_span = l6;
        _a3_obj->f_id = INT64_C(0);
        _a3_obj->f_stmts = l2;
        _a3_obj->f_trailing = l4;
        t0 = (void*) _a3_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_parser_looks_like_for_destructure(void* l0) {
    int32_t l1, l2, l4;
    void* l3;
    bool t0;
    t0 = vader_parser_check(l0, (uint8_t) 82);
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
        if (((vader_struct_vader_lexer_Token_t*) l3)->f_kind == INT32_C(82)) {
            l1 = vader_chk_add(i32, l1, INT32_C(1));
        } else if (((vader_struct_vader_lexer_Token_t*) l3)->f_kind == INT32_C(83)) {
            l1 = vader_chk_sub(i32, l1, INT32_C(1));
            if (l1 == INT32_C(0)) {
                l4 = vader_chk_add(i32, l2, INT32_C(1));
                t0 = vader_parser_check_at(l0, (uint8_t) 21, l4);
                return t0;
            }
        }
        l2 = vader_chk_add(i32, l2, INT32_C(1));
    }
    return false;
}

static bool vader_parser_looks_like_struct_lit_body(void* l0, int32_t l1) {
    int32_t l2, l3;
    void* l4;
    bool l5;
    int64_t t0;
    t0 = ((vader_array_t*) l0)->length;
    l2 = ((int32_t) (int64_t) t0);
    l3 = vader_chk_add(i32, l1, INT32_C(1));
    for (;;) {
        if ((l3 < l2)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
            if (((vader_struct_vader_lexer_Token_t*) l4)->f_kind == INT32_C(1)) {
                l3 = vader_chk_add(i32, l3, INT32_C(1));
                continue;
            }
            if (((vader_struct_vader_lexer_Token_t*) l4)->f_kind == INT32_C(87)) {
                l5 = true;
            } else {
                l5 = ((vader_struct_vader_lexer_Token_t*) l4)->f_kind == INT32_C(75);
            }
            if (l5) {
                return true;
            }
            return ((vader_struct_vader_lexer_Token_t*) l4)->f_kind == INT32_C(85);
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

static vader_box_t vader_parser_match_scrutinee(void* l0, vader_box_t l1) {
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t1 };
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(l1.tag == 0u)) {
        t0 = l1.payload.obj;
        { vader_box_t __vret = ((vader_struct_toolchain_ast_LetStmt_t*) t0)->f_value; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_parser_parse_expr(l0, INT32_C(0));
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_merge_type_params(void* l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    int64_t l3, l5, l9, l10;
    bool l7;
    vader_string_t l11 = 0;
    vader_string_t l12 = 0;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l4, &l6, &l8, &t1 };
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
    vader_array_t* _a0_arr = vader_array_new(54u, 0u, 13u, 658u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_array_t*) l0)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a1_arr;
    l4 = l0;
    l3 = ((vader_array_t*) l4)->length;
    l5 = INT64_C(0);
    while ((l5 < l3)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l6 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
        vader_array_push_ref((vader_array_t*) l2, l6);
        l5 = (l5 + INT64_C(1));
    }
    l4 = l1;
    l3 = ((vader_array_t*) l4)->length;
    l5 = INT64_C(0);
    while ((l5 < l3)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        l6 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l5);
        l7 = false;
        l8 = l2;
        l9 = ((vader_array_t*) l8)->length;
        l10 = INT64_C(0);
        while ((l10 < l9)) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            t1 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l10);
            l11 = ((vader_struct_toolchain_ast_TypeParam_t*) t1)->f_name;
            l12 = ((vader_struct_toolchain_ast_TypeParam_t*) l6)->f_name;
            if (l11 == l12) {
                l7 = true;
                break;
            }
            l10 = (l10 + INT64_C(1));
        }
        if (!(l7)) {
            vader_array_push_ref((vader_array_t*) l2, l6);
        }
        l5 = (l5 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

int64_t vader_parser_mint(void* l0) {
    int64_t l1, l2;
    l1 = ((vader_struct_vader_parser_NodeIdFactory_t*) l0)->f_next;
    l2 = vader_chk_add(i64, l1, INT64_C(1));
    ((vader_struct_vader_parser_NodeIdFactory_t*) l0)->f_next = l2;
    return l1;
}

void* vader_parser_new_node_id_factory(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_parser_NodeIdFactory_t* _a0_obj = (vader_struct_vader_parser_NodeIdFactory_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_NodeIdFactory_t));
    vader_obj_header_init(_a0_obj, 1203u);
    _a0_obj->f_next = INT64_C(1);
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
    vader_array_t* _a0_arr = vader_array_new(91u, 0u, 13u, 954u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(228u, 0u, 13u, 1529u);
    l3 = (void*) _a1_arr;
    vader_struct_vader_parser_Parser_t* _a2_obj = (vader_struct_vader_parser_Parser_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_Parser_t));
    vader_obj_header_init(_a2_obj, 1205u);
    _a2_obj->f_tokens = l0;
    _a2_obj->f_file = l1;
    _a2_obj->f_pos = INT32_C(0);
    _a2_obj->f_errors = l2;
    _a2_obj->f_bracket_depth = INT32_C(0);
    _a2_obj->f_no_struct_lit_at = INT32_C(-1);
    _a2_obj->f_no_bare_lambda_at = INT32_C(-1);
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
    vader_obj_header_init(_a0_obj, 1200u);
    _a0_obj->f_has = false;
    _a0_obj->f_left_bp = INT32_C(0);
    _a0_obj->f_right_bp = INT32_C(0);
    _a0_obj->f_op = (uint8_t) 0;
    _a0_obj->f_non_assoc = false;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_parser_number_literal(void* l0, void* l1, bool l2) {
    vader_box_t l3 = vader_box_null();
    double l4;
    uint64_t l5;
    int64_t l6;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_lexer_Token_t*) l0)->f_value;
    if (((vader_struct_vader_lexer_Token_t*) l0)->f_kind == INT32_C(4)) {
        l4 = 0.0;
        if ((l3.tag == 326u || l3.tag == 327u)) {
            l4 = ((double) l3.payload.f);
        }
        if (!(l2)) {
            vader_struct_toolchain_ast_FloatLitExpr_t* _a0_obj = (vader_struct_toolchain_ast_FloatLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FloatLitExpr_t));
            vader_obj_header_init(_a0_obj, 604u);
            _a0_obj->f_span = l1;
            _a0_obj->f_id = INT64_C(0);
            _a0_obj->f_value = l4;
            t0 = (void*) _a0_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l4 = -(l4);
        vader_struct_toolchain_ast_FloatLitExpr_t* _a1_obj = (vader_struct_toolchain_ast_FloatLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FloatLitExpr_t));
        vader_obj_header_init(_a1_obj, 604u);
        _a1_obj->f_span = l1;
        _a1_obj->f_id = INT64_C(0);
        _a1_obj->f_value = l4;
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = (uint64_t) 0;
    if (l3.tag == 325u) {
        l5 = ((uint64_t) l3.payload.i);
        l6 = INT64_C(0);
        vader_struct_toolchain_ast_IntLitExpr_t* _a2_obj = (vader_struct_toolchain_ast_IntLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_IntLitExpr_t));
        vader_obj_header_init(_a2_obj, 620u);
        _a2_obj->f_span = l1;
        _a2_obj->f_id = l6;
        _a2_obj->f_value = l5;
        _a2_obj->f_negative = l2;
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = INT64_C(0);
    vader_struct_toolchain_ast_IntLitExpr_t* _a3_obj = (vader_struct_toolchain_ast_IntLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_IntLitExpr_t));
    vader_obj_header_init(_a3_obj, 620u);
    _a3_obj->f_span = l1;
    _a3_obj->f_id = l6;
    _a3_obj->f_value = l5;
    _a3_obj->f_negative = l2;
    t0 = (void*) _a3_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_angle_type_params(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l9 = NULL;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    vader_string_t l8 = 0;
    bool t0;
    void* t1 = NULL;
    int64_t t2;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l4, &l5, &t3 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l6, &l7, &l9, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l8 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_parser_check(l0, (uint8_t) 52);
    if (!(t0)) {
        vader_array_t* _a0_arr = vader_array_new(54u, 0u, 13u, 658u);
        t1 = (void*) _a0_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_parser_advance(l0);
    vader_array_t* _a1_arr = vader_array_new(54u, 0u, 13u, 658u);
    l1 = (void*) _a1_arr;
    vader_parser_skip_newlines(l0);
    for (;;) {
        t0 = vader_parser_check(l0, (uint8_t) 0);
        if (!(t0)) {
            t0 = vader_parser_check_closing_angle(l0);
            if (t0) break;
            t2 = ((vader_array_t*) l1)->length;
            if ((t2 > INT64_C(0))) {
                t3 = vader_parser_match_kind(l0, (uint8_t) 86);
                if (t3.tag == 0u) break;
                vader_parser_skip_newlines(l0);
                t0 = vader_parser_check_closing_angle(l0);
                if (t0) break;
            }
            l2 = vader_parser_peek(l0);
            l3 = vader_parser_expect(l0, (uint8_t) 2, 2653u);
            l4 = vader_box_obj(0u, NULL);
            t3 = vader_parser_match_kind(l0, (uint8_t) 88);
            if (!(t3.tag == 0u)) {
                vader_parser_skip_newlines(l0);
                l4 = vader_parser_parse_type(l0);
            }
            l5 = vader_box_obj(0u, NULL);
            t3 = vader_parser_match_kind(l0, (uint8_t) 62);
            if (!(t3.tag == 0u)) {
                vader_parser_skip_newlines(l0);
                l5 = vader_parser_parse_type(l0);
            }
            l6 = vader_parser_peek_at(l0, INT32_C(-1));
            l7 = vader_parser_span_of(l0, l2, l6);
            l8 = ((vader_struct_vader_lexer_Token_t*) l3)->f_text;
            vader_struct_toolchain_ast_TypeParam_t* _a2_obj = (vader_struct_toolchain_ast_TypeParam_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_TypeParam_t));
            vader_obj_header_init(_a2_obj, 658u);
            _a2_obj->f_span = l7;
            _a2_obj->f_id = INT64_C(0);
            _a2_obj->f_name = l8;
            _a2_obj->f_bound = l4;
            _a2_obj->f_default_v = l5;
            _a2_obj->f_is_comptime_value = false;
            l9 = (void*) _a2_obj;
            vader_array_push_ref((vader_array_t*) l1, l9);
            continue;
        }
        break;
    }
    t0 = vader_parser_check_closing_angle(l0);
    if (t0) {
        vader_parser_consume_closing_angle(l0);
        { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_parser_expect(l0, (uint8_t) 54, 1276u);
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_any_let(void* l0) {
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[2] = { &l0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_parser_check(l0, (uint8_t) 82);
    if (t0) {
        t1 = vader_parser_parse_tuple_let(l0);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_parser_check_at(l0, (uint8_t) 88, INT32_C(1));
    if (!(t0)) {
        t1 = vader_parser_parse_let(l0);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_parser_parse_typed_let(l0);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_parser_parse_assert_decl(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    bool l2;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null(), l6 = vader_box_null();
    int64_t t0;
    vader_string_t t1 = 0;
    vader_box_t t2 = vader_box_null();
    void* t3 = NULL;
    vader_box_t* gc_roots[4] = { &l4, &l5, &l6, &t2 };
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &t3 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_parse_decorator(l0);
    vader_parser_skip_newlines(l0);
    t0 = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l1)->f_args)->length;
    if ((t0 < INT64_C(1))) {
        l2 = true;
    } else {
        t0 = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l1)->f_args)->length;
        l2 = (t0 > INT64_C(2));
    }
    if (l2) {
        l3 = ((vader_struct_toolchain_ast_Decorator_t*) l1)->f_span;
        vader_parser_error(l0, (uint8_t) 18, l3, 1281u);
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l4 = vader_box_obj(0u, NULL);
    l5 = vader_box_obj(0u, NULL);
    t0 = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l1)->f_args)->length;
    if (t0 == INT64_C(2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l1)->f_args);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(1))
        l6 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(1));
        l6 = vader_parser_static_assert_message(l0, l6);
        if (l6.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
        }
        t1 = l6.payload.s;
        l4 = vader_box_string(317u, t1);
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l1)->f_args);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(1))
        t2 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT32_C(1));
        t3 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, t2.payload.obj);
        l5 = vader_ref_box(t3);
    }
    l3 = ((vader_struct_toolchain_ast_Decorator_t*) l1)->f_span;
    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l1)->f_args);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(0))
    l6 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT32_C(0));
    vader_array_t* _a3_arr = vader_array_new(40u, 0u, 13u, 590u);
    l1 = (void*) _a3_arr;
    vader_struct_toolchain_ast_AssertDecl_t* _a4_obj = (vader_struct_toolchain_ast_AssertDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_AssertDecl_t));
    vader_obj_header_init(_a4_obj, 577u);
    _a4_obj->f_span = l3;
    _a4_obj->f_id = INT64_C(0);
    _a4_obj->f_condition = l6;
    _a4_obj->f_message = l4;
    _a4_obj->f_message_span = l5;
    _a4_obj->f_decorators = l1;
    t3 = (void*) _a4_obj;
    { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_parser_parse_assign_target(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    vader_box_t l2 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    bool t2;
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[2] = { &l2, &t0 };
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &t1 };
    vader_string_t* gc_atom_roots[1] = { &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_peek(l0);
    t0 = vader_parser_match_kind(l0, (uint8_t) 75);
    if (!(t0.tag == 0u)) {
        l2 = vader_parser_parse_expr(l0, INT32_C(0));
        l3 = vader_parser_peek_at(l0, INT32_C(-1));
        t1 = vader_parser_span_of(l0, l1, l3);
        vader_struct_toolchain_ast_RestTarget_t* _a0_obj = (vader_struct_toolchain_ast_RestTarget_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_RestTarget_t));
        vader_obj_header_init(_a0_obj, 641u);
        _a0_obj->f_span = t1;
        _a0_obj->f_id = INT64_C(0);
        _a0_obj->f_place = l2;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_parser_check(l0, (uint8_t) 2);
    if (t2) {
        t1 = vader_parser_peek(l0);
        t3 = ((vader_struct_vader_lexer_Token_t*) t1)->f_text;
        if (t3 == 928u) {
            t1 = vader_parser_advance(l0);
            vader_struct_toolchain_ast_WildcardTarget_t* _a1_obj = (vader_struct_toolchain_ast_WildcardTarget_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_WildcardTarget_t));
            vader_obj_header_init(_a1_obj, 664u);
            _a1_obj->f_span = ((vader_struct_vader_lexer_Token_t*) t1)->f_span;
            _a1_obj->f_id = INT64_C(0);
            t1 = (void*) _a1_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l2 = vader_parser_parse_expr(l0, INT32_C(0));
    vader_struct_toolchain_ast_PlaceTarget_t* _a2_obj = (vader_struct_toolchain_ast_PlaceTarget_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_PlaceTarget_t));
    vader_obj_header_init(_a2_obj, 636u);
    _a2_obj->f_span = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, l2.payload.obj);
    _a2_obj->f_id = INT64_C(0);
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
    int64_t l16, l18;
    bool l17;
    int32_t t0;
    bool t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[3] = { &l5, &l6, &l19 };
    void** gc_raw_roots[14] = {
        &l0, &l1, &l3, &l4, &l7, &l8, &l9, &l10, &l11, &l12, &l13, &l14, &l15, &t2,
    };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 14u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_expect(l0, (uint8_t) 84, 1351u);
    t0 = ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth;
    l2 = vader_chk_add(i32, t0, INT32_C(1));
    ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth = l2;
    t0 = ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth;
    if ((t0 > INT32_C(256))) {
        t0 = ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth;
        l2 = vader_chk_sub(i32, t0, INT32_C(1));
        ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth = l2;
        vader_parser_report_nesting_too_deep(l0, 1563u);
        l2 = INT32_C(1);
        while ((l2 > INT32_C(0))) {
            t1 = vader_parser_check(l0, (uint8_t) 0);
            if (t1) break;
            l3 = vader_parser_advance(l0);
            if (((vader_struct_vader_lexer_Token_t*) l3)->f_kind == INT32_C(84)) {
                l2 = vader_chk_add(i32, l2, INT32_C(1));
            }
            if (!(((vader_struct_vader_lexer_Token_t*) l3)->f_kind == INT32_C(85))) {
                continue;
            }
            l2 = vader_chk_sub(i32, l2, INT32_C(1));
        }
        l3 = vader_parser_peek_at(l0, INT32_C(-1));
        l3 = vader_parser_span_of(l0, l1, l3);
        vader_array_t* _a0_arr = vader_array_new(229u, 0u, 13u, 1536u);
        l4 = (void*) _a0_arr;
        vader_struct_toolchain_ast_BlockExpr_t* _a1_obj = (vader_struct_toolchain_ast_BlockExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BlockExpr_t));
        vader_obj_header_init(_a1_obj, 581u);
        _a1_obj->f_span = l3;
        _a1_obj->f_id = INT64_C(0);
        _a1_obj->f_stmts = l4;
        _a1_obj->f_trailing = vader_box_obj(0u, NULL);
        t2 = (void*) _a1_obj;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_parser_skip_newlines(l0);
    vader_array_t* _a2_arr = vader_array_new(229u, 0u, 13u, 1536u);
    l3 = (void*) _a2_arr;
    l5 = vader_box_obj(0u, NULL);
    for (;;) {
        t1 = vader_parser_check(l0, (uint8_t) 85);
        if (!(t1)) {
            t1 = vader_parser_check(l0, (uint8_t) 0);
            if (t1) break;
            l6 = vader_parser_parse_stmt(l0);
            if (!(l6.tag == 0u)) {
                if (l6.tag == 624u) {
                    l4 = l6.payload.obj;
                    vader_array_push_ref((vader_array_t*) l3, l4);
                } else if (l6.tag == 578u) {
                    l7 = l6.payload.obj;
                    vader_array_push_ref((vader_array_t*) l3, l7);
                } else if (l6.tag == 594u) {
                    l8 = l6.payload.obj;
                    vader_array_push_ref((vader_array_t*) l3, l8);
                } else if (l6.tag == 602u) {
                    l9 = l6.payload.obj;
                    vader_array_push_ref((vader_array_t*) l3, l9);
                } else if (l6.tag == 642u) {
                    l10 = l6.payload.obj;
                    vader_array_push_ref((vader_array_t*) l3, l10);
                } else if (l6.tag == 665u) {
                    l11 = l6.payload.obj;
                    vader_array_push_ref((vader_array_t*) l3, l11);
                } else if (l6.tag == 608u) {
                    l12 = l6.payload.obj;
                    vader_array_push_ref((vader_array_t*) l3, l12);
                } else if (l6.tag == 583u) {
                    l13 = l6.payload.obj;
                    vader_array_push_ref((vader_array_t*) l3, l13);
                } else if (l6.tag == 589u) {
                    l14 = l6.payload.obj;
                    vader_array_push_ref((vader_array_t*) l3, l14);
                } else {
                    if (!(l6.tag == 592u)) {
                        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                    }
                    l15 = l6.payload.obj;
                    vader_array_push_ref((vader_array_t*) l3, l15);
                }
            }
            vader_parser_skip_newlines(l0);
            continue;
        }
        break;
    }
    vader_array_t* _a3_arr = vader_array_new(229u, 0u, 13u, 1536u);
    l4 = (void*) _a3_arr;
    l16 = ((vader_array_t*) l3)->length;
    l17 = false;
    l6 = vader_box_obj(0u, NULL);
    if ((l16 > INT64_C(0))) {
        l18 = vader_chk_sub(i64, l16, INT64_C(1));
        vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        l19 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l18);
        if (l19.tag == 602u) {
            l17 = true;
            t2 = l19.payload.obj;
            l6 = ((vader_struct_toolchain_ast_ExprStmt_t*) t2)->f_expr;
        } else if (!(l19.tag == 624u)) {
            if (!(l19.tag == 578u)) {
                if (!(l19.tag == 594u)) {
                    if (!(l19.tag == 642u)) {
                        if (!(l19.tag == 665u)) {
                            if (!(l19.tag == 608u)) {
                                if (!(l19.tag == 583u)) {
                                    if (!(l19.tag == 589u)) {
                                        if (!(l19.tag == 592u)) {
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
        l18 = vader_chk_sub(i64, l16, INT64_C(1));
    } else {
        l18 = l16;
    }
    l16 = INT64_C(0);
    while ((l16 < l18)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l16)
        l19 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l16);
        vader_array_push_ref((vader_array_t*) l4, l19.payload.obj);
        l16 = (l16 + INT64_C(1));
    }
    if (l17) {
        if (!(l6.tag == 0u)) {
            l5 = l6;
        }
    }
    l3 = vader_parser_expect(l0, (uint8_t) 85, 1357u);
    t0 = ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth;
    l2 = vader_chk_sub(i32, t0, INT32_C(1));
    ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth = l2;
    t2 = vader_parser_span_of(l0, l1, l3);
    vader_struct_toolchain_ast_BlockExpr_t* _a6_obj = (vader_struct_toolchain_ast_BlockExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BlockExpr_t));
    vader_obj_header_init(_a6_obj, 581u);
    _a6_obj->f_span = t2;
    _a6_obj->f_id = INT64_C(0);
    _a6_obj->f_stmts = l4;
    _a6_obj->f_trailing = l5;
    t2 = (void*) _a6_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_break(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    vader_box_t l2 = vader_box_null();
    bool t0;
    void* t1 = NULL;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &t1 };
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
        l2 = vader_box_string(317u, t2);
    }
    l3 = vader_parser_peek_at(l0, INT32_C(-1));
    t1 = vader_parser_span_of(l0, l1, l3);
    vader_struct_toolchain_ast_BreakStmt_t* _a0_obj = (vader_struct_toolchain_ast_BreakStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BreakStmt_t));
    vader_obj_header_init(_a0_obj, 583u);
    _a0_obj->f_span = t1;
    _a0_obj->f_id = INT64_C(0);
    _a0_obj->f_label = l2;
    t1 = (void*) _a0_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_call_args(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    void* l5 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l10 = NULL;
    void* l12 = NULL;
    bool l2, l4;
    vader_box_t l6 = vader_box_null(), l11 = vader_box_null();
    vader_string_t l9 = 0;
    bool t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l6, &l11, &t2 };
    void** gc_raw_roots[9] = { &l0, &l1, &l3, &l5, &l7, &l8, &l10, &l12, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(38u, 0u, 13u, 584u);
    l1 = (void*) _a0_arr;
    l2 = false;
    vader_parser_skip_newlines(l0);
    t0 = vader_parser_check(l0, (uint8_t) 81);
    if (t0) {
        vader_struct_vader_parser_CommaList__Any_t* _a1_obj = (vader_struct_vader_parser_CommaList__Any_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_CommaList__Any_t));
        vader_obj_header_init(_a1_obj, 1192u);
        _a1_obj->f_items = l1;
        _a1_obj->f_trailing_comma = false;
        t1 = (void*) _a1_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    for (;;) {
        vader_parser_skip_newlines(l0);
        t0 = vader_parser_check(l0, (uint8_t) 81);
        if (!(t0)) {
            l3 = vader_parser_peek(l0);
            t0 = vader_parser_check(l0, (uint8_t) 2);
            if (t0) {
                l4 = vader_parser_check_at(l0, (uint8_t) 62, INT32_C(1));
            } else {
                l4 = false;
            }
            if (l4) {
                l5 = vader_parser_advance(l0);
                vader_parser_advance(l0);
                l6 = vader_parser_parse_expr(l0, INT32_C(0));
                l7 = vader_parser_peek_at(l0, INT32_C(-1));
                l8 = vader_parser_span_of(l0, l3, l7);
                l9 = ((vader_struct_vader_lexer_Token_t*) l5)->f_text;
                vader_struct_toolchain_ast_CallArg_t* _a2_obj = (vader_struct_toolchain_ast_CallArg_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_CallArg_t));
                vader_obj_header_init(_a2_obj, 584u);
                _a2_obj->f_span = l8;
                _a2_obj->f_id = INT64_C(0);
                _a2_obj->f_name = vader_box_string(317u, l9);
                _a2_obj->f_value = l6;
                _a2_obj->f_spread = false;
                l10 = (void*) _a2_obj;
                vader_array_push_ref((vader_array_t*) l1, l10);
            } else {
                l11 = vader_parser_parse_expr(l0, INT32_C(0));
                vader_struct_toolchain_ast_CallArg_t* _a3_obj = (vader_struct_toolchain_ast_CallArg_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_CallArg_t));
                vader_obj_header_init(_a3_obj, 584u);
                _a3_obj->f_span = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, l11.payload.obj);
                _a3_obj->f_id = INT64_C(0);
                _a3_obj->f_name = vader_box_obj(0u, NULL);
                _a3_obj->f_value = l11;
                _a3_obj->f_spread = false;
                l12 = (void*) _a3_obj;
                vader_array_push_ref((vader_array_t*) l1, l12);
            }
            vader_parser_skip_newlines(l0);
            t2 = vader_parser_match_kind(l0, (uint8_t) 86);
            if (t2.tag == 0u) break;
            vader_parser_skip_newlines(l0);
            l2 = vader_parser_check(l0, (uint8_t) 81);
            continue;
        }
        break;
    }
    vader_struct_vader_parser_CommaList__Any_t* _a4_obj = (vader_struct_vader_parser_CommaList__Any_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_CommaList__Any_t));
    vader_obj_header_init(_a4_obj, 1192u);
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
    void* l5 = NULL;
    void* l7 = NULL;
    vader_string_t l6 = 0;
    bool t0;
    void* t1 = NULL;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[6] = { &l0, &l1, &l3, &l5, &l7, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l6, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_parser_reject_free_fn_decorators(l0, l1, 1389u, 59u);
    vader_parser_match_kind(l0, (uint8_t) 45);
    t0 = vader_parser_check(l0, (uint8_t) 78);
    if (t0) {
        t1 = vader_parser_peek_at(l0, INT32_C(1));
        if (((vader_struct_vader_lexer_Token_t*) t1)->f_kind == INT32_C(2)) {
            t1 = vader_parser_peek_at(l0, INT32_C(1));
            t2 = ((vader_struct_vader_lexer_Token_t*) t1)->f_text;
            if (t2 == 1702u) {
                t1 = vader_parser_desugar_comptime_const(l0, l1, l2, l3, vader_box_obj(0u, NULL));
                { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
    }
    l4 = vader_parser_parse_expr(l0, INT32_C(0));
    l5 = vader_parser_peek_at(l0, INT32_C(-1));
    l5 = vader_parser_span_of(l0, l3, l5);
    l6 = ((vader_struct_vader_lexer_Token_t*) l3)->f_text;
    l7 = ((vader_struct_vader_lexer_Token_t*) l3)->f_span;
    vader_struct_toolchain_ast_ConstDecl_t* _a0_obj = (vader_struct_toolchain_ast_ConstDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ConstDecl_t));
    vader_obj_header_init(_a0_obj, 588u);
    _a0_obj->f_span = l5;
    _a0_obj->f_id = INT64_C(0);
    _a0_obj->f_name = l6;
    _a0_obj->f_name_span = l7;
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
    void* l3 = NULL;
    vader_box_t l2 = vader_box_null();
    bool t0;
    void* t1 = NULL;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &t1 };
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
        l2 = vader_box_string(317u, t2);
    }
    l3 = vader_parser_peek_at(l0, INT32_C(-1));
    t1 = vader_parser_span_of(l0, l1, l3);
    vader_struct_toolchain_ast_ContinueStmt_t* _a0_obj = (vader_struct_toolchain_ast_ContinueStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ContinueStmt_t));
    vader_obj_header_init(_a0_obj, 589u);
    _a0_obj->f_span = t1;
    _a0_obj->f_id = INT64_C(0);
    _a0_obj->f_label = l2;
    t1 = (void*) _a0_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_parser_parse_decl(void* l0) {
    void* l1 = NULL;
    uint8_t l2;
    vader_box_t l3 = vader_box_null();
    bool t0;
    void* t1 = NULL;
    vader_string_t t2 = 0;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l3, &t3 };
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_string_t* gc_atom_roots[1] = { &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_parser_check(l0, (uint8_t) 78);
    if (t0) {
        t0 = vader_parser_check_at(l0, (uint8_t) 2, INT32_C(1));
        if (t0) {
            t1 = vader_parser_peek_at(l0, INT32_C(1));
            t2 = ((vader_struct_vader_lexer_Token_t*) t1)->f_text;
            if (t2 == 1531u) {
                t3 = vader_parser_parse_assert_decl(l0);
                { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
    }
    l1 = vader_parser_parse_decorators(l0);
    vader_parser_reject_assert_decorator(l0, l1);
    vader_parser_check_guard_arity(l0, l1);
    vader_parser_check_c_struct_arguments(l0, l1);
    l2 = (uint8_t) 1;
    t3 = vader_parser_match_kind(l0, (uint8_t) 30);
    if (!(t3.tag == 0u)) {
        l2 = (uint8_t) 0;
    }
    l3 = vader_parser_parse_decorated_decl(l0, l1, l2);
    if (l3.tag == 0u) {
        { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l3.tag == 599u) {
        { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_parser_reject_displayable_decorator(l0, l1);
    { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_parser_parse_decorated_decl(void* l0, void* l1, uint8_t l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    vader_string_t l5 = 0;
    bool t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[5] = { &l0, &l1, &l3, &l4, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_parser_check(l0, (uint8_t) 28);
    if (t0) {
        t1 = vader_parser_parse_import_decl(l0, l1);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_parser_is_impl_decl(l0);
    if (t0) {
        t1 = vader_parser_parse_impl_decl(l0, l1);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_parser_check(l0, (uint8_t) 2);
    if (t0) {
        t0 = vader_parser_check_at(l0, (uint8_t) 52, INT32_C(1));
        if (t0) {
            t0 = vader_parser_peek_is_lhs_generic_alias_head(l0);
            if (t0) {
                t1 = vader_parser_parse_lhs_generic_alias_decl(l0, l1, l2);
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
    }
    t0 = vader_parser_check(l0, (uint8_t) 2);
    if (t0) {
        t0 = vader_parser_check_at(l0, (uint8_t) 71, INT32_C(1));
        if (t0) {
            t2 = vader_parser_parse_named_decl(l0, l1, l2);
            { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    t0 = vader_parser_check(l0, (uint8_t) 2);
    if (t0) {
        t0 = vader_parser_check_at(l0, (uint8_t) 88, INT32_C(1));
        if (t0) {
            t1 = vader_parser_parse_typed_const_decl(l0, l1, l2);
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l3 = vader_parser_peek(l0);
    l4 = ((vader_struct_vader_lexer_Token_t*) l3)->f_span;
    l5 = vader_parser_describe_token(l3);
    l5 = concat_2(1976u, l5);
    vader_parser_error(l0, (uint8_t) 4, l4, l5);
    vader_parser_sync_to_top_level(l0);
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static void* vader_parser_parse_decorator(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    bool l4;
    vader_box_t l5 = vader_box_null();
    vader_string_t l7 = 0;
    vader_box_t t0 = vader_box_null();
    bool t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[2] = { &l5, &t0 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l6, &t2 };
    vader_string_t* gc_atom_roots[1] = { &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_advance(l0);
    l2 = vader_parser_expect(l0, (uint8_t) 2, 1745u);
    vader_array_t* _a0_arr = vader_array_new(227u, 0u, 13u, 1503u);
    l3 = (void*) _a0_arr;
    t0 = vader_parser_match_kind(l0, (uint8_t) 80);
    if (!(t0.tag == 0u)) {
        t1 = vader_parser_check(l0, (uint8_t) 81);
        if (!(t1)) {
            l4 = true;
            for (;;) {
                if (!(l4)) {
                    t0 = vader_parser_match_kind(l0, (uint8_t) 86);
                    if (t0.tag == 0u) break;
                    t1 = vader_parser_check(l0, (uint8_t) 81);
                    if (t1) break;
                }
                l4 = false;
                l5 = vader_parser_parse_expr(l0, INT32_C(0));
                vader_array_push_ref((vader_array_t*) l3, l5.payload.obj);
                continue;
            }
        }
        vader_parser_expect(l0, (uint8_t) 81, 1232u);
    }
    l6 = vader_parser_peek_at(l0, INT32_C(-1));
    l1 = vader_parser_span_of(l0, l1, l6);
    l7 = ((vader_struct_vader_lexer_Token_t*) l2)->f_text;
    vader_struct_toolchain_ast_Decorator_t* _a1_obj = (vader_struct_toolchain_ast_Decorator_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_Decorator_t));
    vader_obj_header_init(_a1_obj, 590u);
    _a1_obj->f_span = l1;
    _a1_obj->f_id = INT64_C(0);
    _a1_obj->f_name = l7;
    _a1_obj->f_args = l3;
    t2 = (void*) _a1_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_decorators(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    bool t0;
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(40u, 0u, 13u, 590u);
    l1 = (void*) _a0_arr;
    for (;;) {
        t0 = vader_parser_check(l0, (uint8_t) 78);
        if (t0) {
            l2 = vader_parser_parse_decorator(l0);
            vader_array_push_ref((vader_array_t*) l1, l2);
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
    bool t1;
    vader_box_t* gc_roots[2] = { &l4, &l5 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_advance(l0);
    l2 = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
    vader_struct_toolchain_ast_NullLitExpr_t* _a0_obj = (vader_struct_toolchain_ast_NullLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_NullLitExpr_t));
    vader_obj_header_init(_a0_obj, 632u);
    _a0_obj->f_span = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
    _a0_obj->f_id = INT64_C(0);
    l3 = (void*) _a0_obj;
    vader_struct_toolchain_ast_ExprStmt_t* _a1_obj = (vader_struct_toolchain_ast_ExprStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ExprStmt_t));
    vader_obj_header_init(_a1_obj, 602u);
    _a1_obj->f_span = l2;
    _a1_obj->f_id = INT64_C(0);
    _a1_obj->f_expr = vader_ref_box(l3);
    t0 = (void*) _a1_obj;
    vader_struct_toolchain_ast_DeferStmtBody_t* _a2_obj = (vader_struct_toolchain_ast_DeferStmtBody_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_DeferStmtBody_t));
    vader_obj_header_init(_a2_obj, 593u);
    _a2_obj->f_stmt = vader_ref_box(t0);
    t0 = (void*) _a2_obj;
    l4 = vader_ref_box(t0);
    t1 = vader_parser_check(l0, (uint8_t) 84);
    if (t1) {
        t0 = vader_parser_parse_block(l0);
        vader_struct_toolchain_ast_DeferBlockBody_t* _a3_obj = (vader_struct_toolchain_ast_DeferBlockBody_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_DeferBlockBody_t));
        vader_obj_header_init(_a3_obj, 591u);
        _a3_obj->f_block = t0;
        t0 = (void*) _a3_obj;
        l4 = vader_ref_box(t0);
    } else {
        l5 = vader_parser_parse_stmt(l0);
        if (!(l5.tag == 0u)) {
            vader_struct_toolchain_ast_DeferStmtBody_t* _a4_obj = (vader_struct_toolchain_ast_DeferStmtBody_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_DeferStmtBody_t));
            vader_obj_header_init(_a4_obj, 593u);
            _a4_obj->f_stmt = l5;
            t0 = (void*) _a4_obj;
            l4 = vader_ref_box(t0);
        }
    }
    if (l4.tag == 593u) {
        t0 = l4.payload.obj;
        l2 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_AssignStmt_t, f_span, ((vader_struct_toolchain_ast_DeferStmtBody_t*) t0)->f_stmt.payload.obj);
    } else {
        if (!(l4.tag == 591u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = l4.payload.obj;
        l2 = ((vader_struct_toolchain_ast_BlockExpr_t*) ((vader_struct_toolchain_ast_DeferBlockBody_t*) t0)->f_block)->f_span;
    }
    l1 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l1)->f_span)->f_start;
    l2 = ((vader_struct_toolchain_span_Span_t*) l2)->f_end;
    vader_struct_toolchain_span_Span_t* _a5_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a5_obj, 667u);
    _a5_obj->f_start = l1;
    _a5_obj->f_end = l2;
    t0 = (void*) _a5_obj;
    vader_struct_toolchain_ast_DeferStmt_t* _a6_obj = (vader_struct_toolchain_ast_DeferStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_DeferStmt_t));
    vader_obj_header_init(_a6_obj, 592u);
    _a6_obj->f_span = t0;
    _a6_obj->f_id = INT64_C(0);
    _a6_obj->f_body = l4;
    t0 = (void*) _a6_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_destructure_assign(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l4 = NULL;
    vader_box_t l3 = vader_box_null();
    int64_t l5, l6, l7;
    bool t0;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    void* t3 = NULL;
    void* t4 = NULL;
    vader_box_t* gc_roots[2] = { &l3, &t1 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l4, &t3, &t4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_advance(l0);
    vader_array_t* _a0_arr = vader_array_new(232u, 0u, 13u, 1577u);
    l2 = (void*) _a0_arr;
    for (;;) {
        vader_parser_skip_newlines(l0);
        t0 = vader_parser_check(l0, (uint8_t) 83);
        if (!(t0)) {
            l3 = vader_parser_parse_assign_target(l0);
            vader_array_push_ref((vader_array_t*) l2, l3.payload.obj);
            vader_parser_skip_newlines(l0);
            t1 = vader_parser_match_kind(l0, (uint8_t) 86);
            if (t1.tag == 0u) break;
            continue;
        }
        break;
    }
    l4 = vader_parser_expect(l0, (uint8_t) 83, 1324u);
    t2 = ((vader_array_t*) l2)->length;
    if (t2 == INT64_C(0)) {
        l4 = vader_parser_span_of(l0, l1, l4);
        vader_parser_error(l0, (uint8_t) 14, l4, 1466u);
    }
    l5 = INT64_C(1);
    l6 = ((vader_array_t*) l2)->length;
    while ((l5 < l6)) {
        l7 = vader_chk_sub(i64, l5, INT64_C(1));
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l3 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l7);
        if (l3.tag == 641u) {
            t3 = l3.payload.obj;
            l4 = ((vader_struct_toolchain_ast_RestTarget_t*) t3)->f_span;
            vader_parser_error(l0, (uint8_t) 23, l4, 0u);
        }
        l5 = (l5 + INT64_C(1));
    }
    t3 = vader_parser_peek(l0);
    t4 = vader_parser_compound_op(((vader_struct_vader_lexer_Token_t*) t3)->f_kind);
    t0 = ((vader_struct_vader_parser_CompoundOpResult_t*) t4)->f_matched;
    if (t0) {
        l4 = vader_parser_advance(l0);
        l4 = vader_parser_span_of(l0, l1, l4);
        vader_parser_error(l0, (uint8_t) 20, l4, 1396u);
    } else {
        vader_parser_expect(l0, (uint8_t) 62, 1272u);
    }
    l3 = vader_parser_parse_expr(l0, INT32_C(0));
    l4 = vader_parser_peek_at(l0, INT32_C(-1));
    t3 = vader_parser_span_of(l0, l1, l4);
    vader_struct_toolchain_ast_DestructureAssignStmt_t* _a2_obj = (vader_struct_toolchain_ast_DestructureAssignStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_DestructureAssignStmt_t));
    vader_obj_header_init(_a2_obj, 594u);
    _a2_obj->f_span = t3;
    _a2_obj->f_id = INT64_C(0);
    _a2_obj->f_targets = l2;
    _a2_obj->f_value = l3;
    t3 = (void*) _a2_obj;
    { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_enum_decl(void* l0, void* l1, uint8_t l2, void* l3) {
    void* l4 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    void* l12 = NULL;
    void* l14 = NULL;
    void* l18 = NULL;
    void* l19 = NULL;
    void* l21 = NULL;
    vader_box_t l5 = vader_box_null(), l9 = vader_box_null(), l10 = vader_box_null(), l11 = vader_box_null(), l13 = vader_box_null(), l17 = vader_box_null();
    int64_t l7;
    uint64_t l15;
    bool l16;
    vader_string_t l20 = 0;
    vader_box_t t0 = vader_box_null();
    bool t1;
    void* t2 = NULL;
    void* t3 = NULL;
    int64_t t4;
    vader_box_t* gc_roots[7] = { &l5, &l9, &l10, &l11, &l13, &l17, &t0 };
    void** gc_raw_roots[13] = {
        &l0, &l1, &l3, &l4, &l6, &l8, &l12, &l14, &l18, &l19, &l21, &t2, &t3,
    };
    vader_string_t* gc_atom_roots[1] = { &l20 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 7u, 13u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_parser_reject_free_fn_decorators(l0, l1, 1468u, 0u);
    vader_parser_reject_c_decorators(l0, l1, 1468u);
    vader_parser_advance(l0);
    vader_array_t* _a0_arr = vader_array_new(227u, 0u, 13u, 1503u);
    l4 = (void*) _a0_arr;
    t0 = vader_parser_match_kind(l0, (uint8_t) 80);
    if (!(t0.tag == 0u)) {
        l5 = vader_parser_parse_type(l0);
        vader_array_push_ref((vader_array_t*) l4, l5.payload.obj);
        t0 = vader_parser_match_kind(l0, (uint8_t) 86);
        if (!(t0.tag == 0u)) {
            l5 = vader_parser_parse_type(l0);
            vader_array_push_ref((vader_array_t*) l4, l5.payload.obj);
        }
        vader_parser_expect(l0, (uint8_t) 81, 1233u);
    }
    vader_parser_expect(l0, (uint8_t) 84, 1352u);
    vader_parser_skip_newlines(l0);
    vader_array_t* _a1_arr = vader_array_new(41u, 0u, 13u, 600u);
    l6 = (void*) _a1_arr;
    for (;;) {
        t1 = vader_parser_check(l0, (uint8_t) 85);
        if (!(t1)) {
            t1 = vader_parser_check(l0, (uint8_t) 0);
            if (t1) break;
            l7 = ((vader_array_t*) ((vader_struct_vader_parser_Parser_t*) l0)->f_errors)->length;
            l8 = vader_parser_expect(l0, (uint8_t) 2, 2894u);
            l5 = vader_box_obj(0u, NULL);
            t0 = vader_parser_match_kind(l0, (uint8_t) 84);
            if (!(t0.tag == 0u)) {
                t2 = vader_parser_parse_struct_lit_fields(l0);
                t3 = ((vader_struct_vader_parser_CommaList__toolchain_ast_StructLitField___toolchain_ast_StructLitSpread_t*) t2)->f_items;
                l5 = vader_ref_box(t3);
                vader_parser_expect(l0, (uint8_t) 85, 1366u);
            }
            l9 = vader_box_obj(0u, NULL);
            l10 = vader_box_obj(0u, NULL);
            t0 = vader_parser_match_kind(l0, (uint8_t) 62);
            if (!(t0.tag == 0u)) {
                l11 = vader_parser_match_kind(l0, (uint8_t) 37);
                l12 = vader_parser_expect(l0, (uint8_t) 3, 2089u);
                l13 = ((vader_struct_vader_lexer_Token_t*) l12)->f_value;
                if (l13.tag == 325u) {
                    l14 = ((vader_struct_vader_lexer_Token_t*) l12)->f_span;
                    l15 = ((uint64_t) l13.payload.i);
                    l16 = !(l11.tag == 0u);
                    vader_struct_toolchain_ast_IntLitExpr_t* _a2_obj = (vader_struct_toolchain_ast_IntLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_IntLitExpr_t));
                    vader_obj_header_init(_a2_obj, 620u);
                    _a2_obj->f_span = l14;
                    _a2_obj->f_id = INT64_C(0);
                    _a2_obj->f_value = l15;
                    _a2_obj->f_negative = l16;
                    t2 = (void*) _a2_obj;
                    t4 = toolchain_ast_int_literal_value(t2);
                    l9 = vader_box_i64(321u, t4);
                }
                l17 = l11;
                if (l17.tag == 0u) {
                    l18 = l12;
                } else {
                    l18 = l17.payload.obj;
                }
                t2 = vader_parser_span_of(l0, l18, l12);
                l10 = vader_ref_box(t2);
            }
            l19 = ((vader_struct_vader_lexer_Token_t*) l8)->f_span;
            l20 = ((vader_struct_vader_lexer_Token_t*) l8)->f_text;
            vader_struct_toolchain_ast_EnumVariant_t* _a3_obj = (vader_struct_toolchain_ast_EnumVariant_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_EnumVariant_t));
            vader_obj_header_init(_a3_obj, 600u);
            _a3_obj->f_span = l19;
            _a3_obj->f_id = INT64_C(0);
            _a3_obj->f_name = l20;
            _a3_obj->f_value = l9;
            _a3_obj->f_value_span = l10;
            _a3_obj->f_data = l5;
            l21 = (void*) _a3_obj;
            vader_array_push_ref((vader_array_t*) l6, l21);
            t4 = ((vader_array_t*) ((vader_struct_vader_parser_Parser_t*) l0)->f_errors)->length;
            if ((t4 > l7)) {
                for (;;) {
                    t1 = vader_parser_check(l0, (uint8_t) 86);
                    if (!(t1)) {
                        t1 = vader_parser_check(l0, (uint8_t) 1);
                        if (t1) break;
                        t1 = vader_parser_check(l0, (uint8_t) 85);
                        if (t1) break;
                        t1 = vader_parser_check(l0, (uint8_t) 0);
                        if (t1) break;
                        vader_parser_advance(l0);
                        continue;
                    }
                    break;
                }
            }
            vader_parser_match_kind(l0, (uint8_t) 86);
            vader_parser_skip_newlines(l0);
            continue;
        }
        break;
    }
    l8 = vader_parser_expect(l0, (uint8_t) 85, 1358u);
    l8 = vader_parser_span_of(l0, l3, l8);
    l20 = ((vader_struct_vader_lexer_Token_t*) l3)->f_text;
    l12 = ((vader_struct_vader_lexer_Token_t*) l3)->f_span;
    vader_struct_toolchain_ast_EnumDecl_t* _a4_obj = (vader_struct_toolchain_ast_EnumDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_EnumDecl_t));
    vader_obj_header_init(_a4_obj, 599u);
    _a4_obj->f_span = l8;
    _a4_obj->f_id = INT64_C(0);
    _a4_obj->f_name = l20;
    _a4_obj->f_name_span = l12;
    _a4_obj->f_visibility = l2;
    _a4_obj->f_header = l4;
    _a4_obj->f_variants = l6;
    _a4_obj->f_decorators = l1;
    t2 = (void*) _a4_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_parser_parse_expr(void* l0, int32_t l1) {
    int32_t l2, l5, l38, l42, l58;
    void* l3 = NULL;
    void* l10 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l16 = NULL;
    void* l18 = NULL;
    void* l19 = NULL;
    void* l21 = NULL;
    void* l22 = NULL;
    void* l23 = NULL;
    void* l24 = NULL;
    void* l26 = NULL;
    void* l27 = NULL;
    void* l28 = NULL;
    void* l29 = NULL;
    void* l31 = NULL;
    void* l32 = NULL;
    void* l33 = NULL;
    void* l35 = NULL;
    void* l36 = NULL;
    void* l39 = NULL;
    void* l45 = NULL;
    void* l46 = NULL;
    void* l47 = NULL;
    void* l50 = NULL;
    void* l51 = NULL;
    void* l52 = NULL;
    void* l53 = NULL;
    void* l54 = NULL;
    void* l57 = NULL;
    vader_box_t l4 = vader_box_null(), l7 = vader_box_null(), l8 = vader_box_null(), l11 = vader_box_null(), l15 = vader_box_null(), l20 = vader_box_null(), l25 = vader_box_null(), l30 = vader_box_null(), l34 = vader_box_null(), l43 = vader_box_null(), l49 = vader_box_null(), l56 = vader_box_null();
    bool l6, l9, l17, l37, l44, l48;
    vader_string_t l40 = 0;
    vader_string_t l41 = 0;
    uint8_t l55;
    int32_t t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    bool t3;
    vader_box_t* gc_roots[13] = {
        &l4, &l7, &l8, &l11, &l15, &l20, &l25, &l30, &l34, &l43, &l49, &l56, &t2,
    };
    void** gc_raw_roots[33] = {
        &l0, &l3, &l10, &l12, &l13, &l14, &l16, &l18, &l19, &l21, &l22, &l23, &l24, &l26, &l27,
        &l28, &l29, &l31, &l32, &l33, &l35, &l36, &l39, &l45, &l46, &l47, &l50, &l51, &l52, &l53,
        &l54, &l57, &t1,
    };
    vader_string_t* gc_atom_roots[2] = { &l40, &l41 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 13u, 33u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth;
    l2 = vader_chk_add(i32, t0, INT32_C(1));
    ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth = l2;
    t0 = ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth;
    if ((t0 > INT32_C(256))) {
        t0 = ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth;
        l2 = vader_chk_sub(i32, t0, INT32_C(1));
        ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth = l2;
        t1 = vader_parser_peek(l0);
        l3 = ((vader_struct_vader_lexer_Token_t*) t1)->f_span;
        vader_parser_report_nesting_too_deep(l0, 1857u);
        vader_struct_toolchain_ast_NullLitExpr_t* _a0_obj = (vader_struct_toolchain_ast_NullLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_NullLitExpr_t));
        vader_obj_header_init(_a0_obj, 632u);
        _a0_obj->f_span = l3;
        _a0_obj->f_id = INT64_C(0);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_parser_parse_prefix(l0);
    vader_struct__Cell_Union_Struct_toolchain_ast_ArrayTypeExpr___Struct_toolchain_ast_AwaitExpr___Struct_toolchain_ast_BinaryExpr___Struct_toolchain_ast_BlockExpr___Struct_toolchain_ast_BoolLitExpr___Struct_toolchain_ast_CallExpr___Struct_toolchain_ast_CastExpr___Struct_toolchain_ast_CharLitExpr___Struct_toolchain_ast_DotVariantExpr___Struct_toolchain_ast_FieldExpr___Struct_toolchain_ast_FloatLitExpr___Struct_toolchain_ast_FnTypeExpr___Struct_toolchain_ast_GenericInstExpr___Struct_toolchain_ast_IdentExpr___Struct_toolchain_ast_IfExpr___Struct_toolchain_ast_IndexExpr___Struct_toolchain_ast_IntLitExpr___Struct_toolchain_ast_IntrinsicCallExpr___Struct_toolchain_ast_LambdaExpr___Struct_toolchain_ast_MatchExpr___Struct_toolchain_ast_NullCoalesceExpr___Struct_toolchain_ast_NullLitExpr___Struct_toolchain_ast_RangeExpr___Struct_toolchain_ast_SeqLitExpr___Struct_toolchain_ast_StringLitExpr___Struct_toolchain_ast_StructLitExpr___Struct_toolchain_ast_UnaryExpr____t* _a1_obj = (vader_struct__Cell_Union_Struct_toolchain_ast_ArrayTypeExpr___Struct_toolchain_ast_AwaitExpr___Struct_toolchain_ast_BinaryExpr___Struct_toolchain_ast_BlockExpr___Struct_toolchain_ast_BoolLitExpr___Struct_toolchain_ast_CallExpr___Struct_toolchain_ast_CastExpr___Struct_toolchain_ast_CharLitExpr___Struct_toolchain_ast_DotVariantExpr___Struct_toolchain_ast_FieldExpr___Struct_toolchain_ast_FloatLitExpr___Struct_toolchain_ast_FnTypeExpr___Struct_toolchain_ast_GenericInstExpr___Struct_toolchain_ast_IdentExpr___Struct_toolchain_ast_IfExpr___Struct_toolchain_ast_IndexExpr___Struct_toolchain_ast_IntLitExpr___Struct_toolchain_ast_IntrinsicCallExpr___Struct_toolchain_ast_LambdaExpr___Struct_toolchain_ast_MatchExpr___Struct_toolchain_ast_NullCoalesceExpr___Struct_toolchain_ast_NullLitExpr___Struct_toolchain_ast_RangeExpr___Struct_toolchain_ast_SeqLitExpr___Struct_toolchain_ast_StringLitExpr___Struct_toolchain_ast_StructLitExpr___Struct_toolchain_ast_UnaryExpr____t*) vader_gc_alloc(sizeof(vader_struct__Cell_Union_Struct_toolchain_ast_ArrayTypeExpr___Struct_toolchain_ast_AwaitExpr___Struct_toolchain_ast_BinaryExpr___Struct_toolchain_ast_BlockExpr___Struct_toolchain_ast_BoolLitExpr___Struct_toolchain_ast_CallExpr___Struct_toolchain_ast_CastExpr___Struct_toolchain_ast_CharLitExpr___Struct_toolchain_ast_DotVariantExpr___Struct_toolchain_ast_FieldExpr___Struct_toolchain_ast_FloatLitExpr___Struct_toolchain_ast_FnTypeExpr___Struct_toolchain_ast_GenericInstExpr___Struct_toolchain_ast_IdentExpr___Struct_toolchain_ast_IfExpr___Struct_toolchain_ast_IndexExpr___Struct_toolchain_ast_IntLitExpr___Struct_toolchain_ast_IntrinsicCallExpr___Struct_toolchain_ast_LambdaExpr___Struct_toolchain_ast_MatchExpr___Struct_toolchain_ast_NullCoalesceExpr___Struct_toolchain_ast_NullLitExpr___Struct_toolchain_ast_RangeExpr___Struct_toolchain_ast_SeqLitExpr___Struct_toolchain_ast_StringLitExpr___Struct_toolchain_ast_StructLitExpr___Struct_toolchain_ast_UnaryExpr____t));
    vader_obj_header_init(_a1_obj, 329u);
    _a1_obj->f_value = t2;
    t1 = (void*) _a1_obj;
    l4 = vader_ref_box(t1);
    if (((vader_struct__Cell_Union_Struct_toolchain_ast_ArrayTypeExpr___Struct_toolchain_ast_AwaitExpr___Struct_toolchain_ast_BinaryExpr___Struct_toolchain_ast_BlockExpr___Struct_toolchain_ast_BoolLitExpr___Struct_toolchain_ast_CallExpr___Struct_toolchain_ast_CastExpr___Struct_toolchain_ast_CharLitExpr___Struct_toolchain_ast_DotVariantExpr___Struct_toolchain_ast_FieldExpr___Struct_toolchain_ast_FloatLitExpr___Struct_toolchain_ast_FnTypeExpr___Struct_toolchain_ast_GenericInstExpr___Struct_toolchain_ast_IdentExpr___Struct_toolchain_ast_IfExpr___Struct_toolchain_ast_IndexExpr___Struct_toolchain_ast_IntLitExpr___Struct_toolchain_ast_IntrinsicCallExpr___Struct_toolchain_ast_LambdaExpr___Struct_toolchain_ast_MatchExpr___Struct_toolchain_ast_NullCoalesceExpr___Struct_toolchain_ast_NullLitExpr___Struct_toolchain_ast_RangeExpr___Struct_toolchain_ast_SeqLitExpr___Struct_toolchain_ast_StringLitExpr___Struct_toolchain_ast_StructLitExpr___Struct_toolchain_ast_UnaryExpr____t*) l4.payload.obj)->f_value.tag == 610u) {
        t3 = vader_parser_allows_bare_lambda(l0);
        if (t3) {
            t3 = vader_parser_check(l0, (uint8_t) 76);
            if (t3) {
                l3 = ((vader_struct__Cell_Union_Struct_toolchain_ast_ArrayTypeExpr___Struct_toolchain_ast_AwaitExpr___Struct_toolchain_ast_BinaryExpr___Struct_toolchain_ast_BlockExpr___Struct_toolchain_ast_BoolLitExpr___Struct_toolchain_ast_CallExpr___Struct_toolchain_ast_CastExpr___Struct_toolchain_ast_CharLitExpr___Struct_toolchain_ast_DotVariantExpr___Struct_toolchain_ast_FieldExpr___Struct_toolchain_ast_FloatLitExpr___Struct_toolchain_ast_FnTypeExpr___Struct_toolchain_ast_GenericInstExpr___Struct_toolchain_ast_IdentExpr___Struct_toolchain_ast_IfExpr___Struct_toolchain_ast_IndexExpr___Struct_toolchain_ast_IntLitExpr___Struct_toolchain_ast_IntrinsicCallExpr___Struct_toolchain_ast_LambdaExpr___Struct_toolchain_ast_MatchExpr___Struct_toolchain_ast_NullCoalesceExpr___Struct_toolchain_ast_NullLitExpr___Struct_toolchain_ast_RangeExpr___Struct_toolchain_ast_SeqLitExpr___Struct_toolchain_ast_StringLitExpr___Struct_toolchain_ast_StructLitExpr___Struct_toolchain_ast_UnaryExpr____t*) l4.payload.obj)->f_value.payload.obj;
                l3 = vader_parser_parse_single_param_lambda_tail(l0, l3);
                ((vader_struct__Cell_Union_Struct_toolchain_ast_ArrayTypeExpr___Struct_toolchain_ast_AwaitExpr___Struct_toolchain_ast_BinaryExpr___Struct_toolchain_ast_BlockExpr___Struct_toolchain_ast_BoolLitExpr___Struct_toolchain_ast_CallExpr___Struct_toolchain_ast_CastExpr___Struct_toolchain_ast_CharLitExpr___Struct_toolchain_ast_DotVariantExpr___Struct_toolchain_ast_FieldExpr___Struct_toolchain_ast_FloatLitExpr___Struct_toolchain_ast_FnTypeExpr___Struct_toolchain_ast_GenericInstExpr___Struct_toolchain_ast_IdentExpr___Struct_toolchain_ast_IfExpr___Struct_toolchain_ast_IndexExpr___Struct_toolchain_ast_IntLitExpr___Struct_toolchain_ast_IntrinsicCallExpr___Struct_toolchain_ast_LambdaExpr___Struct_toolchain_ast_MatchExpr___Struct_toolchain_ast_NullCoalesceExpr___Struct_toolchain_ast_NullLitExpr___Struct_toolchain_ast_RangeExpr___Struct_toolchain_ast_SeqLitExpr___Struct_toolchain_ast_StringLitExpr___Struct_toolchain_ast_StructLitExpr___Struct_toolchain_ast_UnaryExpr____t*) l4.payload.obj)->f_value = vader_ref_box(l3);
                VADER_WRITE_BARRIER((vader_struct__Cell_Union_Struct_toolchain_ast_ArrayTypeExpr___Struct_toolchain_ast_AwaitExpr___Struct_toolchain_ast_BinaryExpr___Struct_toolchain_ast_BlockExpr___Struct_toolchain_ast_BoolLitExpr___Struct_toolchain_ast_CallExpr___Struct_toolchain_ast_CastExpr___Struct_toolchain_ast_CharLitExpr___Struct_toolchain_ast_DotVariantExpr___Struct_toolchain_ast_FieldExpr___Struct_toolchain_ast_FloatLitExpr___Struct_toolchain_ast_FnTypeExpr___Struct_toolchain_ast_GenericInstExpr___Struct_toolchain_ast_IdentExpr___Struct_toolchain_ast_IfExpr___Struct_toolchain_ast_IndexExpr___Struct_toolchain_ast_IntLitExpr___Struct_toolchain_ast_IntrinsicCallExpr___Struct_toolchain_ast_LambdaExpr___Struct_toolchain_ast_MatchExpr___Struct_toolchain_ast_NullCoalesceExpr___Struct_toolchain_ast_NullLitExpr___Struct_toolchain_ast_RangeExpr___Struct_toolchain_ast_SeqLitExpr___Struct_toolchain_ast_StringLitExpr___Struct_toolchain_ast_StructLitExpr___Struct_toolchain_ast_UnaryExpr____t*) l4.payload.obj);
            }
        }
    }
    l2 = INT32_C(-1);
    {
        {
            for (;;) {
                l3 = vader_parser_peek(l0);
                l5 = vader_parser_postfix_bp(((vader_struct_vader_lexer_Token_t*) l3)->f_kind);
                if ((l5 >= INT32_C(0))) {
                    if ((l5 >= l1)) {
                        if (((vader_struct_vader_lexer_Token_t*) l3)->f_kind == INT32_C(82)) {
                            l6 = true;
                        } else {
                            l6 = ((vader_struct_vader_lexer_Token_t*) l3)->f_kind == INT32_C(80);
                        }
                        if (l6) {
                            if (((vader_struct__Cell_Union_Struct_toolchain_ast_ArrayTypeExpr___Struct_toolchain_ast_AwaitExpr___Struct_toolchain_ast_BinaryExpr___Struct_toolchain_ast_BlockExpr___Struct_toolchain_ast_BoolLitExpr___Struct_toolchain_ast_CallExpr___Struct_toolchain_ast_CastExpr___Struct_toolchain_ast_CharLitExpr___Struct_toolchain_ast_DotVariantExpr___Struct_toolchain_ast_FieldExpr___Struct_toolchain_ast_FloatLitExpr___Struct_toolchain_ast_FnTypeExpr___Struct_toolchain_ast_GenericInstExpr___Struct_toolchain_ast_IdentExpr___Struct_toolchain_ast_IfExpr___Struct_toolchain_ast_IndexExpr___Struct_toolchain_ast_IntLitExpr___Struct_toolchain_ast_IntrinsicCallExpr___Struct_toolchain_ast_LambdaExpr___Struct_toolchain_ast_MatchExpr___Struct_toolchain_ast_NullCoalesceExpr___Struct_toolchain_ast_NullLitExpr___Struct_toolchain_ast_RangeExpr___Struct_toolchain_ast_SeqLitExpr___Struct_toolchain_ast_StringLitExpr___Struct_toolchain_ast_StructLitExpr___Struct_toolchain_ast_UnaryExpr____t*) l4.payload.obj)->f_value.tag == 613u) goto end_63;
                            if (((vader_struct__Cell_Union_Struct_toolchain_ast_ArrayTypeExpr___Struct_toolchain_ast_AwaitExpr___Struct_toolchain_ast_BinaryExpr___Struct_toolchain_ast_BlockExpr___Struct_toolchain_ast_BoolLitExpr___Struct_toolchain_ast_CallExpr___Struct_toolchain_ast_CastExpr___Struct_toolchain_ast_CharLitExpr___Struct_toolchain_ast_DotVariantExpr___Struct_toolchain_ast_FieldExpr___Struct_toolchain_ast_FloatLitExpr___Struct_toolchain_ast_FnTypeExpr___Struct_toolchain_ast_GenericInstExpr___Struct_toolchain_ast_IdentExpr___Struct_toolchain_ast_IfExpr___Struct_toolchain_ast_IndexExpr___Struct_toolchain_ast_IntLitExpr___Struct_toolchain_ast_IntrinsicCallExpr___Struct_toolchain_ast_LambdaExpr___Struct_toolchain_ast_MatchExpr___Struct_toolchain_ast_NullCoalesceExpr___Struct_toolchain_ast_NullLitExpr___Struct_toolchain_ast_RangeExpr___Struct_toolchain_ast_SeqLitExpr___Struct_toolchain_ast_StringLitExpr___Struct_toolchain_ast_StructLitExpr___Struct_toolchain_ast_UnaryExpr____t*) l4.payload.obj)->f_value.tag == 627u) goto end_63;
                            if (((vader_struct__Cell_Union_Struct_toolchain_ast_ArrayTypeExpr___Struct_toolchain_ast_AwaitExpr___Struct_toolchain_ast_BinaryExpr___Struct_toolchain_ast_BlockExpr___Struct_toolchain_ast_BoolLitExpr___Struct_toolchain_ast_CallExpr___Struct_toolchain_ast_CastExpr___Struct_toolchain_ast_CharLitExpr___Struct_toolchain_ast_DotVariantExpr___Struct_toolchain_ast_FieldExpr___Struct_toolchain_ast_FloatLitExpr___Struct_toolchain_ast_FnTypeExpr___Struct_toolchain_ast_GenericInstExpr___Struct_toolchain_ast_IdentExpr___Struct_toolchain_ast_IfExpr___Struct_toolchain_ast_IndexExpr___Struct_toolchain_ast_IntLitExpr___Struct_toolchain_ast_IntrinsicCallExpr___Struct_toolchain_ast_LambdaExpr___Struct_toolchain_ast_MatchExpr___Struct_toolchain_ast_NullCoalesceExpr___Struct_toolchain_ast_NullLitExpr___Struct_toolchain_ast_RangeExpr___Struct_toolchain_ast_SeqLitExpr___Struct_toolchain_ast_StringLitExpr___Struct_toolchain_ast_StructLitExpr___Struct_toolchain_ast_UnaryExpr____t*) l4.payload.obj)->f_value.tag == 581u) goto end_63;
                        }
                        l7 = ((vader_struct__Cell_Union_Struct_toolchain_ast_ArrayTypeExpr___Struct_toolchain_ast_AwaitExpr___Struct_toolchain_ast_BinaryExpr___Struct_toolchain_ast_BlockExpr___Struct_toolchain_ast_BoolLitExpr___Struct_toolchain_ast_CallExpr___Struct_toolchain_ast_CastExpr___Struct_toolchain_ast_CharLitExpr___Struct_toolchain_ast_DotVariantExpr___Struct_toolchain_ast_FieldExpr___Struct_toolchain_ast_FloatLitExpr___Struct_toolchain_ast_FnTypeExpr___Struct_toolchain_ast_GenericInstExpr___Struct_toolchain_ast_IdentExpr___Struct_toolchain_ast_IfExpr___Struct_toolchain_ast_IndexExpr___Struct_toolchain_ast_IntLitExpr___Struct_toolchain_ast_IntrinsicCallExpr___Struct_toolchain_ast_LambdaExpr___Struct_toolchain_ast_MatchExpr___Struct_toolchain_ast_NullCoalesceExpr___Struct_toolchain_ast_NullLitExpr___Struct_toolchain_ast_RangeExpr___Struct_toolchain_ast_SeqLitExpr___Struct_toolchain_ast_StringLitExpr___Struct_toolchain_ast_StructLitExpr___Struct_toolchain_ast_UnaryExpr____t*) l4.payload.obj)->f_value;
                        l8 = vader_parser_parse_postfix(l0, l7, l3);
                        ((vader_struct__Cell_Union_Struct_toolchain_ast_ArrayTypeExpr___Struct_toolchain_ast_AwaitExpr___Struct_toolchain_ast_BinaryExpr___Struct_toolchain_ast_BlockExpr___Struct_toolchain_ast_BoolLitExpr___Struct_toolchain_ast_CallExpr___Struct_toolchain_ast_CastExpr___Struct_toolchain_ast_CharLitExpr___Struct_toolchain_ast_DotVariantExpr___Struct_toolchain_ast_FieldExpr___Struct_toolchain_ast_FloatLitExpr___Struct_toolchain_ast_FnTypeExpr___Struct_toolchain_ast_GenericInstExpr___Struct_toolchain_ast_IdentExpr___Struct_toolchain_ast_IfExpr___Struct_toolchain_ast_IndexExpr___Struct_toolchain_ast_IntLitExpr___Struct_toolchain_ast_IntrinsicCallExpr___Struct_toolchain_ast_LambdaExpr___Struct_toolchain_ast_MatchExpr___Struct_toolchain_ast_NullCoalesceExpr___Struct_toolchain_ast_NullLitExpr___Struct_toolchain_ast_RangeExpr___Struct_toolchain_ast_SeqLitExpr___Struct_toolchain_ast_StringLitExpr___Struct_toolchain_ast_StructLitExpr___Struct_toolchain_ast_UnaryExpr____t*) l4.payload.obj)->f_value = l8;
                        VADER_WRITE_BARRIER((vader_struct__Cell_Union_Struct_toolchain_ast_ArrayTypeExpr___Struct_toolchain_ast_AwaitExpr___Struct_toolchain_ast_BinaryExpr___Struct_toolchain_ast_BlockExpr___Struct_toolchain_ast_BoolLitExpr___Struct_toolchain_ast_CallExpr___Struct_toolchain_ast_CastExpr___Struct_toolchain_ast_CharLitExpr___Struct_toolchain_ast_DotVariantExpr___Struct_toolchain_ast_FieldExpr___Struct_toolchain_ast_FloatLitExpr___Struct_toolchain_ast_FnTypeExpr___Struct_toolchain_ast_GenericInstExpr___Struct_toolchain_ast_IdentExpr___Struct_toolchain_ast_IfExpr___Struct_toolchain_ast_IndexExpr___Struct_toolchain_ast_IntLitExpr___Struct_toolchain_ast_IntrinsicCallExpr___Struct_toolchain_ast_LambdaExpr___Struct_toolchain_ast_MatchExpr___Struct_toolchain_ast_NullCoalesceExpr___Struct_toolchain_ast_NullLitExpr___Struct_toolchain_ast_RangeExpr___Struct_toolchain_ast_SeqLitExpr___Struct_toolchain_ast_StringLitExpr___Struct_toolchain_ast_StructLitExpr___Struct_toolchain_ast_UnaryExpr____t*) l4.payload.obj);
                        l2 = INT32_C(-1);
                        continue;
                    }
                }
                if (((vader_struct_vader_lexer_Token_t*) l3)->f_kind == INT32_C(60)) {
                    t1 = vader_parser_peek_at(l0, INT32_C(1));
                    if (((vader_struct_vader_lexer_Token_t*) t1)->f_kind == INT32_C(21)) {
                        if ((INT32_C(20) >= l1)) {
                            l9 = l2 == INT32_C(20);
                            if (l9) {
                                l10 = ((vader_struct_vader_lexer_Token_t*) l3)->f_span;
                                vader_parser_error(l0, (uint8_t) 6, l10, 1675u);
                            }
                            vader_parser_advance(l0);
                            vader_parser_advance(l0);
                            l11 = vader_parser_parse_expr(l0, INT32_C(21));
                            if (l9) {
                                continue;
                            }
                            l12 = ((vader_struct_toolchain_span_Span_t*) VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, ((vader_struct__Cell_Union_Struct_toolchain_ast_ArrayTypeExpr___Struct_toolchain_ast_AwaitExpr___Struct_toolchain_ast_BinaryExpr___Struct_toolchain_ast_BlockExpr___Struct_toolchain_ast_BoolLitExpr___Struct_toolchain_ast_CallExpr___Struct_toolchain_ast_CastExpr___Struct_toolchain_ast_CharLitExpr___Struct_toolchain_ast_DotVariantExpr___Struct_toolchain_ast_FieldExpr___Struct_toolchain_ast_FloatLitExpr___Struct_toolchain_ast_FnTypeExpr___Struct_toolchain_ast_GenericInstExpr___Struct_toolchain_ast_IdentExpr___Struct_toolchain_ast_IfExpr___Struct_toolchain_ast_IndexExpr___Struct_toolchain_ast_IntLitExpr___Struct_toolchain_ast_IntrinsicCallExpr___Struct_toolchain_ast_LambdaExpr___Struct_toolchain_ast_MatchExpr___Struct_toolchain_ast_NullCoalesceExpr___Struct_toolchain_ast_NullLitExpr___Struct_toolchain_ast_RangeExpr___Struct_toolchain_ast_SeqLitExpr___Struct_toolchain_ast_StringLitExpr___Struct_toolchain_ast_StructLitExpr___Struct_toolchain_ast_UnaryExpr____t*) l4.payload.obj)->f_value.payload.obj))->f_start;
                            l13 = ((vader_struct_toolchain_span_Span_t*) VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, l11.payload.obj))->f_end;
                            vader_struct_toolchain_span_Span_t* _a2_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
                            vader_obj_header_init(_a2_obj, 667u);
                            _a2_obj->f_start = l12;
                            _a2_obj->f_end = l13;
                            l14 = (void*) _a2_obj;
                            l15 = ((vader_struct__Cell_Union_Struct_toolchain_ast_ArrayTypeExpr___Struct_toolchain_ast_AwaitExpr___Struct_toolchain_ast_BinaryExpr___Struct_toolchain_ast_BlockExpr___Struct_toolchain_ast_BoolLitExpr___Struct_toolchain_ast_CallExpr___Struct_toolchain_ast_CastExpr___Struct_toolchain_ast_CharLitExpr___Struct_toolchain_ast_DotVariantExpr___Struct_toolchain_ast_FieldExpr___Struct_toolchain_ast_FloatLitExpr___Struct_toolchain_ast_FnTypeExpr___Struct_toolchain_ast_GenericInstExpr___Struct_toolchain_ast_IdentExpr___Struct_toolchain_ast_IfExpr___Struct_toolchain_ast_IndexExpr___Struct_toolchain_ast_IntLitExpr___Struct_toolchain_ast_IntrinsicCallExpr___Struct_toolchain_ast_LambdaExpr___Struct_toolchain_ast_MatchExpr___Struct_toolchain_ast_NullCoalesceExpr___Struct_toolchain_ast_NullLitExpr___Struct_toolchain_ast_RangeExpr___Struct_toolchain_ast_SeqLitExpr___Struct_toolchain_ast_StringLitExpr___Struct_toolchain_ast_StructLitExpr___Struct_toolchain_ast_UnaryExpr____t*) l4.payload.obj)->f_value;
                            vader_struct_toolchain_ast_BinaryExpr_t* _a3_obj = (vader_struct_toolchain_ast_BinaryExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BinaryExpr_t));
                            vader_obj_header_init(_a3_obj, 580u);
                            _a3_obj->f_span = l14;
                            _a3_obj->f_id = INT64_C(0);
                            _a3_obj->f_op = (uint8_t) 20;
                            _a3_obj->f_left = l15;
                            _a3_obj->f_right = l11;
                            l16 = (void*) _a3_obj;
                            ((vader_struct__Cell_Union_Struct_toolchain_ast_ArrayTypeExpr___Struct_toolchain_ast_AwaitExpr___Struct_toolchain_ast_BinaryExpr___Struct_toolchain_ast_BlockExpr___Struct_toolchain_ast_BoolLitExpr___Struct_toolchain_ast_CallExpr___Struct_toolchain_ast_CastExpr___Struct_toolchain_ast_CharLitExpr___Struct_toolchain_ast_DotVariantExpr___Struct_toolchain_ast_FieldExpr___Struct_toolchain_ast_FloatLitExpr___Struct_toolchain_ast_FnTypeExpr___Struct_toolchain_ast_GenericInstExpr___Struct_toolchain_ast_IdentExpr___Struct_toolchain_ast_IfExpr___Struct_toolchain_ast_IndexExpr___Struct_toolchain_ast_IntLitExpr___Struct_toolchain_ast_IntrinsicCallExpr___Struct_toolchain_ast_LambdaExpr___Struct_toolchain_ast_MatchExpr___Struct_toolchain_ast_NullCoalesceExpr___Struct_toolchain_ast_NullLitExpr___Struct_toolchain_ast_RangeExpr___Struct_toolchain_ast_SeqLitExpr___Struct_toolchain_ast_StringLitExpr___Struct_toolchain_ast_StructLitExpr___Struct_toolchain_ast_UnaryExpr____t*) l4.payload.obj)->f_value = vader_ref_box(l16);
                            VADER_WRITE_BARRIER((vader_struct__Cell_Union_Struct_toolchain_ast_ArrayTypeExpr___Struct_toolchain_ast_AwaitExpr___Struct_toolchain_ast_BinaryExpr___Struct_toolchain_ast_BlockExpr___Struct_toolchain_ast_BoolLitExpr___Struct_toolchain_ast_CallExpr___Struct_toolchain_ast_CastExpr___Struct_toolchain_ast_CharLitExpr___Struct_toolchain_ast_DotVariantExpr___Struct_toolchain_ast_FieldExpr___Struct_toolchain_ast_FloatLitExpr___Struct_toolchain_ast_FnTypeExpr___Struct_toolchain_ast_GenericInstExpr___Struct_toolchain_ast_IdentExpr___Struct_toolchain_ast_IfExpr___Struct_toolchain_ast_IndexExpr___Struct_toolchain_ast_IntLitExpr___Struct_toolchain_ast_IntrinsicCallExpr___Struct_toolchain_ast_LambdaExpr___Struct_toolchain_ast_MatchExpr___Struct_toolchain_ast_NullCoalesceExpr___Struct_toolchain_ast_NullLitExpr___Struct_toolchain_ast_RangeExpr___Struct_toolchain_ast_SeqLitExpr___Struct_toolchain_ast_StringLitExpr___Struct_toolchain_ast_StructLitExpr___Struct_toolchain_ast_UnaryExpr____t*) l4.payload.obj);
                            l2 = INT32_C(20);
                            continue;
                        }
                    }
                }
                if (((vader_struct_vader_lexer_Token_t*) l3)->f_kind == INT32_C(60)) {
                    t1 = vader_parser_peek_at(l0, INT32_C(1));
                    if (((vader_struct_vader_lexer_Token_t*) t1)->f_kind == INT32_C(19)) {
                        if ((INT32_C(20) >= l1)) {
                            l17 = l2 == INT32_C(20);
                            if (l17) {
                                l18 = ((vader_struct_vader_lexer_Token_t*) l3)->f_span;
                                vader_parser_error(l0, (uint8_t) 6, l18, 1676u);
                            }
                            l19 = vader_parser_advance(l0);
                            vader_parser_advance(l0);
                            l20 = vader_parser_parse_type(l0);
                            if (l17) {
                                continue;
                            }
                            vader_struct___lambda_env_vader_parser_1_t* _a4_obj = (vader_struct___lambda_env_vader_parser_1_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_parser_1_t));
                            vader_obj_header_init(_a4_obj, 382u);
                            _a4_obj->f_cap_0 = l4;
                            t1 = (void*) _a4_obj;
                            vader_fn_t* _a5_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
                            vader_obj_header_init(_a5_closure, 288u);
                            _a5_closure->code = (void*) &vader_fn_lift___lambda_vader_parser_0;
                            _a5_closure->env = t1;
                            l21 = (void*) _a5_closure;
                            vader_parser_reject_as_binder(l0, (uint8_t) 21, l21);
                            l22 = ((vader_struct_toolchain_span_Span_t*) VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, ((vader_struct__Cell_Union_Struct_toolchain_ast_ArrayTypeExpr___Struct_toolchain_ast_AwaitExpr___Struct_toolchain_ast_BinaryExpr___Struct_toolchain_ast_BlockExpr___Struct_toolchain_ast_BoolLitExpr___Struct_toolchain_ast_CallExpr___Struct_toolchain_ast_CastExpr___Struct_toolchain_ast_CharLitExpr___Struct_toolchain_ast_DotVariantExpr___Struct_toolchain_ast_FieldExpr___Struct_toolchain_ast_FloatLitExpr___Struct_toolchain_ast_FnTypeExpr___Struct_toolchain_ast_GenericInstExpr___Struct_toolchain_ast_IdentExpr___Struct_toolchain_ast_IfExpr___Struct_toolchain_ast_IndexExpr___Struct_toolchain_ast_IntLitExpr___Struct_toolchain_ast_IntrinsicCallExpr___Struct_toolchain_ast_LambdaExpr___Struct_toolchain_ast_MatchExpr___Struct_toolchain_ast_NullCoalesceExpr___Struct_toolchain_ast_NullLitExpr___Struct_toolchain_ast_RangeExpr___Struct_toolchain_ast_SeqLitExpr___Struct_toolchain_ast_StringLitExpr___Struct_toolchain_ast_StructLitExpr___Struct_toolchain_ast_UnaryExpr____t*) l4.payload.obj)->f_value.payload.obj))->f_start;
                            l23 = ((vader_struct_toolchain_span_Span_t*) VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, l20.payload.obj))->f_end;
                            vader_struct_toolchain_span_Span_t* _a6_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
                            vader_obj_header_init(_a6_obj, 667u);
                            _a6_obj->f_start = l22;
                            _a6_obj->f_end = l23;
                            l24 = (void*) _a6_obj;
                            l25 = ((vader_struct__Cell_Union_Struct_toolchain_ast_ArrayTypeExpr___Struct_toolchain_ast_AwaitExpr___Struct_toolchain_ast_BinaryExpr___Struct_toolchain_ast_BlockExpr___Struct_toolchain_ast_BoolLitExpr___Struct_toolchain_ast_CallExpr___Struct_toolchain_ast_CastExpr___Struct_toolchain_ast_CharLitExpr___Struct_toolchain_ast_DotVariantExpr___Struct_toolchain_ast_FieldExpr___Struct_toolchain_ast_FloatLitExpr___Struct_toolchain_ast_FnTypeExpr___Struct_toolchain_ast_GenericInstExpr___Struct_toolchain_ast_IdentExpr___Struct_toolchain_ast_IfExpr___Struct_toolchain_ast_IndexExpr___Struct_toolchain_ast_IntLitExpr___Struct_toolchain_ast_IntrinsicCallExpr___Struct_toolchain_ast_LambdaExpr___Struct_toolchain_ast_MatchExpr___Struct_toolchain_ast_NullCoalesceExpr___Struct_toolchain_ast_NullLitExpr___Struct_toolchain_ast_RangeExpr___Struct_toolchain_ast_SeqLitExpr___Struct_toolchain_ast_StringLitExpr___Struct_toolchain_ast_StructLitExpr___Struct_toolchain_ast_UnaryExpr____t*) l4.payload.obj)->f_value;
                            vader_struct_toolchain_ast_BinaryExpr_t* _a7_obj = (vader_struct_toolchain_ast_BinaryExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BinaryExpr_t));
                            vader_obj_header_init(_a7_obj, 580u);
                            _a7_obj->f_span = l24;
                            _a7_obj->f_id = INT64_C(0);
                            _a7_obj->f_op = (uint8_t) 18;
                            _a7_obj->f_left = l25;
                            _a7_obj->f_right = l20;
                            l26 = (void*) _a7_obj;
                            l27 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l19)->f_span)->f_start;
                            l28 = ((vader_struct_toolchain_span_Span_t*) VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, l20.payload.obj))->f_end;
                            vader_struct_toolchain_span_Span_t* _a8_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
                            vader_obj_header_init(_a8_obj, 667u);
                            _a8_obj->f_start = l27;
                            _a8_obj->f_end = l28;
                            t1 = (void*) _a8_obj;
                            vader_struct_toolchain_ast_UnaryExpr_t* _a9_obj = (vader_struct_toolchain_ast_UnaryExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_UnaryExpr_t));
                            vader_obj_header_init(_a9_obj, 659u);
                            _a9_obj->f_span = t1;
                            _a9_obj->f_id = INT64_C(0);
                            _a9_obj->f_op = (uint8_t) 1;
                            _a9_obj->f_operand = vader_ref_box(l26);
                            l29 = (void*) _a9_obj;
                            ((vader_struct__Cell_Union_Struct_toolchain_ast_ArrayTypeExpr___Struct_toolchain_ast_AwaitExpr___Struct_toolchain_ast_BinaryExpr___Struct_toolchain_ast_BlockExpr___Struct_toolchain_ast_BoolLitExpr___Struct_toolchain_ast_CallExpr___Struct_toolchain_ast_CastExpr___Struct_toolchain_ast_CharLitExpr___Struct_toolchain_ast_DotVariantExpr___Struct_toolchain_ast_FieldExpr___Struct_toolchain_ast_FloatLitExpr___Struct_toolchain_ast_FnTypeExpr___Struct_toolchain_ast_GenericInstExpr___Struct_toolchain_ast_IdentExpr___Struct_toolchain_ast_IfExpr___Struct_toolchain_ast_IndexExpr___Struct_toolchain_ast_IntLitExpr___Struct_toolchain_ast_IntrinsicCallExpr___Struct_toolchain_ast_LambdaExpr___Struct_toolchain_ast_MatchExpr___Struct_toolchain_ast_NullCoalesceExpr___Struct_toolchain_ast_NullLitExpr___Struct_toolchain_ast_RangeExpr___Struct_toolchain_ast_SeqLitExpr___Struct_toolchain_ast_StringLitExpr___Struct_toolchain_ast_StructLitExpr___Struct_toolchain_ast_UnaryExpr____t*) l4.payload.obj)->f_value = vader_ref_box(l29);
                            VADER_WRITE_BARRIER((vader_struct__Cell_Union_Struct_toolchain_ast_ArrayTypeExpr___Struct_toolchain_ast_AwaitExpr___Struct_toolchain_ast_BinaryExpr___Struct_toolchain_ast_BlockExpr___Struct_toolchain_ast_BoolLitExpr___Struct_toolchain_ast_CallExpr___Struct_toolchain_ast_CastExpr___Struct_toolchain_ast_CharLitExpr___Struct_toolchain_ast_DotVariantExpr___Struct_toolchain_ast_FieldExpr___Struct_toolchain_ast_FloatLitExpr___Struct_toolchain_ast_FnTypeExpr___Struct_toolchain_ast_GenericInstExpr___Struct_toolchain_ast_IdentExpr___Struct_toolchain_ast_IfExpr___Struct_toolchain_ast_IndexExpr___Struct_toolchain_ast_IntLitExpr___Struct_toolchain_ast_IntrinsicCallExpr___Struct_toolchain_ast_LambdaExpr___Struct_toolchain_ast_MatchExpr___Struct_toolchain_ast_NullCoalesceExpr___Struct_toolchain_ast_NullLitExpr___Struct_toolchain_ast_RangeExpr___Struct_toolchain_ast_SeqLitExpr___Struct_toolchain_ast_StringLitExpr___Struct_toolchain_ast_StructLitExpr___Struct_toolchain_ast_UnaryExpr____t*) l4.payload.obj);
                            l2 = INT32_C(20);
                            continue;
                        }
                    }
                }
                if (((vader_struct_vader_lexer_Token_t*) l3)->f_kind == INT32_C(61)) {
                    if ((INT32_C(6) >= l1)) {
                        vader_parser_advance(l0);
                        l30 = vader_parser_parse_coalesce_fallback(l0);
                        l31 = ((vader_struct_toolchain_span_Span_t*) VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, ((vader_struct__Cell_Union_Struct_toolchain_ast_ArrayTypeExpr___Struct_toolchain_ast_AwaitExpr___Struct_toolchain_ast_BinaryExpr___Struct_toolchain_ast_BlockExpr___Struct_toolchain_ast_BoolLitExpr___Struct_toolchain_ast_CallExpr___Struct_toolchain_ast_CastExpr___Struct_toolchain_ast_CharLitExpr___Struct_toolchain_ast_DotVariantExpr___Struct_toolchain_ast_FieldExpr___Struct_toolchain_ast_FloatLitExpr___Struct_toolchain_ast_FnTypeExpr___Struct_toolchain_ast_GenericInstExpr___Struct_toolchain_ast_IdentExpr___Struct_toolchain_ast_IfExpr___Struct_toolchain_ast_IndexExpr___Struct_toolchain_ast_IntLitExpr___Struct_toolchain_ast_IntrinsicCallExpr___Struct_toolchain_ast_LambdaExpr___Struct_toolchain_ast_MatchExpr___Struct_toolchain_ast_NullCoalesceExpr___Struct_toolchain_ast_NullLitExpr___Struct_toolchain_ast_RangeExpr___Struct_toolchain_ast_SeqLitExpr___Struct_toolchain_ast_StringLitExpr___Struct_toolchain_ast_StructLitExpr___Struct_toolchain_ast_UnaryExpr____t*) l4.payload.obj)->f_value.payload.obj))->f_start;
                        t1 = vader_parser_peek_at(l0, INT32_C(-1));
                        l32 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) t1)->f_span)->f_end;
                        vader_struct_toolchain_span_Span_t* _a10_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
                        vader_obj_header_init(_a10_obj, 667u);
                        _a10_obj->f_start = l31;
                        _a10_obj->f_end = l32;
                        l33 = (void*) _a10_obj;
                        l34 = ((vader_struct__Cell_Union_Struct_toolchain_ast_ArrayTypeExpr___Struct_toolchain_ast_AwaitExpr___Struct_toolchain_ast_BinaryExpr___Struct_toolchain_ast_BlockExpr___Struct_toolchain_ast_BoolLitExpr___Struct_toolchain_ast_CallExpr___Struct_toolchain_ast_CastExpr___Struct_toolchain_ast_CharLitExpr___Struct_toolchain_ast_DotVariantExpr___Struct_toolchain_ast_FieldExpr___Struct_toolchain_ast_FloatLitExpr___Struct_toolchain_ast_FnTypeExpr___Struct_toolchain_ast_GenericInstExpr___Struct_toolchain_ast_IdentExpr___Struct_toolchain_ast_IfExpr___Struct_toolchain_ast_IndexExpr___Struct_toolchain_ast_IntLitExpr___Struct_toolchain_ast_IntrinsicCallExpr___Struct_toolchain_ast_LambdaExpr___Struct_toolchain_ast_MatchExpr___Struct_toolchain_ast_NullCoalesceExpr___Struct_toolchain_ast_NullLitExpr___Struct_toolchain_ast_RangeExpr___Struct_toolchain_ast_SeqLitExpr___Struct_toolchain_ast_StringLitExpr___Struct_toolchain_ast_StructLitExpr___Struct_toolchain_ast_UnaryExpr____t*) l4.payload.obj)->f_value;
                        vader_struct_toolchain_ast_NullCoalesceExpr_t* _a11_obj = (vader_struct_toolchain_ast_NullCoalesceExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_NullCoalesceExpr_t));
                        vader_obj_header_init(_a11_obj, 631u);
                        _a11_obj->f_span = l33;
                        _a11_obj->f_id = INT64_C(0);
                        _a11_obj->f_left = l34;
                        _a11_obj->f_fallback = l30;
                        l35 = (void*) _a11_obj;
                        ((vader_struct__Cell_Union_Struct_toolchain_ast_ArrayTypeExpr___Struct_toolchain_ast_AwaitExpr___Struct_toolchain_ast_BinaryExpr___Struct_toolchain_ast_BlockExpr___Struct_toolchain_ast_BoolLitExpr___Struct_toolchain_ast_CallExpr___Struct_toolchain_ast_CastExpr___Struct_toolchain_ast_CharLitExpr___Struct_toolchain_ast_DotVariantExpr___Struct_toolchain_ast_FieldExpr___Struct_toolchain_ast_FloatLitExpr___Struct_toolchain_ast_FnTypeExpr___Struct_toolchain_ast_GenericInstExpr___Struct_toolchain_ast_IdentExpr___Struct_toolchain_ast_IfExpr___Struct_toolchain_ast_IndexExpr___Struct_toolchain_ast_IntLitExpr___Struct_toolchain_ast_IntrinsicCallExpr___Struct_toolchain_ast_LambdaExpr___Struct_toolchain_ast_MatchExpr___Struct_toolchain_ast_NullCoalesceExpr___Struct_toolchain_ast_NullLitExpr___Struct_toolchain_ast_RangeExpr___Struct_toolchain_ast_SeqLitExpr___Struct_toolchain_ast_StringLitExpr___Struct_toolchain_ast_StructLitExpr___Struct_toolchain_ast_UnaryExpr____t*) l4.payload.obj)->f_value = vader_ref_box(l35);
                        VADER_WRITE_BARRIER((vader_struct__Cell_Union_Struct_toolchain_ast_ArrayTypeExpr___Struct_toolchain_ast_AwaitExpr___Struct_toolchain_ast_BinaryExpr___Struct_toolchain_ast_BlockExpr___Struct_toolchain_ast_BoolLitExpr___Struct_toolchain_ast_CallExpr___Struct_toolchain_ast_CastExpr___Struct_toolchain_ast_CharLitExpr___Struct_toolchain_ast_DotVariantExpr___Struct_toolchain_ast_FieldExpr___Struct_toolchain_ast_FloatLitExpr___Struct_toolchain_ast_FnTypeExpr___Struct_toolchain_ast_GenericInstExpr___Struct_toolchain_ast_IdentExpr___Struct_toolchain_ast_IfExpr___Struct_toolchain_ast_IndexExpr___Struct_toolchain_ast_IntLitExpr___Struct_toolchain_ast_IntrinsicCallExpr___Struct_toolchain_ast_LambdaExpr___Struct_toolchain_ast_MatchExpr___Struct_toolchain_ast_NullCoalesceExpr___Struct_toolchain_ast_NullLitExpr___Struct_toolchain_ast_RangeExpr___Struct_toolchain_ast_SeqLitExpr___Struct_toolchain_ast_StringLitExpr___Struct_toolchain_ast_StructLitExpr___Struct_toolchain_ast_UnaryExpr____t*) l4.payload.obj);
                        l2 = INT32_C(-1);
                        continue;
                    }
                }
                l36 = vader_parser_infix_for(((vader_struct_vader_lexer_Token_t*) l3)->f_kind);
                t3 = ((vader_struct_vader_parser_InfixOpDescr_t*) l36)->f_has;
                if (!(t3)) {
                    break;
                }
                t0 = ((vader_struct_vader_parser_InfixOpDescr_t*) l36)->f_left_bp;
                if (!((t0 >= l1))) {
                    break;
                }
                t3 = ((vader_struct_vader_parser_InfixOpDescr_t*) l36)->f_non_assoc;
                if (t3) {
                    l38 = ((vader_struct_vader_parser_InfixOpDescr_t*) l36)->f_left_bp;
                    l37 = l2 == l38;
                } else {
                    l37 = false;
                }
                if (l37) {
                    l39 = ((vader_struct_vader_lexer_Token_t*) l3)->f_span;
                    l40 = vader_parser_describe_token(l3);
                    l41 = concat_2(1674u, l40);
                    vader_parser_error(l0, (uint8_t) 6, l39, l41);
                }
                vader_parser_advance(l0);
                t3 = ((vader_struct_vader_parser_InfixOpDescr_t*) l36)->f_non_assoc;
                if (t3) {
                    t0 = ((vader_struct_vader_parser_InfixOpDescr_t*) l36)->f_right_bp;
                    l42 = vader_chk_add(i32, t0, INT32_C(1));
                } else {
                    l42 = ((vader_struct_vader_parser_InfixOpDescr_t*) l36)->f_right_bp;
                }
                if (((vader_struct_vader_parser_InfixOpDescr_t*) l36)->f_op == INT32_C(18)) {
                    l43 = vader_parser_parse_type(l0);
                } else {
                    l43 = vader_parser_parse_expr(l0, l42);
                }
                if (l37) {
                    continue;
                }
                if (((vader_struct_vader_lexer_Token_t*) l3)->f_kind == INT32_C(73)) {
                    l44 = true;
                } else {
                    l44 = ((vader_struct_vader_lexer_Token_t*) l3)->f_kind == INT32_C(74);
                }
                if (l44) {
                    l45 = ((vader_struct_toolchain_span_Span_t*) VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, ((vader_struct__Cell_Union_Struct_toolchain_ast_ArrayTypeExpr___Struct_toolchain_ast_AwaitExpr___Struct_toolchain_ast_BinaryExpr___Struct_toolchain_ast_BlockExpr___Struct_toolchain_ast_BoolLitExpr___Struct_toolchain_ast_CallExpr___Struct_toolchain_ast_CastExpr___Struct_toolchain_ast_CharLitExpr___Struct_toolchain_ast_DotVariantExpr___Struct_toolchain_ast_FieldExpr___Struct_toolchain_ast_FloatLitExpr___Struct_toolchain_ast_FnTypeExpr___Struct_toolchain_ast_GenericInstExpr___Struct_toolchain_ast_IdentExpr___Struct_toolchain_ast_IfExpr___Struct_toolchain_ast_IndexExpr___Struct_toolchain_ast_IntLitExpr___Struct_toolchain_ast_IntrinsicCallExpr___Struct_toolchain_ast_LambdaExpr___Struct_toolchain_ast_MatchExpr___Struct_toolchain_ast_NullCoalesceExpr___Struct_toolchain_ast_NullLitExpr___Struct_toolchain_ast_RangeExpr___Struct_toolchain_ast_SeqLitExpr___Struct_toolchain_ast_StringLitExpr___Struct_toolchain_ast_StructLitExpr___Struct_toolchain_ast_UnaryExpr____t*) l4.payload.obj)->f_value.payload.obj))->f_start;
                    l46 = ((vader_struct_toolchain_span_Span_t*) VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, l43.payload.obj))->f_end;
                    vader_struct_toolchain_span_Span_t* _a12_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
                    vader_obj_header_init(_a12_obj, 667u);
                    _a12_obj->f_start = l45;
                    _a12_obj->f_end = l46;
                    l47 = (void*) _a12_obj;
                    l48 = ((vader_struct_vader_lexer_Token_t*) l3)->f_kind == INT32_C(74);
                    l49 = ((vader_struct__Cell_Union_Struct_toolchain_ast_ArrayTypeExpr___Struct_toolchain_ast_AwaitExpr___Struct_toolchain_ast_BinaryExpr___Struct_toolchain_ast_BlockExpr___Struct_toolchain_ast_BoolLitExpr___Struct_toolchain_ast_CallExpr___Struct_toolchain_ast_CastExpr___Struct_toolchain_ast_CharLitExpr___Struct_toolchain_ast_DotVariantExpr___Struct_toolchain_ast_FieldExpr___Struct_toolchain_ast_FloatLitExpr___Struct_toolchain_ast_FnTypeExpr___Struct_toolchain_ast_GenericInstExpr___Struct_toolchain_ast_IdentExpr___Struct_toolchain_ast_IfExpr___Struct_toolchain_ast_IndexExpr___Struct_toolchain_ast_IntLitExpr___Struct_toolchain_ast_IntrinsicCallExpr___Struct_toolchain_ast_LambdaExpr___Struct_toolchain_ast_MatchExpr___Struct_toolchain_ast_NullCoalesceExpr___Struct_toolchain_ast_NullLitExpr___Struct_toolchain_ast_RangeExpr___Struct_toolchain_ast_SeqLitExpr___Struct_toolchain_ast_StringLitExpr___Struct_toolchain_ast_StructLitExpr___Struct_toolchain_ast_UnaryExpr____t*) l4.payload.obj)->f_value;
                    vader_struct_toolchain_ast_RangeExpr_t* _a13_obj = (vader_struct_toolchain_ast_RangeExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_RangeExpr_t));
                    vader_obj_header_init(_a13_obj, 638u);
                    _a13_obj->f_span = l47;
                    _a13_obj->f_id = INT64_C(0);
                    _a13_obj->f_inclusive = l48;
                    _a13_obj->f_lower = l49;
                    _a13_obj->f_upper = l43;
                    l50 = (void*) _a13_obj;
                    ((vader_struct__Cell_Union_Struct_toolchain_ast_ArrayTypeExpr___Struct_toolchain_ast_AwaitExpr___Struct_toolchain_ast_BinaryExpr___Struct_toolchain_ast_BlockExpr___Struct_toolchain_ast_BoolLitExpr___Struct_toolchain_ast_CallExpr___Struct_toolchain_ast_CastExpr___Struct_toolchain_ast_CharLitExpr___Struct_toolchain_ast_DotVariantExpr___Struct_toolchain_ast_FieldExpr___Struct_toolchain_ast_FloatLitExpr___Struct_toolchain_ast_FnTypeExpr___Struct_toolchain_ast_GenericInstExpr___Struct_toolchain_ast_IdentExpr___Struct_toolchain_ast_IfExpr___Struct_toolchain_ast_IndexExpr___Struct_toolchain_ast_IntLitExpr___Struct_toolchain_ast_IntrinsicCallExpr___Struct_toolchain_ast_LambdaExpr___Struct_toolchain_ast_MatchExpr___Struct_toolchain_ast_NullCoalesceExpr___Struct_toolchain_ast_NullLitExpr___Struct_toolchain_ast_RangeExpr___Struct_toolchain_ast_SeqLitExpr___Struct_toolchain_ast_StringLitExpr___Struct_toolchain_ast_StructLitExpr___Struct_toolchain_ast_UnaryExpr____t*) l4.payload.obj)->f_value = vader_ref_box(l50);
                    VADER_WRITE_BARRIER((vader_struct__Cell_Union_Struct_toolchain_ast_ArrayTypeExpr___Struct_toolchain_ast_AwaitExpr___Struct_toolchain_ast_BinaryExpr___Struct_toolchain_ast_BlockExpr___Struct_toolchain_ast_BoolLitExpr___Struct_toolchain_ast_CallExpr___Struct_toolchain_ast_CastExpr___Struct_toolchain_ast_CharLitExpr___Struct_toolchain_ast_DotVariantExpr___Struct_toolchain_ast_FieldExpr___Struct_toolchain_ast_FloatLitExpr___Struct_toolchain_ast_FnTypeExpr___Struct_toolchain_ast_GenericInstExpr___Struct_toolchain_ast_IdentExpr___Struct_toolchain_ast_IfExpr___Struct_toolchain_ast_IndexExpr___Struct_toolchain_ast_IntLitExpr___Struct_toolchain_ast_IntrinsicCallExpr___Struct_toolchain_ast_LambdaExpr___Struct_toolchain_ast_MatchExpr___Struct_toolchain_ast_NullCoalesceExpr___Struct_toolchain_ast_NullLitExpr___Struct_toolchain_ast_RangeExpr___Struct_toolchain_ast_SeqLitExpr___Struct_toolchain_ast_StringLitExpr___Struct_toolchain_ast_StructLitExpr___Struct_toolchain_ast_UnaryExpr____t*) l4.payload.obj);
                } else {
                    if (((vader_struct_vader_parser_InfixOpDescr_t*) l36)->f_op == INT32_C(18)) {
                        vader_struct___lambda_env_vader_parser_3_t* _a14_obj = (vader_struct___lambda_env_vader_parser_3_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_parser_3_t));
                        vader_obj_header_init(_a14_obj, 383u);
                        _a14_obj->f_cap_0 = l4;
                        t1 = (void*) _a14_obj;
                        vader_fn_t* _a15_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
                        vader_obj_header_init(_a15_closure, 288u);
                        _a15_closure->code = (void*) &vader_fn_lift___lambda_vader_parser_2;
                        _a15_closure->env = t1;
                        l51 = (void*) _a15_closure;
                        vader_parser_reject_as_binder(l0, (uint8_t) 21, l51);
                    }
                    l52 = ((vader_struct_toolchain_span_Span_t*) VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, ((vader_struct__Cell_Union_Struct_toolchain_ast_ArrayTypeExpr___Struct_toolchain_ast_AwaitExpr___Struct_toolchain_ast_BinaryExpr___Struct_toolchain_ast_BlockExpr___Struct_toolchain_ast_BoolLitExpr___Struct_toolchain_ast_CallExpr___Struct_toolchain_ast_CastExpr___Struct_toolchain_ast_CharLitExpr___Struct_toolchain_ast_DotVariantExpr___Struct_toolchain_ast_FieldExpr___Struct_toolchain_ast_FloatLitExpr___Struct_toolchain_ast_FnTypeExpr___Struct_toolchain_ast_GenericInstExpr___Struct_toolchain_ast_IdentExpr___Struct_toolchain_ast_IfExpr___Struct_toolchain_ast_IndexExpr___Struct_toolchain_ast_IntLitExpr___Struct_toolchain_ast_IntrinsicCallExpr___Struct_toolchain_ast_LambdaExpr___Struct_toolchain_ast_MatchExpr___Struct_toolchain_ast_NullCoalesceExpr___Struct_toolchain_ast_NullLitExpr___Struct_toolchain_ast_RangeExpr___Struct_toolchain_ast_SeqLitExpr___Struct_toolchain_ast_StringLitExpr___Struct_toolchain_ast_StructLitExpr___Struct_toolchain_ast_UnaryExpr____t*) l4.payload.obj)->f_value.payload.obj))->f_start;
                    l53 = ((vader_struct_toolchain_span_Span_t*) VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, l43.payload.obj))->f_end;
                    vader_struct_toolchain_span_Span_t* _a16_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
                    vader_obj_header_init(_a16_obj, 667u);
                    _a16_obj->f_start = l52;
                    _a16_obj->f_end = l53;
                    l54 = (void*) _a16_obj;
                    l55 = ((vader_struct_vader_parser_InfixOpDescr_t*) l36)->f_op;
                    l56 = ((vader_struct__Cell_Union_Struct_toolchain_ast_ArrayTypeExpr___Struct_toolchain_ast_AwaitExpr___Struct_toolchain_ast_BinaryExpr___Struct_toolchain_ast_BlockExpr___Struct_toolchain_ast_BoolLitExpr___Struct_toolchain_ast_CallExpr___Struct_toolchain_ast_CastExpr___Struct_toolchain_ast_CharLitExpr___Struct_toolchain_ast_DotVariantExpr___Struct_toolchain_ast_FieldExpr___Struct_toolchain_ast_FloatLitExpr___Struct_toolchain_ast_FnTypeExpr___Struct_toolchain_ast_GenericInstExpr___Struct_toolchain_ast_IdentExpr___Struct_toolchain_ast_IfExpr___Struct_toolchain_ast_IndexExpr___Struct_toolchain_ast_IntLitExpr___Struct_toolchain_ast_IntrinsicCallExpr___Struct_toolchain_ast_LambdaExpr___Struct_toolchain_ast_MatchExpr___Struct_toolchain_ast_NullCoalesceExpr___Struct_toolchain_ast_NullLitExpr___Struct_toolchain_ast_RangeExpr___Struct_toolchain_ast_SeqLitExpr___Struct_toolchain_ast_StringLitExpr___Struct_toolchain_ast_StructLitExpr___Struct_toolchain_ast_UnaryExpr____t*) l4.payload.obj)->f_value;
                    vader_struct_toolchain_ast_BinaryExpr_t* _a17_obj = (vader_struct_toolchain_ast_BinaryExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BinaryExpr_t));
                    vader_obj_header_init(_a17_obj, 580u);
                    _a17_obj->f_span = l54;
                    _a17_obj->f_id = INT64_C(0);
                    _a17_obj->f_op = l55;
                    _a17_obj->f_left = l56;
                    _a17_obj->f_right = l43;
                    l57 = (void*) _a17_obj;
                    ((vader_struct__Cell_Union_Struct_toolchain_ast_ArrayTypeExpr___Struct_toolchain_ast_AwaitExpr___Struct_toolchain_ast_BinaryExpr___Struct_toolchain_ast_BlockExpr___Struct_toolchain_ast_BoolLitExpr___Struct_toolchain_ast_CallExpr___Struct_toolchain_ast_CastExpr___Struct_toolchain_ast_CharLitExpr___Struct_toolchain_ast_DotVariantExpr___Struct_toolchain_ast_FieldExpr___Struct_toolchain_ast_FloatLitExpr___Struct_toolchain_ast_FnTypeExpr___Struct_toolchain_ast_GenericInstExpr___Struct_toolchain_ast_IdentExpr___Struct_toolchain_ast_IfExpr___Struct_toolchain_ast_IndexExpr___Struct_toolchain_ast_IntLitExpr___Struct_toolchain_ast_IntrinsicCallExpr___Struct_toolchain_ast_LambdaExpr___Struct_toolchain_ast_MatchExpr___Struct_toolchain_ast_NullCoalesceExpr___Struct_toolchain_ast_NullLitExpr___Struct_toolchain_ast_RangeExpr___Struct_toolchain_ast_SeqLitExpr___Struct_toolchain_ast_StringLitExpr___Struct_toolchain_ast_StructLitExpr___Struct_toolchain_ast_UnaryExpr____t*) l4.payload.obj)->f_value = vader_ref_box(l57);
                    VADER_WRITE_BARRIER((vader_struct__Cell_Union_Struct_toolchain_ast_ArrayTypeExpr___Struct_toolchain_ast_AwaitExpr___Struct_toolchain_ast_BinaryExpr___Struct_toolchain_ast_BlockExpr___Struct_toolchain_ast_BoolLitExpr___Struct_toolchain_ast_CallExpr___Struct_toolchain_ast_CastExpr___Struct_toolchain_ast_CharLitExpr___Struct_toolchain_ast_DotVariantExpr___Struct_toolchain_ast_FieldExpr___Struct_toolchain_ast_FloatLitExpr___Struct_toolchain_ast_FnTypeExpr___Struct_toolchain_ast_GenericInstExpr___Struct_toolchain_ast_IdentExpr___Struct_toolchain_ast_IfExpr___Struct_toolchain_ast_IndexExpr___Struct_toolchain_ast_IntLitExpr___Struct_toolchain_ast_IntrinsicCallExpr___Struct_toolchain_ast_LambdaExpr___Struct_toolchain_ast_MatchExpr___Struct_toolchain_ast_NullCoalesceExpr___Struct_toolchain_ast_NullLitExpr___Struct_toolchain_ast_RangeExpr___Struct_toolchain_ast_SeqLitExpr___Struct_toolchain_ast_StringLitExpr___Struct_toolchain_ast_StructLitExpr___Struct_toolchain_ast_UnaryExpr____t*) l4.payload.obj);
                }
                t3 = ((vader_struct_vader_parser_InfixOpDescr_t*) l36)->f_non_assoc;
                if (t3) {
                    l58 = ((vader_struct_vader_parser_InfixOpDescr_t*) l36)->f_left_bp;
                } else {
                    l58 = INT32_C(-1);
                }
                l2 = l58;
                continue;
            }
            goto end_62;
        } end_63: ;
    } end_62: ;
    t0 = ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth;
    l2 = vader_chk_sub(i32, t0, INT32_C(1));
    ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth = l2;
    { vader_box_t __vret = ((vader_struct__Cell_Union_Struct_toolchain_ast_ArrayTypeExpr___Struct_toolchain_ast_AwaitExpr___Struct_toolchain_ast_BinaryExpr___Struct_toolchain_ast_BlockExpr___Struct_toolchain_ast_BoolLitExpr___Struct_toolchain_ast_CallExpr___Struct_toolchain_ast_CastExpr___Struct_toolchain_ast_CharLitExpr___Struct_toolchain_ast_DotVariantExpr___Struct_toolchain_ast_FieldExpr___Struct_toolchain_ast_FloatLitExpr___Struct_toolchain_ast_FnTypeExpr___Struct_toolchain_ast_GenericInstExpr___Struct_toolchain_ast_IdentExpr___Struct_toolchain_ast_IfExpr___Struct_toolchain_ast_IndexExpr___Struct_toolchain_ast_IntLitExpr___Struct_toolchain_ast_IntrinsicCallExpr___Struct_toolchain_ast_LambdaExpr___Struct_toolchain_ast_MatchExpr___Struct_toolchain_ast_NullCoalesceExpr___Struct_toolchain_ast_NullLitExpr___Struct_toolchain_ast_RangeExpr___Struct_toolchain_ast_SeqLitExpr___Struct_toolchain_ast_StringLitExpr___Struct_toolchain_ast_StructLitExpr___Struct_toolchain_ast_UnaryExpr____t*) l4.payload.obj)->f_value; vader_gc_top = gc_frame.prev; return __vret; }
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
    t0 = vader_parser_check(l0, (uint8_t) 62);
    if (t0) {
        vader_parser_advance(l0);
        l2 = vader_parser_parse_expr(l0, INT32_C(0));
        l3 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, l2.payload.obj);
        vader_array_t* _a0_arr = vader_array_new(229u, 0u, 13u, 1536u);
        l4 = (void*) _a0_arr;
        vader_struct_toolchain_ast_BlockExpr_t* _a1_obj = (vader_struct_toolchain_ast_BlockExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BlockExpr_t));
        vader_obj_header_init(_a1_obj, 581u);
        _a1_obj->f_span = l3;
        _a1_obj->f_id = INT64_C(0);
        _a1_obj->f_stmts = l4;
        _a1_obj->f_trailing = l2;
        t1 = (void*) _a1_obj;
        vader_struct_vader_parser_FnBodyTail_t* _a2_obj = (vader_struct_vader_parser_FnBodyTail_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_FnBodyTail_t));
        vader_obj_header_init(_a2_obj, 1198u);
        _a2_obj->f_body = vader_ref_box(t1);
        _a2_obj->f_is_expression_bodied = true;
        t1 = (void*) _a2_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_parser_check(l0, (uint8_t) 84);
    if (!(t0)) {
        vader_struct_vader_parser_FnBodyTail_t* _a3_obj = (vader_struct_vader_parser_FnBodyTail_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_FnBodyTail_t));
        vader_obj_header_init(_a3_obj, 1198u);
        _a3_obj->f_body = vader_box_obj(0u, NULL);
        _a3_obj->f_is_expression_bodied = false;
        t1 = (void*) _a3_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_parser_parse_block(l0);
    vader_struct_vader_parser_FnBodyTail_t* _a4_obj = (vader_struct_vader_parser_FnBodyTail_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_FnBodyTail_t));
    vader_obj_header_init(_a4_obj, 1198u);
    _a4_obj->f_body = vader_ref_box(t1);
    _a4_obj->f_is_expression_bodied = false;
    t1 = (void*) _a4_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_fn_decl(void* l0, void* l1, uint8_t l2, void* l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    vader_box_t l7 = vader_box_null(), l12 = vader_box_null();
    vader_string_t l9 = 0;
    bool l13, l14;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[3] = { &l7, &l12, &t0 };
    void** gc_raw_roots[10] = { &l0, &l1, &l3, &l4, &l5, &l6, &l8, &l10, &l11, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_parser_reject_c_decorators(l0, l1, 1401u);
    vader_parser_advance(l0);
    l4 = vader_parser_parse_angle_type_params(l0);
    l5 = vader_parser_parse_fn_signature_params(l0);
    l6 = ((vader_struct_vader_parser_FnSignature_t*) l5)->f_type_params;
    l4 = vader_parser_merge_type_params(l4, l6);
    l7 = vader_box_obj(0u, NULL);
    t0 = vader_parser_match_kind(l0, (uint8_t) 76);
    if (!(t0.tag == 0u)) {
        l7 = vader_parser_parse_type(l0);
    }
    l6 = vader_parser_parse_fn_body_tail(l0, l7);
    l8 = vader_parser_peek_at(l0, INT32_C(-1));
    l8 = vader_parser_span_of(l0, l3, l8);
    l9 = ((vader_struct_vader_lexer_Token_t*) l3)->f_text;
    l10 = ((vader_struct_vader_lexer_Token_t*) l3)->f_span;
    l11 = ((vader_struct_vader_parser_FnSignature_t*) l5)->f_params;
    l12 = ((vader_struct_vader_parser_FnBodyTail_t*) l6)->f_body;
    l13 = ((vader_struct_vader_parser_FnBodyTail_t*) l6)->f_is_expression_bodied;
    l14 = ((vader_struct_vader_parser_FnSignature_t*) l5)->f_trailing_comma;
    vader_struct_toolchain_ast_FnDecl_t* _a0_obj = (vader_struct_toolchain_ast_FnDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FnDecl_t));
    vader_obj_header_init(_a0_obj, 605u);
    _a0_obj->f_span = l8;
    _a0_obj->f_id = INT64_C(0);
    _a0_obj->f_name = l9;
    _a0_obj->f_name_span = l10;
    _a0_obj->f_visibility = l2;
    _a0_obj->f_type_params = l4;
    _a0_obj->f_params = l11;
    _a0_obj->f_return_type = l7;
    _a0_obj->f_body = l12;
    _a0_obj->f_decorators = l1;
    _a0_obj->f_sam_synthetic = false;
    _a0_obj->f_is_expression_bodied = l13;
    _a0_obj->f_materialized = false;
    _a0_obj->f_comptime_synthetic = false;
    _a0_obj->f_trailing_comma = l14;
    t1 = (void*) _a0_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_parser_parse_fn_decl_inside_trait(void* l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    uint8_t l2;
    bool l3, l14;
    vader_string_t l5 = 0;
    vader_box_t l9 = vader_box_null(), l13 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    bool t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[3] = { &l9, &l13, &t0 };
    void** gc_raw_roots[10] = { &l0, &l1, &l4, &l6, &l7, &l8, &l10, &l11, &l12, &t2 };
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
        l3 = ((vader_struct_vader_lexer_Token_t*) t2)->f_kind == INT32_C(71);
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
        t0 = vader_parser_match_kind(l0, (uint8_t) 76);
        if (!(t0.tag == 0u)) {
            l9 = vader_parser_parse_type(l0);
        }
        l8 = vader_parser_parse_fn_body_tail(l0, l9);
        l10 = vader_parser_peek_at(l0, INT32_C(-1));
        l10 = vader_parser_span_of(l0, l4, l10);
        l5 = ((vader_struct_vader_lexer_Token_t*) l4)->f_text;
        l11 = ((vader_struct_vader_lexer_Token_t*) l4)->f_span;
        l12 = ((vader_struct_vader_parser_FnSignature_t*) l7)->f_params;
        l13 = ((vader_struct_vader_parser_FnBodyTail_t*) l8)->f_body;
        l3 = ((vader_struct_vader_parser_FnBodyTail_t*) l8)->f_is_expression_bodied;
        l14 = ((vader_struct_vader_parser_FnSignature_t*) l7)->f_trailing_comma;
        vader_struct_toolchain_ast_FnDecl_t* _a0_obj = (vader_struct_toolchain_ast_FnDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FnDecl_t));
        vader_obj_header_init(_a0_obj, 605u);
        _a0_obj->f_span = l10;
        _a0_obj->f_id = INT64_C(0);
        _a0_obj->f_name = l5;
        _a0_obj->f_name_span = l11;
        _a0_obj->f_visibility = l2;
        _a0_obj->f_type_params = l6;
        _a0_obj->f_params = l12;
        _a0_obj->f_return_type = l9;
        _a0_obj->f_body = l13;
        _a0_obj->f_decorators = l1;
        _a0_obj->f_sam_synthetic = false;
        _a0_obj->f_is_expression_bodied = l3;
        _a0_obj->f_materialized = false;
        _a0_obj->f_comptime_synthetic = false;
        _a0_obj->f_trailing_comma = l14;
        t2 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = vader_parser_peek(l0);
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(11)) {
        l4 = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
        vader_parser_error(l0, (uint8_t) 4, l4, 2637u);
    } else {
        l4 = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
        l5 = vader_parser_describe_token(l1);
        l5 = concat_3(1845u, l5, 289u);
        vader_parser_error(l0, (uint8_t) 4, l4, l5);
    }
    for (;;) {
        t1 = vader_parser_check(l0, (uint8_t) 85);
        if (!(t1)) {
            t1 = vader_parser_check(l0, (uint8_t) 0);
            if (t1) break;
            t1 = vader_parser_check(l0, (uint8_t) 2);
            if (t1) {
                t2 = vader_parser_peek_at(l0, INT32_C(1));
                if (((vader_struct_vader_lexer_Token_t*) t2)->f_kind == INT32_C(71)) {
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
    void* l16 = NULL;
    void* l17 = NULL;
    void* l19 = NULL;
    void* l20 = NULL;
    bool l3, l4, l7, l9;
    vader_string_t l12 = 0;
    vader_string_t l13 = 0;
    vader_string_t l18 = 0;
    vader_box_t l14 = vader_box_null(), l15 = vader_box_null();
    bool t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[3] = { &l14, &l15, &t1 };
    void** gc_raw_roots[13] = {
        &l0, &l1, &l2, &l5, &l6, &l8, &l10, &l11, &l16, &l17, &l19, &l20, &t2,
    };
    vader_string_t* gc_atom_roots[3] = { &l12, &l13, &l18 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 13u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(54u, 0u, 13u, 658u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(43u, 0u, 13u, 606u);
    l2 = (void*) _a1_arr;
    l3 = false;
    vader_parser_expect(l0, (uint8_t) 80, 1227u);
    vader_parser_skip_newlines(l0);
    t0 = vader_parser_check(l0, (uint8_t) 81);
    if (!(t0)) {
        l4 = true;
        for (;;) {
            vader_parser_skip_newlines(l0);
            t0 = vader_parser_check(l0, (uint8_t) 81);
            if (!(t0)) {
                t0 = vader_parser_check(l0, (uint8_t) 0);
                if (t0) break;
                if (!(l4)) {
                    t1 = vader_parser_match_kind(l0, (uint8_t) 86);
                    if (t1.tag == 0u) break;
                    vader_parser_skip_newlines(l0);
                    t0 = vader_parser_check(l0, (uint8_t) 81);
                    if (t0) {
                        l3 = true;
                        break;
                    }
                }
                l4 = false;
                l5 = vader_parser_peek(l0);
                l6 = vader_parser_parse_decorators(l0);
                l7 = false;
                t0 = vader_parser_check(l0, (uint8_t) 87);
                if (t0) {
                    t0 = vader_parser_check_at(l0, (uint8_t) 87, INT32_C(1));
                    if (t0) {
                        t0 = vader_parser_check_at(l0, (uint8_t) 87, INT32_C(2));
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
                    l14 = vader_box_obj(0u, NULL);
                    t1 = vader_parser_match_kind(l0, (uint8_t) 88);
                    if (!(t1.tag == 0u)) {
                        vader_parser_skip_newlines(l0);
                        l14 = vader_parser_parse_type(l0);
                    }
                    l15 = vader_box_obj(0u, NULL);
                    t1 = vader_parser_match_kind(l0, (uint8_t) 62);
                    if (!(t1.tag == 0u)) {
                        l15 = vader_parser_parse_expr(l0, INT32_C(0));
                    }
                    vader_parser_collect_type_params(l14, l1);
                    l16 = vader_parser_peek_at(l0, INT32_C(-1));
                    l17 = vader_parser_span_of(l0, l5, l16);
                    l18 = ((vader_struct_vader_lexer_Token_t*) l8)->f_text;
                    l19 = ((vader_struct_vader_lexer_Token_t*) l8)->f_span;
                    vader_struct_toolchain_ast_FnParam_t* _a2_obj = (vader_struct_toolchain_ast_FnParam_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FnParam_t));
                    vader_obj_header_init(_a2_obj, 606u);
                    _a2_obj->f_span = l17;
                    _a2_obj->f_id = INT64_C(0);
                    _a2_obj->f_name = l18;
                    _a2_obj->f_name_span = l19;
                    _a2_obj->f_ty = l14;
                    _a2_obj->f_default_value = l15;
                    _a2_obj->f_variadic = l7;
                    _a2_obj->f_decorators = l6;
                    l20 = (void*) _a2_obj;
                    vader_array_push_ref((vader_array_t*) l2, l20);
                    continue;
                }
                l10 = vader_parser_peek(l0);
                l11 = ((vader_struct_vader_lexer_Token_t*) l10)->f_span;
                l12 = vader_parser_describe_token(l10);
                l13 = concat_3(1846u, l12, 289u);
                vader_parser_error(l0, (uint8_t) 1, l11, l13);
                for (;;) {
                    t0 = vader_parser_check(l0, (uint8_t) 86);
                    if (!(t0)) {
                        t0 = vader_parser_check(l0, (uint8_t) 81);
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
    vader_parser_expect(l0, (uint8_t) 81, 1237u);
    vader_struct_vader_parser_FnSignature_t* _a3_obj = (vader_struct_vader_parser_FnSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_FnSignature_t));
    vader_obj_header_init(_a3_obj, 1199u);
    _a3_obj->f_params = l2;
    _a3_obj->f_type_params = l1;
    _a3_obj->f_trailing_comma = l3;
    t2 = (void*) _a3_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_fn_type(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l4 = NULL;
    vader_box_t l3 = vader_box_null();
    bool t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[2] = { &l3, &t1 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l4, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_advance(l0);
    vader_parser_expect(l0, (uint8_t) 80, 1226u);
    vader_array_t* _a0_arr = vader_array_new(227u, 0u, 13u, 1503u);
    l2 = (void*) _a0_arr;
    vader_parser_skip_newlines(l0);
    t0 = vader_parser_check(l0, (uint8_t) 81);
    if (!(t0)) {
        for (;;) {
            vader_parser_skip_newlines(l0);
            t0 = vader_parser_check(l0, (uint8_t) 81);
            if (!(t0)) {
                l3 = vader_parser_parse_type(l0);
                vader_array_push_ref((vader_array_t*) l2, l3.payload.obj);
                vader_parser_skip_newlines(l0);
                t1 = vader_parser_match_kind(l0, (uint8_t) 86);
                if (t1.tag == 0u) break;
                continue;
            }
            break;
        }
    }
    vader_parser_expect(l0, (uint8_t) 81, 1234u);
    l3 = vader_box_obj(0u, NULL);
    t1 = vader_parser_match_kind(l0, (uint8_t) 76);
    if (!(t1.tag == 0u)) {
        l3 = vader_parser_parse_type(l0);
    }
    l4 = vader_parser_peek_at(l0, INT32_C(-1));
    t2 = vader_parser_span_of(l0, l1, l4);
    vader_struct_toolchain_ast_FnTypeExpr_t* _a1_obj = (vader_struct_toolchain_ast_FnTypeExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FnTypeExpr_t));
    vader_obj_header_init(_a1_obj, 607u);
    _a1_obj->f_span = t2;
    _a1_obj->f_id = INT64_C(0);
    _a1_obj->f_params = l2;
    _a1_obj->f_return_type = l3;
    t2 = (void*) _a1_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_for(void* l0, vader_box_t l1, bool l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l10 = NULL;
    void* l13 = NULL;
    int32_t l7, l8;
    vader_box_t l9 = vader_box_null(), l12 = vader_box_null();
    vader_string_t l11 = 0;
    bool t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[3] = { &l1, &l9, &l12 };
    void** gc_raw_roots[8] = { &l0, &l3, &l4, &l5, &l6, &l10, &l13, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l11 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_parser_advance(l0);
    t0 = vader_parser_check(l0, (uint8_t) 84);
    if (t0) {
        l4 = vader_parser_parse_block(l0);
        l5 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l3)->f_span)->f_start;
        l6 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_BlockExpr_t*) l4)->f_span)->f_end;
        vader_struct_toolchain_span_Span_t* _a0_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
        vader_obj_header_init(_a0_obj, 667u);
        _a0_obj->f_start = l5;
        _a0_obj->f_end = l6;
        l5 = (void*) _a0_obj;
        vader_struct_toolchain_ast_InfiniteFor_t* _a1_obj = (vader_struct_toolchain_ast_InfiniteFor_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_InfiniteFor_t));
        vader_obj_header_init(_a1_obj, 619u);
        l6 = (void*) _a1_obj;
        vader_struct_toolchain_ast_ForStmt_t* _a2_obj = (vader_struct_toolchain_ast_ForStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ForStmt_t));
        vader_obj_header_init(_a2_obj, 608u);
        _a2_obj->f_span = l5;
        _a2_obj->f_id = INT64_C(0);
        _a2_obj->f_label = l1;
        _a2_obj->f_form = vader_ref_box(l6);
        _a2_obj->f_body = l4;
        _a2_obj->f_is_comptime = l2;
        t1 = (void*) _a2_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l7 = ((vader_struct_vader_parser_Parser_t*) l0)->f_no_struct_lit_at;
    l8 = ((vader_struct_vader_parser_Parser_t*) l0)->f_bracket_depth;
    ((vader_struct_vader_parser_Parser_t*) l0)->f_no_struct_lit_at = l8;
    t0 = vader_parser_check(l0, (uint8_t) 2);
    if (t0) {
        t0 = vader_parser_check_at(l0, (uint8_t) 21, INT32_C(1));
        if (t0) {
            l4 = vader_parser_advance(l0);
            vader_parser_advance(l0);
            l9 = vader_parser_parse_expr(l0, INT32_C(0));
            ((vader_struct_vader_parser_Parser_t*) l0)->f_no_struct_lit_at = l7;
            l5 = vader_parser_parse_block(l0);
            l6 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l3)->f_span)->f_start;
            l10 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_BlockExpr_t*) l5)->f_span)->f_end;
            vader_struct_toolchain_span_Span_t* _a3_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
            vader_obj_header_init(_a3_obj, 667u);
            _a3_obj->f_start = l6;
            _a3_obj->f_end = l10;
            l6 = (void*) _a3_obj;
            l11 = ((vader_struct_vader_lexer_Token_t*) l4)->f_text;
            l4 = ((vader_struct_vader_lexer_Token_t*) l4)->f_span;
            vader_struct_toolchain_ast_NamedVar_t* _a4_obj = (vader_struct_toolchain_ast_NamedVar_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_NamedVar_t));
            vader_obj_header_init(_a4_obj, 630u);
            _a4_obj->f_name = l11;
            _a4_obj->f_span = l4;
            t1 = (void*) _a4_obj;
            vader_struct_toolchain_ast_InFor_t* _a5_obj = (vader_struct_toolchain_ast_InFor_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_InFor_t));
            vader_obj_header_init(_a5_obj, 617u);
            _a5_obj->f_loop_var = vader_ref_box(t1);
            _a5_obj->f_iter = l9;
            l4 = (void*) _a5_obj;
            vader_struct_toolchain_ast_ForStmt_t* _a6_obj = (vader_struct_toolchain_ast_ForStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ForStmt_t));
            vader_obj_header_init(_a6_obj, 608u);
            _a6_obj->f_span = l6;
            _a6_obj->f_id = INT64_C(0);
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
        l9 = vader_parser_parse_let_binding(l0);
        vader_parser_expect(l0, (uint8_t) 21, 1341u);
        l12 = vader_parser_parse_expr(l0, INT32_C(0));
        ((vader_struct_vader_parser_Parser_t*) l0)->f_no_struct_lit_at = l7;
        l4 = vader_parser_parse_block(l0);
        l5 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l3)->f_span)->f_start;
        l6 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_BlockExpr_t*) l4)->f_span)->f_end;
        vader_struct_toolchain_span_Span_t* _a7_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
        vader_obj_header_init(_a7_obj, 667u);
        _a7_obj->f_start = l5;
        _a7_obj->f_end = l6;
        l5 = (void*) _a7_obj;
        vader_struct_toolchain_ast_DestructureVar_t* _a8_obj = (vader_struct_toolchain_ast_DestructureVar_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_DestructureVar_t));
        vader_obj_header_init(_a8_obj, 596u);
        _a8_obj->f_pattern = l9;
        t1 = (void*) _a8_obj;
        vader_struct_toolchain_ast_InFor_t* _a9_obj = (vader_struct_toolchain_ast_InFor_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_InFor_t));
        vader_obj_header_init(_a9_obj, 617u);
        _a9_obj->f_loop_var = vader_ref_box(t1);
        _a9_obj->f_iter = l12;
        l6 = (void*) _a9_obj;
        vader_struct_toolchain_ast_ForStmt_t* _a10_obj = (vader_struct_toolchain_ast_ForStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ForStmt_t));
        vader_obj_header_init(_a10_obj, 608u);
        _a10_obj->f_span = l5;
        _a10_obj->f_id = INT64_C(0);
        _a10_obj->f_label = l1;
        _a10_obj->f_form = vader_ref_box(l6);
        _a10_obj->f_body = l4;
        _a10_obj->f_is_comptime = l2;
        t1 = (void*) _a10_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l9 = vader_parser_parse_expr(l0, INT32_C(0));
    ((vader_struct_vader_parser_Parser_t*) l0)->f_no_struct_lit_at = l7;
    l4 = vader_parser_parse_block(l0);
    if (!(l9.tag == 638u)) {
        l10 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l3)->f_span)->f_start;
        l13 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_BlockExpr_t*) l4)->f_span)->f_end;
        vader_struct_toolchain_span_Span_t* _a11_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
        vader_obj_header_init(_a11_obj, 667u);
        _a11_obj->f_start = l10;
        _a11_obj->f_end = l13;
        l10 = (void*) _a11_obj;
        vader_struct_toolchain_ast_WhileFor_t* _a12_obj = (vader_struct_toolchain_ast_WhileFor_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_WhileFor_t));
        vader_obj_header_init(_a12_obj, 660u);
        _a12_obj->f_cond = l9;
        l13 = (void*) _a12_obj;
        vader_struct_toolchain_ast_ForStmt_t* _a13_obj = (vader_struct_toolchain_ast_ForStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ForStmt_t));
        vader_obj_header_init(_a13_obj, 608u);
        _a13_obj->f_span = l10;
        _a13_obj->f_id = INT64_C(0);
        _a13_obj->f_label = l1;
        _a13_obj->f_form = vader_ref_box(l13);
        _a13_obj->f_body = l4;
        _a13_obj->f_is_comptime = l2;
        t1 = (void*) _a13_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l3)->f_span)->f_start;
    l5 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_BlockExpr_t*) l4)->f_span)->f_end;
    vader_struct_toolchain_span_Span_t* _a14_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a14_obj, 667u);
    _a14_obj->f_start = l3;
    _a14_obj->f_end = l5;
    l3 = (void*) _a14_obj;
    vader_struct_toolchain_ast_DiscardVar_t* _a15_obj = (vader_struct_toolchain_ast_DiscardVar_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_DiscardVar_t));
    vader_obj_header_init(_a15_obj, 597u);
    l5 = (void*) _a15_obj;
    l6 = l9.payload.obj;
    vader_struct_toolchain_ast_InFor_t* _a16_obj = (vader_struct_toolchain_ast_InFor_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_InFor_t));
    vader_obj_header_init(_a16_obj, 617u);
    _a16_obj->f_loop_var = vader_ref_box(l5);
    _a16_obj->f_iter = vader_ref_box(l6);
    l5 = (void*) _a16_obj;
    vader_struct_toolchain_ast_ForStmt_t* _a17_obj = (vader_struct_toolchain_ast_ForStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ForStmt_t));
    vader_obj_header_init(_a17_obj, 608u);
    _a17_obj->f_span = l3;
    _a17_obj->f_id = INT64_C(0);
    _a17_obj->f_label = l1;
    _a17_obj->f_form = vader_ref_box(l5);
    _a17_obj->f_body = l4;
    _a17_obj->f_is_comptime = l2;
    t1 = (void*) _a17_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_parser_parse_generic_use(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    bool l6;
    bool t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[6] = { &l0, &l2, &l3, &l4, &l5, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_parser_advance(l0);
    l2 = vader_parser_parse_type_list_until_angle(l0);
    t0 = vader_parser_check(l0, (uint8_t) 80);
    if (t0) {
        vader_parser_advance(l0);
        l3 = vader_parser_parse_call_args(l0);
        l4 = vader_parser_expect(l0, (uint8_t) 81, 1236u);
        l5 = ((vader_struct_toolchain_span_Span_t*) VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, l1.payload.obj))->f_start;
        l4 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l4)->f_span)->f_end;
        vader_struct_toolchain_span_Span_t* _a0_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
        vader_obj_header_init(_a0_obj, 667u);
        _a0_obj->f_start = l5;
        _a0_obj->f_end = l4;
        l4 = (void*) _a0_obj;
        l5 = ((vader_struct_vader_parser_CommaList__toolchain_ast_CallArg_t*) l3)->f_items;
        l6 = ((vader_struct_vader_parser_CommaList__toolchain_ast_CallArg_t*) l3)->f_trailing_comma;
        vader_struct_toolchain_ast_CallExpr_t* _a1_obj = (vader_struct_toolchain_ast_CallExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_CallExpr_t));
        vader_obj_header_init(_a1_obj, 585u);
        _a1_obj->f_span = l4;
        _a1_obj->f_id = INT64_C(0);
        _a1_obj->f_callee = l1;
        _a1_obj->f_type_args = l2;
        _a1_obj->f_args = l5;
        _a1_obj->f_trailing_comma = l6;
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((vader_struct_toolchain_span_Span_t*) VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, l1.payload.obj))->f_start;
    t1 = vader_parser_peek_at(l0, INT32_C(-1));
    l4 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) t1)->f_span)->f_end;
    vader_struct_toolchain_span_Span_t* _a2_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a2_obj, 667u);
    _a2_obj->f_start = l3;
    _a2_obj->f_end = l4;
    t1 = (void*) _a2_obj;
    vader_struct_toolchain_ast_GenericInstExpr_t* _a3_obj = (vader_struct_toolchain_ast_GenericInstExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_GenericInstExpr_t));
    vader_obj_header_init(_a3_obj, 609u);
    _a3_obj->f_span = t1;
    _a3_obj->f_id = INT64_C(0);
    _a3_obj->f_callee = l1;
    _a3_obj->f_type_args = l2;
    l2 = (void*) _a3_obj;
    t0 = vader_parser_allows_struct_lit(l0);
    if (t0) {
        t0 = vader_parser_check(l0, (uint8_t) 84);
        if (t0) {
            vader_parser_advance(l0);
            l3 = vader_parser_parse_struct_lit_fields(l0);
            l4 = vader_parser_expect(l0, (uint8_t) 85, 1363u);
            l5 = ((vader_struct_toolchain_span_Span_t*) VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, l1.payload.obj))->f_start;
            l4 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l4)->f_span)->f_end;
            vader_struct_toolchain_span_Span_t* _a4_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
            vader_obj_header_init(_a4_obj, 667u);
            _a4_obj->f_start = l5;
            _a4_obj->f_end = l4;
            l4 = (void*) _a4_obj;
            l5 = ((vader_struct_vader_parser_CommaList__toolchain_ast_StructLitField___toolchain_ast_StructLitSpread_t*) l3)->f_items;
            l6 = ((vader_struct_vader_parser_CommaList__toolchain_ast_StructLitField___toolchain_ast_StructLitSpread_t*) l3)->f_trailing_comma;
            vader_struct_toolchain_ast_StructLitExpr_t* _a5_obj = (vader_struct_toolchain_ast_StructLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_StructLitExpr_t));
            vader_obj_header_init(_a5_obj, 650u);
            _a5_obj->f_span = l4;
            _a5_obj->f_id = INT64_C(0);
            _a5_obj->f_type_name = vader_ref_box(l2);
            _a5_obj->f_items = l5;
            _a5_obj->f_trailing_comma = l6;
            t1 = (void*) _a5_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_box_t __vret = vader_ref_box(l2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = vader_ref_box(l2); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_parser_parse_ident_or_struct_lit(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    int32_t l2;
    vader_string_t l4 = 0;
    bool l8;
    bool t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[7] = { &l0, &l1, &l3, &l5, &l6, &l7, &t2 };
    vader_string_t* gc_atom_roots[1] = { &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_advance(l0);
    l2 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pos;
    t0 = vader_parser_scan_angle_generic(l0, l2);
    if (t0) {
        l3 = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
        l4 = ((vader_struct_vader_lexer_Token_t*) l1)->f_text;
        l3 = vader_parser_ident_expr(l3, l4);
        t1 = vader_parser_parse_generic_use(l0, vader_ref_box(l3));
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_parser_allows_struct_lit(l0);
    if (t0) {
        t0 = vader_parser_check(l0, (uint8_t) 84);
        if (t0) {
            l3 = ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens;
            l2 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pos;
            t0 = vader_parser_looks_like_struct_lit_body(l3, l2);
            if (t0) {
                vader_parser_advance(l0);
                l3 = vader_parser_parse_struct_lit_fields(l0);
                l5 = vader_parser_expect(l0, (uint8_t) 85, 1363u);
                l5 = vader_parser_span_of(l0, l1, l5);
                l6 = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
                l4 = ((vader_struct_vader_lexer_Token_t*) l1)->f_text;
                l6 = vader_parser_ident_expr(l6, l4);
                l7 = ((vader_struct_vader_parser_CommaList__toolchain_ast_StructLitField___toolchain_ast_StructLitSpread_t*) l3)->f_items;
                l8 = ((vader_struct_vader_parser_CommaList__toolchain_ast_StructLitField___toolchain_ast_StructLitSpread_t*) l3)->f_trailing_comma;
                vader_struct_toolchain_ast_StructLitExpr_t* _a0_obj = (vader_struct_toolchain_ast_StructLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_StructLitExpr_t));
                vader_obj_header_init(_a0_obj, 650u);
                _a0_obj->f_span = l5;
                _a0_obj->f_id = INT64_C(0);
                _a0_obj->f_type_name = vader_ref_box(l6);
                _a0_obj->f_items = l7;
                _a0_obj->f_trailing_comma = l8;
                t2 = (void*) _a0_obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
    }
    l3 = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
    l4 = ((vader_struct_vader_lexer_Token_t*) l1)->f_text;
    t2 = vader_parser_ident_expr(l3, l4);
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_if_expr(void* l0) {
    void* l1 = NULL;
    void* l5 = NULL;
    void* l7 = NULL;
    int32_t l2, l3;
    vader_box_t l4 = vader_box_null(), l6 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    bool t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[3] = { &l4, &l6, &t0 };
    void** gc_raw_roots[5] = { &l0, &l1, &l5, &l7, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_advance(l0);
    l2 = ((vader_struct_vader_parser_Parser_t*) l0)->f_no_struct_lit_at;
    l3 = ((vader_struct_vader_parser_Parser_t*) l0)->f_bracket_depth;
    ((vader_struct_vader_parser_Parser_t*) l0)->f_no_struct_lit_at = l3;
    l4 = vader_parser_parse_expr(l0, INT32_C(0));
    ((vader_struct_vader_parser_Parser_t*) l0)->f_no_struct_lit_at = l2;
    l5 = vader_parser_parse_block(l0);
    l6 = vader_box_obj(0u, NULL);
    vader_parser_skip_newlines(l0);
    t0 = vader_parser_match_kind(l0, (uint8_t) 17);
    if (!(t0.tag == 0u)) {
        vader_parser_skip_newlines(l0);
        t1 = vader_parser_check(l0, (uint8_t) 16);
        if (t1) {
            t2 = vader_parser_parse_if_expr(l0);
            vader_struct_toolchain_ast_IfElseIf_t* _a0_obj = (vader_struct_toolchain_ast_IfElseIf_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_IfElseIf_t));
            vader_obj_header_init(_a0_obj, 612u);
            _a0_obj->f_branch = t2;
            t2 = (void*) _a0_obj;
            l6 = vader_ref_box(t2);
        } else {
            t2 = vader_parser_parse_block(l0);
            vader_struct_toolchain_ast_IfElseBlock_t* _a1_obj = (vader_struct_toolchain_ast_IfElseBlock_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_IfElseBlock_t));
            vader_obj_header_init(_a1_obj, 611u);
            _a1_obj->f_block = t2;
            t2 = (void*) _a1_obj;
            l6 = vader_ref_box(t2);
        }
    }
    if (l6.tag == 612u) {
        t2 = l6.payload.obj;
        l7 = ((vader_struct_toolchain_ast_IfExpr_t*) ((vader_struct_toolchain_ast_IfElseIf_t*) t2)->f_branch)->f_span;
    } else if (l6.tag == 611u) {
        t2 = l6.payload.obj;
        l7 = ((vader_struct_toolchain_ast_BlockExpr_t*) ((vader_struct_toolchain_ast_IfElseBlock_t*) t2)->f_block)->f_span;
    } else {
        if (!(l6.tag == 0u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l7 = ((vader_struct_toolchain_ast_BlockExpr_t*) l5)->f_span;
    }
    l1 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l1)->f_span)->f_start;
    l7 = ((vader_struct_toolchain_span_Span_t*) l7)->f_end;
    vader_struct_toolchain_span_Span_t* _a2_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a2_obj, 667u);
    _a2_obj->f_start = l1;
    _a2_obj->f_end = l7;
    t2 = (void*) _a2_obj;
    vader_struct_toolchain_ast_IfExpr_t* _a3_obj = (vader_struct_toolchain_ast_IfExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_IfExpr_t));
    vader_obj_header_init(_a3_obj, 613u);
    _a3_obj->f_span = t2;
    _a3_obj->f_id = INT64_C(0);
    _a3_obj->f_cond = l4;
    _a3_obj->f_then_block = l5;
    _a3_obj->f_else_branch = l6;
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
    void* l15 = NULL;
    vader_box_t l3 = vader_box_null(), l14 = vader_box_null();
    bool l7, l13;
    int64_t l9, l10;
    vader_string_t l16 = 0;
    bool t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[3] = { &l3, &l14, &t1 };
    void** gc_raw_roots[11] = { &l0, &l1, &l2, &l4, &l5, &l6, &l8, &l11, &l12, &l15, &t2 };
    vader_string_t* gc_atom_roots[2] = { &l16, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 11u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_parser_reject_free_fn_decorators(l0, l1, 1462u, 0u);
    l2 = vader_parser_peek(l0);
    l3 = vader_parser_parse_type(l0);
    vader_parser_expect(l0, (uint8_t) 14, 1338u);
    vader_array_t* _a0_arr = vader_array_new(54u, 0u, 13u, 658u);
    l4 = (void*) _a0_arr;
    t0 = vader_parser_check(l0, (uint8_t) 52);
    if (t0) {
        l4 = vader_parser_parse_angle_type_params(l0);
    }
    l5 = vader_parser_expect(l0, (uint8_t) 2, 2634u);
    vader_array_t* _a1_arr = vader_array_new(227u, 0u, 13u, 1503u);
    l6 = (void*) _a1_arr;
    t1 = vader_parser_match_kind(l0, (uint8_t) 52);
    if (!(t1.tag == 0u)) {
        l6 = vader_parser_parse_type_list_until_angle(l0);
    }
    l7 = false;
    l8 = l1;
    l9 = ((vader_array_t*) l8)->length;
    l10 = INT64_C(0);
    while ((l10 < l9)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t2 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l10);
        t3 = ((vader_struct_toolchain_ast_Decorator_t*) t2)->f_name;
        if (t3 == 2102u) {
            l7 = true;
        }
        l10 = (l10 + INT64_C(1));
    }
    vader_array_t* _a3_arr = vader_array_new(42u, 0u, 13u, 605u);
    l8 = (void*) _a3_arr;
    l11 = l5;
    t0 = vader_parser_check(l0, (uint8_t) 76);
    if (t0) {
        l12 = vader_parser_parse_sam_arrow_member(l0);
        vader_array_push_ref((vader_array_t*) l8, l12);
        l11 = vader_parser_peek_at(l0, INT32_C(-1));
    } else {
        t0 = vader_parser_check(l0, (uint8_t) 84);
        if (t0) {
            l13 = vader_parser_peek_is_classic_impl_body(l0);
        } else {
            l13 = false;
        }
        if (l13) {
            vader_parser_advance(l0);
            vader_parser_skip_newlines(l0);
            for (;;) {
                t0 = vader_parser_check(l0, (uint8_t) 85);
                if (!(t0)) {
                    t0 = vader_parser_check(l0, (uint8_t) 0);
                    if (t0) break;
                    l14 = vader_parser_parse_fn_decl_inside_trait(l0);
                    if (l14.tag == 605u) {
                        t2 = l14.payload.obj;
                        l12 = ((vader_struct_toolchain_ast_FnDecl_t*) t2)->f_decorators;
                        vader_parser_reject_free_fn_decorators(l0, l12, 1471u, 0u);
                        l15 = l14.payload.obj;
                        vader_array_push_ref((vader_array_t*) l8, l15);
                    } else if (!(l14.tag == 0u)) {
                        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                    }
                    vader_parser_skip_newlines(l0);
                    continue;
                }
                break;
            }
            l11 = vader_parser_expect(l0, (uint8_t) 85, 1359u);
        } else {
            t0 = vader_parser_check(l0, (uint8_t) 84);
            if (t0) {
                l12 = vader_parser_parse_sam_block_member(l0);
                vader_array_push_ref((vader_array_t*) l8, l12);
                l11 = vader_parser_peek_at(l0, INT32_C(-1));
            } else if (l7) {
                l11 = vader_parser_peek_at(l0, INT32_C(-1));
            } else {
                l12 = vader_parser_peek(l0);
                l15 = ((vader_struct_vader_lexer_Token_t*) l12)->f_span;
                l16 = vader_parser_describe_token(l12);
                l16 = concat_3(1831u, l16, 289u);
                vader_parser_error(l0, (uint8_t) 4, l15, l16);
                l11 = l12;
            }
        }
    }
    l2 = vader_parser_span_of(l0, l2, l11);
    l16 = ((vader_struct_vader_lexer_Token_t*) l5)->f_text;
    l5 = ((vader_struct_vader_lexer_Token_t*) l5)->f_span;
    vader_struct_toolchain_ast_ImplDecl_t* _a4_obj = (vader_struct_toolchain_ast_ImplDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ImplDecl_t));
    vader_obj_header_init(_a4_obj, 614u);
    _a4_obj->f_span = l2;
    _a4_obj->f_id = INT64_C(0);
    _a4_obj->f_type_params = l4;
    _a4_obj->f_for_type = l3;
    _a4_obj->f_trait_name = l16;
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
    void* l5 = NULL;
    void* l7 = NULL;
    vader_string_t l6 = 0;
    bool l8;
    bool t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l4, &l5, &l7, &t2 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_parser_advance(l0);
    l3 = vader_parser_expect_string_literal(l0, 2053u);
    t0 = vader_parser_check(l0, (uint8_t) 29);
    if (t0) {
        l4 = vader_parser_peek(l0);
        l4 = ((vader_struct_vader_lexer_Token_t*) l4)->f_span;
        vader_parser_error(l0, (uint8_t) 4, l4, 2603u);
        vader_parser_advance(l0);
        t0 = vader_parser_check(l0, (uint8_t) 2);
        if (t0) {
            vader_parser_advance(l0);
        }
    }
    t1 = vader_parser_match_kind(l0, (uint8_t) 84);
    if (!(t1.tag == 0u)) {
        l4 = vader_parser_parse_import_name_list_rest(l0);
        l5 = vader_parser_peek_at(l0, INT32_C(-1));
        l5 = vader_parser_span_of(l0, l2, l5);
        l6 = ((vader_struct_vader_parser_StringLitInfo_t*) l3)->f_text;
        l7 = ((vader_struct_vader_parser_CommaList__toolchain_ast_ImportName_t*) l4)->f_items;
        l8 = ((vader_struct_vader_parser_CommaList__toolchain_ast_ImportName_t*) l4)->f_trailing_comma;
        vader_struct_toolchain_ast_DestructureImport_t* _a0_obj = (vader_struct_toolchain_ast_DestructureImport_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_DestructureImport_t));
        vader_obj_header_init(_a0_obj, 595u);
        _a0_obj->f_names = l7;
        _a0_obj->f_trailing_comma = l8;
        l4 = (void*) _a0_obj;
        vader_struct_toolchain_ast_ImportDecl_t* _a1_obj = (vader_struct_toolchain_ast_ImportDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ImportDecl_t));
        vader_obj_header_init(_a1_obj, 615u);
        _a1_obj->f_span = l5;
        _a1_obj->f_id = INT64_C(0);
        _a1_obj->f_path = l6;
        _a1_obj->f_binding = vader_ref_box(l4);
        _a1_obj->f_decorators = l1;
        t2 = (void*) _a1_obj;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = vader_parser_peek_at(l0, INT32_C(-1));
    l2 = vader_parser_span_of(l0, l2, l4);
    l6 = ((vader_struct_vader_parser_StringLitInfo_t*) l3)->f_text;
    vader_struct_toolchain_ast_WildcardImport_t* _a2_obj = (vader_struct_toolchain_ast_WildcardImport_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_WildcardImport_t));
    vader_obj_header_init(_a2_obj, 662u);
    l3 = (void*) _a2_obj;
    vader_struct_toolchain_ast_ImportDecl_t* _a3_obj = (vader_struct_toolchain_ast_ImportDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ImportDecl_t));
    vader_obj_header_init(_a3_obj, 615u);
    _a3_obj->f_span = l2;
    _a3_obj->f_id = INT64_C(0);
    _a3_obj->f_path = l6;
    _a3_obj->f_binding = vader_ref_box(l3);
    _a3_obj->f_decorators = l1;
    t2 = (void*) _a3_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_import_name_list_rest(void* l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    bool l2, l3;
    vader_box_t l5 = vader_box_null();
    vader_string_t l6 = 0;
    bool t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[2] = { &l5, &t1 };
    void** gc_raw_roots[7] = { &l0, &l1, &l4, &l7, &l8, &l9, &t2 };
    vader_string_t* gc_atom_roots[2] = { &l6, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(44u, 0u, 13u, 616u);
    l1 = (void*) _a0_arr;
    l2 = false;
    vader_parser_skip_newlines(l0);
    t0 = vader_parser_check(l0, (uint8_t) 85);
    if (!(t0)) {
        l3 = true;
        for (;;) {
            if (!(l3)) {
                t1 = vader_parser_match_kind(l0, (uint8_t) 86);
                if (t1.tag == 0u) break;
            }
            l3 = false;
            vader_parser_skip_newlines(l0);
            t0 = vader_parser_check(l0, (uint8_t) 85);
            if (t0) {
                l2 = true;
                break;
            }
            l4 = vader_parser_expect(l0, (uint8_t) 2, 2056u);
            l5 = vader_box_obj(0u, NULL);
            t1 = vader_parser_match_kind(l0, (uint8_t) 29);
            if (!(t1.tag == 0u)) {
                t2 = vader_parser_expect(l0, (uint8_t) 2, 1455u);
                t3 = ((vader_struct_vader_lexer_Token_t*) t2)->f_text;
                l5 = vader_box_string(317u, t3);
            }
            l6 = ((vader_struct_vader_lexer_Token_t*) l4)->f_text;
            l7 = vader_parser_peek_at(l0, INT32_C(-1));
            l8 = vader_parser_span_of(l0, l4, l7);
            vader_struct_toolchain_ast_ImportName_t* _a1_obj = (vader_struct_toolchain_ast_ImportName_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ImportName_t));
            vader_obj_header_init(_a1_obj, 616u);
            _a1_obj->f_name = l6;
            _a1_obj->f_alias = l5;
            _a1_obj->f_span = l8;
            _a1_obj->f_id = INT64_C(0);
            l9 = (void*) _a1_obj;
            vader_array_push_ref((vader_array_t*) l1, l9);
            vader_parser_skip_newlines(l0);
            continue;
        }
    }
    vader_parser_skip_newlines(l0);
    vader_parser_expect(l0, (uint8_t) 85, 1360u);
    vader_struct_vader_parser_CommaList__Any_t* _a2_obj = (vader_struct_vader_parser_CommaList__Any_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_CommaList__Any_t));
    vader_obj_header_init(_a2_obj, 1192u);
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
    t0 = vader_parser_match_kind(l0, (uint8_t) 76);
    if (!(t0.tag == 0u)) {
        l3 = vader_parser_parse_type(l0);
    }
    l4 = vader_parser_parse_block(l0);
    l1 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l1)->f_span)->f_start;
    l5 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_BlockExpr_t*) l4)->f_span)->f_end;
    vader_struct_toolchain_span_Span_t* _a0_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a0_obj, 667u);
    _a0_obj->f_start = l1;
    _a0_obj->f_end = l5;
    l1 = (void*) _a0_obj;
    l5 = ((vader_struct_vader_parser_FnSignature_t*) l2)->f_params;
    l6 = ((vader_struct_vader_parser_FnSignature_t*) l2)->f_trailing_comma;
    vader_struct_toolchain_ast_LambdaExpr_t* _a1_obj = (vader_struct_toolchain_ast_LambdaExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_LambdaExpr_t));
    vader_obj_header_init(_a1_obj, 623u);
    _a1_obj->f_span = l1;
    _a1_obj->f_id = INT64_C(0);
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
    vader_parser_expect(l0, (uint8_t) 76, 1256u);
    t0 = vader_parser_parse_expr(l0, INT32_C(0));
    l3 = vader_parser_wrap_as_block(t0);
    l1 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l1)->f_span)->f_start;
    l4 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_BlockExpr_t*) l3)->f_span)->f_end;
    vader_struct_toolchain_span_Span_t* _a0_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a0_obj, 667u);
    _a0_obj->f_start = l1;
    _a0_obj->f_end = l4;
    l1 = (void*) _a0_obj;
    l4 = ((vader_struct_vader_parser_FnSignature_t*) l2)->f_params;
    l5 = ((vader_struct_vader_parser_FnSignature_t*) l2)->f_trailing_comma;
    vader_struct_toolchain_ast_LambdaExpr_t* _a1_obj = (vader_struct_toolchain_ast_LambdaExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_LambdaExpr_t));
    vader_obj_header_init(_a1_obj, 623u);
    _a1_obj->f_span = l1;
    _a1_obj->f_id = INT64_C(0);
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
    l2 = ((vader_struct_vader_lexer_Token_t*) t0)->f_kind == INT32_C(72);
    l3 = vader_parser_parse_expr(l0, INT32_C(0));
    l4 = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
    l5 = ((vader_struct_vader_lexer_Token_t*) l1)->f_text;
    l6 = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
    vader_struct_toolchain_ast_SimpleBinding_t* _a0_obj = (vader_struct_toolchain_ast_SimpleBinding_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_SimpleBinding_t));
    vader_obj_header_init(_a0_obj, 644u);
    _a0_obj->f_span = l4;
    _a0_obj->f_id = INT64_C(0);
    _a0_obj->f_name = l5;
    _a0_obj->f_name_span = l6;
    l4 = (void*) _a0_obj;
    l6 = vader_parser_peek_at(l0, INT32_C(-1));
    t0 = vader_parser_span_of(l0, l1, l6);
    vader_struct_toolchain_ast_LetStmt_t* _a1_obj = (vader_struct_toolchain_ast_LetStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_LetStmt_t));
    vader_obj_header_init(_a1_obj, 624u);
    _a1_obj->f_span = t0;
    _a1_obj->f_id = INT64_C(0);
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
    int64_t l10, l11, l12;
    bool t0;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    void* t3 = NULL;
    vader_string_t t4 = 0;
    vader_box_t* gc_roots[2] = { &l9, &t1 };
    void** gc_raw_roots[9] = { &l0, &l1, &l2, &l3, &l4, &l5, &l7, &l8, &t3 };
    vader_string_t* gc_atom_roots[2] = { &l6, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_parser_check(l0, (uint8_t) 82);
    if (t0) {
        l1 = vader_parser_advance(l0);
        vader_parser_skip_newlines(l0);
        vader_array_t* _a0_arr = vader_array_new(233u, 0u, 13u, 1580u);
        l2 = (void*) _a0_arr;
        t0 = vader_parser_check(l0, (uint8_t) 83);
        if (!(t0)) {
            for (;;) {
                vader_parser_skip_newlines(l0);
                t0 = vader_parser_check(l0, (uint8_t) 83);
                if (!(t0)) {
                    l3 = vader_parser_peek(l0);
                    t1 = vader_parser_match_kind(l0, (uint8_t) 75);
                    if (t1.tag == 0u) {
                        l9 = vader_parser_parse_let_binding(l0);
                        vader_array_push_ref((vader_array_t*) l2, l9.payload.obj);
                    } else {
                        l4 = vader_parser_expect(l0, (uint8_t) 2, 2277u);
                        l5 = vader_parser_span_of(l0, l3, l4);
                        l6 = ((vader_struct_vader_lexer_Token_t*) l4)->f_text;
                        l7 = ((vader_struct_vader_lexer_Token_t*) l4)->f_span;
                        vader_struct_toolchain_ast_RestBinding_t* _a1_obj = (vader_struct_toolchain_ast_RestBinding_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_RestBinding_t));
                        vader_obj_header_init(_a1_obj, 640u);
                        _a1_obj->f_span = l5;
                        _a1_obj->f_id = INT64_C(0);
                        _a1_obj->f_name = l6;
                        _a1_obj->f_name_span = l7;
                        l8 = (void*) _a1_obj;
                        vader_array_push_ref((vader_array_t*) l2, l8);
                    }
                    vader_parser_skip_newlines(l0);
                    t1 = vader_parser_match_kind(l0, (uint8_t) 86);
                    if (t1.tag == 0u) break;
                    vader_parser_skip_newlines(l0);
                    continue;
                }
                break;
            }
        }
        l3 = vader_parser_expect(l0, (uint8_t) 83, 1323u);
        t2 = ((vader_array_t*) l2)->length;
        if ((t2 < INT64_C(2))) {
            l4 = vader_parser_span_of(l0, l1, l3);
            vader_parser_error(l0, (uint8_t) 14, l4, 1394u);
        }
        l10 = INT64_C(1);
        l11 = ((vader_array_t*) l2)->length;
        while ((l10 < l11)) {
            l12 = vader_chk_sub(i64, l10, INT64_C(1));
            vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            l9 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l12);
            if (l9.tag == 640u) {
                t3 = l9.payload.obj;
                l4 = ((vader_struct_toolchain_ast_RestBinding_t*) t3)->f_span;
                vader_parser_error(l0, (uint8_t) 23, l4, 0u);
            }
            l10 = (l10 + INT64_C(1));
        }
        t3 = vader_parser_span_of(l0, l1, l3);
        vader_struct_toolchain_ast_TupleBinding_t* _a3_obj = (vader_struct_toolchain_ast_TupleBinding_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_TupleBinding_t));
        vader_obj_header_init(_a3_obj, 656u);
        _a3_obj->f_span = t3;
        _a3_obj->f_id = INT64_C(0);
        _a3_obj->f_elements = l2;
        t3 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_parser_check(l0, (uint8_t) 2);
    if (t0) {
        t3 = vader_parser_peek(l0);
        t4 = ((vader_struct_vader_lexer_Token_t*) t3)->f_text;
        if (t4 == 928u) {
            t3 = vader_parser_advance(l0);
            vader_struct_toolchain_ast_WildcardBinding_t* _a4_obj = (vader_struct_toolchain_ast_WildcardBinding_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_WildcardBinding_t));
            vader_obj_header_init(_a4_obj, 661u);
            _a4_obj->f_span = ((vader_struct_vader_lexer_Token_t*) t3)->f_span;
            _a4_obj->f_id = INT64_C(0);
            t3 = (void*) _a4_obj;
            { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l1 = vader_parser_expect(l0, (uint8_t) 2, 1557u);
    l2 = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
    l6 = ((vader_struct_vader_lexer_Token_t*) l1)->f_text;
    l1 = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
    vader_struct_toolchain_ast_SimpleBinding_t* _a5_obj = (vader_struct_toolchain_ast_SimpleBinding_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_SimpleBinding_t));
    vader_obj_header_init(_a5_obj, 644u);
    _a5_obj->f_span = l2;
    _a5_obj->f_id = INT64_C(0);
    _a5_obj->f_name = l6;
    _a5_obj->f_name_span = l1;
    t3 = (void*) _a5_obj;
    { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_lhs_generic_alias_decl(void* l0, void* l1, uint8_t l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l6 = NULL;
    vader_box_t l5 = vader_box_null();
    vader_string_t l7 = 0;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[6] = { &l0, &l1, &l3, &l4, &l6, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_parser_advance(l0);
    l4 = vader_parser_parse_angle_type_params(l0);
    vader_parser_advance(l0);
    l5 = vader_parser_parse_expr(l0, INT32_C(0));
    l6 = vader_parser_peek_at(l0, INT32_C(-1));
    l6 = vader_parser_span_of(l0, l3, l6);
    l7 = ((vader_struct_vader_lexer_Token_t*) l3)->f_text;
    l3 = ((vader_struct_vader_lexer_Token_t*) l3)->f_span;
    vader_struct_toolchain_ast_TypeAliasDecl_t* _a0_obj = (vader_struct_toolchain_ast_TypeAliasDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_TypeAliasDecl_t));
    vader_obj_header_init(_a0_obj, 657u);
    _a0_obj->f_span = l6;
    _a0_obj->f_id = INT64_C(0);
    _a0_obj->f_name = l7;
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
    void* l5 = NULL;
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l10 = vader_box_null();
    int64_t l6, l7;
    int32_t l8, l9;
    bool t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[4] = { &l2, &l3, &l10, &t1 };
    void** gc_raw_roots[5] = { &l0, &l1, &l4, &l5, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_peek(l0);
    l2 = vader_parser_parse_pattern(l0);
    l3 = l2;
    t0 = vader_parser_check(l0, (uint8_t) 45);
    if (t0) {
        vader_array_t* _a0_arr = vader_array_new(231u, 1u, 13u, 1559u);
        ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l2.payload.obj;
        l4 = (void*) _a0_arr;
        for (;;) {
            t1 = vader_parser_match_kind(l0, (uint8_t) 45);
            if (!(t1.tag == 0u)) {
                vader_parser_skip_newlines(l0);
                l2 = vader_parser_parse_pattern(l0);
                vader_array_push_ref((vader_array_t*) l4, l2.payload.obj);
                continue;
            }
            break;
        }
        l5 = l4;
        l6 = ((vader_array_t*) l5)->length;
        l7 = INT64_C(0);
        while ((l7 < l6)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            l2 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l7);
            vader_parser_reject_alternative_bindings(l0, l2);
            l7 = (l7 + INT64_C(1));
        }
        l5 = vader_parser_peek_at(l0, INT32_C(-1));
        t2 = vader_parser_span_of(l0, l1, l5);
        vader_struct_toolchain_ast_OrPattern_t* _a2_obj = (vader_struct_toolchain_ast_OrPattern_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_OrPattern_t));
        vader_obj_header_init(_a2_obj, 633u);
        _a2_obj->f_span = t2;
        _a2_obj->f_id = INT64_C(0);
        _a2_obj->f_patterns = l4;
        t2 = (void*) _a2_obj;
        l3 = vader_ref_box(t2);
    }
    l2 = vader_box_obj(0u, NULL);
    t1 = vader_parser_match_kind(l0, (uint8_t) 16);
    if (!(t1.tag == 0u)) {
        l8 = ((vader_struct_vader_parser_Parser_t*) l0)->f_no_bare_lambda_at;
        l9 = ((vader_struct_vader_parser_Parser_t*) l0)->f_bracket_depth;
        ((vader_struct_vader_parser_Parser_t*) l0)->f_no_bare_lambda_at = l9;
        l2 = vader_parser_parse_expr(l0, INT32_C(0));
        ((vader_struct_vader_parser_Parser_t*) l0)->f_no_bare_lambda_at = l8;
    }
    vader_parser_expect(l0, (uint8_t) 76, 1257u);
    l10 = vader_parser_parse_expr(l0, INT32_C(0));
    l1 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l1)->f_span)->f_start;
    l4 = ((vader_struct_toolchain_span_Span_t*) VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, l10.payload.obj))->f_end;
    vader_struct_toolchain_span_Span_t* _a3_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a3_obj, 667u);
    _a3_obj->f_start = l1;
    _a3_obj->f_end = l4;
    t2 = (void*) _a3_obj;
    vader_struct_toolchain_ast_MatchArm_t* _a4_obj = (vader_struct_toolchain_ast_MatchArm_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_MatchArm_t));
    vader_obj_header_init(_a4_obj, 626u);
    _a4_obj->f_span = t2;
    _a4_obj->f_id = INT64_C(0);
    _a4_obj->f_pattern = l3;
    _a4_obj->f_guard = l2;
    _a4_obj->f_body = l10;
    t2 = (void*) _a4_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_parser_parse_match_declaration(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    void* l5 = NULL;
    vader_box_t l2 = vader_box_null();
    vader_string_t l4 = 0;
    bool t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[5] = { &l0, &l1, &l3, &l5, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_parser_starts_let(l0);
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l1 = vader_parser_parse_any_let(l0);
    l2 = ((vader_struct_toolchain_ast_LetStmt_t*) l1)->f_binding;
    if (l2.tag == 644u) {
        t0 = ((vader_struct_toolchain_ast_LetStmt_t*) l1)->f_mutable;
        if (t0) {
            l3 = ((vader_struct_toolchain_ast_LetStmt_t*) l1)->f_span;
            t1 = l2.payload.obj;
            l4 = ((vader_struct_toolchain_ast_SimpleBinding_t*) t1)->f_name;
            l4 = concat_3(2931u, l4, 49u);
            vader_parser_error(l0, (uint8_t) 24, l3, l4);
        } else if (!(((vader_struct_toolchain_ast_LetStmt_t*) l1)->f_ty.tag == 0u)) {
            l5 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, ((vader_struct_toolchain_ast_LetStmt_t*) l1)->f_ty.payload.obj);
            t1 = l2.payload.obj;
            l4 = ((vader_struct_toolchain_ast_SimpleBinding_t*) t1)->f_name;
            l4 = concat_3(1772u, l4, 49u);
            vader_parser_error(l0, (uint8_t) 24, l5, l4);
        }
        { vader_box_t __vret = vader_ref_box(l1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((vader_struct_toolchain_ast_LetStmt_t*) l1)->f_span;
    vader_parser_error(l0, (uint8_t) 24, l3, 1553u);
    { vader_box_t __vret = vader_ref_box(l1); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_match_expr(void* l0, bool l1, bool l2, void* l3) {
    int32_t l4, l5;
    vader_box_t l6 = vader_box_null(), l7 = vader_box_null();
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    bool t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[3] = { &l6, &l7, &t1 };
    void** gc_raw_roots[6] = { &l0, &l3, &l8, &l9, &l10, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_parser_advance(l0);
    l4 = ((vader_struct_vader_parser_Parser_t*) l0)->f_no_struct_lit_at;
    l5 = ((vader_struct_vader_parser_Parser_t*) l0)->f_bracket_depth;
    ((vader_struct_vader_parser_Parser_t*) l0)->f_no_struct_lit_at = l5;
    l6 = vader_parser_parse_match_declaration(l0);
    l7 = vader_parser_match_scrutinee(l0, l6);
    ((vader_struct_vader_parser_Parser_t*) l0)->f_no_struct_lit_at = l4;
    l8 = (void*) &vader_fn_static___lambda_vader_parser_4;
    vader_parser_reject_as_binder(l0, (uint8_t) 24, l8);
    vader_parser_expect(l0, (uint8_t) 84, 1353u);
    vader_parser_skip_newlines(l0);
    vader_array_t* _a0_arr = vader_array_new(47u, 0u, 13u, 626u);
    l8 = (void*) _a0_arr;
    for (;;) {
        t0 = vader_parser_check(l0, (uint8_t) 85);
        if (!(t0)) {
            t0 = vader_parser_check(l0, (uint8_t) 0);
            if (t0) break;
            l9 = vader_parser_parse_match_arm(l0);
            vader_array_push_ref((vader_array_t*) l8, l9);
            vader_parser_skip_newlines(l0);
            t1 = vader_parser_match_kind(l0, (uint8_t) 86);
            if (t1.tag == 0u) {
                continue;
            }
            vader_parser_skip_newlines(l0);
            continue;
        }
        break;
    }
    l9 = vader_parser_expect(l0, (uint8_t) 85, 1361u);
    l10 = ((vader_struct_toolchain_span_Span_t*) l3)->f_start;
    l9 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l9)->f_span)->f_end;
    vader_struct_toolchain_span_Span_t* _a1_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a1_obj, 667u);
    _a1_obj->f_start = l10;
    _a1_obj->f_end = l9;
    l9 = (void*) _a1_obj;
    l6 = vader_parser_declared_binding(l6);
    vader_struct_toolchain_ast_MatchExpr_t* _a2_obj = (vader_struct_toolchain_ast_MatchExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_MatchExpr_t));
    vader_obj_header_init(_a2_obj, 627u);
    _a2_obj->f_span = l9;
    _a2_obj->f_id = INT64_C(0);
    _a2_obj->f_scrutinee = l7;
    _a2_obj->f_arms = l8;
    _a2_obj->f_partial = l1;
    _a2_obj->f_unreachable = l2;
    _a2_obj->f_binding = l6;
    t2 = (void*) _a2_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_parser_parse_module_header(vader_string_t l0, vader_string_t l1) {
    int64_t l2, l3, l4, l9;
    uint8_t l5;
    bool l6, l7, l8;
    vader_string_t l10 = 0;
    void* l11 = NULL;
    bool t0;
    uint8_t t1;
    void* t2 = NULL;
    void** gc_raw_roots[2] = { &l11, &t2 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l1, &l10 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_host_std_core_byte_len(l0);
    l3 = INT64_C(0);
    t0 = std_string_matches_at(l0, INT64_C(0), 2967u);
    if (t0) {
        l3 = INT64_C(3);
    }
    t0 = std_string_matches_at(l0, l3, 227u);
    if (t0) {
        l3 = vader_parser_skip_to_eol(l0, l3);
    }
    l4 = vader_parser_header_budget(l2);
    while ((l3 < l4)) {
        l5 = vader_host_std_core_byte_at(l0, l3);
        if (l5 == INT32_C(32)) {
            l6 = true;
        } else {
            l6 = l5 == INT32_C(9);
        }
        if (l6) {
            l7 = true;
        } else {
            l7 = l5 == INT32_C(10);
        }
        if (l7) {
            l8 = true;
        } else {
            l8 = l5 == INT32_C(13);
        }
        if (l8) {
            l3 = vader_chk_add(i64, l3, INT64_C(1));
            continue;
        }
        t0 = std_string_matches_at(l0, l3, 400u);
        if (t0) {
            l3 = vader_parser_skip_to_eol(l0, l3);
            continue;
        }
        t0 = std_string_matches_at(l0, l3, 398u);
        if (!(t0)) {
            break;
        }
        l9 = vader_chk_add(i64, l3, INT64_C(2));
        l3 = vader_parser_skip_block_comment(l0, l9);
    }
    t0 = std_string_matches_at(l0, l3, 2268u);
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l4 = vader_host_std_core_byte_len(2268u);
    l3 = vader_chk_add(i64, l3, l4);
    while ((l3 < l2)) {
        l5 = vader_host_std_core_byte_at(l0, l3);
        if (l5 == INT32_C(32)) {
            l6 = true;
        } else {
            l6 = l5 == INT32_C(9);
        }
        if (!(l6)) {
            break;
        }
        l3 = vader_chk_add(i64, l3, INT64_C(1));
    }
    t0 = std_string_matches_at(l0, l3, 221u);
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l3 = vader_chk_add(i64, l3, INT64_C(1));
    l4 = l3;
    while ((l3 < l2)) {
        t1 = vader_host_std_core_byte_at(l0, l3);
        if (!(t1 != INT32_C(34))) {
            break;
        }
        l3 = vader_chk_add(i64, l3, INT64_C(1));
    }
    if (!((l3 >= l2))) {
        l10 = vader_host_std_core_byte_slice(l0, l4, l3);
        l11 = vader_lexer_empty_file_span(l1);
        vader_struct_vader_parser_ModuleHeader_t* _a0_obj = (vader_struct_vader_parser_ModuleHeader_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_ModuleHeader_t));
        vader_obj_header_init(_a0_obj, 1202u);
        _a0_obj->f_name = l10;
        _a0_obj->f_name_span = l11;
        t2 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_string_t l6 = 0;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l5, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l6, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_parser_advance(l0);
    l3 = vader_parser_expect_string_literal(l0, 2053u);
    l4 = vader_parser_match_kind(l0, (uint8_t) 84);
    if (!(l4.tag == 0u)) {
        t0 = l4.payload.obj;
        l5 = ((vader_struct_vader_lexer_Token_t*) t0)->f_span;
        vader_parser_error(l0, (uint8_t) 4, l5, 2616u);
        vader_parser_parse_import_name_list_rest(l0);
    }
    l5 = vader_parser_peek_at(l0, INT32_C(-1));
    l5 = vader_parser_span_of(l0, l2, l5);
    l6 = ((vader_struct_vader_parser_StringLitInfo_t*) l3)->f_text;
    t1 = ((vader_struct_vader_lexer_Token_t*) l2)->f_text;
    vader_struct_toolchain_ast_NamedNamespaceImport_t* _a0_obj = (vader_struct_toolchain_ast_NamedNamespaceImport_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_NamedNamespaceImport_t));
    vader_obj_header_init(_a0_obj, 629u);
    _a0_obj->f_name = t1;
    l3 = (void*) _a0_obj;
    vader_struct_toolchain_ast_ImportDecl_t* _a1_obj = (vader_struct_toolchain_ast_ImportDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ImportDecl_t));
    vader_obj_header_init(_a1_obj, 615u);
    _a1_obj->f_span = l5;
    _a1_obj->f_id = INT64_C(0);
    _a1_obj->f_path = l6;
    _a1_obj->f_binding = vader_ref_box(l3);
    _a1_obj->f_decorators = l1;
    t0 = (void*) _a1_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_parser_parse_optional_module_decl(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    vader_string_t l4 = 0;
    vader_string_t t0 = 0;
    bool t1;
    void* t2 = NULL;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t2 };
    vader_string_t* gc_atom_roots[2] = { &l4, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_peek(l0);
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind != INT32_C(2)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t0 = ((vader_struct_vader_lexer_Token_t*) l1)->f_text;
    if (t0 != 2268u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t1 = vader_parser_check_at(l0, (uint8_t) 6, INT32_C(1));
    if (!(t1)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l1 = vader_parser_advance(l0);
    l2 = vader_parser_expect_string_literal(l0, 2271u);
    t0 = ((vader_struct_vader_parser_StringLitInfo_t*) l2)->f_text;
    t1 = vader_parser_is_valid_module_name(t0);
    if (!(t1)) {
        l3 = ((vader_struct_vader_parser_StringLitInfo_t*) l2)->f_span;
        vader_parser_error(l0, (uint8_t) 16, l3, 0u);
    }
    l3 = vader_parser_peek_at(l0, INT32_C(-1));
    l1 = vader_parser_span_of(l0, l1, l3);
    l4 = ((vader_struct_vader_parser_StringLitInfo_t*) l2)->f_text;
    l2 = ((vader_struct_vader_parser_StringLitInfo_t*) l2)->f_span;
    vader_struct_toolchain_ast_ModuleDecl_t* _a0_obj = (vader_struct_toolchain_ast_ModuleDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ModuleDecl_t));
    vader_obj_header_init(_a0_obj, 628u);
    _a0_obj->f_span = l1;
    _a0_obj->f_id = INT64_C(0);
    _a0_obj->f_name = l4;
    _a0_obj->f_name_span = l2;
    t2 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_parser_parse_paren(void* l0) {
    vader_box_t l1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_parser_advance(l0);
    vader_parser_skip_newlines(l0);
    l1 = vader_parser_parse_expr(l0, INT32_C(0));
    vader_parser_skip_newlines(l0);
    vader_parser_expect(l0, (uint8_t) 81, 1238u);
    { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_parser_parse_pattern(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    vader_string_t l5 = 0;
    vader_box_t l6 = vader_box_null(), l7 = vader_box_null();
    bool l8;
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
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(87)) {
        vader_parser_advance(l0);
        l2 = vader_parser_expect(l0, (uint8_t) 2, 2895u);
        l3 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l1)->f_span)->f_start;
        l4 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l2)->f_span)->f_end;
        vader_struct_toolchain_span_Span_t* _a0_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
        vader_obj_header_init(_a0_obj, 667u);
        _a0_obj->f_start = l3;
        _a0_obj->f_end = l4;
        l3 = (void*) _a0_obj;
        l5 = ((vader_struct_vader_lexer_Token_t*) l2)->f_text;
        vader_struct_toolchain_ast_EnumVariantPattern_t* _a1_obj = (vader_struct_toolchain_ast_EnumVariantPattern_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_EnumVariantPattern_t));
        vader_obj_header_init(_a1_obj, 601u);
        _a1_obj->f_span = l3;
        _a1_obj->f_id = INT64_C(0);
        _a1_obj->f_variant = l5;
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(19)) {
        vader_parser_advance(l0);
        t1 = vader_parser_check(l0, (uint8_t) 87);
        if (t1) {
            l2 = vader_parser_advance(l0);
            l3 = vader_parser_expect(l0, (uint8_t) 2, 2895u);
            l2 = vader_parser_span_of(l0, l2, l3);
            l5 = ((vader_struct_vader_lexer_Token_t*) l3)->f_text;
            vader_struct_toolchain_ast_IdentExpr_t* _a2_obj = (vader_struct_toolchain_ast_IdentExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_IdentExpr_t));
            vader_obj_header_init(_a2_obj, 610u);
            _a2_obj->f_span = l2;
            _a2_obj->f_id = INT64_C(0);
            _a2_obj->f_name = l5;
            _a2_obj->f_implicit_dot = true;
            _a2_obj->f_is_type_param_intro = false;
            t0 = (void*) _a2_obj;
            l6 = vader_ref_box(t0);
        } else {
            l6 = vader_parser_parse_type(l0);
        }
        l7 = vader_box_obj(0u, NULL);
        t1 = vader_parser_check(l0, (uint8_t) 84);
        if (t1) {
            t0 = vader_parser_parse_struct_pattern(l0);
            l7 = vader_ref_box(t0);
        }
        l2 = (void*) &vader_fn_static___lambda_vader_parser_5;
        vader_parser_reject_as_binder(l0, (uint8_t) 22, l2);
        l2 = vader_parser_peek_at(l0, INT32_C(-1));
        t0 = vader_parser_span_of(l0, l1, l2);
        vader_struct_toolchain_ast_IsPattern_t* _a3_obj = (vader_struct_toolchain_ast_IsPattern_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_IsPattern_t));
        vader_obj_header_init(_a3_obj, 622u);
        _a3_obj->f_span = t0;
        _a3_obj->f_id = INT64_C(0);
        _a3_obj->f_ty = l6;
        _a3_obj->f_inner = l7;
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(2)) {
        t2 = ((vader_struct_vader_lexer_Token_t*) l1)->f_text;
        if (t2 == 928u) {
            vader_parser_advance(l0);
            vader_struct_toolchain_ast_WildcardPattern_t* _a4_obj = (vader_struct_toolchain_ast_WildcardPattern_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_WildcardPattern_t));
            vader_obj_header_init(_a4_obj, 663u);
            _a4_obj->f_span = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
            _a4_obj->f_id = INT64_C(0);
            t0 = (void*) _a4_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(2)) {
        vader_parser_advance(l0);
        l2 = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
        l5 = ((vader_struct_vader_lexer_Token_t*) l1)->f_text;
        l5 = concat_3(2930u, l5, 49u);
        vader_parser_error(l0, (uint8_t) 22, l2, l5);
        vader_struct_toolchain_ast_WildcardPattern_t* _a5_obj = (vader_struct_toolchain_ast_WildcardPattern_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_WildcardPattern_t));
        vader_obj_header_init(_a5_obj, 663u);
        _a5_obj->f_span = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
        _a5_obj->f_id = INT64_C(0);
        t0 = (void*) _a5_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(82)) {
        t0 = vader_parser_reject_tuple_pattern(l0);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_parser_is_literal_start(l1);
    if (!(t1)) {
        l4 = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
        l5 = vader_parser_describe_token(l1);
        l5 = concat_2(1976u, l5);
        vader_parser_error(l0, (uint8_t) 5, l4, l5);
        vader_parser_advance(l0);
        vader_struct_toolchain_ast_WildcardPattern_t* _a6_obj = (vader_struct_toolchain_ast_WildcardPattern_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_WildcardPattern_t));
        vader_obj_header_init(_a6_obj, 663u);
        _a6_obj->f_span = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
        _a6_obj->f_id = INT64_C(0);
        t0 = (void*) _a6_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = vader_parser_parse_prefix(l0);
    t1 = vader_parser_check(l0, (uint8_t) 74);
    if (t1) {
        l8 = true;
    } else {
        l8 = vader_parser_check(l0, (uint8_t) 73);
    }
    if (!(l8)) {
        l3 = vader_parser_peek_at(l0, INT32_C(-1));
        t0 = vader_parser_span_of(l0, l1, l3);
        vader_struct_toolchain_ast_LiteralPattern_t* _a7_obj = (vader_struct_toolchain_ast_LiteralPattern_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_LiteralPattern_t));
        vader_obj_header_init(_a7_obj, 625u);
        _a7_obj->f_span = t0;
        _a7_obj->f_id = INT64_C(0);
        _a7_obj->f_value = l6;
        t0 = (void*) _a7_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l8 = vader_parser_check(l0, (uint8_t) 74);
    vader_parser_advance(l0);
    l7 = vader_parser_parse_prefix(l0);
    l2 = vader_parser_peek_at(l0, INT32_C(-1));
    t0 = vader_parser_span_of(l0, l1, l2);
    vader_struct_toolchain_ast_RangePattern_t* _a8_obj = (vader_struct_toolchain_ast_RangePattern_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_RangePattern_t));
    vader_obj_header_init(_a8_obj, 639u);
    _a8_obj->f_span = t0;
    _a8_obj->f_id = INT64_C(0);
    _a8_obj->f_inclusive = l8;
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
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l1, &l10, &t2 };
    void** gc_raw_roots[7] = { &l0, &l2, &l3, &l4, &l5, &l8, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (((vader_struct_vader_lexer_Token_t*) l2)->f_kind == INT32_C(87)) {
        vader_parser_advance(l0);
        t0 = vader_parser_check(l0, (uint8_t) 3);
        if (t0) {
            l3 = vader_parser_advance(l0);
            l4 = ((vader_struct_toolchain_span_Span_t*) VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, l1.payload.obj))->f_start;
            l5 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l3)->f_span)->f_end;
            vader_struct_toolchain_span_Span_t* _a0_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
            vader_obj_header_init(_a0_obj, 667u);
            _a0_obj->f_start = l4;
            _a0_obj->f_end = l5;
            l4 = (void*) _a0_obj;
            l6 = ((vader_struct_vader_lexer_Token_t*) l3)->f_text;
            l3 = ((vader_struct_vader_lexer_Token_t*) l3)->f_span;
            vader_struct_toolchain_ast_FieldExpr_t* _a1_obj = (vader_struct_toolchain_ast_FieldExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FieldExpr_t));
            vader_obj_header_init(_a1_obj, 603u);
            _a1_obj->f_span = l4;
            _a1_obj->f_id = INT64_C(0);
            _a1_obj->f_target = l1;
            _a1_obj->f_field = l6;
            _a1_obj->f_field_span = l3;
            _a1_obj->f_is_numeric = true;
            t1 = (void*) _a1_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l3 = vader_parser_expect(l0, (uint8_t) 2, 1901u);
        l4 = ((vader_struct_toolchain_span_Span_t*) VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, l1.payload.obj))->f_start;
        l5 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l3)->f_span)->f_end;
        vader_struct_toolchain_span_Span_t* _a2_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
        vader_obj_header_init(_a2_obj, 667u);
        _a2_obj->f_start = l4;
        _a2_obj->f_end = l5;
        l4 = (void*) _a2_obj;
        l6 = ((vader_struct_vader_lexer_Token_t*) l3)->f_text;
        l3 = ((vader_struct_vader_lexer_Token_t*) l3)->f_span;
        vader_struct_toolchain_ast_FieldExpr_t* _a3_obj = (vader_struct_toolchain_ast_FieldExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FieldExpr_t));
        vader_obj_header_init(_a3_obj, 603u);
        _a3_obj->f_span = l4;
        _a3_obj->f_id = INT64_C(0);
        _a3_obj->f_target = l1;
        _a3_obj->f_field = l6;
        _a3_obj->f_field_span = l3;
        _a3_obj->f_is_numeric = false;
        l3 = (void*) _a3_obj;
        l7 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pos;
        t0 = vader_parser_scan_angle_generic(l0, l7);
        if (t0) {
            t2 = vader_parser_parse_generic_use(l0, vader_ref_box(l3));
            { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = vader_parser_allows_struct_lit(l0);
        if (t0) {
            t0 = vader_parser_check(l0, (uint8_t) 84);
            if (t0) {
                l4 = ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens;
                l7 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pos;
                t0 = vader_parser_looks_like_struct_lit_body(l4, l7);
                if (t0) {
                    vader_parser_advance(l0);
                    l4 = vader_parser_parse_struct_lit_fields(l0);
                    l5 = vader_parser_expect(l0, (uint8_t) 85, 1363u);
                    l8 = ((vader_struct_toolchain_span_Span_t*) VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, l1.payload.obj))->f_start;
                    l5 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l5)->f_span)->f_end;
                    vader_struct_toolchain_span_Span_t* _a4_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
                    vader_obj_header_init(_a4_obj, 667u);
                    _a4_obj->f_start = l8;
                    _a4_obj->f_end = l5;
                    l5 = (void*) _a4_obj;
                    l8 = ((vader_struct_vader_parser_CommaList__toolchain_ast_StructLitField___toolchain_ast_StructLitSpread_t*) l4)->f_items;
                    l9 = ((vader_struct_vader_parser_CommaList__toolchain_ast_StructLitField___toolchain_ast_StructLitSpread_t*) l4)->f_trailing_comma;
                    vader_struct_toolchain_ast_StructLitExpr_t* _a5_obj = (vader_struct_toolchain_ast_StructLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_StructLitExpr_t));
                    vader_obj_header_init(_a5_obj, 650u);
                    _a5_obj->f_span = l5;
                    _a5_obj->f_id = INT64_C(0);
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
    if (((vader_struct_vader_lexer_Token_t*) l2)->f_kind == INT32_C(80)) {
        vader_parser_advance(l0);
        l3 = vader_parser_parse_call_args(l0);
        vader_parser_expect(l0, (uint8_t) 81, 1236u);
        l4 = ((vader_struct_toolchain_span_Span_t*) VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, l1.payload.obj))->f_start;
        t1 = vader_parser_peek_at(l0, INT32_C(-1));
        l5 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) t1)->f_span)->f_end;
        vader_struct_toolchain_span_Span_t* _a6_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
        vader_obj_header_init(_a6_obj, 667u);
        _a6_obj->f_start = l4;
        _a6_obj->f_end = l5;
        l4 = (void*) _a6_obj;
        vader_array_t* _a7_arr = vader_array_new(227u, 0u, 13u, 1503u);
        l5 = (void*) _a7_arr;
        l8 = ((vader_struct_vader_parser_CommaList__toolchain_ast_CallArg_t*) l3)->f_items;
        l9 = ((vader_struct_vader_parser_CommaList__toolchain_ast_CallArg_t*) l3)->f_trailing_comma;
        vader_struct_toolchain_ast_CallExpr_t* _a8_obj = (vader_struct_toolchain_ast_CallExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_CallExpr_t));
        vader_obj_header_init(_a8_obj, 585u);
        _a8_obj->f_span = l4;
        _a8_obj->f_id = INT64_C(0);
        _a8_obj->f_callee = l1;
        _a8_obj->f_type_args = l5;
        _a8_obj->f_args = l8;
        _a8_obj->f_trailing_comma = l9;
        t1 = (void*) _a8_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_parser_check_at(l0, (uint8_t) 83, INT32_C(1));
    if (!(t0)) {
        vader_parser_advance(l0);
        l10 = vader_parser_parse_expr(l0, INT32_C(0));
        vader_parser_expect(l0, (uint8_t) 83, 1325u);
        l5 = ((vader_struct_toolchain_span_Span_t*) VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, l1.payload.obj))->f_start;
        t1 = vader_parser_peek_at(l0, INT32_C(-1));
        l8 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) t1)->f_span)->f_end;
        vader_struct_toolchain_span_Span_t* _a9_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
        vader_obj_header_init(_a9_obj, 667u);
        _a9_obj->f_start = l5;
        _a9_obj->f_end = l8;
        t1 = (void*) _a9_obj;
        vader_struct_toolchain_ast_IndexExpr_t* _a10_obj = (vader_struct_toolchain_ast_IndexExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_IndexExpr_t));
        vader_obj_header_init(_a10_obj, 618u);
        _a10_obj->f_span = t1;
        _a10_obj->f_id = INT64_C(0);
        _a10_obj->f_target = l1;
        _a10_obj->f_index = l10;
        t1 = (void*) _a10_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_parser_advance(l0);
    l3 = vader_parser_advance(l0);
    l4 = ((vader_struct_toolchain_span_Span_t*) VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, l1.payload.obj))->f_start;
    l3 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l3)->f_span)->f_end;
    vader_struct_toolchain_span_Span_t* _a11_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a11_obj, 667u);
    _a11_obj->f_start = l4;
    _a11_obj->f_end = l3;
    t1 = (void*) _a11_obj;
    vader_struct_toolchain_ast_ArrayTypeExpr_t* _a12_obj = (vader_struct_toolchain_ast_ArrayTypeExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ArrayTypeExpr_t));
    vader_obj_header_init(_a12_obj, 576u);
    _a12_obj->f_span = t1;
    _a12_obj->f_id = INT64_C(0);
    _a12_obj->f_element = l1;
    t1 = (void*) _a12_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_parser_parse_prefix(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l15 = NULL;
    int64_t l3, l4;
    uint32_t l7;
    vader_box_t l8 = vader_box_null(), l13 = vader_box_null(), l14 = vader_box_null();
    bool l9, l12;
    uint8_t l10;
    vader_string_t l11 = 0;
    vader_string_t l16 = 0;
    bool t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_string_t t3 = 0;
    uint8_t t4;
    vader_box_t* gc_roots[4] = { &l8, &l13, &l14, &t1 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l5, &l6, &l15, &t2 };
    vader_string_t* gc_atom_roots[3] = { &l11, &l16, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_peek(l0);
    t0 = vader_parser_is_number_token(l1);
    if (t0) {
        vader_parser_advance(l0);
        l2 = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
        t1 = vader_parser_number_literal(l1, l2, false);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(37)) {
        l2 = vader_parser_peek_at(l0, INT32_C(1));
        t0 = vader_parser_is_number_token(l2);
        if (t0) {
            l3 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l2)->f_span)->f_start)->f_offset;
            l4 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l1)->f_span)->f_end)->f_offset;
            if (l3 == l4) {
                vader_parser_advance(l0);
                vader_parser_advance(l0);
                l5 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l1)->f_span)->f_start;
                l6 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l2)->f_span)->f_end;
                vader_struct_toolchain_span_Span_t* _a0_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
                vader_obj_header_init(_a0_obj, 667u);
                _a0_obj->f_start = l5;
                _a0_obj->f_end = l6;
                l5 = (void*) _a0_obj;
                t1 = vader_parser_number_literal(l2, l5, true);
                { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(5)) {
        vader_parser_advance(l0);
        l7 = (uint32_t) 0;
        l8 = ((vader_struct_vader_lexer_Token_t*) l1)->f_value;
        if (l8.tag == 324u) {
            l7 = ((uint32_t) l8.payload.i);
        }
        vader_struct_toolchain_ast_CharLitExpr_t* _a1_obj = (vader_struct_toolchain_ast_CharLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_CharLitExpr_t));
        vader_obj_header_init(_a1_obj, 587u);
        _a1_obj->f_span = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
        _a1_obj->f_id = INT64_C(0);
        _a1_obj->f_value = l7;
        t2 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(31)) {
        vader_parser_advance(l0);
        vader_struct_toolchain_ast_BoolLitExpr_t* _a2_obj = (vader_struct_toolchain_ast_BoolLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BoolLitExpr_t));
        vader_obj_header_init(_a2_obj, 582u);
        _a2_obj->f_span = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
        _a2_obj->f_id = INT64_C(0);
        _a2_obj->f_value = true;
        t2 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(32)) {
        vader_parser_advance(l0);
        vader_struct_toolchain_ast_BoolLitExpr_t* _a3_obj = (vader_struct_toolchain_ast_BoolLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BoolLitExpr_t));
        vader_obj_header_init(_a3_obj, 582u);
        _a3_obj->f_span = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
        _a3_obj->f_id = INT64_C(0);
        _a3_obj->f_value = false;
        t2 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(33)) {
        vader_parser_advance(l0);
        vader_struct_toolchain_ast_NullLitExpr_t* _a4_obj = (vader_struct_toolchain_ast_NullLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_NullLitExpr_t));
        vader_obj_header_init(_a4_obj, 632u);
        _a4_obj->f_span = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
        _a4_obj->f_id = INT64_C(0);
        t2 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(6)) {
        t2 = vader_parser_parse_string_lit(l0);
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(2)) {
        t1 = vader_parser_parse_ident_or_struct_lit(l0);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(80)) {
        t0 = vader_parser_allows_bare_lambda(l0);
        if (t0) {
            t0 = vader_parser_peek_lambda_without_fn(l0);
            if (t0) {
                t2 = vader_parser_parse_lambda_without_fn(l0);
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t1 = vader_parser_parse_paren(l0);
            { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t1 = vader_parser_parse_paren(l0);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(82)) {
        t2 = vader_parser_parse_seq_lit(l0);
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(84)) {
        t2 = vader_parser_parse_block(l0);
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(37)) {
        l9 = true;
    } else {
        l9 = ((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(60);
    }
    if (l9) {
        l9 = true;
    } else {
        l9 = ((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(47);
    }
    if (l9) {
        vader_parser_advance(l0);
        l10 = (uint8_t) 0;
        if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(60)) {
            l10 = (uint8_t) 1;
        }
        if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(47)) {
            l10 = (uint8_t) 2;
        }
        l8 = vader_parser_parse_expr(l0, INT32_C(95));
        l2 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l1)->f_span)->f_start;
        l5 = ((vader_struct_toolchain_span_Span_t*) VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, l8.payload.obj))->f_end;
        vader_struct_toolchain_span_Span_t* _a5_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
        vader_obj_header_init(_a5_obj, 667u);
        _a5_obj->f_start = l2;
        _a5_obj->f_end = l5;
        t2 = (void*) _a5_obj;
        vader_struct_toolchain_ast_UnaryExpr_t* _a6_obj = (vader_struct_toolchain_ast_UnaryExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_UnaryExpr_t));
        vader_obj_header_init(_a6_obj, 659u);
        _a6_obj->f_span = t2;
        _a6_obj->f_id = INT64_C(0);
        _a6_obj->f_op = l10;
        _a6_obj->f_operand = l8;
        t2 = (void*) _a6_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(24)) {
        vader_parser_advance(l0);
        l8 = vader_parser_parse_expr(l0, INT32_C(95));
        l2 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l1)->f_span)->f_start;
        l5 = ((vader_struct_toolchain_span_Span_t*) VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, l8.payload.obj))->f_end;
        vader_struct_toolchain_span_Span_t* _a7_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
        vader_obj_header_init(_a7_obj, 667u);
        _a7_obj->f_start = l2;
        _a7_obj->f_end = l5;
        t2 = (void*) _a7_obj;
        vader_struct_toolchain_ast_AwaitExpr_t* _a8_obj = (vader_struct_toolchain_ast_AwaitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_AwaitExpr_t));
        vader_obj_header_init(_a8_obj, 579u);
        _a8_obj->f_span = t2;
        _a8_obj->f_id = INT64_C(0);
        _a8_obj->f_inner = l8;
        t2 = (void*) _a8_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(16)) {
        t2 = vader_parser_parse_if_expr(l0);
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(18)) {
        l2 = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
        t2 = vader_parser_parse_match_expr(l0, false, false, l2);
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(11)) {
        t2 = vader_parser_parse_lambda(l0);
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(34)) {
        vader_parser_advance(l0);
        t2 = vader_parser_ident_expr(((vader_struct_vader_lexer_Token_t*) l1)->f_span, 2446u);
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(78)) {
        l2 = vader_parser_advance(l0);
        l5 = vader_parser_expect(l0, (uint8_t) 2, 1745u);
        t3 = ((vader_struct_vader_lexer_Token_t*) l5)->f_text;
        t0 = vader_parser_decorator_on(t3, (uint8_t) 2);
        if (t0) {
            t0 = vader_parser_check(l0, (uint8_t) 18);
            if (!(t0)) {
                l6 = ((vader_struct_vader_lexer_Token_t*) l5)->f_span;
                l11 = ((vader_struct_vader_lexer_Token_t*) l5)->f_text;
                l11 = concat_3(1280u, l11, 1145u);
                vader_parser_error(l0, (uint8_t) 8, l6, l11);
            }
            t3 = ((vader_struct_vader_lexer_Token_t*) l5)->f_text;
            l9 = t3 == 2365u;
            l12 = !(l9);
            l6 = ((vader_struct_vader_lexer_Token_t*) l2)->f_span;
            t2 = vader_parser_parse_match_expr(l0, l9, l12, l6);
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t3 = ((vader_struct_vader_lexer_Token_t*) l5)->f_text;
        l8 = vader_parser_intrinsic_spec(t3);
        if (l8.tag == 0u) {
            l6 = vader_parser_span_of(l0, l2, l5);
            l11 = ((vader_struct_vader_lexer_Token_t*) l5)->f_text;
            l11 = concat_3(1280u, l11, 1119u);
            vader_parser_error(l0, (uint8_t) 8, l6, l11);
            t0 = vader_parser_check(l0, (uint8_t) 80);
            if (t0) {
                vader_parser_advance(l0);
                for (;;) {
                    t0 = vader_parser_check(l0, (uint8_t) 81);
                    if (!(t0)) {
                        t0 = vader_parser_check(l0, (uint8_t) 0);
                        if (t0) break;
                        vader_parser_advance(l0);
                        continue;
                    }
                    break;
                }
                t0 = vader_parser_check(l0, (uint8_t) 81);
                if (t0) {
                    vader_parser_advance(l0);
                }
            }
            t2 = vader_parser_span_of(l0, l2, l5);
            vader_struct_toolchain_ast_NullLitExpr_t* _a9_obj = (vader_struct_toolchain_ast_NullLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_NullLitExpr_t));
            vader_obj_header_init(_a9_obj, 632u);
            _a9_obj->f_span = t2;
            _a9_obj->f_id = INT64_C(0);
            t2 = (void*) _a9_obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (!(l8.tag == 1201u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t2 = l8.payload.obj;
        l11 = ((vader_struct_vader_parser_IntrinsicSpec_t*) t2)->f_name;
        l11 = concat_3(1225u, l11, 990u);
        vader_parser_expect(l0, (uint8_t) 80, l11);
        vader_array_t* _a10_arr = vader_array_new(227u, 0u, 13u, 1503u);
        l6 = (void*) _a10_arr;
        vader_parser_skip_newlines(l0);
        l9 = false;
        t0 = vader_parser_check(l0, (uint8_t) 81);
        if (!(t0)) {
            for (;;) {
                vader_parser_skip_newlines(l0);
                t0 = vader_parser_check(l0, (uint8_t) 81);
                if (!(t0)) {
                    l3 = ((vader_array_t*) l6)->length;
                    t2 = l8.payload.obj;
                    t4 = vader_parser_arg_kind(t2, l3);
                    if (t4 == INT32_C(0)) {
                        l13 = vader_parser_parse_type(l0);
                        vader_array_push_ref((vader_array_t*) l6, l13.payload.obj);
                    } else {
                        l14 = vader_parser_parse_expr(l0, INT32_C(0));
                        vader_array_push_ref((vader_array_t*) l6, l14.payload.obj);
                    }
                    vader_parser_skip_newlines(l0);
                    t1 = vader_parser_match_kind(l0, (uint8_t) 86);
                    if (t1.tag == 0u) break;
                    vader_parser_skip_newlines(l0);
                    l9 = vader_parser_check(l0, (uint8_t) 81);
                    continue;
                }
                break;
            }
        }
        t2 = l8.payload.obj;
        l11 = ((vader_struct_vader_parser_IntrinsicSpec_t*) t2)->f_name;
        l11 = concat_3(1235u, l11, 279u);
        l15 = vader_parser_expect(l0, (uint8_t) 81, l11);
        l2 = vader_parser_span_of(l0, l2, l15);
        t2 = l8.payload.obj;
        l11 = ((vader_struct_vader_parser_IntrinsicSpec_t*) t2)->f_name;
        l5 = ((vader_struct_vader_lexer_Token_t*) l5)->f_span;
        vader_struct_toolchain_ast_IntrinsicCallExpr_t* _a11_obj = (vader_struct_toolchain_ast_IntrinsicCallExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_IntrinsicCallExpr_t));
        vader_obj_header_init(_a11_obj, 621u);
        _a11_obj->f_span = l2;
        _a11_obj->f_id = INT64_C(0);
        _a11_obj->f_name = l11;
        _a11_obj->f_name_span = l5;
        _a11_obj->f_args = l6;
        _a11_obj->f_trailing_comma = l9;
        t2 = (void*) _a11_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(87))) {
        l6 = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
        l16 = vader_parser_describe_token(l1);
        l16 = concat_2(1976u, l16);
        vader_parser_error(l0, (uint8_t) 2, l6, l16);
        vader_parser_advance(l0);
        vader_struct_toolchain_ast_NullLitExpr_t* _a12_obj = (vader_struct_toolchain_ast_NullLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_NullLitExpr_t));
        vader_obj_header_init(_a12_obj, 632u);
        _a12_obj->f_span = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
        _a12_obj->f_id = INT64_C(0);
        t2 = (void*) _a12_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_parser_advance(l0);
    l2 = vader_parser_expect(l0, (uint8_t) 2, 2895u);
    l1 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l1)->f_span)->f_start;
    l5 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l2)->f_span)->f_end;
    vader_struct_toolchain_span_Span_t* _a13_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a13_obj, 667u);
    _a13_obj->f_start = l1;
    _a13_obj->f_end = l5;
    l1 = (void*) _a13_obj;
    l11 = ((vader_struct_vader_lexer_Token_t*) l2)->f_text;
    l2 = ((vader_struct_vader_lexer_Token_t*) l2)->f_span;
    vader_struct_toolchain_ast_DotVariantExpr_t* _a14_obj = (vader_struct_toolchain_ast_DotVariantExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_DotVariantExpr_t));
    vader_obj_header_init(_a14_obj, 598u);
    _a14_obj->f_span = l1;
    _a14_obj->f_id = INT64_C(0);
    _a14_obj->f_variant = l11;
    _a14_obj->f_variant_span = l2;
    t2 = (void*) _a14_obj;
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
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
    int64_t l6, l7;
    vader_string_t l19 = 0;
    bool t0;
    int64_t t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[3] = { &l3, &l4, &l8 };
    void** gc_raw_roots[15] = {
        &l0, &l1, &l2, &l5, &l9, &l10, &l11, &l12, &l13, &l14, &l15, &l16, &l17, &l18, &t2,
    };
    vader_string_t* gc_atom_roots[1] = { &l19 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 15u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_peek(l0);
    vader_array_t* _a0_arr = vader_array_new(228u, 0u, 13u, 1529u);
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
                l7 = INT64_C(0);
                while ((l7 < l6)) {
                    vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
                    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                    l8 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l7);
                    vader_array_push_ref((vader_array_t*) l2, l8.payload.obj);
                    l7 = (l7 + INT64_C(1));
                }
                vader_array_t* _a2_arr = vader_array_new(228u, 0u, 13u, 1529u);
                l9 = (void*) _a2_arr;
                ((vader_struct_vader_parser_Parser_t*) l0)->f_pending_decls = l9;
                VADER_WRITE_BARRIER((vader_struct_vader_parser_Parser_t*) l0);
            }
            if (l4.tag == 0u) {
                vader_parser_advance(l0);
            } else if (l4.tag == 615u) {
                l10 = l4.payload.obj;
                vader_array_push_ref((vader_array_t*) l2, l10);
            } else if (l4.tag == 605u) {
                l11 = l4.payload.obj;
                vader_array_push_ref((vader_array_t*) l2, l11);
            } else if (l4.tag == 648u) {
                l12 = l4.payload.obj;
                vader_array_push_ref((vader_array_t*) l2, l12);
            } else if (l4.tag == 599u) {
                l13 = l4.payload.obj;
                vader_array_push_ref((vader_array_t*) l2, l13);
            } else if (l4.tag == 655u) {
                l14 = l4.payload.obj;
                vader_array_push_ref((vader_array_t*) l2, l14);
            } else if (l4.tag == 614u) {
                l15 = l4.payload.obj;
                vader_array_push_ref((vader_array_t*) l2, l15);
            } else if (l4.tag == 657u) {
                l16 = l4.payload.obj;
                vader_array_push_ref((vader_array_t*) l2, l16);
            } else if (l4.tag == 588u) {
                l17 = l4.payload.obj;
                vader_array_push_ref((vader_array_t*) l2, l17);
            } else {
                if (!(l4.tag == 577u)) {
                    vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                }
                l18 = l4.payload.obj;
                vader_array_push_ref((vader_array_t*) l2, l18);
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
    vader_obj_header_init(_a3_obj, 667u);
    _a3_obj->f_start = l1;
    _a3_obj->f_end = l5;
    l1 = (void*) _a3_obj;
    vader_struct_toolchain_ast_Program_t* _a4_obj = (vader_struct_toolchain_ast_Program_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_Program_t));
    vader_obj_header_init(_a4_obj, 637u);
    _a4_obj->f_file = l19;
    _a4_obj->f_span = l1;
    _a4_obj->f_id = INT64_C(0);
    _a4_obj->f_module = l3;
    _a4_obj->f_decls = l2;
    t2 = (void*) _a4_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_parser_parse_range_bound(void* l0) {
    vader_box_t l1 = vader_box_null(), l3 = vader_box_null();
    void* l2 = NULL;
    void* l4 = NULL;
    bool l5;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l1, &l3, &t0 };
    void** gc_raw_roots[3] = { &l0, &l2, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_match_kind(l0, (uint8_t) 37);
    l2 = vader_parser_expect(l0, (uint8_t) 3, 2090u);
    l3 = l1;
    if (l3.tag == 0u) {
        l4 = l2;
    } else {
        l4 = l3.payload.obj;
    }
    l4 = vader_parser_span_of(l0, l4, l2);
    l5 = !(l1.tag == 0u);
    t0 = vader_parser_number_literal(l2, l4, l5);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_parser_parse_range_type(void* l0) {
    vader_box_t l1 = vader_box_null(), l5 = vader_box_null();
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    vader_string_t l4 = 0;
    bool l7;
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l5 };
    void** gc_raw_roots[5] = { &l0, &l2, &l3, &l6, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_parse_range_bound(l0);
    l2 = vader_parser_peek(l0);
    if (((vader_struct_vader_lexer_Token_t*) l2)->f_kind != INT32_C(74)) {
        if (((vader_struct_vader_lexer_Token_t*) l2)->f_kind != INT32_C(73)) {
            l3 = ((vader_struct_vader_lexer_Token_t*) l2)->f_span;
            l4 = vader_parser_describe_token(l2);
            l4 = concat_2(1427u, l4);
            vader_parser_error(l0, (uint8_t) 3, l3, l4);
            { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    vader_parser_advance(l0);
    l5 = vader_parser_parse_range_bound(l0);
    l3 = ((vader_struct_toolchain_span_Span_t*) VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, l1.payload.obj))->f_start;
    l6 = ((vader_struct_toolchain_span_Span_t*) VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, l5.payload.obj))->f_end;
    vader_struct_toolchain_span_Span_t* _a0_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a0_obj, 667u);
    _a0_obj->f_start = l3;
    _a0_obj->f_end = l6;
    l3 = (void*) _a0_obj;
    l7 = ((vader_struct_vader_lexer_Token_t*) l2)->f_kind == INT32_C(74);
    vader_struct_toolchain_ast_RangeExpr_t* _a1_obj = (vader_struct_toolchain_ast_RangeExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_RangeExpr_t));
    vader_obj_header_init(_a1_obj, 638u);
    _a1_obj->f_span = l3;
    _a1_obj->f_id = INT64_C(0);
    _a1_obj->f_inclusive = l7;
    _a1_obj->f_lower = l1;
    _a1_obj->f_upper = l5;
    t0 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_return(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    vader_box_t l2 = vader_box_null();
    bool t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_advance(l0);
    l2 = vader_box_obj(0u, NULL);
    t0 = vader_parser_check(l0, (uint8_t) 1);
    if (!(t0)) {
        t0 = vader_parser_check(l0, (uint8_t) 85);
        if (!(t0)) {
            t0 = vader_parser_check(l0, (uint8_t) 0);
            if (!(t0)) {
                l2 = vader_parser_parse_expr(l0, INT32_C(0));
            }
        }
    }
    l3 = vader_parser_peek_at(l0, INT32_C(-1));
    t1 = vader_parser_span_of(l0, l1, l3);
    vader_struct_toolchain_ast_ReturnStmt_t* _a0_obj = (vader_struct_toolchain_ast_ReturnStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ReturnStmt_t));
    vader_obj_header_init(_a0_obj, 642u);
    _a0_obj->f_span = t1;
    _a0_obj->f_id = INT64_C(0);
    _a0_obj->f_value = l2;
    t1 = (void*) _a0_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_sam_arrow_member(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    vader_box_t l2 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[8] = { &l0, &l1, &l3, &l4, &l5, &l6, &l7, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_expect(l0, (uint8_t) 76, 1258u);
    l2 = vader_parser_parse_expr(l0, INT32_C(0));
    l3 = vader_parser_peek_at(l0, INT32_C(-1));
    l3 = vader_parser_span_of(l0, l1, l3);
    vader_array_t* _a0_arr = vader_array_new(229u, 0u, 13u, 1536u);
    l4 = (void*) _a0_arr;
    vader_struct_toolchain_ast_BlockExpr_t* _a1_obj = (vader_struct_toolchain_ast_BlockExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BlockExpr_t));
    vader_obj_header_init(_a1_obj, 581u);
    _a1_obj->f_span = l3;
    _a1_obj->f_id = INT64_C(0);
    _a1_obj->f_stmts = l4;
    _a1_obj->f_trailing = l2;
    l4 = (void*) _a1_obj;
    l1 = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
    vader_array_t* _a2_arr = vader_array_new(54u, 0u, 13u, 658u);
    l5 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(43u, 0u, 13u, 606u);
    l6 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(40u, 0u, 13u, 590u);
    l7 = (void*) _a4_arr;
    vader_struct_toolchain_ast_FnDecl_t* _a5_obj = (vader_struct_toolchain_ast_FnDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FnDecl_t));
    vader_obj_header_init(_a5_obj, 605u);
    _a5_obj->f_span = l3;
    _a5_obj->f_id = INT64_C(0);
    _a5_obj->f_name = 0u;
    _a5_obj->f_name_span = l1;
    _a5_obj->f_visibility = (uint8_t) 0;
    _a5_obj->f_type_params = l5;
    _a5_obj->f_params = l6;
    _a5_obj->f_return_type = vader_box_obj(0u, NULL);
    _a5_obj->f_body = vader_ref_box(l4);
    _a5_obj->f_decorators = l7;
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
    vader_array_t* _a0_arr = vader_array_new(54u, 0u, 13u, 658u);
    l4 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(43u, 0u, 13u, 606u);
    l5 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(40u, 0u, 13u, 590u);
    l6 = (void*) _a2_arr;
    vader_struct_toolchain_ast_FnDecl_t* _a3_obj = (vader_struct_toolchain_ast_FnDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FnDecl_t));
    vader_obj_header_init(_a3_obj, 605u);
    _a3_obj->f_span = l2;
    _a3_obj->f_id = INT64_C(0);
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
    vader_array_t* _a0_arr = vader_array_new(227u, 0u, 13u, 1503u);
    l2 = (void*) _a0_arr;
    l3 = false;
    vader_parser_skip_newlines(l0);
    t0 = vader_parser_check(l0, (uint8_t) 83);
    if (!(t0)) {
        for (;;) {
            vader_parser_skip_newlines(l0);
            t0 = vader_parser_check(l0, (uint8_t) 83);
            if (!(t0)) {
                l4 = vader_parser_parse_expr(l0, INT32_C(0));
                vader_array_push_ref((vader_array_t*) l2, l4.payload.obj);
                vader_parser_skip_newlines(l0);
                t1 = vader_parser_match_kind(l0, (uint8_t) 86);
                if (t1.tag == 0u) break;
                vader_parser_skip_newlines(l0);
                l3 = vader_parser_check(l0, (uint8_t) 83);
                continue;
            }
            break;
        }
    }
    l5 = vader_parser_expect(l0, (uint8_t) 83, 1326u);
    t2 = vader_parser_span_of(l0, l1, l5);
    vader_struct_toolchain_ast_SeqLitExpr_t* _a1_obj = (vader_struct_toolchain_ast_SeqLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_SeqLitExpr_t));
    vader_obj_header_init(_a1_obj, 643u);
    _a1_obj->f_span = t2;
    _a1_obj->f_id = INT64_C(0);
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
    l4 = ((vader_struct_toolchain_ast_IdentExpr_t*) l1)->f_span;
    vader_array_t* _a0_arr = vader_array_new(40u, 0u, 13u, 590u);
    l5 = (void*) _a0_arr;
    vader_struct_toolchain_ast_FnParam_t* _a1_obj = (vader_struct_toolchain_ast_FnParam_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FnParam_t));
    vader_obj_header_init(_a1_obj, 606u);
    _a1_obj->f_span = l2;
    _a1_obj->f_id = INT64_C(0);
    _a1_obj->f_name = l3;
    _a1_obj->f_name_span = l4;
    _a1_obj->f_ty = vader_box_obj(0u, NULL);
    _a1_obj->f_default_value = vader_box_obj(0u, NULL);
    _a1_obj->f_variadic = false;
    _a1_obj->f_decorators = l5;
    l2 = (void*) _a1_obj;
    t0 = vader_parser_parse_expr(l0, INT32_C(0));
    l4 = vader_parser_wrap_as_block(t0);
    l5 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_IdentExpr_t*) l1)->f_span)->f_start;
    l6 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_BlockExpr_t*) l4)->f_span)->f_end;
    vader_struct_toolchain_span_Span_t* _a2_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a2_obj, 667u);
    _a2_obj->f_start = l5;
    _a2_obj->f_end = l6;
    l5 = (void*) _a2_obj;
    vader_array_t* _a3_arr = vader_array_new(43u, 1u, 13u, 606u);
    ((void**) _a3_arr->buf->slots)[_a3_arr->offset + 0u] = l2;
    l2 = (void*) _a3_arr;
    vader_struct_toolchain_ast_LambdaExpr_t* _a4_obj = (vader_struct_toolchain_ast_LambdaExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_LambdaExpr_t));
    vader_obj_header_init(_a4_obj, 623u);
    _a4_obj->f_span = l5;
    _a4_obj->f_id = INT64_C(0);
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
    int64_t l5, l6;
    void* t0 = NULL;
    void** gc_raw_roots[5] = { &l2, &l3, &l4, &l7, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_lexer_tokenize(l0, l1);
    l3 = vader_parser_new_parser(((vader_struct_vader_lexer_Lexer_t*) l2)->f_tokens, l1);
    l4 = ((vader_struct_vader_lexer_Lexer_t*) l2)->f_errors;
    l5 = ((vader_array_t*) l4)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l7 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
        vader_array_push_ref((vader_array_t*) ((vader_struct_vader_parser_Parser_t*) l3)->f_errors, l7);
        l6 = (l6 + INT64_C(1));
    }
    l4 = vader_parser_parse_program(l3);
    l7 = vader_parser_new_node_id_factory();
    vader_parser_assign_program_ids(l4, l7);
    l2 = ((vader_struct_vader_lexer_Lexer_t*) l2)->f_tokens;
    l3 = ((vader_struct_vader_parser_Parser_t*) l3)->f_errors;
    vader_struct_vader_parser_ParsedSource_t* _a1_obj = (vader_struct_vader_parser_ParsedSource_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_ParsedSource_t));
    vader_obj_header_init(_a1_obj, 1204u);
    _a1_obj->f_program = l4;
    _a1_obj->f_tokens = l2;
    _a1_obj->f_errors = l3;
    _a1_obj->f_id_factory = l7;
    t0 = (void*) _a1_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_parser_parse_stmt(void* l0) {
    void* l1 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    vader_string_t l2 = 0;
    uint8_t l3;
    bool l4;
    vader_box_t l5 = vader_box_null(), l6 = vader_box_null();
    bool t0;
    void* t1 = NULL;
    vader_string_t t2 = 0;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l5, &l6, &t3 };
    void** gc_raw_roots[5] = { &l0, &l1, &l7, &l8, &t1 };
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
    t0 = vader_parser_check(l0, (uint8_t) 78);
    if (t0) {
        t1 = vader_parser_peek_at(l0, INT32_C(1));
        if (((vader_struct_vader_lexer_Token_t*) t1)->f_kind == INT32_C(2)) {
            t1 = vader_parser_peek_at(l0, INT32_C(1));
            t2 = ((vader_struct_vader_lexer_Token_t*) t1)->f_text;
            if (t2 == 1702u) {
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
        t0 = vader_parser_check_at(l0, (uint8_t) 88, INT32_C(1));
        if (t0) {
            t0 = vader_parser_check_at(l0, (uint8_t) 20, INT32_C(2));
            if (t0) {
                l1 = vader_parser_advance(l0);
                vader_parser_advance(l0);
                l2 = ((vader_struct_vader_lexer_Token_t*) l1)->f_text;
                t1 = vader_parser_parse_for(l0, vader_box_string(317u, l2), false);
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
    }
    t0 = vader_parser_starts_let(l0);
    if (t0) {
        t1 = vader_parser_parse_any_let(l0);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_parser_check(l0, (uint8_t) 82);
    if (t0) {
        l3 = vader_parser_kind_after_bracket_group(l0);
        if (l3 == INT32_C(62)) {
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
    l1 = vader_parser_peek(l0);
    l5 = vader_parser_parse_expr(l0, INT32_C(0));
    t3 = vader_parser_match_kind(l0, (uint8_t) 62);
    if (!(t3.tag == 0u)) {
        l6 = vader_parser_parse_expr(l0, INT32_C(0));
        l7 = vader_parser_peek_at(l0, INT32_C(-1));
        t1 = vader_parser_span_of(l0, l1, l7);
        vader_struct_toolchain_ast_AssignStmt_t* _a0_obj = (vader_struct_toolchain_ast_AssignStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_AssignStmt_t));
        vader_obj_header_init(_a0_obj, 578u);
        _a0_obj->f_span = t1;
        _a0_obj->f_id = INT64_C(0);
        _a0_obj->f_target = l5;
        _a0_obj->f_value = l6;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_parser_peek(l0);
    l7 = vader_parser_compound_op(((vader_struct_vader_lexer_Token_t*) t1)->f_kind);
    t0 = ((vader_struct_vader_parser_CompoundOpResult_t*) l7)->f_matched;
    if (!(t0)) {
        vader_struct_toolchain_ast_ExprStmt_t* _a1_obj = (vader_struct_toolchain_ast_ExprStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ExprStmt_t));
        vader_obj_header_init(_a1_obj, 602u);
        _a1_obj->f_span = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, l5.payload.obj);
        _a1_obj->f_id = INT64_C(0);
        _a1_obj->f_expr = l5;
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_parser_advance(l0);
    l6 = vader_parser_parse_expr(l0, INT32_C(0));
    l8 = vader_parser_peek_at(l0, INT32_C(-1));
    l1 = vader_parser_span_of(l0, l1, l8);
    l3 = ((vader_struct_vader_parser_CompoundOpResult_t*) l7)->f_op;
    vader_struct_toolchain_ast_BinaryExpr_t* _a2_obj = (vader_struct_toolchain_ast_BinaryExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BinaryExpr_t));
    vader_obj_header_init(_a2_obj, 580u);
    _a2_obj->f_span = l1;
    _a2_obj->f_id = INT64_C(0);
    _a2_obj->f_op = l3;
    _a2_obj->f_left = l5;
    _a2_obj->f_right = l6;
    l7 = (void*) _a2_obj;
    vader_struct_toolchain_ast_AssignStmt_t* _a3_obj = (vader_struct_toolchain_ast_AssignStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_AssignStmt_t));
    vader_obj_header_init(_a3_obj, 578u);
    _a3_obj->f_span = l1;
    _a3_obj->f_id = INT64_C(0);
    _a3_obj->f_target = l5;
    _a3_obj->f_value = vader_ref_box(l7);
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
    vader_array_t* _a0_arr = vader_array_new(234u, 0u, 13u, 1582u);
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
                if (l5.tag == 317u) {
                    l4 = l5.payload.s;
                }
                l6 = ((vader_struct_vader_lexer_Token_t*) l3)->f_span;
                vader_struct_toolchain_ast_StringLitText_t* _a1_obj = (vader_struct_toolchain_ast_StringLitText_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_StringLitText_t));
                vader_obj_header_init(_a1_obj, 647u);
                _a1_obj->f_value = l4;
                _a1_obj->f_span = l6;
                _a1_obj->f_id = INT64_C(0);
                l7 = (void*) _a1_obj;
                vader_array_push_ref((vader_array_t*) l2, l7);
                continue;
            }
            if (((vader_struct_vader_lexer_Token_t*) l3)->f_kind == INT32_C(9)) {
                l8 = vader_parser_advance(l0);
                l9 = vader_parser_parse_expr(l0, INT32_C(0));
                l10 = vader_parser_match_kind(l0, (uint8_t) 10);
                if (l10.tag == 0u) {
                    l11 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, l9.payload.obj);
                } else {
                    t1 = l10.payload.obj;
                    l11 = ((vader_struct_vader_lexer_Token_t*) t1)->f_span;
                }
                l12 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l8)->f_span)->f_start;
                l13 = ((vader_struct_toolchain_span_Span_t*) l11)->f_end;
                vader_struct_toolchain_span_Span_t* _a2_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
                vader_obj_header_init(_a2_obj, 667u);
                _a2_obj->f_start = l12;
                _a2_obj->f_end = l13;
                l14 = (void*) _a2_obj;
                vader_struct_toolchain_ast_StringLitInterp_t* _a3_obj = (vader_struct_toolchain_ast_StringLitInterp_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_StringLitInterp_t));
                vader_obj_header_init(_a3_obj, 646u);
                _a3_obj->f_expr = l9;
                _a3_obj->f_span = l14;
                _a3_obj->f_id = INT64_C(0);
                l15 = (void*) _a3_obj;
                vader_array_push_ref((vader_array_t*) l2, l15);
                continue;
            }
            l16 = ((vader_struct_vader_lexer_Token_t*) l3)->f_span;
            vader_parser_error(l0, (uint8_t) 0, l16, 2080u);
            vader_parser_advance(l0);
            continue;
        }
        break;
    }
    l3 = vader_parser_match_or_peek(l0, (uint8_t) 8);
    t1 = vader_parser_span_of(l0, l1, l3);
    vader_struct_toolchain_ast_StringLitExpr_t* _a4_obj = (vader_struct_toolchain_ast_StringLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_StringLitExpr_t));
    vader_obj_header_init(_a4_obj, 645u);
    _a4_obj->f_span = t1;
    _a4_obj->f_id = INT64_C(0);
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
    void* l18 = NULL;
    void* l19 = NULL;
    void* l21 = NULL;
    uint8_t l6;
    int64_t l8, l9;
    vader_string_t l12 = 0;
    vader_string_t l13 = 0;
    vader_string_t l20 = 0;
    vader_box_t l16 = vader_box_null(), l17 = vader_box_null();
    bool t0;
    vader_string_t t1 = 0;
    vader_box_t t2 = vader_box_null();
    void* t3 = NULL;
    vader_box_t* gc_roots[3] = { &l16, &l17, &t2 };
    void** gc_raw_roots[14] = {
        &l0, &l1, &l3, &l4, &l5, &l7, &l10, &l11, &l14, &l15, &l18, &l19, &l21, &t3,
    };
    vader_string_t* gc_atom_roots[4] = { &l12, &l13, &l20, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 14u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_parser_reject_free_fn_decorators(l0, l1, 1434u, 0u);
    vader_parser_advance(l0);
    l4 = vader_parser_parse_struct_type_param_list(l0);
    vader_parser_expect(l0, (uint8_t) 84, 1354u);
    vader_parser_skip_newlines(l0);
    vader_array_t* _a0_arr = vader_array_new(50u, 0u, 13u, 649u);
    l5 = (void*) _a0_arr;
    for (;;) {
        t0 = vader_parser_check(l0, (uint8_t) 85);
        if (!(t0)) {
            t0 = vader_parser_check(l0, (uint8_t) 0);
            if (t0) break;
            l7 = vader_parser_parse_decorators(l0);
            l6 = (uint8_t) 0;
            l8 = ((vader_array_t*) l7)->length;
            l9 = INT64_C(0);
            while ((l9 < l8)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                l10 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l9);
                t1 = ((vader_struct_toolchain_ast_Decorator_t*) l10)->f_name;
                t0 = vader_parser_decorator_on(t1, (uint8_t) 3);
                if (t0) {
                    l6 = (uint8_t) 1;
                } else {
                    l11 = ((vader_struct_toolchain_ast_Decorator_t*) l10)->f_span;
                    l12 = ((vader_struct_toolchain_ast_Decorator_t*) l10)->f_name;
                    l13 = concat_3(1280u, l12, 1028u);
                    vader_parser_error(l0, (uint8_t) 8, l11, l13);
                }
                l9 = (l9 + INT64_C(1));
            }
            l14 = vader_parser_peek(l0);
            l15 = vader_parser_expect(l0, (uint8_t) 2, 1900u);
            vader_parser_expect(l0, (uint8_t) 88, 1268u);
            l16 = vader_parser_parse_type(l0);
            l17 = vader_box_obj(0u, NULL);
            t2 = vader_parser_match_kind(l0, (uint8_t) 62);
            if (!(t2.tag == 0u)) {
                vader_parser_skip_newlines(l0);
                l17 = vader_parser_parse_expr(l0, INT32_C(0));
            }
            l18 = vader_parser_peek_at(l0, INT32_C(-1));
            l19 = vader_parser_span_of(l0, l14, l18);
            l20 = ((vader_struct_vader_lexer_Token_t*) l15)->f_text;
            vader_struct_toolchain_ast_StructField_t* _a2_obj = (vader_struct_toolchain_ast_StructField_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_StructField_t));
            vader_obj_header_init(_a2_obj, 649u);
            _a2_obj->f_span = l19;
            _a2_obj->f_id = INT64_C(0);
            _a2_obj->f_name = l20;
            _a2_obj->f_ty = l16;
            _a2_obj->f_visibility = l6;
            _a2_obj->f_default_v = l17;
            l21 = (void*) _a2_obj;
            vader_array_push_ref((vader_array_t*) l5, l21);
            t0 = vader_parser_check(l0, (uint8_t) 85);
            if (t0) {
                continue;
            }
            vader_parser_match_kind(l0, (uint8_t) 86);
            vader_parser_skip_newlines(l0);
            continue;
        }
        break;
    }
    l7 = vader_parser_expect(l0, (uint8_t) 85, 1362u);
    l7 = vader_parser_span_of(l0, l3, l7);
    l12 = ((vader_struct_vader_lexer_Token_t*) l3)->f_text;
    l10 = ((vader_struct_vader_lexer_Token_t*) l3)->f_span;
    vader_struct_toolchain_ast_StructDecl_t* _a3_obj = (vader_struct_toolchain_ast_StructDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_StructDecl_t));
    vader_obj_header_init(_a3_obj, 648u);
    _a3_obj->f_span = l7;
    _a3_obj->f_id = INT64_C(0);
    _a3_obj->f_name = l12;
    _a3_obj->f_name_span = l10;
    _a3_obj->f_visibility = l2;
    _a3_obj->f_type_params = l4;
    _a3_obj->f_fields = l5;
    _a3_obj->f_decorators = l1;
    t3 = (void*) _a3_obj;
    { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_struct_lit_fields(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    bool l2;
    vader_box_t l4 = vader_box_null(), l8 = vader_box_null();
    vader_string_t l11 = 0;
    bool t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[3] = { &l4, &l8, &t1 };
    void** gc_raw_roots[11] = { &l0, &l1, &l3, &l5, &l6, &l7, &l9, &l10, &l12, &l13, &t2 };
    vader_string_t* gc_atom_roots[1] = { &l11 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 11u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(235u, 0u, 13u, 1583u);
    l1 = (void*) _a0_arr;
    l2 = false;
    vader_parser_skip_newlines(l0);
    for (;;) {
        t0 = vader_parser_check(l0, (uint8_t) 85);
        if (!(t0)) {
            t0 = vader_parser_check(l0, (uint8_t) 0);
            if (t0) break;
            l3 = vader_parser_peek(l0);
            t1 = vader_parser_match_kind(l0, (uint8_t) 75);
            if (t1.tag == 0u) {
                vader_parser_expect(l0, (uint8_t) 87, 1262u);
                l7 = vader_parser_expect(l0, (uint8_t) 2, 2559u);
                vader_parser_expect(l0, (uint8_t) 62, 1273u);
                l8 = vader_parser_parse_expr(l0, INT32_C(0));
                l9 = vader_parser_peek_at(l0, INT32_C(-1));
                l10 = vader_parser_span_of(l0, l3, l9);
                l11 = ((vader_struct_vader_lexer_Token_t*) l7)->f_text;
                l12 = ((vader_struct_vader_lexer_Token_t*) l7)->f_span;
                vader_struct_toolchain_ast_StructLitField_t* _a1_obj = (vader_struct_toolchain_ast_StructLitField_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_StructLitField_t));
                vader_obj_header_init(_a1_obj, 651u);
                _a1_obj->f_span = l10;
                _a1_obj->f_id = INT64_C(0);
                _a1_obj->f_name = l11;
                _a1_obj->f_name_span = l12;
                _a1_obj->f_value = l8;
                l13 = (void*) _a1_obj;
                vader_array_push_ref((vader_array_t*) l1, l13);
            } else {
                l4 = vader_parser_parse_expr(l0, INT32_C(0));
                l5 = vader_parser_peek_at(l0, INT32_C(-1));
                t2 = vader_parser_span_of(l0, l3, l5);
                vader_struct_toolchain_ast_StructLitSpread_t* _a2_obj = (vader_struct_toolchain_ast_StructLitSpread_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_StructLitSpread_t));
                vader_obj_header_init(_a2_obj, 652u);
                _a2_obj->f_span = t2;
                _a2_obj->f_id = INT64_C(0);
                _a2_obj->f_expr = l4;
                l6 = (void*) _a2_obj;
                vader_array_push_ref((vader_array_t*) l1, l6);
            }
            vader_parser_skip_newlines(l0);
            t1 = vader_parser_match_kind(l0, (uint8_t) 86);
            if (t1.tag == 0u) break;
            vader_parser_skip_newlines(l0);
            l2 = vader_parser_check(l0, (uint8_t) 85);
            continue;
        }
        break;
    }
    vader_parser_skip_newlines(l0);
    vader_struct_vader_parser_CommaList__Any_t* _a3_obj = (vader_struct_vader_parser_CommaList__Any_t*) vader_gc_alloc(sizeof(vader_struct_vader_parser_CommaList__Any_t));
    vader_obj_header_init(_a3_obj, 1192u);
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
    void* l12 = NULL;
    void* l13 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    vader_string_t l5 = 0;
    vader_string_t l10 = 0;
    vader_string_t l14 = 0;
    vader_box_t l7 = vader_box_null();
    bool l8;
    bool t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l7, &t2 };
    void** gc_raw_roots[13] = {
        &l0, &l1, &l2, &l3, &l4, &l6, &l9, &l11, &l12, &l13, &l15, &l16, &t1,
    };
    vader_string_t* gc_atom_roots[3] = { &l5, &l10, &l14 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 13u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_expect(l0, (uint8_t) 84, 1355u);
    vader_parser_skip_newlines(l0);
    vader_array_t* _a0_arr = vader_array_new(52u, 0u, 13u, 654u);
    l2 = (void*) _a0_arr;
    for (;;) {
        t0 = vader_parser_check(l0, (uint8_t) 85);
        if (!(t0)) {
            t0 = vader_parser_check(l0, (uint8_t) 0);
            if (t0) break;
            l3 = vader_parser_peek(l0);
            l4 = vader_parser_expect(l0, (uint8_t) 2, 1903u);
            l5 = ((vader_struct_vader_lexer_Token_t*) l4)->f_text;
            l6 = ((vader_struct_vader_lexer_Token_t*) l4)->f_span;
            vader_struct_toolchain_ast_PatternBinding_t* _a1_obj = (vader_struct_toolchain_ast_PatternBinding_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_PatternBinding_t));
            vader_obj_header_init(_a1_obj, 634u);
            _a1_obj->f_name = l5;
            _a1_obj->f_span = l6;
            _a1_obj->f_id = INT64_C(0);
            t1 = (void*) _a1_obj;
            l7 = vader_ref_box(t1);
            t2 = vader_parser_match_kind(l0, (uint8_t) 88);
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
                    vader_obj_header_init(_a2_obj, 634u);
                    _a2_obj->f_name = l10;
                    _a2_obj->f_span = l11;
                    _a2_obj->f_id = INT64_C(0);
                    t1 = (void*) _a2_obj;
                    l7 = vader_ref_box(t1);
                } else {
                    t2 = vader_parser_parse_expr(l0, INT32_C(0));
                    vader_struct_toolchain_ast_PatternLiteral_t* _a3_obj = (vader_struct_toolchain_ast_PatternLiteral_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_PatternLiteral_t));
                    vader_obj_header_init(_a3_obj, 635u);
                    _a3_obj->f_value = t2;
                    t1 = (void*) _a3_obj;
                    l7 = vader_ref_box(t1);
                }
            }
            l12 = vader_parser_peek_at(l0, INT32_C(-1));
            l13 = vader_parser_span_of(l0, l3, l12);
            l14 = ((vader_struct_vader_lexer_Token_t*) l4)->f_text;
            l15 = ((vader_struct_vader_lexer_Token_t*) l4)->f_span;
            vader_struct_toolchain_ast_StructPatternField_t* _a4_obj = (vader_struct_toolchain_ast_StructPatternField_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_StructPatternField_t));
            vader_obj_header_init(_a4_obj, 654u);
            _a4_obj->f_span = l13;
            _a4_obj->f_id = INT64_C(0);
            _a4_obj->f_name = l14;
            _a4_obj->f_name_span = l15;
            _a4_obj->f_value = l7;
            l16 = (void*) _a4_obj;
            vader_array_push_ref((vader_array_t*) l2, l16);
            vader_parser_skip_newlines(l0);
            t2 = vader_parser_match_kind(l0, (uint8_t) 86);
            if (t2.tag == 0u) break;
            vader_parser_skip_newlines(l0);
            continue;
        }
        break;
    }
    l3 = vader_parser_expect(l0, (uint8_t) 85, 1364u);
    l1 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l1)->f_span)->f_start;
    l3 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l3)->f_span)->f_end;
    vader_struct_toolchain_span_Span_t* _a5_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a5_obj, 667u);
    _a5_obj->f_start = l1;
    _a5_obj->f_end = l3;
    t1 = (void*) _a5_obj;
    vader_struct_toolchain_ast_StructPattern_t* _a6_obj = (vader_struct_toolchain_ast_StructPattern_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_StructPattern_t));
    vader_obj_header_init(_a6_obj, 653u);
    _a6_obj->f_span = t1;
    _a6_obj->f_id = INT64_C(0);
    _a6_obj->f_fields = l2;
    t1 = (void*) _a6_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_struct_type_param_list(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l18 = NULL;
    void* l19 = NULL;
    void* l21 = NULL;
    bool l2, l17;
    vader_box_t l5 = vader_box_null(), l12 = vader_box_null();
    vader_string_t l6 = 0;
    vader_string_t l7 = 0;
    vader_string_t l8 = 0;
    vader_string_t l9 = 0;
    vader_string_t l15 = 0;
    vader_string_t l16 = 0;
    vader_string_t l20 = 0;
    bool t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    int64_t t3;
    vader_string_t t4 = 0;
    vader_box_t* gc_roots[3] = { &l5, &l12, &t2 };
    void** gc_raw_roots[12] = { &l0, &l1, &l3, &l4, &l10, &l11, &l13, &l14, &l18, &l19, &l21, &t1 };
    vader_string_t* gc_atom_roots[8] = { &l6, &l7, &l8, &l9, &l15, &l16, &l20, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 8u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_parser_check(l0, (uint8_t) 52);
    if (t0) {
        t1 = vader_parser_parse_angle_type_params(l0);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_parser_match_kind(l0, (uint8_t) 80);
    if (t2.tag == 0u) {
        vader_array_t* _a0_arr = vader_array_new(54u, 0u, 13u, 658u);
        t1 = (void*) _a0_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a1_arr = vader_array_new(54u, 0u, 13u, 658u);
    l1 = (void*) _a1_arr;
    vader_parser_skip_newlines(l0);
    for (;;) {
        t0 = vader_parser_check(l0, (uint8_t) 81);
        if (!(t0)) {
            t0 = vader_parser_check(l0, (uint8_t) 0);
            if (t0) break;
            t3 = ((vader_array_t*) l1)->length;
            if ((t3 > INT64_C(0))) {
                t2 = vader_parser_match_kind(l0, (uint8_t) 86);
                if (t2.tag == 0u) break;
                vader_parser_skip_newlines(l0);
                t0 = vader_parser_check(l0, (uint8_t) 81);
                if (t0) break;
            }
            t2 = vader_parser_match_kind(l0, (uint8_t) 79);
            l2 = !(t2.tag == 0u);
            l3 = vader_parser_peek(l0);
            l4 = vader_parser_expect(l0, (uint8_t) 2, 2648u);
            l5 = vader_box_obj(0u, NULL);
            t2 = vader_parser_match_kind(l0, (uint8_t) 88);
            if (!(t2.tag == 0u)) {
                l5 = vader_parser_parse_type(l0);
            }
            if (l2) {
                l12 = l5;
                if (!(l12.tag == 0u)) {
                    if (l12.tag == 610u) {
                        t1 = l12.payload.obj;
                        t4 = ((vader_struct_toolchain_ast_IdentExpr_t*) t1)->f_name;
                        if (t4 == 2643u) {
                            l13 = vader_parser_peek_at(l0, INT32_C(-1));
                            l14 = vader_parser_span_of(l0, l3, l13);
                            l15 = ((vader_struct_vader_lexer_Token_t*) l4)->f_text;
                            l16 = concat_3(990u, l15, 1088u);
                            vader_parser_error(l0, (uint8_t) 11, l14, l16);
                            l5 = vader_box_obj(0u, NULL);
                        }
                    }
                }
            } else {
                if (l5.tag == 0u) {
                    l7 = ((vader_struct_vader_lexer_Token_t*) l4)->f_text;
                    l8 = ((vader_struct_vader_lexer_Token_t*) l4)->f_text;
                    l6 = concat_5(990u, l7, 1144u, l8, 990u);
                } else {
                    l9 = ((vader_struct_vader_lexer_Token_t*) l4)->f_text;
                    l6 = concat_3(990u, l9, 1143u);
                }
                l10 = vader_parser_peek_at(l0, INT32_C(-1));
                l11 = vader_parser_span_of(l0, l3, l10);
                vader_parser_error(l0, (uint8_t) 10, l11, l6);
            }
            l17 = !(l5.tag == 0u);
            l18 = vader_parser_peek_at(l0, INT32_C(-1));
            l19 = vader_parser_span_of(l0, l3, l18);
            l20 = ((vader_struct_vader_lexer_Token_t*) l4)->f_text;
            vader_struct_toolchain_ast_TypeParam_t* _a2_obj = (vader_struct_toolchain_ast_TypeParam_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_TypeParam_t));
            vader_obj_header_init(_a2_obj, 658u);
            _a2_obj->f_span = l19;
            _a2_obj->f_id = INT64_C(0);
            _a2_obj->f_name = l20;
            _a2_obj->f_bound = l5;
            _a2_obj->f_default_v = vader_box_obj(0u, NULL);
            _a2_obj->f_is_comptime_value = l17;
            l21 = (void*) _a2_obj;
            vader_array_push_ref((vader_array_t*) l1, l21);
            continue;
        }
        break;
    }
    vader_parser_expect(l0, (uint8_t) 81, 1240u);
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_trait_decl(void* l0, void* l1, uint8_t l2, void* l3) {
    void* l4 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l9 = NULL;
    vader_box_t l5 = vader_box_null(), l10 = vader_box_null();
    vader_string_t l8 = 0;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    bool t2;
    vader_box_t* gc_roots[3] = { &l5, &l10, &t0 };
    void** gc_raw_roots[8] = { &l0, &l1, &l3, &l4, &l6, &l7, &l9, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l8 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_parser_reject_free_fn_decorators(l0, l1, 1435u, 0u);
    vader_parser_reject_c_decorators(l0, l1, 1435u);
    vader_parser_advance(l0);
    l4 = vader_parser_parse_struct_type_param_list(l0);
    l5 = vader_box_obj(0u, NULL);
    vader_array_t* _a0_arr = vader_array_new(42u, 0u, 13u, 605u);
    l6 = (void*) _a0_arr;
    t0 = vader_parser_match_kind(l0, (uint8_t) 62);
    if (!(t0.tag == 0u)) {
        l5 = vader_parser_parse_type(l0);
        l7 = vader_parser_peek_at(l0, INT32_C(-1));
        l7 = vader_parser_span_of(l0, l3, l7);
        l8 = ((vader_struct_vader_lexer_Token_t*) l3)->f_text;
        l9 = ((vader_struct_vader_lexer_Token_t*) l3)->f_span;
        vader_struct_toolchain_ast_TraitDecl_t* _a1_obj = (vader_struct_toolchain_ast_TraitDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_TraitDecl_t));
        vader_obj_header_init(_a1_obj, 655u);
        _a1_obj->f_span = l7;
        _a1_obj->f_id = INT64_C(0);
        _a1_obj->f_name = l8;
        _a1_obj->f_name_span = l9;
        _a1_obj->f_visibility = l2;
        _a1_obj->f_type_params = l4;
        _a1_obj->f_requires = l5;
        _a1_obj->f_members = l6;
        _a1_obj->f_decorators = l1;
        t1 = (void*) _a1_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_parser_match_kind(l0, (uint8_t) 88);
    if (!(t0.tag == 0u)) {
        l5 = vader_parser_parse_type(l0);
    }
    vader_parser_expect(l0, (uint8_t) 84, 1356u);
    vader_parser_skip_newlines(l0);
    for (;;) {
        t2 = vader_parser_check(l0, (uint8_t) 85);
        if (!(t2)) {
            t2 = vader_parser_check(l0, (uint8_t) 0);
            if (t2) break;
            l10 = vader_parser_parse_fn_decl_inside_trait(l0);
            if (l10.tag == 605u) {
                l7 = l10.payload.obj;
                vader_array_push_ref((vader_array_t*) l6, l7);
            } else if (!(l10.tag == 0u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            vader_parser_skip_newlines(l0);
            continue;
        }
        break;
    }
    l7 = vader_parser_expect(l0, (uint8_t) 85, 1365u);
    l7 = vader_parser_span_of(l0, l3, l7);
    l8 = ((vader_struct_vader_lexer_Token_t*) l3)->f_text;
    l9 = ((vader_struct_vader_lexer_Token_t*) l3)->f_span;
    vader_struct_toolchain_ast_TraitDecl_t* _a2_obj = (vader_struct_toolchain_ast_TraitDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_TraitDecl_t));
    vader_obj_header_init(_a2_obj, 655u);
    _a2_obj->f_span = l7;
    _a2_obj->f_id = INT64_C(0);
    _a2_obj->f_name = l8;
    _a2_obj->f_name_span = l9;
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
    t0 = vader_parser_check(l0, (uint8_t) 88);
    if (t0) {
        vader_parser_advance(l0);
        l3 = vader_parser_parse_type(l0);
        t1 = vader_parser_peek(l0);
        if (((vader_struct_vader_lexer_Token_t*) t1)->f_kind == INT32_C(88)) {
            vader_parser_advance(l0);
            l4 = false;
        } else {
            vader_parser_expect(l0, (uint8_t) 62, 1274u);
        }
    } else {
        l5 = vader_parser_peek(l0);
        if (((vader_struct_vader_lexer_Token_t*) l5)->f_kind == INT32_C(71)) {
            l6 = true;
        } else {
            l6 = ((vader_struct_vader_lexer_Token_t*) l5)->f_kind == INT32_C(72);
        }
        if (l6) {
            vader_parser_advance(l0);
            l4 = ((vader_struct_vader_lexer_Token_t*) l5)->f_kind == INT32_C(72);
        } else {
            vader_parser_expect(l0, (uint8_t) 72, 1267u);
        }
    }
    l7 = vader_parser_parse_expr(l0, INT32_C(0));
    l5 = vader_parser_peek_at(l0, INT32_C(-1));
    t1 = vader_parser_span_of(l0, l1, l5);
    vader_struct_toolchain_ast_LetStmt_t* _a0_obj = (vader_struct_toolchain_ast_LetStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_LetStmt_t));
    vader_obj_header_init(_a0_obj, 624u);
    _a0_obj->f_span = t1;
    _a0_obj->f_id = INT64_C(0);
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
    l1 = vader_chk_add(i32, t0, INT32_C(1));
    ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth = l1;
    t0 = ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth;
    if ((t0 > INT32_C(256))) {
        t0 = ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth;
        l1 = vader_chk_sub(i32, t0, INT32_C(1));
        ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth = l1;
        t1 = vader_parser_peek(l0);
        l2 = ((vader_struct_vader_lexer_Token_t*) t1)->f_span;
        vader_parser_report_nesting_too_deep(l0, 2643u);
        t1 = vader_parser_ident_expr(l2, 481u);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_parser_match_kind(l0, (uint8_t) 45);
    vader_parser_reject_removed_const(l0);
    l3 = vader_parser_parse_type_intersection(l0);
    t2 = vader_parser_check(l0, (uint8_t) 45);
    if (t2) {
        l2 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, l3.payload.obj);
        for (;;) {
            t3 = vader_parser_match_kind(l0, (uint8_t) 45);
            if (!(t3.tag == 0u)) {
                vader_parser_reject_removed_const(l0);
                l4 = vader_parser_parse_type_intersection(l0);
                l5 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, l4.payload.obj);
                l6 = ((vader_struct_toolchain_span_Span_t*) l2)->f_start;
                l7 = ((vader_struct_toolchain_span_Span_t*) l5)->f_end;
                vader_struct_toolchain_span_Span_t* _a0_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
                vader_obj_header_init(_a0_obj, 667u);
                _a0_obj->f_start = l6;
                _a0_obj->f_end = l7;
                t1 = (void*) _a0_obj;
                vader_struct_toolchain_ast_BinaryExpr_t* _a1_obj = (vader_struct_toolchain_ast_BinaryExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BinaryExpr_t));
                vader_obj_header_init(_a1_obj, 580u);
                _a1_obj->f_span = t1;
                _a1_obj->f_id = INT64_C(0);
                _a1_obj->f_op = (uint8_t) 8;
                _a1_obj->f_left = l3;
                _a1_obj->f_right = l4;
                t1 = (void*) _a1_obj;
                l3 = vader_ref_box(t1);
                continue;
            }
            break;
        }
    }
    t0 = ((vader_struct_vader_parser_Parser_t*) l0)->f_expr_depth;
    l1 = vader_chk_sub(i32, t0, INT32_C(1));
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
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[3] = { &l1, &l3, &t1 };
    void** gc_raw_roots[6] = { &l0, &l2, &l4, &l5, &l6, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_parse_type_postfix(l0);
    t0 = vader_parser_check(l0, (uint8_t) 44);
    if (t0) {
        l2 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, l1.payload.obj);
        for (;;) {
            t1 = vader_parser_match_kind(l0, (uint8_t) 44);
            if (!(t1.tag == 0u)) {
                l3 = vader_parser_parse_type_postfix(l0);
                l4 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, l3.payload.obj);
                l5 = ((vader_struct_toolchain_span_Span_t*) l2)->f_start;
                l6 = ((vader_struct_toolchain_span_Span_t*) l4)->f_end;
                vader_struct_toolchain_span_Span_t* _a0_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
                vader_obj_header_init(_a0_obj, 667u);
                _a0_obj->f_start = l5;
                _a0_obj->f_end = l6;
                t2 = (void*) _a0_obj;
                vader_struct_toolchain_ast_BinaryExpr_t* _a1_obj = (vader_struct_toolchain_ast_BinaryExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BinaryExpr_t));
                vader_obj_header_init(_a1_obj, 580u);
                _a1_obj->f_span = t2;
                _a1_obj->f_id = INT64_C(0);
                _a1_obj->f_op = (uint8_t) 7;
                _a1_obj->f_left = l1;
                _a1_obj->f_right = l3;
                t2 = (void*) _a1_obj;
                l1 = vader_ref_box(t2);
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
    vader_array_t* _a0_arr = vader_array_new(227u, 0u, 13u, 1503u);
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
            vader_array_push_ref((vader_array_t*) l1, l2.payload.obj);
            vader_parser_skip_newlines(l0);
            t1 = vader_parser_match_kind(l0, (uint8_t) 86);
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
    vader_parser_expect(l0, (uint8_t) 54, 1275u);
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_parser_parse_type_postfix(void* l0) {
    vader_box_t l1 = vader_box_null();
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    bool t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[5] = { &l0, &l2, &l3, &l4, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_parse_type_primary(l0);
    for (;;) {
        t0 = vader_parser_check(l0, (uint8_t) 82);
        if (t0) {
            t0 = vader_parser_check_at(l0, (uint8_t) 83, INT32_C(1));
            if (!(t0)) {
                break;
            }
            vader_parser_advance(l0);
            l2 = vader_parser_advance(l0);
            l3 = ((vader_struct_toolchain_span_Span_t*) VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, l1.payload.obj))->f_start;
            l4 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l2)->f_span)->f_end;
            vader_struct_toolchain_span_Span_t* _a0_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
            vader_obj_header_init(_a0_obj, 667u);
            _a0_obj->f_start = l3;
            _a0_obj->f_end = l4;
            t1 = (void*) _a0_obj;
            vader_struct_toolchain_ast_ArrayTypeExpr_t* _a1_obj = (vader_struct_toolchain_ast_ArrayTypeExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ArrayTypeExpr_t));
            vader_obj_header_init(_a1_obj, 576u);
            _a1_obj->f_span = t1;
            _a1_obj->f_id = INT64_C(0);
            _a1_obj->f_element = l1;
            t1 = (void*) _a1_obj;
            l1 = vader_ref_box(t1);
            continue;
        }
        break;
    }
    { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_parser_parse_type_primary(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    vader_string_t l4 = 0;
    vader_box_t l5 = vader_box_null();
    bool l10, l11;
    void* t0 = NULL;
    bool t1;
    vader_box_t t2 = vader_box_null();
    int64_t t3;
    vader_box_t* gc_roots[2] = { &l5, &t2 };
    void** gc_raw_roots[9] = { &l0, &l1, &l2, &l3, &l6, &l7, &l8, &l9, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_peek(l0);
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(79)) {
        vader_parser_advance(l0);
        l2 = vader_parser_expect(l0, (uint8_t) 2, 2649u);
        l3 = vader_parser_span_of(l0, l1, l2);
        l4 = ((vader_struct_vader_lexer_Token_t*) l2)->f_text;
        vader_struct_toolchain_ast_IdentExpr_t* _a0_obj = (vader_struct_toolchain_ast_IdentExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_IdentExpr_t));
        vader_obj_header_init(_a0_obj, 610u);
        _a0_obj->f_span = l3;
        _a0_obj->f_id = INT64_C(0);
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
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(80)) {
        vader_parser_advance(l0);
        vader_parser_skip_newlines(l0);
        l5 = vader_parser_parse_type(l0);
        vader_parser_skip_newlines(l0);
        vader_parser_expect(l0, (uint8_t) 81, 1239u);
        { vader_box_t __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(82)) {
        l2 = vader_parser_advance(l0);
        vader_array_t* _a1_arr = vader_array_new(227u, 0u, 13u, 1503u);
        l3 = (void*) _a1_arr;
        vader_parser_skip_newlines(l0);
        t1 = vader_parser_check(l0, (uint8_t) 83);
        if (t1) {
            l6 = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
            vader_parser_error(l0, (uint8_t) 3, l6, 1785u);
            l6 = vader_parser_advance(l0);
            t0 = vader_parser_span_of(l0, l2, l6);
            vader_struct_toolchain_ast_SeqLitExpr_t* _a2_obj = (vader_struct_toolchain_ast_SeqLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_SeqLitExpr_t));
            vader_obj_header_init(_a2_obj, 643u);
            _a2_obj->f_span = t0;
            _a2_obj->f_id = INT64_C(0);
            _a2_obj->f_elements = l3;
            _a2_obj->f_trailing_comma = false;
            t0 = (void*) _a2_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l5 = vader_parser_parse_type(l0);
        vader_array_push_ref((vader_array_t*) l3, l5.payload.obj);
        vader_parser_skip_newlines(l0);
        for (;;) {
            t2 = vader_parser_match_kind(l0, (uint8_t) 86);
            if (!(t2.tag == 0u)) {
                vader_parser_skip_newlines(l0);
                t1 = vader_parser_check(l0, (uint8_t) 83);
                if (t1) break;
                l5 = vader_parser_parse_type(l0);
                vader_array_push_ref((vader_array_t*) l3, l5.payload.obj);
                vader_parser_skip_newlines(l0);
                continue;
            }
            break;
        }
        l6 = vader_parser_expect(l0, (uint8_t) 83, 1322u);
        t3 = ((vader_array_t*) l3)->length;
        if (!(t3 == INT64_C(1))) {
            t0 = vader_parser_span_of(l0, l2, l6);
            vader_struct_toolchain_ast_SeqLitExpr_t* _a3_obj = (vader_struct_toolchain_ast_SeqLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_SeqLitExpr_t));
            vader_obj_header_init(_a3_obj, 643u);
            _a3_obj->f_span = t0;
            _a3_obj->f_id = INT64_C(0);
            _a3_obj->f_elements = l3;
            _a3_obj->f_trailing_comma = false;
            t0 = (void*) _a3_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = vader_parser_span_of(l0, l2, l6);
        vader_parser_error(l0, (uint8_t) 12, l7, 2744u);
        l2 = vader_parser_span_of(l0, l2, l6);
        vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        l5 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) INT32_C(0));
        vader_struct_toolchain_ast_ArrayTypeExpr_t* _a5_obj = (vader_struct_toolchain_ast_ArrayTypeExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ArrayTypeExpr_t));
        vader_obj_header_init(_a5_obj, 576u);
        _a5_obj->f_span = l2;
        _a5_obj->f_id = INT64_C(0);
        _a5_obj->f_element = l5;
        t0 = (void*) _a5_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(33)) {
        vader_parser_advance(l0);
        t0 = vader_parser_ident_expr(((vader_struct_vader_lexer_Token_t*) l1)->f_span, 2324u);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(2)) {
        l2 = vader_parser_advance(l0);
        l3 = ((vader_struct_vader_lexer_Token_t*) l2)->f_span;
        l4 = ((vader_struct_vader_lexer_Token_t*) l2)->f_text;
        t0 = vader_parser_ident_expr(l3, l4);
        l5 = vader_ref_box(t0);
        for (;;) {
            t1 = vader_parser_check(l0, (uint8_t) 87);
            if (t1) {
                vader_parser_advance(l0);
                l3 = vader_parser_expect(l0, (uint8_t) 2, 1902u);
                l6 = ((vader_struct_toolchain_span_Span_t*) VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, l5.payload.obj))->f_start;
                l7 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_lexer_Token_t*) l3)->f_span)->f_end;
                vader_struct_toolchain_span_Span_t* _a6_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
                vader_obj_header_init(_a6_obj, 667u);
                _a6_obj->f_start = l6;
                _a6_obj->f_end = l7;
                l8 = (void*) _a6_obj;
                l4 = ((vader_struct_vader_lexer_Token_t*) l3)->f_text;
                l9 = ((vader_struct_vader_lexer_Token_t*) l3)->f_span;
                vader_struct_toolchain_ast_FieldExpr_t* _a7_obj = (vader_struct_toolchain_ast_FieldExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FieldExpr_t));
                vader_obj_header_init(_a7_obj, 603u);
                _a7_obj->f_span = l8;
                _a7_obj->f_id = INT64_C(0);
                _a7_obj->f_target = l5;
                _a7_obj->f_field = l4;
                _a7_obj->f_field_span = l9;
                _a7_obj->f_is_numeric = false;
                t0 = (void*) _a7_obj;
                l5 = vader_ref_box(t0);
                continue;
            }
            break;
        }
        t2 = vader_parser_match_kind(l0, (uint8_t) 52);
        if (!(t2.tag == 0u)) {
            l3 = vader_parser_parse_type_list_until_angle(l0);
            l6 = vader_parser_peek_at(l0, INT32_C(-1));
            t0 = vader_parser_span_of(l0, l2, l6);
            vader_struct_toolchain_ast_GenericInstExpr_t* _a8_obj = (vader_struct_toolchain_ast_GenericInstExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_GenericInstExpr_t));
            vader_obj_header_init(_a8_obj, 609u);
            _a8_obj->f_span = t0;
            _a8_obj->f_id = INT64_C(0);
            _a8_obj->f_callee = l5;
            _a8_obj->f_type_args = l3;
            t0 = (void*) _a8_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_box_t __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(3)) {
        l10 = true;
    } else {
        if (((vader_struct_vader_lexer_Token_t*) l1)->f_kind == INT32_C(37)) {
            t0 = vader_parser_peek_at(l0, INT32_C(1));
            l11 = ((vader_struct_vader_lexer_Token_t*) t0)->f_kind == INT32_C(3);
        } else {
            l11 = false;
        }
        l10 = l11;
    }
    if (!(l10)) {
        l2 = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
        l4 = vader_parser_describe_token(l1);
        l4 = concat_2(1976u, l4);
        vader_parser_error(l0, (uint8_t) 3, l2, l4);
        vader_parser_advance(l0);
        t0 = vader_parser_ident_expr(((vader_struct_vader_lexer_Token_t*) l1)->f_span, 481u);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_parser_parse_range_type(l0);
    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_typed_const_decl(void* l0, void* l1, uint8_t l2) {
    void* l3 = NULL;
    void* l6 = NULL;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    vader_string_t l7 = 0;
    bool t0;
    void* t1 = NULL;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[2] = { &l4, &l5 };
    void** gc_raw_roots[5] = { &l0, &l1, &l3, &l6, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l7, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_parser_reject_free_fn_decorators(l0, l1, 1389u, 59u);
    l3 = vader_parser_advance(l0);
    vader_parser_advance(l0);
    l4 = vader_parser_parse_type(l0);
    vader_parser_expect(l0, (uint8_t) 88, 1269u);
    t0 = vader_parser_check(l0, (uint8_t) 78);
    if (t0) {
        t1 = vader_parser_peek_at(l0, INT32_C(1));
        if (((vader_struct_vader_lexer_Token_t*) t1)->f_kind == INT32_C(2)) {
            t1 = vader_parser_peek_at(l0, INT32_C(1));
            t2 = ((vader_struct_vader_lexer_Token_t*) t1)->f_text;
            if (t2 == 1702u) {
                t1 = vader_parser_desugar_comptime_const(l0, l1, l2, l3, l4);
                { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
    }
    l5 = vader_parser_parse_expr(l0, INT32_C(0));
    l6 = vader_parser_peek_at(l0, INT32_C(-1));
    l6 = vader_parser_span_of(l0, l3, l6);
    l7 = ((vader_struct_vader_lexer_Token_t*) l3)->f_text;
    l3 = ((vader_struct_vader_lexer_Token_t*) l3)->f_span;
    vader_struct_toolchain_ast_ConstDecl_t* _a0_obj = (vader_struct_toolchain_ast_ConstDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ConstDecl_t));
    vader_obj_header_init(_a0_obj, 588u);
    _a0_obj->f_span = l6;
    _a0_obj->f_id = INT64_C(0);
    _a0_obj->f_name = l7;
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
    if (((vader_struct_vader_lexer_Token_t*) l3)->f_kind == INT32_C(88)) {
        vader_parser_advance(l0);
        l4 = false;
    } else {
        vader_parser_expect(l0, (uint8_t) 62, 1274u);
    }
    l5 = vader_parser_parse_expr(l0, INT32_C(0));
    l3 = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
    l6 = ((vader_struct_vader_lexer_Token_t*) l1)->f_text;
    l7 = ((vader_struct_vader_lexer_Token_t*) l1)->f_span;
    vader_struct_toolchain_ast_SimpleBinding_t* _a0_obj = (vader_struct_toolchain_ast_SimpleBinding_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_SimpleBinding_t));
    vader_obj_header_init(_a0_obj, 644u);
    _a0_obj->f_span = l3;
    _a0_obj->f_id = INT64_C(0);
    _a0_obj->f_name = l6;
    _a0_obj->f_name_span = l7;
    l3 = (void*) _a0_obj;
    l7 = vader_parser_peek_at(l0, INT32_C(-1));
    t0 = vader_parser_span_of(l0, l1, l7);
    vader_struct_toolchain_ast_LetStmt_t* _a1_obj = (vader_struct_toolchain_ast_LetStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_LetStmt_t));
    vader_obj_header_init(_a1_obj, 624u);
    _a1_obj->f_span = t0;
    _a1_obj->f_id = INT64_C(0);
    _a1_obj->f_mutable = l4;
    _a1_obj->f_binding = vader_ref_box(l3);
    _a1_obj->f_ty = l2;
    _a1_obj->f_value = l5;
    t0 = (void*) _a1_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_parse_yield(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    vader_box_t l2 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_parser_advance(l0);
    l2 = vader_parser_parse_expr(l0, INT32_C(0));
    l3 = vader_parser_peek_at(l0, INT32_C(-1));
    t0 = vader_parser_span_of(l0, l1, l3);
    vader_struct_toolchain_ast_YieldStmt_t* _a0_obj = (vader_struct_toolchain_ast_YieldStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_YieldStmt_t));
    vader_obj_header_init(_a0_obj, 665u);
    _a0_obj->f_span = t0;
    _a0_obj->f_id = INT64_C(0);
    _a0_obj->f_value = l2;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_parser_peek(void* l0) {
    vader_box_t l1;
    int32_t l2, l4;
    void* l3;
    void* t0;
    int64_t t1;
    int32_t t2;
    l1 = ((vader_struct_vader_parser_Parser_t*) l0)->f_shr_pending_half;
    if (!(l1.tag == 0u)) {
        t0 = l1.payload.obj;
        return t0;
    }
    t1 = ((vader_array_t*) ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens)->length;
    l2 = ((int32_t) (int64_t) t1);
    t2 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pos;
    if (!((t2 < l2))) {
        l3 = ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens;
        l4 = vader_chk_sub(i32, l2, INT32_C(1));
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        return t0;
    }
    l3 = ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens;
    l2 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pos;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
    t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l2);
    return t0;
}

static void* vader_parser_peek_at(void* l0, int32_t l1) {
    int32_t l2, l3;
    void* l4;
    int64_t t0;
    int32_t t1;
    void* t2;
    t0 = ((vader_array_t*) ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens)->length;
    l2 = ((int32_t) (int64_t) t0);
    t1 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pos;
    l3 = vader_chk_add(i32, t1, l1);
    if ((l3 < INT32_C(0))) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
        t2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
        return t2;
    }
    if (!((l3 < l2))) {
        l4 = ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens;
        l2 = vader_chk_sub(i32, l2, INT32_C(1));
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
        t2 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l2);
        return t2;
    }
    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
    t2 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l3);
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
            l1 = vader_chk_add(i32, l1, INT32_C(1));
            continue;
        }
        break;
    }
    l2 = true;
    while (l2) {
        t0 = vader_parser_peek_at(l0, l1);
        l3 = ((vader_struct_vader_lexer_Token_t*) t0)->f_kind;
        if (l3 == INT32_C(78)) {
            l1 = vader_chk_add(i32, l1, INT32_C(1));
            t0 = vader_parser_peek_at(l0, l1);
            if (((vader_struct_vader_lexer_Token_t*) t0)->f_kind == INT32_C(2)) {
                l1 = vader_chk_add(i32, l1, INT32_C(1));
            }
            t0 = vader_parser_peek_at(l0, l1);
            if (((vader_struct_vader_lexer_Token_t*) t0)->f_kind == INT32_C(80)) {
                l4 = INT32_C(1);
                l1 = vader_chk_add(i32, l1, INT32_C(1));
                while ((l4 > INT32_C(0))) {
                    t0 = vader_parser_peek_at(l0, l1);
                    if (!(((vader_struct_vader_lexer_Token_t*) t0)->f_kind != INT32_C(0))) {
                        break;
                    }
                    t0 = vader_parser_peek_at(l0, l1);
                    l5 = ((vader_struct_vader_lexer_Token_t*) t0)->f_kind;
                    if (l5 == INT32_C(80)) {
                        l4 = vader_chk_add(i32, l4, INT32_C(1));
                    }
                    if (l5 == INT32_C(81)) {
                        l4 = vader_chk_sub(i32, l4, INT32_C(1));
                    }
                    l1 = vader_chk_add(i32, l1, INT32_C(1));
                }
            }
            for (;;) {
                t0 = vader_parser_peek_at(l0, l1);
                if (((vader_struct_vader_lexer_Token_t*) t0)->f_kind == INT32_C(1)) {
                    l1 = vader_chk_add(i32, l1, INT32_C(1));
                    continue;
                }
                break;
            }
            continue;
        }
        if (l3 == INT32_C(30)) {
            l1 = vader_chk_add(i32, l1, INT32_C(1));
            for (;;) {
                t0 = vader_parser_peek_at(l0, l1);
                if (((vader_struct_vader_lexer_Token_t*) t0)->f_kind == INT32_C(1)) {
                    l1 = vader_chk_add(i32, l1, INT32_C(1));
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
        l4 = vader_chk_add(i32, l1, INT32_C(1));
        t0 = vader_parser_peek_at(l0, l4);
        l2 = ((vader_struct_vader_lexer_Token_t*) t0)->f_kind == INT32_C(71);
    } else {
        l2 = false;
    }
    if (l2) {
        l1 = vader_chk_add(i32, l1, INT32_C(2));
        t0 = vader_parser_peek_at(l0, l1);
        return ((vader_struct_vader_lexer_Token_t*) t0)->f_kind == INT32_C(11);
    }
    return false;
}

static bool vader_parser_peek_is_lhs_generic_alias_head(void* l0) {
    int32_t l1, l2, l3, l4, l9, l12;
    void* l5;
    void* l8;
    void* l11;
    bool l6, l7, l10, l13, l14, l15, l16;
    int64_t t0;
    int32_t t1;
    void* t2;
    t0 = ((vader_array_t*) ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens)->length;
    l1 = ((int32_t) (int64_t) t0);
    l2 = INT32_C(1);
    l3 = INT32_C(0);
    t1 = ((vader_struct_vader_parser_Parser_t*) l0)->f_pos;
    l4 = vader_chk_add(i32, t1, INT32_C(2));
    while ((l4 < l1)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        if (((vader_struct_vader_lexer_Token_t*) l5)->f_kind == INT32_C(0)) {
            return false;
        }
        if (((vader_struct_vader_lexer_Token_t*) l5)->f_kind == INT32_C(1)) {
            return false;
        }
        if (((vader_struct_vader_lexer_Token_t*) l5)->f_kind == INT32_C(52)) {
            l6 = l3 == INT32_C(0);
        } else {
            l6 = false;
        }
        if (l6) {
            l2 = vader_chk_add(i32, l2, INT32_C(1));
        } else {
            if (((vader_struct_vader_lexer_Token_t*) l5)->f_kind == INT32_C(54)) {
                l7 = l3 == INT32_C(0);
            } else {
                l7 = false;
            }
            if (l7) {
                l2 = vader_chk_sub(i32, l2, INT32_C(1));
                if (l2 == INT32_C(0)) {
                    t1 = vader_chk_add(i32, l4, INT32_C(1));
                    if (!((t1 < l1))) {
                        return false;
                    }
                    l8 = ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens;
                    l9 = vader_chk_add(i32, l4, INT32_C(1));
                    vader_array_t* _a1_slotarr = ((vader_array_t*) l8);
                    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l9)
                    t2 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l9);
                    return ((vader_struct_vader_lexer_Token_t*) t2)->f_kind == INT32_C(71);
                }
            } else {
                if (((vader_struct_vader_lexer_Token_t*) l5)->f_kind == INT32_C(49)) {
                    l10 = l3 == INT32_C(0);
                } else {
                    l10 = false;
                }
                if (l10) {
                    l2 = vader_chk_sub(i32, l2, INT32_C(2));
                    if (l2 == INT32_C(0)) {
                        t1 = vader_chk_add(i32, l4, INT32_C(1));
                        if (!((t1 < l1))) {
                            return false;
                        }
                        l11 = ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens;
                        l12 = vader_chk_add(i32, l4, INT32_C(1));
                        vader_array_t* _a2_slotarr = ((vader_array_t*) l11);
                        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l12)
                        t2 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l12);
                        return ((vader_struct_vader_lexer_Token_t*) t2)->f_kind == INT32_C(71);
                    }
                    if ((l2 < INT32_C(0))) {
                        return false;
                    }
                } else {
                    if (((vader_struct_vader_lexer_Token_t*) l5)->f_kind == INT32_C(80)) {
                        l13 = true;
                    } else {
                        l13 = ((vader_struct_vader_lexer_Token_t*) l5)->f_kind == INT32_C(82);
                    }
                    if (l13) {
                        l14 = true;
                    } else {
                        l14 = ((vader_struct_vader_lexer_Token_t*) l5)->f_kind == INT32_C(84);
                    }
                    if (l14) {
                        l3 = vader_chk_add(i32, l3, INT32_C(1));
                    } else {
                        if (((vader_struct_vader_lexer_Token_t*) l5)->f_kind == INT32_C(81)) {
                            l15 = true;
                        } else {
                            l15 = ((vader_struct_vader_lexer_Token_t*) l5)->f_kind == INT32_C(83);
                        }
                        if (l15) {
                            l16 = true;
                        } else {
                            l16 = ((vader_struct_vader_lexer_Token_t*) l5)->f_kind == INT32_C(85);
                        }
                        if (l16) {
                            l3 = vader_chk_sub(i32, l3, INT32_C(1));
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
    if (((vader_struct_vader_lexer_Token_t*) t0)->f_kind != INT32_C(80)) {
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
        if (l3 == INT32_C(80)) {
            l1 = vader_chk_add(i32, l1, INT32_C(1));
        } else if (l3 == INT32_C(81)) {
            l1 = vader_chk_sub(i32, l1, INT32_C(1));
            if (l1 == INT32_C(0)) break;
        }
        l2 = vader_chk_add(i32, l2, INT32_C(1));
    }
    l2 = vader_chk_add(i32, l2, INT32_C(1));
    for (;;) {
        t0 = vader_parser_peek_at(l0, l2);
        if (((vader_struct_vader_lexer_Token_t*) t0)->f_kind == INT32_C(1)) {
            l2 = vader_chk_add(i32, l2, INT32_C(1));
            continue;
        }
        break;
    }
    t0 = vader_parser_peek_at(l0, l2);
    return ((vader_struct_vader_lexer_Token_t*) t0)->f_kind == INT32_C(76);
}

static vader_box_t vader_parser_place_text(vader_box_t l0) {
    vader_string_t l1 = 0;
    vader_string_t l3 = 0;
    vader_box_t l2 = vader_box_null();
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[2] = { &l0, &l2 };
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l3, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 610u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_toolchain_ast_IdentExpr_t*) t0)->f_name;
        { vader_box_t __vret = vader_box_string(317u, t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0.tag == 603u)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t0 = l0.payload.obj;
    l2 = vader_parser_place_text(((vader_struct_toolchain_ast_FieldExpr_t*) t0)->f_target);
    if (l2.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l1 = l2.payload.s;
    t0 = l0.payload.obj;
    l3 = ((vader_struct_toolchain_ast_FieldExpr_t*) t0)->f_field;
    t1 = concat_3(l1, 356u, l3);
    { vader_box_t __vret = vader_box_string(317u, t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_parser_postfix_bp(uint8_t l0) {
    int32_t l1;
    if (l0 == INT32_C(80)) {
        l1 = INT32_C(100);
        return l1;
    }
    if (l0 == INT32_C(82)) {
        l1 = INT32_C(100);
    } else if (l0 == INT32_C(87)) {
        l1 = INT32_C(100);
    } else if (l0 == INT32_C(35)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(0)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(1)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(2)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(3)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(4)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(5)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(6)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(7)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(8)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(9)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(10)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(36)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(37)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(38)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(39)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(40)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(41)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(42)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(43)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(44)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(45)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(46)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(47)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(48)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(49)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(50)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(51)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(56)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(57)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(52)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(53)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(54)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(55)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(58)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(59)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(61)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(60)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(62)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(63)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(64)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(65)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(66)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(67)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(68)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(69)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(70)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(71)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(72)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(73)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(74)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(75)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(76)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(77)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(78)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(79)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(81)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(83)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(84)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(85)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(86)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(88)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(11)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(12)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(13)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(14)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(15)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(16)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(17)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(18)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(19)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(20)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(21)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(22)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(23)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(24)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(25)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(26)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(27)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(28)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(29)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(30)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(31)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(32)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(33)) {
        l1 = INT32_C(-1);
    } else {
        if (!(l0 == INT32_C(34))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = INT32_C(-1);
    }
    return l1;
}

static void vader_parser_reject_alternative_bindings(void* l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    int64_t l4, l5;
    vader_string_t l8 = 0;
    vader_string_t l9 = 0;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[5] = { &l0, &l3, &l6, &l7, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l8, &l9, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!(l1.tag == 622u)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = l1.payload.obj;
    l2 = ((vader_struct_toolchain_ast_IsPattern_t*) t0)->f_inner;
    if (!(l2.tag == 653u)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = l2.payload.obj;
    l3 = ((vader_struct_toolchain_ast_StructPattern_t*) t0)->f_fields;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l6 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        if (((vader_struct_toolchain_ast_StructPatternField_t*) l6)->f_value.tag == 634u) {
            l7 = ((vader_struct_toolchain_ast_PatternBinding_t*) ((vader_struct_toolchain_ast_StructPatternField_t*) l6)->f_value.payload.obj)->f_span;
            l8 = ((vader_struct_toolchain_ast_StructPatternField_t*) l6)->f_name;
            t1 = concat_3(1464u, l8, 991u);
            l9 = concat_2(t1, 2623u);
            vader_parser_error(l0, (uint8_t) 22, l7, l9);
        }
        l5 = (l5 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_parser_reject_as_binder(void* l0, uint8_t l1, void* l2) {
    void* l3 = NULL;
    void* l5 = NULL;
    vader_box_t l4 = vader_box_null();
    vader_string_t l6 = 0;
    vader_string_t t0 = 0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l4, &t1 };
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &l5 };
    vader_string_t* gc_atom_roots[2] = { &l6, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = vader_parser_match_kind(l0, (uint8_t) 29);
    if (l4.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = l4.payload.obj;
    l5 = vader_parser_expect(l0, (uint8_t) 2, 1556u);
    if (((vader_struct_vader_lexer_Token_t*) l5)->f_kind == INT32_C(2)) {
        l3 = vader_parser_span_of(l0, l3, l5);
        t0 = ((vader_struct_vader_lexer_Token_t*) l5)->f_text;
        vader_fn_t* _a0_fnobj = (vader_fn_t*) l2;
        t1 = ((vader_fn_erased_sig_1_t) _a0_fnobj->code)(_a0_fnobj->env, vader_box_string(317u, t0));
        l6 = t1.payload.s;
        vader_parser_error(l0, l1, l3, l6);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_parser_reject_assert_decorator(void* l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    int64_t l3, l4;
    vader_string_t t0 = 0;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l5, &l6 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = l1;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t0 = ((vader_struct_toolchain_ast_Decorator_t*) l5)->f_name;
        if (t0 == 1531u) {
            l6 = ((vader_struct_toolchain_ast_Decorator_t*) l5)->f_span;
            vader_parser_error(l0, (uint8_t) 8, l6, 1283u);
        }
        l4 = (l4 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_parser_reject_c_decorators(void* l0, void* l1, vader_string_t l2) {
    void* l3 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    void* l11 = NULL;
    int64_t l4, l5;
    bool l7;
    vader_string_t l9 = 0;
    vader_string_t l10 = 0;
    vader_string_t l12 = 0;
    vader_string_t t0 = 0;
    void** gc_raw_roots[6] = { &l0, &l1, &l3, &l6, &l8, &l11 };
    vader_string_t* gc_atom_roots[5] = { &l2, &l9, &l10, &l12, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = l1;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l6 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        t0 = ((vader_struct_toolchain_ast_Decorator_t*) l6)->f_name;
        if (t0 == 1637u) {
            l7 = true;
        } else {
            t0 = ((vader_struct_toolchain_ast_Decorator_t*) l6)->f_name;
            l7 = t0 == 1636u;
        }
        if (l7) {
            l8 = ((vader_struct_toolchain_ast_Decorator_t*) l6)->f_span;
            l9 = ((vader_struct_toolchain_ast_Decorator_t*) l6)->f_name;
            l10 = concat_4(1280u, l9, 1027u, l2);
            vader_parser_error(l0, (uint8_t) 8, l8, l10);
        }
        t0 = ((vader_struct_toolchain_ast_Decorator_t*) l6)->f_name;
        if (t0 == 1638u) {
            l11 = ((vader_struct_toolchain_ast_Decorator_t*) l6)->f_span;
            l12 = concat_2(1288u, l2);
            vader_parser_error(l0, (uint8_t) 8, l11, l12);
        }
        l5 = (l5 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_parser_reject_displayable_decorator(void* l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    int64_t l3, l4;
    vader_string_t t0 = 0;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l5, &l6 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = l1;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t0 = ((vader_struct_toolchain_ast_Decorator_t*) l5)->f_name;
        if (t0 == 1764u) {
            l6 = ((vader_struct_toolchain_ast_Decorator_t*) l5)->f_span;
            vader_parser_error(l0, (uint8_t) 8, l6, 1302u);
        }
        l4 = (l4 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_parser_reject_free_fn_decorators(void* l0, void* l1, vader_string_t l2, vader_string_t l3) {
    void* l4 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l10 = NULL;
    void* l12 = NULL;
    void* l14 = NULL;
    void* l17 = NULL;
    int64_t l5, l6;
    vader_string_t l9 = 0;
    vader_string_t l11 = 0;
    vader_string_t l13 = 0;
    vader_string_t l15 = 0;
    vader_string_t l16 = 0;
    vader_string_t l18 = 0;
    vader_string_t l19 = 0;
    vader_string_t t0 = 0;
    void** gc_raw_roots[9] = { &l0, &l1, &l4, &l7, &l8, &l10, &l12, &l14, &l17 };
    vader_string_t* gc_atom_roots[10] = { &l2, &l3, &l9, &l11, &l13, &l15, &l16, &l18, &l19, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 9u, NULL, gc_raw_roots, 0u, NULL, 10u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = l1;
    l5 = ((vader_array_t*) l4)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l7 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
        t0 = ((vader_struct_toolchain_ast_Decorator_t*) l7)->f_name;
        if (t0 == 2595u) {
            l8 = ((vader_struct_toolchain_ast_Decorator_t*) l7)->f_span;
            l9 = concat_3(1316u, l2, l3);
            vader_parser_error(l0, (uint8_t) 8, l8, l9);
        }
        t0 = ((vader_struct_toolchain_ast_Decorator_t*) l7)->f_name;
        if (t0 == 2460u) {
            l10 = ((vader_struct_toolchain_ast_Decorator_t*) l7)->f_span;
            l11 = concat_2(1312u, l2);
            vader_parser_error(l0, (uint8_t) 8, l10, l11);
        }
        t0 = ((vader_struct_toolchain_ast_Decorator_t*) l7)->f_name;
        if (t0 == 2433u) {
            l12 = ((vader_struct_toolchain_ast_Decorator_t*) l7)->f_span;
            l13 = concat_2(1311u, l2);
            vader_parser_error(l0, (uint8_t) 8, l12, l13);
        }
        t0 = ((vader_struct_toolchain_ast_Decorator_t*) l7)->f_name;
        if (t0 == 1792u) {
            l14 = ((vader_struct_toolchain_ast_Decorator_t*) l7)->f_span;
            l15 = concat_2(2125u, l2);
            l16 = concat_2(1304u, l15);
            vader_parser_error(l0, (uint8_t) 8, l14, l16);
        }
        t0 = ((vader_struct_toolchain_ast_Decorator_t*) l7)->f_name;
        if (t0 == 1639u) {
            l17 = ((vader_struct_toolchain_ast_Decorator_t*) l7)->f_span;
            l18 = concat_2(2125u, l2);
            l19 = concat_2(1292u, l18);
            vader_parser_error(l0, (uint8_t) 8, l17, l19);
        }
        l6 = (l6 + INT64_C(1));
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
    vader_parser_error(l0, (uint8_t) 15, l2, 1333u);
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
        if (((vader_struct_vader_lexer_Token_t*) l3)->f_kind == INT32_C(82)) {
            l2 = vader_chk_add(i32, l2, INT32_C(1));
        }
        if (!(((vader_struct_vader_lexer_Token_t*) l3)->f_kind == INT32_C(83))) {
            continue;
        }
        l2 = vader_chk_sub(i32, l2, INT32_C(1));
    }
    l1 = vader_parser_span_of(l0, l1, l3);
    vader_parser_error(l0, (uint8_t) 13, l1, 2601u);
    vader_struct_toolchain_ast_WildcardPattern_t* _a0_obj = (vader_struct_toolchain_ast_WildcardPattern_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_WildcardPattern_t));
    vader_obj_header_init(_a0_obj, 663u);
    _a0_obj->f_span = l1;
    _a0_obj->f_id = INT64_C(0);
    t1 = (void*) _a0_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_parser_report_nesting_too_deep(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    vader_string_t l4 = 0;
    int64_t l5;
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
    l6 = (void*) vader_buffer_new((size_t) (INT64_C(50) + l5));
    l5 = INT64_C(0);
    l5 = std_core_write_string_at(l6, l5, l4);
    l5 = std_core_write_string_at(l6, l5, 149u);
    l5 = std_core_write_int(l6, l5, INT64_C(256));
    l5 = std_core_write_string_at(l6, l5, 140u);
    l4 = std_core_finish_buffer(l6, l5);
    l3 = vader_diagnostics_parser_error((uint8_t) 17, l3, l4);
    vader_array_push_ref((vader_array_t*) l2, l3);
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
    int32_t l2, l3, l4, l5, l6;
    void* l7;
    bool l8;
    int64_t t0;
    void* t1;
    bool t2;
    t0 = ((vader_array_t*) ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens)->length;
    l2 = ((int32_t) (int64_t) t0);
    if ((l1 >= l2)) {
        return false;
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    if (((vader_struct_vader_lexer_Token_t*) t1)->f_kind != INT32_C(52)) {
        return false;
    }
    l3 = INT32_C(1);
    l4 = INT32_C(0);
    l5 = INT32_C(0);
    l6 = vader_chk_add(i32, l1, INT32_C(1));
    while ((l6 < l2)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_parser_Parser_t*) l0)->f_tokens);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        l7 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
        if (((vader_struct_vader_lexer_Token_t*) l7)->f_kind == INT32_C(0)) {
            return false;
        }
        if (l4 == INT32_C(0)) {
            l8 = l5 == INT32_C(0);
        } else {
            l8 = false;
        }
        if (((vader_struct_vader_lexer_Token_t*) l7)->f_kind == INT32_C(1)) {
            if (l8) {
                return false;
            }
        }
        if (l8) {
            t2 = vader_parser_is_angle_scan_bailout(((vader_struct_vader_lexer_Token_t*) l7)->f_kind);
            if (t2) {
                return false;
            }
        }
        if (l8) {
            if (((vader_struct_vader_lexer_Token_t*) l7)->f_kind == INT32_C(52)) {
                l3 = vader_chk_add(i32, l3, INT32_C(1));
            } else if (((vader_struct_vader_lexer_Token_t*) l7)->f_kind == INT32_C(54)) {
                l3 = vader_chk_sub(i32, l3, INT32_C(1));
                if (l3 == INT32_C(0)) {
                    t2 = vader_parser_generic_use_follows(l0, l6);
                    return t2;
                }
            } else if (((vader_struct_vader_lexer_Token_t*) l7)->f_kind == INT32_C(49)) {
                l3 = vader_chk_sub(i32, l3, INT32_C(2));
                if (l3 == INT32_C(0)) {
                    t2 = vader_parser_generic_use_follows(l0, l6);
                    return t2;
                }
                if ((l3 < INT32_C(0))) {
                    return false;
                }
            }
        }
        if (((vader_struct_vader_lexer_Token_t*) l7)->f_kind == INT32_C(80)) {
            l4 = vader_chk_add(i32, l4, INT32_C(1));
        } else if (((vader_struct_vader_lexer_Token_t*) l7)->f_kind == INT32_C(81)) {
            if (l4 == INT32_C(0)) {
                return false;
            }
            l4 = vader_chk_sub(i32, l4, INT32_C(1));
        } else if (((vader_struct_vader_lexer_Token_t*) l7)->f_kind == INT32_C(82)) {
            l5 = vader_chk_add(i32, l5, INT32_C(1));
        } else if (((vader_struct_vader_lexer_Token_t*) l7)->f_kind == INT32_C(83)) {
            if (l5 == INT32_C(0)) {
                return false;
            }
            l5 = vader_chk_sub(i32, l5, INT32_C(1));
        }
        l6 = (l6 + INT32_C(1));
    }
    return false;
}

static int64_t vader_parser_skip_block_comment(vader_string_t l0, int64_t l1) {
    int64_t l2, l3, l6;
    int32_t l4;
    uint8_t l5, l7;
    int64_t t0;
    l2 = vader_host_std_core_byte_len(l0);
    l3 = l1;
    l4 = INT32_C(1);
    for (;;) {
        t0 = vader_chk_add(i64, l3, INT64_C(1));
        if ((t0 < l2)) {
            if (!((l4 > INT32_C(0)))) {
                break;
            }
            l5 = vader_host_std_core_byte_at(l0, l3);
            l6 = vader_chk_add(i64, l3, INT64_C(1));
            l7 = vader_host_std_core_byte_at(l0, l6);
            if (l5 == INT32_C(47)) {
                if (l7 == INT32_C(42)) {
                    l4 = vader_chk_add(i32, l4, INT32_C(1));
                    l3 = vader_chk_add(i64, l3, INT64_C(2));
                    continue;
                }
            }
            if (l5 == INT32_C(42)) {
                if (l7 == INT32_C(47)) {
                    l4 = vader_chk_sub(i32, l4, INT32_C(1));
                    l3 = vader_chk_add(i64, l3, INT64_C(2));
                    continue;
                }
            }
            l3 = vader_chk_add(i64, l3, INT64_C(1));
            continue;
        }
        break;
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
            l1 = vader_chk_add(i32, t1, INT32_C(1));
            ((vader_struct_vader_parser_Parser_t*) l0)->f_pos = l1;
            continue;
        }
        break;
    }
    return;
}

static int64_t vader_parser_skip_to_eol(vader_string_t l0, int64_t l1) {
    int64_t l2, l3;
    uint8_t t0;
    l2 = vader_host_std_core_byte_len(l0);
    l3 = l1;
    while ((l3 < l2)) {
        t0 = vader_host_std_core_byte_at(l0, l3);
        if (!(t0 != INT32_C(10))) {
            break;
        }
        l3 = vader_chk_add(i64, l3, INT64_C(1));
    }
    if ((l3 < l2)) {
        l3 = vader_chk_add(i64, l3, INT64_C(1));
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
    vader_obj_header_init(_a0_obj, 667u);
    _a0_obj->f_start = l3;
    _a0_obj->f_end = l4;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_parser_starts_let(void* l0) {
    uint8_t l1;
    bool l2;
    bool t0;
    t0 = vader_parser_check(l0, (uint8_t) 82);
    if (t0) {
        l1 = vader_parser_kind_after_bracket_group(l0);
        if (l1 == INT32_C(71)) {
            l2 = true;
        } else {
            l2 = l1 == INT32_C(72);
        }
        if (l2) {
            return true;
        }
        return l1 == INT32_C(88);
    }
    t0 = vader_parser_check(l0, (uint8_t) 2);
    if (t0) {
        t0 = vader_parser_check_at(l0, (uint8_t) 71, INT32_C(1));
        if (t0) {
            l2 = true;
        } else {
            l2 = vader_parser_check_at(l0, (uint8_t) 72, INT32_C(1));
        }
        if (l2) {
            l2 = true;
        } else {
            l2 = vader_parser_check_at(l0, (uint8_t) 88, INT32_C(1));
        }
        return l2;
    }
    return false;
}

static vader_box_t vader_parser_static_assert_message(void* l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = toolchain_ast_string_literal_text(l1);
    if (l2.tag == 0u) {
        l3 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, l1.payload.obj);
        vader_parser_error(l0, (uint8_t) 19, l3, 1282u);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_box_t l2;
    int64_t l3;
    void* l4;
    if ((l0.tag == 636u || l0.tag == 641u)) {
        l2 = l0;
        l3 = vader_parser_mint(l1);
        VADER_UNION_FIELD(int64_t, vader_struct_toolchain_ast_PlaceTarget_t, f_id, l2.payload.obj) = l3;
        vader_parser_walk_expr(VADER_UNION_FIELD(vader_box_t, vader_struct_toolchain_ast_PlaceTarget_t, f_place, l0.payload.obj), l1);
        return;
    }
    if (!(l0.tag == 664u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    l4 = l0.payload.obj;
    l3 = vader_parser_mint(l1);
    ((vader_struct_toolchain_ast_WildcardTarget_t*) l4)->f_id = l3;
    return;
}

static void vader_parser_walk_block(void* l0, void* l1) {
    int64_t l2, l4;
    void* l3;
    vader_box_t t0;
    l2 = vader_parser_mint(l1);
    ((vader_struct_toolchain_ast_BlockExpr_t*) l0)->f_id = l2;
    l3 = ((vader_struct_toolchain_ast_BlockExpr_t*) l0)->f_stmts;
    l2 = ((vader_array_t*) l3)->length;
    l4 = INT64_C(0);
    while ((l4 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        vader_parser_walk_stmt(t0, l1);
        l4 = (l4 + INT64_C(1));
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
    int64_t l3, l4, l6;
    void* t0;
    vader_box_t t1;
    if (l0.tag == 615u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_ImportDecl_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_parser_walk_import_binding(((vader_struct_toolchain_ast_ImportDecl_t*) t0)->f_binding, l1);
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_ImportDecl_t*) t0)->f_decorators;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
            vader_parser_walk_decorator(t0, l1);
            l4 = (l4 + INT64_C(1));
        }
    } else if (l0.tag == 605u) {
        t0 = l0.payload.obj;
        vader_parser_walk_fn_decl(t0, l1);
    } else if (l0.tag == 648u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_StructDecl_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_StructDecl_t*) t0)->f_type_params;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
            vader_parser_walk_type_param(t0, l1);
            l4 = (l4 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_StructDecl_t*) t0)->f_fields;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            l5 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
            l6 = vader_parser_mint(l1);
            ((vader_struct_toolchain_ast_StructField_t*) l5)->f_id = l6;
            vader_parser_walk_expr(((vader_struct_toolchain_ast_StructField_t*) l5)->f_ty, l1);
            if (!(((vader_struct_toolchain_ast_StructField_t*) l5)->f_default_v.tag == 0u)) {
                vader_parser_walk_expr(((vader_struct_toolchain_ast_StructField_t*) l5)->f_default_v, l1);
            }
            l4 = (l4 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_StructDecl_t*) t0)->f_decorators;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            t0 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l4);
            vader_parser_walk_decorator(t0, l1);
            l4 = (l4 + INT64_C(1));
        }
    } else if (l0.tag == 599u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_EnumDecl_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_EnumDecl_t*) t0)->f_header;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            t1 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l4);
            vader_parser_walk_expr(t1, l1);
            l4 = (l4 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_EnumDecl_t*) t0)->f_variants;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            l5 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l4);
            l6 = vader_parser_mint(l1);
            ((vader_struct_toolchain_ast_EnumVariant_t*) l5)->f_id = l6;
            if (!(((vader_struct_toolchain_ast_EnumVariant_t*) l5)->f_data.tag == 0u)) {
                vader_parser_walk_struct_lit_items(((vader_struct_toolchain_ast_EnumVariant_t*) l5)->f_data.payload.obj, l1);
            }
            l4 = (l4 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_EnumDecl_t*) t0)->f_decorators;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a6_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            t0 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l4);
            vader_parser_walk_decorator(t0, l1);
            l4 = (l4 + INT64_C(1));
        }
    } else if (l0.tag == 655u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_TraitDecl_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_TraitDecl_t*) t0)->f_type_params;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a7_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            t0 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l4);
            vader_parser_walk_type_param(t0, l1);
            l4 = (l4 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        if (!(((vader_struct_toolchain_ast_TraitDecl_t*) t0)->f_requires.tag == 0u)) {
            t0 = l0.payload.obj;
            vader_parser_walk_expr(((vader_struct_toolchain_ast_TraitDecl_t*) t0)->f_requires, l1);
        }
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_TraitDecl_t*) t0)->f_members;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a8_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            t0 = vader_array_ref_load_obj(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l4);
            vader_parser_walk_fn_decl(t0, l1);
            l4 = (l4 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_TraitDecl_t*) t0)->f_decorators;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a9_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            t0 = vader_array_ref_load_obj(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l4);
            vader_parser_walk_decorator(t0, l1);
            l4 = (l4 + INT64_C(1));
        }
    } else if (l0.tag == 614u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_ImplDecl_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_ImplDecl_t*) t0)->f_type_params;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a10_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
            t0 = vader_array_ref_load_obj(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l4);
            vader_parser_walk_type_param(t0, l1);
            l4 = (l4 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_ImplDecl_t*) t0)->f_for_type, l1);
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_ImplDecl_t*) t0)->f_trait_args;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a11_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
            t1 = vader_array_ref_load_box(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l4);
            vader_parser_walk_expr(t1, l1);
            l4 = (l4 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_ImplDecl_t*) t0)->f_members;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a12_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
            t0 = vader_array_ref_load_obj(_a12_slotarr->buf, _a12_slotarr->offset + (size_t) l4);
            vader_parser_walk_fn_decl(t0, l1);
            l4 = (l4 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_ImplDecl_t*) t0)->f_decorators;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a13_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
            t0 = vader_array_ref_load_obj(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l4);
            vader_parser_walk_decorator(t0, l1);
            l4 = (l4 + INT64_C(1));
        }
    } else if (l0.tag == 657u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_TypeAliasDecl_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_TypeAliasDecl_t*) t0)->f_type_params;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a14_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
            t0 = vader_array_ref_load_obj(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l4);
            vader_parser_walk_type_param(t0, l1);
            l4 = (l4 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_TypeAliasDecl_t*) t0)->f_aliased, l1);
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_TypeAliasDecl_t*) t0)->f_decorators;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a15_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
            t0 = vader_array_ref_load_obj(_a15_slotarr->buf, _a15_slotarr->offset + (size_t) l4);
            vader_parser_walk_decorator(t0, l1);
            l4 = (l4 + INT64_C(1));
        }
    } else if (l0.tag == 588u) {
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
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a16_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
            t0 = vader_array_ref_load_obj(_a16_slotarr->buf, _a16_slotarr->offset + (size_t) l4);
            vader_parser_walk_decorator(t0, l1);
            l4 = (l4 + INT64_C(1));
        }
    } else {
        if (!(l0.tag == 577u)) {
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
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a17_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
            t0 = vader_array_ref_load_obj(_a17_slotarr->buf, _a17_slotarr->offset + (size_t) l4);
            vader_parser_walk_decorator(t0, l1);
            l4 = (l4 + INT64_C(1));
        }
    }
    return;
}

static void vader_parser_walk_decorator(void* l0, void* l1) {
    int64_t l2, l4;
    void* l3;
    vader_box_t t0;
    l2 = vader_parser_mint(l1);
    ((vader_struct_toolchain_ast_Decorator_t*) l0)->f_id = l2;
    l3 = ((vader_struct_toolchain_ast_Decorator_t*) l0)->f_args;
    l2 = ((vader_array_t*) l3)->length;
    l4 = INT64_C(0);
    while ((l4 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        vader_parser_walk_expr(t0, l1);
        l4 = (l4 + INT64_C(1));
    }
    return;
}

static void vader_parser_walk_expr(vader_box_t l0, void* l1) {
    void* l2;
    void* l6;
    void* l8;
    int64_t l3, l4, l7, l9;
    vader_box_t l5, l10;
    void* t0;
    vader_box_t t1;
    if (l0.tag == 620u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_IntLitExpr_t*) l2)->f_id = l3;
        return;
    }
    if (l0.tag == 604u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_FloatLitExpr_t*) l2)->f_id = l3;
    } else if (l0.tag == 582u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_BoolLitExpr_t*) l2)->f_id = l3;
    } else if (l0.tag == 632u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_NullLitExpr_t*) l2)->f_id = l3;
    } else if (l0.tag == 587u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_CharLitExpr_t*) l2)->f_id = l3;
    } else if (l0.tag == 645u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_StringLitExpr_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_StringLitExpr_t*) t0)->f_parts;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
            if (l5.tag == 647u) {
                l6 = l5.payload.obj;
                l7 = vader_parser_mint(l1);
                ((vader_struct_toolchain_ast_StringLitText_t*) l6)->f_id = l7;
            } else {
                if (!(l5.tag == 646u)) {
                    vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                }
                l8 = l5.payload.obj;
                l9 = vader_parser_mint(l1);
                ((vader_struct_toolchain_ast_StringLitInterp_t*) l8)->f_id = l9;
                t0 = l5.payload.obj;
                vader_parser_walk_expr(((vader_struct_toolchain_ast_StringLitInterp_t*) t0)->f_expr, l1);
            }
            l4 = (l4 + INT64_C(1));
        }
    } else if (l0.tag == 610u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_IdentExpr_t*) l2)->f_id = l3;
    } else if (l0.tag == 585u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_CallExpr_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_CallExpr_t*) t0)->f_callee, l1);
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_CallExpr_t*) t0)->f_type_args;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            t1 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
            vader_parser_walk_expr(t1, l1);
            l4 = (l4 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_CallExpr_t*) t0)->f_args;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            l6 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
            l7 = vader_parser_mint(l1);
            ((vader_struct_toolchain_ast_CallArg_t*) l6)->f_id = l7;
            vader_parser_walk_expr(((vader_struct_toolchain_ast_CallArg_t*) l6)->f_value, l1);
            l4 = (l4 + INT64_C(1));
        }
    } else if (l0.tag == 603u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_FieldExpr_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_FieldExpr_t*) t0)->f_target, l1);
    } else if (l0.tag == 618u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_IndexExpr_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_IndexExpr_t*) t0)->f_target, l1);
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_IndexExpr_t*) t0)->f_index, l1);
    } else if (l0.tag == 659u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_UnaryExpr_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_UnaryExpr_t*) t0)->f_operand, l1);
    } else if (l0.tag == 580u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_BinaryExpr_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_left, l1);
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_right, l1);
    } else if (l0.tag == 631u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_NullCoalesceExpr_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_NullCoalesceExpr_t*) t0)->f_left, l1);
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_NullCoalesceExpr_t*) t0)->f_fallback;
        l10 = l5;
        if ((l5.tag == 583u || l5.tag == 589u || l5.tag == 642u)) {
            vader_parser_walk_stmt(l10, l1);
        } else {
            if (!((l5.tag == 576u || l5.tag == 579u || l5.tag == 580u || l5.tag == 581u || l5.tag == 582u || l5.tag == 585u || l5.tag == 586u || l5.tag == 587u || l5.tag == 598u || l5.tag == 603u || l5.tag == 604u || l5.tag == 607u || l5.tag == 609u || l5.tag == 610u || l5.tag == 613u || l5.tag == 618u || l5.tag == 620u || l5.tag == 621u || l5.tag == 623u || l5.tag == 627u || l5.tag == 631u || l5.tag == 632u || l5.tag == 638u || l5.tag == 643u || l5.tag == 645u || l5.tag == 650u || l5.tag == 659u))) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            vader_parser_walk_expr(l10, l1);
        }
    } else if (l0.tag == 613u) {
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
            if (l5.tag == 612u) {
                t0 = l10.payload.obj;
                vader_parser_walk_expr(vader_ref_box(((vader_struct_toolchain_ast_IfElseIf_t*) t0)->f_branch), l1);
            } else {
                if (!(l5.tag == 611u)) {
                    vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                }
                t0 = l10.payload.obj;
                vader_parser_walk_block(((vader_struct_toolchain_ast_IfElseBlock_t*) t0)->f_block, l1);
            }
        }
    } else if (l0.tag == 627u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_MatchExpr_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        if (!(((vader_struct_toolchain_ast_MatchExpr_t*) t0)->f_binding.tag == 0u)) {
            t0 = l0.payload.obj;
            vader_parser_walk_let_binding(((vader_struct_toolchain_ast_MatchExpr_t*) t0)->f_binding, l1);
        }
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_MatchExpr_t*) t0)->f_scrutinee, l1);
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_MatchExpr_t*) t0)->f_arms;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            l6 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l4);
            l7 = vader_parser_mint(l1);
            ((vader_struct_toolchain_ast_MatchArm_t*) l6)->f_id = l7;
            vader_parser_walk_pattern(((vader_struct_toolchain_ast_MatchArm_t*) l6)->f_pattern, l1);
            if (!(((vader_struct_toolchain_ast_MatchArm_t*) l6)->f_guard.tag == 0u)) {
                vader_parser_walk_expr(((vader_struct_toolchain_ast_MatchArm_t*) l6)->f_guard, l1);
            }
            vader_parser_walk_expr(((vader_struct_toolchain_ast_MatchArm_t*) l6)->f_body, l1);
            l4 = (l4 + INT64_C(1));
        }
    } else if (l0.tag == 581u) {
        t0 = l0.payload.obj;
        vader_parser_walk_block(t0, l1);
    } else if (l0.tag == 623u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_LambdaExpr_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_LambdaExpr_t*) t0)->f_params;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            t0 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l4);
            vader_parser_walk_fn_param(t0, l1);
            l4 = (l4 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        if (!(((vader_struct_toolchain_ast_LambdaExpr_t*) t0)->f_return_type.tag == 0u)) {
            t0 = l0.payload.obj;
            vader_parser_walk_expr(((vader_struct_toolchain_ast_LambdaExpr_t*) t0)->f_return_type, l1);
        }
        t0 = l0.payload.obj;
        vader_parser_walk_block(((vader_struct_toolchain_ast_LambdaExpr_t*) t0)->f_body, l1);
    } else if (l0.tag == 650u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_StructLitExpr_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_StructLitExpr_t*) t0)->f_type_name, l1);
        t0 = l0.payload.obj;
        vader_parser_walk_struct_lit_items(((vader_struct_toolchain_ast_StructLitExpr_t*) t0)->f_items, l1);
    } else if (l0.tag == 643u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_SeqLitExpr_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_SeqLitExpr_t*) t0)->f_elements;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            t1 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l4);
            vader_parser_walk_expr(t1, l1);
            l4 = (l4 + INT64_C(1));
        }
    } else if (l0.tag == 638u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_RangeExpr_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_RangeExpr_t*) t0)->f_lower, l1);
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_RangeExpr_t*) t0)->f_upper, l1);
    } else if (l0.tag == 579u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_AwaitExpr_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_AwaitExpr_t*) t0)->f_inner, l1);
    } else if (l0.tag == 586u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_CastExpr_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_CastExpr_t*) t0)->f_target, l1);
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_CastExpr_t*) t0)->f_value, l1);
    } else if (l0.tag == 609u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_GenericInstExpr_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_GenericInstExpr_t*) t0)->f_callee, l1);
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_GenericInstExpr_t*) t0)->f_type_args;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a6_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            t1 = vader_array_ref_load_box(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l4);
            vader_parser_walk_expr(t1, l1);
            l4 = (l4 + INT64_C(1));
        }
    } else if (l0.tag == 621u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) t0)->f_args;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a7_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            t1 = vader_array_ref_load_box(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l4);
            vader_parser_walk_expr(t1, l1);
            l4 = (l4 + INT64_C(1));
        }
    } else if (l0.tag == 598u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_DotVariantExpr_t*) l2)->f_id = l3;
    } else if (l0.tag == 607u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_FnTypeExpr_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_FnTypeExpr_t*) t0)->f_params;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a8_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            t1 = vader_array_ref_load_box(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l4);
            vader_parser_walk_expr(t1, l1);
            l4 = (l4 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        if (!(((vader_struct_toolchain_ast_FnTypeExpr_t*) t0)->f_return_type.tag == 0u)) {
            t0 = l0.payload.obj;
            vader_parser_walk_expr(((vader_struct_toolchain_ast_FnTypeExpr_t*) t0)->f_return_type, l1);
        }
    } else {
        if (!(l0.tag == 576u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t0)->f_element, l1);
    }
    return;
}

static void vader_parser_walk_fn_decl(void* l0, void* l1) {
    int64_t l2, l4;
    void* l3;
    void* t0;
    l2 = vader_parser_mint(l1);
    ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_id = l2;
    l3 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_decorators;
    l2 = ((vader_array_t*) l3)->length;
    l4 = INT64_C(0);
    while ((l4 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        vader_parser_walk_decorator(t0, l1);
        l4 = (l4 + INT64_C(1));
    }
    l3 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_type_params;
    l2 = ((vader_array_t*) l3)->length;
    l4 = INT64_C(0);
    while ((l4 < l2)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        vader_parser_walk_type_param(t0, l1);
        l4 = (l4 + INT64_C(1));
    }
    l3 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_params;
    l2 = ((vader_array_t*) l3)->length;
    l4 = INT64_C(0);
    while ((l4 < l2)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        vader_parser_walk_fn_param(t0, l1);
        l4 = (l4 + INT64_C(1));
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
    int64_t l2;
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
    if (l0.tag == 619u) {
        return;
    }
    if (l0.tag == 660u) {
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_WhileFor_t*) t0)->f_cond, l1);
    } else {
        if (!(l0.tag == 617u)) {
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
    int64_t l3, l4, l6;
    void* t0;
    if (l0.tag == 629u) {
        return;
    }
    if (!(l0.tag == 662u)) {
        if (!(l0.tag == 595u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_DestructureImport_t*) t0)->f_names;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
            l6 = vader_parser_mint(l1);
            ((vader_struct_toolchain_ast_ImportName_t*) l5)->f_id = l6;
            l4 = (l4 + INT64_C(1));
        }
    }
    return;
}

static void vader_parser_walk_let_binding(vader_box_t l0, void* l1) {
    void* l2;
    int64_t l3, l4;
    void* t0;
    vader_box_t t1;
    if (l0.tag == 644u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_SimpleBinding_t*) l2)->f_id = l3;
        return;
    }
    if (l0.tag == 661u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_WildcardBinding_t*) l2)->f_id = l3;
    } else if (l0.tag == 640u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_RestBinding_t*) l2)->f_id = l3;
    } else {
        if (!(l0.tag == 656u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_TupleBinding_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_TupleBinding_t*) t0)->f_elements;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
            vader_parser_walk_let_binding(t1, l1);
            l4 = (l4 + INT64_C(1));
        }
    }
    return;
}

static void vader_parser_walk_pattern(vader_box_t l0, void* l1) {
    void* l2;
    void* l5;
    void* l9;
    int64_t l3, l4, l6, l10;
    vader_box_t l7, l8;
    void* t0;
    vader_box_t t1;
    if (l0.tag == 622u) {
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
    if (l0.tag == 653u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_StructPattern_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_StructPattern_t*) t0)->f_fields;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
            l6 = vader_parser_mint(l1);
            ((vader_struct_toolchain_ast_StructPatternField_t*) l5)->f_id = l6;
            l7 = ((vader_struct_toolchain_ast_StructPatternField_t*) l5)->f_value;
            l8 = l7;
            if (l7.tag == 634u) {
                l9 = l8.payload.obj;
                l10 = vader_parser_mint(l1);
                ((vader_struct_toolchain_ast_PatternBinding_t*) l9)->f_id = l10;
            } else {
                if (!(l7.tag == 635u)) {
                    vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                }
                t0 = l8.payload.obj;
                vader_parser_walk_expr(((vader_struct_toolchain_ast_PatternLiteral_t*) t0)->f_value, l1);
            }
            l4 = (l4 + INT64_C(1));
        }
    } else if (l0.tag == 663u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_WildcardPattern_t*) l2)->f_id = l3;
    } else if (l0.tag == 601u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_EnumVariantPattern_t*) l2)->f_id = l3;
    } else if (l0.tag == 625u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_LiteralPattern_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_LiteralPattern_t*) t0)->f_value, l1);
    } else if (l0.tag == 639u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_RangePattern_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_RangePattern_t*) t0)->f_lower, l1);
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_RangePattern_t*) t0)->f_upper, l1);
    } else {
        if (!(l0.tag == 633u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_OrPattern_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_OrPattern_t*) t0)->f_patterns;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            t1 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
            vader_parser_walk_pattern(t1, l1);
            l4 = (l4 + INT64_C(1));
        }
    }
    return;
}

static void vader_parser_walk_stmt(vader_box_t l0, void* l1) {
    void* l2;
    int64_t l3, l4;
    vader_box_t l5, l6;
    void* t0;
    vader_box_t t1;
    if (l0.tag == 624u) {
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
    if (l0.tag == 578u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_AssignStmt_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_AssignStmt_t*) t0)->f_target, l1);
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_AssignStmt_t*) t0)->f_value, l1);
    } else if (l0.tag == 594u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_DestructureAssignStmt_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_DestructureAssignStmt_t*) t0)->f_targets;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
            vader_parser_walk_assign_target(t1, l1);
            l4 = (l4 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_DestructureAssignStmt_t*) t0)->f_value, l1);
    } else if (l0.tag == 602u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_ExprStmt_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_ExprStmt_t*) t0)->f_expr, l1);
    } else if (l0.tag == 642u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_ReturnStmt_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        if (!(((vader_struct_toolchain_ast_ReturnStmt_t*) t0)->f_value.tag == 0u)) {
            t0 = l0.payload.obj;
            vader_parser_walk_expr(((vader_struct_toolchain_ast_ReturnStmt_t*) t0)->f_value, l1);
        }
    } else if (l0.tag == 665u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_YieldStmt_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_parser_walk_expr(((vader_struct_toolchain_ast_YieldStmt_t*) t0)->f_value, l1);
    } else if (l0.tag == 608u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_ForStmt_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_parser_walk_for_form(((vader_struct_toolchain_ast_ForStmt_t*) t0)->f_form, l1);
        t0 = l0.payload.obj;
        vader_parser_walk_block(((vader_struct_toolchain_ast_ForStmt_t*) t0)->f_body, l1);
    } else if (l0.tag == 583u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_BreakStmt_t*) l2)->f_id = l3;
    } else if (l0.tag == 589u) {
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_ContinueStmt_t*) l2)->f_id = l3;
    } else {
        if (!(l0.tag == 592u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = l0.payload.obj;
        l3 = vader_parser_mint(l1);
        ((vader_struct_toolchain_ast_DeferStmt_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_DeferStmt_t*) t0)->f_body;
        l6 = l5;
        if (l5.tag == 593u) {
            t0 = l6.payload.obj;
            vader_parser_walk_stmt(((vader_struct_toolchain_ast_DeferStmtBody_t*) t0)->f_stmt, l1);
        } else {
            if (!(l5.tag == 591u)) {
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
    int64_t l3, l4, l6;
    vader_box_t l5;
    void* t0;
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        l6 = vader_parser_mint(l1);
        VADER_UNION_FIELD(int64_t, vader_struct_toolchain_ast_StructLitField_t, f_id, l5.payload.obj) = l6;
        if (l5.tag == 651u) {
            t0 = l5.payload.obj;
            vader_parser_walk_expr(((vader_struct_toolchain_ast_StructLitField_t*) t0)->f_value, l1);
        } else {
            t0 = l5.payload.obj;
            vader_parser_walk_expr(((vader_struct_toolchain_ast_StructLitSpread_t*) t0)->f_expr, l1);
        }
        l4 = (l4 + INT64_C(1));
    }
    return;
}

static void vader_parser_walk_type_param(void* l0, void* l1) {
    int64_t l2;
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
    if (!(l0.tag == 581u)) {
        l1 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, l0.payload.obj);
        vader_array_t* _a0_arr = vader_array_new(229u, 0u, 13u, 1536u);
        l2 = (void*) _a0_arr;
        l3 = l0;
        vader_struct_toolchain_ast_BlockExpr_t* _a1_obj = (vader_struct_toolchain_ast_BlockExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BlockExpr_t));
        vader_obj_header_init(_a1_obj, 581u);
        _a1_obj->f_span = l1;
        _a1_obj->f_id = INT64_C(0);
        _a1_obj->f_stmts = l2;
        _a1_obj->f_trailing = l3;
        t0 = (void*) _a1_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l0.payload.obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}
