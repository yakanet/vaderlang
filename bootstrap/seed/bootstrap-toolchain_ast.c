#include "bootstrap.split.h"

static void toolchain_ast_append_bitor_variants(vader_box_t l0, void* l1);
static bool toolchain_ast_is_arith_op(uint8_t l0);

static void toolchain_ast_append_bitor_variants(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l0, &l3 };
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 444u) {
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
    size_t l3, l4;
    vader_box_t l5 = vader_box_null(), l6 = vader_box_null();
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[2] = { &l5, &l6 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(178u, 0u, 13u, 1254u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct_toolchain_ast_DestructureAssignStmt_t*) l0)->f_targets;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        l5 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        if ((l5.tag == 501u || l5.tag == 506u)) {
            t0 = l5.payload.obj;
            l6 = ((vader_struct_toolchain_ast_PlaceTarget_t*) t0)->f_place;
            vader_array_push((vader_array_t*) l1, l6);
        } else if (!(l5.tag == 529u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t toolchain_ast_binary_op_symbol(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 272u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 293u;
    } else if (l0 == INT32_C(2)) {
        l1 = 268u;
    } else if (l0 == INT32_C(3)) {
        l1 = 332u;
    } else if (l0 == INT32_C(4)) {
        l1 = 209u;
    } else if (l0 == INT32_C(5)) {
        l1 = 383u;
    } else if (l0 == INT32_C(6)) {
        l1 = 406u;
    } else if (l0 == INT32_C(7)) {
        l1 = 211u;
    } else if (l0 == INT32_C(8)) {
        l1 = 2649u;
    } else if (l0 == INT32_C(9)) {
        l1 = 802u;
    } else if (l0 == INT32_C(10)) {
        l1 = 212u;
    } else if (l0 == INT32_C(11)) {
        l1 = 2650u;
    } else if (l0 == INT32_C(12)) {
        l1 = 401u;
    } else if (l0 == INT32_C(13)) {
        l1 = 175u;
    } else if (l0 == INT32_C(14)) {
        l1 = 382u;
    } else if (l0 == INT32_C(15)) {
        l1 = 384u;
    } else if (l0 == INT32_C(16)) {
        l1 = 404u;
    } else if (l0 == INT32_C(17)) {
        l1 = 405u;
    } else if (l0 == INT32_C(18)) {
        l1 = 1872u;
    } else if (l0 == INT32_C(19)) {
        l1 = 1818u;
    } else if (l0 == INT32_C(20)) {
        l1 = 179u;
    } else if (l0 == INT32_C(21)) {
        l1 = 402u;
    } else if (l0 == INT32_C(22)) {
        l1 = 176u;
    } else if (l0 == INT32_C(23)) {
        l1 = 273u;
    } else if (l0 == INT32_C(24)) {
        l1 = 294u;
    } else {
        if (!(l0 == INT32_C(25))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 269u;
    }
    return l1;
}

vader_box_t toolchain_ast_coalesce_fallback_expr(vader_box_t l0) {
    vader_box_t l1;
    void* t0;
    if (l0.tag == 507u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast_ReturnStmt_t*) t0)->f_value;
        return l1;
    }
    if ((l0.tag == 447u || l0.tag == 453u)) {
        l1 = vader_box_obj(0u, NULL);
    } else {
        if (!((l0.tag == 439u || l0.tag == 443u || l0.tag == 444u || l0.tag == 445u || l0.tag == 446u || l0.tag == 449u || l0.tag == 450u || l0.tag == 451u || l0.tag == 462u || l0.tag == 467u || l0.tag == 468u || l0.tag == 471u || l0.tag == 473u || l0.tag == 474u || l0.tag == 477u || l0.tag == 482u || l0.tag == 484u || l0.tag == 485u || l0.tag == 487u || l0.tag == 491u || l0.tag == 493u || l0.tag == 496u || l0.tag == 497u || l0.tag == 503u || l0.tag == 508u || l0.tag == 510u || l0.tag == 515u || l0.tag == 524u))) {
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
    vader_array_t* _a0_arr = vader_array_new(178u, 0u, 13u, 1254u);
    l1 = (void*) _a0_arr;
    toolchain_ast_append_bitor_variants(l0, l1);
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t toolchain_ast_compound_assign_op(void* l0) {
    void* l1;
    void* l2;
    void* l3;
    void* t0;
    bool t1;
    vader_box_t t2;
    if (((vader_struct_toolchain_ast_AssignStmt_t*) l0)->f_value.tag == 444u) {
        l1 = ((vader_struct_toolchain_ast_AssignStmt_t*) l0)->f_value.payload.obj;
        t0 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l1)->f_left.payload.obj;
        l2 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t0)->f_span;
        t0 = ((vader_struct_toolchain_ast_AssignStmt_t*) l0)->f_target.payload.obj;
        l3 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t0)->f_span;
        t1 = toolchain_span_Span_Equals_equals(l2, l3);
        if (t1) {
            t1 = toolchain_ast_is_arith_op(((vader_struct_toolchain_ast_BinaryExpr_t*) l1)->f_op);
            if (t1) {
                t2 = vader_box_i32(249u, (int32_t)(uint32_t) ((vader_struct_toolchain_ast_BinaryExpr_t*) l1)->f_op);
                return t2;
            }
        }
        return vader_box_obj(0u, NULL);
    }
    return vader_box_obj(0u, NULL);
}

bool toolchain_ast_decorators_have(void* l0, vader_string_t l1) {
    void* l2;
    size_t l3, l4;
    void* t0;
    vader_string_t t1;
    int64_t t2;
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t1 = ((vader_struct_toolchain_ast_Decorator_t*) t0)->f_name;
        if (t1 == l1) {
            return true;
        }
        t2 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t2;
    }
    return false;
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

bool toolchain_ast_param_is_mutable(void* l0) {
    bool t0;
    t0 = ((vader_struct_toolchain_ast_FnParam_t*) l0)->f_mutable;
    if (t0) {
        return true;
    }
    t0 = toolchain_ast_type_expr_marks_mutable(((vader_struct_toolchain_ast_FnParam_t*) l0)->f_ty);
    return t0;
}

vader_box_t toolchain_ast_strip_mut_marker(vader_box_t l0) {
    void* t0;
    if (!(l0.tag == 493u)) {
        return l0;
    }
    t0 = l0.payload.obj;
    return ((vader_struct_toolchain_ast_MutableTypeExpr_t*) t0)->f_inner;
}

bool toolchain_ast_type_expr_marks_mutable(vader_box_t l0) {
    void* t0;
    bool t1;
    if (l0.tag == 0u) {
        return false;
    }
    if (l0.tag == 493u) {
        return true;
    }
    if (l0.tag == 444u) {
        t0 = l0.payload.obj;
        if (((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_op == INT32_C(8)) {
            t0 = l0.payload.obj;
            t1 = toolchain_ast_type_expr_marks_mutable(((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_left);
            if (t1) {
                return true;
            }
            t0 = l0.payload.obj;
            t1 = toolchain_ast_type_expr_marks_mutable(((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_right);
            return t1;
        }
        return false;
    }
    return false;
}
