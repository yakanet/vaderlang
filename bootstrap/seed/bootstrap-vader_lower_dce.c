#include "bootstrap.split.h"

static bool vader_lower_dce$fn_survives(vader_box_t l0, void* l1, void* l2);
static bool vader_lower_dce$is_fn_root(void* l0, bool l1, bool l2, bool l3);
static void vader_lower_dce$mark_reachable(void* l0, void* l1, void* l2);
static bool vader_lower_dce$project_has_main(void* l0);

static bool vader_lower_dce$fn_survives(vader_box_t l0, void* l1, void* l2) {
    vader_box_t l3;
    int32_t l4;
    void* t0;
    vader_box_t t1;
    if (!(l0.tag == 1266u)) {
        return true;
    }
    t0 = l0.payload.obj;
    l3 = ((vader_struct_vader_core_mono$MonoEntry_t*) ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) t0)->f_origin)->f_symbol;
    if (!(l3.tag == 892u)) {
        return true;
    }
    t0 = l3.payload.obj;
    l4 = ((vader_struct_vader_core_symbol$Symbol_t*) t0)->f_id;
    t1 = std_collections$MutableMap$std_core$Index$at__i32__bool(l1, l4);
    return !(t1.tag == 0u);
}

static bool vader_lower_dce$is_fn_root(void* l0, bool l1, bool l2, bool l3) {
    vader_box_t l4;
    void* l5;
    void* l8;
    int64_t l6, l7;
    bool t0;
    void* t1;
    vader_string_t t2;
    if (l1) {
        if (!(l2)) {
            return true;
        }
    }
    if (((vader_struct_vader_lower_ir$LoweredFnDecl_t*) l0)->f_body.tag == 0u) {
        return true;
    }
    t0 = ((vader_struct_vader_core_mono$MonoEntry_t*) ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) l0)->f_origin)->f_is_main;
    if (t0) {
        return true;
    }
    l4 = ((vader_struct_vader_core_mono$MonoEntry_t*) ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) l0)->f_origin)->f_decl;
    if (l4.tag == 650u) {
        t1 = l4.payload.obj;
        l5 = ((vader_struct_toolchain_ast$FnDecl_t*) t1)->f_decorators;
        l6 = ((vader_array_t*) l5)->length;
        l7 = INT64_C(0);
        while ((l7 < l6)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            l8 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
            t2 = ((vader_struct_toolchain_ast$Decorator_t*) l8)->f_name;
            if (t2 == 1941u) {
                return true;
            }
            t2 = ((vader_struct_toolchain_ast$Decorator_t*) l8)->f_name;
            if (t2 == 1954u) {
                return true;
            }
            if (l3) {
                t2 = ((vader_struct_toolchain_ast$Decorator_t*) l8)->f_name;
                if (t2 == 2701u) {
                    return true;
                }
            }
            l7 = (l7 + INT64_C(1));
        }
    }
    return false;
}

