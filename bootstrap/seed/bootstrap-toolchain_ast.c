#include "bootstrap.split.h"

static void toolchain_ast_append_bitor_variants(vader_box_t l0, void* l1);
static bool toolchain_ast_inspect_alias(void* l0, void* l1);
static bool toolchain_ast_inspect_arms(void* l0, void* l1);
static bool toolchain_ast_inspect_assign(void* l0, void* l1);
static bool toolchain_ast_inspect_call(void* l0, void* l1);
static bool toolchain_ast_inspect_const(void* l0, void* l1);
static bool toolchain_ast_inspect_decorators(void* l0, void* l1);
static bool toolchain_ast_inspect_defer(vader_box_t l0, void* l1);
static bool toolchain_ast_inspect_enum(void* l0, void* l1);
static bool toolchain_ast_inspect_exprs(void* l0, void* l1);
static bool toolchain_ast_inspect_fn(void* l0, void* l1);
static bool toolchain_ast_inspect_fns(void* l0, void* l1);
static bool toolchain_ast_inspect_form(vader_box_t l0, void* l1);
static bool toolchain_ast_inspect_if(void* l0, void* l1);
static bool toolchain_ast_inspect_impl(void* l0, void* l1);
static bool toolchain_ast_inspect_items(void* l0, void* l1);
static bool toolchain_ast_inspect_lambda(void* l0, void* l1);
static bool toolchain_ast_inspect_maybe(vader_box_t l0, void* l1);
static bool toolchain_ast_inspect_params(void* l0, void* l1);
static bool toolchain_ast_inspect_parts(void* l0, void* l1);
static bool toolchain_ast_inspect_pattern_fields(void* l0, void* l1);
static bool toolchain_ast_inspect_patterns(void* l0, void* l1);
static bool toolchain_ast_inspect_stmts(void* l0, void* l1);
static bool toolchain_ast_inspect_struct(void* l0, void* l1);
static bool toolchain_ast_inspect_targets(void* l0, void* l1);
static bool toolchain_ast_inspect_trait(void* l0, void* l1);
static bool toolchain_ast_inspect_type_params(void* l0, void* l1);
static bool toolchain_ast_is_arith_op(uint8_t l0);
static vader_box_t toolchain_ast_own_const_type(void* l0);
static vader_string_t toolchain_ast_sole_string_argument(void* l0);
static vader_box_t toolchain_ast_struct_item_value(vader_box_t l0);

