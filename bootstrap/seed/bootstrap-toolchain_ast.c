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
static vader_box_t toolchain_ast_struct_item_value(vader_box_t l0);

static void toolchain_ast_append_bitor_variants(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l0, &l3 };
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 528u) {
        t0 = l0.payload.obj;
        if (((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_op == INT32_C(8)) {
            t0 = l0.payload.obj;
            toolchain_ast_append_bitor_variants(((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_left, l1);
            t0 = l0.payload.obj;
            toolchain_ast_append_bitor_variants(((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_right, l1);
            { vader_gc_top = gc_frame.prev; return; }
        }
        l2 = l0.payload.obj;
        vader_array_push((vader_array_t*) l1, vader_ref_box(l2));
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = l0;
    vader_array_push((vader_array_t*) l1, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

void* toolchain_ast_assign_places(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null(), l6 = vader_box_null();
    size_t t0;
    vader_box_t* gc_roots[2] = { &l5, &l6 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(214u, 0u, 13u, 1436u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct_toolchain_ast_DestructureAssignStmt_t*) l0)->f_targets;
    t0 = ((vader_array_t*) l2)->length;
    l3 = (int64_t) (size_t) t0;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l5 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        if ((l5.tag == 584u || l5.tag == 589u)) {
            l6 = VADER_UNION_FIELD(vader_box_t, vader_struct_toolchain_ast_PlaceTarget_t, f_place, l5.payload.obj);
            vader_array_push((vader_array_t*) l1, l6);
        } else if (!(l5.tag == 612u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l4 = (l4 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t toolchain_ast_binary_op_symbol(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 291u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 314u;
    } else if (l0 == INT32_C(2)) {
        l1 = 287u;
    } else if (l0 == INT32_C(3)) {
        l1 = 368u;
    } else if (l0 == INT32_C(4)) {
        l1 = 224u;
    } else if (l0 == INT32_C(5)) {
        l1 = 423u;
    } else if (l0 == INT32_C(6)) {
        l1 = 447u;
    } else if (l0 == INT32_C(7)) {
        l1 = 226u;
    } else if (l0 == INT32_C(8)) {
        l1 = 2797u;
    } else if (l0 == INT32_C(9)) {
        l1 = 838u;
    } else if (l0 == INT32_C(10)) {
        l1 = 227u;
    } else if (l0 == INT32_C(11)) {
        l1 = 2798u;
    } else if (l0 == INT32_C(12)) {
        l1 = 442u;
    } else if (l0 == INT32_C(13)) {
        l1 = 192u;
    } else if (l0 == INT32_C(14)) {
        l1 = 422u;
    } else if (l0 == INT32_C(15)) {
        l1 = 424u;
    } else if (l0 == INT32_C(16)) {
        l1 = 445u;
    } else if (l0 == INT32_C(17)) {
        l1 = 446u;
    } else if (l0 == INT32_C(18)) {
        l1 = 1984u;
    } else if (l0 == INT32_C(19)) {
        l1 = 1925u;
    } else if (l0 == INT32_C(20)) {
        l1 = 194u;
    } else if (l0 == INT32_C(21)) {
        l1 = 443u;
    } else if (l0 == INT32_C(22)) {
        l1 = 193u;
    } else if (l0 == INT32_C(23)) {
        l1 = 292u;
    } else if (l0 == INT32_C(24)) {
        l1 = 315u;
    } else {
        if (!(l0 == INT32_C(25))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 288u;
    }
    return l1;
}

vader_box_t toolchain_ast_coalesce_fallback_expr(vader_box_t l0) {
    vader_box_t l1;
    void* t0;
    if (l0.tag == 590u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast_ReturnStmt_t*) t0)->f_value;
        return l1;
    }
    if ((l0.tag == 531u || l0.tag == 537u)) {
        l1 = vader_box_obj(0u, NULL);
    } else {
        if (!((l0.tag == 523u || l0.tag == 527u || l0.tag == 528u || l0.tag == 529u || l0.tag == 530u || l0.tag == 533u || l0.tag == 534u || l0.tag == 535u || l0.tag == 546u || l0.tag == 551u || l0.tag == 552u || l0.tag == 555u || l0.tag == 557u || l0.tag == 558u || l0.tag == 561u || l0.tag == 566u || l0.tag == 568u || l0.tag == 569u || l0.tag == 571u || l0.tag == 575u || l0.tag == 579u || l0.tag == 580u || l0.tag == 586u || l0.tag == 591u || l0.tag == 593u || l0.tag == 598u || l0.tag == 607u))) {
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
    vader_array_t* _a0_arr = vader_array_new(214u, 0u, 13u, 1436u);
    l1 = (void*) _a0_arr;
    toolchain_ast_append_bitor_variants(l0, l1);
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t toolchain_ast_compound_assign_op(void* l0) {
    void* l1;
    void* l2;
    void* l3;
    bool t0;
    vader_box_t t1;
    if (((vader_struct_toolchain_ast_AssignStmt_t*) l0)->f_value.tag == 528u) {
        l1 = ((vader_struct_toolchain_ast_AssignStmt_t*) l0)->f_value.payload.obj;
        l2 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, ((vader_struct_toolchain_ast_BinaryExpr_t*) l1)->f_left.payload.obj);
        l3 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, ((vader_struct_toolchain_ast_AssignStmt_t*) l0)->f_target.payload.obj);
        t0 = toolchain_span_Span_std_core_Equals_equals(l2, l3);
        if (t0) {
            t0 = toolchain_ast_is_arith_op(((vader_struct_toolchain_ast_BinaryExpr_t*) l1)->f_op);
            if (t0) {
                t1 = vader_box_i32(291u, (int32_t)(uint32_t) ((vader_struct_toolchain_ast_BinaryExpr_t*) l1)->f_op);
                return t1;
            }
        }
        return vader_box_obj(0u, NULL);
    }
    return vader_box_obj(0u, NULL);
}

vader_box_t toolchain_ast_decl_name_span(vader_box_t l0) {
    vader_box_t l1;
    void* t0;
    void* t1;
    if (l0.tag == 553u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_name_span;
        l1 = vader_ref_box(t1);
        return l1;
    }
    if (l0.tag == 596u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_toolchain_ast_StructDecl_t*) t0)->f_name_span;
        l1 = vader_ref_box(t1);
    } else if (l0.tag == 547u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_toolchain_ast_EnumDecl_t*) t0)->f_name_span;
        l1 = vader_ref_box(t1);
    } else if (l0.tag == 603u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_toolchain_ast_TraitDecl_t*) t0)->f_name_span;
        l1 = vader_ref_box(t1);
    } else if (l0.tag == 605u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_toolchain_ast_TypeAliasDecl_t*) t0)->f_name_span;
        l1 = vader_ref_box(t1);
    } else if (l0.tag == 536u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_toolchain_ast_ConstDecl_t*) t0)->f_name_span;
        l1 = vader_ref_box(t1);
    } else {
        if (!((l0.tag == 525u || l0.tag == 562u || l0.tag == 563u))) {
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

vader_box_t toolchain_ast_find_decorator(void* l0, vader_string_t l1) {
    void* l2;
    void* l5;
    int64_t l3, l4;
    size_t t0;
    vader_string_t t1;
    l2 = l0;
    t0 = ((vader_array_t*) l2)->length;
    l3 = (int64_t) (size_t) t0;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t1 = ((vader_struct_toolchain_ast_Decorator_t*) l5)->f_name;
        if (t1 == l1) {
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
    if ((l0.tag == 530u || l0.tag == 535u || l0.tag == 552u || l0.tag == 568u || l0.tag == 580u)) {
        l3 = false;
        { bool __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 593u) {
        t1 = l0.payload.obj;
        l3 = toolchain_ast_inspect_parts(((vader_struct_toolchain_ast_StringLitExpr_t*) t1)->f_parts, l1);
    } else if ((l0.tag == 546u || l0.tag == 558u)) {
        l3 = false;
    } else if (l0.tag == 533u) {
        t1 = l0.payload.obj;
        l3 = toolchain_ast_inspect_call(t1, l1);
    } else if (l0.tag == 551u) {
        t1 = l0.payload.obj;
        l3 = toolchain_ast_inspect(((vader_struct_toolchain_ast_FieldExpr_t*) t1)->f_target, l1);
    } else if (l0.tag == 566u) {
        t1 = l0.payload.obj;
        t2 = toolchain_ast_inspect(((vader_struct_toolchain_ast_IndexExpr_t*) t1)->f_target, l1);
        if (t2) {
            l3 = true;
        } else {
            t1 = l0.payload.obj;
            l3 = toolchain_ast_inspect(((vader_struct_toolchain_ast_IndexExpr_t*) t1)->f_index, l1);
        }
    } else if (l0.tag == 607u) {
        t1 = l0.payload.obj;
        l3 = toolchain_ast_inspect(((vader_struct_toolchain_ast_UnaryExpr_t*) t1)->f_operand, l1);
    } else if (l0.tag == 528u) {
        t1 = l0.payload.obj;
        t2 = toolchain_ast_inspect(((vader_struct_toolchain_ast_BinaryExpr_t*) t1)->f_left, l1);
        if (t2) {
            l3 = true;
        } else {
            t1 = l0.payload.obj;
            l3 = toolchain_ast_inspect(((vader_struct_toolchain_ast_BinaryExpr_t*) t1)->f_right, l1);
        }
    } else if (l0.tag == 579u) {
        t1 = l0.payload.obj;
        t2 = toolchain_ast_inspect(((vader_struct_toolchain_ast_NullCoalesceExpr_t*) t1)->f_left, l1);
        if (t2) {
            l3 = true;
        } else {
            t1 = l0.payload.obj;
            l3 = toolchain_ast_inspect(((vader_struct_toolchain_ast_NullCoalesceExpr_t*) t1)->f_fallback, l1);
        }
    } else if (l0.tag == 561u) {
        t1 = l0.payload.obj;
        l3 = toolchain_ast_inspect_if(t1, l1);
    } else if (l0.tag == 575u) {
        t1 = l0.payload.obj;
        t2 = toolchain_ast_inspect(((vader_struct_toolchain_ast_MatchExpr_t*) t1)->f_scrutinee, l1);
        if (t2) {
            l3 = true;
        } else {
            t1 = l0.payload.obj;
            l3 = toolchain_ast_inspect_arms(((vader_struct_toolchain_ast_MatchExpr_t*) t1)->f_arms, l1);
        }
    } else if (l0.tag == 529u) {
        t1 = l0.payload.obj;
        t2 = toolchain_ast_inspect_stmts(((vader_struct_toolchain_ast_BlockExpr_t*) t1)->f_stmts, l1);
        if (t2) {
            l3 = true;
        } else {
            t1 = l0.payload.obj;
            l3 = toolchain_ast_inspect_maybe(((vader_struct_toolchain_ast_BlockExpr_t*) t1)->f_trailing, l1);
        }
    } else if (l0.tag == 571u) {
        t1 = l0.payload.obj;
        l3 = toolchain_ast_inspect_lambda(t1, l1);
    } else if (l0.tag == 598u) {
        t1 = l0.payload.obj;
        t2 = toolchain_ast_inspect(((vader_struct_toolchain_ast_StructLitExpr_t*) t1)->f_type_name, l1);
        if (t2) {
            l3 = true;
        } else {
            t1 = l0.payload.obj;
            l3 = toolchain_ast_inspect_items(((vader_struct_toolchain_ast_StructLitExpr_t*) t1)->f_items, l1);
        }
    } else if (l0.tag == 591u) {
        t1 = l0.payload.obj;
        l3 = toolchain_ast_inspect_exprs(((vader_struct_toolchain_ast_SeqLitExpr_t*) t1)->f_elements, l1);
    } else if (l0.tag == 586u) {
        t1 = l0.payload.obj;
        t2 = toolchain_ast_inspect(((vader_struct_toolchain_ast_RangeExpr_t*) t1)->f_lower, l1);
        if (t2) {
            l3 = true;
        } else {
            t1 = l0.payload.obj;
            l3 = toolchain_ast_inspect(((vader_struct_toolchain_ast_RangeExpr_t*) t1)->f_upper, l1);
        }
    } else if (l0.tag == 534u) {
        t1 = l0.payload.obj;
        t2 = toolchain_ast_inspect(((vader_struct_toolchain_ast_CastExpr_t*) t1)->f_value, l1);
        if (t2) {
            l3 = true;
        } else {
            t1 = l0.payload.obj;
            l3 = toolchain_ast_inspect(((vader_struct_toolchain_ast_CastExpr_t*) t1)->f_target, l1);
        }
    } else if (l0.tag == 557u) {
        t1 = l0.payload.obj;
        t2 = toolchain_ast_inspect(((vader_struct_toolchain_ast_GenericInstExpr_t*) t1)->f_callee, l1);
        if (t2) {
            l3 = true;
        } else {
            t1 = l0.payload.obj;
            l3 = toolchain_ast_inspect_exprs(((vader_struct_toolchain_ast_GenericInstExpr_t*) t1)->f_type_args, l1);
        }
    } else if (l0.tag == 569u) {
        t1 = l0.payload.obj;
        l3 = toolchain_ast_inspect_exprs(((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) t1)->f_args, l1);
    } else if (l0.tag == 555u) {
        t1 = l0.payload.obj;
        t2 = toolchain_ast_inspect_exprs(((vader_struct_toolchain_ast_FnTypeExpr_t*) t1)->f_params, l1);
        if (t2) {
            l3 = true;
        } else {
            t1 = l0.payload.obj;
            l3 = toolchain_ast_inspect_maybe(((vader_struct_toolchain_ast_FnTypeExpr_t*) t1)->f_return_type, l1);
        }
    } else if (l0.tag == 523u) {
        t1 = l0.payload.obj;
        l3 = toolchain_ast_inspect(((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_element, l1);
    } else if (l0.tag == 527u) {
        t1 = l0.payload.obj;
        l3 = toolchain_ast_inspect(((vader_struct_toolchain_ast_AwaitExpr_t*) t1)->f_inner, l1);
    } else if (l0.tag == 572u) {
        t1 = l0.payload.obj;
        t2 = toolchain_ast_inspect_maybe(((vader_struct_toolchain_ast_LetStmt_t*) t1)->f_ty, l1);
        if (t2) {
            l3 = true;
        } else {
            t1 = l0.payload.obj;
            l3 = toolchain_ast_inspect(((vader_struct_toolchain_ast_LetStmt_t*) t1)->f_value, l1);
        }
    } else if (l0.tag == 526u) {
        t1 = l0.payload.obj;
        l3 = toolchain_ast_inspect_assign(t1, l1);
    } else if (l0.tag == 542u) {
        t1 = l0.payload.obj;
        t2 = toolchain_ast_inspect_targets(((vader_struct_toolchain_ast_DestructureAssignStmt_t*) t1)->f_targets, l1);
        if (t2) {
            l3 = true;
        } else {
            t1 = l0.payload.obj;
            l3 = toolchain_ast_inspect(((vader_struct_toolchain_ast_DestructureAssignStmt_t*) t1)->f_value, l1);
        }
    } else if (l0.tag == 550u) {
        t1 = l0.payload.obj;
        l3 = toolchain_ast_inspect(((vader_struct_toolchain_ast_ExprStmt_t*) t1)->f_expr, l1);
    } else if (l0.tag == 590u) {
        t1 = l0.payload.obj;
        l3 = toolchain_ast_inspect_maybe(((vader_struct_toolchain_ast_ReturnStmt_t*) t1)->f_value, l1);
    } else if (l0.tag == 613u) {
        t1 = l0.payload.obj;
        l3 = toolchain_ast_inspect(((vader_struct_toolchain_ast_YieldStmt_t*) t1)->f_value, l1);
    } else if (l0.tag == 556u) {
        t1 = l0.payload.obj;
        t2 = toolchain_ast_inspect_form(((vader_struct_toolchain_ast_ForStmt_t*) t1)->f_form, l1);
        if (t2) {
            l3 = true;
        } else {
            t1 = l0.payload.obj;
            l3 = toolchain_ast_inspect(vader_ref_box(((vader_struct_toolchain_ast_ForStmt_t*) t1)->f_body), l1);
        }
    } else if ((l0.tag == 531u || l0.tag == 537u)) {
        l3 = false;
    } else if (l0.tag == 540u) {
        t1 = l0.payload.obj;
        l3 = toolchain_ast_inspect_defer(((vader_struct_toolchain_ast_DeferStmt_t*) t1)->f_body, l1);
    } else if (l0.tag == 570u) {
        t1 = l0.payload.obj;
        t2 = toolchain_ast_inspect(((vader_struct_toolchain_ast_IsPattern_t*) t1)->f_ty, l1);
        if (t2) {
            l3 = true;
        } else {
            t1 = l0.payload.obj;
            l3 = toolchain_ast_inspect_maybe(((vader_struct_toolchain_ast_IsPattern_t*) t1)->f_inner, l1);
        }
    } else if (l0.tag == 601u) {
        t1 = l0.payload.obj;
        l3 = toolchain_ast_inspect_pattern_fields(((vader_struct_toolchain_ast_StructPattern_t*) t1)->f_fields, l1);
    } else if ((l0.tag == 549u || l0.tag == 611u)) {
        l3 = false;
    } else if (l0.tag == 573u) {
        t1 = l0.payload.obj;
        l3 = toolchain_ast_inspect(((vader_struct_toolchain_ast_LiteralPattern_t*) t1)->f_value, l1);
    } else if (l0.tag == 587u) {
        t1 = l0.payload.obj;
        t2 = toolchain_ast_inspect(((vader_struct_toolchain_ast_RangePattern_t*) t1)->f_lower, l1);
        if (t2) {
            l3 = true;
        } else {
            t1 = l0.payload.obj;
            l3 = toolchain_ast_inspect(((vader_struct_toolchain_ast_RangePattern_t*) t1)->f_upper, l1);
        }
    } else if (l0.tag == 581u) {
        t1 = l0.payload.obj;
        l3 = toolchain_ast_inspect_patterns(((vader_struct_toolchain_ast_OrPattern_t*) t1)->f_patterns, l1);
    } else if (l0.tag == 563u) {
        t1 = l0.payload.obj;
        l3 = toolchain_ast_inspect_decorators(((vader_struct_toolchain_ast_ImportDecl_t*) t1)->f_decorators, l1);
    } else if (l0.tag == 553u) {
        t1 = l0.payload.obj;
        l3 = toolchain_ast_inspect_fn(t1, l1);
    } else if (l0.tag == 596u) {
        t1 = l0.payload.obj;
        l3 = toolchain_ast_inspect_struct(t1, l1);
    } else if (l0.tag == 547u) {
        t1 = l0.payload.obj;
        l3 = toolchain_ast_inspect_enum(t1, l1);
    } else if (l0.tag == 603u) {
        t1 = l0.payload.obj;
        l3 = toolchain_ast_inspect_trait(t1, l1);
    } else if (l0.tag == 562u) {
        t1 = l0.payload.obj;
        l3 = toolchain_ast_inspect_impl(t1, l1);
    } else if (l0.tag == 605u) {
        t1 = l0.payload.obj;
        l3 = toolchain_ast_inspect_alias(t1, l1);
    } else if (l0.tag == 536u) {
        t1 = l0.payload.obj;
        l3 = toolchain_ast_inspect_const(t1, l1);
    } else {
        if (!(l0.tag == 525u)) {
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
    size_t t0;
    bool t1;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l0;
    t0 = ((vader_array_t*) l2)->length;
    l3 = (int64_t) (size_t) t0;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t1 = toolchain_ast_inspect(((vader_struct_toolchain_ast_MatchArm_t*) l5)->f_pattern, l1);
        if (t1) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        t1 = toolchain_ast_inspect_maybe(((vader_struct_toolchain_ast_MatchArm_t*) l5)->f_guard, l1);
        if (t1) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        t1 = toolchain_ast_inspect(((vader_struct_toolchain_ast_MatchArm_t*) l5)->f_body, l1);
        if (t1) {
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
    size_t t1;
    void* t2 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t2 };
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
    t1 = ((vader_array_t*) l2)->length;
    l3 = (int64_t) (size_t) t1;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t0 = toolchain_ast_inspect(((vader_struct_toolchain_ast_CallArg_t*) t2)->f_value, l1);
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
    size_t t0;
    void* t1 = NULL;
    bool t2;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l0;
    t0 = ((vader_array_t*) l2)->length;
    l3 = (int64_t) (size_t) t0;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t2 = toolchain_ast_inspect_exprs(((vader_struct_toolchain_ast_Decorator_t*) t1)->f_args, l1);
        if (t2) {
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
    if (l0.tag == 541u) {
        t0 = l0.payload.obj;
        t1 = toolchain_ast_inspect(((vader_struct_toolchain_ast_DeferStmtBody_t*) t0)->f_stmt, l1);
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0.tag == 539u)) {
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
    size_t t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t2 };
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
    t1 = ((vader_array_t*) l2)->length;
    l3 = (int64_t) (size_t) t1;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        l5 = ((vader_struct_toolchain_ast_EnumVariant_t*) t2)->f_data;
        if (l5.tag == 0u) {
            l4 = (l4 + INT64_C(1));
            continue;
        }
        t2 = l5.payload.obj;
        t0 = toolchain_ast_inspect_items(t2, l1);
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
    size_t t0;
    vader_box_t t1 = vader_box_null();
    bool t2;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l0;
    t0 = ((vader_array_t*) l2)->length;
    l3 = (int64_t) (size_t) t0;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t2 = toolchain_ast_inspect(t1, l1);
        if (t2) {
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
    size_t t0;
    void* t1 = NULL;
    bool t2;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l0;
    t0 = ((vader_array_t*) l2)->length;
    l3 = (int64_t) (size_t) t0;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t2 = toolchain_ast_inspect(vader_ref_box(t1), l1);
        if (t2) {
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
    if (l0.tag == 565u) {
        t0 = l0.payload.obj;
        l2 = toolchain_ast_inspect(((vader_struct_toolchain_ast_InFor_t*) t0)->f_iter, l1);
        { bool __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 608u) {
        t0 = l0.payload.obj;
        l2 = toolchain_ast_inspect(((vader_struct_toolchain_ast_WhileFor_t*) t0)->f_cond, l1);
    } else {
        if (!(l0.tag == 567u)) {
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
    if (l2.tag == 560u) {
        t1 = l3.payload.obj;
        l4 = toolchain_ast_inspect(vader_ref_box(((vader_struct_toolchain_ast_IfElseIf_t*) t1)->f_branch), l1);
    } else {
        if (!(l2.tag == 559u)) {
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
    size_t t0;
    vader_box_t t1 = vader_box_null(), t2 = vader_box_null();
    bool t3;
    vader_box_t* gc_roots[2] = { &t1, &t2 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l0;
    t0 = ((vader_array_t*) l2)->length;
    l3 = (int64_t) (size_t) t0;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t2 = toolchain_ast_struct_item_value(t1);
        t3 = toolchain_ast_inspect(t2, l1);
        if (t3) {
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
    size_t t0;
    bool t1;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l0;
    t0 = ((vader_array_t*) l2)->length;
    l3 = (int64_t) (size_t) t0;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t1 = toolchain_ast_inspect_decorators(((vader_struct_toolchain_ast_FnParam_t*) l5)->f_decorators, l1);
        if (t1) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        t1 = toolchain_ast_inspect_maybe(((vader_struct_toolchain_ast_FnParam_t*) l5)->f_ty, l1);
        if (t1) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        t1 = toolchain_ast_inspect_maybe(((vader_struct_toolchain_ast_FnParam_t*) l5)->f_default_value, l1);
        if (t1) {
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
    size_t t0;
    void* t1 = NULL;
    bool t2;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l0;
    t0 = ((vader_array_t*) l2)->length;
    l3 = (int64_t) (size_t) t0;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        if (l5.tag == 594u) {
            t1 = l5.payload.obj;
            t2 = toolchain_ast_inspect(((vader_struct_toolchain_ast_StringLitInterp_t*) t1)->f_expr, l1);
            if (t2) {
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
    size_t t0;
    void* t1 = NULL;
    bool t2;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l0;
    t0 = ((vader_array_t*) l2)->length;
    l3 = (int64_t) (size_t) t0;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        l5 = ((vader_struct_toolchain_ast_StructPatternField_t*) t1)->f_value;
        if (l5.tag == 583u) {
            t1 = l5.payload.obj;
            t2 = toolchain_ast_inspect(((vader_struct_toolchain_ast_PatternLiteral_t*) t1)->f_value, l1);
            if (t2) {
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
    size_t t0;
    vader_box_t t1 = vader_box_null();
    bool t2;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l0;
    t0 = ((vader_array_t*) l2)->length;
    l3 = (int64_t) (size_t) t0;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t2 = toolchain_ast_inspect(t1, l1);
        if (t2) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        l4 = (l4 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static bool toolchain_ast_inspect_stmts(void* l0, void* l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    size_t t0;
    vader_box_t t1 = vader_box_null();
    bool t2;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l0;
    t0 = ((vader_array_t*) l2)->length;
    l3 = (int64_t) (size_t) t0;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t2 = toolchain_ast_inspect(t1, l1);
        if (t2) {
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
    size_t t1;
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
    t1 = ((vader_array_t*) l2)->length;
    l3 = (int64_t) (size_t) t1;
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
    size_t t0;
    bool t1;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l0;
    t0 = ((vader_array_t*) l2)->length;
    l3 = (int64_t) (size_t) t0;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        if ((l5.tag == 584u || l5.tag == 589u)) {
            t1 = toolchain_ast_inspect(VADER_UNION_FIELD(vader_box_t, vader_struct_toolchain_ast_PlaceTarget_t, f_place, l5.payload.obj), l1);
            if (t1) {
                { vader_gc_top = gc_frame.prev; return true; }
            }
        } else if (!(l5.tag == 612u)) {
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
    size_t t0;
    bool t1;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l0;
    t0 = ((vader_array_t*) l2)->length;
    l3 = (int64_t) (size_t) t0;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t1 = toolchain_ast_inspect_maybe(((vader_struct_toolchain_ast_TypeParam_t*) l5)->f_bound, l1);
        if (t1) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        t1 = toolchain_ast_inspect_maybe(((vader_struct_toolchain_ast_TypeParam_t*) l5)->f_default_v, l1);
        if (t1) {
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
        l1 = std_core_new_byte_buffer(INT64_C(20));
        l2 = INT64_C(0);
        l3 = ((vader_struct_toolchain_ast_IntLitExpr_t*) l0)->f_value;
        l2 = std_core_write_unsigned(l1, l2, l3);
        t1 = std_core_finish_buffer(l1, l2);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = std_core_new_byte_buffer(INT64_C(21));
    l2 = INT64_C(0);
    l2 = std_core_write_string_at(l1, l2, 314u);
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

vader_box_t toolchain_ast_string_literal_text(vader_box_t l0) {
    vader_box_t l1;
    void* t0;
    size_t t1;
    vader_string_t t2;
    vader_box_t t3;
    if (l0.tag == 593u) {
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
        if (!(l1.tag == 595u)) {
            return vader_box_obj(0u, NULL);
        }
        t0 = l1.payload.obj;
        t2 = ((vader_struct_toolchain_ast_StringLitText_t*) t0)->f_value;
        t3 = vader_box_string(285u, t2);
        return t3;
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t toolchain_ast_struct_item_value(vader_box_t l0) {
    void* t0;
    if (l0.tag == 599u) {
        t0 = l0.payload.obj;
        return ((vader_struct_toolchain_ast_StructLitField_t*) t0)->f_value;
    }
    if (!(l0.tag == 600u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    t0 = l0.payload.obj;
    return ((vader_struct_toolchain_ast_StructLitSpread_t*) t0)->f_expr;
}
