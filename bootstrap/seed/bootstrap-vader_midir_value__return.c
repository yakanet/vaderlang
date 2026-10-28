#include "bootstrap.split.h"

static void* vader_midir_value__return$absent_arm(void* l0, int32_t l1, int32_t l2, int32_t l3, void* l4);
static int32_t vader_midir_value__return$add_local(void* l0, vader_string_t l1, vader_box_t l2);
static vader_string_t vader_midir_value__return$callee_mangle(void* l0, void* l1, void* l2);
static vader_box_t vader_midir_value__return$callee_shape(void* l0, void* l1, void* l2);
static void* vader_midir_value__return$choose_functions(void* l0, void* l1, void* l2);
static int32_t vader_midir_value__return$const_i32(void* l0, void* l1, int64_t l2, void* l3);
static void vader_midir_value__return$drop_records_touching(void* l0, int32_t l1);
static int32_t vader_midir_value__return$emit_rewritten_block(void* l0, void* l1, void* l2, void* l3, void* l4, void* l5, int32_t l6);
static void vader_midir_value__return$fill_mangles_by_symbol_id(void* l0, void* l1, void* l2);
static void* vader_midir_value__return$forward_block_with(void* l0, void* l1);
static void* vader_midir_value__return$forward_struct_fields_in_fn(void* l0);
static void* vader_midir_value__return$forwarded_symbol(void* l0, vader_string_t l1);
static void* vader_midir_value__return$forwarding_body(void* l0, vader_string_t l1);
static bool vader_midir_value__return$has_null_variant(vader_box_t l0);
static void* vader_midir_value__return$join_of_predecessors(void* l0, void* l1, int32_t l2);
static void vader_midir_value__return$mark_forwarding(vader_string_t l0, void* l1, void* l2);
static void vader_midir_value__return$note_call(void* l0, void* l1, void* l2, void* l3, void* l4, vader_string_t l5);
static void vader_midir_value__return$note_symbol(void* l0, void* l1, void* l2);
static void* vader_midir_value__return$nullable_results(void* l0);
static vader_box_t vader_midir_value__return$nullable_return_of(void* l0);
static void vader_midir_value__return$place(void* l0, void* l1, int32_t l2, int32_t l3, void* l4);
static void vader_midir_value__return$plan_forwarding(void* l0, void* l1, void* l2, void* l3);
static void* vader_midir_value__return$present_arm(void* l0, int32_t l1, void* l2, vader_box_t l3, int32_t l4, int32_t l5, void* l6);
static vader_box_t vader_midir_value__return$return_source(void* l0, int32_t l1);
static vader_box_t vader_midir_value__return$returns_fresh_composite(void* l0);
static void* vader_midir_value__return$rewrite_call_sites(void* l0, void* l1, void* l2, void* l3);
static void* vader_midir_value__return$rewrite_callee(void* l0, void* l1, bool l2);
static void* vader_midir_value__return$rewrite_nullable_return(void* l0, void* l1, void* l2);
static void* vader_midir_value__return$rewrite_return_block(void* l0, void* l1, void* l2);
static bool vader_midir_value__return$same_carrier(vader_box_t l0, vader_box_t l1);
static void* vader_midir_value__return$scalarised_copy(void* l0, vader_string_t l1);
static vader_string_t vader_midir_value__return$scalarised_copy_mangle(vader_string_t l0);
static void* vader_midir_value__return$scalarised_forms(void* l0, vader_box_t l1);
static int32_t vader_midir_value__return$tuple_field_index(vader_string_t l0);
static vader_box_t vader_midir_value__return$zero_const_for(vader_box_t l0);
static int32_t vader_midir_value__return$zero_of(void* l0, void* l1, vader_box_t l2, void* l3);

