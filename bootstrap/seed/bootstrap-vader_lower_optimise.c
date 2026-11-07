#include "bootstrap.split.h"

static void vader_lower_optimise$analyze_block(void* l0, void* l1);
static void vader_lower_optimise$analyze_expr(vader_box_t l0, void* l1);
static void vader_lower_optimise$analyze_stmt(vader_box_t l0, void* l1);
static bool vader_lower_optimise$any_expr_may_disturb(void* l0, void* l1);
static bool vader_lower_optimise$block_may_disturb(void* l0, void* l1);
static bool vader_lower_optimise$call_may_disturb(void* l0, void* l1);
static vader_box_t vader_lower_optimise$count_between(vader_box_t l0, vader_box_t l1, void* l2);
static vader_box_t vader_lower_optimise$count_lit(int64_t l0, void* l1);
static vader_box_t vader_lower_optimise$counted_loop_in(vader_box_t l0, void* l1);
static vader_box_t vader_lower_optimise$counted_loop_of(vader_box_t l0);
static vader_box_t vader_lower_optimise$defining_let(void* l0, void* l1);
static void vader_lower_optimise$devirt_body(void* l0);
static bool vader_lower_optimise$expr_may_disturb(void* l0, vader_box_t l1);
static bool vader_lower_optimise$fields_may_disturb(void* l0, void* l1);
static bool vader_lower_optimise$has_top_level_push(void* l0, void* l1);
static vader_box_t vader_lower_optimise$hoisted(vader_box_t l0, void* l1);
static vader_box_t vader_lower_optimise$indexed_decl(void* l0, void* l1);
static bool vader_lower_optimise$is_empty_array_lit(vader_box_t l0);
static bool vader_lower_optimise$is_fresh_array(vader_box_t l0);
static bool vader_lower_optimise$is_int_lit(vader_box_t l0, int64_t l1);
static bool vader_lower_optimise$is_pure_fn(void* l0, void* l1);
static bool vader_lower_optimise$is_push_onto(vader_box_t l0, void* l1);
static bool vader_lower_optimise$names_local(vader_box_t l0, void* l1);
static bool vader_lower_optimise$never_negative(vader_box_t l0);
static void* vader_lower_optimise$new_purity_ctx(void* l0);
static bool vader_lower_optimise$opt_block_may_disturb(void* l0, vader_box_t l1);
static bool vader_lower_optimise$opt_expr_may_disturb(void* l0, vader_box_t l1);
static bool vader_lower_optimise$pc_body_may_disturb(void* l0, void* l1, int32_t l2);
static void vader_lower_optimise$pc_collect_in_expr(vader_box_t l0, void* l1);
static void vader_lower_optimise$pc_collect_in_stmt(vader_box_t l0, void* l1);
static void vader_lower_optimise$pc_collect_pushes(void* l0, void* l1);
static bool vader_lower_optimise$pc_expr_may_disturb_skipping_push(void* l0, vader_box_t l1, int32_t l2);
static bool vader_lower_optimise$pc_has_extra_exit(void* l0);
static void* vader_lower_optimise$pc_live_entering(void* l0, void* l1);
static void vader_lower_optimise$pc_scan_block(void* l0, void* l1, void* l2);
static void vader_lower_optimise$pc_scan_expr(void* l0, vader_box_t l1, void* l2);
static void vader_lower_optimise$pc_scan_stmt(void* l0, vader_box_t l1, void* l2);
static vader_box_t vader_lower_optimise$pc_single_target(void* l0);
static bool vader_lower_optimise$pc_stmt_may_disturb(void* l0, vader_box_t l1, int32_t l2);
static void vader_lower_optimise$pc_try_cache(void* l0, void* l1, void* l2);
static void vader_lower_optimise$pc_update_live(void* l0, vader_box_t l1);
static bool vader_lower_optimise$pc_used_outside_push(void* l0, int32_t l1);
static bool vader_lower_optimise$reads_local(vader_box_t l0, void* l1);
static void vader_lower_optimise$rewrite_block(void* l0, void* l1);
static void vader_lower_optimise$rewrite_expr(vader_box_t l0, void* l1);
static void vader_lower_optimise$rewrite_stmt(vader_box_t l0, void* l1);
static bool vader_lower_optimise$runs_every_turn(void* l0);
static bool vader_lower_optimise$stmt_may_disturb(void* l0, vader_box_t l1);
static vader_box_t vader_lower_optimise$trip_count(void* l0, void* l1);

