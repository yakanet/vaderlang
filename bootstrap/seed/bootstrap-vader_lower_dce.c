#include "bootstrap.split.h"

static bool vader_lower_dce$entry_survives(void* l0, void* l1, void* l2, void* l3);
static bool vader_lower_dce$fn_survives(vader_box_t l0, void* l1, void* l2);
static bool vader_lower_dce$is_fn_root(void* l0, bool l1, bool l2, bool l3, void* l4);
static void vader_lower_dce$mark_reachable(void* l0, void* l1, void* l2);
static bool vader_lower_dce$project_has_main(void* l0);
static bool vader_lower_dce$receiver_is_built(vader_box_t l0, void* l1);

static bool vader_lower_dce$entry_survives(void* l0, void* l1, void* l2, void* l3) {
    vader_string_t l4;
    int32_t l5;
    vader_box_t t0;
    bool t1;
    l4 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$LoweredVtableEntry_t*) l0)->f_fn_symbol)->f_name;
    t0 = std_collections$Map$std_core$Index$at__string__Any(l1, l4);
    if (!(t0.tag == 0u)) {
        l4 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$LoweredVtableEntry_t*) l0)->f_fn_symbol)->f_name;
        t1 = std_collections$Set$std_core$Contains$contains__string(l3, l4);
        return t1;
    }
    l5 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$LoweredVtableEntry_t*) l0)->f_fn_symbol)->f_id;
    t1 = std_collections$Set$std_core$Contains$contains__i32(l2, l5);
    return t1;
}

static bool vader_lower_dce$fn_survives(vader_box_t l0, void* l1, void* l2) {
    vader_box_t l3;
    int32_t l4;
    vader_string_t l5;
    void* t0;
    bool t1;
    if (!(l0.tag == 1606u)) {
        return true;
    }
    t0 = l0.payload.obj;
    l3 = ((vader_struct_vader_core_mono$MonoEntry_t*) ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) t0)->f_origin)->f_symbol;
    if (!(l3.tag == 1213u)) {
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) t0)->f_mangled;
        t1 = std_collections$Set$std_core$Contains$contains__string(l2, l5);
        return t1;
    }
    t0 = l3.payload.obj;
    l4 = ((vader_struct_vader_core_symbol$Symbol_t*) t0)->f_id;
    t1 = std_collections$Set$std_core$Contains$contains__i32(l1, l4);
    return t1;
}

