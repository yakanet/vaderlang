#include "bootstrap.split.h"

static void toolchain_ast$append_bitor_variants(vader_box_t l0, void* l1);
static vader_string_t toolchain_ast$c_header_of(void* l0);
static bool toolchain_ast$inspect_alias(void* l0, void* l1, void* l2);
static bool toolchain_ast$inspect_arms(void* l0, void* l1, void* l2);
static bool toolchain_ast$inspect_assign(void* l0, void* l1, void* l2);
static bool toolchain_ast$inspect_call(void* l0, void* l1, void* l2);
static bool toolchain_ast$inspect_const(void* l0, void* l1, void* l2);
static bool toolchain_ast$inspect_decorators(void* l0, void* l1, void* l2);
static bool toolchain_ast$inspect_defer(vader_box_t l0, void* l1, void* l2);
static bool toolchain_ast$inspect_enum(void* l0, void* l1, void* l2);
static bool toolchain_ast$inspect_exprs(void* l0, void* l1, void* l2);
static bool toolchain_ast$inspect_fn(void* l0, void* l1, void* l2);
static bool toolchain_ast$inspect_fns(void* l0, void* l1, void* l2);
static bool toolchain_ast$inspect_form(vader_box_t l0, void* l1, void* l2);
static bool toolchain_ast$inspect_if(void* l0, void* l1, void* l2);
static bool toolchain_ast$inspect_impl(void* l0, void* l1, void* l2);
static bool toolchain_ast$inspect_items(void* l0, void* l1, void* l2);
static bool toolchain_ast$inspect_lambda(void* l0, void* l1, void* l2);
static bool toolchain_ast$inspect_maybe(vader_box_t l0, void* l1, void* l2);
static bool toolchain_ast$inspect_params(void* l0, void* l1, void* l2);
static bool toolchain_ast$inspect_parts(void* l0, void* l1, void* l2);
static bool toolchain_ast$inspect_pattern_fields(void* l0, void* l1, void* l2);
static bool toolchain_ast$inspect_patterns(void* l0, void* l1, void* l2);
static bool toolchain_ast$inspect_stmts(void* l0, void* l1, void* l2);
static bool toolchain_ast$inspect_struct(void* l0, void* l1, void* l2);
static bool toolchain_ast$inspect_targets(void* l0, void* l1, void* l2);
static bool toolchain_ast$inspect_trait(void* l0, void* l1, void* l2);
static bool toolchain_ast$inspect_type_params(void* l0, void* l1, void* l2);
static bool toolchain_ast$is_arith_op(uint8_t l0);
static vader_box_t toolchain_ast$own_const_type(void* l0);
static vader_string_t toolchain_ast$sole_string_argument(void* l0);
static vader_box_t toolchain_ast$struct_item_value(vader_box_t l0);

