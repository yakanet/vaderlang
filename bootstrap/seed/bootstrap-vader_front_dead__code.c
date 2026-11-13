#include "bootstrap.split.h"

static void vader_front_dead__code$add_names(vader_box_t l0, void* l1);
static bool vader_front_dead__code$brings_a_name(void* l0, void* l1, void* l2);
static vader_box_t vader_front_dead__code$collect_decl_refs(vader_box_t l0, void* l1);
static bool vader_front_dead__code$declares_an_impl(void* l0);
static void* vader_front_dead__code$impls_run(void* l0, vader_box_t l1, void* l2);
static bool vader_front_dead__code$is_comptime_helper(vader_box_t l0);
static bool vader_front_dead__code$is_public(uint8_t l0);
static bool vader_front_dead__code$is_root_decl(uint8_t l0, void* l1, vader_string_t l2, vader_string_t l3);
static void* vader_front_dead__code$loaded_from(void* l0, void* l1, vader_box_t l2, vader_string_t l3);
static bool vader_front_dead__code$loads_an_impl(void* l0, void* l1, void* l2, vader_string_t l3);
static void* vader_front_dead__code$named_decl(vader_box_t l0, vader_string_t l1, void* l2, uint8_t l3, void* l4, bool l5);
static void* vader_front_dead__code$names_written(void* l0);
static void vader_front_dead__code$note_callee_run(vader_box_t l0, void* l1, void* l2);
static bool vader_front_dead__code$runs_an_impl_of(void* l0, vader_string_t l1, void* l2);
static void vader_front_dead__code$walk_imports(void* l0, vader_string_t l1, vader_box_t l2, vader_string_t l3, void* l4);