static void toolchain_ast_append_bitor_variants(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l0, &l3 };
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 580u) {
        t0 = l0.payload.obj;
        if (((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_op == INT32_C(8)) {
            t0 = l0.payload.obj;
            toolchain_ast_append_bitor_variants(((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_left, l1);
            t0 = l0.payload.obj;
            toolchain_ast_append_bitor_variants(((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_right, l1);
            { vader_gc_top = gc_frame.prev; return; }
        }
        l2 = l0.payload.obj;
        vader_array_push_ref((vader_array_t*) l1, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = l0;
    vader_array_push_ref((vader_array_t*) l1, l3.payload.obj);
    { vader_gc_top = gc_frame.prev; return; }
}

void* toolchain_ast_assign_places(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null(), l6 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l5, &l6 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(227u, 0u, 13u, 1503u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct_toolchain_ast_DestructureAssignStmt_t*) l0)->f_targets;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l5 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        if ((l5.tag == 636u || l5.tag == 641u)) {
            l6 = VADER_UNION_FIELD(vader_box_t, vader_struct_toolchain_ast_PlaceTarget_t, f_place, l5.payload.obj);
            vader_array_push_ref((vader_array_t*) l1, l6.payload.obj);
        } else if (!(l5.tag == 664u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l4 = (l4 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t toolchain_ast_binary_op_symbol(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 318u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 342u;
    } else if (l0 == INT32_C(2)) {
        l1 = 314u;
    } else if (l0 == INT32_C(3)) {
        l1 = 397u;
    } else if (l0 == INT32_C(4)) {
        l1 = 250u;
    } else if (l0 == INT32_C(5)) {
        l1 = 454u;
    } else if (l0 == INT32_C(6)) {
        l1 = 479u;
    } else if (l0 == INT32_C(7)) {
        l1 = 252u;
    } else if (l0 == INT32_C(8)) {
        l1 = 2957u;
    } else if (l0 == INT32_C(9)) {
        l1 = 927u;
    } else if (l0 == INT32_C(10)) {
        l1 = 253u;
    } else if (l0 == INT32_C(11)) {
        l1 = 2958u;
    } else if (l0 == INT32_C(12)) {
        l1 = 474u;
    } else if (l0 == INT32_C(13)) {
        l1 = 218u;
    } else if (l0 == INT32_C(14)) {
        l1 = 453u;
    } else if (l0 == INT32_C(15)) {
        l1 = 455u;
    } else if (l0 == INT32_C(16)) {
        l1 = 477u;
    } else if (l0 == INT32_C(17)) {
        l1 = 478u;
    } else if (l0 == INT32_C(18)) {
        l1 = 2119u;
    } else if (l0 == INT32_C(19)) {
        l1 = 2059u;
    } else if (l0 == INT32_C(20)) {
        l1 = 220u;
    } else if (l0 == INT32_C(21)) {
        l1 = 475u;
    } else if (l0 == INT32_C(22)) {
        l1 = 219u;
    } else if (l0 == INT32_C(23)) {
        l1 = 319u;
    } else if (l0 == INT32_C(24)) {
        l1 = 343u;
    } else {
        if (!(l0 == INT32_C(25))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 315u;
    }
    return l1;
}

vader_string_t toolchain_ast_c_header_of(void* l0) {
    vader_box_t l1;
    void* t0;
    vader_string_t t1;
    l1 = toolchain_ast_find_decorator(((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_decorators, 1635u);
    if (l1.tag == 0u) {
        return 0u;
    }
    t0 = l1.payload.obj;
    t1 = toolchain_ast_sole_string_argument(t0);
    return t1;
}

vader_string_t toolchain_ast_c_struct_spelling(void* l0, vader_string_t l1) {
    void* l2;
    vader_box_t l3;
    int64_t t0;
    vader_string_t t1;
    l3 = toolchain_ast_find_decorator(l0, 1638u);
    if (l3.tag == 0u) {
        return 0u;
    }
    l2 = l3.payload.obj;
    t0 = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l2)->f_args)->length;
    if (!(t0 == INT64_C(0))) {
        t1 = toolchain_ast_sole_string_argument(l2);
        return t1;
    }
    return l1;
}

vader_string_t toolchain_ast_c_type_of(void* l0) {
    vader_box_t l1;
    void* t0;
    vader_string_t t1;
    l1 = toolchain_ast_find_decorator(l0, 1639u);
    if (l1.tag == 0u) {
        return 0u;
    }
    t0 = l1.payload.obj;
    t1 = toolchain_ast_sole_string_argument(t0);
    return t1;
}

vader_box_t toolchain_ast_coalesce_fallback_expr(vader_box_t l0) {
    vader_box_t l1;
    void* t0;
    if (l0.tag == 642u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast_ReturnStmt_t*) t0)->f_value;
        return l1;
    }
    if ((l0.tag == 583u || l0.tag == 589u)) {
        l1 = vader_box_obj(0u, NULL);
    } else {
        if (!((l0.tag == 576u || l0.tag == 579u || l0.tag == 580u || l0.tag == 581u || l0.tag == 582u || l0.tag == 585u || l0.tag == 586u || l0.tag == 587u || l0.tag == 598u || l0.tag == 603u || l0.tag == 604u || l0.tag == 607u || l0.tag == 609u || l0.tag == 610u || l0.tag == 613u || l0.tag == 618u || l0.tag == 620u || l0.tag == 621u || l0.tag == 623u || l0.tag == 627u || l0.tag == 631u || l0.tag == 632u || l0.tag == 638u || l0.tag == 643u || l0.tag == 645u || l0.tag == 650u || l0.tag == 659u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = l0;
    }
    return l1;
}

void* toolchain_ast_collect_bitor_variants(vader_box_t l0) {
    void* l1 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(227u, 0u, 13u, 1503u);
    l1 = (void*) _a0_arr;
    toolchain_ast_append_bitor_variants(l0, l1);
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t toolchain_ast_compound_assign_op(void* l0) {
    vader_box_t l1;
    void* l2;
    void* l3;
    void* t0;
    bool t1;
    l1 = ((vader_struct_toolchain_ast_AssignStmt_t*) l0)->f_value;
    if (l1.tag == 580u) {
        t0 = l1.payload.obj;
        l2 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, ((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_left.payload.obj);
        l3 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, ((vader_struct_toolchain_ast_AssignStmt_t*) l0)->f_target.payload.obj);
        t1 = toolchain_span_Span_std_core_Equals_equals(l2, l3);
        if (t1) {
            t0 = l1.payload.obj;
            t1 = toolchain_ast_is_arith_op(((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_op);
            if (t1) {
                t0 = l1.payload.obj;
                return vader_box_i32(322u, (int32_t)(uint32_t) ((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_op);
            }
        }
        return vader_box_obj(0u, NULL);
    }
    return vader_box_obj(0u, NULL);
}

void* toolchain_ast_decl_decorators(vader_box_t l0) {
    void* l1;
    void* t0;
    if (l0.tag == 615u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast_ImportDecl_t*) t0)->f_decorators;
        return l1;
    }
    if (l0.tag == 605u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_decorators;
    } else if (l0.tag == 648u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast_StructDecl_t*) t0)->f_decorators;
    } else if (l0.tag == 599u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast_EnumDecl_t*) t0)->f_decorators;
    } else if (l0.tag == 655u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast_TraitDecl_t*) t0)->f_decorators;
    } else if (l0.tag == 614u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast_ImplDecl_t*) t0)->f_decorators;
    } else if (l0.tag == 657u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast_TypeAliasDecl_t*) t0)->f_decorators;
    } else if (l0.tag == 588u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast_ConstDecl_t*) t0)->f_decorators;
    } else {
        if (!(l0.tag == 577u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast_AssertDecl_t*) t0)->f_decorators;
    }
    return l1;
}

vader_box_t toolchain_ast_decl_name_span(vader_box_t l0) {
    vader_box_t l1;
    void* t0;
    void* t1;
    if (l0.tag == 605u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_name_span;
        l1 = vader_ref_box(t1);
        return l1;
    }
    if (l0.tag == 648u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_toolchain_ast_StructDecl_t*) t0)->f_name_span;
        l1 = vader_ref_box(t1);
    } else if (l0.tag == 599u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_toolchain_ast_EnumDecl_t*) t0)->f_name_span;
        l1 = vader_ref_box(t1);
    } else if (l0.tag == 655u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_toolchain_ast_TraitDecl_t*) t0)->f_name_span;
        l1 = vader_ref_box(t1);
    } else if (l0.tag == 657u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_toolchain_ast_TypeAliasDecl_t*) t0)->f_name_span;
        l1 = vader_ref_box(t1);
    } else if (l0.tag == 588u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_toolchain_ast_ConstDecl_t*) t0)->f_name_span;
        l1 = vader_ref_box(t1);
    } else {
        if (!((l0.tag == 577u || l0.tag == 614u || l0.tag == 615u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = vader_box_obj(0u, NULL);
    }
    return l1;
}

bool toolchain_ast_decorators_have(void* l0, vader_string_t l1) {
    vader_box_t t0;
    t0 = toolchain_ast_find_decorator(l0, l1);
    return !(t0.tag == 0u);
}

vader_string_t toolchain_ast_extern_symbol_of(void* l0) {
    void* l1;
    void* l3;
    vader_box_t l2;
    int64_t l4;
    vader_string_t t0;
    int64_t t1;
    vader_box_t t2;
    l2 = toolchain_ast_find_decorator(((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_decorators, 1862u);
    if (l2.tag == 0u) {
        t0 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_name;
        return t0;
    }
    l1 = l2.payload.obj;
    t1 = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l1)->f_args)->length;
    if (t1 == INT64_C(0)) {
        t0 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_name;
        return t0;
    }
    l3 = ((vader_struct_toolchain_ast_Decorator_t*) l1)->f_args;
    t1 = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l1)->f_args)->length;
    l4 = vader_chk_sub(i64, t1, INT64_C(1));
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    t2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
    l2 = toolchain_ast_string_literal_text(t2);
    if (l2.tag == 0u) {
        t0 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_name;
        return t0;
    }
    t0 = l2.payload.s;
    return t0;
}

