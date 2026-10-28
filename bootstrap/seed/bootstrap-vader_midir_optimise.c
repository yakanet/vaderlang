#include "bootstrap.split.h"

static void* vader_midir_optimise$annotate_function(void* l0);
static void vader_midir_optimise$append_alias(void* l0, int32_t l1, int32_t l2);
static void* vader_midir_optimise$compact_locals(void* l0);
static void* vader_midir_optimise$compute_carried_across_loop_headers(void* l0, void* l1);
static void* vader_midir_optimise$compute_escaping(void* l0, void* l1);
static void* vader_midir_optimise$drop_slots_using(void* l0, int32_t l1);
static void* vader_midir_optimise$fold_moves(void* l0);
static void* vader_midir_optimise$fold_moves_in_block(void* l0, void* l1, void* l2, void* l3);
static void* vader_midir_optimise$forward_block(void* l0);
static void* vader_midir_optimise$forward_function(void* l0);
static vader_box_t vader_midir_optimise$lookup_slot(void* l0, int32_t l1, int32_t l2);
static bool vader_midir_optimise$move_retags(void* l0, void* l1);
static void* vader_midir_optimise$optimise_function(void* l0);
static bool vader_midir_optimise$read_may_carry_ref(vader_box_t l0);
static void vader_midir_optimise$record_alias(void* l0, void* l1, int32_t l2, int32_t l3);
static vader_box_t vader_midir_optimise$remap_instr(vader_box_t l0, void* l1);
static int32_t vader_midir_optimise$remap_local(void* l0, int32_t l1);
static vader_box_t vader_midir_optimise$remap_local_opt(void* l0, vader_box_t l1);
static void* vader_midir_optimise$remap_locals(void* l0, void* l1);
static vader_box_t vader_midir_optimise$remap_terminator(vader_box_t l0, void* l1);
static vader_box_t vader_midir_optimise$with_dst(vader_box_t l0, int32_t l1);