static void toolchain_ast$append_bitor_variants(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l0, &l3 };
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 746u) {
        t0 = l0.payload.obj;
        if (((vader_struct_toolchain_ast$BinaryExpr_t*) t0)->f_op == INT32_C(8)) {
            t0 = l0.payload.obj;
            toolchain_ast$append_bitor_variants(((vader_struct_toolchain_ast$BinaryExpr_t*) t0)->f_left, l1);
            t0 = l0.payload.obj;
            toolchain_ast$append_bitor_variants(((vader_struct_toolchain_ast$BinaryExpr_t*) t0)->f_right, l1);
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

void* toolchain_ast$assign_places(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null(), l6 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l5, &l6 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(349u, 0u, 13u, 1716u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct_toolchain_ast$DestructureAssignStmt_t*) l0)->f_targets;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l5 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        if ((l5.tag == 804u || l5.tag == 809u)) {
            l6 = VADER_UNION_FIELD(vader_box_t, vader_struct_toolchain_ast$PlaceTarget_t, f_place, l5.payload.obj);
            vader_array_push_ref((vader_array_t*) l1, l6.payload.obj);
        } else if (!(l5.tag == 832u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l4 = (l4 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t toolchain_ast$binary_op_symbol(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 356u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 386u;
    } else if (l0 == INT32_C(2)) {
        l1 = 352u;
    } else if (l0 == INT32_C(3)) {
        l1 = 441u;
    } else if (l0 == INT32_C(4)) {
        l1 = 285u;
    } else if (l0 == INT32_C(5)) {
        l1 = 506u;
    } else if (l0 == INT32_C(6)) {
        l1 = 528u;
    } else if (l0 == INT32_C(7)) {
        l1 = 287u;
    } else if (l0 == INT32_C(8)) {
        l1 = 3063u;
    } else if (l0 == INT32_C(9)) {
        l1 = 975u;
    } else if (l0 == INT32_C(10)) {
        l1 = 288u;
    } else if (l0 == INT32_C(11)) {
        l1 = 3064u;
    } else if (l0 == INT32_C(12)) {
        l1 = 523u;
    } else if (l0 == INT32_C(13)) {
        l1 = 247u;
    } else if (l0 == INT32_C(14)) {
        l1 = 505u;
    } else if (l0 == INT32_C(15)) {
        l1 = 507u;
    } else if (l0 == INT32_C(16)) {
        l1 = 526u;
    } else if (l0 == INT32_C(17)) {
        l1 = 527u;
    } else if (l0 == INT32_C(18)) {
        l1 = 2207u;
    } else if (l0 == INT32_C(19)) {
        l1 = 2147u;
    } else if (l0 == INT32_C(20)) {
        l1 = 249u;
    } else if (l0 == INT32_C(21)) {
        l1 = 524u;
    } else if (l0 == INT32_C(22)) {
        l1 = 248u;
    } else if (l0 == INT32_C(23)) {
        l1 = 357u;
    } else if (l0 == INT32_C(24)) {
        l1 = 387u;
    } else {
        if (!(l0 == INT32_C(25))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 353u;
    }
    return l1;
}

void* toolchain_ast$body_source(void* l0) {
    vader_box_t l1;
    void* t0;
    l1 = ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_inherits;
    if (l1.tag == 0u) {
        return l0;
    }
    t0 = l1.payload.obj;
    return t0;
}

static vader_string_t toolchain_ast$c_header_of(void* l0) {
    vader_box_t l1;
    void* t0;
    vader_string_t t1;
    l1 = toolchain_ast$find_decorator(((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_decorators, 1703u);
    if (l1.tag == 0u) {
        return 0u;
    }
    t0 = l1.payload.obj;
    t1 = toolchain_ast$sole_string_argument(t0);
    return t1;
}

vader_string_t toolchain_ast$c_struct_spelling(void* l0, vader_string_t l1) {
    void* l2;
    vader_box_t l3;
    int64_t t0;
    vader_string_t t1;
    l3 = toolchain_ast$find_decorator(l0, 1706u);
    if (l3.tag == 0u) {
        return 0u;
    }
    l2 = l3.payload.obj;
    t0 = ((vader_array_t*) ((vader_struct_toolchain_ast$Decorator_t*) l2)->f_args)->length;
    if (!(t0 == INT64_C(0))) {
        t1 = toolchain_ast$sole_string_argument(l2);
        return t1;
    }
    return l1;
}

vader_string_t toolchain_ast$c_type_of(void* l0) {
    vader_box_t l1;
    void* t0;
    vader_string_t t1;
    l1 = toolchain_ast$find_decorator(l0, 1707u);
    if (l1.tag == 0u) {
        return 0u;
    }
    t0 = l1.payload.obj;
    t1 = toolchain_ast$sole_string_argument(t0);
    return t1;
}

vader_box_t toolchain_ast$coalesce_fallback_expr(vader_box_t l0) {
    vader_box_t l1;
    void* t0;
    if (l0.tag == 810u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast$ReturnStmt_t*) t0)->f_value;
        return l1;
    }
    if ((l0.tag == 749u || l0.tag == 755u)) {
        l1 = vader_box_obj(0u, NULL);
    } else {
        if (!((l0.tag == 742u || l0.tag == 745u || l0.tag == 746u || l0.tag == 747u || l0.tag == 748u || l0.tag == 751u || l0.tag == 752u || l0.tag == 753u || l0.tag == 766u || l0.tag == 771u || l0.tag == 772u || l0.tag == 775u || l0.tag == 777u || l0.tag == 778u || l0.tag == 781u || l0.tag == 786u || l0.tag == 788u || l0.tag == 789u || l0.tag == 791u || l0.tag == 795u || l0.tag == 799u || l0.tag == 800u || l0.tag == 806u || l0.tag == 811u || l0.tag == 813u || l0.tag == 818u || l0.tag == 827u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = l0;
    }
    return l1;
}

void* toolchain_ast$collect_bitor_variants(vader_box_t l0) {
    void* l1 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(349u, 0u, 13u, 1716u);
    l1 = (void*) _a0_arr;
    toolchain_ast$append_bitor_variants(l0, l1);
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t toolchain_ast$compound_assign_op(void* l0) {
    vader_box_t l1;
    void* l2;
    void* l3;
    void* t0;
    bool t1;
    l1 = ((vader_struct_toolchain_ast$AssignStmt_t*) l0)->f_value;
    if (l1.tag == 746u) {
        t0 = l1.payload.obj;
        l2 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, ((vader_struct_toolchain_ast$BinaryExpr_t*) t0)->f_left.payload.obj);
        l3 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, ((vader_struct_toolchain_ast$AssignStmt_t*) l0)->f_target.payload.obj);
        t1 = toolchain_span$Span$std_core$Equals$equals(l2, l3);
        if (t1) {
            t0 = l1.payload.obj;
            t1 = toolchain_ast$is_arith_op(((vader_struct_toolchain_ast$BinaryExpr_t*) t0)->f_op);
            if (t1) {
                t0 = l1.payload.obj;
                return vader_box_i32(452u, (int32_t)(uint32_t) ((vader_struct_toolchain_ast$BinaryExpr_t*) t0)->f_op);
            }
        }
        return vader_box_obj(0u, NULL);
    }
    return vader_box_obj(0u, NULL);
}

void* toolchain_ast$decl_decorators(vader_box_t l0) {
    void* l1;
    void* t0;
    if (l0.tag == 783u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast$ImportDecl_t*) t0)->f_decorators;
        return l1;
    }
    if (l0.tag == 773u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_decorators;
    } else if (l0.tag == 816u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast$StructDecl_t*) t0)->f_decorators;
    } else if (l0.tag == 767u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast$EnumDecl_t*) t0)->f_decorators;
    } else if (l0.tag == 823u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast$TraitDecl_t*) t0)->f_decorators;
    } else if (l0.tag == 782u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast$ImplDecl_t*) t0)->f_decorators;
    } else if (l0.tag == 825u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast$TypeAliasDecl_t*) t0)->f_decorators;
    } else if (l0.tag == 754u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast$ConstDecl_t*) t0)->f_decorators;
    } else {
        if (!(l0.tag == 743u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast$AssertDecl_t*) t0)->f_decorators;
    }
    return l1;
}

