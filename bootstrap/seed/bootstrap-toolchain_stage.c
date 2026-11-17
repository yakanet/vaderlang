#include "bootstrap.split.h"

static vader_box_t toolchain_stage$first_free(void* l0, void* l1);
static vader_box_t toolchain_stage$plan_order__vader_emit_bytecode_BytecodeSpec(void* l0);
static vader_box_t toolchain_stage$plan_order__vader_front_resolver_SourceSpec(void* l0);
static vader_box_t toolchain_stage$plan_order__vader_pipeline_check_CheckSpec(void* l0);
static vader_string_t toolchain_stage$waits__vader_emit_bytecode_BytecodeSpec(void* l0, void* l1, void* l2, void* l3);
static vader_string_t toolchain_stage$waits__vader_front_resolver_SourceSpec(void* l0, void* l1, void* l2, void* l3);
static vader_string_t toolchain_stage$waits__vader_pipeline_check_CheckSpec(void* l0, void* l1, void* l2, void* l3);

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
            vader_obj_header_init(_a2_obj, 572u);
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
                { vader_box_t __vret = vader_box_i64(540u, l2); vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
        l2 = (l2 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t toolchain_stage$plan_order__vader_emit_bytecode_BytecodeSpec(void* l0) {
    int64_t l1, l4, l5;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    vader_string_t l8 = 0;
    vader_box_t l9 = vader_box_null();
    void* t0 = NULL;
    int64_t t1;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[1] = { &l9 };
    void** gc_raw_roots[6] = { &l0, &l2, &l3, &l6, &l7, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l8, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_array_length(((vader_array_t*) l0));
    l2 = (void*) &vader_fn_static___lambda_toolchain_stage_2;
    l2 = std_core$filled__i64__(l1, l2);
    l3 = (void*) &vader_fn_static___lambda_toolchain_stage_3;
    l3 = std_core$filled__string__(l1, l3);
    l4 = INT64_C(0);
    while ((l4 < l1)) {
        l5 = INT64_C(0);
        while ((l5 < l1)) {
            if (l4 == l5) {
                l5 = (l5 + INT64_C(1));
                continue;
            }
            vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
            l6 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
            l7 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l4);
            l8 = vader_emit_bytecode$BytecodeSpec$toolchain_stage$Placed$precedes(l6, l7);
            if (l8 != 0u) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t0 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l4);
                vader_array_push_i64((vader_array_t*) t0, l5);
                vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                t0 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l4);
                vader_array_push_scalar((vader_array_t*) t0, vader_box_string(536u, l8));
            }
            l5 = (l5 + INT64_C(1));
        }
        l4 = (l4 + INT64_C(1));
    }
    vader_array_t* _a3_arr = vader_array_new(28u, 0u, 8u, 540u);
    l6 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(24u, 1u, 12u, 534u);
    ((uint8_t*) _a4_arr->buf->slots)[vader_array_offset(_a4_arr) + 0u] = (uint8_t) false;
    t0 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l1);
    l7 = (void*) _a5_arr;
    for (;;) {
        t1 = vader_array_length(((vader_array_t*) l6));
        if ((t1 < l1)) {
            l9 = toolchain_stage$first_free(l2, l7);
            if (l9.tag == 0u) {
                l8 = toolchain_stage$waits__vader_emit_bytecode_BytecodeSpec(l0, l2, l3, l7);
                t2 = concat_2(2717u, l8);
                vader_struct_toolchain_stage$PlanError_t* _a6_obj = (vader_struct_toolchain_stage$PlanError_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_stage$PlanError_t));
                vader_obj_header_init(_a6_obj, 1077u);
                _a6_obj->f_message = t2;
                t0 = (void*) _a6_obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l4 = ((int64_t) l9.payload.i);
            vader_array_t* _a7_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l4)
            ((uint8_t*) _a7_slotarr->buf->slots)[vader_array_offset(_a7_slotarr) + (size_t) l4] = (uint8_t) true;
            vader_array_push_i64((vader_array_t*) l6, l4);
            continue;
        }
        break;
    }
    { vader_box_t __vret = vader_ref_box(l6); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t toolchain_stage$plan_order__vader_front_resolver_SourceSpec(void* l0) {
    int64_t l1, l4, l5;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    vader_string_t l8 = 0;
    vader_box_t l9 = vader_box_null();
    void* t0 = NULL;
    int64_t t1;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[1] = { &l9 };
    void** gc_raw_roots[6] = { &l0, &l2, &l3, &l6, &l7, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l8, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_array_length(((vader_array_t*) l0));
    l2 = (void*) &vader_fn_static___lambda_toolchain_stage_4;
    l2 = std_core$filled__i64__(l1, l2);
    l3 = (void*) &vader_fn_static___lambda_toolchain_stage_5;
    l3 = std_core$filled__string__(l1, l3);
    l4 = INT64_C(0);
    while ((l4 < l1)) {
        l5 = INT64_C(0);
        while ((l5 < l1)) {
            if (l4 == l5) {
                l5 = (l5 + INT64_C(1));
                continue;
            }
            vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
            l6 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
            l7 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l4);
            l8 = vader_front_resolver$SourceSpec$toolchain_stage$Placed$precedes(l6, l7);
            if (l8 != 0u) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t0 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l4);
                vader_array_push_i64((vader_array_t*) t0, l5);
                vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                t0 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l4);
                vader_array_push_scalar((vader_array_t*) t0, vader_box_string(536u, l8));
            }
            l5 = (l5 + INT64_C(1));
        }
        l4 = (l4 + INT64_C(1));
    }
    vader_array_t* _a3_arr = vader_array_new(28u, 0u, 8u, 540u);
    l6 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(24u, 1u, 12u, 534u);
    ((uint8_t*) _a4_arr->buf->slots)[vader_array_offset(_a4_arr) + 0u] = (uint8_t) false;
    t0 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l1);
    l7 = (void*) _a5_arr;
    for (;;) {
        t1 = vader_array_length(((vader_array_t*) l6));
        if ((t1 < l1)) {
            l9 = toolchain_stage$first_free(l2, l7);
            if (l9.tag == 0u) {
                l8 = toolchain_stage$waits__vader_front_resolver_SourceSpec(l0, l2, l3, l7);
                t2 = concat_2(2717u, l8);
                vader_struct_toolchain_stage$PlanError_t* _a6_obj = (vader_struct_toolchain_stage$PlanError_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_stage$PlanError_t));
                vader_obj_header_init(_a6_obj, 1077u);
                _a6_obj->f_message = t2;
                t0 = (void*) _a6_obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l4 = ((int64_t) l9.payload.i);
            vader_array_t* _a7_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l4)
            ((uint8_t*) _a7_slotarr->buf->slots)[vader_array_offset(_a7_slotarr) + (size_t) l4] = (uint8_t) true;
            vader_array_push_i64((vader_array_t*) l6, l4);
            continue;
        }
        break;
    }
    { vader_box_t __vret = vader_ref_box(l6); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t toolchain_stage$plan_order__vader_pipeline_check_CheckSpec(void* l0) {
    int64_t l1, l4, l5;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    vader_string_t l8 = 0;
    vader_box_t l9 = vader_box_null();
    void* t0 = NULL;
    int64_t t1;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[1] = { &l9 };
    void** gc_raw_roots[6] = { &l0, &l2, &l3, &l6, &l7, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l8, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_array_length(((vader_array_t*) l0));
    l2 = (void*) &vader_fn_static___lambda_toolchain_stage_0;
    l2 = std_core$filled__i64__(l1, l2);
    l3 = (void*) &vader_fn_static___lambda_toolchain_stage_1;
    l3 = std_core$filled__string__(l1, l3);
    l4 = INT64_C(0);
    while ((l4 < l1)) {
        l5 = INT64_C(0);
        while ((l5 < l1)) {
            if (l4 == l5) {
                l5 = (l5 + INT64_C(1));
                continue;
            }
            vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
            l6 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
            l7 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l4);
            l8 = vader_pipeline_check$CheckSpec$toolchain_stage$Placed$precedes(l6, l7);
            if (l8 != 0u) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                t0 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l4);
                vader_array_push_i64((vader_array_t*) t0, l5);
                vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                t0 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l4);
                vader_array_push_scalar((vader_array_t*) t0, vader_box_string(536u, l8));
            }
            l5 = (l5 + INT64_C(1));
        }
        l4 = (l4 + INT64_C(1));
    }
    vader_array_t* _a3_arr = vader_array_new(28u, 0u, 8u, 540u);
    l6 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(24u, 1u, 12u, 534u);
    ((uint8_t*) _a4_arr->buf->slots)[vader_array_offset(_a4_arr) + 0u] = (uint8_t) false;
    t0 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l1);
    l7 = (void*) _a5_arr;
    for (;;) {
        t1 = vader_array_length(((vader_array_t*) l6));
        if ((t1 < l1)) {
            l9 = toolchain_stage$first_free(l2, l7);
            if (l9.tag == 0u) {
                l8 = toolchain_stage$waits__vader_pipeline_check_CheckSpec(l0, l2, l3, l7);
                t2 = concat_2(2717u, l8);
                vader_struct_toolchain_stage$PlanError_t* _a6_obj = (vader_struct_toolchain_stage$PlanError_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_stage$PlanError_t));
                vader_obj_header_init(_a6_obj, 1077u);
                _a6_obj->f_message = t2;
                t0 = (void*) _a6_obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l4 = ((int64_t) l9.payload.i);
            vader_array_t* _a7_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l4)
            ((uint8_t*) _a7_slotarr->buf->slots)[vader_array_offset(_a7_slotarr) + (size_t) l4] = (uint8_t) true;
            vader_array_push_i64((vader_array_t*) l6, l4);
            continue;
        }
        break;
    }
    { vader_box_t __vret = vader_ref_box(l6); vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_array_t* _a0_arr = vader_array_reserve(217u, (int64_t) t0, 13u, 1288u);
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
    if (l6.tag == 1077u) {
        t3 = l7.payload.obj;
        { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = l6.payload.obj;
    t0 = vader_array_length(((vader_array_t*) l1));
    vader_array_t* _a2_arr = vader_array_reserve(34u, (int64_t) t0, 0u, 550u);
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

vader_box_t toolchain_stage$plan_stages__vader_front_resolver_Sources__vader_front_resolver_Generated__vader_front_resolver_SourceSpec(void* l0) {
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
    vader_array_t* _a0_arr = vader_array_reserve(300u, (int64_t) t0, 13u, 1501u);
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
    l6 = toolchain_stage$plan_order__vader_front_resolver_SourceSpec(l1);
    l7 = l6;
    if (l6.tag == 1077u) {
        t3 = l7.payload.obj;
        { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = l6.payload.obj;
    t0 = vader_array_length(((vader_array_t*) l1));
    vader_array_t* _a2_arr = vader_array_reserve(34u, (int64_t) t0, 0u, 550u);
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
    vader_array_t* _a0_arr = vader_array_reserve(385u, (int64_t) t0, 13u, 1803u);
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
    if (l6.tag == 1077u) {
        t3 = l7.payload.obj;
        { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = l6.payload.obj;
    t0 = vader_array_length(((vader_array_t*) l1));
    vader_array_t* _a2_arr = vader_array_reserve(34u, (int64_t) t0, 0u, 550u);
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
    vader_array_t* _a0_arr = vader_array_new(26u, 0u, 0u, 536u);
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
                l13 = concat_7(1213u, l10, 1227u, l11, 1215u, l12, 362u);
                vader_array_push_scalar((vader_array_t*) l4, vader_box_string(536u, l13));
            }
            l7 = (l7 + INT64_C(1));
        }
        l5 = (l5 + INT64_C(1));
    }
    t4 = std_string$join(l4, 89u);
    { vader_string_t __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t toolchain_stage$waits__vader_front_resolver_SourceSpec(void* l0, void* l1, void* l2, void* l3) {
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
    vader_array_t* _a0_arr = vader_array_new(26u, 0u, 0u, 536u);
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
                l10 = vader_front_resolver$SourceSpec$toolchain_stage$Placed$stage_name(t2);
                vader_array_t* _a7_slotarr = ((vader_array_t*) l0);
                VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l9)
                t2 = vader_array_ref_load_obj(_a7_slotarr->buf, vader_array_offset(_a7_slotarr) + (size_t) l9);
                l11 = vader_front_resolver$SourceSpec$toolchain_stage$Placed$stage_name(t2);
                vader_array_t* _a8_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l5)
                t2 = vader_array_ref_load_obj(_a8_slotarr->buf, vader_array_offset(_a8_slotarr) + (size_t) l5);
                vader_array_t* _a9_slotarr = ((vader_array_t*) t2);
                VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l7)
                t3 = vader_array_box_slots(_a9_slotarr->buf)[vader_array_offset(_a9_slotarr) + (size_t) l7];
                l12 = t3.payload.s;
                l13 = concat_7(1213u, l10, 1227u, l11, 1215u, l12, 362u);
                vader_array_push_scalar((vader_array_t*) l4, vader_box_string(536u, l13));
            }
            l7 = (l7 + INT64_C(1));
        }
        l5 = (l5 + INT64_C(1));
    }
    t4 = std_string$join(l4, 89u);
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
    vader_array_t* _a0_arr = vader_array_new(26u, 0u, 0u, 536u);
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
                l13 = concat_7(1213u, l10, 1227u, l11, 1215u, l12, 362u);
                vader_array_push_scalar((vader_array_t*) l4, vader_box_string(536u, l13));
            }
            l7 = (l7 + INT64_C(1));
        }
        l5 = (l5 + INT64_C(1));
    }
    t4 = std_string$join(l4, 89u);
    { vader_string_t __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
}