static void vader_front_dead__code$add_names(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    vader_string_t l5 = 0;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &t0 };
    void** gc_raw_roots[2] = { &l1, &l2 };
    vader_string_t* gc_atom_roots[1] = { &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(26u, 0u, 0u, 499u);
    l2 = (void*) _a0_arr;
    vader_front_reach$collect_names(l0, l2);
    l3 = vader_array_length(((vader_array_t*) l2));
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t0 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l4];
        l5 = t0.payload.s;
        std_collections$add__string(l1, l5);
        l4 = (l4 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_front_dead__code$brings_a_name(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l7 = NULL;
    void* l10 = NULL;
    void* l12 = NULL;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    vader_string_t l6 = 0;
    vader_string_t l11 = 0;
    int64_t l8, l9;
    void* t0 = NULL;
    bool t1;
    vader_box_t t2 = vader_box_null();
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[3] = { &l4, &l5, &t2 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l7, &l10, &l12, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l6, &l11, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(26u, 0u, 0u, 499u);
    l3 = (void*) _a0_arr;
    l4 = ((vader_struct_toolchain_ast$ImportDecl_t*) l0)->f_binding;
    l5 = l4;
    if (l4.tag == 931u) {
        t0 = l5.payload.obj;
        l6 = ((vader_struct_toolchain_ast$NamedNamespaceImport_t*) t0)->f_name;
        t1 = std_collections$Set$std_core$Contains$contains__string(l2, l6);
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4.tag == 895u) {
        t0 = l5.payload.obj;
        l7 = ((vader_struct_toolchain_ast$DestructureImport_t*) t0)->f_names;
        l8 = vader_array_length(((vader_array_t*) l7));
        l9 = INT64_C(0);
        while ((l9 < l8)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            l10 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l9);
            l6 = ((vader_struct_toolchain_ast$ImportName_t*) l10)->f_name;
            vader_array_push_scalar((vader_array_t*) l3, vader_box_string(499u, l6));
            l5 = ((vader_struct_toolchain_ast$ImportName_t*) l10)->f_alias;
            if (l5.tag == 0u) {
                l9 = (l9 + INT64_C(1));
                continue;
            }
            l11 = l5.payload.s;
            if (l11 != 1047u) {
                t1 = std_collections$Set$std_core$Contains$contains__string(l2, l11);
                if (t1) {
                    { vader_gc_top = gc_frame.prev; return true; }
                }
            }
            l9 = (l9 + INT64_C(1));
        }
    } else if (!(l4.tag == 965u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    l7 = ((vader_struct_vader_front_resolver$CollectedModule_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l1)->f_collected)->f_symbols;
    l10 = ((vader_struct_std_collections$Map__string__vader_core_symbol_Symbol_t*) l7)->f_ekeys;
    l12 = ((vader_struct_std_collections$Map__string__vader_core_symbol_Symbol_t*) l7)->f_evals;
    l8 = INT64_C(0);
    l9 = ((vader_struct_std_collections$Map__string__vader_core_symbol_Symbol_t*) l7)->f_size;
    while ((l8 < l9)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l10);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l8)
        t2 = vader_array_box_slots(_a2_slotarr->buf)[vader_array_offset(_a2_slotarr) + (size_t) l8];
        t3 = t2.payload.s;
        vader_array_t* _a3_slotarr = ((vader_array_t*) l12);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l8)
        l7 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l8);
        t1 = vader_front_resolver$wildcard_exposes(l7, vader_ref_box(l3));
        if (t1) {
            l6 = ((vader_struct_vader_core_symbol$Symbol_t*) l7)->f_name;
            t1 = std_collections$Set$std_core$Contains$contains__string(l2, l6);
            if (t1) {
                { vader_gc_top = gc_frame.prev; return true; }
            }
        }
        l8 = (l8 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return false; }
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
    vader_array_t* _a0_arr = vader_array_new(26u, 0u, 0u, 499u);
    l4 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(2u, 0u, 13u, 26u);
    l5 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(27u, 0u, 7u, 502u);
    l6 = (void*) _a2_arr;
    vader_struct_std_collections$Map__string__string___t* _a3_obj = (vader_struct_std_collections$Map__string__string___t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__string___t));
    vader_obj_header_init(_a3_obj, 793u);
    _a3_obj->f_ekeys = l4;
    _a3_obj->f_evals = l5;
    _a3_obj->f_index = l6;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l4 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(26u, 0u, 0u, 499u);
    l5 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(26u, 0u, 0u, 499u);
    l6 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(228u, 0u, 13u, 1288u);
    l7 = (void*) _a6_arr;
    l8 = l0;
    l9 = vader_array_length(((vader_array_t*) l8));
    l10 = INT64_C(0);
    while ((l10 < l9)) {
        vader_array_t* _a7_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l10)
        l11 = vader_array_ref_load_box(_a7_slotarr->buf, vader_array_offset(_a7_slotarr) + (size_t) l10);
        l13 = vader_front_dead__code$collect_decl_refs(l11, l6);
        if (l13.tag == 0u) {
            l10 = (l10 + INT64_C(1));
            continue;
        }
        l12 = l13.payload.obj;
        l14 = ((vader_struct_vader_front_dead__code$NamedDeclRefs_t*) l12)->f_name;
        l15 = ((vader_struct_vader_front_dead__code$NamedDeclRefs_t*) l12)->f_refs;
        vader_front_reach$register_refs(l4, l14, l15);
        l16 = ((vader_struct_vader_front_dead__code$NamedDeclRefs_t*) l12)->f_visibility;
        l17 = ((vader_struct_vader_front_dead__code$NamedDeclRefs_t*) l12)->f_decorators;
        l18 = ((vader_struct_vader_front_dead__code$NamedDeclRefs_t*) l12)->f_name;
        t0 = vader_front_dead__code$is_root_decl(l16, l17, l18, l1);
        if (t0) {
            l19 = ((vader_struct_vader_front_dead__code$NamedDeclRefs_t*) l12)->f_name;
            vader_array_push_scalar((vader_array_t*) l5, vader_box_string(499u, l19));
        } else {
            t0 = vader_front_dead__code$is_comptime_helper(l11);
            if (!(t0)) {
                l20 = ((vader_struct_vader_front_dead__code$NamedDeclRefs_t*) l12)->f_name;
                l21 = ((vader_struct_vader_front_dead__code$NamedDeclRefs_t*) l12)->f_name_span;
                vader_struct_vader_front_dead__code$DeadDecl_t* _a8_obj = (vader_struct_vader_front_dead__code$DeadDecl_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_dead__code$DeadDecl_t));
                vader_obj_header_init(_a8_obj, 1288u);
                _a8_obj->f_name = l20;
                _a8_obj->f_name_span = l21;
                l22 = (void*) _a8_obj;
                vader_array_push_ref((vader_array_t*) l7, l22);
            }
        }
        l10 = (l10 + INT64_C(1));
    }
    l8 = l3;
    l9 = vader_array_length(((vader_array_t*) l8));
    l10 = INT64_C(0);
    while ((l10 < l9)) {
        vader_array_t* _a9_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l10)
        t1 = vader_array_ref_load_obj(_a9_slotarr->buf, vader_array_offset(_a9_slotarr) + (size_t) l10);
        vader_front_reach$collect_names(vader_ref_box(t1), l6);
        l10 = (l10 + INT64_C(1));
    }
    l4 = vader_front_reach$bfs_reachable(l5, l6, l4);
    l5 = l7;
    l9 = vader_array_length(((vader_array_t*) l5));
    l10 = INT64_C(0);
    while ((l10 < l9)) {
        vader_array_t* _a10_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        l6 = vader_array_ref_load_obj(_a10_slotarr->buf, vader_array_offset(_a10_slotarr) + (size_t) l10);
        l14 = ((vader_struct_vader_front_dead__code$DeadDecl_t*) l6)->f_name;
        t0 = std_collections$Set$std_core$Contains$contains__string(l4, l14);
        if (!(t0)) {
            l7 = ((vader_struct_vader_front_dead__code$DeadDecl_t*) l6)->f_name_span;
            l18 = ((vader_struct_vader_front_dead__code$DeadDecl_t*) l6)->f_name;
            l19 = concat_3(1104u, l18, 1240u);
            l8 = vader_support_diagnostics$warning((uint8_t) 4, l7, l19);
            vader_array_push_ref((vader_array_t*) l2, l8);
        }
        l10 = (l10 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

void vader_front_dead__code$check_unused_imports(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l11 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    void* l20 = NULL;
    void* l21 = NULL;
    void* l24 = NULL;
    void* l26 = NULL;
    void* l30 = NULL;
    void* l33 = NULL;
    void* l37 = NULL;
    void* l40 = NULL;
    int64_t l8, l9, l12, l13, l22, l23, l27, l28;
    vader_string_t l10 = 0;
    vader_string_t l14 = 0;
    vader_string_t l15 = 0;
    vader_string_t l25 = 0;
    vader_string_t l31 = 0;
    vader_string_t l35 = 0;
    vader_string_t l36 = 0;
    vader_string_t l38 = 0;
    vader_string_t l39 = 0;
    vader_box_t l16 = vader_box_null(), l19 = vader_box_null(), l29 = vader_box_null(), l32 = vader_box_null(), l34 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    void* t2 = NULL;
    bool t3;
    vader_box_t* gc_roots[6] = { &l16, &l19, &l29, &l32, &l34, &t0 };
    void** gc_raw_roots[20] = {
        &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l11, &l17, &l18, &l20, &l21, &l24, &l26, &l30,
        &l33, &l37, &l40, &t2,
    };
    vader_string_t* gc_atom_roots[10] = {
        &l10, &l14, &l15, &l25, &l31, &l35, &l36, &l38, &l39, &t1,
    };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 6u, 20u, gc_roots, gc_raw_roots, 0u, NULL, 10u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(26u, 0u, 0u, 499u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(33u, 0u, 0u, 510u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(27u, 0u, 7u, 502u);
    l5 = (void*) _a2_arr;
    vader_struct_std_collections$Map__string__Any_t* _a3_obj = (vader_struct_std_collections$Map__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any_t));
    vader_obj_header_init(_a3_obj, 773u);
    _a3_obj->f_ekeys = l3;
    _a3_obj->f_evals = l4;
    _a3_obj->f_index = l5;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l3 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(26u, 0u, 0u, 499u);
    l4 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(26u, 0u, 0u, 499u);
    l5 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(27u, 0u, 7u, 502u);
    l6 = (void*) _a6_arr;
    vader_struct_std_collections$Map__string__string_t* _a7_obj = (vader_struct_std_collections$Map__string__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__string_t));
    vader_obj_header_init(_a7_obj, 792u);
    _a7_obj->f_ekeys = l4;
    _a7_obj->f_evals = l5;
    _a7_obj->f_index = l6;
    _a7_obj->f_mask = INT64_C(0);
    _a7_obj->f_grow_at = INT64_C(0);
    _a7_obj->f_size = INT64_C(0);
    _a7_obj->f_tombs = INT64_C(0);
    l4 = (void*) _a7_obj;
    l5 = ((vader_struct_vader_front_resolver$LoadedProject_t*) l0)->f_modules;
    l6 = ((vader_struct_std_collections$Map__string__vader_front_resolver_LoadedModule_t*) l5)->f_ekeys;
    l7 = ((vader_struct_std_collections$Map__string__vader_front_resolver_LoadedModule_t*) l5)->f_evals;
    l8 = INT64_C(0);
    l9 = ((vader_struct_std_collections$Map__string__vader_front_resolver_LoadedModule_t*) l5)->f_size;
    while ((l8 < l9)) {
        vader_array_t* _a8_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l8)
        t0 = vader_array_box_slots(_a8_slotarr->buf)[vader_array_offset(_a8_slotarr) + (size_t) l8];
        t1 = t0.payload.s;
        vader_array_t* _a9_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l8)
        l5 = vader_array_ref_load_obj(_a9_slotarr->buf, vader_array_offset(_a9_slotarr) + (size_t) l8);
        l10 = ((vader_struct_vader_front_resolver$Module_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l5)->f_module)->f_module_name;
        std_collections$Map$std_core$IndexSet$set_at__string__Any(l3, l10, vader_ref_box(l5));
        l11 = ((vader_struct_vader_front_resolver$Module_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l5)->f_module)->f_files;
        l12 = vader_array_length(((vader_array_t*) l11));
        l13 = INT64_C(0);
        while ((l13 < l12)) {
            vader_array_t* _a10_slotarr = ((vader_array_t*) l11);
            VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
            t2 = vader_array_ref_load_obj(_a10_slotarr->buf, vader_array_offset(_a10_slotarr) + (size_t) l13);
            l14 = ((vader_struct_vader_front_resolver$SourceFile_t*) t2)->f_path;
            l15 = ((vader_struct_vader_front_resolver$Module_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l5)->f_module)->f_module_name;
            std_collections$Map$std_core$IndexSet$set_at__string__string(l4, l14, l15);
            l13 = (l13 + INT64_C(1));
        }
        l8 = (l8 + INT64_C(1));
    }
    l5 = ((vader_struct_vader_front_resolver$LoadedProject_t*) l0)->f_modules;
    l6 = ((vader_struct_std_collections$Map__string__vader_front_resolver_LoadedModule_t*) l5)->f_ekeys;
    l7 = ((vader_struct_std_collections$Map__string__vader_front_resolver_LoadedModule_t*) l5)->f_evals;
    l8 = INT64_C(0);
    l9 = ((vader_struct_std_collections$Map__string__vader_front_resolver_LoadedModule_t*) l5)->f_size;
    while ((l8 < l9)) {
        vader_array_t* _a11_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l8)
        t0 = vader_array_box_slots(_a11_slotarr->buf)[vader_array_offset(_a11_slotarr) + (size_t) l8];
        l10 = t0.payload.s;
        vader_array_t* _a12_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l8)
        l5 = vader_array_ref_load_obj(_a12_slotarr->buf, vader_array_offset(_a12_slotarr) + (size_t) l8);
        l14 = l10;
        l11 = l5;
        t3 = ((vader_struct_vader_front_resolver$LoadedModule_t*) l11)->f_tests_removed;
        if (!(t3)) {
            l16 = std_collections$Map$std_core$Index$at__string__Any(((vader_struct_vader_front_typecheck$CheckResult_t*) l1)->f_all_modules, l14);
            l17 = ((vader_struct_vader_front_resolver$Module_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l11)->f_module)->f_files;
            l12 = vader_array_length(((vader_array_t*) l17));
            l13 = INT64_C(0);
            while ((l13 < l12)) {
                vader_array_t* _a13_slotarr = ((vader_array_t*) l17);
                VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l13)
                l18 = vader_array_ref_load_obj(_a13_slotarr->buf, vader_array_offset(_a13_slotarr) + (size_t) l13);
                l19 = vader_box_obj(0u, NULL);
                l20 = vader_front_dead__code$names_written(((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) l18)->f_program)->f_decls);
                l21 = ((vader_struct_vader_front_resolver$LoadedModule_t*) l11)->f_discarded_bodies;
                l22 = vader_array_length(((vader_array_t*) l21));
                l23 = INT64_C(0);
                while ((l23 < l22)) {
                    vader_array_t* _a14_slotarr = ((vader_array_t*) l21);
                    VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l23)
                    l24 = vader_array_ref_load_obj(_a14_slotarr->buf, vader_array_offset(_a14_slotarr) + (size_t) l23);
                    l15 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) ((vader_struct_toolchain_ast$FnDecl_t*) l24)->f_span)->f_start)->f_file;
                    l25 = ((vader_struct_vader_front_resolver$SourceFile_t*) l18)->f_path;
                    if (l15 == l25) {
                        vader_front_dead__code$add_names(vader_ref_box(l24), l20);
                    }
                    l23 = (l23 + INT64_C(1));
                }
                l26 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) l18)->f_program)->f_decls;
                l27 = vader_array_length(((vader_array_t*) l26));
                l28 = INT64_C(0);
                while ((l28 < l27)) {
                    vader_array_t* _a15_slotarr = ((vader_array_t*) l26);
                    VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l28)
                    l29 = vader_array_ref_load_box(_a15_slotarr->buf, vader_array_offset(_a15_slotarr) + (size_t) l28);
                    if (l29.tag == 917u) {
                        t2 = l29.payload.obj;
                        t3 = toolchain_ast$decorators_have(((vader_struct_toolchain_ast$ImportDecl_t*) t2)->f_decorators, 1634u);
                        if (!(t3)) {
                            t2 = l29.payload.obj;
                            l31 = ((vader_struct_toolchain_ast$ImportDecl_t*) t2)->f_path;
                            l32 = std_collections$Map$std_core$Index$at__string__Any(l3, l31);
                            if (l32.tag == 0u) {
                                l28 = (l28 + INT64_C(1));
                                continue;
                            }
                            l30 = l32.payload.obj;
                            t2 = l29.payload.obj;
                            t3 = vader_front_dead__code$brings_a_name(t2, l30, l20);
                            if (t3) {
                                l28 = (l28 + INT64_C(1));
                                continue;
                            }
                            l34 = l19;
                            if (l34.tag == 0u) {
                                l33 = vader_front_dead__code$impls_run(l18, l16, l4);
                            } else {
                                l33 = l34.payload.obj;
                            }
                            l19 = vader_ref_box(l33);
                            t2 = l29.payload.obj;
                            l35 = ((vader_struct_toolchain_ast$ImportDecl_t*) t2)->f_path;
                            t3 = vader_front_dead__code$runs_an_impl_of(l33, l35, l30);
                            if (!(t3)) {
                                t2 = l29.payload.obj;
                                l36 = ((vader_struct_toolchain_ast$ImportDecl_t*) t2)->f_path;
                                t3 = vader_front_dead__code$loads_an_impl(l0, l3, l11, l36);
                                if (!(t3)) {
                                    t2 = l29.payload.obj;
                                    l37 = ((vader_struct_toolchain_ast$ImportDecl_t*) t2)->f_span;
                                    t2 = l29.payload.obj;
                                    l38 = ((vader_struct_toolchain_ast$ImportDecl_t*) t2)->f_path;
                                    l39 = concat_3(1104u, l38, 1104u);
                                    l40 = vader_support_diagnostics$warning((uint8_t) 3, l37, l39);
                                    vader_array_push_ref((vader_array_t*) l2, l40);
                                    l28 = (l28 + INT64_C(1));
                                    continue;
                                }
                            }
                            l28 = (l28 + INT64_C(1));
                            continue;
                        }
                    }
                    l28 = (l28 + INT64_C(1));
                }
                l13 = (l13 + INT64_C(1));
            }
        }
        l8 = (l8 + INT64_C(1));
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
    if (l0.tag == 907u) {
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
    if (l0.tag == 888u) {
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
    } else if (l0.tag == 950u) {
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
    } else if (l0.tag == 901u) {
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
    } else if (l0.tag == 958u) {
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
    } else if (l0.tag == 960u) {
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
    } else if (l0.tag == 916u) {
        t0 = l0.payload.obj;
        vader_front_reach$collect_names(vader_ref_box(t0), l1);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_toolchain_ast$ImplDecl_t*) t0)->f_trait_name;
        vader_array_push_scalar((vader_array_t*) l1, vader_box_string(499u, l4));
        l2 = vader_box_obj(0u, NULL);
    } else if (l0.tag == 878u) {
        t0 = l0.payload.obj;
        vader_front_reach$collect_names(vader_ref_box(t0), l1);
        l2 = vader_box_obj(0u, NULL);
    } else {
        if (!(l0.tag == 917u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = vader_box_obj(0u, NULL);
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_front_dead__code$declares_an_impl(void* l0) {
    void* l1;
    void* l4;
    int64_t l2, l3, l5, l6;
    void* t0;
    vader_box_t t1;
    l1 = ((vader_struct_vader_front_resolver$Module_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l0)->f_module)->f_files;
    l2 = vader_array_length(((vader_array_t*) l1));
    l3 = INT64_C(0);
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l3);
        l4 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) t0)->f_program)->f_decls;
        l5 = vader_array_length(((vader_array_t*) l4));
        l6 = INT64_C(0);
        while ((l6 < l5)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            t1 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l6);
            if (t1.tag == 916u) {
                return true;
            }
            l6 = (l6 + INT64_C(1));
        }
        l3 = (l3 + INT64_C(1));
    }
    return false;
}