vader_box_t toolchain_ast_find_decorator(void* l0, vader_string_t l1) {
    void* l2;
    void* l5;
    int64_t l3, l4;
    vader_string_t t0;
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t0 = ((vader_struct_toolchain_ast_Decorator_t*) l5)->f_name;
        if (t0 == l1) {
            return vader_ref_box(l5);
        }
        l4 = (l4 + INT64_C(1));
    }
    return vader_box_obj(0u, NULL);
}

bool toolchain_ast_inspect(vader_box_t l0, void* l1) {
    uint8_t l2;
    bool l3;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    bool t2;
    vader_box_t* gc_roots[2] = { &l0, &t0 };
    void** gc_raw_roots[2] = { &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_fn_t* _a0_fnobj = (vader_fn_t*) l1;
    t0 = ((vader_fn_erased_sig_1_t) _a0_fnobj->code)(_a0_fnobj->env, l0);
    l2 = ((uint8_t) t0.payload.i);
    if (l2 != INT32_C(0)) {
        { bool __vret = l2 == INT32_C(2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if ((l0.tag == 582u || l0.tag == 587u || l0.tag == 604u || l0.tag == 620u || l0.tag == 632u)) {
        l3 = false;
        { bool __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 645u) {
        t1 = l0.payload.obj;
        l3 = toolchain_ast_inspect_parts(((vader_struct_toolchain_ast_StringLitExpr_t*) t1)->f_parts, l1);
    } else if ((l0.tag == 598u || l0.tag == 610u)) {
        l3 = false;
    } else if (l0.tag == 585u) {
        t1 = l0.payload.obj;
        l3 = toolchain_ast_inspect_call(t1, l1);
    } else if (l0.tag == 603u) {
        t1 = l0.payload.obj;
        l3 = toolchain_ast_inspect(((vader_struct_toolchain_ast_FieldExpr_t*) t1)->f_target, l1);
    } else if (l0.tag == 618u) {
        t1 = l0.payload.obj;
        t2 = toolchain_ast_inspect(((vader_struct_toolchain_ast_IndexExpr_t*) t1)->f_target, l1);
        if (t2) {
            l3 = true;
        } else {
            t1 = l0.payload.obj;
            l3 = toolchain_ast_inspect(((vader_struct_toolchain_ast_IndexExpr_t*) t1)->f_index, l1);
        }
    } else if (l0.tag == 659u) {
        t1 = l0.payload.obj;
        l3 = toolchain_ast_inspect(((vader_struct_toolchain_ast_UnaryExpr_t*) t1)->f_operand, l1);
    } else if (l0.tag == 580u) {
        t1 = l0.payload.obj;
        t2 = toolchain_ast_inspect(((vader_struct_toolchain_ast_BinaryExpr_t*) t1)->f_left, l1);
        if (t2) {
            l3 = true;
        } else {
            t1 = l0.payload.obj;
            l3 = toolchain_ast_inspect(((vader_struct_toolchain_ast_BinaryExpr_t*) t1)->f_right, l1);
        }
    } else if (l0.tag == 631u) {
        t1 = l0.payload.obj;
        t2 = toolchain_ast_inspect(((vader_struct_toolchain_ast_NullCoalesceExpr_t*) t1)->f_left, l1);
        if (t2) {
            l3 = true;
        } else {
            t1 = l0.payload.obj;
            l3 = toolchain_ast_inspect(((vader_struct_toolchain_ast_NullCoalesceExpr_t*) t1)->f_fallback, l1);
        }
    } else if (l0.tag == 613u) {
        t1 = l0.payload.obj;
        l3 = toolchain_ast_inspect_if(t1, l1);
    } else if (l0.tag == 627u) {
        t1 = l0.payload.obj;
        t2 = toolchain_ast_inspect(((vader_struct_toolchain_ast_MatchExpr_t*) t1)->f_scrutinee, l1);
        if (t2) {
            l3 = true;
        } else {
            t1 = l0.payload.obj;
            l3 = toolchain_ast_inspect_arms(((vader_struct_toolchain_ast_MatchExpr_t*) t1)->f_arms, l1);
        }
    } else if (l0.tag == 581u) {
        t1 = l0.payload.obj;
        t2 = toolchain_ast_inspect_stmts(((vader_struct_toolchain_ast_BlockExpr_t*) t1)->f_stmts, l1);
        if (t2) {
            l3 = true;
        } else {
            t1 = l0.payload.obj;
            l3 = toolchain_ast_inspect_maybe(((vader_struct_toolchain_ast_BlockExpr_t*) t1)->f_trailing, l1);
        }
    } else if (l0.tag == 623u) {
        t1 = l0.payload.obj;
        l3 = toolchain_ast_inspect_lambda(t1, l1);
    } else if (l0.tag == 650u) {
        t1 = l0.payload.obj;
        t2 = toolchain_ast_inspect(((vader_struct_toolchain_ast_StructLitExpr_t*) t1)->f_type_name, l1);
        if (t2) {
            l3 = true;
        } else {
            t1 = l0.payload.obj;
            l3 = toolchain_ast_inspect_items(((vader_struct_toolchain_ast_StructLitExpr_t*) t1)->f_items, l1);
        }
    } else if (l0.tag == 643u) {
        t1 = l0.payload.obj;
        l3 = toolchain_ast_inspect_exprs(((vader_struct_toolchain_ast_SeqLitExpr_t*) t1)->f_elements, l1);
    } else if (l0.tag == 638u) {
        t1 = l0.payload.obj;
        t2 = toolchain_ast_inspect(((vader_struct_toolchain_ast_RangeExpr_t*) t1)->f_lower, l1);
        if (t2) {
            l3 = true;
        } else {
            t1 = l0.payload.obj;
            l3 = toolchain_ast_inspect(((vader_struct_toolchain_ast_RangeExpr_t*) t1)->f_upper, l1);
        }
    } else if (l0.tag == 586u) {
        t1 = l0.payload.obj;
        t2 = toolchain_ast_inspect(((vader_struct_toolchain_ast_CastExpr_t*) t1)->f_value, l1);
        if (t2) {
            l3 = true;
        } else {
            t1 = l0.payload.obj;
            l3 = toolchain_ast_inspect(((vader_struct_toolchain_ast_CastExpr_t*) t1)->f_target, l1);
        }
    } else if (l0.tag == 609u) {
        t1 = l0.payload.obj;
        t2 = toolchain_ast_inspect(((vader_struct_toolchain_ast_GenericInstExpr_t*) t1)->f_callee, l1);
        if (t2) {
            l3 = true;
        } else {
            t1 = l0.payload.obj;
            l3 = toolchain_ast_inspect_exprs(((vader_struct_toolchain_ast_GenericInstExpr_t*) t1)->f_type_args, l1);
        }
    } else if (l0.tag == 621u) {
        t1 = l0.payload.obj;
        l3 = toolchain_ast_inspect_exprs(((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) t1)->f_args, l1);
    } else if (l0.tag == 607u) {
        t1 = l0.payload.obj;
        t2 = toolchain_ast_inspect_exprs(((vader_struct_toolchain_ast_FnTypeExpr_t*) t1)->f_params, l1);
        if (t2) {
            l3 = true;
        } else {
            t1 = l0.payload.obj;
            l3 = toolchain_ast_inspect_maybe(((vader_struct_toolchain_ast_FnTypeExpr_t*) t1)->f_return_type, l1);
        }
    } else if (l0.tag == 576u) {
        t1 = l0.payload.obj;
        l3 = toolchain_ast_inspect(((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_element, l1);
    } else if (l0.tag == 579u) {
        t1 = l0.payload.obj;
        l3 = toolchain_ast_inspect(((vader_struct_toolchain_ast_AwaitExpr_t*) t1)->f_inner, l1);
    } else if (l0.tag == 624u) {
        t1 = l0.payload.obj;
        t2 = toolchain_ast_inspect_maybe(((vader_struct_toolchain_ast_LetStmt_t*) t1)->f_ty, l1);
        if (t2) {
            l3 = true;
        } else {
            t1 = l0.payload.obj;
            l3 = toolchain_ast_inspect(((vader_struct_toolchain_ast_LetStmt_t*) t1)->f_value, l1);
        }
    } else if (l0.tag == 578u) {
        t1 = l0.payload.obj;
        l3 = toolchain_ast_inspect_assign(t1, l1);
    } else if (l0.tag == 594u) {
        t1 = l0.payload.obj;
        t2 = toolchain_ast_inspect_targets(((vader_struct_toolchain_ast_DestructureAssignStmt_t*) t1)->f_targets, l1);
        if (t2) {
            l3 = true;
        } else {
            t1 = l0.payload.obj;
            l3 = toolchain_ast_inspect(((vader_struct_toolchain_ast_DestructureAssignStmt_t*) t1)->f_value, l1);
        }
    } else if (l0.tag == 602u) {
        t1 = l0.payload.obj;
        l3 = toolchain_ast_inspect(((vader_struct_toolchain_ast_ExprStmt_t*) t1)->f_expr, l1);
    } else if (l0.tag == 642u) {
        t1 = l0.payload.obj;
        l3 = toolchain_ast_inspect_maybe(((vader_struct_toolchain_ast_ReturnStmt_t*) t1)->f_value, l1);
    } else if (l0.tag == 665u) {
        t1 = l0.payload.obj;
        l3 = toolchain_ast_inspect(((vader_struct_toolchain_ast_YieldStmt_t*) t1)->f_value, l1);
    } else if (l0.tag == 608u) {
        t1 = l0.payload.obj;
        t2 = toolchain_ast_inspect_form(((vader_struct_toolchain_ast_ForStmt_t*) t1)->f_form, l1);
        if (t2) {
            l3 = true;
        } else {
            t1 = l0.payload.obj;
            l3 = toolchain_ast_inspect(vader_ref_box(((vader_struct_toolchain_ast_ForStmt_t*) t1)->f_body), l1);
        }
    } else if ((l0.tag == 583u || l0.tag == 589u)) {
        l3 = false;
    } else if (l0.tag == 592u) {
        t1 = l0.payload.obj;
        l3 = toolchain_ast_inspect_defer(((vader_struct_toolchain_ast_DeferStmt_t*) t1)->f_body, l1);
    } else if (l0.tag == 622u) {
        t1 = l0.payload.obj;
        t2 = toolchain_ast_inspect(((vader_struct_toolchain_ast_IsPattern_t*) t1)->f_ty, l1);
        if (t2) {
            l3 = true;
        } else {
            t1 = l0.payload.obj;
            l3 = toolchain_ast_inspect_maybe(((vader_struct_toolchain_ast_IsPattern_t*) t1)->f_inner, l1);
        }
    } else if (l0.tag == 653u) {
        t1 = l0.payload.obj;
        l3 = toolchain_ast_inspect_pattern_fields(((vader_struct_toolchain_ast_StructPattern_t*) t1)->f_fields, l1);
    } else if ((l0.tag == 601u || l0.tag == 663u)) {
        l3 = false;
    } else if (l0.tag == 625u) {
        t1 = l0.payload.obj;
        l3 = toolchain_ast_inspect(((vader_struct_toolchain_ast_LiteralPattern_t*) t1)->f_value, l1);
    } else if (l0.tag == 639u) {
        t1 = l0.payload.obj;
        t2 = toolchain_ast_inspect(((vader_struct_toolchain_ast_RangePattern_t*) t1)->f_lower, l1);
        if (t2) {
            l3 = true;
        } else {
            t1 = l0.payload.obj;
            l3 = toolchain_ast_inspect(((vader_struct_toolchain_ast_RangePattern_t*) t1)->f_upper, l1);
        }
    } else if (l0.tag == 633u) {
        t1 = l0.payload.obj;
        l3 = toolchain_ast_inspect_patterns(((vader_struct_toolchain_ast_OrPattern_t*) t1)->f_patterns, l1);
    } else if (l0.tag == 615u) {
        t1 = l0.payload.obj;
        l3 = toolchain_ast_inspect_decorators(((vader_struct_toolchain_ast_ImportDecl_t*) t1)->f_decorators, l1);
    } else if (l0.tag == 605u) {
        t1 = l0.payload.obj;
        l3 = toolchain_ast_inspect_fn(t1, l1);
    } else if (l0.tag == 648u) {
        t1 = l0.payload.obj;
        l3 = toolchain_ast_inspect_struct(t1, l1);
    } else if (l0.tag == 599u) {
        t1 = l0.payload.obj;
        l3 = toolchain_ast_inspect_enum(t1, l1);
    } else if (l0.tag == 655u) {
        t1 = l0.payload.obj;
        l3 = toolchain_ast_inspect_trait(t1, l1);
    } else if (l0.tag == 614u) {
        t1 = l0.payload.obj;
        l3 = toolchain_ast_inspect_impl(t1, l1);
    } else if (l0.tag == 657u) {
        t1 = l0.payload.obj;
        l3 = toolchain_ast_inspect_alias(t1, l1);
    } else if (l0.tag == 588u) {
        t1 = l0.payload.obj;
        l3 = toolchain_ast_inspect_const(t1, l1);
    } else {
        if (!(l0.tag == 577u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t1 = l0.payload.obj;
        t2 = toolchain_ast_inspect_decorators(((vader_struct_toolchain_ast_AssertDecl_t*) t1)->f_decorators, l1);
        if (t2) {
            l3 = true;
        } else {
            t1 = l0.payload.obj;
            l3 = toolchain_ast_inspect(((vader_struct_toolchain_ast_AssertDecl_t*) t1)->f_condition, l1);
        }
    }
    { bool __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool toolchain_ast_inspect_alias(void* l0, void* l1) {
    bool l2;
    bool t0;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = toolchain_ast_inspect_decorators(((vader_struct_toolchain_ast_TypeAliasDecl_t*) l0)->f_decorators, l1);
    if (t0) {
        l2 = true;
    } else {
        l2 = toolchain_ast_inspect_type_params(((vader_struct_toolchain_ast_TypeAliasDecl_t*) l0)->f_type_params, l1);
    }
    if (l2) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    t0 = toolchain_ast_inspect(((vader_struct_toolchain_ast_TypeAliasDecl_t*) l0)->f_aliased, l1);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool toolchain_ast_inspect_arms(void* l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    int64_t l3, l4;
    bool t0;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t0 = toolchain_ast_inspect(((vader_struct_toolchain_ast_MatchArm_t*) l5)->f_pattern, l1);
        if (t0) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        t0 = toolchain_ast_inspect_maybe(((vader_struct_toolchain_ast_MatchArm_t*) l5)->f_guard, l1);
        if (t0) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        t0 = toolchain_ast_inspect(((vader_struct_toolchain_ast_MatchArm_t*) l5)->f_body, l1);
        if (t0) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        l4 = (l4 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static bool toolchain_ast_inspect_assign(void* l0, void* l1) {
    vader_box_t t0 = vader_box_null();
    bool t1;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = toolchain_ast_compound_assign_op(l0);
    if (!(t0.tag == 0u)) {
        t1 = toolchain_ast_inspect(((vader_struct_toolchain_ast_AssignStmt_t*) l0)->f_value, l1);
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = toolchain_ast_inspect(((vader_struct_toolchain_ast_AssignStmt_t*) l0)->f_target, l1);
    if (t1) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    t1 = toolchain_ast_inspect(((vader_struct_toolchain_ast_AssignStmt_t*) l0)->f_value, l1);
    { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool toolchain_ast_inspect_call(void* l0, void* l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = toolchain_ast_inspect(((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_callee, l1);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    t0 = toolchain_ast_inspect_exprs(((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_type_args, l1);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    l2 = ((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_args;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t0 = toolchain_ast_inspect(((vader_struct_toolchain_ast_CallArg_t*) t1)->f_value, l1);
        if (t0) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        l4 = (l4 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static bool toolchain_ast_inspect_const(void* l0, void* l1) {
    bool l2;
    bool t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = toolchain_ast_inspect_decorators(((vader_struct_toolchain_ast_ConstDecl_t*) l0)->f_decorators, l1);
    if (t0) {
        l2 = true;
    } else {
        t1 = toolchain_ast_own_const_type(l0);
        l2 = toolchain_ast_inspect_maybe(t1, l1);
    }
    if (l2) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    t0 = toolchain_ast_inspect(((vader_struct_toolchain_ast_ConstDecl_t*) l0)->f_value, l1);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool toolchain_ast_inspect_decorators(void* l0, void* l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    void* t0 = NULL;
    bool t1;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t1 = toolchain_ast_inspect_exprs(((vader_struct_toolchain_ast_Decorator_t*) t0)->f_args, l1);
        if (t1) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        l4 = (l4 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static bool toolchain_ast_inspect_defer(vader_box_t l0, void* l1) {
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 593u) {
        t0 = l0.payload.obj;
        t1 = toolchain_ast_inspect(((vader_struct_toolchain_ast_DeferStmtBody_t*) t0)->f_stmt, l1);
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0.tag == 591u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    t0 = l0.payload.obj;
    t1 = toolchain_ast_inspect(vader_ref_box(((vader_struct_toolchain_ast_DeferBlockBody_t*) t0)->f_block), l1);
    { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool toolchain_ast_inspect_enum(void* l0, void* l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null();
    bool t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = toolchain_ast_inspect_decorators(((vader_struct_toolchain_ast_EnumDecl_t*) l0)->f_decorators, l1);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    t0 = toolchain_ast_inspect_exprs(((vader_struct_toolchain_ast_EnumDecl_t*) l0)->f_header, l1);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    l2 = ((vader_struct_toolchain_ast_EnumDecl_t*) l0)->f_variants;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        l5 = ((vader_struct_toolchain_ast_EnumVariant_t*) t1)->f_data;
        if (l5.tag == 0u) {
            l4 = (l4 + INT64_C(1));
            continue;
        }
        t1 = l5.payload.obj;
        t0 = toolchain_ast_inspect_items(t1, l1);
        if (t0) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        l4 = (l4 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static bool toolchain_ast_inspect_exprs(void* l0, void* l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    vader_box_t t0 = vader_box_null();
    bool t1;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t1 = toolchain_ast_inspect(t0, l1);
        if (t1) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        l4 = (l4 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static bool toolchain_ast_inspect_fn(void* l0, void* l1) {
    bool l2;
    bool t0;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = toolchain_ast_inspect_decorators(((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_decorators, l1);
    if (t0) {
        l2 = true;
    } else {
        l2 = toolchain_ast_inspect_type_params(((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_type_params, l1);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = toolchain_ast_inspect_params(((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_params, l1);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = toolchain_ast_inspect_maybe(((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_return_type, l1);
    }
    if (l2) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    t0 = toolchain_ast_inspect_maybe(((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_body, l1);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool toolchain_ast_inspect_fns(void* l0, void* l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    void* t0 = NULL;
    bool t1;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t1 = toolchain_ast_inspect(vader_ref_box(t0), l1);
        if (t1) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        l4 = (l4 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static bool toolchain_ast_inspect_form(vader_box_t l0, void* l1) {
    bool l2;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 617u) {
        t0 = l0.payload.obj;
        l2 = toolchain_ast_inspect(((vader_struct_toolchain_ast_InFor_t*) t0)->f_iter, l1);
        { bool __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 660u) {
        t0 = l0.payload.obj;
        l2 = toolchain_ast_inspect(((vader_struct_toolchain_ast_WhileFor_t*) t0)->f_cond, l1);
    } else {
        if (!(l0.tag == 619u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = false;
    }
    { bool __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool toolchain_ast_inspect_if(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null();
    bool l4;
    bool t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l2, &l3 };
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = toolchain_ast_inspect(((vader_struct_toolchain_ast_IfExpr_t*) l0)->f_cond, l1);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    t0 = toolchain_ast_inspect(vader_ref_box(((vader_struct_toolchain_ast_IfExpr_t*) l0)->f_then_block), l1);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    l2 = ((vader_struct_toolchain_ast_IfExpr_t*) l0)->f_else_branch;
    l3 = l2;
    if (l2.tag == 0u) {
        l4 = false;
        { bool __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2.tag == 612u) {
        t1 = l3.payload.obj;
        l4 = toolchain_ast_inspect(vader_ref_box(((vader_struct_toolchain_ast_IfElseIf_t*) t1)->f_branch), l1);
    } else {
        if (!(l2.tag == 611u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t1 = l3.payload.obj;
        l4 = toolchain_ast_inspect(vader_ref_box(((vader_struct_toolchain_ast_IfElseBlock_t*) t1)->f_block), l1);
    }
    { bool __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool toolchain_ast_inspect_impl(void* l0, void* l1) {
    bool l2;
    bool t0;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = toolchain_ast_inspect_decorators(((vader_struct_toolchain_ast_ImplDecl_t*) l0)->f_decorators, l1);
    if (t0) {
        l2 = true;
    } else {
        l2 = toolchain_ast_inspect_type_params(((vader_struct_toolchain_ast_ImplDecl_t*) l0)->f_type_params, l1);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = toolchain_ast_inspect(((vader_struct_toolchain_ast_ImplDecl_t*) l0)->f_for_type, l1);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = toolchain_ast_inspect_exprs(((vader_struct_toolchain_ast_ImplDecl_t*) l0)->f_trait_args, l1);
    }
    if (l2) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    t0 = toolchain_ast_inspect_fns(((vader_struct_toolchain_ast_ImplDecl_t*) l0)->f_members, l1);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool toolchain_ast_inspect_items(void* l0, void* l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    vader_box_t t0 = vader_box_null(), t1 = vader_box_null();
    bool t2;
    vader_box_t* gc_roots[2] = { &t0, &t1 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t1 = toolchain_ast_struct_item_value(t0);
        t2 = toolchain_ast_inspect(t1, l1);
        if (t2) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        l4 = (l4 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static bool toolchain_ast_inspect_lambda(void* l0, void* l1) {
    bool l2;
    bool t0;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = toolchain_ast_inspect_params(((vader_struct_toolchain_ast_LambdaExpr_t*) l0)->f_params, l1);
    if (t0) {
        l2 = true;
    } else {
        l2 = toolchain_ast_inspect_maybe(((vader_struct_toolchain_ast_LambdaExpr_t*) l0)->f_return_type, l1);
    }
    if (l2) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    t0 = toolchain_ast_inspect(vader_ref_box(((vader_struct_toolchain_ast_LambdaExpr_t*) l0)->f_body), l1);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool toolchain_ast_inspect_maybe(vader_box_t l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    bool t0;
    vader_box_t* gc_roots[2] = { &l0, &l2 };
    void** gc_raw_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l0;
    if (l2.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    t0 = toolchain_ast_inspect(l2, l1);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool toolchain_ast_inspect_params(void* l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    int64_t l3, l4;
    bool t0;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t0 = toolchain_ast_inspect_decorators(((vader_struct_toolchain_ast_FnParam_t*) l5)->f_decorators, l1);
        if (t0) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        t0 = toolchain_ast_inspect_maybe(((vader_struct_toolchain_ast_FnParam_t*) l5)->f_ty, l1);
        if (t0) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        t0 = toolchain_ast_inspect_maybe(((vader_struct_toolchain_ast_FnParam_t*) l5)->f_default_value, l1);
        if (t0) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        l4 = (l4 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static bool toolchain_ast_inspect_parts(void* l0, void* l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null();
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        if (l5.tag == 646u) {
            t0 = l5.payload.obj;
            t1 = toolchain_ast_inspect(((vader_struct_toolchain_ast_StringLitInterp_t*) t0)->f_expr, l1);
            if (t1) {
                { vader_gc_top = gc_frame.prev; return true; }
            }
        }
        l4 = (l4 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static bool toolchain_ast_inspect_pattern_fields(void* l0, void* l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null();
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        l5 = ((vader_struct_toolchain_ast_StructPatternField_t*) t0)->f_value;
        if (l5.tag == 635u) {
            t0 = l5.payload.obj;
            t1 = toolchain_ast_inspect(((vader_struct_toolchain_ast_PatternLiteral_t*) t0)->f_value, l1);
            if (t1) {
                { vader_gc_top = gc_frame.prev; return true; }
            }
        }
        l4 = (l4 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static bool toolchain_ast_inspect_patterns(void* l0, void* l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    vader_box_t t0 = vader_box_null();
    bool t1;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t1 = toolchain_ast_inspect(t0, l1);
        if (t1) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        l4 = (l4 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static bool toolchain_ast_inspect_stmts(void* l0, void* l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    vader_box_t t0 = vader_box_null();
    bool t1;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t1 = toolchain_ast_inspect(t0, l1);
        if (t1) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        l4 = (l4 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static bool toolchain_ast_inspect_struct(void* l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    int64_t l3, l4;
    bool t0;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = toolchain_ast_inspect_decorators(((vader_struct_toolchain_ast_StructDecl_t*) l0)->f_decorators, l1);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    t0 = toolchain_ast_inspect_type_params(((vader_struct_toolchain_ast_StructDecl_t*) l0)->f_type_params, l1);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    l2 = ((vader_struct_toolchain_ast_StructDecl_t*) l0)->f_fields;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t0 = toolchain_ast_inspect(((vader_struct_toolchain_ast_StructField_t*) l5)->f_ty, l1);
        if (t0) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        t0 = toolchain_ast_inspect_maybe(((vader_struct_toolchain_ast_StructField_t*) l5)->f_default_v, l1);
        if (t0) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        l4 = (l4 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static bool toolchain_ast_inspect_targets(void* l0, void* l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null();
    bool t0;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        if ((l5.tag == 636u || l5.tag == 641u)) {
            t0 = toolchain_ast_inspect(VADER_UNION_FIELD(vader_box_t, vader_struct_toolchain_ast_PlaceTarget_t, f_place, l5.payload.obj), l1);
            if (t0) {
                { vader_gc_top = gc_frame.prev; return true; }
            }
        } else if (!(l5.tag == 664u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l4 = (l4 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static bool toolchain_ast_inspect_trait(void* l0, void* l1) {
    bool l2;
    bool t0;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = toolchain_ast_inspect_decorators(((vader_struct_toolchain_ast_TraitDecl_t*) l0)->f_decorators, l1);
    if (t0) {
        l2 = true;
    } else {
        l2 = toolchain_ast_inspect_type_params(((vader_struct_toolchain_ast_TraitDecl_t*) l0)->f_type_params, l1);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = toolchain_ast_inspect_maybe(((vader_struct_toolchain_ast_TraitDecl_t*) l0)->f_requires, l1);
    }
    if (l2) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    t0 = toolchain_ast_inspect_fns(((vader_struct_toolchain_ast_TraitDecl_t*) l0)->f_members, l1);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool toolchain_ast_inspect_type_params(void* l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    int64_t l3, l4;
    bool t0;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t0 = toolchain_ast_inspect_maybe(((vader_struct_toolchain_ast_TypeParam_t*) l5)->f_bound, l1);
        if (t0) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        t0 = toolchain_ast_inspect_maybe(((vader_struct_toolchain_ast_TypeParam_t*) l5)->f_default_v, l1);
        if (t0) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        l4 = (l4 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

vader_string_t toolchain_ast_int_literal_text(void* l0) {
    void* l1 = NULL;
    int64_t l2;
    uint64_t l3;
    bool t0;
    vader_string_t t1 = 0;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_toolchain_ast_IntLitExpr_t*) l0)->f_negative;
    if (!(t0)) {
        l1 = (void*) vader_buffer_new((size_t) INT64_C(20));
        l2 = INT64_C(0);
        l3 = ((vader_struct_toolchain_ast_IntLitExpr_t*) l0)->f_value;
        l2 = std_core_write_unsigned(l1, l2, l3);
        t1 = std_core_finish_buffer(l1, l2);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = (void*) vader_buffer_new((size_t) INT64_C(21));
    l2 = INT64_C(0);
    l2 = std_core_write_string_at(l1, l2, 342u);
    l3 = ((vader_struct_toolchain_ast_IntLitExpr_t*) l0)->f_value;
    l2 = std_core_write_unsigned(l1, l2, l3);
    t1 = std_core_finish_buffer(l1, l2);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

int64_t toolchain_ast_int_literal_value(void* l0) {
    int64_t l1;
    bool t0;
    uint64_t t1;
    t0 = ((vader_struct_toolchain_ast_IntLitExpr_t*) l0)->f_negative;
    if (!(t0)) {
        t1 = ((vader_struct_toolchain_ast_IntLitExpr_t*) l0)->f_value;
        return ((int64_t) (uint64_t) t1);
    }
    t1 = ((vader_struct_toolchain_ast_IntLitExpr_t*) l0)->f_value;
    l1 = ((int64_t) (uint64_t) t1);
    return (INT64_C(0) - l1);
}

static bool toolchain_ast_is_arith_op(uint8_t l0) {
    bool l1, l2;
    if (l0 == INT32_C(0)) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(1);
    }
    if (l1) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(2);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(3);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(4);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(23);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(24);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(25);
    }
    if (l2) {
        l1 = true;
        return l1;
    }
    if (l0 == INT32_C(5)) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(6);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(7);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(8);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(9);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(10);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(11);
    }
    if (l2) {
        l1 = false;
    } else {
        if (l0 == INT32_C(12)) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(13);
        }
        if (l2) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(14);
        }
        if (l2) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(15);
        }
        if (l2) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(16);
        }
        if (l2) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(17);
        }
        if (l2) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(18);
        }
        if (l2) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(19);
        }
        if (l2) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(20);
        }
        if (l2) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(21);
        }
        if (l2) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(22);
        }
        if (!(l2)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = false;
    }
    return l1;
}

static vader_box_t toolchain_ast_own_const_type(void* l0) {
    if (!(((vader_struct_toolchain_ast_ConstDecl_t*) l0)->f_comptime_body.tag == 0u)) {
        return vader_box_obj(0u, NULL);
    }
    return ((vader_struct_toolchain_ast_ConstDecl_t*) l0)->f_ty;
}

static vader_string_t toolchain_ast_sole_string_argument(void* l0) {
    vader_box_t l1;
    int64_t t0;
    vader_box_t t1;
    vader_string_t t2;
    t0 = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l0)->f_args)->length;
    if (t0 != INT64_C(1)) {
        return 0u;
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l0)->f_args);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
    t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
    l1 = toolchain_ast_string_literal_text(t1);
    if (l1.tag == 0u) {
        return 0u;
    }
    t2 = l1.payload.s;
    return t2;
}

vader_box_t toolchain_ast_string_literal_text(vader_box_t l0) {
    vader_box_t l1;
    void* t0;
    int64_t t1;
    vader_string_t t2;
    if (l0.tag == 645u) {
        t0 = l0.payload.obj;
        t1 = ((vader_array_t*) ((vader_struct_toolchain_ast_StringLitExpr_t*) t0)->f_parts)->length;
        if (t1 != INT64_C(1)) {
            return vader_box_obj(0u, NULL);
        }
        t0 = l0.payload.obj;
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_StringLitExpr_t*) t0)->f_parts);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
        l1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
        if (!(l1.tag == 647u)) {
            return vader_box_obj(0u, NULL);
        }
        t0 = l1.payload.obj;
        t2 = ((vader_struct_toolchain_ast_StringLitText_t*) t0)->f_value;
        return vader_box_string(317u, t2);
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t toolchain_ast_struct_item_value(vader_box_t l0) {
    void* t0;
    if (l0.tag == 651u) {
        t0 = l0.payload.obj;
        return ((vader_struct_toolchain_ast_StructLitField_t*) t0)->f_value;
    }
    if (!(l0.tag == 652u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    t0 = l0.payload.obj;
    return ((vader_struct_toolchain_ast_StructLitSpread_t*) t0)->f_expr;
}
