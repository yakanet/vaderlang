#include "bootstrap.split.h"

static void* vader_front_parser$advance(void* l0);
static bool vader_front_parser$allows_bare_lambda(void* l0);
static bool vader_front_parser$allows_struct_lit(void* l0);
static bool vader_front_parser$at_top_level_start(void* l0);
static int32_t vader_front_parser$bracket_step(uint8_t l0);
static bool vader_front_parser$check(void* l0, uint8_t l1);
static bool vader_front_parser$check_at(void* l0, uint8_t l1, int32_t l2);
static void vader_front_parser$check_c_struct_arguments(void* l0, void* l1);
static bool vader_front_parser$check_closing_angle(void* l0);
static void vader_front_parser$check_guard_arity(void* l0, void* l1);
static void* vader_front_parser$compound_op(uint8_t l0);
static vader_box_t vader_front_parser$comptime_helper_marker(void* l0, vader_box_t l1);
static void* vader_front_parser$consume_closing_angle(void* l0);
static vader_box_t vader_front_parser$declared_binding(vader_box_t l0);
static vader_box_t vader_front_parser$decorator_spec(vader_string_t l0);
static vader_string_t vader_front_parser$describe_token(void* l0);
static void* vader_front_parser$desugar_comptime_const(void* l0, void* l1, uint8_t l2, void* l3, vader_box_t l4);
static bool vader_front_parser$ends_a_value(uint8_t l0);
static bool vader_front_parser$ends_its_line(void* l0, int32_t l1);
static void vader_front_parser$error(void* l0, uint8_t l1, void* l2, vader_string_t l3);
static void* vader_front_parser$expect(void* l0, uint8_t l1, vader_string_t l2);
static void* vader_front_parser$expect_string_literal(void* l0, vader_string_t l1);
static bool vader_front_parser$generic_use_follows(void* l0, int32_t l1);
static bool vader_front_parser$has_type_shape(vader_box_t l0);
static int64_t vader_front_parser$header_budget(int64_t l0);
static void* vader_front_parser$ident_expr(void* l0, vader_string_t l1);
static void* vader_front_parser$infix_for(uint8_t l0);
static bool vader_front_parser$is_angle_scan_bailout(uint8_t l0);
static bool vader_front_parser$is_bare_nullary_call(vader_box_t l0);
static bool vader_front_parser$is_impl_decl(void* l0);
static bool vader_front_parser$is_literal_start(void* l0);
static bool vader_front_parser$is_module_segment_continue(uint32_t l0);
static bool vader_front_parser$is_module_segment_start(uint32_t l0);
static bool vader_front_parser$is_number_token(void* l0);
static bool vader_front_parser$is_tuple_type(void* l0);
static bool vader_front_parser$is_type_operator(void* l0);
static bool vader_front_parser$is_type_union_operand(vader_box_t l0);
static bool vader_front_parser$is_valid_module_name(vader_string_t l0);
static uint8_t vader_front_parser$kind_after_bracket_group(void* l0);
static void* vader_front_parser$lift_trailing_return(void* l0);
static bool vader_front_parser$looks_like_for_destructure(void* l0);
static bool vader_front_parser$looks_like_struct_lit_body(void* l0, int32_t l1);
static vader_box_t vader_front_parser$match_kind(void* l0, uint8_t l1);
static void* vader_front_parser$match_or_peek(void* l0, uint8_t l1);
static vader_box_t vader_front_parser$match_scrutinee(void* l0, vader_box_t l1);
static void* vader_front_parser$no_infix(void);
static vader_box_t vader_front_parser$number_literal(void* l0, void* l1, bool l2);
static void* vader_front_parser$parse_angle_type_params(void* l0);
static void* vader_front_parser$parse_any_let(void* l0);
static vader_box_t vader_front_parser$parse_assert_decl(void* l0);
static vader_box_t vader_front_parser$parse_assign_target(void* l0);
static void* vader_front_parser$parse_block(void* l0);
static void* vader_front_parser$parse_break(void* l0);
static void* vader_front_parser$parse_call_args(void* l0);
static vader_box_t vader_front_parser$parse_coalesce_fallback(void* l0);
static void* vader_front_parser$parse_const_decl(void* l0, void* l1, uint8_t l2, void* l3);
static void* vader_front_parser$parse_continue(void* l0);
static vader_box_t vader_front_parser$parse_decl(void* l0);
static vader_box_t vader_front_parser$parse_decorated_decl(void* l0, void* l1, uint8_t l2);
static void* vader_front_parser$parse_decorator(void* l0);
static void* vader_front_parser$parse_decorators(void* l0);
static void* vader_front_parser$parse_defer(void* l0);
static void* vader_front_parser$parse_destructure_assign(void* l0);
static void* vader_front_parser$parse_enum_decl(void* l0, void* l1, uint8_t l2, void* l3);
static vader_box_t vader_front_parser$parse_expr(void* l0, int32_t l1);
static void* vader_front_parser$parse_fn_body_tail(void* l0);
static void* vader_front_parser$parse_fn_decl(void* l0, void* l1, uint8_t l2, void* l3);
static vader_box_t vader_front_parser$parse_fn_decl_inside_trait(void* l0);
static void* vader_front_parser$parse_fn_signature_params(void* l0);
static void* vader_front_parser$parse_fn_type(void* l0);
static void* vader_front_parser$parse_for(void* l0, vader_box_t l1, bool l2);
static vader_box_t vader_front_parser$parse_generic_use(void* l0, vader_box_t l1);
static vader_box_t vader_front_parser$parse_ident_or_struct_lit(void* l0);
static void* vader_front_parser$parse_if_expr(void* l0);
static void* vader_front_parser$parse_impl_decl(void* l0, void* l1);
static void* vader_front_parser$parse_import_decl(void* l0, void* l1);
static void* vader_front_parser$parse_import_name_list_rest(void* l0);
static void* vader_front_parser$parse_lambda(void* l0);
static void* vader_front_parser$parse_lambda_without_fn(void* l0);
static void* vader_front_parser$parse_let(void* l0);
static vader_box_t vader_front_parser$parse_let_binding(void* l0);
static void* vader_front_parser$parse_lexed(void* l0);
static void* vader_front_parser$parse_lhs_generic_alias_decl(void* l0, void* l1, uint8_t l2);
static void* vader_front_parser$parse_match_arm(void* l0);
static vader_box_t vader_front_parser$parse_match_declaration(void* l0);
static void* vader_front_parser$parse_match_expr(void* l0, bool l1, bool l2, void* l3);
static vader_box_t vader_front_parser$parse_named_decl(void* l0, void* l1, uint8_t l2);
static void* vader_front_parser$parse_named_import_decl(void* l0, void* l1, void* l2);
static vader_box_t vader_front_parser$parse_optional_module_decl(void* l0);
static vader_box_t vader_front_parser$parse_paren(void* l0);
static vader_box_t vader_front_parser$parse_pattern(void* l0);
static vader_box_t vader_front_parser$parse_postfix(void* l0, vader_box_t l1, void* l2);
static vader_box_t vader_front_parser$parse_prefix(void* l0);
static void* vader_front_parser$parse_program(void* l0);
static vader_box_t vader_front_parser$parse_range_bound(void* l0);
static vader_box_t vader_front_parser$parse_range_type(void* l0);
static void* vader_front_parser$parse_return(void* l0);
static void* vader_front_parser$parse_sam_arrow_member(void* l0);
static void* vader_front_parser$parse_sam_block_member(void* l0);
static void* vader_front_parser$parse_seq_lit(void* l0);
static void* vader_front_parser$parse_single_param_lambda_tail(void* l0, void* l1);
static vader_box_t vader_front_parser$parse_stmt(void* l0);
static void* vader_front_parser$parse_string_lit(void* l0);
static void* vader_front_parser$parse_struct_decl(void* l0, void* l1, uint8_t l2, void* l3);
static void* vader_front_parser$parse_struct_lit_fields(void* l0);
static void* vader_front_parser$parse_struct_pattern(void* l0);
static void* vader_front_parser$parse_trait_decl(void* l0, void* l1, uint8_t l2, void* l3);
static void* vader_front_parser$parse_tuple_let(void* l0);
static vader_box_t vader_front_parser$parse_type(void* l0);
static vader_box_t vader_front_parser$parse_type_intersection(void* l0);
static void* vader_front_parser$parse_type_list_until_angle(void* l0);
static vader_box_t vader_front_parser$parse_type_postfix(void* l0);
static vader_box_t vader_front_parser$parse_type_primary(void* l0);
static void* vader_front_parser$parse_typed_const_decl(void* l0, void* l1, uint8_t l2);
static void* vader_front_parser$parse_typed_let(void* l0);
static void* vader_front_parser$parse_yield(void* l0);
static void* vader_front_parser$peek(void* l0);
static void* vader_front_parser$peek_at(void* l0, int32_t l1);
static bool vader_front_parser$peek_is_classic_impl_body(void* l0);
static bool vader_front_parser$peek_is_lhs_generic_alias_head(void* l0);
static bool vader_front_parser$peek_lambda_without_fn(void* l0);
static vader_box_t vader_front_parser$place_text(vader_box_t l0);
static int32_t vader_front_parser$postfix_bp(uint8_t l0);
static void vader_front_parser$reject_alternative_bindings(void* l0, vader_box_t l1);
static void vader_front_parser$reject_as_binder(void* l0, uint8_t l1, void* l2);
static void vader_front_parser$reject_assert_decorator(void* l0, void* l1);
static void vader_front_parser$reject_c_decorators(void* l0, void* l1, vader_string_t l2);
static void vader_front_parser$reject_displayable_decorator(void* l0, void* l1);
static void vader_front_parser$reject_free_fn_decorators(void* l0, void* l1, vader_string_t l2, vader_string_t l3);
static void vader_front_parser$reject_removed_const(void* l0);
static void* vader_front_parser$reject_tuple_pattern(void* l0);
static void vader_front_parser$report_nesting_too_deep(void* l0, vader_string_t l1);
static bool vader_front_parser$scan_angle_generic(void* l0, int32_t l1);
static void vader_front_parser$set_decl_doc(vader_box_t l0, void* l1);
static int64_t vader_front_parser$skip_block_comment(vader_string_t l0, int64_t l1);
static void vader_front_parser$skip_newlines(void* l0);
static int64_t vader_front_parser$skip_to_eol(vader_string_t l0, int64_t l1);
static void* vader_front_parser$span_of(void* l0, void* l1, void* l2);
static bool vader_front_parser$starts_let(void* l0);
static vader_box_t vader_front_parser$static_assert_message(void* l0, vader_box_t l1);
static void vader_front_parser$sync_to_top_level(void* l0);
static vader_box_t vader_front_parser$take_doc(void* l0);
static void* vader_front_parser$through_comptime_helper(void* l0, void* l1, uint8_t l2, void* l3, vader_box_t l4, vader_box_t l5, void* l6, bool l7);
static void vader_front_parser$walk_assign_target(vader_box_t l0, void* l1);
static void vader_front_parser$walk_block(void* l0, void* l1);
static void vader_front_parser$walk_decl(vader_box_t l0, void* l1);
static void vader_front_parser$walk_decorator(void* l0, void* l1);
static void vader_front_parser$walk_expr(vader_box_t l0, void* l1);
static void vader_front_parser$walk_fn_decl(void* l0, void* l1);
static void vader_front_parser$walk_fn_param(void* l0, void* l1);
static void vader_front_parser$walk_for_form(vader_box_t l0, void* l1);
static void vader_front_parser$walk_import_binding(vader_box_t l0, void* l1);
static void vader_front_parser$walk_let_binding(vader_box_t l0, void* l1);
static void vader_front_parser$walk_pattern(vader_box_t l0, void* l1);
static void vader_front_parser$walk_stmt(vader_box_t l0, void* l1);
static void vader_front_parser$walk_struct_lit_items(void* l0, void* l1);
static void vader_front_parser$walk_type_param(void* l0, void* l1);
static void* vader_front_parser$wrap_as_block(vader_box_t l0);

static void* vader_front_parser$advance(void* l0) {
    void* l1;
    int32_t l2, l3;
    int64_t t0;
    int32_t t1;
    l1 = vader_front_parser$peek(l0);
    if (((vader_struct_vader_front_parser$Parser_t*) l0)->f_shr_pending_half.tag == 0u) {
        l2 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_pos;
        t0 = ((vader_array_t*) ((vader_struct_vader_front_parser$Parser_t*) l0)->f_tokens)->length;
        l3 = vader_chk_sub(i32, ((int32_t) (int64_t) t0), INT32_C(1));
        if ((l2 < l3)) {
            t1 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_pos;
            l2 = vader_chk_add(i32, t1, INT32_C(1));
            ((vader_struct_vader_front_parser$Parser_t*) l0)->f_pos = l2;
        }
    } else {
        ((vader_struct_vader_front_parser$Parser_t*) l0)->f_shr_pending_half = vader_box_obj(0u, NULL);
        VADER_WRITE_BARRIER((vader_struct_vader_front_parser$Parser_t*) l0);
    }
    l2 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_bracket_depth;
    l3 = vader_front_parser$bracket_step(((vader_struct_vader_front_lexer$Token_t*) l1)->f_kind);
    l2 = vader_chk_add(i32, l2, l3);
    ((vader_struct_vader_front_parser$Parser_t*) l0)->f_bracket_depth = l2;
    return l1;
}

static bool vader_front_parser$allows_bare_lambda(void* l0) {
    int32_t l1, l2;
    l1 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_bracket_depth;
    l2 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_no_bare_lambda_at;
    return l1 != l2;
}

static bool vader_front_parser$allows_struct_lit(void* l0) {
    int32_t l1, l2;
    l1 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_bracket_depth;
    l2 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_no_struct_lit_at;
    return l1 != l2;
}

uint8_t vader_front_parser$arg_kind(void* l0, int64_t l1) {
    int64_t l2;
    vader_box_t t0;
    l2 = ((vader_array_t*) ((vader_struct_vader_front_parser$IntrinsicSpec_t*) l0)->f_args)->length;
    if (!((l1 < l2))) {
        return (uint8_t) 1;
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_front_parser$IntrinsicSpec_t*) l0)->f_args);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l1, 452u);
    return ((uint8_t) t0.payload.i);
}

void vader_front_parser$assign_program_ids(void* l0, void* l1) {
    int64_t l2, l4;
    void* l3;
    vader_box_t t0;
    l2 = vader_front_parser$mint(l1);
    ((vader_struct_toolchain_ast$Program_t*) l0)->f_id = l2;
    if (!(((vader_struct_toolchain_ast$Program_t*) l0)->f_module.tag == 0u)) {
        t0 = ((vader_struct_toolchain_ast$Program_t*) l0)->f_module;
        l3 = t0.payload.obj;
        l2 = vader_front_parser$mint(l1);
        ((vader_struct_toolchain_ast$ModuleDecl_t*) l3)->f_id = l2;
    }
    l3 = ((vader_struct_toolchain_ast$Program_t*) l0)->f_decls;
    l2 = ((vader_array_t*) l3)->length;
    l4 = INT64_C(0);
    while ((l4 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        vader_front_parser$walk_decl(t0, l1);
        l4 = (l4 + INT64_C(1));
    }
    return;
}

static bool vader_front_parser$at_top_level_start(void* l0) {
    void* l1;
    void* l2;
    l1 = vader_front_parser$peek(l0);
    if (((vader_struct_vader_front_lexer$Token_t*) l1)->f_kind == INT32_C(28)) {
        return true;
    }
    if (((vader_struct_vader_front_lexer$Token_t*) l1)->f_kind == INT32_C(30)) {
        return true;
    }
    if (((vader_struct_vader_front_lexer$Token_t*) l1)->f_kind == INT32_C(2)) {
        l2 = vader_front_parser$peek_at(l0, INT32_C(1));
        if (((vader_struct_vader_front_lexer$Token_t*) l2)->f_kind == INT32_C(71)) {
            return true;
        }
        if (((vader_struct_vader_front_lexer$Token_t*) l2)->f_kind == INT32_C(14)) {
            return true;
        }
    }
    if (!(((vader_struct_vader_front_lexer$Token_t*) l1)->f_kind == INT32_C(78))) {
        return false;
    }
    return true;
}

static int32_t vader_front_parser$bracket_step(uint8_t l0) {
    if (l0 == INT32_C(79)) {
        return INT32_C(1);
    }
    if (l0 == INT32_C(81)) {
        return INT32_C(1);
    }
    if (l0 == INT32_C(83)) {
        return INT32_C(1);
    }
    if (l0 == INT32_C(9)) {
        return INT32_C(1);
    }
    if (l0 == INT32_C(80)) {
        return INT32_C(-1);
    }
    if (l0 == INT32_C(82)) {
        return INT32_C(-1);
    }
    if (l0 == INT32_C(84)) {
        return INT32_C(-1);
    }
    if (!(l0 == INT32_C(10))) {
        return INT32_C(0);
    }
    return INT32_C(-1);
}

static bool vader_front_parser$check(void* l0, uint8_t l1) {
    void* t0;
    t0 = vader_front_parser$peek(l0);
    return ((vader_struct_vader_front_lexer$Token_t*) t0)->f_kind == l1;
}

static bool vader_front_parser$check_at(void* l0, uint8_t l1, int32_t l2) {
    void* t0;
    t0 = vader_front_parser$peek_at(l0, l2);
    return ((vader_struct_vader_front_lexer$Token_t*) t0)->f_kind == l1;
}

static void vader_front_parser$check_c_struct_arguments(void* l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    vader_box_t l3 = vader_box_null();
    int64_t t0;
    vader_box_t t1 = vader_box_null(), t2 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l3, &t1, &t2 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = toolchain_ast$find_decorator(l1, 1706u);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l2 = l3.payload.obj;
    t0 = ((vader_array_t*) ((vader_struct_toolchain_ast$Decorator_t*) l2)->f_args)->length;
    if ((t0 > INT64_C(1))) {
        l4 = ((vader_struct_toolchain_ast$Decorator_t*) l2)->f_span;
        vader_front_parser$error(l0, (uint8_t) 16, l4, 1337u);
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = ((vader_array_t*) ((vader_struct_toolchain_ast$Decorator_t*) l2)->f_args)->length;
    if (t0 == INT64_C(1)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$Decorator_t*) l2)->f_args);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
        t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
        t2 = toolchain_ast$string_literal_text(t1);
        if (t2.tag == 0u) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$Decorator_t*) l2)->f_args);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
            t1 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT32_C(0));
            l2 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, t1.payload.obj);
            vader_front_parser$error(l0, (uint8_t) 17, l2, 1336u);
            { vader_gc_top = gc_frame.prev; return; }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_front_parser$check_closing_angle(void* l0) {
    uint8_t l1;
    void* t0;
    if (!(((vader_struct_vader_front_parser$Parser_t*) l0)->f_shr_pending_half.tag == 0u)) {
        return true;
    }
    t0 = vader_front_parser$peek(l0);
    l1 = ((vader_struct_vader_front_lexer$Token_t*) t0)->f_kind;
    if (l1 == INT32_C(54)) {
        return true;
    }
    return l1 == INT32_C(49);
}

static void vader_front_parser$check_guard_arity(void* l0, void* l1) {
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
        l6 = ((vader_struct_toolchain_ast$Decorator_t*) l5)->f_name;
        {
            if (!(l6 == 2531u)) {
                t0 = ((vader_struct_toolchain_ast$Decorator_t*) l5)->f_name;
                if (!(t0 == 1881u)) {
                    goto end_18;
                }
            }
            t1 = ((vader_array_t*) ((vader_struct_toolchain_ast$Decorator_t*) l5)->f_args)->length;
            if (t1 != INT64_C(1)) {
                l7 = ((vader_struct_toolchain_ast$Decorator_t*) l5)->f_span;
                l8 = ((vader_struct_toolchain_ast$Decorator_t*) l5)->f_name;
                l9 = ((vader_struct_toolchain_ast$Decorator_t*) l5)->f_name;
                l10 = concat_5(1327u, l8, 1087u, l9, 316u);
                vader_front_parser$error(l0, (uint8_t) 16, l7, l10);
            }
        } end_18: ;
        l4 = (l4 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_front_parser$compound_op(uint8_t l0) {
    void* l1 = NULL;
    void** gc_raw_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(63)) {
        vader_struct_vader_front_parser$CompoundOpResult_t* _a0_obj = (vader_struct_vader_front_parser$CompoundOpResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_parser$CompoundOpResult_t));
        vader_obj_header_init(_a0_obj, 1196u);
        _a0_obj->f_matched = true;
        _a0_obj->f_op = (uint8_t) 0;
        l1 = (void*) _a0_obj;
        { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(64)) {
        vader_struct_vader_front_parser$CompoundOpResult_t* _a1_obj = (vader_struct_vader_front_parser$CompoundOpResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_parser$CompoundOpResult_t));
        vader_obj_header_init(_a1_obj, 1196u);
        _a1_obj->f_matched = true;
        _a1_obj->f_op = (uint8_t) 1;
        l1 = (void*) _a1_obj;
    } else if (l0 == INT32_C(65)) {
        vader_struct_vader_front_parser$CompoundOpResult_t* _a2_obj = (vader_struct_vader_front_parser$CompoundOpResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_parser$CompoundOpResult_t));
        vader_obj_header_init(_a2_obj, 1196u);
        _a2_obj->f_matched = true;
        _a2_obj->f_op = (uint8_t) 2;
        l1 = (void*) _a2_obj;
    } else if (l0 == INT32_C(66)) {
        vader_struct_vader_front_parser$CompoundOpResult_t* _a3_obj = (vader_struct_vader_front_parser$CompoundOpResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_parser$CompoundOpResult_t));
        vader_obj_header_init(_a3_obj, 1196u);
        _a3_obj->f_matched = true;
        _a3_obj->f_op = (uint8_t) 3;
        l1 = (void*) _a3_obj;
    } else if (l0 == INT32_C(67)) {
        vader_struct_vader_front_parser$CompoundOpResult_t* _a4_obj = (vader_struct_vader_front_parser$CompoundOpResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_parser$CompoundOpResult_t));
        vader_obj_header_init(_a4_obj, 1196u);
        _a4_obj->f_matched = true;
        _a4_obj->f_op = (uint8_t) 4;
        l1 = (void*) _a4_obj;
    } else if (l0 == INT32_C(68)) {
        vader_struct_vader_front_parser$CompoundOpResult_t* _a5_obj = (vader_struct_vader_front_parser$CompoundOpResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_parser$CompoundOpResult_t));
        vader_obj_header_init(_a5_obj, 1196u);
        _a5_obj->f_matched = true;
        _a5_obj->f_op = (uint8_t) 23;
        l1 = (void*) _a5_obj;
    } else if (l0 == INT32_C(69)) {
        vader_struct_vader_front_parser$CompoundOpResult_t* _a6_obj = (vader_struct_vader_front_parser$CompoundOpResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_parser$CompoundOpResult_t));
        vader_obj_header_init(_a6_obj, 1196u);
        _a6_obj->f_matched = true;
        _a6_obj->f_op = (uint8_t) 24;
        l1 = (void*) _a6_obj;
    } else if (l0 == INT32_C(70)) {
        vader_struct_vader_front_parser$CompoundOpResult_t* _a7_obj = (vader_struct_vader_front_parser$CompoundOpResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_parser$CompoundOpResult_t));
        vader_obj_header_init(_a7_obj, 1196u);
        _a7_obj->f_matched = true;
        _a7_obj->f_op = (uint8_t) 25;
        l1 = (void*) _a7_obj;
    } else {
        vader_struct_vader_front_parser$CompoundOpResult_t* _a8_obj = (vader_struct_vader_front_parser$CompoundOpResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_parser$CompoundOpResult_t));
        vader_obj_header_init(_a8_obj, 1196u);
        _a8_obj->f_matched = false;
        _a8_obj->f_op = (uint8_t) 0;
        l1 = (void*) _a8_obj;
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_parser$comptime_helper_marker(void* l0, vader_box_t l1) {
    void* l2;
    vader_box_t l3;
    bool t0;
    t0 = vader_front_parser$is_bare_nullary_call(l1);
    if (t0) {
        return vader_box_obj(0u, NULL);
    }
    l3 = toolchain_ast$find_decorator(l0, 1778u);
    if (l3.tag == 0u) {
        return vader_box_obj(0u, NULL);
    }
    l2 = l3.payload.obj;
    t0 = vader_front_parser$has_type_shape(l1);
    if (!(t0)) {
        return vader_ref_box(((vader_struct_toolchain_ast$Decorator_t*) l2)->f_span);
    }
    return vader_box_obj(0u, NULL);
}

static void* vader_front_parser$consume_closing_angle(void* l0) {
    vader_box_t l1 = vader_box_null();
    void* l2 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    int32_t l3, l4;
    vader_string_t l5 = 0;
    int64_t l6;
    void* t0 = NULL;
    int64_t t1;
    int32_t t2;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[5] = { &l0, &l2, &l7, &l8, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_shr_pending_half;
    if (!(l1.tag == 0u)) {
        ((vader_struct_vader_front_parser$Parser_t*) l0)->f_shr_pending_half = vader_box_obj(0u, NULL);
        VADER_WRITE_BARRIER((vader_struct_vader_front_parser$Parser_t*) l0);
        l2 = l1.payload.obj;
        ((vader_struct_vader_front_parser$Parser_t*) l0)->f_split_half = vader_ref_box(l2);
        VADER_WRITE_BARRIER((vader_struct_vader_front_parser$Parser_t*) l0);
        l3 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_pos;
        ((vader_struct_vader_front_parser$Parser_t*) l0)->f_split_at = l3;
        t0 = l1.payload.obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = vader_front_parser$peek(l0);
    if (((vader_struct_vader_front_lexer$Token_t*) l2)->f_kind == INT32_C(54)) {
        l3 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_pos;
        t1 = ((vader_array_t*) ((vader_struct_vader_front_parser$Parser_t*) l0)->f_tokens)->length;
        l4 = vader_chk_sub(i32, ((int32_t) (int64_t) t1), INT32_C(1));
        if ((l3 < l4)) {
            t2 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_pos;
            l3 = vader_chk_add(i32, t2, INT32_C(1));
            ((vader_struct_vader_front_parser$Parser_t*) l0)->f_pos = l3;
            { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
        }
        { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(((vader_struct_vader_front_lexer$Token_t*) l2)->f_kind == INT32_C(49))) {
        { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_front_lexer$Token_t*) l2)->f_span)->f_start)->f_file;
    t1 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_front_lexer$Token_t*) l2)->f_span)->f_start)->f_offset;
    l6 = vader_chk_add(i64, t1, INT64_C(1));
    l3 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_front_lexer$Token_t*) l2)->f_span)->f_start)->f_line;
    t2 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_front_lexer$Token_t*) l2)->f_span)->f_start)->f_column;
    l4 = vader_chk_add(i32, t2, INT32_C(1));
    vader_struct_toolchain_span$Position_t* _a0_obj = (vader_struct_toolchain_span$Position_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Position_t));
    vader_obj_header_init(_a0_obj, 834u);
    _a0_obj->f_file = l5;
    _a0_obj->f_offset = l6;
    _a0_obj->f_line = l3;
    _a0_obj->f_column = l4;
    l7 = (void*) _a0_obj;
    vader_struct_toolchain_span$Span_t* _a1_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
    vader_obj_header_init(_a1_obj, 835u);
    _a1_obj->f_start = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_front_lexer$Token_t*) l2)->f_span)->f_start;
    _a1_obj->f_end = l7;
    l8 = (void*) _a1_obj;
    vader_struct_vader_front_lexer$Token_t* _a2_obj = (vader_struct_vader_front_lexer$Token_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_lexer$Token_t));
    vader_obj_header_init(_a2_obj, 1191u);
    _a2_obj->f_kind = (uint8_t) 54;
    _a2_obj->f_text = 526u;
    _a2_obj->f_span = l8;
    _a2_obj->f_value = vader_box_obj(0u, NULL);
    l8 = (void*) _a2_obj;
    l2 = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_front_lexer$Token_t*) l2)->f_span)->f_end;
    vader_struct_toolchain_span$Span_t* _a3_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
    vader_obj_header_init(_a3_obj, 835u);
    _a3_obj->f_start = l7;
    _a3_obj->f_end = l2;
    l2 = (void*) _a3_obj;
    vader_struct_vader_front_lexer$Token_t* _a4_obj = (vader_struct_vader_front_lexer$Token_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_lexer$Token_t));
    vader_obj_header_init(_a4_obj, 1191u);
    _a4_obj->f_kind = (uint8_t) 54;
    _a4_obj->f_text = 526u;
    _a4_obj->f_span = l2;
    _a4_obj->f_value = vader_box_obj(0u, NULL);
    l2 = (void*) _a4_obj;
    ((vader_struct_vader_front_parser$Parser_t*) l0)->f_shr_pending_half = vader_ref_box(l2);
    VADER_WRITE_BARRIER((vader_struct_vader_front_parser$Parser_t*) l0);
    l3 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_pos;
    t1 = ((vader_array_t*) ((vader_struct_vader_front_parser$Parser_t*) l0)->f_tokens)->length;
    l4 = vader_chk_sub(i32, ((int32_t) (int64_t) t1), INT32_C(1));
    if ((l3 < l4)) {
        t2 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_pos;
        l3 = vader_chk_add(i32, t2, INT32_C(1));
        ((vader_struct_vader_front_parser$Parser_t*) l0)->f_pos = l3;
    }
    ((vader_struct_vader_front_parser$Parser_t*) l0)->f_split_half = vader_ref_box(l8);
    VADER_WRITE_BARRIER((vader_struct_vader_front_parser$Parser_t*) l0);
    l3 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_pos;
    ((vader_struct_vader_front_parser$Parser_t*) l0)->f_split_at = l3;
    { void* __vret = l8; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_parser$declared_binding(vader_box_t l0) {
    vader_box_t l1;
    void* t0;
    if (l0.tag == 0u) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l0.payload.obj;
    l1 = ((vader_struct_toolchain_ast$LetStmt_t*) t0)->f_binding;
    if (!(l1.tag == 812u)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l1.payload.obj;
    return vader_ref_box(t0);
}

bool vader_front_parser$decorator_on(vader_string_t l0, uint8_t l1) {
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
    l3 = vader_front_parser$decorator_spec(l0);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    l2 = l3.payload.obj;
    t0 = std_core$$array$Contains$contains__vader_front_parser_DecoratorPlace(((vader_struct_vader_front_parser$DecoratorSpec_t*) l2)->f_places, l1);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_parser$decorator_spec(vader_string_t l0) {
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
    l1 = __const_vader_front_parser$DECORATORS();
    l2 = ((vader_array_t*) l1)->length;
    l3 = INT64_C(0);
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        t0 = ((vader_struct_vader_front_parser$DecoratorSpec_t*) l4)->f_name;
        if (t0 == l0) {
            { vader_box_t __vret = vader_ref_box(l4); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l3 = (l3 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_string_t vader_front_parser$describe_token(void* l0) {
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
    if (((vader_struct_vader_front_lexer$Token_t*) l0)->f_kind == INT32_C(2)) {
        l1 = ((vader_struct_vader_front_lexer$Token_t*) l0)->f_text;
        t0 = concat_3(1033u, l1, 1033u);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_front_lexer$Token_t*) l0)->f_kind == INT32_C(3)) {
        l2 = true;
    } else {
        l2 = ((vader_struct_vader_front_lexer$Token_t*) l0)->f_kind == INT32_C(4);
    }
    if (l2) {
        t0 = ((vader_struct_vader_front_lexer$Token_t*) l0)->f_text;
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_front_lexer$Token_t*) l0)->f_kind == INT32_C(1)) {
        { vader_gc_top = gc_frame.prev; return 2378u; }
    }
    if (((vader_struct_vader_front_lexer$Token_t*) l0)->f_kind == INT32_C(0)) {
        { vader_gc_top = gc_frame.prev; return 1878u; }
    }
    t0 = ((vader_struct_vader_front_lexer$Token_t*) l0)->f_text;
    t1 = std_string$is_empty(t0);
    if (!(t1)) {
        l1 = ((vader_struct_vader_front_lexer$Token_t*) l0)->f_text;
        t0 = concat_3(1033u, l1, 1033u);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_front_lexer$kind_name(((vader_struct_vader_front_lexer$Token_t*) l0)->f_kind);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_parser$desugar_comptime_const(void* l0, void* l1, uint8_t l2, void* l3, vader_box_t l4) {
    void* l5 = NULL;
    void* l6 = NULL;
    vader_box_t l7 = vader_box_null();
    bool t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l4, &l7 };
    void** gc_raw_roots[6] = { &l0, &l1, &l3, &l5, &l6, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l5 = vader_front_parser$advance(l0);
    l6 = vader_front_parser$advance(l0);
    t0 = vader_front_parser$check(l0, (uint8_t) 83);
    if (t0) {
        t1 = vader_front_parser$parse_block(l0);
        l7 = vader_ref_box(t1);
    } else {
        l7 = vader_front_parser$parse_expr(l0, INT32_C(0));
    }
    l5 = vader_front_parser$span_of(l0, l5, l6);
    t1 = vader_front_parser$through_comptime_helper(l0, l1, l2, l3, l4, l7, l5, false);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_front_parser$ends_a_value(uint8_t l0) {
    bool l1;
    int32_t t0;
    t0 = vader_front_parser$bracket_step(l0);
    if ((t0 < INT32_C(0))) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(85);
    }
    if (l1) {
        return true;
    }
    return l0 == INT32_C(0);
}

static bool vader_front_parser$ends_its_line(void* l0, int32_t l1) {
    void* l2;
    int32_t l3, l4;
    void* t0;
    l2 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_tokens;
    l3 = vader_chk_add(i32, l1, INT32_C(1));
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    l3 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_front_lexer$Token_t*) t0)->f_span)->f_start)->f_line;
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_front_parser$Parser_t*) l0)->f_tokens);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
    t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l1);
    l4 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_front_lexer$Token_t*) t0)->f_span)->f_end)->f_line;
    return (l3 > l4);
}

static void vader_front_parser$error(void* l0, uint8_t l1, void* l2, vader_string_t l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    bool t0;
    void** gc_raw_roots[4] = { &l0, &l2, &l4, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_depth_exceeded;
    if (!(t0)) {
        l4 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_errors;
        l5 = vader_support_diagnostics$parser_error(l1, l2, l3);
        vader_array_push_ref((vader_array_t*) l4, l5);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_front_parser$expect(void* l0, uint8_t l1, vader_string_t l2) {
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
    t0 = vader_front_parser$check(l0, l1);
    if (!(t0)) {
        l3 = vader_front_parser$peek(l0);
        l4 = ((vader_struct_vader_front_lexer$Token_t*) l3)->f_span;
        l5 = vader_front_parser$describe_token(l3);
        l5 = concat_5(1914u, l2, 53u, l5, 324u);
        vader_front_parser$error(l0, (uint8_t) 1, l4, l5);
        { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_front_parser$advance(l0);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_parser$expect_string_literal(void* l0, vader_string_t l1) {
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
    t0 = vader_front_parser$check(l0, (uint8_t) 6);
    if (!(t0)) {
        l2 = vader_front_parser$peek(l0);
        l3 = ((vader_struct_vader_front_lexer$Token_t*) l2)->f_span;
        l4 = vader_front_parser$describe_token(l2);
        l4 = concat_5(1914u, l1, 53u, l4, 324u);
        vader_front_parser$error(l0, (uint8_t) 1, l3, l4);
        l2 = ((vader_struct_vader_front_lexer$Token_t*) l2)->f_span;
        vader_struct_vader_front_parser$StringLitInfo_t* _a0_obj = (vader_struct_vader_front_parser$StringLitInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_parser$StringLitInfo_t));
        vader_obj_header_init(_a0_obj, 1206u);
        _a0_obj->f_text = 0u;
        _a0_obj->f_span = l2;
        t1 = (void*) _a0_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = vader_front_parser$advance(l0);
    vader_array_t* _a1_arr = vader_array_new(22u, 0u, 0u, 447u);
    t1 = (void*) _a1_arr;
    vader_struct_std_string__builder$StringBuilder_t* _a2_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
    vader_obj_header_init(_a2_obj, 741u);
    _a2_obj->f_parts = t1;
    l3 = (void*) _a2_obj;
    for (;;) {
        t0 = vader_front_parser$check(l0, (uint8_t) 8);
        if (!(t0)) {
            t0 = vader_front_parser$check(l0, (uint8_t) 0);
            if (t0) break;
            l5 = vader_front_parser$advance(l0);
            if (((vader_struct_vader_front_lexer$Token_t*) l5)->f_kind == INT32_C(7)) {
                l6 = ((vader_struct_vader_front_lexer$Token_t*) l5)->f_value;
                if (l6.tag == 447u) {
                    l4 = l6.payload.s;
                    std_string__builder$append(l3, l4);
                } else {
                    l7 = ((vader_struct_vader_front_lexer$Token_t*) l5)->f_text;
                    std_string__builder$append(l3, l7);
                }
            }
            if (!(((vader_struct_vader_front_lexer$Token_t*) l5)->f_kind == INT32_C(9))) {
                continue;
            }
            l8 = ((vader_struct_vader_front_lexer$Token_t*) l5)->f_span;
            vader_front_parser$error(l0, (uint8_t) 0, l8, 2186u);
            for (;;) {
                t0 = vader_front_parser$check(l0, (uint8_t) 10);
                if (!(t0)) {
                    t0 = vader_front_parser$check(l0, (uint8_t) 0);
                    if (t0) break;
                    vader_front_parser$advance(l0);
                    continue;
                }
                break;
            }
            continue;
        }
        break;
    }
    l5 = vader_front_parser$match_or_peek(l0, (uint8_t) 8);
    l4 = std_string__builder$StringBuilder$std_core$Display$to_string(l3);
    l2 = vader_front_parser$span_of(l0, l2, l5);
    vader_struct_vader_front_parser$StringLitInfo_t* _a3_obj = (vader_struct_vader_front_parser$StringLitInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_parser$StringLitInfo_t));
    vader_obj_header_init(_a3_obj, 1206u);
    _a3_obj->f_text = l4;
    _a3_obj->f_span = l2;
    t1 = (void*) _a3_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_front_parser$generic_use_follows(void* l0, int32_t l1) {
    int32_t l2, l4;
    void* l3;
    uint8_t l5;
    bool l6;
    int64_t t0;
    int32_t t1;
    void* t2;
    bool t3;
    t0 = ((vader_array_t*) ((vader_struct_vader_front_parser$Parser_t*) l0)->f_tokens)->length;
    l2 = ((int32_t) (int64_t) t0);
    t1 = vader_chk_add(i32, l1, INT32_C(1));
    if ((t1 >= l2)) {
        return false;
    }
    l3 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_tokens;
    l4 = vader_chk_add(i32, l1, INT32_C(1));
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    t2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
    l5 = ((vader_struct_vader_front_lexer$Token_t*) t2)->f_kind;
    if (l5 == INT32_C(79)) {
        return true;
    }
    if (l5 == INT32_C(83)) {
        return true;
    }
    t3 = vader_front_parser$ends_a_value(l5);
    if (t3) {
        return true;
    }
    t3 = vader_front_parser$ends_its_line(l0, l1);
    if (t3) {
        return true;
    }
    if (l5 == INT32_C(86)) {
        t1 = vader_chk_add(i32, l1, INT32_C(2));
        l6 = (t1 < l2);
    } else {
        l6 = false;
    }
    if (l6) {
        l3 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_tokens;
        l2 = vader_chk_add(i32, l1, INT32_C(2));
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
        t2 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l2);
        return ((vader_struct_vader_front_lexer$Token_t*) t2)->f_kind == INT32_C(2);
    }
    return false;
}

static bool vader_front_parser$has_type_shape(vader_box_t l0) {
    bool l1;
    void* t0;
    if ((l0.tag == 742u || l0.tag == 775u || l0.tag == 778u)) {
        l1 = true;
        return l1;
    }
    if (l0.tag == 771u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast$FieldExpr_t*) t0)->f_target.tag == 778u;
    } else if (l0.tag == 777u) {
        t0 = l0.payload.obj;
        l1 = vader_front_parser$has_type_shape(((vader_struct_toolchain_ast$GenericInstExpr_t*) t0)->f_callee);
    } else if (l0.tag == 746u) {
        t0 = l0.payload.obj;
        l1 = vader_front_parser$is_type_operator(t0);
    } else if (l0.tag == 811u) {
        t0 = l0.payload.obj;
        l1 = vader_front_parser$is_tuple_type(((vader_struct_toolchain_ast$SeqLitExpr_t*) t0)->f_elements);
    } else {
        l1 = false;
    }
    return l1;
}

static int64_t vader_front_parser$header_budget(int64_t l0) {
    int64_t l1;
    l1 = INT64_C(4096);
    if (!((l0 < l1))) {
        return l1;
    }
    return l0;
}

static void* vader_front_parser$ident_expr(void* l0, vader_string_t l1) {
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_toolchain_ast$IdentExpr_t* _a0_obj = (vader_struct_toolchain_ast$IdentExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$IdentExpr_t));
    vader_obj_header_init(_a0_obj, 778u);
    _a0_obj->f_span = l0;
    _a0_obj->f_id = INT64_C(0);
    _a0_obj->f_name = l1;
    _a0_obj->f_implicit_dot = false;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_parser$infix_for(uint8_t l0) {
    void* l1 = NULL;
    void** gc_raw_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(59)) {
        vader_struct_vader_front_parser$InfixOpDescr_t* _a0_obj = (vader_struct_vader_front_parser$InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_parser$InfixOpDescr_t));
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
        vader_struct_vader_front_parser$InfixOpDescr_t* _a1_obj = (vader_struct_vader_front_parser$InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_parser$InfixOpDescr_t));
        vader_obj_header_init(_a1_obj, 1200u);
        _a1_obj->f_has = true;
        _a1_obj->f_left_bp = INT32_C(12);
        _a1_obj->f_right_bp = INT32_C(13);
        _a1_obj->f_op = (uint8_t) 10;
        _a1_obj->f_non_assoc = false;
        l1 = (void*) _a1_obj;
    } else if (l0 == INT32_C(50)) {
        vader_struct_vader_front_parser$InfixOpDescr_t* _a2_obj = (vader_struct_vader_front_parser$InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_parser$InfixOpDescr_t));
        vader_obj_header_init(_a2_obj, 1200u);
        _a2_obj->f_has = true;
        _a2_obj->f_left_bp = INT32_C(20);
        _a2_obj->f_right_bp = INT32_C(20);
        _a2_obj->f_op = (uint8_t) 12;
        _a2_obj->f_non_assoc = true;
        l1 = (void*) _a2_obj;
    } else if (l0 == INT32_C(51)) {
        vader_struct_vader_front_parser$InfixOpDescr_t* _a3_obj = (vader_struct_vader_front_parser$InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_parser$InfixOpDescr_t));
        vader_obj_header_init(_a3_obj, 1200u);
        _a3_obj->f_has = true;
        _a3_obj->f_left_bp = INT32_C(20);
        _a3_obj->f_right_bp = INT32_C(20);
        _a3_obj->f_op = (uint8_t) 13;
        _a3_obj->f_non_assoc = true;
        l1 = (void*) _a3_obj;
    } else if (l0 == INT32_C(56)) {
        vader_struct_vader_front_parser$InfixOpDescr_t* _a4_obj = (vader_struct_vader_front_parser$InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_parser$InfixOpDescr_t));
        vader_obj_header_init(_a4_obj, 1200u);
        _a4_obj->f_has = true;
        _a4_obj->f_left_bp = INT32_C(20);
        _a4_obj->f_right_bp = INT32_C(20);
        _a4_obj->f_op = (uint8_t) 21;
        _a4_obj->f_non_assoc = true;
        l1 = (void*) _a4_obj;
    } else if (l0 == INT32_C(57)) {
        vader_struct_vader_front_parser$InfixOpDescr_t* _a5_obj = (vader_struct_vader_front_parser$InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_parser$InfixOpDescr_t));
        vader_obj_header_init(_a5_obj, 1200u);
        _a5_obj->f_has = true;
        _a5_obj->f_left_bp = INT32_C(20);
        _a5_obj->f_right_bp = INT32_C(20);
        _a5_obj->f_op = (uint8_t) 22;
        _a5_obj->f_non_assoc = true;
        l1 = (void*) _a5_obj;
    } else if (l0 == INT32_C(52)) {
        vader_struct_vader_front_parser$InfixOpDescr_t* _a6_obj = (vader_struct_vader_front_parser$InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_parser$InfixOpDescr_t));
        vader_obj_header_init(_a6_obj, 1200u);
        _a6_obj->f_has = true;
        _a6_obj->f_left_bp = INT32_C(20);
        _a6_obj->f_right_bp = INT32_C(20);
        _a6_obj->f_op = (uint8_t) 14;
        _a6_obj->f_non_assoc = true;
        l1 = (void*) _a6_obj;
    } else if (l0 == INT32_C(53)) {
        vader_struct_vader_front_parser$InfixOpDescr_t* _a7_obj = (vader_struct_vader_front_parser$InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_parser$InfixOpDescr_t));
        vader_obj_header_init(_a7_obj, 1200u);
        _a7_obj->f_has = true;
        _a7_obj->f_left_bp = INT32_C(20);
        _a7_obj->f_right_bp = INT32_C(20);
        _a7_obj->f_op = (uint8_t) 15;
        _a7_obj->f_non_assoc = true;
        l1 = (void*) _a7_obj;
    } else if (l0 == INT32_C(54)) {
        vader_struct_vader_front_parser$InfixOpDescr_t* _a8_obj = (vader_struct_vader_front_parser$InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_parser$InfixOpDescr_t));
        vader_obj_header_init(_a8_obj, 1200u);
        _a8_obj->f_has = true;
        _a8_obj->f_left_bp = INT32_C(20);
        _a8_obj->f_right_bp = INT32_C(20);
        _a8_obj->f_op = (uint8_t) 16;
        _a8_obj->f_non_assoc = true;
        l1 = (void*) _a8_obj;
    } else if (l0 == INT32_C(55)) {
        vader_struct_vader_front_parser$InfixOpDescr_t* _a9_obj = (vader_struct_vader_front_parser$InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_parser$InfixOpDescr_t));
        vader_obj_header_init(_a9_obj, 1200u);
        _a9_obj->f_has = true;
        _a9_obj->f_left_bp = INT32_C(20);
        _a9_obj->f_right_bp = INT32_C(20);
        _a9_obj->f_op = (uint8_t) 17;
        _a9_obj->f_non_assoc = true;
        l1 = (void*) _a9_obj;
    } else if (l0 == INT32_C(19)) {
        vader_struct_vader_front_parser$InfixOpDescr_t* _a10_obj = (vader_struct_vader_front_parser$InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_parser$InfixOpDescr_t));
        vader_obj_header_init(_a10_obj, 1200u);
        _a10_obj->f_has = true;
        _a10_obj->f_left_bp = INT32_C(20);
        _a10_obj->f_right_bp = INT32_C(20);
        _a10_obj->f_op = (uint8_t) 18;
        _a10_obj->f_non_assoc = true;
        l1 = (void*) _a10_obj;
    } else if (l0 == INT32_C(21)) {
        vader_struct_vader_front_parser$InfixOpDescr_t* _a11_obj = (vader_struct_vader_front_parser$InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_parser$InfixOpDescr_t));
        vader_obj_header_init(_a11_obj, 1200u);
        _a11_obj->f_has = true;
        _a11_obj->f_left_bp = INT32_C(20);
        _a11_obj->f_right_bp = INT32_C(20);
        _a11_obj->f_op = (uint8_t) 19;
        _a11_obj->f_non_assoc = true;
        l1 = (void*) _a11_obj;
    } else if (l0 == INT32_C(73)) {
        vader_struct_vader_front_parser$InfixOpDescr_t* _a12_obj = (vader_struct_vader_front_parser$InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_parser$InfixOpDescr_t));
        vader_obj_header_init(_a12_obj, 1200u);
        _a12_obj->f_has = true;
        _a12_obj->f_left_bp = INT32_C(30);
        _a12_obj->f_right_bp = INT32_C(30);
        _a12_obj->f_op = (uint8_t) 14;
        _a12_obj->f_non_assoc = true;
        l1 = (void*) _a12_obj;
    } else if (l0 == INT32_C(74)) {
        vader_struct_vader_front_parser$InfixOpDescr_t* _a13_obj = (vader_struct_vader_front_parser$InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_parser$InfixOpDescr_t));
        vader_obj_header_init(_a13_obj, 1200u);
        _a13_obj->f_has = true;
        _a13_obj->f_left_bp = INT32_C(30);
        _a13_obj->f_right_bp = INT32_C(30);
        _a13_obj->f_op = (uint8_t) 15;
        _a13_obj->f_non_assoc = true;
        l1 = (void*) _a13_obj;
    } else if (l0 == INT32_C(75)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(45)) {
        vader_struct_vader_front_parser$InfixOpDescr_t* _a14_obj = (vader_struct_vader_front_parser$InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_parser$InfixOpDescr_t));
        vader_obj_header_init(_a14_obj, 1200u);
        _a14_obj->f_has = true;
        _a14_obj->f_left_bp = INT32_C(40);
        _a14_obj->f_right_bp = INT32_C(41);
        _a14_obj->f_op = (uint8_t) 8;
        _a14_obj->f_non_assoc = false;
        l1 = (void*) _a14_obj;
    } else if (l0 == INT32_C(46)) {
        vader_struct_vader_front_parser$InfixOpDescr_t* _a15_obj = (vader_struct_vader_front_parser$InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_parser$InfixOpDescr_t));
        vader_obj_header_init(_a15_obj, 1200u);
        _a15_obj->f_has = true;
        _a15_obj->f_left_bp = INT32_C(50);
        _a15_obj->f_right_bp = INT32_C(51);
        _a15_obj->f_op = (uint8_t) 9;
        _a15_obj->f_non_assoc = false;
        l1 = (void*) _a15_obj;
    } else if (l0 == INT32_C(44)) {
        vader_struct_vader_front_parser$InfixOpDescr_t* _a16_obj = (vader_struct_vader_front_parser$InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_parser$InfixOpDescr_t));
        vader_obj_header_init(_a16_obj, 1200u);
        _a16_obj->f_has = true;
        _a16_obj->f_left_bp = INT32_C(60);
        _a16_obj->f_right_bp = INT32_C(61);
        _a16_obj->f_op = (uint8_t) 7;
        _a16_obj->f_non_assoc = false;
        l1 = (void*) _a16_obj;
    } else if (l0 == INT32_C(48)) {
        vader_struct_vader_front_parser$InfixOpDescr_t* _a17_obj = (vader_struct_vader_front_parser$InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_parser$InfixOpDescr_t));
        vader_obj_header_init(_a17_obj, 1200u);
        _a17_obj->f_has = true;
        _a17_obj->f_left_bp = INT32_C(70);
        _a17_obj->f_right_bp = INT32_C(71);
        _a17_obj->f_op = (uint8_t) 5;
        _a17_obj->f_non_assoc = false;
        l1 = (void*) _a17_obj;
    } else if (l0 == INT32_C(49)) {
        vader_struct_vader_front_parser$InfixOpDescr_t* _a18_obj = (vader_struct_vader_front_parser$InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_parser$InfixOpDescr_t));
        vader_obj_header_init(_a18_obj, 1200u);
        _a18_obj->f_has = true;
        _a18_obj->f_left_bp = INT32_C(70);
        _a18_obj->f_right_bp = INT32_C(71);
        _a18_obj->f_op = (uint8_t) 6;
        _a18_obj->f_non_assoc = false;
        l1 = (void*) _a18_obj;
    } else if (l0 == INT32_C(36)) {
        vader_struct_vader_front_parser$InfixOpDescr_t* _a19_obj = (vader_struct_vader_front_parser$InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_parser$InfixOpDescr_t));
        vader_obj_header_init(_a19_obj, 1200u);
        _a19_obj->f_has = true;
        _a19_obj->f_left_bp = INT32_C(80);
        _a19_obj->f_right_bp = INT32_C(81);
        _a19_obj->f_op = (uint8_t) 0;
        _a19_obj->f_non_assoc = false;
        l1 = (void*) _a19_obj;
    } else if (l0 == INT32_C(37)) {
        vader_struct_vader_front_parser$InfixOpDescr_t* _a20_obj = (vader_struct_vader_front_parser$InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_parser$InfixOpDescr_t));
        vader_obj_header_init(_a20_obj, 1200u);
        _a20_obj->f_has = true;
        _a20_obj->f_left_bp = INT32_C(80);
        _a20_obj->f_right_bp = INT32_C(81);
        _a20_obj->f_op = (uint8_t) 1;
        _a20_obj->f_non_assoc = false;
        l1 = (void*) _a20_obj;
    } else if (l0 == INT32_C(38)) {
        vader_struct_vader_front_parser$InfixOpDescr_t* _a21_obj = (vader_struct_vader_front_parser$InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_parser$InfixOpDescr_t));
        vader_obj_header_init(_a21_obj, 1200u);
        _a21_obj->f_has = true;
        _a21_obj->f_left_bp = INT32_C(90);
        _a21_obj->f_right_bp = INT32_C(91);
        _a21_obj->f_op = (uint8_t) 2;
        _a21_obj->f_non_assoc = false;
        l1 = (void*) _a21_obj;
    } else if (l0 == INT32_C(39)) {
        vader_struct_vader_front_parser$InfixOpDescr_t* _a22_obj = (vader_struct_vader_front_parser$InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_parser$InfixOpDescr_t));
        vader_obj_header_init(_a22_obj, 1200u);
        _a22_obj->f_has = true;
        _a22_obj->f_left_bp = INT32_C(90);
        _a22_obj->f_right_bp = INT32_C(91);
        _a22_obj->f_op = (uint8_t) 3;
        _a22_obj->f_non_assoc = false;
        l1 = (void*) _a22_obj;
    } else if (l0 == INT32_C(40)) {
        vader_struct_vader_front_parser$InfixOpDescr_t* _a23_obj = (vader_struct_vader_front_parser$InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_parser$InfixOpDescr_t));
        vader_obj_header_init(_a23_obj, 1200u);
        _a23_obj->f_has = true;
        _a23_obj->f_left_bp = INT32_C(90);
        _a23_obj->f_right_bp = INT32_C(91);
        _a23_obj->f_op = (uint8_t) 4;
        _a23_obj->f_non_assoc = false;
        l1 = (void*) _a23_obj;
    } else if (l0 == INT32_C(41)) {
        vader_struct_vader_front_parser$InfixOpDescr_t* _a24_obj = (vader_struct_vader_front_parser$InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_parser$InfixOpDescr_t));
        vader_obj_header_init(_a24_obj, 1200u);
        _a24_obj->f_has = true;
        _a24_obj->f_left_bp = INT32_C(80);
        _a24_obj->f_right_bp = INT32_C(81);
        _a24_obj->f_op = (uint8_t) 23;
        _a24_obj->f_non_assoc = false;
        l1 = (void*) _a24_obj;
    } else if (l0 == INT32_C(42)) {
        vader_struct_vader_front_parser$InfixOpDescr_t* _a25_obj = (vader_struct_vader_front_parser$InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_parser$InfixOpDescr_t));
        vader_obj_header_init(_a25_obj, 1200u);
        _a25_obj->f_has = true;
        _a25_obj->f_left_bp = INT32_C(80);
        _a25_obj->f_right_bp = INT32_C(81);
        _a25_obj->f_op = (uint8_t) 24;
        _a25_obj->f_non_assoc = false;
        l1 = (void*) _a25_obj;
    } else if (l0 == INT32_C(43)) {
        vader_struct_vader_front_parser$InfixOpDescr_t* _a26_obj = (vader_struct_vader_front_parser$InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_parser$InfixOpDescr_t));
        vader_obj_header_init(_a26_obj, 1200u);
        _a26_obj->f_has = true;
        _a26_obj->f_left_bp = INT32_C(90);
        _a26_obj->f_right_bp = INT32_C(91);
        _a26_obj->f_op = (uint8_t) 25;
        _a26_obj->f_non_assoc = false;
        l1 = (void*) _a26_obj;
    } else if (l0 == INT32_C(0)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(1)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(2)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(3)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(4)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(5)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(6)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(7)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(8)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(9)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(10)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(47)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(60)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(61)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(62)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(63)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(64)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(65)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(66)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(67)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(68)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(69)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(70)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(71)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(72)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(76)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(77)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(78)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(79)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(80)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(81)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(82)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(83)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(84)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(85)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(86)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(87)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(11)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(12)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(13)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(14)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(15)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(16)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(17)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(18)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(20)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(22)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(23)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(24)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(25)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(26)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(27)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(28)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(29)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(30)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(31)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(32)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(33)) {
        l1 = vader_front_parser$no_infix();
    } else if (l0 == INT32_C(34)) {
        l1 = vader_front_parser$no_infix();
    } else {
        if (!(l0 == INT32_C(35))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = vader_front_parser$no_infix();
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_front_parser$intrinsic_spec(vader_string_t l0) {
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
    l1 = __const_vader_front_parser$INTRINSICS();
    l2 = ((vader_array_t*) l1)->length;
    l3 = INT64_C(0);
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        t0 = ((vader_struct_vader_front_parser$IntrinsicSpec_t*) l4)->f_name;
        if (t0 == l0) {
            { vader_box_t __vret = vader_ref_box(l4); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l3 = (l3 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static bool vader_front_parser$is_angle_scan_bailout(uint8_t l0) {
    if (l0 == INT32_C(83)) {
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

static bool vader_front_parser$is_bare_nullary_call(vader_box_t l0) {
    bool l1;
    void* t0;
    int64_t t1;
    if (l0.tag == 751u) {
        t0 = l0.payload.obj;
        t1 = ((vader_array_t*) ((vader_struct_toolchain_ast$CallExpr_t*) t0)->f_args)->length;
        l1 = t1 == INT64_C(0);
    } else {
        l1 = false;
    }
    if (l1) {
        t0 = l0.payload.obj;
        return ((vader_struct_toolchain_ast$CallExpr_t*) t0)->f_callee.tag == 778u;
    }
    return false;
}

vader_string_t vader_front_parser$is_binding_hint(vader_box_t l0, vader_string_t l1, bool l2) {
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
    l3 = vader_front_parser$place_text(l0);
    if (!(l3.tag == 0u)) {
        l4 = l3.payload.s;
        l5 = l3.payload.s;
        t0 = concat_7(1033u, l4, 1154u, l1, 1057u, l5, 1033u);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l2)) {
        t0 = concat_5(1622u, l1, 70u, l1, 166u);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = concat_5(1622u, l1, 70u, l1, 43u);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool vader_front_parser$is_evaluated(uint8_t l0) {
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

static bool vader_front_parser$is_impl_decl(void* l0) {
    int32_t l1, l2, l3;
    void* l4;
    bool l5, l6, l7, l8;
    int64_t t0;
    l1 = INT32_C(0);
    t0 = ((vader_array_t*) ((vader_struct_vader_front_parser$Parser_t*) l0)->f_tokens)->length;
    l2 = ((int32_t) (int64_t) t0);
    l3 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_pos;
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_front_parser$Parser_t*) l0)->f_tokens);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        if (((vader_struct_vader_front_lexer$Token_t*) l4)->f_kind == INT32_C(0)) {
            return false;
        }
        if (((vader_struct_vader_front_lexer$Token_t*) l4)->f_kind == INT32_C(1)) {
            return false;
        }
        if (((vader_struct_vader_front_lexer$Token_t*) l4)->f_kind == INT32_C(14)) {
            if (l1 == INT32_C(0)) {
                return true;
            }
        }
        if (((vader_struct_vader_front_lexer$Token_t*) l4)->f_kind == INT32_C(79)) {
            l5 = true;
        } else {
            l5 = ((vader_struct_vader_front_lexer$Token_t*) l4)->f_kind == INT32_C(81);
        }
        if (l5) {
            l6 = true;
        } else {
            l6 = ((vader_struct_vader_front_lexer$Token_t*) l4)->f_kind == INT32_C(83);
        }
        if (l6) {
            l1 = vader_chk_add(i32, l1, INT32_C(1));
        }
        if (((vader_struct_vader_front_lexer$Token_t*) l4)->f_kind == INT32_C(80)) {
            l7 = true;
        } else {
            l7 = ((vader_struct_vader_front_lexer$Token_t*) l4)->f_kind == INT32_C(82);
        }
        if (l7) {
            l8 = true;
        } else {
            l8 = ((vader_struct_vader_front_lexer$Token_t*) l4)->f_kind == INT32_C(84);
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

static bool vader_front_parser$is_literal_start(void* l0) {
    bool l1;
    if (((vader_struct_vader_front_lexer$Token_t*) l0)->f_kind == INT32_C(3)) {
        l1 = true;
    } else {
        l1 = ((vader_struct_vader_front_lexer$Token_t*) l0)->f_kind == INT32_C(4);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = ((vader_struct_vader_front_lexer$Token_t*) l0)->f_kind == INT32_C(5);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = ((vader_struct_vader_front_lexer$Token_t*) l0)->f_kind == INT32_C(6);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = ((vader_struct_vader_front_lexer$Token_t*) l0)->f_kind == INT32_C(31);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = ((vader_struct_vader_front_lexer$Token_t*) l0)->f_kind == INT32_C(32);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = ((vader_struct_vader_front_lexer$Token_t*) l0)->f_kind == INT32_C(33);
    }
    if (l1) {
        return true;
    }
    return ((vader_struct_vader_front_lexer$Token_t*) l0)->f_kind == INT32_C(37);
}

static bool vader_front_parser$is_module_segment_continue(uint32_t l0) {
    bool l1;
    if ((97u <= l0)) {
        l1 = (l0 <= 122u);
    } else {
        l1 = false;
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = std_char$is_digit(l0);
    }
    if (l1) {
        return true;
    }
    return l0 == 95u;
}

static bool vader_front_parser$is_module_segment_start(uint32_t l0) {
    if ((97u <= l0)) {
        return (l0 <= 122u);
    }
    return false;
}

static bool vader_front_parser$is_number_token(void* l0) {
    if (((vader_struct_vader_front_lexer$Token_t*) l0)->f_kind == INT32_C(3)) {
        return true;
    }
    return ((vader_struct_vader_front_lexer$Token_t*) l0)->f_kind == INT32_C(4);
}

static bool vader_front_parser$is_tuple_type(void* l0) {
    void* l1;
    int64_t l2, l3;
    int64_t t0;
    vader_box_t t1;
    bool t2;
    t0 = ((vader_array_t*) l0)->length;
    if ((t0 < INT64_C(2))) {
        return false;
    }
    l1 = l0;
    l2 = ((vader_array_t*) l1)->length;
    l3 = INT64_C(0);
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        t2 = vader_front_parser$has_type_shape(t1);
        if (!(t2)) {
            return false;
        }
        l3 = (l3 + INT64_C(1));
    }
    return true;
}

static bool vader_front_parser$is_type_operator(void* l0) {
    bool l1;
    bool t0;
    if (((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_op == INT32_C(19)) {
        t0 = vader_front_parser$has_type_shape(((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_left);
        return t0;
    }
    if (((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_op == INT32_C(8)) {
        l1 = vader_front_parser$is_type_union_operand(((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_left);
    } else {
        l1 = false;
    }
    if (l1) {
        t0 = vader_front_parser$is_type_union_operand(((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_right);
        return t0;
    }
    return false;
}

static bool vader_front_parser$is_type_union_operand(vader_box_t l0) {
    bool t0;
    if (l0.tag == 800u) {
        return true;
    }
    t0 = vader_front_parser$has_type_shape(l0);
    return t0;
}

static bool vader_front_parser$is_valid_module_name(vader_string_t l0) {
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
        l4 = vader_host_std_core$byte_len(l2);
        if ((l3 < l4)) {
            l5 = vader_host_std_core$byte_at(l2, l3);
            if ((l5 < INT32_C(128))) {
                l3 = vader_chk_add(i64, l3, INT64_C(1));
                l6 = ((uint32_t) (uint8_t) l5);
                if (l1) {
                    t0 = vader_front_parser$is_module_segment_start(l6);
                    if (!(t0)) {
                        return false;
                    }
                    l1 = false;
                } else if (l6 == 47u) {
                    l1 = true;
                } else {
                    t0 = vader_front_parser$is_module_segment_continue(l6);
                    if (!(t0)) {
                        return false;
                    }
                }
                continue;
            }
            std_core$decode_tail(l2, l5, l3, &t1, &t2);
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
                t0 = vader_front_parser$is_module_segment_start(l9);
                if (!(t0)) {
                    return false;
                }
                l1 = false;
            } else if (l9 == 47u) {
                l1 = true;
            } else {
                t0 = vader_front_parser$is_module_segment_continue(l9);
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

static uint8_t vader_front_parser$kind_after_bracket_group(void* l0) {
    int32_t l1, l2, l3;
    uint8_t l4;
    int32_t t0;
    int64_t t1;
    void* t2;
    l1 = INT32_C(1);
    t0 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_pos;
    l2 = vader_chk_add(i32, t0, INT32_C(1));
    t1 = ((vader_array_t*) ((vader_struct_vader_front_parser$Parser_t*) l0)->f_tokens)->length;
    l3 = ((int32_t) (int64_t) t1);
    while ((l2 < l3)) {
        if (!((l1 > INT32_C(0)))) {
            break;
        }
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_front_parser$Parser_t*) l0)->f_tokens);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        t2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        l4 = ((vader_struct_vader_front_lexer$Token_t*) t2)->f_kind;
        if (l4 == INT32_C(0)) {
            return (uint8_t) 0;
        }
        if (l4 == INT32_C(81)) {
            l1 = vader_chk_add(i32, l1, INT32_C(1));
        } else if (l4 == INT32_C(82)) {
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
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_front_parser$Parser_t*) l0)->f_tokens);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
        t2 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l1);
        if (!(((vader_struct_vader_front_lexer$Token_t*) t2)->f_kind == INT32_C(1))) {
            break;
        }
        l1 = vader_chk_add(i32, l1, INT32_C(1));
    }
    if (!((l1 >= l3))) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_front_parser$Parser_t*) l0)->f_tokens);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l1)
        t2 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l1);
        return ((vader_struct_vader_front_lexer$Token_t*) t2)->f_kind;
    }
    return (uint8_t) 0;
}

static void* vader_front_parser$lift_trailing_return(void* l0) {
    int64_t l1, l3;
    void* l2 = NULL;
    void* l6 = NULL;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l4, &l5 };
    void** gc_raw_roots[4] = { &l0, &l2, &l6, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(((vader_struct_toolchain_ast$BlockExpr_t*) l0)->f_trailing.tag == 0u)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = ((vader_array_t*) ((vader_struct_toolchain_ast$BlockExpr_t*) l0)->f_stmts)->length;
    if (l1 == INT64_C(0)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_toolchain_ast$BlockExpr_t*) l0)->f_stmts;
    l3 = vader_chk_sub(i64, l1, INT64_C(1));
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    if (l4.tag == 810u) {
        t0 = l4.payload.obj;
        if (((vader_struct_toolchain_ast$ReturnStmt_t*) t0)->f_value.tag == 0u) {
            { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_array_t* _a1_arr = vader_array_new(351u, 0u, 13u, 1753u);
        l2 = (void*) _a1_arr;
        l3 = INT64_C(0);
        l1 = vader_chk_sub(i64, l1, INT64_C(1));
        while ((l3 < l1)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$BlockExpr_t*) l0)->f_stmts);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
            l5 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l3);
            vader_array_push_ref((vader_array_t*) l2, l5.payload.obj);
            l3 = (l3 + INT64_C(1));
        }
        l6 = ((vader_struct_toolchain_ast$BlockExpr_t*) l0)->f_span;
        t0 = l4.payload.obj;
        l4 = ((vader_struct_toolchain_ast$ReturnStmt_t*) t0)->f_value;
        vader_struct_toolchain_ast$BlockExpr_t* _a3_obj = (vader_struct_toolchain_ast$BlockExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$BlockExpr_t));
        vader_obj_header_init(_a3_obj, 747u);
        _a3_obj->f_span = l6;
        _a3_obj->f_id = INT64_C(0);
        _a3_obj->f_stmts = l2;
        _a3_obj->f_trailing = l4;
        t0 = (void*) _a3_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_front_parser$looks_like_for_destructure(void* l0) {
    int32_t l1, l2, l4;
    void* l3;
    bool t0;
    t0 = vader_front_parser$check(l0, (uint8_t) 81);
    if (!(t0)) {
        return false;
    }
    l1 = INT32_C(0);
    l2 = INT32_C(0);
    while (!((l2 > INT32_C(256)))) {
        l3 = vader_front_parser$peek_at(l0, l2);
        if (((vader_struct_vader_front_lexer$Token_t*) l3)->f_kind == INT32_C(0)) {
            return false;
        }
        if (((vader_struct_vader_front_lexer$Token_t*) l3)->f_kind == INT32_C(81)) {
            l1 = vader_chk_add(i32, l1, INT32_C(1));
        } else if (((vader_struct_vader_front_lexer$Token_t*) l3)->f_kind == INT32_C(82)) {
            l1 = vader_chk_sub(i32, l1, INT32_C(1));
            if (l1 == INT32_C(0)) {
                l4 = vader_chk_add(i32, l2, INT32_C(1));
                t0 = vader_front_parser$check_at(l0, (uint8_t) 21, l4);
                return t0;
            }
        }
        l2 = vader_chk_add(i32, l2, INT32_C(1));
    }
    return false;
}

static bool vader_front_parser$looks_like_struct_lit_body(void* l0, int32_t l1) {
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
            if (((vader_struct_vader_front_lexer$Token_t*) l4)->f_kind == INT32_C(1)) {
                l3 = vader_chk_add(i32, l3, INT32_C(1));
                continue;
            }
            if (((vader_struct_vader_front_lexer$Token_t*) l4)->f_kind == INT32_C(86)) {
                l5 = true;
            } else {
                l5 = ((vader_struct_vader_front_lexer$Token_t*) l4)->f_kind == INT32_C(75);
            }
            if (l5) {
                return true;
            }
            return ((vader_struct_vader_front_lexer$Token_t*) l4)->f_kind == INT32_C(84);
        }
        break;
    }
    return false;
}

static vader_box_t vader_front_parser$match_kind(void* l0, uint8_t l1) {
    bool t0;
    void* t1;
    t0 = vader_front_parser$check(l0, l1);
    if (!(t0)) {
        return vader_box_obj(0u, NULL);
    }
    t1 = vader_front_parser$advance(l0);
    return vader_ref_box(t1);
}

static void* vader_front_parser$match_or_peek(void* l0, uint8_t l1) {
    vader_box_t l2;
    void* t0;
    l2 = vader_front_parser$match_kind(l0, l1);
    if (!(l2.tag == 0u)) {
        t0 = l2.payload.obj;
        return t0;
    }
    t0 = vader_front_parser$peek(l0);
    return t0;
}

static vader_box_t vader_front_parser$match_scrutinee(void* l0, vader_box_t l1) {
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t1 };
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(l1.tag == 0u)) {
        t0 = l1.payload.obj;
        { vader_box_t __vret = ((vader_struct_toolchain_ast$LetStmt_t*) t0)->f_value; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_front_parser$parse_expr(l0, INT32_C(0));
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

int64_t vader_front_parser$mint(void* l0) {
    int64_t l1, l2;
    l1 = ((vader_struct_vader_front_parser$NodeIdFactory_t*) l0)->f_next;
    l2 = vader_chk_add(i64, l1, INT64_C(1));
    ((vader_struct_vader_front_parser$NodeIdFactory_t*) l0)->f_next = l2;
    return l1;
}

void* vader_front_parser$new_node_id_factory(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_front_parser$NodeIdFactory_t* _a0_obj = (vader_struct_vader_front_parser$NodeIdFactory_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_parser$NodeIdFactory_t));
    vader_obj_header_init(_a0_obj, 1203u);
    _a0_obj->f_next = INT64_C(1);
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_parser$no_infix(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_front_parser$InfixOpDescr_t* _a0_obj = (vader_struct_vader_front_parser$InfixOpDescr_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_parser$InfixOpDescr_t));
    vader_obj_header_init(_a0_obj, 1200u);
    _a0_obj->f_has = false;
    _a0_obj->f_left_bp = INT32_C(0);
    _a0_obj->f_right_bp = INT32_C(0);
    _a0_obj->f_op = (uint8_t) 0;
    _a0_obj->f_non_assoc = false;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_parser$number_literal(void* l0, void* l1, bool l2) {
    vader_box_t l3 = vader_box_null();
    double l4;
    uint64_t l5;
    int64_t l6;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_front_lexer$Token_t*) l0)->f_value;
    if (((vader_struct_vader_front_lexer$Token_t*) l0)->f_kind == INT32_C(4)) {
        l4 = 0.0;
        if ((l3.tag == 456u || l3.tag == 457u)) {
            l4 = ((double) l3.payload.f);
        }
        if (!(l2)) {
            vader_struct_toolchain_ast$FloatLitExpr_t* _a0_obj = (vader_struct_toolchain_ast$FloatLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$FloatLitExpr_t));
            vader_obj_header_init(_a0_obj, 772u);
            _a0_obj->f_span = l1;
            _a0_obj->f_id = INT64_C(0);
            _a0_obj->f_value = l4;
            t0 = (void*) _a0_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l4 = -(l4);
        vader_struct_toolchain_ast$FloatLitExpr_t* _a1_obj = (vader_struct_toolchain_ast$FloatLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$FloatLitExpr_t));
        vader_obj_header_init(_a1_obj, 772u);
        _a1_obj->f_span = l1;
        _a1_obj->f_id = INT64_C(0);
        _a1_obj->f_value = l4;
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = (uint64_t) 0;
    if (l3.tag == 455u) {
        l5 = ((uint64_t) l3.payload.i);
        l6 = INT64_C(0);
        vader_struct_toolchain_ast$IntLitExpr_t* _a2_obj = (vader_struct_toolchain_ast$IntLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$IntLitExpr_t));
        vader_obj_header_init(_a2_obj, 788u);
        _a2_obj->f_span = l1;
        _a2_obj->f_id = l6;
        _a2_obj->f_value = l5;
        _a2_obj->f_negative = l2;
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = INT64_C(0);
    vader_struct_toolchain_ast$IntLitExpr_t* _a3_obj = (vader_struct_toolchain_ast$IntLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$IntLitExpr_t));
    vader_obj_header_init(_a3_obj, 788u);
    _a3_obj->f_span = l1;
    _a3_obj->f_id = l6;
    _a3_obj->f_value = l5;
    _a3_obj->f_negative = l2;
    t0 = (void*) _a3_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_parser$parse_angle_type_params(void* l0) {
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
    t0 = vader_front_parser$check(l0, (uint8_t) 52);
    if (!(t0)) {
        vader_array_t* _a0_arr = vader_array_new(59u, 0u, 13u, 826u);
        t1 = (void*) _a0_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_front_parser$advance(l0);
    vader_array_t* _a1_arr = vader_array_new(59u, 0u, 13u, 826u);
    l1 = (void*) _a1_arr;
    vader_front_parser$skip_newlines(l0);
    for (;;) {
        t0 = vader_front_parser$check(l0, (uint8_t) 0);
        if (!(t0)) {
            t0 = vader_front_parser$check_closing_angle(l0);
            if (t0) break;
            t2 = ((vader_array_t*) l1)->length;
            if ((t2 > INT64_C(0))) {
                t3 = vader_front_parser$match_kind(l0, (uint8_t) 85);
                if (t3.tag == 0u) break;
                vader_front_parser$skip_newlines(l0);
                t0 = vader_front_parser$check_closing_angle(l0);
                if (t0) break;
            }
            l2 = vader_front_parser$peek(l0);
            l3 = vader_front_parser$expect(l0, (uint8_t) 2, 2755u);
            l4 = vader_box_obj(0u, NULL);
            t3 = vader_front_parser$match_kind(l0, (uint8_t) 87);
            if (!(t3.tag == 0u)) {
                vader_front_parser$skip_newlines(l0);
                l4 = vader_front_parser$parse_type(l0);
            }
            l5 = vader_box_obj(0u, NULL);
            t3 = vader_front_parser$match_kind(l0, (uint8_t) 62);
            if (!(t3.tag == 0u)) {
                vader_front_parser$skip_newlines(l0);
                l5 = vader_front_parser$parse_type(l0);
            }
            l6 = vader_front_parser$peek_at(l0, INT32_C(-1));
            l7 = vader_front_parser$span_of(l0, l2, l6);
            l8 = ((vader_struct_vader_front_lexer$Token_t*) l3)->f_text;
            vader_struct_toolchain_ast$TypeParam_t* _a2_obj = (vader_struct_toolchain_ast$TypeParam_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$TypeParam_t));
            vader_obj_header_init(_a2_obj, 826u);
            _a2_obj->f_span = l7;
            _a2_obj->f_id = INT64_C(0);
            _a2_obj->f_name = l8;
            _a2_obj->f_bound = l4;
            _a2_obj->f_default = l5;
            l9 = (void*) _a2_obj;
            vader_array_push_ref((vader_array_t*) l1, l9);
            continue;
        }
        break;
    }
    t0 = vader_front_parser$check_closing_angle(l0);
    if (t0) {
        vader_front_parser$consume_closing_angle(l0);
        { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_front_parser$expect(l0, (uint8_t) 54, 1323u);
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_parser$parse_any_let(void* l0) {
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[2] = { &l0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_front_parser$check(l0, (uint8_t) 81);
    if (t0) {
        t1 = vader_front_parser$parse_tuple_let(l0);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_front_parser$check_at(l0, (uint8_t) 87, INT32_C(1));
    if (!(t0)) {
        t1 = vader_front_parser$parse_let(l0);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_front_parser$parse_typed_let(l0);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_parser$parse_assert_decl(void* l0) {
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
    l1 = vader_front_parser$parse_decorator(l0);
    vader_front_parser$skip_newlines(l0);
    t0 = ((vader_array_t*) ((vader_struct_toolchain_ast$Decorator_t*) l1)->f_args)->length;
    if ((t0 < INT64_C(1))) {
        l2 = true;
    } else {
        t0 = ((vader_array_t*) ((vader_struct_toolchain_ast$Decorator_t*) l1)->f_args)->length;
        l2 = (t0 > INT64_C(2));
    }
    if (l2) {
        l3 = ((vader_struct_toolchain_ast$Decorator_t*) l1)->f_span;
        vader_front_parser$error(l0, (uint8_t) 16, l3, 1328u);
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l4 = vader_box_obj(0u, NULL);
    l5 = vader_box_obj(0u, NULL);
    t0 = ((vader_array_t*) ((vader_struct_toolchain_ast$Decorator_t*) l1)->f_args)->length;
    if (t0 == INT64_C(2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$Decorator_t*) l1)->f_args);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(1))
        l6 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(1));
        l6 = vader_front_parser$static_assert_message(l0, l6);
        if (l6.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
        }
        t1 = l6.payload.s;
        l4 = vader_box_string(447u, t1);
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$Decorator_t*) l1)->f_args);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(1))
        t2 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT32_C(1));
        t3 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, t2.payload.obj);
        l5 = vader_ref_box(t3);
    }
    l3 = ((vader_struct_toolchain_ast$Decorator_t*) l1)->f_span;
    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$Decorator_t*) l1)->f_args);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(0))
    l6 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT32_C(0));
    vader_array_t* _a3_arr = vader_array_new(43u, 0u, 13u, 756u);
    l1 = (void*) _a3_arr;
    vader_struct_toolchain_ast$AssertDecl_t* _a4_obj = (vader_struct_toolchain_ast$AssertDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$AssertDecl_t));
    vader_obj_header_init(_a4_obj, 743u);
    _a4_obj->f_span = l3;
    _a4_obj->f_id = INT64_C(0);
    _a4_obj->f_condition = l6;
    _a4_obj->f_message = l4;
    _a4_obj->f_message_span = l5;
    _a4_obj->f_decorators = l1;
    t3 = (void*) _a4_obj;
    { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_parser$parse_assign_target(void* l0) {
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
    l1 = vader_front_parser$peek(l0);
    t0 = vader_front_parser$match_kind(l0, (uint8_t) 75);
    if (!(t0.tag == 0u)) {
        l2 = vader_front_parser$parse_expr(l0, INT32_C(0));
        l3 = vader_front_parser$peek_at(l0, INT32_C(-1));
        t1 = vader_front_parser$span_of(l0, l1, l3);
        vader_struct_toolchain_ast$RestTarget_t* _a0_obj = (vader_struct_toolchain_ast$RestTarget_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$RestTarget_t));
        vader_obj_header_init(_a0_obj, 809u);
        _a0_obj->f_span = t1;
        _a0_obj->f_id = INT64_C(0);
        _a0_obj->f_place = l2;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_front_parser$check(l0, (uint8_t) 2);
    if (t2) {
        t1 = vader_front_parser$peek(l0);
        t3 = ((vader_struct_vader_front_lexer$Token_t*) t1)->f_text;
        if (t3 == 976u) {
            t1 = vader_front_parser$advance(l0);
            vader_struct_toolchain_ast$WildcardTarget_t* _a1_obj = (vader_struct_toolchain_ast$WildcardTarget_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$WildcardTarget_t));
            vader_obj_header_init(_a1_obj, 832u);
            _a1_obj->f_span = ((vader_struct_vader_front_lexer$Token_t*) t1)->f_span;
            _a1_obj->f_id = INT64_C(0);
            t1 = (void*) _a1_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l2 = vader_front_parser$parse_expr(l0, INT32_C(0));
    vader_struct_toolchain_ast$PlaceTarget_t* _a2_obj = (vader_struct_toolchain_ast$PlaceTarget_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$PlaceTarget_t));
    vader_obj_header_init(_a2_obj, 804u);
    _a2_obj->f_span = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l2.payload.obj);
    _a2_obj->f_id = INT64_C(0);
    _a2_obj->f_place = l2;
    t1 = (void*) _a2_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_parser$parse_block(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    int32_t l2;
    vader_box_t l5 = vader_box_null(), l16 = vader_box_null();
    int64_t l15;
    int32_t t0;
    bool t1;
    void* t2 = NULL;
    int64_t t3;
    vader_box_t t4 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l5, &l16, &t4 };
    void** gc_raw_roots[14] = {
        &l0, &l1, &l3, &l4, &l6, &l7, &l8, &l9, &l10, &l11, &l12, &l13, &l14, &t2,
    };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 14u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_front_parser$expect(l0, (uint8_t) 83, 1398u);
    t0 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_expr_depth;
    l2 = vader_chk_add(i32, t0, INT32_C(1));
    ((vader_struct_vader_front_parser$Parser_t*) l0)->f_expr_depth = l2;
    t0 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_expr_depth;
    if ((t0 > INT32_C(256))) {
        t0 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_expr_depth;
        l2 = vader_chk_sub(i32, t0, INT32_C(1));
        ((vader_struct_vader_front_parser$Parser_t*) l0)->f_expr_depth = l2;
        vader_front_parser$report_nesting_too_deep(l0, 1631u);
        l2 = INT32_C(1);
        while ((l2 > INT32_C(0))) {
            t1 = vader_front_parser$check(l0, (uint8_t) 0);
            if (t1) break;
            l3 = vader_front_parser$advance(l0);
            if (((vader_struct_vader_front_lexer$Token_t*) l3)->f_kind == INT32_C(83)) {
                l2 = vader_chk_add(i32, l2, INT32_C(1));
            }
            if (!(((vader_struct_vader_front_lexer$Token_t*) l3)->f_kind == INT32_C(84))) {
                continue;
            }
            l2 = vader_chk_sub(i32, l2, INT32_C(1));
        }
        l3 = vader_front_parser$peek_at(l0, INT32_C(-1));
        l3 = vader_front_parser$span_of(l0, l1, l3);
        vader_array_t* _a0_arr = vader_array_new(351u, 0u, 13u, 1753u);
        l4 = (void*) _a0_arr;
        vader_struct_toolchain_ast$BlockExpr_t* _a1_obj = (vader_struct_toolchain_ast$BlockExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$BlockExpr_t));
        vader_obj_header_init(_a1_obj, 747u);
        _a1_obj->f_span = l3;
        _a1_obj->f_id = INT64_C(0);
        _a1_obj->f_stmts = l4;
        _a1_obj->f_trailing = vader_box_obj(0u, NULL);
        t2 = (void*) _a1_obj;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_front_parser$skip_newlines(l0);
    vader_array_t* _a2_arr = vader_array_new(351u, 0u, 13u, 1753u);
    l3 = (void*) _a2_arr;
    for (;;) {
        t1 = vader_front_parser$check(l0, (uint8_t) 84);
        if (!(t1)) {
            t1 = vader_front_parser$check(l0, (uint8_t) 0);
            if (t1) break;
            l5 = vader_front_parser$parse_stmt(l0);
            if (!(l5.tag == 0u)) {
                if (l5.tag == 792u) {
                    l4 = l5.payload.obj;
                    vader_array_push_ref((vader_array_t*) l3, l4);
                } else if (l5.tag == 744u) {
                    l6 = l5.payload.obj;
                    vader_array_push_ref((vader_array_t*) l3, l6);
                } else if (l5.tag == 760u) {
                    l7 = l5.payload.obj;
                    vader_array_push_ref((vader_array_t*) l3, l7);
                } else if (l5.tag == 770u) {
                    l8 = l5.payload.obj;
                    vader_array_push_ref((vader_array_t*) l3, l8);
                } else if (l5.tag == 810u) {
                    l9 = l5.payload.obj;
                    vader_array_push_ref((vader_array_t*) l3, l9);
                } else if (l5.tag == 833u) {
                    l10 = l5.payload.obj;
                    vader_array_push_ref((vader_array_t*) l3, l10);
                } else if (l5.tag == 776u) {
                    l11 = l5.payload.obj;
                    vader_array_push_ref((vader_array_t*) l3, l11);
                } else if (l5.tag == 749u) {
                    l12 = l5.payload.obj;
                    vader_array_push_ref((vader_array_t*) l3, l12);
                } else if (l5.tag == 755u) {
                    l13 = l5.payload.obj;
                    vader_array_push_ref((vader_array_t*) l3, l13);
                } else {
                    if (!(l5.tag == 758u)) {
                        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                    }
                    l14 = l5.payload.obj;
                    vader_array_push_ref((vader_array_t*) l3, l14);
                }
            }
            vader_front_parser$skip_newlines(l0);
            continue;
        }
        break;
    }
    l5 = vader_box_obj(0u, NULL);
    t3 = ((vader_array_t*) l3)->length;
    if ((t3 > INT64_C(0))) {
        t3 = ((vader_array_t*) l3)->length;
        l15 = vader_chk_sub(i64, t3, INT64_C(1));
        vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        l16 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l15);
        if (l16.tag == 770u) {
            t4 = vader_array_remove_last((vader_array_t*) l3);
            t2 = l16.payload.obj;
            l5 = ((vader_struct_toolchain_ast$ExprStmt_t*) t2)->f_expr;
        }
    }
    l4 = vader_front_parser$expect(l0, (uint8_t) 84, 1404u);
    t0 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_expr_depth;
    l2 = vader_chk_sub(i32, t0, INT32_C(1));
    ((vader_struct_vader_front_parser$Parser_t*) l0)->f_expr_depth = l2;
    t2 = vader_front_parser$span_of(l0, l1, l4);
    vader_struct_toolchain_ast$BlockExpr_t* _a4_obj = (vader_struct_toolchain_ast$BlockExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$BlockExpr_t));
    vader_obj_header_init(_a4_obj, 747u);
    _a4_obj->f_span = t2;
    _a4_obj->f_id = INT64_C(0);
    _a4_obj->f_stmts = l3;
    _a4_obj->f_trailing = l5;
    t2 = (void*) _a4_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_parser$parse_break(void* l0) {
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
    l1 = vader_front_parser$advance(l0);
    l2 = vader_box_obj(0u, NULL);
    t0 = vader_front_parser$check(l0, (uint8_t) 2);
    if (t0) {
        t1 = vader_front_parser$advance(l0);
        t2 = ((vader_struct_vader_front_lexer$Token_t*) t1)->f_text;
        l2 = vader_box_string(447u, t2);
    }
    l3 = vader_front_parser$peek_at(l0, INT32_C(-1));
    t1 = vader_front_parser$span_of(l0, l1, l3);
    vader_struct_toolchain_ast$BreakStmt_t* _a0_obj = (vader_struct_toolchain_ast$BreakStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$BreakStmt_t));
    vader_obj_header_init(_a0_obj, 749u);
    _a0_obj->f_span = t1;
    _a0_obj->f_id = INT64_C(0);
    _a0_obj->f_label = l2;
    t1 = (void*) _a0_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_parser$parse_call_args(void* l0) {
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
    vader_array_t* _a0_arr = vader_array_new(41u, 0u, 13u, 750u);
    l1 = (void*) _a0_arr;
    l2 = false;
    vader_front_parser$skip_newlines(l0);
    t0 = vader_front_parser$check(l0, (uint8_t) 80);
    if (t0) {
        vader_struct_vader_front_parser$CommaList__Any_t* _a1_obj = (vader_struct_vader_front_parser$CommaList__Any_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_parser$CommaList__Any_t));
        vader_obj_header_init(_a1_obj, 1192u);
        _a1_obj->f_items = l1;
        _a1_obj->f_trailing_comma = false;
        t1 = (void*) _a1_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    for (;;) {
        vader_front_parser$skip_newlines(l0);
        t0 = vader_front_parser$check(l0, (uint8_t) 80);
        if (!(t0)) {
            l3 = vader_front_parser$peek(l0);
            t0 = vader_front_parser$check(l0, (uint8_t) 2);
            if (t0) {
                l4 = vader_front_parser$check_at(l0, (uint8_t) 62, INT32_C(1));
            } else {
                l4 = false;
            }
            if (l4) {
                l5 = vader_front_parser$advance(l0);
                vader_front_parser$advance(l0);
                l6 = vader_front_parser$parse_expr(l0, INT32_C(0));
                l7 = vader_front_parser$peek_at(l0, INT32_C(-1));
                l8 = vader_front_parser$span_of(l0, l3, l7);
                l9 = ((vader_struct_vader_front_lexer$Token_t*) l5)->f_text;
                vader_struct_toolchain_ast$CallArg_t* _a2_obj = (vader_struct_toolchain_ast$CallArg_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$CallArg_t));
                vader_obj_header_init(_a2_obj, 750u);
                _a2_obj->f_span = l8;
                _a2_obj->f_id = INT64_C(0);
                _a2_obj->f_name = vader_box_string(447u, l9);
                _a2_obj->f_value = l6;
                _a2_obj->f_spread = false;
                l10 = (void*) _a2_obj;
                vader_array_push_ref((vader_array_t*) l1, l10);
            } else {
                l11 = vader_front_parser$parse_expr(l0, INT32_C(0));
                vader_struct_toolchain_ast$CallArg_t* _a3_obj = (vader_struct_toolchain_ast$CallArg_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$CallArg_t));
                vader_obj_header_init(_a3_obj, 750u);
                _a3_obj->f_span = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l11.payload.obj);
                _a3_obj->f_id = INT64_C(0);
                _a3_obj->f_name = vader_box_obj(0u, NULL);
                _a3_obj->f_value = l11;
                _a3_obj->f_spread = false;
                l12 = (void*) _a3_obj;
                vader_array_push_ref((vader_array_t*) l1, l12);
            }
            vader_front_parser$skip_newlines(l0);
            t2 = vader_front_parser$match_kind(l0, (uint8_t) 85);
            if (t2.tag == 0u) break;
            vader_front_parser$skip_newlines(l0);
            l2 = vader_front_parser$check(l0, (uint8_t) 80);
            continue;
        }
        break;
    }
    vader_struct_vader_front_parser$CommaList__Any_t* _a4_obj = (vader_struct_vader_front_parser$CommaList__Any_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_parser$CommaList__Any_t));
    vader_obj_header_init(_a4_obj, 1192u);
    _a4_obj->f_items = l1;
    _a4_obj->f_trailing_comma = l2;
    t1 = (void*) _a4_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_parser$parse_coalesce_fallback(void* l0) {
    uint8_t l1;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_front_parser$peek(l0);
    l1 = ((vader_struct_vader_front_lexer$Token_t*) t0)->f_kind;
    if (l1 == INT32_C(22)) {
        t0 = vader_front_parser$parse_return(l0);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(26)) {
        t0 = vader_front_parser$parse_break(l0);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l1 == INT32_C(27))) {
        t1 = vader_front_parser$parse_expr(l0, INT32_C(7));
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_front_parser$parse_continue(l0);
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_parser$parse_const_decl(void* l0, void* l1, uint8_t l2, void* l3) {
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    void* l6 = NULL;
    void* l8 = NULL;
    vader_string_t l7 = 0;
    bool t0;
    void* t1 = NULL;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[2] = { &l4, &l5 };
    void** gc_raw_roots[6] = { &l0, &l1, &l3, &l6, &l8, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l7, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_front_parser$reject_free_fn_decorators(l0, l1, 1437u, 79u);
    vader_front_parser$match_kind(l0, (uint8_t) 45);
    t0 = vader_front_parser$check(l0, (uint8_t) 78);
    if (t0) {
        t1 = vader_front_parser$peek_at(l0, INT32_C(1));
        if (((vader_struct_vader_front_lexer$Token_t*) t1)->f_kind == INT32_C(2)) {
            t1 = vader_front_parser$peek_at(l0, INT32_C(1));
            t2 = ((vader_struct_vader_front_lexer$Token_t*) t1)->f_text;
            if (t2 == 1778u) {
                t1 = vader_front_parser$desugar_comptime_const(l0, l1, l2, l3, vader_box_obj(0u, NULL));
                { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
    }
    l4 = vader_front_parser$parse_expr(l0, INT32_C(0));
    l5 = vader_front_parser$comptime_helper_marker(l1, l4);
    if (!(l5.tag == 0u)) {
        l6 = l5.payload.obj;
        t1 = vader_front_parser$through_comptime_helper(l0, l1, l2, l3, vader_box_obj(0u, NULL), l4, l6, true);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = vader_front_parser$peek_at(l0, INT32_C(-1));
    l6 = vader_front_parser$span_of(l0, l3, l6);
    l7 = ((vader_struct_vader_front_lexer$Token_t*) l3)->f_text;
    l8 = ((vader_struct_vader_front_lexer$Token_t*) l3)->f_span;
    vader_struct_toolchain_ast$ConstDecl_t* _a0_obj = (vader_struct_toolchain_ast$ConstDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$ConstDecl_t));
    vader_obj_header_init(_a0_obj, 754u);
    _a0_obj->f_span = l6;
    _a0_obj->f_id = INT64_C(0);
    _a0_obj->f_name = l7;
    _a0_obj->f_name_span = l8;
    _a0_obj->f_visibility = l2;
    _a0_obj->f_ty = vader_box_obj(0u, NULL);
    _a0_obj->f_value = l4;
    _a0_obj->f_decorators = l1;
    _a0_obj->f_comptime_body = vader_box_obj(0u, NULL);
    _a0_obj->f_comptime_as_decorator = false;
    _a0_obj->f_doc = vader_box_obj(0u, NULL);
    t1 = (void*) _a0_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_parser$parse_continue(void* l0) {
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
    l1 = vader_front_parser$advance(l0);
    l2 = vader_box_obj(0u, NULL);
    t0 = vader_front_parser$check(l0, (uint8_t) 2);
    if (t0) {
        t1 = vader_front_parser$advance(l0);
        t2 = ((vader_struct_vader_front_lexer$Token_t*) t1)->f_text;
        l2 = vader_box_string(447u, t2);
    }
    l3 = vader_front_parser$peek_at(l0, INT32_C(-1));
    t1 = vader_front_parser$span_of(l0, l1, l3);
    vader_struct_toolchain_ast$ContinueStmt_t* _a0_obj = (vader_struct_toolchain_ast$ContinueStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$ContinueStmt_t));
    vader_obj_header_init(_a0_obj, 755u);
    _a0_obj->f_span = t1;
    _a0_obj->f_id = INT64_C(0);
    _a0_obj->f_label = l2;
    t1 = (void*) _a0_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_parser$parse_decl(void* l0) {
    vader_box_t l1 = vader_box_null(), l4 = vader_box_null(), l5 = vader_box_null();
    void* l2 = NULL;
    uint8_t l3;
    bool t0;
    void* t1 = NULL;
    vader_string_t t2 = 0;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l1, &l4, &l5, &t3 };
    void** gc_raw_roots[3] = { &l0, &l2, &t1 };
    vader_string_t* gc_atom_roots[1] = { &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_front_parser$take_doc(l0);
    t0 = vader_front_parser$check(l0, (uint8_t) 78);
    if (t0) {
        t0 = vader_front_parser$check_at(l0, (uint8_t) 2, INT32_C(1));
        if (t0) {
            t1 = vader_front_parser$peek_at(l0, INT32_C(1));
            t2 = ((vader_struct_vader_front_lexer$Token_t*) t1)->f_text;
            if (t2 == 1596u) {
                t3 = vader_front_parser$parse_assert_decl(l0);
                { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
    }
    l2 = vader_front_parser$parse_decorators(l0);
    vader_front_parser$reject_assert_decorator(l0, l2);
    vader_front_parser$check_guard_arity(l0, l2);
    vader_front_parser$check_c_struct_arguments(l0, l2);
    l3 = (uint8_t) 1;
    t3 = vader_front_parser$match_kind(l0, (uint8_t) 30);
    if (!(t3.tag == 0u)) {
        l3 = (uint8_t) 0;
    }
    l4 = vader_front_parser$parse_decorated_decl(l0, l2, l3);
    if (!(l4.tag == 0u)) {
        if (!(l4.tag == 767u)) {
            vader_front_parser$reject_displayable_decorator(l0, l2);
        }
    }
    if (l4.tag == 0u) {
        { vader_box_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 0u) {
        { vader_box_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = l4;
    l2 = l1.payload.obj;
    vader_front_parser$set_decl_doc(l5, l2);
    { vader_box_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_parser$parse_decorated_decl(void* l0, void* l1, uint8_t l2) {
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
    t0 = vader_front_parser$check(l0, (uint8_t) 28);
    if (t0) {
        t1 = vader_front_parser$parse_import_decl(l0, l1);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_front_parser$is_impl_decl(l0);
    if (t0) {
        t1 = vader_front_parser$parse_impl_decl(l0, l1);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_front_parser$check(l0, (uint8_t) 2);
    if (t0) {
        t0 = vader_front_parser$check_at(l0, (uint8_t) 52, INT32_C(1));
        if (t0) {
            t0 = vader_front_parser$peek_is_lhs_generic_alias_head(l0);
            if (t0) {
                t1 = vader_front_parser$parse_lhs_generic_alias_decl(l0, l1, l2);
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
    }
    t0 = vader_front_parser$check(l0, (uint8_t) 2);
    if (t0) {
        t0 = vader_front_parser$check_at(l0, (uint8_t) 71, INT32_C(1));
        if (t0) {
            t2 = vader_front_parser$parse_named_decl(l0, l1, l2);
            { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    t0 = vader_front_parser$check(l0, (uint8_t) 2);
    if (t0) {
        t0 = vader_front_parser$check_at(l0, (uint8_t) 87, INT32_C(1));
        if (t0) {
            t1 = vader_front_parser$parse_typed_const_decl(l0, l1, l2);
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l3 = vader_front_parser$peek(l0);
    l4 = ((vader_struct_vader_front_lexer$Token_t*) l3)->f_span;
    l5 = vader_front_parser$describe_token(l3);
    l5 = concat_2(2065u, l5);
    vader_front_parser$error(l0, (uint8_t) 4, l4, l5);
    vader_front_parser$sync_to_top_level(l0);
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static void* vader_front_parser$parse_decorator(void* l0) {
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
    l1 = vader_front_parser$advance(l0);
    l2 = vader_front_parser$expect(l0, (uint8_t) 2, 1822u);
    vader_array_t* _a0_arr = vader_array_new(349u, 0u, 13u, 1716u);
    l3 = (void*) _a0_arr;
    t0 = vader_front_parser$match_kind(l0, (uint8_t) 79);
    if (!(t0.tag == 0u)) {
        t1 = vader_front_parser$check(l0, (uint8_t) 80);
        if (!(t1)) {
            l4 = true;
            for (;;) {
                if (!(l4)) {
                    t0 = vader_front_parser$match_kind(l0, (uint8_t) 85);
                    if (t0.tag == 0u) break;
                    t1 = vader_front_parser$check(l0, (uint8_t) 80);
                    if (t1) break;
                }
                l4 = false;
                l5 = vader_front_parser$parse_expr(l0, INT32_C(0));
                vader_array_push_ref((vader_array_t*) l3, l5.payload.obj);
                continue;
            }
        }
        vader_front_parser$expect(l0, (uint8_t) 80, 1271u);
    }
    l6 = vader_front_parser$peek_at(l0, INT32_C(-1));
    l1 = vader_front_parser$span_of(l0, l1, l6);
    l7 = ((vader_struct_vader_front_lexer$Token_t*) l2)->f_text;
    vader_struct_toolchain_ast$Decorator_t* _a1_obj = (vader_struct_toolchain_ast$Decorator_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$Decorator_t));
    vader_obj_header_init(_a1_obj, 756u);
    _a1_obj->f_span = l1;
    _a1_obj->f_id = INT64_C(0);
    _a1_obj->f_name = l7;
    _a1_obj->f_args = l3;
    t2 = (void*) _a1_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_parser$parse_decorators(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    bool t0;
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(43u, 0u, 13u, 756u);
    l1 = (void*) _a0_arr;
    for (;;) {
        t0 = vader_front_parser$check(l0, (uint8_t) 78);
        if (t0) {
            l2 = vader_front_parser$parse_decorator(l0);
            vader_array_push_ref((vader_array_t*) l1, l2);
            vader_front_parser$skip_newlines(l0);
            continue;
        }
        break;
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_parser$parse_defer(void* l0) {
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
    l1 = vader_front_parser$advance(l0);
    l2 = ((vader_struct_vader_front_lexer$Token_t*) l1)->f_span;
    vader_struct_toolchain_ast$NullLitExpr_t* _a0_obj = (vader_struct_toolchain_ast$NullLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$NullLitExpr_t));
    vader_obj_header_init(_a0_obj, 800u);
    _a0_obj->f_span = ((vader_struct_vader_front_lexer$Token_t*) l1)->f_span;
    _a0_obj->f_id = INT64_C(0);
    l3 = (void*) _a0_obj;
    vader_struct_toolchain_ast$ExprStmt_t* _a1_obj = (vader_struct_toolchain_ast$ExprStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$ExprStmt_t));
    vader_obj_header_init(_a1_obj, 770u);
    _a1_obj->f_span = l2;
    _a1_obj->f_id = INT64_C(0);
    _a1_obj->f_expr = vader_ref_box(l3);
    t0 = (void*) _a1_obj;
    vader_struct_toolchain_ast$DeferStmtBody_t* _a2_obj = (vader_struct_toolchain_ast$DeferStmtBody_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$DeferStmtBody_t));
    vader_obj_header_init(_a2_obj, 759u);
    _a2_obj->f_stmt = vader_ref_box(t0);
    t0 = (void*) _a2_obj;
    l4 = vader_ref_box(t0);
    t1 = vader_front_parser$check(l0, (uint8_t) 83);
    if (t1) {
        t0 = vader_front_parser$parse_block(l0);
        vader_struct_toolchain_ast$DeferBlockBody_t* _a3_obj = (vader_struct_toolchain_ast$DeferBlockBody_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$DeferBlockBody_t));
        vader_obj_header_init(_a3_obj, 757u);
        _a3_obj->f_block = t0;
        t0 = (void*) _a3_obj;
        l4 = vader_ref_box(t0);
    } else {
        l5 = vader_front_parser$parse_stmt(l0);
        if (!(l5.tag == 0u)) {
            vader_struct_toolchain_ast$DeferStmtBody_t* _a4_obj = (vader_struct_toolchain_ast$DeferStmtBody_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$DeferStmtBody_t));
            vader_obj_header_init(_a4_obj, 759u);
            _a4_obj->f_stmt = l5;
            t0 = (void*) _a4_obj;
            l4 = vader_ref_box(t0);
        }
    }
    if (l4.tag == 759u) {
        t0 = l4.payload.obj;
        l2 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$AssignStmt_t, f_span, ((vader_struct_toolchain_ast$DeferStmtBody_t*) t0)->f_stmt.payload.obj);
    } else {
        if (!(l4.tag == 757u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = l4.payload.obj;
        l2 = ((vader_struct_toolchain_ast$BlockExpr_t*) ((vader_struct_toolchain_ast$DeferBlockBody_t*) t0)->f_block)->f_span;
    }
    l1 = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_front_lexer$Token_t*) l1)->f_span)->f_start;
    l2 = ((vader_struct_toolchain_span$Span_t*) l2)->f_end;
    vader_struct_toolchain_span$Span_t* _a5_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
    vader_obj_header_init(_a5_obj, 835u);
    _a5_obj->f_start = l1;
    _a5_obj->f_end = l2;
    t0 = (void*) _a5_obj;
    vader_struct_toolchain_ast$DeferStmt_t* _a6_obj = (vader_struct_toolchain_ast$DeferStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$DeferStmt_t));
    vader_obj_header_init(_a6_obj, 758u);
    _a6_obj->f_span = t0;
    _a6_obj->f_id = INT64_C(0);
    _a6_obj->f_body = l4;
    t0 = (void*) _a6_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_parser$parse_destructure_assign(void* l0) {
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
    l1 = vader_front_parser$advance(l0);
    vader_array_t* _a0_arr = vader_array_new(354u, 0u, 13u, 1794u);
    l2 = (void*) _a0_arr;
    for (;;) {
        vader_front_parser$skip_newlines(l0);
        t0 = vader_front_parser$check(l0, (uint8_t) 82);
        if (!(t0)) {
            l3 = vader_front_parser$parse_assign_target(l0);
            vader_array_push_ref((vader_array_t*) l2, l3.payload.obj);
            vader_front_parser$skip_newlines(l0);
            t1 = vader_front_parser$match_kind(l0, (uint8_t) 85);
            if (t1.tag == 0u) break;
            continue;
        }
        break;
    }
    l4 = vader_front_parser$expect(l0, (uint8_t) 82, 1372u);
    t2 = ((vader_array_t*) l2)->length;
    if (t2 == INT64_C(0)) {
        l4 = vader_front_parser$span_of(l0, l1, l4);
        vader_front_parser$error(l0, (uint8_t) 12, l4, 1526u);
    }
    l5 = INT64_C(1);
    l6 = ((vader_array_t*) l2)->length;
    while ((l5 < l6)) {
        l7 = vader_chk_sub(i64, l5, INT64_C(1));
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l3 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l7);
        if (l3.tag == 809u) {
            t3 = l3.payload.obj;
            l4 = ((vader_struct_toolchain_ast$RestTarget_t*) t3)->f_span;
            vader_front_parser$error(l0, (uint8_t) 21, l4, 0u);
        }
        l5 = (l5 + INT64_C(1));
    }
    t3 = vader_front_parser$peek(l0);
    t4 = vader_front_parser$compound_op(((vader_struct_vader_front_lexer$Token_t*) t3)->f_kind);
    t0 = ((vader_struct_vader_front_parser$CompoundOpResult_t*) t4)->f_matched;
    if (t0) {
        l4 = vader_front_parser$advance(l0);
        l4 = vader_front_parser$span_of(l0, l1, l4);
        vader_front_parser$error(l0, (uint8_t) 18, l4, 1444u);
    } else {
        vader_front_parser$expect(l0, (uint8_t) 62, 1319u);
    }
    l3 = vader_front_parser$parse_expr(l0, INT32_C(0));
    l4 = vader_front_parser$peek_at(l0, INT32_C(-1));
    t3 = vader_front_parser$span_of(l0, l1, l4);
    vader_struct_toolchain_ast$DestructureAssignStmt_t* _a2_obj = (vader_struct_toolchain_ast$DestructureAssignStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$DestructureAssignStmt_t));
    vader_obj_header_init(_a2_obj, 760u);
    _a2_obj->f_span = t3;
    _a2_obj->f_id = INT64_C(0);
    _a2_obj->f_targets = l2;
    _a2_obj->f_value = l3;
    t3 = (void*) _a2_obj;
    { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_parser$parse_enum_decl(void* l0, void* l1, uint8_t l2, void* l3) {
    void* l4 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    void* l13 = NULL;
    void* l15 = NULL;
    void* l19 = NULL;
    void* l20 = NULL;
    void* l22 = NULL;
    vader_box_t l5 = vader_box_null(), l9 = vader_box_null(), l10 = vader_box_null(), l11 = vader_box_null(), l12 = vader_box_null(), l14 = vader_box_null(), l18 = vader_box_null();
    int64_t l7;
    uint64_t l16;
    bool l17;
    vader_string_t l21 = 0;
    vader_box_t t0 = vader_box_null();
    bool t1;
    void* t2 = NULL;
    void* t3 = NULL;
    int64_t t4;
    vader_box_t* gc_roots[8] = { &l5, &l9, &l10, &l11, &l12, &l14, &l18, &t0 };
    void** gc_raw_roots[13] = {
        &l0, &l1, &l3, &l4, &l6, &l8, &l13, &l15, &l19, &l20, &l22, &t2, &t3,
    };
    vader_string_t* gc_atom_roots[1] = { &l21 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 8u, 13u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_front_parser$reject_free_fn_decorators(l0, l1, 1528u, 0u);
    vader_front_parser$reject_c_decorators(l0, l1, 1528u);
    vader_front_parser$advance(l0);
    vader_array_t* _a0_arr = vader_array_new(349u, 0u, 13u, 1716u);
    l4 = (void*) _a0_arr;
    t0 = vader_front_parser$match_kind(l0, (uint8_t) 79);
    if (!(t0.tag == 0u)) {
        l5 = vader_front_parser$parse_type(l0);
        vader_array_push_ref((vader_array_t*) l4, l5.payload.obj);
        t0 = vader_front_parser$match_kind(l0, (uint8_t) 85);
        if (!(t0.tag == 0u)) {
            l5 = vader_front_parser$parse_type(l0);
            vader_array_push_ref((vader_array_t*) l4, l5.payload.obj);
        }
        vader_front_parser$expect(l0, (uint8_t) 80, 1272u);
    }
    vader_front_parser$expect(l0, (uint8_t) 83, 1399u);
    vader_front_parser$skip_newlines(l0);
    vader_array_t* _a1_arr = vader_array_new(46u, 0u, 13u, 768u);
    l6 = (void*) _a1_arr;
    for (;;) {
        t1 = vader_front_parser$check(l0, (uint8_t) 84);
        if (!(t1)) {
            t1 = vader_front_parser$check(l0, (uint8_t) 0);
            if (t1) break;
            l7 = ((vader_array_t*) ((vader_struct_vader_front_parser$Parser_t*) l0)->f_errors)->length;
            l5 = vader_front_parser$take_doc(l0);
            l8 = vader_front_parser$expect(l0, (uint8_t) 2, 2999u);
            l9 = vader_box_obj(0u, NULL);
            t0 = vader_front_parser$match_kind(l0, (uint8_t) 83);
            if (!(t0.tag == 0u)) {
                t2 = vader_front_parser$parse_struct_lit_fields(l0);
                t3 = ((vader_struct_vader_front_parser$CommaList__toolchain_ast_StructLitField___toolchain_ast_StructLitSpread_t*) t2)->f_items;
                l9 = vader_ref_box(t3);
                vader_front_parser$expect(l0, (uint8_t) 84, 1413u);
            }
            l10 = vader_box_obj(0u, NULL);
            l11 = vader_box_obj(0u, NULL);
            t0 = vader_front_parser$match_kind(l0, (uint8_t) 62);
            if (!(t0.tag == 0u)) {
                l12 = vader_front_parser$match_kind(l0, (uint8_t) 37);
                l13 = vader_front_parser$expect(l0, (uint8_t) 3, 2177u);
                l14 = ((vader_struct_vader_front_lexer$Token_t*) l13)->f_value;
                if (l14.tag == 455u) {
                    l15 = ((vader_struct_vader_front_lexer$Token_t*) l13)->f_span;
                    l16 = ((uint64_t) l14.payload.i);
                    l17 = !(l12.tag == 0u);
                    vader_struct_toolchain_ast$IntLitExpr_t* _a2_obj = (vader_struct_toolchain_ast$IntLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$IntLitExpr_t));
                    vader_obj_header_init(_a2_obj, 788u);
                    _a2_obj->f_span = l15;
                    _a2_obj->f_id = INT64_C(0);
                    _a2_obj->f_value = l16;
                    _a2_obj->f_negative = l17;
                    t2 = (void*) _a2_obj;
                    t4 = toolchain_ast$int_literal_value(t2);
                    l10 = vader_box_i64(451u, t4);
                }
                l18 = l12;
                if (l18.tag == 0u) {
                    l19 = l13;
                } else {
                    l19 = l18.payload.obj;
                }
                t2 = vader_front_parser$span_of(l0, l19, l13);
                l11 = vader_ref_box(t2);
            }
            l20 = ((vader_struct_vader_front_lexer$Token_t*) l8)->f_span;
            l21 = ((vader_struct_vader_front_lexer$Token_t*) l8)->f_text;
            vader_struct_toolchain_ast$EnumVariant_t* _a3_obj = (vader_struct_toolchain_ast$EnumVariant_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$EnumVariant_t));
            vader_obj_header_init(_a3_obj, 768u);
            _a3_obj->f_span = l20;
            _a3_obj->f_id = INT64_C(0);
            _a3_obj->f_name = l21;
            _a3_obj->f_value = l10;
            _a3_obj->f_value_span = l11;
            _a3_obj->f_data = l9;
            _a3_obj->f_doc = l5;
            l22 = (void*) _a3_obj;
            vader_array_push_ref((vader_array_t*) l6, l22);
            t4 = ((vader_array_t*) ((vader_struct_vader_front_parser$Parser_t*) l0)->f_errors)->length;
            if ((t4 > l7)) {
                for (;;) {
                    t1 = vader_front_parser$check(l0, (uint8_t) 85);
                    if (!(t1)) {
                        t1 = vader_front_parser$check(l0, (uint8_t) 1);
                        if (t1) break;
                        t1 = vader_front_parser$check(l0, (uint8_t) 84);
                        if (t1) break;
                        t1 = vader_front_parser$check(l0, (uint8_t) 0);
                        if (t1) break;
                        vader_front_parser$advance(l0);
                        continue;
                    }
                    break;
                }
            }
            vader_front_parser$match_kind(l0, (uint8_t) 85);
            vader_front_parser$skip_newlines(l0);
            continue;
        }
        break;
    }
    l8 = vader_front_parser$expect(l0, (uint8_t) 84, 1405u);
    l8 = vader_front_parser$span_of(l0, l3, l8);
    l21 = ((vader_struct_vader_front_lexer$Token_t*) l3)->f_text;
    l13 = ((vader_struct_vader_front_lexer$Token_t*) l3)->f_span;
    vader_struct_toolchain_ast$EnumDecl_t* _a4_obj = (vader_struct_toolchain_ast$EnumDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$EnumDecl_t));
    vader_obj_header_init(_a4_obj, 767u);
    _a4_obj->f_span = l8;
    _a4_obj->f_id = INT64_C(0);
    _a4_obj->f_name = l21;
    _a4_obj->f_name_span = l13;
    _a4_obj->f_visibility = l2;
    _a4_obj->f_header = l4;
    _a4_obj->f_variants = l6;
    _a4_obj->f_decorators = l1;
    _a4_obj->f_doc = vader_box_obj(0u, NULL);
    t2 = (void*) _a4_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_parser$parse_expr(void* l0, int32_t l1) {
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
    t0 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_expr_depth;
    l2 = vader_chk_add(i32, t0, INT32_C(1));
    ((vader_struct_vader_front_parser$Parser_t*) l0)->f_expr_depth = l2;
    t0 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_expr_depth;
    if ((t0 > INT32_C(256))) {
        t0 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_expr_depth;
        l2 = vader_chk_sub(i32, t0, INT32_C(1));
        ((vader_struct_vader_front_parser$Parser_t*) l0)->f_expr_depth = l2;
        t1 = vader_front_parser$peek(l0);
        l3 = ((vader_struct_vader_front_lexer$Token_t*) t1)->f_span;
        vader_front_parser$report_nesting_too_deep(l0, 1946u);
        vader_struct_toolchain_ast$NullLitExpr_t* _a0_obj = (vader_struct_toolchain_ast$NullLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$NullLitExpr_t));
        vader_obj_header_init(_a0_obj, 800u);
        _a0_obj->f_span = l3;
        _a0_obj->f_id = INT64_C(0);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_front_parser$parse_prefix(l0);
    vader_struct_$Cell_f3a01222880a8b1f_t* _a1_obj = (vader_struct_$Cell_f3a01222880a8b1f_t*) vader_gc_alloc(sizeof(vader_struct_$Cell_f3a01222880a8b1f_t));
    vader_obj_header_init(_a1_obj, 460u);
    _a1_obj->f_value = t2;
    t1 = (void*) _a1_obj;
    l4 = vader_ref_box(t1);
    if (((vader_struct_$Cell_f3a01222880a8b1f_t*) l4.payload.obj)->f_value.tag == 778u) {
        t3 = vader_front_parser$allows_bare_lambda(l0);
        if (t3) {
            t3 = vader_front_parser$check(l0, (uint8_t) 76);
            if (t3) {
                l3 = ((vader_struct_$Cell_f3a01222880a8b1f_t*) l4.payload.obj)->f_value.payload.obj;
                l3 = vader_front_parser$parse_single_param_lambda_tail(l0, l3);
                ((vader_struct_$Cell_f3a01222880a8b1f_t*) l4.payload.obj)->f_value = vader_ref_box(l3);
                VADER_WRITE_BARRIER((vader_struct_$Cell_f3a01222880a8b1f_t*) l4.payload.obj);
            }
        }
    }
    l2 = INT32_C(-1);
    {
        {
            for (;;) {
                l3 = vader_front_parser$peek(l0);
                l5 = vader_front_parser$postfix_bp(((vader_struct_vader_front_lexer$Token_t*) l3)->f_kind);
                if ((l5 >= INT32_C(0))) {
                    if ((l5 >= l1)) {
                        if (((vader_struct_vader_front_lexer$Token_t*) l3)->f_kind == INT32_C(81)) {
                            l6 = true;
                        } else {
                            l6 = ((vader_struct_vader_front_lexer$Token_t*) l3)->f_kind == INT32_C(79);
                        }
                        if (l6) {
                            if (((vader_struct_$Cell_f3a01222880a8b1f_t*) l4.payload.obj)->f_value.tag == 781u) goto end_63;
                            if (((vader_struct_$Cell_f3a01222880a8b1f_t*) l4.payload.obj)->f_value.tag == 795u) goto end_63;
                            if (((vader_struct_$Cell_f3a01222880a8b1f_t*) l4.payload.obj)->f_value.tag == 747u) goto end_63;
                        }
                        l7 = ((vader_struct_$Cell_f3a01222880a8b1f_t*) l4.payload.obj)->f_value;
                        l8 = vader_front_parser$parse_postfix(l0, l7, l3);
                        ((vader_struct_$Cell_f3a01222880a8b1f_t*) l4.payload.obj)->f_value = l8;
                        VADER_WRITE_BARRIER((vader_struct_$Cell_f3a01222880a8b1f_t*) l4.payload.obj);
                        l2 = INT32_C(-1);
                        continue;
                    }
                }
                if (((vader_struct_vader_front_lexer$Token_t*) l3)->f_kind == INT32_C(60)) {
                    t1 = vader_front_parser$peek_at(l0, INT32_C(1));
                    if (((vader_struct_vader_front_lexer$Token_t*) t1)->f_kind == INT32_C(21)) {
                        if ((INT32_C(20) >= l1)) {
                            l9 = l2 == INT32_C(20);
                            if (l9) {
                                l10 = ((vader_struct_vader_front_lexer$Token_t*) l3)->f_span;
                                vader_front_parser$error(l0, (uint8_t) 6, l10, 1748u);
                            }
                            vader_front_parser$advance(l0);
                            vader_front_parser$advance(l0);
                            l11 = vader_front_parser$parse_expr(l0, INT32_C(21));
                            if (l9) {
                                continue;
                            }
                            l12 = ((vader_struct_toolchain_span$Span_t*) VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, ((vader_struct_$Cell_f3a01222880a8b1f_t*) l4.payload.obj)->f_value.payload.obj))->f_start;
                            l13 = ((vader_struct_toolchain_span$Span_t*) VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l11.payload.obj))->f_end;
                            vader_struct_toolchain_span$Span_t* _a2_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
                            vader_obj_header_init(_a2_obj, 835u);
                            _a2_obj->f_start = l12;
                            _a2_obj->f_end = l13;
                            l14 = (void*) _a2_obj;
                            l15 = ((vader_struct_$Cell_f3a01222880a8b1f_t*) l4.payload.obj)->f_value;
                            vader_struct_toolchain_ast$BinaryExpr_t* _a3_obj = (vader_struct_toolchain_ast$BinaryExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$BinaryExpr_t));
                            vader_obj_header_init(_a3_obj, 746u);
                            _a3_obj->f_span = l14;
                            _a3_obj->f_id = INT64_C(0);
                            _a3_obj->f_op = (uint8_t) 20;
                            _a3_obj->f_left = l15;
                            _a3_obj->f_right = l11;
                            l16 = (void*) _a3_obj;
                            ((vader_struct_$Cell_f3a01222880a8b1f_t*) l4.payload.obj)->f_value = vader_ref_box(l16);
                            VADER_WRITE_BARRIER((vader_struct_$Cell_f3a01222880a8b1f_t*) l4.payload.obj);
                            l2 = INT32_C(20);
                            continue;
                        }
                    }
                }
                if (((vader_struct_vader_front_lexer$Token_t*) l3)->f_kind == INT32_C(60)) {
                    t1 = vader_front_parser$peek_at(l0, INT32_C(1));
                    if (((vader_struct_vader_front_lexer$Token_t*) t1)->f_kind == INT32_C(19)) {
                        if ((INT32_C(20) >= l1)) {
                            l17 = l2 == INT32_C(20);
                            if (l17) {
                                l18 = ((vader_struct_vader_front_lexer$Token_t*) l3)->f_span;
                                vader_front_parser$error(l0, (uint8_t) 6, l18, 1749u);
                            }
                            l19 = vader_front_parser$advance(l0);
                            vader_front_parser$advance(l0);
                            l20 = vader_front_parser$parse_type(l0);
                            if (l17) {
                                continue;
                            }
                            vader_struct___lambda_env_vader_front_parser_1_t* _a4_obj = (vader_struct___lambda_env_vader_front_parser_1_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_front_parser_1_t));
                            vader_obj_header_init(_a4_obj, 503u);
                            _a4_obj->f_cap_0 = l4;
                            t1 = (void*) _a4_obj;
                            vader_fn_t* _a5_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
                            vader_obj_header_init(_a5_closure, 413u);
                            _a5_closure->code = (void*) &vader_fn_lift___lambda_vader_front_parser_0;
                            _a5_closure->env = t1;
                            l21 = (void*) _a5_closure;
                            vader_front_parser$reject_as_binder(l0, (uint8_t) 19, l21);
                            l22 = ((vader_struct_toolchain_span$Span_t*) VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, ((vader_struct_$Cell_f3a01222880a8b1f_t*) l4.payload.obj)->f_value.payload.obj))->f_start;
                            l23 = ((vader_struct_toolchain_span$Span_t*) VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l20.payload.obj))->f_end;
                            vader_struct_toolchain_span$Span_t* _a6_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
                            vader_obj_header_init(_a6_obj, 835u);
                            _a6_obj->f_start = l22;
                            _a6_obj->f_end = l23;
                            l24 = (void*) _a6_obj;
                            l25 = ((vader_struct_$Cell_f3a01222880a8b1f_t*) l4.payload.obj)->f_value;
                            vader_struct_toolchain_ast$BinaryExpr_t* _a7_obj = (vader_struct_toolchain_ast$BinaryExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$BinaryExpr_t));
                            vader_obj_header_init(_a7_obj, 746u);
                            _a7_obj->f_span = l24;
                            _a7_obj->f_id = INT64_C(0);
                            _a7_obj->f_op = (uint8_t) 18;
                            _a7_obj->f_left = l25;
                            _a7_obj->f_right = l20;
                            l26 = (void*) _a7_obj;
                            l27 = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_front_lexer$Token_t*) l19)->f_span)->f_start;
                            l28 = ((vader_struct_toolchain_span$Span_t*) VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l20.payload.obj))->f_end;
                            vader_struct_toolchain_span$Span_t* _a8_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
                            vader_obj_header_init(_a8_obj, 835u);
                            _a8_obj->f_start = l27;
                            _a8_obj->f_end = l28;
                            t1 = (void*) _a8_obj;
                            vader_struct_toolchain_ast$UnaryExpr_t* _a9_obj = (vader_struct_toolchain_ast$UnaryExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$UnaryExpr_t));
                            vader_obj_header_init(_a9_obj, 827u);
                            _a9_obj->f_span = t1;
                            _a9_obj->f_id = INT64_C(0);
                            _a9_obj->f_op = (uint8_t) 1;
                            _a9_obj->f_operand = vader_ref_box(l26);
                            l29 = (void*) _a9_obj;
                            ((vader_struct_$Cell_f3a01222880a8b1f_t*) l4.payload.obj)->f_value = vader_ref_box(l29);
                            VADER_WRITE_BARRIER((vader_struct_$Cell_f3a01222880a8b1f_t*) l4.payload.obj);
                            l2 = INT32_C(20);
                            continue;
                        }
                    }
                }
                if (((vader_struct_vader_front_lexer$Token_t*) l3)->f_kind == INT32_C(61)) {
                    if ((INT32_C(6) >= l1)) {
                        vader_front_parser$advance(l0);
                        l30 = vader_front_parser$parse_coalesce_fallback(l0);
                        l31 = ((vader_struct_toolchain_span$Span_t*) VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, ((vader_struct_$Cell_f3a01222880a8b1f_t*) l4.payload.obj)->f_value.payload.obj))->f_start;
                        t1 = vader_front_parser$peek_at(l0, INT32_C(-1));
                        l32 = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_front_lexer$Token_t*) t1)->f_span)->f_end;
                        vader_struct_toolchain_span$Span_t* _a10_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
                        vader_obj_header_init(_a10_obj, 835u);
                        _a10_obj->f_start = l31;
                        _a10_obj->f_end = l32;
                        l33 = (void*) _a10_obj;
                        l34 = ((vader_struct_$Cell_f3a01222880a8b1f_t*) l4.payload.obj)->f_value;
                        vader_struct_toolchain_ast$NullCoalesceExpr_t* _a11_obj = (vader_struct_toolchain_ast$NullCoalesceExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$NullCoalesceExpr_t));
                        vader_obj_header_init(_a11_obj, 799u);
                        _a11_obj->f_span = l33;
                        _a11_obj->f_id = INT64_C(0);
                        _a11_obj->f_left = l34;
                        _a11_obj->f_fallback = l30;
                        l35 = (void*) _a11_obj;
                        ((vader_struct_$Cell_f3a01222880a8b1f_t*) l4.payload.obj)->f_value = vader_ref_box(l35);
                        VADER_WRITE_BARRIER((vader_struct_$Cell_f3a01222880a8b1f_t*) l4.payload.obj);
                        l2 = INT32_C(-1);
                        continue;
                    }
                }
                l36 = vader_front_parser$infix_for(((vader_struct_vader_front_lexer$Token_t*) l3)->f_kind);
                t3 = ((vader_struct_vader_front_parser$InfixOpDescr_t*) l36)->f_has;
                if (!(t3)) {
                    break;
                }
                t0 = ((vader_struct_vader_front_parser$InfixOpDescr_t*) l36)->f_left_bp;
                if (!((t0 >= l1))) {
                    break;
                }
                t3 = ((vader_struct_vader_front_parser$InfixOpDescr_t*) l36)->f_non_assoc;
                if (t3) {
                    l38 = ((vader_struct_vader_front_parser$InfixOpDescr_t*) l36)->f_left_bp;
                    l37 = l2 == l38;
                } else {
                    l37 = false;
                }
                if (l37) {
                    l39 = ((vader_struct_vader_front_lexer$Token_t*) l3)->f_span;
                    l40 = vader_front_parser$describe_token(l3);
                    l41 = concat_2(1747u, l40);
                    vader_front_parser$error(l0, (uint8_t) 6, l39, l41);
                }
                vader_front_parser$advance(l0);
                t3 = ((vader_struct_vader_front_parser$InfixOpDescr_t*) l36)->f_non_assoc;
                if (t3) {
                    t0 = ((vader_struct_vader_front_parser$InfixOpDescr_t*) l36)->f_right_bp;
                    l42 = vader_chk_add(i32, t0, INT32_C(1));
                } else {
                    l42 = ((vader_struct_vader_front_parser$InfixOpDescr_t*) l36)->f_right_bp;
                }
                if (((vader_struct_vader_front_parser$InfixOpDescr_t*) l36)->f_op == INT32_C(18)) {
                    l43 = vader_front_parser$parse_type(l0);
                } else {
                    l43 = vader_front_parser$parse_expr(l0, l42);
                }
                if (l37) {
                    continue;
                }
                if (((vader_struct_vader_front_lexer$Token_t*) l3)->f_kind == INT32_C(73)) {
                    l44 = true;
                } else {
                    l44 = ((vader_struct_vader_front_lexer$Token_t*) l3)->f_kind == INT32_C(74);
                }
                if (l44) {
                    l45 = ((vader_struct_toolchain_span$Span_t*) VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, ((vader_struct_$Cell_f3a01222880a8b1f_t*) l4.payload.obj)->f_value.payload.obj))->f_start;
                    l46 = ((vader_struct_toolchain_span$Span_t*) VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l43.payload.obj))->f_end;
                    vader_struct_toolchain_span$Span_t* _a12_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
                    vader_obj_header_init(_a12_obj, 835u);
                    _a12_obj->f_start = l45;
                    _a12_obj->f_end = l46;
                    l47 = (void*) _a12_obj;
                    l48 = ((vader_struct_vader_front_lexer$Token_t*) l3)->f_kind == INT32_C(74);
                    l49 = ((vader_struct_$Cell_f3a01222880a8b1f_t*) l4.payload.obj)->f_value;
                    vader_struct_toolchain_ast$RangeExpr_t* _a13_obj = (vader_struct_toolchain_ast$RangeExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$RangeExpr_t));
                    vader_obj_header_init(_a13_obj, 806u);
                    _a13_obj->f_span = l47;
                    _a13_obj->f_id = INT64_C(0);
                    _a13_obj->f_inclusive = l48;
                    _a13_obj->f_lower = l49;
                    _a13_obj->f_upper = l43;
                    l50 = (void*) _a13_obj;
                    ((vader_struct_$Cell_f3a01222880a8b1f_t*) l4.payload.obj)->f_value = vader_ref_box(l50);
                    VADER_WRITE_BARRIER((vader_struct_$Cell_f3a01222880a8b1f_t*) l4.payload.obj);
                } else {
                    if (((vader_struct_vader_front_parser$InfixOpDescr_t*) l36)->f_op == INT32_C(18)) {
                        vader_struct___lambda_env_vader_front_parser_3_t* _a14_obj = (vader_struct___lambda_env_vader_front_parser_3_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_front_parser_3_t));
                        vader_obj_header_init(_a14_obj, 504u);
                        _a14_obj->f_cap_0 = l4;
                        t1 = (void*) _a14_obj;
                        vader_fn_t* _a15_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
                        vader_obj_header_init(_a15_closure, 413u);
                        _a15_closure->code = (void*) &vader_fn_lift___lambda_vader_front_parser_2;
                        _a15_closure->env = t1;
                        l51 = (void*) _a15_closure;
                        vader_front_parser$reject_as_binder(l0, (uint8_t) 19, l51);
                    }
                    l52 = ((vader_struct_toolchain_span$Span_t*) VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, ((vader_struct_$Cell_f3a01222880a8b1f_t*) l4.payload.obj)->f_value.payload.obj))->f_start;
                    l53 = ((vader_struct_toolchain_span$Span_t*) VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l43.payload.obj))->f_end;
                    vader_struct_toolchain_span$Span_t* _a16_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
                    vader_obj_header_init(_a16_obj, 835u);
                    _a16_obj->f_start = l52;
                    _a16_obj->f_end = l53;
                    l54 = (void*) _a16_obj;
                    l55 = ((vader_struct_vader_front_parser$InfixOpDescr_t*) l36)->f_op;
                    l56 = ((vader_struct_$Cell_f3a01222880a8b1f_t*) l4.payload.obj)->f_value;
                    vader_struct_toolchain_ast$BinaryExpr_t* _a17_obj = (vader_struct_toolchain_ast$BinaryExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$BinaryExpr_t));
                    vader_obj_header_init(_a17_obj, 746u);
                    _a17_obj->f_span = l54;
                    _a17_obj->f_id = INT64_C(0);
                    _a17_obj->f_op = l55;
                    _a17_obj->f_left = l56;
                    _a17_obj->f_right = l43;
                    l57 = (void*) _a17_obj;
                    ((vader_struct_$Cell_f3a01222880a8b1f_t*) l4.payload.obj)->f_value = vader_ref_box(l57);
                    VADER_WRITE_BARRIER((vader_struct_$Cell_f3a01222880a8b1f_t*) l4.payload.obj);
                }
                t3 = ((vader_struct_vader_front_parser$InfixOpDescr_t*) l36)->f_non_assoc;
                if (t3) {
                    l58 = ((vader_struct_vader_front_parser$InfixOpDescr_t*) l36)->f_left_bp;
                } else {
                    l58 = INT32_C(-1);
                }
                l2 = l58;
                continue;
            }
            goto end_62;
        } end_63: ;
    } end_62: ;
    t0 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_expr_depth;
    l2 = vader_chk_sub(i32, t0, INT32_C(1));
    ((vader_struct_vader_front_parser$Parser_t*) l0)->f_expr_depth = l2;
    { vader_box_t __vret = ((vader_struct_$Cell_f3a01222880a8b1f_t*) l4.payload.obj)->f_value; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_parser$parse_fn_body_tail(void* l0) {
    vader_box_t l1 = vader_box_null();
    void* l2 = NULL;
    void* l3 = NULL;
    bool t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_front_parser$check(l0, (uint8_t) 62);
    if (t0) {
        vader_front_parser$advance(l0);
        l1 = vader_front_parser$parse_expr(l0, INT32_C(0));
        l2 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l1.payload.obj);
        vader_array_t* _a0_arr = vader_array_new(351u, 0u, 13u, 1753u);
        l3 = (void*) _a0_arr;
        vader_struct_toolchain_ast$BlockExpr_t* _a1_obj = (vader_struct_toolchain_ast$BlockExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$BlockExpr_t));
        vader_obj_header_init(_a1_obj, 747u);
        _a1_obj->f_span = l2;
        _a1_obj->f_id = INT64_C(0);
        _a1_obj->f_stmts = l3;
        _a1_obj->f_trailing = l1;
        t1 = (void*) _a1_obj;
        vader_struct_vader_front_parser$FnBodyTail_t* _a2_obj = (vader_struct_vader_front_parser$FnBodyTail_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_parser$FnBodyTail_t));
        vader_obj_header_init(_a2_obj, 1198u);
        _a2_obj->f_body = vader_ref_box(t1);
        _a2_obj->f_is_expression_bodied = true;
        t1 = (void*) _a2_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_front_parser$check(l0, (uint8_t) 83);
    if (!(t0)) {
        vader_struct_vader_front_parser$FnBodyTail_t* _a3_obj = (vader_struct_vader_front_parser$FnBodyTail_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_parser$FnBodyTail_t));
        vader_obj_header_init(_a3_obj, 1198u);
        _a3_obj->f_body = vader_box_obj(0u, NULL);
        _a3_obj->f_is_expression_bodied = false;
        t1 = (void*) _a3_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_front_parser$parse_block(l0);
    vader_struct_vader_front_parser$FnBodyTail_t* _a4_obj = (vader_struct_vader_front_parser$FnBodyTail_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_parser$FnBodyTail_t));
    vader_obj_header_init(_a4_obj, 1198u);
    _a4_obj->f_body = vader_ref_box(t1);
    _a4_obj->f_is_expression_bodied = false;
    t1 = (void*) _a4_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_parser$parse_fn_decl(void* l0, void* l1, uint8_t l2, void* l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    vader_box_t l6 = vader_box_null(), l12 = vader_box_null();
    vader_string_t l9 = 0;
    bool l13, l14;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[3] = { &l6, &l12, &t0 };
    void** gc_raw_roots[10] = { &l0, &l1, &l3, &l4, &l5, &l7, &l8, &l10, &l11, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_front_parser$reject_c_decorators(l0, l1, 1451u);
    vader_front_parser$advance(l0);
    l4 = vader_front_parser$parse_angle_type_params(l0);
    l5 = vader_front_parser$parse_fn_signature_params(l0);
    l6 = vader_box_obj(0u, NULL);
    t0 = vader_front_parser$match_kind(l0, (uint8_t) 76);
    if (!(t0.tag == 0u)) {
        l6 = vader_front_parser$parse_type(l0);
    }
    l7 = vader_front_parser$parse_fn_body_tail(l0);
    l8 = vader_front_parser$peek_at(l0, INT32_C(-1));
    l8 = vader_front_parser$span_of(l0, l3, l8);
    l9 = ((vader_struct_vader_front_lexer$Token_t*) l3)->f_text;
    l10 = ((vader_struct_vader_front_lexer$Token_t*) l3)->f_span;
    l11 = ((vader_struct_vader_front_parser$FnSignature_t*) l5)->f_params;
    l12 = ((vader_struct_vader_front_parser$FnBodyTail_t*) l7)->f_body;
    l13 = ((vader_struct_vader_front_parser$FnBodyTail_t*) l7)->f_is_expression_bodied;
    l14 = ((vader_struct_vader_front_parser$FnSignature_t*) l5)->f_trailing_comma;
    vader_struct_toolchain_ast$FnDecl_t* _a0_obj = (vader_struct_toolchain_ast$FnDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$FnDecl_t));
    vader_obj_header_init(_a0_obj, 773u);
    _a0_obj->f_span = l8;
    _a0_obj->f_id = INT64_C(0);
    _a0_obj->f_name = l9;
    _a0_obj->f_name_span = l10;
    _a0_obj->f_visibility = l2;
    _a0_obj->f_type_params = l4;
    _a0_obj->f_params = l11;
    _a0_obj->f_return_type = l6;
    _a0_obj->f_body = l12;
    _a0_obj->f_decorators = l1;
    _a0_obj->f_sam_synthetic = false;
    _a0_obj->f_is_expression_bodied = l13;
    _a0_obj->f_materialized = false;
    _a0_obj->f_comptime_synthetic = false;
    _a0_obj->f_trailing_comma = l14;
    _a0_obj->f_doc = vader_box_obj(0u, NULL);
    _a0_obj->f_inherits = vader_box_obj(0u, NULL);
    t1 = (void*) _a0_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_parser$parse_fn_decl_inside_trait(void* l0) {
    vader_box_t l1 = vader_box_null(), l9 = vader_box_null(), l14 = vader_box_null();
    void* l2 = NULL;
    void* l5 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    uint8_t l3;
    bool l4, l15;
    vader_string_t l6 = 0;
    vader_box_t t0 = vader_box_null();
    bool t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[4] = { &l1, &l9, &l14, &t0 };
    void** gc_raw_roots[10] = { &l0, &l2, &l5, &l7, &l8, &l10, &l11, &l12, &l13, &t2 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_front_parser$take_doc(l0);
    l2 = vader_front_parser$parse_decorators(l0);
    vader_front_parser$reject_displayable_decorator(l0, l2);
    l3 = (uint8_t) 1;
    t0 = vader_front_parser$match_kind(l0, (uint8_t) 30);
    if (!(t0.tag == 0u)) {
        l3 = (uint8_t) 0;
    }
    t1 = vader_front_parser$check(l0, (uint8_t) 2);
    if (t1) {
        t2 = vader_front_parser$peek_at(l0, INT32_C(1));
        l4 = ((vader_struct_vader_front_lexer$Token_t*) t2)->f_kind == INT32_C(71);
    } else {
        l4 = false;
    }
    if (l4) {
        t2 = vader_front_parser$peek_at(l0, INT32_C(2));
        l4 = ((vader_struct_vader_front_lexer$Token_t*) t2)->f_kind == INT32_C(11);
    } else {
        l4 = false;
    }
    if (l4) {
        l5 = vader_front_parser$advance(l0);
        vader_front_parser$advance(l0);
        vader_front_parser$advance(l0);
        l7 = vader_front_parser$parse_angle_type_params(l0);
        l8 = vader_front_parser$parse_fn_signature_params(l0);
        l9 = vader_box_obj(0u, NULL);
        t0 = vader_front_parser$match_kind(l0, (uint8_t) 76);
        if (!(t0.tag == 0u)) {
            l9 = vader_front_parser$parse_type(l0);
        }
        l10 = vader_front_parser$parse_fn_body_tail(l0);
        l11 = vader_front_parser$peek_at(l0, INT32_C(-1));
        l11 = vader_front_parser$span_of(l0, l5, l11);
        l6 = ((vader_struct_vader_front_lexer$Token_t*) l5)->f_text;
        l12 = ((vader_struct_vader_front_lexer$Token_t*) l5)->f_span;
        l13 = ((vader_struct_vader_front_parser$FnSignature_t*) l8)->f_params;
        l14 = ((vader_struct_vader_front_parser$FnBodyTail_t*) l10)->f_body;
        l4 = ((vader_struct_vader_front_parser$FnBodyTail_t*) l10)->f_is_expression_bodied;
        l15 = ((vader_struct_vader_front_parser$FnSignature_t*) l8)->f_trailing_comma;
        vader_struct_toolchain_ast$FnDecl_t* _a0_obj = (vader_struct_toolchain_ast$FnDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$FnDecl_t));
        vader_obj_header_init(_a0_obj, 773u);
        _a0_obj->f_span = l11;
        _a0_obj->f_id = INT64_C(0);
        _a0_obj->f_name = l6;
        _a0_obj->f_name_span = l12;
        _a0_obj->f_visibility = l3;
        _a0_obj->f_type_params = l7;
        _a0_obj->f_params = l13;
        _a0_obj->f_return_type = l9;
        _a0_obj->f_body = l14;
        _a0_obj->f_decorators = l2;
        _a0_obj->f_sam_synthetic = false;
        _a0_obj->f_is_expression_bodied = l4;
        _a0_obj->f_materialized = false;
        _a0_obj->f_comptime_synthetic = false;
        _a0_obj->f_trailing_comma = l15;
        _a0_obj->f_doc = l1;
        _a0_obj->f_inherits = vader_box_obj(0u, NULL);
        t2 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = vader_front_parser$peek(l0);
    if (((vader_struct_vader_front_lexer$Token_t*) l2)->f_kind == INT32_C(11)) {
        l5 = ((vader_struct_vader_front_lexer$Token_t*) l2)->f_span;
        vader_front_parser$error(l0, (uint8_t) 4, l5, 2743u);
    } else {
        l5 = ((vader_struct_vader_front_lexer$Token_t*) l2)->f_span;
        l6 = vader_front_parser$describe_token(l2);
        l6 = concat_3(1933u, l6, 324u);
        vader_front_parser$error(l0, (uint8_t) 4, l5, l6);
    }
    for (;;) {
        t1 = vader_front_parser$check(l0, (uint8_t) 84);
        if (!(t1)) {
            t1 = vader_front_parser$check(l0, (uint8_t) 0);
            if (t1) break;
            t1 = vader_front_parser$check(l0, (uint8_t) 2);
            if (t1) {
                t2 = vader_front_parser$peek_at(l0, INT32_C(1));
                if (((vader_struct_vader_front_lexer$Token_t*) t2)->f_kind == INT32_C(71)) {
                    t2 = vader_front_parser$peek_at(l0, INT32_C(2));
                    if (((vader_struct_vader_front_lexer$Token_t*) t2)->f_kind == INT32_C(11)) break;
                }
            }
            vader_front_parser$advance(l0);
            continue;
        }
        break;
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static void* vader_front_parser$parse_fn_signature_params(void* l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l11 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    bool l2, l3, l6;
    vader_string_t l9 = 0;
    vader_string_t l10 = 0;
    vader_string_t l16 = 0;
    vader_box_t l12 = vader_box_null(), l13 = vader_box_null();
    bool t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[3] = { &l12, &l13, &t1 };
    void** gc_raw_roots[12] = { &l0, &l1, &l4, &l5, &l7, &l8, &l11, &l14, &l15, &l17, &l18, &t2 };
    vader_string_t* gc_atom_roots[3] = { &l9, &l10, &l16 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(48u, 0u, 13u, 774u);
    l1 = (void*) _a0_arr;
    l2 = false;
    vader_front_parser$expect(l0, (uint8_t) 79, 1266u);
    vader_front_parser$skip_newlines(l0);
    t0 = vader_front_parser$check(l0, (uint8_t) 80);
    if (!(t0)) {
        l3 = true;
        for (;;) {
            vader_front_parser$skip_newlines(l0);
            t0 = vader_front_parser$check(l0, (uint8_t) 80);
            if (!(t0)) {
                t0 = vader_front_parser$check(l0, (uint8_t) 0);
                if (t0) break;
                if (!(l3)) {
                    t1 = vader_front_parser$match_kind(l0, (uint8_t) 85);
                    if (t1.tag == 0u) break;
                    vader_front_parser$skip_newlines(l0);
                    t0 = vader_front_parser$check(l0, (uint8_t) 80);
                    if (t0) {
                        l2 = true;
                        break;
                    }
                }
                l3 = false;
                l4 = vader_front_parser$peek(l0);
                l5 = vader_front_parser$parse_decorators(l0);
                l6 = false;
                t0 = vader_front_parser$check(l0, (uint8_t) 86);
                if (t0) {
                    t0 = vader_front_parser$check_at(l0, (uint8_t) 86, INT32_C(1));
                    if (t0) {
                        t0 = vader_front_parser$check_at(l0, (uint8_t) 86, INT32_C(2));
                        if (t0) {
                            vader_front_parser$advance(l0);
                            vader_front_parser$advance(l0);
                            vader_front_parser$advance(l0);
                            l6 = true;
                        }
                    }
                }
                t0 = vader_front_parser$check(l0, (uint8_t) 34);
                if (!(t0)) {
                    t0 = vader_front_parser$check(l0, (uint8_t) 2);
                    if (!(t0)) {
                        l7 = vader_front_parser$peek(l0);
                        l8 = ((vader_struct_vader_front_lexer$Token_t*) l7)->f_span;
                        l9 = vader_front_parser$describe_token(l7);
                        l10 = concat_3(1934u, l9, 324u);
                        vader_front_parser$error(l0, (uint8_t) 1, l8, l10);
                        for (;;) {
                            t0 = vader_front_parser$check(l0, (uint8_t) 85);
                            if (!(t0)) {
                                t0 = vader_front_parser$check(l0, (uint8_t) 80);
                                if (t0) break;
                                t0 = vader_front_parser$check(l0, (uint8_t) 0);
                                if (t0) break;
                                vader_front_parser$advance(l0);
                                continue;
                            }
                            break;
                        }
                        continue;
                    }
                }
                l11 = vader_front_parser$advance(l0);
                l12 = vader_box_obj(0u, NULL);
                t1 = vader_front_parser$match_kind(l0, (uint8_t) 87);
                if (!(t1.tag == 0u)) {
                    vader_front_parser$skip_newlines(l0);
                    l12 = vader_front_parser$parse_type(l0);
                }
                l13 = vader_box_obj(0u, NULL);
                t1 = vader_front_parser$match_kind(l0, (uint8_t) 62);
                if (!(t1.tag == 0u)) {
                    l13 = vader_front_parser$parse_expr(l0, INT32_C(0));
                }
                l14 = vader_front_parser$peek_at(l0, INT32_C(-1));
                l15 = vader_front_parser$span_of(l0, l4, l14);
                l16 = ((vader_struct_vader_front_lexer$Token_t*) l11)->f_text;
                l17 = ((vader_struct_vader_front_lexer$Token_t*) l11)->f_span;
                vader_struct_toolchain_ast$FnParam_t* _a1_obj = (vader_struct_toolchain_ast$FnParam_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$FnParam_t));
                vader_obj_header_init(_a1_obj, 774u);
                _a1_obj->f_span = l15;
                _a1_obj->f_id = INT64_C(0);
                _a1_obj->f_name = l16;
                _a1_obj->f_name_span = l17;
                _a1_obj->f_ty = l12;
                _a1_obj->f_default_value = l13;
                _a1_obj->f_variadic = l6;
                _a1_obj->f_decorators = l5;
                l18 = (void*) _a1_obj;
                vader_array_push_ref((vader_array_t*) l1, l18);
                continue;
            }
            break;
        }
    }
    vader_front_parser$expect(l0, (uint8_t) 80, 1276u);
    vader_struct_vader_front_parser$FnSignature_t* _a2_obj = (vader_struct_vader_front_parser$FnSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_parser$FnSignature_t));
    vader_obj_header_init(_a2_obj, 1199u);
    _a2_obj->f_params = l1;
    _a2_obj->f_trailing_comma = l2;
    t2 = (void*) _a2_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_parser$parse_fn_type(void* l0) {
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
    l1 = vader_front_parser$advance(l0);
    vader_front_parser$expect(l0, (uint8_t) 79, 1265u);
    vader_array_t* _a0_arr = vader_array_new(349u, 0u, 13u, 1716u);
    l2 = (void*) _a0_arr;
    vader_front_parser$skip_newlines(l0);
    t0 = vader_front_parser$check(l0, (uint8_t) 80);
    if (!(t0)) {
        for (;;) {
            vader_front_parser$skip_newlines(l0);
            t0 = vader_front_parser$check(l0, (uint8_t) 80);
            if (!(t0)) {
                l3 = vader_front_parser$parse_type(l0);
                vader_array_push_ref((vader_array_t*) l2, l3.payload.obj);
                vader_front_parser$skip_newlines(l0);
                t1 = vader_front_parser$match_kind(l0, (uint8_t) 85);
                if (t1.tag == 0u) break;
                continue;
            }
            break;
        }
    }
    vader_front_parser$expect(l0, (uint8_t) 80, 1273u);
    l3 = vader_box_obj(0u, NULL);
    t1 = vader_front_parser$match_kind(l0, (uint8_t) 76);
    if (!(t1.tag == 0u)) {
        l3 = vader_front_parser$parse_type(l0);
    }
    l4 = vader_front_parser$peek_at(l0, INT32_C(-1));
    t2 = vader_front_parser$span_of(l0, l1, l4);
    vader_struct_toolchain_ast$FnTypeExpr_t* _a1_obj = (vader_struct_toolchain_ast$FnTypeExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$FnTypeExpr_t));
    vader_obj_header_init(_a1_obj, 775u);
    _a1_obj->f_span = t2;
    _a1_obj->f_id = INT64_C(0);
    _a1_obj->f_params = l2;
    _a1_obj->f_return_type = l3;
    t2 = (void*) _a1_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_parser$parse_for(void* l0, vader_box_t l1, bool l2) {
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
    l3 = vader_front_parser$advance(l0);
    t0 = vader_front_parser$check(l0, (uint8_t) 83);
    if (t0) {
        l4 = vader_front_parser$parse_block(l0);
        l5 = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_front_lexer$Token_t*) l3)->f_span)->f_start;
        l6 = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_toolchain_ast$BlockExpr_t*) l4)->f_span)->f_end;
        vader_struct_toolchain_span$Span_t* _a0_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
        vader_obj_header_init(_a0_obj, 835u);
        _a0_obj->f_start = l5;
        _a0_obj->f_end = l6;
        l5 = (void*) _a0_obj;
        t1 = (void*) &vader_data_77;
        vader_array_t* _a1_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l6 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
        vader_struct_toolchain_ast$ForStmt_t* _a2_obj = (vader_struct_toolchain_ast$ForStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$ForStmt_t));
        vader_obj_header_init(_a2_obj, 776u);
        _a2_obj->f_span = l5;
        _a2_obj->f_id = INT64_C(0);
        _a2_obj->f_label = l1;
        _a2_obj->f_form = vader_ref_box(l6);
        _a2_obj->f_body = l4;
        _a2_obj->f_is_comptime = l2;
        t1 = (void*) _a2_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l7 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_no_struct_lit_at;
    l8 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_bracket_depth;
    ((vader_struct_vader_front_parser$Parser_t*) l0)->f_no_struct_lit_at = l8;
    t0 = vader_front_parser$check(l0, (uint8_t) 2);
    if (t0) {
        t0 = vader_front_parser$check_at(l0, (uint8_t) 21, INT32_C(1));
        if (t0) {
            l4 = vader_front_parser$advance(l0);
            vader_front_parser$advance(l0);
            l9 = vader_front_parser$parse_expr(l0, INT32_C(0));
            ((vader_struct_vader_front_parser$Parser_t*) l0)->f_no_struct_lit_at = l7;
            l5 = vader_front_parser$parse_block(l0);
            l6 = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_front_lexer$Token_t*) l3)->f_span)->f_start;
            l10 = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_toolchain_ast$BlockExpr_t*) l5)->f_span)->f_end;
            vader_struct_toolchain_span$Span_t* _a3_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
            vader_obj_header_init(_a3_obj, 835u);
            _a3_obj->f_start = l6;
            _a3_obj->f_end = l10;
            l6 = (void*) _a3_obj;
            l11 = ((vader_struct_vader_front_lexer$Token_t*) l4)->f_text;
            l4 = ((vader_struct_vader_front_lexer$Token_t*) l4)->f_span;
            vader_struct_toolchain_ast$NamedVar_t* _a4_obj = (vader_struct_toolchain_ast$NamedVar_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$NamedVar_t));
            vader_obj_header_init(_a4_obj, 798u);
            _a4_obj->f_name = l11;
            _a4_obj->f_span = l4;
            t1 = (void*) _a4_obj;
            vader_struct_toolchain_ast$InFor_t* _a5_obj = (vader_struct_toolchain_ast$InFor_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$InFor_t));
            vader_obj_header_init(_a5_obj, 785u);
            _a5_obj->f_loop_var = vader_ref_box(t1);
            _a5_obj->f_iter = l9;
            l4 = (void*) _a5_obj;
            vader_struct_toolchain_ast$ForStmt_t* _a6_obj = (vader_struct_toolchain_ast$ForStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$ForStmt_t));
            vader_obj_header_init(_a6_obj, 776u);
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
    t0 = vader_front_parser$looks_like_for_destructure(l0);
    if (t0) {
        l9 = vader_front_parser$parse_let_binding(l0);
        vader_front_parser$expect(l0, (uint8_t) 21, 1388u);
        l12 = vader_front_parser$parse_expr(l0, INT32_C(0));
        ((vader_struct_vader_front_parser$Parser_t*) l0)->f_no_struct_lit_at = l7;
        l4 = vader_front_parser$parse_block(l0);
        l5 = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_front_lexer$Token_t*) l3)->f_span)->f_start;
        l6 = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_toolchain_ast$BlockExpr_t*) l4)->f_span)->f_end;
        vader_struct_toolchain_span$Span_t* _a7_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
        vader_obj_header_init(_a7_obj, 835u);
        _a7_obj->f_start = l5;
        _a7_obj->f_end = l6;
        l5 = (void*) _a7_obj;
        vader_struct_toolchain_ast$DestructureVar_t* _a8_obj = (vader_struct_toolchain_ast$DestructureVar_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$DestructureVar_t));
        vader_obj_header_init(_a8_obj, 762u);
        _a8_obj->f_pattern = l9;
        t1 = (void*) _a8_obj;
        vader_struct_toolchain_ast$InFor_t* _a9_obj = (vader_struct_toolchain_ast$InFor_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$InFor_t));
        vader_obj_header_init(_a9_obj, 785u);
        _a9_obj->f_loop_var = vader_ref_box(t1);
        _a9_obj->f_iter = l12;
        l6 = (void*) _a9_obj;
        vader_struct_toolchain_ast$ForStmt_t* _a10_obj = (vader_struct_toolchain_ast$ForStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$ForStmt_t));
        vader_obj_header_init(_a10_obj, 776u);
        _a10_obj->f_span = l5;
        _a10_obj->f_id = INT64_C(0);
        _a10_obj->f_label = l1;
        _a10_obj->f_form = vader_ref_box(l6);
        _a10_obj->f_body = l4;
        _a10_obj->f_is_comptime = l2;
        t1 = (void*) _a10_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l9 = vader_front_parser$parse_expr(l0, INT32_C(0));
    ((vader_struct_vader_front_parser$Parser_t*) l0)->f_no_struct_lit_at = l7;
    l4 = vader_front_parser$parse_block(l0);
    if (!(l9.tag == 806u)) {
        l10 = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_front_lexer$Token_t*) l3)->f_span)->f_start;
        l13 = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_toolchain_ast$BlockExpr_t*) l4)->f_span)->f_end;
        vader_struct_toolchain_span$Span_t* _a11_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
        vader_obj_header_init(_a11_obj, 835u);
        _a11_obj->f_start = l10;
        _a11_obj->f_end = l13;
        l10 = (void*) _a11_obj;
        vader_struct_toolchain_ast$WhileFor_t* _a12_obj = (vader_struct_toolchain_ast$WhileFor_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$WhileFor_t));
        vader_obj_header_init(_a12_obj, 828u);
        _a12_obj->f_cond = l9;
        l13 = (void*) _a12_obj;
        vader_struct_toolchain_ast$ForStmt_t* _a13_obj = (vader_struct_toolchain_ast$ForStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$ForStmt_t));
        vader_obj_header_init(_a13_obj, 776u);
        _a13_obj->f_span = l10;
        _a13_obj->f_id = INT64_C(0);
        _a13_obj->f_label = l1;
        _a13_obj->f_form = vader_ref_box(l13);
        _a13_obj->f_body = l4;
        _a13_obj->f_is_comptime = l2;
        t1 = (void*) _a13_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_front_lexer$Token_t*) l3)->f_span)->f_start;
    l5 = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_toolchain_ast$BlockExpr_t*) l4)->f_span)->f_end;
    vader_struct_toolchain_span$Span_t* _a14_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
    vader_obj_header_init(_a14_obj, 835u);
    _a14_obj->f_start = l3;
    _a14_obj->f_end = l5;
    l3 = (void*) _a14_obj;
    t1 = (void*) &vader_data_59;
    vader_array_t* _a15_slotarr = ((vader_array_t*) t1);
    VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
    l5 = vader_array_ref_load_obj(_a15_slotarr->buf, _a15_slotarr->offset + (size_t) INT64_C(0));
    l6 = l9.payload.obj;
    vader_struct_toolchain_ast$InFor_t* _a16_obj = (vader_struct_toolchain_ast$InFor_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$InFor_t));
    vader_obj_header_init(_a16_obj, 785u);
    _a16_obj->f_loop_var = vader_ref_box(l5);
    _a16_obj->f_iter = vader_ref_box(l6);
    l5 = (void*) _a16_obj;
    vader_struct_toolchain_ast$ForStmt_t* _a17_obj = (vader_struct_toolchain_ast$ForStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$ForStmt_t));
    vader_obj_header_init(_a17_obj, 776u);
    _a17_obj->f_span = l3;
    _a17_obj->f_id = INT64_C(0);
    _a17_obj->f_label = l1;
    _a17_obj->f_form = vader_ref_box(l5);
    _a17_obj->f_body = l4;
    _a17_obj->f_is_comptime = l2;
    t1 = (void*) _a17_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_parser$parse_generic_use(void* l0, vader_box_t l1) {
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
    vader_front_parser$advance(l0);
    l2 = vader_front_parser$parse_type_list_until_angle(l0);
    t0 = vader_front_parser$check(l0, (uint8_t) 79);
    if (t0) {
        vader_front_parser$advance(l0);
        l3 = vader_front_parser$parse_call_args(l0);
        l4 = vader_front_parser$expect(l0, (uint8_t) 80, 1275u);
        l5 = ((vader_struct_toolchain_span$Span_t*) VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l1.payload.obj))->f_start;
        l4 = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_front_lexer$Token_t*) l4)->f_span)->f_end;
        vader_struct_toolchain_span$Span_t* _a0_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
        vader_obj_header_init(_a0_obj, 835u);
        _a0_obj->f_start = l5;
        _a0_obj->f_end = l4;
        l4 = (void*) _a0_obj;
        l5 = ((vader_struct_vader_front_parser$CommaList__toolchain_ast_CallArg_t*) l3)->f_items;
        l6 = ((vader_struct_vader_front_parser$CommaList__toolchain_ast_CallArg_t*) l3)->f_trailing_comma;
        vader_struct_toolchain_ast$CallExpr_t* _a1_obj = (vader_struct_toolchain_ast$CallExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$CallExpr_t));
        vader_obj_header_init(_a1_obj, 751u);
        _a1_obj->f_span = l4;
        _a1_obj->f_id = INT64_C(0);
        _a1_obj->f_callee = l1;
        _a1_obj->f_type_args = l2;
        _a1_obj->f_args = l5;
        _a1_obj->f_trailing_comma = l6;
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((vader_struct_toolchain_span$Span_t*) VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l1.payload.obj))->f_start;
    t1 = vader_front_parser$peek_at(l0, INT32_C(-1));
    l4 = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_front_lexer$Token_t*) t1)->f_span)->f_end;
    vader_struct_toolchain_span$Span_t* _a2_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
    vader_obj_header_init(_a2_obj, 835u);
    _a2_obj->f_start = l3;
    _a2_obj->f_end = l4;
    t1 = (void*) _a2_obj;
    vader_struct_toolchain_ast$GenericInstExpr_t* _a3_obj = (vader_struct_toolchain_ast$GenericInstExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$GenericInstExpr_t));
    vader_obj_header_init(_a3_obj, 777u);
    _a3_obj->f_span = t1;
    _a3_obj->f_id = INT64_C(0);
    _a3_obj->f_callee = l1;
    _a3_obj->f_type_args = l2;
    l2 = (void*) _a3_obj;
    t0 = vader_front_parser$allows_struct_lit(l0);
    if (t0) {
        t0 = vader_front_parser$check(l0, (uint8_t) 83);
        if (t0) {
            vader_front_parser$advance(l0);
            l3 = vader_front_parser$parse_struct_lit_fields(l0);
            l4 = vader_front_parser$expect(l0, (uint8_t) 84, 1410u);
            l5 = ((vader_struct_toolchain_span$Span_t*) VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l1.payload.obj))->f_start;
            l4 = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_front_lexer$Token_t*) l4)->f_span)->f_end;
            vader_struct_toolchain_span$Span_t* _a4_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
            vader_obj_header_init(_a4_obj, 835u);
            _a4_obj->f_start = l5;
            _a4_obj->f_end = l4;
            l4 = (void*) _a4_obj;
            l5 = ((vader_struct_vader_front_parser$CommaList__toolchain_ast_StructLitField___toolchain_ast_StructLitSpread_t*) l3)->f_items;
            l6 = ((vader_struct_vader_front_parser$CommaList__toolchain_ast_StructLitField___toolchain_ast_StructLitSpread_t*) l3)->f_trailing_comma;
            vader_struct_toolchain_ast$StructLitExpr_t* _a5_obj = (vader_struct_toolchain_ast$StructLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$StructLitExpr_t));
            vader_obj_header_init(_a5_obj, 818u);
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

static vader_box_t vader_front_parser$parse_ident_or_struct_lit(void* l0) {
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
    l1 = vader_front_parser$advance(l0);
    l2 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_pos;
    t0 = vader_front_parser$scan_angle_generic(l0, l2);
    if (t0) {
        l3 = ((vader_struct_vader_front_lexer$Token_t*) l1)->f_span;
        l4 = ((vader_struct_vader_front_lexer$Token_t*) l1)->f_text;
        l3 = vader_front_parser$ident_expr(l3, l4);
        t1 = vader_front_parser$parse_generic_use(l0, vader_ref_box(l3));
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_front_parser$allows_struct_lit(l0);
    if (t0) {
        t0 = vader_front_parser$check(l0, (uint8_t) 83);
        if (t0) {
            l3 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_tokens;
            l2 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_pos;
            t0 = vader_front_parser$looks_like_struct_lit_body(l3, l2);
            if (t0) {
                vader_front_parser$advance(l0);
                l3 = vader_front_parser$parse_struct_lit_fields(l0);
                l5 = vader_front_parser$expect(l0, (uint8_t) 84, 1410u);
                l5 = vader_front_parser$span_of(l0, l1, l5);
                l6 = ((vader_struct_vader_front_lexer$Token_t*) l1)->f_span;
                l4 = ((vader_struct_vader_front_lexer$Token_t*) l1)->f_text;
                l6 = vader_front_parser$ident_expr(l6, l4);
                l7 = ((vader_struct_vader_front_parser$CommaList__toolchain_ast_StructLitField___toolchain_ast_StructLitSpread_t*) l3)->f_items;
                l8 = ((vader_struct_vader_front_parser$CommaList__toolchain_ast_StructLitField___toolchain_ast_StructLitSpread_t*) l3)->f_trailing_comma;
                vader_struct_toolchain_ast$StructLitExpr_t* _a0_obj = (vader_struct_toolchain_ast$StructLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$StructLitExpr_t));
                vader_obj_header_init(_a0_obj, 818u);
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
    l3 = ((vader_struct_vader_front_lexer$Token_t*) l1)->f_span;
    l4 = ((vader_struct_vader_front_lexer$Token_t*) l1)->f_text;
    t2 = vader_front_parser$ident_expr(l3, l4);
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_parser$parse_if_expr(void* l0) {
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
    l1 = vader_front_parser$advance(l0);
    l2 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_no_struct_lit_at;
    l3 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_bracket_depth;
    ((vader_struct_vader_front_parser$Parser_t*) l0)->f_no_struct_lit_at = l3;
    l4 = vader_front_parser$parse_expr(l0, INT32_C(0));
    ((vader_struct_vader_front_parser$Parser_t*) l0)->f_no_struct_lit_at = l2;
    l5 = vader_front_parser$parse_block(l0);
    l6 = vader_box_obj(0u, NULL);
    vader_front_parser$skip_newlines(l0);
    t0 = vader_front_parser$match_kind(l0, (uint8_t) 17);
    if (!(t0.tag == 0u)) {
        vader_front_parser$skip_newlines(l0);
        t1 = vader_front_parser$check(l0, (uint8_t) 16);
        if (t1) {
            t2 = vader_front_parser$parse_if_expr(l0);
            vader_struct_toolchain_ast$IfElseIf_t* _a0_obj = (vader_struct_toolchain_ast$IfElseIf_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$IfElseIf_t));
            vader_obj_header_init(_a0_obj, 780u);
            _a0_obj->f_branch = t2;
            t2 = (void*) _a0_obj;
            l6 = vader_ref_box(t2);
        } else {
            t2 = vader_front_parser$parse_block(l0);
            vader_struct_toolchain_ast$IfElseBlock_t* _a1_obj = (vader_struct_toolchain_ast$IfElseBlock_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$IfElseBlock_t));
            vader_obj_header_init(_a1_obj, 779u);
            _a1_obj->f_block = t2;
            t2 = (void*) _a1_obj;
            l6 = vader_ref_box(t2);
        }
    }
    if (l6.tag == 780u) {
        t2 = l6.payload.obj;
        l7 = ((vader_struct_toolchain_ast$IfExpr_t*) ((vader_struct_toolchain_ast$IfElseIf_t*) t2)->f_branch)->f_span;
    } else if (l6.tag == 779u) {
        t2 = l6.payload.obj;
        l7 = ((vader_struct_toolchain_ast$BlockExpr_t*) ((vader_struct_toolchain_ast$IfElseBlock_t*) t2)->f_block)->f_span;
    } else {
        if (!(l6.tag == 0u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l7 = ((vader_struct_toolchain_ast$BlockExpr_t*) l5)->f_span;
    }
    l1 = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_front_lexer$Token_t*) l1)->f_span)->f_start;
    l7 = ((vader_struct_toolchain_span$Span_t*) l7)->f_end;
    vader_struct_toolchain_span$Span_t* _a2_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
    vader_obj_header_init(_a2_obj, 835u);
    _a2_obj->f_start = l1;
    _a2_obj->f_end = l7;
    t2 = (void*) _a2_obj;
    vader_struct_toolchain_ast$IfExpr_t* _a3_obj = (vader_struct_toolchain_ast$IfExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$IfExpr_t));
    vader_obj_header_init(_a3_obj, 781u);
    _a3_obj->f_span = t2;
    _a3_obj->f_id = INT64_C(0);
    _a3_obj->f_cond = l4;
    _a3_obj->f_then_block = l5;
    _a3_obj->f_else_branch = l6;
    t2 = (void*) _a3_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_parser$parse_impl_decl(void* l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l13 = NULL;
    vader_box_t l3 = vader_box_null(), l12 = vader_box_null();
    bool l7, l11;
    vader_string_t l14 = 0;
    bool t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[3] = { &l3, &l12, &t1 };
    void** gc_raw_roots[11] = { &l0, &l1, &l2, &l4, &l5, &l6, &l8, &l9, &l10, &l13, &t2 };
    vader_string_t* gc_atom_roots[1] = { &l14 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 11u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_front_parser$reject_free_fn_decorators(l0, l1, 1520u, 0u);
    l2 = vader_front_parser$peek(l0);
    l3 = vader_front_parser$parse_type(l0);
    vader_front_parser$expect(l0, (uint8_t) 14, 1385u);
    vader_array_t* _a0_arr = vader_array_new(59u, 0u, 13u, 826u);
    l4 = (void*) _a0_arr;
    t0 = vader_front_parser$check(l0, (uint8_t) 52);
    if (t0) {
        l4 = vader_front_parser$parse_angle_type_params(l0);
    }
    l5 = vader_front_parser$expect(l0, (uint8_t) 2, 2740u);
    vader_array_t* _a1_arr = vader_array_new(349u, 0u, 13u, 1716u);
    l6 = (void*) _a1_arr;
    t1 = vader_front_parser$match_kind(l0, (uint8_t) 52);
    if (!(t1.tag == 0u)) {
        l6 = vader_front_parser$parse_type_list_until_angle(l0);
    }
    l7 = toolchain_ast$decorators_have(l1, 2190u);
    vader_array_t* _a2_arr = vader_array_new(47u, 0u, 13u, 773u);
    l8 = (void*) _a2_arr;
    l9 = l5;
    t0 = vader_front_parser$check(l0, (uint8_t) 76);
    if (t0) {
        l10 = vader_front_parser$parse_sam_arrow_member(l0);
        vader_array_push_ref((vader_array_t*) l8, l10);
        l9 = vader_front_parser$peek_at(l0, INT32_C(-1));
    } else {
        t0 = vader_front_parser$check(l0, (uint8_t) 83);
        if (t0) {
            l11 = vader_front_parser$peek_is_classic_impl_body(l0);
        } else {
            l11 = false;
        }
        if (l11) {
            vader_front_parser$advance(l0);
            vader_front_parser$skip_newlines(l0);
            for (;;) {
                t0 = vader_front_parser$check(l0, (uint8_t) 84);
                if (!(t0)) {
                    t0 = vader_front_parser$check(l0, (uint8_t) 0);
                    if (t0) break;
                    l12 = vader_front_parser$parse_fn_decl_inside_trait(l0);
                    if (l12.tag == 773u) {
                        t2 = l12.payload.obj;
                        l10 = ((vader_struct_toolchain_ast$FnDecl_t*) t2)->f_decorators;
                        vader_front_parser$reject_free_fn_decorators(l0, l10, 1531u, 0u);
                        l13 = l12.payload.obj;
                        vader_array_push_ref((vader_array_t*) l8, l13);
                    } else if (!(l12.tag == 0u)) {
                        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                    }
                    vader_front_parser$skip_newlines(l0);
                    continue;
                }
                break;
            }
            l9 = vader_front_parser$expect(l0, (uint8_t) 84, 1406u);
        } else {
            t0 = vader_front_parser$check(l0, (uint8_t) 83);
            if (t0) {
                l10 = vader_front_parser$parse_sam_block_member(l0);
                vader_array_push_ref((vader_array_t*) l8, l10);
                l9 = vader_front_parser$peek_at(l0, INT32_C(-1));
            } else if (l7) {
                l9 = vader_front_parser$peek_at(l0, INT32_C(-1));
            } else {
                l10 = vader_front_parser$peek(l0);
                l13 = ((vader_struct_vader_front_lexer$Token_t*) l10)->f_span;
                l14 = vader_front_parser$describe_token(l10);
                l14 = concat_3(1919u, l14, 324u);
                vader_front_parser$error(l0, (uint8_t) 4, l13, l14);
                l9 = l10;
            }
        }
    }
    l2 = vader_front_parser$span_of(l0, l2, l9);
    l14 = ((vader_struct_vader_front_lexer$Token_t*) l5)->f_text;
    l5 = ((vader_struct_vader_front_lexer$Token_t*) l5)->f_span;
    vader_struct_toolchain_ast$ImplDecl_t* _a3_obj = (vader_struct_toolchain_ast$ImplDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$ImplDecl_t));
    vader_obj_header_init(_a3_obj, 782u);
    _a3_obj->f_span = l2;
    _a3_obj->f_id = INT64_C(0);
    _a3_obj->f_type_params = l4;
    _a3_obj->f_for_type = l3;
    _a3_obj->f_trait_name = l14;
    _a3_obj->f_trait_name_span = l5;
    _a3_obj->f_trait_args = l6;
    _a3_obj->f_members = l8;
    _a3_obj->f_decorators = l1;
    _a3_obj->f_doc = vader_box_obj(0u, NULL);
    t2 = (void*) _a3_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_parser$parse_import_decl(void* l0, void* l1) {
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
    l2 = vader_front_parser$advance(l0);
    l3 = vader_front_parser$expect_string_literal(l0, 2142u);
    t0 = vader_front_parser$check(l0, (uint8_t) 29);
    if (t0) {
        l4 = vader_front_parser$peek(l0);
        l4 = ((vader_struct_vader_front_lexer$Token_t*) l4)->f_span;
        vader_front_parser$error(l0, (uint8_t) 4, l4, 2705u);
        vader_front_parser$advance(l0);
        t0 = vader_front_parser$check(l0, (uint8_t) 2);
        if (t0) {
            vader_front_parser$advance(l0);
        }
    }
    t1 = vader_front_parser$match_kind(l0, (uint8_t) 83);
    if (!(t1.tag == 0u)) {
        l4 = vader_front_parser$parse_import_name_list_rest(l0);
        l5 = vader_front_parser$peek_at(l0, INT32_C(-1));
        l5 = vader_front_parser$span_of(l0, l2, l5);
        l6 = ((vader_struct_vader_front_parser$StringLitInfo_t*) l3)->f_text;
        l7 = ((vader_struct_vader_front_parser$CommaList__toolchain_ast_ImportName_t*) l4)->f_items;
        l8 = ((vader_struct_vader_front_parser$CommaList__toolchain_ast_ImportName_t*) l4)->f_trailing_comma;
        vader_struct_toolchain_ast$DestructureImport_t* _a0_obj = (vader_struct_toolchain_ast$DestructureImport_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$DestructureImport_t));
        vader_obj_header_init(_a0_obj, 761u);
        _a0_obj->f_names = l7;
        _a0_obj->f_trailing_comma = l8;
        l4 = (void*) _a0_obj;
        vader_struct_toolchain_ast$ImportDecl_t* _a1_obj = (vader_struct_toolchain_ast$ImportDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$ImportDecl_t));
        vader_obj_header_init(_a1_obj, 783u);
        _a1_obj->f_span = l5;
        _a1_obj->f_id = INT64_C(0);
        _a1_obj->f_path = l6;
        _a1_obj->f_binding = vader_ref_box(l4);
        _a1_obj->f_decorators = l1;
        t2 = (void*) _a1_obj;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = vader_front_parser$peek_at(l0, INT32_C(-1));
    l2 = vader_front_parser$span_of(l0, l2, l4);
    l6 = ((vader_struct_vader_front_parser$StringLitInfo_t*) l3)->f_text;
    t2 = (void*) &vader_data_76;
    vader_array_t* _a2_slotarr = ((vader_array_t*) t2);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    l3 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT64_C(0));
    vader_struct_toolchain_ast$ImportDecl_t* _a3_obj = (vader_struct_toolchain_ast$ImportDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$ImportDecl_t));
    vader_obj_header_init(_a3_obj, 783u);
    _a3_obj->f_span = l2;
    _a3_obj->f_id = INT64_C(0);
    _a3_obj->f_path = l6;
    _a3_obj->f_binding = vader_ref_box(l3);
    _a3_obj->f_decorators = l1;
    t2 = (void*) _a3_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_parser$parse_import_name_list_rest(void* l0) {
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
    vader_array_t* _a0_arr = vader_array_new(49u, 0u, 13u, 784u);
    l1 = (void*) _a0_arr;
    l2 = false;
    vader_front_parser$skip_newlines(l0);
    t0 = vader_front_parser$check(l0, (uint8_t) 84);
    if (!(t0)) {
        l3 = true;
        for (;;) {
            if (!(l3)) {
                t1 = vader_front_parser$match_kind(l0, (uint8_t) 85);
                if (t1.tag == 0u) break;
            }
            l3 = false;
            vader_front_parser$skip_newlines(l0);
            t0 = vader_front_parser$check(l0, (uint8_t) 84);
            if (t0) {
                l2 = true;
                break;
            }
            l4 = vader_front_parser$expect(l0, (uint8_t) 2, 2145u);
            l5 = vader_box_obj(0u, NULL);
            t1 = vader_front_parser$match_kind(l0, (uint8_t) 29);
            if (!(t1.tag == 0u)) {
                t2 = vader_front_parser$expect(l0, (uint8_t) 2, 1513u);
                t3 = ((vader_struct_vader_front_lexer$Token_t*) t2)->f_text;
                l5 = vader_box_string(447u, t3);
            }
            l6 = ((vader_struct_vader_front_lexer$Token_t*) l4)->f_text;
            l7 = vader_front_parser$peek_at(l0, INT32_C(-1));
            l8 = vader_front_parser$span_of(l0, l4, l7);
            vader_struct_toolchain_ast$ImportName_t* _a1_obj = (vader_struct_toolchain_ast$ImportName_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$ImportName_t));
            vader_obj_header_init(_a1_obj, 784u);
            _a1_obj->f_name = l6;
            _a1_obj->f_alias = l5;
            _a1_obj->f_span = l8;
            _a1_obj->f_id = INT64_C(0);
            l9 = (void*) _a1_obj;
            vader_array_push_ref((vader_array_t*) l1, l9);
            vader_front_parser$skip_newlines(l0);
            continue;
        }
    }
    vader_front_parser$skip_newlines(l0);
    vader_front_parser$expect(l0, (uint8_t) 84, 1407u);
    vader_struct_vader_front_parser$CommaList__Any_t* _a2_obj = (vader_struct_vader_front_parser$CommaList__Any_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_parser$CommaList__Any_t));
    vader_obj_header_init(_a2_obj, 1192u);
    _a2_obj->f_items = l1;
    _a2_obj->f_trailing_comma = l2;
    t2 = (void*) _a2_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_parser$parse_lambda(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l7 = NULL;
    vader_box_t l3 = vader_box_null(), l6 = vader_box_null();
    bool l8, l9;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[3] = { &l3, &l6, &t0 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l4, &l5, &l7, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_front_parser$advance(l0);
    l2 = vader_front_parser$parse_fn_signature_params(l0);
    l3 = vader_box_obj(0u, NULL);
    t0 = vader_front_parser$match_kind(l0, (uint8_t) 76);
    if (!(t0.tag == 0u)) {
        l3 = vader_front_parser$parse_type(l0);
    }
    l4 = vader_front_parser$parse_fn_body_tail(l0);
    l6 = ((vader_struct_vader_front_parser$FnBodyTail_t*) l4)->f_body;
    if (l6.tag == 0u) {
        l5 = vader_front_parser$parse_block(l0);
    } else {
        l5 = l6.payload.obj;
    }
    l1 = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_front_lexer$Token_t*) l1)->f_span)->f_start;
    l7 = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_toolchain_ast$BlockExpr_t*) l5)->f_span)->f_end;
    vader_struct_toolchain_span$Span_t* _a0_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
    vader_obj_header_init(_a0_obj, 835u);
    _a0_obj->f_start = l1;
    _a0_obj->f_end = l7;
    l1 = (void*) _a0_obj;
    l7 = ((vader_struct_vader_front_parser$FnSignature_t*) l2)->f_params;
    l8 = ((vader_struct_vader_front_parser$FnSignature_t*) l2)->f_trailing_comma;
    l9 = ((vader_struct_vader_front_parser$FnBodyTail_t*) l4)->f_is_expression_bodied;
    vader_struct_toolchain_ast$LambdaExpr_t* _a1_obj = (vader_struct_toolchain_ast$LambdaExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$LambdaExpr_t));
    vader_obj_header_init(_a1_obj, 791u);
    _a1_obj->f_span = l1;
    _a1_obj->f_id = INT64_C(0);
    _a1_obj->f_params = l7;
    _a1_obj->f_return_type = l3;
    _a1_obj->f_body = l5;
    _a1_obj->f_trailing_comma = l8;
    _a1_obj->f_is_expression_bodied = l9;
    t1 = (void*) _a1_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_parser$parse_lambda_without_fn(void* l0) {
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
    l1 = vader_front_parser$peek(l0);
    l2 = vader_front_parser$parse_fn_signature_params(l0);
    vader_front_parser$expect(l0, (uint8_t) 76, 1302u);
    t0 = vader_front_parser$parse_expr(l0, INT32_C(0));
    l3 = vader_front_parser$wrap_as_block(t0);
    l1 = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_front_lexer$Token_t*) l1)->f_span)->f_start;
    l4 = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_toolchain_ast$BlockExpr_t*) l3)->f_span)->f_end;
    vader_struct_toolchain_span$Span_t* _a0_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
    vader_obj_header_init(_a0_obj, 835u);
    _a0_obj->f_start = l1;
    _a0_obj->f_end = l4;
    l1 = (void*) _a0_obj;
    l4 = ((vader_struct_vader_front_parser$FnSignature_t*) l2)->f_params;
    l5 = ((vader_struct_vader_front_parser$FnSignature_t*) l2)->f_trailing_comma;
    vader_struct_toolchain_ast$LambdaExpr_t* _a1_obj = (vader_struct_toolchain_ast$LambdaExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$LambdaExpr_t));
    vader_obj_header_init(_a1_obj, 791u);
    _a1_obj->f_span = l1;
    _a1_obj->f_id = INT64_C(0);
    _a1_obj->f_params = l4;
    _a1_obj->f_return_type = vader_box_obj(0u, NULL);
    _a1_obj->f_body = l3;
    _a1_obj->f_trailing_comma = l5;
    _a1_obj->f_is_expression_bodied = false;
    t1 = (void*) _a1_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_parser$parse_let(void* l0) {
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
    l1 = vader_front_parser$advance(l0);
    t0 = vader_front_parser$advance(l0);
    l2 = ((vader_struct_vader_front_lexer$Token_t*) t0)->f_kind == INT32_C(72);
    l3 = vader_front_parser$parse_expr(l0, INT32_C(0));
    l4 = ((vader_struct_vader_front_lexer$Token_t*) l1)->f_span;
    l5 = ((vader_struct_vader_front_lexer$Token_t*) l1)->f_text;
    l6 = ((vader_struct_vader_front_lexer$Token_t*) l1)->f_span;
    vader_struct_toolchain_ast$SimpleBinding_t* _a0_obj = (vader_struct_toolchain_ast$SimpleBinding_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$SimpleBinding_t));
    vader_obj_header_init(_a0_obj, 812u);
    _a0_obj->f_span = l4;
    _a0_obj->f_id = INT64_C(0);
    _a0_obj->f_name = l5;
    _a0_obj->f_name_span = l6;
    l4 = (void*) _a0_obj;
    l6 = vader_front_parser$peek_at(l0, INT32_C(-1));
    t0 = vader_front_parser$span_of(l0, l1, l6);
    vader_struct_toolchain_ast$LetStmt_t* _a1_obj = (vader_struct_toolchain_ast$LetStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$LetStmt_t));
    vader_obj_header_init(_a1_obj, 792u);
    _a1_obj->f_span = t0;
    _a1_obj->f_id = INT64_C(0);
    _a1_obj->f_mutable = l2;
    _a1_obj->f_binding = vader_ref_box(l4);
    _a1_obj->f_ty = vader_box_obj(0u, NULL);
    _a1_obj->f_value = l3;
    t0 = (void*) _a1_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_parser$parse_let_binding(void* l0) {
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
    t0 = vader_front_parser$check(l0, (uint8_t) 81);
    if (t0) {
        l1 = vader_front_parser$advance(l0);
        vader_front_parser$skip_newlines(l0);
        vader_array_t* _a0_arr = vader_array_new(355u, 0u, 13u, 1797u);
        l2 = (void*) _a0_arr;
        t0 = vader_front_parser$check(l0, (uint8_t) 82);
        if (!(t0)) {
            for (;;) {
                vader_front_parser$skip_newlines(l0);
                t0 = vader_front_parser$check(l0, (uint8_t) 82);
                if (!(t0)) {
                    l3 = vader_front_parser$peek(l0);
                    t1 = vader_front_parser$match_kind(l0, (uint8_t) 75);
                    if (t1.tag == 0u) {
                        l9 = vader_front_parser$parse_let_binding(l0);
                        vader_array_push_ref((vader_array_t*) l2, l9.payload.obj);
                    } else {
                        l4 = vader_front_parser$expect(l0, (uint8_t) 2, 2364u);
                        l5 = vader_front_parser$span_of(l0, l3, l4);
                        l6 = ((vader_struct_vader_front_lexer$Token_t*) l4)->f_text;
                        l7 = ((vader_struct_vader_front_lexer$Token_t*) l4)->f_span;
                        vader_struct_toolchain_ast$RestBinding_t* _a1_obj = (vader_struct_toolchain_ast$RestBinding_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$RestBinding_t));
                        vader_obj_header_init(_a1_obj, 808u);
                        _a1_obj->f_span = l5;
                        _a1_obj->f_id = INT64_C(0);
                        _a1_obj->f_name = l6;
                        _a1_obj->f_name_span = l7;
                        l8 = (void*) _a1_obj;
                        vader_array_push_ref((vader_array_t*) l2, l8);
                    }
                    vader_front_parser$skip_newlines(l0);
                    t1 = vader_front_parser$match_kind(l0, (uint8_t) 85);
                    if (t1.tag == 0u) break;
                    vader_front_parser$skip_newlines(l0);
                    continue;
                }
                break;
            }
        }
        l3 = vader_front_parser$expect(l0, (uint8_t) 82, 1371u);
        t2 = ((vader_array_t*) l2)->length;
        if ((t2 < INT64_C(2))) {
            l4 = vader_front_parser$span_of(l0, l1, l3);
            vader_front_parser$error(l0, (uint8_t) 12, l4, 1442u);
        }
        l10 = INT64_C(1);
        l11 = ((vader_array_t*) l2)->length;
        while ((l10 < l11)) {
            l12 = vader_chk_sub(i64, l10, INT64_C(1));
            vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            l9 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l12);
            if (l9.tag == 808u) {
                t3 = l9.payload.obj;
                l4 = ((vader_struct_toolchain_ast$RestBinding_t*) t3)->f_span;
                vader_front_parser$error(l0, (uint8_t) 21, l4, 0u);
            }
            l10 = (l10 + INT64_C(1));
        }
        t3 = vader_front_parser$span_of(l0, l1, l3);
        vader_struct_toolchain_ast$TupleBinding_t* _a3_obj = (vader_struct_toolchain_ast$TupleBinding_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$TupleBinding_t));
        vader_obj_header_init(_a3_obj, 824u);
        _a3_obj->f_span = t3;
        _a3_obj->f_id = INT64_C(0);
        _a3_obj->f_elements = l2;
        t3 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_front_parser$check(l0, (uint8_t) 2);
    if (t0) {
        t3 = vader_front_parser$peek(l0);
        t4 = ((vader_struct_vader_front_lexer$Token_t*) t3)->f_text;
        if (t4 == 976u) {
            t3 = vader_front_parser$advance(l0);
            vader_struct_toolchain_ast$WildcardBinding_t* _a4_obj = (vader_struct_toolchain_ast$WildcardBinding_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$WildcardBinding_t));
            vader_obj_header_init(_a4_obj, 829u);
            _a4_obj->f_span = ((vader_struct_vader_front_lexer$Token_t*) t3)->f_span;
            _a4_obj->f_id = INT64_C(0);
            t3 = (void*) _a4_obj;
            { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l1 = vader_front_parser$expect(l0, (uint8_t) 2, 1625u);
    l2 = ((vader_struct_vader_front_lexer$Token_t*) l1)->f_span;
    l6 = ((vader_struct_vader_front_lexer$Token_t*) l1)->f_text;
    l1 = ((vader_struct_vader_front_lexer$Token_t*) l1)->f_span;
    vader_struct_toolchain_ast$SimpleBinding_t* _a5_obj = (vader_struct_toolchain_ast$SimpleBinding_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$SimpleBinding_t));
    vader_obj_header_init(_a5_obj, 812u);
    _a5_obj->f_span = l2;
    _a5_obj->f_id = INT64_C(0);
    _a5_obj->f_name = l6;
    _a5_obj->f_name_span = l1;
    t3 = (void*) _a5_obj;
    { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_parser$parse_lexed(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    vader_string_t l2 = 0;
    void* t0 = NULL;
    void** gc_raw_roots[6] = { &l0, &l1, &l3, &l4, &l5, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_front_lexer$LexedSource_t*) l0)->f_tokens;
    l2 = ((vader_struct_vader_front_lexer$LexedSource_t*) l0)->f_file;
    l3 = ((vader_struct_vader_front_lexer$LexedSource_t*) l0)->f_errors;
    vader_array_t* _a0_arr = vader_array_new(350u, 0u, 13u, 1745u);
    l4 = (void*) _a0_arr;
    l5 = ((vader_struct_vader_front_lexer$LexedSource_t*) l0)->f_doc_runs;
    vader_struct_vader_front_parser$Parser_t* _a1_obj = (vader_struct_vader_front_parser$Parser_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_parser$Parser_t));
    vader_obj_header_init(_a1_obj, 1205u);
    _a1_obj->f_tokens = l1;
    _a1_obj->f_file = l2;
    _a1_obj->f_pos = INT32_C(0);
    _a1_obj->f_errors = l3;
    _a1_obj->f_bracket_depth = INT32_C(0);
    _a1_obj->f_no_struct_lit_at = INT32_C(-1);
    _a1_obj->f_no_bare_lambda_at = INT32_C(-1);
    _a1_obj->f_shr_pending_half = vader_box_obj(0u, NULL);
    _a1_obj->f_split_half = vader_box_obj(0u, NULL);
    _a1_obj->f_split_at = INT32_C(-1);
    _a1_obj->f_pending_decls = l4;
    _a1_obj->f_expr_depth = INT32_C(0);
    _a1_obj->f_depth_exceeded = false;
    _a1_obj->f_doc_runs = l5;
    _a1_obj->f_doc_cursor = INT64_C(0);
    l1 = (void*) _a1_obj;
    l3 = vader_front_parser$parse_program(l1);
    l4 = vader_front_parser$new_node_id_factory();
    vader_front_parser$assign_program_ids(l3, l4);
    l4 = ((vader_struct_vader_front_lexer$LexedSource_t*) l0)->f_tokens;
    l1 = ((vader_struct_vader_front_parser$Parser_t*) l1)->f_errors;
    vader_struct_vader_front_parser$ParsedSource_t* _a2_obj = (vader_struct_vader_front_parser$ParsedSource_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_parser$ParsedSource_t));
    vader_obj_header_init(_a2_obj, 1204u);
    _a2_obj->f_program = l3;
    _a2_obj->f_tokens = l4;
    _a2_obj->f_errors = l1;
    t0 = (void*) _a2_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_parser$parse_lhs_generic_alias_decl(void* l0, void* l1, uint8_t l2) {
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
    l3 = vader_front_parser$advance(l0);
    l4 = vader_front_parser$parse_angle_type_params(l0);
    vader_front_parser$advance(l0);
    l5 = vader_front_parser$parse_expr(l0, INT32_C(0));
    l6 = vader_front_parser$peek_at(l0, INT32_C(-1));
    l6 = vader_front_parser$span_of(l0, l3, l6);
    l7 = ((vader_struct_vader_front_lexer$Token_t*) l3)->f_text;
    l3 = ((vader_struct_vader_front_lexer$Token_t*) l3)->f_span;
    vader_struct_toolchain_ast$TypeAliasDecl_t* _a0_obj = (vader_struct_toolchain_ast$TypeAliasDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$TypeAliasDecl_t));
    vader_obj_header_init(_a0_obj, 825u);
    _a0_obj->f_span = l6;
    _a0_obj->f_id = INT64_C(0);
    _a0_obj->f_name = l7;
    _a0_obj->f_name_span = l3;
    _a0_obj->f_visibility = l2;
    _a0_obj->f_type_params = l4;
    _a0_obj->f_aliased = l5;
    _a0_obj->f_decorators = l1;
    _a0_obj->f_doc = vader_box_obj(0u, NULL);
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_parser$parse_match_arm(void* l0) {
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
    l1 = vader_front_parser$peek(l0);
    l2 = vader_front_parser$parse_pattern(l0);
    l3 = l2;
    t0 = vader_front_parser$check(l0, (uint8_t) 45);
    if (t0) {
        vader_array_t* _a0_arr = vader_array_new(353u, 1u, 13u, 1776u);
        ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l2.payload.obj;
        l4 = (void*) _a0_arr;
        for (;;) {
            t1 = vader_front_parser$match_kind(l0, (uint8_t) 45);
            if (!(t1.tag == 0u)) {
                vader_front_parser$skip_newlines(l0);
                l2 = vader_front_parser$parse_pattern(l0);
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
            vader_front_parser$reject_alternative_bindings(l0, l2);
            l7 = (l7 + INT64_C(1));
        }
        l5 = vader_front_parser$peek_at(l0, INT32_C(-1));
        t2 = vader_front_parser$span_of(l0, l1, l5);
        vader_struct_toolchain_ast$OrPattern_t* _a2_obj = (vader_struct_toolchain_ast$OrPattern_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$OrPattern_t));
        vader_obj_header_init(_a2_obj, 801u);
        _a2_obj->f_span = t2;
        _a2_obj->f_id = INT64_C(0);
        _a2_obj->f_patterns = l4;
        t2 = (void*) _a2_obj;
        l3 = vader_ref_box(t2);
    }
    l2 = vader_box_obj(0u, NULL);
    t1 = vader_front_parser$match_kind(l0, (uint8_t) 16);
    if (!(t1.tag == 0u)) {
        l8 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_no_bare_lambda_at;
        l9 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_bracket_depth;
        ((vader_struct_vader_front_parser$Parser_t*) l0)->f_no_bare_lambda_at = l9;
        l2 = vader_front_parser$parse_expr(l0, INT32_C(0));
        ((vader_struct_vader_front_parser$Parser_t*) l0)->f_no_bare_lambda_at = l8;
    }
    vader_front_parser$expect(l0, (uint8_t) 76, 1303u);
    l10 = vader_front_parser$parse_expr(l0, INT32_C(0));
    l1 = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_front_lexer$Token_t*) l1)->f_span)->f_start;
    l4 = ((vader_struct_toolchain_span$Span_t*) VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l10.payload.obj))->f_end;
    vader_struct_toolchain_span$Span_t* _a3_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
    vader_obj_header_init(_a3_obj, 835u);
    _a3_obj->f_start = l1;
    _a3_obj->f_end = l4;
    t2 = (void*) _a3_obj;
    vader_struct_toolchain_ast$MatchArm_t* _a4_obj = (vader_struct_toolchain_ast$MatchArm_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$MatchArm_t));
    vader_obj_header_init(_a4_obj, 794u);
    _a4_obj->f_span = t2;
    _a4_obj->f_id = INT64_C(0);
    _a4_obj->f_pattern = l3;
    _a4_obj->f_guard = l2;
    _a4_obj->f_body = l10;
    t2 = (void*) _a4_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_parser$parse_match_declaration(void* l0) {
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
    t0 = vader_front_parser$starts_let(l0);
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l1 = vader_front_parser$parse_any_let(l0);
    l2 = ((vader_struct_toolchain_ast$LetStmt_t*) l1)->f_binding;
    if (l2.tag == 812u) {
        t0 = ((vader_struct_toolchain_ast$LetStmt_t*) l1)->f_mutable;
        if (t0) {
            l3 = ((vader_struct_toolchain_ast$LetStmt_t*) l1)->f_span;
            t1 = l2.payload.obj;
            l4 = ((vader_struct_toolchain_ast$SimpleBinding_t*) t1)->f_name;
            l4 = concat_3(3037u, l4, 69u);
            vader_front_parser$error(l0, (uint8_t) 22, l3, l4);
        } else if (!(((vader_struct_toolchain_ast$LetStmt_t*) l1)->f_ty.tag == 0u)) {
            l5 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, ((vader_struct_toolchain_ast$LetStmt_t*) l1)->f_ty.payload.obj);
            t1 = l2.payload.obj;
            l4 = ((vader_struct_toolchain_ast$SimpleBinding_t*) t1)->f_name;
            l4 = concat_3(1848u, l4, 69u);
            vader_front_parser$error(l0, (uint8_t) 22, l5, l4);
        }
        { vader_box_t __vret = vader_ref_box(l1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((vader_struct_toolchain_ast$LetStmt_t*) l1)->f_span;
    vader_front_parser$error(l0, (uint8_t) 22, l3, 1621u);
    { vader_box_t __vret = vader_ref_box(l1); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_parser$parse_match_expr(void* l0, bool l1, bool l2, void* l3) {
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
    vader_front_parser$advance(l0);
    l4 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_no_struct_lit_at;
    l5 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_bracket_depth;
    ((vader_struct_vader_front_parser$Parser_t*) l0)->f_no_struct_lit_at = l5;
    l6 = vader_front_parser$parse_match_declaration(l0);
    l7 = vader_front_parser$match_scrutinee(l0, l6);
    ((vader_struct_vader_front_parser$Parser_t*) l0)->f_no_struct_lit_at = l4;
    l8 = (void*) &vader_fn_static___lambda_vader_front_parser_4;
    vader_front_parser$reject_as_binder(l0, (uint8_t) 22, l8);
    vader_front_parser$expect(l0, (uint8_t) 83, 1400u);
    vader_front_parser$skip_newlines(l0);
    vader_array_t* _a0_arr = vader_array_new(52u, 0u, 13u, 794u);
    l8 = (void*) _a0_arr;
    for (;;) {
        t0 = vader_front_parser$check(l0, (uint8_t) 84);
        if (!(t0)) {
            t0 = vader_front_parser$check(l0, (uint8_t) 0);
            if (t0) break;
            l9 = vader_front_parser$parse_match_arm(l0);
            vader_array_push_ref((vader_array_t*) l8, l9);
            vader_front_parser$skip_newlines(l0);
            t1 = vader_front_parser$match_kind(l0, (uint8_t) 85);
            if (t1.tag == 0u) {
                continue;
            }
            vader_front_parser$skip_newlines(l0);
            continue;
        }
        break;
    }
    l9 = vader_front_parser$expect(l0, (uint8_t) 84, 1408u);
    l10 = ((vader_struct_toolchain_span$Span_t*) l3)->f_start;
    l9 = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_front_lexer$Token_t*) l9)->f_span)->f_end;
    vader_struct_toolchain_span$Span_t* _a1_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
    vader_obj_header_init(_a1_obj, 835u);
    _a1_obj->f_start = l10;
    _a1_obj->f_end = l9;
    l9 = (void*) _a1_obj;
    l6 = vader_front_parser$declared_binding(l6);
    vader_struct_toolchain_ast$MatchExpr_t* _a2_obj = (vader_struct_toolchain_ast$MatchExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$MatchExpr_t));
    vader_obj_header_init(_a2_obj, 795u);
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

vader_box_t vader_front_parser$parse_module_header(vader_string_t l0, vader_string_t l1) {
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
    l2 = vader_host_std_core$byte_len(l0);
    l3 = INT64_C(0);
    t0 = std_string$matches_at(l0, INT64_C(0), 3073u);
    if (t0) {
        l3 = INT64_C(3);
    }
    t0 = std_string$matches_at(l0, l3, 256u);
    if (t0) {
        l3 = vader_front_parser$skip_to_eol(l0, l3);
    }
    l4 = vader_front_parser$header_budget(l2);
    while ((l3 < l4)) {
        l5 = vader_host_std_core$byte_at(l0, l3);
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
        t0 = std_string$matches_at(l0, l3, 444u);
        if (t0) {
            l3 = vader_front_parser$skip_to_eol(l0, l3);
            continue;
        }
        t0 = std_string$matches_at(l0, l3, 442u);
        if (!(t0)) {
            break;
        }
        l9 = vader_chk_add(i64, l3, INT64_C(2));
        l3 = vader_front_parser$skip_block_comment(l0, l9);
    }
    t0 = std_string$matches_at(l0, l3, 2355u);
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l4 = vader_host_std_core$byte_len(2355u);
    l3 = vader_chk_add(i64, l3, l4);
    while ((l3 < l2)) {
        l5 = vader_host_std_core$byte_at(l0, l3);
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
    t0 = std_string$matches_at(l0, l3, 250u);
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l3 = vader_chk_add(i64, l3, INT64_C(1));
    l4 = l3;
    while ((l3 < l2)) {
        t1 = vader_host_std_core$byte_at(l0, l3);
        if (!(t1 != INT32_C(34))) {
            break;
        }
        l3 = vader_chk_add(i64, l3, INT64_C(1));
    }
    if (!((l3 >= l2))) {
        l10 = vader_host_std_core$byte_slice(l0, l4, l3);
        l11 = vader_front_lexer$empty_file_span(l1);
        vader_struct_vader_front_parser$ModuleHeader_t* _a0_obj = (vader_struct_vader_front_parser$ModuleHeader_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_parser$ModuleHeader_t));
        vader_obj_header_init(_a0_obj, 1202u);
        _a0_obj->f_name = l10;
        _a0_obj->f_name_span = l11;
        t2 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_front_parser$parse_named_decl(void* l0, void* l1, uint8_t l2) {
    void* l3 = NULL;
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_front_parser$advance(l0);
    vader_front_parser$advance(l0);
    t0 = vader_front_parser$check(l0, (uint8_t) 11);
    if (t0) {
        t1 = vader_front_parser$parse_fn_decl(l0, l1, l2, l3);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_front_parser$check(l0, (uint8_t) 12);
    if (t0) {
        t1 = vader_front_parser$parse_struct_decl(l0, l1, l2, l3);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_front_parser$check(l0, (uint8_t) 15);
    if (t0) {
        t1 = vader_front_parser$parse_enum_decl(l0, l1, l2, l3);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_front_parser$check(l0, (uint8_t) 13);
    if (t0) {
        t1 = vader_front_parser$parse_trait_decl(l0, l1, l2, l3);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_front_parser$check(l0, (uint8_t) 28);
    if (!(t0)) {
        t1 = vader_front_parser$parse_const_decl(l0, l1, l2, l3);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_front_parser$parse_named_import_decl(l0, l1, l3);
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_parser$parse_named_import_decl(void* l0, void* l1, void* l2) {
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
    vader_front_parser$advance(l0);
    l3 = vader_front_parser$expect_string_literal(l0, 2142u);
    l4 = vader_front_parser$match_kind(l0, (uint8_t) 83);
    if (!(l4.tag == 0u)) {
        t0 = l4.payload.obj;
        l5 = ((vader_struct_vader_front_lexer$Token_t*) t0)->f_span;
        vader_front_parser$error(l0, (uint8_t) 4, l5, 2722u);
        vader_front_parser$parse_import_name_list_rest(l0);
    }
    l5 = vader_front_parser$peek_at(l0, INT32_C(-1));
    l5 = vader_front_parser$span_of(l0, l2, l5);
    l6 = ((vader_struct_vader_front_parser$StringLitInfo_t*) l3)->f_text;
    t1 = ((vader_struct_vader_front_lexer$Token_t*) l2)->f_text;
    vader_struct_toolchain_ast$NamedNamespaceImport_t* _a0_obj = (vader_struct_toolchain_ast$NamedNamespaceImport_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$NamedNamespaceImport_t));
    vader_obj_header_init(_a0_obj, 797u);
    _a0_obj->f_name = t1;
    l3 = (void*) _a0_obj;
    vader_struct_toolchain_ast$ImportDecl_t* _a1_obj = (vader_struct_toolchain_ast$ImportDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$ImportDecl_t));
    vader_obj_header_init(_a1_obj, 783u);
    _a1_obj->f_span = l5;
    _a1_obj->f_id = INT64_C(0);
    _a1_obj->f_path = l6;
    _a1_obj->f_binding = vader_ref_box(l3);
    _a1_obj->f_decorators = l1;
    t0 = (void*) _a1_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_parser$parse_optional_module_decl(void* l0) {
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
    l1 = vader_front_parser$peek(l0);
    if (((vader_struct_vader_front_lexer$Token_t*) l1)->f_kind != INT32_C(2)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t0 = ((vader_struct_vader_front_lexer$Token_t*) l1)->f_text;
    if (t0 != 2355u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t1 = vader_front_parser$check_at(l0, (uint8_t) 6, INT32_C(1));
    if (!(t1)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l1 = vader_front_parser$advance(l0);
    l2 = vader_front_parser$expect_string_literal(l0, 2358u);
    t0 = ((vader_struct_vader_front_parser$StringLitInfo_t*) l2)->f_text;
    t1 = vader_front_parser$is_valid_module_name(t0);
    if (!(t1)) {
        l3 = ((vader_struct_vader_front_parser$StringLitInfo_t*) l2)->f_span;
        vader_front_parser$error(l0, (uint8_t) 14, l3, 0u);
    }
    l3 = vader_front_parser$peek_at(l0, INT32_C(-1));
    l1 = vader_front_parser$span_of(l0, l1, l3);
    l4 = ((vader_struct_vader_front_parser$StringLitInfo_t*) l2)->f_text;
    l2 = ((vader_struct_vader_front_parser$StringLitInfo_t*) l2)->f_span;
    vader_struct_toolchain_ast$ModuleDecl_t* _a0_obj = (vader_struct_toolchain_ast$ModuleDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$ModuleDecl_t));
    vader_obj_header_init(_a0_obj, 796u);
    _a0_obj->f_span = l1;
    _a0_obj->f_id = INT64_C(0);
    _a0_obj->f_name = l4;
    _a0_obj->f_name_span = l2;
    t2 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_parser$parse_paren(void* l0) {
    vader_box_t l1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_front_parser$advance(l0);
    vader_front_parser$skip_newlines(l0);
    l1 = vader_front_parser$parse_expr(l0, INT32_C(0));
    vader_front_parser$skip_newlines(l0);
    vader_front_parser$expect(l0, (uint8_t) 80, 1277u);
    { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_parser$parse_pattern(void* l0) {
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
    l1 = vader_front_parser$peek(l0);
    if (((vader_struct_vader_front_lexer$Token_t*) l1)->f_kind == INT32_C(86)) {
        vader_front_parser$advance(l0);
        l2 = vader_front_parser$expect(l0, (uint8_t) 2, 3000u);
        l3 = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_front_lexer$Token_t*) l1)->f_span)->f_start;
        l4 = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_front_lexer$Token_t*) l2)->f_span)->f_end;
        vader_struct_toolchain_span$Span_t* _a0_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
        vader_obj_header_init(_a0_obj, 835u);
        _a0_obj->f_start = l3;
        _a0_obj->f_end = l4;
        l3 = (void*) _a0_obj;
        l5 = ((vader_struct_vader_front_lexer$Token_t*) l2)->f_text;
        vader_struct_toolchain_ast$EnumVariantPattern_t* _a1_obj = (vader_struct_toolchain_ast$EnumVariantPattern_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$EnumVariantPattern_t));
        vader_obj_header_init(_a1_obj, 769u);
        _a1_obj->f_span = l3;
        _a1_obj->f_id = INT64_C(0);
        _a1_obj->f_variant = l5;
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_front_lexer$Token_t*) l1)->f_kind == INT32_C(19)) {
        vader_front_parser$advance(l0);
        t1 = vader_front_parser$check(l0, (uint8_t) 86);
        if (t1) {
            l2 = vader_front_parser$advance(l0);
            l3 = vader_front_parser$expect(l0, (uint8_t) 2, 3000u);
            l2 = vader_front_parser$span_of(l0, l2, l3);
            l5 = ((vader_struct_vader_front_lexer$Token_t*) l3)->f_text;
            vader_struct_toolchain_ast$IdentExpr_t* _a2_obj = (vader_struct_toolchain_ast$IdentExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$IdentExpr_t));
            vader_obj_header_init(_a2_obj, 778u);
            _a2_obj->f_span = l2;
            _a2_obj->f_id = INT64_C(0);
            _a2_obj->f_name = l5;
            _a2_obj->f_implicit_dot = true;
            t0 = (void*) _a2_obj;
            l6 = vader_ref_box(t0);
        } else {
            l6 = vader_front_parser$parse_type(l0);
        }
        l7 = vader_box_obj(0u, NULL);
        t1 = vader_front_parser$check(l0, (uint8_t) 83);
        if (t1) {
            t0 = vader_front_parser$parse_struct_pattern(l0);
            l7 = vader_ref_box(t0);
        }
        l2 = (void*) &vader_fn_static___lambda_vader_front_parser_5;
        vader_front_parser$reject_as_binder(l0, (uint8_t) 20, l2);
        l2 = vader_front_parser$peek_at(l0, INT32_C(-1));
        t0 = vader_front_parser$span_of(l0, l1, l2);
        vader_struct_toolchain_ast$IsPattern_t* _a3_obj = (vader_struct_toolchain_ast$IsPattern_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$IsPattern_t));
        vader_obj_header_init(_a3_obj, 790u);
        _a3_obj->f_span = t0;
        _a3_obj->f_id = INT64_C(0);
        _a3_obj->f_ty = l6;
        _a3_obj->f_inner = l7;
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_front_lexer$Token_t*) l1)->f_kind == INT32_C(2)) {
        t2 = ((vader_struct_vader_front_lexer$Token_t*) l1)->f_text;
        if (t2 == 976u) {
            vader_front_parser$advance(l0);
            vader_struct_toolchain_ast$WildcardPattern_t* _a4_obj = (vader_struct_toolchain_ast$WildcardPattern_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$WildcardPattern_t));
            vader_obj_header_init(_a4_obj, 831u);
            _a4_obj->f_span = ((vader_struct_vader_front_lexer$Token_t*) l1)->f_span;
            _a4_obj->f_id = INT64_C(0);
            t0 = (void*) _a4_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (((vader_struct_vader_front_lexer$Token_t*) l1)->f_kind == INT32_C(2)) {
        vader_front_parser$advance(l0);
        l2 = ((vader_struct_vader_front_lexer$Token_t*) l1)->f_span;
        l5 = ((vader_struct_vader_front_lexer$Token_t*) l1)->f_text;
        l5 = concat_3(3036u, l5, 69u);
        vader_front_parser$error(l0, (uint8_t) 20, l2, l5);
        vader_struct_toolchain_ast$WildcardPattern_t* _a5_obj = (vader_struct_toolchain_ast$WildcardPattern_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$WildcardPattern_t));
        vader_obj_header_init(_a5_obj, 831u);
        _a5_obj->f_span = ((vader_struct_vader_front_lexer$Token_t*) l1)->f_span;
        _a5_obj->f_id = INT64_C(0);
        t0 = (void*) _a5_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_front_lexer$Token_t*) l1)->f_kind == INT32_C(81)) {
        t0 = vader_front_parser$reject_tuple_pattern(l0);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_front_parser$is_literal_start(l1);
    if (!(t1)) {
        l4 = ((vader_struct_vader_front_lexer$Token_t*) l1)->f_span;
        l5 = vader_front_parser$describe_token(l1);
        l5 = concat_2(2065u, l5);
        vader_front_parser$error(l0, (uint8_t) 5, l4, l5);
        vader_front_parser$advance(l0);
        vader_struct_toolchain_ast$WildcardPattern_t* _a6_obj = (vader_struct_toolchain_ast$WildcardPattern_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$WildcardPattern_t));
        vader_obj_header_init(_a6_obj, 831u);
        _a6_obj->f_span = ((vader_struct_vader_front_lexer$Token_t*) l1)->f_span;
        _a6_obj->f_id = INT64_C(0);
        t0 = (void*) _a6_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = vader_front_parser$parse_prefix(l0);
    t1 = vader_front_parser$check(l0, (uint8_t) 74);
    if (t1) {
        l8 = true;
    } else {
        l8 = vader_front_parser$check(l0, (uint8_t) 73);
    }
    if (!(l8)) {
        l3 = vader_front_parser$peek_at(l0, INT32_C(-1));
        t0 = vader_front_parser$span_of(l0, l1, l3);
        vader_struct_toolchain_ast$LiteralPattern_t* _a7_obj = (vader_struct_toolchain_ast$LiteralPattern_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$LiteralPattern_t));
        vader_obj_header_init(_a7_obj, 793u);
        _a7_obj->f_span = t0;
        _a7_obj->f_id = INT64_C(0);
        _a7_obj->f_value = l6;
        t0 = (void*) _a7_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l8 = vader_front_parser$check(l0, (uint8_t) 74);
    vader_front_parser$advance(l0);
    l7 = vader_front_parser$parse_prefix(l0);
    l2 = vader_front_parser$peek_at(l0, INT32_C(-1));
    t0 = vader_front_parser$span_of(l0, l1, l2);
    vader_struct_toolchain_ast$RangePattern_t* _a8_obj = (vader_struct_toolchain_ast$RangePattern_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$RangePattern_t));
    vader_obj_header_init(_a8_obj, 807u);
    _a8_obj->f_span = t0;
    _a8_obj->f_id = INT64_C(0);
    _a8_obj->f_inclusive = l8;
    _a8_obj->f_lower = l6;
    _a8_obj->f_upper = l7;
    t0 = (void*) _a8_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_parser$parse_postfix(void* l0, vader_box_t l1, void* l2) {
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
    if (((vader_struct_vader_front_lexer$Token_t*) l2)->f_kind == INT32_C(86)) {
        vader_front_parser$advance(l0);
        t0 = vader_front_parser$check(l0, (uint8_t) 3);
        if (t0) {
            l3 = vader_front_parser$advance(l0);
            l4 = ((vader_struct_toolchain_span$Span_t*) VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l1.payload.obj))->f_start;
            l5 = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_front_lexer$Token_t*) l3)->f_span)->f_end;
            vader_struct_toolchain_span$Span_t* _a0_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
            vader_obj_header_init(_a0_obj, 835u);
            _a0_obj->f_start = l4;
            _a0_obj->f_end = l5;
            l4 = (void*) _a0_obj;
            l6 = ((vader_struct_vader_front_lexer$Token_t*) l3)->f_text;
            l3 = ((vader_struct_vader_front_lexer$Token_t*) l3)->f_span;
            vader_struct_toolchain_ast$FieldExpr_t* _a1_obj = (vader_struct_toolchain_ast$FieldExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$FieldExpr_t));
            vader_obj_header_init(_a1_obj, 771u);
            _a1_obj->f_span = l4;
            _a1_obj->f_id = INT64_C(0);
            _a1_obj->f_target = l1;
            _a1_obj->f_field = l6;
            _a1_obj->f_field_span = l3;
            _a1_obj->f_is_numeric = true;
            t1 = (void*) _a1_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l3 = vader_front_parser$expect(l0, (uint8_t) 2, 1989u);
        l4 = ((vader_struct_toolchain_span$Span_t*) VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l1.payload.obj))->f_start;
        l5 = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_front_lexer$Token_t*) l3)->f_span)->f_end;
        vader_struct_toolchain_span$Span_t* _a2_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
        vader_obj_header_init(_a2_obj, 835u);
        _a2_obj->f_start = l4;
        _a2_obj->f_end = l5;
        l4 = (void*) _a2_obj;
        l6 = ((vader_struct_vader_front_lexer$Token_t*) l3)->f_text;
        l3 = ((vader_struct_vader_front_lexer$Token_t*) l3)->f_span;
        vader_struct_toolchain_ast$FieldExpr_t* _a3_obj = (vader_struct_toolchain_ast$FieldExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$FieldExpr_t));
        vader_obj_header_init(_a3_obj, 771u);
        _a3_obj->f_span = l4;
        _a3_obj->f_id = INT64_C(0);
        _a3_obj->f_target = l1;
        _a3_obj->f_field = l6;
        _a3_obj->f_field_span = l3;
        _a3_obj->f_is_numeric = false;
        l3 = (void*) _a3_obj;
        l7 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_pos;
        t0 = vader_front_parser$scan_angle_generic(l0, l7);
        if (t0) {
            t2 = vader_front_parser$parse_generic_use(l0, vader_ref_box(l3));
            { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = vader_front_parser$allows_struct_lit(l0);
        if (t0) {
            t0 = vader_front_parser$check(l0, (uint8_t) 83);
            if (t0) {
                l4 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_tokens;
                l7 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_pos;
                t0 = vader_front_parser$looks_like_struct_lit_body(l4, l7);
                if (t0) {
                    vader_front_parser$advance(l0);
                    l4 = vader_front_parser$parse_struct_lit_fields(l0);
                    l5 = vader_front_parser$expect(l0, (uint8_t) 84, 1410u);
                    l8 = ((vader_struct_toolchain_span$Span_t*) VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l1.payload.obj))->f_start;
                    l5 = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_front_lexer$Token_t*) l5)->f_span)->f_end;
                    vader_struct_toolchain_span$Span_t* _a4_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
                    vader_obj_header_init(_a4_obj, 835u);
                    _a4_obj->f_start = l8;
                    _a4_obj->f_end = l5;
                    l5 = (void*) _a4_obj;
                    l8 = ((vader_struct_vader_front_parser$CommaList__toolchain_ast_StructLitField___toolchain_ast_StructLitSpread_t*) l4)->f_items;
                    l9 = ((vader_struct_vader_front_parser$CommaList__toolchain_ast_StructLitField___toolchain_ast_StructLitSpread_t*) l4)->f_trailing_comma;
                    vader_struct_toolchain_ast$StructLitExpr_t* _a5_obj = (vader_struct_toolchain_ast$StructLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$StructLitExpr_t));
                    vader_obj_header_init(_a5_obj, 818u);
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
    if (((vader_struct_vader_front_lexer$Token_t*) l2)->f_kind == INT32_C(79)) {
        vader_front_parser$advance(l0);
        l3 = vader_front_parser$parse_call_args(l0);
        vader_front_parser$expect(l0, (uint8_t) 80, 1275u);
        l4 = ((vader_struct_toolchain_span$Span_t*) VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l1.payload.obj))->f_start;
        t1 = vader_front_parser$peek_at(l0, INT32_C(-1));
        l5 = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_front_lexer$Token_t*) t1)->f_span)->f_end;
        vader_struct_toolchain_span$Span_t* _a6_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
        vader_obj_header_init(_a6_obj, 835u);
        _a6_obj->f_start = l4;
        _a6_obj->f_end = l5;
        l4 = (void*) _a6_obj;
        vader_array_t* _a7_arr = vader_array_new(349u, 0u, 13u, 1716u);
        l5 = (void*) _a7_arr;
        l8 = ((vader_struct_vader_front_parser$CommaList__toolchain_ast_CallArg_t*) l3)->f_items;
        l9 = ((vader_struct_vader_front_parser$CommaList__toolchain_ast_CallArg_t*) l3)->f_trailing_comma;
        vader_struct_toolchain_ast$CallExpr_t* _a8_obj = (vader_struct_toolchain_ast$CallExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$CallExpr_t));
        vader_obj_header_init(_a8_obj, 751u);
        _a8_obj->f_span = l4;
        _a8_obj->f_id = INT64_C(0);
        _a8_obj->f_callee = l1;
        _a8_obj->f_type_args = l5;
        _a8_obj->f_args = l8;
        _a8_obj->f_trailing_comma = l9;
        t1 = (void*) _a8_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_front_parser$check_at(l0, (uint8_t) 82, INT32_C(1));
    if (!(t0)) {
        vader_front_parser$advance(l0);
        l10 = vader_front_parser$parse_expr(l0, INT32_C(0));
        vader_front_parser$expect(l0, (uint8_t) 82, 1373u);
        l5 = ((vader_struct_toolchain_span$Span_t*) VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l1.payload.obj))->f_start;
        t1 = vader_front_parser$peek_at(l0, INT32_C(-1));
        l8 = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_front_lexer$Token_t*) t1)->f_span)->f_end;
        vader_struct_toolchain_span$Span_t* _a9_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
        vader_obj_header_init(_a9_obj, 835u);
        _a9_obj->f_start = l5;
        _a9_obj->f_end = l8;
        t1 = (void*) _a9_obj;
        vader_struct_toolchain_ast$IndexExpr_t* _a10_obj = (vader_struct_toolchain_ast$IndexExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$IndexExpr_t));
        vader_obj_header_init(_a10_obj, 786u);
        _a10_obj->f_span = t1;
        _a10_obj->f_id = INT64_C(0);
        _a10_obj->f_target = l1;
        _a10_obj->f_index = l10;
        t1 = (void*) _a10_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_front_parser$advance(l0);
    l3 = vader_front_parser$advance(l0);
    l4 = ((vader_struct_toolchain_span$Span_t*) VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l1.payload.obj))->f_start;
    l3 = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_front_lexer$Token_t*) l3)->f_span)->f_end;
    vader_struct_toolchain_span$Span_t* _a11_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
    vader_obj_header_init(_a11_obj, 835u);
    _a11_obj->f_start = l4;
    _a11_obj->f_end = l3;
    t1 = (void*) _a11_obj;
    vader_struct_toolchain_ast$ArrayTypeExpr_t* _a12_obj = (vader_struct_toolchain_ast$ArrayTypeExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$ArrayTypeExpr_t));
    vader_obj_header_init(_a12_obj, 742u);
    _a12_obj->f_span = t1;
    _a12_obj->f_id = INT64_C(0);
    _a12_obj->f_element = l1;
    t1 = (void*) _a12_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_parser$parse_prefix(void* l0) {
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
    l1 = vader_front_parser$peek(l0);
    t0 = vader_front_parser$is_number_token(l1);
    if (t0) {
        vader_front_parser$advance(l0);
        l2 = ((vader_struct_vader_front_lexer$Token_t*) l1)->f_span;
        t1 = vader_front_parser$number_literal(l1, l2, false);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_front_lexer$Token_t*) l1)->f_kind == INT32_C(37)) {
        l2 = vader_front_parser$peek_at(l0, INT32_C(1));
        t0 = vader_front_parser$is_number_token(l2);
        if (t0) {
            l3 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_front_lexer$Token_t*) l2)->f_span)->f_start)->f_offset;
            l4 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_front_lexer$Token_t*) l1)->f_span)->f_end)->f_offset;
            if (l3 == l4) {
                vader_front_parser$advance(l0);
                vader_front_parser$advance(l0);
                l5 = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_front_lexer$Token_t*) l1)->f_span)->f_start;
                l6 = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_front_lexer$Token_t*) l2)->f_span)->f_end;
                vader_struct_toolchain_span$Span_t* _a0_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
                vader_obj_header_init(_a0_obj, 835u);
                _a0_obj->f_start = l5;
                _a0_obj->f_end = l6;
                l5 = (void*) _a0_obj;
                t1 = vader_front_parser$number_literal(l2, l5, true);
                { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
    }
    if (((vader_struct_vader_front_lexer$Token_t*) l1)->f_kind == INT32_C(5)) {
        vader_front_parser$advance(l0);
        l7 = (uint32_t) 0;
        l8 = ((vader_struct_vader_front_lexer$Token_t*) l1)->f_value;
        if (l8.tag == 454u) {
            l7 = ((uint32_t) l8.payload.i);
        }
        vader_struct_toolchain_ast$CharLitExpr_t* _a1_obj = (vader_struct_toolchain_ast$CharLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$CharLitExpr_t));
        vader_obj_header_init(_a1_obj, 753u);
        _a1_obj->f_span = ((vader_struct_vader_front_lexer$Token_t*) l1)->f_span;
        _a1_obj->f_id = INT64_C(0);
        _a1_obj->f_value = l7;
        t2 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_front_lexer$Token_t*) l1)->f_kind == INT32_C(31)) {
        vader_front_parser$advance(l0);
        vader_struct_toolchain_ast$BoolLitExpr_t* _a2_obj = (vader_struct_toolchain_ast$BoolLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$BoolLitExpr_t));
        vader_obj_header_init(_a2_obj, 748u);
        _a2_obj->f_span = ((vader_struct_vader_front_lexer$Token_t*) l1)->f_span;
        _a2_obj->f_id = INT64_C(0);
        _a2_obj->f_value = true;
        t2 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_front_lexer$Token_t*) l1)->f_kind == INT32_C(32)) {
        vader_front_parser$advance(l0);
        vader_struct_toolchain_ast$BoolLitExpr_t* _a3_obj = (vader_struct_toolchain_ast$BoolLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$BoolLitExpr_t));
        vader_obj_header_init(_a3_obj, 748u);
        _a3_obj->f_span = ((vader_struct_vader_front_lexer$Token_t*) l1)->f_span;
        _a3_obj->f_id = INT64_C(0);
        _a3_obj->f_value = false;
        t2 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_front_lexer$Token_t*) l1)->f_kind == INT32_C(33)) {
        vader_front_parser$advance(l0);
        vader_struct_toolchain_ast$NullLitExpr_t* _a4_obj = (vader_struct_toolchain_ast$NullLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$NullLitExpr_t));
        vader_obj_header_init(_a4_obj, 800u);
        _a4_obj->f_span = ((vader_struct_vader_front_lexer$Token_t*) l1)->f_span;
        _a4_obj->f_id = INT64_C(0);
        t2 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_front_lexer$Token_t*) l1)->f_kind == INT32_C(6)) {
        t2 = vader_front_parser$parse_string_lit(l0);
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_front_lexer$Token_t*) l1)->f_kind == INT32_C(2)) {
        t1 = vader_front_parser$parse_ident_or_struct_lit(l0);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_front_lexer$Token_t*) l1)->f_kind == INT32_C(79)) {
        t0 = vader_front_parser$allows_bare_lambda(l0);
        if (t0) {
            t0 = vader_front_parser$peek_lambda_without_fn(l0);
            if (t0) {
                t2 = vader_front_parser$parse_lambda_without_fn(l0);
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t1 = vader_front_parser$parse_paren(l0);
            { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t1 = vader_front_parser$parse_paren(l0);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_front_lexer$Token_t*) l1)->f_kind == INT32_C(81)) {
        t2 = vader_front_parser$parse_seq_lit(l0);
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_front_lexer$Token_t*) l1)->f_kind == INT32_C(83)) {
        t2 = vader_front_parser$parse_block(l0);
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_front_lexer$Token_t*) l1)->f_kind == INT32_C(37)) {
        l9 = true;
    } else {
        l9 = ((vader_struct_vader_front_lexer$Token_t*) l1)->f_kind == INT32_C(60);
    }
    if (l9) {
        l9 = true;
    } else {
        l9 = ((vader_struct_vader_front_lexer$Token_t*) l1)->f_kind == INT32_C(47);
    }
    if (l9) {
        vader_front_parser$advance(l0);
        l10 = (uint8_t) 0;
        if (((vader_struct_vader_front_lexer$Token_t*) l1)->f_kind == INT32_C(60)) {
            l10 = (uint8_t) 1;
        }
        if (((vader_struct_vader_front_lexer$Token_t*) l1)->f_kind == INT32_C(47)) {
            l10 = (uint8_t) 2;
        }
        l8 = vader_front_parser$parse_expr(l0, INT32_C(95));
        l2 = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_front_lexer$Token_t*) l1)->f_span)->f_start;
        l5 = ((vader_struct_toolchain_span$Span_t*) VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l8.payload.obj))->f_end;
        vader_struct_toolchain_span$Span_t* _a5_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
        vader_obj_header_init(_a5_obj, 835u);
        _a5_obj->f_start = l2;
        _a5_obj->f_end = l5;
        t2 = (void*) _a5_obj;
        vader_struct_toolchain_ast$UnaryExpr_t* _a6_obj = (vader_struct_toolchain_ast$UnaryExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$UnaryExpr_t));
        vader_obj_header_init(_a6_obj, 827u);
        _a6_obj->f_span = t2;
        _a6_obj->f_id = INT64_C(0);
        _a6_obj->f_op = l10;
        _a6_obj->f_operand = l8;
        t2 = (void*) _a6_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_front_lexer$Token_t*) l1)->f_kind == INT32_C(24)) {
        vader_front_parser$advance(l0);
        l8 = vader_front_parser$parse_expr(l0, INT32_C(95));
        l2 = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_front_lexer$Token_t*) l1)->f_span)->f_start;
        l5 = ((vader_struct_toolchain_span$Span_t*) VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l8.payload.obj))->f_end;
        vader_struct_toolchain_span$Span_t* _a7_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
        vader_obj_header_init(_a7_obj, 835u);
        _a7_obj->f_start = l2;
        _a7_obj->f_end = l5;
        t2 = (void*) _a7_obj;
        vader_struct_toolchain_ast$AwaitExpr_t* _a8_obj = (vader_struct_toolchain_ast$AwaitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$AwaitExpr_t));
        vader_obj_header_init(_a8_obj, 745u);
        _a8_obj->f_span = t2;
        _a8_obj->f_id = INT64_C(0);
        _a8_obj->f_inner = l8;
        t2 = (void*) _a8_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_front_lexer$Token_t*) l1)->f_kind == INT32_C(16)) {
        t2 = vader_front_parser$parse_if_expr(l0);
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_front_lexer$Token_t*) l1)->f_kind == INT32_C(18)) {
        l2 = ((vader_struct_vader_front_lexer$Token_t*) l1)->f_span;
        t2 = vader_front_parser$parse_match_expr(l0, false, false, l2);
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_front_lexer$Token_t*) l1)->f_kind == INT32_C(11)) {
        t2 = vader_front_parser$parse_lambda(l0);
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_front_lexer$Token_t*) l1)->f_kind == INT32_C(34)) {
        vader_front_parser$advance(l0);
        t2 = vader_front_parser$ident_expr(((vader_struct_vader_front_lexer$Token_t*) l1)->f_span, 2545u);
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_front_lexer$Token_t*) l1)->f_kind == INT32_C(78)) {
        l2 = vader_front_parser$advance(l0);
        l5 = vader_front_parser$expect(l0, (uint8_t) 2, 1822u);
        t3 = ((vader_struct_vader_front_lexer$Token_t*) l5)->f_text;
        t0 = vader_front_parser$decorator_on(t3, (uint8_t) 2);
        if (t0) {
            t0 = vader_front_parser$check(l0, (uint8_t) 18);
            if (!(t0)) {
                l6 = ((vader_struct_vader_front_lexer$Token_t*) l5)->f_span;
                l11 = ((vader_struct_vader_front_lexer$Token_t*) l5)->f_text;
                l11 = concat_3(1327u, l11, 1193u);
                vader_front_parser$error(l0, (uint8_t) 8, l6, l11);
            }
            t3 = ((vader_struct_vader_front_lexer$Token_t*) l5)->f_text;
            l9 = t3 == 2460u;
            l12 = !(l9);
            l6 = ((vader_struct_vader_front_lexer$Token_t*) l2)->f_span;
            t2 = vader_front_parser$parse_match_expr(l0, l9, l12, l6);
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t3 = ((vader_struct_vader_front_lexer$Token_t*) l5)->f_text;
        l8 = vader_front_parser$intrinsic_spec(t3);
        if (l8.tag == 0u) {
            l6 = vader_front_parser$span_of(l0, l2, l5);
            l11 = ((vader_struct_vader_front_lexer$Token_t*) l5)->f_text;
            l11 = concat_3(1327u, l11, 1166u);
            vader_front_parser$error(l0, (uint8_t) 8, l6, l11);
            t0 = vader_front_parser$check(l0, (uint8_t) 79);
            if (t0) {
                vader_front_parser$advance(l0);
                for (;;) {
                    t0 = vader_front_parser$check(l0, (uint8_t) 80);
                    if (!(t0)) {
                        t0 = vader_front_parser$check(l0, (uint8_t) 0);
                        if (t0) break;
                        vader_front_parser$advance(l0);
                        continue;
                    }
                    break;
                }
                t0 = vader_front_parser$check(l0, (uint8_t) 80);
                if (t0) {
                    vader_front_parser$advance(l0);
                }
            }
            t2 = vader_front_parser$span_of(l0, l2, l5);
            vader_struct_toolchain_ast$NullLitExpr_t* _a9_obj = (vader_struct_toolchain_ast$NullLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$NullLitExpr_t));
            vader_obj_header_init(_a9_obj, 800u);
            _a9_obj->f_span = t2;
            _a9_obj->f_id = INT64_C(0);
            t2 = (void*) _a9_obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (!(l8.tag == 1201u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t2 = l8.payload.obj;
        l11 = ((vader_struct_vader_front_parser$IntrinsicSpec_t*) t2)->f_name;
        l11 = concat_3(1264u, l11, 1033u);
        vader_front_parser$expect(l0, (uint8_t) 79, l11);
        vader_array_t* _a10_arr = vader_array_new(349u, 0u, 13u, 1716u);
        l6 = (void*) _a10_arr;
        vader_front_parser$skip_newlines(l0);
        l9 = false;
        t0 = vader_front_parser$check(l0, (uint8_t) 80);
        if (!(t0)) {
            for (;;) {
                vader_front_parser$skip_newlines(l0);
                t0 = vader_front_parser$check(l0, (uint8_t) 80);
                if (!(t0)) {
                    l3 = ((vader_array_t*) l6)->length;
                    t2 = l8.payload.obj;
                    t4 = vader_front_parser$arg_kind(t2, l3);
                    if (t4 == INT32_C(0)) {
                        l13 = vader_front_parser$parse_type(l0);
                        vader_array_push_ref((vader_array_t*) l6, l13.payload.obj);
                    } else {
                        l14 = vader_front_parser$parse_expr(l0, INT32_C(0));
                        vader_array_push_ref((vader_array_t*) l6, l14.payload.obj);
                    }
                    vader_front_parser$skip_newlines(l0);
                    t1 = vader_front_parser$match_kind(l0, (uint8_t) 85);
                    if (t1.tag == 0u) break;
                    vader_front_parser$skip_newlines(l0);
                    l9 = vader_front_parser$check(l0, (uint8_t) 80);
                    continue;
                }
                break;
            }
        }
        t2 = l8.payload.obj;
        l11 = ((vader_struct_vader_front_parser$IntrinsicSpec_t*) t2)->f_name;
        l11 = concat_3(1274u, l11, 314u);
        l15 = vader_front_parser$expect(l0, (uint8_t) 80, l11);
        l2 = vader_front_parser$span_of(l0, l2, l15);
        t2 = l8.payload.obj;
        l11 = ((vader_struct_vader_front_parser$IntrinsicSpec_t*) t2)->f_name;
        l5 = ((vader_struct_vader_front_lexer$Token_t*) l5)->f_span;
        vader_struct_toolchain_ast$IntrinsicCallExpr_t* _a11_obj = (vader_struct_toolchain_ast$IntrinsicCallExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$IntrinsicCallExpr_t));
        vader_obj_header_init(_a11_obj, 789u);
        _a11_obj->f_span = l2;
        _a11_obj->f_id = INT64_C(0);
        _a11_obj->f_name = l11;
        _a11_obj->f_name_span = l5;
        _a11_obj->f_args = l6;
        _a11_obj->f_trailing_comma = l9;
        t2 = (void*) _a11_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(((vader_struct_vader_front_lexer$Token_t*) l1)->f_kind == INT32_C(86))) {
        l6 = ((vader_struct_vader_front_lexer$Token_t*) l1)->f_span;
        l16 = vader_front_parser$describe_token(l1);
        l16 = concat_2(2065u, l16);
        vader_front_parser$error(l0, (uint8_t) 2, l6, l16);
        vader_front_parser$advance(l0);
        vader_struct_toolchain_ast$NullLitExpr_t* _a12_obj = (vader_struct_toolchain_ast$NullLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$NullLitExpr_t));
        vader_obj_header_init(_a12_obj, 800u);
        _a12_obj->f_span = ((vader_struct_vader_front_lexer$Token_t*) l1)->f_span;
        _a12_obj->f_id = INT64_C(0);
        t2 = (void*) _a12_obj;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_front_parser$advance(l0);
    l2 = vader_front_parser$expect(l0, (uint8_t) 2, 3000u);
    l1 = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_front_lexer$Token_t*) l1)->f_span)->f_start;
    l5 = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_front_lexer$Token_t*) l2)->f_span)->f_end;
    vader_struct_toolchain_span$Span_t* _a13_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
    vader_obj_header_init(_a13_obj, 835u);
    _a13_obj->f_start = l1;
    _a13_obj->f_end = l5;
    l1 = (void*) _a13_obj;
    l11 = ((vader_struct_vader_front_lexer$Token_t*) l2)->f_text;
    l2 = ((vader_struct_vader_front_lexer$Token_t*) l2)->f_span;
    vader_struct_toolchain_ast$DotVariantExpr_t* _a14_obj = (vader_struct_toolchain_ast$DotVariantExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$DotVariantExpr_t));
    vader_obj_header_init(_a14_obj, 766u);
    _a14_obj->f_span = l1;
    _a14_obj->f_id = INT64_C(0);
    _a14_obj->f_variant = l11;
    _a14_obj->f_variant_span = l2;
    t2 = (void*) _a14_obj;
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_parser$parse_program(void* l0) {
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
    l1 = vader_front_parser$peek(l0);
    vader_array_t* _a0_arr = vader_array_new(350u, 0u, 13u, 1745u);
    l2 = (void*) _a0_arr;
    vader_front_parser$skip_newlines(l0);
    l3 = vader_front_parser$parse_optional_module_decl(l0);
    vader_front_parser$skip_newlines(l0);
    for (;;) {
        t0 = vader_front_parser$check(l0, (uint8_t) 0);
        if (!(t0)) {
            l4 = vader_front_parser$parse_decl(l0);
            t1 = ((vader_array_t*) ((vader_struct_vader_front_parser$Parser_t*) l0)->f_pending_decls)->length;
            if ((t1 > INT64_C(0))) {
                l5 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_pending_decls;
                l6 = ((vader_array_t*) l5)->length;
                l7 = INT64_C(0);
                while ((l7 < l6)) {
                    vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
                    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                    l8 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l7);
                    vader_array_push_ref((vader_array_t*) l2, l8.payload.obj);
                    l7 = (l7 + INT64_C(1));
                }
                vader_array_t* _a2_arr = vader_array_new(350u, 0u, 13u, 1745u);
                l9 = (void*) _a2_arr;
                ((vader_struct_vader_front_parser$Parser_t*) l0)->f_pending_decls = l9;
                VADER_WRITE_BARRIER((vader_struct_vader_front_parser$Parser_t*) l0);
            }
            if (l4.tag == 0u) {
                vader_front_parser$advance(l0);
            } else if (l4.tag == 783u) {
                l10 = l4.payload.obj;
                vader_array_push_ref((vader_array_t*) l2, l10);
            } else if (l4.tag == 773u) {
                l11 = l4.payload.obj;
                vader_array_push_ref((vader_array_t*) l2, l11);
            } else if (l4.tag == 816u) {
                l12 = l4.payload.obj;
                vader_array_push_ref((vader_array_t*) l2, l12);
            } else if (l4.tag == 767u) {
                l13 = l4.payload.obj;
                vader_array_push_ref((vader_array_t*) l2, l13);
            } else if (l4.tag == 823u) {
                l14 = l4.payload.obj;
                vader_array_push_ref((vader_array_t*) l2, l14);
            } else if (l4.tag == 782u) {
                l15 = l4.payload.obj;
                vader_array_push_ref((vader_array_t*) l2, l15);
            } else if (l4.tag == 825u) {
                l16 = l4.payload.obj;
                vader_array_push_ref((vader_array_t*) l2, l16);
            } else if (l4.tag == 754u) {
                l17 = l4.payload.obj;
                vader_array_push_ref((vader_array_t*) l2, l17);
            } else {
                if (!(l4.tag == 743u)) {
                    vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                }
                l18 = l4.payload.obj;
                vader_array_push_ref((vader_array_t*) l2, l18);
            }
            vader_front_parser$skip_newlines(l0);
            continue;
        }
        break;
    }
    l5 = vader_front_parser$peek(l0);
    l19 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_file;
    l1 = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_front_lexer$Token_t*) l1)->f_span)->f_start;
    l5 = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_front_lexer$Token_t*) l5)->f_span)->f_end;
    vader_struct_toolchain_span$Span_t* _a3_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
    vader_obj_header_init(_a3_obj, 835u);
    _a3_obj->f_start = l1;
    _a3_obj->f_end = l5;
    l1 = (void*) _a3_obj;
    vader_struct_toolchain_ast$Program_t* _a4_obj = (vader_struct_toolchain_ast$Program_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$Program_t));
    vader_obj_header_init(_a4_obj, 805u);
    _a4_obj->f_file = l19;
    _a4_obj->f_span = l1;
    _a4_obj->f_id = INT64_C(0);
    _a4_obj->f_module = l3;
    _a4_obj->f_decls = l2;
    t2 = (void*) _a4_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_parser$parse_range_bound(void* l0) {
    vader_box_t l1 = vader_box_null(), l3 = vader_box_null();
    void* l2 = NULL;
    void* l4 = NULL;
    bool l5;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l1, &l3, &t0 };
    void** gc_raw_roots[3] = { &l0, &l2, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_front_parser$match_kind(l0, (uint8_t) 37);
    l2 = vader_front_parser$expect(l0, (uint8_t) 3, 2178u);
    l3 = l1;
    if (l3.tag == 0u) {
        l4 = l2;
    } else {
        l4 = l3.payload.obj;
    }
    l4 = vader_front_parser$span_of(l0, l4, l2);
    l5 = !(l1.tag == 0u);
    t0 = vader_front_parser$number_literal(l2, l4, l5);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_parser$parse_range_type(void* l0) {
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
    l1 = vader_front_parser$parse_range_bound(l0);
    l2 = vader_front_parser$peek(l0);
    if (((vader_struct_vader_front_lexer$Token_t*) l2)->f_kind != INT32_C(74)) {
        if (((vader_struct_vader_front_lexer$Token_t*) l2)->f_kind != INT32_C(73)) {
            l3 = ((vader_struct_vader_front_lexer$Token_t*) l2)->f_span;
            l4 = vader_front_parser$describe_token(l2);
            l4 = concat_2(1480u, l4);
            vader_front_parser$error(l0, (uint8_t) 3, l3, l4);
            { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    vader_front_parser$advance(l0);
    l5 = vader_front_parser$parse_range_bound(l0);
    l3 = ((vader_struct_toolchain_span$Span_t*) VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l1.payload.obj))->f_start;
    l6 = ((vader_struct_toolchain_span$Span_t*) VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l5.payload.obj))->f_end;
    vader_struct_toolchain_span$Span_t* _a0_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
    vader_obj_header_init(_a0_obj, 835u);
    _a0_obj->f_start = l3;
    _a0_obj->f_end = l6;
    l3 = (void*) _a0_obj;
    l7 = ((vader_struct_vader_front_lexer$Token_t*) l2)->f_kind == INT32_C(74);
    vader_struct_toolchain_ast$RangeExpr_t* _a1_obj = (vader_struct_toolchain_ast$RangeExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$RangeExpr_t));
    vader_obj_header_init(_a1_obj, 806u);
    _a1_obj->f_span = l3;
    _a1_obj->f_id = INT64_C(0);
    _a1_obj->f_inclusive = l7;
    _a1_obj->f_lower = l1;
    _a1_obj->f_upper = l5;
    t0 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_parser$parse_return(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    vader_box_t l2 = vader_box_null();
    bool t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_front_parser$advance(l0);
    l2 = vader_box_obj(0u, NULL);
    t0 = vader_front_parser$check(l0, (uint8_t) 1);
    if (!(t0)) {
        t0 = vader_front_parser$check(l0, (uint8_t) 84);
        if (!(t0)) {
            t0 = vader_front_parser$check(l0, (uint8_t) 0);
            if (!(t0)) {
                l2 = vader_front_parser$parse_expr(l0, INT32_C(0));
            }
        }
    }
    l3 = vader_front_parser$peek_at(l0, INT32_C(-1));
    t1 = vader_front_parser$span_of(l0, l1, l3);
    vader_struct_toolchain_ast$ReturnStmt_t* _a0_obj = (vader_struct_toolchain_ast$ReturnStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$ReturnStmt_t));
    vader_obj_header_init(_a0_obj, 810u);
    _a0_obj->f_span = t1;
    _a0_obj->f_id = INT64_C(0);
    _a0_obj->f_value = l2;
    t1 = (void*) _a0_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_parser$parse_sam_arrow_member(void* l0) {
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
    l1 = vader_front_parser$expect(l0, (uint8_t) 76, 1304u);
    l2 = vader_front_parser$parse_expr(l0, INT32_C(0));
    l3 = vader_front_parser$peek_at(l0, INT32_C(-1));
    l3 = vader_front_parser$span_of(l0, l1, l3);
    vader_array_t* _a0_arr = vader_array_new(351u, 0u, 13u, 1753u);
    l4 = (void*) _a0_arr;
    vader_struct_toolchain_ast$BlockExpr_t* _a1_obj = (vader_struct_toolchain_ast$BlockExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$BlockExpr_t));
    vader_obj_header_init(_a1_obj, 747u);
    _a1_obj->f_span = l3;
    _a1_obj->f_id = INT64_C(0);
    _a1_obj->f_stmts = l4;
    _a1_obj->f_trailing = l2;
    l4 = (void*) _a1_obj;
    l1 = ((vader_struct_vader_front_lexer$Token_t*) l1)->f_span;
    vader_array_t* _a2_arr = vader_array_new(59u, 0u, 13u, 826u);
    l5 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(48u, 0u, 13u, 774u);
    l6 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(43u, 0u, 13u, 756u);
    l7 = (void*) _a4_arr;
    vader_struct_toolchain_ast$FnDecl_t* _a5_obj = (vader_struct_toolchain_ast$FnDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$FnDecl_t));
    vader_obj_header_init(_a5_obj, 773u);
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
    _a5_obj->f_doc = vader_box_obj(0u, NULL);
    _a5_obj->f_inherits = vader_box_obj(0u, NULL);
    t0 = (void*) _a5_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_parser$parse_sam_block_member(void* l0) {
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
    l1 = vader_front_parser$parse_block(l0);
    l2 = ((vader_struct_toolchain_ast$BlockExpr_t*) l1)->f_span;
    l3 = ((vader_struct_toolchain_ast$BlockExpr_t*) l1)->f_span;
    vader_array_t* _a0_arr = vader_array_new(59u, 0u, 13u, 826u);
    l4 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(48u, 0u, 13u, 774u);
    l5 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(43u, 0u, 13u, 756u);
    l6 = (void*) _a2_arr;
    vader_struct_toolchain_ast$FnDecl_t* _a3_obj = (vader_struct_toolchain_ast$FnDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$FnDecl_t));
    vader_obj_header_init(_a3_obj, 773u);
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
    _a3_obj->f_doc = vader_box_obj(0u, NULL);
    _a3_obj->f_inherits = vader_box_obj(0u, NULL);
    t0 = (void*) _a3_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_parser$parse_seq_lit(void* l0) {
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
    l1 = vader_front_parser$advance(l0);
    vader_array_t* _a0_arr = vader_array_new(349u, 0u, 13u, 1716u);
    l2 = (void*) _a0_arr;
    l3 = false;
    vader_front_parser$skip_newlines(l0);
    t0 = vader_front_parser$check(l0, (uint8_t) 82);
    if (!(t0)) {
        for (;;) {
            vader_front_parser$skip_newlines(l0);
            t0 = vader_front_parser$check(l0, (uint8_t) 82);
            if (!(t0)) {
                l4 = vader_front_parser$parse_expr(l0, INT32_C(0));
                vader_array_push_ref((vader_array_t*) l2, l4.payload.obj);
                vader_front_parser$skip_newlines(l0);
                t1 = vader_front_parser$match_kind(l0, (uint8_t) 85);
                if (t1.tag == 0u) break;
                vader_front_parser$skip_newlines(l0);
                l3 = vader_front_parser$check(l0, (uint8_t) 82);
                continue;
            }
            break;
        }
    }
    l5 = vader_front_parser$expect(l0, (uint8_t) 82, 1374u);
    t2 = vader_front_parser$span_of(l0, l1, l5);
    vader_struct_toolchain_ast$SeqLitExpr_t* _a1_obj = (vader_struct_toolchain_ast$SeqLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$SeqLitExpr_t));
    vader_obj_header_init(_a1_obj, 811u);
    _a1_obj->f_span = t2;
    _a1_obj->f_id = INT64_C(0);
    _a1_obj->f_elements = l2;
    _a1_obj->f_trailing_comma = l3;
    t2 = (void*) _a1_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_parser$parse_single_param_lambda_tail(void* l0, void* l1) {
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
    vader_front_parser$advance(l0);
    l2 = ((vader_struct_toolchain_ast$IdentExpr_t*) l1)->f_span;
    l3 = ((vader_struct_toolchain_ast$IdentExpr_t*) l1)->f_name;
    l4 = ((vader_struct_toolchain_ast$IdentExpr_t*) l1)->f_span;
    vader_array_t* _a0_arr = vader_array_new(43u, 0u, 13u, 756u);
    l5 = (void*) _a0_arr;
    vader_struct_toolchain_ast$FnParam_t* _a1_obj = (vader_struct_toolchain_ast$FnParam_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$FnParam_t));
    vader_obj_header_init(_a1_obj, 774u);
    _a1_obj->f_span = l2;
    _a1_obj->f_id = INT64_C(0);
    _a1_obj->f_name = l3;
    _a1_obj->f_name_span = l4;
    _a1_obj->f_ty = vader_box_obj(0u, NULL);
    _a1_obj->f_default_value = vader_box_obj(0u, NULL);
    _a1_obj->f_variadic = false;
    _a1_obj->f_decorators = l5;
    l2 = (void*) _a1_obj;
    t0 = vader_front_parser$parse_expr(l0, INT32_C(0));
    l4 = vader_front_parser$wrap_as_block(t0);
    l5 = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_toolchain_ast$IdentExpr_t*) l1)->f_span)->f_start;
    l6 = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_toolchain_ast$BlockExpr_t*) l4)->f_span)->f_end;
    vader_struct_toolchain_span$Span_t* _a2_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
    vader_obj_header_init(_a2_obj, 835u);
    _a2_obj->f_start = l5;
    _a2_obj->f_end = l6;
    l5 = (void*) _a2_obj;
    vader_array_t* _a3_arr = vader_array_new(48u, 1u, 13u, 774u);
    ((void**) _a3_arr->buf->slots)[_a3_arr->offset + 0u] = l2;
    l2 = (void*) _a3_arr;
    vader_struct_toolchain_ast$LambdaExpr_t* _a4_obj = (vader_struct_toolchain_ast$LambdaExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$LambdaExpr_t));
    vader_obj_header_init(_a4_obj, 791u);
    _a4_obj->f_span = l5;
    _a4_obj->f_id = INT64_C(0);
    _a4_obj->f_params = l2;
    _a4_obj->f_return_type = vader_box_obj(0u, NULL);
    _a4_obj->f_body = l4;
    _a4_obj->f_trailing_comma = false;
    _a4_obj->f_is_expression_bodied = false;
    t1 = (void*) _a4_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_front_parser$parse_source(vader_string_t l0, vader_string_t l1) {
    void* t0 = NULL;
    void* t1 = NULL;
    void** gc_raw_roots[2] = { &t0, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_front_lexer$tokenize(l0, l1);
    t1 = vader_front_parser$parse_lexed(t0);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_front_parser$parse_source_with_docs(vader_string_t l0, vader_string_t l1) {
    void* t0 = NULL;
    void* t1 = NULL;
    void** gc_raw_roots[2] = { &t0, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_front_lexer$tokenize_with_docs(l0, l1);
    t1 = vader_front_parser$parse_lexed(t0);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_parser$parse_stmt(void* l0) {
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
    t0 = vader_front_parser$check(l0, (uint8_t) 22);
    if (t0) {
        t1 = vader_front_parser$parse_return(l0);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_front_parser$check(l0, (uint8_t) 23);
    if (t0) {
        t1 = vader_front_parser$parse_yield(l0);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_front_parser$check(l0, (uint8_t) 20);
    if (t0) {
        t1 = vader_front_parser$parse_for(l0, vader_box_obj(0u, NULL), false);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_front_parser$check(l0, (uint8_t) 78);
    if (t0) {
        t1 = vader_front_parser$peek_at(l0, INT32_C(1));
        if (((vader_struct_vader_front_lexer$Token_t*) t1)->f_kind == INT32_C(2)) {
            t1 = vader_front_parser$peek_at(l0, INT32_C(1));
            t2 = ((vader_struct_vader_front_lexer$Token_t*) t1)->f_text;
            if (t2 == 1778u) {
                t0 = vader_front_parser$check_at(l0, (uint8_t) 20, INT32_C(2));
                if (t0) {
                    vader_front_parser$advance(l0);
                    vader_front_parser$advance(l0);
                    t1 = vader_front_parser$parse_for(l0, vader_box_obj(0u, NULL), true);
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
            }
        }
    }
    t0 = vader_front_parser$check(l0, (uint8_t) 26);
    if (t0) {
        t1 = vader_front_parser$parse_break(l0);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_front_parser$check(l0, (uint8_t) 27);
    if (t0) {
        t1 = vader_front_parser$parse_continue(l0);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_front_parser$check(l0, (uint8_t) 25);
    if (t0) {
        t1 = vader_front_parser$parse_defer(l0);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_front_parser$check(l0, (uint8_t) 2);
    if (t0) {
        t0 = vader_front_parser$check_at(l0, (uint8_t) 87, INT32_C(1));
        if (t0) {
            t0 = vader_front_parser$check_at(l0, (uint8_t) 20, INT32_C(2));
            if (t0) {
                l1 = vader_front_parser$advance(l0);
                vader_front_parser$advance(l0);
                l2 = ((vader_struct_vader_front_lexer$Token_t*) l1)->f_text;
                t1 = vader_front_parser$parse_for(l0, vader_box_string(447u, l2), false);
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
    }
    t0 = vader_front_parser$starts_let(l0);
    if (t0) {
        t1 = vader_front_parser$parse_any_let(l0);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_front_parser$check(l0, (uint8_t) 81);
    if (t0) {
        l3 = vader_front_parser$kind_after_bracket_group(l0);
        if (l3 == INT32_C(62)) {
            l4 = true;
        } else {
            t1 = vader_front_parser$compound_op(l3);
            l4 = ((vader_struct_vader_front_parser$CompoundOpResult_t*) t1)->f_matched;
        }
        if (l4) {
            t1 = vader_front_parser$parse_destructure_assign(l0);
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l1 = vader_front_parser$peek(l0);
    l5 = vader_front_parser$parse_expr(l0, INT32_C(0));
    t3 = vader_front_parser$match_kind(l0, (uint8_t) 62);
    if (!(t3.tag == 0u)) {
        l6 = vader_front_parser$parse_expr(l0, INT32_C(0));
        l7 = vader_front_parser$peek_at(l0, INT32_C(-1));
        t1 = vader_front_parser$span_of(l0, l1, l7);
        vader_struct_toolchain_ast$AssignStmt_t* _a0_obj = (vader_struct_toolchain_ast$AssignStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$AssignStmt_t));
        vader_obj_header_init(_a0_obj, 744u);
        _a0_obj->f_span = t1;
        _a0_obj->f_id = INT64_C(0);
        _a0_obj->f_target = l5;
        _a0_obj->f_value = l6;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_front_parser$peek(l0);
    l7 = vader_front_parser$compound_op(((vader_struct_vader_front_lexer$Token_t*) t1)->f_kind);
    t0 = ((vader_struct_vader_front_parser$CompoundOpResult_t*) l7)->f_matched;
    if (!(t0)) {
        vader_struct_toolchain_ast$ExprStmt_t* _a1_obj = (vader_struct_toolchain_ast$ExprStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$ExprStmt_t));
        vader_obj_header_init(_a1_obj, 770u);
        _a1_obj->f_span = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l5.payload.obj);
        _a1_obj->f_id = INT64_C(0);
        _a1_obj->f_expr = l5;
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_front_parser$advance(l0);
    l6 = vader_front_parser$parse_expr(l0, INT32_C(0));
    l8 = vader_front_parser$peek_at(l0, INT32_C(-1));
    l1 = vader_front_parser$span_of(l0, l1, l8);
    l3 = ((vader_struct_vader_front_parser$CompoundOpResult_t*) l7)->f_op;
    vader_struct_toolchain_ast$BinaryExpr_t* _a2_obj = (vader_struct_toolchain_ast$BinaryExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$BinaryExpr_t));
    vader_obj_header_init(_a2_obj, 746u);
    _a2_obj->f_span = l1;
    _a2_obj->f_id = INT64_C(0);
    _a2_obj->f_op = l3;
    _a2_obj->f_left = l5;
    _a2_obj->f_right = l6;
    l7 = (void*) _a2_obj;
    vader_struct_toolchain_ast$AssignStmt_t* _a3_obj = (vader_struct_toolchain_ast$AssignStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$AssignStmt_t));
    vader_obj_header_init(_a3_obj, 744u);
    _a3_obj->f_span = l1;
    _a3_obj->f_id = INT64_C(0);
    _a3_obj->f_target = l5;
    _a3_obj->f_value = vader_ref_box(l7);
    t1 = (void*) _a3_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_parser$parse_string_lit(void* l0) {
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
    l1 = vader_front_parser$advance(l0);
    vader_array_t* _a0_arr = vader_array_new(356u, 0u, 13u, 1799u);
    l2 = (void*) _a0_arr;
    for (;;) {
        t0 = vader_front_parser$check(l0, (uint8_t) 8);
        if (!(t0)) {
            t0 = vader_front_parser$check(l0, (uint8_t) 0);
            if (t0) break;
            l3 = vader_front_parser$peek(l0);
            if (((vader_struct_vader_front_lexer$Token_t*) l3)->f_kind == INT32_C(7)) {
                vader_front_parser$advance(l0);
                l4 = ((vader_struct_vader_front_lexer$Token_t*) l3)->f_text;
                l5 = ((vader_struct_vader_front_lexer$Token_t*) l3)->f_value;
                if (l5.tag == 447u) {
                    l4 = l5.payload.s;
                }
                l6 = ((vader_struct_vader_front_lexer$Token_t*) l3)->f_span;
                vader_struct_toolchain_ast$StringLitText_t* _a1_obj = (vader_struct_toolchain_ast$StringLitText_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$StringLitText_t));
                vader_obj_header_init(_a1_obj, 815u);
                _a1_obj->f_value = l4;
                _a1_obj->f_span = l6;
                _a1_obj->f_id = INT64_C(0);
                l7 = (void*) _a1_obj;
                vader_array_push_ref((vader_array_t*) l2, l7);
                continue;
            }
            if (((vader_struct_vader_front_lexer$Token_t*) l3)->f_kind == INT32_C(9)) {
                l8 = vader_front_parser$advance(l0);
                l9 = vader_front_parser$parse_expr(l0, INT32_C(0));
                l10 = vader_front_parser$match_kind(l0, (uint8_t) 10);
                if (l10.tag == 0u) {
                    l11 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l9.payload.obj);
                } else {
                    t1 = l10.payload.obj;
                    l11 = ((vader_struct_vader_front_lexer$Token_t*) t1)->f_span;
                }
                l12 = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_front_lexer$Token_t*) l8)->f_span)->f_start;
                l13 = ((vader_struct_toolchain_span$Span_t*) l11)->f_end;
                vader_struct_toolchain_span$Span_t* _a2_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
                vader_obj_header_init(_a2_obj, 835u);
                _a2_obj->f_start = l12;
                _a2_obj->f_end = l13;
                l14 = (void*) _a2_obj;
                vader_struct_toolchain_ast$StringLitInterp_t* _a3_obj = (vader_struct_toolchain_ast$StringLitInterp_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$StringLitInterp_t));
                vader_obj_header_init(_a3_obj, 814u);
                _a3_obj->f_expr = l9;
                _a3_obj->f_span = l14;
                _a3_obj->f_id = INT64_C(0);
                l15 = (void*) _a3_obj;
                vader_array_push_ref((vader_array_t*) l2, l15);
                continue;
            }
            l16 = ((vader_struct_vader_front_lexer$Token_t*) l3)->f_span;
            vader_front_parser$error(l0, (uint8_t) 0, l16, 2168u);
            vader_front_parser$advance(l0);
            continue;
        }
        break;
    }
    l3 = vader_front_parser$match_or_peek(l0, (uint8_t) 8);
    t1 = vader_front_parser$span_of(l0, l1, l3);
    vader_struct_toolchain_ast$StringLitExpr_t* _a4_obj = (vader_struct_toolchain_ast$StringLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$StringLitExpr_t));
    vader_obj_header_init(_a4_obj, 813u);
    _a4_obj->f_span = t1;
    _a4_obj->f_id = INT64_C(0);
    _a4_obj->f_parts = l2;
    t1 = (void*) _a4_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_parser$parse_struct_decl(void* l0, void* l1, uint8_t l2, void* l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    void* l8 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l19 = NULL;
    void* l20 = NULL;
    void* l22 = NULL;
    vader_box_t l6 = vader_box_null(), l17 = vader_box_null(), l18 = vader_box_null();
    uint8_t l7;
    int64_t l9, l10;
    vader_string_t l13 = 0;
    vader_string_t l14 = 0;
    vader_string_t l21 = 0;
    bool t0;
    vader_string_t t1 = 0;
    vader_box_t t2 = vader_box_null();
    void* t3 = NULL;
    vader_box_t* gc_roots[4] = { &l6, &l17, &l18, &t2 };
    void** gc_raw_roots[14] = {
        &l0, &l1, &l3, &l4, &l5, &l8, &l11, &l12, &l15, &l16, &l19, &l20, &l22, &t3,
    };
    vader_string_t* gc_atom_roots[4] = { &l13, &l14, &l21, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 14u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_front_parser$reject_free_fn_decorators(l0, l1, 1487u, 0u);
    vader_front_parser$advance(l0);
    l4 = vader_front_parser$parse_angle_type_params(l0);
    vader_front_parser$expect(l0, (uint8_t) 83, 1401u);
    vader_front_parser$skip_newlines(l0);
    vader_array_t* _a0_arr = vader_array_new(55u, 0u, 13u, 817u);
    l5 = (void*) _a0_arr;
    for (;;) {
        t0 = vader_front_parser$check(l0, (uint8_t) 84);
        if (!(t0)) {
            t0 = vader_front_parser$check(l0, (uint8_t) 0);
            if (t0) break;
            l6 = vader_front_parser$take_doc(l0);
            l8 = vader_front_parser$parse_decorators(l0);
            l7 = (uint8_t) 0;
            l9 = ((vader_array_t*) l8)->length;
            l10 = INT64_C(0);
            while ((l10 < l9)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l8);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                l11 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l10);
                t1 = ((vader_struct_toolchain_ast$Decorator_t*) l11)->f_name;
                t0 = vader_front_parser$decorator_on(t1, (uint8_t) 3);
                if (t0) {
                    l7 = (uint8_t) 1;
                } else {
                    l12 = ((vader_struct_toolchain_ast$Decorator_t*) l11)->f_span;
                    l13 = ((vader_struct_toolchain_ast$Decorator_t*) l11)->f_name;
                    l14 = concat_3(1327u, l13, 1078u);
                    vader_front_parser$error(l0, (uint8_t) 8, l12, l14);
                }
                l10 = (l10 + INT64_C(1));
            }
            l15 = vader_front_parser$peek(l0);
            l16 = vader_front_parser$expect(l0, (uint8_t) 2, 1988u);
            vader_front_parser$expect(l0, (uint8_t) 87, 1315u);
            l17 = vader_front_parser$parse_type(l0);
            l18 = vader_box_obj(0u, NULL);
            t2 = vader_front_parser$match_kind(l0, (uint8_t) 62);
            if (!(t2.tag == 0u)) {
                vader_front_parser$skip_newlines(l0);
                l18 = vader_front_parser$parse_expr(l0, INT32_C(0));
            }
            l19 = vader_front_parser$peek_at(l0, INT32_C(-1));
            l20 = vader_front_parser$span_of(l0, l15, l19);
            l21 = ((vader_struct_vader_front_lexer$Token_t*) l16)->f_text;
            vader_struct_toolchain_ast$StructField_t* _a2_obj = (vader_struct_toolchain_ast$StructField_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$StructField_t));
            vader_obj_header_init(_a2_obj, 817u);
            _a2_obj->f_span = l20;
            _a2_obj->f_id = INT64_C(0);
            _a2_obj->f_name = l21;
            _a2_obj->f_ty = l17;
            _a2_obj->f_visibility = l7;
            _a2_obj->f_default = l18;
            _a2_obj->f_doc = l6;
            l22 = (void*) _a2_obj;
            vader_array_push_ref((vader_array_t*) l5, l22);
            t0 = vader_front_parser$check(l0, (uint8_t) 84);
            if (t0) {
                continue;
            }
            vader_front_parser$match_kind(l0, (uint8_t) 85);
            vader_front_parser$skip_newlines(l0);
            continue;
        }
        break;
    }
    l8 = vader_front_parser$expect(l0, (uint8_t) 84, 1409u);
    l8 = vader_front_parser$span_of(l0, l3, l8);
    l13 = ((vader_struct_vader_front_lexer$Token_t*) l3)->f_text;
    l11 = ((vader_struct_vader_front_lexer$Token_t*) l3)->f_span;
    vader_struct_toolchain_ast$StructDecl_t* _a3_obj = (vader_struct_toolchain_ast$StructDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$StructDecl_t));
    vader_obj_header_init(_a3_obj, 816u);
    _a3_obj->f_span = l8;
    _a3_obj->f_id = INT64_C(0);
    _a3_obj->f_name = l13;
    _a3_obj->f_name_span = l11;
    _a3_obj->f_visibility = l2;
    _a3_obj->f_type_params = l4;
    _a3_obj->f_fields = l5;
    _a3_obj->f_decorators = l1;
    _a3_obj->f_doc = vader_box_obj(0u, NULL);
    t3 = (void*) _a3_obj;
    { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_parser$parse_struct_lit_fields(void* l0) {
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
    vader_array_t* _a0_arr = vader_array_new(357u, 0u, 13u, 1800u);
    l1 = (void*) _a0_arr;
    l2 = false;
    vader_front_parser$skip_newlines(l0);
    for (;;) {
        t0 = vader_front_parser$check(l0, (uint8_t) 84);
        if (!(t0)) {
            t0 = vader_front_parser$check(l0, (uint8_t) 0);
            if (t0) break;
            l3 = vader_front_parser$peek(l0);
            t1 = vader_front_parser$match_kind(l0, (uint8_t) 75);
            if (t1.tag == 0u) {
                vader_front_parser$expect(l0, (uint8_t) 86, 1308u);
                l7 = vader_front_parser$expect(l0, (uint8_t) 2, 2658u);
                vader_front_parser$expect(l0, (uint8_t) 62, 1320u);
                l8 = vader_front_parser$parse_expr(l0, INT32_C(0));
                l9 = vader_front_parser$peek_at(l0, INT32_C(-1));
                l10 = vader_front_parser$span_of(l0, l3, l9);
                l11 = ((vader_struct_vader_front_lexer$Token_t*) l7)->f_text;
                l12 = ((vader_struct_vader_front_lexer$Token_t*) l7)->f_span;
                vader_struct_toolchain_ast$StructLitField_t* _a1_obj = (vader_struct_toolchain_ast$StructLitField_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$StructLitField_t));
                vader_obj_header_init(_a1_obj, 819u);
                _a1_obj->f_span = l10;
                _a1_obj->f_id = INT64_C(0);
                _a1_obj->f_name = l11;
                _a1_obj->f_name_span = l12;
                _a1_obj->f_value = l8;
                l13 = (void*) _a1_obj;
                vader_array_push_ref((vader_array_t*) l1, l13);
            } else {
                l4 = vader_front_parser$parse_expr(l0, INT32_C(0));
                l5 = vader_front_parser$peek_at(l0, INT32_C(-1));
                t2 = vader_front_parser$span_of(l0, l3, l5);
                vader_struct_toolchain_ast$StructLitSpread_t* _a2_obj = (vader_struct_toolchain_ast$StructLitSpread_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$StructLitSpread_t));
                vader_obj_header_init(_a2_obj, 820u);
                _a2_obj->f_span = t2;
                _a2_obj->f_id = INT64_C(0);
                _a2_obj->f_expr = l4;
                l6 = (void*) _a2_obj;
                vader_array_push_ref((vader_array_t*) l1, l6);
            }
            vader_front_parser$skip_newlines(l0);
            t1 = vader_front_parser$match_kind(l0, (uint8_t) 85);
            if (t1.tag == 0u) break;
            vader_front_parser$skip_newlines(l0);
            l2 = vader_front_parser$check(l0, (uint8_t) 84);
            continue;
        }
        break;
    }
    vader_front_parser$skip_newlines(l0);
    vader_struct_vader_front_parser$CommaList__Any_t* _a3_obj = (vader_struct_vader_front_parser$CommaList__Any_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_parser$CommaList__Any_t));
    vader_obj_header_init(_a3_obj, 1192u);
    _a3_obj->f_items = l1;
    _a3_obj->f_trailing_comma = l2;
    t2 = (void*) _a3_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_parser$parse_struct_pattern(void* l0) {
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
    l1 = vader_front_parser$expect(l0, (uint8_t) 83, 1402u);
    vader_front_parser$skip_newlines(l0);
    vader_array_t* _a0_arr = vader_array_new(57u, 0u, 13u, 822u);
    l2 = (void*) _a0_arr;
    for (;;) {
        t0 = vader_front_parser$check(l0, (uint8_t) 84);
        if (!(t0)) {
            t0 = vader_front_parser$check(l0, (uint8_t) 0);
            if (t0) break;
            l3 = vader_front_parser$peek(l0);
            l4 = vader_front_parser$expect(l0, (uint8_t) 2, 1991u);
            l5 = ((vader_struct_vader_front_lexer$Token_t*) l4)->f_text;
            l6 = ((vader_struct_vader_front_lexer$Token_t*) l4)->f_span;
            vader_struct_toolchain_ast$PatternBinding_t* _a1_obj = (vader_struct_toolchain_ast$PatternBinding_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$PatternBinding_t));
            vader_obj_header_init(_a1_obj, 802u);
            _a1_obj->f_name = l5;
            _a1_obj->f_span = l6;
            _a1_obj->f_id = INT64_C(0);
            t1 = (void*) _a1_obj;
            l7 = vader_ref_box(t1);
            t2 = vader_front_parser$match_kind(l0, (uint8_t) 87);
            if (!(t2.tag == 0u)) {
                t0 = vader_front_parser$check(l0, (uint8_t) 2);
                if (t0) {
                    t1 = vader_front_parser$peek_at(l0, INT32_C(1));
                    t0 = vader_front_parser$is_literal_start(t1);
                    l8 = !(t0);
                } else {
                    l8 = false;
                }
                if (l8) {
                    l9 = vader_front_parser$advance(l0);
                    l10 = ((vader_struct_vader_front_lexer$Token_t*) l9)->f_text;
                    l11 = ((vader_struct_vader_front_lexer$Token_t*) l9)->f_span;
                    vader_struct_toolchain_ast$PatternBinding_t* _a2_obj = (vader_struct_toolchain_ast$PatternBinding_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$PatternBinding_t));
                    vader_obj_header_init(_a2_obj, 802u);
                    _a2_obj->f_name = l10;
                    _a2_obj->f_span = l11;
                    _a2_obj->f_id = INT64_C(0);
                    t1 = (void*) _a2_obj;
                    l7 = vader_ref_box(t1);
                } else {
                    t2 = vader_front_parser$parse_expr(l0, INT32_C(0));
                    vader_struct_toolchain_ast$PatternLiteral_t* _a3_obj = (vader_struct_toolchain_ast$PatternLiteral_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$PatternLiteral_t));
                    vader_obj_header_init(_a3_obj, 803u);
                    _a3_obj->f_value = t2;
                    t1 = (void*) _a3_obj;
                    l7 = vader_ref_box(t1);
                }
            }
            l12 = vader_front_parser$peek_at(l0, INT32_C(-1));
            l13 = vader_front_parser$span_of(l0, l3, l12);
            l14 = ((vader_struct_vader_front_lexer$Token_t*) l4)->f_text;
            l15 = ((vader_struct_vader_front_lexer$Token_t*) l4)->f_span;
            vader_struct_toolchain_ast$StructPatternField_t* _a4_obj = (vader_struct_toolchain_ast$StructPatternField_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$StructPatternField_t));
            vader_obj_header_init(_a4_obj, 822u);
            _a4_obj->f_span = l13;
            _a4_obj->f_id = INT64_C(0);
            _a4_obj->f_name = l14;
            _a4_obj->f_name_span = l15;
            _a4_obj->f_value = l7;
            l16 = (void*) _a4_obj;
            vader_array_push_ref((vader_array_t*) l2, l16);
            vader_front_parser$skip_newlines(l0);
            t2 = vader_front_parser$match_kind(l0, (uint8_t) 85);
            if (t2.tag == 0u) break;
            vader_front_parser$skip_newlines(l0);
            continue;
        }
        break;
    }
    l3 = vader_front_parser$expect(l0, (uint8_t) 84, 1411u);
    l1 = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_front_lexer$Token_t*) l1)->f_span)->f_start;
    l3 = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_front_lexer$Token_t*) l3)->f_span)->f_end;
    vader_struct_toolchain_span$Span_t* _a5_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
    vader_obj_header_init(_a5_obj, 835u);
    _a5_obj->f_start = l1;
    _a5_obj->f_end = l3;
    t1 = (void*) _a5_obj;
    vader_struct_toolchain_ast$StructPattern_t* _a6_obj = (vader_struct_toolchain_ast$StructPattern_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$StructPattern_t));
    vader_obj_header_init(_a6_obj, 821u);
    _a6_obj->f_span = t1;
    _a6_obj->f_id = INT64_C(0);
    _a6_obj->f_fields = l2;
    t1 = (void*) _a6_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_parser$parse_trait_decl(void* l0, void* l1, uint8_t l2, void* l3) {
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
    vader_front_parser$reject_free_fn_decorators(l0, l1, 1488u, 0u);
    vader_front_parser$reject_c_decorators(l0, l1, 1488u);
    vader_front_parser$advance(l0);
    l4 = vader_front_parser$parse_angle_type_params(l0);
    l5 = vader_box_obj(0u, NULL);
    vader_array_t* _a0_arr = vader_array_new(47u, 0u, 13u, 773u);
    l6 = (void*) _a0_arr;
    t0 = vader_front_parser$match_kind(l0, (uint8_t) 62);
    if (!(t0.tag == 0u)) {
        l5 = vader_front_parser$parse_type(l0);
        l7 = vader_front_parser$peek_at(l0, INT32_C(-1));
        l7 = vader_front_parser$span_of(l0, l3, l7);
        l8 = ((vader_struct_vader_front_lexer$Token_t*) l3)->f_text;
        l9 = ((vader_struct_vader_front_lexer$Token_t*) l3)->f_span;
        vader_struct_toolchain_ast$TraitDecl_t* _a1_obj = (vader_struct_toolchain_ast$TraitDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$TraitDecl_t));
        vader_obj_header_init(_a1_obj, 823u);
        _a1_obj->f_span = l7;
        _a1_obj->f_id = INT64_C(0);
        _a1_obj->f_name = l8;
        _a1_obj->f_name_span = l9;
        _a1_obj->f_visibility = l2;
        _a1_obj->f_type_params = l4;
        _a1_obj->f_requires = l5;
        _a1_obj->f_members = l6;
        _a1_obj->f_decorators = l1;
        _a1_obj->f_doc = vader_box_obj(0u, NULL);
        t1 = (void*) _a1_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_front_parser$match_kind(l0, (uint8_t) 87);
    if (!(t0.tag == 0u)) {
        l5 = vader_front_parser$parse_type(l0);
    }
    vader_front_parser$expect(l0, (uint8_t) 83, 1403u);
    vader_front_parser$skip_newlines(l0);
    for (;;) {
        t2 = vader_front_parser$check(l0, (uint8_t) 84);
        if (!(t2)) {
            t2 = vader_front_parser$check(l0, (uint8_t) 0);
            if (t2) break;
            l10 = vader_front_parser$parse_fn_decl_inside_trait(l0);
            if (l10.tag == 773u) {
                l7 = l10.payload.obj;
                vader_array_push_ref((vader_array_t*) l6, l7);
            } else if (!(l10.tag == 0u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            vader_front_parser$skip_newlines(l0);
            continue;
        }
        break;
    }
    l7 = vader_front_parser$expect(l0, (uint8_t) 84, 1412u);
    l7 = vader_front_parser$span_of(l0, l3, l7);
    l8 = ((vader_struct_vader_front_lexer$Token_t*) l3)->f_text;
    l9 = ((vader_struct_vader_front_lexer$Token_t*) l3)->f_span;
    vader_struct_toolchain_ast$TraitDecl_t* _a2_obj = (vader_struct_toolchain_ast$TraitDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$TraitDecl_t));
    vader_obj_header_init(_a2_obj, 823u);
    _a2_obj->f_span = l7;
    _a2_obj->f_id = INT64_C(0);
    _a2_obj->f_name = l8;
    _a2_obj->f_name_span = l9;
    _a2_obj->f_visibility = l2;
    _a2_obj->f_type_params = l4;
    _a2_obj->f_requires = l5;
    _a2_obj->f_members = l6;
    _a2_obj->f_decorators = l1;
    _a2_obj->f_doc = vader_box_obj(0u, NULL);
    t1 = (void*) _a2_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_parser$parse_tuple_let(void* l0) {
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
    l1 = vader_front_parser$peek(l0);
    l2 = vader_front_parser$parse_let_binding(l0);
    l3 = vader_box_obj(0u, NULL);
    l4 = true;
    t0 = vader_front_parser$check(l0, (uint8_t) 87);
    if (t0) {
        vader_front_parser$advance(l0);
        l3 = vader_front_parser$parse_type(l0);
        t1 = vader_front_parser$peek(l0);
        if (((vader_struct_vader_front_lexer$Token_t*) t1)->f_kind == INT32_C(87)) {
            vader_front_parser$advance(l0);
            l4 = false;
        } else {
            vader_front_parser$expect(l0, (uint8_t) 62, 1321u);
        }
    } else {
        l5 = vader_front_parser$peek(l0);
        if (((vader_struct_vader_front_lexer$Token_t*) l5)->f_kind == INT32_C(71)) {
            l6 = true;
        } else {
            l6 = ((vader_struct_vader_front_lexer$Token_t*) l5)->f_kind == INT32_C(72);
        }
        if (l6) {
            vader_front_parser$advance(l0);
            l4 = ((vader_struct_vader_front_lexer$Token_t*) l5)->f_kind == INT32_C(72);
        } else {
            vader_front_parser$expect(l0, (uint8_t) 72, 1314u);
        }
    }
    l7 = vader_front_parser$parse_expr(l0, INT32_C(0));
    l5 = vader_front_parser$peek_at(l0, INT32_C(-1));
    t1 = vader_front_parser$span_of(l0, l1, l5);
    vader_struct_toolchain_ast$LetStmt_t* _a0_obj = (vader_struct_toolchain_ast$LetStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$LetStmt_t));
    vader_obj_header_init(_a0_obj, 792u);
    _a0_obj->f_span = t1;
    _a0_obj->f_id = INT64_C(0);
    _a0_obj->f_mutable = l4;
    _a0_obj->f_binding = l2;
    _a0_obj->f_ty = l3;
    _a0_obj->f_value = l7;
    t1 = (void*) _a0_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_parser$parse_type(void* l0) {
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
    t0 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_expr_depth;
    l1 = vader_chk_add(i32, t0, INT32_C(1));
    ((vader_struct_vader_front_parser$Parser_t*) l0)->f_expr_depth = l1;
    t0 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_expr_depth;
    if ((t0 > INT32_C(256))) {
        t0 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_expr_depth;
        l1 = vader_chk_sub(i32, t0, INT32_C(1));
        ((vader_struct_vader_front_parser$Parser_t*) l0)->f_expr_depth = l1;
        t1 = vader_front_parser$peek(l0);
        l2 = ((vader_struct_vader_front_lexer$Token_t*) t1)->f_span;
        vader_front_parser$report_nesting_too_deep(l0, 2749u);
        t1 = vader_front_parser$ident_expr(l2, 530u);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_front_parser$match_kind(l0, (uint8_t) 45);
    vader_front_parser$reject_removed_const(l0);
    l3 = vader_front_parser$parse_type_intersection(l0);
    t2 = vader_front_parser$check(l0, (uint8_t) 45);
    if (t2) {
        l2 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l3.payload.obj);
        for (;;) {
            t3 = vader_front_parser$match_kind(l0, (uint8_t) 45);
            if (!(t3.tag == 0u)) {
                vader_front_parser$reject_removed_const(l0);
                l4 = vader_front_parser$parse_type_intersection(l0);
                l5 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l4.payload.obj);
                l6 = ((vader_struct_toolchain_span$Span_t*) l2)->f_start;
                l7 = ((vader_struct_toolchain_span$Span_t*) l5)->f_end;
                vader_struct_toolchain_span$Span_t* _a0_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
                vader_obj_header_init(_a0_obj, 835u);
                _a0_obj->f_start = l6;
                _a0_obj->f_end = l7;
                t1 = (void*) _a0_obj;
                vader_struct_toolchain_ast$BinaryExpr_t* _a1_obj = (vader_struct_toolchain_ast$BinaryExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$BinaryExpr_t));
                vader_obj_header_init(_a1_obj, 746u);
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
    t0 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_expr_depth;
    l1 = vader_chk_sub(i32, t0, INT32_C(1));
    ((vader_struct_vader_front_parser$Parser_t*) l0)->f_expr_depth = l1;
    { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_parser$parse_type_intersection(void* l0) {
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
    l1 = vader_front_parser$parse_type_postfix(l0);
    t0 = vader_front_parser$check(l0, (uint8_t) 44);
    if (t0) {
        l2 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l1.payload.obj);
        for (;;) {
            t1 = vader_front_parser$match_kind(l0, (uint8_t) 44);
            if (!(t1.tag == 0u)) {
                l3 = vader_front_parser$parse_type_postfix(l0);
                l4 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l3.payload.obj);
                l5 = ((vader_struct_toolchain_span$Span_t*) l2)->f_start;
                l6 = ((vader_struct_toolchain_span$Span_t*) l4)->f_end;
                vader_struct_toolchain_span$Span_t* _a0_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
                vader_obj_header_init(_a0_obj, 835u);
                _a0_obj->f_start = l5;
                _a0_obj->f_end = l6;
                t2 = (void*) _a0_obj;
                vader_struct_toolchain_ast$BinaryExpr_t* _a1_obj = (vader_struct_toolchain_ast$BinaryExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$BinaryExpr_t));
                vader_obj_header_init(_a1_obj, 746u);
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

static void* vader_front_parser$parse_type_list_until_angle(void* l0) {
    void* l1 = NULL;
    vader_box_t l2 = vader_box_null();
    bool t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l2, &t1 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(349u, 0u, 13u, 1716u);
    l1 = (void*) _a0_arr;
    vader_front_parser$skip_newlines(l0);
    t0 = vader_front_parser$check_closing_angle(l0);
    if (t0) {
        vader_front_parser$consume_closing_angle(l0);
        { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    for (;;) {
        vader_front_parser$skip_newlines(l0);
        t0 = vader_front_parser$check_closing_angle(l0);
        if (!(t0)) {
            l2 = vader_front_parser$parse_type(l0);
            vader_array_push_ref((vader_array_t*) l1, l2.payload.obj);
            vader_front_parser$skip_newlines(l0);
            t1 = vader_front_parser$match_kind(l0, (uint8_t) 85);
            if (t1.tag == 0u) break;
            continue;
        }
        break;
    }
    t0 = vader_front_parser$check_closing_angle(l0);
    if (t0) {
        vader_front_parser$consume_closing_angle(l0);
        { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_front_parser$expect(l0, (uint8_t) 54, 1322u);
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_parser$parse_type_postfix(void* l0) {
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
    l1 = vader_front_parser$parse_type_primary(l0);
    for (;;) {
        t0 = vader_front_parser$check(l0, (uint8_t) 81);
        if (t0) {
            t0 = vader_front_parser$check_at(l0, (uint8_t) 82, INT32_C(1));
            if (!(t0)) {
                break;
            }
            vader_front_parser$advance(l0);
            l2 = vader_front_parser$advance(l0);
            l3 = ((vader_struct_toolchain_span$Span_t*) VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l1.payload.obj))->f_start;
            l4 = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_front_lexer$Token_t*) l2)->f_span)->f_end;
            vader_struct_toolchain_span$Span_t* _a0_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
            vader_obj_header_init(_a0_obj, 835u);
            _a0_obj->f_start = l3;
            _a0_obj->f_end = l4;
            t1 = (void*) _a0_obj;
            vader_struct_toolchain_ast$ArrayTypeExpr_t* _a1_obj = (vader_struct_toolchain_ast$ArrayTypeExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$ArrayTypeExpr_t));
            vader_obj_header_init(_a1_obj, 742u);
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

static vader_box_t vader_front_parser$parse_type_primary(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    vader_box_t l2 = vader_box_null();
    vader_string_t l7 = 0;
    bool l10, l11;
    void* t0 = NULL;
    bool t1;
    vader_box_t t2 = vader_box_null();
    int64_t t3;
    vader_box_t* gc_roots[2] = { &l2, &t2 };
    void** gc_raw_roots[9] = { &l0, &l1, &l3, &l4, &l5, &l6, &l8, &l9, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_front_parser$peek(l0);
    if (((vader_struct_vader_front_lexer$Token_t*) l1)->f_kind == INT32_C(11)) {
        t0 = vader_front_parser$parse_fn_type(l0);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_front_lexer$Token_t*) l1)->f_kind == INT32_C(79)) {
        vader_front_parser$advance(l0);
        vader_front_parser$skip_newlines(l0);
        l2 = vader_front_parser$parse_type(l0);
        vader_front_parser$skip_newlines(l0);
        vader_front_parser$expect(l0, (uint8_t) 80, 1278u);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_front_lexer$Token_t*) l1)->f_kind == INT32_C(81)) {
        l3 = vader_front_parser$advance(l0);
        vader_array_t* _a0_arr = vader_array_new(349u, 0u, 13u, 1716u);
        l4 = (void*) _a0_arr;
        vader_front_parser$skip_newlines(l0);
        t1 = vader_front_parser$check(l0, (uint8_t) 82);
        if (t1) {
            l5 = ((vader_struct_vader_front_lexer$Token_t*) l1)->f_span;
            vader_front_parser$error(l0, (uint8_t) 3, l5, 1874u);
            l5 = vader_front_parser$advance(l0);
            t0 = vader_front_parser$span_of(l0, l3, l5);
            vader_struct_toolchain_ast$SeqLitExpr_t* _a1_obj = (vader_struct_toolchain_ast$SeqLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$SeqLitExpr_t));
            vader_obj_header_init(_a1_obj, 811u);
            _a1_obj->f_span = t0;
            _a1_obj->f_id = INT64_C(0);
            _a1_obj->f_elements = l4;
            _a1_obj->f_trailing_comma = false;
            t0 = (void*) _a1_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l2 = vader_front_parser$parse_type(l0);
        vader_array_push_ref((vader_array_t*) l4, l2.payload.obj);
        vader_front_parser$skip_newlines(l0);
        for (;;) {
            t2 = vader_front_parser$match_kind(l0, (uint8_t) 85);
            if (!(t2.tag == 0u)) {
                vader_front_parser$skip_newlines(l0);
                t1 = vader_front_parser$check(l0, (uint8_t) 82);
                if (t1) break;
                l2 = vader_front_parser$parse_type(l0);
                vader_array_push_ref((vader_array_t*) l4, l2.payload.obj);
                vader_front_parser$skip_newlines(l0);
                continue;
            }
            break;
        }
        l5 = vader_front_parser$expect(l0, (uint8_t) 82, 1370u);
        t3 = ((vader_array_t*) l4)->length;
        if (!(t3 == INT64_C(1))) {
            t0 = vader_front_parser$span_of(l0, l3, l5);
            vader_struct_toolchain_ast$SeqLitExpr_t* _a2_obj = (vader_struct_toolchain_ast$SeqLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$SeqLitExpr_t));
            vader_obj_header_init(_a2_obj, 811u);
            _a2_obj->f_span = t0;
            _a2_obj->f_id = INT64_C(0);
            _a2_obj->f_elements = l4;
            _a2_obj->f_trailing_comma = false;
            t0 = (void*) _a2_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l6 = vader_front_parser$span_of(l0, l3, l5);
        vader_front_parser$error(l0, (uint8_t) 10, l6, 2847u);
        l3 = vader_front_parser$span_of(l0, l3, l5);
        vader_array_t* _a3_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        l2 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) INT32_C(0));
        vader_struct_toolchain_ast$ArrayTypeExpr_t* _a4_obj = (vader_struct_toolchain_ast$ArrayTypeExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$ArrayTypeExpr_t));
        vader_obj_header_init(_a4_obj, 742u);
        _a4_obj->f_span = l3;
        _a4_obj->f_id = INT64_C(0);
        _a4_obj->f_element = l2;
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_front_lexer$Token_t*) l1)->f_kind == INT32_C(33)) {
        vader_front_parser$advance(l0);
        t0 = vader_front_parser$ident_expr(((vader_struct_vader_front_lexer$Token_t*) l1)->f_span, 2413u);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_front_lexer$Token_t*) l1)->f_kind == INT32_C(2)) {
        l3 = vader_front_parser$advance(l0);
        l4 = ((vader_struct_vader_front_lexer$Token_t*) l3)->f_span;
        l7 = ((vader_struct_vader_front_lexer$Token_t*) l3)->f_text;
        t0 = vader_front_parser$ident_expr(l4, l7);
        l2 = vader_ref_box(t0);
        for (;;) {
            t1 = vader_front_parser$check(l0, (uint8_t) 86);
            if (t1) {
                vader_front_parser$advance(l0);
                l4 = vader_front_parser$expect(l0, (uint8_t) 2, 1990u);
                l5 = ((vader_struct_toolchain_span$Span_t*) VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l2.payload.obj))->f_start;
                l6 = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_front_lexer$Token_t*) l4)->f_span)->f_end;
                vader_struct_toolchain_span$Span_t* _a5_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
                vader_obj_header_init(_a5_obj, 835u);
                _a5_obj->f_start = l5;
                _a5_obj->f_end = l6;
                l8 = (void*) _a5_obj;
                l7 = ((vader_struct_vader_front_lexer$Token_t*) l4)->f_text;
                l9 = ((vader_struct_vader_front_lexer$Token_t*) l4)->f_span;
                vader_struct_toolchain_ast$FieldExpr_t* _a6_obj = (vader_struct_toolchain_ast$FieldExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$FieldExpr_t));
                vader_obj_header_init(_a6_obj, 771u);
                _a6_obj->f_span = l8;
                _a6_obj->f_id = INT64_C(0);
                _a6_obj->f_target = l2;
                _a6_obj->f_field = l7;
                _a6_obj->f_field_span = l9;
                _a6_obj->f_is_numeric = false;
                t0 = (void*) _a6_obj;
                l2 = vader_ref_box(t0);
                continue;
            }
            break;
        }
        t2 = vader_front_parser$match_kind(l0, (uint8_t) 52);
        if (!(t2.tag == 0u)) {
            l4 = vader_front_parser$parse_type_list_until_angle(l0);
            l5 = vader_front_parser$peek_at(l0, INT32_C(-1));
            t0 = vader_front_parser$span_of(l0, l3, l5);
            vader_struct_toolchain_ast$GenericInstExpr_t* _a7_obj = (vader_struct_toolchain_ast$GenericInstExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$GenericInstExpr_t));
            vader_obj_header_init(_a7_obj, 777u);
            _a7_obj->f_span = t0;
            _a7_obj->f_id = INT64_C(0);
            _a7_obj->f_callee = l2;
            _a7_obj->f_type_args = l4;
            t0 = (void*) _a7_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_front_lexer$Token_t*) l1)->f_kind == INT32_C(3)) {
        l10 = true;
    } else {
        if (((vader_struct_vader_front_lexer$Token_t*) l1)->f_kind == INT32_C(37)) {
            t0 = vader_front_parser$peek_at(l0, INT32_C(1));
            l11 = ((vader_struct_vader_front_lexer$Token_t*) t0)->f_kind == INT32_C(3);
        } else {
            l11 = false;
        }
        l10 = l11;
    }
    if (!(l10)) {
        l3 = ((vader_struct_vader_front_lexer$Token_t*) l1)->f_span;
        l7 = vader_front_parser$describe_token(l1);
        l7 = concat_2(2065u, l7);
        vader_front_parser$error(l0, (uint8_t) 3, l3, l7);
        vader_front_parser$advance(l0);
        t0 = vader_front_parser$ident_expr(((vader_struct_vader_front_lexer$Token_t*) l1)->f_span, 530u);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_front_parser$parse_range_type(l0);
    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_parser$parse_typed_const_decl(void* l0, void* l1, uint8_t l2) {
    void* l3 = NULL;
    void* l7 = NULL;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null(), l6 = vader_box_null();
    vader_string_t l8 = 0;
    bool t0;
    void* t1 = NULL;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[3] = { &l4, &l5, &l6 };
    void** gc_raw_roots[5] = { &l0, &l1, &l3, &l7, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l8, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_front_parser$reject_free_fn_decorators(l0, l1, 1437u, 79u);
    l3 = vader_front_parser$advance(l0);
    vader_front_parser$advance(l0);
    l4 = vader_front_parser$parse_type(l0);
    vader_front_parser$expect(l0, (uint8_t) 87, 1316u);
    t0 = vader_front_parser$check(l0, (uint8_t) 78);
    if (t0) {
        t1 = vader_front_parser$peek_at(l0, INT32_C(1));
        if (((vader_struct_vader_front_lexer$Token_t*) t1)->f_kind == INT32_C(2)) {
            t1 = vader_front_parser$peek_at(l0, INT32_C(1));
            t2 = ((vader_struct_vader_front_lexer$Token_t*) t1)->f_text;
            if (t2 == 1778u) {
                t1 = vader_front_parser$desugar_comptime_const(l0, l1, l2, l3, l4);
                { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
    }
    l5 = vader_front_parser$parse_expr(l0, INT32_C(0));
    l6 = vader_front_parser$comptime_helper_marker(l1, l5);
    if (!(l6.tag == 0u)) {
        l7 = l6.payload.obj;
        t1 = vader_front_parser$through_comptime_helper(l0, l1, l2, l3, l4, l5, l7, true);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l7 = vader_front_parser$peek_at(l0, INT32_C(-1));
    l7 = vader_front_parser$span_of(l0, l3, l7);
    l8 = ((vader_struct_vader_front_lexer$Token_t*) l3)->f_text;
    l3 = ((vader_struct_vader_front_lexer$Token_t*) l3)->f_span;
    vader_struct_toolchain_ast$ConstDecl_t* _a0_obj = (vader_struct_toolchain_ast$ConstDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$ConstDecl_t));
    vader_obj_header_init(_a0_obj, 754u);
    _a0_obj->f_span = l7;
    _a0_obj->f_id = INT64_C(0);
    _a0_obj->f_name = l8;
    _a0_obj->f_name_span = l3;
    _a0_obj->f_visibility = l2;
    _a0_obj->f_ty = l4;
    _a0_obj->f_value = l5;
    _a0_obj->f_decorators = l1;
    _a0_obj->f_comptime_body = vader_box_obj(0u, NULL);
    _a0_obj->f_comptime_as_decorator = false;
    _a0_obj->f_doc = vader_box_obj(0u, NULL);
    t1 = (void*) _a0_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_parser$parse_typed_let(void* l0) {
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
    l1 = vader_front_parser$advance(l0);
    vader_front_parser$advance(l0);
    l2 = vader_front_parser$parse_type(l0);
    l3 = vader_front_parser$peek(l0);
    l4 = true;
    if (((vader_struct_vader_front_lexer$Token_t*) l3)->f_kind == INT32_C(87)) {
        vader_front_parser$advance(l0);
        l4 = false;
    } else {
        vader_front_parser$expect(l0, (uint8_t) 62, 1321u);
    }
    l5 = vader_front_parser$parse_expr(l0, INT32_C(0));
    l3 = ((vader_struct_vader_front_lexer$Token_t*) l1)->f_span;
    l6 = ((vader_struct_vader_front_lexer$Token_t*) l1)->f_text;
    l7 = ((vader_struct_vader_front_lexer$Token_t*) l1)->f_span;
    vader_struct_toolchain_ast$SimpleBinding_t* _a0_obj = (vader_struct_toolchain_ast$SimpleBinding_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$SimpleBinding_t));
    vader_obj_header_init(_a0_obj, 812u);
    _a0_obj->f_span = l3;
    _a0_obj->f_id = INT64_C(0);
    _a0_obj->f_name = l6;
    _a0_obj->f_name_span = l7;
    l3 = (void*) _a0_obj;
    l7 = vader_front_parser$peek_at(l0, INT32_C(-1));
    t0 = vader_front_parser$span_of(l0, l1, l7);
    vader_struct_toolchain_ast$LetStmt_t* _a1_obj = (vader_struct_toolchain_ast$LetStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$LetStmt_t));
    vader_obj_header_init(_a1_obj, 792u);
    _a1_obj->f_span = t0;
    _a1_obj->f_id = INT64_C(0);
    _a1_obj->f_mutable = l4;
    _a1_obj->f_binding = vader_ref_box(l3);
    _a1_obj->f_ty = l2;
    _a1_obj->f_value = l5;
    t0 = (void*) _a1_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_parser$parse_yield(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    vader_box_t l2 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_front_parser$advance(l0);
    l2 = vader_front_parser$parse_expr(l0, INT32_C(0));
    l3 = vader_front_parser$peek_at(l0, INT32_C(-1));
    t0 = vader_front_parser$span_of(l0, l1, l3);
    vader_struct_toolchain_ast$YieldStmt_t* _a0_obj = (vader_struct_toolchain_ast$YieldStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$YieldStmt_t));
    vader_obj_header_init(_a0_obj, 833u);
    _a0_obj->f_span = t0;
    _a0_obj->f_id = INT64_C(0);
    _a0_obj->f_value = l2;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_parser$peek(void* l0) {
    vader_box_t l1;
    int32_t l2, l4;
    void* l3;
    void* t0;
    int64_t t1;
    int32_t t2;
    l1 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_shr_pending_half;
    if (!(l1.tag == 0u)) {
        t0 = l1.payload.obj;
        return t0;
    }
    t1 = ((vader_array_t*) ((vader_struct_vader_front_parser$Parser_t*) l0)->f_tokens)->length;
    l2 = ((int32_t) (int64_t) t1);
    t2 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_pos;
    if (!((t2 < l2))) {
        l3 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_tokens;
        l4 = vader_chk_sub(i32, l2, INT32_C(1));
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        return t0;
    }
    l3 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_tokens;
    l2 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_pos;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
    t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l2);
    return t0;
}

static void* vader_front_parser$peek_at(void* l0, int32_t l1) {
    vader_box_t l2;
    int32_t l3, l4;
    void* l5;
    void* t0;
    int64_t t1;
    int32_t t2;
    l2 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_split_half;
    if (l1 == INT32_C(-1)) {
        if (!(l2.tag == 0u)) {
            l3 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_pos;
            l4 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_split_at;
            if (l3 == l4) {
                t0 = l2.payload.obj;
                return t0;
            }
        }
    }
    t1 = ((vader_array_t*) ((vader_struct_vader_front_parser$Parser_t*) l0)->f_tokens)->length;
    l3 = ((int32_t) (int64_t) t1);
    t2 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_pos;
    l4 = vader_chk_add(i32, t2, l1);
    if ((l4 < INT32_C(0))) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_front_parser$Parser_t*) l0)->f_tokens);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
        return t0;
    }
    if (!((l4 < l3))) {
        l5 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_tokens;
        l3 = vader_chk_sub(i32, l3, INT32_C(1));
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
        return t0;
    }
    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_front_parser$Parser_t*) l0)->f_tokens);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
    t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
    return t0;
}

static bool vader_front_parser$peek_is_classic_impl_body(void* l0) {
    int32_t l1, l4;
    bool l2;
    uint8_t l3, l5;
    void* t0;
    l1 = INT32_C(1);
    for (;;) {
        t0 = vader_front_parser$peek_at(l0, l1);
        if (((vader_struct_vader_front_lexer$Token_t*) t0)->f_kind == INT32_C(1)) {
            l1 = vader_chk_add(i32, l1, INT32_C(1));
            continue;
        }
        break;
    }
    l2 = true;
    while (l2) {
        t0 = vader_front_parser$peek_at(l0, l1);
        l3 = ((vader_struct_vader_front_lexer$Token_t*) t0)->f_kind;
        if (l3 == INT32_C(78)) {
            l1 = vader_chk_add(i32, l1, INT32_C(1));
            t0 = vader_front_parser$peek_at(l0, l1);
            if (((vader_struct_vader_front_lexer$Token_t*) t0)->f_kind == INT32_C(2)) {
                l1 = vader_chk_add(i32, l1, INT32_C(1));
            }
            t0 = vader_front_parser$peek_at(l0, l1);
            if (((vader_struct_vader_front_lexer$Token_t*) t0)->f_kind == INT32_C(79)) {
                l4 = INT32_C(1);
                l1 = vader_chk_add(i32, l1, INT32_C(1));
                while ((l4 > INT32_C(0))) {
                    t0 = vader_front_parser$peek_at(l0, l1);
                    if (!(((vader_struct_vader_front_lexer$Token_t*) t0)->f_kind != INT32_C(0))) {
                        break;
                    }
                    t0 = vader_front_parser$peek_at(l0, l1);
                    l5 = ((vader_struct_vader_front_lexer$Token_t*) t0)->f_kind;
                    if (l5 == INT32_C(79)) {
                        l4 = vader_chk_add(i32, l4, INT32_C(1));
                    }
                    if (l5 == INT32_C(80)) {
                        l4 = vader_chk_sub(i32, l4, INT32_C(1));
                    }
                    l1 = vader_chk_add(i32, l1, INT32_C(1));
                }
            }
            for (;;) {
                t0 = vader_front_parser$peek_at(l0, l1);
                if (((vader_struct_vader_front_lexer$Token_t*) t0)->f_kind == INT32_C(1)) {
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
                t0 = vader_front_parser$peek_at(l0, l1);
                if (((vader_struct_vader_front_lexer$Token_t*) t0)->f_kind == INT32_C(1)) {
                    l1 = vader_chk_add(i32, l1, INT32_C(1));
                    continue;
                }
                break;
            }
        } else {
            l2 = false;
        }
    }
    t0 = vader_front_parser$peek_at(l0, l1);
    if (((vader_struct_vader_front_lexer$Token_t*) t0)->f_kind == INT32_C(2)) {
        l4 = vader_chk_add(i32, l1, INT32_C(1));
        t0 = vader_front_parser$peek_at(l0, l4);
        l2 = ((vader_struct_vader_front_lexer$Token_t*) t0)->f_kind == INT32_C(71);
    } else {
        l2 = false;
    }
    if (l2) {
        l1 = vader_chk_add(i32, l1, INT32_C(2));
        t0 = vader_front_parser$peek_at(l0, l1);
        return ((vader_struct_vader_front_lexer$Token_t*) t0)->f_kind == INT32_C(11);
    }
    return false;
}

static bool vader_front_parser$peek_is_lhs_generic_alias_head(void* l0) {
    int32_t l1, l2, l3, l4, l9, l12;
    void* l5;
    void* l8;
    void* l11;
    bool l6, l7, l10, l13, l14, l15, l16;
    int64_t t0;
    int32_t t1;
    void* t2;
    t0 = ((vader_array_t*) ((vader_struct_vader_front_parser$Parser_t*) l0)->f_tokens)->length;
    l1 = ((int32_t) (int64_t) t0);
    l2 = INT32_C(1);
    l3 = INT32_C(0);
    t1 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_pos;
    l4 = vader_chk_add(i32, t1, INT32_C(2));
    while ((l4 < l1)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_front_parser$Parser_t*) l0)->f_tokens);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        if (((vader_struct_vader_front_lexer$Token_t*) l5)->f_kind == INT32_C(0)) {
            return false;
        }
        if (((vader_struct_vader_front_lexer$Token_t*) l5)->f_kind == INT32_C(1)) {
            return false;
        }
        if (((vader_struct_vader_front_lexer$Token_t*) l5)->f_kind == INT32_C(52)) {
            l6 = l3 == INT32_C(0);
        } else {
            l6 = false;
        }
        if (l6) {
            l2 = vader_chk_add(i32, l2, INT32_C(1));
        } else {
            if (((vader_struct_vader_front_lexer$Token_t*) l5)->f_kind == INT32_C(54)) {
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
                    l8 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_tokens;
                    l9 = vader_chk_add(i32, l4, INT32_C(1));
                    vader_array_t* _a1_slotarr = ((vader_array_t*) l8);
                    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l9)
                    t2 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l9);
                    return ((vader_struct_vader_front_lexer$Token_t*) t2)->f_kind == INT32_C(71);
                }
            } else {
                if (((vader_struct_vader_front_lexer$Token_t*) l5)->f_kind == INT32_C(49)) {
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
                        l11 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_tokens;
                        l12 = vader_chk_add(i32, l4, INT32_C(1));
                        vader_array_t* _a2_slotarr = ((vader_array_t*) l11);
                        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l12)
                        t2 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l12);
                        return ((vader_struct_vader_front_lexer$Token_t*) t2)->f_kind == INT32_C(71);
                    }
                    if ((l2 < INT32_C(0))) {
                        return false;
                    }
                } else {
                    if (((vader_struct_vader_front_lexer$Token_t*) l5)->f_kind == INT32_C(79)) {
                        l13 = true;
                    } else {
                        l13 = ((vader_struct_vader_front_lexer$Token_t*) l5)->f_kind == INT32_C(81);
                    }
                    if (l13) {
                        l14 = true;
                    } else {
                        l14 = ((vader_struct_vader_front_lexer$Token_t*) l5)->f_kind == INT32_C(83);
                    }
                    if (l14) {
                        l3 = vader_chk_add(i32, l3, INT32_C(1));
                    } else {
                        if (((vader_struct_vader_front_lexer$Token_t*) l5)->f_kind == INT32_C(80)) {
                            l15 = true;
                        } else {
                            l15 = ((vader_struct_vader_front_lexer$Token_t*) l5)->f_kind == INT32_C(82);
                        }
                        if (l15) {
                            l16 = true;
                        } else {
                            l16 = ((vader_struct_vader_front_lexer$Token_t*) l5)->f_kind == INT32_C(84);
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

static bool vader_front_parser$peek_lambda_without_fn(void* l0) {
    int32_t l1, l2;
    uint8_t l3;
    void* t0;
    t0 = vader_front_parser$peek(l0);
    if (((vader_struct_vader_front_lexer$Token_t*) t0)->f_kind != INT32_C(79)) {
        return false;
    }
    l1 = INT32_C(1);
    l2 = INT32_C(1);
    while ((l1 > INT32_C(0))) {
        t0 = vader_front_parser$peek_at(l0, l2);
        l3 = ((vader_struct_vader_front_lexer$Token_t*) t0)->f_kind;
        if (l3 == INT32_C(0)) {
            return false;
        }
        if (l3 == INT32_C(79)) {
            l1 = vader_chk_add(i32, l1, INT32_C(1));
        } else if (l3 == INT32_C(80)) {
            l1 = vader_chk_sub(i32, l1, INT32_C(1));
            if (l1 == INT32_C(0)) break;
        }
        l2 = vader_chk_add(i32, l2, INT32_C(1));
    }
    l2 = vader_chk_add(i32, l2, INT32_C(1));
    for (;;) {
        t0 = vader_front_parser$peek_at(l0, l2);
        if (((vader_struct_vader_front_lexer$Token_t*) t0)->f_kind == INT32_C(1)) {
            l2 = vader_chk_add(i32, l2, INT32_C(1));
            continue;
        }
        break;
    }
    t0 = vader_front_parser$peek_at(l0, l2);
    return ((vader_struct_vader_front_lexer$Token_t*) t0)->f_kind == INT32_C(76);
}

static vader_box_t vader_front_parser$place_text(vader_box_t l0) {
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
    if (l0.tag == 778u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_toolchain_ast$IdentExpr_t*) t0)->f_name;
        { vader_box_t __vret = vader_box_string(447u, t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0.tag == 771u)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t0 = l0.payload.obj;
    l2 = vader_front_parser$place_text(((vader_struct_toolchain_ast$FieldExpr_t*) t0)->f_target);
    if (l2.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l1 = l2.payload.s;
    t0 = l0.payload.obj;
    l3 = ((vader_struct_toolchain_ast$FieldExpr_t*) t0)->f_field;
    t1 = concat_3(l1, 400u, l3);
    { vader_box_t __vret = vader_box_string(447u, t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_front_parser$postfix_bp(uint8_t l0) {
    int32_t l1;
    if (l0 == INT32_C(79)) {
        l1 = INT32_C(100);
        return l1;
    }
    if (l0 == INT32_C(81)) {
        l1 = INT32_C(100);
    } else if (l0 == INT32_C(86)) {
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
    } else if (l0 == INT32_C(80)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(82)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(83)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(84)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(85)) {
        l1 = INT32_C(-1);
    } else if (l0 == INT32_C(87)) {
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

static void vader_front_parser$reject_alternative_bindings(void* l0, vader_box_t l1) {
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
    if (!(l1.tag == 790u)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = l1.payload.obj;
    l2 = ((vader_struct_toolchain_ast$IsPattern_t*) t0)->f_inner;
    if (!(l2.tag == 821u)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = l2.payload.obj;
    l3 = ((vader_struct_toolchain_ast$StructPattern_t*) t0)->f_fields;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l6 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        if (((vader_struct_toolchain_ast$StructPatternField_t*) l6)->f_value.tag == 802u) {
            l7 = ((vader_struct_toolchain_ast$PatternBinding_t*) ((vader_struct_toolchain_ast$StructPatternField_t*) l6)->f_value.payload.obj)->f_span;
            l8 = ((vader_struct_toolchain_ast$StructPatternField_t*) l6)->f_name;
            t1 = concat_3(1523u, l8, 1034u);
            l9 = concat_2(t1, 2729u);
            vader_front_parser$error(l0, (uint8_t) 20, l7, l9);
        }
        l5 = (l5 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_parser$reject_as_binder(void* l0, uint8_t l1, void* l2) {
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
    l4 = vader_front_parser$match_kind(l0, (uint8_t) 29);
    if (l4.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = l4.payload.obj;
    l5 = vader_front_parser$expect(l0, (uint8_t) 2, 1624u);
    if (((vader_struct_vader_front_lexer$Token_t*) l5)->f_kind == INT32_C(2)) {
        l3 = vader_front_parser$span_of(l0, l3, l5);
        t0 = ((vader_struct_vader_front_lexer$Token_t*) l5)->f_text;
        vader_fn_t* _a0_fnobj = (vader_fn_t*) l2;
        t1 = ((vader_fn_erased_sig_1_t) _a0_fnobj->code)(_a0_fnobj->env, vader_box_string(447u, t0));
        l6 = t1.payload.s;
        vader_front_parser$error(l0, l1, l3, l6);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_parser$reject_assert_decorator(void* l0, void* l1) {
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
        t0 = ((vader_struct_toolchain_ast$Decorator_t*) l5)->f_name;
        if (t0 == 1596u) {
            l6 = ((vader_struct_toolchain_ast$Decorator_t*) l5)->f_span;
            vader_front_parser$error(l0, (uint8_t) 8, l6, 1330u);
        }
        l4 = (l4 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_parser$reject_c_decorators(void* l0, void* l1, vader_string_t l2) {
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
        t0 = ((vader_struct_toolchain_ast$Decorator_t*) l6)->f_name;
        if (t0 == 1705u) {
            l7 = true;
        } else {
            t0 = ((vader_struct_toolchain_ast$Decorator_t*) l6)->f_name;
            l7 = t0 == 1704u;
        }
        if (l7) {
            l8 = ((vader_struct_toolchain_ast$Decorator_t*) l6)->f_span;
            l9 = ((vader_struct_toolchain_ast$Decorator_t*) l6)->f_name;
            l10 = concat_4(1327u, l9, 1077u, l2);
            vader_front_parser$error(l0, (uint8_t) 8, l8, l10);
        }
        t0 = ((vader_struct_toolchain_ast$Decorator_t*) l6)->f_name;
        if (t0 == 1706u) {
            l11 = ((vader_struct_toolchain_ast$Decorator_t*) l6)->f_span;
            l12 = concat_2(1335u, l2);
            vader_front_parser$error(l0, (uint8_t) 8, l11, l12);
        }
        l5 = (l5 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_parser$reject_displayable_decorator(void* l0, void* l1) {
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
        t0 = ((vader_struct_toolchain_ast$Decorator_t*) l5)->f_name;
        if (t0 == 1841u) {
            l6 = ((vader_struct_toolchain_ast$Decorator_t*) l5)->f_span;
            vader_front_parser$error(l0, (uint8_t) 8, l6, 1349u);
        }
        l4 = (l4 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_parser$reject_free_fn_decorators(void* l0, void* l1, vader_string_t l2, vader_string_t l3) {
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
        t0 = ((vader_struct_toolchain_ast$Decorator_t*) l7)->f_name;
        if (t0 == 2695u) {
            l8 = ((vader_struct_toolchain_ast$Decorator_t*) l7)->f_span;
            l9 = concat_3(1363u, l2, l3);
            vader_front_parser$error(l0, (uint8_t) 8, l8, l9);
        }
        t0 = ((vader_struct_toolchain_ast$Decorator_t*) l7)->f_name;
        if (t0 == 2560u) {
            l10 = ((vader_struct_toolchain_ast$Decorator_t*) l7)->f_span;
            l11 = concat_2(1359u, l2);
            vader_front_parser$error(l0, (uint8_t) 8, l10, l11);
        }
        t0 = ((vader_struct_toolchain_ast$Decorator_t*) l7)->f_name;
        if (t0 == 2531u) {
            l12 = ((vader_struct_toolchain_ast$Decorator_t*) l7)->f_span;
            l13 = concat_2(1358u, l2);
            vader_front_parser$error(l0, (uint8_t) 8, l12, l13);
        }
        t0 = ((vader_struct_toolchain_ast$Decorator_t*) l7)->f_name;
        if (t0 == 1881u) {
            l14 = ((vader_struct_toolchain_ast$Decorator_t*) l7)->f_span;
            l15 = concat_2(2214u, l2);
            l16 = concat_2(1351u, l15);
            vader_front_parser$error(l0, (uint8_t) 8, l14, l16);
        }
        t0 = ((vader_struct_toolchain_ast$Decorator_t*) l7)->f_name;
        if (t0 == 1707u) {
            l17 = ((vader_struct_toolchain_ast$Decorator_t*) l7)->f_span;
            l18 = concat_2(2214u, l2);
            l19 = concat_2(1339u, l18);
            vader_front_parser$error(l0, (uint8_t) 8, l17, l19);
        }
        l6 = (l6 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_parser$reject_removed_const(void* l0) {
    vader_box_t l1 = vader_box_null();
    void* l2 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_front_parser$match_kind(l0, (uint8_t) 35);
    if (l1.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = l1.payload.obj;
    l2 = ((vader_struct_vader_front_lexer$Token_t*) t0)->f_span;
    vader_front_parser$error(l0, (uint8_t) 13, l2, 1492u);
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_front_parser$reject_tuple_pattern(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    int32_t l2;
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_front_parser$advance(l0);
    l2 = INT32_C(1);
    l3 = l1;
    while ((l2 > INT32_C(0))) {
        t0 = vader_front_parser$check(l0, (uint8_t) 0);
        if (t0) break;
        l3 = vader_front_parser$advance(l0);
        if (((vader_struct_vader_front_lexer$Token_t*) l3)->f_kind == INT32_C(81)) {
            l2 = vader_chk_add(i32, l2, INT32_C(1));
        }
        if (!(((vader_struct_vader_front_lexer$Token_t*) l3)->f_kind == INT32_C(82))) {
            continue;
        }
        l2 = vader_chk_sub(i32, l2, INT32_C(1));
    }
    l1 = vader_front_parser$span_of(l0, l1, l3);
    vader_front_parser$error(l0, (uint8_t) 11, l1, 2702u);
    vader_struct_toolchain_ast$WildcardPattern_t* _a0_obj = (vader_struct_toolchain_ast$WildcardPattern_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$WildcardPattern_t));
    vader_obj_header_init(_a0_obj, 831u);
    _a0_obj->f_span = l1;
    _a0_obj->f_id = INT64_C(0);
    t1 = (void*) _a0_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_front_parser$report_nesting_too_deep(void* l0, vader_string_t l1) {
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
    t0 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_depth_exceeded;
    if (t0) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l2 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_errors;
    t1 = vader_front_parser$peek(l0);
    l3 = ((vader_struct_vader_front_lexer$Token_t*) t1)->f_span;
    l4 = l1;
    l5 = vader_host_std_core$byte_len(l4);
    l6 = (void*) vader_buffer_new((size_t) (INT64_C(50) + l5));
    l5 = INT64_C(0);
    l5 = std_core$write_string_at(l6, l5, l4);
    l5 = std_core$write_string_at(l6, l5, 181u);
    l5 = std_core$write_int(l6, l5, INT64_C(256));
    l5 = std_core$write_string_at(l6, l5, 169u);
    l4 = std_core$finish_buffer(l6, l5);
    l3 = vader_support_diagnostics$parser_error((uint8_t) 15, l3, l4);
    vader_array_push_ref((vader_array_t*) l2, l3);
    ((vader_struct_vader_front_parser$Parser_t*) l0)->f_depth_exceeded = true;
    for (;;) {
        t0 = vader_front_parser$check(l0, (uint8_t) 1);
        if (!(t0)) {
            t0 = vader_front_parser$check(l0, (uint8_t) 0);
            if (t0) break;
            vader_front_parser$advance(l0);
            continue;
        }
        break;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_front_parser$scan_angle_generic(void* l0, int32_t l1) {
    int32_t l2, l3, l4, l5, l6;
    void* l7;
    bool l8;
    int64_t t0;
    void* t1;
    bool t2;
    t0 = ((vader_array_t*) ((vader_struct_vader_front_parser$Parser_t*) l0)->f_tokens)->length;
    l2 = ((int32_t) (int64_t) t0);
    if ((l1 >= l2)) {
        return false;
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_front_parser$Parser_t*) l0)->f_tokens);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    if (((vader_struct_vader_front_lexer$Token_t*) t1)->f_kind != INT32_C(52)) {
        return false;
    }
    l3 = INT32_C(1);
    l4 = INT32_C(0);
    l5 = INT32_C(0);
    l6 = vader_chk_add(i32, l1, INT32_C(1));
    while ((l6 < l2)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_front_parser$Parser_t*) l0)->f_tokens);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        l7 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
        if (((vader_struct_vader_front_lexer$Token_t*) l7)->f_kind == INT32_C(0)) {
            return false;
        }
        if (l4 == INT32_C(0)) {
            l8 = l5 == INT32_C(0);
        } else {
            l8 = false;
        }
        if (((vader_struct_vader_front_lexer$Token_t*) l7)->f_kind == INT32_C(1)) {
            if (l8) {
                return false;
            }
        }
        if (l8) {
            t2 = vader_front_parser$is_angle_scan_bailout(((vader_struct_vader_front_lexer$Token_t*) l7)->f_kind);
            if (t2) {
                return false;
            }
        }
        if (l8) {
            if (((vader_struct_vader_front_lexer$Token_t*) l7)->f_kind == INT32_C(52)) {
                l3 = vader_chk_add(i32, l3, INT32_C(1));
            } else if (((vader_struct_vader_front_lexer$Token_t*) l7)->f_kind == INT32_C(54)) {
                l3 = vader_chk_sub(i32, l3, INT32_C(1));
                if (l3 == INT32_C(0)) {
                    t2 = vader_front_parser$generic_use_follows(l0, l6);
                    return t2;
                }
            } else if (((vader_struct_vader_front_lexer$Token_t*) l7)->f_kind == INT32_C(49)) {
                l3 = vader_chk_sub(i32, l3, INT32_C(2));
                if (l3 == INT32_C(0)) {
                    t2 = vader_front_parser$generic_use_follows(l0, l6);
                    return t2;
                }
                if ((l3 < INT32_C(0))) {
                    return false;
                }
            }
        }
        if (((vader_struct_vader_front_lexer$Token_t*) l7)->f_kind == INT32_C(79)) {
            l4 = vader_chk_add(i32, l4, INT32_C(1));
        } else if (((vader_struct_vader_front_lexer$Token_t*) l7)->f_kind == INT32_C(80)) {
            if (l4 == INT32_C(0)) {
                return false;
            }
            l4 = vader_chk_sub(i32, l4, INT32_C(1));
        } else if (((vader_struct_vader_front_lexer$Token_t*) l7)->f_kind == INT32_C(81)) {
            l5 = vader_chk_add(i32, l5, INT32_C(1));
        } else if (((vader_struct_vader_front_lexer$Token_t*) l7)->f_kind == INT32_C(82)) {
            if (l5 == INT32_C(0)) {
                return false;
            }
            l5 = vader_chk_sub(i32, l5, INT32_C(1));
        }
        l6 = (l6 + INT32_C(1));
    }
    return false;
}

static void vader_front_parser$set_decl_doc(vader_box_t l0, void* l1) {
    void* t0;
    if (l0.tag == 773u) {
        t0 = l0.payload.obj;
        ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_doc = vader_ref_box(l1);
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast$FnDecl_t*) t0);
        return;
    }
    if (l0.tag == 816u) {
        t0 = l0.payload.obj;
        ((vader_struct_toolchain_ast$StructDecl_t*) t0)->f_doc = vader_ref_box(l1);
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast$StructDecl_t*) t0);
    } else if (l0.tag == 767u) {
        t0 = l0.payload.obj;
        ((vader_struct_toolchain_ast$EnumDecl_t*) t0)->f_doc = vader_ref_box(l1);
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast$EnumDecl_t*) t0);
    } else if (l0.tag == 823u) {
        t0 = l0.payload.obj;
        ((vader_struct_toolchain_ast$TraitDecl_t*) t0)->f_doc = vader_ref_box(l1);
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast$TraitDecl_t*) t0);
    } else if (l0.tag == 782u) {
        t0 = l0.payload.obj;
        ((vader_struct_toolchain_ast$ImplDecl_t*) t0)->f_doc = vader_ref_box(l1);
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast$ImplDecl_t*) t0);
    } else if (l0.tag == 825u) {
        t0 = l0.payload.obj;
        ((vader_struct_toolchain_ast$TypeAliasDecl_t*) t0)->f_doc = vader_ref_box(l1);
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast$TypeAliasDecl_t*) t0);
    } else if (l0.tag == 754u) {
        t0 = l0.payload.obj;
        ((vader_struct_toolchain_ast$ConstDecl_t*) t0)->f_doc = vader_ref_box(l1);
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast$ConstDecl_t*) t0);
    } else if (!((l0.tag == 743u || l0.tag == 783u))) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    return;
}

static int64_t vader_front_parser$skip_block_comment(vader_string_t l0, int64_t l1) {
    int64_t l2, l3, l6;
    int32_t l4;
    uint8_t l5, l7;
    int64_t t0;
    l2 = vader_host_std_core$byte_len(l0);
    l3 = l1;
    l4 = INT32_C(1);
    for (;;) {
        t0 = vader_chk_add(i64, l3, INT64_C(1));
        if ((t0 < l2)) {
            if (!((l4 > INT32_C(0)))) {
                break;
            }
            l5 = vader_host_std_core$byte_at(l0, l3);
            l6 = vader_chk_add(i64, l3, INT64_C(1));
            l7 = vader_host_std_core$byte_at(l0, l6);
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

static void vader_front_parser$skip_newlines(void* l0) {
    int32_t l1;
    bool t0;
    int32_t t1;
    for (;;) {
        t0 = vader_front_parser$check(l0, (uint8_t) 1);
        if (t0) {
            t1 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_pos;
            l1 = vader_chk_add(i32, t1, INT32_C(1));
            ((vader_struct_vader_front_parser$Parser_t*) l0)->f_pos = l1;
            continue;
        }
        break;
    }
    return;
}

static int64_t vader_front_parser$skip_to_eol(vader_string_t l0, int64_t l1) {
    int64_t l2, l3;
    uint8_t t0;
    l2 = vader_host_std_core$byte_len(l0);
    l3 = l1;
    while ((l3 < l2)) {
        t0 = vader_host_std_core$byte_at(l0, l3);
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

static void* vader_front_parser$span_of(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_front_lexer$Token_t*) l1)->f_span)->f_start;
    l4 = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_front_lexer$Token_t*) l2)->f_span)->f_end;
    vader_struct_toolchain_span$Span_t* _a0_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
    vader_obj_header_init(_a0_obj, 835u);
    _a0_obj->f_start = l3;
    _a0_obj->f_end = l4;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_front_parser$starts_let(void* l0) {
    uint8_t l1;
    bool l2;
    bool t0;
    t0 = vader_front_parser$check(l0, (uint8_t) 81);
    if (t0) {
        l1 = vader_front_parser$kind_after_bracket_group(l0);
        if (l1 == INT32_C(71)) {
            l2 = true;
        } else {
            l2 = l1 == INT32_C(72);
        }
        if (l2) {
            return true;
        }
        return l1 == INT32_C(87);
    }
    t0 = vader_front_parser$check(l0, (uint8_t) 2);
    if (t0) {
        t0 = vader_front_parser$check_at(l0, (uint8_t) 71, INT32_C(1));
        if (t0) {
            l2 = true;
        } else {
            l2 = vader_front_parser$check_at(l0, (uint8_t) 72, INT32_C(1));
        }
        if (l2) {
            l2 = true;
        } else {
            l2 = vader_front_parser$check_at(l0, (uint8_t) 87, INT32_C(1));
        }
        return l2;
    }
    return false;
}

static vader_box_t vader_front_parser$static_assert_message(void* l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = toolchain_ast$string_literal_text(l1);
    if (l2.tag == 0u) {
        l3 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l1.payload.obj);
        vader_front_parser$error(l0, (uint8_t) 17, l3, 1329u);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_front_parser$sync_to_top_level(void* l0) {
    void* t0;
    bool t1;
    for (;;) {
        t0 = vader_front_parser$peek(l0);
        if (((vader_struct_vader_front_lexer$Token_t*) t0)->f_kind != INT32_C(0)) {
            t1 = vader_front_parser$at_top_level_start(l0);
            if (t1) break;
            vader_front_parser$advance(l0);
            continue;
        }
        break;
    }
    return;
}

static vader_box_t vader_front_parser$take_doc(void* l0) {
    int64_t l1, l2, l3, l5, l7;
    void* l4;
    void* l6;
    void* t0;
    int64_t t1;
    t0 = vader_front_parser$peek(l0);
    l1 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_front_lexer$Token_t*) t0)->f_span)->f_start)->f_offset;
    for (;;) {
        l2 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_doc_cursor;
        l3 = ((vader_array_t*) ((vader_struct_vader_front_parser$Parser_t*) l0)->f_doc_runs)->length;
        if ((l2 < l3)) {
            l4 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_doc_runs;
            l5 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_doc_cursor;
            vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
            l6 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
            t1 = ((vader_struct_vader_front_lexer$DocRun_t*) l6)->f_followed_by;
            if ((t1 > l1)) {
                return vader_box_obj(0u, NULL);
            }
            t1 = ((vader_struct_vader_front_parser$Parser_t*) l0)->f_doc_cursor;
            l7 = vader_chk_add(i64, t1, INT64_C(1));
            ((vader_struct_vader_front_parser$Parser_t*) l0)->f_doc_cursor = l7;
            t1 = ((vader_struct_vader_front_lexer$DocRun_t*) l6)->f_followed_by;
            if (!(t1 == l1)) {
                continue;
            }
            return vader_ref_box(((vader_struct_vader_front_lexer$DocRun_t*) l6)->f_doc);
        }
        break;
    }
    return vader_box_obj(0u, NULL);
}

static void* vader_front_parser$through_comptime_helper(void* l0, void* l1, uint8_t l2, void* l3, vader_box_t l4, vader_box_t l5, void* l6, bool l7) {
    void* l8 = NULL;
    void* l9 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    vader_string_t l10 = 0;
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l4, &l5 };
    void** gc_raw_roots[11] = { &l0, &l1, &l3, &l6, &l8, &l9, &l11, &l12, &l13, &l14, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l10 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 11u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_front_parser$wrap_as_block(l5);
    l8 = vader_front_parser$lift_trailing_return(t0);
    l9 = vader_front_parser$peek_at(l0, INT32_C(-1));
    l10 = ((vader_struct_vader_front_lexer$Token_t*) l3)->f_text;
    l10 = concat_2(997u, l10);
    l11 = ((vader_struct_toolchain_span$Span_t*) l6)->f_start;
    l12 = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_front_lexer$Token_t*) l9)->f_span)->f_end;
    vader_struct_toolchain_span$Span_t* _a0_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
    vader_obj_header_init(_a0_obj, 835u);
    _a0_obj->f_start = l11;
    _a0_obj->f_end = l12;
    l11 = (void*) _a0_obj;
    vader_array_t* _a1_arr = vader_array_new(59u, 0u, 13u, 826u);
    l12 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(48u, 0u, 13u, 774u);
    l13 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(43u, 0u, 13u, 756u);
    l14 = (void*) _a3_arr;
    vader_struct_toolchain_ast$FnDecl_t* _a4_obj = (vader_struct_toolchain_ast$FnDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$FnDecl_t));
    vader_obj_header_init(_a4_obj, 773u);
    _a4_obj->f_span = l11;
    _a4_obj->f_id = INT64_C(0);
    _a4_obj->f_name = l10;
    _a4_obj->f_name_span = l6;
    _a4_obj->f_visibility = (uint8_t) 1;
    _a4_obj->f_type_params = l12;
    _a4_obj->f_params = l13;
    _a4_obj->f_return_type = l4;
    _a4_obj->f_body = vader_ref_box(l8);
    _a4_obj->f_decorators = l14;
    _a4_obj->f_sam_synthetic = false;
    _a4_obj->f_is_expression_bodied = true;
    _a4_obj->f_materialized = false;
    _a4_obj->f_comptime_synthetic = true;
    _a4_obj->f_trailing_comma = false;
    _a4_obj->f_doc = vader_box_obj(0u, NULL);
    _a4_obj->f_inherits = vader_box_obj(0u, NULL);
    l8 = (void*) _a4_obj;
    vader_array_push_ref((vader_array_t*) ((vader_struct_vader_front_parser$Parser_t*) l0)->f_pending_decls, l8);
    l8 = vader_front_parser$ident_expr(((vader_struct_vader_front_lexer$Token_t*) l3)->f_span, l10);
    vader_array_t* _a5_arr = vader_array_new(349u, 0u, 13u, 1716u);
    l12 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(41u, 0u, 13u, 750u);
    l13 = (void*) _a6_arr;
    vader_struct_toolchain_ast$CallExpr_t* _a7_obj = (vader_struct_toolchain_ast$CallExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$CallExpr_t));
    vader_obj_header_init(_a7_obj, 751u);
    _a7_obj->f_span = l11;
    _a7_obj->f_id = INT64_C(0);
    _a7_obj->f_callee = vader_ref_box(l8);
    _a7_obj->f_type_args = l12;
    _a7_obj->f_args = l13;
    _a7_obj->f_trailing_comma = false;
    l8 = (void*) _a7_obj;
    vader_array_t* _a8_arr = vader_array_new(43u, 0u, 13u, 756u);
    l11 = (void*) _a8_arr;
    vader_array_push_all((vader_array_t*) l11, (vader_array_t*) l1);
    if (!(l7)) {
        l12 = ((vader_struct_vader_front_lexer$Token_t*) l3)->f_span;
        vader_array_t* _a9_arr = vader_array_new(349u, 0u, 13u, 1716u);
        l13 = (void*) _a9_arr;
        vader_struct_toolchain_ast$Decorator_t* _a10_obj = (vader_struct_toolchain_ast$Decorator_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$Decorator_t));
        vader_obj_header_init(_a10_obj, 756u);
        _a10_obj->f_span = l12;
        _a10_obj->f_id = INT64_C(0);
        _a10_obj->f_name = 1778u;
        _a10_obj->f_args = l13;
        l12 = (void*) _a10_obj;
        vader_array_push_ref((vader_array_t*) l11, l12);
    }
    l9 = vader_front_parser$span_of(l0, l3, l9);
    l10 = ((vader_struct_vader_front_lexer$Token_t*) l3)->f_text;
    l12 = ((vader_struct_vader_front_lexer$Token_t*) l3)->f_span;
    vader_struct_toolchain_ast$ConstDecl_t* _a11_obj = (vader_struct_toolchain_ast$ConstDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$ConstDecl_t));
    vader_obj_header_init(_a11_obj, 754u);
    _a11_obj->f_span = l9;
    _a11_obj->f_id = INT64_C(0);
    _a11_obj->f_name = l10;
    _a11_obj->f_name_span = l12;
    _a11_obj->f_visibility = l2;
    _a11_obj->f_ty = l4;
    _a11_obj->f_value = vader_ref_box(l8);
    _a11_obj->f_decorators = l11;
    _a11_obj->f_comptime_body = l5;
    _a11_obj->f_comptime_as_decorator = l7;
    _a11_obj->f_doc = vader_box_obj(0u, NULL);
    t0 = (void*) _a11_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_front_parser$walk_assign_target(vader_box_t l0, void* l1) {
    vader_box_t l2;
    int64_t l3;
    void* l4;
    if ((l0.tag == 804u || l0.tag == 809u)) {
        l2 = l0;
        l3 = vader_front_parser$mint(l1);
        VADER_UNION_FIELD(int64_t, vader_struct_toolchain_ast$PlaceTarget_t, f_id, l2.payload.obj) = l3;
        vader_front_parser$walk_expr(VADER_UNION_FIELD(vader_box_t, vader_struct_toolchain_ast$PlaceTarget_t, f_place, l0.payload.obj), l1);
        return;
    }
    if (!(l0.tag == 832u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    l4 = l0.payload.obj;
    l3 = vader_front_parser$mint(l1);
    ((vader_struct_toolchain_ast$WildcardTarget_t*) l4)->f_id = l3;
    return;
}

static void vader_front_parser$walk_block(void* l0, void* l1) {
    int64_t l2, l4;
    void* l3;
    vader_box_t t0;
    l2 = vader_front_parser$mint(l1);
    ((vader_struct_toolchain_ast$BlockExpr_t*) l0)->f_id = l2;
    l3 = ((vader_struct_toolchain_ast$BlockExpr_t*) l0)->f_stmts;
    l2 = ((vader_array_t*) l3)->length;
    l4 = INT64_C(0);
    while ((l4 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        vader_front_parser$walk_stmt(t0, l1);
        l4 = (l4 + INT64_C(1));
    }
    if (((vader_struct_toolchain_ast$BlockExpr_t*) l0)->f_trailing.tag == 0u) {
        return;
    }
    vader_front_parser$walk_expr(((vader_struct_toolchain_ast$BlockExpr_t*) l0)->f_trailing, l1);
    return;
}

static void vader_front_parser$walk_decl(vader_box_t l0, void* l1) {
    void* l2;
    void* l5;
    int64_t l3, l4, l6;
    void* t0;
    vader_box_t t1;
    if (l0.tag == 783u) {
        l2 = l0.payload.obj;
        l3 = vader_front_parser$mint(l1);
        ((vader_struct_toolchain_ast$ImportDecl_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_front_parser$walk_import_binding(((vader_struct_toolchain_ast$ImportDecl_t*) t0)->f_binding, l1);
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$ImportDecl_t*) t0)->f_decorators;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
            vader_front_parser$walk_decorator(t0, l1);
            l4 = (l4 + INT64_C(1));
        }
    } else if (l0.tag == 773u) {
        t0 = l0.payload.obj;
        vader_front_parser$walk_fn_decl(t0, l1);
    } else if (l0.tag == 816u) {
        l2 = l0.payload.obj;
        l3 = vader_front_parser$mint(l1);
        ((vader_struct_toolchain_ast$StructDecl_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$StructDecl_t*) t0)->f_type_params;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
            vader_front_parser$walk_type_param(t0, l1);
            l4 = (l4 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$StructDecl_t*) t0)->f_fields;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            l5 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
            l6 = vader_front_parser$mint(l1);
            ((vader_struct_toolchain_ast$StructField_t*) l5)->f_id = l6;
            vader_front_parser$walk_expr(((vader_struct_toolchain_ast$StructField_t*) l5)->f_ty, l1);
            if (!(((vader_struct_toolchain_ast$StructField_t*) l5)->f_default.tag == 0u)) {
                vader_front_parser$walk_expr(((vader_struct_toolchain_ast$StructField_t*) l5)->f_default, l1);
            }
            l4 = (l4 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$StructDecl_t*) t0)->f_decorators;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            t0 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l4);
            vader_front_parser$walk_decorator(t0, l1);
            l4 = (l4 + INT64_C(1));
        }
    } else if (l0.tag == 767u) {
        l2 = l0.payload.obj;
        l3 = vader_front_parser$mint(l1);
        ((vader_struct_toolchain_ast$EnumDecl_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$EnumDecl_t*) t0)->f_header;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            t1 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l4);
            vader_front_parser$walk_expr(t1, l1);
            l4 = (l4 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$EnumDecl_t*) t0)->f_variants;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            l5 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l4);
            l6 = vader_front_parser$mint(l1);
            ((vader_struct_toolchain_ast$EnumVariant_t*) l5)->f_id = l6;
            if (!(((vader_struct_toolchain_ast$EnumVariant_t*) l5)->f_data.tag == 0u)) {
                vader_front_parser$walk_struct_lit_items(((vader_struct_toolchain_ast$EnumVariant_t*) l5)->f_data.payload.obj, l1);
            }
            l4 = (l4 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$EnumDecl_t*) t0)->f_decorators;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a6_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            t0 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l4);
            vader_front_parser$walk_decorator(t0, l1);
            l4 = (l4 + INT64_C(1));
        }
    } else if (l0.tag == 823u) {
        l2 = l0.payload.obj;
        l3 = vader_front_parser$mint(l1);
        ((vader_struct_toolchain_ast$TraitDecl_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$TraitDecl_t*) t0)->f_type_params;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a7_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            t0 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l4);
            vader_front_parser$walk_type_param(t0, l1);
            l4 = (l4 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        if (!(((vader_struct_toolchain_ast$TraitDecl_t*) t0)->f_requires.tag == 0u)) {
            t0 = l0.payload.obj;
            vader_front_parser$walk_expr(((vader_struct_toolchain_ast$TraitDecl_t*) t0)->f_requires, l1);
        }
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$TraitDecl_t*) t0)->f_members;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a8_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            t0 = vader_array_ref_load_obj(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l4);
            vader_front_parser$walk_fn_decl(t0, l1);
            l4 = (l4 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$TraitDecl_t*) t0)->f_decorators;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a9_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            t0 = vader_array_ref_load_obj(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l4);
            vader_front_parser$walk_decorator(t0, l1);
            l4 = (l4 + INT64_C(1));
        }
    } else if (l0.tag == 782u) {
        l2 = l0.payload.obj;
        l3 = vader_front_parser$mint(l1);
        ((vader_struct_toolchain_ast$ImplDecl_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$ImplDecl_t*) t0)->f_type_params;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a10_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
            t0 = vader_array_ref_load_obj(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l4);
            vader_front_parser$walk_type_param(t0, l1);
            l4 = (l4 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        vader_front_parser$walk_expr(((vader_struct_toolchain_ast$ImplDecl_t*) t0)->f_for_type, l1);
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$ImplDecl_t*) t0)->f_trait_args;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a11_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
            t1 = vader_array_ref_load_box(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l4);
            vader_front_parser$walk_expr(t1, l1);
            l4 = (l4 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$ImplDecl_t*) t0)->f_members;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a12_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
            t0 = vader_array_ref_load_obj(_a12_slotarr->buf, _a12_slotarr->offset + (size_t) l4);
            vader_front_parser$walk_fn_decl(t0, l1);
            l4 = (l4 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$ImplDecl_t*) t0)->f_decorators;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a13_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
            t0 = vader_array_ref_load_obj(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l4);
            vader_front_parser$walk_decorator(t0, l1);
            l4 = (l4 + INT64_C(1));
        }
    } else if (l0.tag == 825u) {
        l2 = l0.payload.obj;
        l3 = vader_front_parser$mint(l1);
        ((vader_struct_toolchain_ast$TypeAliasDecl_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$TypeAliasDecl_t*) t0)->f_type_params;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a14_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
            t0 = vader_array_ref_load_obj(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l4);
            vader_front_parser$walk_type_param(t0, l1);
            l4 = (l4 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        vader_front_parser$walk_expr(((vader_struct_toolchain_ast$TypeAliasDecl_t*) t0)->f_aliased, l1);
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$TypeAliasDecl_t*) t0)->f_decorators;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a15_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
            t0 = vader_array_ref_load_obj(_a15_slotarr->buf, _a15_slotarr->offset + (size_t) l4);
            vader_front_parser$walk_decorator(t0, l1);
            l4 = (l4 + INT64_C(1));
        }
    } else if (l0.tag == 754u) {
        l2 = l0.payload.obj;
        l3 = vader_front_parser$mint(l1);
        ((vader_struct_toolchain_ast$ConstDecl_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        if (!(((vader_struct_toolchain_ast$ConstDecl_t*) t0)->f_ty.tag == 0u)) {
            t0 = l0.payload.obj;
            vader_front_parser$walk_expr(((vader_struct_toolchain_ast$ConstDecl_t*) t0)->f_ty, l1);
        }
        t0 = l0.payload.obj;
        vader_front_parser$walk_expr(((vader_struct_toolchain_ast$ConstDecl_t*) t0)->f_value, l1);
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$ConstDecl_t*) t0)->f_decorators;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a16_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
            t0 = vader_array_ref_load_obj(_a16_slotarr->buf, _a16_slotarr->offset + (size_t) l4);
            vader_front_parser$walk_decorator(t0, l1);
            l4 = (l4 + INT64_C(1));
        }
    } else {
        if (!(l0.tag == 743u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = l0.payload.obj;
        l3 = vader_front_parser$mint(l1);
        ((vader_struct_toolchain_ast$AssertDecl_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_front_parser$walk_expr(((vader_struct_toolchain_ast$AssertDecl_t*) t0)->f_condition, l1);
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$AssertDecl_t*) t0)->f_decorators;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a17_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
            t0 = vader_array_ref_load_obj(_a17_slotarr->buf, _a17_slotarr->offset + (size_t) l4);
            vader_front_parser$walk_decorator(t0, l1);
            l4 = (l4 + INT64_C(1));
        }
    }
    return;
}

static void vader_front_parser$walk_decorator(void* l0, void* l1) {
    int64_t l2, l4;
    void* l3;
    vader_box_t t0;
    l2 = vader_front_parser$mint(l1);
    ((vader_struct_toolchain_ast$Decorator_t*) l0)->f_id = l2;
    l3 = ((vader_struct_toolchain_ast$Decorator_t*) l0)->f_args;
    l2 = ((vader_array_t*) l3)->length;
    l4 = INT64_C(0);
    while ((l4 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        vader_front_parser$walk_expr(t0, l1);
        l4 = (l4 + INT64_C(1));
    }
    return;
}

static void vader_front_parser$walk_expr(vader_box_t l0, void* l1) {
    void* l2;
    void* l6;
    void* l8;
    int64_t l3, l4, l7, l9;
    vader_box_t l5, l10;
    void* t0;
    vader_box_t t1;
    if (l0.tag == 788u) {
        l2 = l0.payload.obj;
        l3 = vader_front_parser$mint(l1);
        ((vader_struct_toolchain_ast$IntLitExpr_t*) l2)->f_id = l3;
        return;
    }
    if (l0.tag == 772u) {
        l2 = l0.payload.obj;
        l3 = vader_front_parser$mint(l1);
        ((vader_struct_toolchain_ast$FloatLitExpr_t*) l2)->f_id = l3;
    } else if (l0.tag == 748u) {
        l2 = l0.payload.obj;
        l3 = vader_front_parser$mint(l1);
        ((vader_struct_toolchain_ast$BoolLitExpr_t*) l2)->f_id = l3;
    } else if (l0.tag == 800u) {
        l2 = l0.payload.obj;
        l3 = vader_front_parser$mint(l1);
        ((vader_struct_toolchain_ast$NullLitExpr_t*) l2)->f_id = l3;
    } else if (l0.tag == 753u) {
        l2 = l0.payload.obj;
        l3 = vader_front_parser$mint(l1);
        ((vader_struct_toolchain_ast$CharLitExpr_t*) l2)->f_id = l3;
    } else if (l0.tag == 813u) {
        l2 = l0.payload.obj;
        l3 = vader_front_parser$mint(l1);
        ((vader_struct_toolchain_ast$StringLitExpr_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$StringLitExpr_t*) t0)->f_parts;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
            if (l5.tag == 815u) {
                l6 = l5.payload.obj;
                l7 = vader_front_parser$mint(l1);
                ((vader_struct_toolchain_ast$StringLitText_t*) l6)->f_id = l7;
            } else {
                if (!(l5.tag == 814u)) {
                    vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                }
                l8 = l5.payload.obj;
                l9 = vader_front_parser$mint(l1);
                ((vader_struct_toolchain_ast$StringLitInterp_t*) l8)->f_id = l9;
                t0 = l5.payload.obj;
                vader_front_parser$walk_expr(((vader_struct_toolchain_ast$StringLitInterp_t*) t0)->f_expr, l1);
            }
            l4 = (l4 + INT64_C(1));
        }
    } else if (l0.tag == 778u) {
        l2 = l0.payload.obj;
        l3 = vader_front_parser$mint(l1);
        ((vader_struct_toolchain_ast$IdentExpr_t*) l2)->f_id = l3;
    } else if (l0.tag == 751u) {
        l2 = l0.payload.obj;
        l3 = vader_front_parser$mint(l1);
        ((vader_struct_toolchain_ast$CallExpr_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_front_parser$walk_expr(((vader_struct_toolchain_ast$CallExpr_t*) t0)->f_callee, l1);
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$CallExpr_t*) t0)->f_type_args;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            t1 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
            vader_front_parser$walk_expr(t1, l1);
            l4 = (l4 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$CallExpr_t*) t0)->f_args;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            l6 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
            l7 = vader_front_parser$mint(l1);
            ((vader_struct_toolchain_ast$CallArg_t*) l6)->f_id = l7;
            vader_front_parser$walk_expr(((vader_struct_toolchain_ast$CallArg_t*) l6)->f_value, l1);
            l4 = (l4 + INT64_C(1));
        }
    } else if (l0.tag == 771u) {
        l2 = l0.payload.obj;
        l3 = vader_front_parser$mint(l1);
        ((vader_struct_toolchain_ast$FieldExpr_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_front_parser$walk_expr(((vader_struct_toolchain_ast$FieldExpr_t*) t0)->f_target, l1);
    } else if (l0.tag == 786u) {
        l2 = l0.payload.obj;
        l3 = vader_front_parser$mint(l1);
        ((vader_struct_toolchain_ast$IndexExpr_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_front_parser$walk_expr(((vader_struct_toolchain_ast$IndexExpr_t*) t0)->f_target, l1);
        t0 = l0.payload.obj;
        vader_front_parser$walk_expr(((vader_struct_toolchain_ast$IndexExpr_t*) t0)->f_index, l1);
    } else if (l0.tag == 827u) {
        l2 = l0.payload.obj;
        l3 = vader_front_parser$mint(l1);
        ((vader_struct_toolchain_ast$UnaryExpr_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_front_parser$walk_expr(((vader_struct_toolchain_ast$UnaryExpr_t*) t0)->f_operand, l1);
    } else if (l0.tag == 746u) {
        l2 = l0.payload.obj;
        l3 = vader_front_parser$mint(l1);
        ((vader_struct_toolchain_ast$BinaryExpr_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_front_parser$walk_expr(((vader_struct_toolchain_ast$BinaryExpr_t*) t0)->f_left, l1);
        t0 = l0.payload.obj;
        vader_front_parser$walk_expr(((vader_struct_toolchain_ast$BinaryExpr_t*) t0)->f_right, l1);
    } else if (l0.tag == 799u) {
        l2 = l0.payload.obj;
        l3 = vader_front_parser$mint(l1);
        ((vader_struct_toolchain_ast$NullCoalesceExpr_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_front_parser$walk_expr(((vader_struct_toolchain_ast$NullCoalesceExpr_t*) t0)->f_left, l1);
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast$NullCoalesceExpr_t*) t0)->f_fallback;
        l10 = l5;
        if ((l5.tag == 749u || l5.tag == 755u || l5.tag == 810u)) {
            vader_front_parser$walk_stmt(l10, l1);
        } else {
            if (!((l5.tag == 742u || l5.tag == 745u || l5.tag == 746u || l5.tag == 747u || l5.tag == 748u || l5.tag == 751u || l5.tag == 752u || l5.tag == 753u || l5.tag == 766u || l5.tag == 771u || l5.tag == 772u || l5.tag == 775u || l5.tag == 777u || l5.tag == 778u || l5.tag == 781u || l5.tag == 786u || l5.tag == 788u || l5.tag == 789u || l5.tag == 791u || l5.tag == 795u || l5.tag == 799u || l5.tag == 800u || l5.tag == 806u || l5.tag == 811u || l5.tag == 813u || l5.tag == 818u || l5.tag == 827u))) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            vader_front_parser$walk_expr(l10, l1);
        }
    } else if (l0.tag == 781u) {
        l2 = l0.payload.obj;
        l3 = vader_front_parser$mint(l1);
        ((vader_struct_toolchain_ast$IfExpr_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_front_parser$walk_expr(((vader_struct_toolchain_ast$IfExpr_t*) t0)->f_cond, l1);
        t0 = l0.payload.obj;
        vader_front_parser$walk_block(((vader_struct_toolchain_ast$IfExpr_t*) t0)->f_then_block, l1);
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast$IfExpr_t*) t0)->f_else_branch;
        l10 = l5;
        if (!(l5.tag == 0u)) {
            if (l5.tag == 780u) {
                t0 = l10.payload.obj;
                vader_front_parser$walk_expr(vader_ref_box(((vader_struct_toolchain_ast$IfElseIf_t*) t0)->f_branch), l1);
            } else {
                if (!(l5.tag == 779u)) {
                    vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                }
                t0 = l10.payload.obj;
                vader_front_parser$walk_block(((vader_struct_toolchain_ast$IfElseBlock_t*) t0)->f_block, l1);
            }
        }
    } else if (l0.tag == 795u) {
        l2 = l0.payload.obj;
        l3 = vader_front_parser$mint(l1);
        ((vader_struct_toolchain_ast$MatchExpr_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        if (!(((vader_struct_toolchain_ast$MatchExpr_t*) t0)->f_binding.tag == 0u)) {
            t0 = l0.payload.obj;
            vader_front_parser$walk_let_binding(((vader_struct_toolchain_ast$MatchExpr_t*) t0)->f_binding, l1);
        }
        t0 = l0.payload.obj;
        vader_front_parser$walk_expr(((vader_struct_toolchain_ast$MatchExpr_t*) t0)->f_scrutinee, l1);
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$MatchExpr_t*) t0)->f_arms;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            l6 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l4);
            l7 = vader_front_parser$mint(l1);
            ((vader_struct_toolchain_ast$MatchArm_t*) l6)->f_id = l7;
            vader_front_parser$walk_pattern(((vader_struct_toolchain_ast$MatchArm_t*) l6)->f_pattern, l1);
            if (!(((vader_struct_toolchain_ast$MatchArm_t*) l6)->f_guard.tag == 0u)) {
                vader_front_parser$walk_expr(((vader_struct_toolchain_ast$MatchArm_t*) l6)->f_guard, l1);
            }
            vader_front_parser$walk_expr(((vader_struct_toolchain_ast$MatchArm_t*) l6)->f_body, l1);
            l4 = (l4 + INT64_C(1));
        }
    } else if (l0.tag == 747u) {
        t0 = l0.payload.obj;
        vader_front_parser$walk_block(t0, l1);
    } else if (l0.tag == 791u) {
        l2 = l0.payload.obj;
        l3 = vader_front_parser$mint(l1);
        ((vader_struct_toolchain_ast$LambdaExpr_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$LambdaExpr_t*) t0)->f_params;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            t0 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l4);
            vader_front_parser$walk_fn_param(t0, l1);
            l4 = (l4 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        if (!(((vader_struct_toolchain_ast$LambdaExpr_t*) t0)->f_return_type.tag == 0u)) {
            t0 = l0.payload.obj;
            vader_front_parser$walk_expr(((vader_struct_toolchain_ast$LambdaExpr_t*) t0)->f_return_type, l1);
        }
        t0 = l0.payload.obj;
        vader_front_parser$walk_block(((vader_struct_toolchain_ast$LambdaExpr_t*) t0)->f_body, l1);
    } else if (l0.tag == 818u) {
        l2 = l0.payload.obj;
        l3 = vader_front_parser$mint(l1);
        ((vader_struct_toolchain_ast$StructLitExpr_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_front_parser$walk_expr(((vader_struct_toolchain_ast$StructLitExpr_t*) t0)->f_type_name, l1);
        t0 = l0.payload.obj;
        vader_front_parser$walk_struct_lit_items(((vader_struct_toolchain_ast$StructLitExpr_t*) t0)->f_items, l1);
    } else if (l0.tag == 811u) {
        l2 = l0.payload.obj;
        l3 = vader_front_parser$mint(l1);
        ((vader_struct_toolchain_ast$SeqLitExpr_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$SeqLitExpr_t*) t0)->f_elements;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            t1 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l4);
            vader_front_parser$walk_expr(t1, l1);
            l4 = (l4 + INT64_C(1));
        }
    } else if (l0.tag == 806u) {
        l2 = l0.payload.obj;
        l3 = vader_front_parser$mint(l1);
        ((vader_struct_toolchain_ast$RangeExpr_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_front_parser$walk_expr(((vader_struct_toolchain_ast$RangeExpr_t*) t0)->f_lower, l1);
        t0 = l0.payload.obj;
        vader_front_parser$walk_expr(((vader_struct_toolchain_ast$RangeExpr_t*) t0)->f_upper, l1);
    } else if (l0.tag == 745u) {
        l2 = l0.payload.obj;
        l3 = vader_front_parser$mint(l1);
        ((vader_struct_toolchain_ast$AwaitExpr_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_front_parser$walk_expr(((vader_struct_toolchain_ast$AwaitExpr_t*) t0)->f_inner, l1);
    } else if (l0.tag == 752u) {
        l2 = l0.payload.obj;
        l3 = vader_front_parser$mint(l1);
        ((vader_struct_toolchain_ast$CastExpr_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_front_parser$walk_expr(((vader_struct_toolchain_ast$CastExpr_t*) t0)->f_target, l1);
        t0 = l0.payload.obj;
        vader_front_parser$walk_expr(((vader_struct_toolchain_ast$CastExpr_t*) t0)->f_value, l1);
    } else if (l0.tag == 777u) {
        l2 = l0.payload.obj;
        l3 = vader_front_parser$mint(l1);
        ((vader_struct_toolchain_ast$GenericInstExpr_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_front_parser$walk_expr(((vader_struct_toolchain_ast$GenericInstExpr_t*) t0)->f_callee, l1);
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$GenericInstExpr_t*) t0)->f_type_args;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a6_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            t1 = vader_array_ref_load_box(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l4);
            vader_front_parser$walk_expr(t1, l1);
            l4 = (l4 + INT64_C(1));
        }
    } else if (l0.tag == 789u) {
        l2 = l0.payload.obj;
        l3 = vader_front_parser$mint(l1);
        ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) t0)->f_args;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a7_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            t1 = vader_array_ref_load_box(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l4);
            vader_front_parser$walk_expr(t1, l1);
            l4 = (l4 + INT64_C(1));
        }
    } else if (l0.tag == 766u) {
        l2 = l0.payload.obj;
        l3 = vader_front_parser$mint(l1);
        ((vader_struct_toolchain_ast$DotVariantExpr_t*) l2)->f_id = l3;
    } else if (l0.tag == 775u) {
        l2 = l0.payload.obj;
        l3 = vader_front_parser$mint(l1);
        ((vader_struct_toolchain_ast$FnTypeExpr_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$FnTypeExpr_t*) t0)->f_params;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a8_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            t1 = vader_array_ref_load_box(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l4);
            vader_front_parser$walk_expr(t1, l1);
            l4 = (l4 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        if (!(((vader_struct_toolchain_ast$FnTypeExpr_t*) t0)->f_return_type.tag == 0u)) {
            t0 = l0.payload.obj;
            vader_front_parser$walk_expr(((vader_struct_toolchain_ast$FnTypeExpr_t*) t0)->f_return_type, l1);
        }
    } else {
        if (!(l0.tag == 742u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = l0.payload.obj;
        l3 = vader_front_parser$mint(l1);
        ((vader_struct_toolchain_ast$ArrayTypeExpr_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_front_parser$walk_expr(((vader_struct_toolchain_ast$ArrayTypeExpr_t*) t0)->f_element, l1);
    }
    return;
}

static void vader_front_parser$walk_fn_decl(void* l0, void* l1) {
    int64_t l2, l4;
    void* l3;
    void* t0;
    l2 = vader_front_parser$mint(l1);
    ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_id = l2;
    l3 = ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_decorators;
    l2 = ((vader_array_t*) l3)->length;
    l4 = INT64_C(0);
    while ((l4 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        vader_front_parser$walk_decorator(t0, l1);
        l4 = (l4 + INT64_C(1));
    }
    l3 = ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_type_params;
    l2 = ((vader_array_t*) l3)->length;
    l4 = INT64_C(0);
    while ((l4 < l2)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        vader_front_parser$walk_type_param(t0, l1);
        l4 = (l4 + INT64_C(1));
    }
    l3 = ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_params;
    l2 = ((vader_array_t*) l3)->length;
    l4 = INT64_C(0);
    while ((l4 < l2)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        vader_front_parser$walk_fn_param(t0, l1);
        l4 = (l4 + INT64_C(1));
    }
    if (!(((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_return_type.tag == 0u)) {
        vader_front_parser$walk_expr(((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_return_type, l1);
    }
    if (((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_body.tag == 0u) {
        return;
    }
    vader_front_parser$walk_block(((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_body.payload.obj, l1);
    return;
}

static void vader_front_parser$walk_fn_param(void* l0, void* l1) {
    int64_t l2;
    l2 = vader_front_parser$mint(l1);
    ((vader_struct_toolchain_ast$FnParam_t*) l0)->f_id = l2;
    if (!(((vader_struct_toolchain_ast$FnParam_t*) l0)->f_ty.tag == 0u)) {
        vader_front_parser$walk_expr(((vader_struct_toolchain_ast$FnParam_t*) l0)->f_ty, l1);
    }
    if (((vader_struct_toolchain_ast$FnParam_t*) l0)->f_default_value.tag == 0u) {
        return;
    }
    vader_front_parser$walk_expr(((vader_struct_toolchain_ast$FnParam_t*) l0)->f_default_value, l1);
    return;
}

static void vader_front_parser$walk_for_form(vader_box_t l0, void* l1) {
    void* t0;
    if (l0.tag == 787u) {
        return;
    }
    if (l0.tag == 828u) {
        t0 = l0.payload.obj;
        vader_front_parser$walk_expr(((vader_struct_toolchain_ast$WhileFor_t*) t0)->f_cond, l1);
    } else {
        if (!(l0.tag == 785u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = l0.payload.obj;
        vader_front_parser$walk_expr(((vader_struct_toolchain_ast$InFor_t*) t0)->f_iter, l1);
    }
    return;
}

static void vader_front_parser$walk_import_binding(vader_box_t l0, void* l1) {
    void* l2;
    void* l5;
    int64_t l3, l4, l6;
    void* t0;
    if (l0.tag == 797u) {
        return;
    }
    if (!(l0.tag == 830u)) {
        if (!(l0.tag == 761u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$DestructureImport_t*) t0)->f_names;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
            l6 = vader_front_parser$mint(l1);
            ((vader_struct_toolchain_ast$ImportName_t*) l5)->f_id = l6;
            l4 = (l4 + INT64_C(1));
        }
    }
    return;
}

static void vader_front_parser$walk_let_binding(vader_box_t l0, void* l1) {
    void* l2;
    int64_t l3, l4;
    void* t0;
    vader_box_t t1;
    if (l0.tag == 812u) {
        l2 = l0.payload.obj;
        l3 = vader_front_parser$mint(l1);
        ((vader_struct_toolchain_ast$SimpleBinding_t*) l2)->f_id = l3;
        return;
    }
    if (l0.tag == 829u) {
        l2 = l0.payload.obj;
        l3 = vader_front_parser$mint(l1);
        ((vader_struct_toolchain_ast$WildcardBinding_t*) l2)->f_id = l3;
    } else if (l0.tag == 808u) {
        l2 = l0.payload.obj;
        l3 = vader_front_parser$mint(l1);
        ((vader_struct_toolchain_ast$RestBinding_t*) l2)->f_id = l3;
    } else {
        if (!(l0.tag == 824u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = l0.payload.obj;
        l3 = vader_front_parser$mint(l1);
        ((vader_struct_toolchain_ast$TupleBinding_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$TupleBinding_t*) t0)->f_elements;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
            vader_front_parser$walk_let_binding(t1, l1);
            l4 = (l4 + INT64_C(1));
        }
    }
    return;
}

static void vader_front_parser$walk_pattern(vader_box_t l0, void* l1) {
    void* l2;
    void* l5;
    void* l9;
    int64_t l3, l4, l6, l10;
    vader_box_t l7, l8;
    void* t0;
    vader_box_t t1;
    if (l0.tag == 790u) {
        l2 = l0.payload.obj;
        l3 = vader_front_parser$mint(l1);
        ((vader_struct_toolchain_ast$IsPattern_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_front_parser$walk_expr(((vader_struct_toolchain_ast$IsPattern_t*) t0)->f_ty, l1);
        t0 = l0.payload.obj;
        if (!(((vader_struct_toolchain_ast$IsPattern_t*) t0)->f_inner.tag == 0u)) {
            t0 = l0.payload.obj;
            vader_front_parser$walk_pattern(((vader_struct_toolchain_ast$IsPattern_t*) t0)->f_inner, l1);
        }
        return;
    }
    if (l0.tag == 821u) {
        l2 = l0.payload.obj;
        l3 = vader_front_parser$mint(l1);
        ((vader_struct_toolchain_ast$StructPattern_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$StructPattern_t*) t0)->f_fields;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
            l6 = vader_front_parser$mint(l1);
            ((vader_struct_toolchain_ast$StructPatternField_t*) l5)->f_id = l6;
            l7 = ((vader_struct_toolchain_ast$StructPatternField_t*) l5)->f_value;
            l8 = l7;
            if (l7.tag == 802u) {
                l9 = l8.payload.obj;
                l10 = vader_front_parser$mint(l1);
                ((vader_struct_toolchain_ast$PatternBinding_t*) l9)->f_id = l10;
            } else {
                if (!(l7.tag == 803u)) {
                    vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                }
                t0 = l8.payload.obj;
                vader_front_parser$walk_expr(((vader_struct_toolchain_ast$PatternLiteral_t*) t0)->f_value, l1);
            }
            l4 = (l4 + INT64_C(1));
        }
    } else if (l0.tag == 831u) {
        l2 = l0.payload.obj;
        l3 = vader_front_parser$mint(l1);
        ((vader_struct_toolchain_ast$WildcardPattern_t*) l2)->f_id = l3;
    } else if (l0.tag == 769u) {
        l2 = l0.payload.obj;
        l3 = vader_front_parser$mint(l1);
        ((vader_struct_toolchain_ast$EnumVariantPattern_t*) l2)->f_id = l3;
    } else if (l0.tag == 793u) {
        l2 = l0.payload.obj;
        l3 = vader_front_parser$mint(l1);
        ((vader_struct_toolchain_ast$LiteralPattern_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_front_parser$walk_expr(((vader_struct_toolchain_ast$LiteralPattern_t*) t0)->f_value, l1);
    } else if (l0.tag == 807u) {
        l2 = l0.payload.obj;
        l3 = vader_front_parser$mint(l1);
        ((vader_struct_toolchain_ast$RangePattern_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_front_parser$walk_expr(((vader_struct_toolchain_ast$RangePattern_t*) t0)->f_lower, l1);
        t0 = l0.payload.obj;
        vader_front_parser$walk_expr(((vader_struct_toolchain_ast$RangePattern_t*) t0)->f_upper, l1);
    } else {
        if (!(l0.tag == 801u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = l0.payload.obj;
        l3 = vader_front_parser$mint(l1);
        ((vader_struct_toolchain_ast$OrPattern_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$OrPattern_t*) t0)->f_patterns;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            t1 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
            vader_front_parser$walk_pattern(t1, l1);
            l4 = (l4 + INT64_C(1));
        }
    }
    return;
}

static void vader_front_parser$walk_stmt(vader_box_t l0, void* l1) {
    void* l2;
    int64_t l3, l4;
    vader_box_t l5, l6;
    void* t0;
    vader_box_t t1;
    if (l0.tag == 792u) {
        l2 = l0.payload.obj;
        l3 = vader_front_parser$mint(l1);
        ((vader_struct_toolchain_ast$LetStmt_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_front_parser$walk_let_binding(((vader_struct_toolchain_ast$LetStmt_t*) t0)->f_binding, l1);
        t0 = l0.payload.obj;
        if (!(((vader_struct_toolchain_ast$LetStmt_t*) t0)->f_ty.tag == 0u)) {
            t0 = l0.payload.obj;
            vader_front_parser$walk_expr(((vader_struct_toolchain_ast$LetStmt_t*) t0)->f_ty, l1);
        }
        t0 = l0.payload.obj;
        vader_front_parser$walk_expr(((vader_struct_toolchain_ast$LetStmt_t*) t0)->f_value, l1);
        return;
    }
    if (l0.tag == 744u) {
        l2 = l0.payload.obj;
        l3 = vader_front_parser$mint(l1);
        ((vader_struct_toolchain_ast$AssignStmt_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_front_parser$walk_expr(((vader_struct_toolchain_ast$AssignStmt_t*) t0)->f_target, l1);
        t0 = l0.payload.obj;
        vader_front_parser$walk_expr(((vader_struct_toolchain_ast$AssignStmt_t*) t0)->f_value, l1);
    } else if (l0.tag == 760u) {
        l2 = l0.payload.obj;
        l3 = vader_front_parser$mint(l1);
        ((vader_struct_toolchain_ast$DestructureAssignStmt_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$DestructureAssignStmt_t*) t0)->f_targets;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
            vader_front_parser$walk_assign_target(t1, l1);
            l4 = (l4 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        vader_front_parser$walk_expr(((vader_struct_toolchain_ast$DestructureAssignStmt_t*) t0)->f_value, l1);
    } else if (l0.tag == 770u) {
        l2 = l0.payload.obj;
        l3 = vader_front_parser$mint(l1);
        ((vader_struct_toolchain_ast$ExprStmt_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_front_parser$walk_expr(((vader_struct_toolchain_ast$ExprStmt_t*) t0)->f_expr, l1);
    } else if (l0.tag == 810u) {
        l2 = l0.payload.obj;
        l3 = vader_front_parser$mint(l1);
        ((vader_struct_toolchain_ast$ReturnStmt_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        if (!(((vader_struct_toolchain_ast$ReturnStmt_t*) t0)->f_value.tag == 0u)) {
            t0 = l0.payload.obj;
            vader_front_parser$walk_expr(((vader_struct_toolchain_ast$ReturnStmt_t*) t0)->f_value, l1);
        }
    } else if (l0.tag == 833u) {
        l2 = l0.payload.obj;
        l3 = vader_front_parser$mint(l1);
        ((vader_struct_toolchain_ast$YieldStmt_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_front_parser$walk_expr(((vader_struct_toolchain_ast$YieldStmt_t*) t0)->f_value, l1);
    } else if (l0.tag == 776u) {
        l2 = l0.payload.obj;
        l3 = vader_front_parser$mint(l1);
        ((vader_struct_toolchain_ast$ForStmt_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        vader_front_parser$walk_for_form(((vader_struct_toolchain_ast$ForStmt_t*) t0)->f_form, l1);
        t0 = l0.payload.obj;
        vader_front_parser$walk_block(((vader_struct_toolchain_ast$ForStmt_t*) t0)->f_body, l1);
    } else if (l0.tag == 749u) {
        l2 = l0.payload.obj;
        l3 = vader_front_parser$mint(l1);
        ((vader_struct_toolchain_ast$BreakStmt_t*) l2)->f_id = l3;
    } else if (l0.tag == 755u) {
        l2 = l0.payload.obj;
        l3 = vader_front_parser$mint(l1);
        ((vader_struct_toolchain_ast$ContinueStmt_t*) l2)->f_id = l3;
    } else {
        if (!(l0.tag == 758u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = l0.payload.obj;
        l3 = vader_front_parser$mint(l1);
        ((vader_struct_toolchain_ast$DeferStmt_t*) l2)->f_id = l3;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast$DeferStmt_t*) t0)->f_body;
        l6 = l5;
        if (l5.tag == 759u) {
            t0 = l6.payload.obj;
            vader_front_parser$walk_stmt(((vader_struct_toolchain_ast$DeferStmtBody_t*) t0)->f_stmt, l1);
        } else {
            if (!(l5.tag == 757u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            t0 = l6.payload.obj;
            vader_front_parser$walk_block(((vader_struct_toolchain_ast$DeferBlockBody_t*) t0)->f_block, l1);
        }
    }
    return;
}

static void vader_front_parser$walk_struct_lit_items(void* l0, void* l1) {
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
        l6 = vader_front_parser$mint(l1);
        VADER_UNION_FIELD(int64_t, vader_struct_toolchain_ast$StructLitField_t, f_id, l5.payload.obj) = l6;
        if (l5.tag == 819u) {
            t0 = l5.payload.obj;
            vader_front_parser$walk_expr(((vader_struct_toolchain_ast$StructLitField_t*) t0)->f_value, l1);
        } else {
            t0 = l5.payload.obj;
            vader_front_parser$walk_expr(((vader_struct_toolchain_ast$StructLitSpread_t*) t0)->f_expr, l1);
        }
        l4 = (l4 + INT64_C(1));
    }
    return;
}

static void vader_front_parser$walk_type_param(void* l0, void* l1) {
    int64_t l2;
    l2 = vader_front_parser$mint(l1);
    ((vader_struct_toolchain_ast$TypeParam_t*) l0)->f_id = l2;
    if (((vader_struct_toolchain_ast$TypeParam_t*) l0)->f_bound.tag == 0u) {
        return;
    }
    vader_front_parser$walk_expr(((vader_struct_toolchain_ast$TypeParam_t*) l0)->f_bound, l1);
    return;
}

static void* vader_front_parser$wrap_as_block(vader_box_t l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l0, &l3 };
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(l0.tag == 747u)) {
        l1 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l0.payload.obj);
        vader_array_t* _a0_arr = vader_array_new(351u, 0u, 13u, 1753u);
        l2 = (void*) _a0_arr;
        l3 = l0;
        vader_struct_toolchain_ast$BlockExpr_t* _a1_obj = (vader_struct_toolchain_ast$BlockExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$BlockExpr_t));
        vader_obj_header_init(_a1_obj, 747u);
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