static void* vader_front_dead__code$impls_run(void* l0, vader_box_t l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l11 = NULL;
    int64_t l8, l9;
    uint8_t l10;
    vader_box_t l12 = vader_box_null();
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l1, &l12, &t2 };
    void** gc_raw_roots[9] = { &l0, &l2, &l3, &l4, &l5, &l6, &l7, &l11, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 9u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(26u, 0u, 0u, 499u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(24u, 0u, 12u, 497u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(27u, 0u, 7u, 502u);
    l5 = (void*) _a2_arr;
    vader_struct_std_collections$Map__string__bool_t* _a3_obj = (vader_struct_std_collections$Map__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__bool_t));
    vader_obj_header_init(_a3_obj, 779u);
    _a3_obj->f_ekeys = l3;
    _a3_obj->f_evals = l4;
    _a3_obj->f_index = l5;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections$Set__string_t* _a4_obj = (vader_struct_std_collections$Set__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__string_t));
    vader_obj_header_init(_a4_obj, 861u);
    _a4_obj->f_inner = t0;
    l3 = (void*) _a4_obj;
    vader_array_t* _a5_arr = vader_array_new(26u, 0u, 0u, 499u);
    l4 = (void*) _a5_arr;
    vader_struct_vader_front_dead__code$ImplsRun_t* _a6_obj = (vader_struct_vader_front_dead__code$ImplsRun_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_dead__code$ImplsRun_t));
    vader_obj_header_init(_a6_obj, 1289u);
    _a6_obj->f_modules = l3;
    _a6_obj->f_trait_keys = l4;
    _a6_obj->f_inherited = false;
    l3 = (void*) _a6_obj;
    if (l1.tag == 0u) {
        { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = vader_front_typecheck$all_roles();
    vader_struct___lambda_env_vader_front_dead__code_1_t* _a7_obj = (vader_struct___lambda_env_vader_front_dead__code_1_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_front_dead__code_1_t));
    vader_obj_header_init(_a7_obj, 545u);
    _a7_obj->f_cap_0 = l1;
    l6 = (void*) _a7_obj;
    t1 = vader_array_length(((vader_array_t*) l5));
    vader_array_t* _a8_arr = vader_array_reserve(36u, (int64_t) t1, 13u, 761u);
    l7 = (void*) _a8_arr;
    l8 = vader_array_length(((vader_array_t*) l5));
    l9 = INT64_C(0);
    while ((l9 < l8)) {
        vader_array_t* _a9_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        t2 = vader_array_read_u8(_a9_slotarr, vader_array_offset(_a9_slotarr) + (size_t) l9, 504u);
        l10 = ((uint8_t) t2.payload.i);
        l11 = __lambda_vader_front_dead__code_0(l6, l10);
        vader_array_push_ref((vader_array_t*) l7, l11);
        l9 = (l9 + INT64_C(1));
    }
    l4 = l7;
    l5 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) l0)->f_program)->f_decls;
    l8 = vader_array_length(((vader_array_t*) l5));
    l9 = INT64_C(0);
    while ((l9 < l8)) {
        vader_array_t* _a10_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l9)
        l12 = vader_array_ref_load_box(_a10_slotarr->buf, vader_array_offset(_a10_slotarr) + (size_t) l9);
        vader_struct___lambda_env_vader_front_dead__code_3_t* _a11_obj = (vader_struct___lambda_env_vader_front_dead__code_3_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_front_dead__code_3_t));
        vader_obj_header_init(_a11_obj, 546u);
        _a11_obj->f_cap_0 = l4;
        _a11_obj->f_cap_1 = l2;
        _a11_obj->f_cap_2 = l3;
        t0 = (void*) _a11_obj;
        vader_fn_t* _a12_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
        vader_obj_header_init(_a12_closure, 488u);
        _a12_closure->code = (void*) &vader_fn_lift___lambda_vader_front_dead__code_2;
        _a12_closure->env = t0;
        l6 = (void*) _a12_closure;
        l7 = (void*) &vader_fn_static_toolchain_ast$ignore_node;
        toolchain_ast$inspect(l12, l6, l7);
        l9 = (l9 + INT64_C(1));
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_front_dead__code$is_comptime_helper(vader_box_t l0) {
    void* t0;
    bool t1;
    if (l0.tag == 907u) {
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
        l4 = vader_front_reach$is_wired_root(l1, l2);
    }
    if (l4) {
        return true;
    }
    if (l3 == 1776u) {
        l4 = l2 == 1776u;
    } else {
        l4 = false;
    }
    return l4;
}