vader_box_t toolchain_ast$decl_name_span(vader_box_t l0) {
    vader_box_t l1;
    void* t0;
    void* t1;
    if (l0.tag == 773u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_name_span;
        l1 = vader_ref_box(t1);
        return l1;
    }
    if (l0.tag == 816u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_toolchain_ast$StructDecl_t*) t0)->f_name_span;
        l1 = vader_ref_box(t1);
    } else if (l0.tag == 767u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_toolchain_ast$EnumDecl_t*) t0)->f_name_span;
        l1 = vader_ref_box(t1);
    } else if (l0.tag == 823u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_toolchain_ast$TraitDecl_t*) t0)->f_name_span;
        l1 = vader_ref_box(t1);
    } else if (l0.tag == 825u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_toolchain_ast$TypeAliasDecl_t*) t0)->f_name_span;
        l1 = vader_ref_box(t1);
    } else if (l0.tag == 754u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_toolchain_ast$ConstDecl_t*) t0)->f_name_span;
        l1 = vader_ref_box(t1);
    } else {
        if (!((l0.tag == 743u || l0.tag == 782u || l0.tag == 783u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = vader_box_obj(0u, NULL);
    }
    return l1;
}

bool toolchain_ast$decorators_have(void* l0, vader_string_t l1) {
    vader_box_t t0;
    t0 = toolchain_ast$find_decorator(l0, l1);
    return !(t0.tag == 0u);
}

vader_string_t toolchain_ast$extern_header(void* l0, vader_box_t l1) {
    vader_string_t l2;
    void* t0;
    vader_string_t t1;
    l2 = toolchain_ast$c_header_of(l0);
    if (l2 != 0u) {
        return l2;
    }
    if (!(l1.tag == 0u)) {
        t0 = l1.payload.obj;
        t1 = ((vader_struct_std_ffi$CLibrary_t*) t0)->f_header;
        return t1;
    }
    return l2;
}

vader_string_t toolchain_ast$extern_symbol_of(void* l0) {
    void* l1;
    void* l3;
    vader_box_t l2;
    int64_t l4;
    vader_string_t t0;
    int64_t t1;
    vader_box_t t2;
    l2 = toolchain_ast$find_decorator(((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_decorators, 1951u);
    if (l2.tag == 0u) {
        t0 = ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_name;
        return t0;
    }
    l1 = l2.payload.obj;
    t1 = ((vader_array_t*) ((vader_struct_toolchain_ast$Decorator_t*) l1)->f_args)->length;
    if (t1 == INT64_C(0)) {
        t0 = ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_name;
        return t0;
    }
    l3 = ((vader_struct_toolchain_ast$Decorator_t*) l1)->f_args;
    t1 = ((vader_array_t*) ((vader_struct_toolchain_ast$Decorator_t*) l1)->f_args)->length;
    l4 = vader_chk_sub(i64, t1, INT64_C(1));
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    t2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
    l2 = toolchain_ast$string_literal_text(t2);
    if (l2.tag == 0u) {
        t0 = ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_name;
        return t0;
    }
    t0 = l2.payload.s;
    return t0;
}

vader_box_t toolchain_ast$find_decorator(void* l0, vader_string_t l1) {
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
        t0 = ((vader_struct_toolchain_ast$Decorator_t*) l5)->f_name;
        if (t0 == l1) {
            return vader_ref_box(l5);
        }
        l4 = (l4 + INT64_C(1));
    }
    return vader_box_obj(0u, NULL);
}

void toolchain_ast$ignore_node(vader_box_t l0) {
    return;
}

bool toolchain_ast$inspect(vader_box_t l0, void* l1, void* l2) {
    uint8_t l3;
    bool l4;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    bool t2;
    vader_box_t* gc_roots[2] = { &l0, &t0 };
    void** gc_raw_roots[3] = { &l1, &l2, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_fn_t* _a0_fnobj = (vader_fn_t*) l1;
    t0 = ((vader_fn_erased_sig_1_t) _a0_fnobj->code)(_a0_fnobj->env, l0);
    l3 = ((uint8_t) t0.payload.i);
    if (l3 == INT32_C(2)) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    if (l3 == INT32_C(0)) {
        if ((l0.tag == 748u || l0.tag == 753u || l0.tag == 772u || l0.tag == 788u || l0.tag == 800u)) {
            l4 = false;
        } else if (l0.tag == 813u) {
            t1 = l0.payload.obj;
            l4 = toolchain_ast$inspect_parts(((vader_struct_toolchain_ast$StringLitExpr_t*) t1)->f_parts, l1, l2);
        } else if ((l0.tag == 766u || l0.tag == 778u)) {
            l4 = false;
        } else if (l0.tag == 751u) {
            t1 = l0.payload.obj;
            l4 = toolchain_ast$inspect_call(t1, l1, l2);
        } else if (l0.tag == 771u) {
            t1 = l0.payload.obj;
            l4 = toolchain_ast$inspect(((vader_struct_toolchain_ast$FieldExpr_t*) t1)->f_target, l1, l2);
        } else if (l0.tag == 786u) {
            t1 = l0.payload.obj;
            t2 = toolchain_ast$inspect(((vader_struct_toolchain_ast$IndexExpr_t*) t1)->f_target, l1, l2);
            if (t2) {
                l4 = true;
            } else {
                t1 = l0.payload.obj;
                l4 = toolchain_ast$inspect(((vader_struct_toolchain_ast$IndexExpr_t*) t1)->f_index, l1, l2);
            }
        } else if (l0.tag == 827u) {
            t1 = l0.payload.obj;
            l4 = toolchain_ast$inspect(((vader_struct_toolchain_ast$UnaryExpr_t*) t1)->f_operand, l1, l2);
        } else if (l0.tag == 746u) {
            t1 = l0.payload.obj;
            t2 = toolchain_ast$inspect(((vader_struct_toolchain_ast$BinaryExpr_t*) t1)->f_left, l1, l2);
            if (t2) {
                l4 = true;
            } else {
                t1 = l0.payload.obj;
                l4 = toolchain_ast$inspect(((vader_struct_toolchain_ast$BinaryExpr_t*) t1)->f_right, l1, l2);
            }
        } else if (l0.tag == 799u) {
            t1 = l0.payload.obj;
            t2 = toolchain_ast$inspect(((vader_struct_toolchain_ast$NullCoalesceExpr_t*) t1)->f_left, l1, l2);
            if (t2) {
                l4 = true;
            } else {
                t1 = l0.payload.obj;
                l4 = toolchain_ast$inspect(((vader_struct_toolchain_ast$NullCoalesceExpr_t*) t1)->f_fallback, l1, l2);
            }
        } else if (l0.tag == 781u) {
            t1 = l0.payload.obj;
            l4 = toolchain_ast$inspect_if(t1, l1, l2);
        } else if (l0.tag == 795u) {
            t1 = l0.payload.obj;
            t2 = toolchain_ast$inspect(((vader_struct_toolchain_ast$MatchExpr_t*) t1)->f_scrutinee, l1, l2);
            if (t2) {
                l4 = true;
            } else {
                t1 = l0.payload.obj;
                l4 = toolchain_ast$inspect_arms(((vader_struct_toolchain_ast$MatchExpr_t*) t1)->f_arms, l1, l2);
            }
        } else if (l0.tag == 747u) {
            t1 = l0.payload.obj;
            t2 = toolchain_ast$inspect_stmts(((vader_struct_toolchain_ast$BlockExpr_t*) t1)->f_stmts, l1, l2);
            if (t2) {
                l4 = true;
            } else {
                t1 = l0.payload.obj;
                l4 = toolchain_ast$inspect_maybe(((vader_struct_toolchain_ast$BlockExpr_t*) t1)->f_trailing, l1, l2);
            }
        } else if (l0.tag == 791u) {
            t1 = l0.payload.obj;
            l4 = toolchain_ast$inspect_lambda(t1, l1, l2);
        } else if (l0.tag == 818u) {
            t1 = l0.payload.obj;
            t2 = toolchain_ast$inspect(((vader_struct_toolchain_ast$StructLitExpr_t*) t1)->f_type_name, l1, l2);
            if (t2) {
                l4 = true;
            } else {
                t1 = l0.payload.obj;
                l4 = toolchain_ast$inspect_items(((vader_struct_toolchain_ast$StructLitExpr_t*) t1)->f_items, l1, l2);
            }
        } else if (l0.tag == 811u) {
            t1 = l0.payload.obj;
            l4 = toolchain_ast$inspect_exprs(((vader_struct_toolchain_ast$SeqLitExpr_t*) t1)->f_elements, l1, l2);
        } else if (l0.tag == 806u) {
            t1 = l0.payload.obj;
            t2 = toolchain_ast$inspect(((vader_struct_toolchain_ast$RangeExpr_t*) t1)->f_lower, l1, l2);
            if (t2) {
                l4 = true;
            } else {
                t1 = l0.payload.obj;
                l4 = toolchain_ast$inspect(((vader_struct_toolchain_ast$RangeExpr_t*) t1)->f_upper, l1, l2);
            }
        } else if (l0.tag == 752u) {
            t1 = l0.payload.obj;
            t2 = toolchain_ast$inspect(((vader_struct_toolchain_ast$CastExpr_t*) t1)->f_value, l1, l2);
            if (t2) {
                l4 = true;
            } else {
                t1 = l0.payload.obj;
                l4 = toolchain_ast$inspect(((vader_struct_toolchain_ast$CastExpr_t*) t1)->f_target, l1, l2);
            }
        } else if (l0.tag == 777u) {
            t1 = l0.payload.obj;
            t2 = toolchain_ast$inspect(((vader_struct_toolchain_ast$GenericInstExpr_t*) t1)->f_callee, l1, l2);
            if (t2) {
                l4 = true;
            } else {
                t1 = l0.payload.obj;
                l4 = toolchain_ast$inspect_exprs(((vader_struct_toolchain_ast$GenericInstExpr_t*) t1)->f_type_args, l1, l2);
            }
        } else if (l0.tag == 789u) {
            t1 = l0.payload.obj;
            l4 = toolchain_ast$inspect_exprs(((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) t1)->f_args, l1, l2);
        } else if (l0.tag == 775u) {
            t1 = l0.payload.obj;
            t2 = toolchain_ast$inspect_exprs(((vader_struct_toolchain_ast$FnTypeExpr_t*) t1)->f_params, l1, l2);
            if (t2) {
                l4 = true;
            } else {
                t1 = l0.payload.obj;
                l4 = toolchain_ast$inspect_maybe(((vader_struct_toolchain_ast$FnTypeExpr_t*) t1)->f_return_type, l1, l2);
            }
        } else if (l0.tag == 742u) {
            t1 = l0.payload.obj;
            l4 = toolchain_ast$inspect(((vader_struct_toolchain_ast$ArrayTypeExpr_t*) t1)->f_element, l1, l2);
        } else if (l0.tag == 745u) {
            t1 = l0.payload.obj;
            l4 = toolchain_ast$inspect(((vader_struct_toolchain_ast$AwaitExpr_t*) t1)->f_inner, l1, l2);
        } else if (l0.tag == 792u) {
            t1 = l0.payload.obj;
            t2 = toolchain_ast$inspect_maybe(((vader_struct_toolchain_ast$LetStmt_t*) t1)->f_ty, l1, l2);
            if (t2) {
                l4 = true;
            } else {
                t1 = l0.payload.obj;
                l4 = toolchain_ast$inspect(((vader_struct_toolchain_ast$LetStmt_t*) t1)->f_value, l1, l2);
            }
        } else if (l0.tag == 744u) {
            t1 = l0.payload.obj;
            l4 = toolchain_ast$inspect_assign(t1, l1, l2);
        } else if (l0.tag == 760u) {
            t1 = l0.payload.obj;
            t2 = toolchain_ast$inspect_targets(((vader_struct_toolchain_ast$DestructureAssignStmt_t*) t1)->f_targets, l1, l2);
            if (t2) {
                l4 = true;
            } else {
                t1 = l0.payload.obj;
                l4 = toolchain_ast$inspect(((vader_struct_toolchain_ast$DestructureAssignStmt_t*) t1)->f_value, l1, l2);
            }
        } else if (l0.tag == 770u) {
            t1 = l0.payload.obj;
            l4 = toolchain_ast$inspect(((vader_struct_toolchain_ast$ExprStmt_t*) t1)->f_expr, l1, l2);
        } else if (l0.tag == 810u) {
            t1 = l0.payload.obj;
            l4 = toolchain_ast$inspect_maybe(((vader_struct_toolchain_ast$ReturnStmt_t*) t1)->f_value, l1, l2);
        } else if (l0.tag == 833u) {
            t1 = l0.payload.obj;
            l4 = toolchain_ast$inspect(((vader_struct_toolchain_ast$YieldStmt_t*) t1)->f_value, l1, l2);
        } else if (l0.tag == 776u) {
            t1 = l0.payload.obj;
            t2 = toolchain_ast$inspect_form(((vader_struct_toolchain_ast$ForStmt_t*) t1)->f_form, l1, l2);
            if (t2) {
                l4 = true;
            } else {
                t1 = l0.payload.obj;
                l4 = toolchain_ast$inspect(vader_ref_box(((vader_struct_toolchain_ast$ForStmt_t*) t1)->f_body), l1, l2);
            }
        } else if ((l0.tag == 749u || l0.tag == 755u)) {
            l4 = false;
        } else if (l0.tag == 758u) {
            t1 = l0.payload.obj;
            l4 = toolchain_ast$inspect_defer(((vader_struct_toolchain_ast$DeferStmt_t*) t1)->f_body, l1, l2);
        } else if (l0.tag == 790u) {
            t1 = l0.payload.obj;
            t2 = toolchain_ast$inspect(((vader_struct_toolchain_ast$IsPattern_t*) t1)->f_ty, l1, l2);
            if (t2) {
                l4 = true;
            } else {
                t1 = l0.payload.obj;
                l4 = toolchain_ast$inspect_maybe(((vader_struct_toolchain_ast$IsPattern_t*) t1)->f_inner, l1, l2);
            }
        } else if (l0.tag == 821u) {
            t1 = l0.payload.obj;
            l4 = toolchain_ast$inspect_pattern_fields(((vader_struct_toolchain_ast$StructPattern_t*) t1)->f_fields, l1, l2);
        } else if ((l0.tag == 769u || l0.tag == 831u)) {
            l4 = false;
        } else if (l0.tag == 793u) {
            t1 = l0.payload.obj;
            l4 = toolchain_ast$inspect(((vader_struct_toolchain_ast$LiteralPattern_t*) t1)->f_value, l1, l2);
        } else if (l0.tag == 807u) {
            t1 = l0.payload.obj;
            t2 = toolchain_ast$inspect(((vader_struct_toolchain_ast$RangePattern_t*) t1)->f_lower, l1, l2);
            if (t2) {
                l4 = true;
            } else {
                t1 = l0.payload.obj;
                l4 = toolchain_ast$inspect(((vader_struct_toolchain_ast$RangePattern_t*) t1)->f_upper, l1, l2);
            }
        } else if (l0.tag == 801u) {
            t1 = l0.payload.obj;
            l4 = toolchain_ast$inspect_patterns(((vader_struct_toolchain_ast$OrPattern_t*) t1)->f_patterns, l1, l2);
        } else if (l0.tag == 783u) {
            t1 = l0.payload.obj;
            l4 = toolchain_ast$inspect_decorators(((vader_struct_toolchain_ast$ImportDecl_t*) t1)->f_decorators, l1, l2);
        } else if (l0.tag == 773u) {
            t1 = l0.payload.obj;
            l4 = toolchain_ast$inspect_fn(t1, l1, l2);
        } else if (l0.tag == 816u) {
            t1 = l0.payload.obj;
            l4 = toolchain_ast$inspect_struct(t1, l1, l2);
        } else if (l0.tag == 767u) {
            t1 = l0.payload.obj;
            l4 = toolchain_ast$inspect_enum(t1, l1, l2);
        } else if (l0.tag == 823u) {
            t1 = l0.payload.obj;
            l4 = toolchain_ast$inspect_trait(t1, l1, l2);
        } else if (l0.tag == 782u) {
            t1 = l0.payload.obj;
            l4 = toolchain_ast$inspect_impl(t1, l1, l2);
        } else if (l0.tag == 825u) {
            t1 = l0.payload.obj;
            l4 = toolchain_ast$inspect_alias(t1, l1, l2);
        } else if (l0.tag == 754u) {
            t1 = l0.payload.obj;
            l4 = toolchain_ast$inspect_const(t1, l1, l2);
        } else {
            if (!(l0.tag == 743u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            t1 = l0.payload.obj;
            t2 = toolchain_ast$inspect_decorators(((vader_struct_toolchain_ast$AssertDecl_t*) t1)->f_decorators, l1, l2);
            if (t2) {
                l4 = true;
            } else {
                t1 = l0.payload.obj;
                l4 = toolchain_ast$inspect(((vader_struct_toolchain_ast$AssertDecl_t*) t1)->f_condition, l1, l2);
            }
        }
        if (l4) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        vader_fn_t* _a1_fnobj = (vader_fn_t*) l2;
        ((vader_fn_erased_sig_1_t) _a1_fnobj->code)(_a1_fnobj->env, l0);
        { vader_gc_top = gc_frame.prev; return false; }
    }
    vader_fn_t* _a2_fnobj = (vader_fn_t*) l2;
    ((vader_fn_erased_sig_1_t) _a2_fnobj->code)(_a2_fnobj->env, l0);
    { vader_gc_top = gc_frame.prev; return false; }
}

static bool toolchain_ast$inspect_alias(void* l0, void* l1, void* l2) {
    bool l3;
    bool t0;
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = toolchain_ast$inspect_decorators(((vader_struct_toolchain_ast$TypeAliasDecl_t*) l0)->f_decorators, l1, l2);
    if (t0) {
        l3 = true;
    } else {
        l3 = toolchain_ast$inspect_type_params(((vader_struct_toolchain_ast$TypeAliasDecl_t*) l0)->f_type_params, l1, l2);
    }
    if (l3) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    t0 = toolchain_ast$inspect(((vader_struct_toolchain_ast$TypeAliasDecl_t*) l0)->f_aliased, l1, l2);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool toolchain_ast$inspect_arms(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l6 = NULL;
    int64_t l4, l5;
    bool t0;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = l0;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        l6 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        t0 = toolchain_ast$inspect(((vader_struct_toolchain_ast$MatchArm_t*) l6)->f_pattern, l1, l2);
        if (t0) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        t0 = toolchain_ast$inspect_maybe(((vader_struct_toolchain_ast$MatchArm_t*) l6)->f_guard, l1, l2);
        if (t0) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        t0 = toolchain_ast$inspect(((vader_struct_toolchain_ast$MatchArm_t*) l6)->f_body, l1, l2);
        if (t0) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        l5 = (l5 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static bool toolchain_ast$inspect_assign(void* l0, void* l1, void* l2) {
    vader_box_t t0 = vader_box_null();
    bool t1;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = toolchain_ast$compound_assign_op(l0);
    if (!(t0.tag == 0u)) {
        t1 = toolchain_ast$inspect(((vader_struct_toolchain_ast$AssignStmt_t*) l0)->f_value, l1, l2);
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = toolchain_ast$inspect(((vader_struct_toolchain_ast$AssignStmt_t*) l0)->f_target, l1, l2);
    if (t1) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    t1 = toolchain_ast$inspect(((vader_struct_toolchain_ast$AssignStmt_t*) l0)->f_value, l1, l2);
    { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool toolchain_ast$inspect_call(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    int64_t l4, l5;
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = toolchain_ast$inspect(((vader_struct_toolchain_ast$CallExpr_t*) l0)->f_callee, l1, l2);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    t0 = toolchain_ast$inspect_exprs(((vader_struct_toolchain_ast$CallExpr_t*) l0)->f_type_args, l1, l2);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    l3 = ((vader_struct_toolchain_ast$CallExpr_t*) l0)->f_args;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        t0 = toolchain_ast$inspect(((vader_struct_toolchain_ast$CallArg_t*) t1)->f_value, l1, l2);
        if (t0) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        l5 = (l5 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static bool toolchain_ast$inspect_const(void* l0, void* l1, void* l2) {
    bool l3;
    bool t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = toolchain_ast$inspect_decorators(((vader_struct_toolchain_ast$ConstDecl_t*) l0)->f_decorators, l1, l2);
    if (t0) {
        l3 = true;
    } else {
        t1 = toolchain_ast$own_const_type(l0);
        l3 = toolchain_ast$inspect_maybe(t1, l1, l2);
    }
    if (l3) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    t0 = toolchain_ast$inspect(((vader_struct_toolchain_ast$ConstDecl_t*) l0)->f_value, l1, l2);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool toolchain_ast$inspect_decorators(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    int64_t l4, l5;
    void* t0 = NULL;
    bool t1;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = l0;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        t1 = toolchain_ast$inspect_exprs(((vader_struct_toolchain_ast$Decorator_t*) t0)->f_args, l1, l2);
        if (t1) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        l5 = (l5 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static bool toolchain_ast$inspect_defer(vader_box_t l0, void* l1, void* l2) {
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 759u) {
        t0 = l0.payload.obj;
        t1 = toolchain_ast$inspect(((vader_struct_toolchain_ast$DeferStmtBody_t*) t0)->f_stmt, l1, l2);
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0.tag == 757u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    t0 = l0.payload.obj;
    t1 = toolchain_ast$inspect(vader_ref_box(((vader_struct_toolchain_ast$DeferBlockBody_t*) t0)->f_block), l1, l2);
    { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool toolchain_ast$inspect_enum(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    int64_t l4, l5;
    vader_box_t l6 = vader_box_null();
    bool t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l6 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = toolchain_ast$inspect_decorators(((vader_struct_toolchain_ast$EnumDecl_t*) l0)->f_decorators, l1, l2);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    t0 = toolchain_ast$inspect_exprs(((vader_struct_toolchain_ast$EnumDecl_t*) l0)->f_header, l1, l2);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    l3 = ((vader_struct_toolchain_ast$EnumDecl_t*) l0)->f_variants;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        l6 = ((vader_struct_toolchain_ast$EnumVariant_t*) t1)->f_data;
        if (l6.tag == 0u) {
            l5 = (l5 + INT64_C(1));
            continue;
        }
        t1 = l6.payload.obj;
        t0 = toolchain_ast$inspect_items(t1, l1, l2);
        if (t0) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        l5 = (l5 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static bool toolchain_ast$inspect_exprs(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    int64_t l4, l5;
    vader_box_t t0 = vader_box_null();
    bool t1;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = l0;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        t1 = toolchain_ast$inspect(t0, l1, l2);
        if (t1) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        l5 = (l5 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static bool toolchain_ast$inspect_fn(void* l0, void* l1, void* l2) {
    bool l3;
    bool t0;
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = toolchain_ast$inspect_decorators(((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_decorators, l1, l2);
    if (t0) {
        l3 = true;
    } else {
        l3 = toolchain_ast$inspect_type_params(((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_type_params, l1, l2);
    }
    if (l3) {
        l3 = true;
    } else {
        l3 = toolchain_ast$inspect_params(((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_params, l1, l2);
    }
    if (l3) {
        l3 = true;
    } else {
        l3 = toolchain_ast$inspect_maybe(((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_return_type, l1, l2);
    }
    if (l3) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    t0 = toolchain_ast$inspect_maybe(((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_body, l1, l2);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool toolchain_ast$inspect_fns(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    int64_t l4, l5;
    void* t0 = NULL;
    bool t1;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = l0;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        t1 = toolchain_ast$inspect(vader_ref_box(t0), l1, l2);
        if (t1) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        l5 = (l5 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static bool toolchain_ast$inspect_form(vader_box_t l0, void* l1, void* l2) {
    bool l3;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 785u) {
        t0 = l0.payload.obj;
        l3 = toolchain_ast$inspect(((vader_struct_toolchain_ast$InFor_t*) t0)->f_iter, l1, l2);
        { bool __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 828u) {
        t0 = l0.payload.obj;
        l3 = toolchain_ast$inspect(((vader_struct_toolchain_ast$WhileFor_t*) t0)->f_cond, l1, l2);
    } else {
        if (!(l0.tag == 787u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l3 = false;
    }
    { bool __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool toolchain_ast$inspect_if(void* l0, void* l1, void* l2) {
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null();
    bool l5;
    bool t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l3, &l4 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = toolchain_ast$inspect(((vader_struct_toolchain_ast$IfExpr_t*) l0)->f_cond, l1, l2);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    t0 = toolchain_ast$inspect(vader_ref_box(((vader_struct_toolchain_ast$IfExpr_t*) l0)->f_then_block), l1, l2);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    l3 = ((vader_struct_toolchain_ast$IfExpr_t*) l0)->f_else_branch;
    l4 = l3;
    if (l3.tag == 0u) {
        l5 = false;
        { bool __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l3.tag == 780u) {
        t1 = l4.payload.obj;
        l5 = toolchain_ast$inspect(vader_ref_box(((vader_struct_toolchain_ast$IfElseIf_t*) t1)->f_branch), l1, l2);
    } else {
        if (!(l3.tag == 779u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t1 = l4.payload.obj;
        l5 = toolchain_ast$inspect(vader_ref_box(((vader_struct_toolchain_ast$IfElseBlock_t*) t1)->f_block), l1, l2);
    }
    { bool __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool toolchain_ast$inspect_impl(void* l0, void* l1, void* l2) {
    bool l3;
    bool t0;
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = toolchain_ast$inspect_decorators(((vader_struct_toolchain_ast$ImplDecl_t*) l0)->f_decorators, l1, l2);
    if (t0) {
        l3 = true;
    } else {
        l3 = toolchain_ast$inspect_type_params(((vader_struct_toolchain_ast$ImplDecl_t*) l0)->f_type_params, l1, l2);
    }
    if (l3) {
        l3 = true;
    } else {
        l3 = toolchain_ast$inspect(((vader_struct_toolchain_ast$ImplDecl_t*) l0)->f_for_type, l1, l2);
    }
    if (l3) {
        l3 = true;
    } else {
        l3 = toolchain_ast$inspect_exprs(((vader_struct_toolchain_ast$ImplDecl_t*) l0)->f_trait_args, l1, l2);
    }
    if (l3) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    t0 = toolchain_ast$inspect_fns(((vader_struct_toolchain_ast$ImplDecl_t*) l0)->f_members, l1, l2);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool toolchain_ast$inspect_items(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    int64_t l4, l5;
    vader_box_t t0 = vader_box_null(), t1 = vader_box_null();
    bool t2;
    vader_box_t* gc_roots[2] = { &t0, &t1 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = l0;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        t1 = toolchain_ast$struct_item_value(t0);
        t2 = toolchain_ast$inspect(t1, l1, l2);
        if (t2) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        l5 = (l5 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static bool toolchain_ast$inspect_lambda(void* l0, void* l1, void* l2) {
    bool l3;
    bool t0;
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = toolchain_ast$inspect_params(((vader_struct_toolchain_ast$LambdaExpr_t*) l0)->f_params, l1, l2);
    if (t0) {
        l3 = true;
    } else {
        l3 = toolchain_ast$inspect_maybe(((vader_struct_toolchain_ast$LambdaExpr_t*) l0)->f_return_type, l1, l2);
    }
    if (l3) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    t0 = toolchain_ast$inspect(vader_ref_box(((vader_struct_toolchain_ast$LambdaExpr_t*) l0)->f_body), l1, l2);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool toolchain_ast$inspect_maybe(vader_box_t l0, void* l1, void* l2) {
    vader_box_t l3 = vader_box_null();
    bool t0;
    vader_box_t* gc_roots[2] = { &l0, &l3 };
    void** gc_raw_roots[2] = { &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = l0;
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    t0 = toolchain_ast$inspect(l3, l1, l2);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool toolchain_ast$inspect_params(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l6 = NULL;
    int64_t l4, l5;
    bool t0;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = l0;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        l6 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        t0 = toolchain_ast$inspect_decorators(((vader_struct_toolchain_ast$FnParam_t*) l6)->f_decorators, l1, l2);
        if (t0) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        t0 = toolchain_ast$inspect_maybe(((vader_struct_toolchain_ast$FnParam_t*) l6)->f_ty, l1, l2);
        if (t0) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        t0 = toolchain_ast$inspect_maybe(((vader_struct_toolchain_ast$FnParam_t*) l6)->f_default_value, l1, l2);
        if (t0) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        l5 = (l5 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static bool toolchain_ast$inspect_parts(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    int64_t l4, l5;
    vader_box_t l6 = vader_box_null();
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[1] = { &l6 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = l0;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        l6 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        if (l6.tag == 814u) {
            t0 = l6.payload.obj;
            t1 = toolchain_ast$inspect(((vader_struct_toolchain_ast$StringLitInterp_t*) t0)->f_expr, l1, l2);
            if (t1) {
                { vader_gc_top = gc_frame.prev; return true; }
            }
        }
        l5 = (l5 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static bool toolchain_ast$inspect_pattern_fields(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    int64_t l4, l5;
    vader_box_t l6 = vader_box_null();
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[1] = { &l6 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = l0;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        l6 = ((vader_struct_toolchain_ast$StructPatternField_t*) t0)->f_value;
        if (l6.tag == 803u) {
            t0 = l6.payload.obj;
            t1 = toolchain_ast$inspect(((vader_struct_toolchain_ast$PatternLiteral_t*) t0)->f_value, l1, l2);
            if (t1) {
                { vader_gc_top = gc_frame.prev; return true; }
            }
        }
        l5 = (l5 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static bool toolchain_ast$inspect_patterns(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    int64_t l4, l5;
    vader_box_t t0 = vader_box_null();
    bool t1;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = l0;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        t1 = toolchain_ast$inspect(t0, l1, l2);
        if (t1) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        l5 = (l5 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static bool toolchain_ast$inspect_stmts(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    int64_t l4, l5;
    vader_box_t t0 = vader_box_null();
    bool t1;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = l0;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        t1 = toolchain_ast$inspect(t0, l1, l2);
        if (t1) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        l5 = (l5 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static bool toolchain_ast$inspect_struct(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l6 = NULL;
    int64_t l4, l5;
    bool t0;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = toolchain_ast$inspect_decorators(((vader_struct_toolchain_ast$StructDecl_t*) l0)->f_decorators, l1, l2);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    t0 = toolchain_ast$inspect_type_params(((vader_struct_toolchain_ast$StructDecl_t*) l0)->f_type_params, l1, l2);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    l3 = ((vader_struct_toolchain_ast$StructDecl_t*) l0)->f_fields;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        l6 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        t0 = toolchain_ast$inspect(((vader_struct_toolchain_ast$StructField_t*) l6)->f_ty, l1, l2);
        if (t0) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        t0 = toolchain_ast$inspect_maybe(((vader_struct_toolchain_ast$StructField_t*) l6)->f_default, l1, l2);
        if (t0) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        l5 = (l5 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static bool toolchain_ast$inspect_targets(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    int64_t l4, l5;
    vader_box_t l6 = vader_box_null();
    bool t0;
    vader_box_t* gc_roots[1] = { &l6 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = l0;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        l6 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        if ((l6.tag == 804u || l6.tag == 809u)) {
            t0 = toolchain_ast$inspect(VADER_UNION_FIELD(vader_box_t, vader_struct_toolchain_ast$PlaceTarget_t, f_place, l6.payload.obj), l1, l2);
            if (t0) {
                { vader_gc_top = gc_frame.prev; return true; }
            }
        } else if (!(l6.tag == 832u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l5 = (l5 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static bool toolchain_ast$inspect_trait(void* l0, void* l1, void* l2) {
    bool l3;
    bool t0;
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = toolchain_ast$inspect_decorators(((vader_struct_toolchain_ast$TraitDecl_t*) l0)->f_decorators, l1, l2);
    if (t0) {
        l3 = true;
    } else {
        l3 = toolchain_ast$inspect_type_params(((vader_struct_toolchain_ast$TraitDecl_t*) l0)->f_type_params, l1, l2);
    }
    if (l3) {
        l3 = true;
    } else {
        l3 = toolchain_ast$inspect_maybe(((vader_struct_toolchain_ast$TraitDecl_t*) l0)->f_requires, l1, l2);
    }
    if (l3) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    t0 = toolchain_ast$inspect_fns(((vader_struct_toolchain_ast$TraitDecl_t*) l0)->f_members, l1, l2);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool toolchain_ast$inspect_type_params(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l6 = NULL;
    int64_t l4, l5;
    bool t0;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = l0;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        l6 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        t0 = toolchain_ast$inspect_maybe(((vader_struct_toolchain_ast$TypeParam_t*) l6)->f_bound, l1, l2);
        if (t0) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        t0 = toolchain_ast$inspect_maybe(((vader_struct_toolchain_ast$TypeParam_t*) l6)->f_default, l1, l2);
        if (t0) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        l5 = (l5 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

vader_string_t toolchain_ast$int_literal_text(void* l0) {
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
    t0 = ((vader_struct_toolchain_ast$IntLitExpr_t*) l0)->f_negative;
    if (!(t0)) {
        l1 = (void*) vader_buffer_new((size_t) INT64_C(20));
        l2 = INT64_C(0);
        l3 = ((vader_struct_toolchain_ast$IntLitExpr_t*) l0)->f_value;
        l2 = std_core$write_unsigned(l1, l2, l3);
        t1 = std_core$finish_buffer(l1, l2);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = (void*) vader_buffer_new((size_t) INT64_C(21));
    l2 = INT64_C(0);
    l2 = std_core$write_string_at(l1, l2, 386u);
    l3 = ((vader_struct_toolchain_ast$IntLitExpr_t*) l0)->f_value;
    l2 = std_core$write_unsigned(l1, l2, l3);
    t1 = std_core$finish_buffer(l1, l2);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

int64_t toolchain_ast$int_literal_value(void* l0) {
    int64_t l1;
    bool t0;
    uint64_t t1;
    t0 = ((vader_struct_toolchain_ast$IntLitExpr_t*) l0)->f_negative;
    if (!(t0)) {
        t1 = ((vader_struct_toolchain_ast$IntLitExpr_t*) l0)->f_value;
        return ((int64_t) (uint64_t) t1);
    }
    t1 = ((vader_struct_toolchain_ast$IntLitExpr_t*) l0)->f_value;
    l1 = ((int64_t) (uint64_t) t1);
    return (INT64_C(0) - l1);
}

static bool toolchain_ast$is_arith_op(uint8_t l0) {
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

static vader_box_t toolchain_ast$own_const_type(void* l0) {
    if (!(((vader_struct_toolchain_ast$ConstDecl_t*) l0)->f_comptime_body.tag == 0u)) {
        return vader_box_obj(0u, NULL);
    }
    return ((vader_struct_toolchain_ast$ConstDecl_t*) l0)->f_ty;
}

static vader_string_t toolchain_ast$sole_string_argument(void* l0) {
    vader_box_t l1;
    int64_t t0;
    vader_box_t t1;
    vader_string_t t2;
    t0 = ((vader_array_t*) ((vader_struct_toolchain_ast$Decorator_t*) l0)->f_args)->length;
    if (t0 != INT64_C(1)) {
        return 0u;
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$Decorator_t*) l0)->f_args);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
    t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
    l1 = toolchain_ast$string_literal_text(t1);
    if (l1.tag == 0u) {
        return 0u;
    }
    t2 = l1.payload.s;
    return t2;
}

vader_box_t toolchain_ast$string_literal_text(vader_box_t l0) {
    vader_box_t l1;
    void* t0;
    int64_t t1;
    vader_string_t t2;
    if (l0.tag == 813u) {
        t0 = l0.payload.obj;
        t1 = ((vader_array_t*) ((vader_struct_toolchain_ast$StringLitExpr_t*) t0)->f_parts)->length;
        if (t1 != INT64_C(1)) {
            return vader_box_obj(0u, NULL);
        }
        t0 = l0.payload.obj;
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$StringLitExpr_t*) t0)->f_parts);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
        l1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
        if (!(l1.tag == 815u)) {
            return vader_box_obj(0u, NULL);
        }
        t0 = l1.payload.obj;
        t2 = ((vader_struct_toolchain_ast$StringLitText_t*) t0)->f_value;
        return vader_box_string(447u, t2);
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t toolchain_ast$struct_item_value(vader_box_t l0) {
    void* t0;
    if (l0.tag == 819u) {
        t0 = l0.payload.obj;
        return ((vader_struct_toolchain_ast$StructLitField_t*) t0)->f_value;
    }
    if (!(l0.tag == 820u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    t0 = l0.payload.obj;
    return ((vader_struct_toolchain_ast$StructLitSpread_t*) t0)->f_expr;
}