static void* vader_midir_value__return$absent_arm(void* l0, int32_t l1, int32_t l2, int32_t l3, void* l4) {
    void* l5 = NULL;
    void* l6 = NULL;
    vader_box_t l7 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l7 };
    void** gc_raw_roots[5] = { &l0, &l4, &l5, &l6, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l5 = ((vader_struct_vader_midir$InstrCall_t*) l0)->f_span;
    vader_struct_vader_midir$ConstNull_t* _a0_obj = (vader_struct_vader_midir$ConstNull_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$ConstNull_t));
    vader_obj_header_init(_a0_obj, 1322u);
    l6 = (void*) _a0_obj;
    l7 = ((vader_struct_vader_midir$InstrCall_t*) l0)->f_type;
    vader_struct_vader_midir$InstrConst_t* _a1_obj = (vader_struct_vader_midir$InstrConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrConst_t));
    vader_obj_header_init(_a1_obj, 1341u);
    _a1_obj->f_span = l5;
    _a1_obj->f_dst = l1;
    _a1_obj->f_value = vader_ref_box(l6);
    _a1_obj->f_type = l7;
    t0 = (void*) _a1_obj;
    vader_array_t* _a2_arr = vader_array_new(268u, 1u, 13u, 2082u);
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = t0;
    l5 = (void*) _a2_arr;
    vader_struct_vader_midir$TermBranch_t* _a3_obj = (vader_struct_vader_midir$TermBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$TermBranch_t));
    vader_obj_header_init(_a3_obj, 1370u);
    _a3_obj->f_span = ((vader_struct_vader_midir$InstrCall_t*) l0)->f_span;
    _a3_obj->f_target = l3;
    l6 = (void*) _a3_obj;
    vader_struct_vader_midir$BasicBlock_t* _a4_obj = (vader_struct_vader_midir$BasicBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$BasicBlock_t));
    vader_obj_header_init(_a4_obj, 1304u);
    _a4_obj->f_id = l2;
    _a4_obj->f_instructions = l5;
    _a4_obj->f_terminator = vader_ref_box(l6);
    _a4_obj->f_span = l4;
    t0 = (void*) _a4_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_midir_value__return$add_local(void* l0, vader_string_t l1, vader_box_t l2) {
    int32_t l3;
    vader_string_t l4 = 0;
    int64_t l5, l7;
    void* l6 = NULL;
    int64_t t0;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l0, &l6 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l4, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) l0)->length;
    l3 = ((int32_t) (int64_t) t0);
    l4 = l1;
    l5 = vader_host_std_core$byte_len(l4);
    l6 = (void*) vader_buffer_new((size_t) (INT64_C(22) + l5));
    l5 = INT64_C(0);
    l5 = std_core$write_string_at(l6, l5, 258u);
    l5 = std_core$write_string_at(l6, l5, l4);
    l5 = std_core$write_string_at(l6, l5, 977u);
    l7 = ((vader_array_t*) l0)->length;
    l5 = std_core$write_int(l6, l5, l7);
    t1 = std_core$finish_buffer(l6, l5);
    vader_struct_vader_midir$CFGLocal_t* _a0_obj = (vader_struct_vader_midir$CFGLocal_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$CFGLocal_t));
    vader_obj_header_init(_a0_obj, 1307u);
    _a0_obj->f_name = t1;
    _a0_obj->f_type = l2;
    _a0_obj->f_symbol = vader_box_obj(0u, NULL);
    l6 = (void*) _a0_obj;
    vader_array_push_ref((vader_array_t*) l0, l6);
    { int32_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_midir_value__return$callee_mangle(void* l0, void* l1, void* l2) {
    vader_string_t l3;
    int32_t l4;
    vader_box_t l5;
    vader_box_t t0;
    vader_string_t t1;
    l3 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_name;
    t0 = std_collections$MutableMap$std_core$Index$at__string__Any(l1, l3);
    if (!(t0.tag == 0u)) {
        t1 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_name;
        return t1;
    }
    l4 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_id;
    l5 = std_collections$MutableMap$std_core$Index$at__i32__string(l2, l4);
    if (l5.tag == 0u) {
        t1 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_name;
        return t1;
    }
    t1 = l5.payload.s;
    return t1;
}

static vader_box_t vader_midir_value__return$callee_shape(void* l0, void* l1, void* l2) {
    vader_string_t l3;
    vader_box_t l4;
    int32_t l5;
    void* t0;
    vader_box_t t1;
    l3 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_name;
    l4 = std_collections$MutableMap$std_core$Index$at__string__Any(l1, l3);
    if (!(l4.tag == 0u)) {
        t0 = l4.payload.obj;
        return vader_ref_box(t0);
    }
    l5 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_id;
    l4 = std_collections$MutableMap$std_core$Index$at__i32__string(l2, l5);
    if (l4.tag == 0u) {
        return vader_box_obj(0u, NULL);
    }
    l3 = l4.payload.s;
    t1 = std_collections$MutableMap$std_core$Index$at__string__Any(l1, l3);
    return t1;
}

static void* vader_midir_value__return$choose_functions(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l11 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l18 = NULL;
    void* l20 = NULL;
    int64_t l7, l8, l9, l10;
    vader_box_t l12 = vader_box_null(), l16 = vader_box_null(), l19 = vader_box_null();
    vader_string_t l13 = 0;
    vader_string_t l17 = 0;
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    void* t2 = NULL;
    bool t3;
    int64_t t4;
    vader_box_t* gc_roots[4] = { &l12, &l16, &l19, &t0 };
    void** gc_raw_roots[13] = {
        &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l11, &l14, &l15, &l18, &l20, &t2,
    };
    vader_string_t* gc_atom_roots[3] = { &l13, &l17, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 13u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 335u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 346u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
    l5 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections$MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 533u);
    _a3_obj->f_ekeys = l3;
    _a3_obj->f_evals = l4;
    _a3_obj->f_index = l5;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l3 = (void*) _a3_obj;
    l4 = ((vader_struct_vader_midir$CFGProject_t*) l0)->f_modules;
    l5 = ((vader_struct_std_collections$MutableMap__string__vader_midir_CFGModule_t*) l4)->f_ekeys;
    l6 = ((vader_struct_std_collections$MutableMap__string__vader_midir_CFGModule_t*) l4)->f_evals;
    l7 = INT64_C(0);
    l8 = ((vader_struct_std_collections$MutableMap__string__vader_midir_CFGModule_t*) l4)->f_size;
    while ((l7 < l8)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        t0 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l7];
        t1 = t0.payload.s;
        vader_array_t* _a5_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l7)
        t2 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l7);
        l4 = ((vader_struct_vader_midir$CFGModule_t*) t2)->f_functions;
        l9 = ((vader_array_t*) l4)->length;
        l10 = INT64_C(0);
        while ((l10 < l9)) {
            vader_array_t* _a6_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            l11 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l10);
            t3 = ((vader_struct_vader_core_mono$MonoEntry_t*) ((vader_struct_vader_midir$CFGFunction_t*) l11)->f_origin)->f_is_main;
            if (t3) {
                l10 = (l10 + INT64_C(1));
                continue;
            }
            l12 = vader_core_types$value_abi_tuple_elements(((vader_struct_vader_midir$CFGFunction_t*) l11)->f_return_type);
            if (l12.tag == 0u) {
                l16 = vader_midir_value__return$nullable_return_of(l11);
                if (l16.tag == 0u) {
                    l10 = (l10 + INT64_C(1));
                    continue;
                }
                l15 = l16.payload.obj;
                l17 = ((vader_struct_vader_midir$CFGFunction_t*) l11)->f_mangled;
                l18 = ((vader_struct_vader_midir_value__return$NullableReturn_t*) l15)->f_fields;
                l19 = ((vader_struct_vader_midir_value__return$NullableReturn_t*) l15)->f_struct_type;
                vader_struct_vader_midir_value__return$ReturnShape_t* _a7_obj = (vader_struct_vader_midir_value__return$ReturnShape_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_value__return$ReturnShape_t));
                vader_obj_header_init(_a7_obj, 1389u);
                _a7_obj->f_elements = l18;
                _a7_obj->f_rebuilt = l19;
                _a7_obj->f_forward_to = vader_box_obj(0u, NULL);
                l20 = (void*) _a7_obj;
                std_collections$MutableMap$std_core$IndexSet$set_at__string__Any(l3, l17, vader_ref_box(l20));
                l10 = (l10 + INT64_C(1));
                continue;
            }
            l13 = ((vader_struct_vader_midir$CFGFunction_t*) l11)->f_mangled;
            t2 = l12.payload.obj;
            vader_struct_vader_midir_value__return$ReturnShape_t* _a8_obj = (vader_struct_vader_midir_value__return$ReturnShape_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_value__return$ReturnShape_t));
            vader_obj_header_init(_a8_obj, 1389u);
            _a8_obj->f_elements = t2;
            _a8_obj->f_rebuilt = vader_box_obj(0u, NULL);
            _a8_obj->f_forward_to = vader_box_obj(0u, NULL);
            l14 = (void*) _a8_obj;
            std_collections$MutableMap$std_core$IndexSet$set_at__string__Any(l3, l13, vader_ref_box(l14));
            l10 = (l10 + INT64_C(1));
        }
        l7 = (l7 + INT64_C(1));
    }
    t4 = std_collections$len__string__Any(l3);
    if (!(t4 == INT64_C(0))) {
        vader_midir_value__return$fill_mangles_by_symbol_id(l0, l3, l1);
        vader_midir_value__return$plan_forwarding(l0, l3, l1, l2);
        { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_midir_value__return$const_i32(void* l0, void* l1, int64_t l2, void* l3) {
    void* l4 = NULL;
    void* l6 = NULL;
    int32_t l5;
    void* t0 = NULL;
    void** gc_raw_roots[6] = { &l0, &l1, &l3, &l4, &l6, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = (void*) &vader_data_19;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
    l5 = vader_midir_value__return$add_local(l1, 2694u, vader_ref_box(l4));
    vader_struct_vader_midir$ConstInt_t* _a1_obj = (vader_struct_vader_midir$ConstInt_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$ConstInt_t));
    vader_obj_header_init(_a1_obj, 1321u);
    _a1_obj->f_value = l2;
    l4 = (void*) _a1_obj;
    t0 = (void*) &vader_data_19;
    vader_array_t* _a2_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    l6 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT64_C(0));
    vader_struct_vader_midir$InstrConst_t* _a3_obj = (vader_struct_vader_midir$InstrConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrConst_t));
    vader_obj_header_init(_a3_obj, 1341u);
    _a3_obj->f_span = l3;
    _a3_obj->f_dst = l5;
    _a3_obj->f_value = vader_ref_box(l4);
    _a3_obj->f_type = vader_ref_box(l6);
    l4 = (void*) _a3_obj;
    vader_array_push_ref((vader_array_t*) l0, l4);
    { int32_t __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_midir_value__return$drop_records_touching(void* l0, int32_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l10 = NULL;
    int64_t l6, l7;
    int32_t l8, l9, l11;
    bool l12;
    void** gc_raw_roots[6] = { &l0, &l2, &l3, &l4, &l5, &l10 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 7u, 338u);
    l2 = (void*) _a0_arr;
    l3 = l0;
    l4 = ((vader_struct_std_collections$MutableMap__i32__i32___t*) l3)->f_ekeys;
    l5 = ((vader_struct_std_collections$MutableMap__i32__i32___t*) l3)->f_evals;
    l6 = INT64_C(0);
    l7 = ((vader_struct_std_collections$MutableMap__i32__i32___t*) l3)->f_size;
    while ((l6 < l7)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        l8 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l6];
        vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
        l3 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l6);
        l9 = l8;
        l10 = l3;
        l11 = l1;
        if (l9 == l11) {
            l12 = true;
        } else {
            l12 = std_core$$array$Contains$contains__i32(l10, l1);
        }
        if (l12) {
            vader_array_push_i32((vader_array_t*) l2, l9);
        }
        l6 = (l6 + INT64_C(1));
    }
    l6 = ((vader_array_t*) l2)->length;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        l8 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
        std_collections$remove__i32__i32__(l0, l8);
        l7 = (l7 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static int32_t vader_midir_value__return$emit_rewritten_block(void* l0, void* l1, void* l2, void* l3, void* l4, void* l5, int32_t l6) {
    int32_t l7, l8, l21, l26, l37, l40, l41, l42, l44, l46, l48, l51, l56, l60;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l16 = NULL;
    void* l18 = NULL;
    void* l19 = NULL;
    void* l20 = NULL;
    void* l22 = NULL;
    void* l27 = NULL;
    void* l28 = NULL;
    void* l30 = NULL;
    void* l31 = NULL;
    void* l32 = NULL;
    void* l34 = NULL;
    void* l36 = NULL;
    void* l39 = NULL;
    void* l43 = NULL;
    void* l45 = NULL;
    void* l47 = NULL;
    void* l49 = NULL;
    void* l50 = NULL;
    void* l52 = NULL;
    void* l53 = NULL;
    void* l54 = NULL;
    void* l55 = NULL;
    void* l57 = NULL;
    void* l58 = NULL;
    void* l59 = NULL;
    void* l62 = NULL;
    void* l63 = NULL;
    int64_t l11, l12, l23, l24;
    vader_box_t l13 = vader_box_null(), l14 = vader_box_null(), l15 = vader_box_null(), l17 = vader_box_null(), l25 = vader_box_null(), l33 = vader_box_null(), l35 = vader_box_null(), l38 = vader_box_null(), l61 = vader_box_null();
    vader_string_t l29 = 0;
    void* t0 = NULL;
    vader_box_t* gc_roots[9] = { &l13, &l14, &l15, &l17, &l25, &l33, &l35, &l38, &l61 };
    void** gc_raw_roots[36] = {
        &l0, &l1, &l2, &l3, &l4, &l5, &l9, &l10, &l16, &l18, &l19, &l20, &l22, &l27, &l28, &l30,
        &l31, &l32, &l34, &l36, &l39, &l43, &l45, &l47, &l49, &l50, &l52, &l53, &l54, &l55, &l57,
        &l58, &l59, &l62, &l63, &t0,
    };
    vader_string_t* gc_atom_roots[1] = { &l29 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 9u, 36u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l7 = l6;
    l8 = ((vader_struct_vader_midir$BasicBlock_t*) l0)->f_id;
    vader_array_t* _a0_arr = vader_array_new(268u, 0u, 13u, 2082u);
    l9 = (void*) _a0_arr;
    l10 = ((vader_struct_vader_midir$BasicBlock_t*) l0)->f_instructions;
    l11 = ((vader_array_t*) l10)->length;
    l12 = INT64_C(0);
    while ((l12 < l11)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l10);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l13 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l12);
        if (l13.tag == 1335u) {
            t0 = l13.payload.obj;
            l15 = vader_midir$call_single_dst(t0);
            if (l15.tag == 0u) {
                l16 = l13.payload.obj;
                vader_array_push_ref((vader_array_t*) l9, l16);
                l12 = (l12 + INT64_C(1));
                continue;
            }
            t0 = l13.payload.obj;
            l17 = vader_midir_value__return$callee_shape(((vader_struct_vader_midir$InstrCall_t*) t0)->f_callee, l1, l2);
            if (l17.tag == 0u) {
                l18 = l13.payload.obj;
                vader_array_push_ref((vader_array_t*) l9, l18);
                l12 = (l12 + INT64_C(1));
                continue;
            }
            vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
            l19 = (void*) _a2_arr;
            t0 = l17.payload.obj;
            if (!(((vader_struct_vader_midir_value__return$ReturnShape_t*) t0)->f_rebuilt.tag == 0u)) {
                t0 = (void*) &vader_data_19;
                vader_array_t* _a3_slotarr = ((vader_array_t*) t0);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                l20 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) INT64_C(0));
                l21 = vader_midir_value__return$add_local(l3, 1721u, vader_ref_box(l20));
                vader_array_push_i32((vader_array_t*) l19, l21);
            }
            t0 = l17.payload.obj;
            l22 = ((vader_struct_vader_midir_value__return$ReturnShape_t*) t0)->f_elements;
            l23 = ((vader_array_t*) l22)->length;
            l24 = INT64_C(0);
            while ((l24 < l23)) {
                vader_array_t* _a4_slotarr = ((vader_array_t*) l22);
                VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                l25 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l24);
                l26 = vader_midir_value__return$add_local(l3, 1719u, l25);
                vader_array_push_i32((vader_array_t*) l19, l26);
                l24 = (l24 + INT64_C(1));
            }
            t0 = l17.payload.obj;
            if (((vader_struct_vader_midir_value__return$ReturnShape_t*) t0)->f_forward_to.tag == 0u) {
                t0 = l13.payload.obj;
                l27 = ((vader_struct_vader_midir$InstrCall_t*) t0)->f_callee;
            } else {
                t0 = l13.payload.obj;
                l28 = ((vader_struct_vader_midir$InstrCall_t*) t0)->f_callee;
                t0 = l17.payload.obj;
                l29 = ((vader_struct_vader_midir_value__return$ReturnShape_t*) t0)->f_forward_to.payload.s;
                l27 = vader_midir_value__return$forwarded_symbol(l28, l29);
            }
            l30 = l13.payload.obj;
            l31 = ((vader_struct_vader_midir$InstrCall_t*) l30)->f_span;
            l32 = ((vader_struct_vader_midir$InstrCall_t*) l30)->f_args;
            l33 = ((vader_struct_vader_midir$InstrCall_t*) l30)->f_type;
            vader_struct_vader_midir$InstrCall_t* _a5_obj = (vader_struct_vader_midir$InstrCall_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrCall_t));
            vader_obj_header_init(_a5_obj, 1335u);
            _a5_obj->f_span = l31;
            _a5_obj->f_dsts = l19;
            _a5_obj->f_callee = l27;
            _a5_obj->f_args = l32;
            _a5_obj->f_type = l33;
            l34 = (void*) _a5_obj;
            vader_array_push_ref((vader_array_t*) l9, l34);
            t0 = l17.payload.obj;
            l35 = ((vader_struct_vader_midir_value__return$ReturnShape_t*) t0)->f_rebuilt;
            if (l35.tag == 0u) {
                t0 = l13.payload.obj;
                l36 = ((vader_struct_vader_midir$InstrCall_t*) t0)->f_span;
                l37 = ((int32_t) l15.payload.i);
                t0 = l13.payload.obj;
                l38 = ((vader_struct_vader_midir$InstrCall_t*) t0)->f_type;
                vader_struct_vader_midir$InstrStructNew_t* _a6_obj = (vader_struct_vader_midir$InstrStructNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrStructNew_t));
                vader_obj_header_init(_a6_obj, 1354u);
                _a6_obj->f_span = l36;
                _a6_obj->f_dst = l37;
                _a6_obj->f_type = l38;
                _a6_obj->f_fields = l19;
                _a6_obj->f_stack = false;
                l39 = (void*) _a6_obj;
                vader_array_push_ref((vader_array_t*) l9, l39);
                l12 = (l12 + INT64_C(1));
                continue;
            }
            l40 = l7;
            l41 = vader_chk_add(i32, l7, INT32_C(1));
            l42 = vader_chk_add(i32, l7, INT32_C(2));
            l7 = vader_chk_add(i32, l7, INT32_C(3));
            t0 = (void*) &vader_data_21;
            vader_array_t* _a7_slotarr = ((vader_array_t*) t0);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            l43 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) INT64_C(0));
            l44 = vader_midir_value__return$add_local(l3, 1510u, vader_ref_box(l43));
            t0 = l13.payload.obj;
            l45 = ((vader_struct_vader_midir$InstrCall_t*) t0)->f_span;
            l46 = vader_midir_value__return$const_i32(l9, l3, INT64_C(0), l45);
            t0 = l13.payload.obj;
            l47 = ((vader_struct_vader_midir$InstrCall_t*) t0)->f_span;
            vader_array_t* _a8_slotarr = ((vader_array_t*) l19);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a8_slotarr, INT32_C(0))
            l48 = ((int32_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) INT32_C(0)];
            t0 = (void*) &vader_data_21;
            vader_array_t* _a9_slotarr = ((vader_array_t*) t0);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            l49 = vader_array_ref_load_obj(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) INT64_C(0));
            vader_struct_vader_midir$InstrBinOp_t* _a10_obj = (vader_struct_vader_midir$InstrBinOp_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrBinOp_t));
            vader_obj_header_init(_a10_obj, 1334u);
            _a10_obj->f_span = l47;
            _a10_obj->f_dst = l44;
            _a10_obj->f_op = (uint8_t) 12;
            _a10_obj->f_lhs = l48;
            _a10_obj->f_rhs = l46;
            _a10_obj->f_type = vader_ref_box(l49);
            l50 = (void*) _a10_obj;
            vader_array_push_ref((vader_array_t*) l9, l50);
            l51 = ((vader_struct_vader_midir$BasicBlock_t*) l0)->f_id;
            t0 = l13.payload.obj;
            vader_struct_vader_midir$TermCondBranch_t* _a11_obj = (vader_struct_vader_midir$TermCondBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$TermCondBranch_t));
            vader_obj_header_init(_a11_obj, 1371u);
            _a11_obj->f_span = ((vader_struct_vader_midir$InstrCall_t*) t0)->f_span;
            _a11_obj->f_cond = l44;
            _a11_obj->f_then_block = l40;
            _a11_obj->f_else_block = l41;
            l52 = (void*) _a11_obj;
            l53 = ((vader_struct_vader_midir$BasicBlock_t*) l0)->f_span;
            vader_struct_vader_midir$BasicBlock_t* _a12_obj = (vader_struct_vader_midir$BasicBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$BasicBlock_t));
            vader_obj_header_init(_a12_obj, 1304u);
            _a12_obj->f_id = l8;
            _a12_obj->f_instructions = l9;
            _a12_obj->f_terminator = vader_ref_box(l52);
            _a12_obj->f_span = l53;
            l54 = (void*) _a12_obj;
            vader_midir_value__return$place(l4, l5, l8, l51, l54);
            l55 = l13.payload.obj;
            l56 = ((int32_t) l15.payload.i);
            l57 = ((vader_struct_vader_midir$BasicBlock_t*) l0)->f_span;
            l58 = vader_midir_value__return$absent_arm(l55, l56, l40, l42, l57);
            vader_array_push_ref((vader_array_t*) l5, l58);
            l59 = l13.payload.obj;
            l60 = ((int32_t) l15.payload.i);
            l61 = l35;
            l62 = ((vader_struct_vader_midir$BasicBlock_t*) l0)->f_span;
            l63 = vader_midir_value__return$present_arm(l59, l60, l19, l61, l41, l42, l62);
            vader_array_push_ref((vader_array_t*) l5, l63);
            l8 = l42;
            vader_array_t* _a13_arr = vader_array_new(268u, 0u, 13u, 2082u);
            l9 = (void*) _a13_arr;
            l12 = (l12 + INT64_C(1));
            continue;
        }
        l14 = l13;
        vader_array_push_ref((vader_array_t*) l9, l14.payload.obj);
        l12 = (l12 + INT64_C(1));
    }
    l21 = ((vader_struct_vader_midir$BasicBlock_t*) l0)->f_id;
    l13 = ((vader_struct_vader_midir$BasicBlock_t*) l0)->f_terminator;
    l10 = ((vader_struct_vader_midir$BasicBlock_t*) l0)->f_span;
    vader_struct_vader_midir$BasicBlock_t* _a14_obj = (vader_struct_vader_midir$BasicBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$BasicBlock_t));
    vader_obj_header_init(_a14_obj, 1304u);
    _a14_obj->f_id = l8;
    _a14_obj->f_instructions = l9;
    _a14_obj->f_terminator = l13;
    _a14_obj->f_span = l10;
    l9 = (void*) _a14_obj;
    vader_midir_value__return$place(l4, l5, l8, l21, l9);
    { int32_t __vret = l7; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_midir_value__return$fill_mangles_by_symbol_id(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l10 = NULL;
    int64_t l6, l7, l8, l9;
    vader_box_t l11 = vader_box_null();
    vader_string_t l12 = 0;
    vader_string_t l14 = 0;
    int32_t l13;
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    void* t2 = NULL;
    vader_box_t* gc_roots[2] = { &l11, &t0 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l4, &l5, &l10, &t2 };
    vader_string_t* gc_atom_roots[3] = { &l12, &l14, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_midir$CFGProject_t*) l0)->f_modules;
    l4 = ((vader_struct_std_collections$MutableMap__string__vader_midir_CFGModule_t*) l3)->f_ekeys;
    l5 = ((vader_struct_std_collections$MutableMap__string__vader_midir_CFGModule_t*) l3)->f_evals;
    l6 = INT64_C(0);
    l7 = ((vader_struct_std_collections$MutableMap__string__vader_midir_CFGModule_t*) l3)->f_size;
    while ((l6 < l7)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
        t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l6];
        t1 = t0.payload.s;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        t2 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
        l3 = ((vader_struct_vader_midir$CFGModule_t*) t2)->f_functions;
        l8 = ((vader_array_t*) l3)->length;
        l9 = INT64_C(0);
        while ((l9 < l8)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            l10 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l9);
            l11 = ((vader_struct_vader_core_mono$MonoEntry_t*) ((vader_struct_vader_midir$CFGFunction_t*) l10)->f_origin)->f_symbol;
            if (!(l11.tag == 0u)) {
                l12 = ((vader_struct_vader_midir$CFGFunction_t*) l10)->f_mangled;
                t0 = std_collections$MutableMap$std_core$Index$at__string__Any(l1, l12);
                if (!(t0.tag == 0u)) {
                    t2 = l11.payload.obj;
                    l13 = ((vader_struct_vader_core_symbol$Symbol_t*) t2)->f_id;
                    l14 = ((vader_struct_vader_midir$CFGFunction_t*) l10)->f_mangled;
                    std_collections$MutableMap$std_core$IndexSet$set_at__i32__string(l2, l13, l14);
                }
            }
            l9 = (l9 + INT64_C(1));
        }
        l6 = (l6 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_midir_value__return$forward_block_with(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l8 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l20 = NULL;
    void* l21 = NULL;
    void* l27 = NULL;
    void* l30 = NULL;
    int64_t l4, l5, l9, l10, l25, l26;
    vader_box_t l6 = vader_box_null(), l7 = vader_box_null(), l12 = vader_box_null(), l18 = vader_box_null(), l23 = vader_box_null(), l31 = vader_box_null();
    int32_t l11, l13, l14, l17, l19, l22, l24, l28, l29;
    int64_t t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[7] = { &l6, &l7, &l12, &l18, &l23, &l31, &t2 };
    void** gc_raw_roots[12] = { &l0, &l1, &l2, &l3, &l8, &l15, &l16, &l20, &l21, &l27, &l30, &t1 };
    vader_string_t* gc_atom_roots[1] = { &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 7u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(268u, 0u, 13u, 2082u);
    l2 = (void*) _a0_arr;
    l3 = l0;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l6 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
        t0 = std_collections$len__i32__Any(l1);
        if ((t0 > INT64_C(0))) {
            l7 = vader_midir$multi_dsts(l6);
            if (l7.tag == 0u) {
                l12 = vader_midir$dst_of(l6);
                if (!(l12.tag == 0u)) {
                    l13 = ((int32_t) l12.payload.i);
                    vader_midir_value__return$drop_records_touching(l1, l13);
                }
            } else {
                l8 = l7.payload.obj;
                l9 = ((vader_array_t*) l8)->length;
                l10 = INT64_C(0);
                while ((l10 < l9)) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) l8);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    l11 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l10];
                    vader_midir_value__return$drop_records_touching(l1, l11);
                    l10 = (l10 + INT64_C(1));
                }
            }
        }
        if (l6.tag == 1354u) {
            t1 = l6.payload.obj;
            t2 = vader_core_types$tuple_backing(((vader_struct_vader_midir$InstrStructNew_t*) t1)->f_type);
            if (!(t2.tag == 0u)) {
                t1 = l6.payload.obj;
                l14 = ((vader_struct_vader_midir$InstrStructNew_t*) t1)->f_dst;
                t1 = l6.payload.obj;
                l15 = ((vader_struct_vader_midir$InstrStructNew_t*) t1)->f_fields;
                std_collections$MutableMap$std_core$IndexSet$set_at__i32__Any(l1, l14, vader_ref_box(l15));
                l16 = l6.payload.obj;
                vader_array_push_ref((vader_array_t*) l2, l16);
                l5 = (l5 + INT64_C(1));
                continue;
            }
        }
        if (l6.tag == 1353u) {
            t1 = l6.payload.obj;
            l17 = ((vader_struct_vader_midir$InstrMove_t*) t1)->f_src;
            l18 = std_collections$MutableMap$std_core$Index$at__i32__Any(l1, l17);
            if (!(l18.tag == 0u)) {
                t1 = l6.payload.obj;
                l19 = ((vader_struct_vader_midir$InstrMove_t*) t1)->f_dst;
                l20 = l18.payload.obj;
                std_collections$MutableMap$std_core$IndexSet$set_at__i32__Any(l1, l19, vader_ref_box(l20));
            }
            l21 = l6.payload.obj;
            vader_array_push_ref((vader_array_t*) l2, l21);
            l5 = (l5 + INT64_C(1));
            continue;
        }
        if (l6.tag == 1345u) {
            t1 = l6.payload.obj;
            l22 = ((vader_struct_vader_midir$InstrFieldGet_t*) t1)->f_target;
            l23 = std_collections$MutableMap$std_core$Index$at__i32__Any(l1, l22);
            if (!(l23.tag == 0u)) {
                t1 = l6.payload.obj;
                t3 = ((vader_struct_vader_midir$InstrFieldGet_t*) t1)->f_field;
                l24 = vader_midir_value__return$tuple_field_index(t3);
                if ((l24 >= INT32_C(0))) {
                    l25 = ((int64_t) (int32_t) l24);
                    t1 = l23.payload.obj;
                    l26 = ((vader_array_t*) t1)->length;
                    if ((l25 < l26)) {
                        t1 = l6.payload.obj;
                        l27 = ((vader_struct_vader_midir$InstrFieldGet_t*) t1)->f_span;
                        t1 = l6.payload.obj;
                        l28 = ((vader_struct_vader_midir$InstrFieldGet_t*) t1)->f_dst;
                        t1 = l23.payload.obj;
                        vader_array_t* _a3_slotarr = ((vader_array_t*) t1);
                        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l24)
                        l29 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l24];
                        vader_struct_vader_midir$InstrMove_t* _a4_obj = (vader_struct_vader_midir$InstrMove_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrMove_t));
                        vader_obj_header_init(_a4_obj, 1353u);
                        _a4_obj->f_span = l27;
                        _a4_obj->f_dst = l28;
                        _a4_obj->f_src = l29;
                        l30 = (void*) _a4_obj;
                        vader_array_push_ref((vader_array_t*) l2, l30);
                        l5 = (l5 + INT64_C(1));
                        continue;
                    }
                }
            }
        }
        l31 = l6;
        vader_array_push_ref((vader_array_t*) l2, l31.payload.obj);
        l5 = (l5 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir_value__return$forward_struct_fields_in_fn(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l12 = NULL;
    void* l16 = NULL;
    int64_t l7, l8, l11;
    int32_t l9, l10, l13;
    vader_box_t l14 = vader_box_null(), l15 = vader_box_null();
    vader_string_t l17 = 0;
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l14, &l15 };
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l12, &l16, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l17 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_midir$predecessors_of(l0);
    l6 = vader_midir$reverse_postorder(l0);
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 7u, 338u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 346u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__i32__std_collections_MutableMap_Any__Any____t* _a3_obj = (vader_struct_std_collections$MutableMap__i32__std_collections_MutableMap_Any__Any____t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__std_collections_MutableMap_Any__Any____t));
    vader_obj_header_init(_a3_obj, 466u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l2 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(22u, 0u, 7u, 338u);
    l3 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(28u, 0u, 0u, 346u);
    l4 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(22u, 0u, 7u, 338u);
    l5 = (void*) _a6_arr;
    vader_struct_std_collections$MutableMap__i32__Any___t* _a7_obj = (vader_struct_std_collections$MutableMap__i32__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__Any___t));
    vader_obj_header_init(_a7_obj, 460u);
    _a7_obj->f_ekeys = l3;
    _a7_obj->f_evals = l4;
    _a7_obj->f_index = l5;
    _a7_obj->f_mask = INT64_C(0);
    _a7_obj->f_grow_at = INT64_C(0);
    _a7_obj->f_size = INT64_C(0);
    _a7_obj->f_tombs = INT64_C(0);
    l3 = (void*) _a7_obj;
    l7 = ((vader_array_t*) l6)->length;
    l8 = INT64_C(0);
    while ((l8 < l7)) {
        vader_array_t* _a8_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        l9 = ((int32_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l8];
        l4 = vader_midir_value__return$join_of_predecessors(l1, l2, l9);
        l10 = l9;
        l5 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks;
        l11 = ((int64_t) (int32_t) l9);
        vader_array_t* _a9_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l11)
        t0 = vader_array_ref_load_obj(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l11);
        l12 = vader_midir_value__return$forward_block_with(((vader_struct_vader_midir$BasicBlock_t*) t0)->f_instructions, l4);
        std_collections$MutableMap$std_core$IndexSet$set_at__i32__Any(l3, l10, vader_ref_box(l12));
        l13 = l9;
        std_collections$MutableMap$std_core$IndexSet$set_at__i32__Any(l2, l13, vader_ref_box(l4));
        l8 = (l8 + INT64_C(1));
    }
    vader_array_t* _a10_arr = vader_array_new(201u, 0u, 13u, 1304u);
    l1 = (void*) _a10_arr;
    l2 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks;
    l7 = ((vader_array_t*) l2)->length;
    l8 = INT64_C(0);
    while ((l8 < l7)) {
        vader_array_t* _a11_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
        l4 = vader_array_ref_load_obj(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l8);
        l9 = ((vader_struct_vader_midir$BasicBlock_t*) l4)->f_id;
        l14 = std_collections$MutableMap$std_core$Index$at__i32__Any(l3, l9);
        if (l14.tag == 0u) {
            vader_array_push_ref((vader_array_t*) l1, l4);
        } else {
            l5 = l4;
            l10 = ((vader_struct_vader_midir$BasicBlock_t*) l5)->f_id;
            l6 = l14.payload.obj;
            l15 = ((vader_struct_vader_midir$BasicBlock_t*) l5)->f_terminator;
            l12 = ((vader_struct_vader_midir$BasicBlock_t*) l5)->f_span;
            vader_struct_vader_midir$BasicBlock_t* _a12_obj = (vader_struct_vader_midir$BasicBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$BasicBlock_t));
            vader_obj_header_init(_a12_obj, 1304u);
            _a12_obj->f_id = l10;
            _a12_obj->f_instructions = l6;
            _a12_obj->f_terminator = l15;
            _a12_obj->f_span = l12;
            l16 = (void*) _a12_obj;
            vader_array_push_ref((vader_array_t*) l1, l16);
        }
        l8 = (l8 + INT64_C(1));
    }
    l2 = l0;
    l17 = ((vader_struct_vader_midir$CFGFunction_t*) l2)->f_mangled;
    l3 = ((vader_struct_vader_midir$CFGFunction_t*) l2)->f_params;
    l14 = ((vader_struct_vader_midir$CFGFunction_t*) l2)->f_return_type;
    l4 = ((vader_struct_vader_midir$CFGFunction_t*) l2)->f_locals;
    l9 = ((vader_struct_vader_midir$CFGFunction_t*) l2)->f_entry;
    l5 = ((vader_struct_vader_midir$CFGFunction_t*) l2)->f_origin;
    l2 = ((vader_struct_vader_midir$CFGFunction_t*) l2)->f_scalarised_results;
    vader_struct_vader_midir$CFGFunction_t* _a13_obj = (vader_struct_vader_midir$CFGFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$CFGFunction_t));
    vader_obj_header_init(_a13_obj, 1306u);
    _a13_obj->f_mangled = l17;
    _a13_obj->f_params = l3;
    _a13_obj->f_return_type = l14;
    _a13_obj->f_locals = l4;
    _a13_obj->f_blocks = l1;
    _a13_obj->f_entry = l9;
    _a13_obj->f_origin = l5;
    _a13_obj->f_scalarised_results = l2;
    t0 = (void*) _a13_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir_value__return$forwarded_symbol(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    int32_t l3;
    uint8_t l4, l7;
    vader_string_t l5 = 0;
    vader_string_t l6 = 0;
    vader_box_t l8 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l8 };
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l5, &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = l0;
    l3 = ((vader_struct_vader_core_symbol$Symbol_t*) l2)->f_id;
    l4 = ((vader_struct_vader_core_symbol$Symbol_t*) l2)->f_kind;
    l5 = ((vader_struct_vader_core_symbol$Symbol_t*) l2)->f_module;
    l6 = ((vader_struct_vader_core_symbol$Symbol_t*) l2)->f_module_name;
    l7 = ((vader_struct_vader_core_symbol$Symbol_t*) l2)->f_visibility;
    l8 = ((vader_struct_vader_core_symbol$Symbol_t*) l2)->f_defined_at;
    vader_struct_vader_core_symbol$Symbol_t* _a0_obj = (vader_struct_vader_core_symbol$Symbol_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_symbol$Symbol_t));
    vader_obj_header_init(_a0_obj, 892u);
    _a0_obj->f_id = l3;
    _a0_obj->f_kind = l4;
    _a0_obj->f_name = l1;
    _a0_obj->f_module = l5;
    _a0_obj->f_module_name = l6;
    _a0_obj->f_visibility = l7;
    _a0_obj->f_defined_at = l8;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir_value__return$forwarding_body(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l9 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l14 = NULL;
    int64_t l3, l4;
    int32_t l7;
    vader_box_t l8 = vader_box_null(), l13 = vader_box_null();
    vader_string_t l10 = 0;
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l8, &l13 };
    void** gc_raw_roots[9] = { &l0, &l2, &l5, &l6, &l9, &l11, &l12, &l14, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l10 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(204u, 0u, 13u, 1307u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_array_t*) ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_params)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a1_arr;
    l3 = INT64_C(0);
    l4 = ((vader_array_t*) ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_params)->length;
    while ((l3 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_locals);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
        l5 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l3);
        vader_array_push_ref((vader_array_t*) l2, l5);
        l3 = (l3 + INT64_C(1));
    }
    vader_array_t* _a3_arr = vader_array_new(22u, 0u, 7u, 338u);
    l5 = (void*) _a3_arr;
    l3 = ((vader_array_t*) ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_params)->length;
    vader_array_t* _a4_arr = vader_array_repeat((vader_array_t*) l5, (int64_t) l3);
    l5 = (void*) _a4_arr;
    l6 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_params;
    l3 = ((vader_array_t*) l6)->length;
    l4 = INT64_C(0);
    vader_array_t* _pc48_hdr = (vader_array_t*) l5;
    size_t _pc48_len = _pc48_hdr->length;
    size_t _pc48_cap = (_pc48_hdr->offset == 0 && !vader_array_is_borrowed(_pc48_hdr) && _pc48_hdr->length >= _pc48_hdr->buf->length) ? _pc48_hdr->capacity : (size_t) 0;
    void* _pc48_slots = _pc48_hdr->buf->slots;
    for (;;) {
        if ((l4 < l3)) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            t0 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l4);
            l7 = ((vader_struct_vader_midir$CFGParam_t*) t0)->f_local;
            if (VADER_LIKELY(_pc48_len < _pc48_cap)) {
                ((int32_t*) _pc48_slots)[_pc48_len] = (int32_t) (l7);
                _pc48_len += 1;
            } else {
                _pc48_hdr->length = _pc48_len;
                if (_pc48_hdr->buf->length < _pc48_len) {
                    _pc48_hdr->buf->length = _pc48_len;
                }
                vader_array_push_i32((vader_array_t*) l5, l7);
                _pc48_hdr = (vader_array_t*) l5;
                _pc48_len = _pc48_hdr->length;
                _pc48_cap = (_pc48_hdr->offset == 0 && !vader_array_is_borrowed(_pc48_hdr) && _pc48_hdr->length >= _pc48_hdr->buf->length) ? _pc48_hdr->capacity : (size_t) 0;
                _pc48_slots = _pc48_hdr->buf->slots;
            }
            l4 = (l4 + INT64_C(1));
            continue;
        }
        _pc48_hdr->length = _pc48_len;
        if (_pc48_hdr->buf->length < _pc48_len) {
            _pc48_hdr->buf->length = _pc48_len;
        }
        break;
    }
    l8 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_return_type;
    l7 = vader_midir_value__return$add_local(l2, 2053u, l8);
    l6 = vader_midir$fn_span(l0);
    l9 = l0;
    l10 = ((vader_struct_vader_midir$CFGFunction_t*) l9)->f_mangled;
    l11 = ((vader_struct_vader_midir$CFGFunction_t*) l9)->f_params;
    l8 = ((vader_struct_vader_midir$CFGFunction_t*) l9)->f_return_type;
    vader_array_t* _a6_arr = vader_array_new(22u, 1u, 7u, 338u);
    ((int32_t*) _a6_arr->buf->slots)[_a6_arr->offset + 0u] = (int32_t) l7;
    l12 = (void*) _a6_arr;
    l13 = ((vader_struct_vader_core_mono$MonoEntry_t*) ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_origin)->f_symbol;
    if (l13.tag == 0u) {
        vader_array_t* _a7_slotarr = ((vader_array_t*) ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_params);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, INT32_C(0))
        t0 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) INT32_C(0));
        l14 = ((vader_struct_vader_midir$CFGParam_t*) t0)->f_symbol;
    } else {
        l14 = l13.payload.obj;
    }
    l14 = vader_midir_value__return$forwarded_symbol(l14, l1);
    l13 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_return_type;
    vader_struct_vader_midir$InstrCall_t* _a8_obj = (vader_struct_vader_midir$InstrCall_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrCall_t));
    vader_obj_header_init(_a8_obj, 1335u);
    _a8_obj->f_span = l6;
    _a8_obj->f_dsts = l12;
    _a8_obj->f_callee = l14;
    _a8_obj->f_args = l5;
    _a8_obj->f_type = l13;
    t0 = (void*) _a8_obj;
    vader_array_t* _a9_arr = vader_array_new(268u, 1u, 13u, 2082u);
    ((void**) _a9_arr->buf->slots)[_a9_arr->offset + 0u] = t0;
    l5 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(22u, 1u, 7u, 338u);
    ((int32_t*) _a10_arr->buf->slots)[_a10_arr->offset + 0u] = (int32_t) l7;
    l12 = (void*) _a10_arr;
    vader_struct_vader_midir$TermReturn_t* _a11_obj = (vader_struct_vader_midir$TermReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$TermReturn_t));
    vader_obj_header_init(_a11_obj, 1372u);
    _a11_obj->f_span = l6;
    _a11_obj->f_values = l12;
    l12 = (void*) _a11_obj;
    vader_struct_vader_midir$BasicBlock_t* _a12_obj = (vader_struct_vader_midir$BasicBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$BasicBlock_t));
    vader_obj_header_init(_a12_obj, 1304u);
    _a12_obj->f_id = INT32_C(0);
    _a12_obj->f_instructions = l5;
    _a12_obj->f_terminator = vader_ref_box(l12);
    _a12_obj->f_span = l6;
    t0 = (void*) _a12_obj;
    vader_array_t* _a13_arr = vader_array_new(201u, 1u, 13u, 1304u);
    ((void**) _a13_arr->buf->slots)[_a13_arr->offset + 0u] = t0;
    l5 = (void*) _a13_arr;
    l7 = ((vader_struct_vader_midir$CFGFunction_t*) l9)->f_entry;
    l6 = ((vader_struct_vader_midir$CFGFunction_t*) l9)->f_origin;
    l9 = ((vader_struct_vader_midir$CFGFunction_t*) l9)->f_scalarised_results;
    vader_struct_vader_midir$CFGFunction_t* _a14_obj = (vader_struct_vader_midir$CFGFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$CFGFunction_t));
    vader_obj_header_init(_a14_obj, 1306u);
    _a14_obj->f_mangled = l10;
    _a14_obj->f_params = l11;
    _a14_obj->f_return_type = l8;
    _a14_obj->f_locals = l2;
    _a14_obj->f_blocks = l5;
    _a14_obj->f_entry = l7;
    _a14_obj->f_origin = l6;
    _a14_obj->f_scalarised_results = l9;
    t0 = (void*) _a14_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_midir_value__return$has_null_variant(vader_box_t l0) {
    void* l1;
    int64_t l2, l3;
    vader_box_t l4;
    void* t0;
    vader_string_t t1;
    if (!(l0.tag == 918u)) {
        return false;
    }
    t0 = l0.payload.obj;
    l1 = ((vader_struct_vader_core_types$UnionType_t*) t0)->f_variants;
    l2 = ((vader_array_t*) l1)->length;
    l3 = INT64_C(0);
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        if (l4.tag == 907u) {
            t0 = l4.payload.obj;
            t1 = ((vader_struct_vader_core_types$PrimitiveType_t*) t0)->f_name;
            if (t1 == 2416u) {
                return true;
            }
        }
        l3 = (l3 + INT64_C(1));
    }
    return false;
}