void* vader_midir_optimise$annotate_escape(void* l0) {
    int32_t l1, l2;
    bool l3;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l11 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    void* l21 = NULL;
    void* l25 = NULL;
    void* l27 = NULL;
    void* l28 = NULL;
    void* l30 = NULL;
    void* l32 = NULL;
    void* l35 = NULL;
    void* l36 = NULL;
    void* l37 = NULL;
    int64_t l9, l10, l12, l15, l16, l19, l20, l22, l23;
    vader_box_t l24 = vader_box_null();
    vader_string_t l26 = 0;
    vader_string_t l29 = 0;
    vader_string_t l31 = 0;
    vader_string_t l33 = 0;
    vader_string_t l34 = 0;
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    void* t2 = NULL;
    bool t3;
    vader_box_t* gc_roots[2] = { &l24, &t0 };
    void** gc_raw_roots[21] = {
        &l0, &l4, &l5, &l6, &l7, &l8, &l11, &l13, &l14, &l17, &l18, &l21, &l25, &l27, &l28, &l30,
        &l32, &l35, &l36, &l37, &t2,
    };
    vader_string_t* gc_atom_roots[6] = { &l26, &l29, &l31, &l33, &l34, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 21u, gc_roots, gc_raw_roots, 0u, NULL, 6u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = INT32_C(0);
    l2 = INT32_C(0);
    l3 = vader_support_opt__report$opt_report_enabled();
    vader_array_t* _a0_arr = vader_array_new(211u, 0u, 13u, 1377u);
    l4 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(21u, 0u, 0u, 335u);
    l5 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(28u, 0u, 0u, 346u);
    l6 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(22u, 0u, 7u, 338u);
    l7 = (void*) _a3_arr;
    vader_struct_std_collections$MutableMap__string__Any_t* _a4_obj = (vader_struct_std_collections$MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__Any_t));
    vader_obj_header_init(_a4_obj, 533u);
    _a4_obj->f_ekeys = l5;
    _a4_obj->f_evals = l6;
    _a4_obj->f_index = l7;
    _a4_obj->f_mask = INT64_C(0);
    _a4_obj->f_grow_at = INT64_C(0);
    _a4_obj->f_size = INT64_C(0);
    _a4_obj->f_tombs = INT64_C(0);
    l5 = (void*) _a4_obj;
    l6 = ((vader_struct_vader_midir$CFGProject_t*) l0)->f_modules;
    l7 = ((vader_struct_std_collections$MutableMap__string__vader_midir_CFGModule_t*) l6)->f_ekeys;
    l8 = ((vader_struct_std_collections$MutableMap__string__vader_midir_CFGModule_t*) l6)->f_evals;
    l9 = INT64_C(0);
    l10 = ((vader_struct_std_collections$MutableMap__string__vader_midir_CFGModule_t*) l6)->f_size;
    while ((l9 < l10)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l9)
        t0 = vader_array_box_slots(_a5_slotarr->buf)[_a5_slotarr->offset + (size_t) l9];
        t1 = t0.payload.s;
        vader_array_t* _a6_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l9)
        l6 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l9);
        vader_array_t* _a7_arr = vader_array_new(203u, 0u, 13u, 1306u);
        l11 = (void*) _a7_arr;
        l12 = ((vader_array_t*) ((vader_struct_vader_midir$CFGModule_t*) l6)->f_functions)->length;
        vader_array_t* _a8_arr = vader_array_repeat((vader_array_t*) l11, (int64_t) l12);
        l13 = (void*) _a8_arr;
        l14 = ((vader_struct_vader_midir$CFGModule_t*) l6)->f_functions;
        l15 = ((vader_array_t*) l14)->length;
        l16 = INT64_C(0);
        while ((l16 < l15)) {
            vader_array_t* _a9_slotarr = ((vader_array_t*) l14);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l16)
            t2 = vader_array_ref_load_obj(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l16);
            l17 = vader_midir_optimise$annotate_function(t2);
            l18 = ((vader_struct_vader_midir$CFGFunction_t*) l17)->f_blocks;
            l19 = ((vader_array_t*) l18)->length;
            l20 = INT64_C(0);
            while ((l20 < l19)) {
                vader_array_t* _a10_slotarr = ((vader_array_t*) l18);
                VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
                t2 = vader_array_ref_load_obj(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l20);
                l21 = ((vader_struct_vader_midir$BasicBlock_t*) t2)->f_instructions;
                l22 = ((vader_array_t*) l21)->length;
                l23 = INT64_C(0);
                while ((l23 < l22)) {
                    vader_array_t* _a11_slotarr = ((vader_array_t*) l21);
                    VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
                    l24 = vader_array_ref_load_box(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l23);
                    if (l24.tag == 1354u) {
                        l1 = vader_chk_add(i32, l1, INT32_C(1));
                        t2 = l24.payload.obj;
                        t3 = ((vader_struct_vader_midir$InstrStructNew_t*) t2)->f_stack;
                        if (t3) {
                            l2 = vader_chk_add(i32, l2, INT32_C(1));
                        } else if (l3) {
                            t2 = l24.payload.obj;
                            l25 = ((vader_struct_vader_midir$InstrStructNew_t*) t2)->f_span;
                            t2 = l24.payload.obj;
                            l26 = vader_core_types$display_type(((vader_struct_vader_midir$InstrStructNew_t*) t2)->f_type);
                            vader_struct_vader_midir_optimise$EscapeSite_t* _a12_obj = (vader_struct_vader_midir_optimise$EscapeSite_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_optimise$EscapeSite_t));
                            vader_obj_header_init(_a12_obj, 1377u);
                            _a12_obj->f_span = l25;
                            _a12_obj->f_kind = 2658u;
                            _a12_obj->f_type_name = l26;
                            l27 = (void*) _a12_obj;
                            vader_array_push_ref((vader_array_t*) l4, l27);
                        }
                    } else if (l24.tag == 1330u) {
                        l1 = vader_chk_add(i32, l1, INT32_C(1));
                        t2 = l24.payload.obj;
                        t3 = ((vader_struct_vader_midir$InstrArrayNew_t*) t2)->f_stack;
                        if (t3) {
                            l2 = vader_chk_add(i32, l2, INT32_C(1));
                        } else if (l3) {
                            t2 = l24.payload.obj;
                            l28 = ((vader_struct_vader_midir$InstrArrayNew_t*) t2)->f_span;
                            t2 = l24.payload.obj;
                            l29 = vader_core_types$display_type(((vader_struct_vader_midir$InstrArrayNew_t*) t2)->f_type);
                            vader_struct_vader_midir_optimise$EscapeSite_t* _a13_obj = (vader_struct_vader_midir_optimise$EscapeSite_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_optimise$EscapeSite_t));
                            vader_obj_header_init(_a13_obj, 1377u);
                            _a13_obj->f_span = l28;
                            _a13_obj->f_kind = 1564u;
                            _a13_obj->f_type_name = l29;
                            l30 = (void*) _a13_obj;
                            vader_array_push_ref((vader_array_t*) l4, l30);
                        }
                    }
                    l23 = (l23 + INT64_C(1));
                }
                l20 = (l20 + INT64_C(1));
            }
            vader_array_push_ref((vader_array_t*) l13, l17);
            l16 = (l16 + INT64_C(1));
        }
        l31 = ((vader_struct_vader_midir$CFGModule_t*) l6)->f_module_id;
        l32 = l6;
        l33 = ((vader_struct_vader_midir$CFGModule_t*) l32)->f_module_id;
        l34 = ((vader_struct_vader_midir$CFGModule_t*) l32)->f_display_path;
        l35 = ((vader_struct_vader_midir$CFGModule_t*) l32)->f_externs;
        l36 = ((vader_struct_vader_midir$CFGModule_t*) l32)->f_struct_decls;
        vader_struct_vader_midir$CFGModule_t* _a14_obj = (vader_struct_vader_midir$CFGModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$CFGModule_t));
        vader_obj_header_init(_a14_obj, 1308u);
        _a14_obj->f_module_id = l33;
        _a14_obj->f_display_path = l34;
        _a14_obj->f_functions = l13;
        _a14_obj->f_externs = l35;
        _a14_obj->f_struct_decls = l36;
        l37 = (void*) _a14_obj;
        std_collections$MutableMap$std_core$IndexSet$set_at__string__Any(l5, l31, vader_ref_box(l37));
        l9 = (l9 + INT64_C(1));
    }
    l6 = l0;
    l7 = ((vader_struct_vader_midir$CFGProject_t*) l6)->f_vtable_entries;
    l8 = ((vader_struct_vader_midir$CFGProject_t*) l6)->f_strings;
    l11 = ((vader_struct_vader_midir$CFGProject_t*) l6)->f_data_pool;
    l13 = ((vader_struct_vader_midir$CFGProject_t*) l6)->f_globals;
    l6 = ((vader_struct_vader_midir$CFGProject_t*) l6)->f_trait_membership;
    vader_struct_vader_midir$CFGProject_t* _a15_obj = (vader_struct_vader_midir$CFGProject_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$CFGProject_t));
    vader_obj_header_init(_a15_obj, 1310u);
    _a15_obj->f_modules = l5;
    _a15_obj->f_vtable_entries = l7;
    _a15_obj->f_strings = l8;
    _a15_obj->f_data_pool = l11;
    _a15_obj->f_globals = l13;
    _a15_obj->f_trait_membership = l6;
    l5 = (void*) _a15_obj;
    vader_struct_vader_midir_optimise$EscapeStats_t* _a16_obj = (vader_struct_vader_midir_optimise$EscapeStats_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_optimise$EscapeStats_t));
    vader_obj_header_init(_a16_obj, 1378u);
    _a16_obj->f_total_allocs = l1;
    _a16_obj->f_stack_promoted = l2;
    _a16_obj->f_heap_sites = l4;
    l4 = (void*) _a16_obj;
    vader_struct_vader_midir_optimise$AnnotatedProject_t* _a17_obj = (vader_struct_vader_midir_optimise$AnnotatedProject_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_optimise$AnnotatedProject_t));
    vader_obj_header_init(_a17_obj, 1375u);
    _a17_obj->f_project = l5;
    _a17_obj->f_stats = l4;
    t2 = (void*) _a17_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir_optimise$annotate_function(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l20 = NULL;
    void* l21 = NULL;
    void* l22 = NULL;
    void* l24 = NULL;
    void* l26 = NULL;
    void* l27 = NULL;
    void* l28 = NULL;
    void* l30 = NULL;
    void* l31 = NULL;
    void* l33 = NULL;
    void* l35 = NULL;
    void* l39 = NULL;
    void* l40 = NULL;
    void* l41 = NULL;
    void* l44 = NULL;
    void* l45 = NULL;
    void* l49 = NULL;
    void* l50 = NULL;
    void* l51 = NULL;
    void* l55 = NULL;
    void* l57 = NULL;
    void* l60 = NULL;
    void* l61 = NULL;
    int64_t l4, l5, l7, l8;
    vader_box_t l9 = vader_box_null(), l16 = vader_box_null(), l17 = vader_box_null(), l56 = vader_box_null(), l59 = vader_box_null();
    int32_t l10, l11, l12, l29, l32, l36, l37, l42, l43, l46, l52, l54, l58;
    bool l18, l19, l23, l25, l34, l38, l47, l48;
    vader_string_t l53 = 0;
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[5] = { &l9, &l16, &l17, &l56, &l59 };
    void** gc_raw_roots[32] = {
        &l0, &l1, &l2, &l3, &l6, &l13, &l14, &l15, &l20, &l21, &l22, &l24, &l26, &l27, &l28, &l30,
        &l31, &l33, &l35, &l39, &l40, &l41, &l44, &l45, &l49, &l50, &l51, &l55, &l57, &l60, &l61,
        &t0,
    };
    vader_string_t* gc_atom_roots[1] = { &l53 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 5u, 32u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 7u, 338u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(19u, 0u, 12u, 333u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections$MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 462u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections$MutableSet__i32_t* _a4_obj = (vader_struct_std_collections$MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 605u);
    _a4_obj->f_inner = t0;
    l1 = (void*) _a4_obj;
    vader_array_t* _a5_arr = vader_array_new(22u, 0u, 7u, 338u);
    l2 = (void*) _a5_arr;
    l3 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        t0 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l5);
        l6 = ((vader_struct_vader_midir$BasicBlock_t*) t0)->f_instructions;
        l7 = ((vader_array_t*) l6)->length;
        l8 = INT64_C(0);
        while ((l8 < l7)) {
            vader_array_t* _a7_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            l9 = vader_array_ref_load_box(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l8);
            if (l9.tag == 1354u) {
                t0 = l9.payload.obj;
                l10 = ((vader_struct_vader_midir$InstrStructNew_t*) t0)->f_dst;
                std_collections$add__vader_midir$LocalId(l1, l10);
                t0 = l9.payload.obj;
                l11 = ((vader_struct_vader_midir$InstrStructNew_t*) t0)->f_dst;
                vader_array_push_i32((vader_array_t*) l2, l11);
            } else if (l9.tag == 1330u) {
                t0 = l9.payload.obj;
                l12 = ((vader_struct_vader_midir$InstrArrayNew_t*) t0)->f_dst;
                std_collections$add__vader_midir$LocalId(l1, l12);
            }
            l8 = (l8 + INT64_C(1));
        }
        l5 = (l5 + INT64_C(1));
    }
    t1 = std_collections$is_empty__i32(l1);
    if (t1) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = vader_midir_optimise$compute_escaping(l0, l1);
    l6 = ((vader_struct_vader_midir_optimise$EscapeResult_t*) l3)->f_alias_of;
    l6 = vader_midir_optimise$compute_carried_across_loop_headers(l0, l6);
    vader_array_t* _a8_arr = vader_array_new(22u, 0u, 7u, 338u);
    l13 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(19u, 0u, 12u, 333u);
    l14 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(22u, 0u, 7u, 338u);
    l15 = (void*) _a10_arr;
    vader_struct_std_collections$MutableMap__i32__bool_t* _a11_obj = (vader_struct_std_collections$MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__bool_t));
    vader_obj_header_init(_a11_obj, 462u);
    _a11_obj->f_ekeys = l13;
    _a11_obj->f_evals = l14;
    _a11_obj->f_index = l15;
    _a11_obj->f_mask = INT64_C(0);
    _a11_obj->f_grow_at = INT64_C(0);
    _a11_obj->f_size = INT64_C(0);
    _a11_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a11_obj;
    vader_struct_std_collections$MutableSet__i32_t* _a12_obj = (vader_struct_std_collections$MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__i32_t));
    vader_obj_header_init(_a12_obj, 605u);
    _a12_obj->f_inner = t0;
    l13 = (void*) _a12_obj;
    vader_array_t* _a13_arr = vader_array_new(22u, 0u, 7u, 338u);
    l14 = (void*) _a13_arr;
    l4 = ((vader_array_t*) l2)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a14_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
        l10 = ((int32_t*) _a14_slotarr->buf->slots)[_a14_slotarr->offset + (size_t) l5];
        t1 = std_collections$MutableSet$std_core$Contains$contains__i32(((vader_struct_vader_midir_optimise$EscapeResult_t*) l3)->f_escaping, l10);
        if (t1) {
            l5 = (l5 + INT64_C(1));
            continue;
        }
        t1 = std_collections$MutableSet$std_core$Contains$contains__i32(l6, l10);
        if (t1) {
            l5 = (l5 + INT64_C(1));
            continue;
        }
        std_collections$add__vader_midir$LocalId(l13, l10);
        vader_array_push_i32((vader_array_t*) l14, l10);
        l5 = (l5 + INT64_C(1));
    }
    for (;;) {
        l9 = vader_array_remove_last((vader_array_t*) l14);
        if (!(l9.tag == 0u)) {
            l10 = ((int32_t) l9.payload.i);
            l16 = std_collections$MutableMap$std_core$Index$at__i32__Any(((vader_struct_vader_midir_optimise$EscapeResult_t*) l3)->f_alias_from, l10);
            if (l16.tag == 0u) {
                continue;
            }
            l2 = l16.payload.obj;
            l4 = ((vader_array_t*) l2)->length;
            l5 = INT64_C(0);
            while ((l5 < l4)) {
                vader_array_t* _a15_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
                l11 = ((int32_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l5];
                t1 = std_collections$MutableSet$std_core$Contains$contains__i32(l13, l11);
                if (t1) {
                    l5 = (l5 + INT64_C(1));
                    continue;
                }
                l17 = std_collections$MutableMap$std_core$Index$at__i32__Any(((vader_struct_vader_midir_optimise$EscapeResult_t*) l3)->f_alias_of, l11);
                if (!(l17.tag == 0u)) {
                    l18 = true;
                    l15 = l17.payload.obj;
                    l7 = ((vader_array_t*) l15)->length;
                    l8 = INT64_C(0);
                    for (;;) {
                        if ((l8 < l7)) {
                            vader_array_t* _a16_slotarr = ((vader_array_t*) l15);
                            VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
                            l12 = ((int32_t*) _a16_slotarr->buf->slots)[_a16_slotarr->offset + (size_t) l8];
                            t1 = std_collections$MutableSet$std_core$Contains$contains__i32(l13, l12);
                            if (t1) {
                                l8 = (l8 + INT64_C(1));
                                continue;
                            }
                            l18 = false;
                            break;
                        }
                        break;
                    }
                    if (l18) {
                        std_collections$add__vader_midir$LocalId(l13, l11);
                        vader_array_push_i32((vader_array_t*) l14, l11);
                    }
                }
                l5 = (l5 + INT64_C(1));
            }
            continue;
        }
        break;
    }
    l18 = false;
    vader_array_t* _a17_arr = vader_array_new(201u, 0u, 13u, 1304u);
    l2 = (void*) _a17_arr;
    l14 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks;
    l4 = ((vader_array_t*) l14)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a18_slotarr = ((vader_array_t*) l14);
        VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
        l15 = vader_array_ref_load_obj(_a18_slotarr->buf, _a18_slotarr->offset + (size_t) l5);
        l19 = false;
        vader_array_t* _a19_arr = vader_array_new(268u, 0u, 13u, 2082u);
        l20 = (void*) _a19_arr;
        l21 = ((vader_struct_vader_midir$BasicBlock_t*) l15)->f_instructions;
        l7 = ((vader_array_t*) l21)->length;
        l8 = INT64_C(0);
        while ((l8 < l7)) {
            vader_array_t* _a20_slotarr = ((vader_array_t*) l21);
            VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
            l9 = vader_array_ref_load_box(_a20_slotarr->buf, _a20_slotarr->offset + (size_t) l8);
            if (l9.tag == 1354u) {
                t0 = l9.payload.obj;
                l10 = ((vader_struct_vader_midir$InstrStructNew_t*) t0)->f_dst;
                t1 = std_collections$MutableSet$std_core$Contains$contains__i32(l1, l10);
                if (t1) {
                    l24 = ((vader_struct_vader_midir_optimise$EscapeResult_t*) l3)->f_escaping;
                    t0 = l9.payload.obj;
                    l11 = ((vader_struct_vader_midir$InstrStructNew_t*) t0)->f_dst;
                    t1 = std_collections$MutableSet$std_core$Contains$contains__i32(l24, l11);
                    if (!(t1)) {
                        t0 = l9.payload.obj;
                        l12 = ((vader_struct_vader_midir$InstrStructNew_t*) t0)->f_dst;
                        t1 = std_collections$MutableSet$std_core$Contains$contains__i32(l6, l12);
                        l23 = !(t1);
                    } else {
                        l23 = false;
                    }
                    t0 = l9.payload.obj;
                    l25 = ((vader_struct_vader_midir$InstrStructNew_t*) t0)->f_stack;
                    if (l23 == l25) {
                        l26 = l9.payload.obj;
                        vader_array_push_ref((vader_array_t*) l20, l26);
                        l8 = (l8 + INT64_C(1));
                        continue;
                    }
                    l19 = true;
                    l27 = l9.payload.obj;
                    l28 = ((vader_struct_vader_midir$InstrStructNew_t*) l27)->f_span;
                    l29 = ((vader_struct_vader_midir$InstrStructNew_t*) l27)->f_dst;
                    l16 = ((vader_struct_vader_midir$InstrStructNew_t*) l27)->f_type;
                    l30 = ((vader_struct_vader_midir$InstrStructNew_t*) l27)->f_fields;
                    vader_struct_vader_midir$InstrStructNew_t* _a21_obj = (vader_struct_vader_midir$InstrStructNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrStructNew_t));
                    vader_obj_header_init(_a21_obj, 1354u);
                    _a21_obj->f_span = l28;
                    _a21_obj->f_dst = l29;
                    _a21_obj->f_type = l16;
                    _a21_obj->f_fields = l30;
                    _a21_obj->f_stack = l23;
                    l31 = (void*) _a21_obj;
                    vader_array_push_ref((vader_array_t*) l20, l31);
                } else {
                    l22 = l9.payload.obj;
                    vader_array_push_ref((vader_array_t*) l20, l22);
                    l8 = (l8 + INT64_C(1));
                    continue;
                }
            } else if (l9.tag == 1330u) {
                t0 = l9.payload.obj;
                l32 = ((vader_struct_vader_midir$InstrArrayNew_t*) t0)->f_dst;
                t1 = std_collections$MutableSet$std_core$Contains$contains__i32(l1, l32);
                if (t1) {
                    l35 = ((vader_struct_vader_midir_optimise$EscapeResult_t*) l3)->f_escaping;
                    t0 = l9.payload.obj;
                    l36 = ((vader_struct_vader_midir$InstrArrayNew_t*) t0)->f_dst;
                    t1 = std_collections$MutableSet$std_core$Contains$contains__i32(l35, l36);
                    if (!(t1)) {
                        t0 = l9.payload.obj;
                        l37 = ((vader_struct_vader_midir$InstrArrayNew_t*) t0)->f_dst;
                        t1 = std_collections$MutableSet$std_core$Contains$contains__i32(l6, l37);
                        l34 = !(t1);
                    } else {
                        l34 = false;
                    }
                    t0 = l9.payload.obj;
                    l38 = ((vader_struct_vader_midir$InstrArrayNew_t*) t0)->f_stack;
                    if (l34 == l38) {
                        l39 = l9.payload.obj;
                        vader_array_push_ref((vader_array_t*) l20, l39);
                        l8 = (l8 + INT64_C(1));
                        continue;
                    }
                    l19 = true;
                    l40 = l9.payload.obj;
                    l41 = ((vader_struct_vader_midir$InstrArrayNew_t*) l40)->f_span;
                    l42 = ((vader_struct_vader_midir$InstrArrayNew_t*) l40)->f_dst;
                    l17 = ((vader_struct_vader_midir$InstrArrayNew_t*) l40)->f_type;
                    l43 = ((vader_struct_vader_midir$InstrArrayNew_t*) l40)->f_length;
                    l44 = ((vader_struct_vader_midir$InstrArrayNew_t*) l40)->f_elements;
                    vader_struct_vader_midir$InstrArrayNew_t* _a22_obj = (vader_struct_vader_midir$InstrArrayNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrArrayNew_t));
                    vader_obj_header_init(_a22_obj, 1330u);
                    _a22_obj->f_span = l41;
                    _a22_obj->f_dst = l42;
                    _a22_obj->f_type = l17;
                    _a22_obj->f_length = l43;
                    _a22_obj->f_elements = l44;
                    _a22_obj->f_stack = l34;
                    l45 = (void*) _a22_obj;
                    vader_array_push_ref((vader_array_t*) l20, l45);
                } else {
                    l33 = l9.payload.obj;
                    vader_array_push_ref((vader_array_t*) l20, l33);
                    l8 = (l8 + INT64_C(1));
                    continue;
                }
            } else if (l9.tag == 1346u) {
                t0 = l9.payload.obj;
                l46 = ((vader_struct_vader_midir$InstrFieldSet_t*) t0)->f_target;
                l47 = std_collections$MutableSet$std_core$Contains$contains__i32(l13, l46);
                t0 = l9.payload.obj;
                l48 = ((vader_struct_vader_midir$InstrFieldSet_t*) t0)->f_barrierless;
                if (l47 == l48) {
                    l49 = l9.payload.obj;
                    vader_array_push_ref((vader_array_t*) l20, l49);
                    l8 = (l8 + INT64_C(1));
                    continue;
                }
                l19 = true;
                l50 = l9.payload.obj;
                l51 = ((vader_struct_vader_midir$InstrFieldSet_t*) l50)->f_span;
                l52 = ((vader_struct_vader_midir$InstrFieldSet_t*) l50)->f_target;
                l53 = ((vader_struct_vader_midir$InstrFieldSet_t*) l50)->f_field;
                l54 = ((vader_struct_vader_midir$InstrFieldSet_t*) l50)->f_value;
                vader_struct_vader_midir$InstrFieldSet_t* _a23_obj = (vader_struct_vader_midir$InstrFieldSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrFieldSet_t));
                vader_obj_header_init(_a23_obj, 1346u);
                _a23_obj->f_span = l51;
                _a23_obj->f_target = l52;
                _a23_obj->f_field = l53;
                _a23_obj->f_value = l54;
                _a23_obj->f_barrierless = l47;
                l55 = (void*) _a23_obj;
                vader_array_push_ref((vader_array_t*) l20, l55);
            } else {
                l56 = l9;
                vader_array_push_ref((vader_array_t*) l20, l56.payload.obj);
            }
            l8 = (l8 + INT64_C(1));
        }
        if (l19) {
            l18 = true;
            l57 = l15;
            l58 = ((vader_struct_vader_midir$BasicBlock_t*) l57)->f_id;
            l59 = ((vader_struct_vader_midir$BasicBlock_t*) l57)->f_terminator;
            l60 = ((vader_struct_vader_midir$BasicBlock_t*) l57)->f_span;
            vader_struct_vader_midir$BasicBlock_t* _a24_obj = (vader_struct_vader_midir$BasicBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$BasicBlock_t));
            vader_obj_header_init(_a24_obj, 1304u);
            _a24_obj->f_id = l58;
            _a24_obj->f_instructions = l20;
            _a24_obj->f_terminator = l59;
            _a24_obj->f_span = l60;
            l61 = (void*) _a24_obj;
            vader_array_push_ref((vader_array_t*) l2, l61);
            l5 = (l5 + INT64_C(1));
            continue;
        }
        vader_array_push_ref((vader_array_t*) l2, l15);
        l5 = (l5 + INT64_C(1));
    }
    if (!(l18)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = l0;
    l53 = ((vader_struct_vader_midir$CFGFunction_t*) l1)->f_mangled;
    l3 = ((vader_struct_vader_midir$CFGFunction_t*) l1)->f_params;
    l9 = ((vader_struct_vader_midir$CFGFunction_t*) l1)->f_return_type;
    l6 = ((vader_struct_vader_midir$CFGFunction_t*) l1)->f_locals;
    l10 = ((vader_struct_vader_midir$CFGFunction_t*) l1)->f_entry;
    l13 = ((vader_struct_vader_midir$CFGFunction_t*) l1)->f_origin;
    l1 = ((vader_struct_vader_midir$CFGFunction_t*) l1)->f_scalarised_results;
    vader_struct_vader_midir$CFGFunction_t* _a25_obj = (vader_struct_vader_midir$CFGFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$CFGFunction_t));
    vader_obj_header_init(_a25_obj, 1306u);
    _a25_obj->f_mangled = l53;
    _a25_obj->f_params = l3;
    _a25_obj->f_return_type = l9;
    _a25_obj->f_locals = l6;
    _a25_obj->f_blocks = l2;
    _a25_obj->f_entry = l10;
    _a25_obj->f_origin = l13;
    _a25_obj->f_scalarised_results = l1;
    t0 = (void*) _a25_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_midir_optimise$append_alias(void* l0, int32_t l1, int32_t l2) {
    vader_box_t l3 = vader_box_null();
    void* l4 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[3] = { &l0, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = std_collections$MutableMap$std_core$Index$at__i32__Any(l0, l1);
    if (l3.tag == 0u) {
        vader_array_t* _a0_arr = vader_array_new(22u, 1u, 7u, 338u);
        ((int32_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int32_t) l2;
        l4 = (void*) _a0_arr;
        std_collections$MutableMap$std_core$IndexSet$set_at__i32__Any(l0, l1, vader_ref_box(l4));
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = l3.payload.obj;
    vader_array_push_i32((vader_array_t*) t0, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void* vader_midir_optimise$array_load_forward_project(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    void* l20 = NULL;
    void* l21 = NULL;
    void* l22 = NULL;
    int64_t l5, l6, l11, l14, l15;
    vader_string_t l7 = 0;
    vader_string_t l8 = 0;
    vader_string_t l18 = 0;
    vader_string_t l19 = 0;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[15] = {
        &l0, &l1, &l2, &l3, &l4, &l9, &l10, &l12, &l13, &l16, &l17, &l20, &l21, &l22, &t1,
    };
    vader_string_t* gc_atom_roots[4] = { &l7, &l8, &l18, &l19 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 15u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 335u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 346u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections$MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 533u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l1 = (void*) _a3_obj;
    l2 = ((vader_struct_vader_midir$CFGProject_t*) l0)->f_modules;
    l3 = ((vader_struct_std_collections$MutableMap__string__vader_midir_CFGModule_t*) l2)->f_ekeys;
    l4 = ((vader_struct_std_collections$MutableMap__string__vader_midir_CFGModule_t*) l2)->f_evals;
    l5 = INT64_C(0);
    l6 = ((vader_struct_std_collections$MutableMap__string__vader_midir_CFGModule_t*) l2)->f_size;
    while ((l5 < l6)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
        t0 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l5];
        l7 = t0.payload.s;
        vader_array_t* _a5_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
        l2 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l5);
        l8 = l7;
        l9 = l2;
        vader_array_t* _a6_arr = vader_array_new(203u, 0u, 13u, 1306u);
        l10 = (void*) _a6_arr;
        l11 = ((vader_array_t*) ((vader_struct_vader_midir$CFGModule_t*) l9)->f_functions)->length;
        vader_array_t* _a7_arr = vader_array_repeat((vader_array_t*) l10, (int64_t) l11);
        l12 = (void*) _a7_arr;
        l13 = ((vader_struct_vader_midir$CFGModule_t*) l9)->f_functions;
        l14 = ((vader_array_t*) l13)->length;
        l15 = INT64_C(0);
        while ((l15 < l14)) {
            vader_array_t* _a8_slotarr = ((vader_array_t*) l13);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l15)
            t1 = vader_array_ref_load_obj(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l15);
            l16 = vader_midir_optimise$forward_function(t1);
            vader_array_push_ref((vader_array_t*) l12, l16);
            l15 = (l15 + INT64_C(1));
        }
        l17 = l9;
        l18 = ((vader_struct_vader_midir$CFGModule_t*) l17)->f_module_id;
        l19 = ((vader_struct_vader_midir$CFGModule_t*) l17)->f_display_path;
        l20 = ((vader_struct_vader_midir$CFGModule_t*) l17)->f_externs;
        l21 = ((vader_struct_vader_midir$CFGModule_t*) l17)->f_struct_decls;
        vader_struct_vader_midir$CFGModule_t* _a9_obj = (vader_struct_vader_midir$CFGModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$CFGModule_t));
        vader_obj_header_init(_a9_obj, 1308u);
        _a9_obj->f_module_id = l18;
        _a9_obj->f_display_path = l19;
        _a9_obj->f_functions = l12;
        _a9_obj->f_externs = l20;
        _a9_obj->f_struct_decls = l21;
        l22 = (void*) _a9_obj;
        std_collections$MutableMap$std_core$IndexSet$set_at__string__Any(l1, l8, vader_ref_box(l22));
        l5 = (l5 + INT64_C(1));
    }
    l2 = l0;
    l3 = ((vader_struct_vader_midir$CFGProject_t*) l2)->f_vtable_entries;
    l4 = ((vader_struct_vader_midir$CFGProject_t*) l2)->f_strings;
    l9 = ((vader_struct_vader_midir$CFGProject_t*) l2)->f_data_pool;
    l10 = ((vader_struct_vader_midir$CFGProject_t*) l2)->f_globals;
    l2 = ((vader_struct_vader_midir$CFGProject_t*) l2)->f_trait_membership;
    vader_struct_vader_midir$CFGProject_t* _a10_obj = (vader_struct_vader_midir$CFGProject_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$CFGProject_t));
    vader_obj_header_init(_a10_obj, 1310u);
    _a10_obj->f_modules = l1;
    _a10_obj->f_vtable_entries = l3;
    _a10_obj->f_strings = l4;
    _a10_obj->f_data_pool = l9;
    _a10_obj->f_globals = l10;
    _a10_obj->f_trait_membership = l2;
    t1 = (void*) _a10_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir_optimise$compact_locals(void* l0) {
    int64_t l1, l5, l6, l9, l10, l14, l15, l23;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l13 = NULL;
    void* l20 = NULL;
    void* l21 = NULL;
    void* l22 = NULL;
    void* l25 = NULL;
    void* l26 = NULL;
    vader_box_t l11 = vader_box_null(), l12 = vader_box_null(), l16 = vader_box_null(), l24 = vader_box_null();
    bool l17;
    int32_t l18;
    vader_string_t l19 = 0;
    void* t0 = NULL;
    bool t1, t3;
    int32_t t2;
    int64_t t4;
    vader_box_t* gc_roots[4] = { &l11, &l12, &l16, &l24 };
    void** gc_raw_roots[13] = {
        &l0, &l2, &l3, &l4, &l7, &l8, &l13, &l20, &l21, &l22, &l25, &l26, &t0,
    };
    vader_string_t* gc_atom_roots[1] = { &l19 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 13u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_array_t*) ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_locals)->length;
    vader_array_t* _a0_arr = vader_array_new(19u, 1u, 12u, 333u);
    ((uint8_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (uint8_t) false;
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l1);
    l2 = (void*) _a1_arr;
    vader_struct___lambda_env_vader_midir_optimise_1_t* _a2_obj = (vader_struct___lambda_env_vader_midir_optimise_1_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_midir_optimise_1_t));
    vader_obj_header_init(_a2_obj, 438u);
    _a2_obj->f_cap_0 = l2;
    t0 = (void*) _a2_obj;
    vader_fn_t* _a3_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a3_closure, 305u);
    _a3_closure->code = (void*) &vader_fn_lift___lambda_vader_midir_optimise_0;
    _a3_closure->env = t0;
    l3 = (void*) _a3_closure;
    l4 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_params;
    l5 = ((vader_array_t*) l4)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l6)
        t0 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l6);
        vader_fn_t* _a5_fnobj = (vader_fn_t*) l3;
        ((vader_fn_erased_sig_1_t) _a5_fnobj->code)(_a5_fnobj->env, vader_box_i32(338u, ((vader_struct_vader_midir$CFGParam_t*) t0)->f_local));
        l6 = (l6 + INT64_C(1));
    }
    l4 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks;
    l5 = ((vader_array_t*) l4)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l6)
        l7 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l6);
        l8 = ((vader_struct_vader_midir$BasicBlock_t*) l7)->f_instructions;
        l9 = ((vader_array_t*) l8)->length;
        l10 = INT64_C(0);
        while ((l10 < l9)) {
            vader_array_t* _a7_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l10)
            l11 = vader_array_ref_load_box(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l10);
            vader_midir$for_each_read_local(l11, l3);
            t1 = vader_midir$instruction_has_side_effect(l11);
            if (t1) {
                l12 = vader_midir$multi_dsts(l11);
                if (l12.tag == 0u) {
                    l16 = vader_midir$dst_of(l11);
                    if (!(l16.tag == 0u)) {
                        t2 = ((int32_t) l16.payload.i);
                        vader_fn_t* _a8_fnobj = (vader_fn_t*) l3;
                        ((vader_fn_erased_sig_1_t) _a8_fnobj->code)(_a8_fnobj->env, vader_box_i32(338u, t2));
                    }
                } else {
                    l13 = l12.payload.obj;
                    l14 = ((vader_array_t*) l13)->length;
                    l15 = INT64_C(0);
                    while ((l15 < l14)) {
                        vader_array_t* _a9_slotarr = ((vader_array_t*) l13);
                        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l15)
                        t2 = ((int32_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l15];
                        vader_fn_t* _a10_fnobj = (vader_fn_t*) l3;
                        ((vader_fn_erased_sig_1_t) _a10_fnobj->code)(_a10_fnobj->env, vader_box_i32(338u, t2));
                        l15 = (l15 + INT64_C(1));
                    }
                }
            }
            l10 = (l10 + INT64_C(1));
        }
        vader_midir$for_each_read_in_terminator(((vader_struct_vader_midir$BasicBlock_t*) l7)->f_terminator, l3);
        l6 = (l6 + INT64_C(1));
    }
    l17 = false;
    l5 = ((vader_array_t*) ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_params)->length;
    for (;;) {
        if ((l5 < l1)) {
            vader_array_t* _a11_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l5)
            t1 = ((uint8_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l5];
            t3 = t1;
            if (t3) {
                l5 = (l5 + INT64_C(1));
                continue;
            }
            l17 = true;
            break;
        }
        break;
    }
    if (!(l17)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a12_arr = vader_array_new(22u, 0u, 7u, 338u);
    t0 = (void*) _a12_arr;
    vader_array_t* _a13_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l1);
    l3 = (void*) _a13_arr;
    vader_array_t* _a14_arr = vader_array_new(204u, 0u, 13u, 1307u);
    t0 = (void*) _a14_arr;
    vader_array_t* _a15_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l1);
    l4 = (void*) _a15_arr;
    l5 = INT64_C(0);
    while ((l5 < l1)) {
        vader_array_t* _a16_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l5)
        t1 = ((uint8_t*) _a16_slotarr->buf->slots)[_a16_slotarr->offset + (size_t) l5];
        t3 = t1;
        if (t3) {
            t4 = ((vader_array_t*) l4)->length;
            l18 = ((int32_t) (int64_t) t4);
            vader_array_push_i32((vader_array_t*) l3, l18);
            vader_array_t* _a17_slotarr = ((vader_array_t*) ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_locals);
            VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l5)
            l7 = vader_array_ref_load_obj(_a17_slotarr->buf, _a17_slotarr->offset + (size_t) l5);
            vader_array_push_ref((vader_array_t*) l4, l7);
            l5 = (l5 + INT64_C(1));
            continue;
        }
        vader_array_push_i32((vader_array_t*) l3, INT32_C(-1));
        l5 = (l5 + INT64_C(1));
    }
    vader_array_t* _a18_arr = vader_array_new(206u, 0u, 13u, 1309u);
    l2 = (void*) _a18_arr;
    l1 = ((vader_array_t*) ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_params)->length;
    vader_array_t* _a19_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l1);
    l2 = (void*) _a19_arr;
    l7 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_params;
    l1 = ((vader_array_t*) l7)->length;
    l5 = INT64_C(0);
    while ((l5 < l1)) {
        vader_array_t* _a20_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
        l8 = vader_array_ref_load_obj(_a20_slotarr->buf, _a20_slotarr->offset + (size_t) l5);
        l19 = ((vader_struct_vader_midir$CFGParam_t*) l8)->f_name;
        l13 = ((vader_struct_vader_midir$CFGParam_t*) l8)->f_symbol;
        l11 = ((vader_struct_vader_midir$CFGParam_t*) l8)->f_type;
        l6 = ((int64_t) (int32_t) ((vader_struct_vader_midir$CFGParam_t*) l8)->f_local);
        vader_array_t* _a21_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l6)
        l18 = ((int32_t*) _a21_slotarr->buf->slots)[_a21_slotarr->offset + (size_t) l6];
        vader_struct_vader_midir$CFGParam_t* _a22_obj = (vader_struct_vader_midir$CFGParam_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$CFGParam_t));
        vader_obj_header_init(_a22_obj, 1309u);
        _a22_obj->f_name = l19;
        _a22_obj->f_symbol = l13;
        _a22_obj->f_type = l11;
        _a22_obj->f_local = l18;
        l20 = (void*) _a22_obj;
        vader_array_push_ref((vader_array_t*) l2, l20);
        l5 = (l5 + INT64_C(1));
    }
    vader_array_t* _a23_arr = vader_array_new(201u, 0u, 13u, 1304u);
    l7 = (void*) _a23_arr;
    l1 = ((vader_array_t*) ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks)->length;
    vader_array_t* _a24_arr = vader_array_repeat((vader_array_t*) l7, (int64_t) l1);
    l7 = (void*) _a24_arr;
    l8 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks;
    l1 = ((vader_array_t*) l8)->length;
    l5 = INT64_C(0);
    while ((l5 < l1)) {
        vader_array_t* _a25_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
        l13 = vader_array_ref_load_obj(_a25_slotarr->buf, _a25_slotarr->offset + (size_t) l5);
        vader_array_t* _a26_arr = vader_array_new(268u, 0u, 13u, 2082u);
        l20 = (void*) _a26_arr;
        l6 = ((vader_array_t*) ((vader_struct_vader_midir$BasicBlock_t*) l13)->f_instructions)->length;
        vader_array_t* _a27_arr = vader_array_repeat((vader_array_t*) l20, (int64_t) l6);
        l21 = (void*) _a27_arr;
        l22 = ((vader_struct_vader_midir$BasicBlock_t*) l13)->f_instructions;
        l9 = ((vader_array_t*) l22)->length;
        l10 = INT64_C(0);
        while ((l10 < l9)) {
            vader_array_t* _a28_slotarr = ((vader_array_t*) l22);
            VADER_ARRAY_RESOLVE_BUF(_a28_slotarr)
            l11 = vader_array_ref_load_box(_a28_slotarr->buf, _a28_slotarr->offset + (size_t) l10);
            l12 = vader_midir$dst_of(l11);
            if (l12.tag == 338u) {
                t2 = ((int32_t) l12.payload.i);
                l14 = ((int64_t) (int32_t) t2);
                if ((INT64_C(0) <= l14)) {
                    l15 = ((vader_array_t*) l3)->length;
                    l17 = (l14 < l15);
                } else {
                    l17 = false;
                }
                if (l17) {
                    t2 = ((int32_t) l12.payload.i);
                    l23 = ((int64_t) (int32_t) t2);
                    vader_array_t* _a29_slotarr = ((vader_array_t*) l3);
                    VADER_ARRAY_RESOLVE_BUF(_a29_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a29_slotarr, l23)
                    t2 = ((int32_t*) _a29_slotarr->buf->slots)[_a29_slotarr->offset + (size_t) l23];
                    if ((t2 < INT32_C(0))) {
                        t1 = vader_midir$instruction_has_side_effect(l11);
                        if (!(t1)) {
                            l10 = (l10 + INT64_C(1));
                            continue;
                        }
                    }
                }
            }
            l16 = vader_midir_optimise$remap_instr(l11, l3);
            vader_array_push_ref((vader_array_t*) l21, l16.payload.obj);
            l10 = (l10 + INT64_C(1));
        }
        l18 = ((vader_struct_vader_midir$BasicBlock_t*) l13)->f_id;
        l24 = vader_midir_optimise$remap_terminator(((vader_struct_vader_midir$BasicBlock_t*) l13)->f_terminator, l3);
        l25 = ((vader_struct_vader_midir$BasicBlock_t*) l13)->f_span;
        vader_struct_vader_midir$BasicBlock_t* _a30_obj = (vader_struct_vader_midir$BasicBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$BasicBlock_t));
        vader_obj_header_init(_a30_obj, 1304u);
        _a30_obj->f_id = l18;
        _a30_obj->f_instructions = l21;
        _a30_obj->f_terminator = l24;
        _a30_obj->f_span = l25;
        l26 = (void*) _a30_obj;
        vader_array_push_ref((vader_array_t*) l7, l26);
        l5 = (l5 + INT64_C(1));
    }
    l3 = l0;
    l19 = ((vader_struct_vader_midir$CFGFunction_t*) l3)->f_mangled;
    l11 = ((vader_struct_vader_midir$CFGFunction_t*) l3)->f_return_type;
    l18 = ((vader_struct_vader_midir$CFGFunction_t*) l3)->f_entry;
    l8 = ((vader_struct_vader_midir$CFGFunction_t*) l3)->f_origin;
    l3 = ((vader_struct_vader_midir$CFGFunction_t*) l3)->f_scalarised_results;
    vader_struct_vader_midir$CFGFunction_t* _a31_obj = (vader_struct_vader_midir$CFGFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$CFGFunction_t));
    vader_obj_header_init(_a31_obj, 1306u);
    _a31_obj->f_mangled = l19;
    _a31_obj->f_params = l2;
    _a31_obj->f_return_type = l11;
    _a31_obj->f_locals = l4;
    _a31_obj->f_blocks = l7;
    _a31_obj->f_entry = l18;
    _a31_obj->f_origin = l8;
    _a31_obj->f_scalarised_results = l3;
    t0 = (void*) _a31_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir_optimise$compute_carried_across_loop_headers(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    void* l22 = NULL;
    void* l24 = NULL;
    void* l29 = NULL;
    void* l35 = NULL;
    void* l37 = NULL;
    void* l38 = NULL;
    int64_t l8, l9, l19, l20, l25, l26, l30, l31, l39, l40;
    int32_t l10, l11, l21, l23, l32, l34, l36, l41;
    vader_box_t l12 = vader_box_null(), l27 = vader_box_null(), l28 = vader_box_null(), l33 = vader_box_null();
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[4] = { &l12, &l27, &l28, &l33 };
    void** gc_raw_roots[21] = {
        &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l13, &l14, &l15, &l16, &l17, &l18, &l22, &l24,
        &l29, &l35, &l37, &l38, &t0,
    };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 21u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 7u, 338u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(19u, 0u, 12u, 333u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections$MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 462u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections$MutableSet__i32_t* _a4_obj = (vader_struct_std_collections$MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 605u);
    _a4_obj->f_inner = t0;
    l2 = (void*) _a4_obj;
    l3 = vader_midir$predecessors_of(l0);
    l4 = vader_midir$compute_dominators(l0, l3);
    l3 = vader_midir$natural_loop_bodies(l0, l3, l4);
    t1 = std_collections$is_empty__i32__Any(l3);
    if (t1) {
        { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = vader_midir$compute_liveness(l0);
    l5 = l3;
    l6 = ((vader_struct_std_collections$MutableMap__i32__std_collections_MutableSet_i32__t*) l5)->f_ekeys;
    l7 = ((vader_struct_std_collections$MutableMap__i32__std_collections_MutableSet_i32__t*) l5)->f_evals;
    l8 = INT64_C(0);
    l9 = ((vader_struct_std_collections$MutableMap__i32__std_collections_MutableSet_i32__t*) l5)->f_size;
    while ((l8 < l9)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l8)
        l10 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l8];
        vader_array_t* _a6_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l8)
        t0 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l8);
        l11 = l10;
        l12 = std_collections$MutableMap$std_core$Index$at__i32__Any(l3, l11);
        if (!(l12.tag == 0u)) {
            l5 = l12.payload.obj;
            vader_array_t* _a7_arr = vader_array_new(22u, 0u, 7u, 338u);
            l13 = (void*) _a7_arr;
            vader_array_t* _a8_arr = vader_array_new(19u, 0u, 12u, 333u);
            l14 = (void*) _a8_arr;
            vader_array_t* _a9_arr = vader_array_new(22u, 0u, 7u, 338u);
            l15 = (void*) _a9_arr;
            vader_struct_std_collections$MutableMap__i32__bool_t* _a10_obj = (vader_struct_std_collections$MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__bool_t));
            vader_obj_header_init(_a10_obj, 462u);
            _a10_obj->f_ekeys = l13;
            _a10_obj->f_evals = l14;
            _a10_obj->f_index = l15;
            _a10_obj->f_mask = INT64_C(0);
            _a10_obj->f_grow_at = INT64_C(0);
            _a10_obj->f_size = INT64_C(0);
            _a10_obj->f_tombs = INT64_C(0);
            t0 = (void*) _a10_obj;
            vader_struct_std_collections$MutableSet__i32_t* _a11_obj = (vader_struct_std_collections$MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__i32_t));
            vader_obj_header_init(_a11_obj, 605u);
            _a11_obj->f_inner = t0;
            l16 = (void*) _a11_obj;
            l17 = l5;
            l18 = ((vader_struct_std_collections$MutableMap__i32__bool_t*) ((vader_struct_std_collections$MutableSet__i32_t*) l17)->f_inner)->f_ekeys;
            l19 = INT64_C(0);
            l20 = ((vader_struct_std_collections$MutableMap__i32__bool_t*) ((vader_struct_std_collections$MutableSet__i32_t*) l17)->f_inner)->f_size;
            while ((l19 < l20)) {
                vader_array_t* _a12_slotarr = ((vader_array_t*) l18);
                VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l19)
                l21 = ((int32_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l19];
                l22 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks;
                l23 = l21;
                vader_array_t* _a13_slotarr = ((vader_array_t*) l22);
                VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l23)
                t0 = vader_array_ref_load_obj(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l23);
                l24 = ((vader_struct_vader_midir$BasicBlock_t*) t0)->f_instructions;
                l25 = ((vader_array_t*) l24)->length;
                l26 = INT64_C(0);
                while ((l26 < l25)) {
                    vader_array_t* _a14_slotarr = ((vader_array_t*) l24);
                    VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
                    l27 = vader_array_ref_load_box(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l26);
                    l28 = vader_midir$multi_dsts(l27);
                    if (l28.tag == 0u) {
                        l33 = vader_midir$dst_of(l27);
                        if (!(l33.tag == 0u)) {
                            l34 = ((int32_t) l33.payload.i);
                            std_collections$add__vader_midir$LocalId(l16, l34);
                        }
                    } else {
                        l29 = l28.payload.obj;
                        l30 = ((vader_array_t*) l29)->length;
                        l31 = INT64_C(0);
                        while ((l31 < l30)) {
                            vader_array_t* _a15_slotarr = ((vader_array_t*) l29);
                            VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
                            l32 = ((int32_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l31];
                            std_collections$add__vader_midir$LocalId(l16, l32);
                            l31 = (l31 + INT64_C(1));
                        }
                    }
                    l26 = (l26 + INT64_C(1));
                }
                l19 = (l19 + INT64_C(1));
            }
            l35 = ((vader_struct_vader_midir$Liveness_t*) l4)->f_live_in;
            l36 = l11;
            vader_array_t* _a16_slotarr = ((vader_array_t*) l35);
            VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l36)
            l37 = vader_array_ref_load_obj(_a16_slotarr->buf, _a16_slotarr->offset + (size_t) l36);
            l38 = ((vader_struct_std_collections$MutableMap__i32__bool_t*) ((vader_struct_std_collections$MutableSet__i32_t*) l37)->f_inner)->f_ekeys;
            l39 = INT64_C(0);
            l40 = ((vader_struct_std_collections$MutableMap__i32__bool_t*) ((vader_struct_std_collections$MutableSet__i32_t*) l37)->f_inner)->f_size;
            while ((l39 < l40)) {
                vader_array_t* _a17_slotarr = ((vader_array_t*) l38);
                VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l39)
                l41 = ((int32_t*) _a17_slotarr->buf->slots)[_a17_slotarr->offset + (size_t) l39];
                t1 = std_collections$MutableSet$std_core$Contains$contains__i32(l16, l41);
                if (t1) {
                    std_collections$add__vader_midir$LocalId(l2, l41);
                }
                l39 = (l39 + INT64_C(1));
            }
        }
        l8 = (l8 + INT64_C(1));
    }
    vader_array_t* _a18_arr = vader_array_new(22u, 0u, 7u, 338u);
    l3 = (void*) _a18_arr;
    l9 = ((vader_struct_std_collections$MutableMap__i32__bool_t*) ((vader_struct_std_collections$MutableSet__i32_t*) l2)->f_inner)->f_size;
    if ((INT64_C(0) < l9)) {
        l8 = ((vader_struct_std_collections$MutableMap__i32__bool_t*) ((vader_struct_std_collections$MutableSet__i32_t*) l2)->f_inner)->f_size;
    } else {
        l8 = INT64_C(0);
    }
    vader_array_t* _a19_arr = vader_array_repeat((vader_array_t*) l3, (int64_t) l8);
    l3 = (void*) _a19_arr;
    l4 = l2;
    l5 = ((vader_struct_std_collections$MutableMap__i32__bool_t*) ((vader_struct_std_collections$MutableSet__i32_t*) l4)->f_inner)->f_ekeys;
    l8 = INT64_C(0);
    l9 = ((vader_struct_std_collections$MutableMap__i32__bool_t*) ((vader_struct_std_collections$MutableSet__i32_t*) l4)->f_inner)->f_size;
    vader_array_t* _pc274_hdr = (vader_array_t*) l3;
    size_t _pc274_len = _pc274_hdr->length;
    size_t _pc274_cap = (_pc274_hdr->offset == 0 && !vader_array_is_borrowed(_pc274_hdr) && _pc274_hdr->length >= _pc274_hdr->buf->length) ? _pc274_hdr->capacity : (size_t) 0;
    void* _pc274_slots = _pc274_hdr->buf->slots;
    for (;;) {
        if ((l8 < l9)) {
            vader_array_t* _a20_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a20_slotarr, l8)
            l10 = ((int32_t*) _a20_slotarr->buf->slots)[_a20_slotarr->offset + (size_t) l8];
            if (VADER_LIKELY(_pc274_len < _pc274_cap)) {
                ((int32_t*) _pc274_slots)[_pc274_len] = (int32_t) (l10);
                _pc274_len += 1;
            } else {
                _pc274_hdr->length = _pc274_len;
                if (_pc274_hdr->buf->length < _pc274_len) {
                    _pc274_hdr->buf->length = _pc274_len;
                }
                vader_array_push_i32((vader_array_t*) l3, l10);
                _pc274_hdr = (vader_array_t*) l3;
                _pc274_len = _pc274_hdr->length;
                _pc274_cap = (_pc274_hdr->offset == 0 && !vader_array_is_borrowed(_pc274_hdr) && _pc274_hdr->length >= _pc274_hdr->buf->length) ? _pc274_hdr->capacity : (size_t) 0;
                _pc274_slots = _pc274_hdr->buf->slots;
            }
            l8 = (l8 + INT64_C(1));
            continue;
        }
        _pc274_hdr->length = _pc274_len;
        if (_pc274_hdr->buf->length < _pc274_len) {
            _pc274_hdr->buf->length = _pc274_len;
        }
        break;
    }
    for (;;) {
        l12 = vader_array_remove_last((vader_array_t*) l3);
        if (!(l12.tag == 0u)) {
            l10 = ((int32_t) l12.payload.i);
            l27 = std_collections$MutableMap$std_core$Index$at__i32__Any(l1, l10);
            if (l27.tag == 0u) {
                continue;
            }
            l4 = l27.payload.obj;
            l8 = ((vader_array_t*) l4)->length;
            l9 = INT64_C(0);
            while ((l9 < l8)) {
                vader_array_t* _a21_slotarr = ((vader_array_t*) l4);
                VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
                l11 = ((int32_t*) _a21_slotarr->buf->slots)[_a21_slotarr->offset + (size_t) l9];
                t1 = std_collections$add__vader_midir$LocalId(l2, l11);
                if (t1) {
                    vader_array_push_i32((vader_array_t*) l3, l11);
                }
                l9 = (l9 + INT64_C(1));
            }
            continue;
        }
        break;
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir_optimise$compute_escaping(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l9 = NULL;
    void* l29 = NULL;
    void* l34 = NULL;
    void* l39 = NULL;
    void* l43 = NULL;
    void* l48 = NULL;
    void* l53 = NULL;
    void* l61 = NULL;
    int64_t l7, l8, l10, l11, l30, l31, l35, l36, l40, l41, l44, l45, l49, l50, l54, l55, l62, l63;
    vader_box_t l12 = vader_box_null(), l60 = vader_box_null();
    int32_t l13, l14, l15, l16, l17, l18, l19, l20, l21, l22, l23, l24, l25, l26, l27, l28, l32, l33, l37, l38, l42, l46, l47, l51, l52, l56, l57, l58, l59, l64;
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[2] = { &l12, &l60 };
    void** gc_raw_roots[16] = {
        &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l9, &l29, &l34, &l39, &l43, &l48, &l53, &l61, &t0,
    };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 16u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 7u, 338u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(19u, 0u, 12u, 333u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections$MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 462u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections$MutableSet__i32_t* _a4_obj = (vader_struct_std_collections$MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 605u);
    _a4_obj->f_inner = t0;
    l2 = (void*) _a4_obj;
    vader_array_t* _a5_arr = vader_array_new(22u, 0u, 7u, 338u);
    l3 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(28u, 0u, 0u, 346u);
    l4 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(22u, 0u, 7u, 338u);
    l5 = (void*) _a7_arr;
    vader_struct_std_collections$MutableMap__i32__Any___t* _a8_obj = (vader_struct_std_collections$MutableMap__i32__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__Any___t));
    vader_obj_header_init(_a8_obj, 460u);
    _a8_obj->f_ekeys = l3;
    _a8_obj->f_evals = l4;
    _a8_obj->f_index = l5;
    _a8_obj->f_mask = INT64_C(0);
    _a8_obj->f_grow_at = INT64_C(0);
    _a8_obj->f_size = INT64_C(0);
    _a8_obj->f_tombs = INT64_C(0);
    l3 = (void*) _a8_obj;
    vader_array_t* _a9_arr = vader_array_new(22u, 0u, 7u, 338u);
    l4 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(28u, 0u, 0u, 346u);
    l5 = (void*) _a10_arr;
    vader_array_t* _a11_arr = vader_array_new(22u, 0u, 7u, 338u);
    l6 = (void*) _a11_arr;
    vader_struct_std_collections$MutableMap__i32__Any___t* _a12_obj = (vader_struct_std_collections$MutableMap__i32__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__Any___t));
    vader_obj_header_init(_a12_obj, 460u);
    _a12_obj->f_ekeys = l4;
    _a12_obj->f_evals = l5;
    _a12_obj->f_index = l6;
    _a12_obj->f_mask = INT64_C(0);
    _a12_obj->f_grow_at = INT64_C(0);
    _a12_obj->f_size = INT64_C(0);
    _a12_obj->f_tombs = INT64_C(0);
    l4 = (void*) _a12_obj;
    l5 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks;
    l7 = ((vader_array_t*) l5)->length;
    l8 = INT64_C(0);
    while ((l8 < l7)) {
        vader_array_t* _a13_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
        l6 = vader_array_ref_load_obj(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l8);
        l9 = ((vader_struct_vader_midir$BasicBlock_t*) l6)->f_instructions;
        l10 = ((vader_array_t*) l9)->length;
        l11 = INT64_C(0);
        while ((l11 < l10)) {
            vader_array_t* _a14_slotarr = ((vader_array_t*) l9);
            VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
            l12 = vader_array_ref_load_box(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l11);
            if (l12.tag == 1353u) {
                t0 = l12.payload.obj;
                l13 = ((vader_struct_vader_midir$InstrMove_t*) t0)->f_dst;
                t0 = l12.payload.obj;
                l14 = ((vader_struct_vader_midir$InstrMove_t*) t0)->f_src;
                vader_midir_optimise$record_alias(l3, l4, l13, l14);
            } else if (l12.tag == 1337u) {
                t0 = l12.payload.obj;
                l15 = ((vader_struct_vader_midir$InstrCast_t*) t0)->f_dst;
                t0 = l12.payload.obj;
                l16 = ((vader_struct_vader_midir$InstrCast_t*) t0)->f_value;
                vader_midir_optimise$record_alias(l3, l4, l15, l16);
            } else if ((l12.tag == 1346u || l12.tag == 1359u)) {
                l17 = VADER_UNION_FIELD(int32_t, vader_struct_vader_midir$InstrFieldSet_t, f_value, l12.payload.obj);
                std_collections$add__vader_midir$LocalId(l2, l17);
            } else if (l12.tag == 1332u) {
                t0 = l12.payload.obj;
                l18 = ((vader_struct_vader_midir$InstrArraySet_t*) t0)->f_value;
                std_collections$add__vader_midir$LocalId(l2, l18);
                t0 = l12.payload.obj;
                l19 = ((vader_struct_vader_midir$InstrArraySet_t*) t0)->f_target;
                std_collections$add__vader_midir$LocalId(l2, l19);
            } else if (l12.tag == 1331u) {
                t0 = l12.payload.obj;
                l20 = ((vader_struct_vader_midir$InstrArrayPush_t*) t0)->f_value;
                std_collections$add__vader_midir$LocalId(l2, l20);
                t0 = l12.payload.obj;
                l21 = ((vader_struct_vader_midir$InstrArrayPush_t*) t0)->f_target;
                std_collections$add__vader_midir$LocalId(l2, l21);
            } else if (l12.tag == 1333u) {
                t0 = l12.payload.obj;
                l22 = ((vader_struct_vader_midir$InstrArraySlice_t*) t0)->f_target;
                std_collections$add__vader_midir$LocalId(l2, l22);
                t0 = l12.payload.obj;
                l23 = ((vader_struct_vader_midir$InstrArraySlice_t*) t0)->f_lo;
                std_collections$add__vader_midir$LocalId(l2, l23);
                t0 = l12.payload.obj;
                l24 = ((vader_struct_vader_midir$InstrArraySlice_t*) t0)->f_hi;
                std_collections$add__vader_midir$LocalId(l2, l24);
            } else if (l12.tag == 1339u) {
                t0 = l12.payload.obj;
                l25 = ((vader_struct_vader_midir$InstrCellNew_t*) t0)->f_value;
                std_collections$add__vader_midir$LocalId(l2, l25);
            } else if (l12.tag == 1340u) {
                t0 = l12.payload.obj;
                l26 = ((vader_struct_vader_midir$InstrCellSet_t*) t0)->f_value;
                std_collections$add__vader_midir$LocalId(l2, l26);
                t0 = l12.payload.obj;
                l27 = ((vader_struct_vader_midir$InstrCellSet_t*) t0)->f_cell;
                std_collections$add__vader_midir$LocalId(l2, l27);
            } else if (l12.tag == 1350u) {
                t0 = l12.payload.obj;
                l28 = ((vader_struct_vader_midir$InstrGlobalSet_t*) t0)->f_value;
                std_collections$add__vader_midir$LocalId(l2, l28);
            } else if (l12.tag == 1335u) {
                t0 = l12.payload.obj;
                l29 = ((vader_struct_vader_midir$InstrCall_t*) t0)->f_args;
                l30 = ((vader_array_t*) l29)->length;
                l31 = INT64_C(0);
                while ((l31 < l30)) {
                    vader_array_t* _a15_slotarr = ((vader_array_t*) l29);
                    VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
                    l32 = ((int32_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l31];
                    std_collections$add__vader_midir$LocalId(l2, l32);
                    l31 = (l31 + INT64_C(1));
                }
            } else if (l12.tag == 1336u) {
                t0 = l12.payload.obj;
                l33 = ((vader_struct_vader_midir$InstrCallIndirect_t*) t0)->f_callee;
                std_collections$add__vader_midir$LocalId(l2, l33);
                t0 = l12.payload.obj;
                l34 = ((vader_struct_vader_midir$InstrCallIndirect_t*) t0)->f_args;
                l35 = ((vader_array_t*) l34)->length;
                l36 = INT64_C(0);
                while ((l36 < l35)) {
                    vader_array_t* _a16_slotarr = ((vader_array_t*) l34);
                    VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
                    l37 = ((int32_t*) _a16_slotarr->buf->slots)[_a16_slotarr->offset + (size_t) l36];
                    std_collections$add__vader_midir$LocalId(l2, l37);
                    l36 = (l36 + INT64_C(1));
                }
            } else if (l12.tag == 1360u) {
                t0 = l12.payload.obj;
                l38 = ((vader_struct_vader_midir$InstrVirtualCall_t*) t0)->f_receiver;
                std_collections$add__vader_midir$LocalId(l2, l38);
                t0 = l12.payload.obj;
                l39 = ((vader_struct_vader_midir$InstrVirtualCall_t*) t0)->f_args;
                l40 = ((vader_array_t*) l39)->length;
                l41 = INT64_C(0);
                while ((l41 < l40)) {
                    vader_array_t* _a17_slotarr = ((vader_array_t*) l39);
                    VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
                    l42 = ((int32_t*) _a17_slotarr->buf->slots)[_a17_slotarr->offset + (size_t) l41];
                    std_collections$add__vader_midir$LocalId(l2, l42);
                    l41 = (l41 + INT64_C(1));
                }
            } else if (l12.tag == 1351u) {
                t0 = l12.payload.obj;
                l43 = ((vader_struct_vader_midir$InstrIntrinsic_t*) t0)->f_args;
                l44 = ((vader_array_t*) l43)->length;
                l45 = INT64_C(0);
                while ((l45 < l44)) {
                    vader_array_t* _a18_slotarr = ((vader_array_t*) l43);
                    VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
                    l46 = ((int32_t*) _a18_slotarr->buf->slots)[_a18_slotarr->offset + (size_t) l45];
                    std_collections$add__vader_midir$LocalId(l2, l46);
                    l45 = (l45 + INT64_C(1));
                }
            } else if (l12.tag == 1352u) {
                t0 = l12.payload.obj;
                l47 = ((vader_struct_vader_midir$InstrMakeClosure_t*) t0)->f_env;
                std_collections$add__vader_midir$LocalId(l2, l47);
            } else if (l12.tag == 1354u) {
                t0 = l12.payload.obj;
                l48 = ((vader_struct_vader_midir$InstrStructNew_t*) t0)->f_fields;
                l49 = ((vader_array_t*) l48)->length;
                l50 = INT64_C(0);
                while ((l50 < l49)) {
                    vader_array_t* _a19_slotarr = ((vader_array_t*) l48);
                    VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
                    l51 = ((int32_t*) _a19_slotarr->buf->slots)[_a19_slotarr->offset + (size_t) l50];
                    t0 = l12.payload.obj;
                    l52 = ((vader_struct_vader_midir$InstrStructNew_t*) t0)->f_dst;
                    vader_midir_optimise$append_alias(l3, l52, l51);
                    l50 = (l50 + INT64_C(1));
                }
            } else if (l12.tag == 1330u) {
                t0 = l12.payload.obj;
                l53 = ((vader_struct_vader_midir$InstrArrayNew_t*) t0)->f_elements;
                l54 = ((vader_array_t*) l53)->length;
                l55 = INT64_C(0);
                while ((l55 < l54)) {
                    vader_array_t* _a20_slotarr = ((vader_array_t*) l53);
                    VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
                    l56 = ((int32_t*) _a20_slotarr->buf->slots)[_a20_slotarr->offset + (size_t) l55];
                    t0 = l12.payload.obj;
                    l57 = ((vader_struct_vader_midir$InstrArrayNew_t*) t0)->f_dst;
                    vader_midir_optimise$append_alias(l3, l57, l56);
                    l55 = (l55 + INT64_C(1));
                }
            } else if ((l12.tag == 1328u || l12.tag == 1345u || l12.tag == 1358u)) {
                t1 = vader_midir_optimise$read_may_carry_ref(VADER_UNION_FIELD(vader_box_t, vader_struct_vader_midir$InstrArrayGet_t, f_type, l12.payload.obj));
                if (t1) {
                    l58 = VADER_UNION_FIELD(int32_t, vader_struct_vader_midir$InstrArrayGet_t, f_dst, l12.payload.obj);
                    l59 = VADER_UNION_FIELD(int32_t, vader_struct_vader_midir$InstrArrayGet_t, f_target, l12.payload.obj);
                    vader_midir_optimise$append_alias(l3, l58, l59);
                }
            }
            l11 = (l11 + INT64_C(1));
        }
        l60 = ((vader_struct_vader_midir$BasicBlock_t*) l6)->f_terminator;
        if (l60.tag == 1372u) {
            t0 = l60.payload.obj;
            l61 = ((vader_struct_vader_midir$TermReturn_t*) t0)->f_values;
            l62 = ((vader_array_t*) l61)->length;
            l63 = INT64_C(0);
            while ((l63 < l62)) {
                vader_array_t* _a21_slotarr = ((vader_array_t*) l61);
                VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
                l64 = ((int32_t*) _a21_slotarr->buf->slots)[_a21_slotarr->offset + (size_t) l63];
                std_collections$add__vader_midir$LocalId(l2, l64);
                l63 = (l63 + INT64_C(1));
            }
        }
        l8 = (l8 + INT64_C(1));
    }
    vader_array_t* _a22_arr = vader_array_new(22u, 0u, 7u, 338u);
    l5 = (void*) _a22_arr;
    l8 = ((vader_struct_std_collections$MutableMap__i32__bool_t*) ((vader_struct_std_collections$MutableSet__i32_t*) l2)->f_inner)->f_size;
    if ((INT64_C(0) < l8)) {
        l7 = ((vader_struct_std_collections$MutableMap__i32__bool_t*) ((vader_struct_std_collections$MutableSet__i32_t*) l2)->f_inner)->f_size;
    } else {
        l7 = INT64_C(0);
    }
    vader_array_t* _a23_arr = vader_array_repeat((vader_array_t*) l5, (int64_t) l7);
    l5 = (void*) _a23_arr;
    l6 = l2;
    l9 = ((vader_struct_std_collections$MutableMap__i32__bool_t*) ((vader_struct_std_collections$MutableSet__i32_t*) l6)->f_inner)->f_ekeys;
    l7 = INT64_C(0);
    l8 = ((vader_struct_std_collections$MutableMap__i32__bool_t*) ((vader_struct_std_collections$MutableSet__i32_t*) l6)->f_inner)->f_size;
    vader_array_t* _pc575_hdr = (vader_array_t*) l5;
    size_t _pc575_len = _pc575_hdr->length;
    size_t _pc575_cap = (_pc575_hdr->offset == 0 && !vader_array_is_borrowed(_pc575_hdr) && _pc575_hdr->length >= _pc575_hdr->buf->length) ? _pc575_hdr->capacity : (size_t) 0;
    void* _pc575_slots = _pc575_hdr->buf->slots;
    for (;;) {
        if ((l7 < l8)) {
            vader_array_t* _a24_slotarr = ((vader_array_t*) l9);
            VADER_ARRAY_RESOLVE_BUF(_a24_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a24_slotarr, l7)
            l13 = ((int32_t*) _a24_slotarr->buf->slots)[_a24_slotarr->offset + (size_t) l7];
            if (VADER_LIKELY(_pc575_len < _pc575_cap)) {
                ((int32_t*) _pc575_slots)[_pc575_len] = (int32_t) (l13);
                _pc575_len += 1;
            } else {
                _pc575_hdr->length = _pc575_len;
                if (_pc575_hdr->buf->length < _pc575_len) {
                    _pc575_hdr->buf->length = _pc575_len;
                }
                vader_array_push_i32((vader_array_t*) l5, l13);
                _pc575_hdr = (vader_array_t*) l5;
                _pc575_len = _pc575_hdr->length;
                _pc575_cap = (_pc575_hdr->offset == 0 && !vader_array_is_borrowed(_pc575_hdr) && _pc575_hdr->length >= _pc575_hdr->buf->length) ? _pc575_hdr->capacity : (size_t) 0;
                _pc575_slots = _pc575_hdr->buf->slots;
            }
            l7 = (l7 + INT64_C(1));
            continue;
        }
        _pc575_hdr->length = _pc575_len;
        if (_pc575_hdr->buf->length < _pc575_len) {
            _pc575_hdr->buf->length = _pc575_len;
        }
        break;
    }
    for (;;) {
        l12 = vader_array_remove_last((vader_array_t*) l5);
        if (!(l12.tag == 0u)) {
            l13 = ((int32_t) l12.payload.i);
            l60 = std_collections$MutableMap$std_core$Index$at__i32__Any(l3, l13);
            if (l60.tag == 0u) {
                continue;
            }
            l6 = l60.payload.obj;
            l7 = ((vader_array_t*) l6)->length;
            l8 = INT64_C(0);
            while ((l8 < l7)) {
                vader_array_t* _a25_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
                l14 = ((int32_t*) _a25_slotarr->buf->slots)[_a25_slotarr->offset + (size_t) l8];
                t1 = std_collections$add__vader_midir$LocalId(l2, l14);
                if (t1) {
                    vader_array_push_i32((vader_array_t*) l5, l14);
                }
                l8 = (l8 + INT64_C(1));
            }
            continue;
        }
        break;
    }
    vader_array_t* _a26_arr = vader_array_new(22u, 0u, 7u, 338u);
    l5 = (void*) _a26_arr;
    vader_array_t* _a27_arr = vader_array_new(19u, 0u, 12u, 333u);
    l6 = (void*) _a27_arr;
    vader_array_t* _a28_arr = vader_array_new(22u, 0u, 7u, 338u);
    l9 = (void*) _a28_arr;
    vader_struct_std_collections$MutableMap__i32__bool_t* _a29_obj = (vader_struct_std_collections$MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__bool_t));
    vader_obj_header_init(_a29_obj, 462u);
    _a29_obj->f_ekeys = l5;
    _a29_obj->f_evals = l6;
    _a29_obj->f_index = l9;
    _a29_obj->f_mask = INT64_C(0);
    _a29_obj->f_grow_at = INT64_C(0);
    _a29_obj->f_size = INT64_C(0);
    _a29_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a29_obj;
    vader_struct_std_collections$MutableSet__i32_t* _a30_obj = (vader_struct_std_collections$MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__i32_t));
    vader_obj_header_init(_a30_obj, 605u);
    _a30_obj->f_inner = t0;
    l5 = (void*) _a30_obj;
    l6 = l1;
    l9 = ((vader_struct_std_collections$MutableMap__i32__bool_t*) ((vader_struct_std_collections$MutableSet__i32_t*) l6)->f_inner)->f_ekeys;
    l7 = INT64_C(0);
    l8 = ((vader_struct_std_collections$MutableMap__i32__bool_t*) ((vader_struct_std_collections$MutableSet__i32_t*) l6)->f_inner)->f_size;
    while ((l7 < l8)) {
        vader_array_t* _a31_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a31_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a31_slotarr, l7)
        l13 = ((int32_t*) _a31_slotarr->buf->slots)[_a31_slotarr->offset + (size_t) l7];
        t1 = std_collections$MutableSet$std_core$Contains$contains__i32(l2, l13);
        if (t1) {
            std_collections$add__vader_midir$LocalId(l5, l13);
        }
        l7 = (l7 + INT64_C(1));
    }
    vader_struct_vader_midir_optimise$EscapeResult_t* _a32_obj = (vader_struct_vader_midir_optimise$EscapeResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_optimise$EscapeResult_t));
    vader_obj_header_init(_a32_obj, 1376u);
    _a32_obj->f_escaping = l5;
    _a32_obj->f_alias_of = l3;
    _a32_obj->f_alias_from = l4;
    t0 = (void*) _a32_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir_optimise$drop_slots_using(void* l0, int32_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    int64_t l4, l5;
    bool t0;
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(212u, 0u, 13u, 1379u);
    l2 = (void*) _a0_arr;
    l3 = l0;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l6 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
        t0 = vader_midir$LocalId$std_core$Equals$equals(((vader_struct_vader_midir_optimise$SlotVal_t*) l6)->f_target, l1);
        if (!(t0)) {
            t0 = vader_midir$LocalId$std_core$Equals$equals(((vader_struct_vader_midir_optimise$SlotVal_t*) l6)->f_index, l1);
            if (!(t0)) {
                t0 = vader_midir$LocalId$std_core$Equals$equals(((vader_struct_vader_midir_optimise$SlotVal_t*) l6)->f_value, l1);
                if (!(t0)) {
                    vader_array_push_ref((vader_array_t*) l2, l6);
                }
            }
        }
        l5 = (l5 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_midir_optimise$eliminate_dead_cfg(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    void* l20 = NULL;
    void* l21 = NULL;
    void* l22 = NULL;
    int64_t l5, l6, l11, l14, l15;
    vader_string_t l7 = 0;
    vader_string_t l8 = 0;
    vader_string_t l18 = 0;
    vader_string_t l19 = 0;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[15] = {
        &l0, &l1, &l2, &l3, &l4, &l9, &l10, &l12, &l13, &l16, &l17, &l20, &l21, &l22, &t1,
    };
    vader_string_t* gc_atom_roots[4] = { &l7, &l8, &l18, &l19 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 15u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 335u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 346u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections$MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 533u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l1 = (void*) _a3_obj;
    l2 = ((vader_struct_vader_midir$CFGProject_t*) l0)->f_modules;
    l3 = ((vader_struct_std_collections$MutableMap__string__vader_midir_CFGModule_t*) l2)->f_ekeys;
    l4 = ((vader_struct_std_collections$MutableMap__string__vader_midir_CFGModule_t*) l2)->f_evals;
    l5 = INT64_C(0);
    l6 = ((vader_struct_std_collections$MutableMap__string__vader_midir_CFGModule_t*) l2)->f_size;
    while ((l5 < l6)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
        t0 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l5];
        l7 = t0.payload.s;
        vader_array_t* _a5_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
        l2 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l5);
        l8 = l7;
        l9 = l2;
        vader_array_t* _a6_arr = vader_array_new(203u, 0u, 13u, 1306u);
        l10 = (void*) _a6_arr;
        l11 = ((vader_array_t*) ((vader_struct_vader_midir$CFGModule_t*) l9)->f_functions)->length;
        vader_array_t* _a7_arr = vader_array_repeat((vader_array_t*) l10, (int64_t) l11);
        l12 = (void*) _a7_arr;
        l13 = ((vader_struct_vader_midir$CFGModule_t*) l9)->f_functions;
        l14 = ((vader_array_t*) l13)->length;
        l15 = INT64_C(0);
        while ((l15 < l14)) {
            vader_array_t* _a8_slotarr = ((vader_array_t*) l13);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l15)
            t1 = vader_array_ref_load_obj(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l15);
            l16 = vader_midir_optimise$optimise_function(t1);
            vader_array_push_ref((vader_array_t*) l12, l16);
            l15 = (l15 + INT64_C(1));
        }
        l17 = l9;
        l18 = ((vader_struct_vader_midir$CFGModule_t*) l17)->f_module_id;
        l19 = ((vader_struct_vader_midir$CFGModule_t*) l17)->f_display_path;
        l20 = ((vader_struct_vader_midir$CFGModule_t*) l17)->f_externs;
        l21 = ((vader_struct_vader_midir$CFGModule_t*) l17)->f_struct_decls;
        vader_struct_vader_midir$CFGModule_t* _a9_obj = (vader_struct_vader_midir$CFGModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$CFGModule_t));
        vader_obj_header_init(_a9_obj, 1308u);
        _a9_obj->f_module_id = l18;
        _a9_obj->f_display_path = l19;
        _a9_obj->f_functions = l12;
        _a9_obj->f_externs = l20;
        _a9_obj->f_struct_decls = l21;
        l22 = (void*) _a9_obj;
        std_collections$MutableMap$std_core$IndexSet$set_at__string__Any(l1, l8, vader_ref_box(l22));
        l5 = (l5 + INT64_C(1));
    }
    l2 = l0;
    l3 = ((vader_struct_vader_midir$CFGProject_t*) l2)->f_vtable_entries;
    l4 = ((vader_struct_vader_midir$CFGProject_t*) l2)->f_strings;
    l9 = ((vader_struct_vader_midir$CFGProject_t*) l2)->f_data_pool;
    l10 = ((vader_struct_vader_midir$CFGProject_t*) l2)->f_globals;
    l2 = ((vader_struct_vader_midir$CFGProject_t*) l2)->f_trait_membership;
    vader_struct_vader_midir$CFGProject_t* _a10_obj = (vader_struct_vader_midir$CFGProject_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$CFGProject_t));
    vader_obj_header_init(_a10_obj, 1310u);
    _a10_obj->f_modules = l1;
    _a10_obj->f_vtable_entries = l3;
    _a10_obj->f_strings = l4;
    _a10_obj->f_data_pool = l9;
    _a10_obj->f_globals = l10;
    _a10_obj->f_trait_membership = l2;
    t1 = (void*) _a10_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir_optimise$fold_moves(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    int64_t l5, l6;
    int32_t l7;
    vader_box_t l12 = vader_box_null();
    vader_string_t l15 = 0;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l12 };
    void** gc_raw_roots[12] = { &l0, &l1, &l2, &l3, &l4, &l8, &l9, &l10, &l11, &l13, &l14, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l15 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_midir$count_uses(l0);
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 7u, 338u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(19u, 0u, 12u, 333u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections$MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 462u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections$MutableSet__i32_t* _a4_obj = (vader_struct_std_collections$MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 605u);
    _a4_obj->f_inner = t0;
    l2 = (void*) _a4_obj;
    l3 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_params;
    l5 = ((vader_array_t*) l3)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        t0 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l6);
        l7 = ((vader_struct_vader_midir$CFGParam_t*) t0)->f_local;
        std_collections$add__vader_midir$LocalId(l2, l7);
        l6 = (l6 + INT64_C(1));
    }
    vader_array_t* _a6_arr = vader_array_new(201u, 0u, 13u, 1304u);
    l3 = (void*) _a6_arr;
    l5 = ((vader_array_t*) ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks)->length;
    vader_array_t* _a7_arr = vader_array_repeat((vader_array_t*) l3, (int64_t) l5);
    l3 = (void*) _a7_arr;
    l4 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks;
    l5 = ((vader_array_t*) l4)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a8_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l6)
        l8 = vader_array_ref_load_obj(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l6);
        l9 = l8;
        l7 = ((vader_struct_vader_midir$BasicBlock_t*) l9)->f_id;
        l10 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_locals;
        l11 = vader_midir_optimise$fold_moves_in_block(l8, l10, l1, l2);
        l12 = ((vader_struct_vader_midir$BasicBlock_t*) l9)->f_terminator;
        l13 = ((vader_struct_vader_midir$BasicBlock_t*) l9)->f_span;
        vader_struct_vader_midir$BasicBlock_t* _a9_obj = (vader_struct_vader_midir$BasicBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$BasicBlock_t));
        vader_obj_header_init(_a9_obj, 1304u);
        _a9_obj->f_id = l7;
        _a9_obj->f_instructions = l11;
        _a9_obj->f_terminator = l12;
        _a9_obj->f_span = l13;
        l14 = (void*) _a9_obj;
        vader_array_push_ref((vader_array_t*) l3, l14);
        l6 = (l6 + INT64_C(1));
    }
    l1 = l0;
    l15 = ((vader_struct_vader_midir$CFGFunction_t*) l1)->f_mangled;
    l2 = ((vader_struct_vader_midir$CFGFunction_t*) l1)->f_params;
    l12 = ((vader_struct_vader_midir$CFGFunction_t*) l1)->f_return_type;
    l4 = ((vader_struct_vader_midir$CFGFunction_t*) l1)->f_locals;
    l7 = ((vader_struct_vader_midir$CFGFunction_t*) l1)->f_entry;
    l8 = ((vader_struct_vader_midir$CFGFunction_t*) l1)->f_origin;
    l1 = ((vader_struct_vader_midir$CFGFunction_t*) l1)->f_scalarised_results;
    vader_struct_vader_midir$CFGFunction_t* _a10_obj = (vader_struct_vader_midir$CFGFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$CFGFunction_t));
    vader_obj_header_init(_a10_obj, 1306u);
    _a10_obj->f_mangled = l15;
    _a10_obj->f_params = l2;
    _a10_obj->f_return_type = l12;
    _a10_obj->f_locals = l4;
    _a10_obj->f_blocks = l3;
    _a10_obj->f_entry = l7;
    _a10_obj->f_origin = l8;
    _a10_obj->f_scalarised_results = l1;
    t0 = (void*) _a10_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir_optimise$fold_moves_in_block(void* l0, void* l1, void* l2, void* l3) {
    void* l4 = NULL;
    void* l10 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l20 = NULL;
    void* l26 = NULL;
    void* l28 = NULL;
    void* l30 = NULL;
    int64_t l5, l6, l18, l21;
    vader_box_t l7 = vader_box_null(), l8 = vader_box_null(), l13 = vader_box_null(), l22 = vader_box_null(), l23 = vader_box_null(), l29 = vader_box_null(), l32 = vader_box_null();
    int32_t l9, l11, l12, l17, l24, l25, l31;
    bool l14, l19, l27;
    void* t0 = NULL;
    bool t1, t4;
    int64_t t2;
    int32_t t3;
    vader_box_t* gc_roots[7] = { &l7, &l8, &l13, &l22, &l23, &l29, &l32 };
    void** gc_raw_roots[13] = {
        &l0, &l1, &l2, &l3, &l4, &l10, &l15, &l16, &l20, &l26, &l28, &l30, &t0,
    };
    vader_gc_frame_t gc_frame = { vader_gc_top, 7u, 13u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(268u, 0u, 13u, 2082u);
    l4 = (void*) _a0_arr;
    l5 = INT64_C(0);
    l6 = ((vader_array_t*) ((vader_struct_vader_midir$BasicBlock_t*) l0)->f_instructions)->length;
    while ((l5 < l6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_midir$BasicBlock_t*) l0)->f_instructions);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        l7 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
        if (l7.tag == 1353u) {
            if (l7.tag == 1353u) {
                t0 = l7.payload.obj;
                l9 = ((vader_struct_vader_midir$InstrMove_t*) t0)->f_src;
                t1 = std_collections$MutableSet$std_core$Contains$contains__i32(l3, l9);
                if (t1) {
                    l10 = l7.payload.obj;
                    vader_array_push_ref((vader_array_t*) l4, l10);
                    l5 = (l5 + INT64_C(1));
                    continue;
                }
                t0 = l7.payload.obj;
                l12 = ((vader_struct_vader_midir$InstrMove_t*) t0)->f_src;
                l13 = std_collections$MutableMap$std_core$Index$at__i32__i32(l2, l12);
                if (l13.tag == 0u) {
                    l11 = INT32_C(0);
                } else {
                    l11 = ((int32_t) l13.payload.i);
                }
                if (l11 != INT32_C(1)) {
                    l14 = true;
                } else {
                    l15 = l7.payload.obj;
                    l14 = vader_midir_optimise$move_retags(l1, l15);
                }
                if (l14) {
                    l16 = l7.payload.obj;
                    vader_array_push_ref((vader_array_t*) l4, l16);
                    l5 = (l5 + INT64_C(1));
                    continue;
                }
                t0 = l7.payload.obj;
                l17 = ((vader_struct_vader_midir$InstrMove_t*) t0)->f_dst;
                l18 = INT64_C(-1);
                l19 = false;
                vader_array_t* _a2_arr = vader_array_new(19u, 1u, 12u, 333u);
                ((uint8_t*) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = (uint8_t) false;
                l20 = (void*) _a2_arr;
                t2 = ((vader_array_t*) l4)->length;
                l21 = vader_chk_sub(i64, t2, INT64_C(1));
                while ((l21 >= INT64_C(0))) {
                    vader_array_t* _a3_slotarr = ((vader_array_t*) l4);
                    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l21)
                    l22 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l21);
                    l23 = vader_midir$dst_of(l22);
                    if (l23.tag == 338u) {
                        l24 = ((int32_t) l23.payload.i);
                        t0 = l7.payload.obj;
                        l25 = ((vader_struct_vader_midir$InstrMove_t*) t0)->f_src;
                        t1 = vader_midir$LocalId$std_core$Equals$equals(l24, l25);
                        if (t1) {
                            l18 = l21;
                            break;
                        }
                        t3 = ((int32_t) l23.payload.i);
                        t1 = vader_midir$LocalId$std_core$Equals$equals(t3, l17);
                        if (t1) {
                            l19 = true;
                            break;
                        }
                    }
                    vader_array_t* _a4_slotarr = ((vader_array_t*) l20);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, INT32_C(0))
                    ((uint8_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) INT32_C(0)] = (uint8_t) false;
                    vader_struct___lambda_env_vader_midir_optimise_3_t* _a5_obj = (vader_struct___lambda_env_vader_midir_optimise_3_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_midir_optimise_3_t));
                    vader_obj_header_init(_a5_obj, 439u);
                    _a5_obj->f_cap_0 = l17;
                    _a5_obj->f_cap_1 = l20;
                    t0 = (void*) _a5_obj;
                    vader_fn_t* _a6_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
                    vader_obj_header_init(_a6_closure, 305u);
                    _a6_closure->code = (void*) &vader_fn_lift___lambda_vader_midir_optimise_2;
                    _a6_closure->env = t0;
                    l26 = (void*) _a6_closure;
                    vader_midir$for_each_read_local(l22, l26);
                    vader_array_t* _a7_slotarr = ((vader_array_t*) l20);
                    VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a7_slotarr, INT32_C(0))
                    t1 = ((uint8_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) INT32_C(0)];
                    t4 = t1;
                    if (t4) {
                        l19 = true;
                        break;
                    }
                    l21 = vader_chk_sub(i64, l21, INT64_C(1));
                }
                if ((l18 < INT64_C(0))) {
                    l27 = true;
                } else {
                    l27 = l19;
                }
                if (l27) {
                    l28 = l7.payload.obj;
                    vader_array_push_ref((vader_array_t*) l4, l28);
                    l5 = (l5 + INT64_C(1));
                    continue;
                }
                vader_array_t* _a8_slotarr = ((vader_array_t*) l4);
                VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l18)
                l29 = vader_array_ref_load_box(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l18);
                t1 = vader_midir$instruction_has_side_effect(l29);
                if (t1) {
                    l30 = l7.payload.obj;
                    vader_array_push_ref((vader_array_t*) l4, l30);
                    l5 = (l5 + INT64_C(1));
                    continue;
                }
                t0 = l7.payload.obj;
                l31 = ((vader_struct_vader_midir$InstrMove_t*) t0)->f_dst;
                l32 = vader_midir_optimise$with_dst(l29, l31);
                vader_array_t* _a9_slotarr = ((vader_array_t*) l4);
                VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l18)
                vader_array_ref_store(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l18, l32.payload.obj);
                VADER_WRITE_BARRIER(_a9_slotarr->buf);
            }
            l5 = (l5 + INT64_C(1));
            continue;
        }
        l8 = l7;
        vader_array_push_ref((vader_array_t*) l4, l8.payload.obj);
        l5 = (l5 + INT64_C(1));
    }
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir_optimise$forward_block(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l4 = NULL;
    void* l12 = NULL;
    void* l15 = NULL;
    void* l19 = NULL;
    void* l20 = NULL;
    void* l24 = NULL;
    void* l25 = NULL;
    int64_t l3, l5;
    vader_box_t l6 = vader_box_null(), l7 = vader_box_null(), l11 = vader_box_null(), l26 = vader_box_null();
    int32_t l8, l9, l10, l13, l14, l16, l17, l18, l21, l22, l23;
    int64_t t0;
    void* t1 = NULL;
    bool t2;
    vader_box_t* gc_roots[4] = { &l6, &l7, &l11, &l26 };
    void** gc_raw_roots[11] = { &l0, &l1, &l2, &l4, &l12, &l15, &l19, &l20, &l24, &l25, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 11u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(212u, 0u, 13u, 1379u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(268u, 0u, 13u, 2082u);
    l2 = (void*) _a1_arr;
    l3 = ((vader_array_t*) l0)->length;
    vader_array_t* _a2_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a2_arr;
    l4 = l0;
    l3 = ((vader_array_t*) l4)->length;
    l5 = INT64_C(0);
    while ((l5 < l3)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
        l6 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l5);
        l7 = vader_midir$dst_of(l6);
        if (!(l7.tag == 0u)) {
            t0 = ((vader_array_t*) l1)->length;
            if ((t0 > INT64_C(0))) {
                l8 = ((int32_t) l7.payload.i);
                l1 = vader_midir_optimise$drop_slots_using(l1, l8);
            }
        }
        if (l6.tag == 1328u) {
            t1 = l6.payload.obj;
            l9 = ((vader_struct_vader_midir$InstrArrayGet_t*) t1)->f_target;
            t1 = l6.payload.obj;
            l10 = ((vader_struct_vader_midir$InstrArrayGet_t*) t1)->f_index;
            l11 = vader_midir_optimise$lookup_slot(l1, l9, l10);
            if (l11.tag == 0u) {
                t1 = l6.payload.obj;
                l16 = ((vader_struct_vader_midir$InstrArrayGet_t*) t1)->f_target;
                t1 = l6.payload.obj;
                l17 = ((vader_struct_vader_midir$InstrArrayGet_t*) t1)->f_index;
                t1 = l6.payload.obj;
                l18 = ((vader_struct_vader_midir$InstrArrayGet_t*) t1)->f_dst;
                vader_struct_vader_midir_optimise$SlotVal_t* _a4_obj = (vader_struct_vader_midir_optimise$SlotVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_optimise$SlotVal_t));
                vader_obj_header_init(_a4_obj, 1379u);
                _a4_obj->f_target = l16;
                _a4_obj->f_index = l17;
                _a4_obj->f_value = l18;
                l19 = (void*) _a4_obj;
                vader_array_push_ref((vader_array_t*) l1, l19);
                l20 = l6.payload.obj;
                vader_array_push_ref((vader_array_t*) l2, l20);
                l5 = (l5 + INT64_C(1));
                continue;
            }
            t1 = l6.payload.obj;
            l12 = ((vader_struct_vader_midir$InstrArrayGet_t*) t1)->f_span;
            t1 = l6.payload.obj;
            l13 = ((vader_struct_vader_midir$InstrArrayGet_t*) t1)->f_dst;
            l14 = ((int32_t) l11.payload.i);
            vader_struct_vader_midir$InstrMove_t* _a5_obj = (vader_struct_vader_midir$InstrMove_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrMove_t));
            vader_obj_header_init(_a5_obj, 1353u);
            _a5_obj->f_span = l12;
            _a5_obj->f_dst = l13;
            _a5_obj->f_src = l14;
            l15 = (void*) _a5_obj;
            vader_array_push_ref((vader_array_t*) l2, l15);
            l5 = (l5 + INT64_C(1));
            continue;
        }
        if (l6.tag == 1332u) {
            vader_array_clear((vader_array_t*) l1);
            t1 = l6.payload.obj;
            l21 = ((vader_struct_vader_midir$InstrArraySet_t*) t1)->f_target;
            t1 = l6.payload.obj;
            l22 = ((vader_struct_vader_midir$InstrArraySet_t*) t1)->f_index;
            t1 = l6.payload.obj;
            l23 = ((vader_struct_vader_midir$InstrArraySet_t*) t1)->f_value;
            vader_struct_vader_midir_optimise$SlotVal_t* _a6_obj = (vader_struct_vader_midir_optimise$SlotVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_optimise$SlotVal_t));
            vader_obj_header_init(_a6_obj, 1379u);
            _a6_obj->f_target = l21;
            _a6_obj->f_index = l22;
            _a6_obj->f_value = l23;
            l24 = (void*) _a6_obj;
            vader_array_push_ref((vader_array_t*) l1, l24);
            l25 = l6.payload.obj;
            vader_array_push_ref((vader_array_t*) l2, l25);
            l5 = (l5 + INT64_C(1));
            continue;
        }
        t2 = vader_midir$instruction_has_side_effect(l6);
        if (t2) {
            vader_array_clear((vader_array_t*) l1);
        }
        l26 = l6;
        vader_array_push_ref((vader_array_t*) l2, l26.payload.obj);
        l5 = (l5 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir_optimise$forward_function(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    int64_t l2, l4;
    int32_t l7;
    vader_box_t l9 = vader_box_null();
    vader_string_t l12 = 0;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l9 };
    void** gc_raw_roots[9] = { &l0, &l1, &l3, &l5, &l6, &l8, &l10, &l11, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l12 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(201u, 0u, 13u, 1304u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_array_t*) ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (int64_t) l2);
    l1 = (void*) _a1_arr;
    l3 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks;
    l2 = ((vader_array_t*) l3)->length;
    l4 = INT64_C(0);
    while ((l4 < l2)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        l5 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        l6 = l5;
        l7 = ((vader_struct_vader_midir$BasicBlock_t*) l6)->f_id;
        l8 = vader_midir_optimise$forward_block(((vader_struct_vader_midir$BasicBlock_t*) l5)->f_instructions);
        l9 = ((vader_struct_vader_midir$BasicBlock_t*) l6)->f_terminator;
        l10 = ((vader_struct_vader_midir$BasicBlock_t*) l6)->f_span;
        vader_struct_vader_midir$BasicBlock_t* _a3_obj = (vader_struct_vader_midir$BasicBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$BasicBlock_t));
        vader_obj_header_init(_a3_obj, 1304u);
        _a3_obj->f_id = l7;
        _a3_obj->f_instructions = l8;
        _a3_obj->f_terminator = l9;
        _a3_obj->f_span = l10;
        l11 = (void*) _a3_obj;
        vader_array_push_ref((vader_array_t*) l1, l11);
        l4 = (l4 + INT64_C(1));
    }
    l3 = l0;
    l12 = ((vader_struct_vader_midir$CFGFunction_t*) l3)->f_mangled;
    l5 = ((vader_struct_vader_midir$CFGFunction_t*) l3)->f_params;
    l9 = ((vader_struct_vader_midir$CFGFunction_t*) l3)->f_return_type;
    l6 = ((vader_struct_vader_midir$CFGFunction_t*) l3)->f_locals;
    l7 = ((vader_struct_vader_midir$CFGFunction_t*) l3)->f_entry;
    l8 = ((vader_struct_vader_midir$CFGFunction_t*) l3)->f_origin;
    l3 = ((vader_struct_vader_midir$CFGFunction_t*) l3)->f_scalarised_results;
    vader_struct_vader_midir$CFGFunction_t* _a4_obj = (vader_struct_vader_midir$CFGFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$CFGFunction_t));
    vader_obj_header_init(_a4_obj, 1306u);
    _a4_obj->f_mangled = l12;
    _a4_obj->f_params = l5;
    _a4_obj->f_return_type = l9;
    _a4_obj->f_locals = l6;
    _a4_obj->f_blocks = l1;
    _a4_obj->f_entry = l7;
    _a4_obj->f_origin = l8;
    _a4_obj->f_scalarised_results = l3;
    t0 = (void*) _a4_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_optimise$lookup_slot(void* l0, int32_t l1, int32_t l2) {
    void* l3;
    void* l6;
    int64_t l4, l5;
    bool t0;
    l3 = l0;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l6 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        t0 = vader_midir$LocalId$std_core$Equals$equals(((vader_struct_vader_midir_optimise$SlotVal_t*) l6)->f_target, l1);
        if (t0) {
            t0 = vader_midir$LocalId$std_core$Equals$equals(((vader_struct_vader_midir_optimise$SlotVal_t*) l6)->f_index, l2);
            if (t0) {
                return vader_box_i32(338u, ((vader_struct_vader_midir_optimise$SlotVal_t*) l6)->f_value);
            }
        }
        l5 = (l5 + INT64_C(1));
    }
    return vader_box_obj(0u, NULL);
}