static void vader_lower_optimise$analyze_block(void* l0, void* l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l5, &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_lower_ir$LoweredBlock_t*) l0)->f_stmts;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        vader_lower_optimise$analyze_stmt(t0, l1);
        l4 = (l4 + INT64_C(1));
    }
    l5 = ((vader_struct_vader_lower_ir$LoweredBlock_t*) l0)->f_trailing;
    if (l5.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_lower_optimise$analyze_expr(l5, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_lower_optimise$analyze_expr(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    int32_t l3;
    int64_t l4, l5;
    vader_box_t l6 = vader_box_null();
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l6, &t1 };
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1538u) {
        l2 = ((vader_struct_vader_lower_optimise$AnalyzeCtx_t*) l1)->f_escaped;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$LoweredIdent_t*) t0)->f_symbol)->f_id;
        std_collections$add__i32(l2, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 1521u) {
        t0 = l0.payload.obj;
        if (!(((vader_struct_vader_lower_ir$LoweredCall_t*) t0)->f_callee.tag == 1538u)) {
            t0 = l0.payload.obj;
            vader_lower_optimise$analyze_expr(((vader_struct_vader_lower_ir$LoweredCall_t*) t0)->f_callee, l1);
        }
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_lower_ir$LoweredCall_t*) t0)->f_args;
        l4 = ((vader_array_t*) l2)->length;
        l5 = INT64_C(0);
        while ((l5 < l4)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
            vader_lower_optimise$analyze_expr(t1, l1);
            l5 = (l5 + INT64_C(1));
        }
    } else if (l0.tag == 1562u) {
        t0 = l0.payload.obj;
        vader_lower_optimise$analyze_expr(((vader_struct_vader_lower_ir$LoweredVirtualCall_t*) t0)->f_receiver, l1);
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_lower_ir$LoweredVirtualCall_t*) t0)->f_args;
        l4 = ((vader_array_t*) l2)->length;
        l5 = INT64_C(0);
        while ((l5 < l4)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            t1 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
            vader_lower_optimise$analyze_expr(t1, l1);
            l5 = (l5 + INT64_C(1));
        }
    } else if ((l0.tag == 1533u || l0.tag == 1560u)) {
        vader_lower_optimise$analyze_expr(VADER_UNION_FIELD(vader_box_t, vader_struct_vader_lower_ir$LoweredFieldAccess_t, f_target, l0.payload.obj), l1);
    } else if (l0.tag == 1540u) {
        t0 = l0.payload.obj;
        vader_lower_optimise$analyze_expr(((vader_struct_vader_lower_ir$LoweredIndex_t*) t0)->f_target, l1);
        t0 = l0.payload.obj;
        vader_lower_optimise$analyze_expr(((vader_struct_vader_lower_ir$LoweredIndex_t*) t0)->f_index, l1);
    } else if (l0.tag == 1559u) {
        t0 = l0.payload.obj;
        vader_lower_optimise$analyze_expr(((vader_struct_vader_lower_ir$LoweredUnary_t*) t0)->f_operand, l1);
    } else if (l0.tag == 1517u) {
        t0 = l0.payload.obj;
        vader_lower_optimise$analyze_expr(((vader_struct_vader_lower_ir$LoweredBinary_t*) t0)->f_left, l1);
        t0 = l0.payload.obj;
        vader_lower_optimise$analyze_expr(((vader_struct_vader_lower_ir$LoweredBinary_t*) t0)->f_right, l1);
    } else if (l0.tag == 1539u) {
        t0 = l0.payload.obj;
        vader_lower_optimise$analyze_expr(((vader_struct_vader_lower_ir$LoweredIf_t*) t0)->f_cond, l1);
        t0 = l0.payload.obj;
        vader_lower_optimise$analyze_block(((vader_struct_vader_lower_ir$LoweredIf_t*) t0)->f_then_block, l1);
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_lower_ir$LoweredIf_t*) t0)->f_else_block;
        if (!(l6.tag == 0u)) {
            t0 = l6.payload.obj;
            vader_lower_optimise$analyze_block(t0, l1);
        }
    } else if (l0.tag == 1518u) {
        t0 = l0.payload.obj;
        vader_lower_optimise$analyze_block(t0, l1);
    } else if (l0.tag == 1555u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_lower_ir$LoweredStructLit_t*) t0)->f_fields;
        l4 = ((vader_array_t*) l2)->length;
        l5 = INT64_C(0);
        while ((l5 < l4)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
            vader_lower_optimise$analyze_expr(((vader_struct_vader_lower_ir$LoweredStructLitField_t*) t0)->f_value, l1);
            l5 = (l5 + INT64_C(1));
        }
    } else if (l0.tag == 1513u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_lower_ir$LoweredArrayLit_t*) t0)->f_elements;
        l4 = ((vader_array_t*) l2)->length;
        l5 = INT64_C(0);
        while ((l5 < l4)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            t1 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l5);
            vader_lower_optimise$analyze_expr(t1, l1);
            l5 = (l5 + INT64_C(1));
        }
    } else if (l0.tag == 1512u) {
        t0 = l0.payload.obj;
        vader_lower_optimise$analyze_expr(((vader_struct_vader_lower_ir$LoweredArrayLen_t*) t0)->f_target, l1);
    } else if (l0.tag == 1514u) {
        t0 = l0.payload.obj;
        vader_lower_optimise$analyze_expr(((vader_struct_vader_lower_ir$LoweredArrayPush_t*) t0)->f_target, l1);
        t0 = l0.payload.obj;
        vader_lower_optimise$analyze_expr(((vader_struct_vader_lower_ir$LoweredArrayPush_t*) t0)->f_value, l1);
    } else if (l0.tag == 1515u) {
        t0 = l0.payload.obj;
        vader_lower_optimise$analyze_expr(((vader_struct_vader_lower_ir$LoweredArraySlice_t*) t0)->f_target, l1);
        t0 = l0.payload.obj;
        vader_lower_optimise$analyze_expr(((vader_struct_vader_lower_ir$LoweredArraySlice_t*) t0)->f_lo, l1);
        t0 = l0.payload.obj;
        vader_lower_optimise$analyze_expr(((vader_struct_vader_lower_ir$LoweredArraySlice_t*) t0)->f_hi, l1);
    } else if (l0.tag == 1522u) {
        t0 = l0.payload.obj;
        vader_lower_optimise$analyze_expr(((vader_struct_vader_lower_ir$LoweredCast_t*) t0)->f_value, l1);
    } else if (l0.tag == 1557u) {
        t0 = l0.payload.obj;
        vader_lower_optimise$analyze_expr(((vader_struct_vader_lower_ir$LoweredTypeCheck_t*) t0)->f_value, l1);
    } else if (l0.tag == 1542u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_lower_ir$LoweredIntrinsicCall_t*) t0)->f_args;
        l4 = ((vader_array_t*) l2)->length;
        l5 = INT64_C(0);
        while ((l5 < l4)) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            t1 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l5);
            vader_lower_optimise$analyze_expr(t1, l1);
            l5 = (l5 + INT64_C(1));
        }
    } else if (l0.tag == 1524u) {
        t0 = l0.payload.obj;
        vader_lower_optimise$analyze_expr(((vader_struct_vader_lower_ir$LoweredCellNew_t*) t0)->f_value, l1);
    } else if (l0.tag == 1523u) {
        t0 = l0.payload.obj;
        vader_lower_optimise$analyze_expr(((vader_struct_vader_lower_ir$LoweredCellGet_t*) t0)->f_target, l1);
    } else if (l0.tag == 1546u) {
        t0 = l0.payload.obj;
        vader_lower_optimise$analyze_expr(((vader_struct_vader_lower_ir$LoweredMakeClosure_t*) t0)->f_env, l1);
    } else if (!(l0.tag == 1541u)) {
        if (!(l0.tag == 1534u)) {
            if (!(l0.tag == 1519u)) {
                if (!(l0.tag == 1548u)) {
                    if (!(l0.tag == 1526u)) {
                        if (!(l0.tag == 1552u)) {
                            if (!(l0.tag == 1529u)) {
                                if (!(l0.tag == 1536u)) {
                                    if (!(l0.tag == 1558u)) {
                                        if (!(l0.tag == 1561u)) {
                                            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_lower_optimise$analyze_stmt(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    int32_t l3;
    vader_box_t l4 = vader_box_null(), l6 = vader_box_null();
    int64_t l7, l8;
    void* t0 = NULL;
    bool t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l0, &l4, &l6, &t2 };
    void** gc_raw_roots[4] = { &l1, &l2, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1544u) {
        l2 = ((vader_struct_vader_lower_optimise$AnalyzeCtx_t*) l1)->f_bound;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$LoweredLet_t*) t0)->f_symbol)->f_id;
        t1 = std_collections$add__i32(l2, l3);
        if (!(t1)) {
            l2 = ((vader_struct_vader_lower_optimise$AnalyzeCtx_t*) l1)->f_escaped;
            t0 = l0.payload.obj;
            l3 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$LoweredLet_t*) t0)->f_symbol)->f_id;
            std_collections$add__i32(l2, l3);
        }
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_lower_ir$LoweredLet_t*) t0)->f_value;
        if (l4.tag == 1538u) {
            t0 = l4.payload.obj;
            if (((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$LoweredIdent_t*) t0)->f_symbol)->f_kind == INT32_C(0)) {
                l2 = ((vader_struct_vader_lower_optimise$AnalyzeCtx_t*) l1)->f_aliases;
                t0 = l0.payload.obj;
                l3 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$LoweredLet_t*) t0)->f_symbol)->f_id;
                t0 = l4.payload.obj;
                l5 = ((vader_struct_vader_lower_ir$LoweredIdent_t*) t0)->f_symbol;
                std_collections$Map$std_core$IndexSet$set_at__i32__Any(l2, l3, vader_ref_box(l5));
                { vader_gc_top = gc_frame.prev; return; }
            }
        }
        if (l4.tag == 1546u) {
            l2 = ((vader_struct_vader_lower_optimise$AnalyzeCtx_t*) l1)->f_closures;
            t0 = l0.payload.obj;
            l3 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$LoweredLet_t*) t0)->f_symbol)->f_id;
            t0 = l4.payload.obj;
            l5 = ((vader_struct_vader_lower_ir$LoweredMakeClosure_t*) t0)->f_fn_symbol;
            t0 = l4.payload.obj;
            l6 = VADER_UNION_FIELD(vader_box_t, vader_struct_vader_lower_ir$LoweredArrayLen_t, f_type, ((vader_struct_vader_lower_ir$LoweredMakeClosure_t*) t0)->f_env.payload.obj);
            vader_struct_vader_lower_optimise$ClosureAlias_t* _a0_obj = (vader_struct_vader_lower_optimise$ClosureAlias_t*) vader_gc_alloc(sizeof(vader_struct_vader_lower_optimise$ClosureAlias_t));
            vader_obj_header_init(_a0_obj, 1570u);
            _a0_obj->f_fn_sym = l5;
            _a0_obj->f_env_type = l6;
            l5 = (void*) _a0_obj;
            std_collections$Map$std_core$IndexSet$set_at__i32__Any(l2, l3, vader_ref_box(l5));
            t0 = l4.payload.obj;
            vader_lower_optimise$analyze_expr(((vader_struct_vader_lower_ir$LoweredMakeClosure_t*) t0)->f_env, l1);
            { vader_gc_top = gc_frame.prev; return; }
        }
        vader_lower_optimise$analyze_expr(l4, l1);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 1516u) {
        t0 = l0.payload.obj;
        vader_lower_optimise$analyze_expr(((vader_struct_vader_lower_ir$LoweredAssign_t*) t0)->f_target, l1);
        t0 = l0.payload.obj;
        vader_lower_optimise$analyze_expr(((vader_struct_vader_lower_ir$LoweredAssign_t*) t0)->f_value, l1);
    } else if (l0.tag == 1525u) {
        t0 = l0.payload.obj;
        vader_lower_optimise$analyze_expr(((vader_struct_vader_lower_ir$LoweredCellSet_t*) t0)->f_target, l1);
        t0 = l0.payload.obj;
        vader_lower_optimise$analyze_expr(((vader_struct_vader_lower_ir$LoweredCellSet_t*) t0)->f_value, l1);
    } else if (l0.tag == 1537u) {
        t0 = l0.payload.obj;
        vader_lower_optimise$analyze_expr(((vader_struct_vader_lower_ir$LoweredGlobalSet_t*) t0)->f_value, l1);
    } else if (l0.tag == 1532u) {
        t0 = l0.payload.obj;
        vader_lower_optimise$analyze_expr(((vader_struct_vader_lower_ir$LoweredExprStmt_t*) t0)->f_expr, l1);
    } else if (l0.tag == 1551u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_lower_ir$LoweredReturn_t*) t0)->f_value;
        if (!(l4.tag == 0u)) {
            vader_lower_optimise$analyze_expr(l4, l1);
        }
    } else if (l0.tag == 1564u) {
        t0 = l0.payload.obj;
        vader_lower_optimise$analyze_expr(((vader_struct_vader_lower_ir$LoweredYield_t*) t0)->f_value, l1);
    } else if (l0.tag == 1543u) {
        t0 = l0.payload.obj;
        vader_lower_optimise$analyze_block(((vader_struct_vader_lower_ir$LoweredLabelledBlock_t*) t0)->f_body, l1);
    } else if (l0.tag == 1545u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_lower_ir$LoweredLoop_t*) t0)->f_cond;
        if (!(l4.tag == 0u)) {
            vader_lower_optimise$analyze_expr(l4, l1);
        }
        t0 = l0.payload.obj;
        vader_lower_optimise$analyze_block(((vader_struct_vader_lower_ir$LoweredLoop_t*) t0)->f_body, l1);
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_lower_ir$LoweredLoop_t*) t0)->f_step;
        l7 = ((vader_array_t*) l2)->length;
        l8 = INT64_C(0);
        while ((l8 < l7)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            t2 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l8);
            vader_lower_optimise$analyze_stmt(t2, l1);
            l8 = (l8 + INT64_C(1));
        }
    } else if (!(l0.tag == 1520u)) {
        if (!(l0.tag == 1528u)) {
            if (l0.tag == 1531u) {
                t0 = l0.payload.obj;
                vader_lower_optimise$analyze_expr(((vader_struct_vader_lower_ir$LoweredDeferPush_t*) t0)->f_thunk, l1);
            } else if (!(l0.tag == 1530u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_lower_optimise$any_expr_may_disturb(void* l0, void* l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null();
    bool t0;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l1;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t0 = vader_lower_optimise$expr_may_disturb(l0, l5);
        if (t0) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        l4 = (l4 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static bool vader_lower_optimise$block_may_disturb(void* l0, void* l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null(), l6 = vader_box_null();
    bool t0;
    vader_box_t* gc_roots[2] = { &l5, &l6 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_lower_ir$LoweredBlock_t*) l1)->f_stmts;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t0 = vader_lower_optimise$stmt_may_disturb(l0, l5);
        if (t0) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        l4 = (l4 + INT64_C(1));
    }
    l6 = ((vader_struct_vader_lower_ir$LoweredBlock_t*) l1)->f_trailing;
    if (l6.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    l5 = l6;
    t0 = vader_lower_optimise$expr_may_disturb(l0, l5);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_lower_optimise$call_may_disturb(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_lower_ir$LoweredCall_t*) l1)->f_callee;
    if (!(l2.tag == 1538u)) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    t0 = l2.payload.obj;
    l3 = ((vader_struct_vader_lower_ir$LoweredIdent_t*) t0)->f_symbol;
    if (((vader_struct_vader_core_symbol$Symbol_t*) l3)->f_kind != INT32_C(0)) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    l2 = vader_lower_optimise$indexed_decl(l0, l3);
    if (l2.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    l3 = l2.payload.obj;
    t1 = vader_lower_optimise$is_pure_fn(l0, l3);
    if (!(t1)) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    l3 = ((vader_struct_vader_lower_ir$LoweredCall_t*) l1)->f_args;
    t1 = vader_lower_optimise$any_expr_may_disturb(l0, l3);
    { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_lower_optimise$count_between(vader_box_t l0, vader_box_t l1, void* l2) {
    void* l3 = NULL;
    bool t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l0, &l1 };
    void** gc_raw_roots[3] = { &l2, &l3, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_lower_optimise$is_int_lit(l1, INT64_C(0));
    if (!(t0)) {
        t1 = (void*) &vader_data_24;
        vader_array_t* _a0_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l3 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
        vader_struct_vader_lower_ir$LoweredBinary_t* _a1_obj = (vader_struct_vader_lower_ir$LoweredBinary_t*) vader_gc_alloc(sizeof(vader_struct_vader_lower_ir$LoweredBinary_t));
        vader_obj_header_init(_a1_obj, 1517u);
        _a1_obj->f_span = l2;
        _a1_obj->f_type = vader_ref_box(l3);
        _a1_obj->f_op = (uint8_t) 1;
        _a1_obj->f_left = l0;
        _a1_obj->f_right = l1;
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_lower_optimise$count_lit(int64_t l0, void* l1) {
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = (void*) &vader_data_24;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
    vader_struct_vader_lower_ir$LoweredIntLit_t* _a1_obj = (vader_struct_vader_lower_ir$LoweredIntLit_t*) vader_gc_alloc(sizeof(vader_struct_vader_lower_ir$LoweredIntLit_t));
    vader_obj_header_init(_a1_obj, 1541u);
    _a1_obj->f_span = l1;
    _a1_obj->f_type = vader_ref_box(l2);
    _a1_obj->f_value = l0;
    t0 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_lower_optimise$counted_loop_in(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    vader_box_t l3 = vader_box_null(), l6 = vader_box_null();
    bool l7;
    int64_t l8, l9;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null(), t3 = vader_box_null();
    vader_box_t* gc_roots[5] = { &l0, &l3, &l6, &t2, &t3 };
    void** gc_raw_roots[5] = { &l1, &l2, &l4, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 5u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1545u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_lower_ir$LoweredLoop_t*) t0)->f_turns;
        if (l3.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
        }
        l2 = l3.payload.obj;
        l4 = l2;
        l5 = ((vader_struct_vader_lower_ir$LoopTurns_t*) l4)->f_counter;
        l3 = vader_lower_optimise$hoisted(((vader_struct_vader_lower_ir$LoopTurns_t*) l2)->f_start, l1);
        if (l3.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
        }
        l6 = vader_lower_optimise$hoisted(((vader_struct_vader_lower_ir$LoopTurns_t*) l2)->f_bound, l1);
        if (l6.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
        }
        l7 = ((vader_struct_vader_lower_ir$LoopTurns_t*) l4)->f_inclusive;
        vader_struct_vader_lower_ir$LoopTurns_t* _a0_obj = (vader_struct_vader_lower_ir$LoopTurns_t*) vader_gc_alloc(sizeof(vader_struct_vader_lower_ir$LoopTurns_t));
        vader_obj_header_init(_a0_obj, 1511u);
        _a0_obj->f_counter = l5;
        _a0_obj->f_start = l3;
        _a0_obj->f_bound = l6;
        _a0_obj->f_inclusive = l7;
        l2 = (void*) _a0_obj;
        t0 = l0.payload.obj;
        vader_struct_vader_lower_optimise$CountedLoop_t* _a1_obj = (vader_struct_vader_lower_optimise$CountedLoop_t*) vader_gc_alloc(sizeof(vader_struct_vader_lower_optimise$CountedLoop_t));
        vader_obj_header_init(_a1_obj, 1571u);
        _a1_obj->f_body = ((vader_struct_vader_lower_ir$LoweredLoop_t*) t0)->f_body;
        _a1_obj->f_turns = l2;
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1532u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_lower_ir$LoweredExprStmt_t*) t0)->f_expr;
        if (l3.tag == 1518u) {
            t0 = l3.payload.obj;
            if (((vader_struct_vader_lower_ir$LoweredBlock_t*) t0)->f_trailing.tag == 0u) {
                t0 = l3.payload.obj;
                t1 = ((vader_array_t*) ((vader_struct_vader_lower_ir$LoweredBlock_t*) t0)->f_stmts)->length;
                if (t1 == INT64_C(0)) {
                    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
                }
                t0 = l3.payload.obj;
                t1 = ((vader_array_t*) ((vader_struct_vader_lower_ir$LoweredBlock_t*) t0)->f_stmts)->length;
                l8 = vader_chk_sub(i64, t1, INT64_C(1));
                l9 = INT64_C(0);
                while ((l9 < l8)) {
                    t0 = l3.payload.obj;
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_lower_ir$LoweredBlock_t*) t0)->f_stmts);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l9)
                    l6 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l9);
                    if (!(l6.tag == 1544u)) {
                        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
                    }
                    l2 = l6.payload.obj;
                    vader_array_push_ref((vader_array_t*) l1, l2);
                    l9 = (l9 + INT64_C(1));
                }
                t0 = l3.payload.obj;
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_lower_ir$LoweredBlock_t*) t0)->f_stmts);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l8)
                t2 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l8);
                t3 = vader_lower_optimise$counted_loop_in(t2, l1);
                { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
            }
            { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
        }
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_lower_optimise$counted_loop_of(vader_box_t l0) {
    void* l1 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &t0 };
    void** gc_raw_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1545u) {
        vader_array_t* _a0_arr = vader_array_new(328u, 0u, 13u, 1544u);
        l1 = (void*) _a0_arr;
        t0 = vader_lower_optimise$counted_loop_in(l0, l1);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0.tag == 1532u)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    vader_array_t* _a1_arr = vader_array_new(328u, 0u, 13u, 1544u);
    l1 = (void*) _a1_arr;
    t0 = vader_lower_optimise$counted_loop_in(l0, l1);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_lower_optimise$defining_let(void* l0, void* l1) {
    void* l2;
    void* l5;
    int64_t l3, l4;
    int32_t l6, l7;
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        l6 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$LoweredLet_t*) l5)->f_symbol)->f_id;
        l7 = ((vader_struct_vader_core_symbol$Symbol_t*) l1)->f_id;
        if (l6 == l7) {
            return vader_ref_box(l5);
        }
        l4 = (l4 + INT64_C(1));
    }
    return vader_box_obj(0u, NULL);
}