static void* vader_midir_value__return$join_of_predecessors(void* l0, void* l1, int32_t l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    void* l21 = NULL;
    void* l23 = NULL;
    void* l25 = NULL;
    int64_t l6, l8, l19, l20, l26, l27;
    bool l7;
    int32_t l9, l13, l22, l28;
    vader_box_t l10 = vader_box_null(), l24 = vader_box_null();
    int64_t t0;
    void* t1 = NULL;
    bool t2;
    vader_box_t* gc_roots[2] = { &l10, &l24 };
    void** gc_raw_roots[16] = {
        &l0, &l1, &l3, &l4, &l5, &l11, &l12, &l14, &l15, &l16, &l17, &l18, &l21, &l23, &l25, &t1,
    };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 16u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 7u, 338u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 346u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
    l5 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__i32__Any___t* _a3_obj = (vader_struct_std_collections$MutableMap__i32__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__Any___t));
    vader_obj_header_init(_a3_obj, 460u);
    _a3_obj->f_ekeys = l3;
    _a3_obj->f_evals = l4;
    _a3_obj->f_index = l5;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l3 = (void*) _a3_obj;
    l6 = ((int64_t) (int32_t) l2);
    if ((INT64_C(0) <= l6)) {
        l8 = ((vader_array_t*) l0)->length;
        l7 = (l6 < l8);
    } else {
        l7 = false;
    }
    if (!(l7)) {
        { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = ((int64_t) (int32_t) l2);
    vader_array_t* _a4_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l6)
    l4 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l6);
    t0 = ((vader_array_t*) l4)->length;
    if (t0 == INT64_C(0)) {
        { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a5_slotarr = ((vader_array_t*) l4);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, INT32_C(0))
    l9 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) INT32_C(0)];
    l10 = std_collections$MutableMap$std_core$Index$at__i32__Any(l1, l9);
    if (l10.tag == 0u) {
        { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = l10.payload.obj;
    l11 = ((vader_struct_std_collections$MutableMap__i32__i32___t*) l5)->f_ekeys;
    l12 = ((vader_struct_std_collections$MutableMap__i32__i32___t*) l5)->f_evals;
    l6 = INT64_C(0);
    l8 = ((vader_struct_std_collections$MutableMap__i32__i32___t*) l5)->f_size;
    while ((l6 < l8)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l11);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l6)
        l9 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l6];
        vader_array_t* _a7_slotarr = ((vader_array_t*) l12);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l6)
        l5 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l6);
        l13 = l9;
        l14 = l5;
        std_collections$MutableMap$std_core$IndexSet$set_at__i32__Any(l3, l13, vader_ref_box(l14));
        l6 = (l6 + INT64_C(1));
    }
    l6 = INT64_C(1);
    l8 = ((vader_array_t*) l4)->length;
    while ((l6 < l8)) {
        vader_array_t* _a8_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        l9 = ((int32_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l6];
        l10 = std_collections$MutableMap$std_core$Index$at__i32__Any(l1, l9);
        if (l10.tag == 0u) {
            vader_array_t* _a9_arr = vader_array_new(22u, 0u, 7u, 338u);
            l11 = (void*) _a9_arr;
            vader_array_t* _a10_arr = vader_array_new(28u, 0u, 0u, 346u);
            l12 = (void*) _a10_arr;
            vader_array_t* _a11_arr = vader_array_new(22u, 0u, 7u, 338u);
            l14 = (void*) _a11_arr;
            vader_struct_std_collections$MutableMap__i32__Any___t* _a12_obj = (vader_struct_std_collections$MutableMap__i32__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__Any___t));
            vader_obj_header_init(_a12_obj, 460u);
            _a12_obj->f_ekeys = l11;
            _a12_obj->f_evals = l12;
            _a12_obj->f_index = l14;
            _a12_obj->f_mask = INT64_C(0);
            _a12_obj->f_grow_at = INT64_C(0);
            _a12_obj->f_size = INT64_C(0);
            _a12_obj->f_tombs = INT64_C(0);
            t1 = (void*) _a12_obj;
            { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l5 = l10.payload.obj;
        vader_array_t* _a13_arr = vader_array_new(22u, 0u, 7u, 338u);
        l15 = (void*) _a13_arr;
        l16 = l3;
        l17 = ((vader_struct_std_collections$MutableMap__i32__i32___t*) l16)->f_ekeys;
        l18 = ((vader_struct_std_collections$MutableMap__i32__i32___t*) l16)->f_evals;
        l19 = INT64_C(0);
        l20 = ((vader_struct_std_collections$MutableMap__i32__i32___t*) l16)->f_size;
        while ((l19 < l20)) {
            vader_array_t* _a14_slotarr = ((vader_array_t*) l17);
            VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l19)
            l13 = ((int32_t*) _a14_slotarr->buf->slots)[_a14_slotarr->offset + (size_t) l19];
            vader_array_t* _a15_slotarr = ((vader_array_t*) l18);
            VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l19)
            l21 = vader_array_ref_load_obj(_a15_slotarr->buf, _a15_slotarr->offset + (size_t) l19);
            l22 = l13;
            l23 = l21;
            l24 = std_collections$MutableMap$std_core$Index$at__i32__Any(l5, l22);
            if (l24.tag == 0u) {
                vader_array_push_i32((vader_array_t*) l15, l22);
            } else {
                t1 = l24.payload.obj;
                t2 = std_core$content_equals__i32(t1, l23);
                if (!(t2)) {
                    vader_array_push_i32((vader_array_t*) l15, l22);
                }
            }
            l19 = (l19 + INT64_C(1));
        }
        l25 = l15;
        l26 = ((vader_array_t*) l25)->length;
        l27 = INT64_C(0);
        while ((l27 < l26)) {
            vader_array_t* _a16_slotarr = ((vader_array_t*) l25);
            VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
            l28 = ((int32_t*) _a16_slotarr->buf->slots)[_a16_slotarr->offset + (size_t) l27];
            std_collections$remove__i32__i32__(l3, l28);
            l27 = (l27 + INT64_C(1));
        }
        l6 = (l6 + INT64_C(1));
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_midir_value__return$mark_forwarding(vader_string_t l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    vader_box_t l4 = vader_box_null();
    vader_string_t l5 = 0;
    bool t0;
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[5] = { &l1, &l2, &l3, &l6, &l7 };
    vader_string_t* gc_atom_roots[2] = { &l0, &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = std_collections$MutableMap$std_core$Index$at__string__Any(l1, l0);
    if (l4.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = l4.payload.obj;
    if (!(((vader_struct_vader_midir_value__return$ReturnShape_t*) l3)->f_forward_to.tag == 0u)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l5 = vader_midir_value__return$scalarised_copy_mangle(l0);
    l6 = l3;
    l7 = ((vader_struct_vader_midir_value__return$ReturnShape_t*) l6)->f_elements;
    l4 = ((vader_struct_vader_midir_value__return$ReturnShape_t*) l6)->f_rebuilt;
    vader_struct_vader_midir_value__return$ReturnShape_t* _a0_obj = (vader_struct_vader_midir_value__return$ReturnShape_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_value__return$ReturnShape_t));
    vader_obj_header_init(_a0_obj, 1389u);
    _a0_obj->f_elements = l7;
    _a0_obj->f_rebuilt = l4;
    _a0_obj->f_forward_to = vader_box_string(335u, l5);
    l6 = (void*) _a0_obj;
    std_collections$MutableMap$std_core$IndexSet$set_at__string__Any(l1, l0, vader_ref_box(l6));
    std_collections$MutableMap$std_core$IndexSet$set_at__string__Any(l1, l5, vader_ref_box(l3));
    t0 = std_collections$MutableSet$std_core$Contains$contains__string(l2, l0);
    if (t0) {
        std_collections$add__string(l2, l5);
        std_collections$add__string(l2, l0);
        { vader_gc_top = gc_frame.prev; return; }
    }
    std_collections$add__string(l2, l0);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_value__return$note_call(void* l0, void* l1, void* l2, void* l3, void* l4, vader_string_t l5) {
    vader_string_t l6 = 0;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l4 };
    vader_string_t* gc_atom_roots[2] = { &l5, &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_midir_value__return$callee_shape(l0, l1, l2);
    if (!(t0.tag == 0u)) {
        std_collections$add__string(l3, l5);
        l6 = vader_midir_value__return$callee_mangle(l0, l1, l2);
        std_collections$add__string(l4, l6);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_value__return$note_symbol(void* l0, void* l1, void* l2) {
    vader_string_t l3 = 0;
    int32_t l4;
    vader_box_t l5 = vader_box_null();
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_name;
    std_collections$add__string(l2, l3);
    l4 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_id;
    l5 = std_collections$MutableMap$std_core$Index$at__i32__string(l1, l4);
    if (l5.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = l5.payload.s;
    std_collections$add__string(l2, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_midir_value__return$nullable_results(void* l0) {
    void* l1 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = (void*) &vader_data_19;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
    vader_array_t* _a1_arr = vader_array_new(252u, 1u, 13u, 1776u);
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = t0;
    l1 = (void*) _a1_arr;
    vader_array_push_all((vader_array_t*) l1, (vader_array_t*) l0);
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_value__return$nullable_return_of(void* l0) {
    void* l1 = NULL;
    vader_box_t l2 = vader_box_null();
    bool t0;
    void* t1 = NULL;
    int64_t t2;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_midir_value__return$has_null_variant(((vader_struct_vader_midir$CFGFunction_t*) l0)->f_return_type);
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = vader_midir_value__return$returns_fresh_composite(l0);
    if (l2.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l1 = l2.payload.obj;
    t1 = vader_midir_value__return$nullable_results(((vader_struct_vader_midir_value__return$NullableReturn_t*) l1)->f_fields);
    t2 = vader_core_types$value_abi_sum_leaves(t1);
    if (!((t2 < INT64_C(0)))) {
        { vader_box_t __vret = vader_ref_box(l1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static void vader_midir_value__return$place(void* l0, void* l1, int32_t l2, int32_t l3, void* l4) {
    bool t0;
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_midir$BlockId$std_core$Equals$equals(l2, l3);
    if (!(t0)) {
        vader_array_push_ref((vader_array_t*) l1, l4);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_push_ref((vader_array_t*) l0, l4);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_value__return$plan_forwarding(void* l0, void* l1, void* l2, void* l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l10 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l17 = NULL;
    void* l21 = NULL;
    int64_t l8, l9, l11, l12, l15, l16, l18, l19;
    vader_box_t l20 = vader_box_null(), l23 = vader_box_null();
    vader_string_t l22 = 0;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_string_t t2 = 0;
    bool t3;
    vader_box_t* gc_roots[3] = { &l20, &l23, &t1 };
    void** gc_raw_roots[14] = {
        &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l10, &l13, &l14, &l17, &l21, &t0,
    };
    vader_string_t* gc_atom_roots[2] = { &l22, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 14u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 335u);
    l4 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(19u, 0u, 12u, 333u);
    l5 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
    l6 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__string__bool_t* _a3_obj = (vader_struct_std_collections$MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__bool_t));
    vader_obj_header_init(_a3_obj, 539u);
    _a3_obj->f_ekeys = l4;
    _a3_obj->f_evals = l5;
    _a3_obj->f_index = l6;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections$MutableSet__string_t* _a4_obj = (vader_struct_std_collections$MutableSet__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__string_t));
    vader_obj_header_init(_a4_obj, 607u);
    _a4_obj->f_inner = t0;
    l4 = (void*) _a4_obj;
    vader_array_t* _a5_arr = vader_array_new(21u, 0u, 0u, 335u);
    l5 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(19u, 0u, 12u, 333u);
    l6 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(22u, 0u, 7u, 338u);
    l7 = (void*) _a7_arr;
    vader_struct_std_collections$MutableMap__string__bool_t* _a8_obj = (vader_struct_std_collections$MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__bool_t));
    vader_obj_header_init(_a8_obj, 539u);
    _a8_obj->f_ekeys = l5;
    _a8_obj->f_evals = l6;
    _a8_obj->f_index = l7;
    _a8_obj->f_mask = INT64_C(0);
    _a8_obj->f_grow_at = INT64_C(0);
    _a8_obj->f_size = INT64_C(0);
    _a8_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a8_obj;
    vader_struct_std_collections$MutableSet__string_t* _a9_obj = (vader_struct_std_collections$MutableSet__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__string_t));
    vader_obj_header_init(_a9_obj, 607u);
    _a9_obj->f_inner = t0;
    l5 = (void*) _a9_obj;
    l6 = ((vader_struct_vader_midir$CFGProject_t*) l0)->f_vtable_entries;
    l8 = ((vader_array_t*) l6)->length;
    l9 = INT64_C(0);
    while ((l9 < l8)) {
        vader_array_t* _a10_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        t0 = vader_array_ref_load_obj(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l9);
        vader_midir_value__return$note_symbol(((vader_struct_vader_lower_ir$LoweredVtableEntry_t*) t0)->f_fn_symbol, l2, l4);
        l9 = (l9 + INT64_C(1));
    }
    l6 = ((vader_struct_vader_midir$CFGProject_t*) l0)->f_modules;
    l7 = ((vader_struct_std_collections$MutableMap__string__vader_midir_CFGModule_t*) l6)->f_ekeys;
    l10 = ((vader_struct_std_collections$MutableMap__string__vader_midir_CFGModule_t*) l6)->f_evals;
    l8 = INT64_C(0);
    l9 = ((vader_struct_std_collections$MutableMap__string__vader_midir_CFGModule_t*) l6)->f_size;
    while ((l8 < l9)) {
        vader_array_t* _a11_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l8)
        t1 = vader_array_box_slots(_a11_slotarr->buf)[_a11_slotarr->offset + (size_t) l8];
        t2 = t1.payload.s;
        vader_array_t* _a12_slotarr = ((vader_array_t*) l10);
        VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l8)
        t0 = vader_array_ref_load_obj(_a12_slotarr->buf, _a12_slotarr->offset + (size_t) l8);
        l6 = ((vader_struct_vader_midir$CFGModule_t*) t0)->f_functions;
        l11 = ((vader_array_t*) l6)->length;
        l12 = INT64_C(0);
        while ((l12 < l11)) {
            vader_array_t* _a13_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
            l13 = vader_array_ref_load_obj(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l12);
            l14 = ((vader_struct_vader_midir$CFGFunction_t*) l13)->f_blocks;
            l15 = ((vader_array_t*) l14)->length;
            l16 = INT64_C(0);
            while ((l16 < l15)) {
                vader_array_t* _a14_slotarr = ((vader_array_t*) l14);
                VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
                t0 = vader_array_ref_load_obj(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l16);
                l17 = ((vader_struct_vader_midir$BasicBlock_t*) t0)->f_instructions;
                l18 = ((vader_array_t*) l17)->length;
                l19 = INT64_C(0);
                while ((l19 < l18)) {
                    vader_array_t* _a15_slotarr = ((vader_array_t*) l17);
                    VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
                    l20 = vader_array_ref_load_box(_a15_slotarr->buf, _a15_slotarr->offset + (size_t) l19);
                    if (l20.tag == 1335u) {
                        t0 = l20.payload.obj;
                        l21 = ((vader_struct_vader_midir$InstrCall_t*) t0)->f_callee;
                        l22 = ((vader_struct_vader_midir$CFGFunction_t*) l13)->f_mangled;
                        vader_midir_value__return$note_call(l21, l1, l2, l3, l5, l22);
                        l19 = (l19 + INT64_C(1));
                        continue;
                    }
                    l23 = vader_midir$taken_function(l20);
                    if (l23.tag == 0u) {
                        l19 = (l19 + INT64_C(1));
                        continue;
                    }
                    t0 = l23.payload.obj;
                    vader_midir_value__return$note_symbol(t0, l2, l4);
                    l19 = (l19 + INT64_C(1));
                }
                l16 = (l16 + INT64_C(1));
            }
            l12 = (l12 + INT64_C(1));
        }
        l8 = (l8 + INT64_C(1));
    }
    l6 = ((vader_struct_std_collections$MutableMap__string__bool_t*) ((vader_struct_std_collections$MutableSet__string_t*) l4)->f_inner)->f_ekeys;
    l8 = INT64_C(0);
    l9 = ((vader_struct_std_collections$MutableMap__string__bool_t*) ((vader_struct_std_collections$MutableSet__string_t*) l4)->f_inner)->f_size;
    while ((l8 < l9)) {
        vader_array_t* _a16_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l8)
        t1 = vader_array_box_slots(_a16_slotarr->buf)[_a16_slotarr->offset + (size_t) l8];
        l22 = t1.payload.s;
        t3 = std_collections$MutableSet$std_core$Contains$contains__string(l5, l22);
        if (t3) {
            vader_midir_value__return$mark_forwarding(l22, l1, l3);
        } else {
            std_collections$remove__string__vader_midir_value__return_ReturnShape(l1, l22);
        }
        l8 = (l8 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_midir_value__return$present_arm(void* l0, int32_t l1, void* l2, vader_box_t l3, int32_t l4, int32_t l5, void* l6) {
    int64_t l7;
    void* l8 = NULL;
    void* l9 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[6] = { &l0, &l2, &l6, &l8, &l9, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l7 = ((vader_array_t*) l2)->length;
    vader_array_t* _a0_arr = vader_array_slice((vader_array_t*) l2, (int64_t) INT64_C(1), (int64_t) l7);
    l8 = (void*) _a0_arr;
    vader_struct_vader_midir$InstrStructNew_t* _a1_obj = (vader_struct_vader_midir$InstrStructNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrStructNew_t));
    vader_obj_header_init(_a1_obj, 1354u);
    _a1_obj->f_span = ((vader_struct_vader_midir$InstrCall_t*) l0)->f_span;
    _a1_obj->f_dst = l1;
    _a1_obj->f_type = l3;
    _a1_obj->f_fields = l8;
    _a1_obj->f_stack = false;
    t0 = (void*) _a1_obj;
    vader_array_t* _a2_arr = vader_array_new(268u, 1u, 13u, 2082u);
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = t0;
    l8 = (void*) _a2_arr;
    vader_struct_vader_midir$TermBranch_t* _a3_obj = (vader_struct_vader_midir$TermBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$TermBranch_t));
    vader_obj_header_init(_a3_obj, 1370u);
    _a3_obj->f_span = ((vader_struct_vader_midir$InstrCall_t*) l0)->f_span;
    _a3_obj->f_target = l5;
    l9 = (void*) _a3_obj;
    vader_struct_vader_midir$BasicBlock_t* _a4_obj = (vader_struct_vader_midir$BasicBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$BasicBlock_t));
    vader_obj_header_init(_a4_obj, 1304u);
    _a4_obj->f_id = l4;
    _a4_obj->f_instructions = l8;
    _a4_obj->f_terminator = vader_ref_box(l9);
    _a4_obj->f_span = l6;
    t0 = (void*) _a4_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_value__return$return_source(void* l0, int32_t l1) {
    int64_t l2, l3, l4;
    vader_box_t l5 = vader_box_null(), l6 = vader_box_null(), l8 = vader_box_null();
    void* l7 = NULL;
    int64_t t0;
    int32_t t1;
    bool t2;
    void* t3 = NULL;
    vader_box_t* gc_roots[3] = { &l5, &l6, &l8 };
    void** gc_raw_roots[3] = { &l0, &l7, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_array_t*) l0)->length;
    l3 = INT64_C(0);
    while ((l3 < l2)) {
        t0 = vader_chk_sub(i64, l2, INT64_C(1));
        l4 = vader_chk_sub(i64, t0, l3);
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        l6 = vader_midir$dst_of(l5);
        if (l6.tag == 0u) {
            l3 = (l3 + INT64_C(1));
            continue;
        }
        t1 = ((int32_t) l6.payload.i);
        t2 = vader_midir$LocalId$std_core$Equals$equals(t1, l1);
        if (t2) {
            if (l5.tag == 1354u) {
                t3 = l5.payload.obj;
                l7 = ((vader_struct_vader_midir$InstrStructNew_t*) t3)->f_fields;
                t3 = l5.payload.obj;
                l8 = ((vader_struct_vader_midir$InstrStructNew_t*) t3)->f_type;
                vader_struct_vader_midir_value__return$ReturnsStruct_t* _a1_obj = (vader_struct_vader_midir_value__return$ReturnsStruct_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_value__return$ReturnsStruct_t));
                vader_obj_header_init(_a1_obj, 1391u);
                _a1_obj->f_fields = l7;
                _a1_obj->f_type = l8;
                t3 = (void*) _a1_obj;
                { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l5.tag == 1341u) {
                t3 = l5.payload.obj;
                if (((vader_struct_vader_midir$InstrConst_t*) t3)->f_value.tag == 1322u) {
                    vader_struct_vader_midir_value__return$ReturnsNull_t* _a2_obj = (vader_struct_vader_midir_value__return$ReturnsNull_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_value__return$ReturnsNull_t));
                    vader_obj_header_init(_a2_obj, 1390u);
                    t3 = (void*) _a2_obj;
                    { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
                }
                { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
            }
            { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
        }
        l3 = (l3 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_midir_value__return$returns_fresh_composite(void* l0) {
    vader_box_t l1 = vader_box_null(), l6 = vader_box_null(), l8 = vader_box_null(), l9 = vader_box_null(), l10 = vader_box_null(), l11 = vader_box_null(), l12 = vader_box_null(), l23 = vader_box_null(), l24 = vader_box_null();
    void* l2 = NULL;
    void* l5 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l21 = NULL;
    int64_t l3, l4, l15, l16, l18, l20, l22;
    int32_t l7, l17;
    bool l19;
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[9] = { &l1, &l6, &l8, &l9, &l10, &l11, &l12, &l23, &l24 };
    void** gc_raw_roots[7] = { &l0, &l2, &l5, &l13, &l14, &l21, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 9u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_box_obj(0u, NULL);
    l2 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        l6 = ((vader_struct_vader_midir$BasicBlock_t*) l5)->f_terminator;
        if (l6.tag == 1372u) {
            t0 = l6.payload.obj;
            l8 = vader_midir$term_return_single(t0);
            if (l8.tag == 0u) {
                { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
            }
            l7 = ((int32_t) l8.payload.i);
            l10 = vader_midir_value__return$return_source(((vader_struct_vader_midir$BasicBlock_t*) l5)->f_instructions, l7);
            if (l10.tag == 0u) {
                { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
            }
            l9 = l10;
            if (l9.tag == 1390u) {
                l4 = (l4 + INT64_C(1));
                continue;
            }
            if (l1.tag == 0u) {
                vader_array_t* _a1_arr = vader_array_new(252u, 0u, 13u, 1776u);
                l13 = (void*) _a1_arr;
                t0 = l9.payload.obj;
                l14 = ((vader_struct_vader_midir_value__return$ReturnsStruct_t*) t0)->f_fields;
                l15 = ((vader_array_t*) l14)->length;
                l16 = INT64_C(0);
                while ((l16 < l15)) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) l14);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    l17 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l16];
                    l18 = ((int64_t) (int32_t) l17);
                    if ((INT64_C(0) <= l18)) {
                        l20 = ((vader_array_t*) ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_locals)->length;
                        l19 = (l18 < l20);
                    } else {
                        l19 = false;
                    }
                    if (!(l19)) {
                        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
                    }
                    l21 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_locals;
                    l22 = ((int64_t) (int32_t) l17);
                    vader_array_t* _a3_slotarr = ((vader_array_t*) l21);
                    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l22)
                    t0 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l22);
                    l23 = ((vader_struct_vader_midir$CFGLocal_t*) t0)->f_type;
                    vader_array_push_ref((vader_array_t*) l13, l23.payload.obj);
                    l16 = (l16 + INT64_C(1));
                }
                t0 = l9.payload.obj;
                l24 = ((vader_struct_vader_midir_value__return$ReturnsStruct_t*) t0)->f_type;
                vader_struct_vader_midir_value__return$NullableReturn_t* _a4_obj = (vader_struct_vader_midir_value__return$NullableReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_value__return$NullableReturn_t));
                vader_obj_header_init(_a4_obj, 1388u);
                _a4_obj->f_fields = l13;
                _a4_obj->f_struct_type = l24;
                t0 = (void*) _a4_obj;
                l1 = vader_ref_box(t0);
                l4 = (l4 + INT64_C(1));
                continue;
            }
            t0 = l1.payload.obj;
            l11 = ((vader_struct_vader_midir_value__return$NullableReturn_t*) t0)->f_struct_type;
            t0 = l9.payload.obj;
            l12 = ((vader_struct_vader_midir_value__return$ReturnsStruct_t*) t0)->f_type;
            t1 = vader_midir_value__return$same_carrier(l11, l12);
            if (!(t1)) {
                { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
            }
            l4 = (l4 + INT64_C(1));
            continue;
        }
        l4 = (l4 + INT64_C(1));
    }
    { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir_value__return$rewrite_call_sites(void* l0, void* l1, void* l2, void* l3) {
    vader_string_t l4 = 0;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l9 = NULL;
    void* l13 = NULL;
    int32_t l8;
    int64_t l10, l11;
    vader_box_t l12 = vader_box_null();
    bool t0;
    int64_t t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &l12 };
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l5, &l6, &l7, &l9, &l13, &t2 };
    vader_string_t* gc_atom_roots[1] = { &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_mangled;
    t0 = std_collections$MutableSet$std_core$Contains$contains__string(l3, l4);
    if (!(t0)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(204u, 0u, 13u, 1307u);
    l5 = (void*) _a0_arr;
    l6 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_locals;
    vader_array_push_all((vader_array_t*) l5, (vader_array_t*) l6);
    vader_array_t* _a1_arr = vader_array_new(201u, 0u, 13u, 1304u);
    l6 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(201u, 0u, 13u, 1304u);
    l7 = (void*) _a2_arr;
    t1 = ((vader_array_t*) ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks)->length;
    l8 = ((int32_t) (int64_t) t1);
    l9 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks;
    l10 = ((vader_array_t*) l9)->length;
    l11 = INT64_C(0);
    while ((l11 < l10)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        t2 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l11);
        l8 = vader_midir_value__return$emit_rewritten_block(t2, l1, l2, l5, l6, l7, l8);
        l11 = (l11 + INT64_C(1));
    }
    vader_array_push_all((vader_array_t*) l6, (vader_array_t*) l7);
    l7 = l0;
    l4 = ((vader_struct_vader_midir$CFGFunction_t*) l7)->f_mangled;
    l9 = ((vader_struct_vader_midir$CFGFunction_t*) l7)->f_params;
    l12 = ((vader_struct_vader_midir$CFGFunction_t*) l7)->f_return_type;
    l8 = ((vader_struct_vader_midir$CFGFunction_t*) l7)->f_entry;
    l13 = ((vader_struct_vader_midir$CFGFunction_t*) l7)->f_origin;
    l7 = ((vader_struct_vader_midir$CFGFunction_t*) l7)->f_scalarised_results;
    vader_struct_vader_midir$CFGFunction_t* _a4_obj = (vader_struct_vader_midir$CFGFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$CFGFunction_t));
    vader_obj_header_init(_a4_obj, 1306u);
    _a4_obj->f_mangled = l4;
    _a4_obj->f_params = l9;
    _a4_obj->f_return_type = l12;
    _a4_obj->f_locals = l5;
    _a4_obj->f_blocks = l6;
    _a4_obj->f_entry = l8;
    _a4_obj->f_origin = l13;
    _a4_obj->f_scalarised_results = l7;
    t2 = (void*) _a4_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir_value__return$rewrite_callee(void* l0, void* l1, bool l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    int64_t l5, l7;
    vader_string_t l10 = 0;
    vader_box_t l11 = vader_box_null();
    int32_t l12;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l11 };
    void** gc_raw_roots[8] = { &l0, &l1, &l3, &l4, &l6, &l8, &l9, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l10 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(204u, 0u, 13u, 1307u);
    l3 = (void*) _a0_arr;
    l4 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_locals;
    vader_array_push_all((vader_array_t*) l3, (vader_array_t*) l4);
    vader_array_t* _a1_arr = vader_array_new(201u, 0u, 13u, 1304u);
    l4 = (void*) _a1_arr;
    l5 = ((vader_array_t*) ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks)->length;
    vader_array_t* _a2_arr = vader_array_repeat((vader_array_t*) l4, (int64_t) l5);
    l4 = (void*) _a2_arr;
    l6 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks;
    l5 = ((vader_array_t*) l6)->length;
    l7 = INT64_C(0);
    while ((l7 < l5)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        l8 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l7);
        if (l2) {
            l9 = vader_midir_value__return$rewrite_nullable_return(l8, l1, l3);
        } else {
            l9 = vader_midir_value__return$rewrite_return_block(l8, l1, l3);
        }
        vader_array_push_ref((vader_array_t*) l4, l9);
        l7 = (l7 + INT64_C(1));
    }
    l6 = l0;
    l10 = ((vader_struct_vader_midir$CFGFunction_t*) l6)->f_mangled;
    l8 = ((vader_struct_vader_midir$CFGFunction_t*) l6)->f_params;
    l11 = ((vader_struct_vader_midir$CFGFunction_t*) l6)->f_return_type;
    l12 = ((vader_struct_vader_midir$CFGFunction_t*) l6)->f_entry;
    l6 = ((vader_struct_vader_midir$CFGFunction_t*) l6)->f_origin;
    if (l2) {
        l9 = vader_midir_value__return$nullable_results(l1);
        vader_struct_vader_midir$CFGFunction_t* _a4_obj = (vader_struct_vader_midir$CFGFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$CFGFunction_t));
        vader_obj_header_init(_a4_obj, 1306u);
        _a4_obj->f_mangled = l10;
        _a4_obj->f_params = l8;
        _a4_obj->f_return_type = l11;
        _a4_obj->f_locals = l3;
        _a4_obj->f_blocks = l4;
        _a4_obj->f_entry = l12;
        _a4_obj->f_origin = l6;
        _a4_obj->f_scalarised_results = l9;
        t0 = (void*) _a4_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l9 = l1;
    vader_struct_vader_midir$CFGFunction_t* _a5_obj = (vader_struct_vader_midir$CFGFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$CFGFunction_t));
    vader_obj_header_init(_a5_obj, 1306u);
    _a5_obj->f_mangled = l10;
    _a5_obj->f_params = l8;
    _a5_obj->f_return_type = l11;
    _a5_obj->f_locals = l3;
    _a5_obj->f_blocks = l4;
    _a5_obj->f_entry = l12;
    _a5_obj->f_origin = l6;
    _a5_obj->f_scalarised_results = l9;
    t0 = (void*) _a5_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir_value__return$rewrite_nullable_return(void* l0, void* l1, void* l2) {
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null();
    void* l5 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l11 = NULL;
    int32_t l6;
    int64_t l9, l10;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[2] = { &l3, &l4 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l5, &l7, &l8, &l11, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_midir$BasicBlock_t*) l0)->f_terminator;
    if (!(l3.tag == 1372u)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l3.payload.obj;
    t1 = ((vader_array_t*) ((vader_struct_vader_midir$TermReturn_t*) t0)->f_values)->length;
    if (t1 != INT64_C(1)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = ((vader_struct_vader_midir$BasicBlock_t*) l0)->f_instructions;
    t0 = l3.payload.obj;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_midir$TermReturn_t*) t0)->f_values);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
    l6 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) INT32_C(0)];
    l4 = vader_midir_value__return$return_source(l5, l6);
    if (l4.tag == 0u) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a1_arr = vader_array_new(268u, 0u, 13u, 2082u);
    l5 = (void*) _a1_arr;
    l7 = ((vader_struct_vader_midir$BasicBlock_t*) l0)->f_instructions;
    vader_array_push_all((vader_array_t*) l5, (vader_array_t*) l7);
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
    l7 = (void*) _a2_arr;
    if (l4.tag == 1391u) {
        t0 = l3.payload.obj;
        l8 = ((vader_struct_vader_midir$TermReturn_t*) t0)->f_span;
        l6 = vader_midir_value__return$const_i32(l5, l2, INT64_C(1), l8);
        vader_array_push_i32((vader_array_t*) l7, l6);
        t0 = l4.payload.obj;
        l8 = ((vader_struct_vader_midir_value__return$ReturnsStruct_t*) t0)->f_fields;
        vader_array_push_all((vader_array_t*) l7, (vader_array_t*) l8);
    } else {
        t0 = l3.payload.obj;
        l8 = ((vader_struct_vader_midir$TermReturn_t*) t0)->f_span;
        l6 = vader_midir_value__return$const_i32(l5, l2, INT64_C(0), l8);
        vader_array_push_i32((vader_array_t*) l7, l6);
        l8 = l1;
        l9 = ((vader_array_t*) l8)->length;
        l10 = INT64_C(0);
        while ((l10 < l9)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            l4 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l10);
            t0 = l3.payload.obj;
            l11 = ((vader_struct_vader_midir$TermReturn_t*) t0)->f_span;
            l6 = vader_midir_value__return$zero_of(l5, l2, l4, l11);
            vader_array_push_i32((vader_array_t*) l7, l6);
            l10 = (l10 + INT64_C(1));
        }
    }
    l8 = l0;
    l6 = ((vader_struct_vader_midir$BasicBlock_t*) l8)->f_id;
    t0 = l3.payload.obj;
    vader_struct_vader_midir$TermReturn_t* _a4_obj = (vader_struct_vader_midir$TermReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$TermReturn_t));
    vader_obj_header_init(_a4_obj, 1372u);
    _a4_obj->f_span = ((vader_struct_vader_midir$TermReturn_t*) t0)->f_span;
    _a4_obj->f_values = l7;
    l7 = (void*) _a4_obj;
    l8 = ((vader_struct_vader_midir$BasicBlock_t*) l8)->f_span;
    vader_struct_vader_midir$BasicBlock_t* _a5_obj = (vader_struct_vader_midir$BasicBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$BasicBlock_t));
    vader_obj_header_init(_a5_obj, 1304u);
    _a5_obj->f_id = l6;
    _a5_obj->f_instructions = l5;
    _a5_obj->f_terminator = vader_ref_box(l7);
    _a5_obj->f_span = l8;
    t0 = (void*) _a5_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir_value__return$rewrite_return_block(void* l0, void* l1, void* l2) {
    vader_box_t l3 = vader_box_null(), l5 = vader_box_null(), l13 = vader_box_null();
    int32_t l4, l9;
    int64_t l6, l7, l14;
    void* l8 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l16 = NULL;
    vader_string_t l15 = 0;
    void* t0 = NULL;
    vader_box_t* gc_roots[3] = { &l3, &l5, &l13 };
    void** gc_raw_roots[9] = { &l0, &l1, &l2, &l8, &l10, &l11, &l12, &l16, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l15 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_midir$BasicBlock_t*) l0)->f_terminator;
    if (!(l3.tag == 1372u)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l3.payload.obj;
    l5 = vader_midir$term_return_single(t0);
    if (l5.tag == 0u) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = ((int32_t) l5.payload.i);
    l5 = vader_midir_value__return$return_source(((vader_struct_vader_midir$BasicBlock_t*) l0)->f_instructions, l4);
    if (l5.tag == 1391u) {
        t0 = l5.payload.obj;
        l6 = ((vader_array_t*) ((vader_struct_vader_midir_value__return$ReturnsStruct_t*) t0)->f_fields)->length;
        l7 = ((vader_array_t*) l1)->length;
        if (l6 == l7) {
            l8 = l0;
            l9 = ((vader_struct_vader_midir$BasicBlock_t*) l8)->f_id;
            l10 = ((vader_struct_vader_midir$BasicBlock_t*) l8)->f_instructions;
            t0 = l3.payload.obj;
            l11 = ((vader_struct_vader_midir$TermReturn_t*) t0)->f_span;
            t0 = l5.payload.obj;
            l12 = ((vader_struct_vader_midir_value__return$ReturnsStruct_t*) t0)->f_fields;
            vader_struct_vader_midir$TermReturn_t* _a0_obj = (vader_struct_vader_midir$TermReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$TermReturn_t));
            vader_obj_header_init(_a0_obj, 1372u);
            _a0_obj->f_span = l11;
            _a0_obj->f_values = l12;
            l11 = (void*) _a0_obj;
            l8 = ((vader_struct_vader_midir$BasicBlock_t*) l8)->f_span;
            vader_struct_vader_midir$BasicBlock_t* _a1_obj = (vader_struct_vader_midir$BasicBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$BasicBlock_t));
            vader_obj_header_init(_a1_obj, 1304u);
            _a1_obj->f_id = l9;
            _a1_obj->f_instructions = l10;
            _a1_obj->f_terminator = vader_ref_box(l11);
            _a1_obj->f_span = l8;
            t0 = (void*) _a1_obj;
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    vader_array_t* _a2_arr = vader_array_new(268u, 0u, 13u, 2082u);
    l8 = (void*) _a2_arr;
    l10 = ((vader_struct_vader_midir$BasicBlock_t*) l0)->f_instructions;
    vader_array_push_all((vader_array_t*) l8, (vader_array_t*) l10);
    vader_array_t* _a3_arr = vader_array_new(22u, 0u, 7u, 338u);
    l10 = (void*) _a3_arr;
    l6 = ((vader_array_t*) l1)->length;
    vader_array_t* _a4_arr = vader_array_repeat((vader_array_t*) l10, (int64_t) l6);
    l10 = (void*) _a4_arr;
    l6 = INT64_C(0);
    l7 = ((vader_array_t*) l1)->length;
    while ((l6 < l7)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        l5 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l6);
        l9 = vader_midir_value__return$add_local(l2, 2524u, l5);
        t0 = l3.payload.obj;
        l11 = ((vader_struct_vader_midir$TermReturn_t*) t0)->f_span;
        vader_array_t* _a6_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        l13 = vader_array_ref_load_box(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l6);
        l12 = (void*) vader_buffer_new((size_t) INT64_C(21));
        l14 = INT64_C(0);
        l14 = std_core$write_string_at(l12, l14, 977u);
        l14 = std_core$write_int(l12, l14, l6);
        l15 = std_core$finish_buffer(l12, l14);
        vader_struct_vader_midir$InstrFieldGet_t* _a7_obj = (vader_struct_vader_midir$InstrFieldGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrFieldGet_t));
        vader_obj_header_init(_a7_obj, 1345u);
        _a7_obj->f_span = l11;
        _a7_obj->f_dst = l9;
        _a7_obj->f_target = l4;
        _a7_obj->f_type = l13;
        _a7_obj->f_field = l15;
        l16 = (void*) _a7_obj;
        vader_array_push_ref((vader_array_t*) l8, l16);
        vader_array_push_i32((vader_array_t*) l10, l9);
        l6 = (l6 + INT64_C(1));
    }
    l11 = l0;
    l4 = ((vader_struct_vader_midir$BasicBlock_t*) l11)->f_id;
    t0 = l3.payload.obj;
    vader_struct_vader_midir$TermReturn_t* _a8_obj = (vader_struct_vader_midir$TermReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$TermReturn_t));
    vader_obj_header_init(_a8_obj, 1372u);
    _a8_obj->f_span = ((vader_struct_vader_midir$TermReturn_t*) t0)->f_span;
    _a8_obj->f_values = l10;
    l10 = (void*) _a8_obj;
    l11 = ((vader_struct_vader_midir$BasicBlock_t*) l11)->f_span;
    vader_struct_vader_midir$BasicBlock_t* _a9_obj = (vader_struct_vader_midir$BasicBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$BasicBlock_t));
    vader_obj_header_init(_a9_obj, 1304u);
    _a9_obj->f_id = l4;
    _a9_obj->f_instructions = l8;
    _a9_obj->f_terminator = vader_ref_box(l10);
    _a9_obj->f_span = l11;
    t0 = (void*) _a9_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_midir_value__return$same_carrier(vader_box_t l0, vader_box_t l1) {
    int32_t l2, l3;
    int64_t l4, l5;
    void* t0;
    bool t1;
    if (l0.tag == 910u) {
        if (l1.tag == 910u) {
            t0 = l0.payload.obj;
            l2 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$StructType_t*) t0)->f_symbol)->f_id;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$StructType_t*) t0)->f_symbol)->f_id;
            if (l2 == l3) {
                t0 = l0.payload.obj;
                l4 = ((vader_array_t*) ((vader_struct_vader_core_types$StructType_t*) t0)->f_args)->length;
                t0 = l1.payload.obj;
                l5 = ((vader_array_t*) ((vader_struct_vader_core_types$StructType_t*) t0)->f_args)->length;
                return l4 == l5;
            }
            return false;
        }
        t1 = vader_core_types$equals_type(l0, l1);
        return t1;
    }
    t1 = vader_core_types$equals_type(l0, l1);
    return t1;
}

