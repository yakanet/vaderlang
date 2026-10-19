#include "bootstrap.split.h"

static void* vader_fixpoint_components_bottom_up(void* l0);
static void vader_fixpoint_enter(void* l0, int32_t l1);
static bool vader_fixpoint_is_cycle(void* l0, void* l1);
static void* vader_fixpoint_pop_component(void* l0, int32_t l1);
static void* vader_fixpoint_reachability_step(void* l0, void* l1);
static bool vader_fixpoint_sweep_until_settled(void* l0, void* l1, int32_t l2);

void* vader_fixpoint_component_of_each_node(void* l0) {
    int64_t l1, l4, l6, l7;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l5 = NULL;
    int32_t l8, l9;
    size_t t0;
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_vader_fixpoint_Graph_t*) l0)->f_successors)->length;
    l1 = (int64_t) (size_t) t0;
    l2 = (void*) &vader_fn_static___lambda_vader_fixpoint_0;
    l2 = std_core_filled__i32(l1, l2);
    l3 = vader_fixpoint_components_bottom_up(l0);
    l1 = INT64_C(0);
    t0 = ((vader_array_t*) l3)->length;
    l4 = (int64_t) (size_t) t0;
    while ((l1 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
        t0 = ((vader_array_t*) l5)->length;
        l6 = (int64_t) (size_t) t0;
        l7 = INT64_C(0);
        while ((l7 < l6)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            l8 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l7];
            l9 = ((int32_t) (int64_t) l1);
            vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l8)
            ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l8] = (int32_t) l9;
            l7 = (l7 + INT64_C(1));
        }
        l1 = (l1 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_fixpoint_components_bottom_up(void* l0) {
    int64_t l1, l8, l10, l12, l13, l14;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l21 = NULL;
    void* l28 = NULL;
    int32_t l9, l11, l15, l16, l17, l18, l20, l22, l23, l24, l25, l26, l27;
    vader_box_t l19 = vader_box_null();
    size_t t0;
    void* t1 = NULL;
    int32_t t2;
    vader_box_t t3 = vader_box_null();
    bool t4;
    vader_box_t* gc_roots[2] = { &l19, &t3 };
    void** gc_raw_roots[10] = { &l0, &l2, &l3, &l4, &l5, &l6, &l7, &l21, &l28, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 10u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_vader_fixpoint_Graph_t*) l0)->f_successors)->length;
    l1 = (int64_t) (size_t) t0;
    vader_array_t* _a0_arr = vader_array_new(15u, 1u, 7u, 288u);
    ((int32_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int32_t) INT32_C(-1);
    t1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) l1);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(15u, 1u, 7u, 288u);
    ((int32_t*) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = (int32_t) INT32_C(0);
    t1 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) l1);
    l3 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(12u, 1u, 12u, 283u);
    ((uint8_t*) _a4_arr->buf->slots)[_a4_arr->offset + 0u] = (uint8_t) false;
    t1 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) l1);
    l4 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(15u, 0u, 7u, 288u);
    l5 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(15u, 0u, 7u, 288u);
    l6 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(16u, 0u, 8u, 289u);
    l7 = (void*) _a8_arr;
    vader_struct_vader_fixpoint_TarjanWalk_t* _a9_obj = (vader_struct_vader_fixpoint_TarjanWalk_t*) vader_gc_alloc(sizeof(vader_struct_vader_fixpoint_TarjanWalk_t));
    vader_obj_header_init(_a9_obj, 935u);
    _a9_obj->f_order = l2;
    _a9_obj->f_low = l3;
    _a9_obj->f_on_stack = l4;
    _a9_obj->f_stack = l5;
    _a9_obj->f_frame_nodes = l6;
    _a9_obj->f_frame_tried = l7;
    _a9_obj->f_next_rank = INT32_C(0);
    l2 = (void*) _a9_obj;
    vader_array_t* _a10_arr = vader_array_new(2u, 0u, 13u, 15u);
    l3 = (void*) _a10_arr;
    l8 = INT64_C(0);
    while ((l8 < l1)) {
        vader_array_t* _a11_slotarr = ((vader_array_t*) ((vader_struct_vader_fixpoint_TarjanWalk_t*) l2)->f_order);
        VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l8)
        t2 = ((int32_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l8];
        if (t2 != INT32_C(-1)) {
            l8 = (l8 + INT64_C(1));
            continue;
        }
        l9 = ((int32_t) (int64_t) l8);
        vader_fixpoint_enter(l2, l9);
        for (;;) {
            t0 = ((vader_array_t*) ((vader_struct_vader_fixpoint_TarjanWalk_t*) l2)->f_frame_nodes)->length;
            if ((t0 > INT64_C(0))) {
                t0 = ((vader_array_t*) ((vader_struct_vader_fixpoint_TarjanWalk_t*) l2)->f_frame_nodes)->length;
                l10 = vader_chk_sub(i64, t0, INT64_C(1));
                vader_array_t* _a12_slotarr = ((vader_array_t*) ((vader_struct_vader_fixpoint_TarjanWalk_t*) l2)->f_frame_nodes);
                VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l10)
                l11 = ((int32_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l10];
                vader_array_t* _a13_slotarr = ((vader_array_t*) ((vader_struct_vader_fixpoint_Graph_t*) l0)->f_successors);
                VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l11)
                l4 = vader_array_ref_load_obj(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l11);
                vader_array_t* _a14_slotarr = ((vader_array_t*) ((vader_struct_vader_fixpoint_TarjanWalk_t*) l2)->f_frame_tried);
                VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l10)
                l12 = ((int64_t*) _a14_slotarr->buf->slots)[_a14_slotarr->offset + (size_t) l10];
                t0 = ((vader_array_t*) l4)->length;
                l13 = (int64_t) (size_t) t0;
                if ((l12 < l13)) {
                    l5 = ((vader_struct_vader_fixpoint_TarjanWalk_t*) l2)->f_frame_tried;
                    l14 = vader_chk_add(i64, l12, INT64_C(1));
                    vader_array_t* _a15_slotarr = ((vader_array_t*) l5);
                    VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l10)
                    ((int64_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l10] = (int64_t) l14;
                    vader_array_t* _a16_slotarr = ((vader_array_t*) l4);
                    VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l12)
                    l15 = ((int32_t*) _a16_slotarr->buf->slots)[_a16_slotarr->offset + (size_t) l12];
                    vader_array_t* _a17_slotarr = ((vader_array_t*) ((vader_struct_vader_fixpoint_TarjanWalk_t*) l2)->f_order);
                    VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l15)
                    t2 = ((int32_t*) _a17_slotarr->buf->slots)[_a17_slotarr->offset + (size_t) l15];
                    if (t2 == INT32_C(-1)) {
                        vader_fixpoint_enter(l2, l15);
                        continue;
                    }
                    vader_array_t* _a18_slotarr = ((vader_array_t*) ((vader_struct_vader_fixpoint_TarjanWalk_t*) l2)->f_on_stack);
                    VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a18_slotarr, l15)
                    t3 = vader_box_bool(283u, ((uint8_t*) _a18_slotarr->buf->slots)[_a18_slotarr->offset + (size_t) l15]);
                    t4 = t3.payload.b;
                    if (t4) {
                        l6 = ((vader_struct_vader_fixpoint_TarjanWalk_t*) l2)->f_low;
                        vader_array_t* _a19_slotarr = ((vader_array_t*) ((vader_struct_vader_fixpoint_TarjanWalk_t*) l2)->f_low);
                        VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l11)
                        l16 = ((int32_t*) _a19_slotarr->buf->slots)[_a19_slotarr->offset + (size_t) l11];
                        vader_array_t* _a20_slotarr = ((vader_array_t*) ((vader_struct_vader_fixpoint_TarjanWalk_t*) l2)->f_order);
                        VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a20_slotarr, l15)
                        l17 = ((int32_t*) _a20_slotarr->buf->slots)[_a20_slotarr->offset + (size_t) l15];
                        l18 = std_math_min_1(l16, l17);
                        vader_array_t* _a21_slotarr = ((vader_array_t*) l6);
                        VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l11)
                        ((int32_t*) _a21_slotarr->buf->slots)[_a21_slotarr->offset + (size_t) l11] = (int32_t) l18;
                    }
                    continue;
                }
                t3 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_fixpoint_TarjanWalk_t*) l2)->f_frame_nodes);
                t3 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_fixpoint_TarjanWalk_t*) l2)->f_frame_tried);
                l19 = std_iter_last__i32(((vader_struct_vader_fixpoint_TarjanWalk_t*) l2)->f_frame_nodes);
                if (!(l19.tag == 0u)) {
                    l7 = ((vader_struct_vader_fixpoint_TarjanWalk_t*) l2)->f_low;
                    l20 = ((int32_t) l19.payload.i);
                    l21 = ((vader_struct_vader_fixpoint_TarjanWalk_t*) l2)->f_low;
                    l22 = ((int32_t) l19.payload.i);
                    vader_array_t* _a22_slotarr = ((vader_array_t*) l21);
                    VADER_ARRAY_RESOLVE_BUF(_a22_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a22_slotarr, l22)
                    l23 = ((int32_t*) _a22_slotarr->buf->slots)[_a22_slotarr->offset + (size_t) l22];
                    vader_array_t* _a23_slotarr = ((vader_array_t*) ((vader_struct_vader_fixpoint_TarjanWalk_t*) l2)->f_low);
                    VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a23_slotarr, l11)
                    l24 = ((int32_t*) _a23_slotarr->buf->slots)[_a23_slotarr->offset + (size_t) l11];
                    l25 = std_math_min_1(l23, l24);
                    vader_array_t* _a24_slotarr = ((vader_array_t*) l7);
                    VADER_ARRAY_RESOLVE_BUF(_a24_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a24_slotarr, l20)
                    ((int32_t*) _a24_slotarr->buf->slots)[_a24_slotarr->offset + (size_t) l20] = (int32_t) l25;
                }
                vader_array_t* _a25_slotarr = ((vader_array_t*) ((vader_struct_vader_fixpoint_TarjanWalk_t*) l2)->f_low);
                VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a25_slotarr, l11)
                l26 = ((int32_t*) _a25_slotarr->buf->slots)[_a25_slotarr->offset + (size_t) l11];
                vader_array_t* _a26_slotarr = ((vader_array_t*) ((vader_struct_vader_fixpoint_TarjanWalk_t*) l2)->f_order);
                VADER_ARRAY_RESOLVE_BUF(_a26_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a26_slotarr, l11)
                l27 = ((int32_t*) _a26_slotarr->buf->slots)[_a26_slotarr->offset + (size_t) l11];
                if (!(l26 == l27)) {
                    continue;
                }
                l28 = vader_fixpoint_pop_component(l2, l11);
                vader_array_push((vader_array_t*) l3, vader_ref_box(l28));
                continue;
            }
            break;
        }
        l8 = (l8 + INT64_C(1));
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_fixpoint_enter(void* l0, int32_t l1) {
    void* l2 = NULL;
    int32_t l3;
    int32_t t0;
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_fixpoint_TarjanWalk_t*) l0)->f_order;
    l3 = ((vader_struct_vader_fixpoint_TarjanWalk_t*) l0)->f_next_rank;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1] = (int32_t) l3;
    l2 = ((vader_struct_vader_fixpoint_TarjanWalk_t*) l0)->f_low;
    l3 = ((vader_struct_vader_fixpoint_TarjanWalk_t*) l0)->f_next_rank;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
    ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l1] = (int32_t) l3;
    t0 = ((vader_struct_vader_fixpoint_TarjanWalk_t*) l0)->f_next_rank;
    l3 = vader_chk_add(i32, t0, INT32_C(1));
    ((vader_struct_vader_fixpoint_TarjanWalk_t*) l0)->f_next_rank = l3;
    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_fixpoint_TarjanWalk_t*) l0)->f_on_stack);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l1)
    ((uint8_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l1] = (uint8_t) true;
    vader_array_push_i32((vader_array_t*) ((vader_struct_vader_fixpoint_TarjanWalk_t*) l0)->f_stack, l1);
    vader_array_push_i32((vader_array_t*) ((vader_struct_vader_fixpoint_TarjanWalk_t*) l0)->f_frame_nodes, l1);
    vader_array_push_i64((vader_array_t*) ((vader_struct_vader_fixpoint_TarjanWalk_t*) l0)->f_frame_tried, INT64_C(0));
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_fixpoint_is_cycle(void* l0, void* l1) {
    int32_t l2, l4;
    void* l3;
    size_t t0;
    void* t1;
    bool t2;
    t0 = ((vader_array_t*) l1)->length;
    if ((t0 > INT64_C(1))) {
        return true;
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
    l2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) INT32_C(0)];
    l3 = ((vader_struct_vader_fixpoint_Graph_t*) l0)->f_successors;
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
    l4 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) INT32_C(0)];
    vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
    t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
    t2 = std_core____Contains_contains__i32(t1, l2);
    return t2;
}