static void vader_lower_optimise$devirt_body(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* t0 = NULL;
    bool t1;
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 8u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(27u, 0u, 7u, 496u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(33u, 0u, 0u, 504u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(27u, 0u, 7u, 496u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections$Map__i32__Any_t* _a3_obj = (vader_struct_std_collections$Map__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__Any_t));
    vader_obj_header_init(_a3_obj, 682u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l1 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(27u, 0u, 7u, 496u);
    l2 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(33u, 0u, 0u, 504u);
    l3 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(27u, 0u, 7u, 496u);
    l4 = (void*) _a6_arr;
    vader_struct_std_collections$Map__i32__Any_t* _a7_obj = (vader_struct_std_collections$Map__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__Any_t));
    vader_obj_header_init(_a7_obj, 682u);
    _a7_obj->f_ekeys = l2;
    _a7_obj->f_evals = l3;
    _a7_obj->f_index = l4;
    _a7_obj->f_mask = INT64_C(0);
    _a7_obj->f_grow_at = INT64_C(0);
    _a7_obj->f_size = INT64_C(0);
    _a7_obj->f_tombs = INT64_C(0);
    l2 = (void*) _a7_obj;
    vader_array_t* _a8_arr = vader_array_new(27u, 0u, 7u, 496u);
    l3 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(24u, 0u, 12u, 491u);
    l4 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(27u, 0u, 7u, 496u);
    l5 = (void*) _a10_arr;
    vader_struct_std_collections$Map__i32__bool_t* _a11_obj = (vader_struct_std_collections$Map__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__bool_t));
    vader_obj_header_init(_a11_obj, 685u);
    _a11_obj->f_ekeys = l3;
    _a11_obj->f_evals = l4;
    _a11_obj->f_index = l5;
    _a11_obj->f_mask = INT64_C(0);
    _a11_obj->f_grow_at = INT64_C(0);
    _a11_obj->f_size = INT64_C(0);
    _a11_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a11_obj;
    vader_struct_std_collections$Set__i32_t* _a12_obj = (vader_struct_std_collections$Set__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__i32_t));
    vader_obj_header_init(_a12_obj, 842u);
    _a12_obj->f_inner = t0;
    l3 = (void*) _a12_obj;
    vader_array_t* _a13_arr = vader_array_new(27u, 0u, 7u, 496u);
    l4 = (void*) _a13_arr;
    vader_array_t* _a14_arr = vader_array_new(24u, 0u, 12u, 491u);
    l5 = (void*) _a14_arr;
    vader_array_t* _a15_arr = vader_array_new(27u, 0u, 7u, 496u);
    l6 = (void*) _a15_arr;
    vader_struct_std_collections$Map__i32__bool_t* _a16_obj = (vader_struct_std_collections$Map__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__bool_t));
    vader_obj_header_init(_a16_obj, 685u);
    _a16_obj->f_ekeys = l4;
    _a16_obj->f_evals = l5;
    _a16_obj->f_index = l6;
    _a16_obj->f_mask = INT64_C(0);
    _a16_obj->f_grow_at = INT64_C(0);
    _a16_obj->f_size = INT64_C(0);
    _a16_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a16_obj;
    vader_struct_std_collections$Set__i32_t* _a17_obj = (vader_struct_std_collections$Set__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__i32_t));
    vader_obj_header_init(_a17_obj, 842u);
    _a17_obj->f_inner = t0;
    l4 = (void*) _a17_obj;
    vader_struct_vader_lower_optimise$AnalyzeCtx_t* _a18_obj = (vader_struct_vader_lower_optimise$AnalyzeCtx_t*) vader_gc_alloc(sizeof(vader_struct_vader_lower_optimise$AnalyzeCtx_t));
    vader_obj_header_init(_a18_obj, 1569u);
    _a18_obj->f_aliases = l1;
    _a18_obj->f_closures = l2;
    _a18_obj->f_escaped = l3;
    _a18_obj->f_bound = l4;
    l1 = (void*) _a18_obj;
    vader_lower_optimise$analyze_block(l0, l1);
    t1 = std_collections$is_empty__i32__Any(((vader_struct_vader_lower_optimise$AnalyzeCtx_t*) l1)->f_aliases);
    if (t1) {
        t1 = std_collections$is_empty__i32__Any(((vader_struct_vader_lower_optimise$AnalyzeCtx_t*) l1)->f_closures);
        if (t1) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        vader_lower_optimise$rewrite_block(l0, l1);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_lower_optimise$rewrite_block(l0, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

void vader_lower_optimise$devirtualize_fn_refs(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    int64_t l4, l5, l6, l7;
    vader_box_t l8 = vader_box_null(), l9 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    void* t2 = NULL;
    vader_box_t* gc_roots[3] = { &l8, &l9, &t0 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t2 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l0)->f_modules;
    l2 = ((vader_struct_std_collections$Map__string__vader_lower_ir_LoweredModule_t*) l1)->f_ekeys;
    l3 = ((vader_struct_std_collections$Map__string__vader_lower_ir_LoweredModule_t*) l1)->f_evals;
    l4 = INT64_C(0);
    l5 = ((vader_struct_std_collections$Map__string__vader_lower_ir_LoweredModule_t*) l1)->f_size;
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
            if (l8.tag == 1535u) {
                t2 = l8.payload.obj;
                l9 = ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) t2)->f_body;
                if (!(l9.tag == 0u)) {
                    t2 = l9.payload.obj;
                    vader_lower_optimise$devirt_body(t2);
                }
            }
            l7 = (l7 + INT64_C(1));
        }
        l4 = (l4 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_lower_optimise$expr_may_disturb(void* l0, vader_box_t l1) {
    bool l2, l5;
    void* l3 = NULL;
    vader_box_t l4 = vader_box_null();
    void* t0 = NULL;
    int64_t t1;
    bool t2;
    vader_box_t* gc_roots[2] = { &l1, &l4 };
    void** gc_raw_roots[3] = { &l0, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 1521u) {
        l3 = l1.payload.obj;
        l2 = vader_lower_optimise$call_may_disturb(l0, l3);
        { bool __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if ((l1.tag == 1514u || l1.tag == 1542u || l1.tag == 1562u)) {
        l2 = true;
    } else if ((l1.tag == 1513u || l1.tag == 1524u || l1.tag == 1546u)) {
        l2 = true;
    } else if (l1.tag == 1515u) {
        l2 = true;
    } else if (l1.tag == 1555u) {
        t0 = l1.payload.obj;
        t1 = vader_core_types$value_abi_type_size(((vader_struct_vader_lower_ir$LoweredStructLit_t*) t0)->f_type);
        if ((t1 < INT64_C(0))) {
            l2 = true;
        } else {
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_lower_ir$LoweredStructLit_t*) t0)->f_fields;
            l2 = vader_lower_optimise$fields_may_disturb(l0, l3);
        }
    } else if ((l1.tag == 1519u || l1.tag == 1526u || l1.tag == 1534u || l1.tag == 1541u || l1.tag == 1548u)) {
        l2 = false;
    } else if ((l1.tag == 1529u || l1.tag == 1538u || l1.tag == 1552u || l1.tag == 1561u)) {
        l2 = false;
    } else if ((l1.tag == 1536u || l1.tag == 1558u)) {
        l2 = false;
    } else if (l1.tag == 1533u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_lower_ir$LoweredFieldAccess_t*) t0)->f_target;
        l2 = vader_lower_optimise$expr_may_disturb(l0, l4);
    } else if (l1.tag == 1560u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_lower_ir$LoweredUnionField_t*) t0)->f_target;
        l2 = vader_lower_optimise$expr_may_disturb(l0, l4);
    } else if (l1.tag == 1540u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_lower_ir$LoweredIndex_t*) t0)->f_target;
        t2 = vader_lower_optimise$expr_may_disturb(l0, l4);
        if (t2) {
            l2 = true;
        } else {
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_lower_ir$LoweredIndex_t*) t0)->f_index;
            l2 = vader_lower_optimise$expr_may_disturb(l0, l4);
        }
    } else if (l1.tag == 1559u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_lower_ir$LoweredUnary_t*) t0)->f_operand;
        l2 = vader_lower_optimise$expr_may_disturb(l0, l4);
    } else if (l1.tag == 1517u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_lower_ir$LoweredBinary_t*) t0)->f_left;
        t2 = vader_lower_optimise$expr_may_disturb(l0, l4);
        if (t2) {
            l2 = true;
        } else {
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_lower_ir$LoweredBinary_t*) t0)->f_right;
            l2 = vader_lower_optimise$expr_may_disturb(l0, l4);
        }
    } else if (l1.tag == 1539u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_lower_ir$LoweredIf_t*) t0)->f_cond;
        t2 = vader_lower_optimise$expr_may_disturb(l0, l4);
        if (t2) {
            l5 = true;
        } else {
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_lower_ir$LoweredIf_t*) t0)->f_then_block;
            l5 = vader_lower_optimise$block_may_disturb(l0, l3);
        }
        if (l5) {
            l2 = true;
        } else {
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_lower_ir$LoweredIf_t*) t0)->f_else_block;
            l2 = vader_lower_optimise$opt_block_may_disturb(l0, l4);
        }
    } else if (l1.tag == 1518u) {
        l3 = l1.payload.obj;
        l2 = vader_lower_optimise$block_may_disturb(l0, l3);
    } else if (l1.tag == 1522u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_lower_ir$LoweredCast_t*) t0)->f_value;
        l2 = vader_lower_optimise$expr_may_disturb(l0, l4);
    } else if (l1.tag == 1557u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_lower_ir$LoweredTypeCheck_t*) t0)->f_value;
        l2 = vader_lower_optimise$expr_may_disturb(l0, l4);
    } else if (l1.tag == 1512u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_lower_ir$LoweredArrayLen_t*) t0)->f_target;
        l2 = vader_lower_optimise$expr_may_disturb(l0, l4);
    } else {
        if (!(l1.tag == 1523u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_lower_ir$LoweredCellGet_t*) t0)->f_target;
        l2 = vader_lower_optimise$expr_may_disturb(l0, l4);
    }
    { bool __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_lower_optimise$fields_may_disturb(void* l0, void* l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null();
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l1;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        l5 = ((vader_struct_vader_lower_ir$LoweredStructLitField_t*) t0)->f_value;
        t1 = vader_lower_optimise$expr_may_disturb(l0, l5);
        if (t1) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        l4 = (l4 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static bool vader_lower_optimise$has_top_level_push(void* l0, void* l1) {
    void* l2;
    int64_t l3, l4;
    vader_box_t l5;
    void* t0;
    bool t1;
    l2 = ((vader_struct_vader_lower_ir$LoweredBlock_t*) l0)->f_stmts;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        if (l5.tag == 1532u) {
            t0 = l5.payload.obj;
            t1 = vader_lower_optimise$is_push_onto(((vader_struct_vader_lower_ir$LoweredExprStmt_t*) t0)->f_expr, l1);
            if (t1) {
                return true;
            }
        }
        l4 = (l4 + INT64_C(1));
    }
    l5 = ((vader_struct_vader_lower_ir$LoweredBlock_t*) l0)->f_trailing;
    if (l5.tag == 0u) {
        return false;
    }
    t1 = vader_lower_optimise$is_push_onto(l5, l1);
    return t1;
}

static vader_box_t vader_lower_optimise$hoisted(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null();
    vader_string_t l6 = 0;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l0, &l3, &l4, &t1 };
    void** gc_raw_roots[4] = { &l1, &l2, &l5, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1541u) {
        t0 = l0.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1538u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_lower_ir$LoweredIdent_t*) t0)->f_symbol;
        l3 = vader_lower_optimise$defining_let(l1, l2);
        if (l3.tag == 0u) {
            t0 = l0.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l2 = l3.payload.obj;
        t1 = vader_lower_optimise$hoisted(((vader_struct_vader_lower_ir$LoweredLet_t*) l2)->f_value, l1);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1512u) {
        t0 = l0.payload.obj;
        l4 = vader_lower_optimise$hoisted(((vader_struct_vader_lower_ir$LoweredArrayLen_t*) t0)->f_target, l1);
        if (l4.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
        }
        l3 = l4;
        l2 = l0.payload.obj;
        l5 = ((vader_struct_vader_lower_ir$LoweredArrayLen_t*) l2)->f_span;
        l4 = ((vader_struct_vader_lower_ir$LoweredArrayLen_t*) l2)->f_type;
        vader_struct_vader_lower_ir$LoweredArrayLen_t* _a0_obj = (vader_struct_vader_lower_ir$LoweredArrayLen_t*) vader_gc_alloc(sizeof(vader_struct_vader_lower_ir$LoweredArrayLen_t));
        vader_obj_header_init(_a0_obj, 1512u);
        _a0_obj->f_span = l5;
        _a0_obj->f_type = l4;
        _a0_obj->f_target = l3;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0.tag == 1533u)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t0 = l0.payload.obj;
    l4 = vader_lower_optimise$hoisted(((vader_struct_vader_lower_ir$LoweredFieldAccess_t*) t0)->f_target, l1);
    if (l4.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l3 = l4;
    l2 = l0.payload.obj;
    l5 = ((vader_struct_vader_lower_ir$LoweredFieldAccess_t*) l2)->f_span;
    l4 = ((vader_struct_vader_lower_ir$LoweredFieldAccess_t*) l2)->f_type;
    l6 = ((vader_struct_vader_lower_ir$LoweredFieldAccess_t*) l2)->f_field;
    vader_struct_vader_lower_ir$LoweredFieldAccess_t* _a1_obj = (vader_struct_vader_lower_ir$LoweredFieldAccess_t*) vader_gc_alloc(sizeof(vader_struct_vader_lower_ir$LoweredFieldAccess_t));
    vader_obj_header_init(_a1_obj, 1533u);
    _a1_obj->f_span = l5;
    _a1_obj->f_type = l4;
    _a1_obj->f_target = l3;
    _a1_obj->f_field = l6;
    t0 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_lower_optimise$indexed_decl(void* l0, void* l1) {
    void* l2;
    vader_string_t l3;
    vader_box_t l4;
    int32_t l5;
    void* t0;
    vader_box_t t1;
    l2 = ((vader_struct_vader_lower_optimise$PurityCtx_t*) l0)->f_by_mangle;
    l3 = ((vader_struct_vader_core_symbol$Symbol_t*) l1)->f_name;
    l4 = std_collections$Map$std_core$Index$at__string__Any(l2, l3);
    if (!(l4.tag == 0u)) {
        t0 = l4.payload.obj;
        return vader_ref_box(t0);
    }
    l2 = ((vader_struct_vader_lower_optimise$PurityCtx_t*) l0)->f_by_sym_id;
    l5 = ((vader_struct_vader_core_symbol$Symbol_t*) l1)->f_id;
    t1 = std_collections$Map$std_core$Index$at__i32__Any(l2, l5);
    return t1;
}

static bool vader_lower_optimise$is_empty_array_lit(vader_box_t l0) {
    void* t0;
    int64_t t1;
    if (l0.tag == 1513u) {
        t0 = l0.payload.obj;
        t1 = ((vader_array_t*) ((vader_struct_vader_lower_ir$LoweredArrayLit_t*) t0)->f_elements)->length;
        return t1 == INT64_C(0);
    }
    return false;
}

static bool vader_lower_optimise$is_fresh_array(vader_box_t l0) {
    bool l1;
    void* t0;
    vader_string_t t1;
    int64_t t2;
    vader_box_t t3;
    if (l0.tag == 1513u) {
        return true;
    }
    if (!(l0.tag == 1542u)) {
        return false;
    }
    t0 = l0.payload.obj;
    t1 = ((vader_struct_vader_lower_ir$LoweredIntrinsicCall_t*) t0)->f_name;
    if (t1 == 1674u) {
        return true;
    }
    t0 = l0.payload.obj;
    t1 = ((vader_struct_vader_lower_ir$LoweredIntrinsicCall_t*) t0)->f_name;
    if (t1 == 1671u) {
        t0 = l0.payload.obj;
        t2 = ((vader_array_t*) ((vader_struct_vader_lower_ir$LoweredIntrinsicCall_t*) t0)->f_args)->length;
        l1 = t2 == INT64_C(2);
    } else {
        l1 = false;
    }
    if (l1) {
        t0 = l0.payload.obj;
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_lower_ir$LoweredIntrinsicCall_t*) t0)->f_args);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
        t3 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
        l1 = t3.tag == 1513u;
    } else {
        l1 = false;
    }
    return l1;
}