void vader_midir_optimise$mark_referenced(void* l0, int32_t l1) {
    int64_t l2, l4;
    bool l3;
    l2 = ((int64_t) (int32_t) l1);
    if ((INT64_C(0) <= l2)) {
        l4 = ((vader_array_t*) l0)->length;
        l3 = (l2 < l4);
    } else {
        l3 = false;
    }
    if (l3) {
        l2 = ((int64_t) (int32_t) l1);
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l2] = (uint8_t) true;
        return;
    }
    return;
}

static bool vader_midir_optimise$move_retags(void* l0, void* l1) {
    int64_t l2;
    void* t0 = NULL;
    bool t1;
    uint8_t t2;
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((int64_t) (int32_t) ((vader_struct_vader_midir$InstrMove_t*) l1)->f_dst);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
    t1 = vader_midir_select$is_boxed_slot(((vader_struct_vader_midir$CFGLocal_t*) t0)->f_type);
    if (t1) {
        l2 = ((int64_t) (int32_t) ((vader_struct_vader_midir$InstrMove_t*) l1)->f_src);
        vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l2);
        t2 = vader_midir_select$val_type_of_type(((vader_struct_vader_midir$CFGLocal_t*) t0)->f_type);
        t1 = vader_midir_select$is_scalar_class(t2);
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static void* vader_midir_optimise$optimise_function(void* l0) {
    void* t0 = NULL;
    void* t1 = NULL;
    void** gc_raw_roots[3] = { &l0, &t0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_midir_optimise$fold_moves(l0);
    t1 = vader_midir_optimise$compact_locals(t0);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_midir_optimise$read_may_carry_ref(vader_box_t l0) {
    uint8_t l1;
    vader_box_t* gc_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_midir_select$val_type_of_type(l0);
    if (l1 == INT32_C(16)) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    { bool __vret = l1 == INT32_C(17); vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_midir_optimise$record_alias(void* l0, void* l1, int32_t l2, int32_t l3) {
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_midir_optimise$append_alias(l0, l2, l3);
    vader_midir_optimise$append_alias(l1, l3, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_midir_optimise$remap_instr(vader_box_t l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l5 = vader_box_null(), l12 = vader_box_null(), l13 = vader_box_null();
    void* l3 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    int32_t l4, l6, l8, l17;
    uint8_t l7;
    vader_string_t l14 = 0;
    vader_string_t l15 = 0;
    bool l16;
    void* t0 = NULL;
    vader_box_t* gc_roots[5] = { &l0, &l2, &l5, &l12, &l13 };
    void** gc_raw_roots[6] = { &l1, &l3, &l9, &l10, &l11, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l14, &l15 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 5u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1341u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrConst_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrConst_t*) t0)->f_dst;
        l4 = vader_midir_optimise$remap_local(l1, l4);
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir$InstrConst_t*) t0)->f_value;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir$InstrConst_t*) t0)->f_type;
        vader_struct_vader_midir$InstrConst_t* _a0_obj = (vader_struct_vader_midir$InstrConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrConst_t));
        vader_obj_header_init(_a0_obj, 1341u);
        _a0_obj->f_span = l3;
        _a0_obj->f_dst = l4;
        _a0_obj->f_value = l2;
        _a0_obj->f_type = l5;
        t0 = (void*) _a0_obj;
        l2 = vader_ref_box(t0);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1353u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrMove_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrMove_t*) t0)->f_dst;
        l4 = vader_midir_optimise$remap_local(l1, l4);
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir$InstrMove_t*) t0)->f_src;
        l6 = vader_midir_optimise$remap_local(l1, l6);
        vader_struct_vader_midir$InstrMove_t* _a1_obj = (vader_struct_vader_midir$InstrMove_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrMove_t));
        vader_obj_header_init(_a1_obj, 1353u);
        _a1_obj->f_span = l3;
        _a1_obj->f_dst = l4;
        _a1_obj->f_src = l6;
        t0 = (void*) _a1_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1334u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrBinOp_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrBinOp_t*) t0)->f_dst;
        l4 = vader_midir_optimise$remap_local(l1, l4);
        t0 = l0.payload.obj;
        l7 = ((vader_struct_vader_midir$InstrBinOp_t*) t0)->f_op;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir$InstrBinOp_t*) t0)->f_lhs;
        l6 = vader_midir_optimise$remap_local(l1, l6);
        t0 = l0.payload.obj;
        l8 = ((vader_struct_vader_midir$InstrBinOp_t*) t0)->f_rhs;
        l8 = vader_midir_optimise$remap_local(l1, l8);
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir$InstrBinOp_t*) t0)->f_type;
        vader_struct_vader_midir$InstrBinOp_t* _a2_obj = (vader_struct_vader_midir$InstrBinOp_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrBinOp_t));
        vader_obj_header_init(_a2_obj, 1334u);
        _a2_obj->f_span = l3;
        _a2_obj->f_dst = l4;
        _a2_obj->f_op = l7;
        _a2_obj->f_lhs = l6;
        _a2_obj->f_rhs = l8;
        _a2_obj->f_type = l5;
        t0 = (void*) _a2_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1357u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrUnOp_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrUnOp_t*) t0)->f_dst;
        l4 = vader_midir_optimise$remap_local(l1, l4);
        t0 = l0.payload.obj;
        l7 = ((vader_struct_vader_midir$InstrUnOp_t*) t0)->f_op;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir$InstrUnOp_t*) t0)->f_operand;
        l6 = vader_midir_optimise$remap_local(l1, l6);
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir$InstrUnOp_t*) t0)->f_type;
        vader_struct_vader_midir$InstrUnOp_t* _a3_obj = (vader_struct_vader_midir$InstrUnOp_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrUnOp_t));
        vader_obj_header_init(_a3_obj, 1357u);
        _a3_obj->f_span = l3;
        _a3_obj->f_dst = l4;
        _a3_obj->f_op = l7;
        _a3_obj->f_operand = l6;
        _a3_obj->f_type = l5;
        t0 = (void*) _a3_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1335u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrCall_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l9 = ((vader_struct_vader_midir$InstrCall_t*) t0)->f_dsts;
        l9 = vader_midir_optimise$remap_locals(l1, l9);
        t0 = l0.payload.obj;
        l10 = ((vader_struct_vader_midir$InstrCall_t*) t0)->f_callee;
        t0 = l0.payload.obj;
        l11 = ((vader_struct_vader_midir$InstrCall_t*) t0)->f_args;
        l11 = vader_midir_optimise$remap_locals(l1, l11);
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir$InstrCall_t*) t0)->f_type;
        vader_struct_vader_midir$InstrCall_t* _a4_obj = (vader_struct_vader_midir$InstrCall_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrCall_t));
        vader_obj_header_init(_a4_obj, 1335u);
        _a4_obj->f_span = l3;
        _a4_obj->f_dsts = l9;
        _a4_obj->f_callee = l10;
        _a4_obj->f_args = l11;
        _a4_obj->f_type = l5;
        t0 = (void*) _a4_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1336u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrCallIndirect_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir$InstrCallIndirect_t*) t0)->f_dst;
        l5 = vader_midir_optimise$remap_local_opt(l1, l5);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrCallIndirect_t*) t0)->f_callee;
        l4 = vader_midir_optimise$remap_local(l1, l4);
        t0 = l0.payload.obj;
        l9 = ((vader_struct_vader_midir$InstrCallIndirect_t*) t0)->f_args;
        l9 = vader_midir_optimise$remap_locals(l1, l9);
        t0 = l0.payload.obj;
        l12 = ((vader_struct_vader_midir$InstrCallIndirect_t*) t0)->f_fn_type;
        t0 = l0.payload.obj;
        l13 = ((vader_struct_vader_midir$InstrCallIndirect_t*) t0)->f_type;
        vader_struct_vader_midir$InstrCallIndirect_t* _a5_obj = (vader_struct_vader_midir$InstrCallIndirect_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrCallIndirect_t));
        vader_obj_header_init(_a5_obj, 1336u);
        _a5_obj->f_span = l3;
        _a5_obj->f_dst = l5;
        _a5_obj->f_callee = l4;
        _a5_obj->f_args = l9;
        _a5_obj->f_fn_type = l12;
        _a5_obj->f_type = l13;
        t0 = (void*) _a5_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1360u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrVirtualCall_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir$InstrVirtualCall_t*) t0)->f_dst;
        l5 = vader_midir_optimise$remap_local_opt(l1, l5);
        t0 = l0.payload.obj;
        l14 = ((vader_struct_vader_midir$InstrVirtualCall_t*) t0)->f_trait_name;
        t0 = l0.payload.obj;
        l15 = ((vader_struct_vader_midir$InstrVirtualCall_t*) t0)->f_method;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrVirtualCall_t*) t0)->f_receiver;
        l4 = vader_midir_optimise$remap_local(l1, l4);
        t0 = l0.payload.obj;
        l9 = ((vader_struct_vader_midir$InstrVirtualCall_t*) t0)->f_args;
        l9 = vader_midir_optimise$remap_locals(l1, l9);
        t0 = l0.payload.obj;
        l12 = ((vader_struct_vader_midir$InstrVirtualCall_t*) t0)->f_type;
        t0 = l0.payload.obj;
        l10 = ((vader_struct_vader_midir$InstrVirtualCall_t*) t0)->f_param_types;
        vader_struct_vader_midir$InstrVirtualCall_t* _a6_obj = (vader_struct_vader_midir$InstrVirtualCall_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrVirtualCall_t));
        vader_obj_header_init(_a6_obj, 1360u);
        _a6_obj->f_span = l3;
        _a6_obj->f_dst = l5;
        _a6_obj->f_trait_name = l14;
        _a6_obj->f_method = l15;
        _a6_obj->f_receiver = l4;
        _a6_obj->f_args = l9;
        _a6_obj->f_type = l12;
        _a6_obj->f_param_types = l10;
        t0 = (void*) _a6_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1348u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrFnRef_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrFnRef_t*) t0)->f_dst;
        l4 = vader_midir_optimise$remap_local(l1, l4);
        t0 = l0.payload.obj;
        l9 = ((vader_struct_vader_midir$InstrFnRef_t*) t0)->f_fn_symbol;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir$InstrFnRef_t*) t0)->f_type;
        vader_struct_vader_midir$InstrFnRef_t* _a7_obj = (vader_struct_vader_midir$InstrFnRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrFnRef_t));
        vader_obj_header_init(_a7_obj, 1348u);
        _a7_obj->f_span = l3;
        _a7_obj->f_dst = l4;
        _a7_obj->f_fn_symbol = l9;
        _a7_obj->f_type = l5;
        t0 = (void*) _a7_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1347u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrFnAddr_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrFnAddr_t*) t0)->f_dst;
        l4 = vader_midir_optimise$remap_local(l1, l4);
        t0 = l0.payload.obj;
        l9 = ((vader_struct_vader_midir$InstrFnAddr_t*) t0)->f_fn_symbol;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir$InstrFnAddr_t*) t0)->f_type;
        vader_struct_vader_midir$InstrFnAddr_t* _a8_obj = (vader_struct_vader_midir$InstrFnAddr_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrFnAddr_t));
        vader_obj_header_init(_a8_obj, 1347u);
        _a8_obj->f_span = l3;
        _a8_obj->f_dst = l4;
        _a8_obj->f_fn_symbol = l9;
        _a8_obj->f_type = l5;
        t0 = (void*) _a8_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1345u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrFieldGet_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrFieldGet_t*) t0)->f_dst;
        l4 = vader_midir_optimise$remap_local(l1, l4);
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir$InstrFieldGet_t*) t0)->f_target;
        l6 = vader_midir_optimise$remap_local(l1, l6);
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir$InstrFieldGet_t*) t0)->f_type;
        t0 = l0.payload.obj;
        l14 = ((vader_struct_vader_midir$InstrFieldGet_t*) t0)->f_field;
        vader_struct_vader_midir$InstrFieldGet_t* _a9_obj = (vader_struct_vader_midir$InstrFieldGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrFieldGet_t));
        vader_obj_header_init(_a9_obj, 1345u);
        _a9_obj->f_span = l3;
        _a9_obj->f_dst = l4;
        _a9_obj->f_target = l6;
        _a9_obj->f_type = l5;
        _a9_obj->f_field = l14;
        t0 = (void*) _a9_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1346u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrFieldSet_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrFieldSet_t*) t0)->f_target;
        l4 = vader_midir_optimise$remap_local(l1, l4);
        t0 = l0.payload.obj;
        l14 = ((vader_struct_vader_midir$InstrFieldSet_t*) t0)->f_field;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir$InstrFieldSet_t*) t0)->f_value;
        l6 = vader_midir_optimise$remap_local(l1, l6);
        t0 = l0.payload.obj;
        l16 = ((vader_struct_vader_midir$InstrFieldSet_t*) t0)->f_barrierless;
        vader_struct_vader_midir$InstrFieldSet_t* _a10_obj = (vader_struct_vader_midir$InstrFieldSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrFieldSet_t));
        vader_obj_header_init(_a10_obj, 1346u);
        _a10_obj->f_span = l3;
        _a10_obj->f_target = l4;
        _a10_obj->f_field = l14;
        _a10_obj->f_value = l6;
        _a10_obj->f_barrierless = l16;
        t0 = (void*) _a10_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1358u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrUnionFieldGet_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrUnionFieldGet_t*) t0)->f_dst;
        l4 = vader_midir_optimise$remap_local(l1, l4);
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir$InstrUnionFieldGet_t*) t0)->f_target;
        l6 = vader_midir_optimise$remap_local(l1, l6);
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir$InstrUnionFieldGet_t*) t0)->f_type;
        t0 = l0.payload.obj;
        l14 = ((vader_struct_vader_midir$InstrUnionFieldGet_t*) t0)->f_field;
        vader_struct_vader_midir$InstrUnionFieldGet_t* _a11_obj = (vader_struct_vader_midir$InstrUnionFieldGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrUnionFieldGet_t));
        vader_obj_header_init(_a11_obj, 1358u);
        _a11_obj->f_span = l3;
        _a11_obj->f_dst = l4;
        _a11_obj->f_target = l6;
        _a11_obj->f_type = l5;
        _a11_obj->f_field = l14;
        t0 = (void*) _a11_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1359u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrUnionFieldSet_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrUnionFieldSet_t*) t0)->f_target;
        l4 = vader_midir_optimise$remap_local(l1, l4);
        t0 = l0.payload.obj;
        l14 = ((vader_struct_vader_midir$InstrUnionFieldSet_t*) t0)->f_field;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir$InstrUnionFieldSet_t*) t0)->f_value;
        l6 = vader_midir_optimise$remap_local(l1, l6);
        vader_struct_vader_midir$InstrUnionFieldSet_t* _a12_obj = (vader_struct_vader_midir$InstrUnionFieldSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrUnionFieldSet_t));
        vader_obj_header_init(_a12_obj, 1359u);
        _a12_obj->f_span = l3;
        _a12_obj->f_target = l4;
        _a12_obj->f_field = l14;
        _a12_obj->f_value = l6;
        t0 = (void*) _a12_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1328u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrArrayGet_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrArrayGet_t*) t0)->f_dst;
        l4 = vader_midir_optimise$remap_local(l1, l4);
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir$InstrArrayGet_t*) t0)->f_target;
        l6 = vader_midir_optimise$remap_local(l1, l6);
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir$InstrArrayGet_t*) t0)->f_type;
        t0 = l0.payload.obj;
        l8 = ((vader_struct_vader_midir$InstrArrayGet_t*) t0)->f_index;
        l8 = vader_midir_optimise$remap_local(l1, l8);
        t0 = l0.payload.obj;
        l16 = ((vader_struct_vader_midir$InstrArrayGet_t*) t0)->f_bounds_safe;
        vader_struct_vader_midir$InstrArrayGet_t* _a13_obj = (vader_struct_vader_midir$InstrArrayGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrArrayGet_t));
        vader_obj_header_init(_a13_obj, 1328u);
        _a13_obj->f_span = l3;
        _a13_obj->f_dst = l4;
        _a13_obj->f_target = l6;
        _a13_obj->f_type = l5;
        _a13_obj->f_index = l8;
        _a13_obj->f_bounds_safe = l16;
        t0 = (void*) _a13_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1332u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrArraySet_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrArraySet_t*) t0)->f_target;
        l4 = vader_midir_optimise$remap_local(l1, l4);
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir$InstrArraySet_t*) t0)->f_index;
        l6 = vader_midir_optimise$remap_local(l1, l6);
        t0 = l0.payload.obj;
        l8 = ((vader_struct_vader_midir$InstrArraySet_t*) t0)->f_value;
        l8 = vader_midir_optimise$remap_local(l1, l8);
        t0 = l0.payload.obj;
        l16 = ((vader_struct_vader_midir$InstrArraySet_t*) t0)->f_bounds_safe;
        vader_struct_vader_midir$InstrArraySet_t* _a14_obj = (vader_struct_vader_midir$InstrArraySet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrArraySet_t));
        vader_obj_header_init(_a14_obj, 1332u);
        _a14_obj->f_span = l3;
        _a14_obj->f_target = l4;
        _a14_obj->f_index = l6;
        _a14_obj->f_value = l8;
        _a14_obj->f_bounds_safe = l16;
        t0 = (void*) _a14_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1329u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrArrayLen_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrArrayLen_t*) t0)->f_dst;
        l4 = vader_midir_optimise$remap_local(l1, l4);
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir$InstrArrayLen_t*) t0)->f_target;
        l6 = vader_midir_optimise$remap_local(l1, l6);
        vader_struct_vader_midir$InstrArrayLen_t* _a15_obj = (vader_struct_vader_midir$InstrArrayLen_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrArrayLen_t));
        vader_obj_header_init(_a15_obj, 1329u);
        _a15_obj->f_span = l3;
        _a15_obj->f_dst = l4;
        _a15_obj->f_target = l6;
        t0 = (void*) _a15_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1331u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrArrayPush_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrArrayPush_t*) t0)->f_target;
        l4 = vader_midir_optimise$remap_local(l1, l4);
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir$InstrArrayPush_t*) t0)->f_value;
        l6 = vader_midir_optimise$remap_local(l1, l6);
        t0 = l0.payload.obj;
        l16 = ((vader_struct_vader_midir$InstrArrayPush_t*) t0)->f_cached;
        vader_struct_vader_midir$InstrArrayPush_t* _a16_obj = (vader_struct_vader_midir$InstrArrayPush_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrArrayPush_t));
        vader_obj_header_init(_a16_obj, 1331u);
        _a16_obj->f_span = l3;
        _a16_obj->f_target = l4;
        _a16_obj->f_value = l6;
        _a16_obj->f_cached = l16;
        t0 = (void*) _a16_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1333u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrArraySlice_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrArraySlice_t*) t0)->f_dst;
        l4 = vader_midir_optimise$remap_local(l1, l4);
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir$InstrArraySlice_t*) t0)->f_type;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir$InstrArraySlice_t*) t0)->f_target;
        l6 = vader_midir_optimise$remap_local(l1, l6);
        t0 = l0.payload.obj;
        l8 = ((vader_struct_vader_midir$InstrArraySlice_t*) t0)->f_lo;
        l8 = vader_midir_optimise$remap_local(l1, l8);
        t0 = l0.payload.obj;
        l17 = ((vader_struct_vader_midir$InstrArraySlice_t*) t0)->f_hi;
        l17 = vader_midir_optimise$remap_local(l1, l17);
        vader_struct_vader_midir$InstrArraySlice_t* _a17_obj = (vader_struct_vader_midir$InstrArraySlice_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrArraySlice_t));
        vader_obj_header_init(_a17_obj, 1333u);
        _a17_obj->f_span = l3;
        _a17_obj->f_dst = l4;
        _a17_obj->f_type = l5;
        _a17_obj->f_target = l6;
        _a17_obj->f_lo = l8;
        _a17_obj->f_hi = l17;
        t0 = (void*) _a17_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1354u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrStructNew_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrStructNew_t*) t0)->f_dst;
        l4 = vader_midir_optimise$remap_local(l1, l4);
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir$InstrStructNew_t*) t0)->f_type;
        t0 = l0.payload.obj;
        l9 = ((vader_struct_vader_midir$InstrStructNew_t*) t0)->f_fields;
        l9 = vader_midir_optimise$remap_locals(l1, l9);
        t0 = l0.payload.obj;
        l16 = ((vader_struct_vader_midir$InstrStructNew_t*) t0)->f_stack;
        vader_struct_vader_midir$InstrStructNew_t* _a18_obj = (vader_struct_vader_midir$InstrStructNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrStructNew_t));
        vader_obj_header_init(_a18_obj, 1354u);
        _a18_obj->f_span = l3;
        _a18_obj->f_dst = l4;
        _a18_obj->f_type = l5;
        _a18_obj->f_fields = l9;
        _a18_obj->f_stack = l16;
        t0 = (void*) _a18_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1330u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrArrayNew_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrArrayNew_t*) t0)->f_dst;
        l4 = vader_midir_optimise$remap_local(l1, l4);
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir$InstrArrayNew_t*) t0)->f_type;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir$InstrArrayNew_t*) t0)->f_length;
        t0 = l0.payload.obj;
        l9 = ((vader_struct_vader_midir$InstrArrayNew_t*) t0)->f_elements;
        l9 = vader_midir_optimise$remap_locals(l1, l9);
        t0 = l0.payload.obj;
        l16 = ((vader_struct_vader_midir$InstrArrayNew_t*) t0)->f_stack;
        vader_struct_vader_midir$InstrArrayNew_t* _a19_obj = (vader_struct_vader_midir$InstrArrayNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrArrayNew_t));
        vader_obj_header_init(_a19_obj, 1330u);
        _a19_obj->f_span = l3;
        _a19_obj->f_dst = l4;
        _a19_obj->f_type = l5;
        _a19_obj->f_length = l6;
        _a19_obj->f_elements = l9;
        _a19_obj->f_stack = l16;
        t0 = (void*) _a19_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1342u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrDataConst_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrDataConst_t*) t0)->f_dst;
        l4 = vader_midir_optimise$remap_local(l1, l4);
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir$InstrDataConst_t*) t0)->f_type;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir$InstrDataConst_t*) t0)->f_pool_index;
        vader_struct_vader_midir$InstrDataConst_t* _a20_obj = (vader_struct_vader_midir$InstrDataConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrDataConst_t));
        vader_obj_header_init(_a20_obj, 1342u);
        _a20_obj->f_span = l3;
        _a20_obj->f_dst = l4;
        _a20_obj->f_type = l5;
        _a20_obj->f_pool_index = l6;
        t0 = (void*) _a20_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1349u) {
        l3 = l0.payload.obj;
        l9 = ((vader_struct_vader_midir$InstrGlobalGet_t*) l3)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrGlobalGet_t*) t0)->f_dst;
        l4 = vader_midir_optimise$remap_local(l1, l4);
        l5 = ((vader_struct_vader_midir$InstrGlobalGet_t*) l3)->f_type;
        l6 = ((vader_struct_vader_midir$InstrGlobalGet_t*) l3)->f_slot;
        vader_struct_vader_midir$InstrGlobalGet_t* _a21_obj = (vader_struct_vader_midir$InstrGlobalGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrGlobalGet_t));
        vader_obj_header_init(_a21_obj, 1349u);
        _a21_obj->f_span = l9;
        _a21_obj->f_dst = l4;
        _a21_obj->f_type = l5;
        _a21_obj->f_slot = l6;
        t0 = (void*) _a21_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1350u) {
        l3 = l0.payload.obj;
        l9 = ((vader_struct_vader_midir$InstrGlobalSet_t*) l3)->f_span;
        l4 = ((vader_struct_vader_midir$InstrGlobalSet_t*) l3)->f_slot;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir$InstrGlobalSet_t*) t0)->f_value;
        l6 = vader_midir_optimise$remap_local(l1, l6);
        l5 = ((vader_struct_vader_midir$InstrGlobalSet_t*) l3)->f_type;
        vader_struct_vader_midir$InstrGlobalSet_t* _a22_obj = (vader_struct_vader_midir$InstrGlobalSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrGlobalSet_t));
        vader_obj_header_init(_a22_obj, 1350u);
        _a22_obj->f_span = l9;
        _a22_obj->f_slot = l4;
        _a22_obj->f_value = l6;
        _a22_obj->f_type = l5;
        t0 = (void*) _a22_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1355u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrTypeCheck_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrTypeCheck_t*) t0)->f_dst;
        l4 = vader_midir_optimise$remap_local(l1, l4);
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir$InstrTypeCheck_t*) t0)->f_value;
        l6 = vader_midir_optimise$remap_local(l1, l6);
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir$InstrTypeCheck_t*) t0)->f_check_type;
        vader_struct_vader_midir$InstrTypeCheck_t* _a23_obj = (vader_struct_vader_midir$InstrTypeCheck_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrTypeCheck_t));
        vader_obj_header_init(_a23_obj, 1355u);
        _a23_obj->f_span = l3;
        _a23_obj->f_dst = l4;
        _a23_obj->f_value = l6;
        _a23_obj->f_check_type = l5;
        t0 = (void*) _a23_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1356u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrTypeConst_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrTypeConst_t*) t0)->f_dst;
        l4 = vader_midir_optimise$remap_local(l1, l4);
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir$InstrTypeConst_t*) t0)->f_type;
        t0 = l0.payload.obj;
        l12 = ((vader_struct_vader_midir$InstrTypeConst_t*) t0)->f_value_type;
        vader_struct_vader_midir$InstrTypeConst_t* _a24_obj = (vader_struct_vader_midir$InstrTypeConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrTypeConst_t));
        vader_obj_header_init(_a24_obj, 1356u);
        _a24_obj->f_span = l3;
        _a24_obj->f_dst = l4;
        _a24_obj->f_type = l5;
        _a24_obj->f_value_type = l12;
        t0 = (void*) _a24_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1337u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrCast_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrCast_t*) t0)->f_dst;
        l4 = vader_midir_optimise$remap_local(l1, l4);
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir$InstrCast_t*) t0)->f_value;
        l6 = vader_midir_optimise$remap_local(l1, l6);
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir$InstrCast_t*) t0)->f_type;
        vader_struct_vader_midir$InstrCast_t* _a25_obj = (vader_struct_vader_midir$InstrCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrCast_t));
        vader_obj_header_init(_a25_obj, 1337u);
        _a25_obj->f_span = l3;
        _a25_obj->f_dst = l4;
        _a25_obj->f_value = l6;
        _a25_obj->f_type = l5;
        t0 = (void*) _a25_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1339u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrCellNew_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrCellNew_t*) t0)->f_dst;
        l4 = vader_midir_optimise$remap_local(l1, l4);
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir$InstrCellNew_t*) t0)->f_value;
        l6 = vader_midir_optimise$remap_local(l1, l6);
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir$InstrCellNew_t*) t0)->f_value_type;
        vader_struct_vader_midir$InstrCellNew_t* _a26_obj = (vader_struct_vader_midir$InstrCellNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrCellNew_t));
        vader_obj_header_init(_a26_obj, 1339u);
        _a26_obj->f_span = l3;
        _a26_obj->f_dst = l4;
        _a26_obj->f_value = l6;
        _a26_obj->f_value_type = l5;
        t0 = (void*) _a26_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1338u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrCellGet_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrCellGet_t*) t0)->f_dst;
        l4 = vader_midir_optimise$remap_local(l1, l4);
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir$InstrCellGet_t*) t0)->f_cell;
        l6 = vader_midir_optimise$remap_local(l1, l6);
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir$InstrCellGet_t*) t0)->f_value_type;
        vader_struct_vader_midir$InstrCellGet_t* _a27_obj = (vader_struct_vader_midir$InstrCellGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrCellGet_t));
        vader_obj_header_init(_a27_obj, 1338u);
        _a27_obj->f_span = l3;
        _a27_obj->f_dst = l4;
        _a27_obj->f_cell = l6;
        _a27_obj->f_value_type = l5;
        t0 = (void*) _a27_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1340u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrCellSet_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrCellSet_t*) t0)->f_cell;
        l4 = vader_midir_optimise$remap_local(l1, l4);
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir$InstrCellSet_t*) t0)->f_value;
        l6 = vader_midir_optimise$remap_local(l1, l6);
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir$InstrCellSet_t*) t0)->f_value_type;
        vader_struct_vader_midir$InstrCellSet_t* _a28_obj = (vader_struct_vader_midir$InstrCellSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrCellSet_t));
        vader_obj_header_init(_a28_obj, 1340u);
        _a28_obj->f_span = l3;
        _a28_obj->f_cell = l4;
        _a28_obj->f_value = l6;
        _a28_obj->f_value_type = l5;
        t0 = (void*) _a28_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1352u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrMakeClosure_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrMakeClosure_t*) t0)->f_dst;
        l4 = vader_midir_optimise$remap_local(l1, l4);
        t0 = l0.payload.obj;
        l9 = ((vader_struct_vader_midir$InstrMakeClosure_t*) t0)->f_fn_symbol;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir$InstrMakeClosure_t*) t0)->f_env;
        l6 = vader_midir_optimise$remap_local(l1, l6);
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir$InstrMakeClosure_t*) t0)->f_type;
        vader_struct_vader_midir$InstrMakeClosure_t* _a29_obj = (vader_struct_vader_midir$InstrMakeClosure_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrMakeClosure_t));
        vader_obj_header_init(_a29_obj, 1352u);
        _a29_obj->f_span = l3;
        _a29_obj->f_dst = l4;
        _a29_obj->f_fn_symbol = l9;
        _a29_obj->f_env = l6;
        _a29_obj->f_type = l5;
        t0 = (void*) _a29_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1351u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrIntrinsic_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir$InstrIntrinsic_t*) t0)->f_dst;
        l5 = vader_midir_optimise$remap_local_opt(l1, l5);
        t0 = l0.payload.obj;
        l14 = ((vader_struct_vader_midir$InstrIntrinsic_t*) t0)->f_name;
        t0 = l0.payload.obj;
        l9 = ((vader_struct_vader_midir$InstrIntrinsic_t*) t0)->f_args;
        l9 = vader_midir_optimise$remap_locals(l1, l9);
        t0 = l0.payload.obj;
        l10 = ((vader_struct_vader_midir$InstrIntrinsic_t*) t0)->f_param_types;
        vader_struct_vader_midir$InstrIntrinsic_t* _a30_obj = (vader_struct_vader_midir$InstrIntrinsic_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrIntrinsic_t));
        vader_obj_header_init(_a30_obj, 1351u);
        _a30_obj->f_span = l3;
        _a30_obj->f_dst = l5;
        _a30_obj->f_name = l14;
        _a30_obj->f_args = l9;
        _a30_obj->f_param_types = l10;
        t0 = (void*) _a30_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1344u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrDeferPush_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrDeferPush_t*) t0)->f_value;
        l4 = vader_midir_optimise$remap_local(l1, l4);
        vader_struct_vader_midir$InstrDeferPush_t* _a31_obj = (vader_struct_vader_midir$InstrDeferPush_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrDeferPush_t));
        vader_obj_header_init(_a31_obj, 1344u);
        _a31_obj->f_span = l3;
        _a31_obj->f_value = l4;
        t0 = (void*) _a31_obj;
        l2 = vader_ref_box(t0);
    } else {
        if (!(l0.tag == 1343u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = l0.payload.obj;
        l2 = vader_ref_box(t0);
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_midir_optimise$remap_local(void* l0, int32_t l1) {
    int64_t l2, l4;
    bool l3;
    int32_t t0;
    l2 = ((int64_t) (int32_t) l1);
    if ((INT64_C(0) <= l2)) {
        l4 = ((vader_array_t*) l0)->length;
        l3 = (l2 < l4);
    } else {
        l3 = false;
    }
    if (!(l3)) {
        return l1;
    }
    l2 = ((int64_t) (int32_t) l1);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    t0 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l2];
    return t0;
}

static vader_box_t vader_midir_optimise$remap_local_opt(void* l0, vader_box_t l1) {
    int32_t l2;
    int32_t t0;
    if (l1.tag == 0u) {
        return vader_box_obj(0u, NULL);
    }
    if (!(l1.tag == 338u)) {
        return vader_box_obj(0u, NULL);
    }
    l2 = ((int32_t) l1.payload.i);
    t0 = vader_midir_optimise$remap_local(l0, l2);
    return vader_box_i32(338u, t0);
}

static void* vader_midir_optimise$remap_locals(void* l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    int64_t l3, l5;
    int32_t l6, l7;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 7u, 338u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_array_t*) l1)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a1_arr;
    l4 = l1;
    l3 = ((vader_array_t*) l4)->length;
    l5 = INT64_C(0);
    vader_array_t* _pc15_hdr = (vader_array_t*) l2;
    size_t _pc15_len = _pc15_hdr->length;
    size_t _pc15_cap = (_pc15_hdr->offset == 0 && !vader_array_is_borrowed(_pc15_hdr) && _pc15_hdr->length >= _pc15_hdr->buf->length) ? _pc15_hdr->capacity : (size_t) 0;
    void* _pc15_slots = _pc15_hdr->buf->slots;
    for (;;) {
        if ((l5 < l3)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            l6 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l5];
            l7 = vader_midir_optimise$remap_local(l0, l6);
            if (VADER_LIKELY(_pc15_len < _pc15_cap)) {
                ((int32_t*) _pc15_slots)[_pc15_len] = (int32_t) (l7);
                _pc15_len += 1;
            } else {
                _pc15_hdr->length = _pc15_len;
                if (_pc15_hdr->buf->length < _pc15_len) {
                    _pc15_hdr->buf->length = _pc15_len;
                }
                vader_array_push_i32((vader_array_t*) l2, l7);
                _pc15_hdr = (vader_array_t*) l2;
                _pc15_len = _pc15_hdr->length;
                _pc15_cap = (_pc15_hdr->offset == 0 && !vader_array_is_borrowed(_pc15_hdr) && _pc15_hdr->length >= _pc15_hdr->buf->length) ? _pc15_hdr->capacity : (size_t) 0;
                _pc15_slots = _pc15_hdr->buf->slots;
            }
            l5 = (l5 + INT64_C(1));
            continue;
        }
        _pc15_hdr->length = _pc15_len;
        if (_pc15_hdr->buf->length < _pc15_len) {
            _pc15_hdr->buf->length = _pc15_len;
        }
        break;
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_optimise$remap_terminator(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    void* l6 = NULL;
    int32_t l3, l4, l5;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &t1 };
    void** gc_raw_roots[4] = { &l1, &l2, &l6, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1370u) {
        t0 = l0.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1373u) {
        t0 = l0.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1371u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir$TermCondBranch_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir$TermCondBranch_t*) t0)->f_cond;
        l3 = vader_midir_optimise$remap_local(l1, l3);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir$TermCondBranch_t*) t0)->f_then_block;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir$TermCondBranch_t*) t0)->f_else_block;
        vader_struct_vader_midir$TermCondBranch_t* _a0_obj = (vader_struct_vader_midir$TermCondBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$TermCondBranch_t));
        vader_obj_header_init(_a0_obj, 1371u);
        _a0_obj->f_span = l2;
        _a0_obj->f_cond = l3;
        _a0_obj->f_then_block = l4;
        _a0_obj->f_else_block = l5;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0.tag == 1372u)) {
        t1 = l0;
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l0.payload.obj;
    l2 = ((vader_struct_vader_midir$TermReturn_t*) t0)->f_span;
    t0 = l0.payload.obj;
    l6 = ((vader_struct_vader_midir$TermReturn_t*) t0)->f_values;
    l6 = vader_midir_optimise$remap_locals(l1, l6);
    vader_struct_vader_midir$TermReturn_t* _a1_obj = (vader_struct_vader_midir$TermReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$TermReturn_t));
    vader_obj_header_init(_a1_obj, 1372u);
    _a1_obj->f_span = l2;
    _a1_obj->f_values = l6;
    t0 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