static void* vader_fixpoint_pop_component(void* l0, int32_t l1) {
    void* l2 = NULL;
    int32_t l3;
    vader_box_t l4 = vader_box_null();
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 288u);
    l2 = (void*) _a0_arr;
    for (;;) {
        l4 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_fixpoint_TarjanWalk_t*) l0)->f_stack);
        if (!(l4.tag == 0u)) {
            l3 = ((int32_t) l4.payload.i);
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_fixpoint_TarjanWalk_t*) l0)->f_on_stack);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            ((uint8_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3] = (uint8_t) false;
            vader_array_push_i32((vader_array_t*) l2, l3);
            if (!(l3 == l1)) {
                continue;
            }
            { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
        }
        break;
    }
    vader_host_std_abort_panic(2454u);
    vader_unreachable("a no-return call returned");
    vader_gc_top = gc_frame.prev;
}

static void* vader_fixpoint_reachability_step(void* l0, void* l1) {
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct___lambda_env_vader_fixpoint_2_t* _a0_obj = (vader_struct___lambda_env_vader_fixpoint_2_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_fixpoint_2_t));
    vader_obj_header_init(_a0_obj, 325u);
    _a0_obj->f_cap_0 = l1;
    _a0_obj->f_cap_1 = l0;
    t0 = (void*) _a0_obj;
    vader_fn_t* _a1_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a1_closure, 258u);
    _a1_closure->code = (void*) &vader_fn_lift___lambda_vader_fixpoint_1;
    _a1_closure->env = t0;
    t0 = (void*) _a1_closure;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_fixpoint_solve_bottom_up(void* l0, void* l1, int32_t l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l7 = NULL;
    int64_t l5, l6;
    size_t t0;
    bool t1;
    int32_t t2;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t3 };
    void** gc_raw_roots[5] = { &l0, &l1, &l3, &l4, &l7 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 288u);
    l3 = (void*) _a0_arr;
    l4 = vader_fixpoint_components_bottom_up(l0);
    t0 = ((vader_array_t*) l4)->length;
    l5 = (int64_t) (size_t) t0;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        l7 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
        t1 = vader_fixpoint_is_cycle(l0, l7);
        if (t1) {
            t1 = vader_fixpoint_sweep_until_settled(l7, l1, l2);
            if (!(t1)) {
                vader_array_push_all((vader_array_t*) l3, (vader_array_t*) l7);
            }
            l6 = (l6 + INT64_C(1));
            continue;
        }
        vader_array_t* _a2_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(0))
        t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) INT32_C(0)];
        vader_fn_t* _a3_fnobj = (vader_fn_t*) l1;
        t3 = ((vader_fn_erased_sig_1_t) _a3_fnobj->code)(_a3_fnobj->env, vader_box_i32(288u, t2));
        t1 = t3.payload.b;
        l6 = (l6 + INT64_C(1));
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