static bool vader_lower_optimise$is_int_lit(vader_box_t l0, int64_t l1) {
    void* t0;
    int64_t t1;
    if (l0.tag == 1541u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_lower_ir$LoweredIntLit_t*) t0)->f_value;
        return t1 == l1;
    }
    return false;
}

static bool vader_lower_optimise$is_pure_fn(void* l0, void* l1) {
    vader_string_t l2 = 0;
    vader_box_t l3 = vader_box_null();
    void* l4 = NULL;
    bool l5;
    bool t0;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) l1)->f_mangled;
    l3 = std_collections$Map$std_core$Index$at__string__bool(((vader_struct_vader_lower_optimise$PurityCtx_t*) l0)->f_memo, l2);
    if (!(l3.tag == 0u)) {
        t0 = l3.payload.b;
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) l1)->f_body;
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    l4 = l3.payload.obj;
    std_collections$Map$std_core$IndexSet$set_at__string__bool(((vader_struct_vader_lower_optimise$PurityCtx_t*) l0)->f_memo, l2, false);
    t0 = vader_lower_optimise$block_may_disturb(l0, l4);
    l5 = !(t0);
    std_collections$Map$std_core$IndexSet$set_at__string__bool(((vader_struct_vader_lower_optimise$PurityCtx_t*) l0)->f_memo, l2, l5);
    { bool __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_lower_optimise$is_push_onto(vader_box_t l0, void* l1) {
    void* t0;
    bool t1;
    if (l0.tag == 1514u) {
        t0 = l0.payload.obj;
        t1 = vader_lower_optimise$names_local(((vader_struct_vader_lower_ir$LoweredArrayPush_t*) t0)->f_target, l1);
        return t1;
    }
    return false;
}

static bool vader_lower_optimise$names_local(vader_box_t l0, void* l1) {
    int32_t l2, l3;
    void* t0;
    if (l0.tag == 1538u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$LoweredIdent_t*) t0)->f_symbol)->f_id;
        l3 = ((vader_struct_vader_core_symbol$Symbol_t*) l1)->f_id;
        return l2 == l3;
    }
    return false;
}

static bool vader_lower_optimise$never_negative(vader_box_t l0) {
    vader_box_t l1;
    void* t0;
    int64_t t1;
    if (l0.tag == 1512u) {
        return true;
    }
    l1 = VADER_UNION_FIELD(vader_box_t, vader_struct_vader_lower_ir$LoweredArrayLit_t, f_type, l0.payload.obj);
    if (l1.tag == 1147u) {
        t0 = l1.payload.obj;
        t1 = ((vader_struct_vader_support_integer$Interval_t*) ((vader_struct_vader_core_types$RangeType_t*) t0)->f_bounds)->f_lo;
        return (t1 >= INT64_C(0));
    }
    return false;
}