void* vader_midir_value__return$scalarise_value_returns(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l17 = NULL;
    void* l20 = NULL;
    void* l23 = NULL;
    void* l24 = NULL;
    void* l27 = NULL;
    void* l28 = NULL;
    void* l29 = NULL;
    int64_t l8, l9, l15, l16, l21, l22;
    vader_string_t l10 = 0;
    vader_string_t l11 = 0;
    vader_string_t l18 = 0;
    vader_string_t l25 = 0;
    vader_string_t l26 = 0;
    vader_box_t l19 = vader_box_null();
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l19, &t2 };
    void** gc_raw_roots[19] = {
        &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l12, &l13, &l14, &l17, &l20, &l23, &l24, &l27,
        &l28, &l29, &t0,
    };
    vader_string_t* gc_atom_roots[5] = { &l10, &l11, &l18, &l25, &l26 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 19u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 7u, 338u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(21u, 0u, 0u, 335u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__i32__string_t* _a3_obj = (vader_struct_std_collections$MutableMap__i32__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__string_t));
    vader_obj_header_init(_a3_obj, 474u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l1 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(21u, 0u, 0u, 335u);
    l2 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(19u, 0u, 12u, 333u);
    l3 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(22u, 0u, 7u, 338u);
    l4 = (void*) _a6_arr;
    vader_struct_std_collections$MutableMap__string__bool_t* _a7_obj = (vader_struct_std_collections$MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__bool_t));
    vader_obj_header_init(_a7_obj, 539u);
    _a7_obj->f_ekeys = l2;
    _a7_obj->f_evals = l3;
    _a7_obj->f_index = l4;
    _a7_obj->f_mask = INT64_C(0);
    _a7_obj->f_grow_at = INT64_C(0);
    _a7_obj->f_size = INT64_C(0);
    _a7_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a7_obj;
    vader_struct_std_collections$MutableSet__string_t* _a8_obj = (vader_struct_std_collections$MutableSet__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__string_t));
    vader_obj_header_init(_a8_obj, 607u);
    _a8_obj->f_inner = t0;
    l2 = (void*) _a8_obj;
    l3 = vader_midir_value__return$choose_functions(l0, l1, l2);
    t1 = std_collections$len__string__Any(l3);
    if (t1 == INT64_C(0)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a9_arr = vader_array_new(21u, 0u, 0u, 335u);
    l4 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(28u, 0u, 0u, 346u);
    l5 = (void*) _a10_arr;
    vader_array_t* _a11_arr = vader_array_new(22u, 0u, 7u, 338u);
    l6 = (void*) _a11_arr;
    vader_struct_std_collections$MutableMap__string__Any_t* _a12_obj = (vader_struct_std_collections$MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__Any_t));
    vader_obj_header_init(_a12_obj, 533u);
    _a12_obj->f_ekeys = l4;
    _a12_obj->f_evals = l5;
    _a12_obj->f_index = l6;
    _a12_obj->f_mask = INT64_C(0);
    _a12_obj->f_grow_at = INT64_C(0);
    _a12_obj->f_size = INT64_C(0);
    _a12_obj->f_tombs = INT64_C(0);
    l4 = (void*) _a12_obj;
    l5 = ((vader_struct_vader_midir$CFGProject_t*) l0)->f_modules;
    l6 = ((vader_struct_std_collections$MutableMap__string__vader_midir_CFGModule_t*) l5)->f_ekeys;
    l7 = ((vader_struct_std_collections$MutableMap__string__vader_midir_CFGModule_t*) l5)->f_evals;
    l8 = INT64_C(0);
    l9 = ((vader_struct_std_collections$MutableMap__string__vader_midir_CFGModule_t*) l5)->f_size;
    while ((l8 < l9)) {
        vader_array_t* _a13_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l8)
        t2 = vader_array_box_slots(_a13_slotarr->buf)[_a13_slotarr->offset + (size_t) l8];
        l10 = t2.payload.s;
        vader_array_t* _a14_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l8)
        l5 = vader_array_ref_load_obj(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l8);
        l11 = l10;
        l12 = l5;
        vader_array_t* _a15_arr = vader_array_new(203u, 0u, 13u, 1306u);
        l13 = (void*) _a15_arr;
        l14 = ((vader_struct_vader_midir$CFGModule_t*) l12)->f_functions;
        l15 = ((vader_array_t*) l14)->length;
        l16 = INT64_C(0);
        while ((l16 < l15)) {
            vader_array_t* _a16_slotarr = ((vader_array_t*) l14);
            VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
            l17 = vader_array_ref_load_obj(_a16_slotarr->buf, _a16_slotarr->offset + (size_t) l16);
            l18 = ((vader_struct_vader_midir$CFGFunction_t*) l17)->f_mangled;
            l19 = std_collections$MutableMap$std_core$Index$at__string__Any(l3, l18);
            l20 = vader_midir_value__return$scalarised_forms(l17, l19);
            l21 = ((vader_array_t*) l20)->length;
            l22 = INT64_C(0);
            while ((l22 < l21)) {
                vader_array_t* _a17_slotarr = ((vader_array_t*) l20);
                VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
                t0 = vader_array_ref_load_obj(_a17_slotarr->buf, _a17_slotarr->offset + (size_t) l22);
                l23 = vader_midir_value__return$rewrite_call_sites(t0, l3, l1, l2);
                vader_array_push_ref((vader_array_t*) l13, l23);
                l22 = (l22 + INT64_C(1));
            }
            l16 = (l16 + INT64_C(1));
        }
        l24 = l12;
        l25 = ((vader_struct_vader_midir$CFGModule_t*) l24)->f_module_id;
        l26 = ((vader_struct_vader_midir$CFGModule_t*) l24)->f_display_path;
        l27 = ((vader_struct_vader_midir$CFGModule_t*) l24)->f_externs;
        l28 = ((vader_struct_vader_midir$CFGModule_t*) l24)->f_struct_decls;
        vader_struct_vader_midir$CFGModule_t* _a18_obj = (vader_struct_vader_midir$CFGModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$CFGModule_t));
        vader_obj_header_init(_a18_obj, 1308u);
        _a18_obj->f_module_id = l25;
        _a18_obj->f_display_path = l26;
        _a18_obj->f_functions = l13;
        _a18_obj->f_externs = l27;
        _a18_obj->f_struct_decls = l28;
        l29 = (void*) _a18_obj;
        std_collections$MutableMap$std_core$IndexSet$set_at__string__Any(l4, l11, vader_ref_box(l29));
        l8 = (l8 + INT64_C(1));
    }
    l1 = l0;
    l2 = ((vader_struct_vader_midir$CFGProject_t*) l1)->f_vtable_entries;
    l3 = ((vader_struct_vader_midir$CFGProject_t*) l1)->f_strings;
    l5 = ((vader_struct_vader_midir$CFGProject_t*) l1)->f_data_pool;
    l6 = ((vader_struct_vader_midir$CFGProject_t*) l1)->f_globals;
    l1 = ((vader_struct_vader_midir$CFGProject_t*) l1)->f_trait_membership;
    vader_struct_vader_midir$CFGProject_t* _a19_obj = (vader_struct_vader_midir$CFGProject_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$CFGProject_t));
    vader_obj_header_init(_a19_obj, 1310u);
    _a19_obj->f_modules = l4;
    _a19_obj->f_vtable_entries = l2;
    _a19_obj->f_strings = l3;
    _a19_obj->f_data_pool = l5;
    _a19_obj->f_globals = l6;
    _a19_obj->f_trait_membership = l1;
    t0 = (void*) _a19_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir_value__return$scalarised_copy(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    vader_box_t l4 = vader_box_null(), l12 = vader_box_null(), l16 = vader_box_null();
    int32_t l7, l9;
    bool l10;
    vader_string_t l11 = 0;
    vader_string_t l15 = 0;
    void* t0 = NULL;
    vader_box_t* gc_roots[3] = { &l4, &l12, &l16 };
    void** gc_raw_roots[9] = { &l0, &l2, &l3, &l5, &l6, &l8, &l13, &l14, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l11, &l15 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = l0;
    l3 = ((vader_struct_vader_midir$CFGFunction_t*) l2)->f_params;
    l4 = ((vader_struct_vader_midir$CFGFunction_t*) l2)->f_return_type;
    l5 = ((vader_struct_vader_midir$CFGFunction_t*) l2)->f_locals;
    l6 = ((vader_struct_vader_midir$CFGFunction_t*) l2)->f_blocks;
    l7 = ((vader_struct_vader_midir$CFGFunction_t*) l2)->f_entry;
    l8 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_origin;
    l9 = ((vader_struct_vader_core_mono$MonoEntry_t*) l8)->f_id;
    l10 = ((vader_struct_vader_core_mono$MonoEntry_t*) l8)->f_is_main;
    l11 = ((vader_struct_vader_core_mono$MonoEntry_t*) l8)->f_mangled;
    l12 = ((vader_struct_vader_core_mono$MonoEntry_t*) l8)->f_decl;
    l13 = ((vader_struct_vader_core_mono$MonoEntry_t*) l8)->f_subst;
    l14 = ((vader_struct_vader_core_mono$MonoEntry_t*) l8)->f_type_arguments;
    l15 = ((vader_struct_vader_core_mono$MonoEntry_t*) l8)->f_module;
    l16 = ((vader_struct_vader_core_mono$MonoEntry_t*) l8)->f_vtable_slot;
    vader_struct_vader_core_mono$MonoEntry_t* _a0_obj = (vader_struct_vader_core_mono$MonoEntry_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_mono$MonoEntry_t));
    vader_obj_header_init(_a0_obj, 890u);
    _a0_obj->f_id = l9;
    _a0_obj->f_is_main = l10;
    _a0_obj->f_mangled = l11;
    _a0_obj->f_decl = l12;
    _a0_obj->f_symbol = vader_box_obj(0u, NULL);
    _a0_obj->f_subst = l13;
    _a0_obj->f_type_arguments = l14;
    _a0_obj->f_module = l15;
    _a0_obj->f_vtable_slot = l16;
    l8 = (void*) _a0_obj;
    l2 = ((vader_struct_vader_midir$CFGFunction_t*) l2)->f_scalarised_results;
    vader_struct_vader_midir$CFGFunction_t* _a1_obj = (vader_struct_vader_midir$CFGFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$CFGFunction_t));
    vader_obj_header_init(_a1_obj, 1306u);
    _a1_obj->f_mangled = l1;
    _a1_obj->f_params = l3;
    _a1_obj->f_return_type = l4;
    _a1_obj->f_locals = l5;
    _a1_obj->f_blocks = l6;
    _a1_obj->f_entry = l7;
    _a1_obj->f_origin = l8;
    _a1_obj->f_scalarised_results = l2;
    t0 = (void*) _a1_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_midir_value__return$scalarised_copy_mangle(vader_string_t l0) {
    vader_string_t t0;
    t0 = concat_2(l0, 280u);
    return t0;
}