void vader_fixpoint_solve_reachability(void* l0, void* l1) {
    int32_t l2;
    void* l3 = NULL;
    int64_t l4, l5;
    size_t t0;
    void** gc_raw_roots[3] = { &l0, &l1, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_vader_fixpoint_Graph_t*) l0)->f_successors)->length;
    l2 = vader_chk_add(i32, ((int32_t) (size_t) t0), INT32_C(1));
    l3 = vader_fixpoint_reachability_step(l0, l1);
    l3 = vader_fixpoint_solve_bottom_up(l0, l3, l2);
    t0 = ((vader_array_t*) l3)->length;
    l4 = (int64_t) (size_t) t0;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l5];
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
        ((uint8_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l2] = (uint8_t) true;
        l5 = (l5 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_fixpoint_sweep_until_settled(void* l0, void* l1, int32_t l2) {
    int32_t l3;
    bool l4;
    void* l5 = NULL;
    int64_t l6, l7;
    size_t t0;
    int32_t t1;
    vader_box_t t2 = vader_box_null();
    bool t3;
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[3] = { &l0, &l1, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = INT32_C(0);
    while ((l3 < l2)) {
        l4 = false;
        l5 = l0;
        t0 = ((vader_array_t*) l5)->length;
        l6 = (int64_t) (size_t) t0;
        l7 = INT64_C(0);
        while ((l7 < l6)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l7)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l7];
            vader_fn_t* _a1_fnobj = (vader_fn_t*) l1;
            t2 = ((vader_fn_erased_sig_1_t) _a1_fnobj->code)(_a1_fnobj->env, vader_box_i32(288u, t1));
            t3 = t2.payload.b;
            if (t3) {
                l4 = true;
            }
            l7 = (l7 + INT64_C(1));
        }
        if (!(l4)) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        l3 = (l3 + INT32_C(1));
    }
    { vader_gc_top = gc_frame.prev; return false; }
}