static void* vader_lower_optimise$new_purity_ctx(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l12 = NULL;
    void* l15 = NULL;
    int64_t l6, l7, l8, l9;
    vader_box_t l10 = vader_box_null(), l13 = vader_box_null();
    vader_string_t l11 = 0;
    int32_t l14;
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    void* t2 = NULL;
    int64_t t3;
    vader_box_t* gc_roots[3] = { &l10, &l13, &t0 };
    void** gc_raw_roots[9] = { &l0, &l1, &l2, &l3, &l4, &l5, &l12, &l15, &t2 };
    vader_string_t* gc_atom_roots[2] = { &l11, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(26u, 0u, 0u, 493u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(33u, 0u, 0u, 504u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(27u, 0u, 7u, 496u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections$Map__string__Any_t* _a3_obj = (vader_struct_std_collections$Map__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any_t));
    vader_obj_header_init(_a3_obj, 759u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l1 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(27u, 0u, 7u, 496u);
    l2 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(33u, 0u, 0u, 504u);
    l3 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(27u, 0u, 7u, 496u);
    l4 = (void*) _a6_arr;
    vader_struct_std_collections$Map__i32__Any_t* _a7_obj = (vader_struct_std_collections$Map__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__Any_t));
    vader_obj_header_init(_a7_obj, 682u);
    _a7_obj->f_ekeys = l2;
    _a7_obj->f_evals = l3;
    _a7_obj->f_index = l4;
    _a7_obj->f_mask = INT64_C(0);
    _a7_obj->f_grow_at = INT64_C(0);
    _a7_obj->f_size = INT64_C(0);
    _a7_obj->f_tombs = INT64_C(0);
    l2 = (void*) _a7_obj;
    l3 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l0)->f_modules;
    l4 = ((vader_struct_std_collections$Map__string__vader_lower_ir_LoweredModule_t*) l3)->f_ekeys;
    l5 = ((vader_struct_std_collections$Map__string__vader_lower_ir_LoweredModule_t*) l3)->f_evals;
    l6 = INT64_C(0);
    l7 = ((vader_struct_std_collections$Map__string__vader_lower_ir_LoweredModule_t*) l3)->f_size;
    while ((l6 < l7)) {
        vader_array_t* _a8_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l6)
        t0 = vader_array_box_slots(_a8_slotarr->buf)[_a8_slotarr->offset + (size_t) l6];
        t1 = t0.payload.s;
        vader_array_t* _a9_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l6)
        t2 = vader_array_ref_load_obj(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l6);
        l3 = ((vader_struct_vader_lower_ir$LoweredModule_t*) t2)->f_decls;
        l8 = ((vader_array_t*) l3)->length;
        l9 = INT64_C(0);
        while ((l9 < l8)) {
            vader_array_t* _a10_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
            l10 = vader_array_ref_load_box(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l9);
            if (l10.tag == 1535u) {
                t2 = l10.payload.obj;
                l11 = ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) t2)->f_mangled;
                l12 = l10.payload.obj;
                std_collections$Map$std_core$IndexSet$set_at__string__Any(l1, l11, vader_ref_box(l12));
                t2 = l10.payload.obj;
                l13 = ((vader_struct_vader_core_mono$MonoEntry_t*) ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) t2)->f_origin)->f_symbol;
                if (!(l13.tag == 0u)) {
                    t2 = l10.payload.obj;
                    t3 = ((vader_array_t*) ((vader_struct_vader_core_mono$MonoEntry_t*) ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) t2)->f_origin)->f_type_arguments)->length;
                    if (t3 == INT64_C(0)) {
                        t2 = l13.payload.obj;
                        l14 = ((vader_struct_vader_core_symbol$Symbol_t*) t2)->f_id;
                        l15 = l10.payload.obj;
                        std_collections$Map$std_core$IndexSet$set_at__i32__Any(l2, l14, vader_ref_box(l15));
                    }
                }
            }
            l9 = (l9 + INT64_C(1));
        }
        l6 = (l6 + INT64_C(1));
    }
    vader_array_t* _a11_arr = vader_array_new(26u, 0u, 0u, 493u);
    l3 = (void*) _a11_arr;
    vader_array_t* _a12_arr = vader_array_new(24u, 0u, 12u, 491u);
    l4 = (void*) _a12_arr;
    vader_array_t* _a13_arr = vader_array_new(27u, 0u, 7u, 496u);
    l5 = (void*) _a13_arr;
    vader_struct_std_collections$Map__string__bool_t* _a14_obj = (vader_struct_std_collections$Map__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__bool_t));
    vader_obj_header_init(_a14_obj, 765u);
    _a14_obj->f_ekeys = l3;
    _a14_obj->f_evals = l4;
    _a14_obj->f_index = l5;
    _a14_obj->f_mask = INT64_C(0);
    _a14_obj->f_grow_at = INT64_C(0);
    _a14_obj->f_size = INT64_C(0);
    _a14_obj->f_tombs = INT64_C(0);
    l3 = (void*) _a14_obj;
    vader_struct_vader_lower_optimise$PurityCtx_t* _a15_obj = (vader_struct_vader_lower_optimise$PurityCtx_t*) vader_gc_alloc(sizeof(vader_struct_vader_lower_optimise$PurityCtx_t));
    vader_obj_header_init(_a15_obj, 1572u);
    _a15_obj->f_by_mangle = l1;
    _a15_obj->f_by_sym_id = l2;
    _a15_obj->f_memo = l3;
    t2 = (void*) _a15_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_lower_optimise$opt_block_may_disturb(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    bool t0;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(l1.tag == 0u)) {
        l2 = l1.payload.obj;
        t0 = vader_lower_optimise$block_may_disturb(l0, l2);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static bool vader_lower_optimise$opt_expr_may_disturb(void* l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null();
    bool t0;
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(l1.tag == 0u)) {
        l2 = l1;
        t0 = vader_lower_optimise$expr_may_disturb(l0, l2);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static bool vader_lower_optimise$pc_body_may_disturb(void* l0, void* l1, int32_t l2) {
    void* l3 = NULL;
    int64_t l4, l5;
    vader_box_t l6 = vader_box_null(), l7 = vader_box_null();
    bool t0;
    vader_box_t* gc_roots[2] = { &l6, &l7 };
    void** gc_raw_roots[3] = { &l0, &l1, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_lower_ir$LoweredBlock_t*) l1)->f_stmts;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l6 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        t0 = vader_lower_optimise$pc_stmt_may_disturb(l0, l6, l2);
        if (t0) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        l5 = (l5 + INT64_C(1));
    }
    l7 = ((vader_struct_vader_lower_ir$LoweredBlock_t*) l1)->f_trailing;
    if (l7.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    l6 = l7;
    t0 = vader_lower_optimise$pc_expr_may_disturb_skipping_push(l0, l6, l2);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_lower_optimise$pc_collect_in_expr(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l0, &l3 };
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1514u) {
        l2 = l0.payload.obj;
        vader_array_push_ref((vader_array_t*) l1, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 1518u) {
        t0 = l0.payload.obj;
        vader_lower_optimise$pc_collect_pushes(t0, l1);
    } else if (l0.tag == 1539u) {
        t0 = l0.payload.obj;
        vader_lower_optimise$pc_collect_pushes(((vader_struct_vader_lower_ir$LoweredIf_t*) t0)->f_then_block, l1);
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_lower_ir$LoweredIf_t*) t0)->f_else_block;
        if (!(l3.tag == 0u)) {
            t0 = l3.payload.obj;
            vader_lower_optimise$pc_collect_pushes(t0, l1);
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_lower_optimise$pc_collect_in_stmt(vader_box_t l0, void* l1) {
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1532u) {
        t0 = l0.payload.obj;
        vader_lower_optimise$pc_collect_in_expr(((vader_struct_vader_lower_ir$LoweredExprStmt_t*) t0)->f_expr, l1);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 1544u) {
        t0 = l0.payload.obj;
        vader_lower_optimise$pc_collect_in_expr(((vader_struct_vader_lower_ir$LoweredLet_t*) t0)->f_value, l1);
    } else if (l0.tag == 1516u) {
        t0 = l0.payload.obj;
        vader_lower_optimise$pc_collect_in_expr(((vader_struct_vader_lower_ir$LoweredAssign_t*) t0)->f_value, l1);
    } else if (l0.tag == 1543u) {
        t0 = l0.payload.obj;
        vader_lower_optimise$pc_collect_pushes(((vader_struct_vader_lower_ir$LoweredLabelledBlock_t*) t0)->f_body, l1);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_lower_optimise$pc_collect_pushes(void* l0, void* l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l5, &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_lower_ir$LoweredBlock_t*) l0)->f_stmts;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        vader_lower_optimise$pc_collect_in_stmt(t0, l1);
        l4 = (l4 + INT64_C(1));
    }
    l5 = ((vader_struct_vader_lower_ir$LoweredBlock_t*) l0)->f_trailing;
    if (l5.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_lower_optimise$pc_collect_in_expr(l5, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_lower_optimise$pc_expr_may_disturb_skipping_push(void* l0, vader_box_t l1, int32_t l2) {
    vader_box_t l3 = vader_box_null(), l5 = vader_box_null();
    void* l4 = NULL;
    void* t0 = NULL;
    int32_t t1;
    bool t2;
    vader_box_t* gc_roots[3] = { &l1, &l3, &l5 };
    void** gc_raw_roots[3] = { &l0, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 1514u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_lower_ir$LoweredArrayPush_t*) t0)->f_target;
        if (!(l3.tag == 1538u)) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        t0 = l3.payload.obj;
        t1 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$LoweredIdent_t*) t0)->f_symbol)->f_id;
        if (!(t1 != l2)) {
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_lower_ir$LoweredArrayPush_t*) t0)->f_value;
            t2 = vader_lower_optimise$expr_may_disturb(l0, l3);
            { bool __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_gc_top = gc_frame.prev; return true; }
    }
    if (l1.tag == 1518u) {
        l4 = l1.payload.obj;
        t2 = vader_lower_optimise$pc_body_may_disturb(l0, l4, l2);
        { bool __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l1.tag == 1539u)) {
        l5 = l1;
        t2 = vader_lower_optimise$expr_may_disturb(l0, l5);
        { bool __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l1.payload.obj;
    l3 = ((vader_struct_vader_lower_ir$LoweredIf_t*) t0)->f_cond;
    t2 = vader_lower_optimise$expr_may_disturb(l0, l3);
    if (t2) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    t0 = l1.payload.obj;
    l4 = ((vader_struct_vader_lower_ir$LoweredIf_t*) t0)->f_then_block;
    t2 = vader_lower_optimise$pc_body_may_disturb(l0, l4, l2);
    if (t2) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    t0 = l1.payload.obj;
    l3 = ((vader_struct_vader_lower_ir$LoweredIf_t*) t0)->f_else_block;
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    l4 = l3.payload.obj;
    t2 = vader_lower_optimise$pc_body_may_disturb(l0, l4, l2);
    { bool __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_lower_optimise$pc_has_extra_exit(void* l0) {
    vader_box_t l1 = vader_box_null();
    void* l2 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_$Cell_bool_cd2fd49b_t* _a0_obj = (vader_struct_$Cell_bool_cd2fd49b_t*) vader_gc_alloc(sizeof(vader_struct_$Cell_bool_cd2fd49b_t));
    vader_obj_header_init(_a0_obj, 506u);
    _a0_obj->f_value = false;
    t0 = (void*) _a0_obj;
    l1 = vader_ref_box(t0);
    vader_struct___lambda_env_vader_lower_optimise_1_t* _a1_obj = (vader_struct___lambda_env_vader_lower_optimise_1_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_lower_optimise_1_t));
    vader_obj_header_init(_a1_obj, 643u);
    _a1_obj->f_cap_0 = l1;
    t0 = (void*) _a1_obj;
    vader_fn_t* _a2_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a2_closure, 487u);
    _a2_closure->code = (void*) &vader_fn_lift___lambda_vader_lower_optimise_0;
    _a2_closure->env = t0;
    l2 = (void*) _a2_closure;
    vader_lower_ir$for_each_stmt_node_in_block(l0, l2);
    { bool __vret = ((vader_struct_$Cell_bool_cd2fd49b_t*) l1.payload.obj)->f_value; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_lower_optimise$pc_live_entering(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l7 = NULL;
    int64_t l4, l5;
    int32_t l6;
    void* t0 = NULL;
    bool t1;
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l7, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(27u, 0u, 7u, 496u);
    l2 = (void*) _a0_arr;
    l3 = l0;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l6 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l5];
        t0 = (void*) &vader_data_50;
        vader_array_t* _a2_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l7 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT64_C(0));
        t1 = vader_lower_ir$stmt_mentions_symbol(vader_ref_box(l1), l6, l7);
        if (!(t1)) {
            vader_array_push_i32((vader_array_t*) l2, l6);
        }
        l5 = (l5 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_lower_optimise$pc_scan_block(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    int64_t l5, l6;
    vader_box_t l7 = vader_box_null();
    vader_box_t* gc_roots[1] = { &l7 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(27u, 0u, 7u, 496u);
    l3 = (void*) _a0_arr;
    vader_array_push_all((vader_array_t*) l3, (vader_array_t*) l2);
    l4 = ((vader_struct_vader_lower_ir$LoweredBlock_t*) l1)->f_stmts;
    l5 = ((vader_array_t*) l4)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        l7 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
        vader_lower_optimise$pc_scan_stmt(l0, l7, l3);
        vader_lower_optimise$pc_update_live(l3, l7);
        l6 = (l6 + INT64_C(1));
    }
    l7 = ((vader_struct_vader_lower_ir$LoweredBlock_t*) l1)->f_trailing;
    if (l7.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_lower_optimise$pc_scan_expr(l0, l7, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_lower_optimise$pc_scan_expr(void* l0, vader_box_t l1, void* l2) {
    void* l3 = NULL;
    vader_box_t l4 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l4 };
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 1518u) {
        l3 = l1.payload.obj;
        vader_lower_optimise$pc_scan_block(l0, l3, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 1539u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_lower_ir$LoweredIf_t*) t0)->f_then_block;
        vader_lower_optimise$pc_scan_block(l0, l3, l2);
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_lower_ir$LoweredIf_t*) t0)->f_else_block;
        if (!(l4.tag == 0u)) {
            l3 = l4.payload.obj;
            vader_lower_optimise$pc_scan_block(l0, l3, l2);
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_lower_optimise$pc_scan_stmt(void* l0, vader_box_t l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    int64_t l5, l6;
    vader_box_t l7 = vader_box_null(), l8 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[3] = { &l1, &l7, &l8 };
    void** gc_raw_roots[5] = { &l0, &l2, &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 1545u) {
        l3 = l1.payload.obj;
        l3 = vader_lower_optimise$pc_live_entering(l2, l3);
        l4 = l1.payload.obj;
        vader_lower_optimise$pc_try_cache(l0, l4, l3);
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_lower_ir$LoweredLoop_t*) t0)->f_body;
        vader_lower_optimise$pc_scan_block(l0, l4, l3);
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_lower_ir$LoweredLoop_t*) t0)->f_step;
        l5 = ((vader_array_t*) l4)->length;
        l6 = INT64_C(0);
        while ((l6 < l5)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
            l7 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
            vader_lower_optimise$pc_scan_stmt(l0, l7, l3);
            l6 = (l6 + INT64_C(1));
        }
        t0 = l1.payload.obj;
        l7 = ((vader_struct_vader_lower_ir$LoweredLoop_t*) t0)->f_cond;
        if (l7.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        vader_lower_optimise$pc_scan_expr(l0, l7, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l7 = l1;
    if (l7.tag == 1544u) {
        t0 = l1.payload.obj;
        l8 = ((vader_struct_vader_lower_ir$LoweredLet_t*) t0)->f_value;
        vader_lower_optimise$pc_scan_expr(l0, l8, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l7.tag == 1516u) {
        t0 = l1.payload.obj;
        l8 = ((vader_struct_vader_lower_ir$LoweredAssign_t*) t0)->f_value;
        vader_lower_optimise$pc_scan_expr(l0, l8, l2);
    } else if (l7.tag == 1525u) {
        t0 = l1.payload.obj;
        l8 = ((vader_struct_vader_lower_ir$LoweredCellSet_t*) t0)->f_value;
        vader_lower_optimise$pc_scan_expr(l0, l8, l2);
    } else if (l7.tag == 1537u) {
        t0 = l1.payload.obj;
        l8 = ((vader_struct_vader_lower_ir$LoweredGlobalSet_t*) t0)->f_value;
        vader_lower_optimise$pc_scan_expr(l0, l8, l2);
    } else if (l7.tag == 1564u) {
        t0 = l1.payload.obj;
        l8 = ((vader_struct_vader_lower_ir$LoweredYield_t*) t0)->f_value;
        vader_lower_optimise$pc_scan_expr(l0, l8, l2);
    } else if (l7.tag == 1532u) {
        t0 = l1.payload.obj;
        l8 = ((vader_struct_vader_lower_ir$LoweredExprStmt_t*) t0)->f_expr;
        vader_lower_optimise$pc_scan_expr(l0, l8, l2);
    } else if (l7.tag == 1531u) {
        t0 = l1.payload.obj;
        l8 = ((vader_struct_vader_lower_ir$LoweredDeferPush_t*) t0)->f_thunk;
        vader_lower_optimise$pc_scan_expr(l0, l8, l2);
    } else if (l7.tag == 1543u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_lower_ir$LoweredLabelledBlock_t*) t0)->f_body;
        vader_lower_optimise$pc_scan_block(l0, l3, l2);
    } else if (l7.tag == 1551u) {
        t0 = l1.payload.obj;
        l7 = ((vader_struct_vader_lower_ir$LoweredReturn_t*) t0)->f_value;
        if (!(l7.tag == 0u)) {
            vader_lower_optimise$pc_scan_expr(l0, l7, l2);
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_lower_optimise$pc_single_target(void* l0) {
    vader_box_t l1, l5;
    void* l2;
    int64_t l3, l4;
    int32_t l6, l7;
    void* t0;
    int32_t t1;
    l1 = vader_box_obj(0u, NULL);
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        l5 = ((vader_struct_vader_lower_ir$LoweredArrayPush_t*) t0)->f_target;
        if (!(l5.tag == 1538u)) {
            return vader_box_obj(0u, NULL);
        }
        if (l1.tag == 0u) {
            t0 = l5.payload.obj;
            t1 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$LoweredIdent_t*) t0)->f_symbol)->f_id;
            l1 = vader_box_i32(496u, t1);
        } else {
            l6 = ((int32_t) l1.payload.i);
            t0 = l5.payload.obj;
            l7 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$LoweredIdent_t*) t0)->f_symbol)->f_id;
            if (l6 != l7) {
                return vader_box_obj(0u, NULL);
            }
        }
        l4 = (l4 + INT64_C(1));
    }
    return l1;
}