void vader_midir_optimise$report_heap_allocations(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l6 = NULL;
    int64_t l3, l4;
    vader_string_t l5 = 0;
    vader_string_t l7 = 0;
    vader_string_t l8 = 0;
    vader_string_t l9 = 0;
    int64_t t0;
    void* t1 = NULL;
    int32_t t2;
    vader_string_t t3 = 0;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l6, &t1 };
    vader_string_t* gc_atom_roots[5] = { &l5, &l7, &l8, &l9, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_vader_midir_optimise$EscapeStats_t*) l0)->f_heap_sites)->length;
    if (t0 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 335u);
    t1 = (void*) _a0_arr;
    vader_struct_std_string__builder$StringBuilder_t* _a1_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
    vader_obj_header_init(_a1_obj, 618u);
    _a1_obj->f_parts = t1;
    l1 = (void*) _a1_obj;
    std_string__builder$append(l1, 8u);
    l2 = (void*) vader_buffer_new((size_t) INT64_C(102));
    l3 = INT64_C(0);
    l3 = std_core$write_string_at(l2, l3, 39u);
    l4 = ((vader_array_t*) ((vader_struct_vader_midir_optimise$EscapeStats_t*) l0)->f_heap_sites)->length;
    l3 = std_core$write_int(l2, l3, l4);
    l3 = std_core$write_string_at(l2, l3, 184u);
    t2 = ((vader_struct_vader_midir_optimise$EscapeStats_t*) l0)->f_total_allocs;
    l4 = ((int64_t) (int32_t) t2);
    l3 = std_core$write_int(l2, l3, l4);
    l3 = std_core$write_string_at(l2, l3, 57u);
    t2 = ((vader_struct_vader_midir_optimise$EscapeStats_t*) l0)->f_stack_promoted;
    l4 = ((int64_t) (int32_t) t2);
    l3 = std_core$write_int(l2, l3, l4);
    l3 = std_core$write_string_at(l2, l3, 323u);
    l5 = std_core$finish_buffer(l2, l3);
    std_string__builder$append(l1, l5);
    l2 = ((vader_struct_vader_midir_optimise$EscapeStats_t*) l0)->f_heap_sites;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l6 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        l5 = toolchain_span$source_position(((vader_struct_vader_midir_optimise$EscapeSite_t*) l6)->f_span);
        l7 = ((vader_struct_vader_midir_optimise$EscapeSite_t*) l6)->f_kind;
        l8 = ((vader_struct_vader_midir_optimise$EscapeSite_t*) l6)->f_type_name;
        l9 = concat_7(26u, l5, 971u, l7, 14u, l8, 117u);
        std_string__builder$append(l1, l9);
        l4 = (l4 + INT64_C(1));
    }
    t3 = std_string__builder$StringBuilder$std_core$Display$to_string(l1);
    std_io$eprintln__string(t3);
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_midir_optimise$with_dst(vader_box_t l0, int32_t l1) {
    vader_box_t l2 = vader_box_null(), l5 = vader_box_null(), l13 = vader_box_null();
    void* l3 = NULL;
    void* l4 = NULL;
    void* l12 = NULL;
    int32_t l6, l8, l11;
    uint8_t l7;
    vader_string_t l9 = 0;
    bool l10;
    void* t0 = NULL;
    vader_box_t* gc_roots[4] = { &l0, &l2, &l5, &l13 };
    void** gc_raw_roots[4] = { &l3, &l4, &l12, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1341u) {
        l3 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrConst_t*) l3)->f_span;
        l2 = ((vader_struct_vader_midir$InstrConst_t*) l3)->f_value;
        l5 = ((vader_struct_vader_midir$InstrConst_t*) l3)->f_type;
        vader_struct_vader_midir$InstrConst_t* _a0_obj = (vader_struct_vader_midir$InstrConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrConst_t));
        vader_obj_header_init(_a0_obj, 1341u);
        _a0_obj->f_span = l4;
        _a0_obj->f_dst = l1;
        _a0_obj->f_value = l2;
        _a0_obj->f_type = l5;
        t0 = (void*) _a0_obj;
        l2 = vader_ref_box(t0);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1353u) {
        l3 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrMove_t*) l3)->f_span;
        l6 = ((vader_struct_vader_midir$InstrMove_t*) l3)->f_src;
        vader_struct_vader_midir$InstrMove_t* _a1_obj = (vader_struct_vader_midir$InstrMove_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrMove_t));
        vader_obj_header_init(_a1_obj, 1353u);
        _a1_obj->f_span = l4;
        _a1_obj->f_dst = l1;
        _a1_obj->f_src = l6;
        t0 = (void*) _a1_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1334u) {
        l3 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrBinOp_t*) l3)->f_span;
        l7 = ((vader_struct_vader_midir$InstrBinOp_t*) l3)->f_op;
        l6 = ((vader_struct_vader_midir$InstrBinOp_t*) l3)->f_lhs;
        l8 = ((vader_struct_vader_midir$InstrBinOp_t*) l3)->f_rhs;
        l5 = ((vader_struct_vader_midir$InstrBinOp_t*) l3)->f_type;
        vader_struct_vader_midir$InstrBinOp_t* _a2_obj = (vader_struct_vader_midir$InstrBinOp_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrBinOp_t));
        vader_obj_header_init(_a2_obj, 1334u);
        _a2_obj->f_span = l4;
        _a2_obj->f_dst = l1;
        _a2_obj->f_op = l7;
        _a2_obj->f_lhs = l6;
        _a2_obj->f_rhs = l8;
        _a2_obj->f_type = l5;
        t0 = (void*) _a2_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1357u) {
        l3 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrUnOp_t*) l3)->f_span;
        l7 = ((vader_struct_vader_midir$InstrUnOp_t*) l3)->f_op;
        l6 = ((vader_struct_vader_midir$InstrUnOp_t*) l3)->f_operand;
        l5 = ((vader_struct_vader_midir$InstrUnOp_t*) l3)->f_type;
        vader_struct_vader_midir$InstrUnOp_t* _a3_obj = (vader_struct_vader_midir$InstrUnOp_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrUnOp_t));
        vader_obj_header_init(_a3_obj, 1357u);
        _a3_obj->f_span = l4;
        _a3_obj->f_dst = l1;
        _a3_obj->f_op = l7;
        _a3_obj->f_operand = l6;
        _a3_obj->f_type = l5;
        t0 = (void*) _a3_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1345u) {
        l3 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrFieldGet_t*) l3)->f_span;
        l6 = ((vader_struct_vader_midir$InstrFieldGet_t*) l3)->f_target;
        l5 = ((vader_struct_vader_midir$InstrFieldGet_t*) l3)->f_type;
        l9 = ((vader_struct_vader_midir$InstrFieldGet_t*) l3)->f_field;
        vader_struct_vader_midir$InstrFieldGet_t* _a4_obj = (vader_struct_vader_midir$InstrFieldGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrFieldGet_t));
        vader_obj_header_init(_a4_obj, 1345u);
        _a4_obj->f_span = l4;
        _a4_obj->f_dst = l1;
        _a4_obj->f_target = l6;
        _a4_obj->f_type = l5;
        _a4_obj->f_field = l9;
        t0 = (void*) _a4_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1358u) {
        l3 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrUnionFieldGet_t*) l3)->f_span;
        l6 = ((vader_struct_vader_midir$InstrUnionFieldGet_t*) l3)->f_target;
        l5 = ((vader_struct_vader_midir$InstrUnionFieldGet_t*) l3)->f_type;
        l9 = ((vader_struct_vader_midir$InstrUnionFieldGet_t*) l3)->f_field;
        vader_struct_vader_midir$InstrUnionFieldGet_t* _a5_obj = (vader_struct_vader_midir$InstrUnionFieldGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrUnionFieldGet_t));
        vader_obj_header_init(_a5_obj, 1358u);
        _a5_obj->f_span = l4;
        _a5_obj->f_dst = l1;
        _a5_obj->f_target = l6;
        _a5_obj->f_type = l5;
        _a5_obj->f_field = l9;
        t0 = (void*) _a5_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1328u) {
        l3 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrArrayGet_t*) l3)->f_span;
        l6 = ((vader_struct_vader_midir$InstrArrayGet_t*) l3)->f_target;
        l5 = ((vader_struct_vader_midir$InstrArrayGet_t*) l3)->f_type;
        l8 = ((vader_struct_vader_midir$InstrArrayGet_t*) l3)->f_index;
        l10 = ((vader_struct_vader_midir$InstrArrayGet_t*) l3)->f_bounds_safe;
        vader_struct_vader_midir$InstrArrayGet_t* _a6_obj = (vader_struct_vader_midir$InstrArrayGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrArrayGet_t));
        vader_obj_header_init(_a6_obj, 1328u);
        _a6_obj->f_span = l4;
        _a6_obj->f_dst = l1;
        _a6_obj->f_target = l6;
        _a6_obj->f_type = l5;
        _a6_obj->f_index = l8;
        _a6_obj->f_bounds_safe = l10;
        t0 = (void*) _a6_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1329u) {
        l3 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrArrayLen_t*) l3)->f_span;
        l6 = ((vader_struct_vader_midir$InstrArrayLen_t*) l3)->f_target;
        vader_struct_vader_midir$InstrArrayLen_t* _a7_obj = (vader_struct_vader_midir$InstrArrayLen_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrArrayLen_t));
        vader_obj_header_init(_a7_obj, 1329u);
        _a7_obj->f_span = l4;
        _a7_obj->f_dst = l1;
        _a7_obj->f_target = l6;
        t0 = (void*) _a7_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1333u) {
        l3 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrArraySlice_t*) l3)->f_span;
        l5 = ((vader_struct_vader_midir$InstrArraySlice_t*) l3)->f_type;
        l6 = ((vader_struct_vader_midir$InstrArraySlice_t*) l3)->f_target;
        l8 = ((vader_struct_vader_midir$InstrArraySlice_t*) l3)->f_lo;
        l11 = ((vader_struct_vader_midir$InstrArraySlice_t*) l3)->f_hi;
        vader_struct_vader_midir$InstrArraySlice_t* _a8_obj = (vader_struct_vader_midir$InstrArraySlice_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrArraySlice_t));
        vader_obj_header_init(_a8_obj, 1333u);
        _a8_obj->f_span = l4;
        _a8_obj->f_dst = l1;
        _a8_obj->f_type = l5;
        _a8_obj->f_target = l6;
        _a8_obj->f_lo = l8;
        _a8_obj->f_hi = l11;
        t0 = (void*) _a8_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1354u) {
        l3 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrStructNew_t*) l3)->f_span;
        l5 = ((vader_struct_vader_midir$InstrStructNew_t*) l3)->f_type;
        l12 = ((vader_struct_vader_midir$InstrStructNew_t*) l3)->f_fields;
        l10 = ((vader_struct_vader_midir$InstrStructNew_t*) l3)->f_stack;
        vader_struct_vader_midir$InstrStructNew_t* _a9_obj = (vader_struct_vader_midir$InstrStructNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrStructNew_t));
        vader_obj_header_init(_a9_obj, 1354u);
        _a9_obj->f_span = l4;
        _a9_obj->f_dst = l1;
        _a9_obj->f_type = l5;
        _a9_obj->f_fields = l12;
        _a9_obj->f_stack = l10;
        t0 = (void*) _a9_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1330u) {
        l3 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrArrayNew_t*) l3)->f_span;
        l5 = ((vader_struct_vader_midir$InstrArrayNew_t*) l3)->f_type;
        l6 = ((vader_struct_vader_midir$InstrArrayNew_t*) l3)->f_length;
        l12 = ((vader_struct_vader_midir$InstrArrayNew_t*) l3)->f_elements;
        l10 = ((vader_struct_vader_midir$InstrArrayNew_t*) l3)->f_stack;
        vader_struct_vader_midir$InstrArrayNew_t* _a10_obj = (vader_struct_vader_midir$InstrArrayNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrArrayNew_t));
        vader_obj_header_init(_a10_obj, 1330u);
        _a10_obj->f_span = l4;
        _a10_obj->f_dst = l1;
        _a10_obj->f_type = l5;
        _a10_obj->f_length = l6;
        _a10_obj->f_elements = l12;
        _a10_obj->f_stack = l10;
        t0 = (void*) _a10_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1342u) {
        l3 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrDataConst_t*) l3)->f_span;
        l5 = ((vader_struct_vader_midir$InstrDataConst_t*) l3)->f_type;
        l6 = ((vader_struct_vader_midir$InstrDataConst_t*) l3)->f_pool_index;
        vader_struct_vader_midir$InstrDataConst_t* _a11_obj = (vader_struct_vader_midir$InstrDataConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrDataConst_t));
        vader_obj_header_init(_a11_obj, 1342u);
        _a11_obj->f_span = l4;
        _a11_obj->f_dst = l1;
        _a11_obj->f_type = l5;
        _a11_obj->f_pool_index = l6;
        t0 = (void*) _a11_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1349u) {
        l3 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrGlobalGet_t*) l3)->f_span;
        l5 = ((vader_struct_vader_midir$InstrGlobalGet_t*) l3)->f_type;
        l6 = ((vader_struct_vader_midir$InstrGlobalGet_t*) l3)->f_slot;
        vader_struct_vader_midir$InstrGlobalGet_t* _a12_obj = (vader_struct_vader_midir$InstrGlobalGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrGlobalGet_t));
        vader_obj_header_init(_a12_obj, 1349u);
        _a12_obj->f_span = l4;
        _a12_obj->f_dst = l1;
        _a12_obj->f_type = l5;
        _a12_obj->f_slot = l6;
        t0 = (void*) _a12_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1355u) {
        l3 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrTypeCheck_t*) l3)->f_span;
        l6 = ((vader_struct_vader_midir$InstrTypeCheck_t*) l3)->f_value;
        l5 = ((vader_struct_vader_midir$InstrTypeCheck_t*) l3)->f_check_type;
        vader_struct_vader_midir$InstrTypeCheck_t* _a13_obj = (vader_struct_vader_midir$InstrTypeCheck_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrTypeCheck_t));
        vader_obj_header_init(_a13_obj, 1355u);
        _a13_obj->f_span = l4;
        _a13_obj->f_dst = l1;
        _a13_obj->f_value = l6;
        _a13_obj->f_check_type = l5;
        t0 = (void*) _a13_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1356u) {
        l3 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrTypeConst_t*) l3)->f_span;
        l5 = ((vader_struct_vader_midir$InstrTypeConst_t*) l3)->f_type;
        l13 = ((vader_struct_vader_midir$InstrTypeConst_t*) l3)->f_value_type;
        vader_struct_vader_midir$InstrTypeConst_t* _a14_obj = (vader_struct_vader_midir$InstrTypeConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrTypeConst_t));
        vader_obj_header_init(_a14_obj, 1356u);
        _a14_obj->f_span = l4;
        _a14_obj->f_dst = l1;
        _a14_obj->f_type = l5;
        _a14_obj->f_value_type = l13;
        t0 = (void*) _a14_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1337u) {
        l3 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrCast_t*) l3)->f_span;
        l6 = ((vader_struct_vader_midir$InstrCast_t*) l3)->f_value;
        l5 = ((vader_struct_vader_midir$InstrCast_t*) l3)->f_type;
        vader_struct_vader_midir$InstrCast_t* _a15_obj = (vader_struct_vader_midir$InstrCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrCast_t));
        vader_obj_header_init(_a15_obj, 1337u);
        _a15_obj->f_span = l4;
        _a15_obj->f_dst = l1;
        _a15_obj->f_value = l6;
        _a15_obj->f_type = l5;
        t0 = (void*) _a15_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1339u) {
        l3 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrCellNew_t*) l3)->f_span;
        l6 = ((vader_struct_vader_midir$InstrCellNew_t*) l3)->f_value;
        l5 = ((vader_struct_vader_midir$InstrCellNew_t*) l3)->f_value_type;
        vader_struct_vader_midir$InstrCellNew_t* _a16_obj = (vader_struct_vader_midir$InstrCellNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrCellNew_t));
        vader_obj_header_init(_a16_obj, 1339u);
        _a16_obj->f_span = l4;
        _a16_obj->f_dst = l1;
        _a16_obj->f_value = l6;
        _a16_obj->f_value_type = l5;
        t0 = (void*) _a16_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1338u) {
        l3 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrCellGet_t*) l3)->f_span;
        l6 = ((vader_struct_vader_midir$InstrCellGet_t*) l3)->f_cell;
        l5 = ((vader_struct_vader_midir$InstrCellGet_t*) l3)->f_value_type;
        vader_struct_vader_midir$InstrCellGet_t* _a17_obj = (vader_struct_vader_midir$InstrCellGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrCellGet_t));
        vader_obj_header_init(_a17_obj, 1338u);
        _a17_obj->f_span = l4;
        _a17_obj->f_dst = l1;
        _a17_obj->f_cell = l6;
        _a17_obj->f_value_type = l5;
        t0 = (void*) _a17_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1352u) {
        l3 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrMakeClosure_t*) l3)->f_span;
        l12 = ((vader_struct_vader_midir$InstrMakeClosure_t*) l3)->f_fn_symbol;
        l6 = ((vader_struct_vader_midir$InstrMakeClosure_t*) l3)->f_env;
        l5 = ((vader_struct_vader_midir$InstrMakeClosure_t*) l3)->f_type;
        vader_struct_vader_midir$InstrMakeClosure_t* _a18_obj = (vader_struct_vader_midir$InstrMakeClosure_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrMakeClosure_t));
        vader_obj_header_init(_a18_obj, 1352u);
        _a18_obj->f_span = l4;
        _a18_obj->f_dst = l1;
        _a18_obj->f_fn_symbol = l12;
        _a18_obj->f_env = l6;
        _a18_obj->f_type = l5;
        t0 = (void*) _a18_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1348u) {
        l3 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrFnRef_t*) l3)->f_span;
        l12 = ((vader_struct_vader_midir$InstrFnRef_t*) l3)->f_fn_symbol;
        l5 = ((vader_struct_vader_midir$InstrFnRef_t*) l3)->f_type;
        vader_struct_vader_midir$InstrFnRef_t* _a19_obj = (vader_struct_vader_midir$InstrFnRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrFnRef_t));
        vader_obj_header_init(_a19_obj, 1348u);
        _a19_obj->f_span = l4;
        _a19_obj->f_dst = l1;
        _a19_obj->f_fn_symbol = l12;
        _a19_obj->f_type = l5;
        t0 = (void*) _a19_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1347u) {
        l3 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrFnAddr_t*) l3)->f_span;
        l12 = ((vader_struct_vader_midir$InstrFnAddr_t*) l3)->f_fn_symbol;
        l5 = ((vader_struct_vader_midir$InstrFnAddr_t*) l3)->f_type;
        vader_struct_vader_midir$InstrFnAddr_t* _a20_obj = (vader_struct_vader_midir$InstrFnAddr_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrFnAddr_t));
        vader_obj_header_init(_a20_obj, 1347u);
        _a20_obj->f_span = l4;
        _a20_obj->f_dst = l1;
        _a20_obj->f_fn_symbol = l12;
        _a20_obj->f_type = l5;
        t0 = (void*) _a20_obj;
        l2 = vader_ref_box(t0);
    } else {
        if (!((l0.tag == 1331u || l0.tag == 1332u || l0.tag == 1335u || l0.tag == 1336u || l0.tag == 1340u || l0.tag == 1343u || l0.tag == 1344u || l0.tag == 1346u || l0.tag == 1350u || l0.tag == 1351u || l0.tag == 1359u || l0.tag == 1360u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = l0;
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}
