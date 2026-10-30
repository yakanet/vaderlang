#include "bootstrap.split.h"

static bool vader_lower_dce$entry_survives(void* l0, void* l1, void* l2, void* l3);
static bool vader_lower_dce$fn_survives(vader_box_t l0, void* l1, void* l2);
static bool vader_lower_dce$is_fn_root(void* l0, bool l1, bool l2, bool l3);
static void vader_lower_dce$mark_reachable(void* l0, void* l1, void* l2);
static bool vader_lower_dce$project_has_main(void* l0);
static bool vader_lower_dce$receiver_is_built(vader_box_t l0, void* l1);

static bool vader_lower_dce$entry_survives(void* l0, void* l1, void* l2, void* l3) {
    vader_string_t l4;
    int32_t l5;
    vader_box_t t0;
    bool t1;
    l4 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$LoweredVtableEntry_t*) l0)->f_fn_symbol)->f_name;
    t0 = std_collections$MutableMap$std_core$Index$at__string__Any(l1, l4);
    if (!(t0.tag == 0u)) {
        l4 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$LoweredVtableEntry_t*) l0)->f_fn_symbol)->f_name;
        t1 = std_collections$MutableSet$std_core$Contains$contains__string(l3, l4);
        return t1;
    }
    l5 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$LoweredVtableEntry_t*) l0)->f_fn_symbol)->f_id;
    t1 = std_collections$MutableSet$std_core$Contains$contains__i32(l2, l5);
    return t1;
}

