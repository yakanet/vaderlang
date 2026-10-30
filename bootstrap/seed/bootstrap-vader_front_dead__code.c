#include "bootstrap.split.h"

static void* vader_front_dead__code$bfs_reachable(void* l0, void* l1, void* l2);
static vader_box_t vader_front_dead__code$collect_decl_refs(vader_box_t l0, void* l1);
static void vader_front_dead__code$collect_names(vader_box_t l0, void* l1);
static bool vader_front_dead__code$is_comptime_helper(vader_box_t l0);
static bool vader_front_dead__code$is_public(uint8_t l0);
static bool vader_front_dead__code$is_root_decl(uint8_t l0, void* l1, vader_string_t l2, vader_string_t l3);
static bool vader_front_dead__code$is_wired_root(void* l0, vader_string_t l1);
static void* vader_front_dead__code$named_decl(vader_box_t l0, vader_string_t l1, void* l2, uint8_t l3, void* l4, bool l5);
static void vader_front_dead__code$register_refs(void* l0, vader_string_t l1, void* l2);

static void* vader_front_dead__code$bfs_reachable(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    int64_t l8, l9, l12, l13;
    vader_string_t l10 = 0;
    vader_string_t l14 = 0;
    vader_box_t l11 = vader_box_null();
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    bool t2;
    vader_box_t* gc_roots[2] = { &l11, &t1 };
    void** gc_raw_roots[9] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l10, &l14 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 0u, 447u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(20u, 0u, 12u, 445u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(23u, 0u, 7u, 450u);
    l5 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__string__bool_t* _a3_obj = (vader_struct_std_collections$MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__bool_t));
    vader_obj_header_init(_a3_obj, 662u);
    _a3_obj->f_ekeys = l3;
    _a3_obj->f_evals = l4;
    _a3_obj->f_index = l5;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections$MutableSet__string_t* _a4_obj = (vader_struct_std_collections$MutableSet__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__string_t));
    vader_obj_header_init(_a4_obj, 730u);
    _a4_obj->f_inner = t0;
    l3 = (void*) _a4_obj;
    l5 = l0;
    l6 = l1;
    vader_array_t* _a5_arr = vader_array_new(22u, 0u, 0u, 447u);
    l7 = (void*) _a5_arr;
    l8 = ((vader_array_t*) l5)->length;
    l9 = INT64_C(0);
    while ((l9 < l8)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        t1 = vader_array_box_slots(_a6_slotarr->buf)[_a6_slotarr->offset + (size_t) l9];
        l10 = t1.payload.s;
        vader_array_push_scalar((vader_array_t*) l7, vader_box_string(447u, l10));
        l9 = (l9 + INT64_C(1));
    }
    l8 = ((vader_array_t*) l6)->length;
    l9 = INT64_C(0);
    while ((l9 < l8)) {
        vader_array_t* _a7_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        t1 = vader_array_box_slots(_a7_slotarr->buf)[_a7_slotarr->offset + (size_t) l9];
        l10 = t1.payload.s;
        vader_array_push_scalar((vader_array_t*) l7, vader_box_string(447u, l10));
        l9 = (l9 + INT64_C(1));
    }
    l4 = l7;
    l8 = INT64_C(0);
    for (;;) {
        l9 = ((vader_array_t*) l4)->length;
        if ((l8 < l9)) {
            vader_array_t* _a8_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            t1 = vader_array_box_slots(_a8_slotarr->buf)[_a8_slotarr->offset + (size_t) l8];
            l10 = t1.payload.s;
            l8 = vader_chk_add(i64, l8, INT64_C(1));
            t2 = std_collections$add__string(l3, l10);
            if (!(t2)) {
                continue;
            }
            l11 = std_collections$MutableMap$std_core$Index$at__string__string__(l2, l10);
            if (l11.tag == 0u) {
                continue;
            }
            l5 = l11.payload.obj;
            l12 = ((vader_array_t*) l5)->length;
            l13 = INT64_C(0);
            while ((l13 < l12)) {
                vader_array_t* _a9_slotarr = ((vader_array_t*) l5);
                VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                t1 = vader_array_box_slots(_a9_slotarr->buf)[_a9_slotarr->offset + (size_t) l13];
                l14 = t1.payload.s;
                vader_array_push_scalar((vader_array_t*) l4, vader_box_string(447u, l14));
                l13 = (l13 + INT64_C(1));
            }
            continue;
        }
        break;
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

void vader_front_dead__code$check_dead_code(void* l0, vader_string_t l1, void* l2, void* l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l12 = NULL;
    void* l15 = NULL;
    void* l17 = NULL;
    void* l21 = NULL;
    void* l22 = NULL;
    int64_t l9, l10;
    vader_box_t l11 = vader_box_null(), l13 = vader_box_null();
    vader_string_t l14 = 0;
    vader_string_t l18 = 0;
    vader_string_t l19 = 0;
    vader_string_t l20 = 0;
    uint8_t l16;
    bool t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l11, &l13 };
    void** gc_raw_roots[14] = {
        &l0, &l2, &l3, &l4, &l5, &l6, &l7, &l8, &l12, &l15, &l17, &l21, &l22, &t1,
    };
    vader_string_t* gc_atom_roots[5] = { &l1, &l14, &l18, &l19, &l20 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 14u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 0u, 447u);
    l4 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(2u, 0u, 13u, 22u);
    l5 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(23u, 0u, 7u, 450u);
    l6 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__string__string___t* _a3_obj = (vader_struct_std_collections$MutableMap__string__string___t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__string___t));
    vader_obj_header_init(_a3_obj, 676u);
    _a3_obj->f_ekeys = l4;
    _a3_obj->f_evals = l5;
    _a3_obj->f_index = l6;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l4 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(22u, 0u, 0u, 447u);
    l5 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(22u, 0u, 0u, 447u);
    l6 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(214u, 0u, 13u, 1149u);
    l7 = (void*) _a6_arr;
    l8 = l0;
    l9 = ((vader_array_t*) l8)->length;
    l10 = INT64_C(0);
    while ((l10 < l9)) {
        vader_array_t* _a7_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l10)
        l11 = vader_array_ref_load_box(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l10);
        l13 = vader_front_dead__code$collect_decl_refs(l11, l6);
        if (l13.tag == 0u) {
            l10 = (l10 + INT64_C(1));
            continue;
        }
        l12 = l13.payload.obj;
        l14 = ((vader_struct_vader_front_dead__code$NamedDeclRefs_t*) l12)->f_name;
        l15 = ((vader_struct_vader_front_dead__code$NamedDeclRefs_t*) l12)->f_refs;
        vader_front_dead__code$register_refs(l4, l14, l15);
        l16 = ((vader_struct_vader_front_dead__code$NamedDeclRefs_t*) l12)->f_visibility;
        l17 = ((vader_struct_vader_front_dead__code$NamedDeclRefs_t*) l12)->f_decorators;
        l18 = ((vader_struct_vader_front_dead__code$NamedDeclRefs_t*) l12)->f_name;
        t0 = vader_front_dead__code$is_root_decl(l16, l17, l18, l1);
        if (t0) {
            l19 = ((vader_struct_vader_front_dead__code$NamedDeclRefs_t*) l12)->f_name;
            vader_array_push_scalar((vader_array_t*) l5, vader_box_string(447u, l19));
        } else {
            t0 = vader_front_dead__code$is_comptime_helper(l11);
            if (!(t0)) {
                l20 = ((vader_struct_vader_front_dead__code$NamedDeclRefs_t*) l12)->f_name;
                l21 = ((vader_struct_vader_front_dead__code$NamedDeclRefs_t*) l12)->f_name_span;
                vader_struct_vader_front_dead__code$DeadDecl_t* _a8_obj = (vader_struct_vader_front_dead__code$DeadDecl_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_dead__code$DeadDecl_t));
                vader_obj_header_init(_a8_obj, 1149u);
                _a8_obj->f_name = l20;
                _a8_obj->f_name_span = l21;
                l22 = (void*) _a8_obj;
                vader_array_push_ref((vader_array_t*) l7, l22);
            }
        }
        l10 = (l10 + INT64_C(1));
    }
    l8 = l3;
    l9 = ((vader_array_t*) l8)->length;
    l10 = INT64_C(0);
    while ((l10 < l9)) {
        vader_array_t* _a9_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l10)
        t1 = vader_array_ref_load_obj(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l10);
        vader_front_dead__code$collect_names(vader_ref_box(t1), l6);
        l10 = (l10 + INT64_C(1));
    }
    l4 = vader_front_dead__code$bfs_reachable(l5, l6, l4);
    l5 = l7;
    l9 = ((vader_array_t*) l5)->length;
    l10 = INT64_C(0);
    while ((l10 < l9)) {
        vader_array_t* _a10_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        l6 = vader_array_ref_load_obj(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l10);
        l14 = ((vader_struct_vader_front_dead__code$DeadDecl_t*) l6)->f_name;
        t0 = std_collections$MutableSet$std_core$Contains$contains__string(l4, l14);
        if (!(t0)) {
            l7 = ((vader_struct_vader_front_dead__code$DeadDecl_t*) l6)->f_name_span;
            l18 = ((vader_struct_vader_front_dead__code$DeadDecl_t*) l6)->f_name;
            l19 = concat_3(1033u, l18, 1156u);
            l8 = vader_support_diagnostics$warning((uint8_t) 3, l7, l19);
            vader_array_push_ref((vader_array_t*) l2, l8);
        }
        l10 = (l10 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_front_dead__code$collect_decl_refs(vader_box_t l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    void* l5 = NULL;
    void* l7 = NULL;
    vader_string_t l4 = 0;
    uint8_t l6;
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l0, &l2 };
    void** gc_raw_roots[5] = { &l1, &l3, &l5, &l7, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 773u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_name;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_name_span;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_visibility;
        t0 = l0.payload.obj;
        l7 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_decorators;
        t0 = vader_front_dead__code$named_decl(vader_ref_box(l3), l4, l5, l6, l7, true);
        l2 = vader_ref_box(t0);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 754u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_toolchain_ast$ConstDecl_t*) t0)->f_name;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast$ConstDecl_t*) t0)->f_name_span;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_toolchain_ast$ConstDecl_t*) t0)->f_visibility;
        t0 = l0.payload.obj;
        l7 = ((vader_struct_toolchain_ast$ConstDecl_t*) t0)->f_decorators;
        t0 = vader_front_dead__code$named_decl(vader_ref_box(l3), l4, l5, l6, l7, false);
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 816u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_toolchain_ast$StructDecl_t*) t0)->f_name;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast$StructDecl_t*) t0)->f_name_span;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_toolchain_ast$StructDecl_t*) t0)->f_visibility;
        t0 = l0.payload.obj;
        l7 = ((vader_struct_toolchain_ast$StructDecl_t*) t0)->f_decorators;
        t0 = vader_front_dead__code$named_decl(vader_ref_box(l3), l4, l5, l6, l7, false);
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 767u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_toolchain_ast$EnumDecl_t*) t0)->f_name;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast$EnumDecl_t*) t0)->f_name_span;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_toolchain_ast$EnumDecl_t*) t0)->f_visibility;
        t0 = l0.payload.obj;
        l7 = ((vader_struct_toolchain_ast$EnumDecl_t*) t0)->f_decorators;
        t0 = vader_front_dead__code$named_decl(vader_ref_box(l3), l4, l5, l6, l7, false);
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 823u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_toolchain_ast$TraitDecl_t*) t0)->f_name;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast$TraitDecl_t*) t0)->f_name_span;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_toolchain_ast$TraitDecl_t*) t0)->f_visibility;
        t0 = l0.payload.obj;
        l7 = ((vader_struct_toolchain_ast$TraitDecl_t*) t0)->f_decorators;
        t0 = vader_front_dead__code$named_decl(vader_ref_box(l3), l4, l5, l6, l7, false);
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 825u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_toolchain_ast$TypeAliasDecl_t*) t0)->f_name;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast$TypeAliasDecl_t*) t0)->f_name_span;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_toolchain_ast$TypeAliasDecl_t*) t0)->f_visibility;
        t0 = l0.payload.obj;
        l7 = ((vader_struct_toolchain_ast$TypeAliasDecl_t*) t0)->f_decorators;
        t0 = vader_front_dead__code$named_decl(vader_ref_box(l3), l4, l5, l6, l7, false);
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 782u) {
        t0 = l0.payload.obj;
        vader_front_dead__code$collect_names(vader_ref_box(t0), l1);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_toolchain_ast$ImplDecl_t*) t0)->f_trait_name;
        vader_array_push_scalar((vader_array_t*) l1, vader_box_string(447u, l4));
        l2 = vader_box_obj(0u, NULL);
    } else if (l0.tag == 743u) {
        t0 = l0.payload.obj;
        vader_front_dead__code$collect_names(vader_ref_box(t0), l1);
        l2 = vader_box_obj(0u, NULL);
    } else {
        if (!(l0.tag == 783u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = vader_box_obj(0u, NULL);
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_front_dead__code$collect_names(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[4] = { &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct___lambda_env_vader_front_dead__code_1_t* _a0_obj = (vader_struct___lambda_env_vader_front_dead__code_1_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_front_dead__code_1_t));
    vader_obj_header_init(_a0_obj, 488u);
    _a0_obj->f_cap_0 = l1;
    t0 = (void*) _a0_obj;
    vader_fn_t* _a1_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a1_closure, 436u);
    _a1_closure->code = (void*) &vader_fn_lift___lambda_vader_front_dead__code_0;
    _a1_closure->env = t0;
    l2 = (void*) _a1_closure;
    l3 = (void*) &vader_fn_static_toolchain_ast$ignore_node;
    toolchain_ast$inspect(l0, l2, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_front_dead__code$is_comptime_helper(vader_box_t l0) {
    void* t0;
    bool t1;
    if (l0.tag == 773u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_comptime_synthetic;
        return t1;
    }
    return false;
}

static bool vader_front_dead__code$is_public(uint8_t l0) {
    return l0 == INT32_C(0);
}

static bool vader_front_dead__code$is_root_decl(uint8_t l0, void* l1, vader_string_t l2, vader_string_t l3) {
    bool l4;
    bool t0;
    t0 = vader_front_dead__code$is_public(l0);
    if (t0) {
        l4 = true;
    } else {
        l4 = vader_front_dead__code$is_wired_root(l1, l2);
    }
    if (l4) {
        return true;
    }
    if (l3 == 1664u) {
        l4 = l2 == 1664u;
    } else {
        l4 = false;
    }
    return l4;
}

static bool vader_front_dead__code$is_wired_root(void* l0, vader_string_t l1) {
    void* l2;
    void* l5;
    int64_t l3, l4;
    vader_string_t t0;
    if (l1 == 2303u) {
        return true;
    }
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t0 = ((vader_struct_toolchain_ast$Decorator_t*) l5)->f_name;
        if (t0 == 2698u) {
            return true;
        }
        t0 = ((vader_struct_toolchain_ast$Decorator_t*) l5)->f_name;
        if (t0 == 1951u) {
            return true;
        }
        t0 = ((vader_struct_toolchain_ast$Decorator_t*) l5)->f_name;
        if (t0 == 2190u) {
            return true;
        }
        t0 = ((vader_struct_toolchain_ast$Decorator_t*) l5)->f_name;
        if (t0 == 1938u) {
            return true;
        }
        t0 = ((vader_struct_toolchain_ast$Decorator_t*) l5)->f_name;
        if (t0 == 1516u) {
            return true;
        }
        l4 = (l4 + INT64_C(1));
    }
    return false;
}

static void* vader_front_dead__code$named_decl(vader_box_t l0, vader_string_t l1, void* l2, uint8_t l3, void* l4, bool l5) {
    void* l6 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[4] = { &l2, &l4, &l6, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 0u, 447u);
    l6 = (void*) _a0_arr;
    vader_front_dead__code$collect_names(l0, l6);
    vader_struct_vader_front_dead__code$NamedDeclRefs_t* _a1_obj = (vader_struct_vader_front_dead__code$NamedDeclRefs_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_dead__code$NamedDeclRefs_t));
    vader_obj_header_init(_a1_obj, 1150u);
    _a1_obj->f_name = l1;
    _a1_obj->f_name_span = l2;
    _a1_obj->f_visibility = l3;
    _a1_obj->f_decorators = l4;
    _a1_obj->f_is_fn = l5;
    _a1_obj->f_refs = l6;
    t0 = (void*) _a1_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

uint8_t vader_front_dead__code$referenced_name(vader_box_t l0, void* l1) {
    vader_string_t l2 = 0;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 778u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$IdentExpr_t*) t0)->f_name;
        vader_array_push_scalar((vader_array_t*) l1, vader_box_string(447u, l2));
        { vader_gc_top = gc_frame.prev; return (uint8_t) 0; }
    }
    if (l0.tag == 771u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$FieldExpr_t*) t0)->f_field;
        vader_array_push_scalar((vader_array_t*) l1, vader_box_string(447u, l2));
    }
    { vader_gc_top = gc_frame.prev; return (uint8_t) 0; }
}

static void vader_front_dead__code$register_refs(void* l0, vader_string_t l1, void* l2) {
    int64_t l3, l6;
    void* l4 = NULL;
    void* l5 = NULL;
    vader_string_t l7 = 0;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[4] = { &l0, &l2, &l4, &l5 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = std_collections$len__string__string__(l0);
    l4 = std_collections$get_or_put__string__string__(l0, l1, l2);
    t0 = std_collections$len__string__string__(l0);
    if (t0 == l3) {
        l5 = l2;
        l3 = ((vader_array_t*) l5)->length;
        l6 = INT64_C(0);
        while ((l6 < l3)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            t1 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l6];
            l7 = t1.payload.s;
            vader_array_push_scalar((vader_array_t*) l4, vader_box_string(447u, l7));
            l6 = (l6 + INT64_C(1));
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
}