static void vader_lower_dce$mark_reachable(void* l0, void* l1, void* l2) {
    vader_box_t l3 = vader_box_null();
    int32_t l4;
    vader_string_t l5 = 0;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_core_mono$MonoEntry_t*) ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) l0)->f_origin)->f_symbol;
    if (l3.tag == 892u) {
        t0 = l3.payload.obj;
        l4 = ((vader_struct_vader_core_symbol$Symbol_t*) t0)->f_id;
        std_collections$MutableMap$std_core$IndexSet$set_at__i32__bool(l1, l4, true);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l5 = ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) l0)->f_mangled;
    std_collections$MutableMap$std_core$IndexSet$set_at__string__bool(l2, l5, true);
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_lower_dce$project_has_main(void* l0) {
    void* l1;
    void* l2;
    void* l3;
    int64_t l4, l5, l6, l7;
    vader_box_t l8;
    vader_box_t t0;
    vader_string_t t1;
    void* t2;
    bool t3;
    l1 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l0)->f_modules;
    l2 = ((vader_struct_std_collections$MutableMap__string__vader_lower_ir_LoweredModule_t*) l1)->f_ekeys;
    l3 = ((vader_struct_std_collections$MutableMap__string__vader_lower_ir_LoweredModule_t*) l1)->f_evals;
    l4 = INT64_C(0);
    l5 = ((vader_struct_std_collections$MutableMap__string__vader_lower_ir_LoweredModule_t*) l1)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l4];
        t1 = t0.payload.s;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        t2 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        l1 = ((vader_struct_vader_lower_ir$LoweredModule_t*) t2)->f_decls;
        l6 = ((vader_array_t*) l1)->length;
        l7 = INT64_C(0);
        while ((l7 < l6)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            l8 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l7);
            if (l8.tag == 1266u) {
                t2 = l8.payload.obj;
                if (!(((vader_struct_vader_lower_ir$LoweredFnDecl_t*) t2)->f_body.tag == 0u)) {
                    t2 = l8.payload.obj;
                    t3 = ((vader_struct_vader_core_mono$MonoEntry_t*) ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) t2)->f_origin)->f_is_main;
                    if (t3) {
                        return true;
                    }
                }
            }
            l7 = (l7 + INT64_C(1));
        }
        l4 = (l4 + INT64_C(1));
    }
    return false;
}