static void* vader_midir_value__return$scalarised_forms(void* l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    bool l4;
    vader_string_t l5 = 0;
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[5] = { &l0, &l3, &l6, &l7, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1.tag == 0u) {
        vader_array_t* _a0_arr = vader_array_new(203u, 1u, 13u, 1306u);
        ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l0;
        t0 = (void*) _a0_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l1.payload.obj;
    l2 = ((vader_struct_vader_midir_value__return$ReturnShape_t*) t0)->f_forward_to;
    if (!(l2.tag == 0u)) {
        l5 = l2.payload.s;
        l3 = vader_midir_value__return$forwarding_body(l0, l5);
        l5 = l2.payload.s;
        l6 = vader_midir_value__return$scalarised_copy(l0, l5);
        t0 = l1.payload.obj;
        l7 = ((vader_struct_vader_midir_value__return$ReturnShape_t*) t0)->f_elements;
        t0 = l1.payload.obj;
        l4 = !(((vader_struct_vader_midir_value__return$ReturnShape_t*) t0)->f_rebuilt.tag == 0u);
        l6 = vader_midir_value__return$rewrite_callee(l6, l7, l4);
        vader_array_t* _a1_arr = vader_array_new(203u, 2u, 13u, 1306u);
        ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 1u] = l6;
        ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = l3;
        t0 = (void*) _a1_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l1.payload.obj;
    l3 = ((vader_struct_vader_midir_value__return$ReturnShape_t*) t0)->f_elements;
    t0 = l1.payload.obj;
    l4 = !(((vader_struct_vader_midir_value__return$ReturnShape_t*) t0)->f_rebuilt.tag == 0u);
    t0 = vader_midir_value__return$rewrite_callee(l0, l3, l4);
    vader_array_t* _a2_arr = vader_array_new(203u, 1u, 13u, 1306u);
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = t0;
    t0 = (void*) _a2_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_midir_value__return$struct_field_forward_project(void* l0) {
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
            l16 = vader_midir_value__return$forward_struct_fields_in_fn(t1);
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

static int32_t vader_midir_value__return$tuple_field_index(vader_string_t l0) {
    int64_t l1;
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    bool t0;
    vader_string_t t1 = 0;
    int32_t t2;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[1] = { &l2 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = std_string$starts_with(l0, 977u);
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return INT32_C(-1); }
    }
    l1 = std_core$len(l0);
    vader_struct_std_core$Range__i64_t* _a0_obj = (vader_struct_std_core$Range__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_core$Range__i64_t));
    vader_obj_header_init(_a0_obj, 613u);
    _a0_obj->f_start = INT64_C(1);
    _a0_obj->f_end = l1;
    _a0_obj->f_inclusive = false;
    _a0_obj->f_done = false;
    _a0_obj->f_cursor = INT64_C(1);
    l2 = (void*) _a0_obj;
    t1 = std_core$string$Index$at$1(l0, l2);
    l3 = std_string$parse_int(t1);
    if (!(l3.tag == 338u)) {
        { vader_gc_top = gc_frame.prev; return INT32_C(-1); }
    }
    t2 = ((int32_t) l3.payload.i);
    { int32_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_value__return$zero_const_for(vader_box_t l0) {
    void* t0 = NULL;
    vader_string_t t1 = 0;
    bool t2;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!(l0.tag == 907u)) {
        vader_struct_vader_midir$ConstInt_t* _a0_obj = (vader_struct_vader_midir$ConstInt_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$ConstInt_t));
        vader_obj_header_init(_a0_obj, 1321u);
        _a0_obj->f_value = INT64_C(0);
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l0.payload.obj;
    t1 = ((vader_struct_vader_core_types$PrimitiveType_t*) t0)->f_name;
    if (t1 == 1634u) {
        vader_struct_vader_midir$ConstBool_t* _a1_obj = (vader_struct_vader_midir$ConstBool_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$ConstBool_t));
        vader_obj_header_init(_a1_obj, 1318u);
        _a1_obj->f_value = false;
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l0.payload.obj;
    t1 = ((vader_struct_vader_core_types$PrimitiveType_t*) t0)->f_name;
    if (t1 == 1753u) {
        vader_struct_vader_midir$ConstChar_t* _a2_obj = (vader_struct_vader_midir$ConstChar_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$ConstChar_t));
        vader_obj_header_init(_a2_obj, 1319u);
        _a2_obj->f_value = INT32_C(32);
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l0.payload.obj;
    t1 = ((vader_struct_vader_core_types$PrimitiveType_t*) t0)->f_name;
    t2 = vader_core_types$is_float_name(t1);
    if (!(t2)) {
        vader_struct_vader_midir$ConstInt_t* _a3_obj = (vader_struct_vader_midir$ConstInt_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$ConstInt_t));
        vader_obj_header_init(_a3_obj, 1321u);
        _a3_obj->f_value = INT64_C(0);
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_midir$ConstFloat_t* _a4_obj = (vader_struct_vader_midir$ConstFloat_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$ConstFloat_t));
    vader_obj_header_init(_a4_obj, 1320u);
    _a4_obj->f_value = 0.0;
    t0 = (void*) _a4_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_midir_value__return$zero_of(void* l0, void* l1, vader_box_t l2, void* l3) {
    int32_t l4;
    vader_box_t l5 = vader_box_null();
    void* l6 = NULL;
    vader_box_t* gc_roots[2] = { &l2, &l5 };
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = vader_midir_value__return$add_local(l1, 1509u, l2);
    l5 = vader_midir_value__return$zero_const_for(l2);
    vader_struct_vader_midir$InstrConst_t* _a0_obj = (vader_struct_vader_midir$InstrConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrConst_t));
    vader_obj_header_init(_a0_obj, 1341u);
    _a0_obj->f_span = l3;
    _a0_obj->f_dst = l4;
    _a0_obj->f_value = l5;
    _a0_obj->f_type = l2;
    l6 = (void*) _a0_obj;
    vader_array_push_ref((vader_array_t*) l0, l6);
    { int32_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}