static void* vader_front_dead__code$loaded_from(void* l0, void* l1, vader_box_t l2, vader_string_t l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    vader_string_t l7 = 0;
    vader_string_t l14 = 0;
    vader_box_t l8 = vader_box_null();
    int64_t l12, l13;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    bool t2;
    vader_box_t* gc_roots[3] = { &l2, &l8, &t1 };
    void** gc_raw_roots[9] = { &l0, &l1, &l4, &l5, &l6, &l9, &l10, &l11, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l3, &l7, &l14 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(26u, 0u, 0u, 499u);
    l4 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(24u, 0u, 12u, 497u);
    l5 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(27u, 0u, 7u, 502u);
    l6 = (void*) _a2_arr;
    vader_struct_std_collections$Map__string__bool_t* _a3_obj = (vader_struct_std_collections$Map__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__bool_t));
    vader_obj_header_init(_a3_obj, 779u);
    _a3_obj->f_ekeys = l4;
    _a3_obj->f_evals = l5;
    _a3_obj->f_index = l6;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections$Set__string_t* _a4_obj = (vader_struct_std_collections$Set__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__string_t));
    vader_obj_header_init(_a4_obj, 861u);
    _a4_obj->f_inner = t0;
    l4 = (void*) _a4_obj;
    l6 = ((vader_struct_vader_front_resolver$LoadedProject_t*) l0)->f_modules;
    l7 = ((vader_struct_vader_front_resolver$LoadedProject_t*) l0)->f_entry;
    l8 = std_collections$Map$std_core$Index$at__string__Any(l6, l7);
    if (l8.tag == 0u) {
        { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = l8.payload.obj;
    l7 = ((vader_struct_vader_front_resolver$Module_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l5)->f_module)->f_module_name;
    vader_front_dead__code$walk_imports(l1, l7, vader_box_obj(0u, NULL), 0u, l4);
    vader_array_t* _a5_arr = vader_array_new(26u, 0u, 0u, 499u);
    l6 = (void*) _a5_arr;
    l9 = l1;
    l10 = ((vader_struct_std_collections$Map__string__vader_front_resolver_LoadedModule_t*) l9)->f_ekeys;
    l11 = ((vader_struct_std_collections$Map__string__vader_front_resolver_LoadedModule_t*) l9)->f_evals;
    l12 = INT64_C(0);
    l13 = ((vader_struct_std_collections$Map__string__vader_front_resolver_LoadedModule_t*) l9)->f_size;
    while ((l12 < l13)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l10);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l12)
        t1 = vader_array_box_slots(_a6_slotarr->buf)[vader_array_offset(_a6_slotarr) + (size_t) l12];
        l7 = t1.payload.s;
        vader_array_t* _a7_slotarr = ((vader_array_t*) l11);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l12)
        t0 = vader_array_ref_load_obj(_a7_slotarr->buf, vader_array_offset(_a7_slotarr) + (size_t) l12);
        l14 = l7;
        t2 = std_collections$Set$std_core$Contains$contains__string(l4, l14);
        if (!(t2)) {
            vader_array_push_scalar((vader_array_t*) l6, vader_box_string(499u, l14));
        }
        l12 = (l12 + INT64_C(1));
    }
    if (l2.tag == 0u) {
        l9 = l6;
        l12 = vader_array_length(((vader_array_t*) l9));
        l13 = INT64_C(0);
        while ((l13 < l12)) {
            vader_array_t* _a8_slotarr = ((vader_array_t*) l9);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            t1 = vader_array_box_slots(_a8_slotarr->buf)[vader_array_offset(_a8_slotarr) + (size_t) l13];
            l7 = t1.payload.s;
            std_collections$add__string(l4, l7);
            l13 = (l13 + INT64_C(1));
        }
        { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a9_arr = vader_array_new(26u, 0u, 0u, 499u);
    l4 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(24u, 0u, 12u, 497u);
    l9 = (void*) _a10_arr;
    vader_array_t* _a11_arr = vader_array_new(27u, 0u, 7u, 502u);
    l10 = (void*) _a11_arr;
    vader_struct_std_collections$Map__string__bool_t* _a12_obj = (vader_struct_std_collections$Map__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__bool_t));
    vader_obj_header_init(_a12_obj, 779u);
    _a12_obj->f_ekeys = l4;
    _a12_obj->f_evals = l9;
    _a12_obj->f_index = l10;
    _a12_obj->f_mask = INT64_C(0);
    _a12_obj->f_grow_at = INT64_C(0);
    _a12_obj->f_size = INT64_C(0);
    _a12_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a12_obj;
    vader_struct_std_collections$Set__string_t* _a13_obj = (vader_struct_std_collections$Set__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__string_t));
    vader_obj_header_init(_a13_obj, 861u);
    _a13_obj->f_inner = t0;
    l4 = (void*) _a13_obj;
    l7 = ((vader_struct_vader_front_resolver$Module_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l5)->f_module)->f_module_name;
    l14 = l2.payload.s;
    vader_front_dead__code$walk_imports(l1, l7, vader_box_string(499u, l14), l3, l4);
    l5 = l6;
    l12 = vader_array_length(((vader_array_t*) l5));
    l13 = INT64_C(0);
    while ((l13 < l12)) {
        vader_array_t* _a14_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
        t1 = vader_array_box_slots(_a14_slotarr->buf)[vader_array_offset(_a14_slotarr) + (size_t) l13];
        l7 = t1.payload.s;
        l14 = l2.payload.s;
        vader_front_dead__code$walk_imports(l1, l7, vader_box_string(499u, l14), l3, l4);
        l13 = (l13 + INT64_C(1));
    }
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_front_dead__code$loads_an_impl(void* l0, void* l1, void* l2, vader_string_t l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    void* l9 = NULL;
    int64_t l6, l7, l8;
    vader_string_t l10 = 0;
    vader_box_t l11 = vader_box_null();
    bool t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[2] = { &l11, &t1 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l4, &l5, &l9, &t2 };
    vader_string_t* gc_atom_roots[2] = { &l3, &l10 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_front_resolver$CollectedModule_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l2)->f_collected)->f_import_paths;
    vader_struct___lambda_env_vader_front_dead__code_7_t* _a0_obj = (vader_struct___lambda_env_vader_front_dead__code_7_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_front_dead__code_7_t));
    vader_obj_header_init(_a0_obj, 548u);
    _a0_obj->f_cap_0 = l3;
    l5 = (void*) _a0_obj;
    l6 = INT64_C(0);
    l7 = vader_array_length(((vader_array_t*) l4));
    l8 = INT64_C(0);
    while ((l8 < l7)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l9 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l8);
        t0 = __lambda_vader_front_dead__code_6(l5, l9);
        if (t0) {
            l6 = vader_chk_add(i64, l6, INT64_C(1));
        }
        l8 = (l8 + INT64_C(1));
    }
    if ((l6 > INT64_C(1))) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    l5 = vader_front_dead__code$loaded_from(l0, l1, vader_box_obj(0u, NULL), 0u);
    l10 = ((vader_struct_vader_front_resolver$Module_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l2)->f_module)->f_module_name;
    l4 = vader_front_dead__code$loaded_from(l0, l1, vader_box_string(499u, l10), l3);
    l9 = ((vader_struct_std_collections$Map__string__bool_t*) ((vader_struct_std_collections$Set__string_t*) l5)->f_inner)->f_ekeys;
    l6 = INT64_C(0);
    l7 = ((vader_struct_std_collections$Map__string__bool_t*) ((vader_struct_std_collections$Set__string_t*) l5)->f_inner)->f_size;
    while ((l6 < l7)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
        t1 = vader_array_box_slots(_a2_slotarr->buf)[vader_array_offset(_a2_slotarr) + (size_t) l6];
        l10 = t1.payload.s;
        t0 = std_collections$Set$std_core$Contains$contains__string(l4, l10);
        if (!(t0)) {
            l11 = std_collections$Map$std_core$Index$at__string__Any(l1, l10);
            if (!(l11.tag == 0u)) {
                t2 = l11.payload.obj;
                t0 = vader_front_dead__code$declares_an_impl(t2);
                if (t0) {
                    { vader_gc_top = gc_frame.prev; return true; }
                }
            }
        }
        l6 = (l6 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return false; }
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
    vader_array_t* _a0_arr = vader_array_new(26u, 0u, 0u, 499u);
    l6 = (void*) _a0_arr;
    vader_front_reach$collect_names(l0, l6);
    vader_struct_vader_front_dead__code$NamedDeclRefs_t* _a1_obj = (vader_struct_vader_front_dead__code$NamedDeclRefs_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_dead__code$NamedDeclRefs_t));
    vader_obj_header_init(_a1_obj, 1290u);
    _a1_obj->f_name = l1;
    _a1_obj->f_name_span = l2;
    _a1_obj->f_visibility = l3;
    _a1_obj->f_decorators = l4;
    _a1_obj->f_is_fn = l5;
    _a1_obj->f_refs = l6;
    t0 = (void*) _a1_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_dead__code$names_written(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null();
    vader_string_t l6 = 0;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l5, &t1 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l7, &l8, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(26u, 0u, 0u, 499u);
    l1 = (void*) _a0_arr;
    l2 = l0;
    l3 = vader_array_length(((vader_array_t*) l2));
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        l5 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l4);
        if (!(l5.tag == 917u)) {
            vader_front_reach$collect_names(l5, l1);
            if (l5.tag == 916u) {
                t0 = l5.payload.obj;
                l6 = ((vader_struct_toolchain_ast$ImplDecl_t*) t0)->f_trait_name;
                vader_array_push_scalar((vader_array_t*) l1, vader_box_string(499u, l6));
            }
        }
        l4 = (l4 + INT64_C(1));
    }
    vader_array_t* _a2_arr = vader_array_new(26u, 0u, 0u, 499u);
    l2 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(24u, 0u, 12u, 497u);
    l7 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(27u, 0u, 7u, 502u);
    l8 = (void*) _a4_arr;
    vader_struct_std_collections$Map__string__bool_t* _a5_obj = (vader_struct_std_collections$Map__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__bool_t));
    vader_obj_header_init(_a5_obj, 779u);
    _a5_obj->f_ekeys = l2;
    _a5_obj->f_evals = l7;
    _a5_obj->f_index = l8;
    _a5_obj->f_mask = INT64_C(0);
    _a5_obj->f_grow_at = INT64_C(0);
    _a5_obj->f_size = INT64_C(0);
    _a5_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a5_obj;
    vader_struct_std_collections$Set__string_t* _a6_obj = (vader_struct_std_collections$Set__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__string_t));
    vader_obj_header_init(_a6_obj, 861u);
    _a6_obj->f_inner = t0;
    l2 = (void*) _a6_obj;
    l3 = vader_array_length(((vader_array_t*) l1));
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a7_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        t1 = vader_array_box_slots(_a7_slotarr->buf)[vader_array_offset(_a7_slotarr) + (size_t) l4];
        l6 = t1.payload.s;
        std_collections$add__string(l2, l6);
        l4 = (l4 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_front_dead__code$note_callee_run(vader_box_t l0, void* l1, void* l2) {
    vader_string_t l3 = 0;
    vader_box_t l4 = vader_box_null();
    void* l5 = NULL;
    int64_t l6, l7;
    void* t0 = NULL;
    bool t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l4, &t2 };
    void** gc_raw_roots[4] = { &l1, &l2, &l5, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1416u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_toolchain_ast$FnDecl_t*) ((vader_struct_vader_front_typecheck$DirectFn_t*) t0)->f_decl)->f_materialized;
        if (t1) {
            ((vader_struct_vader_front_dead__code$ImplsRun_t*) l2)->f_inherited = true;
        } else {
            t0 = l0.payload.obj;
            l3 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) ((vader_struct_toolchain_ast$FnDecl_t*) ((vader_struct_vader_front_typecheck$DirectFn_t*) t0)->f_decl)->f_span)->f_start)->f_file;
            l4 = std_collections$Map$std_core$Index$at__string__string(l1, l3);
            if (l4.tag == 0u) {
                { vader_gc_top = gc_frame.prev; return; }
            }
            l3 = l4.payload.s;
            std_collections$add__string(((vader_struct_vader_front_dead__code$ImplsRun_t*) l2)->f_modules, l3);
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 1404u) {
        l5 = ((vader_struct_vader_front_dead__code$ImplsRun_t*) l2)->f_trait_keys;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_front_typecheck$BoundMember_t*) t0)->f_trait_key;
        vader_array_push_scalar((vader_array_t*) l5, vader_box_string(499u, l3));
    } else if (l0.tag == 1458u) {
        l5 = ((vader_struct_vader_front_dead__code$ImplsRun_t*) l2)->f_trait_keys;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_front_typecheck$TraitMember_t*) t0)->f_trait_key;
        vader_array_push_scalar((vader_array_t*) l5, vader_box_string(499u, l3));
    } else if (l0.tag == 1418u) {
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_front_typecheck$EachOf_t*) t0)->f_callees;
        l6 = vader_array_length(((vader_array_t*) l5));
        l7 = INT64_C(0);
        while ((l7 < l6)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            t2 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l7);
            vader_front_dead__code$note_callee_run(t2, l1, l2);
            l7 = (l7 + INT64_C(1));
        }
    } else if (!((l0.tag == 1406u || l0.tag == 1421u || l0.tag == 1426u || l0.tag == 1465u))) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    { vader_gc_top = gc_frame.prev; return; }
}