void* vader_lower_dce$prune_unreachable_fns(void* l0, bool l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l15 = NULL;
    void* l18 = NULL;
    void* l24 = NULL;
    void* l26 = NULL;
    void* l29 = NULL;
    void* l30 = NULL;
    void* l31 = NULL;
    bool l8, l17;
    int64_t l11, l12, l19, l20, l34, l35, l36;
    vader_string_t l13 = 0;
    vader_string_t l14 = 0;
    vader_string_t l16 = 0;
    vader_string_t l25 = 0;
    vader_string_t l27 = 0;
    vader_string_t l28 = 0;
    vader_box_t l21 = vader_box_null(), l22 = vader_box_null();
    int32_t l23, l32, l33;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    bool t2;
    int64_t t3;
    vader_box_t* gc_roots[3] = { &l21, &l22, &t0 };
    void** gc_raw_roots[17] = {
        &l0, &l2, &l3, &l4, &l5, &l6, &l7, &l9, &l10, &l15, &l18, &l24, &l26, &l29, &l30, &l31, &t1,
    };
    vader_string_t* gc_atom_roots[6] = { &l13, &l14, &l16, &l25, &l27, &l28 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 17u, gc_roots, gc_raw_roots, 0u, NULL, 6u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 7u, 338u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 346u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__i32__Any_t* _a3_obj = (vader_struct_std_collections$MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__Any_t));
    vader_obj_header_init(_a3_obj, 459u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l2 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(21u, 0u, 0u, 335u);
    l3 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(28u, 0u, 0u, 346u);
    l4 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(22u, 0u, 7u, 338u);
    l5 = (void*) _a6_arr;
    vader_struct_std_collections$MutableMap__string__Any_t* _a7_obj = (vader_struct_std_collections$MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__Any_t));
    vader_obj_header_init(_a7_obj, 533u);
    _a7_obj->f_ekeys = l3;
    _a7_obj->f_evals = l4;
    _a7_obj->f_index = l5;
    _a7_obj->f_mask = INT64_C(0);
    _a7_obj->f_grow_at = INT64_C(0);
    _a7_obj->f_size = INT64_C(0);
    _a7_obj->f_tombs = INT64_C(0);
    l3 = (void*) _a7_obj;
    vader_array_t* _a8_arr = vader_array_new(22u, 0u, 7u, 338u);
    l4 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(19u, 0u, 12u, 333u);
    l5 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(22u, 0u, 7u, 338u);
    l6 = (void*) _a10_arr;
    vader_struct_std_collections$MutableMap__i32__bool_t* _a11_obj = (vader_struct_std_collections$MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__bool_t));
    vader_obj_header_init(_a11_obj, 462u);
    _a11_obj->f_ekeys = l4;
    _a11_obj->f_evals = l5;
    _a11_obj->f_index = l6;
    _a11_obj->f_mask = INT64_C(0);
    _a11_obj->f_grow_at = INT64_C(0);
    _a11_obj->f_size = INT64_C(0);
    _a11_obj->f_tombs = INT64_C(0);
    l4 = (void*) _a11_obj;
    vader_array_t* _a12_arr = vader_array_new(21u, 0u, 0u, 335u);
    l5 = (void*) _a12_arr;
    vader_array_t* _a13_arr = vader_array_new(19u, 0u, 12u, 333u);
    l6 = (void*) _a13_arr;
    vader_array_t* _a14_arr = vader_array_new(22u, 0u, 7u, 338u);
    l7 = (void*) _a14_arr;
    vader_struct_std_collections$MutableMap__string__bool_t* _a15_obj = (vader_struct_std_collections$MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__bool_t));
    vader_obj_header_init(_a15_obj, 539u);
    _a15_obj->f_ekeys = l5;
    _a15_obj->f_evals = l6;
    _a15_obj->f_index = l7;
    _a15_obj->f_mask = INT64_C(0);
    _a15_obj->f_grow_at = INT64_C(0);
    _a15_obj->f_size = INT64_C(0);
    _a15_obj->f_tombs = INT64_C(0);
    l5 = (void*) _a15_obj;
    vader_array_t* _a16_arr = vader_array_new(266u, 0u, 13u, 2057u);
    l6 = (void*) _a16_arr;
    l8 = vader_lower_dce$project_has_main(l0);
    l7 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l0)->f_modules;
    l9 = ((vader_struct_std_collections$MutableMap__string__vader_lower_ir_LoweredModule_t*) l7)->f_ekeys;
    l10 = ((vader_struct_std_collections$MutableMap__string__vader_lower_ir_LoweredModule_t*) l7)->f_evals;
    l11 = INT64_C(0);
    l12 = ((vader_struct_std_collections$MutableMap__string__vader_lower_ir_LoweredModule_t*) l7)->f_size;
    while ((l11 < l12)) {
        vader_array_t* _a17_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l11)
        t0 = vader_array_box_slots(_a17_slotarr->buf)[_a17_slotarr->offset + (size_t) l11];
        l13 = t0.payload.s;
        vader_array_t* _a18_slotarr = ((vader_array_t*) l10);
        VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a18_slotarr, l11)
        l7 = vader_array_ref_load_obj(_a18_slotarr->buf, _a18_slotarr->offset + (size_t) l11);
        l14 = l13;
        l15 = l7;
        l16 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l0)->f_entry;
        l17 = l14 == l16;
        l18 = ((vader_struct_vader_lower_ir$LoweredModule_t*) l15)->f_decls;
        l19 = ((vader_array_t*) l18)->length;
        l20 = INT64_C(0);
        while ((l20 < l19)) {
            vader_array_t* _a19_slotarr = ((vader_array_t*) l18);
            VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
            l21 = vader_array_ref_load_box(_a19_slotarr->buf, _a19_slotarr->offset + (size_t) l20);
            if (l21.tag == 1266u) {
                t1 = l21.payload.obj;
                l22 = ((vader_struct_vader_core_mono$MonoEntry_t*) ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) t1)->f_origin)->f_symbol;
                if (l22.tag == 892u) {
                    t1 = l22.payload.obj;
                    l23 = ((vader_struct_vader_core_symbol$Symbol_t*) t1)->f_id;
                    l24 = l21.payload.obj;
                    std_collections$MutableMap$std_core$IndexSet$set_at__i32__Any(l2, l23, vader_ref_box(l24));
                } else {
                    t1 = l21.payload.obj;
                    l25 = ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) t1)->f_mangled;
                    l26 = l21.payload.obj;
                    std_collections$MutableMap$std_core$IndexSet$set_at__string__Any(l3, l25, vader_ref_box(l26));
                    t1 = l21.payload.obj;
                    l27 = ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) t1)->f_mangled;
                    t0 = std_collections$MutableMap$std_core$Index$at__string__bool(l5, l27);
                    if (t0.tag == 0u) {
                        t1 = l21.payload.obj;
                        l28 = ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) t1)->f_mangled;
                        std_collections$MutableMap$std_core$IndexSet$set_at__string__bool(l5, l28, true);
                        l29 = l21.payload.obj;
                        vader_array_push_ref((vader_array_t*) l6, l29);
                    }
                }
                t1 = l21.payload.obj;
                t2 = vader_lower_dce$is_fn_root(t1, l17, l8, l1);
                if (t2) {
                    t1 = l21.payload.obj;
                    vader_lower_dce$mark_reachable(t1, l4, l5);
                    l30 = l21.payload.obj;
                    vader_array_push_ref((vader_array_t*) l6, l30);
                }
            } else if (l21.tag == 1258u) {
                l31 = l21.payload.obj;
                vader_array_push_ref((vader_array_t*) l6, l31);
            }
            l20 = (l20 + INT64_C(1));
        }
        l11 = (l11 + INT64_C(1));
    }
    l7 = std_collections$values__i32__vader_lower_ir_ConstFnWrap(((vader_struct_vader_lower_ir$LoweredProject_t*) l0)->f_const_fn_wrap);
    l9 = std_collections$values__i32__vader_lower_ir_ConstFnWrap(((vader_struct_vader_lower_ir$LoweredProject_t*) l0)->f_const_fresh_wrap);
    l11 = ((vader_array_t*) l7)->length;
    l12 = INT64_C(0);
    while ((l12 < l11)) {
        vader_array_t* _a20_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
        l10 = vader_array_ref_load_obj(_a20_slotarr->buf, _a20_slotarr->offset + (size_t) l12);
        l23 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$ConstFnWrap_t*) l10)->f_fn_symbol)->f_id;
        l21 = std_collections$MutableMap$std_core$Index$at__i32__Any(l2, l23);
        if (!(l21.tag == 0u)) {
            l32 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$ConstFnWrap_t*) l10)->f_fn_symbol)->f_id;
            t0 = std_collections$MutableMap$std_core$Index$at__i32__bool(l4, l32);
            if (t0.tag == 0u) {
                l33 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$ConstFnWrap_t*) l10)->f_fn_symbol)->f_id;
                std_collections$MutableMap$std_core$IndexSet$set_at__i32__bool(l4, l33, true);
                l22 = l21;
                vader_array_push_ref((vader_array_t*) l6, l22.payload.obj);
            }
        }
        l12 = (l12 + INT64_C(1));
    }
    l11 = ((vader_array_t*) l9)->length;
    l12 = INT64_C(0);
    while ((l12 < l11)) {
        vader_array_t* _a21_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
        l7 = vader_array_ref_load_obj(_a21_slotarr->buf, _a21_slotarr->offset + (size_t) l12);
        l23 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$ConstFnWrap_t*) l7)->f_fn_symbol)->f_id;
        l21 = std_collections$MutableMap$std_core$Index$at__i32__Any(l2, l23);
        if (!(l21.tag == 0u)) {
            l32 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$ConstFnWrap_t*) l7)->f_fn_symbol)->f_id;
            t0 = std_collections$MutableMap$std_core$Index$at__i32__bool(l4, l32);
            if (t0.tag == 0u) {
                l33 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$ConstFnWrap_t*) l7)->f_fn_symbol)->f_id;
                std_collections$MutableMap$std_core$IndexSet$set_at__i32__bool(l4, l33, true);
                l22 = l21;
                vader_array_push_ref((vader_array_t*) l6, l22.payload.obj);
            }
        }
        l12 = (l12 + INT64_C(1));
    }
    vader_array_t* _a22_arr = vader_array_new(21u, 0u, 0u, 335u);
    l7 = (void*) _a22_arr;
    vader_array_t* _a23_arr = vader_array_new(28u, 0u, 0u, 346u);
    l9 = (void*) _a23_arr;
    vader_array_t* _a24_arr = vader_array_new(22u, 0u, 7u, 338u);
    l10 = (void*) _a24_arr;
    vader_struct_std_collections$MutableMap__string__Any___t* _a25_obj = (vader_struct_std_collections$MutableMap__string__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__Any___t));
    vader_obj_header_init(_a25_obj, 534u);
    _a25_obj->f_ekeys = l7;
    _a25_obj->f_evals = l9;
    _a25_obj->f_index = l10;
    _a25_obj->f_mask = INT64_C(0);
    _a25_obj->f_grow_at = INT64_C(0);
    _a25_obj->f_size = INT64_C(0);
    _a25_obj->f_tombs = INT64_C(0);
    l7 = (void*) _a25_obj;
    l9 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l0)->f_vtable_entries;
    l11 = ((vader_array_t*) l9)->length;
    l12 = INT64_C(0);
    while ((l12 < l11)) {
        vader_array_t* _a26_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a26_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a26_slotarr, l12)
        l10 = vader_array_ref_load_obj(_a26_slotarr->buf, _a26_slotarr->offset + (size_t) l12);
        l13 = ((vader_struct_vader_lower_ir$LoweredVtableEntry_t*) l10)->f_trait_name;
        l14 = ((vader_struct_vader_lower_ir$LoweredVtableEntry_t*) l10)->f_method_name;
        l16 = concat_3(l13, 3068u, l14);
        l15 = (void*) &vader_fn_static___lambda_vader_lower_dce_0;
        l18 = std_collections$get_or_put_with__string__vader_core_symbol_Symbol__(l7, l16, l15);
        l24 = ((vader_struct_vader_lower_ir$LoweredVtableEntry_t*) l10)->f_fn_symbol;
        vader_array_push_ref((vader_array_t*) l18, l24);
        l12 = (l12 + INT64_C(1));
    }
    vader_array_t* _a27_arr = vader_array_new(21u, 0u, 0u, 335u);
    l9 = (void*) _a27_arr;
    vader_array_t* _a28_arr = vader_array_new(21u, 0u, 0u, 335u);
    l10 = (void*) _a28_arr;
    vader_array_t* _a29_arr = vader_array_new(19u, 0u, 12u, 333u);
    l15 = (void*) _a29_arr;
    vader_array_t* _a30_arr = vader_array_new(22u, 0u, 7u, 338u);
    l18 = (void*) _a30_arr;
    vader_struct_std_collections$MutableMap__string__bool_t* _a31_obj = (vader_struct_std_collections$MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__bool_t));
    vader_obj_header_init(_a31_obj, 539u);
    _a31_obj->f_ekeys = l10;
    _a31_obj->f_evals = l15;
    _a31_obj->f_index = l18;
    _a31_obj->f_mask = INT64_C(0);
    _a31_obj->f_grow_at = INT64_C(0);
    _a31_obj->f_size = INT64_C(0);
    _a31_obj->f_tombs = INT64_C(0);
    l10 = (void*) _a31_obj;
    vader_struct___lambda_env_vader_lower_dce_2_t* _a32_obj = (vader_struct___lambda_env_vader_lower_dce_2_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_lower_dce_2_t));
    vader_obj_header_init(_a32_obj, 421u);
    _a32_obj->f_cap_0 = l3;
    _a32_obj->f_cap_1 = l5;
    _a32_obj->f_cap_2 = l6;
    _a32_obj->f_cap_3 = l2;
    _a32_obj->f_cap_4 = l4;
    t1 = (void*) _a32_obj;
    vader_fn_t* _a33_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a33_closure, 306u);
    _a33_closure->code = (void*) &vader_fn_lift___lambda_vader_lower_dce_1;
    _a33_closure->env = t1;
    l2 = (void*) _a33_closure;
    vader_struct___lambda_env_vader_lower_dce_4_t* _a34_obj = (vader_struct___lambda_env_vader_lower_dce_4_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_lower_dce_4_t));
    vader_obj_header_init(_a34_obj, 422u);
    _a34_obj->f_cap_0 = l10;
    _a34_obj->f_cap_1 = l9;
    t1 = (void*) _a34_obj;
    vader_fn_t* _a35_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a35_closure, 303u);
    _a35_closure->code = (void*) &vader_fn_lift___lambda_vader_lower_dce_3;
    _a35_closure->env = t1;
    l3 = (void*) _a35_closure;
    l11 = INT64_C(0);
    for (;;) {
        for (;;) {
            l12 = ((vader_array_t*) l6)->length;
            if ((l11 < l12)) {
                vader_array_t* _a36_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a36_slotarr)
                l21 = vader_array_ref_load_box(_a36_slotarr->buf, _a36_slotarr->offset + (size_t) l11);
                l11 = vader_chk_add(i64, l11, INT64_C(1));
                vader_lower_ir$for_each_lowered_ref(l21, l2, l3);
                continue;
            }
            break;
        }
        l19 = ((vader_array_t*) l6)->length;
        l10 = l9;
        l20 = ((vader_array_t*) l10)->length;
        l34 = INT64_C(0);
        while ((l34 < l20)) {
            vader_array_t* _a37_slotarr = ((vader_array_t*) l10);
            VADER_ARRAY_RESOLVE_BUF(_a37_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a37_slotarr, l34)
            t0 = vader_array_box_slots(_a37_slotarr->buf)[_a37_slotarr->offset + (size_t) l34];
            l13 = t0.payload.s;
            l22 = std_collections$MutableMap$std_core$Index$at__string__Any(l7, l13);
            if (!(l22.tag == 0u)) {
                l15 = l22.payload.obj;
                l35 = ((vader_array_t*) l15)->length;
                l36 = INT64_C(0);
                while ((l36 < l35)) {
                    vader_array_t* _a38_slotarr = ((vader_array_t*) l15);
                    VADER_ARRAY_RESOLVE_BUF(_a38_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a38_slotarr, l36)
                    l18 = vader_array_ref_load_obj(_a38_slotarr->buf, _a38_slotarr->offset + (size_t) l36);
                    l23 = ((vader_struct_vader_core_symbol$Symbol_t*) l18)->f_id;
                    l14 = ((vader_struct_vader_core_symbol$Symbol_t*) l18)->f_name;
                    vader_fn_t* _a39_fnobj = (vader_fn_t*) l2;
                    ((vader_fn_erased_sig_2_t) _a39_fnobj->code)(_a39_fnobj->env, vader_box_i32(338u, l23), vader_box_string(335u, l14));
                    l36 = (l36 + INT64_C(1));
                }
            }
            l34 = (l34 + INT64_C(1));
        }
        t3 = ((vader_array_t*) l6)->length;
        if (t3 == l19) break;
        continue;
    }
    vader_array_t* _a40_arr = vader_array_new(21u, 0u, 0u, 335u);
    l2 = (void*) _a40_arr;
    vader_array_t* _a41_arr = vader_array_new(28u, 0u, 0u, 346u);
    l3 = (void*) _a41_arr;
    vader_array_t* _a42_arr = vader_array_new(22u, 0u, 7u, 338u);
    l6 = (void*) _a42_arr;
    vader_struct_std_collections$MutableMap__string__Any_t* _a43_obj = (vader_struct_std_collections$MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__Any_t));
    vader_obj_header_init(_a43_obj, 533u);
    _a43_obj->f_ekeys = l2;
    _a43_obj->f_evals = l3;
    _a43_obj->f_index = l6;
    _a43_obj->f_mask = INT64_C(0);
    _a43_obj->f_grow_at = INT64_C(0);
    _a43_obj->f_size = INT64_C(0);
    _a43_obj->f_tombs = INT64_C(0);
    l2 = (void*) _a43_obj;
    l3 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l0)->f_modules;
    l6 = ((vader_struct_std_collections$MutableMap__string__vader_lower_ir_LoweredModule_t*) l3)->f_ekeys;
    l7 = ((vader_struct_std_collections$MutableMap__string__vader_lower_ir_LoweredModule_t*) l3)->f_evals;
    l11 = INT64_C(0);
    l12 = ((vader_struct_std_collections$MutableMap__string__vader_lower_ir_LoweredModule_t*) l3)->f_size;
    while ((l11 < l12)) {
        vader_array_t* _a44_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a44_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a44_slotarr, l11)
        t0 = vader_array_box_slots(_a44_slotarr->buf)[_a44_slotarr->offset + (size_t) l11];
        l13 = t0.payload.s;
        vader_array_t* _a45_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a45_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a45_slotarr, l11)
        l3 = vader_array_ref_load_obj(_a45_slotarr->buf, _a45_slotarr->offset + (size_t) l11);
        l14 = l13;
        l9 = l3;
        vader_array_t* _a46_arr = vader_array_new(266u, 0u, 13u, 2057u);
        l10 = (void*) _a46_arr;
        l15 = ((vader_struct_vader_lower_ir$LoweredModule_t*) l9)->f_decls;
        l19 = ((vader_array_t*) l15)->length;
        l20 = INT64_C(0);
        while ((l20 < l19)) {
            vader_array_t* _a47_slotarr = ((vader_array_t*) l15);
            VADER_ARRAY_RESOLVE_BUF(_a47_slotarr)
            l21 = vader_array_ref_load_box(_a47_slotarr->buf, _a47_slotarr->offset + (size_t) l20);
            t2 = vader_lower_dce$fn_survives(l21, l4, l5);
            if (t2) {
                vader_array_push_ref((vader_array_t*) l10, l21.payload.obj);
            }
            l20 = (l20 + INT64_C(1));
        }
        l16 = ((vader_struct_vader_lower_ir$LoweredModule_t*) l9)->f_module_id;
        l25 = ((vader_struct_vader_lower_ir$LoweredModule_t*) l9)->f_display_path;
        vader_struct_vader_lower_ir$LoweredModule_t* _a48_obj = (vader_struct_vader_lower_ir$LoweredModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_lower_ir$LoweredModule_t));
        vader_obj_header_init(_a48_obj, 1278u);
        _a48_obj->f_module_id = l16;
        _a48_obj->f_display_path = l25;
        _a48_obj->f_decls = l10;
        l18 = (void*) _a48_obj;
        std_collections$MutableMap$std_core$IndexSet$set_at__string__Any(l2, l14, vader_ref_box(l18));
        l11 = (l11 + INT64_C(1));
    }
    l3 = l0;
    l13 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l3)->f_entry;
    l4 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l3)->f_vtable_entries;
    l5 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l3)->f_data_pool;
    l6 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l3)->f_globals;
    l7 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l3)->f_libraries;
    l9 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l3)->f_const_fn_wrap;
    l10 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l3)->f_const_inline;
    l15 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l3)->f_const_fresh_wrap;
    l18 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l3)->f_const_routes;
    l3 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l3)->f_trait_membership;
    vader_struct_vader_lower_ir$LoweredProject_t* _a49_obj = (vader_struct_vader_lower_ir$LoweredProject_t*) vader_gc_alloc(sizeof(vader_struct_vader_lower_ir$LoweredProject_t));
    vader_obj_header_init(_a49_obj, 1281u);
    _a49_obj->f_modules = l2;
    _a49_obj->f_entry = l13;
    _a49_obj->f_vtable_entries = l4;
    _a49_obj->f_data_pool = l5;
    _a49_obj->f_globals = l6;
    _a49_obj->f_libraries = l7;
    _a49_obj->f_const_fn_wrap = l9;
    _a49_obj->f_const_inline = l10;
    _a49_obj->f_const_fresh_wrap = l15;
    _a49_obj->f_const_routes = l18;
    _a49_obj->f_trait_membership = l3;
    t1 = (void*) _a49_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}
