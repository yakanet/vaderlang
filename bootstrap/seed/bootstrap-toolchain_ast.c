#include "bootstrap.split.h"

static void toolchain_ast_append_bitor_variants(vader_box_t l0, void* l1);

static void toolchain_ast_append_bitor_variants(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l0, &l3 };
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 397u) {
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
    } else {
        l3 = l0;
        vader_array_push((vader_array_t*) l1, l3);
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t toolchain_ast_coalesce_fallback_expr(vader_box_t l0) {
    vader_box_t l1;
    void* t0;
    if (l0.tag == 458u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast_ReturnStmt_t*) t0)->f_value;
    } else {
        if ((l0.tag == 401u || l0.tag == 407u)) {
            l1 = vader_box_obj(0u, NULL);
        } else {
            if ((l0.tag == 393u || l0.tag == 396u || l0.tag == 397u || l0.tag == 399u || l0.tag == 400u || l0.tag == 403u || l0.tag == 404u || l0.tag == 405u || l0.tag == 415u || l0.tag == 420u || l0.tag == 421u || l0.tag == 424u || l0.tag == 426u || l0.tag == 427u || l0.tag == 430u || l0.tag == 435u || l0.tag == 437u || l0.tag == 438u || l0.tag == 440u || l0.tag == 444u || l0.tag == 446u || l0.tag == 449u || l0.tag == 450u || l0.tag == 455u || l0.tag == 459u || l0.tag == 461u || l0.tag == 466u || l0.tag == 476u)) {
                l1 = l0;
            } else {
                vader_unreachable("unreachable return in toolchain_ast$coalesce_fallback_expr");
            }
        }
    }
    return l1;
}

void* toolchain_ast_collect_bitor_variants(vader_box_t l0) {
    void* l1 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(113u, 0u, 13u, 1040u);
    l1 = (void*) _a0_arr;
    toolchain_ast_append_bitor_variants(l0, l1);
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

bool toolchain_ast_decorators_have(void* l0, vader_string_t l1) {
    void* l2;
    size_t l3, l4;
    void* t0;
    vader_string_t t1;
    int64_t t2;
    l2 = l0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_7: {
            if ((l4 < l3)) {
                if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
                t1 = ((vader_struct_toolchain_ast_Decorator_t*) t0)->f_name;
                if (t1 == l1) {
                    return true;
                }
                t2 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                goto loop_7;
            }
        }
    }
    return false;
}

bool toolchain_ast_param_is_mutable(void* l0) {
    bool l1;
    bool t0;
    t0 = ((vader_struct_toolchain_ast_FnParam_t*) l0)->f_mutable;
    if (t0) {
        l1 = true;
    } else {
        l1 = toolchain_ast_type_expr_marks_mutable(((vader_struct_toolchain_ast_FnParam_t*) l0)->f_ty);
    }
    return l1;
}

vader_box_t toolchain_ast_strip_mut_marker(vader_box_t l0) {
    void* t0;
    if (l0.tag == 446u) {
        t0 = l0.payload.obj;
        return ((vader_struct_toolchain_ast_MutableTypeExpr_t*) t0)->f_inner;
    }
    return l0;
}

bool toolchain_ast_type_expr_marks_mutable(vader_box_t l0) {
    bool l1;
    void* t0;
    bool t1;
    if (l0.tag == 0u) {
        return false;
    }
    if (l0.tag == 446u) {
        return true;
    }
    if (l0.tag == 397u) {
        t0 = l0.payload.obj;
        if (((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_op == INT32_C(8)) {
            t0 = l0.payload.obj;
            t1 = toolchain_ast_type_expr_marks_mutable(((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_left);
            if (t1) {
                l1 = true;
            } else {
                t0 = l0.payload.obj;
                l1 = toolchain_ast_type_expr_marks_mutable(((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_right);
            }
            return l1;
        }
    }
    return false;
}

