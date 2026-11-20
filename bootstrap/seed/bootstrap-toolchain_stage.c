#include "bootstrap.split.h"

static vader_string_t toolchain_stage$SourceSpec$Placed$precedes(void* l0, void* l1);
static vader_string_t toolchain_stage$SourceSpec$Placed$stage_name(void* l0);
static vader_box_t toolchain_stage$first_free(void* l0, void* l1);
static vader_box_t toolchain_stage$plan_order__toolchain_stage_SourceSpec(void* l0);
static vader_box_t toolchain_stage$plan_order__vader_emit_bytecode_BytecodeSpec(void* l0);
static vader_box_t toolchain_stage$plan_order__vader_pipeline_check_CheckSpec(void* l0);
static vader_string_t toolchain_stage$waits__toolchain_stage_SourceSpec(void* l0, void* l1, void* l2, void* l3);
static vader_string_t toolchain_stage$waits__vader_emit_bytecode_BytecodeSpec(void* l0, void* l1, void* l2, void* l3);
static vader_string_t toolchain_stage$waits__vader_pipeline_check_CheckSpec(void* l0, void* l1, void* l2, void* l3);

static vader_string_t toolchain_stage$SourceSpec$Placed$precedes(void* l0, void* l1) {
    void* l2 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    int64_t l3, l4, l9, l10;
    vader_box_t l5 = vader_box_null(), l11 = vader_box_null();
    bool l8;
    vader_string_t l12 = 0;
    vader_string_t l13 = 0;
    bool t0;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[2] = { &l5, &l11 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l6, &l7 };
    vader_string_t* gc_atom_roots[3] = { &l12, &l13, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_stage$SourceSpec_t*) l0)->f_generates;
    l3 = vader_array_length(((vader_array_t*) l2));
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l4);
        l6 = ((vader_struct_toolchain_stage$SourceSpec_t*) l1)->f_given;
        vader_struct___lambda_env_toolchain_stage_9_t* _a1_obj = (vader_struct___lambda_env_toolchain_stage_9_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_toolchain_stage_9_t));
        vader_obj_header_init(_a1_obj, 616u);
        _a1_obj->f_cap_0 = l5;
        l7 = (void*) _a1_obj;
        l8 = false;
        l9 = vader_array_length(((vader_array_t*) l6));
        l10 = INT64_C(0);
        {
            while ((l10 < l9)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                l11 = vader_array_ref_load_box(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l10);
                t0 = __lambda_toolchain_stage_8(l7, l11);
                if (t0) {
                    l8 = true;
                    goto end_27;
                }
                l10 = (l10 + INT64_C(1));
            }
            l8 = false;
        } end_27: ;
        if (l8) {
            l12 = ((vader_struct_toolchain_stage$SourceSpec_t*) l1)->f_name;
            l13 = ((vader_struct_toolchain_stage$SourceSpec_t*) l0)->f_name;
            t1 = concat_5(1258u, l12, 1512u, l13, 1330u);
            { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l4 = (l4 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return 0u; }
}

static vader_string_t toolchain_stage$SourceSpec$Placed$stage_name(void* l0) {
    vader_string_t t0;
    t0 = ((vader_struct_toolchain_stage$SourceSpec_t*) l0)->f_name;
    return t0;
}

static vader_box_t toolchain_stage$first_free(void* l0, void* l1) {
    int64_t l2, l3, l7, l8, l9;
    void* l4 = NULL;
    void* l5 = NULL;
    bool l6;
    bool t0, t1;
    void** gc_raw_roots[4] = { &l0, &l1, &l4, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = INT64_C(0);
    l3 = vader_array_length(((vader_array_t*) l0));
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        t0 = ((uint8_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l2];
        t1 = t0;
        if (!(t1)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            l4 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l2);
            vader_struct___lambda_env_toolchain_stage_7_t* _a2_obj = (vader_struct___lambda_env_toolchain_stage_7_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_toolchain_stage_7_t));
            vader_obj_header_init(_a2_obj, 615u);
            _a2_obj->f_cap_0 = l1;
            l5 = (void*) _a2_obj;
            l6 = false;
            l7 = vader_array_length(((vader_array_t*) l4));
            l8 = INT64_C(0);
            {
                for (;;) {
                    if ((l8 < l7)) {
                        vader_array_t* _a3_slotarr = ((vader_array_t*) l4);
                        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                        l9 = ((int64_t*) _a3_slotarr->buf->slots)[vader_array_offset(_a3_slotarr) + (size_t) l8];
                        t0 = __lambda_toolchain_stage_6(l5, l9);
                        if (t0) {
                            l8 = (l8 + INT64_C(1));
                            continue;
                        }
                        l6 = false;
                        goto end_30;
                    }
                    break;
                }
                l6 = true;
            } end_30: ;
            if (l6) {
                { vader_box_t __vret = vader_box_i64(580u, l2); vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
        l2 = (l2 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t toolchain_stage$plan_order__toolchain_stage_SourceSpec(void* l0) {
    int64_t l1, l5, l6;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l9 = NULL;
    vader_string_t l7 = 0;
    vader_string_t l8 = 0;
    vader_box_t l10 = vader_box_null();
    void* t0 = NULL;
    bool t1;
    vader_string_t t2 = 0;
    int64_t t3;
    vader_box_t* gc_roots[1] = { &l10 };
    void** gc_raw_roots[6] = { &l0, &l2, &l3, &l4, &l9, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l7, &l8, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_array_length(((vader_array_t*) l0));
    vader_array_t* _a0_arr = vader_array_new(26u, 0u, 0u, 576u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(24u, 0u, 12u, 574u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(27u, 0u, 7u, 579u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections$Map__string__bool_t* _a3_obj = (vader_struct_std_collections$Map__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__bool_t));
    vader_obj_header_init(_a3_obj, 900u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections$Set__string_t* _a4_obj = (vader_struct_std_collections$Set__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__string_t));
    vader_obj_header_init(_a4_obj, 990u);
    _a4_obj->f_inner = t0;
    l2 = (void*) _a4_obj;
    l3 = l0;
    l5 = vader_array_length(((vader_array_t*) l3));
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        l4 = vader_array_ref_load_obj(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) l6);
        l7 = toolchain_stage$SourceSpec$Placed$stage_name(l4);
        t1 = std_collections$add__string(l2, l7);
        if (!(t1)) {
            l8 = toolchain_stage$SourceSpec$Placed$stage_name(l4);
            t2 = concat_3(3233u, l8, 1258u);
            vader_struct_toolchain_stage$PlanError_t* _a6_obj = (vader_struct_toolchain_stage$PlanError_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_stage$PlanError_t));
            vader_obj_header_init(_a6_obj, 1160u);
            _a6_obj->f_message = t2;
            t0 = (void*) _a6_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l6 = (l6 + INT64_C(1));
    }
    l2 = (void*) &vader_fn_static___lambda_toolchain_stage_4;
    l2 = std_core$filled__i64__(l1, l2);
    l3 = (void*) &vader_fn_static___lambda_toolchain_stage_5;
    l3 = std_core$filled__string__(l1, l3);
    l5 = INT64_C(0);
    while ((l5 < l1)) {
        l6 = INT64_C(0);
        while ((l6 < l1)) {
            if (l5 == l6) {
                l6 = (l6 + INT64_C(1));
                continue;
            }
            vader_array_t* _a7_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l6)
            l4 = vader_array_ref_load_obj(_a7_slotarr->buf, vader_array_offset(_a7_slotarr) + (size_t) l6);
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l5)
            l9 = vader_array_ref_load_obj(_a7_slotarr->buf, vader_array_offset(_a7_slotarr) + (size_t) l5);
            l7 = toolchain_stage$SourceSpec$Placed$precedes(l4, l9);
            if (l7 != 0u) {
                vader_array_t* _a8_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l5)
                t0 = vader_array_ref_load_obj(_a8_slotarr->buf, vader_array_offset(_a8_slotarr) + (size_t) l5);
                vader_array_push_i64((vader_array_t*) t0, l6);
                vader_array_t* _a9_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l5)
                t0 = vader_array_ref_load_obj(_a9_slotarr->buf, vader_array_offset(_a9_slotarr) + (size_t) l5);
                vader_array_push_scalar((vader_array_t*) t0, vader_box_string(576u, l7));
            }
            l6 = (l6 + INT64_C(1));
        }
        l5 = (l5 + INT64_C(1));
    }
    vader_array_t* _a10_arr = vader_array_new(28u, 0u, 8u, 580u);
    l4 = (void*) _a10_arr;
    vader_array_t* _a11_arr = vader_array_new(24u, 1u, 12u, 574u);
    ((uint8_t*) _a11_arr->buf->slots)[vader_array_offset(_a11_arr) + 0u] = (uint8_t) false;
    t0 = (void*) _a11_arr;
    vader_array_t* _a12_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l1);
    l9 = (void*) _a12_arr;
    for (;;) {
        t3 = vader_array_length(((vader_array_t*) l4));
        if ((t3 < l1)) {
            l10 = toolchain_stage$first_free(l2, l9);
            if (l10.tag == 0u) {
                l7 = toolchain_stage$waits__toolchain_stage_SourceSpec(l0, l2, l3, l9);
                t2 = concat_2(2855u, l7);
                vader_struct_toolchain_stage$PlanError_t* _a13_obj = (vader_struct_toolchain_stage$PlanError_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_stage$PlanError_t));
                vader_obj_header_init(_a13_obj, 1160u);
                _a13_obj->f_message = t2;
                t0 = (void*) _a13_obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l5 = ((int64_t) l10.payload.i);
            vader_array_t* _a14_slotarr = ((vader_array_t*) l9);
            VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l5)
            ((uint8_t*) _a14_slotarr->buf->slots)[vader_array_offset(_a14_slotarr) + (size_t) l5] = (uint8_t) true;
            vader_array_push_i64((vader_array_t*) l4, l5);
            continue;
        }
        break;
    }
    { vader_box_t __vret = vader_ref_box(l4); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t toolchain_stage$plan_order__vader_emit_bytecode_BytecodeSpec(void* l0) {
    int64_t l1, l5, l6;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l9 = NULL;
    vader_string_t l7 = 0;
    vader_string_t l8 = 0;
    vader_box_t l10 = vader_box_null();
    void* t0 = NULL;
    bool t1;
    vader_string_t t2 = 0;
    int64_t t3;
    vader_box_t* gc_roots[1] = { &l10 };
    void** gc_raw_roots[6] = { &l0, &l2, &l3, &l4, &l9, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l7, &l8, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_array_length(((vader_array_t*) l0));
    vader_array_t* _a0_arr = vader_array_new(26u, 0u, 0u, 576u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(24u, 0u, 12u, 574u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(27u, 0u, 7u, 579u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections$Map__string__bool_t* _a3_obj = (vader_struct_std_collections$Map__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__bool_t));
    vader_obj_header_init(_a3_obj, 900u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections$Set__string_t* _a4_obj = (vader_struct_std_collections$Set__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__string_t));
    vader_obj_header_init(_a4_obj, 990u);
    _a4_obj->f_inner = t0;
    l2 = (void*) _a4_obj;
    l3 = l0;
    l5 = vader_array_length(((vader_array_t*) l3));
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        l4 = vader_array_ref_load_obj(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) l6);
        l7 = vader_emit_bytecode$BytecodeSpec$toolchain_stage$Placed$stage_name(l4);
        t1 = std_collections$add__string(l2, l7);
        if (!(t1)) {
            l8 = vader_emit_bytecode$BytecodeSpec$toolchain_stage$Placed$stage_name(l4);
            t2 = concat_3(3233u, l8, 1258u);
            vader_struct_toolchain_stage$PlanError_t* _a6_obj = (vader_struct_toolchain_stage$PlanError_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_stage$PlanError_t));
            vader_obj_header_init(_a6_obj, 1160u);
            _a6_obj->f_message = t2;
            t0 = (void*) _a6_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l6 = (l6 + INT64_C(1));
    }
    l2 = (void*) &vader_fn_static___lambda_toolchain_stage_2;
    l2 = std_core$filled__i64__(l1, l2);
    l3 = (void*) &vader_fn_static___lambda_toolchain_stage_3;
    l3 = std_core$filled__string__(l1, l3);
    l5 = INT64_C(0);
    while ((l5 < l1)) {
        l6 = INT64_C(0);
        while ((l6 < l1)) {
            if (l5 == l6) {
                l6 = (l6 + INT64_C(1));
                continue;
            }
            vader_array_t* _a7_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l6)
            l4 = vader_array_ref_load_obj(_a7_slotarr->buf, vader_array_offset(_a7_slotarr) + (size_t) l6);
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l5)
            l9 = vader_array_ref_load_obj(_a7_slotarr->buf, vader_array_offset(_a7_slotarr) + (size_t) l5);
            l7 = vader_emit_bytecode$BytecodeSpec$toolchain_stage$Placed$precedes(l4, l9);
            if (l7 != 0u) {
                vader_array_t* _a8_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l5)
                t0 = vader_array_ref_load_obj(_a8_slotarr->buf, vader_array_offset(_a8_slotarr) + (size_t) l5);
                vader_array_push_i64((vader_array_t*) t0, l6);
                vader_array_t* _a9_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l5)
                t0 = vader_array_ref_load_obj(_a9_slotarr->buf, vader_array_offset(_a9_slotarr) + (size_t) l5);
                vader_array_push_scalar((vader_array_t*) t0, vader_box_string(576u, l7));
            }
            l6 = (l6 + INT64_C(1));
        }
        l5 = (l5 + INT64_C(1));
    }
    vader_array_t* _a10_arr = vader_array_new(28u, 0u, 8u, 580u);
    l4 = (void*) _a10_arr;
    vader_array_t* _a11_arr = vader_array_new(24u, 1u, 12u, 574u);
    ((uint8_t*) _a11_arr->buf->slots)[vader_array_offset(_a11_arr) + 0u] = (uint8_t) false;
    t0 = (void*) _a11_arr;
    vader_array_t* _a12_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l1);
    l9 = (void*) _a12_arr;
    for (;;) {
        t3 = vader_array_length(((vader_array_t*) l4));
        if ((t3 < l1)) {
            l10 = toolchain_stage$first_free(l2, l9);
            if (l10.tag == 0u) {
                l7 = toolchain_stage$waits__vader_emit_bytecode_BytecodeSpec(l0, l2, l3, l9);
                t2 = concat_2(2855u, l7);
                vader_struct_toolchain_stage$PlanError_t* _a13_obj = (vader_struct_toolchain_stage$PlanError_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_stage$PlanError_t));
                vader_obj_header_init(_a13_obj, 1160u);
                _a13_obj->f_message = t2;
                t0 = (void*) _a13_obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l5 = ((int64_t) l10.payload.i);
            vader_array_t* _a14_slotarr = ((vader_array_t*) l9);
            VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l5)
            ((uint8_t*) _a14_slotarr->buf->slots)[vader_array_offset(_a14_slotarr) + (size_t) l5] = (uint8_t) true;
            vader_array_push_i64((vader_array_t*) l4, l5);
            continue;
        }
        break;
    }
    { vader_box_t __vret = vader_ref_box(l4); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t toolchain_stage$plan_order__vader_pipeline_check_CheckSpec(void* l0) {
    int64_t l1, l5, l6;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l9 = NULL;
    vader_string_t l7 = 0;
    vader_string_t l8 = 0;
    vader_box_t l10 = vader_box_null();
    void* t0 = NULL;
    bool t1;
    vader_string_t t2 = 0;
    int64_t t3;
    vader_box_t* gc_roots[1] = { &l10 };
    void** gc_raw_roots[6] = { &l0, &l2, &l3, &l4, &l9, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l7, &l8, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_array_length(((vader_array_t*) l0));
    vader_array_t* _a0_arr = vader_array_new(26u, 0u, 0u, 576u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(24u, 0u, 12u, 574u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(27u, 0u, 7u, 579u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections$Map__string__bool_t* _a3_obj = (vader_struct_std_collections$Map__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__bool_t));
    vader_obj_header_init(_a3_obj, 900u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections$Set__string_t* _a4_obj = (vader_struct_std_collections$Set__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__string_t));
    vader_obj_header_init(_a4_obj, 990u);
    _a4_obj->f_inner = t0;
    l2 = (void*) _a4_obj;
    l3 = l0;
    l5 = vader_array_length(((vader_array_t*) l3));
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        l4 = vader_array_ref_load_obj(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) l6);
        l7 = vader_pipeline_check$CheckSpec$toolchain_stage$Placed$stage_name(l4);
        t1 = std_collections$add__string(l2, l7);
        if (!(t1)) {
            l8 = vader_pipeline_check$CheckSpec$toolchain_stage$Placed$stage_name(l4);
            t2 = concat_3(3233u, l8, 1258u);
            vader_struct_toolchain_stage$PlanError_t* _a6_obj = (vader_struct_toolchain_stage$PlanError_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_stage$PlanError_t));
            vader_obj_header_init(_a6_obj, 1160u);
            _a6_obj->f_message = t2;
            t0 = (void*) _a6_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l6 = (l6 + INT64_C(1));
    }
    l2 = (void*) &vader_fn_static___lambda_toolchain_stage_0;
    l2 = std_core$filled__i64__(l1, l2);
    l3 = (void*) &vader_fn_static___lambda_toolchain_stage_1;
    l3 = std_core$filled__string__(l1, l3);
    l5 = INT64_C(0);
    while ((l5 < l1)) {
        l6 = INT64_C(0);
        while ((l6 < l1)) {
            if (l5 == l6) {
                l6 = (l6 + INT64_C(1));
                continue;
            }
            vader_array_t* _a7_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l6)
            l4 = vader_array_ref_load_obj(_a7_slotarr->buf, vader_array_offset(_a7_slotarr) + (size_t) l6);
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l5)
            l9 = vader_array_ref_load_obj(_a7_slotarr->buf, vader_array_offset(_a7_slotarr) + (size_t) l5);
            l7 = vader_pipeline_check$CheckSpec$toolchain_stage$Placed$precedes(l4, l9);
            if (l7 != 0u) {
                vader_array_t* _a8_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l5)
                t0 = vader_array_ref_load_obj(_a8_slotarr->buf, vader_array_offset(_a8_slotarr) + (size_t) l5);
                vader_array_push_i64((vader_array_t*) t0, l6);
                vader_array_t* _a9_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l5)
                t0 = vader_array_ref_load_obj(_a9_slotarr->buf, vader_array_offset(_a9_slotarr) + (size_t) l5);
                vader_array_push_scalar((vader_array_t*) t0, vader_box_string(576u, l7));
            }
            l6 = (l6 + INT64_C(1));
        }
        l5 = (l5 + INT64_C(1));
    }
    vader_array_t* _a10_arr = vader_array_new(28u, 0u, 8u, 580u);
    l4 = (void*) _a10_arr;
    vader_array_t* _a11_arr = vader_array_new(24u, 1u, 12u, 574u);
    ((uint8_t*) _a11_arr->buf->slots)[vader_array_offset(_a11_arr) + 0u] = (uint8_t) false;
    t0 = (void*) _a11_arr;
    vader_array_t* _a12_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l1);
    l9 = (void*) _a12_arr;
    for (;;) {
        t3 = vader_array_length(((vader_array_t*) l4));
        if ((t3 < l1)) {
            l10 = toolchain_stage$first_free(l2, l9);
            if (l10.tag == 0u) {
                l7 = toolchain_stage$waits__vader_pipeline_check_CheckSpec(l0, l2, l3, l9);
                t2 = concat_2(2855u, l7);
                vader_struct_toolchain_stage$PlanError_t* _a13_obj = (vader_struct_toolchain_stage$PlanError_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_stage$PlanError_t));
                vader_obj_header_init(_a13_obj, 1160u);
                _a13_obj->f_message = t2;
                t0 = (void*) _a13_obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l5 = ((int64_t) l10.payload.i);
            vader_array_t* _a14_slotarr = ((vader_array_t*) l9);
            VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l5)
            ((uint8_t*) _a14_slotarr->buf->slots)[vader_array_offset(_a14_slotarr) + (size_t) l5] = (uint8_t) true;
            vader_array_push_i64((vader_array_t*) l4, l5);
            continue;
        }
        break;
    }
    { vader_box_t __vret = vader_ref_box(l4); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t toolchain_stage$plan_stages__toolchain_stage_Sources__toolchain_stage_Generated__toolchain_stage_SourceSpec(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l5 = NULL;
    int64_t l3, l4, l8;
    vader_box_t l6 = vader_box_null(), l7 = vader_box_null();
    int64_t t0;
    vader_box_t t1 = vader_box_null(), t2 = vader_box_null();
    void* t3 = NULL;
    vader_box_t* gc_roots[4] = { &l6, &l7, &t1, &t2 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l5, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_array_length(((vader_array_t*) l0));
    vader_array_t* _a0_arr = vader_array_reserve(93u, (int64_t) t0, 13u, 1161u);
    l1 = (void*) _a0_arr;
    l2 = l0;
    l3 = vader_array_length(((vader_array_t*) l2));
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t1 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l4);
        t2 = toolchain_stage$Stage$describe$$dispatch(t1);
        l5 = t2.payload.obj;
        vader_array_push_ref((vader_array_t*) l1, l5);
        l4 = (l4 + INT64_C(1));
    }
    l6 = toolchain_stage$plan_order__toolchain_stage_SourceSpec(l1);
    l7 = l6;
    if (l6.tag == 1160u) {
        t3 = l7.payload.obj;
        { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = l6.payload.obj;
    t0 = vader_array_length(((vader_array_t*) l1));
    vader_array_t* _a2_arr = vader_array_reserve(34u, (int64_t) t0, 0u, 590u);
    l2 = (void*) _a2_arr;
    l3 = vader_array_length(((vader_array_t*) l1));
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        l8 = ((int64_t*) _a3_slotarr->buf->slots)[vader_array_offset(_a3_slotarr) + (size_t) l4];
        vader_array_t* _a4_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l8)
        l6 = vader_array_ref_load_box(_a4_slotarr->buf, vader_array_offset(_a4_slotarr) + (size_t) l8);
        vader_array_push((vader_array_t*) l2, l6);
        l4 = (l4 + INT64_C(1));
    }
    { vader_box_t __vret = vader_ref_box(l2); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t toolchain_stage$plan_stages__vader_core_bytecode_BcFunction__vader_core_bytecode_BcFunction__vader_emit_bytecode_BytecodeSpec(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l5 = NULL;
    int64_t l3, l4, l8;
    vader_box_t l6 = vader_box_null(), l7 = vader_box_null();
    int64_t t0;
    vader_box_t t1 = vader_box_null(), t2 = vader_box_null();
    void* t3 = NULL;
    vader_box_t* gc_roots[4] = { &l6, &l7, &t1, &t2 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l5, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_array_length(((vader_array_t*) l0));
    vader_array_t* _a0_arr = vader_array_reserve(224u, (int64_t) t0, 13u, 1373u);
    l1 = (void*) _a0_arr;
    l2 = l0;
    l3 = vader_array_length(((vader_array_t*) l2));
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t1 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l4);
        t2 = toolchain_stage$Stage$describe$$dispatch(t1);
        l5 = t2.payload.obj;
        vader_array_push_ref((vader_array_t*) l1, l5);
        l4 = (l4 + INT64_C(1));
    }
    l6 = toolchain_stage$plan_order__vader_emit_bytecode_BytecodeSpec(l1);
    l7 = l6;
    if (l6.tag == 1160u) {
        t3 = l7.payload.obj;
        { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = l6.payload.obj;
    t0 = vader_array_length(((vader_array_t*) l1));
    vader_array_t* _a2_arr = vader_array_reserve(34u, (int64_t) t0, 0u, 590u);
    l2 = (void*) _a2_arr;
    l3 = vader_array_length(((vader_array_t*) l1));
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        l8 = ((int64_t*) _a3_slotarr->buf->slots)[vader_array_offset(_a3_slotarr) + (size_t) l4];
        vader_array_t* _a4_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l8)
        l6 = vader_array_ref_load_box(_a4_slotarr->buf, vader_array_offset(_a4_slotarr) + (size_t) l8);
        vader_array_push((vader_array_t*) l2, l6);
        l4 = (l4 + INT64_C(1));
    }
    { vader_box_t __vret = vader_ref_box(l2); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t toolchain_stage$plan_stages__vader_pipeline_check_Checked__toolchain_diagnostics_Diagnostic____vader_pipeline_check_CheckSpec(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l5 = NULL;
    int64_t l3, l4, l8;
    vader_box_t l6 = vader_box_null(), l7 = vader_box_null();
    int64_t t0;
    vader_box_t t1 = vader_box_null(), t2 = vader_box_null();
    void* t3 = NULL;
    vader_box_t* gc_roots[4] = { &l6, &l7, &t1, &t2 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l5, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_array_length(((vader_array_t*) l0));
    vader_array_t* _a0_arr = vader_array_reserve(397u, (int64_t) t0, 13u, 1901u);
    l1 = (void*) _a0_arr;
    l2 = l0;
    l3 = vader_array_length(((vader_array_t*) l2));
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t1 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l4);
        t2 = toolchain_stage$Stage$describe$$dispatch(t1);
        l5 = t2.payload.obj;
        vader_array_push_ref((vader_array_t*) l1, l5);
        l4 = (l4 + INT64_C(1));
    }
    l6 = toolchain_stage$plan_order__vader_pipeline_check_CheckSpec(l1);
    l7 = l6;
    if (l6.tag == 1160u) {
        t3 = l7.payload.obj;
        { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = l6.payload.obj;
    t0 = vader_array_length(((vader_array_t*) l1));
    vader_array_t* _a2_arr = vader_array_reserve(34u, (int64_t) t0, 0u, 590u);
    l2 = (void*) _a2_arr;
    l3 = vader_array_length(((vader_array_t*) l1));
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        l8 = ((int64_t*) _a3_slotarr->buf->slots)[vader_array_offset(_a3_slotarr) + (size_t) l4];
        vader_array_t* _a4_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l8)
        l6 = vader_array_ref_load_box(_a4_slotarr->buf, vader_array_offset(_a4_slotarr) + (size_t) l8);
        vader_array_push((vader_array_t*) l2, l6);
        l4 = (l4 + INT64_C(1));
    }
    { vader_box_t __vret = vader_ref_box(l2); vader_gc_top = gc_frame.prev; return __vret; }
}

bool toolchain_stage$same_given(vader_box_t l0, vader_box_t l1) {
    bool l2;
    uint8_t l3, l4;
    void* l5;
    void* l6;
    void* t0;
    if (l0.tag == 1157u) {
        if (l1.tag == 1157u) {
            t0 = l1.payload.obj;
            l3 = ((vader_struct_toolchain_stage$DecoratedWith_t*) t0)->f_marker;
            t0 = l0.payload.obj;
            l4 = ((vader_struct_toolchain_stage$DecoratedWith_t*) t0)->f_marker;
            l2 = l3 == l4;
        } else {
            l2 = false;
        }
        return l2;
    }
    if (!(l0.tag == 1158u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    if (l1.tag == 1158u) {
        l5 = l1.payload.obj;
        l6 = l0.payload.obj;
        l2 = toolchain_stage$same_origin(l5, l6);
    } else {
        l2 = false;
    }
    return l2;
}

bool toolchain_stage$same_origin(void* l0, void* l1) {
    vader_string_t l2, l3;
    l2 = ((vader_struct_toolchain_stage$DecoratorOrigin_t*) l0)->f_module;
    l3 = ((vader_struct_toolchain_stage$DecoratorOrigin_t*) l1)->f_module;
    if (l2 == l3) {
        l2 = ((vader_struct_toolchain_stage$DecoratorOrigin_t*) l0)->f_name;
        l3 = ((vader_struct_toolchain_stage$DecoratorOrigin_t*) l1)->f_name;
        return l2 == l3;
    }
    return false;
}

static vader_string_t toolchain_stage$waits__toolchain_stage_SourceSpec(void* l0, void* l1, void* l2, void* l3) {
    void* l4 = NULL;
    int64_t l5, l6, l7, l8, l9;
    vader_string_t l10 = 0;
    vader_string_t l11 = 0;
    vader_string_t l12 = 0;
    vader_string_t l13 = 0;
    bool t0, t1;
    void* t2 = NULL;
    vader_box_t t3 = vader_box_null();
    vader_string_t t4 = 0;
    vader_box_t* gc_roots[1] = { &t3 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l4, &t2 };
    vader_string_t* gc_atom_roots[5] = { &l10, &l11, &l12, &l13, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(26u, 0u, 0u, 576u);
    l4 = (void*) _a0_arr;
    l5 = INT64_C(0);
    l6 = vader_array_length(((vader_array_t*) l0));
    while ((l5 < l6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        t0 = ((uint8_t*) _a1_slotarr->buf->slots)[vader_array_offset(_a1_slotarr) + (size_t) l5];
        t1 = t0;
        if (t1) {
            l5 = (l5 + INT64_C(1));
            continue;
        }
        l7 = INT64_C(0);
        vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
        t2 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l5);
        l8 = vader_array_length(((vader_array_t*) t2));
        while ((l7 < l8)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
            t2 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l5);
            vader_array_t* _a4_slotarr = ((vader_array_t*) t2);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
            l9 = ((int64_t*) _a4_slotarr->buf->slots)[vader_array_offset(_a4_slotarr) + (size_t) l7];
            vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l9)
            t0 = ((uint8_t*) _a5_slotarr->buf->slots)[vader_array_offset(_a5_slotarr) + (size_t) l9];
            t1 = t0;
            if (!(t1)) {
                vader_array_t* _a6_slotarr = ((vader_array_t*) l0);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                t2 = vader_array_ref_load_obj(_a6_slotarr->buf, vader_array_offset(_a6_slotarr) + (size_t) l5);
                l10 = toolchain_stage$SourceSpec$Placed$stage_name(t2);
                vader_array_t* _a7_slotarr = ((vader_array_t*) l0);
                VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l9)
                t2 = vader_array_ref_load_obj(_a7_slotarr->buf, vader_array_offset(_a7_slotarr) + (size_t) l9);
                l11 = toolchain_stage$SourceSpec$Placed$stage_name(t2);
                vader_array_t* _a8_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l5)
                t2 = vader_array_ref_load_obj(_a8_slotarr->buf, vader_array_offset(_a8_slotarr) + (size_t) l5);
                vader_array_t* _a9_slotarr = ((vader_array_t*) t2);
                VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l7)
                t3 = vader_array_box_slots(_a9_slotarr->buf)[vader_array_offset(_a9_slotarr) + (size_t) l7];
                l12 = t3.payload.s;
                l13 = concat_7(1258u, l10, 1273u, l11, 1260u, l12, 377u);
                vader_array_push_scalar((vader_array_t*) l4, vader_box_string(576u, l13));
            }
            l7 = (l7 + INT64_C(1));
        }
        l5 = (l5 + INT64_C(1));
    }
    t4 = std_string$join(l4, 93u);
    { vader_string_t __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t toolchain_stage$waits__vader_emit_bytecode_BytecodeSpec(void* l0, void* l1, void* l2, void* l3) {
    void* l4 = NULL;
    int64_t l5, l6, l7, l8, l9;
    vader_string_t l10 = 0;
    vader_string_t l11 = 0;
    vader_string_t l12 = 0;
    vader_string_t l13 = 0;
    bool t0, t1;
    void* t2 = NULL;
    vader_box_t t3 = vader_box_null();
    vader_string_t t4 = 0;
    vader_box_t* gc_roots[1] = { &t3 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l4, &t2 };
    vader_string_t* gc_atom_roots[5] = { &l10, &l11, &l12, &l13, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(26u, 0u, 0u, 576u);
    l4 = (void*) _a0_arr;
    l5 = INT64_C(0);
    l6 = vader_array_length(((vader_array_t*) l0));
    while ((l5 < l6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        t0 = ((uint8_t*) _a1_slotarr->buf->slots)[vader_array_offset(_a1_slotarr) + (size_t) l5];
        t1 = t0;
        if (t1) {
            l5 = (l5 + INT64_C(1));
            continue;
        }
        l7 = INT64_C(0);
        vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
        t2 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l5);
        l8 = vader_array_length(((vader_array_t*) t2));
        while ((l7 < l8)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
            t2 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l5);
            vader_array_t* _a4_slotarr = ((vader_array_t*) t2);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
            l9 = ((int64_t*) _a4_slotarr->buf->slots)[vader_array_offset(_a4_slotarr) + (size_t) l7];
            vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l9)
            t0 = ((uint8_t*) _a5_slotarr->buf->slots)[vader_array_offset(_a5_slotarr) + (size_t) l9];
            t1 = t0;
            if (!(t1)) {
                vader_array_t* _a6_slotarr = ((vader_array_t*) l0);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                t2 = vader_array_ref_load_obj(_a6_slotarr->buf, vader_array_offset(_a6_slotarr) + (size_t) l5);
                l10 = vader_emit_bytecode$BytecodeSpec$toolchain_stage$Placed$stage_name(t2);
                vader_array_t* _a7_slotarr = ((vader_array_t*) l0);
                VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l9)
                t2 = vader_array_ref_load_obj(_a7_slotarr->buf, vader_array_offset(_a7_slotarr) + (size_t) l9);
                l11 = vader_emit_bytecode$BytecodeSpec$toolchain_stage$Placed$stage_name(t2);
                vader_array_t* _a8_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l5)
                t2 = vader_array_ref_load_obj(_a8_slotarr->buf, vader_array_offset(_a8_slotarr) + (size_t) l5);
                vader_array_t* _a9_slotarr = ((vader_array_t*) t2);
                VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l7)
                t3 = vader_array_box_slots(_a9_slotarr->buf)[vader_array_offset(_a9_slotarr) + (size_t) l7];
                l12 = t3.payload.s;
                l13 = concat_7(1258u, l10, 1273u, l11, 1260u, l12, 377u);
                vader_array_push_scalar((vader_array_t*) l4, vader_box_string(576u, l13));
            }
            l7 = (l7 + INT64_C(1));
        }
        l5 = (l5 + INT64_C(1));
    }
    t4 = std_string$join(l4, 93u);
    { vader_string_t __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t toolchain_stage$waits__vader_pipeline_check_CheckSpec(void* l0, void* l1, void* l2, void* l3) {
    void* l4 = NULL;
    int64_t l5, l6, l7, l8, l9;
    vader_string_t l10 = 0;
    vader_string_t l11 = 0;
    vader_string_t l12 = 0;
    vader_string_t l13 = 0;
    bool t0, t1;
    void* t2 = NULL;
    vader_box_t t3 = vader_box_null();
    vader_string_t t4 = 0;
    vader_box_t* gc_roots[1] = { &t3 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l4, &t2 };
    vader_string_t* gc_atom_roots[5] = { &l10, &l11, &l12, &l13, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(26u, 0u, 0u, 576u);
    l4 = (void*) _a0_arr;
    l5 = INT64_C(0);
    l6 = vader_array_length(((vader_array_t*) l0));
    while ((l5 < l6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        t0 = ((uint8_t*) _a1_slotarr->buf->slots)[vader_array_offset(_a1_slotarr) + (size_t) l5];
        t1 = t0;
        if (t1) {
            l5 = (l5 + INT64_C(1));
            continue;
        }
        l7 = INT64_C(0);
        vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
        t2 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l5);
        l8 = vader_array_length(((vader_array_t*) t2));
        while ((l7 < l8)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
            t2 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l5);
            vader_array_t* _a4_slotarr = ((vader_array_t*) t2);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
            l9 = ((int64_t*) _a4_slotarr->buf->slots)[vader_array_offset(_a4_slotarr) + (size_t) l7];
            vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l9)
            t0 = ((uint8_t*) _a5_slotarr->buf->slots)[vader_array_offset(_a5_slotarr) + (size_t) l9];
            t1 = t0;
            if (!(t1)) {
                vader_array_t* _a6_slotarr = ((vader_array_t*) l0);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                t2 = vader_array_ref_load_obj(_a6_slotarr->buf, vader_array_offset(_a6_slotarr) + (size_t) l5);
                l10 = vader_pipeline_check$CheckSpec$toolchain_stage$Placed$stage_name(t2);
                vader_array_t* _a7_slotarr = ((vader_array_t*) l0);
                VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l9)
                t2 = vader_array_ref_load_obj(_a7_slotarr->buf, vader_array_offset(_a7_slotarr) + (size_t) l9);
                l11 = vader_pipeline_check$CheckSpec$toolchain_stage$Placed$stage_name(t2);
                vader_array_t* _a8_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l5)
                t2 = vader_array_ref_load_obj(_a8_slotarr->buf, vader_array_offset(_a8_slotarr) + (size_t) l5);
                vader_array_t* _a9_slotarr = ((vader_array_t*) t2);
                VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l7)
                t3 = vader_array_box_slots(_a9_slotarr->buf)[vader_array_offset(_a9_slotarr) + (size_t) l7];
                l12 = t3.payload.s;
                l13 = concat_7(1258u, l10, 1273u, l11, 1260u, l12, 377u);
                vader_array_push_scalar((vader_array_t*) l4, vader_box_string(576u, l13));
            }
            l7 = (l7 + INT64_C(1));
        }
        l5 = (l5 + INT64_C(1));
    }
    t4 = std_string$join(l4, 93u);
    { vader_string_t __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
}
