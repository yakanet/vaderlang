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
    if (l0.tag == 502u) {
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
    vader_array_t* _a0_arr = vader_array_new(206u, 0u, 13u, 1375u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct_toolchain_ast_DestructureAssignStmt_t*) l0)->f_targets;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l5 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        if ((l5.tag == 559u || l5.tag == 564u)) {
            t0 = l5.payload.obj;
            l6 = ((vader_struct_toolchain_ast_PlaceTarget_t*) t0)->f_place;
            vader_array_push((vader_array_t*) l1, l6);
        } else if (!(l5.tag == 587u)) {
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
        l1 = 281u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 304u;
    } else if (l0 == INT32_C(2)) {
        l1 = 277u;
    } else if (l0 == INT32_C(3)) {
        l1 = 357u;
    } else if (l0 == INT32_C(4)) {
        l1 = 217u;
    } else if (l0 == INT32_C(5)) {
        l1 = 412u;
    } else if (l0 == INT32_C(6)) {
        l1 = 435u;
    } else if (l0 == INT32_C(7)) {
        l1 = 219u;
    } else if (l0 == INT32_C(8)) {
        l1 = 2769u;
    } else if (l0 == INT32_C(9)) {
        l1 = 840u;
    } else if (l0 == INT32_C(10)) {
        l1 = 220u;
    } else if (l0 == INT32_C(11)) {
        l1 = 2770u;
    } else if (l0 == INT32_C(12)) {
        l1 = 430u;
    } else if (l0 == INT32_C(13)) {
        l1 = 183u;
    } else if (l0 == INT32_C(14)) {
        l1 = 411u;
    } else if (l0 == INT32_C(15)) {
        l1 = 413u;
    } else if (l0 == INT32_C(16)) {
        l1 = 433u;
    } else if (l0 == INT32_C(17)) {
        l1 = 434u;
    } else if (l0 == INT32_C(18)) {
        l1 = 1955u;
    } else if (l0 == INT32_C(19)) {
        l1 = 1898u;
    } else if (l0 == INT32_C(20)) {
        l1 = 187u;
    } else if (l0 == INT32_C(21)) {
        l1 = 431u;
    } else if (l0 == INT32_C(22)) {
        l1 = 184u;
    } else if (l0 == INT32_C(23)) {
        l1 = 282u;
    } else if (l0 == INT32_C(24)) {
        l1 = 305u;
    } else {
        if (!(l0 == INT32_C(25))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 278u;
    }
    return l1;
}

vader_box_t toolchain_ast_coalesce_fallback_expr(vader_box_t l0) {
    vader_box_t l1;
    void* t0;
    if (l0.tag == 565u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast_ReturnStmt_t*) t0)->f_value;
        return l1;
    }
    if ((l0.tag == 505u || l0.tag == 511u)) {
        l1 = vader_box_obj(0u, NULL);
    } else {
        if (!((l0.tag == 497u || l0.tag == 501u || l0.tag == 502u || l0.tag == 503u || l0.tag == 504u || l0.tag == 507u || l0.tag == 508u || l0.tag == 509u || l0.tag == 520u || l0.tag == 525u || l0.tag == 526u || l0.tag == 529u || l0.tag == 531u || l0.tag == 532u || l0.tag == 535u || l0.tag == 540u || l0.tag == 542u || l0.tag == 543u || l0.tag == 545u || l0.tag == 549u || l0.tag == 551u || l0.tag == 554u || l0.tag == 555u || l0.tag == 561u || l0.tag == 566u || l0.tag == 568u || l0.tag == 573u || l0.tag == 582u))) {
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
    vader_array_t* _a0_arr = vader_array_new(206u, 0u, 13u, 1375u);
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
    if (((vader_struct_toolchain_ast_AssignStmt_t*) l0)->f_value.tag == 502u) {
        l1 = ((vader_struct_toolchain_ast_AssignStmt_t*) l0)->f_value.payload.obj;
        t0 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l1)->f_left.payload.obj;
        l2 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t0)->f_span;
        t0 = ((vader_struct_toolchain_ast_AssignStmt_t*) l0)->f_target.payload.obj;
        l3 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t0)->f_span;
        t1 = toolchain_span_Span_Equals_equals(l2, l3);
        if (t1) {
            t1 = toolchain_ast_is_arith_op(((vader_struct_toolchain_ast_BinaryExpr_t*) l1)->f_op);
            if (t1) {
                t2 = vader_box_i32(284u, (int32_t)(uint32_t) ((vader_struct_toolchain_ast_BinaryExpr_t*) l1)->f_op);
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

vader_string_t toolchain_ast_int_literal_text(void* l0) {
    void* l1 = NULL;
    size_t l2;
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
        l1 = std_core_new_byte_buffer((size_t) 20);
        l2 = (size_t) 0;
        l3 = ((vader_struct_toolchain_ast_IntLitExpr_t*) l0)->f_value;
        l2 = std_core_write_unsigned(l1, l2, l3);
        t1 = std_core_finish_buffer(l1, l2);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = std_core_new_byte_buffer((size_t) 21);
    l2 = (size_t) 0;
    l2 = std_core_write_string_at(l1, l2, 304u);
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
    if (!(l0.tag == 551u)) {
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
    if (l0.tag == 551u) {
        return true;
    }
    if (l0.tag == 502u) {
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

bool toolchain_ast_type_expr_marks_mutable_anywhere(vader_box_t l0) {
    void* l1;
    size_t l2, l3;
    void* t0;
    bool t1;
    vader_box_t t2;
    int64_t t3;
    if (l0.tag == 551u) {
        return true;
    }
    if (l0.tag == 497u) {
        t0 = l0.payload.obj;
        t1 = toolchain_ast_type_expr_marks_mutable_anywhere(((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t0)->f_element);
        return t1;
    }
    if (l0.tag == 566u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast_SeqLitExpr_t*) t0)->f_elements;
        l2 = ((vader_array_t*) l1)->length;
        l3 = (size_t) 0;
        while ((l3 < l2)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            t2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
            t1 = toolchain_ast_type_expr_marks_mutable_anywhere(t2);
            if (t1) {
                return true;
            }
            t3 = (l3 + INT64_C(1));
            l3 = (size_t) (int64_t) t3;
        }
        return false;
    }
    if (l0.tag == 502u) {
        t0 = l0.payload.obj;
        if (((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_op == INT32_C(8)) {
            t0 = l0.payload.obj;
            t1 = toolchain_ast_type_expr_marks_mutable_anywhere(((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_left);
            if (t1) {
                return true;
            }
            t0 = l0.payload.obj;
            t1 = toolchain_ast_type_expr_marks_mutable_anywhere(((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_right);
            return t1;
        }
        return false;
    }
    return false;
}