static bool vader_lower_dce$is_fn_root(void* l0, bool l1, bool l2, bool l3, void* l4) {
    vader_box_t l5;
    int64_t l6, l8;
    void* l7;
    void* l9;
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
    l5 = ((vader_struct_vader_core_mono$MonoEntry_t*) ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) l0)->f_origin)->f_decl;
    if (l5.tag == 943u) {
        t1 = l5.payload.obj;
        l6 = ((vader_struct_toolchain_ast$FnDecl_t*) t1)->f_id;
        t0 = std_core$$array$Contains$contains__i64(l4, l6);
        if (t0) {
            return true;
        }
        t1 = l5.payload.obj;
        l7 = ((vader_struct_toolchain_ast$FnDecl_t*) t1)->f_decorators;
        l6 = vader_array_length(((vader_array_t*) l7));
        l8 = INT64_C(0);
        while ((l8 < l6)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            l9 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l8);
            t2 = ((vader_struct_toolchain_ast$Decorator_t*) l9)->f_name;
            if (t2 == 2226u) {
                return true;
            }
            if (l3) {
                t2 = ((vader_struct_toolchain_ast$Decorator_t*) l9)->f_name;
                if (t2 == 3053u) {
                    return true;
                }
            }
            l8 = (l8 + INT64_C(1));
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
    if (l3.tag == 1213u) {
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
    void* l9;
    int64_t l4, l5, l6, l7;
    vader_box_t l8;
    vader_box_t t0;
    vader_string_t t1;
    void* t2;
    bool t3;
    l1 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l0)->f_modules;
    l2 = ((vader_struct_std_collections$Map__string__vader_lower_ir_LoweredModule_t*) l1)->f_ekeys;
    l3 = ((vader_struct_std_collections$Map__string__vader_lower_ir_LoweredModule_t*) l1)->f_evals;
    l4 = INT64_C(0);
    l5 = ((vader_struct_std_collections$Map__string__vader_lower_ir_LoweredModule_t*) l1)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t0 = vader_array_box_slots(_a0_slotarr->buf)[vader_array_offset(_a0_slotarr) + (size_t) l4];
        t1 = t0.payload.s;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        t2 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l4);
        l1 = ((vader_struct_vader_lower_ir$LoweredModule_t*) t2)->f_decls;
        l6 = vader_array_length(((vader_array_t*) l1));
        l7 = INT64_C(0);
        while ((l7 < l6)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            l8 = vader_array_ref_load_box(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l7);
            if (l8.tag == 1606u) {
                l9 = l8.payload.obj;
                if (!(((vader_struct_vader_lower_ir$LoweredFnDecl_t*) l9)->f_body.tag == 0u)) {
                    t3 = ((vader_struct_vader_core_mono$MonoEntry_t*) ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) l9)->f_origin)->f_is_main;
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

void* vader_lower_dce$prune_unreachable_fns(void* l0, bool l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l18 = NULL;
    void* l21 = NULL;
    void* l27 = NULL;
    void* l29 = NULL;
    void* l30 = NULL;
    void* l31 = NULL;
    void* l34 = NULL;
    bool l11, l20;
    int64_t l14, l15, l22, l23, l32, l33, l36;
    vader_string_t l16 = 0;
    vader_string_t l17 = 0;
    vader_string_t l19 = 0;
    vader_string_t l28 = 0;
    vader_box_t l24 = vader_box_null(), l25 = vader_box_null();
    int32_t l26, l35;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    bool t2;
    int64_t t3;
    vader_box_t* gc_roots[3] = { &l24, &l25, &t1 };
    void** gc_raw_roots[20] = {
        &l0, &l2, &l3, &l4, &l5, &l6, &l7, &l8, &l9, &l10, &l12, &l13, &l18, &l21, &l27, &l29, &l30,
        &l31, &l34, &t0,
    };
    vader_string_t* gc_atom_roots[4] = { &l16, &l17, &l19, &l28 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 20u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(27u, 0u, 7u, 510u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(33u, 0u, 0u, 518u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(27u, 0u, 7u, 510u);
    l5 = (void*) _a2_arr;
    vader_struct_std_collections$Map__i32__Any_t* _a3_obj = (vader_struct_std_collections$Map__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__Any_t));
    vader_obj_header_init(_a3_obj, 721u);
    _a3_obj->f_ekeys = l3;
    _a3_obj->f_evals = l4;
    _a3_obj->f_index = l5;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l3 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(26u, 0u, 0u, 507u);
    l4 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(33u, 0u, 0u, 518u);
    l5 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(27u, 0u, 7u, 510u);
    l6 = (void*) _a6_arr;
    vader_struct_std_collections$Map__string__Any_t* _a7_obj = (vader_struct_std_collections$Map__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any_t));
    vader_obj_header_init(_a7_obj, 801u);
    _a7_obj->f_ekeys = l4;
    _a7_obj->f_evals = l5;
    _a7_obj->f_index = l6;
    _a7_obj->f_mask = INT64_C(0);
    _a7_obj->f_grow_at = INT64_C(0);
    _a7_obj->f_size = INT64_C(0);
    _a7_obj->f_tombs = INT64_C(0);
    l4 = (void*) _a7_obj;
    vader_array_t* _a8_arr = vader_array_new(27u, 0u, 7u, 510u);
    l5 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(24u, 0u, 12u, 505u);
    l6 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(27u, 0u, 7u, 510u);
    l7 = (void*) _a10_arr;
    vader_struct_std_collections$Map__i32__bool_t* _a11_obj = (vader_struct_std_collections$Map__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__bool_t));
    vader_obj_header_init(_a11_obj, 724u);
    _a11_obj->f_ekeys = l5;
    _a11_obj->f_evals = l6;
    _a11_obj->f_index = l7;
    _a11_obj->f_mask = INT64_C(0);
    _a11_obj->f_grow_at = INT64_C(0);
    _a11_obj->f_size = INT64_C(0);
    _a11_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a11_obj;
    vader_struct_std_collections$Set__i32_t* _a12_obj = (vader_struct_std_collections$Set__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__i32_t));
    vader_obj_header_init(_a12_obj, 889u);
    _a12_obj->f_inner = t0;
    l5 = (void*) _a12_obj;
    vader_array_t* _a13_arr = vader_array_new(26u, 0u, 0u, 507u);
    l6 = (void*) _a13_arr;
    vader_array_t* _a14_arr = vader_array_new(24u, 0u, 12u, 505u);
    l7 = (void*) _a14_arr;
    vader_array_t* _a15_arr = vader_array_new(27u, 0u, 7u, 510u);
    l8 = (void*) _a15_arr;
    vader_struct_std_collections$Map__string__bool_t* _a16_obj = (vader_struct_std_collections$Map__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__bool_t));
    vader_obj_header_init(_a16_obj, 807u);
    _a16_obj->f_ekeys = l6;
    _a16_obj->f_evals = l7;
    _a16_obj->f_index = l8;
    _a16_obj->f_mask = INT64_C(0);
    _a16_obj->f_grow_at = INT64_C(0);
    _a16_obj->f_size = INT64_C(0);
    _a16_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a16_obj;
    vader_struct_std_collections$Set__string_t* _a17_obj = (vader_struct_std_collections$Set__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__string_t));
    vader_obj_header_init(_a17_obj, 891u);
    _a17_obj->f_inner = t0;
    l6 = (void*) _a17_obj;
    vader_array_t* _a18_arr = vader_array_new(421u, 0u, 13u, 2487u);
    l7 = (void*) _a18_arr;
    vader_array_t* _a19_arr = vader_array_new(27u, 0u, 7u, 510u);
    l8 = (void*) _a19_arr;
    vader_array_t* _a20_arr = vader_array_new(24u, 0u, 12u, 505u);
    l9 = (void*) _a20_arr;
    vader_array_t* _a21_arr = vader_array_new(27u, 0u, 7u, 510u);
    l10 = (void*) _a21_arr;
    vader_struct_std_collections$Map__i32__bool_t* _a22_obj = (vader_struct_std_collections$Map__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__bool_t));
    vader_obj_header_init(_a22_obj, 724u);
    _a22_obj->f_ekeys = l8;
    _a22_obj->f_evals = l9;
    _a22_obj->f_index = l10;
    _a22_obj->f_mask = INT64_C(0);
    _a22_obj->f_grow_at = INT64_C(0);
    _a22_obj->f_size = INT64_C(0);
    _a22_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a22_obj;
    vader_struct_std_collections$Set__i32_t* _a23_obj = (vader_struct_std_collections$Set__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__i32_t));
    vader_obj_header_init(_a23_obj, 889u);
    _a23_obj->f_inner = t0;
    l8 = (void*) _a23_obj;
    vader_struct___lambda_env_vader_lower_dce_1_t* _a24_obj = (vader_struct___lambda_env_vader_lower_dce_1_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_lower_dce_1_t));
    vader_obj_header_init(_a24_obj, 672u);
    _a24_obj->f_cap_0 = l8;
    t0 = (void*) _a24_obj;
    vader_fn_t* _a25_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a25_closure, 500u);
    _a25_closure->code = (void*) &vader_fn_lift___lambda_vader_lower_dce_0;
    _a25_closure->env = t0;
    l9 = (void*) _a25_closure;
    l11 = vader_lower_dce$project_has_main(l0);
    l10 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l0)->f_modules;
    l12 = ((vader_struct_std_collections$Map__string__vader_lower_ir_LoweredModule_t*) l10)->f_ekeys;
    l13 = ((vader_struct_std_collections$Map__string__vader_lower_ir_LoweredModule_t*) l10)->f_evals;
    l14 = INT64_C(0);
    l15 = ((vader_struct_std_collections$Map__string__vader_lower_ir_LoweredModule_t*) l10)->f_size;
    while ((l14 < l15)) {
        vader_array_t* _a26_slotarr = ((vader_array_t*) l12);
        VADER_ARRAY_RESOLVE_BUF(_a26_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a26_slotarr, l14)
        t1 = vader_array_box_slots(_a26_slotarr->buf)[vader_array_offset(_a26_slotarr) + (size_t) l14];
        l16 = t1.payload.s;
        vader_array_t* _a27_slotarr = ((vader_array_t*) l13);
        VADER_ARRAY_RESOLVE_BUF(_a27_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a27_slotarr, l14)
        l10 = vader_array_ref_load_obj(_a27_slotarr->buf, vader_array_offset(_a27_slotarr) + (size_t) l14);
        l17 = l16;
        l18 = l10;
        l19 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l0)->f_entry;
        l20 = l17 == l19;
        l21 = ((vader_struct_vader_lower_ir$LoweredModule_t*) l18)->f_decls;
        l22 = vader_array_length(((vader_array_t*) l21));
        l23 = INT64_C(0);
        while ((l23 < l22)) {
            vader_array_t* _a28_slotarr = ((vader_array_t*) l21);
            VADER_ARRAY_RESOLVE_BUF(_a28_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a28_slotarr, l23)
            l24 = vader_array_ref_load_box(_a28_slotarr->buf, vader_array_offset(_a28_slotarr) + (size_t) l23);
            if (l24.tag == 1606u) {
                t0 = l24.payload.obj;
                l25 = ((vader_struct_vader_core_mono$MonoEntry_t*) ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) t0)->f_origin)->f_symbol;
                if (l25.tag == 1213u) {
                    t0 = l25.payload.obj;
                    l26 = ((vader_struct_vader_core_symbol$Symbol_t*) t0)->f_id;
                    l27 = l24.payload.obj;
                    std_collections$Map$std_core$IndexSet$set_at__i32__Any(l3, l26, vader_ref_box(l27));
                } else {
                    t0 = l24.payload.obj;
                    l28 = ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) t0)->f_mangled;
                    l29 = l24.payload.obj;
                    std_collections$Map$std_core$IndexSet$set_at__string__Any(l4, l28, vader_ref_box(l29));
                }
                t0 = l24.payload.obj;
                t2 = vader_lower_dce$is_fn_root(t0, l20, l11, l1, l2);
                if (t2) {
                    t0 = l24.payload.obj;
                    vader_lower_dce$mark_reachable(t0, l5, l6);
                    l30 = l24.payload.obj;
                    vader_array_push_ref((vader_array_t*) l7, l30);
                    t0 = l24.payload.obj;
                    if (!(((vader_struct_vader_lower_ir$LoweredFnDecl_t*) t0)->f_body.tag == 0u)) {
                        t0 = l24.payload.obj;
                        l31 = ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) t0)->f_params;
                        l32 = vader_array_length(((vader_array_t*) l31));
                        l33 = INT64_C(0);
                        while ((l33 < l32)) {
                            vader_array_t* _a29_slotarr = ((vader_array_t*) l31);
                            VADER_ARRAY_RESOLVE_BUF(_a29_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a29_slotarr, l33)
                            t0 = vader_array_ref_load_obj(_a29_slotarr->buf, vader_array_offset(_a29_slotarr) + (size_t) l33);
                            vader_core_types$for_each_type(((vader_struct_vader_lower_ir$LoweredParam_t*) t0)->f_type, l9);
                            l33 = (l33 + INT64_C(1));
                        }
                    }
                }
            } else if (l24.tag == 1598u) {
                l34 = l24.payload.obj;
                vader_array_push_ref((vader_array_t*) l7, l34);
            }
            l23 = (l23 + INT64_C(1));
        }
        l14 = (l14 + INT64_C(1));
    }
    l10 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l0)->f_const_fn_wrap;
    l12 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l0)->f_const_fresh_wrap;
    l13 = ((vader_struct_std_collections$Map__i32__vader_lower_ir_ConstFnWrap_t*) l10)->f_evals;
    l14 = INT64_C(0);
    l15 = ((vader_struct_std_collections$Map__i32__vader_lower_ir_ConstFnWrap_t*) l10)->f_size;
    while ((l14 < l15)) {
        vader_array_t* _a30_slotarr = ((vader_array_t*) l13);
        VADER_ARRAY_RESOLVE_BUF(_a30_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a30_slotarr, l14)
        l10 = vader_array_ref_load_obj(_a30_slotarr->buf, vader_array_offset(_a30_slotarr) + (size_t) l14);
        l26 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$ConstFnWrap_t*) l10)->f_fn_symbol)->f_id;
        l24 = std_collections$Map$std_core$Index$at__i32__Any(l3, l26);
        if (!(l24.tag == 0u)) {
            l35 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$ConstFnWrap_t*) l10)->f_fn_symbol)->f_id;
            t2 = std_collections$add__i32(l5, l35);
            if (t2) {
                l25 = l24;
                vader_array_push_ref((vader_array_t*) l7, l25.payload.obj);
            }
        }
        l14 = (l14 + INT64_C(1));
    }
    l10 = ((vader_struct_std_collections$Map__i32__vader_lower_ir_ConstFnWrap_t*) l12)->f_evals;
    l14 = INT64_C(0);
    l15 = ((vader_struct_std_collections$Map__i32__vader_lower_ir_ConstFnWrap_t*) l12)->f_size;
    while ((l14 < l15)) {
        vader_array_t* _a31_slotarr = ((vader_array_t*) l10);
        VADER_ARRAY_RESOLVE_BUF(_a31_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a31_slotarr, l14)
        l12 = vader_array_ref_load_obj(_a31_slotarr->buf, vader_array_offset(_a31_slotarr) + (size_t) l14);
        l26 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$ConstFnWrap_t*) l12)->f_fn_symbol)->f_id;
        l24 = std_collections$Map$std_core$Index$at__i32__Any(l3, l26);
        if (!(l24.tag == 0u)) {
            l35 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$ConstFnWrap_t*) l12)->f_fn_symbol)->f_id;
            t2 = std_collections$add__i32(l5, l35);
            if (t2) {
                l25 = l24;
                vader_array_push_ref((vader_array_t*) l7, l25.payload.obj);
            }
        }
        l14 = (l14 + INT64_C(1));
    }
    vader_array_t* _a32_arr = vader_array_new(26u, 0u, 0u, 507u);
    l10 = (void*) _a32_arr;
    vader_array_t* _a33_arr = vader_array_new(33u, 0u, 0u, 518u);
    l12 = (void*) _a33_arr;
    vader_array_t* _a34_arr = vader_array_new(27u, 0u, 7u, 510u);
    l13 = (void*) _a34_arr;
    vader_struct_std_collections$Map__string__Any___t* _a35_obj = (vader_struct_std_collections$Map__string__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any___t));
    vader_obj_header_init(_a35_obj, 802u);
    _a35_obj->f_ekeys = l10;
    _a35_obj->f_evals = l12;
    _a35_obj->f_index = l13;
    _a35_obj->f_mask = INT64_C(0);
    _a35_obj->f_grow_at = INT64_C(0);
    _a35_obj->f_size = INT64_C(0);
    _a35_obj->f_tombs = INT64_C(0);
    l10 = (void*) _a35_obj;
    l12 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l0)->f_vtable_entries;
    l14 = vader_array_length(((vader_array_t*) l12));
    l15 = INT64_C(0);
    while ((l15 < l14)) {
        vader_array_t* _a36_slotarr = ((vader_array_t*) l12);
        VADER_ARRAY_RESOLVE_BUF(_a36_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a36_slotarr, l15)
        l13 = vader_array_ref_load_obj(_a36_slotarr->buf, vader_array_offset(_a36_slotarr) + (size_t) l15);
        l16 = ((vader_struct_vader_lower_ir$LoweredVtableEntry_t*) l13)->f_trait_name;
        l17 = ((vader_struct_vader_lower_ir$LoweredVtableEntry_t*) l13)->f_method_name;
        l19 = concat_3(l16, 3478u, l17);
        l18 = (void*) &vader_fn_static___lambda_vader_lower_dce_2;
        t0 = std_collections$get_or_put_with__string__vader_lower_ir_LoweredVtableEntry__(l10, l19, l18);
        vader_array_push_ref((vader_array_t*) t0, l13);
        l15 = (l15 + INT64_C(1));
    }
    vader_array_t* _a37_arr = vader_array_new(26u, 0u, 0u, 507u);
    l12 = (void*) _a37_arr;
    vader_array_t* _a38_arr = vader_array_new(26u, 0u, 0u, 507u);
    l13 = (void*) _a38_arr;
    vader_array_t* _a39_arr = vader_array_new(24u, 0u, 12u, 505u);
    l18 = (void*) _a39_arr;
    vader_array_t* _a40_arr = vader_array_new(27u, 0u, 7u, 510u);
    l21 = (void*) _a40_arr;
    vader_struct_std_collections$Map__string__bool_t* _a41_obj = (vader_struct_std_collections$Map__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__bool_t));
    vader_obj_header_init(_a41_obj, 807u);
    _a41_obj->f_ekeys = l13;
    _a41_obj->f_evals = l18;
    _a41_obj->f_index = l21;
    _a41_obj->f_mask = INT64_C(0);
    _a41_obj->f_grow_at = INT64_C(0);
    _a41_obj->f_size = INT64_C(0);
    _a41_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a41_obj;
    vader_struct_std_collections$Set__string_t* _a42_obj = (vader_struct_std_collections$Set__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__string_t));
    vader_obj_header_init(_a42_obj, 891u);
    _a42_obj->f_inner = t0;
    l13 = (void*) _a42_obj;
    vader_struct___lambda_env_vader_lower_dce_4_t* _a43_obj = (vader_struct___lambda_env_vader_lower_dce_4_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_lower_dce_4_t));
    vader_obj_header_init(_a43_obj, 673u);
    _a43_obj->f_cap_0 = l4;
    _a43_obj->f_cap_1 = l6;
    _a43_obj->f_cap_2 = l7;
    _a43_obj->f_cap_3 = l3;
    _a43_obj->f_cap_4 = l5;
    t0 = (void*) _a43_obj;
    vader_fn_t* _a44_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a44_closure, 470u);
    _a44_closure->code = (void*) &vader_fn_lift___lambda_vader_lower_dce_3;
    _a44_closure->env = t0;
    l3 = (void*) _a44_closure;
    vader_struct___lambda_env_vader_lower_dce_6_t* _a45_obj = (vader_struct___lambda_env_vader_lower_dce_6_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_lower_dce_6_t));
    vader_obj_header_init(_a45_obj, 674u);
    _a45_obj->f_cap_0 = l13;
    _a45_obj->f_cap_1 = l12;
    t0 = (void*) _a45_obj;
    vader_fn_t* _a46_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a46_closure, 467u);
    _a46_closure->code = (void*) &vader_fn_lift___lambda_vader_lower_dce_5;
    _a46_closure->env = t0;
    l13 = (void*) _a46_closure;
    vader_struct___lambda_env_vader_lower_dce_8_t* _a47_obj = (vader_struct___lambda_env_vader_lower_dce_8_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_lower_dce_8_t));
    vader_obj_header_init(_a47_obj, 675u);
    _a47_obj->f_cap_0 = l9;
    t0 = (void*) _a47_obj;
    vader_fn_t* _a48_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a48_closure, 500u);
    _a48_closure->code = (void*) &vader_fn_lift___lambda_vader_lower_dce_7;
    _a48_closure->env = t0;
    l9 = (void*) _a48_closure;
    l18 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l0)->f_const_inline;
    l21 = ((vader_struct_std_collections$Map__i32__vader_lower_ir_LoweredArrayLen___vader_lower_ir_LoweredArrayLit___vader_lower_ir_LoweredArrayPush___vader_lower_ir_LoweredArraySlice___vader_lower_ir_LoweredBinary___vader_lower_ir_LoweredBlock___vader_lower_ir_LoweredBoolLit___vader_lower_ir_LoweredCall___vader_lower_ir_LoweredCast___vader_lower_ir_LoweredCellGet___vader_lower_ir_LoweredCellNew___vader_lower_ir_LoweredCharLit___vader_lower_ir_LoweredDataConst___vader_lower_ir_LoweredFieldAccess___vader_lower_ir_LoweredFloatLit___vader_lower_ir_LoweredGlobalGet___vader_lower_ir_LoweredIdent___vader_lower_ir_LoweredIf___vader_lower_ir_LoweredIndex___vader_lower_ir_LoweredIntLit___vader_lower_ir_LoweredIntrinsicCall___vader_lower_ir_LoweredMakeClosure___vader_lower_ir_LoweredNullLit___vader_lower_ir_LoweredStringLit___vader_lower_ir_LoweredStructLit___vader_lower_ir_LoweredTypeCheck___vader_lower_ir_LoweredTypeConst___vader_lower_ir_LoweredUnary___vader_lower_ir_LoweredUnionField___vader_lower_ir_LoweredUnreachable___vader_lower_ir_LoweredVirtualCall_t*) l18)->f_evals;
    l14 = INT64_C(0);
    l15 = ((vader_struct_std_collections$Map__i32__vader_lower_ir_LoweredArrayLen___vader_lower_ir_LoweredArrayLit___vader_lower_ir_LoweredArrayPush___vader_lower_ir_LoweredArraySlice___vader_lower_ir_LoweredBinary___vader_lower_ir_LoweredBlock___vader_lower_ir_LoweredBoolLit___vader_lower_ir_LoweredCall___vader_lower_ir_LoweredCast___vader_lower_ir_LoweredCellGet___vader_lower_ir_LoweredCellNew___vader_lower_ir_LoweredCharLit___vader_lower_ir_LoweredDataConst___vader_lower_ir_LoweredFieldAccess___vader_lower_ir_LoweredFloatLit___vader_lower_ir_LoweredGlobalGet___vader_lower_ir_LoweredIdent___vader_lower_ir_LoweredIf___vader_lower_ir_LoweredIndex___vader_lower_ir_LoweredIntLit___vader_lower_ir_LoweredIntrinsicCall___vader_lower_ir_LoweredMakeClosure___vader_lower_ir_LoweredNullLit___vader_lower_ir_LoweredStringLit___vader_lower_ir_LoweredStructLit___vader_lower_ir_LoweredTypeCheck___vader_lower_ir_LoweredTypeConst___vader_lower_ir_LoweredUnary___vader_lower_ir_LoweredUnionField___vader_lower_ir_LoweredUnreachable___vader_lower_ir_LoweredVirtualCall_t*) l18)->f_size;
    while ((l14 < l15)) {
        vader_array_t* _a49_slotarr = ((vader_array_t*) l21);
        VADER_ARRAY_RESOLVE_BUF(_a49_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a49_slotarr, l14)
        t1 = vader_array_ref_load_box(_a49_slotarr->buf, vader_array_offset(_a49_slotarr) + (size_t) l14);
        vader_lower_ir$for_each_lowered_ref_in_expr(t1, l3, l13, l9);
        l14 = (l14 + INT64_C(1));
    }
    l18 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l0)->f_data_pool;
    l14 = vader_array_length(((vader_array_t*) l18));
    l15 = INT64_C(0);
    while ((l15 < l14)) {
        vader_array_t* _a50_slotarr = ((vader_array_t*) l18);
        VADER_ARRAY_RESOLVE_BUF(_a50_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a50_slotarr, l15)
        l24 = vader_array_ref_load_box(_a50_slotarr->buf, vader_array_offset(_a50_slotarr) + (size_t) l15);
        if (l24.tag == 1577u) {
            t0 = l24.payload.obj;
            vader_lower_ir$for_each_lowered_ref_in_expr(vader_ref_box(((vader_struct_vader_lower_ir$AggregateDataPoolEntry_t*) t0)->f_literal), l3, l13, l9);
        }
        l15 = (l15 + INT64_C(1));
    }
    l14 = INT64_C(0);
    for (;;) {
        for (;;) {
            l15 = vader_array_length(((vader_array_t*) l7));
            if ((l14 < l15)) {
                vader_array_t* _a51_slotarr = ((vader_array_t*) l7);
                VADER_ARRAY_RESOLVE_BUF(_a51_slotarr)
                l24 = vader_array_ref_load_box(_a51_slotarr->buf, vader_array_offset(_a51_slotarr) + (size_t) l14);
                l14 = vader_chk_add(i64, l14, INT64_C(1));
                vader_lower_ir$for_each_lowered_ref(l24, l3, l13, l9);
                continue;
            }
            break;
        }
        l22 = vader_array_length(((vader_array_t*) l7));
        l18 = l12;
        l23 = vader_array_length(((vader_array_t*) l18));
        l32 = INT64_C(0);
        while ((l32 < l23)) {
            vader_array_t* _a52_slotarr = ((vader_array_t*) l18);
            VADER_ARRAY_RESOLVE_BUF(_a52_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a52_slotarr, l32)
            t1 = vader_array_box_slots(_a52_slotarr->buf)[vader_array_offset(_a52_slotarr) + (size_t) l32];
            l16 = t1.payload.s;
            l25 = std_collections$Map$std_core$Index$at__string__Any(l10, l16);
            if (!(l25.tag == 0u)) {
                l21 = l25.payload.obj;
                l33 = vader_array_length(((vader_array_t*) l21));
                l36 = INT64_C(0);
                while ((l36 < l33)) {
                    vader_array_t* _a53_slotarr = ((vader_array_t*) l21);
                    VADER_ARRAY_RESOLVE_BUF(_a53_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a53_slotarr, l36)
                    l27 = vader_array_ref_load_obj(_a53_slotarr->buf, vader_array_offset(_a53_slotarr) + (size_t) l36);
                    t2 = vader_lower_dce$receiver_is_built(((vader_struct_vader_lower_ir$LoweredVtableEntry_t*) l27)->f_struct_type, l8);
                    if (t2) {
                        l26 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$LoweredVtableEntry_t*) l27)->f_fn_symbol)->f_id;
                        l17 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$LoweredVtableEntry_t*) l27)->f_fn_symbol)->f_name;
                        vader_fn_t* _a54_fnobj = (vader_fn_t*) l3;
                        ((vader_fn_erased_sig_2_t) _a54_fnobj->code)(_a54_fnobj->env, vader_box_i32(510u, l26), vader_box_string(507u, l17));
                    }
                    l36 = (l36 + INT64_C(1));
                }
            }
            l32 = (l32 + INT64_C(1));
        }
        t3 = vader_array_length(((vader_array_t*) l7));
        if (t3 == l22) break;
        continue;
    }
    vader_array_t* _a55_arr = vader_array_new(26u, 0u, 0u, 507u);
    l3 = (void*) _a55_arr;
    vader_array_t* _a56_arr = vader_array_new(33u, 0u, 0u, 518u);
    l7 = (void*) _a56_arr;
    vader_array_t* _a57_arr = vader_array_new(27u, 0u, 7u, 510u);
    l8 = (void*) _a57_arr;
    vader_struct_std_collections$Map__string__Any_t* _a58_obj = (vader_struct_std_collections$Map__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any_t));
    vader_obj_header_init(_a58_obj, 801u);
    _a58_obj->f_ekeys = l3;
    _a58_obj->f_evals = l7;
    _a58_obj->f_index = l8;
    _a58_obj->f_mask = INT64_C(0);
    _a58_obj->f_grow_at = INT64_C(0);
    _a58_obj->f_size = INT64_C(0);
    _a58_obj->f_tombs = INT64_C(0);
    l3 = (void*) _a58_obj;
    l7 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l0)->f_modules;
    l8 = ((vader_struct_std_collections$Map__string__vader_lower_ir_LoweredModule_t*) l7)->f_ekeys;
    l9 = ((vader_struct_std_collections$Map__string__vader_lower_ir_LoweredModule_t*) l7)->f_evals;
    l14 = INT64_C(0);
    l15 = ((vader_struct_std_collections$Map__string__vader_lower_ir_LoweredModule_t*) l7)->f_size;
    while ((l14 < l15)) {
        vader_array_t* _a59_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a59_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a59_slotarr, l14)
        t1 = vader_array_box_slots(_a59_slotarr->buf)[vader_array_offset(_a59_slotarr) + (size_t) l14];
        l16 = t1.payload.s;
        vader_array_t* _a60_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a60_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a60_slotarr, l14)
        l7 = vader_array_ref_load_obj(_a60_slotarr->buf, vader_array_offset(_a60_slotarr) + (size_t) l14);
        l17 = l16;
        l10 = l7;
        vader_array_t* _a61_arr = vader_array_new(421u, 0u, 13u, 2487u);
        l12 = (void*) _a61_arr;
        l13 = ((vader_struct_vader_lower_ir$LoweredModule_t*) l10)->f_decls;
        l22 = vader_array_length(((vader_array_t*) l13));
        l23 = INT64_C(0);
        while ((l23 < l22)) {
            vader_array_t* _a62_slotarr = ((vader_array_t*) l13);
            VADER_ARRAY_RESOLVE_BUF(_a62_slotarr)
            l24 = vader_array_ref_load_box(_a62_slotarr->buf, vader_array_offset(_a62_slotarr) + (size_t) l23);
            t2 = vader_lower_dce$fn_survives(l24, l5, l6);
            if (t2) {
                vader_array_push_ref((vader_array_t*) l12, l24.payload.obj);
            }
            l23 = (l23 + INT64_C(1));
        }
        l19 = ((vader_struct_vader_lower_ir$LoweredModule_t*) l10)->f_module_id;
        l28 = ((vader_struct_vader_lower_ir$LoweredModule_t*) l10)->f_display_path;
        vader_struct_vader_lower_ir$LoweredModule_t* _a63_obj = (vader_struct_vader_lower_ir$LoweredModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_lower_ir$LoweredModule_t));
        vader_obj_header_init(_a63_obj, 1618u);
        _a63_obj->f_module_id = l19;
        _a63_obj->f_display_path = l28;
        _a63_obj->f_decls = l12;
        l18 = (void*) _a63_obj;
        std_collections$Map$std_core$IndexSet$set_at__string__Any(l3, l17, vader_ref_box(l18));
        l14 = (l14 + INT64_C(1));
    }
    vader_array_t* _a64_arr = vader_array_new(346u, 0u, 13u, 1634u);
    l7 = (void*) _a64_arr;
    l8 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l0)->f_vtable_entries;
    l14 = vader_array_length(((vader_array_t*) l8));
    l15 = INT64_C(0);
    while ((l15 < l14)) {
        vader_array_t* _a65_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a65_slotarr)
        l9 = vader_array_ref_load_obj(_a65_slotarr->buf, vader_array_offset(_a65_slotarr) + (size_t) l15);
        t2 = vader_lower_dce$entry_survives(l9, l4, l5, l6);
        if (t2) {
            vader_array_push_ref((vader_array_t*) l7, l9);
        }
        l15 = (l15 + INT64_C(1));
    }
    l4 = l0;
    l16 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l4)->f_entry;
    l5 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l4)->f_data_pool;
    l6 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l4)->f_globals;
    l8 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l4)->f_libraries;
    l9 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l4)->f_const_fn_wrap;
    l10 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l4)->f_const_inline;
    l12 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l4)->f_const_fresh_wrap;
    l13 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l4)->f_const_routes;
    l18 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l4)->f_identity_compared;
    l4 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l4)->f_trait_membership;
    vader_struct_vader_lower_ir$LoweredProject_t* _a66_obj = (vader_struct_vader_lower_ir$LoweredProject_t*) vader_gc_alloc(sizeof(vader_struct_vader_lower_ir$LoweredProject_t));
    vader_obj_header_init(_a66_obj, 1621u);
    _a66_obj->f_modules = l3;
    _a66_obj->f_entry = l16;
    _a66_obj->f_vtable_entries = l7;
    _a66_obj->f_data_pool = l5;
    _a66_obj->f_globals = l6;
    _a66_obj->f_libraries = l8;
    _a66_obj->f_const_fn_wrap = l9;
    _a66_obj->f_const_inline = l10;
    _a66_obj->f_const_fresh_wrap = l12;
    _a66_obj->f_const_routes = l13;
    _a66_obj->f_identity_compared = l18;
    _a66_obj->f_trait_membership = l4;
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
    t0 = std_collections$Set$std_core$Contains$contains__i32(l1, l4);
    return t0;
}