bool vader_lower_optimise$pc_stmt_exits(vader_box_t l0) {
    bool l1;
    if ((l0.tag == 1530u || l0.tag == 1531u || l0.tag == 1551u || l0.tag == 1564u)) {
        l1 = true;
        return l1;
    }
    if ((l0.tag == 1520u || l0.tag == 1528u)) {
        l1 = !(VADER_UNION_FIELD(vader_box_t, vader_struct_vader_lower_ir$LoweredBreak_t, f_label, l0.payload.obj).tag == 0u);
    } else {
        if (!((l0.tag == 1516u || l0.tag == 1525u || l0.tag == 1532u || l0.tag == 1537u || l0.tag == 1543u || l0.tag == 1544u || l0.tag == 1545u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = false;
    }
    return l1;
}

static bool vader_lower_optimise$pc_stmt_may_disturb(void* l0, vader_box_t l1, int32_t l2) {
    vader_box_t l3 = vader_box_null(), l6 = vader_box_null();
    void* l4 = NULL;
    bool l5;
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[3] = { &l1, &l3, &l6 };
    void** gc_raw_roots[3] = { &l0, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 1532u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_lower_ir$LoweredExprStmt_t*) t0)->f_expr;
        t1 = vader_lower_optimise$pc_expr_may_disturb_skipping_push(l0, l3, l2);
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1543u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_lower_ir$LoweredLabelledBlock_t*) t0)->f_body;
        t1 = vader_lower_optimise$pc_body_may_disturb(l0, l4, l2);
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l1.tag == 1545u)) {
        l6 = l1;
        t1 = vader_lower_optimise$stmt_may_disturb(l0, l6);
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l1.payload.obj;
    l3 = ((vader_struct_vader_lower_ir$LoweredLoop_t*) t0)->f_cond;
    t1 = vader_lower_optimise$opt_expr_may_disturb(l0, l3);
    if (t1) {
        l5 = true;
    } else {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_lower_ir$LoweredLoop_t*) t0)->f_body;
        l5 = vader_lower_optimise$pc_body_may_disturb(l0, l4, l2);
    }
    if (l5) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    t0 = l1.payload.obj;
    l4 = vader_lower_ir$loop_step_block(t0);
    t1 = vader_lower_optimise$pc_body_may_disturb(l0, l4, l2);
    { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_lower_optimise$pc_try_cache(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    int64_t l5, l6;
    int32_t l7;
    vader_box_t l8 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    bool t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[2] = { &l8, &t0 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l4, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(326u, 0u, 13u, 1514u);
    l3 = (void*) _a0_arr;
    vader_lower_optimise$pc_collect_pushes(((vader_struct_vader_lower_ir$LoweredLoop_t*) l1)->f_body, l3);
    l4 = ((vader_struct_vader_lower_ir$LoweredLoop_t*) l1)->f_step;
    l5 = ((vader_array_t*) l4)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t0 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
        vader_lower_optimise$pc_collect_in_stmt(t0, l3);
        l6 = (l6 + INT64_C(1));
    }
    l8 = vader_lower_optimise$pc_single_target(l3);
    if (l8.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l7 = ((int32_t) l8.payload.i);
    t1 = vader_lower_optimise$pc_has_extra_exit(((vader_struct_vader_lower_ir$LoweredLoop_t*) l1)->f_body);
    if (t1) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    t1 = vader_lower_optimise$pc_used_outside_push(l1, l7);
    if (t1) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    t1 = std_core$$array$Contains$contains__i32(l2, l7);
    if (!(t1)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    t1 = vader_lower_optimise$pc_stmt_may_disturb(l0, vader_ref_box(l1), l7);
    if (t1) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l5 = ((vader_array_t*) l3)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t2 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l6);
        ((vader_struct_vader_lower_ir$LoweredArrayPush_t*) t2)->f_cached = true;
        l6 = (l6 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_lower_optimise$pc_update_live(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l7 = NULL;
    int64_t l4, l5;
    int32_t l6;
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[5] = { &l0, &l2, &l3, &l7, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(27u, 0u, 7u, 496u);
    l2 = (void*) _a0_arr;
    l3 = l0;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l6 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l5];
        t0 = (void*) &vader_data_50;
        vader_array_t* _a2_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l7 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT64_C(0));
        t1 = vader_lower_ir$stmt_mentions_symbol(l1, l6, l7);
        if (!(t1)) {
            vader_array_push_i32((vader_array_t*) l2, l6);
        }
        l5 = (l5 + INT64_C(1));
    }
    vader_array_clear((vader_array_t*) l0);
    vader_array_push_all((vader_array_t*) l0, (vader_array_t*) l2);
    if (l1.tag == 1544u) {
        t0 = l1.payload.obj;
        t1 = vader_lower_optimise$is_fresh_array(((vader_struct_vader_lower_ir$LoweredLet_t*) t0)->f_value);
        if (t1) {
            t0 = l1.payload.obj;
            l6 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$LoweredLet_t*) t0)->f_symbol)->f_id;
            vader_array_push_i32((vader_array_t*) l0, l6);
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_lower_optimise$pc_used_outside_push(void* l0, int32_t l1) {
    void* l2 = NULL;
    void* t0 = NULL;
    bool t1;
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = (void*) &vader_data_51;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
    t1 = vader_lower_ir$stmt_mentions_symbol(vader_ref_box(l0), l1, l2);
    { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

void vader_lower_optimise$push_cache_tag(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    int64_t l5, l6, l7, l8;
    vader_box_t l9 = vader_box_null(), l10 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    void* t2 = NULL;
    vader_box_t* gc_roots[3] = { &l9, &l10, &t0 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l4, &l11, &l12, &t2 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_lower_optimise$new_purity_ctx(l0);
    l2 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l0)->f_modules;
    l3 = ((vader_struct_std_collections$Map__string__vader_lower_ir_LoweredModule_t*) l2)->f_ekeys;
    l4 = ((vader_struct_std_collections$Map__string__vader_lower_ir_LoweredModule_t*) l2)->f_evals;
    l5 = INT64_C(0);
    l6 = ((vader_struct_std_collections$Map__string__vader_lower_ir_LoweredModule_t*) l2)->f_size;
    while ((l5 < l6)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l5];
        t1 = t0.payload.s;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        t2 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
        l2 = ((vader_struct_vader_lower_ir$LoweredModule_t*) t2)->f_decls;
        l7 = ((vader_array_t*) l2)->length;
        l8 = INT64_C(0);
        while ((l8 < l7)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l8)
            l9 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l8);
            if (l9.tag == 1535u) {
                t2 = l9.payload.obj;
                l10 = ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) t2)->f_body;
                if (!(l10.tag == 0u)) {
                    l11 = l10.payload.obj;
                    vader_array_t* _a3_arr = vader_array_new(27u, 0u, 7u, 496u);
                    l12 = (void*) _a3_arr;
                    vader_lower_optimise$pc_scan_block(l1, l11, l12);
                }
            }
            l8 = (l8 + INT64_C(1));
        }
        l5 = (l5 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_lower_optimise$reads_local(vader_box_t l0, void* l1) {
    int32_t l2, l3;
    void* t0;
    bool t1;
    if (l0.tag == 1538u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$LoweredIdent_t*) t0)->f_symbol)->f_id;
        l3 = ((vader_struct_vader_core_symbol$Symbol_t*) l1)->f_id;
        return l2 == l3;
    }
    if (l0.tag == 1512u) {
        t0 = l0.payload.obj;
        t1 = vader_lower_optimise$reads_local(((vader_struct_vader_lower_ir$LoweredArrayLen_t*) t0)->f_target, l1);
        return t1;
    }
    if (!(l0.tag == 1533u)) {
        return false;
    }
    t0 = l0.payload.obj;
    t1 = vader_lower_optimise$reads_local(((vader_struct_vader_lower_ir$LoweredFieldAccess_t*) t0)->f_target, l1);
    return t1;
}