uint8_t vader_front_dead__code$note_site(vader_box_t l0, void* l1, void* l2, void* l3) {
    void* l4 = NULL;
    void* l7 = NULL;
    int64_t l5, l6, l8;
    vader_box_t l9 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &l9 };
    void** gc_raw_roots[5] = { &l1, &l2, &l3, &l4, &l7 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if ((l0.tag == 877u || l0.tag == 880u || l0.tag == 881u || l0.tag == 882u || l0.tag == 885u || l0.tag == 886u || l0.tag == 887u || l0.tag == 900u || l0.tag == 905u || l0.tag == 906u || l0.tag == 909u || l0.tag == 911u || l0.tag == 912u || l0.tag == 915u || l0.tag == 920u || l0.tag == 922u || l0.tag == 923u || l0.tag == 925u || l0.tag == 929u || l0.tag == 933u || l0.tag == 934u || l0.tag == 940u || l0.tag == 945u || l0.tag == 947u || l0.tag == 952u || l0.tag == 962u)) {
        l4 = l1;
        l5 = vader_array_length(((vader_array_t*) l4));
        l6 = INT64_C(0);
        while ((l6 < l5)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            l7 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l6);
            l8 = VADER_UNION_FIELD(int64_t, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_id, l0.payload.obj);
            l9 = std_collections$Map$std_core$Index$at__i64__Any(l7, l8);
            if (l9.tag == 0u) {
                l6 = (l6 + INT64_C(1));
                continue;
            }
            vader_front_dead__code$note_callee_run(l9, l2, l3);
            l6 = (l6 + INT64_C(1));
        }
    }
    { vader_gc_top = gc_frame.prev; return (uint8_t) 0; }
}