static bool vader_lower_dce$fn_survives(vader_box_t l0, void* l1, void* l2) {
    vader_box_t l3;
    int32_t l4;
    vader_string_t l5;
    void* t0;
    bool t1;
    if (!(l0.tag == 1390u)) {
        return true;
    }
    t0 = l0.payload.obj;
    l3 = ((vader_struct_vader_core_mono$MonoEntry_t*) ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) t0)->f_origin)->f_symbol;
    if (!(l3.tag == 1015u)) {
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) t0)->f_mangled;
        t1 = std_collections$MutableSet$std_core$Contains$contains__string(l2, l5);
        return t1;
    }
    t0 = l3.payload.obj;
    l4 = ((vader_struct_vader_core_symbol$Symbol_t*) t0)->f_id;
    t1 = std_collections$MutableSet$std_core$Contains$contains__i32(l1, l4);
    return t1;
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
    if (l4.tag == 773u) {
        t1 = l4.payload.obj;
        l5 = ((vader_struct_toolchain_ast$FnDecl_t*) t1)->f_decorators;
        l6 = ((vader_array_t*) l5)->length;
        l7 = INT64_C(0);
        while ((l7 < l6)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            l8 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
            t2 = ((vader_struct_toolchain_ast$Decorator_t*) l8)->f_name;
            if (t2 == 1938u) {
                return true;
            }
            t2 = ((vader_struct_toolchain_ast$Decorator_t*) l8)->f_name;
            if (t2 == 1951u) {
                return true;
            }
            if (l3) {
                t2 = ((vader_struct_toolchain_ast$Decorator_t*) l8)->f_name;
                if (t2 == 2698u) {
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
    if (l3.tag == 1015u) {
        t0 = l3.payload.obj;
        l4 = ((vader_struct_vader_core_symbol$Symbol_t*) t0)->f_id;
        std_collections$add__i32(l1, l4);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l5 = ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) l0)->f_mangled;
    std_collections$add__string(l2, l5);
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
            if (l8.tag == 1390u) {
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
    void* l8 = NULL;
    void* l9 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l17 = NULL;
    void* l20 = NULL;
    void* l26 = NULL;
    void* l28 = NULL;
    void* l29 = NULL;
    void* l30 = NULL;
    void* l33 = NULL;
    bool l10, l19;
    int64_t l13, l14, l21, l22, l31, l32, l35;
    vader_string_t l15 = 0;
    vader_string_t l16 = 0;
    vader_string_t l18 = 0;
    vader_string_t l27 = 0;
    vader_box_t l23 = vader_box_null(), l24 = vader_box_null();
    int32_t l25, l34;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    bool t2;
    int64_t t3;
    vader_box_t* gc_roots[3] = { &l23, &l24, &t1 };
    void** gc_raw_roots[19] = {
        &l0, &l2, &l3, &l4, &l5, &l6, &l7, &l8, &l9, &l11, &l12, &l17, &l20, &l26, &l28, &l29, &l30,
        &l33, &t0,
    };
    vader_string_t* gc_atom_roots[4] = { &l15, &l16, &l18, &l27 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 19u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(23u, 0u, 7u, 450u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(29u, 0u, 0u, 458u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(23u, 0u, 7u, 450u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__i32__Any_t* _a3_obj = (vader_struct_std_collections$MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__Any_t));
    vader_obj_header_init(_a3_obj, 582u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l2 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(22u, 0u, 0u, 447u);
    l3 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(29u, 0u, 0u, 458u);
    l4 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(23u, 0u, 7u, 450u);
    l5 = (void*) _a6_arr;
    vader_struct_std_collections$MutableMap__string__Any_t* _a7_obj = (vader_struct_std_collections$MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__Any_t));
    vader_obj_header_init(_a7_obj, 656u);
    _a7_obj->f_ekeys = l3;
    _a7_obj->f_evals = l4;
    _a7_obj->f_index = l5;
    _a7_obj->f_mask = INT64_C(0);
    _a7_obj->f_grow_at = INT64_C(0);
    _a7_obj->f_size = INT64_C(0);
    _a7_obj->f_tombs = INT64_C(0);
    l3 = (void*) _a7_obj;
    vader_array_t* _a8_arr = vader_array_new(23u, 0u, 7u, 450u);
    l4 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(20u, 0u, 12u, 445u);
    l5 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(23u, 0u, 7u, 450u);
    l6 = (void*) _a10_arr;
    vader_struct_std_collections$MutableMap__i32__bool_t* _a11_obj = (vader_struct_std_collections$MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__bool_t));
    vader_obj_header_init(_a11_obj, 585u);
    _a11_obj->f_ekeys = l4;
    _a11_obj->f_evals = l5;
    _a11_obj->f_index = l6;
    _a11_obj->f_mask = INT64_C(0);
    _a11_obj->f_grow_at = INT64_C(0);
    _a11_obj->f_size = INT64_C(0);
    _a11_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a11_obj;
    vader_struct_std_collections$MutableSet__i32_t* _a12_obj = (vader_struct_std_collections$MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__i32_t));
    vader_obj_header_init(_a12_obj, 728u);
    _a12_obj->f_inner = t0;
    l4 = (void*) _a12_obj;
    vader_array_t* _a13_arr = vader_array_new(22u, 0u, 0u, 447u);
    l5 = (void*) _a13_arr;
    vader_array_t* _a14_arr = vader_array_new(20u, 0u, 12u, 445u);
    l6 = (void*) _a14_arr;
    vader_array_t* _a15_arr = vader_array_new(23u, 0u, 7u, 450u);
    l7 = (void*) _a15_arr;
    vader_struct_std_collections$MutableMap__string__bool_t* _a16_obj = (vader_struct_std_collections$MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__bool_t));
    vader_obj_header_init(_a16_obj, 662u);
    _a16_obj->f_ekeys = l5;
    _a16_obj->f_evals = l6;
    _a16_obj->f_index = l7;
    _a16_obj->f_mask = INT64_C(0);
    _a16_obj->f_grow_at = INT64_C(0);
    _a16_obj->f_size = INT64_C(0);
    _a16_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a16_obj;
    vader_struct_std_collections$MutableSet__string_t* _a17_obj = (vader_struct_std_collections$MutableSet__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__string_t));
    vader_obj_header_init(_a17_obj, 730u);
    _a17_obj->f_inner = t0;
    l5 = (void*) _a17_obj;
    vader_array_t* _a18_arr = vader_array_new(377u, 0u, 13u, 2198u);
    l6 = (void*) _a18_arr;
    vader_array_t* _a19_arr = vader_array_new(23u, 0u, 7u, 450u);
    l7 = (void*) _a19_arr;
    vader_array_t* _a20_arr = vader_array_new(20u, 0u, 12u, 445u);
    l8 = (void*) _a20_arr;
    vader_array_t* _a21_arr = vader_array_new(23u, 0u, 7u, 450u);
    l9 = (void*) _a21_arr;
    vader_struct_std_collections$MutableMap__i32__bool_t* _a22_obj = (vader_struct_std_collections$MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__bool_t));
    vader_obj_header_init(_a22_obj, 585u);
    _a22_obj->f_ekeys = l7;
    _a22_obj->f_evals = l8;
    _a22_obj->f_index = l9;
    _a22_obj->f_mask = INT64_C(0);
    _a22_obj->f_grow_at = INT64_C(0);
    _a22_obj->f_size = INT64_C(0);
    _a22_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a22_obj;
    vader_struct_std_collections$MutableSet__i32_t* _a23_obj = (vader_struct_std_collections$MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__i32_t));
    vader_obj_header_init(_a23_obj, 728u);
    _a23_obj->f_inner = t0;
    l7 = (void*) _a23_obj;
    vader_struct___lambda_env_vader_lower_dce_1_t* _a24_obj = (vader_struct___lambda_env_vader_lower_dce_1_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_lower_dce_1_t));
    vader_obj_header_init(_a24_obj, 541u);
    _a24_obj->f_cap_0 = l7;
    t0 = (void*) _a24_obj;
    vader_fn_t* _a25_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a25_closure, 440u);
    _a25_closure->code = (void*) &vader_fn_lift___lambda_vader_lower_dce_0;
    _a25_closure->env = t0;
    l8 = (void*) _a25_closure;
    l10 = vader_lower_dce$project_has_main(l0);
    l9 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l0)->f_modules;
    l11 = ((vader_struct_std_collections$MutableMap__string__vader_lower_ir_LoweredModule_t*) l9)->f_ekeys;
    l12 = ((vader_struct_std_collections$MutableMap__string__vader_lower_ir_LoweredModule_t*) l9)->f_evals;
    l13 = INT64_C(0);
    l14 = ((vader_struct_std_collections$MutableMap__string__vader_lower_ir_LoweredModule_t*) l9)->f_size;
    while ((l13 < l14)) {
        vader_array_t* _a26_slotarr = ((vader_array_t*) l11);
        VADER_ARRAY_RESOLVE_BUF(_a26_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a26_slotarr, l13)
        t1 = vader_array_box_slots(_a26_slotarr->buf)[_a26_slotarr->offset + (size_t) l13];
        l15 = t1.payload.s;
        vader_array_t* _a27_slotarr = ((vader_array_t*) l12);
        VADER_ARRAY_RESOLVE_BUF(_a27_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a27_slotarr, l13)
        l9 = vader_array_ref_load_obj(_a27_slotarr->buf, _a27_slotarr->offset + (size_t) l13);
        l16 = l15;
        l17 = l9;
        l18 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l0)->f_entry;
        l19 = l16 == l18;
        l20 = ((vader_struct_vader_lower_ir$LoweredModule_t*) l17)->f_decls;
        l21 = ((vader_array_t*) l20)->length;
        l22 = INT64_C(0);
        while ((l22 < l21)) {
            vader_array_t* _a28_slotarr = ((vader_array_t*) l20);
            VADER_ARRAY_RESOLVE_BUF(_a28_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a28_slotarr, l22)
            l23 = vader_array_ref_load_box(_a28_slotarr->buf, _a28_slotarr->offset + (size_t) l22);
            if (l23.tag == 1390u) {
                t0 = l23.payload.obj;
                l24 = ((vader_struct_vader_core_mono$MonoEntry_t*) ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) t0)->f_origin)->f_symbol;
                if (l24.tag == 1015u) {
                    t0 = l24.payload.obj;
                    l25 = ((vader_struct_vader_core_symbol$Symbol_t*) t0)->f_id;
                    l26 = l23.payload.obj;
                    std_collections$MutableMap$std_core$IndexSet$set_at__i32__Any(l2, l25, vader_ref_box(l26));
                } else {
                    t0 = l23.payload.obj;
                    l27 = ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) t0)->f_mangled;
                    l28 = l23.payload.obj;
                    std_collections$MutableMap$std_core$IndexSet$set_at__string__Any(l3, l27, vader_ref_box(l28));
                }
                t0 = l23.payload.obj;
                t2 = vader_lower_dce$is_fn_root(t0, l19, l10, l1);
                if (t2) {
                    t0 = l23.payload.obj;
                    vader_lower_dce$mark_reachable(t0, l4, l5);
                    l29 = l23.payload.obj;
                    vader_array_push_ref((vader_array_t*) l6, l29);
                    t0 = l23.payload.obj;
                    if (!(((vader_struct_vader_lower_ir$LoweredFnDecl_t*) t0)->f_body.tag == 0u)) {
                        t0 = l23.payload.obj;
                        l30 = ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) t0)->f_params;
                        l31 = ((vader_array_t*) l30)->length;
                        l32 = INT64_C(0);
                        while ((l32 < l31)) {
                            vader_array_t* _a29_slotarr = ((vader_array_t*) l30);
                            VADER_ARRAY_RESOLVE_BUF(_a29_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a29_slotarr, l32)
                            t0 = vader_array_ref_load_obj(_a29_slotarr->buf, _a29_slotarr->offset + (size_t) l32);
                            vader_core_types$for_each_type(((vader_struct_vader_lower_ir$LoweredParam_t*) t0)->f_type, l8);
                            l32 = (l32 + INT64_C(1));
                        }
                    }
                }
            } else if (l23.tag == 1382u) {
                l33 = l23.payload.obj;
                vader_array_push_ref((vader_array_t*) l6, l33);
            }
            l22 = (l22 + INT64_C(1));
        }
        l13 = (l13 + INT64_C(1));
    }
    l9 = std_collections$values__i32__vader_lower_ir_ConstFnWrap(((vader_struct_vader_lower_ir$LoweredProject_t*) l0)->f_const_fn_wrap);
    l11 = std_collections$values__i32__vader_lower_ir_ConstFnWrap(((vader_struct_vader_lower_ir$LoweredProject_t*) l0)->f_const_fresh_wrap);
    l13 = ((vader_array_t*) l9)->length;
    l14 = INT64_C(0);
    while ((l14 < l13)) {
        vader_array_t* _a30_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a30_slotarr)
        l12 = vader_array_ref_load_obj(_a30_slotarr->buf, _a30_slotarr->offset + (size_t) l14);
        l25 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$ConstFnWrap_t*) l12)->f_fn_symbol)->f_id;
        l23 = std_collections$MutableMap$std_core$Index$at__i32__Any(l2, l25);
        if (!(l23.tag == 0u)) {
            l34 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$ConstFnWrap_t*) l12)->f_fn_symbol)->f_id;
            t2 = std_collections$add__i32(l4, l34);
            if (t2) {
                l24 = l23;
                vader_array_push_ref((vader_array_t*) l6, l24.payload.obj);
            }
        }
        l14 = (l14 + INT64_C(1));
    }
    l13 = ((vader_array_t*) l11)->length;
    l14 = INT64_C(0);
    while ((l14 < l13)) {
        vader_array_t* _a31_slotarr = ((vader_array_t*) l11);
        VADER_ARRAY_RESOLVE_BUF(_a31_slotarr)
        l9 = vader_array_ref_load_obj(_a31_slotarr->buf, _a31_slotarr->offset + (size_t) l14);
        l25 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$ConstFnWrap_t*) l9)->f_fn_symbol)->f_id;
        l23 = std_collections$MutableMap$std_core$Index$at__i32__Any(l2, l25);
        if (!(l23.tag == 0u)) {
            l34 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$ConstFnWrap_t*) l9)->f_fn_symbol)->f_id;
            t2 = std_collections$add__i32(l4, l34);
            if (t2) {
                l24 = l23;
                vader_array_push_ref((vader_array_t*) l6, l24.payload.obj);
            }
        }
        l14 = (l14 + INT64_C(1));
    }
    vader_array_t* _a32_arr = vader_array_new(22u, 0u, 0u, 447u);
    l9 = (void*) _a32_arr;
    vader_array_t* _a33_arr = vader_array_new(29u, 0u, 0u, 458u);
    l11 = (void*) _a33_arr;
    vader_array_t* _a34_arr = vader_array_new(23u, 0u, 7u, 450u);
    l12 = (void*) _a34_arr;
    vader_struct_std_collections$MutableMap__string__Any___t* _a35_obj = (vader_struct_std_collections$MutableMap__string__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__Any___t));
    vader_obj_header_init(_a35_obj, 657u);
    _a35_obj->f_ekeys = l9;
    _a35_obj->f_evals = l11;
    _a35_obj->f_index = l12;
    _a35_obj->f_mask = INT64_C(0);
    _a35_obj->f_grow_at = INT64_C(0);
    _a35_obj->f_size = INT64_C(0);
    _a35_obj->f_tombs = INT64_C(0);
    l9 = (void*) _a35_obj;
    l11 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l0)->f_vtable_entries;
    l13 = ((vader_array_t*) l11)->length;
    l14 = INT64_C(0);
    while ((l14 < l13)) {
        vader_array_t* _a36_slotarr = ((vader_array_t*) l11);
        VADER_ARRAY_RESOLVE_BUF(_a36_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a36_slotarr, l14)
        l12 = vader_array_ref_load_obj(_a36_slotarr->buf, _a36_slotarr->offset + (size_t) l14);
        l15 = ((vader_struct_vader_lower_ir$LoweredVtableEntry_t*) l12)->f_trait_name;
        l16 = ((vader_struct_vader_lower_ir$LoweredVtableEntry_t*) l12)->f_method_name;
        l18 = concat_3(l15, 3063u, l16);
        l17 = (void*) &vader_fn_static___lambda_vader_lower_dce_2;
        t0 = std_collections$get_or_put_with__string__vader_lower_ir_LoweredVtableEntry__(l9, l18, l17);
        vader_array_push_ref((vader_array_t*) t0, l12);
        l14 = (l14 + INT64_C(1));
    }
    vader_array_t* _a37_arr = vader_array_new(22u, 0u, 0u, 447u);
    l11 = (void*) _a37_arr;
    vader_array_t* _a38_arr = vader_array_new(22u, 0u, 0u, 447u);
    l12 = (void*) _a38_arr;
    vader_array_t* _a39_arr = vader_array_new(20u, 0u, 12u, 445u);
    l17 = (void*) _a39_arr;
    vader_array_t* _a40_arr = vader_array_new(23u, 0u, 7u, 450u);
    l20 = (void*) _a40_arr;
    vader_struct_std_collections$MutableMap__string__bool_t* _a41_obj = (vader_struct_std_collections$MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__bool_t));
    vader_obj_header_init(_a41_obj, 662u);
    _a41_obj->f_ekeys = l12;
    _a41_obj->f_evals = l17;
    _a41_obj->f_index = l20;
    _a41_obj->f_mask = INT64_C(0);
    _a41_obj->f_grow_at = INT64_C(0);
    _a41_obj->f_size = INT64_C(0);
    _a41_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a41_obj;
    vader_struct_std_collections$MutableSet__string_t* _a42_obj = (vader_struct_std_collections$MutableSet__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__string_t));
    vader_obj_header_init(_a42_obj, 730u);
    _a42_obj->f_inner = t0;
    l12 = (void*) _a42_obj;
    vader_struct___lambda_env_vader_lower_dce_4_t* _a43_obj = (vader_struct___lambda_env_vader_lower_dce_4_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_lower_dce_4_t));
    vader_obj_header_init(_a43_obj, 542u);
    _a43_obj->f_cap_0 = l3;
    _a43_obj->f_cap_1 = l5;
    _a43_obj->f_cap_2 = l6;
    _a43_obj->f_cap_3 = l2;
    _a43_obj->f_cap_4 = l4;
    t0 = (void*) _a43_obj;
    vader_fn_t* _a44_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a44_closure, 418u);
    _a44_closure->code = (void*) &vader_fn_lift___lambda_vader_lower_dce_3;
    _a44_closure->env = t0;
    l2 = (void*) _a44_closure;
    vader_struct___lambda_env_vader_lower_dce_6_t* _a45_obj = (vader_struct___lambda_env_vader_lower_dce_6_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_lower_dce_6_t));
    vader_obj_header_init(_a45_obj, 543u);
    _a45_obj->f_cap_0 = l12;
    _a45_obj->f_cap_1 = l11;
    t0 = (void*) _a45_obj;
    vader_fn_t* _a46_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a46_closure, 415u);
    _a46_closure->code = (void*) &vader_fn_lift___lambda_vader_lower_dce_5;
    _a46_closure->env = t0;
    l12 = (void*) _a46_closure;
    vader_struct___lambda_env_vader_lower_dce_8_t* _a47_obj = (vader_struct___lambda_env_vader_lower_dce_8_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_lower_dce_8_t));
    vader_obj_header_init(_a47_obj, 544u);
    _a47_obj->f_cap_0 = l8;
    t0 = (void*) _a47_obj;
    vader_fn_t* _a48_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a48_closure, 440u);
    _a48_closure->code = (void*) &vader_fn_lift___lambda_vader_lower_dce_7;
    _a48_closure->env = t0;
    l8 = (void*) _a48_closure;
    l17 = std_collections$values__i32__vader_lower_ir_LoweredArrayLen___vader_lower_ir_LoweredArrayLit___vader_lower_ir_LoweredArrayPush___vader_lower_ir_LoweredArraySlice___vader_lower_ir_LoweredBinary___vader_lower_ir_LoweredBlock___vader_lower_ir_LoweredBoolLit___vader_lower_ir_LoweredCall___vader_lower_ir_LoweredCast___vader_lower_ir_LoweredCellGet___vader_lower_ir_LoweredCellNew___vader_lower_ir_LoweredCharLit___vader_lower_ir_LoweredDataConst___vader_lower_ir_LoweredFieldAccess___vader_lower_ir_LoweredFloatLit___vader_lower_ir_LoweredGlobalGet___vader_lower_ir_LoweredIdent___vader_lower_ir_LoweredIf___vader_lower_ir_LoweredIndex___vader_lower_ir_LoweredIntLit___vader_lower_ir_LoweredIntrinsicCall___vader_lower_ir_LoweredMakeClosure___vader_lower_ir_LoweredNullLit___vader_lower_ir_LoweredStringLit___vader_lower_ir_LoweredStructLit___vader_lower_ir_LoweredTypeCheck___vader_lower_ir_LoweredTypeConst___vader_lower_ir_LoweredUnary___vader_lower_ir_LoweredUnionField___vader_lower_ir_LoweredUnreachable___vader_lower_ir_LoweredVirtualCall(((vader_struct_vader_lower_ir$LoweredProject_t*) l0)->f_const_inline);
    l13 = ((vader_array_t*) l17)->length;
    l14 = INT64_C(0);
    while ((l14 < l13)) {
        vader_array_t* _a49_slotarr = ((vader_array_t*) l17);
        VADER_ARRAY_RESOLVE_BUF(_a49_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a49_slotarr, l14)
        t1 = vader_array_ref_load_box(_a49_slotarr->buf, _a49_slotarr->offset + (size_t) l14);
        vader_lower_ir$for_each_lowered_ref_in_expr(t1, l2, l12, l8);
        l14 = (l14 + INT64_C(1));
    }
    l17 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l0)->f_data_pool;
    l13 = ((vader_array_t*) l17)->length;
    l14 = INT64_C(0);
    while ((l14 < l13)) {
        vader_array_t* _a50_slotarr = ((vader_array_t*) l17);
        VADER_ARRAY_RESOLVE_BUF(_a50_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a50_slotarr, l14)
        l23 = vader_array_ref_load_box(_a50_slotarr->buf, _a50_slotarr->offset + (size_t) l14);
        if (l23.tag == 1360u) {
            t0 = l23.payload.obj;
            vader_lower_ir$for_each_lowered_ref_in_expr(vader_ref_box(((vader_struct_vader_lower_ir$AggregateDataPoolEntry_t*) t0)->f_literal), l2, l12, l8);
        }
        l14 = (l14 + INT64_C(1));
    }
    l13 = INT64_C(0);
    for (;;) {
        for (;;) {
            l14 = ((vader_array_t*) l6)->length;
            if ((l13 < l14)) {
                vader_array_t* _a51_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a51_slotarr)
                l23 = vader_array_ref_load_box(_a51_slotarr->buf, _a51_slotarr->offset + (size_t) l13);
                l13 = vader_chk_add(i64, l13, INT64_C(1));
                vader_lower_ir$for_each_lowered_ref(l23, l2, l12, l8);
                continue;
            }
            break;
        }
        l21 = ((vader_array_t*) l6)->length;
        l17 = l11;
        l22 = ((vader_array_t*) l17)->length;
        l31 = INT64_C(0);
        while ((l31 < l22)) {
            vader_array_t* _a52_slotarr = ((vader_array_t*) l17);
            VADER_ARRAY_RESOLVE_BUF(_a52_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a52_slotarr, l31)
            t1 = vader_array_box_slots(_a52_slotarr->buf)[_a52_slotarr->offset + (size_t) l31];
            l15 = t1.payload.s;
            l24 = std_collections$MutableMap$std_core$Index$at__string__Any(l9, l15);
            if (!(l24.tag == 0u)) {
                l20 = l24.payload.obj;
                l32 = ((vader_array_t*) l20)->length;
                l35 = INT64_C(0);
                while ((l35 < l32)) {
                    vader_array_t* _a53_slotarr = ((vader_array_t*) l20);
                    VADER_ARRAY_RESOLVE_BUF(_a53_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a53_slotarr, l35)
                    l26 = vader_array_ref_load_obj(_a53_slotarr->buf, _a53_slotarr->offset + (size_t) l35);
                    t2 = vader_lower_dce$receiver_is_built(((vader_struct_vader_lower_ir$LoweredVtableEntry_t*) l26)->f_struct_type, l7);
                    if (t2) {
                        l25 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$LoweredVtableEntry_t*) l26)->f_fn_symbol)->f_id;
                        l16 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$LoweredVtableEntry_t*) l26)->f_fn_symbol)->f_name;
                        vader_fn_t* _a54_fnobj = (vader_fn_t*) l2;
                        ((vader_fn_erased_sig_2_t) _a54_fnobj->code)(_a54_fnobj->env, vader_box_i32(450u, l25), vader_box_string(447u, l16));
                    }
                    l35 = (l35 + INT64_C(1));
                }
            }
            l31 = (l31 + INT64_C(1));
        }
        t3 = ((vader_array_t*) l6)->length;
        if (t3 == l21) break;
        continue;
    }
    vader_array_t* _a55_arr = vader_array_new(22u, 0u, 0u, 447u);
    l2 = (void*) _a55_arr;
    vader_array_t* _a56_arr = vader_array_new(29u, 0u, 0u, 458u);
    l6 = (void*) _a56_arr;
    vader_array_t* _a57_arr = vader_array_new(23u, 0u, 7u, 450u);
    l7 = (void*) _a57_arr;
    vader_struct_std_collections$MutableMap__string__Any_t* _a58_obj = (vader_struct_std_collections$MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__Any_t));
    vader_obj_header_init(_a58_obj, 656u);
    _a58_obj->f_ekeys = l2;
    _a58_obj->f_evals = l6;
    _a58_obj->f_index = l7;
    _a58_obj->f_mask = INT64_C(0);
    _a58_obj->f_grow_at = INT64_C(0);
    _a58_obj->f_size = INT64_C(0);
    _a58_obj->f_tombs = INT64_C(0);
    l2 = (void*) _a58_obj;
    l6 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l0)->f_modules;
    l7 = ((vader_struct_std_collections$MutableMap__string__vader_lower_ir_LoweredModule_t*) l6)->f_ekeys;
    l8 = ((vader_struct_std_collections$MutableMap__string__vader_lower_ir_LoweredModule_t*) l6)->f_evals;
    l13 = INT64_C(0);
    l14 = ((vader_struct_std_collections$MutableMap__string__vader_lower_ir_LoweredModule_t*) l6)->f_size;
    while ((l13 < l14)) {
        vader_array_t* _a59_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a59_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a59_slotarr, l13)
        t1 = vader_array_box_slots(_a59_slotarr->buf)[_a59_slotarr->offset + (size_t) l13];
        l15 = t1.payload.s;
        vader_array_t* _a60_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a60_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a60_slotarr, l13)
        l6 = vader_array_ref_load_obj(_a60_slotarr->buf, _a60_slotarr->offset + (size_t) l13);
        l16 = l15;
        l9 = l6;
        vader_array_t* _a61_arr = vader_array_new(377u, 0u, 13u, 2198u);
        l11 = (void*) _a61_arr;
        l12 = ((vader_struct_vader_lower_ir$LoweredModule_t*) l9)->f_decls;
        l21 = ((vader_array_t*) l12)->length;
        l22 = INT64_C(0);
        while ((l22 < l21)) {
            vader_array_t* _a62_slotarr = ((vader_array_t*) l12);
            VADER_ARRAY_RESOLVE_BUF(_a62_slotarr)
            l23 = vader_array_ref_load_box(_a62_slotarr->buf, _a62_slotarr->offset + (size_t) l22);
            t2 = vader_lower_dce$fn_survives(l23, l4, l5);
            if (t2) {
                vader_array_push_ref((vader_array_t*) l11, l23.payload.obj);
            }
            l22 = (l22 + INT64_C(1));
        }
        l18 = ((vader_struct_vader_lower_ir$LoweredModule_t*) l9)->f_module_id;
        l27 = ((vader_struct_vader_lower_ir$LoweredModule_t*) l9)->f_display_path;
        vader_struct_vader_lower_ir$LoweredModule_t* _a63_obj = (vader_struct_vader_lower_ir$LoweredModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_lower_ir$LoweredModule_t));
        vader_obj_header_init(_a63_obj, 1402u);
        _a63_obj->f_module_id = l18;
        _a63_obj->f_display_path = l27;
        _a63_obj->f_decls = l11;
        l17 = (void*) _a63_obj;
        std_collections$MutableMap$std_core$IndexSet$set_at__string__Any(l2, l16, vader_ref_box(l17));
        l13 = (l13 + INT64_C(1));
    }
    vader_array_t* _a64_arr = vader_array_new(305u, 0u, 13u, 1418u);
    l6 = (void*) _a64_arr;
    l7 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l0)->f_vtable_entries;
    l13 = ((vader_array_t*) l7)->length;
    l14 = INT64_C(0);
    while ((l14 < l13)) {
        vader_array_t* _a65_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a65_slotarr)
        l8 = vader_array_ref_load_obj(_a65_slotarr->buf, _a65_slotarr->offset + (size_t) l14);
        t2 = vader_lower_dce$entry_survives(l8, l3, l4, l5);
        if (t2) {
            vader_array_push_ref((vader_array_t*) l6, l8);
        }
        l14 = (l14 + INT64_C(1));
    }
    l3 = l0;
    l15 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l3)->f_entry;
    l4 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l3)->f_data_pool;
    l5 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l3)->f_globals;
    l7 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l3)->f_libraries;
    l8 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l3)->f_const_fn_wrap;
    l9 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l3)->f_const_inline;
    l11 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l3)->f_const_fresh_wrap;
    l12 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l3)->f_const_routes;
    l17 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l3)->f_identity_compared;
    l3 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l3)->f_trait_membership;
    vader_struct_vader_lower_ir$LoweredProject_t* _a66_obj = (vader_struct_vader_lower_ir$LoweredProject_t*) vader_gc_alloc(sizeof(vader_struct_vader_lower_ir$LoweredProject_t));
    vader_obj_header_init(_a66_obj, 1405u);
    _a66_obj->f_modules = l2;
    _a66_obj->f_entry = l15;
    _a66_obj->f_vtable_entries = l6;
    _a66_obj->f_data_pool = l4;
    _a66_obj->f_globals = l5;
    _a66_obj->f_libraries = l7;
    _a66_obj->f_const_fn_wrap = l8;
    _a66_obj->f_const_inline = l9;
    _a66_obj->f_const_fresh_wrap = l11;
    _a66_obj->f_const_routes = l12;
    _a66_obj->f_identity_compared = l17;
    _a66_obj->f_trait_membership = l3;
    t0 = (void*) _a66_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_lower_dce$receiver_is_built(vader_box_t l0, void* l1) {
    void* l2;
    vader_box_t l3;
    int32_t l4;
    bool t0;
    l3 = vader_core_types$struct_backing(l0);
    if (l3.tag == 0u) {
        return true;
    }
    l2 = l3.payload.obj;
    l4 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$StructType_t*) l2)->f_symbol)->f_id;
    t0 = std_collections$MutableSet$std_core$Contains$contains__i32(l1, l4);
    return t0;
}