void vader_lower_optimise$reserve_push_tail(void* l0) {
    int64_t l1, l2;
    void* l3 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l16 = NULL;
    void* l18 = NULL;
    void* l19 = NULL;
    void* l21 = NULL;
    void* l23 = NULL;
    vader_box_t l4 = vader_box_null(), l9 = vader_box_null(), l10 = vader_box_null(), l17 = vader_box_null(), l20 = vader_box_null(), l22 = vader_box_null();
    vader_string_t l15 = 0;
    vader_box_t t0 = vader_box_null();
    bool t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[7] = { &l4, &l9, &l10, &l17, &l20, &l22, &t0 };
    void** gc_raw_roots[16] = {
        &l0, &l3, &l5, &l6, &l7, &l8, &l11, &l12, &l13, &l14, &l16, &l18, &l19, &l21, &l23, &t2,
    };
    vader_string_t* gc_atom_roots[1] = { &l15 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 7u, 16u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_array_t*) l0)->length;
    if ((l1 < INT64_C(2))) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l2 = vader_chk_sub(i64, l1, INT64_C(2));
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
    if (t0.tag == 1544u) {
        l2 = vader_chk_sub(i64, l1, INT64_C(1));
        vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t0 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l2);
        l4 = vader_lower_optimise$counted_loop_of(t0);
        if (l4.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        l3 = l4.payload.obj;
        t1 = vader_lower_optimise$runs_every_turn(l3);
        if (!(t1)) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        l1 = vader_chk_sub(i64, l1, INT64_C(1));
        for (;;) {
            if ((l1 > INT64_C(0))) {
                l1 = vader_chk_sub(i64, l1, INT64_C(1));
                vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l1)
                l4 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l1);
                if (!(l4.tag == 1544u)) {
                    { vader_gc_top = gc_frame.prev; return; }
                }
                t2 = l4.payload.obj;
                t1 = vader_lower_optimise$is_empty_array_lit(((vader_struct_vader_lower_ir$LoweredLet_t*) t2)->f_value);
                if (t1) {
                    l5 = ((vader_struct_vader_lower_optimise$CountedLoop_t*) l3)->f_body;
                    t2 = l4.payload.obj;
                    l6 = ((vader_struct_vader_lower_ir$LoweredLet_t*) t2)->f_symbol;
                    t1 = vader_lower_optimise$has_top_level_push(l5, l6);
                    if (t1) {
                        l7 = ((vader_struct_vader_lower_optimise$CountedLoop_t*) l3)->f_turns;
                        t2 = l4.payload.obj;
                        l8 = ((vader_struct_vader_lower_ir$LoweredLet_t*) t2)->f_span;
                        l9 = vader_lower_optimise$trip_count(l7, l8);
                        t2 = l4.payload.obj;
                        l10 = VADER_UNION_FIELD(vader_box_t, vader_struct_vader_lower_ir$LoweredArrayLen_t, f_type, ((vader_struct_vader_lower_ir$LoweredLet_t*) t2)->f_value.payload.obj);
                        t2 = l4.payload.obj;
                        l11 = ((vader_struct_vader_lower_ir$LoweredLet_t*) t2)->f_span;
                        l12 = vader_lower_ir$mk_array_reserve(l9, l10, l11);
                        l13 = l4.payload.obj;
                        l14 = ((vader_struct_vader_lower_ir$LoweredLet_t*) l13)->f_span;
                        l15 = ((vader_struct_vader_lower_ir$LoweredLet_t*) l13)->f_name;
                        l16 = ((vader_struct_vader_lower_ir$LoweredLet_t*) l13)->f_symbol;
                        l17 = ((vader_struct_vader_lower_ir$LoweredLet_t*) l13)->f_type;
                        vader_struct_vader_lower_ir$LoweredLet_t* _a3_obj = (vader_struct_vader_lower_ir$LoweredLet_t*) vader_gc_alloc(sizeof(vader_struct_vader_lower_ir$LoweredLet_t));
                        vader_obj_header_init(_a3_obj, 1544u);
                        _a3_obj->f_span = l14;
                        _a3_obj->f_name = l15;
                        _a3_obj->f_symbol = l16;
                        _a3_obj->f_type = l17;
                        _a3_obj->f_value = vader_ref_box(l12);
                        l18 = (void*) _a3_obj;
                        vader_array_t* _a4_slotarr = ((vader_array_t*) l0);
                        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l1)
                        vader_array_ref_store(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l1, l18);
                        VADER_WRITE_BARRIER(_a4_slotarr->buf);
                    }
                }
                l19 = ((vader_struct_vader_lower_optimise$CountedLoop_t*) l3)->f_turns;
                l20 = ((vader_struct_vader_lower_ir$LoopTurns_t*) l19)->f_start;
                t2 = l4.payload.obj;
                l21 = ((vader_struct_vader_lower_ir$LoweredLet_t*) t2)->f_symbol;
                t1 = vader_lower_optimise$reads_local(l20, l21);
                if (t1) {
                    { vader_gc_top = gc_frame.prev; return; }
                }
                l22 = ((vader_struct_vader_lower_ir$LoopTurns_t*) l19)->f_bound;
                t2 = l4.payload.obj;
                l23 = ((vader_struct_vader_lower_ir$LoweredLet_t*) t2)->f_symbol;
                t1 = vader_lower_optimise$reads_local(l22, l23);
                if (!(t1)) {
                    continue;
                }
                { vader_gc_top = gc_frame.prev; return; }
            }
            break;
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_lower_optimise$rewrite_block(void* l0, void* l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l5, &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_lower_ir$LoweredBlock_t*) l0)->f_stmts;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        vader_lower_optimise$rewrite_stmt(t0, l1);
        l4 = (l4 + INT64_C(1));
    }
    l5 = ((vader_struct_vader_lower_ir$LoweredBlock_t*) l0)->f_trailing;
    if (l5.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_lower_optimise$rewrite_expr(l5, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_lower_optimise$rewrite_expr(vader_box_t l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l7 = vader_box_null(), l8 = vader_box_null(), l12 = vader_box_null();
    void* l3 = NULL;
    void* l11 = NULL;
    void* l13 = NULL;
    int64_t l4, l5;
    int32_t l6;
    bool l9, l10;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    bool t2;
    vader_box_t* gc_roots[6] = { &l0, &l2, &l7, &l8, &l12, &t1 };
    void** gc_raw_roots[5] = { &l1, &l3, &l11, &l13, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 6u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1538u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 1521u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_lower_ir$LoweredCall_t*) t0)->f_callee;
        if (l2.tag == 1538u) {
            t0 = l0.payload.obj;
            l3 = ((vader_struct_vader_lower_ir$LoweredCall_t*) t0)->f_args;
            l4 = ((vader_array_t*) l3)->length;
            l5 = INT64_C(0);
            while ((l5 < l4)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
                t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
                vader_lower_optimise$rewrite_expr(t1, l1);
                l5 = (l5 + INT64_C(1));
            }
            l3 = ((vader_struct_vader_lower_optimise$AnalyzeCtx_t*) l1)->f_aliases;
            t0 = l2.payload.obj;
            l6 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$LoweredIdent_t*) t0)->f_symbol)->f_id;
            l7 = std_collections$Map$std_core$Index$at__i32__Any(l3, l6);
            l3 = ((vader_struct_vader_lower_optimise$AnalyzeCtx_t*) l1)->f_closures;
            t0 = l2.payload.obj;
            l6 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$LoweredIdent_t*) t0)->f_symbol)->f_id;
            l8 = std_collections$Map$std_core$Index$at__i32__Any(l3, l6);
            l3 = ((vader_struct_vader_lower_optimise$AnalyzeCtx_t*) l1)->f_escaped;
            t0 = l2.payload.obj;
            l6 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$LoweredIdent_t*) t0)->f_symbol)->f_id;
            t2 = std_collections$Set$std_core$Contains$contains__i32(l3, l6);
            l9 = !(t2);
            if (!(l7.tag == 0u)) {
                l10 = l9;
            } else {
                l10 = false;
            }
            if (l10) {
                l3 = l0.payload.obj;
                t0 = l2.payload.obj;
                l11 = ((vader_struct_vader_lower_ir$LoweredIdent_t*) t0)->f_span;
                t0 = l2.payload.obj;
                l12 = ((vader_struct_vader_lower_ir$LoweredIdent_t*) t0)->f_type;
                l13 = l7.payload.obj;
                vader_struct_vader_lower_ir$LoweredIdent_t* _a1_obj = (vader_struct_vader_lower_ir$LoweredIdent_t*) vader_gc_alloc(sizeof(vader_struct_vader_lower_ir$LoweredIdent_t));
                vader_obj_header_init(_a1_obj, 1538u);
                _a1_obj->f_span = l11;
                _a1_obj->f_type = l12;
                _a1_obj->f_symbol = l13;
                _a1_obj->f_fresh = false;
                l11 = (void*) _a1_obj;
                ((vader_struct_vader_lower_ir$LoweredCall_t*) l3)->f_callee = vader_ref_box(l11);
                VADER_WRITE_BARRIER((vader_struct_vader_lower_ir$LoweredCall_t*) l3);
            } else if (!(l8.tag == 0u)) {
                if (l9) {
                    t0 = l2.payload.obj;
                    l3 = ((vader_struct_vader_lower_ir$LoweredIdent_t*) t0)->f_span;
                    t0 = l8.payload.obj;
                    l7 = ((vader_struct_vader_lower_optimise$ClosureAlias_t*) t0)->f_env_type;
                    t0 = l2.payload.obj;
                    l11 = ((vader_struct_vader_lower_ir$LoweredIdent_t*) t0)->f_symbol;
                    vader_struct_vader_lower_ir$LoweredIdent_t* _a2_obj = (vader_struct_vader_lower_ir$LoweredIdent_t*) vader_gc_alloc(sizeof(vader_struct_vader_lower_ir$LoweredIdent_t));
                    vader_obj_header_init(_a2_obj, 1538u);
                    _a2_obj->f_span = l3;
                    _a2_obj->f_type = l7;
                    _a2_obj->f_symbol = l11;
                    _a2_obj->f_fresh = false;
                    t0 = (void*) _a2_obj;
                    vader_array_t* _a3_arr = vader_array_new(408u, 1u, 13u, 2348u);
                    ((void**) _a3_arr->buf->slots)[_a3_arr->offset + 0u] = t0;
                    l3 = (void*) _a3_arr;
                    t0 = l0.payload.obj;
                    l11 = ((vader_struct_vader_lower_ir$LoweredCall_t*) t0)->f_args;
                    vader_array_push_all((vader_array_t*) l3, (vader_array_t*) l11);
                    t0 = l0.payload.obj;
                    ((vader_struct_vader_lower_ir$LoweredCall_t*) t0)->f_args = l3;
                    VADER_WRITE_BARRIER((vader_struct_vader_lower_ir$LoweredCall_t*) t0);
                    l3 = l0.payload.obj;
                    t0 = l2.payload.obj;
                    l11 = ((vader_struct_vader_lower_ir$LoweredIdent_t*) t0)->f_span;
                    t0 = l2.payload.obj;
                    l2 = ((vader_struct_vader_lower_ir$LoweredIdent_t*) t0)->f_type;
                    t0 = l8.payload.obj;
                    l13 = ((vader_struct_vader_lower_optimise$ClosureAlias_t*) t0)->f_fn_sym;
                    vader_struct_vader_lower_ir$LoweredIdent_t* _a4_obj = (vader_struct_vader_lower_ir$LoweredIdent_t*) vader_gc_alloc(sizeof(vader_struct_vader_lower_ir$LoweredIdent_t));
                    vader_obj_header_init(_a4_obj, 1538u);
                    _a4_obj->f_span = l11;
                    _a4_obj->f_type = l2;
                    _a4_obj->f_symbol = l13;
                    _a4_obj->f_fresh = false;
                    l11 = (void*) _a4_obj;
                    ((vader_struct_vader_lower_ir$LoweredCall_t*) l3)->f_callee = vader_ref_box(l11);
                    VADER_WRITE_BARRIER((vader_struct_vader_lower_ir$LoweredCall_t*) l3);
                }
            }
        } else {
            t0 = l0.payload.obj;
            vader_lower_optimise$rewrite_expr(((vader_struct_vader_lower_ir$LoweredCall_t*) t0)->f_callee, l1);
            t0 = l0.payload.obj;
            l3 = ((vader_struct_vader_lower_ir$LoweredCall_t*) t0)->f_args;
            l4 = ((vader_array_t*) l3)->length;
            l5 = INT64_C(0);
            while ((l5 < l4)) {
                vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                t1 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l5);
                vader_lower_optimise$rewrite_expr(t1, l1);
                l5 = (l5 + INT64_C(1));
            }
        }
    } else if (l0.tag == 1562u) {
        t0 = l0.payload.obj;
        vader_lower_optimise$rewrite_expr(((vader_struct_vader_lower_ir$LoweredVirtualCall_t*) t0)->f_receiver, l1);
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_lower_ir$LoweredVirtualCall_t*) t0)->f_args;
        l4 = ((vader_array_t*) l3)->length;
        l5 = INT64_C(0);
        while ((l5 < l4)) {
            vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            t1 = vader_array_ref_load_box(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l5);
            vader_lower_optimise$rewrite_expr(t1, l1);
            l5 = (l5 + INT64_C(1));
        }
    } else if ((l0.tag == 1533u || l0.tag == 1560u)) {
        vader_lower_optimise$rewrite_expr(VADER_UNION_FIELD(vader_box_t, vader_struct_vader_lower_ir$LoweredFieldAccess_t, f_target, l0.payload.obj), l1);
    } else if (l0.tag == 1540u) {
        t0 = l0.payload.obj;
        vader_lower_optimise$rewrite_expr(((vader_struct_vader_lower_ir$LoweredIndex_t*) t0)->f_target, l1);
        t0 = l0.payload.obj;
        vader_lower_optimise$rewrite_expr(((vader_struct_vader_lower_ir$LoweredIndex_t*) t0)->f_index, l1);
    } else if (l0.tag == 1559u) {
        t0 = l0.payload.obj;
        vader_lower_optimise$rewrite_expr(((vader_struct_vader_lower_ir$LoweredUnary_t*) t0)->f_operand, l1);
    } else if (l0.tag == 1517u) {
        t0 = l0.payload.obj;
        vader_lower_optimise$rewrite_expr(((vader_struct_vader_lower_ir$LoweredBinary_t*) t0)->f_left, l1);
        t0 = l0.payload.obj;
        vader_lower_optimise$rewrite_expr(((vader_struct_vader_lower_ir$LoweredBinary_t*) t0)->f_right, l1);
    } else if (l0.tag == 1539u) {
        t0 = l0.payload.obj;
        vader_lower_optimise$rewrite_expr(((vader_struct_vader_lower_ir$LoweredIf_t*) t0)->f_cond, l1);
        t0 = l0.payload.obj;
        vader_lower_optimise$rewrite_block(((vader_struct_vader_lower_ir$LoweredIf_t*) t0)->f_then_block, l1);
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_lower_ir$LoweredIf_t*) t0)->f_else_block;
        if (!(l2.tag == 0u)) {
            t0 = l2.payload.obj;
            vader_lower_optimise$rewrite_block(t0, l1);
        }
    } else if (l0.tag == 1518u) {
        t0 = l0.payload.obj;
        vader_lower_optimise$rewrite_block(t0, l1);
    } else if (l0.tag == 1555u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_lower_ir$LoweredStructLit_t*) t0)->f_fields;
        l4 = ((vader_array_t*) l3)->length;
        l5 = INT64_C(0);
        while ((l5 < l4)) {
            vader_array_t* _a7_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            t0 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l5);
            vader_lower_optimise$rewrite_expr(((vader_struct_vader_lower_ir$LoweredStructLitField_t*) t0)->f_value, l1);
            l5 = (l5 + INT64_C(1));
        }
    } else if (l0.tag == 1513u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_lower_ir$LoweredArrayLit_t*) t0)->f_elements;
        l4 = ((vader_array_t*) l3)->length;
        l5 = INT64_C(0);
        while ((l5 < l4)) {
            vader_array_t* _a8_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            t1 = vader_array_ref_load_box(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l5);
            vader_lower_optimise$rewrite_expr(t1, l1);
            l5 = (l5 + INT64_C(1));
        }
    } else if (l0.tag == 1512u) {
        t0 = l0.payload.obj;
        vader_lower_optimise$rewrite_expr(((vader_struct_vader_lower_ir$LoweredArrayLen_t*) t0)->f_target, l1);
    } else if (l0.tag == 1514u) {
        t0 = l0.payload.obj;
        vader_lower_optimise$rewrite_expr(((vader_struct_vader_lower_ir$LoweredArrayPush_t*) t0)->f_target, l1);
        t0 = l0.payload.obj;
        vader_lower_optimise$rewrite_expr(((vader_struct_vader_lower_ir$LoweredArrayPush_t*) t0)->f_value, l1);
    } else if (l0.tag == 1515u) {
        t0 = l0.payload.obj;
        vader_lower_optimise$rewrite_expr(((vader_struct_vader_lower_ir$LoweredArraySlice_t*) t0)->f_target, l1);
        t0 = l0.payload.obj;
        vader_lower_optimise$rewrite_expr(((vader_struct_vader_lower_ir$LoweredArraySlice_t*) t0)->f_lo, l1);
        t0 = l0.payload.obj;
        vader_lower_optimise$rewrite_expr(((vader_struct_vader_lower_ir$LoweredArraySlice_t*) t0)->f_hi, l1);
    } else if (l0.tag == 1522u) {
        t0 = l0.payload.obj;
        vader_lower_optimise$rewrite_expr(((vader_struct_vader_lower_ir$LoweredCast_t*) t0)->f_value, l1);
    } else if (l0.tag == 1557u) {
        t0 = l0.payload.obj;
        vader_lower_optimise$rewrite_expr(((vader_struct_vader_lower_ir$LoweredTypeCheck_t*) t0)->f_value, l1);
    } else if (l0.tag == 1542u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_lower_ir$LoweredIntrinsicCall_t*) t0)->f_args;
        l4 = ((vader_array_t*) l3)->length;
        l5 = INT64_C(0);
        while ((l5 < l4)) {
            vader_array_t* _a9_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            t1 = vader_array_ref_load_box(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l5);
            vader_lower_optimise$rewrite_expr(t1, l1);
            l5 = (l5 + INT64_C(1));
        }
    } else if (l0.tag == 1524u) {
        t0 = l0.payload.obj;
        vader_lower_optimise$rewrite_expr(((vader_struct_vader_lower_ir$LoweredCellNew_t*) t0)->f_value, l1);
    } else if (l0.tag == 1523u) {
        t0 = l0.payload.obj;
        vader_lower_optimise$rewrite_expr(((vader_struct_vader_lower_ir$LoweredCellGet_t*) t0)->f_target, l1);
    } else if (l0.tag == 1546u) {
        t0 = l0.payload.obj;
        vader_lower_optimise$rewrite_expr(((vader_struct_vader_lower_ir$LoweredMakeClosure_t*) t0)->f_env, l1);
    } else if (!(l0.tag == 1541u)) {
        if (!(l0.tag == 1534u)) {
            if (!(l0.tag == 1519u)) {
                if (!(l0.tag == 1548u)) {
                    if (!(l0.tag == 1526u)) {
                        if (!(l0.tag == 1552u)) {
                            if (!(l0.tag == 1529u)) {
                                if (!(l0.tag == 1536u)) {
                                    if (!(l0.tag == 1558u)) {
                                        if (!(l0.tag == 1561u)) {
                                            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_lower_optimise$rewrite_stmt(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    int32_t l3;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    int64_t l6, l7;
    void* t0 = NULL;
    bool t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l0, &l4, &l5, &t2 };
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1544u) {
        l2 = ((vader_struct_vader_lower_optimise$AnalyzeCtx_t*) l1)->f_closures;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$LoweredLet_t*) t0)->f_symbol)->f_id;
        l4 = std_collections$Map$std_core$Index$at__i32__Any(l2, l3);
        if (!(l4.tag == 0u)) {
            l2 = ((vader_struct_vader_lower_optimise$AnalyzeCtx_t*) l1)->f_escaped;
            t0 = l0.payload.obj;
            l3 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$LoweredLet_t*) t0)->f_symbol)->f_id;
            t1 = std_collections$Set$std_core$Contains$contains__i32(l2, l3);
            if (!(t1)) {
                t0 = l0.payload.obj;
                l5 = ((vader_struct_vader_lower_ir$LoweredLet_t*) t0)->f_value;
                if (l5.tag == 1546u) {
                    l2 = l0.payload.obj;
                    t0 = l5.payload.obj;
                    l5 = ((vader_struct_vader_lower_ir$LoweredMakeClosure_t*) t0)->f_env;
                    ((vader_struct_vader_lower_ir$LoweredLet_t*) l2)->f_value = l5;
                    VADER_WRITE_BARRIER((vader_struct_vader_lower_ir$LoweredLet_t*) l2);
                    l2 = l0.payload.obj;
                    t0 = l4.payload.obj;
                    l4 = ((vader_struct_vader_lower_optimise$ClosureAlias_t*) t0)->f_env_type;
                    ((vader_struct_vader_lower_ir$LoweredLet_t*) l2)->f_type = l4;
                    VADER_WRITE_BARRIER((vader_struct_vader_lower_ir$LoweredLet_t*) l2);
                }
            }
        }
        t0 = l0.payload.obj;
        vader_lower_optimise$rewrite_expr(((vader_struct_vader_lower_ir$LoweredLet_t*) t0)->f_value, l1);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 1516u) {
        t0 = l0.payload.obj;
        vader_lower_optimise$rewrite_expr(((vader_struct_vader_lower_ir$LoweredAssign_t*) t0)->f_target, l1);
        t0 = l0.payload.obj;
        vader_lower_optimise$rewrite_expr(((vader_struct_vader_lower_ir$LoweredAssign_t*) t0)->f_value, l1);
    } else if (l0.tag == 1525u) {
        t0 = l0.payload.obj;
        vader_lower_optimise$rewrite_expr(((vader_struct_vader_lower_ir$LoweredCellSet_t*) t0)->f_target, l1);
        t0 = l0.payload.obj;
        vader_lower_optimise$rewrite_expr(((vader_struct_vader_lower_ir$LoweredCellSet_t*) t0)->f_value, l1);
    } else if (l0.tag == 1537u) {
        t0 = l0.payload.obj;
        vader_lower_optimise$rewrite_expr(((vader_struct_vader_lower_ir$LoweredGlobalSet_t*) t0)->f_value, l1);
    } else if (l0.tag == 1532u) {
        t0 = l0.payload.obj;
        vader_lower_optimise$rewrite_expr(((vader_struct_vader_lower_ir$LoweredExprStmt_t*) t0)->f_expr, l1);
    } else if (l0.tag == 1551u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_lower_ir$LoweredReturn_t*) t0)->f_value;
        if (!(l4.tag == 0u)) {
            vader_lower_optimise$rewrite_expr(l4, l1);
        }
    } else if (l0.tag == 1564u) {
        t0 = l0.payload.obj;
        vader_lower_optimise$rewrite_expr(((vader_struct_vader_lower_ir$LoweredYield_t*) t0)->f_value, l1);
    } else if (l0.tag == 1543u) {
        t0 = l0.payload.obj;
        vader_lower_optimise$rewrite_block(((vader_struct_vader_lower_ir$LoweredLabelledBlock_t*) t0)->f_body, l1);
    } else if (l0.tag == 1545u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_lower_ir$LoweredLoop_t*) t0)->f_cond;
        if (!(l4.tag == 0u)) {
            vader_lower_optimise$rewrite_expr(l4, l1);
        }
        t0 = l0.payload.obj;
        vader_lower_optimise$rewrite_block(((vader_struct_vader_lower_ir$LoweredLoop_t*) t0)->f_body, l1);
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_lower_ir$LoweredLoop_t*) t0)->f_step;
        l6 = ((vader_array_t*) l2)->length;
        l7 = INT64_C(0);
        while ((l7 < l6)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            t2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
            vader_lower_optimise$rewrite_stmt(t2, l1);
            l7 = (l7 + INT64_C(1));
        }
    } else if (!(l0.tag == 1520u)) {
        if (!(l0.tag == 1528u)) {
            if (l0.tag == 1531u) {
                t0 = l0.payload.obj;
                vader_lower_optimise$rewrite_expr(((vader_struct_vader_lower_ir$LoweredDeferPush_t*) t0)->f_thunk, l1);
            } else if (!(l0.tag == 1530u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_lower_optimise$runs_every_turn(void* l0) {
    vader_box_t l1 = vader_box_null();
    void* l2 = NULL;
    void* l3 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_$Cell_bool_cd2fd49b_t* _a0_obj = (vader_struct_$Cell_bool_cd2fd49b_t*) vader_gc_alloc(sizeof(vader_struct_$Cell_bool_cd2fd49b_t));
    vader_obj_header_init(_a0_obj, 506u);
    _a0_obj->f_value = false;
    t0 = (void*) _a0_obj;
    l1 = vader_ref_box(t0);
    l2 = ((vader_struct_vader_lower_optimise$CountedLoop_t*) l0)->f_body;
    vader_struct___lambda_env_vader_lower_optimise_3_t* _a1_obj = (vader_struct___lambda_env_vader_lower_optimise_3_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_lower_optimise_3_t));
    vader_obj_header_init(_a1_obj, 644u);
    _a1_obj->f_cap_0 = l1;
    t0 = (void*) _a1_obj;
    vader_fn_t* _a2_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a2_closure, 487u);
    _a2_closure->code = (void*) &vader_fn_lift___lambda_vader_lower_optimise_2;
    _a2_closure->env = t0;
    l3 = (void*) _a2_closure;
    vader_lower_ir$for_each_stmt_node_in_block(l2, l3);
    { bool __vret = !(((vader_struct_$Cell_bool_cd2fd49b_t*) l1.payload.obj)->f_value); vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_lower_optimise$stmt_may_disturb(void* l0, vader_box_t l1) {
    bool l2, l5;
    vader_box_t l3 = vader_box_null();
    void* l4 = NULL;
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[2] = { &l1, &l3 };
    void** gc_raw_roots[3] = { &l0, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 1544u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_lower_ir$LoweredLet_t*) t0)->f_value;
        l2 = vader_lower_optimise$expr_may_disturb(l0, l3);
        { bool __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if ((l1.tag == 1516u || l1.tag == 1525u)) {
        l3 = VADER_UNION_FIELD(vader_box_t, vader_struct_vader_lower_ir$LoweredAssign_t, f_target, l1.payload.obj);
        t1 = vader_lower_optimise$expr_may_disturb(l0, l3);
        if (t1) {
            l2 = true;
        } else {
            l3 = VADER_UNION_FIELD(vader_box_t, vader_struct_vader_lower_ir$LoweredAssign_t, f_value, l1.payload.obj);
            l2 = vader_lower_optimise$expr_may_disturb(l0, l3);
        }
    } else if (l1.tag == 1537u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_lower_ir$LoweredGlobalSet_t*) t0)->f_value;
        l2 = vader_lower_optimise$expr_may_disturb(l0, l3);
    } else if (l1.tag == 1532u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_lower_ir$LoweredExprStmt_t*) t0)->f_expr;
        l2 = vader_lower_optimise$expr_may_disturb(l0, l3);
    } else if (l1.tag == 1551u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_lower_ir$LoweredReturn_t*) t0)->f_value;
        l2 = vader_lower_optimise$opt_expr_may_disturb(l0, l3);
    } else if (l1.tag == 1543u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_lower_ir$LoweredLabelledBlock_t*) t0)->f_body;
        l2 = vader_lower_optimise$block_may_disturb(l0, l4);
    } else if (l1.tag == 1545u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_lower_ir$LoweredLoop_t*) t0)->f_cond;
        t1 = vader_lower_optimise$opt_expr_may_disturb(l0, l3);
        if (t1) {
            l5 = true;
        } else {
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_lower_ir$LoweredLoop_t*) t0)->f_body;
            l5 = vader_lower_optimise$block_may_disturb(l0, l4);
        }
        if (l5) {
            l2 = true;
        } else {
            t0 = l1.payload.obj;
            l4 = vader_lower_ir$loop_step_block(t0);
            l2 = vader_lower_optimise$block_may_disturb(l0, l4);
        }
    } else if ((l1.tag == 1520u || l1.tag == 1528u)) {
        l2 = false;
    } else {
        if (!((l1.tag == 1530u || l1.tag == 1531u || l1.tag == 1564u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = true;
    }
    { bool __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_lower_optimise$trip_count(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l8 = vader_box_null();
    bool l4;
    int64_t l5, l6, l7;
    void* l9 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    uint8_t l10;
    bool t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l2, &l3, &l8, &t2 };
    void** gc_raw_roots[7] = { &l0, &l1, &l9, &l11, &l12, &l13, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_lower_ir$LoopTurns_t*) l0)->f_start;
    l3 = ((vader_struct_vader_lower_ir$LoopTurns_t*) l0)->f_bound;
    l4 = ((vader_struct_vader_lower_ir$LoopTurns_t*) l0)->f_inclusive;
    if (l4) {
        l5 = INT64_C(1);
    } else {
        l5 = INT64_C(0);
    }
    t0 = vader_lower_optimise$is_int_lit(l2, INT64_C(0));
    if (t0) {
        t0 = vader_lower_optimise$never_negative(l3);
        if (t0) {
            if (!(l4)) {
                { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
    }
    if (l2.tag == 1541u) {
        if (l3.tag == 1541u) {
            t1 = l3.payload.obj;
            l6 = ((vader_struct_vader_lower_ir$LoweredIntLit_t*) t1)->f_value;
            t1 = l2.payload.obj;
            l7 = ((vader_struct_vader_lower_ir$LoweredIntLit_t*) t1)->f_value;
            l5 = ((l6 - l7) + l5);
            if ((l5 > INT64_C(0))) {
                t2 = vader_lower_optimise$count_lit(l5, l1);
                { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
            }
            t2 = vader_lower_optimise$count_lit(INT64_C(0), l1);
            { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l8 = vader_lower_optimise$count_between(l3, l2, l1);
    t1 = (void*) &vader_data_22;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t1);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l9 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
    if (l4) {
        l10 = (uint8_t) 15;
    } else {
        l10 = (uint8_t) 14;
    }
    vader_struct_vader_lower_ir$LoweredBinary_t* _a1_obj = (vader_struct_vader_lower_ir$LoweredBinary_t*) vader_gc_alloc(sizeof(vader_struct_vader_lower_ir$LoweredBinary_t));
    vader_obj_header_init(_a1_obj, 1517u);
    _a1_obj->f_span = l1;
    _a1_obj->f_type = vader_ref_box(l9);
    _a1_obj->f_op = l10;
    _a1_obj->f_left = l2;
    _a1_obj->f_right = l3;
    l9 = (void*) _a1_obj;
    t1 = (void*) &vader_data_24;
    vader_array_t* _a2_slotarr = ((vader_array_t*) t1);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    l11 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT64_C(0));
    t2 = vader_lower_ir$adjust_hi_inclusive(l8, l4, l1);
    l12 = vader_lower_ir$wrap_as_block(t2, l1);
    t2 = vader_lower_optimise$count_lit(INT64_C(0), l1);
    l13 = vader_lower_ir$wrap_as_block(t2, l1);
    vader_struct_vader_lower_ir$LoweredIf_t* _a3_obj = (vader_struct_vader_lower_ir$LoweredIf_t*) vader_gc_alloc(sizeof(vader_struct_vader_lower_ir$LoweredIf_t));
    vader_obj_header_init(_a3_obj, 1539u);
    _a3_obj->f_span = l1;
    _a3_obj->f_type = vader_ref_box(l11);
    _a3_obj->f_cond = vader_ref_box(l9);
    _a3_obj->f_then_block = l12;
    _a3_obj->f_else_block = vader_ref_box(l13);
    t1 = (void*) _a3_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}