static bool vader_front_dead__code$runs_an_impl_of(void* l0, vader_string_t l1, void* l2) {
    void* l3 = NULL;
    void* l6 = NULL;
    void* l10 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    int64_t l4, l5, l7, l8, l11, l16, l17;
    vader_box_t l9 = vader_box_null();
    vader_string_t l12 = 0;
    vader_string_t l18 = 0;
    bool l15;
    bool t0;
    int64_t t1;
    void* t2 = NULL;
    vader_string_t t3 = 0;
    vader_box_t t4 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l9, &t4 };
    void** gc_raw_roots[8] = { &l0, &l2, &l3, &l6, &l10, &l13, &l14, &t2 };
    vader_string_t* gc_atom_roots[4] = { &l1, &l12, &l18, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = std_collections$Set$std_core$Contains$contains__string(((vader_struct_vader_front_dead__code$ImplsRun_t*) l0)->f_modules, l1);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    t0 = ((vader_struct_vader_front_dead__code$ImplsRun_t*) l0)->f_inherited;
    if (!(t0)) {
        t1 = vader_array_length(((vader_array_t*) ((vader_struct_vader_front_dead__code$ImplsRun_t*) l0)->f_trait_keys));
        if (t1 == INT64_C(0)) {
            { vader_gc_top = gc_frame.prev; return false; }
        }
    }
    l3 = ((vader_struct_vader_front_resolver$Module_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l2)->f_module)->f_files;
    l4 = vader_array_length(((vader_array_t*) l3));
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t2 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
        l6 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) t2)->f_program)->f_decls;
        l7 = vader_array_length(((vader_array_t*) l6));
        l8 = INT64_C(0);
        while ((l8 < l7)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            l9 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l8);
            if (l9.tag == 916u) {
                t2 = l9.payload.obj;
                t3 = ((vader_struct_toolchain_ast$ImplDecl_t*) t2)->f_trait_name;
                l10 = std_string$split(t3, 432u);
                t1 = vader_array_length(((vader_array_t*) l10));
                l11 = vader_chk_sub(i64, t1, INT64_C(1));
                vader_array_t* _a2_slotarr = ((vader_array_t*) l10);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l11)
                t4 = vader_array_box_slots(_a2_slotarr->buf)[vader_array_offset(_a2_slotarr) + (size_t) l11];
                l12 = t4.payload.s;
                t0 = ((vader_struct_vader_front_dead__code$ImplsRun_t*) l0)->f_inherited;
                if (t0) {
                    { vader_gc_top = gc_frame.prev; return true; }
                }
                l13 = ((vader_struct_vader_front_dead__code$ImplsRun_t*) l0)->f_trait_keys;
                vader_struct___lambda_env_vader_front_dead__code_5_t* _a3_obj = (vader_struct___lambda_env_vader_front_dead__code_5_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_front_dead__code_5_t));
                vader_obj_header_init(_a3_obj, 547u);
                _a3_obj->f_cap_0 = l12;
                l14 = (void*) _a3_obj;
                l15 = false;
                l16 = vader_array_length(((vader_array_t*) l13));
                l17 = INT64_C(0);
                {
                    while ((l17 < l16)) {
                        vader_array_t* _a4_slotarr = ((vader_array_t*) l13);
                        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                        t4 = vader_array_box_slots(_a4_slotarr->buf)[vader_array_offset(_a4_slotarr) + (size_t) l17];
                        l18 = t4.payload.s;
                        t0 = __lambda_vader_front_dead__code_4(l14, l18);
                        if (t0) {
                            l15 = true;
                            goto end_84;
                        }
                        l17 = (l17 + INT64_C(1));
                    }
                    l15 = false;
                } end_84: ;
                if (l15) {
                    { vader_gc_top = gc_frame.prev; return true; }
                }
                l8 = (l8 + INT64_C(1));
                continue;
            }
            l8 = (l8 + INT64_C(1));
        }
        l5 = (l5 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static void vader_front_dead__code$walk_imports(void* l0, vader_string_t l1, vader_box_t l2, vader_string_t l3, void* l4) {
    void* l5 = NULL;
    void* l9 = NULL;
    void* l11 = NULL;
    void* l14 = NULL;
    int64_t l6, l7, l12, l13;
    vader_string_t l8 = 0;
    vader_string_t l15 = 0;
    vader_box_t l10 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    bool t1;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[3] = { &l2, &l10, &t0 };
    void** gc_raw_roots[6] = { &l0, &l4, &l5, &l9, &l11, &l14 };
    vader_string_t* gc_atom_roots[5] = { &l1, &l3, &l8, &l15, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(26u, 1u, 0u, 499u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 0u] = vader_box_string(499u, l1);
    l5 = (void*) _a0_arr;
    l6 = INT64_C(0);
    for (;;) {
        l7 = vader_array_length(((vader_array_t*) l5));
        if ((l6 < l7)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            t0 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l6];
            l8 = t0.payload.s;
            l6 = vader_chk_add(i64, l6, INT64_C(1));
            t1 = std_collections$add__string(l4, l8);
            if (!(t1)) {
                continue;
            }
            l10 = std_collections$Map$std_core$Index$at__string__Any(l0, l8);
            if (l10.tag == 0u) {
                continue;
            }
            l9 = l10.payload.obj;
            l11 = ((vader_struct_vader_front_resolver$CollectedModule_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l9)->f_collected)->f_import_paths;
            l12 = vader_array_length(((vader_array_t*) l11));
            l13 = INT64_C(0);
            while ((l13 < l12)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l11);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                l14 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l13);
                if (vader_box_eq(vader_box_string(499u, l8), l2)) {
                    t2 = ((vader_struct_vader_front_resolver$ImportPath_t*) l14)->f_path;
                    if (t2 == l3) {
                        l13 = (l13 + INT64_C(1));
                        continue;
                    }
                }
                l15 = ((vader_struct_vader_front_resolver$ImportPath_t*) l14)->f_path;
                vader_array_push_scalar((vader_array_t*) l5, vader_box_string(499u, l15));
                l13 = (l13 + INT64_C(1));
            }
            continue;
        }
        break;
    }
    { vader_gc_top = gc_frame.prev; return; }
}
