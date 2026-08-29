#include "bootstrap.split.h"

void toolchain_ast_append_bitor_variants(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &l3 };
    void** gc_raw_roots[2] = { &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 232u) {
        l2 = l0.payload.obj;
        if (((vader_struct_toolchain_ast_BinaryExpr_t*) l2)->f_op == INT32_C(8)) {
            toolchain_ast_append_bitor_variants(((vader_struct_toolchain_ast_BinaryExpr_t*) l2)->f_left, l1);
            toolchain_ast_append_bitor_variants(((vader_struct_toolchain_ast_BinaryExpr_t*) l2)->f_right, l1);
            { vader_gc_top = gc_frame.prev; return; }
        }
        l2 = l0.payload.obj;
        vader_array_push((vader_array_t*) l1, vader_ref_box(l2));
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = l0;
    vader_array_push((vader_array_t*) l1, l3);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t toolchain_ast_coalesce_fallback_expr(vader_box_t l0) {
    void* t0;
    if (l0.tag == 273u) {
        t0 = l0.payload.obj;
        return ((vader_struct_toolchain_ast_ReturnStmt_t*) t0)->f_value;
    }
    if ((l0.tag == 267u || l0.tag == 268u)) {
        return vader_box_obj(0u, NULL);
    }
    if ((l0.tag == 230u || l0.tag == 231u || l0.tag == 232u || l0.tag == 233u || l0.tag == 234u || l0.tag == 235u || l0.tag == 236u || l0.tag == 237u || l0.tag == 238u || l0.tag == 239u || l0.tag == 240u || l0.tag == 241u || l0.tag == 242u || l0.tag == 243u || l0.tag == 244u || l0.tag == 245u || l0.tag == 246u || l0.tag == 247u || l0.tag == 248u || l0.tag == 249u || l0.tag == 250u || l0.tag == 251u || l0.tag == 252u || l0.tag == 253u || l0.tag == 254u || l0.tag == 255u || l0.tag == 256u || l0.tag == 257u)) {
        return l0;
    }
    vader_unreachable("unreachable return in toolchain_ast$coalesce_fallback_expr");
}

void* toolchain_ast_collect_bitor_variants(vader_box_t l0) {
    void* l1 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(339u, 0u, 13u, 261u);
    l1 = (void*) _a0_arr;
    toolchain_ast_append_bitor_variants(l0, l1);
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
    if (l0.tag == 250u) {
        t0 = l0.payload.obj;
        return ((vader_struct_toolchain_ast_MutableTypeExpr_t*) t0)->f_inner;
    }
    return l0;
}

bool toolchain_ast_type_expr_marks_mutable(vader_box_t l0) {
    void* l1;
    bool l2;
    bool t0;
    if (l0.tag == 0u) {
        return false;
    }
    if (l0.tag == 250u) {
        return true;
    }
    if (l0.tag == 232u) {
        l1 = l0.payload.obj;
        if (((vader_struct_toolchain_ast_BinaryExpr_t*) l1)->f_op == INT32_C(8)) {
            t0 = toolchain_ast_type_expr_marks_mutable(((vader_struct_toolchain_ast_BinaryExpr_t*) l1)->f_left);
            if (t0) {
                l2 = true;
            } else {
                l2 = toolchain_ast_type_expr_marks_mutable(((vader_struct_toolchain_ast_BinaryExpr_t*) l1)->f_right);
            }
            return l2;
        }
        return false;
    }
    return false;
}

